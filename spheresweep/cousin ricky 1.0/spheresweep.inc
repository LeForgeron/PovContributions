/* spheresweep.inc version 1.0
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   22-may-2013  Created.
 * 1.0   22-jul-2013  Uploaded.
 */
#ifndef (SPHERESWEEP__INC) #declare SPHERESWEEP__INC = version;
#version 3.5;
#debug "#include \"spheresweep.inc\" //version 1.0\n"
#declare SPHERESWEEP_VERSION = 1.0;

#include "shapes.inc"

#declare SSWP_LINEAR_SPLINE = 0;
#declare SSWP_QUADRATIC_SPLINE = 1;
#declare SSWP_CUBIC_SPLINE = 2;
#declare SSWP_NATURAL_SPLINE = 3;
#declare SSWP_B_SPLINE = 4;
#declare SSWP_BEZIER_SPLINE = 5; //reserved for future use
#declare sswp__s_Types = array[6]
{ "linear spline",
  "quadratic spline",
  "cubic spline",
  "natural spline",
  "B-spline",
  "Bezier spline",
}

//================= INTERNAL AUXILIARY MACROS AND FUNCTIONS ====================

// Constructs an error message for a multidimensional array.
#macro SSwp__1D_message_s (s_Macro, s_Desc)
  concat (s_Macro, "(): array", s_Desc, " must be 1 dimensional.\n")
#end

// Creates a spline from user points.
#macro SSwp__Spline (Type, v_Points, Radii, s_Macro)
  #if (dimensions (v_Points) != 1)
    #error SSwp__1D_message_s (s_Macro, " of spline control points")
  #end
  #if (dimensions (Radii) != 1)
    #error SSwp__1D_message_s (s_Macro, " of radii")
  #end
  spline
  { #switch (Type)
      #case (SSWP_LINEAR_SPLINE) linear_spline #break
      #case (SSWP_QUADRATIC_SPLINE) quadratic_spline #break
      #case (SSWP_CUBIC_SPLINE) cubic_spline #break
      #case (SSWP_NATURAL_SPLINE) natural_spline #break
      #case (SSWP_B_SPLINE)
      #case (SSWP_BEZIER_SPLINE)
        #error concat
        ( s_Macro, "(): ", sswp__s_Types[Type],
          " cannot be used with this version of spheresweep.inc.\n"
        )
        #break
      #else
        #error concat
        ( s_Macro, "(): Unknown spline type code ", str(Type,0,-1), ".\n"
        )
    #end
    #local sswp_I = 0;
    #while (sswp_I < dimension_size (v_Points, 1))
      #local sswp_Pt = <0,0,0> + v_Points [sswp_I];
      sswp_I,
      < sswp_Pt.x, sswp_Pt.y, sswp_Pt.z,
        Radii [min (sswp_I, dimension_size (Radii, 1) - 1)]
      >
      #local sswp_I = sswp_I + 1;
    #end
  }
#end

// Returns the physical endpoint indexes of a sphere sweep,
// according to spline type.
#macro SSwp__Ends (Type, v_Points)
( #switch (Type)
    #case (SSWP_CUBIC_SPLINE)
    #case (SSWP_B_SPLINE) //future use
      <1, dimension_size (v_Points, 1) - 2>
      #break
    #else
      <0, dimension_size (v_Points, 1) - 1>
  #end
)
#end

// Assembles a sphere sweep approximation from spheres and cones.
#macro SphereSweep__Core (Type, v_Points, Radii, Res, Use_merge, s_Macro)
  #local sswp_Spline = SSwp__Spline (Type, v_Points, Radii, s_Macro)
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  #if (Use_merge) merge #else union #end
  { #local sswp_First = yes;
    #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_New = sswp_Spline (sswp_I / Res);
      sphere { <sswp_New.x, sswp_New.y, sswp_New.z>, sswp_New.t }
      #if (sswp_First)
        #local sswp_First = no;
      #else
        #if //Check for extreme change of radius:
        (   vlength
            (   <sswp_New.x, sswp_New.y, sswp_New.z>
              - <sswp_Old.x, sswp_Old.y, sswp_Old.z>
            )
          > abs (sswp_New.t - sswp_Old.t)
        )
          Connect_Spheres
          ( <sswp_Old.x, sswp_Old.y, sswp_Old.z>, sswp_Old.t,
            <sswp_New.x, sswp_New.y, sswp_New.z>, sswp_New.t
          )
        #end
      #end
      #local sswp_Old = sswp_New;
      #local sswp_I = sswp_I + 1;
    #end
  }
#end

//==================== PUBLIC UTILITY FUNCTION AND MACRO =======================

#declare SSwp_fn_Blob_strength = function
  (sswp_P0_RSurface, sswp_P1_RField)
{ 1 / pow (1 - pow (sswp_P0_RSurface / sswp_P1_RField, 2), 2)
}

//----------------------------------------------------------

