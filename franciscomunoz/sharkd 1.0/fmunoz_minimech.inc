// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_MiniMech.inc
// Desc: A robot warrior.
// Date: Nov-Dec 1997
// Last: 09/07/2008
// Auth: Francisco Munoz Cotobal, tweaked and prepared by Michael Horvath


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
// Textures

// Semi-arid theatre
#declare FMunoz_Mech_Texture1 = texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color DarkGreen]
			[0.55 color DarkGreen]
			[0.57 color rgb <0.45,0.25,0.20>]
			[1.00 color rgb <0.45,0.25,0.20>]
		}
	}
	scale 1.5
}
/*
texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color Clear]
			[0.70 color Clear]
			[0.71 color rgb <0.7,0.5,0.2>]
			[1.00 color rgb <0.7,0.5,0.2>]
		}
	}
	scale 1.5
	rotate 45
}
*/
// European/Woods theatre
#declare FMunoz_Mech_Texture2 = texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color DarkGreen]
			[0.55 color DarkGreen]
			[0.57 color rgb <0.45,0.25,0.20>]
			[1.00 color rgb <0.45,0.25,0.20>]
		}
	}
	scale 1.5
}
/*
texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color Clear]
			[0.70 color Clear]
			[0.71 color rgb <0.2,0.2,0.2>]
			[1.00 color rgb <0.19,0.18,0.18>]
		}
	}
	scale 1.5
	rotate 45
}
*/
// Desert theatre
#declare FMunoz_Mech_Texture3 = texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color rgb <0.7,0.5,0.2>]
			[0.65 color rgb <0.7,0.5,0.2>]
			[0.67 color DarkGreen]
			[1.00 color DarkGreen]
		}
	}
	scale 1.5
}
/*
texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color Clear]
			[0.75 color Clear]
			[0.76 color rgb <0.45,0.25,0.20>]
			[1.00 color rgb <0.45,0.25,0.20>]
		}
	}
	scale 1.5
	rotate 45
}
*/
// Snow theatre
#declare FMunoz_Mech_Texture4 = texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color rgb <1,1,1>]
			[0.75 color rgb <1,1,1>]
			[0.76 color rgb <0.39,0.50,0.39>]
			[1.00 color rgb <0.39,0.50,0.39>]
		}
	}
	scale 1.5
}
/*
texture
{
	pigment
	{
		bozo
		turbulence .025
		color_map
		{
			[0.00 color Clear]
			[0.80 color Clear]
			[0.81 color rgb <0.55,0.45,0.40>]
			[1.00 color rgb <0.55,0.45,0.40>]
		}
	}
	scale 1.5
	rotate 45
}
*/
// Fancy quasiorganic Red/White texture
#declare FMunoz_Mech_Texture5 = texture
{
	pigment
	{
		bozo
		pigment_map
		{
			[.0 color White]
			[.1 color rgb <1,.5,.5>]
			[.18 color Red]
			[.45 color Red]
			[.65 color rgb <.5,0,0>]
			[.85 color rgb <.3,0,0>]
			[.9 color Black]
		}
		triangle_wave
		scale .5
	}
	normal {bumps 1 scale .2}
}

#declare FMunoz_Barrel_Texture = texture
{
	pigment{ color rgb <0.60,0.61,0.68>}
	finish
	{
		metallic
		ambient 0.2
		diffuse 0.7
		brilliance 6
		reflection 0.25
		phong 0.75
		phong_size 80
	}
}

#declare FMunoz_Barrel_Texture2 = texture
{
	pigment{ color rgb <0.15,0.155,0.17>}
	finish
	{
		metallic
		ambient 0.2
		diffuse 0.7
		brilliance 6
		reflection 0.1
		phong 0.65
		phong_size 65
	}
}

