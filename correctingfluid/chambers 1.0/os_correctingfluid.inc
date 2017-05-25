// os_correctingfluid.inc
// ----------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This include file contains the correcting fluid object definition.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// Render times are typically about a minute (but most of that is the label).  
// 

// This switch lets you render the bottle from here.
// It should be set to 0 in normal use.
#ifndef (OS_CorrectingFluid_DesignMode) #declare OS_CorrectingFluid_DesignMode = 0; #end  

// The default bottle/cap texture is a bland white colour    
#declare OS_CorrectingFluidDefaultBottleTexture    = texture {pigment {rgb 1}}
// The stem sticking down from the cap into the inside of the bottle is a light grey
#declare OS_CorrectingFluidDefaultBrushStemTexture = texture {pigment {rgb 0.8}} 
// The brush attached to the stemp sticking down from the cap into the bottle is dark grey
#declare OS_CorrectingFluidDefaultBrushTexture     = texture {pigment {rgb 0.4}}  
// The default fluid texture is an over-illuminated white
#declare OS_CorrectingFluidDefaultTexture = texture {pigment {rgb 1.5}}
  

//**************************//
// Bottle, Cap and Label    //
//**************************//
#macro OS_CorrectingFluid ()
  union { 
    OS_CorrectingFluidBottle()
    OS_CorrectingFluidCap   () 
    OS_CorrectingFluidLabel () 
  }
#end

//**************************//
//          Bottle          //
//**************************//
#macro OS_CorrectingFluidBottle () 
  #ifndef (OS_CorrectingFluidBottleRadius   ) #declare OS_CorrectingFluidBottleRadius    = 0.015;  #end
  #ifndef (OS_CorrectingFluidBottleHeight   ) #declare OS_CorrectingFluidBottleHeight    = 0.072;  #end
  #ifndef (OS_CorrectingFluidBottleThickness) #declare OS_CorrectingFluidBottleThickness = 0.0005; #end 

  #ifndef (OS_CorrectingFluidBottleTexture  ) #declare OS_CorrectingFluidBottleTexture   = OS_CorrectingFluidDefaultBottleTexture #end
  
  #ifndef(OS_CorrectingFluidBottleShoulderHeight    ) #declare OS_CorrectingFluidBottleShoulderHeight     = OS_CorrectingFluidBottleHeight*0.046 /0.072; #end
  #ifndef(OS_CorrectingFluidBottleShoulderRoundness ) #declare OS_CorrectingFluidBottleShoulderRoundness  = OS_CorrectingFluidBottleHeight*0.001 /0.072; #end
  #ifndef(OS_CorrectingFluidBottleBaseRoundness     ) #declare OS_CorrectingFluidBottleBaseRoundness      = OS_CorrectingFluidBottleHeight*0.002 /0.072; #end
  #ifndef(OS_CorrectingFluidBottleBaseInsetRadius   ) #declare OS_CorrectingFluidBottleBaseInsetRadius    = OS_CorrectingFluidBottleHeight*0.0075/0.072; #end
  #ifndef(OS_CorrectingFluidBottleBaseInsetRoundness) #declare OS_CorrectingFluidBottleBaseInsetRoundness = OS_CorrectingFluidBottleHeight*0.001 /0.072; #end
  #ifndef(OS_CorrectingFluidBottleNeckRadius        ) #declare OS_CorrectingFluidBottleNeckRadius         = OS_CorrectingFluidBottleHeight*0.006 /0.072; #end
  #ifndef(OS_CorrectingFluidBottleNeckBase          ) #declare OS_CorrectingFluidBottleNeckBase           = OS_CorrectingFluidBottleHeight*0.047 /0.072; #end
  #ifndef(OS_CorrectingFluidBottleNeckTop           ) #declare OS_CorrectingFluidBottleNeckTop            = OS_CorrectingFluidBottleHeight*0.057 /0.072; #end
  
  #local Delta               = 0.0000001;
   
  union { 
    // The main body of the bottle
    difference {
      cylinder {<0,OS_CorrectingFluidBottleBaseRoundness          ,0><0,OS_CorrectingFluidBottleShoulderHeight-OS_CorrectingFluidBottleShoulderRoundness,0>,OS_CorrectingFluidBottleRadius}
      cylinder {<0,OS_CorrectingFluidBottleBaseRoundness+OS_CorrectingFluidBottleThickness,0><0,Delta+OS_CorrectingFluidBottleShoulderHeight-OS_CorrectingFluidBottleShoulderRoundness,0>,OS_CorrectingFluidBottleRadius-OS_CorrectingFluidBottleThickness}
    }
    // The base of the bottle
    torus {OS_CorrectingFluidBottleRadius-OS_CorrectingFluidBottleBaseRoundness,OS_CorrectingFluidBottleBaseRoundness translate OS_CorrectingFluidBottleBaseRoundness*y}
    torus {OS_CorrectingFluidBottleBaseInsetRadius,OS_CorrectingFluidBottleBaseInsetRoundness translate OS_CorrectingFluidBottleBaseInsetRoundness*y}
    cylinder {OS_CorrectingFluidBottleBaseInsetRoundness*y,2*OS_CorrectingFluidBottleBaseInsetRoundness*y,OS_CorrectingFluidBottleBaseInsetRadius} 
    // The flat bit that the bottle actually stands on
    difference {
      cylinder {0,OS_CorrectingFluidBottleBaseRoundness*y,OS_CorrectingFluidBottleRadius-OS_CorrectingFluidBottleBaseRoundness}
      cylinder {-Delta*y,(OS_CorrectingFluidBottleBaseRoundness+Delta)*y,OS_CorrectingFluidBottleBaseInsetRadius}
    }
    // The shoulder of the bottle 
    torus {OS_CorrectingFluidBottleRadius-OS_CorrectingFluidBottleShoulderRoundness,OS_CorrectingFluidBottleShoulderRoundness translate (OS_CorrectingFluidBottleShoulderHeight-OS_CorrectingFluidBottleShoulderRoundness)*y} 
    difference {
      cone {<0,OS_CorrectingFluidBottleShoulderHeight      ,0>,OS_CorrectingFluidBottleRadius-OS_CorrectingFluidBottleShoulderRoundness,<0,OS_CorrectingFluidBottleNeckBase,0>,OS_CorrectingFluidBottleNeckRadius}
      cone {<0,OS_CorrectingFluidBottleShoulderHeight-OS_CorrectingFluidBottleThickness,0>,OS_CorrectingFluidBottleRadius-OS_CorrectingFluidBottleShoulderRoundness,<0,OS_CorrectingFluidBottleNeckBase-OS_CorrectingFluidBottleThickness,0>,OS_CorrectingFluidBottleNeckRadius}
      cylinder {<0,OS_CorrectingFluidBottleNeckBase-OS_CorrectingFluidBottleThickness-Delta,0>,<0,OS_CorrectingFluidBottleNeckBase+Delta,0>,OS_CorrectingFluidBottleNeckRadius-OS_CorrectingFluidBottleThickness}
    } 
    // The neck of the bottle  
    difference {
      cylinder {<0,OS_CorrectingFluidBottleNeckBase-OS_CorrectingFluidBottleThickness,0>,<0,OS_CorrectingFluidBottleNeckTop,0>,OS_CorrectingFluidBottleNeckRadius}
      cylinder {<0,OS_CorrectingFluidBottleNeckBase-OS_CorrectingFluidBottleThickness-Delta,0>,<0,OS_CorrectingFluidBottleNeckTop+Delta,0>,OS_CorrectingFluidBottleNeckRadius-OS_CorrectingFluidBottleThickness}
    }
    texture {OS_CorrectingFluidBottleTexture}
  }
