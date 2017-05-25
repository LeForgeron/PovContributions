// Title:        MultiObjectPattern simple examples
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 19, 2008
// Last updated: June 19, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#include "colors.inc"
#include "multiobj.inc"

global_settings {
  assumed_gamma 1.0
}

camera {
  location z * -15
  up y
  right x * image_width/image_height
  look_at 0
}

light_source {
  <5, 5, -20>, White
}

background { GreenYellow }

// Using object array

#declare Objs =
  array[3] {
    box { <-1.5, -1.5, -3>, <1.5, 1.5, 3> },
    box { <-1, -1, -3>, <1, 1, 3> },
    cylinder { z * -3, z * 3, 0.5 }
  };

box {
  -2, 2
  pigment {
    MultiObj_Ptrn(Objs)
    color_map {
      [0   Blue]
      [1/3 Red]
      [2/3 Green]
      [1   Yellow]
    }
  }
  translate x * -5
}

// Using predeclared objects

#declare Box1 =
  box {
    <-1, -1, -3>, <1, 1, 3>
    translate <0.5, 0.5, 0>
  }

#declare Box2 =
  box {
    <-1, -1, -3>, <1, 1, 3>
  }

#declare Box3 =
  box {
    <-1, -1, -3>, <1, 1, 3>
    translate <-0.5, -0.5, 0>
  }
  
box {
  -2, 2
  pigment {
    MultiObj_Ptrn_3(Box1, Box2, Box3)
    color_map {
      [0   Blue]
      [1/3 Red]
      [2/3 Green]
      [1   Yellow]
    }
  }
}

// Using inline objects

box {
  -2, 2
  pigment {
    MultiObj_Ptrn_3(
      cylinder { <-0.5, 0, -3>, <-0.5, 0, 3>, 0.5 },
      cylinder { z * -3, z * 3, 0.5 },
      cylinder { <0.5, 0, -3>, <0.5, 0, 3>, 0.5 }
    )      
    color_map {
      [0   Blue]
      [1/3 Red]
      [2/3 Green]
      [1   Yellow]
    }
  }
  translate x * 5
}