#declare FMunoz_Focus_Glass = texture
{
	pigment
	{
		gradient x
		color_map
		{
			[0.000 rgbf <0.0, 0.0, 0.0, 0.0>]
			[0.020 rgbf <0.2, 0.2, 0.2, 0.0>]
			[0.050 rgbf <0.98, 0.98, 0.98, 0.9>]
			[0.950 rgbf <0.98, 0.98, 0.98, 0.9>]
			[0.970 rgbf <0.2, 0.2, 0.2, 0.0>]
			[1.000 rgbf <0.0, 0.0, 0.0, 0.0>]
		}
		scale .1
	}
	finish
	{
		ambient 0.1
		diffuse 0.1
		reflection 0.1
		refraction 0.9
		ior 1.45
		specular 0.8
		roughness 0.0003
		phong 1
		phong_size 400
	}
}

#declare FMunoz_MainTexture = texture {FMunoz_Mech_Texture3}

// ----------------- Motion -----------------------

// Faster render
#ifndef (FMunoz_Turbo)			#declare FMunoz_Turbo = 0; #end
// 0=Off , 1 =On     Feet's rockets
#ifndef (FMunoz_Rockets)		#declare FMunoz_Rockets = 0; #end


// ------------ Some modular custom changes --- Kits de implementos para su mech ---

// 0=Standar , 1 = With guns
#ifndef (FMunoz_HeadModel)		#declare FMunoz_HeadModel = 1; #end
// 0=Lights , 1 = Missiles  Shoulder racket
#ifndef (FMunoz_Shouders)		#declare FMunoz_Shoulders = 1; #end
// 0 = Gatling Gun, 1 = Heavy Gun
#ifndef (FMunoz_RightHandWeapon)	#declare FMunoz_RightHandWeapon = 1; #end
// 0 = Gatling Gun, 1 = Heavy Gun
#ifndef (FMunoz_LeftHandWeapon)		#declare FMunoz_LeftHandWeapon = 0; #end


// -------------- XXXXXXXXXXX --- Medidas --- This must be included ----

#declare FMunoz_lenghtupperarmD =	4.125;
#declare FMunoz_lenghtpantorrI =	5.75;
#declare FMunoz_lenghtpantorrD =	5.75;
#declare FMunoz_heightfootL =		1.75;
#declare FMunoz_heightfootR =		1.75;
#declare FMunoz_widetorso =		9;
#declare FMunoz_widebelly =		4.5;		//not true but needed for good legs' positioning
#declare FMunoz_heightbelly =		2.75;


// ----------- Let's vogue --- Posturitas ;-) -----

//Articulaciones
#declare FMunoz_girXhead =		0;
#declare FMunoz_girYhead =		-25;
#declare FMunoz_girZhead =		0;

#declare FMunoz_girXtorso =		0;
#declare FMunoz_girYtorso =		0;
#declare FMunoz_girZtorso =		0;

#declare FMunoz_girXupperarmD =		-165;
#declare FMunoz_girYupperarmD =		-40;
#declare FMunoz_girZupperarmD =		0;

#declare FMunoz_girXarmD =		70;
#declare FMunoz_girYarmD =		0;
#declare FMunoz_girZarmD =		0;

#declare FMunoz_girXupperarmI =		-100;
#declare FMunoz_girYupperarmI =		0;
#declare FMunoz_girZupperarmI =		-15;

#declare FMunoz_girXarmI =		55;
#declare FMunoz_girYarmI =		-10;
#declare FMunoz_girZarmI =		0;

#declare FMunoz_girXmusloD =		5;
#declare FMunoz_girYmusloD =		-10;
#declare FMunoz_girZmusloD =		0;

#declare FMunoz_girXmusloI =		5;
#declare FMunoz_girYmusloI =		10;
#declare FMunoz_girZmusloI =		0;

#declare FMunoz_girXpantorrD =		-10;
#declare FMunoz_girXpantorrI =		-10;

#declare FMunoz_flatfootR =		yes;
#declare FMunoz_flatfootL =		yes;


// ---------------------

