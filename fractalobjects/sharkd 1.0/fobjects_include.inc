// Title: Fractal Objects Include v1.00
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/11/23
// Last Updated: 2008/11/23
// This file is licensed under the terms of the CC-LGPL.

//------------------------------
// Menger Sponge
#macro FObjects_Menger_Sponge_Obj(dMax)
	#if (dMax = 0)
		box {0,1}
	#else
		merge
		{
			#local iCount = 0;
			#while (iCount < 20)
				#local iCoo = iPos[iCount];
				object
				{
					FObjects_Menger_Sponge_Obj(dMax - 1)
					translate iCoo
					scale 1/3
				}
				#local iCount = iCount + 1;
			#end
		}
	#end
#end

#macro FObjects_Menger_Sponge(dMax)
	#local iPos = array[20];
	#local iMax = 3;
	#local iCount = 0;
	#local xCount = 0;
	#while (xCount < iMax)
		#local yCount = 0;
		#while (yCount < iMax)
			#local zCount = 0;
			#while (zCount < iMax)
				#if ((xCount = 1) & (yCount = 1))
				#else
					#if ((xCount = 1) & (zCount = 1))
					#else
						#if ((zCount = 1) & (yCount = 1))
						#else
							#local iPos[iCount] = <xCount,yCount,zCount,>;
							#local iCount = iCount + 1;
						#end
					#end
				#end
				#local zCount = zCount + 1;
			#end
			#local yCount = yCount + 1;
		#end
		#local xCount = xCount + 1;
	#end
	object {FObjects_Menger_Sponge_Obj(dMax)}
#end
