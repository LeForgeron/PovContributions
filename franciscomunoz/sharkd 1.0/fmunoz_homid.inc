// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_Homid.inc
// Desc: Include file for generate bipedal beings.
// Date: 23/08/1997
// Last: 08/07/2008
// Auth: Francisco Munoz Cotobal, tweaked and prepared by Michael Horvath
// Homid.inc version: Alpha 0.5
// Some notes:
//  The rotation <0,0,0> in the arms gets a "hands up" posture
//  there are yet some bugs in this version (mostly by stupid mistakes
//    and a very bad english vocabulary)


#ifndef (Black)		#include "colors.inc" #end
#ifndef (Gold_Texture)	#include "textures.inc" #end


// ----------------------------------------

#ifndef (FMunoz_MainTexture)
	#ifndef (DMFWood2)
		#warning "colors.inc or textures.inc not #included !!! \n"
		#declare FMunoz_MainTexture = texture {pigment {color rgb <0.7,0.7,0.7>}}
	#else
		#declare FMunoz_MainTexture = texture {pigment {DMFWood2}}
	#end
#end

#ifndef (FMunoz_Textjoint)	#declare FMunoz_Textjoint = texture {Bronze_Metal}	#end

#ifndef (FMunoz_height)		#declare FMunoz_height = 25;				#end


// ---------------belly-------------------------  Belly

#ifndef (FMunoz_heightbelly)	#declare FMunoz_heightbelly = FMunoz_height * 3/25;	#end
#ifndef (FMunoz_widebelly)	#declare FMunoz_widebelly = FMunoz_heightbelly * 4/3;	#end

#ifndef (FMunoz_belly)
	#declare FMunoz_belly = union
	{
		cylinder {<0,0,0>,<0,-FMunoz_heightbelly/2,0>,FMunoz_widebelly * 0.5 scale <1,1,0.75>}
		cone {<0,-FMunoz_heightbelly/2,0>,FMunoz_widebelly * 0.5,<0,-FMunoz_heightbelly,0>,0 scale <1,1,0.75>}
	}
#end


// ---------------Torso-------------------------  Breast

#ifndef (FMunoz_heightorso)	#declare FMunoz_heightorso = FMunoz_height/5;		#end
#ifndef (FMunoz_widetorso)	#declare FMunoz_widetorso = FMunoz_heightorso;		#end
#ifndef (FMunoz_girXtorso)	#declare FMunoz_girXtorso = 0;				#end
#ifndef (FMunoz_girYtorso)	#declare FMunoz_girYtorso = 0;				#end
#ifndef (FMunoz_girZtorso)	#declare FMunoz_girZtorso = 0;				#end

#ifndef (FMunoz_torso)
	#declare FMunoz_torso = union
	{
		sphere {<0,FMunoz_widetorso * 0.2,0>, FMunoz_widetorso * 0.25 texture {FMunoz_Textjoint}}
		cone {<0,FMunoz_widetorso * 0.3,0>, FMunoz_widetorso * 0.35, <0,FMunoz_heightorso,0>, FMunoz_widetorso * 0.5 scale <1,1,0.75>}
	}
#end


// ---------------head-------------------------  Head

#ifndef (FMunoz_heighthead)	#declare FMunoz_heighthead = FMunoz_heightorso * 0.8;	#end
#ifndef (FMunoz_widehead)	#declare FMunoz_widehead = FMunoz_heighthead * 0.55;	#end
#ifndef (FMunoz_girXhead)	#declare FMunoz_girXhead = 0;				#end
#ifndef (FMunoz_girYhead)	#declare FMunoz_girYhead = 0;				#end
#ifndef (FMunoz_girZhead)	#declare FMunoz_girZhead = 0;				#end
#declare FMunoz_girXhead2 =	FMunoz_girXhead + FMunoz_girXtorso;
#declare FMunoz_girYhead2 =	FMunoz_girYhead + FMunoz_girYtorso;
#declare FMunoz_girZhead2 =	FMunoz_girZhead + FMunoz_girZtorso;

