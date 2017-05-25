/* spheresweep_infinity.pov version 1.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A demonstration of the SphereSweep module's sphere_sweep wrapper, 2-D control
 * points, and B-spline.  The rendered frame of the sphere_sweep wrapper has
 * artifacts in POV-Ray 3.6.1, but not in 3.5 or 3.7.
 *
 * Copyright 2013 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   2013-Jun-11  Created.
 * 1.0   2013-Jul-22  Uploaded.
 *       2015-May-10  Aspect ratio is changed to fit new the demo montage.
 * 1.1   2015-Aug-28  A second frame is added with a B-spline union.
 */
// +KFF2 +W420 +H180 +A +AM2 -J
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
  right 7/3 * x
  angle 32
}

light_source
{ <-1, 2, -2> * 1000, rgb 1
  area_light 500 * x, 500 * y, 9, 9 adaptive 1
  circular orient jitter
}

background { rgb 0.25 }

plane
{ -z, -0.85
  pigment { rgb (frame_number = 2? 0.8: <0.2, 0.8, 1.0>) }
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

#switch (frame_number)

  #case (1) // wrapper for POV-Ray built-in sphere sweep with B-spline
    object
    { SphereSweep_Native (SSWP_B_SPLINE, Pts, Radii, 0)
      pigment { red 0.1 }
      finish { specular 0.25 roughness 0.025 }
    }
    #break

  #case (2) // sphere sweep approximation with B-spline
    object
    { SphereSweep_Union (SSWP_B_SPLINE, Pts, Radii, 20)
      pigment { red 0.1 }
      finish { specular 0.25 roughness 0.025 }
    }
    #break

#end
// end of spheresweep_infinity.pov
