// Copyright David Barnard, 1994, 2008
// This file is licensed under the terms of the CC-LGPL   

#include "shapes.inc"
#include "colors.inc"
#include "textures.inc"

#declare Biro_Cap_Texture = texture {
  finish {
    specular 1
    roughness 0.003 
    phong 0.9
    phong_size 100
    diffuse 0.7
    reflection 0.1
  }
}  

#declare Biro_Body_Texture = texture {
  pigment {
    color Gray95 filter 0.9
    quick_color Red
  }
  finish {
    ambient 0.1
    diffuse 0.1
    reflection 0.1
    specular 0.8
    roughness 0.0003
    phong 1
    phong_size 200
  }
}   

#declare Biro_Body_Plastic = interior {
  ior 1.49
}

//Biro ----------------------------------------------------------------------
#macro Biro(Biro_Pigment)

#local Biro_Color = texture {
  Biro_Cap_Texture 
  pigment {Biro_Pigment} 
}

union {
difference {
merge {
difference {
object { cylinder {y,-y,1} }
        object { Plane_XY rotate <0,150,0> translate z } 
        object { Plane_XY rotate <0,30,0> translate -z }
        object { Plane_XY rotate <0,-150,0> translate z } 
        object { Plane_XY rotate <0,-30,0> translate -z }
        object { Plane_XY rotate <0,30,0> translate -z rotate <0,60,0>} 
        object { Plane_XY rotate <0,-30,0> translate -z rotate <0,-60,0>} 

rotate <0,0,90> scale <4.5,.45,.45>}
cylinder {<-4.49,0,0>,<-6.1,0,0>,.45}
cone {<4.49,0,0>,0.4 <6.4,0,0>,0.35}
torus {.25,.05 rotate <0,0,90> scale <2,1,1> translate <6.4,0,0>}
}
cone {<-6.11,0,0>,0.32 <6.3,0,0>,0.2}
cylinder {<6,0,0>,<7,0,0>,0.08}
texture { Biro_Body_Texture }
interior { Biro_Body_Plastic }
}

cylinder {<-6,0,0>,<6.25,0,0>,0.14
texture { Biro_Color}}

difference {
union {   
cone {<-6.1,0,0>,.43 <-6.6,0,0>,0.375}
torus {0.325,0.05 rotate <0,0,90> translate <-6.6,0,0>}
cone {<-6.65,0,0>,0.325 <-7.7,0,0>,0.2}
torus {0.15, 0.05 rotate <0,0,90> translate <-7.7,0,0>}
cylinder {<-7.75,0,0>, <-7.7,0,0>, 0.15}
cylinder {<-5.2,0,0>, <-6.11,0,0>,0.3} 
torus {0.3,0.025 rotate <0,0,90> translate <-5.3,0,0>}
torus {0.3,0.025 rotate <0,0,90> translate <-5.5,0,0>}         
torus {0.3,0.025 rotate <0,0,90> translate <-5.7,0,0>}
torus {0.3,0.025 rotate <0,0,90> translate <-5.9,0,0>}         
cone {<-5.2,0,0>,.3 <-5.1,0,0>,0.25}
}
cylinder {<-5,0,0>, <-6.1,0,0>, 0.25}
texture { Biro_Color}
}

union {
cylinder {<-7.75,0,0>, <-7.9,0,0>, 0.1}
cone {<-7.9,0,0>, 0.1 <-8.15,0,0>, 0.05}
sphere {<-8.15,0,0>, 0.05}
texture { New_Brass }
}

sphere {<-8.17,0,0>, 0.0375
texture { Chrome_Texture }
}
scale <10,10,10>
}    

#end

//Cap -----------------------------------------------------------------------
#macro Biro_Cap(Biro_Pigment)

#local Biro_Color = texture {
  Biro_Cap_Texture
  pigment {Biro_Pigment} 
}

union {
difference {
union {
intersection {
object {
Paraboloid_X }
box {<0.81,-1,-1>,<1,1,1>}
translate <-1,0,0> scale <20.526,.5,.5>
}


torus {0.35,0.09 scale <1,5,1>
                rotate <0,0,90>
                translate <-3.9,0,0>}

cylinder {<-4.37,0,0>,<-4,0,0>,0.35}

difference {
intersection {
object {
Paraboloid_X translate <-.8,0,0> scale <20.526, .7,.7>}
box {<-3.6,0,-.25>,<2.2,2,.25>}}
box {<-3.61,0.5,-.15>,<-.1,1,.15>}
box {<0,0.6,-1>,<3,1,1>}
box {<0,0.6,-1>,<3,1,1> rotate <0,0,-10> translate <1.9,0,0>
}}

cylinder {<0,0,0>, <-0.1,0,0>, 0.55}

box {<-0.1,0.3,-0.3>,<0,0.65,0.3>}
}
cone {<-4.4,0,0>,0.25<0.01,0,0>,0.45}
cylinder {<0,0,0>, <3,0,0>, 0.5}
}
box {<-4.32,-0.3,-0.05>,<-4.27,0.3,0.05>}
box {<-4.32,-0.05,-0.3>,<-4.27,0.05,0.3>}

texture { Biro_Color }
translate <-5,0,0>
scale <10,10,10>
}

#end