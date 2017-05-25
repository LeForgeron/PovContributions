
// labeller.pov
// ------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This scene file demonstrates the use of the 'labeller' include file. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 0.001 POV-Ray units = 1mm   (1m = 1 POV-Ray unit)
//
// Render Times
// ------------
// Individual labels typically add a few seconds to the render time. 
//
// This example scene contains 10 labels, some with multiple parts and transparency defined.
// Render time is typically 2-3 minutes at 640x480 with AA 0.3 and AddBackgroundSurfaces set to '0'.
// Render time is typically 3-4 minutes at 640x480 with AA 0.3 and AddBackgroundSurfaces set to '1'.
// This goes up to 15-20 minutes with AddBackgroundSurfaces set to '2' to add jittered reflection to the background planes.
//

// The following setting enable you to quickly switch on/off the background.
#local AddBackgroundSurfaces = 0;    // 0=Off, 1=No Reflection, 2=Reflective      

background {rgb <0.05,0.2,0.05>}

light_source {   <-4,7.5 ,-10   >, rgb 1}
light_source {   < 8,7.5 ,-15   >, rgb 1}
light_source {   < 0,0.1,- 0.2>, rgb 0.4}
camera {location < 0,0.1,- 0.18> look_at <0,0.04,0>}

//**************************//
//  Correcting Fluid Label  //
//**************************// 
// Example 1 - Correcting Fluid - Centre
#include "labeller_correctingfluid.inc" 
Labeller() 

// Example 2 - Back of Correcting Fluid Label
#declare MyLabel = object {Labeller()}
object {MyLabel rotate y*180 translate <0.035,0,-0.01>}    



//**************************//
//  Bottled Photons         //
//**************************// 
// Example 3 
#include "labeller_bottledphotons.inc"
object {Labeller() rotate y*120 translate <0.075,0,-0.035>}    
#include "labeller_bottledphotonsneck.inc"
object {Labeller() rotate y*120 translate <0.075,0,-0.035>}    

 

//**************************//
//     Fruit Tin Labels     //
//**************************// 
// Example 4 - Peaches with Green label - back right, on its side
#include "labeller_peaches.inc" 
object {Labeller()  rotate -30*y translate -x*Labeller_ObjectRadius rotate -z*90 rotate y*48 translate <0,0.01,0.23>}

// Example 5 - Pears with Green label - right of centre
#include "labeller_pears.inc" 
object {Labeller() rotate -y*90 translate <-0.03,0.01,0.14>}

// Example 6 - Conference Pears label - far right
#include "labeller_conferencepears.inc" 
object {Labeller() rotate y*8 translate <0.09,0.01,0.10>}

 
//**************************//
//     Ink Bottle Labels    //
//**************************// 
// Example 7 - Price Writing Ink label - just left of centre
#include "labeller_price.inc" 
object {Labeller() rotate y*20 translate <-0.04,0,-0.03>} 

// Example 8 - Polyhedron example
#include "labeller_polyhedron.inc" 
object {Labeller() scale 0.7 translate <-0.1,0,-0.04>} //translate <-0.1,0,0.125>} 

// Example 9 - A fictitious black ink bottle label
#include "labeller_blackink.inc" 
object {Labeller() rotate -y*50 translate <-0.065,0,-0.074>}

// Example 10 - A rendition of a genuine Tusche ink bottle label
#include "labeller_tusche.inc" 
object {Labeller() rotate -y*47 translate <-0.12,0,0.05>}


//**************************//
//   Hazard Warning Label   //
//**************************// 
// Example 11 - A rendition of the hazard warning label on the backing plane
#include "labeller_hazardlabel.inc" 
object {Labeller() rotate <-90,0,-20> translate <-0.03,0.04,0> translate 0.4*z rotate -y*35}





//**************************//
//     Background Surfaces  //
//**************************// 

// Set to 0 for quick render, 1 to include mirrors and sky
#if (AddBackgroundSurfaces>0)
  #local BlurAmount  = .2; // Amount of blurring 
  #local BlurSamples = 50; // How many rays to shoot 
  #if (AddBackgroundSurfaces=2)  
    #local ReflectivePlaneTexture1 = texture {
      average texture_map {
      #declare Ind = 0; 
      #declare S = seed(0); 
        #while(Ind < BlurSamples) 
          [1
             pigment { rgb <0.1 ,0.1,0>*8} 
             finish { reflection 0.3 } 
             normal { 
               bumps BlurAmount 
               translate <rand(S),rand(S),rand(S)>*100
               scale 0.00001 
             } 
          ] 
          #declare Ind = Ind+1; 
        #end     
      } 
    }
  #else 
    #local ReflectivePlaneTexture1 = texture {  
      pigment { rgb <0.1 ,0.1,0>*8} 
    }
  #end 
  
  plane {y,-0.001 texture {ReflectivePlaneTexture1}}    


  #local BlurAmount  = .1; // Amount of blurring 
  #local BlurSamples = 50; // How many rays to shoot 
  #if (AddBackgroundSurfaces=2)  
  #local ReflectivePlaneTexture2 = texture {
    average texture_map {
    #declare Ind = 0; 
    #declare S = seed(0);
      #while(Ind < BlurSamples) 
        [1 
           pigment { rgb <0.25,0.15,0.1>*3} 
           finish { reflection 0.5 } 
           normal { 
             bumps BlurAmount 
             translate <rand(S),rand(S),rand(S)>*100
             scale 0.00001 
           } 
        ] 
        #declare Ind = Ind+1; 
      #end 
    } 
  } 
  #else 
    #local ReflectivePlaneTexture2 = texture {  
      pigment { rgb <0.1 ,0.1,0>*8} 
    }
  #end 
  
  plane {-z,-0.4 rotate -y*35 texture {ReflectivePlaneTexture2}}    

  
  #include "colors.inc"
  sky_sphere {
    pigment {
      marble turbulence 2 
      color_map {
        [ 0.3  color CornflowerBlue ]
        [ 0.6  color White ]
        [ 1.0  color MidnightBlue ]
      }
      scale 0.7
      rotate z*90
    }
  }
#end  



