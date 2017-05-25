/* spheresweep_lanes.pov version 1.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A demonstration of the SphereSweep module's approximation macros and
 * transparency.
 *
 * Copyright 2013 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   2013-Jun-12  Created.
 * 1.0   2013-Jul-22  Completed and uploaded.
 * 1.1   2015-Aug-28  A color is tweaked.
 */
// +W300 +H450 +A +AM2
#version 3.5;

#ifndef (Soft) #declare Soft = yes; #end //area light switch
#ifndef (Rad) #declare Rad = yes; #end //radiosity switch

#include "shapes.inc"
#include "spheresweep.inc"

global_settings
{ assumed_gamma 1
  #if (Rad)
    radiosity
    { count 1000
      error_bound 0.5
      media on
      pretrace_end 0.01
      recursion_limit 2
    }
  #end
  max_trace_level 10
}
#default { finish { ambient (Rad? 0: 0.007) diffuse 0.75 } }

camera
{ location -95 * z
  look_at 0
  right 2/3 * x
  angle 30
}

#declare V_AIM = <0, -6, -20>;
#declare V_LIGHT = V_AIM + <-1, 1, -1> * 120;
#declare RLIGHT = 6;
light_source
{ V_LIGHT, rgb (1 + pow (vlength (V_LIGHT - V_AIM) / RLIGHT, 2)) / 2
  fade_power 2
  fade_distance RLIGHT
  spotlight point_at V_AIM radius 5 falloff 10
  #if (Soft)
    area_light RLIGHT * 2 * x, RLIGHT * 2 * y, 9, 9 adaptive 0
    circular orient jitter
  #end
}

plane { -z, 0 pigment { rgb 0.4 } }

//------------------------------- BOWLING PIN ----------------------------------

//----------------- dimensions -------------------
#declare RPIN = 2.375;
#declare HPIN = 15;
#declare RTOP = 1.3;

#declare PinPts = array[6]
{ -HPIN/3 * y, 0 * y, HPIN/3 * y, HPIN * 2/3 * y, (HPIN - RTOP) * y,
  HPIN * 4/3 * y
}
#declare PinRs = array[6] { 0, RTOP, RPIN, 0.95, RTOP, RTOP }

//------------------ pigments --------------------
#declare FREQ = 6;
#declare C_IVORY = rgb <1, 0.97, 0.88>;
#declare p_Check1 = pigment
{ radial color_map { [0.5 rgb <0.85, 0, 0.085>] [0.5 rgb <1, 0.8, 0>] }
  frequency FREQ
  rotate 90 / FREQ * y
}
#declare p_Check2 = pigment { p_Check1 rotate 180 / FREQ * y }
#declare p_Logo = pigment
{ object
  { Center_Object (text { ttf "povlogo.ttf" "P" 1, 0 }, x+y)
    scale <2.5, 2.5 / HPIN, -1.1 * RPIN>
    translate 0.48 * y
    C_IVORY rgb <0, 0.15, 0.55>
  }
}

//------------------------------------------------
#declare Pin = intersection
{ SphereSweep_Blob_margin (SSWP_CUBIC_SPLINE, PinPts, PinRs, 20, 0.1, no)
  plane { -y, 0 }
  pigment
  { gradient y pigment_map
    { [0.61 p_Logo] [0.61 p_Check1]
      [0.66 p_Check1] [0.66 p_Check2]
      [0.71 p_Check2] [0.71 p_Check1]
      [0.76 p_Check1] [0.76 C_IVORY]
    }
    scale <1, HPIN, 1>
  }
  finish
  { reflection { 0.25 fresnel } conserve_energy
    specular 0.7844 roughness 0.002
  }
  interior { ior 1.49 }
}

//-------------------------------- NEON SIGN -----------------------------------

