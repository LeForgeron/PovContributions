// Caption: SolarSystemOrrery
// Version: 2.2
// Authors: Michael Horvath
// Website: http://isometricland.net
// Created: 2018-09-13
// Updated: 2018-09-19
// This file is licensed under the terms of the CC-LGPL.
// http://www.gnu.org/licenses/lgpl-2.1.html
// Formulas based on PDF document available at: https://ssd.jpl.nasa.gov/?planet_pos
// Also requires PlanetPovray textures at: http://www.midnightkite.com/index.aspx?AID=300
// Or Solar System Scope textures at: https://www.solarsystemscope.com/textures/

#version 3.8


//------------------------------------------------------------------------------
// INCLUDES


#include "screen.inc"			// Requires the updated version available here: http://news.povray.org/povray.text.scene-files/thread/%3C581be4f1%241%40news.povray.org%3E/
#include "CIE.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "math.inc"
#include "transforms.inc"


//------------------------------------------------------------------------------
// PARAMETERS


#declare Orrery_PlanetsNumber		= 8;
#declare Orrery_StartDate			= 2458376.5;			// Julian days, A.D. 2018 Sep 15
#declare Orrery_DecoMode			= 1;					// 1 = black; 2 = gray
#declare Orrery_Inner_Outer			= 2;					// 1 = inner planets; 2 = outer planets
#declare Orrery_SunRadius			= 696000;				// km
#declare Orrery_AU					= 149597870.691;		// km
#declare Orrery_EccentricityMulti	= 1;					// not used currrently
#declare Orrery_InclinationMulti	= 1;					// not used currrently
#declare Orrery_Toggle_Radiosity	= true;
#declare Orrery_Camera_Mode			= 1;					// 1 = perspective; 2 = orthographic
#declare Orrery_Bitmap_Textures		= true;
#declare Orrery_TextSize			= 0.05;
#declare Orrery_Animation			= false;					// true or false
#declare Orrery_Light_Lumens		= 2;
#declare Orrery_Light_Temp			= Daylight(5800);
#declare Orrery_Light_Color			= Light_Color(Orrery_Light_Temp,Orrery_Light_Lumens);

#if (Orrery_Inner_Outer = 1)
	#declare Orrery_Scene_Scale			= 1.75;
	#declare Orrery_MeanRadiusMulti		= 1024;
	#declare Orrery_Line_Thickness		= 1/32;															// AU
//	#declare Orrery_Line_Thickness		= Orrery_Scene_Scale * 1/40;									// AU
	#if (Orrery_Animation = true)
		#declare Orrery_StopDate		= Orrery_StartDate + clock * 364.840045525330;					// Julian days
	#else
		#declare Orrery_StopDate		= Orrery_StartDate + 120;										// Julian days
	#end
	#declare Orrery_Sun_Radius			= Orrery_SunRadius/Orrery_AU * Orrery_Scene_Scale * 8;			// AU
	#declare Orrery_Ring_Distance		= 1/2;															// AU
	#declare Orrery_Trail_Radius		= Orrery_Scene_Scale/256;										// AU
#elseif (Orrery_Inner_Outer = 2)
	#declare Orrery_Scene_Scale			= 32;
	#declare Orrery_MeanRadiusMulti		= 1024 * 2;
	#declare Orrery_Line_Thickness		= 1/32 * 8;														// AU
//	#declare Orrery_Line_Thickness		= Orrery_Scene_Scale * 1/40;									// AU
	#if (Orrery_Animation = true)
		#declare Orrery_StopDate		= Orrery_StartDate + clock * 4331.67549980859;					// Julian days
	#else
		#declare Orrery_StopDate		= Orrery_StartDate + 4320;										// Julian days
	#end
	#declare Orrery_Sun_Radius			= Orrery_SunRadius/Orrery_AU * Orrery_Scene_Scale * 8;			// AU
	#declare Orrery_Ring_Distance		= 4;															// AU
	#declare Orrery_Trail_Radius		= Orrery_Scene_Scale/256;										// AU
#end

#if (Orrery_DecoMode = 1)
	#declare Orrery_Light_Mode = 2;
#elseif (Orrery_DecoMode = 2)
	#declare Orrery_Light_Mode = 4;
#end

#debug "\n"
#debug concat("Orrery_StartDate = ", str(Orrery_StartDate, 0, -1), "\n")
#debug concat("Orrery_StopDate = ", str(Orrery_StopDate, 0, -1), "\n")
#debug "\n"


//------------------------------------------------------------------------------
// CAMERA


