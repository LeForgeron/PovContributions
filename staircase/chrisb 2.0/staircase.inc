//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// Updated March 2008 for inclusion in the POV-Ray Object Collection

/**********************************************************************************/
/* staircase.inc         -  Created by Chris Bartlett April 2006                  */
/*                          Updated June 2006 to add spiral stair cases           */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This file contains definitions and macros designed to enable you  */
/*              to add a staircase to a POV-Ray scene.                            */
/*              The file staircase.html describes its use.                        */
/* Version:     Written using POV-Ray 3.5 and tested on 3.6                       */
/**********************************************************************************/

#version 3.5; 

#include "math.inc"
#include "transforms.inc" 

// The StairCase Macro generates a staircase based upon control variable settings.
// The main variable is StairCase_PostPositions which is an array that holds the positions of the newel 
// posts that define one side of the staircase (by default the left hand posts). All of the 
// control variables have default settings. The control variables are described in staircase_variables.html.  

#macro StairCase() 
  // Check for old-style variable names (POV-Stairs variable names)
  #ifndef (StairCase_CompatibilityMode) #declare StairCase_CompatibilityMode = 0; #end
  #if (StairCase_CompatibilityMode=1)
    StairCase_Compatibility()
  #end

  // Default Texture Settings 
  #local TextureSeed = seed(6);
  #ifndef(StairCase_PostPositions) #local StairCase_PostPositions = array [4] {<0,0,0>,<0,2,3>,<-1,2.5,2>,<-2,3,-2>}; #end 
  #ifndef(StairCase_NewelTexture)
    #ifndef(Clear)   #include "colors.inc" #end
    #ifndef(T_Wood1) #include "woods.inc"  #end
    #local StairCase_NewelTexture = texture {T_Wood1 scale 0.1 rotate x*90}
  #end
  #ifndef(StairCase_BalusterTexture)    #local StairCase_BalusterTexture    = texture {StairCase_NewelTexture}              #end
  #ifndef(StairCase_StringerTexture)       
    #ifndef(Clear)   #include "colors.inc" #end
    #ifndef(T_Wood30) #include "woods.inc" #end
    #local StairCase_StringerTexture = texture {T_Wood30 scale 0.1} // rotate <90,0,90>}
  #end
  #ifndef(StairCase_RailTexture)        #local StairCase_RailTexture        = texture {StairCase_NewelTexture rotate -x*90} #end
  #ifndef(StairCase_TreadTexture)       #local StairCase_TreadTexture       = texture {StairCase_NewelTexture rotate -z*90} #end
  #ifndef(StairCase_RiserTexture)       
    #ifndef(Clear)   #include "colors.inc" #end
    #ifndef(T_Wood30) #include "woods.inc" #end
    #local StairCase_RiserTexture = texture {T_Wood30 scale 0.1 rotate <90,0,90>}
  #end 
  
  // Default Control Variable Settings
  #ifndef(StairCase_MaxBalusterSpacing) #local StairCase_MaxBalusterSpacing = 0.135;      #end
  #ifndef(StairCase_MaxRiserHeight)     #local StairCase_MaxRiserHeight     = 0.190;      #end
  #ifndef(StairCase_RiserCoverage)      #local StairCase_RiserCoverage      = 1;          #end // 0=No Riser, 1=Full Height Riser
  #ifndef(StairCase_HandRailHeight)     #local StairCase_HandRailHeight     = 0.920;      #end
  #ifndef(StairCase_StairWidth)         #local StairCase_StairWidth         = 1;          #end 
  #ifndef(StairCase_StairsOn)           #local StairCase_StairsOn           = 1;          #end // 0=No Stairs, 1=Stairs
  #ifndef(StairCase_StairHandedness)    #local StairCase_StairHandedness    = 1;          #end //-1=Left, 0=Centred, 1=Right as seen from foot of stairs
  #ifndef(StairCase_LandingsOn)         #local StairCase_LandingsOn         = StairCase_StairsOn; #end // 0=No Landings, 1=Add Landings 
  #ifndef(StairCase_LandingThreshold)   #local StairCase_LandingThreshold   = 50;         #end // Threshold angle below which we remove a newel post 
  #ifndef(StairCase_MainBanisterOn)     #local StairCase_MainBanisterOn     = 1;          #end // 1=Main Hand Rail On, 0=No Main Hand Rail
  #ifndef(StairCase_PairedBanisterOn)   #local StairCase_PairedBanisterOn   = 1;          #end // 1=Paired Hand Rail On, 0=No Paired Hand Rail
  
  // Default Stair covering, colour and texture 
  #ifndef(StairCase_StairCarpetOn)     #local StairCase_StairCarpetOn = 1;                #end
  #ifndef(StairCase_StairCarpetWidth)  #local StairCase_StairCarpetWidth = StairCase_StairWidth;  #end
  #ifndef(StairCase_StairCarpetColour) #local StairCase_StairCarpetColour = <1,1,0>;      #end
  #ifndef(StairCase_StairCarpetTexture)
    #local StairCase_StairCarpetTexture = texture {pigment {color rgb StairCase_StairCarpetColour} normal{agate 0.2 scale 0.01}} 
  #end 
  
  // Default staircase components
  #ifndef(StairCase_Stringer   ) #local StairCase_Stringer    = StairCase_DefaultStringer    #end
  #ifndef(StairCase_Tread      ) #local StairCase_Tread       = StairCase_DefaultTread       #end
  #ifndef(StairCase_Riser      ) #local StairCase_Riser       = StairCase_DefaultRiser       #end
  #ifndef(StairCase_StairCarpet) #local StairCase_StairCarpet = StairCase_DefaultStairCarpet #end
  #ifndef(StairCase_HandRail   ) #local StairCase_HandRail    = StairCase_DefaultHandRail    #end
  #ifndef(StairCase_Baluster   ) #local StairCase_Baluster    = StairCase_DefaultBaluster    #end
  #ifndef(StairCase_NewelPost  ) #local StairCase_NewelPost   = StairCase_DefaultNewelPost   #end

  union {
    // At each of the positions defined in the StairCase_PostPositions array we position a newel post and optionaly add stairs 
    // a banister rail and landings. We also add a second set of newel posts and banister rails at the other side of the 
    // stairs. The local variable 'I' holds the array index number of the current newel post.
    #local I = 0;
    #while (I<dimension_size(StairCase_PostPositions,1))
      #local PostSeparation = StairCase_StairWidth*(abs(StairCase_StairHandedness));
      #if (StairCase_MainBanisterOn)
        object {StairCase_NewelPost
          texture {StairCase_NewelTexture translate <0.05+0.05*rand(TextureSeed),20*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
          #if (I=0)
            rotate y*atan2d(StairCase_PostPositions[1].x-StairCase_PostPositions[0].x,StairCase_PostPositions[1].z-StairCase_PostPositions[0].z)
          #else
            rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
          #end
          translate StairCase_PostPositions[I]
        }
      #end
  
      // Place a corresponding Newel Post at the opposite side of the stairs
      #if (I=0 & StairCase_PairedBanisterOn)
        #local NextHorizontalOffset = <1,0,1> * (StairCase_PostPositions[I] - StairCase_PostPositions[I+1]);
        #local Post2 = StairCase_PostPositions[I] + vrotate(vnormalize(NextHorizontalOffset), -y*90*sgn(StairCase_StairHandedness)) * PostSeparation; 
      #end
  
      // Starting from the second Newel Post we start drawing stairs and banister rails
      #if (I>0)
        #local NewelSeparation = vlength(StairCase_PostPositions[I]-StairCase_PostPositions[I-1]);
        #local HorizontalNewelSeparation = vlength(<StairCase_PostPositions[I].x-StairCase_PostPositions[I-1].x,0,StairCase_PostPositions[I].z-StairCase_PostPositions[I-1].z>);
        #local VerticalNewelSeparation   = StairCase_PostPositions[I].y-StairCase_PostPositions[I-1].y;
        #if (StairCase_MainBanisterOn) StairCase_BannisterGen(StairCase_PostPositions[I], StairCase_PostPositions[I-1],StairCase_HandRailHeight) #end
        #local Post1 = StairCase_PostPositions[I];
        #local PreviousHorizontalOffset = <1,0,1> * (StairCase_PostPositions[I] - StairCase_PostPositions[I-1]);
        #local Post2 = Post1 + vrotate(vnormalize(PreviousHorizontalOffset), y*90*sgn(StairCase_StairHandedness)) * PostSeparation;
        #if (I<dimension_size(StairCase_PostPositions,1)-1) 
          #local NextHorizontalOffset     = <1,0,1> * (StairCase_PostPositions[I] - StairCase_PostPositions[I+1]);
          #local Post4 = Post1 + vrotate(vnormalize(NextHorizontalOffset),-y*90*sgn(StairCase_StairHandedness)) * PostSeparation;
          #if (abs(VAngleD(Post4-Post1,Post2-Post1))>StairCase_LandingThreshold) #local AddCorner = 1;
          #else #local AddCorner = 0;
          #end
          #if (AddCorner) #local Post3 = Post2 + Post4-Post1;
          #else #ifdef(Post3) #undef Post3 #end
          #end 
        #end
        // The stairs themselves are also optional
        #if (StairCase_StairsOn!=0)
          #local TreadCount = div(abs(VerticalNewelSeparation/StairCase_MaxRiserHeight)+0.999,1);
          #if (TreadCount = 0)
            box {<0,-0.018,0>,<1,0,vlength(StairCase_PostPositions[I]-StairCase_PostPositions[I-1])>
              translate -0.5*x 
              translate -x*StairCase_StairHandedness/2 scale <StairCase_StairWidth,1,1>
              texture {StairCase_TreadTexture translate <-20*rand(TextureSeed),0.05+0.05*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
              rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
              translate StairCase_PostPositions[I]
            }
            #if (StairCase_StairCarpetOn)
              box {<0,0,0>,<1,0.005,vlength(StairCase_PostPositions[I]-StairCase_PostPositions[I-1])>
                translate -0.5*x
                scale <StairCase_StairCarpetWidth,1,1> 
                translate -x*StairCase_StairWidth*StairCase_StairHandedness/2    
                texture {StairCase_StairCarpetTexture}
                rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
                translate StairCase_PostPositions[I]
              }
            #end
          #else 
            #local RiserSpacing = HorizontalNewelSeparation/TreadCount;
            #local RiserHeight  = VerticalNewelSeparation/TreadCount;
            #local J = 0;
            #while (J<=TreadCount)
              #if (!(I=1&J=TreadCount&VerticalNewelSeparation>0))
                #if (VerticalNewelSeparation>0)
                  // The Flight of Stairs is going up relative to the start of the flight
                  union {object {StairCase_Tread}
                    object {StairCase_Tread clipped_by {box {<-1,-1,-0.1><1,0.01,0>}} scale <1,1,10*(RiserSpacing-0.122)>} 
                    #if (J=0) clipped_by {plane {-z,0}} #end   
                    #if (J>0 & J< TreadCount) clipped_by {plane {-z,0 translate -z*(RiserSpacing-0.122)}} #end   
                    #if (J=TreadCount) clipped_by {box {<-1,-1,-(RiserSpacing-0.122)><1,0.01,0>}} #end 
                    translate -x*StairCase_StairHandedness/2 scale <StairCase_StairWidth,1,1>  
                    texture {StairCase_TreadTexture translate <-20*rand(TextureSeed),0.05+0.05*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
                    translate z*J*RiserSpacing
                    rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
                    translate -y*J*VerticalNewelSeparation/TreadCount 
                    translate StairCase_PostPositions[I]
                  }
                #else
                  // The Flight of Stairs is going down relative to the start of the flight
                  object {StairCase_Tread 
                    #if (J>0) 
                      clipped_by {plane {-z,0 translate -z*(RiserSpacing-0.120)}} 
                      translate z*(RiserSpacing/2-0.122) rotate y*180 translate -z*(RiserSpacing/2-0.122)
                    #end   
                    #if (J=0) clipped_by {box {<-1.01,-0.1,0.122><1.01,0.01,0>}} #end 
                    translate -x*StairCase_StairHandedness/2 scale <StairCase_StairWidth,1,1>  
                    texture {StairCase_TreadTexture translate <-20*rand(TextureSeed),0.05+0.05*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
                    translate z*J*RiserSpacing
                    rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
                    translate -y*J*VerticalNewelSeparation/TreadCount 
                    translate StairCase_PostPositions[I]
                  }
                #end
                #if (J!=TreadCount)
                  object {StairCase_Riser translate -x*StairCase_StairHandedness/2 scale<StairCase_StairWidth,RiserHeight*StairCase_RiserCoverage,1>  
                    texture {StairCase_RiserTexture translate <-20*rand(TextureSeed),0.05+0.05*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
                    translate z*J*RiserSpacing
                    rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
                    translate -y*J*VerticalNewelSeparation/TreadCount 
                    translate StairCase_PostPositions[I]
                  } 
                #end
                #if (StairCase_StairCarpetOn)
                  #if (VerticalNewelSeparation>0)
                    // This uses two copies of the carpet object with one bit being stretched back to make sure we have enough to cover a 
                    // very large step or a landing without distorting the profile of the front edge of the carpet where it wraps over the
                    // stair.
                    union {object {StairCase_StairCarpet}
                      object {StairCase_StairCarpet clipped_by {box {<-1,-1,-0.1><1,0.01,0>}} scale <1,1,10*(RiserSpacing-0.122)>} 
                      #if (J=0) clipped_by {plane {-z,0}} #end   
                      #if (J>0 & J< TreadCount) clipped_by {plane {-z,0 translate -z*(RiserSpacing-0.122)}} #end   
                      #if (J=TreadCount) clipped_by {box {<-1,-1,-(RiserSpacing-0.122)><1,0.01,0>}} #end 
                      #if (VerticalNewelSeparation<0) translate z*RiserSpacing/2+0.122 rotate y*180 translate z*RiserSpacing/2+0.122 #end
                      scale <StairCase_StairCarpetWidth,1,1> translate -x*StairCase_StairWidth*StairCase_StairHandedness/2   
                      texture {StairCase_StairCarpetTexture translate 2*y*J*VerticalNewelSeparation/TreadCount}
                      translate z*J*RiserSpacing
                      rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
                      translate -y*J*VerticalNewelSeparation/TreadCount 
                      translate StairCase_PostPositions[I]
                    }
                  #else
                    object {StairCase_StairCarpet   
                    #if (J>0) 
                      clipped_by {plane {-z,0 translate -z*(RiserSpacing-0.120)}} 
                      translate z*(RiserSpacing/2-0.122) rotate y*180 translate -z*(RiserSpacing/2-0.122)
                    #end   
                      #if (J=0) clipped_by {box {<-1.01,-0.1,0.122><1.01,0.01,0>}} #end 
                      scale <StairCase_StairCarpetWidth,1,1> translate -x*StairCase_StairWidth*StairCase_StairHandedness/2   
                      texture {StairCase_StairCarpetTexture translate 2*y*J*VerticalNewelSeparation/TreadCount}
                      translate z*J*RiserSpacing
                      rotate y*atan2d(StairCase_PostPositions[I-1].x-StairCase_PostPositions[I].x,StairCase_PostPositions[I-1].z-StairCase_PostPositions[I].z)
                      translate -y*J*VerticalNewelSeparation/TreadCount 
                      translate StairCase_PostPositions[I]
                    }
                  #end
                #end
              #end
              #local J = J + 1; 
            #end 
          #end
  
          // Work out the corners for landings to connect the top of one flight of stairs to the bottom of the next.
          #local PostToEdge = (StairCase_StairWidth - PostSeparation)/2;
          #if (I<dimension_size(StairCase_PostPositions,1)-1)
            #local Corner1  = Post1;
            #local Corner2  = Post2;
            #local Corner4  = Post4;
            #local Corner2a = Post2 + vnormalize(PreviousHorizontalOffset) * PostToEdge; 
            #local Corner4a = Post4 + vnormalize(NextHorizontalOffset)     * PostToEdge;
            #if (AddCorner)
              #local ParallelogramWidth = vlength(Post3-Post1+VProject_Axis(Post3-Post1,Post2-Post1));
              #local Corner3 = Post3+(Post3-Post1)*PostToEdge/ParallelogramWidth;
            #end
            #if (StairCase_LandingsOn)
              #local Landing = prism {
                linear_spline
                -0.02,0,
                #if (AddCorner) 7,
                #else 6,
                #end
                <Corner1.x ,Corner1.z >,
                <Corner2.x ,Corner2.z >,
                <Corner2a.x,Corner2a.z>,
                #if (AddCorner) <Corner3.x,Corner3.z>, #end
                <Corner4a.x,Corner4a.z>,
                <Corner4.x ,Corner4.z >,
                <Corner1.x ,Corner1.z >
              }
              object {Landing
                texture {StairCase_TreadTexture}
                translate y*Corner1
              }
              // The carpeting of the landing can be complicated by the shape of the landing and depends upon
              // the number of Newel Posts required to turn the corner.
              #if (StairCase_StairCarpetOn)
                #local CarpetInset = (StairCase_StairWidth-StairCase_StairCarpetWidth)/2;
                #local Corner1a = Post1 + (CarpetInset-PostToEdge)*vnormalize(Post2-Post1);
                #local Corner1b = Post1 + (CarpetInset-PostToEdge)*vnormalize(Post4-Post1);
                #local Corner1  = Corner1a + Corner1b - Post1;
                #local Corner2  = Post2 - (CarpetInset-PostToEdge)*vnormalize(Post2-Post1);
                #local Corner4  = Post4 - (CarpetInset-PostToEdge)*vnormalize(Post4-Post1);
                #if (AddCorner) #local Corner3 = Corner4 + Corner2 - Post1; #end
                #local LandingCarpet = prism {
                  linear_spline
                  0,0.005,
                  #if (AddCorner) 7,
                  #else 5,
                  #end
                  <Corner1a.x,Corner1a.z>,
                  <Corner2.x ,Corner2.z >,
                  #if (AddCorner) <Corner3.x,Corner3.z>, #end
                  <Corner4.x ,Corner4.z >, 
                  <Corner1b.x,Corner1b.z>,
                  #if (AddCorner) <Corner1.x ,Corner1.z >, #end
                  <Corner1a.x ,Corner1a.z >
                }
                object {LandingCarpet
                  texture {StairCase_StairCarpetTexture}
                  translate y*Corner1
                }
              #end
            #end
          #end
        #end
      #end 
      // Create a Newel Post on the opposite side of the staircase
      #ifdef(Post2) 
        // Temporary Bodge
        #if (I>0)
          #local PreviousHorizontalOffset = <1,0,1> * (StairCase_PostPositions[I] - StairCase_PostPositions[I-1]);
          #local Post2 = StairCase_PostPositions[I] + vrotate(vnormalize(PreviousHorizontalOffset), y*90*sgn(StairCase_StairHandedness)) * PostSeparation; 
        #end
        #if (StairCase_PairedBanisterOn) 
          #if (I>0) StairCase_BannisterGen(Post2, StairCase_PostPositions[I-1]+Post2-StairCase_PostPositions[I],StairCase_HandRailHeight) #end
          #if (I=0)
            object {StairCase_NewelPost
              texture {StairCase_NewelTexture translate <0.05+0.05*rand(TextureSeed),20*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
              rotate y*atan2d(StairCase_PostPositions[I].x-StairCase_PostPositions[I+1].x,StairCase_PostPositions[I].z-StairCase_PostPositions[I+1].z)
              translate Post2
            }
          #else
            object {StairCase_NewelPost
              texture {StairCase_NewelTexture translate <0.05+0.05*rand(TextureSeed),20*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
              rotate y*atan2d(StairCase_PostPositions[I].x-StairCase_PostPositions[I-1].x,StairCase_PostPositions[I].z-StairCase_PostPositions[I-1].z)
              translate Post2
            }
          #end
        #end 
      #end
      
      #if (I<dimension_size(StairCase_PostPositions,1)-1)
        // If doing a landing we may need an additional Newel Post and a bit more banister rail to turn the corner
        #ifdef(Post3)
          #if (StairCase_PairedBanisterOn) 
            object {StairCase_NewelPost
              texture {StairCase_NewelTexture translate <0.05+0.05*rand(TextureSeed),20*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
              rotate y*atan2d(StairCase_PostPositions[I].x-StairCase_PostPositions[I+1].x,StairCase_PostPositions[I].z-StairCase_PostPositions[I+1].z)
              translate Post3
            }
            StairCase_BannisterGen(Post2,Post3,StairCase_HandRailHeight)
          #end
        #end
        // If doing a landing we may need an additional Newel Post and a bit more banister rail to turn the corner
        #ifdef(Post4)
          #if (StairCase_PairedBanisterOn) 
            object {StairCase_NewelPost
              texture {StairCase_NewelTexture translate <0.05+0.05*rand(TextureSeed),20*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
              rotate y*atan2d(StairCase_PostPositions[I].x-StairCase_PostPositions[I+1].x,StairCase_PostPositions[I].z-StairCase_PostPositions[I+1].z)
              translate Post4
            }
            #ifdef(Post3) StairCase_BannisterGen(Post3,Post4,StairCase_HandRailHeight)
            #else StairCase_BannisterGen(Post2,Post4,StairCase_HandRailHeight)
            #end
          #end 
        #end
      #end
      #local I = I + 1;
    #end  
  }
#end

// The StairCase_BannisterGen macro is used by the StairCase macro to define the banister rail that connects two newel posts.
// Certain variables must be set before this macro is called. This macro is not intended to be called directly from 
// a scene file.
#macro StairCase_BannisterGen(Start,End,Height) 
  #local NewelSeparation = vlength(Start-End);
  #local HorizontalNewelSeparation = vlength(<Start.x-End.x,0,Start.z-End.z>);
  #local VerticalNewelSeparation   = Start.y-End.y;
  #if (NewelSeparation = 0) #local NewelSeparation = 0.0001; #end
  object {StairCase_HandRail scale <1,1,NewelSeparation>
    texture {StairCase_RailTexture translate <0.05+0.08*rand(TextureSeed),0.05+0.08*rand(TextureSeed),2000*rand(TextureSeed)>}
    translate  z*0.032*sgn(VerticalNewelSeparation)
    rotate x*asind(VerticalNewelSeparation/NewelSeparation)
    translate -z*0.032*sgn(VerticalNewelSeparation)
    rotate y*atan2d(End.x-Start.x,End.z-Start.z)
    translate Start+y*Height  
  }

  // Baluster separation should be a maximum of 135mm
  #local BalusterCount = div((HorizontalNewelSeparation/StairCase_MaxBalusterSpacing)-0.5,1);
  #if (BalusterCount>0) #local BalusterSpacing = HorizontalNewelSeparation/BalusterCount; #end
  #local J = 1;
  #while (J<BalusterCount)
    object {StairCase_Baluster    
      clipped_by {plane {y,0 rotate x*asind(VerticalNewelSeparation/NewelSeparation) translate y*Height}}
      texture {StairCase_BalusterTexture translate <0.05+0.05*rand(TextureSeed),-20*rand(TextureSeed),0.1+0.5*rand(TextureSeed)>}
      translate z*J*BalusterSpacing
      rotate y*atan2d(End.x-Start.x,End.z-Start.z)
      translate -y*J*VerticalNewelSeparation/BalusterCount 
      translate Start
    }
    #local J = J + 1;
  #end
  difference {
    object {StairCase_Stringer scale <1,1,NewelSeparation>
      texture {StairCase_StringerTexture translate <0.05+0.08*rand(TextureSeed),0.05+0.08*rand(TextureSeed),2000*rand(TextureSeed)>}
      rotate x*asind(VerticalNewelSeparation/NewelSeparation)
    }
    plane { z,0 texture {StairCase_StringerTexture}}
    plane {-z,0 translate z*HorizontalNewelSeparation texture {StairCase_StringerTexture}}
    rotate y*atan2d(End.x-Start.x,End.z-Start.z)
    translate Start 
  }
#end 


// The StairCase_Spiral Macro generates a spiral staircase based upon control variable settings.
// The main variables are StairCase_PostPositions which is an array that holds the positions of the newel 
// posts and StairCase_SpiralCentre which defines the position of the central vertical axis of the spiral.
// All of the control variables have default settings. The control variables are described in staircase_variables.html.  

#macro StairCase_Spiral()  

  // Default Texture Settings 
  #local StairCase_TextureSeed = seed(6);
  #ifndef(StairCase_PostPositions) #local StairCase_PostPositions = array [2] {<-1.5,0,0>,<1.5,2,0>}; #end 
  #ifndef(StairCase_NewelTexture)
    #ifndef(Clear)   #include "colors.inc" #end
    #ifndef(T_Wood1) #include "woods.inc"  #end
    #local StairCase_NewelTexture = texture {T_Wood1 scale 0.1 rotate x*90}
  #end
  #ifndef(StairCase_BalusterTexture)    #local StairCase_BalusterTexture    = texture {StairCase_NewelTexture}              #end
  #ifndef(StairCase_StringerTexture)       
    #ifndef(Clear)    #include "colors.inc" #end
    #ifndef(T_Wood30) #include "woods.inc"  #end
    #local StairCase_StringerTexture = texture {T_Wood30 scale 0.1}
  #end
  #ifndef(StairCase_RailTexture)  #local StairCase_RailTexture  = texture {StairCase_NewelTexture rotate -x*90} #end
  #ifndef(StairCase_TreadTexture) #local StairCase_TreadTexture = texture {StairCase_NewelTexture rotate -z*90} #end
  #ifndef(StairCase_RiserTexture)       
    #ifndef(Clear)    #include "colors.inc" #end
    #ifndef(T_Wood30) #include "woods.inc"  #end
    #local StairCase_RiserTexture = texture {T_Wood30 scale 0.1 rotate <90,0,90>}
  #end 

  #ifndef(StairCase_CentralCoreTexture)
    #local StairCase_CentralCoreTexture = texture {pigment {color rgb 1} normal {agate 0.1 scale 0.04}}
  #end
  
  // Default Control Variable Settings
  #ifndef(StairCase_MaxBalusterSpacing)   #local StairCase_MaxBalusterSpacing   = 0.135;   #end
  #ifndef(StairCase_MaxRiserHeight)       #local StairCase_MaxRiserHeight       = 0.190;   #end
  #ifndef(StairCase_MaxInclination)       #local StairCase_MaxInclination       = 3/4;     #end // A rise of 3 every 4 units at the outer edge
  #ifndef(StairCase_RiserCoverage)        #local StairCase_RiserCoverage        = 1;       #end // 0=No Riser, 1=Full Height Riser
  #ifndef(StairCase_HandRailHeight)       #local StairCase_HandRailHeight       = 0.920;   #end
  #ifndef(StairCase_StairsOn)             #local StairCase_StairsOn             = 1;       #end // 0=No Stairs, 1=Stairs
//  #ifndef(StairCase_StairWidth)           #local StairCase_StairWidth           = 1.4;     #end // Only used if StairCase_ConstantStairWidthOn=1
  #ifndef(StairCase_StairHandedness)      #local StairCase_StairHandedness      = 1;       #end //-1=Left, 1=Right as seen from start of stairs
  #ifndef(StairCase_MainBanisterOn)       #local StairCase_MainBanisterOn       = 1;       #end // 1=Main Hand Rail On, 0=No Main Hand Rail
  #ifndef(StairCase_PairedBanisterOn)     #local StairCase_PairedBanisterOn     = 1;       #end // 1=Paired Hand Rail On, 0=No Paired Hand Rail
  #ifndef(StairCase_CentralCoreOn)        #local StairCase_CentralCoreOn        = 1;       #end // 1=On, 0=Off
  #ifndef(StairCase_CentralCoreRadius)    #local StairCase_CentralCoreRadius    = 0.1;     #end
  #ifndef(StairCase_SpiralCentre)         #local StairCase_SpiralCentre         = <0,0,0>; #end // Only x and z have any effect
  #ifndef(StairCase_HandRailSlices)       #local StairCase_HandRailSlices       = 5;       #end // Higher numbers give a smoother hand rail
  #ifndef(StairCase_StringerSlices)       #local StairCase_StringerSlices       = 5;       #end // Higher numbers give a smoother stringer
  #ifndef(StairCase_StringerOn)           #local StairCase_StringerOn           = 1;       #end // 0=No Stringer, 1=Stringer
  #ifndef(StairCase_ConstantStairWidthOn) #local StairCase_ConstantStairWidthOn = 1;       #end // 1=Maintains a constant stair width, 0=Doesn't
  #ifndef(StairCase_BanisterInset)
    #if (StairCase_StringerOn) #local StairCase_BanisterInset  = 0;
    #else              #local StairCase_BanisterInset  = 0.02; // Inset Banister by this proportion of stair width 
    #end
  #end 
  
  // Default Stair covering, colour and texture 
  #ifndef(StairCase_StairCarpetOn)     #local StairCase_StairCarpetOn = 1;           #end
  #ifndef(StairCase_StairCarpetWidth)  #local StairCase_StairCarpetWidth = 1;        #end
  #ifndef(StairCase_StairCarpetColour) #local StairCase_StairCarpetColour = <1,1,0>; #end
  #ifndef(StairCase_StairCarpetTexture)
    #local StairCase_StairCarpetTexture = texture {pigment {color rgb StairCase_StairCarpetColour} normal{agate 0.2 scale 0.01}} 
  #end 
  
  // Default staircase components
  #ifndef(StairCase_Stringer   ) #local StairCase_Stringer    = StairCase_DefaultStringer    #end
  #ifndef(StairCase_Tread      ) #local StairCase_Tread       = StairCase_DefaultTread       #end
  #ifndef(StairCase_Riser      ) #local StairCase_Riser       = StairCase_DefaultRiser       #end
  #ifndef(StairCase_StairCarpet) #local StairCase_StairCarpet = StairCase_DefaultStairCarpet #end
  #ifndef(StairCase_HandRail   ) #local StairCase_HandRail    = StairCase_DefaultHandRail    #end
  #ifndef(StairCase_Baluster   ) #local StairCase_Baluster    = StairCase_DefaultBaluster    #end
  #ifndef(StairCase_NewelPost  ) #local StairCase_NewelPost   = StairCase_DefaultNewelPost   #end



  /*****************************/
  /*  Start Calculating Stuff  */
  /*****************************/
  // Calculate values to work out how to get from one Newel Post position to the next
  #if (StairCase_PostPositions[1].y>StairCase_PostPositions[0].y) 
    #local StairCase_FlightTop    = StairCase_PostPositions[1];
    #local StairCase_FlightBottom = StairCase_PostPositions[0];
  #else
    #local StairCase_FlightTop    = StairCase_PostPositions[0];
    #local StairCase_FlightBottom = StairCase_PostPositions[1];
  #end   
    
  #local StairCase_FlightHeight                = StairCase_FlightTop.y-StairCase_FlightBottom.y;
  #local StairCase_TopNewelRelativePosition    = StairCase_FlightTop   -StairCase_SpiralCentre; 
  #local StairCase_BottomNewelRelativePosition = StairCase_FlightBottom-StairCase_SpiralCentre;
  #local StairCase_StartOuterRadius            = vlength(StairCase_BottomNewelRelativePosition*<1,0,1>);
  #local StairCase_EndOuterRadius              = vlength(StairCase_TopNewelRelativePosition*<1,0,1>); 
  
  // Calculate the total amount to turn in the height of the stairs making sure we've got a positive value
  #local StairCase_TotalAngle = VRotationD(StairCase_BottomNewelRelativePosition*<1,0,1>,
                                           StairCase_TopNewelRelativePosition   *<1,0,1>,
                                           y*StairCase_StairHandedness);    
  #if (StairCase_TotalAngle<0) #local StairCase_TotalAngle = StairCase_TotalAngle + 360; #end

  // Adjust the number of complete turns so that the height is attained without the stairs becoming too steep
  // This uses an approximate calculation of the spiral length based on an average radius
  #local StairCase_AverageRadius = (StairCase_StartOuterRadius  + StairCase_EndOuterRadius)/2;
  #local StairCase_Circumference = 2*pi*StairCase_AverageRadius * StairCase_TotalAngle/360; 
  #while (StairCase_FlightHeight/StairCase_Circumference > StairCase_MaxInclination)   
    #local StairCase_TotalAngle = StairCase_TotalAngle + 360;
    #local StairCase_Circumference = 2*pi*StairCase_AverageRadius * StairCase_TotalAngle/360; 
  #end 
  
  // Work out how many risers we need and the angle of the arc described between one riser and the next
  #local StairCase_RiserCount  = ceil(StairCase_FlightHeight/StairCase_MaxRiserHeight);  
  #local StairCase_RisePerStep = StairCase_FlightHeight/StairCase_RiserCount;  
  // If there is only one step, it's at the start. Otherwise there's one at the start and one at the end.
  #if (StairCase_RiserCount = 1)
    #local StairCase_StepArc = StairCase_TotalAngle; 
    #local StairCase_RadiusIncreasePerStep = StairCase_EndOuterRadius - StairCase_StartOuterRadius; 
  #else
    #local StairCase_StepArc = StairCase_TotalAngle/(StairCase_RiserCount-1); 
    #local StairCase_RadiusIncreasePerStep = (StairCase_EndOuterRadius - StairCase_StartOuterRadius)/(StairCase_RiserCount-1); 
  #end

  // The inner edge of the spiral can run parallel to the outer edge or can be at a constant radius from the centre
  #if (StairCase_ConstantStairWidthOn)
    #ifndef (StairCase_StairWidth)
      #local StairCase_StairWidth = min(StairCase_StartOuterRadius,StairCase_EndOuterRadius) - StairCase_CentralCoreRadius;
    #end 
    #local StairCase_StartInnerRadius = max(0,StairCase_StartOuterRadius - StairCase_StairWidth); 
    #local StairCase_EndInnerRadius   = max(0,StairCase_EndOuterRadius   - StairCase_StairWidth); 
  #else
    #local StairCase_SegmentStartInnerRadius        = StairCase_CentralCoreRadius;
    #local StairCase_SegmentEndInnerRadius          = StairCase_CentralCoreRadius;
//    #local StairCase_InnerBanisterAverageRadius     = StairCase_CentralCoreRadius + (StairCase_BanisterInset*StairCase_StairWidth);  
    #local StairCase_StartInnerRadius               = StairCase_CentralCoreRadius; 
    #local StairCase_EndInnerRadius                 = StairCase_CentralCoreRadius; 
  #end 
  

  // For each stair we add a segment of spiral staircase, including the stair, the riser and the carpet 
  #local StairCase_Steps = union {
    #local I=0;    
    #while (I<StairCase_RiserCount)
  
      // Calculate values specific to this segment (equals one stair)
      #local StairCase_SegmentStartAngle       = StairCase_StepArc*I;    // Relative to the line between the first newel post and the centre
      #local StairCase_SegmentEndAngle         = StairCase_StepArc*(I+1);// Also relative to the line between the first newel post and the centre
      #local StairCase_SegmentStartOuterRadius = StairCase_StartOuterRadius+StairCase_RadiusIncreasePerStep*I;
      #local StairCase_SegmentEndOuterRadius   = StairCase_StartOuterRadius+StairCase_RadiusIncreasePerStep*(I+1);
  
      // If the stair width is constant, then the inner rim of the stairs will vary in radius along with the outer rim
      #if (StairCase_ConstantStairWidthOn)
        #local StairCase_SegmentStartInnerRadius    = max(0,StairCase_SegmentStartOuterRadius-StairCase_StairWidth);
        #local StairCase_SegmentEndInnerRadius      = max(0,StairCase_SegmentEndOuterRadius  -StairCase_StairWidth);
//        #local StairCase_InnerBanisterAverageRadius = (StairCase_SegmentStartInnerRadius+StairCase_SegmentEndInnerRadius)/2 + 
//                                                      (StairCase_BanisterInset*StairCase_StairWidth);
      #else   // If the edges of the stairs are not to be parallel, then work out the stair width at the start of the segment.
        #local StairCase_StairWidth = StairCase_SegmentStartOuterRadius - StairCase_CentralCoreRadius;
      #end 
  
      // Calculate the change in radius of the inner and outer spirals from the start to the end of this segment
      #local StairCase_OuterRadiusIncrement = StairCase_SegmentEndOuterRadius - StairCase_SegmentStartOuterRadius;
      #local StairCase_InnerRadiusIncrement = StairCase_SegmentEndInnerRadius - StairCase_SegmentStartInnerRadius;
      // Calculate values for each little chunk of this segment
      #local OuterRadiusDelta     = StairCase_OuterRadiusIncrement/StairCase_HandRailSlices;
      #local InnerRadiusDelta     = StairCase_InnerRadiusIncrement/StairCase_HandRailSlices;
      #local ArcDelta             = StairCase_StepArc             /StairCase_HandRailSlices;
      #local OuterRadiusStart     = StairCase_SegmentStartOuterRadius;
      #local InnerRadiusStart     = StairCase_SegmentStartInnerRadius;
  
      // Calculate the horizontal component of the length of the segment of the outer and inner spiral edges.
      #local J = 0;
      #local StairCase_OuterBanisterSegmentLength = 0; 
      #local StairCase_InnerBanisterSegmentLength = 0;
      #while (J<StairCase_HandRailSlices-1)  
        #local SliceStart = x*(OuterRadiusStart + J*OuterRadiusDelta);
        #local SliceEnd   = vrotate(x*(SliceStart + OuterRadiusDelta),y*ArcDelta);
        #local StairCase_OuterBanisterSegmentLength = StairCase_OuterBanisterSegmentLength + vlength(SliceEnd - SliceStart);
        #if (StairCase_ConstantStairWidthOn)
          #local SliceStart = x*(InnerRadiusStart+J*InnerRadiusDelta);
          #local SliceEnd   = vrotate(x*(SliceStart+InnerRadiusDelta),y*ArcDelta);
          #local StairCase_InnerBanisterSegmentLength = StairCase_InnerBanisterSegmentLength + vlength(SliceEnd - SliceStart);
        #end
        #local J = J + 1; 
      #end  
      #if (!StairCase_ConstantStairWidthOn) 
        #local SliceStart = x*(InnerRadiusStart);
        #local SliceEnd   = vrotate(x*(SliceStart),y*ArcDelta);
        #local StairCase_InnerBanisterSegmentLength = vlength(SliceEnd - SliceStart)*StairCase_HandRailSlices;
      #end
  
      // Calculate the inclination and turn required to cut straight slices of handrail that will subsequently fit together to form a spiral 
      #local Turn = asind(StairCase_OuterRadiusIncrement/StairCase_OuterBanisterSegmentLength); 
      #local Inclination = atan2d(StairCase_RisePerStep ,StairCase_OuterBanisterSegmentLength);
      #local StairCase_SpiralOuterHandRailTilt       = <-Inclination,-Turn,0>;
      #if (StairCase_InnerBanisterSegmentLength>0)
        #local Turn = asind(StairCase_InnerRadiusIncrement/StairCase_InnerBanisterSegmentLength); 
        #local Inclination = atan2d(StairCase_RisePerStep ,StairCase_InnerBanisterSegmentLength);
        #local StairCase_SpiralInnerHandRailTilt       = <-Inclination,-Turn,0>;
      #else
        #local StairCase_SpiralInnerHandRailTilt     = <-90,ArcDelta,0>;
      #end

      // Create a cutting surface for the outer edge of the stair 
      #declare StairCase_StairOuterEdgeCut = merge {  
        #local J = 0;
        #while (J<StairCase_StringerSlices)  
          plane { x,0
            rotate StairCase_SpiralOuterHandRailTilt*y 
            translate -(StairCase_SegmentStartOuterRadius+StairCase_OuterRadiusIncrement*J/StairCase_StringerSlices)*x
            rotate y*StairCase_StepArc*J/StairCase_StringerSlices 
            pigment {color rgb <J/StairCase_StringerSlices,1,1-J/StairCase_StringerSlices>}
          } 
          #local J = J + 1;
        #end
      }
      
      // Create a cutting surface for the inner edge of the stair
      #declare StairCase_StairInnerEdgeCut = intersection {  
        #local J = 0;
        #while (J<StairCase_StringerSlices)  
          plane {-x,0
            rotate StairCase_SpiralInnerHandRailTilt*y 
            translate -(StairCase_SegmentStartInnerRadius+StairCase_InnerRadiusIncrement*J/StairCase_StringerSlices)*x
            rotate y*StairCase_StepArc*J/StairCase_StringerSlices 
            pigment {color rgb <J/StairCase_StringerSlices,1,1-J/StairCase_StringerSlices>}
          } 
          #local J = J + 1;
        #end
      }
       
      // Create a cutting surface for the two sides and the back edge of the stair
      // The cutting is done before mirroring the object for a left handed staircase, so we don't need to take account of this here.
      #local StairCase_CookieCutter = union {
        plane {-z,0 rotate StairCase_StepArc*y}
        object {StairCase_StairInnerEdgeCut}
        object {StairCase_StairOuterEdgeCut}
      }
      
      
      #local CarpetInset = (StairCase_StairWidth-StairCase_StairCarpetWidth)/2;
      #local StairCase_CarpetStartOuterRadius = StairCase_SegmentStartOuterRadius - CarpetInset;
      #local StairCase_CarpetStartInnerRadius = StairCase_SegmentStartInnerRadius + CarpetInset;
      // Create a cutting surface for the outer edge of the carpet 
      #declare StairCase_CarpetOuterEdgeCut = merge {  
        #local J = 0;
        #while (J<StairCase_StringerSlices)  
          plane { x,0
            rotate StairCase_SpiralOuterHandRailTilt*y 
            translate -(StairCase_CarpetStartOuterRadius+StairCase_OuterRadiusIncrement*J/StairCase_StringerSlices)*x
            rotate y*StairCase_StepArc*J/StairCase_StringerSlices 
            pigment {color rgb <J/StairCase_StringerSlices,1,1-J/StairCase_StringerSlices>}
          } 
          #local J = J + 1;
        #end
      }
      
      // Create a cutting surface for the inner edge of the carpet
      #declare StairCase_CarpetInnerEdgeCut = intersection {  
        #local J = 0;
        #while (J<StairCase_StringerSlices)  
          plane {-x,0
            rotate StairCase_SpiralInnerHandRailTilt*y 
            translate -(StairCase_CarpetStartInnerRadius+StairCase_InnerRadiusIncrement*J/StairCase_StringerSlices)*x
            rotate y*StairCase_StepArc*J/StairCase_StringerSlices 
            pigment {color rgb <J/StairCase_StringerSlices,1,1-J/StairCase_StringerSlices>}
          } 
          #local J = J + 1;
        #end
      }
       
      // Create a cutting surface for the two sides and the back edge of the carpet
      #local StairCase_CarpetCookieCutter = union {
        plane {-z,0 rotate StairCase_StepArc*y}
        object {StairCase_CarpetInnerEdgeCut}
        object {StairCase_CarpetOuterEdgeCut}
      }




      // Here we need to start paying attention to whether it's a left handed spiral or a right handed spiral
      // The pieces of each step will be constructed in a standard location then transformed into position  
      // Define the tranformation required to move the elements corresponding to this step into position
      // For a left handed staircase we need to mirror everything
      #local StairCase_SegmentTransform = transform { 
         scale <1,1,StairCase_StairHandedness>
         Reorient_Trans (-x,StairCase_BottomNewelRelativePosition*<1,0,1>)
         rotate I*StairCase_StepArc*y*StairCase_StairHandedness 
         translate y*((I+1)*StairCase_RisePerStep + StairCase_BottomNewelRelativePosition.y)  
      } 
      
      /*************************************/
      /*  Assemble the parts of this step  */
      /*************************************/
      // Now we start to specify the components of the staircase object that will be returned by this macro.
      #if (StairCase_StairsOn)
        // Tread 
        difference {
          object {StairCase_Tread 
            scale <1,1,-1>
            translate z*0.14
            scale <2*StairCase_StairWidth,1,1>  // Need some spare on inner spiral in case it wraps around the central post
            translate -x*(max(StairCase_SegmentStartOuterRadius,StairCase_SegmentEndOuterRadius)-StairCase_StairWidth)
          }
          object {StairCase_CookieCutter}
          texture {StairCase_TreadTexture translate 1000*x*rand(StairCase_TextureSeed)}
          transform {StairCase_SegmentTransform}          
        }
        // Riser
        difference {
          object {StairCase_Riser
            scale <1,1,-1>
            translate z*0.14
            scale <2*StairCase_StairWidth,StairCase_RisePerStep*StairCase_RiserCoverage,1>  
            translate -x*(max(StairCase_SegmentStartOuterRadius,StairCase_SegmentEndOuterRadius)-StairCase_StairWidth)
          }
          object {StairCase_CookieCutter}
          texture {StairCase_RiserTexture
            translate <-20*rand(StairCase_TextureSeed),0.05+0.05*rand(StairCase_TextureSeed),0.1+0.5*rand(StairCase_TextureSeed)>
          }
          transform {StairCase_SegmentTransform}          
        }
        #if (StairCase_StairCarpetOn) 
          // Carpet
          difference {
            object {StairCase_StairCarpet
              scale <1,1,-1>
              translate z*0.14
              scale <2*StairCase_StairWidth,1,1>
              translate -x*(max(StairCase_SegmentStartOuterRadius,StairCase_SegmentEndOuterRadius)-StairCase_StairWidth)
            }
            object {StairCase_CarpetCookieCutter}
            texture {StairCase_StairCarpetTexture translate 1000*x*rand(StairCase_TextureSeed)}
            transform {StairCase_SegmentTransform}          
          }
        #end 
      #end
      #local I = I + 1;
    #end
  }


  // Work out the total number of slices to use for the whole handrail
  #if (StairCase_RiserCount<2)
    #local Slices = StairCase_HandRailSlices*StairCase_RiserCount; 
  #else 
    #local Slices = StairCase_HandRailSlices*(StairCase_RiserCount-1); 
  #end


  // Work out the start and end positions of the spirals
  #local OuterRailStart         = StairCase_BottomNewelRelativePosition + StairCase_RisePerStep*y;
  #local OuterRadiusChange      = StairCase_EndOuterRadius-StairCase_StartOuterRadius;  
  #local OuterRailPositionDelta = vnormalize(OuterRailStart)*OuterRadiusChange/Slices;
  #local OuterRailEnd           = StairCase_TopNewelRelativePosition; 

  #local InnerRailStart       = vnormalize(OuterRailStart*<1,0,1>)*StairCase_StartInnerRadius+y*OuterRailStart;
  #if (vlength(InnerRailStart*<1,0,1>)=0)
    #local InnerRailStart       = vnormalize(OuterRailStart*<1,0,1>)*0.001+y*OuterRailStart; 
  #end
  #local InnerRadiusChange      = StairCase_EndInnerRadius-StairCase_StartInnerRadius;  
  #local InnerRailPositionDelta = vnormalize(InnerRailStart)*InnerRadiusChange/Slices;
  #local InnerRailEnd           = vnormalize(OuterRailEnd*<1,0,1>)*StairCase_EndInnerRadius+y*OuterRailEnd; 
  #if (vlength(InnerRailEnd*<1,0,1>)=0)
    #local InnerRailEnd         = vnormalize(OuterRailEnd*<1,0,1>)*0.001+y*OuterRailEnd; 
  #end



  #local RailHeight             = OuterRailEnd.y-OuterRailStart.y;
  #local RailHeightDelta        = (OuterRailEnd.y-OuterRailStart.y)/Slices;
  #local RailArcDelta           = StairCase_TotalAngle/Slices;

