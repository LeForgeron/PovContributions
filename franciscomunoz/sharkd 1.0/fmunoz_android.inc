// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_Android.inc
// Desc: include file for generate bipedal beings
// Date: 23/08/1997
// Last: 08/07/2008
// Auth: Francisco Munoz Cotobal, Michael Horvath
// Some notes:
//  The rotation <0,0,0> in the arms gets a "hands up" posture
//  there are yet some bugs in this version (mostly by stupid mistakes
//    and a very bad english vocabulary)


#ifndef (Black)		#include "colors.inc" #end
#ifndef (Gold_Texture)	#include "textures.inc" #end
#include "FMunoz_Homid.inc"

#declare FMunoz_HeadAdjust = 25/64;
#undef FMunoz_belly
#undef FMunoz_torso
#undef FMunoz_head
#undef FMunoz_upperarmR
#undef FMunoz_forearmR
#undef FMunoz_handR
#undef FMunoz_upperarmL
#undef FMunoz_forearmL
#undef FMunoz_handL
#undef FMunoz_musloI
#undef FMunoz_pantorrI
#undef FMunoz_footR
#undef FMunoz_musloD
#undef FMunoz_pantorrD
#undef FMunoz_footL


// ----------------------------------------

#declare FMunoz_MainTexture =	Chrome_Metal;
#declare FMunoz_Textjoint =	Bronze_Metal;
#declare FMunoz_Textface =	Bronze_Metal;


// ---------------Torso-------------------------  Breast

#declare FMunoz_torso = union
{
	sphere {<0,FMunoz_widetorso*.2,0>,FMunoz_widetorso*.25 texture{FMunoz_Textjoint}}
	cone {<0,FMunoz_widetorso*.3,0>,FMunoz_widetorso*.35,<0,FMunoz_heightorso,0>,FMunoz_widetorso*.5 scale <1,1,.67>}
	cone {<0,FMunoz_heightorso,0>,FMunoz_widetorso*.5,<0,FMunoz_heightorso*1.2,0>,FMunoz_widetorso*.1 scale <1,1,.67>}
}


// ---------------belly-------------------------  Belly

#declare FMunoz_belly= union
{
	cylinder {<0,0,0>,<0,-FMunoz_heightbelly/2,0>,FMunoz_widebelly*.5 scale <1,1,.67>}
	cone {<0,-FMunoz_heightbelly/2,0>,FMunoz_widebelly*.5, <0,-FMunoz_heightbelly,0>,0 scale <1,1,.67>}
	cone {<0,0,0>,FMunoz_widebelly*.5,<0,FMunoz_heightbelly/2,0>,FMunoz_widebelly*.4 scale <1,1,.67>}
}


// ---------------head-------------------------  Head

#declare FMunoz_radiusneck =	FMunoz_heighthead/7;
#declare FMunoz_radiuscranium =	FMunoz_heighthead/4;
#declare FMunoz_posYcranium =	FMunoz_heighthead/2+FMunoz_radiuscranium;
#declare FMunoz_scaXhead =	FMunoz_heighthead/4;
#declare FMunoz_scaZhead =	FMunoz_heighthead/4;
#declare FMunoz_poshead =	(FMunoz_heighthead+FMunoz_radiusneck)/2;
#declare FMunoz_radiushead =	(FMunoz_heighthead-FMunoz_radiusneck)/2;

#declare FMunoz_neck = sphere {<0,0,0>,FMunoz_radiusneck}

