/* integratelight.inc version 1.0
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Converts spectral curve splines into a data structure suitable for
 * Lilysoft's SpectralRender package, using numeric integration.
 *
 * Copyright 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       2013-Dec-11  Begun.
 * 1.0   2016-Nov-14  Uploaded.
 */
/* This file references the following identifiers that are defined by Lightsys
 * IV or by SpectralRender:
 *   CIE_IntegralStep
 *   CMF_xyz
 *   DaylightM1M2
 *   DS012
 *   MapGamut
 *   PlanckBlackBody
 *   ReflectiveSpectrum
 *   SpectralMode
 *   xyz2RGB
 *   xyz2xyY
 */
#ifndef (IntegrateLight_Inc_Temp) #declare IntegrateLight_Inc_Temp = version;
#version 3.7;
#debug "#include \"integratelight.inc\" //version 1.0\n"
#declare INTEGRATELIGHT_VERSION = 1.0;

// Explain the situation to the user before letting the scene crash:
#if (!file_exists ("CIE.inc"))
  #warning "Lightsys 4 (Lightsys IV) is a prerequisite for the IntegrateLight module."
#end
#include "CIE.inc"

// Do not #include spectral.inc here, because it currently has no mechanism to
// prevent multiple #includes.
#ifndef (SpectralMode)
  #error "SpectralRender file spectral.inc must be #included before #including integratelight.inc."
#end

//=========================== NORMALIZATION CODES ==============================

#declare ILIGHT_NONE = 0;
#declare ILIGHT_MAX = 1;
#declare ILIGHT_MEAN = 2;
#declare ILIGHT_GRAY = 3;
#declare ILIGHT_GREY = ILIGHT_GRAY;
#declare ILIGHT_XYY = 4;
#declare ILIGHT_XYZ = 5;

//=========================== SPECTRAL MODE MACROS =============================

#if (SpectralMode)

  #macro ILight_Continuous (Curve, Simpson, Normalization, Level)
    #local ilight_Spectrum = ILight__Integrate (Curve, Simpson);
    ILight__Normalize
    ( "ILight_Continuous", ilight_Spectrum, Curve, Normalization, Level
    )
    ilight_Spectrum
  #end

  //--------------------------------------

  #macro ILight_Reflective (Curve, Simpson, Level)
    #local ilight_Spectrum = ILight__Integrate (Curve, Simpson);
    #for (ilight_Wx, 0, 35)
      #local ilight_Spectrum [ilight_Wx] = ilight_Spectrum [ilight_Wx] * Level;
      #if (ilight_Spectrum [ilight_Wx] > 1)
        #warning concat
        ( "ILight_Reflective(): Surface reflects more light than it receives ",
          "at ", str (ILight__fn_Wavelength (ilight_Wx, 10), 0, 0), " nm (",
          str (ilight_Spectrum [ilight_Wx], 0, -1), ")."
        )
      #end
    #end
    ilight_Spectrum
  #end

//=========================== PREVIEW MODE MACROS ==============================
#else

  #macro ILight_Continuous (Curve, Simpson, Normalization, Level)
    #local ilight_Spectrum = ILight__Integrate (Curve, Simpson);
    ILight__Normalize
    ( "ILight_Continuous", ilight_Spectrum, Curve, Normalization, Level
    )
    MapGamut (xyz2RGB (ILight__To_xyz (ilight_Spectrum)))
  #end

  //--------------------------------------

  #macro ILight_Reflective (Curve, Simpson, Level)
    (ReflectiveSpectrum (Curve) * Level)
  #end

#end

//=========================== OTHER PUBLIC MACROS ==============================

#macro ILight_Blackbody (TempK) // cf. CIE.inc::Blackbody2xyz()
  spline
  { natural_spline
    #for (ilight_W, 375, 735, 5)
      ilight_W, PlanckBlackBody (ilight_W*1e-9, TempK)
    #end
  }
#end

//--------------------------------------

#macro ILight_Daylight (TempK) // cf. CIE.inc::Daylight2xyz()
  #local ilight_M1 = 0;
  #local ilight_M2 = 0;
  DaylightM1M2 (TempK, ilight_M1, ilight_M2)
  spline
  { linear_spline
    #for (ilight_I, 0, 71)
      ILight__fn_Wavelength (ilight_I, 5),
      DS012[ilight_I][0]
        + ilight_M1 * DS012[ilight_I][1]
        + ilight_M2 * DS012[ilight_I][2]
    #end
  }
#end

//======================= AUXILIARY (PRIVATE) ELEMENTS =========================
// These elements are not intended to be called directly by the user.

#ifndef (ilight__Debug) #declare ilight__Debug = 0; #end
#declare ilight__s_Norms = array[6]
{ "none", "max", "mean", "gray", "xyY", "xyz",
}

//--------------------------------------
// Returns a wavelength.
//   x - an index
//   y - a step size
#declare ILight__fn_Wavelength = function (x, y) { 380 + x * y }

