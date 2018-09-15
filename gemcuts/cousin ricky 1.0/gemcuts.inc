/* gemcuts.inc version 1.0
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Gem cuts and accessories.
 *
 * Copyright 2018 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 *        2017-Mar-10  Started.
 * 1.0    2018-Feb-27  Round brilliant and emerald cuts are implemented.
 */
#ifndef (GemCuts_Inc_Temp) #declare GemCuts_Inc_Temp = version;
#version 3.6;
#debug "#include \"gemcuts.inc\" //version 1.0\n"
#declare GEMCUTS_VERSION = 1.0;

#include "shapes.inc"

//============================= PRIVATE FEATURES ===============================
// These features are not intended for direct use by the end user.

#ifndef (gem__Debug) #declare gem__Debug = off; #end

/* Checks that a linear argument is within non-negative range.
 *   s_This - the name of the calling macro
 *   s_Arg  - the formal parameter name
 *   Value  - the value to be checked
 */
#macro Gem__range0 (s_This, s_Arg, Value)
  #if (Value < 0 | Value >= 1)
    #error concat
    ( s_This, "(): ", s_Arg, " was set to ", str (Value, 0, -1),
      "; it must be non-negative and less than 1."
    )
  #end
#end

/* Checks that a linear argument is within positive range.
 *   s_This - the name of the calling macro
 *   s_Arg  - the formal parameter name
 *   Value  - the value to be checked
 */
#macro Gem__range1 (s_This, s_Arg, Value)
  #if (Value <= 0 | Value >= 1)
    #error concat
    ( s_This, "(): ", s_Arg, " was set to ", str (Value, 0, -1),
      "; it must be between 0 and 1 noninclusive."
    )
  #end
#end

/* Checks the range of an angular argument.
 *   s_This - the name of the calling macro
 *   s_Arg  - the formal parameter name
 *   Value  - the value to be checked
 */
#macro Gem__range90 (s_This, s_Arg, Value)
  #if (Value <= 0 | Value >= 90)
    #error concat
    ( s_This, "(): ", s_Arg, " was set to ", str (Value, 0, -1),
      "; it must be between 0 and 90 noninclusive."
    )
  #end
#end

/* Checks that an argument is positive.
 *   s_This - the name of the calling macro
 *   s_Arg  - the formal parameter name
 *   Value  - the value to be checked
 */
#macro Gem__range_pos (s_This, s_Arg, Value)
  #if (Value <= 0)
    #error concat
    ( s_This, "(): ", s_Arg, " was set to ", str (Value, 0, -1),
      "; it must be positive."
    )
  #end
#end

// Cosines of round brilliant star indexes:
#declare gem__cStar = cos (radians (22.5)); // star facets
#declare gem__cGirdle = cos (radians (11.25)); // girdle (break) facets

// Returns an array of setting prong longitudinal angles, in degrees.
#macro Gem__Prong_thetas (Gemstone, nProngs)
  #if (gem__Debug)
    #debug concat
    ( "Gem__Prong_thetas(): <",
      vstr (3, min_extent (Gemstone), ", ", 0, 3), ">...<",
      vstr (3, max_extent (Gemstone), ", ", 0, 3), ">, ",
      str (nProngs, 0, -1), "\n"
    )
  #end
  #local gem_Angles = array[nProngs] // prong longitudinal angles
  #local gem_P = 0;
  #while (gem_P < nProngs)
    // Determine longitudinal angle:
    // Note: trace() occasionally misses if exactly 0.5 is used.
    #local gem_V = vrotate (z, (gem_P + 0.500001) / nProngs * 360 * y);
    #if (gem__Debug)
      #debug concat ("  Initial V = <", vstr (3, gem_V, ", ", 0, 4), ">\n")
    #end
    // Adjust for any gem asymmetry:
    #local gem_V =
    < ( gem_V.x > 0?
        max_extent (Gemstone).x: -min_extent (Gemstone).x
      ) * gem_V.x,
      0,
      ( gem_V.z > 0?
        max_extent (Gemstone).z: -min_extent (Gemstone).z
      ) * gem_V.z
    >;
    #local gem_Angles [gem_P] = -degrees (atan2 (gem_V.z, gem_V.x));
    #if (gem__Debug)
      #debug concat
      ( "  Adjusted V = <", vstr (3, gem_V, ", ", 0, 4), ">, Angles[",
        str (gem_P, 0, 0), "] = ", str (gem_Angles [gem_P], 0, 1), " degrees\n"
      )
    #end
    #local gem_P = gem_P + 1;
  #end
  gem_Angles
#end

/* Returns the distance between a 3rd degree Bezier anchor point and the
 * adjacent control point that yields a near-circular arc of radius 1.
 *   x - the angle in radians of ABC, where A and C are Bezier anchor points,
 *       each 1 unit away from point B
 * Warning:  x must be positive.
 * Warning:  The curve deviates markedly from the circle if x > ~radians(90).
 */
#declare Gem__fn_Bezier_arc = function (x)
{ (8 * cos (x / 2) - 4 - 4 * cos (x)) / (3 * sin (x))
}

/* Returns the distance between 3rd degree Bezier anchor points and the
 * adjacent control points that yields a half-ovoid of semi-axis length x.
 * The anchor points are assumed to be 1 unit apart.
 */
#declare Gem__fn_Bezier_hump = function (x)
{ 4/3 * x
}

/* Computes a blob's field strength, given the surface radius and field radius.
 * See RoundEdge in the Object Collection for more like this.
 */
#declare Gem__fn_Blob = function (gem_P0_RSurface, gem_P1_RField)
{ 1 / pow (1 - pow (gem_P0_RSurface / gem_P1_RField, 2), 2)
}

// Setting prong parts:
#local GEM__TILT = 15;
#declare GEM__COSTILT = cos (radians (GEM__TILT));
#declare GEM__SINTILT = sin (radians (GEM__TILT));
#declare GEM__RTOP = 1 / GEM__SINTILT;

#declare gem__Prong_top = union
{ sphere { 0, 1 }
  intersection
  { sphere { 0, 1 }
    box { <-1, 0, -1>, <0, 1, 1> }
    scale <1.5, 1, 1>
  }
  intersection
  { sphere { 0, 1 scale <1.5, 2/3, 1> }
    plane { x, 0 }
  }
  rotate -25 * z
  scale <1, 4/3, 1>
}

