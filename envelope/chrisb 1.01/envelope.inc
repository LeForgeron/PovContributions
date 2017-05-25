// envelope.inc
// ------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This include file contains the Envelope_ macro which creates an envelope based upon the settings of 
// a range of control variables, as documented in the envelope.html file accompanying this file.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// Render times are typically a few seconds for a single envelope.

#include "envelope_textures.inc"
#ifndef(cosd) #include "math.inc" #end 


//
// The Envelope_ macro is used to generate an envelope object
// The 'EnvelopeType' parameter is provides future support for alternative generation algorithms
// This parameter is a string. The only value currently supported is "Quicky". 
// The characteristics of the envelope are controlled through variables which all have default settings 
//
#macro Envelope()
  //****************************************************//
  //    Set Default values for all Control Variables    //
  //****************************************************// 
  #ifndef (Envelope_Style) #declare Envelope_Style = "business"; #end

  // Define default sizes for all components
  #ifndef (Envelope_Width)            #declare Envelope_Width            = 0.23;    #end 
  #ifndef (Envelope_Depth)            #declare Envelope_Depth            = 0.16;    #end
  #ifndef (Envelope_Thickness)        #declare Envelope_Thickness        = 0.0015;  #end
  #ifndef (Envelope_LabelWidth)       #declare Envelope_LabelWidth       = Envelope_Width/2;        #end  
  #ifndef (Envelope_LabelDepth)       #declare Envelope_LabelDepth       = Envelope_Depth/3;        #end
  #ifndef (Envelope_LabelThickness)   #declare Envelope_LabelThickness   = 0.0003;  #end              
  #ifndef (Envelope_LabelRounding)    #declare Envelope_LabelRounding    = 0.008;   #end              
  #ifndef(Envelope_LabelLeftEdge   )  #declare Envelope_LabelLeftEdge    = (Envelope_Width-Envelope_LabelWidth)/2;  #end
  #ifndef(Envelope_LabelBottomEdge )  #declare Envelope_LabelBottomEdge  = (Envelope_Depth-Envelope_LabelDepth)/2;  #end
  #ifndef (Envelope_WindowWidth)      #declare Envelope_WindowWidth      = Envelope_Width/2;        #end  
  #ifndef (Envelope_WindowDepth)      #declare Envelope_WindowDepth      = Envelope_Depth/3;        #end
  #ifndef (Envelope_WindowRounding)   #declare Envelope_WindowRounding   = Envelope_WindowWidth/12; #end 
  #ifndef(Envelope_WindowLeftEdge  )  #declare Envelope_WindowLeftEdge   = (Envelope_Width-Envelope_WindowWidth)/2; #end
  #ifndef(Envelope_WindowBottomEdge)  #declare Envelope_WindowBottomEdge = (Envelope_Depth-Envelope_WindowDepth)/2; #end
  #ifndef (Envelope_StampWidth)       #declare Envelope_StampWidth       = 0.02;    #end  
  #ifndef (Envelope_StampDepth)       #declare Envelope_StampDepth       = 0.023;   #end
  #ifndef (Envelope_StampThickness)   #declare Envelope_StampThickness   = 0.0002;  #end
  #ifndef (Envelope_StampHoleSize)    #declare Envelope_StampHoleSize    = 0.0005;  #end  
  #ifndef (Envelope_StampBorderSize)  #declare Envelope_StampBorderSize  = 0.0015;  #end 
  #ifndef(Envelope_StampInsetRight )  #declare Envelope_StampInsetRight  = 0.01; #end
  #ifndef(Envelope_StampInsetTop   )  #declare Envelope_StampInsetTop    = 0.01; #end
  #ifndef (Envelope_FlapLength)       #declare Envelope_FlapLength       = 0.02;    #end

  // The flap can be along the top or on the right and can be open (Angle=180) or closed (Angle=0)
  #ifndef (Envelope_FlapLocation)       #declare Envelope_FlapLocation     = "Right"; #end 
  #if (strcmp(Envelope_Style,"social")=0)
                                          #declare Envelope_FlapLocation     = "Top";
  #end 
  #ifndef (Envelope_FlapAngle)          #declare Envelope_FlapAngle        = 0;       #end  
  #if (Envelope_FlapAngle>360)          #declare Envelope_FlapAngle        = 360;     #end
  #if (strcmp(Envelope_Style,"social")=0)
    #if (Envelope_FlapAngle<0.5)        #declare Envelope_FlapAngle        = 0.5;     #end
    #ifndef (Envelope_FlapChamferAngle) #declare Envelope_FlapChamferAngle = 45;      #end
  #else
    #if (Envelope_FlapAngle<2)          #declare Envelope_FlapAngle        = 2;       #end
    #ifndef (Envelope_FlapChamferAngle) #declare Envelope_FlapChamferAngle = 30;      #end  
  #end 
  
  // Default settings give a windowless envelope with an address label containing the default address text 
  #ifndef (Envelope_StampOn)   #declare Envelope_StampOn   = 1; #end 
  #ifndef (Envelope_WindowOn)  #declare Envelope_WindowOn  = 0; #end 
  #ifndef (Envelope_LabelOn)
    #if (Envelope_WindowOn)    #declare Envelope_LabelOn   = 0;
    #else                        #declare Envelope_LabelOn   = 1;                    
    #end
  #end  
  #ifndef (Envelope_AddressOn) #declare Envelope_AddressOn = 1; #end
  #if(Envelope_AddressOn)
    #ifndef (Envelope_Address)
      #declare Envelope_Address = array[4] {   
        "\"Envelope\"",
        "Office Supplies",
        "POV-Ray Object Collection",
        "http://lib.povray.org/"
      }
    #end
  #end  
  
  // Default Textures
  #ifndef (Envelope_Texture) 
    #declare Envelope_Texture        = Envelope_DefaultTexture;
  #end  
  #ifndef (Envelope_LabelTexture) 
    #declare Envelope_LabelTexture   = Envelope_DefaultLabelTexture;
  #end 
  #ifndef (Envelope_StampTexture) 
    #declare Envelope_StampTexture   = Envelope_DefaultStampTexture;
  #end 
  #ifndef (Envelope_WindowTexture) 
    #declare Envelope_WindowTexture  = Envelope_DefaultWindowTexture;
  #end
  #ifndef (Envelope_ContentTexture) 
    #declare Envelope_ContentTexture = Envelope_DefaultContentTexture;  
  #end
  #ifndef (Envelope_AddressTexture)
    #declare Envelope_AddressTexture = Envelope_DefaultAddressTexture;
  #end
  

  //****************************************************//
  //    Calculate the positions of the key components   //
  //****************************************************//