#if (FMunoz_Turbo = 1)
	#declare FMunoz_MainTexture =		texture {pigment {Yellow}}
	#declare FMunoz_Barrel_Texture =	texture {pigment {White}}
	#declare FMunoz_Barrel_Texture2 =	texture {pigment {Black}}
	#debug "\nTHE TURBO MODE ON!!!!  Textures will be very different in normal mode.\n"
	#debug "THE TURBO MODE ON!!!!  Check vogue.in to change\n\n"
#end
#if (FMunoz_Rockets = 1)
	#debug "\nROCKET PROPULSOR are ON, beware the halos inside them"
	#debug "\n slow down the render a lot"
#end


// ----------------- Pieces -----------------------

// *****HEAD*****
#declare FMunoz_head = union
{  
	#if (FMunoz_HeadModel = 0)
		difference
		{
			union
			{
				sphere {0,.75}
				sphere {<0,1,0>,.75}
				cone {<0,0,0>,.75,<0,1,0>,.75}
				sphere {<0,.25,2>,1}
				sphere {<0,1.25,2>,1}
				cone {<0,.25,2>,1,<0,1.25,2>,1}
				cone {<0,0,0>,.75,<0,.25,2>,1}
				cone {<0,1,0>,.75,<0,1.25,2>,1}
			}
			box {<1,1,-5>,<-1,.5,1.5>}
		}
		merge
		{
			box {<-.5,1,0>,<.5,.5,1.5>}
			cylinder {<0,.5,0>,<0,1,0>,.5}
			pigment {color rgbf <0,.80,.10,.80>}
		}
		union
		{
			sphere {<0,.875,2>,.45 scale <.75,1,1> translate x*-1}
			sphere {<0,.875,2>,.45 scale <.75,1,1> translate x*1}
			box {<-1,.875,1.9>,<-1.20,2.5,2.1>}
			box {<1,.875,1.9>,<1.20,2.5,2.1>}
			texture {FMunoz_Barrel_Texture2}
		}
		cylinder {<0,-1.5,1.75>,<0,0,1.75>,.65 texture {FMunoz_Barrel_Texture2}}
	#else
		difference
		{
			union
			{
				sphere {0,.75}
				sphere {<0,1,0>,.75}
				cone {<0,0,0>,.75,<0,1,0>,.75}
				sphere {<0,.25,2>,1}
				sphere {<0,1.25,2>,1}
				cone {<0,.25,2>,1,<0,1.25,2>,1}
				cone {<0,0,0>,.75,<0,.25,2>,1}
				cone {<0,1,0>,.75,<0,1.25,2>,1}
				cylinder {<.6,.875,2>,<.6,.875,-.5>,.4}
				triangle {<-.75,1,0>,<-.75,0,0>,<-1,1.25,2>}	//  This is not a very good solution but it works
				triangle {<-1,.25,2>,<-.75,0,0>,<-1,1.25,2>}	//  Ignore the warning
				#debug "\n Ignore the warning \n"
				cylinder {<.5,.2,0>,<.5,.2,-.65>,.2}
				cylinder {<-.5,.2,0>,<-.5,.2,-.65>,.2}
				cylinder {<-.5,.65,0>,<-.5,.65,-.65>,.2}
				cylinder {<-.5,1.1,0>,<-.5,1.1,-.65>,.2}
			}
			cylinder {<.65,.875,-.6>,<.65,.875,-.77>,.35 texture {FMunoz_Barrel_Texture2}}
		}
		union
		{
			sphere {<0,.875,2>,.45 scale <.75,1,1> translate x*-1}
			sphere {<0,.875,2>,.45 scale <.75,1,1> translate x*1}
			box {<-1,.875,1.9>,<-1.20,2.5,2.1>}
			box {<1,.875,1.9>,<1.20,2.5,2.1>}
			texture {FMunoz_Barrel_Texture2}
		}
		difference
		{
			union
			{
				cylinder {<.5,.2,-.6>,<.5,.2,-.77>,.15}
				cylinder {<-.5,.2,-.6>,<-.5,.2,-.77>,.15}
				cylinder {<-.5,.65,-.6>,<-.5,.65,-.77>,.15}
				cylinder {<-.5,1.1,-.6>,<-.5,1.1,-.77>,.15}
				texture {FMunoz_Barrel_Texture}
			}
			union
			{
				cylinder {<.5,.2,-.651>,<.5,.2,-.78>,.1}
				cylinder {<-.5,.2,-.651>,<-.5,.2,-.78>,.1}
				cylinder {<-.5,.65,-.651>,<-.5,.65,-.78>,.1}
				cylinder {<-.5,1.1,-.651>,<-.5,1.1,-.78>,.1}
				texture {FMunoz_Barrel_Texture2}
			}
		}
		difference
		{
			cylinder {<.65,.875,-.5>,<.65,.875,-.75>,.38}
			cylinder {<.65,.875,-.6>,<.65,.875,-.77>,.35}
			texture {FMunoz_Barrel_Texture2}
		}
		cylinder {<.65,.875,-.65>,<.65,.875,-.73>,.35	pigment {color rgbf <1,0,0,.75>}}
		box {<.67,1.225,-.731>,<.63,.525,-.65>		pigment {Black}}
		box {<.3,.855,-.731>,<.95,.895,-.65>		pigment {Black}}
		cylinder {<0,-1.5,1.75>,<0,0,1.75>,.65		texture {FMunoz_Barrel_Texture2}}
	#end
	translate <0,1,-1.75>
	scale .85
}

