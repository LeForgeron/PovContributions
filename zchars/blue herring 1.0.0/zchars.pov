// Title:        ZChars demo scene
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 27, 2008
// Last updated: July 15, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#declare Use_Radiosity = yes;

#if(Use_Radiosity)
  #default { finish { ambient 0 diffuse 1 } }
#end

#include "colors.inc"
#include "functions.inc"
#include "metals.inc"
#include "rad_def.inc"
#include "rand.inc"
#include "shapes.inc"
#include "transforms.inc"
#include "zchars.inc"
#include "zchars_demo.inc"
#include "zchars_text.inc"

#declare Use_Light = no;
#declare Use_Area = yes;
#declare Use_Blur = no;
#declare Use_HQ_Blur = no;  // very, very time consuming

#declare Radiosity_Pre = no;

#declare Save_Radiosity = no;
#declare Load_Radiosity = yes;

#declare Radiosity_File = "zchars.rad";

global_settings {
  assumed_gamma 1.0
  max_trace_level 6
  #if(Use_Radiosity)
    radiosity {
      #if(Radiosity_Pre)
        Rad_Settings(Radiosity_Pre, no, no)
        recursion_limit 3
      #else
        pretrace_start 64/image_width
        pretrace_end   1/image_width
        count 250
        nearest_count 7
        error_bound 0.4
        recursion_limit 3
        low_error_factor 0.5
        gray_threshold 0
        minimum_reuse 0.017
        brightness 1.0
        adc_bailout 0.01/3
        #if(Load_Radiosity & file_exists(Radiosity_File))
          pretrace_start 1
          pretrace_end 1
          load_file Radiosity_File
          always_sample no
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
  location z * -15
  //location <0, 8, -10>
  up y
  right x * image_width/image_height
  look_at 0
  #if(Use_Blur)
    aperture 0.01
    focal_point 0
    #if(Use_HQ_Blur)
      blur_samples 512
      confidence 0.98
      variance 0
    #else
      blur_samples 100
      confidence 0.9
      variance 1/10000
    #end
  #end
}

#declare Warm_Daylight = rgb <255, 231, 204>/255;
#declare Incandescent = rgb <255, 178, 91>/255;

#if(Use_Light)
  #declare Light =
    light_source {
      0, Incandescent * (Use_Radiosity ? 0.25 : 1)
      #if(Use_Area)
        area_light
        x * 30, y * 30, 33, 33
        adaptive 0
        circular
        orient
      #end
      fade_power 2
      fade_distance 40
    }
    
  light_source {
    Light
    translate <-50, 40, -40>
  }

  light_source {
    Light
    translate <10, 40, -40>
  }

  light_source {
    Light
    translate <-20, 40, -40>
  }
#end

sphere {
  0, 1
  inverse
  texture {
    pigment { Warm_Daylight * 5 }
    finish {
      ambient 1
      diffuse 0
    }
  }
  scale 10000
}

#declare Paper_C1 = rgb <1, 0.98, 0.95>;
#declare Paper_C2 = rgb <1, 0.96, 0.83>;
#declare Paper_C3 = rgb <0.77, 0.54, 0.33>;

#declare Blank_Paper_T =
  texture {
    pigment {
      granite
      color_map {
        [0    Paper_C1]
        [0.2  Paper_C1]
        [0.21 Paper_C2]
        [0.3  Paper_C2]
        [0.4  Paper_C1]
        [0.5  Paper_C1]
        [0.51 Paper_C3]
        [0.6  Paper_C3]
        [0.61 Paper_C2]
        [0.9  Paper_C2]
        [1    Paper_C3]
      }
    scale 0.5
    }
  }
  texture {
    pigment { Paper_C2 transmit 0.1 }
    finish {
      specular 0.25
      roughness 0.08
    }
    normal { 
      leopard 1 
      warp { turbulence 1.7 }
      scale 0.01 
    }
  }

#declare Ink_T =
  texture {
    pigment { Black }
    finish {
      specular 0.25
      roughness 0.1
    }
  }

#declare S = "All work and no POV make Jack a dull boy.";

#declare Txt =
  union {
    object { 
      ZC_Text("*", S, 1, <0, -0.2, 0>)
      translate y * 2
    }
    object { ZC_Text("Arial.ttf", S, 1, <0, -0.2, 0>) }
    object {
      ZC_Text("Times_New_Roman.ttf", S, 1, <0, -0.1, 0>)
      translate y * 4
    }
    rotate x * 90
  }

#declare Paper_T =
  texture {
    object {
      object {
        Txt
        Center_Trans(Txt, 1)
        scale <0.3, 10, 0.3>
        translate z * 2.5
      }
      texture { Blank_Paper_T }
      texture { Ink_T }
    }
  }
  
#declare Paper_F =
  function {
    abs(f_wrinkles(x * 4, y * 4, z * 4) * 0.2)
  }  

#declare Paper = 
  object {
    HF_Square(Paper_F, yes, no, <20, 20>, yes, "", <-4, 0, -5.5>, <4, 1, 5.5>)
    texture { Paper_T }
  }

#declare Fridge_Door_T =
  texture {
    pigment { White }
    finish {
      specular 0.8
      roughness 0.001
      metallic
      reflection {
        0, 0.25
        metallic
      }
      conserve_energy
    }
  }
  
#declare Fridge =
  union {
    union {
      Round_Box_Union(<-15, -4, 0>, <15, 20, 10>, 0.75)
      Round_Box_Union(<-15, -20, 0>, <15, -4, 10>, 0.75)
      texture { Fridge_Door_T }
    }
    union {
      object { Freezer_Handle }
      object { Fridge_Handle }
      rotate <-90, 0, 180>
      scale <1.5, 3, 1> 
      translate <-8.5, -4, 0.1>
    }
  }
  
#declare Magnet_T =
  texture {
    finish {
      specular 0.75
      roughness 0.02
      reflection {
        0, 0.2
        fresnel
      }
      conserve_energy
    }
    normal { bozo 0.2 }
  }
  
#macro Magnet(Obj, Color)
  object {
    Obj
    texture {
      Magnet_T
      pigment { Color }
    }
    interior {
      ior 1.46
    }
    Center_Trans(Obj, x + y)
    Align_Trans(Obj, z, <0, 0, 0>)
    translate z * -0.1
  }
#end

#declare Room =
  union {
    // Ceiling
    box {
      <-100, 95, -100>, <100, 100, 30>
      pigment { rgb <0.99, 0.99, 0.97> }
    }
    // Floor
    box {
      -100, <100, -95, 30>
      pigment { 
        checker Black White
        scale 10
      }
    }
    // Left Wall
    box { -100, <-95, 100, 30> }
    // Right wall
    box { <95, -100, -30>, <100, 100, 30> }
    box { <95, -100, -100>, <100, 0, -30> }
    box { <95, 75, -100>, <100, 100, -30> }
    box { <95, -100, -100>, <100, 100, -80> }
    // Back wall
    box { <-100, -100, 25>, <100, 100, 30> }
    // Front wall
    box { -100, <-88, 100, -95> }
    box { <-88, -100, -100>, <-63, 10, -95> }
    box { <-88, 40, -100>, <-63, 100, -95> }
    box { <-64, -100, -100>, <100, 100, -95> }
    // Counter
    union {
      box { <-60, -22, -95>, <60, -20, -65> }
      box { <-58, -95, -95>, <58, -22, -67> }
      pigment { DarkWood }
    }
    // Front window frame
    union {
      box { <-89, 9, -101>, <-62, 11, -94> }
      box { <-89, 39, -101>, <-62, 41, -94> }
      box { <-89, 9, -101>, <-87, 41, -94> }
      box { <-64, 9, -101>, <-62, 41, -94> }
      box { <-76, 10, -96>, <-75, 40, -95> }
      box { <-88, 24.5, -96>, <-63, 25.5, -95> }
      pigment { White }
    }
    pigment { GreenYellow }
  }

object { Room }

object {
  Paper
  rotate <-90, 0, -7>
  translate <2, 0.5, 0>
}

object { Fridge }  

object {
  Magnet(ZC_Equals, Med_Purple)
  scale 0.5
  rotate z * -15
  translate <5, 4.5, 0>
}

object {
  Magnet(ZC_Period, Green)
  scale 0.5
  translate <4, -1.25, 0>
}

object {
  Magnet(ZC_Colon, Blue)
  scale 0.5
  rotate z * -5
  translate <8, 6, 0>
}

object {
  Magnet(ZC_Semicolon, Yellow)
  scale 0.5
  rotate z * 7
  translate <-5.5, 6.5, 0>
}

object {
  Magnet(ZC_Underline, Orange)
  scale 0.5
  rotate z * 4
  translate <-4, -6, 0>
}

object {
  Magnet(ZC_Comma, Red)
  scale 0.5
  rotate z * 4
  translate <-0.25, 6, 0>
}

object {
  Magnet(ZC_LCurly, DarkGreen)
  scale 0.5
  rotate z * 4
  translate <-4, 1, 0>
}

object {
  Magnet(ZC_RCurly, DarkGreen)
  scale 0.5
  rotate z * 3.5
  translate <-3, 0.7, 0>
}

object {
  Magnet(ZC_Question, MidnightBlue)
  scale 0.5
  rotate z * -6
  translate <1, -1, 0>
}

object {
  Magnet(ZC_Char_To_Obj("b"), Aquamarine)
  scale 0.5
  rotate z * 8
  translate <8, -0.5, 0>
}

object {
  Magnet(ZC_Char_To_Obj("h"), Scarlet)
  scale 0.5
  rotate z * -7
  translate <7.5, -6.5, 0>
}
