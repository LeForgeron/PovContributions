//
// hknots_doc.pov
// --------------
// Created by Chris Bartlett Oct 2009.
//
// This scene file illustrates the use of the macros contained in the 'hknots.inc' file.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The generated object is about 200 POV-Ray units high and about 400 wide and by default 
// is centred at the origin.
//
// Adding this model to your scene is likely to add a couple of seconds to the render time.
//
// See hknots.html for more details.
//
// Use animation options +kfi0 +kff25 and regenerate the images for the documentation. 

// Comments, suggestions, complaints, etc to dsharp@interport.net 
// http://www.interport.net/~dsharp

#include "colors.Inc"
#include "textures.Inc"

#include "hknots.inc"

// Viewpoint location needs adjusting for different knots
camera{
  location <0, 0, -400>
  look_at <0,0,0>
}

light_source {
  <200, 100, -1200>
  color White
}

#declare Example = frame_number;

#declare KnotShape     = array [16];
#declare ScaleFactor   = array [16];
#declare KnotShape[0]  = HKnots_three_1_array            #declare ScaleFactor[0]  = 0.75;
#declare KnotShape[1]  = HKnots_four_1_array             #declare ScaleFactor[1]  = 0.5;
#declare KnotShape[2]  = HKnots_five_1_array             #declare ScaleFactor[2]  = 0.35;
#declare KnotShape[3]  = HKnots_five_2_array             #declare ScaleFactor[3]  = 0.45;
#declare KnotShape[4]  = HKnots_six_1_array              #declare ScaleFactor[4]  = 0.5;
#declare KnotShape[5]  = HKnots_six_2_array              #declare ScaleFactor[5]  = 0.5;
#declare KnotShape[6]  = HKnots_six_3_array              #declare ScaleFactor[6]  = 0.5;
#declare KnotShape[7]  = HKnots_Square_knot_array        #declare ScaleFactor[7]  = 1;
#declare KnotShape[8]  = HKnots_Granny_knot_array        #declare ScaleFactor[8]  = 1;
#declare KnotShape[9]  = HKnots_seven_1_array            #declare ScaleFactor[9]  = 0.5;
#declare KnotShape[10] = HKnots_seven_2_array            #declare ScaleFactor[10] = 0.45;
#declare KnotShape[11] = HKnots_seven_3_array            #declare ScaleFactor[11] = 0.45;
#declare KnotShape[12] = HKnots_seven_4_array            #declare ScaleFactor[12] = 0.75;
#declare KnotShape[13] = HKnots_seven_5_array            #declare ScaleFactor[13] = 0.75;
#declare KnotShape[14] = HKnots_seven_6_array            #declare ScaleFactor[14] = 0.45;
#declare KnotShape[15] = HKnots_seven_7_array            #declare ScaleFactor[15] = 0.55;


#declare RibbonStyle = array[8] {"STriangles2", "KTriangles", "CylRibs", "CylArray", "STriangles", "Tracks", "STriangles2", "TriangleRibs"}


#declare Scale = 1;
#declare Style = RibbonStyle[5];
#declare HKnots_H_Array = KnotShape[8]

// Frames 0-7 illustrate the available Ribbon Styles
#if (frame_number < 8)
  #declare Style = RibbonStyle[frame_number];
  background{White}  
#end
                                                
// Frames 10-25 illustrate the available Knot Shapes
#if (frame_number >=10 & frame_number<=25)
  #declare HKnots_H_Array = KnotShape[frame_number-10]
  #declare Scale = ScaleFactor[frame_number-10];
  background{Black}  
#end  
  
#if (frame_number=30)
  // Set the size of the tube, ribbon, whatever
  #declare HKnots_R0=35;             // Default 15
  // The 'resolution' of the parameterization
  #declare HKnots_Total_Segs= 900;   // Default 200
#end

object{HKnots(Style) scale Scale}

