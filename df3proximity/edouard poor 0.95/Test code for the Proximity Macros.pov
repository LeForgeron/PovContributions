/*
 *  Proximity Text.pov
 *
 *    Test code for the Proximity Macros       
 
 
This file is an example and test file created by Edouard Poor of the Pov-Ray community, in 2009. 
It is my personal copy that I am posting to the Pov-Ray newsgroups as it is no longer available on the internet. 
 All credit must go to Edouard.


Stephen McAvoy

 
 
 
 */


// -- SDL Version -------------------------------------------------------------

#version 3.7;



// -- Include Files -----------------------------------------------------------

#include "DF3ProximityPattern.inc"



// -- Scene Settings ----------------------------------------------------------

/* DF3 Proximity Options */
#declare generate_df3 = true;  // false; // true;  // Generate pattern (turn off after 1st render)

/* Scene Options */
#declare object_name = "julia";  // "dome", "julia", "boxes", "sphere"

/* Material */
#declare pattern_name = "brass"; // "brass", "stone", "false_color", "grid"
#declare use_df3_proximity_pattern = true;  // load the proximity pattern
#declare add_noise = true;  // Adds random noise to the proximity pattern

/* Lighting */
#declare use_area_light = false;  // area_light or point light
#declare use_radiosity = false;  // overrides use_area_light
#declare radiosity_quality = 3;  // use values from 1 to 5

/* Focal Blur */
#declare use_focal_blur = false;  // On or off



// -- The object to apply the DF3 proximity pattern to ------------------------

#if( object_name = "julia" )
	#declare obj = 
		julia_fractal {
			<0.1,0.8,-0.1,0.01>
			quaternion sqr
			max_iteration 8 precision 1000
			scale 60 translate y*60 rotate y*45
		}
#end

#if( object_name = "sphere" )
	#declare obj = sphere { 0, 1 scale 60 translate y*60 }
#end

#if( object_name = "boxes" )
	#declare obj = union {
		box { <-60,-30,-30>,<60,30,30> rotate z * 90 translate y*60 }
		box { <-60,-30,-30>,<60,30,30> rotate y * 90 translate y*60 }
		box { <-60,-30,-30>,<60,30,30> rotate x * 90 translate y*60 }
		rotate y*45
	}
#end

#if( object_name = "dome" )
	#declare obj = 
	union {
		sphere { 0, 1 }
		cylinder { <0.0, -1, 0.0>, <0.0, -0.3, 0.0>, 1.2 }
	#declare n = 0;
	#while ( n < 12 )
		cylinder {
			<-0.03, 0, 0>, <0.03, 0, 0>, 1.05
			translate y*-0.05
			rotate y * (n * (360/12))
		}
	#declare n = n + 1;
	#end
		scale 55 translate y*55
	}
#end



// -- Proximity Pattern -------------------------------------------------------

/* Only need to generate the DF3 Pattern the very first time */
#if( generate_df3 = true )
	//Proximity_SetMeshMode( on )
	Proximity_GenerateMap( obj, object_name )
#end

/* Load the DF3 Proximity Pattern */
Proximity_SetPatternSmoothingMode( on )  // default is off
Proximity_SetPatternSmoothingValue( 20 )  // default is 20
#declare df3_pattern = Proximity_LoadMap( obj, object_name )



// -- Materials ---------------------------------------------------------------

#declare shiny_brass =
	texture {
		pigment { rgb <0.8,0.5,0>*0.9 }
		finish { brilliance 2 reflection 0.33 metallic conserve_energy }
	};

#declare shiny_brass_dents =
	texture {
		shiny_brass
		normal {
            dents 1 scale 2 
            slope_map {
                [ 0.0 <1,0> ] [ 0.8 <1,0> ] [ 0.8 <1,-1> ] [ 1.0 <0,0> ]
            }
        }
	};

#declare dull_brass =
	texture {
		pigment {
			bumps scale 5
			color_map {
				[ 0, rgb <0.8,0.5,0> * 0.6 ]
				[ 1, rgb <0.8,0.5,0> * 0.5 ]
			}
		}
		finish { reflection 0.01 metallic conserve_energy }
	};

#declare corroded_brass =
	texture {
		pigment { rgb <0.49,0.81,0.77> }
		normal { bumps scale 0.5 }
		finish { reflection 0 }
	};

#declare brass_map = 
	texture_map {
		[ 0.38 shiny_brass ]
		[ 0.42 dull_brass ]
		//[ 0.53 dull_brass ]
		[ 0.58 corroded_brass]
	};

