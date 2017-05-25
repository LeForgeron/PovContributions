// Video game sprites collection for POV-Ray
// *****************************************
// Author: Michael Horvath
// Website: http://isometricland.com/povray/povray.php
// This file is licensed under the terms of the CC-LGPL.


// -------------------------------------------------------------

// the innards of a frightening beast generated using TexRD
#macro GSprites_Guts_Straight_Texture()
	#local Angle_Fraction = asin(Tiles_Width/2/Tube_Radius)/pi;
	texture
	{
		pigment
		{
			image_map {png "GSprites_Guts_Texture.png"}
			translate y/2
			translate x/2
			rotate y * 180
			rotate z * 270
			scale Angle_Fraction
			translate x/2
			warp
			{
				cylindrical
				orientation z
				dist_exp 0
			}
		}
		finish {GSprites_Default_Finish}
		scale 1/Angle_Fraction
		translate -y/2
		scale Tiles_Width
		rotate y * -90
		rotate z * 90
		translate z * Tiles_Width
		translate y * Tiles_Width/2
	}
#end

#macro GSprites_Guts_Outer_Texture()
	texture
	{
		pigment
		{
			image_map {png "GSprites_Guts_Texture.png"}
			translate x * 1/2
			translate y * 1/2
			rotate x * 180
			scale 1/4
			warp
			{
				toroidal
				orientation z
				dist_exp 0
				major_radius Tiles_Width
			}
		}
		finish {GSprites_Default_Finish}
		translate y * Tiles_Height/2
	}
#end

#macro GSprites_Guts_Inner_Texture()
	texture
	{
		pigment
		{
			image_map {png "GSprites_Guts_Texture.png"}
			translate -x * (GSprites_Tiles_Factor - 1)/2
			translate -y * 1/2
			rotate y * 180
			scale <1/4,1/8,1/4,>
			warp
			{
				toroidal
				orientation z
				dist_exp 0
				major_radius -Tiles_Width
			}
		}
		finish {GSprites_Default_Finish}
		translate y * (Tiles_Height/2-Tiles_Width/2)
	}
#end

#declare GSprites_Guts_Roof_Texture = texture
{
	pigment {image_map {png "GSprites_Guts_Texture.png"}}
	finish {GSprites_Default_Finish}
	translate x * 0.5
	rotate y * 180
	rotate x * 270
}

// a techy looking texture generated using HullGen
#macro GSprites_Tech_Straight_Texture()
	#local Angle_Fraction = asin(Tiles_Width/2/Tube_Radius)/pi;
	texture
	{
		pigment
		{
			image_map {png "GSprites_Tech_Texture.png"}
			translate y/2
			translate x/2
			rotate y * 180
			rotate z * 270
			scale Angle_Fraction
			translate x/2
			warp
			{
				cylindrical
				orientation z
				dist_exp 0
			}
		}
		finish {GSprites_Default_Finish}
		scale 1/Angle_Fraction
		translate -y/2
		scale Tiles_Width
		rotate y * -90
		rotate z * 90
		translate z * Tiles_Width
		translate y * Tiles_Width/2
	}
#end

#macro GSprites_Tech_Outer_Texture()
	#local Angle_Fraction = acos(Tiles_Width/2/Tube_Radius)/pi/4;
	texture
	{
		pigment
		{
			image_map {png "GSprites_Tech_Texture.png"}
			translate -x/2 * GSprites_Tiles_Factor
			translate -y/2
			rotate x * 180
			scale <1/4,1/5,1/4,>
			warp
			{
				toroidal
				orientation z
				dist_exp 0
				major_radius Tiles_Width
			}
		}
		finish {GSprites_Default_Finish}
	}
#end

#macro GSprites_Tech_Inner_Texture()
	texture
	{
		pigment
		{
			image_map {png "GSprites_Tech_Texture.png"}
			translate -x/2 * (GSprites_Tiles_Factor - 1)
			translate -y/2
			rotate y * 180
			scale 1/<4,8,4,>
			warp
			{
				toroidal
				orientation z
				dist_exp 0
				major_radius -Tiles_Width
			}
		}
		finish {GSprites_Default_Finish}
	}
#end

#declare GSprites_Tech_Roof_Texture = texture
{
	pigment {image_map {png "GSprites_Tech_Texture.png"}}
	finish {GSprites_Default_Finish}
	translate x * 0.5
	rotate y * 180
	rotate x * 270
}

