//
// labeller_pearsdesign.inc
// ------------------------
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

#ifndef (Labeller_LabelDesignClip) #declare Labeller_LabelDesignClip = 0; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)        #declare Labeller_ShowAxes        = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_conferencepears.inc","Rect")
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[2][50];
  
  //**************************//
  //     Label Texts          //
  //**************************//
  #local LabelText1 = array[18] {
    "3D VIRTUAL PEARS in light syrup",
    "CONTAINS: Nothing at all",
    "Add pears to taste",
    " ", 
    "3D FERSKENSKIVER i lett sirup",
    "INGREDIENSER: Rien de Tout",
    " ", 
    " ", 
    "Net Weight",
    "Nettovikt",
    " ", 
    " ", 
    "Drained Weight",
    "Varav Persikor",
    " ", 
    " ", 
    "See lid for Best Before Date",
    " ", 
  }  
  
  #local LabelText2 = array[13] {
    "Instructions for use -",
    "1. Add model to a POV-Ray",
    "scene file.",
    "2. Run POV-Ray to generate",
    "your image.",
    "3. Sit back and admire the",
    "sophisticated and elegant",
    "label that appears like",
    "magic before your eyes as",
    "you watch POV-Ray in action.",
    " ",
    " ",
    "Made in Great Britain"
  }
  
  #local LabelText3 = "420g";
  #local LabelText4 = "250g";
  
  #local LabelText5 = "3.1415926535";
 
  #local LabelText6 = "Conference"; 
  #local LabelText7 = "Pears";

  
  #local ConferenceWhite     = <1,1,1>            *Labeller_PigmentIntensity;
  #local ConferenceFawn      = <0.9,0.85,0.75>    *Labeller_PigmentIntensity;
  #local ConferenceBrown     = <0.9,0.85,0.75>*0.8*Labeller_PigmentIntensity;
  #local ConferenceDarkBrown = <0.2,0.1 ,0>       *Labeller_PigmentIntensity;
 
  //**************************//
  //   Layers of pigment      //
  //**************************//
  
  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb ConferenceFawn}
  
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
        scale <0.0030,1,0.0030>
        translate <0.125,0,0.065>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
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
        scale <0.0030,1,0.0030>
        translate <Labeller_LabelWidth-0.04,0,0.065>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }
  
  // The 420g text next to the first block of small print
  #declare Labeller_LabelLayer[1][3] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText3 1, 0 
        rotate x*90
        translate y*0.1 
        scale <0.006,1,0.006>
        translate <0.160,0,0.04>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }

  // The 250g text next to the first block of small print
  #declare Labeller_LabelLayer[1][4] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText4 1, 0 
        rotate x*90
        scale <0.006,1,0.006>
        translate <0.160,0,0.03>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }
    
  // The background to the main panel
  #declare Labeller_LabelLayer[1][11] = pigment {
    object { 
      box {<0,-1,0>,<Labeller_LabelWidth/2,0,Labeller_LabelHeight>}
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }
  
  // The main bitmapped image 
  #declare Labeller_LabelLayer[1][12] = pigment { 
    image_map {jpeg "labeller_conferencepears.jpg" once} 
    scale <0.085,0.09,1>
    rotate x*90 
    translate <0.015,0,0.006>
  } 
  
  // The bitmapped recipe image on the back
  #declare Labeller_LabelLayer[1][14] = pigment { 
    image_map {jpeg "labeller_pear_desert.jpg" once} 
    scale <0.02,0.024,1>
    rotate x*90 
    translate <Labeller_LabelWidth-0.04,0,Labeller_LabelHeight-0.0255>
  } 
  
  

  // The words 'POV-Ray' on the bar
  #declare Labeller_LabelLayer[1][16] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") "POV-Ray" 1, 0 
        rotate x*90
        scale <0.005,1,0.005>
        translate <Labeller_LabelWidth-0.04,0,0.072>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  } 
  


  // The default label texture incorporates the POV-Ray logo
  #ifndef(Povray_Logo_Prism) #include "logo.inc" #end     
  


  // The "Conference" shadow on the front of the can
  #declare Labeller_LabelLayer[1][20] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText6 1, 0 
        rotate x*90
        scale <0.008,1,0.008>
        translate <0.0455,0,0.0785>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }
  
  // The "Pears" shadow on the front of the can
  #declare Labeller_LabelLayer[1][21] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText7 1, 0 
        rotate x*90
        scale <0.010,1,0.010>
        translate <0.0605,0,0.0685>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }


  // The "Conference" text on the front of the can
  #declare Labeller_LabelLayer[1][22] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText6 1, 0 
        rotate x*90
        scale <0.008,1,0.008>
        translate <0.045,0,0.079>   
      }
      color <1,1,1,1>
      color ConferenceWhite
    } 
  }

  // The "Pears" text on the front of the can
  #declare Labeller_LabelLayer[1][23] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText7 1, 0 
        rotate x*90
        scale <0.010,1,0.010>
        translate <0.06,0,0.069>   
      }
      color <1,1,1,1>
      color ConferenceWhite
    } 
  }
  
  // The "Conference" text on the back of the can
  #declare Labeller_LabelLayer[1][24] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText6 1, 0 
        rotate x*90
        scale <0.006,1,0.006>
        translate <0.140,0,0.08>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }

  // The "Pears" text on the back of the can
  #declare Labeller_LabelLayer[1][25] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText7 1, 0 
        rotate x*90
        scale <0.006,1,0.006>
        translate <0.140,0,0.074>   
      }
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  }
    
  // The POV-Ray logo on the front label
  #declare Labeller_LabelLayer[1][31] = pigment {
    object {
      Povray_Logo_Prism
      translate <1,0.5,0.1>
      scale <0.016,0.016,8>
      rotate x*90
      translate <0.0155,0,0.072>
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  } 
  
  // The POV-Ray logo on the back label
  #declare Labeller_LabelLayer[1][32] = pigment {
    object {
      Povray_Logo_Prism
      translate <1,0.5,0.1>
      scale <0.008,0.008,8>
      rotate x*90
      translate <Labeller_LabelWidth/2+0.005,0,0.075>
      color <1,1,1,1>
      color ConferenceDarkBrown
    } 
  } 
  
  
  // Add a black bar code to the back
  #declare Labeller_LabelLayer[1][41] = pigment {
    object {
      Labeller_EANBarCode(5,"141421356237",0.5)
      rotate x*90
      scale 0.05
      translate <Labeller_LabelWidth-0.052,0,0>
      color <1,1,1,1>
      color 0 
    }
  }

#end



