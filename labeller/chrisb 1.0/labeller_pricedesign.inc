//
// labeller_pricedesign.inc
// ------------------------
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
//

#ifndef (Labeller_LabelDesignClip)    #declare Labeller_LabelDesignClip     = 1; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)           #declare Labeller_ShowAxes            = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders
#ifndef (Labeller_LabelDesignSegment) #declare Labeller_LabelDesignSegment  = 0; #end  // 0 for full view. Otherwise a number between 1 and Labeller_PolyhedronFaces

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_price.inc","Poly")
  background {rgb <0.1,0.2,0.1>*0.5}  
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[Labeller_PolyhedronFaces+1][30];

  //**************************//
  //     Label Texts          //
  //**************************//
  
  #local LabelText1 = array[2] {
    "Black",
    "   Ink"
  }
  
  #local LabelText4 = "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";  

  #local LabelText11 = "FINE";  
  #local LabelText12 = "BLUE WRITING";  
  #local LabelText13 = "INK";  
  #local LabelText14 = "PRICE & SONS";  
  
  #local PriceLightBlue = 1.5*Labeller_PigmentIntensity*<110,134,113>/255;
  #local PriceGold      = 1  *Labeller_PigmentIntensity*<200,200,150>/255;
  #local PriceBlue      = 0.5*Labeller_PigmentIntensity*<101,157,172>/255;  
  #local PriceGrey      = 1.5*Labeller_PigmentIntensity*<162,150,124>/255;

  #local Labeller_BlueBandThickness = 0.0065;    
  #local Labeller_RedRimThickness   = 0.0015;
  #local Labeller_BlueRimThickness  = 0.0015;   
  #local Labeller_FaceCentre = <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,0,Labeller_LabelDepth/2>;
  
  //**************************//
  //   Layers of pigment      //
  //**************************// 
  
  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb PriceBlue}  
  
  #local Labeller_GoldRimThickness  = 0.0015;
  #local Labeller_BlueGapThickness  = Labeller_GoldRimThickness/2;
  #local Labeller_GoldLineThickness = Labeller_BlueGapThickness/2;
  
  // The thin bands around the top and bottom of the label including the symbols used to add a pattern to the rims 
  #local TextObject4 = text {ttf Labeller_FontCheck("wingding.ttf") LabelText4 1,0}
  #local TextCentre4 = (max_extent(TextObject4)+min_extent(TextObject4))/2;
   #declare Labeller_LabelLayer[0][1] = pigment {
    object { 
      union {
        box { // Bottom Gold Rim
          <0,-1,0>,
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_GoldRimThickness>
        }
        box { // Top Gold Rim
          <0,-1            ,Labeller_LabelDepth>,
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_LabelDepth-Labeller_GoldRimThickness>
        }
        box { // Gold Line inside Top Rim 
          <0,-1            ,Labeller_GoldRimThickness+Labeller_BlueGapThickness>,
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_GoldRimThickness+Labeller_BlueGapThickness+Labeller_GoldLineThickness>
        }
        box { // Gold Line inside Bottom Rim
          <0,-1            ,Labeller_LabelDepth-Labeller_GoldRimThickness-Labeller_BlueGapThickness-Labeller_GoldLineThickness>,                            
          <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),0,Labeller_LabelDepth-Labeller_GoldRimThickness-Labeller_BlueGapThickness>  
        }
        object { TextObject4
          translate -x*(TextCentre4)
          rotate x*90                                                       // Rotate onto the XZ plane
          scale <0.0015,1,0.0015>                                           // Scale as required
          translate <Labeller_FaceCentre.x,0,Labeller_LabelDepth-2.5*Labeller_GoldRimThickness>
        } 
        object { TextObject4
          translate -x*(TextCentre4)
          rotate x*90                                                       // Rotate onto the XZ plane
          scale <0.0015,1,0.0015>                                           // Scale as required
          translate <Labeller_FaceCentre.x,0,1.8*Labeller_GoldRimThickness> 
        } 
      }
      color <1,1,1,1>
      color PriceGold
    } 
  }



  // The word 'FINE' on the top of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("times.ttf") LabelText11 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[2][3] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0033,1,0.0033>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,Labeller_LabelDepth-5*Labeller_GoldRimThickness> // Centre on label
      color <1,1,1,1>
      color PriceGold
    } 
  }

  // The word 'BLUE WRITING' in the middle of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("arial.ttf") LabelText12 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[2][4] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0033,1,0.0033>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,Labeller_LabelDepth*7/12>      // Centre on label
      color <1,1,1,1>
      color PriceGold 
    } 
  }

  // The word 'INK' in the middle of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("times.ttf") LabelText13 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[2][5] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0080,1,0.0080>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,Labeller_LabelDepth/3.8>       // Centre on label
      color <1,1,1,1>
      color PriceGold
    } 
  }

  // The 'PRICE & SONS' text at the foot of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("arial.ttf") LabelText14 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[2][6] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0014,1,0.0014>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,2.8*Labeller_GoldRimThickness> // Centre on label
      color <1,1,1,1>
      color PriceGold
    } 
  }
  

#end