#declare Orrery_Camera_Vertical		= 45;			//45;
#declare Orrery_Camera_Horizontal	= 30;			//asind(tand(30));
#declare Orrery_Camera_Aspect		= image_height/image_width;
#declare Orrery_Camera_Distance		= 32;
#declare Orrery_Camera_Rotate		= <Orrery_Camera_Horizontal,Orrery_Camera_Vertical,0,>;
#declare Orrery_Camera_Translate	= <0,0,0>;
#declare Orrery_Camera_Up			= +y * 2 * Orrery_Camera_Aspect;
#declare Orrery_Camera_Right		= +x * 2;
#declare Orrery_Camera_Location		= -z * Orrery_Camera_Distance;
#declare Orrery_Camera_Direction	= +z * Orrery_Camera_Distance;
#declare Orrery_Camera_Transform = transform
{
	rotate		Orrery_Camera_Rotate
	scale		Orrery_Scene_Scale
	translate	Orrery_Camera_Translate
}

#if (Orrery_Camera_Mode = 1)
	Set_Camera_Orthographic(false)
	Set_Camera_Transform(Orrery_Camera_Transform)
	Set_Camera_Alt(Orrery_Camera_Location, Orrery_Camera_Direction, Orrery_Camera_Right, Orrery_Camera_Up)
#elseif (Orrery_Camera_Mode = 2)
	Set_Camera_Orthographic(true)
	Set_Camera_Transform(Orrery_Camera_Transform)
	Set_Camera_Alt(Orrery_Camera_Location, Orrery_Camera_Direction, Orrery_Camera_Right, Orrery_Camera_Up)
#end


//------------------------------------------------------------------------------
// MISC. GRAPHICAL SETTINGS


global_settings
{
	#if (Orrery_Toggle_Radiosity = true)
		radiosity
		{
			always_sample	off
			brightness		0.3
		}
	#end
	ambient_light	0.01
	charset			utf8
	assumed_gamma	1
}

#if (Orrery_DecoMode = 1)

	sky_sphere
	{
		pigment
		{
			bozo
			color_map
			{
				[0.0 color srgb 1]
				[0.2 color srgb 0]
				[1.0 color srgb 0]
			}
			scale 1e-4
		}
	}
/*
	sky_sphere
	{
		pigment
		{
			image_map
			{
				jpeg "8k_stars_milky_way.jpg"
				map_type 1
			}
		}
	}
*/
#elseif (Orrery_DecoMode = 2)
	background {color srgb 3/4}
#end

//------------------------------------------------------------------------------
// PLANETS


#declare Orrery_PlanetName					= array[Orrery_PlanetsNumber]	{"Mercury",			"Venus",			"Earth",			"Mars",				"Jupiter",			"Saturn",			"Uranus",			"Neptune"}				// string
#declare Orrery_MeanRadius					= array[Orrery_PlanetsNumber]	{2439.00000000,		6051.80000000,		6371.00000000,		3389.90000000,		69911.00000000,		58232.00000000,		25362.00000000,		24624.00000000}			// km
#declare Orrery_OrbitalPeriod				= array[Orrery_PlanetsNumber]	{87.9690017344257,	224.699143682606,	364.840045525330,	687.012184509975,	4331.67549980859,	10767.4799006351,	30677.7150878657,	60173.0097300372}		// days
#declare Orrery_RotationPeriod				= array[Orrery_PlanetsNumber]	{58.646,			-243.025,			0.99726968,			1.025957,			0.41354166666667,	0.43958333333333,	-0.71833,			0.6713}					// days
#declare Orrery_AxialTilt					= array[Orrery_PlanetsNumber]	{0.034,				177.36,				23.4392811,			25.19,				3.13,				26.73,				97.77,				28.32}					// deg
#declare Orrery_Color						= array[Orrery_PlanetsNumber]	{<115,115,115>,		<237,197,135>,		<030,059,117>,		<219,097,058>,		<179,158,131>,		<220,193,148>,		<164,213,220>,		<057,087,183>}			// 0..255
#if (Orrery_Inner_Outer = 1)
	#declare Orrery_ShowPlanet					= array[Orrery_PlanetsNumber]	{true,				true,				true,				true,				false,				false,				false,				false}					// true or false
#elseif (Orrery_Inner_Outer = 2)
	#declare Orrery_ShowPlanet					= array[Orrery_PlanetsNumber]	{false,				false,				false,				false,				true,				true,				true,				true}					// true or false
#end
#declare Orrery_ShowPaths					= array[Orrery_PlanetsNumber]	{true,				true,				true,				true,				true,				true,				true,				true}					// true or false
#declare Orrery_Textures					= array[Orrery_PlanetsNumber]	{"2k_mercury.jpg",	"2k_venus_atmosphere.jpg",	"2k_earth_daymap.jpg",	"2k_mars.jpg",	"2k_jupiter.jpg",	"2k_saturn.jpg",	"2k_uranus.jpg",	"2k_neptune.jpg"}		// filename

