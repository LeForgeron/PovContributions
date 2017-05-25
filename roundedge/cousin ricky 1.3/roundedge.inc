/* roundedge.inc version 1.3
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Macros and functions to facilitate rounded CSG joints and edges.
 * Based on various functions and macros that I wrote, dating back to 2004.
 *
 * Copyright 2008 - 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       12-jul-2008  Compiled from old include files.
 *       24-aug-2008  Adapted for object collection save fn_Oblong_torus().
 *                    (fn_Oblong_torus() is on my hard disk; don't look for it
 *                    anywhere.)
 * 1.0   02-sep-2008  Local variable names are brought into compliance.
 *       07-jun-2012  Added RE_Round_inside_join().
 *       08-jun-2012  Added RE_Corner_join().
 * 1.1   09-jun-2012  Uploaded (incomplete upload).
 *       17-jul-2012  Tested for 3.5 compatibility.
 *       03-sep-2012  Added version identifier.
 *       27-feb-2013  Added elliptical torus macros.
 * 1.2   01-mar-2013  Uploaded (incomplete upload).
 * 1.3   15-jum-2013  Blob functions are renamed.
 */
#ifndef (ROUNDEDGE_INC) #declare ROUNDEDGE_INC = version;
#version 3.5;
#declare ROUNDEDGE_VERSION = 1.3;

#include "functions.inc"
#include "transforms.inc"
#include "shapes.inc"
#debug "#include \"roundedge.inc\" //version 1.3\n"

//============================== ERROR HANDLING ================================

//N.B. In my personal experience, the error checking is *necessary*.

//Converts a number to a string of a fixed number of /significant/ digits.  This
//is in contrast to str(), which returns a requested number of /decimal/ digits.
//Returns: the string.
#macro RE__str (Number)
  #local re_Sig = 3;
  #if (Number * 1e10 = 0) str (0, 1, re_Sig - 1) //1e10 helps avoid the epsilon
  #else str (Number, 1, max (re_Sig - floor(log(abs(Number))) - 1, 0))
  #end
#end

//Throws a fatal error if a value is zero.
#macro RE__error0 (Caller, Side)
  #error concat (Caller, "(): Zero ", Side, ".\n")
#end

//Warns if a value is zero.
#macro RE__check0 (Caller, Desc, Side)
  #if (Side = 0) #warning concat (Caller, "(): Zero ", Desc, ".\n") #end
#end

//Warns if a value is negative.
#macro RE__check_neg (Caller, Desc, Edge)
  #if (Edge < 0)
    #warning concat
    ( Caller, "(): The ", Desc, " (", RE__str(Edge),
      ") is negative. The result is undefined.\n"
    )
  #end
#end

//Warns if the edge radius is negative.
#macro RE__check1 (Caller, rEdge)
  RE__check_neg (Caller, "edge radius", rEdge)
#end

//Warns if a value is too small compared to the edge radius.
#macro RE__check2 (Caller, Side, Dim1, Dim2, rEdge, Constraint)
  #local re_Dim = abs (Dim2 - Dim1);
  #if (re_Dim < rEdge * Constraint)
    #warning concat
    ( Caller, "(): ", Side, " (", RE__str(re_Dim), ") is less than ",
      #if (Constraint = 2) "twice ", #end
      "the edge radius (", RE__str(rEdge), "). The result is undefined.\n"
    )
  #end
#end

//Warns if a value is less than the blob radius.
#macro RE__check2b (Caller, Side, Dim1, Dim2, rEdge)
  #local re_Dim = abs (Dim2 - Dim1);
  #if (re_Dim < rEdge)
    #warning concat
    ( Caller, "(): The ", Side, " (", RE__str(re_Dim),
      ") is less than the blob radius (", RE__str(rEdge),
      "). The result is undefined.\n"
    )
  #end
#end

