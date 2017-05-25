/* coffeemug.inc version 1.2
 *
 * Copyright 2008 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 * --- : 05-aug-2008 : Created.
 * 1.0 : 07-aug-2008 : Submitted to the POV-Ray Object Collection.
 * 1.1 : 08-aug-2008 : Texture options added.
 * 1.2 : 31-aug-2008 : Local variables renamed to avoid potential problems with
 *                     POV-Ray's odd scoping rules.
 */
#ifndef (COFFEEMUG_INC) #declare COFFEEMUG_INC = version;
#version 3.6;

#declare COFFEEMUG_HEIGHT = 0;
#declare COFFEEMUG_INCH = 1;
#declare COFFEEMUG_CM = 2;
#declare COFFEEMUG_MM = 3;

#declare COFFEEMUG_BOTTOM = 2;
#declare COFFEEMUG_WALL = 1/8;
#declare COFFEEMUG_MENISCUS = 2; //approx. mm
#declare COFFEEMUG_EPSILON = 0.01;
#declare COFFEEMUG_MORE = 1 + COFFEEMUG_EPSILON;

//------------------------------------------------------------------------------

#macro CoffeeMug_Height (Radius, Capacity, Units)
(  #switch (Units)
   #case (COFFEEMUG_INCH) // oz to inches
      #local COFFEEMUG_OZtoCC = 29.565;
      #local COFFEEMUG_IN3toCC = pow (2.54, 3);
      (Capacity * COFFEEMUG_OZtoCC / COFFEEMUG_IN3toCC) / (pi * Radius*Radius)
      #break
   #case (COFFEEMUG_CM) //ml to cm
      Capacity / (pi * Radius*Radius)
      #break
   #case (COFFEEMUG_MM) //ml to mm
      Capacity / (pi * Radius*Radius) * 1000
      #break
   #case (COFFEEMUG_HEIGHT) //no conversion
   #else //undefined
      Capacity
   #end
)
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Net_height (Radius, Wall, Capacity, Units)
(  CoffeeMug_Height (Radius, Capacity, Units)
 - (Units = COFFEEMUG_HEIGHT? COFFEEMUG_BOTTOM * Wall: 0)
)
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Mug (Radius, Capacity, Units, Use_merge)
   #local coffeemug_Wall = Radius * COFFEEMUG_WALL;
   #local coffeemug_Space = Radius * 2/3;
   CoffeeMug_Detail
   (  Radius, coffeemug_Wall, Capacity, Units,
      <2.7 * coffeemug_Wall,
       CoffeeMug_Net_height (Radius - coffeemug_Wall, coffeemug_Wall, Capacity, Units) * 0.85,
       coffeemug_Space + 1.5 * coffeemug_Wall>,
      coffeemug_Space, Use_merge
   )
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Detail (Radius, Wall, Capacity, Units, Handle, Handle_space, Use_merge)

   #local coffeemug_RInner = Radius - Wall;
   #local coffeemug_H = CoffeeMug_Net_height (coffeemug_RInner, Wall, Capacity, Units);
   #local coffeemug_rRim = Wall / 2;
   #local coffeemug_rFoot = coffeemug_rRim * 0.25;
   #local coffeemug_rUnder = coffeemug_rRim * 41/32;
   #local coffeemug_hUnder = Wall * 5/4;
   #local coffeemug_yUnder = coffeemug_rFoot + coffeemug_hUnder - COFFEEMUG_BOTTOM * Wall;

   #local coffeemug_rHandle = (Handle.z - Handle_space) / 2;
   #local coffeemug_sxHandle = Handle.x / (coffeemug_rHandle * 2);

   #local coffeemug_RTop = Handle.z / 2;//Handle_space / 2 + coffeemug_rHandle;
   #local COFFEEMUG_SANGLE = 15;
   #local coffeemug_ysHandle = (coffeemug_H + Handle.y) / 2 - coffeemug_RTop - coffeemug_rHandle;
   #local coffeemug_zHandle = -Radius - Handle_space/2;

   #local coffeemug_RBottom = Handle_space + coffeemug_rHandle;
   #local coffeemug_Reserve = Handle.y - coffeemug_RTop - coffeemug_rHandle;
   #if (coffeemug_Reserve < Handle.z)
      #warning "CoffeeMug_Detail(): Handle.y is too small for a well-formed handle.\n"
      #local COFFEEMUG_IANGLE = 0;
   #else
      #local COFFEEMUG_IANGLE = min (degrees (acos (Handle.z / coffeemug_Reserve)), 25);
   #end
   #local coffeemug_C = Handle.z / cos (radians (COFFEEMUG_IANGLE));
   #local coffeemug_yiHandle = (coffeemug_H - Handle.y) / 2 + coffeemug_C;

  //computes a blob's field strength, given the surface radius and field radius.
   #local CoffeeMug_Blob = function (CoffeeMug_P0, CoffeeMug_P1)
   {  1 / pow (1 - pow (CoffeeMug_P0 / CoffeeMug_P1, 2), 2)
   }

   #if (Use_merge) merge #else union #end
   {  difference
      {  cylinder { coffeemug_yUnder * y, (coffeemug_H - coffeemug_rRim) * y, Radius }
         cylinder { coffeemug_rRim * y, coffeemug_H * y, coffeemug_RInner }
         cylinder { 0, coffeemug_rRim * COFFEEMUG_MORE * y, coffeemug_RInner - coffeemug_rRim }
         torus { coffeemug_RInner - coffeemug_rRim, coffeemug_rRim translate coffeemug_rRim * y }
      }
      torus { Radius - coffeemug_rRim, coffeemug_rRim translate (coffeemug_H - coffeemug_rRim) * y }
      torus { Radius - coffeemug_rUnder, coffeemug_rUnder translate coffeemug_yUnder * y }
     //base of mug
      #if (Use_merge) merge #else union #end
      {  difference
         {  cylinder { 0, coffeemug_hUnder * COFFEEMUG_MORE * y, coffeemug_RInner + coffeemug_rRim }
            torus { coffeemug_RInner + coffeemug_rUnder, coffeemug_rUnder }
            superellipsoid
            {  <1, 0.75> rotate 90 * x
               scale <coffeemug_RInner - Wall, (COFFEEMUG_BOTTOM - 1) * Wall - coffeemug_rFoot, coffeemug_RInner - Wall>
            }
         }
         torus { coffeemug_RInner - coffeemug_rFoot, coffeemug_rFoot }
         torus { coffeemug_RInner - Wall + coffeemug_rFoot, coffeemug_rFoot }
         difference
         {  cylinder { -coffeemug_rFoot * y, COFFEEMUG_EPSILON * y, coffeemug_RInner - coffeemug_rFoot }
            cylinder { -coffeemug_rFoot * COFFEEMUG_MORE * y, 2 * COFFEEMUG_EPSILON * y,
                       coffeemug_RInner - Wall + coffeemug_rFoot }
         }
         translate (coffeemug_rFoot - COFFEEMUG_BOTTOM * Wall) * y
      }
     //top of handle
      intersection
      {  torus { coffeemug_RTop, coffeemug_rHandle rotate 90 * z scale <coffeemug_sxHandle, 1, 1> }
         plane { -y, 0 }
         plane { z, 0 rotate COFFEEMUG_SANGLE * x }
         translate <0, coffeemug_ysHandle, coffeemug_zHandle>
      }
      intersection
      {  blob
         {  cylinder
            {  0, coffeemug_RTop * z, coffeemug_rHandle + coffeemug_rRim, CoffeeMug_Blob (coffeemug_rHandle, coffeemug_rHandle + coffeemug_rRim)
               scale <coffeemug_sxHandle, 1, 1> translate coffeemug_RTop * y
               rotate COFFEEMUG_SANGLE * x translate <0, coffeemug_ysHandle, coffeemug_zHandle>
            }
            cylinder { 0, coffeemug_H * y, Radius + coffeemug_rRim, CoffeeMug_Blob (Radius, Radius + coffeemug_rRim) }
         }
         cylinder
         {  -COFFEEMUG_EPSILON * z, coffeemug_RTop * z, coffeemug_rHandle + coffeemug_rRim
            scale <coffeemug_sxHandle, 1, 1> translate coffeemug_RTop * y
            rotate COFFEEMUG_SANGLE * x translate <0, coffeemug_ysHandle, coffeemug_zHandle>
         }
         plane { z, coffeemug_rRim - Radius }
      }
     //bottom of handle
      intersection
      {  torus { coffeemug_RBottom, coffeemug_rHandle rotate 90 * z scale <coffeemug_sxHandle, 1, 1> }
         plane { y, 0 }
         plane { z, 0 rotate COFFEEMUG_IANGLE * x }
         translate <0, coffeemug_yiHandle, -Radius>
      }
      intersection
      {  blob
         {  cylinder
            {  0, coffeemug_C * z, coffeemug_rHandle + coffeemug_rRim, CoffeeMug_Blob (coffeemug_rHandle, coffeemug_rHandle + coffeemug_rRim)
               scale <coffeemug_sxHandle, 1, 1> translate -coffeemug_RBottom * y
               rotate COFFEEMUG_IANGLE * x translate <0, coffeemug_yiHandle, -Radius>
            }
            cylinder { 0, coffeemug_H * y, Radius + coffeemug_rRim, CoffeeMug_Blob (Radius, Radius + coffeemug_rRim) }
         }
         cylinder
         {  -COFFEEMUG_EPSILON * z, coffeemug_C * z, coffeemug_rHandle + coffeemug_rRim
            scale <coffeemug_sxHandle, 1, 1> translate -coffeemug_RBottom * y
            rotate COFFEEMUG_IANGLE * x translate <0, coffeemug_yiHandle, -Radius>
         }
         plane { z, coffeemug_rRim - Radius }
      }
     //middle of handle
      #if (coffeemug_yiHandle != coffeemug_ysHandle)
         blob //blob cylinder makes for cleaner merge than cylinder alone
         {  cylinder
            {  coffeemug_yiHandle * y, coffeemug_ysHandle * y, coffeemug_rHandle + coffeemug_rRim,
               CoffeeMug_Blob (coffeemug_rHandle, coffeemug_rHandle + coffeemug_rRim)
               scale <coffeemug_sxHandle, 1, 1> translate  (coffeemug_zHandle - coffeemug_RTop) * z
            }
         }
      #end
      translate Wall * COFFEEMUG_BOTTOM * y
   }
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Beverage (Radius, Wall, Capacity, Units, Epsilon)
   #local coffeemug_Wall = (Wall? Wall: Radius * COFFEEMUG_WALL);
   #local coffeemug_RInner = Radius - coffeemug_Wall;
   #local coffeemug_rRim = coffeemug_Wall / 2;
   #local coffeemug_H = CoffeeMug_Height (coffeemug_RInner, Capacity, Units);
   #local coffeemug_Meniscus = COFFEEMUG_MENISCUS
    * #switch (Units)
      #case (COFFEEMUG_INCH) 1/25.4; #break
      #case (COFFEEMUG_CM) 0.1; #break
      #case (COFFEEMUG_MM) 1; #break
      #else 0;
      #end
   merge
   {  cylinder { -Epsilon * y, coffeemug_rRim * COFFEEMUG_MORE * y, coffeemug_RInner - coffeemug_rRim }
      torus { coffeemug_RInner - coffeemug_rRim, coffeemug_rRim + Epsilon translate coffeemug_rRim * y }
      #if (coffeemug_Meniscus) difference #else object #end
      {  cylinder { coffeemug_rRim * y, (coffeemug_H + coffeemug_Meniscus) * y, coffeemug_RInner + Epsilon }
         #if (coffeemug_Meniscus)
            torus { coffeemug_RInner - coffeemug_Meniscus, coffeemug_Meniscus translate (coffeemug_H + coffeemug_Meniscus) * y }
            cylinder { coffeemug_H * y, (coffeemug_H + coffeemug_Meniscus * COFFEEMUG_MORE) * y, coffeemug_RInner - coffeemug_Meniscus }
         #end
      }
      translate coffeemug_Wall * COFFEEMUG_BOTTOM * y
   }
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Pigment (Radius, Wall, Capacity, Units, o_Print, p_Background, p_Foreground)
   #local coffeemug_Wall = (Wall? Wall: Radius * COFFEEMUG_WALL);
   #local coffeemug_H = CoffeeMug_Net_height (Radius - coffeemug_Wall, coffeemug_Wall, Capacity, Units);
   #local coffeemug_fn_Print = function { pigment { object { o_Print rgb 0 rgb 1 } } }
   pigment 
   {  object
      {  cylinder { 0, coffeemug_H * y, Radius - coffeemug_Wall/2 } //avoid inside of mug
         pigment
         {  function { coffeemug_fn_Print (atan2 (-x, z) * Radius, y, 0).red }
            pigment_map { [0.5 p_Background] [0.5 p_Foreground] }
            translate coffeemug_H/2 * y
         }
         pigment { p_Background }
      }
      translate coffeemug_Wall * (COFFEEMUG_BOTTOM - 0.5) * y
   }
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Texture (Radius, Wall, Capacity, Units, o_Print, t_Background, t_Foreground)
   #local coffeemug_Wall = (Wall? Wall: Radius * COFFEEMUG_WALL);
   #local coffeemug_H = CoffeeMug_Net_height (Radius - coffeemug_Wall, coffeemug_Wall, Capacity, Units);
   #local coffeemug_fn_Print = function { pigment { object { o_Print rgb 0 rgb 1 } } }
   texture 
   {  object
      {  cylinder { 0, coffeemug_H * y, Radius - coffeemug_Wall/2 } //avoid inside of mug
         texture
         {  function { coffeemug_fn_Print (atan2 (-x, z) * Radius, y, 0).red }
            texture_map { [0.5 t_Background] [0.5 t_Foreground] }
            translate coffeemug_H/2 * y
         }
         texture { t_Background }
      }
      translate coffeemug_Wall * (COFFEEMUG_BOTTOM - 0.5) * y
   }
#end

#version COFFEEMUG_INC;
#end
