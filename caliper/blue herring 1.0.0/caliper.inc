// Title:        Caliper
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   April 1, 2008
// Last updated: June 27, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(Caliper_Inc)
#declare Caliper_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including caliper.inc\n"
#end

#include "caliper_aux.inc"
#include "metals.inc"
#include "shapes.inc"

// Caliper
// Creates a caliper object (specifically an outside caliper).
//  Angle - 
//    Type: Float
//    Use:  The angle at which the caliper arms are open.
//
// Additional parameters:
//  Caliper_Texture - 
//    Type:    Texture
//    Default: Caliper_Default_Texture
//    Use:     If this variable is defined, it will be used to texture the
//             resultant object instead of Caliper_Default_Texture (defined below).
//  Caliper_No_Texture - 
//    Type:    Boolean
//    Default: False
//    Use:     If this variable is defined to be a true value it will disable any
//             texturing.  The macro will thus return an untextured object.  This
//             variable has precedence over Caliper_Texture (if set).
//
#macro Caliper(Angle)

  #ifndef(Caliper_Texture)
    #local Caliper_Texture = Caliper_Default_Texture;
  #end
  
  #ifndef(Caliper_No_Texture)
    #local Caliper_No_Texture = no;
  #end
  
  #local Caliper_Arm =
    prism {
      linear_sweep
      bezier_spline
      1.0, //top
      0.0, //bottom
      76, //nr points
      /*   0*/ <391.92933, 124.38431>, <422.09615, 123.44539>, <450.38158,108.79776>, <468.48268,87.748712>,
      /*   1*/ <468.48268, 87.748712>, <486.25008, 67.087692>, <499.10939,42.546302>, <499.99919,11.113722>,
      /*   2*/ <499.99919, 11.113722>, <500.02367, 10.422952>, <499.48993,9.799532>, <498.82441,9.817522>,
      /*   3*/ <498.82441, 9.817522>, <498.14303, 9.835942>, <497.87102,10.332012>, <497.56098,11.022782>,
      /*   4*/ <497.56098, 11.022782>, <496.21679, 14.165982>, <494.4523,17.118302>, <494.15218,19.698472>,
      /*   5*/ <494.15218, 19.698472>, <491.4654, 42.798792>, <472.58567,70.729872>, <463.81264,79.970142>,
      /*   6*/ <463.81264, 79.970142>, <445.21098, 99.562492>, <421.15272,111.4997>, <391.7095,112.4161>,
      /*   7*/ <391.7095, 112.4161>, <362.23348, 113.33353>, <344.79195,98.672622>, <329.50926,87.652012>,
      /*   8*/ <329.50926, 87.652012>, <321.88146, 82.151452>, <303.17386,62.032852>, <286.72069,48.774852>,
      /*   9*/ <286.72069, 48.774852>, <270.26753, 35.516832>, <258.17662,25.053972>, <247.81864,18.230192>,
      /*  10*/ <247.81864, 18.230192>, <237.46065, 11.406422>, <225.99624,4.705712>, <218.78738,3.246662>,
      /*  11*/ <218.78738, 3.246662>, <190.90509, -2.396618>, <13.639135,0.79911202>, <10.730063,1.902702>,
      /*  12*/ <10.730063, 1.902702>, <7.8209898, 3.006292>, <0.054975,19.442922>, <0.005567,19.966612>,
      /*  13*/ <0.005567, 19.966612>, <-0.05932, 20.654232>, <0.45099,20.821892>, <1.119563,20.944992>,
      /*  14*/ <1.119563, 20.944992>, <1.827593, 21.075352>, <192.45229,24.780712>, <209.38296,28.207412>,
      /*  15*/ <209.38296, 28.207412>, <226.31363, 31.634142>, <228.4438,32.988732>, <238.69307,39.740902>,
      /*  16*/ <238.69307, 39.740902>, <248.94235, 46.493062>, <263.9222,53.279022>, <280.32503,66.496472>,
      /*  17*/ <280.32503, 66.496472>, <296.72787, 79.713922>, <313.93749,96.506222>, <321.96829,102.29735>,
      /*  18*/ <321.96829, 102.29735>, <337.56624, 113.54532>, <361.79534,125.32225>, <391.92933,124.38431>
      scale <0.02, 0.25, 0.02> // 500x1x124 -> 10x0.25x2.4
      translate <-0.6, -0.125, 0.1>
      rotate y * -Angle/2
    }
    
  #local Hinge_Cap = Caliper_Sphere_Cap(0.1, 0.35);
  #local Side_Cap = Caliper_Sphere_Cap(0.1, 0.25);
  
  #local P1 = vrotate(<3, 0, 0.36>, y * -Angle/2);
  #local P2 = vrotate(<3, 0, -0.36>, y * Angle/2);  
    
  union {
    // Arms
    object { Caliper_Arm }
    object { 
      Caliper_Arm 
      scale <1, 1, -1>
    }
    
    // Hinge
    cylinder { y * -0.125, y * 0.125, 0.1 }
    object {
      Hinge_Cap
      translate y * 0.125
    }
    object {
      Hinge_Cap
      rotate x * 180
      translate y * -0.125
    }
    difference {
      Caliper_Tube(y * -0.25, y * 0.25, 0.6, 0.56)
      box { <0, -0.3, -0.35>, <0.7, 0.3, 0.35> }
      bounded_by {
        cylinder { y * -0.25, y * 0.25, 0.6 }
      }
      translate x * -0.6
    }      
    
    // Side caps
    object {
      Side_Cap
      translate P1 + y * 0.125
    }
    object {
      Side_Cap
      rotate x * 180
      translate P1 + y * -0.125
    }
    object {
      Side_Cap
      translate P2 + y * 0.125
    }
    object {
      Side_Cap
      rotate x * 180
      translate P2 + y * -0.125
    }
    
    // Bolt
    cylinder {
      0, z * 3.5, 0.08
      translate P2
    }
    object {
      Caliper_Sphere_Coil(0, y * 7, 0.08, 0.025, 250, 0.05, no)
      scale <1, 0.5, 1> 
      rotate x * 90
      translate P2
    }
    sphere {
      z * 3.5, 0.15
      translate P2
    }
    
    // Adjustment nut
    cylinder {
      0, z * 0.5, 0.11
      translate P1
    }
    object {
      Round_Cylinder_Union(0, z * 0.25, 0.2, 0.05)
      translate P1 + z * 0.45
    }
    cone {
      0, 0.15, z * 0.35, 0.25
      translate P1 + z * 0.7
    }
    object {
      Round_Cylinder_Union(0, z * 0.25, 0.3, 0.03)
      translate P1 + z * 1.05
    }
    #local Count = 50;
    #local Ct = 0;
    #while(Ct < Count)
      sphere {
        0, 0.08
        scale <0.25, 1, 1>
        translate y * 0.3
        rotate z * 360/Count * Ct
        translate P1 + z * 1.175
      }
      #local Ct = Ct + 1;
    #end
    
    #if(! Caliper_No_Texture)
      texture { Caliper_Texture }
    #end
  }
#end

// Caliper_Default_Texture
// This is the default texture applied by the Caliper macro.  It can be
// redefined, but its probably better to set Caliper_Texture.
//
#declare Caliper_Default_Texture =
  texture {
    pigment { P_Chrome2 }
    finish {
      ambient 0
      diffuse 0.3
      specular 1.4
      roughness 0.020962
      metallic
      reflection {
        0.35, 0.7
        metallic
      }
      conserve_energy
      brilliance 2
    }
    normal {
      granite -0.02
      poly_wave 4
    }
  }

#version Caliper_Inc;
#end

