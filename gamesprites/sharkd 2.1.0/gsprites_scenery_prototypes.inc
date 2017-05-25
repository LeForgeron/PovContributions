// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "GSprites_Scenery_textures.inc"


// -------------------------------------------------------------
// City block - requires "city.inc" by Chris Colefax

#macro GSprites_City_Scenery_Prototype(Tiles_Width,Tiles_Height,Block_Size,City_Seed,Random_Height)
	#local Building_Width = Tiles_Width/Block_Size;		// the width of a building.
//	#local Storey_Height = 128/8;		// the height of each storey. (note: the ratio should always equal roughly 128/8.)
//	#local Block_Size = 2;			// the number of buildings per block.
	#local Blocks_Number = GSprites_Tiles;	// the number of blocks to render.
	#local Scale_Factor = 1;		// the scene is scaled down by this factor.
//	#local Random_Height = false;		// if enabled, building heights are randomized.
	#local Add_Roads = false;		// if enabled, roads are added between each block.
	#local Fit_To_Tile = false;		// if enabled, the scene is scaled so that it fits within the target 64-pixel wide sprite (this overrides Scale_Factor).
	#local Rotate_Y = clock * 1440;		// rotate the object around the Y-axis by this amount.
//	#local City_Seed = 0110999;		// seed for random city generator.
	
	// CREATE CITY AND SAVE TO FILE
	#local street_width = Tiles_Width/8;
	#local traffic_spacing = Tiles_Width/8;
	#local traffic_lanes = 2;
	#local pavement_width = Tiles_Width/16;
	#local buildings_per_block = Block_Size;
	#local building_gap = Tiles_Width/16;
	#if (Random_Height = true)
		#local building_height_turb = 1/2;
	#else
		#local building_height_turb = 0;
	#end
	#local building_height_falloff = 0;
	#local debug_progress = false;
	#local city_tileable = true;
	#local city_block_count = Blocks_Number;
	#local city_seed = (Rotate_Y + clock) * City_Seed;
	#local city_macro_file = "FILECITY.MCR"
	#local city_output_file = "MYCITY.INC"
	#if (Block_Size > 1)
		#local Is_Block_Gap = 1;
	#else
		#local Is_Block_Gap = 0;
	#end
	#if (city_tileable = true)
		#local Extra_Road = 0;
	#else
		#local Extra_Road = 1;
	#end
	#if (Add_Roads = 1)
		#local traffic_width = Tiles_Width/8;
		#local Road_Width = traffic_width * (traffic_lanes * 2 + 1);
	#else
		#local traffic_width = 0;
		#local Road_Width = 0;
	#end
	#local Roads_Number = Blocks_Number + Extra_Road;
	#local Gaps_Number = (Block_Size - 1) * Blocks_Number;
	#if (Fit_To_Tile = true)
		#local building_width = Building_Width;
	#else
		#local building_width = (Tiles_Width - pavement_width * 2 * Blocks_Number - building_gap * Gaps_Number - Road_Width * Roads_Number)/Block_Size/Blocks_Number;
	#end
	#local max_building_height = Tiles_Height;
	#local min_building_height = 0;
	#local Total_Size = Building_Width * Block_Size * Blocks_Number + pavement_width * 2 * Blocks_Number + building_gap * Gaps_Number + Road_Width * Roads_Number;
	#if (Fit_To_Tile = true)
//old method	#local Scale_Factor = Tiles_Width / Total_Size;
		#local Scale_Factor = (Total_Size - mod(Total_Size,Tiles_Width))/Total_Size;
	#else
		#local Scale_Factor = 1/Scale_Factor;
	#end
	#local city_transform = transform {rotate y * 180 scale Scale_Factor rotate y * Rotate_Y}
	#include "CITY.INC"
#end

