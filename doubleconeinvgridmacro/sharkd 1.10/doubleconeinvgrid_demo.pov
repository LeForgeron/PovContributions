// Title: Double-cone (inverted) grid macro v1.10
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008-06-22
// Last Updated: 2008-06-22
// This file is licensed under the terms of the CC-LGPL.

#include "DoubleConeInvGrid_macro.inc"
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
	rotate    z*asind(tand(-30))
	translate y * 0.5
}


//------------------------------------------------------------------------------CSG objects


//------------------------------
// Call the macro

DoubleConeInvGrid_Macro
(
	6,			// DoubleConeInvGrid_radii,	The number of radial divisions.			(integer)
	12,			// DoubleConeInvGrid_longt,	The number of longitudinal divisions.		(integer)
	6,			// DoubleConeInvGrid_lattt,	The number of latitudinal divisions.		(integer)
	1,			// DoubleConeInvGrid_radius,	The radius of the double-cone.			(float)
	1,			// DoubleConeInvGrid_height,	The height of each half of the double-cone.	(float)
	0,			// DoubleConeInvGrid_center,	The center coordinates of the double-cone.	(vector)
	0.01,			// DoubleConeInvGrid_thickness,	The thickness of the grid lines.		(float)
	on,			// DoubleConeInvGrid_offset,	Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
	off,			// DoubleConeInvGrid_endcap,	Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
)

#declare DoubleConeInvObject_Object = union
{
	cone {<0,0,0,>, 0, <0,+1,0,>, 1}
	cone {<0,0,0,>, 0, <0,-1,0,>, 1}
	scale 0.99999
	translate 0.00001
}

#declare DoubleConeInvObject_Intersection = intersection
{
	plane {-z, 0 rotate y * -60}
//	plane {-y, 0 rotate z * 15}
	plane {+z, 0 rotate y * 60}
}

#declare DoubleConeInvObject_Pigment = pigment {color rgb <1,0,0,>}

//------------------------------
// Example of the object used as an object pattern

difference
{
	object {DoubleConeInvObject_Object}
	object {DoubleConeInvObject_Intersection}
	texture {DoubleConeInvObject_Pigment}
	texture
	{
		pigment
		{
			object
			{
				DoubleConeInvGrid_Object
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
	object {DoubleConeInvObject_Object}
	object {DoubleConeInvObject_Intersection}
	object {DoubleConeInvGrid_Object}
	texture {DoubleConeInvObject_Pigment}
	scale 1
	translate <1,0,-1,>
}


//------------------------------
// Example of the object being used in an intersection

difference
{
	intersection
	{
		object {DoubleConeInvGrid_Object}
		object {DoubleConeInvObject_Object}
	}
	object {DoubleConeInvObject_Intersection}
	texture {DoubleConeInvObject_Pigment}
	scale 1
	translate <1,0,1,>
}