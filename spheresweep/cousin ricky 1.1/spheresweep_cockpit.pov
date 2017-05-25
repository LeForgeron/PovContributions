/* spheresweep_cockpit.pov version 1.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A demonstration of the SphereSweep module using trace() to control sphere
 * sweeps and SSwp_fn_Blob_strength() to control blob sizes.
 *
 * Copyright 2013 - 2015 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 * n/a   2013-Jul-03  Created.
 * 1.0   2013-Jul-22  Completed and uploaded.
 *       2015-May-10  Aspect ratio is changed to fit the new demo montage.
 *       2015-May-10  Colors are tweaked.
 *       2015-Aug-07  Sky (fog) and lighting colors are revised.
 * 1.1   2015-Aug-28  Pilots are added, with another example of trace().
 */
// +W540 +H450 +A0.02 +AM1 +J +R5
#version 3.5;

// Radiosity switch: 0 = off, 1 = medium quality, 2 = high quality
#ifndef (Rad) #declare Rad = 1; #end

#declare V_DEFAULT_CAM = <0, 1.5, -6.0>;
#ifndef (Debug_theta)
  #declare Debug_theta = degrees (atan2 (V_DEFAULT_CAM.x, -V_DEFAULT_CAM.z));
#end
#ifndef (Debug_phi)
  #declare Debug_phi = degrees (atan2 (V_DEFAULT_CAM.y, -V_DEFAULT_CAM.z));
#end
#ifndef (Debug_r) #declare Debug_r = vlength (V_DEFAULT_CAM); #end
#ifndef (Debug_cockpit) #declare Debug_cockpit = no; #end

#include "transforms.inc"
#include "consts.inc"
#include "spheresweep.inc"

global_settings
{ assumed_gamma 1
  #if (Rad)
    radiosity
    { count 200
      error_bound 0.5
      media on // for fog
      pretrace_end (Rad = 2? 2 / image_width: 0.01)
      recursion_limit 2
    }
  #end
  max_trace_level 10
}
#declare C_AMBIENCE = rgb (Rad? 0: <0.193, 0.242, 0.298>);
#default { finish { ambient C_AMBIENCE diffuse 0.75 } }

light_source // Sun
{ <-1, 1, -1> * 100000, rgb <1.194, 0.954, 0.734>
  parallel point_at 0
}

fog // poor man's Rayleigh scattering for sky
{ fog_type 2
  fog_offset 0
  color rgb <0.6, 0.8, 1.2>
  distance 30000
  fog_alt 6000
}

#declare V_AIM = 3000 * y;

camera
{ location V_AIM + vrotate (-Debug_r * z, <Debug_phi, Debug_theta, 0>)
  look_at V_AIM
  right 1.2 * x
  angle 46
}

plane // farmland (checkered plain) ;-)
{ y, 0
  pigment
  { checker
    rgb <0.34, 0.18, 0.10> // plowed
    rgb <0.27, 0.46, 0.09> // planted
    scale 1000
  }
  #if (!Rad) finish { ambient rgb <0.192, 0.256, 0.384> } #end
}

//============================= PILOT DEFINITION ===============================

#declare YHEAD = 7;
#declare YWAIST = 3.2;
#declare C_BLACK = rgb 0.04;
#declare C_GOLD = rgb <1, 0.6, 0>;

#declare f_Hat_metal = finish
{ reflection { 2/3 metallic }
  diffuse 0.25
  ambient C_AMBIENCE / 3
  specular 87 metallic
  roughness 0.00095
}
#declare Hat_button = sphere
{ 0, 1
  scale <0.04, 0.04, 0.02>
  translate <0, 0.77, -0.81>
  finish { f_Hat_metal }
  pigment { rgb <0.61, 0.59, 0.54> }
}
#declare Hat_cone = cone { 0.9 * y, 0.8, 1.5 * y, 1.05 }

#declare yHat_top = 1.25;
#declare aHat_top = 9;
#declare v_Hat_top = vrotate (yHat_top * y, aHat_top * x);
#declare Hat_rim_radii = array[1] { 0.015 }
#declare NHATCTRL = 15;
#declare Hat_rim_pts = array[NHATCTRL + 3]
#declare I = 0;
#while (I < NHATCTRL + 3)
  #declare Hat_rim_pts[I] = trace
  ( Hat_cone,
    v_Hat_top,
    vtransform
    ( z, transform { rotate I * 360 / NHATCTRL * y rotate aHat_top * x }
    )
  );
  #declare I = I + 1;
#end

