//
// labeller_peachesimage.inc
// -------------------------
// Created by Chris Bartlett February 2008
// This include file defines the layers of pigment required to build up a label.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 0.001 POV-Ray units = 1mm   (1m = 1 POV-Ray unit)
// Layers of pigment need to lie on the XZ plane. The sample is taken at y=-0.0001.
//
// You can render this file, which will display a flattened version of the label.
// Render times are typically half a minute to a couple of minutes depending on size.  
//

#ifndef (Labeller_LabelDesignClip) #declare Labeller_LabelDesignClip = 0; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)        #declare Labeller_ShowAxes        = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_peachesimage.inc","Rect")
#else  
    
  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[2][3];
  
  //**************************//
  //   Layers of pigment      //
  //**************************//
  
  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb 1.2}
  
  // The bitmapped image 
  #declare Labeller_LabelLayer[1][1] = pigment { 
    image_map {jpeg "labeller_peaches.jpg" once} 
    scale <Labeller_LabelWidth,Labeller_LabelHeight,1> 
    rotate x*90 
  }

#end





