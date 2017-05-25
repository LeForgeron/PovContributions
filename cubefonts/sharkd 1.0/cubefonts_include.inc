// Title: Cube Fonts macro v1.0
// Author: Michael Horvath
// Homepage: http://isometricland.com
// Created: 2009-10-29
// Last Updated: 2009-10-29
// This file is licensed under the terms of the CC-LGPL.

#macro CBF_String_Macro(CBF_String_Array,CBF_Font_Name,CBF_Text_Obj_Direction,CBF_Char_Distance,CBF_Char_Scale)
	union
	{
		#local CBF_Count = 0;
		#local CBF_String_Length = strlen(CBF_String_Array[0]);
		#while (CBF_Count < CBF_String_Length)
			intersection
			{
				#local CBF_Temp_Char = substr(CBF_String_Array[0],CBF_Count+1,1);
				#if (strcmp(CBF_Temp_Char," ") != 0)
					#local CBF_Text_Obj = text
					{
						ttf CBF_Font_Name CBF_Temp_Char 1/2, 0
						scale 2
					}
					#local CBF_Min_Pos = min_extent(CBF_Text_Obj);
					#local CBF_Max_Pos = max_extent(CBF_Text_Obj);
					#local CBF_Box_Size = CBF_Max_Pos - CBF_Min_Pos;
					object
					{
						CBF_Text_Obj
						translate	-CBF_Min_Pos
						scale		CBF_Char_Scale/CBF_Box_Size
					}
				#end
				#local CBF_Temp_Char = substr(CBF_String_Array[1],CBF_Count+1,1);
				#if (strcmp(CBF_Temp_Char," ") != 0)
					#local CBF_Text_Obj = text
					{
						ttf CBF_Font_Name CBF_Temp_Char 1/2, 0
						scale 2
						rotate		+y * 90
						translate	+z
					}
					#local CBF_Min_Pos = min_extent(CBF_Text_Obj);
					#local CBF_Max_Pos = max_extent(CBF_Text_Obj);
					#local CBF_Box_Size = CBF_Max_Pos - CBF_Min_Pos;
					object
					{
						CBF_Text_Obj
						translate	-CBF_Min_Pos
						scale		CBF_Char_Scale/CBF_Box_Size
					}
				#end
				#local CBF_Temp_Char = substr(CBF_String_Array[2],CBF_Count+1,1);
				#if (strcmp(CBF_Temp_Char," ") != 0)
					#local CBF_Text_Obj = text
					{
						ttf CBF_Font_Name CBF_Temp_Char 1/2, 0
						scale 2
						rotate		+x * 90
						translate	+y
					}
					#local CBF_Min_Pos = min_extent(CBF_Text_Obj);
					#local CBF_Max_Pos = max_extent(CBF_Text_Obj);
					#local CBF_Box_Size = CBF_Max_Pos - CBF_Min_Pos;
					object
					{
						CBF_Text_Obj
						translate	-CBF_Min_Pos
						scale		CBF_Char_Scale/CBF_Box_Size
					}
				#end
				bounded_by
				{
					box {0, 1}
				}
				#local CBF_Temp_Loc = CBF_Char_Distance * CBF_Count;
				#switch (CBF_Text_Obj_Direction)
					#case (0)
						translate	+x * CBF_Temp_Loc
					#break
					#case (1)
						translate	+x * CBF_Temp_Loc
						translate	+z * CBF_Temp_Loc
					#break
					#case (2)
						translate	+z * CBF_Temp_Loc
					#break
					#case (3)
						translate	-x * CBF_Temp_Loc
						translate	+z * CBF_Temp_Loc
					#break
					#case (4)
						translate	-x * CBF_Temp_Loc
					#break
					#case (5)
						translate	-x * CBF_Temp_Loc
						translate	-z * CBF_Temp_Loc
					#break
					#case (6)
						translate	-z * CBF_Temp_Loc
					#break
					#case (7)
						translate	+x * CBF_Temp_Loc
						translate	-z * CBF_Temp_Loc
					#break
					#case (8)
						translate	+y * CBF_Temp_Loc
					#break
					#case (9)
						translate	-y * CBF_Temp_Loc
					#break
				#end
			}
			#local CBF_Count = CBF_Count + 1;
		#end
	}
#end
