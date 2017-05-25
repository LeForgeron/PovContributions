// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_Mano.inc
// Desc: A jar or vase.
// Date: 27/08/1997
// Last: 09/07/2008
// Auth: Francisco Munoz, tweaked and prepared by Michael Horvath

#include "colors.inc"
#include "textures.inc"

#declare FMunoz_Jarron = union
{
	lathe
	{
		cubic_spline
		6,
		<-.25, -1.00>,
		<.35, 0.00>,
		<1.1, 2.25>,
		<.50, 3.0>,
		<.75, 4.50>,
		<1.25, 5.0>
		texture {PinkAlabaster}
	}
	torus {.75,.02 translate y*4.5 pigment {White}}
	torus {.35,.02 translate y*0 pigment {White}}
}
