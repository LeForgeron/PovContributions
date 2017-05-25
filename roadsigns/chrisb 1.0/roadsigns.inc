//
// roadsigns.inc
// -------------
// Created by Chris Bartlett March 2008
// This file contains the 'Roadsigns' macros. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 1 metre
//


// This macro generates the panel for a road sign. It requires two parameters: 
//  
//   Style      indicates the type of panel to generate ("Warning" or "Regulatory") 
//   Symbol     provides the name of the symbol to use on the panel, or some text/digits to display on it.
//
#macro Roadsigns_Panel (Style, Symbol)
  #ifndef (sind) #include "math.inc" #end      
  Roadsigns_DefaultSettings()
  #debug concat("\n",Symbol,"\n") 
  #switch (0)
    #case (strcmp(Style,"Warning")) 
      #declare Roadsigns_SymbolScaling = Roadsigns_FaceHeight/0.6;
      #ifndef (Roadsigns_BorderWidth ) #local Roadsigns_BorderWidth  = 0.1  *Roadsigns_FaceHeight;      #end
      #ifndef (Roadsigns_CornerRadius) #local Roadsigns_CornerRadius = 0.75 *Roadsigns_BorderWidth;     #end
      #local Roadsigns_CornerCentreToCentreHeight = Roadsigns_FaceHeight-2*Roadsigns_CornerRadius;
      #local Roadsigns_CornerCentreToCentreWidth  = Roadsigns_CornerCentreToCentreHeight/sind(60); 
      #local Roadsigns_InnerRadius  = 0.5*Roadsigns_CornerCentreToCentreWidth*tand(30) - (Roadsigns_BorderWidth-Roadsigns_CornerRadius);
      #local Roadsigns_InnerTriangleWidth  = 2*Roadsigns_InnerRadius/tand(30);
      #local Roadsigns_CornerCentreRadius  = 0.5*Roadsigns_CornerCentreToCentreWidth/sind(60);
      #local Roadsigns_InnerTriangleHeight = Roadsigns_InnerRadius + Roadsigns_InnerRadius/sind(30);
  
      #local Roadsigns_RimStraightEdge = box {
        <-Roadsigns_CornerCentreToCentreWidth/2,-(Roadsigns_InnerRadius+Roadsigns_BorderWidth),0>
        < Roadsigns_CornerCentreToCentreWidth/2,- Roadsigns_InnerRadius,                       1> 
      }
      #local Roadsigns_RimCorner =   difference {
        cylinder {<0,0,0><0,0,1>,Roadsigns_CornerRadius   
        } 
        box {
          <-(Roadsigns_CornerRadius+Roadsigns_Delta),0                                      , -Roadsigns_Delta>
          <  Roadsigns_CornerRadius+Roadsigns_Delta ,Roadsigns_CornerRadius+Roadsigns_Delta ,1+Roadsigns_Delta>
        }
        translate -y*Roadsigns_CornerCentreRadius
      }
      
      // Assemble the coloured rim to build the front edge of the sign
      #local Roadsigns_TriangularRim = union {
        object {Roadsigns_RimStraightEdge}
        object {Roadsigns_RimStraightEdge rotate z*120}
        object {Roadsigns_RimStraightEdge rotate z*240}
        object {Roadsigns_RimCorner       rotate z* 60}
        object {Roadsigns_RimCorner       rotate z*180}
        object {Roadsigns_RimCorner       rotate z*300}
      }
      
      #local Roadsigns_InnerTriangle = difference {
        box {
          <-Roadsigns_InnerTriangleWidth/2,-Roadsigns_InnerRadius                              ,0>
          < Roadsigns_InnerTriangleWidth/2,-Roadsigns_InnerRadius+Roadsigns_InnerTriangleHeight,1>
        }
        box {
          <-Roadsigns_InnerTriangleWidth/2,-Roadsigns_InnerRadius                              , -Roadsigns_Delta>
          < Roadsigns_InnerTriangleWidth/2,-Roadsigns_InnerRadius-Roadsigns_InnerTriangleHeight,1+Roadsigns_Delta> 
          rotate z*120
        }
        box {
          <-Roadsigns_InnerTriangleWidth/2,-Roadsigns_InnerRadius                              , -Roadsigns_Delta>
          < Roadsigns_InnerTriangleWidth/2,-Roadsigns_InnerRadius-Roadsigns_InnerTriangleHeight,1+Roadsigns_Delta> 
          rotate z*240
        }
      }
    
      // Assemble the road sign and apply the appropriate textures
      union {  // p500   
        object {Roadsigns_TriangularRim
          scale <1,1,0.1*Roadsigns_Thickness>
          translate -z*Roadsigns_Thickness
          texture {
            pigment {rgb Roadsigns_SignalRed}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_DirtTexture}
        } 
        object {Roadsigns_InnerTriangle 
          scale <1,1,0.1*Roadsigns_Thickness>
          translate -z*Roadsigns_Thickness
          texture {
            pigment {rgb Roadsigns_White}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_SymbolTexture(Symbol) scale Roadsigns_SymbolScaling translate -z*0.5}
          texture {Roadsigns_DirtTexture}
        }
        // The back of the sign
        object {Roadsigns_TriangularRim
          scale <1,1,0.9*Roadsigns_Thickness>
          translate -0.9*z*Roadsigns_Thickness
          texture {Roadsigns_GreyBack} 
          texture {Roadsigns_DirtTexture}
        } 
        object {Roadsigns_InnerTriangle 
          scale <1,1,0.9*Roadsigns_Thickness>
          translate -0.9*z*Roadsigns_Thickness
          texture {Roadsigns_GreyBack} 
          texture {Roadsigns_DirtTexture}
        }
      }
    #break
    #case (strcmp(Style,"Regulatory"))
      #declare Roadsigns_SymbolScaling = Roadsigns_Diameter/0.6;
      #ifndef (Roadsigns_BorderWidth) #local Roadsigns_BorderWidth  = 0.1*Roadsigns_Diameter;  #end
      union {            // p600 
        // The back of the sign
        cylinder {-0.9*z*(Roadsigns_Thickness),0,Roadsigns_Diameter/2
          texture {Roadsigns_GreyBack} 
          texture {Roadsigns_DirtTexture}
        }
        // The red border
        difference {
          cylinder {-z* Roadsigns_Thickness                 ,-0.9*z*Roadsigns_Thickness                  ,Roadsigns_Diameter/2}
          cylinder {-z*(Roadsigns_Thickness+Roadsigns_Delta),-0.9*z*(Roadsigns_Thickness+Roadsigns_Delta),Roadsigns_Diameter/2-Roadsigns_BorderWidth}
          pigment {rgb Roadsigns_SignalRed}
          texture {
            pigment {rgb Roadsigns_SignalRed}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_DirtTexture}
        }
        // The white centre
        cylinder {-z*(Roadsigns_Thickness),-0.9*z*Roadsigns_Thickness,Roadsigns_Diameter/2-Roadsigns_BorderWidth
          texture {
            pigment {rgb Roadsigns_White}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_SymbolTexture(Symbol) scale Roadsigns_SymbolScaling translate -z*0.5}
          texture {Roadsigns_DirtTexture}
        } 
      }
    #break 
    #case (strcmp(Style,"Compulsory"))
      #declare Roadsigns_SymbolScaling = Roadsigns_Diameter/0.6;
      #ifndef (Roadsigns_BorderWidth) #local Roadsigns_BorderWidth  = 0.1*Roadsigns_Diameter;  #end
      union {
        // The back of the sign
        cylinder {-0.9*z*(Roadsigns_Thickness),0,Roadsigns_Diameter/2
          texture {Roadsigns_GreyBack} 
          texture {Roadsigns_DirtTexture}
        } 
        // The front of the sign
        cylinder {-z* Roadsigns_Thickness,-0.9*z*Roadsigns_Thickness,Roadsigns_Diameter/2
          texture {
            pigment {rgb Roadsigns_MiddleBlue}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_SymbolTexture(Symbol) scale Roadsigns_SymbolScaling translate -z*0.5}
          texture {Roadsigns_DirtTexture}
        }
        // The white band around the perimeter
        difference {
          cylinder {-z*(Roadsigns_Thickness+  Roadsigns_Delta),-0.9*z*(Roadsigns_Thickness+  Roadsigns_Delta),(585/600)*Roadsigns_Diameter/2}
          cylinder {-z*(Roadsigns_Thickness+2*Roadsigns_Delta),-0.9*z*(Roadsigns_Thickness+2*Roadsigns_Delta),(568/600)*Roadsigns_Diameter/2}
          texture {
            pigment {rgb Roadsigns_White}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_DirtTexture}
        }
      }
    #break
    #case (strcmp(Style,"Hazard"))
      #declare Roadsigns_SymbolScaling = Roadsigns_FaceHeight/0.6;
      #local CentrePoint = <75.181,0,15+(122.948*tand(30)/2)>; 
      #local PrismScale  = <1.1,1,1.1>*<0.6/123,1,0.6/123>*Roadsigns_SymbolScaling;
      // The border width isn't used for the border of this sign, but it is used for scaling other elements 
      #ifndef (Roadsigns_BorderWidth) #local Roadsigns_BorderWidth  = 0.1*Roadsigns_FaceHeight;  #end
      union {
        // The back of the sign
        prism {
          linear_sweep
          bezier_spline
          Roadsigns_Thickness*0.9, //top
          0,  //bottom
          40, //nr points
          /*   0*/ <75.040418, 120.650601>, <72.939280, 120.609814>, <70.674637,119.686282>, <69.358315,117.655311>,
          /*   1*/ <69.358315, 117.655311>, <69.358315, 117.655311>, <13.707238,22.904858>, <13.707238,22.904858>,
          /*   2*/ <13.707238, 22.904858>, <10.663191, 17.038518>, <14.496778,12.610158>, <19.374346,12.610158>,
          /*   3*/ <19.374346, 12.610158>, <19.374346, 12.610158>, <130.959720,12.610158>, <130.959720,12.610158>,
          /*   4*/ <130.959720, 12.610158>, <136.096640, 12.610148>, <138.792480,18.744048>, <136.655170,23.255198>,
          /*   5*/ <136.655170, 23.255198>, <136.655170, 23.255198>, <80.639164,117.540401>, <80.639164,117.540401>,
          /*   6*/ <80.639164, 117.540401>, <79.484852, 119.260210>, <77.141554,120.691388>, <75.040418,120.650601>,
          /*   7*/ <75.105477, 111.056589>, <75.105477, 111.056589>, <128.097840,20.560248>, <128.097840,20.560248>,
          /*   8*/ <128.097840, 20.560248>, <128.097840, 20.560248>, <22.377915,20.479398>, <22.377915,20.479398>,
          /*   9*/ <22.377915, 20.479398>, <22.377915, 20.479398>, <75.105477,111.056589>, <75.105477,111.056589>
          texture {Roadsigns_GreyBack} 
          texture {Roadsigns_DirtTexture}
          translate -CentrePoint
          scale PrismScale
          rotate -x*90 
        }
        // The front of the sign 
        // Thick Black Band around Edge
        prism {
          linear_sweep
          bezier_spline
          Roadsigns_Thickness, //top
          Roadsigns_Thickness*0.9, //bottom
          40, //nr points
          /*   0*/ <75.040418, 120.650601>, <72.939280, 120.609814>, <70.674637,119.686282>, <69.358315,117.655311>,
          /*   1*/ <69.358315, 117.655311>, <69.358315, 117.655311>, <13.707238,22.904858>, <13.707238,22.904858>,
          /*   2*/ <13.707238, 22.904858>, <10.663191, 17.038518>, <14.496778,12.610158>, <19.374346,12.610158>,
          /*   3*/ <19.374346, 12.610158>, <19.374346, 12.610158>, <130.959720,12.610158>, <130.959720,12.610158>,
          /*   4*/ <130.959720, 12.610158>, <136.096640, 12.610148>, <138.792480,18.744048>, <136.655170,23.255198>,
          /*   5*/ <136.655170, 23.255198>, <136.655170, 23.255198>, <80.639164,117.540401>, <80.639164,117.540401>,
          /*   6*/ <80.639164, 117.540401>, <79.484852, 119.260210>, <77.141554,120.691388>, <75.040418,120.650601>,
          /*   7*/ <75.105477, 111.056589>, <75.105477, 111.056589>, <128.097840,20.560248>, <128.097840,20.560248>,
          /*   8*/ <128.097840, 20.560248>, <128.097840, 20.560248>, <22.377915,20.479398>, <22.377915,20.479398>,
          /*   9*/ <22.377915, 20.479398>, <22.377915, 20.479398>, <75.105477,111.056589>, <75.105477,111.056589>
          translate -CentrePoint
          scale PrismScale
          rotate -x*90 
          texture {
            pigment {rgb Roadsigns_Black}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_DirtTexture}
        }
        // Thin White Line on the Black Band
        prism {
          linear_sweep
          bezier_spline
          Roadsigns_Thickness+Roadsigns_Delta, //top
          Roadsigns_Thickness*0.9, //bottom
          48, //nr points
          /*   0*/ <70.850177, 116.770384>, <70.850177, 116.770384>, <14.875740,21.688278>, <14.875740,21.688278>,
          /*   1*/ <14.875740, 21.688278>, <13.288950, 18.370138>, <15.112734,14.236748>, <19.466098,14.174958>,
          /*   2*/ <19.466098, 14.174958>, <19.466098, 14.174958>, <130.654780,14.283068>, <130.654780,14.283068>,
          /*   3*/ <130.654780, 14.283068>, <134.457890, 14.221288>, <136.746930,19.227258>, <134.933450,22.282858>,
          /*   4*/ <134.933450, 22.282858>, <134.933450, 22.282858>, <79.488592,116.706562>, <79.488592,116.706562>,
          /*   5*/ <79.488592, 116.706562>, <77.346617, 119.677985>, <73.233101,120.029060>, <70.850177,116.770384>,
          /*   6*/ <77.886831, 114.920894>, <77.886831, 114.920894>, <132.949960,21.418018>, <132.949960,21.418018>,
          /*   7*/ <132.949960, 21.418018>, <134.264730, 19.350498>, <132.416850,16.228948>, <129.719700,16.228958>,
          /*   8*/ <129.719700, 16.228958>, <129.719700, 16.228958>, <20.287830,16.255988>, <20.287830,16.255988>,
          /*   9*/ <20.287830, 16.255988>, <17.454918, 16.169498>, <15.776810,18.091058>, <17.227590,20.634238>,
          /*  10*/ <17.227590, 20.634238>, <17.227590, 20.634238>, <72.339199,114.920894>, <72.339199,114.920894>,
          /*  11*/ <72.339199, 114.920894>, <74.139642, 117.556159>, <76.397224,117.549991>, <77.886831,114.920894>
          translate -CentrePoint
          scale PrismScale
          rotate -x*90 
          texture {
            pigment {rgb Roadsigns_White}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_DirtTexture}
        }
        
        prism {
          linear_sweep
          bezier_spline
          Roadsigns_Thickness, //top
          Roadsigns_Thickness*0.9, //bottom
          12, //nr points
          /*   0*/ <75.139661, 111.089291>, <75.139661, 111.089291>, <128.132030,20.592948>, <128.132030,20.592948>,
          /*   1*/ <128.132030, 20.592948>, <128.132030, 20.592948>, <22.412099,20.512098>, <22.412099,20.512098>,
          /*   2*/ <22.412099, 20.512098>, <22.412099, 20.512098>, <75.139661,111.089291>, <75.139661,111.089291>
          translate -CentrePoint
          scale PrismScale
          rotate -x*90 
          texture {
            pigment {rgb Roadsigns_Orange}
            normal  {Roadsigns_Normal}
            finish  {Roadsigns_Finish}
          }
          texture {Roadsigns_SymbolTexture(Symbol) scale Roadsigns_SymbolScaling translate -z*0.5}
          texture {Roadsigns_DirtTexture}
        }        
      }
    #break
  #end

