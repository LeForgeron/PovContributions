/* coffeemug.inc version 2.0
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * A coffee mug, with available (untextured) beverage object.
 *
 * Copyright 2008 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   2008-Aug-05  Created.
 * 1.0   2008-Aug-07  Submitted to the POV-Ray Object Collection.
 * 1.1   2008-Aug-08  Texture are options added.
 * 1.2   2008-Aug-31  Local variables are renamed to avoid potential problems
 *                    with POV-Ray's odd scoping rules.
 * 1.3   2013-May-20  Meniscus options are introduced.
 *                    Module is made compatible to version 3.5.
 * 1.3a  2013-May-21  Version 1.3, re-uploaded with correct sample output.
 *       2015-Feb-04  The fix for the torus merge artifact is replaced with
 *                    a faster solution.
 *       2015-Feb-21  The bottom of the mug is redesigned, and a stack height
 *                    macro is added.
 *       2015-Feb-??  A version identifier is added.
 *       2015-Feb-28  The pigment and texture macros are rewritten to map
 *                    general pigments and textures cylindrically, not just the
 *                    object masks.
 * 2.0   2015-Mar-05  Identifiers with short prefixes are introduced, and the
 *                    code is edited accordingly in many places, to improve
 *                    compactness and readability.
 */
#ifndef (CoffeeMug_Inc_Temp) #declare CoffeeMug_Inc_Temp = version;
#version 3.5;

#debug "#include \"coffeemug.inc\" //version 2.0\n"
#declare COFFEEMUG_VERSION = 2.0;

//----------------------- Public values and parameters -------------------------
// (See the user manual for descriptions.)
#ifndef (CoffeeMug_rMeniscus) #declare CoffeeMug_rMeniscus = 2; #end //in mm
#ifndef (CoffeeMug_ConAngle) #declare CoffeeMug_ConAngle = 8; #end

#declare COFFEEMUG_HEIGHT = 0;
#declare COFFEEMUG_INCH = 1;
#declare COFFEEMUG_CM = 2;
#declare COFFEEMUG_MM = 3;
#declare COFFEEMUG_NO_MASK = plane { z, 1 }

//----------------------- Internal (private) values ----------------------------
#declare MUG__FLOOR = 2; // floor height, relative to wall thickness
#declare MUG__LOWER = 1.5; // top of S-rounding of mug bottom, relative to wall thickness
#declare MUG__RFOOT = 1/8; // rounded edge of mug bottom, relative to wall thickness
#declare MUG__WALL = 1/8; // default wall thickness, relative to radius
#declare MUG__EPSILON = 0.01;
#declare MUG__MORE = 1 + MUG__EPSILON;

//================= INTERNAL (PRIVATE) MACROS AND FUNCTIONS ====================

//----------------------------------------------------------
// Computes a blob's field strength, given the surface radius and field radius.
// See RoundEdge in the Object Collection for more like this.
#declare Mug__fn_Blob = function (mug_P0_RSurface, mug_P1_RField)
{ 1 / pow (1 - pow (mug_P0_RSurface / mug_P1_RField, 2), 2)
}

//----------------------------------------------------------
// Returns the height of a cylinder, without the thickness of the floor of the
// hypothetical mug.
#macro Mug__Net_height (Radius, Wall, Capacity, Units)
( CoffeeMug_Height (Radius, Capacity, Units)
 // If the unit is MUG_HEIGHT, then CoffeeMug_Height() has returned the entire
 // height of the mug, not the height of the space inside.  In this case, the
 // floor height must be subtracted.
  - (Units = MUG_HEIGHT? MUG__FLOOR * Wall: 0)
)
#end

//----------------------------------------------------------
// Converts a number to a string of the given number of significant digits.
#macro Mug__Str (Number, Sig)
  #if (Number < 0 | Number > 0) //This circumlocution avoids the epsilon.
    str (Number, 1, max (Sig - floor(log(abs(Number))) - 1, 0))
  #else
    str (0, 1, Sig - 1)
  #end
#end

//----------------------------------------------------------
// A merge of torus and cylinder has an artifact if the major radius is less
// than half the minor radius.  This construction avoids that problem.
#macro Mug__Torus (RMajor, rMinor)
  #if (RMajor * 2 < rMinor)
    #local mug_R = sqrt (rMinor * rMinor - RMajor * RMajor);
    merge
    { difference
      { torus { RMajor, rMinor }
        sphere { 0, mug_R }
      }
      sphere { 0, (mug_R + rMinor) / 2 }
    }
  #else
    torus { RMajor, rMinor }
  #end
