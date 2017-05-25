// Video game sprites collection for POV-Ray
// *****************************************
// Author: Michael Horvath
// Website: http://isometricland.com/povray/povray.php
// This file is licensed under the terms of the CC-LGPL.

#include "GSprites_Walls_textures.inc"                 // Source of the textures


// -------------------------------------------------------------
// Tubular walls

#macro GSprites_Tube_Frame_Prototype(Wid,Hgh,IsRight,RotateY,Side)
	intersection
	{
		plane {+x, Side texture {Mask_Texture}}
		plane {-x, 000 texture {Mask_Texture}}
		plane {+z, HlfWid texture {Mask_Texture}}
		plane {-z, 000 texture {Mask_Texture}}
		plane {+y, Hgh texture {Roof_Texture	translate -z * HlfWid rotate -y * RotateY translate -x * IsRight * HlfWid rotate -y * IsRight * 180}}
		plane {-y, 000 texture {Floor_Texture	translate -z * HlfWid rotate -y * RotateY translate -x * IsRight * HlfWid rotate -y * IsRight * 180}}
		bounded_by {Bound_Box}
	}
#end

#macro GSprites_Tube_Straight_Prototype(Wid,Hgh,IsRight,RotateY,Side,MoveMe)
	#local MoveMe2 = BinarySwitch(IsRight) * (GSprites_Tiles_Factor - 1);
	difference
	{
		object {GSprites_Tube_Frame_Prototype(Wid,Hgh,IsRight,RotateY,Side)}
		cylinder {<-Len*2*GSprites_Tiles_Factor,HlfWid,HlfWid*2,>,<+Len*2*GSprites_Tiles_Factor,HlfWid,HlfWid*2,>,Tube_Radius texture {Wall_Texture translate x * (1 + IsRight + MoveMe + MoveMe2) * HlfWid}}
		bounded_by {Bound_Box}
		rotate		y * IsRight * 180
		translate	x * IsRight * Len
		rotate		y * RotateY
	}
#end

#macro GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,IsRight,RotateY)
	object
	{
		GSprites_Tube_Straight_Prototype(Wid,Hgh,IsRight,RotateY,Len,0)
		scale x * 4
		no_image
	}
#end

#macro GSprites_Tube_Corner_Inner_Prototype(Wid,Hgh,IsRight,RotateY)
	#local HlfWid = Wid/2;
	union
	{
		difference
		{
			object {GSprites_Tube_Frame_Prototype(Wid,Hgh,IsRight,RotateY,HlfWid)}
			#local Angle_Start = acos(HlfWid/Tube_Radius);
			#local Angle_Incrm = 2/8 * Angle_Start;
			sor
			{
				11,
				<
					max(0,cos(Angle_Start - 8 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 8 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 8 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 8 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 7 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 7 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 6 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 6 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 5 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 5 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 4 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 4 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 3 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 3 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 2 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 2 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 1 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 1 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 0 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 0 * Angle_Incrm) * Tube_Radius,
				>
				<
					max(0,cos(Angle_Start - 0 * Angle_Incrm) * Tube_Radius - HlfWid),
					sin(Angle_Start - 0 * Angle_Incrm) * Tube_Radius,
				>
				texture {Inner_Corner_Texture}
				translate HlfWid
			}
			bounded_by {Bound_Box}
			rotate y * RotateY
		}
		#if (GSprites_Tiles_Factor > 1)
			object {GSprites_Tube_Straight_Prototype(Wid,Hgh,IsRight,RotateY,Len-HlfWid,1) translate vaxis_rotate(x * HlfWid,y,RotateY)}
			object {GSprites_Tube_Straight_Prototype(Wid,Hgh,BinarySwitch(IsRight),RotateY,Len-HlfWid,0) rotate y * -90}
		#end
	}
#end

#macro GSprites_Tube_Corner_Outer_Prototype(Wid,Hgh,IsRight,RotateY)
	difference
	{
		object {GSprites_Tube_Frame_Prototype(Wid,Hgh,IsRight,RotateY+180,HlfWid)}
		torus
		{
			Wid, Tube_Radius
			texture {Outer_Corner_Texture}
			translate y * HlfWid
		}
		bounded_by {Bound_Box}
		rotate y * (RotateY+180)
	}
#end

#macro GSprites_Tube_Wall_Prototype(North,East,South,West,Wid,Hgh)
	#local HlfWid	= Wid/2;
	#local Len	= HlfWid * GSprites_Tiles_Factor;
	#local Bound_Box = box {0, <Len,Hgh,Len,>}
	union
	{
		// Straight portions
		#if (West = 1) 
			#if (South = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,0,000,Len,0)}
			#end
			#if (North = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,1,000,Len,0)}
			#end
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,0,000)}
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,1,000)}
		#end
		#if (South = 1)
			#if (East = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,0,270,Len,0)}
			#end
			#if (West = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,1,270,Len,0)}
			#end
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,0,270)}
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,1,270)}
		#end
		#if (East = 1)
			#if (North = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,0,180,Len,0)}
			#end
			#if (South = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,1,180,Len,0)}
			#end
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,0,180)}
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,1,180)}
		#end
		#if (North = 1) 
			#if (West = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,0,090,Len,0)}
			#end
			#if (East = 0)
				object {GSprites_Tube_Straight_Prototype(Wid,Hgh,1,090,Len,0)}
			#end
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,0,090)}
//			object {GSprites_Tube_Straight_Shadow_Prototype(Wid,Hgh,1,090)}
		#end
		// Curved portions
		#if (West + South = 2)
			object {GSprites_Tube_Corner_Inner_Prototype(Wid,Hgh,0,000)}
		#end
		#if (East + North = 0)
			object {GSprites_Tube_Corner_Outer_Prototype(Wid,Hgh,0,000)}
		#end
		#if (South + East = 2)
			object {GSprites_Tube_Corner_Inner_Prototype(Wid,Hgh,0,270)}
		#end
		#if (North + West = 0)
			object {GSprites_Tube_Corner_Outer_Prototype(Wid,Hgh,0,270)}
		#end
		#if (East + North = 2)
			object {GSprites_Tube_Corner_Inner_Prototype(Wid,Hgh,0,180)}
		#end
		#if (West + South = 0)
			object {GSprites_Tube_Corner_Outer_Prototype(Wid,Hgh,0,180)}
		#end
		#if (North + West = 2)
			object {GSprites_Tube_Corner_Inner_Prototype(Wid,Hgh,0,090)}
		#end
		#if (South + East = 0)
			object {GSprites_Tube_Corner_Outer_Prototype(Wid,Hgh,0,090)}
		#end
	}
