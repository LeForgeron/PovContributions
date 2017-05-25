//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL.
// Scale: 1 POV-Ray unit = 1 metre. 
// 

/**********************************************************************************/
/* staircase_spiralexample01.pov  -  Created by Chris Bartlett March 2008         */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This scene file illustrates the use of the staircase.inc file     */
/*              which is designed to enable you to add a staircase to a POV-Ray   */
/*              scene. The file staircase.html describes its use.                 */
/* Version:     Written using POV-Ray 3.5 and tested on 3.6                       */
/**********************************************************************************/
/*  This scene file defines a hotel lobby, with a complex stair case constructed  */
/*  using POV-Stairs situated at one end. The handrails running around each       */
/*  floor are also constructed using POV-Stairs. The walls, floors, ceilings,     */
/*  doors and windows are all dynamically added and are controlled by a small     */
/*  set of variables near the top of the scene file. This enables you to adjust   */
/*  the width of the lobby and the number of floors.                              */
/*                                                                                */
/*  NOTE: Setting the LandingLightsOn variable to 0 really speed up test renders. */ 
/*  Takes about 2 hours to render with the landing lights on and only a few       */
/*  minutes to render with them off.                                              */
/**********************************************************************************/

#version 3.5;

camera {location <-7.4,4.7,-8.3> look_at  <0,4.0,7>}
background {rgb <0.8,1,1>} 

#include "staircase.inc" 
#include "textures.inc"  

#declare FloorCount = 3;
#declare CeilingHeight = 1+2.5*(FloorCount+1);
#declare BuildingWidth = 40;
#declare FoyerWidth = 19;
#declare VoidWidth = 14; 
#declare MySeed = seed(1);
#declare LandingLightsOn = 1;  
#declare StairLightsOn = 1;  

// Add some general background lighting
light_source {<-4,CeilingHeight-1,0> color rgb 0.3}
light_source {<0,CeilingHeight-1,0> color rgb 0.3}
light_source {<4,CeilingHeight-1,0> color rgb 0.3}
light_source {<0,100,-200> color rgb 1}


#declare MainStairs = union {
  /***** The StairWell Core *****/
  #declare ArchCuts = union {
    box {<-1,0,1.9><1,1.25,4.5>}
    box {<-1.21,0.0001,2.2><1.21,1.45,3.7>}
    cylinder {<0,1.2,1.99><0,1.2,4.5>,1}
    cylinder {<-1.21,1.45,2.95><1.21,1.45,2.95>,0.75}
  }
  
  difference {
    box {<-1.2,0,2><1.2,CeilingHeight,4.4>}
    #local I = 1;
    #while (I<=FloorCount)
      object {ArchCuts translate y*(2.5*I+0.5)} 
      #local I = I + 1;
    #end
    pigment {color rgb 1}
  }
  
  // Add a light to each arch 
  #if (StairLightsOn)
    #local I = 1;
    #while (I<=FloorCount)
      light_source {<0,2.0,3.2> color rgb 1 translate y*(2.5*I+0.5) fade_power 2 fade_distance 1}
      #local I = I + 1;
    #end 
  #end
  
  /***** The StairCase *****/
  // The main sets of stairs between floors are basically all the same (just translated and mirrored)
  #declare StairCase_StairWidth=1.6;
  #declare StairCase_PostPositions     = array [2] {<-1.25,3,3.8>,<-1.1,0.5,0.5>};
  #declare StairCase_SpiralCentre      = <-1.2,0.5,1.8>;
  #declare StairCase_CentralCoreRadius = 0.3;
  #declare StairCase_CentralCoreOn     = 0;
  #declare MyStairCase = object {StairCase_Spiral()}

  #declare StairCase_StairWidth=1.5;
  
  object {MyStairCase}
  object {MyStairCase scale <-1,1,1>}
  
  // The rail along the back of the raised landing on the ground floor
  #declare StairCase_PairedBanisterOn = 0;
  #declare StairCase_PostPositions = array [2] {<-1.1,0.5,2>,<1.1,0.5,2>};
  StairCase()
  
  // The steps up to the bottom set of stairs is unique
  #declare StairCase_StairWidth=2;
  #declare StairCase_PairedBanisterOn = 1;
  #declare StairCase_PostPositions = array [2] {<-1,0,-0.4>,<-1,0.5,0.5>};
  StairCase()
  
  
  // The Upper flights use a repeating pattern, with the main flights joined by a landing at the front on each floor.  
  #declare MyStairCasePattern = union {
    // The main flight of stairs on the left plus a mirrored copy on the right
    object {MyStairCase}
    object {MyStairCase scale <-1,1,1>}
  
    // The handrail and landing joining the opposite flights
    #declare StairCase_StairWidth=1.5;
    #declare StairCase_MainBanisterOn = 0;
    #declare StairCase_PostPositions = array [2] {<-1,0.5,2>,<1,0.5,2>};
    StairCase()
  }
  
  
  // Add one of these for however many floors there are above the ground floor
  #local I = 1;
  #while (I<FloorCount)
    object {MyStairCasePattern translate y*2.5*I} 
    #local I = I + 1;
  #end     
  
  
  // Add a handrail to the top gap
  #declare StairCase_MainBanisterOn = 1;
  #declare StairCase_PairedBanisterOn = 0;
  #declare StairCase_StairsOn = 0;
  #declare StairCase_PostPositions = array [2] {<-1,0.5,2.1>,<1,0.5,2.1>};
  object {StairCase()  translate y*2.5*FloorCount}
}

