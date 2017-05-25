//
// herschel.inc
// ------------
// Created by Chris Walker 2001  
// Adapted to go into the POV-Ray Object Collection Sept 2009 by Chris Bartlett
// This include file adds a 40ft telescope to your scene. 
//
// Although Heschel made over 300 telescopes, this was the largest, measuring 40 ft.
// Other telescopes and many other astronomical features have been named after him in 
// recognition of his achievements.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 0.5 metres
//
// Adding this model to your scene is likely to add a few seconds to the render time.
//
// See herschel.html for more details.


union {
  #declare Herschel_RopeMaterial   = material {texture {pigment {rgb 0.7*<1,0.96,0.6>}}}
  #declare Herschel_BlockMaterial  = material {texture {pigment {rgb 0.2*<0.5,0.1,0.1>}}}
  #declare Herschel_WheelMaterial  = material {texture {pigment {rgb 0.1*<0.2,0.1,0.05>}}}
  #declare Herschel_RungMaterial   = material {texture {pigment {wood scale 0.01 turbulence 0.01}}}
  #declare Herschel_LadderMaterial = material {texture {pigment {wood scale 0.01 turbulence 0.01}}}
//  #declare Herschel_RungMaterial   = material {texture {pigment {rgb <1,0,0>}}}
//  #declare Herschel_LadderMaterial = material {texture {pigment {rgb <1,0,0>}}}
  #declare Herschel_FrameMaterial  = material {texture {pigment {wood scale 0.01 turbulence 0.05}}}
//  #declare Herschel_FrameMaterial  = material {texture {pigment {rgb <1,1,0>}}}
  #declare Herschel_CasingMaterial = material {texture {pigment {rgb 0.8} finish {reflection 0.1 phong 0.2}}}
  #declare Herschel_BaseMaterial   = material {texture {pigment {rgb 0.8} normal {agate scale 0.1}}}
  
  #declare Herschel_RandomStream = seed(0);
  
  #macro Herschel_LongLadder(Herschel_LadderRungs) 
    union {
      #declare Herschel_YCount=0;
      #while (Herschel_YCount < Herschel_LadderRungs)
        cylinder {
          <0,0,0>, 
          <0,0,1>,0.1
          material{Herschel_RungMaterial translate <0.2*rand(Herschel_RandomStream),0.2*rand(Herschel_RandomStream),1000*rand(Herschel_RandomStream)>} 
          translate <10-Herschel_YCount*10/Herschel_LadderRungs, Herschel_YCount*20/Herschel_LadderRungs, 0>
        }
        #declare Herschel_YCount=Herschel_YCount+1;
      #end
      cylinder { <10, 0, 0>, <-0.5, 21, 0> 0.1 material{Herschel_LadderMaterial}}
      cylinder { <10, 0, 1>, <-0.5, 21, 1> 0.1 material{Herschel_LadderMaterial}}
    }
  #end
  