// Purple zigguraut - requires "pyramid.mcr" by Fabien Mosen
#macro GSprites_Zigguraut_Scenery_Prototype(Tiles_Width)
	#include "pyramid.mcr"
	#include "shapes.inc"
	#include "shapes2.inc"
	union
	{
		difference
		{
			object {Pyramid_N(4,32,64)}
			box {<+14,+30,+14,>,<-14,+64,-14,>}
			plane {-y, -32}
			box {<+32,-08,+04,>,<-32,+08,-04,>}
			box {<+04,-08,+32,>,<-04,+08,-32,>}
			bounded_by {box {<-32,+00,-32>,<+32,+64,+32,>}}
			texture {Wall_Texture}
		}
		difference
		{
			box {<-10,+30,-10,>,<+10,+36,+10,>}
			box {<-02,+30,-12,>,<+02,+34,+12,>}
			box {<-12,+30,-02,>,<+12,+34,+02,>}
			bounded_by {box {<-32,+00,-32>,<+32,+64,+32,>}}
			texture {Wall_Texture}
		}
		object
		{
			Pyramid_N(4,12,3)
			//box {<-12,0,-12,>,<12,2,12>}
			texture {Cap_Texture}
			translate y * 36
		}
		object
		{
			#local Dode_Width = 1;
			//Dodecahedron
			Octahedron
			//rotate x * 45
			//rotate z * 45
			scale Dode_Width
			translate y * (39)
			texture {Cap_Texture}
		}
		scale Tiles_Width/64
	}
#end

#macro GSprites_Temple_Scenery_Prototype(Tiles_Width)
	#local Sides_N = 8;
	#local Rot_Vec = y*360/Sides_N;
	#local P_1 = <64/2,0,0,>;
	#local P_2 = vrotate(P_1,Rot_Vec);
	#local P_3 = vrotate(P_2,Rot_Vec);
	#local P_4 = vrotate(P_3,Rot_Vec);
	#local P_5 = vrotate(P_4,Rot_Vec);
	#local P_6 = vrotate(P_5,Rot_Vec);
	#local P_7 = vrotate(P_6,Rot_Vec);
	#local P_8 = vrotate(P_7,Rot_Vec);
	#local Door_Hole = cylinder {<-64/2,64/12,0,>,<+64/2,64/12,0,>,64/8}
	#local Temple_Prism = prism
	{
		linear_spline 0, 1, Sides_N,
		<P_1.x,P_1.z,>, <P_2.x,P_2.z,>, <P_3.x,P_3.z,>, <P_4.x,P_4.z,>, <P_5.x,P_5.z,>, <P_6.x,P_6.z,>, <P_7.x,P_7.z,>, <P_8.x,P_8.z,>
	}
	union
	{	
		// outer walls
		difference
		{
			object {Temple_Prism scale y * 64/2}
			object {Door_Hole}
			bounded_by {box {<-64/2,+00,-64/2>,<+64/2,+64,+64/2,>}}
			texture {Wall_Texture}
		}
		// top rim
		torus
		{
			64/2,64/32
			translate y * 64/2
			texture {Trim_Texture}
		}
		// columns
		#local Count_N = 0;
		#while (Count_N < Sides_N)
			#local P_c = vrotate(P_1,<0,45 * Count_N + 45/2,0,>);
			cylinder {P_c,P_c + y * 64/2,64/32 texture {Trim_Texture}}
			#local Count_N = Count_N + 1;
		#end
		// roof
		sphere
		{
			0,64/2
			scale y * 1/4
			translate y * 64/2
			texture {Roof_Texture}
		}
		// stupa
		sphere
		{
			0,64/16
			translate y * (64/2 + 64/8 + 64/16)
			texture {Knob_Texture}
		}
		// step #1
		object
		{
			Temple_Prism
			scale <09/8,64/16,09/8,>
			translate -y * 64/16
			texture {Steps_Texture}
		}
		// step #2
		object
		{
			Temple_Prism
			scale <10/8,64/16,10/8,>
			translate -y * 64/8
			texture {Steps_Texture}
		}
		translate y * 64/8
		scale Tiles_Width/64
	}
#end

// Geodesic dome - requires "sphere.inc" by Shuhei Kawachi
#macro GSprites_Geodome_Scenery_Prototype(Tiles_Width)
	#local R_Ten = 0.025/N;
	#local R_Hen = 0.025/N;
	#include "sphere.inc"
	#local Dome_Object = union
	{
		object {Ten texture {RibTexture}}
		object {Hen texture {RibTexture}}
		object {Men texture {PaneTexture}}
		scale 12
		translate <0,0,-20,>
	}
	intersection
	{
		union
		{
			object {Dome_Object rotate y * 000}
			object {Dome_Object rotate y * 090}
			object {Dome_Object rotate y * 180}
			object {Dome_Object rotate y * 270}
			cylinder {<-12,+00,+00,>,<+12,+00,+00,>,4}
			cylinder {<+00,+00,-12,>,<+00,+00,+12,>,4}
			cylinder {<+00,+00,+00,>,<+00,+04,+00,>,8}
			cylinder {<+00,+00,+00,>,<+00,+06,+00,>,4}
			//cone {<64/3,0,64/2,>,2,<64/3,64,64/2,>,1}
		}
		plane {-y,0}
		bounded_by {box {<-64/2,+00/2,-64/2,>,<+64/2,+64/1,+64/2,>}}
		texture {RibTexture}
		scale Tiles_Width/64
	}
