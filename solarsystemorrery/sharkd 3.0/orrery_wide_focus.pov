// Caption: SolarSystemOrrery
// Version: 3.0 alpha
// Authors: Michael Horvath
// Website: http://isometricland.net
// Created: 2018-09-13
// Updated: 2018-09-28
// This file is licensed under the terms of the CC-LGPL.
// http://www.gnu.org/licenses/lgpl-2.1.html
// Orbital formulas and elements from "aprx_pos_planets.pdf"
// Rotational formulas from "burmeister_steffi.pdf"
// Rotational elements from "WGCCRE2009reprint.pdf"
// Matrices solved/converted using https://www.symbolab.com/solver/matrix-vector-calculator
// Requires Solar System Scope textures at https://www.solarsystemscope.com/textures/
// Requires "Open Sans" font by Steve Matteson.


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

#declare Orrery_PlanetsFocus		= -1;					// number of planet or -1 to disable
#declare Orrery_PlanetsNumber		= 8;					// 8 currently
#declare Orrery_DecoMode			= 1;					// 1 = black; 2 = gray
#declare Orrery_InnerOuter			= 1;					// 1 = inner planets; 2 = outer planets
#declare Orrery_SunRadius			= 696000;				// km
#declare Orrery_AU					= 149597870.691;		// km
#declare Orrery_EccentricityMulti	= 1;					// not used currrently
#declare Orrery_InclinationMulti	= 1;					// not used currrently
#declare Orrery_Radiosity			= true;
#declare Orrery_CameraMode			= 2;					// 1 = perspective; 2 = orthographic
#declare Orrery_BitmapTextures		= true;
#declare Orrery_TextSize			= 0.04;
#declare Orrery_TextFont			= "OpenSans-Regular.ttf";
#declare Orrery_Animation			= false;					// true or false
#declare Orrery_LightLumens			= 2;
#declare Orrery_LightTemp			= Daylight(5800);
#declare Orrery_LightColor			= Light_Color(Orrery_LightTemp,Orrery_LightLumens);
#declare Orrery_J2000_Obliquity		= 23.43928;					// deg, obliquity of Earth pole axis
#declare Orrery_J2000_Date			= 2451545.0;				// Julian days, January 1, 2000, at 12h TT
#declare Orrery_MarkerShow			= false;					// true or false

#if (Orrery_InnerOuter = 1)
	#declare Orrery_SceneScale			= 4/2;															// multiplier
	#declare Orrery_MeanRadiusMulti		= 1024;															// multiplier
	#declare Orrery_LineThickness		= 1/32;															// AU
//	#declare Orrery_LineThickness		= Orrery_SceneScale * 1/40;										// AU
//	#declare Orrery_StartDate			= 2458198.177083;												// a. Julian days, A.D. 2018 Mar 20 (Earth vernal equinox)
//	#declare Orrery_StartDate			= 2458384.579167;												// b. Julian days, A.D. 2018 Sep 23, 01:54:00.0 (Earth autumnal equinox)
	#declare Orrery_StartDate			= 2458290.921528;												// c. Julian days, A.D. 2018 Jun 21 (Earth northern solstice)
//	#declare Orrery_StartDate			= 2458306.199306;												// d. Julian days, A.D. 2018 Jul 06, 16:47:00.0 (Earth aphelion)
	#if (Orrery_Animation = true)
		#declare Orrery_StopDate		= Orrery_StartDate + clock * 364.840045525330;					// Julian days, timespan of one Earth year
	#else
//		#declare Orrery_StopDate		= 2458384.579167;												// a. Julian days, A.D. 2018 Sep 23 (Earth autumnal equinox)
//		#declare Orrery_StopDate		= 2458563.415278;												// b. Julian days, A.D. 2019 Mar 20 (Earth vernal equinox)
		#declare Orrery_StopDate		= 2458474.432639;												// c. Julian days, A.D. 2018 Dec 21 (Earth southern solstice)
