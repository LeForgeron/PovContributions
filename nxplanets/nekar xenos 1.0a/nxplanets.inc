// Persistence of Vision Ray Tracer Include File
// File: NXPlanets.inc
// Vers: 3.6
// Desc: Planet macro. 
//       Planet(Size) // Planet Macro
// Date: 22/09/2008
// Auth: - Nekar Xenos -  
//
//This file is licensed under the terms of the CC-LGPL
// 

// Warning: Slow Render. Clouds render very slow!!


global_settings{
  //assumed_gamma 1
  max_trace_level 100 
  //radiosity{}
}
#default{texture{finish{ambient 0}}}
#include "functions.inc"


#declare ShowMedia=on;
#declare ShowPlanet=on;
#declare ShowWater=on;
#declare ShowClouds=on;
#declare ShowRings=on;

#declare Seed=seed(97531);

#macro NegRnd(Value)   
      #if (Value<0)
          #declare Value=rand(Seed)*abs(Value);
      #end
#end

#macro NegCol(Value)   
      //#declare Value=abs((rand(Seed))*(Value)*(Value);
#end

// Negative value is taken as Max Random Value
#macro NXPlanet(Size,Terra,Cloud,Atmosphere,Gas,GasLines,GasTurb,GasTint,RingCount,RingTint,Vulcanic,Sea,SeaCol,TerraCol,Foilage,FoilageCol,Ice)
// *** PLANET Bue ***
       
NegRnd(Size)
NegRnd(Terra) 
NegRnd(Cloud) 
//NegCol(Atmosphere)
NegRnd(Gas) 
NegRnd(GasLines)
//NegCol(GasTurb)
//NegCol(GasTint) 
NegRnd(RingCount) 
//NegCol(RingTint)
NegRnd(Vulcanic) 
NegRnd(Sea)    
//NegCol(SeaCol) 
//NegCol(TerraCol)
NegRnd(Foilage) 
//NegCol(FoilageCol)
NegRnd(Ice)

       
#declare t_planet=
pigment{
           onion    warp { turbulence 0.01 /*lambda 33 */ }
           pigment_map{
                    #if (Sea) [0 rgb .9] #end
                    [.79 rgb TerraCol] // sand
                    #if(Foilage) [.85 rgb FoilageCol] #end   
                    #if(Vulcanic) 
                        [1 crackle scale .01 turbulence 0.1 colour_map{[0 rgb <1,0,0> ][.001 rgb 0][.5 rgb TerraCol]}]//rgb <1,.5,0> ]  
                    #end
                    }
                  scale 1/(<1.01,.995,1.01>)
                  }


#if(Ice)
#declare t_planet= // Bue texture
texture{
  pigment{
           onion    scale <1.01,.995,1.01>
           turbulence .0005
           lambda 2.5
           omega 1.2
           pigment_map{
                    [0 rgb 1]
                    [.05  t_planet ]
                    [.95  t_planet ] // sand
                    [1 rgb 1]//<.1,.2,.01>]
                    }
          }
        normal {agate scale .001}
        }  
#end



#declare Scalar=<4,1,4>;
#declare Rotar= <-15,0,0>; //<0,0,0>; //<60,0,16>; //<15,0,0>;//




        // }
#declare d_clouds=
//texture{
          density{
                   wrinkles  scale <100,50,100>*22
                   turbulence <1,2,1>
                   lambda 2.5
                   omega 1.3
                   warp { turbulence <10,0,10>*.1
                         //lambda 3
                         omega 1.2
                         }
                   density_map{
                            [0 rgb 0]
                            [.3 granite scale 1/(<100,50,100>*22) density_map{[0 rgb 0][.7 rgb 200]}]  
                            [1 rgb 200]
                            }
                   rotate y*15
                   scale<0.021,0.02,0.021>/Scalar
                   rotate -Rotar
                  }
