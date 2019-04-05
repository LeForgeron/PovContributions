/* spectrum.inc 4.0.1
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Calibrated spectrum color maps and pigments.
 *
 * Copyright 2014 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Notes
 * -----  ----         -----
 * none   2008-Dec-22  Created.  (See User Manual, Unpublished Versions.)
 * none   2009-Aug-18  Young's images are sampled in detail.
 *        2012-Oct-06  New names are introduced to clarify roles of Young's
 *                     data.
 *        2012-Oct-06  Local identifiers are renamed to work around POV-Ray's
 *                     odd scope rules.
 *        2012-Oct-06  New macros use arbitrary data.
 *        2012-Oct-06  New macros use LightsysIV.
 * 2.0    2012-Oct-07  The version identifier is added.
 * 2.1    2012-Oct-07  A macro is added to normalize data.  Lightsys data are no
 *                     longer normalized (but color map and pigment still are.)
 *        2014-Jan-04  A specially gamut-mapped Lightsys pigment is added.
 * 3.0    2014-Jan-04  A yellow parameter is added to Young's "brightest"
 *                     macros.
 *        2014-Jan-08  To prepare for the transfer to the Object Collection,
 *                     legacy identifiers and Young's data are removed.
 *        2014-Jan-08  The wavelength unit for data is changed from microns to
 *                     nanometers.
 *        2014-Jan-08  The normalization macro is replaced.
 * 4.0    2014-Jan-10  The first Object Collection version is uploaded.
 * 4.0.1  2019-Apr-02  View_POV_Include_Stack is utilized.
 */
#ifndef (Spectrum_Inc_Temp) #declare Spectrum_Inc_Temp = version;
#version 3.5;
#declare SPECTRUM_VERSION = 4.01;
#ifdef (View_POV_Include_Stack)
  #debug "#include \"spectrum.inc\" //version 4.0.1\n"
#end

#if (!file_exists ("CIE.inc"))
  #warning "Lightsys IV is a prerequisite for the Spectrum module."
#end
#include "CIE.inc"

//sRGB wavelengths in nanometers
#declare SPECTRUM_BLUE = 464.3;
#declare SPECTRUM_CYAN = 491.5;
#declare SPECTRUM_GREEN = 549.1;
#declare SPECTRUM_YELLOW = 570.5;
#declare SPECTRUM_RED = 611.3;

//========================== MISCELLANEOUS UTILITY =============================

#macro Spectrum_Rule_p (Fine, c_Ink)
  pigment
  { gradient x color_map { [Fine color c_Ink] [Fine rgbt 1] }
    translate -Fine/2 * x
  }
#end

//================================= GENERAL ====================================

#macro Spectrum_Normalize (Data, Scale)
  #local spectrum_Max = 0;
  #local spectrum_I = 0;
  #while (spectrum_I < dimension_size (Data, 1))
    #local spectrum_Ch = 1;
    #while (spectrum_Ch <= 3)
      #if (Data [spectrum_I][spectrum_Ch] > spectrum_Max)
        #local spectrum_Max = Data [spectrum_I][spectrum_Ch];
      #end
      #local spectrum_Ch = spectrum_Ch + 1;
    #end
    #local spectrum_I = spectrum_I + 1;
  #end
  #local spectrum_I = 0;
  #while (spectrum_I < dimension_size (Data, 1))
    #local spectrum_Ch = 1;
    #while (spectrum_Ch <= 3)
      #local Data [spectrum_I][spectrum_Ch] =
        Data [spectrum_I][spectrum_Ch] / spectrum_Max * Scale;
      #local spectrum_Ch = spectrum_Ch + 1;
    #end
    #local spectrum_I = spectrum_I + 1;
  #end
#end

#macro Spectrum_Make_cm (Data)
  color_map
  { #local spectrum_I = 0;
    #while (spectrum_I < dimension_size (Data, 1))
      [ Data [spectrum_I][0] / 1000
        rgb <Data [spectrum_I][1], Data [spectrum_I][2], Data [spectrum_I][3]>
      ]
      #local spectrum_I = spectrum_I + 1;
    #end
  }
#end

#macro Spectrum_Make_p (Data)
  pigment { gradient x Spectrum_Make_cm (Data) }
#end

//=============================== LIGHTSYS IV ==================================

#macro Spectrum_Lightsys_data()
  #local SPECTRUM_SHORTEST = 378;
  #local SPECTRUM_LONGEST = 826;
  #local SPECTRUM_STEP = 2;
  #local spectrum_Data = array
    [(SPECTRUM_LONGEST - SPECTRUM_SHORTEST) / SPECTRUM_STEP + 1] [4]

  #local spectrum_I = 0;
  #local spectrum_W = SPECTRUM_SHORTEST;
  #while (spectrum_W <= SPECTRUM_LONGEST)
    #local spectrum_c_Value = MapGamut (Wavelength2RGB (spectrum_W));
    #local spectrum_Data [spectrum_I][0] = spectrum_W;
    #local spectrum_Data [spectrum_I][1] = spectrum_c_Value.red;
    #local spectrum_Data [spectrum_I][2] = spectrum_c_Value.green;
    #local spectrum_Data [spectrum_I][3] = spectrum_c_Value.blue;
    #local spectrum_I = spectrum_I + 1;
    #local spectrum_W = spectrum_W + SPECTRUM_STEP;
  #end

  spectrum_Data
#end

#macro Spectrum_Lightsys_cm()
  #local spectrum_Data = Spectrum_Lightsys_data()
  Spectrum_Normalize (spectrum_Data, 1)
  Spectrum_Make_cm (spectrum_Data)
#end

#macro Spectrum_Lightsys_p()
  pigment { gradient x Spectrum_Lightsys_cm() }
#end

#macro Spectrum_Special_p()
  #local spectrum_Gm = GamutMapFunction; //@@[1] (Undocumented! See user manual.)
  CIE_GamutMapping (2)
  #local spectrum_P2 = Spectrum_Lightsys_p()
  CIE_GamutMapping (3)
  #local spectrum_P3 = Spectrum_Lightsys_p()
  pigment { average pigment_map { [1 spectrum_P2] [1 spectrum_P3] } }
  CIE_GamutMapping (spectrum_Gm) //@@[1] (See user manual.)
#end

#version Spectrum_Inc_Temp;
#end
// end of spectrum.inc
