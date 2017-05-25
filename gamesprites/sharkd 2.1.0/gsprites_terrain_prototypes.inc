// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "GSprites_Terrain_textures.inc"


// -------------------------------------------------------------
// Macros for the various terrain prototypes

#macro GSprites_Bumpy_Terrain_Prototype(Tiles_Width,Tiles_Height,S1)
	union
	{
		#local Hgh = Tiles_Height;
		#local Wid = Tiles_Width/2;
		#local Off = Tiles_Width/3;
//		#local PosX = rand(S1)*RandSign(S1)*Off;
//		#local PosZ = rand(S1)*RandSign(S1)*Off;
		#local PosX = 0;
		#local PosZ = 0;
		#local X_1 = rand(S1)*Hgh/2+Hgh/2;
		#local X_2 = rand(S1)*Hgh/2+Hgh/2;
		#local X_3 = rand(S1)*Hgh/2+Hgh/2;
		#local X_4 = rand(S1)*Hgh/2+Hgh/2;
//		#local A = X_1;	#local B = X_1;	#local C = X_2;	#local D = X_2;
//		#local E = X_1;	#local F = X_1;	#local G = X_2;	#local H = X_2;
//		#local I = X_4;	#local J = X_4;	#local K = X_3;	#local L = X_3;
//		#local M = X_4;	#local N = X_4;	#local O = X_3;	#local P = X_3;
		#local A = 0;	#local B = 0;	#local C = 0;	#local D = 0;
		#local E = 0;	#local F = X_1;	#local G = X_2;	#local H = X_2;
		#local I = 0;	#local J = X_4;	#local K = X_3;	#local L = X_3;
		#local M = 0;	#local N = X_4;	#local O = X_3;	#local P = X_3;
		// North-West
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0+Wid*3/3,A,0-Wid*3/3,>,	<0+Wid*2/3,B,0-Wid*3/3,>,				<0+Wid*1/3,C,0-Wid*3/3,>,				<0+Wid*0/3,D,0-Wid*3/3,>
			<0+Wid*3/3,E,0-Wid*2/3,>,	<0+Wid*2/3,F,0-Wid*2/3,>+<PosX*1/3,0,PosZ*1/3,>,	<0+Wid*1/3,G,0-Wid*2/3,>+<PosX*2/3,0,PosZ*1/3,>,	<0+Wid*0/3,H,0-Wid*2/3,>+<PosX*3/3,0,PosZ*1/3,>
			<0+Wid*3/3,I,0-Wid*1/3,>,	<0+Wid*2/3,J,0-Wid*1/3,>+<PosX*1/3,0,PosZ*2/3,>,	<0+Wid*1/3,K,0-Wid*1/3,>+<PosX*2/3,0,PosZ*2/3,>,	<0+Wid*0/3,L,0-Wid*1/3,>+<PosX*3/3,0,PosZ*2/3,>
			<0+Wid*3/3,M,0-Wid*0/3,>,	<0+Wid*2/3,N,0-Wid*0/3,>+<PosX*1/3,0,PosZ*3/3,>,	<0+Wid*1/3,O,0-Wid*0/3,>+<PosX*2/3,0,PosZ*3/3,>,	<0+Wid*0/3,P,0-Wid*0/3,>+<PosX*3/3,0,PosZ*3/3,>
//			uv_mapping
		}
		// North-East
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0-Wid*0/3,D,0-Wid*3/3,>,				<0-Wid*1/3,C,0-Wid*3/3,>,				<0-Wid*2/3,B,0-Wid*3/3,>,				<0-Wid*3/3,A,0-Wid*3/3,>
			<0-Wid*0/3,H,0-Wid*2/3,>+<PosX*3/3,0,PosZ*1/3,>,	<0-Wid*1/3,G,0-Wid*2/3,>+<PosX*2/3,0,PosZ*1/3,>,	<0-Wid*2/3,F,0-Wid*2/3,>+<PosX*1/3,0,PosZ*1/3,>,	<0-Wid*3/3,E,0-Wid*2/3,>
			<0-Wid*0/3,L,0-Wid*1/3,>+<PosX*3/3,0,PosZ*2/3,>,	<0-Wid*1/3,K,0-Wid*1/3,>+<PosX*2/3,0,PosZ*2/3,>,	<0-Wid*2/3,J,0-Wid*1/3,>+<PosX*1/3,0,PosZ*2/3,>,	<0-Wid*3/3,I,0-Wid*1/3,>
			<0+Wid*0/3,P,0-Wid*0/3,>+<PosX*3/3,0,PosZ*3/3,>,	<0-Wid*1/3,O,0-Wid*0/3,>+<PosX*2/3,0,PosZ*3/3,>,	<0-Wid*2/3,N,0-Wid*0/3,>+<PosX*1/3,0,PosZ*3/3,>,	<0-Wid*3/3,M,0-Wid*0/3,>
