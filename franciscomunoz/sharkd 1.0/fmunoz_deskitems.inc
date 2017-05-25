// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// Date: 01/1998
// Last: 08/07/2008
// Auth: Francisco Munoz, tweaked and prepared by Michael Horvath
// Scale: 1 unit = 1 Cm.
// Based on a real object (Yes, i have one like it)
// An ink dryer (not sure about name in english
//      but render it and you'll see it;)
// Along z axis (base at z=0)
//  Can be bounded box of left, bottom, "far" <-5,0,10>
//                    right, top, "near" <5,4,0>

#ifndef (Black)		#include "colors.inc" #end
#ifndef (Gold_Texture)	#include "textures.inc" #end

#local FMunoz_G1 = texture {pigment {color Brass} finish {specular .3 reflection .3}}

#local FMunoz_Inked_Paper = texture
{
	pigment
	{
		granite
		color_map
		{
			[0.0 color White]
			[0.6 color White]
			[0.9 color NavyBlue]
		}
	}
	finish {ambient .4}
	scale 1.5
}

#declare FMunoz_Blotter = union
{
	sphere {<0,2,8>,2 texture {FMunoz_G1}}
	cylinder {<0,2,8>,<0,2,4>,1 texture {FMunoz_G1}}
	difference
	{
		cylinder {<0,0,4>,<0,4,4>,3.9}
		cylinder {<0,-0.1,4>,<0,4.1,4>,3.75}
		box {<-5,-1,9>,<5,5,4>}
		texture {FMunoz_G1}
		scale <1.25,1,1>
	}
	difference
	{
		cylinder {<0,1,4>,<0,3,4>,3.9}
		box {<-5,-1,9>,<5,5,4>}
		texture {FMunoz_G1}
		scale <1.25,1,1>
	}
	//Paper Layer to dry ink
	difference
	{
		cylinder {<0,.1,4>,<0,3.9,4>,4}
		cylinder {<0,-0.1,4>,<0,4.1,4>,3.9}
		box {<-5,-1,9>,<5,5,3.95>}
		texture {FMunoz_Inked_Paper}
		scale <1.25,1,1>
	}
	box {<-4.95,0,3.75>,<4.95,4,4> texture {FMunoz_G1}}
	cylinder {<0,.75,2>,<0,3.25,2>,1.25 texture {FMunoz_G1}}
	torus {1.25,.25 translate <0,0.95,2> texture {FMunoz_G1}}
	torus {1.25,.25 translate <0,3.05,2> texture {FMunoz_G1}}
	torus {2,.1 rotate x*90 translate <0,2,4>}
	rotate x * -90
	translate z * 2
}


// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// Date: --/10/1997  (revised in 01/1998)
// Last: 08/07/2008
// Auth: Francisco Munoz, tweaked by Michael Horvath
// Scale: 1 unit = 1 Cm.
// Based on a true object :-) (just check my web page to see
//         a more accurate white model)
// A pen 11.2 units high (y axis from 0), and .4 radius
// A pencap 5.1 units high (y axis from 0), and .4 radius
// To close put the base of cap at y=7.6

// A very simple texture
#local FMunoz_My_Black_Texture = texture
{
	pigment {color rgb <0,0,0>}
	finish {phong 0.8}
}

