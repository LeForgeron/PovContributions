//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// Scale is 1 Pov-Ray unit = 1 metre
// 

/**********************************************************************************/
/* staircase_samples.pov  -  Created by Chris Bartlett April 2006                 */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This scene file illustrates the different shaped balusters and    */
/*              newel posts defined in staircase_samples.inc.                     */
/*                                                                                */
/* Version:     Written using POV-Ray 3.6                                         */
/*                                                                                */
/**********************************************************************************/

#include "colors.inc"
#include "woods.inc"
#local StairCase_BalusterTexture = texture {T_Wood1 scale 0.1 rotate x*90}
light_source{<2,20,-5> color rgb 4}
light_source{<0,-2,-4> color rgb 1}

#include "staircase_samples.inc"

camera { orthographic location <0,0.5,-1.3> look_at <0,0.5,0>}

object {StairCase_BalusterShape ("Box"     ) texture {StairCase_BalusterTexture} translate -x*0.1}
object {StairCase_BalusterShape ("Bevelled") texture {StairCase_BalusterTexture} translate -x*0.2}
object {StairCase_BalusterShape ("Chamfer" ) texture {StairCase_BalusterTexture} translate -x*0.3}
object {StairCase_BalusterShape ("Notched" ) texture {StairCase_BalusterTexture} translate -x*0.4}
object {StairCase_BalusterShape ("Turned"  ) texture {StairCase_BalusterTexture} translate -x*0.5}
object {StairCase_BalusterShape ("Fluted"  ) texture {StairCase_BalusterTexture} translate -x*0.6}

object {StairCase_NewelShape ("Box"     ) texture {StairCase_BalusterTexture} translate x*0.1}
object {StairCase_NewelShape ("Bevelled") texture {StairCase_BalusterTexture} translate x*0.2}
object {StairCase_NewelShape ("Chamfer" ) texture {StairCase_BalusterTexture} translate x*0.3}
object {StairCase_NewelShape ("Notched" ) texture {StairCase_BalusterTexture} translate x*0.4}
object {StairCase_NewelShape ("Turned"  ) texture {StairCase_BalusterTexture} translate x*0.5}
object {StairCase_NewelShape ("Fluted"  ) texture {StairCase_BalusterTexture} translate x*0.6}