#end 

//**************************//
//       Cap and Brush      //
//**************************//
#macro OS_CorrectingFluidCap ()
  #ifndef (OS_CorrectingFluidBottleRadius   ) #declare OS_CorrectingFluidBottleRadius    = 0.015;  #end
  #ifndef (OS_CorrectingFluidBottleHeight   ) #declare OS_CorrectingFluidBottleHeight    = 0.072;  #end
  #ifndef (OS_CorrectingFluidBottleThickness) #declare OS_CorrectingFluidBottleThickness = 0.0005; #end 

  // Cap texture
  #ifndef (OS_CorrectingFluidCapTexture) 
    #ifdef(OS_CorrectingFluidBottleTexture) #declare OS_CorrectingFluidCapTexture = OS_CorrectingFluidBottleTexture
    #else                                   #declare OS_CorrectingFluidCapTexture = OS_CorrectingFluidDefaultBottleTexture
    #end
  #end 
  
  // Textures for the stem of the brush and the fibres of the brush
  #ifndef (OS_CorrectingFluidBrushStemTexture) #declare OS_CorrectingFluidBrushStemTexture = OS_CorrectingFluidDefaultBrushStemTexture #end
  #ifndef (OS_CorrectingFluidBrushTexture    ) #declare OS_CorrectingFluidBrushTexture     = OS_CorrectingFluidDefaultBrushTexture     #end

  // Texture for the little blob of correcting fluid on the end of the brush
  #ifndef (OS_CorrectingFluidTexture)
    #declare OS_CorrectingFluidTexture = OS_CorrectingFluidDefaultTexture
  #end

  #ifndef (OS_CorrectingFluidBottleNeckRadius          ) #declare OS_CorrectingFluidBottleNeckRadius           = OS_CorrectingFluidBottleHeight*0.006 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleNeckBase            ) #declare OS_CorrectingFluidBottleNeckBase             = OS_CorrectingFluidBottleHeight*0.047 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleNeckTop             ) #declare OS_CorrectingFluidBottleNeckTop              = OS_CorrectingFluidBottleHeight*0.057 /0.072; #end
  #local Delta                = 0.0000001;                                                             
                                                                                                       
  #ifndef (OS_CorrectingFluidBottleStemBase            ) #declare OS_CorrectingFluidBottleStemBase             = OS_CorrectingFluidBottleHeight*0.015 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleStemTop             ) #declare OS_CorrectingFluidBottleStemTop              = OS_CorrectingFluidBottleHeight*0.065 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleStemRadius          ) #declare OS_CorrectingFluidBottleStemRadius           = OS_CorrectingFluidBottleHeight*0.002 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleBrushLength         ) #declare OS_CorrectingFluidBottleBrushLength          = OS_CorrectingFluidBottleHeight*0.0125/0.072; #end
  #ifndef (OS_CorrectingFluidBottleBrushRadius         ) #declare OS_CorrectingFluidBottleBrushRadius          = OS_CorrectingFluidBottleHeight*0.0015/0.072; #end
  #ifndef (OS_CorrectingFluidBottleCapRadius           ) #declare OS_CorrectingFluidBottleCapRadius            = OS_CorrectingFluidBottleHeight*0.010 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleCapRecessHeight     ) #declare OS_CorrectingFluidBottleCapRecessHeight      = OS_CorrectingFluidBottleHeight*0.066 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleCapRecessLowerRadius) #declare OS_CorrectingFluidBottleCapRecessLowerRadius = OS_CorrectingFluidBottleHeight*0.006 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleCapRecessUpperRadius) #declare OS_CorrectingFluidBottleCapRecessUpperRadius = OS_CorrectingFluidBottleHeight*0.007 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleCapLipThickness     ) #declare OS_CorrectingFluidBottleCapLipThickness      = OS_CorrectingFluidBottleHeight*0.002 /0.072; #end
  #ifndef (OS_CorrectingFluidBottleCapDentRadius       ) #declare OS_CorrectingFluidBottleCapDentRadius        = OS_CorrectingFluidBottleHeight*0.02  /0.072; #end
  #ifndef (OS_CorrectingFluidBottleFibreCount          ) #declare OS_CorrectingFluidBottleFibreCount           = 36;                                          #end
  #ifndef (OS_CorrectingFluidBottleFibreSeed           ) #declare OS_CorrectingFluidBottleFibreSeed            = seed(1);                                     #end

  #local OS_CorrectingFluidBottleCapDentDepth = OS_CorrectingFluidBottleHeight-OS_CorrectingFluidBottleNeckBase-OS_CorrectingFluidBottleCapLipThickness;
  #local OS_CorrectingFluidBottleFibreRadius  = OS_CorrectingFluidBottleBrushRadius/sqrt(OS_CorrectingFluidBottleFibreCount);

  union { 
    // The stem of the brush
    difference {
      cylinder {<0,OS_CorrectingFluidBottleStemBase,0><0,OS_CorrectingFluidBottleStemTop,0>,OS_CorrectingFluidBottleStemRadius}
      cylinder {<0,OS_CorrectingFluidBottleStemBase-Delta,0><0,OS_CorrectingFluidBottleStemBase+OS_CorrectingFluidBottleBrushLength,0>,OS_CorrectingFluidBottleBrushRadius}
      texture {OS_CorrectingFluidBrushStemTexture}
    }
    // The brush fibres 
    #local BrushI = 0;
    #while (BrushI<OS_CorrectingFluidBottleFibreCount)
      #local RandomNumber = rand(OS_CorrectingFluidBottleFibreSeed);
      cylinder {-OS_CorrectingFluidBottleBrushLength*y,OS_CorrectingFluidBottleBrushLength*y,OS_CorrectingFluidBottleFibreRadius
        rotate -2*x*RandomNumber
        translate RandomNumber*OS_CorrectingFluidBottleBrushRadius*z
        rotate y*360*rand(OS_CorrectingFluidBottleFibreSeed) 
        translate y*OS_CorrectingFluidBottleStemBase
        texture {OS_CorrectingFluidBrushTexture}
      }
      #local BrushI = BrushI + 1;
    #end
    // Blob of correcting fluid
    blob {
      threshold 0.6
      sphere { <0                                      , OS_CorrectingFluidBottleStemBase-0.5 *OS_CorrectingFluidBottleBrushLength, 0>, OS_CorrectingFluidBottleStemRadius,     0.5 }
      sphere { <0                                      , OS_CorrectingFluidBottleStemBase-0.6 *OS_CorrectingFluidBottleBrushLength, 0>, OS_CorrectingFluidBottleStemRadius*2,   0.3 }
      sphere { <-OS_CorrectingFluidBottleBrushLength/15, OS_CorrectingFluidBottleStemBase-0.8*OS_CorrectingFluidBottleBrushLength, 0>, OS_CorrectingFluidBottleStemRadius*5,    0.6 scale <1,8,1>}
      sphere { <0                                      , OS_CorrectingFluidBottleStemBase-0.9 *OS_CorrectingFluidBottleBrushLength, 0>, OS_CorrectingFluidBottleStemRadius*2.6, 0.49}
      texture {OS_CorrectingFluidTexture}
    }
    // The main body of the cap  
    difference {
      cylinder {<0,OS_CorrectingFluidBottleNeckBase      ,0>,<0,OS_CorrectingFluidBottleHeight,0>,OS_CorrectingFluidBottleCapRadius}
      cylinder {<0,OS_CorrectingFluidBottleNeckBase-Delta,0>,<0,OS_CorrectingFluidBottleCapRecessHeight-OS_CorrectingFluidBottleThickness,0>,OS_CorrectingFluidBottleNeckRadius}
      difference {
        cone {y*(OS_CorrectingFluidBottleHeight+Delta),OS_CorrectingFluidBottleCapRecessUpperRadius,y*OS_CorrectingFluidBottleCapRecessHeight,OS_CorrectingFluidBottleCapRecessLowerRadius} 
        // Add two little dimples into the recess
        cone {y*(OS_CorrectingFluidBottleCapRecessHeight-Delta),0.0025,y*(OS_CorrectingFluidBottleCapRecessHeight+0.0003),0.0015}
        cone {y*(OS_CorrectingFluidBottleCapRecessHeight-Delta),0.0005,y*(OS_CorrectingFluidBottleCapRecessHeight+0.0008),0}
      }
      // Cut channels out around the outside of the cap to provide grip
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness>}
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness> rotate y*45}
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness> rotate y*45*2}
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness> rotate y*45*3}
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness> rotate y*45*4}
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness> rotate y*45*5}
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness> rotate y*45*6}
      cylinder {<0,-OS_CorrectingFluidBottleCapDentDepth,OS_CorrectingFluidBottleCapDentRadius>,<0,0,OS_CorrectingFluidBottleCapDentRadius>,OS_CorrectingFluidBottleCapDentRadius rotate -x*3 translate <0,OS_CorrectingFluidBottleHeight,OS_CorrectingFluidBottleCapRecessUpperRadius+OS_CorrectingFluidBottleThickness> rotate y*45*7}
      texture {OS_CorrectingFluidCapTexture}
    }
  }
