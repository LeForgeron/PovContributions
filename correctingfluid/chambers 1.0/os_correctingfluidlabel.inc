// os_correctingfluidlabel.inc
// ---------------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This include file defines the layers of pigment required to build up the label.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// 
// You can render this file, which will display a flattened version of the label.
// Render times are typically half a minute to a couple of minutes depending on size.  
//


// This switch lets you render the label onto a flat surface before applying it to a bottle.
#ifndef (OS_CorrectingFluid_LabelDesignMode) #declare OS_CorrectingFluid_LabelDesignMode = 1;     #end
#ifndef (OS_CorrectingFluidBottleRadius)     #declare OS_CorrectingFluidBottleRadius     = 0.015; #end

//**************************//
//     Label Texts          //
//**************************//
#local LabelText1 = array[18] {
  "3D Model of a bottle",
  "of correction fluid.",
  "Contains absolutely",
  "nothing real.", 
  "Oh! and by the way;",
  "This is the small print",
  "on a bottle of imaginary",
  "correcting fluid, so why",
  "the blazes are you",
  "reading this. I've got",
  "an excuse, I needed to",
  "write something, but ",
  "there's a whole world",
  "of things out there you",
  "could be doing rather than",
  "reading this.",
  "Stir well before use.",
  "Close tightly after use."
}  

#local LabelText2 = array[16] {
  "Instructions for use -",
  "1. Add model to a",
  "POV-Ray scene file.",
  "2. Run POV-Ray to",
  "generate your image.",
  "3. Sit back and admire",
  "the sophisticated and",
  "elegant correction",
  "fluid bottle that",
  "appears like magic",
  "before your eyes as",
  "you watch POV-Ray in",
  "action.",
  " ",
  " ",
  "Made in Great Britain"
}

#local LabelText3 = "20ml";

#local LabelText5 = "3.1415926535";


//**************************//
//   Label Size Settings    //
//**************************//

#ifndef (OS_CorrectingFluidLabelRounding ) #declare OS_CorrectingFluidLabelRounding  = 0.002;  #end
#ifndef (OS_CorrectingFluidLabelThickness) #declare OS_CorrectingFluidLabelThickness = 0.0001; #end
#ifndef (OS_CorrectingFluidLabelGap      ) #declare OS_CorrectingFluidLabelGap       = 0.002;  #end
#ifndef (OS_CorrectingFluidLabelBottom   ) #declare OS_CorrectingFluidLabelBottom    = 0.004;  #end
#ifndef (OS_CorrectingFluidLabelTop      ) #declare OS_CorrectingFluidLabelTop       = 0.042;  #end

#local OS_CorrectingFluidLabelCircumference = 2*3.1415926535*OS_CorrectingFluidBottleRadius;                      
#local OS_CorrectingFluidLabelWidth         = OS_CorrectingFluidLabelCircumference-OS_CorrectingFluidLabelGap;    
#local OS_CorrectingFluidLabelGapAngle      = 360*OS_CorrectingFluidLabelGap/OS_CorrectingFluidLabelCircumference;
#local OS_CorrectingFluidLabelHeight        = OS_CorrectingFluidLabelTop - OS_CorrectingFluidLabelBottom;         


//**************************//
//   Layers of pigment      //
//**************************//
#declare OS_CorrectingFluidLabelLayer = array[30];

// The label background 
#declare OS_CorrectingFluidLabelLayer[0] = pigment {rgb 1.2}

// The first block of small print
#declare OS_CorrectingFluidLabelLayer[1] = pigment {
  object {
    union { 
      #local LineI = 0;
      #while (LineI<dimension_size(LabelText1,1))
        text {
          ttf "arial.ttf" LabelText1[LineI] 1, 0 
          translate -y*LineI
          rotate x*90
        }
        #local LineI = LineI + 1;
      #end 
      translate y*0.1 
      scale <0.0014,1,0.0014>
      translate <0.055,0,0.03>   
    }
    color <1,1,1,1>
    color 0
  } 
}  

// The second block of small print
#declare OS_CorrectingFluidLabelLayer[2] = pigment {
  object {
    union { 
      #local LineI = 0;
      #while (LineI<dimension_size(LabelText2,1))
        text {
          ttf "arial.ttf" LabelText2[LineI] 1, 0 
          translate -y*LineI
          rotate x*90
        }
        #local LineI = LineI + 1;
      #end 
      translate y*0.1 
      scale <0.0014,1,0.0014>
      translate <0.075,0,0.03>   
    }
    color <1,1,1,1>
    color 0
  } 
}

