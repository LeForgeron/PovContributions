
// envelope_testbed.pov
// --------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This scene file displays a single envelope using the 'Envelope_' macro from the 'envelope.inc' file.
// This is a very simple scene intended to help develop textures and styles.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// Render time is typically 1-2 seconds.

light_source { <-15,7.5,-1.5>, rgb 2}
camera {location <-0.05,0.16,-0.16> look_at 0}

#include "envelope.inc"

#declare Envelope_Crumple = 0.3; 

#declare Envelope_Texture = 
texture {
  pigment {crackle 
    color_map {
      [0.1  color rgb <1,0.95,0.75>]
      [0.3  color rgb <1,0.95,0.75>*0.8]
      [0.6  color rgb <1,0.95,0.75>*0.9]
      [0.6  color rgb <1,0.95,0.75>*0.9]
      [0.8  color rgb <1,0.95,0.75>*0.95]
    }
    turbulence 1
    scale 0.01
  }

  #ifdef(Envelope_Crumple) normal  {crackle Envelope_Crumple scale 0.1} #end
}   
    

object {Envelope() translate -0.5*<Envelope_Width,0,Envelope_Depth>}  

