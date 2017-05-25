// Title:        ZShapes
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   February 14, 2008
// Last Updated: February 14, 2008
//
// This file is licensed under the terms of the CC-LGPL

#ifndef(ZShapes_Inc)
#declare ZShapes_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including Z_Shapes.inc\n"
#end

#include "transforms.inc"

// ZS_Tri_Sphere
// Convenience macro to create a sphere scaled with different radii on the x, y, and z axes.
// Location - Vector coordinates to place sphere
// Radius_X - Sphere radius in x axis
// Radius_Y - Sphere radius in y axis
// Radius_Z - Sphere radius in z axis
#macro ZS_Tri_Sphere(Location, Radius_X, Radius_Y, Radius_Z)
  sphere {
    0, 1
    scale <Radius_X, Radius_Y, Radius_Z>
    translate Location
  }
#end

// ZS_Duo_Sphere
// Convenience macro to create a sphere scaled with different radii on the x/z and y axes.
// Location - Vector coordinates to place sphere
// Radius_XZ - Sphere radius in x and z axes
// Radius_Y - Sphere radius in y axis
#macro ZS_Duo_Sphere(Location, Radius_XZ, Radius_Y)
  ZS_Tri_Sphere(Location, Radius_XZ, Radius_Y, Radius_XZ)
#end
 
// ZS_Duo_Torus
// Creates a scaled torus at the origin by specifying two minor radii
// Major - Major radius
// Minor_1 - Minor radius in x and z axes
// Minor_2 - Minor radius in y axis
#macro ZS_Duo_Torus(Major, Minor_1, Minor_2)
  torus {
    Major, Minor_1
    scale <1, Minor_2 / Minor_1, 1>
  }
#end

#local sqrt_half = sqrt(0.5);

// ZS_Octahedron
// A regular octahedron centered on the origin
#declare ZS_Octahedron =
  intersection {
    box { 
      <-sqrt_half, -sqrt_half, -2>, <sqrt_half, sqrt_half, 2>
      rotate z * 45
    }
    box {
      <-2, -sqrt_half, -sqrt_half>, <2, sqrt_half, sqrt_half>
      rotate x * 45
    }
    bounded_by {
      box { -1, 1 }
    }  
  }

// ZS_Pyramid
// A pyramid with a four sided base, 2x1x2 units
#declare ZS_Pyramid =
  intersection {
    object { ZS_Octahedron }
    box { <-1, 0, -1>, 1 }
    bounded_by {
      box { <-1, 0, -1>, 1 }
    }
  }
  
// ZS_Solid_Triangle
// Creates a triangle connecting three points, with a defined thickness and inside, for use in CSG  
// Point_1, Point_2, Point_3 - Vertices of the triangle
// Thickness - Distance to extend triangle, creating a prism-like shape.  If it is negative, it
//             will extend in the opposite direction.
#macro ZS_Solid_Triangle(Point_1, Point_2, Point_3, Thickness)

  #local Delta = vnormalize(vcross(Point_2 - Point_1, Point_3 - Point_1)) * Thickness;
  #local P1    = Point_1 + Delta;
  #local P2    = Point_2 + Delta;
  #local P3    = Point_3 + Delta;
  
  mesh2 {
    vertex_vectors {
      6,
      Point_1, Point_2, Point_3,
      P1, P2, P3
    }
    face_indices {
      8,
      <0, 1, 2>,
      <0, 1, 3>,
      <1, 4, 3>,
      <0, 2, 5>,
      <0, 3, 5>,
      <1, 2, 5>,
      <1, 4, 5>,
      <3, 4, 5>
    }
    inside_vector y
  }

#end

// ZS_Sphere_Cap
// Creates a semisphere given the radius of the circular base, and the height of the curve
// Height - Height of the semisphere
// Radius - Radius of the circular base
#macro ZS_Sphere_Cap(Height, Base_Radius)

  #local Radius = (Base_Radius*Base_Radius + Height*Height) / (2 * Height);
  
  difference {
    sphere { -y * (Radius - Height), Radius }
    plane { y, 0 }
    bounded_by {
      box { <-Base_Radius, 0, -Base_Radius>, <Base_Radius, Height, Base_Radius> }
    }
  }
#end

// ZS_Tube
// Create a cylinder with a hole in the center.
// End_1, End_2 - Endpoints of the tube
// Outer_Radius - Outer radius of the tube
// Inner_Radius - Radius of the hole in the tube
#macro ZS_Tube(End_1, End_2, Outer_Radius, Inner_Radius)
  #if(Inner_Radius<=0)
    #warning "ZS_Tube: Inner radius <= 0, replaced by cylinder/n"
    cylinder { End_1, End_2, Outer_Radius }
  #else
    #local Length = vlength(End_1 - End_2);
  
    lathe {
      linear_spline
      5,
      <Inner_Radius, 0>,
      <Outer_Radius, 0>,
      <Outer_Radius, Length>,
      <Inner_Radius, Length>,
      <Inner_Radius, 0>
      Reorient_Trans(y * Length, End_2 - End_1)
      translate End_1
    }
  #end
#end

// ZS_Round_Tube
// Like ZS_Tube with rounded edges
// Edge_Radius - Radius of rounded edges
// Use_Merge - Boolean, if yes object is a merge, otherwise object is a union
#macro ZS_Round_Tube(End_1, End_2, Outer_Radius, Inner_Radius, Edge_Radius, Use_Merge)

  #local Length = vlength(End_1 - End_2);
  
  #local E1 = y * Edge_Radius;
  #local E2 = y * (Length - Edge_Radius);
  
  #local Outer_Edge_Radius = Outer_Radius - Edge_Radius;
  #local Inner_Edge_Radius = Inner_Radius + Edge_Radius;
  
  #local Outer_Edge = torus { Outer_Edge_Radius, Edge_Radius }
    
  #local Inner_Edge = torus { Inner_Edge_Radius, Edge_Radius }
  
  #if(Use_Merge)
  merge {
  #else
  union {
  #end
    ZS_Tube(E1, E2, Outer_Radius, Inner_Radius)
    #if(Outer_Radius - Inner_Radius > Edge_Radius*2)
      ZS_Tube(0, y * Length, Outer_Radius - Edge_Radius, Inner_Radius + Edge_Radius)
      object {
        Inner_Edge
        translate E1
      }
      object {
        Inner_Edge
        translate E2
      }
    #end
    object {
      Outer_Edge
      translate E1
    }
    object {
      Outer_Edge
      translate E2
    }
    Reorient_Trans(y * Length, End_2 - End_1)
    translate End_1
  }
#end
  
#macro ZS_Round_Tube_Merge(End_1, End_2, Outer_Radius, Inner_Radius, Edge_Radius)
  ZS_Round_Tube(End_1, End_2, Outer_Radius, Inner_Radius, Edge_Radius, yes)
#end

#macro ZS_Round_Tube_Union(End_1, End_2, Outer_Radius, Inner_Radius, Edge_Radius)
  ZS_Round_Tube(End_1, End_2, Outer_Radius, Inner_Radius, Edge_Radius, no)
#end
 
#version ZShapes_Inc;
#end
