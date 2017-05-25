//////////////////////////////////////////////////////////////////////////////
// Persistence of Vision Ray Tracer Scene Description File                  //
// File: texturegen.pov                                                     //
// Vers: 3.6                                                                //
// Desc: RandomSeed is not a true random seed; it is instead the location   //
// of the camera and the sphere. The texture changes according to position. //
// LevelOfDetail changes the size of the details.                           //
// 0.25 and 0.5 Good for asteroid models                                    //
// 0.75 - 1.5   Nice general height map for planets                         //
// 2 and up     Good detailed map for planets, should be combined with      //
// general map with soft light blend mode in Photoshop                      //
// To add more detail to planet map use layers and flatten image, then      //
// decrease contrast and add another level of detail                        //
// There comes a point when you can't add any more detail, when the next    //
// level of detail turns continents into immense clusters of islands. For   //
// me, using levels 1-8 is good enough. Add level 32, however, and it       //
// becomes useless (unless you are trying to make a planet of islands) and  //
// you have to go to the Edit menu and click that Undo command.             //
// TerrainType specifies what type of noise to use when generating the map. //
// You can use any pattern, even non-random ones, but I recommend bozo and  //
// wrinkles. Agate, granite and crackle also give good results. Heck, even  //
// leopard and ripples look good with the right amount of Complexity!       //
// NoiseType tells POV-Ray what version of the noise to use: 1 creates      //
// plateaus at the highest points, 2 is the old noise generator fixed (no   //
// plateaus) and 3 is Perlin noise.                                         //
// Date: October 2, 2009                                                    //
// Auth: worldbuilder                                                       //
// Use command line options to create maps suitable for Celestia or         //
// Anim8or                                                                  //
// -w1024 -h512                                                             //
// -w2048 -h1024                                                            //
// -w4096 -h2048                                                            //
// This file is licensed under the terms of the CC-LGPL.                    //
// I didn't want to say that. :-)                                           //
//////////////////////////////////////////////////////////////////////////////
#declare RandomSeed = <84, 64, 536>;                                            
#declare LevelOfDetail = 1;                                                 
#declare Complexity = 1;
#declare TerrainType = pigment { wrinkles };
#declare NoiseType = 3; 
                                                    
                                                                            
#include "colors.inc"                                                       
                                                                            
camera {     // Gets the texture, change lookat point to rotate map 
  spherical
  location RandomSeed     
  look_at  <0,0,1>      
  angle 360             
        180             
}

sphere {   // Texture surface
  RandomSeed 
  LevelOfDetail      
  texture {
  pigment {
  TerrainType noise_generator NoiseType
  turbulence Complexity
  color_map { [0.0 Black] [1.0 White] }
  }
  finish { ambient 1 }
}
}





