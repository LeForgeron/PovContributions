//
// hknots.inc
// ----------
// Created by David Sharp based upon Aaron K. Trautwein's concepts for the Fourier 
// "harmonic" parameterizations of knots. Adapted to go into the POV-Ray Object 
// Collection Oct 2009 by Chris Bartlett.
//
// This include file contains the HKnots macros.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The default settings generate an object about 200 POV-Ray units high and about 400 wide, 
// centred at the origin.
//
// Adding this model to your scene is likely to add a couple of seconds to the render time.
//
// See hknots.html for more details.
//

// Comments, suggestions, complaints, etc to dsharp@interport.net 
// http://www.interport.net/~dsharp


// A few utility macros are used to simplify the code 
#include "hknots_utilmacros.inc"
// The file 'hknots_arrays.inc' contains arrays representing Aaron K. Trautwein's 
// 'Harmonic' knots series.
#include "hknots_arrays.inc"



/*---- Random coefficients  ----------------------*/
//  This constructs a random array of coefficients.
//  Probably not very useful, but often interesting
#macro HKnots_randomcoefficients(HKnots_maxorder,HKnots_myseed)
  #declare HKnots_randarray=array[3][15][2]
  #local HKnots_S1 = seed(HKnots_myseed);
  #local HKnots_i=0;
  #local HKnots_j=0;
  #local HKnots_k=0;
  #while(HKnots_i<3)
    #while(HKnots_j<15)
      #while(HKnots_k<2)
        #if(HKnots_j<HKnots_maxorder)// put a limit on the order of our series
          #declare HKnots_randarray[HKnots_i][HKnots_j][HKnots_k]=50-int(100*rand(HKnots_S1));
        #else
          #declare HKnots_randarray[HKnots_i][HKnots_j][HKnots_k]=0;
        #end
	#declare HKnots_k=HKnots_k+1;
      #end
      #declare HKnots_k=0;
      #declare HKnots_j=HKnots_j+1;
    #end
    #declare HKnots_j=0;
    #declare HKnots_i=HKnots_i+1;
  #end
  HKnots_randarray 
#end
/*----------------------------------*/

  
// the macro which returns coordinates of points
// on the knot's curve. 0 < HKnots_m < 2*pi 
#macro knot(HKnots_m)
  #local HKnots_i=0;
  #local HKnots_xx=0; 
  #while (HKnots_i<15)
    #local HKnots_xx=HKnots_xx+HKnots_H_Array[0][HKnots_i][0]*cos((HKnots_i+1)*HKnots_m)+HKnots_H_Array[0][HKnots_i][1]*sin((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1; 
  #end
  #local HKnots_i=0;
  #local HKnots_yy=0; 
  #while (HKnots_i<15)
    #local HKnots_yy=HKnots_yy+HKnots_H_Array[1][HKnots_i][0]*cos((HKnots_i+1)*HKnots_m)+HKnots_H_Array[1][HKnots_i][1]*sin((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1;
  #end
  #local HKnots_i=0;
  #local HKnots_zz=0; 
  #while (HKnots_i<15)
    #local HKnots_zz=HKnots_zz+HKnots_H_Array[2][HKnots_i][0]*cos((HKnots_i+1)*HKnots_m)+HKnots_H_Array[2][HKnots_i][1]*sin((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1;
  #end
  <HKnots_xx,HKnots_yy,HKnots_zz>
#end

// there are many uses for the curve's tangent vector
// 
#macro HKnots_d1knot(HKnots_m) 
  #local HKnots_i=0;
  #local HKnots_xx=0; 
  #while (HKnots_i<15)
    #local HKnots_xx=HKnots_xx-HKnots_H_Array[0][HKnots_i][0]*(HKnots_i+1)*sin((HKnots_i+1)*HKnots_m)+HKnots_H_Array[0][HKnots_i][1]*(HKnots_i+1)*cos((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1; 
  #end
  #local HKnots_i=0;
  #local HKnots_yy=0; 
  #while (HKnots_i<15)
    #local HKnots_yy=HKnots_yy-HKnots_H_Array[1][HKnots_i][0]*(HKnots_i+1)*sin((HKnots_i+1)*HKnots_m)+HKnots_H_Array[1][HKnots_i][1]*(HKnots_i+1)*cos((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1;
  #end
  #local HKnots_i=0;
  #local HKnots_zz=0; 
  #while (HKnots_i<15)
    #local HKnots_zz=HKnots_zz-HKnots_H_Array[2][HKnots_i][0]*(HKnots_i+1)*sin((HKnots_i+1)*HKnots_m)+HKnots_H_Array[2][HKnots_i][1]*(HKnots_i+1)*cos((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1;
  #end
  <HKnots_xx,HKnots_yy,HKnots_zz>
