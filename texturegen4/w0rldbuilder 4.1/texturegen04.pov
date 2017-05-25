//////////////////////////////////////////////////////////////
// File: texturegen02.pov                                   //
// Vers: 3.6                                                //
// Desc: An upgraded version of my TextureGen map generator.//
// This new version includes a terrestrial color map, as    //
// well as an upgraded version of the bump map included in  //
// the original. This new bump map is 50% darker, as the    //
// oceans are represented with a low, flat surface.         //
// Included in this new release is a specular/ocean mask,   //
// useful in other graphics programs as well as POV-Ray (?).//
// Also included in this new release is a Mars-like set of  //
// maps for desert planets. The Complexity and Detail       //
// controls are now included in the new include file. The   //
// include file now allows an unlimited number of maps to   //
// be included in TextureGen without having them take up    //
// space in the POV file, which allows the user to more     //
// easily change the map used without scrolling down to the //
// end of the file. The code for the sphere used to create  //
// the maps is now higher up in the file as well.           //
// Date: September 30, 2010                                 //
// Auth: w0rldbuilder                                       //
// This file is licensed under the terms of the CC-LGPL.    //
// This is an official release uploaded under a slightly    //
// username because I lost the password for the original    //
// worldbuilder account and can't get it back. >:(          //                
//////////////////////////////////////////////////////////////
// Maps icnluded are EarthMap, MarsMap, EarthBump, MarsBump, 
// EarthSpec, EarthClouds, MarsClouds, and Raw. Controls for 
// turbulence and detail are now in planetmaps.inc.

#include "planetmaps.inc"
#declare MapScale=0.5;
#declare RandomSeed=<0, 0, 0>;

sphere {
  RandomSeed
  MapScale       
  texture { MarsMap }
}



light_source {
  RandomSeed                 
  color rgb <1,1,1>    
}

light_source {
  RandomSeed                 
  color rgb <0.5,0.5,0.5>    
}
 
 
camera {
  spherical
  location RandomSeed      
  look_at  <0,0,1>     
  angle 360             
        180             
}




