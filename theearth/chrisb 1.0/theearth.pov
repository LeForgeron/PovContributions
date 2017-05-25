
// TheEarth.pov
// ------------

// Sample scene that maps an image of the earth onto a sphere
// Created by Chris Bartlett 07.02.2005 
// Updated 2007 for inclusion in the POV-Ray Object Collection
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time 1 second
// Radius is 0.5 POV-Ray units
// Position is 0.5 POV-Ray units above the origin   
// The images included in the download come from http://www.evl.uic.edu/pape/data/Earth/ where
// there are higher resolution images along with alternative data representations. 
// They were created by Dave Pape, while a federal employee at NASA/GSFC and are copyright free.
// These images are in a cylindrical mapping.

camera {location  <4,2,-8> look_at <0,0.5,0> angle 10}
light_source {<-100, 10, -300> color rgb 1.5}    

#declare TheEarth_CloudsOn = 1;                                  // 0=No, 1=Yes
#declare TheEarth_Rotation = y*210;                              // Can be controlled by the clock    
#declare TheEarth_SourceImage = "theearth_bigearth.jpg";         // 'True' colour representation - high resolution
//#declare TheEarth_SourceImage = "theearth_topography.jpg";     // Colours indicate Heights and Depths
//#declare TheEarth_SourceImage = "theearth_mapperwdb.jpg";      // World DataBase Country markings


// The Earth itself
#declare TheEarth = sphere {<0,0.5,0>,0.5   
  texture {
    pigment {
      image_map {jpeg TheEarth_SourceImage map_type 2} // 2=Cylindrical Mapping    
    }  
    finish {ambient 0.03}
  }
}
 
// A crude cloud layer
#declare TheEarth_Clouds = sphere {<0,0.5,0>,0.501   
  texture {
    pigment {
      spotted  turbulence 1 omega 0.6
      color_map {
        [0.0   color rgb 1]
        [0.25  color rgb 1]
        [0.55  color rgbt 1]
        [1.0   color rgbt 1]
      } 
      scale <0.3,0.1,0.3>  
    }     
    finish {ambient 0.03}
  }
}
   
// Draw the objects
object {TheEarth rotate TheEarth_Rotation}  
#if (TheEarth_CloudsOn)
   object {TheEarth_Clouds}   
#end