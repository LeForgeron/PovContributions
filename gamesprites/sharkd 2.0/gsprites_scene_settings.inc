// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Created: 2006-03-01
// Last updated: 2008-07-05
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "stdinc.inc"
#include "textures.inc"
#include "woods.inc"
#include "stones.inc"
#include "glass.inc"
#include "metals.inc"


// -------------------------------------------------------------
// Default values. These can be pre-declared in your scene.

#ifndef (GSprites_Seed)			#declare GSprites_Seed = seed(8829464);		#end	// The default seed value used for random functions.
#ifndef (GSprites_Width)		#declare GSprites_Width = 64;			#end	// The default width of a tile in POV-Ray units.
#ifndef (GSprites_Height)		#declare GSprites_Height = 64;			#end	// The default Height of a tile in POV-Ray units.
#ifndef (GSprites_Tiles)		#declare GSprites_Tiles = 1;			#end	// The default size of a scene, measured in tiles. Use this to zoom in/out.
#ifndef (GSprites_Stretch)		#declare GSprites_Stretch = off;		#end	// Should objects be stretched to meet the change in the number of tiles?
#ifndef (GSprites_Burst_Mode)		#declare GSprites_Burst_Mode = on;		#end	// Renders multiple copies of a projectile in a single tile.
#ifndef (GSprites_Camera_Rotate)	#declare GSprites_Camera_Rotate = 45;		#end	// The default camera y-axis rotation angle. By default the camera points in the -X and -Z directions.
#ifndef (GSprites_Show_Ground_Plane)	#declare GSprites_Show_Ground_Plane = off;	#end	// Use this to render the scene on a basic ground plane.
#ifndef (GSprites_Show_Grid_Marker)	#declare GSprites_Show_Grid_Marker = off;	#end	// Use this to orient the sprite within a template.
#ifndef (GSprites_Show_Basic_Floor)	#declare GSprites_Show_Basic_Floor = off;	#end	// Renders a plain, 1-tile floor beneath the scene.
#ifndef (GSprites_Show_Axis_Marker)	#declare GSprites_Show_Axis_Marker = off;	#end	// Renders crosshairs in the center of the scene.
#ifndef (GSprites_Show_Grid_Marker)	#declare GSprites_Show_Grid_Marker = off;	#end	// Renders part of a tile *beneath* the normal tile so that you can orient the image in a paint program.
#ifndef (GSprites_Sprite_Height)	#declare GSprites_Sprite_Height = 4;		#end	// The height/width aspect ratio of the sprite. You can make a sprite wider in the INI file, but the tile will always be aligned to the bottom.
#ifndef (GSprites_Left_Vector)		#declare GSprites_Left_Vector = (x-z)*GSprites_Width*GSprites_Tiles;	#end	// Used for moving tiles to the right or left.
#ifndef (GSprites_Up_Vector)		#declare GSprites_Up_Vector = (x+z)*GSprites_Width*GSprites_Tiles;	#end	// Used for moving tiles forward or backward.
#ifndef (GSprites_Tiles_Factor)
	#if (GSprites_Stretch = on)
		#declare GSprites_Tiles_Factor = GSprites_Tiles;
	#else
		#declare GSprites_Tiles_Factor = 1;
	#end
#end


// -------------------------------------------------------------
// Set direction based on the clock value.

#local GSprites_Count = clock * 16;
#local GSprites_No1 = mod(GSprites_Count,4);
#local GSprites_No2 = floor(GSprites_Count/4);
#if ((GSprites_No1 = 1) | (GSprites_No1 = 3))
	#ifndef (GSprites_North)	#declare GSprites_North = true; #end		// Is the object connected on this side?
#else
	#ifndef (GSprites_North)	#declare GSprites_North = false; #end
#end
#if ((GSprites_No1 = 2) | (GSprites_No1 = 3))
	#ifndef (GSprites_East)		#declare GSprites_East  = true; #end		// ...
#else
	#ifndef (GSprites_East)		#declare GSprites_East  = false; #end
#end
#if ((GSprites_No2 = 1) | (GSprites_No2 = 3))
	#ifndef (GSprites_South)	#declare GSprites_South = true; #end		// ...
#else
	#ifndef (GSprites_South)	#declare GSprites_South = false; #end
#end
#if ((GSprites_No2 = 2) | (GSprites_No2 = 3))
	#ifndef (GSprites_West)		#declare GSprites_West  = true; #end		// ...
#else
	#ifndef (GSprites_West)		#declare GSprites_West  = false; #end
#end


// -------------------------------------------------------------
// Misc. scene settings

