// blockwall.inc
// ----------------

// This include file contains a set of macros to produce block walls in a variety  
// of forms. The different macros allow you to specify the dimensions and location 
// or path of a wall with whatever information you have available. They then 
// invoke a macro that defines a randomised block pattern and a macro to create 
// individual blocks to fit the pattern.
//
// This file is licensed under the terms of the CC-LGPL. 
// This license permits you to use, modify and redistribute the content.
// 
// Typical render time 10 seconds (at 640x480 AA 0.3) for 20 rows of 20 blocks.
// The default settings produce a layer of paving stones about 1.4 POV-Ray 
// units wide laying on the XZ plane, centred on the Z axis and heading away
// from the origin in the +Z direction.


#include "math.inc" 
#include "transforms.inc"

// Macro to draw a single stone block. This macro is called repeatedly when generating a wall to create each 
// individual block.
#macro Blockwall_Block(Blockwall_TopLeft, Blockwall_TopRight, Blockwall_BottomRight, Blockwall_BottomLeft, Blockwall_BlockType)
  // Set defaults
  #ifndef (Blockwall_MortarGap               ) #declare Blockwall_MortarGap               = 0.0001;           #end
  #ifndef (Blockwall_BlockThickness          ) #declare Blockwall_BlockThickness          = 0.08;             #end
  #ifndef (Blockwall_BlockThicknessDecrement ) #declare Blockwall_BlockThicknessDecrement = 0;                #end
  #ifndef (Blockwall_BlockRoundness          ) #declare Blockwall_BlockRoundness          = 0.2;              #end
  #ifndef (Blockwall_MinColor                ) #declare Blockwall_MinColor                = <0.7,0.4,0.4>;    #end
  #ifndef (Blockwall_MaxColor                ) #declare Blockwall_MaxColor                = <0.9,0.45,0.45>;  #end
  #ifndef (Blockwall_Contrast                ) #declare Blockwall_Contrast                = 0.8;              #end
  #ifndef (Blockwall_Brightness              ) #declare Blockwall_Brightness              = 1;                #end
  #ifndef (Blockwall_ClipBlock               ) #declare Blockwall_ClipBlock               = 0;                #end
  #ifndef (Blockwall_RoughStoneRandomness    ) #declare Blockwall_RoughStoneRandomness    = 1;                #end
  #ifndef (Blockwall_RoughStoneSeed          ) #declare Blockwall_RoughStoneSeed          = seed(1);          #end
  #ifndef (Blockwall_ColorSeed               ) #declare Blockwall_ColorSeed               = seed(1);          #end     
  #ifndef (Blockwall_Normal) 
    #declare Blockwall_Normal = normal {
      average
      normal_map {
        [1.0  granite scale 0.25]
        [1.0  agate 0.5 scale 0.005]
      }
    }
  #end
  #ifndef (Blockwall_Finish) 
    #declare Blockwall_Finish = finish {specular 0.1*Blockwall_Brightness roughness 0.3*Blockwall_Brightness }
  #end    
  
  // This switch provides support for several predefined color and contrast settings.
  #switch(0)
    #case(strcmp(Blockwall_BlockType, "ColorBrick")!=0)
    #case(strcmp(Blockwall_BlockType, "ColorStone")!=0)
      #declare Blockwall_MinColor        = <0.7,0.65,0.65>;   
      #declare Blockwall_MaxColor        = <1.0,0.7,0.7>;
      #declare Blockwall_Contrast        = 0.98;             
      #declare Blockwall_Finish = finish {phong 0}
    #break
    #case(strcmp(Blockwall_BlockType, "BuffBrick")!=0)
    #case(strcmp(Blockwall_BlockType, "BuffStone")!=0)
      #declare Blockwall_MinColor        = <0.9,0.7,0.5>;   
      #declare Blockwall_MaxColor        = <1.0,0.8,0.6>;
      #declare Blockwall_Contrast        = 0.4;             
    #break
    #case(strcmp(Blockwall_BlockType, "GreenBrick")!=0)
    #case(strcmp(Blockwall_BlockType, "GreenStone")!=0)
      #declare Blockwall_MinColor        = <0.8,0.8,0.7>;   
      #declare Blockwall_MaxColor        = <0.85,0.9,0.75>;
      #declare Blockwall_Contrast        = 0.8;             
    #break
    #case(strcmp(Blockwall_BlockType, "GreyBrick")!=0)
    #case(strcmp(Blockwall_BlockType, "GreyStone")!=0)
      #declare Blockwall_MinColor        = <0.8,0.82,0.82>;   
      #declare Blockwall_MaxColor        = <0.95,0.9,0.95>;
      #declare Blockwall_Contrast        = 0.9;             
    #break
    #case(strcmp(Blockwall_BlockType, "BlueBrick")!=0)
    #case(strcmp(Blockwall_BlockType, "BlueStone")!=0)
      #declare Blockwall_MinColor        = <0.7,0.7,0.8>;   
      #declare Blockwall_MaxColor        = <0.8,0.75,1.0>;
      #declare Blockwall_Contrast        = 0.85;             
    #break
    #case(strcmp(Blockwall_BlockType, "PinkBrick")!=0)
    #case(strcmp(Blockwall_BlockType, "PinkStone")!=0)
      #declare Blockwall_MinColor        = <0.9,0.55,0.55>;      
      #declare Blockwall_MaxColor        = <1.0,0.6,0.6>;
      #declare Blockwall_Contrast        = 0.4;             
    #break
    #case(strcmp(Blockwall_BlockType, "RedBrick")!=0)
    #case(strcmp(Blockwall_BlockType, "RedStone")!=0)
      #declare Blockwall_MinColor        = <0.7,0.4,0.4>;   
      #declare Blockwall_MaxColor        = <0.9,0.45,0.45>;
      #declare Blockwall_Contrast        = 0.8;             
    #break
  #end  

  // Calculate certain block dimensions; e.g. a midline and the inset of the bottom left corner.
  // Not all values are used by all shapes. For example Blockwall_X isn't used by the Polygon shape.   
  #local Blockwall_X            = vlength(Blockwall_BottomLeft - Blockwall_BottomRight) - Blockwall_MortarGap;
  #local Blockwall_TopMiddle    = (Blockwall_TopLeft    + Blockwall_TopRight    )/2;
  #local Blockwall_BottomMiddle = (Blockwall_BottomLeft + Blockwall_BottomRight )/2;
  #local Blockwall_Centre       = (Blockwall_TopMiddle  + Blockwall_BottomMiddle)/2;
  #local Blockwall_Y            = vlength(Blockwall_TopMiddle - Blockwall_BottomMiddle) - Blockwall_MortarGap;
  #local Blockwall_MortarInset  = Blockwall_MortarGap*<1,0,1>/2;  

  // The Polygon shape (and potentially others) draw straight to the inset position.
  #local Blockwall_InsetTopLeft     = Blockwall_TopLeft +
    vnormalize(Blockwall_Centre-Blockwall_TopLeft    )*sqrt(2)*Blockwall_MortarGap/2;
  #local Blockwall_InsetTopRight    = Blockwall_TopRight +
    vnormalize(Blockwall_Centre-Blockwall_TopRight   )*sqrt(2)*Blockwall_MortarGap/2;
  #local Blockwall_InsetBottomRight = Blockwall_BottomRight +
    vnormalize(Blockwall_Centre-Blockwall_BottomRight)*sqrt(2)*Blockwall_MortarGap/2;
  #local Blockwall_InsetBottomLeft  = Blockwall_BottomLeft +
    vnormalize(Blockwall_Centre-Blockwall_BottomLeft )*sqrt(2)*Blockwall_MortarGap/2;

  // Select a randomised color for this block  (within the given range)
  #local Blockwall_ColorRange = Blockwall_MaxColor - Blockwall_MinColor;
  #local Blockwall_R = Blockwall_MinColor.red  +rand(Blockwall_ColorSeed)*Blockwall_ColorRange.red;
  #local Blockwall_G = Blockwall_MinColor.green+rand(Blockwall_ColorSeed)*Blockwall_ColorRange.green;
  #local Blockwall_B = Blockwall_MinColor.blue +rand(Blockwall_ColorSeed)*Blockwall_ColorRange.blue;
  
  // Define a texture for this block 
  #declare Blockwall_ThisBlockTexture = texture {
    #local Blockwall_ThisColor = <Blockwall_R,Blockwall_G,Blockwall_B>*(1-Blockwall_Contrast*rand(Blockwall_ColorSeed))*Blockwall_Brightness;
    pigment {color rgb Blockwall_ThisColor} 
    normal {Blockwall_Normal translate rand(Blockwall_ColorSeed)*1000*z} 
    finish {Blockwall_Finish}
  }
  
  // Blockwall_BlockThinning can be used by the Blockwall macros to reduce the thickness of higher 
  // layers of blocks relative to the thickness at the base of the wall. If it's not set we don't 
  // reduce the thickness of this block. 
  #ifndef(Blockwall_BlockThinning) #local Blockwall_BlockThinning = 0; #end
  #local Blockwall_ThisBlockThickness = Blockwall_BlockThickness - Blockwall_BlockThinning;  
  
  // This switch provides support for a variety of shapes.
  #switch(0)
    #case(strcmp(Blockwall_BlockType, "Box")!=0)
      box {z*Blockwall_ThisBlockThickness, <Blockwall_X, Blockwall_Y, 0>
        translate Blockwall_MortarInset
        texture {Blockwall_ThisBlockTexture}
        Reorient_Trans(x, Blockwall_BottomRight-Blockwall_BottomLeft)
        translate Blockwall_BottomLeft
      }
    #break
    #case(strcmp(Blockwall_BlockType, "Polygon")!=0)
      polygon {
        5,
        <Blockwall_InsetTopLeft.x    ,Blockwall_InsetTopLeft.y    >, 
        <Blockwall_InsetTopRight.x   ,Blockwall_InsetTopRight.y   >, 
        <Blockwall_InsetBottomRight.x,Blockwall_InsetBottomRight.y>, 
        <Blockwall_InsetBottomLeft.x ,Blockwall_InsetBottomLeft.y >, 
        <Blockwall_InsetTopLeft.x    ,Blockwall_InsetTopLeft.y    > 
//        rotate -90*x
        texture {Blockwall_ThisBlockTexture}
      }
    #break
    #case(strcmp(Blockwall_BlockType, "SquarePolygon")!=0)
      polygon {
        5,
        <0             ,0>, 
        <0             ,Blockwall_Y>,
        <Blockwall_X,Blockwall_Y>,
        <Blockwall_X,0>,
        <0             ,0>
        rotate 90*x
        translate Blockwall_MortarInset
        Reorient_Trans(z, Blockwall_TopMiddle-Blockwall_BottomMiddle)
        translate Blockwall_BottomLeft
        texture {Blockwall_ThisBlockTexture}
      }
    #break
    #case(strcmp(Blockwall_BlockType, "Pebbles")!=0)
      sphere {
        0,1/2
        scale <Blockwall_X,Blockwall_Y,Blockwall_ThisBlockThickness>
        translate Blockwall_Centre
        texture {Blockwall_ThisBlockTexture}
      }
    #break
    #case(strcmp(Blockwall_BlockType, "RoughStone")!=0)
    #case(strcmp(Blockwall_BlockType, "ColorStone")!=0)
    #case(strcmp(Blockwall_BlockType, "BuffStone" )!=0)
    #case(strcmp(Blockwall_BlockType, "GreenStone")!=0)
    #case(strcmp(Blockwall_BlockType, "GreyStone" )!=0)
    #case(strcmp(Blockwall_BlockType, "PinkStone" )!=0)
    #case(strcmp(Blockwall_BlockType, "BlueStone" )!=0)
    #case(strcmp(Blockwall_BlockType, "RedStone"  )!=0)
      #local Blockwall_BlockUnits_X = floor(0.5+Blockwall_X/Blockwall_MatrixSpacing);
      #local Blockwall_BlockUnits_Y = floor(0.5+Blockwall_Y/Blockwall_MatrixSpacing);
      #if (Blockwall_ClipBlock) 
        intersection {
          box{-<Blockwall_BlockUnits_X,Blockwall_BlockUnits_Y,1>/2,<Blockwall_BlockUnits_X,Blockwall_BlockUnits_Y,1>/2}      
          blob {
            threshold 0.6  
            Blockwall_BlobBlock(Blockwall_BlockUnits_X,Blockwall_BlockUnits_Y)
          }
          scale <Blockwall_X/Blockwall_BlockUnits_X,Blockwall_Y/Blockwall_BlockUnits_Y,Blockwall_ThisBlockThickness>
          translate Blockwall_Centre +z*Blockwall_BlockThickness/2
          texture {Blockwall_ThisBlockTexture}
        }
      
      #else
        blob {
          threshold 0.6  
          Blockwall_BlobBlock(Blockwall_BlockUnits_X,Blockwall_BlockUnits_Y)
          
          scale <Blockwall_X/Blockwall_BlockUnits_X,Blockwall_Y/Blockwall_BlockUnits_Y,Blockwall_ThisBlockThickness>
          translate Blockwall_Centre +z*Blockwall_BlockThickness/2
          texture {Blockwall_ThisBlockTexture}
        }
      #end
    #break
    // RandomColorSuperellipsoid is the default
    #case(strcmp(Blockwall_BlockType, "Superellipsoid")!=0)
    #else
      superellipsoid { <1,1>*Blockwall_BlockRoundness 
        scale 0.5
        translate <0.5,-0.5,0.5>
        scale <Blockwall_X,Blockwall_ThisBlockThickness, Blockwall_Y>
        translate Blockwall_MortarInset
        texture {Blockwall_ThisBlockTexture}
        Reorient_Trans(z, Blockwall_TopMiddle-Blockwall_BottomMiddle)
        translate Blockwall_BottomLeft
      }
    #break
  #end 

