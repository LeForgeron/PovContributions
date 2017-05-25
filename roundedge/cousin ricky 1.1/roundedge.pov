/* roundedge.pov
 * Persistence of Vision Raytracer scene file
 * POV-Ray Object Collection
 *
 * Demonstration of roundedge.inc functions and macros.
 *
 * Copyright 2008 - 2012 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       17-jul-2008  Created.
 * 1.0   25-aug-2008  Ready for upload.
 *       07-jun-2012  Several aesthetic changes:
 *                     - Fog removed and light source made parallel;
 *                     - Radiosity, lighting, and some textures tweaked;
 *                     - POV logo reworked.
 *       07-jun-2012  Defaults gracefully if Microsoft fonts aren't available.
 *       08-jun-2012  Frame order rearranged to match the user manual;
 *                    elliptical torus place holders temporarily removed.
 *       08-jun-2012  Demo frames added for RE_Corner_join() and
 *                    RE_Round_inside_join().
 * 1.1   09-jun-2012  Uploaded.
 */
//+w800 +h600 declare=Rad=1 +a0.05 +am2 +r3 declare=Soft=5
//+w160 +h120 declare=Rad=1 +a0.05 +am2 +r3 +oroundedge_thumbnail
//+w240 +h180 declare=Rad=1 +a0.05 +am2 +r3 +kff28 +oroundedge_
#version 3.6;

#include "roundedge.inc"
#include "colors.inc"
#include "functions.inc"
#include "textures.inc"
#include "woods.inc"

//----------------------------- DEMO PARAMETERS --------------------------------

#if (clock_on)
   #declare Test = frame_number;
#else#ifndef (Test)
   #declare Test = 0;
#end#end

#ifndef (Rad) #declare Rad = off; #end  //radiosity on/off
#ifndef (MaxG) #declare MaxG = no; #end //test max_gradient by forcing more rays
#ifndef (Soft) #declare Soft = 0; #end  //soft shadows; 1.0 = solar

//Good-looking, but Microsoft proprietary:
#declare s_Bold_font = "arialbd.ttf"
#declare s_Normal_font = "arial.ttf"
#declare s_Var_font = "timesbi.ttf"

//If proprietary fonts aren't available:
#if (!file_exists (s_Bold_font))
  #declare s_Bold_font = "cyrvetic.ttf"
#end
#if (!file_exists (s_Normal_font))
  #declare s_Normal_font = "cyrvetic.ttf"
#end
#if (!file_exists (s_Var_font))
  #declare s_Var_font = "timrom.ttf"
  #declare Shear_font = yes;
#else
  #declare Shear_font = no;
#end

//------------------------------ AN ENVIRONMENT --------------------------------

#ifndef (Debug_ambient) #declare Debug_ambient = no; #end
#ifndef (Debug_angle) #declare Debug_angle = 30; #end
#ifndef (Debug_boom) #declare Debug_boom = 15; #end
#ifndef (Debug_dolly) #declare Debug_dolly = -20; #end
#ifndef (Debug_zoom_out) #declare Debug_zoom_out = 16; #end

#declare Pretrace = 1 / max (image_width, image_height);
global_settings
{ assumed_gamma 1
  #if (Rad)
    radiosity
    { recursion_limit 1
      error_bound 0.5
      pretrace_start 32 * Pretrace
      pretrace_end 2 * Pretrace
      count 200
      brightness 0.5
    }
  #end
  max_trace_level 15
}

#if (Rad) 
  #declare c_Ambience = 0;
  #declare c_Sun = rgb <1.45, 1.4, 1.3>;
#else
  #declare c_Ambience = <0.8, 1.0, 1.4> * 0.1;
  #declare c_Sun = rgb <1.44, 1.4, 1.32>;
#end
#declare v_Sun = <-2, 8, -5> * 1000;
#declare RSun = vlength (v_Sun) / 215;

#default { finish { ambient c_Ambience } }

light_source
{ v_Sun, c_Sun
  parallel point_at 0
  #if (Soft)
    #declare Fuzz = 2 * RSun * Soft;
    area_light x * Fuzz, z * Fuzz, 9, 9
    circular orient adaptive 0
  #end
}

sky_sphere
{ pigment
  { gradient y color_map
    { [0.0 rgb <0.7, 0.8, 0.9>]
      [0.2 rgb <0.5, 0.6, 0.75>]
      [1.0 rgb <0.3, 0.375, 0.6>]
    }
  }
}

plane
{ y, -2.5
  pigment { rgb 0.5 }
  #if (Debug_ambient) finish { ambient 0.8 diffuse 0 } #end
}

camera
{ #if (Debug_angle >= 70) ultra_wide_angle #end
  angle Debug_angle
  location -Debug_zoom_out * z
  rotate <Debug_boom, Debug_dolly, 0>
  look_at 0
  up image_height * y
  right image_width * x
}

//---------------- chess board -------------------

