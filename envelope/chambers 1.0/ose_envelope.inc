// OSE_envelope.inc
// ---------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This include file contains the OSE_Envelope macro which creates an envelope based upon the settings of 
// a range of control variables, as documented in the OSE_envelope.html file accompanying this file.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// Render times are typically a few seconds for a single envelope.

#include "OSE_envelopetextures.inc"
#ifndef(cosd) #include "math.inc" #end 


//
// The OSE_Envelope macro is used to generate an envelope object
// The 'EnvelopeType' parameter is provides future support for alternative generation algorithms
// This parameter is a string. The only value currently supported is "Quicky". 
// The characteristics of the envelope are controlled through variables which all have default settings 
//
#macro OSE_Envelope ()
  //****************************************************//
  //    Set Default values for all Control Variables    //
  //****************************************************// 
  #ifndef (OSE_EnvelopeStyle) #declare OSE_EnvelopeStyle = "business"; #end

  // Define default sizes for all components
  #ifndef (OSE_EnvelopeWidth)            #declare OSE_EnvelopeWidth            = 0.23;    #end 
  #ifndef (OSE_EnvelopeDepth)            #declare OSE_EnvelopeDepth            = 0.16;    #end
  #ifndef (OSE_EnvelopeThickness)        #declare OSE_EnvelopeThickness        = 0.0015;  #end
  #ifndef (OSE_EnvelopeLabelWidth)       #declare OSE_EnvelopeLabelWidth       = OSE_EnvelopeWidth/2;        #end  
  #ifndef (OSE_EnvelopeLabelDepth)       #declare OSE_EnvelopeLabelDepth       = OSE_EnvelopeDepth/3;        #end
  #ifndef (OSE_EnvelopeLabelThickness)   #declare OSE_EnvelopeLabelThickness   = 0.0003;  #end              
  #ifndef (OSE_EnvelopeLabelRounding)    #declare OSE_EnvelopeLabelRounding    = 0.008;   #end              
  #ifndef(OSE_EnvelopeLabelLeftEdge   )  #declare OSE_EnvelopeLabelLeftEdge    = (OSE_EnvelopeWidth-OSE_EnvelopeLabelWidth)/2;  #end
  #ifndef(OSE_EnvelopeLabelBottomEdge )  #declare OSE_EnvelopeLabelBottomEdge  = (OSE_EnvelopeDepth-OSE_EnvelopeLabelDepth)/2;  #end
  #ifndef (OSE_EnvelopeWindowWidth)      #declare OSE_EnvelopeWindowWidth      = OSE_EnvelopeWidth/2;        #end  
  #ifndef (OSE_EnvelopeWindowDepth)      #declare OSE_EnvelopeWindowDepth      = OSE_EnvelopeDepth/3;        #end
  #ifndef (OSE_EnvelopeWindowRounding)   #declare OSE_EnvelopeWindowRounding   = OSE_EnvelopeWindowWidth/12; #end 
  #ifndef(OSE_EnvelopeWindowLeftEdge  )  #declare OSE_EnvelopeWindowLeftEdge   = (OSE_EnvelopeWidth-OSE_EnvelopeWindowWidth)/2; #end
  #ifndef(OSE_EnvelopeWindowBottomEdge)  #declare OSE_EnvelopeWindowBottomEdge = (OSE_EnvelopeDepth-OSE_EnvelopeWindowDepth)/2; #end
  #ifndef (OSE_EnvelopeStampWidth)       #declare OSE_EnvelopeStampWidth       = 0.02;    #end  
  #ifndef (OSE_EnvelopeStampDepth)       #declare OSE_EnvelopeStampDepth       = 0.023;   #end
  #ifndef (OSE_EnvelopeStampThickness)   #declare OSE_EnvelopeStampThickness   = 0.0002;  #end
  #ifndef (OSE_EnvelopeStampHoleSize)    #declare OSE_EnvelopeStampHoleSize    = 0.0005;  #end  
  #ifndef (OSE_EnvelopeStampBorderSize)  #declare OSE_EnvelopeStampBorderSize  = 0.0015;  #end 
  #ifndef(OSE_EnvelopeStampInsetRight )  #declare OSE_EnvelopeStampInsetRight  = 0.01; #end
  #ifndef(OSE_EnvelopeStampInsetTop   )  #declare OSE_EnvelopeStampInsetTop    = 0.01; #end
  #ifndef (OSE_EnvelopeFlapLength)       #declare OSE_EnvelopeFlapLength       = 0.02;    #end

  // The flap can be along the top or on the right and can be open (Angle=180) or closed (Angle=0)
  #ifndef (OSE_EnvelopeFlapLocation)       #declare OSE_EnvelopeFlapLocation     = "Right"; #end 
  #if (strcmp(OSE_EnvelopeStyle,"social")=0)
                                          #declare OSE_EnvelopeFlapLocation     = "Top";
  #end 
  #ifndef (OSE_EnvelopeFlapAngle)          #declare OSE_EnvelopeFlapAngle        = 0;       #end  
  #if (OSE_EnvelopeFlapAngle>360)          #declare OSE_EnvelopeFlapAngle        = 360;     #end
  #if (strcmp(OSE_EnvelopeStyle,"social")=0)
    #if (OSE_EnvelopeFlapAngle<0.5)        #declare OSE_EnvelopeFlapAngle        = 0.5;     #end
    #ifndef (OSE_EnvelopeFlapChamferAngle) #declare OSE_EnvelopeFlapChamferAngle = 45;      #end
  #else
    #if (OSE_EnvelopeFlapAngle<2)          #declare OSE_EnvelopeFlapAngle        = 2;       #end
    #ifndef (OSE_EnvelopeFlapChamferAngle) #declare OSE_EnvelopeFlapChamferAngle = 30;      #end  
  #end 
  
  // Default settings give a windowless envelope with an address label containing the default address text 
  #ifndef (OSE_EnvelopeStampOn)   #declare OSE_EnvelopeStampOn   = 1; #end 
  #ifndef (OSE_EnvelopeWindowOn)  #declare OSE_EnvelopeWindowOn  = 0; #end 
  #ifndef (OSE_EnvelopeLabelOn)
    #if (OSE_EnvelopeWindowOn)    #declare OSE_EnvelopeLabelOn   = 0;
    #else                        #declare OSE_EnvelopeLabelOn   = 1;                    
    #end
  #end  
  #ifndef (OSE_EnvelopeAddressOn) #declare OSE_EnvelopeAddressOn = 1; #end
  #if(OSE_EnvelopeAddressOn)
    #ifndef (OSE_EnvelopeAddress)
      #declare OSE_EnvelopeAddress = array[4] {   
        "\"Envelope\"",
        "Office Supplies",
        "POV-Ray Object Collection",
        "http://lib.povray.org/"
      }
    #end
  #end  
  
  // Default Textures
  #ifndef (OSE_EnvelopeTexture) 
    #declare OSE_EnvelopeTexture        = OSE_EnvelopeDefaultTexture;
  #end  
  #ifndef (OSE_EnvelopeLabelTexture) 
    #declare OSE_EnvelopeLabelTexture   = OSE_EnvelopeDefaultLabelTexture;
  #end 
  #ifndef (OSE_EnvelopeStampTexture) 
    #declare OSE_EnvelopeStampTexture   = OSE_EnvelopeDefaultStampTexture;
  #end 
  #ifndef (OSE_EnvelopeWindowTexture) 
    #declare OSE_EnvelopeWindowTexture  = OSE_EnvelopeDefaultWindowTexture;
  #end
  #ifndef (OSE_EnvelopeContentTexture) 
    #declare OSE_EnvelopeContentTexture = OSE_EnvelopeDefaultContentTexture;  
  #end
  #ifndef (OSE_EnvelopeAddressTexture)
    #declare OSE_EnvelopeAddressTexture = OSE_EnvelopeDefaultAddressTexture;
  #end
  

  //****************************************************//
  //    Calculate the positions of the key components   //
  //****************************************************//
