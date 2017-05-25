/* tiltedtorus.inc version 1.0
 * Persistence of Vision Raytracer include file
 * POV-Ray Object Collection
 *
 * A torus that is scaled in the y direction, then rotated about its circular
 * axis.
 *
 * Copyright 2012 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * 1.0   21-jul-2012  Created.
 */
#ifndef (TILTEDTORUS_INC) #declare TILTEDTORUS_INC = version;
#version 3.5;
#include "functions.inc"

#debug "#include \"tiltedtorus.inc\" //version 1.0\n"

#declare TiltedTorus__fn_x123 = function
( x, y, z, TiltedTorus_P0_RMajor, TiltedTorus_P1_rMinor,
  TiltedTorus_P2_yScale,
  TiltedTorus_P3_sinPA, TiltedTorus_P4_cosPA
)
{ f_torus
  ( (x + TiltedTorus_P0_RMajor) * TiltedTorus_P4_cosPA - z * TiltedTorus_P3_sinPA,
    y / TiltedTorus_P2_yScale,
    (x + TiltedTorus_P0_RMajor) * TiltedTorus_P3_sinPA + z * TiltedTorus_P4_cosPA,
    TiltedTorus_P0_RMajor,
    TiltedTorus_P1_rMinor
  )
}

#declare TiltedTorus__fn_x45 = function
( x, y, z, TiltedTorus_P0_RMajor, TiltedTorus_P1_rMinor,
  TiltedTorus_P2_yScale,
  TiltedTorus_P3_sinPA, TiltedTorus_P4_cosPA,
  TiltedTorus_P5_sinTilt, TiltedTorus_P6_cosTilt
)
{ TiltedTorus__fn_x123
  ( (x - TiltedTorus_P0_RMajor) * TiltedTorus_P6_cosTilt - y * TiltedTorus_P5_sinTilt,
    (x - TiltedTorus_P0_RMajor) * TiltedTorus_P5_sinTilt + y * TiltedTorus_P6_cosTilt,
    z,
    TiltedTorus_P0_RMajor,
    TiltedTorus_P1_rMinor,
    TiltedTorus_P2_yScale,
    TiltedTorus_P3_sinPA,
    TiltedTorus_P4_cosPA
  )
}

#declare TiltedTorus__fn_x6 = function
( x, y, z, TiltedTorus_P0_RMajor, TiltedTorus_P1_rMinor,
  TiltedTorus_P2_yScale,
  TiltedTorus_P3_sinPA, TiltedTorus_P4_cosPA,
  TiltedTorus_P5_sinTilt, TiltedTorus_P6_cosTilt
)
{ TiltedTorus__fn_x45
  ( x * TiltedTorus_P4_cosPA + z * TiltedTorus_P3_sinPA,
    y,
    z * TiltedTorus_P4_cosPA - x * TiltedTorus_P3_sinPA,
    TiltedTorus_P0_RMajor,
    TiltedTorus_P1_rMinor,
    TiltedTorus_P2_yScale,
    TiltedTorus_P3_sinPA,
    TiltedTorus_P4_cosPA,
    TiltedTorus_P5_sinTilt,
    TiltedTorus_P6_cosTilt
  )
}

#declare TiltedTorus_fn = function
( x, y, z, TiltedTorus_P0_RMajor, TiltedTorus_P1_rMinor,
  TiltedTorus_P2_yScale, TiltedTorus_P3_Tilt
)
{ TiltedTorus__fn_x6
  ( x,
    y,
    z,
    TiltedTorus_P0_RMajor,
    TiltedTorus_P1_rMinor,
    TiltedTorus_P2_yScale,
    sin (atan2(z,x)),
    cos (atan2(z,x)),
    sin (radians(TiltedTorus_P3_Tilt)),
    cos (radians(TiltedTorus_P3_Tilt))
  )
}

#macro TiltedTorus_Container_v (RMajor, rMinor, yScale, Tilt)
  <RMajor + rMinor * yScale, yScale, RMajor + rMinor * yScale>
#end

#version TILTEDTORUS_INC;
#end
