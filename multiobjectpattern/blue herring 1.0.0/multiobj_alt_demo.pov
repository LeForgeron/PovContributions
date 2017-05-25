// Title:        MultiObjectPattern alternate demo scene
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 19, 2008
// Last updated: June 24, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#declare Use_Radiosity = yes;
#declare Use_HQ_Radiosity = yes;
#declare Use_Area = yes;
#declare Use_Blur = yes;
#declare Use_HQ_Blur = yes; // Very time consuming, final render only.

#if(Use_Radiosity)
  #default { finish { ambient 0 diffuse 1 } }
#end

#include "colors.inc"
#include "golds.inc"
#include "math.inc"
#include "metals.inc"
#include "multiobj.inc"
#include "rad_def.inc"
#include "shapes.inc"

global_settings {
  assumed_gamma 1.0
  max_trace_level 6
  #if(Use_Radiosity)
    radiosity {
      #if(Use_HQ_Radiosity)
        pretrace_start 0.08
        pretrace_end   0.002
        count 600
        nearest_count 7
        error_bound 0.4
        recursion_limit 1
        low_error_factor 0.6
        gray_threshold 0
        minimum_reuse 0.013
        brightness 0.6
        adc_bailout 0.01/3
        normal no
        media no
      #else
        Rad_Settings(Radiosity_Fast, no, no)
        brightness 0.7
      #end
    }
  #end
}

camera {
  location <0, 5, -8>
  up y
  right x * image_width/image_height
  look_at 0
  #if(Use_Blur)
    aperture 0.125
    focal_point <0, 1, -1>
    #if(Use_HQ_Blur)
      blur_samples 512
      confidence 0.98
      variance 1/100000
    #else
      blur_samples 100
      confidence 0.9
      variance 1/10000
    #end
  #end
}

#declare Cool_Daylight = rgb <255, 238, 222>/255;


light_source {
  <10, 6, -12>, Cool_Daylight * (Use_Radiosity ? 0.6 : 1)
  #if(Use_Area)
    area_light
    x * 6, y * 6, 17, 17
    adaptive 0
    circular
    orient
  #end
}

background { rgb <0.8, 0.8, 1> }

plane {
  y, 0
  pigment { NewTan }
}

#if(Use_Radiosity)
  sphere {
    0, 10000
    inverse
    no_reflection
    texture {
      pigment { Cool_Daylight }
      finish {
        ambient 1
        diffuse 0
      }
    }
  }
#end

#declare Shiny_Metal_F = 
  finish {
    ambient 0
    diffuse 0.05
    specular 1.9
    roughness 0.005272
    metallic
    reflection {
      0.475, 0.95
      metallic
    }
    conserve_energy
    brilliance 5
  }

#declare Crinkly_N =  
  normal { 
    dents -1
    scale 0.02
  }
  
#declare Shiny_Gold =
  texture {
    pigment { P_Gold1 }
    finish { Shiny_Metal_F }
  }

#declare Crinkly_Gold =
  texture {
    Shiny_Gold
    normal { Crinkly_N }
  }
  
#declare Shiny_Silver =
  texture {
    pigment { P_Silver2 }
    finish { Shiny_Metal_F }
  }    
  
#declare Rippled_Silver =
  texture {
    Shiny_Silver
    normal {
      function { sin(sqrt(f_sqr(x*8) + f_sqr(y*8)) * pi) }
    }
  }
  
#declare Shiny_Copper =
  texture {
    pigment { P_Copper3 }
    finish { Shiny_Metal_F }
  }
  
#declare Plastic_Base =
  texture {
    pigment { rgb <0.5, 0.5, 0.7> }
    finish {
      specular 0.75
      roughness 0.05
      reflection {
        0, 0.125
      }
      conserve_energy
    }
  }
  
#declare Rippled_Base =
  texture {
    Plastic_Base
    normal {
      gradient z, -1
      triangle_wave
      scale 0.075
    }
  }
  
#declare Pearl =
  texture {
    pigment { rgb <170, 171, 183>/255 }
    finish {
      specular 0.75
      roughness 0.001
      irid {
        0.4
        thickness 0.8
        turbulence 0.15
      }
      reflection {
        0.1, 0.25
      }
      conserve_energy
    }
    normal {
      bozo 0.5
      scale 0.5
    }
  }
  