//  #local ContentOffset = <Envelope_Width-Envelope_ContentWidth, Envelope_Thickness-Envelope_ContentThickness, Envelope_Depth-Envelope_ContentDepth>/2;
//  #local LabelOffset   = <(Envelope_Width-Envelope_LabelWidth)/2,   Envelope_Thickness+Envelope_ContentThickness, (Envelope_Depth-Envelope_LabelDepth)/2>;
//  #local WindowOffset  = <(Envelope_Width-Envelope_WindowWidth)/2,  Envelope_Thickness/2, (Envelope_Depth-Envelope_WindowDepth)/2>;
//  #local StampOffset   = <Envelope_Width-Envelope_StampWidth-0.01,  Envelope_Thickness+Envelope_ContentThickness, Envelope_Depth-Envelope_StampDepth-0.01>;
  #local LabelOffset   = <Envelope_LabelLeftEdge,  Envelope_Thickness,   Envelope_LabelBottomEdge>;
  #local WindowOffset  = <Envelope_WindowLeftEdge, Envelope_Thickness/2, Envelope_WindowBottomEdge>;
  #local StampOffset   = <Envelope_Width-Envelope_StampWidth-Envelope_StampInsetRight,  Envelope_Thickness, Envelope_Depth-Envelope_StampDepth-Envelope_StampInsetTop>;


  //****************************************************//
  //    Calculate values needed for the flap            //
  //****************************************************// 
  #local TopLeftCornerScaling     = 1;
  #local TopRightCornerScaling    = 1;
  #local BottomRightCornerScaling = 1;
  #local CornerScaling            = 1;
  #if (Envelope_FlapAngle>70 & Envelope_FlapAngle<=110)
    #local CornerScaling = 1-(Envelope_FlapAngle-70)/40;
  #end
  #if (Envelope_FlapAngle>110)   
    #local CornerScaling = 0.025;
  #end 
  // Adjust the position of the rim to generate a little ridge when the flap is laid flat open 
  #local AdditionalRimDisplacement = 0;
  #if (Envelope_FlapAngle>160 & Envelope_FlapAngle<=200)
    #local AdditionalRimDisplacement = (1-abs((Envelope_FlapAngle-180)/20))*Envelope_Thickness/8;
  #end
  
  #if (strcmp(Envelope_FlapLocation,"Right")=0)
    #local RightRimDisplacement     = AdditionalRimDisplacement+0.5*Envelope_Thickness*Envelope_FlapAngle/360;
    #local RightRimRadius           = (0.5+abs((Envelope_FlapAngle/360)-0.5))*Envelope_Thickness/2;
    #local TopRightCornerScaling    = <CornerScaling,1,1>;
    #local BottomRightCornerScaling = <CornerScaling,1,1>;
    #local TopRimDisplacement       = 0;
    #local TopRimRadius             = Envelope_Thickness/2; 
    #local TopCornerRadius          = 0;
  #else
    #local TopRimDisplacement       = AdditionalRimDisplacement+0.5*Envelope_Thickness*Envelope_FlapAngle/360;  
    #local TopRimRadius             = (0.5+abs((Envelope_FlapAngle/360)-0.5))*Envelope_Thickness/2;
    #local TopLeftCornerScaling     = <1,1,CornerScaling>;
    #local TopRightCornerScaling    = <1,1,CornerScaling>;
    #local RightRimDisplacement     = 0;  
    #local RightRimRadius           = Envelope_Thickness/2; 
    #local RightCornerRadius        = 0;
  #end
  #local CutterLength = Envelope_FlapLength/cosd(Envelope_FlapChamferAngle)*1.001;


  //****************************************************//
  //    Construct the individual components             //
  //****************************************************//
  // Define the Main Envelope Object
  #local Envelope_Object = union {
    #if (file_exists(concat("envelope_",Envelope_Style,".inc"))) #include concat("envelope_",Envelope_Style,".inc")
    #else #include "envelope_business.inc"
    #end 
    
    // Create a rounded rim using cylinders and spheres
    cylinder {<Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Thickness/2>,<Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Thickness/2>,Envelope_Thickness/2}
    cylinder {<Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Thickness/2>,<Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Depth-Envelope_Thickness/2>,Envelope_Thickness/2}
    // Right Edge (could be open or closed)
    cylinder {<Envelope_Width-Envelope_Thickness/2,(Envelope_Thickness/2)+RightRimDisplacement,Envelope_Thickness/2>,<Envelope_Width-Envelope_Thickness/2,(Envelope_Thickness/2)+RightRimDisplacement,Envelope_Depth-Envelope_Thickness/2>,RightRimRadius}
    // Top Edge (could be open or closed)
    cylinder {<Envelope_Thickness/2,(Envelope_Thickness/2)+TopRimDisplacement,Envelope_Depth-Envelope_Thickness/2>,<Envelope_Width-Envelope_Thickness/2,(Envelope_Thickness/2)+TopRimDisplacement,Envelope_Depth-Envelope_Thickness/2>,TopRimRadius}
    sphere {0,Envelope_Thickness/2                                translate <Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Thickness/2>}
    // The top left corner is rounded unless the flap is at the top and is more than 90 degrees open
    sphere {0,Envelope_Thickness/2 scale TopLeftCornerScaling     translate <Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Depth-Envelope_Thickness/2>}
    // The top right corner is rounded unless the flap is more than 90 degrees open
    sphere {0,Envelope_Thickness/2 scale TopRightCornerScaling    translate <Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Depth-Envelope_Thickness/2>}
    // The bottom right corner is rounded unless the flap is on the right and is more than 90 degrees open
    sphere {0,Envelope_Thickness/2 scale BottomRightCornerScaling translate <Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,Envelope_Thickness/2>}
  }
  #local ComponentCount = 1;

  // Address Text
  #if (Envelope_AddressOn)
    #declare AddressText = 
    union {  
      #local I =0;
      #while (I<dimension_size(Envelope_Address,1))
        text {ttf "timrom.ttf" Envelope_Address[I] 1,0 translate y*(dimension_size(Envelope_Address,1)-I)}
        #local I = I + 1;  
      #end
      scale <1,1,0.0001>
      texture {Envelope_AddressTexture}
    } 
    #local ComponentCount = ComponentCount + 1;
  #end
  
  // Work out how to fit the address into the available space, which depends on whether we're using a
  // label or a window for the address, or whether we're just writing on the envelope itself.                
  #if (Envelope_AddressOn)
    #if (Envelope_LabelOn) 
      #local TextWidth  = 0.8*Envelope_LabelWidth;
      #local TextDepth = 0.8*Envelope_LabelDepth;
      #local TextCentre = (LabelOffset+<0.5*Envelope_LabelWidth,Envelope_LabelThickness,0.5*Envelope_LabelDepth>)*<1,1.001,1>;
    #end
    #if (Envelope_WindowOn) 
      #local TextWidth  = 0.8*Envelope_WindowWidth;
      #local TextDepth = 0.8*Envelope_WindowDepth;
      #local TextCentre = (WindowOffset+<0.5*Envelope_WindowWidth,0,0.5*Envelope_WindowDepth>)*<1,1.001,1>;
    #end 
    #ifndef (TextWidth)
      #local TextWidth  = 0.75*Envelope_Width;
      #local TextDepth = 0.7*Envelope_Depth;
      #local TextCentre = <0.5*Envelope_Width,Envelope_Thickness,0.5*Envelope_Depth>*<1,1.001,1>;
    #end
    
    // The text scale factor is based on whichever dimension needs scaling the most 
    // to fit everything in the available area. 
    #local RawTextSize = max_extent(AddressText);
    #if (TextWidth/RawTextSize.x<TextDepth/RawTextSize.y) #local TextScaleFactor = TextWidth/RawTextSize.x;
    #else #local TextScaleFactor = TextDepth/RawTextSize.y;
    #end 
  #end
  

  // Define a Label object and position it relative to the envelope
  #if (Envelope_LabelOn)
    #local Label = object {
      Envelope_RoundCorneredBox(Envelope_LabelWidth,Envelope_LabelDepth,Envelope_LabelThickness,Envelope_LabelRounding) 
      translate LabelOffset  
    } 
    #local ComponentCount = ComponentCount + 1;
  #end   

  // Define a Stamp object and position it relative to the envelope
  #if (Envelope_StampOn)
    #local Stamp = object {
      Envelope_StampShape(Envelope_StampWidth,Envelope_StampDepth,Envelope_StampThickness,Envelope_StampHoleSize,Envelope_StampBorderSize,Envelope_StampTexture) 
      translate StampOffset  
    } 
    #local ComponentCount = ComponentCount + 1;
  #end   
  
  // Define a Window Cutter object, the transparent Window object and the Paper beneath the window.
  #if (Envelope_WindowOn)
    #local WindowCutter = object {
      Envelope_RoundCorneredBox(Envelope_WindowWidth,Envelope_WindowDepth,Envelope_Thickness/2,Envelope_WindowRounding) 
      scale <1,1.001,1>
      translate WindowOffset 
    }
    #local WindowObject = object {
      Envelope_RoundCorneredBox(Envelope_WindowWidth,Envelope_WindowDepth,Envelope_Thickness/2,Envelope_WindowRounding)
      scale <1,-1,1> 
      translate WindowOffset*<1,1.0015,1> 
    } 
    #local WindowBackingPaper = object {
      Envelope_RoundCorneredBox(Envelope_WindowWidth,Envelope_WindowDepth,Envelope_Thickness/2000,Envelope_WindowRounding)
      scale <1,-1,1> 
      translate WindowOffset*<1,1.0001,1> 
    } 
    // Cut a window into the envelope if it's required  
    #local Envelope_Object = difference {
      object {Envelope_Object}
      object {WindowCutter}
    }
    #local ComponentCount = ComponentCount + 1;
  #end  


  //****************************************************//
  //    Construct the finished envelope object          //
  //****************************************************//
  #if (ComponentCount>1) union { #end
    object {Envelope_Object texture {Envelope_Texture}}
    // Add the Label 
    #if (Envelope_LabelOn) object {Label texture {Envelope_LabelTexture}} #end 
    #if (Envelope_StampOn) object {Stamp} #end 
    #if (Envelope_WindowOn)
      object {WindowObject       texture {Envelope_WindowTexture}} 
      object {WindowBackingPaper texture {Envelope_ContentTexture}} 
    #end
    // Add the Address text
    #if (Envelope_AddressOn) 
      object {AddressText translate -RawTextSize*<1,1,0>/2 scale TextScaleFactor rotate x*90 translate TextCentre}
    #end
  #if (ComponentCount>1) } #end
  
