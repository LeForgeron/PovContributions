/*
 
 //This file is licensed under the terms of the CC-LGPL
 
 rlpArch.pov
 
 An example showing how to use rlp_bevels to seamlessly fit an rlp object to other geometries.
 
*/


  //¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //   example   //
//_____________//

#include "rlp.inc"

// this pointset will contain two subsets
#declare pts = array[2];

// container, 1st subset
#declare pts[0] = rlp_rectangle(<1.5,2>)

// arch-shaped hole, 2nd subset
#declare pts[1] =
 array[5]{
  <1.3,  -1.8, 0.00>,
  <1.3,   0.5, 1.25>,    // rounded portion
  <0.0,   1.8, 0.00>,    // top point
  <-1.3,  0.5, 1.25>,    // rounded portion
  <-1.3, -1.8, 0.00>
 }

// set the beveling for individual subsets
// the container gets zero beveling
#declare rlp_bevels = array[2]{0, 0.1}

// invoking the object macro
union{
 rlp(pts, -0.5, 1.0, 0, 0)
 pigment{rgb 1}
}

// wall
union{
 box{<-5,-2,-0.5>,<-1.5,2,0.5>}
 box{<1.5,-2,-0.5>,<5,2,0.5>}
 box{<-5,2,-0.5>,<5,5,0.5>}
 box{<-5,-5,-0.5>,<5,-2,0.5>}
 pigment{rgb .8}
}
  
  //¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //  end example  //
//_______________//


light_source{<.25,1,-.5>*1e9,1.5}

camera{
 location -z*10
 look_at 0
 angle 35
}