#declare Gizmo_Copper_Obj =
  union {
    sphere { <-1, 1, -1>, 0.5 }
    sphere { <1, -1, -1>, 0.5 }
    sphere { <-1, 1, 1>, 0.5 }
    sphere { <1, -1, 1>, 0.5 }
    cylinder { z * -3, z * 3, 0.5 }
  box {
    <-3, -0.025, -3>, <3, 0.025, 3> 
    rotate z * -45
  }
  }
  
#declare Gizmo_Silver_Obj =
  union {
    sphere { <-1, 1, -1>, 0.45 }
    sphere { <1, -1, -1>, 0.45 }
    sphere { <-1, 1, 1>, 0.45 }
    sphere { <1, -1, 1>, 0.45 }
  }

#declare Gizmo_RSilver_Obj = cylinder { z * -3, z * 3, 0.45 }
  
#declare Gizmo_RBase_Obj = cylinder { <1, 1, -0.8>, <1, 1, 0.8>, 0.45 }

#declare Gizmo =  
  superellipsoid {
    <0.2, 0.2>
    texture {
      MultiObj_Ptrn_4(Gizmo_RBase_Obj, Gizmo_Copper_Obj, Gizmo_Silver_Obj, Gizmo_RSilver_Obj)
      texture_map {
        [0   Plastic_Base]
        [1/4 Rippled_Base]
        [2/4 Shiny_Copper]
        [3/4 Shiny_Silver]
        [1   Rippled_Silver]
      }
    }
    rotate z * 90
    translate y
  }
  
#declare Flower_Obj =
  union {
    #declare Count = 6;
    #declare Ct = 0;
    #while(Ct < Count)
      object {
        Round_Cone3_Union(y * 0.25, 0.1, y * 0.5, 0.22)
        rotate z * 360/Count * Ct
      }
      #declare Ct = Ct + 1;
    #end
    sphere { 0, 0.17 }
  }
  
#declare Flower_Block =
  superellipsoid {
    <0.15, 0.15>
    texture {
      Pearl
      pigment {
        MultiObj_Ptrn_6(
          object {
            Flower_Obj
            translate -z
          },
          object {
            Flower_Obj
            translate z
          },
          object {
            Flower_Obj
            translate z
            rotate y * -90
          },
          object {
            Flower_Obj
            translate z
            rotate y * 90
          },
          object {
            Flower_Obj
            translate z
            rotate x * -90
          },
          object {
            Flower_Obj
            translate z
            rotate x * 90
          }
        )
        color_map {
          [0 rgb <170, 171, 183>/255]
          [1/6 Red]
          [2/6 Orange]
          [3/6 Blue]
          [4/6 Med_Purple]
          [5/6 Yellow]
          [1   NeonPink]
        }
      }
    }
    translate y
  }
  
