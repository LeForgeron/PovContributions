/* caption_uniform.pov version 1.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A comparison of macros Caption() and Caption_Uniform() in caption.inc.
 *
 * Copyright 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers   Date         Comments
 * ----   ----         --------
 *        2016-Apr-12  Created.
 * 1.1    2016-Apr-30  Uploaded.
 */
#version 3.5;

#include "shapes.inc"
#include "caption.inc"

global_settings { assumed_gamma 1 }

background { rgb <0.50, 0.66, 1.00> }

camera
{ orthographic
  location -z
  right 8.8 * x
  up 6.6 * y
}

union
{ Caption ("Get", "", 0.1, red 1, rgb 1, -1)
  object { Caption ("yours", "", 0.1, red 1, rgb 1, -1) translate 2.08 * x }
  object { Caption ("today!", "", 0.1, red 1, rgb 1, -1) translate 5.0 * x }
  text
  { ttf "crystal" "Caption()" 1, <-0.05, 0>
    pigment { rgb 0 }
    scale 0.6
    translate <0, 1, 0>
  }
  translate <-3.8, 1.65, 0>
}

union
{ Center_Object
  ( Caption ("Get", "", 0.1, red 1, rgb 1, -1),
    y
  )
  Center_Object
  ( object { Caption ("yours", "", 0.1, red 1, rgb 1, -1) translate 2.08 * x },
    y
  )
  Center_Object
  ( object { Caption ("today!", "", 0.1, red 1, rgb 1, -1) translate 5.0 * x },
    y
  )
  text
  { ttf "crystal" "Caption()" 1, <-0.05, 0>
    pigment { rgb 0 }
    scale 0.6
    translate <0, 0.7, 0>
  }
  text
  { ttf "cyrvetic" "(vertically centered)" 1, 0
    pigment { rgb 0 }
    scale 0.55
    translate <2.7, 0.7, 0>
  }
  translate <-3.8, -0.25, 0>
}

union
{ Caption_Uniform ("Get", "", 0.1, red 1, rgb 1, -1)
  object
  { Caption_Uniform ("yours", "", 0.1, red 1, rgb 1, -1) translate 2.08 * x
  }
  object
  { Caption_Uniform ("today!", "", 0.1, red 1, rgb 1, -1) translate 5.0 * x
  }
  text
  { ttf "crystal" "Caption_Uniform()" 1, <-0.05, 0>
    pigment { rgb 0 }
    scale 0.6
    translate <0, 1, 0>
  }
  translate <-3.8, -2.75, 0>
}

// End of caption_uniform.pov
