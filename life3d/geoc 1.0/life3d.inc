//
// life3d.inc
// ----------
// Created by David Sharp to provide a 3D POV-Ray implementation of John Conway's 'Game of Life' 
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett.
//
// This include file contains all of the macros and default parameter settings necessary to use 
// the Life3D macro.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The generated object is about 15 POV-Ray units high and about 15 wide and by default 
// is centred at the origin.
//
// Render times typically range from a few seconds per frame to a few minutes per frame,
// but can be a lot higher if you use a large 3D array of cells or if you use complex 
// shapes or textures for the individual cells.
//
// See life3d.html for more details.
//
// These macros are designed to be used with the POV-Ray animation options. For Example:
//   +kfi1 +kff56 
//


/*  
A 3-d implementation of John Conway's 'Game of Life' in POV-Ray script/macros.
It is meant to be used in an animated sequence of renderings. That is,
you should start POV-Ray with an 'ini' file set up for animation.
For example, see 'myanim.ini'.

The main macro to call in the scene file is
Life3D(Life3D_xs,Life3D_yS,Life3D_zs,Life3D_rules,Life3D_gen1From,Life3D_cellType,Life3D_wrap)
(see documentation for it below or in life3d.html)

Each generation saves the last generation in a file named by the variable 
Life3D_tempCellfilename
For example:
        #declare Life3D_tempCellfilename="lifecells.tmp";
The first three numbers in the file Life3D_tempCellfilename are the
cell array dimensions. Then come the 'x layers' of cells.
Each x layer is a 'yz' array of cell values.

*/ 

// some simple but interesting initially 'live' cell arrangements
#declare Life3D_OOOArray=array[3][3]{
        { 0,  0, -1},
        { 0,  0,  0},
        { 0,  0,  1}
} 
#declare Life3D_liveGlider5766=array[10][3]{
        { 0,  0,  0},
        { 0,  0,  1},
        { 0,  0, -1},
        { 0, -1,  1},
        { 0, -2,  0},
        { 1,  0,  0},
        { 1,  0,  1},
        { 1,  0, -1},
        { 1, -1,  1},
        { 1, -2,  0}
} 
#declare Life3D_liveGlider4555=array[10][3]{
        { 1,  0, -1},
        { 1, -1,  0},
        { 1, -1,  1},
        { 1,  0,  2},
        { 0,  0, -1},
        { 0, -1,  0},
        { 0, -1,  1},
        { 0,  0,  2},
        {-1,  0,  0},
        {-1,  0,  1}
}

#declare Life3D_rules3555=array[4]{3,5,5,5} 
#declare Life3D_rules5766=array[4]{5,7,6,6}
#declare Life3D_rules4555=array[4]{4,5,5,5}
#declare Life3D_rules3423=array[4]{3,4,2,3} 

// these are some default values 
#declare Life3D_tempCellfilename="life3d.tmp";
#declare Life3D_xsize=9;
#declare Life3D_ySize=9;
#declare Life3D_zsize=9;
#declare Life3D_livePercent=10;
#declare Life3D_initialGenerationFile="glider5766.lif";
#declare Life3D_liveArray=Life3D_liveGlider5766;
#declare Life3D_centerTheArray=1;
#declare Life3D_diffScale=0;
#declare Life3D_blobStrength=1;
#declare Life3D_blobThreshold=.4;
#declare Life3D_Tiles=0;
#declare Life3D_leaveCorpses=0;

#declare Life3D_cubeTexture=texture{
        pigment{rgb<1,0,0>}
}
/*
#declare Life3D_gbNewTexture=texture{
        pigment{rgb<0,1,0>}
}                    
#declare Life3D_gbOldTexture=texture{
        pigment{rgb<1,0,0>}
} 
*/                 
#declare Life3D_gbDiedTexture=texture{
        pigment{rgbt<1,1,1,.8>}
}

#declare Life3D_stateTextures=array[8]{
       texture{pigment{rgb<0,1,0>}},
       texture{pigment{rgb<1,0,0>}},
       texture{pigment{rgb<0,0,1>}},
       texture{pigment{rgb<1,1,0>}},
       texture{pigment{rgb<1,0,1>}},
       texture{pigment{rgb<0,1,1>}},
       texture{pigment{rgb<1,1,1>}},
       texture{pigment{rgb<0,0,0>}}
}                    
       