#declare stone_map =
	texture_map {
		[ 0.35 
			pigment { color rgb <0.625, 0.5729, 0.454396>*1.1 } 
			normal { crackle 1 scale 6 slope_map { [ 0.0 <1,0> ] [ 0.4 <1,0> ] [ 0.4 <1,-1> ] [ 1.0 <0,0> ] } } ]
		[ 0.45 
			pigment { color rgb <0.625, 0.5729, 0.454396>*1.1 } 
			normal { crackle 0 scale 6 slope_map { [ 0.0 <1,0> ] [ 0.4 <1,0> ] [ 0.4 <1,-1> ] [ 1.0 <0,0> ] } } ]
		[ 0.5 
			pigment { color rgb <0.625, 0.5729, 0.454396> } 
			normal { crackle 0 scale 3 } ]
		[ 0.6 
			pigment { color rgb <0.3854, 0.395833, 0.1875> } 
			normal { bumps scale 0.2 } ]
	};

#declare false_color_map = 
	texture_map {
		[ 0.35 pigment { rgb <0,169,224>/255 } ]
		[ 0.41 pigment { rgb <50,52,144>/255 } ]
		[ 0.47 pigment { rgb <234,22,136>/255 } ]
		[ 0.53 pigment { rgb <235,46,46>/255 } ]
		[ 0.59 pigment { rgb <253,233,45>/255 } ]
		[ 0.65 pigment { rgb <0,158,84>/255 } ]
	}

#if( pattern_name = "brass" )
	#declare map = brass_map;
#end

#if( pattern_name = "stone" )
	#declare map = stone_map;
#end

#if( pattern_name = "false_color" )
	#declare map = false_color_map;
#end



// -- Create the object and materials -----------------------------------------
	
object {
        obj

	#if( pattern_name != "grid" )
	texture {
		pigment_pattern {
			average
			pigment_map {
				#if( use_df3_proximity_pattern )
				[ 3 df3_pattern ]
				#end
				#if( add_noise = true )
				[ 0.6 slope { y altitude <0,1,0> } color_map { [0 rgb 1] [1 rgb 0] } scale 120 ]
				[ 0.4 bozo color_map { [0 rgb 0] [1 rgb 1] } scale 4 ]
				[ 0.3 bozo color_map { [0 rgb 0] [1 rgb 1] } scale 1 ]
				[ 0.2 bozo color_map { [0 rgb 0] [1 rgb 1] } scale 0.33 ]
				[ 0.1 bozo color_map { [0 rgb 0] [1 rgb 1] } scale 0.1 ]
				#end
			}
		}
		texture_map {	map }
	}
	#else
	pigment { Proximity_DebugGrid( obj, object_name ) }
	#end
}



// -- Global Settings ---------------------------------------------------------

global_settings {
    max_trace_level 3
}



// -- Lighting ----------------------------------------------------------------

#if( use_radiosity )
	#include "rad_def.inc"
	#default {
	   finish {
	      ambient 0
	   }
	}
	global_settings {
	       radiosity {
			pretrace_start 0.08
			pretrace_end 0.002
			count 20 * radiosity_quality
			nearest_count 5
			error_bound 1
			recursion_limit 2
			low_error_factor 0.5
			gray_threshold 0.0
			minimum_reuse 0.015
			brightness 1
			adc_bailout 0.01/2
#if( pattern_name = "stone" )
			normal on
#end
			always_sample off
	        }
	}
#else
	light_source {
		< 50, 1000, -700>
		rgb 1
	#if ( use_area_light = true )
		area_light < 2000,0,0 >,< 0,2000,0 >, 5,5
		adaptive 3
		jitter
	#end
	}
#end

#macro LightBox( Width, Height, Distance, Latitude, Longitude, Rotation, Colour )
	light_group {
		box {
			<-Width/2, -Height/2, 0>, < Width/2, Height/2, 0.01>
			translate -z*Distance
			rotate x* Longitude
			rotate y*Latitude
			material { 
				texture { 
					pigment { colour rgb 1 } 
					finish { ambient 1 }
				}
			}
		}

		#local dd = cos( Latitude ) * (Distance/2);
		#local xx = sin( Longitude ) * dd;
		#local yy = sin( Latitude ) * (Distance/2);
		#local zz = cos( Latitude ) * dd;

		light_source {
			< -xx, -yy, -zz >
			color Colour
		}		

	}
#end

LightBox( 6000, 4000, 2000, 180, 70, 0, rgb<1,1,1>*3 )
LightBox( 1000, 1000, 1200, -90, 10, 0, rgb<0,0,1>*1 )
LightBox( 1500, 600, 1000, 30, 10, 0, rgb<1,1,0>*1 )



// -- The Rest of the Scene ---------------------------------------------------

camera {
    location  <0.0, 200.0, -500.0>
    look_at   <0.0, 50,  0.0> // <0.0, 50,  0.0>
    right     x*image_width/image_height
    angle 30
#if( use_focal_blur )
    focal_point < 0.0, 50,  0.0 >
    aperture 6
    blur_samples 10
#end
}

sphere {
	0, 20
	translate y*20
	translate x*-70
	translate z*-50
	texture { finish { reflection 1 } }
}

plane {
    y, 0
    pigment { checker rgb 1 rgb 0.8 scale 100 }
}