//#debug concat("StairCase_BottomNewelRelativePosition",vstr(3,StairCase_BottomNewelRelativePosition,",",3,12),"\n")
//#debug concat("StairCase_RisePerStep",str(StairCase_RisePerStep,3,12),"\n")
//#debug concat("OuterRailStart",vstr(3,OuterRailStart,",",3,12),"\n")
//
//#debug concat("OuterRailEnd",vstr(3,OuterRailEnd,",",3,12),"\n")
//#debug concat("RailHeight",str(RailHeight,3,12),"\n")


  /********************/
  /*  Final Assembly  */
  /********************/
  #local StairCase_Object = union {
    // Add the bottom outer newel post
    #if (StairCase_MainBanisterOn)
      object {StairCase_NewelPost
        translate -y*0.08
        scale <1,1.05,1>
        texture {StairCase_NewelTexture
          translate <0.05+0.05*rand(StairCase_TextureSeed),20*rand(StairCase_TextureSeed),0.1+0.5*rand(StairCase_TextureSeed)>
        }
        Reorient_Trans (x,OuterRailStart*<1,0,1>)
        translate OuterRailStart
      } 
      // The top outer newel post
      object {StairCase_NewelPost 
        translate -y*0.08
        scale <1,1.05,1>
        texture {StairCase_NewelTexture
          translate <0.05+0.05*rand(StairCase_TextureSeed),20*rand(StairCase_TextureSeed),0.1+0.5*rand(StairCase_TextureSeed)>
        }
        Reorient_Trans (x,OuterRailEnd*<1,0,1>)
        translate OuterRailEnd
      }
      //  Create the main banister (the outer banister)
      union {
        StairCase_SpiralBannisterGen(OuterRailStart, RailHeight, OuterRailPositionDelta, StairCase_StartOuterRadius,StairCase_EndOuterRadius)
        translate -0.05*y
      }
    #end
    
    #if (StairCase_PairedBanisterOn)
      // Add the bottom inner newel post
      object {StairCase_NewelPost
        translate -y*0.08
        scale <1,1.05,1>
        texture {StairCase_NewelTexture
          translate <0.05+0.05*rand(StairCase_TextureSeed),20*rand(StairCase_TextureSeed),0.1+0.5*rand(StairCase_TextureSeed)>
        }
        Reorient_Trans (x,InnerRailStart*<1,0,1>)
        translate InnerRailStart
      } 
      // The top inner newel post
      object {StairCase_NewelPost 
        translate -y*0.08
        scale <1,1.05,1>
        texture {StairCase_NewelTexture
          translate <0.05+0.05*rand(StairCase_TextureSeed),20*rand(StairCase_TextureSeed),0.1+0.5*rand(StairCase_TextureSeed)>
        }
        Reorient_Trans (x,InnerRailEnd*<1,0,1>)
        translate InnerRailEnd
      }
      //  Create the paired banister (the inner banister)
      union {
        StairCase_SpiralBannisterGen(InnerRailStart, RailHeight, InnerRailPositionDelta, StairCase_StartInnerRadius,StairCase_EndInnerRadius)
        translate -0.05*y
      }
    #end
  
  
    #if (StairCase_CentralCoreOn)
      cylinder {0,y+y*StairCase_FlightHeight,StairCase_CentralCoreRadius texture {StairCase_CentralCoreTexture}}
    #end
    
    object {StairCase_Steps}
  }