// Add a handrail around each floor 
#declare StairCase_PostPositions = array [6] {<-1.2,0,VoidWidth/2>,<-VoidWidth/2,0,VoidWidth/2>,<-VoidWidth/2,0,-VoidWidth/2>,<VoidWidth/2,0,-VoidWidth/2>,<VoidWidth/2,0,VoidWidth/2>,<1.2,0,VoidWidth/2>};
#declare Perimeter = object {StairCase()}
#local I = 1;
#while (I<=FloorCount)
  object {Perimeter translate y*(2.5*I+0.5)} 
  #local I = I + 1;
#end     



// Roof
box {<-BuildingWidth/2,CeilingHeight,-BuildingWidth/2>,<BuildingWidth/2,CeilingHeight+0.2,BuildingWidth/2> texture {pigment {color rgb 1} normal {bumps 0.005} finish {ambient 0.3}}}

// Floors
#declare CarpetTexture = texture {pigment {color rgb <0,1,1>} normal{agate 0.2 scale 0.01}} 
box {<-BuildingWidth/2,-0.2,-BuildingWidth/2>,<BuildingWidth/2,0,BuildingWidth/2> pigment { checker pigment{Jade scale 0.2}, pigment{Red_Marble scale 0.2} scale 0.3}}
#declare FloorObject = difference {
  box {<-BuildingWidth/2,-0.125,-BuildingWidth/2>,<BuildingWidth/2,0,BuildingWidth/2>} 
  box {<-VoidWidth/2,-0.21,-VoidWidth/2>,<VoidWidth/2,0.01,VoidWidth/2>} 
  texture {pigment {color rgb 1} normal {bumps 0.005} finish {ambient 0.3}}
}
#declare FloorCarpet = difference {
  box {<-BuildingWidth/2,-0.005,-BuildingWidth/2>,<BuildingWidth/2,0.001,BuildingWidth/2>} 
  box {<-VoidWidth/2,-0.21,-VoidWidth/2>,<VoidWidth/2,0.01,VoidWidth/2>} 
  texture {CarpetTexture}
}
#local I = 1;
#while (I<FloorCount+1)
  object {FloorObject translate y*(2.5*I+0.5)} 
  object {FloorCarpet translate y*(2.5*I+0.5)} 
  #local I = I + 1;
#end

// Doorway
#declare Doorway = box {<-0.4,0,-0.01><0.4,0.8,0.21>}     

// Door
#declare Door = union {
  box {<-0.39,0,0.19><0.39,0.8,0.22>} 
  sphere {<0.30,0.4,0.18>,0.03
    texture {
      pigment {rgb <1,1,0>}
      finish {phong 0.5}
    }
  }
}

// Walls
#declare InternalWallStructure = union {
  // Long Wall
  difference {
    box {<-(FoyerWidth/2+0.2),0,-BuildingWidth/2>,<- FoyerWidth/2     ,1,BuildingWidth/2>}
    #local I = 0;
    #while (I<BuildingWidth/2-0.5)
      object {Doorway rotate -y*90 translate <-FoyerWidth/2,0, I>} 
      object {Doorway rotate -y*90 translate <-FoyerWidth/2,0,-I>} 
      #local I = I + 4;
    #end
  }
  // Opposite side of End Corridor   
  box {<-(FoyerWidth/2-2  ),0, FoyerWidth   /2>,<-(FoyerWidth/2-2.2),1,BuildingWidth/2>}
  // Other End Corridor  
  box {<  FoyerWidth/2-2   ,0, FoyerWidth   /2>,<  FoyerWidth/2-2.2 ,1,BuildingWidth/2>}
  // Short Wall Joining Corridors 
  difference {  
    box {<-(FoyerWidth/2-2  ),0, FoyerWidth   /2>,<  FoyerWidth/2-2   ,1,FoyerWidth/2+0.2>} 
    #local I = 0;
    #while (I<FoyerWidth/2-2.5)
      object {Doorway translate < I,0,FoyerWidth/2>} 
      object {Doorway translate <-I,0,FoyerWidth/2>} 
      #local I = I + 4;
    #end
  }
  // Doors
  #local I = 0;
  #while (I<BuildingWidth/2-0.5)
    object {Door pigment {Dark_Wood scale 0.5 translate z*rand(MySeed)} rotate -y*90 translate <-FoyerWidth/2,0, I>} 
    object {Door pigment {Dark_Wood scale 0.5 translate z*rand(MySeed)} rotate -y*90 translate <-FoyerWidth/2,0,-I>} 
    #local I = I + 4;
  #end
  #local I = 0;
  #while (I<FoyerWidth/2-2.5)
    object {Door pigment {Dark_Wood scale 0.5 translate z*rand(MySeed)}translate < I,0,FoyerWidth/2>} 
    object {Door pigment {Dark_Wood scale 0.5 translate z*rand(MySeed)}translate <-I,0,FoyerWidth/2>} 
    #local I = I + 4;
  #end
}