#declare d_clouds2=
//texture{
          density{ wrinkles  rotate Rotar
                   scale Scalar
                   //lambda 2.5
                   omega 1.3
                   density_map{
                            [.1 rgb 0 ]
                            [.6 granite scale 3 density_map{
                                                [.5 rgb 0]
                                                [.7 granite scale .1 
                                                density_map{
                                                        [0 rgb 0]
                                                        [.7 granite scale .1 density_map{[.5 rgb 0][.6 rgb 10][1 rgb 200]}]
                                                        
                                                        [1 rgb 200]
                                                        }
                                                
                                                ] 
                                                
                                                [.8 rgb 100]
                                                [1 rgb 200]
                                                }
                            ]
                            //[.5 d_clouds]
                            //[.6 granite scale .1 density_map{[.5 rgb 0][.6 rgb 100]}]
                            
                            //[1 d_clouds] 
                            [1 rgb 0]
                            }
                   rotate y*-5
                   scale<0.021,0.02,0.021>/Scalar
                   rotate -Rotar
                  }


#declare d_clouds3=
//texture{
          density{
                   wrinkles  scale <100,50,100>*22
                   turbulence <1,2,1>
                   lambda 2.5
                   omega 1.3
                   warp { turbulence <10,0,10>*.1
                         //lambda 3
                         omega 1.2
                         }
                   density_map{
                            [0 rgb 0]
                            [.3 d_clouds2]  
                            [1 rgb 200]
                            }
                   rotate y*15
                   scale<0.021,0.02,0.021>/Scalar
                   rotate -Rotar
                  }

// Cloud texture 
#declare t_clouds1=
texture{
          pigment{
                   wrinkles  scale <100,50,100>*22
                   turbulence <1,2,1>
                   lambda 2.5
                   omega 1.3
                   warp { turbulence <10,0,10>*.1
                         //lambda 3
                         omega 1.2
                         }
                   color_map{
                            [0 rgb 1 transmit 1]
                            [.3 rgb 1 transmit .9]
                            [1 rgb 1 transmit 0]
                            }
                   rotate y*15
                   scale<0.021,0.02,0.021>/Scalar
                   rotate -Rotar
                  }
         }
#declare t_clouds=
texture{ wrinkles  rotate Rotar
                   scale Scalar
                   //lambda 2.5
                   omega 1.3
                   texture_map{
                            [0 t_clouds1 ]
                            [.3 pigment {rgb 1 transmit 1}]
                            [.5 t_clouds1]
                            [.7 pigment {rgb 1 transmit 1}]
                            [1 t_clouds1 ]
                            }
                  }

        // }
#declare t_smog=
texture{
          pigment{
                   wrinkles  scale <100,50,100>*22
                   turbulence <1,2,1>
                   lambda 2.5
                   omega 1.3
                   warp { turbulence <10,0,10>*.1
                         //lambda 3
                         omega 1.2
                         }
                   color_map{
                            [0 rgb 1 transmit 1]
                            //[.3 rgb <.3,.4,.1> transmit .9]
                            [1 rgb .5 transmit 0]
                            }
                   rotate y*15
                   scale<0.021,0.02,0.021>/Scalar
                    rotate -Rotar
                  }
         }
#declare t_smog=
texture{ wrinkles  rotate Rotar
                   scale Scalar
                   //lambda 2.5
                   omega 1.3
                   texture_map{
                            [0 t_clouds ]
                            [.3 pigment {rgb 1 transmit 1}]
                            [.5 t_clouds]
                            [.7 pigment {rgb 1 transmit 1}]
                            [1 t_clouds ]
                            }
                  }

#declare RndSeed1=rand(Seed); 
#declare RndSeed2=rand(Seed);  
#declare RndSeed3=rand(Seed);
#declare RndSeed4=rand(Seed);
#declare RndSeed5=rand(Seed);
#declare RndSeed6=rand(Seed);
#declare RndSeed7=rand(Seed);
#declare RndSeed8=rand(Seed);
#declare RndSeed9=rand(Seed);  
#declare RndSeeda=rand(Seed);
#declare RndSeedb=rand(Seed);
#declare RndSeedc=rand(Seed);

// Planet
#declare PlanetBue=
union{   #if(Terra)
                 isosurface{  
         
                function{(x*x+y*y+z*z-1)
                          +f_granite((x-RndSeed1)*2,(y-RndSeed2)*2,(z-RndSeed3)*2)*f_agate(x,y,z)*.05*(.5+RndSeeda)
                          +f_agate((x-RndSeed4)*100,(y-RndSeed5)*100,(z-RndSeed6)*100)*.001*(.5+RndSeedb)
                          -f_granite((x-RndSeed7)*1000,(y-RndSeed8)*1000,(z-RndSeed9)*1000)*.0001*(.5+RndSeedc)
                          
                          }
                          //max_gradient 3.199 
                          accuracy 1/100000
                          contained_by{sphere{0,1}}
                           
                        texture{t_planet 
                        scale .02}
                          scale y*1.002
                          }
          #end

