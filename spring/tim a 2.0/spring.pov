// This file is licensed under the terms of the CC-LGPL

// Persistence of Vision Ray Tracer Scene Description File
// File: spring_demo.pov
// Vers: 3.7
// Desc: Mesh Spring Scene Example, this scene demonstrates the use of 
// the BoxSpring macro from "spring.inc"
// Date: 9/24/2009
// Auth: Tim Attwood

#include "colors.inc"
#include "metals.inc"

// include the macro
#include "spring.inc"

// --- camera, lights & background ------------------------------------------

camera {
   location  <0.0, -0.5, -4.0>
   direction 1.5*z
   right     x*image_width/image_height
   look_at   <0.0, -0.5,  0.0>
   angle 32
}

sky_sphere {
  pigment {
    gradient y
    color_map {
      [0.0 Red]
      [0.1 Blue]
      [0.2 Black]
      [0.3 Blue]
      [0.4 Red]
      [0.5 Yellow]
      [0.6 Red]
      [0.7 Blue]
      [0.8 Black]
      [0.9 Blue]
      [1.0 Red]
    }
  }
}

light_source {
  <-30, 30, -30>           
  color rgb <1, 1, 1> 
}

// --- scene ----------------------------------------------------------------                                                                             

plane {y,-1
   texture {
      checker
      texture {T_Brass_2A}
      texture { pigment {White}}
   }   
}

fog {
  fog_type 2
  distance 30
  color <0.5,0.05,0.05>
  fog_alt 1
}

// The spring is created with it's base on the origin, oriented on the +X axis

// U and V are the rectangular width and height of the spring wire

// X_Length is the overall length of the spring

// Radius is the radius of the spring

// Coils is the number of turns the spring makes (fractional numbers are OK)

// Rez is the appoximate number of desired triangles in the mesh.

object {
   // U, V, length, radius, coils, rez   
   Spring (0.1, 0.2, 2, 0.5, 7.0, 5000) 
   texture {T_Chrome_2A}   
   translate <-1,-0.5,0>
}                                                                            
