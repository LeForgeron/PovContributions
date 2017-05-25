// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

#include "GSprites_Hills_Textures.inc"


// -------------------------------------------------------------
// Macros for the various hill prototypes

// pedestal
#macro GSprites_Pedestal_Hill_Prototype(Tile_Width,Tile_Height)
	#local Wid = Tile_Width/2 * GSprites_Tiles_Factor;
	#local Hgh = Tile_Height;
	box {<+Wid,000,+Wid,>,<-Wid,Hgh,-Wid,>}
#end

// Bicubic patch
#macro GSprites_Patch_Hill_Prototype(North,West,South,East,Tiles_Width,Tiles_Height,Tiles_MaxHeight,Tiles_Seed)
	#local MaxSteps = GSprites_MaxSteps;
	#local Step = GSprites_Step;
	#local Sum = North + West + South + East;
	#local Bin = 16-1*North-2*East-4*South-8*West;
	#local R1 = 1234 * rand(Tiles_Seed)*Step*Bin;
	#local R2 = 4321 * rand(Tiles_Seed)*Step;
	#local R3 = 2143 * rand(Tiles_Seed)*Step;
	#local S1 = seed(R1);
	#local Wid = Tiles_Width/2 * GSprites_Tiles_Factor;
	#local Off = Tiles_Width/16 * Sum;
	#local Hgh = Tiles_Height/8;
	#local Alt = 16 + Hgh * Sum;
	#local Pos = <rand(S1)*RandSign(S1)*Off,0,rand(S1)*RandSign(S1)*Off,>;
	#local W = Tiles_Height;				//(V+Height/Step)/2 or Height*(Step+12)/16
	#local V = (Step/MaxSteps)*(Tiles_MaxHeight-Tiles_Height);
	#local X = (rand(S1)*1/3+2/3)*(V+Alt);
	#declare Peak = <0,X,0,> + Pos;
	union
	{
		#local Y = X*(MaxSteps-Step)/MaxSteps;
		#local Z = (rand(S1)*Tiles_MaxHeight)*(Step/MaxSteps);
		#local A = 0;#local B = 0;#local C = 0;#local D = 0;
		#local E = 0;#local F = Z;#local G = Y;#local H = Y;
		#local I = 0;#local J = Y;#local K = X;#local L = X;
		#local M = 0;#local N = Y;#local O = X;#local P = X;
		#if (North = 1)
			#local S2 = seed(R2);
			#local U = (rand(S2)*3/4+1/4)*W;
			#local C = U;#local D = U;
			#local G = U;#local H = U;
//			#local B = U;			// rand(S1)*U
		#end
		#if (West = 1)
			#local S3 = seed(R3);
			#local U = (rand(S3)*3/4+1/4)*W;
			#local I = U;#local J = U;
			#local M = U;#local N = U;
//			#local E = U;			// rand(S1)*U
		#end
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0+Wid*3/3,A,0-Wid*3/3,>+000, <0+Wid*2/3,B,0-Wid*3/3,>+000, <0+Wid*1/3,C,0-Wid*3/3,>+000, <0+Wid*0/3,D,0-Wid*3/3,>+000
			<0+Wid*3/3,E,0-Wid*2/3,>+000, <0+Wid*2/3,F,0-Wid*2/3,>+Pos, <0+Wid*1/3,G,0-Wid*2/3,>+Pos, <0+Wid*0/3,H,0-Wid*2/3,>+Pos
			<0+Wid*3/3,I,0-Wid*1/3,>+000, <0+Wid*2/3,J,0-Wid*1/3,>+Pos, <0+Wid*1/3,K,0-Wid*1/3,>+Pos, <0+Wid*0/3,L,0-Wid*1/3,>+Pos
			<0+Wid*3/3,M,0-Wid*0/3,>+000, <0+Wid*2/3,N,0-Wid*0/3,>+Pos, <0+Wid*1/3,O,0-Wid*0/3,>+Pos, <0+Wid*0/3,P,0-Wid*0/3,>+Pos
		}
		#local Y = X*(MaxSteps-Step)/MaxSteps;
		#local Z = (rand(S1)*Tiles_MaxHeight)*(Step/MaxSteps);
		#local A = 0;#local B = 0;#local C = 0;#local D = 0;
		#local E = 0;#local F = Z;#local G = Y;#local H = Y;
		#local I = 0;#local J = Y;#local K = X;#local L = X;
		#local M = 0;#local N = Y;#local O = X;#local P = X;
		#if (North = 1)
			#local S2 = seed(R2);
			#local U = (rand(S2)*3/4+1/4)*W;
			#local C = U;#local D = U;
			#local G = U;#local H = U;
