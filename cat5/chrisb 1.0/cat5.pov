// CAT5.pov
// --------

// Scene file illustrating the use of a sphere sweep with writing down the side to represent a section of CAT5 computer cable. 
// Created by Chris Bartlett 07.02.2005 
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time about 20 seconds.
camera {location<1.5,10,-4> look_at<0,0,0>}
light_source{<30,30,-20> color rgb 2} 

#include "transforms.inc" 

// create a curved tube object translating a sphere along a certain path
#declare C5_Sweep = sphere_sweep {
  cubic_spline                
  4,                          
  <-30,  5, 0>, 1             
  < -5,  5, 0>, 1             
  <  5, -5, 0>, 1
  < 30, -5, 0>, 1
  tolerance 0.001             
} 

#declare C5_Spline =
  spline {
    cubic_spline
    -1, <-30,  5, 0>
     0, < -5,  5, 0>
     1, <  5, -5, 0>
     2, < 30, -5, 0>
  }

#declare C5_C =  text {
    ttf "cyrvetic.ttf" "C" 0.25, 0
    pigment { color rgb <1,0,0>}
    scale <0.8,0.8,1>        
    translate <-0.5,-0.2,-1.08>
    rotate -y*90  
}
#declare C5_A =  text {
    ttf "cyrvetic.ttf" "A" 0.25, 0
    pigment { color rgb <1,0,0>}
    scale <0.8,0.8,1>        
    translate <-0.5,-0.2,-1.08>
    rotate -y*90  
}
#declare C5_T =  text {
    ttf "cyrvetic.ttf" "T" 0.25, 0
    pigment { color rgb <1,0,0>}
    scale <0.8,0.8,1>        
    translate <-0.5,-0.2,-1.08>
    rotate -y*90  
}

#declare C5_5e =  text {
    ttf "cyrvetic.ttf" "5e" 0.25, 0
    pigment { color rgb <1,0,0>}
    scale <0.8,0.8,1>        
    translate <-0.5,-0.2,-1.08>
    rotate -y*90  
}
#declare C5_4PR =  text {
    ttf "cyrvetic.ttf" "4PR" 0.25, 0
    pigment { color rgb <1,0,0>}
    scale <0.8,0.8,1>        
    translate <-0.5,-0.2,-1.08>
    rotate -y*90  
}

difference {
  object {C5_Sweep pigment {color rgb <1,1,0>}}

  object {C5_C   rotate <-10,0,0>  Spline_Trans(C5_Spline,0.10,y,0.005,0.005)}
  object {C5_A   rotate <-10,0,3>  Spline_Trans(C5_Spline,0.14,y,0.005,0.005)}
  object {C5_T   rotate <-10,0,6>  Spline_Trans(C5_Spline,0.18,y,0.005,0.005)}
  object {C5_5e  rotate <-10,0,14> Spline_Trans(C5_Spline,0.25,y,0.005,0.005)}
  object {C5_4PR rotate <-10,0,23> Spline_Trans(C5_Spline,0.35,y,0.005,0.005)}
                       
  object {C5_C   rotate <-10,0,50> Spline_Trans(C5_Spline,0.60,y,0.005,0.005)}
  object {C5_A   rotate <-10,0,53> Spline_Trans(C5_Spline,0.64,y,0.005,0.005)}
  object {C5_T   rotate <-10,0,56> Spline_Trans(C5_Spline,0.68,y,0.005,0.005)}
  object {C5_5e  rotate <-10,0,64> Spline_Trans(C5_Spline,0.75,y,0.005,0.005)}
  object {C5_4PR rotate <-10,0,73> Spline_Trans(C5_Spline,0.85,y,0.005,0.005)}
}