// Title:        PointArrays
// Version:      1.1.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   May 22, 2008
// Last updated: June 16, 2008
//
// This file is licensed under the terms of the CC-LGPL

#ifndef(Point_Arrays_Inc)
#declare Point_Arrays_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including point_arrays.inc\n"
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

// PA_Bezier_To_Linear
// Takes an array representing a bezier spline and returns it converted to a linear spline.
//  Points      - Array of point vectors.
//  Use_Control - Boolean.  If false, then the control points will be dropped and the result
//                will be a linear spline connecting the endpoints only.  If true, the
//                control points will be included in the result.

#macro PA_Bezier_To_Linear(Points, Use_Control)
  
  #local Count = dimension_size(Points, 1);
  
  #if(mod(Count, 4) != 0)
    #error "PA_Bezier_To_Linear: Number of input points should be a multiple of four.\n"
  #end

  #if(Use_Control)
    #local LCount = Count/4 * 3 + 1;
  #else
    #local LCount = Count/4 + 1;
  #end
  
  #local Linear = array[LCount];
  
  #local Ct = 0;
  #local Ct2 = 0;
  #while(Ct < LCount - 1)
    #local Linear[Ct] = Points[Ct2];
    
    #if(Use_Control)
      #local Linear[Ct + 1] = Points[Ct2 + 1];
      #local Linear[Ct + 2] = Points[Ct2 + 2];
      #local Ct = Ct + 2;
    #end
    
    #local Ct = Ct + 1;
    #local Ct2 = Ct2 + 4;
  #end
  
  #local Linear[LCount - 1] = Points[Count - 1];
  
  Linear
#end

// PA_Linear_To_Bezier
// Accepts an array containing a linear spline and returns the equivalent bezier spline,
// optionally rounding the vertices of the original into smooth curves.
//  Points     - Array of point vectors.
//  Round_Size - The distance from each original vertex/corner at which the rounding stops.
//               Larger values will give larger rounded corners.  Zero will create sharp
//               corners identical to the original linear spline.  Generally this should be
//               smaller than the length of the smallest segment.
//  Round_Str  - Strength of the rounding.  This determines how long the control vectors are
//               for the endpoints of each corner.  Values above Round_Size/2 will produce more
//               pointed corners.  Values below Round_Size/2 will produce flatter corners. Zero
//               will make flat chamfered corners.  For near-circular corners see the 
//               PA_Linear_To_Bezier_Circ macro.
//               
#macro PA_Linear_To_Bezier(Points, Round_Size, Round_Str)

  #local Count = dimension_size(Points, 1);
  
  #local Closed = PA_Is_Closed(PA_Linear, Points);
  
  #local BCount = (Count - 1) * 4;
  
  #if(Round_Size != 0)
    #local BCount = BCount + ((Count - 2) * 4);
    #if(Closed)
      #local BCount =  BCount + 4;
    #end
  #end

  #local Bezier = array[BCount];
  
  #local Ct_L = 0;
  #local Ct_B = 0;
  #while(Ct_L < Count - 1)
    #local Pt_1 = Points[Ct_L] * <1, 1, 1>;
    #local Pt_2 = Points[mod(Ct_L + 1, Count)] * <1, 1, 1>;
    #local Pt_3 = Points[mod(Ct_L + 2, Count)] * <1, 1, 1>;
    
    #if(Ct_L > 0 | Closed)
      #local Bezier[Ct_B] = PA_Adj_Len(Pt_2, Pt_1, -Round_Size);
    #else
      #local Bezier[Ct_B] = Pt_1;
    #end

    #local Bezier[Ct_B + 1] = Bezier[Ct_B];
        
    #if(Ct_L < Count - 2 | Closed)
      #local Bezier[Ct_B + 2] = PA_Adj_Len(Pt_1, Pt_2, -Round_Size);
    #else
      #local Bezier[Ct_B + 2] = Pt_2;
    #end
      
    #local Bezier[Ct_B + 3] = Bezier[Ct_B + 2];
  
    #if(Round_Size != 0 & (Ct_L < Count - 2 | Closed))
      #local Bezier[Ct_B + 4] = Bezier[Ct_B + 2];
      #local Bezier[Ct_B + 5] = PA_Adj_Len(Pt_1, Bezier[Ct_B + 4], Round_Str);
      #if(Ct_B + 7 = BCount - 1)
        #local Bezier[Ct_B + 7] = Bezier[0];
        #local Bezier[Ct_B + 6] = PA_Adj_Len(Points[1], Bezier[Ct_B + 7], Round_Str);
      #else
        #local Bezier[Ct_B + 7] = PA_Adj_Len(Pt_3, Pt_2, -Round_Size);
        #local Bezier[Ct_B + 6] = PA_Adj_Len(Pt_3, Bezier[Ct_B + 7], Round_Str);
      #end
      #local Ct_B = Ct_B + 4;
    #end
    
    #local Ct_L = Ct_L + 1;
    #local Ct_B = Ct_B + 4;
          
  #end
  
  Bezier