//			#local B = U;			// rand(S1)*U
		#end
		#if (East = 1)
			#local S3 = seed(R3);
			#local U = (rand(S3)*3/4+1/4)*W;
			#local I = U;#local J = U;
			#local M = U;#local N = U;
//			#local E = U;			// rand(S1)*U
		#end
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0-Wid*0/3,D,0-Wid*3/3,>+000, <0-Wid*1/3,C,0-Wid*3/3,>+000, <0-Wid*2/3,B,0-Wid*3/3,>+000, <0-Wid*3/3,A,0-Wid*3/3,>+000
			<0-Wid*0/3,H,0-Wid*2/3,>+Pos, <0-Wid*1/3,G,0-Wid*2/3,>+Pos, <0-Wid*2/3,F,0-Wid*2/3,>+Pos, <0-Wid*3/3,E,0-Wid*2/3,>+000
			<0-Wid*0/3,L,0-Wid*1/3,>+Pos, <0-Wid*1/3,K,0-Wid*1/3,>+Pos, <0-Wid*2/3,J,0-Wid*1/3,>+Pos, <0-Wid*3/3,I,0-Wid*1/3,>+000
			<0+Wid*0/3,P,0-Wid*0/3,>+Pos, <0-Wid*1/3,O,0-Wid*0/3,>+Pos, <0-Wid*2/3,N,0-Wid*0/3,>+Pos, <0-Wid*3/3,M,0-Wid*0/3,>+000
		}
		#local Y = X*(MaxSteps-Step)/MaxSteps;
		#local Z = (rand(S1)*Tiles_MaxHeight)*(Step/MaxSteps);
		#local A = 0;#local B = 0;#local C = 0;#local D = 0;
		#local E = 0;#local F = Z;#local G = Y;#local H = Y;
		#local I = 0;#local J = Y;#local K = X;#local L = X;
		#local M = 0;#local N = Y;#local O = X;#local P = X;
		#if (South = 1)
			#local S2 = seed(R2);
			#local U = (rand(S2)*3/4+1/4)*W;
			#local C = U;#local D = U;
			#local G = U;#local H = U;
//			#local B = U;			// rand(S1)*U
		#end
		#if (West = 1)
			#local S3 = seed(R3);
			#local U = (rand(S3)*3/4+1/4)*W;
			#local I = U;#local J = U;
			#local M = U;#local N = U;