#end 


// This macro adds blob components to the rough stone shape. 
//
#macro Blockwall_BlobBlock (Blockwall_BlockUnits_X,Blockwall_BlockUnits_Y)
//  #debug concat("x,y",str(Blockwall_BlockUnits_X,3,3),",",str(Blockwall_BlockUnits_Y,3,3),"\n") 

  #switch (1)
    #case (Blockwall_BlockUnits_X=1 & Blockwall_BlockUnits_Y=1) 
//      #debug "Case 1:1\n"
      Blockwall_CoreBlob (1  , 0.95, <Blockwall_BlockUnits_X*1.2, Blockwall_BlockUnits_Y*1.1 ,1.1>, 0)                           // Centre   
      Blockwall_CoreBlob (0.7, 0.6 , <Blockwall_BlockUnits_X*0.8, Blockwall_BlockUnits_Y*0.33,0.8>, Blockwall_BlockUnits_Y*0.25) // Top
      Blockwall_CoreBlob (0.7, 0.6 , <Blockwall_BlockUnits_X*0.8, Blockwall_BlockUnits_Y*0.33,0.8>,-Blockwall_BlockUnits_Y*0.25) // Bottom
      #local Blockwall_CornerStrength   = 0.28;
      #local Blockwall_CornerBlobRadius = 0.73;
      #local Blockwall_CornerDepth = 0.6;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.48, Blockwall_BlockUnits_Y*0.5, 0.44>;
    #break
    #case (Blockwall_BlockUnits_X=2 & Blockwall_BlockUnits_Y=1) 
//      #debug "Case 2:1\n"
      Blockwall_CoreBlob (0.9, 0.95, <Blockwall_BlockUnits_X*1.2,Blockwall_BlockUnits_Y*0.9,1.28>, 0)                           // Centre 
      Blockwall_CoreBlob (0.9, 0.6 , <Blockwall_BlockUnits_X*0.8,Blockwall_BlockUnits_Y*0.35,0.8>, Blockwall_BlockUnits_Y*0.32) // Top    
      Blockwall_CoreBlob (0.9, 0.6 , <Blockwall_BlockUnits_X*0.8,Blockwall_BlockUnits_Y*0.35,0.8>,-Blockwall_BlockUnits_Y*0.32) // Bottom 
      #local Blockwall_CornerStrength   = 0.4;
      #local Blockwall_CornerBlobRadius = 1.3;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.55, Blockwall_BlockUnits_Y*0.8, 0.95>;
    #break
    #case (Blockwall_BlockUnits_X=2 & Blockwall_BlockUnits_Y=2) 
//      #debug "Case 2:2\n"
      Blockwall_CoreBlob (1.05, 1  , <Blockwall_BlockUnits_X*1,Blockwall_BlockUnits_Y*0.65,1.25>, 0)                           // Centre 
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*1,Blockwall_BlockUnits_Y*0.42,1.1 >, Blockwall_BlockUnits_Y*0.35) // Top    
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*1,Blockwall_BlockUnits_Y*0.42,1.1 >,-Blockwall_BlockUnits_Y*0.35) // Bottom 
      #local Blockwall_CornerStrength   = 0.59;
      #local Blockwall_CornerBlobRadius = 1.9;
      #local Blockwall_CornerDepth = 0.2;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.65, Blockwall_BlockUnits_Y*0.72, 0.52>;
    #break
    #case (Blockwall_BlockUnits_X=3 & Blockwall_BlockUnits_Y=2) 
//      #debug "Case 3:2\n"
      Blockwall_CoreBlob (1.05, 1  , <Blockwall_BlockUnits_X*1.05,Blockwall_BlockUnits_Y*0.78,1.1>, 0)                          // Centre 
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.82,Blockwall_BlockUnits_Y*0.3 ,0.9>, Blockwall_BlockUnits_Y*0.3) // Top    
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.82,Blockwall_BlockUnits_Y*0.3 ,0.9>,-Blockwall_BlockUnits_Y*0.3) // Bottom 
      #local Blockwall_CornerStrength   = 0.4;
      #local Blockwall_CornerBlobRadius = 1.2;
      #local Blockwall_CornerDepth = 0.25;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.3, Blockwall_BlockUnits_Y*0.35, 0.35>;
    #break
    #case (Blockwall_BlockUnits_X=3 & Blockwall_BlockUnits_Y=3) 
//      #debug "Case 3:3\n"
      Blockwall_CoreBlob (1.05, 1  , <Blockwall_BlockUnits_X*1.05,Blockwall_BlockUnits_Y*0.65,1.18>, 0)                           // Centre 
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*1   ,Blockwall_BlockUnits_Y*0.42,1.1 >, Blockwall_BlockUnits_Y*0.38) // Top    
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*1   ,Blockwall_BlockUnits_Y*0.42,1.1 >,-Blockwall_BlockUnits_Y*0.38) // Bottom 
      #local Blockwall_CornerStrength   = 0.5; //0.45;
      #local Blockwall_CornerBlobRadius = 3.2;
      #local Blockwall_CornerDepth = 0.3;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.82, Blockwall_BlockUnits_Y*0.9, 0.5>;
    #break
    #case (Blockwall_BlockUnits_X=4 & Blockwall_BlockUnits_Y=2) 
//      #debug "Case 4:2\n"
      Blockwall_CoreBlob (1.05, 1  , <Blockwall_BlockUnits_X*1   ,Blockwall_BlockUnits_Y*0.8 ,1.35>, 0)                           // Centre 
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.92,Blockwall_BlockUnits_Y*0.35,1.15>, Blockwall_BlockUnits_Y*0.30) // Top    
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.92,Blockwall_BlockUnits_Y*0.35,1.15>,-Blockwall_BlockUnits_Y*0.30) // Bottom 
      #local Blockwall_CornerStrength   = 0.42;
      #local Blockwall_CornerBlobRadius = 1.35;
      #local Blockwall_CornerDepth = 0.25;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.28, Blockwall_BlockUnits_Y*0.35, 0.45>;
    #break
    #case (Blockwall_BlockUnits_X=4 & Blockwall_BlockUnits_Y=3) 
//      #debug "Case 4:3\n"
      Blockwall_CoreBlob (1.05, 1  , <Blockwall_BlockUnits_X*1.0 ,Blockwall_BlockUnits_Y*0.78,1.1 >, 0)                           // Centre 
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.85,Blockwall_BlockUnits_Y*0.32,0.85>, Blockwall_BlockUnits_Y*0.34) // Top    
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.85,Blockwall_BlockUnits_Y*0.32,0.85>,-Blockwall_BlockUnits_Y*0.34) // Bottom 
      #local Blockwall_CornerStrength   = 0.4;
      #local Blockwall_CornerBlobRadius = 1.4;
      #local Blockwall_CornerDepth = 0.25;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.242, Blockwall_BlockUnits_Y*0.28, 0.33>;
    #break
    #case (Blockwall_BlockUnits_X=4 & Blockwall_BlockUnits_Y=4) 