#end


//**************************//
//          Label           //
//**************************// 
#macro OS_CorrectingFluidLabel ()
  #ifndef (OS_CorrectingFluidBottleRadius     ) #declare OS_CorrectingFluidBottleRadius      = 0.015;  #end

  #ifndef (OS_CorrectingFluidLabelRounding    ) #declare OS_CorrectingFluidLabelRounding     = 0.002;  #end
  #ifndef (OS_CorrectingFluidLabelThickness   ) #declare OS_CorrectingFluidLabelThickness    = 0.0001; #end
  #ifndef (OS_CorrectingFluidLabelGap         ) #declare OS_CorrectingFluidLabelGap          = 0.002;  #end
  #ifndef (OS_CorrectingFluidLabelBottom      ) #declare OS_CorrectingFluidLabelBottom       = 0.004;  #end
  #ifndef (OS_CorrectingFluidLabelTop         ) #declare OS_CorrectingFluidLabelTop          = 0.042;  #end
  
  #local OS_CorrectingFluidLabelCircumference = 2*3.1415926535*OS_CorrectingFluidBottleRadius;                      
  #local OS_CorrectingFluidLabelWidth         = OS_CorrectingFluidLabelCircumference-OS_CorrectingFluidLabelGap;    
  #local OS_CorrectingFluidLabelGapAngle      = 360*OS_CorrectingFluidLabelGap/OS_CorrectingFluidLabelCircumference;
  #local OS_CorrectingFluidLabelHeight        = OS_CorrectingFluidLabelTop - OS_CorrectingFluidLabelBottom;         
  #ifndef (OS_CorrectingFluid_LabelDesignMode) #declare OS_CorrectingFluid_LabelDesignMode = 0; #end  
  #ifndef (OS_CorrectingFluid_LabelFile)       #declare OS_CorrectingFluid_LabelFile = "os_correctingfluidlabel.inc"; #end

  #local Delta                = 0.0000001;

  // The graphical design of the label (the pigment) is held in an external file to make it easier to change.
  #if (file_exists(OS_CorrectingFluid_LabelFile)) #include OS_CorrectingFluid_LabelFile
  #else #include "os_correctingfluidlabel.inc" 
  #end
  
  // Create a cutter to round off the corners of the label to the required radius
  #local Cutter = difference {  
    box      {-(OS_CorrectingFluidLabelThickness+OS_CorrectingFluidBottleRadius/3  )*z,<OS_CorrectingFluidLabelRounding+Delta,OS_CorrectingFluidLabelRounding+Delta,OS_CorrectingFluidLabelThickness+Delta>}
    cylinder {-(OS_CorrectingFluidLabelThickness+OS_CorrectingFluidBottleRadius/2.9)*z,(OS_CorrectingFluidLabelThickness+2*Delta)*z,OS_CorrectingFluidLabelRounding} 
    translate -<OS_CorrectingFluidLabelRounding,OS_CorrectingFluidLabelRounding,0>
  }
  
  
  // Create the label object using CSG and apply the layers of pigment as defined in the external file.
  difference { 
    cylinder { OS_CorrectingFluidLabelBottom*y       , OS_CorrectingFluidLabelTop*y       ,OS_CorrectingFluidBottleRadius+OS_CorrectingFluidLabelThickness}
    cylinder {(OS_CorrectingFluidLabelBottom-Delta)*y,(OS_CorrectingFluidLabelTop+Delta)*y,OS_CorrectingFluidBottleRadius+Delta} 
    box {<-OS_CorrectingFluidLabelGap/2,OS_CorrectingFluidLabelBottom-Delta,OS_CorrectingFluidBottleRadius-OS_CorrectingFluidBottleRadius/5> <OS_CorrectingFluidLabelGap/2,OS_CorrectingFluidLabelTop + Delta,OS_CorrectingFluidBottleRadius+OS_CorrectingFluidLabelThickness+Delta>}
    object {Cutter              translate <-OS_CorrectingFluidLabelGap/2,OS_CorrectingFluidLabelTop   ,OS_CorrectingFluidBottleRadius>}
    object {Cutter rotate z*90  translate < OS_CorrectingFluidLabelGap/2,OS_CorrectingFluidLabelTop   ,OS_CorrectingFluidBottleRadius>}
    object {Cutter rotate z*180 translate < OS_CorrectingFluidLabelGap/2,OS_CorrectingFluidLabelBottom,OS_CorrectingFluidBottleRadius>}
    object {Cutter rotate z*270 translate <-OS_CorrectingFluidLabelGap/2,OS_CorrectingFluidLabelBottom,OS_CorrectingFluidBottleRadius>}
    // Add layers of pigment and use a cylindrical warp to wrap them around the surface
    #local LayerI = 0; 
    #while (LayerI<dimension_size(OS_CorrectingFluidLabelLayer,1))   
      #ifdef (OS_CorrectingFluidLabelLayer[LayerI])
        texture {
          pigment {
            OS_CorrectingFluidLabelLayer[LayerI]  
            scale <1/OS_CorrectingFluidLabelWidth,1,1>
            warp {
              cylindrical 
              orientation y 
            }
            rotate -y*(90+OS_CorrectingFluidLabelGapAngle/2)
            translate y*OS_CorrectingFluidLabelBottom
          } 
        } 
      #end
      #local LayerI = LayerI + 1;
    #end
  }
#end
     

// You can temporarily set OS_CorrectingFluid_DesignMode to enable you to render this file directly.
// This is intended for maintenance purposes only. Don't forget to set it back afterwards. 
#if (OS_CorrectingFluid_DesignMode)     
  light_source { <-4,145,-50>, rgb 1}
  camera {location <-0.1,0.05,-0.05> look_at <0,0.04,0>}
  
  
  object {OS_CorrectingFluidBottle()}   
  object {OS_CorrectingFluidCap()}
  object {OS_CorrectingFluidLabel()} 
#end                                        
                                        

