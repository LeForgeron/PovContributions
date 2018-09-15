// Caption: Ringworld Full-scale Scene
// Version: 2.1
// Authors: Michael Horvath, based on Ringworld by Larry Niven
// Website: http://isometricland.net
// Created: 2013-10-16
// Updated: 2018-08-08
// This file is licensed under the terms of the CC-LGPL.

#version 3.7;

#declare HPlanet_Water_Ratio			= 1/3;
#declare HPlanet_Seed_Value				= seed(808232374);

#declare RWorld_Toggle_Sun_Object		= true;
#declare RWorld_Toggle_Corona			= false;
#declare RWorld_Toggle_Surface			= true;
#declare RWorld_Toggle_Clouds			= true;
#declare RWorld_Toggle_Atmosphere		= true;
#declare RWorld_Toggle_Shadow_Squares	= true;
#declare RWorld_Toggle_Radiosity		= true;
#declare RWorld_Toggle_Camera_Mode		= 1;
#declare RWorld_Toggle_Light_Mode		= 2;

// 1 unit = 1000 miles
#declare RWorld_Ring_Radius				= 95000;
#declare RWorld_Ring_Width				= 997;
#declare RWorld_Ring_Height				= 1;
#declare RWorld_Shadow_Ring_Radius		= 13000;
#declare RWorld_Shadow_Ring_Circum		= RWorld_Shadow_Ring_Radius * 2 * pi;
#declare RWorld_Shadow_Square_Width		= 1000;
#declare RWorld_Shadow_Square_Length	= 2500;
#declare RWorld_Shadow_Square_Number	= 20;
#declare RWorld_Spill_Mtn_Height_1		= 0.03;
#declare RWorld_Spill_Mtn_Height_2		= 0.04;
#declare RWorld_Sun_Diameter			= 1000;
#declare RWorld_Sun_Radius				= RWorld_Sun_Diameter/2;
#declare RWorld_Corona_Radius			= RWorld_Ring_Radius*2;
#declare RWorld_Atmosphere_Height		= 1;
#declare RWorld_Clouds_Bottom			= 0.01;
#declare RWorld_Clouds_Top				= 0.05;

#include "CIE.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "math.inc"
#include "transforms.inc"

#declare RWorld_Light_Area_Radius		= RWorld_Sun_Radius;
#declare RWorld_Light_Area_Theta_Num	= 6;
#declare RWorld_Light_Area_Theta_Dif	= 2 * pi/RWorld_Light_Area_Theta_Num;
#declare RWorld_Light_Area_Phi_Num		= 6;
#declare RWorld_Light_Area_Phi_Dif		= pi/RWorld_Light_Area_Phi_Num;
#declare RWorld_Light_Area_Lumens		= 2/RWorld_Light_Area_Theta_Num/RWorld_Light_Area_Phi_Num;
#declare RWorld_Light_Area_Temp			= Daylight(5800);
#declare RWorld_Light_Area_Color		= Light_Color(RWorld_Light_Area_Temp,RWorld_Light_Area_Lumens);

#declare RWorld_Light_Point_Lumens		= 2;
#declare RWorld_Light_Point_Temp		= Daylight(5800);
#declare RWorld_Light_Point_Color		= Light_Color(RWorld_Light_Point_Temp,RWorld_Light_Point_Lumens);


//------------------------------------------------------------------------------
// CAMERA


