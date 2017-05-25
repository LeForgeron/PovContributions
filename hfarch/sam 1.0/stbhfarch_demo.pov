/*

stbHFarch.inc example scene file
2007 Sam Benge
This file is licensed under the terms of the CC-LGPL

Object definitions are made into macros to
avoid unessessary parsing at render time.

Just uncomment the macro instances near the
bottom of this file.

Render with +w400 +h400

*/


global_settings{
 assumed_gamma 1
}

#default{ finish{ambient 0 } }

camera{ 
 orthographic
 right x*1
 up y*1
 location <0,0,-45>
 angle 26
 look_at 0
}

#declare area_light_res=2;
light_source{<.5,1,-.5>*100000,<1,.95,.8>*2 area_light x*25000,z*25000,area_light_res,area_light_res orient circular jitter adaptive 1 }
light_source{<-.3,-.5,-1>*100000,<1,.95,.8>/2 area_light x*90000,z*90000,area_light_res,area_light_res orient circular jitter adaptive 2 }

// backdrop
plane{z,100
 pigment{
  planar scale 24 translate -y*12
  turbulence .2 lambda 3
  color_map{[0 rgb .8][1 rgb 0]}
 }
 finish{ambient 1 diffuse 0}
 no_shadow
}

#include"stbHFarch.inc"

// basic arch shape with default values and
// a higher (than default) detail
#macro stbHFarch_object1() 
 #declare stbHFarch_brick_res = <200,200>;
 object{
  stbHFarch_brick_arch(10,10,360,7,1)
  pigment{rgb 1}
 }
 stbHFarch_reset_values()
#end

// pillars with custom brick patterns
#macro stbHFarch_object2()
 union{
  #declare stbHFarch_brick_pattern =
  pigment_map{
   [0 rgb 0]
   [.5
    function{1-min(abs(x),abs(y))/2}
    color_map{[.5 rgb 0][1 rgb 1]}
   ]
  }
  object{
   stbHFarch_pillar(10,4,20,4,2)
   translate -y*10
   pigment{rgb 1}
  }
  
  #declare stbHFarch_brick_pattern_reset = yes;
  #declare stbHFarch_brick_pattern =
  pigment_map{
   [0 rgb 0]
   [.25 rgb .25]
   [.75 rgb .25]
   [1
    granite scale 8
   ]
  }
  object{
   stbHFarch_pillar(6,5,20,5,2)
   translate -y*10
   pigment{rgb 1}
  }
 }
 
 stbHFarch_reset_values()
#end

// arch and pillars with lattice brick pattern
// and pattern reset
#macro stbHFarch_object3()
 #declare stbHFarch_brick_pattern_reset = yes;
 #declare stbHFarch_brick_pattern =
 pigment_map{
  [0 rgb 0]
  [.2 rgb 1]
  [.5 rgb 1]
  [.6
   pigment_pattern{
    boxed scale .5 translate (x+y)/2
    warp{repeat x}
    warp{repeat y}
    warp{planar}
    rotate z*45
    scale 2
    
   }
   color_map{[0 rgb .8][.3 rgb .8][.4 rgb 0]}
  ]
 }
 union{
  stbHFarch_pillar(10,5,10,1,.5)
  #declare stbHFarch_brick_res = <300,300>;
  object{
   stbHFarch_brick_arch(10,5,180,1,.5)
   translate y*10
  }
  
  pigment{rgb 1}
  translate -y*10
 }
 stbHFarch_reset_values()
#end

// arch and pillars with mirroring, modified clipping depth,
// offset pattern and offset texture
#macro stbHFarch_object4()
 #declare stbHFarch_brick_mirror = yes;
 #declare stbHFarch_brick_clipping_depth = .2;
 #declare stbHFarch_brick_texture_offset=<0,0,4>;
 #declare stbHFarch_brick_texture =
 texture{
  pigment{
   cylindrical scale 3 rotate x*90
   turbulence .5 lambda 3
   color_map{[0 rgb 1][.5 rgb .5]}
  }
 }
 #declare stbHFarch_brick_pattern_offset = .5;
 #declare stbHFarch_brick_pattern =
 pigment_map{
  [0 rgb 0]
  [.2 rgb 1]
  [.5 rgb 1]
  [.7
   pigment_pattern{
    gradient z
    translate z/2
    pigment_map{
     [.5
      spherical scale 1.5
      warp{planar}
      scallop_wave frequency 2
      color_map{[0 rgb .5][1 rgb .9]}
     ]
     [.5
      boxed scale 1.5
      warp{planar}
     ]
    }
    
   }
   color_map{[0 rgb .5][1 rgb 1]}
  ]
 }
 union{
  object{
   stbHFarch_brick_arch(9,4,180,7,1)
   translate y*10
  }
  
  stbHFarch_pillar(9,4,10,4,1)
  translate -y*8.75
  rotate -y*45 rotate -x*15
 }
 stbHFarch_reset_values()
#end

// single arch brick with mirroring, clipping,
// and custom pattern
#macro stbHFarch_object5()
 #declare stbHFarch_brick_res = <300,300>;
 #declare stbHFarch_brick_mirror = yes;
 #declare stbHFarch_brick_clipping_depth = .1;
 #declare stbHFarch_brick_pattern =
 pigment_map{
  [0 rgb 0]
  [.2 rgb 1]
  [.4 rgb 1]
  [.6
   boxed scale .5 translate (x+y)/2
   warp{repeat x flip x}
   warp{repeat y flip y}
   scale 5
   translate y*1
   color_map{[0 rgb .75][.1 rgb .75][.2 rgb 0]}
  ]
 }
 object{
  stbHFarch_single_brick(10,7,7,.5)
  translate -y*6.5
  rotate -y*45 rotate -x*15
  pigment{rgb 1}
  scale 2.5
 }
 stbHFarch_reset_values()
#end

// single pillar brick with mirroring, clipping,
// and custom pattern
#macro stbHFarch_object6()
 #declare stbHFarch_brick_res = <300,300>;
 #declare stbHFarch_brick_mirror = yes;
 #declare stbHFarch_brick_clipping_depth = .1;
 #declare stbHFarch_brick_pattern =
 pigment_map{
  [0 rgb 0]
  [.1 rgb .75]
  [.7
   granite scale 7 translate 2
   sine_wave frequency 2
   color_map{[0 rgb .75][1 rgb 1]}
  ]
 }
 object{
  stbHFarch_single_pillar_brick(7,4,1)
  translate -y*2
  rotate -y*45 rotate -x*15
  pigment{rgb 1}
  scale 2.5
 }
 stbHFarch_reset_values()
#end


object{stbHFarch_object1()}
//object{stbHFarch_object2()}
//object{stbHFarch_object3()}
//object{stbHFarch_object4()}
//object{stbHFarch_object5()}
//object{stbHFarch_object6()}