#ifndef (FMunoz_head)
	#declare FMunoz_head = union
	{
		sphere {<0,FMunoz_heighthead * 0.1,0>, FMunoz_heighthead * 0.12 texture {FMunoz_Textjoint}}
		sphere {<0,FMunoz_heighthead * 0.55,0>, FMunoz_heighthead * 0.45
		scale <FMunoz_widehead/FMunoz_heighthead,1,FMunoz_widehead/FMunoz_heighthead>}
	}
#end


// -------------arm Izquierdo--------------------------- Left arm (actualy the right one)

#ifndef (FMunoz_lenghtarms)		#declare FMunoz_lenghtarms = FMunoz_height * 10/25;		#end

#ifndef (FMunoz_lenghtupperarmI)	#declare FMunoz_lenghtupperarmI = FMunoz_lenghtarms * 5/12;	#end
#ifndef (FMunoz_girXupperarmI)		#declare FMunoz_girXupperarmI = 15;				#end
#ifndef (FMunoz_girYupperarmI)		#declare FMunoz_girYupperarmI = 0;				#end
#ifndef (FMunoz_girZupperarmI)		#declare FMunoz_girZupperarmI = 170;				#end
#declare FMunoz_girXupperarmI2 =	FMunoz_girXupperarmI + FMunoz_girXtorso;
#declare FMunoz_girYupperarmI2 =	FMunoz_girYupperarmI + FMunoz_girYtorso;
#declare FMunoz_girZupperarmI2 =	FMunoz_girZupperarmI + FMunoz_girZtorso;

#ifndef (FMunoz_lenghtarmI)		#declare FMunoz_lenghtarmI = FMunoz_lenghtarms * 4.5/12;	#end
#ifndef (FMunoz_girXarmI)		#declare FMunoz_girXarmI = -50;					#end
#ifndef (FMunoz_girYarmI)		#declare FMunoz_girYarmI = 0;					#end
#ifndef (FMunoz_girZarmI)		#declare FMunoz_girZarmI = -10;					#end
#declare FMunoz_girXarmI2 =		FMunoz_girXarmI + FMunoz_girXupperarmI2;
#declare FMunoz_girYarmI2 =		FMunoz_girYarmI + FMunoz_girYupperarmI2;
#declare FMunoz_girZarmI2 =		FMunoz_girZarmI + FMunoz_girZupperarmI2;

#ifndef (FMunoz_lenghthandR)		#declare FMunoz_lenghthandR = FMunoz_lenghtarms * 2.5/12;	#end
#ifndef (FMunoz_girXhandR)		#declare FMunoz_girXhandR = 0;					#end
#ifndef (FMunoz_girYhandR)		#declare FMunoz_girYhandR = -15;				#end
#ifndef (FMunoz_girZhandR)		#declare FMunoz_girZhandR = 0;					#end
#declare FMunoz_girXhandR2 =		FMunoz_girXarmI2 + FMunoz_girXhandR;
#declare FMunoz_girYhandR2 =		FMunoz_girYarmI2 + FMunoz_girYhandR;
#declare FMunoz_girZhandR2 =		FMunoz_girZarmI2 + FMunoz_girZhandR;

#ifndef (FMunoz_incmano)		#declare FMunoz_incmano = 0;					#end

#ifndef (FMunoz_upperarmR)
	#declare FMunoz_upperarmR = union
	{
		sphere {<0,0,0>,FMunoz_lenghtupperarmI/10 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtupperarmI/10,FMunoz_lenghtupperarmI/10,-FMunoz_lenghtupperarmI/10>,<FMunoz_lenghtupperarmI/10,FMunoz_lenghtupperarmI,FMunoz_lenghtupperarmI/10>}
	}
#end

#ifndef (FMunoz_forearmR)
	#declare FMunoz_forearmR = union
	{
		sphere {<0,0,0>,FMunoz_lenghtarmI/10 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtarmI/10,FMunoz_lenghtarmI/10,-FMunoz_lenghtarmI/10>,<FMunoz_lenghtarmI/10,FMunoz_lenghtarmI,FMunoz_lenghtarmI/10>}
	}
#end

#if (FMunoz_incmano)
	#ifndef (FMunoz_lenghthand)	#declare FMunoz_lenghthand = FMunoz_lenghthandR;		#end
	#include "FMunoz_Mano.inc"
	#declare FMunoz_handR = object {FMunoz_hand scale <-1,1,1>}
