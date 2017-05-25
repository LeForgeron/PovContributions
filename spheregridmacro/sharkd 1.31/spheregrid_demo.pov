// Title: Sphere grid macro v1.30
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008-01-10
// Last Updated: 2008-06-22
// This file is licensed under the terms of the CC-LGPL.

#include "SphereGrid_macro.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"

//------------------------------------------------------------------------------Scenery

global_settings
{
	assumed_gamma 1.0
	ambient_light 0.3
	radiosity
	{
		brightness 0.3
	}
}

background {rgb 1}

light_source
{
	<0, 0, 0>            // light's position (translated below)
	color rgb <1, 1, 1>  // light's color
	translate x*-30
	rotate z*-60
	rotate y * -30
	shadowless
}

light_source
{
	<0, 0, 0>            // light's position (translated below)
	color rgb <1, 1, 1>  // light's color
	translate x*-30
	rotate z*-60
	rotate y * 60
	shadowless
}

sky_sphere
{
	pigment
	{
		gradient y
		color_map
		{
			[0.0 rgb <0.6,0.7,1.0>]
			[0.7 rgb <0.0,0.1,0.8>]
		}
	}
}

camera
{
	#local CameraDistance = 10;
	#local ScreenArea = 3;
	#local AspectRatio = image_width/image_height;
//	orthographic
	location -x*CameraDistance
	direction x*CameraDistance
	right     z*ScreenArea*AspectRatio
	up        y*ScreenArea
	rotate z*asind(tand(-30))
}
/*
camera
{
	#local CameraDistance = 10;
	#local ScreenArea = 5;
	#local AspectRatio = image_width/image_height;
	orthographic
	location -z*CameraDistance
	direction z*CameraDistance
	right     x*ScreenArea*AspectRatio
	up        y*ScreenArea
//	rotate x*asind(tand(30))
	rotate x*90
//	rotate y*225
}
*/


//------------------------------------------------------------------------------CSG objects


//------------------------------
// Call the macro

SphereGrid_Macro
(
	6,			// SphereGrid_radii,		The number of radial divisions.		(integer)
	12,			// SphereGrid_longt,		The number of longitudinal divisions.	(integer)
	6,			// SphereGrid_lattt,		The number of lattitudinal divisions.	(integer)
	1,			// SphereGrid_radius,		The radius of the sphere.		(float)
	0,			// SphereGrid_center,		The center coordinates of the sphere.	(vector)
	0.01,			// SphereGrid_thickness,	The thickness of the grid lines.	(float)
	on,			// SphereGrid_offset,		Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
	off			// SphereGrid_endcap,		Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
)


#declare SphereObject_Object = sphere
{
	0, 1
}

#declare SphereObject_Intersection = intersection
{
	plane {-z, 0 rotate y * -60}
	plane {-y, 0 rotate z * 15}
	plane {+z, 0 rotate y * 60}
}

#declare SphereObject_Pigment = pigment {color rgb <1,0,0,>}

//------------------------------
// Example of the object used as an object pattern

difference
{
	object {SphereObject_Object}
	object {SphereObject_Intersection}
	texture {SphereObject_Pigment}
	texture
	{
		pigment
		{
			object
			{
				SphereGrid_Object
				color rgbt 1
				color rgb <0,0,1,>
			}
		}
	}
	scale 1
	translate <-1,0,0,>
}


//------------------------------
// Example of the object being used in a difference

difference
{
	object {SphereObject_Object}
	object {SphereObject_Intersection}
	object {SphereGrid_Object}
	texture {SphereObject_Pigment}
	scale 1
	translate <1,0,-1,>
}


//------------------------------
// Example of the object being used in an intersection

difference
{
	intersection
	{
		object {SphereGrid_Object}
		object {SphereObject_Object}
	}
	object {SphereObject_Intersection}
	texture {SphereObject_Pigment}
	scale 1
	translate <1,0,1,>
}