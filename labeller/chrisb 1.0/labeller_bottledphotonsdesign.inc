//
// labeller_bottledphotonsdesign.inc
// ---------------------------------
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
#ifndef (Labeller_LabelDesignSegment) #declare Labeller_LabelDesignSegment  = 7; #end  // 0 for full view. Otherwise a number between 1 and Labeller_PolyhedronFaces

// If the Labeller_LabelDesignMode is set to '1' we call a macro to display a flattened version of the label and
// to set up a standard orthographic camera and a light source. The various Labeller macros set 
// Labeller_LabelDesignMode to '0', so if it's not set we know this file wasn't included through the macros. 
#ifndef (Labeller_LabelDesignMode)    #declare Labeller_LabelDesignMode     = 1;     #end
#if (Labeller_LabelDesignMode)
  #include "labeller.inc"
  Labeller_DisplayDesign("labeller_bottledphotons.inc","Poly")
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
  
  //**************************//
  //   Layers of pigment      //
  //**************************// 
  
  #include "labeller_bottledphotonsshapes.inc"
  #local PrismCentre = (max_extent(Outline)+min_extent(Outline))/2;
  #local Label_Prism_Transform = transform {
      translate -y*0.9 
      translate -x*PrismCentre     // Centre on z axis
      scale <0.00007,1,0.00007>  
      translate <Labeller_FaceCentre.x,0,0>            // Centre on the centre of the face
  }

  // The label background
  #declare Labeller_LabelLayer[0][0] = pigment {rgbt 1}  
//  #declare Labeller_LabelLayer[2][0] = pigment {rgb 1}  

  // Front label section
  #declare Labeller_LabelLayer[3][0] = pigment { 
    object {
      Outline 
      transform {Label_Prism_Transform}
      color <1,1,1,1>
      color PrismWhite   
    }
  }  

  #declare Labeller_LabelLayer[3][1] = pigment { 
    object {
      difference {   
        object {GoldRim}
        object {InnerGold}
      }
      transform {Label_Prism_Transform}
      color <1,1,1,1>
      color PrismRed   
    }
  }  

  #declare Labeller_LabelLayer[3][2] = pigment { 
    object {
      difference {   
        object {InnerGold}
        object {InnerGreen}
      }
      transform {Label_Prism_Transform}
      color <1,1,1,1>
      color PrismGold    
    }
  }  


  // The symbols in the middle of the top and bottom of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("wingding.ttf") "T" 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[3][10] = pigment {  
    object {
      union {
        object { TextObject
          translate -x*TextSize.x/2                                         // Centre on x=0 
          rotate x*90                                                       // Rotate onto the XZ plane
          scale <0.0120,1,0.0120>                                           // Scale as required
          translate <Labeller_FaceCentre.x,0,0.052>                         // Align on label
        } 
        object { TextObject
          translate -x*TextSize.x/2                                         // Centre on x=0 
          rotate x*90                                                       // Rotate onto the XZ plane
          scale <0.0120,1,0.0120>                                           // Scale as required
          translate <Labeller_FaceCentre.x,0,0.01>                          // Align on label
        }    
      }
      color <1,1,1,1>
      color PrismGold
    }
  }

  // The word 'POV-Ray' in the middle of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("oldengl.ttf") LabelText11 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[3][11] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0054,1,0.0054>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,0.043>                         // Align on label
      color <1,1,1,1>
      color PrismGold
    } 
  }

  // The word 'Prestigeous' in the middle of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("oldengl.ttf") LabelText12 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[3][12] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0054,1,0.0054>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,0.036>                         // Align on label
      color <1,1,1,1>
      color PrismGold
    } 
  }

  // The word 'Pickled' in the middle of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("oldengl.ttf") LabelText13 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[3][13] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0054,1,0.0054>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,0.029>                         // Align on label
      color <1,1,1,1>
      color PrismGold
    } 
  }

  // The word 'Photons' in the middle of the main panel
  #local TextObject = text {ttf Labeller_FontCheck("oldengl.ttf") LabelText14 1,0}
  #local TextSize = max_extent(TextObject)-min_extent(TextObject);
  #declare Labeller_LabelLayer[3][14] = pigment {
    object { TextObject
      translate -x*TextSize.x/2                                         // Centre on x=0 
      rotate x*90                                                       // Rotate onto the XZ plane
      scale <0.0054,1,0.0054>                                           // Scale as required
      translate <Labeller_FaceCentre.x,0,0.022>                         // Align on label
      color <1,1,1,1>
      color PrismGold 
    } 
  }



  // Back label section (much of which is a copy of the front label section)
  #declare Labeller_LabelLayer[7][ 0] = Labeller_LabelLayer[3][ 0]; 
  #declare Labeller_LabelLayer[7][ 1] = Labeller_LabelLayer[3][ 1]; 
  #declare Labeller_LabelLayer[7][ 2] = Labeller_LabelLayer[3][ 2]; 
  #declare Labeller_LabelLayer[7][10] = Labeller_LabelLayer[3][10]; 
   
  // A block of meaningless small print on the back of the label
  #declare Labeller_LabelLayer[7][3] = pigment {
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
        scale <0.0024,1,0.0024>
      }
      translate <Labeller_FaceCentre.x,0,0.025>   
      color <1,1,1,1>
      color PrismGold
    } 
  }  


#end