#end


// -------------------------------------------------------------
// Fence posts

#macro GSprites_Fence_Wall_Posts(North,East,South,West,Wid,Hgh)
	union
	{
		#local Fence_Radius	= Wid/64;
		#local Fence_Vector	= -z * Wid/2 * GSprites_Tiles_Factor;
		#local Radius_Vector	= +y * Fence_Radius;
		#local UpSky_Vector	= +y * Hgh - Radius_Vector;
		#local Fence_Section = union
		{
			cylinder {0,Fence_Vector,Fence_Radius translate Radius_Vector}
			cylinder {0,Fence_Vector,Fence_Radius translate UpSky_Vector}
			cylinder {Radius_Vector,UpSky_Vector,Fence_Radius translate Fence_Vector}
			sphere {Fence_Vector,Fence_Radius translate Radius_Vector}
			sphere {Fence_Vector,Fence_Radius translate UpSky_Vector}
		}
		cylinder {0,UpSky_Vector,Fence_Radius}
		#if (North = 1)
			object {Fence_Section rotate y * 000}
		#end
		#if (East = 1)
			object {Fence_Section rotate y * 090}
		#end
		#if (South = 1)
			object {Fence_Section rotate y * 180}
		#end
		#if (West = 1)
			object {Fence_Section rotate y * 270}
		#end
		texture {Post_Texture}
	}
#end


// -------------------------------------------------------------
// Razor wire

#macro GSprites_Razor_Wall_Prototype(North,East,South,West,Wid,Hgh,Tiles_Steps)
	#local HlfWid	= Wid/2;
	#local HlfHgh	= Hgh/2;
	#local Thk	= 1/32;
	#local Trn	= 128/HlfHgh * GSprites_Tiles_Factor;
	#local T1_Val	= 0;
	#local T2_Val	= 0;
	#local Razor_Blade = mesh
	{
		#local P_1	= <-2,1,0,>;
		#local P_2	= <+2,1,0,>;
		#local P_3	= <-1,0,0,>;
		#local P_4	= <+1,0,0,>;
		triangle {P_1,P_2,P_4}
		triangle {P_4,P_3,P_1}
		rotate	y * 90
		rotate	z * -90
		scale	Thk
	}
	#local Razor_Coil = union
	{
		#local Count	= 0;
		#while (Count < Tiles_Steps)
			#local T2_Val	= T1_Val;
			#local T1_Val	= T1_Val + 1/Tiles_Steps;
			#local P_1	= <1 * cos(Trn * T1_Val * 2 * pi), T1_Val, (1 + Thk/2) * sin(Trn * T1_Val * 2 * pi),>;
			#local P_2	= <(1 - Thk) * cos(Trn * T1_Val * 2 * pi), T1_Val, (1 - Thk/2) * sin(Trn * T1_Val * 2 * pi),>;
			#local P_3	= <1 * cos(Trn * T2_Val * 2 * pi), T2_Val, (1 + Thk/2) * sin(Trn * T2_Val * 2 * pi),>;
			#local P_4	= <(1 - Thk) * cos(Trn * T2_Val * 2 * pi), T2_Val, (1 - Thk/2) * sin(Trn * T2_Val * 2 * pi),>;
			object {Razor_Blade rotate -y * degrees(Trn * T1_Val * 2 * pi) translate P_1}
			object {Razor_Blade rotate -y * degrees(Trn * T1_Val * 2 * pi) rotate y * 180 translate P_2}
			triangle {P_1,P_2,P_4}
			triangle {P_4,P_3,P_1}
			#local Count = Count + 1;
		#end
		translate	x * (1+Thk)
		scale		<HlfHgh*(1-Thk*2),HlfWid * GSprites_Tiles_Factor,HlfHgh*(1-Thk*2),>
		rotate		z * 90
		rotate		y * -90
	}
	union
	{
		#if (North = 1)
			object {Razor_Coil rotate y * 000}
		#end
		#if (East = 1)
			object {Razor_Coil rotate y * 090}
		#end
		#if (South = 1)
			object {Razor_Coil rotate y * 180}
		#end
		#if (West = 1)
			object {Razor_Coil rotate y * 270}
		#end
	}
#end

// -------------------------------------------------------------
// Flat walls