#end 
 
// the curve's 2nd derivative (acceleration)
// for determining how the curve is curving
//
#macro HKnots_d2knot(HKnots_m) 
  #local HKnots_i=0;
  #local HKnots_xx=0; 
  #while (HKnots_i<15)
    #local HKnots_xx=HKnots_xx-HKnots_H_Array[0][HKnots_i][0]*(HKnots_i+1)*(HKnots_i+1)*cos((HKnots_i+1)*HKnots_m)-HKnots_H_Array[0][HKnots_i][1]*(HKnots_i+1)*(HKnots_i+1)*sin((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1; 
  #end
  #local HKnots_i=0;
  #local HKnots_yy=0; 
  #while (HKnots_i<15)
    #local HKnots_yy=HKnots_yy-HKnots_H_Array[1][HKnots_i][0]*(HKnots_i+1)*(HKnots_i+1)*cos((HKnots_i+1)*HKnots_m)-HKnots_H_Array[1][HKnots_i][1]*(HKnots_i+1)*(HKnots_i+1)*sin((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1;
  #end
  #local HKnots_i=0;
  #local HKnots_zz=0; 
  #while (HKnots_i<15)
    #local HKnots_zz=HKnots_zz-HKnots_H_Array[2][HKnots_i][0]*(HKnots_i+1)*(HKnots_i+1)*cos((HKnots_i+1)*HKnots_m)-HKnots_H_Array[2][HKnots_i][1]*(HKnots_i+1)*(HKnots_i+1)*sin((HKnots_i+1)*HKnots_m);
    #local HKnots_i=HKnots_i+1;
  #end
  <HKnots_xx,HKnots_yy,HKnots_zz>
#end 

/*-------------------------------*/
/*-------------------------------*/


#macro HKnots_mytexture(HKnots_beta)
   texture{pigment{HKnots_hcolor(HKnots_beta)} finish{reflection .2}}
#end

/* 
  HKnots_theradius(HKnots_beta) gives a smoothly varying radius or
   width for spheres, tubes, ribbons, etc
   keep HKnots_RadiusFreq an integer so that the radius 
   varies smoothly at HKnots_beta=0->2pi 
*/
#declare HKnots_minRadius =10;
#declare HKnots_maxRadius =20;
#declare HKnots_RadiusPhase=pi/2;
#declare HKnots_RadiusFreq=5;
#declare HKnots_midRadius=(HKnots_maxRadius-HKnots_minRadius)/2;
#macro HKnots_theradius(HKnots_beta)   
    HKnots_midRadius*cos(HKnots_RadiusFreq*HKnots_beta+HKnots_RadiusPhase)+HKnots_midRadius+HKnots_minRadius
#end

/*-----------------------------------------------*/
/* various objects to build the HKnots_knot out of. */
/* 
   mostly these macros take vectors HKnots_v1 and v2
   as calling parameters.
   HKnots_v1 and v2 generally refer to consecutive
   points on the HKnots_knot curve. HKnots_v1u, and v2u are
   (normalized) directions perpendicular to the knot
   tangent and its curvature 'radius' at HKnots_v1 and v2.
   HKnots_uLen is the 'width' of the curve (for tubes, ribbons, etc)
*/
// just a sphere at HKnots_v1
#macro HKnots_sph_object(HKnots_v1, HKnots_R)
// eg:  HKnots_sph_object(knot(HKnots_beta),sphereRadius))
  sphere{<0,0,0>,HKnots_R
    translate HKnots_v1
  }
