/* roundedge.pov version 1.3.1
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstration of roundedge.inc functions and macros.
 *
 * Copyright 2008 - 2016 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date        Comments
 * -----  ----        --------
 *        2008-Jul-17  Created.
 *        2008-Aug-25  Completed.
 * 1.0    2008-Sep-04  Uploaded.
 *        2012-Jun-07  Several aesthetic changes:
 *                      - Fog is removed and light source is made parallel;
 *                      - Radiosity, lighting, and some textures are tweaked;
 *                      - POV logo is reworked.
 *        2012-Jun-07  Defaults gracefully if Microsoft fonts aren't available.
 *        2012-Jun-08  Frame order is rearranged to match the user manual;
 *                     elliptical toroid place holders are removed.
 *        2012-Jun-08  Demo frames are added for RE_Corner_join() and
 *                     RE_Round_inside_join().
 * 1.1    2012-Jun-09  Uploaded.
 *        2012-Jul-17  Scenes are tested for 3.5 compatibility.
 * 1.2    2013-Mar-01  Demo frames added for elliptical toroids.
 *        2013-Apr-21  Clouds are added for more interesting metallic
 *                     reflections; the sky is tweaked; the lighting is
 *                     reworked; and the textures are brightened.
 *        2013-Apr-21  Checks are added for negative sqrt() operands.
 * 1.3    2013-Jun-15  Blob function names are changed.
 *        2014-Feb-14  The colors of the test objects are redone.
 *        2015-Mar-08  woods.inc is #included /after/ #default ambient.  This
 *                     makes a difference when radiosity is not used.
 *        2016-Jan-19  The sky is remodeled, and the lighting is made sunnier.
 *        2016-Jan-19  The RE_fn_Hole() and RE_fn_Wheel demos are adjusted to
 *                     better illustrate the isosurface patches.
 * 1.3.1  2016-Jan-23  Some metallic textures are made shinier.
 */
// +W800 +H600 Declare=Rad=1 +A0.05 +AM2 +R3 Declare=Soft=5
// +W160 +H120 Declare=Rad=1 +A0.05 +AM2 +R3 +Oroundedge_thumbnail
// +W240 +H180 Declare=Rad=1 +A0.05 +AM2 +R3 +KFF30 +Oroundedge_
#version 3.5;

#include "roundedge.inc"
#include "colors.inc"
#include "skies.inc"
#include "functions.inc"
#include "textures.inc"

//============================= DEMO PARAMETERS ================================

#if (clock_on)
  #declare Test = frame_number;
#else
  #ifndef (Test) #declare Test = 0; #end
#end

#ifndef (Rad) #declare Rad = off; #end  //radiosity on/off
#ifndef (MaxG) #declare MaxG = no; #end //test max_gradient by forcing more rays
#ifndef (Soft) #declare Soft = 0; #end  //soft shadows; 1.0 = solar

// These Microsoft fonts are used because they have good variants:
#declare s_Bold_font = "arialbd.ttf" //cyrvetic has no bold variant
#declare s_Normal_font = "arial.ttf"
#declare s_Var_font = "timesbi.ttf"  //timrom has no italic variant

// If Microsoft fonts aren't available:
#if (!file_exists (s_Bold_font))
  #declare s_Bold_font = "cyrvetic.ttf"
#end
#if (!file_exists (s_Normal_font))
  #declare s_Normal_font = "cyrvetic.ttf"
#end
#if (!file_exists (s_Var_font))
  #declare s_Var_font = "timrom.ttf"
  #declare Shear_font = yes;
#else
  #declare Shear_font = no;
#end

//============================== AN ENVIRONMENT ================================

#ifndef (Debug_angle) #declare Debug_angle = 30; #end
#ifndef (Debug_boom) #declare Debug_boom = 15; #end
#ifndef (Debug_dolly) #declare Debug_dolly = -20; #end
#ifndef (Debug_zoom_out) #declare Debug_zoom_out = 16; #end

global_settings
{ assumed_gamma 1
  max_trace_level (MaxG? 55: 15)
  #if (Rad)
    #declare Pretrace = 1 / max (image_width, image_height);
    radiosity
    { count 200
      error_bound 0.5
      pretrace_start 32 * Pretrace
      pretrace_end 2 * Pretrace
      recursion_limit 2
    }
  #end
}

#declare v_Sun = <-2, 8, -5> * 1000;
#declare RSun = vlength (v_Sun) / 215;
light_source
{ v_Sun, rgb <1.221, 0.950, 0.683>
  parallel point_at 0
  #if (Soft)
    #declare Fuzz = 2 * RSun * Soft;
    area_light x * Fuzz, z * Fuzz, 9, 9
    circular orient adaptive 1
  #end
}

#declare p_Skygrad = pigment
{ gradient y color_map
  { [0.0 rgb <1.736, 2.391, 3.983>]
    [0.1 rgb <1.341, 1.857, 3.119>]
    [0.2 rgb <1.026, 1.429, 2.428>]
    [0.3 rgb <0.780, 1.096, 1.889>]
    [0.4 rgb <0.595, 0.846, 1.485>]
    [0.5 rgb <0.462, 0.667, 1.195>]
    [0.6 rgb <0.374, 0.546, 1.000>]
    [0.7 rgb <0.320, 0.474, 0.883>]
    [0.8 rgb <0.292, 0.436, 0.822>]
    [0.9 rgb <0.282, 0.422, 0.800>]
    [1.0 rgb <0.280, 0.420, 0.797>]
  }
}

