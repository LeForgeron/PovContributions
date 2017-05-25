/* spheresweep.inc version 1.1
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * This file provides alternatives to the sphere_sweep primitive.
 *
 * Copyright 2013 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   2013-May-22  Created.
 * 1.0   2013-Jul-22  Uploaded.
 * 1.1   2015-Aug-28  B-spline capability is added for most of the object
 *                    macros.
 * 1.1   2015-Aug-28  Array error checking is centralized.
 */
#ifndef (SphereSweep_Inc_Temp) #declare SphereSweep_Inc_Temp = version;
#version 3.5;
#debug "#include \"spheresweep.inc\" //version 1.1\n"
#declare SPHERESWEEP_VERSION = 1.1;

#include "shapes.inc"

#declare SSWP_LINEAR_SPLINE = 0;
#declare SSWP_QUADRATIC_SPLINE = 1;
#declare SSWP_CUBIC_SPLINE = 2;
#declare SSWP_NATURAL_SPLINE = 3;
#declare SSWP_B_SPLINE = 4;
#declare SSWP_BEZIER_SPLINE = 5; // Reserved for future use
#declare sswp__s_Types = array[6]
{ "linear spline",
  "quadratic spline",
  "cubic spline",
  "natural spline",
  "B-spline",
  "Bezier spline",
}
#declare sswp__Minima = array[6] { 2, 2, 4, 2, 4, 4 }

//================= INTERNAL AUXILIARY MACROS AND FUNCTIONS ====================

// Constructs an error message for a multidimensional array.
/*#macro SSwp__1D_message_s (s_Macro, s_Desc)
  concat (s_Macro, "(): Array", s_Desc, " must be 1 dimensional.")
#end*/

// Throws an error message if an array is multidimensional.
#macro SSwp__Check_1D (Array, s_Macro, s_Desc)
  #if (dimensions (Array) != 1)
    #error concat (s_Macro, "(): Array", s_Desc, " must be 1 dimensional.")
  #end
#end

// Array error checking.
#macro SSwp__Check (Type, v_Points, Radii, s_Macro)
  SSwp__Check_1D (v_Points, s_Macro, " of spline control points")
  SSwp__Check_1D (Radii, s_Macro, " of radii")
  //@@ Change Type <= 4 to Type <= 5 if Bezier spline is implemented.
  #if (Type = floor (Type) & Type >= 0 & Type <= 4)
    #local sswp_NPts = dimension_size (v_Points, 1);
    #if (sswp_NPts < sswp__Minima [Type])
      #error concat
      ( s_Macro, "(): A ", sswp__s_Types [Type], " requires a minimum of ",
        str (sswp__Minima [Type], 0, 0), " control points.  Only ",
        #if (sswp_NPts = 1)
          "one was given."
        #else
          str (sswp_NPts, 0, 0), " were given."
        #end
      )
    #end
  #end
#end

// Requests user to report an internal error.
#macro SSwp__Report()
  #warning "Please report the following error message to http://news.povray.org/povray.object-collection/ :"
#end

// Creates a spline from control points and radii.
#macro SSwp__Spline (Type, v_Points, Radii, s_Macro)
  //SSwp__Check (Type, v_Points, Radii, s_Macro)
  spline
  { #switch (Type)
      #case (SSWP_LINEAR_SPLINE) linear_spline #break
      #case (SSWP_QUADRATIC_SPLINE) quadratic_spline #break
      #case (SSWP_CUBIC_SPLINE) cubic_spline #break
      #case (SSWP_NATURAL_SPLINE) natural_spline #break
      #case (SSWP_B_SPLINE)
        SSwp__Report()
        #error concat
        ( s_Macro,
          "(): Internal error: SSwp__Spline() was called with SSWP_B_SPLINE."
        )
        #break
      #case (SSWP_BEZIER_SPLINE)
        #error 
        concat
        ( s_Macro, "(): ", sswp__s_Types[Type],
          " cannot be used with this version of spheresweep.inc."
        )
        #break
      #else
        #error concat
        ( s_Macro, "(): Unknown spline type code ", str(Type,0,-1), "."
        )
    #end
    #local sswp_I = 0;
    #while (sswp_I < dimension_size (v_Points, 1))
      // Warning:  Do not optimize.  Optimization may cause problems
      // if the elements of v_Points are scalar or higher than 3-D.
      #local sswp_Pt = <0,0,0> + v_Points [sswp_I];
      sswp_I,
      < sswp_Pt.x, sswp_Pt.y, sswp_Pt.z,
        Radii [min (sswp_I, dimension_size (Radii, 1) - 1)]
      >
      #local sswp_I = sswp_I + 1;
    #end
  }