//      #debug "Case 4:4\n"
      Blockwall_CoreBlob (1.05, 1  , <Blockwall_BlockUnits_X*1.05,Blockwall_BlockUnits_Y*0.65,1.1>, 0)                           // Centre 
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*1   ,Blockwall_BlockUnits_Y*0.42,1  >, Blockwall_BlockUnits_Y*0.38) // Top    
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*1   ,Blockwall_BlockUnits_Y*0.42,1  >,-Blockwall_BlockUnits_Y*0.38) // Bottom 
      #local Blockwall_CornerStrength   = 0.5; //0.45;
      #local Blockwall_CornerBlobRadius = (Blockwall_BlockUnits_X+Blockwall_BlockUnits_Y)*0.35;
      #local Blockwall_CornerDepth = 0.3;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.45, Blockwall_BlockUnits_Y*0.5, 0.64+0.05*Blockwall_BlockUnits_X>;
    #break
    #case (Blockwall_BlockUnits_Y=1) 
      Blockwall_CoreBlob (0.8, 1  , <Blockwall_BlockUnits_X*1+pow(Blockwall_BlockUnits_X,2)*0.04,Blockwall_BlockUnits_Y*1.05,1.4>, 0)                          // Centre 
      Blockwall_CoreBlob (0.8, 0.6, <Blockwall_BlockUnits_X*0.75                                ,Blockwall_BlockUnits_Y*0.35,0.9>, Blockwall_BlockUnits_Y*0.3) // Top    
      Blockwall_CoreBlob (0.8, 0.6, <Blockwall_BlockUnits_X*0.75                                ,Blockwall_BlockUnits_Y*0.35,0.9>,-Blockwall_BlockUnits_Y*0.3) // Bottom 
      #local Blockwall_CornerStrength   = 0.24;
      #local Blockwall_CornerBlobRadius = 1.45;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.38, Blockwall_BlockUnits_Y*0.8, 0.4+0.05*Blockwall_BlockUnits_X>;
    #break
    #case (Blockwall_BlockUnits_Y=2) 
      Blockwall_CoreBlob (0.8, 1  , <Blockwall_BlockUnits_X*0.75+pow(Blockwall_BlockUnits_X,2)*0.035,Blockwall_BlockUnits_Y*1.05,1.4>, 0)                          // Centre 
      Blockwall_CoreBlob (0.8, 0.6, <Blockwall_BlockUnits_X*0.75                                    ,Blockwall_BlockUnits_Y*0.35,0.9>, Blockwall_BlockUnits_Y*0.3) // Top    
      Blockwall_CoreBlob (0.8, 0.6, <Blockwall_BlockUnits_X*0.75                                    ,Blockwall_BlockUnits_Y*0.35,0.9>,-Blockwall_BlockUnits_Y*0.3) // Bottom 
      #local Blockwall_CornerStrength   = 0.24;
      #local Blockwall_CornerBlobRadius = (Blockwall_BlockUnits_X+Blockwall_BlockUnits_Y)*0.32;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.42, Blockwall_BlockUnits_Y*0.7, 0.5+0.05*Blockwall_BlockUnits_X>;
    #break
    #else
      Blockwall_CoreBlob (1.05, 1  , <Blockwall_BlockUnits_X*0.78,Blockwall_BlockUnits_Y*0.78,1.1>, 0) // Centre 
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.7,Blockwall_BlockUnits_Y*0.32,0.95>, Blockwall_BlockUnits_Y*0.34) // Top    
      Blockwall_CoreBlob (0.8 , 0.6, <Blockwall_BlockUnits_X*0.7,Blockwall_BlockUnits_Y*0.32,0.95>,-Blockwall_BlockUnits_Y*0.34) // Bottom 
      #local Blockwall_CornerStrength   = 0.3;
      #local Blockwall_CornerBlobRadius = (Blockwall_BlockUnits_X+Blockwall_BlockUnits_Y)*0.4;
      #local Blockwall_CornerDepth = 0.35;
      #local Blockwall_CornerPosition = <Blockwall_BlockUnits_X*0.55, Blockwall_BlockUnits_Y*0.55, 0.55>;
    #break 
  #end
      
      
  #ifndef (Blockwall_CornerDepth) #local Blockwall_CornerDepth = 1; #end
  Blockwall_CornerBlobs (Blockwall_CornerBlobRadius, Blockwall_CornerStrength, Blockwall_CornerPosition, Blockwall_CornerDepth)
#end


// This macro adds a squashed spherical component to the core of a blob-based block. 
// Blobs are used for the rough stone shapes.
//
#macro Blockwall_CoreBlob (Blockwall_CoreBlobRadius, Blockwall_CoreStrength, Blockwall_CoreScale, Blockwall_CoreHeight) 
  sphere { <0, 0, 0>, 
    Blockwall_CoreBlobRadius             + 0.1  *Blockwall_CoreBlobRadius*Blockwall_RoughStoneRandomness*(rand(Blockwall_RoughStoneSeed)-0.5), 
    Blockwall_CoreStrength               + 0.001*Blockwall_CoreStrength  *Blockwall_RoughStoneRandomness*(rand(Blockwall_RoughStoneSeed)-0.5)
    scale Blockwall_CoreScale            + 0.2  *Blockwall_CoreScale     *Blockwall_RoughStoneRandomness*(<rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed)>-0.5) 
    rotate <3,5,5>*Blockwall_RoughStoneRandomness*(2*<rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed)>-1)
    translate <0,Blockwall_CoreHeight,0> + 0.5  *Blockwall_CoreHeight    *Blockwall_RoughStoneRandomness*(<rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed)>-0.5)                           
  }                                                                          
#end


// This macro provides a shorthand for adding the eight corners to a blob-based block. 
// Blobs are used for the rough stone shapes. This macro adds sphere blob components. 
//
#macro Blockwall_CornerBlobs (Blockwall_CornerBlobRadius, Blockwall_CornerStrength, Blockwall_CornerPosition, Blockwall_CornerDepth) 
//Blockwall_RoughStoneRandomness  Blockwall_RoughStoneSeed 
  #local Blockwall_CornerNumber = 0;                                             
  // Cycle through the 8 corners positions by working out a direction vector
  #while (Blockwall_CornerNumber<8) 
    #local Blockwall_CornerDirection = <
      (mod(Blockwall_CornerNumber,2)?-1:1),          // Every other corner has -x
      (mod(int(Blockwall_CornerNumber/2),2)?-1:1),   // Alternate between +y and -y every two corners
      (Blockwall_CornerNumber>3?-1:1)                // The first 4 have +z, the last 4 have -z
    >;
    sphere { <0, 0, 0>, 
      Blockwall_CornerBlobRadius      +0.1  *Blockwall_CornerBlobRadius*Blockwall_RoughStoneRandomness*(rand(Blockwall_RoughStoneSeed)-0.5), 
      Blockwall_CornerStrength        +0.001*Blockwall_CornerStrength  *Blockwall_RoughStoneRandomness*(rand(Blockwall_RoughStoneSeed)-0.5)
      scale <1,1,Blockwall_CornerDepth+0.1  *Blockwall_CornerDepth     *Blockwall_RoughStoneRandomness*(rand(Blockwall_RoughStoneSeed)-0.5)> 
      translate Blockwall_CornerPosition*Blockwall_CornerDirection 
                                      + 0.1 *Blockwall_CornerPosition  *Blockwall_RoughStoneRandomness*(<rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed),rand(Blockwall_RoughStoneSeed)>-0.5)
    } 
    #local Blockwall_CornerNumber = Blockwall_CornerNumber+1;
  #end                                                                         
#end