//object {StairCase_CookieCutter clipped_by{plane {y,0.2}} pigment {rgb 1}}
object {StairCase_Object translate StairCase_SpiralCentre}
  
#end
 
 
// The StairCase_SpiralBannisterGen macro is used by the StairCase_Spiral macro to define the banister rail that connects two newel posts.
// Certain variables must be set before this macro is called. This macro is not intended to be called directly from 
// a scene file.
#macro StairCase_SpiralBannisterGen(Start, Height, PositionDelta, StartRadius, EndRadius) 

//#debug concat (vstr(3,Start,",",3,8)," ",vstr(3,Height,",",3,8)," ",vstr(3,PositionDelta,",",3,8)," ",str(StartRadius,3,8)," ",str(EndRadius,3,8)," ","\n")
 
  // Cut slices of handrail to form a spiral 

  #if (StairCase_RiserCount<2)
    #local Slices = StairCase_HandRailSlices*StairCase_RiserCount;
  #else
    #local Slices = StairCase_HandRailSlices*(StairCase_RiserCount-1);
  #end
  #local I=0;    
  #local LowerLimit = min_extent(StairCase_HandRail).y+Start.y;
  #local UpperLimit = max_extent(StairCase_HandRail).y+Start.y+Height;
  #while (I<Slices)
    #local SliceStart = vrotate(
      Start+vnormalize(Start*<1,0,1>)*( I   *(EndRadius-StartRadius)/Slices),
      y*I*StairCase_StairHandedness*StairCase_TotalAngle/Slices
      )+y*I*Height/Slices; 
      
    #local SliceEnd   = vrotate(
      Start+vnormalize(Start*<1,0,1>)*((I+1)*(EndRadius-StartRadius)/Slices),
      y*(I+1)*StairCase_StairHandedness*StairCase_TotalAngle/Slices
      )+y*(I+1)*Height/Slices; 
    #if (mod(I,StairCase_HandRailSlices)=0) // We don't want to change the texture with every slice
      #local SegmentTexture = texture {StairCase_RailTexture
        translate <0.4*rand(StairCase_TextureSeed),-0.4-0.5*StairCase_TextureSeed,30*rand(StairCase_TextureSeed)>
        Reorient_Trans(z,(SliceEnd-SliceStart)*<1,0,1>)                    // Horizontal reorientation
        Reorient_Trans((SliceEnd-SliceStart)*<1,0,1>,SliceEnd-SliceStart)  // Tilt
        translate (SliceEnd+SliceStart)/2
      }  
    #end
    difference {
      object { StairCase_HandRail
        translate -z*0.5
        Reorient_Trans(z,(SliceEnd-SliceStart)*<1,0,1>)                    // Horizontal reorientation
        Reorient_Trans((SliceEnd-SliceStart)*<1,0,1>,SliceEnd-SliceStart)  // Tilt
        translate (SliceEnd+SliceStart)/2
      } 
      plane { StairCase_StairHandedness*z,0 Reorient_Trans(-x,Start*<1,0,1>) rotate y*StairCase_StairHandedness*I    *StairCase_TotalAngle/Slices}
      plane {-StairCase_StairHandedness*z,0 Reorient_Trans(-x,Start*<1,0,1>) rotate y*StairCase_StairHandedness*(I+1)*StairCase_TotalAngle/Slices}
      plane { y, LowerLimit} 
      plane {-y,-UpperLimit}
      texture {SegmentTexture}
      translate y*StairCase_HandRailHeight
    }
    #local I = I + 1;
  #end
  
  // Cut slices of stringer to form a spiral  
  #if (StairCase_StringerOn)
    #local Slices = StairCase_StringerSlices*StairCase_RiserCount;
    #local I=0;    
    #local LowerLimit = min_extent(StairCase_Stringer).y+Start.y;        
    #local UpperLimit = max_extent(StairCase_Stringer).y+Start.y+Height; 
    #while (I<Slices) 
      #local SliceStart = vrotate(
        Start+vnormalize(Start*<1,0,1>)*(I*(EndRadius-StartRadius)/Slices),
        y*I*StairCase_StairHandedness*StairCase_TotalAngle/Slices
        )+y*I*Height/Slices;
      #local SliceEnd   = vrotate(
        Start+vnormalize(Start*<1,0,1>)*((I+1)*(EndRadius-StartRadius)/Slices),
        y*(I+1)*StairCase_StairHandedness*StairCase_TotalAngle/Slices
        )+y*(I+1)*Height/Slices; 
      #if (mod(I,StairCase_StringerSlices)=0) // We don't want to change the texture with every slice
        #local SegmentTexture = texture {StairCase_StringerTexture 
          translate <0.2,-0.5,30*rand(StairCase_TextureSeed)>
          Reorient_Trans(z,(SliceEnd-SliceStart)*<1,0,1>)                    // Horizontal reorientation
          Reorient_Trans((SliceEnd-SliceStart)*<1,0,1>,SliceEnd-SliceStart)  // Tilt
          translate (SliceEnd+SliceStart)/2
        }  
      #end  
      
      difference {
        object { StairCase_Stringer
          translate -z*0.5
          Reorient_Trans(z,(SliceEnd-SliceStart)*<1,0,1>)                    // Horizontal reorientation
          Reorient_Trans((SliceEnd-SliceStart)*<1,0,1>,SliceEnd-SliceStart)  // Tilt
          translate (SliceEnd+SliceStart)/2
        } 
        plane { StairCase_StairHandedness*z,0 Reorient_Trans(-x,Start*<1,0,1>) rotate y*StairCase_StairHandedness*I    *StairCase_TotalAngle/Slices}
        plane {-StairCase_StairHandedness*z,0 Reorient_Trans(-x,Start*<1,0,1>) rotate y*StairCase_StairHandedness*(I+1)*StairCase_TotalAngle/Slices}
        plane { y, LowerLimit}
        plane {-y,-UpperLimit}
        texture {SegmentTexture}
      }
    
      #local I = I + 1;
    #end 
  #end

  // Calculate the length of the rail
  #local RailLength   = 0;
  #local I=0;    
  #while (I<Slices) 
    #local SliceStart = vrotate(Start*<1,0,1>+    I*PositionDelta, y*I    *RailArcDelta);
    #local SliceEnd   = vrotate(Start*<1,0,1>+(I+1)*PositionDelta, y*(I+1)*RailArcDelta) + y*RailHeightDelta; 
    #local RailLength = RailLength+vlength(SliceEnd-SliceStart);
    #local I = I + 1;
  #end 

  // Add Balusters
  #local BalusterCount = int(RailLength/StairCase_MaxBalusterSpacing)+1;
  #local I=1;    
  #while (I<BalusterCount) 
    #local ThisPosition = vrotate(
      Start+vnormalize(Start*<1,0,1>)*( I   *(EndRadius-StartRadius)/BalusterCount),
      y* I   *StairCase_StairHandedness*StairCase_TotalAngle/BalusterCount
      )+y* I   *Height/BalusterCount;
    #local NextPosition = vrotate(
      Start+vnormalize(Start*<1,0,1>)*((I+1)*(EndRadius-StartRadius)/BalusterCount),
      y*(I+1)*StairCase_StairHandedness*StairCase_TotalAngle/BalusterCount
      )+y*(I+1)*Height/BalusterCount;
    difference {
      object {StairCase_Baluster
        #if (StairCase_StringerOn=0) translate -0.1*y #end
      } 
      // Trim the bottom of the banuster
      #if (StairCase_StringerOn)  
        plane {y,0                 
          Reorient_Trans(z,<0,NextPosition.y-ThisPosition.y,vlength((NextPosition-ThisPosition)*<1,0,1>)>) // Tilt
          translate -y*0.01        // Add a little bit to make sure there's not a little gap between the Baluster and the Toe Rail
        }
      #else plane {y,0}    
      #end
      // Trim the top of the banuster
      plane {-y,0
        Reorient_Trans(z,<0,NextPosition.y-ThisPosition.y,vlength((NextPosition-ThisPosition)*<1,0,1>)>) // Tilt
        translate y*(StairCase_HandRailHeight+0.01)  // Add a little bit to make sure there's not a little gap between the Baluster and the Hand Rail
      }
      texture {StairCase_BalusterTexture  translate y*30*rand(StairCase_TextureSeed)}
      Reorient_Trans(z,(NextPosition-ThisPosition)*<1,0,1>)                    // Horizontal reorientation
      translate ThisPosition
    }


    #local I = I + 1;
  #end