#declare Life3D_RS1=seed(12);
#macro Life3D_RND(Life3D_N)
        int(Life3D_N*rand(Life3D_RS1))
#end 

#declare Life3D_numLiveCells=0;

#macro Life3D_initCellArrayS(Life3D_xs,Life3D_yS,Life3D_zs)
        #declare Life3D_xsz=Life3D_xs;
        #declare Life3D_ysz=Life3D_yS;
        #declare Life3D_zsz=Life3D_zs;
        #declare Life3D_cells1Array=array[Life3D_xsz][Life3D_ysz][Life3D_zsz] 
        #declare Life3D_cells2Array=array[Life3D_xsz][Life3D_ysz][Life3D_zsz]
        
        Life3D_fillCellArrayWithZeroes(Life3D_cells1Array)
        Life3D_fillCellArrayWithZeroes(Life3D_cells2Array) 
#end

#macro Life3D_fillCellArrayRandomly(Life3D_cArray,Life3D_pct)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        
        
        #local Life3D_i=0;          
        #while (Life3D_i<Life3D_asz)
        
                
                #local Life3D_j=0;
                #while(Life3D_j<Life3D_bsz)  
                        #local Life3D_k=0;
                        #while (Life3D_k<Life3D_csz)         
                                #if(rand(Life3D_RS1)<Life3D_pct/100)
                                        #declare Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]=1;
                                        
                                #else                            
                                        #declare Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]=0;            
                                #end
                                #local Life3D_k=Life3D_k+1;    
                                
                        #end
                        #local Life3D_j=Life3D_j+1;
                #end
                #local Life3D_i=Life3D_i+1;
        #end
        
#end 
#macro Life3D_fillCellArrayWithZeroes(Life3D_cArray)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        
        #local Life3D_i=0;
        #while (Life3D_i<Life3D_asz)
                        
                #local Life3D_j=0;
                #while(Life3D_j<Life3D_bsz)  
                        #local Life3D_k=0;
                        #while (Life3D_k<Life3D_csz)
                                #declare Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]=0;            
                                
                                #local Life3D_k=Life3D_k+1;                                
                        #end
                        #local Life3D_j=Life3D_j+1;
                #end
                #local Life3D_i=Life3D_i+1;
        #end
        
#end 

#macro Life3D_liveCellsCount(Life3D_cArray)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        #local Life3D_liveCount=0;
        #local Life3D_i=0;
        #while (Life3D_i<Life3D_asz)
                        
                #local Life3D_j=0;
                #while(Life3D_j<Life3D_bsz)  
                        #local Life3D_k=0;
                        #while (Life3D_k<Life3D_csz)
                                #if (Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]>0)
                                    #local Life3D_liveCount=Life3D_liveCount+1;
                                #end
                                
                                #local Life3D_k=Life3D_k+1;                                
                        #end
                        #local Life3D_j=Life3D_j+1;
                #end
                #local Life3D_i=Life3D_i+1;
        #end
        Life3D_liveCount
#end 

#macro Life3D_cellObjectsCount(Life3D_cArray)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        #local Life3D_objectCount=0;
        #local Life3D_i=0;
        #while (Life3D_i<Life3D_asz)
                        
                #local Life3D_j=0;
                #while(Life3D_j<Life3D_bsz)  
                        #local Life3D_k=0;
                        #while (Life3D_k<Life3D_csz)
                                #if (Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]!=0) 
                                    #if(Life3D_leaveCorpses)    
                                        #local Life3D_objectCount=Life3D_objectCount+1;
                                    #else
                                        #if(Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]>0)           
                                                #local Life3D_objectCount=Life3D_objectCount+1;
                                        #end
                                    #end
                                #end
                                
                                #local Life3D_k=Life3D_k+1;                                
                        #end
                        #local Life3D_j=Life3D_j+1;
                #end
                #local Life3D_i=Life3D_i+1;
        #end
        Life3D_objectCount
#end                         
                        
