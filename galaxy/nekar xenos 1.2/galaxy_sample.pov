//
// Galaxy sample scene by Nekar Xenos 
//
// This file is licensed under the terms of the CC-LGPL  
//
// Warning: This sample takes about 8.5 hours to render on a 4 way 2.4GHz machine
//          at a resolution of 320x240 without antialiasing.  
//

#version 3.6;  

#include"galaxy.inc"

sky_sphere{pigment{Galaxy_Star_pig}}   

// 
object{Galaxy_StarField }


// Galaxy(Rotation,Size,ArmCount,Tightness,Turb,NucleuSize,Quality) 
object{Galaxy(<0,0,0>,.5,2,2,2,.05,6) 
        rotate <0,45,-30>
        //rotate <0,90,-45> 
        //translate z
        }     




// Perspective (default) camera
camera {
  location  <0.0, 0, -.7>
  look_at   <0.0, 0.0,  0.0>
  right     x*image_width/image_height
}
             