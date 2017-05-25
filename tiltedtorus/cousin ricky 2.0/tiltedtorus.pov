/* tiltedtorus.pov version 2.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demo of tiltedtorus.inc
 *
 * Copyright 2012 - 2014 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * 1.0   21-Jul-2012  Created.
 * 2.0   09-Oct-2014  Lathe demo is added.
 * 2.0   09-Oct-2014  Isosurface max_gradient is added for yScale < 1.
 */
#version 3.5;
#include "screen.inc"
#include "tiltedtorus.inc"

#ifndef (Annotate) #declare Annotate = yes; #end
#ifndef (Tilt) #declare Tilt = -45; #end
#ifndef (Type) #declare Type = 2; #end
#ifndef (yScale) #declare yScale = 2; #end

#declare RMAJOR = 4;
#declare rMINOR = 1;

global_settings { assumed_gamma 1 }

Set_Camera (vrotate (<0, 0, -4 * (RMAJOR + 2.5)>, <20, 10, 0>), -0.7 * y, 30)

light_source
{ <-1, 2, -3> * 1000, rgb 1
  parallel point_at 0
}

#declare v_Container = TiltedTorus_Container_v (RMAJOR, rMINOR, yScale, Tilt);

difference
{ #switch (Type)
    #case (1)
      isosurface
      { function { TiltedTorus_fn (x, y, z, RMAJOR, rMINOR, yScale, Tilt) }
        contained_by { box { -v_Container, v_Container } }
        max_gradient 1 / (rMINOR * min (yScale, 1))
        max_trace 3
      }
      #break
    #case (2)
      TiltedTorus_Lathe (RMAJOR, rMINOR, yScale, Tilt)
      #break
  #end
  box
  { -v_Container, v_Container * y
    scale 1.01
  }
  pigment { rgb <1.0, 0.3, 0.45> }
  finish { specular 0.25 roughness 0.025 ambient 0.05 }
}

//==============================================================================

#if (Annotate)

  #macro Annotation (Text, Font)
    text
    { ttf Font Text 0.001, 0
      scale 0.075
      pigment { rgb 1 }
      finish { ambient 1 diffuse 0 }
    }
  #end

  Screen_Object
  ( Annotation
    ( #switch (Type)
        #case (1) "Isosurface" #break
        #case (2) "Lathe" #break
        #else concat ("Unknown type ", str (Type, 0, -1)) #break
      #end,
      "cyrvetic"
    ),
    <0, 1>, <0.02, 0.02>, yes, 1
  )
  Screen_Object
  ( Annotation (concat ("yScale = ", str(yScale,0,3)), "crystal"),
    <0, 0>, <0.02, 0.006>, yes, 1
  )
  Screen_Object
  ( Annotation (concat ("Tilt = ", str(Tilt,0,3)), "crystal"),
    <1, 0>, <0.02, 0.02>, yes, 1
  )

#end