//  #local ContentOffset = <OSE_EnvelopeWidth-OSE_EnvelopeContentWidth, OSE_EnvelopeThickness-OSE_EnvelopeContentThickness, OSE_EnvelopeDepth-OSE_EnvelopeContentDepth>/2;
//  #local LabelOffset   = <(OSE_EnvelopeWidth-OSE_EnvelopeLabelWidth)/2,   OSE_EnvelopeThickness+OSE_EnvelopeContentThickness, (OSE_EnvelopeDepth-OSE_EnvelopeLabelDepth)/2>;
//  #local WindowOffset  = <(OSE_EnvelopeWidth-OSE_EnvelopeWindowWidth)/2,  OSE_EnvelopeThickness/2, (OSE_EnvelopeDepth-OSE_EnvelopeWindowDepth)/2>;
//  #local StampOffset   = <OSE_EnvelopeWidth-OSE_EnvelopeStampWidth-0.01,  OSE_EnvelopeThickness+OSE_EnvelopeContentThickness, OSE_EnvelopeDepth-OSE_EnvelopeStampDepth-0.01>;
  #local LabelOffset   = <OSE_EnvelopeLabelLeftEdge,  OSE_EnvelopeThickness,   OSE_EnvelopeLabelBottomEdge>;
  #local WindowOffset  = <OSE_EnvelopeWindowLeftEdge, OSE_EnvelopeThickness/2, OSE_EnvelopeWindowBottomEdge>;
  #local StampOffset   = <OSE_EnvelopeWidth-OSE_EnvelopeStampWidth-OSE_EnvelopeStampInsetRight,  OSE_EnvelopeThickness, OSE_EnvelopeDepth-OSE_EnvelopeStampDepth-OSE_EnvelopeStampInsetTop>;


  //****************************************************//
  //    Calculate values needed for the flap            //
  //****************************************************// 
  #local TopLeftCornerScaling     = 1;
  #local TopRightCornerScaling    = 1;
  #local BottomRightCornerScaling = 1;
  #local CornerScaling            = 1;
  #if (OSE_EnvelopeFlapAngle>70 & OSE_EnvelopeFlapAngle<=110)
    #local CornerScaling = 1-(OSE_EnvelopeFlapAngle-70)/40;
  #end
  #if (OSE_EnvelopeFlapAngle>110)   
    #local CornerScaling = 0.025;
  #end 
  // Adjust the position of the rim to generate a little ridge when the flap is laid flat open 
  #local AdditionalRimDisplacement = 0;
  #if (OSE_EnvelopeFlapAngle>160 & OSE_EnvelopeFlapAngle<=200)
    #local AdditionalRimDisplacement = (1-abs((OSE_EnvelopeFlapAngle-180)/20))*OSE_EnvelopeThickness/8;
  #end
  
  #if (strcmp(OSE_EnvelopeFlapLocation,"Right")=0)
    #local RightRimDisplacement     = AdditionalRimDisplacement+0.5*OSE_EnvelopeThickness*OSE_EnvelopeFlapAngle/360;
    #local RightRimRadius           = (0.5+abs((OSE_EnvelopeFlapAngle/360)-0.5))*OSE_EnvelopeThickness/2;
    #local TopRightCornerScaling    = <CornerScaling,1,1>;
    #local BottomRightCornerScaling = <CornerScaling,1,1>;
    #local TopRimDisplacement       = 0;
    #local TopRimRadius             = OSE_EnvelopeThickness/2; 
    #local TopCornerRadius          = 0;
  #else
    #local TopRimDisplacement       = AdditionalRimDisplacement+0.5*OSE_EnvelopeThickness*OSE_EnvelopeFlapAngle/360;  
    #local TopRimRadius             = (0.5+abs((OSE_EnvelopeFlapAngle/360)-0.5))*OSE_EnvelopeThickness/2;
    #local TopLeftCornerScaling     = <1,1,CornerScaling>;
    #local TopRightCornerScaling    = <1,1,CornerScaling>;
    #local RightRimDisplacement     = 0;  
    #local RightRimRadius           = OSE_EnvelopeThickness/2; 
    #local RightCornerRadius        = 0;
  #end
  #local CutterLength = OSE_EnvelopeFlapLength/cosd(OSE_EnvelopeFlapChamferAngle)*1.001;


  //****************************************************//
  //    Construct the individual components             //
  //****************************************************//
  // Define the Main Envelope Object
  #local Envelope = union {
    #if (file_exists(concat("OSE_envelope_",OSE_EnvelopeStyle,".inc"))) #include concat("OSE_envelope_",OSE_EnvelopeStyle,".inc")
    #else #include "OSE_envelope_business.inc"
    #end 
    
    // Create a rounded rim using cylinders and spheres
    cylinder {<OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2>,<OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2>,OSE_EnvelopeThickness/2}
    cylinder {<OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2>,<OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>,OSE_EnvelopeThickness/2}
    // Right Edge (could be open or closed)
    cylinder {<OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,(OSE_EnvelopeThickness/2)+RightRimDisplacement,OSE_EnvelopeThickness/2>,<OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,(OSE_EnvelopeThickness/2)+RightRimDisplacement,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>,RightRimRadius}
    // Top Edge (could be open or closed)
    cylinder {<OSE_EnvelopeThickness/2,(OSE_EnvelopeThickness/2)+TopRimDisplacement,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>,<OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,(OSE_EnvelopeThickness/2)+TopRimDisplacement,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>,TopRimRadius}
    sphere {0,OSE_EnvelopeThickness/2                                translate <OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2>}
    // The top left corner is rounded unless the flap is at the top and is more than 90 degrees open
    sphere {0,OSE_EnvelopeThickness/2 scale TopLeftCornerScaling     translate <OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>}
    // The top right corner is rounded unless the flap is more than 90 degrees open
    sphere {0,OSE_EnvelopeThickness/2 scale TopRightCornerScaling    translate <OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>}
    // The bottom right corner is rounded unless the flap is on the right and is more than 90 degrees open
    sphere {0,OSE_EnvelopeThickness/2 scale BottomRightCornerScaling translate <OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2>}
  }
  #local ComponentCount = 1;

  // Address Text
  #if (OSE_EnvelopeAddressOn)
    #declare AddressText = 
    union {  
      #local I =0;
      #while (I<dimension_size(OSE_EnvelopeAddress,1))
        text {ttf "timrom.ttf" OSE_EnvelopeAddress[I] 1,0 translate y*(dimension_size(OSE_EnvelopeAddress,1)-I)}
        #local I = I + 1;  
      #end
      scale <1,1,0.0001>
      texture {OSE_EnvelopeAddressTexture}
    } 
    #local ComponentCount = ComponentCount + 1;
  #end
  
  // Work out how to fit the address into the available space, which depends on whether we're using a
  // label or a window for the address, or whether we're just writing on the envelope itself.                
  #if (OSE_EnvelopeAddressOn)
    #if (OSE_EnvelopeLabelOn) 
      #local TextWidth  = 0.8*OSE_EnvelopeLabelWidth;
      #local TextDepth = 0.8*OSE_EnvelopeLabelDepth;
      #local TextCentre = (LabelOffset+<0.5*OSE_EnvelopeLabelWidth,OSE_EnvelopeLabelThickness,0.5*OSE_EnvelopeLabelDepth>)*<1,1.001,1>;
    #end
    #if (OSE_EnvelopeWindowOn) 
      #local TextWidth  = 0.8*OSE_EnvelopeWindowWidth;
      #local TextDepth = 0.8*OSE_EnvelopeWindowDepth;
      #local TextCentre = (WindowOffset+<0.5*OSE_EnvelopeWindowWidth,0,0.5*OSE_EnvelopeWindowDepth>)*<1,1.001,1>;
    #end 
    #ifndef (TextWidth)
      #local TextWidth  = 0.75*OSE_EnvelopeWidth;
      #local TextDepth = 0.7*OSE_EnvelopeDepth;
      #local TextCentre = <0.5*OSE_EnvelopeWidth,OSE_EnvelopeThickness,0.5*OSE_EnvelopeDepth>*<1,1.001,1>;
    #end
    
    // The text scale factor is based on whichever dimension needs scaling the most 
    // to fit everything in the available area. 
    #local RawTextSize = max_extent(AddressText);
    #if (TextWidth/RawTextSize.x<TextDepth/RawTextSize.y) #local TextScaleFactor = TextWidth/RawTextSize.x;
    #else #local TextScaleFactor = TextDepth/RawTextSize.y;
    #end 
  #end
  

  // Define a Label object and position it relative to the envelope
  #if (OSE_EnvelopeLabelOn)
    #local Label = object {
      OSE_RoundCorneredBox(OSE_EnvelopeLabelWidth,OSE_EnvelopeLabelDepth,OSE_EnvelopeLabelThickness,OSE_EnvelopeLabelRounding) 
      translate LabelOffset  
    } 
    #local ComponentCount = ComponentCount + 1;
  #end   

  // Define a Stamp object and position it relative to the envelope
  #if (OSE_EnvelopeStampOn)
    #local Stamp = object {
      OSE_StampShape(OSE_EnvelopeStampWidth,OSE_EnvelopeStampDepth,OSE_EnvelopeStampThickness,OSE_EnvelopeStampHoleSize,OSE_EnvelopeStampBorderSize,OSE_EnvelopeStampTexture) 
      translate StampOffset  
    } 
    #local ComponentCount = ComponentCount + 1;
  #end   
  
  // Define a Window Cutter object, the transparent Window object and the Paper beneath the window.
  #if (OSE_EnvelopeWindowOn)
    #local WindowCutter = object {
      OSE_RoundCorneredBox(OSE_EnvelopeWindowWidth,OSE_EnvelopeWindowDepth,OSE_EnvelopeThickness/2,OSE_EnvelopeWindowRounding) 
      scale <1,1.001,1>
      translate WindowOffset 
    }
    #local WindowObject = object {
      OSE_RoundCorneredBox(OSE_EnvelopeWindowWidth,OSE_EnvelopeWindowDepth,OSE_EnvelopeThickness/2,OSE_EnvelopeWindowRounding)
      scale <1,-1,1> 
      translate WindowOffset*<1,1.0015,1> 
    } 
    #local WindowBackingPaper = object {
      OSE_RoundCorneredBox(OSE_EnvelopeWindowWidth,OSE_EnvelopeWindowDepth,OSE_EnvelopeThickness/2000,OSE_EnvelopeWindowRounding)
      scale <1,-1,1> 
      translate WindowOffset*<1,1.0001,1> 
    } 
    // Cut a window into the envelope if it's required  
    #local Envelope = difference {
      object {Envelope}
      object {WindowCutter}
    }
    #local ComponentCount = ComponentCount + 1;
  #end  


  //****************************************************//
  //    Construct the finished envelope object          //
  //****************************************************//
  #if (ComponentCount>1) union { #end
    object {Envelope texture {OSE_EnvelopeTexture}}
    // Add the Label 
    #if (OSE_EnvelopeLabelOn) object {Label texture {OSE_EnvelopeLabelTexture}} #end 
    #if (OSE_EnvelopeStampOn) object {Stamp} #end 
    #if (OSE_EnvelopeWindowOn)
      object {WindowObject       texture {OSE_EnvelopeWindowTexture}} 
      object {WindowBackingPaper texture {OSE_EnvelopeContentTexture}} 
    #end
    // Add the Address text
    #if (OSE_EnvelopeAddressOn) 
      object {AddressText translate -RawTextSize*<1,1,0>/2 scale TextScaleFactor rotate x*90 translate TextCentre}
    #end
  #if (ComponentCount>1) } #end
  
