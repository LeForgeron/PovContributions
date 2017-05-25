//
// labeller_hazardsigndesign.inc
// -----------------------------
// Created by Chris Bartlett February 2008
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// This POV-Ray include file uses prism objects that were generated using Inkscape. 
// from public domain SVG files downloaded from http://commons.wikimedia.org/wiki/Category:Hazard_symbols.
// Inkscape is an open source SVG editor available from http://www.inkscape.org.

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
  Labeller_DisplayDesign("labeller_hazardlabel.inc","Rect")
#else  

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[2][60];

  //**************************//
  //     Hazard Symbols       //
  //**************************//
  #ifndef (Hazard_Cross) #include "labeller_hazardsymbols.inc" #end

  //**************************//
  //     Label Texts          //
  //**************************//
  #local LabelText1 = "Hazardous Substance";
  
  #local LabelText2 = array[22] {
    "This is an extremely hazardous material.",
    "If you're close enough to read this",
    "notice you're way too close.  I can't ",
    "emphasize enough how dangerous this",
    "stuff is.  If I were anywhere near this ",
    "container right now I'd be moving ",
    "away very fast. This is so hazardous ",
    "that you shouldn't even be wasting your",
    "time reading this label. That time would",
    "be much better spent running. If",
    "anyone sent you this material you may ",
    "wish to thank them by having it",
    "returned to sender, but I'd recommend ",
    "doing it through a courrier service",
    "that doesn't require you to stick around",
    "while they come and pick it up. ",
    " ",
    "After use, please dispose of the empty",
    "container in an environmentally",
    "friendly manner. The recommended method",
    "is to shoot it into a black hole",
    "at the centre of someone else's galaxy."
  }

  #local LabelText3 = "All in all, really quite Hazardous!";

  #local LabelText11 = array[7] {
    "Irritating and Noxious",
    "Highly Toxic",
    "Explosive Substance",
    "Highly Flammable",
    "Oxidating Substance",
    "Extremely Corrosive",
    "BioHazard"
  }

  #local Labeller_Orange = <0.996, 0.488, 0.000>*Labeller_PigmentIntensity; 
  #local Labeller_Red    = <1,0,0>*Labeller_PigmentIntensity;
  #local Labeller_SymbolBackgroundPigment = pigment {rgb 0}

  #local Labeller_SymbolWidth = Labeller_LabelHeight/8;  
  #local Labeller_SymbolBorderWidth = 0.016;

  // The hazard symbol prism objects each fit into a 500x500 unit square and need to be scaled to fit into the label width and height.
  #local Labeller_SymbolTransform = transform {
    scale <1/500,1,1/500>
    translate -y*1 
    scale Labeller_SymbolWidth
  }

  //**************************//
  //   Layers of pigment      //
  //**************************//
  
  // The white label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb 0.9*Labeller_PigmentIntensity}
  


  // The black border around each of the orange boxes containing the hazard symbols
  #local BlackBox = box {-y,<1,0,1> scale Labeller_SymbolWidth}
  #declare Labeller_LabelLayer[1][1] = pigment {
    object { 
      union {
        object {BlackBox translate 0*z*Labeller_SymbolWidth}
        object {BlackBox translate 1*z*Labeller_SymbolWidth}
        object {BlackBox translate 2*z*Labeller_SymbolWidth}
        object {BlackBox translate 3*z*Labeller_SymbolWidth}
        object {BlackBox translate 4*z*Labeller_SymbolWidth}
        object {BlackBox translate 5*z*Labeller_SymbolWidth}
        object {BlackBox translate 6*z*Labeller_SymbolWidth}
        object {BlackBox translate 7*z*Labeller_SymbolWidth}
      }
      color <1,1,1,1>
      color 0
    } 
  } 

  // The orange boxes containing the hazard symbols
  #local OrangeBox = box {
    <  Labeller_SymbolBorderWidth,-1,  Labeller_SymbolBorderWidth>
    <1-Labeller_SymbolBorderWidth, 0,1-Labeller_SymbolBorderWidth>