#declare c_Halo = rgb <2.406, 2.872, 3.818>;
#declare p_Halo = pigment
{ wood ramp_wave color_map
  { [0.0 c_Halo]
    [0.1 c_Halo * 0.622]
    [0.2 c_Halo * 0.380]
    [0.3 c_Halo * 0.225]
    [0.4 c_Halo * 0.124]
    [0.5 c_Halo * 0.060]
    [0.6 c_Halo * 0.019]
    [0.7 rgb 0]
  }
  Reorient_Trans (z, v_Sun)
}

sky_sphere
{ pigment
  { average pigment_map
    { [1 p_Skygrad]
      [1 p_Halo ]
    }
  }
  pigment { P_Cloud1 scale 0.075 }
}

#declare Diffuse = 0.6;
// general ambient:
#declare c_Ambience = rgb (Rad? 0: <0.224, 0.248, 0.335>);
// upward facing surfaces:
#declare c_Ground_ambience = rgb (Rad? 0: <0.186, 0.237, 0.368>);

#default { finish { diffuse Diffuse ambient c_Ground_ambience } }
#include "woods.inc"

plane { y, -2.5 pigment { rgb 0.5 } }

camera
{ #if (Debug_angle >= 70) ultra_wide_angle #end
  location -Debug_zoom_out * z
  rotate <Debug_boom, Debug_dolly, 0>
  look_at 0
  up image_height * y
  right image_width * x
  angle Debug_angle
}

//---------------- chess board -------------------

box { -4, <4, -2, 4> pigment { checker rgb 1, rgb 0.025 } }
#declare Side = intersection
{ RE_Box (-<4.25, 2.5, 4.25>, <4.25, -1.95, -4>, 0.05, no)
  box { -y, <6, -3, 6> rotate 135 * y }
  texture
  { T_Wood6
    finish { specular 0.379 roughness 0.01 }
    rotate <-15, 90, 0> scale 0.25
  }
}
object { Side }
object { Side rotate 90 * y }
object { Side rotate 180 * y }
object { Side rotate 270 * y }

//================================= TEXTURES ===================================

#default { finish { diffuse Diffuse ambient c_Ambience } }

// Fooling around with the Adobe color system in Lightsys IV led to this
// beautiful array of colors.
#declare Vary = array[6]
{ <0.6046, 0.2200, 0.7936>,
  <0.9891, 0.2200, 0.5068>,
  <0.8796, 0.4950, 0.2082>,
  <0.3854, 0.7700, 0.1964>,
  <0.0009, 0.7700, 0.4832>,
  <0.1104, 0.4950, 0.7818>,
}

#declare t_Sample = texture
{ pigment { rgb Vary[mod (Test, 6)] }
  finish
  { specular 0.154 roughness 0.025
    diffuse Diffuse * 1.25 ambient c_Ambience * 1.25
  }
}

#declare t_Metal_dull = texture
{ finish
  { reflection { 0.1 metallic }
    diffuse Diffuse * 0.9
    ambient c_Ambience * 0.9
    brilliance 1.86
    specular 1.50 metallic
    roughness 0.0329
  }
}

#declare t_Special = texture
{ t_Metal_dull
  pigment { rgb Vary[mod (Test + 4, 6)] }
}

#declare t_Metal_shine = texture
{ finish
  { reflection { 2/3 metallic }
    diffuse Diffuse / 3
    ambient c_Ambience / 3
    brilliance 1.86
    specular 100 metallic
    roughness 0.000958
  }
}

#declare t_Max_gradient_test = texture
{ pigment { rgb <0.500, 0.508, 0.545> }
  finish
  { reflection { 1 metallic }
    diffuse 0
    ambient 0
    specular 4095 metallic
    roughness 0.0000296
  }
}

//============================== CONTEXT TOOLS =================================

#macro Sticker (Caption, Font, Place, Size, Paint)
  #local Label = text
  { ttf #if (strcmp (Font, "")) Font #else s_Bold_font #end
    Caption 0.025, 0
  }
  object
  { Label
    translate -(max_extent(Label) + min_extent(Label)) / 2
    scale Size
    translate Place
    pigment { color Paint }
    no_shadow
    no_reflection
  }
#end

#macro Coord_label (Caption, Place, Paint)
  object
  { Sticker (Caption, s_Var_font, 0, 0.75, Paint)
    #if (Shear_font) Shear_Trans (x, <0.3, 1, 0>, z) #end
    translate Place
  }
#end

#declare Axis = merge
{ cylinder { -3.5*x, 3.5*x, 0.05 }
  cone { 3.25*x, 0.15, 3.75*x, 0 }
}

#declare Axes = union
{ object { Axis pigment { red 1 transmit 0.5 } }
  object { Axis pigment { green 0.5 transmit 0.5 } rotate 90 * z translate -y }
  object { Axis pigment { blue 1 transmit 0.5 } rotate -90 * y }
  Coord_label ("x", <3.5, 0.5, 0>, red 1 transmit 0.5)
  Coord_label ("y", <0.5, 2.5, 0>, green 0.5 transmit 0.5)
  Coord_label ("-z", <0, -0.3, -3.5>, blue 1 transmit 0.5)
}

#declare Caption = "";

//================================ SHOWPIECE ===================================

#declare H3 = -0.4;
#declare H2 = -1.2;
#declare H1 = -1.5;
#declare H0 = -2;
#declare rPLAT = 0.05;
#declare R1 = 3.1;
#declare R2 = 2.6;
#declare R3 = 2.3;

//-------------- marble platform -----------------

