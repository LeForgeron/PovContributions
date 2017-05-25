// RANDOM SOLAR SYSTEM GENERATOR FOR POV-Ray v1.01
// ***********************************************
// Created: 2005-03-01 by Michael Horvath
// Last updated: 2008-06-23
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.

// Set this to equal "true" if Chris Colefax's "GALAXY.INC" and "Lens.inc" exist somewhere within POV-Ray's library path.
#declare SSys_DependenciesExist = false;	// boolean

// ... seed for planets
#declare SSys_S1 = seed(3427);		// float
// ...seed for moons
#declare SSys_S2 = seed(09822334834);	// float
// ...seed for rings
#declare SSys_S3 = seed(12);			// float
// ...seed for orbits, camera, & lights
#declare SSys_S4 = seed(2212);		// float
// ...seed for starry background
#declare SSys_S5 = seed(98200);		// float
// ...seed for asteroid fields
#declare SSys_S6 = seed(88934);		// float
// ...seed for planet materials
#declare SSys_M1 = seed(88934);		// float
// ...seed for moon materials
#declare SSys_M2 = seed(12);			// float
// ...seed for ring materials
#declare SSys_M3 = seed(88934);		// float
// ...seed for camera & light materials
#declare SSys_M4 = seed(88934);		// float
// ...seed for asteroid field materials
#declare SSys_M6 = seed(88934);

// focus the camera on this planet (or, only render this planet if RenderMode = 1), counting from bottom to top, starting on the left
// set this to zero (0) to focus on the sun (or, render all planets if RenderMode = 1)
#declare SSys_RenderOnly = 4;		// integer, from 0 to NumberPlanets
// the method of texturing the planets
#declare SSys_RenderStyle = 0;		// integer, 0 = plain, with high detail maps; 1 = shiny and slow, like glass or metal; 2 = smooth bright pastels, like ice cream
// the method of rendering the scene
#declare SSys_RenderMode = 0;		// integer, 0 = perspective, random orbits; 1 = orthographic, tiled; 2 = spherical, random orbits
// render the starry background? (requires Chris Colefax's Galaxy Include File)
#declare SSys_RenderStarfield = 1;		// boolian, 0 = disable; 1 = enable
// render the galactic background? (requires Chris Colefax's Galaxy Include File) (slow)
#declare SSys_RenderBackground = 0;		// boolian, 0 = disable; 1 = enable
// render the galactic objects? (requires Chris Colefax's Galaxy Include File)
#declare SSys_RenderObjects = 0;		// boolian, 0 = disable; 1 = enable
// render the lens effects? (requires Chris Colefax's Lens Effects Include File)
#declare SSys_RenderLensEffects = 0;		// boolian, 0 = disable; 1 = enable
// should fog be added to the scene?
#declare SSys_RenderFog = 0;			// boolian, 0 = disable; 1 = enable
// surround the sun in a sphere of solar wind
#declare SSys_RenderWind = 0;		// boolian, 0 = disable; 1 = enable
// render the planets' orbital paths
#declare SSys_RenderOrbits = off;		// boolian, 0 = disable; 1 = enable
// render a numbered label above each planet
#declare SSys_RenderLabels = off;		// boolian, 0 = disable; 1 = enable

// the number of planetary to generate
#declare SSys_NumberPlanets = 9;		// must be the square of an integer
// the maximum number of moons a planet may have
#declare SSys_NumberMoons = <1, 10,>;		// integer
// the maximum number of rings a planet may have
#declare SSys_NumberRings = <1, 10,>;		// integer
// the maximum number of unique asteroids to generate and store in memory (these will get reused over and over fill the field)
#declare SSys_NumberAsteroids = 16;		// integer
// the maximum number of galactic objects
#declare SSys_NumberObjects = 8;		// integer
// the statistical chance that a planet has moons
#declare SSys_ChanceMoons = 0.5;		// float, 0 to 1
// the statistical chance that a planet has rings
#declare SSys_ChanceRings = 0.5;		// float, 0 to 1
// the statistical chance that a planet has malformed into an asteroid field (slow)
#declare SSys_ChanceAsteroids = 0.0;		// float, 0 to 1
// the maximum planet radius
#declare SSys_PlanetsRadius = 1;		// float
// the maximum distance of a planet from the center of the sun (not implemented currently)
#declare SSys_PlanetsDistance = 20000;		// float
// the maximum distance of a moon from the planet it orbits. note that planets and moons follow circular orbits
#declare SSys_MoonsDistance = 10;		// float
// the maximum density of an asteroid field (asteroids per unit of area, independent of height)
#declare SSys_AsteroidsDensity = 0.001;		// float

// the maximum height of a planet's atmosphere, relative to the planet's radius (recommend you use higher values for orthographic projections)
#declare SSys_AtmosFactor = 1/64;		// float, 0 to 1
// enables scattering-type media for the planet atmospheres (very slow, but more realistic)
#declare SSys_AtmosScatter = 1;			// boolian, 0 = disable; 1 = enable
// the color of the fog
#declare SSys_FogColor = <rand(SSys_S4), rand(SSys_S4), rand(SSys_S4),>/8;	// color vector, typically low values
// the relative luminence/opacity of the background scene
#declare SSys_GalaxyIntensity = 0.1;		// float, 0 to 1

// the radius of the light source (the sun)
#declare SSys_LightRadius = 5;			// float
// the distance of the light source from the center of the scene (only applies if RenderMode = 1)
#declare SSys_LightDistance = 100;		// float
// the relative strength of the light source
#declare SSys_LightIntensity = 5;		// float, default 5
// the color of the light emitted by the light source
#declare SSys_LightColor = <1, 1, 0.5,>;	// color vector
//#declare LightColor = <rand(SSys_S5), rand(SSys_S5), rand(SSys_S5),>;		// color vector
// the lattitude and longitude of the light source (only applies if RenderMode = 1)
#declare SSys_LightPosition = <-10, -80,>;	// vector (degrees)
// the sun object visual style (i.e. what the sun itself looks like)
#declare SSys_LightMode = 0;			// integer, 0, 1 or 2

// the coordinates of the camera (only applies if RenderMode != 1 and RenderOnly = 0)
#declare SSys_CameraLocation = <0, 0, 10,>;	// vector
// the coordinates that the camera will point toward (only applies if RenderMode != 1 and RenderOnly = 0)
#declare SSys_CameraLookAt = <0, 0, 0,>;	// vector
// the distance between the camera and the object it is orbiting (only applies if RenderMode != 1 and RenderOnly != 0)
#declare SSys_CameraDistance = 2;		// float
// the lattitude and longitude of the camera, with repect to the object it is orbiting (only applies if RenderMode != 1)
// the camera is pointed along the Z axis, by default.
#declare SSys_CameraPosition = <0, 180,>;	// vector (degrees)
// the altitude and azimuth of the camera (only applies if RenderMode != 1)
#declare SSys_CameraDirection = <0, 0,>;	// vector (degrees)


// TEXTURE OPTIONS
#declare SSys_TexAmbient = <0, 0,>;
#declare SSys_MedEmission = <0, 1,>;
#declare SSys_MedAbsorbtion = <0, 1,>;
#include "SolarSystem_include.inc"
