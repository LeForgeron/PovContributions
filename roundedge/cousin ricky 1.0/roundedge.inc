/* roundedge.inc version 1.0
 *
 * Macros and functions to facilitate rounded CSG joints and edges.
 * Based on various functions and macros that I wrote, dating back to 2004.
 *
 * Copyright 2008 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 * n/a 12-jul-2008 Compiled from old include files
 * 1.0 24-aug-2008 Adapted for object collection save RE_fn_Oblong_torus()
 * n/a 02-sep-2008 Local variable names brought into compliance
 * n/a 03-sep-2008 Administrative
 */
#ifndef (ROUNDEDGE_INC) #declare ROUNDEDGE_INC = version;
#version 3.6;

#include "transforms.inc"
#include "shapes.inc"
#debug "#include \"roundedge.inc\" //version 1.0\n"

//============================== ERROR HANDLING ================================

//N.B. In my personal experience, the error checking is *necessary*.

#macro RE__str (Number)
   #local re_Sig = 3;
   #if (Number * 1e10 = 0) str (0, 1, re_Sig - 1) //1e10 helps avoid the epsilon
   #else str (Number, 1, max (re_Sig - floor(log(abs(Number))) - 1, 0))
   #end
#end

#macro RE__error (Name, Side)
   #error concat (Name, "(): Zero ", Side, ".\n")
#end

#macro RE__check0 (Name, Desc, Side)
   #if (Side = 0) #warning concat (Name, "(): Zero ", Desc, ".\n") #end
#end

#macro RE__check_neg (Name, Desc, Edge)
   #if (Edge < 0)
      #warning concat (Name, "(): The ", Desc, " (", RE__str(Edge),
         ") is negative. The result is undefined.\n")
   #end
#end

#macro RE__check1 (Name, rEdge)
   RE__check_neg (Name, "edge radius", rEdge)
#end

#macro RE__check2 (Name, Side, Dim1, Dim2, rEdge, Constraint)
   #local re_Dim = abs (Dim2 - Dim1);
   #if (re_Dim < rEdge * Constraint)
      #warning concat (Name, "(): ", Side, " (", RE__str(re_Dim),
         ") is less than ", #if (Constraint = 2) "twice ", #end
         "the edge radius (", RE__str(rEdge), "). The result is undefined.\n")
   #end
#end

#macro RE__check3 (Name, RInner, ROuter, rEdge, Constraint)
   #if (RInner > ROuter)
      #warning concat (Name, "(): The outer radius (", RE__str(ROuter),
         ") is less than the inner radius (", RE__str(RInner),
         "). The result is undefined.\n")
   #else#if (ROuter - RInner < rEdge * Constraint)
      #warning concat (Name, "(): The difference between the outer radius (",
         RE__str(ROuter), ") and the inner radius (", RE__str(RInner),
         ") is less than ", #if (Constraint = 2) "twice ", #end
         "the edge radius (", RE__str(rEdge), "). The result is undefined.\n")
   #end#end
#end

//============================ CONVENIENT VALUES ===============================

#ifndef (RE_MORE) #declare RE_MORE = 1.001; #end
#ifndef (RE_LESS) #declare RE_LESS = 0.999; #end
#ifndef (RE_ABIT) #declare RE_ABIT = 0.001; #end
#ifndef (RE_Split_union) #declare RE_Split_union = off; #end

//=============================== JOINT MACROS =================================

#macro RE_Round_join (RPost, rBlob)
   RE__check_neg ("RE_Round_join", "post radius", RPost)
   RE__check_neg ("RE_Round_join", "blob radius", rBlob)
   difference
   {  cylinder { -RE_ABIT * y, rBlob * y, RPost + rBlob }
      torus { RPost + rBlob, rBlob translate rBlob * y }
   }
#end

#macro RE_Straight_join_x (Start, End_x, rBlob, Dir)
   #local re_This = "RE_Straight_join_x"
   #local re_Scale = (End_x - Start) * x + <0, rBlob, rBlob>;
   RE__check_neg (re_This, "blob radius", rBlob)
   RE__check0 (re_This, "width", re_Scale.x)
   difference
   {  box { -<0, RE_ABIT, RE_ABIT>, 1 }
      cylinder { <-RE_ABIT, 1, 1>, <RE_MORE, 1, 1>, 1 }
      rotate Dir * x
      scale re_Scale
      translate Start
   }
