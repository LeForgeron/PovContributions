
// labeller_documentimages.pov
// ---------------------------
// Created by Chris Bartlett January 2008
// This scene file demonstrates the use of the 'labeller' include file. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 0.001 POV-Ray units = 1mm   (1m = 1 POV-Ray unit)

// Purpose
// -------
// This scene file is used to re-generate the images used within the documentation contained in labeller.html. 
//
// To generate all images use the animation command line options +kfi1 +kff11 which sets ImageNumber to equal the frame_number.
// To generate a single image switch off animation and it will use ImageNumber = n, where 'n' is the number of the image you 
// specify here:
#if (frame_number=0) #local ImageNumber = 12;  // Set this to the required image number
#else                #local ImageNumber = frame_number;
#end 

light_source {   <-4,7.5 ,-10   >, rgb 1}
light_source {   < 8,7.5 ,-15   >, rgb 1}
light_source {   < 0,0.1,- 0.2>, rgb 0.4}

//**************************//
//  Correcting Fluid Label  //
//**************************// 
// Image 1 - Front of Correcting Fluid Label
#if (ImageNumber=1)
  #include "labeller_correctingfluid.inc" 
  object {Labeller()} 
#end

// Image 2 - Back of Correcting Fluid Label
#if (ImageNumber=2)
  #include "labeller_correctingfluid.inc" 
  #declare MyLabel = object {Labeller()}
  object {MyLabel rotate y*180}    
#end


//**************************//
//  Bottled Photons         //
//**************************// 
// Image 3
#if (ImageNumber=3)
  background {rgb 0.05}
  #include "labeller_bottledphotons.inc"
  object {Labeller() rotate y*115}    
  #include "labeller_bottledphotonsneck.inc"
  object {Labeller() rotate y*115}    
#end


//**************************//
//     Fruit Tin Labels     //
//**************************// 
//  Image 4 - Peaches with Green label - back right, on its side
#if (ImageNumber=4)
  background {rgb <0,0.1,0.1>}
  #include "labeller_peaches.inc" 
  object {Labeller()  rotate -60*y translate -x*0.04}
  object {Labeller()  rotate 150*y translate  x*0.04}
#end
  
//  Image 5 - Pears with Green label - right of centre
#if (ImageNumber=5)
  background {rgb <0,0.1,0.1>}
  #include "labeller_pears.inc" 
  object {Labeller()  rotate -60*y translate -x*0.04}
  object {Labeller()  rotate 150*y translate  x*0.04}
#end
  
//  Image 6 - Conference Pears label - far right
#if (ImageNumber=6)
  background {rgb <0,0.1,0.1>}
  #include "labeller_conferencepears.inc" 
  object {Labeller()  rotate -60*y translate -x*0.04}
  object {Labeller()  rotate 150*y translate  x*0.04}
#end

 
//**************************//
//     Ink Bottle Labels    //
//**************************// 
//  Image 7 - Price Writing Ink label - just left of centre
#if (ImageNumber=7)
  background {rgb <0.03,0.18,0.03>}
  #include "labeller_price.inc" 
  object {Labeller() rotate y*20} 
#end
  
//  Image 8 - Polyhedron example
#if (ImageNumber=8)
  background {rgb <0.03,0.18,0.03>}
  #include "labeller_polyhedron.inc" 
  object {Labeller() scale 0.7} 
#end
  
//  Image 9 - A fictitious black ink bottle label
#if (ImageNumber=9) 
  background {rgb <0.03,0.18,0.03>}
  light_source {   < -10,4,-30>, rgb 0.8}
  #include "labeller_blackink.inc" 
  object {Labeller() rotate y*40}
#end
  
//  Image 10 - A rendition of a genuine Tusche ink bottle label
#if (ImageNumber=10)
  background {rgb 0.1}
  #include "labeller_tusche.inc" 
  object {Labeller() rotate -y*17}
#end

//  Image 11 - A rendition of a hazardous substances sticker
#if (ImageNumber=11)
  background {rgb 0.1}
  #include "labeller_hazardlabel.inc" 
  object {Labeller()}
#end

//  Image 12 - A rendition of a hazardous substances sticker
#if (ImageNumber=12)
  background {rgb <0,0.1,0.1>}
  #include "labeller_peachesimage.inc" 
  object {Labeller()  rotate -60*y translate -x*0.04}
  object {Labeller()  rotate 150*y translate  x*0.04}
#end


//  Image 101 - The default design
#if (ImageNumber=101)
  #include "labeller.inc" 
  object {Labeller()}
#end




//  Image 99 - Used for testing
#if (ImageNumber=99)
  background {rgb 0.1}
//  #declare Labeller_PlainBack = 1;
  #declare Labeller_PlainBackColor = <1,1,0>;
  #include "test.inc"  
  #include "labeller.inc" 
  #declare Labeller_PolyhedronFaces = 4;
  #declare Labeller_LabelBottom = 0.02;
  #declare Labeller_LabelTop    = 0.06;  
  object {Labeller_Polyhedron() rotate y*60}
#end


//**************************//
//     Add a Camera         //
//**************************// 
// The include files should set default camera location and look_at variables.
#ifdef (Labeller_DefaultCameraLocation) 
  camera {location Labeller_DefaultCameraLocation look_at Labeller_DefaultCameraLook_At}
#end



