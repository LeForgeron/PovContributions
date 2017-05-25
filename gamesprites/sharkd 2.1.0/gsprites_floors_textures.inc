// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.


// -------------------------------------------------------------

#declare GSprites_Hardwood_Texture_A = texture
{
	#local board_length = 1/2;
	#local board_width = 1/8;
	#local light_wood = pigment {P_WoodGrain7A color_map {M_Wood7A}}
	#local dark_wood = pigment {P_WoodGrain14A color_map {M_Wood14A}}
	pigment
	{
		gradient y
		triangle_wave
		pigment_map {[0 light_wood][1 dark_wood]}
		warp {repeat z * board_length offset y * 1/32} 
		warp {repeat x * board_width offset z * board_length * 5/2}
	}
	finish {GSprites_Default_Finish}
	normal
	{
		boxed
		slope_map
		{
			[0 <1,0>]
			[1/16 <1/2,0>]
			[1/2 <1/2,0>]
			[1 <0,0>]
		}
		bump_size 1/4
		scale x * board_width
		scale z * board_length
		warp {repeat z * board_length}
		warp {repeat x * board_width offset z * board_length/2}
	}
}

#declare GSprites_Hardwood_Texture_B = texture
{
	#local board_length = 1/2;
	#local board_width = 1/8;
	pigment
	{
		cells
		color_map
		{
			[0 color rgb <159,114,053,>/255]
			[1/2 color rgb <139,055,027,>/255]
			[1 color rgb <103,053,028,>/255]
		}
		scale x * board_width
		scale z * board_length
		warp {repeat z * board_length * 2}
		warp {repeat x * board_width offset <0,1,board_length/2,>}
	}
	finish {GSprites_Default_Finish}
	normal
	{
//		boxed
		cells
		slope_map
		{
			[0 <1,0>]
//			[1/4 <0,0>]
//			[1/8 <1/2,0>]
//			[1/2 <1/2,0>]
			[1 <0,0>]
		}
		bump_size 1/1
		scale x * board_width
		scale z * board_length
		warp {repeat z * board_length}
		warp {repeat x * board_width offset z * board_length/2}
	}
}

#declare GSprites_Hardwood_Texture_C = texture
{
	#local board_length = 1/2;
	#local board_width = 1/8;
	#local Norml_1 = normal
	{
		gradient x
		slope_map
		{
			[0/8 <0,1,>]
			[1/8 <0,1,>]
			[1/8 <1,0,>]
			[7/8 <1,0,>]
			[7/8 <0,-1,>]
			[8/8 <0,-1,>]
		}
	}
	#local Norml_2 = normal
	{
		gradient z
		slope_map
		{
			[00/32 <0,1,>]
			[01/32 <0,1,>]
			[01/32 <1,0,>]
			[31/32 <1,0,>]
			[31/32 <0,-1,>]
			[32/32 <0,-1,>]
		}
	}
	pigment
	{
		cells
		color_map
		{
			[0 color rgb <159,114,053,>/255]
			[1/2 color rgb <139,055,027,>/255]
			[1 color rgb <103,053,028,>/255]
		}
		scale x * board_width
		scale z * board_length
		scale y * board_width
		warp {repeat z * board_length * 2}
		warp {repeat x * board_width offset <0,1,board_length/2,>}
	}
	finish {GSprites_Default_Finish}
	normal
	{
		gradient z
		normal_map
		{
			[00/32 Norml_2]
			[01/32 Norml_2]
			[01/32 Norml_1]
			[31/32 Norml_1]
			[31/32 Norml_2]
			[32/32 Norml_2]
		}
		bump_size GSprites_Height/GSprites_Width
		scale x * board_width
		scale z * board_length
		scale y * board_width
		warp {repeat z * board_length}
		warp {repeat x * board_width offset z * board_length/2}
	}
	no_bump_scale
}

#declare GSprites_Tile_Texture_A = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <72,108,113,>/255]
//			[1 color rgb 3/4]
		}
		warp {repeat z}
		warp {repeat x}
	}
	finish
	{
		GSprites_Default_Finish
		phong 1
		phong_size 250
	}
}

#declare GSprites_Tile_Texture_B = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <44,81,91,>/255]
//			[1 color rgb 3/4]
		}
		warp {repeat z}
		warp {repeat x}
	}
	finish
	{
		GSprites_Default_Finish
		phong 1
		phong_size 250
	}
}

#declare GSprites_Tile_Texture_C = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb 1/4]
//			[1 color rgb 3/4]
		}
		warp {repeat z}
		warp {repeat x}
	}
	finish
	{
		GSprites_Default_Finish
		phong 1
		phong_size 250
	}
}

#declare GSprites_Tile_Texture_D = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <204,208,195,>/255]
		}
		warp {repeat z}
		warp {repeat x}
	}
	finish
	{
		GSprites_Default_Finish
		phong 1
		phong_size 250
	}
}

#declare GSprites_Grout_Texture_A = texture
{
	#local Norml_1 = normal
	{
		gradient x
		slope_map
		{
			[00/32 <0,1,>]
			[01/32 <1,0,>]
			[31/32 <1,0,>]
			[32/32 <0,-1,>]
		}
	}
	#local Norml_2 = normal
	{
		gradient z
		slope_map
		{
			[00/32 <0,1,>]
			[01/32 <1,0,>]
			[31/32 <1,0,>]
			[32/32 <0,-1,>]
		}
	}
	pigment {color rgb 1/2}
	finish
	{
		GSprites_Default_Finish
		phong 1
		phong_size 250
	}
	normal
	{
		gradient z
		normal_map
		{
			[00/32 Norml_2]
			[01/32 Norml_1]
			[31/32 Norml_1]
			[32/32 Norml_2]
		}
		bump_size GSprites_Height/GSprites_Width
		warp {repeat z}
		warp {repeat x offset z * 1/2}
	}
	no_bump_scale
	translate <-1/2,0,-1/2,>
}

#declare GSprites_Grout_Texture_B = texture
{
	#local Norml_1 = normal
	{
		gradient x
		slope_map
		{
			[00/32 <0,1,>]
			[01/32 <1,0,>]
			[31/32 <1,0,>]
			[32/32 <0,-1,>]
		}
	}
	#local Norml_2 = normal
	{
		gradient z
		slope_map
		{
			[00/32 <0,1,>]
			[01/32 <1,0,>]
			[31/32 <1,0,>]
			[32/32 <0,-1,>]
		}
	}
	pigment {color rgb 1}
	finish
	{
		GSprites_Default_Finish
		phong 1
		phong_size 250
	}
	normal
	{
		gradient z
		normal_map
		{
			[00/32 Norml_2]
			[01/32 Norml_1]
			[31/32 Norml_1]
			[32/32 Norml_2]
		}
		bump_size GSprites_Height/GSprites_Width
		warp {repeat z}
		warp {repeat x offset z * 1/2}
	}
	no_bump_scale
	translate <-1/2,0,-1/2,>
}
