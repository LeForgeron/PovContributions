//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// Updated March 2008 for the POV-Ray Object Collection

/**********************************************************************************/
/* staircase_documentimages.pov  -  Created by Chris Bartlett April 2006          */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Version:     Written using POV-Ray 3.5 and tested on 3.6                       */
/**********************************************************************************/

// Purpose
// -------
// This scene file is used to re-generate the images used within the documentation contained in staircase.html. 
//
// To generate all images use the animation command line options +kfi1 +kff63 which sets ImageNumber to equal the frame_number.
// You can use +fn to generate png files directly. The png files used in the documentation are mostly 640x480, AA 0.3.
// To generate a single image switch off animation and it will use ImageNumber = n, where 'n' is the number of the image you 
// specify here:
#if (frame_number=0) #local ImageNumber = 99;  // Set this to the required image number
#else                #local ImageNumber = frame_number;
#end 

#version 3.5;

#local SimpleLight = light_source { <3, 14,-10> color rgb 1.35 }

// An area light
#local AreaLight = light_source {0 color rgb 1.2
  area_light            
  <8, 0, 0> <0, 0, 8>   // lights spread out across this distance (x * z)
  4, 4                  // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0            // 0,1,2,3...
  jitter                // adds random softening of light
  circular              // make the shape of the light circular
  orient                // orient light
  translate <60, 80,-70>  // <x y z> position of light
}

// An area light
#local AreaLight2 = light_source {0 color rgb 1.2
  area_light            
  <8, 0, 0> <0, 0, 8>   // lights spread out across this distance (x * z)
  4, 4                  // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0            // 0,1,2,3...
  jitter                // adds random softening of light
  circular              // make the shape of the light circular
  orient                // orient light
  translate <20, 90,-20>  // <x y z> position of light
}

#local Image = ""; 

#if (ImageNumber = 1) 
  #local Image = "Example1";
  camera {location <4,2,-2> look_at  <0,1.75,2>}
  light_source {AreaLight}

  #include "staircase.inc"
  #declare StairCase_PostPositions = array [3] {<0,0,0>,<0,2,2.5>,<-2.5,4,2.5>};
  StairCase()
#end 
 
