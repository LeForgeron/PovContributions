//
// Galaxy sample scene by Nekar Xenos 
//
//This file is licensed under the terms of the CC-LGPL   
//

#include"Galaxy.inc"

sky_sphere{pigment{star_pig}}   

// 
object{StarField }


// Galaxy(Rotation,Size)
object{Galaxy(<0,0,0>,1 ) rotate <45,45,0>}     




// perspective (default) camera
camera {
  location  <0.0, 0, -.5>
  look_at   <0.0, 0.0,  0.0>
  right     x*image_width/image_height
}
             