#declare FMunoz_Fire = sphere
{
	0, 1 hollow
	texture
	{
		pigment {colour Clear}
// Needs to be converted to interior
//		halo
//		{
//			cubic
//			max_value 3 spherical_mapping glowing
//			colour_map {[0 color rgbt <1,0,0,1>][1 color rgbt <1,1,0,0>]}
//			turbulence 1.5 samples 30
//		}
//		halo
//		{
//			cubic
//			max_value 3 spherical_mapping glowing
//			colour_map {[0 color rgbt <1,0,0,1>][1 color rgbt <1,1,0,0>]}
//			turbulence 1.05 samples 30 scale .5
//			rotate  y*45 translate y*1
//		}
	}
}

//  ***** Weapon *****
#declare FMunoz_Gatling = union
{
	#declare FMunoz_Count = 0;
	#while (FMunoz_Count < 11)
		difference
		{
			cylinder {<-1,.9,0>,<-15,.9,0>,.20 rotate FMunoz_Count*x*36 texture {FMunoz_Barrel_Texture}}
			cylinder {<-2,.9,0>,<-16,.9,0>,.19 rotate FMunoz_Count*x*36 texture {FMunoz_Barrel_Texture2}}
		}
		#declare FMunoz_Count = FMunoz_Count + 1;
	#end
	cone {<-1.25,0,0>,1.5,<-.75,0,0>,1 }
	cylinder {<-3,0,0>,<-1.25,0,0>,1.5 }
	cylinder {<-4.5,0,0>,<-4.75,0,0>,1.75	texture {FMunoz_Barrel_Texture2}}
	cylinder {<-3,0,0>,<-5,0,0>,1.5		texture {FMunoz_Barrel_Texture2}}
	cylinder {<-8.875,0,0>,<-9.125,0,0>,1.5	texture {FMunoz_Barrel_Texture2}}
	cylinder {<-13,0,0>,<-13.25,0,0>,1.5	texture {FMunoz_Barrel_Texture2}}
	cylinder {<-1,0,0>,<-13.26,0,0>,.20	texture {FMunoz_Barrel_Texture}}	//Barrels' Axis
	sphere {<-13.26,0,0>,.20		texture {FMunoz_Barrel_Texture2}}
	sphere {0,1				texture {FMunoz_Barrel_Texture2}}
	scale .5
	rotate z*-90
}

