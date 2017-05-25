//
// eyesection_meterials.inc
// ------------------------
//
// Materials created by Israel Barzel 1997  
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett
// This include file contains the material declarations used by the 'eyesection.inc'
// file to add a model of the section of an eye to your scene. It also declares
// textures for tools used to perform Phacoemulcification (modern cataract 
// surgery).
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// See eyesection.html for more details
//


#declare EyeSection_WhiteMaterial = 
   material  // EyeSection_WhiteMaterial
   {   
      texture
      {      
         pigment
         {
            color rgbf <1.0, 1.0, 1.0, 0.504>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'EyeSection_GoldMaterial'


#declare EyeSection_GoldMaterial = 
   material  // EyeSection_GoldMaterial
   {   
      texture
      {      
         pigment
         {
            color rgb <0.85, 0.85, 0.1>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.7
            brilliance 6.0
            phong 0.75
            phong_size 80.0
            metallic 1.0
            reflection
            {
               0.36 , 0.36
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'EyeSection_GreenMaterial'


#declare EyeSection_GreenMaterial = 
   material  // EyeSection_GreenMaterial
   {   
      texture
      {      
         pigment
         {
            color rgbf <0.0, 0.777, 0.726, 0.518>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'EyeSection_ChromeMetalMaterial'


#declare EyeSection_ChromeMetalMaterial = 
   material  // EyeSection_ChromeMetalMaterial
   {   
      texture
      {      
         pigment
         {
            color rgb <0.658824, 0.658824, 0.658824>
         }      
         finish
         {
            ambient 0.3
            diffuse 0.7
            brilliance 8.0
            specular 0.8
            roughness 0.1
            metallic 1.0
            reflection
            {
               0.2 , 0.2
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'EyeSection_TransparentMaterial11'


#declare EyeSection_TransparentMaterial2 = 
   material  // EyeSection_TransparentMaterial11
   {   
      texture
      {      
         pigment
         {
            color rgbf <1.0, 1.0, 1.0, 1.0>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong_size 1.0
            specular 0.05
            roughness 0.001
         }
      }
   }


//  $MRY$: 'EyeSection_ChoroidMaterial'


#declare EyeSection_ChoroidMaterial = 
   material  // EyeSection_ChoroidMaterial
   {   
      texture
      {      
         pigment
         {
            marble
            color_map
            {
               [ 0.0     rgbft <0.854133, 0.0, 0.0, 0.0, 0.0> ]
               [ 1.0     rgbft <0.916667, 0.364567, 0.0, 0.000467, 0.0> ]
            }
            turbulence 0.75
            omega 1.0
            lambda 2.009
            frequency 0.1
            ramp_wave
         }      
      }
   }


//  $MRY$: 'EyeSection_IrisMaterial1'


#declare EyeSection_IrisMaterial1 = 
   material  // EyeSection_IrisMaterial1
   {   
      texture
      {      
         pigment
         {
            radial
            pigment_map
            {
               [0.0   
                  color rgb <0.25, 0.125, 0.0>
               ]
               [0.9509
                  color rgb <0.0, 0.0, 0.0104>
               ]
               [1.0   
                  color rgb <0.109353, 0.060749, 0.036447>
               ]
            }
            rotate -90*x
            turbulence 0.5
            omega 0.0
            lambda 9.0
            frequency 100.0
            ramp_wave
         }      
         normal
         {
            bumps , 10.0
            bump_size 20.0
            scale  0.1
         }
      }
   }


//  $MRY$: 'EyeSection_IrisCutAwayMaterial'


#declare EyeSection_IrisCutAwayMaterial = 
   material  // EyeSection_IrisCutAwayMaterial
   {   
      texture
      {      
         pigment
         {
            marble
            color_map
            {
               [ 0.0     rgbft <0.438514, 0.176053, 0.176053, 0.0, 0.0> ]
               [ 1.0     rgbft <0.389621, 0.172846, 0.172846, 0.0, 0.0> ]
            }
            turbulence 5.0
            omega 6.0
            ramp_wave
         }      

      }
   }


//  $MRY$: 'EyeSection_ScleraMaterial'


#declare EyeSection_ScleraMaterial = 
   material  // EyeSection_ScleraMaterial
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 1.0>
         }      
         finish
         {
            ambient 0.36
            diffuse 0.5
            phong_size 1.0
            specular 0.41
            roughness 0.01
         }
      }
   }


//  $MRY$: 'EyeSection_CorneaMaterial'


#declare EyeSection_CorneaMaterial = 
   material  // EyeSection_CorneaMaterial
   {   
      texture
      {      
         pigment
         {
            color rgbf <1.0, 1.0, 1.0, 0.851>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong 0.25
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'EyeSection_TransparentMaterial1'


#declare EyeSection_TransparentMaterial1 = 
   material  // EyeSection_TransparentMaterial1
   {   
      texture
      {      
         pigment
         {
            color rgbf <1.0, 1.0, 1.0, 1.0>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong_size 1.0
            roughness 0.01
         }
      }
   }


//  $MRY$: 'EyeSection_ZonularFibersMaterial'


#declare EyeSection_ZonularFibersMaterial = 
   material  // EyeSection_ZonularFibersMaterial
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 0.80376, 0.12>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            brilliance 9.655
            phong_size 1.0
            specular 0.4
            roughness 0.01
            metallic 1.0
         }
      }
   }


//  $MRY$: 'EyeSection_CornealCrossSectionMaterial'


#declare EyeSection_CornealCrossSectionMaterial = 
   material  // EyeSection_CornealCrossSectionMaterial
   {   
      texture
      {      
         pigment
         {
            color rgbft <0.802067, 0.854167, 0.838854, 0.583333, 0.0208>
         }
      }
   }


//  $MRY$: 'EyeSection_RetinaMaterial'


#declare EyeSection_RetinaMaterial = 
   material  // EyeSection_RetinaMaterial
   {   
      texture
      {      
         pigment
         {
            gradient z
            color_map
            {
               [ 0.0     rgbft <0.687467, 0.0, 0.0, 0.0, 0.0> ]
               [ 1.0     rgbft <1.0, 1.0, 1.0, 1.0, 1.0> ]
            }
            turbulence 0.5
            octaves 1
            omega 0.0
            lambda 0.0
            frequency 0.0
            ramp_wave
         }      
         scale  <0.1, 0.1, 50.0>
      }
   }


//  $MRY$: 'EyeSection_GrayMaterial'


#declare EyeSection_GrayMaterial = 
   material  // EyeSection_GrayMaterial
   {   
      texture
      {      
         pigment
         {
            color rgb <0.75, 0.75, 0.75>
         }
      }
   }


//  $MRY$: 'EyeSection_YellowMaterial'


#declare EyeSection_YellowMaterial = 
   material  // EyeSection_YellowMaterial
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 0.1354>
         }      
         finish
         {
            ambient 0.1
            specular 0.1151
            metallic 1.0
         }
      }
   }


//  $MRY$: 'EyeSection_IrisMaterial2'


#declare EyeSection_IrisMaterial2 = 
   material  // EyeSection_IrisMaterial2
   {   
      texture
      {      
         pigment
         {
            radial
            pigment_map
            {
               [0.0   
                  color rgb <0.25, 0.125, 0.0>
               ]
               [0.9509
                  color rgb <0.0, 0.0, 0.0104>
               ]
               [1.0   
                  color rgb <0.109353, 0.060749, 0.036447>
               ]
            }
            rotate -90*x
            turbulence 0.5
            omega 0.0
            lambda 9.0
            frequency 100.0
            ramp_wave
         }      
         normal
         {
            bumps , 10.0
            bump_size 20.0
            scale  0.1
         }
      }
   }


#declare EyeSection_LensMaterial = 
   material  // EyeSection_LensMaterial
   {   
      texture
      {      
         pigment
         {
            color rgbf <1.0, 1.0, 1.0, 0.753>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong 0.17
            phong_size 1.0
            roughness 0.01
         }
      }
   }


//  $MRY$: 'EyeSection_NucleusMaterial1'


#declare EyeSection_NucleusMaterial1 = 
   material  // EyeSection_NucleusMaterial1
   {   
      texture
      {      
         pigment
         {
            color rgbf <0.7604, 0.996749, 1.0, 0.312467>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'EyeSection_NucleusMaterial2'


#declare EyeSection_NucleusMaterial2 = 
   material  // EyeSection_NucleusMaterial2
   {   
      texture
      {      
         pigment
         {
            color rgbf <0.645833, 1.0, 1.0, 0.375>
         }      
         finish
         {
            ambient 0.2
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


