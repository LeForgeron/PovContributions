/* androidrobot_posed.pov version 3.0a
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demo of posing of Google's Android[TM] mascot.
 *
 * Android is a trademark of Google Inc.  The Android robot is reproduced or
 * modified from work created and shared by Google and used according to terms
 * described in the Creative Commons 3.0 Attribution License.
 * See http://developer.android.com/distribute/tools/promote/brand.html and
 * http://creativecommons.org/licenses/by/3.0/ for more information.
 *
 * Copyright 2011 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments                                       Author
 * ----  ----         --------                                       ------
 * 2.0   2011-Jul-23  Created.                                       R. Callwood
 * 2.1   2012-Jun-26  #version is changed to 3.5.                    R. Callwood
 * 2.1a  2012-Jun-28  No change.
 * 2.2   2014-Oct-05  Robot is more charismatic.                     R. Callwood
 * 2.2   2014-Oct-05  Radiosity is added.                            R. Callwood
 * 2.2   2014-Oct-05  Metallic finish is tweaked.                    R. Callwood
 * 2.2   2014-Oct-05  Google license statement is copied from the    R. Callwood
 *                      include file, just in case.
 * 3.0   2015-Apr-25  Lenses are placed in the eyes.                 R. Callwood
 * 3.0   2015-Apr-25  Some kick is added to the robot's pose.        R. Callwood
 * 3.0a  2015-Apr-27  User manual update.                            R. Callwood
 */
/* 3.5, 3.6 // +w280 +h280
 * 3.7      // +w280 +h280 +a declare=BLUR_SAMPLES=37
 */
#version 3.5;

#ifndef (BLUR_SAMPLES)
  #declare BLUR_SAMPLES = 100; // POV 3.7 can use smaller value with +A
#end
#ifndef (Rad) #declare Rad = yes; #end // Use radiosity?

global_settings
{ assumed_gamma 1
 // With the eye lenses introduced in the 3.0 version of this demo, the trace
 // maxes out at 160+, but there's no visual improvement at that level.
  max_trace_level 10
  #if (Rad)
    radiosity
    { count 100
      error_bound 0.5
      pretrace_end 0.005
      recursion_limit 2
    }
  #end
  photons { spacing 0.002 autostop 0 }
}


#declare C_AMBIENCE =
  #if (Rad)
    rgb 0; // Turn off ambient for POV-Ray < 3.7.
  #else
    rgb <0.15, 0.18, 0.30>; // Simulate sky radiosity.
  #end
#declare DIFFUSE = 0.8;
#default { finish { ambient C_AMBIENCE diffuse DIFFUSE } }

light_source
{ <-1, 3, -2> * 1000, rgb <1.06, 1.00, 0.82>
  parallel point_at 0
  #if(1)
    area_light x * 1000, y * 1000, 17, 17
    circular orient adaptive 1 jitter
  #end
}

#declare V_AIM = <0, 0.85, 0>;
#declare V_CAM = <1.7, 0.75, -2.1>;
#declare HVIEW = 2.5;
#declare Field = HVIEW / vlength (V_AIM - V_CAM);
camera
{ location V_CAM
  look_at V_AIM
  up Field * y
  right Field * x
  #if (BLUR_SAMPLES)
    aperture 0.02
    focal_point V_AIM
    blur_samples BLUR_SAMPLES
  #end
}

sky_sphere
{ pigment
  { gradient y color_map
    { [0 rgb <0.44, 0.54, 0.74>]
      [1 rgb <0.04, 0.06, 0.22>]
    }
  }
}

plane
{ y, 0
  pigment { checker rgb 0.125 rgb 0.625 }
}

#include "consts.inc" // for glass property
#include "androidrobot.inc"

#declare UserDefinedEye = sphere
{ 0, AndroidRobot_Eye_radius()
  scale <0.5, 1, 1>
  pigment { rgbf 1 }
  finish
  { reflection { 0 1 fresnel } conserve_energy
    specular 125 roughness 0.001
  }
  interior { ior Crown_Glass_Ior }
 // While the stored photons aren't visible in this scene,
 // enabling photons adds to the contrast in the eyes.
  photons { target collect off reflection on refraction on }
  translate AndroidRobot_Eye_v() - <0.05, 0, 0>
}

#declare MyHeadRotation = transform { rotate <0, -25, 0> }

union
{ object
  { AndroidRobot_Posed
    ( no,
      MyHeadRotation,
      transform { rotate <-135, 30, 0> },
      transform { rotate <135, -30, 0> },
      transform {},
      transform { translate -0.1 * y rotate <0, 0, 60> }
    )
    pigment { ANDROIDROBOT_C_COLOR }
    finish
    { reflection { 0.5 metallic }
      diffuse DIFFUSE * 0.5
      ambient C_AMBIENCE * 0.5
      specular 1.788 metallic
      roughness 0.05
      brilliance 1.857
    }
  }
  union // facial features
  { object { UserDefinedEye }
    object { UserDefinedEye scale <1, 1, -1> }
    // transform { MyHeadRotation } // Wrong!
    AndroidRobot_Head_x (MyHeadRotation) // Correct
  }
  rotate 90 * y
  translate -ANDROIDROBOT_V_BASE
}
// end of androidrobot_posed.pov
