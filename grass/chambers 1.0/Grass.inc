// File: bdc_grass.inc
// Grass generation macro
// Created by: Ben Chambers (ben@pacificwebguy.com)
// Submitted on February 22nd, 2007
// Version 1.0

// This file is licensed under the terms of the CC-LGPL.

// MIN is a vector specifying one corner of the box
// MAX is a vector specifying the other corner
// DENSITY is how many blades per unit square to generate
// WIDTH is the width of each blade of grass
// HEIGHT is the height of each blade of grass
// STEPS is the number of steps each blade should be divided into
// GRAVITY is a vector defining the direction (and magnitude) and gravity
// WIND is a vector defining the direction of wind (gets normalized).
// WIND_FUNCTION is a function defining the force of wind at any given point
// RSTRM is a random number stream
#macro bdc_grass(MIN, MAX, DENSITY, WIDTH, HEIGHT, STEPS, GRAVITY, WIND, WIND_FUNCTION, RSTRM)
	// Set up some simple values first
	#local BDC_GRASS_WIDTH = MAX.x - MIN.x;
	#local BDC_GRASS_DEPTH = MAX.z - MIN.z;
	
	#local BDC_GRASS_L = HEIGHT/STEPS;
	#local BDC_GRASS_HS = y*HEIGHT/STEPS;
	#local BDC_GRASS_GS = GRAVITY/STEPS;
	#local BDC_GRASS_WS = vnormalize(WIND)/STEPS;

	// First, find the number of blades we need to create
	#local BDC_BLADE_NUM = BDC_GRASS_WIDTH * BDC_GRASS_DEPTH * DENSITY;
	
	mesh {
	// Now, loop for all of them...
	#local BDC_BLADE_COUNT = 0;
	#while (BDC_BLADE_COUNT < BDC_BLADE_NUM)
		// Get the location of the blade.
		#local BDC_BLADE_X = rand(RSTRM)*BDC_GRASS_WIDTH+MIN.x;
		#local BDC_BLADE_Z = rand(RSTRM)*BDC_GRASS_DEPTH+MIN.z;
		
		#local BDC_BLADE_ROTATE = vrotate(x, y*rand(RSTRM)*360);
		#local BDC_GRASS_P1 = <BDC_BLADE_X, 0, BDC_BLADE_Z>;
		
		#local BDC_STEP_C = 0;
		#while (BDC_STEP_C < STEPS)
			#local BDC_GRASS_DELTA = BDC_GRASS_HS + BDC_GRASS_GS*BDC_STEP_C/STEPS + BDC_GRASS_WS*WIND_FUNCTION(BDC_GRASS_P1.x, BDC_GRASS_P1.y, BDC_GRASS_P1.z);
			#local BDC_GRASS_P2 = BDC_GRASS_P1 + BDC_GRASS_L*vnormalize(BDC_GRASS_DELTA);
			#local BDC_GRASS_A = BDC_GRASS_P1 + BDC_BLADE_ROTATE*WIDTH*(1-BDC_STEP_C/STEPS);
			#local BDC_GRASS_B = BDC_GRASS_P1 - BDC_BLADE_ROTATE*WIDTH*(1-BDC_STEP_C/STEPS);
			#local BDC_GRASS_C = BDC_GRASS_P2 + BDC_BLADE_ROTATE*WIDTH*(1-(BDC_STEP_C+1)/STEPS);
			#local BDC_GRASS_D = BDC_GRASS_P2 - BDC_BLADE_ROTATE*WIDTH*(1-(BDC_STEP_C+1)/STEPS);
			triangle {BDC_GRASS_A, BDC_GRASS_C, BDC_GRASS_B}
			triangle {BDC_GRASS_C, BDC_GRASS_D, BDC_GRASS_B}
			
			#local BDC_GRASS_P1 = BDC_GRASS_P2;
		#local BDC_STEP_C = BDC_STEP_C + 1;
		#end
	#local BDC_BLADE_COUNT = BDC_BLADE_COUNT + 1;
	#end
	}
#end