box { -4, <4, -2, 4> pigment { checker rgb 1, rgb 0.05 } }
#declare Side = intersection
{ RE_Box (-<4.25, 2.5, 4.25>, <4.25, -1.95, -4>, 0.05, no)
  box { -y, <6, -3, 6> rotate 135 * y }
  texture
  { T_Wood6
    finish { specular 0.5 roughness 0.01 }
    rotate <-15, 90, 0> scale 0.25
  }
}
object { Side }
object { Side rotate 90 * y }
object { Side rotate 180 * y }
object { Side rotate 270 * y }

//--------------------------------- TEXTURES -----------------------------------

#declare t_Glossy = texture
{ finish { specular 2 roughness 0.0025 reflection { 0 0.4 fresnel } }
}

#declare Vary = array[6]
{ <0.75, 0.5, 1.0>,
  <1.0, 0.4, 0.7>,
  <1.0, 0.55, 0.175>,
  <0.6, 1.0, 0.2>,
  <0.2, 1.0, 0.6>,
  <0.4, 0.7, 1.0>
}
#declare Boost = array[6] { 1, 1, 1.2, 1, 1, 1 }
#declare Choose = mod (Test, 6);
#declare p_Sample = pigment
{ rgb #if (Debug_ambient) 0.5 #else Vary[Choose] #end
}
#declare t_Sample = texture
{ pigment { p_Sample }
  finish
  { specular 0.15 roughness 0.025
    diffuse 0.6 * Boost[Choose] ambient c_Ambience * Boost[Choose]
  }
}

#declare f_Metal_satin = finish
{  reflection { 0.1 metallic }
   diffuse 0.72 ambient c_Ambience * 0.9
   specular 0.6 metallic roughness 0.035
   brilliance 3.5
}
#declare t_Metal_satin = texture { finish { f_Metal_satin } }

#declare f_Metal_shine = finish
{  reflection { 0.5 metallic }
   diffuse 0.4 ambient c_Ambience * 0.5
   specular 1.2 metallic roughness 0.015
   brilliance 6
}
#declare t_Metal_shine = texture { finish { f_Metal_shine } }

#declare f_Metal_chrome = finish
{  reflection { 0.9 metallic }
   diffuse 0.08 ambient c_Ambience * 0.1
   specular 4 roughness 0.001
   brilliance 10
}
#declare t_Max_gradient_test = texture
{ pigment { rgb <0.61, 0.61, 0.64> }
  finish { f_Metal_chrome }
}

//--------------------------------- CONTEXT ------------------------------------

#macro Sticker (Caption, Font, Place, Size, Paint)
  #local Label = text
  { ttf #if (strcmp (Font, "")) Font #else s_Bold_font #end
    Caption 0.025, 0
  }
  object
  { Label
    translate -(max_extent(Label) + min_extent(Label)) / 2
    scale Size
    translate Place
    pigment { color Paint }
    no_shadow
    no_reflection
  }
#end

#macro Coord_label (Caption, Place, Paint)
  object
  { Sticker (Caption, s_Var_font, 0, 0.75, Paint)
    #if (Shear_font) Shear_Trans (x, <0.3, 1, 0>, z) #end
    translate Place
  }
#end

#declare Axis = merge
{ cylinder { -3.5*x, 3.5*x, 0.05 }
  cone { 3.25*x, 0.15, 3.75*x, 0 }
}

#declare Axes = union
{ object { Axis pigment { red 1 transmit 0.5 } }
  object { Axis pigment { green 0.5 transmit 0.5 } rotate 90 * z translate -y }
  object { Axis pigment { blue 1 transmit 0.5 } rotate -90 * y }
  Coord_label ("x", <3.5, 0.5, 0>, red 1 transmit 0.5)
  Coord_label ("y", <0.5, 2.5, 0>, green 0.5 transmit 0.5)
  Coord_label ("-z", <0, -0.3, -3.5>, blue 1 transmit 0.5)
}

#declare Caption = "";

//-------------------------------- SHOWPIECE -----------------------------------

#declare H3 = -0.4;
#declare H2 = -1.2;
#declare H1 = -1.5;
#declare H0 = -2;
#declare rPLAT = 0.05;
#declare R1 = 3.1;
#declare R2 = 2.6;
#declare R3 = 2.3;

//-------------- marble platform -----------------

#declare fn_Wide_ribs = function
{ f_sphere (x, 0, z, R3 - (cos (atan2 (z, x) * 20) + 1) * 0.075)
}
#declare fn_Thin_ribs = function
{ f_sphere (x, 0, z, R3 - 0.325 + pow (cos (atan2 (z, x) * 20) + 1, 2) * 0.075)
}
#declare fn_Column = function
{ 1 - sqrt
  ( RE_fn_Blob2 (fn_Wide_ribs (x, y, z), rPLAT)
  + RE_fn_Blob2 (fn_Thin_ribs (x, y, z), rPLAT)
  )
}

