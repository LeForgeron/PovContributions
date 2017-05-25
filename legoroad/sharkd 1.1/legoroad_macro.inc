// Title: Lego Road Macro v2.1
// Author: Michael Horvath
// Created: 2005-02-05
// Updated: 2008-06-25
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.


//------------------------------------------------------------------------------Description

// This include file contains macros that generate LDraw-style roads that can be formed into various shapes. There are macros for:
// - creating straight roads
// - creating elliptical roads
// - creating spiral roads
// - creating spline-shaped roads
// - creating straight roads that intersect at any angle
//
// Also supported is super-elevation (banking) of the roads. This can be enabled/disabled when calling the macro.


//------------------------------------------------------------------------------Notes

// If super-elevation is disabled, then tilt angles are interpolated linearly from beginning to end.
// If you enable superelevation, don't make the curve turn too sharply at the beginning, as the change in banking angle will be too abrupt.
// Note that the banking angle at each step is printed to the "Messages" window when you select one of the higher debug levels. You can use this information to determine whether you've set the speed limit too high or too low.
// Banking angles should never be more than 7 degrees on normal roads (5 degrees in icy areas).
// When using the intersection macro, roads will always be flat. Tilting and banking intersections is not supported.


//------------------------------------------------------------------------------Formulae

// Superelevation Formula #1:
// 	e + f = V^2 / 15 * r
//	      = v^2 / g * r
// Variables:
// 	e = rate of superelevation (ft/ft)
//	    values range from 0.00 to 0.12 ft/ft. (0.08 in areas w/snow and ice, such as Virginia)
// 	f = side friction factor
//	    values range from 0.17 to 0.09
// 	V = velocity (mph) (5280 ft/mi)
// 	r = radius of curve (ft)
// 	v = velocity (ft/sec)
// 	g = acceleration of gravity (32.2 ft/sec^2)
//
// Superelevation Formula #2:
// 	tan(theta) = v^2 / rg
// Variables:
// 	theta = banking angle
// 	v = car speed (ft/sec) (mph * 5280/3600 = ft/sec)
// 	r = radius of curvature (ft)
// 	g = acceleration due to gravity (32.2 ft/sec^2)


//------------------------------------------------------------------------------Things to do

// Store the tangent vectors at the beginning and end of each curve, so that roads in succession can line up flush with one another.
// The center stripes aren't evenly spaced.
// Provide a way of reversing the spiral's direction.
// The tilt angle is currently only valid if the spline turns in a counter-clockwise direction. Otherwise, the road is banked in the wrong direction (e.g. up-side-down).
// There is an odd twisting of the road surface when a spline turns at an angle greater than 90 degrees.
// The spline should accept an initial and final tilt value, as well. (Maybe.)
// Need to be able to pass information (e.g. start and ending coords, tilt angles and vectors) between splines, so that they can be smoothed together.
// I would like to base spline tension upon speed-limit.
// I would also like to have the macro automatically generate the proper speed-limit signs at the beginning and end of each curve, using the appropriate LDraw part.
// Automatic generation of structural supports, guard rails and street lamps would be splendid, as well.
// Make it so that the intersection does nt have to be perfectly flat.
// Auto-generate things like stoplights and signposts.


//------------------------------------------------------------------------------Dependencies & global variables

#include "math.inc"
#ifndef (LRoad_RoadWidth)	#declare LRoad_RoadWidth =		array[3] {280,306,360,}	#end		// The width of the road.
#ifndef (LRoad_StripeLength)	#declare LRoad_StripeLength =		array[3] {64,64,64,}	#end		// The distance between each stripe-interval.
#ifndef (LRoad_CornerRadius)	#declare LRoad_CornerRadius =		array[3] {23,36,63,}	#end		// The distance from the outer edge of the road to the inner edge of the innermost stripe, not including the center stripes.
#ifndef (LRoad_MajorArc)	#declare LRoad_MajorArc =		array[3] {52,0,10,}	#end		// The distance from the intersection that the road begins to curve.
#ifndef (LRoad_WalkDistance)	#declare LRoad_WalkDistance =		array[3] {75,75,75,}	#end		// The distance from the intersection to the center of a crosswalk.
#ifndef (LRoad_WalkWidth)	#declare LRoad_WalkWidth =		array[3] {234,234,234,}	#end		// The width of the crosswalk.
#ifndef (LRoad_WalkLength)	#declare LRoad_WalkLength =		array[3] {60,60,60,}	#end		// The width of the crosswalk.
#ifndef (LRoad_WalkStripeWidth)	#declare LRoad_WalkStripeWidth =	array[3] {25,25,25,}	#end		// The width of a crosswalk stripe.
#ifndef (LRoad_DistanceUnit)	#declare LRoad_DistanceUnit = 		10;			#end		// The unit of distance equivalent to 1 foot. Used when determining banking amount.


//------------------------------------------------------------------------------Line intersection macro

// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7
// Copyright Tor Olav Kristensen
// http://subcube.com
// ===== 1 ======= 2 ======= 3 ======= 4 ======= 5 ======= 6 ======= 7

// Projection of the vector v1 in the direction  of the vector v2.
#macro vproject(v1, v2)
	v2 * vdot(v1, v2)/vdot(v2, v2)
#end

#macro inv_vproject(v1, v2)
	v2/vdot(v2, v1) * vdot(v1, v1)
#end

// Find the two points on the lines which is closest to each other
#macro ln2ln(pLine1, vLine1, pLine2, vLine2)
	#local vPN = pLine2 - pLine1;
	#local vPQ = vPN - vproject(vPN, vcross(vLine1, vLine2));
	#local vQS = inv_vproject(vproject(vPQ, vLine1) - vPQ, vLine2);
	array[2] {pLine1 + vQS + vPQ, pLine2 + vQS,}
