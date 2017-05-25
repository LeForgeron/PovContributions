// tables.inc
// ----------

// Include file for the Tables macro.  
// 
// Created by Chris Bartlett 12.06.2009
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typically adds about 2 seconds to render time
// Default scale is approximately 1 Metre = 1 POV-Ray unit. 
//


//
// Tables:
//  
#macro Tables(Tables_TableType)
  #switch(0)
    #case(strcmp(strlwr(Tables_TableType),"big coffee table"))
      union {
        // Legs
        #declare Tables_Object = cone {0,0.010,0.42*y,0.015}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate < 0.15,0, 0.1>}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate <-0.15,0, 0.1>}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate <-0.15,0,-0.1>}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate < 0.15,0,-0.1>}   
        // Supports
        #declare Tables_Object = box {<-0.15,0.35, 0.01><0.15,0.42, 0.01>}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate  z*0.1}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate -z*0.1}   
        #declare Tables_Object = box {<-0.01,0.35,-0.1><0.01,0.42, 0.1>}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate  x*0.15}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate -x*0.15}   
        #declare Tables_Object = box {<-0.17,0.42,-0.12><0.17,0.44, 0.12>}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1)}   
      }
    #break
    #case(strcmp(strlwr(Tables_TableType),"small coffee table"))
      union {
        // Legs
        #declare Tables_Object = cone {0,0.010,0.2*y,0.015}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate < 0.1,0, 0.08>}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate <-0.1,0, 0.08>}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate <-0.1,0,-0.08>}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate < 0.1,0,-0.08>}   
        // Supports
        #declare Tables_Object = box {<-0.1,0.16, 0.01><0.1,0.2, 0.01>}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate  z*0.08}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate -z*0.08}   
        #declare Tables_Object = box {<-0.01,0.16,-0.08><0.01,0.2, 0.08>}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate  x*0.1}   
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1) translate -x*0.1}   
        #declare Tables_Object = box {<-0.12,0.2,-0.1><0.12,0.22, 0.1>}
        object { Tables_Object Tables_WoodTextureMacro(-1,-1,-1,-1)}   
      }
    #break
    #else #error "The table type you specified as a parameter to this macro call is not defined."
  #end
#end

#include "math.inc"

