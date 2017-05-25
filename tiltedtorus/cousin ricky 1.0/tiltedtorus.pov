/* tiltedtorus.pov version 1.0
 * Persistence of Vision Raytracer scene file
 * POV-Ray Object Collection demo
 *
 * Demo of tiltedtorus.inc
 *
 * Copyright 2012 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * 1.0   21-jul-2012  Created.
 */
#version 3.5;
#include "screen.inc"
#include "tiltedtorus.inc"

#ifndef (Annotate) #declare Annotate = yes; #end
#ifndef (Tilt) #declare Tilt = -45; #end
#ifndef (yScale) #declare yScale = 2; #end

#declare RMAJOR = 4;

global_settings { assumed_gamma 1 }

Set_Camera
( vrotate (<0, 0, -4 * (RMAJOR + 2.5)>, <20, 10, 0>),
  (Annotate? -0.75 * y: 0),
  30
)

light_source
{ <-1, 2, -3> * 1000, rgb 1
  parallel point_at 0
}

#declare v_Container = TiltedTorus_Container_v (RMAJOR, 1, yScale, Tilt);

difference
{ isosurface
  { function { TiltedTorus_fn (x, y, z, RMAJOR, 1, yScale, Tilt) }
    contained_by { box { -v_Container, v_Container } }
    max_trace 3
  }
  box
  { -v_Container, v_Container * y
    scale 1.01
  }
  pigment { rgb <1.0, 0.8, 0.1> }
  finish { specular 0.25 roughness 0.025 ambient 0.05 }
}

//==============================================================================

#if (Annotate)

  #macro Annotation (Text)
    text
    { ttf "crystal.ttf" Text 0.001, 0
      scale 0.075
      pigment { rgb 1 }
      finish { ambient 1 diffuse 0 }
    }
  #end

  Screen_Object
  ( Annotation (concat ("yScale = ", str(yScale,0,3))),
    <0, 0>, <0.02, 0.006>, yes, 1
  )
  Screen_Object
  ( Annotation (concat ("Tilt = ", str(Tilt,0,3))),
    <1, 0>, <0.02, 0.02>, yes, 1
  )

#end