#declare gem__Prong_heel = intersection
{ torus { GEM__RTOP, 1 rotate 90 * x }
  plane { <-GEM__SINTILT, -GEM__COSTILT, 0>, 0 }
 // For more efficient bounding, a box is used instead of a plane
  box
  { <(GEM__RTOP - 1) * GEM__COSTILT, -GEM__RTOP - 1, -1>,
    <GEM__RTOP + 1, 0, 1>
  }
  translate -GEM__RTOP * x
}

//======================= PUBLIC REFERENCE IDENTIFIERS =========================

// Cut arguments:
#declare GEM_AMERICAN_CROWN = 34.5;
#declare GEM_AMERICAN_PAVILION = 40.75;
#declare GEM_AMERICAN_TABLE = 0.530;
#declare GEM_EPPLER_CROWN = 33.2;
#declare GEM_EPPLER_PAVILION = 40.8;
#declare GEM_EPPLER_TABLE = 0.560;
#declare GEM_EULITZ_CROWN = 33.6;
#declare GEM_EULITZ_GIRDLE = 0.015;
#declare GEM_EULITZ_PAVILION = 40.8;
#declare GEM_EULITZ_TABLE = 0.565;
#declare GEM_PRFINE_CROWN = GEM_EPPLER_CROWN;
#declare GEM_PRFINE_PAVILION = GEM_EPPLER_PAVILION;
#declare GEM_PRFINE_TABLE = GEM_EPPLER_TABLE;
#declare GEM_IDEAL_CROWN = 41.1;
#declare GEM_IDEAL_PAVILION = 38.7;
#declare GEM_IDEAL_TABLE = 0.561;
#declare GEM_PARKER_CROWN = 25.5;
#declare GEM_PARKER_PAVILION = 40.9;
#declare GEM_PARKER_TABLE = 0.559;
#declare GEM_SCAND_CROWN = 34.5;
#declare GEM_SCAND_PAVILION = 40.75;
#declare GEM_SCAND_TABLE = 0.575;
#declare GEM_TOLKOWSKY_CROWN = GEM_AMERICAN_CROWN;
#declare GEM_TOLKOWSKY_PAVILION = GEM_AMERICAN_PAVILION;
#declare GEM_TOLKOWSKY_TABLE = GEM_AMERICAN_TABLE;

// Setting types:
#declare GEM_OPEN = 0;
#declare GEM_CLOSED = 1;
#declare GEM_HOLE = 2;
// Rail implementation:
#declare GEM_NONE = 0;
#declare GEM_SEGMENTED = 1;
#declare GEM_CURVED = 2;

//============================ PUBLIC CUT MACROS ===============================

#macro Gem_Emerald_cut
( Ratio, Table, Corner, aCrown1, aCrown2, aCrown3,
  aPavilion1, aPavilion2, aPavilion3, aPavilion4, Girdle, Culet
)
  #local gem_s_This = "Gem_Emerald_cut"
 // Range checks:
  #if (Ratio < 1)
    #error concat
    ( gem_s_This, "(): Ratio was set to ", str (Ratio, 0, -1),
      ".  It must not be less than 1."
    )
  #end
  Gem__range1 (gem_s_This, "Table", Table)
  #if (Corner <= 0 | Corner >= 0.5)
    #error concat
    ( gem_s_This, "(): Corner was set to ", str (Corner, 0, -1),
      ".  It must be positive and less than 0.5."
    )
  #end
  Gem__range90 (gem_s_This, "aCrown1", aCrown1)
  Gem__range90 (gem_s_This, "aCrown2", aCrown2)
  Gem__range90 (gem_s_This, "aCrown3", aCrown3)
  Gem__range90 (gem_s_This, "aPavilion1", aPavilion1)
  Gem__range90 (gem_s_This, "aPavilion2", aPavilion2)
  Gem__range90 (gem_s_This, "aPavilion3", aPavilion3)
  #if (aPavilion4 < 0 | aPavilion4 >= 90)
    #error concat
    ( gem_s_This, "(): aPavilion4 was set to ", str (aPavilion4, 0, -1),
      ".  It must be non-negative and less than 90."
    )
  #end
  Gem__range0 (gem_s_This, "Girdle", Girdle)
  Gem__range0 (gem_s_This, "Culet", Culet)
 //
  #local gem_Has_girdle = (Girdle != 0);
  #local gem_Has4 = (aPavilion4 != 0);
  #local gem_Xtra = gem_Has4 + gem_Has_girdle;
  #local gem_Steps = array[9]
  #local gem_Steps[0] = <Culet, 0, Culet>;
  #local gem_Dz = (1 - Culet) / (3 + gem_Has4);
  #local gem_Side = 1 - Corner * 2;
  #local gem_Steps[1] =
  < Culet + gem_Dz * gem_Side,
    tan (radians (gem_Has4? aPavilion4: aPavilion3)) * gem_Dz,
    Culet + gem_Dz
  >;
  #if (gem_Has4)
    #local gem_Steps[2] = gem_Steps[1]
      + <gem_Side, tan (radians (aPavilion3)), 1> * gem_Dz;
  #end
  #local gem_Steps [2 + gem_Has4] = gem_Steps [1 + gem_Has4]
    + <gem_Side, tan (radians (aPavilion2)), 1> * gem_Dz;
  #local gem_Steps [3 + gem_Has4] =
  < gem_Side,
    tan (radians (aPavilion1)) * gem_Dz + gem_Steps[2 + gem_Has4].y,
    1
  >;
  #if (gem_Has_girdle)
    #local gem_Steps [4 + gem_Has4] =
      gem_Steps [3 + gem_Has4] + <0, Girdle * 2, 0>;
    #local gem_ixCrown = 4 + gem_Has4;
  #else
    #local gem_ixCrown = 3 + gem_Has4;
  #end
  #local gem_Dz = (1 - Table) / 3;
  #local gem_Steps [gem_ixCrown + 1] = gem_Steps [gem_ixCrown]
    + <-gem_Side, tan (radians (aCrown1)), -1> * gem_Dz;
  #local gem_Steps [gem_ixCrown + 2] = gem_Steps [gem_ixCrown + 1]
    + <-gem_Side, tan (radians (aCrown2)), -1> * gem_Dz;
  #local gem_Steps [gem_ixCrown + 3] = gem_Steps [gem_ixCrown + 2]
    + <-gem_Side, tan (radians (aCrown3)), -1> * gem_Dz;
  #if (gem__Debug)
    #debug concat (gem_s_This, "() key points:\n")
    #local gem_I = 0;
    #while (gem_I <= 6 + gem_Xtra)
      #debug concat
      ( str (gem_I, 0, 0), ": <", vstr (3, gem_Steps[gem_I], ", ", 0, 6), ">\n"
      )
      #local gem_I = gem_I + 1;
    #end
  #end
  mesh2
  { vertex_vectors
    { 52 + 8 * gem_Xtra,
      #local gem_zOfs = Ratio - 1;
      gem_zOfs * z + gem_Steps[0],
      (gem_zOfs * z + gem_Steps[0]) * <1, 1, -1>,
      (gem_zOfs * z + gem_Steps[0]) * <-1, 1, -1>,
      (gem_zOfs * z + gem_Steps[0]) * <-1, 1, 1>,
      #local gem_I = 1;
      #while (gem_I <= 6 + gem_Has4 + gem_Has_girdle)
        #local gem_Pt1 = gem_Steps[gem_I] + gem_zOfs * z;
        #local gem_Pt2 =
        < gem_Steps[gem_I].z,
          gem_Steps[gem_I].y,
          gem_Steps[gem_I].x + gem_zOfs
        >;
        gem_Pt1, gem_Pt2,
        gem_Pt2 * <1, 1, -1>, gem_Pt1 * <1, 1, -1>,
        gem_Pt1 * <-1, 1, -1>, gem_Pt2 * <-1, 1, -1>,
        gem_Pt2 * <-1, 1, 1>, gem_Pt1 * <-1, 1, 1>
        #local gem_I = gem_I + 1;
      #end
    }
    face_indices
    { (5 + gem_Xtra) * 16 +
      #if (Culet > 0)
        20,
        <0, 1, 2>, <0, 2, 3>,
        <0, 4, 5>, <0, 5, 6>, <0, 6, 1>, <1, 6, 7>,
        <1, 7, 8>, <1, 8, 2>, <2, 8, 9>, <2, 9, 10>,
        <2, 10, 3>, <3, 10, 11>, <3, 11, 4>, <3, 4, 0>
      #else #if (Ratio > 1)
        16,
        <0, 4, 5>, <0, 5, 6>, <0, 6, 1>, <1, 6, 7>, <1, 7, 8>,
        <1, 8, 9>, <1, 9, 10>, <1, 10, 0>, <0, 10, 11>, <0, 11, 4>
      #else
        14,
        <0, 4, 5>, <0, 5, 6>, <0, 6, 7>, <0, 7, 8>,
        <0, 8, 9>, <0, 9, 10>, <0, 10, 11>, <0, 11, 4>
      #end
      #end
      #local gem_I = 4;
      #while (gem_I <= 36 + gem_Xtra * 8)
        #local gem_J = 0;
        #while (gem_J <= 6)
          <0, 8, 9> + gem_I + gem_J, <0, 9, 1> + gem_I + gem_J
          #local gem_J = gem_J + 1;
        #end
        <7, 15, 8> + gem_I, <7, 8, 0> + gem_I
        #local gem_I = gem_I + 8;
      #end
      #local gem_J = 1;
      #while (gem_J <= 6)
        <0, gem_J, gem_J + 1> + 44 + gem_Xtra * 8
        #local gem_J = gem_J + 1;
      #end
    }
   // a vector not parallel to any facet:
    inside_vector vrotate
    ( z,
      < ( max
          ( aCrown1, aCrown2, aCrown3,
            aPavilion1, aPavilion2, aPavilion3, aPavilion4
          ) + 90
        ) / 2,
        22.5,
        0
      >
    )
    scale 0.5
  }