#end
// Note:  The internal function coffeemug__fn_Meniscus() has been deleted.
// If you need that functionality, please use function RE_fn_Wheel() in the
// RoundEdge module of the Object Collection.

//============================== PUBLIC MACROS =================================
// (See the user manual for descriptions.)

#macro CoffeeMug_Height (Radius, Capacity, Units)
( #switch (Units)
    #case (MUG_INCH) // oz to inches
      #local MUG_OZtoCC = 29.565;
      #local MUG_IN3toCC = pow (2.54, 3);
      (Capacity * MUG_OZtoCC / MUG_IN3toCC) / (pi * Radius*Radius)
      #break
    #case (MUG_CM) //ml to cm
      Capacity / (pi * Radius*Radius)
      #break
    #case (MUG_MM) //ml to mm
      Capacity / (pi * Radius*Radius) * 1000
      #break
    #case (MUG_HEIGHT) //no conversion
    #else //undefined
      Capacity
  #end
)
#end

//----------------------------------------------------------

#macro CoffeeMug_Stack_height (Radius, Wall, Capacity, Units)
( #local mug_Wall = (Wall? Wall: Radius * MUG__WALL);
  Mug__Net_height (Radius - mug_Wall, mug_Wall, Capacity, Units)
  + mug_Wall * (MUG__FLOOR - 0.5 - MUG__RFOOT)
)
#end

//----------------------------------------------------------

#macro CoffeeMug_Mug (Radius, Capacity, Units, Use_merge)
  #local mug_Wall = Radius * MUG__WALL;
  #local mug_Space = Radius * 2/3;
  CoffeeMug_Detail
  ( Radius, mug_Wall, Capacity, Units,
    < 2.7 * mug_Wall,
      Mug__Net_height (Radius - mug_Wall, mug_Wall, Capacity, Units) * 0.85,
      mug_Space + 1.5 * mug_Wall
    >,
    mug_Space, Use_merge
  )
#end

//----------------------------------------------------------