#end


// This utility macro uses CSG to create a label shape by cutting rounded corners away from a box.
#macro Envelope_RoundCorneredBox(Width, Depth, Thickness, Roundness) 
  #declare CornerCutter = difference {  
    box {-0.000001,<Roundness,Thickness+0.000001,Roundness>}
    cylinder {<Roundness,-0.000002,Roundness><Roundness,Thickness+0.000002,Roundness>,Roundness}
  }
  difference {
    box {0,<Width,Thickness,Depth>} 
    object {CornerCutter}
    object {CornerCutter rotate y* 90 translate <0,0,Depth>}
    object {CornerCutter rotate y*180 translate <Width,0,Depth>}
    object {CornerCutter rotate y*270 translate <Width,0,0>}
  }
#end

 
// The Envelope_StampShape macro uses CSG to create a stamp shape by cutting serrations away from a box.
#macro Envelope_StampShape(Width, Depth, Thickness, HoleSize, Border, Texture) 
  union {
    #if (HoleSize=0) 
      box {0,<Width,Thickness,Depth> pigment {rgb 1}}
    #else 
      #local EdgeCutterLength = max(Width, Depth); 
      #local EdgeCutterDistance = 2*HoleSize;
      #local EdgeCutter = union { 
        #while (EdgeCutterDistance<EdgeCutterLength)   
          cylinder {-y*0.000001,y*Thickness+0.000001,HoleSize translate x*EdgeCutterDistance}
          #local EdgeCutterDistance = EdgeCutterDistance + 3*HoleSize;
        #end
      }
      difference {
        box {0,<Width,Thickness,Depth>} 
        object {EdgeCutter}
        object {EdgeCutter rotate -y*90}
        object {EdgeCutter translate z*Depth}
        object {EdgeCutter rotate -y*90 translate x*Width}   
        pigment {rgb 1}
      }  
    #end   
    box {<Border,0,Border>,<Width-Border,Thickness+0.000001,Depth-Border> texture {Texture translate <Border,0,Border>}}
  }
