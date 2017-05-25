// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "GSprites_Scene_settings.inc"			// Source of the camera and lighting code
#include "GSprites_Scenery_prototypes.inc"		// Source of the object components


// -------------------------------------------------------------
// City block - requires "city.inc" by Chris Colefax

object
{
	GSprites_City_Scenery_Object(GSprites_Width,GSprites_Height/4,GSprites_Seed,true)
	translate GSprites_Left_Vector*+3/2
}

// Purple zigguraut - requires "pyramid.mcr" by Fabien Mosen
object
{
	GSprites_Zigguraut_Scenery_Object(GSprites_Width/2)
	translate GSprites_Left_Vector*+1/2
}

// Temple
object
{
	GSprites_Temple_Scenery_Object(GSprites_Width/3)
	translate GSprites_Left_Vector*-1/2
}

// Geodesic dome - requires "sphere.inc" by Shuhei Kawachi
object
{
	GSprites_Geodome_Scenery_Object(GSprites_Width)
	translate GSprites_Left_Vector*-3/2
}

// Grass - requires "grasspatch.inc" by Josh English
object
{
	GSprites_Grass_Scenery_Object(GSprites_Width,GSprites_Height/32,2,GSprites_Seed)
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector
}

// Dead tree - requires "m_tree.mcr" by Gilles Tran
object
{
	GSprites_DeadTreeField_Scenery_Object(GSprites_Width,GSprites_Height/4,8,GSprites_Seed,1)
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector
}

// Electrical generator
object
{
	GSprites_Generator_Scenery_Object(GSprites_Width/3)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector*2
}

// Rock boulders
object
{
	GSprites_BoulderField_Scenery_Object(GSprites_Width,GSprites_Height/8,8,GSprites_Seed,1)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector
}

// Ferns - requires "veg.inc" by Joerg Schrammel and Stig Bachmann Nielsen
object
{
	GSprites_FernField_Scenery_Object(GSprites_Width,GSprites_Height/4,32,GSprites_Seed,1)
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector
}

// Coniferous trees
object
{
	GSprites_PineField_Scenery_Object(GSprites_Width,GSprites_Height/8,32,GSprites_Seed,1)
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector*2
}

// Deciduous trees
object
{
	GSprites_OakField_Scenery_Object(GSprites_Width,GSprites_Height/8,32,GSprites_Seed,1)
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector*2
}

// Redwood trees - requires "veg.inc" by Joerg Schrammel and Stig Bachmann Nielsen
object
{
	GSprites_RedwoodField_Scenery_Object(GSprites_Width,GSprites_Height/8,32,GSprites_Seed,1)
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector*2
}

// Road barriers
object
{
	GSprites_BarrierField_Scenery_Object(GSprites_Width-GSprites_Height/8,GSprites_Height/16,8,GSprites_Seed,2)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector*3
}
