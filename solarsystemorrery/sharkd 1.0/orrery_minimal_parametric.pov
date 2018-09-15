// Caption: Orrery
// Version: 1.0
// Authors: Michael Horvath
// Website: http://isometricland.net
// Created: 2018-09-13
// Updated: 2018-09-13
// This file is licensed under the terms of the CC-LGPL.
// http://www.gnu.org/licenses/lgpl-2.1.html

#include "math.inc"
#include "transforms.inc"
#include "meshmaker.inc"

#declare PlanetsNumber		= 8;
#declare StartDate			= 2455376.5;			// days
#declare DateRange			= 5000;					// days
#declare Today				= StartDate + clock * DateRange;	// days
#declare ReferenceDate		= 2455376.5;			// days
#declare SunRadius			= 696000;				// km
#declare AU					= 149597870.691;		// km
#declare EccentricityMulti	= 1;
#declare InclinationMulti	= 1;
#declare MeanRadiusMulti	= 1000;
#declare MultiSunRadius		= SunRadius / AU * MeanRadiusMulti / 100;		// km
#declare Hidden				= true;
#declare Constructs			= true;

#declare PlanetName					= array[PlanetsNumber]	{"Mercury",			"Venus",				"Earth",				"Mars",				"Jupiter",			"Saturn",			"Uranus",			"Neptune"}				// string
#declare MeanRadius					= array[PlanetsNumber]	{2439.00000000000,	6051.80000000000,		6371.00000000000,		3389.90000000000,	69911.0000000000,	58232.0000000000,	25362.0000000000,	24624.0000000000}		// km
#declare Eccentricity				= array[PlanetsNumber]	{0.205620000000000,	0.00681000000000001,	0.0174500000000000,		0.0933100000000001,	0.0487700172393226,	0.0543567124395717,	0.0474181287155161,	0.00867613156526848}	// 0..1
#declare PeriapsisDistance			= array[PlanetsNumber]	{0.307500000000000,	0.718400000000001,		0.981800000000001,		1.38155607491481,	4.94428800019439,	9.02556880140891,	18.2765360029404,	29.8027416187573}		// AU
#declare Inclination				= array[PlanetsNumber]	{7.00437000000001,	3.39449000000000,		0.00265000000000000,	1.84890000000000,	1.30471529390000,	2.48627960990000,	0.772208056400001,	1.77363184250000}		// deg
#declare LongitudeOfAscendingNode	= array[PlanetsNumber]	{48.3175000000001,	76.6503600000001,		125.106850000000,		49.5243100000001,	100.512620913600,	113.580108269500,	73.9887836759001,	131.812865345800}		// deg
#declare ArgumentOfPerifocus		= array[PlanetsNumber]	{29.1531600000000,	54.8862100000001,		338.168880000000,		286.588600000000,	273.863659279900,	339.012583100900,	97.0984503626001,	274.763059227300}		// deg
#declare TimeOfPeriapsis			= array[PlanetsNumber]	{2455372.93755000,	2455333.42831000,		2455200.63690000,		2455630.00590000,	2455636.98729551,	2452815.05701155,	2470111.02681989,	2468542.30107738}		// Julian Date
#declare MeanMotion					= array[PlanetsNumber]	{4.09235000000000,	1.60214000000000,		0.986730000000001,		0.524010000000001,	0.0831087186000001,	0.0334340072000000,	0.0117349026000000,	0.00598274880000001}	// deg/day
#declare MeanAnomaly				= array[PlanetsNumber]	{14.5787800000000,	69.0069800000001,		173.530063432941,		227.160840000000,	338.351234669700,	85.6393031936001,	187.091762213400,	281.232319787200}		// deg
#declare TrueAnomaly				= array[PlanetsNumber]	{22.4135700000000,	69.7378700000001,		173.750630000000,		219.916960000000,	336.166514350700,	91.8700282165001,	186.458277094000,	280.255135189300}		// deg
#declare SemiMajorAxis				= array[PlanetsNumber]	{0.387100000000000,	0.723330000000001,		0.999240000000001,		1.52373948563770,	5.19778401627436,	9.54436934110015,	19.1863151650114,	30.0635771696034}		// AU
#declare ApoapsisDistance			= array[PlanetsNumber]	{0.466690000000000,	0.728260000000001,		1.01667932374362,		1.66592289636059,	5.45128003235434,	10.0631698807914,	20.0960943270823,	30.3244127204495}		// AU
#declare OrbitalPeriod				= array[PlanetsNumber]	{87.9690017344257,	224.699143682606,		364.840045525330,		687.012184509975,	4331.67549980859,	10767.4799006351,	30677.7150878657,	60173.0097300372}		// days
#declare ColorR						= array[PlanetsNumber]	{115,				222,					28,						135,				255,				204,				153,				102}					// 0..255
#declare ColorG						= array[PlanetsNumber]	{115,				199,					83,						100,				204,				204,				153,				102}					// 0..255
#declare ColorB						= array[PlanetsNumber]	{115,				165,					108,					60,					153,				204,				255,				255}					// 0..255

