/* coffeemug.pov version 2.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstration of coffeemug.inc.
 *
 * Frame number or Texture parameter:
 *   1 - Masked pigment
 *   2 - Non-masked pigment
 *   3 - Masked texture
 *   4 - Non-masked texture
 *
 * Copyright 2008 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   2008-Aug-06  Created.
 * 1.0   2008-Aug-07  Submitted to the POV-Ray Object Collection.
 * 1.1   2008-Aug-08  Updated.
 * 1.2   2008-Aug-31  No change.
 * 1.3   2013-May-20  Tweaked textures & lighting; #version is added.
 * 1.3a  2013-May-21  Version 1.3, re-uploaded with correct sample output.
 *       2015-Feb-22  The table surface is changed from checker to a less
 *                    distracting wood.
 *       2015-Feb-26  Ambient light is reconfigured due to wooden surface.
 *       2015-Feb-28  Demos of cylindrical textures are added.
 *       2015-Mar-03  Coffee material is made stand-alone.
 *       2015-Mar-04  Some prefixes are shortened here and there.
 * 2.0   2015-Mar-05  Coffee beverage material is tweaked.
 */
// (If rendering into your Object Collection folder, then do not omit the
// underscore below.)
// +kff4 +ocoffeemug_
#version 3.5;

#ifndef (Ph) #declare Ph = off; #end // photons
#ifndef (Rad) #declare Rad = off; #end // radiosity
#ifndef (Soft) #declare Soft = off; #end // soft shadows
#if (clock_on)
  #declare Texture = frame_number;
#else
  #ifndef (Texture) #declare Texture = 4; #end
#end
#declare C_SKY = rgb 0.1;

#default // for wood texture only
{ finish
  { reflection { 0 0.2 fresnel } conserve_energy
    ambient (Rad? 0: C_SKY)
  }
}
#include "colors.inc" // required by woodmaps.inc 3.5/3.6
#include "woods.inc"

#include "shapes.inc"
#include "coffeemug.inc"

//=============================== ENVIRONMENT ==================================

global_settings
{ assumed_gamma 1
  #if (Rad)
    radiosity
    { count 100
      error_bound 0.5
      pretrace_start 0.08
      pretrace_end 0.01
      recursion_limit 2
    }
  #end
  #if (Ph) photons { spacing 0.005 autostop 0 } #end
  max_trace_level 10
}

camera
{ location <1, 13.5, -18>
  look_at <0, 1.95, 0>
  angle 20
}

#declare LIGHT_POSITION = <-0.5, 1, -1> * 60;
light_source
{ LIGHT_POSITION, rgb 1
  fade_power 2 fade_distance vlength (LIGHT_POSITION)
  spotlight point_at <0, 1.5, 0> radius 5 falloff 10
  #if (Soft) area_light 2.5 * x, 2.5 * z, 9, 9 adaptive 1 circular orient #end
}

//----- A little ambience -----
background { C_SKY }

//----- Estimate ambient light -----
#declare Illumination = vdot (vnormalize (LIGHT_POSITION), y);
#declare c_Table = rgb <0.295, 0.163, 0.118>; // sampled from T_Wood12
#declare LIT = 0.8; // estimate of contribution of spotlit portion of the table
#declare DIFFUSE = 0.6; // this scene's diffuse (which is the POV-Ray default)
#declare Ambience =
( Rad?
  0:
  (C_SKY + c_Table * (C_SKY + Illumination * DIFFUSE * LIT)) / 2
);
#default { finish { ambient Ambience } }

//----- The table -----
plane
{ y, 0
  texture
  { T_Wood12
    rotate <0, 5, 0>
    scale 2
  }
  interior { ior 1.47 }
}

//=============================== MUG TEXTURES =================================

//------------------- Texture elements ---------------------

#declare o_Design = Center_Object (text { ttf "povlogo.ttf" "P" 1, 0 }, x+y+z)

#declare p_Image = pigment
{// Note:  For POV-Ray 3.5/3.6 compatibility,
 // coffeemug_map.jpg was rendered with File_Gamma=1.
  image_map { jpeg "coffeemug_map" interpolate 2 }
  translate -0.5 // must be centered on the origin
  scale 2.5
}

#declare o_Pic_area = Round_Box_Union (-<1.25, 1.25, 1>, <1.25, 1.25, 1>, 0.2)

#declare p_Pattern = pigment
{ leopard color_map
  { [0.1 rgb <1, 0.8, 0>]
    [0.1 rgb <0.88, 0, 0.022>]
  }
  scale 0.1
}

