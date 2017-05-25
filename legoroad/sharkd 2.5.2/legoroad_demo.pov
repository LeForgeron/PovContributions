// Title: Lego Road Macro v2.5.2
// Author: Michael Horvath
// Created: 2005-02-05
// Updated: 2008-12-22
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.
// +KFI0 +KFF11 +KC
// +k0.5

//------------------------------------------------------------------------------Dependencies & global variables

#declare LRoad_SkyVector =		y;					// The direction of the sky.								(vector)
										// ... Does not apply to flat intersections.
#declare LRoad_FloorObject =		plane {LRoad_SkyVector, -100};		// The object that is considered the ground.						(object)

#declare LRoad_Debug =			0;					// Level of debug information.								(integer)
										// ... 0 = off; 1 = text only; 2 = text and marker objects.
#include "LegoRoad_macro.inc"


//------------------------------------------------------------------------------Scenery

camera
{
	#local CameraDistance = 100000;
	#local ScreenArea = 1600;
	#local AspectRatio = image_width/image_height;
	orthographic
	location	x*-CameraDistance
	direction	x//*+CameraDistance		// Uncomment the latter portion if not using an orthographic camera.
	right		z*ScreenArea*AspectRatio
	up		y*ScreenArea
	rotate		z*-30
	rotate		y*+45
	scale 2
}

light_source
{
	-z * 100000
	rgb 2.0
	rotate x*30
	rotate y*45
	parallel
//	shadowless
}

light_source
{
	-z * 100000
	rgb 2.0
	rotate x*30
	rotate y*225
	parallel
	shadowless
}

background {rgb 1/2}

object
{
	LRoad_FloorObject
	pigment {color rgb 1/2}
}

//------------------------------------------------------------------------------Examples

