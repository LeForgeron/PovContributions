/* androidrobot.inc version 2.1a
 * Persistence of Vision Raytracer include file
 * POV-Ray Object Collection
 *
 * Google's Android Robot.
 * Based on work created and shared by the Android Open Source Project and used
 * according to terms described in the Creative Commons 2.5 Attribution License.
 * See http://www.android.com/branding.html and
 * http://creativecommons.org/licenses/by/2.5/ for more information.
 *
 * See also http://commons.wikimedia.org/wiki/File:Android_Robot_POV-Ray.png
 *
 * Copyright 2011 - 2012 Richard Callwood III.  Some rights reserved.
 * Portions copyright 2009 Karl Ostmo.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments                              Author
 * ----  ----         --------                              ------
 * 1.0   30-oct-2009  Original code written as droid.pov.   Karl Ostmo
 *
 * 2.0   23-jul-2011  Code is separated into include and    Richard Callwood III
 *                      demo files.
 *                    Code is made fully namespace compliant.
 *                    Pigment is removed from robot and the
 *                      official color declared separately.
 *                    Robot can be posed.
 *
 * 2.1   26-jun-2012  Non-gamma-adjusted official color     Richard Callwood III
 *                      is added.
 *
 * 2.1a  28-jun-2012  Correction is made to Google license  Richard Callwood III
 *                    statement.
 *
 * Disclaimer:  I know nothing about Android.  I just thought the robot looked
 * cute.
 */

#ifndef (ANDROIDROBOT_INC) #declare ANDROIDROBOT_INC = version;
#debug "#include \"androidrobot.inc\" //version 2.1a\n"

//Take advantage of 3.7 feature if and only if available:
#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("  #version ", str(version,0,1), ";\n")

#declare ANDROIDROBOT_V_BASE = <0, -0.55, 0>;
#declare ANDROIDROBOT_C_RAWCOLOR = <164, 198, 57> / 255; // #A4C639
#if (version < 3.7)
  #declare ANDROIDROBOT_C_COLOR = rgb
    <pow (ANDROIDROBOT_C_RAWCOLOR.red, 2.2),
     pow (ANDROIDROBOT_C_RAWCOLOR.green, 2.2),
     pow (ANDROIDROBOT_C_RAWCOLOR.blue, 2.2)>;
#else
  #declare ANDROIDROBOT_C_COLOR = srgb ANDROIDROBOT_C_RAWCOLOR;
#end
#declare ANDROIDROBOT_C_RAWCOLOR = rgb ANDROIDROBOT_C_RAWCOLOR;

#macro AndroidRobot_posed
  (Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg)

  #local ANDROIDROBOT_ANTENNAE_ANGLE = 30;
  #local ANDROIDROBOT_ANTENNAE_LENGTH = 0.2;
  #local ANDROIDROBOT_EYE_HEIGHT = 0.8;

  #local AndroidRobot_Antenna = cylinder
  { <0, ANDROIDROBOT_ANTENNAE_LENGTH, 0>, <0, 0, 0>, 0.02
  }

  #local AndroidRobot_Arm = #if (Use_merge) merge #else union #end
  { sphere { <0, 0.5, 0>, 0.1 }
    cylinder { <0, 0.5, 0>, <0, 0.1, 0>, 0.1 }
    sphere { <0, 0.1, 0>, 0.1 }
  }

  #local AndroidRobot_Leg = #if (Use_merge) merge #else union #end
  { cylinder
    { <0, 0.5, 0>, <0, -0.2, 0>, 0.1
      translate <0, -0.25, 0>
    }
    sphere
    { <0, -0.2, 0>, 0.1
      translate <0, -0.25, 0>
    }
  }

  #local AndroidRobot_EyeSocket = cylinder
  { <0, 0.5, 0>, <0, 0, 0>, 0.05
    rotate z*(-90)
    translate <0, ANDROIDROBOT_EYE_HEIGHT, 0>
  }

  #if (Use_merge) merge #else union #end
  {
   //Torso
    cylinder { <0, 0.6, 0>, <0, -0.1, 0>, 0.5 }
    cylinder { <0, 0.1, 0>, <0, -0.2, 0>, 0.4 }
    torus { 0.4, 0.1 translate -0.1 * y }

   //Head
    #if (Use_merge) merge #else union #end
    { difference
      { sphere { <0, 0.6, 0>, 0.5 }
        plane { y, 0.65 }
        object { AndroidRobot_EyeSocket translate z*(-.25) }
        object { AndroidRobot_EyeSocket translate z*(.25) }
      }
      object
      { AndroidRobot_Antenna
        rotate x*(-ANDROIDROBOT_ANTENNAE_ANGLE)
        translate <0, 1, -0.25>
      }
      object
      { AndroidRobot_Antenna
        rotate x*(ANDROIDROBOT_ANTENNAE_ANGLE)
        translate <0, 1, 0.25>
      }
      translate -0.625 * y //move to origin
      transform { x_Head }
      translate 0.625 * y //move back from origin
    }

    object
    { AndroidRobot_Arm
      translate -0.5 * y //move to origin
      transform { x_Right_arm }
      translate 0.5 * y //move back from origin
      translate z*(-0.6)
    }

    object
    { AndroidRobot_Arm
      translate -0.5 * y //move to origin
      transform { x_Left_arm }
      translate 0.5 * y //move back from origin
      translate z*(0.6)
    }

    object
    { AndroidRobot_Leg
      translate 0.1 * y //move to origin
      transform { x_Left_leg }
      translate -0.1 * y //move back from origin
      translate z*(.25)
    }

    object
    { AndroidRobot_Leg
      translate 0.1 * y //move to origin
      transform { x_Right_leg }
      translate -0.1 * y //move back from origin
      translate z*(-.25)
    }

  }
#end

#macro AndroidRobot (Use_merge)
  AndroidRobot_posed (Use_merge, transform{}, transform{}, transform{},
    transform{}, transform{})
#end

#version ANDROIDROBOT_INC;
#end