/*
// Keplerian elements and their rates, with respect to the mean ecliptic and equinox of J2000, valid for the time-interval 3000 BC -- 3000 AD.
#declare Orrery_SemiMajorAxis				= array[Orrery_PlanetsNumber]	{     0.38709843,	    0.72332102,		    1.00000018,		    1.52371243,		   5.20248019,		   9.54149883,		 19.18797948,		 30.06952752}			// AU
#declare Orrery_SemiMajorAxisCty			= array[Orrery_PlanetsNumber]	{     0.00000000,	   -0.00000026,		   -0.00000003,		    0.00000097,		  -0.00002864,		  -0.00003065,		 -0.00020455,		  0.00006447}			// AU/century
#declare Orrery_Eccentricity				= array[Orrery_PlanetsNumber]	{     0.20563661,	    0.00676399,		    0.01673163,		    0.09336511,		   0.04853590,		   0.05550825,		  0.04685740,		  0.00895439}			// 0..1
#declare Orrery_EccentricityCty				= array[Orrery_PlanetsNumber]	{     0.00002123,	   -0.00005107,		   -0.00003661,		    0.00009149,		   0.00018026,		  -0.00032044,		 -0.00001550,		  0.00000818}			// 0..1/century
#declare Orrery_Inclination					= array[Orrery_PlanetsNumber]	{     7.00559432,	    3.39777545,		   -0.00054346,		    1.85181869,		   1.29861416,		   2.49424102,		  0.77298127,		  1.77005520}			// deg
#declare Orrery_InclinationCty				= array[Orrery_PlanetsNumber]	{    -0.00590158,	    0.00043494,		   -0.01337178,		   -0.00724757,		  -0.00322699,		   0.00451969,		 -0.00180155,		  0.00022400}			// deg/century
#declare Orrery_MeanLongitude				= array[Orrery_PlanetsNumber]	{   252.25166724,	  181.97970850,		  100.46691572,		   -4.56813164,		  34.33479152,		  50.07571329,		314.20276625,		304.22289287}			// deg
#declare Orrery_MeanLongitudeCty			= array[Orrery_PlanetsNumber]	{149472.67486623,	58517.81560260,		35999.37306329,		19140.29934243,		3034.90371757,		1222.11494724,		428.49512595,		218.46515314}			// deg/century
#declare Orrery_LongitudeOfPerihelion		= array[Orrery_PlanetsNumber]	{    77.45771895,	  131.76755713,		  102.93005885,		  -23.91744784,		  14.27495244,		  92.86136063,		172.43404441,		 46.68158724}			// deg
#declare Orrery_LongitudeOfPerihelionCty	= array[Orrery_PlanetsNumber]	{     0.15940013,	    0.05679648,		    0.31795260,		    0.45223625,		   0.18199196,		   0.54179478,		  0.09266985,		  0.01009938}			// deg/century
#declare Orrery_LongitudeOfAscendingNode	= array[Orrery_PlanetsNumber]	{    48.33961819,	   76.67261496,		   -5.11260389,		   49.71320984,		 100.29282654,		 113.63998702,		 73.96250215,		131.78635853}			// deg
#declare Orrery_LongitudeOfAscendingNodeCty	= array[Orrery_PlanetsNumber]	{    -0.12214182,	   -0.27274174,		   -0.24123856,		   -0.26852431,		   0.13024619,		  -0.25015002,		  0.05739699,		 -0.00606302}			// deg/century
#declare Orrery_TermB						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,		    0.00000000,		    0.00000000,		  -0.00012452,		   0.00025899,		  0.00058331,		 -0.00041348}			// b
#declare Orrery_TermC						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,		    0.00000000,		    0.00000000,		   0.06064060,		  -0.13434469,		 -0.97731848,		  0.68346318}			// c
#declare Orrery_TermS						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,		    0.00000000,		    0.00000000,		  -0.35635438,		   0.87320147,		  0.17689245,		 -0.10162547}			// s
#declare Orrery_TermF						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,		    0.00000000,		    0.00000000,		  38.35125000,		  38.35125000,		  7.67025000,		  7.67025000}			// f
*/

