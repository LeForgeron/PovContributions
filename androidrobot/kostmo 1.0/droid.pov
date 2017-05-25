//This file is licensed under the terms of the CC-LGPL

// Author: Karl Ostmo
// Date: 10/30/2009

#include "colors.inc"
#include "metals.inc"

// See http://www.android.com/branding.html
// and http://en.wikipedia.org/wiki/File:Android-logo.svg

/*
plane {
   <0, 1, 0>, 0
   
   pigment {
      checker 
      color rgb <0, 0, 0>
      color rgb <1, 1, 1>
   }
   translate y*(-0.55)
}
*/
light_source {
   <2.8, 2, -2.83333>, rgb <1, 1, 1>
}

camera {
   perspective
   location <2, 1.2, -0.3>
   sky <0, 1, 0>
   direction <0, 0, 1>
   right <1.33333, 0, 0>
   up <0, 1, 0>
   look_at <0, 0.5, 0>
}

#declare antennae_angle = 30;
#declare antennae_length = 0.2;
#declare eye_height = 0.8;

#declare Antenna = cylinder {
	<0, antennae_length, 0>, <0, 0, 0>, 0.02
}

#declare Arm = merge {
     sphere {
        <0, 0, 0>, 0.1
        translate <0, 0.5, 0>
     }
     
     cylinder {
        <0, 0.5, 0>, <0, 0.1, 0>, 0.1
     }
     
     sphere {
        <0, 0.1, 0>, 0.1
     }
}

#declare Leg = merge {
         cylinder {
            <0, 0.5, 0>, <0, -0.2, 0>, 0.1
            translate <0, -0.25, 0>
         }
         sphere {
            <0, -0.2, 0>, 0.1
            translate <0, -0.25, 0>
         }
      }


#declare EyeSocket = cylinder {
            <0, 0.5, 0>, <0, 0, 0>, 0.05
            rotate z*(-90)
            translate <0, eye_height, 0>
         }


merge {
   merge {
      object{ Antenna
      rotate x*(-antennae_angle)
         translate <0, 1, -0.25>}
      
      object{ Antenna
      rotate x*(antennae_angle)
         translate <0, 1, 0.25>}
   }
   
   merge {
      object{ Arm
            translate z*(-0.6)}

      object{ Arm
            translate z*(0.6)}
   }
   
   merge {
      object{ Leg
            translate z*(.25)}
  
        object{ Leg
            translate z*(-.25)}
   }

   difference {
      // Head and Torso
      
      merge {
         // Torso
         
         cylinder {
            <0, 0.6, 0>, <0, -0.1, 0>, 0.5
         }
         
         sphere {
            <0, 0.6, 0>, 0.5
         }
         
         torus {
            0.4, 0.1
            translate y*(-0.1)
         }
         
         cylinder {
            <0, 0.1, 0>, <0, -0.2, 0>, 0.4
         }
      }
      
      cylinder {
      	// Head-torso spacing
         <0, 0.65, 0>, <0, 0.6, 0>, 0.6
      }
      
      merge {
         // Eye sockets
           object{ EyeSocket
            translate z*(-.25)}
           object{ EyeSocket
            translate z*(.25)}
     }

   }
   
   // Android Green is: #A4C639 or <0.64, 0.78, 0.22>
   
	pigment {
		MediumSpringGreen
	}
	/*
	finish {
		F_MetalD	
		ambient 0.2
		diffuse 0.6
	}
	*/
}