/* androidrobot.inc version 4.0
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * A 3-D model of Google's Android[TM] mascot.
 *
 * Android is a trademark of Google Inc.  The Android robot is reproduced or
 * modified from work created and shared by Google and used according to terms
 * described in the Creative Commons 3.0 Attribution License.
 * See https://developer.android.com/distribute/marketing-tools/ and
 * https://creativecommons.org/licenses/by/3.0/ for more information.
 *
 * See also https://commons.wikimedia.org/wiki/File:Android_Robot_POV-Ray.png
 *
 * SDL is copyright 2011 - 2018 Richard Callwood III.  Some rights reserved.
 * Portions copyright 2009 Karl Ostmo.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments                                       Author
 * ----  ----         --------                                       ------
 * 1.0   2009-Oct-30  The original code is written as droid.pov.     K. Ostmo
 *
 * 2.0   2011-Jul-23  The code is separated into include and demo    R. Callwood
 *                      files.
 *                    The code is made fully namespace compliant.
 *                    The pigment is removed from the robot and the
 *                      official color is declared separately.
 *                    The robot can be posed.
 *
 * 2.1   2012-Jun-26  Non-gamma-adjusted official color is added.    R. Callwood
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
 * 3.0a  2015-Apr-27  A correction is made to the user manual.       R. Callwood
 *
 * 4.0   2018-Sep-23  The short prefix is reinstated.                R. Callwood
 *                    The official color is updated.                 R. Callwood
 *
 * Author's note:  OK, so the remodeled robot isn't as cute as Ostmo's version,
 * due to the eyes being higher set on the face.  Still, the remodeling was a
 * worthy effort, and the old, cuter versions are still available by setting the
 * variable AndroidRobot_Version. --RC
 */
#ifndef (AndroidRobot_Inc_Temp) #declare AndroidRobot_Inc_Temp = version;
#debug "#include \"androidrobot.inc\" //version 4.0\n"

#ifndef (AndroidRobot_Version) #declare AndroidRobot_Version = 4.0; #end

//Take advantage of POV-Ray 3.7 feature if and only if available:
#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("  #version ", str(version,0,1), ";\n")

//============================= PUBLIC CONSTANTS ===============================

#declare ANDROIDROBOT_HEIGHT = 1.65;
#declare ANDROIDROBOT_V_BASE = <0, -0.55, 0>;

//======================== INTERNAL (PRIVATE) MACROS ===========================

//---------------------- Ostmo model -----------------------

#declare DROID__EYE_HEIGHT = 0.8;

#macro AndroidRobot__V2
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  #local DROID_ANTENNAE_ANGLE = 30;
  #local DROID_ANTENNAE_LENGTH = 0.2;
  #local DROID_XARM = (AndroidRobot_Version < 2.2? 0.6: 0.65);

  #local Droid_Antenna = cylinder
  { <0, DROID_ANTENNAE_LENGTH, 0>, <0, 0, 0>, 0.02
  }

  #local Droid_Arm = #if (Use_merge) merge #else union #end
  { sphere { <0, 0.5, 0>, 0.1 }
    cylinder { <0, 0.5, 0>, <0, 0.1, 0>, 0.1 }
    sphere { <0, 0.1, 0>, 0.1 }
  }

  #local Droid_Leg = #if (Use_merge) merge #else union #end
  { cylinder
    { <0, 0.5, 0>, <0, -0.2, 0>, 0.1
      translate <0, -0.25, 0>
    }
    sphere
    { <0, -0.2, 0>, 0.1
      translate <0, -0.25, 0>
    }
  }

  #local Droid_EyeSocket = cylinder
  { <0, 0.5, 0>, <0, 0, 0>, 0.05
    rotate z*(-90)
    translate <0, DROID__EYE_HEIGHT, 0>
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
        object { Droid_EyeSocket translate z*(-.25) }
        object { Droid_EyeSocket translate z*(.25) }
      }
      object
      { Droid_Antenna
        rotate x*(-DROID_ANTENNAE_ANGLE)
        translate <0, 1, -0.25>
      }
      object
      { Droid_Antenna
        rotate x*(DROID_ANTENNAE_ANGLE)
        translate <0, 1, 0.25>
      }
      AndroidRobot_Head_x (x_Head)
    }

    object
    { Droid_Arm
      translate -0.5 * y //move to origin
      transform { x_Right_arm }
      translate 0.5 * y //move back from origin
      translate z*(-DROID_XARM)
    }

    object
    { Droid_Arm
      translate -0.5 * y //move to origin
      transform { x_Left_arm }
      translate 0.5 * y //move back from origin
      translate z*(DROID_XARM)
    }

    object
    { Droid_Leg
      translate 0.1 * y //move to origin
      transform { x_Left_leg }
      translate -0.1 * y //move back from origin
      translate z*(.25)
    }

    object
    { Droid_Leg
      translate 0.1 * y //move to origin
      transform { x_Right_leg }
      translate -0.1 * y //move back from origin
      translate z*(-.25)
    }

  }