// faceted
#declare GSprites_Faceted_Wall_Normal_A = normal
{
	facets          // generates facets on the surface
	coords 0.5      // for flat surfaces
	//size 1.0      // for curved surfaces
	no_bump_scale
	scale 8
}

// simplistic brick wall
#declare GSprites_Brick_Wall_Texture_a = texture
{
	pigment
	{
		brick      
		color Gray,          // color of mortar
		color Red            // color of brick
		brick_size <2,1,1>   // size of brick    (optional)
		mortar     0.4       // width of mortar  (optional)
	}
	finish {GSprites_Default_Finish}
/*
	normal
	{
		brick 0.1
		brick_size <2,1,1>   // size of brick    (optional)
		mortar     0.4       // width of mortar  (optional)
	}
*/
	translate x * 0.2
	translate y * 0.2
	scale 8
	no_bump_scale
}

#declare GSprites_Stone_Wall_Texture_A = texture
{
	pigment
	{
		crackle
		color_map {[0 color rgb 1/3][1 color rgb 2/3]}
		warp {turbulence y * 0.0}
		noise_generator 3
	}
	finish {GSprites_Default_Finish /*crand 0.2*/}
	normal
	{
		crackle 8		// crackled pattern
		warp {turbulence y * 0.0}
		noise_generator 3
	}
	scale 8
	no_bump_scale
}

// bumpy brick wall
#declare GSprites_Brick_Wall_Texture_B = texture
{
	pigment
	{
		brick      
		color rgb 1/2,		// color of mortar
		color rgb x		// color of brick
		brick_size <2,1,1>	// size of brick    (optional)
		mortar 0.2		// width of mortar  (optional)
		warp {turbulence y * 0.1}
		noise_generator 3
	}
	finish {GSprites_Default_Finish}
	normal
	{
		brick 1
		brick_size <2,1,1>	// size of brick    (optional)
		mortar 0.2		// width of mortar  (optional)
		warp {turbulence y * 0.1}
		noise_generator 3
	}
	translate x * 0.1
	translate y * 0.1
	scale 8
	no_bump_scale
}

// fence. use Thick = 0
#declare GSprites_Fence_Wall_Hash = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[00/16 color rgbt <1,1,1,1,>]
			[07/16 color rgbt <1,1,1,1,>]
			[07/16 color rgbt <1,1,1,0,>]
			[09/16 color rgbt <1,1,1,0,>]
			[09/16 color rgbt <1,1,1,1,>]
			[16/16 color rgbt <1,1,1,1,>]
		}
	}
	finish {GSprites_Default_Finish}
}

#declare GSprites_Fence_Wall_Texture = texture
{
	gradient x
	texture_map
	{
		[00/16 GSprites_Fence_Wall_Hash]
		[07/16 GSprites_Fence_Wall_Hash]
		[07/16 GSprites_Plain_White]
		[09/16 GSprites_Plain_White]
		[09/16 GSprites_Fence_Wall_Hash]
		[16/16 GSprites_Fence_Wall_Hash]
	}
	rotate z * 45
	scale 1/cos(pi/4)
}

// decent stone wall
#declare GSprites_Stone_Wall_Texture_B = texture
{
	pigment
	{
		crackle
		color_map
		{
			[0 color rgb 1/2]
			[1/2 color rgb <098,064,030,>/255]
			[1 color rgb <140,123,093,>/255]
		}
		warp {turbulence y * 0.0}
		noise_generator 3
	}
	finish {GSprites_Default_Finish /*crand 0.2*/}
	normal
	{
		crackle   8      // crackled pattern
		warp {turbulence y * 0.0}
		noise_generator 3
	}
	scale 8
	no_bump_scale
}

// faceted wall
#declare GSprites_Faceted_Wall_Texture_B = texture
{
	pigment
	{
//		color rgb <154,118,073,>/255
//		color rgb <192,160,128,>/255
		bozo
		color_map {[0 color rgb 1/2][1 color rgb <154,118,073,>/255]}
		scale 32
	}
	finish {GSprites_Default_Finish}
	normal
	{
		facets
		coords 0.5
		warp {turbulence y * 0}
		noise_generator 3
		scale 64
	}
	no_bump_scale
}