//  ***** Weapon *****
#declare FMunoz_BigGun = union
{
	sphere {0,.5						texture {FMunoz_Barrel_Texture2}}
	cylinder {<0,0,0>,<0,-1.5,0>,.4				texture {FMunoz_Barrel_Texture2}}
	box {<-.45,-1,.65>,<.45,-5,-1.05>}
	cylinder {<0,-1,-1.05>,<0,-5,-1.05>,.45}
	cylinder {<0,-1,0>,<0,-5,0>,.45 scale <1,1,.35> translate <0,0,.65>}
	cone {<0,-.625,0>,.65,<0,-.45,0>,.5}
	cylinder {<0,-2.25,0>,<0,-.625,0>,.65}
	sphere {<0,-2.25,0>,.65}
	box {<-.05,-5.4,.53><.05,-4.5,.60>			texture {FMunoz_Barrel_Texture}}
	box {<-.05,-5.5,.53><.05,-5.35,.65>			texture {FMunoz_Barrel_Texture}}
	difference
	{
		cylinder {<0,-5.5,.25>,<0,-4.499,.25>,.3	texture {FMunoz_Barrel_Texture}}
		cylinder {<0,-5.6,.25>,<0,-4.499,.25>,.2	texture {FMunoz_Barrel_Texture2}}
	}
	difference
	{
		cylinder {<0,-5.5,-.45>,<0,-4.499,-.45>,.2	texture {FMunoz_Barrel_Texture}}
		cylinder {<0,-5.6,-.45>,<0,-4.499,-.45>,.13	texture {FMunoz_Barrel_Texture2}}
	}
	rotate z*180
}

#declare FMunoz_forearmL = object
{
	#if (FMunoz_LeftHandWeapon = 0)
		FMunoz_Gatling
	#else
		FMunoz_BigGun
	#end
}

#declare FMunoz_forearmR = object
{
	#if (FMunoz_RightHandWeapon = 0)
		FMunoz_Gatling
	#else
		FMunoz_BigGun
	#end
}

// there is no need for hands now
#declare FMunoz_handL = difference
{ 
	sphere {0,.5}
	sphere {0,1}
}

// there is no need for hands now
#declare FMunoz_handR = difference
{
	sphere {0,.5}
	sphere {0,1}
}

