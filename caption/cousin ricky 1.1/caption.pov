/* caption.pov version 1.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A demonstration of caption.inc.
 *
 * Copyright 2013 - 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
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
 */
// +A +AM1 +J +R5
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
}

Set_Camera (<-0.2, 1.5, -7.2>, <0, 1, 0>, 30)

#declare v_Sun = vrotate (-z, <45, 45, 0>) * 1000000;
light_source
{ v_Sun, rgb <1.221, 0.950, 0.683>
  parallel point_at 0
}

#declare p_Skygrad = pigment
{ gradient y color_map
  { [0.0 rgb <0.526, 0.860, 1.053>]
    [0.1 rgb <0.404, 0.673, 0.890>]
    [0.2 rgb <0.306, 0.523, 0.760>]
    [0.3 rgb <0.230, 0.406, 0.658>]
    [0.4 rgb <0.173, 0.319, 0.582>]
    [0.5 rgb <0.132, 0.256, 0.527>]
    [0.6 rgb <0.104, 0.214, 0.491>]
    [0.7 rgb <0.088, 0.188, 0.469>]
    [0.8 rgb <0.079, 0.175, 0.457>]
    [0.9 rgb <0.076, 0.170, 0.453>]
    [1.0 rgb <0.075, 0.170, 0.452>]
  }
}

#declare c_Halo = rgb <1.395, 1.511, 1.719>;
#declare p_Halo = pigment
{ object
  { plane { z, 0 }
    pigment
    { wood ramp_wave color_map
      { [0.00 c_Halo]
        [0.05 c_Halo transmit 0.211]
        [0.10 c_Halo transmit 0.378]
        [0.15 c_Halo transmit 0.512]
        [0.20 c_Halo transmit 0.620]
        [0.25 c_Halo transmit 0.706]
        [0.30 c_Halo transmit 0.775]
        [0.40 c_Halo transmit 0.876]
        [0.50 c_Halo transmit 0.940]
        [0.60 c_Halo transmit 0.981]
        [0.70 c_Halo transmit 1]
      }
    }
    pigment { rgbt 1 }
  }
  Reorient_Trans (z, v_Sun)
}

sky_sphere
{ pigment { p_Skygrad }
  pigment { p_Halo }
}

#default { finish { ambient 0 diffuse 0.75 } }

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
