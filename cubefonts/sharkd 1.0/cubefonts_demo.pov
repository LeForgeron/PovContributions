// Title: Cube Fonts macro v1.0
// Author: Michael Horvath
// Homepage: http://isometricland.com
// Created: 2009-10-29
// Last Updated: 2009-10-29
// This file is licensed under the terms of the CC-LGPL.


//------------------------------
// Includes

#include "CubeFonts_include.inc"
#include "math.inc"


//------------------------------
// Scenery

global_settings
{
	assumed_gamma	1.0
	ambient_light	0.3
}

background {rgb 1}

light_source
{
	-x * 100
	color rgb 2/4
	shadowless
	parallel
	rotate		-z * 60
	rotate		-y * 30
}
light_source
{
	-x * 100
	color rgb 2/4
	shadowless
	parallel
	rotate		-z * 60
	rotate		+y * 60
}

camera
{
	#local CameraDistance =	10;
	#local AspectRatio =	image_width/image_height;
	orthographic
	location	-z * CameraDistance
	direction	+z
	up		+y * 6
	right		+x * 8
	rotate		+x * asind(tand(30))
	rotate		+y * 45
//	rotate		+y * 90
}
/*
union
{
	sphere
	{
		0,1/100
		pigment{color rgb <0,0,0,>}
	}
	cylinder
	{
		0,x,1/100
		pigment{color rgb <1,0,0,>}
	}
	cylinder
	{
		0,y,1/100
		pigment{color rgb <0,1,0,>}
	}
	cylinder
	{
		0,z,1/100
		pigment{color rgb <0,0,1,>}
	}
}
*/

//------------------------------
// Macro examples

#declare Font_Name =		"visitor1.ttf";
#declare Text_Direction =	7;
#declare Char_Distance =	1;
#declare Char_Scale =		<1,1,1,>;
#declare String_Array = array[3]
{
	"HELLO",
	"HELLO",
	"HELLO"
}
object
{
	CBF_String_Macro(String_Array,Font_Name,Text_Direction,Char_Distance,Char_Scale)
	pigment {color rgb 1}
	translate	+z * 3
	translate	-x * 1
}


#declare Font_Name =		"visitor1.ttf";
#declare Text_Direction =	7;
#declare Char_Distance =	1;
#declare Char_Scale =		<1,1,1,>;
#declare String_Array = array[3]
{
	"WORLD",
	"WORLD",
	"     ",
}
object
{
	CBF_String_Macro(String_Array,Font_Name,Text_Direction,Char_Distance,Char_Scale)
	pigment {color rgb 1}
	translate	-x * 5
	translate	-z * 1
}

#declare Font_Name =		"visitor1.ttf";
#declare Text_Direction =	7;
#declare Char_Distance =	1;
#declare Char_Scale =		<1,1,1,>;
#declare String_Array = array[3]
{
	"    ",
	"FONT",
	"CUBE",
}
object
{
	CBF_String_Macro(String_Array,Font_Name,Text_Direction,Char_Distance,Char_Scale)
	pigment {color rgb 1}
	translate	+z * 0.5
	translate	-x * 2.5
}
