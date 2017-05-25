/* androidrobot.pov
 *
 * Demo of Google's Android robot.
 *
 * Copyright 2011 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date          Comments                            Author
 * -----  ----          --------                            ------
 * 1.0    30-oct-2009   Original code written as droid.pov  Karl Ostmo
 * 2.0    23-jul-2011   Demo environment moved to separate  Richard Callwood III
 *                      scene file
 */
//+a +w160 +h120 +oandroidrobot_thumbnail

#version 3.7;

global_settings
{  assumed_gamma 1
   #if(1)
      radiosity
      {  recursion_limit 1
         error_bound 0.1
         pretrace_end 0.01
         count 200
      }
   #end
}

light_source {
   <2.8, 2, -2.83333>, rgb 1
   parallel point_at 0
   #if(1)
      area_light x, y, 17, 17
      circular orient adaptive 1 jitter
   #end
}

camera {
   perspective
   location <2, 1.2, -0.3>
   sky <0, 1, 0>
   direction <0, 0, 1>
   right <1.33333, 0, 0>
   up <0, 1, 0>
   look_at <0, 0.5, 0>
}

background { rgb 1 }

#include "androidrobot.inc"

object
{  AndroidRobot (no)
   pigment { ANDROIDROBOT_C_COLOR }
}

plane
{  y, ANDROIDROBOT_V_BASE.y
   pigment { rgb 1 }
   finish { reflection { 0 0.1 fresnel } }
   interior { ior 1.5 }
}