#declare MultiEccentricity		= array[PlanetsNumber];
#declare MeanAnomalyToday		= array[PlanetsNumber];
#declare TrueAnomalyToday		= array[PlanetsNumber];
#declare RadiusVectorToday		= array[PlanetsNumber];
#declare MultiInclination		= array[PlanetsNumber];
#declare MultiMeanRadius		= array[PlanetsNumber];
#declare XToday					= array[PlanetsNumber];
#declare YToday					= array[PlanetsNumber];
#declare ZToday					= array[PlanetsNumber];

#for (i, 0, PlanetsNumber - 1)
	#declare MultiEccentricity[i]	= max(min(Eccentricity[i] * EccentricityMulti, 1), 0);
	#declare MeanAnomalyToday[i]	= (Today - TimeOfPeriapsis[i]) / OrbitalPeriod[i] * 360;
	#declare TrueAnomalyToday[i]	= MeanAnomalyToday[i] + ((2 * MultiEccentricity[i] - pow(MultiEccentricity[i],3) / 4) * sind(MeanAnomalyToday[i]) + 5 / 4 * pow(MultiEccentricity[i],2) * sind(2 * MeanAnomalyToday[i]) + 13 / 12 * pow(MultiEccentricity[i],3) * sind(3 * MeanAnomalyToday[i])) * 180 / pi;
	#declare RadiusVectorToday[i]	= SemiMajorAxis[i] * (1 - pow(MultiEccentricity[i],2)) / (1 + MultiEccentricity[i] * cosd(TrueAnomalyToday[i]));
	#declare MultiInclination[i]	= Inclination[i] * InclinationMulti;
	#declare MultiMeanRadius[i]		= MeanRadius[i] / AU * MeanRadiusMulti;
	#declare XToday[i]				= RadiusVectorToday[i] * (cosd(LongitudeOfAscendingNode[i]) * cosd(TrueAnomalyToday[i] + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) - sind(LongitudeOfAscendingNode[i]) * sind(TrueAnomalyToday[i] + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) * cosd(MultiInclination[i]));
	#declare YToday[i]				= RadiusVectorToday[i] * (sind(LongitudeOfAscendingNode[i]) * cosd(TrueAnomalyToday[i] + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) + cosd(LongitudeOfAscendingNode[i]) * sind(TrueAnomalyToday[i] + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) * cosd(MultiInclination[i]));
	#declare ZToday[i]				= RadiusVectorToday[i] * sind(TrueAnomalyToday[i] + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) * sind(MultiInclination[i]);
	#debug "\n"
	#debug concat(str(XToday[i],0,-1))
	#debug "\n"
	sphere
	{
		<XToday[i],ZToday[i],YToday[i]>
		MultiMeanRadius[i]
		pigment {color rgb <ColorR[i],ColorG[i],ColorB[i]>/255}
	}

	#undef   func_MeanAnomalyToday
	#declare func_MeanAnomalyToday	= function(v) {(v - TimeOfPeriapsis[i]) / OrbitalPeriod[i] * 360}
	#undef   func_TrueAnomalyToday
	#declare func_TrueAnomalyToday	= function(v) {func_MeanAnomalyToday(v) + ((2 * MultiEccentricity[i] - pow(MultiEccentricity[i],3) / 4) * sind(func_MeanAnomalyToday(v)) + 5 / 4 * pow(MultiEccentricity[i],2) * sind(2 * func_MeanAnomalyToday(v)) + 13 / 12 * pow(MultiEccentricity[i],3) * sind(3 * func_MeanAnomalyToday(v))) * 180 / pi}
	#undef   func_RadiusVectorToday
	#declare func_RadiusVectorToday	= function(v) {SemiMajorAxis[i] * (1 - pow(MultiEccentricity[i],2)) / (1 + MultiEccentricity[i] * cosd(func_TrueAnomalyToday(v)))}
	#undef   func_XToday
	#declare func_XToday			= function(u,v) {u + func_RadiusVectorToday(v) * (cosd(LongitudeOfAscendingNode[i]) * cosd(func_TrueAnomalyToday(v) + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) - sind(LongitudeOfAscendingNode[i]) * sind(func_TrueAnomalyToday(v) + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) * cosd(MultiInclination[i]))}
	#undef   func_YToday
	#declare func_YToday			= function(u,v) {u + func_RadiusVectorToday(v) * (sind(LongitudeOfAscendingNode[i]) * cosd(func_TrueAnomalyToday(v) + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) + cosd(LongitudeOfAscendingNode[i]) * sind(func_TrueAnomalyToday(v) + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) * cosd(MultiInclination[i]))}
	#undef   func_ZToday
	#declare func_ZToday			= function(u,v) {func_RadiusVectorToday(v) * sind(func_TrueAnomalyToday(v) + ArgumentOfPerifocus[i] - LongitudeOfAscendingNode[i]) * sind(MultiInclination[i])}
