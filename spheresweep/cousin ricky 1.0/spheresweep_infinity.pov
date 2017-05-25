/* spheresweep_infinity.pov version 1.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstration of sphere_sweep wrapper and 2-D control points.
 * The rendered image has artifacts in POV-Ray 3.6.1, but not in 3.5 or 3.7.
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   11-jun-2013  Created.
 * 1.0   22-jul-2013  Uploaded.
 */
//+w400 +h200
#version 3.5;

#include "spheresweep.inc"

global_settings
{ assumed_gamma 1
  radiosity
  { count 50
    error_bound 0.5
    pretrace_end 0.01
    recursion_limit 2
  }
}
#default { finish { ambient 0 } }

camera
{ location -25 * z
  right 2 * x
  angle 30
}

light_source
{ <-1, 2, -2> * 1000, rgb 1
  area_light 500 * x, 500 * y, 9, 9 adaptive 1
  circular orient jitter
}

background { rgb 0.25 }

plane
{ -z, -0.85
  pigment { rgb <0.2, 0.8, 1.0> }
}

//------------------------------------------------------------------------------

#declare Pts = array[11]
{ <4, 3>, <0, 0>, <-4, -3>,
  <-6, 0>, <-4, 3>, <0, 0>, <4, -3>, <6, 0>,
  <4, 3>, <0, 0>, <-4, -3>
}
#declare Radii = array[10]
{ 0.12, 0.12, 0.72, 0.24, 0.24, 0.84, 0.24, 0.24, 0.72, 0.12
}

object
{ SphereSweep_Native (SSWP_B_SPLINE, Pts, Radii, 0)
  pigment { red 0.1 }
  finish { specular 0.25 roughness 0.025 }
}
