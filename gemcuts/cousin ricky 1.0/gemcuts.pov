/* gemcuts.pov version 1.0
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * A demonstration of the GemCuts module: a round brilliant diamond ring and an
 * emerald cut emerald ring.
 *
 * In order to speed up high quality renders, this scene file has provisions for
 * 2-pass radiosity.
 *
 * POV-Ray 3.6 2-pass render instructions:
 *   Step 1:
 *     Render at a reduced size with Declare=Pass=1 Declare=Quality=0 on the
 *     command line, without anti-aliasing.
 *   Step 2 (WITHOUT soft shadows or depth of field):
 *     Render at full size with Declare=Pass=2 Declare=Quality=2 on the command
 *     line, with anti-aliasing.
 *   Step 2 (WITH soft shadows and depth of field):
 *     Render at full size with Declare=Pass=2 Declare=Quality=3 on the command
 *     line, without anti-aliasing.
 *   Step 3:
 *     Delete the file gemcuts_tmp.rad, which was created by step 1.
 *
 *   The file gemcuts_36.ini has the necessary options.
 *
 * POV-Ray 3.7 2-pass render instructions:
 *   A parse warning will be issued to specify save_file/load_file as an option.
 *   Follow these steps to insure a proper render.
 *   Step 1:
 *     Render at a reduced size with Declare=Pass=1 Declare=Quality=0 +RFO on
 *     the command line, without anti-aliasing.  Also on the command line, use
 *     +RF"" to declare the name of a temporary working file.
 *   Step 2 (WITHOUT soft shadows or depth of field):
 *     Render at full size with Declare=Pass=2 Declare=Quality=2 +RFI on the
 *     command line, with anti-aliasing.  Also on the command line, use +RF""
 *     with the same filename declared in step 1.
 *   Step 2 (WITH soft shadows and depth of field):
 *     Render at full size with Declare=Pass=2 Declare=Quality=3 +RFI on the
 *     command line, with or without anti-aliasing.  Also on the command line,
 *     use +RF"" with the same filename declared in step 1.
 *   Step 3:
 *     Delete the temporary working file declared in the +RF"" option.
 *
 *   The file gemcuts_37.ini has the necessary options.
 *
 * Copyright 2018 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 *        2017-May-09  Started.
 * 1.0    2018-Feb-27  Uploaded.
 */
#version 3.6; // Note: POV-Ray 3.7 or later is strongly recommended.

// Render Quality:
//
// Quality           0        1               2              3
//                  ---      ---             ---            ---
// Area light       off      off             off            on
// Depth of Field   off      off             off            on
// Gem material     opaque   no dispersion   dispersion     dispersion
// Photons*         off      medium fine     fine           fine
// Radiosity*       off      low quality     high quality   high quality
//
// *If Pass = 1 or 2, then photons and radiosity are determined according to
// Pass, not Quality.
#ifndef (Quality) #declare Quality = 1; #end
#debug concat ("Quality = ", str (Quality, 0, -1), "\n")

// Radiosity Pass:
// The 2-pass radiosity option is included because single-pass radiosity is
// excruciatingly slow when Quality = 2 or 3.
//
// Pass = 0: single-pass radiosity (or no radiosity, if Quality = 0)
// Pass = 1: first pass of 2-pass radiosity
// Pass = 2: second pass of 2-pass radiosity
#ifndef (Pass) #declare Pass = 0; #end
#debug concat ("Pass = ", str (Pass, 0, -1), "\n")

// Camera view:
// 0: oblique; 1: level; 2: above; 3: rear
#ifndef (Cam) #declare Cam = 0; #end

// For predictable results, a default ambient/diffuse must be set before
// #including woods.inc:
#declare DIFFUSE = 0.6;
#default
{ finish { ambient (Pass = 0 & Quality = 0? 0.2: 0) * DIFFUSE diffuse DIFFUSE } }

#include "colors.inc" // required by woodmaps.inc 3.6
#include "consts.inc"
#include "woods.inc"
#include "gemcuts.inc"

//=============================== ENVIRONMENT ==================================
// POV unit = 1 centimeter