#declare Hat = union
{// Top
  intersection
  { object
    { Hat_cone
      pigment
      { object
        { box { 0, 1 }
          pigment { C_BLACK }
         // POV-Ray 3.7 gives a warning here, but renders it as
         // intended.  POV-Ray 3.6 renders it slightly darker.
          pigment { image_map { png "spheresweep_wings" } }
        }
        translate <-0.5, -0.5, 0>
        scale <1, 0.5, 1>
        translate <0, 1.15, -1>
      }
    }
    plane { y, yHat_top rotate aHat_top * x }
  }
  object
  { SphereSweep_Union (SSWP_CUBIC_SPLINE, Hat_rim_pts, Hat_rim_radii, 5)
    pigment { rgb 1 }
  }
 // Middle
  cylinder { 0.65 * y, 0.9 * y, 0.8 }
  intersection
  { cylinder { 0, 0.12 * y 0.801 }
    plane { z, 0.06 }
    finish { f_Hat_metal }
    pigment { rgb <0.80, 0.57, 0.23> }
    normal
    { quilted 0.3
      scale <0.015 / pi, 0.024, 0.024>
      warp { cylindrical }
    }
    translate 0.71 * y
  }
  object { Hat_button rotate 90 * y }
  object { Hat_button rotate -90 * y }
 // Visor
  intersection
  { cone { 0, 0.8, -y, 0.9 }
    cone { 0.001 * y, 0.79, -1.001 * y, 0.89 inverse }
    cylinder
    { -x, x, 1
      scale <0.91, 1, 0.9>
      translate <0, 0, -0.9>
    }
    Shear_Trans (x, <0, 0.35, 0.5>, z)
    translate 0.65 * y
    pigment { rgb 0 }
    finish
    { specular 1.08 roughness 0.005
      reflection { 0 1 fresnel }
    }
    interior { ior 1.45 }
  }
  pigment { C_BLACK }
}

#declare p_Head = pigment
{ object
  { union
    { difference
      { cylinder { 0, -z, 1.1 }
        cylinder { 0, -1.1 * z, 0.9 }
        plane { <4, -3, 0>, 0 }
        plane { <-4, -3, 0>, 0 }
      }
      cylinder { 0, -z, 0.1 translate <-0.6, -0.8, 0> }
      cylinder { 0, -z, 0.1 translate <0.6, -0.8, 0> }
      cylinder { 0, -z, 0.125 translate <-0.45, -0.1, 0> }
      cylinder { 0, -z, 0.125 translate <0.45, -0.1, 0> }
      scale <0.85, 0.85, 1>
      translate 0.3 * y
    }
    rgb <1, 0.8, 0> rgb 0.025
  }
}

#declare p_Suit = pigment
{ object
  { union
    { prism // tie
      { 0, 1, 9,
        <0, YWAIST>, <-0.3, YWAIST + 0.3>, <-0.12, YHEAD - 1.6>,
        <-0.25, YHEAD - 1.35>, <0, YHEAD - 1>, <0.25, YHEAD - 1.35>,
        <0.12, YHEAD - 1.6>, <0.3, YWAIST + 0.3>, <0, YWAIST>
        rotate -90 * x
      }
      plane { y, YWAIST } // pants
    }
    rgb 1 C_BLACK
  }
}

#declare Shoulder_pts = array[4]
{ <0.9, 0.2, 0>, <1.2, 0.2, 0>, <1.35, -0.05, 0>, <1.2, -0.3, 0>
}
#declare Shoulder_rs = array[1] { 0.35 }
#declare Arm_pts = array[3]
{ <1.35, -0.05, 0>, <1.35, -1.25, -0.25>, <1.35, -1.25, -1.75>
}
#declare Arm_rs = array[2] { 0.35, 0.3 }
#declare Arm = union
{ SphereSweep_Union (SSWP_CUBIC_SPLINE, Shoulder_pts, Shoulder_rs, 10)
  SphereSweep_Union (SSWP_LINEAR_SPLINE, Arm_pts, Arm_rs, 1)
  translate (YHEAD - 2) * y
}

#declare Body = union
{ blob
  { sphere { YHEAD * y, 1.25, SSwp_fn_Blob_strength (1, 1.25) }
    cylinder
    { y, (YHEAD - 2) * y, 1.25, SSwp_fn_Blob_strength (1, 1.25)
      scale <1, 1, 0.9>
    }
    cylinder
    { <-1.2, 0.2, 0>, <-0.98, 0.29, 0>, 0.75, SSwp_fn_Blob_strength (0.35, 0.75)
      translate (YHEAD - 2) * y
    }
    cylinder
    { <1.2, 0.2, 0>, <0.98, 0.29, 0>, 0.75, SSwp_fn_Blob_strength (0.35, 0.75)
      translate (YHEAD - 2) * y
    }
  }
  object { Arm }
  object { Arm scale <-1, 1, 1> }
}

