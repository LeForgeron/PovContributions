// Title:        MakeRoom demo scene
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   July 3, 2008
// Last updated: July 11, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
// +W800 +H600 +AM2 +A0.03
//
#version 3.61;

#declare Use_Radiosity = yes;

#if(Use_Radiosity)
  #default { finish { ambient 0 diffuse 1 } }
#end

#include "colors.inc"
#include "makeroom.inc"
#include "metals.inc"
#include "rad_def.inc"

#declare Mode = 1;
#declare Radiosity_Pre = no;

#declare Use_Area = yes;
#declare Use_Glass = yes;
#declare Use_Textures = yes;
#declare Use_Blur = no;
#declare Use_HQ_Blur = yes;

#declare Load_Radiosity = yes;
#declare Save_Radiosity = yes;

#declare Radiosity_File = concat("makeroom-", str(Mode, 0, 0), ".rad");

#switch(Mode)
  #case(1)
    #declare Use_Moon = no;
    #declare Use_Daylight = yes;
    #declare Lamp_On = no;
    #declare Night_Light_On = no;
  #break
  
  #case(2)
    #declare Use_Moon = yes;
    #declare Use_Daylight = no;
    #declare Lamp_On = yes;
    #declare Night_Light_On = no;
  #break
  
  #case(3)
    #declare Use_Moon = yes;
    #declare Use_Daylight = no;
    #declare Lamp_On = no;
    #declare Night_Light_On = yes;
  #break
#end

global_settings {
  assumed_gamma 1.0
  max_trace_level 6
  #if(Use_Radiosity)
    radiosity {
      #if(Radiosity_Pre)
        Rad_Settings(Radiosity_Pre, no, no)
      #else
        pretrace_start 64/image_width
        pretrace_end   1/image_width
        gray_threshold 0
        brightness 1
        adc_bailout 0.01/3
        normal no
        media no

        #switch(Mode)
          #case(1)
            count 800
            nearest_count 17
            error_bound 0.6
            recursion_limit 4
            low_error_factor 0.5
            minimum_reuse 0.015
          #break
            
          // Radiosity settings for mode 2 and 3 are not well tested 
          // and probably need adjustment.
          #case(2)
            count 700
            nearest_count 17
            error_bound 0.3
            recursion_limit 4
            low_error_factor 0.5
            minimum_reuse 0.01
          #break
            
          #case(3)
            count 700
            nearest_count 17
            error_bound 0.6
            recursion_limit 4
            low_error_factor 0.5
            minimum_reuse 0.014
          #break
        #end
        
        #if(Load_Radiosity & file_exists(Radiosity_File))
          pretrace_start 1
          pretrace_end 1
          load_file Radiosity_File
        #else
          #if(Save_Radiosity)
            save_file Radiosity_File
          #end
        #end
        
      #end
    }
  #end
}

camera {
  location <15, 0, -65>
  up y 
  right x * image_width/image_height
  look_at 0
  #if(Use_Blur)
    aperture 0.008
    focal_point 0
    #if(Use_HQ_Blur)
      blur_samples 512
      confidence 0.96
      variance 1/100000
    #else
      blur_samples 100
      confidence 0.9
      variance 1/10000
    #end
  #end
}

#if(! Use_Radiosity)
  light_source { <10, 10, -49>, White }
#end

#declare Warm_Daylight = rgb <255, 231, 204>/255;
#declare Incandescent = rgb <255, 178, 91>/255;
#declare Candle_Flame = rgb <255, 130, 0>/255;
#declare Moonlight = rgb <255, 215, 166>/255;

#if(Use_Daylight)
  sphere {
    0, 10000
    inverse
    texture {
      pigment { Warm_Daylight }
      finish {
        ambient 4
        diffuse 0
      }
    }
  }
#end

#if(Use_Moon)
  light_source {
    z * 500, Moonlight * (Mode = 3 ? 3 : 1)
    #if(Use_Area)
      area_light
      x * 15, y * 15, 33, 33
      circular
      adaptive 2
      jitter
    #end
    fade_power 2
    fade_distance 50
    parallel
    point_at 0
    rotate <-45, 12, 0>
  }
#end

#declare Ceiling_T = 
  texture {
    pigment { 
      bozo
      color_map {
        [0 rgb <1.0000, 0.9290, 0.7370> ]
        [1 MR_AntiqueWhite]
      }
    }
  }
  
#declare Floor_T = 
  texture {
    pigment { rgb <0.6875, 0.8750,0.8984> }
  }

#declare MR_Ceiling_T = Ceiling_T;
#declare MR_Floor_T = Floor_T;

