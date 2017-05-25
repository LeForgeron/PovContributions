// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_Copas.pov
// Desc: Basic Scene Example
// Date: ??/8/97  (revised in 02/98)
// Last: 08/07/2008
// Auth: Francisco Munoz, tweaked and prepared by Michael Horvath
// Scale 1 unit = 10 Cm.
// Bottle = 3 units high
// Cups = 1.65 units high
// Base at y=0

#include "colors.inc"

#local TexCopa = texture
{
	pigment {color rgbf <.8,.9,1,.80>}
	finish
	{
		phong .5
		phong_size 200
		reflection .25
		refraction 1
		ior 1.5
		caustics 1
	}
}
#local TexCava = texture
{
	pigment
	{
		bozo
		turbulence 5
		pigment_map
		{
			[.05 color rgbf <1,1,.8,1>]              //"Brubujas" (Bubles)
			[.06 color rgbf <1,1,.5,.70>]
		}
	}
	finish
	{
		// refraction 1
		//ior 1.6
		//caustics 1 //Lo sentimos pero hace cosas raras
	}
}
#local TexBottle = texture
{
	pigment {color rgbf <.1,.6,.3,.75>}
	finish
	{
		reflection .10
		refraction 1
		ior 1.5
		phong .5
		phong_size 100
		caustics 1
	}
}


// ----------------------------------------

#declare FMunoz_Cup = lathe
{
	quadratic_spline
	7, <1, 6>, <1,5.5>, <.7,3>, <.2,2>,<.2,.75>, <1, .1>, <1,0>
	texture { TexCopa }
	scale .3
}

#declare FMunoz_Cava = sor
{
	6,
	<0,2.1>,<.2,2.25>, <.50,3>,<.85,4.95>,<.80,5>,<0,5>
	texture { TexCava}
	scale .3
}

#declare FMunoz_Bottle = lathe
{
	cubic_spline
	25,
	<0.000000,0.072539>,
	<0.018135,0.075130>,
	<0.090674,0.025907>,
	<0.139896,0.000000>,
	<0.173575,0.020725>,
	<0.183938,0.090674>,
	<0.186528,0.437824>,
	<0.147668,0.546632>,
	<0.077720,0.642487>,
	<0.062176,0.821244>,
	<0.062176,0.888601>,
	<0.069948,0.922280>,
	<0.069948,0.968912>,
	<0.062176,0.984456>,
	<0.051813,1.000000>,
	<0.038860,0.963731>,
	<0.044041,0.813472>,
	<0.051813,0.626943>,
	<0.126943,0.531088>,
	<0.163212,0.432642>,
	<0.160622,0.088083>,
	<0.113990,0.054404>,
	<0.056995,0.126943>,
	<0.015544,0.137306>,
	<0.000000,0.129534>
	texture {TexBottle}
	scale <2.85,3,2.85>
}
