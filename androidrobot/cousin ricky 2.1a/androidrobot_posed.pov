/* androidrobot_posed.pov version 2.1
 * Persistence of Vision Raytracer scene file
 * POV-Ray Object Collection demo
 *
 * Demo of posing of Google's Android robot.
 *
 * Copyright 2011 - 2012 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date          Comments                            Author
 * -----  ----          --------                            ------
 * 2.0    23-jul-2011   Created.                            Richard Callwood III
 * 2.1    26-jun-2012   #version reverted to 3.5.           Richard Callwood III
 */
/* 3.5, 3.6 //+w280 +h280
 * 3.7      //+w280 +h280 +a declare=BLUR_SAMPLES=37
 */
#version 3.5;

#ifndef (BLUR_SAMPLES)
  #declare BLUR_SAMPLES = 100; //POV 3.7 can use smaller value with +A
#end

global_settings { assumed_gamma 1 max_trace_level 10 }

//Simulate sky radiosity:
#declare C_AMBIENCE = <0.20, 0.24, 0.32>;
#default { finish { ambient C_AMBIENCE } }

light_source
{ <-1, 3, -2> * 1000, rgb <1.1, 1.0, 0.83>
  parallel point_at 0
  #if(1)
    area_light x * 1000, y * 1000, 17, 17
    circular orient adaptive 1 jitter
  #end
}

#declare V_AIM = <0, 0.85, 0>;
#declare V_CAM = <1.5, 0.75, -2.25>;
#declare HVIEW = 2.5;
#declare Field = HVIEW / vlength (V_AIM - V_CAM);
camera
{ location V_CAM
  look_at V_AIM
  up Field * y
  right Field * image_width/image_height * x
  #if(1)
    aperture 0.02
    focal_point V_AIM
    blur_samples BLUR_SAMPLES
  #end
}

sky_sphere
{ pigment
  { gradient y color_map
    { [0 rgb <0.7, 0.8, 0.9>]
      [1 rgb <0.2, 0.3, 0.6>]
    }
  }
}

plane
{ y, 0
  pigment { checker rgb 0.5 rgb 1 }
}

#include "androidrobot.inc"

object
{ AndroidRobot_posed
  ( no,
    transform { rotate <0, -30, 0> },
    transform { rotate <-135, 0, -30> },
    transform { rotate <30, 0, 0> },
    transform {},
    transform {}
  )
  rotate 90 * y
  translate -ANDROIDROBOT_V_BASE
  pigment { ANDROIDROBOT_C_COLOR }
  finish
  { reflection { 0.5 metallic }
    diffuse 0.3
    ambient C_AMBIENCE * 0.5
    specular 1.4
    metallic 0.95
    roughness 0.15
    brilliance 6.75
  }
}