#end

// a sphere at HKnots_v1, and a cylinder from HKnots_v1 to v2
#macro HKnots_cyl_sph_object(HKnots_v1, HKnots_v2, HKnots_R)
// eg: HKnots_cyl_sph_object(knot(HKnots_beta1),knot(HKnots_beta2), tubeRadius)
  union{
    sphere{HKnots_v1, HKnots_R}
    #if( (HKnots_v1.x != HKnots_v2.x) | (HKnots_v1.y != HKnots_v2.y) | (HKnots_v1.z != HKnots_v2.z))
      cylinder{HKnots_v1, HKnots_v2, HKnots_R}
    #else
      sphere{HKnots_v1, HKnots_R/2} //suppress csg warning
    #end
	
  }
#end

// a sphere at HKnots_v1 and a cone from HKnots_v1 to v2
#macro HKnots_cone_HKnots_sph_object(HKnots_v1,HKnots_R1, HKnots_v2,HKnots_R2)
  union{
    sphere{HKnots_v1, HKnots_R1}
    #if( (HKnots_v1.x != HKnots_v2.x) | (HKnots_v1.y != HKnots_v2.y) | (HKnots_v1.z != HKnots_v2.z))
      cone{HKnots_v1,HKnots_R1, HKnots_v2,HKnots_R2}
    #else
      sphere{HKnots_v1,HKnots_R1/2} //suppress 'single object' csg warning
    #end
	
  }
#end
#macro merge_HKnots_cone_HKnots_sph_object(HKnots_v1,HKnots_R1, HKnots_v2,HKnots_R2)
  merge{
    sphere{HKnots_v1, HKnots_R1}
    #if( (HKnots_v1.x != HKnots_v2.x) | (HKnots_v1.y != HKnots_v2.y) | (HKnots_v1.z != HKnots_v2.z))
      cone{HKnots_v1,HKnots_R1, HKnots_v2,HKnots_R2}
    #else
      sphere{HKnots_v1,HKnots_R1/2} //suppress 'single object' csg warning
    #end
	
  }
#end

// a pair of HKnots_tracks
#macro HKnots_cylribs(HKnots_v1, HKnots_v1u, HKnots_v2, HKnots_v2u,HKnots_uLen, HKnots_R)
  #if(!HKnots_vzero_p((HKnots_v1-HKnots_v1u)-(HKnots_v2-HKnots_v2u)))
    cylinder{HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_v2-HKnots_uLen * HKnots_v2u, HKnots_R}
    cylinder{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_v2+HKnots_uLen * HKnots_v2u, HKnots_R}      
  #end
  #if(!HKnots_vzero_p(HKnots_v1-HKnots_v2))
     //cylinder{HKnots_v1, HKnots_v2, HKnots_R}
  #end
#end

// these are four 'pigment, finish' pairs for the "array of cylinders"
#macro HKnots_T1(HKnots_m,HKnots_P)
  pigment{HKnots_hcolor(HKnots_m) } finish{reflection .2}
#end
#macro HKnots_T2(HKnots_m,HKnots_P)
  pigment{HKnots_hcolor(2*HKnots_m) } finish{reflection .2}
#end
#macro HKnots_T3(HKnots_m,HKnots_P)
  pigment{HKnots_hcolor(HKnots_m+pi)} finish{reflection .2}
#end
#macro HKnots_T4(HKnots_m,HKnots_P)
  pigment{HKnots_hcolor((2*HKnots_m+pi)) } finish{reflection .2}
#end

#macro HKnots_cylarray(HKnots_v1, HKnots_v1u, HKnots_v2, HKnots_v2u,HKnots_uLen,HKnots_R,HKnots_m)
  #if(!HKnots_vzero_p((HKnots_v1-HKnots_v1u)-(HKnots_v2-HKnots_v2u)))
