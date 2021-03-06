//Title: HSV cone pigment v1.01
//Author: Michael Horvath
//Created date: 2008-06-21
//Modified date: 2008-06-22
//Homepage: http://www.geocities.com/Area51/Quadrant/3864/active.htm
//This file is licensed under the terms of the CC-LGPL

#declare HSVO_SaturationFunction = function
{
	sqrt(pow(x,2) + pow(z,2)) / y
}

#declare HSVO_Hue = pigment
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

#declare HSVO_WhiteToHue = pigment
{
	function
	{
		HSVO_SaturationFunction(x,y,z)
	}
	pigment_map
	{
		[0 color rgb 1]
		[1 HSVO_Hue]
	}
	scale 1.000001
}

#declare HSVO_Value = pigment
{
	gradient -y
	pigment_map
	{
		[0 HSVO_WhiteToHue]
		[1 color rgb 0]
	}
	translate y * 0.000001
}

#declare HSVO_HSVCylinder = pigment {HSVO_Value}