//		#declare Orrery_StopDate		= 2458486.722222;												// d. Julian days, A.D. 2019 Jan 03, 05:19:60.0 (Earth perihelion)
//		#declare Orrery_StopDate		= 2458383.500000;												// e. Julian days, A.D. 2018 Sep 22, 00:00:00.0
//		#declare Orrery_StopDate		= 2458384.579167;												// f. Julian days, A.D. 2018 Sep 23, 01:54:00.0 (Earth autumnal equinox)
//		#declare Orrery_StopDate		= 2451545.000000;												// g. Julian days, A.D. 2000 Jan 01, 12 hours TDB (J2000.0 epoch)
	#end
	#declare Orrery_LightRadius			= Orrery_SunRadius/Orrery_AU * Orrery_SceneScale * 8;			// AU
	#declare Orrery_RingDistance		= 1/2;															// AU
	#declare Orrery_TrailRadius			= Orrery_SceneScale/256;										// AU
#elseif (Orrery_InnerOuter = 2)
	#declare Orrery_SceneScale			= 16 * 3/2;														// multiplier
	#declare Orrery_MeanRadiusMulti		= 1024 * 2;														// multiplier
	#declare Orrery_LineThickness		= 1/32 * 8;														// AU
//	#declare Orrery_LineThickness		= Orrery_SceneScale * 1/40;										// AU
//	#declare Orrery_StartDate			= 2455638.782232;												// a. Julian days, A.D. 2011 Mar 18, 06:46:24.8 (Jupiter perihelion)
	#declare Orrery_StartDate			= 2457801.804167;												// b. Julian days, A.D. 2017 Feb 17, 07:18:00.0 (Jupiter aphelion)
	#if (Orrery_Animation = true)
		#declare Orrery_StopDate		= Orrery_StartDate + clock * 4331.67549980859;					// Julian days, timespan of one Jovian year
	#else
//		#declare Orrery_StopDate		= 2459966.069370;												// a. Julian days, A.D. 2023 Jan 21, 13:39:53.6 (Jupiter perihelion)
		#declare Orrery_StopDate		= 2462132.613194;												// b. Julian days, A.D. 2028 Dec 27, 02:42:60.0 (Jupiter aphelion)
//		#declare Orrery_StopDate		= 2458383.500000;												// c. Julian days, A.D. 2018 Sep 22, 00:00:00.0
	#end
	#declare Orrery_LightRadius			= Orrery_SunRadius/Orrery_AU * Orrery_SceneScale * 8;			// AU
	#declare Orrery_RingDistance		= 4;															// AU
	#declare Orrery_TrailRadius			= Orrery_SceneScale/256;										// AU
#end

#if (Orrery_DecoMode = 1)
	#declare Orrery_LightMode = 2;
#elseif (Orrery_DecoMode = 2)
	#declare Orrery_LightMode = 4;
#end

#debug "\n"
#debug concat("Orrery_StartDate = ", str(Orrery_StartDate, 0, -1), "\n")
#debug concat("Orrery_StopDate = ", str(Orrery_StopDate, 0, -1), "\n")
#debug "\n"


//------------------------------------------------------------------------------
// CAMERA


#declare Orrery_Camera_Horizontal	= -30;			// -asind(tand(30));
#declare Orrery_Camera_Vertical		= 45;			// 45;
#declare Orrery_Camera_Aspect		= image_height/image_width;
#declare Orrery_Camera_Distance		= 4;			// was 32
#declare Orrery_Camera_Rotate		= <Orrery_Camera_Horizontal,0,Orrery_Camera_Vertical>;
#declare Orrery_Camera_Translate	= <0,0,0>;
#declare Orrery_Camera_Up			= +z * 2 * Orrery_Camera_Aspect;
#declare Orrery_Camera_Right		= +x * 2;
#declare Orrery_Camera_Location		= -y * Orrery_Camera_Distance;
#declare Orrery_Camera_Direction	= +y * Orrery_Camera_Distance;
#declare Orrery_Camera_Transform = transform
{
	rotate		Orrery_Camera_Rotate
	scale		Orrery_SceneScale
	translate	Orrery_Camera_Translate
}

#if (Orrery_CameraMode = 1)
	Set_Camera_Orthographic(false)
	Set_Camera_Transform(Orrery_Camera_Transform)
	Set_Camera_Alt(Orrery_Camera_Location, Orrery_Camera_Direction, Orrery_Camera_Right, Orrery_Camera_Up)
#elseif (Orrery_CameraMode = 2)
	Set_Camera_Orthographic(true)
	Set_Camera_Transform(Orrery_Camera_Transform)
	Set_Camera_Alt(Orrery_Camera_Location, Orrery_Camera_Direction, Orrery_Camera_Right, Orrery_Camera_Up)