#end

//----------------------------------------------------------
/* Round brilliant implementation note:  I tested 3 model paradigms, a pure CSG
 * model, a pure mesh, and a mesh-cylinder intersection.  As expected, the pure
 * CSG model was the slowest in all tests.  But when tested with refraction,
 * dispersion, and photons, the mesh-cylinder intersection turned out slightly
 * faster than the pure mesh.  I figure that this is because, in order to model
 * the curvature of the girdle, the pure mesh required many more triangles than
 * the mesh-cylinder intersection.
 * An additional benefit of the mesh-cylinder intersection over a pure mesh is
 * that it does not require special handling for knife-edge girdles or a zero
 * culet.
 */
#macro Gem_Round_brilliant
( Table, aCrown, aPavilion, Girdle, Star, Lower_girdle, Culet
)
  #local gem_s_This = "Gem_Round_brilliant"
 // Range checks:
  Gem__range1 (gem_s_This, "Table", Table)
  Gem__range90 (gem_s_This, "aCrown", aCrown)
  Gem__range90 (gem_s_This, "aPavilion", aPavilion)
  Gem__range0 (gem_s_This, "Girdle", Girdle)
  Gem__range1 (gem_s_This, "Star", Star)
  Gem__range1 (gem_s_This, "Lower_girdle", Lower_girdle)
  Gem__range0 (gem_s_This, "Culet", Culet)
 // Convert angular parameters to linear:
  #local gem_Crown = Gem_fn_1Step_height (Table, aCrown);
  #local gem_Pavilion = Gem_fn_1Step_height (0, aPavilion);