#end 


// The Envelope_StampSheet macro generates a sheet of stamps containing the specified number of rows and columns.
// You can optionally specify which stamps are present on the sheet using the Envelope_StampBookArray array.
#macro Envelope_StampSheet(Horizontal, Vertical, Width, Depth, Thickness, HoleSize, Border, Texture)
  #ifndef (Envelope_StampBookArray)        #declare Envelope_StampBookArray = array [Horizontal][Vertical];       #end
  #ifndef (Envelope_StampBookInnerTexture) #declare Envelope_StampBookInnerTexture = texture {pigment {rgb <1,0.95,0.8>}} #end
  #ifndef (Envelope_StampBookOuterTexture) #declare Envelope_StampBookOuterTexture = texture {pigment {rgb 1}}            #end

  #local SheetWidth = (Width+Border)*Horizontal + Border;
  #local SheetDepth = (Depth+Border)*Vertical   + Border;
  union {
    box {<0,0          ,0>,<SheetWidth,Thickness/2,SheetDepth> texture {Envelope_StampBookOuterTexture}}
    box {<0,Thickness/2,0>,<SheetWidth,Thickness  ,SheetDepth> texture {Envelope_StampBookInnerTexture}}
    #local StampI = 0; 
    #while (StampI<Horizontal)
      #local StampJ = 0;  
      #while (StampJ<Vertical) 
        #ifndef(Envelope_StampBookArray[StampI][StampJ]) #declare Envelope_StampBookArray[StampI][StampJ] = 1; #end 
        #if (Envelope_StampBookArray[StampI][StampJ])
          object {Envelope_StampShape(Width, Depth, Thickness, HoleSize, Border, Texture) 
            translate <(Width+Border)*StampI + Border,Thickness,(Depth+Border)*StampJ + Border>
          }
        #end
        #local StampJ = StampJ + 1;
      #end
      #local StampI = StampI + 1;
    #end
  }