#macro SSwp_Subarray (Array, Start, End)
  #local sswp_This = "SSwp_Subarray"
  #if (dimensions (Array) != 1) #error SSwp__1D_message_s (sswp_This, "") #end
  #local sswp_Nfrom = dimension_size (Array, 1);
  #if (Start < 0)
    #warning concat
    ( sswp_This, "(): Start index ", str(Start,0,-1),
      " is negative; zero will be used instead.\n"
    )
  #end
  #if (End >= sswp_Nfrom)
    #warning concat
    ( sswp_This, "(): End index ", str(End,0,-1),
      " is beyond the end of the given array; ",
      str (sswp_Nfrom-1, 0, 0), " will be used instead.\n"
    )
  #end
  #local sswp_Start = max (floor (Start), 0);
  #local sswp_End = min (floor (End), sswp_Nfrom-1);
  #if (sswp_End < sswp_Start)
    #warning concat
    ( sswp_This, "(): End index ", str(End,0,-1),
      " is less than Start index ", str(Start,0,-1),
      "; no values will be returned.\n"
    )
    array[1]
  #else
    #local sswp_Array = array [sswp_End - sswp_Start + 1]
    #local sswp_I = sswp_Start;
    #while (sswp_I <= sswp_End)
      #local sswp_Array [sswp_I - sswp_Start] = Array [sswp_I];
      #local sswp_I = sswp_I + 1;
    #end
    sswp_Array
  #end
#end

//=========================== PUBLIC OBJECT MACROS =============================

#macro SphereSweep_Approx (Type, v_Points, Radii, Res, Tolerance)
  #local sswp_Spline =
    SSwp__Spline (Type, v_Points, Radii, "SphereSweep_Approx")
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  sphere_sweep
  { linear_spline (sswp_Ends.y - sswp_Ends.x) * Res + 1
    #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_Pt = sswp_Spline (sswp_I / Res);
      <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t
      #local sswp_I = sswp_I + 1;
    #end
    #if (Tolerance) tolerance Tolerance #end
  }
#end

//----------------------------------------------------------

#macro SphereSweep_Blob_field (Type, v_Points, Radii, Res, Field, Use_Sturm)
  #local sswp_Spline =
    SSwp__Spline (Type, v_Points, Radii, "SphereSweep_Blob_field")
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  #local sswp_Blob = SSwp_fn_Blob_strength (1, Field);
  blob
  { #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_Pt = sswp_Spline (sswp_I / Res);
      sphere { <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t * Field, sswp_Blob }
      #local sswp_I = sswp_I + 1;
    #end
    #if (Use_Sturm) sturm #end
  }
#end

//----------------------------------------------------------

#macro SphereSweep_Blob_margin (Type, v_Points, Radii, Res, Margin, Use_Sturm)
  #local sswp_Spline =
    SSwp__Spline (Type, v_Points, Radii, "SphereSweep_Blob_margin")
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  blob
  { #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_Pt = sswp_Spline (sswp_I / Res);
      sphere
      { <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t + Margin,
        SSwp_fn_Blob_strength (sswp_Pt.t, sswp_Pt.t + Margin)
      }
      #local sswp_I = sswp_I + 1;
    #end
    #if (Use_Sturm) sturm #end
  }
#end

//----------------------------------------------------------

#macro SphereSweep_CSG (Type, v_Points, Radii, Res, Use_merge)
  SphereSweep__Core (Type, v_Points, Radii, Res, Use_merge, "SphereSweep_CSG")
#end

//----------------------------------------------------------

#macro SphereSweep_Merge (Type, v_Points, Radii, Res)
  SphereSweep__Core (Type, v_Points, Radii, Res, yes, "SphereSweep_Merge")
#end

//----------------------------------------------------------

#macro SphereSweep_Native (Type, v_Points, Radii, Tolerance)
  #local sswp_This = "SphereSweep_Native"
  #if (dimensions (v_Points) != 1)
    #error SSwp__1D_message_s (sswp_This, " of spline control points")
  #end
  #if (dimensions (Radii) != 1)
    #error SSwp__1D_message_s (sswp_This, " of radii")
  #end
  sphere_sweep
  { #switch (Type)
      #case (SSWP_LINEAR_SPLINE) linear_spline #break
      #case (SSWP_CUBIC_SPLINE) cubic_spline #break
      #case (SSWP_B_SPLINE) b_spline #break
      #case (SSWP_QUADRATIC_SPLINE)
      #case (SSWP_NATURAL_SPLINE)
      #case (SSWP_BEZIER_SPLINE)
        #error concat
        ( sswp_This, "(): ", sswp__s_Types[Type],
          " cannot be used with this macro.\n"
        )
        #break
      #else
        #error concat
        ( sswp_This, "(): Unknown spline type code ", str(Type,0,-1), ".\n"
        )
    #end
    dimension_size (v_Points, 1)
    #local sswp_I = 0;
    #while (sswp_I < dimension_size (v_Points, 1))
      v_Points [sswp_I], Radii [min (sswp_I, dimension_size (Radii, 1) - 1)]
      #local sswp_I = sswp_I + 1;
    #end
    #if (Tolerance) tolerance Tolerance #end
  }
#end

//----------------------------------------------------------

#macro SphereSweep_Union (Type, v_Points, Radii, Res)
  SphereSweep__Core (Type, v_Points, Radii, Res, no, "SphereSweep_Union")
#end

//----------------------------------------------------------

#version SPHERESWEEP__INC;
#end