#else
	#ifndef (FMunoz_handR)
		#declare FMunoz_handR = union
		{
			sphere {<0,0,0>,FMunoz_lenghthandR*.15 texture {FMunoz_Textjoint}}
			sphere {<0,FMunoz_lenghthandR*.55,0>,FMunoz_lenghthandR*.45 scale <.25,.9,.5>}
		}
	#end
#end


// ----------------arm Derecho------------------------  Right Arm (well this is the left)

#ifndef (FMunoz_lenghtupperarmD)	#declare FMunoz_lenghtupperarmD = FMunoz_lenghtarms * 5/12;	#end
#ifndef (FMunoz_girXupperarmD)		#declare FMunoz_girXupperarmD = -15;				#end
#ifndef (FMunoz_girYupperarmD)		#declare FMunoz_girYupperarmD = 0;				#end
#ifndef (FMunoz_girZupperarmD)		#declare FMunoz_girZupperarmD = 190;				#end
#declare FMunoz_girXupperarmD2 =	FMunoz_girXupperarmD + FMunoz_girXtorso;
#declare FMunoz_girYupperarmD2 =	FMunoz_girYupperarmD + FMunoz_girYtorso;
#declare FMunoz_girZupperarmD2 =	FMunoz_girZupperarmD + FMunoz_girZtorso;

#ifndef (FMunoz_lenghtarmD)		#declare FMunoz_lenghtarmD = FMunoz_lenghtarms * 4.5/12;	#end
#ifndef (FMunoz_girXarmD)		#declare FMunoz_girXarmD = -20;					#end
#ifndef (FMunoz_girYarmD)		#declare FMunoz_girYarmD = 0;					#end
//Cuidadin al tocar que da aspecto mariposon ;-)
#ifndef (FMunoz_girZarmD)		#declare FMunoz_girZarmD = 10;					#end
#declare FMunoz_girXarmD2 =		FMunoz_girXarmD + FMunoz_girXupperarmD2;
#declare FMunoz_girYarmD2 =		FMunoz_girYarmD + FMunoz_girYupperarmD2;
#declare FMunoz_girZarmD2 =		FMunoz_girZarmD + FMunoz_girZupperarmD2;

#ifndef (FMunoz_lenghthandL)		#declare FMunoz_lenghthandL = FMunoz_lenghtarms * 2.5/12;	#end
#ifndef (FMunoz_girXhandL)		#declare FMunoz_girXhandL = 0;					#end
#ifndef (FMunoz_girYhandL)		#declare FMunoz_girYhandL = -15;				#end
#ifndef (FMunoz_girZhandL)		#declare FMunoz_girZhandL = 0;					#end
#declare FMunoz_girXhandL2 =		FMunoz_girXarmD2 + FMunoz_girXhandL;
#declare FMunoz_girYhandL2 =		FMunoz_girYarmD2 + FMunoz_girYhandL;
#declare FMunoz_girZhandL2 =		FMunoz_girZarmD2 + FMunoz_girZhandL;

#ifndef (FMunoz_upperarmL)
	#declare FMunoz_upperarmL = union
	{
		sphere {<0,0,0>,FMunoz_lenghtupperarmD/10 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtupperarmD/10,FMunoz_lenghtupperarmD/10,-FMunoz_lenghtupperarmD/10>,<FMunoz_lenghtupperarmD/10,FMunoz_lenghtupperarmD,FMunoz_lenghtupperarmD/10>}
	}
#end

#ifndef (FMunoz_forearmL)
	#declare FMunoz_forearmL = union
	{
		sphere {<0,0,0>,FMunoz_lenghtarmD/10 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtarmD/10,FMunoz_lenghtarmD/10,-FMunoz_lenghtarmD/10>,<FMunoz_lenghtarmD/10,FMunoz_lenghtarmD,FMunoz_lenghtarmD/10>}
	}
#end

#if (FMunoz_incmano)
//	#ifndef (FMunoz_lenghthand) #declare FMunoz_lenghthand=FMunoz_lenghthandL; #end
//	#include "mano.inc"
	#declare FMunoz_lenghthand = FMunoz_lenghthandL;
	#declare FMunoz_handL = object {FMunoz_hand}