background {color rgb z}			// the scene's background color
global_settings
{
	assumed_gamma 1
	max_trace_level 100
}


// -------------------------------------------------------------
// Camera

#declare GSprites_Camera_Latitude =	30;
#declare GSprites_Camera_Width =	GSprites_Width * GSprites_Tiles;
#declare GSprites_Camera_Diagonal =	GSprites_Camera_Width * cos(pi/4);
#declare GSprites_Camera_Offset =	z * (GSprites_Sprite_Height - 1) * GSprites_Camera_Diagonal;
#declare GSprites_Camera_Location =	vaxis_rotate(<0,0,-1,>, <1,0,0,>, GSprites_Camera_Latitude) * GSprites_Camera_Width * 1024;
#declare GSprites_Camera_Location =	GSprites_Camera_Location + GSprites_Camera_Offset;
#declare GSprites_Camera_Location =	vaxis_rotate(GSprites_Camera_Location, y, GSprites_Camera_Rotate);
#declare GSprites_Camera_LookAt =	0;
#declare GSprites_Camera_LookAt =	GSprites_Camera_LookAt + GSprites_Camera_Offset;
#declare GSprites_Camera_LookAt =	vaxis_rotate(GSprites_Camera_LookAt, y, GSprites_Camera_Rotate);

#macro GSprites_Standard_Camera()
	camera
	{
		orthographic
		up		GSprites_Sprite_Height * y * GSprites_Camera_Diagonal
		right		GSprites_Sprite_Height * x * GSprites_Camera_Diagonal  * image_width / image_height
		location	GSprites_Camera_Location
		look_at		GSprites_Camera_LookAt
	}
#end
#macro GSprites_Alternate_Camera()
	camera
	{
		orthographic
		up		GSprites_Sprite_Height * y * GSprites_Camera_Diagonal
		right		GSprites_Sprite_Height * x * GSprites_Camera_Diagonal * image_width / image_height
		location	-z * 4096 * GSprites_Tiles
		direction	+z
		rotate		x * GSprites_Camera_Latitude
		rotate		y * GSprites_Camera_Rotate
		translate	<1,0,1,> * GSprites_Width * 3/2
	}
#end
#macro GSprites_Perspective_Camera()
	camera
	{
		up		GSprites_Sprite_Height * y * GSprites_Camera_Diagonal
		right		GSprites_Sprite_Height * x * GSprites_Camera_Diagonal * image_width / image_height
		location	-z * 4096 * GSprites_Tiles
		direction	+z * 4096 * GSprites_Tiles
		rotate		x * GSprites_Camera_Latitude
		rotate		y * GSprites_Camera_Rotate
		translate	<1,0,1,> * GSprites_Width * 6/2
	}
#end

GSprites_Standard_Camera()


// -------------------------------------------------------------
// Lights

#declare GSprites_Light_Source_1 = light_source
{
	-z * 1024
	color rgb 1
	rotate x * 60
	rotate y * 120
	parallel
	point_at 0
//	rotate y * -90
}

#declare GSprites_Light_Source_2 = light_source
{
	-z * 1024
	color rgb 1
	rotate x * 60
	rotate y * -60
	parallel
	point_at 0
	rotate y * 270
}

object {GSprites_Light_Source_1}


// -------------------------------------------------------------
// Textures

#declare GSprites_Finish_Bright = finish
{
	diffuse 1
	ambient 1
	brilliance 1
	conserve_energy
}
#declare GSprites_Finish_Stark = finish
{
	diffuse 1
	ambient 0
	brilliance 0
	conserve_energy
}
#declare GSprites_Finish_Normal = finish
{
	conserve_energy
}
#declare GSprites_Default_Finish =	GSprites_Finish_Normal;
#declare GSprites_Plain_White =		texture {pigment {color rgb 1}			finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Black =		texture {pigment {color rgb 0}			finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Clear =		texture {pigment {color rgbt 1}			finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Gray =		texture {pigment {color rgb 1/2}		finish {GSprites_Default_Finish}}
#declare GSprites_Plain_DarkGray =	texture {pigment {color rgb 1/4}		finish {GSprites_Default_Finish}}
#declare GSprites_Plain_VDarkGray =	texture {pigment {color rgb 1/8}		finish {GSprites_Default_Finish}}
#declare GSprites_Plain_LightGray =	texture {pigment {color rgb 3/4}		finish {GSprites_Default_Finish}}
#declare GSprites_Plain_VLightGray =	texture {pigment {color rgb 7/8}		finish {GSprites_Default_Finish}}
#declare GSprites_Plain_DarkGreen =	texture {pigment {color rgb <073,116,060,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_DarkBlue =	texture {pigment {color rgb <000,000,136,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Brown =		texture {pigment {color rgb <098,064,030,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Beige =		texture {pigment {color rgb <140,123,093,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Red =		texture {pigment {color rgb <255,000,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_MedRed =	texture {pigment {color rgb <128,000,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_QrtRed =	texture {pigment {color rgb <192,000,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Green =		texture {pigment {color rgb <000,255,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_MedGreen =	texture {pigment {color rgb <000,128,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_QrtGreen =	texture {pigment {color rgb <000,192,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Blue =		texture {pigment {color rgb <000,000,255,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Yellow =	texture {pigment {color rgb <255,255,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_MedYellow =	texture {pigment {color rgb <128,128,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_QrtYellow =	texture {pigment {color rgb <224,224,000,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Pink =		texture {pigment {color rgb <191,064,095,>/255}	finish {GSprites_Default_Finish}}
#declare GSprites_Plain_Magenta =	texture {pigment {color rgb <255,000,255,>/255}	finish {GSprites_Default_Finish}}