#end



// The following object definitions are used by default to construct a staircase. 
// You would not normally need to alter these defaults. To override the defaults you can set user defined objects using the 
// control variables exposed for that purpose. So, for example, instead of modifying the StairCase_DefaultNewelPost object here you can 
// simply declare the obect StairCase_NewelPost in your scene file or in a separate include file prior to calling the StairCase macro.
// If the StairCase_NewelPost is defined, the StairCase macro will use that in place of StairCase_DefaultNewelPost. 

// Default Newel Post
/* Set the control points to be used to generate the Newel Posts at the ends of the hand rails. */ 
#local ProfilePoints = 30;
#local LatheArray = array[ProfilePoints] {
  <0.040,  1.10 >, 
  
  <0.020,  0.920>,
  <0.038,  0.90 >,   
                 
  <0.020,  0.897>,   // Top square section
  <0.075,  0.85 >,
  <0.075,  0.75 >,
  <0.020,  0.70 >, 
                 
  <0.038,  0.695>,
  <0.020,  0.690>,
  <0.038,  0.688>,
  <0.020,  0.660>,
  <0.038,  0.655>,
  <0.025,  0.650>, 
                 
  <0.042,  0.40> ,
  <0.030,  0.38> ,
  <0.030,  0.38> ,
  <0.042,  0.37> ,
  <0.042,  0.37> ,
  <0.030,  0.35> ,
  <0.042,  0.25> ,
  <0.030,  0.245>,
  <0.030,  0.245>,
  <0.042,  0.240>,
  <0.030,  0.235>, 
                 
  <0.010,  0.235>,   // Lower square section
  <0.075,  0.19> ,
  <0.075, -0.05> ,
  <0.075, -0.10> , 
  <0.075, -0.30> , 
                 
  <0.000, -0.30> 
}  