#end


// This utility macro uses CSG to create a label shape by cutting rounded corners away from a box.
#macro OSE_RoundCorneredBox(Width, Depth, Thickness, Roundness) 
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

 
// The OSE_StampShape macro uses CSG to create a stamp shape by cutting serrations away from a box.
#macro OSE_StampShape(Width, Depth, Thickness, HoleSize, Border, Texture) 
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


// The OSE_StampSheet macro generates a sheet of stamps containing the specified number of rows and columns.
// You can optionally specify which stamps are present on the sheet using the OSE_StampBookArray array.
#macro OSE_StampSheet(Horizontal, Vertical, Width, Depth, Thickness, HoleSize, Border, Texture)
  #ifndef (OSE_StampBookArray)        #declare OSE_StampBookArray = array [Horizontal][Vertical];       #end
  #ifndef (OSE_StampBookInnerTexture) #declare OSE_StampBookInnerTexture = texture {pigment {rgb <1,0.95,0.8>}} #end
  #ifndef (OSE_StampBookOuterTexture) #declare OSE_StampBookOuterTexture = texture {pigment {rgb 1}}            #end

  #local SheetWidth = (Width+Border)*Horizontal + Border;
  #local SheetDepth = (Depth+Border)*Vertical   + Border;
  union {
    box {<0,0          ,0>,<SheetWidth,Thickness/2,SheetDepth> texture {OSE_StampBookOuterTexture}}
    box {<0,Thickness/2,0>,<SheetWidth,Thickness  ,SheetDepth> texture {OSE_StampBookInnerTexture}}
    #local StampI = 0; 
    #while (StampI<Horizontal)
      #local StampJ = 0;  
      #while (StampJ<Vertical) 
        #ifndef(OSE_StampBookArray[StampI][StampJ]) #declare OSE_StampBookArray[StampI][StampJ] = 1; #end 
        #if (OSE_StampBookArray[StampI][StampJ])
          object {OSE_StampShape(Width, Depth, Thickness, HoleSize, Border, Texture) 
            translate <(Width+Border)*StampI + Border,Thickness,(Depth+Border)*StampJ + Border>
          }
        #end
        #local StampJ = StampJ + 1;
      #end
      #local StampI = StampI + 1;
    #end
  }