// This macro defines and populates a matrix that describes the positions and sizes of a series of blocks. 
// The start position of each block corresponds to one of the grid positions in the matrix.
// The X and Y dimensions of a block are randomly generated but are always whole numbers of grid positions
// and meet a certain set of user defined criteria which control the relative distribution of large and 
// small blocks.
//
#macro Blockwall_MakeMatrix (Blockwall_MatrixRef)

  #ifndef(Blockwall_HBias          ) #declare Blockwall_HBias           = 2.5;     #end
  #ifndef(Blockwall_VBias          ) #declare Blockwall_VBias           = 3;       #end
  #ifndef(Blockwall_MaxHU          ) #declare Blockwall_MaxHU           = 5;       #end
  #ifndef(Blockwall_MaxVU          ) #declare Blockwall_MaxVU           = 3;       #end
  #ifndef(Blockwall_HUVUDependence ) #declare Blockwall_HUVUDependence  = 1;       #end
  #ifndef(Blockwall_Wrap           ) #declare Blockwall_Wrap            = 0;       #end
  #ifndef(Blockwall_SizeSeed       ) #declare Blockwall_SizeSeed        = seed(2); #end
  
  #local Blockwall_MatrixDimX      = dimension_size(Blockwall_MatrixRef,1);
  #local Blockwall_MatrixDimY      = dimension_size(Blockwall_MatrixRef,2);
  
  // Work out where the blocks are going to go, based on the matrix and maximum size settings.
  // We start from the bottom left corner, moving left to right, then up to the far left of the
  // next row. We insert random sized blocks, checking ahead for collisions with any blocks that 
  // protrude into the current layer from earlier rows.
  // The calculation is complicated by the desire to avoid vertical runs of mortar that a 
  // craftsman laying blocks would be able to spot and avoid without much effort in the real 
  // world. 
  #local Blockwall_J = 0;
  #while (Blockwall_J<Blockwall_MatrixDimY)
    #local Blockwall_I = 0;
    #while (Blockwall_I<Blockwall_MatrixDimX)
      // Ignore positions that have already been filled by blocks protruding through from previous rows. 
      #ifndef(Blockwall_MatrixRef[Blockwall_I][Blockwall_J][0])
        // For the horizontal number of units we want a randomised whole number less than the 
        // maximum number of horizontal units specified. We add a bias to increase the 
        // number of low numbers generated, but limit the smallest block size to 2 units 
        // in the first step. We only go down to a 1 unit wide block if a larger block won't fit. 
        #local Blockwall_HU = floor(pow(rand(Blockwall_SizeSeed),Blockwall_HBias)*0.99999999*(Blockwall_MaxHU-2)) +2;
        #local Blockwall_HU = min(Blockwall_HU,Blockwall_MatrixDimX-Blockwall_I);
        #if (Blockwall_Wrap & Blockwall_I=0 & Blockwall_HU>1)
          // If wrapping is on we can shift a block that starts in column 0 back from the first column and 
          // round to the far right.
          #local Blockwall_LeftShift = floor(rand(Blockwall_SizeSeed)*(Blockwall_HU)*0.99999999);
          #if (Blockwall_LeftShift>0)
            // Check back along the row to make sure spaces aren't already filled. If they are, shorten the left shift. 
            #local Blockwall_K = 1;
            #while (Blockwall_K<=Blockwall_LeftShift)
              #ifdef(Blockwall_MatrixRef[Blockwall_MatrixDimX-Blockwall_K][Blockwall_J][0])
                #local Blockwall_LeftShift = Blockwall_K-1; 
              #end
              #local Blockwall_K = Blockwall_K + 1;
            #end 
          #end
        #else
          #local Blockwall_LeftShift = 0;
          // If wrapping is off, change half the blocks starting in the left-most column from a width of 2 to width 1. 
          #if (Blockwall_I=0 & Blockwall_HU=2 & rand(Blockwall_SizeSeed)>0.5)
            #local Blockwall_HU = 1;
          #end
        #end     
        // Check ahead along the row to make sure spaces aren't already filled. If they are, shorten the block. 
        #local Blockwall_K = 1;
        #while (Blockwall_K < (Blockwall_HU-Blockwall_LeftShift))
          #ifdef(Blockwall_MatrixRef[Blockwall_I+Blockwall_K][Blockwall_J][0])
            #local Blockwall_HU = Blockwall_K + Blockwall_LeftShift; 
          #end
          #local Blockwall_K = Blockwall_K + 1;
        #end 
        // If we can stop a vertical mortar run by adding a unit to a block we do so.
        #if (Blockwall_HU<Blockwall_MaxHU & Blockwall_I<Blockwall_MatrixDimX-(Blockwall_HU))
          #ifndef (Blockwall_MatrixRef[Blockwall_I+Blockwall_HU][Blockwall_J][0])
            #if (Blockwall_J-1>=0)
              // If the position following the current end of this block and one row down contains dimensions
              // then it's the start of a block.
              #ifdef (Blockwall_MatrixRef[Blockwall_I+Blockwall_HU][Blockwall_J-1][1])
                #declare Blockwall_HU = Blockwall_HU + 1;
              #else
                // Otherwise check the positions below it to see if it's part of the first column of a block
                // that starts in a lower row.  
                #local Blockwall_L = Blockwall_J-1;
                #while (Blockwall_L>=0) 
                  #ifdef (Blockwall_MatrixRef[Blockwall_I+Blockwall_HU][Blockwall_L][1])
                    #local Blockwall_FoundBlockHeight = Blockwall_MatrixRef[Blockwall_I+Blockwall_HU][Blockwall_L][1];
                    #if (Blockwall_FoundBlockHeight = Blockwall_J - Blockwall_L)
                      #declare Blockwall_HU = Blockwall_HU + 1;
                    #end
                    #local Blockwall_L = -1;
                  #end
                  #local Blockwall_L = Blockwall_L - 1;
                #end
              #end
            #end
          #end
        #end
        // For the vertical number of units we want a randomised whole number that is less than the number 
        // of horizontal units and that doesn't go past the end of this row. We also add a bias to increase the 
        // number of low numbers generated. 
        #if (Blockwall_HUVUDependence)
          #local Blockwall_VU = floor(pow(rand(Blockwall_SizeSeed),Blockwall_VBias)*min(Blockwall_MaxVU,Blockwall_HU)*0.99999999)+1;
        #else
          #local Blockwall_VU = floor(pow(rand(Blockwall_SizeSeed),Blockwall_VBias)*Blockwall_MaxVU*0.99999999)+1;
        #end
        #local Blockwall_VU = min(Blockwall_VU,dimension_size(Blockwall_MatrixRef,2)-Blockwall_J); 
        // Reserve the locations required for this block in the matrix.
        #local Blockwall_L = 0;
        #while (Blockwall_L<Blockwall_HU)
          #local Blockwall_Col = Blockwall_I+Blockwall_L-Blockwall_LeftShift;
          #if (Blockwall_Col<0)
            #local Blockwall_Col = Blockwall_Col+Blockwall_MatrixDimX;
          #end
          #local Blockwall_M = 0;
          #while (Blockwall_M<Blockwall_VU)
            #local Blockwall_Row = Blockwall_J+Blockwall_M;
            #if (Blockwall_L=0 & Blockwall_M=0)
              // Write the dimensions into the first matrix location.
              #declare Blockwall_MatrixRef[Blockwall_Col][Blockwall_Row][0] = Blockwall_HU;
              #declare Blockwall_MatrixRef[Blockwall_Col][Blockwall_Row][1] = Blockwall_VU;
            #else 
              // Otherwise just write anything into the matrix to prevent the location from being reused.
              #declare Blockwall_MatrixRef[Blockwall_Col][Blockwall_Row][0] = 0;
            #end
            #local Blockwall_M = Blockwall_M + 1;
          #end
          #local Blockwall_L = Blockwall_L + 1;
        #end
      #end
      #local Blockwall_I = Blockwall_I + 1;
    #end
    #local Blockwall_J = Blockwall_J + 1;
  #end
#end  
  
  

// Macro to draw a wall of blocks based on user-defined length, height and block thickness settings.
#macro Blockwall(Blockwall_BlockType)

//  #ifndef(Blockwall_BlockThickness) #declare Blockwall_BlockThickness  = 0.1;  #end  
  #ifndef(Blockwall_WallLength)     #declare Blockwall_WallLength      = 1;    #end  
  #ifndef(Blockwall_WallHeight)     #declare Blockwall_WallHeight      = 1;    #end 
  #ifndef(Blockwall_MatrixSpacing)  #declare Blockwall_MatrixSpacing   = 0.1;  #end
   
  #declare Blockwall_MatrixDimX = floor(max(1,Blockwall_WallLength/Blockwall_MatrixSpacing+0.5));
  #declare Blockwall_MatrixDimY = floor(max(1,Blockwall_WallHeight/Blockwall_MatrixSpacing+0.5));

  // Calculate the centre to centre distance to make adjacent stretches of wall meet.
  #declare Blockwall_CentreToCentre = Blockwall_WallLength;

  #declare Blockwall_MatrixArray = array[Blockwall_MatrixDimX][Blockwall_MatrixDimY][2];
  Blockwall_MakeMatrix(Blockwall_MatrixArray)
    
  union {
    #local Blockwall_I = 0;
    #while (Blockwall_I<dimension_size(Blockwall_MatrixArray,1))
      #local Blockwall_J = 0;
      #while (Blockwall_J<dimension_size(Blockwall_MatrixArray,2))
        #ifdef(Blockwall_MatrixArray[Blockwall_I][Blockwall_J][1])
          #local Blockwall_W = Blockwall_MatrixArray[Blockwall_I][Blockwall_J][0];
          #local Blockwall_H = Blockwall_MatrixArray[Blockwall_I][Blockwall_J][1]; 
          
          // Blockwall_BlockThicknessDecrement can be used by the Blockwall macros to reduce the thickness of higher 
          // layers of blocks relative to the thickness at the base of the wall. 
          #ifdef(Blockwall_BlockThicknessDecrement) 
            #declare Blockwall_BlockThinning = Blockwall_BlockThicknessDecrement*Blockwall_J; 
          #end 
          
          #declare Blockwall_TopLeft     = <
            Blockwall_MatrixSpacing*Blockwall_I,
            Blockwall_MatrixSpacing*(Blockwall_J+Blockwall_H),
            0>;
          #declare Blockwall_TopRight    = <
            Blockwall_MatrixSpacing*(Blockwall_I+Blockwall_W),
            Blockwall_MatrixSpacing*(Blockwall_J+Blockwall_H),
            0>;
          #declare Blockwall_BottomRight = <
            Blockwall_MatrixSpacing*(Blockwall_I+Blockwall_W),
            Blockwall_MatrixSpacing*Blockwall_J,
            0>; 
          #declare Blockwall_BottomLeft  = <
            Blockwall_MatrixSpacing*Blockwall_I,
            Blockwall_MatrixSpacing*Blockwall_J,
            0>;
          // Optionally cut away part or all of the block to make a hole in the wall
          #ifdef (Blockwall_Holes)
            difference {
          #end
          object{
            Blockwall_Block(Blockwall_TopLeft, Blockwall_TopRight, Blockwall_BottomRight, Blockwall_BottomLeft, Blockwall_BlockType)
            #ifdef (Blockwall_BlockThinning) translate z*Blockwall_BlockThinning/2 #end
          }
          // Optionally cut away part or all of the block to make a hole in the wall
          #ifdef (Blockwall_Holes) 
              object {Blockwall_Holes texture {Blockwall_ThisBlockTexture}}
            }
          #end
        #end
        #local Blockwall_J = Blockwall_J + 1;
      #end
      #local Blockwall_I = Blockwall_I + 1;
    #end 
  }
#end  