// The gemstone is constructed with the table at y = 0;
// it is translated at the end so that the culet is at y = 0.
 // Calculate key values:
  #local gem_Star = Table * gem__cStar * (1 - Star) + Star;
  // Implementation note: gem_Lower represents a previous method (discontinued
  // prior to the completion of GemCuts 1.0) that I used for specifying the
  // lower girdle length, and the gem_?Lower values derive from that method.
  #local gem_Lower = (1 - (1 - Lower_girdle) * gem__cStar) * gem_Pavilion;
  #local gem_hLower = 2 * gem_Lower;
  #local gem_rLower = (1 - gem_Lower / gem_Pavilion) / gem__cStar;
  #local gem_xLower = gem_rLower * gem__cGirdle;
  #local gem_yLower = -2 * (gem_Crown + Girdle) - gem_hLower;
 // Calculate unrotated points:
  #local gem_Pt1 =
  < 0,
    2 * gem_Crown * (Table - gem_Star * gem__cStar) / (1 - Table),
    gem_Star
  >;
  #local gem_lv_StarCusp = vrotate (gem_Pt1, 22.5 * y);
  #local gem_lv_UpperGirdle = <0, -2 * gem_Crown, 1>;
  #local gem_lv_LowerGirdle = <0, -2 * (gem_Crown + Girdle), 1>;
  #local gem_lv_LowerCusp = vrotate (<0, gem_yLower, gem_rLower>, 22.5 * y);
  // Determine the extent of excess girdle to be trimmed by the cylinder:
  #local gem_Plane = plane // a lower girdle facet to intersect
  { <0, gem_xLower - gem__cGirdle, gem_hLower>, 0
    translate <0, gem_yLower, gem_xLower>
    rotate 11.25 * y
  }
  #local gem_lv_GirdleExcess =
    trace (gem_Plane, gem_Pt1, gem_lv_UpperGirdle - gem_Pt1);
  // Check for a knife-edge girdle (non-fatal):
  #local gem_v_Flat = gem_lv_GirdleExcess * <1, 0, 1>;
  #if (vlength (gem_v_Flat + vrotate (gem_v_Flat, 22.5 * y)) <= 2)
    #warning concat
    ( gem_s_This, "(): the Girdle value of ", str (Girdle, 0, -1),
      " results in a knife-edge.  Increase the value to avoid this."
    )
  #end
 //
  intersection
  { mesh2
    { vertex_vectors
      { 57,
        #local gem_I = 0;
        #while (gem_I < 8)
          vrotate (Table * z, 45 * gem_I * y),
          #local gem_I = gem_I + 1;
        #end
        #local gem_I = 0;
        #while (gem_I < 8)
          vrotate (gem_lv_StarCusp, gem_I * 45 * y),
          #local gem_I = gem_I + 1;
        #end
        #local gem_I = 0;
        #while (gem_I < 8)
          vrotate (gem_lv_UpperGirdle, gem_I * 45 * y),
          #local gem_I = gem_I + 1;
        #end
        #local gem_I = 0;
        #while (gem_I < 16)
          vrotate (gem_lv_GirdleExcess, gem_I * 22.5 * y),
          #local gem_I = gem_I + 1;
        #end
        #local gem_I = 0;
        #while (gem_I < 8)
          vrotate (gem_lv_LowerGirdle, gem_I * 45 * y),
          #local gem_I = gem_I + 1;
        #end
        #local gem_I = 0;
        #while (gem_I < 8) // cusps of lower girdle facets
          vrotate (gem_lv_LowerCusp, gem_I * 45 * y),
          #local gem_I = gem_I + 1;
        #end
        -2 * (gem_Crown + Girdle + gem_Pavilion) * y // bottom cusp
      }
      face_indices
      { 110,
        #local gem_I = 1;
        #while (gem_I < 7) // table
          <0, gem_I, gem_I + 1>
          #local gem_I = gem_I + 1;
        #end
        #local gem_I = 0;
        #while (gem_I < 8)
          #local gem_Next = mod (gem_I + 1, 8);
          #local gem_Prev = mod (gem_I + 7, 8);
         // star facets
          <gem_I, gem_Next, gem_I + 8>
         // bezel facets
          <gem_I, gem_I + 16, gem_I + 8>
          <gem_I, gem_I + 16, gem_Prev + 8>
         // upper girdle facets
          <gem_I + 8, gem_I * 2 + 25, gem_I + 16>
          <gem_I + 8, gem_I * 2 + 25, gem_Next + 16>
         // lower girdle facets
          <gem_I + 48, gem_I * 2 + 25, gem_I + 40>
          <gem_I + 48, gem_I * 2 + 25, gem_Next + 40>
         // pavilion
          <gem_I + 40, gem_I + 48, gem_Prev + 48>
          <56, gem_I + 48, gem_Prev + 48>
         // girdle excess (to be trimmed by the cylinder)
          <gem_I + 16, gem_I * 2 + 24, gem_I * 2 + 25>
          <gem_I + 16, gem_I * 2 + 24, gem_Prev * 2 + 25>
          <gem_I + 40, gem_I * 2 + 24, gem_I * 2 + 25>
          <gem_I + 40, gem_I * 2 + 24, gem_Prev * 2 + 25>
          #local gem_I = gem_I + 1;
        #end
      }
      inside_vector y
      scale 0.5
    }
    #local gem_Height = gem_Crown + Girdle + gem_Pavilion * (1 - Culet);
    cylinder { 0.01 * y, -gem_Height * y, 0.5 }
    translate gem_Height * y
  }
#end

//================= PUBLIC ACCESSORIES AND AUXILIARY MACROS ====================

//----------------------------------------------------------
/* Implementation note:  In order to shorten render times, Untextured_gem is
 * differenced individually from each part, instead of the whole prong.
 */
