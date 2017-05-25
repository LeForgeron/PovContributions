//
// eagle_materials.inc
// -------------------
// Created by George Leonberger 2001 as a Moray model 
// Adapted to go into the POV-Ray Object Collection Sept 2009 by Chris Bartlett
// This scene file adds materials to an Eagle Transporter from the TV show Space 1999. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// See eagle.html for more details.
// 

//
// ********  MATERIALS  *******
//


#declare Eagle_basic = 
   material  // Eagle_basic
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 1.0>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_windows'


#declare Eagle_windows = 
   material  // Eagle_windows
   {   
      texture
      {      
         pigment
         {
            color rgb <0.15, 0.15, 0.15>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_capSIDE'


#declare Eagle_capSIDE = 
   material  // Eagle_capSIDE
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_capsside.gif"
               once
               interpolate 2
            }
         }      
         finish
         {
            ambient 0.05
            diffuse 0.64
            brilliance 4.997
            phong 0.6
            phong_size 60.4
            specular 0.1
            reflection
            {
               0.44 , 0.44
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'Eagle_decal'


#declare Eagle_decal = 
   material  // Eagle_decal
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               tga   "eagle_decal.TGA"
               once
               interpolate 2
            }
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
         }
      }
   }


//  $MRY$: 'Eagle_Chrome_Metal1'


#declare Eagle_Chrome_Metal1 = 
   material  // Eagle_Chrome_Metal1
   {   
      texture
      {      
         pigment
         {
            color rgb <0.658824, 0.658824, 0.658824>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.7
            brilliance 8.0
            specular 0.8
            roughness 0.1
            reflection
            {
               0.15 , 0.15
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'Eagle_darkgrey'


#declare Eagle_darkgrey = 
   material  // Eagle_darkgrey
   {   
      texture
      {      
         pigment
         {
            color rgb <0.329, 0.329, 0.329>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_lightgrey'


#declare Eagle_lightgrey = 
   material  // Eagle_lightgrey
   {   
      texture
      {      
         pigment
         {
            color rgb <0.75, 0.75, 0.75>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_aluminum'


#declare Eagle_aluminum = 
   material  // Eagle_aluminum
   {   
      texture
      {      
         pigment
         {
            color rgb <0.94, 0.93, 0.9>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.65
            brilliance 6.0
            phong 1.0
            phong_size 100.0
         }
      }
   }


//  $MRY$: 'thrusters'


#declare thrusters = 
   material  // thrusters
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_thrust.gif"
               once
               interpolate 2
            }
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'yellow1'


#declare yellow1 = 
   material  // yellow1
   {   
      texture
      {      
         pigment
         {
            color rgb <0.698, 0.643, 0.0>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_bells'


#declare Eagle_bells = 
   material  // Eagle_bells
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_bells.gif"
               map_type 2
               once
               interpolate 2
            }
            scale  <-1,1,1>
            rotate 90*x
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_black'


#declare Eagle_black = 
   material  // Eagle_black
   {   
      texture
      {      
         pigment
         {
            color rgb <0.04, 0.04, 0.04>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_basic2'


#declare Eagle_basic2 = 
   material  // Eagle_basic2
   {   
      texture
      {      
         pigment
         {
            checker
               color rgb <0.9, 0.9, 0.9>
               color rgb <1.0, 1.0, 1.0>
            scale  <2.0, 2.0, 3.0>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_unknown'


#declare Eagle_unknown = 
   material  // Eagle_unknown
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 1.0>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_windowblack'


#declare Eagle_windowblack = 
   material  // Eagle_windowblack
   {   
      texture
      {      
         pigment
         {
            color rgb <0.03, 0.03, 0.03>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_maglocks'


#declare Eagle_maglocks = 
   material  // Eagle_maglocks
   {   
      texture
      {      
         pigment
         {
            color rgb <0.3, 0.3, 0.3>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_decals2'


#declare Eagle_decals2 = 
   material  // Eagle_decals2
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_decal2.gif"
               once
               interpolate 2
            }
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_cargobasic'


#declare Eagle_cargobasic = 
   material  // Eagle_cargobasic
   {   
      texture
      {      
         pigment
         {
            checker
               color rgb <0.9, 0.9, 0.9>
               color rgb <1.0, 1.0, 1.0>
            scale  <2.0, 2.0, 1.0>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_greenfloor'


#declare Eagle_greenfloor = 
   material  // Eagle_greenfloor
   {   
      texture
      {      
         pigment
         {
            color rgb <0.0, 1.0, 0.25098>
         }
      }
   }


//  $MRY$: 'Eagle_capsulewraptext'


#declare Eagle_capsulewraptext = 
   material  // Eagle_capsulewraptext
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_capwrap.gif"
               map_type 2
               once
            }
            scale  <-1,1,1>
            rotate 90*x
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
         }
      }
   }


//  $MRY$: 'Eagle_balltanktext'


#declare Eagle_balltanktext = 
   material  // Eagle_balltanktext
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_tankwrap.gif"
               map_type 2
               once
            }
            scale  <-1,1,1>
            rotate 90*x
         }
      }
   }


//  $MRY$: 'Eagle_balltank2text'


#declare Eagle_balltank2text = 
   material  // Eagle_balltank2text
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_btankwrap.gif"
               map_type 1
               once
            }
            scale  <-1,1,1>
            rotate 90*x
         }
      }
   }


//  $MRY$: 'Eagle_btank2sphere'


#declare Eagle_btank2sphere = 
   material  // Eagle_btank2sphere
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_btankwrap2.gif"
               map_type 1
            }
            scale  <-1,1,1>
            rotate 90*x
         }
      }
   }


//  $MRY$: 'Eagle_tankdettubing'


#declare Eagle_tankdettubing = 
   material  // Eagle_tankdettubing
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_tankstr.gif"
               map_type 2
            }
            scale  <-1,1,1>
            rotate 90*x
         }      
         finish
         {
            ambient 0.05
         }
      }
   }


//  $MRY$: 'Eagle_thrustcenter'


#declare Eagle_thrustcenter = 
   material  // Eagle_thrustcenter
   {   
      texture
      {      
         pigment
         {
            color rgb <0.94, 0.93, 0.9>
         }      
         finish
         {
            ambient 0.05
            diffuse 0.5
            phong_size 1.0
            specular 0.4
            roughness 0.01
         }
      }
   }


//  $MRY$: 'Eagle_cpinterior'


#declare Eagle_cpinterior = 
   material  // Eagle_cpinterior
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_cockpitint.gif"
               map_type 2
               once
            }
            scale  <-1,1,1>
            rotate 90*x
         }
      }
   }


//  $MRY$: 'Eagle_backwalltexture'


#declare Eagle_backwalltexture = 
   material  // Eagle_backwalltexture
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_backwalltx.gif"
               once
            }
         }
      }
   }


