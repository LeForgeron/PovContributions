// This file is licensed under the terms of the CC-LGPL

// Persistence of Vision Ray Tracer Scene Description File
// File: pillars.pov
// Vers: 2.0 (for POV 3.6+)
// Desc: some pillars (columns)
// Date: 9/27/2009
// Auth: Tim Attwood
//

#include "colors.inc"

#include "pillars.inc"

global_settings {

radiosity {
   brightness 2.5
   count 100
   error_bound 0.15
   gray_threshold 0.0
   low_error_factor 0.2
   minimum_reuse 0.015
   nearest_count 10
   recursion_limit 5
   adc_bailout 0.01
   max_sample 0.5
   media off
   normal off
   always_sample 1
   pretrace_start 0.08
   pretrace_end 0.01
}

}

#default {finish {ambient 0 diffuse 0.3}}

// --- camera, lights & background ------------------------------------------

camera {
   location  <0.0, 0.5, -4.0>
   direction 1.5*z
   right     x*image_width/image_height
   look_at   <0.0, 0.0,  0.0>
   focal_point <0,0,0>
   aperture 0.5
   blur_samples 20
}

background {White}
sphere {<0,0,0>, 100
   inverse
   pigment {White}
   finish {
      ambient 1
      diffuse 0
   }
}

light_source {
  <-30, 30, -30>           
  color rgb <1, 1, 1>*0.2 
}

// --- scene ----------------------------------------------------------------                                                                             

plane {y,-1.3 pigment{hexagon Tan ForestGreen Red}}

box {<-5,-1,-0.5>,<5,-0.9,0.7> pigment {Gray60}}
box {<-5,-1.1,-0.7>,<5,-1,0.7> pigment {Gray60}}
box {<-5,-1.2,-0.9>,<5,-1.1,0.7> pigment {Gray60}}

box {<-5,-1,0.7>,<5,3,1> pigment {Gray60}}
box {<-5,1.1,-0.5>,<5,3,0.7> pigment {Gray60}}

                                                                             
object {
   Pillar1
   translate <-1,-0.9,0>
   pigment {White}
   finish {
      specular 0.3
      roughness 0.005
   }
}

object {
   Pillar2
   translate <0,-0.9,0>
   pigment {White}
   finish {
      specular 0.3
      roughness 0.005
   }
   
}

object {
   Pillar3
   translate <1,-0.9,0>
   pigment {White}
   finish {
      specular 0.3
      roughness 0.005
   }   
}                                                                                        