#macro Tables_WoodTextureMacro(Tables_ColourSeed, Tables_PatternSeed, Tables_CentreSeed, Tables_WarpSeed)

  // If not set by the user, define default values for the control variables
  #ifndef (Tables_Object)           #declare Tables_Object = box{<0,0,0><0.2,0.018,1>} #end
  #ifndef (Tables_BaseColour1)      #declare Tables_BaseColour1 = <231, 183, 111>/255; #end
  #ifndef (Tables_BaseColour2)      #declare Tables_BaseColour2 = <098, 047, 000>/255; #end 
  #ifndef (Tables_ColourVariance)   #declare Tables_ColourVariance  = 0.05;            #end
  #ifndef (Tables_ColourLinearity)  #declare Tables_ColourLinearity = 0.8 ;            #end
  #ifndef (Tables_Brightness)       #declare Tables_Brightness = 1 ;                   #end
  #ifndef (Tables_RandomSeedStream) #declare Tables_RandomSeedStream = seed(1000);     #end   
  #ifndef (Tables_KnotDensity)      #declare Tables_KnotDensity = 15;                  #end
  #ifndef (Tables_GrainDensity)     #declare Tables_GrainDensity = 1;                  #end
  #ifndef (Tables_TreeRadius)       #declare Tables_TreeRadius = 0.5;                  #end
  #ifndef (Tables_HeartwoodOn)      #declare Tables_HeartwoodOn = 0;                   #end
  #ifndef (Tables_ScaleFactor)      #declare Tables_ScaleFactor = 1;                   #end 
  #ifndef (Tables_WarpOn)           #declare Tables_WarpOn = 1;                        #end 
  #ifndef (Tables_Reflection)       #declare Tables_Reflection = 0.05;                 #end 
  #ifndef (Tables_Debug)            #declare Tables_Debug = 1;                         #end 

  #local Tables_ScaledTreeRadius = Tables_TreeRadius*Tables_ScaleFactor;

  // For debugging purposes we keep a count of the number of times this macro is called in a particular render
  #ifndef (Tables_CallCount)        #declare Tables_CallCount = 1;                     
  #else                          #declare Tables_CallCount = Tables_CallCount + 1; 
  #end 
  
  // Debug info
  #if (Tables_Debug) #debug "-------------------\n" #end
  #if (Tables_Debug) #debug concat("Tables_WoodTextureMacro Call Count: ",str(Tables_CallCount,3,0),"\n") #end

  // Determine the base amount by which the RGB colours can vary in the colour map 
  #local Tables_ColourDifference  = Tables_BaseColour2 - Tables_BaseColour1; 
  
  // Set a number of randomisation seeds. Either based on the parameter given or on a global randomisation stream.
  // A macro call parameter of -1 means to randomise the seed for the stream 
  #if (Tables_ColourSeed = -1) #local Tables_ColourSeedValue  = rand(Tables_RandomSeedStream)*100000;
  #else #local Tables_ColourSeedValue  = Tables_ColourSeed;
  #end   
  #if (Tables_PatternSeed = -1) #local Tables_PatternSeedValue  = rand(Tables_RandomSeedStream)*100000;
  #else #local Tables_PatternSeedValue  = Tables_PatternSeed;
  #end  
  #if (Tables_CentreSeed = -1) #local Tables_CentreSeedValue  = rand(Tables_RandomSeedStream)*100000;
  #else #local Tables_CentreSeedValue  = Tables_CentreSeed;
  #end  
  #if (Tables_WarpSeed = -1) #local Tables_WarpSeedValue  = rand(Tables_RandomSeedStream)*100000;
  #else #local Tables_WarpSeedValue  = Tables_WarpSeed;
  #end  
  #local Tables_ColourSeedStream  = seed(Tables_ColourSeedValue);
  #local Tables_PatternSeedStream = seed(Tables_PatternSeedValue);
  #local Tables_CentreSeedStream  = seed(Tables_CentreSeedValue);
  #local Tables_WarpSeedStream    = seed(Tables_WarpSeedValue);
  // Debug info  
  #if (Tables_Debug) #debug concat("Colour Seed:    ",str(Tables_ColourSeedValue,3,0),"\n")     #end
  #if (Tables_Debug) #debug concat("Pattern Seed:   ",str(Tables_PatternSeedValue,3,0),"\n")    #end
  #if (Tables_Debug) #debug concat("Centre Seed:    ",str(Tables_CentreSeedValue,3,0),"\n")     #end
  #if (Tables_Debug) #debug concat("Warp Seed:      ",str(Tables_WarpSeedValue,3,0),"\n")       #end


  // Determine the extents of the object that the texture needs to fit onto
  #local Tables_MinExtent = min_extent(Tables_Object);
  #local Tables_MaxExtent = max_extent(Tables_Object);   
  #local Tables_Dimensions = (Tables_MaxExtent - Tables_MinExtent)*Tables_ScaleFactor; 

  // Debug info
  #if (Tables_Debug) #debug concat("Tables_Dimensions: ",vstr(3,Tables_Dimensions,",",3,5),"\n") #end
  
  // If not specified, work out how the object is orientated
  // Assume object is aligned to an axis and that the largest dimension is the length, the second largest the width
  // and the smallest dimension is the thickness.
  #ifndef (Tables_Orientation_Length)                  
    // Work out which dimension is the longest (for the default object Length)  
    #if (Tables_Dimensions.x >  Tables_Dimensions.y & Tables_Dimensions.x >  Tables_Dimensions.z) #local Tables_Orientation_Length = x; #end
    #if (Tables_Dimensions.y >= Tables_Dimensions.x & Tables_Dimensions.y >  Tables_Dimensions.z) #local Tables_Orientation_Length = y; #end
    #if (Tables_Dimensions.z >= Tables_Dimensions.x & Tables_Dimensions.z >= Tables_Dimensions.y) #local Tables_Orientation_Length = z; #end
  #end
  #ifndef (Tables_Orientation_Width)
    // Work out which dimension is the second longest (for the default object Width)  
    #if (Tables_Orientation_Length.x != 1)   
      #if (Tables_Dimensions.x >= Tables_Dimensions.y & Tables_Dimensions.x <= Tables_Dimensions.z) #local Tables_Orientation_Width = x; #end
      #if (Tables_Dimensions.x <= Tables_Dimensions.y & Tables_Dimensions.x >= Tables_Dimensions.z) #local Tables_Orientation_Width = x; #end
    #end
    #if (Tables_Orientation_Length.y != 1)  
      #if (Tables_Dimensions.y >  Tables_Dimensions.x & Tables_Dimensions.y <= Tables_Dimensions.z) #local Tables_Orientation_Width = y; #end
      #if (Tables_Dimensions.y <  Tables_Dimensions.x & Tables_Dimensions.y >= Tables_Dimensions.z) #local Tables_Orientation_Width = y; #end
    #end
    #if (Tables_Orientation_Length.z != 1)  
      #if (Tables_Dimensions.z >  Tables_Dimensions.x & Tables_Dimensions.z <  Tables_Dimensions.y) #local Tables_Orientation_Width = z; #end
      #if (Tables_Dimensions.z <  Tables_Dimensions.x & Tables_Dimensions.z >  Tables_Dimensions.y) #local Tables_Orientation_Width = z; #end
    #end
  #end  
  // The default Thickness dimension is at right angles to the other two 
  #ifndef (Tables_Orientation_Thickness) #local Tables_Orientation_Thickness = 1-Tables_Orientation_Length-Tables_Orientation_Width; #end

  // Debug info
  #if (Tables_Debug) #debug concat("Length Orientation:    ",vstr(3,Tables_Orientation_Length,",",3,5),"\n")    #end
  #if (Tables_Debug) #debug concat("Width Orientation:     ",vstr(3,Tables_Orientation_Width,",",3,5),"\n")     #end
  #if (Tables_Debug) #debug concat("Thickness Orientation: ",vstr(3,Tables_Orientation_Thickness,",",3,5),"\n") #end

  // Pick out the Length, Width and Thickness values (assumes object is aligned to an axis) 
  #local Tables_Temp            = Tables_Dimensions * vnormalize(Tables_Orientation_Length);
  #local Tables_ObjectLength    = Tables_Temp.x+Tables_Temp.y+Tables_Temp.z;
  // Debug info
  #if (Tables_Debug) #debug concat("Length Tables_Temp:    ",vstr(3,Tables_Temp,",",3,5),"\n")  #end
  #local Tables_Temp            = Tables_Dimensions * vnormalize(Tables_Orientation_Width);
  #local Tables_ObjectWidth     = Tables_Temp.x+Tables_Temp.y+Tables_Temp.z;
  // Debug info
  #if (Tables_Debug) #debug concat("Width Tables_Temp:     ",vstr(3,Tables_Temp,",",3,5),"\n")  #end
  #local Tables_Temp            = Tables_Dimensions * vnormalize(Tables_Orientation_Thickness);
  #local Tables_ObjectThickness = Tables_Temp.x+Tables_Temp.y+Tables_Temp.z; 
  // Debug info
  #if (Tables_Debug) #debug concat("Thickness Tables_Temp: ",vstr(3,Tables_Temp,",",3,5),"\n")  #end
  
  // Debug info
  #if (Tables_Debug) #debug concat("Length:    ",str(Tables_ObjectLength,3,5),"\n")     #end
  #if (Tables_Debug) #debug concat("Width:     ",str(Tables_ObjectWidth,3,5),"\n")      #end
  #if (Tables_Debug) #debug concat("Thickness: ",str(Tables_ObjectThickness,3,5),"\n")  #end

  // The texture is defined with the length oriented towards +z, and the width oriented towards +x.
  // The bottom left corner is positioned at the origin when the texture is defined.
  // Work out the transformations required to reorient the texture at the end.
  #if (Tables_Orientation_Length.z & Tables_Orientation_Width.x)
    #local Tables_TargetRotation = 0;
    #local Tables_TargetTranslation = 0;
  #end
  #if (Tables_Orientation_Length.z & Tables_Orientation_Width.y)
    #local Tables_TargetRotation = -90*z;
    #local Tables_TargetTranslation = y*Tables_ObjectWidth;
  #end
  #if (Tables_Orientation_Length.y & Tables_Orientation_Width.x)
    #local Tables_TargetRotation = -90*x;
    #local Tables_TargetTranslation = z*Tables_ObjectThickness;
  #end
  #if (Tables_Orientation_Length.y & Tables_Orientation_Width.z)
    #local Tables_TargetRotation = -90*(x+y);
    #local Tables_TargetTranslation = 0;
  #end
  #if (Tables_Orientation_Length.x & Tables_Orientation_Width.y)
    #local Tables_TargetRotation = 90*(x+z);
    #local Tables_TargetTranslation = 0;
  #end
  #if (Tables_Orientation_Length.x & Tables_Orientation_Width.z)
    #local Tables_TargetRotation = 90*y;
    #local Tables_TargetTranslation = z*Tables_ObjectWidth;
  #end

  // Debug info
  #if (Tables_Debug) #debug concat("Post-generation Reorientation (starting from Length=Z and Width=X)\n") #end
  #if (Tables_Debug) #debug concat("  Tables_TargetRotation:     ",vstr(3,Tables_TargetRotation,",",3,5),"\n")             #end
  #if (Tables_Debug) #debug concat("  Tables_TargetTranslation:  ",vstr(3,Tables_TargetTranslation,",",3,5),"\n")          #end

  // Pick a centre point for the texture that will place the section within the tree radius, avoiding Heartwood as necessary.
  // This may be difficult or impossible, e.g. if the objects cross section is too big for a tree of the radius specified,
  // so we limit the number of attempts, beyond which we just accept the value found and continue.
  #local Tables_Attempts = 1;
  #local Tables_GoodPosition = 0;
  #while(!Tables_GoodPosition & Tables_Attempts<=4)
    #local Tables_VerticalOffset   = Tables_HeartwoodOn*(0.01+Tables_ObjectThickness/2) + rand(Tables_CentreSeedStream)*(Tables_ScaledTreeRadius-(Tables_ObjectThickness/2)-Tables_HeartwoodOn*(0.01+Tables_ObjectThickness/2));
    #local Tables_HorizontalOffset = Tables_HeartwoodOn*(0.01+Tables_ObjectWidth/2)     + rand(Tables_CentreSeedStream)*(Tables_ScaledTreeRadius-(Tables_ObjectWidth/2)    -Tables_HeartwoodOn*(0.01+Tables_ObjectWidth/2));
    #if (pow(Tables_VerticalOffset,2)+pow(Tables_HorizontalOffset,2) <= pow(Tables_ScaledTreeRadius,2)) #local Tables_GoodPosition = 1; #end  
    #local Tables_Attempts = Tables_Attempts + 1;
  #end 
  // Randomise the decision about whether the centre is above or below and left or right of the object 
  #local Tables_HorizontalSign = select(rand(Tables_CentreSeedStream)-0.5,-1,1);
  #local Tables_VerticalSign   = select(rand(Tables_CentreSeedStream)-0.5,-1,1);
  // The centre point for the wood texture is offset relative to the centre of the object
  #local Tables_TextureCentrePoint = <
    (Tables_ObjectWidth/2)     + Tables_HorizontalOffset*Tables_HorizontalSign,
    (Tables_ObjectThickness/2) + Tables_VerticalOffset*Tables_VerticalSign,
    0
  >;
  // Debug info
  #if (Tables_Debug) #debug concat("Wood Texture Centre Point: ",vstr(3,Tables_TextureCentrePoint,",",3,5),"\n")  #end
  
  // *********************  
  // The main wood texture       
  // *********************
  texture {
    pigment {
      wood 
      // Stretch along length to give a crisper grain
      scale <0.004,0.004,0.09> * Tables_GrainDensity
      translate Tables_TextureCentrePoint
      turbulence 0.035 
      // Define a randomised colour map
      color_map {
        #local Tables_MapPosition = 0;
        #local Tables_Loop = 1;
        #while (Tables_Loop)
          #local Tables_MapColour = Tables_BaseColour1 
            + Tables_ColourDifference*Tables_ColourLinearity*Tables_MapPosition
            + Tables_ColourDifference*rand(Tables_ColourSeedStream)*(1-Tables_ColourVariance-Tables_ColourLinearity)
            + Tables_ColourVariance*<
              Tables_ColourDifference.x*rand(Tables_ColourSeedStream),
              Tables_ColourDifference.y*rand(Tables_ColourSeedStream),
              Tables_ColourDifference.z*rand(Tables_ColourSeedStream)
            >; 
          [min(Tables_MapPosition,1) color rgb Tables_MapColour*Tables_Brightness]
          #if (Tables_MapPosition>=1) #local Tables_Loop = 0; #end
          // Debug info
          #if (Tables_Debug) #debug concat("Colour Map (Position and Colour):",str(min(Tables_MapPosition,1),3,3)," <",vstr(3,Tables_MapColour*255,",",3,9),">\n") #end
          #local Tables_MapPosition = Tables_MapPosition + rand(Tables_ColourSeedStream)*0.2;
        #end
      } 
      #if (Tables_WarpOn)
        // Add a large scale warp somewhere near the middle to help distort the grain
        #local Tables_MainWarpOffset = <
          // The centre of this warp is at least half a tree thickness away from the centre of the object
          Tables_ObjectThickness+Tables_ScaledTreeRadius*(0.5+0.5*rand(Tables_WarpSeedStream))*select(rand(Tables_WarpSeedStream)-0.5,-1,1),
          0,
          // The centre of this warp is somewhere in the middle 80% of the length
          0.8*Tables_ObjectLength*(rand(Tables_WarpSeedStream)-0.5)
        >;
        // The warp centre is randomly rotated and displaced relative to the middle of the object
        #local Tables_MainTables_WarpCentre = vrotate(Tables_MainWarpOffset,z*rand(Tables_WarpSeedStream)*360)+<Tables_ObjectWidth,Tables_ObjectThickness,Tables_ObjectLength>/2;
        #local Tables_MainWarpStrength = 0.2 + 0.2*rand(Tables_WarpSeedStream); 
        warp {black_hole Tables_MainTables_WarpCentre,Tables_ObjectLength*2 strength Tables_MainWarpStrength falloff 2}
        
        // *****  
        // Knots       
        // *****
        // Add randomised warps along the upper and lower surface of the object
        #local WarpQuantity = (Tables_KnotDensity*(0.5+rand(Tables_WarpSeedStream)) * Tables_ObjectLength * Tables_ObjectWidth) - 0.5;
        // Debug info
        #if (Tables_Debug) #debug concat("Number of Knot Warps:",str(WarpQuantity,3,3),"\n") #end
        #local Tables_I = 0;
        #while (Tables_I<WarpQuantity) 
          #local Tables_WarpCentre = <
            Tables_ObjectWidth*rand(Tables_WarpSeedStream),
            // The centre of the warp is within the object
            Tables_ObjectThickness/2,
            // The centre of the warp is somewhere in the length
            Tables_ObjectLength*rand(Tables_WarpSeedStream)
          >;
          #local Tables_WarpStrength = 1 + 0.25*rand(Tables_WarpSeedStream); 
          // Find the XY components of the vector from the centre of the texture to the centre of this warp
          #local Tables_WarpVector = vnormalize(<1,1,0>*(Tables_WarpCentre-Tables_TextureCentrePoint)); 
          // Work out how much and in which direction to displace the texture by to reach the surface
          #local Tables_DisplacementVector = select(Tables_TextureCentrePoint.y,-1,1)*0.5*Tables_WarpVector*(Tables_ObjectThickness/(2*Tables_WarpVector.y));
          // Stretch knots in the Z direction by a randomised amount   
          #local Tables_ZScale = <1,1,1+4*rand(Tables_WarpSeedStream)>;
          // When the texture centre is at a low angle, we need to constrain the size of the knot
          #local Tables_WarpSize = 0.035 + 0.06*(atan2d(abs(Tables_TextureCentrePoint.y),abs(Tables_TextureCentrePoint.x))/90);
          // Scale the whole texture by the inverse amount. Position the warps accordingly then rescale everything back again.
          scale 1/Tables_ZScale 
          // Each knot has 2 warp components, one pulling and one pushing
          warp {black_hole (1/Tables_ZScale)*(Tables_WarpCentre+Tables_DisplacementVector),Tables_WarpSize strength Tables_WarpStrength falloff 2}
          warp {black_hole (1/Tables_ZScale)*(Tables_WarpCentre-Tables_DisplacementVector),Tables_WarpSize strength Tables_WarpStrength inverse falloff 2}
          scale Tables_ZScale
          // Debug info
          #if (Tables_Debug) #debug concat("Centre of Knot ",str(Tables_I,3,0),":",vstr(3,Tables_WarpCentre,",",3,4),"\n")  #end
          #local Tables_I = Tables_I+1;
        #end
      #end
    }
    finish {ambient 0.01 reflection Tables_Reflection}
    normal {
      wood 
      // Stretch along length to give a crisper grain
      scale <0.004,0.004,0.09> * Tables_GrainDensity
      translate Tables_TextureCentrePoint
      turbulence 0.035 
    }
    rotate Tables_TargetRotation
    translate Tables_TargetTranslation
    scale 0.6/Tables_ScaleFactor
    translate Tables_MinExtent  
  }
  // Add a speckled top layer
  texture { 
    pigment {
      bozo
      color_map {
        [0.00 color rgb Tables_BaseColour1*0.35*Tables_Brightness ]
        [0.30 color rgb <min(Tables_BaseColour1.x*255/230,1),min(Tables_BaseColour1.y*255/230,1),min(Tables_BaseColour1.z*255/230,1)>*Tables_Brightness]
        [0.30 color rgbt 1]
        [1.00 color rgbt 1]
      }
      scale <0.0008, 0.0008, 0.05>
      #if (Tables_WarpOn) warp {black_hole Tables_MainTables_WarpCentre,Tables_ObjectLength strength Tables_MainWarpStrength falloff 1} #end
    }
    finish {ambient 0.05} 
    normal {bozo  scale <0.0008, 0.0008, 0.05>}
    rotate Tables_TargetRotation
    translate Tables_TargetTranslation
    scale 1/Tables_ScaleFactor
    translate Tables_MinExtent
  }        
#end