#end

// Electrical generator
#macro GSprites_Generator_Scenery_Prototype(Tiles_Width)
	intersection
	{
		union
		{
			sphere {0,1 scale <64/6,64/2,64/2,> translate x * -64/3}
			sphere {0,1 scale <64/6,64/2,64/2,> translate x * +64/3}
			sphere {0,1 scale <64/6,64/2,64/2,> translate 0}
			sphere {0,1 scale 64/4 translate x * +64/4}
			sphere {0,1 scale 64/4 translate x * -64/4}
			//cylinder {<-3*64/8,0,0,>,<+3*64/8,0,0,>,64/4}
			cylinder {<-64/2,0,0,>,<+64/2,0,0,>,64/3}
			texture {Generator_Texture}
		}
		plane {-y, 0}
		bounded_by {box {<-64/2,+00/2,-64/2,>,<+64/2,+64/1,+64/2,>}}
		scale Tiles_Width/64
	}
#end

// Tiles flipping not implemented fully yet.
#macro GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,Trees_Object,Trees_Number,Tiles_Seed,Tiles_Mode,Rand_Height,Height_Factor)
	union
	{
		#local PosArray = array[Trees_Number];
		#local Count_1 = 0;
		#while (Count_1 < Trees_Number)
			#local V_Value = rand(Tiles_Seed);
			#switch (Tiles_Mode)
				#case (1)
					#local T_Value = BetaDistribution(2,3,Tiles_Seed);
					#local U_Value = rand(Tiles_Seed);
					#local New_X = cos(U_Value * 2 * pi) * T_Value * Tiles_Width/2;
					#local New_Z = sin(U_Value * 2 * pi) * T_Value * Tiles_Width/2;
				#break
				#case (2)
					#local T_Value = rand(Tiles_Seed);
					#local U_Value = rand(Tiles_Seed);
					#local New_X = (T_Value * Tiles_Width - Tiles_Width/2);
					#local New_Z = (U_Value * Tiles_Width - Tiles_Width/2);
				#break
				#case (3)
					#local T_Value = rand(Tiles_Seed);
					#local U_Value = rand(Tiles_Seed);
					#local New_X = (T_Value * U_Value * Tiles_Width - Tiles_Width/2) * 7/8;
					#local New_Z = ((1 - T_Value) * (1 - U_Value) * Tiles_Width - Tiles_Width/2) * 7/8;
				#break
			#end
			#local New_Pos = <New_X,0,New_Z,>;
			#local Bool = 1;
/*
			// check for intersecting objects
			#local Count_2 = 0;
			#while (Count_2 < Count_1)
				#local TreeDist = VDist(New_Pos, PosArray[Count_2]);
				#if (TreeDist < Tiles_Height/2)
					#local Bool = 0;
				#end
				#local Count_2 = Count_2 + 1;
			#end
*/
			#if (Bool = 1)
				#local PosArray[Count_1] = New_Pos;
				object
				{
					Trees_Object
					#if (Rand_Height = 1)
						scale (rand(Tiles_Seed) * Height_Factor + (1 - Height_Factor))
					#end
					rotate y * rand(Tiles_Seed) * 360
					translate New_Pos
					#if (Tiles_Mode = 3)
						rotate y * (Flip * 180)
					#end
				}
				#local Count_1 = Count_1 + 1;
			#end
		#end
	}
#end


// -------------------------------------------------------------
// Definitions for the various wall types

// City block - requires "city.inc" by Chris Colefax
#macro GSprites_City_Scenery_Object(Tiles_Width,Tiles_Height,Tiles_Seed,Random_Height)
	GSprites_City_Scenery_Prototype(Tiles_Width,Tiles_Height,2,Tiles_Seed,Random_Height)
#end