//			#local E = U;			// rand(S1)*U
		#end
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0+Wid*3/3,M,0+Wid*0/3,>+000, <0+Wid*2/3,N,0+Wid*0/3,>+Pos, <0+Wid*1/3,O,0+Wid*0/3,>+Pos, <0+Wid*0/3,P,0-Wid*0/3,>+Pos
			<0+Wid*3/3,I,0+Wid*1/3,>+000, <0+Wid*2/3,J,0+Wid*1/3,>+Pos, <0+Wid*1/3,K,0+Wid*1/3,>+Pos, <0+Wid*0/3,L,0+Wid*1/3,>+Pos
			<0+Wid*3/3,E,0+Wid*2/3,>+000, <0+Wid*2/3,F,0+Wid*2/3,>+Pos, <0+Wid*1/3,G,0+Wid*2/3,>+Pos, <0+Wid*0/3,H,0+Wid*2/3,>+Pos
			<0+Wid*3/3,A,0+Wid*3/3,>+000, <0+Wid*2/3,B,0+Wid*3/3,>+000, <0+Wid*1/3,C,0+Wid*3/3,>+000, <0+Wid*0/3,D,0+Wid*3/3,>+000
		}
		#local Y = X*(MaxSteps-Step)/MaxSteps;
		#local Z = (rand(S1)*Tiles_MaxHeight)*(Step/MaxSteps);
		#local A = 0;#local B = 0;#local C = 0;#local D = 0;
		#local E = 0;#local F = Z;#local G = Y;#local H = Y;
		#local I = 0;#local J = Y;#local K = X;#local L = X;
		#local M = 0;#local N = Y;#local O = X;#local P = X;
		#if (South = 1)
			#local S2 = seed(R2);
			#local U = (rand(S2)*3/4+1/4)*W;
			#local C = U;#local D = U;
			#local G = U;#local H = U;
//			#local B = U;			// rand(S1)*U
		#end
		#if (East = 1)
			#local S3 = seed(R3);
			#local U = (rand(S3)*3/4+1/4)*W;
			#local I = U;#local J = U;
			#local M = U;#local N = U;
//			#local E = U;			// rand(S1)*U
		#end
		bicubic_patch
		{
			type 0 flatness 0
			u_steps 4 v_steps 4
			<0+Wid*0/3,P,0-Wid*0/3,>+Pos, <0-Wid*1/3,O,0+Wid*0/3,>+Pos, <0-Wid*2/3,N,0+Wid*0/3,>+Pos, <0-Wid*3/3,M,0+Wid*0/3,>+000
			<0-Wid*0/3,L,0+Wid*1/3,>+Pos, <0-Wid*1/3,K,0+Wid*1/3,>+Pos, <0-Wid*2/3,J,0+Wid*1/3,>+Pos, <0-Wid*3/3,I,0+Wid*1/3,>+000
			<0-Wid*0/3,H,0+Wid*2/3,>+Pos, <0-Wid*1/3,G,0+Wid*2/3,>+Pos, <0-Wid*2/3,F,0+Wid*2/3,>+Pos, <0-Wid*3/3,E,0+Wid*2/3,>+000
			<0-Wid*0/3,D,0+Wid*3/3,>+000, <0-Wid*1/3,C,0+Wid*3/3,>+000, <0-Wid*2/3,B,0+Wid*3/3,>+000, <0-Wid*3/3,A,0+Wid*3/3,>+000
		}
	}
#end