#macro CoffeeMug_Detail
( Radius, Wall, Capacity, Units, v_Handle, Handle_space, Use_merge
)
  #local mug_RInner = Radius - Wall;
  #local mug_H = Mug__Net_height (mug_RInner, Wall, Capacity, Units);
  #local mug_rRim = Wall / 2;
  #local mug_hFloor = Wall * MUG__FLOOR;
  #local mug_rFoot = Wall * MUG__RFOOT;
  #local mug_yUnder = (MUG__LOWER - MUG__FLOOR) * Wall;

  #local mug_rHandle = (v_Handle.z - Handle_space) / 2;
  #local mug_sxHandle = v_Handle.x / (mug_rHandle * 2);

  #local mug_RTop = v_Handle.z / 2; //Handle_space / 2 + mug_rHandle;
  #local MUG_SANGLE = 15;
  #local mug_ysHandle = (mug_H + v_Handle.y) / 2 - mug_RTop - mug_rHandle;
  #local mug_zHandle = -Radius - Handle_space/2;

  #local mug_RBottom = Handle_space + mug_rHandle;
  #local mug_Reserve = v_Handle.y - mug_RTop - mug_rHandle;
  #if (mug_Reserve < v_Handle.z)
    #warning "CoffeeMug_Detail(): v_Handle.y is too short, or v_Handle.z too deep, for a well-formed handle.\n"
    #warning concat ("v_Handle = <", vstr (3, v_Handle, ", ", 0, 4), ">\n")
    #local MUG_IANGLE = 0;
  #else
    #local MUG_IANGLE = min (degrees (acos (v_Handle.z / mug_Reserve)), 25);
  #end
  #local mug_C = v_Handle.z / cos (radians (MUG_IANGLE));
  #local mug_yiHandle = (mug_H - v_Handle.y) / 2 + mug_C;

  #if (Use_merge) merge #else union #end
  { difference
    { cylinder { mug_yUnder * y, (mug_H - mug_rRim) * y, Radius }
      cylinder { mug_rRim * y, mug_H * y, mug_RInner }
      cylinder { 0, mug_rRim * MUG__MORE * y, mug_RInner - mug_rRim }
      torus { mug_RInner - mug_rRim, mug_rRim translate mug_rRim * y }
    }
    torus { Radius - mug_rRim, mug_rRim translate (mug_H - mug_rRim) * y }
   //base of mug
    lathe
    { bezier_spline 28,
      <0, -0.01 * Wall>, <0, -0.01 * Wall>,
        <Radius, mug_yUnder>, <Radius, mug_yUnder>,
      <Radius, mug_yUnder>, <Radius, mug_yUnder - Wall * 0.6>,
        <mug_RInner, mug_rFoot - mug_hFloor + Wall * 0.6>,
        <mug_RInner, mug_rFoot - mug_hFloor>,
      <mug_RInner, mug_rFoot - mug_hFloor>,
        <mug_RInner, 0.448 * mug_rFoot - mug_hFloor>,
        <mug_RInner - 0.448 * mug_rFoot, -mug_hFloor>,
        <mug_RInner - mug_rFoot, -mug_hFloor>,
      <mug_RInner - mug_rFoot, -mug_hFloor>,
        <mug_RInner - mug_rFoot, -mug_hFloor>,
        <mug_RInner - Wall * 0.7, -mug_hFloor>,
        <mug_RInner - Wall * 0.7, -mug_hFloor>,
      <mug_RInner - Wall * 0.7, -mug_hFloor>,
        <mug_RInner - Wall * 0.9, -mug_hFloor>,
        <mug_RInner - Wall * 0.9, -mug_hFloor>,
        <mug_RInner - Wall * 1.1, Wall * 0.2 - mug_hFloor>,
      <mug_RInner - Wall * 1.1, Wall * 0.2 - mug_hFloor>,
        <mug_RInner - Wall * 1.5, Wall * 0.6 - mug_hFloor>,
        <(mug_RInner - Wall * 1.1) / 2, -2/3 * mug_hFloor>,
        <0, -2/3 * mug_hFloor>,
      <0, -2/3 * mug_hFloor>, <0, -2/3 * mug_hFloor>,
        <0, -0.01 * Wall>, <0, -0.01 * Wall>
    }
   //top of handle
    intersection
    { torus { mug_RTop, mug_rHandle rotate 90 * z scale <mug_sxHandle, 1, 1> }
      plane { -y, 0 }
      plane { z, 0 rotate MUG_SANGLE * x }
      translate <0, mug_ysHandle, mug_zHandle>
    }
    intersection
    { blob
      { cylinder
        { 0, mug_RTop * z, mug_rHandle + mug_rRim,
          Mug__fn_Blob (mug_rHandle, mug_rHandle + mug_rRim)
          scale <mug_sxHandle, 1, 1> translate mug_RTop * y
          rotate MUG_SANGLE * x translate <0, mug_ysHandle, mug_zHandle>
        }
        cylinder
        { 0, mug_H * y, Radius + mug_rRim,
          Mug__fn_Blob (Radius, Radius + mug_rRim)
        }
      }
      cylinder
      { -MUG__EPSILON * z, mug_RTop * z, mug_rHandle + mug_rRim
        scale <mug_sxHandle, 1, 1> translate mug_RTop * y
        rotate MUG_SANGLE * x translate <0, mug_ysHandle, mug_zHandle>
      }
      plane { z, mug_rRim - Radius }
    }
   //bottom of handle
    intersection
    { torus
      { mug_RBottom, mug_rHandle
        rotate 90 * z scale <mug_sxHandle, 1, 1>
      }
      plane { y, 0 }
      plane { z, 0 rotate MUG_IANGLE * x }
      translate <0, mug_yiHandle, -Radius>
    }
    intersection
    { blob
      { cylinder
        { 0, mug_C * z, mug_rHandle + mug_rRim,
          Mug__fn_Blob (mug_rHandle, mug_rHandle + mug_rRim)
          scale <mug_sxHandle, 1, 1> translate -mug_RBottom * y
          rotate MUG_IANGLE * x translate <0, mug_yiHandle, -Radius>
        }
        cylinder
        { 0, mug_H * y, Radius + mug_rRim,
          Mug__fn_Blob (Radius, Radius + mug_rRim)
        }
      }
      cylinder
      { -MUG__EPSILON * z, mug_C * z, mug_rHandle + mug_rRim
        scale <mug_sxHandle, 1, 1> translate -mug_RBottom * y
        rotate MUG_IANGLE * x translate <0, mug_yiHandle, -Radius>
      }
      plane { z, mug_rRim - Radius }
    }
   //middle of handle
    #if (mug_yiHandle != mug_ysHandle)
      blob //blob cylinder makes for cleaner merge than cylinder alone
      { cylinder
        { mug_yiHandle * y, mug_ysHandle * y, mug_rHandle + mug_rRim,
          Mug__fn_Blob (mug_rHandle, mug_rHandle + mug_rRim)
          scale <mug_sxHandle, 1, 1>
          translate  (mug_zHandle - mug_RTop) * z
        }
      }
    #end
    translate mug_hFloor * y
  }
