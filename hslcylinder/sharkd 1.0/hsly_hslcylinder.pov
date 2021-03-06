//This file is licensed under the terms of the CC-LGPL
//Author: Michael Horvath
//Created date: 2008-01-11
//Modified date: 2008-06-21
//Homepage: http://www.geocities.com/Area51/Quadrant/3864/active.htm

#declare HSLY_Hue = pigment
{
	radial
	color_map
	{
		[0 rgb <1, 0, 0>]
		[1/3 rgb <0, 1, 0>]
		[2/3 rgb <0, 0, 1>]
		[1 rgb <1, 0, 0>]
	}
}

#declare HSLY_Saturation = pigment
{
	cylindrical
	pigment_map
	{
		[0 HSLY_Hue]
		[1 color <1/2, 1/2, 1/2>]
	}
	scale 1.000001
}

#declare HSLY_Lightness = pigment
{
	gradient -y
	pigment_map
	{
		[0 color <1, 1, 1>]
		[1/2 HSLY_Saturation]
		[1 color <0, 0, 0>]
	}
	translate y * 0.000001
}

#declare HSLY_HSLCylinder = pigment {HSLY_Lightness}
