/* coffeemug.inc version 1.3
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Copyright 2008 - 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers   Date         Comments
 * ----   ----         --------
 * n/a    05-aug-2008  Created.
 * 1.0    07-aug-2008  Submitted to the POV-Ray Object Collection.
 * 1.1    08-aug-2008  Texture options added.
 * 1.2    31-aug-2008  Local variables renamed to avoid potential problems with
 *                     POV-Ray's odd scoping rules.
 * 1.3    20-may-2013  Introduced meniscus options.
 *                     Made compatible to version 3.5.
 */
#ifndef (COFFEEMUG_INC) #declare COFFEEMUG_INC = version;
#version 3.5;

#include "functions.inc"

#ifndef (CoffeeMug_rMeniscus) #declare CoffeeMug_rMeniscus = 2; #end //in mm
#ifndef (CoffeeMug_ConAngle) #declare CoffeeMug_ConAngle = 8; #end

#declare COFFEEMUG_HEIGHT = 0;
#declare COFFEEMUG_INCH = 1;
#declare COFFEEMUG_CM = 2;
#declare COFFEEMUG_MM = 3;

#declare COFFEEMUG__BOTTOM = 2;
#declare COFFEEMUG__WALL = 1/8;
#declare COFFEEMUG__EPSILON = 0.01;
#declare COFFEEMUG__MORE = 1 + COFFEEMUG__EPSILON;

//================================= PRIVATE MACROS AND FUNCTIONS ===================================

//------------------------------------------------------------------------------
// Converts a number to a string of the given number of significant digits.
#macro coffeemug__Str (Number, Sig)
  #if (Number = 0) str (0, 1, Sig - 1)
  #else str (Number, 1, max (Sig - floor(log(abs(Number))) - 1, 0))
  #end
#end

//------------------------------------------------------------------------------
// Computes a blob's field strength, given the surface radius and field radius.
// See RoundEdge in the Object Collection for more like this.
#declare coffeemug__fn_Blob = function (CoffeeMug_P0, CoffeeMug_P1)
{ 1 / pow (1 - pow (CoffeeMug_P0 / CoffeeMug_P1, 2), 2)
}

//------------------------------------------------------------------------------
// A merge of torus and cylinder has artifacts if the major radius is less than
// half the minor radius.  This is an equivalent isosurface to avoid that
// problem.  Copied from RE_fn_Wheel() in RoundEdge.
#declare coffeemug__fn_Meniscus = function (x, y, z, RMajor, rMinor)
{ select
  ( pow(x,2) + pow(z,2) - pow(RMajor,2),
    max (y - rMinor, -rMinor - y),
    f_torus (x, y, z, RMajor, rMinor)
  )
}

//------------------------------------------------------------------------------

#macro coffeemug__Net_height (Radius, Wall, Capacity, Units)
( CoffeeMug_Height (Radius, Capacity, Units)
- (Units = COFFEEMUG_HEIGHT? COFFEEMUG__BOTTOM * Wall: 0)
)
#end

//======================================== PUBLIC MACROS ===========================================

