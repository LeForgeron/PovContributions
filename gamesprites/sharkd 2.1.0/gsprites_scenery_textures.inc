// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "finish.inc"
#include "metals.inc"
#include "GSprites_Walls_textures.inc"


// -------------------------------------------------------------

#declare GSprites_Boulders_Scenery_Normal_A = normal
{
	bozo
	turbulence 2
	slope_map
	{
		[0.00 <+0,+1>]
		[0.40 <+1,+1>]
		[0.45 <+0,+0>]
		[0.50 <-1,+1>]
		[1.00 <+0,-1>]
	}
	scale 1/2
}

#declare GSprites_Boulders_Scenery_Texture_A = texture
{
	pigment {color rgb 1/3}
	finish {GSprites_Default_Finish}
	normal {GSprites_Boulders_Scenery_Normal_A}
}

#declare GSprites_Boulders_Scenery_Texture_B = texture
{
	pigment {color rgb <1/2,1,1,>}
	finish
	{
		GSprites_Default_Finish
		phong 1
		phong_size 1
		specular 1
	}
	normal {GSprites_Boulders_Scenery_Normal_A}
}

#declare GSprites_Boulders_Scenery_Texture_C = texture
{
	bozo
	turbulence 2
	texture_map
	{
		[0/2 GSprites_Boulders_Scenery_Texture_A]
		[1/2 GSprites_Boulders_Scenery_Texture_A]
		[1/2 GSprites_Boulders_Scenery_Texture_B]
	}
}

#declare GSprites_Boulders_Scenery_Texture_D = texture
{
	GSprites_Plain_Gray
	normal {GSprites_Faceted_Wall_Normal_A}
	finish {GSprites_Default_Finish}
}

#declare GSprites_Purple_Scenery_Texture = texture
{
	pigment {color rgb <137,073,171,>/255}
	normal {GSprites_Faceted_Wall_Normal_A}
	finish {GSprites_Default_Finish}
}

#declare GSprites_Gold_Scenery_Texture = texture
{
	T_Gold_1A
	finish {GSprites_Default_Finish phong 1 phong_size 1}
}

#declare GSprites_Grass_Scenery_Texture = texture
{
	pigment { color rgb <064,104,72,>*2/255 }
	finish {GSprites_Default_Finish}
}
