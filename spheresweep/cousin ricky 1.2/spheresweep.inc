/* spheresweep.inc version 1.2
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * This file provides well-behaved alternatives to the sphere_sweep primitive.
 *
 * Copyright 2013, 2015 Richard Callwood III.  Some rights reserved.
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
 *       2015-Aug-29  A macro is added for creating Bezier control points from
 *                    a set of points and vectors.
 *       2015-Sep-04  Error checks are added for the Res argument.
 * 1.2   2015-Sep-11  Bezier spline capability is added for most of the object
 *                    macros.
 */
#ifndef (SphereSweep_Inc_Temp) #declare SphereSweep_Inc_Temp = version;
#version 3.5;
#debug "#include \"spheresweep.inc\" //version 1.2\n"
#declare SPHERESWEEP_VERSION = 1.2;

#include "shapes.inc"

#declare SSWP_LINEAR_SPLINE = 0;
#declare SSWP_QUADRATIC_SPLINE = 1;
#declare SSWP_CUBIC_SPLINE = 2;
#declare SSWP_NATURAL_SPLINE = 3;
#declare SSWP_B_SPLINE = 4;
#declare SSWP_BEZIER_SPLINE = 5;

//============== INTERNAL AUXILIARY MACROS AND DATA STRUCTURES =================
// These macros and data structures should not be referenced directly by the
// user.

#declare sswp__s_Types = array[6]
{ "linear spline",
  "quadratic spline",
  "cubic spline",
  "natural spline",
  "B-spline",
  "Bezier spline",
}
#declare sswp__Minima = array[6] { 2, 2, 4, 2, 4, 4 }

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
  #if (Type = floor (Type) & Type >= 0 & Type <= 5)
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
    #if (Type = SSWP_BEZIER_SPLINE & mod (sswp_NPts, 4))
      #error concat
      ( s_Macro,
        "(): The number of Bezier control points must be a multiple of 4, but ",
        str (sswp_NPts, 0, 0), " were given."
      )
    #end
  #end
#end

// Checks the number of segments.
#macro SSwp__Check_res (Res, s_Macro)
  #if (Res < 1)
    #warning concat
    ( s_Macro, "(): ", str (Res, 0, -1),
      " was passed as the Res argument.  1 is used instead."
    )
  #end
  max (floor (Res), 1)
#end

// Requests user to report a SphereSweep bug.
#macro SSwp__Report (s_Macro, s_Message)
  #warning "Apparent bug in SphereSweep.  Please report the following error message to http://news.povray.org/povray.object-collection/ :"
  #error concat (s_Macro, "(): Module error: ", s_Message)
#end

// Promotes the arguments to 3-D vectors, then tests them for equality.
#macro SSwp__VEq (A, B)
  #local sswp_A = <0,0,0> + A;
  #local sswp_B = <0,0,0> + B;
  (sswp_A.x = sswp_B.x & sswp_A.y = sswp_B.y & sswp_A.z = sswp_B.z)
#end