//  $MRY$: 'Eagle_maindoortexture'


#declare Eagle_maindoortexture = 
   material  // Eagle_maindoortexture
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 1.0>
         }
      }
   }


//  $MRY$: 'Eagle_doorframered'


#declare Eagle_doorframered = 
   material  // Eagle_doorframered
   {   
      texture
      {      
         pigment
         {
            color rgb <0.8, 0.26, 0.1>
         }
      }
   }


//  $MRY$: 'Eagle_door3text'


#declare Eagle_door3text = 
   material  // Eagle_door3text
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_door3.gif"
               once
            }
         }
      }
   }


//  $MRY$: 'suittexture'


#declare suittexture = 
   material  // suittexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.933, 0.3, 0.0>
         }
      }
   }


//  $MRY$: 'Eagle_neckringtexture'


#declare Eagle_neckringtexture = 
   material  // Eagle_neckringtexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.94, 0.93, 0.86>
         }      
         finish
         {
            ambient 0.25
            diffuse 0.65
            brilliance 6.0
            phong 1.0
            phong_size 100.0
            reflection
            {
               0.45 , 0.45
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'Eagle_packtexture'


#declare Eagle_packtexture = 
   material  // Eagle_packtexture
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 1.0>
         }      
         finish
         {
            ambient 0.3
            diffuse 0.5
            phong 0.7
            phong_size 20.0
         }
      }
   }


//  $MRY$: 'Eagle_helmettexture'


#declare Eagle_helmettexture = 
   material  // Eagle_helmettexture
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 0.614567, 0.0>
         }
      }
   }


//  $MRY$: 'Eagle_visortexture'


#declare Eagle_visortexture = 
   material  // Eagle_visortexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.927067, 0.405499, 0.0>
         }      
         finish
         {
            ambient 0.1
            diffuse 0.1
            phong 0.6043
            phong_size 29.136667
            reflection
            {
               0.18 , 0.18
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'Eagle_chestunittext'


#declare Eagle_chestunittext = 
   material  // Eagle_chestunittext
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_chesttext.gif"
               once
            }
         }
      }
   }


//  $MRY$: 'Eagle_straptexture'


#declare Eagle_straptexture = 
   material  // Eagle_straptexture
   {   
      texture
      {      
         pigment
         {
            color rgb <0.0, 0.0, 0.0>
         }
      }
   }


//  $MRY$: 'Eagle_instpaneltext'


#declare Eagle_instpaneltext = 
   material  // Eagle_instpaneltext
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_1999inst.gif"
               once
            }
         }      
         finish
         {
            ambient 1.0
         }
      }
   }


//  $MRY$: 'Eagle_instpaneltext2'


#declare Eagle_instpaneltext2 = 
   material  // Eagle_instpaneltext2
   {   
      texture
      {      
         pigment
         {
            image_map
            {
               gif   "eagle_1999inst.gif"
               once
            }
         }      
         finish
         {
            ambient 0.95
         }
      }
   }