#macro GSprites_Flat_Wall_Prototype(North,East,South,West,Wid,Hgh,Bot,Top)
	#local HlfBot	= Bot/2;
	#local HlfTop	= Top/2;
	#local HlfWid	= Wid/2;
	#local BotWid	= HlfBot;
	#local TopWid	= HlfTop;
	#local MaxWid	= max(BotWid,TopWid,HlfWid) * GSprites_Tiles_Factor;
	#local Ang	= atan2d(Hgh,BotWid-TopWid);
	intersection
	{
		union
		{
			intersection
			{
				plane
				{
					y, 0 rotate x * -Ang translate z * -BotWid
					texture {Wall_Texture rotate y * 180 * AlignY}
				}
				plane
				{
					y, 0 rotate x * Ang translate z * BotWid
					texture {Wall_Texture rotate y * 000 * AlignY}
				}
				bounded_by {box {<-MaxWid,0,-MaxWid,>,<MaxWid,Hgh,MaxWid,>}}
			}
			intersection
			{
				plane
				{
					y, 0 rotate z * Ang translate x * -BotWid
					texture {Wall_Texture rotate y * 270 * AlignY}
				}
				plane
				{
					y, 0 rotate z * -Ang translate x * BotWid
					texture {Wall_Texture rotate y * 090 * AlignY}
				}
				bounded_by {box {<-MaxWid,0,-MaxWid,>,<MaxWid,Hgh,MaxWid,>}}
			}
		}
		#if (North = 0)
			plane
			{
				y, 0 rotate x * -Ang translate z * -BotWid
				texture {Wall_Texture rotate y * 180 * AlignY}
			}
		#else
			plane {-z, HlfWid * GSprites_Tiles_Factor texture {Mask_Texture rotate y * 180 * AlignY}}
		#end
		#if (East = 0)
			plane
			{
				y, 0 rotate z * Ang translate x * -BotWid
				texture {Wall_Texture rotate y * 270 * AlignY}
			}
		#else
			plane {-x, HlfWid * GSprites_Tiles_Factor texture {Mask_Texture rotate y * 270 * AlignY}}
		#end
		#if (South = 0)
			plane
			{
				y, 0 rotate x * Ang translate z * BotWid
				texture {Wall_Texture rotate y * 000 * AlignY}
			}
		#else
			plane {z, HlfWid * GSprites_Tiles_Factor texture {Mask_Texture rotate y * 000 * AlignY}}
		#end
		#if (West = 0)
			plane
			{
				y, 0 rotate z * -Ang translate x * BotWid
				texture {Wall_Texture rotate y * 090 * AlignY}
			}
		#else
			plane {x, HlfWid * GSprites_Tiles_Factor texture {Mask_Texture rotate y * 090 * AlignY}}
		#end
		plane {+y, Hgh texture {Roof_Texture}}
		plane {-y,   0 texture {Floor_Texture}}
		bounded_by {box {<-MaxWid,0,-MaxWid,>,<+MaxWid,Hgh,+MaxWid,>}}
	}
#end


// -------------------------------------------------------------
// Blocky walls

#macro GSprites_Block_Wall_Intersection(Rows,Cols,MortarWidth,Wid,Hgh,Bot,Top)
	#local HlfBot	= Bot/2;
	#local HlfTop	= Top/2;
	#local HlfWid	= Wid/2;
	#local BotWid	= HlfBot;
	#local TopWid	= HlfTop;
	#local MaxWid	= max(BotWid,TopWid,HlfWid) * GSprites_Tiles_Factor;
	#local XZFudge	= (x+z)*17/16;
	#local BrickWid	= Wid/Cols;
	#local BrickHgh	= Hgh/Rows;
	#local TexRot	= 0;
	#if ((North + East + South + West = 2) & (North + South = 2))
		#local TexRot	= 090;
	#end
	#local temp_texture	= Wall_Texture;
	#local Wall_Texture	= texture {temp_texture rotate y * TexRot scale XZFudge}
	intersection
	{

		union
		{
			#local RowMax = Rows * GSprites_Tiles_Factor;
			#local ColMax = Cols * GSprites_Tiles_Factor + 1;
			#local Count1 = 0;
			#while (Count1 < RowMax)
				#local Modulos = mod(Count1 * 3, 2);
				#local Count2 = 0;
				#while (Count2 < ColMax)
					#local Count3 = 0;
					#while (Count3 < ColMax)
						box
						{
							-<BrickWid,BrickHgh,BrickWid,>/2 + MortarWidth/2,
							+<BrickWid,BrickHgh,BrickWid,>/2 - MortarWidth/2
							translate
							  <BrickWid,BrickHgh,BrickWid,>/2
							+ <Count2*BrickWid,Count1*BrickHgh,Count3*BrickWid,>
							- <HlfWid*GSprites_Tiles_Factor,0,HlfWid*GSprites_Tiles_Factor,>
							- <BrickWid,0,BrickWid,> / ((Modulos != 0) ? 2 : 1)
						}
						#local Count3 = Count3 + 1;
					#end
					#local Count2 = Count2 + 1;
				#end
				#local Count1 = Count1 + 1;
			#end
			scale XZFudge
		}
/*
		union
		{
			#local Count1 = 0;
			#while (Count1 < Rows * GSprites_Tiles_Factor)
				#local Count2 = 0;
				#local Modulos = mod(Count1 * 3, 2);
				#local AddOne = Cols * GSprites_Tiles_Factor + 1;
				#while (Count2 < AddOne)
					#local Count3 = 0;
					#while (Count3 < AddOne)
						#local Scale_Vector = <(Wid-MortarWidth*Cols)/Wid/Cols,(Hgh-MortarWidth*Rows)/Hgh/Rows,(Wid-MortarWidth*Cols)/Wid/Cols,>;
						#local Trans_Vector = <Count2*Wid/Cols+MortarWidth-Wid/2*GSprites_Tiles_Factor,Count1*Hgh/Rows+MortarWidth,Count3*Wid/Cols+MortarWidth-Wid/2*GSprites_Tiles_Factor,>;
						#if (Modulos != 0)
							#local Trans_Vector = Trans_Vector - <Wid/Cols/2,0,Wid/Cols/2,>;
						#else
							#local Trans_Vector = Trans_Vector - <Wid/Cols,0,Wid/Cols,>;
						#end
						box {<0,0,0,>, <Wid,Hgh,Wid,> scale Scale_Vector translate Trans_Vector}
						#local Count3 = Count3 + 1;
					#end
					#local Count2 = Count2 + 1;
				#end
				#local Count1 = Count1 + 1;
			#end
		}
*/
		object {GSprites_Flat_Wall_Prototype(North,East,South,West,Wid,Hgh,Bot,Top)}
		bounded_by {box {<-MaxWid,0,-MaxWid,>,<+MaxWid,Hgh,+MaxWid,>}}
		texture {Wall_Texture}
	}