#end 


// This utility macro takes an object that is passed to it and returns a pigment
// It also centres the object at the origin and turns it through -90 degrees around the x axis.
// It requires 3 parameters:
//   SymbolObject     a POV-Ray object suitable for use as a pigment (one with a well defined inside and outside)
//   ExteriorColour   a colour value for everything outside the object
//   InteriorColour   a colour value for everything inside the object
// 
#macro Roadsigns_PrismToTexture(SymbolObject, ExteriorColour, InteriorColour) 
  #local Roadsigns_SymbolCentre = (min_extent(SymbolObject)+max_extent(SymbolObject))/2;
  pigment {
    object {SymbolObject
      translate <-Roadsigns_SymbolCentre.x,-1,-Roadsigns_SymbolCentre.z>
      rotate -x*90
      color ExteriorColour
      color InteriorColour      
    }
  }
  normal  {Roadsigns_Normal}
  finish  {Roadsigns_Finish}
#end

// This macro works out which symbol file to include and which macro to call to generate a texture for the required symbol.
// This macro requires one parameter:
//
//   Symbol      The name of the symbol to display. Otherwise text to display e.g. "50"
// 
#macro Roadsigns_SymbolTexture(Symbol)
  Roadsigns_DefaultSettings() 
  // Work out which file we're supposed to be able to find the symbol in
  #if (file_exists(Roadsigns_SymbolFile)=0) #declare Roadsigns_SymbolFile = "roadsigns_uksymbols.inc"; #end
  // Each symbol file is handled as a separate case.
  #switch (0)
    #case (strcmp(Roadsigns_SymbolFile,"roadsigns_uksymbols.inc")) 
      #ifndef (Roadsigns_Aircraft)  #include "roadsigns_uksymbols.inc" #end 
      Roadsigns_UKSymbolTexture(Symbol)
    #break
    #case (strcmp(Roadsigns_SymbolFile,"roadsigns_hazardsymbols.inc")) 
      #ifndef (Hazard_Cross)  #include "roadsigns_hazardsymbols.inc" #end 
      Roadsigns_HazardSymbolTexture(Symbol)
    #break
    #else 
      #include Roadsigns_SymbolFile
      Roadsigns_HazardSymbolTexture(Symbol)   
  #end
