// This file is licensed under the terms of the CC-LGPL.

/***************************************************************************************************/
/* Eye.pov  - Copyright Chris Bartlett 7 May 2004                                                  */
/* This work is also licensed for royalty free re-use under the terms of the POV-Person License.   */
/* To view a copy of this license, visit http://www.telinco.co.uk/c_bartlett/license/license.htm   */
/***************************************************************************************************/ 

global_settings { max_trace_level 10 }
#declare Eye_Camera="Mine";     // Otherwise it uses the default camera definition in Eye.inc 
#include "Eye.inc"

// Draw one eye with the default settings
object{Eye() rotate  y*10 translate  1.7*x}

// Same again, but changing just the eye colour
#declare Eye_Colour = 2;          // 1=Blue, 2=Brown, 3=Green 
object{Eye() rotate -y*10 translate -1.7*x}

// Draw a third, larger eye, changing a number of other settings too
#declare Eye_Radius = 2;
#declare Eye_Colour = 1;         // 1=Blue, 2=Brown, 3=Green 
#declare Eye_Brightness = 0.9;   // Normally between 0.5 and 1                     
#declare Eye_Pupil = 0.8;        // Normally between 0.5 and 1.2  
#declare Eye_OuterTexture = texture {pigment {color rgb <1,1,1>} finish {phong 0.8}}
#declare Eye_InnerTexture = texture {pigment {color rgb <1,0,0> } finish {ambient 2}}                                            
object {Eye() translate <0,2.5,5>}


// Position the camera and add lighting
#if (strcmp(Eye_Camera,"Mine")=0)  
  camera {
    location <-4, 2, -12>
    look_at <-1, 1.5, 0>
    angle 34.3775
  }
  
  light_source { <250, 60,-8900> color rgb<1, 1, 1>*0.6 }   
  light_source { <0, 1400,-1600> color rgb<1, 1, 1>*1.2 }   
  light_source { <0, 60,0> color rgb<1, 0.5, 0.5>}  
#end                                                    
