/* rc3metal.inc version 1.2
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       24-jul-2011  Basic colors and textures are gathered from various SDL
 *                    code that I wrote from 2004 to 2008.
 * 1.0   09-mar-2013  Finalized and uploaded.
 * 1.1   23-apr-2013  Added RC3Metal_Set_functions() to define functions.
 *       07-may-2013  Improved debug output for tiny roughness values.
 * 1.2   06-sep-2013  Added RC3Metal_Set_highlight() to coordinate highlight
 *                    and brilliance.
 */
#ifndef (RC3Metal_Inc_Temp) #declare RC3Metal_Inc_Temp = version;
#debug "#include \"rc3metal.inc\" //version 1.2\n"
#declare RC3METAL_VERSION = 1.2;

//The behavior of ambient_light changed in 3.7, so set the version to prevent
//user surprises.
#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("  #version ", str(version,0,1), ";\n")

#include "functions.inc"

//-------------------------------- PARAMETERS ----------------------------------

#ifndef (RC3M_Diffuse) #declare RC3M_Diffuse = 0.6; #end
#ifndef (RC3M_Ambient) #declare RC3M_Ambient = rgb 0.1; #end
#ifndef (RC3M_Debug) #declare RC3M_Debug = off; #end
#ifndef (RC3M_Seed) #declare RC3M_Seed = 0; #end
#ifndef (RC3M_Albedo) #declare RC3M_Albedo = yes; #end

//-------------------------------- CONSTANTS -----------------------------------

// Sample colors.  See documentation for notes.

#declare RC3M_C_ALUMINUM = rgb <0.89, 0.91, 0.91>;
#declare RC3M_C_ALUMINIUM = RC3M_C_ALUMINUM;
#declare RC3M_C_BRASS_COOL = rgb <0.80, 0.72, 0.32>;
#declare RC3M_C_BRASS_LIGHT = rgb <0.80, 0.64, 0.32>;
#declare RC3M_C_BRASS = rgb <0.80, 0.57, 0.23>;
#declare RC3M_C_BRASS_WARM = rgb <0.80, 0.52, 0.20>;
#declare RC3M_C_BRONZE_NEW = rgb <0.80, 0.50, 0.25>;
#declare RC3M_C_BRONZE_COOL = rgb <0.36, 0.30, 0.12>;
#declare RC3M_C_BRONZE = rgb <0.36, 0.26, 0.12>;
#declare RC3M_C_BRONZE_WARM = rgb <0.36, 0.22, 0.12>;
#declare RC3M_C_CHROME = rgb <0.61, 0.61, 0.64>;
#declare RC3M_C_COPPER = rgb <0.80, 0.38, 0.24>;
#declare RC3M_C_COPPER_LIGHT = rgb <0.80, 0.44, 0.32>;
#declare RC3M_C_GOLD = rgb <0.95, 0.75, 0.40>;
#declare RC3M_C_GOLD_LIGHT = rgb <0.95, 0.80, 0.40>;
#declare RC3M_C_NICKEL = rgb <0.68, 0.64, 0.55>;
#declare RC3M_C_PENNY = rgb <0.80, 0.45, 0.25>;
#declare RC3M_C_SILVER = rgb <0.96, 0.96, 0.92>;
#declare RC3M_C_SILVER_COIN = rgb <0.66, 0.63, 0.57>;
#declare RC3M_C_STAINLESS = rgb <0.49, 0.49, 0.49>;
#declare RC3M_C_STAINLESS_WARM = rgb <0.55, 0.55, 0.51>;
#declare RC3M_C_STEEL = rgb <0.61, 0.59, 0.54>;
#declare RC3M_C_ZINC = rgb <0.66, 0.72, 0.72>;
#declare RC3M_C_ZINC_COOL = rgb <0.66, 0.72, 0.78>;
/* Metals I would like to see:
#declare RC3M_C_LEAD = rgb <?, ?, ?>;
#declare RC3M_C_NIOBIUM = rgb <?, ?, ?>;   //used for hypoallergenic body-piercing jewelry
#declare RC3M_C_PEWTER = rgb <?, ?, ?>;
#declare RC3M_C_PLATINUM = rgb <?, ?, ?>;
#declare RC3M_C_RHODIUM = rgb <?, ?, ?>;   //used for white gold plating
#declare RC3M_C_RUTHENIUM = rgb <?, ?, ?>; //used for dark plating for (junk?) jewelry
#declare RC3M_C_SPECULUM = rgb <?, ?, ?>;
#declare RC3M_C_TIN = rgb <?, ?, ?>;
#declare RC3M_C_TITANIUM = rgb <?, ?, ?>;
#declare RC3M_C_TITANIUM_NITRIDE = rgb <?, ?, ?>; //pruners, drill bits
*/

