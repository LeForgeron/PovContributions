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


camera {
  location  < -10, 10,-15>
  look_at   < 0, 7+pow(clock*16,2)/2,  0>
}


light_source {
  <-10, 30,-15>
  color rgb <1.000, 1.000, 1.000>
  fade_distance  100.0
  fade_power 1.0
}


object {
  #include "vulture.inc"
  translate y*pow(clock*16,2)   
  rotate 20*clock*x
}

plane {y,0  
  texture {
    pigment {rgb 0.2*<1,0.8,0.6>}
    normal {crackle 1 scale 0.2}
  }
}


