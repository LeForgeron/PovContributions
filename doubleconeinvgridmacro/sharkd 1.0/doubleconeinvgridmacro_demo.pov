// Title: Double-cone (inverted) grid macro v1.00
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/06/22
// Last Updated: 2008/06/22
// This file is licensed under the terms of the CC-LGPL.

#include "DoubleConeInvGridMacro_macro.inc"
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
	translate <-30, 30, -30>
	shadowless
}

light_source
{
	<0, 0, 0>            // light's position (translated below)
	color rgb <1, 1, 1>  // light's color
	translate <-30, 30, -30>
	rotate y * 90
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
	#local ScreenArea = 5;
	#local AspectRatio = image_width/image_height;
//	orthographic
	location -z*CameraDistance
	direction z*CameraDistance
	right     x*ScreenArea*AspectRatio
	up        y*ScreenArea
	rotate x*asind(tand(30))
	rotate y*225
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
	off,			// DoubleConeInvGrid_offset,	Determines whether the divisions are offset by half the amount (sometimes necessary when doing cut-aways at intervals matching the grid's divisions).	(boolian)
)

#declare DoubleConeObject_Object = union
{
	cone
	{
		<0,0,0,>, 0, <0,+1,0,>, 1
	}
	cone
	{
		<0,0,0,>, 0, <0,-1,0,>, 1
	}
	scale 0.99999
}

#declare DoubleConeObject_Intersection = intersection
{
	plane {-x, 0 rotate y * -15}
//	plane {-y, 0 Axis_Rotate_Trans(x-z, 15)}
	plane {-z, 0 rotate y * 15}
}


//------------------------------
// Example of the object used as an object pattern

difference
{
	object
	{
		DoubleConeObject_Object
	}
	object
	{
		DoubleConeObject_Intersection
	}
	texture
	{
		pigment
		{
			color rgb <1,0,0,>
		}
	}
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
	translate (x-z)
}


//------------------------------
// Example of the object being used in a difference

difference
{
	object
	{
		DoubleConeObject_Object
	}
	object
	{
		DoubleConeObject_Intersection
	}
	object
	{
		DoubleConeInvGrid_Object
	}
	texture
	{
		pigment
		{
			color rgb <1,0,0,>
		}
	}
	scale 1
	translate (z-x)
}


//------------------------------
// Example of the object being used in an intersection

difference
{
	intersection
	{
		object
		{
			DoubleConeInvGrid_Object
			texture
			{
				pigment
				{
					color rgb <1,0,0>
				}
			}
		}
		object
		{
			DoubleConeObject_Object
		}
	}
	object
	{
		DoubleConeObject_Intersection
	}
	scale 1
	translate -2 * (x+z)
}