// ****** CHEST ******
#declare FMunoz_torso = union
{
	cylinder {<0,-1.5,0>,<0,2.5,0>,1.25 scale <1,1,.8>						texture{FMunoz_Barrel_Texture2}}
	superellipsoid {<.5,.5> scale <3.75,1.5,1.35> translate <0,3.75,0>}
	#declare FMunoz_Count = 0;
	#while (FMunoz_Count < 18)
		cylinder {<0,-1.5+FMunoz_Count*.25,0>,<0,-1.35+FMunoz_Count*.25,0>,1.3 scale <1,1,.8>	texture{FMunoz_Barrel_Texture}}
		#declare FMunoz_Count = FMunoz_Count + 1;
	#end
	difference
	{
		union
		{
			cone {<0,1.25,0>,1.7 <0,4.75,0>,2.75 scale <1,1,.8>}
			cone {<0,4.75,0>,2.75 <0,5,0>,2 scale <1,1,.8>}
		}
		plane {z,-1.8}
		plane {z,-1.75 rotate y*180}
		sphere {0,1.9 scale <1,1,1> translate <0,.8,-1.1>}
	}
	union
	{
		difference
		{
			union
			{
				cylinder {<-2.9,5.5,-1.5>,<-2.9,5.5,1.5>,.5}
				cylinder {<-1.5,5.5,-1.5>,<-1.5,5.5,1.5>,.5}
				box {<-3,6,-1.50>,<-1.5,5,1.5>}
				sphere {<-2.9,5.5,1.5>,.5 }
				sphere {<-1.5,5.5,1.5>,.5 }
				cylinder {<-2.9,5.5,1.5>,<-1.5,5.5,1.5>,.5}
				cylinder {<-2.8,5.5,-1.6>,<-2.8,5.5,0>,.45	texture {FMunoz_Barrel_Texture2}}
				cylinder {<-1.6,5.5,-1.6>,<-1.6,5.5,0>,.42	texture {FMunoz_Barrel_Texture2}}
			}
			#if (FMunoz_Shoulders = 0)
				sphere {<-2.8,5.5,-1.6>,.43			texture {pigment {White} finish {reflection .8}}}
				sphere {<-1.6,5.5,-1.6>,.40			texture {pigment {White} finish {reflection .8}}}
			#else
				cylinder {<-2.8,5.5,-2.6>,<-2.8,5.5,1>,.40	texture {FMunoz_Barrel_Texture2}}
				cylinder {<-1.6,5.5,-2.6>,<-1.6,5.5,1>,.37	texture {FMunoz_Barrel_Texture2}}
			#end
		}
		#if (FMunoz_Shoulders = 0)
			sphere
			{
				<0,0,0>,.43
				texture {FMunoz_Focus_Glass}
				scale <1,1,.25>
				translate <-2.8,5.5,-1.6>
			}
			sphere
			{
				<0,0,0>,.40
				texture {pigment {rgbf <1,0,0,1>}}
				texture {FMunoz_Focus_Glass}
				scale <1,1,.25>
				translate <-1.6,5.5,-1.6>
			}
		#else
			sphere
			{
				<0,0,0>,.40
				texture {pigment {White}}
				scale <1,1,3>
				translate <-2.8,5.5,-.75>
			}
			sphere
			{
				<0,0,0>,.37
				texture {pigment {White}}
				scale <1,1,3>
				translate <-1.6,5.5,-.75>
			}
		#end
	}
	union
	{
		difference
		{
			union
			{
				cylinder {<2.9,5.5,-1.5>,<2.9,5.5,1.5>,.5}
				cylinder {<1.5,5.5,-1.5>,<1.5,5.5,1.5>,.5}
				box {<3,6,-1.50>,<1.5,5,1.5>}
				sphere {<2.9,5.5,1.5>,.5 }
				sphere {<1.5,5.5,1.5>,.5 }
				cylinder {<2.9,5.5,1.5>,<1.5,5.5,1.5>,.5}
				cylinder {<2.8,5.5,-1.6>,<2.8,5.5,0>,.45	texture {FMunoz_Barrel_Texture2}}
				cylinder {<1.6,5.5,-1.6>,<1.6,5.5,0>,.42	texture {FMunoz_Barrel_Texture2}}
			}
			#if (FMunoz_Shoulders = 0)
				sphere {<2.8,5.5,-1.6>,.43			texture {pigment {White} finish {reflection .8}}}
				sphere {<1.6,5.5,-1.6>,.40			texture {pigment {White} finish {reflection .8}}}
			#else
				cylinder {<2.8,5.5,-2.6>,<2.8,5.5,1>,.40	texture {FMunoz_Barrel_Texture2}}
				cylinder {<1.6,5.5,-2.6>,<1.6,5.5,1>,.37	texture {FMunoz_Barrel_Texture2}}
			#end
		}
		#if (FMunoz_Shoulders = 0)
			sphere
			{
				<0,0,0>,.43
				texture {FMunoz_Focus_Glass}
				scale <1,1,.25>
				translate <2.8,5.5,-1.6>
			}
			sphere
			{
				<0,0,0>,.40
				texture {pigment {rgbf <0,0,1,1>}}
				texture {FMunoz_Focus_Glass}
				scale <1,1,.25>
				translate <1.6,5.5,-1.6>
			}
		#else
			sphere
			{
				<0,0,0>,.40
				texture {pigment {White}}
				scale <1,1,3>
				translate <2.8,5.5,-.75>
			}
			sphere
			{
				<0,0,0>,.37
				texture {pigment {White}}
				scale <1,1,3>
				translate <1.6,5.5,-.75>
			}
		#end
	}
	box {<-1,2.45,1.65>,<1,6.05,2.25> texture {FMunoz_Barrel_Texture2}}
	superellipsoid {<.5,.5> scale <.85,1.75,.6> translate <0,4.25,2.25>}
	// left Wing
	difference
	{
		box {<-11,-3.5,-.15>,<0,5.75,.15>}
		plane {<6.25,-11,0>,0 inverse translate y*3.5}
		// hard work remembering Calculus classes ;-)
		plane {<7,-11,0>,0  translate y*6.25}
		rotate y*45
		translate <-1,0,1.95>
	}
	// Right Wing
	difference
	{
		box {<-11,-3.5,-.15>,<0,5.75,.15>}
		plane {<6.25,-11,0>,0 inverse translate y*3.5}
		// hard work renembering Calculus classes ;-)
		plane {<7,-11,0>,0  translate y*6.25}
		rotate y*135
		translate <1,0,1.95>
	}
}