//    union{
     sphere{HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_R texture{HKnots_T1(HKnots_m,0)}}      
     cylinder{HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_v2-HKnots_uLen * HKnots_v2u, HKnots_R texture{HKnots_T1(HKnots_m,0)}}
     sphere{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_R texture{HKnots_T2(HKnots_m,0)}}
     cylinder{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_v2+HKnots_uLen * HKnots_v2u, HKnots_R texture{HKnots_T2(HKnots_m,0)}}

     #local HKnots_v1Left=vnormalize(vcross(HKnots_v2-HKnots_v1, HKnots_v1u));
     #local HKnots_v2Left=vnormalize(vcross(HKnots_v2-HKnots_v1, HKnots_v2u));
     sphere{HKnots_v1-HKnots_uLen*HKnots_v1Left, HKnots_R texture{HKnots_T3(HKnots_m,0)}}
     cylinder{HKnots_v1-HKnots_uLen*HKnots_v1Left, HKnots_v2-HKnots_uLen*HKnots_v2Left, HKnots_R texture{HKnots_T3(HKnots_m,0)}}
     sphere{HKnots_v1+HKnots_uLen*HKnots_v1Left, HKnots_R texture{HKnots_T4(HKnots_m,0)}}
     cylinder{HKnots_v1+HKnots_uLen*HKnots_v1Left, HKnots_v2+HKnots_uLen*HKnots_v2Left, HKnots_R texture{HKnots_T4(HKnots_m,0)}}
//    }
  #end
#end

#macro HKnots_ktriangles(HKnots_v1, HKnots_v1u, HKnots_v2, HKnots_v2u,HKnots_uLen,HKnots_m)
  #local HKnots_tv1= HKnots_v1-HKnots_uLen * HKnots_v1u;
  #local HKnots_tv2= HKnots_v2-HKnots_uLen * HKnots_v2u;
  #local HKnots_tv3= HKnots_v1+HKnots_uLen * HKnots_v1u;
  #local HKnots_tv4= HKnots_v2+HKnots_uLen * HKnots_v2u;
  triangle{HKnots_tv1,HKnots_tv2,HKnots_tv3}
  triangle{HKnots_tv3,HKnots_tv2,HKnots_tv4}     
#end

#macro HKnots_striangles(HKnots_v1, HKnots_v1u, HKnots_v1l, HKnots_v2, HKnots_v2u, HKnots_v2l,HKnots_uLen,HKnots_m)
  #local HKnots_tempv1l= HKnots_v1l;
  #local HKnots_tempv2l= HKnots_v2l;
  #local HKnots_tv1= HKnots_v1-HKnots_uLen * HKnots_v1u;
  #local HKnots_tv2= HKnots_v2-HKnots_uLen * HKnots_v2u;
  #local HKnots_tv3= HKnots_v1+HKnots_uLen * HKnots_v1u;
  #local HKnots_tv4= HKnots_v2+HKnots_uLen * HKnots_v2u;
  #if(HKnots_degenerate_norms_p(HKnots_tv1,HKnots_tv2,HKnots_tv3, HKnots_v1l, HKnots_v2l, HKnots_v1l))
    #debug "'degenerate' normals\n"
    #declare HKnots_tempv2l= HKnots_v1l;
  #end
  smooth_triangle{
    HKnots_tv1, HKnots_v1l,
    HKnots_tv2,HKnots_tempv2l,
    HKnots_tv3, HKnots_v1l
  }
  #if(HKnots_degenerate_norms_p(HKnots_tv3,HKnots_tv2,HKnots_tv4, HKnots_v1l, HKnots_v2l, HKnots_v2l))
    #debug "degenerate normals\n"
    #declare HKnots_tempv1l= HKnots_v2l; 
  #end
  smooth_triangle{
    HKnots_tv3,HKnots_tempv1l,
    HKnots_tv2, HKnots_v2l,
    HKnots_tv4, HKnots_v2l
  }

