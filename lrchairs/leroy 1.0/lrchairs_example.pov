//This file is licensed under the terms of the CC-LGPL
// Cheap Texture Chair macro(Ftex,Stex)
//chair faces the -z direction 
//zero point is inbetween back legs
// Vers: 3.6
// Auth: Leroy Whetstone Email llrwii@joplin.com

#include "colors.inc"
camera{ location <0,4,-6>
        look_at <0,1,0>
        right x*image_width/image_height
        //angle 50
        }
 light_source{<4,30,0> color White}
 light_source{<0,10,-10> color White}
 light_source{<0,10,10> color White}

plane{y,0 pigment{Green*.4}}

#include "Cp_Chairs.inc"
//----------test textures---------------
 //frame textures
 #declare F1=texture{pigment{rgb<.5,.4,.2>}
             finish{specular.4 roughness.001 metallic.5}}
 #declare F2=texture{pigment{rgb<.2,.2,.25>}
             finish{specular.4 roughness.001 metallic.5}}
 #declare F3=texture{pigment{rgb<.7,.7,.75>}
             finish{specular.4 roughness.001 metallic.5}}
 //seat textures
 #declare S1=texture{pigment{bozo scale .01}
             normal{granite.1}
             finish{specular.8 roughness.001 metallic.65}}
 #declare S2=texture{pigment{Blue}
             normal{granite.1}
             finish{specular.8 roughness.001 metallic.65}}
 #declare S3=texture{pigment{Red}
             normal{agate.1}
             finish{specular.8 roughness.001 metallic.65}}
 //layered texture
 #declare L1=texture{pigment{rgb<.2,.2,.25>}
              normal{agate.1}
              finish{specular.8 roughness.001 metallic.65}}
             texture{
             pigment{agate color_map{[.7 Clear][.8 rgb<.7,.5,.2>]}scale.1}
             normal{agate.1}
             finish{specular.5 roughness.01 metallic.2}}
 

#declare Chair=object{Cp_Chair(F1,S1)}

  object{Chair translate -x*4}
  object{Chair translate -x*2}
  object{Chair translate 0}
  object{Chair translate x*2}
  object{Chair translate x*4}
  
 object{Cp_Chair(F1,S1)rotate <0,-5,0> translate <-5,0,5>}
 object{Cp_Chair(F2,S2)rotate <0,5,0> translate <-3,0,5>}
 object{Cp_Chair(F3,S3)rotate <0,-5,0> translate <-1,0,5>}
 object{Cp_Chair(pigment{Gold},S2)rotate <0,5,0> translate <1,0,5>}
 object{Cp_Chair(L1,pigment{Gold}) rotate <0,-5,0> translate <3,0,5>}
 object{Cp_Chair(pigment{Green},pigment{Blue}) rotate <0,5,0> translate <5,0,5>}
 