#end

// Implements a B-spline from control points and radii.  De Boor's algorithm is
// used, simplified to assume a 3rd degree spline with u(l) = l.
#macro SSwp__B_calc (T, v_Points, Radii, s_Macro)
( #local sswp_MaxR = dimension_size (Radii, 1) - 1;
 // Level 0 (initial)
  #local sswp_L = min (floor (T + 2), dimension_size (v_Points, 1) - 1);
  #local sswp_X = T + 2 - sswp_L;
  // Warning:  Optimizing these initializations may cause problems
  // if the elements of v_Points are scalar or higher than 3-D.
  #local sswp_A0 = <0,0,0> + v_Points [sswp_L-3];
  #local sswp_A0 =
    <sswp_A0.x, sswp_A0.y, sswp_A0.z, Radii [min (sswp_L-3, sswp_MaxR)]>;
  #local sswp_B0 = <0,0,0> + v_Points [sswp_L-2];
  #local sswp_B0 =
    <sswp_B0.x, sswp_B0.y, sswp_B0.z, Radii [min (sswp_L-2, sswp_MaxR)]>;
  #local sswp_C0 = <0,0,0> + v_Points [sswp_L-1];
  #local sswp_C0 =
    <sswp_C0.x, sswp_C0.y, sswp_C0.z, Radii [min (sswp_L-1, sswp_MaxR)]>;
  #local sswp_D0 = <0,0,0> + v_Points [sswp_L];
  #local sswp_D0 =
    <sswp_D0.x, sswp_D0.y, sswp_D0.z, Radii [min (sswp_L, sswp_MaxR)]>;
 // Level 1
  #local sswp_Alpha = (sswp_X + 2) / 3;
  #local sswp_B1 = (1 - sswp_Alpha) * sswp_A0 + sswp_Alpha * sswp_B0;
  #local sswp_Alpha = (sswp_X + 1) / 3;
  #local sswp_C1 = (1 - sswp_Alpha) * sswp_B0 + sswp_Alpha * sswp_C0;
  #local sswp_Alpha = sswp_X / 3;
  #local sswp_D1 = (1 - sswp_Alpha) * sswp_C0 + sswp_Alpha * sswp_D0;
 // Level 2
  #local sswp_Alpha = (sswp_X + 1) / 2;
  #local sswp_C2 = (1 - sswp_Alpha) * sswp_B1 + sswp_Alpha * sswp_C1;
  #local sswp_Alpha = sswp_X / 2;
  #local sswp_D2 = (1 - sswp_Alpha) * sswp_C1 + sswp_Alpha * sswp_D1;
 // Level 3 (final)
  (1 - sswp_X) * sswp_C2 + sswp_X * sswp_D2
)
#end

// Returns the physical endpoint indexes of a sphere sweep,
// according to spline type.
#macro SSwp__Ends (Type, v_Points)
( #switch (Type)
    #case (SSWP_CUBIC_SPLINE)
    #case (SSWP_B_SPLINE)
      <1, dimension_size (v_Points, 1) - 2>
      #break
    #else
      <0, dimension_size (v_Points, 1) - 1>
  #end
)
#end

