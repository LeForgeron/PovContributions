/* androidrobot_posed.pov version 2.2
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
 * Copyright 2011 - 2014 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments                                       Author
 * ----  ----         --------                                       ------
 * 2.0   23-jul-2011  Created.                                       R. Callwood
 * 2.1   26-jun-2012  #version is changed to 3.5.                    R. Callwood
 * 2.1a  28-Jun-2012  No change.
 * 2.2   05-Oct-2014  Robot is more charismatic.                     R. Callwood
 * 2.2   05-Oct-2014  Radiosity is added.                            R. Callwood
 * 2.2   05-Oct-2014  Metallic finish is tweaked.                    R. Callwood
 * 2.2   05-Oct-2014  Google license statement is copied from the    R. Callwood
 *                      include file, just in case.
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
{ assumed_gamma 1 max_trace_level 10
  #if (Rad)
    radiosity
    { count 100
      error_bound 0.5
      pretrace_end 0.005
      recursion_limit 2
    }
  #end
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
  right Field * image_width/image_height * x
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

#include "androidrobot.inc"

object
{ AndroidRobot_posed
  ( no,
    transform { rotate <0, -35, 0> },
    transform { rotate <-135, 30, 0> },
    transform { rotate <135, -30, 0> },
    transform {},
    transform {}
  )
  rotate 90 * y
  translate -ANDROIDROBOT_V_BASE
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