#end

// brick wall with windows
#macro GSprites_Brick_Wall_Prototype(North,East,South,West,Wid,Hgh,Bot,Top)
	#local HlfBot	= Bot/2;
	#local HlfTop	= Top/2;
	#local HlfWid	= Wid/2;
	#local TilWid	= HlfWid * GSprites_Tiles_Factor;
	#local W_T	= texture {Wall_Texture}
	#local M_T	= texture {Mask_Texture}
	#local R_T	= texture {Roof_Texture}
	#local F_T	= texture {Floor_Texture}
	#local Bound_Box = box {<-TilWid,0,-TilWid,>, <+TilWid,Hgh,+TilWid,>}
	#local Long_Side = union
	{
		// window mortar padding
		difference
		{
			box
			{
				-1,1
				translate	y
				scale		1/2
				scale		x * Bot
				scale		z * (Wid - Wid/Cols * Column_Skip)
				scale		y * (Hgh - Hgh/Rows * (TopRow_Skip + BotRow_Skip))
				translate	y * (Hgh/Rows * BotRow_Skip)
			}
			box
			{
				-1,1
				translate	y
				scale		1/2
				scale		x * (Wid)
				scale		z * (Wid - Wid/Cols * Column_Skip - MortarWidth * 2)
				scale		y * (Hgh - Hgh/Rows * (TopRow_Skip + BotRow_Skip) - MortarWidth * 2)
				translate	y * (Hgh/Rows * BotRow_Skip + MortarWidth)
			}
			bounded_by {Bound_Box}
			texture {Sill_Texture}
		}
		// window sill
		box
		{
			-1,+1
			translate	y
			scale		1/2
			scale		x * SillWidth
			scale		z * (Wid - Wid/Cols * Column_Skip)
			scale		y * SillHeight
			translate	y * (Hgh/Rows * BotRow_Skip + MortarWidth)
			texture {Sill_Texture}
		}
		// window frame
		difference
		{
			box
			{
				-1,+1
				translate	y
				scale		1/2
				scale		x * (HlfBot - MortarDepth * 2 - WindowFrameWidth * 2)
				scale		z * (Wid - Wid/Cols * Column_Skip - MortarWidth * 2)
				scale		y * (Hgh - Hgh/Rows * (TopRow_Skip + BotRow_Skip) - SillHeight - MortarWidth)
				translate	y * (Hgh/Rows * BotRow_Skip + SillHeight + MortarWidth)
			}
			box
			{
				-1,+1
				translate	y
				scale		1/2
				scale		x * (Wid)
				scale		z * (Wid - Wid/Cols * Column_Skip - MortarWidth * 2 - WindowFrameWidth * 2)
				scale		y * (Hgh - Hgh/Rows * (TopRow_Skip + BotRow_Skip) - SillHeight - MortarWidth - WindowFrameWidth * 2)
				translate	y * (Hgh/Rows * BotRow_Skip + WindowFrameWidth + SillHeight + MortarWidth)
			}
			bounded_by {Bound_Box}
			texture {Frame_Texture}
		}
		// glass
		box
		{
			-1,+1
			translate	y
			scale		1/2
			scale		x * (HlfBot - MortarDepth * 2 - WindowFrameWidth * 1)
			scale		z * (Wid - Wid/Cols * Column_Skip - MortarWidth * 2 - WindowFrameWidth * 2)
			scale		y * (Hgh - Hgh/Rows * (TopRow_Skip + BotRow_Skip) - SillHeight - MortarWidth - WindowFrameWidth * 2)
			translate	y * (Hgh/Rows * BotRow_Skip + WindowFrameWidth + SillHeight + MortarWidth)
			texture {Glass_Texture}
		}
	}
	#local Window_Hole = box
	{
		-1,1
		translate	y
		scale		1/2
		scale		x * (Wid)
		scale		z * (Wid - Wid/Cols * Column_Skip)
		scale		y * (Hgh - Hgh/Rows * (TopRow_Skip + BotRow_Skip))
		translate	y * (Hgh/Rows * BotRow_Skip)
		scale		1.00001
		texture {GSprites_Plain_Clear}
	}
	union
	{
		difference
		{
			union
			{
/*
				intersection
				{
					union
					{
						#local Count1 = 0;
						#while (Count1 < Rows)
							// need to adjust topthick and botthick to take Count1 into account.
							#local Offset = y * Count1 * Hgh/Rows;
							#local Wall_Texture	= texture {W_T translate -Offset}
							#local Mask_Texture	= texture {M_T translate -Offset}
							#local Roof_Texture	= texture {R_T translate -Offset}
							#local Floor_Texture	= texture {F_T translate -Offset}
							object {GSprites_Flat_Wall_Prototype(North,East,South,West,HlfWid,Hgh,HlfBot,HlfTop) translate Offset}
							#local Count1 = Count1 + 1;
						#end
					}
					object
					{
						#local Wall_Texture	= texture {W_T}
						#local Mask_Texture	= texture {M_T}
						#local Roof_Texture	= texture {R_T}
						#local Floor_Texture	= texture {F_T}
						GSprites_Block_Wall_Intersection(Rows,Cols,MortarWidth,HlfWid,Hgh,HlfBot,HlfTop)
					}
					bounded_by {Bound_Box}
				}
*/
				// patterned wall
				object
				{
					#local Wall_Texture	= texture {W_T}
					#local Mask_Texture	= texture {M_T}
					#local Roof_Texture	= texture {R_T}
					#local Floor_Texture	= texture {F_T}
					GSprites_Block_Wall_Intersection(Rows,Cols,MortarWidth,Wid,Hgh,Bot,Top)
				}
				// mortar
				object
				{
					#local Wall_Texture	= texture {Mortar_Texture}
					#local Mask_Texture	= texture {Mortar_Texture}
					#local Roof_Texture	= texture {Mortar_Texture}
					#local Floor_Texture	= texture {Mortar_Texture}
					GSprites_Flat_Wall_Prototype(North,East,South,West,Wid,Hgh,Bot,Top)
					scale <(HlfWid-MortarDepth)/HlfWid,(Hgh-MortarDepth)/Hgh,(HlfWid-MortarDepth)/HlfWid,>
				}
			}
			// hole for window
			#if ((((North = 1 & South = 1) & (North + East + South + West = 2)) | (HlfBot = Wid)) & (AddWindows = 1))
				object {Window_Hole}
			#end
			// hole for window
			#if ((((East = 1 & West = 1) & (North + East + South + West = 2)) | (HlfBot = Wid)) & (AddWindows = 1))
				object {Window_Hole rotate y * 90}
			#end
			bounded_by {Bound_Box}
		}
		#if ((((North = 1 & South = 1) & (North + East + South + West = 2)) | (HlfBot = Wid)) & (AddWindows = 1))
			object {Long_Side}
		#end
		#if ((((East = 1 & West = 1) & (North + East + South + West = 2)) | (HlfBot = Wid)) & (AddWindows = 1))
			object {Long_Side rotate y * 90}
		#end
		// top mask
		#if (TopMask)
			intersection
			{
				plane
				{
					y,0
					translate y * (Hgh + 0.00001)
				}
				object
				{
					#local Wall_Texture	= texture {GSprites_Plain_Clear}
					#local Mask_Texture	= texture {GSprites_Plain_Clear}
					#local Roof_Texture	= texture {GSprites_Plain_Clear}
					#local Floor_Texture	= texture {GSprites_Plain_Clear}
					GSprites_Flat_Wall_Prototype(North,East,South,West,Wid,Hgh,Bot,Top)
					translate	y * Hgh
				}
				bounded_by {Bound_Box}
				texture {R_T translate <HlfWid/Cols,0,HlfWid/Cols,>}
			}
		#end
	}
