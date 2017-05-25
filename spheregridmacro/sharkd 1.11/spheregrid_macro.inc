// Title: Sphere grid macro v1.11
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
	)

	#local SphereGrid_thickness = SphereGrid_thickness/SphereGrid_radius;

	#declare SphereGrid_Object = union
	{

		#local SphereGrid_increment = 1/SphereGrid_radii;
		#local SphereGrid_i = 0;
		#local SphereGrid_start = 0;
		#local SphereGrid_max = SphereGrid_radii;
		#if (SphereGrid_offset = on)
			#local SphereGrid_start = SphereGrid_increment/2;
			#local SphereGrid_max = SphereGrid_max - 1;
		#end
		#while(SphereGrid_i < SphereGrid_max)
			#local SphereGrid_value = 1 * (SphereGrid_start + SphereGrid_i * SphereGrid_increment);
			difference
			{
				sphere
				{
					0, SphereGrid_value + SphereGrid_thickness/2
				}
				sphere
				{
					0, SphereGrid_value - SphereGrid_thickness/2
				}
			}
//			#debug concat("value = ", str(SphereGrid_value, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 1;
		#end

		#local SphereGrid_increment = 1/SphereGrid_longt;
		#local SphereGrid_i = 0;
		#local SphereGrid_start = 0;
		#local SphereGrid_max = SphereGrid_longt;
		#if (SphereGrid_offset = on)
			#local SphereGrid_start = SphereGrid_increment/2;
			#local SphereGrid_max = SphereGrid_max - 1;
		#end
		#while(SphereGrid_i < SphereGrid_max)
			#local SphereGrid_value = 360 * (SphereGrid_start + SphereGrid_i * SphereGrid_increment);
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
				rotate y * SphereGrid_value
			}
//			#debug concat("value = ", str(SphereGrid_value, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 1;
		#end

		#local SphereGrid_increment = 1/SphereGrid_lattt;
		#local SphereGrid_i = 0;
		#local SphereGrid_start = 0;
		#local SphereGrid_max = SphereGrid_lattt;
		#if (SphereGrid_offset = on)
			#local SphereGrid_start = SphereGrid_increment/2;
			#local SphereGrid_max = SphereGrid_max - 1;
		#end
		#while(SphereGrid_i < SphereGrid_max)
			#local SphereGrid_value = 180 * (SphereGrid_start + SphereGrid_i * SphereGrid_increment);
			#if (SphereGrid_i <= SphereGrid_lattt/2)
				difference
				{
					cone
					{
						0, 0,
						y, 1/tand(SphereGrid_value)
						translate -y * 1/cosd(SphereGrid_value) * SphereGrid_thickness/2
					}
					cone
					{
						0, 0,
						y, 1/tand(SphereGrid_value)
						translate y * 1/cosd(SphereGrid_value) * SphereGrid_thickness/2
					}
				}
			#else
				difference
				{
					cone
					{
						0, 0,
						-y, 1/tand(SphereGrid_value)
						translate y * 1/cosd(SphereGrid_value) * SphereGrid_thickness/2
					}
					cone
					{
						0, 0,
						-y, 1/tand(SphereGrid_i)
						translate -y * 1/cosd(SphereGrid_value) * SphereGrid_thickness/2
					}
				}
			#end
//			#debug concat("value = ", str(SphereGrid_value, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 1;
		#end
		scale SphereGrid_radius
		translate SphereGrid_center
	}
#end