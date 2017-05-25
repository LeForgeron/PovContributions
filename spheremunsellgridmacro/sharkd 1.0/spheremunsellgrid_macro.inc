// Title: Sphere grid macro v1.2
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/01/10
// Last Updated: 2008/01/14
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"
#include "shapes.inc"

#macro SphereMunsellGrid_Macro
	(
		SphereMunsellGrid_radii,		// The number of radial divisions.		(integer)
		SphereMunsellGrid_longt,		// The number of longitudinal divisions.	(integer)
		SphereMunsellGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		SphereMunsellGrid_radius,		// The radius of the sphere.			(float)
		SphereMunsellGrid_center,		// The center coordinates of the sphere.	(vector)
		SphereMunsellGrid_thickness,		// The thickness of the grid lines.		(float)
		SphereMunsellGrid_offset,		// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SphereMunsellGrid_endcap,		// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SphereMunsellGrid_thickness = SphereMunsellGrid_thickness/SphereMunsellGrid_radius;
	#local SphereMunsellGrid_bounds = sphere
	{
		0, SphereMunsellGrid_radius * 1.01
	}

	#declare SphereMunsellGrid_Object = union
	{

		#local SphereMunsellGrid_increment = 1/SphereMunsellGrid_radii;
		#local SphereMunsellGrid_i = 0;
		#local SphereMunsellGrid_start = 0;
		#if (SphereMunsellGrid_offset = on)
			#local SphereMunsellGrid_start = SphereMunsellGrid_increment/2;
		#end
		#while(SphereMunsellGrid_i < SphereMunsellGrid_radii)
			#local SphereMunsellGrid_value = SphereMunsellGrid_radius * (SphereMunsellGrid_start + SphereMunsellGrid_i * SphereMunsellGrid_increment);
			difference
			{
				object
				{
					Spheroid(0, <SphereMunsellGrid_value + SphereMunsellGrid_thickness/2,SphereMunsellGrid_radius,SphereMunsellGrid_value + SphereMunsellGrid_thickness/2,>)
				}
				object
				{
					Spheroid(0, <SphereMunsellGrid_value - SphereMunsellGrid_thickness/2,SphereMunsellGrid_radius,SphereMunsellGrid_value - SphereMunsellGrid_thickness/2,>)
				}
				bounded_by
				{
					SphereMunsellGrid_bounds
				}
			}
//			#debug concat("radii_value = ", str(SphereMunsellGrid_value, 0, -1),"\n")
			#local SphereMunsellGrid_i = SphereMunsellGrid_i + 1;
		#end

		#local SphereMunsellGrid_increment = 1/SphereMunsellGrid_longt;
		#local SphereMunsellGrid_i = 0;
		#local SphereMunsellGrid_start = 0;
		#if (SphereMunsellGrid_offset = on)
			#local SphereMunsellGrid_start = SphereMunsellGrid_increment/2;
		#end
		#while(SphereMunsellGrid_i < SphereMunsellGrid_longt)
			#local SphereMunsellGrid_value = 360 * (SphereMunsellGrid_start + SphereMunsellGrid_i * SphereMunsellGrid_increment);
			box
			{
				<2*SphereMunsellGrid_radius, 2*SphereMunsellGrid_radius, SphereMunsellGrid_thickness/2,>, <0, -2*SphereMunsellGrid_radius, -SphereMunsellGrid_thickness/2,>
				rotate y * SphereMunsellGrid_value
			}

//			#debug concat("longt_value = ", str(SphereMunsellGrid_value, 0, -1),"\n")
			#local SphereMunsellGrid_i = SphereMunsellGrid_i + 1;
		#end

		#local SphereMunsellGrid_increment = 1/SphereMunsellGrid_lattt;
		#local SphereMunsellGrid_i = 0;
		#if (SphereMunsellGrid_endcap = on)
			#local SphereMunsellGrid_start = 0;
			#local SphereMunsellGrid_finish = SphereMunsellGrid_lattt;
		#else
			#local SphereMunsellGrid_start = SphereMunsellGrid_increment;
			#local SphereMunsellGrid_finish = SphereMunsellGrid_lattt - 2;
		#end
		#if (SphereMunsellGrid_offset = on)
			#local SphereMunsellGrid_start = SphereMunsellGrid_increment/2;
			#local SphereMunsellGrid_finish = SphereMunsellGrid_lattt;
		#end
		#while(SphereMunsellGrid_i <= SphereMunsellGrid_finish)
			#local SphereMunsellGrid_value = -SphereMunsellGrid_radius + 2*SphereMunsellGrid_radius*(SphereMunsellGrid_start + SphereMunsellGrid_i * SphereMunsellGrid_increment);
			box
			{
				<SphereMunsellGrid_radius,SphereMunsellGrid_thickness/2,SphereMunsellGrid_radius,>,<-SphereMunsellGrid_radius,-SphereMunsellGrid_thickness/2,-SphereMunsellGrid_radius,>
				bounded_by
				{
					SphereMunsellGrid_bounds
				}
				translate y * SphereMunsellGrid_value
			}
//			#debug concat("lattt_value = ", str(SphereMunsellGrid_value, 0, -1),"\n")
			#local SphereMunsellGrid_i = SphereMunsellGrid_i + 1;
		#end
		translate SphereMunsellGrid_center
	}
#end