#switch (RWorld_Toggle_Camera_Mode)
	#case (1)
		#declare RWorld_Camera_Vertical		= 0;			//45;
		#declare RWorld_Camera_Horizontal	= 30;			//asind(tand(30));
		#declare RWorld_Camera_Aspect		= image_height/image_width;
		#declare RWorld_Camera_Distance		= 10;
		#declare RWorld_Camera_Translate	= <0,0,0>;
		#declare RWorld_Camera_Scale		= RWorld_Ring_Radius * 1.1;

		#declare RWorld_Camera_Up			= +y * 2 * RWorld_Camera_Aspect;
		#declare RWorld_Camera_Right		= +x * 2;
		#declare RWorld_Camera_Location		= -z * RWorld_Camera_Distance;
		#declare RWorld_Camera_Direction	= +z * RWorld_Camera_Distance;
		#declare RWorld_Camera_LookAt		= RWorld_Camera_Location + RWorld_Camera_Direction;
		#declare RWorld_Camera_Rotate		= <RWorld_Camera_Horizontal,RWorld_Camera_Vertical,0,>;
		#declare RWorld_Camera_Transform = transform
		{
			rotate		RWorld_Camera_Rotate
			scale		RWorld_Camera_Scale
			translate	RWorld_Camera_Translate
		}

		camera
		{
			perspective
			//orthographic
			up			RWorld_Camera_Up
			right		RWorld_Camera_Right
			location	RWorld_Camera_Location
			direction	RWorld_Camera_Direction
			transform {RWorld_Camera_Transform}
		}

		#declare RWorld_Camera_Location	= vtransform(RWorld_Camera_Location,RWorld_Camera_Transform);
		#declare RWorld_Camera_LookAt	= vtransform(RWorld_Camera_LookAt,RWorld_Camera_Transform);
	#break
	#case (2)
		camera
		{
			perspective
			sky		y
			location	<0,0,-RWorld_Ring_Radius*63/64>
			look_at		<0,0,-RWorld_Ring_Radius>
		}
	#break
	#case (3)
		camera
		{
			perspective
			sky		z
			location	<0,0,-RWorld_Ring_Radius + 0.005>
			look_at		<1,0,-RWorld_Ring_Radius + 0.005>
		}
	#break
	#case (4)
		camera
		{
			perspective
			sky		y
			location	<0,RWorld_Ring_Radius*1/4,-RWorld_Ring_Radius*2/3>
			look_at		<0,0,-RWorld_Ring_Radius>
		}
	#break
	#case (5)
		camera
		{
			spherical
			angle		360
			sky		y
			location	<RWorld_Ring_Radius*1/16,RWorld_Ring_Radius*1/16,-RWorld_Ring_Radius*15/16>
			look_at		<0,RWorld_Ring_Radius*1/16,-RWorld_Ring_Radius>
		}
	#break
#end


//------------------------------------------------------------------------------
// MISC GRAPHICAL SETTINGS


global_settings
{
	#if (RWorld_Toggle_Radiosity = true)
		radiosity
		{
			always_sample	off
			brightness		0.3
		}
	#end
	ambient_light	0.01
	charset			utf8
	assumed_gamma	1.0
}

background {color rgb 0}

sky_sphere
{
	pigment
	{
		bozo
		color_map
		{
			[0.0 color rgb 1]
			[0.2 color rgb 0]
			[1.0 color rgb 0]
		}
		scale 1e-4
	}
}


//------------------------------------------------------------------------------
// TEXTURE MAPS


#declare HPlanet_Blue_Texture = texture
{
	pigment {color rgb <000,000,050,>/255}

	finish
	{
		//ambient 0.15
		ambient 0
		diffuse 0.2
		brilliance 5.0
		phong 1.0
		phong_size 90.0
		specular 0.1
		roughness 0.01
		conserve_energy
		reflection
		{
			0.1,
			0.9
			falloff 2
		}
	}
}
#declare HPlanet_Teal_Texture = texture
{
	pigment {color rgb <034,180,180,>/255}

	finish
	{
		//ambient 0.15
		ambient 0
		diffuse 0.2
		brilliance 5.0
		phong 1.0
		phong_size 90.0
		specular 0.1
		roughness 0.01
		conserve_energy
		reflection
		{
			0.1,
			0.9
			falloff 2
		}
	}
}
#declare HPlanet_Light_Green_Texture = texture
{
	pigment {color rgb <067,084,029,>/255}
}
#declare HPlanet_Dark_Green_Texture = texture
{
	pigment {color rgb <040,066,018,>/255}
}
#declare HPlanet_Dark_Tan_Texture = texture
{
	pigment {color rgb <084,076,037,>/255}
}
#declare HPlanet_Light_Tan_Texture = texture
{
	pigment {color rgb <132,114,076,>/255}
}
#declare HPlanet_White_Texture = texture
{
	pigment {color rgb <255,255,255,>/255}
}

#declare HPlanet_Altitiude_Texture_Map = texture_map
{
	[0															HPlanet_Blue_Texture]
	[HPlanet_Water_Ratio * 97.5/100								HPlanet_Blue_Texture]
	[HPlanet_Water_Ratio * 1/1									HPlanet_Teal_Texture]
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 0/6		HPlanet_Light_Green_Texture]
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/6		HPlanet_Dark_Green_Texture]
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/6		HPlanet_Dark_Tan_Texture]
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 4/6		HPlanet_Light_Tan_Texture]
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 4/6		HPlanet_White_Texture]
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 6/6		HPlanet_White_Texture]
}