// Keplerian elements and their rates, with respect to the mean ecliptic and equinox of J2000, valid for the time-interval 1800 AD - 2050 AD.
#declare Orrery_SemiMajorAxis				= array[Orrery_PlanetsNumber]	{     0.38709927,	    0.72333566,			1.00000261,			1.52371034,		   5.20288700,		   9.53667594,		 19.18916464,		 30.06992276}			// AU
#declare Orrery_SemiMajorAxisCty			= array[Orrery_PlanetsNumber]	{     0.00000037,	    0.00000390,			0.00000562,			0.00001847,		  -0.00011607,		  -0.00125060,		 -0.00196176,		  0.00026291}			// AU/century
#declare Orrery_Eccentricity				= array[Orrery_PlanetsNumber]	{     0.20563593,	    0.00677672,			0.01671123,			0.09339410,		   0.04838624,		   0.05386179,		  0.04725744,		  0.00859048}			// 0..1
#declare Orrery_EccentricityCty				= array[Orrery_PlanetsNumber]	{     0.00001906,	   -0.00004107,		   -0.00004392,		    0.00007882,		  -0.00013253,		  -0.00050991,		 -0.00004397,		  0.00005105}			// 0..1/century
#declare Orrery_Inclination					= array[Orrery_PlanetsNumber]	{     7.00497902,	    3.39467605,		   -0.00001531,		    1.84969142,		   1.30439695,		   2.48599187,		  0.77263783,		  1.77004347}			// deg
#declare Orrery_InclinationCty				= array[Orrery_PlanetsNumber]	{    -0.00594749,	   -0.00078890,		   -0.01294668,		   -0.00813131,		  -0.00183714,		   0.00193609,		 -0.00242939,		  0.00035372}			// deg/century
#declare Orrery_MeanLongitude				= array[Orrery_PlanetsNumber]	{   252.25032350,	  181.97909950,		  100.46457170,		   -4.55343205,		  34.39644051,		  49.95424423,		313.23810450,		-55.12002969}			// deg
#declare Orrery_MeanLongitudeCty			= array[Orrery_PlanetsNumber]	{149472.67410000,	58517.81539000,		35999.37245000,		19140.30268000,		3034.74612800,		1222.49362200,		428.48202790,		218.45945330}			// deg/century
#declare Orrery_LongitudeOfPerihelion		= array[Orrery_PlanetsNumber]	{    77.45779628,	  131.60246720,		  102.93768190,		  -23.94362959,		  14.72847983,		  92.59887831,		170.95427630,		 44.96476227}			// deg
#declare Orrery_LongitudeOfPerihelionCty	= array[Orrery_PlanetsNumber]	{     0.16047689,	    0.00268329,			0.32327364,			0.44441088,		   0.21252668,		  -0.41897216,		  0.40805281,		 -0.32241464}			// deg/century
#declare Orrery_LongitudeOfAscendingNode	= array[Orrery_PlanetsNumber]	{    48.33076593,	   76.67984255,		    0.00000000,		   49.55953891,		 100.47390910,		 113.66242450,		 74.01692503,		131.78422570}			// deg
#declare Orrery_LongitudeOfAscendingNodeCty	= array[Orrery_PlanetsNumber]	{    -0.12534081,	   -0.27769418,		    0.00000000,		   -0.29257343,		   0.20469106,		  -0.28867794,		  0.04240589,		 -0.00508664}			// deg/century
#declare Orrery_TermB						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,			0.00000000,			0.00000000,		   0.00000000,		   0.00000000,		  0.00000000,		  0.00000000}			// b
#declare Orrery_TermC						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,			0.00000000,			0.00000000,		   0.00000000,		   0.00000000,		  0.00000000,		  0.00000000}			// c
#declare Orrery_TermS						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,			0.00000000,			0.00000000,		   0.00000000,		   0.00000000,		  0.00000000,		  0.00000000}			// s
#declare Orrery_TermF						= array[Orrery_PlanetsNumber]	{     0.00000000,	    0.00000000,			0.00000000,			0.00000000,		   0.00000000,		   0.00000000,		  0.00000000,		  0.00000000}			// f


#macro Orrery_PlaceSphere(Orrery_i, Orrery_LastDate)
	#local Orrery_Temp_MultiMeanRadius = Orrery_MeanRadius[Orrery_i] / Orrery_AU * Orrery_MeanRadiusMulti;
//	#local Orrery_Temp_MultiMeanRadius = 0.1;
	#local Orrery_SphereColor = Orrery_Color[Orrery_i]/255;
	#local Orrery_SphereFinish = finish {}
