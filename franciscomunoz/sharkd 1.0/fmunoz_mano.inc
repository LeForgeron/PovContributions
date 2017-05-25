// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_Mano.inc
// Desc: A simple "hand" include file
// Date: 27/08/1997
// Last: 09/07/2008
// Auth: Francisco Munoz (fmunoz@hotmail.com), tweaked and prepared by Michael Horvath
// Version: Alpha 0.3


// Wrist texture
#ifndef (FMunoz_Texture1)	#declare FMunoz_FMunoz_Texture1 = texture {pigment {color rgb <.75,.75,.75>}}	#end

// Hand texture
#ifndef (FMunoz_Texture2)	#declare FMunoz_FMunoz_Texture2 = texture {pigment {color rgb <.75,.75,.75>}}	#end

// Nail texture
#ifndef (FMunoz_Texture3)	#declare FMunoz_FMunoz_Texture3 = texture {pigment {color rgb <.75,.75,.75>}}	#end


// ----------------------------------------

#ifndef (FMunoz_poswrist)	#declare FMunoz_poswrist = <0,0,0>;	#end
#ifndef (FMunoz_girTh)		#declare FMunoz_girTh = 45;		#end
#ifndef (FMunoz_girFA)		#declare FMunoz_girFA = 5;		#end
#ifndef (FMunoz_girFB)		#declare FMunoz_girFB = 85;		#end
#ifndef (FMunoz_girFC)		#declare FMunoz_girFC = 85;		#end
#ifndef (FMunoz_girFD)		#declare FMunoz_girFD = 5;		#end
#ifndef (FMunoz_lenghthand)	#declare FMunoz_lenghthand = 10;	#end
#ifndef (FMunoz_longTh)		#declare FMunoz_longTh = FMunoz_lenghthand * 0.6;		#end
#ifndef (FMunoz_longFA)		#declare FMunoz_longFA = FMunoz_lenghthand * 0.95;		#end
#ifndef (FMunoz_longFB)		#declare FMunoz_longFB = FMunoz_lenghthand * 1.0;		#end
#ifndef (FMunoz_longFC)		#declare FMunoz_longFC = FMunoz_lenghthand * 0.9;		#end
#ifndef (FMunoz_longFD)		#declare FMunoz_longFD = FMunoz_lenghthand * 0.8;		#end


// ----------------------------------------

#declare FMunoz_girTh1 = <FMunoz_girTh/2,-FMunoz_girTh/2,-30>;
#declare FMunoz_posTh1 = vrotate(<0,FMunoz_longTh*.5,0>,FMunoz_girTh1);
#declare FMunoz_girTh2 = <FMunoz_girTh/2,0,0> + FMunoz_girTh1;
#declare FMunoz_posTh2 = vrotate(<0,FMunoz_longTh*.25,0>,FMunoz_girTh2) + FMunoz_posTh1;
#declare FMunoz_posTh3 = vrotate(<0,FMunoz_longTh*.25,0>,<FMunoz_girTh,-FMunoz_girTh/2,0>+FMunoz_girTh2) + FMunoz_posTh2;

#declare FMunoz_posFA1 = vrotate(<0,FMunoz_longFA*.5,0>,<0,0,-15>);
#declare FMunoz_posFA2 = vrotate(<0,FMunoz_longFA*.17,0>,<FMunoz_girFA,0,-10>) + FMunoz_posFA1;
#declare FMunoz_posFA3 = vrotate(<0,FMunoz_longFA*.17,0>,<FMunoz_girFA*2,0,-10>) + FMunoz_posFA2;
#declare FMunoz_posFA4 = vrotate(<0,FMunoz_longFA*.16,0>,<FMunoz_girFA*3,0,-10>) + FMunoz_posFA3;
#declare FMunoz_posFB1 = vrotate(<0,FMunoz_longFB*.5,0>,0);
#declare FMunoz_posFB2 = vrotate(<0,FMunoz_longFB*.17,0>,<FMunoz_girFB,0,0>) + FMunoz_posFB1;
#declare FMunoz_posFB3 = vrotate(<0,FMunoz_longFB*.17,0>,<FMunoz_girFB*2,0,0>) + FMunoz_posFB2;
#declare FMunoz_posFB4 = vrotate(<0,FMunoz_longFB*.16,0>,<FMunoz_girFB*3,0,0>) + FMunoz_posFB3;
#declare FMunoz_posFC1 = vrotate(<0,FMunoz_longFC*.5,0>,<0,0,15>);
#declare FMunoz_posFC2 = vrotate(<0,FMunoz_longFC*.17,0>,<FMunoz_girFC,0,10>) + FMunoz_posFC1;
#declare FMunoz_posFC3 = vrotate(<0,FMunoz_longFC*.17,0>,<FMunoz_girFC*2,0,10>) + FMunoz_posFC2;
#declare FMunoz_posFC4 = vrotate(<0,FMunoz_longFC*.16,0>,<FMunoz_girFC*3,0,10>) + FMunoz_posFC3;
#declare FMunoz_posFD1 = vrotate(<0,FMunoz_longFD*.5,0>,<0,0,30>);
#declare FMunoz_posFD2 = vrotate(<0,FMunoz_longFD*.17,0>,<FMunoz_girFD,0,20>) + FMunoz_posFD1;
#declare FMunoz_posFD3 = vrotate(<0,FMunoz_longFD*.17,0>,<FMunoz_girFD*2,0,20>) + FMunoz_posFD2;
#declare FMunoz_posFD4 = vrotate(<0,FMunoz_longFD*.16,0>,<FMunoz_girFD*3,0,20>) + FMunoz_posFD3;


