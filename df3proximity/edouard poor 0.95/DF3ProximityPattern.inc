/*
 *	DF3 Proximity Pattern
 *

This include file was released by Edouard Poor of the Pov-Ray community, in 2009. It is my personal copy that I am posting to the Pov-Ray newsgroups as it is no longer available on the internet. All credit must go to Edouard.

Stephen McAvoy




 *		Version 0.95
 *			-	Major API overhaul
 *			-	Try to make everything automatic
 *
 *		Version 0.92
 *			-	Fixes the Proximity_SetMeshMode() macro to actually set
 *				the mesh mode...
 *
 *		Version 0.91
 *			-	Fixes where the centers of each voxel are when interpolating
 *				the DF3 data.
 *			-	Changes the API to require the resolution to be passed 
 *				to the Proximity_LoadMap() function.
 *			-	Adds a tunable bailout parameter for the voxel sampling
 *
 *		Version 0.9
 *			-	Initial Release
 *    
 */


// -- Include Files -----------------------------------------------------------

#include "arrays.inc"





// -- Internals Parameters and APIs -------------------------------------------

#declare Proximity_Version = 0.95;


#declare Proximity_Interpolation = 2;
#declare Proximity_MeshMode = false;
#declare Proximity_BailoutValue = -1;

#macro Proximity_SetInterpolation( n )
	#declare Proximity_Interpolation = n;
#end

#macro Proximity_SetMeshMode( bool )
	#declare Proximity_MeshMode = bool;
#end

#macro Proximity_SetBailoutValue( n )
	#declare Proximity_BailoutValue = n;
#end

#macro Proximity_SetBailoutOff()
	#declare Proximity_BailoutValue = -1;
#end


#declare Proximity_ShellSamplingGeometry = false;
	// true = Sample in a spherical shell distribution
	// false = Sample in a solid spherical distribution

#declare Proximity_SamplingDensity = 30;
	// approx num voxels to n*n*n for the bounding box

#declare Proximity_NumSamples = 100;
	// Number of samples top take at each sampling point (aka voxel)

#declare Proximity_PatternSmoothingMode = false;
#declare Proximity_PatternSmoothingValue = 20;
#declare Proximity_SmoothingRadius = 2.0;

#macro Proximity_SetPatternSmoothingValue( intValue )
	#declare Proximity_PatternSmoothingValue = intValue; 
#end

#macro Proximity_SetShellSamplingDistribution()
	#declare Proximity_ShellSamplingGeometry = true; 
#end

#macro Proximity_SetSolidSamplingDistribution()
	#declare Proximity_ShellSamplingGeometry = false; 
#end



#macro Proximity_SetPatternSmoothingMode( booleanValue )
	#declare Proximity_PatternSmoothingMode = booleanValue;
#end

/*
// #declare Proximity_SamplingSize = <30,30,30>;

#declare Proximity_SampleRadius = 1.0;
	// 1.0 = 2.5 voxels at <30,30,30>

// #declare Proximity_SampleRadius_Voxels = 2.5;
// #declare Proximity_SetSamplingRadiusInUnits_Units = <1,1,1>;

#declare Proximity_UsePOVBoundingBox = false;
	// for those cases where our tighter box is wrong

#declare Proximity_PatternSmoothingValue = 20;

#declare Proximity_PatternSmoothingMode = false;




#macro Proximity_SetSampes( intValue )
	#declare Proximity_NumSampes = intValue;
#end

#macro Proximity_SetSamplingRadius( floatValue )
	#declare Proximity_SampleRadius = floatValue;
#end

#macro Proximity_SetSamplingRadiusInVoxels( floatValue )
	#declare Proximity_SampleRadius_Voxels = floatValue;
#end

#macro Proximity_SetSamplingRadiusInUnits( vectorValue )
	#declare Proximity_SetSamplingRadiusInUnits_Units = vectorValue;
#end

#macro Proximity_UsePOVBoundingBoxes( booleanValue )
	#declare Proximity_UsePOVBoundingBox = booleanValue;
#end


#macro Proximity_SetPatternSmoothingValue( intValue )
	#declare Proximity_PatternSmoothingValue = intValue; 
#end


#macro Proximity_SetPatternSmoothingMode( booleanValue )
	#declare Proximity_PatternSmoothingMode = booleanValue;
#end


#macro Proximity_SetObjectBoundingBox( minVector, maxVector )
	#declare Proximity_ObjectBoundingBox = vectorValue;
#end


#macro Proximity_SetSamplingDensity( intValue )
	#declare Proximity_SamplingDensity = intValue;
#end


#macro Proximity_SetSamplingSize( vectorValue )
	#declare Proximity_SamplingSize =  vectorValue;
#end
*/


// -- Internal Methods --------------------------------------------