#end

// PA_Linear_To_Bezier_Circ
// This is a shortcut for the PA_Linear_To_Bezier macro to produce near-circular corners,
// based on a given Round_Size.  
//
#macro PA_Linear_To_Bezier_Circ(Points, Round_Size)
  PA_Linear_To_Bezier(Points, Round_Size, Round_Size * (4 * (sqrt(2) - 1) / 3))
#end

// PA_Linear_To_Bezier2
// Similar to PA_Linear_To_Bezier, this macro converts an array representing a linear
// spline to a bezier spline.  
//  Points    - Array of point vectors.
//  Round_Str - Strength of the rounding.  The control vectors of each corner of the spline
//              will be adjusted to be symmetric.  This value sets the magnitude of the
//              control vectors.  If this is zero, then the bezier spline will be identical
//              to the original linear spline.
//
#macro PA_Linear_To_Bezier2(Points, Round_Str)

  #local Bezier = PA_Linear_To_Bezier(Points, 0, 0);
  
  #local Count = dimension_size(Bezier, 1);
  
  #local Ct = 0;
  #while(Ct < Count - 1)
    #if(VEq(Bezier[Ct], Bezier[select(Ct - 1, Count - 1, Ct - 1)]))
      #local Pt_1 = Bezier[select(Ct - 4, Count - 4, Ct - 4)] - Bezier[Ct];
      #local Pt_2 = Bezier[Ct + 3] - Bezier[Ct];
      #local Ctl = vnormalize(vcross(vcross(Pt_1, Pt_2), Pt_1 + Pt_2)) * Round_Str;
      #local Bezier[Ct + 1] = Ctl + Bezier[Ct];
      #local Bezier[select(Ct - 2, Count - 2, Ct - 2)] = -Ctl + Bezier[Ct];
    #end
    
    #local Ct = Ct + 4;
  #end
  
  Bezier
#end

// PA_Bezier_Length_Tolerance
// Any calculations of length involving bezier curves are approximations.  This value
// determines the margin of error tolerated when calculating bezier lengths.  Decreasing
// this will increase accuracy, but it will also increase parse time and memory usage,
// possibly dramatically.  The macros currently influenced by this variable are:
// PA_Bezier_Length and PA_Bezier_Spline_Uniform.
//
#declare PA_Bezier_Length_Tolerance = 0.01;

// PA_Bezier_Length
// Calculates the approximate total length of a bezier spline.  See the above 
// PA_Bezier_Length_Tolerance variable for comments on accuracy.
//  Points - Array of point vectors.
//
#macro PA_Bezier_Length(Points)
  
  #local Count = dimension_size(Points, 1);
  
  #local Length = 0;
  
  #local Ct = 0;
  #while(Ct < Count)
    #local Length = 
      Length + PA_Bezier_Curve_Length(Points[Ct], Points[Ct + 1], Points[Ct + 2], Points[Ct + 3]);
    #local Ct = Ct + 4;
  #end
  
  Length
