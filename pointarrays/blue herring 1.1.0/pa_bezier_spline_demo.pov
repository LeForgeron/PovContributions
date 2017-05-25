// Title:        PointArrays bezier spline demo scene
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 16, 2008
// Last updated: June 16, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#declare Use_Area = yes;
#declare Use_Radiosity = no;

#if(Use_Radiosity) 
  #default { finish { ambient 0 diffuse 0.6 } }
#end

#include "colors.inc"
#include "golds.inc"
#include "metals.inc"
#include "pa_shooting_star.inc"
#include "pointarrays.inc"
#include "rad_def.inc"
#include "z_finishes.inc"

global_settings {
  assumed_gamma 1.0
  max_trace_level 6
  #if(Use_Radiosity)
    radiosity {
      Rad_Settings(Radiosity_Normal, no, no)
    }
  #end
}

#declare Triangle =
  array[12] {
    /*   0*/ <10.03949100, 0.44978262>, <9.68934640, -0.15351738>, <0.42296231, -0.13181738>, <0.07563849, 0.47308262>,
    /*   1*/ <0.07563849, 0.47308262>, <-0.27168565, 1.07788262>, <4.38024760, 9.09198262>, <5.07771820, 9.09028262>,
    /*   2*/ <5.07771820, 9.09028262>, <5.77518750, 9.08868262>, <10.38963800, 1.05288262>, <10.03949100, 0.44978262>
  };

light_source {
  <10, 10, -30>, rgb <255, 249, 251>/255
  #if(Use_Area)
    area_light
    x * 3, y * 3, 9, 9
    adaptive 0
    circular
    orient
  #end
}

camera {
  location <0, 12, -10>
  up y
  right x * image_width/image_height
  look_at 0
}

background { rgb <0.7, 0.7, 1> }

#declare Shiny_Gold =
  texture {
    pigment { P_Gold1 }
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
  }

#declare Shiny_Silver =  
  texture {
    pigment { P_Silver2 }
    finish {
      ambient 0
      diffuse 0.1
      specular 1.8
      roughness 0.006948
      metallic
      reflection {
        0.45, 0.9
        metallic
      }
      conserve_energy
      brilliance 3.5
    }
  }

#declare Shiny_Bronze =
  texture {
    pigment { P_Brass1 }
    finish {
      ambient 0
      diffuse 0.15
      specular 1.7
      roughness 0.009157
      metallic
      reflection {
        0.425, 0.85
        metallic
      }
      conserve_energy
      brilliance 2
    }
  }


#if(Use_Radiosity)
  sphere {
    0, 10000
    inverse
    no_reflection
    texture {
      pigment { rgb <255, 249, 251>/255 }
      finish {
        ambient 0.5
        diffuse 0
      }
    }
  }
#end

plane {
  y, 0
  texture {
    pigment { rgb <0.5, 0.5, 1> }
  }
}

union {

  object {
    PA_Bezier_Sweep(PA_Shooting_Star, 0.15, PA_No_Trans, 40, no)
    texture { Shiny_Silver }
    rotate x * 90
    translate y * 0.5
  }

  union {
    #declare Count = 60;
    #declare Ct = 0;
    #while(Ct < Count)
      #declare Pt = PA_Bezier_Spline_Uniform(PA_Shooting_Star, Ct/Count);
  
      superellipsoid {
        <1, 0.2>
        rotate x * 90
        scale <0.2, 1, 0.2>
        translate <Pt.x, 0, Pt.y>
      }
    
      #declare Ct = Ct + 1;
    #end
  
    texture { Shiny_Gold }
  }
  scale 3/4
  translate <-7, 0, -6>
}
  
union {

  object {
    PA_Bezier_Sweep(PA_Shooting_Star, 0.15, PA_No_Trans, 40, no)
    texture { Shiny_Silver }
    rotate x * 90
    translate y * 0.5
  }

  union {
    #declare Count = 40;
    #declare Ct = 0;
    #while(Ct < Count)
      #declare Pt = PA_Bezier_Spline_Auto(PA_Shooting_Star, Ct/Count);
  
      superellipsoid {
        <1, 0.2>
        rotate x * 90
        scale <0.2, 1, 0.2>
        translate <Pt.x, 0, Pt.y>
      }
    
      #declare Ct = Ct + 1;
    #end
  
    texture { Shiny_Bronze }
  
  }
  scale <-3/4, 3/4, 3/4>
  translate <8, 0, 0>
}