// Creates a spline from control points and radii.
#macro SSwp__Spline (Type, v_Points, Radii, s_Macro)
  //SSwp__Check (Type, v_Points, Radii, s_Macro)
  // In practice, SSwp__Check is already called by the caller.
  spline
  { #switch (Type)
      #case (SSWP_LINEAR_SPLINE) linear_spline #break
      #case (SSWP_QUADRATIC_SPLINE) quadratic_spline #break
      #case (SSWP_CUBIC_SPLINE) cubic_spline #break
      #case (SSWP_NATURAL_SPLINE) natural_spline #break
      #case (SSWP_B_SPLINE)
        SSwp__Report (s_Macro, "SSwp__Spline() was called with SSWP_B_SPLINE.")
        #break
      #case (SSWP_BEZIER_SPLINE)
        SSwp__Report
        ( s_Macro, "SSwp__Spline() was called with SSWP_BEZIER_SPLINE."
        )
        #break
      #else
        #error concat
        ( s_Macro, "(): Unknown spline type code ", str(Type,0,-1), "."
        )
    #end
    #local sswp_MaxR = dimension_size (Radii, 1) - 1;
    #local sswp_I = 0;
    #while (sswp_I < dimension_size (v_Points, 1))
      // Warning:  Do not optimize.  Optimization may cause problems
      // if the elements of v_Points are scalar or higher than 3-D.
      #local sswp_Pt = <0,0,0> + v_Points [sswp_I];
      sswp_I, <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z, Radii [min (sswp_I, sswp_MaxR)]>
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

// Implements a 3rd degree Bezier spline from control points and radii.
#macro SSwp__Bezier_calc (T, v_Points, Radii, s_Macro)
( #local sswp_NPts = dimension_size (v_Points, 1);
  #local sswp_Pt0 = floor (T / 4) * 4;
  #local sswp_T0 = (T - sswp_Pt0) / 3;
  #local sswp_T1 = 1 - sswp_T0;
  #if (sswp_T0 > 1 | T < 0 | T >= sswp_NPts)
    SSwp__Report
    ( s_Macro,
      concat
      ( "SSwp__Bezier_calc() was called with T = ", str (T, 0, -1), " for ",
        str (sswp_NPts, 0, 0), " points."
      )
    )
  #end
  #local sswp_MaxR = dimension_size (Radii, 1) - 1;
 // Level 0 (initial)
  // Warning:  Optimizing these initializations may cause problems
  // if the elements of v_Points are scalar or higher than 3-D.
  #local sswp_A0 = <0,0,0> + v_Points [sswp_Pt0];
  #local sswp_A0 =
    <sswp_A0.x, sswp_A0.y, sswp_A0.z, Radii [min (sswp_Pt0, sswp_MaxR)]>;
  #local sswp_B0 = <0,0,0> + v_Points [sswp_Pt0+1];
  #local sswp_B0 =
    <sswp_B0.x, sswp_B0.y, sswp_B0.z, Radii [min (sswp_Pt0+1, sswp_MaxR)]>;
  #local sswp_C0 = <0,0,0> + v_Points [sswp_Pt0+2];
  #local sswp_C0 =
    <sswp_C0.x, sswp_C0.y, sswp_C0.z, Radii [min (sswp_Pt0+2, sswp_MaxR)]>;
  #local sswp_D0 = <0,0,0> + v_Points [sswp_Pt0+3];
  #local sswp_D0 =
    <sswp_D0.x, sswp_D0.y, sswp_D0.z, Radii [min (sswp_Pt0+3, sswp_MaxR)]>;
 // Level 1
  #local sswp_A1 = sswp_A0 * sswp_T1 + sswp_B0 * sswp_T0;
  #local sswp_B1 = sswp_B0 * sswp_T1 + sswp_C0 * sswp_T0;
  #local sswp_C1 = sswp_C0 * sswp_T1 + sswp_D0 * sswp_T0;
 // Level 2
  #local sswp_A2 = sswp_A1 * sswp_T1 + sswp_B1 * sswp_T0;
  #local sswp_B2 = sswp_B1 * sswp_T1 + sswp_C1 * sswp_T0;
 // Level 3 (final)
  sswp_A2 * sswp_T1 + sswp_B2 * sswp_T0
)
#end

// Parses the disjointed segments of a Bezier spline sequence.
// Returns an array of float, with element [0] containing the number of groups
// of contiguous segments, and the following elements containing the index of
// the last point of each group of contiguous segments.
#macro SSwp__Bezier_segments (v_Points, Radii)
  #local sswp_NPts = dimension_size (v_Points, 1);
  #local sswp_MaxR = dimension_size (Radii, 1) - 1;
  #local sswp_N = sswp_NPts / 4 + 1;
  #local sswp_Segs = array [sswp_N];
  #local sswp_Sx = 0;
  #local sswp_Px = 3;
  #while (sswp_Px < sswp_NPts)
    #if (sswp_Px = sswp_NPts - 1)
      #local sswp_Sx = sswp_Sx + 1;
      #local sswp_Segs [sswp_Sx] = sswp_Px;
    #else #if
    ( !SSwp__VEq (v_Points [sswp_Px], v_Points [sswp_Px+1]) |
      Radii [min (sswp_Px, sswp_MaxR)] != Radii [min (sswp_Px+1, sswp_MaxR)]
    )
      #local sswp_Sx = sswp_Sx + 1;
      #local sswp_Segs [sswp_Sx] = sswp_Px;
    #end
    #end
    #local sswp_Px = sswp_Px + 4;
  #end
  #local sswp_Segs[0] = sswp_Sx;
  sswp_Segs
#end

// If a Bezier segment ends exactly where the next segment begins, one of the
// end spheres must be dropped.  This macro determines which of the end spheres
// of a Bezier segment should be instantiated.  A 2-D vector is returned, with
// deltas for the start and end limits for a loop counter.
// Px = index of start of segment.
#macro SSwp__Bezier_ends (Px, v_Points, Radii)
( #local sswp_MaxR = dimension_size (Radii, 1) - 1;
 // Start of segment:
  #local sswp_Start = 0;
  #if (Px > 0) // never drop 1st sphere of sphere sweep.
    #if // Drop sphere if not bigger than last sphere of previous segment:
    ( SSwp__VEq (v_Points[Px], v_Points[Px - 1]) &
      Radii [min (Px, sswp_MaxR)] <= Radii [min (Px - 1, sswp_MaxR)]
    )
      #local sswp_Start = 1;
    #end
  #end
 // End of segment:
  #local sswp_End = 0;
  #if (Px < dimension_size (v_Points, 1) - 4) // never drop last sphere.
    #if // Drop sphere if smaller than 1st sphere of next segment:
    ( SSwp__VEq (v_Points[Px + 3], v_Points[Px + 4]) &
      Radii [min (Px + 3, sswp_MaxR)] < Radii [min (Px + 4, sswp_MaxR)]
    )
      #local sswp_End = -1;
    #end
  #end
  <sswp_Start, sswp_End>
)
#end

// Returns the physical endpoint indexes of a sphere sweep, according to spline
// type.  The indexes are returned in the form of a 2-D vector.
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
  #local sswp_Res = SSwp__Check_res (Res, s_Macro);
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  #if (Use_merge) merge #else union #end
  {
    #if (Type = SSWP_BEZIER_SPLINE)
      #local sswp_Seg = 0;
      #while (sswp_Seg < dimension_size (v_Points, 1))
        #local sswp_Ends = SSwp__Bezier_ends (sswp_Seg, v_Points, Radii);
        #local sswp_Old = SSwp__Bezier_calc
        ( sswp_Seg, v_Points, Radii, s_Macro
        );
       // first sphere:
        #if (sswp_Ends.x = 0)
          sphere { <sswp_Old.x, sswp_Old.y, sswp_Old.z>, sswp_Old.t }
        #end
        #local sswp_I = sswp_Seg * sswp_Res + 1;
        #local sswp_Stop = (sswp_Seg + 3) * sswp_Res ;
        #while (sswp_I <= sswp_Stop)
          #local sswp_New = SSwp__Bezier_calc
          ( sswp_I / sswp_Res, v_Points, Radii, s_Macro
          );
         // remaining spheres:
          #if (sswp_I <= sswp_Stop + sswp_Ends.y)
            sphere { <sswp_New.x, sswp_New.y, sswp_New.z>, sswp_New.t }
          #end
         // connection:
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
          #local sswp_Old = sswp_New;
          #local sswp_I = sswp_I + 1;
        #end
        #local sswp_Seg = sswp_Seg + 4;
      #end // Bezier

   // non-Bezier:
    #else
      #if (Type != SSWP_B_SPLINE)
        #local sswp_Spline = SSwp__Spline (Type, v_Points, Radii, s_Macro)
      #end
      #local sswp_First = yes;
      #local sswp_I = sswp_Ends.x * sswp_Res;
      #while (sswp_I <= sswp_Ends.y * sswp_Res)
        #local sswp_New =
          #if (Type = SSWP_B_SPLINE)
            SSwp__B_calc (sswp_I / sswp_Res, v_Points, Radii, s_Macro);
          #else
            sswp_Spline (sswp_I / sswp_Res);
          #end
       // sphere:
        sphere { <sswp_New.x, sswp_New.y, sswp_New.z>, sswp_New.t }
        #if (sswp_First)
          #local sswp_First = no;
       // connection:
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
    #end // non-Bezier
  }
#end

//=================== PUBLIC UTILITY FUNCTION AND MACROS =======================
// (See user manual for descriptions.)

#macro SSwp_Bezier (v_Ctrls, s_File, VDim, Places)
  #local sswp_This = "SSwp_Bezier"
  #if (dimensions (v_Ctrls) != 2)
    #error concat (sswp_This, "(): Array v_Ctrls must have 2 dimensions.")
  #end
  #if (dimension_size (v_Ctrls, 1) < 2)
    #error concat (sswp_This, "(): Array v_Ctrls must have at least 2 rows.")
  #end
  #if (dimension_size (v_Ctrls, 2) < 3)
    #error concat (sswp_This, "(): Array v_Ctrls must have 3 columns.")
  #end
 // Create the control points:
  #local sswp_NIn = dimension_size (v_Ctrls, 1);
  #local sswp_NOut = (sswp_NIn - 1) * 4;
  #local sswp_Out = array [sswp_NOut];
  #local sswp_I = 1;
  #while (sswp_I < sswp_NIn)
    #local sswp_J = 4 * sswp_I;
    #local sswp_Out [sswp_J-4] = v_Ctrls [sswp_I-1][1];
    #local sswp_Out [sswp_J-3] = v_Ctrls [sswp_I-1][1] + v_Ctrls [sswp_I-1][2];
    #local sswp_Out [sswp_J-2] = v_Ctrls [sswp_I][1] + v_Ctrls [sswp_I][0];
    #local sswp_Out [sswp_J-1] = v_Ctrls [sswp_I][1];
    #local sswp_I = sswp_I + 1;
  #end
 // Write the control points:
  #if (strlen (s_File) > 0)
    #local sswp_Line = str (sswp_NOut, 0, 0)
    #if (strcmp (s_File, "-"))
      #fopen sswp__F s_File write
      // Note: POV-Ray parser error message seems adequate.
      #write (sswp__F, sswp_Line)
    #else
      #debug sswp_Line
    #end
    #local sswp_J = 0;
    #while (sswp_J < sswp_NOut)
      #local sswp_Line =
        concat (",\n<", vstr (VDim, sswp_Out [sswp_J], ", ", 0, Places), ">")
      #if (strcmp (s_File, "-"))
        #write (sswp__F, sswp_Line)
      #else
        #debug sswp_Line
      #end
      #local sswp_J = sswp_J + 1;
    #end
    #if (strcmp (s_File, "-"))
      #write (sswp__F, "\n")
      #fclose sswp__F
    #else
      #debug "\n"
    #end
  #end
  sswp_Out
#end

//----------------------------------------------------------

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
// (See user manual for descriptions.)

#macro SphereSweep_Approx (Type, v_Points, Radii, Res, Tolerance)
  #local sswp_This = "SphereSweep_Approx"
  SSwp__Check (Type, v_Points, Radii, sswp_This)
  #local sswp_Res = SSwp__Check_res (Res, sswp_This);

  #if (Type = SSWP_BEZIER_SPLINE)
    #local sswp_Segs = SSwp__Bezier_segments (v_Points, Radii)
    #if (sswp_Segs[0] != 1) // more than one set of contiguous segments?
      union {
    #end
    #local sswp_T0 = 0;
    #local sswp_Sx = 1;
    #while (sswp_Sx <= sswp_Segs[0]) // loop over sets of continuous segments
      sphere_sweep // one set of contiguous segments
      { linear_spline (sswp_Segs[sswp_Sx] - sswp_T0 + 1) * 0.75 * sswp_Res + 1
        #local sswp_Pt = SSwp__Bezier_calc
        ( sswp_T0, v_Points, Radii, sswp_This
        );
        <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t
        #while (sswp_T0 < sswp_Segs[sswp_Sx])
          #local sswp_I = 1;
          #while (sswp_I <= sswp_Res * 3)
            #local sswp_Pt = SSwp__Bezier_calc
            ( sswp_T0 + sswp_I / sswp_Res, v_Points, Radii, sswp_This
            );
            <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t
            #local sswp_I = sswp_I + 1;
          #end
          #local sswp_T0 = sswp_T0 + 4;
        #end
      } // end sphere_sweep object
      #local sswp_Sx = sswp_Sx + 1; // onto the next set of contiguous segments
    #end
    #if (sswp_Segs[0] != 1)
      } // end union, if any
    #end

  #else // non-Bezier splines
    #if (Type != SSWP_B_SPLINE)
      #local sswp_Spline =
        SSwp__Spline (Type, v_Points, Radii, sswp_This)
    #end
    #local sswp_Ends = SSwp__Ends (Type, v_Points);
    sphere_sweep
    { linear_spline (sswp_Ends.y - sswp_Ends.x) * sswp_Res + 1
      #local sswp_I = sswp_Ends.x * sswp_Res;
      #while (sswp_I <= sswp_Ends.y * sswp_Res)
        #local sswp_Pt =
          #if (Type = SSWP_B_SPLINE)
            SSwp__B_calc (sswp_I / sswp_Res, v_Points, Radii, sswp_This);
          #else
            sswp_Spline (sswp_I / sswp_Res);
          #end
        <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t
        #local sswp_I = sswp_I + 1;
      #end
      #if (Tolerance) tolerance Tolerance #end
    }
  #end
#end

//----------------------------------------------------------

#macro SphereSweep_Blob_field (Type, v_Points, Radii, Res, Field, Use_Sturm)
  #local sswp_This = "SphereSweep_Blob_field"
  #local sswp_Res = SSwp__Check_res (Res, sswp_This);
  SSwp__Check (Type, v_Points, Radii, sswp_This)
  #local sswp_Blob = SSwp_fn_Blob_strength (1, Field);
  blob
  { #if (Type = SSWP_BEZIER_SPLINE)
      #local sswp_Seg = 0;
      #while (sswp_Seg < dimension_size (v_Points, 1))
        #local sswp_Ends = SSwp__Bezier_ends (sswp_Seg, v_Points, Radii);
        #local sswp_I = sswp_Seg * sswp_Res + sswp_Ends.x;
        #local sswp_Stop = (sswp_Seg + 3) * sswp_Res + sswp_Ends.y;
        #while (sswp_I <= sswp_Stop)
          #local sswp_Pt = SSwp__Bezier_calc
          ( sswp_I / sswp_Res, v_Points, Radii, sswp_This
          );
          sphere
          { <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t * Field, sswp_Blob
          }
          #local sswp_I = sswp_I + 1;
        #end
        #local sswp_Seg = sswp_Seg + 4;
      #end
    #else // non-Bezier splines
      #if (Type != SSWP_B_SPLINE)
        #local sswp_Spline = SSwp__Spline (Type, v_Points, Radii, sswp_This)
      #end
      #local sswp_Ends = SSwp__Ends (Type, v_Points);
      #local sswp_I = sswp_Ends.x * sswp_Res;
      #while (sswp_I <= sswp_Ends.y * sswp_Res)
        #local sswp_Pt =
          #if (Type = SSWP_B_SPLINE)
            SSwp__B_calc (sswp_I / sswp_Res, v_Points, Radii, sswp_This);
          #else
            sswp_Spline (sswp_I / sswp_Res);
          #end
        sphere
        { <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t * Field, sswp_Blob
        }
        #local sswp_I = sswp_I + 1;
      #end
    #end
    #if (Use_Sturm) sturm #end
  }
#end

//----------------------------------------------------------

#macro SphereSweep_Blob_margin (Type, v_Points, Radii, Res, Margin, Use_Sturm)
  #local sswp_This = "SphereSweep_Blob_margin"
  SSwp__Check (Type, v_Points, Radii, sswp_This)
  #local sswp_Res = SSwp__Check_res (Res, sswp_This);
  #local sswp_Ends = SSwp__Ends (Type, v_Points);
  blob
  { #if (Type = SSWP_BEZIER_SPLINE)
      #local sswp_Seg = 0;
      #while (sswp_Seg < dimension_size (v_Points, 1))
        #local sswp_Ends = SSwp__Bezier_ends (sswp_Seg, v_Points, Radii);
        #local sswp_I = sswp_Seg * sswp_Res + sswp_Ends.x;
        #local sswp_Stop = (sswp_Seg + 3) * sswp_Res + sswp_Ends.y;
        #while (sswp_I <= sswp_Stop)
          #local sswp_Pt = SSwp__Bezier_calc
          ( sswp_I / sswp_Res, v_Points, Radii, sswp_This
          );
          sphere
          { <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t + Margin,
            SSwp_fn_Blob_strength (sswp_Pt.t, sswp_Pt.t + Margin)
          }
          #local sswp_I = sswp_I + 1;
        #end
        #local sswp_Seg = sswp_Seg + 4;
      #end
    #else // non-Bezier splines
      #if (Type != SSWP_B_SPLINE)
        #local sswp_Spline = SSwp__Spline (Type, v_Points, Radii, sswp_This)
      #end
      #local sswp_I = sswp_Ends.x * sswp_Res;
      #while (sswp_I <= sswp_Ends.y * sswp_Res)
        #local sswp_Pt =
          #if (Type = SSWP_B_SPLINE)
            SSwp__B_calc (sswp_I / sswp_Res, v_Points, Radii, sswp_This);
          #else
            sswp_Spline (sswp_I / sswp_Res);
          #end
        sphere
        { <sswp_Pt.x, sswp_Pt.y, sswp_Pt.z>, sswp_Pt.t + Margin,
          SSwp_fn_Blob_strength (sswp_Pt.t, sswp_Pt.t + Margin)
        }
        #local sswp_I = sswp_I + 1;
      #end
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
