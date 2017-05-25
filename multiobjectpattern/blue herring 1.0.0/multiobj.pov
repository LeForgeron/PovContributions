// Title:        MultiObjectPattern demo scene
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
#declare Use_HQ_Blur = yes;  // Very time consuming, final render only.

#declare Save_Radiosity = yes;
#declare Load_Radiosity = yes;

#declare Radiosity_File = "multiobj.rad";

#if(Use_Radiosity)
  #default { finish { ambient 0 diffuse 1 } }
#end

#include "colors.inc"
#include "math.inc"
#include "multiobj.inc"
#include "rad_def.inc"
#include "rand.inc"
#include "transforms.inc"

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
        #if(Load_Radiosity & file_exists(Radiosity_File))
          load_file Radiosity_File
          pretrace_start 1
          pretrace_end 1
          always_sample no
        #else
          #if(Save_Radiosity)
            save_file Radiosity_File
          #end
        #end
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
  look_at <0, 2, -2>
  #if(Use_Blur)
    aperture 0.125
    focal_point <0, 2.1, -3>
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
    adaptive 1
    circular
    orient
  #end
}

background { rgb <0.8, 0.8, 1> }

plane {
  y, 0
  pigment { NewTan }
}

plane {
  -z, -5.5
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
  
  
#declare Vase_Obj =
  lathe {
    bezier_spline
    52 //nr points
    /*   0*/ <0.06250000, 0.06253324>, <0.06250000, 0.06253324>, <3.66211500, 0.06253324>, <3.66211500, 0.06253324>,
    /*   1*/ <3.66211500, 0.06253324>, <4.21193530, 0.06253324>, <4.10374440, 1.18653324>, <3.66211500, 1.22473324>,
    /*   2*/ <3.66211500, 1.22473324>, <3.01858640, 1.28033324>, <3.25436170, 1.23713324>, <2.56247450, 1.22473324>,
    /*   3*/ <2.56247450, 1.22473324>, <1.84910600, 1.21193324>, <3.00515900, 2.15113324>, <3.66211500, 7.27273324>,
    /*   4*/ <3.66211500, 7.27273324>, <4.14368910, 11.02703324>, <2.19450810, 10.36183324>, <2.56247450, 11.67133324>,
    /*   5*/ <2.56247450, 11.67133324>, <2.67960490, 12.08813324>, <3.02302650, 12.00563324>, <3.11229480, 12.22113324>,
    /*   6*/ <3.11229480, 12.22113324>, <3.14741210, 12.30593324>, <3.15059770, 12.55473324>, <3.09172680, 12.68053324>,
    /*   7*/ <3.09172680, 12.68053324>, <3.04477900, 12.78093324>, <2.99763090, 12.77093324>, <2.93588880, 12.77093324>,
    /*   8*/ <2.93588880, 12.77093324>, <2.93588880, 12.77093324>, <2.34524710, 12.79143324>, <2.17839620, 12.7735334>,
    /*   9*/ <2.17839620, 12.77353324>, <1.89226190, 12.74263324>, <2.05361860, 12.28753324>, <2.04280530, 11.70083324>,
    /*  10*/ <2.04280530, 11.70083324>, <2.02762170, 10.87693324>, <3.90439420, 9.96963324>, <3.32421060, 7.33033324>,
    /*  11*/ <3.32421060, 7.33033324>, <2.88955710, 5.34633324>, <2.78246860, 3.49993324>, <2.03273150, 1.57203324>,
    /*  12*/ <2.03273150, 1.57203324>, <1.72732200, 0.78673324>, <0.08744755, 0.97333324>, <0.08744755, 0.97333324>
    scale 0.25
  }
  
#declare Vase_Max = max_extent(Vase_Obj);
#declare R = seed(13);

//#debug concat(vstr(3, Vase_Max, ", ", 0, 2), "\n")

#declare Z = trace(Vase_Obj, <0, Vase_Max.y/2, -10>, z);
#declare Count = 31;

#declare Vase_Design_Squiggle =
  sphere_sweep {
    linear_spline
    Count,
    #declare Ct = 0;
    #while(Ct < Count)
      vrotate(Z, y * 360/(Count-1) * Ct) + y * (even(Ct) ? 0.1 : -0.1), 0.05
      #declare Ct = Ct + 1;
    #end
  }

#declare Count = 10;
#declare Ct = 0;
#declare Vine = array[Count];
#while(Ct < Count)
  #declare Y = Vase_Max.y * 4/5 + RRand(-0.12, 0.12, R);
  #declare Pt = trace(Vase_Obj, <0, Y, -10>, z);
  #declare Vine[Ct] = vrotate(Pt, y * 360/(Count - 2) * Ct);
  #declare Ct = Ct + 1;
#end

#declare Leaf =
  intersection {
    cylinder { 
      -z, z, 0.2
      translate x * -0.1
    }
    cylinder { 
      -z, z, 0.2
      translate x * 0.1
    }
    translate y * 0.16
  }
  
#declare Vase_Design_Vine =
  sphere_sweep {
    cubic_spline
    Count,
    #declare Ct = 0;
    #while(Ct < Count)
      Vine[Ct], 0.02
      #declare Ct = Ct + 1;
    #end
    rotate y * 180
  }
      
#declare Vase_Design_Leaves =
  union {
    #declare Ct = 1;
    #while(Ct < Count - 1)
      object {
        Leaf
        #if(odd(Ct))
          scale <1, -1, 1>
          rotate z * RRand(-45, 0, R)
        #else
          rotate z * RRand(0, 45, R)
        #end
        translate Vine[Ct]
      }
      #declare Ct = Ct + 1;
    #end
    rotate y * 180
  }
  
#declare Vase_Design_Stripes =
  union {
    #declare Z = trace(Vase_Obj, <0, Vase_Max.y/2, -10>, z);
    #declare Count = 15;
    #declare Ct = 0;
    #while(Ct < Count)
      box {
        <-0.025, -0.5, -1>, <0.025, 0.5, 1>
        Shear_Trans(x, vrotate(y, z * 22.5), z)
        translate z * Z.z
        rotate y * 360/Count * Ct
      }
      #declare Ct = Ct + 1;
    #end
  }
  
#declare Vase_Design_Blue_Stripes =
  union {
    object {
      Vase_Design_Stripes
      translate y * Z.y
    }
    cylinder { y * (Z.y - 0.5), y * (Z.y - 0.4), 5 }
    cylinder { y * (Z.y + 0.4), y * (Z.y + 0.5), 5 }
  }
  
#declare Vase_Design_Red_Stripes = 
  object {
    Vase_Design_Stripes
    scale <1, -1, 1>
    translate y * Z.y
  }
  
#declare Vase_Design_Lattice_1 =
  union {
    #declare Count = 12;
    #declare Ct = 0;
    #while(Ct < Count)
      box { 
        <-0.015, 0, -5>, <0.015, 0.75, 0> 
        rotate y * 360/Count * Ct
      }
      #declare Ct = Ct + 1;
    #end
    translate y * 2.15
  }
  
#declare Vase_Design_Lattice_2 =
  union {
    object {
      Vase_Design_Lattice_1
      rotate y * (360/Count)/2
    }
    cylinder { y * 2.15, y * 2.2, 5 }
    cylinder { y * 2.25, y * 2.3, 5 }
    cylinder { y * 2.75, y * 2.8, 5 }
    cylinder { y * 2.85, y * 2.9, 5 }
  }

#declare Vase_Designs =
  array[7] {
    Vase_Design_Red_Stripes,
    Vase_Design_Squiggle,
    Vase_Design_Blue_Stripes,
    Vase_Design_Lattice_1,
    Vase_Design_Vine,
    Vase_Design_Lattice_2,
    Vase_Design_Leaves
  }

#declare Chip_F =
  function {
    pattern {
      cells
      scale 0.6
      warp { turbulence 0.8 }
    }
  }
  
#declare Vase_Shiny_T =
  texture {
    pigment {
      MultiObj_Ptrn(Vase_Designs)
      color_map {
        [0   Tan]
        [1/7 Firebrick]
        [2/7 Yellow]
        [3/7 Navy]
        [4/7 DarkBrown]
        [5/7 DarkGreen]
        [6/7 DarkBrown]
        [1   DarkGreen]
      }
    }
    finish {
      specular 0.9
      roughness 0.0001
      reflection {
        0, 0.3
        fresnel
      }
      conserve_energy
    }
  }
  
#declare Vase_Rough_T =
  texture {
    pigment { Tan * 1.2 }
    normal { 
      granite -0.7
      poly_wave 4
      scale 0.5
    }
  }

#declare Vase_Pitted_T =
  texture {
    granite
    texture_map {
      [0    Vase_Shiny_T]
      [0.2  Vase_Shiny_T]
      [1    Vase_Rough_T]
    }
  }

#declare Vase = 
  object {
    Vase_Obj
    texture { Vase_Pitted_T }
    interior {
      ior 1.51
    }
  }

object {
  Pedestal
}

object {
  Vase
  translate <0, 1, -2>
}
