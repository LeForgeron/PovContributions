//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// 

/**********************************************************************************/
/* staircase_samples.inc  -  Created by Chris Bartlett April 2006                 */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This include file provides macros to return a number of different */
/*              styles of baluster and newel post.                                */
/* Version:     Written using POV-Ray 3.6                                         */
/*                                                                                */
/**********************************************************************************/


#macro StairCase_BalusterShape (Name)

  #if (strcmp(Name,"Box"     )=0) box {<-0.015,-0.03,-0.015><0.015,1,0.015>} #end 

  #if (strcmp(Name,"Bevelled")=0) 
    intersection {
      box {<-0.018,-0.03,-0.018><0.018,1,0.018> rotate y*45} 
      box {<-0.015,-0.03,-0.015><0.015,1,0.015>} 
    }
  #end

  #if (strcmp(Name,"Chamfer")=0) 
    #local CuttingEdge = union { 
      box      {<-0.1,0.25,-0.1 ><0.1,0.80,0   >}
      cylinder {<-0.1,0.25,-0.05><0.1,0.25,-0.05>,0.05}
      cylinder {<-0.1,0.80,-0.05><0.1,0.80,-0.05>,0.05}
      translate -z*0.015
    } 
    difference {
      box {<-0.015,-0.03,-0.015><0.015,1,0.015>}
      object {CuttingEdge rotate  y*45} 
      object {CuttingEdge rotate  y*135} 
      object {CuttingEdge rotate -y*45} 
      object {CuttingEdge rotate -y*135} 
    }
  #end

  #if (strcmp(Name,"Notched")=0) 
    #local CuttingEdge = union {
      #local I = 0.25;
      #while (I<0.8) 
        cylinder {<-0.1,I,-0.05><0.1,I,-0.05>,0.05}
        #local I = I + 0.06;
      #end
      translate -z*0.015
    } 
    difference {
      box {<-0.015,-0.03,-0.015><0.015,1,0.015>}
      object {CuttingEdge rotate  y*45} 
      object {CuttingEdge rotate  y*135} 
      object {CuttingEdge rotate -y*45} 
      object {CuttingEdge rotate -y*135} 
    }
  #end

  #if (strcmp(Name,"Turned")=0|strcmp(Name,"Fluted")=0)
    /* Set the control points to be used to generate the balusters beneath the hand rail.*/
    #local ProfilePoints = 31;
    #local LatheArray = array[ProfilePoints] {
      <0.035,  1.10 >,   // Top square section
      <0.035,  1.10 >,   
      <0.035,  0.80 >,
      <0.015,  0.75 >, 
                     
      <0.015,  0.75 >, 
      <0.021,  0.747>,
      <0.015,  0.744>, 
                     
      <0.010,  0.744>, 
      <0.021,  0.740>,
      <0.016,  0.730>,
      <0.015,  0.720>, 
                     
      <0.015,  0.720>, 
      <0.021,  0.717>,
      <0.015,  0.714>, 
                     
      <0.015,  0.714>,
      <0.021,  0.45 >,    // Middle Bulge
      <0.015,  0.406>,  
                     
      <0.015,  0.406>,
      <0.021,  0.403>,
      <0.010,  0.400>,
                     
      <0.015,  0.400>,
      <0.016,  0.390>,
      <0.021,  0.370>,
      <0.015,  0.356>,
                     
      <0.015,  0.356>, 
      <0.021,  0.353>, 
      <0.015,  0.35 >,   
                     
      <0.015,  0.35 >,   // Lower square section
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

    #local FluteCut = union {
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*0}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*1}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*2}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*3}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*4}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*5}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*6}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*7}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*8}
      sphere {0,1 scale <0.008,0.29,0.01> rotate x*2.6 translate <0,0.39,-0.031> rotate 36*y*9}
    }
    #if (strcmp(Name,"Fluted")=0)
      difference {
        intersection {          
          box { 
            <-0.021, -0  , -0.021> 
            < 0.021,  1.1,  0.021> 
          }
          object {LatheCut}
          translate -y*0.03
        }
        object {FluteCut}    
      }
    #else 
      intersection {          
        box { 
          <-0.021, -0  , -0.021> 
          < 0.021,  1.1,  0.021> 
        }
        object {LatheCut}
        translate -y*0.03
      }    
    #end
  #end


#end


