//
// labeller_correctingfluiddesign.inc
// --------------------------
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

#ifndef (Labeller_LabelDesignClip) #declare Labeller_LabelDesignClip = 1; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)        #declare Labeller_ShowAxes        = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_correctingfluid.inc","Rect")
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[1][30];
 
  //**************************//
  //     Label Texts          //
  //**************************//
  #local LabelText1 = array[18] {
    "3D Model of a round",
    "bottle.",
    "Contains absolutely",
    "nothing real.", 
    "Oh! and by the way;",
    "This is the small print",
    "on a bottle of imaginary",
    "bottle, so why",
    "the blazes are you",
    "reading this. I've got",
    "an excuse, I needed to",
    "write something, but ",
    "there's a whole world",
    "of things out there you",
    "could be doing rather than",
    "reading this.",
    "Stir well before use.",
    "Close tightly after use."
  }  
  
  #local LabelText2 = array[16] {
    "Instructions for use -",
    "1. Add model to a",
    "POV-Ray scene file.",
    "2. Run POV-Ray to",
    "generate your image.",
    "3. Sit back and admire",
    "the sophisticated and",
    "elegant correction",
    "fluid bottle that",
    "appears like magic",
    "before your eyes as",
    "you watch POV-Ray in",
    "action.",
    " ",
    " ",
    "Made in Great Britain"
  }
  
  #local LabelText3 = "20ml";
  
  #local LabelText5 = "3.1415926535";
  
  
  //**************************//
  //   Layers of pigment      //
  //**************************//
  #declare Labeller_LabelLayer = array[2][30];
  
  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb 1.2*Labeller_PigmentIntensity}
  
  // The first block of small print
  #declare Labeller_LabelLayer[1][1] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText1,1))
          text {
            ttf Labeller_FontCheck("arial.ttf") LabelText1[LineI] 1, 0 
            translate -y*LineI
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
        scale <0.0014,1,0.0014>
        translate <0.055,0,0.03>   
      }
      color <1,1,1,1>
      color 0
    } 
  }  
  
  // The second block of small print
  #declare Labeller_LabelLayer[1][2] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText2,1))
          text {
            ttf Labeller_FontCheck("arial.ttf") LabelText2[LineI] 1, 0 
            translate -y*LineI
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
        scale <0.0014,1,0.0014>
        translate <0.075,0,0.03>   
      }
      color <1,1,1,1>
      color 0
    } 
  }
  
  // The 20ml text below the second block of small print
  #declare Labeller_LabelLayer[1][3] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText3 1, 0 
        rotate x*90
        scale <0.003,1,0.003>
        translate <0.082,0,0.006>   
      }
      color <1,1,1,1>
      color 0
    } 
  }
  
  // The coloured blocks above and below the blocks of small print
  #declare Labeller_LabelLayer[1][4] = pigment {
    object { 
      union {
        box {<0.055,-1,0.002>,<0.09,0,0.005>}
        box {<0.055,-1,0.033>,<0.09,0,0.036>}
      }
      color <1,1,1,1>
      color <0,1,1>*Labeller_PigmentIntensity
    } 
  }
  
  // The background to the main panel
  #declare Labeller_LabelLayer[1][11] = pigment {
    object { 
      box {<0.024,-1,0.002>,<0.051,0,0.036>}
      color <1,1,1,1>
      color <0,0,0.2>*Labeller_PigmentIntensity
    } 
  }
  
  // The words 'POV-Ray' and 'Correcting Fluid' on the main panel
  #declare Labeller_LabelLayer[1][12] = pigment {
    object {
      union {
        text {
          ttf Labeller_FontCheck("arial.ttf") "POV-Ray" 1, 0 
          rotate x*90
          scale <0.004,1,0.004>
          translate <0.029,0,0.030>   
        }
        text {
          ttf Labeller_FontCheck("arial.ttf") "Correcting Fluid" 1, 0.19*x 
          rotate x*90
          scale <0.0022,1,0.0022>
          translate <0.027,0,0.026>   
        } 
      }
      color <1,1,1,1>
      color <1,1,0>*Labeller_PigmentIntensity
    } 
  } 
  
  // The bitmapped image on the main panel 
  #declare Labeller_LabelLayer[1][13] = pigment { 
    image_map {jpeg "labeller_image.jpg" once} 
    scale 0.02
    rotate x*90 
    translate <0.028,0,0.004>
  }
  
  // The default label texture incorporates the POV-Ray logo
  #ifndef(Povray_Logo_Prism) #include "logo.inc" #end     
  
  
  // The POV-Ray logo
  #declare Labeller_LabelLayer[1][14] = pigment {
    object {
      Povray_Logo_Prism
      translate <1,0.5,0.1>
      scale <0.006,0.006,8>
      rotate x*90
      translate <0.023,0,0.012>
      color <1,1,1,1>
      color <0,0.2,0.2>*Labeller_PigmentIntensity
    } 
  } 
  

  // Add a black bar code to the back
  #declare Labeller_LabelLayer[1][21] = pigment {
    object {
      Labeller_EANBarCode(5,"141421356237",0.5)
      rotate <90,-90,0>
      scale 0.035
      translate 0.021*x
      color <1,1,1,1>
      color 0 
    }
  }

#end



