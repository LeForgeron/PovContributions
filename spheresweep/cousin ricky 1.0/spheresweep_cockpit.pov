/* spheresweep_cockpit.pov version 1.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstration of SphereSweep using trace() to control a sphere sweep and
 * SSwp_fn_Blob_strength() to control blob sizes.
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   03-jul-2013  Created.
 * 1.0   22-jul-2013  Uploaded.
 */
//+w400 +h400 +a0.02 +am1 +j +r5
#version 3.5;

#ifndef (Rad) #declare Rad = yes; #end //radiosity switch

#declare V_DEFAULT_CAM = <0, 1.5, -6.0>;
#ifndef (Debug_theta)
  #declare Debug_theta = degrees (atan2 (V_DEFAULT_CAM.x, -V_DEFAULT_CAM.z));
#end
#ifndef (Debug_phi)
  #declare Debug_phi = degrees (atan2 (V_DEFAULT_CAM.y, -V_DEFAULT_CAM.z));
#end
#ifndef (Debug_r) #declare Debug_r = vlength (V_DEFAULT_CAM); #end

#include "transforms.inc"
#include "consts.inc"
#include "spheresweep.inc"

global_settings
{ assumed_gamma 1
  #if (Rad)
    radiosity
    { count 200
      error_bound 0.5
      media on //for fog
      pretrace_end 0.01
      recursion_limit 2
    }
  #end
  max_trace_level 10
}
#declare C_AMBIENCE = rgb (Rad? 0: <0.12, 0.15, 0.24>);
#default { finish { ambient C_AMBIENCE diffuse 0.75 } }

light_source
{ <-1, 1, -1> * 100000, rgb <1.05, 1.00, 0.85>
  parallel point_at 0
}

fog
{ fog_type 2
  fog_offset 0
  color rgb <0.44, 0.55, 0.88>
  distance 30000
  fog_alt 6000
}

#declare V_AIM = 3000 * y;

camera
{ location V_AIM + vrotate (-Debug_r * z, <Debug_phi, Debug_theta, 0>)
  look_at V_AIM
  right x
  angle 40
}

plane
{ y, 0
  pigment
  { checker rgb <0.34, 0.17, 0.085> rgb <0.22, 0.44, 0.088>
    scale 1000
  }
}

//===========================  AIRPLANE TEXTURES ===============================

#declare f_Paint = finish
{ specular 0.55 roughness 0.002857
  reflection { 0 0.25 fresnel } conserve_energy
}

#declare t_Paint = texture
{ pigment
  { gradient y pigment_map
    { [0.27 checker rgb <1, 0.8, 0> rgb <0.9, 0, 0.03>
            translate <0, 0, 0.585> scale <0.251, 0.135, 0.135>]
      [0.27 rgb 1]
    }
    scale 2
  }
  finish { f_Paint }
}

#declare t_Blank = texture
{ pigment { rgb 1 }
  finish { f_Paint }
}

#declare o_Livery = Center_Object (text { ttf "povlogo.ttf" "P" 1, 0 }, x+y)
#declare t_Livery = texture
{ pigment
  { object
    { union
      { object { o_Livery rotate -90 * y }
        object { o_Livery rotate 90 * y }
        scale <-1, 1, 1> * 1.2
      }
      rgb 1 rgb <0, 0.15, 0.55>
    }
  }
  finish { f_Paint }
}

#declare t_Interior = texture
{ pigment { rgb 0.5 }
}

#declare m_Glass = material
{ texture
  { pigment { rgbf 1 }
    finish
    { specular 6.26 roughness 0.001
      reflection { 0 1 fresnel } conserve_energy
    }
  }
  interior
  { ior Crown_Glass_Ior
    fade_color <0, 0.8, 0.4>
    fade_power 1001
    fade_distance 0.05
  }
}

//=========================== AIRPLANE DEFINITION ==============================

//------------------- Nose and Cockpit ---------------------

#declare fn_Y = function (z, P0_Inset)
{ select
  ( z + 1,
    0.1 * pow (max (z + 1.5, 0) / 0.5, 2) - 0.3,
    -0.2 * pow (z / 1.0, 2)
  )
}

#declare fn_Fore = function (x, y, z, P0_y, P1_Inset)
{ f_sphere (x, (y - P0_y) / (1 + P0_y), z / 2.5, 1 - P1_Inset)
}

#macro Fore (Inset)
  isosurface
  { function { fn_Fore (x, y, z, fn_Y (z, Inset), Inset) }
    max_gradient 1.71 - Inset * 0.45
    contained_by
    { box { <Inset - 1, Inset - 1, -1.5>, <1 - Inset, 1 - Inset, 0> }
    }
    max_trace 4
  }