#macro CoffeeMug_Height (Radius, Capacity, Units)
( #switch (Units)
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

#macro CoffeeMug_Mug (Radius, Capacity, Units, Use_merge)
  #local coffeemug_Wall = Radius * COFFEEMUG__WALL;
  #local coffeemug_Space = Radius * 2/3;
  CoffeeMug_Detail
  ( Radius, coffeemug_Wall, Capacity, Units,
    < 2.7 * coffeemug_Wall,
      coffeemug__Net_height (Radius - coffeemug_Wall, coffeemug_Wall, Capacity, Units) * 0.85,
      coffeemug_Space + 1.5 * coffeemug_Wall
    >,
    coffeemug_Space, Use_merge
  )
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Detail (Radius, Wall, Capacity, Units, v_Handle, Handle_space, Use_merge)

  #local coffeemug_RInner = Radius - Wall;
  #local coffeemug_H = coffeemug__Net_height (coffeemug_RInner, Wall, Capacity, Units);
  #local coffeemug_rRim = Wall / 2;
  #local coffeemug_rFoot = coffeemug_rRim * 0.25;
  #local coffeemug_rUnder = coffeemug_rRim * 41/32;
  #local coffeemug_hUnder = Wall * 5/4;
  #local coffeemug_yUnder = coffeemug_rFoot + coffeemug_hUnder - COFFEEMUG__BOTTOM * Wall;

  #local coffeemug_rHandle = (v_Handle.z - Handle_space) / 2;
  #local coffeemug_sxHandle = v_Handle.x / (coffeemug_rHandle * 2);

  #local coffeemug_RTop = v_Handle.z / 2;//Handle_space / 2 + coffeemug_rHandle;
  #local COFFEEMUG_SANGLE = 15;
  #local coffeemug_ysHandle = (coffeemug_H + v_Handle.y) / 2 - coffeemug_RTop - coffeemug_rHandle;
  #local coffeemug_zHandle = -Radius - Handle_space/2;

  #local coffeemug_RBottom = Handle_space + coffeemug_rHandle;
  #local coffeemug_Reserve = v_Handle.y - coffeemug_RTop - coffeemug_rHandle;
  #if (coffeemug_Reserve < v_Handle.z)
    #warning "CoffeeMug_Detail(): v_Handle.y is too short, or v_Handle.z too deep, for a well-formed handle.\n"
    #warning concat ("v_Handle = <", vstr (3, v_Handle, ", ", 0, 4), ">\n")
    #local COFFEEMUG_IANGLE = 0;
  #else
    #local COFFEEMUG_IANGLE = min (degrees (acos (v_Handle.z / coffeemug_Reserve)), 25);
  #end
  #local coffeemug_C = v_Handle.z / cos (radians (COFFEEMUG_IANGLE));
  #local coffeemug_yiHandle = (coffeemug_H - v_Handle.y) / 2 + coffeemug_C;

  #if (Use_merge) merge #else union #end
  { difference
    { cylinder { coffeemug_yUnder * y, (coffeemug_H - coffeemug_rRim) * y, Radius }
      cylinder { coffeemug_rRim * y, coffeemug_H * y, coffeemug_RInner }
      cylinder { 0, coffeemug_rRim * COFFEEMUG__MORE * y, coffeemug_RInner - coffeemug_rRim }
      torus { coffeemug_RInner - coffeemug_rRim, coffeemug_rRim translate coffeemug_rRim * y }
    }
    torus { Radius - coffeemug_rRim, coffeemug_rRim translate (coffeemug_H - coffeemug_rRim) * y }
    torus { Radius - coffeemug_rUnder, coffeemug_rUnder translate coffeemug_yUnder * y }
   //base of mug
    #if (Use_merge) merge #else union #end
    { difference
      { cylinder { 0, coffeemug_hUnder * COFFEEMUG__MORE * y, coffeemug_RInner + coffeemug_rRim }
        torus { coffeemug_RInner + coffeemug_rUnder, coffeemug_rUnder }
        superellipsoid
        { <1, 0.75> rotate 90 * x
          scale
          < coffeemug_RInner - Wall,
            (COFFEEMUG__BOTTOM - 1) * Wall - coffeemug_rFoot,
            coffeemug_RInner - Wall
          >
        }
      }
      torus { coffeemug_RInner - coffeemug_rFoot, coffeemug_rFoot }
      torus { coffeemug_RInner - Wall + coffeemug_rFoot, coffeemug_rFoot }
      difference
      { cylinder
        { -coffeemug_rFoot * y, COFFEEMUG__EPSILON * y, coffeemug_RInner - coffeemug_rFoot
        }
        cylinder
        { -coffeemug_rFoot * COFFEEMUG__MORE * y, 2 * COFFEEMUG__EPSILON * y,
          coffeemug_RInner - Wall + coffeemug_rFoot
        }
      }
      translate (coffeemug_rFoot - COFFEEMUG__BOTTOM * Wall) * y
    }
   //top of handle
    intersection
    { torus { coffeemug_RTop, coffeemug_rHandle rotate 90 * z scale <coffeemug_sxHandle, 1, 1> }
      plane { -y, 0 }
      plane { z, 0 rotate COFFEEMUG_SANGLE * x }
      translate <0, coffeemug_ysHandle, coffeemug_zHandle>
    }
    intersection
    { blob
      { cylinder
        { 0, coffeemug_RTop * z, coffeemug_rHandle + coffeemug_rRim,
          coffeemug__fn_Blob (coffeemug_rHandle, coffeemug_rHandle + coffeemug_rRim)
          scale <coffeemug_sxHandle, 1, 1> translate coffeemug_RTop * y
          rotate COFFEEMUG_SANGLE * x translate <0, coffeemug_ysHandle, coffeemug_zHandle>
        }
        cylinder
        { 0, coffeemug_H * y, Radius + coffeemug_rRim,
          coffeemug__fn_Blob (Radius, Radius + coffeemug_rRim)
        }
      }
      cylinder
      { -COFFEEMUG__EPSILON * z, coffeemug_RTop * z, coffeemug_rHandle + coffeemug_rRim
        scale <coffeemug_sxHandle, 1, 1> translate coffeemug_RTop * y
        rotate COFFEEMUG_SANGLE * x translate <0, coffeemug_ysHandle, coffeemug_zHandle>
      }
      plane { z, coffeemug_rRim - Radius }
    }
   //bottom of handle
    intersection
    { torus { coffeemug_RBottom, coffeemug_rHandle rotate 90 * z scale <coffeemug_sxHandle, 1, 1> }
      plane { y, 0 }
      plane { z, 0 rotate COFFEEMUG_IANGLE * x }
      translate <0, coffeemug_yiHandle, -Radius>
    }
    intersection
    { blob
      { cylinder
        { 0, coffeemug_C * z, coffeemug_rHandle + coffeemug_rRim,
          coffeemug__fn_Blob (coffeemug_rHandle, coffeemug_rHandle + coffeemug_rRim)
          scale <coffeemug_sxHandle, 1, 1> translate -coffeemug_RBottom * y
          rotate COFFEEMUG_IANGLE * x translate <0, coffeemug_yiHandle, -Radius>
        }
        cylinder
        { 0, coffeemug_H * y, Radius + coffeemug_rRim,
          coffeemug__fn_Blob (Radius, Radius + coffeemug_rRim)
        }
      }
      cylinder
      { -COFFEEMUG__EPSILON * z, coffeemug_C * z, coffeemug_rHandle + coffeemug_rRim
        scale <coffeemug_sxHandle, 1, 1> translate -coffeemug_RBottom * y
        rotate COFFEEMUG_IANGLE * x translate <0, coffeemug_yiHandle, -Radius>
      }
      plane { z, coffeemug_rRim - Radius }
    }
   //middle of handle
    #if (coffeemug_yiHandle != coffeemug_ysHandle)
      blob //blob cylinder makes for cleaner merge than cylinder alone
      { cylinder
        { coffeemug_yiHandle * y, coffeemug_ysHandle * y, coffeemug_rHandle + coffeemug_rRim,
          coffeemug__fn_Blob (coffeemug_rHandle, coffeemug_rHandle + coffeemug_rRim)
          scale <coffeemug_sxHandle, 1, 1>
          translate  (coffeemug_zHandle - coffeemug_RTop) * z
        }
      }
    #end
    translate Wall * COFFEEMUG__BOTTOM * y
  }
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Beverage (Radius, Wall, Capacity, Units, Epsilon)
  #local coffeemug_Wall = (Wall? Wall: Radius * COFFEEMUG__WALL);
  #local coffeemug_RInner = Radius - coffeemug_Wall;
  #local coffeemug_rRim = coffeemug_Wall / 2;
  #local coffeemug_H = CoffeeMug_Height (coffeemug_RInner, Capacity, Units);
  #if (CoffeeMug_ConAngle < 0 | CoffeeMug_ConAngle > 180)
    #warning concat
    ( "CoffeeMug_Beverage(): invalid value ", coffeemug__Str (CoffeeMug_ConAngle, 6),
      " for CoffeeMug_ConAngle.  No meniscus will be rendered.\n"
    )
    #local coffeemug_rMen = 0;
  #else
    #local coffeemug_rMen = CoffeeMug_rMeniscus
      * #switch (Units)
          #case (COFFEEMUG_INCH) 1/25.4; #break
          #case (COFFEEMUG_CM) 0.1; #break
          #case (COFFEEMUG_MM) 1; #break
          #else 0;
        #end
  #end
  merge
  {//Conform to rounded bottom of mug:
    cylinder { -Epsilon * y, coffeemug_rRim * COFFEEMUG__MORE * y, coffeemug_RInner - coffeemug_rRim }
    torus { coffeemug_RInner - coffeemug_rRim, coffeemug_rRim + Epsilon translate coffeemug_rRim * y }
   //Remainder of beverage:
    #if (coffeemug_rMen = 0 | CoffeeMug_ConAngle = 90) //no meniscus
      cylinder { coffeemug_rRim * y, coffeemug_H * y, coffeemug_RInner + Epsilon }
    #else
      #local coffeemug_xMen = coffeemug_rMen * abs (cos (radians(CoffeeMug_ConAngle)));
      #if (coffeemug_xMen < coffeemug_RInner)
        #local coffeemug_hMen = coffeemug_rMen * (1 - sin (radians(CoffeeMug_ConAngle)));
        #local coffeemug_RTorus = coffeemug_RInner - coffeemug_xMen;
        #local coffeemug_RrTorus = coffeemug_RTorus + coffeemug_rMen;
        #local coffeemug_No_artifact = isosurface
        { function { coffeemug__fn_Meniscus (x, y, z, coffeemug_RTorus, coffeemug_rMen) }
          contained_by
          { box
            { -<coffeemug_RrTorus, coffeemug_rMen, coffeemug_RrTorus>,
              <coffeemug_RrTorus, coffeemug_rMen, coffeemug_RrTorus>
            }
          }
          all_intersections
          accuracy min (0.001, abs (Epsilon / 10))
        }
      #else //too narrow for any flat surface
        #local coffeemug_rMen = coffeemug_RInner / abs (cos (radians(CoffeeMug_ConAngle)));
        #local coffeemug_hMen =
          coffeemug_rMen - sqrt (pow (coffeemug_rMen, 2) - pow (coffeemug_RInner, 2));
      #end
      #if (CoffeeMug_ConAngle < 90) //concave meniscus
        difference
        { cylinder { coffeemug_rRim * y, (coffeemug_H + coffeemug_hMen) * y, coffeemug_RInner + Epsilon }
          #if (coffeemug_xMen >= coffeemug_RInner) //too narrow for any flat surface
            sphere { (coffeemug_H + coffeemug_rMen) * y, coffeemug_rMen }
          #else #if (coffeemug_RTorus < coffeemug_rMen * 0.5) //slow, but avoids artifact
            object { coffeemug_No_artifact translate (coffeemug_H + coffeemug_rMen) * y }
          #else //general case
            torus
            { coffeemug_RTorus, coffeemug_rMen
              translate (coffeemug_H + coffeemug_rMen) * y
            }
            cylinder
            { coffeemug_H * y, (coffeemug_H + coffeemug_hMen * COFFEEMUG__MORE) * y, coffeemug_RTorus
            }
          #end
          #end
        }
      #else //convex meniscus
        #local coffeemug_Clip = cone
        { COFFEEMUG__EPSILON * y, coffeemug_RInner + Epsilon + coffeemug_hMen + COFFEEMUG__EPSILON,
          (-coffeemug_hMen - COFFEEMUG__EPSILON) * y, coffeemug_RInner + Epsilon - COFFEEMUG__EPSILON
          translate coffeemug_H * y
        }
        cylinder { coffeemug_rRim * y, (coffeemug_H - coffeemug_hMen) * y, coffeemug_RInner + Epsilon }
        #if (coffeemug_xMen >= coffeemug_RInner) //too narrow for any flat surface
          intersection
          { sphere { (coffeemug_H - coffeemug_rMen) * y, coffeemug_rMen }
            object { coffeemug_Clip }
          }
        #else #if (coffeemug_RTorus < coffeemug_rMen * 0.5) //slow, but avoids artifact
          intersection
          { object { coffeemug_No_artifact translate (coffeemug_H - coffeemug_rMen) * y }
            object { coffeemug_Clip }
          }
        #else //general case
          intersection
          { torus
            { coffeemug_RTorus, coffeemug_rMen
              translate (coffeemug_H - coffeemug_rMen) * y
            }
            object { coffeemug_Clip }
          }
          cylinder
          { coffeemug_H * y, (coffeemug_H - coffeemug_hMen - COFFEEMUG__EPSILON) * y, coffeemug_RTorus
          }
        #end
        #end
      #end
    #end
    translate coffeemug_Wall * COFFEEMUG__BOTTOM * y
  }
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Pigment (Radius, Wall, Capacity, Units, o_Print, p_Background, p_Foreground)
  #local coffeemug_Wall = (Wall? Wall: Radius * COFFEEMUG__WALL);
  #local coffeemug_H = coffeemug__Net_height (Radius - coffeemug_Wall, coffeemug_Wall, Capacity, Units);
  #local coffeemug_fn_Print = function { pigment { object { o_Print rgb 0 rgb 1 } } }
  pigment
  { object
    { cylinder { 0, coffeemug_H * y, Radius - coffeemug_Wall/2 } //avoid inside of mug
      pigment
      { function { coffeemug_fn_Print (atan2 (-x, z) * Radius, y, 0).red }
        pigment_map { [0.5 p_Background] [0.5 p_Foreground] }
        translate coffeemug_H/2 * y
      }
      pigment { p_Background }
    }
    translate coffeemug_Wall * (COFFEEMUG__BOTTOM - 0.5) * y
  }
#end

//------------------------------------------------------------------------------

#macro CoffeeMug_Texture (Radius, Wall, Capacity, Units, o_Print, t_Background, t_Foreground)
  #local coffeemug_Wall = (Wall? Wall: Radius * COFFEEMUG__WALL);
  #local coffeemug_H = coffeemug__Net_height (Radius - coffeemug_Wall, coffeemug_Wall, Capacity, Units);
  #local coffeemug_fn_Print = function { pigment { object { o_Print rgb 0 rgb 1 } } }
  texture
  { object
    { cylinder { 0, coffeemug_H * y, Radius - coffeemug_Wall/2 } //avoid inside of mug
      texture
      { function { coffeemug_fn_Print (atan2 (-x, z) * Radius, y, 0).red }
        texture_map { [0.5 t_Background] [0.5 t_Foreground] }
        translate coffeemug_H/2 * y
      }
      texture { t_Background }
    }
    translate coffeemug_Wall * (COFFEEMUG__BOTTOM - 0.5) * y
  }
#end

#version COFFEEMUG_INC;
#end