// Purple zigguraut - requires "pyramid.mcr" by Fabien Mosen
#macro GSprites_Zigguraut_Scenery_Object(Tiles_Width)
	#local Wall_Texture = GSprites_Purple_Scenery_Texture;
	#local Cap_Texture = GSprites_Gold_Scenery_Texture;
	GSprites_Zigguraut_Scenery_Prototype(Tiles_Width)
#end

// Golden temple - requires "pyramid.mcr" by Fabien Mosen
#macro GSprites_Temple_Scenery_Object(Tiles_Width)
	#local Wall_Texture = GSprites_Gold_Scenery_Texture;
	#local Trim_Texture = GSprites_Gold_Scenery_Texture;
	#local Steps_Texture = GSprites_Gold_Scenery_Texture;
	#local Roof_Texture = GSprites_Gold_Scenery_Texture;
	#local Knob_Texture = GSprites_Gold_Scenery_Texture;
	GSprites_Temple_Scenery_Prototype(Tiles_Width)
#end

// Geodesic dome - requires "sphere.inc" by Shuhei Kawachi
#macro GSprites_Geodome_Scenery_Object(Tiles_Width)
	#local N = 1;
	#local Half = 1;
	#local Method = 1;
	#local RibTexture = GSprites_Plain_White;
	#local PaneTexture = T_Glass1;
	GSprites_Geodome_Scenery_Prototype(Tiles_Width)
#end

// Electrical generator
#macro GSprites_Generator_Scenery_Object(Tiles_Width)
	#local Generator_Texture = GSprites_Plain_Pink;
	GSprites_Generator_Scenery_Prototype(Tiles_Width)
#end

// Grass - requires "grasspatch.inc" by Josh English
#macro GSprites_Grass_Scenery_Object(Tiles_Width,Tiles_Height,Blade_Density,Tiles_Seed)
	#include "grasspatch.inc"
	#local someseed = Tiles_Seed;#local xseed = Tiles_Seed;#local zseed = Tiles_Seed;
	#local Blade_Scale = Tiles_Height/64 * 8;
	#local Blade_Tex = GSprites_Grass_Scenery_Texture;
	#local Camera_Position = GSprites_Camera_Location;
	union {PlantPatch() scale Tiles_Width/8}
#end

// Dead tree - requires "m_tree.mcr" by Gilles Tran
#macro GSprites_DeadTree_Scenery_Object(Tiles_Height)
	#local txtTree = texture	// must use this name
	{
		#local TreeColor1 = pigment {color rgb <098,064,030,>/255}
		#local TreeColor2 = pigment {color rgb <140,123,093,>/255}
		pigment {bozo pigment_map {[0 TreeColor1][1 TreeColor2]}}
		normal {wrinkles 2 scale 0.3}
		finish {GSprites_Default_Finish}
	}
	#include "m_tree.mcr"
	object
	{
		Tree1
		finish {GSprites_Default_Finish}
		translate y * -6
		scale Tiles_Height/8
	}
#end
#macro GSprites_DeadTreeField_Scenery_Object(Tiles_Width,Tiles_Height,Trees_Number,Tiles_Seed,Tiles_Mode)
	GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,GSprites_DeadTree_Scenery_Object(Tiles_Height),Trees_Number,Tiles_Seed,Tiles_Mode,1,1/3)
#end

// Rock boulders
#macro GSprites_Boulder_Scenery_Object(Tiles_Height,Tiles_Seed)
	#local Boulder_Texture = GSprites_Boulders_Scenery_Texture_C;
	intersection
	{
		isosurface
		{
			function {(f_sphere(x, y, z, 1/4) - f_noise3d(x, y, z))}
			max_gradient 4
			contained_by {box {-1,1}}
			texture {Boulder_Texture}
			rotate rand(Tiles_Seed) * 360
			scale Tiles_Height
		}
		plane {-y,0}
	}
#end
#macro GSprites_BoulderField_Scenery_Object(Tiles_Width,Tiles_Height,Trees_Number,Tiles_Seed,Tiles_Mode)
	GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,GSprites_Boulder_Scenery_Object(Tiles_Height,Tiles_Seed),Trees_Number,Tiles_Seed,Tiles_Mode,1,1)
#end