#local LatheCut = lathe {
  cubic_spline
  ProfilePoints,
  #local I = 0;
  #while (I < ProfilePoints-1)  
    LatheArray[I],
    #local I = I+1; 
  #end
  LatheArray[I]
}

#declare StairCase_DefaultNewelPost = union {
  intersection {          
    box { 
      <-0.041, -0.2, -0.041>
      < 0.041,  1,  0.041>
    }
    object {LatheCut}
  }    
  sphere {<0,0.95,0>,0.041}
  translate y*0.135  
}

// Default Baluster
/* Set the control points to be used to generate the balusters beneath the hand rail.*/
#local ProfilePoints = 31;
#local LatheArray = array[ProfilePoints] {
  <0.035,  1.10 >,   // Top square section
  <0.035,  1.10 >,   
  <0.035,  0.80 >,
  <0.010,  0.75 >, 
                 
  <0.010,  0.75 >, 
  <0.015,  0.747>,
  <0.010,  0.744>, 
                 
  <0.010,  0.744>, 
  <0.015,  0.730>,
  <0.011,  0.710>,
  <0.010,  0.700>, 
                 
  <0.010,  0.700>, 
  <0.015,  0.697>,
  <0.010,  0.694>, 
                 
  <0.010,  0.694>,
  <0.015,  0.55 >,    // Middle Bulge
  <0.010,  0.406>,  
                 
  <0.010,  0.406>,
  <0.015,  0.403>,
  <0.010,  0.400>,
                 
  <0.010,  0.400>,
  <0.011,  0.390>,
  <0.015,  0.370>,
  <0.010,  0.356>,
                 
  <0.010,  0.356>, 
  <0.015,  0.353>, 
  <0.010,  0.35 >,   
                 
  <0.010,  0.35 >,   // Lower square section
  <0.035,  0.30 >, 
  <0.035,  0.00 >,
  <0.035, -0.10 >
}

