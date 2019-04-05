/* spectrum.pov version 4.0.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstration of spectrum.inc macros.
 *
 * Copyright 2014 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 * 4.0    2014-Jan-10  Created.
 * 4.0.1  2019-Apr-02  No change.
 */
// +w640 +h480 +a0.0 -j +r5
#version 3.5;

#include "shapes.inc"
#include "spectrum.inc"

global_settings { assumed_gamma 1 }

#default { finish { ambient 1 diffuse 0 } }
//Note:  For #version 3.7; ambient 0 diffuse 0 emission 1 is recommended.

#declare WTICK = 400 / 640;

camera
{ orthographic
  location <565 - WTICK/2, 150, -10>
  right 400 * x
  up 300 * y
}

// Lower, horizontal spectrum
#declare p_Major = Spectrum_Rule_p (WTICK / 50, rgb 1)
#declare p_Minor = Spectrum_Rule_p (WTICK / 10, rgb 1)

box
{ 0, 1
  texture { Spectrum_Special_p() }
  scale <1000, 1, 1>
  texture
  { pigment
    { gradient y pigment_map
      { [0.1 p_Minor scale 10]
        [0.1 p_Major scale 50]
        [0.2 p_Major scale 50]
        [0.2 rgbt 1]
      }
    }
  }
  scale <1, 120, 1>
  translate 20 * y
}

// Wavelength labels
#declare W = 400;
#while (W <= 750)
  object
  { Center_Object (text { ttf "cyrvetic" str(W,0,0) 1, 0 }, x)
    pigment { rgb 0.7 }
    scale 8
    translate <W, 8, 0>
  }
  #declare W = W + 50;
#end

// Upper, vertical spectrum on white background
#declare Data = array[10][4]
{ { 380, 1, 1, 1 },
  { 435, 0.2278, 0, 1 },
  { SPECTRUM_BLUE, 0, 0, 1 },
  { SPECTRUM_CYAN, 0, 0.5, 0.5 },
  { SPECTRUM_GREEN, 0, 0.9, 0 },
  { SPECTRUM_YELLOW, 0.8, 0.8, 0 },
  { 585, 1, 0.3464, 0 },
  { SPECTRUM_RED, 1, 0, 0 },
  { 630, 1, 0, 0.06 },
  { 730, 1, 1, 1 }
}
#declare p_Light = Spectrum_Make_p (Data)
#declare p_Light = pigment
{ p_Light
  rotate 90 * z
  translate -0.4 * y
  scale 1 / 0.3
}

box
{ 0, 1
  pigment
  { gradient x pigment_map
    { [0.15 rgb 1]
      [0.15 p_Light]
      [0.85 p_Light]
      [0.85 rgb 1]
    }
  }
  scale <160, 140, 1>
  translate <485, 150, 0>
}
// end of spectrum.pov