// Coniferous trees
#macro GSprites_Pine_Scenery_Object(Tiles_Height)
	union
	{
		cylinder
		{
			<0,0,0,>,<0,8,0,>,2
			texture
			{
				pigment {color rgb <140,123,93,>/255 * 3/4}
				finish {GSprites_Default_Finish}
				normal {wrinkles 0.5}
			}
		}
		cone
		{
			<0,8,0,>,8,<0,32,0,>,0
			texture
			{
				pigment {color rgb <073,116,060,>/255 * 3/4}
				finish {GSprites_Default_Finish}
				normal {wrinkles}
			}
		}
		scale Tiles_Height/32
	}
#end
#macro GSprites_PineField_Scenery_Object(Tiles_Width,Tiles_Height,Trees_Number,Tiles_Seed,Tiles_Mode)
	GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,GSprites_Pine_Scenery_Object(Tiles_Height),Trees_Number,Tiles_Seed,Tiles_Mode,1,1/3)
#end

// Deciduous trees
#macro GSprites_Oak_Scenery_Object(Tiles_Height)
	union
	{
		cylinder
		{
			<0,0,0,>,<0,12,0,>,2
			texture
			{
				pigment {color rgb <140,123,93,>/255}
				finish {GSprites_Default_Finish}
			}
		}
		isosurface
		{
			#local Size = rand(Tiles_Seed) * 8 + 8;
			function {(f_sphere(x, y, z, 1/4) - f_noise3d(x, y, z))}
			max_gradient 4
			contained_by {box {-1,1}}
			texture
			{
				pigment {color rgb <073,116,060,>/255}
				finish {GSprites_Default_Finish}
			}
			scale Size
			rotate <rand(Tiles_Seed),rand(Tiles_Seed),rand(Tiles_Seed),> * 360
			translate y * (Size + 8)
		}
		scale Tiles_Height/32
	}
#end
#macro GSprites_OakField_Scenery_Object(Tiles_Width,Tiles_Height,Trees_Number,Tiles_Seed,Tiles_Mode)
	GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,GSprites_Oak_Scenery_Object(Tiles_Height),Trees_Number,Tiles_Seed,Tiles_Mode,1,1/3)
#end

// Redwood trees - requires "veg.inc" by Joerg Schrammel and Stig Bachmann Nielsen
#macro GSprites_Redwood_Scenery_Object(Tiles_Height)
	#include "VEG.INC"
	intersection
	{
		object {Grantrae scale Tiles_Height/8}
		plane {-y,0}
	}
#end
#macro GSprites_RedwoodField_Scenery_Object(Tiles_Width,Tiles_Height,Trees_Number,Tiles_Seed,Tiles_Mode)
	GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,GSprites_Redwood_Scenery_Object(Tiles_Height),Trees_Number,Tiles_Seed,Tiles_Mode,1,1/3)
#end

// Ferns - requires "veg.inc" by Joerg Schrammel and Stig Bachmann Nielsen
#macro GSprites_Fern_Scenery_Object(Tiles_Height)
	#include "VEG.INC"
	intersection
	{
		object {Fern scale Tiles_Height}
		plane {-y,0}
	}
#end
#macro GSprites_FernField_Scenery_Object(Tiles_Width,Tiles_Height,Trees_Number,Tiles_Seed,Tiles_Mode)
	GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,GSprites_Fern_Scenery_Object(Tiles_Height),Trees_Number,Tiles_Seed,Tiles_Mode,1,1/3)
#end

// Road_Barriers
#macro GSprites_Barrier_Scenery_Object(Tiles_Height)
	intersection
	{
		union
		{
			#local TempAngle = pi/2 - atan(1/cos(pi/4));
			#local Barrier_Thk = 0.1;
			#local Barrier_Box = box {<-Barrier_Thk,-1.0,-Barrier_Thk,>,<+Barrier_Thk,+1.0,+Barrier_Thk,>}
			object {Barrier_Box}
			object {Barrier_Box rotate x * 90}
			object {Barrier_Box rotate z * 90}
			texture {GSprites_Plain_Gray}
			rotate x * 45
			rotate z * degrees(TempAngle)
			translate y * sin(TempAngle)
			scale Tiles_Height
		}
		plane {-y,0}
	}
#end
#macro GSprites_BarrierField_Scenery_Object(Tiles_Width,Tiles_Height,Trees_Number,Tiles_Seed,Tiles_Mode)
	GSprites_Scatter_Scenery_Prototype(Tiles_Width,Tiles_Height,GSprites_Barrier_Scenery_Object(Tiles_Height),Trees_Number,Tiles_Seed,Tiles_Mode,0,0)
#end
