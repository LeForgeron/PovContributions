//This file is licensed under the terms of the CC-LGPL
//Author: Michael Horvath
//Created date: 2008-01-11
//Modified date: 2008-06-21
//Homepage: http://www.geocities.com/Area51/Quadrant/3864/active.htm

#declare HSVS_Hue = pigment
{
	function
	{
		f_th(x,y,z) / pi / 2
	}
	color_map
	{
		[0 rgb <1, 0, 0>]
		[1/3 rgb <0, 0, 1>]
		[2/3 rgb <0, 1, 0>]
		[1 rgb <1, 0, 0>]
	}
}

#declare HSVS_WhiteToHue = pigment
{
	function
	{
		f_r(x,y,z)
	}
	pigment_map
	{
		[0 color <1, 1, 1>]
		[1 HSVS_Hue]
	}
	scale 1.0001
}

#declare HSVS_Value = pigment
{
	function
	{
		f_ph(x,y,z) / pi
	}
	pigment_map
	{
		[0 HSVS_WhiteToHue]
		[1 color <0, 0, 0>]
	}
}

#declare HSVS_HSVSphere = pigment {HSVS_Value}