#declare fn_Wide_ribs = function
{ f_sphere (x, 0, z, R3 - (cos (atan2 (z, x) * 20) + 1) * 0.075)
}
#declare fn_Thin_ribs = function
{ f_sphere (x, 0, z, R3 - 0.325 + pow (cos (atan2 (z, x) * 20) + 1, 2) * 0.075)
}
#declare fn_Column = function
{ 1 - sqrt
  ( RE_fn_Blob2 (fn_Wide_ribs (x, y, z), rPLAT)
  + RE_fn_Blob2 (fn_Thin_ribs (x, y, z), rPLAT)
  )
}

#declare Platform = union
{ RE_Box (<-R1, H0, -R1>, <R1, H1, R1>, rPLAT, no)
  object { RE_Round_join (R2, rPLAT) translate H1 * y }
  RE_Cylinder_end (H2 * y, (H1 + rPLAT) * y, R2, rPLAT, no)
  isosurface
  { function //create a rounded edge using the negative image of a blob
    { sqrt
      ( RE_fn_Blob2 (-fn_Column (x, y, z) * rPLAT, rPLAT)
      + RE_fn_Blob2 (H3 - y, rPLAT)
      ) - 1
    }
    max_gradient 2/rPLAT
    contained_by { box { <-R3, H3 - rPLAT, -R3>, <R3, H3, R3> } }
  }
  isosurface
  { function { fn_Column (x, y, z) }
    max_gradient 2/rPLAT
    contained_by { box { <-R3, H2 + rPLAT, -R3>, <R3, H3 - rPLAT, R3> } }
  }
  isosurface
  { function
    { max
      ( 1 - sqrt
        ( RE_fn_Blob2 (fn_Column (x, y, z) * rPLAT, rPLAT)
        + RE_fn_Blob2 (y - H2, rPLAT)
        ),
        f_sphere (x, 0, z, R3 + rPLAT)
      )
    }
    max_gradient 2/rPLAT
    contained_by { box { <-R3, H2, -R3> - rPLAT, <R3, H2, R3> + rPLAT } }
  }
  texture
  { pigment { Red_Marble scale 2 translate -0.5 }
    finish
    { specular 0.965 roughness 0.0025
      reflection { 0 0.4 fresnel }
    }
  }
  interior { ior 1.486 } //for calcite or coral; couldn't find marble
}

//------------------ POV logo --------------------

#declare rLOGO1 = 0.075;
#declare rLOGO2 = 0.05;
#declare CRESCENT_ROTN = 30;
#declare POVLOGO_ROTN = -25;

#declare Crescent_sin = sin (radians (CRESCENT_ROTN));
#declare Crescent_cos = cos (radians (CRESCENT_ROTN));
#declare PovLogo_sin = sin (radians (POVLOGO_ROTN));
#declare PovLogo_cos = cos (radians (POVLOGO_ROTN));

#declare fn_Logo_cone = function
{ f_sphere (x, 0, z, (y + 4) / 6)
}

// Create a rounded edge using the negative image of a blob.
#declare fn_Logo_crescent = function
{ sqrt
  ( RE_fn_Blob2 (-f_sphere (x / 2.6, y / 2.2, z / 1.038, 1), rLOGO2)
  + RE_fn_Blob2 (f_sphere ((x + 0.328) / 2.249, y / 1.778, z / 2.076, 1), rLOGO2)
  ) - 1
}

#declare Povument = union
{ sphere { 2*y, 1 }
  cone { -4*y, 0, -0.42*y, 179/300 }
  isosurface //top of cone
  { function //create a rounded edge using the negative image of a blob
    { sqrt
      ( RE_fn_Blob2 (-fn_Logo_cone (x, y, z), rLOGO1)
      + RE_fn_Blob2 (f_sphere (x, y - 2, z/2, 1.391), rLOGO1)
      ) - 1
    }
    max_gradient 1/rLOGO1
    contained_by { box { <-0.81, 0.5, -0.81>, <0.81, 0.84, 0.81> } }
  }
  isosurface //crescent
  { function { fn_Logo_crescent (x, y, z) }
    max_gradient 1/rLOGO2
    contained_by { box { -<2.42, 2.2, 0.73>, <2.6, 2.2, 0.73> } }
    rotate CRESCENT_ROTN * z translate 2*y
  }
  isosurface //join cone & crescent
  { function
    { 1 - sqrt
      ( RE_fn_Blob2 (fn_Logo_cone (x, y, z), rLOGO1)
      + RE_fn_Blob2
        ( fn_Logo_crescent
          ( (y - 2) * Crescent_sin + x * Crescent_cos,
            (y - 2) * Crescent_cos - x * Crescent_sin,
            z
          ) * rLOGO2,
          rLOGO2
        )
      )
    }
    max_gradient 1/rLOGO2
    contained_by { box { -<0.75, 0.42, 0.75>, <0.82, 0.5, 0.75> } }
  }
  rotate POVLOGO_ROTN * z
  translate <-0.5, 4 * PovLogo_cos, 0>
  texture { t_Metal_shine pigment { rgb <0.2, 0.4, 0.8> } }
}

//----------------- screw head -------------------

#declare rSCREW = 1;
#declare YSLOT = 3;
#declare Rot45 = sqrt(0.5);

#declare fn_Slot = function
{ f_sphere (max (y*Rot45 + x*Rot45, 0), max (y*Rot45 - x*Rot45, 0), z, 1)
}

