// lrchairs_example.pov version 1.1
// Persistence of Vision Ray Tracer scene description file
// Demo of lrchairs.inc from the POV-Ray Object Collection
//
// Cheap Texture Chair macro(Ftex,Stex)
// chair faces the -z direction
// zero point is in between back legs
//
// Copyright 2008 Leroy Whetstone Email llrwii@joplin.com  Some rights reserved.
// Modified by Richard Callwood III.
// This file is licensed under the terms of the CC-LGPL
// See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
//
// Vers  Date        Comments                                       Author
// ----  ----        --------                                       ------
// 1.0   2008-08-21  Initial version.                               L. Whetstone
// 1.0A  2008-08-21  A typo is fixed.                               L. Whetstone
// 1.1   2014-12-31  POV-Ray version is added.                      R. Callwood

/* POV-Ray 3.5 or 3.6:
 *  // +a0.1
 * POV-Ray 3.7:
 *  // +a0.1 +ag1.0
 */
#version 3.5;

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

#include "lrchairs.inc"
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