//Warns if the parameters don't make sense compared to each other.
#macro RE__check3 (Caller, RInner, ROuter, rEdge, Constraint)
  #if (RInner > ROuter)
    #warning concat
    (Caller, "(): The outer radius (", RE__str(ROuter),
      ") is less than the inner radius (", RE__str(RInner),
      "). The result is undefined.\n"
    )
  #else#if (ROuter - RInner < rEdge * Constraint)
    #warning concat
    ( Caller, "(): The difference between the outer radius (", RE__str(ROuter),
      ") and the inner radius (", RE__str(RInner), ") is less than ",
      #if (Constraint = 2) "twice ", #end
      "the edge radius (", RE__str(rEdge), "). The result is undefined.\n"
    )
  #end#end
#end

//Warns if a value is too small.
//(Note: Min must be an integer to avoid a misleading message.)
//Returns: the value, corrected if necessary.
#macro RE__check_res (Caller, Value_name, Given, Min)
( #if (Given < Min)
    #warning concat
    ( Caller, "(): ", Value_name, " (", RE__str(Given), ") is less than ",
      str(Min,0,0), "; ", str(Min,0,0), " is substituted.\n"
    )
    Min
  #else
    Given
  #end
)
#end

#ifndef (re__ETdebug) #declare re__ETdebug = off; #end

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
  { cylinder { -RE_ABIT * y, rBlob * y, RPost + rBlob }
    torus { RPost + rBlob, rBlob translate rBlob * y }
  }
#end

#macro RE_Round_inside_join (RHollow, rBlob)
  #local re_This = "RE_Round_inside_join"
  RE__check_neg (re_This, "radius of the hollow", RHollow)
  RE__check_neg (re_This, "blob radius", rBlob)
  RE__check2b (re_This, "radius of the hollow", 0, RHollow, rBlob)
  difference
  { cylinder { -RE_ABIT * y, max (0, rBlob) * y, RHollow + RE_ABIT }
    #if (rBlob = RHollow)
      sphere { y, 1 scale rBlob }
    #else
      torus { RHollow - rBlob, rBlob translate rBlob * y }
      #if (rBlob * 1.5 > RHollow) //delete inner part of torus
        sphere { y, 1 scale <2*rBlob - RHollow, rBlob, 2*rBlob - RHollow> }
      #end
      #if (rBlob < RHollow)
        cylinder { -2*RE_ABIT * y, (rBlob + RE_ABIT) * y, RHollow - rBlob }
      #end
    #end
  }
  //Note: the max() and the last #if directive are there to avoid a potential
  //degenerate cylinder error.  These precautions won't affect the output if
  //the arguments are legit.
#end

#macro RE_Straight_join_x (v_Start, End_x, rBlob, Dir)
  #local re_This = "RE_Straight_join_x"
  #local re_Scale = (End_x - v_Start) * x + <0, rBlob, rBlob>;
  RE__check_neg (re_This, "blob radius", rBlob)
  RE__check0 (re_This, "width", re_Scale.x)
  difference
  { box { -<0, RE_ABIT, RE_ABIT>, 1 }
    cylinder { <-RE_ABIT, 1, 1>, <RE_MORE, 1, 1>, 1 }
    rotate Dir * x
    scale re_Scale
    translate v_Start
  }
#end

#macro RE_Straight_join_y (v_Start, End_y, rBlob, Dir)
  #local re_This = "RE_Straight_join_y"
  #local re_Scale = (End_y - v_Start) * y + <rBlob, 0, rBlob>;
  RE__check_neg (re_This, "blob radius", rBlob)
  RE__check0 (re_This, "height", re_Scale.y)
  difference
  { box { -<RE_ABIT, 0, RE_ABIT>, 1 }
    cylinder { <1, -RE_ABIT, 1>, <1, RE_MORE, 1>, 1 }
    rotate Dir * y
    scale re_Scale
    translate v_Start
  }
#end

#macro RE_Straight_join_z (v_Start, End_z, rBlob, Dir)
  #local re_This = "RE_Straight_join_z"
  #local re_Scale = (End_z - v_Start) * z + <rBlob, rBlob, 0>;
  RE__check_neg (re_This, "blob radius", rBlob)
  RE__check0 (re_This, "depth", re_Scale.z)
  difference
  { box { -<RE_ABIT, RE_ABIT, 0>, 1 }
    cylinder { <1, 1, -RE_ABIT>, <1, 1, RE_MORE>, 1 }
    rotate Dir * z
    scale re_Scale
    translate v_Start
  }