#if (RWorld_Toggle_Atmosphere = true)
	#declare HPlanet_Bozo_Cloud_Color_Map = color_map
	{
		[0.0 color rgb  <0.95, 0.95, 0.95>*0.5]
		[0.1 color rgb  <0.85, 0.85, 0.85>*1.5]
		[0.4 color rgbt 1]
		[1.0 color rgbt 1]
	}
#else
	#declare HPlanet_Bozo_Cloud_Color_Map = color_map
	{
		[0.0 color rgb  <0.95, 0.95, 0.95>*0.5]
		[0.1 color rgb  <0.85, 0.85, 0.85>*1.5]
		[0.4 color rgbt <0.10, 0.30, 1.00, 0.99>]
		[1.0 color rgbt <0.10, 0.30, 1.00, 0.99>]
//		[0.4 color rgbt 1 ]
//		[1.0 color rgbt 1 ]
	}
#end


//------------------------------------------------------------------------------
// TEXTURE FUNCTIONS


#declare HPlanet_Crackle_Function = function
{
	pigment
	{
		crackle form <1,0,0>
		color_map
		{
			[0 rgb 0]
			[1 rgb 1]
		}
		scale 1
	}
}

#declare HPlanet_Granite_Function = function
{
	pigment
	{
		granite
		color_map
		{
			[0 rgb 0]
			[1 rgb 1]
		}
		warp
		{
			turbulence	0.75
			lambda		3
		}
		scale 10
	}
}

#declare HPlanet_Edge_Height_Land_Function = function
{
	pigment
	{
		gradient y
		color_map
		{
			[ 0/16 rgb 0/2]
			[ 2/16 rgb 1/2]
			//[ 5/16 rgb 1/2]
			[ 8/16 rgb 2/2]
			//[ 9/16 rgb 1/2]
			[14/16 rgb 1/2]
			[16/16 rgb 0/2]
		}
		translate -y/2
		scale 2
	}
}

#declare HPlanet_Edge_Height_Cloud_Function = function
{
	pigment
	{
		gradient y
		color_map
		{
			[ 0/16 rgb 2/2]
			[ 7/16 rgb 0/2]
			[ 8/16 rgb 2/2]
			[ 9/16 rgb 0/2]
			[16/16 rgb 2/2]
		}
		translate -y/2
		scale 2
	warp
	{
		turbulence 1
	}
	}
}

#declare HPlanet_Bozo_Cloud_Function = function
{
	pigment
	{
		bozo
		turbulence 0.65
		octaves 6
		omega 0.7
		lambda 2 
		color_map
		{
			[0 rgb 0]
			[1/16 rgb 0]
			[1 rgb 1]
		}
		scale 1/10
	}
}


//------------------------------------------------------------------------------
// FINAL TEXTURES


#declare HPlanet_Granite_Crackle_1_Texture = texture
{
	function {((1-HPlanet_Crackle_Function(x,y,z).green) * 2 + HPlanet_Granite_Function(x,y,z).green * 1 + HPlanet_Edge_Height_Land_Function(x,y,z).green * 3)/5 * -1}
	texture_map
	{
		HPlanet_Altitiude_Texture_Map
	}
/*
	#declare HPlanet_Warp_Count = 0;
	#declare HPlanet_Warp_Total = 10000;
	#while (HPlanet_Warp_Count < HPlanet_Warp_Total)
		#declare HPlanet_Cyl_Radius = RWorld_Ring_Radius/(RWorld_Ring_Width/2);
		#declare HPlanet_Cyl_Theta = rand(HPlanet_Seed_Value) * 2 * pi;
		#declare HPlanet_Cyl_Height = floor(rand(HPlanet_Seed_Value) + 1/2) * 2 - 1;
		#declare HPlanet_Cyl_Height = rand(HPlanet_Seed_Value) * 2 - 1;
		#declare HPlanet_Hole_Radius = rand(HPlanet_Seed_Value) * 2;
		warp
		{
			black_hole	<HPlanet_Cyl_Radius * cos(HPlanet_Cyl_Theta), HPlanet_Cyl_Height, HPlanet_Cyl_Radius * sin(HPlanet_Cyl_Theta)>, HPlanet_Hole_Radius
			falloff		3/6
			strength	1/24
			inverse
		}
		#declare HPlanet_Warp_Count = HPlanet_Warp_Count + 1;
	#end
*/
}