#if (ImageNumber = 2) 
  #local Image = "Example2";
  camera {location <5,3,-4> look_at  <0,2,3.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_PostPositions = array [2] {<0,0,0>,<0,2,2.5>};
  StairCase()
  #declare StairCase_PostPositions = array [2] {<0,2,2.5>,<-2.5,4,2.5>};
  StairCase()
  #declare StairCase_PostPositions = array [2] {<1,2,3.5>,< 3.5,4,3.5>};
  StairCase() 
#end  

#if (ImageNumber = 3) 
  #local Image = "StairCase_DefaultNewelTexture";
  camera {location <1.45,0.5,-0.1> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 4) 
  #local Image = "StairCase_NewelTexture";
  camera {location <1.45,0.5,-0.1> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_NewelTexture = texture {pigment {color rgb <1,0,0>}};
  StairCase()
#end  

#if (ImageNumber = 5) 
  #local Image = "StairCase_DefaultBalusterTexture";
  camera {location <1.45,0.75,0.22> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 6) 
  #local Image = "StairCase_BalusterTexture";
  camera {location <1.45,0.75,0.22> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_BalusterTexture = texture {pigment {color rgb <0,1,0>}};
  StairCase()
#end 
 
#if (ImageNumber = 7) 
  #local Image = "StairCase_DefaultStringerTexture";
  camera {location <1.45,-0.1,0.4> look_at  <0,1.2,1.2>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 8) 
  #local Image = "StairCase_StringerTexture";
  camera {location <1.45,-0.1,0.4> look_at  <0,1.2,1.2>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #include "textures.inc"  
  #declare StairCase_StringerTexture = texture {Cherry_Wood translate <-1,-1,0> translate -y scale <0.1,0.015,0.1>}
  StairCase()
#end   

#if (ImageNumber = 9) 
  #local Image = "StairCase_DefaultRailTexture";
  camera {location <1.35,1.4,0.5> look_at  <0,1.2,0.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 10) 
  #local Image = "StairCase_RailTexture";
  camera {location <1.35,1.4,0.5> look_at  <0,1.2,0.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_RailTexture = texture {pigment {color rgb <1,0,1>}};
  StairCase()
#end  

#if (ImageNumber = 11) 
  #local Image = "StairCase_DefaultTreadTexture";
  camera {location <0.95,1.5,1.9> look_at  <0.1,0,1>}
  light_source {AreaLight2} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetOn=0;
  StairCase()
#end  

//  #declare StairCase_TreadTexture = texture {Sandalwood rotate y*90 scale <0.1,0.1,0.005>}
//  #declare StairCase_TreadTexture = texture {DMFWood6 translate -y rotate y*90 scale <0.1,0.1,0.04>}
//  #declare StairCase_TreadTexture = texture {White_Wood rotate y*90 translate -y*1 scale <0.1,0.1,0.015>}
//  #declare StairCase_TreadTexture = texture {Pine_Wood rotate y*90 translate -y*1 scale <0.01,0.01,0.0025>}
//  #declare StairCase_TreadTexture = texture {Red_Marble rotate y*90 scale <0.08,0.08,0.01>}
//  #declare StairCase_TreadTexture = texture {pigment {color rgb <1,1,1>}};

#if (ImageNumber = 12) 
  #local Image = "StairCase_TreadTexture";
  camera {location <0.95,1.5,1.9> look_at  <0.1,0,1>}
  light_source {AreaLight2} 

  #include "staircase.inc"
  #include "textures.inc"  

  #declare StairCase_TreadTexture = texture {Cherry_Wood translate <-1,-1,0> rotate y*90 translate -y scale <0.1,0.1,0.008>}
  #declare StairCase_StairCarpetOn=0;
  StairCase()
#end  

#if (ImageNumber = 13) 
  #local Image = "StairCase_DefaultRiserTexture";
  camera {location <0.5,0.3,0> look_at  <0.5,0.5,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetOn=0;
  StairCase()
#end  

#if (ImageNumber = 14) 
  #local Image = "StairCase_RiserTexture";
  camera {location <0.5,0.3,0> look_at  <0.5,0.5,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #include "textures.inc"  
  #declare StairCase_RiserTexture = texture {Sandalwood scale <0.1,0.005,0.1>}
  #declare StairCase_StairCarpetOn=0;
  StairCase()
#end  

#if (ImageNumber = 15) 
  #local Image = "StairCase_DefaultStairCarpetTexture";
  camera {location <0.85,0.75,0> look_at  <0.35,0.5,1>}
  light_source {SimpleLight} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetWidth = 0.75;
  StairCase()
#end  

#if (ImageNumber = 16) 
  #local Image = "StairCase_StairCarpetTexture";
  camera {location <0.85,0.75,0> look_at  <0.35,0.5,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetTexture = texture {pigment {color rgb <1,1,1>}};
  #declare StairCase_StairCarpetWidth = 0.75;
  StairCase()
#end  

#if (ImageNumber = 17) 
  #local Image = "StairCase_DefaultStairCarpetColour";
  camera {location <0.85,0.75,0> look_at  <0.35,0.5,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 18) 
  #local Image = "StairCase_StairCarpetColour";
  camera {location <0.85,0.75,0> look_at  <0.35,0.5,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetColour = <0,1,0>;
  StairCase()
#end  
//  *********** ERROR *********** paired Bannister rails don't appear properly

#if (ImageNumber = 19) 
  #local Image = "StairCase_StairsOn";
  camera {location <5,5,1> look_at  <-0.5,2,1.2>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #background {1}
  #declare StairCase_StairsOn = 0;
  StairCase()
#end  

// *****************
#if (ImageNumber = 20) 
  #local Image = "StairCase_LandingsOn";
  camera {location <2,6,2.5> look_at  <-0.5,2,2.5>}
  light_source {AreaLight2} 

  #include "staircase.inc"
  #declare StairCase_LandingsOn = 0;
  StairCase()
#end  

#if (ImageNumber = 21) 
  #local Image = "StairCase_StairCarpetOn";
  camera {location <0.85,0.75,0> look_at  <0.35,0.5,1>}
  light_source {AreaLight2} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetOn = 0;
  StairCase()
#end  

#if (ImageNumber = 22) 
  #local Image = "StairCase_MainBanisterOn";
  camera {location <4,5,-3> look_at  <-2,1.5,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_MainBanisterOn = 0;
  StairCase()
#end  

#if (ImageNumber = 23) 
  #local Image = "StairCase_PairedBanisterOn";
  camera {location <4,5,-3> look_at  <-2,1.5,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_PairedBanisterOn = 0;
  StairCase()
#end  

#if (ImageNumber = 24) 
  #local Image = "StairCase_MaxBalusterSpacing";
  camera {location <2,1.65,0.4> look_at  <0,1.6,1.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_MaxBalusterSpacing = 0.08;
  StairCase()
#end  

#if (ImageNumber = 25) 
  #local Image = "StairCase_MaxBalusterSpacing2";
  camera {location <2,1.65,0.4> look_at  <0,1.6,1.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_MaxBalusterSpacing = 0.25;
  StairCase()
#end  

#if (ImageNumber = 26) 
  #local Image = "StairCase_MaxRiserHeight";
  camera {location <1.5,0.45,-0.5> look_at  <0,0.75,1>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_MaxRiserHeight = 0.10;
  StairCase()
#end  

#if (ImageNumber = 27) 
  #local Image = "StairCase_RiserCoverage";
  camera {location <1.5,0.45,-0.5> look_at  <0,0.75,1>}
  light_source {AreaLight}
  background {rgb <1,1,1>} 

  #include "staircase.inc"
  #declare StairCase_RiserCoverage = 0.5;
  #declare StairCase_StairCarpetOn = 0;
  StairCase()
#end  

#if (ImageNumber = 28) 
  #local Image = "StairCase_StairWidth";
  camera {location <3,3,-4> look_at  <1.4,1,3.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_StairWidth = 4;
  StairCase()
#end  

#if (ImageNumber = 29) 
  #local Image = "StairCase_StairHandedness";
  camera {location <-2,3,-2> look_at  <1,1,1.5>}
  light_source {AreaLight translate -100*x} 

  #include "staircase.inc"
  #declare StairCase_StairHandedness = -1;
  #declare StairCase_PostPositions = array [3] {<1,0,0>,<1,1,1.25>,<2.25,2,1.25>};
  StairCase()
#end  

#if (ImageNumber = 30) 
  #local Image = "StairCase_LandingThreshold";
  camera {location <0.75,4,1> look_at  <0.75,2,1.5>}
  light_source {AreaLight2} 

  #include "staircase.inc"
  #declare StairCase_LandingThreshold = 30;
  #declare StairCase_PostPositions = array [3] {<0,0,0>,<0,1,1.25>,<-0.75,2,2.5>};
  StairCase()
#end  

#if (ImageNumber = 31) 
  #local Image = "StairCase_LandingThreshold2";
  camera {location <0.75,4,1> look_at  <0.75,2,1.5>}
  light_source {AreaLight2} 

  #include "staircase.inc"
  #declare StairCase_LandingThreshold = 40;
  #declare StairCase_PostPositions = array [3] {<0,0,0>,<0,1,1.25>,<-0.75,2,2.5>};
  StairCase()
#end  

#if (ImageNumber = 32) 
  #local Image = "StairCase_StairCarpetWidth";
  camera {location <0.9,1,-0.5> look_at  <0,0.5,1.5>}
  light_source {SimpleLight} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetWidth = 0.5;
  StairCase()
#end  

#if (ImageNumber = 33) 
  #local Image = "StairCase_DefaultStringer";
  camera {location <1.45,0.4,0.4> look_at  <0,1.2,1.2>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 34) 
  #local Image = "StairCase_Stringer";
  camera {location <1.45,0.4,0.4> look_at  <0,1.2,1.2>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_Stringer = box {<-0.03,-0.14,-0.08><0.03,0.12,1.08>};
  StairCase()
#end  

#if (ImageNumber = 35) 
  #local Image = "StairCase_DefaultTread";
  camera {location <0.9,0.6,0.5> look_at  <0.5,0.55,0.8>}
  light_source {AreaLight2 translate -z*40} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetOn = 0;
  StairCase()
#end  

#if (ImageNumber = 36) 
  #local Image = "StairCase_Tread";
  camera {location <0.9,0.6,0.5> look_at  <0.5,0.55,0.8>}
  light_source {AreaLight2 translate -z*40} 

  #include "staircase.inc"
  #declare StairCase_Tread = box {<-0.5,-0.042,-1><0.5,0,0.15>};
  #declare StairCase_StairCarpetOn = 0;
  StairCase()
#end  

#if (ImageNumber = 37) 
  #local Image = "StairCase_DefaultRiser";
  camera {location <0.9,0.6,0.5> look_at  <0.5,0.55,0.8>}
  light_source {AreaLight2 translate -z*40} 

  #include "staircase.inc"
  #declare StairCase_StairCarpetOn = 0;
  StairCase()
#end  

#if (ImageNumber = 38) 
  #local Image = "StairCase_Riser";
  camera {location <0.9,0.6,0.5> look_at  <0.5,0.55,0.8>}
  light_source {AreaLight2 translate -z*40} 

  #include "staircase.inc"
  #declare StairCase_Riser = difference {
    box {<-0.5,-1,0.120><0.5,-0.001,0.128>} 
    box {<-0.05,-0.05,0.119><0.05,0.05,0.129> rotate z*45 scale 2*y translate <-0.25,-0.55,0>}
    box {<-0.05,-0.05,0.119><0.05,0.05,0.129> rotate z*45 scale 2*y translate < 0   ,-0.55,0>}
    box {<-0.05,-0.05,0.119><0.05,0.05,0.129> rotate z*45 scale 2*y translate < 0.25,-0.55,0>}
  }
  #declare StairCase_StairCarpetOn = 0;
  StairCase()
#end  

#if (ImageNumber = 39) 
  #local Image = "StairCase_DefaultStairCarpet";
  camera {location <0.8,0.8,0.5> look_at  <0.5,0.55,0.8>}
  light_source {AreaLight2 translate -z*40} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 40) 
  #local Image = "StairCase_StairCarpet";
  camera {location <0.8,0.8,0.5> look_at  <0.5,0.55,0.8>}
  light_source {AreaLight2 translate -z*40} 

  #include "staircase.inc"
  #declare StairCase_StairCarpet = box {<-0.4,0,-0.1><0.4,0.001,0.10>};
  StairCase()
#end  

#if (ImageNumber = 41) 
  #local Image = "StairCase_DefaultHandRail";
  camera {location <1.35,1.4,0.5> look_at  <0,1.2,0.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 42) 
  #local Image = "StairCase_HandRail";
  camera {location <1.35,1.4,0.5> look_at  <0,1.2,0.5>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_HandRail = cylinder {<0,0.015,0><0,0.015,1>,0.03 clipped_by {plane {-y,0}} scale y*0.6 };
  StairCase()
#end  

#if (ImageNumber = 43) 
  #local Image = "StairCase_DefaultBaluster";
  camera {location <1.45,0.75,0.22> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 44) 
  #local Image = "StairCase_Baluster";
  camera {location <1.45,0.75,0.22> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_Baluster = box {<-0.015,-0.03,-0.015><0.015,1,0.015>};
  StairCase()
#end  

#if (ImageNumber = 45) 
  #local Image = "StairCase_DefaultNewelPost";
  camera {location <1.45,1.2,-0.1> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  StairCase()
#end  

#if (ImageNumber = 46) 
  #local Image = "StairCase_NewelPost";
  camera {location <1.35,1.1,-0.15> look_at  <0,0.5,0>}
  light_source {AreaLight} 

  #include "staircase.inc"
  #declare StairCase_NewelPost = intersection {
    box {<-0.042,-1,-0.042><0.042,1.02,0.042>}
    plane {<0,1,1>,0 translate 1.05*y}
    plane {<0,1,1>,0 translate 1.05*y rotate  90*y}
    plane {<0,1,1>,0 translate 1.05*y rotate 180*y}
    plane {<0,1,1>,0 translate 1.05*y rotate 270*y}
  }
  StairCase()
#end 

#if (ImageNumber = 47) 
  #local Image = "Example3";
  light_source {AreaLight2 translate -z*20} 
  camera {location <-6,5.2,2> look_at  <0,0,1.2>}
  #include "staircase.inc"
  
  #declare StairCase_StairsOn = 1;
  #declare StairCase_StairWidth = 1.5;
  #declare StairCase_StairCarpetWidth = 1.2;
  #declare StairCase_PostPositions = array [6] {<0,2,0>,<0,1,3>,<-1,1,3>,<-2,0,2>,<-2,0,1>,<-2,-1,-2>};
  StairCase()
#end  

#if (ImageNumber = 48) 
  #local Image = "Example4";
  light_source {AreaLight2} 
  camera {location <0,3,-5> look_at  <0,0,0>}
  #include "staircase.inc"

  #declare StairCase_PostPositions = array [6] {<-3,0,0>,<-2,0,0>,<-1,-1,0>,<1,-1,0>,<2,0,0>,<3,0,0>};
  StairCase()
#end  

#if (ImageNumber = 49) 
  #local Image = "Example5";
  light_source {AreaLight2} 
  camera {location <0,3,-5> look_at  <0,0,0>}
  #include "staircase.inc"
  #declare StairCase_PairedBanisterOn = 0;
  #declare StairCase_PostPositions = array [6] {<-3,0,0>,<-2,0,0>,<-1,-1,0>,<1,-1,0>,<2,0,0>,<3,0,0>};
  StairCase()
  
  #declare StairCase_PairedBanisterOn = 1;
  #declare StairCase_MainBanisterOn = 0;
  #declare StairCase_StairsOn = 0;
  #declare StairCase_PostPositions = array [3] {<-3,0,0>,<-2,0,0>,<-1,-1,0>};
  StairCase()
  
  #declare StairCase_PostPositions = array [3] {<1,-1,0>,<2,0,0>,<3,0,0>};
  StairCase()
  
  #declare StairCase_MainBanisterOn = 1;
  #declare StairCase_StairsOn = 1;
  #declare StairCase_StairWidth=2;
  #declare StairCase_PostPositions = array [2] {<-1,-1.5,-1.65>,<-1,-1,-1>};
  StairCase()
#end 
 
#if (ImageNumber = 50) 
  #local Image = "Banner Image";
//  camera {location <5,3,-4> look_at  <0,2,3.5>}
  light_source {AreaLight translate <-10,-20,40>} 
  camera {location <3,4,-5> look_at  <0,2,0>}
  #include "staircase.inc"
  #declare StairCase_StairCarpetColour = <0,1,0>;
  #declare StairCase_PostPositions = array [9] {<0,-1,-3.75>,<0,1,1.25>,<0,1,2.25>,<0,0,4.5>,<-5,4,6.5>,<-8,4,4.5>,<-7,3,3>,<-2,-1,2>,<10,-1,2>};
  #declare StairCase_StairWidth=2;
  #declare StairCase_StairCarpetWidth=1.6;
  StairCase()
#end  



//  *** Spiral Staircase Images ***


#if (ImageNumber = 51) 
  #local Image = "SteepSpiral";
  camera {location <-4,1.7,-3> look_at  <0,1.5,1>}
  #include "staircase.inc"
  light_source {AreaLight} 
  light_source {AreaLight2 translate <-90,-30,-40>} 
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<0,2.35,2>}; 
  StairCase_Spiral ()
#end  

#if (ImageNumber = 52) 
  #local Image = "LessSteepSpiral";
  camera {location <-4,1.7,-3> look_at  <0,1.8,0>}
  #include "staircase.inc"
  light_source {AreaLight} 
  light_source {AreaLight2 translate <-90,-30,-40>} 
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<0,3,2>}; 
  StairCase_Spiral ()
#end  

#if (ImageNumber = 53) 
  #local Image = "SteeperSpiral";
  camera {location <-4,1.7,-3> look_at  <0,1.6,0>}
  #include "staircase.inc"
  light_source {AreaLight} 
  light_source {AreaLight2 translate <-90,-30,-40>} 
  #declare StairCase_MaxInclination       = 39/40;
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<0,3,2>}; 
  StairCase_Spiral ()
#end  

#if (ImageNumber = 54) 
  #local Image = "Aerial View of Spiral";
  camera {location <0.5,5,0.5> look_at  <0.5,2,0.5>}
  #include "staircase.inc"  
  light_source {AreaLight translate y*40} 
  StairCase_Spiral ()
#end  

#if (ImageNumber = 55) 
  #local Image = "Aerial view of offset centre";
  camera {location <0.5,6,0.5> look_at  <0.5,2,0.5>}
  #include "staircase.inc"  
  light_source {AreaLight translate y*40} 
  #local StairCase_SpiralCentre         = <-0.5,0.5,0.5>; 
  StairCase_Spiral ()  
#end  

#if (ImageNumber = 56) 
  #local Image = "Default Spiral with Central Core";
  camera {location <-3,4,-1.5>  look_at  <0.5,1.5,0.5>}
  #include "staircase.inc"  
  light_source {AreaLight translate <-70,40,0>} 
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<2,2.5,0>};
  StairCase_Spiral ()  
#end  

#if (ImageNumber = 57) 
  #local Image = "Large Core/Core On";
  camera {location <-3,4,-1.5>  look_at  <0.5,1.5,0.5>}
  #include "staircase.inc"  
  light_source {AreaLight translate <-70,40,0>} 
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<2,2.5,0>};
  #declare StairCase_CentralCoreRadius    = 0.5;
  StairCase_Spiral ()  
#end    

#if (ImageNumber = 58) 
  #local Image = "Core Off";
  camera {location <-3,4,-1.5>  look_at  <0.5,1.5,0.5>}
  #include "staircase.inc"  
  light_source {AreaLight translate <-70,40,0>} 
  #declare StairCase_CentralCoreOn =0;
  #declare StairCase_CentralCoreRadius    = 0.5;
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<2,2.5,0>};
  StairCase_Spiral ()  
#end  

#if (ImageNumber = 59) 
  #local Image = "Constant Width Off";
  camera {location <0,8,2>  look_at  <0,1.5,2>}
  #include "staircase.inc"  
  light_source {AreaLight translate <0,40,40>} 
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<2,2.5,4>};
  #declare StairCase_CentralCoreRadius    = 0.5;
  #declare StairCase_ConstantStairWidthOn = 0;
  StairCase_Spiral ()  
#end  

#if (ImageNumber = 60) 
  #local Image = "Constant Width Off";
  camera {location <0,8,2>  look_at  <0,1.5,2>}
  #include "staircase.inc"  
  light_source {AreaLight translate <0,40,40>} 
  #declare StairCase_PostPositions = array [2] {<-2,0,0>,<2,2.5,4>};
  #declare StairCase_CentralCoreRadius    = 0.5;
  #declare StairCase_ConstantStairWidthOn = 1;
  StairCase_Spiral ()  
#end

#if (ImageNumber = 61) 
  #local Image = "Default Spiral Core Texture";
  camera {location <-2,1,-2>  look_at  <0,1.5,0>}
  #include "staircase.inc"  
  light_source {AreaLight translate <-80,40,-40>} 
  #declare StairCase_CentralCoreRadius    = 0.5;
  StairCase_Spiral ()  
#end

#if (ImageNumber = 62) 
  #local Image = "Spiral Core Texture";
  camera {location <-2,1,-2>  look_at  <0,1.5,0>}
  #include "staircase.inc"  
  light_source {AreaLight translate <-80,40,-40>} 
  #declare StairCase_CentralCoreRadius    = 0.5;
  #declare StairCase_CentralCoreTexture = texture {pigment {color rgb <1,0,1>}};
  StairCase_Spiral ()  
#end

// Balustrade Examples

#if (ImageNumber = 63) 
  #local Image = "Short Wide Flight of Stone Steps";
  camera {location <-2.4,1.8,-2>  look_at  <-0.5,0.75,1.8>}
  #include "staircase.inc" 
  #include "staircase_samplebalustrade.inc" 
  light_source {AreaLight translate <-120,40,-40>} 
  #declare StairCase_StairWidth = 2;
  #declare StairCase_MaxBalusterSpacing = 0.3;
  #declare StairCase_HandRailHeight = 0.75;
   
  #declare StairCase_BalusterTexture = texture {
    pigment {rgb <1,0.95,0.9>}
    normal {agate 0.5 scale 0.05}
  }
  
  #declare StairCase_RailTexture = texture {
    pigment {rgb <1,0.95,0.9>}
    normal {agate 0.2 scale 0.05}
  }
  #declare StairCase_NewelTexture       = StairCase_RailTexture
  #declare StairCase_StringerTexture    = StairCase_RailTexture
  #declare StairCase_StairCarpetTexture = StairCase_RailTexture

  #declare StairCase_PostPositions = array [2] {<-1,0,0>,<-1,1.5,3>};
  StairCase ()  

  #declare StairCase_PairedBanisterOn = 0;
  #declare StairCase_StairsOn = 0;
  #declare StairCase_PostPositions = array [2] {<-3,1.5,3>,<-1,1.5,3>};
  StairCase ()  

  #declare StairCase_PostPositions = array [2] {<3,1.5,3>,<1,1.5,3>};
  StairCase ()  
#end

 

#if (ImageNumber = 99) 
  #local Image = "Short Wide Flight of stone steps";
//  camera {location <-0.5,1.2,0>  look_at  <0.5,0.75,1>}
  camera {location <-2.4,1.8,-2>  look_at  <-0.5,0.75,1.8>}
  #include "staircase.inc" 
  #include "staircase_samplebalustrade.inc" 
  light_source {AreaLight translate <-120,40,-40>} 
  #declare StairCase_StairWidth = 2;
  #declare StairCase_MaxBalusterSpacing = 0.3;
  #declare StairCase_HandRailHeight = 0.75;
   
  #declare StairCase_BalusterTexture = texture {
    pigment {rgb <1,0.95,0.9>}
    normal {agate 0.5 scale 0.05}
  }
  
  #declare StairCase_RailTexture = texture {
    pigment {rgb <1,0.95,0.9>}
    normal {agate 0.2 scale 0.05}
  }
  #declare StairCase_NewelTexture       = StairCase_RailTexture
  #declare StairCase_StringerTexture    = StairCase_RailTexture
  #declare StairCase_StairCarpetTexture = StairCase_RailTexture

  #declare StairCase_PostPositions = array [2] {<-1,0,0>,<-1,1.5,3>};
  StairCase ()  

  #declare StairCase_PairedBanisterOn = 0;
  #declare StairCase_StairsOn = 0;
  #declare StairCase_PostPositions = array [2] {<-3,1.5,3>,<-1,1.5,3>};
  StairCase ()  

  #declare StairCase_PostPositions = array [2] {<3,1.5,3>,<1,1.5,3>};
  StairCase ()  

//  cylinder {-20*z,20*z,0.01 pigment {rgb <10,0,0>}}
//  cylinder {-20*x,20*x,0.01 pigment {rgb <10,0,10>}}
//  cylinder {<1.5,-2,0>,<1.5,4,0>,0.01 pigment {rgb <0,10,10>}}
//  cylinder {<-0.5,2,0.5>,<3.5,2,-0.5>,0.01 pigment {rgb <0,5,10>}}
//  torus {1.044,0.01 translate StairCase_SpiralCentre+y*2 pigment {rgb <0,5,10>}}
//  torus {2.062,0.01 translate StairCase_SpiralCentre+y*2 pigment {rgb <0,5,10>}}
  
#end  

 