// Assembles a sphere sweep approximation from spheres and cones.
#macro SphereSweep__Core (Type, v_Points, Radii, Res, Use_merge, s_Macro)
  SSwp__Check (Type, v_Points, Radii, s_Macro)
  #if (Type != SSWP_B_SPLINE)
    #local sswp_Spline = SSwp__Spline (Type, v_Points, Radii, s_Macro)
  #end
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  #if (Use_merge) merge #else union #end
  { #local sswp_First = yes;
    #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_New =
        #if (Type = SSWP_B_SPLINE)
          SSwp__B_calc (sswp_I / Res, v_Points, Radii, s_Macro);
        #else
          sswp_Spline (sswp_I / Res);
        #end
      sphere { <sswp_New.x, sswp_New.y, sswp_New.z>, sswp_New.t }
      #if (sswp_First)
        #local sswp_First = no;
      #else
        #if // Check for extreme change of radius:
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

#declare SSwp_fn_Blob_strength = function (sswp_P0_RSurface, sswp_P1_RField)
{ 1 / pow (1 - pow (sswp_P0_RSurface / sswp_P1_RField, 2), 2)
}

//----------------------------------------------------------

#macro SSwp_Subarray (Array, Start, End)
  #local sswp_This = "SSwp_Subarray"
  SSwp__Check_1D (Array, sswp_This, "")
  #local sswp_Nfrom = dimension_size (Array, 1);
  #if (Start < 0)
    #warning concat
    ( sswp_This, "(): Start index ", str(Start,0,-1),
      " is negative; zero will be used instead."
    )
  #end
  #if (End >= sswp_Nfrom)
    #warning concat
    ( sswp_This, "(): End index ", str(End,0,-1),
      " is beyond the end of the given array; ",
      str (sswp_Nfrom-1, 0, 0), " will be used instead."
    )
  #end
  #local sswp_Start = max (floor (Start), 0);
  #local sswp_End = min (floor (End), sswp_Nfrom-1);
  #if (sswp_End < sswp_Start)
    #warning concat
    ( sswp_This, "(): End index ", str(End,0,-1),
      " is less than Start index ", str(Start,0,-1),
      "; no values will be returned."
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
  #local sswp_This = "SphereSweep_Approx"
  SSwp__Check (Type, v_Points, Radii, sswp_This)
  #if (Type != SSWP_B_SPLINE)
    #local sswp_Spline =
      SSwp__Spline (Type, v_Points, Radii, sswp_This)
  #end
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  sphere_sweep
  { linear_spline (sswp_Ends.y - sswp_Ends.x) * Res + 1
    #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_Pt =
        #if (Type = SSWP_B_SPLINE)
          SSwp__B_calc (sswp_I / Res, v_Points, Radii, sswp_This);
        #else
          sswp_Spline (sswp_I / Res);
        #end
      <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t
      #local sswp_I = sswp_I + 1;
    #end
    #if (Tolerance) tolerance Tolerance #end
  }
#end

//----------------------------------------------------------

#macro SphereSweep_Blob_field (Type, v_Points, Radii, Res, Field, Use_Sturm)
  #local sswp_This = "SphereSweep_Blob_field"
  SSwp__Check (Type, v_Points, Radii, sswp_This)
  #if (Type != SSWP_B_SPLINE)
    #local sswp_Spline =
      SSwp__Spline (Type, v_Points, Radii, sswp_This)
  #end
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  #local sswp_Blob = SSwp_fn_Blob_strength (1, Field);
  blob
  { #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_Pt =
        #if (Type = SSWP_B_SPLINE)
          SSwp__B_calc (sswp_I / Res, v_Points, Radii, sswp_This);
        #else
          sswp_Spline (sswp_I / Res);
        #end
      sphere { <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t * Field, sswp_Blob }
      #local sswp_I = sswp_I + 1;
    #end
    #if (Use_Sturm) sturm #end
  }
#end

//----------------------------------------------------------

#macro SphereSweep_Blob_margin (Type, v_Points, Radii, Res, Margin, Use_Sturm)
  #local sswp_This = "SphereSweep_Blob_margin"
  SSwp__Check (Type, v_Points, Radii, sswp_This)
  #if (Type != SSWP_B_SPLINE)
    #local sswp_Spline =
      SSwp__Spline (Type, v_Points, Radii, sswp_This)
  #end
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  blob
  { #local sswp_I = sswp_Ends.x * Res;
    #while (sswp_I <= sswp_Ends.y * Res)
      #local sswp_Pt =
        #if (Type = SSWP_B_SPLINE)
          SSwp__B_calc (sswp_I / Res, v_Points, Radii, sswp_This);
        #else
          sswp_Spline (sswp_I / Res);
        #end
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
          " cannot be used with this macro."
        )
        #break
      #else
        #error concat
        ( sswp_This, "(): Unknown spline type code ", str(Type,0,-1), "."
        )
    #end
    SSwp__Check (Type, v_Points, Radii, sswp_This)
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

#version SphereSweep_Inc_Temp;
#end
// end of spheresweep.inc
