// This file is licensed under the terms of the CC-LGPL


#declare rad=yes;

global_settings{
	assumed_gamma 1
	#if(rad)
	radiosity{
		pretrace_start 0.08
		pretrace_end   0.02
		count 45
		
		nearest_count 5
		error_bound 1.8
		recursion_limit 3
		
		low_error_factor 0.5
		gray_threshold 0.0
		minimum_reuse 0.015
		brightness 1
		
		adc_bailout 0.01/2
	}
	#end
}

#default{
	pigment{rgb 1}
	finish{#if(rad)ambient 0#end}
}

camera{
	location <0,1.5,-3>
	look_at 0
}

#if(!rad)
light_source{
	<-1,3,-6> rgb 1
}
#end

sky_sphere{
	pigment{rgb 1.4}
}
//include this file to use the surface macros
/////////////////////////////////////////////
#include "surface.inc"

//the walls
///////////
union{
	plane{y (-0.6)}
	box{<-3,-0.6,2>,<3,2,3>}
	box{<2,-0.6,-3>,<3,2,3>}
	box{<-2,-0.6,-3>,<-3,2,3>}
}


//the object use to find the surface
////////////////////////////////////
#declare traceObj=union{
	sphere{<-0.65,0,0> 0.35}
	sphere{<0.65,0,0> 0.35}
	cylinder{<-0.65,0,0>,<0.65,0,0>, 0.15}
}

//an object use to place along the surface
//////////////////////////////////////////
#declare placeObj=sphere{0 0.1}


//call this macro first to trace the surface
//the results are saved to "surface_surfacepoints.inc"
//////////////////////////////////////////////////////
//surface_traceSurface(traceObj, 30, "surface_surfacepoints.inc", 8)


//call this macro to generate hair
//the results are saved to "surface_surfacehair.inc"
//once it has been saved comment it out
////////////////////////////////////////////////////
surface_coverHair("surface_Min.inc", "surface_surfacehair.inc", "hairCover", 0.025, 6, 0.01, 1)


//a union of the object and the covering hair
/////////////////////////////////////////////
union{
	object{traceObj
		pigment{rgb x*0.3}
	}
	
	//include the saved file to use the hair
	////////////////////////////////////////
	#include "surface_surfacehair.inc"
	object{hairCover
		pigment{rgb x*0.8}
	}
	rotate y*-30
	translate<-0.5,0,0.2>
}

//the surface covered in spheres
//the results cannot yet be saved to a
//file so this macro has to be called each time
///////////////////////////////////////////////
object{surface_cover("surface_surfacepoints.inc", placeObj, no, yes)
	pigment{agate color_map{[0 rgb y*0.5][1 rgb<0.4,1,0.0>*0.5]}}
	scale 0.75
	rotate y*20
	translate<0.6,0,-1.1>
}