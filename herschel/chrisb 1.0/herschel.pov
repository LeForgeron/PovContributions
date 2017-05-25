//
// herschel.pov
// ------------
// Created by Chris Walker 2001  
// Adapted to go into the POV-Ray Object Collection Sept 2009 by Chris Bartlett
// This scene file illustrates the use of the 'herschel.inc' file which adds a 40ft
// telescope to your scene. 
//
// Although Heschel made over 300 telescopes, this was the largest, measuring 40 ft.
// Other telescopes and many other astronomical features have been named after him in 
// recognition of his achievements.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 0.5 metres
//
// Adding this model to your scene is likely to add a few seconds to the render time.
//
// See herschel.html for more details.
// 

//camera {location <15,1.5,-2> look_at 2*y} 

camera {
//    Uncomment this location statement and comment out the other location statement to have an animated sequence
//    You will also need to change your POVRAY.INI file to include the lines
//    Initial_Frame=1
//    Final_Frame=60
//    location <60*sin(clock*360/60), 9, 60*cos(clock*360/60)>
  location <50, 10, -35>
  look_at <0, 10,  0>
  angle 36
} 

#include "herschel.inc"

#include "colors.inc"  

light_source { <500, 1000, -300> White }

#declare GrassTexture = texture {
  pigment { granite turbulence 0.5 lambda 2 omega 1.8
    color_map {
      [0   color rgb <1,0.6,0.4>]
      [0.3 color rgb <0,0.2,0>]
      [0.7 color rgb <0,0.2,0>]
      [0.9 color rgb <1,0.6,0.4>*0.4]
    }
  }
  normal {
    average
    normal_map {
      [0.5  granite scale 0.1]
      [1.0  agate scale <0.01,0.05,0.01>]
      [2.0  bumps ]
      [1.0  bumps scale 0.2]
    }
  }
  finish {ambient 0}
}

plane { y, 0 texture {GrassTexture}} 

#declare Sky = sky_sphere {
  pigment {
    gradient y
    color_map {
      [0.75  color CornflowerBlue]
      [1.00  color MidnightBlue]
    }
    scale 2
    translate <-1, -1, -1>
  }
  pigment {
    bozo
    turbulence 0.6
    octaves 7
    omega .49876
    lambda 2.5432
    color_map {
      [0.0 color rgbf<.75, .75, .75, 0.1>]
      [0.4 color rgbf<.9, .9, .9, .9>]
      [0.7 color rgbf<1, 1, 1, 1>]
    }
    scale 6/10
    scale <1, 0.3, 0.3>
  }
  pigment {
    bozo
    turbulence 0.6
    octaves 8
    omega .5123
    lambda 2.56578
    color_map {
      [0.0 color rgbf<.375, .375, .375, 0.2>]
      [0.4 color rgbf<.45, .45, .45, .9>]
      [0.6 color rgbf<0.5, 0.5, 0.5, 1>]
    }
    scale 6/10
    scale <1, 0.3, 0.3>
  }
}

sky_sphere { Sky }