// *********** BELLY *****
#declare FMunoz_belly = union
{  
	difference
	{
		cylinder {<0,.5,0>,<0,-3/2,0>,2 scale <1,1,.75>}
		sphere {0,1.9 scale <1,1,1> translate <0,.8,-1.1>}
	}
	sphere {<0,0,0>,2 scale <1,.75,.75> translate <0,-1.5,0>}
	sphere {<0,0,0>,2 scale <1,.75,.75> translate <0,-1.5,0>}
	intersection
	{
		cylinder {<0,.5,0>,<0,-3/2,0>,1.8 scale <1,1,.75>}
		cylinder {<0,-.5,-2>,<0,-.5,2>, 1 scale <1.6,1,1>}
	}
	cone {<-2.2,-1.25,0>,.75,<-1.9,-1.25,0>,1}
	cone {<2.2,-1.25,0>,.75,<1.9,-1.25,0>,1}
}

#declare FMunoz_pantorrD = union
{
	sphere {<0,0,0>,.5				texture {FMunoz_Barrel_Texture2}}
	cylinder {<0,0,0>,<0,-1,0>,.4			texture {FMunoz_Barrel_Texture2}}
	difference
	{
		cone {<0,.3,0>,.8,<0,-4.75,0>,1.25}
		sphere {<0,0,.2>,.8 scale <2,1,1>}
	}
	difference
	{
		sphere {<0,-4.75,0>,1.25}
		cylinder {<0,-4.75,1.5>,<0,-4.75,-1.5>,1}
		plane {z,-.25}
		plane {z,.25 inverse}
	}
	cylinder {<-.25,-4.70,0>,<-.25,-5.75,0>,.1	texture {FMunoz_Barrel_Texture2}}
	cylinder {<.2,-4.70,0>,<.2,-5.75,0>,.075	texture {FMunoz_Barrel_Texture2}}
}

#declare FMunoz_pantorrI = object {FMunoz_pantorrD}

#declare FMunoz_shoulderpadR = difference
{
	union
	{
		superellipsoid {<1,.35> scale .9 rotate y*90}
		sphere {<-1,0,0>, .45 texture {FMunoz_Barrel_Texture2}}
	}
	cylinder {<0,-1.1,-2>,<0,-1,2>,.75}
	texture {FMunoz_MainTexture}
	scale 1.5
	rotate x*180
}

#declare FMunoz_shoulderpadL = object {FMunoz_shoulderpadR rotate y*180}

#declare FMunoz_upperarmL = union
{
	sphere {0,.5 scale <1,2.25,.8> translate <0,-1.1,-.35>}
	sphere {0,.5 scale <1,2.25,.8> translate <0,-1.1,.35>}
	sphere {<0,-2.25,0>,.5 texture{FMunoz_Barrel_Texture2}}
	scale 1.5
	rotate x*180
	texture {FMunoz_MainTexture}
}

#declare FMunoz_upperarmR = object {FMunoz_upperarmL rotate y*180}

