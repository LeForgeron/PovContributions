// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

// Notes: Roads were designed to be rendered as 16-frame animations.
// Simply comment-out the GSprites_North, GSprites_West, etc., 
// declarations to have the sprites be affected by the clock value.
// The clock doesn't really matter for the other sprites.
// +ki0 +kf1 +kfi0 +kff15 +kc
// +k0.5

#declare GSprites_North = 1;			// is the road connected on this side? (0 or 1)
#declare GSprites_East  = 1;			// ...
#declare GSprites_South = 0;			// ...
#declare GSprites_West  = 0;			// ...
#include "GSprites_Scene_settings.inc"			// Source of the camera and lighting code
#include "GSprites_Terrain_prototypes.inc"		// Source of the object components


// -------------------------------------------------------------

object
{
	GSprites_Water_Terrain_Object_A
	translate GSprites_Left_Vector*+3/2
}

object
{
	GSprites_Water_Terrain_Object_B
	translate GSprites_Left_Vector*+1/2
}

object
{
	GSprites_Dirt_Terrain_Object_A
	translate GSprites_Left_Vector*-1/2
}

object
{
	GSprites_Dirt_Terrain_Object_B
	translate GSprites_Left_Vector*-3/2
}

object
{
	GSprites_Desert_Terrain_Object_A
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Desert_Terrain_Object_B
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Desert_Terrain_Object_C
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Gravel_Terrain_Object_A
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Grass_Terrain_Object_A
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector*2
}

object
{
	GSprites_Grass_Terrain_Object_B
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector*2
}

object
{
	GSprites_Marsh_Terrain_Object_A
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector*2
}

object
{
	GSprites_Marsh_Terrain_Object_B
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector*2
}

object
{
	GSprites_Road_Terrain_Object_A
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector*3
}

object
{
	GSprites_Road_Terrain_Object_B
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector*3
}