// The 20ml text below the second block of small print
#declare OS_CorrectingFluidLabelLayer[3] = pigment {
  object {
    text {
      ttf "arial.ttf" LabelText3 1, 0 
      rotate x*90
      translate y*0.1 
      scale <0.003,1,0.003>
      translate <0.082,0,0.006>   
    }
    color <1,1,1,1>
    color 0
  } 
}

// The coloured blocks above and below the blocks of small print
#declare OS_CorrectingFluidLabelLayer[4] = pigment {
  object { 
    union {
      box {<0.055,-1,0.002>,<0.09,0,0.005>}
      box {<0.055,-1,0.033>,<0.09,0,0.036>}
    }
    color <1,1,1,1>
    color <0,1,1>
  } 
}

// The background to the main panel
#declare OS_CorrectingFluidLabelLayer[11] = pigment {
  object { 
    box {<0.024,-1,0.002>,<0.051,0,0.036>}
    color <1,1,1,1>
    color <0,0,0.2>
  } 
}

// The words 'POV-Ray' and 'Correcting Fluid' on the main panel
#declare OS_CorrectingFluidLabelLayer[12] = pigment {
  object {
    union {
      text {
        ttf "arial.ttf" "POV-Ray" 1, 0 
        rotate x*90
        translate y*0.1
        scale <0.004,1,0.004>
        translate <0.029,0,0.030>   
      }
      text {
        ttf "arial.ttf" "Correcting Fluid" 1, 0.19*x 
        rotate x*90
        translate y*0.1
        scale <0.0022,1,0.0022>
        translate <0.027,0,0.026>   
      } 
    }
    color <1,1,1,1>
    color <1,1,0>
  } 
} 

// The bitmapped image on the main panel 
#declare OS_CorrectingFluidLabelLayer[13] = pigment { 
  image_map {jpeg "os_correctingfluid.jpg" once} 
  scale 0.02
  rotate x*90 
  translate <0.028,0,0.004>
}

// The default label texture incorporates the POV-Ray logo
#ifndef(Povray_Logo_Prism) #include "logo.inc" #end     


// The POV-Ray logo
#declare OS_CorrectingFluidLabelLayer[14] = pigment {
  object {
    Povray_Logo_Prism
    translate <1,0.5,0.1>
    scale <0.006,0.006,8>
    rotate x*90
    translate <0.023,0,0.012>
    color <1,1,1,1>
    color <0,0.2,0.2>
  } 
} 


// The bar code
#declare OS_CorrectingFluidLabelLayer[21] = pigment {
  object {
    union {    
      #local BarCodeSeed = seed(1);
      #local LabelBarStart = 0;
      #while (LabelBarStart<0.026)
        #local LabelBarThickness = 0.0009*rand(BarCodeSeed); 
        box {<0.006,-1,0.005+LabelBarStart>,<0.017,0,0.005+LabelBarStart+LabelBarThickness>}
        #local LabelBarStart = LabelBarStart + LabelBarThickness + 0.0009*rand(BarCodeSeed);
      #end
      text {
        ttf "arial.ttf" "3.1415926535" 1, 0.2*x 
        rotate <90,-90,0>
        translate y*0.1
        scale <0.003,1,0.003>
        translate <0.021,0,0.005>   
      }
    }
    color <1,1,1,1>
    color 0
  } 
}


// OS_CorrectingFluid_LabelDesignMode enables you to render this file directly, which shows a flattened version of the
// label design. By default it is set to 1 at the top of this file and to 0 by os_correctingfluid.inc, so that these 
// settings don't interfere with the use of the macros from a scene file.
#if (OS_CorrectingFluid_LabelDesignMode)     
  light_source { <-20,65,30>, rgb 2}
  camera {location <OS_CorrectingFluidLabelWidth/2,0.075,OS_CorrectingFluidLabelHeight/2.2> look_at <OS_CorrectingFluidLabelWidth/2,0,OS_CorrectingFluidLabelHeight/2>} 
  
  #ifdef(OS_CorrectingFluidLabelLayer[0]) box {-0.0002*y,<OS_CorrectingFluidLabelWidth,-0.0001,OS_CorrectingFluidLabelHeight> pigment {OS_CorrectingFluidLabelLayer[0]}}  #end
  
  plane {y,0 
    #local LayerI = 1; 
    #while (LayerI<dimension_size(OS_CorrectingFluidLabelLayer,1))   
      #ifdef (OS_CorrectingFluidLabelLayer[LayerI])
        texture {pigment {OS_CorrectingFluidLabelLayer[LayerI]}} 
      #end
      #local LayerI = LayerI + 1;
    #end
  }
#end