#end

#macro GSprites_Arena_Wall_Prototype(North,East,South,West,Wid,Hgh,Tiles_Seed,Flag_Dir,Number_Fans)
	#local HlfWid	= Wid/2;
	#local Len	= HlfWid * GSprites_Tiles_Factor;
	#local Dep	= Wid/3;
	#local Ang	= 000;
	#if ((North + South = 0) & (East + West = 2))
		#local Ang	= 000;
	#end
	#if ((North + South = 2) & (East + West = 0))
		#local Ang	= 090;
	#end
	#local Arena_Flags = polygon
	{
		3, <0,0,0,>, <0,8,-8,>, <0,8,0,>
		texture {Flag_Texture}
		rotate		y * (Flag_Dir - Ang)
	}
	#local Arena_People = sphere
	{
		0,1
		translate	y
		scale		<1,2,1,>
	}
	#local Arena_Arches = union
	{
		difference
		{
			cylinder {<0,0,-Dep,>,<0,0,-Len,>,Hgh/1}
			cylinder {<0,0,-Dep,>,<0,0,-Len,>,Hgh/2}
			plane {y, 0}
		}
		union
		{
			plane {-y, 0}
			plane {-x, 0}
			clipped_by {cylinder {<0,0,-Dep,>,<0,0,-HlfWid,>,Hgh}}
		}
		scale x * HlfWid/2/Hgh
	}
	#local Arena_Gates = union
	{
		box {<-Dep/1,+0,-Hgh/2,>, <+Dep/1,+Hgh/2,+Hgh/2,> scale x * 1.01}
		box {<-Hgh/2,+0,-Dep/1,>, <+Hgh/2,+Hgh/2,+Dep/1,> scale z * 1.01}
	}
	#local Arena_Stands = union
	{
		difference
		{
			box {<-Len,0,-Dep,>, <+Len,+Hgh*2,+Dep,> hollow}
			plane {-y,0 rotate x * 45 / 2 translate y * Hgh /**3/2*/}
			plane {-y,0 rotate x * -45 / 2 translate y * Hgh /** 3/2*/}
		}
		cylinder
		{
			<-Len * 0.999,0,0,>,
			<+Len * 0.999,0,0,>,
			Dep
			texture {Dome_Texture}
			hollow
			translate	y * Hgh
		}
		cylinder
		{
			<-Len - HlfWid/32,0,0,>,
			<+Len + HlfWid/32,0,0,>,
			HlfWid/8
			translate	y * Hgh
		}
/*
		torus
		{
			Dep,HlfWid/32
			rotate		z * 90
			translate	y * Hgh
		}
*/
		torus
		{
			Dep,HlfWid/32
			rotate		z * 90
			translate	y * +Hgh
			translate	x * -Len
		}
		torus
		{
			Dep,HlfWid/32
			rotate		z * 90
			translate	y * +Hgh
			translate	x * +Len
		}
		object {Arena_Flags translate <-Len,Hgh + Dep,0,>}
//		object {Arena_Flags translate <0,Hgh + Dep,0,>}
		object {Arena_Flags translate <Len,Hgh + Dep,0,>}
		#local Count_Fans = 0;
		#while (Count_Fans < Number_Fans*1/2)
			object
			{
				Arena_People
				#local rand_x	= rand(Tiles_Seed);
				#local rand_z	= rand(Tiles_Seed);
				#local rand_y	= 1 - rand_z;
				GSprites_Random_Wall_Texture(Tiles_Seed)
				translate	x * (rand_x * 14*Len/8 + Len/8 - Len)
				translate	y * (rand_y * Hgh/2*6/8 + Hgh/2*1/8 + Hgh/2)
				translate	z * -(rand_z * Dep*5/8 + Dep*2/8)
			}
			#local Count_Fans = Count_Fans + 1;
		#end
		#local Count_Fans = 0;
		#while (Count_Fans < Number_Fans*1/2)
			object
			{
				Arena_People
				#local rand_r	= rand(Tiles_Seed);
				#local rand_g	= rand(Tiles_Seed);
				#local rand_b	= rand(Tiles_Seed);
				#local rand_x	= rand(Tiles_Seed);
				#local rand_z	= rand(Tiles_Seed);
				#local rand_y	= 1 - rand_z;
				texture
				{
					pigment {color rgb <rand_r,rand_g,rand_b,>}
					finish {GSprites_Default_Finish}
				}
				translate	x * (rand_x * 14*Len/8 + Len/8 - Len)
				translate	y * (rand_y * Hgh/2*6/8 + Hgh/2*1/8 + Hgh/2)
				translate	z * (rand_z * Dep*5/8 + Dep*2/8)
			}
			#local Count_Fans = Count_Fans + 1;
		#end
		clipped_by {plane {-y,0}}
		rotate		y * Ang
		clipped_by {plane {-y,0}}
	}
	#local Arena_Tower = union
	{
		difference
		{
			box {<-Dep,+0,-Dep,>, <+Dep,+Hgh,+Dep,>}
			object {Arena_Gates}
			cylinder {0, y * Hgh, Dep scale y * 1.01}
		}
		object
		{
			Arena_Gates
			clipped_by
			{
				union
				{
					box {<-Dep,+0,-Dep,>, <+Dep,+Hgh,+Dep,>}
					cylinder {0, y * Hgh, Dep scale 1.02}
					inverse
				}
			}
			texture {Dome_Texture}
		}
		intersection
		{
			plane {y,0}
			box {<-Dep,+0,-Dep,>, <+Dep,+Hgh,+Dep,>}
		}
		union
		{
			#local Dome_Radius = Dep;
			sphere
			{
				0, Dome_Radius
				texture {Dome_Texture}
				hollow
				clipped_by {plane {-y,0}}
			}
			sphere
			{
				0, Dome_Radius
				hollow
				clipped_by {plane {-y,-sin(5*pi/12)*Dome_Radius}}
				scale		1.0001
			}
/*
			torus
			{
				Dome_Radius*cos(pi/6),HlfWid/64
				translate	y * Dome_Radius*sin(pi/6)
			}
			torus
			{
				Dome_Radius,HlfWid/64
				rotate		x * 90
				clipped_by {plane {-y,0}}
			}
			torus
			{
				Dome_Radius,HlfWid/64
				rotate		z * 90
				clipped_by {plane {-y,0}}
			}
*/
			translate	y * Hgh
		}
		#local Count_Fans = 0;
		#while (Count_Fans < Number_Fans*1/4)
			object
			{
				Arena_People
				#local rand_x	= rand(Tiles_Seed) * 0.9;
				#local rand_z	= rand(Tiles_Seed) * 0.9;
				#local rand_p	= rand(Tiles_Seed);
				GSprites_Random_Wall_Texture(Tiles_Seed)
				translate	x * (rand_x * Dep * cos(rand_p * pi * 2))
				translate	z * (rand_z * Dep * sin(rand_p * pi * 2))
				no_shadow
			}
			#local Count_Fans = Count_Fans + 1;
		#end
		object {Arena_Flags translate <0,Hgh+Dep,0,>}
		#if (North = 1)
			object {Arena_Arches rotate y*000}
		#end
		#if (East = 1)
			object {Arena_Arches rotate y*090}
		#end
		#if (South = 1)
			object {Arena_Arches rotate y*180}
		#end
		#if (West = 1)
			object {Arena_Arches rotate y*270}
		#end
		clipped_by {plane {-y,0}}
	}
	
	// -------------------------------------------------------------
	// the final object
	
	#if (((North + South = 2) & (East + West = 0)) | ((North + South = 0) & (East + West = 2)))
		object {Arena_Stands texture {Wall_Texture}}
	#else
		object {Arena_Tower texture {Wall_Texture}}
	#end