#end 

// The OSE_EnvelopeUndef macro undefs each of the control variables used by the OSE_Envelope macro so that 
// they are re-initialised to their default values the next time the OSE_Envelope macro is called.
#macro OSE_EnvelopeUndef() 
  #ifdef(OSE_EnvelopeStyle           ) #undef OSE_EnvelopeStyle            #end
  #ifdef(OSE_EnvelopeWidth           ) #undef OSE_EnvelopeWidth            #end
  #ifdef(OSE_EnvelopeDepth           ) #undef OSE_EnvelopeDepth            #end
  #ifdef(OSE_EnvelopeThickness       ) #undef OSE_EnvelopeThickness        #end
  #ifdef(OSE_EnvelopeLabelWidth      ) #undef OSE_EnvelopeLabelWidth       #end
  #ifdef(OSE_EnvelopeLabelDepth      ) #undef OSE_EnvelopeLabelDepth       #end
  #ifdef(OSE_EnvelopeLabelThickness  ) #undef OSE_EnvelopeLabelThickness   #end
  #ifdef(OSE_EnvelopeLabelRounding   ) #undef OSE_EnvelopeLabelRounding    #end
  #ifdef(OSE_EnvelopeWindowWidth     ) #undef OSE_EnvelopeWindowWidth      #end
  #ifdef(OSE_EnvelopeWindowDepth     ) #undef OSE_EnvelopeWindowDepth      #end
  #ifdef(OSE_EnvelopeWindowRounding  ) #undef OSE_EnvelopeWindowRounding   #end
  #ifdef(OSE_EnvelopeContentWidth    ) #undef OSE_EnvelopeContentWidth     #end
  #ifdef(OSE_EnvelopeContentDepth    ) #undef OSE_EnvelopeContentDepth     #end
  #ifdef(OSE_EnvelopeContentThickness) #undef OSE_EnvelopeContentThickness #end
  #ifdef(OSE_EnvelopeStampWidth      ) #undef OSE_EnvelopeStampWidth       #end
  #ifdef(OSE_EnvelopeStampDepth      ) #undef OSE_EnvelopeStampDepth       #end
  #ifdef(OSE_EnvelopeStampThickness  ) #undef OSE_EnvelopeStampThickness   #end
  #ifdef(OSE_EnvelopeStampHoleSize   ) #undef OSE_EnvelopeStampHoleSize    #end
  #ifdef(OSE_EnvelopeStampBorderSize ) #undef OSE_EnvelopeStampBorderSize  #end
  #ifdef(OSE_EnvelopeFlapLength      ) #undef OSE_EnvelopeFlapLength       #end
  #ifdef(OSE_EnvelopeFlapLocation    ) #undef OSE_EnvelopeFlapLocation     #end
  #ifdef(OSE_EnvelopeFlapAngle       ) #undef OSE_EnvelopeFlapAngle        #end
  #ifdef(OSE_EnvelopeFlapChamferAngle) #undef OSE_EnvelopeFlapChamferAngle #end
  #ifdef(OSE_EnvelopeStampOn         ) #undef OSE_EnvelopeStampOn          #end
  #ifdef(OSE_EnvelopeWindowOn        ) #undef OSE_EnvelopeWindowOn         #end
  #ifdef(OSE_EnvelopeLabelOn         ) #undef OSE_EnvelopeLabelOn          #end
  #ifdef(OSE_EnvelopeLabelOn         ) #undef OSE_EnvelopeLabelOn          #end
  #ifdef(OSE_EnvelopeAddressOn       ) #undef OSE_EnvelopeAddressOn        #end
  #ifdef(OSE_EnvelopeAddress         ) #undef OSE_EnvelopeAddress          #end
  #ifdef(OSE_EnvelopeTexture         ) #undef OSE_EnvelopeTexture          #end
  #ifdef(OSE_EnvelopeLabelTexture    ) #undef OSE_EnvelopeLabelTexture     #end
  #ifdef(OSE_EnvelopeStampTexture    ) #undef OSE_EnvelopeStampTexture     #end
  #ifdef(OSE_EnvelopeWindowTexture   ) #undef OSE_EnvelopeWindowTexture    #end
  #ifdef(OSE_EnvelopeContentTexture  ) #undef OSE_EnvelopeContentTexture   #end
  #ifdef(OSE_EnvelopeAddressTexture  ) #undef OSE_EnvelopeAddressTexture   #end
