// Title: Color solid pigment include v1.20
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// Created: 2008-06-22
// Last Updated: 2008-07-07
// This file is licensed under the terms of the CC-LGPL.

#declare CSolid_Offset = 0.000001;


//------------------------------
// Functions

#declare CSolid_Munsell_Function = function(x,y,z) {sqrt(pow(x,2) + pow(z,2)) / cos(asin(abs(y)))}


//------------------------------
// HSL Cube

#declare CSolid_HSLCube_Hue = pigment
{
	gradient x
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSLCube_Saturation = pigment
{
	gradient z
	pigment_map
	{
		[0 color rgb 1/2]
		[1 CSolid_HSLCube_Hue]
	}
}
#declare CSolid_HSLCube_Lightness = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1/2 CSolid_HSLCube_Saturation]
		[1 color rgb 1]
	}
}
#declare CSolid_HSLCube_Pigment = pigment
{
	CSolid_HSLCube_Lightness
	scale (1 + CSolid_Offset)
	translate -CSolid_Offset/2
}


//------------------------------
// HSL Cylinder

#declare CSolid_HSLCylinder_Hue = pigment
{
	radial
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSLCylinder_Saturation = pigment
{
	cylindrical
	pigment_map
	{
		[0 CSolid_HSLCylinder_Hue]
		[1 color rgb 1/2]
	}
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSLCylinder_Lightness = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1/2 CSolid_HSLCylinder_Saturation]
		[1 color rgb 1]
	}
	scale (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_HSLCylinder_Pigment = pigment {CSolid_HSLCylinder_Lightness}


//------------------------------
// HSL Double-cone

#declare CSolid_HSLDblCone_SaturationFunction = function {sqrt(pow(x,2) + pow(z,2)) / (1-abs(y))}
#declare CSolid_HSLDblCone_Hue = pigment
{
	function {f_th(x,y,z)/pi/2}
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSLDblCone_Saturation = pigment
{
	function {CSolid_HSLDblCone_SaturationFunction(x,y,z)}
	pigment_map
	{
		[0 color rgb 1/2]
		[1 CSolid_HSLDblCone_Hue]
	}
	translate y
	scale y/2
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSLDblCone_Lightness = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1/2 CSolid_HSLDblCone_Saturation]
		[1 color rgb 1]
	}
	scale y * 2
	translate -y
	scale (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_HSLDblCone_Pigment = pigment {CSolid_HSLDblCone_Lightness}


//------------------------------
// HSL Parametric sphere

#declare CSolid_HSLSphere_Hue = pigment
{
	function {f_th(x,y,z)/pi/2}
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSLSphere_Saturation = pigment
{
	function {f_r(x,y,z)}
	pigment_map
	{
		[0 color rgb 1/2]
		[1 CSolid_HSLSphere_Hue]
	}
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSLSphere_Lightness = pigment
{
	function {f_ph(x,y,z)/pi}
	pigment_map
	{
		[0 color rgb 1]
		[1/2 CSolid_HSLSphere_Saturation]
		[1 color rgb 0]
	}
}
#declare CSolid_HSLSphere_Pigment = pigment {CSolid_HSLSphere_Lightness}


//------------------------------
// HSL Munsell sphere

#declare CSolid_HSLMunsell_Hue = pigment
{
	function {f_th(x,y,z)/pi/2}
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSLMunsell_Saturation = pigment
{
	function {CSolid_Munsell_Function(x,y,z)}
	pigment_map
	{
		[0 color rgb 1/2]
		[1 CSolid_HSLMunsell_Hue]
	}
	translate y
	scale y/2
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSLMunsell_Lightness = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1/2 CSolid_HSLMunsell_Saturation]
		[1 color rgb 1]
	}
	scale y * 2
	translate -y
	scale (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_HSLMunsell_Pigment = pigment {CSolid_HSLMunsell_Lightness}


//------------------------------
// HSV Cube

#declare CSolid_HSVCube_Hue = pigment
{
	gradient x
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSVCube_WhiteToHue = pigment
{
	gradient z
	pigment_map
	{
		[0 color rgb 1]
		[1 CSolid_HSVCube_Hue]
	}
}
#declare CSolid_HSVCube_Value = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1 CSolid_HSVCube_WhiteToHue]
	}
}
#declare CSolid_HSVCube_Pigment = pigment
{
	CSolid_HSVCube_Value
	scale (1 + CSolid_Offset)
	translate -CSolid_Offset/2
}


//------------------------------
// HSV Cone

#declare CSolid_HSVCone_SaturationFunction = function {sqrt(pow(x,2) + pow(z,2))/y}
#declare CSolid_HSVCone_Hue = pigment
{
	radial
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSVCone_WhiteToHue = pigment
{
	function {CSolid_HSVCone_SaturationFunction(x,y,z)}
	pigment_map
	{
		[0 color rgb 1]
		[1 CSolid_HSVCone_Hue]
	}
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSVCone_Value = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1 CSolid_HSVCone_WhiteToHue]
		
	}
	scale (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_HSVCone_Pigment = pigment {CSolid_HSVCone_Value}


//------------------------------
// HSV Cylinder

#declare CSolid_HSVCylinder_Hue = pigment
{
	radial
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSVCylinder_WhiteToHue = pigment
{
	cylindrical
	pigment_map
	{
		[0 CSolid_HSVCylinder_Hue]
		[1 color rgb 1]
	}
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSVCylinder_Value = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1 CSolid_HSVCylinder_WhiteToHue]
	}
	scale (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_HSVCylinder_Pigment = pigment {CSolid_HSVCylinder_Value}


//------------------------------
// HSV Parametric sphere

#declare CSolid_HSVSphere_Hue = pigment
{
	function {f_th(x,y,z)/pi/2}
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSVSphere_WhiteToHue = pigment
{
	function {f_r(x,y,z)}
	pigment_map
	{
		[0 color rgb 1]
		[1 CSolid_HSVSphere_Hue]
	}
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSVSphere_Value = pigment
{
	function {f_ph(x,y,z)/pi}
	pigment_map
	{
		[0 CSolid_HSVSphere_WhiteToHue]
		[1 color rgb 0]
	}
}
#declare CSolid_HSVSphere_Pigment = pigment {CSolid_HSVSphere_Value}


//------------------------------
// HSV Munsell sphere

#declare CSolid_HSVMunsell_Hue = pigment
{
	function {f_th(x,y,z)/pi/2}
	color_map
	{
		[0/6 rgb <1, 0, 0,>]
		[1/6 rgb <1, 1, 0,>]
		[2/6 rgb <0, 1, 0,>]
		[3/6 rgb <0, 1, 1,>]
		[4/6 rgb <0, 0, 1,>]
		[5/6 rgb <1, 0, 1,>]
		[6/6 rgb <1, 0, 0,>]
	}
}
#declare CSolid_HSVMunsell_WhiteToHue = pigment
{
	function {CSolid_Munsell_Function(x,y,z)}
	pigment_map
	{
		[0 color rgb 1]
		[1 CSolid_HSVMunsell_Hue]
	}
	translate y
	scale y/2
	scale (1 + CSolid_Offset)
}
#declare CSolid_HSVMunsell_Value = pigment
{
	gradient y
	pigment_map
	{
		[0 color rgb 0]
		[1 CSolid_HSVMunsell_WhiteToHue]
	}
	scale y * 2
	translate -y
	scale (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_HSVMunsell_Pigment = pigment {CSolid_HSVMunsell_Value}


//------------------------------
// RGB Cube

#declare CSolid_RGBCube_Red = pigment
{
	gradient x
	color_map
	{
		[0 rgb <0, 0, 0,>]
		[1 rgb <3, 0, 0,>]
	}
}
#declare CSolid_RGBCube_Green = pigment
{
	gradient y
	color_map
	{
		[0 rgb <0, 0, 0,>]
		[1 rgb <0, 3, 0,>]
	}
}
#declare CSolid_RGBCube_Blue = pigment
{
	gradient z
	color_map
	{
		[0 rgb <0, 0, 0,>]
		[1 rgb <0, 0, 3,>]
	}
}
#declare CSolid_RGBCube_Pigment = pigment
{
	average
	pigment_map
	{
		[CSolid_RGBCube_Red]
		[CSolid_RGBCube_Green]
		[CSolid_RGBCube_Blue]
	}
	scale (1 + CSolid_Offset)
	translate -CSolid_Offset/2
}


//------------------------------
// RGB Cylinder

#declare CSolid_RGBCylinder_Red = pigment
{
	radial
	color_map
	{
		[0 rgb <0, 0, 0,>]
		[1 rgb <3, 0, 0,>]
	}
}
#declare CSolid_RGBCylinder_Green = pigment
{
	cylindrical
	color_map
	{
		[0 rgb <0, 3, 0,>]
		[1 rgb <0, 0, 0,>]
	}
}
#declare CSolid_RGBCylinder_Blue = pigment
{
	gradient y
	color_map
	{
		[0 rgb <0, 0, 0,>]
		[1 rgb <0, 0, 3,>]
	}
	scale (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_RGBCylinder_Pigment = pigment
{
	average
	pigment_map
	{
		[CSolid_RGBCylinder_Red]
		[CSolid_RGBCylinder_Green]
		[CSolid_RGBCylinder_Blue]
	}
}


//------------------------------
// RGB Parametric sphere

#declare CSolid_RGBSphere_Red = pigment
{
	function {f_th(x,y,z)/pi/2}
	color_map
	{
		[0 rgb <0, 0, 0,>]
		[1 rgb <3, 0, 0,>]
	}
}
#declare CSolid_RGBSphere_Green = pigment
{
	function {f_r(x,y,z)}
	color_map
	{
		[0 rgb <0, 0, 0,>]
		[1 rgb <0, 3, 0,>]
	}
	scale (1 + CSolid_Offset)
}
#declare CSolid_RGBSphere_Blue = pigment
{
	function {f_ph(x,y,z)/pi}
	color_map
	{
		[0 rgb <0, 0, 3,>]
		[1 rgb <0, 0, 0,>]
	}
}
#declare CSolid_RGBSphere_Pigment = pigment
{
	average
	pigment_map
	{
		[CSolid_RGBSphere_Red]
		[CSolid_RGBSphere_Green]
		[CSolid_RGBSphere_Blue]
	}
	scale (1 + CSolid_Offset)
	translate -CSolid_Offset/2
}


//------------------------------
// RGB Munsell sphere
// This one doesn't work for some reason.

#declare CSolid_RGBMunsell_Red = pigment
{
	function {f_th(x,y,z)/pi/2}
	color_map
	{
		[0 color rgb 0]
		[1 color rgb x]
	}
}
#declare CSolid_RGBMunsell_Green = pigment
{
	function {CSolid_Munsell_Function(x,y,z)}
	pigment_map
	{
		[0 color rgb 0]
		[1 color rgb y]
	}
	translate y
	scale y/2
	scale (1 + CSolid_Offset)
}
#declare CSolid_RGBMunsell_Blue = pigment
{
	gradient y
	color_map
	{
		[1 rgb 0]
		[0 rgb z]
	}
	scale y * 2
	translate -y
	scale y * (1 + CSolid_Offset)
	translate -y * CSolid_Offset/2
}
#declare CSolid_RGBMunsell_Pigment = pigment
{
	average
	pigment_map
	{
		[CSolid_RGBMunsell_Red]
		[CSolid_RGBMunsell_Green]
		[CSolid_RGBMunsell_Blue]
	}
}