#else
	#ifndef(FMunoz_handL)
		#declare FMunoz_handL = union
		{
			sphere {<0,0,0>,FMunoz_lenghthandL * 0.15 texture {FMunoz_Textjoint}}
			sphere {<0,FMunoz_lenghthandL * 0.55,0>,FMunoz_lenghthandL * 0.45 scale <0.25,0.9,0.5>}
		}
	#end
#end


// -------------Pierna Izquierdo--------------------------- Left leg

#ifndef (FMunoz_lenghtpiernas)		#declare FMunoz_lenghtpiernas = FMunoz_height * 12.5/25;	#end

#ifndef (FMunoz_lenghtmusloI)		#declare FMunoz_lenghtmusloI = FMunoz_lenghtpiernas * 4.5/12;	#end
#ifndef (FMunoz_widemusloI)		#declare FMunoz_widemusloI = FMunoz_lenghtpiernas/5;		#end
#ifndef (FMunoz_girXmusloI)		#declare FMunoz_girXmusloI = 0;					#end
#ifndef (FMunoz_girYmusloI)		#declare FMunoz_girYmusloI = 0;					#end
#ifndef (FMunoz_girZmusloI)		#declare FMunoz_girZmusloI = 0;					#end

#ifndef (FMunoz_lenghtpantorrI)		#declare FMunoz_lenghtpantorrI = FMunoz_lenghtpiernas * 6/12;	#end
#ifndef (FMunoz_girXpantorrI)		#declare FMunoz_girXpantorrI = 0;				#end
#ifndef (FMunoz_girYpantorrI)		#declare FMunoz_girYpantorrI = 0;				#end
#ifndef (FMunoz_girZpantorrI)		#declare FMunoz_girZpantorrI = 0;				#end
#declare FMunoz_girXpantorrI2 =		FMunoz_girXpantorrI + FMunoz_girXmusloI;
#declare FMunoz_girYpantorrI2 =		FMunoz_girYpantorrI + FMunoz_girYmusloI;
#declare FMunoz_girZpantorrI2 =		FMunoz_girZpantorrI + FMunoz_girZmusloI;

#ifndef (FMunoz_heightfootR)		#declare FMunoz_heightfootR = FMunoz_lenghtpiernas * 2.5/12;	#end
#ifndef (FMunoz_lenghtfootR)		#declare FMunoz_lenghtfootR = FMunoz_lenghtpiernas * 3/12;	#end
#ifndef (FMunoz_girXfootR)		#declare FMunoz_girXfootR = 0;					#end
#declare FMunoz_girXfootR2 =		FMunoz_girXpantorrI2 + FMunoz_girXfootR;
#ifndef (FMunoz_girZfootR)		#declare FMunoz_girZfootR = 0;					#end
#declare FMunoz_girZfootR2 =		FMunoz_girZpantorrI2 + FMunoz_girZfootR;
#ifndef (FMunoz_girYfootR)		#declare FMunoz_girYfootR = FMunoz_girYmusloI + FMunoz_girYpantorrI2;	#end
#declare FMunoz_girYfootR2 =		FMunoz_girYfootR;

#ifndef (FMunoz_musloI)
	#declare FMunoz_musloI = union
	{
		sphere {<0,0,0>,FMunoz_lenghtmusloI/9 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtmusloI/8,-FMunoz_lenghtmusloI/10,-FMunoz_lenghtmusloI/8>,<FMunoz_lenghtmusloI/8,-FMunoz_lenghtmusloI,FMunoz_lenghtmusloI/8>}
	}
#end

#ifndef (FMunoz_pantorrI)
	#declare FMunoz_pantorrI = union
	{
		sphere {<0,0,0>,FMunoz_lenghtpantorrI/10 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtpantorrI/9,-FMunoz_lenghtpantorrI/10,-FMunoz_lenghtpantorrI/9>,<FMunoz_lenghtpantorrI/9,-FMunoz_lenghtpantorrI,FMunoz_lenghtpantorrI/9>}
	}
#end