#declare FMunoz_head = union
{
	object {FMunoz_neck texture {FMunoz_Textjoint} translate <0,FMunoz_radiusneck,0>}
	cone {<0,FMunoz_radiusneck,0>,FMunoz_radiusneck,<0,FMunoz_posYcranium,0>,FMunoz_radiusneck*3/4 texture {FMunoz_Textjoint}}
	blob
	{
		threshold 0.02
		sphere {<0,FMunoz_posYcranium-.5 * FMunoz_HeadAdjust,.5 * FMunoz_HeadAdjust>,FMunoz_radiuscranium*1.3, .9 scale <1/1.2,1,1.1>}
		sphere
		{
			<0,FMunoz_poshead,0>,FMunoz_radiushead, 1
			scale <FMunoz_scaXhead,FMunoz_radiushead,FMunoz_scaZhead>/FMunoz_radiushead
//		    	clipped_by {object {FMunoz_neck scale 1.2 inverse}}
		}
		translate <0,0,-2> * FMunoz_HeadAdjust
//		texture {FMunoz_Textjoint}
	}
	cone {<+FMunoz_scaXhead*0.9,FMunoz_poshead,-2 * FMunoz_HeadAdjust>,0.5 * FMunoz_HeadAdjust,<+FMunoz_scaXhead*1.1,FMunoz_poshead,-2 * FMunoz_HeadAdjust>,0.25 * FMunoz_HeadAdjust texture {FMunoz_Textface}}
	cone {<-FMunoz_scaXhead*0.9,FMunoz_poshead,-2 * FMunoz_HeadAdjust>,0.5 * FMunoz_HeadAdjust,<-FMunoz_scaXhead*1.1,FMunoz_poshead,-2 * FMunoz_HeadAdjust>,0.25 * FMunoz_HeadAdjust texture {FMunoz_Textface}}
	sphere {0,1 texture {FMunoz_Textface} scale <1,0.5,0.5> * FMunoz_HeadAdjust		translate <+1 * FMunoz_HeadAdjust,FMunoz_poshead,-3.9 * FMunoz_HeadAdjust>}
	sphere {0,1 texture {FMunoz_Textface} scale <1,0.5,0.5> * FMunoz_HeadAdjust		translate <-1 * FMunoz_HeadAdjust,FMunoz_poshead,-3.9 * FMunoz_HeadAdjust>}
	sphere {0,2 texture {FMunoz_Textface} scale <0.5,0.25,0.25> * FMunoz_HeadAdjust		translate <+0 * FMunoz_HeadAdjust,FMunoz_poshead-FMunoz_radiushead/2,-3.75 * FMunoz_HeadAdjust>}	//z=0.1
}


// -------------arm Izquierdo--------------------------- Left arm (actualy the right one)

#declare FMunoz_radiusshoulderI =	FMunoz_lenghtupperarmI/6;
#declare FMunoz_radiuselbowI =		FMunoz_lenghtarmI/6;
#declare FMunoz_radiuswristR =		FMunoz_lenghthandR/4;
#declare FMunoz_scaXhandR =		FMunoz_lenghthandR/4;
#declare FMunoz_scaZhandR =		FMunoz_lenghthandR/8;
#declare FMunoz_poshandR =		(FMunoz_lenghthandR+FMunoz_radiuswristR)/2;
#declare FMunoz_radiushandR =		(FMunoz_lenghthandR-FMunoz_radiuswristR)/2;

#declare FMunoz_upperarmR = union
{
	sphere {0,FMunoz_radiusshoulderI texture {FMunoz_Textjoint} scale y*1/2}
	cone {0,FMunoz_radiusshoulderI,y*FMunoz_lenghtupperarmI,FMunoz_radiuselbowI}
}

#declare FMunoz_forearmR = union
{
	sphere {0,FMunoz_radiuselbowI texture {FMunoz_Textjoint}}
	cone {0,FMunoz_radiuselbowI,y*FMunoz_lenghtarmI,FMunoz_radiuswristR}
}

#declare FMunoz_handR = union
{
	sphere {<0,0,0>,FMunoz_radiuswristR texture {FMunoz_Textjoint}}
	sphere {<0,FMunoz_poshandR,0>,FMunoz_radiushandR scale <FMunoz_scaXhandR,FMunoz_radiushandR,FMunoz_scaZhandR>/FMunoz_radiushandR}
	sphere {<0,FMunoz_radiuswristR,0>,FMunoz_lenghthandR/4 scale <2,.33,.33> rotate z*30 translate <FMunoz_radiuswristR,FMunoz_radiuswristR/2,0>}
}


// ----------------arm Derecho------------------------  Right Arm (well this is the left)

#declare FMunoz_radiusshoulderD =	FMunoz_lenghtupperarmD/6;
#declare FMunoz_radiuselbowD =		FMunoz_lenghtarmD/6;
#declare FMunoz_radiuswristL =		FMunoz_lenghthandL/4;
#declare FMunoz_scaXhandL =		FMunoz_lenghthandL/4;
#declare FMunoz_scaZhandL =		FMunoz_lenghthandL/8;
#declare FMunoz_poshandL =		(FMunoz_lenghthandL+FMunoz_radiuswristL)/2;
#declare FMunoz_radiushandL =		(FMunoz_lenghthandL-FMunoz_radiuswristL)/2;

#declare FMunoz_upperarmL = union
{
	sphere {0,FMunoz_radiusshoulderD texture {FMunoz_Textjoint} scale y * 1/2}
	cone {0,FMunoz_radiusshoulderD,y*FMunoz_lenghtupperarmD,FMunoz_radiuselbowD}
}

#declare FMunoz_forearmL = union
{
	sphere {0,FMunoz_radiuselbowD texture {FMunoz_Textjoint}}
	cone {0,FMunoz_radiuselbowD,y*FMunoz_lenghtarmD,FMunoz_radiuswristL}
}

