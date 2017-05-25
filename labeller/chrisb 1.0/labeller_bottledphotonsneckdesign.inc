//
// labeller_bottledphotonsneckdesign.inc
// -------------------------------------
// Created by Chris Bartlett February 2008
// This include file defines the layers of pigment required to build up a sauce bottle label.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 0.001 POV-Ray units = 1mm   (1m = 1 POV-Ray unit)
// Layers of pigment need to lie on the XZ plane. The sample is taken at y=-0.0001.
//
// You can render this file, which will display a flattened version of the label.
// Render times are typically half a minute to a couple of minutes depending on size.  
  
#ifndef (Labeller_LabelDesignClip)    #declare Labeller_LabelDesignClip     = 1; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)           #declare Labeller_ShowAxes            = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders
#ifndef (Labeller_LabelDesignSegment) #declare Labeller_LabelDesignSegment  = 0; #end  // 0 for full view. Otherwise a number between 1 and Labeller_PolyhedronFaces

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_bottledphotonsneck.inc","Poly")
  background {rgb <0.1,0.2,0.1>*0.5}  
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[Labeller_PolyhedronFaces+1][30];

  //**************************//
  //     Label Texts          //
  //**************************//
  #local LabelText11 = "POV-Ray's";  
  #local LabelText12 = "Prestigeous";  
  #local LabelText13 = "Pickled";  
  #local LabelText14 = "Photons";  

  
  #local LabelText3 = array[8] {
    "Some small-print for the",
    "back of the label.",
    "This text can obviously",
    "say more or less anything",
    "you please as it's fairly",
    "unlikely that anyone will",
    "be able to read it under",
    "most circumstances"
  }
  
  #local PrismWhite     = 1  *Labeller_PigmentIntensity*<255,255,175>/255;
  #local PrismGold      = 0.8*Labeller_PigmentIntensity*<220,220,120>/255;
  #local PrismRed       = 0.6*Labeller_PigmentIntensity*<255,025,024>/255;

  #local Labeller_FaceCentre = <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,0,Labeller_LabelDepth/2>;
  
  #local Labeller_WhiteRimThickness  = 0.002;
  #local Labeller_RedBandThickness  = 0.002;
  #local Labeller_GoldBandThickness = 0.0015;

  //**************************//
  //   Layers of pigment      //
  //**************************// 
  #declare Labeller_LabelLayer = array[Labeller_PolyhedronFaces+1][30];

  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb PrismWhite}  
  
  // The thin Red bands around the top and bottom of the label
   #declare Labeller_LabelLayer[0][1] = pigment {
    object { 
      union {
        box { // Bottom Red Band
          <0,-1,Labeller_WhiteRimThickness>,
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_WhiteRimThickness+Labeller_RedBandThickness>
        }
        box { // Top Red Band
          <0,-1            ,Labeller_LabelDepth-Labeller_WhiteRimThickness>,
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_LabelDepth-Labeller_WhiteRimThickness-Labeller_RedBandThickness>
        }
      }
      color <1,1,1,1>
      color PrismRed
    } 
  }

  // The thin Gold bands around the top and bottom of the label
   #declare Labeller_LabelLayer[0][2] = pigment {
    object { 
      union {
        box { // Bottom Gold Band
          <0,-1,Labeller_WhiteRimThickness+Labeller_RedBandThickness>,
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_WhiteRimThickness+Labeller_GoldBandThickness+Labeller_RedBandThickness>
        }
        box { // Top Gold Band
          <0,-1            ,Labeller_LabelDepth-Labeller_WhiteRimThickness-Labeller_RedBandThickness>,
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_LabelDepth-Labeller_WhiteRimThickness-Labeller_GoldBandThickness-Labeller_RedBandThickness>
        }
      }
      color <1,1,1,1>
      color PrismGold
    } 
  }





  // A block of meaningless small print on the back of the label
  #declare Labeller_LabelLayer[10][3] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText3,1))
          #local TextObject = text {ttf Labeller_FontCheck("arial.ttf") LabelText3[LineI] 1, 0}
          #local TextCentre = (max_extent(TextObject)+min_extent(TextObject))/2;
          object {
            TextObject
            translate -x*TextCentre
            translate -y*LineI 
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
        translate z*dimension_size(LabelText3,1)
        translate y*0.1 
        scale <0.0011,1,0.0011>
      }
      translate <Labeller_FaceCentre.x,0,0.007>   
      color <1,1,1,1>
      color PrismGold
    } 
  }  

  #declare Labeller_LabelLayer[30][3] = Labeller_LabelLayer[10][3]

#end



