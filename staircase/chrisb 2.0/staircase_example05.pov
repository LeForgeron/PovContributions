//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// 

/**********************************************************************************/
/* staircase_example05.pov  -  Created by Chris Bartlett March 2008               */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This scene file illustrates the use of the staircase.inc file     */
/*              which is designed to enable you to add a staircase to a POV-Ray   */
/*              scene. The file staircase.html describes its use.                 */
/* Version:     Written using POV-Ray 3.5 and tested on 3.6                       */
/**********************************************************************************/

#version 3.5;

#include "staircase.inc"   

//camera {location <-9,2.5,-0>  look_at  <-0.5,3.75,10>}    // Inside foyer, near to staircase
//camera {location <-4,2.5,-2>  look_at  <-0.5,3.75,-20>}      // Inside foyer looking towards lobby
//camera {location <15,3.5,-25>  look_at  <16,3.75,-23>}    // Fire Escape Camera
camera {location <-9,3.0,-30>  look_at  <-0.5,3.25,-20>}    // Outside looking into foyer
//light_source {<-2,2.8,-2> color rgb 1.5}      // Temporary light source
light_source {<-30,100,-80> color rgb 1}

// Set up some parameters to control the definition of the building
#declare FloorCount = 3;
#declare CeilingHeight = 1+2.5*(FloorCount+1);
#declare BuildingWidth = 40;
#declare BuildingLength  = 40;
#declare FoyerWidth = 19;
#declare VoidWidth = 14; 
#declare MySeed = seed(1);
#declare LandingLightsOn = 1;  
#declare StairLightsOn = 1;  
#declare EndPatioWidth   = 4;
#declare SidePatioWidth  = 2;


// For the stone balustrade we include appropriate object definitions and define some stone-like textures 
#include "staircase_samplebalustrade.inc" 
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

// Add a short Wide Flight of Stone Steps
#declare StairCase_StairWidth = 3;
#declare StairCase_MaxBalusterSpacing = 0.3;
#declare StairCase_HandRailHeight = 0.75;
#declare StairCase_PostPositions = array [2] {<-3,0,-BuildingLength/2-EndPatioWidth-3>,<-3,1.5,-BuildingLength/2-EndPatioWidth>};
#declare FrontSteps = union {
  object {StairCase ()} 
  #declare StairCase_PairedBanisterOn = 0;
  object {StairCase () scale <-1,1,1>} 
}  
#declare BackSteps  = object {FrontSteps scale <1,1,-1>}

// The front left balustrade
#declare StairCase_PairedBanisterOn = 0;
#declare StairCase_StairWidth = EndPatioWidth;
#local SectionLength = (BuildingWidth+2*SidePatioWidth-6)/8;  
#local I = 0;
#declare StairCase_PostPositions = array [5];
#while (I<=4)
  #declare StairCase_PostPositions[I] = <-3-SectionLength*I,1.5,-BuildingLength/2-EndPatioWidth>;
  #local I = I+1;
#end
#declare FrontLeft  = object {StairCase ()} 
#declare FrontRight = object {FrontLeft scale <-1,1, 1>} 
#declare BackLeft   = object {FrontLeft scale < 1,1,-1>} 
#declare BackRight  = object {FrontLeft scale <-1,1,-1>} 

// The left hand side
#local SectionLength = (BuildingLength+EndPatioWidth*2)/10;  
#local I = 0;
#declare StairCase_PostPositions = array [11];
#while (I<=10)
  #declare StairCase_PostPositions[I] = <-BuildingWidth/2-SidePatioWidth,1.5,-BuildingLength/2-EndPatioWidth+SectionLength*I>;
  #local I = I+1;
#end
#declare LeftSide  = StairCase()
#declare RightSide = object{LeftSide scale <-1,1,1>}

// Assemble the balustrade
object {FrontSteps}
object {FrontLeft}
object {FrontRight} 
object {BackSteps}
object {BackLeft}
object {BackRight} 
object {LeftSide}
object {RightSide}


plane {y,0
  texture {
    pigment {rgb <0.3,1,0.3>}
    normal {agate scale 0.01}
  } 
}

// Surround
difference {
  box {<-BuildingWidth/2-SidePatioWidth,0,-BuildingLength/2-EndPatioWidth><BuildingWidth/2+SidePatioWidth,1.5,BuildingLength/2+EndPatioWidth>}
  box {<-BuildingWidth/2,0.000001,-BuildingLength/2><BuildingWidth/2,1.50001,BuildingLength/2>
    pigment {rgb <0.5,0.8,1>}
  
  }
  texture {StairCase_StairCarpetTexture}
}

background {rgb <0.8,1,1>}    


#include "textures.inc"  

