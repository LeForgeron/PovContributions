/* beamtest.pov version 1.1.1
 * Persistence of Vision Raytracer scene file
 * POV-Ray Object Collection demo
 *
 * Demonstration of beamtest.inc.
 *
 * Copyright 2008 - 2012 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 *        27-jul-2008  Created.
 * 1.0    30-jul-2008  Ready for upload.
 * 1.1        n/a      No changes.
 *        29-jun-2012  Tested using POV-Ray 3.5, with some freakishly odd
 *                     results.
 *        29-jun-2012  #version is set to 3.6.
 * 1.1.1  30-jun-2012  Re-rendered using POV-Ray 3.7.0.RC6, to show 3.7's
 *                     improved dispersion.
 */
//+a0.3 +am2 +r3 -j +w640 +h480
#version 3.6;

#declare Beam_photons_media = 400;

#include "beamtest.inc"
#include "colors.inc"
#include "transforms.inc"

//----- Glass prism test -----

#declare Prism_blank = prism
{ -1, 1, 4, <1, 0>, <-1, 0>, <0, sqrt(3)>, <1, 0>
  rotate -90 * x
  translate -sqrt(3)/3 * y
}

object
{ Prism_blank scale <1, 1, Beam_radius>
  hollow //A refracting object must be declared hollow for the test to work.
  pigment { rgbt 1 }
  finish { specular 1 }
  interior { ior 1.65 dispersion 1.035 dispersion_samples 10 }
  photons { target refraction on collect off } //tested object must be a target
  translate 2.35 * y
}

Beam_targeted (0.35, 1, 2.85 * y)

//----- Parabolic mirror test -----

#declare I = 0;
#while (I < 12)
  Beam_angled (-0.3 * I, CH2RGB (mod (I + 11, 12) * 30) * 0.6 + 0.4, 0)
  #declare I = I + 1;
#end

difference
{ box
  { <-0.2025, -1.8, -Beam_radius>, <0.5, 1.8, Beam_radius>
    pigment { rgb 1 }
  }
  quadric
  { y/16, 0, x, 0
    pigment { rgb 1 }
    finish { reflection 1 diffuse 0 ambient 0 }
  }
  translate <-Beam_fixture_x - 0.5, -1.65, 0>
  photons { target reflection on collect off } //tested object must be a target
}