//  This macro fills an area delimited by a minimum extent vector and a maximum extent vector with block walling.
//  The wall is oriented so that the thinest horizontal dimension (X or Z) is used for the block thickness and the
//  larger horizontal dimension is used as the wall length.
//  The box used is aligned to the X, Y and Z axes.
//
#macro Blockwall_Fill (Blockwall_MinExtents, Blockwall_MaxExtents, Blockwall_BlockType)
  #if (abs(Blockwall_MaxExtents.x-Blockwall_MinExtents.x)<abs(Blockwall_MaxExtents.z-Blockwall_MinExtents.z))
    #local Blockwall_Orientation  = x;
    #declare Blockwall_BlockThickness = abs(Blockwall_MaxExtents.x-Blockwall_MinExtents.x);
    #declare Blockwall_WallLength = abs(Blockwall_MaxExtents.z-Blockwall_MinExtents.z);
  #else 
    #local Blockwall_Orientation  = z; 
    #declare Blockwall_BlockThickness = abs(Blockwall_MaxExtents.z-Blockwall_MinExtents.z);
    #declare Blockwall_WallLength = abs(Blockwall_MaxExtents.x-Blockwall_MinExtents.x);
  #end
  #declare Blockwall_WallHeight = abs(Blockwall_MaxExtents.y-Blockwall_MinExtents.y); 

  // Take a copy of any holes then reposition and reorient the Blockwall_Holes object.
  #ifdef(Blockwall_Holes)
    #local Blockwall_CopyOfHoles = object {Blockwall_Holes}
    #declare Blockwall_Holes = object {Blockwall_Holes 
      translate <
        -min(Blockwall_MaxExtents.x,Blockwall_MinExtents.x),
        -min(Blockwall_MaxExtents.y,Blockwall_MinExtents.y),
        -min(Blockwall_MaxExtents.z,Blockwall_MinExtents.z)
      >
      #if (Blockwall_Orientation.x)
        translate -x*Blockwall_BlockThickness
        rotate y*90
      #end
    }
  #end
  
  // Call the Blockwall macro 
  #local Blockwall_TempObject = Blockwall(Blockwall_BlockType)
  #local Blockwall_Min = min_extent(Blockwall_TempObject);
  #local Blockwall_Max = max_extent(Blockwall_TempObject);
  #local Blockwall_L = Blockwall_Max.x-Blockwall_Min.x;
  #local Blockwall_H = Blockwall_Max.y-Blockwall_Min.y;

  object {
    Blockwall_TempObject 
    #if (Blockwall_Orientation.x) translate -Blockwall_BlockThickness*z #end
    scale <Blockwall_WallLength/Blockwall_L,Blockwall_WallHeight/Blockwall_H,1>
    #if (Blockwall_Orientation.x) rotate -y*90 #end
    translate <
      min(Blockwall_MaxExtents.x,Blockwall_MinExtents.x),
      min(Blockwall_MaxExtents.y,Blockwall_MinExtents.y),
      min(Blockwall_MaxExtents.z,Blockwall_MinExtents.z)
    >
  }
  
  // Restore the holes to their original position and orientation in case they're needed again.
  #ifdef (Blockwall_CopyOfHoles) 
    #declare Blockwall_Holes = object {Blockwall_CopyOfHoles} 
  #end

#end


//  This macro creates a shell around an area delimited by a minimum extent vector and a maximum extent vector 
//  by creating a block wall perimeter within the box defined.
//  The box used is aligned to the X, Y and Z axes.
//
#macro Blockwall_Shell (Blockwall_MinExtents, Blockwall_MaxExtents, Blockwall_BlockType)
  #declare Blockwall_WallHeight  = abs(Blockwall_MaxExtents.y-Blockwall_MinExtents.y); 
  #declare Blockwall_CornerArray = array[5] {
    <Blockwall_MinExtents.x,Blockwall_MinExtents.z>,
    <Blockwall_MaxExtents.x,Blockwall_MinExtents.z>,
    <Blockwall_MaxExtents.x,Blockwall_MaxExtents.z>,
    <Blockwall_MinExtents.x,Blockwall_MaxExtents.z>,
    <Blockwall_MinExtents.x,Blockwall_MinExtents.z>
  }; 
  
  // Take a copy of any holes then reposition the Blockwall_Holes object.
  #ifdef(Blockwall_Holes)
    #local Blockwall_CopyOfHoles = object {Blockwall_Holes}
    #declare Blockwall_Holes = object {Blockwall_Holes translate -y*Blockwall_MinExtents.y}
  #end

  object {
    Blockwall_FollowArray (Blockwall_BlockType)
    translate y*Blockwall_MinExtents.y 
  }

  // Restore the holes to their original position and orientation in case they're needed again.
  #ifdef (Blockwall_CopyOfHoles) 
    #declare Blockwall_Holes = object {Blockwall_CopyOfHoles} 
  #end
#end


//  This macro creates a wall consisting of a series of connected straight sections where the positions of the
//  corners of the front face of the wall are specified as an array of 2D vector coordinates. The X and Z 
//  coordinates need to be specified in the 'Blockwall_CornerArray' array. The wall sits on the XZ plane.
//   
//  If the first and last point are the same then the shape is closed and the ends are interwoven. 
//
//  If the points go clockwise the front face will be on the inside. If they go anticlockwise the 
//  front face will be the outside face. If the corners of the shape are not right-angles then the blocks
//  will not align quite properly at the corners.  
//
#macro Blockwall_FollowArray (Blockwall_BlockType)
  #ifndef(Blockwall_MatrixSpacing)   #declare Blockwall_MatrixSpacing   = 0.1;    #end
  #ifndef(Blockwall_WallHeight)      #declare Blockwall_WallHeight      = 1;      #end 
  #ifndef(Blockwall_MortarGap)       #declare Blockwall_MortarGap       = 0.0001; #end
  #ifndef(Blockwall_BlockThickness)  #declare Blockwall_BlockThickness  = Blockwall_MatrixSpacing-Blockwall_MortarGap;    #end 
  #ifndef(Blockwall_CornerTrimAngle) #declare Blockwall_CornerTrimAngle = 5;      #end
  
  #ifndef(Blockwall_CornerArray) 
    #declare Blockwall_CornerArray = array[5] {
      <0,0>,
      <1,0>,
      <1,1>,
      <0,1>,
      <0,0>
    }; 
  #end  
  #declare Blockwall_CornerArraySize = dimension_size(Blockwall_CornerArray,1);

  // Create a set of arrays to record information describing the wall segments and the corners.
  #local Blockwall_SideLengths       = array [Blockwall_CornerArraySize-1];
  #local Blockwall_SideUnits         = array [Blockwall_CornerArraySize-1];
  #local Blockwall_SideXScale        = array [Blockwall_CornerArraySize-1];
  #local Blockwall_CornerAngles      = array [Blockwall_CornerArraySize-1];
  #local Blockwall_CornerLengths     = array [Blockwall_CornerArraySize-1];
  #local Blockwall_ExtendCornerBlock = array [Blockwall_CornerArraySize-1];
  #local Blockwall_CutOutABlock      = array [Blockwall_CornerArraySize-1];
  #local Blockwall_TrimCorner        = array [Blockwall_CornerArraySize-1];

  // If the ends need to meet up, set the stones to wrap around the end creating a closed shape.
  // If the shape is open we don't really need information about the first corner because it's just a trailing end.
  #if (Blockwall_CornerArray[0].u = Blockwall_CornerArray[Blockwall_CornerArraySize-1].u 
     & Blockwall_CornerArray[0].v = Blockwall_CornerArray[Blockwall_CornerArraySize-1].v)
    #declare Blockwall_Wrap = 1; 
    #local Blockwall_I = 0;
  #else
    #declare Blockwall_Wrap = 0; 
    #local Blockwall_CornerAngles[0]      = 0;
    #local Blockwall_CornerLengths[0]     = 0;
    #local Blockwall_ExtendCornerBlock[0] = 0;
    #local Blockwall_CutOutABlock[0]      = 0;
    #local Blockwall_TrimCorner[0]        = 0;
    #local Blockwall_I = 1;
  #end

  // Loop through the corners recording information such as the angles at the joints. 
  // Angles are measured in degrees relative to the direction straight ahead and can range from -180 to +180 degrees.
  // We don't need any info about the last corner position because it is either in the same position as the 
  // first position and represents the same corner or it's not a real corner, it's just a second trailing end.
  #while (Blockwall_I<Blockwall_CornerArraySize-1) 
    // Work out the index of the first corner on the previous section of wall.
    // For the first corner with wrapping we use the last but one corner index as this is the start of the last 
    // section of wall, which will wrap around and meet the first section of wall.
    #local Blockwall_PI = (Blockwall_I=0?Blockwall_CornerArraySize-2:Blockwall_I-1);
    // Calculate direction vectors for the previous wall segment and for this wall segment. 
    #local Blockwall_PSVector = Blockwall_CornerArray[Blockwall_PI+1]-Blockwall_CornerArray[Blockwall_PI]; 
    #local Blockwall_TSVector = Blockwall_CornerArray[Blockwall_I +1]-Blockwall_CornerArray[Blockwall_I ];
    // Use the two vectors to calculate the angle through which the wall needs to turn at this corner. 
    #local Blockwall_CornerAngles[Blockwall_I] = VRotationD(
      <Blockwall_PSVector.u,0,Blockwall_PSVector.v>,
      <Blockwall_TSVector.u,0,Blockwall_TSVector.v>,
      y
    );
    // To enable proper joints to be cut, extra blockwork may need to be added to or cut away from a corner.
    // This switch clause uses the angle of the corner to determine various details including the length that needs 
    // adding at each corner. This calculated length does not take account of any horizontal scaling that may be 
    
    // needed to match with side lengths that are not an exact number of units.
    #ifndef(Blockwall_Debug) #declare Blockwall_Debug=0; #end
    #if(Blockwall_Debug) #debug "\n" #end
    #switch (1)
      // If the angle is close to -180 degrees, the wall is folded back on itself.
      #case (Blockwall_CornerAngles[Blockwall_I]<(-180+Blockwall_CornerTrimAngle))
        #if(Blockwall_Debug) #debug "Case 1\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = 0;
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 0;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 0;
      #break
      // From -180 to -90 one less block is needed.
      #case (Blockwall_CornerAngles[Blockwall_I]<(-90-Blockwall_CornerTrimAngle))
        #if(Blockwall_Debug) #debug "Case 2\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = 0;
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 0;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 1;
      #break
      // At -90 degrees (within the Blockwall_CornerTrimAngle limits) we need one less block.
      #case (Blockwall_CornerAngles[Blockwall_I]<(-90+Blockwall_CornerTrimAngle))
        #if(Blockwall_Debug) #debug "Case 3\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = 0;
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 0;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 0;
      #break 
      // From -90 to 0, a corner block may need to be extended by up to one full unit of blockwork.
      #case (Blockwall_CornerAngles[Blockwall_I]<(-Blockwall_CornerTrimAngle))
        #if(Blockwall_Debug) #debug "Case 4\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = 0;
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 1;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 1;
      #break
      // If it's straight (within the Blockwall_CornerTrimAngle limits) then don't remove a block from the length.
      #case (Blockwall_CornerAngles[Blockwall_I]<Blockwall_CornerTrimAngle)
        #if(Blockwall_Debug) #debug "Case 5\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = 0;
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 1;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 0;
        #local Blockwall_TrimCorner[Blockwall_I]        = 0;
      #break
      // If the wall turns right we need to extend the length to the position of the corner on the opposite side of the wall segment. 
      // From 0 to 90 extend by an amount dependant upon the angle.
      #case (Blockwall_CornerAngles[Blockwall_I]<(90-Blockwall_CornerTrimAngle))
        #if(Blockwall_Debug) #debug "Case 6\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = Blockwall_BlockThickness*tand(Blockwall_CornerAngles[Blockwall_I]/2);
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 1;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 1;
      #break
      // At 90 degrees (within the Blockwall_CornerTrimAngle limits).
      #case (Blockwall_CornerAngles[Blockwall_I]<(90+Blockwall_CornerTrimAngle))
        #if(Blockwall_Debug) #debug "Case 7\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = Blockwall_BlockThickness*tand(Blockwall_CornerAngles[Blockwall_I]/2);
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 0;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 0;
      #break 
      // From 90 to 180 we could need a lot more blockwork because it comes to a point. 
      // This could go up to infinity if we're not carefull, so we add a hardcoded limit of 179.
      #case (Blockwall_CornerAngles[Blockwall_I]<min(179,180-Blockwall_CornerTrimAngle))
        #if(Blockwall_Debug) #debug "Case 8\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = Blockwall_BlockThickness*tand(Blockwall_CornerAngles[Blockwall_I]/2);
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 0;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 1;
      #break 
      // Assume that any greater corner angle means that the wall is folding back on itself.
      #else
        #if(Blockwall_Debug) #debug "Case 9\n" #end
        #local Blockwall_CornerLengths[Blockwall_I]     = 0;
        #local Blockwall_ExtendCornerBlock[Blockwall_I] = 1;
        #local Blockwall_CutOutABlock[Blockwall_I]      = 1;
        #local Blockwall_TrimCorner[Blockwall_I]        = 0;
      #break
    #end
    #if(Blockwall_Debug) #debug concat("Blockwall_CornerAngles:  ",str(Blockwall_CornerAngles [Blockwall_I],3,3),"\n") #end
    #if(Blockwall_Debug) #debug concat("Blockwall_CornerLengths: ",str(Blockwall_CornerLengths[Blockwall_I],3,3),"\n") #end
    #local Blockwall_I = Blockwall_I + 1;
  #end


  // Loop through the sections of wall working out the dimensions required to generate 
  // the wall pattern and to assemble the wall segments.
