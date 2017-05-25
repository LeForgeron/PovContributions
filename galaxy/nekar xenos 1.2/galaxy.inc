// Persistence of Vision Ray Tracer Include File
// File: Galaxy.inc
// Vers: 3.6
// Desc: Galaxy macro. 
//       Galaxy(Rotation,Size) // Galaxy Macro
//       StarField             // Starfield object
//       star_pig              // Stars sky_sphere pigment
// Date: 13/12/2007
// Auth: - Nekar Xenos -  
//
//This file is licensed under the terms of the CC-LGPL
//                 
// Warning: The sample scene provided to demonstrate this include file 
//          takes about 8.5 hours to render on a 4 way 2.4GHz machine
//          at a resolution of 320x240 without antialiasing.  
//  
#version 3.6; 

#macro Galaxy(Rotation,Size,ArmCount,Tightness,Turb,NucleuSize,Quality) 
// #local NucleuSize=1-NucleuSize;
//#local ArmCount=ArmCount/2;

#declare Galaxy_DenStars=density {crackle 
                           form<1,1,0> 
                           scale.0003 warp{black_hole 0,1 strength .2} 
                           //density_map{[.1 rgb .5][.3 rgb 1][.9 rgb 1][1 rgb 10]}
                           density_map{
                                       [.25  rgb 1000]
                                       [.3 rgb 1] 
                                       [.5 rgb 1] 
                                       [.6 rgb .5]
                                       } 
                           }

#declare Galaxy_DenStars2=density {crackle 
                            form<1,1,0> 
                            scale.001 warp{black_hole 0,1 strength 1} 
                            //density_map{[.1 rgb .8][.2 rgb 1][.5 rgb 2][1 rgb 10]}  
                            density_map{
                                        [.5  rgb 100000] 
                                        [.6 rgb 10]
                                        [.6 rgb 1]
                                        [.9 rgb .8]
                                        
                                        } 
                            }

#declare Galaxy_DenSphere=
                  density {
                    spherical
                    //turbulence .012
                    //omega .7
                   //lambda 3 
                   //sine_wave
                    density_map {
                      [(1-(NucleuSize*.9)) color rgb 0]
                      [(1-(NucleuSize*.8)) color rgb <0.01, 0.1, 0.4>]
                      //[0.6 color rgb <0.1, 0.3, 0.5>]
                      //[0.7 color rgb <1.0, 0.5, 0.5>] 
                      [(1-(NucleuSize*.1)) color rgb <1.0, 0.8, 0.5>]
                      [1 color rgb 4]
                    }
                  }




#declare Galaxy_DenSpiral=
                  density {
                    spiral1 ArmCount   scale 1/Tightness
                    ramp_wave
                    turbulence .1*Turb 
                    omega .7
                    //lambda 2  
                           
                    density_map {
                      [.1 spherical scale Tightness*2  
                           //translate z*-.1
                           density_map {
                                      [((1-NucleuSize)*.8) color rgb 0]
                                      [((1-NucleuSize)*.85) color rgb <0.01, 0.1, 0.4>/4]
                                      //[((1-NucleuSize)*.7) color rgb <0.1, 0.3, 0.5>/4]
                                      [((1-NucleuSize)*.9) color rgb <1.0, 0.5, 0.5>/2]
                                      [((1-NucleuSize)*.95) color rgb <1.0, 0.9, 0.5>]
                                      [(1-(NucleuSize)) color rgb 2 ]  
                                      [1 color rgb 4]
                                    } 
                      ]
                      
                       
                      [.2 spherical  scale Tightness*2
                            
                           density_map {
                                      //[0 color rgb 0] 
                                      [0 color rgb <0.01, 0.1, 0.4>/4]
                                      [(1-NucleuSize)*.1 color rgb <0.1, 0.3, 0.5>/4]
                                      [(1-NucleuSize)*.2 color rgb <0.2, 0.6, 0.6>/2]
                                      [(1-NucleuSize)*.3 color rgb 1]
                                      [(1-(NucleuSize)) color rgb 2 ]  
                                      [1 color rgb 4]
                                    }
                            ]  
                            
                      [0.4 //color rgb <0.1, 0.3, 0.5>
                           spherical  scale Tightness*2
                            
                            density_map {
                              [0 color rgb 0]
                              [(1-NucleuSize)*.3 color rgb <0.01, 0.1, 0.4>/4]
                              [(1-NucleuSize)*.4 color rgb <0.1, 0.3, 0.5>/4]
                              [(1-NucleuSize)*.5 color rgb <1.0, 0.5, 0.5>/2]
                              [(1-NucleuSize)*.7 color rgb <1.0, 0.9, 0.5>]
                              [(1-(NucleuSize)) color rgb 2] 
                              [1 color rgb 4]
                            }
                      ] 
                      [0.7 //color rgb <0.01, 0.1, 0.3>
                           spherical  scale Tightness*2 
                            
                            density_map {
                              [0 color rgb 0]
                              [((1-NucleuSize)*.5) color rgb <0.01, 0.1, 0.3>]
                              [(1-NucleuSize)*.6 color rgb <0.01, 0.1, 0.4>/4]
                              [(1-NucleuSize)*.7 color rgb <0.1, 0.3, 0.5>/4]
                              [(1-NucleuSize)*.8 color rgb <1.0, 0.5, 0.5>/2]
                              [(1-NucleuSize)*.9 color rgb <1.0, 0.9, 0.5>]
                              [(1-(NucleuSize*.65)) color rgb 2] 
                              [1 color rgb 4]
                            }
                      ]
                            
                      [1 //color rgb <0.01, 0.1, 0.3>
                           spherical  scale Tightness*2 
                            
                            density_map {
                              [0 color rgb 0]
                              [((1-NucleuSize)*.5) color rgb <0.01, 0.1, 0.3>]
                              [(1-NucleuSize)*.6 color rgb <0.01, 0.1, 0.4>/4]
                              [(1-NucleuSize)*.7 color rgb <0.1, 0.3, 0.5>/4]
                              [(1-NucleuSize)*.8 color rgb <1.0, 0.5, 0.5>/2]
                              [(1-NucleuSize)*.9 color rgb <1.0, 0.9, 0.5>]
                              [(1-(NucleuSize)) color rgb 2] 
                              [1 color rgb 4]
                            }
                      ]
                    }
                  }