#macro Life3D_translateCells(Life3D_cArray)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        #local Life3D_tempArray=array[Life3D_asz][Life3D_bsz][Life3D_csz]
        
        
        #local Life3D_liveCount=0;
        #local Life3D_i=0;
        #while (Life3D_i<Life3D_asz)
                        
                #local Life3D_j=0;
                #while(Life3D_j<Life3D_bsz)  
                        #local Life3D_k=0;
                        #while (Life3D_k<Life3D_csz)
                     
                                
                                #local Life3D_k=Life3D_k+1;                                
                        #end
                        #local Life3D_j=Life3D_j+1;
                #end
                #local Life3D_i=Life3D_i+1;
        #end
        
#end                         
#macro Life3D_initLiveCellsByArray(Life3D_cArray,Life3D_liveArray)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        
        #local Life3D_numLive=dimension_size(Life3D_liveArray,1);
        
        #local Life3D_i=0;
        #while(Life3D_i<Life3D_numLive)
            #local Life3D_ix=Life3D_liveArray[Life3D_i][0];
            #local Life3D_iy=Life3D_liveArray[Life3D_i][1];
            #local Life3D_iz=Life3D_liveArray[Life3D_i][2];
            #while (Life3D_ix<0)
                #local Life3D_ix=Life3D_ix+Life3D_asz;
            #end  
            #while (Life3D_ix>=Life3D_asz)
                #local Life3D_ix=Life3D_ix-Life3D_asz;
            #end
            #while (Life3D_iy<0)
                #local Life3D_iy=Life3D_iy+Life3D_bsz;
            #end  
            #while (Life3D_iy>=Life3D_bsz)
                #local Life3D_iy=Life3D_iy-Life3D_bsz;
            #end
            #while (Life3D_iz<0)
                #local Life3D_iz=Life3D_iz+Life3D_csz;
            #end  
            #while (Life3D_iz>=Life3D_csz)
                #local Life3D_iz=Life3D_iz-Life3D_csz;
            #end  
            
            
            #declare Life3D_cArray[Life3D_ix][Life3D_iy][Life3D_iz]=1; 
            
            #local Life3D_i=Life3D_i+1;
        #end                      
#end        

#macro Life3D_readCells(Life3D_cArray,Life3D_filename)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        
        
        #fopen Life3D_inFileHandle Life3D_filename read
        #read(Life3D_inFileHandle,Life3D_fasz)
        #read(Life3D_inFileHandle,Life3D_fbsz)
        #read(Life3D_inFileHandle,Life3D_fcsz)
        #if(Life3D_fasz>Life3D_asz | Life3D_fbsz>Life3D_bsz | Life3D_fcsz>Life3D_csz)
            
            #debug "Array size(s) in the file larger than scene file array size(s)\n" 
            #debug concat ("Reset to ",str(Life3D_fasz,0,0)," ",str(Life3D_fbsz,0,0)," ",str(Life3D_fcsz,0,0),"\n")
            Life3D_initCellArrayS(Life3D_fasz,Life3D_fbsz,Life3D_fcsz)
            #local Life3D_asz=Life3D_fasz;
            #local Life3D_bsz=Life3D_fbsz;
            #local Life3D_csz=Life3D_fcsz;
        #end
        
        #local Life3D_i=0;
        #while (Life3D_i<Life3D_fasz)
        
                
                #local Life3D_j=0;
                #while(Life3D_j<Life3D_fbsz)  
                        #local Life3D_k=0;
                        #while (Life3D_k<Life3D_fcsz)         
                                
                                #read(Life3D_inFileHandle,Life3D_inCell)
                                #declare Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]=Life3D_inCell;
                                
                                #local Life3D_k=Life3D_k+1;    
                                
                        #end 
                        
                        #local Life3D_j=Life3D_j+1;                    
                        
                #end
                #local Life3D_i=Life3D_i+1;
        #end
        
        #fclose  Life3D_inFileHandle
#end 