/*
// Straight
object
{
	LRoad_Road_Macro
	(
		0,			// The starting tilt (banking) angle. Only applies if superelevation is disabled.	(float, typically between 0 and +/-90)
		0,			// The ending tilt (banking) angle. Only applies if superelevation is disabled.		(float, typically between 0 and +/-90)
					// ... Tilt angles are interpolated linearly at each step.
		0,			// The road's shape.									(integer)
					// ... 0 = straight line; 1 = ellipse; 2 = Nautilus spiral; 3 = Archimedes spiral; 4 = hermite spline.
		array[2]		// The shape-specific parameters.							(array)
					// ... Make sure to increment the array counter when adding or subtracting elements.
		{
			< 1500, 0, 0>,	// Starting point.									(vector)
			<-1500, 0, 0>,	// Ending point.									(vector)
		},
		60,			// The total number of calculated steps.						(integer)
					// ... Should roughly equal the length of the road divided by the length of each stripe.
		0,			// The step number to begin rendering at.						(integer)
		60,			// The step number to end rendering at.							(integer)
		no,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		10,			// The speed limit (mph). Only applies if superelevation is enabled.			(float)
		2,			// The type of road. 0 = "9-Stud"; 1 = "8-Stud"; 2 = "7-Stud".				(integer)
		1,			// Enable/disable road embankments.							(boolean)
	)
}

// Ellipse
object
{
	LRoad_Road_Macro
	(
		0,			// The starting tilt (banking) angle. Only applies if superelevation is disabled.	(float, typically between 0 and +/-90)
		0,			// The ending tilt (banking) angle. Only applies if superelevation is disabled.		(float, typically between 0 and +/-90)
					// ... Tilt angles are interpolated linearly at each step.
		1,			// The road's shape.									(integer)
					// ... 0 = straight line; 1 = ellipse; 2 = Nautilus spiral; 3 = Archimedes spiral; 4 = hermite spline.
		array[6]		// The shape-specific parameters.							(array)
					// ... Make sure to increment the array counter when adding or subtracting elements.
		{
			1500,		// The length of the ellipse's semi-major axis.						(float)
			1000,		// The length of the ellipse's semi-minor axis.						(float)
			0,		// The starting height.									(float)
			0,		// The ending height. Generates a "corkscrew" effect if not equal to zero.		(float)
			0,		// The starting "t" value. Typically equal to zero.					(float, typically between 0 and 1)
			1,		// The ending "t" value. Typically equal to one.					(float, typically between 0 and 1)
		},
		60,			// The total number of calculated steps.						(integer)
					// ... Should roughly equal the length of the road divided by the length of each stripe.
		0,			// The step number to begin rendering at.						(integer)
		60,			// The step number to end rendering at.							(integer)
		on,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		30,			// The speed limit (mph). Only applies if superelevation is enabled.			(float)
		2,			// The type of road. 0 = "9-Stud"; 1 = "8-Stud"; 2 = "7-Stud".				(integer)
		1,			// Enable/disable road embankments.							(boolean)
	)
}

// Nautilus spiral
object
{
	LRoad_Road_Macro
	(
		0,			// The starting tilt (banking) angle. Only applies if superelevation is disabled.	(float, typically between 0 and +/-90)
		0,			// The ending tilt (banking) angle. Only applies if superelevation is disabled.		(float, typically between 0 and +/-90)
					// ... Tilt angles are interpolated linearly at each step.
		2,			// The road's shape.									(integer)
					// ... 0 = straight line; 1 = ellipse; 2 = Nautilus spiral; 3 = Archimedes spiral; 4 = hermite spline.
		array[7]		// The shape-specific parameters.							(array)
					// ... Make sure to increment the array counter when adding or subtracting elements.
		{
			2000,		// The radius of the spiral at step #0.							(float)
			0,		// The starting height.									(float)
			0,		// The ending height. Generates a "corkscrew" effect if not equal to zero.		(float)
			100,		// The angle at which the path of the spiral deviates from its previous vector.		(float, degrees)
					// Valid values range between 0 and 180 degrees. If 90 degrees, then a circle is generated.
					// A value of 0 (zero) causes POV-Ray to crash.
			0,		// The starting "t" value. Typically equal to zero.					(float, typically between 0 and 1)
			2,		// The ending "t" value. Typically equal to one.					(float, typically between 0 and 1)
			1,		// Reverse the spiral's direction?							(boolean)
		},
		60,			// The total number of calculated steps.						(integer)
					// ... Should roughly equal the length of the road divided by the length of each stripe.
		0,			// The step number to begin rendering at.						(integer)
		60,			// The step number to end rendering at.							(integer)
		no,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		30,			// The speed limit (mph). Only applies if superelevation is enabled.			(float)
		2,			// The type of road. 0 = "9-Stud"; 1 = "8-Stud"; 2 = "7-Stud".				(integer)
		1,			// Enable/disable road embankments.							(boolean)
	)
}

// Archimedes spiral
object
{
	LRoad_Road_Macro
	(
		0,			// The starting tilt (banking) angle. Only applies if superelevation is disabled.	(float, typically between 0 and +/-90)
		0,			// The ending tilt (banking) angle. Only applies if superelevation is disabled.		(float, typically between 0 and +/-90)
					// ... Tilt angles are interpolated linearly at each step.
		3,			// The road's shape.									(integer)
					// ... 0 = straight line; 1 = ellipse; 2 = Nautilus spiral; 3 = Archimedes spiral; 4 = hermite spline.
		array[6]		// The shape-specific parameters.							(array)
					// ... Make sure to increment the array counter when adding or subtracting elements.
		{
			1000,		// The radius of the spiral at step #0.							(float)
			0,		// The starting height.									(float)
			0,		// The ending height. Generates a "corkscrew" effect if not equal to zero.		(float)
			0,		// The starting "t" value. Typically equal to zero.					(float, typically between 0 and 1)
			2,		// The ending "t" value. Typically equal to one.					(float, typically between 0 and 1)
			1,		// Reverse the spiral's direction?							(boolean)
		},
		60,			// The total number of calculated steps.						(integer)
					// ... Should roughly equal the length of the road divided by the length of each stripe.
		0,			// The step number to begin rendering at.						(integer)
		60,			// The step number to end rendering at.							(integer)
		yes,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		30,			// The speed limit (mph). Only applies if superelevation is enabled.			(float)
		2,			// The type of road. 0 = "9-Stud"; 1 = "8-Stud"; 2 = "7-Stud".				(integer)
		1,			// Enable/disable road embankments.							(boolean)
	)
}

// Hermite spline
object
{
	LRoad_Road_Macro
	(
		0,			// The starting tilt (banking) angle. Only applies if superelevation is disabled.	(float, typically between 0 and +/-90)
		0,			// The ending tilt (banking) angle. Only applies if superelevation is disabled.		(float, typically between 0 and +/-90)
					// ... Tilt angles are interpolated linearly at each step.
		4,			// The road's shape.									(integer)
					// ... 0 = straight line; 1 = ellipse; 2 = Nautilus spiral; 3 = Archimedes spiral; 4 = hermite spline.
		array[4]		// The shape-specific parameters.							(array)
					// ... Make sure to increment the array counter when adding or subtracting elements.
		{
			<+1500, 0, -0000>,	// Point1: End of spline #3. Beginning of spline #1.				(vector)
			<+1500, 0, +9000>,	// Tangent1: Point that the spline points toward at Point1.			(vector)
			<-1500, 0, +0000>,	// Point2: End of spline #1. Beginning of spline #2.				(vector)
			<-1500, 0, +9000>,	// Tangent2: Point that the spline points toward at Point2.			(vector)
//			<+1500, 0, -0000>,	// Point3: End of spline #2. Beginning of spline #3.				(vector)
//			<+1500, 0, +9000>,	// Tangent3: Point that the spline points toward at Point3.			(vector)
			// ...			// ...
			// ...			// ...
		},
		60,			// The total number of calculated steps.						(integer)
					// ... Should roughly equal the length of the road divided by the length of each stripe.
		0,			// The step number to begin rendering at.						(integer)
		60,			// The step number to end rendering at.							(integer)
		no,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		30,			// The speed limit (mph). Only applies if superelevation is enabled.			(float)
		2,			// The type of road. 0 = "9-Stud"; 1 = "8-Stud"; 2 = "7-Stud".				(integer)
		1,			// Enable/disable road embankments.							(boolean)
	)
}
*/
// Flat intersections
object
{
	#local test_vector = vaxis_rotate(<+1024, 0, -1024>, y, -clock * 270);
	LRoad_Intersection_Macro
	(
		array[5]		// An array of vectors containing the starting points of the intersecting roads.	(array)
					// ... There can be as many as you want. List them in clockwise order when looking down from the top.
					// ... Since the intersections are flat, the vectors are two-dimensional instead of three-dimensional, and contain only the x and z coordinates.
					// ... Make sure to increment the array counter when adding or subtracting elements.
		{
			<-0512, +1536>,	// Road vector 1.									(vector)
			<-1024, +1024>,	// Road vector 2.									(vector)
			<-1024, -1024>,	// Road vector 3.									(vector)
			<+0512, -1536>,	// Road vector 4.									(vector)
			<+1024, -1024>,	// Road vector 5.									(vector)
			// ...		// ...
//			<test_vector.x, test_vector.z,>,	// Test vector.
		},
		0,			// The height of the road above the x-z plane.						(float)
		2,			// The type of road. 0 = "9-Stud"; 1 = "8-Stud"; 2 = "7-Stud".				(integer)
		1,			// Enable/disable crosswalks.								(boolean)
		1,			// Enable/disable road embankments.							(boolean)
	)
}
