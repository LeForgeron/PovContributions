// Title: Cone grid macro v1.00
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/06/22
// Last Updated: 2008/06/22
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"

#macro ConeGrid_Macro
	(
		ConeGrid_radii,		// The number of radial divisions.		(integer)
		ConeGrid_longt,		// The number of longitudinal divisions.	(integer)
		ConeGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		ConeGrid_radius,		// The radius of each cone.			(float)
		ConeGrid_height,		// The height of each cone.			(float)
		ConeGrid_center,		// The center coordinates of the double-cone.	(vector)
		ConeGrid_thickness,	// The thickness of the grid lines.		(float)
		ConeGrid_offset,		// Determines whether the divisions are offset by half the amount (sometimes necessary when doing cut-aways at intervals matching the grid's divisions).	(boolian)
	)

	#local ConeGrid_thickness = ConeGrid_thickness/ConeGrid_radius;
	#local ConeGrid_bounds = union
	{
		cone
		{
			0, ConeGrid_radius, <0,+ConeGrid_height,0,>, 0
		}
	}

	#declare ConeGrid_Object = union
	{

		#local ConeGrid_increment = 1/ConeGrid_radii;
		#local ConeGrid_i = 0;
		#local ConeGrid_start = 0;
		#if (ConeGrid_offset = on)
			#local ConeGrid_start = ConeGrid_increment/2;
		#end
		#while(ConeGrid_i < ConeGrid_radii)
			#local ConeGrid_value = ConeGrid_radius * (ConeGrid_start + ConeGrid_i * ConeGrid_increment);
			#local ConeGrid_angle = atan2d(ConeGrid_value, ConeGrid_height);
			#local ConeGrid_offsl = ConeGrid_thickness/2 * 1/cosd(ConeGrid_angle);
			#local ConeGrid_offsv = ConeGrid_thickness/2 * 1/cosd(90 - ConeGrid_angle);
			difference
			{
				cone
				{
					0, ConeGrid_value + ConeGrid_offsl, <0,+ConeGrid_height+ConeGrid_offsv,0,>, 0
				}
				cone
				{
					0, ConeGrid_value - ConeGrid_offsl, <0,+ConeGrid_height-ConeGrid_offsv,0,>, 0
				}
				bounded_by
				{
					ConeGrid_bounds
				}
			}
//			#debug concat("radii_value = ", str(ConeGrid_value, 0, -1),"\n")
			#local ConeGrid_i = ConeGrid_i + 1;
		#end

		#local ConeGrid_increment = 1/ConeGrid_longt;
		#local ConeGrid_i = 0;
		#local ConeGrid_start = 0;
		#if (ConeGrid_offset = on)
			#local ConeGrid_start = ConeGrid_increment/2;
		#end
		#while(ConeGrid_i < ConeGrid_longt)
			#local ConeGrid_value = 360 * (ConeGrid_start + ConeGrid_i * ConeGrid_increment);
			box
			{
				<2*ConeGrid_radius, 2*ConeGrid_radius, ConeGrid_thickness/2,>, <0, -2*ConeGrid_radius, -ConeGrid_thickness/2,>
				rotate y * ConeGrid_value
				bounded_by
				{
					ConeGrid_bounds
				}
			}
//			#debug concat("longt_value = ", str(ConeGrid_value, 0, -1),"\n")
			#local ConeGrid_i = ConeGrid_i + 1;
		#end

		#local ConeGrid_increment = 1/ConeGrid_lattt;
		#local ConeGrid_i = 0;
		#local ConeGrid_start = 0;
		#if (ConeGrid_offset = on)
			#local ConeGrid_start = ConeGrid_increment/2;
		#end
		#while(ConeGrid_i < ConeGrid_lattt)
			#local ConeGrid_value = ConeGrid_height * (ConeGrid_start + ConeGrid_i * ConeGrid_increment);
			box
			{
				<ConeGrid_radius,ConeGrid_thickness/2,ConeGrid_radius,>,<-ConeGrid_radius,-ConeGrid_thickness/2,-ConeGrid_radius,>
				bounded_by
				{
					ConeGrid_bounds
				}
				translate y * ConeGrid_value
			}
//			#debug concat("lattt_value = ", str(ConeGrid_value, 0, -1),"\n")
			#local ConeGrid_i = ConeGrid_i + 1;
		#end
		translate ConeGrid_center
	}
#end