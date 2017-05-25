/* androidrobot.pov version 2.2
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demo of Google's Android[TM] mascot.
 *
 * Android is a trademark of Google Inc.  The Android robot is reproduced or
 * modified from work created and shared by Google and used according to terms
 * described in the Creative Commons 3.0 Attribution License.
 * See http://developer.android.com/distribute/tools/promote/brand.html and
 * http://creativecommons.org/licenses/by/3.0/ for more information.
 *
 * See also http://commons.wikimedia.org/wiki/File:Android_Robot_POV-Ray.png
 *
 * Copyright 2011 - 2014 Richard Callwood III.  Some rights reserved.
 * Portions copyright 2009 Karl Ostmo.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments                                       Author
 * ----  ----         --------                                       ------
 * 1.0   30-Oct-2009  Original code is written as droid.pov.         K. Ostmo
 * 2.0   23-Jul-2011  Demo environment moved to a separate scene     R. Callwood
 *                      file.
 * 2.1   26-Jun-2012  #version is changed to 3.5.                    R. Callwood
 * 2.1a  28-Jun-2012  No change.
 * 2.2   05-Oct-2014  Google license statement is copied from the    R. Callwood
 *                      include file, just in case.
 */
#version 3.5;

global_settings
{ assumed_gamma 1
  #if(1)
    radiosity
    { recursion_limit 1
      error_bound 0.1
      pretrace_end 0.01
      count 200
    }
  #end
}
#default { finish { ambient 0 } } //for pre-3.7 radiosity

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
{ AndroidRobot (no)
  pigment { ANDROIDROBOT_C_COLOR }
}

plane
{ y, ANDROIDROBOT_V_BASE.y
  pigment { rgb 1 }
  finish { reflection { 0 0.15 fresnel } }
  interior { ior 1.5 }
}