#end
 


// This macro tries to find the specified symbol in the uk symbols file and returns a texture using the symbol as an 
// object pattern. If it's not in the list it simply returns it as a piece of text converted to a texture.
// This macro requires one parameter:
//
//   SymbolName      The name of the symbol to display. Otherwise text to display e.g. "50"
// 
#macro Roadsigns_UKSymbolTexture(SymbolName) 
  // Symbols all get centred on the origin. Their POV-Ray centre is not necessarily the centre required to position the object 
  // correctly on the appropriate sign, so an 'offset' may need to be applied. This offset is measure in border widths using the
  // width of the border as 1 unit. The standard offsets below position the symbols for their standard sign type. 
  #local Roadsigns_SymbolOffset = <0,0,0>;
  #local Roadsigns_ScaleFactor  = <1/750,1/750,1>;
  #switch (0)
    /*******************************/
    /*      Warning Symbols        */
    /*******************************/
    #case (strcmp(SymbolName,"Aircraft"))
      #local Roadsigns_SymbolOffset = < 0   ,-0.3 ,0>;  // Aircraft
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_Aircraft,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Cattle"))  
      #local Roadsigns_SymbolOffset = <-0.1 ,-0.55,0>;  // Cattle
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_Cattle,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Sidewinds"))  
      #local Roadsigns_SymbolOffset = < 0.2 ,-0.5 ,0>;  // Sidewinds
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_Sidewinds,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"OpeningBridge"))  
      #local Roadsigns_SymbolOffset = < 0   , 0.3 ,0>;  // OpeningBridge        
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_OpeningBridge,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"DualCarriagewayEnds"))  
      #local Roadsigns_SymbolOffset = < 0   , 0.7 ,0>;  // DualCarriagewayEnds
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_DualCarriagewayEnds,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"FallingRocks"))  
      #local Roadsigns_SymbolOffset = <-0.3 , 0.33,0>;  // FallingRocks 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_FallingRocks,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"RiskOfGrounding"))  
      #local Roadsigns_SymbolOffset = < 0   ,-0.6 ,0>;  // RiskOfGrounding
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_RiskOfGrounding,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"WildHorses"))  
      #local Roadsigns_SymbolOffset = <-0.3 ,-0.35,0>;  // WildHorses 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_WildHorses,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"HumpBridge"))  
      #local Roadsigns_SymbolOffset = < 0   ,-0.6 ,0>;  // HumpBridge 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_HumpBridge,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"JunctionOnBend"))  
      #local Roadsigns_SymbolOffset = <-0.2 ,-0.1 ,0>;  // JunctionOnBend 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_JunctionOnBend,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"MenAtWork"))  
      #local Roadsigns_SymbolOffset = <-0.5 , 0.23,0>;  // MenAtWork 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_MenAtWork,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"RoadNarrowsBothSides"))  
      #local Roadsigns_SymbolOffset = < 0   , 0.3 ,0>;  // RoadNarrowsBothSides 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_RoadNarrowsBothSides,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"RoadNarrowsOnRight"))  
      #local Roadsigns_SymbolOffset = < 0.3 , 0.3 ,0>;  // RoadNarrowsOnRight 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_RoadNarrowsOnRight,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"RoadNarrowsOnLeft"))  
      #local Roadsigns_SymbolOffset = <-0.3 , 0.3 ,0>;  // RoadNarrowsOnLeft 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_RoadNarrowsOnLeft,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"FrailPedestrians"))  
      #local Roadsigns_SymbolOffset = <-0.3 , 0.2 ,0>;  // FrailPedestrians 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_FrailPedestrians,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"LevelCrossingWithBarrier"))  
      #local Roadsigns_SymbolOffset = < 0   ,-0.8 ,0>;  // LevelCrossingWithBarrier 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_LevelCrossingWithBarrier,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Roundabout"))  
      #local Roadsigns_SymbolOffset = < 0   , 0   ,0>;  // Roundabout 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_Roundabout,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"StaggeredJunction"))  
      #local Roadsigns_SymbolOffset = <-0.3 , 0.4 ,0>;  // StaggeredJunction 
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_StaggeredJunction,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"LevelCrossingWithoutBarrier"))  
      #local Roadsigns_SymbolOffset = < 0.1 , 0.1 ,0>;  // LevelCrossingWithoutBarrier
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_LevelCrossingWithoutBarrier,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"TramcarCrossing"))  
      #local Roadsigns_SymbolOffset = < 0   ,-0.7 ,0>;  // TramcarCrossing   
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_TramcarCrossing,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"TwoWayTraffic"))  
      #local Roadsigns_SymbolOffset = < 0.25, 0.1 ,0>;  // TwoWayTraffic   
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_TwoWayTraffic,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"TwoWayTrafficCrossing"))  
      #local Roadsigns_SymbolOffset = <-0.5 ,-0.5 ,0>;  // TwoWayTrafficCrossing   
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_TwoWayTrafficCrossing,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Quayside"))  
      #local Roadsigns_SymbolOffset = <-0.05, 0.25,0>;  // Quayside   
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_Quayside,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"WildAnimals"))  
      #local Roadsigns_SymbolOffset = <-0.15, 0.4 ,0>;  // WildAnimals   
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_WildAnimals,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"DoubleBendLeft"))  
      #local Roadsigns_SymbolOffset = < 0.3 , 0   ,0>;  // DoubleBendLeft   
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_DoubleBendLeft,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"DoubleBendRight"))  
      #local Roadsigns_SymbolOffset = <-0.3 , 0   ,0>;  // DoubleBendRight   
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_DoubleBendRight,<1,1,1,1>,<0,0,0>)}
    #break 
    
    /*******************************/
    /*      Regulatory Symbols     */
    /*******************************/
    #case (strcmp(SymbolName,"NoCarsOrBikes"))  
      #local Roadsigns_SymbolOffset = < 0.2 , 0.3 ,0>;  // NoCarsOrBikes  
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_NoCarsOrBikes,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"NoExplosives"))  
      #local Roadsigns_SymbolOffset = < 0   , 0 ,0>;    // NoExplosives  
      #local Roadsigns_ThisSymbolTexture1 = texture {
        Roadsigns_PrismToTexture(Roadsigns_NoExplosivesCloud,<1,1,1,1>,<1,0.5,0>) 
        // The macro centres the texture, we need to adjust the position of the explosion cloud above the car 
        translate Roadsigns_BorderWidth*<0.15,1.85,0>/Roadsigns_ScaleFactor
      }
      #local Roadsigns_ThisSymbolTexture2 = texture {Roadsigns_PrismToTexture(Roadsigns_NoExplosives,<1,1,1,1>,<0,0,0>)}
      #local Roadsigns_ThisSymbolTexture  =
        texture {Roadsigns_ThisSymbolTexture1}
        texture {Roadsigns_ThisSymbolTexture2}
    #break 
    #case (strcmp(SymbolName,"MaxTruckWeight"))  
      #local Roadsigns_SymbolOffset = < 0 , 0 ,0>;     // MaxTruckWeight  
      #local Roadsigns_ThisSymbolTexture1 = texture {Roadsigns_PrismToTexture(Roadsigns_MaxTruckWeight,<1,1,1,1>,<0,0,0>)}
      // Add text to indicate the actual length limit of the truck
      #local SymbolObject = union {
        text {ttf "arialbd.ttf" "7." 1,0
          scale <0.23*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.x,0.23*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.y,1>
        }
        text {ttf "arialbd.ttf" "5" 1,0
          scale <0.16*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.x,0.16*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.y,1>
          translate <0.18*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.x,0.02*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.y,0>
        }
        text {ttf "arialbd.ttf" "T" 1,0
          scale <0.16*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.x,0.16*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.y,1> 
          translate <0.28*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.x,0.04*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.y,0>
        }
      } 
      #local Roadsigns_SymbolCentre = (min_extent(SymbolObject)+max_extent(SymbolObject))/2;
      #local Roadsigns_ThisSymbolTexture2 = texture {
        pigment {
          object {SymbolObject
            translate <-Roadsigns_SymbolCentre.x,-Roadsigns_SymbolCentre.y,0> 
            translate <0.105*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.x,0.035*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.y,0>
            color <1,1,1,1>
            color <1,1,1>      
          }
        }
        normal  {Roadsigns_Normal}
        finish  {Roadsigns_Finish}
      }
      #local Roadsigns_ThisSymbolTexture  =
        texture {Roadsigns_ThisSymbolTexture1}
        texture {Roadsigns_ThisSymbolTexture2}
    #break
    #case (strcmp(SymbolName,"MaxTruckLength"))  
      #local Roadsigns_SymbolOffset = < 0 , -0.2 ,0>;  // MaxTruckLength  
      #local Roadsigns_ThisSymbolTexture1 = texture {Roadsigns_PrismToTexture(Roadsigns_MaxTruckLength,<1,1,1,1>,<0,0,0>)}
      // Add text to indicate the actual length limit of the truck
      #ifndef (Roadsigns_SymbolText) #declare Roadsigns_SymbolText = "32' - 6\"" #end
      #local SymbolObject = text {ttf "arialbd.ttf" Roadsigns_SymbolText 1,0
        scale <0.16*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.x,0.16*Roadsigns_FaceHeight/Roadsigns_ScaleFactor.y,1>
      } 
      #local Roadsigns_SymbolCentre = (min_extent(SymbolObject)+max_extent(SymbolObject))/2;
      #local Roadsigns_ThisSymbolTexture2 = texture {
        pigment {
          object {SymbolObject
            translate <-Roadsigns_SymbolCentre.x,-Roadsigns_SymbolCentre.y,0> 
            translate -0.07*y*Roadsigns_FaceHeight/Roadsigns_ScaleFactor
            color <1,1,1,1>
            color <0,0,0>      
          }
        }
        normal  {Roadsigns_Normal}
        finish  {Roadsigns_Finish}
      }
      #local Roadsigns_ThisSymbolTexture  =
        texture {Roadsigns_ThisSymbolTexture1}
        texture {Roadsigns_ThisSymbolTexture2}
    #break   
    
    /*******************************/
    /*     Compulsory Symbols      */
    /*******************************/
    #case (strcmp(SymbolName,"KeepLeft"))  
      #local Roadsigns_SymbolOffset = < 0.2 , 0.1 ,0>;  // KeepLeft  
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_KeepLeft,<1,1,1,1>,<1,1,1>)}
    #break
    #case (strcmp(SymbolName,"KeepRight"))  
      #local Roadsigns_SymbolOffset = < -0.2, 0.1 ,0>;  // KeepRight  
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_KeepRight,<1,1,1,1>,<1,1,1>)}
    #break
    #case (strcmp(SymbolName,"TurnLeftAhead"))  
      #local Roadsigns_SymbolOffset = < -0.6,0.1 ,0>;  // TurnLeftAhead  
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_TurnLeftAhead,<1,1,1,1>,<1,1,1>)}
    #break
    #case (strcmp(SymbolName,"TurnRightAhead"))  
      #local Roadsigns_SymbolOffset = < 0.6, 0.1 ,0>;  // TurnRightAhead  
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_TurnRightAhead,<1,1,1,1>,<1,1,1>)}
    #break
    #case (strcmp(SymbolName,"PassEitherSide"))  
      #local Roadsigns_SymbolOffset = < 0, 0 ,0>;    // PassEitherSide  
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Roadsigns_PassEitherSide,<1,1,1,1>,<1,1,1>)}
    #break
    

    #else 
     
    /*******************************/
    /*    Text and/or  Numerals    */
    /*******************************/
    // If none of the above worked, simply return the text as a pigment
    #local Roadsigns_ScaleFactor = 1;
    #local Roadsigns_SymbolOffset = 0; 
    #if (strlen(SymbolName)>2) 
      #local ScaleText = 2/strlen(SymbolName); 
    #else 
      #local ScaleText = 1; 
    #end
    #local SymbolObject = text {ttf "arialbd.ttf" SymbolName 1,0
      scale <0.6*Roadsigns_FaceHeight*ScaleText,0.6*Roadsigns_FaceHeight*ScaleText,1>
    }
    #local Roadsigns_SymbolCentre = (min_extent(SymbolObject)+max_extent(SymbolObject))/2;
    #local Roadsigns_ThisSymbolTexture = texture {
      pigment {
        object {SymbolObject
          translate <-Roadsigns_SymbolCentre.x,-Roadsigns_SymbolCentre.y,0>
          color <1,1,1,1>
          color <0,0,0>      
        }
      }
      normal  {Roadsigns_Normal}
      finish  {Roadsigns_Finish}
    }
  #end  
  Roadsigns_ThisSymbolTexture
  scale Roadsigns_ScaleFactor
  translate Roadsigns_SymbolOffset*Roadsigns_BorderWidth

