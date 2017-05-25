// Video game sprites collection for POV-Ray
// *****************************************
// Author: Michael Horvath
// Website: http://isometricland.com/povray/povray.php
// This file is licensed under the terms of the CC-LGPL.

// Notes: Walls are designed to be rendered as 16-frame 
// animations. Simply remove the GSprites_North, GSprites_West, 
// etc., declarations in order to have the sprites be affected 
// in this way by the clock value.
// +ki0 +kf1 +kfi0 +kff15 +kc
// +k0.5

//#declare GSprites_Stretch	= on;
//#declare GSprites_Tiles	= 2;
#include "GSprites_Scene_settings.inc"			// Source of the camera and lighting code
#include "GSprites_Walls_prototypes.inc"		// Source of the object components


// -------------------------------------------------------------

#declare GSprites_North	= 1;			// is the wall connected on this side? (0 or 1)
#declare GSprites_East	= 1;			// ...
#declare GSprites_South	= 0;			// ...
#declare GSprites_West	= 1;			// ...

// There is a slight issues with the texture where the wall 
// meets at an intersection. I hope to resolve it sometime in 
// the future.

object
{
	GSprites_Guts_Tube_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector*2
}

// There is a slight issues with the texture where the wall 
// meets at an intersection. I hope to resolve it sometime in 
// the future.
object
{
	GSprites_Techy_Tube_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height)
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector*2
}

object
{
	GSprites_Fence_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height)
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector*2
}

object
{
	GSprites_Razor_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height/2,240)
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector*2
}


// -------------------------------------------------------------

#declare GSprites_North	= 0;			// is the wall connected on this side? (0 or 1)
#declare GSprites_East	= 1;			// ...
#declare GSprites_South	= 0;			// ...
#declare GSprites_West	= 1;			// ...

object
{
	GSprites_Hospital_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height,GSprites_Thick)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Restaraunt_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height,GSprites_Thick)
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Block_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height,GSprites_Thick)
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Stone_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height,GSprites_Thick*2)
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector
}


// -------------------------------------------------------------

#declare GSprites_North	= 1;			// is the wall connected on this side? (0 or 1)
#declare GSprites_East	= 1;			// ...
#declare GSprites_South	= 0;			// ...
#declare GSprites_West	= 0;			// ...

object
{
	GSprites_Fortress_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height/2,GSprites_Width/3)
	translate GSprites_Left_Vector*+3/2
}

object
{
	GSprites_Arena_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height/4,GSprites_Seed,0,200)
	translate GSprites_Left_Vector*-1/2
}


// -------------------------------------------------------------

#declare GSprites_North	= 1;			// is the wall connected on this side? (0 or 1)
#declare GSprites_East	= 0;			// ...
#declare GSprites_South	= 1;			// ...
#declare GSprites_West	= 0;			// ...

object
{
	GSprites_Fortress_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height/2,GSprites_Width/3)
	translate GSprites_Left_Vector*+1/2
}

object
{
	GSprites_Arena_Wall_Object(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,GSprites_Height/4,GSprites_Seed,0,200)
	translate GSprites_Left_Vector*-3/2
}
