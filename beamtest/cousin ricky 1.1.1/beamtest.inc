/* beamtest.inc version 1.1.1
 * Persistence of Vision Raytracer include file
 * POV-Ray Object Collection
 *
 * Test bed for refraction and reflection of light.
 * Based on:
 *   From: Warp
 *   Subject: Re: Parabolic mirror 2
 *   Date: 17 May 2005 20:34:12
 *   Message: <428a5544@news.povray.org>
 *   Newsgroups: povray.binaries.images
 *
 * Copyright 2008 - 2012 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 * n/a    21-nov-2007  Created.
 * 1.0    30-jul-2008  Adapted for the POV-Ray object collection.
 * 1.1    01-sep-2008  Local variables are renamed to avoid potential problems
 *                     with POV-Ray's odd scoping rules.
 *        29-jun-2012  #version is changed to 3.5, then reverted to 3.6 after
 *                     some freakishly odd results with POV-Ray 3.5.
 * 1.1.1  30-jun-2012  Demo scene is re-rendered using POV-Ray 3.7.0.RC6, to
 *                     show 3.7's improved dispersion.
 */
#ifndef (BEAMTEST_INC) #declare BEAMTEST_INC = version;
#version 3.6;

//----- Parameters -----
#ifndef (Beam_extinction) #declare Beam_extinction = 0; #end //0.001;
#ifndef (Beam_field_of_view) #declare Beam_field_of_view = 15; #end
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
#ifndef (Beam_image_depth) #declare Beam_image_depth = Beam_radius * 2.01; #end

#local BEAM_EXTRA1 = 2;
#local Beam_zCam = -Beam_image_width / (2 * tan (radians (Beam_field_of_view/2)));
#local Beam_wView = Beam_image_width * (1 - Beam_image_depth / (2 * Beam_zCam));

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
{ location Beam_zCam * z
  right x
  up y * image_height / image_width
  angle Beam_field_of_view
}

//----- medium for light beams -----

#declare Beam_media = media
{ scattering { 1, 1 extinction Beam_extinction }
  method 3
  intervals 1
  samples 3, 3
  aa_level 2
}

box
{ -0.5, 0.5 hollow
  scale <Beam_wView, Beam_wView * image_height / image_width, Beam_image_depth>
  pigment { rgbt 1 }
  finish { specular 0 reflection 0 }
  interior { media { Beam_media } }
  photons { pass_through collect off }
}

//================================== EXTRAS ====================================

#declare Beam_t_fixture = texture { finish { specular 1 metallic } }

#declare Beam_o_fixture = cylinder
{ -Beam_fixture_length/2 * x, Beam_fixture_length/2 * x, Beam_fixture_radius
  open hollow
  #if (!Beam_fixture_shadow)
    no_shadow
    photons { collect off pass_through }
  #end
}

light_source
{ <-1, 1, -1> * 1000 * Beam_image_width, rgb 1
  parallel point_at 0
  media_interaction off
  photons { reflection off refraction off  }
}

cylinder
{ -y, y, Beam_fixture_radius / 2
  scale <1, Beam_image_width * image_height / image_width * BEAM_EXTRA1, 1>
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
      cylinder radius Beam_radius * Beam_umbra falloff Beam_radius point_at x
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

#version BEAMTEST_INC;
#end
