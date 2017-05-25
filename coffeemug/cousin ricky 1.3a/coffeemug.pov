/* coffeemug.pov 1.3a
 * Persistence of Vision Ray Tracer scene file
 * POV-Ray Object Collection demo
 *
 * Demonstration of coffeemug.inc.
 *
 * Copyright 2008 - 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   06-aug-2008  Created.
 * 1.0   07-aug-2008  Submitted to the POV-Ray Object Collection.
 * 1.1   08-aug-2008  Updated.
 * 1.2   31-aug-2008  No change.
 * 1.3   20-may-2013  Tweaked textures & lighting; #version is added.
 * 1.3a  21-may-2013  Version 1.3 re-uploaded with correct sample output.
 */
#version 3.5;

#ifndef (Ph) #declare Ph = off; #end
#ifndef (Rad) #declare Rad = off; #end
#ifndef (Soft) #declare Soft = off; #end
#ifndef (Textured) #declare Textured = no; #end

#include "shapes.inc"
#include "coffeemug.inc"

global_settings
{  assumed_gamma 1
   #if (Rad) radiosity { recursion_limit 2 } #end
   #if (Ph) photons { spacing 0.005 autostop 0 } #end
   max_trace_level 10
}
#default { finish { ambient (Rad? 0: 0.05) } }

background { rgb 0.1 }

camera
{  location <1, 15, -20>
   look_at <0, 2, 0>
   angle 20
}

#declare LIGHT_POSITION = <-0.5, 1, -1> * 60;

light_source
{  LIGHT_POSITION, rgb 1
   fade_power 2 fade_distance vlength (LIGHT_POSITION)
   spotlight point_at <0, 1.5, 0> radius 5 falloff 10
   #if (Soft) area_light 2.5 * x, 2.5 * z, 9, 9 adaptive 1 circular orient #end
}

plane
{  y, 0
   pigment { checker rgb 0.025 rgb 1 scale 2 }
   finish { reflection { 0 0.2 fresnel } conserve_energy }
   interior { ior 1.47 }
}

//------------------------------------------------------------------------------

#declare o_Design = Center_Object (text { ttf "povlogo.ttf" "P" 1, 0 scale 2 }, x+y+z)

#declare p_Design = CoffeeMug_Pigment
   (1.5, 0, 3.75, COFFEEMUG_HEIGHT, o_Design, rgb 1, rgb <0, 0.25, 1>)

#declare f_Gloss = finish
{  specular 4.24 roughness 0.002
   reflection { 0.05 0.4 fresnel } conserve_energy
}

#declare t_Dark = texture
{  pigment { rgb <0.04, 0.03, 0.1> }
   finish { f_Gloss }
}

#declare t_Gold = texture
{  pigment { rgb <0.95, 0.75, 0.4> }
   finish
   {  reflection { 0.5 metallic }
      diffuse 0.3
      ambient (Rad? 0: 0.025)
      specular 22 metallic
      roughness 1/350
   }
   normal { crackle 2 scale 0.01 }
}

#declare t_Design = CoffeeMug_Texture
   (1.5, 0, 3.75, COFFEEMUG_HEIGHT, o_Design, t_Dark, t_Gold)

//------------------------------------------------------------------------------

object
{  CoffeeMug_Mug (1.5, 3.75, COFFEEMUG_HEIGHT, no)
   #if (Textured)
      texture
      {  object
         {  plane { x, 0 }
            texture { t_Design rotate 90 * y }
            texture { t_Design rotate -90 * y }
         }
      }
   #else
      pigment
      {  object
         {  plane { x, 0 }
            pigment { p_Design rotate 90 * y }
            pigment { p_Design rotate -90 * y }
         }
      }
      finish { f_Gloss }
   #end
   interior { ior 1.6 }
   photons { target reflection on }
   rotate -60 * y
}

object
{  CoffeeMug_Beverage (1.5, 0, 8, COFFEEMUG_INCH, 0.0001)
   hollow
   pigment { rgbft <0.9, 0.65, 0.4, 0.5, 0.1> }
   finish
   {  specular 0.64 roughness 0.01
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