//------------------------------ INITIALIZATION --------------------------------

#declare rc3m__Stochasm = seed (RC3M_Seed);

//---------------------------------- MACROS ------------------------------------

//Converts a number to a string of so many significant digits.
#macro rc3m__Str (Number, Sig)
  #if (Number = 0) str (0, 1, Sig - 1)
  #else str (Number, 1, max (Sig - floor(log(abs(Number))) - 1, 0))
  #end
#end

#macro RC3Metal_Finish (Specularity, Diffuse_part)

  #local rc3m_Albedo_kwd = (version >= 3.7 & RC3M_Albedo);
  #local rc3m_Rough = RC3M_fn_Roughness (Specularity);
  #local rc3m_Hilite = RC3M_fn_Specular (Specularity);
 //If albedo keyword is not used, then adjust the specular level here.
 //See Parser::Parse_Finish() in parstxtr.cpp POV-Ray 3.7 source.
  #if (!rc3m_Albedo_kwd)
    #local rc3m_Hilite = rc3m_Hilite
      * (1 / rc3m_Rough + 2) / (4 * (2 - pow (2, -0.5 / rc3m_Rough)));
  #end
 //Reduce the diffuse to complement the specular value:
  #local rc3m_Actual_diffuse = (1 - Specularity) * Diffuse_part;
 //Preserve the scene's ambient:diffuse ratio:
 // (5-D color must be used to prevent misleading debugging output)
  #local rc3m_Actual_ambient =
    color rc3m_Actual_diffuse * RC3M_Ambient / RC3M_Diffuse
    filter 0 transmit 0;

  #if (RC3M_Debug)
    #debug concat
    ( "RC3Metal_Finish (", str(Specularity,0,6), ", ", str(Diffuse_part,0,6),
      "):\n"
    )
    #debug "  finish\n"
    #debug concat ("  { reflection { ", str (Specularity,0,6), " metallic }\n")
    #debug concat
    ( "    diffuse ",
      #if (rc3m_Albedo_kwd) "albedo ", #end
      str (rc3m_Actual_diffuse, 0, 6), "\n"
    )
    #debug concat
      ("    ambient <", vstr (5, rc3m_Actual_ambient, ", ", 0, 6), ">\n")
    #debug concat
      ("    brilliance ", str (RC3M_fn_Brilliance (Specularity), 0, 6), "\n")
    #debug concat
    ( "    specular ",
      #if (rc3m_Albedo_kwd) "albedo ", #end
      str (rc3m_Hilite, 0, 6),
      " metallic\n"
    )
    #debug concat ("    roughness ", rc3m__Str (rc3m_Rough, 6), "\n")
    #debug "  }\n"
  #end

  finish
  { reflection { Specularity metallic }
    diffuse #if (rc3m_Albedo_kwd) albedo #end rc3m_Actual_diffuse
    ambient rc3m_Actual_ambient
    brilliance RC3M_fn_Brilliance (Specularity)
    specular #if (rc3m_Albedo_kwd) albedo #end rc3m_Hilite metallic
    roughness rc3m_Rough
  }
#end

#macro RC3Metal_Pigment (c_Color, Specularity)
  #local rc3m_Color = color c_Color;
  #local rc3m_Quick_color = rc3m_Color / max (1 - Specularity, 0.001);

  #if (RC3M_Debug)
    #debug concat
    ( "RC3Metal_Pigment (<", vstr (5, rc3m_Color, ", ", 0, 6), ">, ",
      str(Specularity,0,6), "):\n"
    )
    #debug "  pigment\n"
    #debug concat ("  { <", vstr (5, rc3m_Color, ", ", 0, 6), ">\n")
    #debug concat
      ("    quick_color <", vstr (5, rc3m_Quick_color, ", ", 0, 6), ">\n")
    #debug "  }\n"
  #end

  pigment { rc3m_Color quick_color rc3m_Quick_color }
#end

#macro RC3Metal (c_Color, Specularity, Diffuse_part)
  #if (RC3M_Debug) #debug "RC3Metal()...\n" #end
  RC3Metal_Pigment (c_Color, Specularity)
  RC3Metal_Finish (Specularity, Diffuse_part)
#end

