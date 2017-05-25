
// GridLines.pov
// -------------

// Scene file illustrating the generation of a texture to draw grid lines on a spherical surface 
// Created by Chris Bartlett 07.02.2005 
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time about 20 seconds.
// This example renders the texture on a sphere of 1 POV-Ray unit radius centred at the origin.

#include "math.inc"
#declare GL_YourObject = sphere {0,1}

#declare GL_LineTexture = texture {
  pigment {  
    gradient x
    turbulence 0
    color_map {
      [0      rgbt <0,1,0,0>]
      [0.001  rgbt <0,1,0,0>]
      [0.001  rgbt <1,1,1,1>]
      [1      rgbt <1,1,1,1>]
    }
  }
  scale 10
}

#declare GL_WireframeTexture = texture {GL_LineTexture}

#local GL_I = 0;
#while (GL_I<180)
  #declare GL_WireframeTexture = 
    texture {GL_WireframeTexture}
    texture {GL_LineTexture rotate y*GL_I}  
  #local GL_I = GL_I + 10;
#end 

#local GL_I = -80;
#while (GL_I<90)
  #declare GL_WireframeTexture = 
    texture {GL_WireframeTexture}
    texture {GL_LineTexture rotate z*90 scale 2*y*(1-abs(sind(GL_I)/1.1)) translate y*sind(GL_I)}  
  #local GL_I = GL_I + 10;
#end

object {GL_YourObject texture {GL_WireframeTexture}}

camera {location <0,2,-2> look_at 0}
light_source { <100, 1000, -2000> color rgb 1}
