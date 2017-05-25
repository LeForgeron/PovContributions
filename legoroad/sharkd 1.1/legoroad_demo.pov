// Title: Lego Road Macro v2.1
// Author: Michael Horvath
// Created: 2005-02-05
// Updated: 2008-06-25
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.


//------------------------------------------------------------------------------Dependencies & global variables

#declare LRoad_RoadWidth =		array[3] {280,306,360,}		// The width of the road.
#declare LRoad_StripeLength =		array[3] {64,64,64,}		// The distance between each stripe-interval.
#declare LRoad_CornerRadius =		array[3] {23,36,63,}		// The distance from the outer edge of the road to the inner edge of the innermost stripe, not including the center stripes.
#declare LRoad_MajorArc =		array[3] {52,0,10,}		// The distance from the intersection that the road begins to curve.
#declare LRoad_WalkDistance =		array[3] {75,75,75,}		// The distance from the intersection to the center of a crosswalk.
#declare LRoad_WalkWidth =		array[3] {234,234,234,}		// The width of the crosswalk.
#declare LRoad_WalkLength =		array[3] {60,60,60,}		// The width of the crosswalk.
#declare LRoad_WalkStripeWidth =	array[3] {25,25,25,}		// The width of a crosswalk stripe.
#declare LRoad_DistanceUnit = 		10;				// The unit of distance equivalent to 1 foot. Used when determining banking amount.
#include "LegoRoad_macro.inc"


//------------------------------------------------------------------------------Scenery

camera
{
	#local CameraDistance = 100000;
	#local ScreenArea = 1600;
	#local AspectRatio = image_width/image_height;
//	orthographic
	location	x*-CameraDistance
	direction	x*+CameraDistance
	right		z*ScreenArea*AspectRatio
	up		y*ScreenArea
	rotate		z*-30
	rotate		y*45
}

light_source
{
	<100000, 100000, 100000>
	rgb 2.0
	parallel
	shadowless
}

light_source
{
	<-100000, -100000, -100000>
	rgb 0.5
	parallel
	shadowless
}

background {rgb 0.5}


//------------------------------------------------------------------------------Examples

/*
// Straight
object
{
	LRoad_Road_Macro
	(
		-15,			// Starting tilt (banking) angle. Only applies if superelevation is disabled.	(float)
		-15,			// Ending tilt (banking) angle. Only applies if superelevation is disabled.	(float)
					// Tilt angles are interpolated linearly from beginning to end.
		1,			// The road's shape. 1 is a straight line, 2 is and ellipse, 3 is a Nautilus spiral, 4 is an Archimedes spiral and 5 is a spline (hermite).	(integer)
		array[2]		// The shape-specific parameters.						(array)
		{
			< 1500, 0, 0>,		// Starting point.				(vector)
			<-1500, 0, 0>,		// Ending point.				(vector)
		},
		64,			// The total number of calculated steps. Should equal the length of the road divided by the length of a stripe.	(integer)
		0,			// The step to begin rendering with.						(integer)
		64,			// The step to end rendering with.						(integer)
		yes,			// Enable/disable superelevation (road-banking).				(boolian)
					// Ignored if road shape equals 1.
		10,			// Speed limit (mph). Only applies if superelevation is enabled.		(float)
		2,			// Type of road. "9-Stud" is 1, "8-Stud" is 2 and "7-Stud" is 3.		(integer)
		no,			// Enable/disable debug information.						(boolian)
	)
}
*/
/*
// Ellipse
object
{
	LRoad_Road_Macro
	(
		-15,			// Starting tilt (banking) angle. Only applies if superelevation is disabled.	(float)
		-15,			// Ending tilt (banking) angle. Only applies if superelevation is disabled.	(float)
					// Tilt angles are interpolated linearly from beginning to end.
		2,			// The road's shape. 1 is a straight line, 2 is and ellipse, 3 is a Nautilus spiral, 4 is an Archimedes spiral and 5 is a spline (hermite).	(integer)
		array[2]		// The shape-specific parameters.						(array)
		{
			1500,			// The length of the ellipse's semi-major axis.					(float)
			1000,			// The length of the ellipse's semi-minor axis.					(float)
		},
		64,			// The total number of calculated steps. Should equal the length of the road divided by the length of a stripe.	(integer)
		0,			// The step to begin rendering with.						(integer)
		64,			// The step to end rendering with.						(integer)
		yes,			// Enable/disable superelevation (road-banking).				(boolian)
					// Ignored if road shape equals 1.
		10,			// Speed limit (mph). Only applies if superelevation is enabled.		(float)
		2,			// Type of road. "9-Stud" is 1, "8-Stud" is 2 and "7-Stud" is 3.		(integer)
		no,			// Enable/disable debug information.						(boolian)
	)
}
*/
/*
// Nautilus spiral
object
{
	LRoad_Road_Macro
	(
		-30,			// Starting tilt (banking) angle. Only applies if superelevation is disabled.		(float)
		0,			// Ending tilt (banking) angle. Only applies if superelevation is disabled.		(float)
					// Tilt angles are interpolated linearly from beginning to end.
		3,			// The road's shape. 1 is a straight line, 2 is and ellipse, 3 is a Nautilus spiral, 4 is an Archimedes spiral and 5 is a spline (hermite).	(integer)
		array[5]		// The shape-specific parameters.							(array)
		{
			2000,			// The radius of the spiral at step #0.							(float)
			0,			// The height of the spiral. Generates a 'corkscrew' if set to equal more than zero.	(integer)
			100,			// The angle at which the path of the spiral deviates from its previous vector.		(float, degrees)
						// Valid values range between 0 and 180 degrees. If 90 degrees, then a circle is generated.
						// A value of 0 (zero) causes POV-Ray to crash.
			0,			// The starting "t" value. Typically equal to zero.					(float, typically between 0 and 1)
			2,			// The ending "t" value. Typically equal to one.					(float, typically between 0 and 1)
		},
		60,			// The total number of calculated steps. Should equal the length of the road divided by the length of a stripe.	(integer)
		0,			// Begin rendering at this step.							(integer)
		60,			// End rendering at this step.								(integer)
		no,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		30,			// Speed limit (mph). Only applies if superelevation is enabled.			(float)
		1,			// Type of road. "9-Stud" is 1, "8-Stud" is 2 and "7-Stud" is 3.			(integer)
		no,			// Enable/disable debug information.							(boolian)
	)
}
*/