        #if(Sea)
                sphere{0,1 // water 
                  /*isosurface{  
 
                        function{(x*x+y*y+z*z-1) -f_granite(x,y,z)*.001 }
                                  //max_gradient 3.199 
                                  accuracy 1/1000000
                                  contained_by{sphere{0,1.1}} */
                       pigment{gradient y scale 2 translate y
                               turbulence .1
                                lambda 7
                              pigment_map{
                                       [0 rgbt<1,1,1,0> ]
                                       [.15 rgbft <SeaCol.x,SeaCol.y,SeaCol.z,.5,.5> 
                                       
                                       ]
                                       [.9 rgbft <SeaCol.x,SeaCol.y,SeaCol.z,.5,.5> 
                                       
                                       ]
                                       [1 rgbt<1,1,1,0> ]
                                       }
                               }
                        normal{granite  scale .0005 phase clock}  
                       #if(ShowMedia)
                          finish{//specular .1 metallic .5  
                                //reflection{.5,1 fresnel on} 
                                specular .3 metallic .9 
                                brilliance 2 conserve_energy
                                }
                          
                          interior{ior 1.33 fade_distance .003 fade_color rgb SeaCol*.1
                                        }
                       #end
                       scale .996
                       hollow
                       }
        #end
       
       #if(Gas)
           sphere {0,1.00001 pigment{gradient y translate y*.5 scale 20 warp{turbulence GasTurb } scale .08
                                colour_map{
                                           #declare GasCount=0;
                                           
                                           #while(GasCount<GasLines)
                                               
                                               [(GasCount*(1/GasLines))
                                                 rgb <(GasTint.x)*(.5+.5*rand(Seed)),(GasTint.y)*(.5+.5*rand(Seed)),(GasTint.z)*(.5+.5*rand(Seed))>
                                                ]
                                               
                                               #declare GasCount=GasCount+1;
                                           #end
                                           
                                           }
                                } 
                   //rotate x*90
                   }             
       #end
       #if(Atmosphere.x)
               
               sphere{0,1 // Atmosphere
                       pigment{colour rgbt 1}
                       interior{//ior 1.1
                                media {
                                   method 3     
                                   //adaptive sampling 
                                   aa_threshold 0.1 aa_level 3
                	           samples 20 //6 
                	           //intervals 1 
                	           /*jitter .1*/  
                	           //variance 1.0/500
                	           scattering {4, rgb Atmosphere*3/Size extinction 1}
                                   absorption (1-< 0.1, 0.4, 0.9>)*.5/Size              
                                   density {onion
                                            density_map{
                                                    [0 rgb <.001,.01,.1>]
                                                    [.96 rgb <.001,.01,.1>*2]
                                                    [.97 rgb 1]  // earth
                                                    //[.98 rgb .5]//
                                                    [.99 rgb .1]//
                                                    [1 rgb 0 ]//
                                                    }
                                           }
                                         } 
                                  /*       
                                  media {
                			method 3
                			samples 2 intervals 1
                			scattering {4, color rgb < 0.25, 0.6, 0.9>*0.00075 extinction 1}
                		        }*/       
                                #if(Cloud) 
                                    media {
                			method 3 aa_threshold 0.1 aa_level 3
                			samples 10//6 
                			intervals 3 
                			/*jitter .1*/
                			scattering {2, color rgb .9/Size extinction 1} 
                			absorption 50/Size
                			density {d_clouds2}	
                			density {onion //warp{ turbulence .01 }
                				
                				density_map {
                					[.89  rgb 0]
                					[.979  rgb 0]
                					[.98  rgb 1]
                					[.988  rgb .035]
                					//[.989  rgb .1]
                					//[.99  rgb 0.035]
                					[.99  rgb 0]
                				}
                			
                			}
                			
                			/*
                			}
                			media {
                			method 3 //aa_threshold 0.1 aa_level 3
                			//samples 4 
                			intervals 1 
                			//jitter .1
                			scattering {2, color rgb .01 extinction 1} 
                			//absorption 30
                			density {d_clouds3}	
                			density {onion warp{ turbulence .01 }
                				
                				density_map {
                					//[.98  rgb 0]
                					[.9889  rgb 0]
                					[.989  rgb 1]
                					[.99  rgb 0]
                					//[1  rgb 0]
                				}
                			
                			}    
                			*/
                                #end
                                } }
                       rotate y*0
                       scale 1.03
                       hollow
                       double_illuminate
                       }
        #end
        #if(Cloud // *!ShowMedia 
                        )
               
        sphere{0,1.01 texture{t_clouds }
                       rotate y*0
                       hollow double_illuminate
                       }
         #end 
           
         
         sphere{0,1.025 pigment {rgbft<.9,.8,.1,1,.9>} 
               //rotate y*45
               hollow //double_illuminate
               }
       // } 
        
        


