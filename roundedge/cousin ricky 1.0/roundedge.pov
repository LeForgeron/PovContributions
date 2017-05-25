/* roundedge.pov
 *
 * Demonstration of roundedge.inc functions and macros.
 *
 * Copyright 2008 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 * Created 17-jul-2008
 * Updated 25-aug-2008
 */
//+w800 +h600 declare=Rad=1 +a0.05 +am2 +r3 declare=Soft=5
//+w160 +h120 declare=Rad=1 +a0.05 +am2 +r3 +oroundedge_thumbnail
//+w240 +h180 declare=Rad=1 +a0.05 +am2 +r3 +kff28 +oroundedge_

#include "roundedge.inc"
#include "colors.inc"
#include "woods.inc"

//----------------------------- DEMO PARAMETERS --------------------------------

#if (clock_on)
   #declare Test = frame_number;
#else#ifndef (Test)
   #declare Test = 0;
#end#end

#ifndef (Rad) #declare Rad = off; #end  //radiosity on/off
#ifndef (MaxG) #declare MaxG = no; #end //test max_gradient by forcing more rays
#ifndef (Soft) #declare Soft = 0; #end  //soft shadows. 1.0 = solar

//------------------------------ AN ENVIRONMENT --------------------------------

#ifndef (Debug_ambient) #declare Debug_ambient = no; #end
#ifndef (Debug_angle) #declare Debug_angle = 30; #end
#ifndef (Debug_boom) #declare Debug_boom = 15; #end
#ifndef (Debug_dolly) #declare Debug_dolly = -20; #end
#ifndef (Debug_zoom_out) #declare Debug_zoom_out = 16; #end

