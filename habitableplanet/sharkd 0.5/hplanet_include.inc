// Title: Habitable planet texture include v0.50
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008-02-07
// Last Updated: 2008-11-07
// This file is licensed under the terms of the CC-LGPL.
// +KFI0 +KFF15 +KC
// +k0.5

#local HPlanet_Crackle_pigment = pigment
{
	crackle form <1,0,0>
	color_map
	{
		[0 rgbt 0]
		[1 rgbt 1]
	}
	scale 2
	sine_wave
}

#local HPlanet_Black_pigment = pigment {color rgbt 0}

#local HPlanet_Granite_pigment = pigment
{
	granite
//	poly_wave 2
	color_map
	{
		[0 rgbt 0]
		[1 rgbt 1]
	}
	scale 10
	scale .5
	warp
	{
		turbulence	.75
		lambda		3
	}
	scale .5
}

#local HPlanet_Altitude_function = function
{
	pigment
	{
		HPlanet_Crackle_pigment
		#local HPlanet_WarpCount = 0;
		#local HPlanet_WarpTotal = 512;
		#while (HPlanet_WarpCount < HPlanet_WarpTotal)
			warp
			{
				black_hole VRand_On_Sphere(HPlanet_Seed_Value), Rand_Beta(1,6,HPlanet_Seed_Value)
				falloff		3/6
				strength	3/6
				inverse
			}
			#local HPlanet_WarpCount = HPlanet_WarpCount + 1;
		#end
		warp
		{
			turbulence	1/8		//.125
			lambda		3		//3
//			octaves		20
//			omega		SetOmega
		}
		pigment_map
		{
			[0 HPlanet_Black_pigment]
			[1 HPlanet_Granite_pigment]
		}
	}
}

#local HPlanet_Altitude_function_b = function
{
	pigment
	{
		function {HPlanet_Altitude_function(x,y,z).transmit}
		color_map
		{
			[0 rgbt 0]
			[1 rgbt 1]
		}
		#local HPlanet_WarpCount = 0;
		#local HPlanet_WarpTotal = 1024;
		#while (HPlanet_WarpCount < HPlanet_WarpTotal)
			warp
			{
				black_hole VRand_On_Sphere(HPlanet_Seed_Value), Rand_Beta(1,12,HPlanet_Seed_Value)
				falloff		6/6
				strength	6/6
				inverse
			}
			#local HPlanet_WarpCount = HPlanet_WarpCount + 1;
		#end
	}
}

#declare HPlanet_Latitude_function = function
{
	pigment
	{
		function {f_ph(x,y,z) / pi}
		color_map
		{
			[0/2 rgbt 1]
			[1/2 rgbt 0]
			[2/2 rgbt 1]
		}
	}
}

#declare HPlanet_Altitiude_color_map = color_map
{
	[0								rgb <000,000,050,>/255]		//blue
	[HPlanet_Water_Ratio * 97.5/100					rgb <000,000,050,>/255]		//blue
	[HPlanet_Water_Ratio * 1/1					rgb <034,180,180,>/255]		//teal
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 0/6		rgb <067,084,029,>/255]		//light green
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/6		rgb <040,066,018,>/255]		//dark green
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/6		rgb <084,076,037,>/255]		//dark tan
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 4/6		rgb <132,114,076,>/255]		//light tan
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 4/6		rgb <255,255,255,>/255]		//white
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 6/6		rgb <255,255,255,>/255]		//white
}

#declare HPlanet_Altitiude_color_map_no_land = color_map
{
	[0								rgb <000,000,050,>/255]		//blue
	[HPlanet_Water_Ratio * 97.5/100					rgb <000,000,050,>/255]		//blue
	[HPlanet_Water_Ratio * 1/1					rgb <034,180,180,>/255]		//teal
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 0/3		rgb <067,084,029,>/255]		//light green
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/3		rgb <067,084,029,>/255]		//light green
}

#declare HPlanet_Altitiude_color_map_no_water = color_map
{
	[0								rgb <067,084,029,>/255]		//light green
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 0/2		rgb <067,084,029,>/255]		//light green
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 1/3		rgb <040,066,018,>/255]		//dark green
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 1/2		rgb <084,076,037,>/255]		//dark tan
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/3		rgb <132,114,076,>/255]		//light tan
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/3		rgb <132,114,076,>/255]		//light tan
}

#declare HPlanet_Altitiude_color_map_ice_only = color_map
{
	[0								rgb <132,114,076,>/255]		//light tan
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/3		rgb <132,114,076,>/255]		//light tan
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/3		rgb <255,255,255,>/255]		//white
	[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/3		rgb <255,255,255,>/255]		//white
}

