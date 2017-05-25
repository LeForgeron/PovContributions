// curvedpaving.inc
// ----------------

// This include file can be used to generate interlocking curved bands of 
// block pavers in a "bogen" or "segmental arc" pattern commonly found in
// traditionally block-paved European streets.
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

// Macro to draw a single stone block
#macro CurvedPaving_Block(CurvedPaving_TopLeft, CurvedPaving_TopRight, CurvedPaving_BottomRight, CurvedPaving_BottomLeft, CurvedPaving_BlockType)
  // Set defaults
  #ifndef (CurvedPaving_MortarGap)       #declare CurvedPaving_MortarGap       = 0.0001;           #end
  #ifndef (CurvedPaving_BlockThickness ) #declare CurvedPaving_BlockThickness  = 0.08;             #end
  #ifndef (CurvedPaving_BlockRoundness ) #declare CurvedPaving_BlockRoundness  = 0.4;              #end
  #ifndef (CurvedPaving_MinColor       ) #declare CurvedPaving_MinColor        = <0.6,0.3,0.3>;    #end
  #ifndef (CurvedPaving_MaxColor       ) #declare CurvedPaving_MaxColor        = <0.75,0.35,0.35>; #end
  #ifndef (CurvedPaving_Contrast       ) #declare CurvedPaving_Contrast        = 0.8;              #end
  #ifndef (CurvedPaving_Brightness     ) #declare CurvedPaving_Brightness      = 1;                #end
  #ifndef (CurvedPaving_Normal) 
    #declare CurvedPaving_Normal = normal {granite scale 0.1}
  #end
  #ifndef (CurvedPaving_Finish) 
    #declare CurvedPaving_Finish = finish {phong 0}
  #end    
  
  // This switch provides support for several predefined color and contrast settings.
  #switch(0)
    #case(strcmp(CurvedPaving_BlockType, "BuffBrick")!=0)
      #declare CurvedPaving_MinColor        = <0.9,0.7,0.5>;   
      #declare CurvedPaving_MaxColor        = <1.0,0.8,0.6>;
      #declare CurvedPaving_Contrast        = 0.4;             
    #break
    #case(strcmp(CurvedPaving_BlockType, "GreenBrick")!=0)
      #declare CurvedPaving_MinColor        = <0.7,0.6,0.3>;   
      #declare CurvedPaving_MaxColor        = <0.85,0.75,0.35>;
      #declare CurvedPaving_Contrast        = 0.8;             
    #break
    #case(strcmp(CurvedPaving_BlockType, "GreyBrick")!=0)
      #declare CurvedPaving_MinColor        = <0.8,0.8,0.7>;   
      #declare CurvedPaving_MaxColor        = <0.9,0.9,0.8>;
      #declare CurvedPaving_Contrast        = 0.9;             
    #break
    #case(strcmp(CurvedPaving_BlockType, "BlueBrick")!=0)
      #declare CurvedPaving_MinColor        = <0.7,0.7,0.8>;   
      #declare CurvedPaving_MaxColor        = <0.8,0.8,1.0>;
      #declare CurvedPaving_Contrast        = 0.75;             
    #break
    #case(strcmp(CurvedPaving_BlockType, "PinkBrick")!=0)
      #declare CurvedPaving_MinColor        = <0.9,0.55,0.55>;      
      #declare CurvedPaving_MaxColor        = <1.0,0.6,0.6>;
      #declare CurvedPaving_Contrast        = 0.4;             
    #break
    #case(strcmp(CurvedPaving_BlockType, "RedBrick")!=0)
      #declare CurvedPaving_MinColor        = <0.6,0.3,0.3>;   
      #declare CurvedPaving_MaxColor        = <0.75,0.35,0.35>;
      #declare CurvedPaving_Contrast        = 0.8;             
    #break
  #end  

  // Calculate certain block dimensions; e.g. a midline and the inset of the bottom left corner.
  // Not all values are used by all shapes. For example CurvedPaving_X isn't used by the Polygon shape.   
  #local CurvedPaving_X            = vlength(CurvedPaving_BottomLeft - CurvedPaving_BottomRight) - CurvedPaving_MortarGap;
  #local CurvedPaving_TopMiddle    = (CurvedPaving_TopLeft    + CurvedPaving_TopRight    )/2;
  #local CurvedPaving_BottomMiddle = (CurvedPaving_BottomLeft + CurvedPaving_BottomRight )/2;
  #local CurvedPaving_Centre       = (CurvedPaving_TopMiddle  + CurvedPaving_BottomMiddle)/2;
  #local CurvedPaving_Z            = vlength(CurvedPaving_TopMiddle - CurvedPaving_BottomMiddle) - CurvedPaving_MortarGap;
  #local CurvedPaving_MortarInset  = CurvedPaving_MortarGap*<1,0,1>/2;  

  // The Polygon shape (and potentially others) draw straight to the inset position.
  #local CurvedPaving_InsetTopLeft     = CurvedPaving_TopLeft +
    vnormalize(CurvedPaving_Centre-CurvedPaving_TopLeft    )*sqrt(2)*CurvedPaving_MortarGap/2;
  #local CurvedPaving_InsetTopRight    = CurvedPaving_TopRight +
    vnormalize(CurvedPaving_Centre-CurvedPaving_TopRight   )*sqrt(2)*CurvedPaving_MortarGap/2;
  #local CurvedPaving_InsetBottomRight = CurvedPaving_BottomRight +
    vnormalize(CurvedPaving_Centre-CurvedPaving_BottomRight)*sqrt(2)*CurvedPaving_MortarGap/2;
  #local CurvedPaving_InsetBottomLeft  = CurvedPaving_BottomLeft +
    vnormalize(CurvedPaving_Centre-CurvedPaving_BottomLeft )*sqrt(2)*CurvedPaving_MortarGap/2;

  // Select a randomised color for this block  (within the given range)
  #local CurvedPaving_ColorRange = CurvedPaving_MaxColor - CurvedPaving_MinColor;
  #local CurvedPaving_R = CurvedPaving_MinColor.red  +rand(CurvedPaving_RandomSeed)*CurvedPaving_ColorRange.red;
  #local CurvedPaving_G = CurvedPaving_MinColor.green+rand(CurvedPaving_RandomSeed)*CurvedPaving_ColorRange.green;
  #local CurvedPaving_B = CurvedPaving_MinColor.blue +rand(CurvedPaving_RandomSeed)*CurvedPaving_ColorRange.blue;
  
  // Define a texture for this block
  #declare CurvedPaving_ThisBlockTexture = texture {
    pigment {color rgb <CurvedPaving_R,CurvedPaving_G,CurvedPaving_B>*(1-CurvedPaving_Contrast*rand(CurvedPaving_RandomSeed))*CurvedPaving_Brightness} 
    normal {CurvedPaving_Normal translate rand(CurvedPaving_RandomSeed)*1000*z} 
    finish {CurvedPaving_Finish}
  }
  
  // This switch provides support for a variety of shapes.
  #switch(0)
    #case(strcmp(CurvedPaving_BlockType, "Box")!=0)
      box {-y*CurvedPaving_BlockThickness, <CurvedPaving_X,0, CurvedPaving_Z>
        translate CurvedPaving_MortarInset
        texture {CurvedPaving_ThisBlockTexture}
        Reorient_Trans(z, CurvedPaving_TopMiddle-CurvedPaving_BottomMiddle)
        translate CurvedPaving_BottomLeft
      }
    #break
    #case(strcmp(CurvedPaving_BlockType, "Polygon")!=0)
      polygon {
        5,
        <CurvedPaving_InsetTopLeft.x    ,CurvedPaving_InsetTopLeft.z    >, 
        <CurvedPaving_InsetTopRight.x   ,CurvedPaving_InsetTopRight.z   >, 
        <CurvedPaving_InsetBottomRight.x,CurvedPaving_InsetBottomRight.z>, 
        <CurvedPaving_InsetBottomLeft.x ,CurvedPaving_InsetBottomLeft.z >, 
        <CurvedPaving_InsetTopLeft.x    ,CurvedPaving_InsetTopLeft.z    > 
        rotate 90*x
        texture {CurvedPaving_ThisBlockTexture}
      }
    #break
    #case(strcmp(CurvedPaving_BlockType, "SquarePolygon")!=0)
      polygon {
        5,
        <0             ,0>, 
        <0             ,CurvedPaving_Z>,
        <CurvedPaving_X,CurvedPaving_Z>,
        <CurvedPaving_X,0>,
        <0             ,0>
        rotate 90*x
        translate CurvedPaving_MortarInset
        Reorient_Trans(z, CurvedPaving_TopMiddle-CurvedPaving_BottomMiddle)
        translate CurvedPaving_BottomLeft
        texture {CurvedPaving_ThisBlockTexture}
      }
    #break
    // RandomColorSuperellipsoid is the default
    #case(strcmp(CurvedPaving_BlockType, "Superellipsoid")!=0)
    #else
      superellipsoid { <1,1>*CurvedPaving_BlockRoundness 
        scale 0.5
        translate <0.5,-0.5,0.5>
        scale <CurvedPaving_X,CurvedPaving_BlockThickness, CurvedPaving_Z>
        translate CurvedPaving_MortarInset
        texture {CurvedPaving_ThisBlockTexture}
        Reorient_Trans(z, CurvedPaving_TopMiddle-CurvedPaving_BottomMiddle)
        translate CurvedPaving_BottomLeft
      }
    #break
  #end