global_settings
{  assumed_gamma 1
   #if (Rad)
      radiosity
      {  recursion_limit 1
         error_bound 0.5
         pretrace_end 0.01
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
#declare v_Sun = <-2, 7, -5> * 1000;
#declare RSun = vlength (v_Sun) / 215;

#default {  finish { ambient c_Ambience } }

light_source
{  v_Sun, c_Sun
   #if (Soft)
      #declare Fuzz = 2 * RSun * Soft;
      area_light x * Fuzz, z * Fuzz, 9, 9
      circular orient adaptive 0
   #end
}

sky_sphere
{  pigment
   {  gradient y color_map
      {  [0.0 rgb <0.7, 0.8, 0.9>]
         [0.2 rgb <0.5, 0.6, 0.75>]
         [1.0 rgb <0.3, 0.375, 0.6>]
      }
   }
}
fog
{  fog_type 2
   distance 1000
   color rgb <0.7, 0.8, 0.9>
   fog_offset 0
   fog_alt 100
}

plane
{  y, -2.5
   pigment { rgb 0.5 }
   #if (Debug_ambient) finish { ambient 0.8 diffuse 0 } #end
}

box { -4, <4, -2, 4> pigment { checker rgb 1, rgb 0.05 } }
#declare Side = intersection
{  RE_Box (-<4.25, 2.5, 4.25>, <4.25, -1.95, -4>, 0.05, no)
   box { -y, <6, -3, 6> rotate 135 * y }
   texture
   {  T_Wood6
      finish { specular 0.5 roughness 0.01 }
      rotate <-15, 90, 0> scale 0.25
   }
}
object { Side }
object { Side rotate 90 * y }
object { Side rotate 180 * y }
object { Side rotate 270 * y }

camera
{  #if (Debug_angle >= 70) ultra_wide_angle #end
   angle Debug_angle
   location -Debug_zoom_out * z
   rotate <Debug_boom, Debug_dolly, 0>
   look_at 0
   up image_height * y
   right image_width * x
}

//--------------------------------- TEXTURES -----------------------------------

#declare t_Glossy = texture
{  finish { specular 2 roughness 0.0025 reflection { 0 0.4 fresnel } }
}

#declare Vary = array[6]
{  <0.75, 0.5, 1.0>,
   <1.0, 0.4, 0.7>,
   <1.0, 0.55, 0.175>,
   <0.6, 1.0, 0.2>,
   <0.2, 1.0, 0.6>,
   <0.4, 0.7, 1.0>
}
#declare Boost = array[6] { 1, 1, 1.2, 1, 1, 1 }
#declare Choose = mod (Test, 6);
#declare p_Sample = pigment { rgb #if (Debug_ambient) 0.5 #else Vary[Choose] #end }
#declare t_Sample = texture
{  pigment { p_Sample }
   finish
   {  specular 0.25 roughness 0.025
      diffuse 0.6 * Boost[Choose] ambient c_Ambience * Boost[Choose]
   }
}

#declare f_Metal_satin = finish
{  reflection { 0.1 metallic }
   diffuse 0.72 ambient c_Ambience * 0.9
   specular 1 metallic roughness 0.035
   brilliance 3.5
}
#declare t_Metal_satin = texture { finish { f_Metal_satin } }

#declare f_Metal_shine = finish
{  reflection { 0.5 metallic }
   diffuse 0.4 ambient c_Ambience * 0.5
   specular 1.5 metallic roughness 0.015
   brilliance 6
}
#declare t_Metal_shine = texture { finish { f_Metal_shine } }

#declare f_Metal_chrome = finish
{  reflection { 0.8 metallic }
   diffuse 0.16 ambient c_Ambience * 0.2
   specular 4 roughness 0.002
   brilliance 10
}
#declare t_Max_gradient_test = texture
{  pigment { rgb <0.61, 0.61, 0.65> }
   finish { f_Metal_chrome }
}

//--------------------------------- CONTEXT ------------------------------------

#macro Sticker (Caption, Font, Place, Size, Paint)
   #local Label = text
   {  ttf #if (strcmp (Font, "")) Font #else "arialbd.ttf" #end
      //font is a sans-serif bold. Non-Windows users change font to taste.
      Caption 0.025, 0
   }
   object
   {  Label
      translate -(max_extent(Label) + min_extent(Label)) / 2
      scale Size
      translate Place
      pigment { color Paint }
      no_shadow
   }
#end

#declare Axis = merge
{  cylinder { -3.5*x, 3.5*x, 0.05 }
   cone { 3.25*x, 0.15, 3.75*x, 0 }
}

#declare Axes = union
{  object { Axis pigment { rgb x transmit 0.5 } }
   object { Axis pigment { rgb y/2 transmit 0.5 } rotate 90 * z translate -y }
   object { Axis pigment { rgb z transmit 0.5 } rotate -90 * y }
   Sticker ("x", "timesbi.ttf", <3.5, 0.5, 0>, 0.75, rgb x transmit 0.5)
   Sticker ("y", "timesbi.ttf", <0.5, 2.5, 0>, 0.75, rgb y/2 transmit 0.5)
   Sticker ("-z", "timesbi.ttf", <0, -0.3, -3.5>, 0.75, rgb z transmit 0.5)
   //font is a serif bold italic. Non-Windows users change font to taste.
}

#declare Caption = "";

//-------------------------------- SHOWPIECE -----------------------------------

#include "textures.inc"

#declare H3 = -0.4;
#declare H2 = -1.2;
#declare H1 = -1.5;
#declare H0 = -2;
#declare rPlat = 0.05;
#declare R1 = 3.1;
#declare R2 = 2.6;
#declare R3 = 2.3;

#declare fn_Wide_ribs = function
{  f_sphere (x, 0, z, R3 - (cos (atan2 (z, x) * 20) + 1) * 0.075)
}
#declare fn_Thin_ribs = function
{  f_sphere (x, 0, z, R3 - 0.325 + pow (cos (atan2 (z, x) * 20) + 1, 2) * 0.075)
}
#declare fn_Column = function
{  1 - sqrt
   (  RE_fn_Blob2 (fn_Wide_ribs (x, y, z), rPlat)
    + RE_fn_Blob2 (fn_Thin_ribs (x, y, z), rPlat)
   )
}

#declare Platform = union
{  RE_Box (<-R1, H0, -R1>, <R1, H1, R1>, rPlat, no)
   object { RE_Round_join (R2, rPlat) translate H1 * y }
   RE_Cylinder_end (H2 * y, (H1 + rPlat) * y, R2, rPlat, no)
   isosurface
   {  function //create a rounded edge using the negative image of a blob
      {  sqrt
         (  RE_fn_Blob2 (-fn_Column (x, y, z) * rPlat, rPlat)
          + RE_fn_Blob2 (H3 - y, rPlat)
         ) - 1
      }
      max_gradient 2/rPlat
      contained_by { box { <-R3, H3 - rPlat, -R3>, <R3, H3, R3> } }
   }
   isosurface
   {  function { fn_Column (x, y, z) }
      max_gradient 2/rPlat
      contained_by { box { <-R3, H2 + rPlat, -R3>, <R3, H3 - rPlat, R3> } }
   }
   isosurface
   {  function
      {  max
         (  1 - sqrt
            (  RE_fn_Blob2 (fn_Column (x, y, z) * rPlat, rPlat)
             + RE_fn_Blob2 (y - H2, rPlat)
            ),
            f_sphere (x, 0, z, R3 + rPlat)
         )
      }
      max_gradient 2/rPlat
      contained_by { box { <-R3, H2, -R3> - rPlat, <R3, H2, R3> + rPlat } }
   }
   texture { t_Glossy pigment { Red_Marble scale 2 translate -0.5 } }
   interior { ior 1.486 } //for calcite; couldn't find marble
}

//------------------

#declare rLogo = 0.1;
#declare rAdj = 1.5;

#declare fn_Crescent = function //create rounded edge with negative image of blob
{  sqrt
   (  RE_fn_Blob2 (-f_sphere (x / 2.6, y / 2.2, z, 1) * rAdj, rLogo)
    + RE_fn_Blob2 (f_sphere ((x + 0.34) / 2.22, y / 1.74, z / 2, 1) * rAdj, rLogo)
   ) - 1
}

#declare fn_Cone = function
{  f_sphere (x, 0, z, (y + 4) / 6)
}

#declare CrRot = 30;
#declare CrSin = sin (radians (CrRot));
#declare CrCos = cos (radians (CrRot));
#declare PovRot = -25;
#declare PovSin = sin (radians (PovRot));
#declare PovCos = cos (radians (PovRot));

#declare Povument = union
{  sphere { 2*y, 1 }
   cone { -4*y, 0, -0.5*y, 7/12 }
   isosurface
   {  function //create a rounded edge using the negative image of a blob
      {  sqrt
         (  RE_fn_Blob2 (-fn_Cone (x, y, z), rLogo)
          + RE_fn_Blob2 (f_sphere (x, y - 2, z/2, 1.37), rLogo)
         ) - 1
      }
      max_gradient 1/rLogo
      contained_by { box { <-0.85, 0.55, -0.85>, 0.85 } }
   }
   isosurface
   {  function { fn_Crescent (x, y, z) }
      max_gradient rAdj / rLogo
      contained_by { box { -<2.6, 2.2, 1>, <2.6, 2.2, 1> } }
      rotate z*30 translate 2*y
   }
   isosurface
   {  function
      {  1 - sqrt
         (  RE_fn_Blob2 (fn_Cone (x, y, z), rLogo)
          + RE_fn_Blob2
            (  fn_Crescent ((y - 2) * CrSin + x * CrCos,
                            (y - 2) * CrCos - x * CrSin, z) * rLogo,
               rLogo
            )
         )
      }
      max_gradient rAdj / rLogo
      contained_by { box { -<0.85, 0.5, 0.85>, <0.85, 0.55, 0.85> } }
   }
   rotate PovRot * z
   translate <-0.5, 4 * PovCos, 0>
   texture { t_Metal_shine pigment { rgb <0.2, 0.4, 0.8> } }
}

//------------------

#declare rScrew = 1;
#declare ySlot = 3;
#declare Rot45 = sqrt(0.5);

#declare fn_Slot = function
{  f_sphere (max (y*Rot45 + x*Rot45, 0), max (y*Rot45 - x*Rot45, 0), z, 1)
}

#declare Screw_head = union
{  isosurface
   {  function //create a rounded edge using the negative image of a blob
      {  sqrt
         (  RE_fn_Blob2 (fn_Slot (x, ySlot - y, z), rScrew)
          + RE_fn_Blob2 (fn_Slot (z, ySlot - y, x), rScrew)
          + RE_fn_Blob2 (-RE_fn_Wheel (x, y - 1, z, 2, 6), rScrew)
          - RE_fn_Blob2 (f_sphere (x, y - ySlot, z, 1), rScrew)
         ) - 1
      }
      max_gradient 1.3/rScrew
      contained_by { box { <-8, 1, -8>, <8, 7, 8> } }
   }
   torus { 7, 1 translate y }
   texture { t_Metal_shine pigment { rgb <0.66, 0.72, 0.72> } }
   rotate 123.456 * y //randomish
   scale 1/32
}

//------------------

#declare hHold = 1;
#declare Thin = 0.035;
#declare RHold = hHold / 6 + Thin;
#declare rThin = Thin * 6 / (5 + sqrt(37));

#declare Holder = union
{  object
   {  RE_Washer_end ((hHold - 4) * y, -4 * y, RHold, RHold - 2*rThin, rThin, no)
      rotate PovRot * z
      translate <-0.5, 4 * PovCos, 0>
   }
  //A valid boundary case that would crash Round_Cylinder()
   RE_Cylinder (0, 2*rThin * y, 3.5, rThin, no)
   object
   {  RE_Round_join (RHold, 0.1)
      Shear_Trans (x / PovCos, <-PovSin, PovCos, 0>, z)
      translate <(4 - 2*rThin) * PovSin - 0.5, 2*rThin, 0>
   }
   object { Screw_head translate 3 * x }
   object { Screw_head translate 3 * x rotate 120 * y }
   object { Screw_head translate 3 * x rotate -120 * y }
   texture { t_Metal_shine pigment { rgb <0.61, 0.59, 0.54> } }
}

//------------------------------- DEMO SAMPLES ---------------------------------

#declare Dashed_line = cylinder
{  0, x, 1 scale <20, 0.025, RE_ABIT>
   pigment
   {  gradient x color_map 
      {  [0.3 rgb 0 transmit 0.6] [0.3 rgbt 1]
         [0.7 rgbt 1] [0.7 rgb 0 transmit 0.6]
      }
   }
}

#macro Show_minimal (Obj, Name)
   union
   {  intersection
      {  object { Obj }
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
   {  difference
      {  object { Obj }
         box { -3 * z, Size }
      }
      intersection
      {  object { Obj }
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
   #declare Sample = union
   {  RE_Box (-2, 2, 0.6, no)
      Sticker ("RE_Box", "", -2*z, 0.45, 0)
   }
   #break

#case (2)
   #declare Sample = union
   {  object { Axes }
      RE_Box_x (<-2, -2, -1>, <2, 0, 1>, 0.6, no)
      RE_Box_y (<0, 0, -1>, <3, 2, 1>, 0.6, no)
      RE_Box_z (<-3, 0, -1>, <0, 2, 1>, 0.6, no)
      Sticker ("RE_Box_x", "", <0.25, -1, -1>, 0.425, 0)
      Sticker ("RE_Box_y", "", <1.5, 1, -1>, 0.425, 0)
      Sticker ("RE_Box_z", "", <-1.5, 1, -1>, 0.425, 0)
   }
   #break

#case (3)
   #declare Sample = union
   {  object { Axes }
      RE_Box_left (<-2.5, 0, -1>, <2.5, 2, 1>, 0.6, no)
      RE_Box_right (<-2.5, -2, -1>, <2.5, 0, 1>, 0.6, no)
      Sticker ("RE_Box_left", "", <-0.6, 1, -1>, 0.45, 0)
      Sticker ("RE_Box_right", "", <0.5, -1, -1>, 0.45, 0)
   }
   #break

#case (4)
   #declare Sample = union
   {  object { Axes }
      RE_Box_up (<-2.5, -2, -1>, <0, 2, 1>, 0.6, no)
      RE_Box_down (<0, -2, -1>, <2.5, 2, 1>, 0.6, no)
      object { Sticker ("RE_Box_up", "", <0.25, 1.25, -1>, 0.45, 0) rotate 90 * z }
      object { Sticker ("RE_Box_down", "", <0, 1.25, -1>, 0.45, 0) rotate -90 * z }
   }
   #break

#case (5)
   #declare Sample = union
   {  object { Axes }
      RE_Box_near (<-1, -2, -2>, <1, 0, 2>, 0.6, no)
      RE_Box_far (<-1, 0, -2>, <1, 2, 2>, 0.6, no)
      object { Sticker ("RE_Box_near", "", -<0.2, 1, 1>, 0.45, 0) rotate -90 * y }
      object { Sticker ("RE_Box_far", "", <0.2, 1, -1>, 0.45, 0) rotate -90 * y }
      rotate 45 * y
   }
   #break

#case (6)
   #declare Sample = union
   {  object { Axes }
      RE_Box_x_near (<-1, 0.05, -2.95>, <1, 2, -0.05>, 0.6, no)
      RE_Box_x_up (<-1, 0.05, 0.05>, <1, 2, 2.95>, 0.6, no)
      RE_Box_x_far (<-1, -2, 0.05>, <1, -0.05, 2.95>, 0.6, no)
      RE_Box_x_down (<-1, -2, -2.95>, <1, -0.05, -0.05>, 0.6, no)
      union
      {  Sticker ("RE_Box_x_near", "", <-1.3, 0.75, -1>, 0.4, 0)
         Sticker ("RE_Box_x_up", "", <1.5, 1.25, -1>, 0.4, 0)
         Sticker ("RE_Box_x_far", "", <1.5, -1.25, -1>, 0.4, 0)
         Sticker ("RE_Box_x_down", "", <-1.3, -0.75, -1>, 0.4, 0)
         rotate -90 * y
      }
      rotate 45 * y
   }
   #break

#case (7)
   #declare c_Ink = rgb 1;
   #declare x_Tilt = transform { rotate -25 * x }
   #declare v_Tilted = vtransform (<0, 2, 1>, transform { x_Tilt });
   #declare FONT = "arial.ttf" //sans-serif. Non-Windows users change to taste.
   #declare Sample = union
   {  object { Axes }
      RE_Box_y_right (<-3, -2, -1>, <-1.56, 2, 1>, 0.5, no)
      RE_Box_y_near (<-1.48, -2, -1>, <-0.04, 2, 1>, 0.5, no)
      RE_Box_y_far (<0.04, -2, -1>, <1.48, 2, 1>, 0.5, no)
      RE_Box_y_left (<1.56, -2, -1>, <3, 2, 1>, 0.5, no)
      #declare f_Save = finish {}
      #default { finish { ambient 0.4 } }
      union
      {  Sticker ("RE_Box_y_right", FONT, <0, 2.28, -1>, 0.5, c_Ink)
         Sticker ("RE_Box_y_near", FONT, <0, 0.76, -1>, 0.5, c_Ink)
         Sticker ("RE_Box_y_far", FONT, <0, -0.76, -1>, 0.5, c_Ink)
         Sticker ("RE_Box_y_left", FONT, <0, -2.28, -1>, 0.5, c_Ink)
         rotate 90 * z
      }
      #default { finish { f_Save } }
      transform { x_Tilt }
      translate (v_Tilted.y - 2) * y
   }
   #break

#case (8)
   #declare Sample = union
   {  object { Axes }
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

#case (9)
   #declare Sample = RE_Cylinder (2*y, -2*y, 2, 0.4, no)
   #declare Caption = "RE_Cylinder"
   #break

#case (10)
   #declare Sample = RE_Cylinder_end (-2*y, 2*y, 2, 0.4, no)
   #declare Caption = "RE_Cylinder_end"
   #break

#case (11)
   #declare Sample = Show_sect (RE_Hole (-2 * z, 2 * z, 3, 1, 1, no), 3)
   #declare Caption = "RE_Hole"
   #break

#case (12)
   #declare Sample = Show_sect (RE_Hole_end (-2 * z, 2 * z, 3, 1, 1, no), 3)
   #declare Caption = "RE_Hole_end"
   #break

#case (13)
   #declare Sample = Show_minimal
      (RE_Hole_minimal (-2 * z, 2 * z, 1, 1, no), "RE_Hole_minimal")
   #break

#case (14)
   #declare Sample = Show_minimal
      (RE_Hole_end_minimal (-2 * z, 2 * z, 1, 1, no), "RE_Hole_end_minimal")
   #break

#case (15)
   #declare Sample = Show_sect (RE_Washer (-2 * z, 2 * z, 4, 1, 1, no), 4)
   #declare Caption = "RE_Washer"
   #break

#case (16)
   #declare Sample = Show_sect (RE_Washer_end (-2 * z, 2 * z, 4, 1, 1, no), 4)
   #declare Caption = "RE_Washer_end"
   #break

#case (17)
   #declare Sample = union
   {  box { -2, <2, -1, 2> }
      cylinder { -0.6 * y, 2 * y, 0.7 translate -0.5 * x }
      object { RE_Round_join (0.7, 0.4) translate <-0.5, -1, 0> }
      object { RE_Round_join (0.7, 0.4) translate <1.75, 0.5, 0> }
      Sticker ("RE_Round_join", "", <0, -1.5, -2>, 0.45, 0)
   }
   #break

#case (18)
   #declare Origin = <-0.8, -0.2, 0.5>;
   #declare rEdge = 0.4;
   #declare Sample = union
   {  union
      {  difference
         {  RE_Box (-2, 2, 1, no)
            box { Origin, <1, 1, -1> * 2 * RE_MORE }
         }
         RE_Straight_join_x (Origin, 2, rEdge, -90)
         RE_Straight_join_y (Origin, 2, rEdge, 90)
         RE_Straight_join_z (Origin, -2, rEdge, 0)
         difference
         {  box { 0, 1 }
            sphere { 1, 1 }
            rotate 90 * y
            scale rEdge
            translate Origin
         }
         rotate 30 * y
         translate 0.5 * z
      }
      RE_Straight_join_x (-2, 2, 0.6, -90)
   }
   #declare Caption = "RE_Straight_join_*"
   #break

#case (19)
   #declare R = 0.4;
   #declare Amp = 2;
   #declare Wlen = 6;
   #declare H = 8 * Amp / pow (Wlen, 2);
   #declare Side = Wlen/4;
   #declare Bob = Amp/2;
   #declare Sample = union
   {  intersection
      {  RE_Parabolic_torus (H, R)
         box { <-Side, -R, -R>, <Side, Bob + R, R> }
         translate <Side, Bob, 0>
      }
      intersection
      {  RE_Parabolic_torus (H, R)
         box { <-Side, 0, -R>, <Side, Bob + R, R> }
         translate <Side, -Bob, 0>
      }
      intersection
      {  quadric { -H * x, 0, y, 0 }
         box { <-Side, -2, -R>, <Side, Bob, R> }
         translate <Side, -Bob, 0>
      }
      intersection
      {  RE_Parabolic_torus (-H, R)
         box { <-Side, -Bob, -R>, <Side, R, R> }
         translate <-Side, Bob, 0>
      }
      intersection
      {  quadric { H * x, 0, y, 0 }
         box { <-Side, -2 - Bob, -R>, <Side, 0, R> }
         translate <-Side, Bob, 0>
      }
      Sticker ("RE_Parabolic_torus", "", <0, -1.4, -R>, 0.5, 0)
   }
   #break

#case (20)
   #declare Sample = isosurface
   {  function
      {  1 - RE_fn_Blob (abs(x) + abs(z) - 1, 0.3)
           - RE_fn_Blob (f_sphere (0, y, z, 0.8), 0.2)
      }
      max_gradient 4 / 0.2
      contained_by { box { -<2.5, 2, 1>, <2.5, 2, 1> } }
   }
   #declare Caption = "RE_fn_Blob"
   #break

#case (21)
   #declare Sample = isosurface
   {  function
      {  1 - sqrt
         (  RE_fn_Blob2 (abs(x) + abs(z) - 1, 0.3)
          + RE_fn_Blob2 (f_sphere (0, y, z, 0.8), 0.2)
         )
      }
      max_gradient 1.3 / 0.2
      contained_by { box { -<2.5, 2, 1>, <2.5, 2, 1> } }
   }
   #declare Caption = "RE_fn_Blob2"
   #break

#case (22)
   #declare R = 0.75;
   #declare RIn = 1;
   #declare ROut = 2.5;
   #declare Edge = 0.3;
   #declare Top = 2;
   #declare Side = union
   {  cylinder { <RIn + R, Top, 0>, <RIn + R, 0, 0>, R }
      box { <RIn + R, -RIn, -R>, <ROut, Top, R> }
      RE_Straight_join_x (<RIn + R, -RIn, R>, ROut, Edge, 0)
      RE_Straight_join_x (<RIn + R, -RIn, -R>, ROut, Edge, -90)
   }
   #declare Join = isosurface
   {  function
      {  1 - sqrt
         (  RE_fn_Blob2 (RE_fn_Hole (x, z, y, RIn + R, R), Edge)
          + RE_fn_Blob2 (y + RIn, Edge)
         //Note: be careful with negative blobs; they can easily blow the max_gradient.
          - RE_fn_Blob2 (f_sphere (x, y + RIn + R, z, R), Edge)
         )
      }
      max_gradient 1.42/Edge
      contained_by { box { -<0, RIn, R + Edge>, <RIn + R, Edge - RIn, R + Edge> } }
   }
   #declare Sample = union
   {  RE_Box_down (-ROut, <ROut, -RIn, ROut>, 0.05, no)
      intersection
      {  RE_Hole_minimal (-R * z, R * z, RIn, R, no)
         plane { y, 0 }
      }
      object { Join texture { t_Metal_satin pigment { rgb <0.8, 0.35, 0.2> } } }
      object { Join scale <-1, 1, 1> }
      object { Side }
      object { Side scale <-1, 1, 1> }
      Sticker ("RE_fn_Hole", "", <0, -1.45, -ROut>, 0.45, 0)
      Sticker ("with RE_fn_Blob2", "", <0, -2, -ROut>, 0.375, 0)
      translate (ROut - 2) * y
   }
   #break

#case (23) //demo central ellipse
   #declare Rx = 2.4;
   #declare Rz = 1.4;
   #declare rEdge = 0.6;
   #declare Contain = <Rx, Rz, 0> + rEdge;
   #declare Sample = union
   {  cylinder { -z, z, 1 scale <Rx, Rz, rEdge> }
      Sticker ("TBA", "", <0, 0, -rEdge>, 0.5, 0)
      translate z
   }
   #break

#case (24) //demo inner & outer ellipses (not)
   #declare Rx = 2.4;
   #declare Rz = 1.4;
   #declare rEdge = 0.6;
   #declare Contain = <Rx, Rz, 0> + rEdge;
   #declare Sample = union
   {  union
      {  difference
         {  cylinder { 0, 1.5*z, 1 scale Contain }
            cylinder
            {  -RE_ABIT * z, RE_MORE * 1.5*z, 1
               scale <Rx - rEdge, Rz - rEdge, rEdge>
            }
         }
         rotate 30 * y
         translate z
      }
   }
   #declare Caption = "TBA"
   #break

#case (25)
   #declare R = 0.4;
   #declare Amp = 2;
   #declare Wlen = 6;
   #declare H = 8 * Amp / pow (Wlen, 2);
   #declare Side = Wlen/4;
   #declare Bob = Amp/2;
   #declare Sample = union
   {  isosurface
      {  function { RE_fn_Parabolic_torus (x - Side, y - Bob, z, H, R) }
         max_gradient 1.7
         contained_by { box { <0, Bob - R, -R>, <Wlen/2, 2*Bob + R, R> } }
      }
      isosurface
      {  function { RE_fn_Parabolic_torus (x - Side, y + Bob, z, H, R) }
         max_gradient 1.7
         contained_by { box { <0, -Bob, -R>, <Wlen/2, R, R> } }
      }
      isosurface
      {  function { RE_fn_Parabolic_torus (x + Side, y - Bob, z, -H, R) }
         max_gradient 1.7
         contained_by { box { <-Wlen/2, 0, -R>, <0, R + Bob, R> } }
      }
      intersection
      {  quadric { -H * x, 0, y, 0 }
         box { <-Side, -2, -R>, <Side, Bob, R> }
         translate <Side, -Bob, 0>
      }
      intersection
      {  quadric { H * x, 0, y, 0 }
         box { <-Side, -2 - Bob, -R>, <Side, 0, R> }
         translate <-Side, Bob, 0>
      }
      Sticker ("RE_fn_Parabolic_torus", "", <0, -1.4, -R>, 0.5, 0)
   }
   #break

#case (26)
   #declare R = 0.4;
   #declare ROut = 2.75;
   #declare Blobby= 0.6;
   #declare Effect = R + sqrt (pow (Blobby + R, 2) - pow (Blobby + R - Blobby/sqrt(2), 2));
   #declare End_blob = isosurface
   {  function
      {  1 - sqrt
         (  RE_fn_Blob2 (RE_fn_Wheel (x, z, y, ROut - R, R), Blobby)
          + RE_fn_Blob2 (RE_fn_Wheel (x, y, z, ROut - R, R), Blobby)
         //Note: be careful with negative blobs; they can easily blow the max_gradient.
          - RE_fn_Blob2 (f_sphere (x + R - ROut, y, z, R), Blobby)
         )
      }
      max_gradient 1.42 / Blobby
      accuracy 0.00001
      contained_by
      {  box { <ROut - Effect, 0, -R - Blobby>, <ROut, R + Blobby, R + Blobby> }
      }
   }
   #declare Sample = union
   {  RE_Cylinder (R*y, (ROut - 4) * y, ROut, R, no)
      RE_Cylinder (-R*z, R*z, ROut, R, no)
      RE_Straight_join_x (<ROut - Effect, R, -R>, Effect - ROut, Blobby, -90)
      RE_Straight_join_x (<ROut - Effect, R, R>, Effect - ROut, Blobby, 0)
      object 
      {  End_blob
         texture { t_Metal_satin pigment { rgb <0.1, 0.3, 0.5> } }
      }
      object { End_blob rotate 180 * y }
      Sticker ("RE_fn_Wheel", "", <0, 1.7, -R>, 0.475, 0)
      Sticker ("with RE_fn_Blob2", "", <0, 1.2, -R>, 0.4, 0)
      translate <0, 2 - ROut, 0>
   }
   #break

#case (27)
   #declare R = 0.4;
   #declare RBlob = RE_fn_Blob_distance (1.5, 4);
   #declare Sample = union
   {  blob
      {  sphere { 0, 1.5, 4 }
         cylinder { 0, <1.5, 2.5, 0>, 0.8, 4 }
      }
      difference
      {  RE_Washer_end (R * y, -RBlob * y, 2, RBlob, R, no)
         box { <0, R * RE_MORE, 0>, <3, -3, -3> }
      }
      RE_Cylinder_end (-2 * y, -RBlob * y, 2, R, no)
   }
   #declare Caption = "RE_fn_Blob_distance"
   #break

#case (28)
   #declare RMajor = 1.3;
   #declare rMinor = 0.7;
   #declare Signage = transform { rotate <Debug_boom, Debug_dolly, 0> }
   #declare Sample = union
   {  intersection
      {  torus { RMajor, rMinor rotate 90 * x }
         plane { y, 0 }
      }
      blob //radius of spheres to match minor radius of torus
      {  sphere { -RMajor * x, RE_fn_Blob_radius (rMinor, 2), 2 }
         sphere { RMajor * x, 1.2, RE_fn_Blob_strength (rMinor, 1.2) }
         cylinder { <-0.5, 1.5, 0>, <0.5, 1.5, 0>, 1.3, 2.3 }
      }
      union
      {  Sticker ("RE_fn_Blob_radius", "", <-1.5, 2.25, -2>, 0.425, 0)
         Sticker ("RE_fn_Blob_strength", "", <1.3, 1.45, -2>, 0.425, 0)
         transform { Signage }
      }
      union
      {  cone { <-RMajor, 0, -rMinor>, 0.01,
                vtransform (<-2, 1.9, -2>, transform { Signage }), 0.05 }
         cone { <RMajor, 0, -rMinor>, 0.01,
                vtransform (<1.8, 1.1, -2>, transform { Signage }), 0.05 }
         pigment { rgb 0 }
         no_shadow
      }
   }
   #break

//cmd:declare=Test=99 declare=MaxG=1
//(Shhhh!!!)
#range (90, 99)
   #declare Sample = RE_Cylinder (sqrt(4/3), -sqrt(4/3), 2, 2, no)
   #break

#else
   #include "textures.inc"

   #declare Sample = union
   {  object { Platform }
      union
      {  object { Povument }
         object { Holder }
         scale 0.4
         translate H3 * y
      }
   }

#end

//--------------------------------- DISPLAY ------------------------------------

object
{  Sample
   texture { #if (MaxG) t_Max_gradient_test #else t_Sample #end }
}

#if (strcmp (Caption, ""))
   #declare Word = Sticker (Caption, "", 0, 0.375, 0)
   union
   {  object { Word }
      box
      {  min_extent (Word), max_extent (Word)
         scale <1.1, 1.4, 1>
         translate max_extent (Word) * z
         pigment { rgb 1 transmit 0.7 }
         finish { ambient 0.4 }
      }
      no_shadow
      translate <0, -0.1, -4> rotate <0, Debug_dolly, 0>
   }
#end
