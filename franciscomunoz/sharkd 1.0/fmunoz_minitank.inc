// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_MiniTank.inc
// Desc: Basic Scene Example
// Date: Nov-Dec 1997
// Last: 09/07/2008
// Auth: Francisco Munoz Cotobal, tweaked and prepared by Michael Horvath
// Notes: 1 meter = 10 units

#ifndef (Black)		#include "colors.inc" #end
#ifndef (Gold_Texture)	#include "textures.inc" #end


//*****************************************************************

#local FMunoz_Gun_rotate =		-30;	// values 0 to -180
#local FMunoz_Turret_rotate =		25;	// values 0 to 360
#local FMunoz_Focus =			0;	// 0 = Off , 1 = On, 2 = On w/faked beam (cylinder with high transmit)


//*****************************************************************

// Semi-arid theatre
#local FMunoz_ACP_Texture1 = texture
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
#local FMunoz_ACP_Texture2 = texture
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
#local FMunoz_ACP_Texture3 = texture
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
#local FMunoz_ACP_Texture4 = texture
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
	finish {ambient .45}
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
	finish {ambient .45}
	scale 1.5
	rotate 45
}
*/
#local FMunoz_ACP_Texture = texture {FMunoz_ACP_Texture4}

#local FMunoz_Barrel_Texture = texture
{
	pigment {color rgb <0.60,0.61,0.68>}
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

#local FMunoz_Barrel_Texture2 = texture
{
	pigment {color rgb <0.20,0.21,0.25>}
	finish
	{
		metallic
		ambient 0.2
		diffuse 0.7
		brilliance 6
		reflection 0.15
		phong 0.65
		phong_size 75
	}
}

#local FMunoz_Focus_Glass = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0.000 rgbf <0.0, 0.0, 0.0, 0.0>]
			[0.020 rgbf <0.2, 0.2, 0.2, 0.0>]
			[0.050 rgbf <0.98, 0.98, 0.98, 0.9>]
			[0.950 rgbf <0.98, 0.98, 0.98, 0.9>]
			[0.970 rgbf <0.2, 0.2, 0.2, 0.0>]
			[1.000 rgbf <0.0, 0.0, 0.0, 0.0>]
		}
		scale .3
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


//*****************************************************************
// Beware !! the Gatling gun and the turret uses a different construction view than other parts

#local FMunoz_Gatling = union
{
	#local FMunoz_Count = 0;
	#while (FMunoz_Count < 11)
		difference
		{
			cylinder {<-1,.9,0>,<-16,.9,0>,.20 rotate FMunoz_Count*x*36 texture {FMunoz_Barrel_Texture}}
			cylinder {<-2,.9,0>,<-17,.9,0>,.19 rotate FMunoz_Count*x*36 texture {FMunoz_Barrel_Texture2}}
		}
		#local FMunoz_Count = FMunoz_Count + 1;
	#end
	cylinder {<-5,0,0>,<-1,0,0>,1.5}
	cylinder {<-8.875,0,0>,<-9.125,0,0>,1.5}
	cylinder {<-14,0,0>,<-14.25,0,0>,1.5}
	cylinder {<-1,0,0>,<-14.26,0,0>,.20}		//Barrels' Axis
	sphere {<-14.26,0,0>,.20}
	texture {FMunoz_Barrel_Texture2}
}

#local FMunoz_Gun_Turret = union
{
	// Core
	sphere {<0,0,0>,6}
	difference
	{
		sphere {<0,0,0>,8}
		box {<-15,-2,-1>,<15,2,-15>}
		plane {-z,0}
	}
	// Turret base
	cylinder {<0,0,0>,<0,0,-.5>,9 pigment {Black}}
	// Antenae
	union
	{
		cylinder {<0,7,0>,<0,7,-7>,0.2 }
		cylinder {<0,7,0>,<0,7,-15>,0.05 pigment {Black}}
		sphere {<0,7,-15>,.1  no_shadow pigment {color rgbf <1,.1,.1,.75>}}
		light_source { <0,7,-15.02> color rgb <.2,.1,.1>}
		rotate z*-45
	}
	// Focus
	union
	{
		difference
		{
			union
			{
				cylinder {<0,-6,0><0,-9.5,0>,.4 pigment {Black}}
				cylinder {<-1,-9.5,0>,<1,-9.5,0>,2 }
				sphere {0,2 scale <.2,1,1> translate <1,-9.5,0>}
				cylinder {<-1.1,-9.5,0><-.95,-9.5,0>,2.1 pigment {Black}}
			}
			//"Parabolic" mirror inside focus
			sphere {<-1,-9.5,0>,1.8 texture {pigment {White} finish {reflection .8}}}
		}
		sphere
		{
			<0,0,0>,1.8
			texture {FMunoz_Focus_Glass}
			scale <.25,1,1>
			translate <-1,-9.5,0>
		}
		rotate y * FMunoz_Gun_rotate translate <-1,0,-4>  //Locate the focus
	}
}

#local FMunoz_Cannon_gun = union
{
	object {FMunoz_Gun_Turret}
	object {FMunoz_Gatling rotate y*FMunoz_Gun_rotate translate <0,0,-2>}
}