// ----------------------------------------

#ifndef (FMunoz_knucleclass)	#declare FMunoz_knucleclass = 1;	#end
#switch (FMunoz_knucleclass)
	#case (0)
		#ifndef (FMunoz_knucle)
			#warning "Beware!! knucke must be defined to use knucleclass=0 \n"
		#end
	#break
	#case (1)  // Normal knucle
		#declare FMunoz_knuckle = object{sphere {0,FMunoz_lenghthand/20} texture {FMunoz_Texture2}}
	#break
	#case (2) // Big knucle
		#declare FMunoz_knuckle = sphere {0,FMunoz_lenghthand/15 texture {FMunoz_Texture2}}
	#break
	#case (3) // Spiked knucle
		#declare FMunoz_knuckle = union
		{
			sphere {0,FMunoz_lenghthand/20 texture {FMunoz_Texture2}}
			cone {0,FMunoz_lenghthand/20,<0,0,-FMunoz_lenghthand/10>,0 texture {FMunoz_Texture3}}
		}
	#break
#end

#ifndef (FMunoz_nailclass) #declare FMunoz_nailclass=1 #end
#switch (FMunoz_nailclass)
	#case (0)
		#ifndef (FMunoz_nail)
			#warning "Beware!! nail must be defined to use nailclass=0 \n"
		#end
	#break
	#case (1)  // No nail
		#declare FMunoz_nail = object{sphere {0,FMunoz_lenghthand/22} texture {FMunoz_Texture2}}
	#break
	#case (2) // No nail, Big
		#declare FMunoz_nail = sphere {0,FMunoz_lenghthand/18 texture {FMunoz_Texture2}}
	#break
	#case (3) // claw
		#declare FMunoz_nail = union
		{
			sphere {0,FMunoz_lenghthand/22 texture {FMunoz_Texture2}}
			intersection
			{
				cylinder {0,<0,FMunoz_lenghthand/5,0>,FMunoz_lenghthand/22}
				cone {<0,0,-FMunoz_lenghthand/22>,FMunoz_lenghthand/22,<0,FMunoz_lenghthand/5,-FMunoz_lenghthand/22>,0}
				texture {FMunoz_Texture3}
			}
		}
	#break
#end


// ----------------------------------------

#ifndef (FMunoz_Numberf) #declare FMunoz_Numberf=4 #end