#end

#macro RE_Straight_join_y (Start, End_y, rBlob, Dir)
   #local re_This = "RE_Straight_join_y"
   #local re_Scale = (End_y - Start) * y + <rBlob, 0, rBlob>;
   RE__check_neg (re_This, "blob radius", rBlob)
   RE__check0 (re_This, "height", re_Scale.y)
   difference
   {  box { -<RE_ABIT, 0, RE_ABIT>, 1 }
      cylinder { <1, -RE_ABIT, 1>, <1, RE_MORE, 1>, 1 }
      rotate Dir * y
      scale re_Scale
      translate Start
   }
#end

#macro RE_Straight_join_z (Start, End_z, rBlob, Dir)
   #local re_This = "RE_Straight_join_z"
   #local re_Scale = (End_z - Start) * z + <rBlob, rBlob, 0>;
   RE__check_neg (re_This, "blob radius", rBlob)
   RE__check0 (re_This, "depth", re_Scale.z)
   difference
   {  box { -<RE_ABIT, RE_ABIT, 0>, 1 }
      cylinder { <1, 1, -RE_ABIT>, <1, 1, RE_MORE>, 1 }
      rotate Dir * z
      scale re_Scale
      translate Start
   }
#end

//================================ EDGE MACRO ==================================

#macro RE_Parabolic_torus (H, R)
   RE__check1 ("RE_Parabolic_torus", R)
   quartic
   { <H*H, 0, 0, 0, 0, 0, -2*H, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
      0, 0, 1, 0, -R*R>
      sturm
   }
#end

//============================ ROUNDED BOX MACROS ==============================