#declare Platform = union
{ RE_Box (<-R1, H0, -R1>, <R1, H1, R1>, rPLAT, no)
  object { RE_Round_join (R2, rPLAT) translate H1 * y }
  RE_Cylinder_end (H2 * y, (H1 + rPLAT) * y, R2, rPLAT, no)
  isosurface
  { function //create a rounded edge using the negative image of a blob
    { sqrt
      ( RE_fn_Blob2 (-fn_Column (x, y, z) * rPLAT, rPLAT)
      + RE_fn_Blob2 (H3 - y, rPLAT)
      ) - 1
    }
    max_gradient 2/rPLAT
    contained_by { box { <-R3, H3 - rPLAT, -R3>, <R3, H3, R3> } }
  }
  isosurface
  { function { fn_Column (x, y, z) }
    max_gradient 2/rPLAT
    contained_by { box { <-R3, H2 + rPLAT, -R3>, <R3, H3 - rPLAT, R3> } }
  }
  isosurface
  { function
    { max
      ( 1 - sqrt
        ( RE_fn_Blob2 (fn_Column (x, y, z) * rPLAT, rPLAT)
        + RE_fn_Blob2 (y - H2, rPLAT)
        ),
        f_sphere (x, 0, z, R3 + rPLAT)
      )
    }
    max_gradient 2/rPLAT
    contained_by { box { <-R3, H2, -R3> - rPLAT, <R3, H2, R3> + rPLAT } }
  }
  texture { t_Glossy pigment { Red_Marble scale 2 translate -0.5 } }
  interior { ior 1.486 } //for calcite; couldn't find marble
}

//------------------ POV logo --------------------

#declare rLOGO1 = 0.075;
#declare rLOGO2 = 0.05;
#declare CRESCENT_ROT = 30;
#declare POVLOGO_ROT = -25;

#declare Crescent_sin = sin (radians (CRESCENT_ROT));
#declare Crescent_cos = cos (radians (CRESCENT_ROT));
#declare PovLogo_sin = sin (radians (POVLOGO_ROT));
#declare PovLogo_cos = cos (radians (POVLOGO_ROT));

#declare fn_Logo_cone = function
{ f_sphere (x, 0, z, (y + 4) / 6)
}

#declare fn_Logo_crescent = function //create rounded edge with negative image of blob
{ sqrt
  ( RE_fn_Blob2 (-f_sphere (x / 2.6, y / 2.2, z / 1.038, 1), rLOGO2)
  + RE_fn_Blob2 (f_sphere ((x + 0.328) / 2.249, y / 1.778, z / 2.076,  1), rLOGO2)
  ) - 1
}

#declare Povument = union
{ sphere { 2*y, 1 }
  cone { -4*y, 0, -0.42*y, 179/300 }
  isosurface //top of cone
  { function //create a rounded edge using the negative image of a blob
    { sqrt
      ( RE_fn_Blob2 (-fn_Logo_cone (x, y, z), rLOGO1)
      + RE_fn_Blob2 (f_sphere (x, y - 2, z/2, 1.391), rLOGO1)
      ) - 1
    }
    max_gradient 1/rLOGO1
    contained_by { box { <-0.81, 0.5, -0.81>, <0.81, 0.84, 0.81> } }
  }
  isosurface //crescent
  { function { fn_Logo_crescent (x, y, z) }
    max_gradient 1/rLOGO2
    contained_by { box { -<2.42, 2.2, 0.73>, <2.6, 2.2, 0.73> } }
    rotate CRESCENT_ROT * z translate 2*y
  }
  isosurface //join cone & crescent
  { function
    { 1 - sqrt
      ( RE_fn_Blob2 (fn_Logo_cone (x, y, z), rLOGO1)
      + RE_fn_Blob2
        ( fn_Logo_crescent
          ( (y - 2) * Crescent_sin + x * Crescent_cos,
            (y - 2) * Crescent_cos - x * Crescent_sin,
            z
          ) * rLOGO2,
          rLOGO2
        )
      )
    }
    max_gradient 1/rLOGO2
    contained_by { box { -<0.75, 0.42, 0.75>, <0.82, 0.5, 0.75> } }
  }
  rotate POVLOGO_ROT * z
  translate <-0.5, 4 * PovLogo_cos, 0>
  texture { t_Metal_shine pigment { rgb <0.2, 0.4, 0.8> } }
}

//----------------- screw head -------------------

#declare rSCREW = 1;
#declare YSLOT = 3;
#declare Rot45 = sqrt(0.5);

#declare fn_Slot = function
{ f_sphere (max (y*Rot45 + x*Rot45, 0), max (y*Rot45 - x*Rot45, 0), z, 1)
}