#macro Life3D_writeCells(Life3D_cArray, Life3D_filename)                      
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        
        #fopen Life3D_outFileHandle Life3D_filename write 
        #write(Life3D_outFileHandle, Life3D_asz) 
        #write(Life3D_outFileHandle,",")
        #write(Life3D_outFileHandle, Life3D_bsz)
        #write(Life3D_outFileHandle,",")
        #write(Life3D_outFileHandle, Life3D_csz)
        #write(Life3D_outFileHandle,",")
        #write(Life3D_outFileHandle,"\n")


        #local Life3D_i=0;
        #while (Life3D_i<Life3D_asz)
        
                
                #local Life3D_j=0;
                #while(Life3D_j<Life3D_bsz)  
                        #local Life3D_k=0;
                        #while (Life3D_k<Life3D_csz)         
                                #write(Life3D_outFileHandle,Life3D_cArray[Life3D_i][Life3D_j][Life3D_k])
                                #write(Life3D_outFileHandle,",")
                                #local Life3D_k=Life3D_k+1;    
                                
                        #end 
                        #write(Life3D_outFileHandle,"\n")
                        #local Life3D_j=Life3D_j+1;                    
                        
                #end  
                #write(Life3D_outFileHandle,"\n")
                #local Life3D_i=Life3D_i+1;
        #end
        
        #fclose  Life3D_outFileHandle
#end 



#macro Life3D_nextGenCells(Life3D_oldCArr,Life3D_newCArr,Life3D_rulesArray,Life3D_wrap)
  #local Life3D_XDim=dimension_size(Life3D_oldCArr,1);
  #local Life3D_YDim=dimension_size(Life3D_oldCArr,2);
  #local Life3D_ZDim=dimension_size(Life3D_oldCArr,3);
  
  // Initialise an array to store the neighbor counts.
  #declare Life3D_NeighborsArray = array[Life3D_XDim][Life3D_YDim][Life3D_ZDim];
  #local Life3D_i=0;
  #while (Life3D_i<Life3D_XDim)
    #local Life3D_j=0;
    #while(Life3D_j<Life3D_YDim)  
      #local Life3D_k=0;
      #while (Life3D_k<Life3D_ZDim)
        #declare Life3D_NeighborsArray[Life3D_i][Life3D_j][Life3D_k]=0; 
        #local Life3D_k=Life3D_k+1;
      #end
      #local Life3D_j=Life3D_j+1;
    #end
    #local Life3D_i=Life3D_i+1;
  #end        

  // Work out how many neighbors each cell has
  #if(Life3D_Debug) #debug "  Count Neighbors\n" #end
  #local Life3D_i=0;
  #while (Life3D_i<Life3D_XDim)
    #local Life3D_j=0;
    #while(Life3D_j<Life3D_YDim)  
      #local Life3D_k=0;
      #while (Life3D_k<Life3D_ZDim)
        #if (Life3D_oldCArr[Life3D_i][Life3D_j][Life3D_k]!=0)
          #if (Life3D_wrap)
            Life3D_RegisterNeighborWrap(Life3D_i,Life3D_j,Life3D_k)
          #else 
            Life3D_RegisterNeighborNoWrap(Life3D_i,Life3D_j,Life3D_k)
          #end
        #end 
        #local Life3D_k=Life3D_k+1;
      #end
      #local Life3D_j=Life3D_j+1;
    #end
    #local Life3D_i=Life3D_i+1;
  #end        

  #if(Life3D_Debug) #debug "  Interpret Rules\n" #end
  // Create the new life array based upon the number of neighbors a cell has
  #local Life3D_i=0;
  #while (Life3D_i<Life3D_XDim)
    #local Life3D_j=0;
    #while(Life3D_j<Life3D_YDim)  
      #local Life3D_k=0;
      #while (Life3D_k<Life3D_ZDim)
        #ifdef(Life3D_NeighborsArray[Life3D_i][Life3D_j][Life3D_k])
          #local Life3D_numAlive=Life3D_NeighborsArray[Life3D_i][Life3D_j][Life3D_k];
        #else
          #local Life3D_numAlive=0;
        #end 
        #if(Life3D_oldCArr[Life3D_i][Life3D_j][Life3D_k] >0)
          #if(Life3D_numAlive>=Life3D_rulesArray[0] & Life3D_numAlive<=Life3D_rulesArray[1])
            #declare Life3D_newCArr[Life3D_i][Life3D_j][Life3D_k]=2;
          #else
            #declare Life3D_newCArr[Life3D_i][Life3D_j][Life3D_k]=-1;   
          #end
        #else
          #if(Life3D_numAlive<Life3D_rulesArray[2]|Life3D_numAlive>Life3D_rulesArray[3])
               #declare Life3D_newCArr[Life3D_i][Life3D_j][Life3D_k]=0;
          #else
            #declare Life3D_newCArr[Life3D_i][Life3D_j][Life3D_k]=1;         
          #end
        #end                                        
        #local Life3D_k=Life3D_k+1;
      #end
      #local Life3D_j=Life3D_j+1;
    #end
    #local Life3D_i=Life3D_i+1;
  #end        