#end 


// Macro to draw a row of blocks
#macro CurvedPaving_ArcOfBlocks(CurvedPaving_BlockType)
  #local CurvedPaving_Angle = 0;
  #local CurvedPaving_BlockCounter = 0;
  #while (CurvedPaving_BlockCounter <= CurvedPaving_BlocksPerArc)         
    #local CurvedPaving_TopLeft     = vrotate(CurvedPaving_Radius*z,y*(-45+CurvedPaving_Angle));
    #local CurvedPaving_TopRight    = vrotate(CurvedPaving_Radius*z,y*(-45+CurvedPaving_Angle+CurvedPaving_BlockAngle));
    // Find the inner arc positions by moving the top points back in towards the centre
    // Note. This uses a little approximation. 
    #local CurvedPaving_BottomLeft  = CurvedPaving_TopLeft  - vnormalize(CurvedPaving_TopLeft)  * CurvedPaving_BlockDepth*cosd(-45+CurvedPaving_Angle);
    #local CurvedPaving_BottomRight = CurvedPaving_TopRight - vnormalize(CurvedPaving_TopRight) * CurvedPaving_BlockDepth*cosd(-45+CurvedPaving_Angle+CurvedPaving_BlockAngle);
    // Draw an individual block
    CurvedPaving_Block(CurvedPaving_TopLeft, CurvedPaving_TopRight, CurvedPaving_BottomRight, CurvedPaving_BottomLeft, CurvedPaving_BlockType)
    // Increment counters
    #local CurvedPaving_BlockCounter = CurvedPaving_BlockCounter + 1;
    #if (CurvedPaving_BlockCounter < CurvedPaving_BlocksPerArc-1)
      #local CurvedPaving_Angle = CurvedPaving_Angle + CurvedPaving_BlockAngle;
    #else
      #local CurvedPaving_Angle = CurvedPaving_Angle + CurvedPaving_BlockAngle*0.95;
    #end 
  #end
