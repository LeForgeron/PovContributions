//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// 

/**********************************************************************************/
/* staircase_example01.pov  -  Created by Chris Bartlett April 2006               */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This scene file illustrates the use of the staircase.inc file     */
/*              which is designed to enable you to add a staircase to a POV-Ray   */
/*              scene. The file staircase.html describes its use.                 */
/* Version:     Written using POV-Ray 3.5 and tested on 3.6                       */
/**********************************************************************************/

#version 3.5;

#include "staircase.inc"   

// An area light
light_source {0 color rgb 1.2
  area_light            
  <8, 0, 0> <0, 0, 8>   // lights spread out across this distance (x * z)
  4, 4                  // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0            // 0,1,2,3...
  jitter                // adds random softening of light
  circular              // make the shape of the light circular
  orient                // orient light
  translate <60, 80,-70>  // <x y z> position of light
}

camera {location <3.3,3.2,-4.5> look_at  <0,1.5,0.5>}

#declare StairCase_StairWidth = 2;
#declare StairCase_StairCarpetColour = <0,1,0>;
#declare StairCase_StairCarpetWidth = 1.6;
#declare StairCase_PostPositions = array [9] {
  <0,-1,-3.75>,<0,1,1.25>,<0,1,2.25>,
  <0,0,4.5>   ,<-5,4,6.5>,<-8,4,4.5>,
  <-7,3,3>    ,<-2,-1,2> ,<10,-1,2>
};

StairCase()