#end
#macro HKnots_striangles2(HKnots_v1, HKnots_v1u, HKnots_v1l, HKnots_v2, HKnots_v2u, HKnots_v2l,HKnots_uLen,HKnots_m)
  #local HKnots_tempv1l= HKnots_v1l;
  #local HKnots_tempv2l= HKnots_v2l;
  #local HKnots_tv1= HKnots_v1-HKnots_uLen * HKnots_v1u;
  #local HKnots_tv2= HKnots_v2-HKnots_uLen * HKnots_v2u;
  #local HKnots_tv3= HKnots_v1+HKnots_uLen * HKnots_v1u;
  #local HKnots_tv4= HKnots_v2+HKnots_uLen * HKnots_v2u;
  #if(HKnots_degenerate_norms_p(HKnots_tv1,HKnots_tv2,HKnots_tv3, HKnots_v1l, HKnots_v2l, HKnots_v1l))
     #debug "'degenerate' normals\n"
     triangle{HKnots_tv1,HKnots_tv2,HKnots_tv3}
  #else
    smooth_triangle{
       HKnots_tv1, HKnots_v1l,
       HKnots_tv2,HKnots_tempv2l,
       HKnots_tv3, HKnots_v1l
    }
  #end
  #if(HKnots_degenerate_norms_p(HKnots_tv3,HKnots_tv2,HKnots_tv4, HKnots_v1l, HKnots_v2l, HKnots_v2l))
    #debug "'degenerate' normals\n"
    triangle{HKnots_tv3,HKnots_tv2,HKnots_tv4}
  #else
    smooth_triangle{
       HKnots_tv3,HKnots_tempv1l,
       HKnots_tv2, HKnots_v2l,
       HKnots_tv4, HKnots_v2l
    }
  #end
#end

#macro HKnots_triangleribs(HKnots_v1, HKnots_v1u, HKnots_v1l, HKnots_v2, HKnots_v2u, HKnots_v2l,HKnots_uLen,HKnots_m,HKnots_tradius) 
  sphere{HKnots_v1+HKnots_uLen * HKnots_v1u,HKnots_tradius}
  sphere{HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_tradius}
  sphere{HKnots_v2-HKnots_uLen * HKnots_v2u, HKnots_tradius}
  sphere{HKnots_v2+HKnots_uLen * HKnots_v2u, HKnots_tradius}
  cylinder{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_tradius}
  cylinder{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_v2-HKnots_uLen * HKnots_v2u, HKnots_tradius}  
  cylinder{HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_v2-HKnots_uLen * HKnots_v2u, HKnots_tradius}
  cylinder{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_v2+HKnots_uLen * HKnots_v2u, HKnots_tradius}     
#end

#include "metals.inc"
// primitive 'roller coaster' HKnots_tracks
#macro HKnots_tracks(HKnots_v1, HKnots_v1u, HKnots_v1l, HKnots_v2, HKnots_v2u, HKnots_v2l,HKnots_uLen,HKnots_m,HKnots_tradius) 
  sphere{HKnots_v1+HKnots_uLen * HKnots_v1u,HKnots_tradius} 
  sphere{HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_tradius}
  // 'tie'
  cylinder{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_tradius/2
    texture{DMFWood6 scale 10}
  }
  // 'rails'
  union{
    cylinder{HKnots_v1-HKnots_uLen * HKnots_v1u, HKnots_v2-HKnots_uLen * HKnots_v2u, HKnots_tradius}
    cylinder{HKnots_v1+HKnots_uLen * HKnots_v1u, HKnots_v2+HKnots_uLen * HKnots_v2u, HKnots_tradius} 
    //texture{pigment{Silver} finish{reflection .2}}
    texture {Silver1}
  }    
#end
/*---------------------------------------------------*/


// use HKnots_R0 as the size of the tube, ribbon, whatever
#declare HKnots_R0=15; 

// HKnots_Total_Segs is the 'resolution' of the parameterization
#declare HKnots_Total_Segs= 200;



