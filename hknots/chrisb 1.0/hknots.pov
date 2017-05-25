//
// hknots.pov
// ----------
// Created by David Sharp based upon Aaron K. Trautwein's concepts for the Fourier 
// "harmonic" parameterizations of knots. Adapted to go into the POV-Ray Object 
// Collection Oct 2009 by Chris Bartlett.
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
background{White}  

// Set the size of the tube, ribbon, whatever
//#declare HKnots_R0=35;             // Default 15

// The 'resolution' of the parameterization
//#declare HKnots_Total_Segs= 900;   // Default 200


// Put the knot in the scene                                                                         
// The knot shape is defined as an array of parameters. You can set up the array yourself or use one of the predefined parameter sets:
// HKnots_three_1_array, HKnots_four_1_array, HKnots_five_1_array, HKnots_five_2_array, HKnots_six_1_array, HKnots_six_2_array, HKnots_six_3_array,
// HKnots_Square_knot_array, HKnots_Granny_knot_array, HKnots_seven_1_array, HKnots_seven_2_array, HKnots_seven_3_array, HKnots_seven_4_array, 
// HKnots_seven_5_array, HKnots_seven_6_array, HKnots_seven_7_array,     
#declare HKnots_H_Array = HKnots_Granny_knot_array
       
// The style of the ribbon is specified on the macro call and should be one of the following strings:
// "STriangles2", "KTriangles", "CylRibs", "CylArray", "STriangles", "Tracks", "STriangles2", "TriangleRibs"
object{
  HKnots("Tracks")
//  rotate<0,80,0>
}