//	#local Orrery_SphereFinish = finish {ambient 0 diffuse 0 emission 1/2}

	#local Orrery_Temp_TValue						= (Orrery_LastDate - 2451545.0)/36525;			// number of centuries past J2000.0

	#local Orrery_Temp_SemiMajorAxis				= Orrery_SemiMajorAxis[Orrery_i]				+ Orrery_SemiMajorAxisCty[Orrery_i]				* Orrery_Temp_TValue;
	#local Orrery_Temp_Eccentricity					= Orrery_Eccentricity[Orrery_i]					+ Orrery_EccentricityCty[Orrery_i]				* Orrery_Temp_TValue;
	#local Orrery_Temp_Inclination					= Orrery_Inclination[Orrery_i]					+ Orrery_InclinationCty[Orrery_i]				* Orrery_Temp_TValue;
	#local Orrery_Temp_MeanLongitude				= Orrery_MeanLongitude[Orrery_i]				+ Orrery_MeanLongitudeCty[Orrery_i]				* Orrery_Temp_TValue;
	#local Orrery_Temp_LongitudeOfPerihelion		= Orrery_LongitudeOfPerihelion[Orrery_i]		+ Orrery_LongitudeOfPerihelionCty[Orrery_i]		* Orrery_Temp_TValue;
	#local Orrery_Temp_LongitudeOfAscendingNode		= Orrery_LongitudeOfAscendingNode[Orrery_i]		+ Orrery_LongitudeOfAscendingNodeCty[Orrery_i]	* Orrery_Temp_TValue;

	#local Orrery_Temp_ArgumentOfPerihelion			= Orrery_Temp_LongitudeOfPerihelion - Orrery_Temp_LongitudeOfAscendingNode;
	#local Orrery_Temp_MeanAnomaly					= Orrery_Temp_MeanLongitude - Orrery_Temp_LongitudeOfPerihelion + Orrery_TermB[Orrery_i] * pow(Orrery_Temp_TValue,2) + Orrery_TermC[Orrery_i] * cosd(Orrery_TermF[Orrery_i] * Orrery_Temp_TValue) + Orrery_TermS[Orrery_i] * sind(Orrery_TermF[Orrery_i] * Orrery_Temp_TValue);
	#local Orrery_Temp_MeanAnomaly					= clamp(Orrery_Temp_MeanAnomaly,-180,180);

	#local Orrery_Temp_EccentricityDegrees			= degrees(Orrery_Temp_Eccentricity);
	#local Orrery_Temp_EccentricAnomaly				= Orrery_Temp_MeanAnomaly + Orrery_Temp_EccentricityDegrees * sind(Orrery_Temp_MeanAnomaly);
	#local Orrery_Temp_EccentricAnomalyTolerance	= 10e-6;
	#local Orrery_Temp_EccentricAnomalyDelta		= 10;

	#while (abs(Orrery_Temp_EccentricAnomalyDelta) > Orrery_Temp_EccentricAnomalyTolerance)
		#local Orrery_Temp_MeanAnomalyDelta				= Orrery_Temp_MeanAnomaly - (Orrery_Temp_EccentricAnomaly - Orrery_Temp_EccentricityDegrees * sind(Orrery_Temp_EccentricAnomaly));
		#local Orrery_Temp_EccentricAnomalyDelta		= Orrery_Temp_MeanAnomalyDelta/(1 - Orrery_Temp_Eccentricity * cosd(Orrery_Temp_EccentricAnomaly));
		#local Orrery_Temp_EccentricAnomaly				= Orrery_Temp_EccentricAnomaly + Orrery_Temp_EccentricAnomalyDelta;
	#end

	#local Orrery_Temp_XPrime = Orrery_Temp_SemiMajorAxis * (cosd(Orrery_Temp_EccentricAnomaly) - Orrery_Temp_Eccentricity);
	#local Orrery_Temp_YPrime = Orrery_Temp_SemiMajorAxis * sqrt(1 - pow(Orrery_Temp_Eccentricity,2)) * sind(Orrery_Temp_EccentricAnomaly);
	#local Orrery_Temp_ZPrime = 0;

	#local Orrery_Temp_Xecl_a = Orrery_Temp_XPrime * (+cosd(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) - sind(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
	#local Orrery_Temp_Xecl_b = Orrery_Temp_YPrime * (-sind(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) - cosd(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
	#local Orrery_Temp_Xecl_c = Orrery_Temp_Xecl_a + Orrery_Temp_Xecl_b;

	#local Orrery_Temp_Yecl_a = Orrery_Temp_XPrime * (+cosd(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) + sind(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
	#local Orrery_Temp_Yecl_b = Orrery_Temp_YPrime * (-sind(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) + cosd(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
	#local Orrery_Temp_Yecl_c = Orrery_Temp_Yecl_a + Orrery_Temp_Yecl_b;

	#local Orrery_Temp_Zecl_a = Orrery_Temp_XPrime * (+sind(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_Inclination));
	#local Orrery_Temp_Zecl_b = Orrery_Temp_YPrime * (+cosd(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_Inclination));
	#local Orrery_Temp_Zecl_c = Orrery_Temp_Zecl_a + Orrery_Temp_Zecl_b;

	#local Orrery_SphereCoo3D = <Orrery_Temp_Xecl_c,Orrery_Temp_Zecl_c,Orrery_Temp_Yecl_c>;
	#local Orrery_SphereCoo2D = Get_Screen_XY(Orrery_SphereCoo3D);
	#local Orrery_SphereCoo2D = Orrery_SphereCoo2D/<image_width,image_height>;
	#local Orrery_SphereCoo2D = <Orrery_SphereCoo2D.x,1-Orrery_SphereCoo2D.y>;

	sphere
	{
		0
		Orrery_Temp_MultiMeanRadius
		#if (Orrery_Bitmap_Textures = true)
			texture
			{
				pigment
				{
					image_map
					{
						jpeg Orrery_Textures[Orrery_i]
						map_type 1
					}
				}
				finish {Orrery_SphereFinish}
			}
		#else
			texture
			{
				pigment {color srgb Orrery_SphereColor}
				finish {Orrery_SphereFinish}
			}
		#end
		translate Orrery_SphereCoo3D
	}

	#local Orrery_PlanetText = text
	{
		ttf "crystal.ttf", Orrery_PlanetName[Orrery_i], 0.001, <0,0>
		scale Orrery_TextSize
		#if (Orrery_DecoMode = 1)
			pigment {color srgb 3/4}
			finish {ambient 0 diffuse 0 emission 1}
		#elseif (Orrery_DecoMode = 2)
			pigment {color srgb 0}
		#end
		no_shadow
	}

	Screen_Object(Orrery_PlanetText, Orrery_SphereCoo2D + <0.01,0.01>, 0, false, 0.01)

	#debug "\n"
	#debug concat(Orrery_PlanetName[Orrery_i], "\n")
	#debug concat("SemiMajorAxis (AU) = ", str(Orrery_Temp_SemiMajorAxis, 0, -1), "\n")
	#debug concat("Eccentricity (0..1) = ", str(Orrery_Temp_Eccentricity, 0, -1), "\n")
	#debug concat("Inclination (deg) = ", str(Orrery_Temp_Inclination, 0, -1), "\n")
	#debug concat("MeanLongitude (deg) = ", str(Orrery_Temp_MeanLongitude, 0, -1), "\n")
	#debug concat("LongitudeOfPerihelion (deg) = ", str(Orrery_Temp_LongitudeOfPerihelion, 0, -1), "\n")
	#debug concat("LongitudeOfAscendingNode (deg) = ", str(Orrery_Temp_LongitudeOfAscendingNode, 0, -1), "\n")
	#debug concat("ArgumentOfPerihelion (deg) = ", str(Orrery_Temp_ArgumentOfPerihelion, 0, -1), "\n")
	#debug concat("MeanAnomaly (deg) = ", str(Orrery_Temp_MeanAnomaly, 0, -1), "\n")
	#debug concat("EccentricAnomaly (deg) = ", str(Orrery_Temp_EccentricAnomaly, 0, -1), "\n")
	#debug "\n"

