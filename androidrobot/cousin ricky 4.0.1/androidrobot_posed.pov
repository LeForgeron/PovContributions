/* androidrobot_posed.pov version 4.0.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demo of Google's Android[TM] mascot, showing how it can be posed.
 *
 * Android is a trademark of Google Inc.  The Android robot is reproduced or
 * modified from work created and shared by Google and used according to terms
 * described in the Creative Commons 3.0 Attribution License.
 * See https://developer.android.com/distribute/marketing-tools/ and
 * https://creativecommons.org/licenses/by/3.0/ for more information.
 *
 * Copyright 2011 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments                                      Author
 * -----  ----         --------                                      ------
 * 2.0    2011-Jul-23  Created.                                      R. Callwood
 * 2.1    2012-Jun-26  The #version is changed to 3.5.               R. Callwood
 * 2.2    2014-Oct-05  The robot is more charismatic.                R. Callwood
 *                     Radiosity is added.
 *                     The metallic finish is tweaked.
 *                     The Google license statement is copied from
 *                       the include file.
 * 3.0    2015-Apr-25  Lenses are placed in the eyes.                R. Callwood
 *                     Some kick is added to the robot's pose.
 * 4.0    2018-Sep-23  The environmental lighting is overhauled.     R. Callwood
 *                     The metal finish is tweaked.
 *                     The code is reorganized.
 * 4.0.1  2019-Mar-22  No change.                                    R. Callwood
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
      pretrace_end 0.01
      recursion_limit 2
    }
  #end
  photons { spacing 0.002 autostop 0 }
}

#include "consts.inc" // for glass property
#include "transforms.inc"
#include "androidrobot.inc"

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

//================================= LIGHTING ===================================

#if (Rad) // Turn off ambient for POV-Ray < 3.7.
  #declare C_AMBIENCE = rgb 0;
  #declare C_GROUND_AMBIENCE = rgb 0;
#else // Simulate radiosity.
  #declare C_AMBIENCE = rgb <0.24, 0.28, 0.36>;
  #declare C_GROUND_AMBIENCE = rgb <0.07, 0.12, 0.25>;
#end
#declare DIFFUSE = 0.8;
#default { finish { ambient C_AMBIENCE diffuse DIFFUSE } }

#declare V_SUN = vrotate (-z, <45, 25, 0>);
light_source
{ V_SUN * 1000, rgb <1.81, 1.73, 1.67>
  parallel point_at 0
  #if(1)
    area_light x * 200, y * 200, 17, 17
    circular orient adaptive 1 jitter
  #end
}

//=============================== ENVIRONMENT ==================================

#declare C_HALO = rgb <0.51, 0.81, 1.68>;
sky_sphere
{ pigment
  { function { pow (1 - y, 3) }
    color_map { [0 rgb <0.05, 0.10, 0.25>] [1 rgb <0.4, 0.6, 0.8>] }
  }
  pigment
  { function { select (z, pow (max (1 - sqrt (x*x + y*y) * 1.3, 0), 3), 0) }
    color_map { [0 C_HALO transmit 1] [1 C_HALO] }
    Reorient_Trans(-z, V_SUN)
  }
}

plane
{ y, 0
  pigment { checker rgb 0.125 rgb 0.625 }
  finish { ambient C_GROUND_AMBIENCE }
}

//================================ THE ROBOT ===================================

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
    { reflection { 0.9 metallic }
      diffuse DIFFUSE * 0.05
      ambient C_AMBIENCE * 0.05
      specular 1125 metallic
      roughness 0.0001
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
