// envelope_textures.inc
// ---------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This include file declares a range of textures suitable for use with the 'Envelope_' macro from the 
// 'envelope.inc' file. 
// See the envelope.html file accompanying this file for documentation of these textures.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//

// The default stamp texture incorporates the POV-Ray logo
#ifndef(Povray_Logo_Prism) #include "logo.inc" #end     
#declare Envelope_StampLogo  = union {
  object {Povray_Logo_Prism translate <1,1.05,0> scale 0.009 rotate x*90}
  text {ttf "timrom.ttf" "1"  1,0 translate <0.2,0.6,-0.1> scale 0.005 rotate x*90}
  text {ttf "timrom.ttf" "ST" 1,0 translate <1.2,2.2,-0.1> scale 0.0022 rotate x*90}
}

// Default Texture Settings
#declare Envelope_DefaultAddressTexture = texture {pigment {rgb 0}};
#declare Envelope_DefaultTexture        = texture {pigment {rgb <1,0.85,0.7>}};
#declare Envelope_DefaultLabelTexture   = texture {pigment {rgb <1,1,0.8>}}
#declare Envelope_DefaultStampTexture   = texture {pigment {object{Envelope_StampLogo color <0,0,0.2> color <1,1,0>}}}
#declare Envelope_DefaultWindowTexture  = texture {pigment {rgbt <1,1,1,0.95>}}
#declare Envelope_DefaultContentTexture = texture {pigment {rgb 1}}    

// A mottled brown sort of texture 
#declare Envelope_MottledTexture        = texture {
//  pigment {rgb <1,0.85,0.7>}
  pigment {agate 
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
  normal  {wrinkles 0.3 scale 0.1}
}

// A white texture with a little bit of marbeling
#declare Envelope_WhiteTexture        = texture {
//  pigment {rgb <1,1,1>}
  pigment {marble 
    color_map {
      [0.0  color rgb 1]
      [1.0  color rgb 1*0.95]
    }
    turbulence 2
    scale 0.005
  }
  normal  {agate 0.01 scale 0.01}
}

// A speckled brown texture
#declare Envelope_SpeckledTexture        = texture {
  pigment {agate 
    color_map {
      [0.1  color rgb <1,0.85,0.7>]
      [0.3  color rgb <1,0.95,0.75>*0.8]
      [0.6  color rgb <1,0.95,0.75>*0.9]
      [0.6  color rgb <1,0.95,0.75>*0.9]
      [0.8  color rgb <1,0.85,0.7>*0.95]
    }
    turbulence 2
    scale 0.005
  }
  normal  {wrinkles 0.1 scale 0.1}
}

// A more psychedelic/artistic sort of red marble texture 
#declare Envelope_RedTexture        = texture {
//  pigment {rgb <1,0.85,0.7>}
    pigment {marble 
    turbulence 2
    scale 0.005
  }
  normal  {wrinkles 0.1 scale 0.1}
} 

// Brown with a crackle normal to make the envelope look like it's been crumpled up
#declare Envelope_CrumpledTexture        = texture {
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
  normal  {crackle 0.3 scale 0.1}
}

// A translucent texture for the plastic/paper window in a windowed envelope
#declare Envelope_WrinklyWindowTexture  = texture {
  pigment {rgbt <1,1,1,0.95>}
  finish  {phong 1 reflection {0.3}}
  normal  {wrinkles 0.2 scale 0.01}
}
