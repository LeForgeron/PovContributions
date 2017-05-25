/* caption.inc version 1.0.1
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Imprints text or other form onto a box.
 *
 * Copyright 2013 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers   Date         Comments
 * ----   ----         --------
 *        2013-Mar-13  Created, based on code I wrote between 2004 and 2006.
 *        2013-Dec-23  A macro is added for general objects, not just text.
 * 1.0    2013-Dec-23  The module is adapted for the Object Collection.
 * 1.0.1  2015-May-31  Colors are accepted for the Emission argument.
 */
#ifndef (Caption_Inc_Temp) #declare Caption_Inc_Temp = version;
#debug "#include \"caption.inc\" //version 1.0.1\n"
#declare CAPTION_VERSION = 1.01;

//Determine whether to use emission or ambient:
#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("  #version ", str(version,0,1), ";\n")

#include "math.inc"

//----------------------------------------------------------------------

#macro Caption (s_Text, s_Font, v_Padding, c_Text, c_Background, Emission)
  Caption_Object
  ( text
    { ttf #if (strlen (s_Font) = 0) "cyrvetic.ttf" #else s_Font #end
      s_Text 1, 0
    },
    v_Padding, c_Text, c_Background, Emission
  )
#end

//----------------------------------------------------------------------

#macro Caption_Object (Object, v_Padding, c_Object, c_Background, Emission)
  box
  { (min_extent (Object) - v_Padding) * <1, 1, 0>,
    (max_extent (Object) + v_Padding) * <1, 1, 0> + z
    pigment
    { object
      { Object
        translate -0.5 * (max_extent (Object) + min_extent (Object)) * z
        scale <1, 1, 1 / (max_extent (Object).z - min_extent (Object).z)>
        color c_Background color c_Object
      }
    }
    #local caption_Emission = color Emission filter 0 transmit 0;
    finish
    { #if (version < 3.7)
        #if (VMax (caption_Emission) < 0)
          ambient 1 diffuse 0
        #else
          ambient caption_Emission
        #end
      #else
        #if (VMax (caption_Emission) < 0)
          ambient 0 diffuse 0 emission 1
        #else
          emission caption_Emission
        #end
      #end
    }
   // Do not optimize this next line!  A parse error would
   // result if the user passes in a scalar for v_Padding.
    scale v_Padding * z + <1, 1, 0>
  }
#end

//----------------------------------------------------------------------

#version Caption_Inc_Temp;
#end
// End of caption.inc