//  #declare Blockwall_WallLength = 0;
  #declare Blockwall_MatrixDimX = 0;
  #local Blockwall_I = 0;
  #while (Blockwall_I<Blockwall_CornerArraySize-1)
    #local Blockwall_NominalSL = vlength(Blockwall_CornerArray[Blockwall_I+1] - Blockwall_CornerArray[Blockwall_I]);
    // There is no length element for the last corner so we use the first corner length instead, even
    // if it's an open shape, in which case the length of both the first and last corners should both be zero. 
    #local Blockwall_SecondCorner = (Blockwall_I<Blockwall_CornerArraySize-2?Blockwall_I+1:0);
    #local Blockwall_SideLengths[Blockwall_I] = Blockwall_NominalSL+Blockwall_CornerLengths[Blockwall_I]+Blockwall_CornerLengths[Blockwall_SecondCorner];
    // Keep a record of sidelengths in terms of number of matrix units  
    #local Blockwall_SideUnits[Blockwall_I] = floor(Blockwall_SideLengths[Blockwall_I]/Blockwall_MatrixSpacing+0.5) - Blockwall_CutOutABlock[Blockwall_SecondCorner];
    // After generating a run of standard blockwork, we'll need to scale the horizontal side length slightly to 
    // transform the whole number of units back to the real side length.  
    #local Blockwall_SideXScale[Blockwall_I] = Blockwall_SideLengths[Blockwall_I]/((Blockwall_SideUnits[Blockwall_I]+Blockwall_CutOutABlock[Blockwall_SecondCorner])*Blockwall_MatrixSpacing);
    #declare Blockwall_MatrixDimX = Blockwall_MatrixDimX + Blockwall_SideUnits[Blockwall_I];
//    #declare Blockwall_WallLength = Blockwall_WallLength + Blockwall_SideUnits[Blockwall_I]*Blockwall_MatrixSpacing; 
    #local Blockwall_I = Blockwall_I + 1;
  #end

  // Make sure we don't try and generate an empty matrix
  #declare Blockwall_MatrixDimX = max(1,Blockwall_MatrixDimX);
  #declare Blockwall_MatrixDimY = max(1,floor(Blockwall_WallHeight/Blockwall_MatrixSpacing+0.5)); 
  
  // Generate the wall matrix.
  #declare Blockwall_MatrixArray = array[Blockwall_MatrixDimX][Blockwall_MatrixDimY][2];
  Blockwall_MakeMatrix(Blockwall_MatrixArray)
  
  // Adjust the corner stone pattern so that it folds correctly at each corner.
  // The final 'corner' never needs adjusting. The first 'corner' only needs adjusting if the shape is closed.
  // Only adjust a corner if it is far enough off straight (ie if we had to cut a block out to bend the wall).
  #local Blockwall_MatrixIndex = 0;
  #if (Blockwall_Wrap & Blockwall_CutOutABlock[0])
    #local Blockwall_CornerIndex = 0;
    Blockwall_AdjustCorner(Blockwall_MatrixIndex)
  #end
  #local Blockwall_CornerIndex = 1;
  #while (Blockwall_CornerIndex<=Blockwall_CornerArraySize-2)
    #local Blockwall_MatrixIndex = Blockwall_MatrixIndex + Blockwall_SideUnits[Blockwall_CornerIndex-1];
    #if (Blockwall_CutOutABlock[Blockwall_CornerIndex])
      Blockwall_AdjustCorner(Blockwall_MatrixIndex)
    #end
    #local Blockwall_CornerIndex = Blockwall_CornerIndex + 1;
  #end 
  
  // Run along each section of wall, generating the blocks defined in the matrix.
  union {
    // Loop through the sections of wall
    #local Blockwall_WallSection = 0;
    #local Blockwall_StartIndex = 0;
    #while (Blockwall_WallSection<Blockwall_CornerArraySize-1)
      #local Blockwall_SectionAlignment = 
          <Blockwall_CornerArray[Blockwall_WallSection+1].u,0,Blockwall_CornerArray[Blockwall_WallSection+1].v> 
        - <Blockwall_CornerArray[Blockwall_WallSection  ].u,0,Blockwall_CornerArray[Blockwall_WallSection  ].v>;
      // There is no length element for the last corner so we use the first corner length instead, even
      // if it's an open shape, in which case the length of both the first and last corners should both be zero. 
      #local Blockwall_SecondCorner = (Blockwall_WallSection<Blockwall_CornerArraySize-2?Blockwall_WallSection+1:0);
      // Loop through the rows in the matrix
      #local Blockwall_J = 0;
      #while (Blockwall_J<Blockwall_MatrixDimY)
        // Loop through the horizontal positions in the matrix for this section of wall
        #local Blockwall_I = 0;
        #while (Blockwall_I<Blockwall_SideUnits[Blockwall_WallSection])
          // If a block starts in this position in the matrix, then work out its position and dimensions. 
//#debug concat("...",str(Blockwall_WallSection,3,3),"\n")
          
          #ifdef(Blockwall_MatrixArray[Blockwall_I+Blockwall_StartIndex][Blockwall_J][1])
            #local Blockwall_W = Blockwall_MatrixArray[Blockwall_I+Blockwall_StartIndex][Blockwall_J][0];
            #local Blockwall_H = Blockwall_MatrixArray[Blockwall_I+Blockwall_StartIndex][Blockwall_J][1];
            #if (Blockwall_ExtendCornerBlock[Blockwall_SecondCorner] & Blockwall_I+Blockwall_W >= Blockwall_SideUnits[Blockwall_WallSection])
              #local Blockwall_W = Blockwall_W+1;
            #end
            
            // Generate it in an axis-aligned position relative to the start of the section
            #declare Blockwall_TopLeft     = <
              Blockwall_MatrixSpacing*Blockwall_I,
              Blockwall_MatrixSpacing*(Blockwall_J+Blockwall_H),
              0>;
            #declare Blockwall_TopRight    = <
              Blockwall_MatrixSpacing*(Blockwall_I+Blockwall_W),
              Blockwall_MatrixSpacing*(Blockwall_J+Blockwall_H),
              0>;
            #declare Blockwall_BottomRight = <
              Blockwall_MatrixSpacing*(Blockwall_I+Blockwall_W),
              Blockwall_MatrixSpacing*Blockwall_J,
              0>; 
            #declare Blockwall_BottomLeft  = <
              Blockwall_MatrixSpacing*Blockwall_I,
              Blockwall_MatrixSpacing*Blockwall_J,
              0>;
            
            // Blockwall_BlockThicknessDecrement can be used by the Blockwall macros to reduce the thickness of higher 
            // layers of blocks relative to the thickness at the base of the wall. 
            #ifdef(Blockwall_BlockThicknessDecrement) 
              #declare Blockwall_BlockThinning = Blockwall_BlockThicknessDecrement*Blockwall_J; 
            #end 
            
            #local Blockwall_ThisBlock = object {
              Blockwall_Block(Blockwall_TopLeft, Blockwall_TopRight, Blockwall_BottomRight, Blockwall_BottomLeft, Blockwall_BlockType)
              // Scale to adjust for side lengths that aren't an exact number of blocks
              scale <Blockwall_SideXScale[Blockwall_WallSection],1,1>
              // Align and translate the block to its proper location.
              translate -x*Blockwall_CornerLengths[Blockwall_WallSection]
              #ifdef (Blockwall_BlockThinning) translate z*Blockwall_BlockThinning/2 #end
            }
            // Optionally cut away part or all of the block to make a hole in the wall
            #ifdef (Blockwall_Holes)
              difference {
            #end
            difference {
              object {Blockwall_ThisBlock}
              sphere {0,0.00000000001}  // Avoid lots of warnings about CSG only containing one object.
              // Trim the first corner
              #if (Blockwall_TrimCorner[Blockwall_WallSection])
                #if (Blockwall_CornerAngles[Blockwall_WallSection]>0)
                  plane {-z,0.001
                    rotate -y*Blockwall_CornerAngles[Blockwall_WallSection]
                    translate z*Blockwall_BlockThickness 
                      - x*Blockwall_BlockThickness*tand(Blockwall_CornerAngles[Blockwall_WallSection]/2) 
                    texture {Blockwall_ThisBlockTexture}
                  }
                #else
                  plane {z,0.001
                    rotate -y*Blockwall_CornerAngles[Blockwall_WallSection]
                    texture {Blockwall_ThisBlockTexture}
                  }
                  box {<0,0,-Blockwall_BlockThickness/4>,<-Blockwall_BlockThickness,Blockwall_WallHeight+0.001,Blockwall_BlockThickness/4>
                    rotate -y*Blockwall_CornerAngles[Blockwall_WallSection]
//                    translate x*Blockwall_RSL
                    translate vrotate(-x*Blockwall_MatrixSpacing,-y*Blockwall_CornerAngles[Blockwall_WallSection])
                    texture {Blockwall_ThisBlockTexture}
                  }
                #end 
              #end
              // Trim the second corner  
              #if (Blockwall_TrimCorner[Blockwall_SecondCorner])
                #local Blockwall_RSL = vlength(Blockwall_CornerArray[Blockwall_SecondCorner]-Blockwall_CornerArray[Blockwall_WallSection]);
                #if (Blockwall_CornerAngles[Blockwall_SecondCorner]<0)
                  plane {z,0.001
                    rotate y*Blockwall_CornerAngles[Blockwall_SecondCorner]
                    translate x*Blockwall_RSL
                    texture {Blockwall_ThisBlockTexture}
                  }
                  box {<0,0,-Blockwall_BlockThickness/4>,<Blockwall_BlockThickness,Blockwall_WallHeight+0.001,Blockwall_BlockThickness/4>
                    rotate y*Blockwall_CornerAngles[Blockwall_SecondCorner]
                    translate x*Blockwall_RSL
                    translate vrotate(x*Blockwall_MatrixSpacing,y*Blockwall_CornerAngles[Blockwall_SecondCorner])
                    texture {Blockwall_ThisBlockTexture}
                  }
                #else 
                  plane {-z,0.001
                    rotate y*Blockwall_CornerAngles[Blockwall_SecondCorner]
                    translate x*Blockwall_RSL 
                      + z*Blockwall_BlockThickness 
                      + x*Blockwall_BlockThickness*tand(Blockwall_CornerAngles[Blockwall_SecondCorner]/2) 
                    texture {Blockwall_ThisBlockTexture}
                  }
                #end 
              #end
              Reorient_Trans(x,Blockwall_SectionAlignment)
              translate <Blockwall_CornerArray[Blockwall_WallSection].u,0,Blockwall_CornerArray[Blockwall_WallSection].v>
//    translate y*0.0001*rand(Blockwall_SizeSeed)
            }
            // Optionally cut away part or all of the block to make a hole in the wall
            #ifdef (Blockwall_Holes) 
                object {Blockwall_Holes texture {Blockwall_ThisBlockTexture}}
              }
            #end
          #end
          #local Blockwall_I = Blockwall_I + 1;
        #end
        #local Blockwall_J = Blockwall_J + 1;
      #end
      #local Blockwall_StartIndex  = Blockwall_StartIndex + Blockwall_SideUnits[Blockwall_WallSection];
      #local Blockwall_WallSection = Blockwall_WallSection + 1;
    #end
  }
