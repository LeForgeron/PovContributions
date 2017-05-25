/* caption.inc version 1.0
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Text on a box.
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       13-mar-2013  Created, based on code I wrote between 2004 and 2006.
 * 1.0   23-dec-2013  Adapted for the Object Collection and uploaded.
 */
#ifndef (Caption_Inc_Temp) #declare Caption_Inc_Temp = version;
#debug "#include \"caption.inc\" //version 1.0\n"
#declare CAPTION_VERSION = 1.0;

//Determine whether to use emission or ambient:
#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("  #version ", str(version,0,1), ";\n")

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
    finish
    { #if (version < 3.7)
        #if (Emission < 0)
          ambient 1 diffuse 0
        #else
          ambient Emission
        #end
      #else
        #if (Emission < 0)
          ambient 0 diffuse 0 emission 1
        #else
          emission Emission
        #end
      #end
    }
    scale v_Padding * z + <1, 1, 0>
  }
#end

//----------------------------------------------------------------------

#version Caption_Inc_Temp;
#end