#end


// -------------------------------------------------------------
// Definitions for the various wall types

// There is a slight issues with the texture where the wall 
// meets at an intersection. I hope to resolve it sometime in 
// the future.
#macro GSprites_Guts_Tube_Object(North,East,South,West,Tiles_Width,Tiles_Height)
	#local Tube_Radius		= Tiles_Width/2/cos(pi/4) * 5/4;
	#local Wall_Texture		= GSprites_Guts_Straight_Texture();
	#local Mask_Texture		= GSprites_Plain_MedRed;
	#local Roof_Texture		= texture {GSprites_Guts_Roof_Texture scale <Tiles_Width,Tiles_Width,Tiles_Width,>};
	#local Floor_Texture		= texture {GSprites_Guts_Roof_Texture scale <Tiles_Width,Tiles_Width,Tiles_Width,>};
	#local Outer_Corner_Texture	= GSprites_Guts_Outer_Texture();
	#local Inner_Corner_Texture	= GSprites_Guts_Inner_Texture();
	GSprites_Tube_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height)
#end

// There is a slight issues with the texture where the wall 
// meets at an intersection. I hope to resolve it sometime in 
// the future.
#macro GSprites_Techy_Tube_Object(North,East,South,West,Tiles_Width,Tiles_Height)
	#local Tube_Radius		= Tiles_Width/2/cos(pi/4) * 5/4;
	#local Wall_Texture		= GSprites_Tech_Straight_Texture();
	#local Mask_Texture		= GSprites_Plain_Gray;
	#local Roof_Texture		= GSprites_Plain_Black;
	#local Floor_Texture		= texture {GSprites_Tech_Roof_Texture scale <Tiles_Width,Tiles_Width,Tiles_Width,>};
	#local Outer_Corner_Texture	= GSprites_Tech_Outer_Texture();
	#local Inner_Corner_Texture	= GSprites_Tech_Inner_Texture();
	GSprites_Tube_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height)
