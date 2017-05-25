
// os_correctingfluid.pov
// ----------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This scene file demonstrates the use of the 'os_correctingfluid' include file. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// Render time is typically 10-20 seconds at 640x480 (most of which is the time taken to render the label).

light_source { <-15,7.5,-15>, rgb 2}
camera {location <-0.05,0.05,-0.07> look_at <0,0.035,0>}

#include "os_correctingfluid.inc"        

// The first 3 examples use a complete bottle
#local MyBottle = OS_CorrectingFluid()

// Example 1 - Bottle standing in default position at the origin
object {MyBottle}   

// Example 2 - Bottle standing to the right of the first and rotated slightly
object {MyBottle rotate  80*y translate 0.05*x} 

// Example 3 - Moved off-centre by it's radius, so that when we rotate it the edge lies on the XZ plane
//             Then rotated a bit and moved back behind the first two (and to the left a bit)
object {MyBottle rotate 240*y
  translate -x*OS_CorrectingFluidBottleRadius
  rotate -z*90  
  rotate y*20
  translate <-0.02,0,0.08>
}

// Example 4 - Illustrates how the components can be used independently.
//             This example positions the bottle (without a label) laying on it's side
//             and a cap (mostly out of the bottle) 
union {
  OS_CorrectingFluidBottle()
  object {OS_CorrectingFluidCap() rotate -20*z translate y*0.045}
  translate z*OS_CorrectingFluidBottleRadius
  rotate <-90,-5,0>
  translate <-2.5*OS_CorrectingFluidBottleRadius,0,1.7*OS_CorrectingFluidBottleHeight>
}   
