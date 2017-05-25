// Title:        TrainFaces textures
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   July 17, 2008
// Last updated: July 22, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(Tf_Textures_Inc)
#declare Tf_Textures_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including tf_textures.inc\n"
#end

#include "colors.inc"

#declare TF_Gray = rgb 0.78;
#declare TF_Rosy = rgb <1, 0.73, 0.78>;
  
#declare TF_Plastic_Dull =
  texture {
    finish {
      specular 0.1
      roughness 0.05
      reflection {
        0.01, 0.04
        fresnel
      }
      conserve_energy
    }
  }
  
#declare TF_Plastic_Shiny =
  texture {
    finish {
      ambient 0
      diffuse 0.95
      specular 0.7
      roughness 0.012904
      reflection {
        0.025, 0.1
        fresnel
      }
      conserve_energy
    }
    normal { 
      bozo 0.2 
      scale 3
    }
  }

#declare TF_Plastic_I =
  interior {
    ior 1.46
  }

#declare TF_Default_Face_T  = 
  texture {
    TF_Plastic_Dull
    pigment { TF_Gray }
  }
  
#declare TF_Default_Face_I = TF_Plastic_I;
  
#declare TF_Default_Rosy_T =
  texture {
    TF_Plastic_Dull
    pigment { TF_Rosy }
  }
  
#declare TF_Default_Face_I = TF_Plastic_I;
  
#declare TF_Default_Eye_T = 
  texture {
    TF_Plastic_Shiny
    pigment { White }
  }

#declare TF_Default_Pupil_T = 
  texture {
    TF_Plastic_Shiny
    pigment { Black }
  }
  
#declare TF_Default_Eye_I = TF_Plastic_I;

#declare TF_Default_Mouth_M =
  material {
    texture {
      TF_Plastic_Shiny
      pigment { White }
    }
    interior { TF_Plastic_I }
  }

#declare TF_Default_Brow_T =
  texture {
    TF_Plastic_Dull
    pigment { Black }
  }



#version Tf_Textures_Inc;
#end