#declare R = 0.5;
#declare NeonRs = array[1] { R }
#declare InnerMaskRs = array[1] { R * 1.0001 }
#declare OuterMaskRs = array[1] { R * 1.01 }
#declare RES = 10;
#declare LPts = array[3]
{ <-3, 9, 0>, <-3, 0, 0>, <3, 0, 0>
}
#declare APts = array[9]
{ <-3.5, -4, -R>, <-3.5, -0.25, -R>, <0, 9.25, -R>, <2.75, 4, -R>,
  <3.25, -0.25, -R>, <-1.5, 1, R>, <-2.75, 2.5, R>, <2.5, 3.25, R>, <5, 3, R>
}
#declare AMaskPts = SSwp_Subarray (APts, 3, 7)
#declare NPts = array[4]
{ <-3, -0.25, 0>, <-2.5, 9.25, 0>, <2.5, -0.25, 0>, <3, 9.25, 0>
}
#declare EPts = array[10]
{ <6, 6, 0>, <3, 9, 0>, <-3, 9, 0>, <-3, 4.75, R>, <1, 4.35, R>,
  <1, 4.65, -R>, <-3, 4.25, -R>, <-3, 0, 0>, <3, 0, 0>, <6, 3, 0>
}
#declare EMaskPts = SSwp_Subarray (EPts, 2, 6)
#declare SPts = array[10]
{ <3.25, 7.5, 0>, <1.5, 9.15, 0>, <-1.5, 9.25, 0>, <-3.25, 7.5, 0>, <-2, 5, 0>,
  <2, 4, 0>, <3.25, 1.5, 0>, <1.5, -0.25, 0>, <-1.5, -0.15, 0>, <-3.25, 1.5, 0>
}

//--------------------------------------

#declare m_Letter = material //completely clear material
{ texture
  { pigment { rgbf 1 }
    finish { specular 6.26 roughness 0.001 }
  }
  interior { media { emission rgb <1, 0.05, 0> * 10 } }
}
#declare m_Shadow = material //casts a glassy shadow
{ texture { pigment { rgb 0.8 filter 1 } }
}
#declare p_Mask = pigment { rgb 0.05 }

//--------------------------------------

/* Notes:  Artifacts appear in version 3.5 with SphereSweep_Approx().
 * They are worst in letters 'E' and 'S', so SphereSweep_Merge() is used
 * with these letters, at the expense of render time.  The artifacts do
 * not show in versions 3.6.1 and 3.7.
 */
#declare Letters = array[5]
#declare Letters[0] = object
{ SphereSweep_Approx (SSWP_NATURAL_SPLINE, LPts, NeonRs, RES, 0)
  translate 0.5 * x
}
#declare Letters[1] = union
{ SphereSweep_Approx (SSWP_CUBIC_SPLINE, APts, NeonRs, RES, 0)
  difference
  { SphereSweep_Approx (SSWP_CUBIC_SPLINE, AMaskPts, OuterMaskRs, RES, 0)
    SphereSweep_Approx (SSWP_CUBIC_SPLINE, APts, InnerMaskRs, RES, 0)
    pigment { p_Mask }
  }
}
#declare Letters[2] =
  SphereSweep_Approx (SSWP_NATURAL_SPLINE, NPts, NeonRs, RES, 0)
#declare Letters[3] = union
{ SphereSweep_Merge (SSWP_CUBIC_SPLINE, EPts, NeonRs, RES)
  intersection
  { SphereSweep_Approx (SSWP_CUBIC_SPLINE, EMaskPts, OuterMaskRs, RES, 0)
    object
    { SphereSweep_Approx (SSWP_CUBIC_SPLINE, EPts, InnerMaskRs, RES, 0)
      inverse
    }
    plane { -z, 0 }
    plane { <-1, 1, 0>, 5.1 }
    pigment { p_Mask }
  }
  translate 0.5 * x
}
#declare Letters[4] =
  SphereSweep_Merge (SSWP_NATURAL_SPLINE, SPts, NeonRs, RES)

//------------------------------------------------------------------------------

#declare v_Jitter = <-1, 1, -1> * 0.01;
union
{ #local I = 0;
  #while (I < 5)
    union
    { object
      { Letters[I] hollow
        material { m_Letter }
      }
     // A separate ghost object is used to cast shadows, because using an
     // incompletely transparent texture on the main object resulted in a
     // lot of artifacts.
     // (Yes, more realistic models are very possible, but I think they are
     // overkill for an Object Collection demo.)
      object
      { Letters[I]
        material { m_Shadow }
        translate v_Jitter
        no_image no_reflection
      }
      translate 40 * y
      rotate (2 - I) * 12 * z
    }
    #local I = I + 1;
  #end
  translate <0, -20, -2>
}

union
{ object { Pin rotate <10, -10, -10> translate <3, 0, 1> }
  object { Pin rotate <10, 10, 10> translate <-3, 0, 1> }
  object { Pin rotate <-10, 0, 0> translate <0, 0, -2> }
  translate -HPIN/2 * y
  scale 2.25
  translate V_AIM
}
// end of spheresweep_lanes.pov
