//
// vulture.pov
// -----------
// Created by George Leonberger 2001  
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett
// This scene file illustrates the use of the 'vulture.inc' file which adds a
// Vulture Space Rocket to your scene from the US TV show Salvage 1. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The model is about 14 POV-Ray units in height and, by default is centred at the 
// origin sitting on the plane Y=0.
//
// Adding this model to your scene is likely to add a few seconds to the render time.
//
// See vulture.html for more details.
//
// Why not try animation options +kfi0 +kff20 and see it lift off. 


camera { orthographic
  location  <0, 7.5,-20>
  look_at   <0, 7.5,  0>
}


light_source {
  <-10, 30,-15>
  color rgb <1.000, 1.000, 1.000>
  fade_distance  100.0
  fade_power 1.0
}


difference {
  object {#include "vulture.inc"}
  plane {z,0 pigment {rgb <1,1,0.3>}}
}


cylinder {< -5  , 0  ,10><  5, 0  ,10>,0.02 pigment {rgb <0,5,0>} finish {ambient 20}} 
cylinder {<  0  ,-0.4,10><  0, 0  ,10>,0.02 pigment {rgb <0,5,0>} finish {ambient 20}} 
cylinder {<  5  ,-0.4,10><  5, 0  ,10>,0.02 pigment {rgb <0,5,0>} finish {ambient 20}} 

cylinder {<-5  ,-0.4,10><-5,15  ,10>,0.02 pigment {rgb <0,5,5>} finish {ambient 20}} 
cylinder {<-5.4, 0  ,10><-5, 0  ,10>,0.02 pigment {rgb <0,5,5>} finish {ambient 20}} 
cylinder {<-5.4, 5  ,10><-5, 5  ,10>,0.02 pigment {rgb <0,5,5>} finish {ambient 20}} 
cylinder {<-5.4,10  ,10><-5,10  ,10>,0.02 pigment {rgb <0,5,5>} finish {ambient 20}} 
cylinder {<-5.4,15  ,10><-5,15  ,10>,0.02 pigment {rgb <0,5,5>} finish {ambient 20}} 

text {ttf "arial.ttf",   "X",0.2,0  scale 0.5 pigment {rgb <0,5,0>} finish {ambient 20} translate <  5.3,-0.2, 0  >}
text {ttf "arial.ttf",   "0",0.2,0  scale 0.5 pigment {rgb <0,5,0>} finish {ambient 20} translate < -0.1,-1.2, 0  >}
text {ttf "arial.ttf",   "5",0.2,0  scale 0.5 pigment {rgb <0,5,0>} finish {ambient 20} translate <  4.9,-1.2, 0  >}
text {ttf "arial.ttf",  "-5",0.2,0  scale 0.5 pigment {rgb <0,5,0>} finish {ambient 20} translate < -5.2,-1.2, 0  >}
                                    
text {ttf "arial.ttf",  "Y" ,0.2,0  scale 0.5 pigment {rgb <0,5,5>} finish {ambient 20} translate <-5.2,15.5, 0  >}
text {ttf "arial.ttf",  "0" ,0.2,0  scale 0.5 pigment {rgb <0,5,5>} finish {ambient 20} translate <-6.0,-0.2, 0  >}
text {ttf "arial.ttf",  "5" ,0.2,0  scale 0.5 pigment {rgb <0,5,5>} finish {ambient 20} translate <-6.0, 4.8, 0  >}
text {ttf "arial.ttf", "10" ,0.2,0  scale 0.5 pigment {rgb <0,5,5>} finish {ambient 20} translate <-6.2, 9.8, 0  >}
text {ttf "arial.ttf", "15" ,0.2,0  scale 0.5 pigment {rgb <0,5,5>} finish {ambient 20} translate <-6.2,14.8, 0  >}