#macro Gem_Prong
( Untextured_gem, Girdle, yGirdle_max, Base_test, yBase, R, Theta
)
  #local gem_This = "Gem_Prong"
  #local gem_v_Max = max_extent (Untextured_gem);
  #local gem_v_Min = min_extent (Untextured_gem);
 // a radius that is always outside the gem:
  #local gem_Outside =
    max (gem_v_Max.x, -gem_v_Min.x, gem_v_Max.z, -gem_v_Min.z) * 2;
 // Find the contact points, then rotate them into the x-y plane:
  #local gem_yTrace = yGirdle_max - Girdle / 2;
  #local gem_lv_Trace = vrotate (gem_Outside * x, Theta * y);
  #local gem_v_Norm = <0,0,0>;
  #local gem_lv_Seat = vrotate
  ( trace
    ( Untextured_gem, gem_yTrace * y + gem_lv_Trace, -gem_lv_Trace, gem_v_Norm
    ),
    -Theta * y
  ) + R * 0.15 * x;
 // Check for a missed trace:
  #if (vlength (gem_v_Norm) = 0)
    #warning concat
    ( gem_This, "(): Girdle = ", str (Girdle, 0, -1),
      ", yGirdle_max = ", str (yGirdle_max, 0, -1),
      "; gemstone bottom y = ", str (gem_v_Min.y, 0, -1),
      ", top y = ", str (gem_v_Max.y, 0, -1), "."
    )
    #if (gem_yTrace < gem_v_Min.y)
      #local gem_Msg = "the prong seat is below the gemstone."
    #else #if (gem_yTrace > gem_v_Max.y)
      #local gem_Msg = "the prong seat is above the gemstone."
    #else
      #local gem_Msg = "is the gemstone centered about the y-axis?"
    #end
    #end
    #error concat
    ( gem_This, "(): unable to make contact with the gemstone: ", gem_Msg
    )
  #end
 //
  #local gem_Test = Center_Object (Base_test, y)
  #local gem_lv_Join = vrotate
  ( trace (gem_Test, 0, gem_lv_Trace) + yBase * y,
    -Theta * y
  );
  union
  { difference
    { object
      { gem__Prong_top
        scale R
        translate <gem_lv_Seat.x, yGirdle_max, 0>
        rotate Theta * y
      }
      object { Untextured_gem }
    }
    difference
    { object
      { gem__Prong_heel
        scale R
        translate <gem_lv_Seat.x, yGirdle_max, 0>
        rotate Theta * y
      }
      object { Untextured_gem }
    }
   // main length of prong:
    #local gem_lv_Top =
    < (GEM__RTOP * GEM__COSTILT - GEM__RTOP) * R + gem_lv_Seat.x,
      yGirdle_max - R,
      0
    >;
    #local gem_A = gem_lv_Top.y - yBase;
    #local gem_B = gem_lv_Top.x - gem_lv_Join.x;
    #local gem_Switch = gem_B * GEM__COSTILT - gem_A * GEM__SINTILT;
    #if (gem__Debug)
      #debug concat
      ( gem_This, " (, ", str (Girdle, 0, 4), ", ",
        str (yGirdle_max, 0, 4), ", , ", str (yBase, 0, 4), ", ",
        str (R, 0, 4), ", ", str (Theta, 0, 4),
        ")\n  lv_Seat = <", vstr (3, gem_lv_Seat, ", ", 0, 6),
        ">\n"
      )
      #debug concat
      ( "  lv_Top = <", vstr (3, gem_lv_Top, ", ", 0, 6),
        ">\n  lv_Join = <", vstr (3, gem_lv_Join, ", ", 0, 6),
        ">\n  Switch = ", str (gem_Switch, 0, 6), ":\n"
      )
    #end
    difference
    { #if (abs (gem_Switch) < 1e-4)
        #if (gem__Debug) #debug "  straight\n" #end
        #if (vlength (gem_lv_Top - gem_lv_Join) = 0)
          #if (gem__Debug) #debug "  degenerate\n" #end
          sphere { gem_lv_Top, R rotate Theta * y }
        #else
          union
          { cylinder { gem_lv_Top, gem_lv_Join, R }
            sphere { gem_lv_Top, R }
            rotate Theta * y
          }
        #end
      #else #if (0 < gem_Switch)
        #if (gem__Debug) #debug "  curved outward\n" #end
        #local gem_RLower =
          (gem_A * gem_A + gem_B * gem_B) / (2 * gem_Switch);
        #local gem_nxLower = gem_RLower * GEM__COSTILT - gem_B;
        #local gem_nyLower = -gem_RLower * GEM__SINTILT - gem_A;
        #local gem_aLower = atan2 (gem_nyLower, gem_nxLower);
        intersection
        { torus { gem_RLower, R rotate 90 * x }
          plane { <GEM__SINTILT, GEM__COSTILT, 0>, 0 }
          plane { <gem_nyLower, -gem_nxLower, 0>, 0 }
          // Force bounding (more reliably than bounded_by):
          box
          { < (gem_RLower - R) * cos (gem_aLower),
              (gem_RLower + R) * sin (gem_aLower),
              -R
            >,
            < (gem_RLower + R) * GEM__COSTILT,
              (R - gem_RLower) * GEM__SINTILT,
              R
            >
          }
          translate gem_lv_Top + gem_RLower * <-GEM__COSTILT, GEM__SINTILT, 0>
          rotate Theta * y
        }
      #else
        #if (gem__Debug) #debug "  curved inward\n" #end
        #local gem_RLower = (gem_A * gem_A + gem_B * gem_B) / (-2 * gem_Switch);
        #local gem_nxLower = gem_B + gem_RLower * GEM__COSTILT;
        #local gem_nyLower = gem_A - gem_RLower * GEM__SINTILT;
        #local gem_aLower = atan2 (gem_nyLower, gem_nxLower);
        intersection
        { torus { gem_RLower, R rotate 90 * x }
          plane { <GEM__SINTILT, GEM__COSTILT, 0>, 0 }
          plane { <gem_nyLower, -gem_nxLower, 0>, 0 }
          // Force bounding (more reliably than bounded_by):
          box
          { < -(gem_RLower + R) * (gem_aLower < 0? cos (gem_aLower): 1),
              ((gem_aLower < 0? R: -R) - gem_RLower) * sin (gem_aLower),
              -R
            >,
            < (R - gem_RLower) * min (cos (gem_aLower), GEM__COSTILT),
              (gem_RLower + R) * GEM__SINTILT,
              R
            >
          }
          translate gem_lv_Top + gem_RLower * <GEM__COSTILT, -GEM__SINTILT, 0>
          rotate Theta * y
        }
      #end
      #end
      object { Untextured_gem }
    }
  }
#end

//----------------------------------------------------------

#macro Gem_Rail (Untextured_gem, Y, R, Type, nPoints)
  #local gem_This = "Gem_Rail"
  #switch (Type)
    #case (GEM_SEGMENTED) #local gem_Telomere = 0; #break
    #case (GEM_CURVED) #local gem_Telomere = 1; #break
    #case (GEM_NONE)
      #error concat (gem_This, "(): called with GEM_NONE.")
      #break
    #else
      #error concat (gem_This, "(): unknown rail type ", str (Type, 0, -1), ".")
      #break
  #end
  #if (Y > max_extent (Untextured_gem).y | Y < min_extent (Untextured_gem).y)
    #error concat
    ( gem_This, "(): the Y value ", str (Y, 0, -1),
      " is above or below the gemstone."
    )
  #end
  // a radius that is always outside the gem:
  #local gem_Outside = max
  ( max_extent (Untextured_gem).x, -min_extent (Untextured_gem).x,
    max_extent (Untextured_gem).z, -min_extent (Untextured_gem).z
  ) * 2;
  #local gem_v_Norm = <0, 0, 0>;
  difference
  { sphere_sweep
    { #if (Type = GEM_CURVED) cubic_spline #else linear_spline #end
      nPoints + 1 + 2 * gem_Telomere
      #local gem_I = -gem_Telomere;
      #while (gem_I <= nPoints + gem_Telomere)
        #local gem_lv_Trace =
          vrotate (gem_Outside * z, (gem_I + 0.5) / nPoints * 360 * y);
        #local gem_lv_Contact = trace
        ( Untextured_gem, gem_lv_Trace + Y * y, -gem_lv_Trace, gem_v_Norm
        );
        #if (vlength (gem_v_Norm) = 0)
          #error concat
          ( gem_This, "(): a contact point with the gemstone could not be",
            " made.  Is it centered about the y-axis?"
          )
        #end
        gem_lv_Contact
          + vnormalize (gem_lv_Contact * <1, 0, 1>)
          * R / abs (vdot (vnormalize (gem_lv_Trace), gem_v_Norm)),
        R
        #local gem_I = gem_I + 1;
      #end
    }
    object { Untextured_gem }
  }
