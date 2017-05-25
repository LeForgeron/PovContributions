// Title: Habitable planet texture include v0.50
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008-02-07
// Last Updated: 2008-11-07
// This file is licensed under the terms of the CC-LGPL.
// +KFI0 +KFF15 +KC
// +k0.5


#declare HPlanet_Height_Ratio = 0.005;
#declare HPlanet_Water_Ratio = 1/3;
#declare HPlanet_Ice_Ratio = 2/3;
#declare HPlanet_Planet_Radius = 1;
#declare HPlanet_Tilt_Angle = 30;
#declare HPlanet_Rotate_Angle = clock * 360;
#declare HPlanet_View_Angle = 30;
#declare HPlanet_Seed_Value = seed(808232374);
#declare HPlanet_Show_Mode = 2;

#include "colors.inc"
#include "functions.inc"
#include "rand.inc"
#include "HPlanet_include.inc"


// ----------------------------------------

background {color rgb <0.6,0.7,1.0>}

global_settings
{
	assumed_gamma 1.0
}

camera
{
	orthographic
	location	-z * 1024
//	direction	+z * 1024
	direction	+z
	right		x * 4 * image_width/image_height
	up		y * 4
}
/*
sky_sphere
{
	pigment
	{
		gradient y
		color_map
		{
			[0.0 rgb <0.6,0.7,1.0>]
			[0.7 rgb <0.0,0.1,0.8>]
		}
	}
}
*/
light_source
{
	-z * 1024
	color rgb 2
	parallel
	shadowless
	rotate x * 30
	rotate y * 30
}





//--------------------------------------------------------------

#switch (HPlanet_Show_Mode)
	#case (1)
		union
		{
			text
			{
				ttf "crystal.ttf", "1",
				0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			sphere
			{
				0, 1
				pigment {HPlanet_Final_pigment}
				rotate y * HPlanet_Rotate_Angle
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * +1
			translate y * -1
			scale HPlanet_Planet_Radius
		}
	
		//--------------------------------------------------------------
	
		union
		{
			text
			{
				ttf "crystal.ttf", "2",
				0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			sphere
			{
				0, 1
				pigment {HPlanet_Combined_pigment}
				rotate y * HPlanet_Rotate_Angle
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * +1
			translate y * +1
			scale HPlanet_Planet_Radius
		}
	
		//--------------------------------------------------------------
	
		union
		{
			text
			{
				ttf "crystal.ttf", "3",
				0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			sphere
			{
				0, 1
				pigment {HPlanet_Altitude_pigment}
				rotate y * HPlanet_Rotate_Angle
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * -1
			translate y * +1
			scale HPlanet_Planet_Radius
		}
	
		//--------------------------------------------------------------
	
		union
		{
			text
			{
				ttf "crystal.ttf", "4",
				0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			sphere
			{
				0, 1
				pigment {HPlanet_Latitude_pigment}
				rotate y * HPlanet_Rotate_Angle
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * -1
			translate y * -1
			scale HPlanet_Planet_Radius
		}
	#break

	//--------------------------------------------------------------

	#case (2)
		union
		{
			sphere {0, 1 pigment {HPlanet_Final_pigment}}
			cylinder {<0,-1.2,0,>,<0,+1.2,0,>, 0.02 pigment {color rgb x}}
			torus {1, 0.01 pigment {color rgb x}}
			rotate y * (HPlanet_Rotate_Angle + 090)
			rotate x * HPlanet_Tilt_Angle
			rotate y * HPlanet_View_Angle
			scale HPlanet_Planet_Radius * 2
		}
	#break

	//--------------------------------------------------------------

	#case (3)
		union
		{
			text
			{
				ttf "crystal.ttf", "0 deg", 0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			union
			{
				sphere {0, 1 pigment {HPlanet_Final_pigment}}
				cylinder {<0,-1.2,0,>,<0,+1.2,0,>, 0.02 pigment {color rgb x}}
				torus {1, 0.01 pigment {color rgb x}}
				rotate y * (HPlanet_Rotate_Angle + 000)
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * +1
			translate y * -1
			scale HPlanet_Planet_Radius
		}

		//--------------------------------------------------------------

		union
		{
			text
			{
				ttf "crystal.ttf", "90 deg", 0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			union
			{
				sphere {0, 1 pigment {HPlanet_Final_pigment}}
				cylinder {<0,-1.2,0,>,<0,+1.2,0,>, 0.02 pigment {color rgb x}}
				torus {1, 0.01 pigment {color rgb x}}
				rotate y * (HPlanet_Rotate_Angle + 090)
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * +1
			translate y * +1
			scale HPlanet_Planet_Radius
		}

		//--------------------------------------------------------------

		union
		{
			text
			{
				ttf "crystal.ttf", "180 deg", 0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			union
			{
				sphere {0, 1 pigment {HPlanet_Final_pigment}}
				cylinder {<0,-1.2,0,>,<0,+1.2,0,>, 0.02 pigment {color rgb x}}
				torus {1, 0.01 pigment {color rgb x}}
				rotate y * (HPlanet_Rotate_Angle + 180)
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * -1
			translate y * +1 
			scale HPlanet_Planet_Radius
		}

		//--------------------------------------------------------------

		union
		{
			text
			{
				ttf "crystal.ttf", "270 deg", 0.1, 0
				scale 1/3
				translate z * -2
				pigment {color rgb x}
			}
			union
			{
				sphere {0, 1 pigment {HPlanet_Final_pigment}}
				cylinder {<0,-1.2,0,>,<0,+1.2,0,>, 0.02 pigment {color rgb x}}
				torus {1, 0.01 pigment {color rgb x}}
				rotate y * (HPlanet_Rotate_Angle + 270)
				rotate x * HPlanet_Tilt_Angle
				rotate y * HPlanet_View_Angle
			}
			translate x * -1
			translate y * -1
			scale HPlanet_Planet_Radius
		}
	#break
#end