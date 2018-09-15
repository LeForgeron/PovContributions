// Caption: Orrery
// Version: 1.0
// Authors: Michael Horvath
// Website: http://isometricland.net
// Created: 2018-09-13
// Updated: 2018-09-15
// This file is licensed under the terms of the CC-LGPL.
// http://www.gnu.org/licenses/lgpl-2.1.html

#include "screen.inc"			// Requires the updated version available here: http://news.povray.org/povray.text.scene-files/thread/%3C581be4f1%241%40news.povray.org%3E/
#include "CIE.inc"				// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "lightsys.inc"			// http://www.ignorancia.org/en/index.php?page=Lightsys
#include "math.inc"
#include "transforms.inc"


//------------------------------------------------------------------------------
// PARAMETERS


#declare Orrery_PlanetsNumber		= 8;
#declare Orrery_StartDate			= 2458376.5;			// days, A.D. 2018 Sep 15
//#declare Orrery_StopDate			= Orrery_StartDate + clock * 364.840045525330;		// days, animation
#declare Orrery_StopDate			= Orrery_StartDate + 87.9690017344257;				// days, static
#declare Orrery_ReferenceDate		= 2455376.5;			// days
#declare Orrery_SunRadius			= 696000;				// km
#declare Orrery_AU					= 149597870.691;		// km
#declare Orrery_EccentricityMulti	= 1;
#declare Orrery_InclinationMulti	= 1;
#declare Orrery_MeanRadiusMulti		= 1000;
#declare Orrery_MultiSunRadius		= Orrery_SunRadius / Orrery_AU * Orrery_MeanRadiusMulti / 100;		// km
#declare Orrery_Hidden				= true;
#declare Orrery_Constructs			= true;

#declare Orrery_Toggle_Radiosity		= true;
#declare Orrery_Camera_Mode				= 1;
#declare Orrery_Light_Mode				= 1;
#declare Orrery_Sun_Radius				= Orrery_MultiSunRadius;
#declare Orrery_Light_Area_Radius		= Orrery_MultiSunRadius;
#declare Orrery_Light_Area_Theta_Num	= 6;
#declare Orrery_Light_Area_Theta_Dif	= 2 * pi/Orrery_Light_Area_Theta_Num;
#declare Orrery_Light_Area_Phi_Num		= 6;
#declare Orrery_Light_Area_Phi_Dif		= pi/Orrery_Light_Area_Phi_Num;
#declare Orrery_Light_Area_Lumens		= 2/Orrery_Light_Area_Theta_Num/Orrery_Light_Area_Phi_Num;
#declare Orrery_Light_Area_Temp			= Daylight(5800);
#declare Orrery_Light_Area_Color		= Light_Color(Orrery_Light_Area_Temp,Orrery_Light_Area_Lumens);

#declare Orrery_Light_Point_Lumens		= 2;
#declare Orrery_Light_Point_Temp		= Daylight(5800);
#declare Orrery_Light_Point_Color		= Light_Color(Orrery_Light_Point_Temp,Orrery_Light_Point_Lumens);


//------------------------------------------------------------------------------
// CAMERA