#end 

// A macro to increment neighboring cell counts if Wrapping is specified.
#macro Life3D_RegisterNeighborWrap(Life3D_i,Life3D_j,Life3D_k) 
  #local Life3D_XVal = select(Life3D_i,-1,Life3D_XDim-1,Life3D_i-1);
  #local Life3D_XCnt = 0;
  #while (Life3D_XCnt<3)
    #local Life3D_YVal = select(Life3D_j,-1,Life3D_YDim-1,Life3D_j-1);
    #local Life3D_YCnt = 0;
    #while (Life3D_YCnt<3)
      #local Life3D_ZVal = select(Life3D_k,-1,Life3D_ZDim-1,Life3D_k-1);
      #local Life3D_ZCnt = 0;
      #while (Life3D_ZCnt<3)
        #declare Life3D_NeighborsArray[Life3D_XVal][Life3D_YVal][Life3D_ZVal] 
               = Life3D_NeighborsArray[Life3D_XVal][Life3D_YVal][Life3D_ZVal] + 1;
        #local Life3D_ZVal = Life3D_ZVal+1;
        #if (Life3D_ZVal=Life3D_ZDim) #local Life3D_ZVal = 0; #end
        #local Life3D_ZCnt = Life3D_ZCnt+1;
      #end
      #local Life3D_YVal = Life3D_YVal+1;
      #if (Life3D_YVal=Life3D_YDim) #local Life3D_YVal = 0; #end
      #local Life3D_YCnt = Life3D_YCnt+1;
    #end
    #local Life3D_XVal = Life3D_XVal+1;
    #if (Life3D_XVal=Life3D_XDim) #local Life3D_XVal = 0; #end
    #local Life3D_XCnt = Life3D_XCnt+1;
  #end
#end

// A macro to increment neighboring cell counts if no Wrapping is required.
#macro Life3D_RegisterNeighborNoWrap(Life3D_i,Life3D_j,Life3D_k) 
  #local Life3D_XVal = max(Life3D_i-1,0);
  #while (Life3D_XVal<=min(Life3D_i+1,Life3D_XDim-1))
    #local Life3D_YVal = max(Life3D_j-1,0);
    #while (Life3D_YVal<=min(Life3D_j+1,Life3D_YDim-1))
      #local Life3D_ZVal = max(Life3D_k-1,0);
      #while (Life3D_ZVal<=min(Life3D_k+1,Life3D_ZDim-1))
        #declare Life3D_NeighborsArray[Life3D_XVal][Life3D_YVal][Life3D_ZVal] 
               = Life3D_NeighborsArray[Life3D_XVal][Life3D_YVal][Life3D_ZVal] + 1;
      #local Life3D_ZVal = Life3D_ZVal+1;
      #end
      #local Life3D_YVal = Life3D_YVal+1;
    #end
    #local Life3D_XVal = Life3D_XVal+1;
  #end
#end

// some option constants
#declare Life3D_cubeCells=0;
#declare Life3D_blobCells=1;

#declare Life3D_nowrap=0;
#declare Life3D_toruswrap=1; 

#declare Life3D_fromRandom=0;
#declare Life3D_fromFile=1;
#declare Life3D_fromliveArray=2;