#end

#macro Orrery_TracePath(Orrery_i, Orrery_FirstDate, Orrery_LastDate, Orrery_StepSize)
	#local Orrery_Temp_MultiMeanRadius = Orrery_MeanRadius[Orrery_i] / Orrery_AU * Orrery_MeanRadiusMulti;
//	#local Orrery_Temp_MultiMeanRadius = 0.1;
	#local Orrery_SphereColor = Orrery_Color[Orrery_i]/255;
	#local Orrery_SphereFinish = finish {}
//	#local Orrery_SphereFinish = finish {ambient 0 diffuse 0 emission 1/2}
//	#local Orrery_Trail_Radius = Orrery_Temp_MultiMeanRadius/4;

//	#local Orrery_StepSize				= Orrery_OrbitalPeriod[Orrery_i] / 36;		// days
	#local Orrery_StepsNum				= (Orrery_LastDate - Orrery_FirstDate) / Orrery_StepSize;
	#for (Orrery_j, 0, Orrery_StepsNum - Orrery_StepSize, Orrery_StepSize)
		#local Orrery_StepDate							= Orrery_FirstDate + Orrery_j * Orrery_StepSize;
		#local Orrery_Temp_TValue						= (Orrery_StepDate - 2451545.0)/36525;			// number of centuries past J2000.0
	
		#local Orrery_Temp_SemiMajorAxis				= Orrery_SemiMajorAxis[Orrery_i]				+ Orrery_SemiMajorAxisCty[Orrery_i]				* Orrery_Temp_TValue;
		#local Orrery_Temp_Eccentricity					= Orrery_Eccentricity[Orrery_i]					+ Orrery_EccentricityCty[Orrery_i]				* Orrery_Temp_TValue;
		#local Orrery_Temp_Inclination					= Orrery_Inclination[Orrery_i]					+ Orrery_InclinationCty[Orrery_i]				* Orrery_Temp_TValue;
		#local Orrery_Temp_MeanLongitude				= Orrery_MeanLongitude[Orrery_i]				+ Orrery_MeanLongitudeCty[Orrery_i]				* Orrery_Temp_TValue;
		#local Orrery_Temp_LongitudeOfPerihelion		= Orrery_LongitudeOfPerihelion[Orrery_i]		+ Orrery_LongitudeOfPerihelionCty[Orrery_i]		* Orrery_Temp_TValue;
		#local Orrery_Temp_LongitudeOfAscendingNode		= Orrery_LongitudeOfAscendingNode[Orrery_i]		+ Orrery_LongitudeOfAscendingNodeCty[Orrery_i]	* Orrery_Temp_TValue;
	
		#local Orrery_Temp_ArgumentOfPerihelion			= Orrery_Temp_LongitudeOfPerihelion - Orrery_Temp_LongitudeOfAscendingNode;
		#local Orrery_Temp_MeanAnomaly					= Orrery_Temp_MeanLongitude - Orrery_Temp_LongitudeOfPerihelion + Orrery_TermB[Orrery_i] * pow(Orrery_Temp_TValue,2) + Orrery_TermC[Orrery_i] * cosd(Orrery_TermF[Orrery_i] * Orrery_Temp_TValue) + Orrery_TermS[Orrery_i] * sind(Orrery_TermF[Orrery_i] * Orrery_Temp_TValue);
		#local Orrery_Temp_MeanAnomaly					= clamp(Orrery_Temp_MeanAnomaly,-180,180);
	
		#local Orrery_Temp_EccentricityDegrees			= degrees(Orrery_Temp_Eccentricity);
		#local Orrery_Temp_EccentricAnomaly				= Orrery_Temp_MeanAnomaly + Orrery_Temp_EccentricityDegrees * sind(Orrery_Temp_MeanAnomaly);
		#local Orrery_Temp_EccentricAnomalyTolerance	= 10e-6;
		#local Orrery_Temp_EccentricAnomalyDelta		= 10;
	
		#while (abs(Orrery_Temp_EccentricAnomalyDelta) > Orrery_Temp_EccentricAnomalyTolerance)
			#local Orrery_Temp_MeanAnomalyDelta				= Orrery_Temp_MeanAnomaly - (Orrery_Temp_EccentricAnomaly - Orrery_Temp_EccentricityDegrees * sind(Orrery_Temp_EccentricAnomaly));
			#local Orrery_Temp_EccentricAnomalyDelta		= Orrery_Temp_MeanAnomalyDelta/(1 - Orrery_Temp_Eccentricity * cosd(Orrery_Temp_EccentricAnomaly));
			#local Orrery_Temp_EccentricAnomaly				= Orrery_Temp_EccentricAnomaly + Orrery_Temp_EccentricAnomalyDelta;
		#end
	
		#local Orrery_Temp_XPrime = Orrery_Temp_SemiMajorAxis * (cosd(Orrery_Temp_EccentricAnomaly) - Orrery_Temp_Eccentricity);
		#local Orrery_Temp_YPrime = Orrery_Temp_SemiMajorAxis * sqrt(1 - pow(Orrery_Temp_Eccentricity,2)) * sind(Orrery_Temp_EccentricAnomaly);
		#local Orrery_Temp_ZPrime = 0;
	
		#local Orrery_Temp_Xecl_a = Orrery_Temp_XPrime * (+cosd(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) - sind(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
		#local Orrery_Temp_Xecl_b = Orrery_Temp_YPrime * (-sind(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) - cosd(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
		#local Orrery_Temp_Xecl_c = Orrery_Temp_Xecl_a + Orrery_Temp_Xecl_b;
	
		#local Orrery_Temp_Yecl_a = Orrery_Temp_XPrime * (+cosd(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) + sind(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
		#local Orrery_Temp_Yecl_b = Orrery_Temp_YPrime * (-sind(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_LongitudeOfAscendingNode) + cosd(Orrery_Temp_ArgumentOfPerihelion) * cosd(Orrery_Temp_LongitudeOfAscendingNode) * cosd(Orrery_Temp_Inclination));
		#local Orrery_Temp_Yecl_c = Orrery_Temp_Yecl_a + Orrery_Temp_Yecl_b;
	
		#local Orrery_Temp_Zecl_a = Orrery_Temp_XPrime * (+sind(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_Inclination));
		#local Orrery_Temp_Zecl_b = Orrery_Temp_YPrime * (+cosd(Orrery_Temp_ArgumentOfPerihelion) * sind(Orrery_Temp_Inclination));
		#local Orrery_Temp_Zecl_c = Orrery_Temp_Zecl_a + Orrery_Temp_Zecl_b;
	
		#local Orrery_SphereCoo3D = <Orrery_Temp_Xecl_c,Orrery_Temp_Zecl_c,Orrery_Temp_Yecl_c>;
		#local Orrery_SphereCoo2D = Get_Screen_XY(Orrery_SphereCoo3D);
		#local Orrery_SphereCoo2D = Orrery_SphereCoo2D/<image_width,image_height>;
		#local Orrery_SphereCoo2D = <Orrery_SphereCoo2D.x,1-Orrery_SphereCoo2D.y>;
	
		sphere
		{
			0
			Orrery_Trail_Radius
			pigment {color srgb Orrery_SphereColor}
			finish {Orrery_SphereFinish}
			translate Orrery_SphereCoo3D
			#if (Orrery_DecoMode = 1)
				no_shadow
			#end
		}
	#end
