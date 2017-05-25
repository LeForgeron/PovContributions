// This file is licensed under the terms of the CC-LGPL.

/***************************************************************************************************/
/* Eye.inc  - Copyright Chris Bartlett 7 May 2004                                                  */
/* This work is also licensed for royalty free re-use under the terms of the POV-Person License.   */
/* To view a copy of this license, visit http://www.telinco.co.uk/c_bartlett/license/license.htm   */
/***************************************************************************************************/

// Eye_Colour:     1=Blue, 2=Brown, 3=Green 
// Eye_Brightness: Normally between 0.5 and 1 
// Eye_Pupil:      Normally between 0.5 and 1.2


#macro Eye()
  #ifndef (Eye_Camera)     #declare Eye_Camera="Eyeball"; #else #local Eye_Camera_Set     = 1; #end
  #ifndef (Eye_Colour)     #declare Eye_Colour = 3;       #else #local Eye_Colour_Set     = 1; #end                       
  #ifndef (Eye_Brightness) #declare Eye_Brightness = 1;   #else #local Eye_Brightness_Set = 1; #end                       
  #ifndef (Eye_Pupil)      #declare Eye_Pupil = 1;        #else #local Eye_Pupil_Set      = 1; #end    

  #ifndef (Eye_Radius)     #declare Eye_Radius = 1;       #else #local Eye_Radius_Set     = 1; #end
  
  #ifndef (Eye_InnerRadius      ) #declare Eye_InnerRadius       = Eye_Radius * 0.992;                   #else #local Eye_InnerRadius_Set       = 1; #end
  #ifndef (Eye_PupilOuterRadius ) #declare Eye_PupilOuterRadius  = Eye_Radius/2.4;                       #else #local Eye_PupilOuterRadius_Set  = 1; #end
  #ifndef (Eye_PupilInnerRadius ) #declare Eye_PupilInnerRadius  = Eye_PupilOuterRadius/2;               #else #local Eye_PupilInnerRadius_Set  = 1; #end
  #ifndef (Eye_CorneaThickness  ) #declare Eye_CorneaThickness   = Eye_PupilOuterRadius*Eye_Pupil*3.5/6; #else #local Eye_CorneaThickness_Set   = 1; #end
  #ifndef (Eye_CorneaRadius     ) #declare Eye_CorneaRadius      = ( pow(Eye_PupilOuterRadius,2)                                               
                                                                    +pow(Eye_CorneaThickness ,2))                                              
                                                                   /(2*Eye_CorneaThickness);             #else #local Eye_CorneaRadius_Set      = 1; #end
  #ifndef (Eye_PupilDisplacement) #declare Eye_PupilDisplacement = sqrt(                                                 
                                                                     pow(Eye_Radius,2)
                                                                    -pow(Eye_PupilOuterRadius,2));       #else #local Eye_PupilDisplacement_Set = 1; #end
  
  #ifndef (Eye_OuterTexture1) 
    #declare Eye_OuterTexture1 = texture {
      pigment {crackle
        turbulence 0.5
        form <-1,1,0> 
        color_map {
          [0.0   color <1,0,0>]
          [0.025 color <1, 0.9020, 0.9020>]
          [0.975 color <1, 0.9020, 0.9020>]
          [1.0   color <1,0,0>]
        }
        scale <0.5,0.5,0.2>*Eye_Radius  
      }
      finish { ambient rgb<0.1000, 0.1000, 0.1000> diffuse 0.8000 phong 1 }
    }
    texture {
      pigment {crackle
        turbulence 0.5
        form <-1,1,0> 
        color_map {
          [0.0   color <1,0,0>]
          [0.025 color <1, 0.9020, 0.9020,1>]
          [0.975 color <1, 0.9020, 0.9020,1>]
          [1.0   color <1,0,0>]
        }
        scale <0.5,0.5,0.2>*Eye_Radius/5  
      }
      finish { ambient rgb<0.1000, 0.1000, 0.1000> diffuse 0.8000 phong 1 }
    } 
    #else #local Eye_OuterTexture1_Set = 1;
  #end    

  #ifndef (Eye_OuterTexture2) 
    #declare Eye_OuterTexture2 = texture {
      pigment { color rgb <1, 0.9020, 0.9020> }
      finish { ambient rgb<0.07, 0.07, 0.07> diffuse 0.8000 phong 1 }
    }
    #else #local Eye_OuterTexture2_Set = 1;
  #end    
      
  #ifndef (Eye_OuterTexture) 
    #declare Eye_OuterTexture = texture {
      gradient -z
      texture_map {
        [ 0.0  Eye_OuterTexture1 ]
        [ 0.78 Eye_OuterTexture1 ]
        [ 0.92 Eye_OuterTexture2 ]
        [ 1.0  Eye_OuterTexture2 ]
      }
      scale Eye_Radius*z*2
      translate Eye_Radius*z
    }
    #else #local Eye_OuterTexture_Set = 1;
  #end       
                                       
  #ifndef (Eye_InnerTexture) #declare Eye_InnerTexture = texture {pigment { color rgb<1, 0, 0> }}
  #else #local Eye_InnerTexture_Set = 1;
  #end                                            
  
  union {
    difference {   
      sphere {<0,0,0>,Eye_Radius
        texture {Eye_OuterTexture}
      }     
      sphere {<0,0,0>,Eye_InnerRadius
        texture {Eye_InnerTexture}
      }     
      cylinder {<0,0,-sqrt(pow(Eye_InnerRadius,2)-pow(Eye_PupilOuterRadius,2))>,
                <0,0,-Eye_Radius*1.001>,
                Eye_PupilOuterRadius
        texture {Eye_InnerTexture}
      }  
    }
    disc {
      <0, 0, 0>  // center position
      z,         // normal vector
      Eye_PupilOuterRadius,          // outer radius
      Eye_PupilInnerRadius*Eye_Pupil // iris radius    
      texture {   
        pigment { radial frequency 6        turbulence 0.25  
          #if (Eye_Colour=1)
            color_map {
              [0    color rgb <0.9,1,1>     * Eye_Brightness]  
              [0.25 color rgb <0.4,0.7,0.7> * Eye_Brightness]  
              [0.5  color rgb <0.7,1,1>     * Eye_Brightness]  
              [0.75 color rgb <0.4,0.7,0.7> * Eye_Brightness]  
              [1    color rgb <0.9,1,1>     * Eye_Brightness]  
            }                        
          #end
          #if (Eye_Colour=2)
            color_map {
              [0    color rgb <0.5,0.25,0.25>    * Eye_Brightness]  
              [0.25 color rgb <0.25,0.125,0.125> * Eye_Brightness]  
              [0.5  color rgb <0.5,0.25,0.25>    * Eye_Brightness]  
              [0.75 color rgb <0.25,0.125,0.125> * Eye_Brightness]  
              [1    color rgb <0.5,0.25,0.25>    * Eye_Brightness]  
            }                        
          #end
          #if (Eye_Colour=3)
            color_map {
              [0    color rgb <0.25,0.5,0.25>    * Eye_Brightness]  
              [0.25 color rgb <0.125,0.25,0.125> * Eye_Brightness]  
              [0.5  color rgb <0.25,0.5,0.25>    * Eye_Brightness]  
              [0.75 color rgb <0.125,0.25,0.125> * Eye_Brightness]  
              [1    color rgb <0.25,0.5,0.25>    * Eye_Brightness]  
            }                        
          #end 
          }
        rotate x*90 scale <1,1,0.001>   
        scale Eye_PupilOuterRadius/6.2
        }
      texture {
        pigment { spherical
          color_map {
            [0                 rgbt 0.2 ]  
            [0.2               rgbt <0.1,0.1,0.1,1> ]  
            [0.3               rgbt <1,1,1,1> ]
            [0.4               rgbt <1,1,1,0.9> ]
            [0.5               rgbt <1,1,1,1> ]
            [1-Eye_PupilInnerRadius*Eye_Pupil/Eye_PupilOuterRadius   rgbt <1,1,1,0.6> ] 
          } 
        }
        scale Eye_PupilOuterRadius
      } 
      translate <0, 0, -Eye_PupilDisplacement>
      no_shadow  
    }
    difference {
      sphere {<0,0,-Eye_PupilDisplacement+(Eye_CorneaRadius-Eye_CorneaThickness)>, Eye_CorneaRadius}
      sphere {<0,0,0>,Eye_Radius}
      texture {
        pigment {color rgbt <1,1,1,0.94>}
        finish {phong 1}
      } 
      no_shadow
    }
  }  
  
  #ifndef (Eye_Colour_Set           ) #undef Eye_Colour            #end
  #ifndef (Eye_Brightness_Set       ) #undef Eye_Brightness        #end
  #ifndef (Eye_Pupil_Set            ) #undef Eye_Pupil             #end
  #ifndef (Eye_Radius_Set           ) #undef Eye_Radius            #end
  #ifndef (Eye_InnerRadius_Set      ) #undef Eye_InnerRadius       #end    
  #ifndef (Eye_PupilOuterRadius_Set ) #undef Eye_PupilOuterRadius  #end
  #ifndef (Eye_PupilInnerRadius_Set ) #undef Eye_PupilInnerRadius  #end
  #ifndef (Eye_CorneaThickness_Set  ) #undef Eye_CorneaThickness   #end
  #ifndef (Eye_CorneaRadius_Set     ) #undef Eye_CorneaRadius      #end
  #ifndef (Eye_PupilDisplacement_Set) #undef Eye_PupilDisplacement #end   
  #ifndef (Eye_OuterTexture1_Set    ) #undef Eye_OuterTexture1     #end
  #ifndef (Eye_OuterTexture2_Set    ) #undef Eye_OuterTexture2     #end
  #ifndef (Eye_OuterTexture_Set     ) #undef Eye_OuterTexture      #end
  #ifndef (Eye_InnerTexture_Set     ) #undef Eye_InnerTexture      #end
 
#end

#ifndef(Eye_Camera)
  Eye()
  #if (strcmp(Eye_Camera,"Eyeball")=0)  
    camera {
      location <-2, 0, -4>
      look_at <0, 0, 0>
      angle 34.3775
    }
    
    light_source { <250, 60,-8900> color rgb<1, 1, 1>*0.6 }   
    light_source { <0, 1400,-1600> color rgb<1, 1, 1>*1.2 }   
    light_source { <0, 60,0> color rgb<1, 0.5, 0.5>}  
  #end                                                    
#end   