// Revert to the default settings for a wooden staircase
StairCase_Undef()  
/*******************************************************/
/*   The Central Staircase and Perimeter Handrails     */
/*******************************************************/
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
  // The bottom set of stairs has a unique shape
  #declare StairCase_StairWidth=1.5;
  #declare StairCase_PostPositions = array [4] {<-1.2,3,2.2>,<-2.5,1.75,2.2>,<-2.5,1.75,2>,<-1,0.5,2>};
  #declare MyStairCase = object {StairCase()}
  
  object {MyStairCase}
  object {MyStairCase scale <-1,1,1>}
  
  #declare StairCase_PairedBanisterOn = 0;
  #declare StairCase_PostPositions = array [2] {<-1,0.5,2>,<1,0.5,2>};
  StairCase()
  
  #declare StairCase_StairWidth=2;
  #declare StairCase_PairedBanisterOn = 1;
  #declare StairCase_PostPositions = array [2] {<-1,0,-0.4>,<-1,0.5,0.5>};
  StairCase()
  
  
  // The Upper flights use a repeating pattern  
  #declare MyStairCasePattern = union {
    object {MyStairCase}
    object {MyStairCase scale <-1,1,1>}
  
    #declare StairCase_StairWidth=1.5;
    #declare StairCase_MainBanisterOn = 0;
    #declare StairCase_PostPositions = array [2] {<-1,0.5,2>,<1,0.5,2>};
    StairCase()
  }
  
  
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
 
/************************************************************************/
/*   Add stairs in the lobby and a handrail to front the first floor    */
/************************************************************************/ 
StairCase_Undef()

// Define the stairs on the right hand side of the lobby leading to the first floor
#declare StairCase_StairWidth=2;
#declare StairCase_MainBanisterOn = 1;
#declare StairCase_PostPositions = array [3] {
  <VoidWidth/2-StairCase_StairWidth*2,1.5 ,-FoyerWidth/2-StairCase_StairWidth>,
  <VoidWidth/2-StairCase_StairWidth  ,2.25,-FoyerWidth/2-StairCase_StairWidth>,
  <VoidWidth/2-StairCase_StairWidth  ,3   ,-FoyerWidth/2>
};
#declare LobbyStairs = StairCase() 

// Define the steps down into the central foyer
#declare StairCase_PostPositions = array [2] {
  <VoidWidth/2-StairCase_StairWidth*2,0  ,-FoyerWidth/2>,
  <VoidWidth/2-StairCase_StairWidth*2,1.5,-FoyerWidth/2-StairCase_StairWidth>
};
#declare LobbyToFoyerSteps = StairCase()

// First floor hand rail
#declare StairCase_PairedBanisterOn = 0;
#declare StairCase_StairsOn = 0;
#declare StairCase_PostPositions = array [2] {
  <-VoidWidth/2+StairCase_StairWidth,3,-FoyerWidth/2>,
  <VoidWidth/2-StairCase_StairWidth,3,-FoyerWidth/2>
};
#declare LobbyFirstFloorRail = StairCase()

// Stairs on the right of the lobby
object {LobbyStairs}
// Stairs on the left of the lobby
object {LobbyStairs scale <-1,1,1>}
// Handrail fronting the first floor walkway where it crosses the lobby
object {LobbyFirstFloorRail}
// Steps down from lobby to central foyer
object {LobbyToFoyerSteps}
object {LobbyToFoyerSteps scale <-1,1,1>}
object {LobbyToFoyerSteps translate -x*StairCase_StairWidth}


/*****************************/
/*  The Spiral Fire Escapes  */
/*****************************/
StairCase_Undef()
// Redefine the shapes for some of the staircase components
#include "StairCase_Samples.inc"
#declare StairCase_NewelPost       = difference {
  StairCase_NewelShape    ("Bevelled")
  plane {y,0}
} 
#declare StairCase_Baluster        = StairCase_BalusterShape ("Bevelled")
#declare StairCase_HandRail        = cylinder {<0,0.015,0><0,0.015,1>,0.03 clipped_by{plane{-y,0}} scale <1,0.6,1>}; 
#declare StairCase_Riser = difference {
box {<-0.5,-1,0.120><0.5,-0.001,0.128>} 
box {<-0.05,-0.05,0.119><0.05,0.05,0.129> rotate z*45 scale <1,2,1> translate <-0.25,-0.55,0>}
box {<-0.05,-0.05,0.119><0.05,0.05,0.129> rotate z*45 scale <1,2,1> translate < 0 ,-0.55,0>}
box {<-0.05,-0.05,0.119><0.05,0.05,0.129> rotate z*45 scale <1,2,1> translate < 0.25,-0.55,0>}
}
// Settings
#declare StairCase_StairWidth      = 0.9; 
#declare StairCase_StairHandedness = -1;
#declare StairCase_StairCarpetOn   = 0;
#declare StairCase_SpiralCentre    = <BuildingWidth/2-3,1.5,-BuildingLength/2-1>;
// Use a simple red colour for almost everything
#declare StairCase_RailTexture     = texture {pigment {rgb <0.9,0,0>} normal {agate 0.1 scale 0.1} finish {reflection 0.2 phong 0.5}}
#declare StairCase_NewelTexture    = StairCase_RailTexture
#declare StairCase_BalusterTexture = StairCase_RailTexture
#declare StairCase_StringerTexture = StairCase_RailTexture
#declare StairCase_TreadTexture    = StairCase_RailTexture
#declare StairCase_RiserTexture    = StairCase_RailTexture

