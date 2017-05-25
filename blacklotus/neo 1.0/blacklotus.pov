// This file is licensed under the terms of the CC-LGPL

#include "colors.inc"    // The include files contain

background { color rgb <0.2,0.25,0.2> }

camera {
    location <2, 5,  -7>
    look_at  <0, 0,  0>
    //scale 0.7
}

light_source { <0, 5, -3> color White}       
        
#declare black_petal = sphere {0,1 clipped_by { cone{<-1.1,-1>1<-.6.8>0} }  
  pigment {
      gradient x
      color_map {
        [0.1  color rgb <0.1,0.1,0.1>]
        [0.3  color rgb <0.3,0.2,0.2>]
        [0.6  color rgb <0.6,0.3,0.3>]
 
        [0.8  color rgb <0.8,0.6,0.6>]
        [1.0  color rgb <1,0.6,0.8>]
      }
  }   
} 
  
                     
#declare index = 1;           
#declare petals = 10;
#while(index <= petals)                     
object { black_petal 
         rotate x*0
         rotate y*0
         rotate z*45
         translate x * -1       
         rotate y*index*(360/petals) 
       }

            
#declare index = index + 1;
#end


#declare index = 1;           
#declare petals = 8;
#while(index <= petals)                     
 object { black_petal 
         rotate x*0
         rotate y*0
         rotate z*0
         translate x * -0.5       
         rotate y*index*(360/petals) 
         scale 0.8
       }

            
#declare index = index + 1;
#end                       


#declare index = 1;           
#declare petals = 3;
#while(index <= petals)                     
object { black_petal 
         rotate x*0
         rotate y*0
         rotate z*-45
         translate x * 0.4
         translate y * -0.8       
         rotate y*index*(360/petals) 
         scale 0.8
       }

            
#declare index = index + 1;

#end 

plane{<0,1,0>, -1
      texture{
        pigment{rgb <.1,.1,.1>}
        
              finish {ambient 0.15
                      diffuse 0.55
                      brilliance 6.0
                      phong 0.8
                      phong_size 120
                      reflection 0.6}
              }// end of texture
        normal{ bozo 1.75
         scale <2.0,1,0.3>*0.20
         rotate<0,10,0>
         turbulence 0.9
         translate<0,0,-2>
       /*
        normal{ bumps 0.3
        scale 0.05
        turbulence 0.6 */
      }               
     }// end of plane