#declare FMunoz_footL = union
{
	difference
	{
		union
		{
			difference
			{
				sphere {0,1 scale <1,2.75,1> rotate x*40 translate <0,-1.5,-1.5>}
				plane {y,-1.5}
			}
			difference
			{
				sphere {0,1.1 scale <1,2.75,1> rotate x*40 translate <0,-1.5,-1.5>}
				plane {y,-1.75}
				plane {y,-1.5 inverse}
				#declare FMunoz_Count = 0;
				#while (FMunoz_Count < 15)
					box {<-1.5,.1,.1>,<1.5,-.1,-.1> rotate x*45 translate <0,-1.75,.5-FMunoz_Count*.25>}
					#declare FMunoz_Count = FMunoz_Count +1 ;
				#end
			}
		}
		sphere {<0,-1.75,-1.75>,.5 texture {FMunoz_Barrel_Texture2}}
		texture {FMunoz_Barrel_Texture2}
	}
	difference
	{
		union
		{
			difference
			{
				sphere {0,1 scale <.75,2,.65> rotate x*-25 translate <0,-1.25,.85>}
				plane {y,-1.5}
			}
			difference
			{
				sphere {0,1.1 scale <.75,2,.65> rotate x*-25 translate <0,-1.25,.85>}
				plane {y,-1.75}
				plane {y,-1.5 inverse}
				#declare FMunoz_Count = 0;
				#while (FMunoz_Count < 10)
					box {<-2.5,.1,.1>,<2.5,-.1,-.1> rotate x*45 translate <0,-1.75,-.5+FMunoz_Count*.25>}
					#declare FMunoz_Count = FMunoz_Count + 1;
				#end
			}
		}
		sphere {<0,-1.75,1>,.35 texture {FMunoz_Barrel_Texture2}}
		texture {FMunoz_Barrel_Texture2}
	}
	#if (FMunoz_Rockets = 1)
		object {FMunoz_Fire scale <.6,.8,.6> translate <0,-2.6,1>}
		object {FMunoz_Fire scale <.75,1,.75> translate <0,-2.7,-1.75>}
	#end
}

#declare FMunoz_footR = object {FMunoz_footL}

#declare FMunoz_musloI = union
{
	sphere {<0,0,0>,.85 scale <1,1.25,1> }
	sphere {<0,0,0>,1.1 scale <.5,1.85,.5> translate <-.35,-1.85,-.3>}
	sphere {<0,0,0>,1.1 scale <.5,1.75,.5> translate <.35,-1.85,-.3>}
	sphere {<0,0,0>,1.1 scale <.75,1.75,.55> translate <0,-1.75,.25>}
	sphere {<0,0,0>,1 scale <.3,1,.35> translate <0,-3.75,-.25>	texture {FMunoz_Barrel_Texture2}}
	cylinder {<0,0,0>,<0,-4.65,0>,.4				texture {FMunoz_Barrel_Texture2}}
	cylinder {<-.28,-3,.28>,<-.21,-4.65,.21>,.15}
	cylinder {<.28,-3,.28>,<.21,-4.65,.21>,.15}
}

#declare FMunoz_musloD = object {FMunoz_musloI}


// ----------------------------------------
// The model

#include "FMunoz_Homid.inc"

// adding shoulderpads & some small changes
#declare FMunoz_MiniMech_Object = union
{
	// to the basic homid figure
	object {FMunoz_Homid_Base}
	object
	{
		FMunoz_shoulderpadL
		rotate <FMunoz_girXupperarmD,FMunoz_girYtorso,FMunoz_girZtorso>
		translate FMunoz_poshombroD
	}
	object
	{
		FMunoz_shoulderpadR
		rotate <FMunoz_girXupperarmI,FMunoz_girYtorso,FMunoz_girZtorso>
		translate FMunoz_poshombroI
	}
	#if (FMunoz_Rockets = 0)
		translate <0,-(min(vdot(y,FMunoz_postobilloD),vdot(y,FMunoz_postobilloI))) + FMunoz_heightfootR,0>
	#end
}