//			uv_mapping
		}
		// South-East
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0+Wid*0/3,P,0-Wid*0/3,>+<PosX*3/3,0,PosZ*3/3,>,	<0-Wid*1/3,O,0+Wid*0/3,>+<PosX*2/3,0,PosZ*3/3,>,	<0-Wid*2/3,N,0+Wid*0/3,>+<PosX*1/3,0,PosZ*3/3,>,	<0-Wid*3/3,M,0+Wid*0/3,>
			<0-Wid*0/3,L,0+Wid*1/3,>+<PosX*3/3,0,PosZ*2/3,>,	<0-Wid*1/3,K,0+Wid*1/3,>+<PosX*2/3,0,PosZ*2/3,>,	<0-Wid*2/3,J,0+Wid*1/3,>+<PosX*1/3,0,PosZ*2/3,>,	<0-Wid*3/3,I,0+Wid*1/3,>
			<0-Wid*0/3,H,0+Wid*2/3,>+<PosX*3/3,0,PosZ*1/3,>,	<0-Wid*1/3,G,0+Wid*2/3,>+<PosX*2/3,0,PosZ*1/3,>,	<0-Wid*2/3,F,0+Wid*2/3,>+<PosX*1/3,0,PosZ*1/3,>,	<0-Wid*3/3,E,0+Wid*2/3,>
			<0-Wid*0/3,D,0+Wid*3/3,>,				<0-Wid*1/3,C,0+Wid*3/3,>,				<0-Wid*2/3,B,0+Wid*3/3,>,				<0-Wid*3/3,A,0+Wid*3/3,>
//			uv_mapping
		}
		// South-West
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0+Wid*3/3,M,0+Wid*0/3,>,	<0+Wid*2/3,N,0+Wid*0/3,>+<PosX*1/3,0,PosZ*3/3,>,	<0+Wid*1/3,O,0+Wid*0/3,>+<PosX*2/3,0,PosZ*3/3,>,	<0+Wid*0/3,P,0-Wid*0/3,>+<PosX*3/3,0,PosZ*3/3,>
			<0+Wid*3/3,I,0+Wid*1/3,>,	<0+Wid*2/3,J,0+Wid*1/3,>+<PosX*1/3,0,PosZ*2/3,>,	<0+Wid*1/3,K,0+Wid*1/3,>+<PosX*2/3,0,PosZ*2/3,>,	<0+Wid*0/3,L,0+Wid*1/3,>+<PosX*3/3,0,PosZ*2/3,>
			<0+Wid*3/3,E,0+Wid*2/3,>,	<0+Wid*2/3,F,0+Wid*2/3,>+<PosX*1/3,0,PosZ*1/3,>,	<0+Wid*1/3,G,0+Wid*2/3,>+<PosX*2/3,0,PosZ*1/3,>,	<0+Wid*0/3,H,0+Wid*2/3,>+<PosX*3/3,0,PosZ*1/3,>
			<0+Wid*3/3,A,0+Wid*3/3,>,	<0+Wid*2/3,B,0+Wid*3/3,>,				<0+Wid*1/3,C,0+Wid*3/3,>,				<0+Wid*0/3,D,0+Wid*3/3,>
//			uv_mapping
		}
	}
#end

#macro GSprites_Water_Terrain_Prototype_A(Tiles_Width,Noise_Amount)
	isosurface
	{
		function {y - f_noise3d(x * Noise_Amount, 0, z * Noise_Amount)}
	 	contained_by {box {-Tiles_Width/2, Tiles_Width/2}}
		open
	}
#end

#macro GSprites_Water_Terrain_Prototype_B(Tiles_Width,Tiles_Height,Wave_Frequency)
	parametric
	{
		function {u * Tiles_Width - Tiles_Width/2}
		function {Tiles_Height * (sin(u*2*pi*Wave_Frequency) + sin(v*2*pi*Wave_Frequency))}
		function {v * Tiles_Width - Tiles_Width/2}
		<0,0>, <1,1>
		accuracy 0.01
		precompute 10 x,y,z
		contained_by {box {-Tiles_Width/2, Tiles_Width/2}}
	}
