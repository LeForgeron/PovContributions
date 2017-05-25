/* androidrobot.inc version 3.0a
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Google's Android[TM] mascot.
 *
 * Android is a trademark of Google Inc.  The Android robot is reproduced or
 * modified from work created and shared by Google and used according to terms
 * described in the Creative Commons 3.0 Attribution License.
 * See http://developer.android.com/distribute/tools/promote/brand.html and
 * http://creativecommons.org/licenses/by/3.0/ for more information.
 *
 * See also http://commons.wikimedia.org/wiki/File:Android_Robot_POV-Ray.png
 *
 * Copyright 2011 - 2015 Richard Callwood III.  Some rights reserved.
 * Portions copyright 2009 Karl Ostmo.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments                                       Author
 * ----  ----         --------                                       ------
 * 1.0   2009-Oct-30  The original code is written as droid.pov.     K. Ostmo
 *
 * 2.0   2011-Jul-23  The code is separated into include and demo    R. Callwood
 *                      files.
 *                    The code is made fully namespace compliant.
 *                    The pigment is removed from robot and the
 *                      official color declared separately.
 *                    The robot can be posed.
 *
 * 2.1   2012-Jun-26  Non-gamma-adjusted official color is added.    R. Callwood
 *
 * 2.1a  2012-Jun-28  A correction is made to Google license         R. Callwood
 *                    statement.
 *
 * 2.2   2014-Oct-05  The arms are moved away from the body, as      R. Callwood
 *                      they appear in the 2D logo.
 *                    A backwards compatibility switch is added.
 *                    The Google license statement is upgraded.
 *
 * 3.0   2015-Apr-25  The robot is remodeled based on an SVG source. R. Callwood
 *                    Tools are added to facilitate user modeling
 *                      of eyes.
 *
 * 3.0a  2015-Apr-27  User manual update.                            R. Callwood
 *
 * Author's note:  OK, so the remodeled robot isn't as cute as Ostmo's version,
 * due to the eyes being higher set on the face.  Still, the remodeling was a
 * worthy effort, and the old, cute versions are still available by setting the
 * variable AndroidRobot_Version. --RC
 */
#ifndef (AndroidRobot_Inc_Temp) #declare AndroidRobot_Inc_Temp = version;
#debug "#include \"androidrobot.inc\" //version 3.0a\n"

#ifndef (AndroidRobot_Version) #declare AndroidRobot_Version = 3.0; #end

//Take advantage of POV-Ray 3.7 feature if and only if available:
#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("  #version ", str(version,0,1), ";\n")

//============================= PUBLIC CONSTANTS ===============================

#declare ANDROIDROBOT_C_RAWCOLOR = <164, 198, 57> / 255; // #A4C639
#if (version < 3.7)
  #declare ANDROIDROBOT_C_COLOR = rgb
  < pow (ANDROIDROBOT_C_RAWCOLOR.red, 2.2),
    pow (ANDROIDROBOT_C_RAWCOLOR.green, 2.2),
    pow (ANDROIDROBOT_C_RAWCOLOR.blue, 2.2)
  >;
#else
  #declare ANDROIDROBOT_C_COLOR = srgb ANDROIDROBOT_C_RAWCOLOR;
#end
#declare ANDROIDROBOT_C_RAWCOLOR = rgb ANDROIDROBOT_C_RAWCOLOR;
#declare ANDROIDROBOT_HEIGHT = 1.65;
#declare ANDROIDROBOT_V_BASE = <0, -0.55, 0>;

//======================== INTERNAL (PRIVATE) MACROS ===========================

//---------------------- Ostmo model -----------------------

#declare ANDROIDROBOT__EYE_HEIGHT = 0.8;

