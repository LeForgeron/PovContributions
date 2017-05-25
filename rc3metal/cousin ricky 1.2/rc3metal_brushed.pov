/* rc3metal_brushed.pov version 1.2
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Contrast brushed metal normals.
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       27-aug-2011  Created.
 *       22-sep-2012  Adapted for Object Collection: my custom-written include
 *                    files are dropped and replaced with in-line code.
 * 1.0   09-mar-2013  Uploaded.
 * 1.1   23-apr-2013  No changes.
 * 1.2   06-sep-2013  No changes.
 */
//+w240 +h240 +a0.1 +am1 +r5 +j +kff2
#version 3.5;

#include "shapes.inc"
#include "textures.inc"
#include "rc3metal.inc"

global_settings { assumed_gamma 1 }

#declare V_OBJ = y;
#declare V_LIGHT = <-3.3125, 7.6250, -5.7374>;
camera
{ location <-3.4729, 3.8356, -3.4729>
  look_at V_OBJ
  right x
  up y
  angle 29.6299
}
light_source
{ V_LIGHT, rgb 2.5
  fade_power 2 fade_distance vlength (V_LIGHT - V_OBJ) / 2
}

#default { finish { diffuse 0.6 ambient rgb <0.15814, 0.16950, 0.11646> } }

box
{ -<7, 1, 7>, <7, 9, 7> hollow
  pigment { rgb 1 }
}

plane
{ y, 0
  pigment { checker rgb <0.0, 0.5, 0.08333> rgb <1.0, 0.75, 0.0> }
}

object
{ Round_Box_Union (<-1, 0, -1>, <1, 2, 1>, 0.25)
  #switch (frame_number)
    #case (1) texture { Brushed_Aluminum } #break
    #case (2) texture { Brushed_Aluminum normal { RC3M_n_Brushed } } #break
  #end
}