#end

#macro RE_Corner_join (rBlob)
  RE__check_neg ("RE_Corner_join", "blob radius", rBlob)
  difference
  { box { -RE_ABIT, rBlob }
    sphere { rBlob, rBlob }
  }
#end

//=============================== EDGE MACROS ==================================

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

//---------------------------- elliptical toroids ------------------------------

#macro RE__elliptorus_point (RxMajor, RzMajor, rMinor, Theta, Phi)
  #local re_Radj = rMinor * cos(Phi);
  < (RxMajor + re_Radj) * cos(Theta),
    rMinor * sin(Phi),
    (RzMajor + re_Radj) * sin(Theta)
  >
#end

#macro RE__elliptorus_normal (RxMajor, RzMajor, rMinor, Theta, Phi)
( #local RE_NEAR = 0.001;
  #local re_N =
    RE__elliptorus_point (RxMajor, RzMajor, rMinor, Theta, Phi + RE_NEAR);
  #local re_S =
    RE__elliptorus_point (RxMajor, RzMajor, rMinor, Theta, Phi - RE_NEAR);
  #local re_E =
    RE__elliptorus_point (RxMajor, RzMajor, rMinor, Theta + RE_NEAR, Phi);
  #local re_W =
    RE__elliptorus_point (RxMajor, RzMajor, rMinor, Theta - RE_NEAR, Phi);
  vnormalize (vcross (re_E - re_N, re_W - re_N))
+ vnormalize (vcross (re_N - re_W, re_S - re_W))
+ vnormalize (vcross (re_W - re_S, re_E - re_S))
+ vnormalize (vcross (re_S - re_E, re_N - re_E))
)
#end

#macro RE_Elliptorus_mesh (RxMajor, RzMajor, rMinor, ThetaRes, PhiRes)
  #local re_Ntheta =
    RE__check_res ("RE_Elliptorus_mesh", "ThetaRes", ThetaRes, 4);
  #local re_Nphi =
    RE__check_res ("RE_Elliptorus_mesh", "PhiRes", PhiRes, 4);
  mesh2
  { vertex_vectors
    { re_Ntheta * re_Nphi,
      #local re_V = 0;
      #while (re_V < re_Nphi)
        #local re_U = 0;
        #while (re_U < re_Ntheta)
          RE__elliptorus_point
          ( RxMajor, RzMajor, rMinor,
            re_U/re_Ntheta * 2*pi, re_V/re_Nphi * 2*pi
          )
          #local re_U = re_U + 1;
        #end
        #local re_V = re_V + 1;
      #end
    }
    #if (rMinor != 0)
      normal_vectors
      { re_Ntheta * re_Nphi,
        #local re_V = 0;
        #while (re_V < re_Nphi)
          #local re_U = 0;
          #while (re_U < re_Ntheta)
            RE__elliptorus_normal
            ( RxMajor, RzMajor, rMinor,
              re_U/re_Ntheta * 2*pi, re_V/re_Nphi * 2*pi
            )
            #local re_U = re_U + 1;
          #end
          #local re_V = re_V + 1;
        #end
      }
    #end
    face_indices
    { re_Ntheta * re_Nphi * 2,
      #local re_V = 0;
      #while (re_V < re_Nphi)
        #local re_Base = re_V * re_Ntheta;
        #local re_Next = mod (re_V+1, re_Nphi) * re_Ntheta;
        #local re_U = 0;
        #while (re_U < re_Ntheta)
          #local re_U1 = mod (re_U+1, re_Ntheta);
          <re_Base + re_U, re_Base + re_U1, re_Next + re_U1>
          <re_Base + re_U, re_Next + re_U1, re_Next + re_U>
          #local re_U = re_U + 1;
        #end
        #local re_V = re_V + 1;
      #end
    }
   //Advice has been given to avoid inside_vector parallel to any face (which
   //makes sense). I have not been able to force adverse consequences, but I'm
   //not taking the chance.
    inside_vector vtransform
    ( x,
      transform
      { rotate degrees (1/re_Nphi) * z
        rotate degrees (1/re_Ntheta) * y
        scale <1, 1, RzMajor/RxMajor>
      }
    )
  }
