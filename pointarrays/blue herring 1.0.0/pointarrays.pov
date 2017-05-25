// Title:        PointArrays demo scene
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 5, 2008
// Last updated: June 5, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#default { finish { ambient 0 diffuse 1 } }

#include "colors.inc"
#include "pointarrays.inc"

global_settings {
  assumed_gamma 1.0
  radiosity {
    pretrace_start 0.08
    pretrace_end   0.005
    //count 50
    count 100
    nearest_count 14
    error_bound 0.6
    recursion_limit 1
    low_error_factor 0.7
    gray_threshold 0
    minimum_reuse 0.025
    brightness 1.0
    adc_bailout 0.01/2
    normal off      
    media off
  }
}

#declare PA_Shooting_Star =
  array[120] {
    /*   0*/ <2.75857400, 6.80963501>, <2.74119020, 6.80863501>, <2.72414490, 6.80603501>, <2.70662490, 6.80173501>,
    /*   1*/ <2.70662490, 6.80173501>, <2.14598590, 6.66293501>, <2.46084900, 5.01763501>, <2.08888210, 4.57583501>,
    /*   2*/ <2.08888210, 4.57583501>, <1.71691520, 4.13393501>, <0.04196942, 4.16373501>, <0.00075330, 3.58763501>,
    /*   3*/ <0.00075330, 3.58763501>, <-0.04046282, 3.01163501>, <1.62211020, 2.80293501>, <1.92738810, 2.31263501>,
    /*   4*/ <1.92738810, 2.31263501>, <2.23266590, 1.82233501>, <1.68584760, 0.23853501>, <2.22101360, 0.02123501>,
    /*   5*/ <2.22101360, 0.02123501>, <2.75617960, -0.19586499>, <3.46842960, 1.32003501>, <4.02906870, 1.45883501>,
    /*   6*/ <4.02906870, 1.45883501>, <4.58970750, 1.59773501>, <5.92705240, 0.58903501>, <6.29901930, 1.03083501>,
    /*   7*/ <6.29901930, 1.03083501>, <6.55237890, 1.33183501>, <6.06624170, 1.95963501>, <5.74338960, 2.51143501>,
    /*   8*/ <5.74338960, 2.51143501>, <11.87763700, 3.80123501>, <17.97402000, 2.03713501>, <17.97402000, 2.03713501>,
    /*   9*/ <17.97402000, 2.03713501>, <18.11591400, 1.99573501>, <18.26456600, 2.07703501>, <18.30604200, 2.21893501>,
    /*  10*/ <18.30604200, 2.21893501>, <18.34751900, 2.36083501>, <18.26611500, 2.50953501>, <18.12422000, 2.55103501>,
    /*  11*/ <18.12422000, 2.55103501>, <18.12422000, 2.55103501>, <14.97830300, 3.47623501>, <10.88635200, 3.52333501>,
    /*  12*/ <10.88635200, 3.52333501>, <9.20387280, 3.54273501>, <7.36133210, 3.41253501>, <5.51187720, 3.00953501>,
    /*  13*/ <5.51187720, 3.00953501>, <5.49430770, 3.07573501>, <5.48637760, 3.13813501>, <5.49042000, 3.19463501>,
    /*  14*/ <5.49042000, 3.19463501>, <5.49776510, 3.29733501>, <5.54764930, 3.41243501>, <5.62255140, 3.53463501>,
    /*  15*/ <5.62255140, 3.53463501>, <11.80734500, 5.05833501>, <18.22698900, 3.26583501>, <18.22698900, 3.26583501>,
    /*  16*/ <18.22698900, 3.26583501>, <18.36202300, 3.22773501>, <18.50289500, 3.30583501>, <18.54094300, 3.44093501>,
    /*  17*/ <18.54094300, 3.44093501>, <18.57898900, 3.57593501>, <18.49980100, 3.71673501>, <18.36476700, 3.75473501>,
    /*  18*/ <18.36476700, 3.75473501>, <18.36476700, 3.75473501>, <15.32465400, 4.61763501>, <11.36970600, 4.66173501>,
    /*  19*/ <11.36970600, 4.66173501>, <9.72564580, 4.68003501>, <7.92360870, 4.55603501>, <6.11606800, 4.17033501>,
    /*  20*/ <6.11606800, 4.17033501>, <6.22694500, 4.30253501>, <6.33496630, 4.43363501>, <6.42437480, 4.56003501>,
    /*  21*/ <6.42437480, 4.56003501>, <12.97401500, 6.18283501>, <19.60815800, 4.11053501>, <19.60815800, 4.11053501>,
    /*  22*/ <19.60815800, 4.11053501>, <19.70895800, 4.07373501>, <19.82158100, 4.09573501>, <19.90178300, 4.16703501>,
    /*  23*/ <19.90178300, 4.16703501>, <19.98198500, 4.23843501>, <20.01696700, 4.34723501>, <19.99213000, 4.45163501>,
    /*  24*/ <19.99213000, 4.45163501>, <19.96729200, 4.55603501>, <19.88693100, 4.63853501>, <19.78320500, 4.66623501>,
    /*  25*/ <19.78320500, 4.66623501>, <19.78320500, 4.66623501>, <16.47793700, 5.71613501>, <12.17830400, 5.76953501>,
    /*  26*/ <12.17830400, 5.76953501>, <10.43382600, 5.79123501>, <8.52598070, 5.64793501>, <6.60845530, 5.20493501>,
    /*  27*/ <6.60845530, 5.20493501>, <6.60545190, 5.21053501>, <6.60284130, 5.21633501>, <6.59942070, 5.22183501>,
    /*  28*/ <6.59942070, 5.22183501>, <6.29414280, 5.71213501>, <4.82623920, 4.90413501>, <4.29107290, 5.12133501>,
    /*  29*/ <4.29107290, 5.12133501>, <3.77263070, 5.33173501>, <3.29747160, 6.84163501>, <2.75857400, 6.80963501>
  };

camera {
  location <0, 5, -25>
  up y
  right x * image_width/image_height
  look_at 0
}

#declare PA_Objs =
  union {

    object {
      PA_Bezier_Sweep(PA_Shooting_Star, 0.1, PA_No_Trans, 60, no)
      translate <-10, -3, 0>
      rotate y * 22.5
      pigment { Red }
    }

    object {
      PA_Prism(PA_Bezier, PA_Linear_Sweep, -0.5, 0.5, PA_Shooting_Star, no, no, PA_No_Trans)
      rotate x * -90  
      translate <-10, -3, 0>
      scale <0.4, 0.4, 1>
      translate <2, -3, 0>
      rotate y * 22.5
      pigment { Blue }
    }

    #declare PA_Trans_1 = 
      transform {
        scale 0.25
        rotate z * 90
        translate x * 12.5
      }

    object {
      PA_Lathe_Arc(PA_Bezier, PA_Shooting_Star, no, PA_Trans_1, 270)
      rotate y * 45
      translate y * -3
      pigment { Yellow }
    }

    #declare PA_Trans_2 =
      transform {
        scale 0.25
        rotate z * -90
        translate <13, 5, 0>
      }

    object {
      PA_Lathe_Arc(PA_Bezier, PA_Shooting_Star, no, PA_Trans_2, 270)
      rotate y * 45
      translate y * -3
      pigment { Green }
    }

    translate z * 1.5
  }

plane {
  y, 0
  pigment { White }
  translate y * (min_extent(PA_Objs).y - 0.25)
}

sphere {
  0, 10000
  inverse
  texture {
    pigment { rgb <255, 231, 204>/255 }
    finish {
      ambient 1
      diffuse 0
    }
  }
}

object { PA_Objs }