#macro RE_Box (A, B, rEdge, Use_merge)
   RE__check1 ("RE_Box", rEdge) //As of v3.6.1, Round_Box() does the other checks
   object
   {  Round_Box (<0,0,0> + A, <0,0,0> + B, rEdge, Use_merge)
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
#end

//---------------- rounded along one axis ------------------

#macro RE__box_axis (vA, vB, rEdge, Use_merge) 

   #if (Use_merge)
      #local re_Fuzz = vlength (vB - vA) * RE_ABIT;
      #local re_Base = merge
   #else
      #local re_Fuzz = 0;
      union
   #end
   {  #local re_AOut = <min (vA.x, vB.x), min (vA.y, vB.y) - re_Fuzz, min (vA.z, vB.z)>;
      #local re_BOut = <max (vA.x, vB.x), max (vA.y, vB.y) + re_Fuzz, max (vA.z, vB.z)>;
      #local re_AIn = re_AOut + rEdge;
      #local re_BIn = re_BOut - rEdge;
      #local re_Corner = cylinder { re_AOut * y, re_BOut * y, rEdge }
      #if (re_AOut.z != re_BOut.z) box { <re_AIn.x, re_AOut.y, re_AOut.z>, <re_BIn.x, re_BOut.y, re_BOut.z> } #end
      #if (re_AOut.x != re_BOut.x) box { <re_AOut.x, re_AOut.y, re_AIn.z>, <re_BOut.x, re_BOut.y, re_BIn.z> } #end
      #if (re_AIn.x != re_BIn.x & re_AIn.z != re_BIn.z) object { re_Corner translate <re_AIn.x, 0, re_AIn.z> } #end
      #if (re_AIn.x != re_BIn.x) object { re_Corner translate <re_AIn.x, 0, re_BIn.z> } #end
      #if (re_AIn.z != re_BIn.z) object { re_Corner translate <re_BIn.x, 0, re_AIn.z> } #end
      object { re_Corner translate <re_BIn.x, 0, re_BIn.z> }
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
   #if (Use_merge) //shear off the coincident surfaces
      intersection
      {  object { re_Base }
         box { <re_AOut.x, re_BOut.y, re_AOut.z> - re_Fuzz, <re_BOut.x, re_AOut.y, re_BOut.z> + re_Fuzz }
      }
   #end
#end

#macro RE_Box_x (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_x"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   #if (re_vA.x = re_vB.x) RE__error (re_This, "width") #end
   object
   {  RE__box_axis (<re_vA.y, -re_vA.x, re_vA.z>, <re_vB.y, -re_vB.x, re_vB.z>, rEdge, Use_merge)
      rotate 90 * z
   }
#end

#macro RE_Box_y (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_y"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   #if (re_vA.y = re_vB.y) RE__error (re_This, "height") #end
   RE__box_axis (re_vA, re_vB, rEdge, Use_merge)
#end

#macro RE_Box_z (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_z"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   #if (re_vA.z = re_vB.z) RE__error (re_This, "depth") #end
   object
   {  RE__box_axis (<re_vA.x, re_vA.z, -re_vA.y>, <re_vB.x, re_vB.z, -re_vB.y>, rEdge, Use_merge)
      rotate 90 * x
   }
#end

//------------------ rounded on one end --------------------

#macro RE__box_end (A, B, rEdge, Use_merge)

   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_Base = #if (Use_merge) merge #else union #end
   {  #local re_AOut = <min (re_vA.x, re_vB.x), min (re_vA.y, re_vB.y), min (re_vA.z, re_vB.z)>;
      #local re_BOut = <max (re_vA.x, re_vB.x), max (re_vA.y, re_vB.y), max (re_vA.z, re_vB.z)>;
      #local re_BIn = re_BOut - rEdge;
      #local re_AIn = <re_AOut.x + rEdge, re_AOut.y - (Use_merge? rEdge * RE_ABIT: 0), re_AOut.z + rEdge>;

      sphere { <re_BIn.x, re_BIn.y, re_BIn.z>, rEdge }
      #if (re_AIn.x != re_BIn.x)
         sphere { <re_AIn.x, re_BIn.y, re_BIn.z>, rEdge }
         cylinder { <re_AIn.x, re_BIn.y, re_BIn.z>, <re_BIn.x, re_BIn.y, re_BIn.z>, rEdge }
      #end
      #if (re_AIn.z != re_BIn.z)
         sphere { <re_BIn.x, re_BIn.y, re_AIn.z>, rEdge }
         cylinder { <re_BIn.x, re_BIn.y, re_AIn.z>, <re_BIn.x, re_BIn.y, re_BIn.z>, rEdge }
      #end
      #if (re_AIn.z != re_BIn.z & re_AIn.x != re_BIn.x)
         sphere { <re_AIn.x, re_BIn.y, re_AIn.z>, rEdge }
         cylinder { <re_AIn.x, re_BIn.y, re_AIn.z>, <re_AIn.x, re_BIn.y, re_BIn.z>, rEdge }
         cylinder { <re_AIn.x, re_BIn.y, re_AIn.z>, <re_BIn.x, re_BIn.y, re_AIn.z>, rEdge }
         box { <re_AIn.x, re_BIn.y, re_AIn.z>, <re_BIn.x, re_BOut.y, re_BIn.z> }
      #end
      #if (re_AOut.y < re_BIn.y)
         cylinder { <re_BIn.x, re_BIn.y, re_BIn.z>, <re_BIn.x, re_AIn.y, re_BIn.z>, rEdge }
      #end
      #if (re_AOut.y < re_BIn.y & re_AIn.x != re_BIn.x)
         cylinder { <re_AIn.x, re_BIn.y, re_BIn.z>, <re_AIn.x, re_AIn.y, re_BIn.z>, rEdge }
         box { <re_AIn.x, re_AIn.y, re_AOut.z>, <re_BIn.x, re_BIn.y, re_BOut.z> }
      #end
      #if (re_AOut.y < re_BIn.y & re_AIn.z != re_BIn.z)
         cylinder { <re_BIn.x, re_BIn.y, re_AIn.z>, <re_BIn.x, re_AIn.y, re_AIn.z>, rEdge }
         box { <re_AOut.x, re_AIn.y, re_AIn.z>, <re_BOut.x, re_BIn.y, re_BIn.z> }
      #end
      #if (re_AOut.y < re_BIn.y & re_AIn.z != re_BIn.z & re_AIn.x != re_BIn.x)
         cylinder { <re_AIn.x, re_BIn.y, re_AIn.z>, <re_AIn.x, re_AIn.y, re_AIn.z>, rEdge }
      #end
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
   #if (Use_merge //then shear off the coincident surface
      | re_AOut.y > re_BIn.y - rEdge) //then crop protruding cylinders and spheres
      difference { object { re_Base } plane { y, re_AOut.y } }
   #else
      object { re_Base }
   #end
#end

#macro RE_Box_up (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_up"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 1)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   RE__box_end (re_vA, re_vB, rEdge, Use_merge)
#end

#macro RE_Box_down (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_down"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 1)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   object
   {  RE__box_end (<re_vA.x, -re_vA.y, re_vA.z>, <re_vB.x, -re_vB.y, re_vB.z>, rEdge, Use_merge)
      scale <1, -1, 1>
   }
#end

#macro RE_Box_right (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_right"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 1)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   object
   {  RE__box_end (<-re_vA.y, re_vA.x, re_vA.z>, <-re_vB.y, re_vB.x, re_vB.z>, rEdge, Use_merge)
      rotate -90 * z
   }
#end

#macro RE_Box_left (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_left"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 1)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   object
   {  RE__box_end (<re_vA.y, -re_vA.x, re_vA.z>, <re_vB.y, -re_vB.x, re_vB.z>, rEdge, Use_merge)
      rotate 90 * z
   }
#end

#macro RE_Box_near (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_near"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 1)
   object
   {  RE__box_end (<re_vA.x, -re_vA.z, re_vA.y>, <re_vB.x, -re_vB.z, re_vB.y>, rEdge, Use_merge)
      rotate -90 * x
   }
#end

#macro RE_Box_far (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_far"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 1)
   object
   {  RE__box_end (<re_vA.x, re_vA.z, -re_vA.y>, <re_vB.x, re_vB.z, -re_vB.y>, rEdge, Use_merge)
      rotate 90 * x
   }
#end

//---------- rounded on one side along one axis ------------

#macro RE__box_side (vA, vB, rEdge, Use_merge)

   #if (Use_merge)
      #local re_Fuzz = rEdge * RE_ABIT;
      #local re_Base = merge
   #else
      #local re_Fuzz = 0;
      #local re_Base = union
   #end
   {  #local re_AOut = <min (vA.x, vB.x), min (vA.y, vB.y), min (vA.z, vB.z)>;
      #local re_BOut = <max (vA.x, vB.x), max (vA.y, vB.y), max (vA.z, vB.z)>;
      #local re_BIn = <re_BOut.x + re_Fuzz, re_BOut.y - rEdge, re_BOut.z - rEdge>;
      #local re_AIn = <re_AOut.x - re_Fuzz, re_BIn.y - re_Fuzz, re_AOut.z + rEdge>;

      #if (re_AOut.y < re_BIn.y)
         box { <re_AIn.x, min (re_AOut.y, re_BIn.y - rEdge), re_AOut.z>, <re_BIn.x, re_BIn.y, re_BOut.z> }
      #end
      #if (re_AIn.z != re_BIn.z)
         box { re_AIn, <re_BIn.x, re_BOut.y, re_BIn.z> }
         cylinder { <re_AIn.x, re_BIn.y, re_AIn.z>, <re_BIn.x, re_BIn.y, re_AIn.z>, rEdge }
      #end
      cylinder { <re_AIn.x, re_BIn.y, re_BIn.z>, re_BIn, rEdge }
      
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
   #if (Use_merge) //shear off the coincident surface
      intersection
      {  object { re_Base }
         box { re_AOut - <0, re_Fuzz, re_Fuzz>, re_BOut + <0, re_Fuzz, re_Fuzz> }
      }
   #else#if (re_AOut.y > re_BIn.y - rEdge) //crop protruding cylinders
      difference
      {  object { re_Base }
         plane { y, re_AOut.y }
      }
   #else
      object { re_Base }
   #end#end
#end

#macro RE_Box_x_up (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_x_up"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 1)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   #if (re_vA.x = re_vB.x) RE__error (re_This, "width") #end
   RE__box_side (re_vA, re_vB, rEdge, Use_merge)
#end

#macro RE_Box_x_down (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_x_down"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 1)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   #if (re_vA.x = re_vB.x) RE__error (re_This, "width") #end
   object
   {  RE__box_side (<re_vA.x, -re_vA.y, re_vA.z>, <re_vB.x, -re_vB.y, re_vB.z>, rEdge, Use_merge)
      scale <1, -1, 1>
   }
#end

#macro RE_Box_x_near (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_x_near"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 1)
   #if (re_vA.x = re_vB.x) RE__error (re_This, "width") #end
   object
   {  RE__box_side (<re_vA.x, -re_vA.z, re_vA.y>, <re_vB.x, -re_vB.z, re_vB.y>, rEdge, Use_merge)
      rotate -90 * x
   }
#end

#macro RE_Box_x_far (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_x_far"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 1)
   #if (re_vA.x = re_vB.x) RE__error (re_This, "width") #end
   object
   {  RE__box_side (<re_vA.x, re_vA.z, -re_vA.y>, <re_vB.x, re_vB.z, -re_vB.y>, rEdge, Use_merge)
      rotate 90 * x
   }
#end

#macro RE_Box_y_right (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_y_right"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 1)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   #if (re_vA.y = re_vB.y) RE__error (re_This, "height") #end
   object
   {  RE__box_side (<-re_vA.y, re_vA.x, re_vA.z>, <-re_vB.y, re_vB.x, re_vB.z>, rEdge, Use_merge)
      rotate -90 * z
   }
#end

#macro RE_Box_y_left (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_y_left"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 1)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
   #if (re_vA.y = re_vB.y) RE__error (re_This, "height") #end
   object
   {  RE__box_side (<re_vA.y, -re_vA.x, re_vA.z>, <re_vB.y, -re_vB.x, re_vB.z>, rEdge, Use_merge)
      rotate 90 * z
   }
#end

#macro RE_Box_y_near (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_y_near"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 1)
   #if (re_vA.y = re_vB.y) RE__error (re_This, "height") #end
   object
   {  RE__box_side (<re_vA.y, -re_vA.z, -re_vA.x>, <re_vB.y, -re_vB.z, -re_vB.x>, rEdge, Use_merge)
      rotate <-90, 0, 90>
   }
#end

#macro RE_Box_y_far (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_y_far"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 1)
   #if (re_vA.y = re_vB.y) RE__error (re_This, "height") #end
   object
   {  RE__box_side (<re_vA.y, re_vA.z, re_vA.x>, <re_vB.y, re_vB.z, re_vB.x>, rEdge, Use_merge)
      rotate <90, 0, 90>
   }
#end

#macro RE_Box_z_up (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_z_up"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 1)
   #if (re_vA.z = re_vB.z) RE__error (re_This, "depth") #end
   object
   {  RE__box_side (<-re_vA.z, re_vA.y, re_vA.x>, <-re_vB.z, re_vB.y, re_vB.x>, rEdge, Use_merge)
      rotate 90 * y
   }
#end

#macro RE_Box_z_down (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_z_down"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 1)
   #if (re_vA.z = re_vB.z) RE__error (re_This, "depth") #end
   object
   {  RE__box_side (<re_vA.z, -re_vA.y, re_vA.x>, <re_vB.z, -re_vB.y, re_vB.x>, rEdge, Use_merge)
      rotate <0, -90, 180>
   }
#end

#macro RE_Box_z_right (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_z_right"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 1)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   #if (re_vA.z = re_vB.z) RE__error (re_This, "depth") #end
   object
   {  RE__box_side (<re_vA.z, re_vA.x, re_vA.y>, <re_vB.z, re_vB.x, re_vB.y>, rEdge, Use_merge)
      rotate <-90, -90, 0>
   }
#end

#macro RE_Box_z_left (A, B, rEdge, Use_merge)
   #local re_vA = <0,0,0> + A;
   #local re_vB = <0,0,0> + B;
   #local re_This = "RE_Box_z_left"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 1)
   RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
   #if (re_vA.z = re_vB.z) RE__error (re_This, "depth") #end
   object
   {  RE__box_side (<-re_vA.z, -re_vA.x, re_vA.y>, <-re_vB.z, -re_vB.x, re_vB.y>, rEdge, Use_merge)
      rotate <-90, 90, 0>
   }
#end

//========================= ROUNDED CYLINDER MACROS ============================

#macro RE_Cylinder (A, B, ROuter, rEdge, Use_merge)
   #local re_Axis = vlength (A - B);
  //handle degenerate cases not recognized by Round_Cylinder()
   #local re_This = "RE_Cylinder"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 2)
   #if (2 * rEdge = re_Axis & rEdge = ROuter)
      sphere { (A + B) / 2, rEdge }
   #else#if (2 * rEdge = re_Axis & rEdge < ROuter)
      #if (Use_merge) merge #else union #end
      {  cylinder { A, B, ROuter - rEdge }
         torus { ROuter - rEdge, rEdge Point_At_Trans (B - A) translate (A + B) / 2 }
         #if (!Use_merge & !RE_Split_union) split_union off #end
      }
   #else#if (2 * rEdge != re_Axis & rEdge = ROuter)
      #if (Use_merge) merge #else union #end
      {  sphere { rEdge * y, rEdge }
         sphere { (re_Axis - rEdge) * y, rEdge }
         cylinder { rEdge * y, (re_Axis - rEdge) * y, ROuter }
         Point_At_Trans (B - A) translate A
         #if (!Use_merge & !RE_Split_union) split_union off #end
      }
  //default to Round_Cylinder()
   #else
      object
      {  Round_Cylinder (<0,0,0> + A, <0,0,0> + B, ROuter, rEdge, Use_merge)
         #if (!Use_merge & !RE_Split_union) split_union off #end
      }
   #end#end#end
#end

//----------------------------------------------------------

#macro RE_Cylinder_end (A, B, ROuter, rEdge, Use_merge)

   #local re_Axis = vlength (A - B);
   #local re_This = "RE_Cylinder_end"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 1)
   RE__check2 (re_This, "Radius", 0, ROuter, rEdge, 1)
   #if (re_Axis = 0) RE__error (re_This, "Axis length") #end

   #if (re_Axis >= 2 * rEdge)
      #if (Use_merge) merge #else union #end
      {  cylinder { rEdge * y, re_Axis * y, ROuter }
         #if (rEdge = ROuter)
            sphere { y, 1 scale rEdge } //degenerate torus
         #else
            cylinder { 0, rEdge * RE_MORE * y, ROuter - rEdge }
            torus { ROuter - rEdge, rEdge translate rEdge * y }
         #end
         Point_At_Trans (B - A) translate A
         #if (!Use_merge & !RE_Split_union) split_union off #end
      }
   #else
      intersection
      {  #if (re_Axis <= rEdge & rEdge = ROuter) object
         #else#if (Use_merge) merge
         #else union
         #end#end
         {  #if (re_Axis > rEdge) cylinder { rEdge * y, re_Axis * y, ROuter } #end
            #if (rEdge = ROuter)
               sphere { y, 1 scale rEdge } //degenerate torus
            #else
               cylinder { 0, rEdge * 2 * y, ROuter - rEdge }
               torus { ROuter - rEdge, rEdge translate rEdge * y }
            #end
         }
         plane { y, re_Axis }
         Point_At_Trans (B - A) translate A
      }
   #end
#end

//----------------------------------------------------------

#macro RE__hole (A, B, ROuter, RInner, rEdge, Use_merge)
   #local re_Axis = vlength (A - B);
   #local re_Base = #if (Use_merge) merge #else union #end
   {  difference
      {  cylinder { 0, re_Axis * y, max (ROuter, RInner + 2*rEdge) }
         cylinder { -RE_ABIT * y, re_Axis * RE_MORE * y, RInner + rEdge }
      }
      #if (re_Axis != 2*rEdge)
         difference
         {  cylinder { rEdge * y, (re_Axis - rEdge) * y, RInner + rEdge * RE_MORE }
            cylinder { rEdge * RE_LESS * y, (re_Axis - rEdge * RE_LESS) * y, RInner }
         }
         torus { RInner + rEdge, rEdge translate (re_Axis - rEdge) * y }
      #end
      torus { RInner + rEdge, rEdge translate rEdge * y }
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
   #if (ROuter < RInner + 2*rEdge)
      #local re_Base = intersection
      {  object { re_Base }
         cylinder { -RE_ABIT * y, re_Axis * RE_MORE * y, ROuter }
      }
   #end
   object { re_Base Point_At_Trans (B - A) translate A }
#end

#macro RE_Hole (A, B, ROuter, RInner, rEdge, Use_merge)
   #local re_Axis = vlength (A - B);
   #local re_This = "RE_Hole"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 2)
   RE__check3 (re_This, RInner, ROuter, rEdge, 1)
   #if (re_Axis = 0) RE__error (re_This, "axis length") #end
   RE__hole (A, B, ROuter, RInner, rEdge, Use_merge)
#end

#macro RE_Hole_minimal (A, B, RInner, rEdge, Use_merge)
   #local re_Axis = vlength (A - B);
   #local re_This = "RE_Hole_minimal"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 2)
   #if (re_Axis = 0) RE__error (re_This, "axis length") #end
   RE__hole (A, B, (RInner + rEdge) * sqrt(2), RInner, rEdge, Use_merge)
#end

//----------------------------------------------------------

#macro RE__hole_end (A, B, ROuter, RInner, rEdge, Use_merge)
   #local re_Axis = vlength (A - B);
   #local re_Extent = (ROuter < RInner + 2*rEdge | Use_merge?
                       re_Axis * RE_MORE: max (re_Axis, 2*rEdge));
   #local re_Base = #if (Use_merge) merge #else union #end
   {  difference
      {  cylinder { 0, re_Extent * y, max (ROuter, RInner + 2*rEdge) }
         cylinder { -RE_ABIT * y, re_Extent * RE_MORE * y, RInner + rEdge }
      }
      #if (re_Axis > rEdge)
         difference
         {  cylinder { rEdge * y, re_Extent * y, RInner + rEdge * RE_MORE }
            cylinder { rEdge * RE_LESS * y, re_Extent * RE_MORE * y, RInner }
         }
      #end
      torus { RInner + rEdge, rEdge translate rEdge * y }
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
   #if (ROuter < RInner + 2*rEdge)
      #local re_Base = intersection
      {  object { re_Base }
         cylinder { -RE_ABIT * y, re_Axis * y, ROuter }
      }
   #else#if (re_Axis < 2*rEdge | Use_merge)
      #local re_Base = intersection { object { re_Base } plane { y, re_Axis } }
   #end#end
   object { re_Base Point_At_Trans (B - A) translate A }
#end

#macro RE_Hole_end (A, B, ROuter, RInner, rEdge, Use_merge)
   #local re_Axis = vlength (A - B);
   #local re_This = "RE_Hole_end"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 1)
   RE__check3 (re_This, RInner, ROuter, rEdge, 1)
   #if (re_Axis = 0) RE__error (re_This, "axis length") #end
   RE__hole_end (A, B, ROuter, RInner, rEdge, Use_merge)
#end

#macro RE_Hole_end_minimal (A, B, RInner, rEdge, Use_merge)
   #local re_Axis = vlength (A - B);
   #local re_This = "RE_Hole_end_minimal"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 1)
   #if (re_Axis = 0) RE__error (re_This, "axis length") #end
   RE__hole_end (A, B, (RInner + rEdge) * sqrt(2), RInner, rEdge, Use_merge)
#end

//----------------------------------------------------------

#macro RE_Washer (A, B, ROuter, RInner, rEdge, Use_merge)

   #local re_Axis = vlength (A - B);
   #local re_This = "RE_Washer"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 2)
   RE__check3 (re_This, RInner, ROuter, rEdge, 2)
   #if (re_Axis = 0) RE__error (re_This, "axis length") #end

   #if (Use_merge) merge #else union #end
   {  #if (re_Axis != 2*rEdge)
         difference
         {  cylinder { rEdge * y, (re_Axis - rEdge) * y, ROuter }
            cylinder { rEdge * RE_LESS * y, (re_Axis - rEdge * RE_LESS) * y, RInner }
         }
         torus { ROuter - rEdge, rEdge translate (re_Axis - rEdge) * y }
      #end
      #if (ROuter != RInner + 2*rEdge)
         difference
         {  cylinder { 0, re_Axis * y, ROuter - rEdge }
            cylinder { -RE_ABIT * y, re_Axis * RE_MORE * y, RInner + rEdge }
         }
         torus { RInner + rEdge, rEdge translate rEdge * y }
      #end
      #if (re_Axis != 2*rEdge & ROuter != RInner + 2*rEdge)
         torus { RInner + rEdge, rEdge translate (re_Axis - rEdge) * y }
      #end
      torus { ROuter - rEdge, rEdge translate rEdge * y }
      Point_At_Trans (B - A)
      translate A
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
#end

//----------------------------------------------------------

#macro RE_Washer_end (A, B, ROuter, RInner, rEdge, Use_merge)

   #local re_Axis = vlength (A - B);
   #local re_Extent = max (re_Axis, 2*rEdge);
   #local re_This = "RE_Washer_end"
   RE__check1 (re_This, rEdge)
   RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 1)
   RE__check3 (re_This, RInner, ROuter, rEdge, 2)
   #if (re_Axis = 0) RE__error (re_This, "axis length") #end

   #local re_Base = #if (Use_merge) merge #else union #end
   {  #if (re_Axis > rEdge)
      difference
      {  cylinder { rEdge * y, re_Extent * y, ROuter }
         cylinder { rEdge * RE_LESS * y, re_Extent * RE_MORE * y, RInner }
      }
      #end
      #if (ROuter != RInner + 2*rEdge)
         difference
         {  cylinder { 0, RE_MORE * rEdge * y, ROuter - rEdge }
            cylinder { -RE_ABIT * y, RE_MORE * RE_MORE * rEdge * y, RInner + rEdge }
         }
         torus { RInner + rEdge, rEdge translate rEdge * y }
      #end
      torus { ROuter - rEdge, rEdge translate rEdge * y }
      Point_At_Trans (B - A)
      translate A
      #if (!Use_merge & !RE_Split_union) split_union off #end
   }
   #if (re_Axis < 2*rEdge)
      intersection
      {  object { re_Base }
         plane { y, re_Axis }
      }
   #else
      object { re_Base }
   #end
#end

//=========================== ISOSURFACE FUNCTIONS =============================

#declare RE_fn_Blob = function (RE_P0_Value, RE_P1_Blob)
{  select (RE_P1_Blob - RE_P0_Value, 0,
           pow (1 + (1 - pow (RE_P0_Value + 1, 2)) / (pow (RE_P1_Blob + 1, 2) - 1), 2))
}

#declare RE_fn_Blob2 = function (RE_P0_Value, RE_P1_Blob)
{  select (RE_P1_Blob - RE_P0_Value, 0,
           pow ((RE_P1_Blob - RE_P0_Value) / RE_P1_Blob, 2))
}

#declare RE_fn_Parabolic_torus = function (x, y, z, RE_P0_H, RE_P1_R)
{  sqrt (pow(z,2) + pow(y,2) - 2*RE_P0_H * y * pow (x, 2) + pow (RE_P0_H * x*x, 2))
 - RE_P1_R
}

#declare RE_fn_Wheel = function (x, y, z, RE_P0_RMajor, RE_P1_rMinor)
{  select (pow(x,2) + pow(z,2) - pow(RE_P0_RMajor,2),
      max (y - RE_P1_rMinor, -RE_P1_rMinor - y),
      f_torus (x, y, z, RE_P0_RMajor, RE_P1_rMinor))
}

#declare RE_fn_Hole = function (x, y, z, RE_P0_RMajor, RE_P1_rMinor)
{  select (pow(x,2) + pow(z,2) - pow(RE_P0_RMajor,2),
      f_torus (x, y, z, RE_P0_RMajor, RE_P1_rMinor),
      max (y - RE_P1_rMinor, -RE_P1_rMinor - y))
}

//========================== BLOB ASSIST FUNCTIONS =============================

#declare RE_fn_Blob_distance = function (RE_P0_Radius, RE_P1_Strength)
{  RE_P0_Radius * sqrt (1 - 1 / sqrt (RE_P1_Strength))
}

#declare RE_fn_Blob_radius = function (RE_P0_Distance, RE_P1_Strength)
{  RE_P0_Distance / sqrt (1 - 1 / sqrt (RE_P1_Strength))
}

#declare RE_fn_Blob_strength = function (RE_P0_Distance, RE_P1_Radius)
{  1 / pow (1 - pow (RE_P0_Distance / RE_P1_Radius, 2), 2)
}

//==============================================================================

#version ROUNDEDGE_INC;
#end