#macro Proximity_CalculateTightestBoundingBox( obj )
	/* Parameters */
	#local res = 200;  // TODO - make an option
	
	/* Result */
	#local out_min = max_extent( obj ) + 1;
	#local out_max = min_extent( obj ) - 1;
	
	/* Vars */
	#local stepx = ( max_extent( obj ).x - min_extent( obj ).x ) / res;
	#local stepy = ( max_extent( obj ).y - min_extent( obj ).y ) / res;
	#local stepz = ( max_extent( obj ).z - min_extent( obj ).z ) / res;
	#local xmax = max_extent( obj ).x;
	#local ymax = max_extent( obj ).y;
	#local zmax = max_extent( obj ).z ;

	/* XY Plane */
	#local xpos = min_extent( obj ).x;
	#local ypos = min_extent( obj ).y;
	#local zpos = min_extent( obj ).z - 100;
	
	#while ( xpos <= xmax )
		#local ypos = min_extent( obj ).y;
		#while( ypos <= ymax )
			#local norm = <0,0,0>;
			#local inter = trace( obj, <xpos,ypos,zpos>, z, norm );
			#if ( vlength( norm ) != 0 )
				#local out_min = < min( out_min.x, inter.x ), min( out_min.y, inter.y ), min( out_min.z, inter.z ) >;
				#local out_max = < max( out_max.x, inter.x ), max( out_max.y, inter.y ), max( out_max.z, inter.z ) >;
			#end
			
			#local ypos = ypos + stepy;
		#end

		#local xpos = xpos + stepx;	
	#end

	/* XZ Plane */
	#local xpos = min_extent( obj ).x;
	#local ypos = min_extent( obj ).y - 100;
	#local zpos = min_extent( obj ).z;
	
	#while ( xpos <= xmax )
		#local zpos = min_extent( obj ).z;
		#while( zpos <= ymax )
			#local norm = <0,0,0>;
			#local inter = trace( obj, <xpos,ypos,zpos>, y, norm );
			#if ( vlength( norm ) != 0 )
				#local out_min = < min( out_min.x, inter.x ), min( out_min.y, inter.y ), min( out_min.z, inter.z ) >;
				#local out_max = < max( out_max.x, inter.x ), max( out_max.y, inter.y ), max( out_max.z, inter.z ) >;
			#end
			
			#local zpos = zpos + stepz;
		#end

		#local xpos = xpos + stepx;	
	#end

	/* YZ Plane */
	#local xpos = min_extent( obj ).x - 100;
	#local ypos = min_extent( obj ).y;
	#local zpos = min_extent( obj ).z;
	
	#while ( ypos <= ymax )
		#local zpos = min_extent( obj ).z;
		#while( zpos <= zmax )
			#local norm = <0,0,0>;
			#local inter = trace( obj, <xpos,ypos,zpos>, x, norm );
			#if ( vlength( norm ) != 0 )
				#local out_min = < min( out_min.x, inter.x ), min( out_min.y, inter.y ), min( out_min.z, inter.z ) >;
				#local out_max = < max( out_max.x, inter.x ), max( out_max.y, inter.y ), max( out_max.z, inter.z ) >;
			#end
			
			#local zpos = zpos + stepz;
		#end

		#local ypos = ypos + stepy;
	#end

	#local out_min = out_min - <stepx, stepy, stepz>;
	#local out_max = out_max + <stepx, stepy, stepz>;

	/* Return result */
	#local result = array[2] { out_min, out_max };
	result
#end


#macro inside_m( obj, pos )
	#local current = pos;
	#local dir = <1,1,1>;
	#local done = 0;
	#local num = 0;
	#while ( done != 1 )
		#local norm = <0,0,0>;
		#local inter = trace( obj, current, dir, norm );
		#if ( vlength( norm ) != 0 )
			#local num = num + 1;
			#local current = inter + dir*0.001;
		#else
			#local done = 1;
		#end
	#end
	(mod( num, 2 ) = 1)
#end


#macro halton( index, base )
	#local out = 0.0;
	#local fraction = 1.0 / base;
	#local i = index;
	#while( i > 0 )
		#local remainder = mod( i, base );
		#local out = out + (fraction * remainder);
		#local i = int(i / base);
		#local fraction = fraction / base;
	#end

	out
#end


#macro halton3D( n )
	#local baseX = 2;
	#local baseY = 3;
	#local baseZ = 5;

	< halton( n, baseX ), halton( n, baseY ), halton( n, baseZ ) >
#end



// -- Debug API ---

