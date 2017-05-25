/* androidrobot.inc
 *
 * Google's Android Robot.
 * Used under the Creative Commons Attribution 3.0 License.
 * See http://www.android.com/branding.html and
 * http://creativecommons.org/licenses/by/3.0/ for more information.
 *
 * See also http://commons.wikimedia.org/wiki/File:Android_Robot_POV-Ray.png
 *
 * Copyright 2011 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date          Comments                            Author
 * -----  ----          --------                            ------
 * 1.0    30-oct-2009   Original code written as droid.pov  Karl Ostmo
 *
 * 2.0    23-jul-2011   Code is separated into include      Richard Callwood III
 *                        and demo files
 *                      Code is made fully compliant
 *                      Removed pigment from robot and declared
 *                        the official color separately
 *                      Robot can be posed
 *
 * Disclaimer:  I know nothing about Android.  I just thought the robot looked
 * cute.
 */

#ifndef (ANDROIDROBOT_INC) #declare ANDROIDROBOT_INC = version;
#debug "#include \"androidrobot.inc\" //version 2.0\n"
#debug "  Copyright 2011 Richard Callwood III.  Some rights reserved.\n"
#debug "  Portions copyright 2009 Karl Ostmo.  Some rights reserved.\n"

#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("#version ", str(version,0,1), ";\n")

#declare ANDROIDROBOT_V_BASE = <0, -0.55, 0>;
#if (version < 3.7)
   #declare ANDROIDROBOT_C_COLOR = rgb
      <pow (164/255, 2.2), pow (198/255, 2.2), pow (57/255, 2.2)>; // #A4C639
#else
   #declare ANDROIDROBOT_C_COLOR = srgb <164, 198, 57> / 255; // #A4C639
#end


#macro AndroidRobot_posed
   (Use_merge, x_Head, x_Left_arm, x_Right_arm, x_Left_leg, x_Right_leg)

   #local ANDROIDROBOT_ANTENNAE_ANGLE = 30;
   #local ANDROIDROBOT_ANTENNAE_LENGTH = 0.2;
   #local ANDROIDROBOT_EYE_HEIGHT = 0.8;

   #local AndroidRobot_Antenna = cylinder
   { 	<0, ANDROIDROBOT_ANTENNAE_LENGTH, 0>, <0, 0, 0>, 0.02
   }
   
   #local AndroidRobot_Arm = #if (Use_merge) merge #else union #end
   {  sphere { <0, 0.5, 0>, 0.1 }
      cylinder { <0, 0.5, 0>, <0, 0.1, 0>, 0.1 }
      sphere { <0, 0.1, 0>, 0.1 }
   }

   #local AndroidRobot_Leg = #if (Use_merge) merge #else union #end
   {  cylinder
      {  <0, 0.5, 0>, <0, -0.2, 0>, 0.1
         translate <0, -0.25, 0>
      }
      sphere
      {  <0, -0.2, 0>, 0.1
         translate <0, -0.25, 0>
      }
   }

   #local AndroidRobot_EyeSocket = cylinder
   {  <0, 0.5, 0>, <0, 0, 0>, 0.05
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
      {  difference
         {  sphere { <0, 0.6, 0>, 0.5 }
            plane { y, 0.65 }
            object { AndroidRobot_EyeSocket translate z*(-.25) }
            object { AndroidRobot_EyeSocket translate z*(.25) }
         }
         object
         {  AndroidRobot_Antenna
            rotate x*(-ANDROIDROBOT_ANTENNAE_ANGLE)
            translate <0, 1, -0.25>
         }
         object
         {  AndroidRobot_Antenna
            rotate x*(ANDROIDROBOT_ANTENNAE_ANGLE)
            translate <0, 1, 0.25>
         }
         translate -0.625 * y //move to origin
         transform { x_Head }
         translate 0.625 * y //move back from origin
      }

      object
      {  AndroidRobot_Arm
         translate -0.5 * y //move to origin
         transform { x_Right_arm }
         translate 0.5 * y //move back from origin
         translate z*(-0.6)
      }

      object
      {  AndroidRobot_Arm
         translate -0.5 * y //move to origin
         transform { x_Left_arm }
         translate 0.5 * y //move back from origin
         translate z*(0.6)
      }

      object
      {  AndroidRobot_Leg
         translate 0.1 * y //move to origin
         transform { x_Left_leg }
         translate -0.1 * y //move back from origin
         translate z*(.25)
      }

      object
      {  AndroidRobot_Leg
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