#declare x_Stripes = transform
{ scale <0.7, 0.5, 0.45>
  rotate -22.25 * z
  translate <0.85, YHEAD - 1, 0>
}
#declare Stripes_mask = box
{ -<0, 1, 0.5>, <1, 0, 0.5>
  transform { x_Stripes }
}

#macro Pilot (Rank, Head_turn)
  union
  { object { Hat rotate <15, Head_turn, 0> translate YHEAD * y }
    object { Body }
    pigment
    { object
      { intersection
        { plane { <0, 1, -0.15>, 0 translate <0, YHEAD - 1, 0.4> }
          plane { -z, 1.55 }
        }
        pigment { p_Head rotate Head_turn * y translate YHEAD * y }
        pigment // uniform
        { object
          { union
            { object { Stripes_mask }
              object { Stripes_mask scale <-1, 1, 1> }
            }
            pigment { p_Suit }
            pigment // stripes
            { gradient x color_map
              { #local S = 0;
                #while (S < Rank)
                  #local X = (16 - Rank * 3 + S * 6) / 30;
                  [X C_BLACK] [X C_GOLD]
                  [X + 4/30 C_GOLD] [X + 4/30 C_BLACK]
                  #local S = S + 1;
                #end
              }
              transform { x_Stripes }
              warp { repeat 2 * x flip x }
            } // end stripes
          }
        } // end uniform
      }
    }
    scale 0.15
  }
#end

//============================ AIRPLANE TEXTURES ===============================

#declare f_Paint = finish
{ specular 0.55 roughness 0.002857
  reflection { 0 0.25 fresnel } conserve_energy
}

#declare t_Paint = texture // checkered plane ;-)
{ pigment
  { gradient y pigment_map
    { [0.27 checker rgb <1, 0.8, 0> rgb <0.85, 0, 0.085>
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
// Close the shape:
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
#declare C_STRIPE = rgb <1, 2/3, 0>;

#declare Engine = union
{ difference
  { object
    { SphereSweep_Union (SSWP_CUBIC_SPLINE, Engine_pts, Engine_radii, 10)
      texture { t_Blank }
    }
    cylinder // intake
    { -z, z, 1 scale Engine_radii[1]
      translate Engine_pts[1]
    }
    cylinder // exhaust
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
  disc // propeller (well blurred)
  { 0, z, 1
    hollow // Allows sky to show behind the propellers
    pigment
    { wood ramp_wave color_map
      { #local Opq = WBLADE / sin (pi/4);
        [Opq C_PROP]
        #local NSTEPS = 10;
        #local I = ceil (Opq * NSTEPS);
        #while (I <= NSTEPS)
          #local R = I / NSTEPS;
          #local Xmit = (pi - 4 * asin (WBLADE / R)) / pi;
          #if (I <= NSTEPS - 1) [R C_PROP transmit Xmit] #end
          #if (I >= NSTEPS - 1) [R C_STRIPE transmit Xmit] #end
          #local I = I + 1;
        #end
      }
    }
    // An IOR is applied to the airplane as a whole for the paint gloss.
    // It needs to be preempted here to prevent refraction:
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
{ #declare Floor = 0.6;
 // Nose cone
  intersection
  { sphere { 0, 1 scale <1, 0.7, 2.5> translate <0, -0.3, 0> }
    plane { z, -1.5 }
  }
 // Cockpit area
  difference
  { object
    { Fore (0)
      texture { t_Paint }
    }
    intersection
    { sphere { 0, 0.95 }
      box { -<1, Floor, 1>, <1, 1, 0.001> }
    }
    object { Windshield_cutout }
    #if (Debug_cockpit) plane { x, 0 } #end
    texture { t_Interior }
  }
  object { Pilot (4, -15) translate <0.4, -Floor, -0.35> }
  object { Pilot (3, 15) translate <-0.4, -Floor, -0.35> }
 // Windshield
  #if (!Debug_cockpit)
    intersection
    { Fore (0.01)
      object { Fore (0.02) inverse }
      object { Windshield_cutout }
      material { m_Glass }
    }
  #end
  SphereSweep_Union (SSWP_CUBIC_SPLINE, Windshield_pts, Windshield_radii, 10)
 // Mid section and wings
  difference
  { blob
    { cylinder
      { 0, 10 * z, 1.5,
       // Match surface radius to other sections of the fuselage:
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
      plane { -y, Floor }
    }
    texture { t_Interior }
  }
  object { Engine translate <-2.5, -0.15, 1.75> }
  object { Engine translate <2.5, -0.15, 1.75> }
 // Tail
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
  translate <0, 0, -0.35>
  rotate 30.5 * y
  translate V_AIM
}
// end of spheresweep_cockpit.pov