#end  


// This macro tries to find the specified symbol in the hazard symbols file and returns a texture using the symbol as an 
// object pattern. If it's not in the list it simply returns it as a piece of text converted to a texture.
// This macro requires one parameter:
//
//   SymbolName      The name of the symbol to display. Otherwise text to display e.g. "50"
// 
#macro Roadsigns_HazardSymbolTexture(SymbolName) 
  // Symbols all get centred on the origin. Their POV-Ray centre is not necessarily the centre required to position the object 
  // correctly on the appropriate sign, so an 'offset' may need to be applied. This offset is measure in border widths using the
  // width of the border as 1 unit. The standard offsets below position the symbols for their standard sign type. 
  #local Roadsigns_SymbolOffset = <0,0,0>;
  #local Roadsigns_ScaleFactor  = <1/1500,1/1500,1>;
  #switch (0) 
  
    /*******************************/
    /*      Hazard Symbols        */
    /*******************************/
    #case (strcmp(SymbolName,"ScullAndCrossBones"))
      #local Roadsigns_SymbolOffset = <0,0.2,0>;  // ScullAndCrossBones
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Hazard_ScullAndCrossBones,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Cross"))
      #local Roadsigns_SymbolOffset = <0,-0.2,0>;  // Cross
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Hazard_Cross,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Explosion"))
      #local Roadsigns_SymbolOffset = <-0.2,-0.3,0>; // Explosion
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Hazard_Explosion,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Fire"))
      #local Roadsigns_SymbolOffset = <0,0.2,0>;  // Fire
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Hazard_Fire,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Oxidation"))
      #local Roadsigns_SymbolOffset = <0,0.3,0>;  // Oxidation
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Hazard_Oxidation,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Corrosion"))
      #local Roadsigns_SymbolOffset = <0,0.3,0>;  // Corrosion
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Hazard_Corrosion,<1,1,1,1>,<0,0,0>)}
    #break
    #case (strcmp(SymbolName,"Biohazard"))
      #local Roadsigns_SymbolOffset = <0,0.2,0>;  // Biohazard
      #local Roadsigns_ThisSymbolTexture = texture {Roadsigns_PrismToTexture(Hazard_Biohazard,<1,1,1,1>,<0,0,0>)}
    #break

    #else 
     
    /*******************************/
    /*    Text and/or Numerals     */
    /*******************************/
    // If none of the above worked, simply return the text as a pigment
    #local Roadsigns_ScaleFactor = 1;
    #local Roadsigns_SymbolOffset = 0;
    #local SymbolObject = text {ttf "arialbd.ttf" SymbolName 1,0 scale <0.6*Roadsigns_FaceHeight,0.6*Roadsigns_FaceHeight,1>} 
    #local Roadsigns_SymbolCentre = (min_extent(SymbolObject)+max_extent(SymbolObject))/2;
    #local Roadsigns_ThisSymbolTexture = texture {
      pigment {
        object {SymbolObject
          translate <-Roadsigns_SymbolCentre.x,-Roadsigns_SymbolCentre.y,0>
          color <1,1,1,1>
          color <0,0,0>      
        }
      }
      normal  {Roadsigns_Normal}
      finish  {Roadsigns_Finish}
    }
  #end  
  Roadsigns_ThisSymbolTexture
  scale Roadsigns_ScaleFactor
  translate Roadsigns_SymbolOffset*Roadsigns_BorderWidth

