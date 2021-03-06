// Title: Fractal Objects Include v1.10
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008/11/26
// Last Updated: 2008/11/26
// This file is licensed under the terms of the CC-LGPL.

//------------------------------
// Menger Sponge
#macro FracObj_Menger_Sponge(dMax, cSca, gWid)
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
	#local gWid = gWid * pow(3, dMax);
	#local bObj = box
	{
		0, 1
		scale cSca - gWid
		translate gWid/2
	}
	#local dCount = 0;
	#while (dCount < dMax)
		#local bObj = merge
		{
			#local iCount = 0;
			#while (iCount < 20)
				#local iCoo = iPos[iCount] * cSca;
				object
				{
					bObj
					translate iCoo
					scale 1/3
				}
				#local iCount = iCount + 1;
			#end
			bounded_by {box {0, cSca}}
		}
		#local dCount = dCount + 1;
	#end
	object { bObj }
#end

//------------------------------
// Sierpinski Pyramid
#macro FracObj_Sierpinski_Pyramid(dMax, cSca, gWid)
	#local rot_ang_x = atan2(cSca.y-gWid/2,cSca.x/2-gWid/2);
	#local rot_ang_z = atan2(cSca.y-gWid/2,cSca.z/2-gWid/2);
	#local iPos = array[5]
	{
		<0,0,0,>,
		<1,0,0,>,
		<1,0,1,>,
		<0,0,1,>,
		<1/2,1,1/2,>
	}
	#local gWid = gWid * pow(2, dMax);
	#local bObj = intersection
	{
		plane { +y, 0 rotate z * +degrees(rot_ang_x) translate           gWid/2  * x }
		plane { +y, 0 rotate z * -degrees(rot_ang_x) translate (cSca.x - gWid/2) * x }
		plane { +y, 0 rotate x * -degrees(rot_ang_z) translate           gWid/2  * z }
		plane { +y, 0 rotate x * +degrees(rot_ang_z) translate (cSca.z - gWid/2) * z }
		plane { -y, 0 translate gWid/2 * y }
		bounded_by {box {0, cSca}}
	}
	#local dCount = 0;
	#while (dCount < dMax)
		#local bObj = merge
		{
			#local iCount = 0;
			#while (iCount < 5)
				#local iCoo = iPos[iCount] * cSca;
				object
				{
					bObj
					translate iCoo
					scale 1/2
				}
				#local iCount = iCount + 1;
			#end
			bounded_by {box {0, cSca}}
		}
		#local dCount = dCount + 1;
	#end
	object { bObj }
#end

// The pyramid is 1 unit high by default; if you want the faces to be equilateral triangles, then scale the y-axis by FracObj_Sierpinski_Pyramid_Eql_Hgh.
#declare FracObj_Sierpinski_Pyramid_Eql_Hgh = sin(acos(1/tan(pi/3))) * tan(pi/3)/2;
//#debug concat("\n\nEql_Hgh = ",str(FracObj_Sierpinski_Pyramid_Eql_Hgh,0,-1),"\n\n")

//------------------------------
// Sierpinski Tetrahedron
#macro FracObj_Sierpinski_Tetrahedron(dMax, cSca, gWid)
	#local leg_dst_1 = cSca.x * tan(pi/6)/2 - gWid/2;
	#local leg_dst_2 = cSca.y - gWid/2;
	#local leg_dst_3 = cSca.x * cos(pi/6)   - gWid/2;
	#local rot_ang_h = atan2(leg_dst_2, leg_dst_1);
	#local rot_ang_v = 30;
	#local iPos = array[4]
	{
		<0,0,0,>,
		<1,0,0,>,
		<1/2,0,sin(pi/3),>,
		<1/2,1,tan(pi/6)/2,>
	}
	#local gWid = gWid * pow(2, dMax);
	#local bObj = intersection
	{
		plane { +y, 0 rotate z * +degrees(rot_ang_h) translate leg_dst_3 * -x rotate y * +rot_ang_v translate +x }
		plane { +y, 0 rotate z * -degrees(rot_ang_h) translate leg_dst_3 * +x rotate y * -rot_ang_v }
		plane { +y, 0 rotate x * -degrees(rot_ang_h) translate gWid/2    * +z }
		plane { -y, 0 translate gWid/2 * y}
		bounded_by {box {0, cSca}}
	}
	#local dCount = 0;
	#while (dCount < dMax)
		#local bObj = merge
		{
			#local iCount = 0;
			#while (iCount < 4)
				#local iCoo = iPos[iCount] * cSca;
				object
				{
					bObj
					translate iCoo
					scale 1/2
				}
				#local iCount = iCount + 1;
			#end
			bounded_by {box {0, cSca}}
		}
		#local dCount = dCount + 1;
	#end
	object { bObj }
#end

// The tetrahedron is 1 unit high by default; if you want the faces to be equilateral triangles, then scale the y-axis by FracObj_Sierpinski_Tetrahedron_Eql_Hgh.
#declare FracObj_Sierpinski_Tetrahedron_Eql_Hgh = sin(acos(tan(pi/6)/2/cos(pi/6))) * cos(pi/6);
//#debug concat("\n\nEql_Hgh = ",str(FracObj_Sierpinski_Tetrahedron_Eql_Hgh,0,-1),"\n\n")
