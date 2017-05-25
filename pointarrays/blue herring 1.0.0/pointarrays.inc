// Title:        PointArrays
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   May 22, 2008
// Last updated: June 5, 2008
//
// This file is licensed under the terms of the CC-LGPL

#ifndef(PointArrays_Inc)
#declare PointArrays_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including pointarrays.inc\n"
#end

#include "math.inc"
#include "shapes.inc"

// Spline type constants

#declare PA_Linear    = 1;
#declare PA_Quadratic = 2;
#declare PA_Cubic     = 3;
#declare PA_Bezier    = 4;
#declare PA_B         = 5;
#declare PA_Natural   = 6;

// Sweep type constants

#declare PA_Linear_Sweep = 1;
#declare PA_Conic_Sweep  = 7;

// Null transform

#declare PA_No_Trans = transform {}

// PA_Is_Closed
// Returns true if the array of points represents a closed spline, false otherwise.
//  Spline_Type - Type of spline the array represents.  One of the above constants.
//  Points      - Array of point vectors.
//
#macro PA_Is_Closed(Spline_Type, Points)
  #local Last = dimension_size(Points, 1) - 1;
  
  #if(Spline_Type = PA_Linear
      | Spline_Type = PA_Bezier
      | Spline_Type = PA_B
      | Spline_Type = PA_Natural)
      
    #local P1 = Points[0] * <1, 1, 1>;
    #local P2 = Points[Last] * <1, 1, 1>;
    
  #else
  
    #if(Spline_Type = PA_Quadratic)
    
      #local P1 = Points[1] * <1, 1, 1>;
      #local P2 = Points[Last] * <1, 1, 1>;

    #else    
      #if(Spline_Type = PA_Cubic)
        #local P1 = Points[1] * <1, 1, 1>;
        #local P2 = Points[Last - 1] * <1, 1, 1>;
      
      #else
        #error "PA_Is_Closed: Invalid spline type.\n"
      #end
    #end
  #end
  
  VEq(P1, P2)
#end  

// PA_Lathe
// Creates a lathe object from an array of points.
//  Spline_Type - Type of spline represented by the point array.
//  Points      - Array of point vectors.
//  Sturm       - Boolean. If true, the "sturm" flag is enabled for the lathe.
//  Trans       - Transformation to apply to each point before creating the lathe. For
//                example, applying different amounts of x translation allows lathes
//                of different diameter to be created from the same set of points.
//
#macro PA_Lathe(Spline_Type, Points, Sturm, Trans)
  #if(Spline_Type != PA_Linear 
      & Spline_Type != PA_Quadratic 
      & Spline_Type != PA_Cubic
      & Spline_Type != PA_Bezier)
    #error "PA_Lathe: Invalid spline type.\n"
  #end
  
  #local Count = dimension_size(Points, 1);
  #local Ct = 0;

  #local Trans_F = 
    function {
      transform { Trans }
    }
    
  lathe {
    PA_Spline_Type(Spline_Type)
    Count, 
    #while(Ct < Count)
      #local Pt = Points[Ct] * <1, 1, 1>;
      #local TPt = (Trans_F(Pt.x, Pt.y, Pt.z));
      <TPt.x, TPt.y>
      #if(Ct < Count - 1) , #end
      #local Ct = Ct + 1;
    #end
    #if(Sturm)
      sturm
    #end
  }
#end

// PA_Lathe_Arc
// Creates a lathe cut into a sector of a specific angle.
//  Spline_Type, Points, Sturm, Trans - Same as for PA_Lathe
//  Angle                             - Angle in degrees of the arc.  The arc will 
//                                    - start at the +x axis and wrap around towards +z.
//
#macro PA_Lathe_Arc(Spline_Type, Points, Sturm, Trans, Angle)

  #local L = PA_Lathe(Spline_Type, Points, Sturm, Trans)

  #if(Angle >= 360)
    L
  #else
    #local Min = min_extent(L);
    #local Max = max_extent(L);
    #local O_Pt = vrotate(x * Max.x, y * -Angle);  
    #local BX_Min = select(Angle - 180, min(0, O_Pt.x), Min.x);
    #local BZ_Min = min(0, O_Pt.z);
    #local BZ_Max = select(Angle - 90, O_Pt.z, Max.z);
    
    intersection {
      object { L }
      #if(Angle > 180)
        union {
      #end
      plane { -z, 0}
      plane {
        z, 0
        rotate y * -Angle
      }
      #if(Angle > 180)
        }
      #end
      bounded_by {
        box { <BX_Min, Min.y, BZ_Min>, <Max.x, Max.y, BZ_Max> }
      }
    }
  #end
#end

