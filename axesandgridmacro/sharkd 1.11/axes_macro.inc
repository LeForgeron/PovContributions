// Title: Grid & Axes Include File v1.11
// Author: Michael Horvath
// Homepage: http://www.geocities.com/Area51/Quadrant/3864/email.htm
// Created: 2004/07/14
// Last Updated: 2008/01/09
// This file is licensed under the terms of the CC-LGPL.

//-----------------------------------------------------------------------------Notes

// Include this file in your scene. Generate the axes by using the macro, below.


//-----------------------------------------------------------------------------Macro

#macro AxesParam
	(
		axesSize,			// The distance from the origin to one of the grid's edges.	(float)
		majUnit,			// The size of each large-unit square.	(float)
		minUnit,			// The number of small-unit squares that make up a large-unit square.	(integer)
		thickRatio,			// The thickness of the grid lines (as a factor of axesSize).	(float)
		aBool,				// Turns the axes on/off. (boolian)
		mBool,				// Turns the minor units on/off. (boolian)
		xBool,				// Turns the plane perpendicular to the x-axis on/off.	(boolian)
		yBool,				// Turns the plane perpendicular to the y-axis on/off.	(boolian)
		zBool				// Turns the plane perpendicular to the z-axis on/off.	(boolian)
	)


	//-----------------------------------------------------------------------------Grid pigments

	#local XYgrid_x_maj = pigment
	{
		gradient x
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local XYgrid_y_maj = pigment
	{
		gradient y
		color_map
		{
			[0 rgbt <0.5, 0.5, 0.5, 0.5>]
			[thickRatio*axesSize/majUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local XYgrid_x_min = pigment
	{
		gradient x
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local XYgrid_y_min = pigment
	{
		gradient y
		color_map
		{
			[0 rgbt <0.5, 0.5, 0.5, 0.5>]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[1 rgbt 0.5]
		}
	}


	#local YZgrid_y_maj = pigment
	{
		gradient y
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local YZgrid_z_maj = pigment
	{
		gradient z
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local YZgrid_y_min = pigment
	{
		gradient y
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local YZgrid_z_min = pigment
	{
		gradient z
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit/2 rgbt 0.5]
			[1 rgbt 0.5]
		}
	}


	#local ZXgrid_z_maj = pigment
	{
		gradient z
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local ZXgrid_x_maj = pigment
	{
		gradient x
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local ZXgrid_z_min = pigment
	{
		gradient z
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}
	#local ZXgrid_x_min = pigment
	{
		gradient x
		color_map
		{
			[0 rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit rgbt 0.5]
			[thickRatio*axesSize/majUnit*minUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit rgbt 1]
			[1-thickRatio*axesSize/majUnit*minUnit rgbt 0.5]
			[1 rgbt 0.5]
		}
	}

	#local Xaxes_dot = pigment
	{
		gradient x
		color_map
		{
			[0 rgbt <1, 0, 0, 0.75>]
			[1/2 rgbt <1, 0, 0, 0.75>]
			[1/2 rgbt <0.5, 0.5, 0.5, 0.75>]
			[1 rgbt <0.5, 0.5, 0.5, 0.75>]
		}
	}
	#local Yaxes_dot = pigment
	{
		gradient y
		color_map
		{
			[0 rgbt <0, 1, 0, 0.75>]
			[1/2 rgbt <0, 1, 0, 0.75>]
			[1/2 rgbt <0.5, 0.5, 0.5, 0.75>]
			[1 rgbt <0.5, 0.5, 0.5, 0.75>]
		}
	}
	#local Zaxes_dot = pigment
	{
		gradient z
		color_map
		{
			[0 rgbt <0, 0, 1, 0.75>]
			[1/2 rgbt <0, 0, 1, 0.75>]
			[1/2 rgbt <0.5, 0.5, 0.5, 0.75>]
			[1 rgbt <0.5, 0.5, 0.5, 0.75>]
		}
	}

	//-----------------------------------------------------------------------------Grid
	
	union
	{
		#if (xBool = 1)
			plane
			{
				x,
				0
				texture
				{
					YZgrid_y_maj
					scale majUnit
					translate <0, -1 * axesSize, -1 * axesSize>
				}
				texture
				{
					YZgrid_z_maj
					scale majUnit
					translate <0, -1 * axesSize, -1 * axesSize>
				}
				#if (mBool = 1)
					texture
					{
						YZgrid_y_min
						scale majUnit/minUnit
						translate <0, -1 * axesSize, -1 * axesSize>
					}
					texture
					{
						YZgrid_z_min
						scale majUnit/minUnit
						translate <0, -1 * axesSize, -1 * axesSize>
					}
				#end
			}
		#end
		#if (yBool = 1)
			plane
			{
				y,
				0
				texture
				{
					ZXgrid_z_maj
					scale majUnit
					translate <-1 * axesSize, 0, -1 * axesSize>
				}
				texture
				{
					ZXgrid_x_maj
					scale majUnit
					translate <-1 * axesSize, 0, -1 * axesSize>
				}
				#if (mBool = 1)
					texture
					{
						ZXgrid_z_min
						scale majUnit/minUnit
						translate <-1 * axesSize, 0, -1 * axesSize>
					}
					texture
					{
						ZXgrid_x_min
						scale majUnit/minUnit
						translate <-1 * axesSize, 0, -1 * axesSize>
					}
				#end
			}
		#end
		#if (zBool = 1)
			plane
			{
				z,
				0
				texture
				{
					XYgrid_x_maj
					scale majUnit
					translate <-1 * axesSize, -1 * axesSize, 0>
				}
				texture
				{
					XYgrid_y_maj
					scale majUnit
					translate <-1 * axesSize, -1 * axesSize, 0>
				}
				#if (mBool = 1)
					texture
					{
						XYgrid_x_min
						scale majUnit/minUnit
						translate <-1 * axesSize, -1 * axesSize, 0>
					}
					texture
					{
						XYgrid_y_min
						scale majUnit/minUnit
						translate <-1 * axesSize, -1 * axesSize, 0>
					}
				#end
			}
		#end
		clipped_by
		{
			box
			{
				<1 * axesSize, 1 * axesSize, 1 * axesSize>
				<-1 * axesSize, -1 * axesSize, -1 * axesSize>
			}
		}
		#ifndef (VisibleAxes)
			no_shadow
			no_reflection
		#end
	}
	
	
	//-----------------------------------------------------------------------------Cylinders, cones & text
	
	#if (aBool = 1)
		union
		{
			cylinder
			{
				<0, 0, 0>,
				<axesSize, 0, 0>,
				thickRatio * axesSize
				pigment
				{
					rgbt <1, 0, 0, 0.75>
				}
			}
			cylinder
			{
				<-axesSize, 0, 0>,
				<0, 0, 0>,
				thickRatio * axesSize
				pigment
				{
					Xaxes_dot
					scale thickRatio * axesSize * 25
				}
			}
			cylinder
			{
				<0, 0, 0>,
				<0, axesSize, 0>,
				thickRatio * axesSize
				pigment
				{
					rgbt <0, 1, 0, 0.75>
				}
			}
			cylinder
			{
				<0, -axesSize, 0>,
				<0, 0, 0>,
				thickRatio * axesSize
				pigment
				{
					Yaxes_dot
					scale thickRatio * axesSize * 25
				}
			}
			cylinder
			{
				<0, 0, 0>,
				<0, 0, axesSize>,
				thickRatio * axesSize
				pigment
				{
					rgbt <0, 0, 1, 0.75>
				}
			}
			cylinder
			{
				<0, 0, -axesSize>,
				<0, 0, 0>,
				thickRatio * axesSize
				pigment
				{
					Zaxes_dot
					scale thickRatio * axesSize * 25
				}
			}
			cone
			{
				<0, 0, 0>,
				thickRatio * axesSize * 4
				<thickRatio * axesSize * 20, 0, 0>,
				0
				pigment
				{
					rgbt <1, 0, 0, 0.75>
				}
				translate <axesSize, 0, 0>
			}
			cone
			{
				<0, 0, 0>,
				thickRatio * axesSize * 4
				<0, thickRatio * axesSize * 20, 0>,
				0
				pigment
				{
					rgbt <0, 1, 0, 0.75>
				}
				translate <0, axesSize, 0>
			}
			cone
			{
				<0, 0, 0>,
				thickRatio * axesSize * 4
				<0, 0, thickRatio * axesSize * 20>,
				0
				pigment
				{
					rgbt <0, 0, 1, 0.75>
				}
				translate<0, 0, axesSize>
			}
			text
			{
				ttf "timrom.ttf"
				"X"
				0.05,
				0
				pigment
				{
					rgbt <1, 0, 0, 0.75>
				}
				scale thickRatio * axesSize * 20
				translate <thickRatio * axesSize * 20 + axesSize, 0, 0>
			}
			text
			{
				ttf "timrom.ttf"
				"Y"
				0.05,
				0
				pigment
				{
					rgbt <0, 1, 0, 0.75>
				}
				scale thickRatio * axesSize * 20
				translate <0, thickRatio * axesSize * 20 + axesSize, 0>
			}
			text
			{
				ttf "timrom.ttf"
				"Z"
				0.05,
				0
				pigment
				{
					rgbt <0, 0, 1, 0.75>
				}
				rotate <0, -90, 0>
				scale thickRatio * axesSize * 20
				translate <0, 0, thickRatio * axesSize * 20 + axesSize>
			}
			#ifndef (VisibleAxes)
				no_shadow
				no_reflection
			#end
		}
	#end
#end