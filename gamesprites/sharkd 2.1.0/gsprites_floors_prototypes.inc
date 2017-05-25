// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "GSprites_Floors_textures.inc"


// -------------------------------------------------------------
// Macros for the various floor prototypes

#macro GSprites_Tile_Floor_Prototype(Tiles_Width,Tiles_Height,Tiles_Number,Tiles_Stagger)
	union
	{
		#local Hgh = Tiles_Height;
		#local Wid = Tiles_Width * GSprites_Tiles_Factor;
		#local Number = Tiles_Number * GSprites_Tiles_Factor;
		#local Factor = 1 - 1/Number;
		#local Count1 = 0;
		#while (Count1 < Number)
			#local Count2 = 0;
			#local Modulos = mod(Count1*3,2);
			#local AddOne = Number;
			#if ((Modulos != 0) & (Tiles_Stagger = 1))
				#local AddOne = AddOne + 1;
			#end
			#while (Count2 < AddOne)
				bicubic_patch
				{
					type 0 flatness 0
					u_steps 4 v_steps 4
					<0+Wid*3/3,000,0+Wid*3/3,>, <0+Wid*2/3,000,0+Wid*3/3,>, <0+Wid*1/3,000,0+Wid*3/3,>, <0+Wid*0/3,000,0+Wid*3/3,>
					<0+Wid*3/3,000,0+Wid*2/3,>, <0+Wid*2/3,Hgh,0+Wid*2/3,>, <0+Wid*1/3,Hgh,0+Wid*2/3,>, <0+Wid*0/3,000,0+Wid*2/3,>
					<0+Wid*3/3,000,0+Wid*1/3,>, <0+Wid*2/3,Hgh,0+Wid*1/3,>, <0+Wid*1/3,Hgh,0+Wid*1/3,>, <0+Wid*0/3,000,0+Wid*1/3,>
					<0+Wid*3/3,000,0+Wid*0/3,>, <0+Wid*2/3,000,0+Wid*0/3,>, <0+Wid*1/3,000,0+Wid*0/3,>, <0+Wid*0/3,000,0+Wid*0/3,>
					scale 1/Number * 15/16
					translate <-Wid/2,0,-Wid/2,>
					translate x * Count1 * Wid/Number
					translate z * Count2 * Wid/Number
					#local Modulos = mod(Count1*3,2);
					#if ((Modulos != 0) & (Tiles_Stagger = 1))
						translate z * -Wid/Number/2
					#end
				}
				#local Count2 = Count2 + 1;
			#end
			#local Count1 = Count1 + 1;
		#end
		clipped_by {GSprites_Clip_Box}
	}
#end

// Simple fake shadow
#macro GSprites_Shadow_Floor_Prototype(Tiles_Width)
	disc
	{
		0, y, 1
		pigment
		{
			spherical
			color_map {[0 color rgbt <0,0,0,1,>][1 color rgbt <0,0,0,0,>]}
		}
		scale Tiles_Width/2
	}
#end


// -------------------------------------------------------------
// Definitions for the various pre-defined floor types

#macro GSprites_Tile_Floor_Object_A(Tiles_Width,Tiles_Height)
	union
	{
		object {GSprites_Basic_Floor(Tiles_Width)			texture {GSprites_Grout_Texture_B scale Tiles_Width}}
		object {GSprites_Tile_Floor_Prototype(Tiles_Width,2,2,0)	texture {GSprites_Tile_Texture_D scale Tiles_Height}}
	}
#end

#macro GSprites_Tile_Floor_Object_B(Tiles_Width,Tiles_Height)
	union
	{
		object {GSprites_Basic_Floor(Tiles_Width)			texture {GSprites_Grout_Texture_A scale Tiles_Width}}
		object {GSprites_Tile_Floor_Prototype(Tiles_Width,4,4,1)	texture {GSprites_Tile_Texture_A scale Tiles_Height}}
	}
#end

#macro GSprites_Tile_Floor_Object_C(Tiles_Width,Tiles_Height)
	union
	{
		object {GSprites_Basic_Floor(Tiles_Width)			texture {GSprites_Grout_Texture_A scale Tiles_Width}}
		object {GSprites_Tile_Floor_Prototype(Tiles_Width,4,4,1)	texture {GSprites_Tile_Texture_C scale Tiles_Height}}
	}
#end

#macro GSprites_Tile_Floor_Object_D(Tiles_Width,Tiles_Height)
	union
	{
		object {GSprites_Basic_Floor(Tiles_Width)			texture {GSprites_Grout_Texture_A scale Tiles_Width}}
		object {GSprites_Tile_Floor_Prototype(Tiles_Width,2,4,0)	texture {GSprites_Tile_Texture_B scale Tiles_Height}}
	}
#end

#macro GSprites_Hardwood_Floor_Object_A(Tiles_Width)
	object {GSprites_Basic_Floor(Tiles_Width)				texture {GSprites_Hardwood_Texture_A scale Tiles_Width}}
#end

#macro GSprites_Hardwood_Floor_Object_B(Tiles_Width)
	object {GSprites_Basic_Floor(Tiles_Width)				texture {GSprites_Hardwood_Texture_B scale Tiles_Width}}
#end

#macro GSprites_Hardwood_Floor_Object_C(Tiles_Width)
	object {GSprites_Basic_Floor(Tiles_Width)				texture {GSprites_Hardwood_Texture_C scale Tiles_Width}}
#end

#macro GSprites_Shadow_Floor_Object(Tiles_Width)
	GSprites_Shadow_Floor_Prototype(Tiles_Width)
#end
