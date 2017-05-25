/* coffeemug.pov
 *
 * Demonstration of coffeemug.inc.
 *
 * Copyright 2008 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 * Created 06-aug-2008
 * Updated 07-aug-2008
 */
#ifndef (Ph) #declare Ph = off; #end
#ifndef (Rad) #declare Rad = off; #end
#ifndef (Soft) #declare Soft = off; #end

#include "shapes.inc"
#include "coffeemug.inc"

global_settings
{  assumed_gamma 1
   #if (Rad) radiosity { recursion_limit 1 } #end
   #if (Ph) photons { spacing 0.005 autostop 0 } #end
   max_trace_level 10
}
#default { finish { ambient (Rad? 0: 0.05) } }

camera
{  angle 15 * image_width / image_height
   location <1, 15, -20>
   look_at <0, 2, 0>
   up image_height * y
   right image_width * x
}

#declare LIGHT_POSITION = <-0.5, 1, -1> * 60;

light_source
{  LIGHT_POSITION, rgb 1
   fade_power 2 fade_distance vlength (LIGHT_POSITION)
   spotlight point_at <0, 1.5, 0> radius 5 falloff 10
   #if (Soft) area_light 2.5 * x, 2.5 * z, 9, 9 adaptive 1 circular orient #end
}

plane
{  y, -0.001
   pigment { checker rgb 0.05 rgb 1 scale 2 }
   finish { reflection { 0 0.2 fresnel } }
   interior { ior 1.47 }
}

//----- What!? No cylindrical uv mapping? -----
//
#declare o_Design = Center_Object (text { ttf "povlogo.ttf" "P" 1, 0 scale 4/3 }, x+y+z)

#declare fn_Design = function
{  pigment
   {  object
      {  union
         {  object { o_Design translate -pi/2 * x }
            object { o_Design translate pi/2 * x }
         }
         rgb 0 rgb 1
      }
   }
}

#declare p_Design = pigment
{  function
   {  fn_Design (atan2 (-x, z), (y - 2) / 1.5, 0).red
   }
   color_map { [0.5 rgb 1] [0.5 rgb <0, 0.25, 1>] }
}

#declare p_Design_shell = pigment 
{  object
   {  cylinder { 0, 3.75 * y, 1.499 }
      pigment { p_Design }
      pigment { rgb 1 }
   }
}
//
//----- See ChrisB's labeller for fancier prints -----

object
{  CoffeeMug_Mug (1.5, 3.75, COFFEEMUG_HEIGHT, no)
   pigment { p_Design_shell }
   finish { specular 1 roughness 0.002 reflection { 0.05 0.4 fresnel } }
   interior { ior 1.6 }
   photons { target reflection on }
   rotate -60 * y
}

object
{  CoffeeMug_Beverage (1.5, 0, 8, COFFEEMUG_INCH, 0.0001)
   hollow
   pigment { rgbft <0.9, 0.65, 0.4, 0.5, 0.1> }
   finish
   {  specular 1 roughness 0.01
      reflection { 0, 1 fresnel } conserve_energy
   }
   interior
   {  ior 1.34
      media
      {  absorption <0.25, 0.5, 0.75>
         scattering { 3, 1 }
      }
   }
}
