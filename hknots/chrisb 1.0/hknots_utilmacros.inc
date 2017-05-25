//
// hknots_utilmacros.inc
// ---------------------
// Created by David Sharp 
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett.
//
// This include file contains a small number of utility macros to support the HKnots macros.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// See hknots.html for more details.
//


// Test whether HKnots_vvv=<0,0,0> ?
#macro HKnots_vzero_p(HKnots_vvv)
	(HKnots_vvv.x=0 & HKnots_vvv.y=0 & HKnots_vvv.z=0)
#end


// Return a string representation of vector HKnots_vvv
#macro HKnots_vstring(HKnots_vvv)
	concat("<",str(HKnots_vvv.x,5,5),", ",str(HKnots_vvv.y,5,5),", ",str(HKnots_vvv.z,5,5),">") 
#end


// Check for degenerate triangle
#macro HKnots_degenerate_triangle_p(HKnots_v1,HKnots_v2,HKnots_v3)
	HKnots_vzero_p( vcross(HKnots_v1-HKnots_v2,HKnots_v2-HKnots_v3))
#end


// A check for 'degenerate' normals
#macro HKnots_degenerate_norms_p(HKnots_v1,HKnots_v2,HKnots_v3,HKnots_n1,HKnots_n2,HKnots_n3)
        #local HKnots_tnorm=vcross(HKnots_v1-HKnots_v2,HKnots_v1-HKnots_v3);
        #if(HKnots_vzero_p(HKnots_tnorm))
           #local HKnots_ret=0;
        #else
           #local HKnots_n1t=vdot(HKnots_n1,HKnots_tnorm);
           #local HKnots_n2t=vdot(HKnots_n2,HKnots_tnorm);
           #local HKnots_n3t=vdot(HKnots_n3,HKnots_tnorm);
           #if( HKnots_n1t=0 | HKnots_n2t=0 | HKnots_n3t=0 )
		#local HKnots_ret=0;
           #else
          	#local HKnots_n1s=HKnots_n1t/abs(HKnots_n1t);
               	#local HKnots_n2s=HKnots_n2t/abs(HKnots_n2t);
                #local HKnots_n3s=HKnots_n3t/abs(HKnots_n3t);
               	#local HKnots_ret=(abs(HKnots_n1s+HKnots_n2s+HKnots_n3s)<2.5);
           #end
        #end
        HKnots_ret
#end


// Return vector normal to the triangle v1,v2,v3
#macro HKnots_tnormal(HKnots_v1,HKnots_v2,HKnots_v3)
        vnormalize(vcross(HKnots_v2-HKnots_v1,HKnots_v3-HKnots_v1))
#end


#ifndef(HKnots_RedFreq)    #declare HKnots_RedFreq=1;       #end
#ifndef(HKnots_RedPhase)   #declare HKnots_RedPhase=0;      #end
#ifndef(HKnots_MinRed)     #declare HKnots_MinRed=.4;       #end
#ifndef(HKnots_MaxRed)     #declare HKnots_MaxRed=1.0;      #end

#ifndef(HKnots_GreenFreq)  #declare HKnots_GreenFreq=1;     #end
#ifndef(HKnots_GreenPhase) #declare HKnots_GreenPhase=pi/2; #end
#ifndef(HKnots_MinGreen)   #declare HKnots_MinGreen=.4;     #end
#ifndef(HKnots_MaxGreen)   #declare HKnots_MaxGreen=1.0;    #end

#ifndef(HKnots_BlueFreq)   #declare HKnots_BlueFreq=1;      #end
#ifndef(HKnots_BluePhase)  #declare HKnots_BluePhase=pi;    #end
#ifndef(HKnots_MinBlue)    #declare HKnots_MinBlue=.4;      #end
#ifndef(HKnots_MaxBlue)    #declare HKnots_MaxBlue=1.0;     #end


#macro HKnots_hcolor(HKnots_beta)
  #local HKnots_MidRed=(HKnots_MaxRed-HKnots_MinRed)/2;
  #local HKnots_MidGreen=(HKnots_MaxGreen-HKnots_MinGreen)/2;
  #local HKnots_MidBlue=(HKnots_MaxBlue-HKnots_MinBlue)/2;
  color
   < 
    HKnots_MidRed*cos(HKnots_RedFreq*HKnots_beta+HKnots_RedPhase)+HKnots_MidRed+HKnots_MinRed,
    HKnots_MidGreen*cos(HKnots_GreenFreq*HKnots_beta+HKnots_GreenPhase)+HKnots_MidGreen+HKnots_MinGreen,
    HKnots_MidBlue*cos(HKnots_BlueFreq*HKnots_beta+HKnots_BluePhase)+HKnots_MidBlue+HKnots_MinBlue
   > 
#end


#macro HKnots_hfloat(HKnots_beta,HKnots_MinP,HKnots_MaxP,HKnots_PFreq,HKnots_PPhase)
  #local HKnots_MidP=(HKnots_MaxP-HKnots_MinP)/2;
  HKnots_MidP*cos(HKnots_PFreq*HKnots_beta+HKnots_PPhase)+HKnots_MidP+HKnots_MinP
#end