#end

//----------- Test Object for Windshield Trace -------------

#declare Windshield_test = Fore (0.015)

//-------------- Windshield Control Points -----------------
// Trace the windshield against the test object.

#declare NWS_TOP = 10;
#declare NWS_SIDE = 7;
#declare NWS_BOTTOM = 14;
#declare NWS = NWS_TOP + NWS_SIDE * 2 + NWS_BOTTOM + 3;

#declare Windshield_pts = array[NWS]

#declare I = 0;
#while (I < NWS_TOP)
  #declare Windshield_pts[I] = trace
  ( Windshield_test,
    <0, 0.8, 0>,
    vrotate (-z, (I / NWS_TOP - 0.5) * 120 * y)
  );
  #declare I = I + 1;
#end
#declare Start = I;
#while (I < Start + NWS_SIDE)
  #declare Angle = radians ((I - Start) / NWS_SIDE * 180);
  #declare Windshield_pts[I] = trace
  ( Windshield_test,
    <0, cos (Angle) * 0.25 + 0.55, 0>,
    vrotate (-z, (sin (Angle) * 15 + 60) * y)
  );
  #declare I = I + 1;
#end
#declare Start = I;
#while (I < Start + NWS_BOTTOM)
  #declare Windshield_pts[I] = trace
  ( Windshield_test,
    <0, 0.3, 0>,
    vrotate (-z, (0.5 - (I - Start) / NWS_BOTTOM) * 120 * y)
  );
  #declare I = I + 1;
#end
#declare Start = I;
#while (I < Start + NWS_SIDE)
  #declare Angle = radians ((I - Start) / NWS_SIDE * 180 + 180);
  #declare Windshield_pts[I] = trace
  ( Windshield_test,
    <0, cos (Angle) * 0.25 + 0.55, 0>,
    vrotate (-z, (sin (Angle) * 15 - 60) * y)
  );
  #declare I = I + 1;
#end
//Close the shape:
#declare Start = I;
#while (I < Start + 3)
  #declare Windshield_pts[I] = trace
  ( Windshield_test,
    <0, 0.8, 0>,
    vrotate (-z, ((I - Start) / NWS_TOP - 0.5) * 120 * y)
  );
  #declare I = I + 1;
#end

#declare Windshield_radii = array[1] { 0.015 }

//--------------- Windshield Cutout Object -----------------

#declare Projection_plane = plane { z, -1 }
#declare Windshield_cutout = prism
{ conic_sweep cubic_spline 0, 2, NWS
  #declare I = 0;
  #while (I < NWS)
    #declare Projection = trace (Projection_plane, 0, Windshield_pts[I]);
    <Projection.x, Projection.y>
    #declare I = I + 1;
  #end
  rotate -90 * x
}

//----------------- Other Airplane Parts -------------------

#macro Wing_blob (Side)
  #local EQTRI = sqrt(0.75);
  #local XWINGTIP = 7;
  #local RWINGTIP = 0.15;
  #local x_Pos = transform
  { rotate 5 * x
    Shear_Trans (<Side, 0.1, 0.05>, y, z)
    translate <0, -0.7, 2.75>
  }
  cylinder
  { 0.08 / RWINGTIP * x, XWINGTIP / RWINGTIP * x, 1.75,
    SSwp_fn_Blob_strength (1, 1.75)
    scale <RWINGTIP, 0.2, 1>
    transform x_Pos
  }
  cylinder
  { x, XWINGTIP * x, 2, -2
    translate <0, -EQTRI * 2, 0>
    transform x_Pos
  }
  cylinder
  { <1, -EQTRI * 1.5, 0.24>, <XWINGTIP, -EQTRI * 1.5, 0.18>, 1.5, -3
    transform x_Pos
  }
  cylinder
  { <1, -EQTRI, 0.48>, <XWINGTIP, -EQTRI, 0.36>, 1, -4
    transform x_Pos
  }
  sphere
  { <10, 0, 0>, 9, -0.4
    transform x_Pos
  }
#end

//--------------------------------------

#declare Engine_pts = array[6]
{ <0, 0, -2>, <0, 0, -1>, <0, 0, 0>,
  <0, -0.04, 1>, <0, -0.16, 2>, <0, -0.36, 3>
}
#declare Engine_radii = array[6] { 0, 0.35, 0.50, 0.40, 0.18, 0 }
#declare Exhaust = dimension_size (Engine_pts, 1) - 2;
#declare WBLADE = 0.1;
#declare C_PROP = rgb 0.05;