#end

#for (Orrery_i, 0, Orrery_PlanetsNumber - 1, 1)
	#if (Orrery_ShowPlanet[Orrery_i] = true)
		Orrery_PlaceSphere(Orrery_i, Orrery_StopDate)
		#if (Orrery_ShowPaths[Orrery_i] = true)
			Orrery_TracePath(Orrery_i, Orrery_StartDate, Orrery_StopDate, 1)
		#end
	#end
#end


//------------------------------------------------------------------------------
// ECLIPTIC MARKER PLANE


#declare Orrery_Ecliptic_Pattern = union
{
	#local Orrery_Ecliptic_Steps = 64;
	#for (i, Orrery_Ring_Distance, Orrery_Ecliptic_Steps, Orrery_Ring_Distance)
		difference
		{
			cylinder {-y * 1, +y * 1, i + Orrery_Line_Thickness/2}
			cylinder {-y * 2, +y * 2, i - Orrery_Line_Thickness/2}
		}
	#end
	#local Orrery_Ecliptic_Steps = 4;
	#local Orrery_Ecliptic_Angle = 360/Orrery_Ecliptic_Steps;
	#for (i, 1, Orrery_Ecliptic_Steps)
		cylinder
		{
			0, +x * 48, Orrery_Line_Thickness/2
			rotate +y * i * Orrery_Ecliptic_Angle
		}
	#end
}

