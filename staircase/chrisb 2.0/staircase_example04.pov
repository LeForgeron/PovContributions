//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// 

/**********************************************************************************/
/* staircase_example04.pov  -  Created by Chris Bartlett April 2006               */
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

light_source {0 color rgb 1.2
  area_light            
  <8, 0, 0> <0, 0, 8>   // lights spread out across this distance (x * z)
  4, 4                  // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0            // 0,1,2,3...
  jitter                // adds random softening of light
  circular              // make the shape of the light circular
  orient                // orient light
  translate <50, 60,-30>  // <x y z> position of light
}


camera {location <0,3,-5> look_at  <0,0,0>}
#include "staircase.inc"
#declare StairCase_PairedBanisterOn = 0;
#declare StairCase_PostPositions = array [6] {<-3,0,0>,<-2,0,0>,<-1,-1,0>,<1,-1,0>,<2,0,0>,<3,0,0>};
StairCase()

//#declare StairCase_PairedBanisterOn = 1;
//#declare StairCase_MainBanisterOn = 0;
//#declare StairCase_StairsOn = 0;
//#declare StairCase_PostPositions = array [3] {<-3,0,0>,<-2,0,0>,<-1,-1,0>};
//StairCase()
//
//#declare StairCase_PostPositions = array [3] {<1,-1,0>,<2,0,0>,<3,0,0>};
//StairCase()
//
//#declare StairCase_MainBanisterOn = 1;
//#declare StairCase_StairsOn = 1;
//#declare StairCase_StairWidth=2;
//#declare StairCase_PostPositions = array [2] {<-1,-1.5,-1.65>,<-1,-1,-1>};
//StairCase()
