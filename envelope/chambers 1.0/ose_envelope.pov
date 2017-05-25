
// OSE_envelope.pov
// ---------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This scene file demonstrates the use of the 'OSE_Envelope' macro from the 'OSE_envelope.inc' file
// by creating a series of different types of envelope.
// The control variables are documented in the OSE_envelope.html file accompanying this file.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// Render time is typically 10-20 seconds (for 8 envelopes).

light_source { <-15,7.5,-1.5>, rgb 2}
camera {location <0.08,0.16,-0.16> look_at <0.1,0.06,0.1>}

#include "OSE_envelope.inc"        

// Envelope 1 - The default settings generate an envelope laying flat on the XZ plane with its bottom left corner at the origin
OSE_Envelope()  

// Envelope 2 -  To reposition it just wrap it in an object statement
#declare OSE_EnvelopeFlapAngle = 80; 
object {OSE_Envelope() rotate <180,-35,0> translate <-0.2,0.0005,0.3>}  

// Envelope 3 - Change the shape and style using settings from a standard include file
#include "OSE_envelope_birthday.inc" 
object {OSE_Envelope() rotate <0,40,1> translate <-0.15,0,0.1>}   
 

// Any time we need to we can clear down the variables so previous settings don't interfere with future 
// macro calls.
OSE_EnvelopeUndef()  

// Envelope 4 - Use an ISO standard size code, open the flap and have some paper sticking out
OSE_EnvelopeSize("DL")
#declare OSE_EnvelopeWindowOn  = 1;
#declare OSE_EnvelopeAddressOn = 0;
#declare OSE_EnvelopeLabelOn   = 0;                                  
#declare OSE_EnvelopeStampOn   = 0;
#declare OSE_EnvelopeWindowLeftEdge = 0.08; 
#declare OSE_EnvelopeWindowBottomEdge = 0.02;
#declare OSE_EnvelopeFlapAngle = 179; 
#declare OSE_EnvelopeTexture   = texture{pigment{rgb <0.9,1,0.9>}}
      
union {
  OSE_Envelope() 
  // Add a piece of paper sticking out the right hand side of the envelope
  // Note. We can use the variables set during the macro call in the definition of our piece of paper
  box {0,<0.9*OSE_EnvelopeWidth,OSE_EnvelopeThickness/4,0.9*OSE_EnvelopeDepth> 
    texture {OSE_EnvelopeContentTexture} 
    translate <0.35*OSE_EnvelopeWidth,OSE_EnvelopeThickness/4,0.05*OSE_EnvelopeDepth>
  }
  rotate y*55 rotate x*0.4 
  translate <-0.08,0,0.33>
}   


// Undefine all the envelope control variables
OSE_EnvelopeUndef()  


// We can define a transformation to help stack envelopes together in a holder
#declare LetterHolderPosition = transform {rotate <0,40,0> translate <0.1,0,0.3>}


// Envelope 5 - Increase the size of the stamp and use an image map for the stamp design. 
// Use the predefined crumpled envelope texture.
#declare OSE_EnvelopeStampWidth       = 0.05;   
#declare OSE_EnvelopeStampDepth       = 0.03;
#declare OSE_EnvelopeStampBorderSize  = 0.0015;
#declare OSE_EnvelopeStampTexture = texture {
  pigment {
    image_map {sys "OSE_envelope.bmp"}
    rotate x*90
    scale <(OSE_EnvelopeStampWidth-2*OSE_EnvelopeStampBorderSize),1,(OSE_EnvelopeStampDepth-2*OSE_EnvelopeStampBorderSize)>
  }
}
#declare OSE_EnvelopeTexture = OSE_EnvelopeCrumpledTexture;
object {OSE_Envelope() rotate -x*90 translate -x*0.005 transform {LetterHolderPosition}}  

// Envelope 6 - Change the texture, but otherwise keep the previous settings.
#declare OSE_EnvelopeTexture = OSE_EnvelopeRedTexture; 
// rotate and move it a little bit relative to the last one before adding into the letter holder 
object {OSE_Envelope() rotate <-89,0,1> translate <0.005,0,OSE_EnvelopeThickness> transform {LetterHolderPosition}}  

// Reset the envelope control variables so we get back to the default envelope
OSE_EnvelopeUndef()  
// Envelopes 7 & 8 - Something to add a bit of volume to the letter rack.
object {OSE_Envelope() rotate <-89,0,-1>  translate <0.004,0,OSE_EnvelopeThickness*2> transform {LetterHolderPosition}}  
object {OSE_Envelope() rotate <-89,0,0.9> translate <0.005,0,OSE_EnvelopeThickness*3> transform {LetterHolderPosition}}  

// Add a front and back panel to form a very simple letter rack
union {
  box {<0.08,0,-0.005><0.17,0.075,0>}
  box {<0.08,0,-0.005><0.17,0.075,0> translate <0,0,OSE_EnvelopeThickness*5>}
  pigment {color rgb 1} 
  transform {LetterHolderPosition} 
} 

// Add in a sheet of stamps 
#declare OSE_StampBookArray = array [3][2];  
// Remove 1 stamp from the top left hand corner
#declare OSE_StampBookArray[0][1] = 0;
object {OSE_StampSheet(3, 2, OSE_EnvelopeStampWidth, OSE_EnvelopeStampDepth, OSE_EnvelopeStampThickness, OSE_EnvelopeStampHoleSize, OSE_EnvelopeStampBorderSize, OSE_EnvelopeStampTexture)
  rotate y*20 
  translate <0.1,OSE_EnvelopeThickness*1.1,0.016>
}