//--------------------------------------
// The integration workhorse.
//   Curve   - the spectral spline
//   Simpson - whether or not to use Simpson's rule
// Returns: an array suitable for SpectralRender
#macro ILight__Integrate (Curve, Simpson)
  #if (CIE_IntegralStep <= 0)
    #error concat
    ( "CIE_IntegralStep is ", str (CIE_IntegralStep, 0, -1),
      "; it must be positive."
    )
  #end
  #local ilight_Spectrum = array[36]
 // Technical note: to avoid glitches that may arise with a non-integer step
 // size, all loop counting is done with integer values.
  #if (Simpson) //Use Simpson's rule
    #local ilight_nSteps = ceil (5 / CIE_IntegralStep);
    #local ilight_Step = 5 / ilight_nSteps;
    #for (ilight_Wx, 0, 35)
      #local ilight_W = ILight__fn_Wavelength (ilight_Wx, 10);
      #local ilight_Acc = 0;
      #for (ilight_Ix, 1, ilight_nSteps)
        #local ilight_X = ilight_W - 5 + ilight_Ix * ilight_Step * 2;
        #local ilight_Acc = ilight_Acc
        + (   Curve (ilight_X - ilight_Step * 2).y
            + Curve (ilight_X - ilight_Step).y * 4
            + Curve (ilight_X).y
          ) / 3;
      #end
      #local ilight_Spectrum [ilight_Wx] = ilight_Acc / (ilight_nSteps * 2);
    #end
  #else //Use trapezoidal rule
    #local ilight_nSteps = ceil (10 / CIE_IntegralStep);
    #local ilight_Step = 10 / ilight_nSteps;
    #for (ilight_Wx, 0, 35)
      #local ilight_W = ILight__fn_Wavelength (ilight_Wx, 10);
      #local ilight_Acc = (Curve (ilight_W - 5).y + Curve (ilight_W + 5).y) / 2;
      #for (ilight_X, 1, ilight_nSteps-1)
        #local ilight_Acc =
          ilight_Acc + Curve (ilight_W - 5 + ilight_X * ilight_Step).y;
      #end
      #local ilight_Spectrum [ilight_Wx] = ilight_Acc / ilight_nSteps;
    #end
  #end
  #if (ilight__Debug)
    #debug concat
    ( "ILight__Integrate (, ", #if (Simpson) "yes" #else "no" #end,
      "): nSteps = ", str (ilight_nSteps, 0, 0),
      ", Step = ", str (ilight_Step, 0, -1), "\n"
    )
  #end
  ilight_Spectrum
#end

//--------------------------------------
// Converts a SpectralRender emission spectrum array to xyz.
//   Array - the spectrum array
// Returns: xyz as a 3-D vector
#macro ILight__To_xyz (Array) // cf. CIE.inc::Emissive2xyz()
  #local ilight_Acc = <0, 0, 0>;
  #for (ilight_Wx, 0, 35)
    #local ilight_Acc = ilight_Acc
      + CMF_xyz (ILight__fn_Wavelength (ilight_Wx, 10)) * Array [ilight_Wx];
  #end
 // 10 is the band resolution in nm; / 100 is for unit conversion:
  #local Ilight_xyz = ilight_Acc * 10 / 100;
  #if (ilight__Debug)
    #debug concat
    ( "ILight__To_xyz(): <", vstr (3, Ilight_xyz, ", ", 0, -1), ">\n"
    )
  #end
  Ilight_xyz
#end

//--------------------------------------
// Normalizes a SpectralRender emission spectrum array.
//  This          - the name of the calling macro
//  Output        - the array, altered in place
//  Spline        - the spectral curve (for normalization on wavelength)
//  Normalization - the normalization type
//  Level         - a post-normalization scale factor
#macro ILight__Normalize (This, Output, Spline, Normalization, Level)

 // Determine normalization:
  #switch (Normalization)

    #case (ILIGHT_MAX)
      #local ilight_Divisor = 0;
      #for (ilight_Wx, 0, 35)
        #if (ilight_Divisor < Output [ilight_Wx])
          #local ilight_Divisor = Output [ilight_Wx];
        #end
      #end
      #break

    #case (ILIGHT_MEAN)
      #local ilight_Acc = 0;
      #for (ilight_Wx, 0, 35)
        #local ilight_Acc = ilight_Acc + Output [ilight_Wx];
      #end
      #local ilight_Divisor = ilight_Acc / 36;
      #break

    #case (ILIGHT_GRAY)
      #local iLight_xyz = ILight__To_xyz (Output);
      #local ilight_Divisor = MapGamut (xyz2RGB (iLight_xyz)).gray;
      #break

    #case (ILIGHT_XYZ)
      #local iLight_xyz = ILight__To_xyz (Output);
      #local ilight_Divisor = iLight_xyz.x + iLight_xyz.y + iLight_xyz.z;
      #break

    #case (ILIGHT_XYY)
      #local iLight_xyz = ILight__To_xyz (Output);
      #local ilight_Divisor = xyz2xyY (iLight_xyz).z;
      #break

    #else
      #if (Normalization >= 300)
        #local ilight_Divisor = Spline (Normalization).y;
      #else
        #local ilight_Divisor = 1; // no normalization
      #end

  #end

 // Debug:
  #if (ilight__Debug)
    #ifndef (iLight_xyz)
      #local iLight_xyz = ILight__To_xyz (Output);
    #end
    #debug concat
    ( "ILight__Normalize (,,, ",
      #if (Normalization != floor (Normalization))
        str (Normalization, 0, -1),
      #elseif
      ( Normalization < 0 | Normalization >= dimension_size (ilight__s_Norms, 1)
      )
        str (Normalization, 0, 0),
      #else
        ilight__s_Norms [Normalization],
      #end
      ",): Divisor = ", str (ilight_Divisor, 0, -1), "\n"
    )
  #end

 // Normalize:
  #if (ilight_Divisor = 0)
    #warning concat
    ( This, "(): Division by zero; the spectrum will not be normalized."
    )
  #else
    #for (ilight_Wx, 0, 35)
      #local Output [ilight_Wx] = Output [ilight_Wx] / ilight_Divisor;
    #end
  #end

 // Adjust level:
  #for (ilight_Wx, 0, 35)
    #local Output [ilight_Wx] = Output [ilight_Wx] * Level;
  #end
#end

//--------------------------------------

#version IntegrateLight_Inc_Temp;
#end
// End of integratelight.inc
