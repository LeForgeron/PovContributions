// Copyright David Barnard, 2008
// This file is licensed under the terms of the CC-LGPL

#include "colors.inc"
#include "Biro.inc"

camera {
  angle 30
  location <-180,120,-150>
  look_at <-35,0,0>
}

light_source {<50,400,-200> color VLightGrey}     

sky_sphere {
  pigment {
    gradient y
    color_map { [0.0 color rgb <0.9,0.9,1.0>] [1.0 color blue 0.7] }
  }
}


// Blue pen, cap off
union {
  object {
    Biro(rgb <0.2,0,0.7>)
  }
  object {
    Biro_Cap(rgb <0.2,0,0.7>)
    rotate <-120,0,0>
    translate <60,0,-20>
  }  
}


// Black pen, cap on.
union {
  object {
    Biro(Gray05)
  }
  object {
    Biro_Cap(Gray05)
  }
  translate <0,0,15>
}