// this one has the same shape as the original hills
#macro GSprites_Prism_Hill_Prototype_A(North, West, South, East, Tiles_Width, Tiles_Height)
	union
	{
		#local Wid = Tiles_Width/2 * GSprites_Tiles_Factor;#local Hlf = Tiles_Width/4;#local Hgh = Tiles_Height;
		#local NW1 = <+Wid,000,-Wid,>;#local NE1 = <-Wid,000,-Wid,>;#local SW1 = <+Wid,000,+Wid,>;#local SE1 = <-Wid,000,+Wid,>;
		#local NW2 = <+Hlf,Hgh,-Hlf,>;#local NE2 = <-Hlf,Hgh,-Hlf,>;#local SW2 = <+Hlf,Hgh,+Hlf,>;#local SE2 = <-Hlf,Hgh,+Hlf,>;
		#local NNW = <+Hlf,Hgh,-Wid,>;#local NNE = <-Hlf,Hgh,-Wid,>;#local NEE = <-Wid,Hgh,-Hlf,>;#local SEE = <-Wid,Hgh,+Hlf,>;
		#local SSE = <-Hlf,Hgh,+Wid,>;#local SSW = <+Hlf,Hgh,+Wid,>;#local SWW = <+Wid,Hgh,+Hlf,>;#local NWW = <+Wid,Hgh,-Hlf,>;

		// North		
		#if (North = 1)
			polygon {4, NW1, NNW, NNE, NE1}
			polygon {4, NW2, NNW, NNE, NE2}
			triangle {NW1,NNW,NW2}
			triangle {NE2,NNE,NE1}
		#else
			polygon {4, NW1, NW2, NE2, NE1}
		#end

		// West
		#if (West = 1)
			polygon {4, SW1, SWW, NWW, NW1}
			polygon {4, SW2, SWW, NWW, NW2}
			triangle {NWW,NW1,NW2}
			triangle {SWW,SW1,SW2}
		#else
			polygon {4, SW1, SW2, NW2, NW1}
		#end

		// South
		#if (South = 1)
			polygon {4, SE1, SSE, SSW, SW1}
			polygon {4, SE2, SSE, SSW, SW2}
			triangle {SW1,SSW,SW2}
			triangle {SE2,SSE,SE1}
		#else
			polygon {4, SE1, SE2, SW2, SW1}
		#end

		// East
		#if (East = 1)
			polygon {4, NE1, NEE, SEE, SE1}
			polygon {4, NE2, NEE, SEE, SE2}
			triangle {NE1,NEE,NE2}
			triangle {SE2,SEE,SE1}
		#else
			polygon {4, NE1, NE2, SE2, SE1}
		#end

		// Top middle
		polygon {4, NW2, NE2, SE2, SW2}
		// Bottom middle
		polygon {4, NW1, NE1, SE1, SW1}
	}
#end


// this one has the same shape as the original hills, but is smoothed. some texture issues I'll have to figure out.
#macro GSprites_Prism_Hill_Prototype_B(North, West, South, East, Tiles_Width, Tiles_Height)
	mesh
	{
		#local Wid = Tiles_Width/2 * GSprites_Tiles_Factor;#local Hlf = Tiles_Width/4;#local Hgh = Tiles_Height;
		#local NW1 = <+Wid,000,-Wid,>;#local NE1 = <-Wid,000,-Wid,>;#local SW1 = <+Wid,000,+Wid,>;#local SE1 = <-Wid,000,+Wid,>;
		#local NW2 = <+Hlf,Hgh,-Hlf,>;#local NE2 = <-Hlf,Hgh,-Hlf,>;#local SW2 = <+Hlf,Hgh,+Hlf,>;#local SE2 = <-Hlf,Hgh,+Hlf,>;
		#local NNW = <+Hlf,Hgh,-Wid,>;#local NNE = <-Hlf,Hgh,-Wid,>;#local NEE = <-Wid,Hgh,-Hlf,>;#local SEE = <-Wid,Hgh,+Hlf,>;
		#local SSE = <-Hlf,Hgh,+Wid,>;#local SSW = <+Hlf,Hgh,+Wid,>;#local SWW = <+Wid,Hgh,+Hlf,>;#local NWW = <+Wid,Hgh,-Hlf,>;

		// North		
		#if (North = 1)
			smooth_triangle {NW1,NW1,NNW,NNW,NE1,NE1}
			smooth_triangle {NNW,NNW,NNE,NNE,NE1,NE1}
			smooth_triangle {NW1,NW1,NNW,NNW,NW2,NW2}
			smooth_triangle {NE2,NE2,NNE,NNE,NE1,NE1}
			smooth_triangle {NW2,NW2,NNW,NNW,NE2,NE2}
			smooth_triangle {NNW,NNW,NNE,NNE,NE2,NE2}
		#else
			smooth_triangle {NW1,NW1,NW2,NW2,NE1,NE1}
			smooth_triangle {NW2,NW2,NE2,NE2,NE1,NE1}
		#end

		// West
		#if (West = 1)
			smooth_triangle {SW1,SW1,SWW,SWW,NW1,NW1}
			smooth_triangle {NWW,NWW,SWW,SWW,NW1,NW1}
			smooth_triangle {NWW,NWW,NW1,NW1,NW2,NW2}
			smooth_triangle {SWW,SWW,SW1,SW1,SW2,SW2}
			smooth_triangle {NWW,NWW,SWW,SWW,NW2,NW2}
			smooth_triangle {SWW,SWW,NW2,NW2,SW2,SW2}
		#else
			smooth_triangle {SW1,SW1,SW2,SW2,NW1,NW1}
			smooth_triangle {NW2,NW2,SW2,SW2,NW1,NW1}
		#end

		// South
		#if (South = 1)
			smooth_triangle {SW1,SW1,SSW,SSW,SE1,SE1}
			smooth_triangle {SSW,SSW,SSE,SSE,SE1,SE1}
			smooth_triangle {SW1,SW1,SSW,SSW,SW2,SW2}
			smooth_triangle {SE2,SE2,SSE,SSE,SE1,SE1}
			smooth_triangle {SW2,SW2,SSW,SSW,SE2,SE2}
			smooth_triangle {SSW,SSW,SSE,SSE,SE2,SE2}
		#else
			smooth_triangle {SW1,SW1,SW2,SW2,SE1,SE1}
			smooth_triangle {SW2,SW2,SE2,SE2,SE1,SE1}
		#end

		// East
		#if (East = 1)
			smooth_triangle {NE1,NE1,NEE,NEE,SE1,SE1}
			smooth_triangle {NEE,NEE,SEE,SEE,SE1,SE1}
			smooth_triangle {NE1,NE1,NEE,NEE,NE2,NE2}
			smooth_triangle {SE2,SE2,SEE,SEE,SE1,SE1}
			smooth_triangle {NE2,NE2,NEE,NEE,SE2,SE2}
			smooth_triangle {NEE,NEE,SEE,SEE,SE2,SE2}
		#else
			smooth_triangle {NE1,NE1,NE2,NE2,SE1,SE1}
			smooth_triangle {NE2,NE2,SE2,SE2,SE1,SE1}
		#end

		// Top middle
		smooth_triangle {NW2,NW2,NE2,NE2,SE2,SE2}
		smooth_triangle {NW2,NW2,SE2,SE2,SW2,SW2}
	}
