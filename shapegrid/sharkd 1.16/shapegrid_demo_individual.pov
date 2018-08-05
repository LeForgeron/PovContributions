// Caption: Shape grid macro
// Version: 1.16
// Authors: Michael Horvath, with formulas by And and Tor Olav Kristensen
// Website: http://isometricland.net
// Created: 2008-06-22
// Updated: 2018-08-04
// This file is licensed under the terms of the CC-LGPL.

#version 3.7;

#include "ShapeGrid_macro.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"

#declare scale_test = 2;


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

background {srgb 1}

light_source
{
	<0, 0, 0>
	color rgb	<1, 1, 1>
	translate	-x * 30
	rotate		-z * 60
	rotate		-y * 30
	parallel
	point_at 0
	shadowless
}

light_source
{
	<0, 0, 0>
	color rgb	<1, 1, 1>
	translate	-x * 30
	rotate		-z * 60
	rotate		+y * 60
	parallel
	point_at 0
	shadowless
}

sky_sphere
{
	pigment
	{
		gradient y
		color_map
		{
			[0.0 srgb <0.6,0.7,1.0>]
			[0.7 srgb <0.0,0.1,0.8>]
		}
	}
}

#local cam_aspc = image_width/image_height;		// obsolete. render square images only!
#local cam_dist = 10 * scale_test;
#local cam_area = 2 * scale_test;
#local cam_loca = -x * cam_dist;
#local cam_dirc = +x * cam_dist;
#local cam_rgvc = +z * cam_area;
#local cam_upvc = +y * cam_area;
#local cam_tran = transform
{
//	rotate		-z * 30
//	rotate		-z * atand(sind(45))
}

camera
{
	orthographic
	location	cam_loca				// position
	direction	cam_dirc				// direction of view
	right		cam_rgvc				// horizontal size of view
	up			cam_upvc				// vertical size of view
	transform {cam_tran}				// transforms
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
	plane {-z, 0 rotate -y * 60}
//	plane {-y, 0 rotate +z * 15}
	plane {+z, 0 rotate +y * 60}
}

#declare CylinderObject_Object = cylinder
{
	<0,0,0,>, <0,1,0,>, 1
	scale 0.99999
	translate y*0.000001
}

#declare CylinderObject_Intersection = intersection
{
	plane {-z, 0 rotate -y * 60}
//	plane {-y, 0 rotate +z * 30}
	plane {+z, 0 rotate +y * 60}
}

#declare SphereObject_Object = sphere {0, 1}

#declare SphereObject_Intersection = intersection
{
	plane {-z, 0 rotate -y * 60}
	plane {-y, 0 rotate +z * 30}
	plane {+z, 0 rotate +y * 60}
}


#declare EllipsoidObject_Object = sphere {0, 1 scale y * 3/4 scale scale_test}

#declare EllipsoidObject_Intersection = intersection
{
	plane {-z, 0 rotate -y * 60}
	plane {-y, 0 rotate +z * 30}
	plane {+z, 0 rotate +y * 60}
}

#declare EllipsoidObject_Intersection = intersection
{
	plane {+x, 0}
}

#declare BasicObject_Pigment = pigment {color srgbt <1,0,0,0>}


//------------------------------
// Examples using an object pattern
/*
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
				color srgbt 1
				color srgb <0,0,1,>
			}
		}
	}
//	scale 1
//	translate <-1,0,0,>
}
*/

//------------------------------
// Examples in a difference
/*
difference
{
	object {CylinderObject_Object}
	object {CylinderObject_Intersection}
	object {SGrid_Cylinder_Macro(6,12,6,1,1,0,0.01,on,off,)}
	texture {BasicObject_Pigment}
//	scale 1
//	translate <1,0,-1,>
}
*/

//------------------------------
// Examples in an intersection
/*
difference
{
	intersection
	{
		object {SGrid_Sphere_Macro(6,12,6,1,0,0.01,on,off,)}
		object {SphereObject_Object}
	}
	object {SphereObject_Intersection}
	texture {BasicObject_Pigment}
}
*/

difference
{
	intersection
	{
		object
		{
			SGrid_Ellipsoid_Macro
			(
				6,			// SGrid_Ellipsoid_radii,			// The number of radial divisions. (integer)
				12,			// SGrid_Ellipsoid_longt,			// The number of longitudinal divisions. (integer)
				6,			// SGrid_Ellipsoid_latit,			// The number of latitudinal divisions. (integer)
				scale_test * 1,			// SGrid_Ellipsoid_radius_major,	// The major (horizontal) radius of the ellipsoid. (float)
				scale_test * sinh(1)/cosh(1),		// SGrid_Ellipsoid_radius_minor,	// The minor (vertical) radius of the ellipsoid. (float)
				0,			// SGrid_Ellipsoid_center,			// The center coordinates of the sphere. (vector)
				0.01,		// SGrid_Ellipsoid_thickness,		// The thickness of the grid lines. (float)
				on,			// SGrid_Ellipsoid_offset,			// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways. (boolian)
				off,		// SGrid_Ellipsoid_endcap,			// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. (boolian)
			)
		}
		object {EllipsoidObject_Object}
//		rotate z * 90
	}
	object {EllipsoidObject_Intersection}
	texture {BasicObject_Pigment}
}