#ifndef (FMunoz_footR)
	#declare FMunoz_footR = union
	{
		sphere {<0,-FMunoz_heightfootR * 0.10,0>,FMunoz_heightfootR * 0.25 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtfootR * 0.25,-FMunoz_heightfootR * 0.4,FMunoz_lenghtfootR * 0.35>,<FMunoz_lenghtfootR * 0.25,-FMunoz_heightfootR,-FMunoz_lenghtfootR * 0.65>}
	}
#end


// -------------Pierna Derecha--------------------------- Right left (again the right one)

#ifndef (FMunoz_lenghtmusloD)		#declare FMunoz_lenghtmusloD = FMunoz_lenghtpiernas * 4.5/12;	#end
#ifndef (FMunoz_widemusloD)		#declare FMunoz_widemusloD = FMunoz_lenghtpiernas/5;		#end
#ifndef (FMunoz_girXmusloD)		#declare FMunoz_girXmusloD = 0;					#end
#ifndef (FMunoz_girYmusloD)		#declare FMunoz_girYmusloD = 0;					#end
#ifndef (FMunoz_girZmusloD)		#declare FMunoz_girZmusloD = 0;					#end

#ifndef (FMunoz_lenghtpantorrD)		#declare FMunoz_lenghtpantorrD = FMunoz_lenghtpiernas * 6/12;	#end
#ifndef (FMunoz_girXpantorrD)		#declare FMunoz_girXpantorrD = 0;				#end
#ifndef (FMunoz_girYpantorrD)		#declare FMunoz_girYpantorrD = 0;				#end
#ifndef (FMunoz_girZpantorrD)		#declare FMunoz_girZpantorrD = 0;				#end
#declare FMunoz_girXpantorrD2 =		FMunoz_girXpantorrD + FMunoz_girXmusloD;
#declare FMunoz_girYpantorrD2 =		FMunoz_girYpantorrD + FMunoz_girYmusloD;
#declare FMunoz_girZpantorrD2 =		FMunoz_girZpantorrD + FMunoz_girZmusloD;

#ifndef (FMunoz_heightfootL)		#declare FMunoz_heightfootL = FMunoz_lenghtpiernas * 2.5/12;	#end
#ifndef (FMunoz_lenghtfootL)		#declare FMunoz_lenghtfootL = FMunoz_lenghtpiernas * 3/12;	#end
#ifndef (FMunoz_girXfootL)		#declare FMunoz_girXfootL = 0;					#end
#declare FMunoz_girXfootL2 =		FMunoz_girXpantorrD2 + FMunoz_girXfootL;
#ifndef (FMunoz_girZfootL)		#declare FMunoz_girZfootL = 0;					#end
#declare FMunoz_girZfootL2 =		FMunoz_girZpantorrD2 + FMunoz_girZfootL;
#ifndef (FMunoz_girYfootL)		#declare FMunoz_girYfootL = FMunoz_girYmusloD + FMunoz_girYpantorrD2;	#end
#declare FMunoz_girYfootL2 =		FMunoz_girYfootL;

#ifndef (FMunoz_musloD)
	#declare FMunoz_musloD = union
	{
		sphere {<0,0,0>,FMunoz_lenghtmusloD/10 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtmusloD/8,-FMunoz_lenghtmusloD/10,-FMunoz_lenghtmusloD/8>,<FMunoz_lenghtmusloD/8,-FMunoz_lenghtmusloD,FMunoz_lenghtmusloD/8>}
	}
#end

#ifndef (FMunoz_pantorrD)
	#declare FMunoz_pantorrD = union
	{
		sphere {<0,0,0>,FMunoz_lenghtpantorrD/10 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtpantorrD/9,-FMunoz_lenghtpantorrD/10,-FMunoz_lenghtpantorrD/9>,<FMunoz_lenghtpantorrD/9,-FMunoz_lenghtpantorrD,FMunoz_lenghtpantorrD/9>}
	}
#end

#ifndef (FMunoz_footL)
	#declare FMunoz_footL = union
	{
		sphere {<0,-FMunoz_heightfootL * 0.10,0>,FMunoz_heightfootL * 0.25 texture {FMunoz_Textjoint}}
		box {<-FMunoz_lenghtfootL * 0.25,-FMunoz_heightfootL * 0.4,FMunoz_lenghtfootL * 0.35>,<FMunoz_lenghtfootL * 0.25,-FMunoz_heightfootL,-FMunoz_lenghtfootL * 0.65>}
	}
