// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

// Notes: Hills were designed to be rendered as 16-frame animations.
// Comment-out the GSprites_North, GSprites__West, etc., declarations 
// to have the hills be affected by the clock value.
// +ki0 +kf1 +kfi0 +kff15 +kc
// +k0.5

#declare GSprites_North = 1;				// is the hill connected on this side? (0 or 1)
#declare GSprites_East  = 1;				// ...
#declare GSprites_South = 1;				// ...
#declare GSprites_West  = 0;				// ...
#declare GSprites_MaxSteps = 4;				// the maximum number of steps (used for textures)
#declare GSprites_Step = 1;				// the current elevation level (from 1 to MaxSteps)
#include "GSprites_Scene_settings.inc"			// Source of the camera and lighting code
#include "GSprites_Hills_Prototypes.inc"		// Source of the object components


// -------------------------------------------------------------

object
{
	GSprites_Hill_Object_A(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*+3/2
}

object
{
	GSprites_Hill_Object_B(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Hill_Object_C(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2,GSprites_Height/2,GSprites_Seed)
	translate GSprites_Left_Vector*+3/2
	translate GSprites_Up_Vector*2
}


// -------------------------------------------------------------

#declare GSprites_Step = 2;				// the current elevation level. (from 1 to MaxSteps)
#include "GSprites_Hills_Prototypes.inc"		// Source of the object components


// -------------------------------------------------------------

object
{
	GSprites_Hill_Object_A(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*+1/2
}

object
{
	GSprites_Hill_Object_B(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Hill_Object_C(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2,GSprites_Height/2,GSprites_Seed)
	translate GSprites_Left_Vector*+1/2
	translate GSprites_Up_Vector*2
}


// -------------------------------------------------------------

#declare GSprites_Step = 3;				// the current elevation level. (from 1 to MaxSteps)
#include "GSprites_Hills_Prototypes.inc"		// Source of the object components


// -------------------------------------------------------------

object
{
	GSprites_Hill_Object_A(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*-1/2
}

object
{
	GSprites_Hill_Object_B(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Hill_Object_C(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2,GSprites_Height/2,GSprites_Seed)
	translate GSprites_Left_Vector*-1/2
	translate GSprites_Up_Vector*2
}


// -------------------------------------------------------------

#declare GSprites_Step = 4;				// the current elevation level. (from 1 to MaxSteps)
#include "GSprites_Hills_Prototypes.inc"		// Source of the object components


// -------------------------------------------------------------

object
{
	GSprites_Hill_Object_A(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*-3/2
}

object
{
	GSprites_Hill_Object_B(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2)
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector
}

object
{
	GSprites_Hill_Object_C(GSprites_North,GSprites_West,GSprites_South,GSprites_East,GSprites_Width,GSprites_Height/2,GSprites_Height/2,GSprites_Seed)
	translate GSprites_Left_Vector*-3/2
	translate GSprites_Up_Vector*2
}