#declare Pixel = 1 / image_width;
// These values are declared here, because they must remain consistent for
// 2-pass radiosity.
#declare ERROR_BOUND = 0.5;
#declare RECURSION_LIMIT = 2;
#declare S_RAD_FILENAME = "gemcuts_tmp.rad"

global_settings
{ assumed_gamma 1
  max_trace_level (1 = Pass? 10: 50)

  #switch (Pass)

    #case (0)
      #switch (Quality)
        #case (1)
          photons { spacing 0.004 autostop 0 }
          radiosity
          { brightness 1.5
            count 100
            error_bound 0.8
            pretrace_start 0.08
            pretrace_end 0.01
            recursion_limit 1
          }
          #break
        #case (2)
        #case (3)
          photons { spacing 0.002 autostop 0 }
          radiosity
          { count 300
            error_bound ERROR_BOUND
            // pretrace arguments for full-size image
            pretrace_start Pixel * 64
            pretrace_end Pixel * 2
            recursion_limit RECURSION_LIMIT
          }
          #break
      #end // switch Quality
      #break

    #case (1)
      radiosity
      { count 300
        error_bound ERROR_BOUND
        // pretrace arguments for half-size image
        pretrace_start Pixel * 32
        pretrace_end Pixel
        recursion_limit RECURSION_LIMIT
        save_file S_RAD_FILENAME // See POV-Ray 3.7 2-pass render instructions.
      }
      #break

    #case (2)
      photons { spacing 0.002 autostop 0 }
      radiosity
      { always_sample off
        count 1
        error_bound ERROR_BOUND
        pretrace_start 1
        pretrace_end 1
        recursion_limit RECURSION_LIMIT
        load_file S_RAD_FILENAME // See POV-Ray 3.7 2-pass render instructions.
      }
      #break

  #end // switch Pass
}

#declare V_FOCAL = <-0.1, 0.35, -0.75>;
camera
{ #switch (Cam)
    #case (1) location <0, 0.35, -30> #break // level
    #case (2) location <0, 30, -1> #break // above
    #case (3) location <0, 15, 26> #break // rear
    #else location <0, 15, -26>
  #end
  look_at <0, 0.35, 0>
  right 4/3 * x
  angle (Cam = 2? 10: 6)
  #if (Quality = 3)
    aperture 1.35 // ~0.5 cm (A factor of ~2.7 works; no one knows why.)
    focal_point V_FOCAL
    blur_samples Hex_Blur3
  #end
}

#ifndef (Debug_focal) #declare Debug_focal = no; #end
#if (Debug_focal)
  union
  { sphere { 0, 0.04 pigment { red 1 } }
    cylinder { 0, -y, 0.02 pigment { blue 1 } }
    translate V_FOCAL
  }
#end

#declare V_LIGHT = <-150, 135, -150>;
#declare RLIGHT = 3;
light_source
{ V_LIGHT, rgb (1 + pow (vlength (V_LIGHT) / RLIGHT, 2)) / 2
  fade_power 2 fade_distance RLIGHT
  spotlight falloff 180 radius 120 point_at V_LIGHT - y
  #if (Quality = 3)
    #declare RES = 5;
   // See Area light idiosyncrasies in p.b.i for this formula:
    #declare Size = 2 * RLIGHT * (RES - 1) / RES;
    area_light Size * x, Size * z, RES, RES
    adaptive 0 circular orient jitter
  #end
}

box
{ -<180, 75, 180>, <180, 165, 180> hollow
  pigment { rgb 0.6 }
}

cylinder
{ -0.001 * y, -2.5 * y, 45
  texture
  { T_Wood3 translate x scale 5
    //T_Wood6 rotate -20 * x translate x
    //T_Wood12 scale 5
  }
}

//============================== BLING TEXTURES ================================

#declare ROUGHNESS = 0.0001;
// To accommodate POV-Ray 3.6 users, the specular albedo value is pre-computed
// here.  (The formula is in Parser::Parse_Finish() in parstxtr.cpp in the
// POV-Ray 3.7 source code.)
#declare SPECULAR_ALBEDO = 1250;

#declare f_Metal = finish
{ reflection { 1 metallic }
  diffuse 0
  ambient 0
  specular SPECULAR_ALBEDO metallic
  roughness ROUGHNESS
}

#declare t_Silver = texture
{ pigment { rgb <0.97, 0.96, 0.91> }
  finish { f_Metal }
}

