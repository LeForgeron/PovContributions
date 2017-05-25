//
// life3d.pov
// ----------
// Created by David Sharp to provide a 3D POV-Ray implementation of John Conway's 'Game of Life'
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett.
//
// This scene file illustrates the use of the macros contained in the 'life3d.inc' file.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The generated object is about 15 POV-Ray units high and about 15 wide and by default 
// is centred at the origin.
//
// Render times typically range from a few seconds per frame to a few minutes per frame,
// but can be a lot higher if you use a larger 3D array of cells or if you use complex 
// shapes or textures for the individual cells. This example takes a couple of minutes
// per frame on a reasonably fast machine.
//  
// See life3d.html for more details.
//
// These macros are designed to be used with the POV-Ray animation options. For Example:
//   +kfi1 +kff56 
//

camera {location <0, 45,-70> look_at <0,0,-20>}
//camera {location <0, 5,-26> look_at <0,0,-5>} // (Use with alternative matrix dimensions)
light_source {<-300, 200,-1000> color rgb 1}

global_settings {
  #if (version <3.7) assumed_gamma 1.0 #end
}

#include "life3d.inc" 

// The following optional settings can be overridden if you wish:

//#declare Life3D_RS1=seed(341);                                                                      
//#declare Life3D_gbNewTexture=texture{pigment{rgb<0,1,0>}}                    
//#declare Life3D_gbOldTexture=texture{pigment{Red}}      
//#declare Life3D_gbDiedTexture=texture{pigment{White transmit .8}}

//#declare Life3D_diffScale=.5;  
#declare Life3D_livePercent=4; 
//#declare Life3D_liveArray=Life3D_liveGlider4555; 
//#declare myrules=array[4]{3,5,4,5}
//#declare Life3D_cellObject=sphere{0,1/2}

//#declare Life3D_Debug = true;
//#declare Life3D_tempCellfilename="tempfile.tmp"; 

// The macro returns a single object that you can scale, rotate and translate as required.
object{
  Life3D(
    100,5,100,            // x, y and z dimensions of the Life array
//    20,20,20,           // x, y and z dimensions of the Life array (Use with alternative camera)
    array[4]{3,5,4,8},    // 4D Life Rules array (see life3d.html)
    Life3D_fromRandom,    // Take First generation lifeform from Life3D_liveArray, Life3D_fromFile or Life3D_fromRandom.
    Life3D_blobCells,     // Cell type (Life3D_blobCells or Life3D_cubeCells)
    false,                // Whether or not to wrap the cells (true or false)
    frame_number-1        // Generation indicator.
  )
}




