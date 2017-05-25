
// This file is licensed under the terms of the CC-LGPL

// Carbonated fluid bubble generator 
// Created by Charles Robertson, 14 July 2009

// Optimised for POV-Ray 3.6

/**
Description: Creates collumns of bubbles, representing CO2 inside a fluid.
Bubbles increase in size the higher they ascend, in line with a decrease in fluid pressure
Bubbles collumns are placed randomly within  a specified cylinder vector
Bubble start/end position can be modified
Bubble start/end radius can be modified
Bubble collumn quantity can be modified
Bubble texture can be modified
**/

/** 
Parameters:

// REQUIRED
// a cylinder defines the boundaries of a the bubble area
cylinder{<sFluidX,sFluidY,sFluidZ>,<eFluidX,eFluidY,eFluidZ> fRadius}

// REQUIRED
// other parameters
fHeightRngE = the height at which the bubbles emanate, above the initial start height (sFluidY)
fBblHeightRngS = bubble start radius; the radius of bubbles at sFluidY
fBblHeightRngE = bubble end radius, the radius of bubbles at eFluidY
collumnNm = amount of randomly placed bubble collumns
bblTx = texture of bubble
**/

/**
Example:
#include "bubble.inc"
#declare bblTexture = texture {finish {ambient 0.3 diffuse 0.1 reflection 0.25 specular 1 roughness 0.001} pigment {color rgbf <1,1,1,0.7>}}
#declare bubbleGenerator = mBubbleGenerator(0,0.9,0,0,6.5,0,2.4,2.7,0.0005,0.0006,70,bblTexture)
**/




// Includes

#include "math.inc" 
#include "transforms.inc"
#include "rand.inc"


// Macro

#macro mBubbleGenerator (sFluidX,sFluidY,sFluidZ,eFluidX,eFluidY,eFluidZ,fRadius,fHeightRngE,fBblHeightRngS,fBblHeightRngE,collumnNm,bblTx)  
#local varInitHeightRangeStart = sFluidY;
#local varInitHeightRangeEnd = fHeightRngE;
#local varInitBubbleHeightRangeStart = fBblHeightRngS;
#local varInitBubbleHeightRangeEnd = fBblHeightRngE;
#local varInitHeight = RRand(varInitHeightRangeStart,varInitHeightRangeEnd,1); 
#local varInitBubbleRange = RRand(varInitBubbleHeightRangeStart,varInitBubbleHeightRangeEnd,1);
#local varInitBubbleHeight = varInitBubbleRange;
#local varInitFluidHeight = eFluidY - sFluidY;
#local varInitBubbleNumber = (varInitFluidHeight/varInitBubbleHeight)/2; 
#local varCounter = 1; 

#local varCollumnCount = 0;
#local varX = 0;
#local varZ = 0; 
#local varXtest = varX+fRadius;
#local varZtest = varZ+fRadius;
#local varFluidX = eFluidX+fRadius;
#local varFluidZ = eFluidZ+fRadius;  

union{

#while (varCollumnCount<collumnNm)                                           
#while (varInitHeight<eFluidY) 
sphere { <varX, varInitHeight, varZ>, varInitBubbleHeight texture {bblTx}} 
#local varInitHeight = varInitHeight+(varInitBubbleHeight*varCounter)+(varInitBubbleHeight*2);
#local varInitBubbleHeight = varInitBubbleHeight + (varInitBubbleHeight*(varInitHeight/10));
#local varCounter = varCounter+1;
#end   
 
#local varX = RRand(sFluidX,(sFluidX+fRadius),1);
#local varZ = RRand(sFluidZ,(sFluidZ+fRadius),1);

#if(sFluidX = 0 & ceil(SRand(1)) = 0) 
#local varX = RRand(sFluidX,(sFluidX-fRadius),1);
#end
#if(sFluidX = 0 & ceil(SRand(1)) = 1)
#local varX = RRand(sFluidX,(sFluidX+fRadius),1); 
#end
#if(sFluidZ = 0 & ceil(SRand(1)) = 0) 
#local varZ = RRand(sFluidZ,(sFluidZ-fRadius),1);
#end
#if(sFluidZ = 0 & ceil(SRand(1)) = 1)
#local varZ = RRand(sFluidZ,(sFluidZ+fRadius),1); 
#end
#if(sFluidX != 0 & ceil(SRand(1)) = 0) 
#local varX = RRand(sFluidX,(-sFluidX+fRadius),1);
#end
#if(sFluidX != 0 & ceil(SRand(1)) = 1)
#local varX = RRand(sFluidX,(sFluidX+fRadius),1); 
#end
#if(sFluidZ != 0 & ceil(SRand(1)) = 0) 
#local varZ = RRand(sFluidZ,(-sFluidZ+fRadius),1);
#end
#if(sFluidZ != 0 & ceil(SRand(1)) = 1)
#local varZ = RRand(sFluidZ,(sFluidZ+fRadius),1); 
#end

#if((varX+varInitBubbleHeight)>varFluidX)
#local varXAdj = (varX+varInitBubbleHeight)-varFluidX;
#local varX = varX-(varXAdj*2);  
#end 
#if((varZ+varInitBubbleHeight)>varFluidZ)
#local varZAdj = (varZ+varInitBubbleHeight)-varFluidZ;
#local varZ = varZ-(varZAdj*2);  
#end

#local varInitHeight = RRand(varInitHeightRangeStart,varInitHeightRangeEnd,1); 
#local varInitBubbleRange = RRand(varInitBubbleHeightRangeStart,varInitBubbleHeightRangeEnd,1); 
#local varInitBubbleHeight = varInitBubbleRange;
#local varCollumnCount = varCollumnCount+1;
#local varCounter = 1; 
#end
 
} 
                                                                        
#end 