// Archimedes spiral
object
{
	LRoad_Road_Macro
	(
		0,			// Starting tilt (banking) angle. Only applies if superelevation is disabled.		(float)
		0,			// Ending tilt (banking) angle. Only applies if superelevation is disabled.		(float)
					// Tilt angles are interpolated linearly from beginning to end.
		4,			// The road's shape. 1 is a straight line, 2 is and ellipse, 3 is a Nautilus spiral, 4 is an Archimedes spiral and 5 is a spline (hermite).	(integer)
		array[4]		// The shape-specific parameters.							(array)
		{
			2000,			// The radius of the spiral at step #0.							(float)
			0,			// The height of the spiral. Generates a 'corkscrew' if set to equal more than zero.	(integer)
			0,			// The starting "t" value. Typically equal to zero.					(float, typically between 0 and 1)
			2,			// The ending "t" value. Typically equal to one.					(float, typically between 0 and 1)
		},
		60,			// The total number of calculated steps. Should equal the length of the road divided by the length of a stripe.	(integer)
		0,			// Begin rendering at this step.							(integer)
		60,			// End rendering at this step.								(integer)
		yes,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		30,			// Speed limit (mph). Only applies if superelevation is enabled.			(float)
		1,			// Type of road. "9-Stud" is 1, "8-Stud" is 2 and "7-Stud" is 3.			(integer)
		no,			// Enable/disable debug information.							(boolian)
	)
}

/*
// Hermite spline
object
{
	LRoad_Road_Macro
	(
		0,			// Starting tilt (banking) angle. Only applies if superelevation is disabled.		(float)
		0,			// Ending tilt (banking) angle. Only applies if superelevation is disabled.		(float)
					// Tilt angles are interpolated linearly from beginning to end.
		5,			// The road's shape. 1 is a straight line, 2 is and ellipse, 3 is a Nautilus spiral, 4 is an Archimedes spiral and 5 is a spline (hermite).	(integer)
		array[4]		// The shape-specific parameters.							(array)
		{
			< 1500, 0, -500>,			// EndPoint1: Point at beginning of spline.					(vector)
			<    0, 0, 5000>,		// TangentPoint1: Point that the spline points toward at EndPoint1.		(vector)
			<-1500, 0, 500>,			// EndPoint2: Point at end of spline.						(vector)
			<-3000, 0, 5000>,		// TangentPoint2: Point that the spline points toward at EndPoint2.		(vector)
		},
		60,			// The total number of calculated steps. Should equal the length of the road divided by the length of a stripe.	(integer)
		0,			// Begin rendering at this step.							(integer)
		60,			// End rendering at this step.								(integer)
		no,			// Enable/disable superelevation (road-banking).					(boolian)
					// Ignored if road shape equals 1.
		30,			// Speed limit (mph). Only applies if superelevation is enabled.			(float)
		2,			// Type of road. "9-Stud" is 1, "8-Stud" is 2 and "7-Stud" is 3.			(integer)
		no,			// Enable/disable debug information.							(boolian)
	)
}
*/
/*
// Flat intersections
object
{
	LRoad_Intersection_Macro
	(
					// Intersection vectors. Roads begin at the given vector and end (intersect) at the origin.	(array)
		array[5]		// There can be as many as you want. List them in counter-clockwise order.
		{
			<0, 0, 1024>,			// Road vector 1.	(vector)
			<-1024, 0, 1024>,		// Road vector 2.	(vector)
			<-1024, 0, -1024>,		// Road vector 3.	(vector)
			<0, 0, -1024>,			// Road vector 4.	(vector)
			<1024, 0, -1024>,		// Road vector 5.	(vector)
			// ...				// ...
		},
		3,			// Type of road. "9-Stud" is 1, "8-Stud" is 2 and "7-Stud" is 3.	(integer)
		no,			// Enables/disables debug information.	(boolian)
	)
}
*/