#macro RC3Metal_Texture (c_Color, Specularity, Diffuse_part)
  #if (RC3M_Debug) #debug "RC3Metal_Texture()...\n" #end
  texture { RC3Metal (c_Color, Specularity, Diffuse_part) }
#end

#macro RC3Metal_Galvanized_t (c_Dull, c_Shiny, Dull, Shiny, Dark, Light, Shine)
  #if (RC3M_Debug) #debug "RC3Metal_Galvanized_t()...\n" #end
  texture
  { crackle solid texture_map
    { [0 RC3Metal (c_Shiny, Shiny, Light)]
      [Shine RC3Metal (c_Dull, Dull, Light)]
      [1 RC3Metal (c_Dull, Dull, Dark)]
    }
    turbulence 0.25
  }
#end

//http://wiki.povray.org/content/Knowledgebase:Language_Questions_and_Tips#Topic_13

#macro rc3m__Blur_sample_n (Blurriness, Scale)
  bumps Blurriness
  translate
    <rand (rc3m__Stochasm), rand (rc3m__Stochasm), rand (rc3m__Stochasm)> * 100
  scale Scale
#end

#macro RC3Metal_Blur_t (t_Base, Blurriness, Scale, Samples)
  texture
  { average texture_map
    { #local rc3m_I = 0;
      #while (rc3m_I < Samples)
        [1 t_Base normal { rc3m__Blur_sample_n (Blurriness, Scale) }]
        #local rc3m_I = rc3m_I + 1;
      #end
    }
  }
#end

#macro RC3Metal_Normal_blur_t (t_Base, Blurriness, Scale, Samples, n_Normal)
  texture
  { average texture_map
    { #local rc3m_I = 0;
      #while (rc3m_I < Samples)
        [1 t_Base
          normal
          { average normal_map
            { [1 rc3m__Blur_sample_n (Blurriness, Scale)]
              [1 n_Normal]
            }
          }
        ]
        #local rc3m_I = rc3m_I + 1;
      #end
    }
  }
#end

#macro RC3Metal_Blur (o_Object, t_Base, Blurriness, Scale, Samples)
  union
  { object
    { o_Object
      RC3Metal_Blur_t (t_Base, Blurriness, Scale, Samples)
      no_reflection
    }
    object
    { o_Object
      texture { t_Base }
      no_image
    }
  }
#end

#macro RC3Metal_Normal_blur (o_Object, t_Base, Blurriness, Scale, Samples, n_Normal)
  union
  { object
    { o_Object
      RC3Metal_Normal_blur_t (t_Base, Blurriness, Scale, Samples, n_Normal)
      no_reflection
    }
    object
    { o_Object
      texture { t_Base normal { n_Normal } }
      no_image
    }
  }
#end

#macro RC3M_Uncolor_v (c_Color)
  #local rc3m_C = color c_Color;
  <rc3m_C.red, rc3m_C.green, rc3m_C.blue>
#end

#macro RC3M_Uncolour_v (c_Color)
  RC3M_Uncolor_v (c_Color)
#end

#macro RC3Metal_Set_functions (Hilite, Brilliance)
  #ifdef (RC3M_fn_Brilliance) #undef RC3M_fn_Brilliance #end
  #declare RC3M_fn_Brilliance = function (x) { Brilliance }
  #ifdef (RC3M_fn_Specular) #undef RC3M_fn_Specular #end
  #declare RC3M_fn_Specular = function (x) { (1 - Hilite) * x + Hilite }
#end

#macro RC3Metal_Set_highlight (Hilite)
  #declare RC3M_Albedo = false;
  RC3Metal_Set_functions (Hilite, 2 / (1 - Hilite) - 1)
#end

//-------------------------------- FUNCTIONS -----------------------------------
// These functions are based primarily on looks, not physical theory.

//Grandfather the RC3Metal 1.0 settings:
RC3Metal_Set_functions ((version >= 3.7 & RC3M_Albedo? 0.2: 0.4), 2.5)

#declare RC3M_fn_Roughness = function (x)
{ #local rc3m_ROUGH = 400;
  #local rc3m_EPSILON = 1e-10;
  max
  ( rc3m_EPSILON,
    0.06 * (1 / pow (rc3m_ROUGH, x) - 1/rc3m_ROUGH)
         * rc3m_ROUGH / (rc3m_ROUGH - 1)
  )
}

//---------------------------------- NORMAL ------------------------------------

#declare RC3M_n_Brushed = normal
{ function { f_noise3d (x, y * 1000, z * 1000) } - 0.15
}

#version RC3Metal_Inc_Temp;
#end
