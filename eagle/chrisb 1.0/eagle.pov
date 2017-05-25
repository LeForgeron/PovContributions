//
// eagle.pov
// ---------
// Created by George Leonberger 2001  
// Adapted to go into the POV-Ray Object Collection Sept 2009 by Chris Bartlett
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
// Why not try animation options +kfi0 +kff20 and see it lift off. 


camera {
  location  <-23, 10,-10>
  look_at   < -8,  5,  0>
}

// Alternative camera looking into cockpit
//camera {
//  location  <-15,5.4,2>
//  look_at   <-10,5,-2>
//}



object {
  #include "eagle.inc"
  translate clock*20 
}

plane {y,0  
  texture {
    pigment {rgb 0.2*<1,0.8,0.6>}
    normal {crackle 1 scale 0.2}
  }
}

light_source {
  <-20, 40, -20>
  color rgb <1.000, 1.000, 1.000>
  fade_distance  1000.0
  fade_power 1.0
}