// PA_Prism
// Creates a prism object from an array of points.
//  Spline_Type - Type of spline the array represents.
//  Sweep_Type  - Type of prism sweep to use.
//  Height_1    - First height value of prism.
//  Height_2    - Second height value of prism.
//  Points      - Array of point vectors.
//  Sturm       - Boolean to enable/disable the "sturm" flag.
//  Open        - Boolean to enable/disable open caps on the prism.
//  Trans       - Transformation to apply to each point before creating the prism.
//
#macro PA_Prism(Spline_Type, Sweep_Type, Height_1, Height_2, Points, Sturm, Open, Trans)
  #if(Spline_Type != PA_Linear 
      & Spline_Type != PA_Quadratic 
      & Spline_Type != PA_Cubic
      & Spline_Type != PA_Bezier)
    #error "PA_Prism: Invalid spline type.\n"
  #end
  
  #local Count = dimension_size(Points, 1);
  #local Ct = 0;
  
  #local Trans_F = 
    function {
      transform { Trans }
    }
    
  prism {
    PA_Spline_Type(Spline_Type)
    PA_Sweep_Type(Sweep_Type)
    Height_1, Height_2,
    Count,
    #while(Ct < Count)
      #local Pt = Points[Ct] * <1, 1, 1>;
      #local TPt = (Trans_F(Pt.x, Pt.y, Pt.z));
      <TPt.x, TPt.y>
      #if(Ct < Count - 1) , #end
      #local Ct = Ct + 1;
    #end
    #if(Sturm)
      sturm
    #end
    #if(Open)
      open
    #end
  }
#end

// PA_Prism_Scaled
// Simplifies creating a conic prism with a specific height, and specific end sizes.  The
// resulting object will rest at the origin, and extent Height units in the +y direction.
// The end at the origin will be scaled by Scale_1, and the end at Height will be scaled by 
// Scale_2.
//  Spline_Type - Type of spline represented by the array.
//  Height      - Overall height of the final prism.
//  Scale_1     - Float scale factor of the bottom of the prism.
//  Scale_2     - Float scale factor of the top of the prism.
//  Points      - Array of point vectors.
//  Sturm       - Boolean to enable/disable the "sturm" flag.
//  Open        - Boolean to enable/disable open caps on the prism.
//  Trans       - Transform to apply to each point before creating the prism.
//
#macro PA_Prism_Scaled(Spline_Type, Height, Scale_1, Scale_2, Points, Sturm, Open, Trans)
  object {
    PA_Prism(Spline_Type, PA_Conic_Sweep, Scale_1, Scale_2, Points, Sturm, Open, Trans)
    #if(Scale_1 > Scale_2)
      scale <1, -1, 1>
      translate y * Scale_1
    #else
      translate y * -Scale_2
    #end
    scale <1, Height/abs(Scale_1 - Scale_2), 1>
  }
#end

// PA_Sphere_Sweep
// Creates a sphere_sweep object from an array of points.
//  Spline_Type - Type of spline represented by the array.
//  Points      - Array of point vectors.
//  Radius      - If Radius <= 0, then the radius of each sphere in the sweep will be taken
//                from the t value of each point vector (the fourth element of the vector.)
//                This will end up being zero if the input points have fewer than four
//                dimensions.
//                If Radius > 0 then the t values will be ignored, and Radius will be used as
//                a constant radius value for all spheres in the sweep.
//  Trans       - Transform to apply to each point before creating the sweep.  Note this will
//                not affect the t values.
//
// Additional parameter:
//  PA_Sphere_Sweep_Tolerance - If this variable is defined, it will be used as the "tolerance"
//                              value for the sweep.  Otherwise the default will be used.
//
#macro PA_Sphere_Sweep(Spline_Type, Points, Radius, Trans)
  #if(Spline_Type != PA_Linear
      & Spline_Type != PA_Cubic
      & Spline_Type != PA_B)
    #error "PA_Sphere_Sweep: Invalid spline type.\n"
  #end
  
  #local Count = dimension_size(Points, 1);
  #local Ct = 0;

  #local Trans_F = 
    function {
      transform { Trans }
    }
    
  sphere_sweep {
    PA_Spline_Type(Spline_Type)
    Count,
    #while(Ct < Count)
      #local Pt = Points[Ct] * <1, 1, 1, 1>;
      #local TPt = (Trans_F(Pt.x, Pt.y, Pt.z));
      #local R = select(Radius, Pt.t, Pt.t, Radius);
      <TPt.x, TPt.y, TPt.z>, R
      #if(Ct < Count - 1) , #end
      #local Ct = Ct + 1;
    #end
    #ifdef(PA_Sphere_Sweep_Tolerance)
      tolerance PA_Sphere_Sweep_Tolerance
    #end
  }
#end