#end


//------------------------------------------------------------------------------
// MISC. GRAPHICAL SETTINGS


global_settings
{
	#if (Orrery_Radiosity = true)
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
// BLAH





//------------------------------------------------------------------------------
// PLANET ROTATIONS


#declare Orrery_d = Orrery_StopDate;								// Julian day
#declare Orrery_T = Orrery_d / 36525;								// Julian century
#declare Orrery_Alpha_0 = array[Orrery_PlanetsNumber]				// right ascension
#declare Orrery_Delta_0 = array[Orrery_PlanetsNumber]				// declination
#declare Orrery_W = array[Orrery_PlanetsNumber]						// PMO

#debug "\n"
#debug concat("Orrery_d = ", str(Orrery_d, 0, -1), "\n")
#debug concat("Orrery_T = ", str(Orrery_T, 0, -1), "\n")
#debug "\n"

// Mercury
#declare Orrery_M1 = 174.791086 + 4.092335 * Orrery_d;
#declare Orrery_M2 = 349.582171 + 8.184670 * Orrery_d;
#declare Orrery_M3 = 164.373257 + 12.277005 * Orrery_d;
#declare Orrery_M4 = 339.164343 + 16.369340 * Orrery_d;
#declare Orrery_M5 = 153.955429 + 20.461675 * Orrery_d;
#declare Orrery_Alpha_0[0] = 281.0097 - 0.0328 * Orrery_T;
#declare Orrery_Delta_0[0] = 61.4143 - 0.0049 * Orrery_T;
#declare Orrery_W[0] = 329.5469 + 6.1385025 * Orrery_d + 0.00993822 * sind(Orrery_M1) - 0.00104581 * sind(Orrery_M2) - 0.00010280 * sind(Orrery_M3) - 0.00002364 * sind(Orrery_M4) - 0.00000532 * sind(Orrery_M5);

// Venus
#declare Orrery_Alpha_0[1] = 272.76;
#declare Orrery_Delta_0[1] = 67.16;
#declare Orrery_W[1] = 160.20 - 1.4813688 * Orrery_d;

// Earth
#declare Orrery_Alpha_0[2] = 0.00 - 0.641 * Orrery_T;
#declare Orrery_Delta_0[2] = 90.00 - 0.557 * Orrery_T;
#declare Orrery_W[2] = 190.147 + 360.9856235 * Orrery_d;

// Mars
#declare Orrery_Alpha_0[3] = 317.68143 - 0.1061 * Orrery_T;
#declare Orrery_Delta_0[3] = 52.88650 - 0.0609 * Orrery_T;
#declare Orrery_W[3] = 176.630 + 350.89198226 * Orrery_d;

// Jupiter
#declare Orrery_Ja = 99.360714 + 4850.4046 * Orrery_T;
#declare Orrery_Jb = 175.895369 + 1191.9605 * Orrery_T;
#declare Orrery_Jc = 300.323162 + 262.5475 * Orrery_T;
#declare Orrery_Jd = 114.012305 + 6070.2476 * Orrery_T;
#declare Orrery_Je = 49.511251 + 64.3000 * Orrery_T;
#declare Orrery_Alpha_0[4] = 268.056595 - 0.006499 * Orrery_T + 0.000117 * sind(Orrery_Ja) + 0.000938 * sind(Orrery_Jb) + 0.001432 * sind(Orrery_Jc) + 0.000030 * sind(Orrery_Jd) + 0.002150 * sind(Orrery_Je);
#declare Orrery_Delta_0[4] = 64.495303 + 0.002413 * Orrery_T + 0.000050 * cosd(Orrery_Ja) + 0.000404 * cosd(Orrery_Jb) + 0.000617 * cosd(Orrery_Jc) - 0.000013 * cosd(Orrery_Jd) + 0.000926 * cosd(Orrery_Je);
#declare Orrery_W[4] = 284.95 + 870.5360000 * Orrery_d;

// Saturn
#declare Orrery_Alpha_0[5] = 40.589 - 0.036 * Orrery_T;
#declare Orrery_Delta_0[5] = 83.537 - 0.004 * Orrery_T;
#declare Orrery_W[5] = 38.90 + 810.7939024 * Orrery_d;

// Uranus
#declare Orrery_Alpha_0[6] = 257.311;
#declare Orrery_Delta_0[6] = -15.175;
#declare Orrery_W[6] = 203.81 - 501.1600928 * Orrery_d;

// Neptune
#declare Orrery_N = 357.85 + 52.316 * Orrery_T;
#declare Orrery_Alpha_0[7] = 299.36 + 0.70 * sind(Orrery_N);
#declare Orrery_Delta_0[7] = 43.46 - 0.51 * cosd(Orrery_N);
#declare Orrery_W[7] = 253.18 + 536.3128492 * Orrery_d - 0.48 * sind(Orrery_N);



//------------------------------------------------------------------------------
// PLANET ORBITS

#declare Orrery_PlanetName					= array[Orrery_PlanetsNumber]	{"Mercury",			"Venus",			"Earth",			"Mars",				"Jupiter",			"Saturn",			"Uranus",			"Neptune"}				// string
#declare Orrery_MeanRadius					= array[Orrery_PlanetsNumber]	{2439.00000000,		6051.80000000,		6371.00000000,		3389.90000000,		69911.00000000,		58232.00000000,		25362.00000000,		24624.00000000}			// km
#declare Orrery_OrbitalPeriod				= array[Orrery_PlanetsNumber]	{87.9690017344257,	224.699143682606,	364.840045525330,	687.012184509975,	4331.67549980859,	10767.4799006351,	30677.7150878657,	60173.0097300372}		// days, not used
#declare Orrery_RotationPeriod				= array[Orrery_PlanetsNumber]	{58.646,			-243.025,			0.99726968,			1.025957,			0.41354166666667,	0.43958333333333,	-0.71833,			0.6713}					// days, not used
#declare Orrery_AxialTilt					= array[Orrery_PlanetsNumber]	{0.034,				177.36,				23.4392811,			25.19,				3.13,				26.73,				97.77,				28.32}					// deg, not used
#declare Orrery_Color						= array[Orrery_PlanetsNumber]	{<115,115,115>,		<237,197,135>,		<030,059,117>,		<219,097,058>,		<179,158,131>,		<220,193,148>,		<164,213,220>,		<057,087,183>}			// 0..255
#if (Orrery_InnerOuter = 1)
	#declare Orrery_ShowPlanet					= array[Orrery_PlanetsNumber]	{true,				true,				true,				true,				false,				false,				false,				false}					// true or false
#elseif (Orrery_InnerOuter = 2)
	#declare Orrery_ShowPlanet					= array[Orrery_PlanetsNumber]	{false,				false,				false,				false,				true,				true,				true,				true}					// true or false
#end
#declare Orrery_ShowPaths					= array[Orrery_PlanetsNumber]	{true,				true,				true,				true,				true,				true,				true,				true}					// true or false
#declare Orrery_Textures					= array[Orrery_PlanetsNumber]	{"2k_mercury.jpg",	"2k_venus_atmosphere.jpg",	"2k_earth_combined.jpg",	"2k_mars.jpg",	"2k_jupiter.jpg",	"2k_saturn.jpg",	"2k_uranus.jpg",	"2k_neptune.jpg"}		// filename

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
	#local Orrery_MarkerLength = Orrery_Temp_MultiMeanRadius * 2;
	#local Orrery_MarkerRadius = Orrery_Temp_MultiMeanRadius * 0.025;
	#local Orrery_MarkerArrLen = Orrery_MarkerLength * 1.125;
	#local Orrery_SphereColor = Orrery_Color[Orrery_i]/255;
	#local Orrery_SphereFinish = finish {}
//	#local Orrery_SphereFinish = finish {ambient 0 diffuse 1 emission 16/128}			//1/128

	#local Orrery_Temp_TValue						= (Orrery_LastDate - Orrery_J2000_Date)/36525;			// number of centuries past J2000.0

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

	#local Orrery_SphereCoo3D = <Orrery_Temp_Xecl_c,Orrery_Temp_Yecl_c,Orrery_Temp_Zecl_c>;
	#local Orrery_SphereCoo2D = Get_Screen_XY(Orrery_SphereCoo3D);
	#local Orrery_SphereCoo2D = Orrery_SphereCoo2D/<image_width,image_height>;
	#local Orrery_SphereCoo2D = <Orrery_SphereCoo2D.x,1-Orrery_SphereCoo2D.y>;

	#local Orrery_SphereRotate = transform
	{
		#switch (Orrery_i)
			#case (2)
				rotate +z * -31			// earth
			#break
			#case (7)
				rotate -z * 200			// neptune
			#break
		#end
		rotate +z * Orrery_W[Orrery_i]
		rotate +x * (90-Orrery_Delta_0[Orrery_i])
		rotate +z * (90+Orrery_Alpha_0[Orrery_i])
		rotate +x * -Orrery_J2000_Obliquity
		#switch (Orrery_i)
			#case (2)
				rotate +z * 100			// earth
			#break
		#end
	}

	union
	{
		sphere
		{
			0
			Orrery_Temp_MultiMeanRadius
			#if (Orrery_BitmapTextures = true)
				texture
				{
					pigment
					{
						image_map
						{
							jpeg Orrery_Textures[Orrery_i]
							map_type 1
						}
						scale <-1,1,1>
						rotate +x * 90
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
		}

		// body frame markers
		#if (Orrery_MarkerShow = true)
			union
			{
				cylinder
				{
					0, x * Orrery_MarkerLength, Orrery_MarkerRadius
					pigment {color srgb x}
					finish {ambient 0 diffuse 0 emission 1}
				}
				cone
				{
					x * Orrery_MarkerLength, Orrery_MarkerRadius * 3, x * Orrery_MarkerArrLen, 0
					pigment {color srgb x}
					finish {ambient 0 diffuse 0 emission 1}
				}
				cylinder
				{
					0, y * Orrery_MarkerLength, Orrery_MarkerRadius
					pigment {color srgb y}
					finish {ambient 0 diffuse 0 emission 1}
				}
				cone
				{
					y * Orrery_MarkerLength, Orrery_MarkerRadius * 3, y * Orrery_MarkerArrLen, 0
					pigment {color srgb y}
					finish {ambient 0 diffuse 0 emission 1}
				}
				cylinder
				{
					0, z * Orrery_MarkerLength, Orrery_MarkerRadius
					pigment {color srgb z}
					finish {ambient 0 diffuse 0 emission 1}
				}
				cone
				{
					z * Orrery_MarkerLength, Orrery_MarkerRadius * 3, z * Orrery_MarkerArrLen, 0
					pigment {color srgb z}
					finish {ambient 0 diffuse 0 emission 1}
				}
				no_shadow
			}
		#end

		// Saturn's rings
		#if (Orrery_i = 5)
			#local Orrery_Ring_Inner = Orrery_Temp_MultiMeanRadius + 7000/Orrery_AU * Orrery_MeanRadiusMulti;
			#local Orrery_Ring_Outer = Orrery_Temp_MultiMeanRadius + 80000/Orrery_AU * Orrery_MeanRadiusMulti;
			disc
			{
				0, z, Orrery_Ring_Outer, Orrery_Ring_Inner
				texture
				{
					pigment
					{
						image_map
						{
							png "2k_saturn_ring_alpha.png"
							map_type 0
						}
						translate x * Orrery_Ring_Inner
						scale <-1,1,1>
						rotate +x * 90
						warp
						{
							cylindrical 
							orientation y 
							dist_exp 0
						}
					}
					finish {Orrery_SphereFinish}
				}
			}
		#end

		transform {Orrery_SphereRotate}
		translate Orrery_SphereCoo3D

		no_shadow
	}

	// ecliptic frame markers
	#if (Orrery_MarkerShow = true)
		union
		{
			cylinder
			{
				0, x * Orrery_MarkerLength, Orrery_MarkerRadius
				pigment {color srgb x/4}
				finish {ambient 0 diffuse 1 emission 1/2}
			}
			cone
			{
				x * Orrery_MarkerLength, Orrery_MarkerRadius * 3, x * Orrery_MarkerArrLen, 0
				pigment {color srgb x/4}
				finish {ambient 0 diffuse 1 emission 1/2}
			}
			cylinder
			{
				0, y * Orrery_MarkerLength, Orrery_MarkerRadius
				pigment {color srgb y/4}
				finish {ambient 0 diffuse 1 emission 1/2}
			}
			cone
			{
				y * Orrery_MarkerLength, Orrery_MarkerRadius * 3, y * Orrery_MarkerArrLen, 0
				pigment {color srgb y/4}
				finish {ambient 0 diffuse 1 emission 1/2}
			}
			cylinder
			{
				0, z * Orrery_MarkerLength, Orrery_MarkerRadius
				pigment {color srgb z/4}
				finish {ambient 0 diffuse 1 emission 1/2}
			}
			cone
			{
				z * Orrery_MarkerLength, Orrery_MarkerRadius * 3, z * Orrery_MarkerArrLen, 0
				pigment {color srgb z/4}
				finish {ambient 0 diffuse 1 emission 1/2}
			}
			translate Orrery_SphereCoo3D
			no_shadow
		}
	#end

	// focus on planet
	#if (Orrery_i = Orrery_PlanetsFocus)
		#local Orrery_SphereFocus_Transform = transform
		{
			transform {Orrery_Camera_Transform}
			translate Orrery_SphereCoo3D
		}
		Set_Camera_Transform(Orrery_SphereFocus_Transform)
	#end

	#local Orrery_PlanetText = text
	{
		ttf Orrery_TextFont, Orrery_PlanetName[Orrery_i], 0.001, <0,0>
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

/*
	#debug "\n"
	#debug concat(Orrery_PlanetName[Orrery_i], "\n")
	#debug concat("SemiMajorAxis (AU) = ", str(Orrery_Temp_SemiMajorAxis, 0, -1), "\n")
	#debug concat("Eccentricity (0..1) = ", str(Orrery_Temp_Eccentricity, 0, -1), "\n")
	#debug concat("Inclination (deg) = ", str(Orrery_Temp_Inclination, 0, -1), "\n")
	#debug concat("MeanLongitude (deg) = ", str(Orrery_Temp_MeanLongitude, 0, -1), "\n")
	#debug concat("mod(MeanLongitude,360) (deg) = ", str(mod(Orrery_Temp_MeanLongitude,360), 0, -1), "\n")
	#debug concat("LongitudeOfPerihelion (deg) = ", str(Orrery_Temp_LongitudeOfPerihelion, 0, -1), "\n")
	#debug concat("LongitudeOfAscendingNode (deg) = ", str(Orrery_Temp_LongitudeOfAscendingNode, 0, -1), "\n")
	#debug concat("ArgumentOfPerihelion (deg) = ", str(Orrery_Temp_ArgumentOfPerihelion, 0, -1), "\n")
	#debug concat("MeanAnomaly (deg) = ", str(Orrery_Temp_MeanAnomaly, 0, -1), "\n")
	#debug concat("EccentricAnomaly (deg) = ", str(Orrery_Temp_EccentricAnomaly, 0, -1), "\n")
	#debug concat("Location (AU) = <", vstr(3, Orrery_SphereCoo3D, ",", 0, -1), ">\n")
	#debug concat("W (deg) = ", str(Orrery_W[Orrery_i], 0, -1), "\n")
	#debug concat("mod(W,360) (deg) = ", str(mod(Orrery_W[Orrery_i],360),0,-1), "\n")
	#debug concat("90-delta_0 (deg) = ", str(90-Orrery_Delta_0[Orrery_i], 0, -1), "\n")
	#debug concat("90+alpha_0 (deg) = ", str(90+Orrery_Alpha_0[Orrery_i], 0, -1), "\n")
	#debug "\n"
*/
#end

#macro Orrery_TracePath(Orrery_i, Orrery_FirstDate, Orrery_LastDate, Orrery_StepSize)
	#local Orrery_Temp_MultiMeanRadius = Orrery_MeanRadius[Orrery_i] / Orrery_AU * Orrery_MeanRadiusMulti;
//	#local Orrery_Temp_MultiMeanRadius = 0.1;
	#local Orrery_SphereColor = Orrery_Color[Orrery_i]/255;
//	#local Orrery_SphereFinish = finish {}
	#local Orrery_SphereFinish = finish {ambient 0 diffuse 0 emission 1}
//	#local Orrery_TrailRadius = Orrery_Temp_MultiMeanRadius/4;

	#local Orrery_StepsNum = floor((Orrery_LastDate - Orrery_FirstDate) / Orrery_StepSize);
	#for (Orrery_j, 0, Orrery_StepsNum - 1, 1)
		#local Orrery_StepDate							= Orrery_FirstDate + Orrery_j * Orrery_StepSize;
		#local Orrery_Temp_TValue						= (Orrery_StepDate - Orrery_J2000_Date)/36525;			// number of centuries past J2000.0
	
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

		#local Orrery_SphereCoo3D = <Orrery_Temp_Xecl_c,Orrery_Temp_Yecl_c,Orrery_Temp_Zecl_c>;
		#local Orrery_SphereCoo2D = Get_Screen_XY(Orrery_SphereCoo3D);
		#local Orrery_SphereCoo2D = Orrery_SphereCoo2D/<image_width,image_height>;
		#local Orrery_SphereCoo2D = <Orrery_SphereCoo2D.x,1-Orrery_SphereCoo2D.y>;
	
		sphere
		{
			0
			Orrery_TrailRadius
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
	#if (true = true)
		Orrery_PlaceSphere(Orrery_i, Orrery_StopDate)
		#if (Orrery_ShowPaths[Orrery_i] = true)
			#if (Orrery_InnerOuter = 1)
				Orrery_TracePath(Orrery_i, Orrery_StartDate, Orrery_StopDate, 1)
			#elseif (Orrery_InnerOuter = 2)
				Orrery_TracePath(Orrery_i, Orrery_StartDate, Orrery_StopDate, 100)
			#end
		#end
	#end
#end


//------------------------------------------------------------------------------
// ECLIPTIC MARKER PLANE


#declare Orrery_Ecliptic_Pattern = union
{
	#local Orrery_Ecliptic_Steps = 128;
	#for (i, Orrery_RingDistance, Orrery_Ecliptic_Steps, Orrery_RingDistance)
		difference
		{
			cylinder {-y * 1, +y * 1, i + Orrery_LineThickness/2}
			cylinder {-y * 2, +y * 2, i - Orrery_LineThickness/2}
		}
	#end
	#local Orrery_Ecliptic_Steps = 4;
	#local Orrery_Ecliptic_Angle = 360/Orrery_Ecliptic_Steps;
	#for (i, 1, Orrery_Ecliptic_Steps)
		cylinder
		{
			0, +x * 48, Orrery_LineThickness/2
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
	rotate +x * 90
}


//------------------------------------------------------------------------------
// SUN


#declare Orrery_Sun_Object = sphere
{ 
	0, Orrery_LightRadius
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
				emission Orrery_LightColor/Orrery_LightRadius
				density
				{
					spherical
					density_map
					{
						[0.0 rgb 0]
						[0.1 rgb 1]
						[1.0 rgb 1]
					}
					scale Orrery_LightRadius
				}
			}
		}
	}
	no_shadow
}

#if (Orrery_LightMode != 2)
	object {Orrery_Sun_Object}
#end

#local Orrery_SunText = text
{
	ttf Orrery_TextFont, "Sol", 0.001, <0,0>
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
	ttf Orrery_TextFont Orrery_DayString, 0.001, <0,0>
	scale Orrery_TextSize
	#if (Orrery_DecoMode = 1)
		pigment {color srgb 3/4}
		finish {ambient 0 diffuse 0 emission 1}
	#elseif (Orrery_DecoMode = 2)
		pigment {color srgb 0}
	#end
	no_shadow
}

Screen_Object(Orrery_DayText, <0.74,0.02>, <0.02,0.02>, false, 0.01)


//------------------------------------------------------------------------------
// LIGHTS


#switch (Orrery_LightMode)
	// area light (slow)
	#case (2)
		light_source
		{
			0
			Orrery_LightColor*2
			area_light
			x * Orrery_LightRadius * 2, y * Orrery_LightRadius * 2	// lights spread out across this distance (x * z)
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
			Orrery_LightColor
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


//------------------------------------------------------------------------------
// GUIDES


#if (Orrery_MarkerShow = true)
	union
	{
		cylinder
		{
			0, x * 8, 0.01
			pigment {color srgb x transmit 0}
			finish {ambient 0 diffuse 0 emission 1}
		}
		cylinder
		{
			0, y * 8, 0.01
			pigment {color srgb y transmit 0}
			finish {ambient 0 diffuse 0 emission 1}
		}
		cylinder
		{
			0, z * 8, 0.01
			pigment {color srgb z transmit 0}
			finish {ambient 0 diffuse 0 emission 1}
		}
		no_shadow
		no_reflection
	}
#end
