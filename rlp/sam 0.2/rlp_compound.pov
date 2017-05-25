/*
 
 //This file is licensed under the terms of the CC-LGPL
 
 rlpCompound.pov
 
 A simple demonstration of how multiple rlp objects can be used to build more complex shapes.
 
*/


  //¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //   example   //
//_____________//

#include "rlp.inc"

#declare rlp_enforce_roundness = true;
#declare shift = -0.1;
#declare bev   = 0.05;

#declare pts =
array[1]{
 array[8]{
  <-.5,.5,1>,
  <-.5,-1,0>,
  <-1,-1,0>,
  <-1,1,1>,
  <1,1,1>,
  <1,-1,0>,
  <.5,-1,0>,
  <.5,.5,1>
 }
}

rlp_shift_all(pts, shift)

#declare arch =
object{
 rlp( pts, -1,1, 0, bev)
}

#declare flange=
object{
 rlp(
  array[1]{
   array[8]{
    <1,0,0>,
    <1,-1,.5>,
    <2,-1,0>,
    <2,-1.5,0>,
    <-2,-1.5,0>,
    <-2,-1,0>,
    <-1,-1,.5>,
    <-1,0,0>
   }
  }
  , -1-shift,-.5+shift, 0, bev)
 rotate y*270
}

union{
 object{arch}
 object{flange}
 object{flange scale<-1,1,1>}
 pigment{rgb<1,.95,.9>}
}
  
  //¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //  end example  //
//_______________//

sky_sphere{pigment{bumps cubic_wave scale .3}}

light_source{<.75,1,-.5>*1e9,1.5}

camera{
 location<8,5,-10>
 look_at -y/2
 angle 25
}

plane{y,-1.5
 pigment{rgb<.45,.475,.5>}
}