/* integratelight_compare.pov version 1.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Compare colors of certain lamps by SpectralRender vs. IntegrateLight.
 * In preview mode, the two methods yield nearly identical colors, but in
 * spectral mode, there are striking differences.
 *
 * Copyright 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       2016-Jul-11  Adapted from a test scene.
 * 1.0   2016-Nov-14  Uploaded.
 */
// Preview:
//   +W480 +H360 +A +AM1 +R5 -J Declare=Preview=1
// Pass 1:
//   +W480 +H360 +A +AM1 +R5 -J +FE +KI1 +KF36 +KFI38 +KFF73
// Pass 2:
//   +W480 +H360 -A
// Before running pass 2, make sure ALL of the #declare FName lines in
// SpectralComposer.pov are commented out.
//
// After running pass 2, you may delete the integratelight_compare??.exr files.
#version 3.7;

#ifndef (Preview) #declare Preview = no; #end

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%% CREATE THE SCENE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#if (clock_on | Preview)

  #include "shapes.inc"
  #include "spectral.inc" // from SpectralRender
  #include "integratelight.inc"

  global_settings { assumed_gamma 1 }

  #declare WSWATCH = 8;
  #declare WIDTH = 4 * WSWATCH + 3;
  #declare HEIGHT = WIDTH * 0.75;
  #declare HSWATCH = (HEIGHT - 4) / 3;
  camera
  { orthographic
    location <2 * WSWATCH + 0.5, 1.5 * HSWATCH + 1, -10>
    right WIDTH * x
    up HEIGHT * y
  }

  #default { finish { ambient 0 diffuse 0 emission 1 } }

  #declare Stocks = array[6] // from SpectralRender: spectral_lights.inc
  { E_Mitsubishi_Daylight_Fluorescent,
    E_Mitsubishi_Metal_Halide,
    E_Mitsubishi_Moon_Fluorescent,
    E_Mitsubishi_Standard_Fluorescent,
    E_Phillips_HPS,
    E_Phillips_Mastercolor_3K,
  }
  #declare Curves = array[6] // from Lightsys IV: espd_lightsys.inc
  { ES_Mitsubishi_Daylight_Fluorescent,
    ES_Mitsubishi_Metal_Halide,
    ES_Mitsubishi_Moon_Fluorescent,
    ES_Mitsubishi_Standard_Fluorescent,
    ES_Phillips_HPS,
    ES_Phillips_Mastercolor_3K,
  }
 // Integral step sizes:
  #declare Steps = array[6] { 5, 5, 5, 5, 1, 1 }
 // Pre-calculated adjustment factors to match the lightness of SpectralRender
 // lamps with those normalized by Lightsys IV:
  #declare Adjs = array[6]
  { 1.166, 1.459, 1.188, 1.046, 1.717, 1.113,
  }
  #declare s_Names = array[6][2]
  { { "Mitsubishi", "daylight fluorescent", }
    { "Mitsubishi", "metal halide", }
    { "Mitsubishi", "moon fluorescent", }
    { "Mitsubishi", "standard fluorescent", }
    { "Philips", "high pressure sodium", }
    { "Philips", "MasterColor 3K", }
  }

  #for (Row, 0, 2)
    #for (Col, 0, 1)
      #local Ix = Row * 2 + Col;
      union
      { box // SpectralRender stock lamp on the left
        { 0, <WSWATCH, HSWATCH, 1>
          pigment
          { SpectralEmission (Stocks[Ix])
             // Adjust only in spectral mode.  In preview mode, SpectralRender
             // defers to Lightsys IV, which always normalizes.
              * (SpectralMode? Adjs[Ix]: 1)
          }
        }
        box // IntegrateLight lamp on the right
        { 0, <WSWATCH, HSWATCH, 1> translate WSWATCH * x
          #declare CIE_IntegralStep = Steps[Ix];
          pigment
          { SpectralEmission (ILight_Continuous (Curves[Ix], no, ILIGHT_XYZ, 1))
          }
        }
        object // Annotation
        { Center_Object
          ( union
            { Center_Object
              ( text { ttf "cyrvetic" s_Names[Ix][0] 1, 0 translate y }, x
              )
              Center_Object
              ( text { ttf "cyrvetic" s_Names[Ix][1] 1, 0 }, x
              )
            },
            y
          )
          pigment { rgb 0 }
          scale 1.3
          translate <WSWATCH, HSWATCH / 2, -1>
        }
        translate <Col * (2 * WSWATCH + 1), (2 - Row) * (HSWATCH + 1), 0>
      }
    #end
  #end

  #if (!SpectralMode)
    object
    { Center_Object (text { ttf "cyrvetic" "Preview" 1, 0 }, x)
      pigment { rgb 1 }
      scale 1.5
      translate <2 * WSWATCH + 0.5, HEIGHT * 0.5, -1>
    }
  #end

//%%%%%%%%%%%%%%%%%%%%%%%%%%% ASSEMBLE THE FRAMES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#else

  // Make sure ALL of the #declare FName lines in SpectralComposer.pov
  // are commented out, or this next #declare will be overridden!
  #declare FName = "integratelight_compare"
  #include "SpectralComposer.pov" // from SpectralRender

#end

// End of integratelight_compare.pov