/*
	parametric
	{
		function { func_XToday(u,v) }
		function { func_ZToday(u,v) }
		function { func_YToday(u,v) }
	
		<0,StartDate>, <0.01,StartDate + DateRange>
		contained_by { sphere{0, 40} }
//		max_gradient ??
		accuracy 0.0001
		precompute 10 x,y,z
		pigment {rgb x}
	}
*/
	object
	{
		Parametric(func_XToday, func_ZToday, func_YToday, <0,StartDate>, <0.01,StartDate + 50>, 1, 10, "temp.arr")
		pigment {color rgb <ColorR[i],ColorG[i],ColorB[i]>/255}
	}
#end

#declare RWorld_Sun_Radius				= MultiSunRadius;


//------------------------------------------------------------------------------
// CAMERA


#declare RWorld_Camera_Vertical		= 0;			//45;
#declare RWorld_Camera_Horizontal	= 30;			//asind(tand(30));
#declare RWorld_Camera_Aspect		= image_height/image_width;
#declare RWorld_Camera_Distance		= 10;
#declare RWorld_Camera_Translate	= <0,0,0>;
#declare RWorld_Camera_Scale		= 1;
#declare RWorld_Camera_Rotate		= <RWorld_Camera_Horizontal,RWorld_Camera_Vertical,0,>;

#declare RWorld_Camera_Up			= +y * 2 * RWorld_Camera_Aspect;
#declare RWorld_Camera_Right		= +x * 2;
#declare RWorld_Camera_Location		= -z * RWorld_Camera_Distance;
#declare RWorld_Camera_Direction	= +z * RWorld_Camera_Distance;
#declare RWorld_Camera_LookAt		= RWorld_Camera_Location + RWorld_Camera_Direction;
#declare RWorld_Camera_Transform = transform
{
	rotate		RWorld_Camera_Rotate
	scale		RWorld_Camera_Scale
	translate	RWorld_Camera_Translate
}

camera
{
	perspective
	//orthographic
	up			RWorld_Camera_Up
	right		RWorld_Camera_Right
	location	RWorld_Camera_Location
	direction	RWorld_Camera_Direction
	transform {RWorld_Camera_Transform}
}

#declare RWorld_Camera_Location	= vtransform(RWorld_Camera_Location,RWorld_Camera_Transform);
#declare RWorld_Camera_LookAt	= vtransform(RWorld_Camera_LookAt,RWorld_Camera_Transform);


//------------------------------------------------------------------------------
// MISC GRAPHICAL SETTINGS


background {color rgb 1/2}



//------------------------------------------------------------------------------
// SUN


#declare RWorld_Sun_Object = sphere
{ 
	0, RWorld_Sun_Radius
	hollow
	material
	{
		texture
		{
			pigment {rgbt 1}
		}
		interior
		{
			media
			{
				emission 1/RWorld_Sun_Radius
				density
				{
					spherical
					density_map
					{
						[0.0 rgb 0]
						[0.2 rgb 1]
						[1.0 rgb 1]
					}
					scale RWorld_Sun_Radius
				}
			}
		}
	}
}



//------------------------------------------------------------------------------
// LIGHTS

light_source
{
	<-1,+1,+1,> * 100
	color rgb	1
	rotate -y * 15
	parallel
	point_at 0
	shadowless
}
light_source
{
	<-1,+1,+1,> * 100
	color rgb	1
	rotate +y * 270
	rotate -y * 15
	parallel
	point_at 0
	shadowless
}



object {RWorld_Sun_Object}
