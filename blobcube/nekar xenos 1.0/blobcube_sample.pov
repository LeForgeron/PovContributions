//
// BlobCube sample scene by Nekar Xenos 
//
// This file is licensed under the terms of the CC-LGPL  
//
// Persistence of Vision Ray Tracer Scene Description File
// File: ?.pov
// Vers: 3.6
// Desc: Basic Scene Example
// Date: 22/09/2008
// Auth: - Nekar Xenos -
//

#version 3.6;

#include "colors.inc"

global_settings {
  assumed_gamma 1.0
}

// ----------------------------------------

camera {
  location  <0.0, 0.5, -4.0>
  direction 1.5*z
  right     x*image_width/image_height
  look_at   <0.0, 0.0,  0.0>
}

sky_sphere {
  pigment {
    gradient y
    color_map {
      [0.0 rgb <0.6,0.7,1.0>]
      [0.7 rgb <0.0,0.1,0.8>]
    }
  }
}

light_source {
  <0, 0, 0>            // light's position (translated below)
  color rgb <1, 1, 1>  // light's color
  translate <-30, 30, -30>
}

// ----------------------------------------

plane {
  y, -.7
  pigment { color rgb <0.7,0.5,0.3> }
}

#include "BlobCube.inc"

blob {
  // threshold (0.0 < threshold <= StrengthVal) surface falloff threshold #
  threshold 0.5
BlobCube(<1,1,1>)       
pigment{colour rgb 1} 
 rotate <0,45,0>  
 
}