#declare Screw_head = union
{ isosurface
  { function //create a rounded edge using the negative image of a blob
    { sqrt
      ( max //check for negative sqrt operand when using a negative component
        ( RE_fn_Blob2 (fn_Slot (x, YSLOT - y, z), rSCREW)
        + RE_fn_Blob2 (fn_Slot (z, YSLOT - y, x), rSCREW)
        + RE_fn_Blob2 (-RE_fn_Wheel (x, y - 1, z, 2, 6), rSCREW)
        - RE_fn_Blob2 (f_sphere (x, y - YSLOT, z, 1), rSCREW),
          0
        )
      ) - 1
    }
    max_gradient 1.3/rSCREW
    contained_by { box { <-8, 1, -8>, <8, 7, 8> } }
  }
  torus { 7, 1 translate y }
  texture { t_Metal_dull pigment { rgb <0.533, 0.586, 0.611> } }
  rotate 123.456 * y //randomish
  scale 1/32
}

//----------------- metal base -------------------

#declare HHOLD = 1;
#declare THIN = 0.035;
#declare RHOLD = HHOLD / 6 + THIN;
#declare rTHIN = THIN * 6 / (5 + sqrt(37));

#declare Holder = union
{ object
  { RE_Washer_end ((HHOLD - 4) * y, -4 * y, RHOLD, RHOLD - 2*rTHIN, rTHIN, no)
    rotate POVLOGO_ROTN * z
    translate <-0.5, 4 * PovLogo_cos, 0>
  }
 //A valid boundary case that would crash Round_Cylinder()
  RE_Cylinder (0, 2*rTHIN * y, 3.5, rTHIN, no)
  object
  { RE_Round_join (RHOLD, 0.1)
    Shear_Trans (x / PovLogo_cos, <-PovLogo_sin, PovLogo_cos, 0>, z)
    translate <(4 - 2*rTHIN) * PovLogo_sin - 0.5, 2*rTHIN, 0>
  }
  object { Screw_head translate 3 * x }
  object { Screw_head translate 3 * x rotate 120 * y }
  object { Screw_head translate 3 * x rotate -120 * y }
  texture { t_Metal_shine pigment { rgb <0.485, 0.469, 0.456> } }
}

//=============================== DEMO SAMPLES =================================

#declare Dashed_line = cylinder
{ 0, x, 1 scale <20, 0.025, 0.0001>
  pigment
  { gradient x color_map
    { [0.3 rgb 0 transmit 0.6] [0.3 rgbt 1]
      [0.7 rgbt 1] [0.7 rgb 0 transmit 0.6]
    }
  }
}

#macro Show_minimal (Obj, Name)
  union
  { intersection
    { object { Obj }
      box { -3, 3 * z }
      texture { t_Special }
     // This translation is a fudge for the purpose of illustration *only*,
     // to better show the extent of the object being demonstrated.  (Without
     // the translation, there is a coincident surface.)
      translate -RE_ABIT * z
    }
    RE_Box_x_up (<-4, -4, -2>, <3, -1, 2>, 1, no)
    RE_Box_y_right (<-4, -2, -2>, <-1, 2, 2>, 1, no)
    object
    { Dashed_line
      scale <0.35, 1, 1> translate <-4, -2, -2 - 2 * RE_ABIT>
    }
    object
    { Dashed_line
      scale <0.35, 1, 1> rotate -90 * z translate <-2, 2, -2 - 2 * RE_ABIT>
    }
    Sticker (Name, "", <-0.5, -3.4, -2>, 0.6, 0)
    translate 0.5 * x
    scale 0.75
    translate y
  }
#end

#macro Show_sect (Obj, Size)
  #local Fit = 3 / (Size + 1);
  union
  { difference
    { object { Obj }
      box { -3 * z, Size }
    }
    intersection
    { object { Obj }
      box { -3 * z, Size }
      translate <1.25, 0.25, 1>
    }
    scale Fit
    translate (Fit * Size - 2) * y
  }
#end

//--------------------------------------

