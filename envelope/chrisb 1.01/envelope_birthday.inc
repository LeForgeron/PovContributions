// envelope_birthday.inc
// ---------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This file can be used before calling the Envelope_ macro to modify variable settings. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//

#declare Envelope_Style = "social";
#declare Envelope_Width            = 0.18;  
#declare Envelope_Depth            = 0.12;  
#declare Envelope_Thickness        = 0.0015;
#declare Envelope_LabelWidth       = Envelope_Width/2;
#declare Envelope_LabelDepth       = Envelope_Depth/3;
#declare Envelope_LabelThickness   = 0.0003;
#declare Envelope_LabelRounding    = 0.008; 
#declare Envelope_LabelLeftEdge    = (Envelope_Width-Envelope_LabelWidth)/2;
#declare Envelope_LabelBottomEdge  = (Envelope_Depth-Envelope_LabelDepth)/2;
#declare Envelope_WindowWidth      = Envelope_Width/2;         
#declare Envelope_WindowDepth      = Envelope_Depth/3;        
#declare Envelope_WindowRounding   = Envelope_WindowWidth/12; 
#declare Envelope_WindowLeftEdge   = (Envelope_Width-Envelope_WindowWidth)/2;
#declare Envelope_WindowBottomEdge = (Envelope_Depth-Envelope_WindowDepth)/2;
#declare Envelope_StampWidth       = 0.02;  
#declare Envelope_StampDepth       = 0.023; 
#declare Envelope_StampThickness   = 0.0002;
#declare Envelope_StampHoleSize    = 0.0005;
#declare Envelope_StampBorderSize  = 0.0015;
#declare Envelope_StampInsetRight  = 0.01;
#declare Envelope_StampInsetTop    = 0.01;
#declare Envelope_FlapLength       = 0.07;

#declare Envelope_FlapLocation     = "Top";  
#declare Envelope_FlapAngle        = 176;      
#declare Envelope_FlapChamferAngle = 45;     

#declare Envelope_StampOn   = 0;
#declare Envelope_WindowOn  = 0;
#declare Envelope_LabelOn   = 0;                                  
#declare Envelope_AddressOn = 1;

#declare Envelope_Address = array[3] {   
  " ",
  "To",
  "   Sue",
}

#declare Envelope_Texture        = Envelope_WhiteTexture;
#declare Envelope_LabelTexture   = Envelope_DefaultLabelTexture;
#declare Envelope_StampTexture   = Envelope_DefaultStampTexture;
#declare Envelope_WindowTexture  = Envelope_DefaultWindowTexture;
#declare Envelope_ContentTexture = Envelope_DefaultContentTexture;  
#declare Envelope_AddressTexture = texture {pigment {checker color <0,2,2> color <2,2,0> scale 0.1 rotate z*45}};