#end

#macro RE_Elliptorus_octant (RxMajor, RzMajor, rMinor, ThetaRes, PhiRes)
  #local re_thRes =
    RE__check_res ("RE_Elliptorus_octant", "ThetaRes", ThetaRes, 1);
  #local re_phRes =
    RE__check_res ("RE_Elliptorus_octant", "PhiRes", PhiRes, 2);
  #local re_Ntheta = re_thRes+1;
  #local re_Nphi = re_phRes+2;
  mesh2
  { vertex_vectors
    { re_Ntheta * re_Nphi,
      #local re_V = 0;
      #while (re_V <= re_phRes)
        #local re_U = 0;
        #while (re_U <= re_thRes)
          RE__elliptorus_point
          ( RxMajor, RzMajor, rMinor,
            re_U * pi / (2 * re_thRes), re_V * pi / re_phRes
          )
          #local re_U = re_U + 1;
        #end
        #local re_V = re_V + 1;
      #end
      #local re_U = 0;
      #while (re_U <= re_thRes)
        #local re_Theta = re_U * pi / (2 * re_thRes);
        <cos(re_Theta) * RxMajor, 0, sin(re_Theta) * RzMajor> - RE_ABIT
        #local re_U = re_U + 1;
      #end
    }
    #if (rMinor != 0 & !re__ETdebug)
      normal_vectors
      { re_Ntheta * re_Nphi,
        #local re_V = 0;
        #while (re_V <= re_phRes)
          #local re_U = 0;
          #while (re_U <= re_thRes)
            RE__elliptorus_normal
            ( RxMajor, RzMajor, rMinor,
              re_U * pi / (2 * re_thRes), re_V * pi / re_phRes
            )
            #local re_U = re_U + 1;
          #end
          #local re_V = re_V + 1;
        #end
        #local re_U = 0;
        #while (re_U <= re_thRes)
          , -y
          #local re_U = re_U + 1;
        #end
      }
    #end
    face_indices
    { re_thRes * re_Nphi * 2 + re_phRes * 2,
      #local re_V = 0;
      #while (re_V < re_Nphi)
        #local re_Base = re_V * re_Ntheta;
        #local re_Next = mod (re_V+1, re_Nphi) * re_Ntheta;
        #local re_U = 0;
        #while (re_U < re_thRes)
          <re_Base + re_U, re_Base + re_U+1, re_Next + re_U+1>
          <re_Base + re_U, re_Next + re_U+1, re_Next + re_U>
          #local re_U = re_U + 1;
        #end
        #local re_V = re_V + 1;
      #end
      #local re_V = 0;
      #while (re_V < re_phRes)
        <re_Ntheta * (re_Nphi-1), re_V * re_Ntheta, (re_V+1) * re_Ntheta>
        #local re_V = re_V + 1;
        <re_Ntheta * re_Nphi, re_V * re_Ntheta, (re_V+1) * re_Ntheta> - 1
      #end
    }
   //Advice has been given to avoid inside_vector parallel to any face (which
   //makes sense). I have not been able to force adverse consequences, but I'm
   //not taking the chance.
    inside_vector
      vrotate (x, degrees ((floor (re_Nphi / 2) * pi + 1) / re_Nphi) * z)
  }
#end

//============================ ROUNDED BOX MACROS ==============================