#declare Galaxy_DenSpiral2=
                  density {
                    spiral1 25  scale.1
                    //warp{black_hole 0,.2 strength 1.01 falloff .01 inverse}
                    turbulence .2
                    //lambda 2
                    omega .8
                    colour_map {
                      [0.0 color rgb 0]
                      [0.1 color rgb 1]
                      [0.7 color rgb 2]
                      [0.9 color rgb 1]
                      [1.0 color rgb 0]
                
                    }
                  }

// . , * @ e ~ GALAXY ~ e @ * , .  \\
// Try viewing from different angles for variety.
// This is made to be viewd along the z-plane. Rotate accordingly for other camera angles 


// #macro Galaxy(Rotation,Size,ArmCount,Tightness,Turb,NucleuSize)
sphere {0, 1   
         texture {
          pigment {rgbt 1}
                 }
         interior {
          media {
           //samples 1,2  
           intervals 1+Quality 
           //confidence .00000001
           
           emission 10
           method 1
                  density {Galaxy_DenSpiral translate z*.05 }
                  #if(Quality>6)
                        density {Galaxy_DenSpiral2  }  
                  #end
                  density {Galaxy_DenSphere   scale <(1/NucleuSize),(1/NucleuSize),1>
                        }
                  
                  //density {spherical density_map{[0 rgb .1][1 rgb 1]} scale <1.5,.1,1.5>} 
                  //density {spherical density_map{[0 rgb <0.1, 0.1, 0.4>/4][(1-(NucleuSize)) rgb <1.1,.9,1>][1 rgb 2]} scale <1.5,NucleuSize/2,1.5>}
                  //density {spherical density_map{[.1 rgb <0.1, 0.5, 0.5>/2][(1-(NucleuSize)) rgb <1.1,1,.9>*2][1 rgb 4]} scale <1,NucleuSize,1>}
                          
                          }
                  
                  
                 }
         //rotate -90*x
         rotate Rotation
         scale <Size,Size,1>
         hollow
         }   
#end // #macro 

// Galaxy(Rotation,Size,ArmCount,Tightness,Turb,NucleuSize) 
//object{Galaxy(<0,0,0>,.8,2,2,1,.1)}   

//.........................................................................\\


// .  .: * Star Field * :.  .   \\
// Fits in sphere{0,100}

#declare Galaxy_StarField=sphere{ // surrounding stars
        0,100 pigment {rgbt 1}
        interior {
          media {
           emission 1
           method 3
                                density {crackle 
                                         scale .001  
                                         form<1,1,0>
                                         //warp{black_hole 0,100 strength .3}
                                         density_map {
                                                      [0 color rgb 1000]
                                                      [0.25 color rgb <1.0, 0.9, 0.5>] 
                                                      [0.3 color rgb <1.0, 0.5, 0.5>/2]
                                                      [0.4 color rgb <0.1, 0.3, 0.5>/4]
                                                      [0.5 color rgb <0.01, 0.1, 0.4>/5]
                                                      [0.6 color rgb 0]
                                                      }
                                    }
                                }
                  }
         hollow
         }

//........................................................................\\


//  .  .: * Starry Sky_Sphere Pigment * :.  .   \\  

#declare Galaxy_Star_pig=
          pigment {
                
                    crackle 
                    form<1,1,0> 
                    scale .01//.01
                
                    color_map {
                              [0 color rgb 100000]
                              [0.25 color rgb <1.0, 0.9, 0.5>] 
                              [0.3 color rgb <1.0, 0.5, 0.5>/2]
                              [0.4 color rgb <0.1, 0.3, 0.5>/4]
                              [0.5 color rgb <0.01, 0.1, 0.4>/5]
                              [0.6 color rgb 0]
                              }
                
                  }
// sky_sphere{pigment{star_pig}}

        
//------------------------------------------------------------------------------------\\                       