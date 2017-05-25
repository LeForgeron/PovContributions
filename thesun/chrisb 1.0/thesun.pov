// TheSun.pov
// ------------

// Simple scene that uses a gradient to create a repeating Sun texture that is displayed on a sphere
// Created by Chris Bartlett 20.09.2007
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time 1 second
// Radius is 1 POV-Ray unit
// Positioned at the origin

// To animate, use command line options +kfi0 +kff30

camera{location <0,0,-2.28> look_at 0}

#declare TheSun_BasePigment = pigment {
  bumps turbulence 0.5
  pigment_map {
    [0.0 color rgb<0.7,0.35,0>]
    [0.5 color rgb<1,0.8,0>]
    [1.0 color rgb<0.7,0.35,0>]
  }
}

#declare TheSun_Pigment = pigment {
  gradient z
  pigment_map {
    [0.0, TheSun_BasePigment scale 0.05]
    [0.2, TheSun_BasePigment scale 0.05 translate z*0.2]
    [0.4, TheSun_BasePigment scale 0.05 translate z*0.4]
    [0.6, TheSun_BasePigment scale 0.05 translate z*0.6]
    [0.8, TheSun_BasePigment scale 0.05 translate z*0.8]
    [1.0, TheSun_BasePigment scale 0.05 translate z*1.0]
  }
  scale 5*z
}

sphere {<0,0,0>,1 
  pigment {TheSun_Pigment translate <0,0,-3+clock>}
  finish{ambient 1.2}
}