#declare f_Gloss = finish
{ specular 4.24 roughness 0.002
  reflection { 0.05 0.4 fresnel } conserve_energy
}

#declare t_White = texture
{ pigment { rgb 1 }
  finish { f_Gloss }
}

#declare t_Dark = texture
{ pigment { rgb <0.04, 0.03, 0.1> }
  finish { f_Gloss }
}

#declare t_Gold = texture
{ pigment { rgb <0.97, 0.74, 0.33> }
  finish
  { reflection { 0.5 metallic }
    diffuse 0.5 * DIFFUSE
    ambient (Rad? 0: 0.5 * Ambience)
    specular 22 metallic
    roughness 1/350
  }
  normal { crackle 1 scale 0.01 }
}

//----- Create array of POV logos -----
#declare DELTAX = 0.125 * pi;
#declare DELTAY = 0.46;
#declare o_Smaller = object { o_Design scale <0.5, 0.5, 0.1> }
#declare p_Logo_array = pigment
{ object
  { union
    { object { o_Smaller translate <0, DELTAY * 2, 0> }
      object { o_Smaller }
      object { o_Smaller translate <0, -DELTAY * 2, 0> }
      object { o_Smaller translate <DELTAX, DELTAY * 3, 0> }
      object { o_Smaller translate <DELTAX, DELTAY, 0> }
      object { o_Smaller translate <DELTAX, -DELTAY, 0> }
      object { o_Smaller translate <DELTAX, -DELTAY * 3, 0> }
    }
    rgb 0 rgb 1
  }
  translate DELTAX/2 * x
  warp { repeat DELTAX * 2 * x }
  translate -DELTAX/2 * x
}
#declare fn_Logo_array = function { pigment { p_Logo_array } }
//----- POV logo array is created -----

#declare t_Ensemble = texture
{ object
  { o_Pic_area
    texture
    { function { fn_Logo_array (x, y, z).x }
      texture_map { [0 t_White] [1 t_Gold] }
    }
    texture
    { pigment { p_Image }
      finish { f_Gloss }
    }
  }
}

//-------------------- Final textures ----------------------

#switch (Texture)
  #case (1)
    #declare p_Design = CoffeeMug_Pigment
    ( 1.5, 0, 3.75, MUG_HEIGHT, o_Pic_area, rgb 1, p_Image
    )
    #break
  #case (2)
    #declare p_Design = CoffeeMug_Pigment
    ( 1.5, 0, 3.75, MUG_HEIGHT, MUG_NO_MASK, rgb 1, p_Pattern
    )
    #break
  #case (3)
    #declare t_Design = CoffeeMug_Texture
    ( 1.5, 0, 3.75, MUG_HEIGHT, object { o_Design scale 2 }, t_Dark, t_Gold
    )
    #break
  #case (4)
    #declare t_Design = CoffeeMug_Texture
    ( 1.5, 0, 3.75, MUG_HEIGHT, MUG_NO_MASK, t_White, t_Ensemble
    )
    #break
#end

//============================= COFFEE MATERIAL ================================

#declare m_Coffee = material
{ texture
  { pigment { rgbf <0.9, 0.7, 0.4, 1> }
    finish
    { specular 0.64 roughness 0.01
      reflection { 0, 1 fresnel } conserve_energy
    }
  }
  interior
  { ior 1.34
    media
    { absorption <0.25, 0.4, 0.75>
      scattering { 3, rgb 1 }
    }
  }
}

//================================ SHOWPIECE ===================================

union
{
  object
  { CoffeeMug_Mug (1.5, 3.75, MUG_HEIGHT, no)
    #switch (Texture)
      #case (1) // object pigment
        pigment
        { object
          { plane { x, 0 }
            pigment { p_Design rotate 90 * y }
            pigment { p_Design rotate -90 * y }
          }
        }
        finish { f_Gloss }
        #break
      #case (2) // wrapped pigment
        pigment { p_Design }
        finish { f_Gloss }
        #break
      #case (3) // object texture
      #case (4) // wrapped texture
        texture
        { object
          { plane { x, 0 }
            texture { t_Design rotate 90 * y }
            texture { t_Design rotate -90 * y }
          }
        }
        #break
      #else // undefined Texture parameter
        pigment { rgb 0.5 }
    #end
    interior { ior 1.6 }
    photons { target reflection on }
  }

  object
  { CoffeeMug_Beverage (1.5, 0, 8, MUG_INCH, 0.001)
    hollow
    material { m_Coffee }
  }

  rotate -60 * y
}
// end of coffeemug.pov