#declare FMunoz_hand = union
{
	sphere {FMunoz_posTh1,FMunoz_lenghthand/20}
	sphere {FMunoz_posTh2,FMunoz_lenghthand/20}
	object {FMunoz_nail rotate <FMunoz_girTh,-FMunoz_girTh/2,0>+FMunoz_girTh2 translate FMunoz_posTh3}
	cylinder {FMunoz_posTh1,FMunoz_posTh2,FMunoz_lenghthand/20}
	cone {FMunoz_posTh2,FMunoz_lenghthand/20,FMunoz_posTh3,FMunoz_lenghthand/22}
	object {FMunoz_knuckle translate FMunoz_posFA1}
	sphere {FMunoz_posFA2,FMunoz_lenghthand/20}
	sphere {FMunoz_posFA3,FMunoz_lenghthand/20}
	object {FMunoz_nail rotate <FMunoz_girFA*3,0,-10> translate FMunoz_posFA4}
	cylinder {FMunoz_posFA1,FMunoz_posFA2,FMunoz_lenghthand/20}
	cylinder {FMunoz_posFA2,FMunoz_posFA3,FMunoz_lenghthand/20}
	cone {FMunoz_posFA3,FMunoz_lenghthand/20,FMunoz_posFA4,FMunoz_lenghthand/22}
	#if (FMunoz_Numberf > 1)
		object {FMunoz_knuckle translate FMunoz_posFB1}
		sphere {FMunoz_posFB2,FMunoz_lenghthand/20}
		sphere {FMunoz_posFB3,FMunoz_lenghthand/20}
		object {FMunoz_nail rotate <FMunoz_girFB*3,0,0> translate FMunoz_posFB4}
		cylinder {FMunoz_posFB1,FMunoz_posFB2,FMunoz_lenghthand/20}
		cylinder {FMunoz_posFB2,FMunoz_posFB3,FMunoz_lenghthand/20}
		cone {FMunoz_posFB3,FMunoz_lenghthand/20,FMunoz_posFB4,FMunoz_lenghthand/22}
	#end
	#if (FMunoz_Numberf > 2)
		object {FMunoz_knuckle translate FMunoz_posFC1}
		sphere {FMunoz_posFC2,FMunoz_lenghthand/20}
		sphere {FMunoz_posFC3,FMunoz_lenghthand/20}
		object {FMunoz_nail rotate <FMunoz_girFC*3,0,10> translate FMunoz_posFC4}
		cylinder {FMunoz_posFC1,FMunoz_posFC2,FMunoz_lenghthand/20}
		cylinder {FMunoz_posFC2,FMunoz_posFC3,FMunoz_lenghthand/20}
		cone {FMunoz_posFC3,FMunoz_lenghthand/20,FMunoz_posFC4,FMunoz_lenghthand/22}
	#end
	#if (FMunoz_Numberf > 3)
		object {FMunoz_knuckle translate FMunoz_posFD1}
		sphere {FMunoz_posFD2,FMunoz_lenghthand/20}
		sphere {FMunoz_posFD3,FMunoz_lenghthand/20}
		object {FMunoz_nail rotate <FMunoz_girFD*3,0,20> translate FMunoz_posFD4}
		cylinder {FMunoz_posFD1,FMunoz_posFD2,FMunoz_lenghthand/20}
		cylinder {FMunoz_posFD2,FMunoz_posFD3,FMunoz_lenghthand/20}
		cone {FMunoz_posFD3,FMunoz_lenghthand/20,FMunoz_posFD4,FMunoz_lenghthand/22}
	#end
	sphere {FMunoz_poswrist,FMunoz_lenghthand/10 texture{FMunoz_Texture1}}
	cone {FMunoz_poswrist,FMunoz_lenghthand/15,FMunoz_posTh1,FMunoz_lenghthand/20}
	cylinder {FMunoz_poswrist,FMunoz_posFA1,FMunoz_lenghthand/20}
	cylinder {FMunoz_posTh1,FMunoz_posFA1,FMunoz_lenghthand/20}
	sphere {FMunoz_posTh1,FMunoz_lenghthand/20}
	sphere {FMunoz_posFA1,FMunoz_lenghthand/20}
	triangle {FMunoz_poswrist,FMunoz_posTh1,FMunoz_posFA1}
	#if (FMunoz_Numberf > 1)
		triangle {FMunoz_poswrist,FMunoz_posFA1,FMunoz_posFB1}
		sphere {FMunoz_posFB1,FMunoz_lenghthand/20}
		cylinder {FMunoz_posFA1,FMunoz_posFB1,FMunoz_lenghthand/20}
		cylinder {FMunoz_poswrist,FMunoz_posFB1,FMunoz_lenghthand/20}
	#end
	#if (FMunoz_Numberf > 2)
		cylinder {FMunoz_poswrist,FMunoz_posFC1,FMunoz_lenghthand/20}
		triangle {FMunoz_poswrist,FMunoz_posFB1,FMunoz_posFC1}
		sphere {FMunoz_posFC1,FMunoz_lenghthand/20}
		cylinder {FMunoz_posFB1,FMunoz_posFC1,FMunoz_lenghthand/20}
	#end
	#if (FMunoz_Numberf > 3)
		cylinder {FMunoz_poswrist,FMunoz_posFD1,FMunoz_lenghthand/20}
		cylinder {FMunoz_posFC1,FMunoz_posFD1,FMunoz_lenghthand/20}
		sphere {FMunoz_posFD1,FMunoz_lenghthand/20}
		triangle {FMunoz_poswrist,FMunoz_posFC1,FMunoz_posFD1}
	#end
	texture {FMunoz_Texture2}
}
