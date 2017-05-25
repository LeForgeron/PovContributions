// This file is licensed under the terms of the CC-LGPL

// Persistence of Vision Ray Tracer Scene Description File
// File: daffodil.pov
// Vers: 3.6+
// Desc: A demo of using "daffodil.inc" macro to create a daffodil
// Date: 9/24/2009
// Auth: Tim Attwood

#include "colors.inc"

// --- camera, lights & background ------------------------------------------

camera {
   location  <0.0, 3.5, -2.0>
   direction 1.5*z
   right     x*image_width/image_height
   look_at   <0.0, 0.0,  1.0>
}

background {Black}

light_source {
  <-30, 30, -30>           
  color rgb <1, 1, 1> 
}
light_source {
  <30, 30, -30>           
  color rgb <0, 0.2, 0>
  shadowless 
}


// --- scene ----------------------------------------------------------------                                                                             

plane {y,-1 pigment{White}}


// ------------------------------------
// row 1
// the default flower is a "Las Vegas" daffodil
#include "daffodil.inc"
object {Daffodil translate <-1,-1,0>}                                                                            

// this is a copy of the same exact flower 
object {Daffodil translate <0,-1,0>}                                                                            

// this is a second randomized flower
#include "daffodil.inc"
object {Daffodil translate <1,-1,0>}

// ------------------------------------
// row 2
// this is a flower with a blue center cone
#declare YelDaf = texture {
   pigment {Blue}
};
#include "daffodil.inc"
object {Daffodil translate <-1,-1,1>}

// this is a flower with cyan petals, note that the center remains blue
#declare WhtDaf = texture {
   pigment {Cyan}
};
#include "daffodil.inc"
object {Daffodil translate <0,-1,1>}

// this is a flower with magenta leaves
#undef YelDaf
#undef WhtDaf
#declare GrnDaf = texture {
   pigment {
      Magenta   
   }   
};
#include "daffodil.inc"
object {Daffodil translate <1,-1,1>}
#undef GrnDaf

// ------------------------------------
// row 3
// this is a flower with no leaves
#declare DafLeaves = 0;
#include "daffodil.inc"
object {Daffodil translate <-1,-1,2>}
#undef DafLeaves

// this a flower with more leaves
#declare MinLeaves = 18;
#declare MaxLeaves = 20;
#include "daffodil.inc"
object {Daffodil translate <0,-1,2>}
#undef MinLeaves
#undef MaxLeaves 

// this is a flower that has no random rotation, and a bright red stamen
#declare MaxDrot = 0;
#declare MinDrot = 0;
#declare OrngDaf = texture {
   pigment {Red}
   finish {ambient 1}
};
#include "daffodil.inc"
object {Daffodil translate <1,-1,2>}

                                                                            
                                                                                        