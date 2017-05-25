// Title:        PointArrays demo scene
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 5, 2008
// Last updated: June 16, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#default { finish { ambient 0 diffuse 1 } }

#include "colors.inc"
#include "pa_shooting_star.inc"
#include "pointarrays.inc"

global_settings {
  assumed_gamma 1.0
  radiosity {
    pretrace_start 0.08
    pretrace_end   0.005
    //count 50
    count 100
    nearest_count 14
    error_bound 0.6
    recursion_limit 1
    low_error_factor 0.7
    gray_threshold 0
    minimum_reuse 0.025
    brightness 1.0
    adc_bailout 0.01/2
    normal off      
    media off
  }
}

camera {
  location <0, 5, -25>
  up y
  right x * image_width/image_height
  look_at 0
}

#declare PA_Objs =
  union {

    object {
      PA_Bezier_Sweep(PA_Shooting_Star, 0.1, PA_No_Trans, 60, no)
      translate <-10, -3, 0>
      rotate y * 22.5
      pigment { Red }
    }

    object {
      PA_Prism(PA_Bezier, PA_Linear_Sweep, -0.5, 0.5, PA_Shooting_Star, no, no, PA_No_Trans)
      rotate x * -90  
      translate <-10, -3, 0>
      scale <0.4, 0.4, 1>
      translate <2, -3, 0>
      rotate y * 22.5
      pigment { Blue }
    }

    #declare PA_Trans_1 = 
      transform {
        scale 0.25
        rotate z * 90
        translate x * 12.5
      }

    object {
      PA_Lathe_Arc(PA_Bezier, PA_Shooting_Star, no, PA_Trans_1, 270)
      rotate y * 45
      translate y * -3
      pigment { Yellow }
    }

    #declare PA_Trans_2 =
      transform {
        scale 0.25
        rotate z * -90
        translate <13, 5, 0>
      }

    object {
      PA_Lathe_Arc(PA_Bezier, PA_Shooting_Star, no, PA_Trans_2, 270)
      rotate y * 45
      translate y * -3
      pigment { Green }
    }

    translate z * 1.5
  }

plane {
  y, 0
  pigment { White }
  translate y * (min_extent(PA_Objs).y - 0.25)
}

sphere {
  0, 10000
  inverse
  texture {
    pigment { rgb <255, 231, 204>/255 }
    finish {
      ambient 1
      diffuse 0
    }
  }
}

object { PA_Objs }