#end

//----------------------------------------------------------

#macro Gem_Scale (Gemstone, Scale, hPavilion, Girdle)
  #local gem_This = "Gem_Scale"
  #if (hPavilion >= 1)
    #warning concat
    ( gem_This, "(): hPavilion was set to ", str (hPavilion, 0, -1), ".  ",
      gem_This, "() expects a height; are you sure this isn't an angle?"
    )
  #end
  #if (hPavilion > 0)
    #if (Girdle < 0)
      #warning concat
      ( gem_This, "(): Girdle was set to ", str (Girdle, 0, -1), "."
      )
    #end
    #local gem_lv_Ctr = (hPavilion + Girdle / 2) * y;
  #else
    #local gem_lv_Ctr = (max_extent (Gemstone) + min_extent (Gemstone)) / 2;
  #end
  object
  { Gemstone
    translate -gem_lv_Ctr
    scale Scale
    translate gem_lv_Ctr
  }
#end

//----------------------------------------------------------

#macro Gem_Setting_poly
( Untextured_gem, hPavilion, Girdle, Space, Mode, yBase, v_Base_size, Prongs,
  dProng, Rail_type, yRail, Rail_res
)
  #local gem_This = "Gem_Setting_poly"
  #local gem_nProngs = dimension_size (Prongs, 1);
  #if (gem_nProngs < 3)
    #error concat
    ( gem_This, "(): Prongs has only ", str (gem_nProngs, 0, -1),
      " elements; it must have at least 3."
    )
  #end
  #local gem_RAvg = sqrt
  ( (max_extent (Untextured_gem).x - min_extent (Untextured_gem).x)
  * (max_extent (Untextured_gem).z - min_extent (Untextured_gem).z) / 4
  );
  #local gem_Cutout = Gem_Scale
  ( Untextured_gem, (gem_RAvg + Space) / gem_RAvg, hPavilion, Girdle
  )
  #local gem_v_Base_half = v_Base_size / <2, 2, 2>;
  #local gem_Base_test = cylinder { -y, y, 1 scale gem_v_Base_half }
  #local gem_R = dProng / 2;
  #local gem_Field = 1.36 * gem_R; // blob field
  #local gem_Strength = Gem__fn_Blob (gem_R, gem_Field);
  #local gem_lv_Joins = array [gem_nProngs]
  #local gem_lv_Corners = array [gem_nProngs]
  #local gem_Hole = prism
  { -gem_v_Base_half.y, gem_v_Base_half.y, gem_nProngs + 1
    #local gem_P = 0;
    #while (gem_P < gem_nProngs)
      #local gem_lv_Joins [gem_P] =
        trace (gem_Base_test, 0, vrotate (x, Prongs [gem_P] * y));
      #local gem_lv_Corners [gem_P] =
        gem_lv_Joins [gem_P] - vnormalize (gem_lv_Joins [gem_P]) * gem_R;
      <gem_lv_Corners [gem_P].x, gem_lv_Corners [gem_P].z>
      #local gem_P = gem_P + 1;
    #end
    <gem_lv_Corners[0].x, gem_lv_Corners[0].z>
    translate yBase * y
  }
  #if (Mode = GEM_HOLE)
    gem_Hole
  #else
    union
    { #local gem_P = 0;
      #while (gem_P < gem_nProngs)
        Gem_Prong
        ( gem_Cutout, Girdle, hPavilion + Girdle, gem_Base_test, yBase, gem_R,
          Prongs [gem_P]
        )
        #local gem_P = gem_P + 1;
      #end
     // base:
      blob
      { #local gem_P = 0;
        #while (gem_P < gem_nProngs)
          cylinder
          { gem_lv_Corners [gem_P],
            gem_lv_Corners [mod (gem_P + 1, gem_nProngs)],
            gem_Field, gem_Strength
            scale <1, gem_v_Base_half.y / gem_R, 1>
          }
          sphere
          { gem_lv_Corners [gem_P], gem_Field, -gem_Strength
            scale <1, gem_v_Base_half.y / gem_R, 1>
          }
          sphere { gem_lv_Joins [gem_P], gem_Field, gem_Strength }
          #local gem_P = gem_P + 1;
        #end
        translate yBase * y
      }
     // closed base:
      #if (Mode = GEM_CLOSED)
        difference
        { object { gem_Hole }
          object { gem_Cutout }
        }
      #end
     // gallery rail:
      #if (Rail_type != GEM_NONE)
        Gem_Rail (gem_Cutout, yRail, gem_R, Rail_type, Rail_res)
      #end
    }
  #end
#end

//----------------------------------------------------------

#macro Gem_Setting_poly_auto
( Untextured_gem, hPavilion, Girdle, Space, Mode, yBase, v_Base_size, nProngs,
  dProng, Rail_type, yRail, Rail_res
)
  #local gem_This = "Gem_Setting_poly_auto"
  #if (nProngs < 3)
    #error concat
    ( gem_This, "(): nProngs was set to ", str (nProngs, 0, -1),
      "; it must be at least 3."
    )
  #end
  Gem_Setting_poly
  ( Untextured_gem, hPavilion, Girdle, Space, Mode, yBase, v_Base_size,
    Gem__Prong_thetas (Untextured_gem, nProngs),
    dProng, Rail_type, yRail, Rail_res
  )
#end

//----------------------------------------------------------