#declare HPlanet_Vegetation_color_map = color_map
{
	//rgb <253,234,157,>/255	//blond
	[  00/12		rgb <060,056,029,>/255]		//olive
	[  03/12		rgb <060,056,029,>/255]		//olive
	[  04/12		rgb <040,066,018,>/255]		//dark green
	[ 5.5/12		rgb <067,084,029,>/255]		//green
	[  06/12		rgb <071,059,037,>/255]		//brown
	[6.75/12		rgb <180,148,103,>/255]		//blond
	[8.25/12		rgb <180,148,103,>/255]		//blond
	[  09/12		rgb <071,059,037,>/255]		//brown
	[ 9.5/12		rgb <067,084,029,>/255]		//green
	[  12/12		rgb <040,066,018,>/255]		//dark green
}

#declare HPlanet_Latitude_pigment = pigment
{
	function {HPlanet_Latitude_function(x, y, z).transmit}
	color_map {HPlanet_Altitiude_color_map}
}

#declare HPlanet_Vegetation_pigment = pigment
{
	function {HPlanet_Altitude_function_b(x, y, z).transmit + 1 - HPlanet_Latitude_function(x, y, z).transmit}
	color_map {HPlanet_Vegetation_color_map}
	warp
	{
		turbulence	1/16		//.125
		lambda		3		//3
//		octaves		20
//		omega		SetOmega
	}
}

#declare HPlanet_Water_pigment = pigment
{
	function {HPlanet_Altitude_function_b(x, y, z).transmit}
	color_map {HPlanet_Altitiude_color_map_no_land}
}

// version 1
#declare HPlanet_Land_pigment = pigment
{
	function {HPlanet_Altitude_function(x, y, z).transmit}
	color_map {HPlanet_Altitiude_color_map_no_water}
	warp
	{
		turbulence	1/8		//.125
		lambda		3		//3
//		octaves		20
//		omega		SetOmega
	}
}

// version 2
#declare HPlanet_Land_pigment = pigment
{
	function {min(HPlanet_Altitude_function(x, y, z).transmit + HPlanet_Latitude_function(x, y, z).transmit * HPlanet_Ice_Ratio, 1)}
	color_map {HPlanet_Altitiude_color_map_no_water}
	warp
	{
		turbulence	1/8		//.125
		lambda		3		//3
//		octaves		20
//		omega		SetOmega
	}
}

#declare HPlanet_Average_pigment = pigment
{
	average
	pigment_map
	{
		[1 HPlanet_Land_pigment]
		[2 HPlanet_Vegetation_pigment]
	}
}

// version 1
#declare HPlanet_Ice_pigment = pigment {color rgb 1}

// version 2
#declare HPlanet_Ice_pigment = pigment
{
	function {min(HPlanet_Altitude_function(x, y, z).transmit + HPlanet_Latitude_function(x, y, z).transmit * HPlanet_Ice_Ratio, 1)}
	pigment_map
	{
		[0							HPlanet_Average_pigment]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/3	HPlanet_Average_pigment]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/3	color rgb 1]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/3	color rgb 1]
	}
	warp
	{
		turbulence	1/8		//.125
		lambda		3		//3
//		octaves		20
//		omega		SetOmega
	}	
}

// version 1
#declare HPlanet_Combined_pigment = pigment
{
	function {HPlanet_Altitude_function_b(x, y, z).transmit}
	pigment_map
	{
		[0			HPlanet_Water_pigment]
		[HPlanet_Water_Ratio	HPlanet_Water_pigment]
		[HPlanet_Water_Ratio	HPlanet_Land_pigment]
		[1			HPlanet_Land_pigment]
	}
}

// version 2
#declare HPlanet_Combined_pigment = pigment
{
	function {HPlanet_Altitude_function_b(x, y, z).transmit}
	pigment_map
	{
		[0			HPlanet_Water_pigment]
		[HPlanet_Water_Ratio	HPlanet_Water_pigment]
		[HPlanet_Water_Ratio	HPlanet_Average_pigment]
		[1			HPlanet_Average_pigment]
	}
}

// version 1
#declare HPlanet_Final_pigment = pigment
{
	function {min(HPlanet_Altitude_function(x, y, z).transmit + HPlanet_Latitude_function(x, y, z).transmit * HPlanet_Ice_Ratio, 1)}
	pigment_map
	{
		[0							HPlanet_Combined_pigment]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/3	HPlanet_Combined_pigment]
//		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/3	HPlanet_Combined_pigment]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 2/3	HPlanet_Ice_pigment]
		[HPlanet_Water_Ratio + (1 - HPlanet_Water_Ratio) * 3/3	HPlanet_Ice_pigment]
	}
}

// version 2
//#declare HPlanet_Final_pigment = HPlanet_Combined_pigment;
