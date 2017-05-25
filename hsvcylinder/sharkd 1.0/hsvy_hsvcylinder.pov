//This file is licensed under the terms of the CC-LGPL
//Author: Michael Horvath
//Created date: 2008-01-14
//Modified date: 2008-06-21
//Homepage: http://www.geocities.com/Area51/Quadrant/3864/active.htm

#declare HSVY_Hue = pigment
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

#declare HSVY_WhiteToHue = pigment
{
	cylindrical
	pigment_map
	{
		[0 HSVY_Hue]
		[1 Plain_White]
	}
	scale 1.000001
}

#declare HSVY_Value = pigment
{
	gradient -y
	pigment_map
	{
		[0 HSVY_WhiteToHue]
		[1 Plain_Black]
	}
	translate y * 0.000001
}

#declare HSVY_HSVCylinder = pigment {HSVY_Value}