#declare HPlanet_Granite_Crackle_2_Texture = texture
{
	function {((1-HPlanet_Crackle_Function(x,y,z).green) * 2 + HPlanet_Granite_Function(x,y,z).green * 2)/3 * -1}
	texture_map
	{
		[0															HPlanet_Blue_Texture]
		[HPlanet_Water_Ratio * 97.5/100								HPlanet_Blue_Texture]
		[HPlanet_Water_Ratio * 1/1									HPlanet_Teal_Texture]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 0/6		HPlanet_Granite_Crackle_1_Texture]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 6/6		HPlanet_Granite_Crackle_1_Texture]
	}
/*
	#declare HPlanet_Warp_Count = 0;
	#declare HPlanet_Warp_Total = 10000;
	#while (HPlanet_Warp_Count < HPlanet_Warp_Total)
		#declare HPlanet_Cyl_Radius = RWorld_Ring_Radius/(RWorld_Ring_Width/2);
		#declare HPlanet_Cyl_Theta = rand(HPlanet_Seed_Value) * 2 * pi;
		#declare HPlanet_Cyl_Height = rand(HPlanet_Seed_Value) * 2 - 1;
		#declare HPlanet_Hole_Radius = rand(HPlanet_Seed_Value) / 10;
		warp
		{
			black_hole	<HPlanet_Cyl_Radius * cos(HPlanet_Cyl_Theta), HPlanet_Cyl_Height, HPlanet_Cyl_Radius * sin(HPlanet_Cyl_Theta)>, HPlanet_Hole_Radius
			falloff		3/6
			strength	4/24
			inverse
		}
		#declare HPlanet_Warp_Count = HPlanet_Warp_Count + 1;
	#end
*/
}

#declare HPlanet_Cloud_Edge_Pigment = pigment
{
	function {(HPlanet_Bozo_Cloud_Function(x,y,z).x * 3 + HPlanet_Edge_Height_Cloud_Function(x,y,z).x * 1)/4 * -1}
	color_map
	{
		HPlanet_Bozo_Cloud_Color_Map
	}
	warp
	{
		turbulence <1,0,1>
	}
/*
	#declare HPlanet_Warp_Count = 0;
	#declare HPlanet_Warp_Total = 10000;
	#while (HPlanet_Warp_Count < HPlanet_Warp_Total)
		#declare HPlanet_Cyl_Radius = RWorld_Ring_Radius/(RWorld_Ring_Width/2);
		#declare HPlanet_Cyl_Theta = rand(HPlanet_Seed_Value) * 2 * pi;
		#declare HPlanet_Cyl_Height = floor(rand(HPlanet_Seed_Value) + 1/2) * 2 - 1;
		#declare HPlanet_Cyl_Height = rand(HPlanet_Seed_Value) * 2 - 1;
		#declare HPlanet_Hole_Radius = rand(HPlanet_Seed_Value) * 1;
		warp
		{
			black_hole	<HPlanet_Cyl_Radius * cos(HPlanet_Cyl_Theta), HPlanet_Cyl_Height, HPlanet_Cyl_Radius * sin(HPlanet_Cyl_Theta)>, HPlanet_Hole_Radius
			falloff		3
			strength	1/6
			inverse
		}
		#declare HPlanet_Warp_Count = HPlanet_Warp_Count + 1;
	#end
*/
}


//------------------------------------------------------------------------------
// RINGWORLD


// surface
#declare RWorld_Surface_Object = difference
{
	cylinder {<0,RWorld_Ring_Width/2,0>,		<0,-RWorld_Ring_Width/2,0>,		RWorld_Ring_Radius + 1}
	cylinder {<0,RWorld_Ring_Width/2 + 1,0>,	<0,-RWorld_Ring_Width/2 - 1,0>,	RWorld_Ring_Radius}
	texture
	{
		HPlanet_Granite_Crackle_2_Texture
		scale RWorld_Ring_Width/2
	}
}


// rim
#declare RWorld_Rim_Object = difference
{
	cylinder {<0,RWorld_Ring_Width/2 + 1,0>,	<0,-RWorld_Ring_Width/2 - 1,0>,	RWorld_Ring_Radius + 2}
	cylinder {<0,RWorld_Ring_Width/2,0>,		<0,-RWorld_Ring_Width/2,0>,		RWorld_Ring_Radius + 0.99999}
	cylinder {<0,RWorld_Ring_Width/2 + 2,0>,	<0,-RWorld_Ring_Width/2 - 2,0>,	RWorld_Ring_Radius - RWorld_Ring_Height}
	texture
	{
		pigment {color rgb 1}
		scale RWorld_Ring_Width/2
	}
}


