/* rc3metal.pov version 1.0
 * Persistence of Vision Raytracer scene file
 * POV-Ray Object Collection demo
 *
 * Demo of rc3metals.inc
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       23-sep-2011  Created.
 * 1.0   09-mar-2013  Uploaded.
 */
/*
 * POV-Ray 3.5 or 3.7 //+a0.05 +r3 +am2 +w800 +h600
 * POV-Ray 3.6        //+a0.01 +r3 +am2 +w800 +h600
 * POV-Ray 3.7 only   //+a0.05 +r3 +am2 +w800 +h600 declare=Use37=1
 * Fast test          //+a declare=Fast=1 declare=Rad=0 +otest
*/
#version 3.5;

//-------------------------------- PARAMETERS ----------------------------------

#ifndef (Use37) #declare Use37 = no; #end
#if (Use37) #version 3.7; #end
#ifndef (Fast) #declare Fast = no; #end
#ifndef (Rad) #declare Rad = 2; #end

/* Fast  Micronormals  Shadows
 * ----  ------------  -------
 * no    yes           fuzzy
 * yes   no            sharp
 *
 * Rad  Radiosity
 * ---  ---------
 *  0   none
 *  1   low quality
 *  2   high quality
 */

#declare C_LIGHT = rgb (<1.17, 0.96, 0.78> #if (Rad) * 0.75 #end);
#declare OUTDOOR_BRIGHTNESS = 10;
#declare RC3M_Ambient = rgb (Rad? 0: <0.175, 0.16, 0.15>);

#declare RROOM = 6;
#declare HROOM = 8;
#declare DWALL = 0.5;
#declare XWIN = 3;
#declare RWWIN = 1.25;
#declare YSILL = 3;
#declare HWIN = 3.5;
#declare RLIGHT = 1/3;

#declare V_LIGHT = <0, HROOM - 1, 0>;
#declare V_AIM = <0, 1, RROOM - 2>;
#declare v_Floor_spot = <V_AIM.x, 0, V_AIM.z>;

//-------------------------------- LIBRARIES -----------------------------------

#include "shapes.inc"
#include "rc3metal.inc"

//--------------------------------- SETTINGS -----------------------------------

#default { finish { ambient RC3M_Ambient } }

global_settings
{ assumed_gamma 1
  max_trace_level 10
  #if (Rad)
    radiosity
    { always_sample no
      error_bound 0.5
      nearest_count 1
      #if (Rad = 1)
        count 200
        pretrace_end 0.01
        recursion_limit 1
        brightness 1.25
      #else
        count 400
        pretrace_end 2 / max (image_width, image_height)
        pretrace_start 32 / max (image_width, image_height)
        recursion_limit 2
      #end
    }
  #end
}

camera
{ location <1 - RROOM, 5, 1 - RROOM>
  look_at V_AIM + <0.14, -0.14, 0>
  angle 22.5
}

//------------------------------- ENVIRONMENT ----------------------------------

//------- outdoor illumination ---------

sky_sphere
{ pigment
  { gradient -y color_map
    { [0 rgb <0.100, 0.167, 0.400> * OUTDOOR_BRIGHTNESS]
      [1 rgb <0.433, 0.500, 0.667> * OUTDOOR_BRIGHTNESS]
    }
  }
}

plane
{ y, -1
  pigment { rgb <0.186, 0.223, 0.059> }
  finish
  { diffuse 0
    #if (version < 3.7) ambient OUTDOOR_BRIGHTNESS 
    #else ambient 0 emission OUTDOOR_BRIGHTNESS 
    #end
  }
}

//--------------- room -----------------

union
{ box { -z, 1 scale <DWALL, HROOM, RROOM + DWALL> translate RROOM * x }
  box { -z, 1 scale <-DWALL, HROOM, RROOM + DWALL> translate -RROOM * x }
  box { -x, 1 scale <RROOM, HROOM, DWALL> translate RROOM * z }
  difference
  { box { -x, 1 scale <RROOM, HROOM, -DWALL> }
    box { <-RWWIN, 0, -1>, <RWWIN, HWIN, 1> translate <-XWIN, YSILL, 0> }
    box { <-RWWIN, 0, -1>, <RWWIN, HWIN, 1> translate <XWIN, YSILL, 0> }
    translate -RROOM * z
  }
  box { y - 1, 1 scale RROOM + DWALL translate HROOM * y }
  pigment { rgb 1 }
}

box { -1, 1 - y scale RROOM + DWALL pigment { checker rgb 1 rgb 0.05 } }