#declare MR_Doors      = array[1] { 1 };
#declare MR_Doors_Side = array[1] { -x };
#declare MR_Doors_Size = array[1] { <40, 70> };
#declare MR_Doors_Pos  = array[1] { z * 40 };

#declare MR_Windows      = array[5] { 4, 4, 4, 4, 4 };
#declare MR_Windows_Side = array[5] { z, z, x, x, x };
#declare MR_Windows_Size = array[5] { <30, 40>, <30, 40>, <30, 40>, <30, 40>, <30, 40> };
#declare MR_Windows_Pos  = array[5] { x * 20, x * -20, z * 50, z * 0, z * -50 };
#declare MR_Windows_Thickness = 1;
#declare MR_Windows_Use_Glass = Use_Glass;

#declare MR_Baseboard = yes;

#declare MR_Crown = yes;

#declare Room_1 = MakeRoom(<100, 80, 150>);

MR_Reset()

#declare MR_Ceiling_T = Ceiling_T;
#declare MR_Floor_T = Floor_T;

#declare MR_Doors      = array[1] { 1 };
#declare MR_Doors_Side = array[1] { z };
#declare MR_Doors_Size = array[1] { <40, 70> };
#declare MR_Doors_Align = yes;

#declare MR_Windows      = array[3] { 1, 1, 1 };
#declare MR_Windows_Side = array[3] { -x, -x, -x };
#declare MR_Windows_Size = array[3] { <50, 50>, <50, 50>,  <50, 50> };
#declare MR_Windows_Pos  = array[3] { z * -40, z * 10, z * 60 };
#declare MR_Windows_Thickness = 1;
#declare MR_Windows_Use_Glass = Use_Glass;

#declare MR_Baseboard = yes;

#declare MR_Crown = yes;

#declare Room_2 = MakeRoom(<50, 80, 200>);

#declare Lamp = 
  union {
    cone { 
      0, 5, y * 10, 3
      open
      double_illuminate
      pigment { White }
      finish {
        ambient 0
        diffuse 1
      }
    }
    #if(Lamp_On)
      light_source {
        y * 6, Incandescent * 4
        #if(Use_Area)
          area_light
          x * 2, y * 2, 33, 33
          adaptive 2
          circular
          orient
        #end
        fade_power 2
        fade_distance 4
      }
    #end
    union {
      cylinder { y * -4, y * 3, 0.5 }
      intersection {
        box { -0.75, 0.75 }
        sphere { 0, 1 }
        bounded_by {
          box { -0.75, 0.75 }
        }
        translate y * -5
      }
      cylinder { y * -5, <0, -5, 7>, 0.5 }
      cone { <0, -5, 7>, 0.5, <0, -5, 8>, 2 }
      texture {
        pigment { P_Brass3 }
        finish {
          ambient 0
          diffuse 0.05
          #if(Use_Textures)
            specular 1.9
            roughness 0.005272
            brilliance 3
            metallic
            reflection {
              0.475, 0.95
              metallic
            }
            conserve_energy
          #end
        }
      }
    }
    translate <0, 5, -8>
  }
  
#declare Night_Light =
  union {
    intersection {
      sphere {
        0, 5
        scale <0.5, 1, 0.5>
      }
      box { <-2.5, 0, -2.5>, <2.5, 5, 0> }
      bounded_by {
        box { <-2.5, 0, -2.5>, <2.5, 5, 0> }
      }
      double_illuminate
      texture {
        pigment { White }
        finish {
          ambient 0
          diffuse 1
          #if(Use_Textures)
            specular 0.5
            roughness 0.05
            reflection {
              0, 0.2
              fresnel
            }
            conserve_energy
          #end
        }
      }
    }
    #if(Night_Light_On)
      light_source {
        <0, 2, -1>, Incandescent * 3
        fade_power 2
        fade_distance 2
      }
    #end
    box { <-1, -2.5, -2>, x }
    cylinder { y * -1.25, <0, -1.25, 0.5>, 1 }
    texture {
      pigment { rgb <0.9610, 0.9060, 0.6350> }
      #if(Use_Textures)
        finish {
          specular 0.75
          roughness 0.04
          reflection {
            0, 0.3
            fresnel
          }
          conserve_energy
        }
      #end
    }
    interior {
      ior 1.51
    }
    translate <0, 1.25, -0.5>
  }
  
sphere {
  0, 11000
  inverse
  texture {
    pigment { Black }
    finish {
      ambient 0
      diffuse 0
    }
  }
}

object { Room_1 }  

object {
  Room_2
  rotate y * 90
  translate <-155, 0, 40>
}

object {
  Lamp
  rotate y * -90
  translate x * -50
}
  
object {
  Night_Light
  rotate y * -90
  translate <-50, -32, 10>
}

  