#declare FireEscape = union {
  // Lower Flight, down onto walkway
  #declare StairCase_PostPositions = array [2] {
    StairCase_SpiralCentre+x+y*1.5,
    StairCase_SpiralCentre-x
  };
  StairCase_Spiral()  
  // The other spiral flights
  #declare StairCase_SpiralCentre    = StairCase_SpiralCentre + y*1.5; 
  #declare StairCase_PostPositions = array [2] {
    StairCase_SpiralCentre+x+y*2.5,
    StairCase_SpiralCentre+z
  };
  #declare MainSpiral = StairCase_Spiral()  
  object {MainSpiral}
  object {MainSpiral translate y*2.5}
  object {MainSpiral translate y*5  }
  // The landings on each floor
  #declare StairCase_PairedBanisterOn = 0; 
  #declare StairCase_StairWidth = 1;
  #declare StairCase_PostPositions  = array [2] {
    StairCase_SpiralCentre+x,
    StairCase_SpiralCentre+x+z
  };
  #declare Landing = StairCase()
  object {Landing}
  object {Landing translate y*2.5}
  object {Landing translate y*5  }
}


object {FireEscape}
object {FireEscape scale <-1,1, 1>}
object {FireEscape scale < 1,1,-1>}
object {FireEscape scale <-1,1,-1>}



/**********************************/
/*   The Main Building Fabric     */
/**********************************/ 

// Lobby
#declare Lobby = box {<-(FoyerWidth/2-2.2),0,-(BuildingLength/2+0.001)>,<(FoyerWidth/2-2.2),5.502,-FoyerWidth/2+0.001>}
// Lobby Floor
#declare Lobby_Floor = box {<-(FoyerWidth/2-2.2),1.25,-BuildingLength/2><FoyerWidth/2-2.2,1.5,-FoyerWidth/2-2> pigment {rgb 1}}

// Roof
#declare Roof = box {<-BuildingWidth/2,CeilingHeight,-BuildingWidth/2>,<BuildingWidth/2,CeilingHeight+0.2,BuildingWidth/2> texture {pigment {color rgb 1} normal {bumps 0.005} finish {ambient 0.3}}}

// Floors
#declare CarpetTexture = texture {pigment {color rgb <0,1,1>} normal{agate 0.2 scale 0.01}} 
#declare Floors = union {
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
    #if (I=1) 
      difference { 
        union {
          object {FloorObject translate y*(2.5*I+0.5)} 
          object {FloorCarpet translate y*(2.5*I+0.5)} 
        }  
        object {Lobby}
        cutaway_textures
      }
    #else 
      object {FloorObject translate y*(2.5*I+0.5)} 
      object {FloorCarpet translate y*(2.5*I+0.5)} 
    #end
    #local I = I + 1;
  #end
}


// Doorway
#declare Doorway = box {<-0.4,0,-0.01><0.4,0.8,0.21>}     

// Door
#declare Door = union {
  box {<-0.39,0,0.19><0.39,0.8,0.22> pigment {Dark_Wood}}
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
    object {Door rotate -y*90 translate <-FoyerWidth/2,0, I>} 
    object {Door rotate -y*90 translate <-FoyerWidth/2,0,-I>} 
    #local I = I + 4;
  #end
  #local I = 0;
  #while (I<FoyerWidth/2-2.5)
    object {Door translate < I,0,FoyerWidth/2>} 
    object {Door translate <-I,0,FoyerWidth/2>} 
    #local I = I + 4;
  #end
}

#declare InternalWallStructure = union { 
  object {InternalWallStructure}
  object {InternalWallStructure rotate y*180}
  texture {pigment {color rgb 1} normal {bumps 0.005} finish {ambient 0.3}}
}

#declare InternalWalls = union {
  difference {
    object {InternalWallStructure scale <1,3,1>} 
    object {Lobby}
    cutaway_textures 
  }
  #local I = 1;
  #while (I<FloorCount)
    #if (I=1) 
      difference {
        object {InternalWallStructure scale <1,2.5,1> translate y*(2.5*I+0.5)}
        object {Lobby}
        cutaway_textures
      }
    #else
      object {InternalWallStructure scale <1,2.5,1> translate y*(2.5*I+0.5)}
    #end
    #local I = I + 1;
  #end 
  object {InternalWallStructure scale <1,3,1> translate y*(2.5*FloorCount+0.5)}
}

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

#declare LandingWindows = union {
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
}

// Landing Lights 
#declare LightLine = (FoyerWidth + VoidWidth)/4;
#declare LandingLights = union {
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
}

object {Roof}

object {Floors}
object {Lobby_Floor}

object {InternalWalls}

object {LandingWindows}
object {LandingLights}

object {MainStairs}




