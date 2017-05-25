// Title:        ZShapes demo scene
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   February 14, 2008
// Last Updated: February 14, 2008
//
// This file is licensed under the terms of the CC-LGPL

#version 3.61;

#include "colors.inc"
#include "ZShapes.inc"

global_settings {
  assumed_gamma 1.0
}

#declare ZS_Shiny =
  texture {
    pigment { Red }
    finish { 
      ambient 0
      diffuse 0.95
      specular 0.7
      roughness 0.012904
      reflection {
        0.025, 0.1
      }
      conserve_energy
    }
  }
  

camera {
  location <0, 1, -11>
  up y
  right x * image_width/image_height
  look_at 0
}

light_source {
  <2, 5, -15>, rgb <255, 231, 204>/255
  area_light
  x * 2, y * 2, 15, 15
  circular
  orient
  adaptive 1
  jitter
}

plane {
  -z, -5
  pigment { White }
}

union {

  object {
    ZS_Tri_Sphere(0, 1, 0.5, 2)
    translate <-5, 2, 0>
  }

  object {
    ZS_Duo_Sphere(0, 0.5, 2)
    translate <-2.5, 2, 0>
  }

  object {
    ZS_Octahedron
    rotate y * -20
    translate <0, 2, 0>
  }

  object {
    ZS_Pyramid
    translate <2.5, 2, 0>
  }

  object {
    ZS_Solid_Triangle(<-0.5, 0, 0.5>, <0, 1, 0>, <0.5, 0, 0.5>, 1)
    translate <5, 2, 0>
  }
  
  object {
    ZS_Sphere_Cap(0.4, 1)
    translate <-4.5, -2.5, 0>
  }
  
  object {
    ZS_Tube(-y, y, 0.5, 0.25)
    translate <-1.5, -2.5, 0>
  }

  object {
    ZS_Round_Tube(-y, y, 0.5, 0.25, 0.1, no)
    translate <1.5, -2.5, 0>
  }
  
  object {
    ZS_Duo_Torus(1, 0.25, 0.5)
    translate <4.5, -2.5, 0>
  }
  
  texture { ZS_Shiny }
}