#declare Screw_head = union
{ isosurface
  { function //create a rounded edge using the negative image of a blob
    { sqrt
      ( RE_fn_Blob2 (fn_Slot (x, YSLOT - y, z), rSCREW)
      + RE_fn_Blob2 (fn_Slot (z, YSLOT - y, x), rSCREW)
      + RE_fn_Blob2 (-RE_fn_Wheel (x, y - 1, z, 2, 6), rSCREW)
      - RE_fn_Blob2 (f_sphere (x, y - YSLOT, z, 1), rSCREW)
      ) - 1
    }
    max_gradient 1.3/rSCREW
    contained_by { box { <-8, 1, -8>, <8, 7, 8> } }
  }
  torus { 7, 1 translate y }
  texture { t_Metal_shine pigment { rgb <0.66, 0.72, 0.72> } }
  rotate 123.456 * y //randomish
  scale 1/32
}

//----------------- metal base -------------------

#declare HHOLD = 1;
#declare THIN = 0.035;
#declare RHOLD = HHOLD / 6 + THIN;
#declare rTHIN = THIN * 6 / (5 + sqrt(37));

#declare Holder = union
{ object
  { RE_Washer_end ((HHOLD - 4) * y, -4 * y, RHOLD, RHOLD - 2*rTHIN, rTHIN, no)
    rotate POVLOGO_ROT * z
    translate <-0.5, 4 * PovLogo_cos, 0>
  }
//A valid boundary case that would crash Round_Cylinder()
  RE_Cylinder (0, 2*rTHIN * y, 3.5, rTHIN, no)
  object
  { RE_Round_join (RHOLD, 0.1)
    Shear_Trans (x / PovLogo_cos, <-PovLogo_sin, PovLogo_cos, 0>, z)
    translate <(4 - 2*rTHIN) * PovLogo_sin - 0.5, 2*rTHIN, 0>
  }
  object { Screw_head translate 3 * x }
  object { Screw_head translate 3 * x rotate 120 * y }
  object { Screw_head translate 3 * x rotate -120 * y }
  texture { t_Metal_shine pigment { rgb <0.61, 0.59, 0.54> } }
}

//------------------------------- DEMO SAMPLES ---------------------------------

#declare Dashed_line = cylinder
{ 0, x, 1 scale <20, 0.025, RE_ABIT>
  pigment
  { gradient x color_map 
    { [0.3 rgb 0 transmit 0.6] [0.3 rgbt 1]
      [0.7 rgbt 1] [0.7 rgb 0 transmit 0.6]
    }
  }
}

#macro Show_minimal (Obj, Name)
  union
  { intersection
    { object { Obj }
      box { -3, 3 * z }
      texture { t_Metal_satin pigment { p_Sample } }
      translate -RE_ABIT * z
    }
    RE_Box_x_up (<-4, -4, -2>, <3, -1, 2>, 1, no)
    RE_Box_y_right (<-4, -2, -2>, <-1, 2, 2>, 1, no)
    object { Dashed_line scale <0.35, 1, 1> translate <-4, -2, -2 - RE_ABIT> }
    object { Dashed_line scale <0.35, 1, 1>
                         rotate -90 * z translate <-2, 2, -2 - RE_ABIT> }
    Sticker (Name, "", <-0.5, -3.4, -2>, 0.6, 0)
    translate 0.5 * x
    scale 0.75
    translate y
  }
#end

#macro Show_sect (Obj, Size)
  #local Fit = 3 / (Size + 1);
  union
  { difference
    { object { Obj }
      box { -3 * z, Size }
    }
    intersection
    { object { Obj }
      box { -3 * z, Size }
      translate <1.25, 0.25, 1>
    }
    scale Fit
    translate (Fit * Size - 2) * y
  }
#end

//--------------------------------------

