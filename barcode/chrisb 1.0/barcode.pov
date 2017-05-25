//
// barcode.pov
// -----------
// Created by Chris Bartlett March 2008
// This scene file demonstrates the use of the BarCode macro to generate an EAN (European Article Number) barcode.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The barcodes fits into a cube from <0,0,0> <1,1,1>.
//
// Render times are typically a couple of seconds.  
//

light_source {   <-4,50 ,-100>, rgb 1}

camera {location <-0.3,0.7,-0.9> look_at<0.5,0,0.5>}


#include "barcode.inc" 

// The barcode object
object {BarCode_EAN(2, "348759873453", 0.6)
  pigment {rgb <0.6,0.9,1>}
  rotate y*50
  translate <0.2,0,0.1>
}  


// Using the object as a pigment
plane {y,-0.1
  texture {
    pigment {
      object {
        BarCode_EAN(0, "854634989387", 0.6)
        rotate x*90
        color <1,1,1,1>
        color <1,1,1>
      }
    }
    finish {reflection 0.25}
  } 
  rotate -y*20 
  translate -0.3*z
}

// Black bars on white background
box {0,<1,0.01,0.65>
  texture {
    pigment {
      object {
        BarCode_EAN(9, "349873772838", 0.6)
        rotate x*90
        color <1.2,1.2,1.2>
        color <0.2,0.2,0.2>
      }
    }
    finish {reflection 0.1}
    translate y*0.5
  } 
  rotate <-80,-38,0>
  translate -x*0.3 
}

#declare Laser = union {
  box {<-0.1,0.0002,-0.1><0.1,0.1,0.1>}
  light_source {0, rgb <4,0,0>}
  box {<-0.1,-0.0002,-0.1><0.1,-0.1,0.1>}
}

object {Laser rotate <-2,-3,-10> translate <-1,0.5,-1>}
object {Laser rotate <-85,-88,0> translate <0,0.3,-1>}

