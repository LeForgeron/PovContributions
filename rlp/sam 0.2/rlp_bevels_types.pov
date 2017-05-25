/*
 
 //This file is licensed under the terms of the CC-LGPL
 
 rlpBevels&Types.pov
 
 Here custom beveling and bevel types are provided for a single rlp object.
 
*/


  //¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //   example   //
//_____________//

#include "rlp.inc"

// this pointset will contain two subsets
#declare pts = array[2];

// container, 1st subset
#declare pts[0] = rlp_n_gon(1, 6, 0.125);

// hole, 2nd subset
#declare pts[1] = rlp_n_gon(0.5, 6, 1);

// holes must have points which go counter-clockwise
rlp_reverse(pts[1])

// set the beveling for individual subsets
#declare rlp_bevels = array[2]{0.05, 0.35}

// the first subset will get chamfered beveling, the second, rounded beveling
#declare rlp_types = array[2]{1, 0}

// invoking the object macro
union{
 rlp(pts, -0.5, 0.5, 1, 0)
 pigment{rgb x}
 finish{phong 1}
}
  
  //¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //  end example  //
//_______________//


light_source{<.25,1,-.5>*1e9,1.5}

camera{
 location<5,5,-10>
 look_at 0
 angle 15
}