#macro Gem_Setting_round
( Untextured_gem, hPavilion, Girdle, Space, Mode, yBase, v_Base_size, Prongs,
  dProng, Rail_type, yRail, Rail_res
)
  #local gem_RAvg = sqrt
  ( (max_extent (Untextured_gem).x - min_extent (Untextured_gem).x)
  * (max_extent (Untextured_gem).z - min_extent (Untextured_gem).z) / 4
  );
  #local gem_Cutout = Gem_Scale
  ( Untextured_gem, (gem_RAvg + Space) / gem_RAvg, hPavilion, Girdle
  )
  #local gem_v_Base_half = v_Base_size / <2, 2, 2>;
  #local gem_Base_test = cylinder { -y, y, 1 scale gem_v_Base_half }
  #local gem_R = dProng / 2;
  #local gem_Field = 1.36 * gem_R; // blob field
  #local gem_Strength = Gem__fn_Blob (gem_R, gem_Field);
  #local gem_RAxis = min (gem_v_Base_half.x, gem_v_Base_half.z);
  #local gem_v_Base_xz =
  ( gem_v_Base_half.z > gem_v_Base_half.x?
    <1, 1, gem_v_Base_half.z / gem_v_Base_half.x>:
    <gem_v_Base_half.x / gem_v_Base_half.z, 1, 1>
  );
  #local gem_v_Base_scale = gem_v_Base_xz * <1, gem_v_Base_half.y / gem_R, 1>;
  #local gem_Base_Dy = gem_v_Base_half.y - gem_R;
  #local gem_Hole = cylinder
  { -gem_R * y, gem_R * y, gem_RAxis - gem_R
    scale gem_v_Base_scale
    translate yBase * y
  }
  #if (Mode = GEM_HOLE)
    gem_Hole
  #else
    union
    { #local gem_P = 0;
      #while (gem_P < dimension_size (Prongs, 1))
        Gem_Prong
        ( gem_Cutout, Girdle, hPavilion + Girdle, gem_Base_test, yBase, gem_R,
          Prongs [gem_P]
        )
       // Join the prong to the base:
        #local gem_lv_Bottom =
          trace (gem_Base_test, 0, vrotate (x, Prongs [gem_P] * y));
        #local gem_lv_Angle =
          vrotate (x, Prongs [gem_P] * y) / gem_v_Base_scale;
       // The base is a toroid.  Since tori cannot be blobbed, create a
       // transformation to fit a blob component inside a torus:
        #local gem_x_Fit = transform
        { // Elongate until the maximum radius of curvature matches that of
          // the unscaled base torus:
          scale <1, 1, sqrt (gem_RAxis * gem_R) / gem_R>
          rotate degrees (atan2 (-gem_lv_Angle.z, gem_lv_Angle.x)) * y
        }
        blob
        { sphere { gem_lv_Bottom, gem_Field, gem_Strength } // base of prong
          #if (gem_Base_Dy <= 0) // small v_Base_size.y
            sphere // surrogate for the base toroid
            { (gem_RAxis - gem_R) * x, gem_Field, gem_Strength
              transform { gem_x_Fit }
              scale gem_v_Base_scale
            }
          #else // large v_Base_size.y
            cylinder // surrogate for the base toroid
            { -gem_Base_Dy * y, gem_Base_Dy * y, gem_Field, gem_Strength
              translate (gem_RAxis - gem_R) * x
              transform { gem_x_Fit }
              scale gem_v_Base_xz
            }
          #end
          translate yBase * y
        }
        #local gem_P = gem_P + 1;
      #end
     // base toroid:
      #if (gem_Base_Dy <= 0) // small v_Base_size.y: a torus or flattened torus
        torus
        { gem_RAxis - gem_R, gem_R
          scale gem_v_Base_scale
          translate yBase * y
        }
      #else // large v_Base_size.y: a ring with rounded rims
        #local gem_Y = gem_Base_Dy * y;
        union
        { torus { gem_RAxis - gem_R, gem_R translate gem_Y }
          torus { gem_RAxis - gem_R, gem_R translate -gem_Y }
          difference
          { cylinder { -gem_Y, gem_Y, gem_RAxis }
            cylinder { -1.1 * gem_Y, 1.1 * gem_Y, gem_RAxis - 2 * gem_R }
          }
          scale gem_v_Base_xz
          translate yBase * y
        }
      #end
     // closed base:
      #if (Mode = GEM_CLOSED)
        difference
        { object { gem_Hole }
          object { gem_Cutout }
        }
      #end
     // gallery rail:
      #if (Rail_type != GEM_NONE)
        Gem_Rail (gem_Cutout, yRail, gem_R, Rail_type, Rail_res)
      #end
    }
  #end
#end

//----------------------------------------------------------

#macro Gem_Setting_round_auto
( Untextured_gem, hPavilion, Girdle, Space, Mode, yBase, v_Base_size, nProngs,
  dProng, Rail_type, yRail, Rail_res
)
  #local gem_This = "Gem_Setting_round_auto"
  #if (nProngs < 2)
    #error concat
    ( gem_This, "(): nProngs was set to ", str (nProngs, 0, -1),
      "; it must be at least 2."
    )
  #end
  Gem_Setting_round
  ( Untextured_gem, hPavilion, Girdle, Space, Mode, yBase, v_Base_size,
    Gem__Prong_thetas (Untextured_gem, nProngs),
    dProng, Rail_type, yRail, Rail_res
  )
#end

//----------------------------------------------------------

