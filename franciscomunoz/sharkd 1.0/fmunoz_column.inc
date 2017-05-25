// Persistence of Vision Ray Tracer Scene Description File
// This file is licensed under the terms of the CC-LGPL.
// File: FMunoz_Column.inc
// Desc: A stone column with scrolls.
// Date: 26/08/1997
// Last: 09/07/2008
// Auth: Francisco Munoz, tweaked and prepared by Michael Horvath


#ifndef (Black)		#include "colors.inc" #end
#ifndef (Gold_Texture)	#include "textures.inc" #end

// White marble with gray veins.
#ifndef (FMunoz_Column_Texture)
	#declare FMunoz_Column_Texture = texture
	{
		pigment
		{
			marble
			turbulence 1
			color_map
			{
				[0.0 color rgb <1.0,1.0,1.0>]
				[0.8 color rgb <0.8,0.8,0.8>]
				[0.8 color rgb <0.8,0.8,0.8>]
				[1.0 color rgb <0.5,0.5,0.5>]
			}
		}
		finish
		{
			reflection .1
			ambient .1
			diffuse .4
			phong 5
		}
	}
#end

#ifndef (FMunoz_Column_height)	#declare FMunoz_Column_height = 11;	#end

#declare FMunoz_Column = union
{
	difference
	{
		cylinder {<0,1,0>,<0,FMunoz_Column_height-1,0>,2}
		#declare FMunoz_Count = 0;
		#while (FMunoz_Count < 20)
			cylinder {<0,1.5,2>,<0,FMunoz_Column_height-1.5,2>,.25 rotate y*FMunoz_Count*18}
			sphere {<0,1.5,2>,.25 rotate y*FMunoz_Count*18}
			sphere {<0,FMunoz_Column_height-1.5,2>,.25 rotate y*FMunoz_Count*18}
			#declare FMunoz_Count = FMunoz_Count + 1;
		#end
	}
	difference
	{
		cylinder {<-2.5,FMunoz_Column_height-1,-2.5>,<-2.5,FMunoz_Column_height-1,2.5>,1}
		torus {.5,.1 rotate x*90 translate <-2.5,FMunoz_Column_height-1,-2.5>}
		torus {.5,.1 rotate x*90 translate <-2.5,FMunoz_Column_height-1,2.5>}
	}
	difference
	{
		cylinder {<2.5,FMunoz_Column_height-1,-2.5>,<2.5,FMunoz_Column_height-1,2.5>,1}
		torus {.5,.1 rotate x*90 translate <2.5,FMunoz_Column_height-1,-2.5>}
		torus {.5,.1 rotate x*90 translate <2.5,FMunoz_Column_height-1,2.5>}
	}
	box {<-2.5,FMunoz_Column_height,-2.5>,<2.5,FMunoz_Column_height-.4,2.5>}
	torus {2,.25 scale <1,1.5,1> translate y*(FMunoz_Column_height-.8)}
	torus {2,.25 translate y*.75}
	box {<-2.5,0,-2.5>,<2.5,.5,2.5>}
	texture {FMunoz_Column_Texture}
}