#end


// -------------------------------------------------------------
// Definitions for the various pre-defined floor types

#macro GSprites_Hill_Object_A(North,West,South,East,Tiles_Width,Tiles_Height)
	union
	{
		object {GSprites_Prism_Hill_Prototype_A(North,West,South,East,Tiles_Width,Tiles_Height) translate y * Tiles_Height * (GSprites_Step - 1)}
		#if (GSprites_Step > 1)
			object {GSprites_Pedestal_Hill_Prototype(Tiles_Width,Tiles_Height) scale y * (GSprites_Step - 1)}
		#end
		texture {GSprites_Hills_Texture_K}
	}
#end

#macro GSprites_Hill_Object_B(North,West,South,East,Tiles_Width,Tiles_Height)
	union
	{
		object {GSprites_Prism_Hill_Prototype_B(North,West,South,East,Tiles_Width,Tiles_Height) translate y * Tiles_Height * (GSprites_Step - 1)}
		#if (GSprites_Step > 1)
			object {GSprites_Pedestal_Hill_Prototype(Tiles_Width,Tiles_Height) scale y * (GSprites_Step - 1)}
		#end
		texture {GSprites_Hills_Texture_J}
	}
#end

#macro GSprites_Hill_Object_C(North,West,South,East,Tiles_Width,Tiles_Height,Tiles_MaxHeight,Tiles_Seed)
	union
	{
		object {GSprites_Patch_Hill_Prototype(North,West,South,East,Tiles_Width,Tiles_Height,Tiles_MaxHeight,Tiles_Seed) translate y * Tiles_Height * (GSprites_Step - 1)}
		#if (GSprites_Step > 1)
			object {GSprites_Pedestal_Hill_Prototype(Tiles_Width,Tiles_Height) scale y * (GSprites_Step - 1)}
		#end
		GSprites_Hills_Texture_H(32,32)	// careful, this one's a macro
	}
#end