#local LatheCut = lathe {
  cubic_spline
  ProfilePoints,
  #local I = 0;
  #while (I < ProfilePoints-1)  
    LatheArray[I],
    #local I = I+1; 
  #end
  LatheArray[I]
}

#declare StairCase_DefaultBaluster = intersection {          
  box { 
    <-0.015, -0, -0.015> 
    < 0.015,  1.1,  0.015> 
  }
  object {LatheCut}
  translate -y*0.03
}    
 
// Default Hand Rail
/* Set the control points to be used to generate the hand rail.*/
#local ProfilePoints = 9;
#local PrismArray = array[ProfilePoints] {
  <0.0180, 0.006>, 
  <0.0180, 0.000>,   
  <0.0300, 0.000>,
             
  <0.0320, 0.005>, 
  <0.0305, 0.012>, 
  <0.0230, 0.019>,
             
  <0.0300, 0.035>, 
  <0.0300, 0.042>, 
  <0.0200, 0.053>
}

#declare StairCase_DefaultHandRail = prism {
  cubic_spline
  0,1,ProfilePoints*2+3,
  #local I = 0;
  <-PrismArray[I].x,PrismArray[I].y>,
  #while (I < ProfilePoints)  
    <PrismArray[I].x,PrismArray[I].y>,
    #local I = I+1; 
  #end
  #local I = ProfilePoints-1;
  #while (I > 0)  
    <-PrismArray[I].x,PrismArray[I].y>,
    #local I = I-1; 
  #end
  <-PrismArray[I].x,PrismArray[I].y>,
  <PrismArray[I].x,PrismArray[I].y>,
  #local I = I+1; 
  <PrismArray[I].x,PrismArray[I].y>
  rotate <-90,180,0>
}

