//
// Galaxy sample scene by Nekar Xenos 
//
// This file is licensed under the terms of the CC-LGPL  
//
// Warning: This sample takes about 8.5 hours to render on a 4 way 2.4GHz machine
//          at a resolution of 320x240 without antialiasing.  
//

#include"galaxy.inc"

sky_sphere{pigment{Galaxy_Star_pig}}   

// 
object{Galaxy_StarField }


// Galaxy(Rotation,Size)
object{Galaxy(<0,0,0>,1 ) rotate <45,45,0>}     




// Perspective (default) camera
camera {
  location  <0.0, 0, -.5>
  look_at   <0.0, 0.0,  0.0>
  right     x*image_width/image_height
}
             