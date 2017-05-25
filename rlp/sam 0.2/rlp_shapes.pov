/*
 
 //This file is licensed under the terms of the CC-LGPL
 
 rlpShapes.pov
 
 An example showcasing the four subset shape primitives.
 
*/


  //¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //   example   //
//_____________//

#include "rlp.inc"

#declare Square = rlp_square(1);
rlp_translate(Square, <-3,0>)

#declare rectangle = rlp_rectangle(<.5,1>)
rlp_translate(rectangle, <-1,0>)

#declare n_gon = rlp_n_gon(1, 6, 0);
rlp_translate(n_gon, <0.875,0>)

#declare star = rlp_star(1, -1, 7, 0, 0);
rlp_translate(star, <3,0>)

// invoking the object macro
object{
 rlp_chamfered(
  array[4]{Square, rectangle, star, n_gon},
  -0.5, 0.5, 0, 0.2
 )
 pigment{rgb x+y}
}

object{
 rlp(
  array[4]{Square, rectangle, star, n_gon},
  -0.5, 0.5, 0.2, 0.0
 )
 pigment{rgb x+y}
 translate y*2.5
}

// guarantee roundness for outside corners
//#declare rlp_enforce_roundness = true;

object{
 rlp(
  array[4]{Square, rectangle, star, n_gon},
  -0.5, 0.5, 0, 0.2
 )
 pigment{rgb x+y}
 translate -y*2.5
}
  
  //¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //  end example  //
//_______________//


background{rgb x/10}

light_source{<.25,1,-.5>*1e9,1.5}

camera{
 location<0,0,-15>
 look_at 0
 angle 40
}