#end 


// The OSE_EnvelopeSize macro sets the dimensions of an envelope based on ISO 269 plus some North American sizes
#macro OSE_EnvelopeSize (SizeCode) 

  // ISO 269 sizes
  #if (strcmp(SizeCode,"DL")=0)      #declare OSE_EnvelopeWidth = 0.220 ; #declare OSE_EnvelopeDepth = 0.110 ; #end  
  #if (strcmp(SizeCode,"C7/C6")=0)   #declare OSE_EnvelopeWidth = 0.162 ; #declare OSE_EnvelopeDepth = 0.081 ; #end  
  #if (strcmp(SizeCode,"C6")=0)      #declare OSE_EnvelopeWidth = 0.162 ; #declare OSE_EnvelopeDepth = 0.114 ; #end   
  #if (strcmp(SizeCode,"C6/C5")=0)   #declare OSE_EnvelopeWidth = 0.229 ; #declare OSE_EnvelopeDepth = 0.114 ; #end  
  #if (strcmp(SizeCode,"C5")=0)      #declare OSE_EnvelopeWidth = 0.229 ; #declare OSE_EnvelopeDepth = 0.162 ; #end  
  #if (strcmp(SizeCode,"C4")=0)      #declare OSE_EnvelopeWidth = 0.324 ; #declare OSE_EnvelopeDepth = 0.229 ; #end  
  #if (strcmp(SizeCode,"C3")=0)      #declare OSE_EnvelopeWidth = 0.458 ; #declare OSE_EnvelopeDepth = 0.324 ; #end  
  #if (strcmp(SizeCode,"B6")=0)      #declare OSE_EnvelopeWidth = 0.176 ; #declare OSE_EnvelopeDepth = 0.125 ; #end  
  #if (strcmp(SizeCode,"B5")=0)      #declare OSE_EnvelopeWidth = 0.250 ; #declare OSE_EnvelopeDepth = 0.176 ; #end  
  #if (strcmp(SizeCode,"B4")=0)      #declare OSE_EnvelopeWidth = 0.353 ; #declare OSE_EnvelopeDepth = 0.250 ; #end  
  #if (strcmp(SizeCode,"E3")=0)      #declare OSE_EnvelopeWidth = 0.400 ; #declare OSE_EnvelopeDepth = 0.280 ; #end  
                                                                                                            
  // North American sizes                                                                                   
  #if (strcmp(SizeCode,"A2")=0)      #declare OSE_EnvelopeWidth = 0.1449; #declare OSE_EnvelopeDepth = 0.1103; #end
  #if (strcmp(SizeCode,"A6")=0)      #declare OSE_EnvelopeWidth = 0.1638; #declare OSE_EnvelopeDepth = 0.1197; #end
  #if (strcmp(SizeCode,"A7")=0)      #declare OSE_EnvelopeWidth = 0.1827; #declare OSE_EnvelopeDepth = 0.1323; #end
  #if (strcmp(SizeCode,"No.6.75")=0) #declare OSE_EnvelopeWidth = 0.1651; #declare OSE_EnvelopeDepth = 0.0921; #end
  #if (strcmp(SizeCode,"No.9")=0)    #declare OSE_EnvelopeWidth = 0.2255; #declare OSE_EnvelopeDepth = 0.0985; #end
  #if (strcmp(SizeCode,"No.10")=0)   #declare OSE_EnvelopeWidth = 0.2394; #declare OSE_EnvelopeDepth = 0.1040; #end
#end


   
//#declare OSE_EnvelopeFlapAngle = 0;//360*clock;  
//#declare OSE_EnvelopeFlapLocation = "Right";
//#declare OSE_EnvelopeFlapLength = 0.09;
//#declare OSE_EnvelopeWindowOn  = 1;
//#declare OSE_EnvelopeAddressOn = 1;
//#declare OSE_EnvelopeLabelOn = 0;
////#declare OSE_EnvelopeAddressTexture = texture {pigment {rgb <2,0,2>}};
////#declare OSE_EnvelopeTexture = texture {pigment {rgb <1,0.85,0.7>}};  
////#declare OSE_EnvelopeTexture = OSE_EnvelopeCrumpledTexture;
//object {OSE_Envelope() translate -<OSE_EnvelopeWidth, OSE_EnvelopeThickness, OSE_EnvelopeDepth>*0.5}