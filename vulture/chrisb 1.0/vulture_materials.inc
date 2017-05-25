//
// vulture_materials.inc
// ---------------------
// Created by George Leonberger 2001  
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett
// This include file provides the materials used by the 'vulture.inc' file to add a
// Vulture Space Rocket to your scene from the US TV show Salvage 1. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The model is about 14 POV-Ray units in height and, by default is centred at the 
// origin sitting on the plane Y=0.
//
// Adding this model to your scene is likely to add a few seconds to the render time.
//
// See vulture.html for more details.
//


#declare Vulture_bodywraptexture = 
   material  // Vulture_bodywraptexture
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "vulture_body3.gif"
               map_type 2
               once
            }
            scale  <-1,1,1>
            rotate 90*x
         }      
         finish
         {
            ambient 0.2
            diffuse 0.65
            brilliance 1.5
            specular 0.85
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Vulture_tirtexture'


#declare Vulture_tirtexture = 
   material  // Vulture_tirtexture
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "vulture_tiretr.gif"
               map_type 2
               once
            }
            scale  <-1,1,1>
            rotate 90*x
         }
      }
   }


//  $MRY$: 'Vulture_tirecovertexture'


#declare Vulture_tirecovertexture = 
   material  // Vulture_tirecovertexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.145833, 0.145833, 0.145833>
         }
      }
   }


//  $MRY$: 'Vulture_landgeartexture'


#declare Vulture_landgeartexture = 
   material  // Vulture_landgeartexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.71875, 0.6875, 0.65625>
         }      
         finish
         {
            ambient 0.1
            diffuse 0.65
            brilliance 1.5
            specular 0.85
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Vulture_enginebelltexture'


#declare Vulture_enginebelltexture = 
   material  // Vulture_enginebelltexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.55, 0.5, 0.45>
         }      
         finish
         {
            ambient 0.1
            diffuse 0.65
            brilliance 1.5
            specular 0.85
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Vulture_enginetext2'


#declare Vulture_enginetext2 = 
   material  // Vulture_enginetext2
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "vulture_engtext.gif"
               map_type 2
               once
            }
            scale  <-1,1,1>
            rotate 90*x
         }      
         finish
         {
            ambient 0.2
            diffuse 0.65
            brilliance 1.5
            specular 0.85
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Vulture_cmmaintext'


#declare Vulture_cmmaintext = 
   material  // Vulture_cmmaintext
   {   
      texture
      {      
         pigment
         {
            color rgb <0.658824, 0.658824, 0.658824>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.65
            brilliance 1.5
            specular 0.85
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Vulture_dometexture'


#declare Vulture_dometexture = 
   material  // Vulture_dometexture
   {   
      texture
      {      
         pigment
         {
            color rgbf <0.0, 0.501961, 1.0, 0.7>
         }      
         finish
         {
            ambient 0.1
            diffuse 0.0
            specular 1.0
            roughness 0.001
            reflection
            {
               0.1 , 0.1
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }   
      interior
      {
         ior 1.5
      }
   }


//  $MRY$: 'Vulture_retrotexture'


#declare Vulture_retrotexture = 
   material  // Vulture_retrotexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.302067, 0.302067, 0.302067>
         }
      }
   }


//  $MRY$: 'Vulture_antennatext'


#declare Vulture_antennatext = 
   material  // Vulture_antennatext
   {   
      texture
      {      
         pigment
         {
            color rgb <0.843733, 0.843733, 0.843733>
         }
      }
   }


//  $MRY$: 'Vulture_thrustinttext'


#declare Vulture_thrustinttext = 
   material  // Vulture_thrustinttext
   {   
      texture
      {      
         pigment
         {
            color rgb <0.083333, 0.083333, 0.083333>
         }
      }
   }


//  $MRY$: 'Vulture_hatchsigntexture'


#declare Vulture_hatchsigntexture = 
   material  // Vulture_hatchsigntexture
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif "vulture_body3.gif"  // Should be "secure.gif"
               once
            }
         }      
         finish
         {
            ambient 0.2
            diffuse 0.65
            brilliance 1.5
            specular 0.85
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Vulture_blackwindowtext'


#declare Vulture_blackwindowtext = 
   material  // Vulture_blackwindowtext
   {   
      texture
      {      
         pigment
         {
            color rgb <0.104167, 0.104167, 0.104167>
         }      
         finish
         {
            ambient 0.1
            diffuse 0.1
            specular 1.0
            roughness 0.001
            reflection
            {
               0.25 , 0.25
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }   
      interior
      {
         ior 1.5
      }
   }
