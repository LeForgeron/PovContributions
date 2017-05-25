/* integratelight_scene.pov version 1.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A demo scene for IntegrateLight: four colored matte spheres on a checkered
 * floor are illuminated by a lamp.  The user may select from a variety of
 * lamps.
 *
 * Copyright 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       2014-May-22  Created.
 * 1.0   2016-Nov-14  Uploaded.
 */
// Preview:
//   +W640 +H480 +A Declare=Preview=1
// Pass 1:
//   +W640 +H480 +A +AM1 +R5 +FE +KI1 +KF36 +KFI38 +KFF73
// Pass 2:
//   +W640 +H480 -A
// Before running pass 2, make sure ALL of the #declare FName lines in
// SpectralComposer.pov are commented out.
//
// After running pass 2, you may delete the integratelight_scene??.exr files.
#version 3.7;

#ifndef (Preview) #declare Preview = no; #end

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%% CREATE THE SCENE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#if (clock_on | Preview)

  #include "screen.inc"
  #include "spectral.inc" // from SpectralRender
  #include "integratelight.inc"
  #include "espd_cie_standard.inc" // from Lightsys IV
  #include "rspd_pantone_matte.inc" // from Lightsys IV

  #ifndef (Debug) #declare Debug = no; #end
  #ifndef (Lamp) #declare Lamp = 9; #end
  #ifndef (Norm) #declare Norm = ILIGHT_GRAY; #end
  #ifndef (Rad) #declare Rad = yes; #end

  Set_Camera (<0.4328, 6.5971, -9.0345>, <0.0024, 1.2886, -0.0504>, 29.5029)

  //================================ LIGHTING ==================================

  #declare Pretrace = 1 / image_width;
  global_settings
  { assumed_gamma 1
    #if (Rad)
      radiosity
      { count 200
        error_bound 0.5
        pretrace_end 2 * Pretrace
        pretrace_start 64 * Pretrace
        recursion_limit 2
      }
    #end
  }

  #macro Set_light (Curve)
    #declare Emitter = ILight_Continuous (Curve, no, Norm, 1);
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
    #else #declare Emitter = E_D65;
  #end
  #declare CIE_IntegralStep = 5;

  light_source
  { <-5.625, 12.625, -9.743>,
    SpectralEmission (Emitter) * 11664
    fade_power 2 fade_distance 0.10417
    spotlight point_at <0, 1.3750, 0> radius 45 falloff 90
  }

  #default
  { finish
    { diffuse 1
      ambient SpectralEmission (Emitter) * <0.24439, 0.24932, 0.24558>
    }
  }

  //=============================== DEBUGGING ==================================
  // N.B. The normalization feature of IntegrateLight required more debugging
  // than you know.

  #if (Debug)

    #if (Preview)
      #debug concat ("Emitter = rgb <", vstr (3, Emitter, ", ", 0, 4), ">\n")
    #elseif (frame_number = 73)
      #local xyzAcc = <0, 0, 0>;
      #for (I, 0, 35)
        #local Wl = 380 + I * 10;
        #debug concat (str (Wl, 3, 0), ": ", str (Emitter[I], 7, 5), "\n")
        #local xyzAcc = xyzAcc + CMF_xyz (Wl) * Emitter[I];
      #end
      #declare Rgb = xyz2RGB (xyzAcc * 10 / 100);
      #debug concat
      ( "Emitter (converted) = rgb <", vstr (3, Rgb, ", ", 0, 4), ">\n"
      )
    #end

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
    #declare s_Norms = array[6]
    { "ILIGHT_NONE", "ILIGHT_MAX", "ILIGHT_MEAN",
      "ILIGHT_GRAY", "ILIGHT_XYY", "ILIGHT_XYZ",
    }

    #macro Annotate (S)
      text
      { ttf "cyrvetic" S 0.001, 0
        pigment { rgb 0 }
        scale 0.07
      }
    #end

    Screen_Object
    ( Annotate
      ( #if (Lamp >= 0 & Lamp < NLAMPS)
          s_Lamps[Lamp]
        #else
          concat (str (Lamp, 0, -1), "???")
        #end
      ),
      <0.5, 0.65>, 0, yes, 1
    )
    Screen_Object
    ( Annotate
      ( #if (Norm = floor (Norm) & Norm >= 0 & Norm <=5)
          s_Norms[Norm]
        #else
          str (Norm, 0, -1)
        #end
      ),
      <0.49, 0.4>, 0, yes, 1
    )
    Screen_Object
    ( Annotate (#if (Rad) "radiosity" #else "ambient" #end),
      <0.49, 0.3>, 0, yes, 1
    )
    #if (Preview)
      Screen_Object (Annotate ("preview"), <0.49, 0.2>, 0, yes, 1)
    #end

  #end

  //=========================== REFLECTIVE OBJECTS =============================

  box
  { -1, 1 scale <12, 14, 12> hollow
    pigment { C_Spectral (D_CC_B4) }
  }

  plane
  { y, 0
    pigment { checker C_Spectral (D_CC_F4) C_Spectral (D_CC_B4) }
  }

  #declare MyCyan = ILight_Reflective (RS_Hexachrome_Cyan_M, no, 1);
  #declare MyMagenta = ILight_Reflective (RS_Hexachrome_Magenta_M, no, 1);
  #declare MyYellow = ILight_Reflective (RS_Hexachrome_Yellow_M, no, 1);
  #declare MyGreen = ILight_Reflective (RS_Hexachrome_Green_M, no, 1);
  #declare MyOrange = ILight_Reflective (RS_Hexachrome_Orange_M, no, 1);
  #declare MyBlack = ILight_Reflective (RS_Hexachrome_Black_M, no, 1);

  #declare MyRed = D_Average (MyMagenta, 1, MyOrange, 1);
  #declare MyBlue = D_Average (MyMagenta, 1, MyCyan, 4);

  #declare Ball = sphere { <0, 1, 1.75>, 1 }
  union
  { object
    { Ball
      pigment { C_Average (MyRed, 1, MyBlack, 1) }
      rotate -90 * y
    }
    object { Ball pigment { C_Spectral (MyYellow) } }
    object { Ball pigment { C_Spectral (MyGreen) } rotate 90 * y }
    object
    { Ball
      pigment { C_Average (MyBlue, 1, MyBlack, 1) }
      rotate 180 * y
    }
    translate <0, 0, 0.75>
  }

//%%%%%%%%%%%%%%%%%%%%%%%%%%% ASSEMBLE THE FRAMES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#else

  // Make sure ALL of the #declare FName lines in SpectralComposer.pov
  // are commented out, or this next #declare will be overridden!
  #declare FName = "integratelight_scene"
  #include "SpectralComposer.pov" // from SpectralRender

#end

// End of integratelight_scene.pov
