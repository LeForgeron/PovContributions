/*
 
 //This file is licensed under the terms of the CC-LGPL
 
 rlpMulti.pov
 
 Shows how subsets can be copied and transformed.
 
*/


  //¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //   example   //
//_____________//

#include "rlp.inc"

#declare n_holes = 7;
#declare pts = array[1+n_holes];

// container, 1st subset
#declare pts[0] = rlp_square(1.0);

// round off the container's corners
rlp_set_radii(pts[0], 1.0)

// a shape that will be used for the holes
#declare a_shape =
array[9]{
 <.5, 0,   0>,
 <.5, .5,  1>,
 <1, .5,   0>,
 <1.2, 1,  0>,
 <0, 1.32, 1>,
 <-1.2, 1, 0>,
 <-1, .5,  0>,
 <-.5, .5, 1>,
 <-.5, 0,  0>
}

// scaling the shape
rlp_scale(a_shape, <.2,.2>)

// the holes
#declare V = 1;
#while(V<=n_holes)
 
 // make a new subset from the hole shape
 #declare pts[V] = a_shape;
 
 // transform it
 rlp_translate(pts[V], <0,.65>)
 rlp_rotate(pts[V], 360/(n_holes+1)*V+180)
 
 #declare V = V + 1;
#end

// invoking the object macro
union{
 
 rlp(pts, -0.25, 0.25, 0, .025)
 
  // a wood texture
 texture{
  pigment{
   pigment_pattern{
    pigment_pattern{
     function{ pow((pow(x,2)+pow(y,2))*32,.75) }
     poly_wave .2
    }
    triangle_wave
    pigment_map{
     [0 granite scale<.04,.04,1> poly_wave .75]
     [1 rgb 0]
    }
   }
   color_map{
    [0 rgb<1,.6,.3>*.57]
    [1 rgb<1,.6,.3>]
   }
   turbulence .05 lambda 2.25
  }
  normal{
   granite -.03
   scale<.1,10,10> rotate z*33
   no_bump_scale poly_wave 4
  }
 }
 
}
  
  //¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯//
 //  end example  //
//_______________//


light_source{<.5,1,-.5>*1e9,1.5}

camera{
 location<5,5,-10>
 look_at 0
 angle 15
}

plane{y,-1
 pigment{ // an imbrication
  pigment_pattern{
   cylindrical
   pigment_map{
    [0
     planar rotate z*90
     color_map{
      [0 rgb 1]
      [1 rgb 0]
     }
    ]
    [1e-7
     cylindrical
    ]
   }
  }
  #declare rgb_olden = rgb <1,.8,.6>;
  color_map{
   [0 rgb_olden/2]
   [.1 rgb_olden/2]
   [.1 rgb 1]
   [.2 rgb 1]
   [.3 rgb<.75,.5,.5>]
   [1 rgb<1,.9,.7>]
  }
  translate(x) scale 1/2
  warp{repeat x}
  warp{repeat z/2 offset x/2}
 }
}