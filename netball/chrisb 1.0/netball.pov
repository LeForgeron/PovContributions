// Netball.pov
// -----------

// Sample scene illustrating the use of the NB_Netball Macro for generating a Netball Object  
// Created by Chris Bartlett 07.02.2005
// This file is licensed under the terms of the CC-LGPL.
// Source http://lib.povray.org/
// Typical render time 1 to 3 minutes, depending on settings etc.
// This example renders a ball of 1 POV-Ray unit radius at <1,0,0> and a second at <-1,0,0>

camera {location<3,1.1,-1.4> look_at<0.2,-0.2,0>}
light_source{<30,30,-20>  color rgb 1}  
light_source{<10,30,-200> color rgb 1} 
#include "Netball.inc" 


// Configurable settings
// ---------------------

#declare NB_BallRadius     = 1;  // Gives a 1 POV-Ray unit radius ball centred at the origin                                                   
#declare NB_BallTexture    = texture {pigment {color rgb <1,1,1>} }

// Settings applicable only to Stitched ball
#declare NB_StitchTexture  = texture {pigment {color rgb <1,1,0>}} 
#declare NB_BladderTexture = texture {pigment {color rgb <1,0.8,0>} }

// Setting applicable only to Moulded ball
#declare NB_IndentTexture  = texture {pigment {color rgb <0.1,1,0.2>}} 


// Generate one of each
object {NB_Netball("Stitched") translate  x} 
object {NB_Netball("Moulded")  translate -x} 