#macro RE_Box (A, B, rEdge, Use_merge)
  RE__check1 ("RE_Box", rEdge)
  //Round_Box() does the other checks, at least from 3.5 through 3.7.
  object
  { Round_Box (<0,0,0> + A, <0,0,0> + B, rEdge, Use_merge)
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
  { #local re_AOut = <min (vA.x, vB.x), min (vA.y, vB.y) - re_Fuzz, min (vA.z, vB.z)>;
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
    { object { re_Base }
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
  #if (re_vA.x = re_vB.x) RE__error0 (re_This, "width") #end
  object
  { RE__box_axis (<re_vA.y, -re_vA.x, re_vA.z>, <re_vB.y, -re_vB.x, re_vB.z>, rEdge, Use_merge)
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
  #if (re_vA.y = re_vB.y) RE__error0 (re_This, "height") #end
  RE__box_axis (re_vA, re_vB, rEdge, Use_merge)
#end

#macro RE_Box_z (A, B, rEdge, Use_merge)
  #local re_vA = <0,0,0> + A;
  #local re_vB = <0,0,0> + B;
  #local re_This = "RE_Box_z"
  RE__check1 (re_This, rEdge)
  RE__check2 (re_This, "Width", re_vA.x, re_vB.x, rEdge, 2)
  RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 2)
  #if (re_vA.z = re_vB.z) RE__error0 (re_This, "depth") #end
  object
  { RE__box_axis (<re_vA.x, re_vA.z, -re_vA.y>, <re_vB.x, re_vB.z, -re_vB.y>, rEdge, Use_merge)
    rotate 90 * x
  }
#end

//------------------ rounded on one end --------------------

#macro RE__box_end (A, B, rEdge, Use_merge)

  #local re_vA = <0,0,0> + A;
  #local re_vB = <0,0,0> + B;
  #local re_Base = #if (Use_merge) merge #else union #end
  { #local re_AOut = <min (re_vA.x, re_vB.x), min (re_vA.y, re_vB.y), min (re_vA.z, re_vB.z)>;
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
  { RE__box_end (<re_vA.x, -re_vA.y, re_vA.z>, <re_vB.x, -re_vB.y, re_vB.z>, rEdge, Use_merge)
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
  { RE__box_end (<-re_vA.y, re_vA.x, re_vA.z>, <-re_vB.y, re_vB.x, re_vB.z>, rEdge, Use_merge)
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
  { RE__box_end (<re_vA.y, -re_vA.x, re_vA.z>, <re_vB.y, -re_vB.x, re_vB.z>, rEdge, Use_merge)
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
  { RE__box_end (<re_vA.x, -re_vA.z, re_vA.y>, <re_vB.x, -re_vB.z, re_vB.y>, rEdge, Use_merge)
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
  { RE__box_end (<re_vA.x, re_vA.z, -re_vA.y>, <re_vB.x, re_vB.z, -re_vB.y>, rEdge, Use_merge)
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
  { #local re_AOut = <min (vA.x, vB.x), min (vA.y, vB.y), min (vA.z, vB.z)>;
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
    { object { re_Base }
      box { re_AOut - <0, re_Fuzz, re_Fuzz>, re_BOut + <0, re_Fuzz, re_Fuzz> }
    }
  #else#if (re_AOut.y > re_BIn.y - rEdge) //crop protruding cylinders
    difference
    { object { re_Base }
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
  #if (re_vA.x = re_vB.x) RE__error0 (re_This, "width") #end
  RE__box_side (re_vA, re_vB, rEdge, Use_merge)
#end

#macro RE_Box_x_down (A, B, rEdge, Use_merge)
  #local re_vA = <0,0,0> + A;
  #local re_vB = <0,0,0> + B;
  #local re_This = "RE_Box_x_down"
  RE__check1 (re_This, rEdge)
  RE__check2 (re_This, "Height", re_vA.y, re_vB.y, rEdge, 1)
  RE__check2 (re_This, "Depth", re_vA.z, re_vB.z, rEdge, 2)
  #if (re_vA.x = re_vB.x) RE__error0 (re_This, "width") #end
  object
  { RE__box_side (<re_vA.x, -re_vA.y, re_vA.z>, <re_vB.x, -re_vB.y, re_vB.z>, rEdge, Use_merge)
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
  #if (re_vA.x = re_vB.x) RE__error0 (re_This, "width") #end
  object
  { RE__box_side (<re_vA.x, -re_vA.z, re_vA.y>, <re_vB.x, -re_vB.z, re_vB.y>, rEdge, Use_merge)
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
  #if (re_vA.x = re_vB.x) RE__error0 (re_This, "width") #end
  object
  { RE__box_side (<re_vA.x, re_vA.z, -re_vA.y>, <re_vB.x, re_vB.z, -re_vB.y>, rEdge, Use_merge)
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
  #if (re_vA.y = re_vB.y) RE__error0 (re_This, "height") #end
  object
  { RE__box_side (<-re_vA.y, re_vA.x, re_vA.z>, <-re_vB.y, re_vB.x, re_vB.z>, rEdge, Use_merge)
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
  #if (re_vA.y = re_vB.y) RE__error0 (re_This, "height") #end
  object
  { RE__box_side (<re_vA.y, -re_vA.x, re_vA.z>, <re_vB.y, -re_vB.x, re_vB.z>, rEdge, Use_merge)
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
  #if (re_vA.y = re_vB.y) RE__error0 (re_This, "height") #end
  object
  { RE__box_side (<re_vA.y, -re_vA.z, -re_vA.x>, <re_vB.y, -re_vB.z, -re_vB.x>, rEdge, Use_merge)
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
  #if (re_vA.y = re_vB.y) RE__error0 (re_This, "height") #end
  object
  { RE__box_side (<re_vA.y, re_vA.z, re_vA.x>, <re_vB.y, re_vB.z, re_vB.x>, rEdge, Use_merge)
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
  #if (re_vA.z = re_vB.z) RE__error0 (re_This, "depth") #end
  object
  { RE__box_side (<-re_vA.z, re_vA.y, re_vA.x>, <-re_vB.z, re_vB.y, re_vB.x>, rEdge, Use_merge)
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
  #if (re_vA.z = re_vB.z) RE__error0 (re_This, "depth") #end
  object
  { RE__box_side (<re_vA.z, -re_vA.y, re_vA.x>, <re_vB.z, -re_vB.y, re_vB.x>, rEdge, Use_merge)
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
  #if (re_vA.z = re_vB.z) RE__error0 (re_This, "depth") #end
  object
  { RE__box_side (<re_vA.z, re_vA.x, re_vA.y>, <re_vB.z, re_vB.x, re_vB.y>, rEdge, Use_merge)
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
  #if (re_vA.z = re_vB.z) RE__error0 (re_This, "depth") #end
  object
  { RE__box_side (<-re_vA.z, -re_vA.x, re_vA.y>, <-re_vB.z, -re_vB.x, re_vB.y>, rEdge, Use_merge)
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
    { cylinder { A, B, ROuter - rEdge }
      torus { ROuter - rEdge, rEdge Point_At_Trans (B - A) translate (A + B) / 2 }
      #if (!Use_merge & !RE_Split_union) split_union off #end
    }
  #else#if (2 * rEdge != re_Axis & rEdge = ROuter)
    #if (Use_merge) merge #else union #end
    { sphere { rEdge * y, rEdge }
      sphere { (re_Axis - rEdge) * y, rEdge }
      cylinder { rEdge * y, (re_Axis - rEdge) * y, ROuter }
      Point_At_Trans (B - A) translate A
      #if (!Use_merge & !RE_Split_union) split_union off #end
    }
//default to Round_Cylinder()
  #else
    object
    { Round_Cylinder (<0,0,0> + A, <0,0,0> + B, ROuter, rEdge, Use_merge)
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
  #if (re_Axis = 0) RE__error0 (re_This, "Axis length") #end

  #if (re_Axis >= 2 * rEdge)
    #if (Use_merge) merge #else union #end
    { cylinder { rEdge * y, re_Axis * y, ROuter }
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
    { #if (re_Axis <= rEdge & rEdge = ROuter) object
      #else#if (Use_merge) merge
      #else union
      #end#end
      { #if (re_Axis > rEdge) cylinder { rEdge * y, re_Axis * y, ROuter } #end
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
  { difference
    { cylinder { 0, re_Axis * y, max (ROuter, RInner + 2*rEdge) }
      cylinder { -RE_ABIT * y, re_Axis * RE_MORE * y, RInner + rEdge }
    }
    #if (re_Axis != 2*rEdge)
      difference
      { cylinder { rEdge * y, (re_Axis - rEdge) * y, RInner + rEdge * RE_MORE }
        cylinder { rEdge * RE_LESS * y, (re_Axis - rEdge * RE_LESS) * y, RInner }
      }
      torus { RInner + rEdge, rEdge translate (re_Axis - rEdge) * y }
    #end
    torus { RInner + rEdge, rEdge translate rEdge * y }
    #if (!Use_merge & !RE_Split_union) split_union off #end
  }
  #if (ROuter < RInner + 2*rEdge)
    #local re_Base = intersection
    { object { re_Base }
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
  #if (re_Axis = 0) RE__error0 (re_This, "axis length") #end
  RE__hole (A, B, ROuter, RInner, rEdge, Use_merge)
#end

#macro RE_Hole_minimal (A, B, RInner, rEdge, Use_merge)
  #local re_Axis = vlength (A - B);
  #local re_This = "RE_Hole_minimal"
  RE__check1 (re_This, rEdge)
  RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 2)
  #if (re_Axis = 0) RE__error0 (re_This, "axis length") #end
  RE__hole (A, B, (RInner + rEdge) * sqrt(2), RInner, rEdge, Use_merge)
#end

//----------------------------------------------------------

#macro RE__hole_end (A, B, ROuter, RInner, rEdge, Use_merge)
  #local re_Axis = vlength (A - B);
  #local re_Extent = (ROuter < RInner + 2*rEdge | Use_merge?
                      re_Axis * RE_MORE: max (re_Axis, 2*rEdge));
  #local re_Base = #if (Use_merge) merge #else union #end
  { difference
    { cylinder { 0, re_Extent * y, max (ROuter, RInner + 2*rEdge) }
      cylinder { -RE_ABIT * y, re_Extent * RE_MORE * y, RInner + rEdge }
    }
    #if (re_Axis > rEdge)
      difference
      { cylinder { rEdge * y, re_Extent * y, RInner + rEdge * RE_MORE }
        cylinder { rEdge * RE_LESS * y, re_Extent * RE_MORE * y, RInner }
      }
    #end
    torus { RInner + rEdge, rEdge translate rEdge * y }
    #if (!Use_merge & !RE_Split_union) split_union off #end
  }
  #if (ROuter < RInner + 2*rEdge)
    #local re_Base = intersection
    { object { re_Base }
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
  #if (re_Axis = 0) RE__error0 (re_This, "axis length") #end
  RE__hole_end (A, B, ROuter, RInner, rEdge, Use_merge)
#end

#macro RE_Hole_end_minimal (A, B, RInner, rEdge, Use_merge)
  #local re_Axis = vlength (A - B);
  #local re_This = "RE_Hole_end_minimal"
  RE__check1 (re_This, rEdge)
  RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 1)
  #if (re_Axis = 0) RE__error0 (re_This, "axis length") #end
  RE__hole_end (A, B, (RInner + rEdge) * sqrt(2), RInner, rEdge, Use_merge)
#end

//----------------------------------------------------------

#macro RE_Washer (A, B, ROuter, RInner, rEdge, Use_merge)

  #local re_Axis = vlength (A - B);
  #local re_This = "RE_Washer"
  RE__check1 (re_This, rEdge)
  RE__check2 (re_This, "Axis length", 0, re_Axis, rEdge, 2)
  RE__check3 (re_This, RInner, ROuter, rEdge, 2)
  #if (re_Axis = 0) RE__error0 (re_This, "axis length") #end

  #if (Use_merge) merge #else union #end
  { #if (re_Axis != 2*rEdge)
      difference
      { cylinder { rEdge * y, (re_Axis - rEdge) * y, ROuter }
        cylinder { rEdge * RE_LESS * y, (re_Axis - rEdge * RE_LESS) * y, RInner }
      }
      torus { ROuter - rEdge, rEdge translate (re_Axis - rEdge) * y }
    #end
    #if (ROuter != RInner + 2*rEdge)
      difference
      { cylinder { 0, re_Axis * y, ROuter - rEdge }
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
  #if (re_Axis = 0) RE__error0 (re_This, "axis length") #end

  #local re_Base = #if (Use_merge) merge #else union #end
  { #if (re_Axis > rEdge)
    difference
    { cylinder { rEdge * y, re_Extent * y, ROuter }
      cylinder { rEdge * RE_LESS * y, re_Extent * RE_MORE * y, RInner }
    }
    #end
    #if (ROuter != RInner + 2*rEdge)
      difference
      { cylinder { 0, RE_MORE * rEdge * y, ROuter - rEdge }
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
    { object { re_Base }
      plane { y, re_Axis }
    }
  #else
    object { re_Base }
  #end
#end

//=========================== ISOSURFACE FUNCTIONS =============================

#declare RE_fn_Blob = function (RE_P0_Value, RE_P1_Blob)
{ select
  ( RE_P1_Blob - RE_P0_Value, 0,
    pow (1 + (1 - pow (RE_P0_Value + 1, 2)) / (pow (RE_P1_Blob + 1, 2) - 1), 2)
  )
}

#declare RE_fn_Blob2 = function (RE_P0_Value, RE_P1_Blob)
{ select
  ( RE_P1_Blob - RE_P0_Value, 0,
    pow ((RE_P1_Blob - RE_P0_Value) / RE_P1_Blob, 2)
  )
}

#declare RE_fn_Parabolic_torus = function (x, y, z, RE_P0_H, RE_P1_R)
{ sqrt
  ( pow(z,2) + pow(y,2) - 2*RE_P0_H * y * pow(x,2) + pow (RE_P0_H * x*x, 2)
  ) - RE_P1_R
}

#declare RE_fn_Wheel = function (x, y, z, RE_P0_RMajor, RE_P1_rMinor)
{ select
  ( pow(x,2) + pow(z,2) - pow(RE_P0_RMajor,2),
    max (y - RE_P1_rMinor, -RE_P1_rMinor - y),
    f_torus (x, y, z, RE_P0_RMajor, RE_P1_rMinor)
  )
}

#declare RE_fn_Hole = function (x, y, z, RE_P0_RMajor, RE_P1_rMinor)
{ select
  ( pow(x,2) + pow(z,2) - pow(RE_P0_RMajor,2),
    f_torus (x, y, z, RE_P0_RMajor, RE_P1_rMinor),
    max (y - RE_P1_rMinor, -RE_P1_rMinor - y)
  )
}

//========================== BLOB ASSIST FUNCTIONS =============================

#declare RE_fn_Blob_surface_radius = function (RE_P0_RField, RE_P1_Strength)
{ RE_P0_RField * sqrt (1 - 1 / sqrt (RE_P1_Strength))
}

#declare RE_fn_Blob_field_radius = function (RE_P0_RSurface, RE_P1_Strength)
{ RE_P0_RSurface / sqrt (1 - 1 / sqrt (RE_P1_Strength))
}

#declare RE_fn_Blob_strength = function (RE_P0_RSurface, RE_P1_RField)
{ 1 / pow (1 - pow (RE_P0_RSurface / RE_P1_RField, 2), 2)
}

//--------------------- GRANDFATHER ------------------------

#declare RE_fn_Blob_distance = function (RE_P0_RField, RE_P1_Strength)
{ RE_fn_Blob_surface_radius (RE_P0_RField, RE_P1_Strength)
}

#declare RE_fn_Blob_radius = function (RE_P0_RSurface, RE_P1_Strength)
{ RE_fn_Blob_field_radius (RE_P0_RSurface, RE_P1_Strength)
}

//==============================================================================

#version ROUNDEDGE_INC;
#end