#macro Proximity_DebugBoundingBox( obj, filename )
	/* Step 1. Read in saved values from PROX file */
	#fopen file concat( filename, ".prox") read
	#read( file, string, value )
	#if( string = "num_values" )
		#declare n = 0;
		#declare num_values = value;
		#while( n < num_values )
			#read( file, string, value )
			#if ( string = "df3_min_bounds" ) 
				#declare df3_min_bounds = value;
			#end
			#if ( string = "df3_max_bounds" ) 
				#declare df3_max_bounds = value;
			#end
			#if ( string = "df3_dimensions" ) 
				#declare df3_dimensions = value;
			#end
		#declare n = n + 1;
		#end
	#end
	#fclose file

	/* Step 2. Generate debug box */
	box {
		df3_min_bounds, df3_max_bounds
		pigment { rgbt <0,1,0,0.9> }
	}
#end

#macro Proximity_DebugGrid( obj, filename )
	/* Step 1. Read in saved values from PROX file */
	#fopen file concat( filename, ".prox") read
	#read( file, string, value )
	#if( string = "num_values" )
		#declare n = 0;
		#declare num_values = value;
		#while( n < num_values )
			#read( file, string, value )
			#if ( string = "df3_min_bounds" ) 
				#declare df3_min_bounds = value;
			#end
			#if ( string = "df3_max_bounds" ) 
				#declare df3_max_bounds = value;
			#end
			#if ( string = "df3_dimensions" ) 
				#declare df3_dimensions = value;
			#end
		#declare n = n + 1;
		#end
	#end
	#fclose file

	/* Step 2. Generate debug box */
	#declare temp = pigment {
		boxed
		warp {repeat x} warp {repeat y} warp {planar z, 0} //warp {repeat z} 
		scale (df3_max_bounds - df3_min_bounds) / df3_dimensions
		translate df3_min_bounds
		color_map {
			[ 0.00 color rgb 0 ]   // white stanchions
			[ 0.08 color rgb 1 ]  // black spaces
		}
	}
	
	temp
#end



// -- Public API --------------------------------------------------------------

#macro Proximity_GenerateMap( obj, filename )
	/* TODO */
	#local fraction = 2.5;
	#local num_samples = 100;

	/* Step 1. Setup the sampling array (halton seq) */
	#local halton_array = array[ num_samples ];
#if( Proximity_ShellSamplingGeometry = false )
	#local i = 0;
	#local j = 0;
	#while( i < num_samples )
		#local randomPoint = halton3D( j ) - 0.5;
		#if( vlength( randomPoint ) < 0.5 )
			#declare halton_array[ i ] = randomPoint;
			#local i = i + 1;
		#end
		#local j = j + 1;
	#end
#else
	#local i = 0;
	#while( i < num_samples )
		#local phi = halton( i, 2 ) * 2 * pi;
		#local zee = halton( i, 3 ) - 0.5;
		#local theta = asin( zee / 0.5 );
		#declare halton_array[ i ] = < 0.5 * cos(theta) * cos(phi), 0.5 * cos(theta) * sin(phi), zee >;
		#ev
		#local i = i + 1;
	#end
#end

	/* Step 2. Find tight bounds */
	#local tight_bounds = Proximity_CalculateTightestBoundingBox( obj );
	#local tight_min = tight_bounds[ 0 ];
	#local tight_max = tight_bounds[ 1 ];
	#local tight_extent = tight_max - tight_min;

	/* Step 3. Calculate voxel size */
	#local target_density = Proximity_SamplingDensity;
	#local tight_volume = tight_extent.x* tight_extent.y* tight_extent.z;
	#local cube_root = pow( tight_volume, 1/3 );
	#local voxel_dimensions = < int((tight_extent.x/cube_root)* target_density), int((tight_extent.y/cube_root)* target_density), int((tight_extent.z/cube_root)* target_density) >;
	#local voxel_dimensions = < max( voxel_dimensions.x, 4 ), max( voxel_dimensions.y, 4 ), max( voxel_dimensions.z, 4 ) >;
	#local voxel_size = tight_extent / voxel_dimensions;
	
	/* Step 4. Calculate extended sizes */
	#local extended_min = tight_min - voxel_size*2;
	#local extended_max = tight_max + voxel_size*2;
	#local extended_dimensions = voxel_dimensions + 4;
	
	/* Step 5. Create the proximity array */
	#local prox_array = array[extended_dimensions.x][extended_dimensions.y][extended_dimensions.z];

	/* Step 6. Calculate the proximity data */
	#local i = 0;
	#while( i < extended_dimensions.x )
		#local j = 0;
		#while( j < extended_dimensions.y )
			#local k = 0;
			#while( k < extended_dimensions.z )
				#local xpos = extended_min.x + (voxel_size.x / 2) + (i * voxel_size.x);
				#local ypos = extended_min.y + (voxel_size.y / 2) + (j * voxel_size.y);
				#local zpos = extended_min.z + (voxel_size.z / 2) + (k * voxel_size.z);
				#local numInside = 0;
				#local n = 0;
				#while( n < num_samples )
					#if( Proximity_MeshMode = true )
						#if( inside_m ( obj, <xpos, ypos, zpos> + halton_array [ n ] * voxel_size * fraction ) )
							#local numInside = numInside + 1;
						#end
					#else
						#if( inside ( obj, <xpos, ypos, zpos> + halton_array [ n ] * voxel_size * fraction ) )
							#local numInside = numInside + 1;
						#end
					#end
					#local n = n + 1;
					#if( n = Proximity_BailoutValue & (numInside = 0 | numInside = Proximity_BailoutValue) )
						#if( numInside = Proximity_BailoutValue )
							#local numInside  = num_samples;
						#end
						#local n = num_samples;
					#end
				#end
			#local prox_array[i][j][k] = numInside / num_samples;
			#local k = k + 1;
			#end
		#local j = j + 1;
		#end
	#local i = i + 1;
	#end

	/* Step 7. Write the DF3 file */
	ARRAYS_WriteDF3( prox_array, concat( filename, ".df3") , 8 )

	/* Step 8. Write the PROX file */
	#fopen file concat( filename, ".prox") write
	#write ( file "\"num_values\", ", 7, ",\n" )
	#write( file, "\"original_min_bounds\", ", min_extent( obj ), ",\n" )
	#write( file, "\"original_max_bounds\", ", max_extent( obj ), ",\n" )
	#write( file, "\"tighter_min_bounds\", ", tight_min, ",\n" )
	#write( file, "\"tighter_max_bounds\", ", tight_max, ",\n" )
	#write( file, "\"df3_min_bounds\", ", extended_min, ",\n" )
	#write( file, "\"df3_max_bounds\", ", extended_max, ",\n" )
	#write( file, "\"df3_dimensions\", ", extended_dimensions, ",\n" )
	#fclose file 