#end

#macro GSprites_Razor_Wall_Object(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Steps)
	object
	{
		GSprites_Razor_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Steps)
		texture {GSprites_Plain_Gray}
	}
#end

#macro GSprites_Fence_Wall_Object(North,East,South,West,Tiles_Width,Tiles_Height)
	#local AlignY		= on;			// should textures be rotated to match the wall face's normal?
	#local Wall_Texture	= texture {GSprites_Fence_Wall_Texture scale 4};
	#local Mask_Texture	= texture {GSprites_Fence_Wall_Texture scale 4};
	#local Roof_Texture	= texture {GSprites_Fence_Wall_Texture scale 4};
	#local Floor_Texture	= texture {GSprites_Fence_Wall_Texture scale 4};
	#local Post_Texture	= GSprites_Plain_Gray;
	union
	{
		GSprites_Flat_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,0,0)
		GSprites_Fence_Wall_Posts(North,East,South,West,Tiles_Width,Tiles_Height)
	}
#end

#macro GSprites_Stone_Wall_Object(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick)
	#local AlignY		= on;			// should textures be rotated to match the wall face's normal?
	#local Wall_Texture	= GSprites_StoneBlock_Wall_Texture_C;
	#local Mask_Texture	= GSprites_StoneBlock_Wall_Texture_C;
	#local Roof_Texture	= GSprites_StoneBlock_Wall_Texture_C;
	#local Floor_Texture	= GSprites_StoneBlock_Wall_Texture_C;
	GSprites_Flat_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick,Tiles_Thick/2)
#end

// used for restaraunts
#macro GSprites_Restaraunt_Wall_Object(Tiles_North,Tiles_East,Tiles_South,Tiles_West,Tiles_Width,Tiles_Height,Tiles_Thick)
	#local TopMask		= off;			// should a mask be added to obscure the top?
	#local AlignY		= off;			// should textures be rotated to match the wall face's normal?
	#local AddWindows	= on;			// should windows be inserted into long walls?
	#local AddWindowSill	= on;			// should windowsills be added beneath windows?
	#local Rows		= 12;			// the wall is composed of this may rows of bricks
	#local Cols		= 4;			// the wall is composed of this many colums of bricks
	#local MortarWidth	= Tiles_Width/32;	// width of the mortar between bricks
	#local MortarDepth	= Tiles_Width/128;	// approximate depth of the mortar between bricks
	#local TopRow_Skip	= 2;			// this many rows of bricks separate the window from the top of the wall
	#local BotRow_Skip	= 2;			// this many rows of bricks separate the window from the bottom of the wall	
	#local Column_Skip	= 2;			// this many columns of bricks separate the window from the sides of the wall
	#local WindowFrameWidth	= Tiles_Width/16;	// the width of the window frame
	#local SillHeight	= Tiles_Height/Rows/2;	// the height of the window sill
	#local SillWidth	= Tiles_Thick * 5/4;	// the width of the window sill
	#local Wall_Texture	= GSprites_Plank_Wall_Texture_E()
	#local Mask_Texture	= GSprites_Plank_Wall_Texture_E()
	#local Roof_Texture	= GSprites_Plank_Wall_Texture_E()
	#local Floor_Texture	= GSprites_Plank_Wall_Texture_E()
	#local Sill_Texture	= texture {GSprites_Plain_Gray}
	#local Mortar_Texture	= texture {GSprites_Plain_Gray}
	#local Frame_Texture	= texture {GSprites_Plain_MedGreen}
	#local Glass_Texture	= texture
	{
		pigment {color rgbt 1/2}
		finish {GSprites_Default_Finish phong 1 specular 0}
	}
	#local Roof_Mask_Texture = texture {GSprites_Plain_Black}
	GSprites_Brick_Wall_Prototype(Tiles_North,Tiles_East,Tiles_South,Tiles_West,Tiles_Width,Tiles_Height,Tiles_Thick,Tiles_Thick)
#end

// used for hospitals
#macro GSprites_Hospital_Wall_Object(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick)
	#local TopMask		= off;			// should a mask be added to obscure the top?
	#local AlignY		= on;			// should textures be rotated to match the wall face's normal?
	#local AddWindows	= off;			// should windows be inserted into long walls?
	#local AddWindowSill	= off;			// should windowsills be added beneath windows?
	#local Rows		= 6;			// the wall is composed of this may rows of bricks
	#local Cols		= 2;			// the wall is composed of this many colums of bricks
	#local MortarWidth	= Tiles_Width/16;	// width of the mortar between bricks
	#local MortarDepth	= Tiles_Width/128;	// approximate depth of the mortar between bricks
	#local TopRow_Skip	= 2;			// this many rows of bricks separate the window from the top of the wall
	#local BotRow_Skip	= 2;			// this many rows of bricks separate the window from the bottom of the wall	
	#local Column_Skip	= 2;			// this many columns of bricks separate the window from the sides of the wall
	#local WindowFrameWidth	= Tiles_Width/16;	// the width of the window frame
	#local SillHeight	= Tiles_Height/Rows/2;	// the height of the window sill
	#local SillWidth	= Tiles_Thick * 5/4;	// the width of the window sill
