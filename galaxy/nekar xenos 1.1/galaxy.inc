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
                    turbulence .1
                    omega .7
                    lambda 3
                    density_map {
                      [0 color rgb 0]
                      [0.5 color rgb <0.01, 0.1, 0.4>/4]
                      [0.6 color rgb <0.1, 0.3, 0.5>/2]
                      [0.7 color rgb <1.0, 0.5, 0.5>/2]
                      [0.8 color rgb <1.0, 0.8, 0.5>]
                      [1.0 color rgb 1]
                    }
                  }

#declare Galaxy_DenSphere2=
                  density {
                    spherical
                    omega .7
                    lambda 2
                    density_map {
                      [0.5 color rgb 0]
                      [0.6 color rgb <0.01, 0.1, 0.4>/4]
                      [0.65 color rgb <0.1, 0.3, 0.5>/4]
                      [0.7 color rgb <1.0, 0.5, 0.5>/2]
                      [0.8 color rgb <1.0, 0.9, 0.5>]
                      [1.0 color rgb 1]
                    }
                  }

#declare Galaxy_DenSphere3=
                  density {
                    spherical
                    turbulence .5
                    omega 1
                    lambda 2
                    density_map {
                      [0.5 color rgb 0]
                      [0.6 color rgb <0.01, 0.1, 0.4>/4]
                      [0.65 color rgb <0.1, 0.3, 0.5>/4]
                      [0.7 color rgb <1.0, 0.5, 0.5>/2]
                      [0.8 color rgb <1.0, 0.9, 0.5>]
                      [1.0 color rgb 1]
                    }
                  }

#declare Galaxy_DenSpiral=
                  density {
                    spiral1 1
                    //warp{black_hole <.001,0,.001>,.5 strength 1 falloff 3 inverse}
                    turbulence .1 omega .7
                    lambda 2
                    colour_map {
                      [0  color rgb 0]
                      [0.1 color rgb <0.01, 0.1, 0.3>]
                      [0.4 color rgb <0.1, 0.3, 0.5>]
                      [0.7 color rgb 1]
                      [0.8 color rgb <0.1, 0.3, 0.5>]
                      [0.9 color rgb <0.01, 0.1, 0.3>]
                      [1 color rgb 0]
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


#declare Galaxy_DenSpiral3=
                  density {
                    spiral1 1
                    warp{black_hole 0,.5 strength 1 falloff 3 inverse}
                    turbulence .1 omega .5
                    lambda 1
                    colour_map {
                      [0.2 rgb 0]
                      [0.23 rgb .5]
                      [0.3 rgb 0]
                
                    }
                  rotate x*90
                  }


#declare Galaxy_DenSpiral4=
                  density {
                    spiral1 10  scale.1
                    //warp{black_hole 0,.2 strength 1.01 falloff .01 inverse}
                    turbulence .2
                    //lambda 2
                    omega .8
                    density_map {
                      [0.2 color rgb 0]
                      [0.3 color rgb 2]
                      [0.4 color rgb 0]
                
                    }
                  rotate x*90
                  }

  
  
#declare ColSpiral=
                  pigment {
                    spiral1 1
                    //warp{black_hole <.001,0,.001>,.5 strength 1 falloff 3 inverse}
                    turbulence .1 omega .7
                    lambda 2
                    colour_map {
                      [0 color rgbt <0,0,0,1>]
                      [0.1 color rgbt <0.01, 0.1, 0.3,.9>]
                      [0.4 color rgbt <0.1, 0.3, 0.5,.5>]
                      [0.7 color rgb <1,1,1,.1>]
                      [0.8 color rgbt <0.1, 0.3, 0.5,.5>]
                      [0.9 color rgbt <0.01, 0.1, 0.3,.9>]
                      [1 color rgbt <0,0,0,1>]
                    }
                  }



// . , * @ e ~ GALAXY ~ e @ * , .  \\
// Try viewing from different angles for variety.
// This is made to be viewd along the z-plane. Rotate accordingly for other camera angles 


#macro Galaxy(Rotation,Size)
sphere {0, 1   
         texture {
          pigment {rgbt 1}
                 }
         interior {
          media {
           emission 10
           method 3
           density {Galaxy_DenSpiral   rotate x*90 translate y*.05}
                  density {Galaxy_DenSpiral2  rotate x*90 translate y*.05}
                  density {Galaxy_DenSphere   scale y*.1}
                  density {Galaxy_DenStars}
                  density {spherical density_map{[0 rgb .1][1 rgb 1]} scale <1.5,.1,1.5>}
                          }
                  media { emission 1 method 3  
                          density {Galaxy_DenSphere2 scale y*.3} 
                          density{Galaxy_DenStars}
                          }
                  media { emission 2 method 3  
                          density {Galaxy_DenSphere2 scale .4} 
                          density{Galaxy_DenStars}
                          }
                  media { emission 1 method 3  
                          density {Galaxy_DenSphere3 scale .1} 
                          density{Galaxy_DenStars2 scale .001}
                          }  
                  
                 }
         rotate -90*x
         rotate Rotation
         scale <Size,Size,1>
         hollow
         }   
#end // #macro 

// Galaxy(Rotation,Size) 
// object{Galaxy(0,1 ) rotate x*45}   

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
                                         warp{black_hole 0,100 strength .3}
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