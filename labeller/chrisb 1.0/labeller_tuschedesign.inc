//
// labeller_tuschedesign.inc
// ---------------------------
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

#ifndef (Labeller_LabelDesignClip) #declare Labeller_LabelDesignClip = 1; #end  // 0 = No clipping, 1 = Clipping
#ifndef (Labeller_ShowAxes)        #declare Labeller_ShowAxes        = 1; #end  // 0 = No Axes, 1 for 640x480. Increase for smaller renders

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_tusche.inc","Rect")
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[2][30];
  
  #local LabelText1 = "Biesinger";
  #local LabelText2 = " . tit . Tusche . tit . Tusche . tit . Tusche . tit . ";
  
  #local LabelText11 = "100ml";  
  
  #local LabelText21 = array[8] {
    "Some  small-print  for  the",
    "back of the label.",
    "This  text   can   obviously",
    "say more or less anything",
    "you  please   as  it's fairly",
    "unlikely  that   anyone  will",
    "be  able  to  read  it  under",
    "most circumstances"
  }
  
  #local TuscheLightBlue = 1.5*Labeller_PigmentIntensity*<110,134,113>/255;
  #local TuscheRed       = 1.5*Labeller_PigmentIntensity*<179, 25, 35>/255;
  #local TuscheBlue      = 1.5*Labeller_PigmentIntensity*< 36, 31, 45>/255;  
  #local TuscheGrey      = 1.5*Labeller_PigmentIntensity*<162,150,124>/255;

  #local Labeller_BlueBandThickness = 0.0065;    
  #local Labeller_RedRimThickness   = 0.0015;
  #local Labeller_BlueRimThickness  = 0.0015;
  
  //**************************//
  //   Layers of pigment      //
  //**************************//
  #declare Labeller_LabelLayer = array[2][30];
  
  // ---- Create the main blocks of colour first ---- //

  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb TuscheLightBlue}  
  
  // The red band around the base of the label
  #declare Labeller_LabelLayer[0][1] = pigment {
    object { 
      box {
        <0,-1,0>,
        <Labeller_LabelWidth,0,Labeller_RedRimThickness>
      }
      color <1,1,1,1>
      color TuscheRed
    } 
  }

  // The blue band around the base of the label
  #declare Labeller_LabelLayer[0][2] = pigment {
    object { 
      box {
        <0,-1,Labeller_RedRimThickness>,
        <Labeller_LabelWidth,0,Labeller_RedRimThickness+Labeller_BlueBandThickness>
      }
      color <1,1,1,1>
      color TuscheBlue
    } 
  }

  // The blue band around the top of the label
  #declare Labeller_LabelLayer[0][6] = pigment {
    object { 
      box {
        <0,-1,Labeller_LabelHeight-Labeller_BlueRimThickness>,
        <Labeller_LabelWidth,0,Labeller_LabelHeight>
      }
      color <1,1,1,1>
      color TuscheBlue
    } 
  }
  
  // The blue band around the oval on the label
  #declare Labeller_LabelLayer[1][3] = pigment {
    object { 
      cylinder{ -y, 0, Labeller_LabelWidth/8 
        scale <0.95,1,4*(Labeller_LabelHeight-2*Labeller_BlueRimThickness-Labeller_BlueBandThickness-Labeller_RedRimThickness)/Labeller_LabelWidth>
        translate <Labeller_LabelWidth/2,0,Labeller_LabelHeight/2+Labeller_BlueBandThickness/2>
      }
      color <1,1,1,1>
      color TuscheBlue
    } 
  }

  // The red oval on the label
  #declare Labeller_LabelLayer[1][4] = pigment {
    object { 
      cylinder{ -y, 0, Labeller_LabelWidth/8 
        scale <0.90-((Labeller_LabelWidth/8-2*Labeller_BlueRimThickness)/Labeller_LabelWidth/8),1,4*(Labeller_LabelHeight-4*Labeller_BlueRimThickness-Labeller_BlueBandThickness-Labeller_RedRimThickness)/Labeller_LabelWidth>
        translate <Labeller_LabelWidth/2,0,Labeller_LabelHeight/2+Labeller_BlueBandThickness/2>
      }
      color <1,1,1,1>
      color TuscheRed
    } 
  }

  // ---- Add the various text elements ---- //

  // The main label text
  #local Labeller_ThisText = text {ttf Labeller_FontCheck("palscri.ttf") LabelText1 1, 0}
  #declare Labeller_LabelLayer[1][11] = pigment {
    object {
      Labeller_ThisText 
      translate -x*(max_extent(Labeller_ThisText).x-min_extent(Labeller_ThisText).x)/2
      rotate x*90
      scale <0.016,1,0.016>
      translate <Labeller_LabelWidth/2,0,Labeller_LabelHeight-0.016>   
      color <1,1,1,1>
      color TuscheGrey
    }
  }
    
  // The text on the blue band
  #local Labeller_ThisText = text {ttf Labeller_FontCheck("arial.ttf") LabelText2 1, 0 scale <1.75,1,1>}
  #declare Labeller_LabelLayer[1][12] = pigment {
    object {
      Labeller_ThisText
      translate -x*(max_extent(Labeller_ThisText).x-min_extent(Labeller_ThisText).x)/2
      rotate x*90
      scale <0.006,1,0.006>
      translate <Labeller_LabelWidth/2,0,Labeller_RedRimThickness+0.001>   
      color <1,1,1,1>
      color TuscheGrey
    } 
  }  
  
  // The 100ml text over to the right
  #declare Labeller_LabelLayer[1][16] = pigment {
    object {
      text {
        ttf Labeller_FontCheck("arial.ttf") LabelText11 1, 0 
        rotate x*90
        scale <0.006,1,0.006>
        translate <Labeller_LabelWidth-0.06,0,Labeller_RedRimThickness+Labeller_BlueBandThickness+0.002>   
      }
      color <1,1,1,1>
      color TuscheBlue
    } 
  }
  
  // The small print for the left hand side of the label
  #declare Labeller_LabelLayer[1][21] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText21,1))
          text {
            ttf Labeller_FontCheck("arial.ttf") LabelText21[LineI] 1, 0 
            translate -y*LineI
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
        scale <0.0015,1,0.0015>
        translate <0.0605,0,Labeller_LabelHeight/2+0.005>   
      }
      color <1,1,1,1>
      color TuscheBlue
    } 
  }

  // ---- Add any additional layers on top ---- //

//  // Dirt
//  #declare Labeller_LabelLayer[1][25] = pigment {
//    bozo turbulence 0.5
//    color_map {
//      [0.0  color rgbt 1]
//      [0.75 color rgbt 1]
//      [0.85 color rgbt <0.1,0.1,0.1,0.7>]
//      [1.0  color rgbt <0.1,0.1,0.1,0.7>]
//    }
//    scale 0.002
//  }

#end