#declare InternalWallStructure = union { 
  object {InternalWallStructure}
  object {InternalWallStructure rotate y*180}
  texture {pigment {color rgb 1} normal {bumps 0.005} finish {ambient 0.3}}
}

object {InternalWallStructure scale <1,3,1>}
#local I = 1;
#while (I<FloorCount)
  object {InternalWallStructure scale <1,2.5,1> translate y*(2.5*I+0.5)}
  #local I = I + 1;
#end 
object {InternalWallStructure scale <1,3,1> translate y*(2.5*FloorCount+0.5)}

// Windows
#declare LandingWindowObject = difference {  
  box {<-1,-0.02,-0.1><1,1.02,0>}
  box {<-0.9 ,0.05,-0.11><-0.05,0.45,0.01>}
  box {< 0.05,0.05,-0.11>< 0.9 ,0.45,0.01>}
  box {<-0.9 ,0.55,-0.11><-0.05,0.95,0.01>}
  box {< 0.05,0.55,-0.11>< 0.9 ,0.95,0.01>}
  pigment {color rgb 0} //<0.5,0.3,0.2>}
  translate <-FoyerWidth/2+1,0,BuildingWidth/2>
}
//#declare LandingWindowObject = difference {  
//  box {<-FoyerWidth/2,0,BuildingWidth/2-0.1><-FoyerWidth/2-0.2,1,BuildingWidth/2>}
//  box {<0.09-FoyerWidth/2,0.09,BuildingWidth/2-0.11><0.51-FoyerWidth/2,0.41,BuildingWidth/2+0.01>}
//  box {<1.09-FoyerWidth/2,0.09,BuildingWidth/2-0.11><1.91-FoyerWidth/2,0.41,BuildingWidth/2+0.01>}
//  box {<0.09-FoyerWidth/2,0.59,BuildingWidth/2-0.11><0.91-FoyerWidth/2,0.91,BuildingWidth/2+0.01>}
//  box {<1.09-FoyerWidth/2,0.59,BuildingWidth/2-0.11><1.91-FoyerWidth/2,0.91,BuildingWidth/2+0.01>} 
//  pigment {color rgb 0} //<0.5,0.3,0.2>}
//  translate <FoyerWidth/2,0,-BuildingWidth/2>
//}

#local I = 0;
#while (I<=FloorCount)
  #if (I = 0 | I=FloorCount) #local ScaleFactor = 2.85;
  #else                      #local ScaleFactor = 2.45;
  #end 
  #if (I=0) #local Elevation = 0;
  #else #local Elevation = 2.5*I + 0.5;
  #end 
  object {LandingWindowObject scale < 1,ScaleFactor, 1> translate y*Elevation}
  object {LandingWindowObject scale <-1,ScaleFactor, 1> translate y*Elevation}
  object {LandingWindowObject scale < 1,ScaleFactor,-1> translate y*Elevation}
  object {LandingWindowObject scale <-1,ScaleFactor,-1> translate y*Elevation}
  #local I = I + 1;
#end 


// Landing Lights
#declare LightLine = (FoyerWidth + VoidWidth)/4;
#local I = 1;
#while (I<=FloorCount+1)
  #local J = 0;
  #while (J < 4)
    #local K = -LightLine+0.5; 
    #while (K <= LightLine) 
      #if (I=FloorCount+1) #local LightHeight=CeilingHeight-0.15;
      #else #local LightHeight=2.5*I+0.25;
      #end
      #if (LandingLightsOn) 
        light_source {<K,LightHeight,LightLine> color rgb 5 rotate J*90*y fade_power 2 fade_distance 0.3}
        light_source {<K,LightHeight,LightLine> color rgb 0.2+rand(MySeed)*0.2 spotlight point_at <K,2.5*I-1,LightLine> rotate J*90*y fade_power 2 fade_distance 3 radius 20 falloff 80 }
        sphere {<K,LightHeight+0.15,LightLine>,0.1 texture {pigment {color rgb 1} finish {ambient 1}} rotate J*90*y no_shadow}
      #else  
        sphere {<K,LightHeight+0.15,LightLine>,0.1 texture {pigment {color rgb 1} finish {ambient 0.5}} rotate J*90*y no_shadow}
      #end
      #local K = K + 2;
    #end 
    #local J = J + 1; 
  #end
  #local I = I + 1;
#end     

// Main Stair Case
object {MainStairs translate z*(-4.4+VoidWidth/2)}