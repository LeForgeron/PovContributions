// This file is licensed under the terms of the CC-LGPL
//
// Persistence of Vision Ray Tracer Scene Description File
// File: PipeMrg.pov
// Vers: 2.0 (for POV 3.6+)
// Desc: A demo of the PipeMrg macro
// Date: 9/27/2009
// Auth: Tim Attwood
//

#include "colors.inc"
#include "finish.inc"

// include the macro
#include "PipeMrg.inc"

// --- camera, lights & background ------------------------------------------

camera {
   location  <0.0, 0.5, -4.0>
   direction 1.5*z
   right     x*image_width/image_height
   look_at   <0.0, 0.0,  0.0>
}

background {White}

light_source {
  <-30, 30, -30>           
  color rgb <1, 1, 1> 
}

// --- textures -------------------------------------------------------------
#declare joint_tex = texture {
   pigment{LimeGreen}
   finish {Dull}
};
#declare cyl_tex = texture {
   pigment{Red}
   finish {Dull}
};

// --- scene ----------------------------------------------------------------                                                                             

object {  
   // location, cylinder radius, saddle radius, angle, rotation
   PipeMrg (<0,0,0>,0.25,0.1,45,<0,0,0>)
   texture {joint_tex}
}
object { 
   PipeMrg (<0,0,0>,0.25,0.5,135,<0,0,45>)
   texture {joint_tex}
}
object { 
   PipeMrg (<0,0,0>,0.25,0.25,45,<0,0,180>)
   texture {joint_tex}
}
object { 
   PipeMrg (<0,0,0>,0.25,0.15,135,<0,0,225>)
   texture {joint_tex}
}


// the first cylinder
cylinder {
   <-1.4,0,0>,<1.4,0,0>,0.25
   texture {cyl_tex}
}
// the second cylinder
cylinder {
   <-1,-1,0>,<1,1,0>,0.25
   texture {cyl_tex}
}


                                                                                        