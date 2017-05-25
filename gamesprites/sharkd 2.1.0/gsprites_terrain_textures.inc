// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.


// -------------------------------------------------------------

// green->green->beige bozo
#declare GSprites_Grass_Texture_A = texture
{

	pigment
	{
//		color rgb <72,120,56,>/255

		granite
		color_map
		{
//			[0 color rgb <065,105,075,>/255]
			[0 color rgb <073,116,060,>/255]
			[1 color rgb <080,125,060,>/255]
//			[1 color rgb <140,120,093,>/255]
//			[1 color rgb <160,160,80,>/255]
		}
		scale 32
		noise_generator 3
		warp {turbulence 4}

	}
	finish {GSprites_Default_Finish crand 0.05}
//	normal {bozo 32 scale 32}
	rotate x * 90
	scale 32
	no_bump_scale
}

// mottled grass texture
#declare GSprites_Grass_Texture_B = texture
{
	// green->green bozo
	#local GreenBorder_Pattern = pigment
	{
		granite
		color_map
		{
			[0 color rgb <064,104,072,>/255]
			[1 color rgb <088,132,063,>/255]
	//		[1/2 color rgb <088,132,063,>/255*4/4]
	//		[1 color rgb <140,123,093,>/255*4/4]
		}
	//	scale 16
		warp {turbulence 0}
	}
	
	// green->green->beige bozo
	#local GreenGrass_Pattern = pigment
	{
		granite
		color_map
		{
			[0 color rgb <064,104,072,>/255]
			[1/2 color rgb <088,132,063,>/255]
			[1 color rgb <140,123,093,>/255]
		}
	//	scale 16
		warp {turbulence 0}
	}
	pigment
	{
		spherical
		pigment_map
		{
			[0 GreenBorder_Pattern]
//			[0 GreenGrass_Pattern]
			[1 GreenGrass_Pattern]
		}
		warp {turbulence 0}
	}
	scale 32
	finish {GSprites_Default_Finish}
	normal {bozo 32 scale 32}
	no_bump_scale
}

// beige->blonde height gradient
#declare GSprites_Desert_Texture_A = texture
{

	pigment
	{
		gradient y
		pigment_map {[0 color rgb <148,141,084,>/255][1 color rgb <240,236,179,>/255]}
	}
	finish {GSprites_Default_Finish crand 0.05}
//	normal {bozo 32 scale 32}
	no_bump_scale
}

// swirly dirt. use with small boulders
#declare GSprites_Desert_Texture_B = texture
{
	#local This_Scale = 32;
	pigment
	{
		bozo
		color_map {[0 color rgb <148,141,084,>/255][1 color rgb <240,236,179,>/255]}
		scale This_Scale
		noise_generator 3
		warp {turbulence 4}
	}
	finish {GSprites_Default_Finish crand 0.05}
	normal {bozo This_Scale scale This_Scale}
	rotate x * 90
	no_bump_scale
}

#declare GSprites_Desert_Texture_C = texture
{
	average
	texture_map {[0 GSprites_Desert_Texture_A][1 GSprites_Desert_Texture_B]}
}

// swirly gravel. use with small boulders
#declare GSprites_Gravel_Texture_A = texture
{
	#local This_Scale = 32;
	pigment
	{
		granite
		color_map {[0 color rgb 096/255][1 color rgb 192/255]}
		scale This_Scale
		noise_generator 3
		warp {turbulence 4}

	}
	finish {GSprites_Default_Finish}
	normal {bozo This_Scale scale This_Scale}
	rotate x * 90
	no_bump_scale
}

// sepid marsh texture
#declare GSprites_Marsh_Texture_A = texture
{
	#local This_Scale = 32;
	// green->blue bozo
	#local Putrid_Pattern = pigment
	{
		bozo
		color_map {[0 color rgb <073,116,060,>/255][1 color rgb <000,087,166,>/255]}
		warp {turbulence 2}
		noise_generator 1
	}
	// green bozo
	#local GreenEdges_Pattern = pigment
	{
		bozo
		color_map {[0 color rgb <064,104,072,>/255*4/4]}
		warp {turbulence 0}
	}
	pigment
	{
		spherical
		pigment_map
		{
			[0/2 GreenEdges_Pattern]
//			[1/2 Putrid_Pattern]
			[2/2 Putrid_Pattern]
		}
	}
	finish {GSprites_Default_Finish}
//	normal {bozo This_Scale scale This_Scale}
	no_bump_scale
}

// sepid marsh texture
#declare GSprites_Marsh_Texture_B = texture
{
	#local This_Scale = 32;
	// green->blue bozo
	#local Putrid_Pattern = pigment
	{
		bozo
		color_map
		{
//			[0 color rgb <140,123,093,>/255]
			[0 color rgb <073,116,060,>/255]
//			[1 color rgb <000,087,166,>/255]
			[1 color rgb <000,044,044,>/255]
		}
		warp {turbulence 2}
		noise_generator 1
	}
	// green bozo
	#local GreenEdges_Pattern = pigment
	{
		bozo
		color_map
		{
			[0 color rgb <064,104,072,>/255]
//			[1 color rgb <088,132,063,>/255]
//			[1 color rgb <140,123,093,>/255]
		}
		warp {turbulence 0}
	}
	pigment
	{
		spherical
		pigment_map
		{
			[0 GreenEdges_Pattern]
			[1/2 Putrid_Pattern]
			[1 Putrid_Pattern]
		}
	}
	finish {GSprites_Default_Finish}
//	normal {bozo This_Scale scale This_Scale}
	no_bump_scale
}

// swirly dirt. use with small boulders
#declare GSprites_Dirt_Texture_A = texture
{
	#local This_Scale = 32;
	pigment
	{
		granite
		color_map {[0 color rgb <098,064,030,>/255][1 color rgb <140,120,093,>/255]}
		scale This_Scale
		noise_generator 3
		warp {turbulence 4}

	}
	finish {GSprites_Default_Finish}
//	normal {bozo This_Scale scale This_Scale}
	rotate x * 90
	no_bump_scale
}

// brown->beige height gradient
#declare GSprites_Dirt_Texture_B = texture
{
	#local This_Scale = 32;
	pigment
	{
		gradient y
		pigment_map {[0 color rgb <098,064,030,>/255][1 color rgb <140,123,093,>/255]}
	}
	finish {GSprites_Default_Finish}
//	normal {bozo This_Scale scale This_Scale}
	no_bump_scale
}

#declare GSprites_Water_Texture_A = texture
{
	pigment {color rgbt <0/4,1/4,2/4,2/4,>}
	finish
	{
		specular 1
		brilliance 1
		reflection {0.1}
		ambient 0
//		diffuse 0
	}
}

#declare GSprites_Road_Stripe_Texture_A = texture
{
	pigment {color rgb 3/4}
	finish {GSprites_Default_Finish}
}

#declare GSprites_Road_Surface_Texture_A = texture
{
	pigment {color rgb 1/4}
	finish {GSprites_Default_Finish}
}