#declare t_Gold = texture
{ pigment { rgb <0.99, 0.84, 0.34> }
  finish { f_Metal }
}

// I don't trust the values in consts.inc, and ior.inc is not
// available prior to POV-Ray 3.7, so values are declared here:
#switch (Quality)
  #case (1) // No dispersion:
    #declare Diamond_IOR = 2.417; // spectral line D
    #declare Emerald_IOR = 1.584; // green (IOR at D is 1.580)
    #break
  #case (2)
  #case (3) // IORs that correct for a bias in POV-Ray's dispersion algorithm:
    #declare Diamond_IOR = 2.430;
    #declare Emerald_IOR = 1.584;
    #break
#end
#declare Diamond_disp = 1.0184;
#declare Emerald_disp = 1.0089;
// Without finish-level Fresnel, an average highlight for the IOR must be
// estimated.  (With finish-level Fresnel, introduced in POV-Ray 3.7.1, this
// value would be exactly 1.)
#declare Diamond_hilite = 0.180;
#declare Emerald_hilite = 0.0614;

#switch (Quality)
  #case (1)
  #case (2)
  #case (3)
    #declare m_Diamond = material
    { texture
      { pigment { rgbf 1 }
        finish
        { reflection { 0 1 fresnel } conserve_energy
          specular SPECULAR_ALBEDO * Diamond_hilite
          roughness ROUGHNESS
        }
      }
      interior
      { ior Diamond_IOR
        #if (Quality != 1) dispersion Diamond_disp dispersion_samples 12 #end
      }
    }
    #declare m_Emerald = material
    { texture
      { pigment { rgbf 1 }
        finish
        { reflection { 0 1 fresnel } conserve_energy
          specular SPECULAR_ALBEDO * Emerald_hilite
          roughness ROUGHNESS
        }
      }
      interior
      { ior Emerald_IOR
        #if (Quality != 1) dispersion Emerald_disp #end
        fade_color rgb <0.70, 0.93, 0.85>
        fade_distance 0.05
        fade_power 1000
      }
    }
    #break

  #else
    #declare m_Diamond = material { texture { pigment { rgb 0.6 } } }
    #declare m_Emerald = material
    { texture { pigment { rgb <0.05, 0.30, 0.10> } }
    }

#end

//=============================== DEMO OBJECTS =================================

// Diamond magic numbers:
#declare DTABLE = 0.57;
#declare DGIRDLE = 0.03;
#declare DCULET = 0.015;
#declare DSCALE = 2/3; // diamond-to-shank scale factor
#declare YDCULET = 0.26; // height of the culet above the shank's inner surface
#declare V_DBASE = <0.65, 0.20, 0.65>;
#declare DDPRONG = 0.15;

// I have very little information on emerald cut angles; this is
// what I came up with after testing various angle combinations.
// (Still leaks light like a sieve.)
#declare EPAV1 = 52;
#declare EPAV2 = 46;
#declare EPAV3 = 40;
// Other emerald magic numbers:
#declare ETABLE = 0.65;
#declare ECORNER = 0.15;
#declare EASPECT = 1.5;
#declare EGIRDLE = 0.04;
#declare ECULET = 0.015;
#declare ESCALE = 0.5; // emerald-to-shank scale factor
#declare YEKEEL = 0.35; // height of the keel above the shank's inner surface
#declare V_EBASE = <1.05, 0.30, 1.05>;
#declare DEPRONG = 0.2;

// Shank magic numbers:
#declare RINNER = 1.0;
#declare ROUTER = 1.175;
#declare WIDTH = 0.35;
#declare REDGE = 0.05;
#declare SIDE = 0.14;

//------------- Object definitions ---------------

#declare Shank = object
{ Gem_Shank (RINNER, ROUTER, WIDTH, SIDE, REDGE, yes)
  rotate 90 * x
}