#declare Pedestal_Spiral =
  prism {
    bezier_spline
    -1, 1,
    104 //nr points
    /*   0*/ <0.00981715, 11.54124453>, <0.00981715, 8.41624463>, <0.00981715, 5.29124473>, <0.00981715, 2.16624453>,
    /*   1*/ <0.00981715, 2.16624453>, <2.71815045, 2.16624453>, <5.42648385, 2.16624453>, <8.13481715, 2.16624453>,
    /*   2*/ <8.13481715, 2.16624453>, <8.13481715, 4.73917803>, <8.13481715, 7.31211133>, <8.13481715, 9.88504463>,
    /*   3*/ <8.13481715, 9.88504463>, <5.97856715, 9.88504463>, <3.82231715, 9.88504463>, <1.66606715, 9.88504463>,
    /*   4*/ <1.66606715, 9.88504463>, <1.66606715, 7.93711133>, <1.66606715, 5.98917803>, <1.66606715, 4.04124473>,
    /*   5*/ <1.66606715, 4.04124473>, <3.27023385, 4.04124473>, <4.87440055, 4.04124473>, <6.47856715, 4.04124473>,
    /*   6*/ <6.47856715, 4.04124473>, <6.47856715, 5.50997803>, <6.47856715, 6.97871143>, <6.47856715, 8.44744473>,
    /*   7*/ <6.47856715, 8.44744473>, <5.42648385, 8.44744473>, <4.37440055, 8.44744473>, <3.32231715, 8.44744473>,
    /*   8*/ <3.32231715, 8.44744473>, <3.32231715, 7.53077803>, <3.32231715, 6.61411133>, <3.32231715, 5.69744473>,
    /*   9*/ <3.32231715, 5.69744473>, <3.90565055, 5.69744473>, <4.48898385, 5.69744473>, <5.07231715, 5.69744473>,
    /*  10*/ <5.07231715, 5.69744473>, <5.07231715, 5.98911133>, <5.07231715, 6.28077803>, <5.07231715, 6.57244473>,
    /*  11*/ <5.07231715, 6.57244473>, <4.78065055, 6.57244473>, <4.48898385, 6.57244473>, <4.19731715, 6.57244473>,
    /*  12*/ <4.19731715, 6.57244473>, <4.19731715, 6.90577803>, <4.19731715, 7.23911133>, <4.19731715, 7.57244473>,
    /*  13*/ <4.19731715, 7.57244473>, <4.66606715, 7.57244473>, <5.13481715, 7.57244473>, <5.60356715, 7.57244473>,
    /*  14*/ <5.60356715, 7.57244473>, <5.60356715, 6.68704473>, <5.60356715, 5.80164473>, <5.60356715, 4.91624473>,
    /*  15*/ <5.60356715, 4.91624473>, <4.58273385, 4.91624473>, <3.56190055, 4.91624473>, <2.54106715, 4.91624473>,
    /*  16*/ <2.54106715, 4.91624473>, <2.54106715, 6.29124473>, <2.54106715, 7.66624473>, <2.54106715, 9.04124473>,
    /*  17*/ <2.54106715, 9.04124473>, <4.11398385, 9.04124473>, <5.68690055, 9.04124473>, <7.25981715, 9.04124473>,
    /*  18*/ <7.25981715, 9.04124473>, <7.25981715, 7.04124473>, <7.25981715, 5.04124473>, <7.25981715, 3.04124453>,
    /*  19*/ <7.25981715, 3.04124453>, <5.12440055, 3.04124453>, <2.98898385, 3.04124453>, <0.85356717, 3.04124453>,
    /*  20*/ <0.85356717, 3.04124453>, <0.85356717, 5.59331133>, <0.85356717, 8.14537793>, <0.85356717, 10.69744443>,
    /*  21*/ <0.85356717, 10.69744443>, <3.61398385, 10.69744443>, <6.37440055, 10.69744443>, <9.13481715, 10.69744443>,
    /*  22*/ <9.13481715, 10.69744443>, <9.13481715, 7.13497773>, <9.13481715, 3.57251103>, <9.13481715, 0.01004453>,
    /*  23*/ <9.13481715, 0.01004453>, <9.42648385, 0.01004453>, <9.71815055, 0.01004453>, <10.00981705, 0.01004453>,
    /*  24*/ <10.00981705, 0.01004453>, <10.00981705, 3.85377773>, <10.00981705, 7.69751113>, <10.00981705, 11.54124453>,
    /*  25*/ <10.00981705, 11.54124453>, <6.67648385, 11.54124453>, <3.34315045, 11.54124453>, <0.00981715, 11.54124453>
    rotate x * -90
    translate <-5, -5, 0>
    scale <1/20, 1/20, 1>
  }
  
#declare Pedestal_Design_1 =
  union {
    box { <-6, 0.7, -6>, <6, 0.8, 6> }
    
    #declare Count = 15;
    #declare Ct = 0;
    #while(Ct < Count)
      object {
        Pedestal_Spiral
        rotate z * 180
        translate <0, 0.5, -4>
        rotate y * 360/Count * Ct
      }
      #declare Ct = Ct + 1;
    #end
  }
  
#declare Pedestal_Design_2 =
  object {
    Pedestal_Design_1
    rotate z * 180
    translate y * 0.8
    rotate y * (360/Count)/2
  }

#declare Pedestal =
  superellipsoid {
    <1, 0.1>
    rotate x * 90
    scale 4
    translate y * -3
    pigment {
      MultiObj_Ptrn_2(Pedestal_Design_1, Pedestal_Design_2)
      color_map {
        [0   NewTan]
        [1/2 DarkTan]
        [1   Firebrick]
      }
    }
  }
  
object {
  Pedestal
}

object {
  Gizmo
  rotate y * -45
  translate <-1.8, 1, -1>
}

object {
  Flower_Block
  rotate y * 45
  translate <1.8, 1, -1>
}