#declare Orrery_Camera_Vertical		= 45;			//45;
#declare Orrery_Camera_Horizontal	= 30;			//asind(tand(30));
#declare Orrery_Camera_Aspect		= image_height/image_width;
#declare Orrery_Camera_Distance		= 10;
#declare Orrery_Camera_Rotate		= <Orrery_Camera_Horizontal,Orrery_Camera_Vertical,0,>;
#declare Orrery_Camera_Scale		= 1.8;
#declare Orrery_Camera_Translate	= <0,0,0>;
#declare Orrery_Camera_Up			= +y * 2 * Orrery_Camera_Aspect;
#declare Orrery_Camera_Right		= +x * 2;
#declare Orrery_Camera_Location		= -z * Orrery_Camera_Distance;
#declare Orrery_Camera_Direction	= +z * Orrery_Camera_Distance;
#declare Orrery_Camera_Transform = transform
{
	rotate		Orrery_Camera_Rotate
	scale		Orrery_Camera_Scale
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

background {color rgb 1/2}


sky_sphere
{
	pigment
	{
		bozo
		color_map
		{
			[0.0 color rgb 1]
			[0.2 color rgb 0]
			[1.0 color rgb 0]
		}
		scale 1e-4
	}
}


//------------------------------------------------------------------------------
// PLANETS

#declare Orrery_PlanetName					= array[Orrery_PlanetsNumber]	{"Mercury",			"Venus",				"Earth",				"Mars",				"Jupiter",			"Saturn",			"Uranus",			"Neptune"}				// string
#declare Orrery_MeanRadius					= array[Orrery_PlanetsNumber]	{2439.00000000000,	6051.80000000000,		6371.00000000000,		3389.90000000000,	69911.0000000000,	58232.0000000000,	25362.0000000000,	24624.0000000000}		// km
#declare Orrery_Eccentricity				= array[Orrery_PlanetsNumber]	{0.205620000000000,	0.00681000000000001,	0.0174500000000000,		0.0933100000000001,	0.0487700172393226,	0.0543567124395717,	0.0474181287155161,	0.00867613156526848}	// 0..1
#declare Orrery_PeriapsisDistance			= array[Orrery_PlanetsNumber]	{0.307500000000000,	0.718400000000001,		0.981800000000001,		1.38155607491481,	4.94428800019439,	9.02556880140891,	18.2765360029404,	29.8027416187573}		// AU
#declare Orrery_Inclination					= array[Orrery_PlanetsNumber]	{7.00437000000001,	3.39449000000000,		0.00265000000000000,	1.84890000000000,	1.30471529390000,	2.48627960990000,	0.772208056400001,	1.77363184250000}		// deg
#declare Orrery_LongitudeOfAscendingNode	= array[Orrery_PlanetsNumber]	{48.3175000000001,	76.6503600000001,		125.106850000000,		49.5243100000001,	100.512620913600,	113.580108269500,	73.9887836759001,	131.812865345800}		// deg
#declare Orrery_ArgumentOfPerifocus			= array[Orrery_PlanetsNumber]	{29.1531600000000,	54.8862100000001,		338.168880000000,		286.588600000000,	273.863659279900,	339.012583100900,	97.0984503626001,	274.763059227300}		// deg
#declare Orrery_TimeOfPeriapsis				= array[Orrery_PlanetsNumber]	{2455372.93755000,	2455333.42831000,		2455200.63690000,		2455630.00590000,	2455636.98729551,	2452815.05701155,	2470111.02681989,	2468542.30107738}		// Julian Date
#declare Orrery_MeanMotion					= array[Orrery_PlanetsNumber]	{4.09235000000000,	1.60214000000000,		0.986730000000001,		0.524010000000001,	0.0831087186000001,	0.0334340072000000,	0.0117349026000000,	0.00598274880000001}	// deg/day
#declare Orrery_MeanAnomaly					= array[Orrery_PlanetsNumber]	{14.5787800000000,	69.0069800000001,		173.530063432941,		227.160840000000,	338.351234669700,	85.6393031936001,	187.091762213400,	281.232319787200}		// deg
#declare Orrery_TrueAnomaly					= array[Orrery_PlanetsNumber]	{22.4135700000000,	69.7378700000001,		173.750630000000,		219.916960000000,	336.166514350700,	91.8700282165001,	186.458277094000,	280.255135189300}		// deg
#declare Orrery_SemiMajorAxis				= array[Orrery_PlanetsNumber]	{0.387100000000000,	0.723330000000001,		0.999240000000001,		1.52373948563770,	5.19778401627436,	9.54436934110015,	19.1863151650114,	30.0635771696034}		// AU
#declare Orrery_ApoapsisDistance			= array[Orrery_PlanetsNumber]	{0.466690000000000,	0.728260000000001,		1.01667932374362,		1.66592289636059,	5.45128003235434,	10.0631698807914,	20.0960943270823,	30.3244127204495}		// AU
#declare Orrery_OrbitalPeriod				= array[Orrery_PlanetsNumber]	{87.9690017344257,	224.699143682606,		364.840045525330,		687.012184509975,	4331.67549980859,	10767.4799006351,	30677.7150878657,	60173.0097300372}		// days
#declare Orrery_ColorR						= array[Orrery_PlanetsNumber]	{115,				222,					28,						135,				255,				204,				153,				102}					// 0..255
#declare Orrery_ColorG						= array[Orrery_PlanetsNumber]	{115,				199,					83,						100,				204,				204,				153,				102}					// 0..255
#declare Orrery_ColorB						= array[Orrery_PlanetsNumber]	{115,				165,					108,					60,					153,				204,				255,				255}					// 0..255
#declare Orrery_ShowPaths					= array[Orrery_PlanetsNumber]	{true,				true,					true,					true,				true,				true,				true,				true}					// true or false

#macro Orrery_PlaceSphere(Orrery_i, Orrery_CurrentDate)
	#local Orrery_MultiEccentricity		= max(min(Orrery_Eccentricity[Orrery_i] * Orrery_EccentricityMulti, 1), 0);
	#local Orrery_MeanAnomalyToday		= (Orrery_CurrentDate - Orrery_TimeOfPeriapsis[Orrery_i]) / Orrery_OrbitalPeriod[Orrery_i] * 360;
	#local Orrery_TrueAnomalyToday		= Orrery_MeanAnomalyToday + ((2 * Orrery_MultiEccentricity - pow(Orrery_MultiEccentricity,3) / 4) * sind(Orrery_MeanAnomalyToday) + 5 / 4 * pow(Orrery_MultiEccentricity,2) * sind(2 * Orrery_MeanAnomalyToday) + 13 / 12 * pow(Orrery_MultiEccentricity,3) * sind(3 * Orrery_MeanAnomalyToday)) * 180 / pi;
	#local Orrery_RadiusVectorToday		= Orrery_SemiMajorAxis[Orrery_i] * (1 - pow(Orrery_MultiEccentricity,2)) / (1 + Orrery_MultiEccentricity * cosd(Orrery_TrueAnomalyToday));
	#local Orrery_MultiInclination		= Orrery_Inclination[Orrery_i] * Orrery_InclinationMulti;
	#local Orrery_MultiMeanRadius		= Orrery_MeanRadius[Orrery_i] / Orrery_AU * Orrery_MeanRadiusMulti;
	#local Orrery_XToday				= Orrery_RadiusVectorToday * (cosd(Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) - sind(Orrery_LongitudeOfAscendingNode[Orrery_i]) * sind(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_MultiInclination));
	#local Orrery_YToday				= Orrery_RadiusVectorToday * (sind(Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) + cosd(Orrery_LongitudeOfAscendingNode[Orrery_i]) * sind(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_MultiInclination));
	#local Orrery_ZToday				= Orrery_RadiusVectorToday * sind(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) * sind(Orrery_MultiInclination);
	#local Orrery_SphereCoo3D			= <Orrery_XToday,Orrery_ZToday,Orrery_YToday>;
	#local Orrery_SphereCoo2D			= Get_Screen_XY(Orrery_SphereCoo3D);
	#local Orrery_SphereCoo2D			= Orrery_SphereCoo2D/<image_width,image_height>;
	#local Orrery_SphereCoo2D			= <Orrery_SphereCoo2D.x,1-Orrery_SphereCoo2D.y>;
	#local Orrery_PlanetText = text
	{
		ttf "crystal.ttf", Orrery_PlanetName[Orrery_i], 0.001, <0,0>
		scale 0.04
		pigment {color srgb 1}
		finish {ambient 0 diffuse 0 emission 1/2}
		no_shadow
	}
	sphere
	{
		Orrery_SphereCoo3D
		Orrery_MultiMeanRadius
		pigment {color srgb <Orrery_ColorR[Orrery_i],Orrery_ColorG[Orrery_i],Orrery_ColorB[Orrery_i]>/255}
//		no_shadow
	}
	Screen_Object(Orrery_PlanetText, Orrery_SphereCoo2D + <0.01,0.01>, 0, false, 0.01)
#end

#macro Orrery_TracePath(Orrery_i, Orrery_FirstDate, Orrery_CurrentDate, Orrery_StepSize)
//	#local Orrery_StepSize				= Orrery_OrbitalPeriod[Orrery_i] / 36;		// days
	#local Orrery_StepsNum				= (Orrery_CurrentDate - Orrery_FirstDate) / Orrery_StepSize;
	#for (Orrery_j, 0, Orrery_StepsNum - Orrery_StepSize, Orrery_StepSize)
		#local Orrery_StepDate				= Orrery_FirstDate + Orrery_j * Orrery_StepSize;
		#local Orrery_MultiEccentricity		= max(min(Orrery_Eccentricity[Orrery_i] * Orrery_EccentricityMulti, 1), 0);
		#local Orrery_MeanAnomalyToday		= (Orrery_StepDate - Orrery_TimeOfPeriapsis[Orrery_i]) / Orrery_OrbitalPeriod[Orrery_i] * 360;
		#local Orrery_TrueAnomalyToday		= Orrery_MeanAnomalyToday + ((2 * Orrery_MultiEccentricity - pow(Orrery_MultiEccentricity,3) / 4) * sind(Orrery_MeanAnomalyToday) + 5 / 4 * pow(Orrery_MultiEccentricity,2) * sind(2 * Orrery_MeanAnomalyToday) + 13 / 12 * pow(Orrery_MultiEccentricity,3) * sind(3 * Orrery_MeanAnomalyToday)) * 180 / pi;
		#local Orrery_RadiusVectorToday		= Orrery_SemiMajorAxis[Orrery_i] * (1 - pow(Orrery_MultiEccentricity,2)) / (1 + Orrery_MultiEccentricity * cosd(Orrery_TrueAnomalyToday));
		#local Orrery_MultiInclination		= Orrery_Inclination[Orrery_i] * Orrery_InclinationMulti;
		#local Orrery_MultiMeanRadius		= Orrery_MeanRadius[Orrery_i] / Orrery_AU * Orrery_MeanRadiusMulti;
		#local Orrery_XToday				= Orrery_RadiusVectorToday * (cosd(Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) - sind(Orrery_LongitudeOfAscendingNode[Orrery_i]) * sind(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_MultiInclination));
		#local Orrery_YToday				= Orrery_RadiusVectorToday * (sind(Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) + cosd(Orrery_LongitudeOfAscendingNode[Orrery_i]) * sind(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) * cosd(Orrery_MultiInclination));
		#local Orrery_ZToday				= Orrery_RadiusVectorToday * sind(Orrery_TrueAnomalyToday + Orrery_ArgumentOfPerifocus[Orrery_i] - Orrery_LongitudeOfAscendingNode[Orrery_i]) * sind(Orrery_MultiInclination);
		sphere
		{
			<Orrery_XToday,Orrery_ZToday,Orrery_YToday>
			Orrery_MultiMeanRadius/4
			pigment {color srgb <Orrery_ColorR[Orrery_i],Orrery_ColorG[Orrery_i],Orrery_ColorB[Orrery_i]>/255}
//			pigment {color srgb 1}
			no_shadow
		}
	#end
#end

#for (Orrery_i, 0, Orrery_PlanetsNumber - 1, 1)
	Orrery_PlaceSphere(Orrery_i, Orrery_StopDate)
	#if (Orrery_ShowPaths[Orrery_i] = true)
		Orrery_TracePath(Orrery_i, Orrery_StartDate, Orrery_StopDate, 1)
	#end
#end



//------------------------------------------------------------------------------
// ECLIPTIC MARKER PLANE



#declare Orrery_Ecliptic_Pattern = union
{
	#local Orrery_Line_Thickness = 1/100;
	#local Orrery_Ecliptic_Steps = 30;
	#for (i, 1, Orrery_Ecliptic_Steps)
		difference
		{
			cylinder {-y * 1, +y * 1, i + Orrery_Line_Thickness}
			cylinder {-y * 2, +y * 2, i - Orrery_Line_Thickness}
		}
	#end
	#local Orrery_Ecliptic_Steps = 4;
	#local Orrery_Ecliptic_Angle = 360/Orrery_Ecliptic_Steps;
	#for (i, 1, Orrery_Ecliptic_Steps)
		cylinder
		{
			0, +x * 40, Orrery_Line_Thickness
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
			color srgbt <1,1,1,1/2>
			color srgbt <1,1,1,0/2>
		}
	}
	hollow
}

