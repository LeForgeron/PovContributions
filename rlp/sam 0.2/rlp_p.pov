/*
 
 //This file is licensed under the terms of the CC-LGPL
 
 rlpP.pov
 
 Here's a demonstration of how you might make fonts with the rlp macros.
 
*/


  //¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //   example   //
//_____________//

#include "rlp.inc"

// this pointset will contain two subsets
#declare pts = array[2];

// container, 1st subset
#declare pts[0] =
array[12]{
 <-.7,1,0>,
 <.7,1,1.1/2>,
 <.7,-.1,1.1/2>,
 
 <-.15,-.1,0>,
 <-.15,-.9,.1>,
 <.05,-.9,0>,
 
 <.05,-1,0>,
 <-.7,-1,0>,
 <-.7,-.9,0>,
 
 <-.5,-.9,.1>,
 <-.5,.9,.1>,
 <-.7,.9,0>
}

// hole, 2nd subset
#declare pts[1] =
array[4]{
 <-.15,0,0>,
 <.35,0,.775/2>,
 <.35,.9,.775/2>,
 <-.15,.9,0>
}

// invoking the object macro
union{
 rlp_chamfered(pts, -0.25, 0.25, 0, .02)
 pigment{rgb 1}
 finish{ambient 0 specular 1}
 
}
  
  //¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //  end example  //
//_______________//


light_source{
 <.25,1,-1>*10,2
 fade_power 2 fade_distance 10
 #if(0)
  area_light x*8,y*8,8,8
  jitter adaptive 2
  area_illumination
 #end
}

camera{
 location<5,5,-10>
 look_at y*.1
 angle 15
 
}

plane{y,-1
 pigment{rgb .5}
 finish{ambient 0}
}