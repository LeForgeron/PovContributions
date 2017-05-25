// Title: Shape grid macro v1.01
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/06/22
// Last Updated: 2008/06/22
// This file is licensed under the terms of the CC-LGPL.

#include "math.inc"
#ifndef (SGrid_Debug) #declare SGrid_Debug = false; #end

#macro SGrid_Cone_Macro
	(
		SGrid_Cone_radii,	// The number of radial divisions.		(integer)
		SGrid_Cone_longt,	// The number of longitudinal divisions.	(integer)
		SGrid_Cone_lattt,	// The number of lattitudinal divisions.	(integer)
		SGrid_Cone_radius,	// The radius of each cone.			(float)
		SGrid_Cone_height,	// The height of each cone.			(float)
		SGrid_Cone_center,	// The center coordinates of the double-cone.	(vector)
		SGrid_Cone_thickness,	// The thickness of the grid lines.		(float)
		SGrid_Cone_offset,	// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SGrid_Cone_endcap,	// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SGrid_Cone_thickness = SGrid_Cone_thickness/SGrid_Cone_radius;
	#local SGrid_Cone_bounds = cone {0, SGrid_Cone_radius, <0,SGrid_Cone_height,0,>, 0}

	union
	{

		#local SGrid_Cone_increment = 1/SGrid_Cone_radii;
		#local SGrid_Cone_i = 0;
		#local SGrid_Cone_start = 0;
		#if (SGrid_Cone_offset = on)
			#local SGrid_Cone_start = SGrid_Cone_increment/2;
		#end
		#while(SGrid_Cone_i < SGrid_Cone_radii)
			#local SGrid_Cone_value = SGrid_Cone_radius * (SGrid_Cone_start + SGrid_Cone_i * SGrid_Cone_increment);
			#local SGrid_Cone_angle = atan2d(SGrid_Cone_value, SGrid_Cone_height);
			#local SGrid_Cone_offsl = SGrid_Cone_thickness/2 * 1/cosd(SGrid_Cone_angle);
			#local SGrid_Cone_offsv = SGrid_Cone_thickness/2 * 1/cosd(90 - SGrid_Cone_angle);
			difference
			{
				cone {0, SGrid_Cone_value + SGrid_Cone_offsl, <0,SGrid_Cone_height+SGrid_Cone_offsv,0,>, 0}
				cone {0, SGrid_Cone_value - SGrid_Cone_offsl, <0,SGrid_Cone_height-SGrid_Cone_offsv,0,>, 0}
				bounded_by {SGrid_Cone_bounds}
			}
//			#debug concat("cone_radii_value = ", str(SGrid_Cone_value, 0, -1),"\n")
			#local SGrid_Cone_i = SGrid_Cone_i + 1;
		#end

		#local SGrid_Cone_increment = 1/SGrid_Cone_longt;
		#local SGrid_Cone_i = 0;
		#local SGrid_Cone_start = 0;
		#if (SGrid_Cone_offset = on)
			#local SGrid_Cone_start = SGrid_Cone_increment/2;
		#end
		#while(SGrid_Cone_i < SGrid_Cone_longt)
			#local SGrid_Cone_value = 360 * (SGrid_Cone_start + SGrid_Cone_i * SGrid_Cone_increment);
			box
			{
				<2*SGrid_Cone_radius, 2*SGrid_Cone_radius, SGrid_Cone_thickness/2,>,
				<0, -2*SGrid_Cone_radius, -SGrid_Cone_thickness/2,>
				rotate y * SGrid_Cone_value
				bounded_by {SGrid_Cone_bounds}
			}
//			#debug concat("cone_longt_value = ", str(SGrid_Cone_value, 0, -1),"\n")
			#local SGrid_Cone_i = SGrid_Cone_i + 1;
		#end

		#local SGrid_Cone_increment = 1/SGrid_Cone_lattt;
		#local SGrid_Cone_i = 0;
		#if (SGrid_Cone_endcap = on)
			#local SGrid_Cone_start = 0;
			#local SGrid_Cone_finish = SGrid_Cone_radii + 1;
		#else
			#local SGrid_Cone_start = SGrid_Cone_increment;
			#local SGrid_Cone_finish = SGrid_Cone_lattt - 1;
		#end
		#if (SGrid_Cone_offset = on)
			#local SGrid_Cone_start = SGrid_Cone_increment/2;
			#local SGrid_Cone_finish = SGrid_Cone_lattt;
		#end
		#while(SGrid_Cone_i < SGrid_Cone_finish)
			#local SGrid_Cone_value = SGrid_Cone_height * (SGrid_Cone_start + SGrid_Cone_i * SGrid_Cone_increment);
			box
			{
				<SGrid_Cone_radius,SGrid_Cone_thickness/2,SGrid_Cone_radius,>,
				<-SGrid_Cone_radius,-SGrid_Cone_thickness/2,-SGrid_Cone_radius,>
				bounded_by {SGrid_Cone_bounds}
				translate y * SGrid_Cone_value
			}
//			#debug concat("cone_lattt_value = ", str(SGrid_Cone_value, 0, -1),"\n")
			#local SGrid_Cone_i = SGrid_Cone_i + 1;
		#end
		translate SGrid_Cone_center
	}
#end

#macro SGrid_Cylinder_Macro
	(
		SGrid_Cylinder_radii,		// The number of radial divisions.		(integer)
		SGrid_Cylinder_longt,		// The number of longitudinal divisions.	(integer)
		SGrid_Cylinder_lattt,		// The number of lattitudinal divisions.	(integer)
		SGrid_Cylinder_radius,		// The radius of the cylinder.			(float)
		SGrid_Cylinder_height,		// The height of the cylinder.			(float)
		SGrid_Cylinder_center,		// The center coordinates of the cylinder.	(vector)
		SGrid_Cylinder_thickness,		// The thickness of the grid lines.		(float)
		SGrid_Cylinder_offset,		// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SGrid_Cylinder_endcap,		// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SGrid_Cylinder_thickness = SGrid_Cylinder_thickness/SGrid_Cylinder_radius;
	#local SGrid_Cylinder_bounds = cylinder {0, <0,SGrid_Cylinder_height,0,>, SGrid_Cylinder_radius}

	union
	{

		#local SGrid_Cylinder_increment = 1/SGrid_Cylinder_radii;
		#local SGrid_Cylinder_i = 0;
		#local SGrid_Cylinder_start = 0;
		#if (SGrid_Cylinder_offset = on)
			#local SGrid_Cylinder_start = SGrid_Cylinder_increment/2;
		#end
		#while(SGrid_Cylinder_i < SGrid_Cylinder_radii)
			#local SGrid_Cylinder_value = SGrid_Cylinder_radius * (SGrid_Cylinder_start + SGrid_Cylinder_i * SGrid_Cylinder_increment);
			difference
			{
				cylinder {0, y, SGrid_Cylinder_value + SGrid_Cylinder_thickness/2}
				cylinder {0, y, SGrid_Cylinder_value - SGrid_Cylinder_thickness/2}
				bounded_by {SGrid_Cylinder_bounds}
			}
//			#debug concat("cylinder_radii_value = ", str(SGrid_Cylinder_value, 0, -1),"\n")
			#local SGrid_Cylinder_i = SGrid_Cylinder_i + 1;
		#end

		#local SGrid_Cylinder_increment = 1/SGrid_Cylinder_longt;
		#local SGrid_Cylinder_i = 0;
		#local SGrid_Cylinder_start = 0;
		#if (SGrid_Cylinder_offset = on)
			#local SGrid_Cylinder_start = SGrid_Cylinder_increment/2;
		#end
		#while(SGrid_Cylinder_i < SGrid_Cylinder_longt)
			#local SGrid_Cylinder_value = 360 * (SGrid_Cylinder_start + SGrid_Cylinder_i * SGrid_Cylinder_increment);
			box
			{
				<2*SGrid_Cylinder_radius, 2*SGrid_Cylinder_radius, SGrid_Cylinder_thickness/2,>,
				<0, -2*SGrid_Cylinder_radius, -SGrid_Cylinder_thickness/2,>
				rotate y * SGrid_Cylinder_value
			}
//			#debug concat("cylinder_logt_value = ", str(SGrid_Cylinder_value, 0, -1),"\n")
			#local SGrid_Cylinder_i = SGrid_Cylinder_i + 1;
		#end

		#local SGrid_Cylinder_increment = 1/SGrid_Cylinder_lattt;
		#local SGrid_Cylinder_i = 0;
		#if (SGrid_Cylinder_endcap = on)
			#local SGrid_Cylinder_start = 0;
			#local SGrid_Cylinder_finish = SGrid_Cylinder_lattt + 1;
		#else
			#local SGrid_Cylinder_start = SGrid_Cylinder_increment;
			#local SGrid_Cylinder_finish = SGrid_Cylinder_lattt - 1;
		#end
		#if (SGrid_Cylinder_offset = on)
			#local SGrid_Cylinder_start = SGrid_Cylinder_increment/2;
			#local SGrid_Cylinder_finish = SGrid_Cylinder_lattt;
		#end
		#while(SGrid_Cylinder_i < SGrid_Cylinder_finish)
			#local SGrid_Cylinder_value = SGrid_Cylinder_height * (SGrid_Cylinder_start + SGrid_Cylinder_i * SGrid_Cylinder_increment);
			box
			{
				<-2*SGrid_Cylinder_radius, -SGrid_Cylinder_thickness/2, -2*SGrid_Cylinder_radius,>,
				<2*SGrid_Cylinder_radius, SGrid_Cylinder_thickness/2, 2*SGrid_Cylinder_radius,>
				translate y * SGrid_Cylinder_value
				bounded_by {SGrid_Cylinder_bounds}
			}
//			#debug concat("cylinder_lattt_value = ", str(SGrid_Cylinder_value, 0, -1),"\n")
			#local SGrid_Cylinder_i = SGrid_Cylinder_i + 1;
		#end
		translate SGrid_Cylinder_center
	}
#end

#macro SGrid_DblCone_Macro
	(
		SGrid_DoubleConeGrid_radii,		// The number of radial divisions.		(integer)
		SGrid_DoubleConeGrid_longt,		// The number of longitudinal divisions.	(integer)
		SGrid_DoubleConeGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		SGrid_DoubleConeGrid_radius,		// The radius of each cone.			(float)
		SGrid_DoubleConeGrid_height,		// The height of each cone.			(float)
		SGrid_DoubleConeGrid_center,		// The center coordinates of the double-cone.	(vector)
		SGrid_DoubleConeGrid_thickness,		// The thickness of the grid lines.		(float)
		SGrid_DoubleConeGrid_offset,		// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SGrid_DoubleConeGrid_endcap,		// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SGrid_DoubleConeGrid_thickness = SGrid_DoubleConeGrid_thickness/SGrid_DoubleConeGrid_radius;
	#local SGrid_DoubleConeGrid_bounds = union
	{
		cone {0, SGrid_DoubleConeGrid_radius, <0,+SGrid_DoubleConeGrid_height,0,>, 0}
		cone {0, SGrid_DoubleConeGrid_radius, <0,-SGrid_DoubleConeGrid_height,0,>, 0}
	}

	union
	{

		#local SGrid_DoubleConeGrid_increment = 1/SGrid_DoubleConeGrid_radii;
		#local SGrid_DoubleConeGrid_i = 0;
		#local SGrid_DoubleConeGrid_start = 0;
		#if (SGrid_DoubleConeGrid_offset = on)
			#local SGrid_DoubleConeGrid_start = SGrid_DoubleConeGrid_increment/2;
		#end
		#while(SGrid_DoubleConeGrid_i < SGrid_DoubleConeGrid_radii)
			#local SGrid_DoubleConeGrid_value = SGrid_DoubleConeGrid_radius * (SGrid_DoubleConeGrid_start + SGrid_DoubleConeGrid_i * SGrid_DoubleConeGrid_increment);
			#local SGrid_DoubleConeGrid_angle = atan2d(SGrid_DoubleConeGrid_value, SGrid_DoubleConeGrid_height);
			#local SGrid_DoubleConeGrid_offsl = SGrid_DoubleConeGrid_thickness/2 * 1/cosd(SGrid_DoubleConeGrid_angle);
			#local SGrid_DoubleConeGrid_offsv = SGrid_DoubleConeGrid_thickness/2 * 1/cosd(90 - SGrid_DoubleConeGrid_angle);
			difference
			{
				union
				{
					cone {0, SGrid_DoubleConeGrid_value + SGrid_DoubleConeGrid_offsl, <0,+SGrid_DoubleConeGrid_height+SGrid_DoubleConeGrid_offsv,0,>, 0}
					cone {0, SGrid_DoubleConeGrid_value + SGrid_DoubleConeGrid_offsl, <0,-SGrid_DoubleConeGrid_height-SGrid_DoubleConeGrid_offsv,0,>, 0}
				}
				union
				{
					cone {0, SGrid_DoubleConeGrid_value - SGrid_DoubleConeGrid_offsl, <0,+SGrid_DoubleConeGrid_height-SGrid_DoubleConeGrid_offsv,0,>, 0}
					cone {0, SGrid_DoubleConeGrid_value - SGrid_DoubleConeGrid_offsl, <0,-SGrid_DoubleConeGrid_height+SGrid_DoubleConeGrid_offsv,0,>, 0}
				}
				bounded_by {SGrid_DoubleConeGrid_bounds}
			}
//			#debug concat("radii_value = ", str(SGrid_DoubleConeGrid_value, 0, -1),"\n")
			#local SGrid_DoubleConeGrid_i = SGrid_DoubleConeGrid_i + 1;
		#end

		#local SGrid_DoubleConeGrid_increment = 1/SGrid_DoubleConeGrid_longt;
		#local SGrid_DoubleConeGrid_i = 0;
		#local SGrid_DoubleConeGrid_start = 0;
		#if (SGrid_DoubleConeGrid_offset = on)
			#local SGrid_DoubleConeGrid_start = SGrid_DoubleConeGrid_increment/2;
		#end
		#while(SGrid_DoubleConeGrid_i < SGrid_DoubleConeGrid_longt)
			#local SGrid_DoubleConeGrid_value = 360 * (SGrid_DoubleConeGrid_start + SGrid_DoubleConeGrid_i * SGrid_DoubleConeGrid_increment);
			box
			{
				<2*SGrid_DoubleConeGrid_radius, 2*SGrid_DoubleConeGrid_radius, SGrid_DoubleConeGrid_thickness/2,>,
				<0, -2*SGrid_DoubleConeGrid_radius, -SGrid_DoubleConeGrid_thickness/2,>
				rotate y * SGrid_DoubleConeGrid_value
				bounded_by {SGrid_DoubleConeGrid_bounds}
			}
//			#debug concat("longt_value = ", str(SGrid_DoubleConeGrid_value, 0, -1),"\n")
			#local SGrid_DoubleConeGrid_i = SGrid_DoubleConeGrid_i + 1;
		#end

		#local SGrid_DoubleConeGrid_increment = 1/SGrid_DoubleConeGrid_lattt;
		#local SGrid_DoubleConeGrid_i = 0;
		#if (SGrid_DoubleConeGrid_endcap = on)
			#local SGrid_DoubleConeGrid_start = 0;
			#local SGrid_DoubleConeGrid_finish = SGrid_DoubleConeGrid_lattt + 1;
		#else
			#local SGrid_DoubleConeGrid_start = SGrid_DoubleConeGrid_increment;
			#local SGrid_DoubleConeGrid_finish = SGrid_DoubleConeGrid_lattt - 1;
		#end
		#if (SGrid_DoubleConeGrid_offset = on)
			#local SGrid_DoubleConeGrid_start = SGrid_DoubleConeGrid_increment/2;
			#local SGrid_DoubleConeGrid_finish = SGrid_DoubleConeGrid_lattt;
		#end
		#while (SGrid_DoubleConeGrid_i < SGrid_DoubleConeGrid_finish)
			#local SGrid_DoubleConeGrid_value = -SGrid_DoubleConeGrid_height + 2*SGrid_DoubleConeGrid_height * (SGrid_DoubleConeGrid_start + SGrid_DoubleConeGrid_i * SGrid_DoubleConeGrid_increment);
			box
			{
				<SGrid_DoubleConeGrid_radius,SGrid_DoubleConeGrid_thickness/2,SGrid_DoubleConeGrid_radius,>,
				<-SGrid_DoubleConeGrid_radius,-SGrid_DoubleConeGrid_thickness/2,-SGrid_DoubleConeGrid_radius,>
				bounded_by {SGrid_DoubleConeGrid_bounds}
				translate y * SGrid_DoubleConeGrid_value
			}
//			#debug concat("lattt_value = ", str(SGrid_DoubleConeGrid_value, 0, -1),"\n")
			#local SGrid_DoubleConeGrid_i = SGrid_DoubleConeGrid_i + 1;
		#end
		translate SGrid_DoubleConeGrid_center
	}
#end

#macro SGrid_DblConeInv_Macro
	(
		SGrid_DoubleInvertedConeGrid_radii,		// The number of radial divisions.		(integer)
		SGrid_DoubleInvertedConeGrid_longt,		// The number of longitudinal divisions.	(integer)
		SGrid_DoubleInvertedConeGrid_lattt,		// The number of lattitudinal divisions.	(integer)
		SGrid_DoubleInvertedConeGrid_radius,		// The radius of each cone.			(float)
		SGrid_DoubleInvertedConeGrid_height,		// The height of each cone.			(float)
		SGrid_DoubleInvertedConeGrid_center,		// The center coordinates of the double-cone.	(vector)
		SGrid_DoubleInvertedConeGrid_thickness,		// The thickness of the grid lines.		(float)
		SGrid_DoubleInvertedConeGrid_offset,		// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SGrid_DoubleInvertedConeGrid_endcap,		// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SGrid_DoubleInvertedConeGrid_thickness = SGrid_DoubleInvertedConeGrid_thickness/SGrid_DoubleInvertedConeGrid_radius;
	#local SGrid_DoubleInvertedConeGrid_bounds = union
	{
		cone {0, 0, <0,+SGrid_DoubleInvertedConeGrid_height,0,>, SGrid_DoubleInvertedConeGrid_radius}
		cone {0, 0, <0,-SGrid_DoubleInvertedConeGrid_height,0,>, SGrid_DoubleInvertedConeGrid_radius}
	}

	union
	{

		#local SGrid_DoubleInvertedConeGrid_increment = 1/SGrid_DoubleInvertedConeGrid_radii;
		#local SGrid_DoubleInvertedConeGrid_i = 0;
		#local SGrid_DoubleInvertedConeGrid_start = 0;
		#if (SGrid_DoubleInvertedConeGrid_offset = on)
			#local SGrid_DoubleInvertedConeGrid_start = SGrid_DoubleInvertedConeGrid_increment/2;
		#end
		#while(SGrid_DoubleInvertedConeGrid_i < SGrid_DoubleInvertedConeGrid_radii)
			#local SGrid_DoubleInvertedConeGrid_value = SGrid_DoubleInvertedConeGrid_radius * (SGrid_DoubleInvertedConeGrid_start + SGrid_DoubleInvertedConeGrid_i * SGrid_DoubleInvertedConeGrid_increment);
			#local SGrid_DoubleInvertedConeGrid_angle = atan2d(SGrid_DoubleInvertedConeGrid_value, SGrid_DoubleInvertedConeGrid_height);
			#local SGrid_DoubleInvertedConeGrid_offsl = SGrid_DoubleInvertedConeGrid_thickness/2 * 1/cosd(SGrid_DoubleInvertedConeGrid_angle);
			#local SGrid_DoubleInvertedConeGrid_offsv = SGrid_DoubleInvertedConeGrid_thickness/2 * 1/cosd(90 - SGrid_DoubleInvertedConeGrid_angle);
			difference
			{
				union
				{
					cone {<0,-SGrid_DoubleInvertedConeGrid_offsv,0,>, 0, <0,+SGrid_DoubleInvertedConeGrid_height,0,>, SGrid_DoubleInvertedConeGrid_value + SGrid_DoubleInvertedConeGrid_offsl}
					cone {<0,+SGrid_DoubleInvertedConeGrid_offsv,0,>, 0, <0,-SGrid_DoubleInvertedConeGrid_height,0,>, SGrid_DoubleInvertedConeGrid_value + SGrid_DoubleInvertedConeGrid_offsl}
				}
				union
				{
					cone {<0,+SGrid_DoubleInvertedConeGrid_offsv,0,>, 0, <0,+SGrid_DoubleInvertedConeGrid_height,0,>, SGrid_DoubleInvertedConeGrid_value - SGrid_DoubleInvertedConeGrid_offsl}
					cone {<0,-SGrid_DoubleInvertedConeGrid_offsv,0,>, 0, <0,-SGrid_DoubleInvertedConeGrid_height,0,>, SGrid_DoubleInvertedConeGrid_value - SGrid_DoubleInvertedConeGrid_offsl}
				}
				bounded_by {SGrid_DoubleInvertedConeGrid_bounds}
			}
//			#debug concat("radii_value = ", str(SGrid_DoubleInvertedConeGrid_value, 0, -1),"\n")
			#local SGrid_DoubleInvertedConeGrid_i = SGrid_DoubleInvertedConeGrid_i + 1;
		#end

		#local SGrid_DoubleInvertedConeGrid_increment = 1/SGrid_DoubleInvertedConeGrid_longt;
		#local SGrid_DoubleInvertedConeGrid_i = 0;
		#local SGrid_DoubleInvertedConeGrid_start = 0;
		#if (SGrid_DoubleInvertedConeGrid_offset = on)
			#local SGrid_DoubleInvertedConeGrid_start = SGrid_DoubleInvertedConeGrid_increment/2;
		#end
		#while(SGrid_DoubleInvertedConeGrid_i < SGrid_DoubleInvertedConeGrid_longt)
			#local SGrid_DoubleInvertedConeGrid_value = 360 * (SGrid_DoubleInvertedConeGrid_start + SGrid_DoubleInvertedConeGrid_i * SGrid_DoubleInvertedConeGrid_increment);
			box
			{
				<2*SGrid_DoubleInvertedConeGrid_radius, 2*SGrid_DoubleInvertedConeGrid_radius, SGrid_DoubleInvertedConeGrid_thickness/2,>,
				<0, -2*SGrid_DoubleInvertedConeGrid_radius, -SGrid_DoubleInvertedConeGrid_thickness/2,>
				rotate y * SGrid_DoubleInvertedConeGrid_value
				bounded_by {SGrid_DoubleInvertedConeGrid_bounds}
			}
//			#debug concat("longt_value = ", str(SGrid_DoubleInvertedConeGrid_value, 0, -1),"\n")
			#local SGrid_DoubleInvertedConeGrid_i = SGrid_DoubleInvertedConeGrid_i + 1;
		#end

		#local SGrid_DoubleInvertedConeGrid_increment = 1/SGrid_DoubleInvertedConeGrid_lattt;
		#local SGrid_DoubleInvertedConeGrid_i = 0;
		#if (SGrid_DoubleInvertedConeGrid_endcap = on)
			#local SGrid_DoubleInvertedConeGrid_start = 0;
			#local SGrid_DoubleInvertedConeGrid_finish = SGrid_DoubleInvertedConeGrid_lattt + 1;
		#else
			#local SGrid_DoubleInvertedConeGrid_start = SGrid_DoubleInvertedConeGrid_increment;
			#local SGrid_DoubleInvertedConeGrid_finish = SGrid_DoubleInvertedConeGrid_lattt - 1;
		#end
		#if (SGrid_DoubleInvertedConeGrid_offset = on)
			#local SGrid_DoubleInvertedConeGrid_start = SGrid_DoubleInvertedConeGrid_increment/2;
			#local SGrid_DoubleInvertedConeGrid_finish = SGrid_DoubleInvertedConeGrid_lattt;
		#end
		#while (SGrid_DoubleInvertedConeGrid_i < SGrid_DoubleInvertedConeGrid_finish)
			#local SGrid_DoubleInvertedConeGrid_value = -SGrid_DoubleInvertedConeGrid_height + 2*SGrid_DoubleInvertedConeGrid_height * (SGrid_DoubleInvertedConeGrid_start + SGrid_DoubleInvertedConeGrid_i * SGrid_DoubleInvertedConeGrid_increment);
			box
			{
				<SGrid_DoubleInvertedConeGrid_radius,SGrid_DoubleInvertedConeGrid_thickness/2,SGrid_DoubleInvertedConeGrid_radius,>,
				<-SGrid_DoubleInvertedConeGrid_radius,-SGrid_DoubleInvertedConeGrid_thickness/2,-SGrid_DoubleInvertedConeGrid_radius,>
				bounded_by {SGrid_DoubleInvertedConeGrid_bounds}
				translate y * SGrid_DoubleInvertedConeGrid_value
			}
//			#debug concat("lattt_value = ", str(SGrid_DoubleInvertedConeGrid_value, 0, -1),"\n")
			#local SGrid_DoubleInvertedConeGrid_i = SGrid_DoubleInvertedConeGrid_i + 1;
		#end
		translate SGrid_DoubleInvertedConeGrid_center
	}
#end

#macro SGrid_Sphere_Macro
	(
		SGrid_Sphere_radii,		// The number of radial divisions.		(integer)
		SGrid_Sphere_longt,		// The number of longitudinal divisions.	(integer)
		SGrid_Sphere_lattt,		// The number of lattitudinal divisions.	(integer)
		SGrid_Sphere_radius,		// The radius of the sphere.			(float)
		SGrid_Sphere_center,		// The center coordinates of the sphere.	(vector)
		SGrid_Sphere_thickness,		// The thickness of the grid lines.		(float)
		SGrid_Sphere_offset,		// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SGrid_Sphere_endcap,		// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SGrid_Sphere_thickness = SGrid_Sphere_thickness/SGrid_Sphere_radius;
	#local SGrid_Sphere_bounds = sphere {0, SGrid_Sphere_radius}

	union
	{

		#local SGrid_Sphere_increment = 1/SGrid_Sphere_radii;
		#local SGrid_Sphere_i = 0;
		#local SGrid_Sphere_start = 0;
		#if (SGrid_Sphere_offset = on)
			#local SGrid_Sphere_start = SGrid_Sphere_increment/2;
		#end
		#while(SGrid_Sphere_i < SGrid_Sphere_radii)
			#local SGrid_Sphere_value = SGrid_Sphere_radius * (SGrid_Sphere_start + SGrid_Sphere_i * SGrid_Sphere_increment);
			difference
			{
				sphere {0, SGrid_Sphere_value + SGrid_Sphere_thickness/2}
				sphere {0, SGrid_Sphere_value - SGrid_Sphere_thickness/2}
				bounded_by {SGrid_Sphere_bounds}
			}
//			#debug concat("radii_value = ", str(SGrid_Sphere_value, 0, -1),"\n")
			#local SGrid_Sphere_i = SGrid_Sphere_i + 1;
		#end

		#local SGrid_Sphere_increment = 1/SGrid_Sphere_longt;
		#local SGrid_Sphere_i = 0;
		#local SGrid_Sphere_start = 0;
		#if (SGrid_Sphere_offset = on)
			#local SGrid_Sphere_start = SGrid_Sphere_increment/2;
		#end
		#while(SGrid_Sphere_i < SGrid_Sphere_longt)
			#local SGrid_Sphere_value = 360 * (SGrid_Sphere_start + SGrid_Sphere_i * SGrid_Sphere_increment);
			box
			{
				<2*SGrid_Sphere_radius, 2*SGrid_Sphere_radius, SGrid_Sphere_thickness/2,>,
				<0, -2*SGrid_Sphere_radius, -SGrid_Sphere_thickness/2,>
				rotate y * SGrid_Sphere_value
				bounded_by {SGrid_Sphere_bounds}
			}
//			#debug concat("longt_value = ", str(SGrid_Sphere_value, 0, -1),"\n")
			#local SGrid_Sphere_i = SGrid_Sphere_i + 1;
		#end

		#local SGrid_Sphere_increment = 1/SGrid_Sphere_lattt;
		#local SGrid_Sphere_i = 0;
		#if (SGrid_Sphere_endcap = on)
			#local SGrid_Sphere_start = 0;
			#local SGrid_Sphere_finish = SGrid_Sphere_lattt + 1;
		#else
			#local SGrid_Sphere_start = SGrid_Sphere_increment;
			#local SGrid_Sphere_finish = SGrid_Sphere_lattt - 1;
		#end
		#if (SGrid_Sphere_offset = on)
			#local SGrid_Sphere_start = SGrid_Sphere_increment/2;
			#local SGrid_Sphere_finish = SGrid_Sphere_lattt;
		#end
		#while(SGrid_Sphere_i < SGrid_Sphere_finish)
			#local SGrid_Sphere_value = 180 * (SGrid_Sphere_start + SGrid_Sphere_i * SGrid_Sphere_increment);
			#if (SGrid_Sphere_i < SGrid_Sphere_lattt/2)
				difference
				{
					cone
					{
						0, 0,
						2*SGrid_Sphere_radius*y, 2*SGrid_Sphere_radius*abs(tand(SGrid_Sphere_value))
						translate SGrid_Sphere_radius*-y * 1/abs(sind(SGrid_Sphere_value)) * SGrid_Sphere_thickness/2
					}
					cone
					{
						0, 0,
						2*SGrid_Sphere_radius*y, 2*SGrid_Sphere_radius*abs(tand(SGrid_Sphere_value))
						translate SGrid_Sphere_radius*y * 1/abs(sind(SGrid_Sphere_value)) * SGrid_Sphere_thickness/2
					}
					bounded_by {SGrid_Sphere_bounds}
				}
			#else
				#if (SGrid_Sphere_i = SGrid_Sphere_lattt/2)
					cylinder
					{
						<0,-SGrid_Sphere_thickness/2,0,>, <0,SGrid_Sphere_thickness/2,0,>, 2*SGrid_Sphere_radius
						bounded_by {SGrid_Sphere_bounds}
					}
				#else
					difference
					{
						cone
						{
							0, 0,
							2*SGrid_Sphere_radius*-y, 2*SGrid_Sphere_radius*abs(tand(SGrid_Sphere_value))
							translate SGrid_Sphere_radius*y * 1/abs(sind(SGrid_Sphere_value)) * SGrid_Sphere_thickness/2
						}
						cone
						{
							0, 0,
							2*SGrid_Sphere_radius*-y, 2*SGrid_Sphere_radius*abs(tand(SGrid_Sphere_value))
							translate SGrid_Sphere_radius*-y * 1/abs(sind(SGrid_Sphere_value)) * SGrid_Sphere_thickness/2
						}
						bounded_by {SGrid_Sphere_bounds}
					}
				#end
			#end
//			#debug concat("lattt_value = ", str(SGrid_Sphere_value, 0, -1),"\n")
			#local SGrid_Sphere_i = SGrid_Sphere_i + 1;
		#end
		translate SGrid_Sphere_center
	}
#end

#macro SGrid_Munsell_Macro
	(
		SGrid_SphereMunsell_radii,		// The number of radial divisions.		(integer)
		SGrid_SphereMunsell_longt,		// The number of longitudinal divisions.	(integer)
		SGrid_SphereMunsell_lattt,		// The number of lattitudinal divisions.	(integer)
		SGrid_SphereMunsell_radius,		// The radius of the sphere.			(float)
		SGrid_SphereMunsell_center,		// The center coordinates of the sphere.	(vector)
		SGrid_SphereMunsell_thickness,		// The thickness of the grid lines.		(float)
		SGrid_SphereMunsell_offset,		// Determines whether the divisions are offset by half the amount. Sometimes necessary when doing cut-aways.	(boolian)
		SGrid_SphereMunsell_endcap,		// Determines whether borders are created at each end of the object. Ignored if the offset is turned on. 	(boolian)
	)

	#local SGrid_SphereMunsell_thickness = SGrid_SphereMunsell_thickness/SGrid_SphereMunsell_radius;
	#local SGrid_SphereMunsell_bounds = sphere {0, SGrid_SphereMunsell_radius}

	union
	{

		#local SGrid_SphereMunsell_increment = 1/SGrid_SphereMunsell_radii;
		#local SGrid_SphereMunsell_i = 0;
		#local SGrid_SphereMunsell_start = 0;
		#if (SGrid_SphereMunsell_offset = on)
			#local SGrid_SphereMunsell_start = SGrid_SphereMunsell_increment/2;
		#end
		#while(SGrid_SphereMunsell_i < SGrid_SphereMunsell_radii)
			#local SGrid_SphereMunsell_value = SGrid_SphereMunsell_radius * (SGrid_SphereMunsell_start + SGrid_SphereMunsell_i * SGrid_SphereMunsell_increment);
			difference
			{
				object {Spheroid(0, <SGrid_SphereMunsell_value + SGrid_SphereMunsell_thickness/2,SGrid_SphereMunsell_radius,SGrid_SphereMunsell_value + SGrid_SphereMunsell_thickness/2,>)}
				object {Spheroid(0, <SGrid_SphereMunsell_value - SGrid_SphereMunsell_thickness/2,SGrid_SphereMunsell_radius,SGrid_SphereMunsell_value - SGrid_SphereMunsell_thickness/2,>)}
				bounded_by {SGrid_SphereMunsell_bounds}
			}
//			#debug concat("radii_value = ", str(SGrid_SphereMunsell_value, 0, -1),"\n")
			#local SGrid_SphereMunsell_i = SGrid_SphereMunsell_i + 1;
		#end

		#local SGrid_SphereMunsell_increment = 1/SGrid_SphereMunsell_longt;
		#local SGrid_SphereMunsell_i = 0;
		#local SGrid_SphereMunsell_start = 0;
		#if (SGrid_SphereMunsell_offset = on)
			#local SGrid_SphereMunsell_start = SGrid_SphereMunsell_increment/2;
		#end
		#while(SGrid_SphereMunsell_i < SGrid_SphereMunsell_longt)
			#local SGrid_SphereMunsell_value = 360 * (SGrid_SphereMunsell_start + SGrid_SphereMunsell_i * SGrid_SphereMunsell_increment);
			box
			{
				<2*SGrid_SphereMunsell_radius, 2*SGrid_SphereMunsell_radius, SGrid_SphereMunsell_thickness/2,>,
				<0, -2*SGrid_SphereMunsell_radius, -SGrid_SphereMunsell_thickness/2,>
				bounded_by {SGrid_SphereMunsell_bounds}
				rotate y * SGrid_SphereMunsell_value
			}

//			#debug concat("longt_value = ", str(SGrid_SphereMunsell_value, 0, -1),"\n")
			#local SGrid_SphereMunsell_i = SGrid_SphereMunsell_i + 1;
		#end

		#local SGrid_SphereMunsell_increment = 1/SGrid_SphereMunsell_lattt;
		#local SGrid_SphereMunsell_i = 0;
		#if (SGrid_SphereMunsell_endcap = on)
			#local SGrid_SphereMunsell_start = 0;
			#local SGrid_SphereMunsell_finish = SGrid_SphereMunsell_lattt + 1;
		#else
			#local SGrid_SphereMunsell_start = SGrid_SphereMunsell_increment;
			#local SGrid_SphereMunsell_finish = SGrid_SphereMunsell_lattt - 1;
		#end
		#if (SGrid_SphereMunsell_offset = on)
			#local SGrid_SphereMunsell_start = SGrid_SphereMunsell_increment/2;
			#local SGrid_SphereMunsell_finish = SGrid_SphereMunsell_lattt;
		#end
		#while(SGrid_SphereMunsell_i < SGrid_SphereMunsell_finish)
			#local SGrid_SphereMunsell_value = -SGrid_SphereMunsell_radius + 2*SGrid_SphereMunsell_radius*(SGrid_SphereMunsell_start + SGrid_SphereMunsell_i * SGrid_SphereMunsell_increment);
			box
			{
				<SGrid_SphereMunsell_radius,SGrid_SphereMunsell_thickness/2,SGrid_SphereMunsell_radius,>,
				<-SGrid_SphereMunsell_radius,-SGrid_SphereMunsell_thickness/2,-SGrid_SphereMunsell_radius,>
				bounded_by {SGrid_SphereMunsell_bounds}
				translate y * SGrid_SphereMunsell_value
			}
//			#debug concat("lattt_value = ", str(SGrid_SphereMunsell_value, 0, -1),"\n")
			#local SGrid_SphereMunsell_i = SGrid_SphereMunsell_i + 1;
		#end
		translate SGrid_SphereMunsell_center
	}
#end