#switch (Test)

  #case (1)
    #declare V_ORIGIN = <-0.8, -0.2, 0.5>;
    #declare rBLOB = 0.8;
    #declare Sample = union
    { difference
      { box { -2, 2 }
        box { V_ORIGIN, <2, 2, -2> * RE_MORE }
      }
      object { RE_Corner_join (rBLOB) rotate 90 * y translate V_ORIGIN }
      rotate 30 * y
      translate z
    }
    #declare Caption = "RE_Corner_join"
    #break

  #case (2)
    #declare RPOST = 0.7;
    #declare rBLOB = 0.4;
    #declare Sample = union
    { box { -2, <2, -1, 2> }
      cylinder { -y, 2 * y, RPOST translate -0.5 * x }
      object { RE_Round_join (RPOST, rBLOB) translate <-0.5, -1, 0> }
      object { RE_Round_join (RPOST, rBLOB) translate <1.75, 0.5, 0> }
      Sticker ("RE_Round_join", "", <0, -1.5, -2>, 0.45, 0)
    }
    #break

  #case (3)
    #declare RHOLLOW = 1.25;
    #declare rBLOB = 0.4;
    #declare Sample = union
    { intersection
      { union
        { difference
          { box { -<1.75, 0, 2>, <1.75, 3, 2> }
            cylinder { -0.1 * y, 3.1 * y, RHOLLOW }
          }
          RE_Round_inside_join (RHOLLOW, rBLOB)
        }
        plane { -z, 0 }
        translate <-1.25, -1, 0>
      }
      box { -<3, 2, 2>, <3, -1, 2> }
      object { RE_Round_inside_join (RHOLLOW, rBLOB) translate <2.5, 0.5, 0> }
      Sticker ("RE_Round_inside_join", "", <0, -1.5, -2>, 0.45, 0)
    }
    #break

  #case (4)
    #declare V_ORIGIN = <-0.8, -0.2, 0.5>;
    #declare rBLOB = 0.8;
    #declare Sample = union
    { union
      { difference
        { box { -2, 2 }
          box { V_ORIGIN, <2, 2, -2> * RE_MORE }
        }
        RE_Straight_join_x (V_ORIGIN, 2, rBLOB, -90)
        RE_Straight_join_y (V_ORIGIN, 2, rBLOB, 90)
        RE_Straight_join_z (V_ORIGIN, -2, rBLOB, 0)
        rotate 30 * y
        translate z
      }
      RE_Straight_join_x (-2, 2, rBLOB, -90)
    }
    #declare Caption = "RE_Straight_join_*"
    #break

  #case (5)
    #declare R = 0.4;
    #declare AMP = 2;
    #declare WLEN = 6;
    #declare H = 8 * AMP / pow (WLEN, 2);
    #declare Side = WLEN/4;
    #declare Bob = AMP/2;
    #declare Sample = union
    { intersection
      { RE_Parabolic_torus (H, R)
        box { <-Side, -R, -R>, <Side, Bob + R, R> }
        translate <Side, Bob, 0>
      }
      intersection
      { RE_Parabolic_torus (H, R)
        box { <-Side, 0, -R>, <Side, Bob + R, R> }
        translate <Side, -Bob, 0>
      }
      intersection
      { quadric { -H * x, 0, y, 0 }
        box { <-Side, -2, -R>, <Side, Bob, R> }
        translate <Side, -Bob, 0>
      }
      intersection
      { RE_Parabolic_torus (-H, R)
        box { <-Side, -Bob, -R>, <Side, R, R> }
        translate <-Side, Bob, 0>
      }
      intersection
      { quadric { H * x, 0, y, 0 }
        box { <-Side, -2 - Bob, -R>, <Side, 0, R> }
        translate <-Side, Bob, 0>
      }
      Sticker ("RE_Parabolic_torus", "", <0, -1.4, -R>, 0.5, 0)
    }
    #break

  #case (6)
    #declare Sample = RE_Cylinder (2*y, -2*y, 2, 0.4, no)
    #declare Caption = "RE_Cylinder"
    #break

  #case (7)
    #declare Sample = RE_Cylinder_end (-2*y, 2*y, 2, 0.4, no)
    #declare Caption = "RE_Cylinder_end"
    #break

  #case (8)
    #declare Sample = Show_sect (RE_Hole (-2 * z, 2 * z, 3, 1, 1, no), 3)
    #declare Caption = "RE_Hole"
    #break

  #case (9)
    #declare Sample = Show_sect (RE_Hole_end (-2 * z, 2 * z, 3, 1, 1, no), 3)
    #declare Caption = "RE_Hole_end"
    #break

  #case (10)
    #declare Sample = Show_minimal
      (RE_Hole_minimal (-2 * z, 2 * z, 1, 1, no), "RE_Hole_minimal")
    #break

  #case (11)
    #declare Sample = Show_minimal
      (RE_Hole_end_minimal (-2 * z, 2 * z, 1, 1, no), "RE_Hole_end_minimal")
    #break

  #case (12)
    #declare Sample = Show_sect (RE_Washer (-2 * z, 2 * z, 4, 1, 1, no), 4)
    #declare Caption = "RE_Washer"
    #break

  #case (13)
    #declare Sample = Show_sect (RE_Washer_end (-2 * z, 2 * z, 4, 1, 1, no), 4)
    #declare Caption = "RE_Washer_end"
    #break

  #case (14)
    #declare Sample = union
    { RE_Box (-2, 2, 0.6, no)
      Sticker ("RE_Box", "", -2*z, 0.45, 0)
    }
    #break

  #case (15)
    #declare Sample = union
    { object { Axes }
      RE_Box_x (<-2, -2, -1>, <2, 0, 1>, 0.6, no)
      RE_Box_y (<0, 0, -1>, <3, 2, 1>, 0.6, no)
      RE_Box_z (<-3, 0, -1>, <0, 2, 1>, 0.6, no)
      Sticker ("RE_Box_x", "", <0.25, -1, -1>, 0.425, 0)
      Sticker ("RE_Box_y", "", <1.5, 1, -1>, 0.425, 0)
      Sticker ("RE_Box_z", "", <-1.5, 1, -1>, 0.425, 0)
    }
    #break

  #case (16)
    #declare Sample = union
    { object { Axes }
      RE_Box_left (<-2.5, 0, -1>, <2.5, 2, 1>, 0.6, no)
      RE_Box_right (<-2.5, -2, -1>, <2.5, 0, 1>, 0.6, no)
      Sticker ("RE_Box_left", "", <-0.6, 1, -1>, 0.45, 0)
      Sticker ("RE_Box_right", "", <0.5, -1, -1>, 0.45, 0)
    }
    #break

  #case (17)
    #declare Sample = union
    { object { Axes }
      RE_Box_up (<-2.5, -2, -1>, <0, 2, 1>, 0.6, no)
      RE_Box_down (<0, -2, -1>, <2.5, 2, 1>, 0.6, no)
      object { Sticker ("RE_Box_up", "", <0.25, 1.25, -1>, 0.45, 0) rotate 90 * z }
      object { Sticker ("RE_Box_down", "", <0, 1.25, -1>, 0.45, 0) rotate -90 * z }
    }
    #break

  #case (18)
    #declare Sample = union
    { object { Axes }
      RE_Box_near (<-1, -2, -2>, <1, 0, 2>, 0.6, no)
      RE_Box_far (<-1, 0, -2>, <1, 2, 2>, 0.6, no)
      object { Sticker ("RE_Box_near", "", -<0.2, 1, 1>, 0.45, 0) rotate -90 * y }
      object { Sticker ("RE_Box_far", "", <0.2, 1, -1>, 0.45, 0) rotate -90 * y }
      rotate 45 * y
    }
    #break

  #case (19)
    #declare Sample = union
    { object { Axes }
      RE_Box_x_near (<-1, 0.05, -2.95>, <1, 2, -0.05>, 0.6, no)
      RE_Box_x_up (<-1, 0.05, 0.05>, <1, 2, 2.95>, 0.6, no)
      RE_Box_x_far (<-1, -2, 0.05>, <1, -0.05, 2.95>, 0.6, no)
      RE_Box_x_down (<-1, -2, -2.95>, <1, -0.05, -0.05>, 0.6, no)
      union
      { Sticker ("RE_Box_x_near", "", <-1.3, 0.75, -1>, 0.4, 0)
        Sticker ("RE_Box_x_up", "", <1.5, 1.25, -1>, 0.4, 0)
        Sticker ("RE_Box_x_far", "", <1.5, -1.25, -1>, 0.4, 0)
        Sticker ("RE_Box_x_down", "", <-1.3, -0.75, -1>, 0.4, 0)
        rotate -90 * y
      }
      rotate 45 * y
    }
    #break

  #case (20)
    #declare c_Ink = rgb 1;
    #declare x_Tilt = transform { rotate -25 * x }
    #declare v_Tilted = vtransform (<0, 2, 1>, transform { x_Tilt });
    #declare Sample = union
    { object { Axes }
      RE_Box_y_right (<-3, -2, -1>, <-1.56, 2, 1>, 0.5, no)
      RE_Box_y_near (<-1.48, -2, -1>, <-0.04, 2, 1>, 0.5, no)
      RE_Box_y_far (<0.04, -2, -1>, <1.48, 2, 1>, 0.5, no)
      RE_Box_y_left (<1.56, -2, -1>, <3, 2, 1>, 0.5, no)
      #declare f_Save = finish {}
      #default { finish { ambient 0.4 } }
      union
      { Sticker ("RE_Box_y_right", s_Normal_font, <0, 2.28, -1>, 0.5, c_Ink)
        Sticker ("RE_Box_y_near", s_Normal_font, <0, 0.76, -1>, 0.5, c_Ink)
        Sticker ("RE_Box_y_far", s_Normal_font, <0, -0.76, -1>, 0.5, c_Ink)
        Sticker ("RE_Box_y_left", s_Normal_font, <0, -2.28, -1>, 0.5, c_Ink)
        rotate 90 * z
      }
      #default { finish { f_Save } }
      transform { x_Tilt }
      translate (v_Tilted.y - 2) * y
    }
    #break

  #case (21)
    #declare Sample = union
    { object { Axes }
      RE_Box_z_up (<-2.95, 0.05, -1>, <-0.05, 2, 1>, 0.6, no)
      RE_Box_z_right (<0.05, 0.05, -1>, <2.95, 2, 1>, 0.6, no)
      RE_Box_z_down (<0.05, -2, -1>, <2.95, -0.05, 1>, 0.6, no)
      RE_Box_z_left (<-2.95, -2, -1>, <-0.05, -0.05, 1>, 0.6, no)
      Sticker ("RE_Box_z_up", "", <-1.5, 1.25, -1>, 0.4, 0)
      Sticker ("RE_Box_z_right", "", <1.3, 0.75, -1>, 0.4, 0)
      Sticker ("RE_Box_z_down", "", <1.3, -1.25, -1>, 0.4, 0)
      Sticker ("RE_Box_z_left", "", <-1.5, -0.75, -1>, 0.4, 0)
    }
    #break

  #case (22)
    #declare Sample = isosurface
    { function
      { 1 - RE_fn_Blob (abs(x) + abs(z) - 1, 0.3)
          - RE_fn_Blob (f_sphere (0, y, z, 0.8), 0.2)
      }
      max_gradient 4 / 0.2
      contained_by { box { -<2.5, 2, 1>, <2.5, 2, 1> } }
    }
    #declare Caption = "RE_fn_Blob"
    #break

  #case (23)
    #declare Sample = isosurface
    { function
      { 1 - sqrt
        ( RE_fn_Blob2 (abs(x) + abs(z) - 1, 0.3)
        + RE_fn_Blob2 (f_sphere (0, y, z, 0.8), 0.2)
        )
      }
      max_gradient 1.3 / 0.2
      contained_by { box { -<2.5, 2, 1>, <2.5, 2, 1> } }
    }
    #declare Caption = "RE_fn_Blob2"
    #break

  #case (24)
    #declare R = 0.75;
    #declare RIN = 1;
    #declare ROUT = 2.5;
    #declare EDGE = 0.3;
    #declare TOP = 2;
    #declare Side = union
    { cylinder { <RIN + R, TOP, 0>, <RIN + R, 0, 0>, R }
      box { <RIN + R, -RIN, -R>, <ROUT, TOP, R> }
      RE_Straight_join_x (<RIN + R, -RIN, R>, ROUT, EDGE, 0)
      RE_Straight_join_x (<RIN + R, -RIN, -R>, ROUT, EDGE, -90)
    }
    #declare Join = isosurface
    { function
      { 1 - sqrt
        ( RE_fn_Blob2 (RE_fn_Hole (x, z, y, RIN + R, R), EDGE)
        + RE_fn_Blob2 (y + RIN, EDGE)
        //Note: be careful with negative blobs; they can easily blow the max_gradient.
        - RE_fn_Blob2 (f_sphere (x, y + RIN + R, z, R), EDGE)
        )
      }
      max_gradient 1.42/EDGE
      contained_by { box { -<0, RIN, R + EDGE>, <RIN + R, EDGE - RIN, R + EDGE> } }
    }
    #declare Sample = union
    { RE_Box_down (-ROUT, <ROUT, -RIN, ROUT>, 0.05, no)
      intersection
      { RE_Hole_minimal (-R * z, R * z, RIN, R, no)
        plane { y, 0 }
      }
      object { Join texture { t_Metal_satin pigment { rgb <0.8, 0.35, 0.2> } } }
      object { Join scale <-1, 1, 1> }
      object { Side }
      object { Side scale <-1, 1, 1> }
      Sticker ("RE_fn_Hole", "", <0, -1.45, -ROUT>, 0.45, 0)
      Sticker ("with RE_fn_Blob2", "", <0, -2, -ROUT>, 0.375, 0)
      translate (ROUT - 2) * y
    }
    #break

  #case (25)
    #declare R = 0.4;
    #declare AMP = 2;
    #declare WLEN = 6;
    #declare H = 8 * AMP / pow (WLEN, 2);
    #declare Side = WLEN/4;
    #declare Bob = AMP/2;
    #declare Sample = union
    { isosurface
      { function { RE_fn_Parabolic_torus (x - Side, y - Bob, z, H, R) }
        max_gradient 1.7
        contained_by { box { <0, Bob - R, -R>, <WLEN/2, 2*Bob + R, R> } }
      }
      isosurface
      { function { RE_fn_Parabolic_torus (x - Side, y + Bob, z, H, R) }
        max_gradient 1.7
        contained_by { box { <0, -Bob, -R>, <WLEN/2, R, R> } }
      }
      isosurface
      { function { RE_fn_Parabolic_torus (x + Side, y - Bob, z, -H, R) }
        max_gradient 1.7
        contained_by { box { <-WLEN/2, 0, -R>, <0, R + Bob, R> } }
      }
      intersection
      { quadric { -H * x, 0, y, 0 }
        box { <-Side, -2, -R>, <Side, Bob, R> }
        translate <Side, -Bob, 0>
      }
      intersection
      { quadric { H * x, 0, y, 0 }
        box { <-Side, -2 - Bob, -R>, <Side, 0, R> }
        translate <-Side, Bob, 0>
      }
      Sticker ("RE_fn_Parabolic_torus", "", <0, -1.4, -R>, 0.5, 0)
    }
    #break

  #case (26)
    #declare R = 0.4;
    #declare ROUT = 2.75;
    #declare BLOBBY= 0.6;
    #declare Effect = R + sqrt (pow (BLOBBY + R, 2) - pow (BLOBBY + R - BLOBBY/sqrt(2), 2));
    #declare End_blob = isosurface
    { function
      { 1 - sqrt
        ( RE_fn_Blob2 (RE_fn_Wheel (x, z, y, ROUT - R, R), BLOBBY)
        + RE_fn_Blob2 (RE_fn_Wheel (x, y, z, ROUT - R, R), BLOBBY)
        //Note: be careful with negative blobs; they can easily blow the max_gradient.
        - RE_fn_Blob2 (f_sphere (x + R - ROUT, y, z, R), BLOBBY)
        )
      }
      max_gradient 1.42 / BLOBBY
      accuracy 0.00001
      contained_by
      { box { <ROUT - Effect, 0, -R - BLOBBY>, <ROUT, R + BLOBBY, R + BLOBBY> }
      }
    }
    #declare Sample = union
    { RE_Cylinder (R*y, (ROUT - 4) * y, ROUT, R, no)
      RE_Cylinder (-R*z, R*z, ROUT, R, no)
      RE_Straight_join_x (<ROUT - Effect, R, -R>, Effect - ROUT, BLOBBY, -90)
      RE_Straight_join_x (<ROUT - Effect, R, R>, Effect - ROUT, BLOBBY, 0)
      object 
      { End_blob
        texture { t_Metal_satin pigment { rgb <0.1, 0.3, 0.5> } }
      }
      object { End_blob rotate 180 * y }
      Sticker ("RE_fn_Wheel", "", <0, 1.7, -R>, 0.475, 0)
      Sticker ("with RE_fn_Blob2", "", <0, 1.2, -R>, 0.4, 0)
      translate <0, 2 - ROUT, 0>
    }
    #break

  #case (27)
    #declare R = 0.4;
    #declare RBlob = RE_fn_Blob_distance (1.5, 4);
    #declare Sample = union
    { blob
      { sphere { 0, 1.5, 4 }
        cylinder { 0, <1.5, 2.5, 0>, 0.8, 4 }
      }
      difference
      { RE_Washer_end (R * y, -RBlob * y, 2, RBlob, R, no)
        box { <0, R * RE_MORE, 0>, <3, -3, -3> }
      }
      RE_Cylinder_end (-2 * y, -RBlob * y, 2, R, no)
    }
    #declare Caption = "RE_fn_Blob_distance"
    #break

  #case (28)
    #declare RMAJOR = 1.3;
    #declare rMINOR = 0.7;
    #declare v_Signage = transform { rotate <Debug_boom, Debug_dolly, 0> }
    #declare Sample = union
    { intersection
      { torus { RMAJOR, rMINOR rotate 90 * x }
        plane { y, 0 }
      }
      blob //radius of spheres to match minor radius of torus
      { sphere { -RMAJOR * x, RE_fn_Blob_radius (rMINOR, 2), 2 }
        sphere { RMAJOR * x, 1.2, RE_fn_Blob_strength (rMINOR, 1.2) }
        cylinder { <-0.5, 1.5, 0>, <0.5, 1.5, 0>, 1.3, 2.3 }
      }
      union
      { Sticker ("RE_fn_Blob_radius", "", <-1.5, 2.25, -2>, 0.425, 0)
        Sticker ("RE_fn_Blob_strength", "", <1.3, 1.45, -2>, 0.425, 0)
        transform { v_Signage }
      }
      union
      { cone { <-RMAJOR, 0, -rMINOR>, 0.01,
               vtransform (<-2, 1.9, -2>, transform { v_Signage }), 0.05 }
        cone { <RMAJOR, 0, -rMINOR>, 0.01,
               vtransform (<1.8, 1.1, -2>, transform { v_Signage }), 0.05 }
        pigment { rgb 0 }
        no_shadow
        no_reflection
      }
    }
    #break

  //cmd:declare=Test=99 declare=MaxG=1
  //(Shhhh!!!)
  #range (90, 99)
    #declare Sample = RE_Cylinder (sqrt(4/3), -sqrt(4/3), 2, 2, no)
    #break

  #else
    #declare Sample = union
    { object { Platform }
      union
      { object { Povument }
        object { Holder }
        scale 0.4
        translate H3 * y
      }
    }

#end

//--------------------------------- DISPLAY ------------------------------------

object
{ Sample
  texture { #if (MaxG) t_Max_gradient_test #else t_Sample #end }
  //Actually, just turning on radiosity does a better job of finding the
  //max gradient, but chrome is still fun.
}

#if (strcmp (Caption, ""))
  #declare Word = Sticker (Caption, "", 0, 0.375, 0)
  union
  { object { Word }
    box
    { min_extent (Word), max_extent (Word)
      scale <1.1, 1.4, 1>
      translate max_extent (Word) * z
      pigment { rgb 1 transmit 0.7 }
      finish { ambient 0.4 }
    }
    no_shadow
    no_reflection
    translate <0, -0.1, -4> rotate <0, Debug_dolly, 0>
  }
#end