#end

// PA_Bezier_Spline
// Simulates a spline object for a given bezier spline/array.  Given an array of points,
// indices, and a clock value, it will return the corresponding point on the spline.
//  Points - An array of point vectors.
//  Indices - An array of float values for the spline points.  Index values are specified
//            sequentially one per segment of the bezier spline.  The values represent the
//            endpoint of the clock range for that segment.  Thus for the array { 0.3, 0.6, 1 },
//            Indices[0] would represent the range [0, 0.3] for Points[0] .. Points[3],
//            Indices[1] would be the range (0.3, 0.6] for Points[4] .. Points[7], and 
//            Indices[2] would be the range (0.6, 1] for Points[8] .. Points[11].  Indices
//            should always have 1/4 the number of elements of Points, and should always be in
//            increasing order.  It is not recommended to repeat values, or to have the last
//            element be anything other than 1.  
// Clock    - Input clock parameter.  Using the index values, Clock will be used to locate
//            a point on the spline.
//
// Due to the nature of bezier curves, points will generally not be spaced evenly for evenly
// spaced clock values. If this is necessary please see PA_Bezier_Spline_Uniform.
//
#macro PA_Bezier_Spline(Points, Indices, Clock)

  #if(Clock < 0 | Clock > 1)
    #warning "PA_Bezier_Spline: Clock value out of range, clipping to [0, 1].\n"
  #end
  
  #local Clk = clip(Clock, 0, 1);

  #local Count = dimension_size(Points, 1);
  
  #if(mod(Count, 4) != 0)
    #error "PA_Bezier_Spline: Number of input points must be a multiple of four.\n"
  #end
  
  #local ICount = dimension_size(Indices, 1);
  
  #if(ICount != Count/4)
    #error "PA_Bezier_Spline: Number of indices must be 1/4 of the number of input points.\n"
  #end
    
  #local Low = 0;
  #local High = ICount;
  #while(Low < High)
    #local Mid = div(Low + High, 2);
    #if(Indices[Mid] < Clk)
      #local Low = Mid + 1;
    #else
      #local High = Mid;
    #end
  #end
  
  #if(Low >= ICount)
    #error "PA_Bezier_Spline: No result found.\n"
  #end
  
  #local Max = Indices[Low];
  #if(Low = 0)
    #local Min = 0;
  #else
    #local Min = Indices[Low - 1];
  #end
  
  #local T = adj_range2(Clk, Min, Max, 0, 1);
  
  #local Pt = (pow(1 - T, 3) * Points[Low * 4] +
               3 * T * pow(1 - T, 2) * Points[Low * 4 + 1] +
               3 * pow(T, 2) * (1 -T) * Points[Low * 4 + 2] +
               pow(T, 3) * Points[Low * 4 + 3]);
               
  Pt        
#end

// PA_Bezier_Spline_Auto
// This is a shortcut for PA_Bezier_Spline.  Indices are automatically generated so
// that each segment of the spline has the same index range length.  This macro is
// likely of limited usefullness.
//
#macro PA_Bezier_Spline_Auto(Points, Clock)
  
  #if(Clock < 0 | Clock > 1)
    #warning "PA_Bezier_Spline_Auto: Clock value out of range, clipping to [0, 1].\n"
  #end
  
  #local Clk = clip(Clock, 0, 1);

  #local Count = dimension_size(Points, 1);
  
  #if(mod(Count, 4) != 0)
    #error "PA_Bezier_Spline_Auto: Number of input points must be a multiple of four.\n"
  #end

  #local Indices = array[Count/4];
  
  #local Ct = 0;
  #while(Ct < Count/4)
    #local Indices[Ct] = (Ct + 1)/(Count/4);
    #local Ct = Ct + 1;
  #end
  
  PA_Bezier_Spline(Points, Indices, Clk)