#end  
          


// This macro adjust the matrix so that there is a junction either to the left or right of each corner stone.
// for a specified corner position.
// It follows a line up the matrix and, if there is no suitable junction it creates one by shortening blocks so
// that the matrix can fold along the required line.
#macro Blockwall_AdjustCorner(Blockwall_MatrixIndex)
  // If the column identified in the parameter or the column after it contains the start of a block then
  // that row is ok. 
  #local Blockwall_J = 0;
  #while (Blockwall_J<Blockwall_MatrixDimY)
    #ifdef(Blockwall_MatrixArray[Blockwall_MatrixIndex][Blockwall_J][1])
      #local Blockwall_H1 = Blockwall_MatrixArray[Blockwall_MatrixIndex][Blockwall_J][1];
    #else
      #local Blockwall_H1 = 0;
    #end
    #ifdef(Blockwall_MatrixArray[Blockwall_MatrixIndex+1][Blockwall_J][1])
      #local Blockwall_H2 = Blockwall_MatrixArray[Blockwall_MatrixIndex+1][Blockwall_J][1];
    #else 
      #local Blockwall_H2 = 0;
      #if (Blockwall_H1 = 0)
        // We've identified that a block overruns the corner, so we need to cut it in two.
        // We trace back along the line to find the start of the offending block and its dimensions.
        #local Blockwall_Backstep = 0;
        #while (Blockwall_H2=0)
          #local Blockwall_Backstep = Blockwall_Backstep + 1;
          #local Blockwall_IndexToCheck = Blockwall_MatrixIndex - Blockwall_Backstep;
          // If this takes us back before the start of the row, wrap around to the end of the row.
          #if (Blockwall_IndexToCheck<0)
            #local Blockwall_IndexToCheck = Blockwall_IndexToCheck + Blockwall_MatrixDimX;
          #end
          // Once we find a block definition, store the dimensions and break out of the loop to check the next row.
          #ifdef (Blockwall_MatrixArray[Blockwall_IndexToCheck][Blockwall_J][1])
            #local Blockwall_W2 = Blockwall_MatrixArray[Blockwall_IndexToCheck][Blockwall_J][0];
            #local Blockwall_H2 = Blockwall_MatrixArray[Blockwall_IndexToCheck][Blockwall_J][1];
            // Adjust the block width and add another block to fill the new gap.
            #if (rand(Blockwall_SizeSeed)>0.5)
              #declare Blockwall_MatrixArray[Blockwall_IndexToCheck][Blockwall_J][0] = Blockwall_Backstep;
              #declare Blockwall_MatrixArray[Blockwall_MatrixIndex][Blockwall_J][0] = Blockwall_W2-Blockwall_Backstep;
              #declare Blockwall_MatrixArray[Blockwall_MatrixIndex][Blockwall_J][1] = Blockwall_H2; 
            #else
              #declare Blockwall_MatrixArray[Blockwall_IndexToCheck][Blockwall_J][0] = Blockwall_Backstep+1;
              #declare Blockwall_MatrixArray[Blockwall_MatrixIndex+1][Blockwall_J][0] = Blockwall_W2-Blockwall_Backstep-1;
              #declare Blockwall_MatrixArray[Blockwall_MatrixIndex+1][Blockwall_J][1] = Blockwall_H2; 
            #end
          #end 
        #end
      #end
    #end
    #local Blockwall_J = Blockwall_J + max(Blockwall_H1,Blockwall_H2);
  #end
#end


//  This macro creates a circular (cylindrical) wall or a segment of a circular wall.
//
#macro Blockwall_Arc (Blockwall_ArcDegrees, Blockwall_BlockType) 
  #ifndef(Blockwall_Radius) #declare Blockwall_Radius  = 1;    #end
  #declare Blockwall_Spline = spline {
    cubic_spline
    #local Blockwall_I = -0.25;
    #while (Blockwall_I<=1.25)  
      Blockwall_I, vrotate(Blockwall_Radius*z, y*Blockwall_I*Blockwall_ArcDegrees)
      #local Blockwall_I = Blockwall_I + 0.01;
    #end
  }
  object {Blockwall_FollowSpline(Blockwall_BlockType)}  
#end