#declare Engine = union
{ difference
  { object
    { SphereSweep_Union (SSWP_CUBIC_SPLINE, Engine_pts, Engine_radii, 10)
      texture { t_Blank }
    }
    cylinder //intake
    { -z, z, 1 scale Engine_radii[1]
      translate Engine_pts[1]
    }
    cylinder //exhaust
    { -z, z, 1 scale Engine_radii [Exhaust]
      translate Engine_pts [Exhaust]
    }
    pigment { rgb 0.05 }
  }
  sphere
  { 0, 0.22
    scale <1, 1, 2.3>
    pigment { C_PROP }
    translate Engine_pts[1]
  }
  disc //propeller (well blurred)
  { 0, z, 1 hollow
    pigment
    { wood ramp_wave color_map
      { #local Opq = WBLADE / sin (pi/4);
        [Opq C_PROP]
        #local NSTEPS = 10;
        #local I = ceil (Opq * NSTEPS);
        #while (I <= NSTEPS)
          #local R = I / NSTEPS;
          [R C_PROP transmit (pi - 4 * asin (WBLADE / R)) / pi]
          #local I = I + 1;
        #end
      }
    }
    interior { ior 1 }
    scale 1.1
    translate <0, 0, -1.25>
  }
}

//--------------------------------------

#declare Stabilizer = prism
{ conic_sweep cubic_spline 2/3, 1, 7,
  <-0.15, 2>, <0, 1>, <0.15, -0.4>, <0, -1>,
  <-0.15, -0.4>, <0, 1>, <0.15, 2>
  translate -y
  Shear_Trans (x, <0, -7.5, -2.5>, z)
}

//--------------------------------------

#declare Aft_pts = array[8]
#declare Aft_radii = array[8]
#declare I = 0;
#while (I < 8)
  #declare Z = (I - 1) * 0.95;
  #declare Y = pow (Z/5, 2);
  #declare Aft_pts[I] = <0, Y, Z>;
  #declare Aft_radii[I] = 1 - Y;
  #declare I = I + 1;
#end

//------------------ Airplane Assembly ---------------------

#declare Airplane = union
{//Nose cone
  intersection
  { sphere { 0, 1 scale <1, 0.7, 2.5> translate <0, -0.3, 0> }
    plane { z, -1.5 }
  }
 //Cockpit area
  difference
  { object
    { Fore (0)
      texture { t_Paint }
    }
    intersection
    { sphere { 0, 0.95 }
      box { -<1, 0.5, 1>, <1, 1, 0.001> }
    }
    object { Windshield_cutout }
    texture { t_Interior }
  }
 //Windshield
  intersection
  { Fore (0.01)
    object { Fore (0.02) inverse }
    object { Windshield_cutout }
    material { m_Glass }
  }
  SphereSweep_Union (SSWP_CUBIC_SPLINE, Windshield_pts, Windshield_radii, 10)
 //Mid section and wings
  difference
  { blob
    { cylinder
      { 0, 10 * z, 1.5,
       //Match surface radius to other sections of the fuselage:
        SSwp_fn_Blob_strength (1, 1.5)
        scale <1, 1, 0.5>
        texture { t_Paint }
      }
      Wing_blob (-1)
      Wing_blob (1)
      texture { t_Blank }
    }
    intersection
    { cylinder { -z, 0.5 * z, 0.95 }
      plane { -y, 0.5 }
    }
    texture { t_Interior }
  }
  object { Engine translate <-2.5, -0.15, 1.75> }
  object { Engine translate <2.5, -0.15, 1.75> }
 //Tail
  object
  { SphereSweep_Union (SSWP_CUBIC_SPLINE, Aft_pts, Aft_radii, 10)
    translate 5 * z
  }
  object
  { Stabilizer
    texture { t_Livery translate <0, 1.2, 0.4> }
    translate <0, 0.9, 8.5>
  }
  object
  { Stabilizer
    texture { t_Blank }
    scale <0.8, 0.9, 0.8>
    rotate -80 * z
    translate <0.1, 0.6, 8.4>
  }
  object
  { Stabilizer
    texture { t_Blank }
    scale <0.8, 0.9, 0.8>
    rotate 80 * z
    translate <-0.1, 0.6, 8.4>
  }
  texture { t_Paint }
  interior { ior 1.54 }
}

//==============================================================================

object
{ Airplane
  translate -0.25 * z
  rotate 30.5 * y
  translate V_AIM
}