#end


// ----------------------------------------

#declare FMunoz_pospanza =		0;
#declare FMunoz_poscuello =		vrotate(<0,FMunoz_heightorso,0>,<FMunoz_girXtorso,FMunoz_girYtorso,FMunoz_girZtorso>) + FMunoz_pospanza;

#declare FMunoz_poshombroI =		vrotate(<-FMunoz_widetorso/2,FMunoz_heightorso,0>,<FMunoz_girXtorso,FMunoz_girYtorso,FMunoz_girZtorso>) + FMunoz_pospanza;
#declare FMunoz_poscodoI =		vrotate(<0,FMunoz_lenghtupperarmI,0>,<FMunoz_girXupperarmI2,FMunoz_girYupperarmI2,FMunoz_girZupperarmI2>) + FMunoz_poshombroI;
#declare FMunoz_posmunyecaI =		vrotate(<0,FMunoz_lenghtarmI,0>,<FMunoz_girXarmI2,FMunoz_girYarmI2,FMunoz_girZarmI2>) + FMunoz_poscodoI;

#declare FMunoz_poshombroD =		vrotate(<+FMunoz_widetorso/2,FMunoz_heightorso,0>,<FMunoz_girXtorso,FMunoz_girYtorso,FMunoz_girZtorso>) + FMunoz_pospanza;
#declare FMunoz_poscodoD =		vrotate(<0,FMunoz_lenghtupperarmD,0>,<FMunoz_girXupperarmD2,FMunoz_girYupperarmD2,FMunoz_girZupperarmD2>) + FMunoz_poshombroD;
#declare FMunoz_posmunyecaD =		vrotate(<0,FMunoz_lenghtarmD,0>,<FMunoz_girXarmD2,FMunoz_girYarmD2,FMunoz_girZarmD2>) + FMunoz_poscodoD;

#declare FMunoz_poscaderaI =		vrotate(<+FMunoz_widemusloI/2 - FMunoz_widebelly/1.75,-FMunoz_heightbelly * 0.8,0>,0) + FMunoz_pospanza;
#declare FMunoz_posrodillaI =		vrotate(<0,-FMunoz_lenghtmusloI,0>,<FMunoz_girXmusloI,FMunoz_girYmusloI,FMunoz_girZmusloI>) + FMunoz_poscaderaI;
#declare FMunoz_postobilloI =		vrotate(<0,-FMunoz_lenghtpantorrI,0>,<FMunoz_girXpantorrI2,FMunoz_girYmusloI,FMunoz_girZpantorrI2>) + FMunoz_posrodillaI;

#declare FMunoz_poscaderaD =		vrotate(<-FMunoz_widemusloD/2 + FMunoz_widebelly/1.75,-FMunoz_heightbelly * 0.8,0>,0) + FMunoz_pospanza;
#declare FMunoz_posrodillaD =		vrotate(<0,-FMunoz_lenghtmusloD,0>,<FMunoz_girXmusloD,FMunoz_girYmusloD,FMunoz_girZmusloD>) + FMunoz_poscaderaD;
#declare FMunoz_postobilloD =		vrotate(<0,-FMunoz_lenghtpantorrD,0>,<FMunoz_girXpantorrD2,FMunoz_girYmusloD,FMunoz_girZpantorrD2>) + FMunoz_posrodillaD;

#declare FMunoz_pospalmaI =		vrotate(<0,-FMunoz_lenghthandR/2,0>,<FMunoz_girXhandR2,FMunoz_girYhandR2,FMunoz_girZhandR2>) + FMunoz_posmunyecaI;
#declare FMunoz_pospalmaD =		vrotate(<0,-FMunoz_lenghthandL/2,0>,<FMunoz_girXhandL2,FMunoz_girYhandL2,FMunoz_girZhandL2>) + FMunoz_posmunyecaD;

