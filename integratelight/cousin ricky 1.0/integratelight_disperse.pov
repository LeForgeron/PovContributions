/* integratelight_disperse.pov version 1.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demo of selected lamps prepared with IntegrateLight, viewed through a prism.
 *
 * Copyright 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       2016-Jul-09  Started.
 * 1.0   2016-Nov-14  Uploaded.
 */
// Pass 1:
//   +W640 +H480 +A +AM2 +R3 +FE +KI1 +KF36 +KFI38 +KFF73
// Pass 2:
//   +W640 +H480 -A
// Before running pass 2, make sure ALL of the #declare FName lines in
// SpectralComposer.pov are commented out.
//
// After running pass 2, you may delete the integratelight_disperse??.exr files.
#version 3.7;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%% CREATE THE SCENE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#if (clock_on)

  #ifndef (Annot) #declare Annot = no; #end
  #ifndef (Debug) #declare Debug = no; #end
  #ifndef (Lamp) #declare Lamp = 9; #end

  #include "screen.inc"
  #include "spectral.inc" // from SpectralRender
  #include "integratelight.inc"
  #include "espd_cie_standard.inc" // from Lightsys IV

  global_settings { assumed_gamma 1 }

  Set_Camera (<-1, 0, -100>, <0.9, 0, 0>, 1.8)

  #if (Debug) background { SpectralEmission (E_D65) * 0.2 } #end

  //================================= PRISM ====================================

  prism
  { -1, 1, 4, <2, 0>, <-1, -sqrt(3)>, <-1, sqrt(3)>, <2, 0>
    scale 1.2
    #if (Debug)
      // for debugging, a material that stands out from the
      // background, but still transmits across the spectrum:
      M_Spectral_Filter (D_Amethyst, IOR_Glass_BK7, 1)
    #else
      M_Spectral_Filter (Value_1, IOR_Glass_BK7, 100)
    #end
  }

  //================================= LIGHT ====================================

  #macro Set_light (Curve)
    #declare Emitter = ILight_Continuous (Curve, no, ILIGHT_GRAY, 1);
  #end

  // Identifiers starting with ES_ are from Lightsys IV include files.
  #switch (floor (Lamp))
    #case (0) Set_light (ILight_Blackbody (2856)) #break // Illuminant A
    #case (1) Set_light (ILight_Daylight (5003)) #break  // Illuminant D50
    #case (2) Set_light (ILight_Daylight (6504)) #break  // Illuminant D65
    #case (3) Set_light (ES_Illuminant_F2) #break  // standard fluorescent
    #case (4) Set_light (ES_Illuminant_F9) #break  // broadband fluorescent
    #case (5) Set_light (ES_Illuminant_F11) #break // narrowband fluorescent
    #case (6) Set_light (ES_GE_SW_Incandescent_60w) #break
    #case (7) Set_light (ES_Nikon_SB16_XenonFlash) #break
    #case (8)
      #declare CIE_IntegralStep = 1;
      Set_light (ES_Phillips_HPS)
      #break
    #case (9)
      #declare CIE_IntegralStep = 1;
      Set_light (ES_Phillips_PLS_11w)
      #break
    #case (10) Set_light (ES_Solux_Halog4700K) #break
    #case (11) Set_light (ES_Sunlight) #break
    #else Set_light (spline { linear_spline 380, 0, 730, 0 }) #break
  #end

  cylinder
  { -y, y, 0.2
    scale <1, 1.4, 1>
    pigment { aoi color_map { [0.5 rgb 0] [1.0 SpectralEmission (Emitter)] } }
    finish { ambient 0 diffuse 0 emission 1 }
    translate <-21.5, 0, 20>
  }

  //============================== ANNOTATIONS =================================

  #if (Annot)

    #declare NLAMPS = 12;
    #declare s_Lamps = array[NLAMPS]
    { "Illuminant A",
      "Illuminant D50",
      "Illuminant D65",
      "Illuminant F2",
      "Illuminant F9",
      "Illuminant F11",
      "GE soft white incandescent 60 W",
      "Nikon SB-16 xenon flash",
      "Philips high pressure sodium",
      "Philips PL-S 11 W CFL",
      "SoLux 4700K halogen",
      "Sunlight",
    }

    Screen_Object
    ( text
      { ttf "cyrvetic"
        #if (Lamp >= 0 & Lamp < NLAMPS)
          s_Lamps[Lamp]
        #else
          concat (str (Lamp, 0, -1), "???")
        #end
        0.001, 0
        T_Spectral_Emitting (E_D65, 0.8)
        scale 0.07
      },
      <0.5, 0.5>, 0, yes, 1
    )

  #end

//%%%%%%%%%%%%%%%%%%%%%%%%%%% ASSEMBLE THE FRAMES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#else

  // Make sure ALL of the #declare FName lines in SpectralComposer.pov
  // are commented out, or this next #declare will be overridden!
  #declare FName = "integratelight_disperse"
  #include "SpectralComposer.pov" // from SpectralRender

#end

// End of integratelight_disperse.pov