#declare Diamond_ring = union
{ #declare Stone = Gem_Round_brilliant
  ( DTABLE, GEM_AMERICAN_CROWN, GEM_AMERICAN_PAVILION, DGIRDLE,
    Gem_fn_Lakshmi (DTABLE), 0.78, DCULET
  )
  #declare hPavilion = Gem_fn_1Step_height (DCULET, GEM_AMERICAN_PAVILION);
  #declare Core = Gem_Setting_round_auto
  ( Stone, hPavilion, DGIRDLE, 0, GEM_HOLE, V_DBASE.y / 2 - YDCULET,
    V_DBASE, 4, DDPRONG, GEM_NONE, 0, 0
  )
  difference
  { object { Shank }
    object
    { Core
      translate -min_extent (Core) * y
      scale DSCALE * <1, 2, 1>
      translate (RINNER - 0.05) * y
    }
    texture { t_Gold }
    photons { target collect off reflection on }
  }
  union
  { object
    { Stone
      material { m_Diamond }
      photons { target collect off refraction on reflection on }
    }
    object
    { Gem_Setting_round_auto
      ( Stone, hPavilion, DGIRDLE, 0.0025, GEM_OPEN, V_DBASE.y / 2 - YDCULET,
        V_DBASE, 4, DDPRONG, GEM_CURVED, hPavilion - 0.18, 16
      )
      texture { t_Silver }
      photons { target collect off reflection on }
    }
    // Set the bottom of the setting at y = 0:
    translate YDCULET * y
    scale DSCALE
    // Carving an opening in the shank left sharp edges; using the Pythagorean
    // theorem makes the bridge flush with the shank's inner surface:
    translate sqrt (pow (RINNER, 2) - pow (max_extent (Core).x * DSCALE, 2)) * y
  }
}

#declare Emerald_ring = union
{ #declare Stone = Gem_Emerald_cut
  ( EASPECT, ETABLE, ECORNER, 48, 33, 18, EPAV1, EPAV2, EPAV3, 0, EGIRDLE,
    ECULET
  )
  #declare hPavilion = Gem_fn_3Step_height (ECULET, EPAV1, EPAV2, EPAV3);
  #declare aProng = degrees (atan2 (EASPECT - ECORNER, 1 - ECORNER));
  #declare Prongs = array[4] { aProng, 180 - aProng, 180 + aProng, -aProng }
  #declare Core = Gem_Setting_poly
  ( Stone, hPavilion, EGIRDLE, 0, GEM_HOLE, V_EBASE.y / 2 - YEKEEL,
    V_EBASE, Prongs, DEPRONG, GEM_NONE, 0, 0
  )
  difference
  { object { Shank }
    object
    { Core
      translate -min_extent (Core) * y
      scale ESCALE * <1, 2, 1>
      translate (RINNER - 0.05) * y
    }
    texture { t_Gold }
    photons { target collect off reflection on }
  }
  union
  { object
    { Stone
      material { m_Emerald }
      photons { target collect off refraction on reflection on }
    }
    object
    { Gem_Setting_poly
      ( Stone, hPavilion, EGIRDLE, 0.003, GEM_OPEN, V_EBASE.y / 2 - YEKEEL,
        V_EBASE, Prongs, DEPRONG, GEM_SEGMENTED, hPavilion - 0.25, 24
      )
      texture { t_Silver }
      photons { target collect off reflection on }
    }
    // Set the bottom of the setting at y = 0:
    translate YEKEEL * y
    scale ESCALE
    // Carving an opening in the shank left sharp edges; using the Pythagorean
    // theorem makes the bridge flush with the shank's inner surface:
    translate sqrt (pow (RINNER, 2) - pow (max_extent (Core).x * ESCALE, 2)) * y
  }
}

//-------------- Object Placement ----------------

// Rotates a ring about an outer rim of the shank (which has a circular cross
// section, given the Gem_Shank() arguments in this scene).  Assumes that the
// ring is oriented in the x-y plane, with the stone at the top.
#macro Lay (Ring, Tilt)
  object
  { Ring
    // Move the outer rim's center of curvature to the origin:
    translate <0, RINNER + SIDE - REDGE, REDGE - WIDTH/2>
    rotate Tilt * x
    // Move the surface of the rim to the origin:
    translate REDGE * y
  }
#end

object
{ Lay (Emerald_ring, 84.708)
  rotate 170 * y
  translate <-1.1, 0, 1.9>
}
object
{ Lay (Diamond_ring, 86.405)
  rotate -140 * y
  translate <2.1, 0, 1.0>
}

// end of gemcuts.pov
