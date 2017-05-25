// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_BabyDino.inc
// Desc: A wood T-Rex to use with FMunoz_Homid.inc
// Date: 26/08/1997
// Last: 09/07/2008
// Auth: Francisco Munoz, tweaked and prepared by Michael Horvath
// Version: Alpha 0.7


#ifndef (Black)		#include "colors.inc" #end
#ifndef (Gold_Texture)	#include "textures.inc" #end

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

#declare FMunoz_MainTexture =	texture {pigment {DMFWood2}}
#declare FMunoz_Textjoint =	texture {Bronze_Metal}
#declare FMunoz_Texture1 =	texture {FMunoz_Textjoint}
#declare FMunoz_Texture2 =	texture {FMunoz_MainTexture}
#declare FMunoz_Texture3 =	texture {FMunoz_Textjoint}
#declare FMunoz_height =	10;


// ----------------------------------------

#declare FMunoz_girXjaw =		-25;
#declare FMunoz_girYtail =		5;
#declare FMunoz_girYhead =		0;
#declare FMunoz_girXtail =		5;
#declare FMunoz_girXhead =		95;
#declare FMunoz_girXtorso =		-85;
#declare FMunoz_girXmusloI =		60;
#declare FMunoz_girXmusloD =		60;
#declare FMunoz_girXpantorrI =		-120;
#declare FMunoz_girXpantorrD =		-120;
#declare FMunoz_girXantebrazoD =	125;
#declare FMunoz_girXantebrazoI =	125;
#declare FMunoz_girZantebrazoD =	210;
#declare FMunoz_girZantebrazoI =	-210;
#declare FMunoz_girXbrazoD =		-65;
#declare FMunoz_girXbrazoI =		-60;


// ----------------------------------------

#declare FMunoz_heightorso =		2;
#declare FMunoz_widetorso =		.5;
#declare FMunoz_heightbelly =		1;
#declare FMunoz_widebelly =		2.5;	//false but needed to locate the legs
#declare FMunoz_lenghtmusloI =		1.5;
#declare FMunoz_widemusloI =		1;
#declare FMunoz_lenghtmusloD =		1.5;
#declare FMunoz_widemusloD =		1;
#declare FMunoz_lenghtpantorrD =	2;
#declare FMunoz_lenghtpantorrI =	2;
#declare FMunoz_altfootL =		1;
#declare FMunoz_altfootR =		1;
#declare FMunoz_anchfootL =		1;
#declare FMunoz_anchfootR =		1;
#declare FMunoz_lenghtarms =		1.5;
#undef FMunoz_lenghtarmI
#undef FMunoz_lenghtarmD
#undef FMunoz_lenghtupperarmI
#undef FMunoz_lenghtupperarmD
#declare FMunoz_flatfootR =		yes;
#declare FMunoz_flatfootL =		yes;

#declare FMunoz_incmano =		yes;
#declare FMunoz_lenghthand =		.75;
#declare FMunoz_girTh =			20;
#declare FMunoz_girFA =			40;
#declare FMunoz_girFB =			35;
#declare FMunoz_girFC =			45;
#declare FMunoz_Numberf =		3;
#declare FMunoz_nailclass =		3;


// ----------------------------------------

#ifndef (FMunoz_postailsection)	#declare FMunoz_postailsection = <0,0,0>;	#end

#declare FMunoz_tailsection = sphere {<0,0,0>,.25 texture {FMunoz_Textjoint}}

#declare FMunoz_belly = union
{
	#declare FMunoz_Count = 0;
	#while (FMunoz_Count < 6)
		#object
		{
			FMunoz_tailsection
			translate FMunoz_postailsection
			texture {FMunoz_Textjoint}
		}
		#declare FMunoz_Count = FMunoz_Count + 1;
		#declare FMunoz_postailsection = FMunoz_postailsection + vrotate (y*.5,<FMunoz_girXtail*FMunoz_Count+90,FMunoz_girYtail*FMunoz_Count,0>);
	#end
	#declare FMunoz_Count = 0;
	#while (FMunoz_Count < 6)
		#object
		{
			FMunoz_tailsection
			translate FMunoz_postailsection
			texture {FMunoz_Textjoint}
		}
		#declare FMunoz_Count = FMunoz_Count + 1;
		#declare FMunoz_postailsection = FMunoz_postailsection +vrotate (y*.5,<FMunoz_girXtail*6-FMunoz_girXtail*FMunoz_Count+90,FMunoz_girYtail*(6+FMunoz_Count),0>);
	#end
	cone {<0,0,0>,1,<0,-1.5,0>,.5 texture {FMunoz_MainTexture}}
}