//------- indoor illumination ----------

union
{ light_source
  { 0, C_LIGHT * 2.5
    fade_power 2 fade_distance vlength (V_LIGHT - V_AIM) / 2
    #if (!Fast)
      area_light 2*RLIGHT * x, 2*RLIGHT * z, 9, 9
      circular orient adaptive 1 jitter
    #end
    looks_like
    { sphere
      { 0, RLIGHT
        pigment { C_LIGHT }
        finish { #if (version < 3.7) ambient #else emission #end 5 }
      }
    }
  }
  union
  { cylinder { RLIGHT * y, (HROOM - V_LIGHT) * y, 1/16 }
    cone { y, 1, 2*y, 0 open scale RLIGHT / sqrt(2) }
    RC3Metal (RC3M_C_BRONZE, 0.1, 0.6)
  }
  translate V_LIGHT
}

//----------------------------------- DEMO -------------------------------------

#macro Stand (c_Medal, Height, s_Label)
  #local R = 0.4;
  #local R1 = 0.1;
  #local R2 = 0.04;
  #local R3 = 0.01;
  #local c_Bronze = RC3M_C_BRONZE_WARM * 0.4 + RC3M_C_BRONZE * 0.3;
  #local Platform = union
  { difference
    { cylinder { (Height - 2*R1 - R2) * y, Height * y, R - R1 }
      torus { R - R1, R2 translate (Height - 2*R1 - R2) * y }
    }
    cylinder { (2*R1 + R2) * y, (Height - 2*R1 - R2) * y, R - R1 - R2 }
    difference
    { cylinder { R1 * y, (2*R1 + R2) * y, R - R1 }
      torus { R - R1, R2 translate (2*R1 + R2) * y }
    }
    cylinder { R3 * y, R1 * y, R }
    torus { R - R1, R1 translate (Height - R1) * y }
    torus { R - R1, R1 translate R1 * y }
    torus { R - R3, R3 translate R3 * y }
    //no_radiosity
  }
  union
  { sphere
    { y, 1 scale 0.5
      RC3Metal (c_Medal, 0.5, 0.7)
      translate Height * y
    }
    #if (Fast)
      object { Platform RC3Metal (c_Bronze, 0.18, 0.6) }
    #else
      RC3Metal_Blur
      ( Platform,
        RC3Metal_Texture (c_Bronze, 0.25, 0.6),
        0.35, 0.001, 5
      )
    #end
    #local o_Label = text { ttf "cyrvetic.ttf" s_Label 1, 0 }
    object
    { o_Label Center_Trans (o_Label, x)
      scale <0.6, 0.6, -0.005>
      RC3Metal (RC3M_C_ALUMINUM, 0.25, 0.7)
      #if (!Fast) normal { RC3M_n_Brushed } #end
      translate <0, 1/24, -R>
      //no_radiosity
    }
  }
#end

object
{ Stand (RC3M_C_GOLD, 1, "1")
  translate v_Floor_spot + <0, 0, 1>
}
object
{ Stand (RC3M_C_SILVER, 0.75, "2")
  translate v_Floor_spot + <-1.2, 0, 1>
}
object
{ Stand (RC3M_C_BRONZE_NEW, 0.5, "3")
  translate v_Floor_spot + <1.2, 0, 1>
}

sphere
{ y, 1 scale 0.5
  uv_mapping texture
  { RC3Metal_Finish (0.25, 0.7)
    pigment //"antique brass"
    { bozo color_map
      { [0.4 RC3M_C_BRONZE_COOL * 0.7]
        [0.6 RC3M_C_BRASS_COOL * 0.7]
      }
    }
    #if (!Fast) normal { bozo 0.01 } #end
    scale <1, 0.001, 1>
  }
  rotate -90 * y //Turn uv-mapped seam so it doesn't reflect in chrome sphere
  translate v_Floor_spot + <-1.2, 0, -1>
}

sphere
{ y, 1 scale 0.5
  RC3Metal (RC3M_C_CHROME, 0.9, 0.7)
  translate v_Floor_spot + <0, 0, -1>
}

#declare t_Galv = RC3Metal_Galvanized_t
  (RC3M_C_ZINC, RC3M_C_STEEL, 0, 0.5, 0.35, 0.7, 0.4)
object
{ Wire_Box_Union (-<0.5, 0, 0.5>, <0.5, 1, 0.5>, 1/12)
  texture { t_Galv scale 0.05 }
  translate v_Floor_spot + <1.2, 0, -1>
}
