// tables.pov
// ----------

// Sample scene file for the Tables macro.  
// 
// Created by Chris Bartlett 12.06.2009
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typically takes about 2 seconds to render time
// Default scale is approximately 1 Metre = 1 POV-Ray unit. 
//

camera {location <0.3, 0.6, -0.6> look_at <0,0.2,0>}
light_source {<2,2,-4> color rgb 2}

#include "tables.inc"


// Orange Wood Colors
//#declare Tables_BaseColour1 = 1.1*<0.90, 0.40, 0.04>;
//#declare Tables_BaseColour2 = 1.1*<0.50, 0.10, 0.02>; 
//#declare Tables_ColourVariance  = 0.5;
//#declare Tables_ColourLinearity = 0.8;
//#declare Tables_Brightness = 1;
//#declare Tables_Reflection = 0.05;

//
// Tables
//
#declare BigTable   = Tables("Big Coffee Table")
#declare SmallTable = Tables("Small Coffee Table")

// Add to scene
object {BigTable   rotate  y*3 translate  0.15*x}
object {SmallTable rotate -y*5 translate -0.25*x}


plane {y,0 pigment {crackle scale 0.02}}