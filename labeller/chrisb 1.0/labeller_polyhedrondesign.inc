//
// labeller_polyhedrondesign.inc
// -----------------------------
// Created by Chris Bartlett February 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This include file defines the layers of pigment required to build up a polyhedral label.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 0.001 POV-Ray units = 1mm   (1m = 1 POV-Ray unit)
// Layers of pigment need to lie on the XZ plane. The sample is taken at y=-0.0001.
//
// You can render this file, which will display a flattened version of the label.
// Render times are typically half a minute to a couple of minutes depending on size.  

#ifndef (Labeller_LabelDesignClip)    #declare Labeller_LabelDesignClip     = 0; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)           #declare Labeller_ShowAxes            = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders
#ifndef (Labeller_LabelDesignSegment) #declare Labeller_LabelDesignSegment  = 0; #end  // 0 for full view. Otherwise a number between 1 and Labeller_PolyhedronFaces

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_polyhedron.inc","Poly")
  background {rgb <0.1,0.2,0.1>*0.5}  
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[Labeller_PolyhedronFaces+1][30];
  
  //**************************//
  //   Layers of pigment      //
  //**************************// 
  
  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb <0.85,0.95,0.85>*Labeller_PigmentIntensity}  
  
  #local Labeller_BandThickness = 0.008;    
  
  // The green band around the middle
  #declare Labeller_LabelLayer[0][1] = pigment {
    object { 
      box {
        <0,-1,Labeller_LabelHeight/2-Labeller_BandThickness/2>,
        <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_LabelHeight/2+Labeller_BandThickness/2>
      }
      color <1,1,1,1>
      color <0.55,0.65,0.55>*Labeller_PigmentIntensity
    } 
  }

  // This label texture incorporates the POV-Ray logo
  #ifndef(Povray_Logo_Prism) #include "logo.inc" #end     
  
  // A wide version of the POV-Ray logo that will be wider than the polygon faces
  #declare Labeller_LabelLayer[1][1] = pigment {
    object {
      Povray_Logo_Prism
      translate <0,0,0>
      scale <0.025,0.015,8>
      rotate x*90
      translate <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_LabelDepth>/2
      color <1,1,1,1>
      color <0,0.4,0.4>*Labeller_PigmentIntensity
    } 
  } 

  // A smaller version of the POV-Ray logo that fits on a face
  #declare Labeller_LabelLayer[2][1] = pigment {
    object {
      Povray_Logo_Prism
      translate <0,0,0>
      scale <0.005,0.005,8>
      rotate x*90
      translate <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_LabelDepth>/2
      color <1,1,1,1>
      color <0.5,0.9,0>*Labeller_PigmentIntensity
    } 
  } 

  // Copy them round to alternating faces
  #declare Labeller_LabelLayer[3][1] = Labeller_LabelLayer[1][1];
  #declare Labeller_LabelLayer[5][1] = Labeller_LabelLayer[1][1];
  #declare Labeller_LabelLayer[7][1] = Labeller_LabelLayer[1][1];

  #declare Labeller_LabelLayer[4][1] = Labeller_LabelLayer[2][1];
  #declare Labeller_LabelLayer[6][1] = Labeller_LabelLayer[2][1];
  #declare Labeller_LabelLayer[8][1] = Labeller_LabelLayer[2][1];

#end



