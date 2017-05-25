// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.


// -------------------------------------------------------------

// currently used. so-so.
#declare GSprites_Hills_Texture_K = texture
{
	pigment
	{
		gradient y
		color_map
		{
//			[0 color rgb <064,104,072,>/255]
//			[1/2 color rgb <140,123,93,>/255]
//			[1 color rgb 1]
			[0 color rgb <073,116,060,>/255]
			[1/3 color rgb <160,160,80,>/255]
			[1 color rgb 1]
		}
		scale 36 *  GSprites_MaxSteps * 1.0000001
	}
	finish {GSprites_Default_Finish}
}

// kind of bright with Lights_Method 1, great with Lights_Method 0.
#declare GSprites_Hills_Texture_J = texture
{
	#local Body_Pigment = pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <073,116,060,>/255]
			[1/3 color rgb <160,160,80,>/255 * 5/4]
			[1 color rgb 1]
		}
	}
	#local Cap_Pigment = pigment {color rgb 1}
	pigment
	{
		gradient y
		pigment_map
		{
			[00/12 Body_Pigment]
			[10/12 Body_Pigment]
//			[10/12 Cap_Pigment]
//			[12/12 Cap_Pigment]
			[12/12 Body_Pigment]
		}
		scale 36 * GSprites_MaxSteps * 1.0000001
	}
	finish {GSprites_Default_Finish}
}

// this one is the most 'correct' so far. used for the bicubic patch. ugly. the only macro.
#macro GSprites_Hills_Texture_H(Tiles_Height,Tiles_MaxHeight)
	#local Hgh = Tiles_Height;
	#local MaxHgh = Tiles_MaxHeight;
	texture
	{
		pigment
		{
			#local Scale = Hgh * (GSprites_MaxSteps-1) + MaxHgh;
			gradient y
			color_map
			{							// old settings for when light intensity was 1 and ambient was 0
				[0 color rgb <72,120,56,>/255]			// should use 80,125,60?
				[1/2 color rgb <72,120,56,>/255]		// 2/3
				[3/4 color rgb <140,120,93,>/255]		// <160,160,80,>/255 * 5/4
				[7/8 color rgb 3/4]
				[7/8 color rgb 1]
				[1 color rgb 1]
			}
			scale 2 * Scale * 1.0000001
			translate y * Scale
			noise_generator 3
			warp
			{
				black_hole <0,0,0,>, Hgh/2
				repeat Hgh
				strength 10
				falloff 3
				turbulence Hgh/8
				inverse
			}
			warp {turbulence 4}
		}
		finish {GSprites_Default_Finish /*crand 0.00*/}
		normal {dents 0.5 /*wrinkles 0.1*/}
	}
#end

// this is the one I used, initially, back when ambient and diffuse were set to their defaults, and light intensity was 1. Colors are ok.
#declare GSprites_Hills_Texture_F = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <72,120,56,>/255]
			[1/3 color rgb <160,160,80,>/255]		// * 5/4
			[1 color rgb 1]
		}
		scale 36 * GSprites_MaxSteps * 1.0000001
	}
	finish {GSprites_Default_Finish}
}

// black-white gradient for heightfield generation
#declare GSprites_Hills_Texture_E = texture
{
	pigment
	{
		gradient y
		color_map {[0 color rgb 0][1 color rgb 1]}
		scale 36 * GSprites_MaxSteps * 1.0000001
	}
	finish {GSprites_Default_Finish}
}

// must multiply lightsource values by 1.5 and set ambient and diffuse to their default amounts.
#declare GSprites_Hills_Texture_C = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <72,120,56,>/255 / 1.5]
			[1/3 color rgb <160,160,80,>/255 / 1.0]
			[2/3 color rgb 1/2]
			[1 color rgb 3/4]
		}
		scale 36 * GSprites_MaxSteps * 1.0000001
	}
	finish {GSprites_Default_Finish}
}

// must multiply lightsource values by 1.5 and set ambient and diffuse to their default amounts.
#declare GSprites_Hills_Texture_B = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <72,120,56,>/255 / 1.5]
			[1/2 color rgb <160,160,80,>/255 / 1.0]
			[1 color rgb 3/4]
		}
		scale 36 * GSprites_MaxSteps * 1.0000001
	}
	finish {GSprites_Default_Finish}
}

// must multiply lightsource values by 1.5 and set ambient and diffuse to their default amounts.
#declare GSprites_Hills_Texture_A = texture
{
	pigment
	{
		gradient y
		color_map
		{
			[0 color rgb <72,120,56,>/255 / 1.5]
			[1/2 color rgb <160,160,80,>/255 / 1.5]
			[1 color rgb 3/4]
		}
		scale 36 * GSprites_MaxSteps * 1.0000001
	}
	finish {GSprites_Default_Finish}
}