// -------------------------------------------------------------
// Orientation markers

#local GSprites_Ground_Plane = plane {y,0 pigment {rgb 1/2}}
#local GSprites_Axis_Markers = union
{
	#local Wid = GSprites_Width/2 * GSprites_Tiles_Factor;
	sphere		{0,1		texture {GSprites_Plain_Black}}
	cylinder	{0,x*Wid,1	texture {GSprites_Plain_Red}}
	cylinder	{0,y*Wid,1	texture {GSprites_Plain_Green}}
	cylinder	{0,z*Wid,1	texture {GSprites_Plain_Blue}}
}
#local GSprites_Grid_Marker = polygon
{
	#local Wid = GSprites_Width/2 * GSprites_Tiles_Factor;
	#local NW = <+000/1,+000,-Wid/1,>;
	#local NE = <-Wid/1,+000,-Wid/1,>;
	#local SE = <-Wid/1,+000,+000/1,>;
	#local SW = <-Wid/2,+000,-Wid/2,>;
	4, NW, NE, SE, SW
	translate x * Wid * 2
	translate z * Wid * 2
}
#declare GSprites_Basic_Floor = polygon
{
	#local Wid = GSprites_Width/2 * GSprites_Tiles_Factor;
	#local NW = <+Wid,+000,-Wid,>;
	#local NE = <-Wid,+000,-Wid,>;
	#local SE = <-Wid,+000,+Wid,>;
	#local SW = <+Wid,+000,+Wid,>;
	4, NW, NE, SE, SW
}
#if (GSprites_Show_Ground_Plane = 1)
	object {GSprites_Ground_Plane}
#end
#if (GSprites_Show_Axis_Marker = 1)
	object {GSprites_Axis_Markers}
#end
#if (GSprites_Show_Grid_Marker = 1)
	object {GSprites_Grid_Marker	texture {GSprites_Plain_Magenta}}
#end
#if (GSprites_Show_Basic_Floor = 1)
	object {GSprites_Basic_Floor	texture {GSprites_Plain_White}}
#end
#declare GSprites_Clip_Cylinder = cylinder
{
	#local Hgh = 24/sin(pi/3);
	#local Rad = cos(pi/4) * GSprites_Width * GSprites_Tiles_Factor;
	0, y * Hgh, Rad
	scale y * 2
}
#declare GSprites_Clip_Box = box
{
	#local Wid = GSprites_Width/2 * GSprites_Tiles_Factor;
	#local Hgh = GSprites_Height;
	<-Wid,0,-Wid,>,<+Wid,+Hgh,+Wid,>
}


// -------------------------------------------------------------
// Misc. Macros

#if (version >= 3.1)
	#macro PrintValue(Text, Value)
		#debug concat(Text, str(Value,0,-1),"\n")
	#end
	#macro RandSign(Stream)
		#if (rand(Stream) < 0.5)
			#local Result = -1;
		#else
			#local Result = 1;
		#end
		Result
	#end
	#macro RandomProduct(Iterations,Stream)
		#local Result = 1;
		#local Count = 0;
		#while (Count < Iterations)
			#local Result = Result * rand(Stream);
			#local Count = Count + 1;
		#end
		Result
	#end
	#macro BetaDistribution(Value_1,Value_2,Stream)
		#local First = ln(RandomProduct(Value_1,Stream));
		#local Second = ln(RandomProduct(Value_2,Stream));
		#local Result = First/(First + Second);
		Result
	#end
	#macro BinarySwitch(Value)
		#if (Value = 1)
			#local Result = 0;
		#else
			#local Result = 1;
		#end
		Result
	#end
#end
