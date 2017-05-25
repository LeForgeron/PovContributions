//This file is licensed under the terms of the CC-LGPL
//Author: Michael Horvath
//Created date: 2008-01-14
//Modified date: 2008-06-21
//Homepage: http://www.geocities.com/Area51/Quadrant/3864/active.htm

#declare HSLC_Hue = pigment
{
	gradient x
	color_map
	{
		[0 rgb <1, 0, 0>]
		[1/3 rgb <0, 1, 0>]
		[2/3 rgb <0, 0, 1>]
		[1 rgb <1, 0, 0>]
	}
}

#declare HSLC_Saturation = pigment
{
	gradient z
	pigment_map
	{
		[0 color <1/2, 1/2, 1/2>]
		[1 HSLC_Hue]
	}
}

#declare HSLC_Lightness = pigment
{
	gradient y
	pigment_map
	{
		[0 color <0, 0, 0>]
		[1/2 HSLC_Saturation]
		[1 color <1, 1, 1>]
	}
}

#declare HSLC_HSLCube = pigment {HSLC_Lightness}
