/* beamtest_spectral.pov version 1.2
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstration of beamtest.inc using SpectralRender.
 * Download SpectralRender at:
 *   http://www.lilysoft.org/CGI/SR/Spectral%20Render.htm
 * Download Lightsys IV at:
 *   http://www.ignorancia.org/en/index.php?page=Lightsys
 *
 * Copyright 2014 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       18-Jul-2014  Created.
 * 1.2   01-Nov-2014  Debugged and uploaded.
 */
// This scene is to be rendered in two passes.
// Pass 1:
//   +W640 +H480 +A0.3 +AM2 +R3 -J +FE +KI1 +KF36 +KFI38 +KFF73 +RP5
// Pass 2:
//   +W640 +H480 -A
// IMPORTANT:  Before running pass 2, make sure ALL of the #declare FName
// lines in SpectralComposer.pov are commented out.
//
// After both passes are completed, the .exr files may be deleted.
#version 3.7;

#if (clock_on) // PASS 1

  #include "spectral.inc" // from SpectralRender
 // This next parameter keeps the environmental lighting white when
 // SpectralRender is used.  (If not set, all reflective objects would
 // have a pinkish cast.)
  #declare Beam_c_lighting = SpectralEmission (E_D65);

  #declare Beam_photons_media = 400;
  #include "beamtest.inc"
  #include "transforms.inc"

 //------------------ Glass prism test --------------------

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
    interior { IOR_Spectral (IOR_FlintGlass_SF2) }
   // The tested object must be a target:
    photons { target refraction on collect off }
    translate 2.35 * y
  }

  Beam_targeted (0.35, SpectralEmission (E_Sunlight), 2.85 * y)

 //--------------- Parabolic mirror test ------------------

  #declare Lights = array[12]
  #declare Lights[0] = array[36]
  { 0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130,
    0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703,
    1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000,
  }
  #declare Lights[1] = array[36]
  { 0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703,
    0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000,
  }
  #declare Lights[2] = array[36]
  { 0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297,
    0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668,
    0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
  }
  #declare Lights[3] = array[36]
  { 0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332,
    0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130,
    0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
  }
  #declare Lights[4] = array[36]
  { 0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870,
    0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
  }
  #declare Lights[5] = array[36]
  { 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000,
    0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297,
  }
  #declare Lights[6] = array[36]
  { 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870,
    0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332,
  }
  #declare Lights[7] = array[36]
  { 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130,
    0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332,
    0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870,
  }
  #declare Lights[8] = array[36]
  { 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668,
    0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000,
  }
  #declare Lights[9] = array[36]
  { 0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703,
    1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870,
  }
  #declare Lights[10] = array[36]
  { 0.4000, 0.4297, 0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703,
    0.8870, 0.7668, 0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130,
    0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332,
  }
  #declare Lights[11] = array[36]
  { 0.5130, 0.6332, 0.7668, 0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668,
    0.6332, 0.5130, 0.4297, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4000,
    0.4000, 0.4000, 0.4000, 0.4000, 0.4000, 0.4297, 0.5130, 0.6332, 0.7668,
    0.8870, 0.9703, 1.0000, 0.9703, 0.8870, 0.7668, 0.6332, 0.5130, 0.4297,
  }

  #for (I, 0, 11)
    Beam_angled (-0.3 * I, SpectralEmission (Lights[I]), 0)
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
    photons { target reflection on collect on }
  }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#else // PASS 2

 // IMPORTANT:
 // Make sure ALL of the #declare FName lines in SpectralComposer.pov
 // are commented out, or this next #declare will be overridden!
  #declare FName = "beamtest_spectral"
  #include "SpectralComposer.pov" // from SpectralRender

#end
