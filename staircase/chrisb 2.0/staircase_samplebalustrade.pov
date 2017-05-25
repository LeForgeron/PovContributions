//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// Scale is 1 Pov-Ray unit = 1 metre
// 

/**********************************************************************************/
/* staircase_samplebalustrade.pov  -  Created by Chris Bartlett March 2007        */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This scene file illustrates the different shaped balusters and    */
/*              newel posts defined in staircase_samplebalustrade.inc.            */
/*                                                                                */
/* Version:     Written using POV-Ray 3.6                                         */
/*                                                                                */
/**********************************************************************************/

#local StairCase_BalusterTexture = texture {
  pigment {rgb <1,0.95,0.9>}
  normal {agate 0.5 scale 0.05}
}

#local StairCase_RailTexture = texture {
  pigment {rgb <1,0.95,0.9>}
  normal {agate 0.2 scale 0.05}
}
//light_source{<0,-2,-4> color rgb 1}

#include "staircase_samplebalustrade.inc"

union {
  object {StairCase_Baluster                  texture {StairCase_BalusterTexture} clipped_by {plane {y,0.75}}} 
  object {StairCase_Baluster translate  x*0.3 texture {StairCase_BalusterTexture} clipped_by {plane {y,0.75}}} 
  object {StairCase_Baluster translate  x*0.6 texture {StairCase_BalusterTexture} clipped_by {plane {y,0.75}}} 
  object {StairCase_Baluster translate -x*0.3 texture {StairCase_BalusterTexture} clipped_by {plane {y,0.75}}} 
  object {StairCase_Baluster translate -x*0.6 texture {StairCase_BalusterTexture} clipped_by {plane {y,0.75}}} 
  object {StairCase_Baluster translate -x*0.9 texture {StairCase_BalusterTexture} clipped_by {plane {y,0.75}}} 
  object {StairCase_Baluster translate -x*1.2 texture {StairCase_BalusterTexture} clipped_by {plane {y,0.75}}} 
  object {StairCase_HandRail rotate -y*90 translate 0.75*y        texture {StairCase_RailTexture}}
  object {StairCase_HandRail rotate -y*90 translate < 0.6,0.75,0> texture {StairCase_RailTexture}}
  object {StairCase_HandRail rotate -y*90 translate <-0.6,0.75,0> texture {StairCase_RailTexture}}
  object {StairCase_Stringer texture {StairCase_RailTexture} rotate -y*90}
  object {StairCase_Stringer texture {StairCase_RailTexture} rotate -y*90 translate x*0.6} 
  object {StairCase_Stringer texture {StairCase_RailTexture} rotate -y*90 translate -x*0.6}
}
camera {location <2,0.75,-2>  look_at  <0,0.25,0>}
light_source {<0,10,-20> color rgb 1}