//  This macro creates a wall, where the base of the wall follows a spline.
//
#macro Blockwall_FollowSpline (Blockwall_BlockType) 
  #ifndef(Blockwall_BlockThickness) #declare Blockwall_BlockThickness  = 0.25;    #end
  #ifndef(Blockwall_WallHeight    ) #declare Blockwall_WallHeight      = 0.8;     #end
  #ifndef(Blockwall_MatrixSpacing ) #declare Blockwall_MatrixSpacing   = 0.1;     #end
  // The default spline draws a bridge-like shape along the +Z axis.
  #ifndef (Blockwall_Spline) 
    #declare Blockwall_Spline = spline {
      cubic_spline
      -.25, <0,0,-1>
      0.00, <0,0,0>
      0.25, <0,0,0.5>
      0.50, <0,0.2,1.5>
      0.75, <0,0,2.5>
      1.00, <0,0,3>
      1.25, <0,0,4>
    }
  #end

  // If the start and end of the spline are close enough wrapping defaults to 1. Otherwise 0.
  #ifndef(Blockwall_Wrap)
    #if (vlength(Blockwall_Spline(0)-Blockwall_Spline(1))<0.01) 
      #declare Blockwall_Wrap = 1;
    #else
      #declare Blockwall_Wrap = 0;
    #end       
  #end

  // Work out the length of the wall (the length of the spline from 0 to 1).
  #local Blockwall_SplineDistance = 0;
  #local Blockwall_PreviousPosition = Blockwall_Spline(0);
  #local Blockwall_I = 0;
  #while (Blockwall_I <= 10000)
    #local Blockwall_SplineDistance = Blockwall_SplineDistance + vlength(Blockwall_Spline(Blockwall_I/10000)-Blockwall_PreviousPosition);
    #local Blockwall_PreviousPosition = Blockwall_Spline(Blockwall_I/10000);
    #local Blockwall_I = Blockwall_I + 1;
  #end 

  // Adjust the matrix spacing so that we can get the right wall length using a whole number of blocks.
  #declare Blockwall_UnitCount                          = floor(0.5+Blockwall_SplineDistance/Blockwall_MatrixSpacing);  
  #declare Blockwall_AdjustedMatrixSpacing              = Blockwall_SplineDistance/Blockwall_UnitCount;
  // Initialise an array that will hold the positions that will be used for the bottom row of blocks.
  #declare Blockwall_PositionArrayIndex                 = 0; 
  #declare Blockwall_PositionArray                      = array[Blockwall_UnitCount+1];
  #declare Blockwall_PositionArray[0]                   = Blockwall_Spline(0);
  #declare Blockwall_PositionArray[Blockwall_UnitCount] = Blockwall_Spline(1);
  
  // Step through the spline again to work out the positions that will be used 
  // for the bottom row of blocks. 
  #local Blockwall_SplineDistance = 0;
  #local Blockwall_PreviousPosition = Blockwall_Spline(0);
  #local Blockwall_SplineSteps = 10*Blockwall_UnitCount;
  #local Blockwall_I = 0;
  #while (Blockwall_I <= Blockwall_SplineSteps)
    #local Blockwall_SplineDistance = Blockwall_SplineDistance + vlength(Blockwall_Spline(Blockwall_I/Blockwall_SplineSteps)-Blockwall_PreviousPosition);
    #if (((Blockwall_SplineDistance/Blockwall_AdjustedMatrixSpacing) - Blockwall_PositionArrayIndex) >= 1)
      #declare Blockwall_PositionArrayIndex = Blockwall_PositionArrayIndex + 1; 
      #declare Blockwall_PositionArray[Blockwall_PositionArrayIndex] = Blockwall_Spline(Blockwall_I/Blockwall_SplineSteps);
    #end
    #local Blockwall_PreviousPosition = Blockwall_Spline(Blockwall_I/Blockwall_SplineSteps);
    #local Blockwall_I = Blockwall_I + 1;
  #end
   
  // Calculate the centre to centre distance to make adjacent stretches of wall meet (given appropriate alignment).
  #declare Blockwall_CentreToCentre = Blockwall_PositionArray[Blockwall_PositionArrayIndex]-Blockwall_PositionArray[0];
  // Work out the dimensions of the matrix required.
  #declare Blockwall_MatrixDimX = Blockwall_UnitCount;
  #declare Blockwall_MatrixDimY = floor(max(1,Blockwall_WallHeight/Blockwall_AdjustedMatrixSpacing+0.5));
  // Generate the matrix.
  #declare Blockwall_MatrixArray = array[Blockwall_MatrixDimX][Blockwall_MatrixDimY][2];
  Blockwall_MakeMatrix(Blockwall_MatrixArray)                              
  // Work out how much we need to scale the blocks by vertically to get the required wall height
  #local Blockwall_VerticalScaleFactor = Blockwall_WallHeight/(Blockwall_MatrixDimY*Blockwall_AdjustedMatrixSpacing);

  // Use the matrix to define blocks to build the wall  
  #local Blockwall_J = 0;
  union {
    #while (Blockwall_J < Blockwall_MatrixDimY)
      #local Blockwall_I = 0;
      #while (Blockwall_I < Blockwall_MatrixDimX)
        // If the second matrix position is set then this position is the bottom left of a new block.
        #ifdef(Blockwall_MatrixArray[Blockwall_I][Blockwall_J][1])
          #local Blockwall_W = Blockwall_MatrixArray[Blockwall_I][Blockwall_J][0];
          #local Blockwall_H = Blockwall_MatrixArray[Blockwall_I][Blockwall_J][1];
          #local Blockwall_R = Blockwall_I+Blockwall_W;
          #if (Blockwall_R>=Blockwall_MatrixDimX & Blockwall_Wrap) #local Blockwall_R = Blockwall_R - Blockwall_MatrixDimX; #end

          // These variables all refer to the front face of the block
          #local Blockwall_BaseLeft          = Blockwall_PositionArray[Blockwall_I];
          #local Blockwall_BaseRight         = Blockwall_PositionArray[Blockwall_R];
          #local Blockwall_BaseVector        = vnormalize(Blockwall_BaseRight - Blockwall_BaseLeft);
          #local Blockwall_Horizon           = VPerp_To_Plane(Blockwall_BaseVector, -y);
          #local Blockwall_SideVector        = VPerp_To_Plane(Blockwall_BaseVector, Blockwall_Horizon);
          #local Blockwall_BaseCenter        = (Blockwall_BaseLeft+Blockwall_BaseRight)/2;
          #local Blockwall_BlockCenter       = Blockwall_BaseCenter+(Blockwall_J+Blockwall_H/2)*y*Blockwall_VerticalScaleFactor*Blockwall_AdjustedMatrixSpacing;
          
          #declare Blockwall_TopLeft     = <
            -Blockwall_AdjustedMatrixSpacing*Blockwall_W/2,
             Blockwall_VerticalScaleFactor*Blockwall_AdjustedMatrixSpacing*Blockwall_H/2,
             0>;
          #declare Blockwall_TopRight    = <
             Blockwall_AdjustedMatrixSpacing*Blockwall_W/2,
             Blockwall_VerticalScaleFactor*Blockwall_AdjustedMatrixSpacing*Blockwall_H/2,
             0>;
          #declare Blockwall_BottomRight = <
             Blockwall_AdjustedMatrixSpacing*Blockwall_W/2,
            -Blockwall_VerticalScaleFactor*Blockwall_AdjustedMatrixSpacing*Blockwall_H/2,
             0>;
          #declare Blockwall_BottomLeft  = <
            -Blockwall_AdjustedMatrixSpacing*Blockwall_W/2,
            -Blockwall_VerticalScaleFactor*Blockwall_AdjustedMatrixSpacing*Blockwall_H/2,
             0>;
          
          // Blockwall_BlockThicknessDecrement can be used by the Blockwall macros to reduce the thickness of higher 
          // layers of blocks relative to the thickness at the base of the wall. 
          #ifdef(Blockwall_BlockThicknessDecrement) 
            #declare Blockwall_BlockThinning = Blockwall_BlockThicknessDecrement*Blockwall_J; 
          #end 

          // Optionally cut away part or all of the block to make a hole in the wall
          #ifdef (Blockwall_Holes)
            difference {
          #end
          // Generate the block
          object {
            Blockwall_Block(Blockwall_TopLeft, Blockwall_TopRight, Blockwall_BottomRight, Blockwall_BottomLeft, Blockwall_BlockType)
            #ifdef (Blockwall_BlockThinning) translate z*Blockwall_BlockThinning/2 #end
            Reorient_Trans(x, <Blockwall_BaseVector.x,0,Blockwall_BaseVector.z>)
            Reorient_Trans(<Blockwall_BaseVector.x,0,Blockwall_BaseVector.z>,Blockwall_BaseVector)
            translate Blockwall_BlockCenter
          }
          // Optionally cut away part or all of the block to make a hole in the wall
          #ifdef (Blockwall_Holes) 
              object {Blockwall_Holes texture {Blockwall_ThisBlockTexture}}
            }
          #end
          
        #end
        #local Blockwall_I = Blockwall_I + 1; 
      #end
      #local Blockwall_J = Blockwall_J + 1; 
    #end  
//    scale <1,Blockwall_WallHeight/Blockwall_MatrixSpacing*Blockwall_MatrixDimY,1>
  } 
#end  


// The Blockwall_DropSplineToSurface macro drops the spline assigned to identifier Blockwall_Spline 
// onto the surface of the target object assigned to the identifier Blockwall_Target.
//
#macro Blockwall_DropSplineToSurface()
  // The default spline draws a bridge-like shape along the +Z axis.
  #ifndef (Blockwall_Spline) 
    #declare Blockwall_Spline = spline {
      cubic_spline
      -.25, <0,0,-1>
      0.00, <0,0,0>
      0.25, <0,0,0.5>
      0.50, <0,0.2,1.5>
      0.75, <0,0,2.5>
      1.00, <0,0,3>
      1.25, <0,0,4>
    }
  #end
  #ifndef (Blockwall_Target)
    #declare Blockwall_Target = plane {y,-0.01}
  #end 
  
  #declare Blockwall_NewSpline = spline {
    cubic_spline
    #local Blockwall_I = 0;
    #while (Blockwall_I<=1) 
      #declare Blockwall_N  = <0, 0, 0>; 
      #declare Blockwall_S = Blockwall_Spline(Blockwall_I)+y; 
      #declare Blockwall_P = trace ( Blockwall_Target, Blockwall_S, -y, Blockwall_N ); 
      #if (vlength(Blockwall_N)!=0) 
        Blockwall_I, Blockwall_P
      #end
      #local Blockwall_I = Blockwall_I + 0.001;
    #end
  }
  
  #declare Blockwall_Spline = Blockwall_NewSpline;
#end

// Macro to undef the main control settings so that they revert to their defaults the
// next time the Blockwall macro is called.
#macro Blockwall_Undef() 

  #ifdef(Blockwall_Radius              ) #undef Blockwall_Radius               #end
  #ifdef(Blockwall_BlockThickness      ) #undef Blockwall_BlockThickness       #end  
  #ifdef(Blockwall_ColorSeed           ) #undef Blockwall_ColorSeed            #end                  
  #ifdef(Blockwall_SizeSeed            ) #undef Blockwall_SizeSeed             #end                  
  #ifdef(Blockwall_MortarGap           ) #undef Blockwall_MortarGap            #end
  #ifdef(Blockwall_BlockThickness      ) #undef Blockwall_BlockThickness       #end
  #ifdef(Blockwall_BlockRoundness      ) #undef Blockwall_BlockRoundness       #end
  #ifdef(Blockwall_MinColor            ) #undef Blockwall_MinColor             #end
  #ifdef(Blockwall_MaxColor            ) #undef Blockwall_MaxColor             #end
  #ifdef(Blockwall_Contrast            ) #undef Blockwall_Contrast             #end
  #ifdef(Blockwall_Brightness          ) #undef Blockwall_Brightness           #end
  #ifdef(Blockwall_Normal              ) #undef Blockwall_Normal               #end
  #ifdef(Blockwall_Finish              ) #undef Blockwall_Finish               #end    
  #ifdef(Blockwall_Wrap                ) #undef Blockwall_Wrap                 #end
  #ifdef(Blockwall_Spline              ) #undef Blockwall_Spline               #end
  #ifdef(Blockwall_CornerArray         ) #undef Blockwall_CornerArray          #end
  #ifdef(Blockwall_ClipBlock           ) #undef Blockwall_ClipBlock            #end
  #ifdef(Blockwall_RoughStoneRandomness) #undef Blockwall_RoughStoneRandomness #end
  #ifdef(Blockwall_RoughStoneSeed      ) #undef Blockwall_RoughStoneSeed       #end
  #ifdef(Blockwall_HBias               ) #undef Blockwall_HBias                #end
  #ifdef(Blockwall_VBias               ) #undef Blockwall_VBias                #end
  #ifdef(Blockwall_MaxHU               ) #undef Blockwall_MaxHU                #end
  #ifdef(Blockwall_MaxVU               ) #undef Blockwall_MaxVU                #end
  #ifdef(Blockwall_SizeSeed            ) #undef Blockwall_SizeSeed             #end
  #ifdef(Blockwall_WallLength          ) #undef Blockwall_WallLength           #end
  #ifdef(Blockwall_WallHeight          ) #undef Blockwall_WallHeight           #end 
  #ifdef(Blockwall_MatrixArray         ) #undef Blockwall_MatrixArray          #end
  #ifdef(Blockwall_MatrixSpacing       ) #undef Blockwall_MatrixSpacing        #end
  #ifdef(Blockwall_CornerTrimAngle     ) #undef Blockwall_CornerTrimAngle      #end 
  #ifdef(Blockwall_Holes               ) #undef Blockwall_Holes                #end 

#end