#end  

// PA_Bezier_Spline_Uniform
// Similar to PA_Bezier_Spline, this macro simulates a spline object for a point array.
// The primary difference is that in this case, the clock value is directly proportional
// to the distance along the spline.  Thus points are spaced evenly.
//  Points - An array of point vectors.
//  Clock  - A float value from 0 to 1, which represents the relative distance along the
//           spline.  0 is the starting point, 1 the endpoint, and 0.5 halfway along.
//           See the variable PA_Bezier_Length_Tolerance above for notes on accuracy.
//
#macro PA_Bezier_Spline_Uniform(Points, Clock)
  
  #if(Clock < 0 | Clock > 1)
    #warning "PA_Bezier_Spline_Uniform: Clock value out of range, clipping to [0, 1].\n"
  #end
  
  #local Clk = clip(Clock, 0, 1);

  #local Count = dimension_size(Points, 1);
  
  #if(mod(Count, 4) != 0)
    #error "PA_Bezier_Spline_Uniform: Number of input points must be a multiple of four.\n"
  #end
  
  #local Lens = array[Count/4];
  #local Length = 0;
  
  #local Ct = 0;
  #local Ct_2 = 0;
  #while(Ct < Count/4)
    #local Lens[Ct] = 
      PA_Bezier_Curve_Length(Points[Ct_2], Points[Ct_2 + 1], Points[Ct_2 + 2], Points[Ct_2 + 3]);
    #local Length = Length + Lens[Ct];
    #local Ct = Ct + 1;
    #local Ct_2 = Ct_2 + 4;
  #end
  
  #local Dist = Clk * Length;
  
  #local Ct = 0;
  #local Found = no;
  #while(Ct < Count/4 & !Found)
    #if(Dist <= Lens[Ct])
      #local Found = yes;
    #else
      #local Dist = Dist - Lens[Ct];
      #local Ct = Ct + 1;
    #end
  #end
  
  #if(Found)
    #local Split = 
      PA_Split_Bezier(Points[Ct * 4], Points[Ct * 4 + 1], Points[Ct * 4 + 2], Points[Ct * 4 + 3]);
    #local Found = no;
    #while(!Found)
      #local L = PA_Bezier_Curve_Length(Split[0], Split[1], Split[2], Split[3]);
      #if(abs(Dist - L) > PA_Bezier_Length_Tolerance)
        #if(Dist > L)
          #local Dist = Dist - L;
          #local Split = PA_Split_Bezier(Split[4], Split[5], Split[6], Split[7]);
        #else
          #local Split = PA_Split_Bezier(Split[0], Split[1], Split[2], Split[3]);
        #end
      #else
        #local Found = yes;
        #local Pt = Split[3];
      #end
    #end
  #else
    #error "PA_Bezier_Spline_Dist: No result found.\n"
  #end
  
  Pt
#end

