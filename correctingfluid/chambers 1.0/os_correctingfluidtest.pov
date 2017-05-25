
// os_correctingfluidtest.pov
// --------------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This scene file can be used to test the 'os_correctingfluid' include file parameters. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// Render time is typically 10-20 seconds at 640x480 (most of which is the time taken to render the label).

#local AboveBelow = 1;   // 1 for above, -1 for below
light_source { <-15,AboveBelow*7.5,-15>, rgb 2}
camera {location <-0.05,AboveBelow*0.08,-0.09> look_at <0,0.035,0>}

#include "os_correctingfluid.inc" 

// Use '0' to render using the default values
#if (1)
  #declare OS_CorrectingFluidBottleRadius               = 0.017; 
  #declare OS_CorrectingFluidBottleHeight               = 0.075; 
  #declare OS_CorrectingFluidBottleThickness            = 0.001;
  #declare OS_CorrectingFluidBottleNeckRadius           = OS_CorrectingFluidBottleHeight*0.008 /0.072;
  #declare OS_CorrectingFluidBottleNeckBase             = OS_CorrectingFluidBottleHeight*0.049 /0.072;
  #declare OS_CorrectingFluidBottleNeckTop              = OS_CorrectingFluidBottleHeight*0.054 /0.072;
  #declare OS_CorrectingFluidBottleShoulderHeight       = OS_CorrectingFluidBottleHeight*0.044 /0.072;
  #declare OS_CorrectingFluidBottleShoulderRoundness    = OS_CorrectingFluidBottleHeight*0.004 /0.072;
  #declare OS_CorrectingFluidBottleBaseRoundness        = OS_CorrectingFluidBottleHeight*0.005 /0.072;
  #declare OS_CorrectingFluidBottleBaseInsetRadius      = OS_CorrectingFluidBottleHeight*0.009 /0.072;
  #declare OS_CorrectingFluidBottleBaseInsetRoundness   = OS_CorrectingFluidBottleHeight*0.002 /0.072;
  #declare OS_CorrectingFluidBottleStemBase             = OS_CorrectingFluidBottleHeight*0.022 /0.072;
  #declare OS_CorrectingFluidBottleStemTop              = OS_CorrectingFluidBottleHeight*0.065 /0.072;
  #declare OS_CorrectingFluidBottleStemRadius           = OS_CorrectingFluidBottleHeight*0.003 /0.072;
  #declare OS_CorrectingFluidBottleBrushLength          = OS_CorrectingFluidBottleHeight*0.012 /0.072;
  #declare OS_CorrectingFluidBottleBrushRadius          = OS_CorrectingFluidBottleHeight*0.0025/0.072;
  #declare OS_CorrectingFluidBottleFibreCount           = 45;     
  #declare OS_CorrectingFluidBottleFibreSeed            = seed(8);
  #declare OS_CorrectingFluidBottleCapRadius            = OS_CorrectingFluidBottleHeight*0.015 /0.072;
  #declare OS_CorrectingFluidBottleCapRecessHeight      = OS_CorrectingFluidBottleHeight*0.060 /0.072;
  #declare OS_CorrectingFluidBottleCapRecessLowerRadius = OS_CorrectingFluidBottleHeight*0.007 /0.072;
  #declare OS_CorrectingFluidBottleCapRecessUpperRadius = OS_CorrectingFluidBottleHeight*0.008 /0.072;
  #declare OS_CorrectingFluidBottleCapLipThickness      = OS_CorrectingFluidBottleHeight*0.004 /0.072;
  #declare OS_CorrectingFluidBottleCapDentRadius        = OS_CorrectingFluidBottleHeight*0.01  /0.072;
  #declare OS_CorrectingFluidLabelRounding              = 0.005; 
  #declare OS_CorrectingFluidLabelThickness             = 0.001;
  #declare OS_CorrectingFluidLabelGap                   = 0.003; 
  #declare OS_CorrectingFluidLabelBottom                = 0.006; 
  #declare OS_CorrectingFluidLabelTop                   = 0.040; 
  #declare OS_CorrectingFluid_LabelFile                 = "os_correctingfluidlabel.inc";
  #declare OS_CorrectingFluidBottleTexture              = pigment {rgb <1,1,0>};
  #declare OS_CorrectingFluidCapTexture                 = pigment {rgb <0,0,1>};
  #declare OS_CorrectingFluidBrushStemTexture           = pigment {rgb <1,0,0>};
  #declare OS_CorrectingFluidBrushTexture               = pigment {rgb <1,0,1>};
  #declare OS_CorrectingFluidTexture                    = pigment {rgb <0,1,4>};
  #declare OS_CorrectingFluid_DesignMode                = 0;
  #declare OS_CorrectingFluid_LabelDesignMode           = 0;
#end

object{OS_CorrectingFluid()       translate -x*0.04} 

object{OS_CorrectingFluidBottle() translate -x*0.00} 
object{OS_CorrectingFluidCap()    translate  x*0.03} 
object{OS_CorrectingFluidLabel()  translate  x*0.07} 


