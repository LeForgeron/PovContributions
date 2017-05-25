// Object Name: Pumpkin 
// Version:     01.10.95 for POV 2.2.
// Updated:     17.10.07 To use macros in an include file   
// Description: A pumpkin for Halloween with eye, nose and mouth holes.
// Scale:       1 unit = 0.5 metre diameter pumpkin (All sizes are approximate).
// Positioning: Sphere centred at the origin.
// Details:     A configurable number of copies of a squashed sphere, rotated at different 
//              angles around the Y axis to make a segmented pumpkin shape. 
//              Alternatively a Blob-based pumpkin is slower to render, but more bumpy.
// Keywords:    Pumpkin, Halloween, Vegetables, Market gardening
// Author:      Chris Bartlett.  
// This file is licensed under the terms of the CC-LGPL

//  Sample scene of our smiling pumpkin
#include "pumpkin.inc"

light_source {<2.5, 2.8, -4.8> color rgb <1.2,1.2,1.2> }
camera {location <0.3,0.2,-0.75> look_at  <0.3,0.05,0>}
//camera {location <0.3,0.2,-1.25> look_at  <0,0,0>}

// Example of a bumpy pumpkin made using blobs
#declare Pumpkin_Segments            = 19;  
#declare Pumpkin_SegmentType         = "Blob";      // "Blob"=More realistic or "Sphere"=Quick to render
#declare Pumpkin_SegmentPerturbation = 1;           // 0=Not very perturbed, 1=Very perturbed, 2=Deformed
#declare MyBumpyPumpkin              = union {Pumpkin()}  

// Example of a smooth, quick to render pumpkin made out of spheres
#declare Pumpkin_Segments    = 15;  
#declare Pumpkin_SegmentType = "Sphere";      // "Blob"=More realistic or "Sphere"=Quick to render
#declare MySmoothPumpkin     = union {Pumpkin()}

#declare Pumpkin_Segments    = 10;  
#declare Pumpkin_FaceHolesOn = 0;  
#declare Pumpkin_LightsOn    = 0;  
#declare Pumpkin_SegmentType = "Blob";
#declare MyPlainPumpkin      = union {Pumpkin()}


object {MyPlainPumpkin  rotate y*90  translate <0,-0.5,-0.9> scale 0.3}
object {MySmoothPumpkin rotate -y*45 translate <-0.55,0,0.2>}
object {MyBumpyPumpkin  rotate y*10  translate <0.4,0,0.3>}

// For debug
//Pumpkin_Segment(1)  
//sphere {0,0.01 pigment {color rgb <1,0,0>} translate -z*0.42} 
//cylinder {-z,z,0.003 pigment {color rgb <1,1,0>}}                                 