// PA_Bezier_Spline_Dist
// This is a shortcut for PA_Bezier_Spline_Uniform, which returns a point for a given
// absolute distance along the spline.
//  Points -   An array of point vectors.
//  Distance - The distance along the spline to calculate the point for.  Values longer
//             than the spline will be clipped with a warning.
//
#macro PA_Bezier_Spline_Dist(Points, Distance)
  
  #local Length = PA_Bezier_Length(Points);
  
  #if(Distance < 0 | Distance > Length)
    #warning concat("PA_Bezier_Spline_Dist: Distance out of range, clipped to [0, ",
                    str(Length, 0, 6), "].\n")
  #end
  
  #local Dist = clip(Distance, 0, Length);
  
  PA_Bezier_Spline_Uniform(Points, Dist/Length)
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
      
      #local Ct_2 = 0;
      #while(Ct_2 < Resolution)
        #local T = Ct_2 / (Resolution - 1);
        
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
        
        #local Moved = !VEq(Prev, Pt);
        
        #if(Moved | Pt.t != Prev.t | First)
          sphere { <Pt.x, Pt.y, Pt.z>, Pt.t }
        #end
        
        #if(Moved)
          Connect_Spheres(<Prev.x, Prev.y, Prev.z>, Prev.t, <Pt.x, Pt.y, Pt.z>, Pt.t)
        #end
        
        #local Prev = Pt;
        #local First = no;
        
        #if(Ct_2 = 0
            & VEq(Pt_1, Pt_2) & VEq(Pt_3, Pt_4) 
            & ((Pt_1.t = Pt_2.t & Pt_2.t = Pt_3.t & Pt_3.t = Pt_4.t)
               | Radius > 0))
          #local Ct_2 = Resolution - 1;
        #else
          #local Ct_2 = Ct_2 + 1;
        #end
      #end
      #local Ct = Ct + 4;
    #end
  }
#end

#macro PA_Print_Array(Points, Name, Dims, Min_Length, Digits)
  #local Count = dimension_size(Points, 1);
  
  #if(strlen(Name) > 0)
    #local Pad = "  ";
    #debug concat("#declare ", Name, " =\n")
  #else
    #local Pad = "";
  #end
  
  #debug concat(Pad, "array[", str(Count, 0, 0), "] {\n") 
  
  #local Ct = 0;
  #while(Ct < Count)
    #debug concat(Pad, "  <", 
                  vstr(Dims, Points[Ct], ", ", Min_Length, Digits),
                  ">")
    #if(Ct < Count - 1)
      #debug ","
    #end
    
    #debug "\n"
    
    #local Ct = Ct + 1;
  #end
  
  #debug concat(Pad, "};\n")
#end

// Internal macros

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

#macro PA_Adj_Len(Pt_1, Pt_2, Amount)
  #local Pt = Pt_2 - Pt_1;
  (vnormalize(Pt) * (vlength(Pt) + Amount) + Pt_1)
#end

#macro PA_Split_Bezier(Pt_1, Pt_2, Pt_3, Pt_4)
  
  #local Temp = array[4][4];
  
  #local Temp[0][0] = Pt_1;
  #local Temp[0][1] = Pt_2;
  #local Temp[0][2] = Pt_3;
  #local Temp[0][3] = Pt_4;
  
  #local Ct = 1;
  #while(Ct < 4)
    #local Ct_2 = 0;
    #while(Ct_2 < 4 - Ct)
      #local Temp[Ct][Ct_2] = Temp[Ct - 1][Ct_2]/2 + Temp[Ct - 1][Ct_2 + 1]/2;
      #local Ct_2 = Ct_2 + 1;
    #end
    #local Ct = Ct + 1;
  #end
  
  #local Result = 
    array[8] {
      Temp[0][0], Temp[1][0], Temp[2][0], Temp[3][0],
      Temp[3][0], Temp[2][1], Temp[1][2], Temp[0][3]
    };
  
  Result
#end

#macro PA_Bezier_Curve_Length(Pt_1, Pt_2, Pt_3, Pt_4)

  #local Len_1 = vlength(Pt_1 - Pt_2) + vlength(Pt_2 - Pt_3) + vlength(Pt_3 - Pt_4);
  #local Len_2 = vlength(Pt_1 - Pt_4);
  
  #if(Len_1 - Len_2 > PA_Bezier_Length_Tolerance)
    #local Split = PA_Split_Bezier(Pt_1, Pt_2, Pt_3, Pt_4);
    #local Len = PA_Bezier_Curve_Length(Split[0], Split[1], Split[2], Split[3])
                 + PA_Bezier_Curve_Length(Split[4], Split[5], Split[6], Split[7]);
  #else
    #local Len = Len_1/2 + Len_2/2;
  #end
  
  Len
#end    
            

#version Point_Arrays_Inc;
#end