#end


//------------------------------------------------------------------------------Pigments, patterns and materials

#declare LRoad_RoadColor = color rgb <0.682353,0.682353,0.682353>;
#declare LRoad_EdgeColor = color rgb <0.117647,0.627451,0.227451>;
#declare LRoad_ShldColor = color rgb 1;
#declare LRoad_TrnsColor = color rgbt 1;

#macro LRoad_RoadSurface(roadTyp)
	color_map
	{
		#switch (roadTyp)
			#case (1)
				[000/280 LRoad_RoadColor]
				[007/280 LRoad_RoadColor]
				[007/280 LRoad_EdgeColor]
				[023/280 LRoad_EdgeColor]
				[023/280 LRoad_RoadColor]
				[257/280 LRoad_RoadColor]
				[257/280 LRoad_EdgeColor]
				[273/280 LRoad_EdgeColor]
				[273/280 LRoad_RoadColor]
				[280/280 LRoad_RoadColor]
			#break
			#case (2)
				[000/306 LRoad_RoadColor]
				[020/306 LRoad_RoadColor]
				[020/306 LRoad_EdgeColor]
				[036/306 LRoad_EdgeColor]
				[036/306 LRoad_RoadColor]
				[270/306 LRoad_RoadColor]
				[270/306 LRoad_EdgeColor]
				[286/306 LRoad_EdgeColor]
				[286/306 LRoad_RoadColor]
				[306/306 LRoad_RoadColor]
			#break
			#case (3)
				[000/360 LRoad_RoadColor]
				[002/360 LRoad_RoadColor]
				[002/360 LRoad_ShldColor]
				[012/360 LRoad_ShldColor]
				[012/360 LRoad_RoadColor]
				[047/360 LRoad_RoadColor]
				[047/360 LRoad_EdgeColor]
				[063/360 LRoad_EdgeColor]
				[063/360 LRoad_RoadColor]
				[297/360 LRoad_RoadColor]
				[297/360 LRoad_EdgeColor]
				[313/360 LRoad_EdgeColor]
				[313/360 LRoad_RoadColor]
				[348/360 LRoad_RoadColor]
				[348/360 LRoad_ShldColor]
				[358/360 LRoad_ShldColor]
				[358/360 LRoad_RoadColor]
				[360/360 LRoad_RoadColor]
			#break
		#end
	}
#end
#macro LRoad_StripeSurface()
	color_map
	{
/*
		[00/64 LRoad_ShldColor]
		[44/64 LRoad_ShldColor]
		[44/64 LRoad_RoadColor]
		[64/64 LRoad_RoadColor]
*/
		[00/64 LRoad_ShldColor]
		[20/64 LRoad_ShldColor]
		[20/64 LRoad_RoadColor]
		[44/64 LRoad_RoadColor]
		[44/64 LRoad_ShldColor]
		[64/64 LRoad_ShldColor]
/*
		[00/64 LRoad_RoadColor]
		[12/64 LRoad_RoadColor]
		[12/64 LRoad_ShldColor]
		[52/64 LRoad_ShldColor]
		[52/64 LRoad_RoadColor]
		[64/64 LRoad_RoadColor]
*/
	}
#end
#macro LRoad_WalkSurface()
	color_map
	{
		[00/25 LRoad_ShldColor]
		[08/25 LRoad_ShldColor]
		[08/25 LRoad_RoadColor]
		[17/25 LRoad_RoadColor]
		[17/25 LRoad_ShldColor]
		[25/25 LRoad_ShldColor]
	}