#end   


// This macro assigns default values to any key control variables that are not yet set.
#macro Roadsigns_DefaultSettings()
  #ifndef (Roadsigns_SymbolFile) #declare Roadsigns_SymbolFile     = "roadsigns_uksymbols.inc";  #end 
  #ifndef (Roadsigns_Thickness ) #declare Roadsigns_Thickness      = 0.003;                      #end
  #ifndef (Roadsigns_Diameter  ) #declare Roadsigns_Diameter       = 0.6;                        #end
  #ifndef (Roadsigns_FaceHeight) #declare Roadsigns_FaceHeight     = 0.6;                        #end
  #ifndef (Roadsigns_SignalRed ) #declare Roadsigns_SignalRed      = 0.8*<222, 52, 57>/255;      #end 
  #ifndef (Roadsigns_MiddleBlue) #declare Roadsigns_MiddleBlue     =     <  0,117,189>/255;      #end 
  #ifndef (Roadsigns_Orange    ) #declare Roadsigns_Orange         = 0.8*<255,203,  0>/255;      #end 
  #ifndef (Roadsigns_White     ) #declare Roadsigns_White          = 1;                          #end 
  #ifndef (Roadsigns_Black     ) #declare Roadsigns_Black          = 0;                          #end 
  #ifndef (Roadsigns_GreyBack  ) #declare Roadsigns_GreyBack       = texture {pigment {rgb 0.5}} #end
  #ifndef (Roadsigns_Normal    ) #declare Roadsigns_Normal         = normal {agate 0}            #end
  #ifndef (Roadsigns_Finish    ) #declare Roadsigns_Finish         = finish {reflection 0}       #end
  #ifndef (Roadsigns_Delta     ) #declare Roadsigns_Delta          = 0.0000001;                  #end 
  #ifndef (Roadsigns_DirtTexture)
    #declare Roadsigns_DirtTexture = texture {
      pigment {rgbt 1}
      normal {agate 0}  
      finish {reflection 0}
    }                    
  #end
