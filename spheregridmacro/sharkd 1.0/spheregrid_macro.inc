// Title: Sphere grid macro v1.0
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/01/10
// Last Updated: 2008/01/10
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"

#macro SphereGrid_Macro
	(
		SphereGrid_radii,		// The number of radial divisions.	(integer)
		SphereGrid_longt,		// The number of longitudinal divisions.	(integer)
		SphereGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		SphereGrid_radius,		// The radius of the sphere.	(float)
		SphereGrid_center,		// The center coordinates of the sphere. (vector)
		SphereGrid_thickness,		// The thickness of the grid lines. (float)
		SphereGrid_offset,		// Determines whether the divisions are offset by half the amount (sometimes necessary when doing cut-aways at intervals matching the grid's divisions).	(boolian)
		SphereGrid_color		// The color of the grid lines. (color definition)                                                                                                                         
	)

	#local SphereGrid_thickness = SphereGrid_thickness/SphereGrid_radius;

	#declare SphereGrid_Object = union
	{

		#if (SphereGrid_offset = 1)
			#local SphereGrid_i = 1/SphereGrid_radii/2;
		#else
			#local SphereGrid_i = 0;
		#end
		#while(SphereGrid_i < 0.999999)
			difference
			{
				sphere
				{
					0, SphereGrid_i + SphereGrid_thickness/2
				}
				sphere
				{
					0, SphereGrid_i - SphereGrid_thickness/2
				}
			}
//			#debug concat("i = ", str(SphereGrid_i, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 1/SphereGrid_radii;
		#end

		#if (SphereGrid_offset = 1)
			#local SphereGrid_i = 360/SphereGrid_longt/2;
		#else
			#local SphereGrid_i = 0;
		#end
		#while(SphereGrid_i < 359.999999)
			intersection
			{
				plane
				{
					x, SphereGrid_thickness/2
				}
				plane
				{
					-x, SphereGrid_thickness/2
				}
				rotate y * SphereGrid_i
			}
//			#debug concat("i = ", str(SphereGrid_i, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 360/SphereGrid_longt;
		#end

		#if (SphereGrid_offset = 1)
			#local SphereGrid_i = 180/SphereGrid_lattt/2;
		#else
			#local SphereGrid_i = 0;
		#end
		#while(SphereGrid_i < 179.999999)
			#if (SphereGrid_i <= 90)
				difference
				{
					cone
					{
						0, 0,
						y, 1/tand(SphereGrid_i)
						translate -y * 1/cosd(SphereGrid_i) * SphereGrid_thickness/2
					}
					cone
					{
						0, 0,
						y, 1/tand(SphereGrid_i)
						translate y * 1/cosd(SphereGrid_i) * SphereGrid_thickness/2
					}
				}
			#else
				difference
				{
					cone
					{
						0, 0,
						-y, 1/tand(SphereGrid_i)
						translate y * 1/cosd(SphereGrid_i) * SphereGrid_thickness/2
					}
					cone
					{
						0, 0,
						-y, 1/tand(SphereGrid_i)
						translate -y * 1/cosd(SphereGrid_i) * SphereGrid_thickness/2
					}
				}
			#end
//			#debug concat("i = ", str(SphereGrid_i, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 180/SphereGrid_lattt;
		#end
		scale SphereGrid_radius
		translate SphereGrid_center
	}
	
	#declare SphereGrid_Pigment = pigment
	{
		object
		{
			SphereGrid_Object
			color rgbt 1
			SphereGrid_color
		}
	}

#end