plane
{
	y, 0
	pigment
	{
		object
		{
			Orrery_Ecliptic_Pattern
			color srgbt <1,1,1,3/4>
			color srgbt <1,1,1,1/4>
		}
	}
//	#if (Orrery_DecoMode = 2)
//		finish {ambient 0 diffuse 0 emission 1}
//	#end
	hollow
}


//------------------------------------------------------------------------------
// SUN


#declare Orrery_Sun_Object = sphere
{ 
	0, Orrery_Sun_Radius
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
				emission Orrery_Light_Color/Orrery_Sun_Radius
				density
				{
					spherical
					density_map
					{
						[0.0 rgb 0]
						[0.1 rgb 1]
						[1.0 rgb 1]
					}
					scale Orrery_Sun_Radius
				}
			}
		}
	}
	no_shadow
}

#if (Orrery_Light_Mode != 2)
	object {Orrery_Sun_Object}
#end

#local Orrery_SunText = text
{
	ttf "crystal.ttf", "Sol", 0.001, <0,0>
	scale Orrery_TextSize
	#if (Orrery_DecoMode = 1)
		pigment {color srgb 3/4}
		finish {ambient 0 diffuse 0 emission 1}
	#elseif (Orrery_DecoMode = 2)
		pigment {color srgb 0}
	#end
	no_shadow
}

#local Orrery_SunCoo3D			= <0,0,0>;
#local Orrery_SunCoo2D			= Get_Screen_XY(Orrery_SunCoo3D);
#local Orrery_SunCoo2D			= Orrery_SunCoo2D/<image_width,image_height>;
#local Orrery_SunCoo2D			= <Orrery_SunCoo2D.x,1-Orrery_SunCoo2D.y>;
Screen_Object(Orrery_SunText, Orrery_SunCoo2D + <0.01,0.01>, 0, false, 0.01)


//------------------------------------------------------------------------------
// OVERLAY TEXT


#local Orrery_DayString = concat("JD ", str(Orrery_StopDate,0,1));
#local Orrery_DayText = text
{
	ttf "crystal.ttf", Orrery_DayString, 0.001, <0,0>
	scale Orrery_TextSize
	#if (Orrery_DecoMode = 1)
		pigment {color srgb 3/4}
		finish {ambient 0 diffuse 0 emission 1}
	#elseif (Orrery_DecoMode = 2)
		pigment {color srgb 0}
	#end
	no_shadow
}

Screen_Object(Orrery_DayText, <0.68,0.02>, <0.02,0.02>, false, 0.01)


//------------------------------------------------------------------------------
// LIGHTS


#switch (Orrery_Light_Mode)
	// area light (slow)
	#case (2)
		light_source
		{
			0
			Orrery_Light_Color*2
			area_light
			x * Orrery_Sun_Radius * 2, y * Orrery_Sun_Radius * 2	// lights spread out across this distance (x * z)
			5, 5													// total number of lights in grid (4x*4z = 16 lights)
			adaptive 1												// 0,1,2,3...
			jitter													// adds random softening of light
			circular												// make the shape of the light circular
			orient													// orient light
			area_illumination on
			looks_like {Orrery_Sun_Object}
		}
	#break
	// point light (not slow)
	#case (3)
		light_source
		{
			0
			Orrery_Light_Color
			looks_like {Orrery_Sun_Object}
		}
	#break
	// exterior lights
	#case (4)
		light_source
		{
			<-1,+1,+1,> * 100
			color rgb	1
			rotate -y * 15
			parallel
			point_at 0
//			shadowless
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
	#break
#end