// PA_Bezier_Sweep
// Creates a sphere_sweep-like object that follows a 3D bezier spline.
//  Points     - Array of points describing a series of cubic bezier curve segments.
//  Radius     - If Radius <= 0, then the radius of each sphere in the sweep will be taken
//               from the t value of each point (the fourth element of the vector.)  This
//               applies to endpoints and control points, and the radii will be interpolated
//               as appropriate for a cubic bezier.
//               If Radius > 0 then the t values will be ignored, and Radius will be used as
//               a constant radius value for all spheres in the sweep.
//  Trans      - Transform to apply to each point before creating the sweep.  Note this will not
//               affect the t values.
//  Resolution - The object created is actually a union/merge of spheres connected by cones.
//               This controls how many connected spheres are used for each segment of the
//               spline (each set of two endpoints and two control points.)  The higher the number
//               the smoother the appearance.
//  Use_Merge  - Boolean.  True the object is a merge, false it is a union.
//
#macro PA_Bezier_Sweep(Points, Radius, Trans, Resolution, Use_Merge)
  #local Count = dimension_size(Points, 1);
  
  #if(mod(Count, 4) != 0)
    #error "PA_Bezier_Sweep: Number of points must be a multiple of 4.\n"
  #end
  
  #local Trans_F =
    function {
      transform { Trans }
    }
  
  #local Ct = 0;
  #local First = yes;

  #if(Use_Merge)
  merge {
  #else
  union {
  #end
    #while(Ct < Count)
      #local Ct_2 = 0;
      #while(Ct_2 < Resolution)
        #local T = Ct_2 / (Resolution - 1);
        
        #local Pt_1 = Points[Ct] * <1, 1, 1, 1>;
        #local Pt_2 = Points[Ct + 1] * <1, 1, 1, 1>;
        #local Pt_3 = Points[Ct + 2] * <1, 1, 1, 1>;
        #local Pt_4 = Points[Ct + 3] * <1, 1, 1, 1>;
        
        #local TPt_1 = Trans_F(Pt_1.x, Pt_1.y, Pt_1.z);
        #local TPt_2 = Trans_F(Pt_2.x, Pt_2.y, Pt_2.z);
        #local TPt_3 = Trans_F(Pt_3.x, Pt_3.y, Pt_3.z);
        #local TPt_4 = Trans_F(Pt_4.x, Pt_4.y, Pt_4.z);
        
        #local Pt_1 = <TPt_1.x, TPt_1.y, TPt_1.z, Pt_1.t>;
        #local Pt_2 = <TPt_2.x, TPt_2.y, TPt_2.z, Pt_2.t>;
        #local Pt_3 = <TPt_3.x, TPt_3.y, TPt_3.z, Pt_3.t>;
        #local Pt_4 = <TPt_4.x, TPt_4.y, TPt_4.z, Pt_4.t>;
        
        #local Pt = (pow(1 - T, 3) * Pt_1 +
                     3 * T * pow(1 - T, 2) * Pt_2 +
                     3 * pow(T, 2) * (1 -T) * Pt_3 +
                     pow(T, 3) * Pt_4);
        
        #if(Radius > 0)
          #local Pt = <Pt.x, Pt.y, Pt.z, Radius>;
        #end
        
        #if(First)
          #local Prev = Pt;
        #end
        
        #local Moved = (Pt.x != Prev.x | Pt.y != Prev.y | Pt.z != Prev.z);
        
        #if(Moved | Pt.t != Prev.t | First)
          sphere { <Pt.x, Pt.y, Pt.z>, Pt.t }
        #end
        
        #if(Moved)
          Connect_Spheres(<Prev.x, Prev.y, Prev.z>, Prev.t, <Pt.x, Pt.y, Pt.z>, Pt.t)
        #end
        
        #local Prev = Pt;
        #local First = no;
        #local Ct_2 = Ct_2 + 1;
      #end
      #local Ct = Ct + 4;
    #end
  }
#end

#macro PA_Spline_Type(Type)
  #switch(Type)
    #case(PA_Linear)
      linear_spline
    #break
    
    #case(PA_Quadratic)
      quadratic_spline
    #break
    
    #case(PA_Cubic)
      cubic_spline
    #break
    
    #case(PA_Bezier)
      bezier_spline
    #break
    
    #case(PA_B)
      b_spline
    #break
    
    #case(PA_Natural)
      natural_spline
    #break
    
    #else
      #error "PA_Spline_Type: Invalid spline type\n"
  #end
#end

#macro PA_Sweep_Type(Sweep_Type)
  #switch(Sweep_Type)
    #case(PA_Linear_Sweep)
      linear_sweep
    #break
      
    #case(PA_Conic_Sweep)
      conic_sweep
    #break
    
    #else
      #error "PA_Sweep_Type: Invalid sweep type.\n"
  #end
#end

#version PointArrays_Inc;
#end
