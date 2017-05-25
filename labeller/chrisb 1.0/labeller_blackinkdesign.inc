//
// labeller_blackinkdesign.inc
// ---------------------------
// Created by Chris Bartlett February 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
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

#// You can render this file, which will display a flattened version of the label.
// Render times are typically half a minute to a couple of minutes depending on size.  

#ifndef (Labeller_LabelDesignClip) #declare Labeller_LabelDesignClip = 0; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)        #declare Labeller_ShowAxes        = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_blackink.inc","Rect")
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[2][30];

  //**************************//
  //     Label Texts          //
  //**************************//
  
  #local LabelText1 = array[2] {
    "Black",
    "   Ink"
  }
  
  #local LabelText2 = "80ml";  
  
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
    
  //**************************//
  //   Layers of pigment      //
  //**************************//
  
  #local Labeller_BandThickness = 0.008;    
  #local Labeller_BlackRimThickness = 0.0004;
  #local Labeller_GoldLineThickness = 0.0006;

  
  // The label background 
  
  // The main black band defining the label shape
  #declare Labeller_LabelLayer[0][1] = pigment {
    object { 
      box {
        <0                  ,-1,Labeller_LabelHeight/2-Labeller_BandThickness/2>,
        <Labeller_LabelWidth, 0,Labeller_LabelHeight/2+Labeller_BandThickness/2>
      }
      color <1,1,1,1>
      color <0,0,0>
    } 
  }

  // The gold bands running right around the label
  #declare Labeller_LabelLayer[0][2] = pigment {
    object { 
      difference {
        box {
          <0                  ,-1,Labeller_LabelHeight/2-Labeller_BandThickness/2+Labeller_BlackRimThickness>,
          <Labeller_LabelWidth, 0,Labeller_LabelHeight/2+Labeller_BandThickness/2-Labeller_BlackRimThickness>
        }
        box {
          <0                  ,-1            ,Labeller_LabelHeight/2-Labeller_BandThickness/2+Labeller_BlackRimThickness+Labeller_GoldLineThickness>,
          <Labeller_LabelWidth,Labeller_Delta,Labeller_LabelHeight/2+Labeller_BandThickness/2-Labeller_BlackRimThickness-Labeller_GoldLineThickness>
        }
      }
      color <1,1,1,1>
      color <0.28,0.24,0>*Labeller_PigmentIntensity
    } 
  }

  // The black diamond defining the label shape
  #declare Labeller_LabelLayer[1][1] = pigment {
    object { 
      box {<0,-1,0>,<sqrt(pow(Labeller_LabelHeight,2)/2),0,sqrt(pow(Labeller_LabelHeight,2)/2)>
        rotate -y*45
        translate x*Labeller_LabelWidth/2
      }
      color <1,1,1,1>
      color <0,0,0>
    } 
  }

  // The gold diamond edging on the front
  #declare Labeller_LabelLayer[1][2] = pigment {
    object { 
      difference {
        box {
          -<sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness,1,sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness>
          ,<sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness,0,sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness> 
          rotate -y*45
          translate <Labeller_LabelWidth/2,0,Labeller_LabelHeight/2>
        } 
        box {
          -<sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness-Labeller_GoldLineThickness,1,sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness-Labeller_GoldLineThickness>
          ,<sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness-Labeller_GoldLineThickness,0,sqrt(pow(Labeller_LabelHeight,2)/2)/2-Labeller_BlackRimThickness-Labeller_GoldLineThickness> 
          rotate -y*45
          translate <Labeller_LabelWidth/2,0,Labeller_LabelHeight/2>
        }
      }
      color <1,1,1,1>
      color <0.28,0.24,0>*Labeller_PigmentIntensity
    } 
  }
  
  
  // The first block of small print
  #declare Labeller_LabelLayer[1][3] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText1,1))
          text {
            ttf Labeller_FontCheck("alger.ttf") LabelText1[LineI] 1, 0 
            translate -y*LineI
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
        scale <0.003,1,0.003>
        translate <Labeller_LabelWidth/2-0.0048,0,Labeller_LabelHeight-0.0125>   
      }
      color <1,1,1,1>
      color <0.28,0.24,0>*2*Labeller_PigmentIntensity
    } 
  }  
  
  // The 80ml text below the second block of small print
  #declare Labeller_LabelLayer[1][11] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText2 1, 0 
        rotate x*90
        scale <0.003,1,0.003>
        translate <Labeller_LabelWidth-0.009,0,Labeller_LabelHeight/2-0.002>   
      }
      color <1,1,1,1>
      color <0.28,0.24,0>*Labeller_PigmentIntensity
    } 
  }
  
  // The small print for the left hand side of the label
  #declare Labeller_LabelLayer[1][21] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText3,1))
          text {
            ttf Labeller_FontCheck("arial.ttf") LabelText3[LineI] 1, 0 
            translate -y*LineI
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
        scale <0.00071,1,0.00071>
        translate <0.005,0,Labeller_LabelHeight/2+0.00237>   
      }
      color <1,1,1,1>
      color <0.28,0.24,0>*Labeller_PigmentIntensity
    } 
  }

  
  // This label texture incorporates the POV-Ray logo
  #ifndef(Povray_Logo_Prism) #include "logo.inc" #end     
  
  
  // The POV-Ray logo
  #declare Labeller_LabelLayer[1][14] = pigment {
    object {
      Povray_Logo_Prism
      translate <1,0.5,0.1>
      scale <0.003,0.003,8>
      rotate x*90
      translate <Labeller_LabelWidth/2-0.0035,Labeller_Delta,Labeller_LabelHeight/2+0.003>   
      color <1,1,1,1>
      color <0,0.4,0.4>*Labeller_PigmentIntensity
    } 
  } 
  
  

#end