#end

#macro GSprites_Road_Terrain_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,Road_Width,Stripe_Length,Stripe_Gap,Stripe_Width,Curb_Width,Fill_Corners)
	#local Wid1 = Tiles_Width/2;
	#local Wid2 = Road_Width/2;
	#local Hgh = Tiles_Height;
	#local N1 = <0,0,-Wid1,>;#local E1 = <-Wid1,0,0,>;#local S1 = <0,0,+Wid1,>;#local W1 = <+Wid1,0,0,>;
	#local N2 = <0,0,-Wid2,>;#local E2 = <-Wid2,0,0,>;#local S2 = <0,0,+Wid2,>;#local W2 = <+Wid2,0,0,>;
	#local Up = <0,+Hgh,0,>;
	#local NW1 = N1 + W1;#local NE1 = N1 + E1;#local SE1 = S1 + E1;#local SW1 = S1 + W1;
	#local NW2 = N2 + W2;#local NE2 = N2 + E2;#local SE2 = S2 + E2;#local SW2 = S2 + W2;
	#local NNW = N1 + W2;#local NNE = N1 + E2;#local NEE = N2 + E1;#local SEE = S2 + E1;
	#local SSE = S1 + E2;#local SSW = S1 + W2;#local SWW = S2 + W1;#local NWW = N2 + W1;
	#local Pattern_1 = texture
	{
		#local Len = Stripe_Length + Stripe_Gap;
		gradient z
		texture_map
		{
			[0 Divider_Texture]
			[Stripe_Length/Len Divider_Texture]
			[Stripe_Length/Len Road_Texture]
			[1 Road_Texture]
		}
		scale z * Len
	}
	
	#local Pattern_2 = texture
	{
		#local Wid = Road_Width;
		gradient x
		texture_map
		{
			[0 Curb_Texture]
			[Curb_Width/Wid Curb_Texture]
			[Curb_Width/Wid Stripe_Texture]
			[(Curb_Width+Stripe_Width)/Wid Stripe_Texture]
			[(Curb_Width+Stripe_Width)/Wid Road_Texture]
			[(1-Stripe_Width/Wid)/2 Road_Texture]
			[(1-Stripe_Width/Wid)/2 Pattern_1]
			[(1+Stripe_Width/Wid)/2 Pattern_1]
			[(1+Stripe_Width/Wid)/2 Road_Texture]
			[1-(Curb_Width+Stripe_Width)/Wid Road_Texture]
			[1-(Curb_Width+Stripe_Width)/Wid Stripe_Texture]
			[1-Curb_Width/Wid Stripe_Texture]
			[1-Curb_Width/Wid Curb_Texture]
			[1 Curb_Texture]
		}
		translate x * -1/2
		scale x * Wid
	}
	
	#local Pattern_3 = texture {Pattern_2 rotate y * 90}
	
	#local Pattern_4 = texture
	{
		radial
		texture_map
		{
			[0/8 Pattern_3]
			[1/8 Pattern_3]
			[1/8 Pattern_2]
			[3/8 Pattern_2]
			[3/8 Pattern_3]
			[5/8 Pattern_3]
			[5/8 Pattern_2]
			[7/8 Pattern_2]
			[7/8 Pattern_3]
			[8/8 Pattern_3]
		}
	}
	union
	{
		#if (North = 1)
			#if (Road_Width != Tiles_Width)
				polygon {4, NW2, NNW, NNE, NE2 texture {Pattern_2}}
			#end
			polygon {3, NW2, NE2, 0 texture {Pattern_2}}
		#else
			#if ((Road_Width != Tiles_Width) & (Fill_Corners = 1))
				polygon {4, NW2, NNW, NNE, NE2 texture {Side_Texture}}
			#end
			polygon {3, NW2, NE2, 0 texture {Pattern_3}}
		#end
		#if (East = 1)
			#if (Road_Width != Tiles_Width)
				polygon {4, NE2, NEE, SEE, SE2 texture {Pattern_3}}
			#end
			polygon {3, NE2, SE2, 0 texture {Pattern_3}}
		#else
			#if ((Road_Width != Tiles_Width) & (Fill_Corners = 1))
				polygon {4, NE2, NEE, SEE, SE2 texture {Side_Texture}}
			#end
			polygon {3, NE2, SE2, 0 texture {Pattern_2}}
		#end
		#if (South = 1)
			#if (Road_Width != Tiles_Width)
				polygon {4, SE2, SSE, SSW, SW2 texture {Pattern_2}}
			#end
			polygon {3, SE2, SW2, 0 texture {Pattern_2}}
		#else
			#if ((Road_Width != Tiles_Width) & (Fill_Corners = 1))
				polygon {4, SE2, SSE, SSW, SW2 texture {Side_Texture}}
			#end
			polygon {3, SE2, SW2, 0 texture {Pattern_3}}
		#end
		#if (West = 1)
			#if (Road_Width != Tiles_Width)
				polygon {4, SW2, SWW, NWW, NW2 texture {Pattern_3}}
			#end
			polygon {3, SW2, NW2, 0 texture {Pattern_3}}
		#else
			#if ((Road_Width != Tiles_Width) & (Fill_Corners = 1))
				polygon {4, SW2, SWW, NWW, NW2 texture {Side_Texture}}
			#end
			polygon {3, SW2, NW2, 0 texture {Pattern_2}}
		#end
		#if ((Road_Width != Tiles_Width) & (Fill_Corners = 1))
			polygon {4, NWW, NW1, NNW, NW2 texture {Side_Texture}}
			polygon {4, NNE, NE1, NEE, NE2 texture {Side_Texture}}
			polygon {4, SEE, SE1, SSE, SE2 texture {Side_Texture}}
			polygon {4, SSW, SW1, SWW, SW2 texture {Side_Texture}}
		#end
	}