#macro Gem_Shank (RInner, ROuter, Width, Side, rEdge, use_Sturm)
  #local gem_This = "Gem_Shank"
  Gem__range_pos (gem_This, "RInner", RInner)
  Gem__range_pos (gem_This, "ROuter", ROuter)
  Gem__range_pos (gem_This, "Width", Width)
  Gem__range_pos (gem_This, "Side", Width)
  Gem__range_pos (gem_This, "rEdge", rEdge)
  #if (ROuter < RInner)
    #error concat
    ( gem_This, "(): RInner = ", str (RInner, 0, -1), ", ROuter = ",
      str (ROuter, 0, -1), ".  ROuter must be larger than RInner."
    )
  #end
  #if (2 * rEdge > Side)
    #error concat
    ( gem_This, "(): Side = ", str (Side, 0, -1), ", rEdge = ",
      str (rEdge, 0, -1), ".  Side must be at least twice rEdge."
    )
  #end
  #if (!(ROuter - RInner >= Side)) // circumlocution avoids FP errors
    #error concat
    ( gem_This, "(): RInner = ", str (RInner, 0, -1), ", ROuter = ",
      str (ROuter, 0, -1), ", Side = ", str (rEdge, 0, -1),
      ".  The ring thickness must not be smaller than Side."
    )
  #end
  #if (Width < 2 * rEdge)
    #error concat
    ( gem_This, "(): Width = ", str (Width, 0, -1), ", rEdge = ",
      str (rEdge, 0, -1), ".  Width must be at least twice rEdge."
    )
  #end

  #local gem_Side_pts = (2 * rEdge < Side? 8: 0);
  #local gem_Outer_rim = RInner + Side - rEdge;
  #local gem_A = ROuter - gem_Outer_rim;
  #local gem_B = Width / 2 - rEdge;
  #local gem_ctInner = Gem__fn_Bezier_arc (radians (90)) * rEdge;

  // A laborious Bezier lathe is used instead of CSG because torus artifacts
  // show up with certain reasonable parameters.
  lathe
  { bezier_spline
    #if (gem_A * 2 >= Width)
     //----- oblate outer curvature -----
      #if (gem__Debug) #debug "Oblate outer curvature\n" #end
      16 + gem_Side_pts,
      #local gem_ctOuter = Gem__fn_Bezier_hump (gem_A / Width) * Width;
      <gem_Outer_rim, Width / 2>,
        <gem_Outer_rim + gem_ctOuter, Width / 2>,
        <gem_Outer_rim + gem_ctOuter, -Width / 2>,
        <gem_Outer_rim, -Width / 2>,
    #else #if (ROuter - RInner = Side)
     //----- flat outer "curvature"
      #if (gem__Debug) #debug "Flat outer curvature\n" #end
      24 + gem_Side_pts,
      <gem_Outer_rim, Width / 2>,
        <gem_Outer_rim + gem_ctInner, Width / 2>,
        <ROuter, gem_B + gem_ctInner>,
        <ROuter, gem_B>,
      <ROuter, gem_B>, <ROuter, gem_B>, <ROuter, -gem_B>, <ROuter, -gem_B>,
      <ROuter, -gem_B>,
        <ROuter, -gem_B - gem_ctInner>,
        <gem_Outer_rim + gem_ctInner, -Width / 2>,
        <gem_Outer_rim, -Width / 2>,
    #else
     //----- circular outer curvature -----
      #if (gem__Debug) #debug "Circular outer curvature\n" #end
      24 + gem_Side_pts,
      #local gem_rMinor =
        (rEdge * rEdge - gem_A * gem_A - gem_B * gem_B) / (2 * (rEdge - gem_A));
      #local gem_Aosc =
        gem_rMinor * (gem_rMinor - gem_A) / (gem_rMinor - rEdge);
      #local gem_Aosc_abs = ROuter - gem_rMinor + gem_Aosc;
      #local gem_Bosc = gem_B * gem_rMinor / (gem_rMinor - rEdge);
      #local gem_aOuter = atan2 (gem_Bosc, gem_Aosc);
     // distances to intermediate control points:
      #local gem_ctMid = Gem__fn_Bezier_arc (radians (90) - gem_aOuter) * rEdge;
      #local gem_ctOuter = Gem__fn_Bezier_arc (gem_aOuter * 2) * gem_rMinor;
     // vectors to intermediate control points:
      #local gem_v_Mid =
        vrotate (-gem_ctMid * x, (degrees (gem_aOuter) - 90) * z);
      #local gem_v_Outer = vrotate (-gem_ctOuter * y, degrees (gem_aOuter) * z);
      <gem_Outer_rim, Width / 2>,
        <gem_Outer_rim + gem_ctMid, Width / 2>,
        <gem_Aosc_abs + gem_v_Mid.x, gem_Bosc + gem_v_Mid.y>,
        <gem_Aosc_abs, gem_Bosc>,
      <gem_Aosc_abs, gem_Bosc>,
        <gem_Aosc_abs + gem_v_Outer.x, gem_Bosc + gem_v_Outer.y>,
        <gem_Aosc_abs + gem_v_Outer.x, -gem_Bosc - gem_v_Outer.y>,
        <gem_Aosc_abs, -gem_Bosc>,
      <gem_Aosc_abs, -gem_Bosc>,
        <gem_Aosc_abs + gem_v_Mid.x, -gem_Bosc - gem_v_Mid.y>,
        <gem_Outer_rim + gem_ctMid, -Width / 2>,
        <gem_Outer_rim, -Width / 2>,
    #end
    #end
   //----- inner surface -----
    #if (8 = gem_Side_pts)
      <gem_Outer_rim, -Width / 2>,
        <gem_Outer_rim, -Width / 2>,
        <RInner + rEdge, -Width / 2>,
        <RInner + rEdge, -Width / 2>,
      #if (gem__Debug) #debug "Modeling lower side\n" #end
    #end
    <RInner + rEdge, -Width / 2>,
      <RInner + rEdge - gem_ctInner, -Width / 2>,
      <RInner, -gem_B - gem_ctInner>,
      <RInner, -gem_B>,
    <RInner, -gem_B>, <RInner, -gem_B>, <RInner, gem_B>, <RInner, gem_B>,
    <RInner, gem_B>,
      <RInner, gem_B + gem_ctInner>,
      <RInner + rEdge - gem_ctInner, Width / 2>,
      <RInner + rEdge, Width / 2>
    #if (8 = gem_Side_pts)
      <RInner + rEdge, Width / 2>,
        <RInner + rEdge, Width / 2>,
        <gem_Outer_rim, Width / 2>,
        <gem_Outer_rim, Width / 2>
      #if (gem__Debug) #debug "Modeling upper side\n" #end
    #else #if (gem__Debug) #debug "Side is not modeled\n" #end
    #end
    #if (use_Sturm) sturm #end
  }
#end

//============================= PUBLIC FUNCTIONS ===============================

#declare Gem_fn_1Step_height = function (gem_P0_Flat, gem_P1)
{ tan (radians (gem_P1)) * (1 - gem_P0_Flat) / 2
}

#declare Gem_fn_2Step_height = function (gem_P0_Flat, gem_P1, gem_P2)
{ (tan (radians (gem_P1)) + tan (radians (gem_P2))) * (1 - gem_P0_Flat) / 4
}

#declare Gem_fn_3Step_height = function (gem_P0_Flat, gem_P1, gem_P2, gem_P3)
{ ( tan (radians (gem_P1)) + tan (radians (gem_P2)) + tan (radians (gem_P3))
  ) * (1 - gem_P0_Flat) / 6
}

#declare Gem_fn_4Step_height = function
( gem_P0_Flat, gem_P1, gem_P2, gem_P3, gem_P4
)
{ ( tan (radians (gem_P1)) + tan (radians (gem_P2)) + tan (radians (gem_P3))
  + tan (radians (gem_P4))
  ) * (1 - gem_P0_Flat) / 8
}

#declare Gem_fn_Crown_angle = function (gem_P0_Table, gem_P1_hCrown)
{ degrees (atan2 (2 * gem_P1_hCrown, 1 - gem_P0_Table))
}

#declare Gem_fn_Pavilion_angle = function (gem_P0_Culet, gem_P1_dPavilion)
{ degrees (atan2 (2 * gem_P1_dPavilion, 1 - gem_P0_Culet))
}

#declare Gem_fn_Lakshmi = function (P0_Table)
{ P0_Table * gem__cStar * (sqrt (2) - 1) / (1 - P0_Table * gem__cStar)
}

#version GemCuts_Inc_Temp;
#end
// end of gemcuts.inc
