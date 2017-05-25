// Title:        ZArrays Demo Scene
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   February 22, 2008
// Last Updated: February 26, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#include "chars.inc"
#include "colors.inc"
#include "zarrays.inc"

global_settings {
  assumed_gamma 1.0
}

camera {
  location z * -35
  up y
  right x * image_width/image_height
  look_at 0
}

light_source {
  <10, 10, -100>, White
}

background { rgb <0.7, 0.7, 1> }

#declare X_Size = 4;
#declare Y_Size = 5;
#declare Spacing = 1;
#declare XSz = X_Size + Spacing;
#declare YSz = Y_Size + Spacing;

#declare Count = 6;

#declare Back_Width = 32;
#declare Back_Height = 32;
#declare Back_Z = 80;

#declare R = seed(7);

#declare char_Comma =
  union {
    cylinder { <0, 0.5, 0>, <0, 0.5, 1>, 0.5 }
    difference {
      cylinder { 0, z, 0.5 scale <1, 2, 1> }
      cylinder { z * -0.0001, z * 1.0001, 0.5 
        scale <1, 2.1, 1> 
        translate x * -0.35
      }
      plane { -y, 0 }
      bounded_by {
        box { <-0.5, -1, 0>, <0.5, 0, 1> }
      }
      translate y * 0.5
    }
  }

union {
  object { char_Z translate x * XSz * -Count/2 }
  object { char_A translate x * XSz * (-Count/2 + 1) }
  object { char_R translate x * XSz * (-Count/2 + 2) }
  object { char_R translate x * XSz * (-Count/2 + 3) }
  object { char_A translate x * XSz * (-Count/2 + 4) }
  object { char_Y translate x * XSz * (-Count/2 + 5) }
  object { char_S translate x * XSz * (-Count/2 + 6) }
  no_shadow
  pigment { Red }
  translate y * -0.5
}

#declare Char_Array =
  array[11] {
    object { char_0 },
    object { char_1 },
    object { char_2 },
    object { char_3 },
    object { char_4 },
    object { char_5 },
    object { char_6 },
    object { char_7 },
    object { char_8 },
    object { char_9 },
    object { char_Comma }
  };

#declare Background_Array = ZA_New_Rand_Array(2, <Back_Width, Back_Height>, Char_Array, R);

#declare Grad_Func =
  function {
    pigment {
      gradient x+y
      triangle_wave
      color_map {
        [0 Green]
        [1 Blue ]
      }
      scale 10
    }
  }

#macro ZA_Process_Item(Item, Subs, Stop)
  #local Back_X = (Subs[0] - Back_Width/2) * XSz;
  #local Back_Y = (Subs[1] - Back_Height/2) * YSz;
  
  object { 
    Item
    //pigment { rgb <0.6, 0.6, 1> }
    #declare Col = Grad_Func(Subs[0], Subs[1], 0);
    pigment { Col }
    translate <Back_X, Back_Y, Back_Z> 
  }
#end

ZA_Process_Array(Background_Array)