#end

#macro Proximity_LoadMap( obj, filename )
	/* Step 1. Read in saved values from PROX file */
	#fopen file concat( filename, ".prox") read
	#read( file, string, value )
	#if( string = "num_values" )
		#local n = 0;
		#local num_values = value;
		#while( n < num_values )
			#read( file, string, value )
			#if ( string = "original_min_bounds" ) 
				#local original_min_bounds = value;
			#end
			#if ( string = "original_min_bounds" ) 
				#local original_max_bounds = value;
			#end
			#if ( string = "df3_min_bounds" ) 
				#local df3_min_bounds = value;
			#end
			#if ( string = "df3_max_bounds" ) 
				#local df3_max_bounds = value;
			#end
			#if ( string = "df3_dimensions" ) 
				#local df3_dimensions = value;
			#end
		#local n = n + 1;
		#end
	#end
	#fclose file

	/* Step 2. Very simple error check */
	#if( original_min_bounds.x != min_extent( obj ).x | original_max_bounds.x != max_extent( obj ).x )
		#warning "WARNING: Object may have changed!"
	#end

	/* Step 3. Generate df3 pattern */
	#if( Proximity_PatternSmoothingMode = true )
		#local num_steps = Proximity_PatternSmoothingValue;
		#if( Proximity_Interpolation = 2 )
			#local interpolation_mode = 1;  // Seems to work better
		#end
	#else
		#local num_steps = 1;
		#local interpolation_mode = Proximity_Interpolation;
	#end

	#local halton_array = array[ num_steps ];
	#local i = 0;
	#local j = 103;
	#while( i < num_steps )
		#local randomPoint = halton3D( j ) - 0.5;
		#if( vlength( randomPoint ) < 0.5 )
			#local halton_array[ i ] = randomPoint;
			#local i = i + 1;
		#end
		#local j = j + 1;
	#end

	#declare temp = 
	pigment {
		average
		pigment_map {
#local n = 0;
#while( n < Proximity_PatternSmoothingValue )
			[ 1 
			density_file df3 concat( filename, ".df3" )
			interpolate Proximity_Interpolation
			scale df3_max_bounds - df3_min_bounds
			translate df3_min_bounds
			#if( Proximity_Interpolation != 0 )
				translate ( (df3_max_bounds - df3_min_bounds) / df3_dimensions ) / 2
					// Adjust for interpolation
			#end
			#if( Proximity_PatternSmoothingMode = true )
				//translate ( ( (df3_max_bounds - df3_min_bounds) / df3_dimensions ) * Proximity_SmoothingRadius ) * ( halton3D( n + 103 ) - 0.5 )
				translate ( ( (df3_max_bounds - df3_min_bounds) / df3_dimensions ) * Proximity_SmoothingRadius ) * ( halton_array[ n ] )
			#end
			]
#local n = n + 1;
#end
		}
	}

	/* Step 4. Return pattern */
	temp
#end

