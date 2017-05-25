// OSE_envelope_birthday.inc
// ------------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This file can be used before calling the OSE_Envelope macro to modify variable settings. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//

#declare OSE_EnvelopeStyle = "social";
#declare OSE_EnvelopeWidth            = 0.18;  
#declare OSE_EnvelopeDepth            = 0.12;  
#declare OSE_EnvelopeThickness        = 0.0015;
#declare OSE_EnvelopeLabelWidth       = OSE_EnvelopeWidth/2;
#declare OSE_EnvelopeLabelDepth       = OSE_EnvelopeDepth/3;
#declare OSE_EnvelopeLabelThickness   = 0.0003;
#declare OSE_EnvelopeLabelRounding    = 0.008; 
#declare OSE_EnvelopeLabelLeftEdge    = (OSE_EnvelopeWidth-OSE_EnvelopeLabelWidth)/2;
#declare OSE_EnvelopeLabelBottomEdge  = (OSE_EnvelopeDepth-OSE_EnvelopeLabelDepth)/2;
#declare OSE_EnvelopeWindowWidth      = OSE_EnvelopeWidth/2;         
#declare OSE_EnvelopeWindowDepth      = OSE_EnvelopeDepth/3;        
#declare OSE_EnvelopeWindowRounding   = OSE_EnvelopeWindowWidth/12; 
#declare OSE_EnvelopeWindowLeftEdge   = (OSE_EnvelopeWidth-OSE_EnvelopeWindowWidth)/2;
#declare OSE_EnvelopeWindowBottomEdge = (OSE_EnvelopeDepth-OSE_EnvelopeWindowDepth)/2;
#declare OSE_EnvelopeStampWidth       = 0.02;  
#declare OSE_EnvelopeStampDepth       = 0.023; 
#declare OSE_EnvelopeStampThickness   = 0.0002;
#declare OSE_EnvelopeStampHoleSize    = 0.0005;
#declare OSE_EnvelopeStampBorderSize  = 0.0015;
#declare OSE_EnvelopeStampInsetRight  = 0.01;
#declare OSE_EnvelopeStampInsetTop    = 0.01;
#declare OSE_EnvelopeFlapLength       = 0.07;

#declare OSE_EnvelopeFlapLocation     = "Top";  
#declare OSE_EnvelopeFlapAngle        = 176;      
#declare OSE_EnvelopeFlapChamferAngle = 45;     

#declare OSE_EnvelopeStampOn   = 0;
#declare OSE_EnvelopeWindowOn  = 0;
#declare OSE_EnvelopeLabelOn   = 0;                                  
#declare OSE_EnvelopeAddressOn = 1;

#declare OSE_EnvelopeAddress = array[3] {   
  " ",
  "To",
  "   Sue",
}

#declare OSE_EnvelopeTexture        = OSE_EnvelopeWhiteTexture;
#declare OSE_EnvelopeLabelTexture   = OSE_EnvelopeDefaultLabelTexture;
#declare OSE_EnvelopeStampTexture   = OSE_EnvelopeDefaultStampTexture;
#declare OSE_EnvelopeWindowTexture  = OSE_EnvelopeDefaultWindowTexture;
#declare OSE_EnvelopeContentTexture = OSE_EnvelopeDefaultContentTexture;  
#declare OSE_EnvelopeAddressTexture = texture {pigment {checker color <0,2,2> color <2,2,0> scale 0.1 rotate z*45}};

