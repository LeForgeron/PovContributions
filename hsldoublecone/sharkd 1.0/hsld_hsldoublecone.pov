//This file is licensed under the terms of the CC-LGPL
//Author: Michael Horvath
//Created date: 2008-06-21
//Modified date: 2008-06-21
//Homepage: http://www.geocities.com/Area51/Quadrant/3864/active.htm

#declare HSLD_SaturationFunction = function
{
	sqrt(pow(x,2) + pow(z,2)) / -(abs(y)-1)
}


#declare HSLD_Hue = pigment
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

#declare HSLD_Saturation = pigment
{
	function
	{
		HSLD_SaturationFunction(x,y,z)
	}
	pigment_map
	{
		[0 color <1/2, 1/2, 1/2>]
		[1 HSLD_Hue]
	}
	scale 1.0001
}

#declare HSLD_Lightness = pigment
{
	gradient -y
	pigment_map
	{
		[0 color <1, 1, 1>]
		[1/2 HSLD_Saturation]
		[1 color <0, 0, 0>]
	}
	scale 2
	translate -y
	translate y * 0.000001
}

#declare HSLD_HSLDCone = pigment {HSLD_Lightness}