#declare FMunoz_Pen = union
{
	cylinder {<0,0,0>,<0,1.4,0>,.35 texture {Gold_Texture}}
	cylinder {<0,1.3,0>,<0,7.6,0>,.4 texture {FMunoz_My_Black_Texture}}
	cylinder {<0,7.59,0>,<0,7.54,0>,.401 texture {Gold_Texture}}
	cone {<0,7.55,0>,.35,<0,9.9,0>,.3 texture {Gold_Texture}}
	cone {<0,9.89,0>,.25,<0,9.91,0>,.23 texture {FMunoz_My_Black_Texture}}
	cone {<0,9.89,0>,.24,<0,10.2,0>,.25 texture {FMunoz_My_Black_Texture}}
	cone {<0,10.2,0>,.25,<0,10.3,0>,.23 texture {FMunoz_My_Black_Texture}}
	cylinder {<0,10.3,0>,<0,10.35,0>,.18 texture {FMunoz_My_Black_Texture}}
	difference
	{
		cylinder {<0,10.35,0>,<0,11.05,0>,.22 }
		cylinder {<0,0,-1>,<0,0,1>,.22 scale <1.6,.75/.22,1> translate <0.18,11.16,0> }
		plane {<0,.23,.9>,0 inverse translate <0,10.3,.21> }
		plane {<0,.23,.9>,0 inverse translate <0,10.3,.21> rotate y*180 }
		texture {FMunoz_My_Black_Texture}
	}
	difference
	{
		cylinder {<0,10.3,0>,<0,11.2,0>,.23 }
		cylinder {<0,10.3,0>,<0,11.3,0>,.2275 }
		plane {<0,.23,.9>,0 inverse translate <0,10.3,.23>  }
		plane {<0,.23,.9>,0 inverse translate <0,10.3,.23> rotate y*180 }
		plane {-x ,0 }
		box {<-.24,10.25,-.0015>,<-.22,11.3,.0015> pigment {NavyBlue}}
		texture {Gold_Texture}
	}
	difference
	{
		sphere {<-.23,11.20,0>.02 }
		box {<-.25,11.0,-.0015>,<-.20,11.4,.0015> pigment {NavyBlue}}
		texture {Gold_Texture}
	}
}

#declare FMunoz_PenCap = union
{
	difference
	{
		union
		{
			cylinder {<0,0,0>,<0,5,0>,.4}
			cylinder {<0,-0.001,0>,<0,0.05,0>,.401 texture {Gold_Texture}}
		}
		cylinder {<0,-.1,0>,<0,5.3,0>,.35}
		texture {FMunoz_My_Black_Texture}
	}
	cone {<0,5,0>,.4, <0,5.1,0>,.3 texture {FMunoz_My_Black_Texture}}
	box {<-.3,4.7,-.25>,<-.5,4.75,.25> texture {Gold_Texture}}
	intersection
	{
		box {<-1,4.55,-.25>,<-.5,4.75,.25>}
		difference
		{
			cylinder {<-.5,4.55,-.25>,<-.5,4.55,.25>,.2}
			cylinder {<-.5,4.55,-.26>,<-.5,4.55,.26>,.15}
		}
		texture {Gold_Texture}
	}
	box {<-.7,4.55,-.25>,<-.65,0.6,.25> texture {Gold_Texture}}
	sphere {<0,0,0>,.26 scale <.8,1,1> translate <-.675,0.6,0> texture {Gold_Texture}}
}

// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_Clock.inc
// Date: 01/98
// Last: 08/07/2008
// Auth: Francisco Munoz, tweaked and prepared by Michael Horvath
// Scale: 1 unit = 1 Cm.
// Based on a real object (Yes, i have one like it)
// Programable .. set the hour, minute and second and
//   it will show the right time (alarm also avalaible)
// Can be bounded in a box : left, bottom, "near <-5,0,-1.6>
//                    right, top, "far" <5,12.75,1.6>


#include "colors.inc"
#include "textures.inc"
#include "stones.inc"

#local G1 = texture {pigment {color Brass} finish {specular .3 reflection .3}}


// Set the time
#ifndef (Hour)
	#local Hour = 1;
#end
#ifndef (Minute)
	#local Minute = 50;
#end
#ifndef (Second)
	#local Second = 33;
#end
#ifndef (Alarm)
	#local Alarm = 11.5;
#end


