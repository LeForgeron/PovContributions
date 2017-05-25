/* caption.inc version 1.1
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Imprints text or other form onto a box.
 *
 * Copyright 2013 - 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers   Date         Comments
 * ----   ----         --------
 *        2013-Mar-13  Created, based on code I wrote between 2004 and 2006.
 *        2013-Dec-23  A macro is added for general objects, not just text.
 * 1.0    2013-Dec-23  The module is adapted for the Object Collection.
 * 1.0.1  2015-May-31  Colors are accepted for the Emission argument.
 *        2016-Apr-09  Code for padding and texture is separated into their own
 *                     macros, in preparation for future changes.
 *        2016-Apr-11  Top padding may differ from bottom padding.
 *        2016-Apr-15  The Emission formal parameter is changed to c_Emission.
 * 1.1    2016-Apr-29  Macros are added to apply the padding around the font
 *                     metrics rather than the text or object itself.
 * 1.1    2016-Apr-30  Uploaded.
 */
#ifndef (Caption_Inc_Temp) #declare Caption_Inc_Temp = version;
#debug "#include \"caption.inc\" //version 1.1\n"
#declare CAPTION_VERSION = 1.1;

//Determine whether to use emission or ambient:
#if (version < 3.7) #version 3.5; #else #version 3.7; #end
#debug concat ("  #version ", str(version,0,1), ";\n")

#include "math.inc"

#ifndef (Caption_s_Font_exemplar) #declare Caption_s_Font_exemplar = "Xp" #end

//============================== PRIVATE MACRO =================================

// Convert input to a 4-D vector.  If the input is a 2-D or 3-D vector, then
// use the .y component for .t.
#macro Caption__Get_padding (v_Padding)
  #local caption_Promoted = <0, 0, 0, 0> + v_Padding;

 // See whether .t exists:
  #local caption_Test1 = v_Padding + 1;
  #local caption_Test2 = v_Padding + 2;

  < caption_Promoted.x,
    caption_Promoted.y,
    caption_Promoted.z,
   // Test whether .t exists:
    ( (<0, 0, 0, 0> + caption_Test1).t = (<0, 0, 0, 0> + caption_Test2).t?
      caption_Promoted.y: caption_Promoted.t
    )
    // N.B.  Although a scalar tests incorrectly as having a .t component, it
    // doesn't matter, because the returned 4-D vector is the same either way.
  >
#end

//============================== PUBLIC MACROS =================================

#macro Caption_Texture (Object, c_Object, c_Background, c_Emission)
  texture
  { pigment
    { object
      { Object
        translate -0.5 * (max_extent (Object) + min_extent (Object)) * z
        scale <1, 1, 1 / (max_extent (Object).z - min_extent (Object).z)>
        color c_Background color c_Object
      }
    }
    #local caption_Emission = color c_Emission filter 0 transmit 0;
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
  }
#end

//----------------------------------------------------------

#macro Caption (s_Text, s_Font, v_Padding, c_Text, c_Background, c_Emission)
  Caption_Object
  ( text
    { ttf #if (strlen (s_Font) = 0) "cyrvetic.ttf" #else s_Font #end
      s_Text 1, 0
    },
    v_Padding, c_Text, c_Background, c_Emission
  )
#end

//----------------------------------------------------------

#macro Caption_Object (Object, v_Padding, c_Object, c_Background, c_Emission)
  #local caption_Padding = Caption__Get_padding (v_Padding);
  box
  { (min_extent (Object) - <caption_Padding.x, caption_Padding.y, 0>)
      * <1, 1, 0>,
    (max_extent (Object) + <caption_Padding.x, caption_Padding.t, 0>)
      * <1, 1, 0> + z
    Caption_Texture (Object, c_Object, c_Background, c_Emission)
    scale <1, 1, caption_Padding.z>
  }
#end

//----------------------------------------------------------

#macro Caption_Uniform
( s_Text, s_Font, v_Padding, c_Text, c_Background, c_Emission
)
  Caption_Object_by_font
  ( text
    { ttf #if (strlen (s_Font) = 0) "cyrvetic.ttf" #else s_Font #end
      s_Text 1, 0
    },
    s_Font, v_Padding, c_Text, c_Background, c_Emission
  )
#end

//----------------------------------------------------------

#macro Caption_Object_by_font
( Object, s_Font, v_Padding, c_Object, c_Background, c_Emission
)
  #local caption_Padding = Caption__Get_padding (v_Padding);

 // Determine the bounds:
  #if (strlen (Caption_s_Font_exemplar) > 0)
    #local caption_Std = text
    { ttf #if (strlen (s_Font) = 0) "cyrvetic.ttf" #else s_Font #end
      Caption_s_Font_exemplar 1, 0
    }
    #local caption_Max = max_extent (caption_Std).y;
    #local caption_Min = min_extent (caption_Std).y;
  #else // To date, a null string text object is not
        // efficiently bounded, so we need to fake it:
    #local caption_Max = 0;
    #local caption_Min = 0;
  #end

  box
  { < min_extent (Object).x - caption_Padding.x,
      caption_Min - caption_Padding.y,
      0
    >,
    < max_extent (Object).x + caption_Padding.x,
      caption_Max + caption_Padding.t,
      1
    >
    Caption_Texture (Object, c_Object, c_Background, c_Emission)
    scale <1, 1, caption_Padding.z>
  }
#end

//----------------------------------------------------------

#version Caption_Inc_Temp;
#end
// End of caption.inc