#macro HKnots(HKnots_Type)
  #declare HKnots_Twists=0;
  #declare HKnots_betaphase=0;
  #declare HKnots_dbeta=2*pi/HKnots_Total_Segs;
  union{
    // start the HKnots_knot at HKnots_betaphase (normally 0)
    #declare HKnots_lastV=knot(HKnots_betaphase);          
    #declare HKnots_lastR=HKnots_theradius(HKnots_betaphase);
    #declare HKnots_Seg_Count=1;
    
    #while( HKnots_Seg_Count<=HKnots_Total_Segs+1)
      #declare HKnots_beta = HKnots_Seg_Count*2*pi/HKnots_Total_Segs+HKnots_betaphase;
      #declare HKnots_thisV=knot(HKnots_beta); 
      #declare HKnots_thisLeft=vnormalize(HKnots_d2knot(HKnots_beta));
  	  
      // extra twist:
      #if(HKnots_Twists)
        #declare HKnots_thisLeft=vaxis_rotate(HKnots_thisLeft,HKnots_thisV-HKnots_lastV,180/pi*(HKnots_Twists*HKnots_beta));
      #end 
  
      // define 'up' (relative to the path):
      #declare HKnots_thisUp=vnormalize(vcross( vnormalize(HKnots_d1knot(HKnots_beta)),HKnots_thisLeft));
      
      #declare HKnots_thisR=HKnots_theradius(HKnots_beta); 
      
      #if (HKnots_Seg_Count>1)			
      
        #declare HKnots_T=texture{pigment {HKnots_hcolor(HKnots_beta)} finish { phong 1 phong_size 200 reflection .15 }}
        //#declare HKnots_T=texture{pigment {HKnots_hcolor(HKnots_beta) transmit .8} finish { phong 1 phong_size 200 reflection .15 }} 
        union{ 
          #switch (0)
            #case (strcmp(strlwr(HKnots_Type),"ktriangles"))
              HKnots_ktriangles(HKnots_thisV,HKnots_thisUp,HKnots_lastV,HKnots_lastUp,HKnots_R0,HKnots_beta)
            #break
            #case (strcmp(strlwr(HKnots_Type),"cylribs"))
              HKnots_cylribs(HKnots_thisV,HKnots_thisUp,HKnots_lastV,HKnots_lastUp,HKnots_R0/2,HKnots_R0/8)
            #break
            #case (strcmp(strlwr(HKnots_Type),"cylarray"))
              HKnots_cylarray(HKnots_thisV,HKnots_thisUp,HKnots_lastV,HKnots_lastUp,HKnots_R0/2,HKnots_R0/4,HKnots_beta)
            #break
            #case (strcmp(strlwr(HKnots_Type),"striangles"))
              HKnots_striangles(HKnots_lastV,HKnots_lastUp,HKnots_lastLeft,HKnots_thisV,HKnots_thisUp,HKnots_thisLeft,HKnots_R0,HKnots_beta)
            #break
            #case (strcmp(strlwr(HKnots_Type),"tracks"))
              HKnots_tracks(HKnots_lastV,HKnots_lastUp,HKnots_lastLeft,HKnots_thisV,HKnots_thisUp,HKnots_thisLeft,HKnots_R0/2,HKnots_beta,3)
            #break
            #case (strcmp(strlwr(HKnots_Type),"striangles2"))
              HKnots_striangles2(HKnots_lastV,HKnots_lastUp,HKnots_lastLeft,HKnots_thisV,HKnots_thisUp,HKnots_thisLeft,HKnots_R0,HKnots_beta)			  
            #break
            #case (strcmp(strlwr(HKnots_Type),"triangleribs"))
              HKnots_triangleribs(HKnots_lastV,HKnots_lastUp,HKnots_lastLeft,HKnots_thisV,HKnots_thisUp,HKnots_thisLeft,HKnots_R0,HKnots_beta,3)
            #break
            #else
              HKnots_tracks(HKnots_lastV,HKnots_lastUp,HKnots_lastLeft,HKnots_thisV,HKnots_thisUp,HKnots_thisLeft,HKnots_R0/2,HKnots_beta,3)
  	  #end	   
  	  texture {HKnots_T}
        }
      #end      
                       
      #declare HKnots_lastV=HKnots_thisV;
      #declare HKnots_lastR=HKnots_thisR; 
      #declare HKnots_lastUp= HKnots_thisUp;
      #declare HKnots_lastLeft=HKnots_thisLeft; 
     
      #declare HKnots_Seg_Count=HKnots_Seg_Count+1;
    #end // end of the HKnots_Seg_Count while loop
  }// end of union
#end