// Title: Fractal Objects Include v1.00
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/11/23
// Last Updated: 2008/11/23
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"
#include "FObjects_include.inc"


//------------------------------
// Scenery

global_settings
{
	assumed_gamma 1.0
	ambient_light 0.3
//	radiosity {brightness 0.3}
}

background {rgb 0}

light_source
{
	x*-100
	color rgb 2/4
	shadowless
	parallel
	rotate		z*-60
	rotate		y*-30
}

light_source
{
	x*-100
	color rgb 2/4
	shadowless
	parallel
	rotate		z*-60
	rotate		y*+60
}

camera
{
	#local CameraDistance = 10;
	#local ScreenArea = 2;
	#local AspectRatio = image_width/image_height;
	orthographic
	location -z*CameraDistance
	direction z*CameraDistance
	right     x*ScreenArea
	up        y*ScreenArea/AspectRatio
	rotate x*asind(tand(30))
	rotate y*45
}


//------------------------------
// CSG objects

object
{
	FObjects_Menger_Sponge(2)
	texture
	{
		pigment {color rgb 1}
		finish {ambient 1/2}
	}
	rotate y * 180
}