#macro Life3D_placeOneLifeObject(Life3D_cType,Life3D_wx,Life3D_wy,Life3D_wz,Life3D_sc,Life3D_p1)
        #if(Life3D_cType=Life3D_cubeCells)   
            object{
                 #ifdef(Life3D_cellObject) 
                        Life3D_cellObject
                 #else
                        box{
                          -1/2,1/2
                        }
                 #end 
        #end
        #if(Life3D_cType=Life3D_blobCells)
                 sphere{<0,0,0>,1,Life3D_blobStrength
        #end
                 scale Life3D_sc  
                 translate <Life3D_wx,Life3D_wy,Life3D_wz> 
                 #switch(Life3D_p1)
                        #case(-1)
                                #ifdef(Life3D_gbDiedTexture) 
                                        texture{Life3D_gbDiedTexture}                                 
                                #end
                        #break
                        #case(1)                              
                                #ifdef(Life3D_gbNewTexture) 
                                        texture{Life3D_gbNewTexture}                                 
                                #else
                                        texture{Life3D_stateTextures[0]}
                                #end                           
                                
                        #break
                        #case(2)
                                #ifdef(Life3D_gbOldTexture) 
                                        texture{Life3D_gbOldTexture}                                 
                                #else
                                        texture{Life3D_stateTextures[1]}
                                #end
                        #break
                        
                 #end
                 
                 /*
                 #if(Life3D_p1=-1)
                        texture{Life3D_gbDiedTexture} 
                 #else  
                               
                        texture{Life3D_stateTextures[Life3D_p1-1]}    
                 #end 
                 
                 #if(Life3D_p1=2) 
                        texture{Life3D_gbOldTexture} 
                 #end    
                 #if(Life3D_p1=1)
                        texture{Life3D_gbNewTexture} 
                 #end
                 */
            }

#end
#macro Life3D_placeCellObject(Life3D_cellValue,Life3D_cType,Life3D_wrap,Life3D_ix,Life3D_iy,Life3D_iz,Life3D_asz,Life3D_bsz,Life3D_csz)
        #local Life3D_abscellValue=abs(Life3D_cellValue);
        #local Life3D_rr=1+Life3D_diffScale*(Life3D_abscellValue-1); 
        #local Life3D_PP=Life3D_Tiles;
        #if (Life3D_wrap=Life3D_nowrap)
                #local Life3D_PP=0;
        #end
        #if(Life3D_cellValue>0 |(Life3D_leaveCorpses & Life3D_abscellValue>0))

                #local Life3D_px=-Life3D_PP;
                #while (Life3D_px<=Life3D_PP)   
                        #local Life3D_py=-Life3D_PP;
                        #while(Life3D_py<=Life3D_PP)    
                                #local Life3D_pz=-Life3D_PP;
                                #while (Life3D_pz<=Life3D_PP) 
                                     
                                     Life3D_placeOneLifeObject(Life3D_cType,Life3D_ix+Life3D_px*Life3D_asz,Life3D_iy+Life3D_py*Life3D_bsz,Life3D_iz+Life3D_pz*Life3D_csz,Life3D_rr,Life3D_cellValue)
                               
                                     #local Life3D_pz=Life3D_pz+1;
                                #end   
                                
                                #local Life3D_py=Life3D_py+1;
                        #end
                        #local Life3D_px=Life3D_px+1;
                #end
                                   
        #end 
                                                
#end
#macro Life3D_placeCells(Life3D_cArray,Life3D_cType,Life3D_wrap)
        #local Life3D_asz=dimension_size(Life3D_cArray,1);
        #local Life3D_bsz=dimension_size(Life3D_cArray,2);
        #local Life3D_csz=dimension_size(Life3D_cArray,3);
        
          #if(Life3D_cType=0)
            union{      
          #end
          #if(Life3D_cType=1)
            blob{   threshold Life3D_blobThreshold      
          #end                        
             
                #local Life3D_i=0;
                #while (Life3D_i<Life3D_asz)
                
                        
                        #local Life3D_j=0;
                        #while(Life3D_j<Life3D_bsz)  
                                #local Life3D_k=0;
                                #while (Life3D_k<Life3D_csz)         
                                        
                                        #local Life3D_cellValue=Life3D_cArray[Life3D_i][Life3D_j][Life3D_k]; 
                                        Life3D_placeCellObject(Life3D_cellValue,Life3D_cType,Life3D_wrap,Life3D_i,Life3D_j,Life3D_k,Life3D_asz,Life3D_bsz,Life3D_csz)
                                        
                                        #local Life3D_k=Life3D_k+1;
                                #end
                                #local Life3D_j=Life3D_j+1;
                        #end
                        #local Life3D_i=Life3D_i+1;
                #end        
           }
        
        
#end


#macro Life3D_translateliveArray(Life3D_liveArray,Life3D_movex,Life3D_movey,Life3D_movez)
        #local Life3D_numLiveCells=dimension_size(Life3D_liveArray,1);
        #local Life3D_i=0;
        #while (Life3D_i<Life3D_numLiveCells)
                   
                #declare Life3D_liveArray[Life3D_i][0]=Life3D_liveArray[Life3D_i][0]+Life3D_movex;
                #declare Life3D_liveArray[Life3D_i][1]=Life3D_liveArray[Life3D_i][1]+Life3D_movey;
                #declare Life3D_liveArray[Life3D_i][2]=Life3D_liveArray[Life3D_i][2]+Life3D_movez;
                
                #local Life3D_i=Life3D_i+1;
        #end

#end 
#macro Life3D_centerliveArray(Life3D_liveArray)
        #local Life3D_numLiveCells=dimension_size(Life3D_liveArray,1);
        #local Life3D_i=0;
        #local Life3D_tx=0;#local Life3D_ty=0;#local Life3D_tz=0;
        #while (Life3D_i<Life3D_numLiveCells)
                   
                #local Life3D_tx=Life3D_liveArray[Life3D_i][0]+Life3D_tx;
                #local Life3D_ty=Life3D_liveArray[Life3D_i][1]+Life3D_ty;
                #local Life3D_tz=Life3D_liveArray[Life3D_i][2]+Life3D_tz;
                
                #local Life3D_i=Life3D_i+1;
        #end                                
        #local Life3D_avgx=int(Life3D_tx/Life3D_numLiveCells);
        #local Life3D_avgy=int(Life3D_ty/Life3D_numLiveCells);
        #local Life3D_avgz=int(Life3D_tz/Life3D_numLiveCells);
        
        #local Life3D_mmx=int((Life3D_xsize+1)/2)-1;
        #local Life3D_mmy=int((Life3D_ySize+1)/2)-1;                                              
        #local Life3D_mmz=int((Life3D_zsize+1)/2)-1;                                      
        
        Life3D_translateliveArray(Life3D_liveArray,Life3D_avgx+Life3D_mmx,Life3D_avgy+Life3D_mmy,Life3D_avgz+Life3D_mmz)

#end 


  


#macro Life3D(Life3D_xs,Life3D_yS,Life3D_zs,Life3D_rules,Life3D_gen1From,Life3D_cellType,Life3D_wrap,Life3D_genNum)
// Life3D_xs = 'x' direction width of cell array (integer)

// Life3D_yS = 'y' direction width of cell array (integer)

// Life3D_zs = 'z' direction width of cell array (integer)

// Life3D_rules = an array[4] of integers specifying the Life Life3D_rules
// Using Life3D_rulesArray=array[4]{r1,r2,r3,r4} 
// makes the rule: 
//        if a cell is already 'live' and it has from 
//        r1 through r2 (inclusive) live neighbors, then 
//                it remains alive in the next generation.
//                That is, it will survive. 
//        Otherwise it becomes 'dead'.
//        On the other hand. if the cell is now dead, then 
//        if it has from r3 through r4 (inclusive) live neighbors then 
//                it will be alive in the next generation.

// Life3D_gen1From tells where the first generation comes from. 
//      Life3D_fromliveArray takes an array of cell indexes and each
//              cell in the array will be 'alive' in the first generation.
//              For example, using the array
//                      #declare Life3D_liveArray= array[2][3]={{0,0,1},{0,0,0}}
//              would make two cells alive: the cell at 0,0,1 and the cell at 0,0,0
//              The second index of the array must be '3' since a cell is specified
//              by three indices
//   
//      Life3D_fromFile gets the first generation from a file name by 'Life3D_initialGenerationFile'
//              The file contains the cell Values for all of the cells in the Life game
//              cell value > 0 is alive. cell value <=0 is dead.
//              
//      Life3D_fromRandom generates the first generation randomly with Life3D_livePercent of the cells
//              alive.

// Life3D_cellType is either 'Life3D_cubeCells' (plain cubes occupy live cells, or some other object declared
//      as 'cellObject') or 'Life3D_blobCells' 
//      If 'Life3D_diffScale' > 0, then live cells which were 'just born' (weren't alive 
//      in the last generation) are green.
//      Alive cells which survived from the last generation are larger and red.
//      Cells which were alive in the last generation but are now dead are small and white)

// Life3D_wrap tells whether to Life3D_wrap the cell array or not.
//      Life3D_nowrap means that a cell on the edge of the cell array has no neighboring cells
//              outside the array.
//      Life3D_toruswrap 'Life3D_wraps' the array around from top to bottom and left to right. so a cell
//              at the edge has neighboring cells on the other side of the array.

// Life3D_genNum (an integer) is just which generation this is. The first generation is '0'
//       Currently this is only important to the macro to distinguish the first generation 
//      from the rest. If Initial_Frame = 1 (which is the default value) then you can use
//      frame_number-1 for Life3D_genNum
  #local Life3D_genNum = max(Life3D_genNum,0); 
  #ifndef(Life3D_Debug) #declare Life3D_Debug = false; #end
  #if(Life3D_Debug) #debug "Start Processing\n" #end

        Life3D_initCellArrayS(Life3D_xs,Life3D_yS,Life3D_zs) 
        #if(Life3D_genNum=0) // First time through, we need to initialize the cells
                #switch(Life3D_gen1From)
                        #case (Life3D_fromRandom)
                        // We can initialize the Cells randomly:                     
                                Life3D_fillCellArrayRandomly(Life3D_cells2Array,Life3D_livePercent)    
                        #break
                        #case (Life3D_fromFile)
                        // Or read a file:
                                Life3D_readCells(Life3D_cells2Array, Life3D_initialGenerationFile) 
                        #break
                        #case (Life3D_fromliveArray)
                        // Or read an array of 'live cell' indexes:
                                #if(Life3D_centerTheArray)
                                        Life3D_centerliveArray(Life3D_liveArray)
                                #end
                                Life3D_initLiveCellsByArray(Life3D_cells2Array,Life3D_liveArray)
                        #break
                #end
        #else   // Second time through, and thereafter, get last generation from the file 
                // Life3D_tempCellfilename and compute the next generation
                #if(Life3D_Debug) #debug "Read Data\n" #end
                
                Life3D_readCells(Life3D_cells1Array, Life3D_tempCellfilename ) 
                
                #if(Life3D_Debug) #debug "Calc Data\n" #end
                Life3D_nextGenCells(Life3D_cells1Array,Life3D_cells2Array,Life3D_rules,Life3D_wrap)
                
        #end        
        
        // put the live cells into the scene:
        #if(Life3D_cellObjectsCount(Life3D_cells2Array)>0)
                object{
                        Life3D_placeCells(Life3D_cells2Array,Life3D_cellType,Life3D_wrap)
                        texture{            // default texture
                                pigment{rgbt<1,1,1,1>}
                        }
                        translate <-(Life3D_xs-1/2)/2,-(Life3D_yS-1/2)/2,-(Life3D_zs-1/2)/2> 
                        
                } 
        #else
                #warning "No cell objects left!\n"
                box{<-(Life3D_xs-1/2)/2,-(Life3D_yS-1/2)/2,-(Life3D_zs-1/2)/2>,<(Life3D_xs-1/2)/2,(Life3D_yS-1/2)/2,(Life3D_zs-1/2)/2> pigment{rgbt<1,1,1,1>}}        
        #end  
        #if(Life3D_Debug) #debug "Write Data\n"  #end
        // lastly, write current cell generation to Life3D_tempCellfilename for the next generation/frame
        Life3D_writeCells(Life3D_cells2Array,Life3D_tempCellfilename) 


#end                                  