// Default ShoeRail
/* Set the control points to be used to generate the hand rail.*/
#local ProfilePoints = 12;
#local PrismArray = array[ProfilePoints] {
  <0.016, 0.027>, 
  <0.017, 0.027>,   
  <0.017, 0.025>,
             
  <0.018, 0.025>, 
  <0.023, 0.025>,   
  <0.029, 0.023>,
             
  <0.030, 0.018>, 
  <0.032, 0.017>, 
  <0.032, 0.015>,
             
  <0.032, 0.001>, 
  <0.032, 0.000>, 
  <0.031, 0.000>
}
#local ShoeRail = prism {
  cubic_spline
  0,1,ProfilePoints*2+3,
  #local I = 0;
  <-PrismArray[I].x,PrismArray[I].y>,
  #while (I < ProfilePoints)  
    <PrismArray[I].x,PrismArray[I].y>,
    #local I = I+1; 
  #end
  #local I = ProfilePoints-1;
  #while (I > 0)  
    <-PrismArray[I].x,PrismArray[I].y>,
    #local I = I-1; 
  #end
  <-PrismArray[I].x,PrismArray[I].y>,
  <PrismArray[I].x,PrismArray[I].y>,
  #local I = I+1; 
  <PrismArray[I].x,PrismArray[I].y>
  rotate <-90,180,0>
}

// Default Stringer
#declare StairCase_DefaultStringer = union {
  box {<-0.0175,-0.20,-0.08><0.0175,0.05,1.08>} 
  object {ShoeRail translate y*0.05 scale <1,1,1.16> translate -0.08*z}
  translate y*0.06  
}

// Default Tread
#declare StairCase_DefaultTread = union {
  box {<0,-0.018,-1.00><1,0,0.15>} 
  cylinder {<0,-0.009,0.15><1,-0.009,0.15>,0.009}
  translate -0.5*x 
}

// Default Riser
#declare StairCase_DefaultRiser = box {<0,-1,0.122><1,-0.001,0.13> translate -0.5*x}  

// Default Carpet
#local ProfilePoints = 22;
#local PrismArray = array[ProfilePoints] {
  <-0.005,-1.002>, 
  <-0.005,-1.000>,   
  <-0.005,-0.350>,   
  <-0.005,-0.200>,   
  <-0.005, 0.050>,

  <-0.004, 0.150>,
  < 0.030, 0.170>,
  < 0.080, 0.135>,

  < 0.190, 0.135>,
  < 0.191, 0.135>,
  < 0.191, 0.134>,

  < 0.191, 0.130>,
  < 0.080, 0.130>,
  < 0.030, 0.165>,

  < 0.001, 0.145>,
  < 0.000, 0.050>,
  < 0.000,-0.152>, 

  < 0.000,-0.200>,   
  < 0.000,-0.350>,   
  <-0.005,-1.002>, 
  <-0.005,-1.000>,   
  <-0.005,-0.050>
}