//    translate y*Labeller_Delta
    scale Labeller_SymbolWidth
  }
  #declare Labeller_LabelLayer[1][2] = pigment {
    object { 
      union {
        object {OrangeBox translate 0*z*Labeller_SymbolWidth} 
        object {OrangeBox translate 1*z*Labeller_SymbolWidth} 
        object {OrangeBox translate 2*z*Labeller_SymbolWidth} 
        object {OrangeBox translate 3*z*Labeller_SymbolWidth} 
        object {OrangeBox translate 4*z*Labeller_SymbolWidth} 
        object {OrangeBox translate 5*z*Labeller_SymbolWidth} 
        object {OrangeBox translate 6*z*Labeller_SymbolWidth} 
        object {OrangeBox translate 7*z*Labeller_SymbolWidth} 
      }
      color <1,1,1,1>
      color Labeller_Orange
    } 
  } 


  // The individual hazard labels against each hazard symbol
  #local TextScale = 0.0028;
  #declare Labeller_LabelLayer[1][4] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText11,1))
          text {
            ttf Labeller_FontCheck("arial.ttf") LabelText11[LineI] 1, 0 
            translate LineI*y*Labeller_SymbolWidth/TextScale
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
//        translate y*0.1 
        scale <TextScale,1,TextScale>
        translate <Labeller_SymbolWidth*1.2,0,0.004>   
      }
      color <1,1,1,1>
      color Labeller_Orange
    } 
  }

  // The black warning symbols 
  // The following symbols are contained in "labeller_hazardsigns.inc" and may be assigned to Labeller_Symbol:
  // -------------------------------------------------------------------------------------------------------------
  // Hazard symbols, according to directive 67/548/EWG by the European Chemicals Bureau. 
  //   Hazard_ScullAndCrossBones - Toxic or Highly Toxic substances
  //   Hazard_Cross              - Irritating or Noxious substances
  //   Hazard_Explosion          - Explosive substances 
  //   Hazard_Fire               - Flammable or Highly Flammable substances 
  //   Hazard_Oxidation          - Oxidating substances
  //   Hazard_Corrosion          - Corrosive substances    
  //
  // The international biohazard warning symbol published by the World Health Organization.
  //   Hazard_Biohazard          - Biohazard
  #declare Labeller_LabelLayer[1][5] = pigment { 
    object {
      union {
        object {Hazard_Cross              transform {Labeller_SymbolTransform} translate 0*z*Labeller_SymbolWidth}   
        object {Hazard_ScullAndCrossBones transform {Labeller_SymbolTransform} translate 1*z*Labeller_SymbolWidth}   
        object {Hazard_Explosion          transform {Labeller_SymbolTransform} translate 2*z*Labeller_SymbolWidth}   
        object {Hazard_Fire               transform {Labeller_SymbolTransform} translate 3*z*Labeller_SymbolWidth}   
        object {Hazard_Oxidation          transform {Labeller_SymbolTransform} translate 4*z*Labeller_SymbolWidth}   
        object {Hazard_Corrosion          transform {Labeller_SymbolTransform} translate 5*z*Labeller_SymbolWidth}   
        object {Hazard_Biohazard          transform {Labeller_SymbolTransform} translate 6*z*Labeller_SymbolWidth}   
      }
      color <1,1,1,1>
      color 0
    } 
  }  
  


  // The orange box around the writing
  #local OrangeBox = difference {
    box {<Labeller_LabelWidth/2,-1,0>,<Labeller_LabelWidth,0,Labeller_LabelHeight>} 
    box {<Labeller_LabelWidth/2+0.0005,-1,0.0005>,<Labeller_LabelWidth-0.0005,0,Labeller_LabelHeight-0.0005>} 
  }
  #declare Labeller_LabelLayer[1][11] = pigment {
    object { 
      OrangeBox
      color <1,1,1,1>
      color Labeller_Orange
    } 
  }  



  // The title in the box on the right half of the label
  #local TextScale = 0.004;
  #local ThisText =  text {
    ttf Labeller_FontCheck("arial.ttf") LabelText1 1, 0 
    rotate x*90
  }
  #local TextCentre = TextScale*(min_extent(ThisText)+max_extent(ThisText))/2;
  #declare Labeller_LabelLayer[1][15] = pigment { 
    object {
      ThisText 
      scale <TextScale,1,TextScale>
      translate <Labeller_LabelWidth*3/4-TextCentre.x,0,Labeller_LabelHeight-0.01>
      color <1,1,1,1>
      color Labeller_Red
    } 
  }

  // The red line underlining the title in the box on the right half of the label
  #local RedLine = box {<Labeller_LabelWidth*0.57,-1,Labeller_LabelHeight-0.015>,<Labeller_LabelWidth*0.93,0,Labeller_LabelHeight-0.014>} 
  #declare Labeller_LabelLayer[1][16] = pigment {
    object { 
      RedLine
      color <1,1,1,1>
      color Labeller_Red
    } 
  }  

  // The block of print in the box on the right half of the label
  #local TextScale = 0.0018;
  #declare Labeller_LabelLayer[1][17] = pigment {
    object {
      union { 
        #local LineI = 0;
        #while (LineI<dimension_size(LabelText2,1))
          text {
            ttf Labeller_FontCheck("arial.ttf") LabelText2[LineI] 1, 0 
            translate -LineI*y
            rotate x*90
          }
          #local LineI = LineI + 1;
        #end 
        scale <TextScale,1,TextScale>
        translate <Labeller_LabelWidth*0.57,0,Labeller_LabelHeight-0.02>   
      }
      color <1,1,1,1>
      color 0
    } 
  }

  // The warning at the bottom of the box on the right half of the label
  #local TextScale = 0.002;
  #local ThisText =  text {
    ttf Labeller_FontCheck("arial.ttf") LabelText3 1, 0 
    rotate x*90
  }
  #local TextCentre = TextScale*(min_extent(ThisText)+max_extent(ThisText))/2;
  #declare Labeller_LabelLayer[1][18] = pigment { 
    object {
      ThisText 
      scale <TextScale,1,TextScale>
      translate <Labeller_LabelWidth*3/4-TextCentre.x,0,0.01>
      color <1,1,1,1>
      color Labeller_Red
    } 
  }

#end      

