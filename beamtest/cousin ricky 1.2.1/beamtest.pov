/* beamtest.pov version 1.2.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstrations of beamtest.inc: a light beam dispersed through a prism, and
 * light beams focused by a parabolic mirror.
 *
 * Copyright 2008 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 *        2008-Jul-27  Created.
 * 1.0    2008-Jul-30  Uploaded.
 * 1.1    2008-Sep-01  No changes.
 *        2012-Jun-29  Tested using POV-Ray 3.5, with some freakishly odd
 *                     results.
 *        2012-Jun-29  #version is set to 3.6.
 * 1.1.1  2012-Jun-30  No changes; re-rendered using POV-Ray 3.7.0.RC6 to show
 *                     3.7's improved dispersion.
 * 1.2    2014-Nov-01  Collect on is set for the refracting object.  This
 *                     happens not to be necessary for this particular scene,
 *                     but in some scenes POV-Ray 3.7 renders spurious beams
 *                     when collect off is used.
 * 1.2.1  2019-Mar-24  No change.
 */
// POV-Ray 3.6:
//   +A0.3 +AM2 +R3 -J +W640 +H480
// POV-Ray 3.7:
//   +A0.3 +AM2 +R3 -J +W640 +H480 +RP5
#version 3.6;

#declare Beam_photons_media = 400;

#include "beamtest.inc"
#include "colors.inc"
#include "transforms.inc"

//----------------------------- Glass prism test -------------------------------

#declare Prism_blank = prism
{ -1, 1, 4, <1, 0>, <-1, 0>, <0, sqrt(3)>, <1, 0>
  rotate -90 * x
  translate -sqrt(3)/3 * y
}

object
{ Prism_blank scale <1, 1, Beam_radius>
 // A refracting object must be declared hollow for the light beams to show:
  hollow
  pigment { rgbt 1 }
  finish { specular 1 } // Makes the prism visible.
  interior { ior 1.65 dispersion 1.035 dispersion_samples 10 }
 // The tested object must be a target:
  photons { target refraction on collect on }
  translate 2.35 * y
}

Beam_targeted (0.35, 1, 2.85 * y)

//-------------------------- Parabolic mirror test -----------------------------

#declare I = 0;
#while (I < 12)
  Beam_angled (-0.3 * I, CH2RGB (mod (I + 11, 12) * 30) * 0.6 + 0.4, 0)
  #declare I = I + 1;
#end

// The mirror:
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
 // The tested object must be a target:
  photons { target reflection on collect off }
}
// end of beamtest.pov