#end

//----------------------------------------------------------

#macro CoffeeMug_Beverage (Radius, Wall, Capacity, Units, Epsilon)
  #local mug_Wall = (Wall? Wall: Radius * MUG__WALL);
  #local mug_RInner = Radius - mug_Wall;
  #local mug_rRim = mug_Wall / 2;
  #local mug_H = CoffeeMug_Height (mug_RInner, Capacity, Units);
  #if (CoffeeMug_ConAngle < 0 | CoffeeMug_ConAngle > 180)
    #warning concat
    ( "CoffeeMug_Beverage(): invalid value ", Mug__Str (CoffeeMug_ConAngle, 6),
      " for CoffeeMug_ConAngle.  No meniscus will be rendered.\n"
    )
    #local mug_rMen = 0;
  #else
    #local mug_rMen = CoffeeMug_rMeniscus
      * #switch (Units)
          #case (MUG_INCH) 1/25.4; #break
          #case (MUG_CM) 0.1; #break
          #case (MUG_MM) 1; #break
          #else 0;
        #end
  #end
  merge
  {//Conform to rounded floor of mug:
    cylinder { -Epsilon * y, mug_rRim * MUG__MORE * y, mug_RInner - mug_rRim }
    torus { mug_RInner - mug_rRim, mug_rRim + Epsilon translate mug_rRim * y }
   //Remainder of beverage:
    #if (mug_rMen = 0 | CoffeeMug_ConAngle = 90) //no meniscus
      cylinder { mug_rRim * y, mug_H * y, mug_RInner + Epsilon }
    #else
      #local mug_xMen = mug_rMen * abs (cos (radians(CoffeeMug_ConAngle)));
      #if (mug_xMen < mug_RInner)
        #local mug_hMen = mug_rMen * (1 - sin (radians(CoffeeMug_ConAngle)));
        #local mug_RTorus = mug_RInner - mug_xMen;
      #else //too narrow for any flat surface
        #local mug_rMen = mug_RInner / abs (cos (radians(CoffeeMug_ConAngle)));
        #local mug_hMen =
          mug_rMen - sqrt (pow (mug_rMen, 2) - pow (mug_RInner, 2));
      #end
      #if (CoffeeMug_ConAngle < 90) //concave meniscus
        difference
        { cylinder
          { mug_rRim * y, (mug_H + mug_hMen) * y, mug_RInner + Epsilon
          }
          #if (mug_xMen >= mug_RInner) //too narrow for any flat surface
            sphere { (mug_H + mug_rMen) * y, mug_rMen }
          #else //general case
            object
            { Mug__Torus (mug_RTorus, mug_rMen)
              translate (mug_H + mug_rMen) * y
            }
            cylinder
            { mug_H * y, (mug_H + mug_hMen * MUG__MORE) * y, mug_RTorus
            }
          #end
        }
      #else //convex meniscus
        #local mug_Clip = cone
        { MUG__EPSILON * y, mug_RInner + Epsilon + mug_hMen + MUG__EPSILON,
          (-mug_hMen - MUG__EPSILON) * y, mug_RInner + Epsilon - MUG__EPSILON
          translate mug_H * y
        }
        cylinder { mug_rRim * y, (mug_H - mug_hMen) * y, mug_RInner + Epsilon }
        #if (mug_xMen >= mug_RInner) //too narrow for any flat surface
          intersection
          { sphere { (mug_H - mug_rMen) * y, mug_rMen }
            object { mug_Clip }
          }
        #else //general case
          intersection
          { object
            { Mug__Torus (mug_RTorus, mug_rMen)
              translate (mug_H - mug_rMen) * y
            }
            object { mug_Clip }
          }
          cylinder
          { mug_H * y, (mug_H - mug_hMen - MUG__EPSILON) * y, mug_RTorus
          }
        #end
      #end
    #end
    translate mug_Wall * MUG__FLOOR * y
  }
#end

//----------------------------------------------------------

#macro CoffeeMug_Wrap (Radius)
  translate <0, 0, Radius>
  scale <0.5 / (pi * Radius), 1, 1>
  translate 0.5 * x
  warp { cylindrical }
  rotate 90 * y
#end

//----------------------------------------------------------