#declare GSprites_Plank_Wall_Texture_B = texture
{
	#local board_length = 1/2;
	#local board_width = 1/8;
	pigment
	{
		cells
		color_map
		{
			[0/2 color rgb <159,114,053,>/255]
			[1/2 color rgb <139,055,027,>/255]
			[2/2 color rgb <103,053,028,>/255]
		}
		scale <board_width,1,board_length,>
		warp {repeat z * board_length * 2}
		warp {repeat x * board_width offset z * board_length / 2}
		warp {repeat x * board_width * 2 offset y * 1}
	}
	finish {GSprites_Default_Finish}
	normal
	{
		gradient z
		//cells
		slope_map
		{
			[0 <0,1>]
//			[1/16 <0,0>]
//			[1/16 <1/2,0>]
//			[1/2 <1/2,0>]
			[1 <1,1>]
		}
		bump_size 1
		scale <board_width,1,board_length,>
		warp {repeat z * board_length}
		warp {repeat x * board_width offset z * board_length / 2}
	}
	rotate x * 90
	rotate y * 0
}

#declare GSprites_Plank_Wall_Texture_C = texture
{
	#local board_length = 1/2;
	#local board_width = 1/8;
	pigment
	{
		cells
		color_map
		{
			[0/2 color rgb <159,114,053,>/255]
			[1/2 color rgb <139,055,027,>/255]
			[2/2 color rgb <103,053,028,>/255]
		}
		scale <board_length,1,board_width,>
		warp {repeat x * board_length * 2}
		warp {repeat z * board_width offset <board_length/2,2,0,>}
		warp {repeat z * board_width * 2 offset y}
	}
	finish {GSprites_Default_Finish}
	normal
	{
		gradient z
		slope_map {[0 <0,1>][1 <1,1>]}
		bump_size 1
		scale <board_length,1,board_width,>
		warp {repeat x * board_length}
		warp {repeat z * board_width offset x * board_length / 2}
	}
	no_bump_scale
	rotate x * 90
	rotate y * 0
}

#declare GSprites_Plank_Wall_Texture_D = texture
{
	pigment
	{
		cells
		color_map
		{
			[0/2 color rgb <159,114,053,>/255]
			[1/2 color rgb <139,055,027,>/255]
			[2/2 color rgb <103,053,028,>/255]
		}
	}
	finish {GSprites_Default_Finish}
	translate x * 1/2
}

#macro GSprites_Plank_Wall_Texture_E()
	texture
	{
		#local board_length = 1/Cols;
		#local board_height = 1/Rows;
		pigment
		{
			cells
			color_map
			{
				[0 color rgb <159,114,053,>/255]
				[1/2 color rgb <139,055,027,>/255]
				[1 color rgb <103,053,028,>/255]
			}
			scale <board_length,board_height,board_length,>
/*
			warp {repeat x * board_length * 2}
			warp {repeat y * board_height offset <board_length/2,2,0,>}
			warp {repeat y * board_height * 2 offset y}
*/
			warp {repeat x * board_length * 2}
			warp {repeat z * board_length * 2}
			warp {repeat y * board_height offset <board_length/2,2,board_length/2,>}
		}
		finish {GSprites_Default_Finish}
		no_bump_scale
		scale <Tiles_Width,Tiles_Height,Tiles_Width,>
	}
#end

#macro GSprites_StoneBlock_Wall_Texture_A()
	texture
	{
		#local board_length = 1/Cols;
		#local board_height = 1/Rows;
		#local normal_gap = 1/6;
		#local Norml_1 = normal
		{
			gradient x
			slope_map
			{
				[0 <0,0,>]
				[0 + normal_gap * Cols/Rows <1,0,>]
				[1 - normal_gap * Cols/Rows <1,0,>]
				[1 <0,0,>]
			}
		}
		#local Norml_2 = normal
		{
			gradient y
			slope_map
			{
				[0 <0,0,>]
				[0 + normal_gap <1,0,>]
				[1 - normal_gap <1,0,>]
				[1 <0,0,>]
			}
		}
		pigment
		{
			cells
			color_map {[0 color rgb 1/3][1 color rgb 2/3]}
			scale <board_length,board_height,board_length,>
			warp {repeat x * board_length * 2}
			warp {repeat z * board_length * 2}
			warp {repeat y * board_height offset <board_length/2,2,board_length/2,>}
		}
		finish {GSprites_Default_Finish}
/*
		normal
		{
			gradient y
			normal_map
			{
				[00/6 Norml_2]
				[01/6 Norml_1]
				[05/6 Norml_1]
				[06/6 Norml_2]
			}
			bump_size 100
			scale <board_length,board_height,board_length,>
			warp {repeat x * board_length * 2}
			warp {repeat z * board_length * 2}
			warp {repeat y * board_height offset <board_length/2,2,board_length/2,>}
		}
*/
		no_bump_scale
		scale <Tiles_Width,Tiles_Height,Tiles_Width,>
	}