#end

//-------------------- Callwood model ----------------------

/* The messy values in this section were derived from the file
 * https://commons.wikimedia.org/wiki/File:Android_robot.svg, and transformed
 * such that the new version of the robot has the same size and position as the
 * Ostmo model.
 *
 * The Google Web page from which the Wikimedia image was taken now redirects
 * to a page (see the Google attribution in the header comment) with a different
 * SVG file.  This new file has most of the code packed into a single <path>
 * element, making it much harder to decipher, but it appears prima facie
 * to have the same or similar dimensions as the old file. --RC
 */

#macro AndroidRobot__V3
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  #local Droid_EyeSocket = cylinder
  { 0, x, AndroidRobot_Eye_radius()
    translate AndroidRobot_Eye_v() * <0, 1, 1>
  }

  #local Droid_Antenna = #if (Use_merge) merge #else union #end
  { cylinder { 0.019137 * y, 0.422600 * y, 0.015416 }
    sphere { 0.422600 * y, 0.015416 }
    translate 0.108972 * z
    rotate 29 * x
    translate 0.871424 * y
  }

  #local Droid_Limb = #if (Use_merge) merge #else union #end
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
        object { Droid_EyeSocket }
        object { Droid_EyeSocket scale <1, 1, -1> }
      }
      object { Droid_Antenna }
      object { Droid_Antenna scale <1, 1, -1> }
      AndroidRobot_Head_x (x_Head)
    }

    object
    { Droid_Limb
      transform { x_Right_arm }
      translate <0, 0.525902, -0.632571>
    }
    object
    { Droid_Limb
      transform { x_Left_arm }
      translate <0, 0.525902, 0.632571>
    }
    object
    { Droid_Limb
      translate 0.104188 * y
      transform { x_Right_leg }
      translate <0, -0.093911, -0.180735>
    }
    object
    { Droid_Limb
      translate 0.104188 * y
      transform { x_Left_leg }
      translate <0, -0.093911, 0.180735>
    }
  }
#end

//============================== PUBLIC MACROS =================================

#macro AndroidRobot_Eye_v()
  #local Droid_Test = AndroidRobot_Head (0)
  trace
  ( Droid_Test,
    ( AndroidRobot_Version < 3.0?
      <1, DROID__EYE_HEIGHT, 0.25>: <1, 0.871424, 0.223260>
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
  #local droid_Neck = (AndroidRobot_Version < 3.0? 0.625: 0.634874);
  transform
  { translate -droid_Neck * y // Move center of neck to origin
    transform { x_Head }
    translate droid_Neck * y // Move back from origin
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

//--------------------------------------

#macro AndroidRobot_Set_color (Version)
  #declare DROID_C_RAWCOLOR = rgb
  ( Version < 4?
    <164, 198, 57>: // #A4C639
    <120, 194, 87>  // #78C257
  ) / 255;
  #if (version < 3.7)
    #declare DROID_C_COLOR = rgb
    < pow (DROID_C_RAWCOLOR.red, 2.2),
      pow (DROID_C_RAWCOLOR.green, 2.2),
      pow (DROID_C_RAWCOLOR.blue, 2.2)
    >;
  #else
    #declare DROID_C_COLOR = srgbft DROID_C_RAWCOLOR;
  #end
  #declare ANDROIDROBOT_C_RAWCOLOR = DROID_C_RAWCOLOR;
  #declare ANDROIDROBOT_C_COLOR = DROID_C_COLOR;
#end

AndroidRobot_Set_color (AndroidRobot_Version) // Initialize.

//--------------------- GRANDFATHER ------------------------

#macro AndroidRobot_posed
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  AndroidRobot_Posed
  ( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
  )
#end

//=============================  SHORT PREFIXES ================================

#declare DROID_HEIGHT = ANDROIDROBOT_HEIGHT;
#declare DROID_V_BASE = ANDROIDROBOT_V_BASE;
#macro Droid_Eye_v() AndroidRobot_Eye_v() #end
#macro Droid_Eye_radius() AndroidRobot_Eye_radius() #end
#macro Droid_Head (Outset) AndroidRobot_Head (Outset) #end
#macro Droid_Head_x (x_Head) AndroidRobot_Head_x (x_Head) #end
#macro Droid_Posed
( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
)
  AndroidRobot_Posed
  ( Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg
  )
#end
#macro Droid (Use_merge) AndroidRobot (Use_merge) #end
#macro Droid_Set_color (Version) AndroidRobot_Set_color (Version) #end

//==============================================================================

#version AndroidRobot_Inc_Temp;
#end
// end of androidrobot.inc
