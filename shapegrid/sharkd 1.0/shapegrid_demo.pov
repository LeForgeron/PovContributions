// Title: Shape grid macro v1.00
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008-06-22
// Last Updated: 2008-06-22
// This file is licensed under the terms of the CC-LGPL.

#include "ShapeGrid_macro.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"


//------------------------------
// Scenery

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
	<0, 0, 0>
	color rgb	<1, 1, 1>
	translate	x*-30
	rotate		z*-60
	rotate		y*-30
	shadowless
}

light_source
{
	<0, 0, 0>
	color rgb	<1, 1, 1>
	translate	x*-30
	rotate		z*-60
	rotate		y*60
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
	location	x*-CameraDistance
	direction	x*CameraDistance
	right		z*ScreenArea*AspectRatio
	up		y*ScreenArea
	rotate		z*-30
	translate	y*1/2
}

//------------------------------
// CSG objects

#declare DoubleConeObject_Object = cone
{
	<0,0,0,>, 1, <0,+1,0,>, 0
	translate y*0.000001
}

#declare DoubleConeObject_Intersection = intersection
{
	plane {-z, 0 rotate y * -60}
//	plane {-y, 0 rotate z * 15}
	plane {+z, 0 rotate y * 60}
}

#declare CylinderObject_Object = cylinder
{
	<0,0,0,>, <0,1,0,>, 1
	scale 0.99999
	translate y*0.000001
}

#declare CylinderObject_Intersection = intersection
{
	plane {-z, 0 rotate y * -60}
//	plane {-y, 0 rotate z * 15}
	plane {+z, 0 rotate y * 60}
}

#declare SphereObject_Object = sphere {0, 1}

#declare SphereObject_Intersection = intersection
{
	plane {-z, 0 rotate y * -60}
	plane {-y, 0 rotate z * 15}
	plane {+z, 0 rotate y * 60}
}

#declare BasicObject_Pigment = pigment {color rgb <1,0,0,>}


//------------------------------
// Example using an object pattern

difference
{
	object {DoubleConeObject_Object}
	object {DoubleConeObject_Intersection}
	texture {BasicObject_Pigment}
	texture
	{
		pigment
		{
			object
			{
				SGrid_Cone_Macro(6,12,6,1,1,0,0.01,on,off,)
				color rgbt 1
				color rgb <0,0,1,>
			}
		}
	}
	scale 1
	translate <-1,0,0,>
}


//------------------------------
// Example in a difference

difference
{
	object {CylinderObject_Object}
	object {CylinderObject_Intersection}
	object {SGrid_Cylinder_Macro(6,12,6,1,1,0,0.01,on,off,)}
	texture {BasicObject_Pigment}
	scale 1
	translate <1,0,-1,>
}


//------------------------------
// Example in an intersection

difference
{
	intersection
	{
		object {SGrid_Sphere_Macro(6,12,6,1,0,0.01,on,off,)}
		object {SphereObject_Object}
	}
	object {SphereObject_Intersection}
	texture {BasicObject_Pigment}
	scale 1
	translate <1,1/2,1,>
}
