// Title:        Caliper auxiliary macros
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 24, 2008
// Last updated: June 24, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(Caliper_Aux_Inc)
#declare Caliper_Aux_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including caliper_aux.inc\n"
#end

#include "transforms.inc"

// These are macros used internally by the Caliper macro

#macro Caliper_Sphere_Cap(Height, Base_Radius)

  #local Radius = (Base_Radius*Base_Radius + Height*Height) / (2 * Height);
  
  difference {
    sphere { -y * (Radius - Height), Radius }
    plane { y, 0 }
    bounded_by {
      box { <-Base_Radius, 0, -Base_Radius>, <Base_Radius, Height, Base_Radius> }
    }
  }
#end

#macro Caliper_Tube(End_1, End_2, Outer_Radius, Inner_Radius)
  #if(Inner_Radius<=0)
    #warning "Caliper_Tube: Inner radius <= 0, replaced by cylinder/n"
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

#macro Caliper_Sphere_Coil(Start, End, Major, Minor, Turn_Res, Spacing, Use_Merge)
  
  #local Angle = 360/Turn_Res;
  #local Length = vlength(Start - End);
  #local Step = (Minor + Spacing) / Turn_Res;
  #local Count = Turn_Res * (Length / (Minor + Spacing));
  #local Ct = 0;
  
  union {
    #while(Ct < Count)
      sphere {
        z * Major, Minor
        rotate y * Angle * Ct
        translate y * Step * Ct
      }
      #local Ct = Ct + 1;
    #end
    Reorient_Trans(y, End - Start)
    translate Start
  }
  
#end

#version Caliper_Aux_Inc;
#end
