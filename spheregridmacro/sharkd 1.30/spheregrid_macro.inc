// Title: Sphere grid macro v1.30
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008-01-10
// Last Updated: 2008-06-22
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"

#macro SphereGrid_Macro
	(
		SphereGrid_radii,		// The number of radial divisions.		(integer)
		SphereGrid_longt,		// The number of longitudinal divisions.	(integer)
		SphereGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		SphereGrid_radius,		// The radius of the sphere.			(float)
		SphereGrid_center,		// The center coordinates of the sphere.	(vector)
		SphereGrid_thickness,		// The thickness of the grid lines.		(float)
		SphereGrid_offset,		// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SphereGrid_endcap,		// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SphereGrid_thickness = SphereGrid_thickness/SphereGrid_radius;
	#local SphereGrid_bounds = sphere
	{
		0, SphereGrid_radius * 1.01
	}

	#declare SphereGrid_Object = union
	{

		#local SphereGrid_increment = 1/SphereGrid_radii;
		#local SphereGrid_i = 0;
		#local SphereGrid_start = 0;
		#if (SphereGrid_offset = on)
			#local SphereGrid_start = SphereGrid_increment/2;
		#end
		#while(SphereGrid_i < SphereGrid_radii)
			#local SphereGrid_value = SphereGrid_radius * (SphereGrid_start + SphereGrid_i * SphereGrid_increment);
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
				bounded_by
				{
					SphereGrid_bounds
				}
			}
//			#debug concat("radii_value = ", str(SphereGrid_value, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 1;
		#end

		#local SphereGrid_increment = 1/SphereGrid_longt;
		#local SphereGrid_i = 0;
		#local SphereGrid_start = 0;
		#if (SphereGrid_offset = on)
			#local SphereGrid_start = SphereGrid_increment/2;
		#end
		#while(SphereGrid_i < SphereGrid_longt)
			#local SphereGrid_value = 360 * (SphereGrid_start + SphereGrid_i * SphereGrid_increment);
			box
			{
				<2*SphereGrid_radius, 2*SphereGrid_radius, SphereGrid_thickness/2,>, <0, -2*SphereGrid_radius, -SphereGrid_thickness/2,>
				rotate y * SphereGrid_value
			}

//			#debug concat("longt_value = ", str(SphereGrid_value, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 1;
		#end

		#local SphereGrid_increment = 1/SphereGrid_lattt;
		#local SphereGrid_i = 0;
		#if (SphereGrid_endcap = on)
			#local SphereGrid_start = 0;
			#local SphereGrid_finish = SphereGrid_lattt;
		#else
			#local SphereGrid_start = SphereGrid_increment;
			#local SphereGrid_finish = SphereGrid_lattt - 2;
		#end
		#if (SphereGrid_offset = on)
			#local SphereGrid_start = SphereGrid_increment/2;
			#local SphereGrid_finish = SphereGrid_lattt;
		#end
		#while(SphereGrid_i <= SphereGrid_finish)
			#local SphereGrid_value = 180 * (SphereGrid_start + SphereGrid_i * SphereGrid_increment);
			#if (SphereGrid_i < SphereGrid_lattt/2)
				difference
				{
					cone
					{
						0, 0,
						2*SphereGrid_radius*y, 2*SphereGrid_radius*abs(tand(SphereGrid_value))
						translate SphereGrid_radius*-y * 1/abs(sind(SphereGrid_value)) * SphereGrid_thickness/2
					}
					cone
					{
						0, 0,
						2*SphereGrid_radius*y, 2*SphereGrid_radius*abs(tand(SphereGrid_value))
						translate SphereGrid_radius*y * 1/abs(sind(SphereGrid_value)) * SphereGrid_thickness/2
					}
					bounded_by
					{
						SphereGrid_bounds
					}
				}
			#else
				#if (SphereGrid_i = SphereGrid_lattt/2)
					cylinder
					{
						<0,-SphereGrid_thickness/2,0,>, <0,SphereGrid_thickness/2,0,>, 2*SphereGrid_radius
						bounded_by
						{
							SphereGrid_bounds
						}
					}
				#else
					difference
					{
						cone
						{
							0, 0,
							2*SphereGrid_radius*-y, 2*SphereGrid_radius*abs(tand(SphereGrid_value))
							translate SphereGrid_radius*y * 1/abs(sind(SphereGrid_value)) * SphereGrid_thickness/2
						}
						cone
						{
							0, 0,
							2*SphereGrid_radius*-y, 2*SphereGrid_radius*abs(tand(SphereGrid_value))
							translate SphereGrid_radius*-y * 1/abs(sind(SphereGrid_value)) * SphereGrid_thickness/2
						}
						bounded_by
						{
							SphereGrid_bounds
						}
					}
				#end
			#end
//			#debug concat("lattt_value = ", str(SphereGrid_value, 0, -1),"\n")
			#local SphereGrid_i = SphereGrid_i + 1;
		#end
		translate SphereGrid_center
	}
#end