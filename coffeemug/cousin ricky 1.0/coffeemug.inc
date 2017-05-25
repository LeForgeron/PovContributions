/* coffeemug.inc version 1.0
 *
 * Copyright 2008 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 * Created 05-aug-2008 for the POV-Ray Object Collection.
 * Updated 07-aug-2008.
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
      #local OZtoCC = 29.565;
      #local IN3toCC = pow (2.54, 3);
      (Capacity * OZtoCC / IN3toCC) / (pi * Radius*Radius)
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
   #local Wall = Radius * COFFEEMUG_WALL;
   #local Space = Radius * 2/3;
   CoffeeMug_Detail
   (  Radius, Wall, Capacity, Units,
      <2.7 * Wall,
       CoffeeMug_Net_height (Radius - Wall, Wall, Capacity, Units) * 0.85,
       Space + 1.5 * Wall>,
      Space, Use_merge
   )
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Detail (Radius, Wall, Capacity, Units, Handle, Handle_space, Use_merge)

   #local RInner = Radius - Wall;
   #local H = CoffeeMug_Net_height (RInner, Wall, Capacity, Units);
   #local rRim = Wall / 2;
   #local rFoot = rRim * 0.25;
   #local rUnder = rRim * 41/32;
   #local hUnder = Wall * 5/4;
   #local yUnder = rFoot + hUnder - COFFEEMUG_BOTTOM * Wall;

   #local rHandle = (Handle.z - Handle_space) / 2;
   #local sxHandle = Handle.x / (rHandle * 2);

   #local RTop = Handle.z / 2;//Handle_space / 2 + rHandle;
   #local SANGLE = 15;
   #local ysHandle = (H + Handle.y) / 2 - RTop - rHandle;
   #local zHandle = -Radius - Handle_space/2;

   #local RBottom = Handle_space + rHandle;
   #local Reserve = Handle.y - RTop - rHandle;
   #if (Reserve < Handle.z)
      #warning "CoffeeMug_Detail(): Handle.y is too small for a well-formed handle.\n"
      #local IANGLE = 0;
   #else
      #local IANGLE = min (degrees (acos (Handle.z / Reserve)), 25);
   #end
   #local C = Handle.z / cos (radians (IANGLE));
   #local yiHandle = (H - Handle.y) / 2 + C;

  //computes a blob's field strength, given the surface radius and field radius.
   #local CoffeeMug_Blob = function (CoffeeMug_P0, CoffeeMug_P1)
   {  1 / pow (1 - pow (CoffeeMug_P0 / CoffeeMug_P1, 2), 2)
   }

   #if (Use_merge) merge #else union #end
   {  difference
      {  cylinder { yUnder * y, (H - rRim) * y, Radius }
         cylinder { rRim * y, H * y, RInner }
         cylinder { 0, rRim * COFFEEMUG_MORE * y, RInner - rRim }
         torus { RInner - rRim, rRim translate rRim * y }
      }
      torus { Radius - rRim, rRim translate (H - rRim) * y }
      torus { Radius - rUnder, rUnder translate yUnder * y }
     //base of mug
      #if (Use_merge) merge #else union #end
      {  difference
         {  cylinder { 0, hUnder * COFFEEMUG_MORE * y, RInner + rRim }
            torus { RInner + rUnder, rUnder }
            superellipsoid
            {  <1, 0.75> rotate 90 * x
               scale <RInner - Wall, (COFFEEMUG_BOTTOM - 1) * Wall - rFoot, RInner - Wall>
            }
         }
         torus { RInner - rFoot, rFoot }
         torus { RInner - Wall + rFoot, rFoot }
         difference
         {  cylinder { -rFoot * y, COFFEEMUG_EPSILON * y, RInner - rFoot }
            cylinder { -rFoot * COFFEEMUG_MORE * y, 2 * COFFEEMUG_EPSILON * y,
                       RInner - Wall + rFoot }
         }
         translate (rFoot - COFFEEMUG_BOTTOM * Wall) * y
      }
     //top of handle
      intersection
      {  torus { RTop, rHandle rotate 90 * z scale <sxHandle, 1, 1> }
         plane { -y, 0 }
         plane { z, 0 rotate SANGLE * x }
         translate <0, ysHandle, zHandle>
      }
      intersection
      {  blob
         {  cylinder
            {  0, RTop * z, rHandle + rRim, CoffeeMug_Blob (rHandle, rHandle + rRim)
               scale <sxHandle, 1, 1> translate RTop * y
               rotate SANGLE * x translate <0, ysHandle, zHandle>
            }
            cylinder { 0, H * y, Radius + rRim, CoffeeMug_Blob (Radius, Radius + rRim) }
         }
         cylinder
         {  -COFFEEMUG_EPSILON * z, RTop * z, rHandle + rRim
            scale <sxHandle, 1, 1> translate RTop * y
            rotate SANGLE * x translate <0, ysHandle, zHandle>
         }
         plane { z, rRim - Radius }
      }
     //bottom of handle
      intersection
      {  torus { RBottom, rHandle rotate 90 * z scale <sxHandle, 1, 1> }
         plane { y, 0 }
         plane { z, 0 rotate IANGLE * x }
         translate <0, yiHandle, -Radius>
      }
      intersection
      {  blob
         {  cylinder
            {  0, C * z, rHandle + rRim, CoffeeMug_Blob (rHandle, rHandle + rRim)
               scale <sxHandle, 1, 1> translate -RBottom * y
               rotate IANGLE * x translate <0, yiHandle, -Radius>
            }
            cylinder { 0, H * y, Radius + rRim, CoffeeMug_Blob (Radius, Radius + rRim) }
         }
         cylinder
         {  -COFFEEMUG_EPSILON * z, C * z, rHandle + rRim
            scale <sxHandle, 1, 1> translate -RBottom * y
            rotate IANGLE * x translate <0, yiHandle, -Radius>
         }
         plane { z, rRim - Radius }
      }
     //middle of handle
      #if (yiHandle != ysHandle)
         blob //blob cylinder makes for cleaner merge than cylinder alone
         {  cylinder
            {  yiHandle * y, ysHandle * y, rHandle + rRim,
               CoffeeMug_Blob (rHandle, rHandle + rRim)
               scale <sxHandle, 1, 1> translate  (zHandle - RTop) * z
            }
         }
      #end
      translate Wall * COFFEEMUG_BOTTOM * y
   }
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Beverage (Radius, Wall, Capacity, Units, Epsilon)
   #if (!Wall) #local Wall = Radius * COFFEEMUG_WALL; #end
   #local RInner = Radius - Wall;
   #local rRim = Wall / 2;
   #local H = CoffeeMug_Height (RInner, Capacity, Units);
   #local Meniscus = COFFEEMUG_MENISCUS
    * #switch (Units)
      #case (COFFEEMUG_INCH) 1/25.4; #break
      #case (COFFEEMUG_CM) 0.1; #break
      #case (COFFEEMUG_MM) 1; #break
      #else 0;
      #end
   merge
   {  cylinder { -Epsilon * y, rRim * COFFEEMUG_MORE * y, RInner - rRim }
      torus { RInner - rRim, rRim + Epsilon translate rRim * y }
      #if (Meniscus) difference #else object #end
      {  cylinder { rRim * y, (H + Meniscus) * y, RInner + Epsilon }
         #if (Meniscus)
            torus { RInner - Meniscus, Meniscus translate (H + Meniscus) * y }
            cylinder { H * y, (H + Meniscus * COFFEEMUG_MORE) * y, RInner - Meniscus }
         #end
      }
      translate Wall * COFFEEMUG_BOTTOM * y
   }
#end

#version COFFEEMUG_INC;
#end
