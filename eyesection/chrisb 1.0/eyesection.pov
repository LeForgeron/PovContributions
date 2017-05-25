//
// eyesection.pov
// --------------
//
// Created by Israel Barzel 1997  
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett
// This scene file illustrates the use of the 'eyesection.inc' file which adds a
// model of the section of the front part of the eye to your scene. It can 
// also optionaly add the tools used to perform phacoemulcification (modern 
// cataract surgery) to the model.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The model is about 50 POV-Ray units in height and, by default, the centre of the 
// eye is centred at the origin.
//
// Adding this model to your scene is likely to add a few seconds to the render time.
//
// The following variables can be used to control the generated object.
// See eyesection.html for more details
//
//#declare EyeSection_CutLens           = false;   // true or false
//#declare EyeSection_PhacoProbeDepth   = 0;       // 0 to 1
//#declare EyeSection_InfusionTubeDepth = 0;       // 0 to 1
//
//#declare EyeSection_SectionLens       = false;   // true or false
//#declare EyeSection_SectionIris       = false;   // true or false
//#declare EyeSection_SectionOra        = false;   // true or false
//#declare EyeSection_SectionCornea     = false;   // true or false
//#declare EyeSection_SectionChoroid    = false;   // true or false
//#declare EyeSection_SectionRetina     = false;   // true or false
//#declare EyeSection_SectionSclera     = false;   // true or false
//#declare EyeSection_SectionOpticNerve = false;   // true or false
// 


// Closeup of Optics at the front of the eye
camera {
  location  < -20, 40,-60>
  look_at   < 0,18,0>       
  angle 30
}

// Alternative view of entire object
//camera {
//  location  < -60, 80,-120> 
//  look_at 0
//  angle 30
//}

global_settings {
  max_trace_level 10
}

light_source {   // Light001
  <0, 60, -0.3>
  color rgb <1.000, 1.000, 1.000>
}

light_source {   // Light1
  <-0.4, 32, -43>
  color rgb <1.000, 1.000, 1.000>
  shadowless
}

light_source {   // Arealight AreaL2
  <0.5, 56, 0>
  color rgb <1.000, 1.000, 1.000>
  area_light <2.000, 0.000, 0.000>, <0.000, 2.000, 0.000>, 3, 3
  adaptive 1
  jitter
  shadowless
  scale 29.955313
}


object {
  #include "eyesection.inc" 
}