union{
// placement  of Planet Bue
union{  #if(RingCount)
         disc {<0, 0, 0>  y, 1.0, .7        // -O- RINGs -O-   
         //torus{8.5,1.5 scale y*.00001
                         pigment{spherical
                                 cubic_wave
                                 #declare RingMax=RingCount;
                                 #declare RingCount=0;
                                 
                                 colour_map{
                                            
                                            [0 rgbft <0,0,0, 1,1>] 
                                             
                                            #while  (RingCount<RingMax)
                                            
                                                    [((RingCount+.5)*(.21/RingMax))
                                                       colour rgbft <(RingTint.x)*(.5+.5*rand(Seed)),(RingTint.y)*(.5+.5*rand(Seed)),(RingTint.z)*(.5+.5*rand(Seed)),.2*rand(Seed),.8*rand(Seed)>
                                                    ]
                                                    
                                                    #declare RingCount=RingCount+1;
                                            #end
                                            
                                            [.22 rgbft <0,0,0, 1,1>]
                                            }
                                 }
                         normal{granite .001 scale .00001}
                         finish{diffuse .7 roughness .9 brilliance .2 }
                         scale 2
                         hollow
                         //double_illuminate
                         //rotate <40,0,30>
                         }
          #end
         object{PlanetBue rotate y*4.9*0}
         scale .3 
         //rotate -<40,0,30>
         translate <0,0,0>
         }  
        scale Size
        } 
#end // #macro NXPlanet(Size,Terra,Cloud,Atmosphere,Gas,GasLines,GasTurb,GasTint,RingCount,RingTint,Vulcanic,Sea,SeaCol,TerraCol,Foilage,FoilageCol,Ice)

// NXPlanet(Size,Terra,Cloud,AtmosphereCol,Gas,GasLines,GasTurb,GasTint,RingCount,RingTint,Vulcanic,Sea,SeaCol,TerraCol,Foilage,FoilageCol,Ice)
/*
#declare Size=1; 
#declare Terra=1;
#declare Cloud=0;
#declare AtmosphereCol=< 0.1, 0.4, 1>;
#declare Gas=0; 
#declare GasLines=10;
#declare GasTurb=.3;  
#declare GasTint=<.3,.5,1>;
#declare RingCount=10;
#declare RingTint=<.1,.2,.3>;
#declare Vulcanic=0;
#declare Sea=1;
#declare SeaCol=<.1,.2,.5>;
#declare TerraCol=<.5,.4,.3>;
#declare Foilage=0;
#declare FoilageCol=<.1,.5,.7>;
#declare Ice=1;

NXPlanet(Size,Terra,Cloud,AtmosphereCol,Gas,GasLines,GasTurb,GasTint,RingCount,RingTint,Vulcanic,Sea,SeaCol,TerraCol,Foilage,FoilageCol,Ice)


light_source {<2,.1,3>*1000000, color <2.1,2,1.9>*2 media_attenuation on}
sphere {<2,.1,3>*100, 7.5
	texture {
		pigment {color <2.1,2,1.9>/2}
		finish {ambient 10 diffuse 0}
	}
	no_shadow
}   


///////////////////////////////////////////////////////////////
////////////// Camera ////////////////////////////////////////
 
camera{
  location <0,.2,1>//<0,.299,0>//<0,0,.3>//<2,.1,3>/15//<0,0.2989, 0>//<0,.30055,0>//<0,.5,0>    // <.5,0,-1.2> 
  //rotate <16,0,-65>
  //up y 
  //sky <0,1,0>
  right x*image_width/image_height
  look_at 0 // 0//<2,.1,3>*1000000//<0,1,0>//<0,-.3,1> //<0,-.4,1> //   

}  
*/     