#end 

// The Envelope_Undef macro undefs each of the control variables used by the Envelope_ macro so that 
// they are re-initialised to their default values the next time the Envelope_ macro is called.
#macro Envelope_Undef() 
  #ifdef(Envelope_Style           ) #undef Envelope_Style            #end
  #ifdef(Envelope_Width           ) #undef Envelope_Width            #end
  #ifdef(Envelope_Depth           ) #undef Envelope_Depth            #end
  #ifdef(Envelope_Thickness       ) #undef Envelope_Thickness        #end
  #ifdef(Envelope_LabelWidth      ) #undef Envelope_LabelWidth       #end
  #ifdef(Envelope_LabelDepth      ) #undef Envelope_LabelDepth       #end
  #ifdef(Envelope_LabelThickness  ) #undef Envelope_LabelThickness   #end
  #ifdef(Envelope_LabelRounding   ) #undef Envelope_LabelRounding    #end
  #ifdef(Envelope_WindowWidth     ) #undef Envelope_WindowWidth      #end
  #ifdef(Envelope_WindowDepth     ) #undef Envelope_WindowDepth      #end
  #ifdef(Envelope_WindowRounding  ) #undef Envelope_WindowRounding   #end
  #ifdef(Envelope_ContentWidth    ) #undef Envelope_ContentWidth     #end
  #ifdef(Envelope_ContentDepth    ) #undef Envelope_ContentDepth     #end
  #ifdef(Envelope_ContentThickness) #undef Envelope_ContentThickness #end
  #ifdef(Envelope_StampWidth      ) #undef Envelope_StampWidth       #end
  #ifdef(Envelope_StampDepth      ) #undef Envelope_StampDepth       #end
  #ifdef(Envelope_StampThickness  ) #undef Envelope_StampThickness   #end
  #ifdef(Envelope_StampHoleSize   ) #undef Envelope_StampHoleSize    #end
  #ifdef(Envelope_StampBorderSize ) #undef Envelope_StampBorderSize  #end
  #ifdef(Envelope_FlapLength      ) #undef Envelope_FlapLength       #end
  #ifdef(Envelope_FlapLocation    ) #undef Envelope_FlapLocation     #end
  #ifdef(Envelope_FlapAngle       ) #undef Envelope_FlapAngle        #end
  #ifdef(Envelope_FlapChamferAngle) #undef Envelope_FlapChamferAngle #end
  #ifdef(Envelope_StampOn         ) #undef Envelope_StampOn          #end
  #ifdef(Envelope_WindowOn        ) #undef Envelope_WindowOn         #end
  #ifdef(Envelope_LabelOn         ) #undef Envelope_LabelOn          #end
  #ifdef(Envelope_LabelOn         ) #undef Envelope_LabelOn          #end
  #ifdef(Envelope_AddressOn       ) #undef Envelope_AddressOn        #end
  #ifdef(Envelope_Address         ) #undef Envelope_Address          #end
  #ifdef(Envelope_Texture         ) #undef Envelope_Texture          #end
  #ifdef(Envelope_LabelTexture    ) #undef Envelope_LabelTexture     #end
  #ifdef(Envelope_StampTexture    ) #undef Envelope_StampTexture     #end
  #ifdef(Envelope_WindowTexture   ) #undef Envelope_WindowTexture    #end
  #ifdef(Envelope_ContentTexture  ) #undef Envelope_ContentTexture   #end
  #ifdef(Envelope_AddressTexture  ) #undef Envelope_AddressTexture   #end
