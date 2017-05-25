/*
 
 //This file is licensed under the terms of the CC-LGPL
 
 rlpBorder.pov
 
 Shows how to make borders using rlp_shift and rlp_reverse.
 
*/


  //¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //   example   //
//_____________//

#include "rlp.inc"

// basic sign-shaped subset
#declare sign =
 array[8]{
  <-2, -1.25,  0>,
  <-2, .25,    0>,
  <-1.5, .25,  0>,
  <-1.5, 1.25, 1>, // <--- rounded top
  < 1.5, 1.25, 1>, // <--´
  < 1.5, .25,  0>,
  < 2,   .25,  0>,
  < 2,   -1.25,0>
 }

// declare a new subset derived from "sign"
#declare sign_punch = sign;

// reverse the order of the points so it can be used to make a hole
rlp_reverse(sign_punch)

// offset the points
rlp_shift(sign_punch, 0.25)

// making objects from the subsets
union{
 rlp(                 // object without border
  array[1]{sign},
  -0.15, 0.25, 0, 0.05
 )
 
 rlp(                 // object with border
  array[2]{sign, sign_punch},
  -0.25, 0, 0, 0.05
 )
 
 pigment{rgb<.8,.6,.4>}
}
  
  //¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //  end example  //
//_______________//


background{rgb 1}

light_source{<.25,1,-.5>*1e9,1.5}

camera{
 location<5,5,-10>
 look_at 0
 angle 22
}