#end


// -------------------------------------------------------------
// Definitions for the various pre-defined terrain types

#declare GSprites_Desert_Terrain_Object_A = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Desert_Texture_A scale GSprites_Height/8}}
#declare GSprites_Desert_Terrain_Object_B = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Desert_Texture_B scale GSprites_Width/2}}
#declare GSprites_Desert_Terrain_Object_C = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Desert_Texture_C}}
#declare GSprites_Water_Terrain_Object_A = object {GSprites_Water_Terrain_Prototype_A(GSprites_Width,1/4)				texture {GSprites_Water_Texture_A}}
#declare GSprites_Water_Terrain_Object_B = object {GSprites_Water_Terrain_Prototype_B(GSprites_Width,GSprites_Height/256,4)		texture {GSprites_Water_Texture_A}}
#declare GSprites_Dirt_Terrain_Object_A = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Dirt_Texture_A scale GSprites_Width/2}}
#declare GSprites_Dirt_Terrain_Object_B = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Dirt_Texture_B scale GSprites_Height/8}}
#declare GSprites_Grass_Terrain_Object_A = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Grass_Texture_A}}
#declare GSprites_Grass_Terrain_Object_B = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Grass_Texture_B}}
#declare GSprites_Marsh_Terrain_Object_A = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Marsh_Texture_A scale GSprites_Width/2}}
#declare GSprites_Marsh_Terrain_Object_B = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Marsh_Texture_B scale GSprites_Width/2}}
#declare GSprites_Gravel_Terrain_Object_A = object {GSprites_Bumpy_Terrain_Prototype(GSprites_Width,GSprites_Height/8,GSprites_Seed)	texture {GSprites_Gravel_Texture_A scale GSprites_Width/2}}
#declare GSprites_Road_Terrain_Object_A = object
{
	#local Road_Texture = GSprites_Road_Surface_Texture_A;
	#local Curb_Texture = GSprites_Road_Surface_Texture_A;
	#local Stripe_Texture = GSprites_Road_Stripe_Texture_A;
	#local Divider_Texture = GSprites_Road_Stripe_Texture_A;
	#local Side_Texture = GSprites_Road_Surface_Texture_A;
	GSprites_Road_Terrain_Prototype(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,0,GSprites_Width/4,GSprites_Width/32,GSprites_Width/32,GSprites_Width/64*9/8,GSprites_Width/64,0)
}
#declare GSprites_Road_Terrain_Object_B = object
{
	#local Road_Texture = GSprites_Road_Surface_Texture_A;
	#local Curb_Texture = GSprites_Road_Surface_Texture_A;
	#local Stripe_Texture = GSprites_Road_Stripe_Texture_A;
	#local Divider_Texture = GSprites_Road_Stripe_Texture_A;
	#local Side_Texture = GSprites_Road_Surface_Texture_A;
	GSprites_Road_Terrain_Prototype(GSprites_North,GSprites_East,GSprites_South,GSprites_West,GSprites_Width,0,GSprites_Width,GSprites_Width/16,GSprites_Width/16,GSprites_Width/64*9/8,GSprites_Width/32,0)
}
