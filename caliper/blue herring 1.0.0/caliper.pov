// Title:        Caliper demo scene
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 24, 2008
// Last updated: June 27, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
// +W800 +H600 +AM2 +A0.02
//
#version 3.61;

// Enable/disable area lights
#declare Use_Area = yes;

#include "caliper.inc"
#include "colors.inc"
#include "rand.inc"
#include "shapes.inc"
#include "textures.inc"
#include "transforms.inc"

global_settings {
  assumed_gamma 1.0
  max_trace_level 6
}

camera {
  location <0, 12, -5>
  up y
  right x * image_width/image_height
  look_at 0
}

box {
  <-150, -1, -150>, 150
  inverse
  pigment { VeryDarkBrown }
}

#declare Cool_Fluorescent = rgb <212, 235, 255>/255;

#declare Fl_Tube =
  cylinder {
    x * -90, x * 90, 4
    hollow
    no_image
    no_shadow 
    texture {
      pigment { rgbt 1 }
    }
    interior {
      media {
        method 3
        intervals 1
        samples 10,10
        emission Cool_Fluorescent
        density {
          cylindrical
          poly_wave 2
          rotate z * 90
          scale 4
        }
      }
    }
  }

#declare Fl_Light =
  light_source {
    0, Cool_Fluorescent
    #if(Use_Area)
      area_light
      x * 180, z * 4, 33, 9
      adaptive 2
    #end
    looks_like { Fl_Tube }
    fade_power 2
    fade_distance 75
  }
  
light_source {
  Fl_Light
  translate <0, 120, 40>
}

light_source {
  Fl_Light
  translate <0, 120, 50>
}

#declare R = seed(13);
#declare Count = 6;
#declare Ct = 0;
#while(Ct < Count)
  #local Pig = 
    pigment { 
      DMFDarkOak 
      scale 0.5
      rotate <RRand(-3, 3, R), 90 + RRand(-5, 5, R), 0>
      translate <SRand(R), SRand(R), SRand(R)> * 5
    }
      
  object {
    Round_Box_Union(<-150, -1, -2>, <150, 0, 2>, 0.1)
    texture {
      pigment { Pig }
      finish {
        specular 0.25
        roughness 0.01
        reflection {
          0, 0.2
        }
        conserve_energy
      }
      normal {
        pigment_pattern { Pig }, 0.2
      }
    }
    translate z * (-Count * 2 + Ct * 4)
  }
  #declare Ct = Ct + 1;
#end

#declare Caliper_Obj = Caliper(5)

object {
  Caliper_Obj
  Center_Trans(Caliper_Obj, x + z)
  Align_Trans(Caliper_Obj, -y, <0, 0, 0>)
  rotate y * 22.5
}