#declare FMunoz_jaw = intersection
{
	sphere {<0,0,0>,.5 scale <1,1,2> }
	box {<1,-.2,1>,<-1,-4,-1>}
	texture {FMunoz_MainTexture}
}

#declare FMunoz_head = union
{
	sphere {<0,0,0>,.25 texture {FMunoz_Textjoint}}
	sphere {<0,.5,0>,.25 texture {FMunoz_Textjoint}}
	cylinder {<0,0,0>,<0,1.25,0>,.1}
	sphere {<0,1.25,0>,.5 scale <1,1,1> texture {FMunoz_MainTexture}}
	torus {.1,.05 rotate x*90 translate <.25,1.75,-1.2> texture {FMunoz_MainTexture}}
	torus {.1,.05 rotate x*90 translate <-.25,1.75,-1.2> texture {FMunoz_MainTexture}}
	sphere {<.35,1.8,-.5>,.15 texture {FMunoz_Textjoint}}
	sphere {<-.35,1.8,-.5>,.15 texture {FMunoz_Textjoint}}
	difference
	{
		sphere {<0,1.5,0>,.5 scale <1,1,2> translate <0,0,-.5>}
		box {<-.8,1.15,2>,<2,0,-2>}
		texture {FMunoz_MainTexture}
	}
	object
	{
		FMunoz_jaw
		translate <0,0,-.5>
		rotate <FMunoz_girXjaw,0,0>
		translate <0,1.5,0>
	}
}

#declare FMunoz_torso = union
{
	sphere {<0,0,0>,.25 }
	sphere {<0,.5,0>,.25}
	sphere {<0,1,0>,.25}
	sphere {<0,1.5,0>,.25}
	sphere {<0,2,0>,.25}
	cylinder {<0,0,0>,<0,2,0>,.1}
	cylinder {<0,.25,-.5>,<0,1.5,-.25>,.25 texture {FMunoz_MainTexture}}
	texture {FMunoz_Textjoint}
}

#declare FMunoz_musloD = union
{
	sphere {<0,0,0>,.5 texture{FMunoz_Textjoint}}
	cone {<0,-.25,0>,.4,<0,-1.5,0>,.2 texture {FMunoz_MainTexture}}
}

#declare FMunoz_musloI = object {FMunoz_musloD scale <-1,1,1>}

#declare FMunoz_pantorrD = union
{
	sphere {<0,0,0>,.22 texture {FMunoz_Textjoint}}
	cone { <0,-.20,0>,.2,<0,-2,0>,.15 texture {FMunoz_MainTexture}}
}

#declare FMunoz_pantorrI = object {FMunoz_pantorrD scale <-1,1,1>}

#declare FMunoz_footR = union
{
	sphere {<0,0,0>,.16 texture {FMunoz_Textjoint}}
	cone { <0,-.2,0>,.2,<0,-.75,-.75>,.15 texture {FMunoz_MainTexture}}
	sphere {<0,-.75,-.67>,.14 texture {FMunoz_Textjoint}}
	cylinder { <0,-.75,-.75>,<0,-1,-.75>,.3 texture {FMunoz_MainTexture}}
	difference
	{
		union
		{
			cone {<0,0,-.1>,.15,<0,0,-.6>,0 texture {FMunoz_Textjoint} scale <1,1.75,1> translate <0,-1,-.75>}
			cone {<0,0,-.1>,.15,<0,0,-.6>,0 texture {FMunoz_Textjoint} scale <1,1.5,1> rotate y*35 translate <0,-1,-.75>}
			cone {<0,0,-.1>,.15,<0,0,-.6>,0 texture {FMunoz_Textjoint} scale <1,1.5,1> rotate y*-35 translate <0,-1,-.75>}
		}
		plane {y,-1 texture {FMunoz_Textjoint}}
	}
}

#declare FMunoz_footL = object {FMunoz_footR scale <-1,1,1>}


// ----------------------------------------
//      The POV-Dino!!!

#include "FMunoz_Homid.inc"

#declare FMunoz_BabyDino_Object = object
{
	FMunoz_Homid_Base
	translate <vdot (z,-FMunoz_postobilloI),min (vdot (y,-FMunoz_postobilloD)+1,vdot (y,-FMunoz_postobilloI)+1),vdot (z,-FMunoz_postobilloI)>
}