#macro CoffeeMug_Pigment
( Radius, Wall, Capacity, Units, o_Mask, p_Background, p_Foreground
)
  #local mug_Wall = (Wall? Wall: Radius * MUG__WALL);
  #local mug_Upper = mug_Wall * (MUG__FLOOR - 0.5)
    + Mug__Net_height (Radius - mug_Wall, mug_Wall, Capacity, Units);
  #local mug_Lower = mug_Wall * MUG__LOWER;
  #local mug_Middle = (mug_Upper + mug_Lower) / 2;
  #local mug_fn_Print = function { pigment { object { o_Mask rgb 0 rgb 1 } } }
  #local mug_p_Print = pigment { p_Foreground CoffeeMug_Wrap (Radius) }
  pigment
  { object
    { intersection // confine foreground pigment to outside of mug
      { plane { y, mug_Upper }
        plane { -y, -mug_Lower }
        cylinder
        { 0, (mug_Upper + MUG__EPSILON) * y, Radius - mug_Wall/2
          inverse
        }
      }
      pigment { p_Background }
      pigment
      { function { mug_fn_Print (atan2 (-x, z) * Radius, y - mug_Middle, 0).x }
        pigment_map
        { [0.5 p_Background]
          [0.5 mug_p_Print translate mug_Middle * y]
        }
      }
    }
  }
#end

//----------------------------------------------------------

#macro CoffeeMug_Texture
( Radius, Wall, Capacity, Units, o_Mask, t_Background, t_Foreground
)
  #local mug_Wall = (Wall? Wall: Radius * MUG__WALL);
  #local mug_Upper = mug_Wall * (MUG__FLOOR - 0.5)
    + Mug__Net_height (Radius - mug_Wall, mug_Wall, Capacity, Units);
  #local mug_Lower = mug_Wall * MUG__LOWER;
  #local mug_Middle = (mug_Upper + mug_Lower) / 2;
  #local mug_fn_Print = function { pigment { object { o_Mask rgb 0 rgb 1 } } }
  #local mug_t_Wrapped = texture
  { function { 1 } texture_map { [1 t_Foreground translate mug_Middle * y] }
    CoffeeMug_Wrap (Radius)
  };
  texture
  { object
    { intersection // confine foreground texture to outside of mug
      { plane { y, mug_Upper }
        plane { -y, -mug_Lower }
        cylinder
        { 0, (mug_Upper + MUG__EPSILON) * y, Radius - mug_Wall/2
          inverse
        }
      }
      texture { t_Background }
      texture
      { function { mug_fn_Print (atan2 (-x, z) * Radius, y - mug_Middle, 0).x }
        texture_map { [0.5 t_Background] [0.5 mug_t_Wrapped] }
      }
    }
  }
#end

//======================== SHORT-PREFIX ALTERNATIVES ===========================

#declare MUG_HEIGHT = COFFEEMUG_HEIGHT;
#declare MUG_INCH = COFFEEMUG_INCH;
#declare MUG_CM = COFFEEMUG_CM;
#declare MUG_MM = COFFEEMUG_MM;
#declare MUG_NO_MASK = COFFEEMUG_NO_MASK

#macro Mug_Height (Radius, Capacity, Units)
  CoffeeMug_Height (Radius, Capacity, Units)
#end

#macro Mug_Stack_height (Radius, Wall, Capacity, Units)
  CoffeeMug_Stack_height (Radius, Wall, Capacity, Units)
#end

#macro Mug_Mug (Radius, Capacity, Units, Use_merge)
  CoffeeMug_Mug (Radius, Capacity, Units, Use_merge)
#end

#macro Mug_Detail
( Radius, Wall, Capacity, Units, v_Handle, Handle_space, Use_merge
)
  CoffeeMug_Detail
  ( Radius, Wall, Capacity, Units, v_Handle, Handle_space, Use_merge
  )
#end

#macro Mug_Beverage (Radius, Wall, Capacity, Units, Epsilon)
  CoffeeMug_Beverage (Radius, Wall, Capacity, Units, Epsilon)
#end

#macro Mug_Wrap (Radius)
  CoffeeMug_Wrap (Radius)
#end

#macro Mug_Pigment
( Radius, Wall, Capacity, Units, o_Mask, p_Background, p_Foreground
)
  CoffeeMug_Pigment
  ( Radius, Wall, Capacity, Units, o_Mask, p_Background, p_Foreground
  )
#end

#macro Mug_Texture
( Radius, Wall, Capacity, Units, o_Mask, t_Background, t_Foreground
)
  CoffeeMug_Texture
  ( Radius, Wall, Capacity, Units, o_Mask, t_Background, t_Foreground
  )
#end

#version CoffeeMug_Inc_Temp;
#end
// end of coffeemug.inc
