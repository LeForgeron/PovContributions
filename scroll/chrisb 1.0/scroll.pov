// Scroll.pov
// -----------

// Scene file that generates a mesh2 object in the form of a paper scroll.
// Created by Chris Bartlett 07.02.2005
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time 1 second
// Size is about 0.5 POV-Ray units high.
// Position is close to the origin.

camera {location <-0.2,0.3,-0.5> look_at 0.1}
light_source { <-10,4,-4> color rgb 1}
light_source { <-10,-7,-40> color rgb 1} 
#include "math.inc" 
#include "Scroll_array2mesh2.inc"

// The coordinates of the mesh2 nodes are written into an array   
#local Scroll_Array = array [1000][2];


// First do a spiral at one end
#local Scroll_I = 0;
#local Scroll_ArrayIndex = 0;
#local Scroll_R = 0.015; 
#while (Scroll_I<900)
  #local Scroll_X = Scroll_R*cosd(Scroll_I);
  #local Scroll_Y = Scroll_R*sind(Scroll_I);
  #local Scroll_Z = 0;
  #local Scroll_Array[Scroll_ArrayIndex][0] = <Scroll_X+0.15,Scroll_Y+0.3,Scroll_Z-0.15>;
  #local Scroll_Array[Scroll_ArrayIndex][1] = <Scroll_X+0.15,Scroll_Y+0.3,Scroll_Z+0.15>;
  #local Scroll_R = Scroll_R*1.01;     // Add 1 percent to the radius each time 
  #local Scroll_I = Scroll_I + 10;
  #local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;
#end 

// Then add the more or less straight bit in the middle
#local Scroll_Array[Scroll_ArrayIndex][0] = <Scroll_X+0.135,Scroll_Y+0.25,Scroll_Z-0.15>;
#local Scroll_Array[Scroll_ArrayIndex][1] = <Scroll_X+0.135,Scroll_Y+0.25,Scroll_Z+0.15>;
#local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;

#local Scroll_Array[Scroll_ArrayIndex][0] = <Scroll_X+0.115,Scroll_Y+0.2,Scroll_Z-0.15>;
#local Scroll_Array[Scroll_ArrayIndex][1] = <Scroll_X+0.115,Scroll_Y+0.2,Scroll_Z+0.15>;
#local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;

#local Scroll_Array[Scroll_ArrayIndex][0] = <Scroll_X+0.065,Scroll_Y+0.1,Scroll_Z-0.15>;
#local Scroll_Array[Scroll_ArrayIndex][1] = <Scroll_X+0.065,Scroll_Y+0.1,Scroll_Z+0.15>;
#local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;

#local Scroll_Array[Scroll_ArrayIndex][0] = <Scroll_X+0.035,Scroll_Y+0.05,Scroll_Z-0.15>;
#local Scroll_Array[Scroll_ArrayIndex][1] = <Scroll_X+0.035,Scroll_Y+0.05,Scroll_Z+0.15>;
#local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;

// Then add a spiral at the other end
#local Scroll_I = Scroll_I-40;
#while (Scroll_I<1800)
  #local Scroll_X = Scroll_R*cosd(Scroll_I);
  #local Scroll_Y = Scroll_R*sind(Scroll_I);
  #local Scroll_Z = 0;
  #local Scroll_Array[Scroll_ArrayIndex][0] = <Scroll_X,Scroll_Y,Scroll_Z-0.15>;
  #local Scroll_Array[Scroll_ArrayIndex][1] = <Scroll_X,Scroll_Y,Scroll_Z+0.15>;
  #local Scroll_R = Scroll_R*0.99;     // Remove 1 percent from the radius each time 
  #local Scroll_I = Scroll_I + 10;
  #local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;
#end 


// Call a function to generate a mesh2 object from the array
#local Scroll_DummyArray  = array [Scroll_ArrayIndex][2];
#local Scroll_Verbose = 0;

object {Scroll_Mesh2FromArray(Scroll_Array, Scroll_DummyArray, Scroll_ArrayIndex, 2, 0) pigment {color rgb <1,1,0.9>} }
     

