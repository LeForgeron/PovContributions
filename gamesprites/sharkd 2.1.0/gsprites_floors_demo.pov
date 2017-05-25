// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "GSprites_Scene_settings.inc"			// Source of the camera and lighting code
#include "GSprites_Floors_prototypes.inc"		// Source of the object components


// -------------------------------------------------------------

object
{
	GSprites_Tile_Floor_Object_A(GSprites_Width,GSprites_Height)
	translate GSprites_Left_Vector*+3/2
}

object
{
	GSprites_Tile_Floor_Object_B(GSprites_Width,GSprites_Height)
	translate GSprites_Left_Vector*+1/2
}

object
{
	GSprites_Tile_Floor_Object_C(GSprites_Width,GSprites_Height)
	translate GSprites_Left_Vector*-1/2
}

object
{
	GSprites_Tile_Floor_Object_D(GSprites_Width,GSprites_Height)
	translate GSprites_Left_Vector*-3/2
}

object
{
	GSprites_Hardwood_Floor_Object_A(GSprites_Width)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Hardwood_Floor_Object_B(GSprites_Width)
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Hardwood_Floor_Object_C(GSprites_Width)
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Shadow_Floor_Object(GSprites_Width)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector*2
}
