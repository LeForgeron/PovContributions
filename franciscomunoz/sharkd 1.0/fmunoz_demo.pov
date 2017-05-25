// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// Title: Francisco Munoz object collection
// File: FMunoz_demo.pov
// Desc: Demo of Francisco Munoz's object includes.
// Date: 08/07/2008
// Last: 08/07/2008
// Auth: Michael Horvath


// -------------------------------------------------------------
// Default values. These can be pre-declared in your scene.

#ifndef (FMunoz_Width)			#declare FMunoz_Width =		64;		#end	// The default width of a tile in POV-Ray units.
#ifndef (FMunoz_Height)			#declare FMunoz_Height =	16;		#end	// The default Height of a tile in POV-Ray units.
#ifndef (FMunoz_Tiles)			#declare FMunoz_Tiles =		1;		#end	// The default size of a scene, measured in tiles. Use this to zoom in/out.
#ifndef (FMunoz_Camera_Rotate)		#declare FMunoz_Camera_Rotate =	45;		#end	// The default camera y-axis rotation angle. By default the camera points in the -X and -Z directions.
#ifndef (FMunoz_Sprite_Height)		#declare FMunoz_Sprite_Height =	6;		#end	// The height/width aspect ratio of the sprite. You can make a sprite wider in the INI file, but the tile will always be aligned to the bottom.
#ifndef (FMunoz_Left_Vector)		#declare FMunoz_Left_Vector =	(x-z)*FMunoz_Width*FMunoz_Tiles;	#end	// Used for moving tiles to the right or left.
#ifndef (FMunoz_Up_Vector)		#declare FMunoz_Up_Vector =	(x+z)*FMunoz_Width*FMunoz_Tiles;	#end	// Used for moving tiles forward or backward.
#declare FMunoz_Camera_Latitude =	30;
#declare FMunoz_Camera_Width =		FMunoz_Width * FMunoz_Tiles;
#declare FMunoz_Camera_Diagonal =	FMunoz_Camera_Width * cos(pi/4);
#declare FMunoz_Camera_Offset =		z * (FMunoz_Sprite_Height - 1) * FMunoz_Camera_Diagonal;
#declare FMunoz_Camera_Location =	vaxis_rotate(<0,0,-1,>, <1,0,0,>, FMunoz_Camera_Latitude) * FMunoz_Camera_Width * 1024;
#declare FMunoz_Camera_Location =	FMunoz_Camera_Location + FMunoz_Camera_Offset;
#declare FMunoz_Camera_Location =	vaxis_rotate(FMunoz_Camera_Location, y, FMunoz_Camera_Rotate);
#declare FMunoz_Camera_LookAt =		0;
#declare FMunoz_Camera_LookAt =		FMunoz_Camera_LookAt + FMunoz_Camera_Offset;
#declare FMunoz_Camera_LookAt =		vaxis_rotate(FMunoz_Camera_LookAt, y, FMunoz_Camera_Rotate);


// -------------------------------------------------------------
// Scene settings

background {color rgb 1/2}

global_settings
{
	assumed_gamma 1
	max_trace_level 100
}

plane {y,0 pigment {checker scale FMunoz_Width}}

camera
{
	orthographic
	up		FMunoz_Sprite_Height * y * FMunoz_Camera_Diagonal
	right		FMunoz_Sprite_Height * x * FMunoz_Camera_Diagonal  * image_width / image_height
	location	FMunoz_Camera_Location
	look_at		FMunoz_Camera_LookAt
}

light_source
{
	-z * 1024
	color rgb 1
	rotate x * 60
	rotate y * 120
	parallel
	point_at 0
}


// -------------------------------------------------------------
// The objects

#include "FMunoz_DeskItems.inc"
object {FMunoz_Blotter			scale  3 translate FMunoz_Left_Vector*+3/2}
object {FMunoz_Pen			scale  3 translate FMunoz_Left_Vector*+1/2}
object {FMunoz_PenCap			translate <0,7.6,0> scale 3 translate FMunoz_Left_Vector*+1/2}
object {FMunoz_CigarBox			scale  2 translate FMunoz_Left_Vector*-1/2}
#include "FMunoz_Column.inc"
object {FMunoz_Column			scale  4 translate FMunoz_Left_Vector*-3/2}

#include "FMunoz_Drinks.inc"
object {FMunoz_Cup			scale 16 translate FMunoz_Left_Vector*+3/2 translate FMunoz_Up_Vector}
object {FMunoz_Cava			scale 16 translate FMunoz_Left_Vector*+1/2 translate FMunoz_Up_Vector}
object {FMunoz_Cup			scale 16 translate FMunoz_Left_Vector*+1/2 translate FMunoz_Up_Vector}
object {FMunoz_Bottle			scale 16 translate FMunoz_Left_Vector*-1/2 translate FMunoz_Up_Vector}
#include "FMunoz_Jarron.inc"
object {FMunoz_Jarron			scale  8 translate FMunoz_Left_Vector*-3/2 translate FMunoz_Up_Vector}

#include "FMunoz_Swords.inc"
object {FMunoz_WavySword		scale  2 translate FMunoz_Left_Vector*+3/2 translate FMunoz_Up_Vector*2}
object {FMunoz_ShortSword		scale  4 translate FMunoz_Left_Vector*+1/2 translate FMunoz_Up_Vector*2}
object {FMunoz_Clock			scale  3 translate FMunoz_Left_Vector*-1/2 translate FMunoz_Up_Vector*2}
#include "FMunoz_MiniTank.inc"
object {FMunoz_MiniTank			scale  1 translate FMunoz_Left_Vector*-3/2 translate FMunoz_Up_Vector*2}

#include "FMunoz_Fruit.inc"
object {FMunoz_TodoElMalacaton		scale 16 translate FMunoz_Left_Vector*+3/2 translate FMunoz_Up_Vector*3}
object {FMunoz_TodaLaManzana		scale 16 translate FMunoz_Left_Vector*+1/2 translate FMunoz_Up_Vector*3}
object {FMunoz_TodaLaPera		scale 16 translate FMunoz_Left_Vector*-1/2 translate FMunoz_Up_Vector*3}

#include "FMunoz_Homid.inc"
object {FMunoz_Homid_Object		scale FMunoz_Width/25 translate FMunoz_Left_Vector*+3/2 translate FMunoz_Up_Vector*4}
#include "FMunoz_Android.inc"
object {FMunoz_Android_Object		scale FMunoz_Width/25 translate FMunoz_Left_Vector*+1/2 translate FMunoz_Up_Vector*4}
#include "FMunoz_MiniMech.inc"
object {FMunoz_MiniMech_Object		scale FMunoz_Width/25 translate FMunoz_Left_Vector*-1/2 translate FMunoz_Up_Vector*4}
#include "FMunoz_BabyDino.inc"
object {FMunoz_BabyDino_Object		scale FMunoz_Width/5  translate FMunoz_Left_Vector*-3/2 translate FMunoz_Up_Vector*4}