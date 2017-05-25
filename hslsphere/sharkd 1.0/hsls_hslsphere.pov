//This file is licensed under the terms of the CC-LGPL
//Author: Michael Horvath
//Created date: 2008-01-08
//Modified date: 2008-06-21
//Homepage: http://www.geocities.com/Area51/Quadrant/3864/active.htm

#declare HSLS_Hue = pigment
{
	function
	{
		f_th(x,y,z) / pi / 2
	}
	color_map
	{
		[0 rgb <1, 0, 0>]
		[1/3 rgb <0, 1, 0>]
		[2/3 rgb <0, 0, 1>]
		[1 rgb <1, 0, 0>]
	}
}

#declare HSLS_Saturation = pigment
{
	function
	{
		f_r(x,y,z)
	}
	pigment_map
	{
		[0 color <1/2, 1/2, 1/2>]
		[1 HSLS_Hue]
	}
	scale 1.0001
}

#declare HSLS_Lightness = pigment
{
	function
	{
		f_ph(x,y,z) / pi
	}
	pigment_map
	{
		[0 color <1, 1, 1>]
		[1/2 HSLS_Saturation]
		[1 color <0, 0, 0>]
	}
}

#declare HSLS_HSLSphere = pigment {HSLS_Lightness}