#end 


// The Envelope_Size macro sets the dimensions of an envelope based on ISO 269 plus some North American sizes
#macro Envelope_Size (SizeCode) 

  // ISO 269 sizes
  #if (strcmp(SizeCode,"DL")=0)      #declare Envelope_Width = 0.220 ; #declare Envelope_Depth = 0.110 ; #end  
  #if (strcmp(SizeCode,"C7/C6")=0)   #declare Envelope_Width = 0.162 ; #declare Envelope_Depth = 0.081 ; #end  
  #if (strcmp(SizeCode,"C6")=0)      #declare Envelope_Width = 0.162 ; #declare Envelope_Depth = 0.114 ; #end   
  #if (strcmp(SizeCode,"C6/C5")=0)   #declare Envelope_Width = 0.229 ; #declare Envelope_Depth = 0.114 ; #end  
  #if (strcmp(SizeCode,"C5")=0)      #declare Envelope_Width = 0.229 ; #declare Envelope_Depth = 0.162 ; #end  
  #if (strcmp(SizeCode,"C4")=0)      #declare Envelope_Width = 0.324 ; #declare Envelope_Depth = 0.229 ; #end  
  #if (strcmp(SizeCode,"C3")=0)      #declare Envelope_Width = 0.458 ; #declare Envelope_Depth = 0.324 ; #end  
  #if (strcmp(SizeCode,"B6")=0)      #declare Envelope_Width = 0.176 ; #declare Envelope_Depth = 0.125 ; #end  
  #if (strcmp(SizeCode,"B5")=0)      #declare Envelope_Width = 0.250 ; #declare Envelope_Depth = 0.176 ; #end  
  #if (strcmp(SizeCode,"B4")=0)      #declare Envelope_Width = 0.353 ; #declare Envelope_Depth = 0.250 ; #end  
  #if (strcmp(SizeCode,"E3")=0)      #declare Envelope_Width = 0.400 ; #declare Envelope_Depth = 0.280 ; #end  
                                                                                                            
  // North American sizes                                                                                   
  #if (strcmp(SizeCode,"A2")=0)      #declare Envelope_Width = 0.1449; #declare Envelope_Depth = 0.1103; #end
  #if (strcmp(SizeCode,"A6")=0)      #declare Envelope_Width = 0.1638; #declare Envelope_Depth = 0.1197; #end
  #if (strcmp(SizeCode,"A7")=0)      #declare Envelope_Width = 0.1827; #declare Envelope_Depth = 0.1323; #end
  #if (strcmp(SizeCode,"No.6.75")=0) #declare Envelope_Width = 0.1651; #declare Envelope_Depth = 0.0921; #end
  #if (strcmp(SizeCode,"No.9")=0)    #declare Envelope_Width = 0.2255; #declare Envelope_Depth = 0.0985; #end
  #if (strcmp(SizeCode,"No.10")=0)   #declare Envelope_Width = 0.2394; #declare Envelope_Depth = 0.1040; #end
#end


   
//#declare Envelope_FlapAngle = 0;//360*clock;  
//#declare Envelope_FlapLocation = "Right";
//#declare Envelope_FlapLength = 0.09;
//#declare Envelope_WindowOn  = 1;
//#declare Envelope_AddressOn = 1;
//#declare Envelope_LabelOn = 0;
////#declare Envelope_AddressTexture = texture {pigment {rgb <2,0,2>}};
////#declare Envelope_Texture = texture {pigment {rgb <1,0.85,0.7>}};  
////#declare Envelope_Texture = Envelope_CrumpledTexture;
//object {Envelope() translate -<Envelope_Width, Envelope_Thickness, Envelope_Depth>*0.5}