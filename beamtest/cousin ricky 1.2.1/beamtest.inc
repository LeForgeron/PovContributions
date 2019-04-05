/* beamtest.inc version 1.2.1
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * A test bed for refraction and reflection of light.
 * Based on:
 *   From: Warp
 *   Subject: Re: Parabolic mirror 2
 *   Date: 17 May 2005 20:34:12
 *   Message: <428a5544@news.povray.org>
 *   Newsgroups: povray.binaries.images
 *
 * Copyright 2008 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 * n/a    2007-Nov-21  Created.
 * 1.0    2008-Jul-30  Adapted for the POV-Ray object collection.
 * 1.1    2008-Sep-01  Local variables are renamed to avoid potential problems
 *                     with POV-Ray's odd scoping rules.
 *        2012-Jun-29  #version is changed to 3.5, then reverted to 3.6 after
 *                     some freakishly odd results with POV-Ray 3.5.
 * 1.1.1  2012-Jun-30  The demo scene is re-rendered using POV-Ray 3.7.0.RC6,
 *                     to show 3.7's improved dispersion.
 *        2014-Jul-09  Orthographic camera option is added and made the default.
 *        2014-Jul-11  An image height parameter is added.
 *        2014-Jul-16  The environmental lighting is parameterized.
 * 1.2    2014-Nov-01  Debugged and uploaded.
 * 1.2.1  2019-Mar-24  View_POV_Include_Stack is utilized.
 */
#ifndef (BeamTest_Inc_Temp) #declare BeamTest_Inc_Temp = version;
#version 3.6;
#declare BEAMTEST_VERSION = 1.21;
#ifdef (View_POV_Include_Stack)
  #debug "#include \"beamtest.inc\" //version 1.2.1\n"
#end

//----- Parameters -----
#ifndef (Beam_c_lighting) #declare Beam_c_lighting = rgb 1; #end
#ifndef (Beam_extinction) #declare Beam_extinction = 0; #end //0.001;
#ifndef (Beam_field_of_view) #declare Beam_field_of_view = 0; #end
#ifndef (Beam_fixture_length) #declare Beam_fixture_length = 0.6; #end
#ifndef (Beam_fixture_radius) #declare Beam_fixture_radius = 0.1; #end
#ifndef (Beam_fixture_shadow) #declare Beam_fixture_shadow = yes; #end
#ifndef (Beam_fixture_x) #declare Beam_fixture_x = -5; #end
#ifndef (Beam_image_width) #declare Beam_image_width = 32/3; #end
#ifndef (Beam_max_trace) #declare Beam_max_trace = 15; #end
#ifndef (Beam_photons) #declare Beam_photons = 0.005; #end
#ifndef (Beam_photons_media) #declare Beam_photons_media = 200; #end
#ifndef (Beam_radius) #declare Beam_radius = 0.05; #end
#ifndef (Beam_umbra) #declare Beam_umbra = 0.5; #end
#ifndef (Beam_image_height)
  #declare Beam_image_height = Beam_image_width * image_height / image_width;
#end
#ifndef (Beam_image_depth) #declare Beam_image_depth = Beam_radius * 2.01; #end

#if (Beam_field_of_view = 0)
  #local Beam_zCam = -Beam_image_width; //arbitrary
  #local Beam_wView = Beam_image_width;
#else
  #local Beam_zCam = -Beam_image_width / (2 * tan (radians (Beam_field_of_view/2)));
  #local Beam_wView = Beam_image_width * (1 - Beam_image_depth / (2 * Beam_zCam));
#end

//=============================== ENVIRONMENT ==================================

global_settings
{ assumed_gamma 1
  max_trace_level Beam_max_trace
  #if (Beam_photons > 0)
    photons
    { #if (Beam_photons > 1) count Beam_photons #else spacing Beam_photons #end
      autostop 0
      media Beam_photons_media
    }
  #end
}

camera
{ #if (Beam_field_of_view = 0) orthographic #end
  location Beam_zCam * z
  right x * Beam_image_width
  up y * Beam_image_height
  #if (Beam_field_of_view != 0) angle Beam_field_of_view #end
}

//----- Medium to reveal the path of the light beams -----

#declare Beam_media = media
{ scattering { 1, 1 extinction Beam_extinction }
  method 3
  intervals 1
  samples 3, 3
  aa_level 2
}

box
{ -0.5, 0.5 hollow
  scale
  < Beam_wView,
    Beam_wView * Beam_image_height / Beam_image_width,
    Beam_image_depth
  >
  pigment { rgbt 1 }
  finish { specular 0 reflection 0 }
  interior { media { Beam_media } }
  photons { pass_through collect off }
}

//================================== EXTRAS ====================================

//----- Environmental lighting -----

light_source
{ <-1, 1, -1> * 1000 * Beam_image_width, color Beam_c_lighting
  parallel point_at 0
  media_interaction off
  photons { reflection off refraction off  }
}

//----- Totally cosmetic light fixtures -----

#declare Beam_t_fixture = texture { finish { specular 1 metallic } }

#declare Beam_o_fixture = cylinder
{ -Beam_fixture_length/2 * x, Beam_fixture_length/2 * x, Beam_fixture_radius
  open hollow
  #if (!Beam_fixture_shadow)
    no_shadow
    photons { collect off pass_through }
  #end
}

//----- Totally cosmetic pole on which to affix the light fixtures -----

cylinder
{ -y, y, Beam_fixture_radius / 2
  scale <1, Beam_image_height, 1>
  translate <Beam_fixture_x, 0, Beam_fixture_radius * 1.5>
  texture { Beam_t_fixture pigment { rgb 0.5 } }
}

//================================== TOOLS =====================================

#macro Beam_angled (Height, Color, Angle)
  union
  { object
    { Beam_o_fixture
      texture { Beam_t_fixture pigment { color Color transmit 0 filter 0 } }
    }
    light_source
    { 0, Color / (Beam_radius * 2)
      cylinder radius Beam_radius * Beam_umbra falloff Beam_radius
      parallel point_at x
    }
    rotate Angle * z
    translate <Beam_fixture_x, Height, 0>
  }
#end

#macro Beam_sloped (Height, Color, Slope)
  Beam_angled (Height, Color, degrees (atan2 (Slope, 1)))
#end

#macro Beam_targeted (Height, Color, Target)
  #local Beam_Rel_target = Target - <Beam_fixture_x, Height, 0>;
  Beam_angled (Height, Color, degrees (atan2 (Beam_Rel_target.y, Beam_Rel_target.x)))
#end

#version BeamTest_Inc_Temp;
#end
// end of beamtest.inc