#end


// This macro resets key control variables so that they can revert to default values.
#macro Roadsigns_Undef()
  #ifdef (Roadsigns_Thickness   ) #undef Roadsigns_Thickness     #end
  #ifdef (Roadsigns_Diameter    ) #undef Roadsigns_Diameter      #end
  #ifdef (Roadsigns_FaceHeight  ) #undef Roadsigns_FaceHeight    #end
  #ifdef (Roadsigns_SignalRed   ) #undef Roadsigns_SignalRed     #end
  #ifdef (Roadsigns_White       ) #undef Roadsigns_White         #end
  #ifdef (Roadsigns_Orange      ) #undef Roadsigns_Orange        #end
  #ifdef (Roadsigns_GreyBack    ) #undef Roadsigns_GreyBack      #end
  #ifdef (Roadsigns_Delta       ) #undef Roadsigns_Delta         #end
  #ifdef (Roadsigns_BorderWidth ) #undef Roadsigns_BorderWidth   #end
  #ifdef (Roadsigns_CornerRadius) #undef Roadsigns_CornerRadius  #end 
  #ifdef (Roadsigns_SymbolText  ) #undef Roadsigns_SymbolText    #end  
  #ifdef (Roadsigns_SymbolFile  ) #undef Roadsigns_SymbolFile    #end
  #ifdef (Roadsigns_Finish      ) #undef Roadsigns_Finish        #end
  #ifdef (Roadsigns_Delta       ) #undef Roadsigns_Delta         #end
  #ifdef (Roadsigns_DirtTexture ) #undef Roadsigns_DirtTexture   #end
#end