// clouds
#declare RWorld_Clouds_Object = difference
{
	cylinder {<0,RWorld_Ring_Width/2,0>,		<0,-RWorld_Ring_Width/2,0>,		RWorld_Ring_Radius - RWorld_Clouds_Bottom}
	cylinder {<0,RWorld_Ring_Width/2 + 1,0>,	<0,-RWorld_Ring_Width/2 - 1,0>,	RWorld_Ring_Radius - RWorld_Clouds_Top}
	hollow		// should this be hollow?
	texture
	{
		pigment {HPlanet_Cloud_Edge_Pigment}
		finish {ambient 0 diffuse 1}
		scale RWorld_Ring_Width/2
	}
}


// atmosphere
#declare RWorld_Atmos_Color_Scatter	= <0.1, 0.3, 1.0>;
#declare RWorld_Atmos_Color_Absorb	= <0.9, 0.7, 0.0>;		// should be the inverse of RWorld_Atmos_Color_Scatter
#declare RWorld_Atmosphere_Object = difference
{
	cylinder {<0,+RWorld_Ring_Width/2,0>,		<0,-RWorld_Ring_Width/2,0>,		RWorld_Ring_Radius - 1}	//
	cylinder {<0,+RWorld_Ring_Width/2 + 1,0>,	<0,-RWorld_Ring_Width/2 - 1,0>,	RWorld_Ring_Radius - RWorld_Atmosphere_Height}
	hollow
	material
	{
		texture
		{
			pigment {rgbt 1}
		}
		interior
		{
			media
			{
				scattering
				{
					4, RWorld_Atmos_Color_Scatter
				}
				density
				{
					// Reverse: It starts at 1.0 at the origin and decreases to a minimum value of 0.0 as it approaches a distance of 1 unit from the Y axis.
					function {1-f_cylindrical(x,y,z)}
					density_map
					{
						[0 rgb 0]
						[1-RWorld_Atmosphere_Height/RWorld_Ring_Radius rgb 0]
						[1 rgb 1/10]
					}
					scale RWorld_Ring_Radius
				}
			}
			media
			{
				absorption RWorld_Atmos_Color_Absorb
				density
				{
					function {1-f_cylindrical(x,y,z)}
					density_map
					{
						[0 rgb 0]
						[1-RWorld_Atmosphere_Height/RWorld_Ring_Radius rgb 0]
						[1 rgb 1/10]
					}
					scale RWorld_Ring_Radius
				}
			}
		}
	}
}


//------------------------------------------------------------------------------
// SUN & HELIOSPHERE


#declare RWorld_Sun_Object = sphere
{ 
	0, RWorld_Sun_Radius
	hollow
	material
	{
		texture
		{
			pigment {rgbt 1}
		}
		interior
		{
			media
			{
				emission 10/RWorld_Sun_Radius
				density
				{
					spherical
					density_map
					{
						[0.0 rgb 0]
						[0.1 rgb RWorld_Light_Point_Color]
						[1.0 rgb RWorld_Light_Point_Color]
					}
					scale RWorld_Sun_Radius
				}
			}
		}
	}
}

#declare RWorld_Corona_Object = sphere
{ 
	0, RWorld_Corona_Radius
	hollow
	material
	{
		texture
		{
			pigment {rgbt 1}
		}
		interior
		{
			media
			{
				scattering {1, RWorld_Light_Point_Color/20000}	// needs to be divided by RWorld_Corona_Radius doesn't it?
				density
				{
					function {1/(x*x + y*y + z*z)/RWorld_Corona_Radius}
					density_map
					{
						[0 rgb 0]
						[1 rgb 1]
					}
					scale RWorld_Corona_Radius
				}
			}
		}
	}
}


//------------------------------------------------------------------------------
// LIGHTS