#end

#declare GSprites_StoneBlock_Wall_Texture_B = texture
{
	#local board_length = 1/2;
	#local board_width = 1/6;
	#local Pig_1 = pigment
	{
		bozo
		color_map {[0 color rgb 1/3][1 color rgb 2/3]}
	}
	#local Pig_2 = pigment
	{
		crackle
		color_map {[0 color rgb 1/3][1 color rgb 2/3]}
	}
	pigment
	{
		crackle
		pigment_map {[0 Pig_1][1 Pig_2]}
		scale <board_length,board_width,1,>
		warp {repeat x * board_length * 2}
		warp {repeat y * board_width offset x * board_length / 2}
		warp {repeat y * board_width * 2 offset z * 1}
	}
	finish {GSprites_Default_Finish}
	normal
	{
		boxed
		slope_map
		{
//			[0 <0,10000000>]
			[0 <0,0>]
			[1/16 <1,0>]
			[1 <1,0>]
		}
		bump_size 1/8
		scale <board_length,board_width,1,>
		warp {repeat x * board_length}
		warp {repeat y * board_width offset x * board_length / 2}
	}
}

#declare GSprites_StoneBlock_Wall_Texture_C = texture
{
	pigment
	{
		crackle
		color_map {[0 color rgb 1/8][1 color rgb <160,160,128>/255]}
		warp {turbulence y * 0.0}
		noise_generator 3
	}
	finish {GSprites_Default_Finish}
	normal
	{
		crackle 8
		warp {turbulence y * 0.0}
		noise_generator 3
	}
	scale 8
	no_bump_scale
}

#declare GSprites_Hospital_Wall_Texture_A = texture
{
	pigment {image_map {png "GSprites_Hospital_Texture.png"}}
	finish {GSprites_Default_Finish}
	translate	x * 0.5
	rotate		y * 180
}

#macro GSprites_Hospital_Wall_Texture_B(North,East,South,West)
	texture
	{
		#local Texture_N = texture {GSprites_Hospital_Wall_Texture_A scale <Tiles_Width,80,Tiles_Width,>*Tiles_Height/80}
		#local Texture_E = texture {GSprites_Plain_White}
		#local Texture_S = texture {GSprites_Hospital_Wall_Texture_A scale <Tiles_Width,80,Tiles_Width,>*Tiles_Height/80}
		#local Texture_W = texture {GSprites_Plain_White}
		#if ((North + East + South + West = 2) & ((North + South = 2) | (East + West = 2)))
			radial
			texture_map
			{
				[0/8 Texture_W]
				[1/8 Texture_W]
				[1/8 Texture_N]
				[3/8 Texture_N]
				[3/8 Texture_E]
				[5/8 Texture_E]
				[5/8 Texture_S]
				[7/8 Texture_S]
				[7/8 Texture_W]
				[8/8 Texture_W]
			}
			#if (North + South = 2)
				scale x * Tiles_Thick/Tiles_Width
			#else
				scale z * Tiles_Thick/Tiles_Width
			#end
		#else
			GSprites_Plain_White
		#end
	}
#end

#macro GSprites_Hospital_Wall_Texture_C(North,East,South,West)
	#if ((North + South = 2) & (North + East + South + West = 2))
		texture {Hospital_Wall_Texture_A scale <Tiles_Width,80,Tiles_Width,>*Tiles_Height/80 rotate y * 000}
	#else
		#if ((East + West = 2) & (North + East + South + West = 2))
			texture {GSprites_Hospital_Wall_Texture_A scale <Tiles_Width,80,Tiles_Width,>*Tiles_Height/80 rotate y * 000}
		#else
			texture {GSprites_Plain_White}
		#end
	#end
#end

#declare GSprites_Fortress_Wall_Texture = texture
{
	pigment {color rgb 1/2}
	finish {GSprites_Default_Finish}
	normal
	{
		facets		// generates facets on the surface
		coords	0.5	// for flat surfaces
		//size	1.0	// for curved surfaces
		scale	8
	}
	no_bump_scale
}

#declare GSprites_BlueGlass_Wall_Texture = texture
{
	pigment {color rgbt <0,0,1,3/4,>}
	finish {specular 0.5 brilliance 0.5}
}

#macro GSprites_Random_Wall_Texture(Tiles_Seed)
	texture
	{
		pigment {color rgb <rand(Tiles_Seed),rand(Tiles_Seed),rand(Tiles_Seed),>}
		finish {GSprites_Default_Finish}
	}
#end
