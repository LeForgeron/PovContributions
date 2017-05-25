// WireFence.pov
// -------------

// Scene file illustrating the use of a simple gradient texture to create a wire mesh fence with concreate posts  
// Created by Chris Bartlett 07.02.2005
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time 5 seconds.
// Size is 2 POV-Ray units high running along the x-axis from x=-20 to x=20.

light_source { < -150, 1000  ,-800> color rgb 1}
//light_source { < 10, 4  ,-800> color rgb 1}
camera {location <0,1.5,-1.5> look_at <-2,1.5,0.4>} 
background {color rgb <0.8,0.8,1>} 

max_trace_level 12

#declare WF_FencePost = intersection { 
  box {-1.45,1.45 rotate <45,0,0>}
  box {-1.45,1.45 rotate <0,0,45>}
  box {<-0.05,0,-0.05><0.05,2.02,0.05>}
}

#declare WF_FenceTexture = texture{
  pigment{ gradient y turbulence 0.04
    color_map {
      [0.0  color rgbt<1,1,1,1>]
      [0.92 color rgbt<1,1,1,1>]
      [0.92 color rgb <1,1,1>]
      [1.0  color rgb <1,1,1>]
    }
  }
  normal {gradient y turbulence 0.04
    slope_map {
      [0    <0, 0>]
      [0.92 <0, 0>]
      [0.92 <0.15, 0.5>]
      [0.94 <0.25, 0.25>]
      [0.96 <0.35, 0>]
      [0.98 <0.25,-0.25>]
      [1    <0.15,-0.5>]
    }
  }
  scale 0.05
}

#declare WF_WireTexture = texture{
  pigment{ gradient y turbulence 0.04
    color_map {
      [0.0   color rgbt<1,1,1,1>]
      [0.996 color rgbt<1,1,1,1>]
      [0.996 color rgb <0.6,0.6,0.6>]
      [1.0   color rgb <0.6,0.6,0.6>]
    }
  }
  normal {gradient y turbulence 0.04
    slope_map {
      [0     <0, 0>]
      [0.996 <0, 0>]
      [0.996 <0.15, 0.5>]
      [0.997 <0.25, 0.25>]
      [0.998 <0.35, 0>]
      [0.999 <0.25,-0.25>]
      [1     <0.15,-0.5>]
    }
  }  
  scale 0.94
  translate y*0.08
}

plane {z,0 clipped_by {box {<-20,0,-0.01><20,2,0.01>}}
  texture {WF_FenceTexture rotate  z*45} 
  texture {WF_FenceTexture rotate -z*45}
  texture {WF_WireTexture}
} 

#local WF_I = -20;
#while (WF_I<21)
  object {WF_FencePost texture {pigment {rgb <1,1,0.6>} normal {granite scale 0.03}} translate <WF_I,0,-0.05>}
  #local WF_I = WF_I + 3;
#end

plane {y,0 texture {pigment {color rgb <0.6,1,0.6>} normal {bozo turbulence 1 scale <0.003,1,0.003>}}}
