// Title: Cylinder grid macro v1.0
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/01/11
// Last Updated: 2008/01/18
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"

#macro CylinderGrid_Macro
	(
		CylinderGrid_radii,		// The number of radial divisions.	(integer)
		CylinderGrid_longt,		// The number of longitudinal divisions.	(integer)
		CylinderGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		CylinderGrid_radius,		// The radius of the cylinder.	(float)
		CylinderGrid_height,		// The height of the cylinder.	(float)
		CylinderGrid_center,		// The center coordinates of the cylinder. (vector)
		CylinderGrid_thickness,		// The thickness of the grid lines. (float)
		CylinderGrid_offset,		// Determines whether the divisions are offset by half the amount (sometimes necessary when doing cut-aways at intervals matching the grid's divisions).	(boolian)
	)

	#local CylinderGrid_thickness = CylinderGrid_thickness/CylinderGrid_radius;
	#local CylinderGrid_bounds = cylinder
	{
		0, <0,CylinderGrid_height,0,>, CylinderGrid_radius
	}

	#declare CylinderGrid_Object = union
	{

		#local CylinderGrid_increment = 1/CylinderGrid_radii;
		#local CylinderGrid_i = 0;
		#local CylinderGrid_start = 0;
		#if (CylinderGrid_offset = on)
			#local CylinderGrid_start = CylinderGrid_increment/2;
		#end
		#while(CylinderGrid_i < CylinderGrid_radii)
			#local CylinderGrid_value = CylinderGrid_radius * (CylinderGrid_start + CylinderGrid_i * CylinderGrid_increment);
			difference
			{
				cylinder
				{
					0, y, CylinderGrid_value + CylinderGrid_thickness/2
					
				}
				cylinder
				{
					0, y, CylinderGrid_value - CylinderGrid_thickness/2
				}
				bounded_by
				{
					CylinderGrid_bounds
				}
			}
//			#debug concat("value = ", str(CylinderGrid_value, 0, -1),"\n")
			#local CylinderGrid_i = CylinderGrid_i + 1;
		#end

		#local CylinderGrid_increment = 1/CylinderGrid_longt;
		#local CylinderGrid_i = 0;
		#local CylinderGrid_start = 0;
		#if (CylinderGrid_offset = on)
			#local CylinderGrid_start = CylinderGrid_increment/2;
		#end
		#while(CylinderGrid_i < CylinderGrid_longt)
			#local CylinderGrid_value = 360 * (CylinderGrid_start + CylinderGrid_i * CylinderGrid_increment);
			intersection
			{
				plane
				{
					x, CylinderGrid_thickness/2
				}
				plane
				{
					-x, CylinderGrid_thickness/2
				}
				rotate y * CylinderGrid_value
				bounded_by
				{
					CylinderGrid_bounds
				}
			}
//			#debug concat("value = ", str(CylinderGrid_value, 0, -1),"\n")
			#local CylinderGrid_i = CylinderGrid_i + 1;
		#end

		#local CylinderGrid_increment = 1/CylinderGrid_lattt;
		#local CylinderGrid_i = 0;
		#local CylinderGrid_start = 0;
		#if (CylinderGrid_offset = on)
			#local CylinderGrid_start = CylinderGrid_increment/2;
		#end
		#while(CylinderGrid_i < CylinderGrid_lattt)
			#local CylinderGrid_value = CylinderGrid_height * (CylinderGrid_start + CylinderGrid_i * CylinderGrid_increment);
			intersection
			{
				plane
				{
					y, CylinderGrid_thickness/2
				}
				plane
				{
					-y, CylinderGrid_thickness/2
				}
				translate y * CylinderGrid_value
				bounded_by
				{
					CylinderGrid_bounds
				}
			}
//			#debug concat("value = ", str(CylinderGrid_value, 0, -1),"\n")
			#local CylinderGrid_i = CylinderGrid_i + 1;
		#end
		translate CylinderGrid_center
	}
#end