#macro StairCase_NewelShape (Name)

  #if (strcmp(Name,"Box"     )=0) box {<-0.042,-1,-0.042><0.042,1.02,0.042>} #end 

  #if (strcmp(Name,"Bevelled")=0) 
    intersection {
      box {<-0.042,-1,-0.042><0.042,1.02,0.042>}
      plane {<0,1,1>,0 translate 1.05*y}
      plane {<0,1,1>,0 translate 1.05*y rotate  90*y}
      plane {<0,1,1>,0 translate 1.05*y rotate 180*y}
      plane {<0,1,1>,0 translate 1.05*y rotate 270*y}
      plane {<1,0,1>,0 translate <0.04,0,0.04>}
      plane {<1,0,1>,0 translate <0.04,0,0.04> rotate  90*y}
      plane {<1,0,1>,0 translate <0.04,0,0.04> rotate 180*y}
      plane {<1,0,1>,0 translate <0.04,0,0.04> rotate 270*y}
    }
  #end

  #if (strcmp(Name,"Chamfer")=0) 
    #local CuttingEdge = union { 
      box      {<-0.1,0.25,-0.1 ><0.1,0.80,0   >}
      cylinder {<-0.1,0.25,-0.05><0.1,0.25,-0.05>,0.05}
      cylinder {<-0.1,0.80,-0.05><0.1,0.80,-0.05>,0.05}
      translate -z*0.05
    } 
    difference {
      intersection {
        box {<-0.042,-1,-0.042><0.042,1.02,0.042>}
        plane {<0,1,1>,0 translate 1.05*y}
        plane {<0,1,1>,0 translate 1.05*y rotate  90*y}
        plane {<0,1,1>,0 translate 1.05*y rotate 180*y}
        plane {<0,1,1>,0 translate 1.05*y rotate 270*y}
      }
      object {CuttingEdge rotate  y*45} 
      object {CuttingEdge rotate  y*135} 
      object {CuttingEdge rotate -y*45} 
      object {CuttingEdge rotate -y*135} 
      object {CuttingEdge translate y*0.7 rotate  y*45} 
      object {CuttingEdge translate y*0.7 rotate  y*135} 
      object {CuttingEdge translate y*0.7 rotate -y*45} 
      object {CuttingEdge translate y*0.7 rotate -y*135} 
    }
  #end

  #if (strcmp(Name,"Notched")=0) 
    #local CuttingEdge = union {
      #local I = 0.25;
      #while (I<0.8) 
        cylinder {<-0.1,I,-0.05><0.1,I,-0.05>,0.05}
        #local I = I + 0.06;
      #end
      translate -z*0.05
    } 
    difference {
      intersection {
        box {<-0.042,-1,-0.042><0.042,1.02,0.042>}
        plane {<0,1,1>,0 translate 1.05*y}
        plane {<0,1,1>,0 translate 1.05*y rotate  90*y}
        plane {<0,1,1>,0 translate 1.05*y rotate 180*y}
        plane {<0,1,1>,0 translate 1.05*y rotate 270*y}
        plane {<1,0,1>,0 translate <0.039,0,0.039>}
        plane {<1,0,1>,0 translate <0.039,0,0.039> rotate  90*y}
        plane {<1,0,1>,0 translate <0.039,0,0.039> rotate 180*y}
        plane {<1,0,1>,0 translate <0.039,0,0.039> rotate 270*y} 
      }
      object {CuttingEdge rotate  y*45} 
      object {CuttingEdge rotate  y*135} 
      object {CuttingEdge rotate -y*45} 
      object {CuttingEdge rotate -y*135} 
    }
  #end

  #if (strcmp(Name,"Turned")=0|strcmp(Name,"Fluted")=0)
    #local ProfilePoints = 22;
    #local LatheArray = array[ProfilePoints] {
      <0.040,  1.10 >, 
      
      <0.020,  0.920>,
      <0.038,  0.90 >,   
                     
      <0.020,  0.897>,   // Top square section
      <0.075,  0.85 >,
      <0.075,  0.75 >,
      <0.030,  0.70 >, 
                     
      <0.038,  0.65>,
      <0.025,  0.630>,
      <0.030,  0.5> ,
                     
      <0.040,  0.29> ,
      <0.040,  0.19> ,
      <0.035,  0.17>,
      <0.030,  0.16>,
      <0.035,  0.150>,
      <0.040,  0.14>, 
                     
      <0.040,  0.12>,   // Lower square section
      <0.075,  0.07> ,
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
    
    #local FluteCut = union {
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*0}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*1}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*2}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*3}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*4}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*5}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*6}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*7}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*8}
      sphere {0,1 scale <0.012,0.29,0.014> rotate x*2.6 translate <0,0.51,-0.046> rotate 36*y*9}
    }
    #if (strcmp(Name,"Fluted")=0)
      difference {
        union {
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
        object {FluteCut} 
      }
    #else 
      union {
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
    #end
  #end
#end    

