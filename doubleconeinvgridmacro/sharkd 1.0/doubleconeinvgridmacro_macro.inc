// Title: Double-cone grid macro v1.00
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/06/22
// Last Updated: 2008/06/22
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"

#macro DoubleConeInvGrid_Macro
	(
		DoubleConeInvGrid_radii,		// The number of radial divisions.		(integer)
		DoubleConeInvGrid_longt,		// The number of longitudinal divisions.	(integer)
		DoubleConeInvGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		DoubleConeInvGrid_radius,		// The radius of each cone.			(float)
		DoubleConeInvGrid_height,		// The height of each cone.			(float)
		DoubleConeInvGrid_center,		// The center coordinates of the double-cone.	(vector)
		DoubleConeInvGrid_thickness,		// The thickness of the grid lines.		(float)
		DoubleConeInvGrid_offset,		// Determines whether the divisions are offset by half the amount (sometimes necessary when doing cut-aways at intervals matching the grid's divisions).	(boolian)
	)

	#local DoubleConeInvGrid_thickness = DoubleConeInvGrid_thickness/DoubleConeInvGrid_radius;
	#local DoubleConeInvGrid_bounds = union
	{
		cone
		{
			0, 0, <0,+DoubleConeInvGrid_height,0,>, DoubleConeInvGrid_radius
		}
		cone
		{
			0, 0, <0,-DoubleConeInvGrid_height,0,>, DoubleConeInvGrid_radius
		}
	}

	#declare DoubleConeInvGrid_Object = union
	{

		#local DoubleConeInvGrid_increment = 1/DoubleConeInvGrid_radii;
		#local DoubleConeInvGrid_i = 0;
		#local DoubleConeInvGrid_start = 0;
		#if (DoubleConeInvGrid_offset = on)
			#local DoubleConeInvGrid_start = DoubleConeInvGrid_increment/2;
		#end
		#while(DoubleConeInvGrid_i < DoubleConeInvGrid_radii)
			#local DoubleConeInvGrid_value = DoubleConeInvGrid_radius * (DoubleConeInvGrid_start + DoubleConeInvGrid_i * DoubleConeInvGrid_increment);
			#local DoubleConeInvGrid_angle = atan2d(DoubleConeInvGrid_value, DoubleConeInvGrid_height);
			#local DoubleConeInvGrid_offsl = DoubleConeInvGrid_thickness/2 * 1/cosd(DoubleConeInvGrid_angle);
			#local DoubleConeInvGrid_offsv = DoubleConeInvGrid_thickness/2 * 1/cosd(90 - DoubleConeInvGrid_angle);
			difference
			{
				union
				{
					cone
					{
						<0,-DoubleConeInvGrid_offsv,0,>, 0, <0,+DoubleConeInvGrid_height,0,>, DoubleConeInvGrid_value + DoubleConeInvGrid_offsl
					}
					cone
					{
						<0,+DoubleConeInvGrid_offsv,0,>, 0, <0,-DoubleConeInvGrid_height,0,>, DoubleConeInvGrid_value + DoubleConeInvGrid_offsl
					}
				}
				union
				{
					cone
					{
						<0,+DoubleConeInvGrid_offsv,0,>, 0, <0,+DoubleConeInvGrid_height,0,>, DoubleConeInvGrid_value - DoubleConeInvGrid_offsl
					}
					cone
					{
						<0,-DoubleConeInvGrid_offsv,0,>, 0, <0,-DoubleConeInvGrid_height,0,>, DoubleConeInvGrid_value - DoubleConeInvGrid_offsl
					}
				}
				bounded_by
				{
					DoubleConeInvGrid_bounds
				}
			}
//			#debug concat("radii_value = ", str(DoubleConeInvGrid_value, 0, -1),"\n")
			#local DoubleConeInvGrid_i = DoubleConeInvGrid_i + 1;
		#end

		#local DoubleConeInvGrid_increment = 1/DoubleConeInvGrid_longt;
		#local DoubleConeInvGrid_i = 0;
		#local DoubleConeInvGrid_start = 0;
		#if (DoubleConeInvGrid_offset = on)
			#local DoubleConeInvGrid_start = DoubleConeInvGrid_increment/2;
		#end
		#while(DoubleConeInvGrid_i < DoubleConeInvGrid_longt)
			#local DoubleConeInvGrid_value = 360 * (DoubleConeInvGrid_start + DoubleConeInvGrid_i * DoubleConeInvGrid_increment);
			box
			{
				<2*DoubleConeInvGrid_radius, 2*DoubleConeInvGrid_radius, DoubleConeInvGrid_thickness/2,>, <0, -2*DoubleConeInvGrid_radius, -DoubleConeInvGrid_thickness/2,>
				rotate y * DoubleConeInvGrid_value
				bounded_by
				{
					DoubleConeInvGrid_bounds
				}
			}
//			#debug concat("longt_value = ", str(DoubleConeInvGrid_value, 0, -1),"\n")
			#local DoubleConeInvGrid_i = DoubleConeInvGrid_i + 1;
		#end

		#local DoubleConeInvGrid_increment = 1/DoubleConeInvGrid_lattt;
		#local DoubleConeInvGrid_i = 0;
		#local DoubleConeInvGrid_start = 0;
		#if (DoubleConeInvGrid_offset = on)
			#local DoubleConeInvGrid_start = DoubleConeInvGrid_start + DoubleConeInvGrid_increment/2;
		#end
		#while(DoubleConeInvGrid_i < DoubleConeInvGrid_lattt)
			#local DoubleConeInvGrid_value = -DoubleConeInvGrid_height + 2*DoubleConeInvGrid_height * (DoubleConeInvGrid_start + DoubleConeInvGrid_i * DoubleConeInvGrid_increment);
			box
			{
				<DoubleConeInvGrid_radius,DoubleConeInvGrid_thickness/2,DoubleConeInvGrid_radius,>,<-DoubleConeInvGrid_radius,-DoubleConeInvGrid_thickness/2,-DoubleConeInvGrid_radius,>
				bounded_by
				{
					DoubleConeInvGrid_bounds
				}
				translate y * DoubleConeInvGrid_value
			}
//			#debug concat("lattt_value = ", str(DoubleConeInvGrid_value, 0, -1),"\n")
			#local DoubleConeInvGrid_i = DoubleConeInvGrid_i + 1;
		#end
		translate DoubleConeInvGrid_center
	}
#end