#end
#macro LRoad_CornerSurface(roadTyp,prevRadius)
	color_map
	{
		#switch (roadTyp)
			#case (1)
				[0 LRoad_TrnsColor]
				[(000+prevRadius)/(280+prevRadius*2) LRoad_TrnsColor]
				[(000+prevRadius)/(280+prevRadius*2) LRoad_RoadColor]
				[(007+prevRadius)/(280+prevRadius*2) LRoad_RoadColor]
				[(007+prevRadius)/(280+prevRadius*2) LRoad_EdgeColor]
				[(023+prevRadius)/(280+prevRadius*2) LRoad_EdgeColor]
				[(023+prevRadius)/(280+prevRadius*2) LRoad_RoadColor]
				[(257+prevRadius)/(280+prevRadius*2) LRoad_RoadColor]
				[(257+prevRadius)/(280+prevRadius*2) LRoad_EdgeColor]
				[(273+prevRadius)/(280+prevRadius*2) LRoad_EdgeColor]
				[(273+prevRadius)/(280+prevRadius*2) LRoad_RoadColor]
				[(280+prevRadius)/(280+prevRadius*2) LRoad_RoadColor]
				[(280+prevRadius)/(280+prevRadius*2) LRoad_TrnsColor]
				[1 LRoad_TrnsColor]
			#break
			#case (2)
				[0 LRoad_TrnsColor]
				[(000+prevRadius)/(306+prevRadius*2) LRoad_TrnsColor]
				[(000+prevRadius)/(306+prevRadius*2) LRoad_RoadColor]
				[(020+prevRadius)/(306+prevRadius*2) LRoad_RoadColor]
				[(020+prevRadius)/(306+prevRadius*2) LRoad_EdgeColor]
				[(036+prevRadius)/(306+prevRadius*2) LRoad_EdgeColor]
				[(036+prevRadius)/(306+prevRadius*2) LRoad_RoadColor]
				[(270+prevRadius)/(306+prevRadius*2) LRoad_RoadColor]
				[(270+prevRadius)/(306+prevRadius*2) LRoad_EdgeColor]
				[(286+prevRadius)/(306+prevRadius*2) LRoad_EdgeColor]
				[(286+prevRadius)/(306+prevRadius*2) LRoad_RoadColor]
				[(306+prevRadius)/(306+prevRadius*2) LRoad_RoadColor]
				[(306+prevRadius)/(306+prevRadius*2) LRoad_TrnsColor]
				[1 LRoad_TrnsColor]
			#break
			#case (3)
				[0 LRoad_TrnsColor]
				[(000+prevRadius)/(360+prevRadius*2) LRoad_TrnsColor]
				[(000+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(002+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(002+prevRadius)/(360+prevRadius*2) LRoad_ShldColor]
				[(012+prevRadius)/(360+prevRadius*2) LRoad_ShldColor]
				[(012+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(047+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(047+prevRadius)/(360+prevRadius*2) LRoad_EdgeColor]
				[(063+prevRadius)/(360+prevRadius*2) LRoad_EdgeColor]
				[(063+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(297+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(297+prevRadius)/(360+prevRadius*2) LRoad_EdgeColor]
				[(313+prevRadius)/(360+prevRadius*2) LRoad_EdgeColor]
				[(313+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(348+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(348+prevRadius)/(360+prevRadius*2) LRoad_ShldColor]
				[(358+prevRadius)/(360+prevRadius*2) LRoad_ShldColor]
				[(358+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(360+prevRadius)/(360+prevRadius*2) LRoad_RoadColor]
				[(360+prevRadius)/(360+prevRadius*2) LRoad_TrnsColor]
				[1 LRoad_TrnsColor]
			#break
		#end
	}
#end
#macro LRoad_EdgeSurface1()
	color_map
	{
		[000/280 LRoad_TrnsColor]
		[257/280 LRoad_TrnsColor]
		[257/280 LRoad_EdgeColor]
		[273/280 LRoad_EdgeColor]
		[273/280 LRoad_RoadColor]
		[280/280 LRoad_RoadColor]
	}
#end
#macro LRoad_EdgeSurface2()
	color_map
	{
		[000/280 LRoad_RoadColor]
		[007/280 LRoad_RoadColor]
		[007/280 LRoad_EdgeColor]
		[023/280 LRoad_EdgeColor]
		[023/280 LRoad_TrnsColor]
		[280/280 LRoad_TrnsColor]
	}
#end
#macro LRoad_RoadMap(roadTyp,RoadSurface,StripeSurface)
	pigment_map
	{
		#switch (roadTyp)
			#case (1)
				[000/280 RoadSurface]
				[134/280 RoadSurface]
				[134/280 StripeSurface]
				[146/280 StripeSurface]
				[146/280 RoadSurface]
				[280/280 RoadSurface]
			#break
			#case (2)
				[000/306 RoadSurface]
				[147/306 RoadSurface]
				[147/306 StripeSurface]
				[159/306 StripeSurface]
				[159/306 RoadSurface]
				[306/306 RoadSurface]
			#break
			#case (3)
				[000/360 RoadSurface]
				[174/360 RoadSurface]
				[174/360 StripeSurface]
				[186/360 StripeSurface]
				[186/360 RoadSurface]
				[360/360 RoadSurface]
			#break
		#end
	}
#end
#macro LRoad_RoadMaterial()
	#local QUAL = 3;	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo
	#local SW = 0.5;	// Width of seam between two bricks
	#local STUDS = 1;	// 1=on 0=off
	#local BUMPS = 1;	// 1=on 0=off
	#local BUMPNORMAL = normal { bumps 0.01 scale 20 }
	#local AMB = 0.4;
	#local DIF = 0.4;
	#if (version >= 3.1) material { #end
		texture
		{
			finish { ambient AMB diffuse DIF }
			#if (QUAL > 1)
				finish { phong 0.5 phong_size 40 reflection 0.08 }
				#if (BUMPS) normal { BUMPNORMAL } #end
			#end
		}
	#if (version >= 3.1) } #end
#end


//------------------------------------------------------------------------------Shape formula macros

#macro LRoad_Pos_Straight(V,O,sB,sN)
	#local perc = sB/sN;
	V*perc+O
#end
#macro LRoad_Pos_Ellipse(A,I,sB,sN)
	#local step = 2*pi*sB/sN;
	<cos(step)*A,0,sin(step)*I,>
#end
#macro LRoad_Pos_Nautilus(H,A,R,T1,T2,sB,sN)
	#local perc = sB/sN*(T2-T1)+T1;
	#local step = 2*pi*perc;
	<R*exp(step/tan(A))*cos(step),H*perc,R*exp(step/tan(A))*sin(step),>
#end
#macro LRoad_Pos_Archimedes(H,R,T1,T2,sB,sN)
	#local perc = sB/sN*(T2-T1)+T1;
	#local step = 2*pi*perc;
	<R*cos(step)*perc,H*perc,R*sin(step)*perc,>
#end
#macro LRoad_Pos_Spline(O1,V1,O2,V2,sB,sN)
	#local perc = sB/sN;
	#local h1 = 2*pow(perc,3)-3*pow(perc,2)+1;
	#local h2 = -2*pow(perc,3)+3*pow(perc,2);
	#local h3 = pow(perc,3)-2*pow(perc,2)+perc;
	#local h4 = pow(perc,3)-pow(perc,2);
	O1*h1+O2*h2+V1*h3+V2*h4
#end


//------------------------------------------------------------------------------Flat intersection macro

#macro LRoad_Intersection_Macro
	(
		intersectCoords,		// Array of vectors signifying the directions of the intersecting roads.	(array)
		roadTyp,			// Type of road. "9-Stud" is 1, "8-Stud" is 2 and "7-Stud" is 3.		(integer)
		debgBoo,			// Enables/disables debug information.						(boolian)
	)

	//------------------------------------------------------------------------------Variables

	#local roadNum = dimension_size(intersectCoords,1);			// The number of roads that will intersect at the origin.
	#local RoadWidth =		LRoad_RoadWidth[roadTyp-1];		// The width of the road.
	#local StripeLength =		LRoad_StripeLength[roadTyp-1];		// The distance between each stripe-interval.
	#local CornerRadius =		LRoad_CornerRadius[roadTyp-1];		// The distance from the outer edge of the road to the inner edge of the innermost stripe, not including the center stripes.
	#local MajorArc =		LRoad_MajorArc[roadTyp-1];		// The distance from the intersection that the road begins to curve.
	#local WalkDist =		LRoad_WalkDistance[roadTyp-1];		// The distance from the intersection to the center of a crosswalk.
	#local WalkWidth =		LRoad_WalkWidth[roadTyp-1];		// The width of the crosswalk.
	#local WalkLength =		LRoad_WalkLength[roadTyp-1];		// The width of the crosswalk.
	#local WalkStripeWidth =	LRoad_WalkStripeWidth[roadTyp-1];	// The width of a crosswalk stripe.


	//------------------------------------------------------------------------------Initial masks & objects

	#local circle_mask = cylinder {y, -y, RoadWidth/2}
	#local plane_mask = intersection
	{
		plane {y, 0}
		plane {-y, 0}
	}


	//------------------------------------------------------------------------------Intersection generation

	union
	{
		intersection
		{
			object {circle_mask}
			object {plane_mask}
			pigment {color LRoad_RoadColor}
		}

		#local roadNow = 0;
		#while (roadNow < roadNum)

			#local roadPrv = roadNow - 1;
			#if (roadPrv < 0)
				#local roadPrv = roadNum - 1;
			#end
			#local roadNxt = roadNow + 1;
			#if (roadNxt = roadNum)
				#local roadNxt = 0;
			#end

			#local thisStart = intersectCoords[roadNow];
			#local prevStart = intersectCoords[roadPrv];
			#local nextStart = intersectCoords[roadNxt];

			#local thisTangent = vnormalize(thisStart);
			#local prevTangent = vnormalize(prevStart);
			#local nextTangent = vnormalize(nextStart);

			#local thisPlane = vnormalize(vcross(thisTangent, y));
			#local prevPlane = vnormalize(vcross(prevTangent, y));
			#local nextPlane = vnormalize(vcross(nextTangent, y));

			#local temparray = ln2ln(thisStart - thisPlane * RoadWidth/2, thisTangent, prevStart + prevPlane * RoadWidth/2, prevTangent);
			#local prevIntersect = temparray[0];
			#local prevTest = 0;
			#if (prevIntersect.x > pow(10, 50))
				#local prevIntersect = <0,0,0> - thisPlane*RoadWidth/2;
				#local prevTest = 1;
			#end
			#local temparray = ln2ln(thisStart + thisPlane * RoadWidth/2, thisTangent, nextStart - nextPlane * RoadWidth/2, nextTangent);
			#local nextIntersect = temparray[0];
			#local nextTest = 0;
			#if (nextIntersect.x > pow(10, 50))
					#local nextIntersect =  <0,0,0> + thisPlane * RoadWidth/2;
				#local nextTest = 1;
			#end

			#local prevDistance = VDist(thisStart - thisPlane * RoadWidth/2, prevIntersect);
			#local nextDistance = VDist(thisStart + thisPlane * RoadWidth/2, nextIntersect);
			#local miniDistance = min(prevDistance, nextDistance);

			#if (miniDistance = prevDistance)
				#local miniIntersect = prevIntersect;
				#local miniCase = 1;
				#local oppoPlane = prevPlane;
				#local oppoTangent = prevTangent;
				#local oppoPlane = prevPlane;
				#local othrIntersect = nextIntersect;
			#else
				#local miniIntersect = nextIntersect;
				#local miniCase = -1;
				#local oppoPlane = nextPlane;
				#local oppoTangent = nextTangent;
				#local oppoPlane = nextPlane;
				#local othrIntersect = prevIntersect;
			#end

			#local thisPrvBevel = prevIntersect + MajorArc * thisTangent;
			#local prevThsBevel = prevIntersect + MajorArc * prevTangent;
			#local temparray = ln2ln(thisPrvBevel, thisPlane, prevThsBevel, prevPlane);
			#local prevPivot = temparray[0];
			#local prevRadius = VDist(thisPrvBevel, prevPivot);

			#local maskCorner1 = prevIntersect + CornerRadius * thisPlane + MajorArc * thisTangent;
			#local maskCorner2 = prevIntersect - CornerRadius * prevPlane + MajorArc * prevTangent;
			#local temparray = ln2ln(maskCorner1, thisTangent, maskCorner2, prevTangent);
			#local maskCorner3 = temparray[0];

			#local miniSmll = miniIntersect + miniCase * (RoadWidth - CornerRadius/2) * thisPlane + MajorArc * thisTangent;
			#local othrSmll = othrIntersect - miniCase * (CornerRadius/2) * thisPlane + MajorArc * thisTangent;

			#if (prevTest = 1)
//				#local miniSmll = miniIntersect + miniCase * (RoadWidth - CornerRadius/2) * thisPlane;
				#local othrSmll = othrIntersect - miniCase * (CornerRadius/2)*thisPlane - MajorArc * thisTangent;
			#end
			#if (nextTest = 1)
//				#local miniSmll = miniIntersect + miniCase * (RoadWidth - CornerRadius/2) * thisPlane;
				#local othrSmll = othrIntersect - miniCase * (CornerRadius/2)*thisPlane - MajorArc * thisTangent;
			#end

			#local diagStop = othrIntersect + miniCase * thisPlane * RoadWidth/2 + MajorArc * thisTangent;
			#local othrStop = othrIntersect - miniCase * thisPlane * RoadWidth/2 + MajorArc * thisTangent;
			#local oppoStop = miniIntersect - miniCase * oppoPlane * RoadWidth/2 + MajorArc * oppoTangent;
			#local thisStop = miniIntersect + miniCase * thisPlane * RoadWidth/2 + MajorArc * thisTangent;

			#if (prevTest = 1)
				#local othrStop = othrIntersect - miniCase * thisPlane * RoadWidth/2 - MajorArc * thisTangent;
			#end
			#if (nextTest = 1)
				#local othrStop = othrIntersect - miniCase * thisPlane * RoadWidth/2 - MajorArc * thisTangent;
				#if (prevTest = 1)
					#local thisStop = miniIntersect + miniCase * thisPlane * RoadWidth/2;
				#end
			#end

			#local thisToGo = thisStart - thisStop;

			#local walkEndpt1 = thisStop + (WalkDist - CornerRadius - MajorArc) * thisTangent + WalkWidth * thisPlane/2;
			#local walkEndpt2 = thisStop + (WalkDist - CornerRadius - MajorArc) * thisTangent - WalkWidth * thisPlane/2;
			#local walkEndpt3 = othrStop + (WalkDist - CornerRadius - MajorArc) * thisTangent + WalkWidth * thisPlane/2;
			#local walkEndpt4 = othrStop + (WalkDist - CornerRadius - MajorArc) * thisTangent - WalkWidth * thisPlane/2;


			//----------------------------------------------------------------------------Pigments
	
			#local StripeSurface = pigment
			{
				gradient thisTangent
				LRoad_StripeSurface()
				scale StripeLength/RoadWidth
			}
			#local RoadSurface = pigment
			{
				gradient thisPlane
				LRoad_RoadSurface(roadTyp)
			}
			#local ThisEdgeSurface = pigment
			{
				gradient -thisPlane
				LRoad_EdgeSurface1()
			}
			#local PrevEdgeSurface = pigment
			{
				gradient -prevPlane
				LRoad_EdgeSurface2()
			}
			#local CornerSurface = pigment
			{
				cylindrical
				LRoad_CornerSurface(roadTyp,prevRadius)
			}
			#local WalkSurface = pigment
			{
				gradient thisPlane
				LRoad_WalkSurface()
			}


			//----------------------------------------------------------------------------Masks

			#local road1_mask = cylinder {thisStart, <0,0,0>, WalkWidth/2}
			#local road2_mask = cylinder {prevStart, <0,0,0>, WalkWidth/2}
			#local road3_mask = cylinder {nextStart, <0,0,0>, WalkWidth/2}
			#local road4_mask = cylinder
			{
				#if (VDist(miniSmll, othrSmll) != 0)
					miniSmll, othrSmll, CornerRadius/2
				#else
					y, -y, 1
				#end
			}
			#local corner_mask = cylinder {<prevPivot.x, -100, prevPivot.z>, <prevPivot.x, 100, prevPivot.z>, prevRadius}
			#local crosswalk1_mask = cylinder {walkEndpt1, walkEndpt2, WalkLength/2}
			#local crosswalk2_mask = cylinder {walkEndpt3, walkEndpt4, WalkLength/2}


			//----------------------------------------------------------------------------Objects

			// crosswalks
			intersection
			{
				object {crosswalk1_mask}
				object {plane_mask}
				pigment {WalkSurface scale WalkStripeWidth}
			}

			// phantom crosswalks
			intersection
			{
				object {crosswalk2_mask}
				object {plane_mask}
				pigment {color LRoad_RoadColor}
				clipped_by
				{
					object {crosswalk1_mask inverse}
				}
//no_image
			}

			// large road sections
			intersection
			{
				cylinder {thisStop, thisStart, RoadWidth/2}
				object {plane_mask}
				pigment
				{
					gradient thisPlane
					LRoad_RoadMap(roadTyp,RoadSurface,StripeSurface)
					scale RoadWidth
					translate thisPlane*RoadWidth/2
					translate thisStop
					translate thisTangent*(WalkDist-CornerRadius-MajorArc)
					#if (roadTyp = 2)
						translate thisTangent*CornerRadius
					#end
				}
				clipped_by
				{
					object {crosswalk1_mask inverse}
					object {crosswalk2_mask inverse}
				}
			}

			// middle road sections
			#if (VDist(thisStop, <0,0,0>) != 0)
				intersection
				{
					cylinder {thisStop, <0,0,0>, WalkWidth/2}
					object {plane_mask}
					pigment
					{
						RoadSurface
						scale RoadWidth
						translate thisPlane*RoadWidth/2
					}
					clipped_by
					{
						object {crosswalk1_mask inverse}
						object {crosswalk2_mask inverse}
						object {circle_mask inverse}
					}
				}
			#end

			// longer edge road sections
			#if (VDist(miniSmll, othrSmll) != 0)
				intersection
				{
					object {road4_mask}
					object {plane_mask}
					pigment
					{
						RoadSurface
						scale RoadWidth
						translate thisPlane*RoadWidth/2
					}
				}
			#end

			// corners
			#if (prevTest = 0)
				#if (nextTest = 0)
					intersection
					{
						prism
						{
							linear_spline -100, 100, 4
							<prevPivot.x, prevPivot.z>, <maskCorner1.x, maskCorner1.z>, <maskCorner3.x, maskCorner3.z>, <maskCorner2.x, maskCorner2.z>
						}
						object {plane_mask}
						pigment
						{
							#if (roadTyp = 1)
								#local CornerLength = VDist(prevPivot, maskCorner3);
		
								gradient thisTangent - prevTangent
								pigment_map
								{
									[0 ThisEdgeSurface scale RoadWidth/CornerLength]
									[0.5 ThisEdgeSurface scale RoadWidth/CornerLength]
									[0.5 PrevEdgeSurface scale RoadWidth/CornerLength]
									[1 PrevEdgeSurface scale RoadWidth/CornerLength]
								}
								scale CornerLength
								translate prevIntersect
							#else
								CornerSurface
								scale RoadWidth+prevRadius*2
								translate prevPivot
							#end
						}
						clipped_by
						{
							object {crosswalk1_mask inverse}
							object {crosswalk2_mask inverse}
							object {road1_mask inverse}
							object {road2_mask inverse}
							object {road3_mask inverse}
							object {road4_mask inverse}
						}
					}
				#end
			#end


			//----------------------------------------------------------------------------Debug

			#if (debgBoo = 1)
				#local Pigment_Red = pigment {color rgb <roadNow/roadNum,0,0>}
				#local Pigment_Green = pigment {color rgb <0,roadNow/roadNum,0>}
				sphere {thisStop, 10 pigment {Pigment_Red}}
				sphere {othrStop, 10 pigment {Pigment_Red}}
				sphere {prevPivot, 10 pigment {Pigment_Green}}
				sphere {0, 10 pigment {Pigment_Green}}

				#debug concat("\nRoad #", str(roadNow, 0, 0), ": prevRadius = ", str(prevRadius, 0, -1))
				#debug concat("\nRoad #", str(roadNow, 0, 0), ": prevPivot = <", vstr(3, prevPivot, ", ", 0, -1), ">")
			#end

			#local roadNow = roadNow + 1;
		#end


		//------------------------------------------------------------------------------Materials
	
		LRoad_RoadMaterial()
	}
#end


//------------------------------------------------------------------------------Shaped road macro

#macro LRoad_Road_Macro
	(
		degrBeg,			// Starting tilt (bank) angle. Only applies if superelevation is disabled.	(float)
		degrEnd,			// Ending tilt (bank) angle. Only applies if superelevation is disabled.	(float)
						// Tilt angles are interpolated linearly from beginning to end.
		roadShp,			// The road's shape. 1 is straight, 2 is ellipse, 3 is spiral and 4 is spline (hermite).	(integer)
		roadPrm,			// The shape-specific parameters.						(array)
		stepNum,			// The total number of possible steps.						(integer)
		stepBeg,			// The step to begin rendering with.						(integer)
		stepEnd,			// The step to end rendering with.						(integer)
		banking,			// Enable calculation of superelevation (road banking)?				(bool)
		spLimit,			// Speed limit. Only applies if superelevation is enabled.			(mph)
		roadTyp,			// Type of road. "9-Stud" is 1 and "7-Stud" is 2.				(integer)
		debgBoo,			// Enables/disables debug information.						(boolian)
	)

	//------------------------------------------------------------------------------Variables

	#switch (roadShp)
		#case (1)						// Straight
			#local origPnt = roadPrm[0];			// Starting point.									(vector)
			#local destPnt = roadPrm[1];			// Ending point.									(vector)
			#local vectPnt = destPnt - origPnt;
		#break
		#case (2)						// Ellipse
			#local majAxis = roadPrm[0];			// The length of the ellipse's semi-major axis.
			#local minAxis = roadPrm[1];			// The length of the ellipse's semi-minor axis.
		#break
		#case (3)						// Nautilus spiral
			#local Radius = roadPrm[0];			// The radius of the spiral at step #0.							(float)
			#local Height = roadPrm[1]; 			// The height of the spiral. Generates a 'corkscrew' if set to equal more than zero.	(integer)
			#local Angle = radians(roadPrm[2]);		// The angle at which the path of the spiral deviates from its previous vector.		(float, degrees)
									// Valid values range between 0 and 180 degrees. If 90 degrees, then a circle is generated.
									// A value of 0 (zero) causes POV-Ray to crash.
			#local TStart = roadPrm[2];			// The starting "t" value. Typically equal to zero.					(float, typically between 0 and 1)
			#local TEnd = roadPrm[3];			// The ending "t" value. Typically equal to one.					(float, typically between 0 and 1)
		#break
		#case (4)						// Archimedes spiral
			#local Radius = roadPrm[0];			// The radius of the spiral at step #0.							(float)
			#local Height = roadPrm[1]; 			// The height of the spiral. Generates a 'corkscrew' if set to equal more than zero.	(integer)
			#local TStart = roadPrm[2];			// The starting "t" value. Typically equal to zero.					(float, typically between 0 and 1)
			#local TEnd = roadPrm[3];			// The ending "t" value. Typically equal to one.					(float, typically between 0 and 1)
		#break
		#case (5)						// Hermite spline
			#local EndPoint1 = roadPrm[0];			// EndPoint1: Point at beginning of spline.						(vector)
			#local TangentPoint1 = roadPrm[1];		// TangentPoint1: Point that the spline points toward at EndPoint1.			(vector)
			#local EndPoint2 = roadPrm[2];    		// EndPoint2: Point at end of spline.							(vector)
			#local TangentPoint2 = roadPrm[3];		// TangentPoint2: Point that the spline points toward at EndPoint2.			(vector)
			#local TangentVector1 = TangentPoint1 - EndPoint1;
			#local TangentVector2 = TangentPoint2 - EndPoint2;
		#break
	#end

	#local maxAngle = 0;
	#local maxAStep = 0;
	#local avgSpeed = f_sqr(spLimit*5280/3600/LRoad_DistanceUnit);
	#local RoadWidth = LRoad_RoadWidth[roadTyp-1];			// The width of the road.
	#local StripeLength = LRoad_StripeLength[roadTyp-1];		// The distance between each stripe-interval.

	mesh
	{
		#while (stepBeg < stepEnd)

			#if (debgBoo = 1)
				#debug concat("sStep = ", str(stepBeg, 0, 0), "\n")
			#end


			//------------------------------------------------------------------------------Curve parameters

			#switch (roadShp)
				#case (1)
					#local pppPos =		LRoad_Pos_Straight(vectPnt,origPnt,stepBeg-3,stepNum);
					#local ppPos =		LRoad_Pos_Straight(vectPnt,origPnt,stepBeg-2,stepNum);
					#local pPos =		LRoad_Pos_Straight(vectPnt,origPnt,stepBeg-1,stepNum);
					#local sPos =		LRoad_Pos_Straight(vectPnt,origPnt,stepBeg-0,stepNum);
					#local nPos =		LRoad_Pos_Straight(vectPnt,origPnt,stepBeg+1,stepNum);
					#local nnPos =		LRoad_Pos_Straight(vectPnt,origPnt,stepBeg+2,stepNum);
					#local nnnPos =		LRoad_Pos_Straight(vectPnt,origPnt,stepBeg+3,stepNum);
					#local nnnnPos =	LRoad_Pos_Straight(vectPnt,origPnt,stepBeg+4,stepNum);
				#break
				#case (2)
					#local pppPos =		LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg-3,stepNum);
					#local ppPos =		LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg-2,stepNum);
					#local pPos =		LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg-1,stepNum);
					#local sPos =		LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg-0,stepNum);
					#local nPos =		LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg+1,stepNum);
					#local nnPos =		LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg+2,stepNum);
					#local nnnPos =		LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg+3,stepNum);
					#local nnnnPos =	LRoad_Pos_Ellipse(majAxis,minAxis,stepBeg+4,stepNum);
				#break
				#case (3)
					#local pppPos =		LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg-3,stepNum);
					#local ppPos =		LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg-2,stepNum);
					#local pPos =		LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg-1,stepNum);
					#local sPos =		LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg-0,stepNum);
					#local nPos =		LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg+1,stepNum);
					#local nnPos =		LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg+2,stepNum);
					#local nnnPos =		LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg+3,stepNum);
					#local nnnnPos =	LRoad_Pos_Nautilus(Height,Angle,Radius,TStart,TEnd,stepBeg+4,stepNum);
				#break
				#case (4)
					#local pppPos =		LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg-3,stepNum);
					#local ppPos =		LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg-2,stepNum);
					#local pPos =		LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg-1,stepNum);
					#local sPos =		LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg-0,stepNum);
					#local nPos =		LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg+1,stepNum);
					#local nnPos =		LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg+2,stepNum);
					#local nnnPos =		LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg+3,stepNum);
					#local nnnnPos =	LRoad_Pos_Archimedes(Height,Radius,TStart,TEnd,stepBeg+4,stepNum);
				#break
				#case (5)
					#local pppPos =		LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg-3,stepNum);
					#local ppPos =		LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg-2,stepNum);
					#local pPos =		LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg-1,stepNum);
					#local sPos =		LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg-0,stepNum);
					#local nPos =		LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg+1,stepNum);
					#local nnPos =		LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg+2,stepNum);
					#local nnnPos =		LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg+3,stepNum);
					#local nnnnPos =	LRoad_Pos_Spline(EndPoint1,TangentVector1,EndPoint2,TangentVector2,stepBeg+4,stepNum);
				#break
			#end

			#local ppTangent = pPos - pppPos;
			#local pTangent = sPos - ppPos;
			#local sTangent = nPos - pPos;
			#local nTangent = nnPos - sPos;
			#local nnTangent = nnnPos - nPos;
			#local nnnTangent = nnnnPos - nnPos;

			#local ppPlane = vnormalize(vcross(ppTangent, y)) * RoadWidth / 2;
			#local pPlane = vnormalize(vcross(pTangent, y)) * RoadWidth / 2;
			#local sPlane = vnormalize(vcross(sTangent, y)) * RoadWidth / 2;
			#local nPlane = vnormalize(vcross(nTangent, y)) * RoadWidth / 2;
			#local nnPlane = vnormalize(vcross(nnTangent, y)) * RoadWidth / 2;
			#local nnnPlane = vnormalize(vcross(nnnTangent, y)) * RoadWidth / 2;

			#local pAngle = degrBeg - (degrBeg-degrEnd)*(stepBeg-1)/stepNum;
			#local sAngle = degrBeg - (degrBeg-degrEnd)*(stepBeg)/stepNum;
			#local nAngle = degrBeg - (degrBeg-degrEnd)*(stepBeg+1)/stepNum;
			#local nnAngle = degrBeg - (degrBeg-degrEnd)*(stepBeg+2)/stepNum;

			#local pTilt = vaxis_rotate(pPlane, pTangent, pAngle);
			#local sTilt = vaxis_rotate(sPlane, sTangent, sAngle);
			#local nTilt = vaxis_rotate(nPlane, nTangent, nAngle);
			#local nnTilt = vaxis_rotate(nnPlane, nnTangent, nnAngle);

			//------------------------------------------------------------------------------Superelevation calculations

			#if (roadShp != 1)
				#if (banking = yes)
					#local temparray = ln2ln(<ppPos.x,0,ppPos.z>, <ppPlane.x,0,ppPlane.z>, <  pPos.x,0,  pPos.z>, <  pPlane.x,0,   pPlane.z>);
					#local p_ppIntersect = temparray[0];
					#local temparray = ln2ln(< sPos.x,0, sPos.z>, < sPlane.x,0, sPlane.z>, <  pPos.x,0,  pPos.z>, <  pPlane.x,0,   pPlane.z>);
					#local s_pIntersect = temparray[0];
					#local temparray = ln2ln(< sPos.x,0, sPos.z>, < sPlane.x,0, sPlane.z>, <  nPos.x,0,  nPos.z>, <  nPlane.x,0,   nPlane.z>);
					#local s_nIntersect = temparray[0];
					#local temparray = ln2ln(<nnPos.x,0,nnPos.z>, <nnPlane.x,0,nnPlane.z>, <  nPos.x,0,  nPos.z>, <  nPlane.x,0,   nPlane.z>);
					#local n_nnIntersect = temparray[0];
					#local temparray = ln2ln(<nnPos.x,0,nnPos.z>, <nnPlane.x,0,nnPlane.z>, <nnnPos.x,0,nnnPos.z>, <nnnPlane.x,0, nnnPlane.z>);
					#local nn_nnnIntersect = temparray[0];

					#local pAvgIntersect = (s_pIntersect + p_ppIntersect) / 2;
					#local sAvgIntersect = (s_pIntersect + s_nIntersect) / 2;
					#local nAvgIntersect = (n_nnIntersect + s_nIntersect) / 2;
					#local nnAvgIntersect = (n_nnIntersect + nn_nnnIntersect) / 2;

					#local pRadius = VDist(pPos, pAvgIntersect) / 20;
					#local sRadius = VDist(sPos, sAvgIntersect) / 20;
					#local nRadius = VDist(nPos, nAvgIntersect) / 20;
					#local nnRadius = VDist(nnPos, nnAvgIntersect) / 20;

					#local pAngle = degrees(atan2(avgSpeed / (pRadius * 32.2), 1));
					#local sAngle = degrees(atan2(avgSpeed / (sRadius * 32.2), 1));
					#local nAngle = degrees(atan2(avgSpeed / (nRadius * 32.2), 1));
					#local nnAngle = degrees(atan2(avgSpeed / (nnRadius * 32.2), 1));

					#local pTilt = vaxis_rotate(pPlane, pTangent, pAngle);
					#local sTilt = vaxis_rotate(sPlane, sTangent, sAngle);
					#local nTilt = vaxis_rotate(nPlane, nTangent, nAngle);
					#local nnTilt = vaxis_rotate(nnPlane, nnTangent, nnAngle);

					#if (debgBoo = 1)
						#debug concat("sAngle = ", str(sAngle, 0,-1), "\n")
						#if (abs(sAngle) > maxAngle)
							#local maxAngle = sAngle;
							#local maxAStep = stepBeg;
						#end
					#end
				#end

			#end


			//------------------------------------------------------------------------------Triangle parameters

			#local sLeft = sPos + sTilt;
			#local sRight = sPos - sTilt;
			#local nLeft = nPos + nTilt;
			#local nRight = nPos - nTilt;

			#local sLeftNorm = vnormalize((vcross(sTangent, sTilt) + vcross(pTangent, sTilt) + vcross(pTangent, pTilt))/3);
			#local sRightNorm = vnormalize((vcross(pTangent, sTilt) + vcross(sTangent, sTilt) + vcross(sTangent, nTilt))/3);
			#local nLeftNorm = vnormalize((vcross(sTangent, nTilt) + vcross(sTangent, sTilt) + vcross(nTangent, nTilt))/3);
			#local nRightNorm = vnormalize((vcross(sTangent, nTilt) + vcross(nTangent, nTilt) + vcross(nTangent, nnTilt))/3);

			#local stepBeg = stepBeg + 1;
	

			//----------------------------------------------------------------------------Pigments
	
			#local StripeSurface = pigment
			{
				gradient (nPos - sPos)
				LRoad_StripeSurface()
				scale StripeLength/RoadWidth
			}
			#local RoadSurface = pigment
			{
				gradient (nTilt + sTilt)
				LRoad_RoadSurface(roadTyp)
			}
			#local TriangleTexture = texture
			{
				pigment
				{
					gradient (nTilt + sTilt)
					LRoad_RoadMap(roadTyp,RoadSurface,StripeSurface)
					scale RoadWidth
					translate nPos
					translate nTilt
				}
			}


			//----------------------------------------------------------------------------Triangles
	
			smooth_triangle {sLeft, sLeftNorm, nLeft, nLeftNorm, sRight, sRightNorm texture {TriangleTexture}}
			smooth_triangle {sRight, sRightNorm, nRight, nRightNorm, nLeft, nLeftNorm texture {TriangleTexture}}


			//------------------------------------------------------------------------------Interior marker objects
/*
			#if (debgBoo = 1)

				// The step number written, in red, at each step.
				text
				{
					ttf "timrom.ttf" concat(str(stepBeg - 1, 0, 0)) 1, 0
					pigment { color rgb <1,0,0> }
					scale <40,40,1>
					rotate <0,180,0>
					translate sPos
				}
			#end
*/
		#end

	
		//------------------------------------------------------------------------------Materials
	
		LRoad_RoadMaterial()
	}

	#if (debgBoo = 1)
		#debug concat("\nMaximum banking angle = +/- ", str(maxAngle, 0, -1), " at Step #", str(maxAStep, 0, 0), ".\n\n")
	#end
#end
