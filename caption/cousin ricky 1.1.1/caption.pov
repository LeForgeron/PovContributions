/* caption.pov version 1.1.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A demonstration of caption.inc.
 *
 * Copyright 2013 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers   Date         Comments
 * ----   ----         --------
 * 1.0    2013-Dec-23  Created.
 * 1.0.1  2015-May-31  Some text is modified.
 *        2016-Apr-08  The tile colors are modified.
 *        2016-Apr-16  The chrome texture is tweaked.
 *        2016-Apr-22  The sky is remodeled.
 * 1.1    2016-Apr-29  Some annotations demonstrate differing top and bottom
 *                     padding.
 * 1.1    2016-Apr-30  Uploaded.
 *        2019-Mar-27  The sky and lighting are changed.
 * 1.1.1  2019-Mar-30  The prefix on the Sun's location identifier is changed
 *                     from "v_" (vector) to "lv_" (location vector).
 */
// +A +AM1 +J +R5
//v3.8 setting:
// +A +AM3 +R4 +AC0.999
//UberPOV settings:
// +A +AM3 +R4 +AC0.999999
// +A +AM3 +R4 +AC1.0
//(The latter setting is smooth, but very slow.)
#version 3.5;

#include "screen.inc"
#include "transforms.inc"
#include "caption.inc"

#declare Pretrace = 1 / image_width;
global_settings
{ assumed_gamma 1
  radiosity
  { count 200
    error_bound 0.5
    pretrace_start 32 * Pretrace
    pretrace_end 2 * Pretrace
    recursion_limit 2
  }
  max_trace_level 6
}

Set_Camera (<-0.2, 1.5, -7.2>, <0, 1, 0>, 30)

#declare lv_Sun = vrotate (-z, <45, 45, 0>) * 1000000;
light_source
{ lv_Sun, rgb <1.557, 1.483, 1.434>
  parallel point_at 0
}

sky_sphere
{ pigment
  { function // visual inspection (no theory)
    { min (pow ((1 - y) / 0.95, 4.0), 1)
    }
    color_map { [0 rgb <0.021, 0.067, 0.206>] [1 rgb <0.287, 0.425, 0.522>] }
  }
  pigment
  { function // curve fit to an image that utilized Scott Boham's SkySim
    { select (z, 0, 1 - pow (1 - z*z, 0.23 + 5 * pow (z - 0.64, 4)))
    }
    color_map
    { [0 rgbt <0.305, 0.446, 0.726, 1>]
      [1 rgb <0.305, 0.446, 0.726>]
    }
    Reorient_Trans (z, lv_Sun)
  }
}

#default { finish { ambient 0 diffuse 0.7 } }

plane
{ y, 0
  pigment { checker rgb <0.2, 0.0, 0.0> rgb <1.0, 1.0, 0.8> scale 0.5 }
}

sphere
{ y, 1
  pigment { rgb <0.500, 0.508, 0.545> }
  finish
  { reflection { 1 metallic }
    diffuse 0
    ambient 0
    specular 2500 metallic
    roughness 0.00005
  }
}

Screen_Object
( object
  { Caption
    ( "Caption", "timrom", <0.2, 0.1, 0.001, 0.15>,
      blue 0.3, rgb 1 transmit 0.6, -1
    )
    scale 0.12
  },
  <0, 1>, <0.02, 0.02>, yes, 1
)
Screen_Object
( object
  { Caption ("Get yours today!", "", <0.3, 0.2, 0.001, 0.25>, red 1, rgb 1, -1)
    scale 0.06
  },
  <1, 0.941>, <0.02, 0.02>, yes, 1
)
Screen_Object
( object
  { Caption_Object
    ( union
      { text { ttf "timrom" "POV-Ray" 1, 0 }
        text { ttf "povlogo" "P" 1, 0 translate <4.2, -0.2, 0> }
        text { ttf "timrom" "Object Collection" 1, 0 translate 5.3 * x }
      }
      <0.2, 0.1, 0.001>, rgb 0, rgb 1 transmit 0.6, -1
    )
    scale 0.08
  },
  <0.5, 0>, <0, 0.04>, yes, 1
)
// End of caption.pov
