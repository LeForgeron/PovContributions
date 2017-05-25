// Title: Double-cone grid macro v1.00
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/06/22
// Last Updated: 2008/06/22
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"

#macro DoubleConeGrid_Macro
	(
		DoubleConeGrid_radii,		// The number of radial divisions.		(integer)
		DoubleConeGrid_longt,		// The number of longitudinal divisions.	(integer)
		DoubleConeGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		DoubleConeGrid_radius,		// The radius of each cone.			(float)
		DoubleConeGrid_height,		// The height of each cone.			(float)
		DoubleConeGrid_center,		// The center coordinates of the double-cone.	(vector)
		DoubleConeGrid_thickness,	// The thickness of the grid lines.		(float)
		DoubleConeGrid_offset,		// Determines whether the divisions are offset by half the amount (sometimes necessary when doing cut-aways at intervals matching the grid's divisions).	(boolian)
	)

	#local DoubleConeGrid_thickness = DoubleConeGrid_thickness/DoubleConeGrid_radius;
	#local DoubleConeGrid_bounds = union
	{
		cone
		{
			0, DoubleConeGrid_radius, <0,+DoubleConeGrid_height,0,>, 0
		}
		cone
		{
			0, DoubleConeGrid_radius, <0,-DoubleConeGrid_height,0,>, 0
		}
	}

	#declare DoubleConeGrid_Object = union
	{

		#local DoubleConeGrid_increment = 1/DoubleConeGrid_radii;
		#local DoubleConeGrid_i = 0;
		#local DoubleConeGrid_start = 0;
		#if (DoubleConeGrid_offset = on)
			#local DoubleConeGrid_start = DoubleConeGrid_increment/2;
		#end
		#while(DoubleConeGrid_i < DoubleConeGrid_radii)
			#local DoubleConeGrid_value = DoubleConeGrid_radius * (DoubleConeGrid_start + DoubleConeGrid_i * DoubleConeGrid_increment);
			#local DoubleConeGrid_angle = atan2d(DoubleConeGrid_value, DoubleConeGrid_height);
			#local DoubleConeGrid_offsl = DoubleConeGrid_thickness/2 * 1/cosd(DoubleConeGrid_angle);
			#local DoubleConeGrid_offsv = DoubleConeGrid_thickness/2 * 1/cosd(90 - DoubleConeGrid_angle);
			difference
			{
				union
				{
					cone
					{
						0, DoubleConeGrid_value + DoubleConeGrid_offsl, <0,+DoubleConeGrid_height+DoubleConeGrid_offsv,0,>, 0
					}
					cone
					{
						0, DoubleConeGrid_value + DoubleConeGrid_offsl, <0,-DoubleConeGrid_height-DoubleConeGrid_offsv,0,>, 0
					}
				}
				union
				{
					cone
					{
						0, DoubleConeGrid_value - DoubleConeGrid_offsl, <0,+DoubleConeGrid_height-DoubleConeGrid_offsv,0,>, 0
					}
					cone
					{
						0, DoubleConeGrid_value - DoubleConeGrid_offsl, <0,-DoubleConeGrid_height+DoubleConeGrid_offsv,0,>, 0
					}
				}
				bounded_by
				{
					DoubleConeGrid_bounds
				}
			}
//			#debug concat("radii_value = ", str(DoubleConeGrid_value, 0, -1),"\n")
			#local DoubleConeGrid_i = DoubleConeGrid_i + 1;
		#end

		#local DoubleConeGrid_increment = 1/DoubleConeGrid_longt;
		#local DoubleConeGrid_i = 0;
		#local DoubleConeGrid_start = 0;
		#if (DoubleConeGrid_offset = on)
			#local DoubleConeGrid_start = DoubleConeGrid_increment/2;
		#end
		#while(DoubleConeGrid_i < DoubleConeGrid_longt)
			#local DoubleConeGrid_value = 360 * (DoubleConeGrid_start + DoubleConeGrid_i * DoubleConeGrid_increment);
			box
			{
				<2*DoubleConeGrid_radius, 2*DoubleConeGrid_radius, DoubleConeGrid_thickness/2,>, <0, -2*DoubleConeGrid_radius, -DoubleConeGrid_thickness/2,>
				rotate y * DoubleConeGrid_value
				bounded_by
				{
					DoubleConeGrid_bounds
				}
			}
//			#debug concat("longt_value = ", str(DoubleConeGrid_value, 0, -1),"\n")
			#local DoubleConeGrid_i = DoubleConeGrid_i + 1;
		#end

		#local DoubleConeGrid_increment = 1/DoubleConeGrid_lattt;
		#local DoubleConeGrid_i = 0;
		#local DoubleConeGrid_start = 0;
		#if (DoubleConeGrid_offset = on)
			#local DoubleConeGrid_start = DoubleConeGrid_increment/2;
		#end
		#while(DoubleConeGrid_i < DoubleConeGrid_lattt)
			#local DoubleConeGrid_value = -DoubleConeGrid_height + 2*DoubleConeGrid_height * (DoubleConeGrid_start + DoubleConeGrid_i * DoubleConeGrid_increment);
			box
			{
				<DoubleConeGrid_radius,DoubleConeGrid_thickness/2,DoubleConeGrid_radius,>,<-DoubleConeGrid_radius,-DoubleConeGrid_thickness/2,-DoubleConeGrid_radius,>
				bounded_by
				{
					DoubleConeGrid_bounds
				}
				translate y * DoubleConeGrid_value
			}
//			#debug concat("lattt_value = ", str(DoubleConeGrid_value, 0, -1),"\n")
			#local DoubleConeGrid_i = DoubleConeGrid_i + 1;
		#end
		translate DoubleConeGrid_center
	}
#end