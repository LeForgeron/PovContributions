/* tiltedtorus.inc version 3.0.1
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * A torus that is scaled in the y direction, then rotated about its circular
 * axis.
 *
 * Copyright 2012 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 * 1.0    2012-Jul-21  Created.
 * 2.0    2014-Oct-09  A lathe object is added.
 * 2.0    2014-Oct-09  The container macro now accommodates yScale < 1.
 * 2.0a   2014-Nov-07  No change, except in the user manual.
 * 3.0    2016-Apr-02  The Sturm parameter is converted to a macro argument.
 * 3.0.1  2019-Apr-01  View_POV_Include_Stack is utilized.
 */
#ifndef (TiltedTorus_Inc_Temp) #declare TiltedTorus_Inc_Temp = version;
#version 3.5;
#declare TILTEDTORUS_VERSION = 3.01;
#ifdef (View_POV_Include_Stack)
  #debug "#include \"tiltedtorus.inc\" //version 3.0.1\n"
#end

#include "functions.inc"
#include "transforms.inc"

//======================= INTERNAL (PRIVATE) FEATURES ==========================
// These functions are not intended to be called directly by the user.

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

//============================= PUBLIC FEATURES ================================

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
  #local TiltedTorus_yScale = max (yScale, 1);
  < RMajor + rMinor * TiltedTorus_yScale,
    TiltedTorus_yScale,
    RMajor + rMinor * TiltedTorus_yScale
  >
#end

#macro TiltedTorus_Lathed (RMajor, rMinor, yScale, Tilt, Sturm)
  lathe
  { cubic_spline 27
    #local TiltedTorus_phi = -1;
    #while (TiltedTorus_phi <= 25)
      #local TiltedTorus_ctrlpt = vtransform
      ( rMinor * x,
        transform
        { rotate 15 * TiltedTorus_phi * z
          scale <1, yScale, 1>
          rotate -Tilt * z
          translate RMajor * x
        }
      );
      <TiltedTorus_ctrlpt.x, TiltedTorus_ctrlpt.y>
      #local TiltedTorus_phi = TiltedTorus_phi + 1;
    #end
    #if (Sturm) sturm #end
  }
#end

//=========================== DEPRECATED FEATURES ==============================
//                   (Retained for backwards compatibility)

#ifndef (TiltedTorus_Sturm) #declare TiltedTorus_Sturm = false; #end

#macro TiltedTorus_Lathe (RMajor, rMinor, yScale, Tilt)
  TiltedTorus_Lathed (RMajor, rMinor, yScale, Tilt, TiltedTorus_Sturm)
#end

//============================

#version TiltedTorus_Inc_Temp;
#end
// end of tiltedtorus.inc