#declare FMunoz_handL= union
{
	sphere {<0,0,0>,FMunoz_radiuswristL texture {FMunoz_Textjoint}}
	sphere {<0,FMunoz_poshandL,0>,FMunoz_radiushandL scale <FMunoz_scaXhandL,FMunoz_radiushandL,FMunoz_scaZhandL>/FMunoz_radiushandL}
	sphere {<0,FMunoz_radiuswristL,0>,FMunoz_lenghthandL/4 scale <2,.33,.33> rotate z*-30 translate <-FMunoz_radiuswristL,FMunoz_radiuswristL/2,0>}
}


// -------------Pierna Izquierdo--------------------------- Left leg

#declare FMunoz_radiushipI =	FMunoz_lenghtmusloI/4.5;
#declare FMunoz_radiuskneeI =	FMunoz_lenghtpantorrI/6;
#declare FMunoz_heightfootR =	FMunoz_lenghtpiernas*2.5/16;
#declare FMunoz_lenghtfootR =	FMunoz_lenghtpiernas*3/9;
#declare FMunoz_radiusankleR =	FMunoz_heightfootR/3;
#declare FMunoz_scaXFootR =	FMunoz_lenghtfootR/4;
#declare FMunoz_scaZFootR =	FMunoz_lenghtfootR/2;
#declare FMunoz_posfootR =	(FMunoz_heightfootR+FMunoz_radiusankleR)/2;
#declare FMunoz_radiusfootR =	FMunoz_radiusankleR;

#declare FMunoz_musloI = union
{
	sphere {<0,0,0>,FMunoz_radiushipI texture {FMunoz_Textjoint} scale y * 2}
	cone {0,FMunoz_radiushipI,y*-FMunoz_lenghtmusloI,FMunoz_radiuskneeI}
}

#declare FMunoz_pantorrI = union
{
	sphere {<0,0,0>,FMunoz_radiuskneeI texture {FMunoz_Textjoint}}
	cone {0,FMunoz_radiuskneeI,y*-FMunoz_lenghtpantorrI,FMunoz_radiusankleR}
}

#declare FMunoz_footR= union
{
	sphere {<0,0,0>,FMunoz_radiusankleR texture {FMunoz_Textjoint}}
	cone {<0,-FMunoz_posfootR,-FMunoz_lenghtfootR*.65>,FMunoz_radiusfootR*.75,<0,-FMunoz_posfootR,0.5>,FMunoz_radiusfootR}
	sphere {<0,-FMunoz_posfootR,0.5>,FMunoz_radiusfootR}
	clipped_by {plane {y,-FMunoz_posfootR*1.2 inverse}}
}


// -------------Pierna Derecha--------------------------- Right left (again the right one)

#declare FMunoz_radiushipD =	FMunoz_lenghtmusloD/4.5;
#declare FMunoz_radiuskneeD =	FMunoz_lenghtpantorrD/6;
#declare FMunoz_heightfootL =	FMunoz_lenghtpiernas*2.5/16;
#declare FMunoz_radiusankleL =	FMunoz_heightfootL/3;
#declare FMunoz_lenghtfootL =	FMunoz_lenghtpiernas*3/9;
#declare FMunoz_scaXFootL =	FMunoz_lenghtfootL/4;
#declare FMunoz_scaZFootL =	FMunoz_lenghtfootL/2;
#declare FMunoz_posfootL =	(FMunoz_heightfootL+FMunoz_radiusankleL)/2;
#declare FMunoz_radiusfootL =	FMunoz_radiusankleL;


#declare FMunoz_musloD = union
{
	sphere {<0,0,0>,FMunoz_radiushipD texture {FMunoz_Textjoint} scale y * 2}
	cone {0,FMunoz_radiushipD,y*-FMunoz_lenghtmusloD,FMunoz_radiuskneeD}
}

#declare FMunoz_pantorrD = union
{
	sphere {<0,0,0>,FMunoz_radiuskneeD texture {FMunoz_Textjoint}}
	cone {0,FMunoz_radiuskneeD,y*-FMunoz_lenghtpantorrD,FMunoz_radiusankleL}
}

#declare FMunoz_footL = union
{
	sphere {<0,0,0>,FMunoz_radiusankleL texture {FMunoz_Textjoint}}
	cone {<0,-FMunoz_posfootL,-FMunoz_lenghtfootL*.65>,FMunoz_radiusfootL*.75,<0,-FMunoz_posfootL,0.5>,FMunoz_radiusfootL}
	sphere {<0,-FMunoz_posfootL,0.5>,FMunoz_radiusfootL}
	clipped_by {plane {y,-FMunoz_posfootL*1.2 inverse}}
}


// ----------------------------------------

#include "FMunoz_Homid.inc"

#declare FMunoz_Android_Object = object
{
	FMunoz_Homid_Base
	translate <0,-(min(vdot(y,FMunoz_postobilloD),vdot(y,FMunoz_postobilloI))) + FMunoz_heightfootR,0>
}