#macro AndroidRobot__V2
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  #local ANDROIDROBOT_ANTENNAE_ANGLE = 30;
  #local ANDROIDROBOT_ANTENNAE_LENGTH = 0.2;
  #local ANDROIDROBOT_XARM = (AndroidRobot_Version < 2.2? 0.6: 0.65);

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
    translate <0, ANDROIDROBOT__EYE_HEIGHT, 0>
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
      { AndroidRobot_Head (0)
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
      AndroidRobot_Head_x (x_Head)
    }

    object
    { AndroidRobot_Arm
      translate -0.5 * y //move to origin
      transform { x_Right_arm }
      translate 0.5 * y //move back from origin
      translate z*(-ANDROIDROBOT_XARM)
    }

    object
    { AndroidRobot_Arm
      translate -0.5 * y //move to origin
      transform { x_Left_arm }
      translate 0.5 * y //move back from origin
      translate z*(ANDROIDROBOT_XARM)
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

//-------------------- Callwood model ----------------------

/* The messy values in this section were derived from the file
 * http://commons.wikimedia.org/wiki/File:Android_robot.svg,
 * and transformed such that the new version of the robot has
 * the same size and position as the Ostmo model.
 *
 * The Web page from which the Wikimedia image was taken now
 * redirects to a page (see the Google attribution in the
 * header comment) with an Adobe Illustrator file, which I
 * have not attempted to reverse-engineer. --RC
 */

#macro AndroidRobot__V3
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  #local AndroidRobot_EyeSocket = cylinder
  { 0, x, AndroidRobot_Eye_radius()
    translate AndroidRobot_Eye_v() * <0, 1, 1>
  }

  #local AndroidRobot_Antenna = #if (Use_merge) merge #else union #end
  { cylinder { 0.019137 * y, 0.422600 * y, 0.015416 }
    sphere { 0.422600 * y, 0.015416 }
    translate 0.108972 * z
    rotate 29 * x
    translate 0.871424 * y
  }

  #local AndroidRobot_Limb = #if (Use_merge) merge #else union #end
  { sphere { 0, 0.108441 }
    cylinder { 0, -0.451836 * y, 0.108441 }
    sphere { -0.451836 * y, 0.108441 }
  }

  #if (Use_merge) merge #else union #end
  {
   // torso
    cylinder { 0.615738 * y, -0.085406 * y, 0.483731 }
    cylinder { -0.085405 * y, -0.202352 * y, 0.366785 }
    torus { 0.366785, 0.116946 translate -0.085406 * y }

   // head
    #if (Use_merge) merge #else union #end
    { difference
      { object { AndroidRobot_Head (0) }
        object { AndroidRobot_EyeSocket }
        object { AndroidRobot_EyeSocket scale <1, 1, -1> }
      }
      object { AndroidRobot_Antenna }
      object { AndroidRobot_Antenna scale <1, 1, -1> }
      AndroidRobot_Head_x (x_Head)
    }

    object
    { AndroidRobot_Limb
      transform { x_Right_arm }
      translate <0, 0.525902, -0.632571>
    }
    object
    { AndroidRobot_Limb
      transform { x_Left_arm }
      translate <0, 0.525902, 0.632571>
    }
    object
    { AndroidRobot_Limb
      translate 0.104188 * y
      transform { x_Right_leg }
      translate <0, -0.093911, -0.180735>
    }
    object
    { AndroidRobot_Limb
      translate 0.104188 * y
      transform { x_Left_leg }
      translate <0, -0.093911, 0.180735>
    }
  }
#end

//============================== PUBLIC MACROS =================================

#macro AndroidRobot_Eye_v()
  #local AndroidRobot_Test = AndroidRobot_Head (0)
  trace
  ( AndroidRobot_Test,
    ( AndroidRobot_Version < 3.0?
      <1, ANDROIDROBOT__EYE_HEIGHT, 0.25>: <1, 0.871424, 0.223260>
    ),
    -x
  )
#end

//--------------------------------------

#macro AndroidRobot_Eye_radius()
  (AndroidRobot_Version < 3.0? 0.05: 0.040399)
#end

//--------------------------------------

#macro AndroidRobot_Head (Outset)
  #if (AndroidRobot_Version < 3.0)
    difference
    { sphere { <0, 0.6, 0>, 0.5 + Outset }
      plane { y, 0.65 - Outset }
    }
  #else
    intersection
    { sphere
      { 0, 1
        scale <0.483731, 0.446521, 0.483731> + Outset
        translate 0.653479 * y
      }
      plane { -y, Outset - 0.654011 }
    }
  #end
#end

//--------------------------------------

#macro AndroidRobot_Head_x (x_Head)
  #local androidrobot_Neck = (AndroidRobot_Version < 3.0? 0.625: 0.634874);
  transform
  { translate -androidrobot_Neck * y // Move center of neck to origin
    transform { x_Head }
    translate androidrobot_Neck * y // Move back from origin
  }
#end

//--------------------------------------

#macro AndroidRobot_Posed
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  #if (AndroidRobot_Version < 3.0)
    AndroidRobot__V2
    ( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
    )
  #else
    AndroidRobot__V3
    ( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
    )
  #end
#end

//--------------------------------------

#macro AndroidRobot (Use_merge)
  AndroidRobot_Posed
  ( Use_merge, transform{}, transform{}, transform{}, transform{}, transform{}
  )
#end

//--------------------- GRANDFATHER ------------------------

#macro AndroidRobot_posed
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  AndroidRobot_Posed
  ( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
  )
#end

//==============================================================================

#version AndroidRobot_Inc_Temp;
#end
// end of androidrobot.inc