#switch (Test)

  #case (1)
    #declare V_ORIGIN = <-0.8, -0.2, 0.5>;
    #declare rBLOB = 0.8;
    #declare Sample = union
    { difference
      { box { -2, 2 }
        box { V_ORIGIN, <2, 2, -2> * RE_MORE }
      }
      object { RE_Corner_join (rBLOB) rotate 90 * y translate V_ORIGIN }
      rotate 30 * y
      translate z
    }
    #declare Caption = "RE_Corner_join"
    #break

  #case (2)
    #declare RPOST = 0.7;
    #declare rBLOB = 0.4;
    #declare Sample = union
    { box { -2, <2, -1, 2> }
      cylinder { -y, 2 * y, RPOST translate -0.5 * x }
      object { RE_Round_join (RPOST, rBLOB) translate <-0.5, -1, 0> }
      object { RE_Round_join (RPOST, rBLOB) translate <1.75, 0.5, 0> }
      Sticker ("RE_Round_join", "", <0, -1.5, -2>, 0.45, 0)
    }
    #break

  #case (3)
    #declare RHOLLOW = 1.25;
    #declare rBLOB = 0.4;
    #declare Sample = union
    { intersection
      { union
        { difference
          { box { -<1.75, 0, 2>, <1.75, 3, 2> }
            cylinder { -0.1 * y, 3.1 * y, RHOLLOW }
          }
          RE_Round_inside_join (RHOLLOW, rBLOB)
        }
        plane { -z, 0 }
        translate <-1.25, -1, 0>
      }
      box { -<3, 2, 2>, <3, -1, 2> }
      object { RE_Round_inside_join (RHOLLOW, rBLOB) translate <2.5, 0.5, 0> }
      Sticker ("RE_Round_inside_join", "", <0, -1.5, -2>, 0.45, 0)
    }
    #break

  #case (4)
    #declare V_ORIGIN = <-0.8, -0.2, 0.5>;
    #declare rBLOB = 0.8;
    #declare Sample = union
    { union
      { difference
        { box { -2, 2 }
          box { V_ORIGIN, <2, 2, -2> * RE_MORE }
        }
        RE_Straight_join_x (V_ORIGIN, 2, rBLOB, -90)
        RE_Straight_join_y (V_ORIGIN, 2, rBLOB, 90)
        RE_Straight_join_z (V_ORIGIN, -2, rBLOB, 0)
        rotate 30 * y
        translate z
      }
      RE_Straight_join_x (-2, 2, rBLOB, -90)
    }
    #declare Caption = "RE_Straight_join_*"
    #break

  #case (5)
    #declare Sample = object
    { RE_Elliptorus_mesh (2.4, 1.4, 0.6, 40, 16)
      rotate 90 * x
    }
    #declare Caption = "RE_Elliptorus_mesh"
    #break

  #case (6)
    #declare R = 0.4;
    #declare Near = -1;
    #declare Far = 3;
    #declare Side = union
    { RE_Box_y_near (<1, -2, Near>, <3, 0, Far>, R, no)
      intersection
      { union
        { cylinder { Near * z, (Near + R) * z, 1 scale <2 - 2 * R, 2 - R, 1> }
          cylinder { (Near + R) * z, Far * z, 1 scale <2 - R, 2, 1> }
        }
        plane { -x, 0 }
        translate <1 + R, 0, 0>
      }
    }
    #declare Edges = union
    { object
      { RE_Elliptorus_octant (2 - 2 * R, 2 - R, R, 16, 16)
        rotate -90 * x translate <1 + R, 0, Near + R>
      }
      object
      { RE_Elliptorus_octant (1 + R, 1, R, 16, 16)
        rotate -90 * x translate <0, 0, Near + R>
      }
    }
    #declare Sample = union
    { object { Side }
      object { Side scale <-1, 1, 1> }
      difference
      { box { <-1 - R, 0, Near>, <1 + R, 2 - R, Far> }
        cylinder { (Near - RE_ABIT) * z, (Near + R) * z, 1 scale <1 + R, 1, 1> }
        cylinder { Near * z, (Far + RE_ABIT) * z, 1 scale <1, 1 - R, 1> }
      }
      box { <-1 - R, 2 - R, Near + R>, <1 + R, 2, Far> }
      cylinder { <-1 - R, 2 - R, Near + R>, <1 + R, 2 - R, Near + R>, R }
      object { Edges texture { t_Special } }
      object { Edges scale <-1, 1, 1> }
      object
      { Edges
        translate <0, 0, - Near - R>
        rotate 90 * x
        translate <0, -0.75, -4>
        texture { t_Special }
      }
      Sticker ("RE_Elliptorus_octant", "", <0, 1.2, Near>, 0.375, 0)
    }
    #break

  #case (7)
    #declare R = 0.4;
    #declare AMP = 2;
    #declare WLEN = 6;
    #declare H = 8 * AMP / pow (WLEN, 2);
    #declare Side = WLEN/4;
    #declare Bob = AMP/2;
    #declare Sample = union
    { intersection
      { RE_Parabolic_torus (H, R)
        box { <-Side, -R, -R>, <Side, Bob + R, R> }
        translate <Side, Bob, 0>
      }
      intersection
      { RE_Parabolic_torus (H, R)
        box { <-Side, 0, -R>, <Side, Bob + R, R> }
        translate <Side, -Bob, 0>
      }
      intersection
      { quadric { -H * x, 0, y, 0 }
        box { <-Side, -2, -R>, <Side, Bob, R> }
        translate <Side, -Bob, 0>
      }
      intersection
      { RE_Parabolic_torus (-H, R)
        box { <-Side, -Bob, -R>, <Side, R, R> }
        translate <-Side, Bob, 0>
      }
      intersection
      { quadric { H * x, 0, y, 0 }
        box { <-Side, -2 - Bob, -R>, <Side, 0, R> }
        translate <-Side, Bob, 0>
      }
      Sticker ("RE_Parabolic_torus", "", <0, -1.4, -R>, 0.5, 0)
    }
    #break

  #case (8)
    #declare Sample = RE_Cylinder (2*y, -2*y, 2, 0.4, no)
    #declare Caption = "RE_Cylinder"
    #break

  #case (9)
    #declare Sample = RE_Cylinder_end (-2*y, 2*y, 2, 0.4, no)
    #declare Caption = "RE_Cylinder_end"
    #break

  #case (10)
    #declare Sample = Show_sect (RE_Hole (-2 * z, 2 * z, 3, 1, 1, no), 3)
    #declare Caption = "RE_Hole"
    #break

  #case (11)
    #declare Sample = Show_sect (RE_Hole_end (-2 * z, 2 * z, 3, 1, 1, no), 3)
    #declare Caption = "RE_Hole_end"
    #break

  #case (12)
    #declare Sample = Show_minimal
      (RE_Hole_minimal (-2 * z, 2 * z, 1, 1, no), "RE_Hole_minimal")
    #break

  #case (13)
    #declare Sample = Show_minimal
      (RE_Hole_end_minimal (-2 * z, 2 * z, 1, 1, no), "RE_Hole_end_minimal")
    #break

  #case (14)
    #declare Sample = Show_sect (RE_Washer (-2 * z, 2 * z, 4, 1, 1, no), 4)
    #declare Caption = "RE_Washer"
    #break

  #case (15)
    #declare Sample = Show_sect (RE_Washer_end (-2 * z, 2 * z, 4, 1, 1, no), 4)
    #declare Caption = "RE_Washer_end"
    #break

  #case (16)
    #declare Sample = union
    { RE_Box (-2, 2, 0.6, no)
      Sticker ("RE_Box", "", -2*z, 0.45, 0)
    }
    #break

  #case (17)
    #declare Sample = union
    { object { Axes }
      RE_Box_x (<-2, -2, -1>, <2, 0, 1>, 0.6, no)
      RE_Box_y (<0, 0, -1>, <3, 2, 1>, 0.6, no)
      RE_Box_z (<-3, 0, -1>, <0, 2, 1>, 0.6, no)
      Sticker ("RE_Box_x", "", <0.25, -1, -1>, 0.425, 0)
      Sticker ("RE_Box_y", "", <1.5, 1, -1>, 0.425, 0)
      Sticker ("RE_Box_z", "", <-1.5, 1, -1>, 0.425, 0)
    }
    #break

  #case (18)
    #declare Sample = union
    { object { Axes }
      RE_Box_left (<-2.5, 0, -1>, <2.5, 2, 1>, 0.6, no)
      RE_Box_right (<-2.5, -2, -1>, <2.5, 0, 1>, 0.6, no)
      Sticker ("RE_Box_left", "", <-0.6, 1, -1>, 0.45, 0)
      Sticker ("RE_Box_right", "", <0.5, -1, -1>, 0.45, 0)
    }
    #break

  #case (19)
    #declare Sample = union
    { object { Axes }
      RE_Box_up (<-2.5, -2, -1>, <0, 2, 1>, 0.6, no)
      RE_Box_down (<0, -2, -1>, <2.5, 2, 1>, 0.6, no)
      object { Sticker ("RE_Box_up", "", <0.25, 1.25, -1>, 0.45, 0) rotate 90 * z }
      object { Sticker ("RE_Box_down", "", <0, 1.25, -1>, 0.45, 0) rotate -90 * z }
    }
    #break

  #case (20)
    #declare Sample = union
    { object { Axes }
      RE_Box_near (<-1, -2, -2>, <1, 0, 2>, 0.6, no)
      RE_Box_far (<-1, 0, -2>, <1, 2, 2>, 0.6, no)
      object { Sticker ("RE_Box_near", "", -<0.2, 1, 1>, 0.45, 0) rotate -90 * y }
      object { Sticker ("RE_Box_far", "", <0.2, 1, -1>, 0.45, 0) rotate -90 * y }
      rotate 45 * y
    }
    #break

  #case (21)
    #declare Sample = union
    { object { Axes }
      RE_Box_x_near (<-1, 0.05, -2.95>, <1, 2, -0.05>, 0.6, no)
      RE_Box_x_up (<-1, 0.05, 0.05>, <1, 2, 2.95>, 0.6, no)
      RE_Box_x_far (<-1, -2, 0.05>, <1, -0.05, 2.95>, 0.6, no)
      RE_Box_x_down (<-1, -2, -2.95>, <1, -0.05, -0.05>, 0.6, no)
      union
      { Sticker ("RE_Box_x_near", "", <-1.3, 0.75, -1>, 0.4, 0)
        Sticker ("RE_Box_x_up", "", <1.5, 1.25, -1>, 0.4, 0)
        Sticker ("RE_Box_x_far", "", <1.5, -1.25, -1>, 0.4, 0)
        Sticker ("RE_Box_x_down", "", <-1.3, -0.75, -1>, 0.4, 0)
        rotate -90 * y
      }
      rotate 45 * y
    }
    #break

  #case (22)
    #declare c_Ink = rgb 1;
    #declare x_Tilt = transform { rotate -25 * x }
    #declare v_Tilted = vtransform (<0, 2, 1>, transform { x_Tilt });
    #declare Sample = union
    { object { Axes }
      RE_Box_y_right (<-3, -2, -1>, <-1.56, 2, 1>, 0.5, no)
      RE_Box_y_near (<-1.48, -2, -1>, <-0.04, 2, 1>, 0.5, no)
      RE_Box_y_far (<0.04, -2, -1>, <1.48, 2, 1>, 0.5, no)
      RE_Box_y_left (<1.56, -2, -1>, <3, 2, 1>, 0.5, no)
      #declare f_Save = finish {}
      #default { finish { ambient 0.4 } }
      union
      { Sticker ("RE_Box_y_right", s_Normal_font, <0, 2.28, -1>, 0.5, c_Ink)
        Sticker ("RE_Box_y_near", s_Normal_font, <0, 0.76, -1>, 0.5, c_Ink)
        Sticker ("RE_Box_y_far", s_Normal_font, <0, -0.76, -1>, 0.5, c_Ink)
        Sticker ("RE_Box_y_left", s_Normal_font, <0, -2.28, -1>, 0.5, c_Ink)
        rotate 90 * z
      }
      #default { finish { f_Save } }
      transform { x_Tilt }
      translate (v_Tilted.y - 2) * y
    }
    #break

  #case (23)
    #declare Sample = union
    { object { Axes }
      RE_Box_z_up (<-2.95, 0.05, -1>, <-0.05, 2, 1>, 0.6, no)
      RE_Box_z_right (<0.05, 0.05, -1>, <2.95, 2, 1>, 0.6, no)
      RE_Box_z_down (<0.05, -2, -1>, <2.95, -0.05, 1>, 0.6, no)
      RE_Box_z_left (<-2.95, -2, -1>, <-0.05, -0.05, 1>, 0.6, no)
      Sticker ("RE_Box_z_up", "", <-1.5, 1.25, -1>, 0.4, 0)
      Sticker ("RE_Box_z_right", "", <1.3, 0.75, -1>, 0.4, 0)
      Sticker ("RE_Box_z_down", "", <1.3, -1.25, -1>, 0.4, 0)
      Sticker ("RE_Box_z_left", "", <-1.5, -0.75, -1>, 0.4, 0)
    }
    #break

  #case (24)
    #declare Sample = isosurface
    { function
      { 1 - RE_fn_Blob (abs(x) + abs(z) - 1, 0.3)
          - RE_fn_Blob (f_sphere (0, y, z, 0.8), 0.2)
      }
      max_gradient 4 / 0.2
      contained_by { box { -<2.5, 2, 1>, <2.5, 2, 1> } }
    }
    #declare Caption = "RE_fn_Blob"
    #break

  #case (25)
    #declare Sample = isosurface
    { function
      { 1 - sqrt
        ( RE_fn_Blob2 (abs(x) + abs(z) - 1, 0.3)
        + RE_fn_Blob2 (f_sphere (0, y, z, 0.8), 0.2)
        )
      }
      max_gradient 1.3 / 0.2
      contained_by { box { -<2.5, 2, 1>, <2.5, 2, 1> } }
    }
    #declare Caption = "RE_fn_Blob2"
    #break

  #case (26)
    #declare R = 0.75;
    #declare RIN = 1;
    #declare ROUT = 2.5;
    #declare EDGE = 0.3;
    #declare TOP = 2;
    #declare Side = union
    { cylinder { <RIN + R, TOP, 0>, <RIN + R, 0, 0>, R }
      box { <RIN + R, -RIN, -R>, <ROUT, TOP, R> }
      RE_Straight_join_x (<RIN + R, -RIN, R>, ROUT, EDGE, 0)
      RE_Straight_join_x (<RIN + R, -RIN, -R>, ROUT, EDGE, -90)
    }
    #declare Join = isosurface
    { function
      { 1 - sqrt
        ( max //check for negative sqrt operand when using a negative component
          ( RE_fn_Blob2 (RE_fn_Hole (x, z, y, RIN + R, R), EDGE)
          + RE_fn_Blob2 (y + RIN, EDGE)
          - RE_fn_Blob2 (f_sphere (x, y + RIN + R, z, R), EDGE),
            0
          )
        )
      }
      max_gradient 1.42/EDGE
     // For a faster render, confine the isosurface to a small patch, and let
     // primitives handle the rest:
      contained_by
      { box { -<0, RIN + 0.001, R + EDGE>, <RIN + R, EDGE - RIN, R + EDGE> }
      }
    }
    #declare Sample = union
    { box { -ROUT, <ROUT, -RIN, ROUT> }
      intersection
      { RE_Hole_minimal (-R * z, R * z, RIN, R, no)
        plane { y, 0 }
      }
      object { Join }
      object
      { Join
        texture { t_Special }
        scale <-1, 1, 1>
       // This translation is a fudge for the purpose of illustration *only*,
       // to better show the extent of the isosurface patch.  (Without the
       // translation, there is a coincident surface with the box, and the
       // isosurface loses.)
        translate 0.001 * y
      }
      object { Side }
      object { Side scale <-1, 1, 1> }
      Sticker ("RE_fn_Hole", "", <0, -1.45, -ROUT>, 0.45, 0)
      Sticker ("with RE_fn_Blob2", "", <0, -2, -ROUT>, 0.375, 0)
      translate (ROUT - 2) * y
    }
    #break

  #case (27)
    #declare R = 0.4;
    #declare AMP = 2;
    #declare WLEN = 6;
    #declare H = 8 * AMP / pow (WLEN, 2);
    #declare Side = WLEN/4;
    #declare Bob = AMP/2;
    #declare Sample = union
    { isosurface
      { function { RE_fn_Parabolic_torus (x - Side, y - Bob, z, H, R) }
        max_gradient 1.7
        contained_by { box { <0, Bob - R, -R>, <WLEN/2, 2*Bob + R, R> } }
      }
      isosurface
      { function { RE_fn_Parabolic_torus (x - Side, y + Bob, z, H, R) }
        max_gradient 1.7
        contained_by { box { <0, -Bob, -R>, <WLEN/2, R, R> } }
      }
      isosurface
      { function { RE_fn_Parabolic_torus (x + Side, y - Bob, z, -H, R) }
        max_gradient 1.7
        contained_by { box { <-WLEN/2, 0, -R>, <0, R + Bob, R> } }
      }
      intersection
      { quadric { -H * x, 0, y, 0 }
        box { <-Side, -2, -R>, <Side, Bob, R> }
        translate <Side, -Bob, 0>
      }
      intersection
      { quadric { H * x, 0, y, 0 }
        box { <-Side, -2 - Bob, -R>, <Side, 0, R> }
        translate <-Side, Bob, 0>
      }
      Sticker ("RE_fn_Parabolic_torus", "", <0, -1.4, -R>, 0.5, 0)
    }
    #break

  #case (28)
    #declare R = 0.4;
    #declare ROUT = 2.75;
    #declare BLOBBY = 0.6;
    #declare Effect =
      R + sqrt (pow (BLOBBY + R, 2) - pow (BLOBBY + R - BLOBBY/sqrt(2), 2));
    #declare End_blob = isosurface
    { function
      { 1 - sqrt
        ( max //check for negative sqrt operand when using a negative component
          ( RE_fn_Blob2 (RE_fn_Wheel (x, z, y, ROUT - R, R), BLOBBY)
          + RE_fn_Blob2 (RE_fn_Wheel (x, y, z, ROUT - R, R), BLOBBY)
          - RE_fn_Blob2 (f_sphere (x + R - ROUT, y, z, R), BLOBBY),
            0
          )
        )
      }
      max_gradient 1.42 / BLOBBY
     // For a faster render, confine the isosurface to a small patch, and let
     // primitives handle the rest:
      contained_by
      { box { <ROUT - Effect, 0, -R - BLOBBY>, <ROUT, R + BLOBBY, R + BLOBBY> }
      }
    }
    #declare Sample = union
    { RE_Cylinder (R*y, (ROUT - 4) * y, ROUT, R, no)
      RE_Cylinder (-R*z, R*z, ROUT, R, no)
      RE_Straight_join_x (<ROUT - Effect, R, -R>, Effect - ROUT, BLOBBY, -90)
      RE_Straight_join_x (<ROUT - Effect, R, R>, Effect - ROUT, BLOBBY, 0)
      object
      { End_blob
        texture { t_Special }
       // This translation is a fudge for the purpose of illustration *only*,
       // to better show the extent of the isosurface patch.  (Without the
       // translation, there is a coincident surface with the RE_Cylinders, and
       // the isosurface loses.)
        translate 0.001 * x
      }
      object { End_blob rotate 180 * y }
      Sticker ("RE_fn_Wheel", "", <0, 1.7, -R>, 0.475, 0)
      Sticker ("with RE_fn_Blob2", "", <0, 1.2, -R>, 0.4, 0)
      translate <0, 2 - ROUT, 0>
    }
    #break

  #case (29)
    #declare R = 0.4;
    #declare RBlob = RE_fn_Blob_surface_radius (1.5, 4);
    #declare Sample = union
    { blob
      { sphere { 0, 1.5, 4 }
        cylinder { 0, <1.5, 2.5, 0>, 0.8, 4 }
      }
      difference
      { RE_Washer_end (R * y, -RBlob * y, 2, RBlob, R, no)
        box { <0, R * RE_MORE, 0>, <3, -3, -3> }
      }
      RE_Cylinder_end (-2 * y, -RBlob * y, 2, R, no)
    }
    #declare Caption = "RE_fn_Blob_surface_radius"
    #break

  #case (30)
    #declare RMAJOR = 1.3;
    #declare rMINOR = 0.7;
    #declare v_Signage = transform { rotate <Debug_boom, Debug_dolly, 0> }
    #declare Sample = union
    { intersection
      { torus { RMAJOR, rMINOR rotate 90 * x }
        plane { y, 0 }
      }
      blob //radius of spheres to match minor radius of torus
      { sphere { -RMAJOR * x, RE_fn_Blob_field_radius (rMINOR, 2), 2 }
        sphere { RMAJOR * x, 1.2, RE_fn_Blob_strength (rMINOR, 1.2) }
        cylinder { <-0.5, 1.5, 0>, <0.5, 1.5, 0>, 1.3, 2.3 }
      }
      union
      { Sticker ("RE_fn_Blob_field_radius", "", <-1.0, 2.25, -2>, 0.425, 0)
        Sticker ("RE_fn_Blob_strength", "", <1.3, 1.45, -2>, 0.425, 0)
        transform { v_Signage }
      }
      union
      { cone
        { <-RMAJOR, 0, -rMINOR>, 0.01,
          vtransform (<-2, 1.9, -2>, transform { v_Signage }), 0.05
        }
        cone
        { <RMAJOR, 0, -rMINOR>, 0.01,
          vtransform (<1.8, 1.1, -2>, transform { v_Signage }), 0.05
        }
        pigment { rgb 0 }
        no_shadow
        no_reflection
      }
    }
    #break

 // A few boundary cases (shhhh!!!):
 //cmd: declare=MaxG=1 +kff99 +sf97
  #case (97)
    #declare Sample = isosurface
    { function { RE_fn_Wheel (x, y, z, 0, 2) }
      contained_by { sphere { 0, 3 } }
    }
    #break
  #case (98)
    #declare Sample = RE_Box (2, -2, 2, no)
    #break
  #case (99)
    #declare Sample = RE_Cylinder (sqrt(4/3), -sqrt(4/3), 2, 2, no)
    #break

 // The main showpiece illustration:
  #else
    #declare Sample = union
    { object { Platform }
      union
      { object { Povument }
        object { Holder }
        scale 0.4
        translate H3 * y
      }
    }

#end

//================================= DISPLAY ====================================

object
{ Sample
  texture { #if (MaxG) t_Max_gradient_test #else t_Sample #end }
  //Actually, just turning on radiosity does a better job of finding the
  //max gradient, but chrome is still fun.
}

#if (strcmp (Caption, ""))
  #declare Word = Sticker (Caption, "", 0, 0.375, 0)
  union
  { object { Word }
    box
    { min_extent (Word), max_extent (Word)
      scale <1.1, 1.4, 1>
      translate max_extent (Word) * z
      pigment { rgb 1 transmit 0.7 }
      finish { ambient 0.4 }
    }
    no_shadow
    no_reflection
    translate <0, -0.1, -4> rotate <0, Debug_dolly, 0>
  }
#end

// end of roundedge.pov
