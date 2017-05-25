//
// eagle_section.pov
// -----------------
// Model created by George Leonberger 2001  
// Scene created for the POV-Ray Object Collection Sept 2009 by Chris Bartlett
// This scene file illustrates the use of the 'eagle.inc' file which adds an
// Eagle Transporter to your scene from the TV show Space 1999. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The model is about 40 POV-Ray units in length and, by default is centred at the 
// origin sitting on the plane Y=0.
//
// Adding this model to your scene is likely to add a couple of minutes to the render time.
//
// See eagle.html for more details.
//


camera { orthographic
  location  <0, 5,-35>
  look_at   <0, 5,  0>
}

// Alternative camera looking into cockpit
//camera {
//  location  <-15,5.4,2>
//  look_at   <-10,5,-2>
//}


difference {
  object {#include "eagle.inc"}
  plane {z,0 pigment {rgb <1,1,0.3>}}
}

light_source {
  <-20, 20, -40>
  color rgb <1.000, 1.000, 1.000>
  fade_distance  1000.0
  fade_power 1.0
}

cylinder {<-20  , 0  ,10>< 20, 0  ,10>,0.03 pigment {rgb <0,5,0>} finish {ambient 20}} 
cylinder {<  0  ,-0.4,10><  0, 0  ,10>,0.03 pigment {rgb <0,5,0>} finish {ambient 20}} 
cylinder {< 10  ,-0.4,10>< 10, 0  ,10>,0.03 pigment {rgb <0,5,0>} finish {ambient 20}} 
cylinder {< 20  ,-0.4,10>< 20, 0  ,10>,0.03 pigment {rgb <0,5,0>} finish {ambient 20}} 
cylinder {<-10  ,-0.4,10><-10, 0  ,10>,0.03 pigment {rgb <0,5,0>} finish {ambient 20}} 

cylinder {<-20  ,-0.4,10><-20,10  ,10>,0.03 pigment {rgb <0,5,5>} finish {ambient 20}} 
cylinder {<-20.4, 0  ,10><-20, 0  ,10>,0.03 pigment {rgb <0,5,5>} finish {ambient 20}} 
cylinder {<-20.4, 5  ,10><-20, 5  ,10>,0.03 pigment {rgb <0,5,5>} finish {ambient 20}} 
cylinder {<-20.4,10  ,10><-20,10  ,10>,0.03 pigment {rgb <0,5,5>} finish {ambient 20}} 

//text {ttf "arial.ttf", "Detachable",2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate < -2.2, 4  ,-0.1>}
text {ttf "arial.ttf", "Cargo Bay" ,0.2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate < -2.1, 3.5,-0.1>}

text {ttf "arial.ttf",   "X"       ,0.2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate < 21  ,-0.5, 0  >}
text {ttf "arial.ttf",   "0"       ,0.2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate < -0.2,-1.5, 0  >}
text {ttf "arial.ttf",  "10"       ,0.2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate <  9.6,-1.5, 0  >}
text {ttf "arial.ttf",  "20"       ,0.2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate < 19.5,-1.5, 0  >}
text {ttf "arial.ttf", "-10"       ,0.2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate <-11.0,-1.5, 0  >}
text {ttf "arial.ttf", "-20"       ,0.2,0  pigment {rgb <0,5,0>} finish {ambient 20} translate <-20.7,-1.5, 0  >}

text {ttf "arial.ttf",  "Y"        ,0.2,0  pigment {rgb <0,5,5>} finish {ambient 20} translate <-20.3,10.5, 0  >}
text {ttf "arial.ttf",  "0"        ,0.2,0  pigment {rgb <0,5,5>} finish {ambient 20} translate <-21.2,-0.4, 0  >}
text {ttf "arial.ttf",  "5"        ,0.2,0  pigment {rgb <0,5,5>} finish {ambient 20} translate <-21.2, 4.7, 0  >}
text {ttf "arial.ttf", "10"        ,0.2,0  pigment {rgb <0,5,5>} finish {ambient 20} translate <-21.8, 9.7, 0  >}