// Here start the clock
#declare FMunoz_Clock = union
{
	//Felt Base
	box {<-4.95,0,-1.45>,<4.95,0.05,1.45> pigment {Black}}
	union
	{
		box {<-5,0.05,-1.5>,<5,0.55,1.5>}
		box {<-4.95,0.55,-1.45>,<4.95,0.6,1.45>}
		cylinder {<-5,0.05,0>,<-5,0.55,0>,.5 scale <1,1,3>}
		cylinder {<5,0.05,0>,<5,0.55,0>,.5 scale <1,1,3>}
		cylinder {<-4.95,0.55,0>,<-4.95,0.6,0>,.5 scale <1,1,2.9>}
		cylinder {<4.95,0.55,0>,<4.95,0.6,0>,.5 scale <1,1,2.9>}
		texture {G1}
	}
	difference
	{
		union
		{
			box {<-4.75,0.6,-1.25>,<4.75,8,1.25>}
			cylinder {<0,8,-1.25>,<0,8,1.25>,4.75}
			torus {4.75,.5 scale <1,2.5,1> rotate x*90 translate <0,8,0>}
			cylinder {<-4.75,.6,0>,<-4.75,8,0>,.5 scale <1,1,2.5>}
			cylinder {<4.75,.6,0>,<4.75,8,0>,.5 scale <1,1,2.5>}
			texture {pigment {Jade scale 3}}
		}
		union
		{
			cylinder {<0,8,-1.5>,<0,8,-.5>,3 texture {pigment {White} finish {ambient .4}}}
			cylinder {<-2.5,8,1.35>,<-2.5,8,.5>,.25 texture {G1}}
			cylinder {<2.5,8,1.35>,<2.5,8,.5>,.25 texture {G1}}
		}
		texture {pigment {Jade scale 3}}
	}
	
	torus {3,0.15 texture {G1} rotate x*90 translate <0,8,-1.5>}
	torus {3.2,0.15 texture {G1} rotate x*90 translate <0,8,-1.375>}
	torus {3.4,0.15 texture {G1} rotate x*90 translate <0,8,-1.25>}
	cylinder
	{
		<0,8,-1.45>,<0,8,-1.35>,3.1
		pigment {rgbf <.98,.98,.98,.98>}
		finish {specular 1 roughness 0.001 ambient 0 diffuse 0 refraction 1 reflection 0.1 ior 1.5}
	}
	cylinder {<0,8,-.49>,<0,8,-1.04>,.1 pigment {White}}
	cylinder {<0,8,-.55>,<0,8,-.6>,.3 texture {G1}}
	box
	{
		<.05,0,0>,<-.05,2,-.1>
		texture {G1}
		rotate Alarm/12*360*-z
		translate <0,8,-.55>
	}
	union
	{
		cylinder {<0,0,0>,<0,0,-.1>,.25}
		box {<.06,0,0>,<-.06,1.1,-.1>}
		cylinder {<0,1.1,0>,<0,1.1,-.1>,.2}
		prism {linear_sweep 0,.1,4, <-.2,1.1>,<0,1.6>,<.2,1.1>,<-.2,1.1> rotate x*-90}
		texture {pigment {Black}}
		rotate (Hour/12*360*-z)+(Minute/60*30*-z)
		translate <0,8,-.65>
	}
	union
	{
		cylinder {<0,0,0>,<0,0,-.1>,.25}
		box {<.04,0,0>,<-.04,1.5,-.1>}
		cylinder {<0,1.5,0>,<0,1.5,-.1>,.15}
		prism {linear_sweep 0,.1,4,<-.15,1.5>,<0,2.1>,<.15,1.5>,<-.15,1.5> rotate x*-90}
		texture {pigment {Black}}
		rotate Minute/60*360*-z
		translate <0,8,-.85>
	}
	union
	{
		cylinder {<0,0,0>,<0,0,-.1>,.3}
		box {<.02,0,0>,<-.02,2.75,-.1>}
		texture {G1}
		rotate Second/60*360*-z
		translate <0,8,-.95>  //check z rotation to make animations
	}
	union
	{
		#declare Count = 0;
		#while (Count < 12)
			sphere
			{
				<0,2.25,-.5>,.1
				rotate <0,0,Count*30>
				translate <0,8,0>
			}
			#declare Count = Count + 1;
		#end
		torus {2.35,.05 rotate x*90 translate <0,8,-.5>}
		torus {2.15,.05 rotate x*90 translate <0,8,-.5>}
		text
		{
			ttf "Arial.ttf",
			"QUARTZ", 
			.001, 0
			scale <.25,.25,1>
			translate <-.5,7,-.5>
			pigment {Black}
		}
		texture {G1}
	}
	difference
	{
		prism
		{
			linear_sweep 0,.1,9,
			<-3,1.75>,<-2.75,2>,<2.75,2>,<3,1.75>
			<3,.25>,<2.75,0><-2.75,0>,<-3,.25>,<-3,1.75>
			rotate x*-90 translate <0,1.5,-1.25>
			texture {G1}
		}
		text
		{
			ttf "Arial.ttf",
			"HERYCOT S.L.", //This was the Xmas's present from my job place
			.05, 0
			scale <.5,1,1>
			translate <-1.75,2.25,-1.36>
			texture {G1}
		}
	}
	difference
	{
		union
		{
			torus {3.4,0.15 rotate x*90 translate <0,8,1.25>}
			cylinder {<0,8,1.2>,<0,8,1.3>,3.4}
			box {<-2,7,1.2>,<2,6,1.35>}
			text
			{
				ttf "Arial.ttf",
				"PATENT PENDING", 
				.05, 0
				scale <.25,.25,1>
				rotate y*180
				translate <1.75,7.25,1.34>
			}
		}
		union
		{
			cone {<-.5,9,1.26>,.8,<-.5,9,1.32>,1.2}
			cylinder {<-2.5,8,1.35>,<-2.5,8,1>,.25}
			cylinder {<2.5,8,1.35>,<2.5,8,1>,.25}
		}
		texture {G1}
	}
	cylinder {<-.5,9,1.20><-.5,9,1.3>,.175 pigment {Black}}
	cylinder {<-.5,9,1.3><-.5,9,1.35>,.225 pigment {Black}}
	difference
	{
		sphere {<-2.5,8,.75>,.25}
		box {<-2.25,8.05,.75>,<-2.75,7.95,1.1>}
		box {<-2.45,8.25,.75>,<-2.55,7.75,1.1>}
		pigment {Black}
	}
	difference
	{
		sphere {<2.5,8,.75>,.25}
		box {<2.25,8.05,.75>,<2.75,7.95,1.1>}
		box {<2.45,8.25,.75>,<2.55,7.75,1.1>}
		pigment {Black}
	}
}

// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_CigarBox.inc
// Date: 01/1998
// Last: 07/08/2008
// Auth: Francisco Munoz, tweaked and prepared by Michael Horvath
// Scale: 1 unit = 1 Cm.
// (no, this time i have none itme like this
// An ink dryer (not sure about name in english
//      but render it and you'll see it;)
// Along z axis (base at z=0)
//  Can be bounded box of left, bottom, "far" <-5,0,10>
//                    right, top, "near" <5,4,0>


#include "colors.inc"
#include "textures.inc"
#include "woods.inc"

#declare CBCoverAngle = 45;	//From 0 to 190
#declare CBLockangle = 170;	//From 0 to 170


#if ((CBCoverAngle > 190)|(CBCoverAngle < 0)) #declare CBCoverAngle = 90; #end
#if ((CBLockangle  > 170)|(CBLockangle  < 0)) #declare CBLockangle =  90; #end

#local G1 = texture {pigment {color Brass} finish {specular .3 reflection .3 phong 10 phong_size 100}}
#local BoxWood = texture {T_Wood6 finish {reflection .1 roughness .001}}
#local Cigar_Box_Main = union
{
	sphere {<-9.25,.5,4.25>,.5 texture {G1}}
	cylinder {<-9.25,.75,4.25>,<-9.25,1,4.25>,.5 texture {G1}}
	sphere {<9.25,.5,4.25>,.5 texture {G1}}
	cylinder {<9.25,.75,4.25>,<9.25,1,4.25>,.5 texture {G1}}
	sphere {<-9.25,.5,-4.25>,.5 texture {G1}}
	cylinder {<-9.25,.75,-4.25>,<-9.25,1,-4.25>,.5 texture {G1}}
	sphere {<9.25,.5,-4.25>,.5 texture {G1}}
	cylinder {<9.5,.75,-4.5>,<9.25,1,-4.25>,.5 texture {G1}}
	box {<-10,1,-5>,<10,1.5,5> texture {BoxWood rotate <0,90,0> scale 10}}
	box {<-10,1.5,5>,<10,5,4.5> texture {BoxWood rotate <0,92,0> scale 10}}
	box {<-10,1.5,-5>,<10,5,-4.5> texture {BoxWood rotate <0,89,0> scale 10}}
	box {<10,1.5,4.5>,<9.5,5,-4.5> texture {BoxWood rotate <0,0,0> scale 10}}
	box {<-10,1.5,4.5>,<-9.5,5,-4.5> texture {BoxWood rotate <0,0,0> scale 10}}
	box {<5,1.5,4.5>,<5.5,5,-4.5> texture {BoxWood rotate <0,0,0> scale 10}}
	box {<5.55,1.5,4.5>,<5.5,4.9,-4.5> texture {pigment {ForestGreen}}}
	box {<9.45,1.5,4.5>,<9.5,4.9,-4.5> texture {pigment {ForestGreen}}}
	box {<5.5,1.5,4.5>,<9.5,1.55,-4.5> texture {pigment {ForestGreen}}}
	box {<5.5,1.5,4.45>,<9.5,4.9,4.5> texture {pigment {ForestGreen}}}
	box {<5.5,1.5,-4.45>,<9.5,4.9,-4.5> texture {pigment {ForestGreen}}}
	cylinder {<6,4.9,5>,<7.5,4.9,5.1>,.1 texture {G1}}
	box {<6,4.95,4.49>,<7.5,5.05,5.01> texture {G1}}
	cylinder {<-6,4.9,5>,<-7.5,4.9,5.1>,.1 texture {G1}}
	box {<-6,4.95,4.49>,<-7.5,5.05,5.01> texture {G1}}
	prism
	{
		linear_sweep 0,.1,7
		<-2,1.5>,<2,1.5>,<2,.5>,<1.5,0>,<-1.5,0>,<-2,.5>,<-2,1.5>
		texture {G1}
		rotate x*-90 translate <0,3.5,-5>
	}
	sphere {<0,4.5,-5.3>,0.2 texture {G1}}
	cylinder {<0,4.5,-5>,<0,4.5,-5.3>,0.18 texture {G1}}
}
#local Box_Cover = union
{
	box {<-10,1,-10>,<10,1.5,0> texture {BoxWood rotate <0,90,0> scale 10}}
	box {<-10,0,0>,<10,1,-.5> texture {BoxWood rotate <0,91,0> scale 10}}
	box {<-10,0,-10>,<10,1,-9.5> texture {BoxWood rotate <0,88,0> scale 10}}
	box {<10,0,-.5>,<9.5,1,-9.5> texture {BoxWood rotate <1,0,0> scale 10}}
	box {<-10,0,-.5>,<-9.5,1,-9.5> texture {BoxWood rotate <0,0,1> scale 10}}
	intersection
	{
		box {<-10,1.5,-10>,<10,2.5,0>}
		cylinder {<-10,0,-5>,<10,0,-5>,5
		scale <1,.2,1> translate y*1.5}
		cylinder {<0,1.5,0>,<0,1.5,-10>,10
		scale <1,.1,1> translate y*1.5}
		texture {BoxWood rotate <1,90,0> scale 10}
	}
	box {<6,-.05,-.51>,<7.5,.05,0.01> texture {G1}}
	box {<-6,-.05,-.51>,<-7.5,.05,0.01> texture {G1}}
	prism
	{
		linear_sweep 0,.1,7
		<-2,0.05>,<-2,.5>,<-1.5,1>,<1.5,1>,
		<2,.5>,<2,0.05>,<-2,0.05>
		texture {G1}
		rotate x*-90 translate <0,0,-10>
	}
	cylinder {<-.5,1,-10.15>,<.5,1,-10.15>,.1 texture {G1}}
	cylinder {<-1.51,1,-10.15>,<1.51,1,-10.15>,.05 texture {G1}}
	cylinder {<-1.5,1,-10.15>,<-.55,1,-10.15>,.1 texture {G1}}
	cylinder {<1.5,1,-10.15>,<.55,1,-10.15>,.1 texture {G1}}
	union
	{
		cylinder {<-1.5,-2,0>,<1.5,-2,0>,.1 texture {G1}}
		difference
		{
			box {<-.56,-2,0>,<.56,-.5,-.05> texture {G1}}
			cylinder {<0,-1.5,-1>,<0,-1.5,0.1>,.21 texture {G1}}
		}
		box {<-1.45,-2,0>,<-.55,0,-.05> texture {G1}}
		box {<1.45,-2,0>,<.55,0,-.05> texture {G1}}
		rotate CBLockangle * x
		translate <0,1,-10.15>
	}
}

#declare FMunoz_CigarBox = union
{
	object {Cigar_Box_Main}
	object {Box_Cover rotate x * CBCoverAngle translate <0,5,5>}
}
