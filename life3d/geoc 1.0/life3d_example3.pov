//
// life3d_example3.pov
// -------------------
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
// but can be a lot higher if you use a large 3D array of cells or if you use complex 
// shapes or textures for the individual cells. This example takes a few seconds
// per frame on a reasonably fast machine.
//
// See life3d.html for more details.
//
// These macros are designed to be used with the POV-Ray animation options. For Example:
//   +kfi1 +kff56 
//

 

#include "colors.inc"

global_settings {
  #if (version <3.7) assumed_gamma 1.0 #end
}


// The array of cells will be centered on <0,0,0>
// and its size will be the array dimensions.
// For example, an 11x11x11 array will be as large
// as box{0,11}
camera {
  location  <-15.0, 12, 12>

  look_at   <0.0, 0.0,  0.0> 
  angle 40
}

sky_sphere {
  pigment {
    bozo
    color_map {
      [0.0 rgb <0.8,0.7,1.0>]
      [0.7 rgb <0.0,0.1,0.8>]
    }
    scale .5
  }
  
}

light_source {
  <-300, 100, 0>
  color rgb <1, 1, 1>
  
}


#include "life3d.inc"

// declare these variables *after* calling life3d.inc
// so that they will override the defaults 

#declare Life3D_RS1=seed(31);              

// Life3D_gbNewTexture is the texture given cells which came alive in the
// current generation
#declare Life3D_gbNewTexture=texture{
        pigment{Green}
} 

// Life3D_gbOldTexture is the texture given live cells which were alive in the
// last generation                   
#declare Life3D_gbOldTexture=texture{
        pigment{Red}
}
// Life3D_gbDiedTexture is the texture given cells which were alive in the
// last generation but are now dead.                  
#declare Life3D_gbDiedTexture=texture{
        pigment{White transmit .8}
}


#declare Life3D_diffScale=.5;// .5 makes 'old'  cells 50% larger than new ones.
                      // diffScale=0 keeps old and new the same size  

// Size of the cell array
// If these dimensions are odd numbers then there is a 'central cell'
// which can be at the center of a scene.
#declare xsize=7;
#declare ySize=7;
#declare zsize=7;

// Each of the three wayS to get an initial generation requires some
// additional parameter
// 1)      To generate live cells randomly, livePercent needs to be specified. to generate live cells randomly
#declare Life3D_livePercent=20; // livePercent=10 makes 10 percent of the array live cells                                           


// 2)     a file of cell values, initialGenerationFile, needs to be specified in order to make the
//      first generation from a file. The file needs to be the same format as those saved by the
//      3dlife macro 'Life3D_writeCells(filename)'
//#declare Life3D_initialGenerationFile="glider5766.lif";
//      could use tempCellfilename to pickup from the end
//      of the last run
//#declare Life3D_initialGenerationFile="lifecells.tmp";


// 3)     an array of indexes of the live cells needs to be specified in order
//      to generate from a 'live array'
//#declare Life3D_liveArray=OOOArray; 
//      it might be convenient to define the liveArray about 0,0,0. 
//      For example:     
#declare Life3D_liveArray=array[7][3]{{0,-1,0},{-1,0,0},{0,0,-1},{0,1,0},{1,0,0},{0,0,1},{0,0,0}} 
//      in which case, the cells need to be centered in the cell array (all indices must
//      be positive before computing the next generation).
#declare Life3D_centerTheArray=1;


#declare myrules=array[4]{5,7,4,7}
//#declare myrules=rules5766

// a declared 'cellObject' replaces the default cube 
// cells are 1x1, and cellObjects should be centered on <0,0,0>
//#declare Life3D_cellObject=sphere{0,1/2}
                                                                         
#declare Life3D_leaveCorpses=0;                                                                         
#declare Life3D_Tiles=0;                                                                         
// the scene dimensions of the entire cell array is xsize x ySize x zsize
object{
        
        Life3D(xsize,ySize,zsize,myrules,Life3D_fromliveArray,Life3D_blobCells,Life3D_toruswrap,frame_number-1) 

}
// ---- end of scene  

// The main macro to call is
// Life3D(xs,yS,zs,rules,gen1From,cellType,wrap)
//
// xs = 'x' direction width of cell array (integer)

// yS = 'y' direction width of cell array (integer)

// zs = 'z' direction width of cell array (integer)

// rules = an array[4] of integers specifying the Life rules
// Using rulesArray=array[4]{r1,r2,r3,r4} 
// makes the rule: 
//        if a cell is already 'live' and it has from 
//        r1 through r2 (inclusive) live neighbors, then 
//                it remains alive in the next generation.
//                That is, it will survive. 
//        Otherwise it becomes 'dead'.
//        On the other hand. if the cell is now dead, then 
//        if it has from r3 through r4 (inclusive) live neighbors then 
//                it will be alive in the next generation.

// gen1From tells where the first generation comes from. 
//      fromliveArray takes an array of cell indexes and each
//              cell in the array will be 'alive' in the first generation.
//              For example, using the array
//                      #declare liveArray= array[2][3]={{0,0,1},{0,0,0}}
//              would make two cells alive: the cell at 0,0,1 and the cell at 0,0,0
//              The second index of the array must be '3' since a cell is specified
//              by three indices
//   
//      fromFile gets the first generation from a file name by 'initialGenerationFile'
//              The file contains the cell Values for all of the cells in the Life game
//              cell value > 0 is alive. cell value <=0 is dead.
//              
//      fromRandom generates the first generation randomly with livePercent of the cells
//              alive.

// cellType is either 'cubeCells' (plain cubes occupy live cells, or some other object declared
//      as 'cellObject') or 'blobCells'
//      If 'diffScale' >0, then live cells which were 'just born' (weren't alive in the 
//      last generation) are green.
//      Alive cells which survived from the last generation are larger and red.
//      Cells which were alive in the last generation but are now dead are small and white

// wrap tells whether to wrap the cell array or not.
//      nowrap means that a cell on the edge of the cell array has no neighboring cells
//              outside the array.
//      toruswrap 'wraps' the array around from top to bottom and left to right. so a cell
//              at the edge has neighboring cells on the other side of the array.

// genNum (an integer) is just which generation this is. The first generation is '0'
//       Currently this is only important to the macro to distinguish the first generation 
//      from the rest. If Initial_Frame = 1 (which is the default value) then you can use
//      frame_number-1 for genNum