#end


// Macro to draw a row of blocks
#macro CurvedPaving(CurvedPaving_BlockType) 
  // Set defaults
  #ifndef(CurvedPaving_Radius    ) #declare CurvedPaving_Radius     = 1;       #end
  #ifndef(CurvedPaving_BlockDepth) #declare CurvedPaving_BlockDepth = 0.1;     #end  
  #ifndef(CurvedPaving_Rows)       #declare CurvedPaving_Rows       = 20;      #end  
  #ifndef(CurvedPaving_RandomSeed) #declare CurvedPaving_RandomSeed = seed(1); #end                  

  // Calculate the centre to centre distance to make adjacent arcs meet at right angles
  #declare CurvedPaving_CentreToCentre = CurvedPaving_Radius*sqrt(2);
  // Find the total length of an outer arc
  #declare CurvedPaving_ArcLength = 2*pi*CurvedPaving_Radius/4;
  // Calculate the arc angle taken up by each block
  #declare CurvedPaving_BlocksPerArc = int(CurvedPaving_ArcLength/(CurvedPaving_BlockDepth*0.8)); 
  #declare CurvedPaving_BlockAngle = 90/CurvedPaving_BlocksPerArc;
  // Define a section of the required number of rows
  union {
    #local CurvedPaving_I = 1;
    #while (CurvedPaving_I<=CurvedPaving_Rows)
      union {CurvedPaving_ArcOfBlocks(CurvedPaving_BlockType) translate z*CurvedPaving_BlockDepth*CurvedPaving_I} 
      #local CurvedPaving_I = CurvedPaving_I + 1;
    #end
  } 
#end


// Macro to undef the main control settings so that they revert to their defaults the
// next time the CurvedPaving macro is called.
#macro CurvedPaving_Undef() 

  #ifdef(CurvedPaving_Radius        ) #undef CurvedPaving_Radius         #end
  #ifdef(CurvedPaving_BlockDepth    ) #undef CurvedPaving_BlockDepth     #end  
  #ifdef(CurvedPaving_Rows          ) #undef CurvedPaving_Rows           #end  
  #ifdef(CurvedPaving_RandomSeed    ) #undef CurvedPaving_RandomSeed     #end                  
  #ifdef(CurvedPaving_MortarGap     ) #undef CurvedPaving_MortarGap      #end
  #ifdef(CurvedPaving_BlockThickness) #undef CurvedPaving_BlockThickness #end
  #ifdef(CurvedPaving_BlockRoundness) #undef CurvedPaving_BlockRoundness #end
  #ifdef(CurvedPaving_MinColor      ) #undef CurvedPaving_MinColor       #end
  #ifdef(CurvedPaving_MaxColor      ) #undef CurvedPaving_MaxColor       #end
  #ifdef(CurvedPaving_Contrast      ) #undef CurvedPaving_Contrast       #end
  #ifdef(CurvedPaving_Brightness    ) #undef CurvedPaving_Brightness     #end
  #ifdef(CurvedPaving_Normal        ) #undef CurvedPaving_Normal         #end
  #ifdef(CurvedPaving_Finish        ) #undef CurvedPaving_Finish         #end    

#end
                       