  #declare Herschel_Ladder1 = Herschel_LongLadder(54)
  #declare Herschel_Ladder2 = object {Herschel_LongLadder(18) translate z}
  #declare Herschel_Ladder3 = object {Herschel_LongLadder(18) translate -z rotate 180*y}
  
  
  #declare Herschel_Ladder4 = union {
    #declare Herschel_YCount=0;
    #while (Herschel_YCount < 10)
      cylinder {
        <0+Herschel_YCount*5/10, Herschel_YCount*10/10, 0>, 
        <0+Herschel_YCount*5/10, Herschel_YCount*10/10, 1>,0.1
        material{Herschel_RungMaterial}
      }
      #declare Herschel_YCount=Herschel_YCount+1;
    #end
    cylinder { <0, 0, 0>, <5, 10, 0> 0.1 material{Herschel_LadderMaterial}}
    cylinder { <0, 0, 1>, <5, 10, 1> 0.1 material{Herschel_LadderMaterial}}
  }
  
  #declare Herschel_Ladder5 = union {
    #declare Herschel_YCount=0;
    #while (Herschel_YCount < 10)
      cylinder { 
        <0-Herschel_YCount*5/10, Herschel_YCount*10/10, 0>, 
        <0-Herschel_YCount*5/10, Herschel_YCount*10/10, 1>,0.1
        material{Herschel_RungMaterial}
      }
      #declare Herschel_YCount=Herschel_YCount+1;
    #end
    cylinder { <0, 0, 0>, <-5, 10, 0> 0.1 material{Herschel_LadderMaterial}}
    cylinder { <0, 0, 1>, <-5, 10, 1> 0.1 material{Herschel_LadderMaterial}}
  }
  
  
  object { Herschel_Ladder1}
  object { Herschel_Ladder1 translate z*9}
  
  object { Herschel_Ladder2}
  object { Herschel_Ladder2 translate z*7}
  
  object { Herschel_Ladder3}
  object { Herschel_Ladder3 translate z*1}
  object { Herschel_Ladder3 translate z*8}
  object { Herschel_Ladder3 translate z*9}
  
  object { Herschel_Ladder4}
  object { Herschel_Ladder4 translate z*1}
  object { Herschel_Ladder4 translate z*8}
  object { Herschel_Ladder4 translate z*9}
  
  object { Herschel_Ladder5}
  object { Herschel_Ladder5 translate z*1}
  object { Herschel_Ladder5 translate z*8}
  object { Herschel_Ladder5 translate z*9}
  
  // Top bar
  cylinder { <0, 20, 0>, <0, 20, 10> 0.2 material {Herschel_FrameMaterial translate 20*y}}
      
  // Back braces
  cylinder { <-5, 10, 0>, <0, 20, 10> 0.2 material {Herschel_FrameMaterial rotate <60,0,-40> translate <0,15,5>}}
  cylinder { <-5, 10, 10>, <0, 20, 0> 0.2 material {Herschel_FrameMaterial rotate <60,0,-40> translate <0,15,5>}}
  
  #declare Herschel_Platform_Side = union {
    cylinder { <0  , 0, 0>, <0  , 2, 0> 0.1}
    cylinder { <0.3, 0, 0>, <0.3, 2, 0> 0.1}
    cylinder { <0.6, 0, 0>, <0.6, 2, 0> 0.1}
    cylinder { <0.9, 0, 0>, <0.9, 2, 0> 0.1}
    cylinder { <1.2, 0, 0>, <1.2, 2, 0> 0.1}
    cylinder { <1.5, 0, 0>, <1.5, 2, 0> 0.1}
    cylinder { <1.8, 0, 0>, <1.8, 2, 0> 0.1}
    cylinder { <2.1, 0, 0>, <2.1, 2, 0> 0.1}
    cylinder { <0  , 2, 0>, <2.1, 2, 0> 0.1}
  }
      
  #declare Herschel_Platform_1 = union {
    cylinder { <0, 0, 0.666>, <0, 2, 0.666> 0.1}
    cylinder { <0, 0, 1.333>, <0, 2, 1.333> 0.1}
    cylinder { <0, 0, 2    >, <0, 2, 2    > 0.1}
    cylinder { <0, 0, 2.666>, <0, 2, 2.666> 0.1}
    cylinder { <0, 0, 3.333>, <0, 2, 3.333> 0.1}
    cylinder { <0, 0, 4    >, <0, 2, 4    > 0.1}
    cylinder { <0, 0, 4.666>, <0, 2, 4.666> 0.1}
    cylinder { <0, 0, 5.333>, <0, 2, 5.333> 0.1}
    cylinder { <0, 0, 6    >, <0, 2, 6    > 0.1}
    cylinder { <0, 0, 6.666>, <0, 2, 6.666> 0.1}
    cylinder { <0, 0, 7.333>, <0, 2, 7.333> 0.1}
    cylinder { <0, 0, 8    >, <0, 2, 8    > 0.1}
    cylinder { <0, 2, 0    >, <0, 2, 8    > 0.1}
  }
  
  #declare Herschel_Platform_Base = box { <0,0,0>, <2.1,0.1,8>}
      
  #declare Herschel_Platform_Strut1 = cylinder {<1, 0, 0>, <0.5, -1.0, 0> 0.1}
  #declare Herschel_Platform_Strut2 = cylinder {<2, 0, 0>, <1  , -2  , 0> 0.1}
      
  #declare Herschel_Platform_Struts = union {
    object{ Herschel_Platform_Strut1 }
    object{ Herschel_Platform_Strut1 translate z*1}
    object{ Herschel_Platform_Strut1 translate z*7}
    object{ Herschel_Platform_Strut1 translate z*8}
    object{ Herschel_Platform_Strut2 }
    object{ Herschel_Platform_Strut2 translate z*1}
    object{ Herschel_Platform_Strut2 translate z*7}
    object{ Herschel_Platform_Strut2 translate z*8}
  }
      
  #declare Herschel_Platform = union { 
    object { Herschel_Platform_Side 
      material {Herschel_FrameMaterial}
      translate x*7
      translate y*6
      translate z*1
    }
    object { Herschel_Platform_Side 
      material {Herschel_FrameMaterial}
      translate x*7
      translate y*6
      translate z*9
    }
    object { Herschel_Platform_1 
      material {Herschel_FrameMaterial}
      translate x*9.1
      translate y*6
      translate z*1
    }
    object { Herschel_Platform_Base
      material {Herschel_FrameMaterial}
      translate x*7
      translate y*6
      translate z*1
    }
    object { Herschel_Platform_Struts
      material {Herschel_FrameMaterial}
      translate x*7
      translate y*6
      translate z*1
    }
  }
      
  object { Herschel_Platform}
  
  
  
  #declare Herschel_Radius=1.6;
  #declare Herschel_Telescope = union { 
    difference {
      cylinder { <0, 0, 0>, <0, 17, 0> Herschel_Radius}
      cylinder { <0, 0.1, 0>, <0, 17.1, 0> Herschel_Radius-0.1}
    }
    difference {
      cylinder { <0, 16.9, 0>, <0, 17, 0> Herschel_Radius+0.1}
      cylinder { <0, 16.8, 0>, <0, 17.1, 0> Herschel_Radius-0.1}
    }
    box { <Herschel_Radius*sin(  0), 10, Herschel_Radius*cos(  0)>, <Herschel_Radius*sin(  0)+0.1, 17, Herschel_Radius*cos(  0)-0.1> }
    box { <Herschel_Radius*sin( 36), 10, Herschel_Radius*cos( 36)>, <Herschel_Radius*sin( 36)+0.1, 17, Herschel_Radius*cos( 36)-0.1> }
    box { <Herschel_Radius*sin( 72), 10, Herschel_Radius*cos( 72)>, <Herschel_Radius*sin( 72)+0.1, 17, Herschel_Radius*cos( 72)-0.1> }
    box { <Herschel_Radius*sin(108), 10, Herschel_Radius*cos(108)>, <Herschel_Radius*sin(108)+0.1, 17, Herschel_Radius*cos(108)-0.1> }
    box { <Herschel_Radius*sin(144), 10, Herschel_Radius*cos(144)>, <Herschel_Radius*sin(144)+0.1, 17, Herschel_Radius*cos(144)-0.1> }
    box { <Herschel_Radius*sin(180), 10, Herschel_Radius*cos(180)>, <Herschel_Radius*sin(180)+0.1, 17, Herschel_Radius*cos(180)-0.1> }
    box { <Herschel_Radius*sin(216), 10, Herschel_Radius*cos(216)>, <Herschel_Radius*sin(216)+0.1, 17, Herschel_Radius*cos(216)-0.1> }
    box { <Herschel_Radius*sin(252), 10, Herschel_Radius*cos(252)>, <Herschel_Radius*sin(252)+0.1, 17, Herschel_Radius*cos(252)-0.1> }
    box { <Herschel_Radius*sin(288), 10, Herschel_Radius*cos(288)>, <Herschel_Radius*sin(288)+0.1, 17, Herschel_Radius*cos(288)-0.1> }
    box { <Herschel_Radius*sin(324), 10, Herschel_Radius*cos(324)>, <Herschel_Radius*sin(324)+0.1, 17, Herschel_Radius*cos(324)-0.1> }
  }
  
  
  object { Herschel_Telescope
    rotate z*-61
    translate x*-7
    translate y*2
    translate z*5 
    material {Herschel_CasingMaterial}
  }
  
  #declare Herschel_Base_Wheel = cylinder { <0, -0.5, 0>, <0, -0.5, 0.5> 0.5 material {Herschel_WheelMaterial}}
      
  //  Add structure to the side of frames
  #declare Herschel_Side_Of_Sideframe = union {
    cylinder { < 0  , 0, -7  >, < 0, 20,  0   > 0.2}
    cylinder { <-5  , 0, -5  >, <-5, 10,  0   > 0.2}
    cylinder { < 5  , 0, -5  >, < 5, 10,  0   > 0.2}
                                              
    cylinder { < 0  , 0, 17  >, < 0, 20, 10   > 0.2}
    cylinder { <-5  , 0, 15  >, <-5, 10, 10   > 0.2}
    cylinder { < 5  , 0, 15  >, < 5, 10, 10   > 0.2}
  
    cylinder { <-2.5,15,  0  >, < 0, 15,-7/4  > 0.2}
    cylinder { < 2.5,15,  0  >, < 0, 15,-7/4  > 0.2}
                                              
    cylinder { <-5  ,10,  0  >, < 0, 10,-7/2  > 0.2}
    cylinder { < 5  ,10,  0  >, < 0, 10,-7/2  > 0.2}
                                              
    cylinder { <-7.5, 5,  0  >, <-5,  5,-5/2  > 0.2}
    cylinder { < 7.5, 5,  0  >, < 5,  5,-5/2  > 0.2}
                                      
    cylinder { <-5  , 5, -5/2>, < 0,  5,-3*7/4> 0.2}
    cylinder { < 5  , 5, -5/2>, < 0,  5,-3*7/4> 0.2}
  
    cylinder { <10  , 0,  5  >, <10,  0,  0   > 0.2}
    object { Herschel_Base_Wheel
      rotate y*-90
      translate x*10
      translate z*5
    }
  
    cylinder { <10, 0, 0>, <5, 0, -3*7/4> 0.2}
    object { Herschel_Base_Wheel
      rotate y*-60
      translate x*10
    }
  
    cylinder { <5, 0, -3*7/4>, <0, 0, -7> 0.2}
    object { Herschel_Base_Wheel
      rotate y*-30
      translate x*5
      translate z*-3*7/4
    }
  
    cylinder { <0, 0, -7>,  <-5, 0, -3*7/4> 0.2}
    object { Herschel_Base_Wheel
      translate z*-7
    }
  
    cylinder { <-5, 0, -3*7/4>,  <-10, 0, 0> 0.2}
    object { Herschel_Base_Wheel
      rotate y*30
      translate x*-5
      translate z*-3*7/4
    }
  
    cylinder { <-10, 0, 0>, <-10, 0, 5> 0.2}
    object { Herschel_Base_Wheel
      rotate y*60
      translate x*-10
    }
  }
      
   
  
  #declare Herschel_Sideframe = union {
    cylinder { <-10 ,  0, 0>, < 0  , 20, 0> 0.2}
    cylinder { < 10 ,  0, 0>, < 0  , 20, 0> 0.2}
    cylinder { <-7.5,  5, 0>, < 7.5,  5, 0> 0.2}
    cylinder { <-5  , 10, 0>, < 5  , 10, 0> 0.2}
    cylinder { <-2.5, 15, 0>, < 2.5, 15, 0> 0.2}
    cylinder { < 0  ,  0, 0>, <-5  , 10, 0> 0.2}
    cylinder { < 0  ,  0, 0>, < 5  , 10, 0> 0.2}
    cylinder { <-5  ,  0, 0>, < 2.5, 15, 0> 0.2}
    cylinder { < 5  ,  0, 0>, <-2.5, 15, 0> 0.2}
  }
  
  object { Herschel_Sideframe material {Herschel_FrameMaterial}}
  object { Herschel_Sideframe material {Herschel_FrameMaterial} translate z*10}
      
  object { Herschel_Side_Of_Sideframe material {Herschel_FrameMaterial}}
  object { Herschel_Side_Of_Sideframe material {Herschel_FrameMaterial} rotate y*180 translate z*10}
          
  #declare Herschel_Plank1 = box { <0, 0, 0>, <20, 1, 0.1> rotate x*10}
  #declare Herschel_Plank2 = box { <0, 0, 0>, <10, 1, 0.1> rotate x*10}
  #declare Herschel_Plank3 = box { <0, 0, 0>, <12, 1, 0.1> rotate x*10}
  #declare Herschel_Plank4 = box { <0, 0, 0>, < 8, 1, 0.1> rotate x*10}
  
  #declare Herschel_Wall1 = union {
    #declare Herschel_YCount=0;
    #while (Herschel_YCount < 20)
      object { Herschel_Plank1
      material {Herschel_FrameMaterial}
      translate y*Herschel_YCount*1.1
    }
    #declare Herschel_YCount=Herschel_YCount+1;
    #end
  }
      
  #declare Herschel_Wall2 = union {
    #declare Herschel_YCount=0;
    #while (Herschel_YCount < 20)
      object { Herschel_Plank2
      material {Herschel_FrameMaterial}
      translate y*Herschel_YCount*1.1
    }
    #declare Herschel_YCount=Herschel_YCount+1;
    #end
  }
  
  #declare Herschel_Wall3 = union {
    #declare Herschel_YCount=0;
    #while (Herschel_YCount < 20)
      object { Herschel_Plank3
      material {Herschel_FrameMaterial}
      translate y*Herschel_YCount*1.1
    }
    #declare Herschel_YCount=Herschel_YCount+1;
    #end
  }
  
  #declare Herschel_Wall4 = union {
    #declare Herschel_YCount=0;
    #while (Herschel_YCount < 20)
      object { Herschel_Plank4
      material {Herschel_FrameMaterial}
      translate y*Herschel_YCount*1.1
    }
    #declare Herschel_YCount=Herschel_YCount+1;
    #end
  }
  
  #declare Herschel_Wall5 = union {
    #declare Herschel_YCount=0;
    #while (Herschel_YCount < 7)
      object { Herschel_Plank4
      material {Herschel_FrameMaterial}
      translate y*Herschel_YCount*1.1
    }
    #declare Herschel_YCount=Herschel_YCount+1;
    #end
  }
  
  #declare Herschel_Gable_End_Remove1 = union {
    box { <0, 0, -1>, <-20, 30, 1> rotate z*-60}
    box { <0, 0, -1>, <-20, 30, 1> rotate z*-120 translate <-6,15,0>}
  }
  
  #declare Herschel_Gable_End_Remove2 = union {
    box { <0, 0, -1>, <-20, 30, 1> rotate z*-60}
    box { <0, 0, -1>, <-20, 30, 1> rotate z*-120 translate <-6,12,0>}
  }
  
    
  #declare Herschel_Gable_End1 = difference { 
    object { Herschel_Wall1}
    object { Herschel_Gable_End_Remove1}
  }
  
  #declare Herschel_Gable_End2 = difference { 
    object { Herschel_Wall3}
    object { Herschel_Gable_End_Remove2}
  }
  
  #declare Herschel_Roof = difference {
    object { Herschel_Wall2}
    box { <0, 12, -1>, <20, 22, 1>}
  } 
  
  #declare Herschel_Roof2 = difference {
    object { Herschel_Wall5}
    box { <0, 12, -1>, <20, 22, 1>}
  } 
  
  #declare Herschel_Observatory = union {
    union {
      object { Herschel_Wall1
        scale 0.15
        translate x*-5
        translate z*-10
      }
  // Door
      box { <-4.3, 0, -10.1>, <-3, 3, -9.9> }
    }
      
      
    union {
      difference { 
        object {
          Herschel_Wall1
          scale 0.15
          rotate y*180
          translate x*-2
          translate z*-11.5
        }
  //      hole in side for window    
        box { <-4.5, 2, -11.6>, <-2.7, 3, -11.4> }
      }
  //    Frames for windows in Herschel_Observatory    
      cylinder { <-4.5 , 2.5, -11.5>, <-2.7 , 2.5, -11.5> 0.05 }
      cylinder { <-4.05, 2  , -11.5>, <-4.05, 3  , -11.5> 0.05 }
      cylinder { <-3.6 , 2  , -11.5>, <-3.6 , 3  , -11.5> 0.05 }
      cylinder { <-3.15, 2  , -11.5>, <-3.15, 3  , -11.5> 0.05 }
      
    }
      
    object { Herschel_Wall2
      scale 0.15
      rotate y*90
      translate x*-5
      translate z*-10
    }    
      
    object { Herschel_Wall2
      scale 0.15
      rotate y*270
      translate x*-2
      translate z*-11.5
    }
      
    object { Herschel_Gable_End1
      scale 0.15
      translate x*-5
      translate z*-10
      translate y*3.3
    }
  
    object { Herschel_Gable_End1
      scale 0.15
      translate x*-5
      translate z*-11.5
      translate y*3.3
    }
                                        
    object { Herschel_Roof
      scale 0.15
      rotate y*90
      rotate z*60
      translate z*-10
      translate y*3.3
      translate x*-2
    }
      
    object { Herschel_Roof
      scale 0.15
      rotate y*90
      rotate z*120
      translate z*-10
      translate y*4.2
      translate x*-3.35
    }
      
  } // end of declaration of Herschel_Observatory
      
  object { Herschel_Observatory
    scale 1.3
    translate z*16
    translate x*-1
  }
      
  #declare Herschel_Working_Room = union {
    object { Herschel_Wall3
      scale 0.15
      translate x*-5
      translate z*-10
    }
      
    union { 
      difference { 
        object { Herschel_Wall3
          scale 0.15
          rotate y*180
          translate x*-3
          translate z*-11.1
        }
  //            hole in side for window    
        box { <-3.5, 2, -11.2>, <-4.5, 3, -11.0> }
      }
      
  //    Frames for windows in working room    
      cylinder { <-4, 2, -11.1>, <-4, 3, -11.1> 0.05 }
      cylinder { <-3.5, 2.5, -11.1>, <-4.5, 2.5, -11.1> 0.05 }
    }
      
    union { 
      object { Herschel_Wall4
        scale 0.15
        rotate y*90
        translate x*-5
        translate z*-10
      }
      box { <-5.1, 0, -11>, <-4.9, 3, -10> }
    }    
      
    union { 
      difference {
        object { Herschel_Wall4
          scale 0.15
          rotate y*270
          translate x*-3
          translate z*-11
        }
      
  //       hole in side for window    
        box { <-2.9, 2.5, -10.5>, <-3.3, 3, -10> }
      }
      
  //     Frames for windows in working room    
      cylinder { <-3, 2.5, -10.25>, <-3, 3, -10.25> 0.05 }
      cylinder { <-3, 2.75, -10.5>, <-3, 2.75, -10> 0.05 }
    } 
  
    object { Herschel_Gable_End2
      scale 0.15
      translate x*-5
      translate z*-10
      translate y*3.3
    }
  
    object { Herschel_Gable_End2
      scale 0.15
      translate x*-5
      translate z*-11.2
      translate y*3.3
    }
                                        
    object { Herschel_Roof2
      scale 0.15
      rotate y*90
      rotate z*60
      translate z*-10
      translate y*3.3
      translate x*-3
    }
      
    object { Herschel_Roof2
      scale 0.15
      rotate y*90
      rotate z*120
      translate z*-10
      translate y*3.8
      translate x*-3.9
    }
      
  } // end of declaration of Herschel_Working_Room
      
  object { Herschel_Working_Room
    scale 1.3
    translate z*21
    translate x*-1
  }
   
  # declare Herschel_Bannisters = union {
    cylinder { <2, 0.5 , 0   >, <2, 2   , 0   > 0.1}
    cylinder { <2, 2.75, 2.75>, <2, 4.25, 2.75> 0.1}
    cylinder { <2, 5   , 5   >, <2, 6.5 , 5   > 0.1}
    cylinder { <2, 5   , 6   >, <2, 6.5 , 6   > 0.1}
    cylinder { <2, 5   , 7   >, <2, 6.5 , 7   > 0.1}
    // Handrail                               
    cylinder { <2, 2   , 0   >, <2, 6.5 , 5   > 0.1}
    cylinder { <2, 6.5 , 5   >, <2, 6.5 , 7   > 0.1}
  }
  
  #declare Herschel_Stair_Plank = box { <0, 0, 0>, <2, .1, .5>}
  
  #declare Herschel_Stairs  = union {    
    object { Herschel_Stair_Plank translate <0,0.5,0.5>}
    object { Herschel_Stair_Plank translate <0,1.0,1.0>}
    object { Herschel_Stair_Plank translate <0,1.5,1.5>}
    object { Herschel_Stair_Plank translate <0,2.0,2.0>}
    object { Herschel_Stair_Plank translate <0,2.5,2.5>}
    object { Herschel_Stair_Plank translate <0,3.0,3.0>}
    object { Herschel_Stair_Plank translate <0,3.5,3.5>}
    object { Herschel_Stair_Plank translate <0,4.0,4.0>}
    object { Herschel_Stair_Plank translate <0,4.5,4.5>}
    object { Herschel_Stair_Plank translate <0,5.0,5.0>}
    // Platform at top of Herschel_Stairs
    box { <0, 5, 5>, <2, 5.1, 7> }
    // Sides to Herschel_Stairs
    box { <0, 0, 0>, <-0.1, 0.2, 7> rotate x*-45}
    box { <2, 0, 0>, < 2.1, 0.2, 7> rotate x*-45}
    object { Herschel_Bannisters }
  }
  
  
  object { Herschel_Stairs
    material {Herschel_FrameMaterial}
    translate x*8.5
    rotate y*30
    scale 0.8
  }
      
  #declare Herschel_Rope = cylinder { <3.7,12.4,5>, <-0.2,19,5> 0.05}
  #declare Herschel_Rope2 = cylinder { <6.3,7,1.5>, <-0.2,19.5,1.5> 0.05}
      
  #declare Herschel_Block = union {
    cylinder { <0, 0, 0>, <0, 0, 0.5> 0.2}
    cylinder { <0, 0.5, 0>, <0, 0.5, 0.5> 0.2}
    box { <-0.05, -0.3, -0.1> <.05, 0.8, 0> }
    box { <-0.05, -0.3, 0.6> <.05, 0.8, 0.5> }    
  }
  
  #declare Herschel_Block2 = cylinder { <0, 0, 0>, <0, 0, 0.5> 0.2}
      
  #declare Herschel_Block3 = union {
    object { Herschel_Block rotate z*20}
    object { Herschel_Block rotate z*20 translate x*1}
    object { Herschel_Block rotate z*20 translate x*2}
  }
      
  
  // Add the blocks for the block and tackle raising gear to the scene
  union {
    object {Herschel_Block3
      translate y*19
      translate z*5
    }
    box { <-0.5,19.3,4.9>, <2.5,19.5,5.1> }
        
    object {Herschel_Block3
      translate y*12
      translate x*4
      translate z*5
    }
    box { <3.5,11.7,4.9>, <6.5,11.6,5.1> }
    cylinder { <5, 11.6, 5>, <5.4, 10.7, 5>, 0.1 }
    object { Herschel_Block2
      translate z*1.5
      translate y*7
      translate x*6.5
    }
    object { Herschel_Block2
      translate z*1.5
      translate y*19.5  
    } 
    material {Herschel_BlockMaterial}
  }
      
  
  // Add the rope to the scene
  union {
    // Six windings around the blocks
    object { Herschel_Rope }
    object { Herschel_Rope translate x*1}
    object { Herschel_Rope translate x*2}
    object { Herschel_Rope translate x*0.4}
    object { Herschel_Rope translate x*1.4}
    object { Herschel_Rope translate x*2.4}
    // Connect the rope back to the anchor point
    cylinder { <-4,0,0>, <0,19,5> 0.05}
    object { Herschel_Rope2}
    object { Herschel_Rope2 translate x*.4}
    cylinder { <-4,0,0>, <-0.2,19.5,1.5> 0.05}
    material {Herschel_RopeMaterial}
  }
  
  // Base            
  difference {
    cylinder { 0    ,y*0.5,12}
    cylinder {-0.1*y,y*0.6,9}
    material {Herschel_BaseMaterial} 
    translate <0,-1.5,5>
  } 
  translate <0,1.5,-5>
}