//------------------------------------------------------------------------------
// SUN


sphere
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
				emission Orrery_Light_Point_Color/Orrery_Sun_Radius
				density
				{
					spherical
					density_map
					{
						[0.0 rgb 0]
						[0.2 rgb 1]
						[1.0 rgb 1]
					}
					scale Orrery_Sun_Radius
				}
			}
		}
	}
	no_shadow
}

#local Orrery_SunText = text
{
	ttf "crystal.ttf", "Sol", 0.001, <0,0>
	scale 0.04
	pigment {color srgb 1}
	finish {ambient 0 diffuse 0 emission 1/2}
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
	scale 0.04
	pigment {color srgb 1}
	finish {ambient 0 diffuse 0 emission 1/2}
	no_shadow
}

Screen_Object(Orrery_DayText, <1,0>, <0.02,0.02>, true, 0.01)


//------------------------------------------------------------------------------
// LIGHTS


#switch (Orrery_Light_Mode)
	// old area light code (very slow)
	// I need a new formula, since right now the lights are concentrated near the poles
	#case (1)
		#local Orrery_Light_Area_Theta = Orrery_Light_Area_Theta_Dif/2;
		#for (Orrery_i, 1, Orrery_Light_Area_Theta_Num)
			#local Orrery_Light_Area_Phi = Orrery_Light_Area_Phi_Dif/2;
			#for (j, 1, Orrery_Light_Area_Phi_Num)
				#local Orrery_Light_Area_X = Orrery_Light_Area_Radius * cos(Orrery_Light_Area_Theta) * sin(Orrery_Light_Area_Phi);
				#local Orrery_Light_Area_Y = Orrery_Light_Area_Radius * cos(Orrery_Light_Area_Phi);
				#local Orrery_Light_Area_Z = Orrery_Light_Area_Radius * sin(Orrery_Light_Area_Theta) * sin(Orrery_Light_Area_Phi);
				light_source
				{
					<Orrery_Light_Area_X, Orrery_Light_Area_Y, Orrery_Light_Area_Z>
					Orrery_Light_Area_Color
				}
				#local Orrery_Light_Area_Phi = Orrery_Light_Area_Phi + Orrery_Light_Area_Phi_Dif;
			#end
			#local Orrery_Light_Area_Theta = Orrery_Light_Area_Theta + Orrery_Light_Area_Theta_Dif;
		#end
	#break
	// new area light code (less slow)
	#case (2)
		light_source
		{
			0
			Orrery_Light_Point_Color
			area_light
			x * Orrery_Sun_Radius * 2, y * Orrery_Sun_Radius * 2	// lights spread out across this distance (x * z)
			5, 5													// total number of lights in grid (4x*4z = 16 lights)
			adaptive 1												// 0,1,2,3...
			jitter													// adds random softening of light
			circular												// make the shape of the light circular
			orient													// orient light
			looks_like {Orrery_Sun_Object}
		}
	#break
	// point light (not slow)
	#case (3)
		light_source
		{
			0
			Orrery_Light_Point_Color
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