#declare StairCase_DefaultStairCarpet = prism {
  cubic_spline
  0,1,ProfilePoints,
  #local I = 0;
  #while (I < ProfilePoints-1)  
    <PrismArray[I].x,PrismArray[I].y>,
    #local I = I+1; 
  #end 
  <PrismArray[I].x,PrismArray[I].y> 
  rotate -z*90
  translate -0.5*x
}


// This macro resets any control variables that have been set. This essentially re-initialises
// settings so that they will revert to their default values the next time the staircase macros
// are called.
#macro StairCase_Undef()

  // Main Control Variables
  #ifdef(StairCase_PostPositions       ) #undef StairCase_PostPositions        #end 
  #ifdef(StairCase_StairWidth          ) #undef StairCase_StairWidth           #end
  #ifdef(StairCase_StairCarpetWidth    ) #undef StairCase_StairCarpetWidth     #end
  #ifdef(StairCase_StairHandedness     ) #undef StairCase_StairHandedness      #end
  #ifdef(StairCase_HandRailHeight      ) #undef StairCase_HandRailHeight       #end
  #ifdef(StairCase_MaxBalusterSpacing  ) #undef StairCase_MaxBalusterSpacing   #end
  #ifdef(StairCase_MaxRiserHeight      ) #undef StairCase_MaxRiserHeight       #end
  #ifdef(StairCase_LandingThreshold    ) #undef StairCase_LandingThreshold     #end
  #ifdef(StairCase_RiserCoverage       ) #undef StairCase_RiserCoverage        #end
  #ifdef(StairCase_MaxInclination      ) #undef StairCase_MaxInclination       #end
  #ifdef(StairCase_SpiralCentre        ) #undef StairCase_SpiralCentre         #end
  #ifdef(StairCase_CentralCoreRadius   ) #undef StairCase_CentralCoreRadius    #end
                              
  // Control Switches              
  #ifdef(StairCase_StairsOn            ) #undef StairCase_StairsOn             #end
  #ifdef(StairCase_LandingsOn          ) #undef StairCase_LandingsOn           #end
  #ifdef(StairCase_StairCarpetOn       ) #undef StairCase_StairCarpetOn        #end
  #ifdef(StairCase_MainBanisterOn      ) #undef StairCase_MainBanisterOn       #end
  #ifdef(StairCase_PairedBanisterOn    ) #undef StairCase_PairedBanisterOn     #end
  #ifdef(StairCase_CentralCoreOn       ) #undef StairCase_CentralCoreOn        #end
  #ifdef(StairCase_ConstantStairWidthOn) #undef StairCase_ConstantStairWidthOn #end
                              
  // Object Definitions            
  #ifdef(StairCase_NewelPost           ) #undef StairCase_NewelPost            #end
  #ifdef(StairCase_Baluster            ) #undef StairCase_Baluster             #end
  #ifdef(StairCase_HandRail            ) #undef StairCase_HandRail             #end
  #ifdef(StairCase_Stringer            ) #undef StairCase_Stringer             #end
  #ifdef(StairCase_Tread               ) #undef StairCase_Tread                #end
  #ifdef(StairCase_Riser               ) #undef StairCase_Riser                #end
  #ifdef(StairCase_StairCarpet         ) #undef StairCase_StairCarpet          #end
                              
  // Textures                      
  #ifdef(StairCase_NewelTexture        ) #undef StairCase_NewelTexture         #end
  #ifdef(StairCase_BalusterTexture     ) #undef StairCase_BalusterTexture      #end
  #ifdef(StairCase_StringerTexture     ) #undef StairCase_StringerTexture      #end
  #ifdef(StairCase_RailTexture         ) #undef StairCase_RailTexture          #end
  #ifdef(StairCase_TreadTexture        ) #undef StairCase_TreadTexture         #end
  #ifdef(StairCase_RiserTexture        ) #undef StairCase_RiserTexture         #end
  #ifdef(StairCase_StairCarpetTexture  ) #undef StairCase_StairCarpetTexture   #end
  #ifdef(StairCase_StairCarpetColour   ) #undef StairCase_StairCarpetColour    #end
  #ifdef(StairCase_CentralCoreTexture  ) #undef StairCase_CentralCoreTexture   #end

#end        

#macro StairCase_Compatibility()
  // Main Control Variables
  #ifndef(StairCase_PostPositions       ) #ifdef(SCPostPositions     ) #declare StairCase_PostPositions      = SCPostPositions     ; #end #end
  #ifndef(StairCase_StairWidth          ) #ifdef(SCStairWidth        ) #declare StairCase_StairWidth         = SCStairWidth        ; #end #end
  #ifndef(StairCase_StairCarpetWidth    ) #ifdef(SCStairCarpetWidth  ) #declare StairCase_StairCarpetWidth   = SCStairCarpetWidth  ; #end #end
  #ifndef(StairCase_StairHandedness     ) #ifdef(SCStairHandedness   ) #declare StairCase_StairHandedness    = SCStairHandedness   ; #end #end
  #ifndef(StairCase_HandRailHeight      ) #ifdef(SCHandRailHeight    ) #declare StairCase_HandRailHeight     = SCHandRailHeight    ; #end #end
  #ifndef(StairCase_MaxBalusterSpacing  ) #ifdef(SCMaxBalusterSpacing) #declare StairCase_MaxBalusterSpacing = SCMaxBalusterSpacing; #end #end
  #ifndef(StairCase_MaxRiserHeight      ) #ifdef(SCMaxRiserHeight    ) #declare StairCase_MaxRiserHeight     = SCMaxRiserHeight    ; #end #end
  #ifndef(StairCase_LandingThreshold    ) #ifdef(SCLandingThreshold  ) #declare StairCase_LandingThreshold   = SCLandingThreshold  ; #end #end
  #ifndef(StairCase_RiserCoverage       ) #ifdef(SCRiserCoverage     ) #declare StairCase_RiserCoverage      = SCRiserCoverage     ; #end #end
                                                                                                      
  // Control Switches              
  #ifndef(StairCase_StairsOn            ) #ifdef(SCStairsOn          ) #declare StairCase_StairsOn           = SCStairsOn          ; #end #end
  #ifndef(StairCase_LandingsOn          ) #ifdef(SCLandingsOn        ) #declare StairCase_LandingsOn         = SCLandingsOn        ; #end #end
  #ifndef(StairCase_StairCarpetOn       ) #ifdef(SCStairCarpetOn     ) #declare StairCase_StairCarpetOn      = SCStairCarpetOn     ; #end #end
  #ifndef(StairCase_MainBanisterOn      ) #ifdef(SCMainBanisterOn    ) #declare StairCase_MainBanisterOn     = SCMainBanisterOn    ; #end #end
  #ifndef(StairCase_PairedBanisterOn    ) #ifdef(SCPairedBanisterOn  ) #declare StairCase_PairedBanisterOn   = SCPairedBanisterOn  ; #end #end

  // Object Definitions            
  #ifndef(StairCase_NewelPost           ) #ifdef(SCNewelPost         ) #declare StairCase_NewelPost          = SCNewelPost         ; #end #end
  #ifndef(StairCase_Baluster            ) #ifdef(SCBaluster          ) #declare StairCase_Baluster           = SCBaluster          ; #end #end
  #ifndef(StairCase_HandRail            ) #ifdef(SCHandRail          ) #declare StairCase_HandRail           = SCHandRail          ; #end #end
  #ifndef(StairCase_Stringer            ) #ifdef(SCStringer          ) #declare StairCase_Stringer           = SCStringer          ; #end #end
  #ifndef(StairCase_Tread               ) #ifdef(SCTread             ) #declare StairCase_Tread              = SCTread             ; #end #end
  #ifndef(StairCase_Riser               ) #ifdef(SCRiser             ) #declare StairCase_Riser              = SCRiser             ; #end #end
  #ifndef(StairCase_StairCarpet         ) #ifdef(SCStairCarpet       ) #declare StairCase_StairCarpet        = SCStairCarpet       ; #end #end
                              
  // Textures                      
  #ifndef(StairCase_NewelTexture        ) #ifdef(SCNewelTexture      ) #declare StairCase_NewelTexture       = SCNewelTexture      ; #end #end
  #ifndef(StairCase_BalusterTexture     ) #ifdef(SCBalusterTexture   ) #declare StairCase_BalusterTexture    = SCBalusterTexture   ; #end #end
  #ifndef(StairCase_StringerTexture     ) #ifdef(SCStringerTexture   ) #declare StairCase_StringerTexture    = SCStringerTexture   ; #end #end
  #ifndef(StairCase_RailTexture         ) #ifdef(SCRailTexture       ) #declare StairCase_RailTexture        = SCRailTexture       ; #end #end
  #ifndef(StairCase_TreadTexture        ) #ifdef(SCTreadTexture      ) #declare StairCase_TreadTexture       = SCTreadTexture      ; #end #end
  #ifndef(StairCase_RiserTexture        ) #ifdef(SCRiserTexture      ) #declare StairCase_RiserTexture       = SCRiserTexture      ; #end #end
  #ifndef(StairCase_StairCarpetTexture  ) #ifdef(SCStairCarpetTexture) #declare StairCase_StairCarpetTexture = SCStairCarpetTexture; #end #end
//  #ifndef(StairCase_StairCarpetColour   ) #ifdef() #declare StairCase_StairCarpetColour    #end

#end