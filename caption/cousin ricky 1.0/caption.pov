/* caption.pov version 1.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * 1.0   23-dec-2013  Created.
 */
// +a +am1 +j +r5
//UberPOV settings:
// +a +am3 +r4 +ac0.999999
// +a +am3 +r4 +ac1.0 (very slow)
#version 3.5;

#include "screen.inc"
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

light_source
{ vrotate (-z, <45, 45, 0>) * 1000000, rgb <1.287  1.006, 0.630>
  parallel point_at 0
}

#declare C_SKY = rgb <0.421, 0.631, 1.263>;
sky_sphere
{ pigment
  { gradient y color_map
    { [0.0 C_SKY]
      [0.2 C_SKY * 0.6]
      [0.7 C_SKY * 0.3]
      [1.0 C_SKY * 0.2]
    }
  }
}

#default { finish { ambient 0 diffuse 0.75 } }

plane
{ y, 0
  pigment { checker rgb <0.34, 0.04, 0.07> rgb <1.0, 1.0, 0.5> scale 0.5 }
}

sphere
{ y, 1
  pigment { rgb <0.61, 0.61, 0.64> }
  finish
  { reflection { 1 metallic }
    diffuse 0
    ambient 0
    specular 1144 metallic
    roughness 0.0001
  }
}

#if (image_width <= 160*0) // Thumbnail captions


#else //Regular captions

  Screen_Object
  ( object
    { Caption
      ( "Classic Sphere", "timrom", <0.2, 0.1, 0.001>,
        blue 0.3, rgb 1 transmit 0.7, -1
      )
      scale 0.11
    },
    <0, 1>, <0.02, 0.02>, yes, 1
  )
  Screen_Object
  ( object
    { Caption ("Get yours today!", "", <0.3, 0.2, 0.001>, red 1, rgb 1, -1)
      scale 0.06
    },
    <1, 0.95>, <0.02, 0.02>, yes, 1
  )
  Screen_Object
  ( object
    { Caption_Object
      ( union
        { text { ttf "timrom" "POV-RAY" 1, 0 }
          text { ttf "povlogo" "P" 1, 0 translate <4.5, -0.2, 0> }
          text { ttf "timrom" "Object Collection" 1, 0 translate 5.5 * x }
        }
        <0.2, 0.1, 0.001>, rgb 0, rgb 1 transmit 0.6, -1
      )
      scale 0.07
    },
    <0.5, 0>, <0, 0.04>, yes, 1
  )

#end