// A Big Wheel ;-)
#local FMunoz_Big_wheel = union
{
	difference
	{
		superellipsoid {<1,.25> pigment {Gray10} scale <5,5,2.5>}
		cylinder {<0,0,3>,<0,0,-3>,3}
	}
	torus {3,.5 rotate x*90 translate <0,0,-2> pigment {Gray10}}
	cylinder {<0,0,2.4>,<0,0,-2.4>,2.5}
	sphere {<0,0,0>,2.6 scale <1,1,.2> translate <0,0,-2.6>}
	intersection
	{
		superellipsoid {<1,.25> pigment {Gray10} scale <5.25,5.25,2.5>}
		union
		{
			#local FMunoz_Count = 0;
			#while (FMunoz_Count < 25)
				union
				{
					cylinder {<0,4,0>,<0,6,0>,.25}
					cylinder {<1,4,-2>,<.5,6,-2>,.25}
					cylinder {<1,4,2>,<.5,6,2>,.25}
					box {<-.25,4,0>,<.25,6,-2.236> rotate y*30}
					box {<-.25,4,0>,<.25,6,2.236> rotate y*-30}
					rotate z*15*FMunoz_Count
					pigment {Gray10}
				}
				#local FMunoz_Count = FMunoz_Count + 1;
			#end
		}
	}
}

#local FMunoz_Body = union
{
	difference
	{
		union
		{
			difference
			{
				// Upper part
				box {<-20,-2,5>,<20,6,-5>}
				plane {y,0 rotate <0,0,-60> translate <-20,6,0>}
				plane {y,0 rotate <0,0,50> translate <20,6,0>}
			}
			// Lower part
			difference
			{
				box {<-20,6,-12>,<20,12,12>}
				plane {-y,0 rotate <0,0,40> translate <-20,6,0>}
				plane {-y,0 rotate <0,0,-55> translate <20,6,0>}
				plane {-y,0 rotate <55,0,0> translate <0,6,12> }
				plane {-y,0 rotate <-55,0,0> translate <0,6,-12>}
			}
		}
		// hole for the back door
		box {<18,-2.1,4.5>,<20,11.5,-4.5>}
	}
	union
	{
		// Backdoor for troops
		box {<15,-1,4.5>,<18,11.5,-4.5>}
		box {<18,-0.5,4.3>,<18.5,11,-4>}
		cylinder {<18.15,1.5,-4.15>,<18.15,2.5,-4.15>,.155}
		cylinder {<18.15,7.5,-4.15>,<18.15,6.5,-4.15>,.155}
		cylinder {<18.5,4,3.5>,<19,4,3.5>,.125}
		cylinder {<18.5,6,3.5>,<19,6,3.5>,.125}
		sphere {<19,4,3.5>,.125}
		sphere {<19,6,3.5>,.125}
		cylinder {<19,4,3.5>,<19,6,3.5>,.125}
	}
	union
	{
		sphere {<14,13,-6>,.125}
		sphere {<12,13,-6>,.125}
		cylinder {<14,12,-6>,<14,13,-6>,.125}
		cylinder {<12,12,-6>,<12,13,-6>,.125}
		cylinder {<12,13,-6>,<14,13,-6>,.125}
	}
	union
	{
		sphere {<14,13,6>,.125}
		sphere {<12,13,6>,.125}
		cylinder {<14,12,6>,<14,13,6>,.125}
		cylinder {<12,12,6>,<12,13,6>,.125}
		cylinder {<12,13,6>,<14,13,6>,.125}
	}
	union
	{
		difference
		{
			union
			{
				cylinder {<-18,9,10>,<-14,9,10>,.75}
				cylinder {<-18,9,6>,<-14,9,6>,.75}
				box {<-18,9.75,10>,<-14,8.25,6>}
				sphere {<-14,9,10>,.75 }
				cylinder {<-14,9,10>,<-14,9,6>,.75}
				cylinder {<-18.2,9,9.5>,<-14,9,9.5>,.7 pigment {Black}}
				cylinder {<-18.2,9,6.5>,<-14,9,6.5>,.55 pigment {Black}}
			}
			sphere {<-18.2,9,9.5>,.6 texture {pigment {White} finish {reflection .8}}}
			sphere {<-18.2,9,6.5>,.5 texture {pigment {White} finish {reflection .8}}}
		}
		sphere
		{
			<0,0,0>,.6
			texture {FMunoz_Focus_Glass rotate x*90}
			scale <.25,1,1>
			translate <-18.2,9,9.5>
		}
		sphere
		{
			<0,0,0>,.5
			texture {pigment {rgbf <1,0,0,1>}}
			texture {FMunoz_Focus_Glass rotate x*90}
			scale <.25,1,1>
			translate <-18.2,9,6.5>
		}
	}
}


//*****************************************************************

#declare FMunoz_MiniTank = union
{
	object {FMunoz_Big_wheel translate <-12,0,-10>}
	object {FMunoz_Big_wheel translate <0,0,-10>}
	object {FMunoz_Big_wheel translate <12,0,-10>}
	object {FMunoz_Big_wheel rotate y*180 translate <-12,0,10>}
	object {FMunoz_Big_wheel rotate y*180 translate <0,0,10>}
	object {FMunoz_Big_wheel rotate y*180 translate <12,0,10>}
	cylinder {<-12,0,10>,<-12,0,-10>,2.25}	// Wheel Axis 1
	cylinder {<0,0,10>,<0,0,-10>,2.25}	// Wheel Axis 2
	cylinder {<12,0,10>,<12,0,-10>,2.25}	// Wheel Axis 2
	object {FMunoz_Cannon_gun scale .75 rotate <90,FMunoz_Turret_rotate,0> translate <-3,12,0>}
	object {FMunoz_Body translate 0}
	translate y*5.20
	texture {FMunoz_ACP_Texture}
}