//To put "flat feets" (no rotated, paralel to floor
#ifndef (FMunoz_flatfeet)		#declare FMunoz_flatfeet = no;		#end
#if (FMunoz_flatfeet)
	#ifndef (FMunoz_flatfootL)	#declare FMunoz_flatfootL = yes;	#end
	#ifndef (FMunoz_flatfootR)	#declare FMunoz_flatfootR = yes;	#end
#end
#ifndef (FMunoz_flatfootL)		#declare FMunoz_flatfootL = no;		#end
#ifndef (FMunoz_flatfootR)		#declare FMunoz_flatfootR = no;		#end

#if (FMunoz_flatfootR)
	#declare FMunoz_girXfootR2 =	0;
	#declare FMunoz_girZfootR2 =	0;
#end

#if (FMunoz_flatfootL)
	#declare FMunoz_girXfootL2 =	0;
	#declare FMunoz_girZfootL2 =	0;
#end


// ----------------------------------------

#declare FMunoz_Homid_Base = union
{
	object
	{
		FMunoz_belly
		translate FMunoz_pospanza
	}
	object
	{
		FMunoz_torso
		rotate <FMunoz_girXtorso,FMunoz_girYtorso,FMunoz_girZtorso>
		translate FMunoz_pospanza
	}
	object
	{
		FMunoz_head
		rotate <FMunoz_girXhead2,FMunoz_girYhead2,FMunoz_girZhead2>
		translate FMunoz_poscuello
	}
	object
	{
		FMunoz_upperarmR
		rotate <FMunoz_girXupperarmI2,FMunoz_girYupperarmI2,FMunoz_girZupperarmI2>
		translate FMunoz_poshombroI
	}
	object
	{
		FMunoz_forearmR
		rotate <FMunoz_girXarmI2,FMunoz_girYupperarmI2,FMunoz_girZarmI2>
		translate FMunoz_poscodoI
	}
	object
	{
		FMunoz_handR
		rotate <FMunoz_girXhandR2,FMunoz_girYhandR2,FMunoz_girZhandR2>
		translate FMunoz_posmunyecaI
	}
	object
	{
		FMunoz_upperarmL
		rotate <FMunoz_girXupperarmD2,FMunoz_girYupperarmD2,FMunoz_girZupperarmD2>
		translate FMunoz_poshombroD
	}
	object
	{
		FMunoz_forearmL
		rotate <FMunoz_girXarmD2,FMunoz_girYarmD2,FMunoz_girZarmD2>
		translate FMunoz_poscodoD
	}
	object
	{
		FMunoz_handL
		rotate <FMunoz_girXhandL2,FMunoz_girYhandL2,FMunoz_girZhandL2>
		translate FMunoz_posmunyecaD
	}
	object
	{
		FMunoz_musloI
		rotate <FMunoz_girXmusloI,FMunoz_girYmusloI,FMunoz_girZmusloI>
		translate FMunoz_poscaderaI
	}
	object
	{
		FMunoz_pantorrI
		rotate <FMunoz_girXpantorrI2,FMunoz_girYmusloI,FMunoz_girZpantorrI2>
		translate FMunoz_posrodillaI
	}
	object
	{
		FMunoz_footR
		rotate <FMunoz_girXfootR2,FMunoz_girYfootR2,FMunoz_girZfootR2>
		translate FMunoz_postobilloI
	}
	object
	{
		FMunoz_musloD
		rotate <FMunoz_girXmusloD,FMunoz_girYmusloD,FMunoz_girZmusloD>
		translate FMunoz_poscaderaD
	}
	object
	{
		FMunoz_pantorrD
		rotate <FMunoz_girXpantorrD2,FMunoz_girYmusloD,FMunoz_girZpantorrD2>
		translate FMunoz_posrodillaD
	}
	object
	{
		FMunoz_footL
		rotate <FMunoz_girXfootL2,FMunoz_girYfootL2,FMunoz_girZfootL2>
		translate FMunoz_postobilloD
	}
	texture {FMunoz_MainTexture}
}

#declare FMunoz_Homid_Object = object
{
	FMunoz_Homid_Base
	translate <0,-(min(vdot(y,FMunoz_postobilloD),vdot(y,FMunoz_postobilloI))) + FMunoz_heightfootR,0>
}