#switch (RWorld_Toggle_Light_Mode)
	#case (1)
		// old area light code (very slow)
		// I need a new formula, since right now the lights are concentrated near the poles
		#declare RWorld_Light_Area_Theta = RWorld_Light_Area_Theta_Dif/2;
		#for (i, 1, RWorld_Light_Area_Theta_Num)
			#declare RWorld_Light_Area_Phi = RWorld_Light_Area_Phi_Dif/2;
			#for (j, 1, RWorld_Light_Area_Phi_Num)
				#declare RWorld_Light_Area_X = RWorld_Light_Area_Radius * cos(RWorld_Light_Area_Theta) * sin(RWorld_Light_Area_Phi);
				#declare RWorld_Light_Area_Y = RWorld_Light_Area_Radius * cos(RWorld_Light_Area_Phi);
				#declare RWorld_Light_Area_Z = RWorld_Light_Area_Radius * sin(RWorld_Light_Area_Theta) * sin(RWorld_Light_Area_Phi);
				light_source
				{
					<RWorld_Light_Area_X, RWorld_Light_Area_Y, RWorld_Light_Area_Z>
					RWorld_Light_Area_Color
				}
				#declare RWorld_Light_Area_Phi = RWorld_Light_Area_Phi + RWorld_Light_Area_Phi_Dif;
			#end
			#declare RWorld_Light_Area_Theta = RWorld_Light_Area_Theta + RWorld_Light_Area_Theta_Dif;
		#end
	#break
	#case (2)
		// new area light code (less slow)
		light_source
		{
			0
			RWorld_Light_Point_Color
			area_light
			x * RWorld_Sun_Diameter, y * RWorld_Sun_Diameter		// lights spread out across this distance (x * z)
			5, 5													// total number of lights in grid (4x*4z = 16 lights)
			adaptive 1												// 0,1,2,3...
			jitter													// adds random softening of light
			circular												// make the shape of the light circular
			orient													// orient light
			looks_like {RWorld_Sun_Object}
		}
	#break
	#case (3)
		// point light (not slow)
		light_source
		{
			0
			RWorld_Light_Point_Color
			looks_like {RWorld_Sun_Object}
		}
	#break
#end


//------------------------------------------------------------------------------
// SHADOW SQUARES

#declare RWorld_Shadow_Square_Factor	= RWorld_Shadow_Square_Length/RWorld_Shadow_Ring_Circum;
#declare RWorld_Shadow_Square_Angle_A	= 360 / RWorld_Shadow_Square_Number;
#declare RWorld_Shadow_Square_Angle_B	= 360 * RWorld_Shadow_Square_Factor;

#debug "\n"
#debug concat("RWorld_Shadow_Ring_Circum: \t", str(RWorld_Shadow_Ring_Circum,0,-1), "\n")
#debug concat("RWorld_Shadow_Square_Factor: \t", str(RWorld_Shadow_Square_Factor,0,-1), "\n")
#debug "\n"

#declare RWorld_Shadow_Square_Piece = intersection
{
	difference
	{
		cylinder {<0,+RWorld_Shadow_Square_Width/2,0>,		<0,-RWorld_Shadow_Square_Width/2,0>,		RWorld_Shadow_Ring_Radius}
		cylinder {<0,+RWorld_Shadow_Square_Width/2 + 1,0>,	<0,-RWorld_Shadow_Square_Width/2 - 1,0>,	RWorld_Shadow_Ring_Radius - 1}
	}
	plane {-z, 0 rotate y * +RWorld_Shadow_Square_Angle_B/2}
	plane {+z, 0 rotate y * -RWorld_Shadow_Square_Angle_B/2}
}

#declare RWorld_Shadow_Square_Union = union
{
	#for (i, 1, RWorld_Shadow_Square_Number)
		object {RWorld_Shadow_Square_Piece rotate y * RWorld_Shadow_Square_Angle_A * i}
	#end
	pigment {color rgb 0}
}


//------------------------------------------------------------------------------
// choose objects to render


#if (RWorld_Toggle_Surface = true)
	object {RWorld_Surface_Object}
	object {RWorld_Rim_Object}
#end
#if (RWorld_Toggle_Clouds = true)
	object {RWorld_Clouds_Object}
#end
#if (RWorld_Toggle_Atmosphere = true)
	object {RWorld_Atmosphere_Object}
#end
#if (RWorld_Toggle_Sun_Object = true)
	object {RWorld_Sun_Object}
#end
#if (RWorld_Toggle_Corona = true)
	object {RWorld_Corona_Object}
#end
#if (RWorld_Toggle_Shadow_Squares = true)
	object {RWorld_Shadow_Square_Union}
#end