//	#local Wall_Texture	= texture {GSprites_Hospital_Wall_Texture_A scale <Tiles_Width,80,Tiles_Width,>*Tiles_Height/80}
//	#local Mask_Texture	= texture {GSprites_Hospital_Wall_Texture_A scale <Tiles_Width,80,Tiles_Width,>*Tiles_Height/80}
	#local Wall_Texture	= GSprites_Hospital_Wall_Texture_B(North,East,South,West)
	#local Mask_Texture	= GSprites_Hospital_Wall_Texture_B(North,East,South,West)
	#local Roof_Texture	= texture {GSprites_Plain_White}
	#local Floor_Texture	= texture {GSprites_Plain_White}
	#local Sill_Texture	= texture {GSprites_Plain_White}
//	#local Mortar_Texture	= texture {GSprites_Hospital_Wall_Texture_A scale <Tiles_Width,80,Tiles_Width,>*Tiles_Height/80}
	#local Mortar_Texture	= GSprites_Hospital_Wall_Texture_B(North,East,South,West)
	#local Frame_Texture	= texture {GSprites_Plain_Green}
	#local Glass_Texture	= texture
	{
		pigment {color rgbt 1/2}
		finish {GSprites_Default_Finish phong 1 specular 0}
	}
	GSprites_Brick_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick,Tiles_Thick)
#end

#macro GSprites_Block_Wall_Object(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick)
	#local TopMask		= off;			// should a mask be added to obscure the top?
	#local AlignY		= off;			// should textures be rotated to match the wall face's normal?
	#local AddWindows	= off;			// should windows be inserted into long walls?
	#local AddWindowSill	= off;			// should windowsills be added beneath windows?
	#local Rows		= 8;			// the wall is composed of this may rows of bricks
	#local Cols		= 4;			// the wall is composed of this many colums of bricks
	#local MortarWidth	= Tiles_Width/32;	// width of the mortar between bricks
	#local MortarDepth	= Tiles_Width/128;	// approximate depth of the mortar between bricks
	#local TopRow_Skip	= 1;			// this many rows of bricks separate the window from the top of the wall
	#local BotRow_Skip	= 2;			// this many rows of bricks separate the window from the bottom of the wall	
	#local Column_Skip	= 3/2;			// this many columns of bricks separate the window from the sides of the wall
	#local WindowFrameWidth	= Tiles_Width/16;	// the width of the window frame
	#local SillHeight	= Tiles_Height/Rows/2;	// the height of the window sill
	#local SillWidth	= Tiles_Thick * 5/4;	// the width of the window sill
	#local Wall_Texture	= GSprites_StoneBlock_Wall_Texture_A();
	#local Mask_Texture	= GSprites_StoneBlock_Wall_Texture_A();
	#local Roof_Texture	= GSprites_StoneBlock_Wall_Texture_A();
	#local Floor_Texture	= texture {GSprites_Plain_Gray}
	#local Sill_Texture	= texture {GSprites_Plain_Gray}
	#local Mortar_Texture	= texture {GSprites_Plain_Gray}
	#local Frame_Texture	= texture {GSprites_Plain_Black}
	#local Glass_Texture	= texture
	{
		pigment {color rgbt <1/2,1/2,1/2,1/2,>}
		finish {specular 0.5 brilliance 0.5}
	}
	#local Roof_Mask_Texture = texture {GSprites_Plain_Black}
	GSprites_Brick_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick,Tiles_Thick)
#end

#macro GSprites_Fortress_Wall_Object(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick)
	#local show_glass	= on;
	#local tower_width	= Tiles_Thick;
	#local glass_height	= Tiles_Height/4;
	#local glass_width	= tower_width/2;
	#local roof_height	= Tiles_Height/32;
	#local razor_height	= tower_width/4;
	#local AlignY		= 1;
	#local Wall_Texture	= GSprites_Fortress_Wall_Texture;
	#local Mask_Texture	= GSprites_Fortress_Wall_Texture;
	#local Roof_Texture	= GSprites_Fortress_Wall_Texture;
	#local Floor_Texture	= GSprites_Fortress_Wall_Texture;
	union
	{
		// wall
		GSprites_Flat_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Thick,Tiles_Thick/2)
		#if ((North + South = 1) | (East + West = 1) | (North + East + South + West > 2) | (North + East + South + West = 0))
			// tower
			object {GSprites_Flat_Wall_Prototype(0,0,0,0,tower_width,Tiles_Height,tower_width,tower_width)}
			#if (show_glass)
				// roof
				object {GSprites_Flat_Wall_Prototype(0,0,0,0,tower_width,roof_height,tower_width,tower_width) translate y * (Tiles_Height+glass_height)}
				#local Glass_Texture = texture
				{
					pigment {color rgbt 1/2}
					finish {GSprites_Default_Finish specular 1/2 brilliance 1/2}
				}
				#local Wall_Texture = Glass_Texture;
				#local Mask_Texture = Glass_Texture;
				#local Roof_Texture = Glass_Texture;
				#local Floor_Texture = Glass_Texture;
				// glass
				object {GSprites_Flat_Wall_Prototype(0,0,0,0,tower_width,glass_height,glass_width,tower_width) translate y * Tiles_Height}
			#end
		#end
		object
		{
			GSprites_Razor_Wall_Prototype(North,East,South,West,Tiles_Width,razor_height,240)
			translate y * Tiles_Height
			texture {GSprites_Plain_Gray}
		}
	}
#end

#macro GSprites_Arena_Wall_Object(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Seed,Flag_Dir,Number_Fans)
	#local Dome_Texture	= GSprites_BlueGlass_Wall_Texture;
	#local Wall_Texture	= GSprites_Plain_White;
	#local Flag_Texture	= GSprites_Plain_Red;
	GSprites_Arena_Wall_Prototype(North,East,South,West,Tiles_Width,Tiles_Height,Tiles_Seed,Flag_Dir,Number_Fans)
#end
