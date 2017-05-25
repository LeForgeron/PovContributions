//
// eagle.inc
// ---------
// Created by George Leonberger 2001 as a Moray model 
// Adapted to go into the POV-Ray Object Collection Sept 2009 by Chris Bartlett
// This scene file adds an Eagle Transporter to your scene from the TV show Space 1999. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The model is about 40 POV-Ray units in length and, by default is centred at the 
// origin sitting on the plane Y=0.
//
// Adding this model to your scene is likely to add a couple of minutes to the render time.
//
// See eagle.html for more details.
// 


//
// *******  L I G H T S *******
//

#declare Eagle_cockpitlight2 = light_source {   // Spotlight Eagle_cockpitlight2
  <0.0, 0.0, 0.0>
  color rgb <1.000, 1.000, 1.000>*0.7351
  spotlight
    point_at  <0.0, 0.0, -2.000>
    falloff    30.000  // outer radius (in deg)
    radius     25.000  // inner radius
    tightness  0.000
  media_interaction off
  photons {
  }
  scale 0.144266
  rotate <129.285904, -14.219927, 1.7979>
  translate  <-0.525594, -24.915005, -1.548758>
}

#declare Eagle_cockpitlight1 = light_source {   // Spotlight Eagle_cockpitlight1
  <0.0, 0.0, 0.0>
  color rgb <1.000, 1.000, 1.000>*0.7351
  spotlight
    point_at  <0.0, 0.0, -2.000>
    falloff    30.000  // outer radius (in deg)
    radius     25.000  // inner radius
    tightness  0.000
  media_interaction off
  photons {
  }
  scale 0.144266
  rotate <129.285904, -14.219927, 1.7979>
  translate  <2.196577, -24.910469, -1.549>
}

#declare Eagle_Light002 = light_source {
  <0.0, 0.0, 0.0>
  color rgb <0.829, 0.903, 1.000>
  media_interaction off
  photons {
  }
  translate  <0.694493, -24.913224, -0.968917>
}


//
// ********  MATERIALS  *******
//

#include "Eagle_materials.inc"


//
// ********  REFERENCED OBJECTS  *******
//



//
// ********  OBJECTS  *******
//

#declare Eagle_framunion4 = union {
  cylinder { // frame78
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
    translate  <-1.1, 0.0, -0.65>
  }
  cylinder { // frame79
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
  }
  cylinder { // frame80
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, -21.002718>
    translate  <-0.076638, -0.146488, -0.045244>
  }
  cylinder { // frame81
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000896, -0.100081, -0.000549>
  }
  cylinder { // frame82
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, 20.906914>
    translate  <-1.02302, -0.144362, -0.603947>
  }
  cylinder { // frame83
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000024, -2.6004, -0.000035>
  }
  cylinder { // fram20
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -2.617556, -0.651328>
  }
  cylinder { // fram21
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -0.117556, -0.651328>
  }
  cylinder { // fram22
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, -0.0, 0.0>
    translate  <-1.099652, -0.116634, -1.281832>
  }
  cylinder { // fram23
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -1.367556, -0.651328>
  }
  cylinder { // frame84
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <-1.1, -2.717556, -1.951832>
  }
  cylinder { // frame85
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <0.0, -2.717556, -2.601832>
  }
  cylinder { // frame86
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, 21.002718>
    translate  <-0.076638, -2.571068, -2.556588>
  }
  cylinder { // frame87
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000896, -2.617475, -2.601282>
  }
  cylinder { // frame88
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, -20.906914>
    translate  <-1.02302, -2.573194, -1.997885>
  }
  cylinder { // frame89
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000024, -0.117157, -2.601797>
  }
  cylinder { // topcross12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -2.601832>
  }
  cylinder { // topcross13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -2.601832>
  }
  cylinder { // topcross14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -0.001832>
  }
  cylinder { // topcross15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -0.001832>
  }
  cylinder { // topcross16
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -1.367558, -0.001832>
  }
  cylinder { // frame90
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <4.2, -2.717556, -0.65>
  }
  cylinder { // frame91
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <3.1, -2.717556, -0.0>
  }
  cylinder { // frame92
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, 158.997284>
    translate  <3.176638, -2.571068, -0.045244>
  }
  cylinder { // frame93
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100896, -2.617475, -0.00055>
  }
  cylinder { // frame94
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, -159.093079>
    translate  <4.12302, -2.573194, -0.603947>
  }
  cylinder { // frame95
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100024, -0.117157, -0.000035>
  }
  cylinder { // fram24
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -0.1, -0.651329>
  }
  cylinder { // fram25
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -2.6, -0.651329>
  }
  cylinder { // fram26
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, 0.0, -180.0>
    translate  <4.199652, -2.600923, -1.281832>
  }
  cylinder { // fram27
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -1.35, -0.651329>
  }
  cylinder { // frame96
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <4.2, 0.0, -1.951832>
  }
  cylinder { // frame97
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <3.1, 0.0, -2.601832>
  }
  cylinder { // frame98
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, -158.997284>
    translate  <3.176638, -0.146488, -2.556588>
  }
  cylinder { // frame99
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100896, -0.100081, -2.601283>
  }
  cylinder { // frame100
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, 159.093094>
    translate  <4.12302, -0.144362, -1.997885>
  }
  cylinder { // frame101
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100024, -2.6004, -2.601797>
  }
  photons {
    collect off
  }
  rotate <180.0, -0.0, -180.0>
  translate  <3.1, 2.7, -2.601832>
}
#declare Eagle_framunion5 = union {
  cylinder { // frame102
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
    translate  <-1.1, 0.0, -0.65>
  }
  cylinder { // frame103
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
  }
  cylinder { // frame104
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, -21.002718>
    translate  <-0.076638, -0.146488, -0.045244>
  }
  cylinder { // frame105
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000896, -0.100081, -0.000549>
  }
  cylinder { // frame106
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, 20.906914>
    translate  <-1.02302, -0.144362, -0.603947>
  }
  cylinder { // frame107
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000024, -2.6004, -0.000035>
  }
  cylinder { // fram28
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -2.617556, -0.651328>
  }
  cylinder { // fram29
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -0.117556, -0.651328>
  }
  cylinder { // fram30
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, -0.0, 0.0>
    translate  <-1.099652, -0.116634, -1.281832>
  }
  cylinder { // fram31
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -1.367556, -0.651328>
  }
  cylinder { // frame108
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <-1.1, -2.717556, -1.951832>
  }
  cylinder { // frame109
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <0.0, -2.717556, -2.601832>
  }
  cylinder { // frame110
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, 21.002718>
    translate  <-0.076638, -2.571068, -2.556588>
  }
  cylinder { // frame111
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000896, -2.617475, -2.601282>
  }
  cylinder { // frame112
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, -20.906914>
    translate  <-1.02302, -2.573194, -1.997885>
  }
  cylinder { // frame113
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000024, -0.117157, -2.601797>
  }
  cylinder { // topcross17
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -2.601832>
  }
  cylinder { // topcross18
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -2.601832>
  }
  cylinder { // topcross19
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -0.001832>
  }
  cylinder { // topcross20
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -0.001832>
  }
  cylinder { // topcross21
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.0, -0.001832>
  }
  cylinder { // frame114
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <4.2, -2.717556, -0.65>
  }
  cylinder { // frame115
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <3.1, -2.717556, -0.0>
  }
  cylinder { // frame116
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, 158.997284>
    translate  <3.176638, -2.571068, -0.045244>
  }
  cylinder { // frame117
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100896, -2.617475, -0.00055>
  }
  cylinder { // frame118
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, -159.093079>
    translate  <4.12302, -2.573194, -0.603947>
  }
  cylinder { // frame119
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100024, -0.117157, -0.000035>
  }
  cylinder { // fram32
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -0.1, -0.651329>
  }
  cylinder { // fram33
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -2.6, -0.651329>
  }
  cylinder { // fram34
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, 0.0, -180.0>
    translate  <4.199652, -2.600923, -1.281832>
  }
  cylinder { // fram35
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -1.35, -0.651329>
  }
  cylinder { // frame120
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <4.2, 0.0, -1.951832>
  }
  cylinder { // frame121
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <3.1, 0.0, -2.601832>
  }
  cylinder { // frame122
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, -158.997284>
    translate  <3.176638, -0.146488, -2.556588>
  }
  cylinder { // frame123
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100896, -0.100081, -2.601283>
  }
  cylinder { // frame124
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, 159.093094>
    translate  <4.12302, -0.144362, -1.997885>
  }
  cylinder { // frame125
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100024, -2.6004, -2.601797>
  }
  photons {
    collect off
  }
  rotate <180.0, -0.0, -180.0>
  translate  <3.1, 0.0, -2.601832>
}
#declare Eagle_rearframeassembly = union {
  cylinder { // fram36
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.302>
    rotate <-0.0, -0.0, -180.0>
    translate  <4.19856, -2.818, -1.957155>
  }
  cylinder { // frame126
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.278>
    rotate <124.447067, 25.927099, 106.728554>
    translate  <3.09754, -2.818, -0.00488>
  }
  cylinder { // topcross22
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <-90.0, -0.0, -90.0>
    translate  <-0.001422, -2.818, -0.005414>
  }
  cylinder { // frame127
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.278>
    rotate <124.44957, 25.926426, -73.27037>
    translate  <-0.000619, -2.818, -0.004895>
  }
  cylinder { // fram37
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.302>
    rotate <180.0, 0.0, 0.0>
    translate  <-1.101251, -2.818, -0.654858>
  }
  cylinder { // frame128
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.277>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000738, -2.818, -2.60583>
  }
  cylinder { // topcross23
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.098552, -2.818, -2.607113>
  }
  cylinder { // frame129
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.278>
    rotate <-55.551392, -25.92668, -106.729248>
    translate  <3.097723, -2.818, -2.60762>
  }
  cylinder { // frame130
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, 0.0, 0.0>
    translate  <-0.001446, -2.93, -2.607145>
  }
  cylinder { // frame131
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, 0.0, 0.0>
    translate  <-1.101446, -2.93, -1.957145>
  }
  cylinder { // frame132
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, 0.0, 0.0>
    translate  <-1.101446, -2.71, -0.655313>
  }
  cylinder { // frame133
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, 0.0, 0.0>
    translate  <-0.001446, -2.71, -0.005313>
  }
  cylinder { // frame134
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, -0.0, 180.0>
    translate  <3.098554, -2.93, -0.005314>
  }
  cylinder { // frame135
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, -0.0, 180.0>
    translate  <4.198554, -2.93, -0.655314>
  }
  cylinder { // frame136
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, -0.0, 180.0>
    translate  <4.198554, -2.71, -1.957145>
  }
  cylinder { // frame137
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.2>
    rotate <90.0, -0.0, 180.0>
    translate  <3.098554, -2.918, -0.005314>
  }
  cylinder { // frame138
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, -0.0, 180.0>
    translate  <3.098554, -2.71, -2.607145>
  }
  cylinder { // frame139
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, -2.83, -0.005314>
  }
  cylinder { // frame140
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, -2.83, -2.607145>
  }
  cylinder { // frame141
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, -2.83, -1.287249>
  }
  cylinder { // frame142
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, -2.83, -1.28713>
  }
  cylinder { // frame143
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, -0.1, -2.607145>
  }
  cylinder { // frame144
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, 0.1, -2.607145>
  }
  cylinder { // frame145
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, 2.61, -2.607145>
  }
  cylinder { // frame146
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, -0.1, -0.005314>
  }
  cylinder { // frame147
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, 0.1, -0.005314>
  }
  cylinder { // frame148
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, 2.61, -0.005314>
  }
  cylinder { // frame149
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, 2.6, -1.28713>
  }
  cylinder { // frame150
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, -0.1, -1.28713>
  }
  cylinder { // frame151
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, 0.1, -1.28713>
  }
  cylinder { // frame152
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, -0.1, -1.287249>
  }
  cylinder { // frame153
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, 0.1, -1.287249>
  }
  cylinder { // frame154
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, 2.6, -1.287249>
  }
  photons {
    collect off
  }
  rotate <180.0, 0.0, -180.0>
  translate  <3.098554, -0.01, -2.607145>
}
#declare Eagle_opendivider = prism {
  linear_sweep
  linear_spline
  -0.8,0.0
  5  // control points
  <-1.0, -1.0>,
  <0.319381, -0.51676>,
  <0.312574, 0.509954>,
  <-1.0, 1.0>,
  <-1.0, -1.0>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.407554, 0.717692, 0.717692>
  rotate <90.0, 0.0, 180.0>
  translate  <-0.304326, 0.333789, -1.330316>
}
#declare Eagle_opendivider2 = prism {
  linear_sweep
  linear_spline
  -0.8,0.0
  5  // control points
  <-1.0, -1.0>,
  <0.319381, -0.51676>,
  <0.312574, 0.509954>,
  <-1.0, 1.0>,
  <-1.0, -1.0>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.407554, 0.717692, 0.717692>
  rotate 90.0*x
  translate  <3.398979, 0.916371, -1.314822>
}
#declare Eagle_door2 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  21  // control points
  <0.158783, 0.188617>,
  <0.188293, 0.162395>,
  <0.2238, 0.154184>,
  <1.778963, 0.155633>,
  <1.817707, 0.163841>,
  <1.843181, 0.184063>,
  <1.857197, 0.218236>,
  <1.85875, 0.263673>,
  <1.618665, 2.141155>,
  <1.608533, 2.176447>,
  <1.589081, 2.211099>,
  <1.55128, 2.234177>,
  <1.496441, 2.245733>,
  <0.516378, 2.245733>,
  <0.459125, 2.242489>,
  <0.421337, 2.227079>,
  <0.398814, 2.196116>,
  <0.382061, 2.141155>,
  <0.142698, 0.271161>,
  <0.144417, 0.227676>,
  <0.158783, 0.188617>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -180.0>
  translate  <2.461975, 2.398696, -2.513085>
}
#declare Eagle_door3 = prism {
  linear_sweep
  linear_spline
  -0.4,0.0
  21  // control points
  <0.288593, 0.346306>,
  <0.314263, 0.328012>,
  <0.343114, 0.322975>,
  <1.662205, 0.322975>,
  <1.694694, 0.328239>,
  <1.714841, 0.34884>,
  <1.721331, 0.375067>,
  <1.721013, 0.406286>,
  <1.519279, 1.989198>,
  <1.510783, 2.018792>,
  <1.494471, 2.047851>,
  <1.462772, 2.067203>,
  <1.416786, 2.076893>,
  <0.59493, 2.076893>,
  <0.546919, 2.074173>,
  <0.515231, 2.061251>,
  <0.496344, 2.035286>,
  <0.482295, 1.989198>,
  <0.280647, 0.406286>,
  <0.279318, 0.37444>,
  <0.288593, 0.346306>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -180.0>
  translate  <2.461975, 2.502221, -2.513085>
}
#declare Eagle_hatch1 = difference {
  object { Eagle_door2 }
  object { Eagle_door3 }
  photons {
    collect off
  }
  scale <0.852697, 0.865487, 0.865487>
  translate  <0.276999, 0.304756, -0.212613>
}
#declare Eagle_lowereng5 = lathe {
  linear_spline
  36  // control points
  <0.003073, 0.017965>,
  <0.517213, 0.017851>,
  <0.518031, -0.331139>,
  <0.590407, -0.444993>,
  <0.650531, -0.570158>,
  <0.67586, -0.661969>,
  <0.69812, -0.756676>,
  <0.719872, -0.841485>,
  <0.7304, -0.92525>,
  <0.737446, -0.999889>,
  <0.801968, -0.999873>,
  <0.797771, -0.959823>,
  <0.79084, -0.959683>,
  <0.787628, -0.941667>,
  <0.796332, -0.941813>,
  <0.793224, -0.916435>,
  <0.786887, -0.833102>,
  <0.771857, -0.751154>,
  <0.751222, -0.655998>,
  <0.726663, -0.570029>,
  <0.706397, -0.518438>,
  <0.694234, -0.518089>,
  <0.68079, -0.493238>,
  <0.697764, -0.492913>,
  <0.678245, -0.446794>,
  <0.663732, -0.446894>,
  <0.649692, -0.419555>,
  <0.665647, -0.419772>,
  <0.640518, -0.3674>,
  <0.628901, -0.36719>,
  <0.615563, -0.343821>,
  <0.627614, -0.343795>,
  <0.600074, -0.299944>,
  <0.661918, -0.299502>,
  <0.66203, 0.107819>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.970662, 1.0, 1.0>
  rotate <-0.0, 0.0, 180.0>
  translate  <0.710386, -1.099702, -2.694243>
}
#declare Eagle_lowereng10 = lathe {
  linear_spline
  36  // control points
  <0.003073, 0.017965>,
  <0.517213, 0.017851>,
  <0.518031, -0.331139>,
  <0.590407, -0.444993>,
  <0.650531, -0.570158>,
  <0.67586, -0.661969>,
  <0.69812, -0.756676>,
  <0.719872, -0.841485>,
  <0.7304, -0.92525>,
  <0.737446, -0.999889>,
  <0.801968, -0.999873>,
  <0.797771, -0.959823>,
  <0.79084, -0.959683>,
  <0.787628, -0.941667>,
  <0.796332, -0.941813>,
  <0.793224, -0.916435>,
  <0.786887, -0.833102>,
  <0.771857, -0.751154>,
  <0.751222, -0.655998>,
  <0.726663, -0.570029>,
  <0.706397, -0.518438>,
  <0.694234, -0.518089>,
  <0.68079, -0.493238>,
  <0.697764, -0.492913>,
  <0.678245, -0.446794>,
  <0.663732, -0.446894>,
  <0.649692, -0.419555>,
  <0.665647, -0.419772>,
  <0.640518, -0.3674>,
  <0.628901, -0.36719>,
  <0.615563, -0.343821>,
  <0.627614, -0.343795>,
  <0.600074, -0.299944>,
  <0.661918, -0.299502>,
  <0.66203, 0.107819>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.970662, 1.0, 1.0>
  rotate <-0.0, 0.0, 180.0>
  translate  <2.377316, -1.099819, -2.694243>
}
#declare Eagle_rearframe = union {
  object { Eagle_framunion4 }
  object { Eagle_framunion5 }
  object { Eagle_rearframeassembly }
  sphere { // FORTANK4
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <3.652066, -1.379008, -1.181465>
  }
  sphere { // FORTANK5
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <-0.539928, -1.379008, -1.204902>
  }
  object { Eagle_opendivider }
  object { Eagle_opendivider2 }
  sphere { // FORTANK6
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <3.649769, 1.936157, -1.22834>
  }
  sphere { // FORTANK7
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <-0.545352, 1.936157, -1.22834>
  }
  box { // forpassa1
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <1.477833, 2.65, 1.2>
    translate  <1.527549, -0.096804, -1.308182>
  }
  box { // forpass2
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.591133, 2.6, 0.05>
    translate  <3.605654, -0.12589, -1.320372>
  }
  box { // forpass3
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.591133, 2.6, 0.05>
    translate  <-0.508978, -0.126026, -1.316162>
  }
  object { Eagle_hatch1 }
  object { Eagle_lowereng5 }
  object { Eagle_lowereng10 }
  photons {
    collect off
  }
  scale <1.015, 1.0, 1.0>
  rotate 180.0*z
  translate  <2.400187, -1.529121, -1.100181>
}
#declare Eagle_framunion3 = union {
  cylinder { // frame25
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
    translate  <-1.1, 0.0, -0.65>
  }
  cylinder { // frame26
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
  }
  cylinder { // frame27
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, -21.002718>
    translate  <-0.076638, -0.146488, -0.045244>
  }
  cylinder { // frame28
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000896, -0.100081, -0.000549>
  }
  cylinder { // frame29
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, 20.906914>
    translate  <-1.02302, -0.144362, -0.603947>
  }
  cylinder { // frame30
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000024, -2.6004, -0.000035>
  }
  cylinder { // fram10
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -2.617556, -0.651328>
  }
  cylinder { // fram11
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -0.117556, -0.651328>
  }
  cylinder { // fram12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, -0.0, 0.0>
    translate  <-1.099652, -0.116634, -1.281832>
  }
  cylinder { // fram13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -1.367556, -0.651328>
  }
  cylinder { // frame31
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <-1.1, -2.717556, -1.951832>
  }
  cylinder { // frame32
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <0.0, -2.717556, -2.601832>
  }
  cylinder { // frame33
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, 21.002718>
    translate  <-0.076638, -2.571068, -2.556588>
  }
  cylinder { // frame34
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000896, -2.617475, -2.601282>
  }
  cylinder { // frame35
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, -20.906914>
    translate  <-1.02302, -2.573194, -1.997885>
  }
  cylinder { // frame36
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000024, -0.117157, -2.601797>
  }
  cylinder { // topcross5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -2.601832>
  }
  cylinder { // topcross6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -2.601832>
  }
  cylinder { // topcross7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -0.001832>
  }
  cylinder { // topcross8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -0.001832>
  }
  cylinder { // topcross9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -1.367558, -0.001832>
  }
  cylinder { // frame37
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <4.2, -2.717556, -0.65>
  }
  cylinder { // frame38
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <3.1, -2.717556, -0.0>
  }
  cylinder { // frame39
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, 158.997284>
    translate  <3.176638, -2.571068, -0.045244>
  }
  cylinder { // frame40
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100896, -2.617475, -0.00055>
  }
  cylinder { // frame41
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, -159.093079>
    translate  <4.12302, -2.573194, -0.603947>
  }
  cylinder { // frame42
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100024, -0.117157, -0.000035>
  }
  cylinder { // fram14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -0.1, -0.651329>
  }
  cylinder { // fram15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -2.6, -0.651329>
  }
  cylinder { // fram16
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, 0.0, -180.0>
    translate  <4.199652, -2.600923, -1.281832>
  }
  cylinder { // fram17
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -1.35, -0.651329>
  }
  cylinder { // frame43
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <4.2, 0.0, -1.951832>
  }
  cylinder { // frame44
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <3.1, 0.0, -2.601832>
  }
  cylinder { // frame45
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, -158.997284>
    translate  <3.176638, -0.146488, -2.556588>
  }
  cylinder { // frame46
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100896, -0.100081, -2.601283>
  }
  cylinder { // frame47
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, 159.093094>
    translate  <4.12302, -0.144362, -1.997885>
  }
  cylinder { // frame48
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100024, -2.6004, -2.601797>
  }
  photons {
    collect off
  }
  rotate <180.0, -0.0, -180.0>
  translate  <3.1, 2.7, -2.601832>
}
#declare Eagle_framunion2 = union {
  cylinder { // frame13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
    translate  <-1.1, 0.0, -0.65>
  }
  cylinder { // frame14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate 90.0*x
  }
  cylinder { // frame15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, -21.002718>
    translate  <-0.076638, -0.146488, -0.045244>
  }
  cylinder { // frame16
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000896, -0.100081, -0.000549>
  }
  cylinder { // frame17
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, 20.906914>
    translate  <-1.02302, -0.144362, -0.603947>
  }
  cylinder { // frame18
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, -73.290031>
    translate  <-0.000024, -2.6004, -0.000035>
  }
  cylinder { // fram6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -2.617556, -0.651328>
  }
  cylinder { // fram7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -0.117556, -0.651328>
  }
  cylinder { // fram8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, -0.0, 0.0>
    translate  <-1.099652, -0.116634, -1.281832>
  }
  cylinder { // fram9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate -180.0*x
    translate  <-1.099652, -1.367556, -0.651328>
  }
  cylinder { // frame19
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <-1.1, -2.717556, -1.951832>
  }
  cylinder { // frame20
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate -90.0*x
    translate  <0.0, -2.717556, -2.601832>
  }
  cylinder { // frame21
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, 21.002718>
    translate  <-0.076638, -2.571068, -2.556588>
  }
  cylinder { // frame22
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000896, -2.617475, -2.601282>
  }
  cylinder { // frame23
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, -20.906914>
    translate  <-1.02302, -2.573194, -1.997885>
  }
  cylinder { // frame24
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000024, -0.117157, -2.601797>
  }
  cylinder { // topcross
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -2.601832>
  }
  cylinder { // topcross1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -2.601832>
  }
  cylinder { // topcross2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.618, -0.001832>
  }
  cylinder { // topcross3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -0.1, -0.001832>
  }
  cylinder { // topcross4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.1, -2.0, -0.001832>
  }
  cylinder { // frame7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <4.2, -2.717556, -0.65>
  }
  cylinder { // frame8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <90.0, 0.0, -180.0>
    translate  <3.1, -2.717556, -0.0>
  }
  cylinder { // frame9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <102.206604, 2.271023, 158.997284>
    translate  <3.176638, -2.571068, -0.045244>
  }
  cylinder { // frame10
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100896, -2.617475, -0.00055>
  }
  cylinder { // frame11
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <77.833, 2.256019, -159.093079>
    translate  <4.12302, -2.573194, -0.603947>
  }
  cylinder { // frame12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <124.404579, 25.938559, 106.709969>
    translate  <3.100024, -0.117157, -0.000035>
  }
  cylinder { // fram3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -0.1, -0.651329>
  }
  cylinder { // fram2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -2.6, -0.651329>
  }
  cylinder { // fram4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.5>
    rotate <90.0, 0.0, -180.0>
    translate  <4.199652, -2.600923, -1.281832>
  }
  cylinder { // fram5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.3>
    rotate <180.0, 0.0, -180.0>
    translate  <4.199652, -1.35, -0.651329>
  }
  cylinder { // frame2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <4.2, 0.0, -1.951832>
  }
  cylinder { // frame1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-90.0, 0.0, -180.0>
    translate  <3.1, 0.0, -2.601832>
  }
  cylinder { // frame3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-77.793396, -2.271023, -158.997284>
    translate  <3.176638, -0.146488, -2.556588>
  }
  cylinder { // frame5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100896, -0.100081, -2.601283>
  }
  cylinder { // frame4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.65>
    rotate <-102.167, -2.256019, 159.093094>
    translate  <4.12302, -0.144362, -1.997885>
  }
  cylinder { // frame6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.27>
    rotate <-55.595421, -25.938559, -106.709969>
    translate  <3.100024, -2.6004, -2.601797>
  }
  photons {
    collect off
  }
  rotate <180.0, -0.0, -180.0>
  translate  <3.1, 0.0, -2.601832>
}
#declare Eagle_frontframeassembly = union {
  cylinder { // fram19
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.302>
    rotate <-0.0, -0.0, -180.0>
    translate  <4.19856, -2.818, -1.957155>
  }
  cylinder { // frame51
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.278>
    rotate <124.447067, 25.927099, 106.728554>
    translate  <3.09754, -2.818, -0.00488>
  }
  cylinder { // topcross11
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <-90.0, -0.0, -90.0>
    translate  <-0.001422, -2.818, -0.005414>
  }
  cylinder { // frame52
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.278>
    rotate <124.44957, 25.926426, -73.27037>
    translate  <-0.000619, -2.818, -0.004895>
  }
  cylinder { // fram18
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.302>
    rotate <180.0, 0.0, 0.0>
    translate  <-1.101251, -2.818, -0.654858>
  }
  cylinder { // frame50
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.277>
    rotate <-55.595421, -25.938559, 73.290031>
    translate  <-0.000738, -2.818, -2.60583>
  }
  cylinder { // topcross10
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate <90.0, 0.0, -90.0>
    translate  <3.098552, -2.818, -2.607113>
  }
  cylinder { // frame49
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.278>
    rotate <-55.551392, -25.92668, -106.729248>
    translate  <3.097723, -2.818, -2.60762>
  }
  cylinder { // frame54
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, 0.0, 0.0>
    translate  <-0.001446, -2.93, -2.607145>
  }
  cylinder { // frame55
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, 0.0, 0.0>
    translate  <-1.101446, -2.93, -1.957145>
  }
  cylinder { // frame56
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, 0.0, 0.0>
    translate  <-1.101446, -2.71, -0.655313>
  }
  cylinder { // frame57
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, 0.0, 0.0>
    translate  <-0.001446, -2.71, -0.005313>
  }
  cylinder { // frame58
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, -0.0, 180.0>
    translate  <3.098554, -2.93, -0.005314>
  }
  cylinder { // frame59
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <90.0, -0.0, 180.0>
    translate  <4.198554, -2.93, -0.655314>
  }
  cylinder { // frame60
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, -0.0, 180.0>
    translate  <4.198554, -2.71, -1.957145>
  }
  cylinder { // frame53
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.2>
    rotate <90.0, -0.0, 180.0>
    translate  <3.098554, -2.918, -0.005314>
  }
  cylinder { // frame61
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.22>
    rotate <-90.0, -0.0, 180.0>
    translate  <3.098554, -2.71, -2.607145>
  }
  cylinder { // frame62
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, -2.83, -0.005314>
  }
  cylinder { // frame63
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, -2.83, -2.607145>
  }
  cylinder { // frame66
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, -2.83, -1.287249>
  }
  cylinder { // frame67
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, -2.83, -1.28713>
  }
  cylinder { // frame64
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, -0.1, -2.607145>
  }
  cylinder { // frame65
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, 0.1, -2.607145>
  }
  cylinder { // frame68
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <0.0, 0.0, 0.0>
    translate  <-0.001446, 2.61, -2.607145>
  }
  cylinder { // frame69
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, -0.1, -0.005314>
  }
  cylinder { // frame70
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, 0.1, -0.005314>
  }
  cylinder { // frame71
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-180.0, -0.0, 180.0>
    translate  <3.098554, 2.61, -0.005314>
  }
  cylinder { // frame72
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, 2.6, -1.28713>
  }
  cylinder { // frame73
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, -0.1, -1.28713>
  }
  cylinder { // frame74
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <-1.101177, 0.1, -1.28713>
  }
  cylinder { // frame75
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, -0.1, -1.287249>
  }
  cylinder { // frame76
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, 0.1, -1.287249>
  }
  cylinder { // frame77
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.1>
    rotate <0.0, 90.0, 0.0>
    translate  <3.0987, 2.6, -1.287249>
  }
  photons {
    collect off
  }
  rotate <180.0, 0.0, -180.0>
  translate  <3.098554, -0.01, -2.607145>
}
#declare Eagle_opendivider3 = prism {
  linear_sweep
  linear_spline
  -0.8,0.0
  5  // control points
  <-1.0, -1.0>,
  <0.319381, -0.51676>,
  <0.312574, 0.509954>,
  <-1.0, 1.0>,
  <-1.0, -1.0>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.407554, 0.717692, 0.717692>
  rotate <90.0, 0.0, 180.0>
  translate  <-0.304326, 0.333789, -1.330316>
}
#declare Eagle_opendivider4 = prism {
  linear_sweep
  linear_spline
  -0.8,0.0
  5  // control points
  <-1.0, -1.0>,
  <0.319381, -0.51676>,
  <0.312574, 0.509954>,
  <-1.0, 1.0>,
  <-1.0, -1.0>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.407554, 0.717692, 0.717692>
  rotate 90.0*x
  translate  <3.398979, 0.916371, -1.314822>
}
#declare Eagle_door101 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  21  // control points
  <0.158783, 0.188617>,
  <0.188293, 0.162395>,
  <0.2238, 0.154184>,
  <1.778963, 0.155633>,
  <1.817707, 0.163841>,
  <1.843181, 0.184063>,
  <1.857197, 0.218236>,
  <1.85875, 0.263673>,
  <1.618665, 2.141155>,
  <1.608533, 2.176447>,
  <1.589081, 2.211099>,
  <1.55128, 2.234177>,
  <1.496441, 2.245733>,
  <0.516378, 2.245733>,
  <0.459125, 2.242489>,
  <0.421337, 2.227079>,
  <0.398814, 2.196116>,
  <0.382061, 2.141155>,
  <0.142698, 0.271161>,
  <0.144417, 0.227676>,
  <0.158783, 0.188617>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -180.0>
  translate  <2.461975, 2.398696, -2.513085>
}
#declare Eagle_door112 = prism {
  linear_sweep
  linear_spline
  -0.4,0.0
  21  // control points
  <0.288593, 0.346306>,
  <0.314263, 0.328012>,
  <0.343114, 0.322975>,
  <1.662205, 0.322975>,
  <1.694694, 0.328239>,
  <1.714841, 0.34884>,
  <1.721331, 0.375067>,
  <1.721013, 0.406286>,
  <1.519279, 1.989198>,
  <1.510783, 2.018792>,
  <1.494471, 2.047851>,
  <1.462772, 2.067203>,
  <1.416786, 2.076893>,
  <0.59493, 2.076893>,
  <0.546919, 2.074173>,
  <0.515231, 2.061251>,
  <0.496344, 2.035286>,
  <0.482295, 1.989198>,
  <0.280647, 0.406286>,
  <0.279318, 0.37444>,
  <0.288593, 0.346306>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -180.0>
  translate  <2.461975, 2.502221, -2.513085>
}
#declare Eagle_hatch = difference {
  object { Eagle_door101 }
  object { Eagle_door112 }
  photons {
    collect off
  }
  scale <0.852697, 0.865487, 0.865487>
  translate  <0.276999, 0.304756, -0.212613>
}
#declare Eagle_lowereng1 = lathe {
  linear_spline
  36  // control points
  <0.003073, 0.017965>,
  <0.517213, 0.017851>,
  <0.518031, -0.331139>,
  <0.590407, -0.444993>,
  <0.650531, -0.570158>,
  <0.67586, -0.661969>,
  <0.69812, -0.756676>,
  <0.719872, -0.841485>,
  <0.7304, -0.92525>,
  <0.737446, -0.999889>,
  <0.801968, -0.999873>,
  <0.797771, -0.959823>,
  <0.79084, -0.959683>,
  <0.787628, -0.941667>,
  <0.796332, -0.941813>,
  <0.793224, -0.916435>,
  <0.786887, -0.833102>,
  <0.771857, -0.751154>,
  <0.751222, -0.655998>,
  <0.726663, -0.570029>,
  <0.706397, -0.518438>,
  <0.694234, -0.518089>,
  <0.68079, -0.493238>,
  <0.697764, -0.492913>,
  <0.678245, -0.446794>,
  <0.663732, -0.446894>,
  <0.649692, -0.419555>,
  <0.665647, -0.419772>,
  <0.640518, -0.3674>,
  <0.628901, -0.36719>,
  <0.615563, -0.343821>,
  <0.627614, -0.343795>,
  <0.600074, -0.299944>,
  <0.661918, -0.299502>,
  <0.66203, 0.107819>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <2.3871, -1.1, -2.694473>
}
#declare Eagle_CSG50 = difference {
  box { // Cube170
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.4, 0.075, 0.2>
    translate  <0.324471, 0.0, 0.225>
  }
  box { // Cube171
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.23, 0.07867, 0.144123>
    translate  <0.1, 0.0, 0.225>
  }
  photons {
    collect off
  }
  rotate <-0.0, -0.0, -21.8305>
}
#declare Eagle_TraSwp118 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.661843>,
  <-0.048154, 0.661843>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.661843>
  rotate -x*90
  photons {
    collect off
  }
  rotate -90.0*z
  translate  <-0.972866, -0.147972, 0.201811>
}
#declare Eagle_latchleft = union {
  object { Eagle_CSG50 }
  object { Eagle_TraSwp118 }
  cylinder { // Cylndr138
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.075, 0.075, 0.45>
  }
  photons {
    collect off
  }
  scale <1.0, 0.985222, 1.0>
  rotate <0.0, -0.0, -90.0>
  translate  <4.201131, -3.022455, -1.54492>
}
#declare Eagle_CSG51 = difference {
  box { // Cube172
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.4, 0.075, 0.2>
    translate  <0.324471, 0.0, 0.225>
  }
  box { // Cube173
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.23, 0.07867, 0.144123>
    translate  <0.1, 0.0, 0.225>
  }
  photons {
    collect off
  }
  rotate <0.0, -0.0, 16.478556>
}
#declare Eagle_TraSwp119 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.661843>,
  <-0.048154, 0.661843>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.661843>
  rotate -x*90
  photons {
    collect off
  }
  rotate -90.0*z
  translate  <-0.972866, -0.147972, 0.201811>
}
#declare Eagle_latchright = union {
  object { Eagle_CSG51 }
  object { Eagle_TraSwp119 }
  cylinder { // Cylndr139
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.075, 0.075, 0.45>
  }
  photons {
    collect off
  }
  scale <1.0, 0.985222, 1.0>
  rotate <0.0, -0.0, -90.0>
  translate  <-1.10174, -3.018788, -1.54492>
}
#declare Eagle_bottombolt3 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.549578>,
  <-0.048154, 0.549578>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.549578>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.739143, 0.733264, 0.750901>
  rotate <-0.0, 0.0, -270.0>
  translate  <0.338103, -0.116353, 0.417463>
}
#declare Eagle_bottomlatchbolt1 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.561395>,
  <-0.048154, 0.561395>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.561395>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.75023, 0.739143, 0.739143>
  rotate <0.0, 0.0, 90.0>
  translate  <0.339181, -0.113494, 0.028305>
}
#declare Eagle_bottomlatchinnerbolt6 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.549578>,
  <-0.048154, 0.549578>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.549578>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.553082, 0.417673, 2.220731>
  rotate <180.0, 0.0, 90.0>
  translate  <-0.682265, -0.137507, 0.18718>
}
#declare Eagle_bottomlatchinnerbolt5 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.549578>,
  <-0.048154, 0.549578>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.549578>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.553082, 0.417673, 2.220731>
  rotate <180.0, 0.0, 90.0>
  translate  <-0.68354, -0.137507, 0.365562>
}
#declare Eagle_latchbottom = union {
  object { Eagle_bottombolt3 }
  cylinder { // bottomlatchcyl1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.045343, 0.045343, 0.46844>
    translate  <-0.305535, -0.220421, 0.0>
  }
  object { Eagle_bottomlatchbolt1 }
  object { Eagle_bottomlatchinnerbolt6 }
  object { Eagle_bottomlatchinnerbolt5 }
  photons {
    collect off
  }
  scale <1.0, 0.985222, 0.985222>
  rotate <90.0, 0.0, -90.0>
  translate  <1.761817, -3.269189, -2.397199>
}
#declare Eagle_toplatchbolt2 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.549578>,
  <-0.048154, 0.549578>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.549578>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.739143, 0.733264, 0.750901>
  rotate <-0.0, 0.0, -270.0>
  translate  <0.338103, -0.116353, 0.417463>
}
#declare Eagle_toplatchbolt = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.561395>,
  <-0.048154, 0.561395>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.561395>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.75023, 0.739143, 0.739143>
  rotate <0.0, 0.0, 90.0>
  translate  <0.339181, -0.113494, 0.028305>
}
#declare Eagle_toplatchinnerbolt4 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.549578>,
  <-0.048154, 0.549578>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.549578>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.544909, 0.417673, 2.220731>
  rotate <0.0, -0.0, -90.0>
  translate  <-0.687284, -0.298823, 0.097421>
}
#declare Eagle_toplatchinnerbolt3 = prism {
  linear_sweep
  linear_spline
  -0.04,0.0
  8  // control points
  <-0.244513, 0.549578>,
  <-0.048154, 0.549578>,
  <-0.048154, 1.000617>,
  <-0.074405, 1.050445>,
  <-0.147627, 1.076631>,
  <-0.217097, 1.048874>,
  <-0.244513, 1.0>,
  <-0.244513, 0.549578>
  rotate -x*90
  photons {
    collect off
  }
  scale <0.544909, 0.417673, 2.220731>
  rotate <0.0, -0.0, -90.0>
  translate  <-0.687996, -0.298823, 0.277477>
}
#declare Eagle_latchtop = union {
  object { Eagle_toplatchbolt2 }
  cylinder { // Eagle_toplatchcyl
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.045343, 0.045343, 0.46844>
    translate  <-0.305535, -0.220421, 0.0>
  }
  object { Eagle_toplatchbolt }
  object { Eagle_toplatchinnerbolt4 }
  object { Eagle_toplatchinnerbolt3 }
  photons {
    collect off
  }
  scale <1.0, 0.985222, 0.985222>
  rotate <90.0, 0.0, -90.0>
  translate  <1.761817, -3.273533, 0.229708>
}
#declare Eagle_framconnect = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.200438>,
  <0.100787, -0.200438>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.200438>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector = union {
  cylinder { // framconnbolt
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.185681, -5.380951, 15.335633>
}
#declare Eagle_framconnect1 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector1 = union {
  cylinder { // framconnbolt1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect1 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.970662>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186819, -4.179876, 15.334903>
}
#declare Eagle_framconnect2 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector2 = union {
  cylinder { // framconnbolt2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect2 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186055, -2.675675, 15.334734>
}
#declare Eagle_framconnect3 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector3 = union {
  cylinder { // framconnbolt3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect3 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.187318, -1.471949, 15.335153>
}
#declare Eagle_frmconnectunion = union {
  object { Eagle_frameconnector }
  object { Eagle_frameconnector1 }
  object { Eagle_frameconnector2 }
  object { Eagle_frameconnector3 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <0.0935, -0.021411, 0.01227>
}
#declare Eagle_framconnect4 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector4 = union {
  cylinder { // framconnbolt4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect4 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.185681, -5.380951, 15.335633>
}
#declare Eagle_framconnect5 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector5 = union {
  cylinder { // framconnbolt5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect5 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.970662>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186819, -3.960355, 15.335824>
}
#declare Eagle_framconnect6 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector6 = union {
  cylinder { // framconnbolt6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect6 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186055, -2.675675, 15.334734>
}
#declare Eagle_framconnect7 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.200438>,
  <0.100787, -0.200438>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.200438>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector7 = union {
  cylinder { // framconnbolt7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect7 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.187318, -1.471949, 15.335153>
}
#declare Eagle_frmconnectunion1 = union {
  object { Eagle_frameconnector4 }
  object { Eagle_frameconnector5 }
  object { Eagle_frameconnector6 }
  object { Eagle_frameconnector7 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <0.092546, 18.083807, 0.012351>
}
#declare Eagle_framconnect8 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.206411>,
  <0.100787, -0.206411>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.206411>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector8 = union {
  cylinder { // framconnbolt8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect8 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.185681, -5.380951, 15.335633>
}
#declare Eagle_framconnect9 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector9 = union {
  cylinder { // framconnbolt9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect9 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.970662>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186819, -4.179876, 15.334903>
}
#declare Eagle_framconnect10 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector10 = union {
  cylinder { // framconnbolt10
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect10 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186055, -2.675675, 15.334734>
}
#declare Eagle_framconnect11 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.20442>,
  <0.100787, -0.20442>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.20442>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector11 = union {
  cylinder { // framconnbolt11
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect11 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.187318, -1.471949, 15.335153>
}
#declare Eagle_frmconnectunion2 = union {
  object { Eagle_frameconnector8 }
  object { Eagle_frameconnector9 }
  object { Eagle_frameconnector10 }
  object { Eagle_frameconnector11 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  rotate -180.0*z
  translate  <2.998161, -0.045534, 0.010662>
}
#declare Eagle_framconnect12 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.20442>,
  <0.100787, -0.20442>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.20442>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector12 = union {
  cylinder { // framconnbolt12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect12 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.185681, -5.380951, 15.335633>
}
#declare Eagle_framconnect13 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.20442>,
  <0.100787, -0.20442>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.20442>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector13 = union {
  cylinder { // framconnbolt13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect13 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.970662>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186819, -4.179876, 15.334903>
}
#declare Eagle_framconnect14 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.20442>,
  <0.100787, -0.20442>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.20442>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector14 = union {
  cylinder { // framconnbolt14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect14 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.186055, -2.891333, 15.336017>
}
#declare Eagle_framconnect15 = prism {
  linear_sweep
  linear_spline
  -0.03,0.0
  12  // control points
  <-0.100787, -0.202429>,
  <0.100787, -0.202429>,
  <0.100787, 0.128226>,
  <0.094815, 0.183246>,
  <0.078888, 0.218356>,
  <0.044421, 0.245233>,
  <0.0, 0.25021>,
  <-0.038448, 0.245233>,
  <-0.074906, 0.216365>,
  <-0.094815, 0.179264>,
  <-0.100787, 0.130217>,
  <-0.100787, -0.202429>
  rotate -x*90
  photons {
    collect off
  }
  translate  <-3.468748, -15.262489, 0.0>
}
#declare Eagle_frameconnector15 = union {
  cylinder { // framconnbolt15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale 0.060771
    translate  <-3.466399, -15.097013, 0.015043>
  }
  object { Eagle_framconnect15 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 0.956317>
  rotate <90.0, 0.0, -90.0>
  translate  <-0.187318, -1.471949, 15.335153>
}
#declare Eagle_frmconnectunion3 = union {
  object { Eagle_frameconnector12 }
  object { Eagle_frameconnector13 }
  object { Eagle_frameconnector14 }
  object { Eagle_frameconnector15 }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  rotate -180.0*z
  translate  <2.998173, 18.063757, 0.010418>
}
#declare Eagle_lowereng4 = lathe {
  linear_spline
  36  // control points
  <0.003073, 0.017965>,
  <0.517213, 0.017851>,
  <0.518031, -0.331139>,
  <0.590407, -0.444993>,
  <0.650531, -0.570158>,
  <0.67586, -0.661969>,
  <0.69812, -0.756676>,
  <0.719872, -0.841485>,
  <0.7304, -0.92525>,
  <0.737446, -0.999889>,
  <0.801968, -0.999873>,
  <0.797771, -0.959823>,
  <0.79084, -0.959683>,
  <0.787628, -0.941667>,
  <0.796332, -0.941813>,
  <0.793224, -0.916435>,
  <0.786887, -0.833102>,
  <0.771857, -0.751154>,
  <0.751222, -0.655998>,
  <0.726663, -0.570029>,
  <0.706397, -0.518438>,
  <0.694234, -0.518089>,
  <0.68079, -0.493238>,
  <0.697764, -0.492913>,
  <0.678245, -0.446794>,
  <0.663732, -0.446894>,
  <0.649692, -0.419555>,
  <0.665647, -0.419772>,
  <0.640518, -0.3674>,
  <0.628901, -0.36719>,
  <0.615563, -0.343821>,
  <0.627614, -0.343795>,
  <0.600074, -0.299944>,
  <0.661918, -0.299502>,
  <0.66203, 0.107819>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <0.700104, -1.102128, -2.694473>
}
#declare Eagle_frontframe = union {
  object { Eagle_framunion3 }
  object { Eagle_framunion2 }
  object { Eagle_frontframeassembly }
  sphere { // FORTANK3
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <3.652066, -1.379008, -1.181465>
  }
  sphere { // FORTANK2
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <-0.539928, -1.379008, -1.204902>
  }
  object { Eagle_opendivider3 }
  object { Eagle_opendivider4 }
  sphere { // FORTANK1
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <3.649769, 1.936157, -1.22834>
  }
  sphere { // FORTANK
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.44335, 0.45, 0.45>
    translate  <-0.545352, 1.936157, -1.22834>
  }
  box { // forpassa
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <1.477833, 2.65, 1.2>
    translate  <1.527549, -0.096804, -1.308182>
  }
  box { // forpass1
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.591133, 2.6, 0.05>
    translate  <3.605654, -0.12589, -1.320372>
  }
  box { // forpass
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.591133, 2.6, 0.05>
    translate  <-0.508978, -0.126026, -1.316162>
  }
  object { Eagle_hatch }
  object { Eagle_lowereng1 }
  object { Eagle_latchleft }
  object { Eagle_latchright }
  object { Eagle_latchbottom }
  object { Eagle_latchtop }
  object { Eagle_frmconnectunion }
  object { Eagle_frmconnectunion1 }
  object { Eagle_frmconnectunion2 }
  object { Eagle_frmconnectunion3 }
  object { Eagle_lowereng4 }
  photons {
    collect off
  }
  scale <1.015, 1.0, 1.0>
  translate  <-0.746267, -19.600496, -1.100381>
}
#declare Eagle_balltank1 = union {
  torus { // Torus0014
    1.5, 0.5  rotate -x*90
    material {
      Eagle_black
    }
    photons {
      collect off
    }
    scale <0.31, 0.31, 0.06>
    rotate 90.0*x
  }
  sphere { // Spheretanks002
    <0,0,0>,1
    material {
      Eagle_btank2sphere
    }
    photons {
      collect off
    }
    scale 0.575
    rotate 90.0*x
  }
  photons {
    collect off
  }
  translate  <1.624856, -4.500811, -0.000084>
}
#declare Eagle_engnozzopen = union {
  cylinder { // Cylndrnozz22
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, -0.790723, 0.92>
  }
  cylinder { // Cylndrnozz23
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, 0.790723, 0.92>
  }
  cylinder { // Cylndrnozz24
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <0.790723, -0.003882, 0.92>
  }
  cylinder { // Cylndrnozz25
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.803619, 0.0, 0.92>
  }
  cylinder { // Cylndrnozz56
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, 0.0, 0.92>
  }
  photons {
    collect off
  }
}
#declare Eagle_engnozz1 = difference {
  cylinder { // Cylndrtanks21
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <1.0, 1.0, 0.05>
    translate  <0.000187, 0.0, 0.939525>
  }
  object { Eagle_engnozzopen }
  material {
    Eagle_black
  }
  photons {
    collect off
  }
  scale 0.98936
}
#declare Eagle_engbell6 = lathe {
  linear_spline
  52  // control points
  <0.000125, 2.062311>,
  <0.482425, 2.061436>,
  <0.6973, 1.633846>,
  <0.835741, 1.233784>,
  <0.929696, 0.817087>,
  <0.965244, 0.580299>,
  <1.016273, 0.386721>,
  <1.04812, 0.228343>,
  <1.097469, 0.001631>,
  <1.152233, 0.001254>,
  <1.146882, 0.18914>,
  <1.125418, 0.188566>,
  <1.119171, 0.27474>,
  <1.110102, 0.377133>,
  <1.100781, 0.494177>,
  <1.08778, 0.605006>,
  <1.073423, 0.720047>,
  <1.05, 0.85>,
  <1.03075, 0.936625>,
  <0.988293, 0.936568>,
  <0.970021, 1.008755>,
  <1.006338, 1.008967>,
  <0.990818, 1.073344>,
  <0.952214, 1.073317>,
  <0.935066, 1.134037>,
  <0.979094, 1.133552>,
  <0.962867, 1.197279>,
  <0.920744, 1.198422>,
  <0.905829, 1.256186>,
  <0.9483, 1.256106>,
  <0.931115, 1.312062>,
  <0.888256, 1.313237>,
  <0.872087, 1.375223>,
  <0.916946, 1.375644>,
  <0.900089, 1.428088>,
  <0.857557, 1.428442>,
  <0.839734, 1.492888>,
  <0.891108, 1.493666>,
  <0.852516, 1.612017>,
  <0.807203, 1.730368>,
  <0.765987, 1.837959>,
  <0.751525, 1.868085>,
  <0.788207, 1.868082>,
  <0.764613, 1.927175>,
  <0.722884, 1.927169>,
  <0.714336, 1.945551>,
  <0.664971, 2.03964>,
  <0.6, 2.15>,
  <0.6, 2.399999>,
  <0.425, 2.4>,
  <0.425, 3.3>,
  <0.0, 3.3>
  rotate <90,0,90>
  material {
    Eagle_bells
    scale <1.128963, 1.128963, 3.261928>
    translate <-0.009620, -0.000000, -0.005412>
  }
  photons {
    collect off
  }
}
#declare Eagle_balltank2 = union {
  object { Eagle_engnozz1 }
  cylinder { // Cylndr26yu
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.3>
    translate  5.8*z
  }
  sphere { // Spheretank7
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000204, 0.0, 5.064947>
  }
  cylinder { // Cylndrtank27
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_balltanktext
      rotate <0.0, -0.0, -90.0>
    }
    photons {
      collect off
    }
    scale <0.85, 0.85, 1.13>
    translate  3.934636*z
  }
  sphere { // Spheretank8
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000209, 0.0, 3.933122>
  }
  cylinder { // Cylndrtank28
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.55, 0.55, 0.2>
    translate  2.85*z
  }
  object { Eagle_engbell6 }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <-2.5, 0.0, -1.375>
}
#declare Eagle_nozzholes2 = union {
  cylinder { // Cylndrnozz14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, -0.777808, 0.92>
  }
  cylinder { // Cylndrnozz15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, 0.777808, 0.92>
  }
  cylinder { // Cylndrnozz16
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <0.790723, -0.003882, 0.92>
  }
  cylinder { // Cylndrnozz17
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.803619, 0.0, 0.92>
  }
  cylinder { // Cylndrnozz57
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, 0.0, 0.92>
  }
  photons {
    collect off
  }
}
#declare Eagle_engnozz2 = difference {
  cylinder { // Cylndreng13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <1.0, 1.0, 0.05>
    translate  <0.000187, 0.0, 0.939525>
  }
  object { Eagle_nozzholes2 }
  material {
    Eagle_black
  }
  photons {
    collect off
  }
  scale 0.98936
}
#declare Eagle_engbell7 = lathe {
  linear_spline
  52  // control points
  <0.000125, 2.062311>,
  <0.482425, 2.061436>,
  <0.6973, 1.633846>,
  <0.835741, 1.233784>,
  <0.929696, 0.817087>,
  <0.965244, 0.580299>,
  <1.006344, 0.380196>,
  <1.034859, 0.223448>,
  <1.090026, -0.00133>,
  <1.152233, 0.001254>,
  <1.146882, 0.18914>,
  <1.125418, 0.188566>,
  <1.119171, 0.27474>,
  <1.110102, 0.377133>,
  <1.100781, 0.494177>,
  <1.08778, 0.605006>,
  <1.073423, 0.720047>,
  <1.05, 0.85>,
  <1.03075, 0.936625>,
  <0.992174, 0.936568>,
  <0.973901, 1.008755>,
  <1.006338, 1.008967>,
  <0.990818, 1.073344>,
  <0.956095, 1.073317>,
  <0.938946, 1.134037>,
  <0.979094, 1.133552>,
  <0.962867, 1.197279>,
  <0.924625, 1.198422>,
  <0.909709, 1.256186>,
  <0.9483, 1.256106>,
  <0.931115, 1.312062>,
  <0.892137, 1.313237>,
  <0.875968, 1.375223>,
  <0.916946, 1.375644>,
  <0.900089, 1.428088>,
  <0.861437, 1.428442>,
  <0.843615, 1.492888>,
  <0.891108, 1.493666>,
  <0.852516, 1.612017>,
  <0.807203, 1.730368>,
  <0.765987, 1.837959>,
  <0.751525, 1.868085>,
  <0.788207, 1.868082>,
  <0.764613, 1.927175>,
  <0.722884, 1.927169>,
  <0.714336, 1.945551>,
  <0.664971, 2.03964>,
  <0.6, 2.15>,
  <0.6, 2.399999>,
  <0.425, 2.4>,
  <0.425, 3.3>,
  <0.0, 3.3>
  rotate <90,0,90>
  material {
    Eagle_bells
    scale <1.128963, 1.128963, 3.261928>
    translate <-0.009620, -0.000000, -0.005412>
  }
  photons {
    collect off
  }
}
#declare Eagle_balltank3 = union {
  object { Eagle_engnozz2 }
  cylinder { // engmount1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.3>
    translate  5.8*z
  }
  sphere { // Spheretank5
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000204, 0.0, 5.064947>
  }
  cylinder { // Cylndrtank19
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_balltanktext
      rotate -90.0*z
    }
    photons {
      collect off
    }
    scale <0.85, 0.85, 1.13>
    translate  3.934636*z
  }
  sphere { // Spheretankss6
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000209, 0.0, 3.933122>
  }
  cylinder { // Cylndrtank20
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.55, 0.55, 0.2>
    translate  2.85*z
  }
  object { Eagle_engbell7 }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <2.5, 0.0, -1.375>
}
#declare Eagle_engnozzholes4 = union {
  cylinder { // Cylndrnozz6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, -0.790723, 0.92>
  }
  cylinder { // Cylndrnozz7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <0.012764, 0.803639, 0.92>
  }
  cylinder { // Cylndrnozz8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <0.803639, -0.003882, 0.92>
  }
  cylinder { // Cylndrnozz9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.816534, 0.0, 0.92>
  }
  cylinder { // Cylndrnozz54
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, 0.0, 0.92>
  }
  photons {
    collect off
  }
}
#declare Eagle_engnozz3 = difference {
  cylinder { // Cylndrnozzle2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <1.0, 1.0, 0.05>
    translate  <0.000187, 0.0, 0.939525>
  }
  object { Eagle_engnozzholes4 }
  material {
    Eagle_black
  }
  photons {
    collect off
  }
  scale 0.98936
}
#declare Eagle_engbell5 = lathe {
  linear_spline
  52  // control points
  <0.000125, 2.062311>,
  <0.482425, 2.061436>,
  <0.6973, 1.633846>,
  <0.835741, 1.233784>,
  <0.929696, 0.817087>,
  <0.965244, 0.580299>,
  <1.013965, 0.383266>,
  <1.052431, 0.22959>,
  <1.095398, 0.001369>,
  <1.152233, 0.001254>,
  <1.146882, 0.18914>,
  <1.125418, 0.188566>,
  <1.119171, 0.27474>,
  <1.110102, 0.377133>,
  <1.100781, 0.494177>,
  <1.08778, 0.605006>,
  <1.073423, 0.720047>,
  <1.05, 0.85>,
  <1.03075, 0.936625>,
  <0.988293, 0.936568>,
  <0.970021, 1.008755>,
  <1.006338, 1.008967>,
  <0.990818, 1.073344>,
  <0.952214, 1.073317>,
  <0.935066, 1.134037>,
  <0.979094, 1.133552>,
  <0.962867, 1.197279>,
  <0.920744, 1.198422>,
  <0.905829, 1.256186>,
  <0.9483, 1.256106>,
  <0.931115, 1.312062>,
  <0.888256, 1.313237>,
  <0.872087, 1.375223>,
  <0.916946, 1.375644>,
  <0.900089, 1.428088>,
  <0.857557, 1.428442>,
  <0.839734, 1.492888>,
  <0.891108, 1.493666>,
  <0.852516, 1.612017>,
  <0.807203, 1.730368>,
  <0.765987, 1.837959>,
  <0.751525, 1.868085>,
  <0.788207, 1.868082>,
  <0.764613, 1.927175>,
  <0.722884, 1.927169>,
  <0.714336, 1.945551>,
  <0.664971, 2.03964>,
  <0.6, 2.15>,
  <0.6, 2.399999>,
  <0.425, 2.4>,
  <0.425, 3.3>,
  <0.0, 3.3>
  rotate <90,0,90>
  material {
    Eagle_bells
    scale <1.128963, 1.128963, 3.261928>
    translate <-0.009620, -0.000000, -0.005412>
  }
  photons {
    collect off
  }
}
#declare Eagle_balltank4 = union {
  object { Eagle_engnozz3 }
  cylinder { // engmount2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.3>
    translate  5.8*z
  }
  sphere { // Spheretank3
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000204, 0.0, 5.064947>
  }
  cylinder { // Cylndrtank11
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_balltanktext
      rotate -90.0*z
    }
    photons {
      collect off
    }
    scale <0.85, 0.85, 1.13>
    translate  3.934636*z
  }
  sphere { // Spheretank4
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000209, 0.0, 3.933122>
  }
  cylinder { // Cylndrtank12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.55, 0.55, 0.2>
    translate  2.85*z
  }
  object { Eagle_engbell5 }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  -2.75*z
}
#declare Eagle_engnozzle7 = union {
  cylinder { // Cylndrnozz5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, -0.777808, 0.92>
  }
  cylinder { // Cylndrnozz4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, 0.777808, 0.92>
  }
  cylinder { // Cylndrnozz3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <0.790723, -0.003882, 0.92>
  }
  cylinder { // Cylndr0nozz02
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.803619, 0.0, 0.92>
  }
  cylinder { // Cylndrnozz55
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.000152, 0.0, 0.92>
  }
  photons {
    collect off
  }
}
#declare Eagle_engnozz5 = difference {
  cylinder { // Cylndrbell001
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <1.0, 1.0, 0.05>
    translate  <0.000187, 0.0, 0.939525>
  }
  object { Eagle_engnozzle7 }
  material {
    Eagle_black
  }
  photons {
    collect off
  }
  scale 0.989362
}
#declare Eagle_engbell4 = lathe {
  linear_spline
  52  // control points
  <0.000125, 2.062311>,
  <0.482425, 2.061436>,
  <0.6973, 1.633846>,
  <0.835741, 1.233784>,
  <0.929696, 0.817087>,
  <0.965244, 0.580299>,
  <1.013349, 0.386989>,
  <1.045366, 0.232506>,
  <1.085631, 0.002264>,
  <1.152233, 0.001254>,
  <1.146882, 0.18914>,
  <1.125418, 0.188566>,
  <1.119171, 0.27474>,
  <1.110102, 0.377133>,
  <1.100781, 0.494177>,
  <1.08778, 0.605006>,
  <1.073423, 0.720047>,
  <1.05, 0.85>,
  <1.03075, 0.936625>,
  <0.988293, 0.936568>,
  <0.970021, 1.008755>,
  <1.006338, 1.008967>,
  <0.990818, 1.073344>,
  <0.952214, 1.073317>,
  <0.935066, 1.134037>,
  <0.979094, 1.133552>,
  <0.962867, 1.197279>,
  <0.920744, 1.198422>,
  <0.905829, 1.256186>,
  <0.9483, 1.256106>,
  <0.931115, 1.312062>,
  <0.888256, 1.313237>,
  <0.872087, 1.375223>,
  <0.916946, 1.375644>,
  <0.900089, 1.428088>,
  <0.857557, 1.428442>,
  <0.839734, 1.492888>,
  <0.891108, 1.493666>,
  <0.852516, 1.612017>,
  <0.807203, 1.730368>,
  <0.765987, 1.837959>,
  <0.751525, 1.868085>,
  <0.788207, 1.868082>,
  <0.764613, 1.927175>,
  <0.722884, 1.927169>,
  <0.714336, 1.945551>,
  <0.664971, 2.03964>,
  <0.6, 2.15>,
  <0.6, 2.399999>,
  <0.425, 2.4>,
  <0.425, 3.3>,
  <0.0, 3.3>
  rotate <90,0,90>
  material {
    Eagle_bells
    scale <1.128963, 1.128963, 3.261928>
    translate <-0.009620, -0.000000, -0.005412>
  }
  photons {
    collect off
  }
}
#declare Eagle_balltank5 = union {
  object { Eagle_engnozz5 }
  cylinder { // engmount6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.25>
    translate  5.8*z
  }
  sphere { // Spheretank2
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000204, 0.0, 5.064947>
  }
  cylinder { // Cylndrtank003
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_balltanktext
      rotate -90.0*z
    }
    photons {
      collect off
    }
    scale <0.85, 0.85, 1.13>
    translate  3.934636*z
  }
  sphere { // Sphere0tank01
    <0,0,0>,1
    material {
      Eagle_balltank2text
    }
    photons {
      collect off
    }
    scale 0.775
    translate  <0.000209, 0.0, 3.933122>
  }
  cylinder { // Cylndrtank005
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.55, 0.55, 0.2>
    translate  2.85*z
  }
  object { Eagle_engbell4 }
  photons {
    collect off
  }
  rotate 90.0*x
}
#declare Eagle_balltank6 = union {
  torus { // Torustank2
    1.5, 0.5  rotate -x*90
    material {
      Eagle_black
    }
    photons {
      collect off
    }
    scale <0.31, 0.31, 0.06>
    rotate 90.0*x
  }
  sphere { // Spheretankl9
    <0,0,0>,1
    material {
      Eagle_btank2sphere
    }
    photons {
      collect off
    }
    scale 0.575
    rotate 90.0*x
  }
  photons {
    collect off
  }
  translate  <-1.624856, -4.500811, -0.000084>
}
#declare Eagle_balltank7 = union {
  torus { // Torustank3
    1.5, 0.5  rotate -x*90
    material {
      Eagle_black
    }
    photons {
      collect off
    }
    scale <0.31, 0.31, 0.06>
    rotate 90.0*x
  }
  sphere { // Sphere1tank0
    <0,0,0>,1
    material {
      Eagle_btank2sphere
    }
    photons {
      collect off
    }
    scale 0.575
    rotate 90.0*x
  }
  photons {
    collect off
  }
  translate  <-1.624856, -4.500811, -2.75>
}
#declare Eagle_balltank8 = union {
  torus { // Torustank4
    1.5, 0.5  rotate -x*90
    material {
      Eagle_black
    }
    photons {
      collect off
    }
    scale <0.31, 0.31, 0.06>
    rotate 90.0*x
  }
  sphere { // Sphere1tankl1
    <0,0,0>,1
    material {
      Eagle_btank2sphere
    }
    photons {
      collect off
    }
    scale 0.575
    rotate 90.0*x
  }
  photons {
    collect off
  }
  translate  <1.624856, -4.500811, -2.75>
}
#declare Eagle_piping1 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <90.0, 90.0, 0.0>
  translate  <-1.623242, -4.968651, 0.002193>
}
#declare Eagle_piping2 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <90.0, 90.0, 0.0>
  translate  <1.623275, -4.969215, 0.001426>
}
#declare Eagle_piping3 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <-90.0, 90.0, 0.0>
  translate  <1.623275, -4.106542, 0.001426>
}
#declare Eagle_piping4 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <-90.0, 90.0, 0.0>
  translate  <-1.623788, -4.103875, 0.001426>
}
#declare Eagle_piping5 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <90.0, -90.0, -180.0>
  translate  <1.622466, -4.105385, -2.749254>
}
#declare Eagle_piping6 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <90.0, -90.0, -180.0>
  translate  <-1.62438, -4.104759, -2.749254>
}
#declare Eagle_piping7 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <90.0, -90.0, 0.0>
  translate  <-1.62383, -4.969394, -2.749254>
}
#declare Eagle_piping8 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.000000, -0.000002, 0.000000>, <-1.000000, -1.333333, 0.000000>, <1.000000, -1.333333, 0.000000>, <1.000000, -0.000000, 0.000000>, 
      <-1.000000, -0.000002, 2.000000>, <-1.000000, -1.333333, 2.000000>, <1.000000, -1.333333, 2.000000>, <1.000000, -0.000000, 2.000000>, 
      <-1.000000, -0.000002, 4.000000>, <-1.000000, -1.333333, 4.000000>, <0.948995, -1.333333, 3.897989>, <0.948995, -0.000000, 3.897989>, 
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.000000, -0.000000, 0.000000>, <1.000000, 1.333333, 0.000000>, <-1.000000, 1.333330, 0.000000>, <-1.000000, -0.000002, 0.000000>, 
      <1.000000, -0.000000, 2.000000>, <1.000000, 1.333333, 2.000000>, <-1.000000, 1.333330, 2.000000>, <-1.000000, -0.000002, 2.000000>, 
      <0.948995, -0.000000, 3.897989>, <0.948995, 1.333333, 3.897989>, <-1.000000, 1.333330, 4.000000>, <-1.000000, -0.000002, 4.000000>, 
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.772378, -0.000002, 6.025409>, <-0.772378, -1.333333, 6.025409>, <1.073762, -1.333333, 4.847857>, <1.073762, -0.000000, 4.847857>, 
      <-0.544756, -0.000002, 8.050818>, <-0.544756, -1.333333, 8.050818>, <1.198530, -1.333333, 5.797725>, <1.198530, -0.000000, 5.797725>, 
      <1.930005, -0.000002, 7.064523>, <1.930005, -1.333333, 7.064523>, <2.174635, -1.333333, 5.721663>, <2.174635, -0.000000, 5.721663>, 
      <13.777394, -0.000002, 7.275546>, <13.777394, -1.333333, 7.275546>, <13.782943, -1.333333, 5.789238>, <13.782943, -0.000000, 5.789238>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <1.073762, -0.000000, 4.847857>, <1.073762, 1.333333, 4.847857>, <-0.772378, 1.333330, 6.025409>, <-0.772378, -0.000002, 6.025409>, 
      <1.198530, -0.000000, 5.797725>, <1.198530, 1.333333, 5.797725>, <-0.544756, 1.333330, 8.050818>, <-0.544756, -0.000002, 8.050818>, 
      <2.174635, -0.000000, 5.721663>, <2.174635, 1.333333, 5.721663>, <1.930005, 1.333330, 7.064523>, <1.930005, -0.000002, 7.064523>, 
      <13.782943, -0.000000, 5.789238>, <13.782943, 1.333333, 5.789238>, <13.777394, 1.333330, 7.275546>, <13.777394, -0.000002, 7.275546>
    }
  }
  photons {
    collect off
  }
  scale 0.070166
  rotate <90.0, -90.0, 0.0>
  translate  <1.623291, -4.970147, -2.749254>
}
#declare Eagle_tankdettube1 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.327326>, <-0.021100, -0.028134, -0.327326>, <0.021100, -0.028134, -0.327326>, <0.021100, -0.000000, -0.327326>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.327326>, <0.021100, 0.028134, -0.327326>, <-0.021100, 0.028134, -0.327326>, <-0.021100, -0.000000, -0.327326>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -0.589448, 0.127904>, <-0.021100, -0.589382, 0.099770>, <0.021100, -0.589382, 0.099770>, <0.021100, -0.589448, 0.127904>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -0.589448, 0.127904>, <0.021100, -0.589513, 0.156037>, <-0.021100, -0.589513, 0.156037>, <-0.021100, -0.589448, 0.127904>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <53.0, -0.0, -0.0>
    translate <0.000000, 0.080273, -0.263753>
  }
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <4.221624, 2.161781, -2.340583>
}
#declare Eagle_tankdettube = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.451118>, <-0.021100, -0.028134, -0.451118>, <0.021100, -0.028134, -0.451118>, <0.021100, -0.000000, -0.451118>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.451118>, <0.021100, 0.028134, -0.451118>, <-0.021100, 0.028134, -0.451118>, <-0.021100, -0.000000, -0.451118>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -1.305432, 0.124558>, <-0.021100, -1.305366, 0.096424>, <0.021100, -1.305366, 0.096424>, <0.021100, -1.305432, 0.124558>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -1.305432, 0.124558>, <0.021100, -1.305497, 0.152692>, <-0.021100, -1.305497, 0.152692>, <-0.021100, -1.305432, 0.124558>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <58.0, -0.0, -0.0>
    translate <0.000000, 0.084095, -0.340203>
  }
  photons {
    collect off
  }
  rotate 90.0*y
  translate  <4.23231, 4.105506, -2.337724>
}
#declare Eagle_tankdetailtubing = union {
  object { Eagle_tankdettube1 }
  object { Eagle_tankdettube }
  cylinder { // tankdetcyl
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.5>
    rotate 90.0*x
    translate  <4.340442, 3.091426, -2.329705>
  }
  photons {
    collect off
  }
  rotate -78.738899*y
  translate  <-0.472651, -7.304564, -4.298286>
}
#declare Eagle_tankdettube2 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.327326>, <-0.021100, -0.028134, -0.327326>, <0.021100, -0.028134, -0.327326>, <0.021100, -0.000000, -0.327326>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.327326>, <0.021100, 0.028134, -0.327326>, <-0.021100, 0.028134, -0.327326>, <-0.021100, -0.000000, -0.327326>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -0.589448, 0.127904>, <-0.021100, -0.589382, 0.099770>, <0.021100, -0.589382, 0.099770>, <0.021100, -0.589448, 0.127904>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -0.589448, 0.127904>, <0.021100, -0.589513, 0.156037>, <-0.021100, -0.589513, 0.156037>, <-0.021100, -0.589448, 0.127904>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <53.0, -0.0, -0.0>
    translate <0.000000, 0.080273, -0.263753>
  }
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <4.221624, 2.161781, -2.340583>
}
#declare Eagle_tankdettube3 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.451118>, <-0.021100, -0.028134, -0.451118>, <0.021100, -0.028134, -0.451118>, <0.021100, -0.000000, -0.451118>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.451118>, <0.021100, 0.028134, -0.451118>, <-0.021100, 0.028134, -0.451118>, <-0.021100, -0.000000, -0.451118>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -1.305432, 0.124558>, <-0.021100, -1.305366, 0.096424>, <0.021100, -1.305366, 0.096424>, <0.021100, -1.305432, 0.124558>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -1.305432, 0.124558>, <0.021100, -1.305497, 0.152692>, <-0.021100, -1.305497, 0.152692>, <-0.021100, -1.305432, 0.124558>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <58.0, -0.0, -0.0>
    translate <0.000000, 0.084095, -0.340203>
  }
  photons {
    collect off
  }
  rotate 90.0*y
  translate  <4.23231, 4.105506, -2.337724>
}
#declare Eagle_tankdetailtubing1 = union {
  object { Eagle_tankdettube2 }
  object { Eagle_tankdettube3 }
  cylinder { // tankdetcyl1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.5>
    rotate 90.0*x
    translate  <4.340442, 3.091426, -2.329705>
  }
  photons {
    collect off
  }
  rotate <180.0, -84.059692, 180.0>
  translate  <-4.548577, -7.304465, -5.0428>
}
#declare Eagle_tankdettube4 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.327326>, <-0.021100, -0.028134, -0.327326>, <0.021100, -0.028134, -0.327326>, <0.021100, -0.000000, -0.327326>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.327326>, <0.021100, 0.028134, -0.327326>, <-0.021100, 0.028134, -0.327326>, <-0.021100, -0.000000, -0.327326>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -0.589448, 0.127904>, <-0.021100, -0.589382, 0.099770>, <0.021100, -0.589382, 0.099770>, <0.021100, -0.589448, 0.127904>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -0.589448, 0.127904>, <0.021100, -0.589513, 0.156037>, <-0.021100, -0.589513, 0.156037>, <-0.021100, -0.589448, 0.127904>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <53.0, -0.0, -0.0>
    translate <0.000000, 0.080273, -0.263753>
  }
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <4.221624, 2.161781, -2.340583>
}
#declare Eagle_tankdettube5 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.327326>, <-0.021100, -0.028134, -0.327326>, <0.021100, -0.028134, -0.327326>, <0.021100, -0.000000, -0.327326>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.327326>, <0.021100, 0.028134, -0.327326>, <-0.021100, 0.028134, -0.327326>, <-0.021100, -0.000000, -0.327326>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -0.589448, 0.127904>, <-0.021100, -0.589382, 0.099770>, <0.021100, -0.589382, 0.099770>, <0.021100, -0.589448, 0.127904>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -0.589448, 0.127904>, <0.021100, -0.589513, 0.156037>, <-0.021100, -0.589513, 0.156037>, <-0.021100, -0.589448, 0.127904>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <53.0, -0.0, -0.0>
    translate <0.000000, 0.080273, -0.263753>
  }
  photons {
    collect off
  }
  rotate <-90.0, 90.0, -90.0>
  translate  <4.221624, 3.449449, -2.340583>
}
#declare Eagle_tankdetailtubing2 = union {
  object { Eagle_tankdettube4 }
  cylinder { // tankdetcyl2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.5>
    rotate 90.0*x
    translate  <4.340442, 3.091426, -2.329705>
  }
  object { Eagle_tankdettube5 }
  photons {
    collect off
  }
  rotate <180.0, -90.0, 180.0>
  translate  <-2.337268, -7.307671, -3.445546>
}
#declare Eagle_tankdettube6 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.327326>, <-0.021100, -0.028134, -0.327326>, <0.021100, -0.028134, -0.327326>, <0.021100, -0.000000, -0.327326>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.327326>, <0.021100, 0.028134, -0.327326>, <-0.021100, 0.028134, -0.327326>, <-0.021100, -0.000000, -0.327326>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -0.589448, 0.127904>, <-0.021100, -0.589382, 0.099770>, <0.021100, -0.589382, 0.099770>, <0.021100, -0.589448, 0.127904>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -0.589448, 0.127904>, <0.021100, -0.589513, 0.156037>, <-0.021100, -0.589513, 0.156037>, <-0.021100, -0.589448, 0.127904>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <53.0, -0.0, -0.0>
    translate <0.000000, 0.080273, -0.263753>
  }
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <4.221624, 2.161781, -2.340583>
}
#declare Eagle_tankdettube7 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.000000, -0.327326>, <-0.021100, -0.028134, -0.327326>, <0.021100, -0.028134, -0.327326>, <0.021100, -0.000000, -0.327326>, 
      <-0.021100, -0.000000, 0.043836>, <-0.021100, -0.028134, 0.043836>, <0.021100, -0.028134, 0.043836>, <0.021100, -0.000000, 0.043836>, 
      <-0.021100, -0.000000, 0.086036>, <-0.021100, -0.028134, 0.086036>, <0.021100, -0.028134, 0.086036>, <0.021100, -0.000000, 0.086036>, 
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.000000, -0.327326>, <0.021100, 0.028134, -0.327326>, <-0.021100, 0.028134, -0.327326>, <-0.021100, -0.000000, -0.327326>, 
      <0.021100, -0.000000, 0.043836>, <0.021100, 0.028134, 0.043836>, <-0.021100, 0.028134, 0.043836>, <-0.021100, -0.000000, 0.043836>, 
      <0.021100, -0.000000, 0.086036>, <0.021100, 0.028134, 0.086036>, <-0.021100, 0.028134, 0.086036>, <-0.021100, -0.000000, 0.086036>, 
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-0.021100, -0.003246, 0.105942>, <-0.021100, -0.029843, 0.089690>, <0.021100, -0.029843, 0.089690>, <0.021100, -0.003246, 0.105942>, 
      <-0.021100, -0.006492, 0.125847>, <-0.021100, -0.031553, 0.093343>, <0.021100, -0.031553, 0.093343>, <0.021100, -0.006492, 0.125847>, 
      <-0.021100, -0.038860, 0.124656>, <-0.021100, -0.038795, 0.096523>, <0.021100, -0.038795, 0.096523>, <0.021100, -0.038860, 0.124656>, 
      <-0.021100, -0.589448, 0.127904>, <-0.021100, -0.589382, 0.099770>, <0.021100, -0.589382, 0.099770>, <0.021100, -0.589448, 0.127904>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <0.021100, -0.003246, 0.105942>, <0.021100, 0.023351, 0.122193>, <-0.021100, 0.023351, 0.122193>, <-0.021100, -0.003246, 0.105942>, 
      <0.021100, -0.006492, 0.125847>, <0.021100, 0.018569, 0.158350>, <-0.021100, 0.018569, 0.158350>, <-0.021100, -0.006492, 0.125847>, 
      <0.021100, -0.038860, 0.124656>, <0.021100, -0.038926, 0.152790>, <-0.021100, -0.038926, 0.152790>, <-0.021100, -0.038860, 0.124656>, 
      <0.021100, -0.589448, 0.127904>, <0.021100, -0.589513, 0.156037>, <-0.021100, -0.589513, 0.156037>, <-0.021100, -0.589448, 0.127904>
    }
  }
  material {
    Eagle_tankdettubing
    scale 0.08
    rotate <53.0, -0.0, -0.0>
    translate <0.000000, 0.080273, -0.263753>
  }
  photons {
    collect off
  }
  rotate <-90.0, 90.0, -90.0>
  translate  <4.221624, 3.449449, -2.340583>
}
#declare Eagle_tankdetailtubing3 = union {
  object { Eagle_tankdettube6 }
  cylinder { // tankdetcyl3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.5>
    rotate 90.0*x
    translate  <4.340442, 3.091426, -2.329705>
  }
  object { Eagle_tankdettube7 }
  photons {
    collect off
  }
  rotate <-180.0, -270.0, 180.0>
  translate  <2.326628, -7.307671, 0.699757>
}
#declare Eagle_engines = union {
  cylinder { // Cylndr370
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.15>
    rotate <0.0, 59.708961, 0.0>
    translate  <-2.128839, -2.949625, -0.944214>
  }
  cylinder { // Cylndr360
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.15>
    rotate <180.0, -63.487972, -180.0>
    translate  <2.201652, -2.949995, -1.782328>
  }
  cylinder { // Cylndr350
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.15>
    rotate <-0.0, -59.631237, 0.0>
    translate  <2.109939, -2.949574, -0.936997>
  }
  cylinder { // Cylndr340
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate -90.0*y
    translate  <-0.450201, -2.950648, -1.823354>
  }
  cylinder { // Cylndr330
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate -90.0*y
    translate  <-0.450201, -2.949574, -0.925906>
  }
  cylinder { // Cylndr320
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate 90.0*y
    translate  <0.450201, -2.949574, -0.925906>
  }
  cylinder { // Cylndr310
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate 90.0*y
    translate  <0.450201, -2.949574, -1.8239>
  }
  cylinder { // Cylndr300
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.95>
    translate  <0.450201, -2.949574, -2.749981>
  }
  cylinder { // Cylndr290
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.95>
    translate  <-0.450077, -2.950004, -2.749981>
  }
  cylinder { // Cylndr0061
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.65>
    translate  <0.0, -2.950004, -2.200003>
  }
  object { Eagle_balltank1 }
  object { Eagle_balltank2 }
  object { Eagle_balltank3 }
  object { Eagle_balltank4 }
  object { Eagle_balltank5 }
  object { Eagle_balltank6 }
  object { Eagle_balltank7 }
  object { Eagle_balltank8 }
  cylinder { // fueline1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.15>
    rotate <-180.0, 64.478157, -180.0>
    translate  <-2.189726, -2.949625, -1.822736>
  }
  cylinder { // engsupport1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <0.447806, -2.948676, -0.927155>
  }
  cylinder { // engsupport2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <-0.447532, -2.948676, -0.923489>
  }
  cylinder { // engsupport3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <-0.451406, -2.948676, -1.824345>
  }
  cylinder { // engsupport4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <0.448754, -2.948676, -1.824345>
  }
  cylinder { // engsupport5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <1.566299, -2.948676, -1.827012>
  }
  cylinder { // engsupport6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <1.566299, -2.948676, -0.922828>
  }
  cylinder { // engsupport7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <-1.568748, -2.948676, -0.925004>
  }
  cylinder { // engsupport8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.17>
    rotate 90.0*x
    translate  <-1.576071, -2.948676, -1.825039>
  }
  object { Eagle_piping1 }
  object { Eagle_piping2 }
  object { Eagle_piping3 }
  object { Eagle_piping4 }
  object { Eagle_piping5 }
  object { Eagle_piping6 }
  object { Eagle_piping7 }
  object { Eagle_piping8 }
  object { Eagle_tankdetailtubing }
  object { Eagle_tankdetailtubing1 }
  object { Eagle_tankdetailtubing2 }
  object { Eagle_tankdetailtubing3 }
  photons {
    collect off
  }
  translate  <0.82947, 7.429182, -0.955572>
}
#declare Eagle_CSG44GEAR = difference {
  box { // Cube145Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.31698, 0.525, 0.05>
    translate  0.94*z
  }
  box { // Cube146Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.223629, 0.49418, 0.08>
    translate  <0.0, -0.089332, 0.94>
  }
  photons {
    collect off
  }
  scale <1.038307, 1.212514, 1.0>
}
#declare Eagle_gearstruta = union {
  cylinder { // Cylndr128Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-19.433929, -24.383585, -0.036361>
    translate  <-0.28273, 0.576777, 0.97194>
  }
  cylinder { // Cylndr129Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-23.208288, 21.251493, -9.656242>
    translate  <0.27971, 0.574937, 0.971881>
  }
  cylinder { // Cylndr130Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <19.116533, 24.203886, 0.586954>
    translate  <0.28036, -0.579915, 0.97194>
  }
  cylinder { // Cylndr131Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <18.384859, -23.857531, 0.240646>
    translate  <-0.281417, -0.583656, 0.971926>
  }
  cylinder { // Cylndr132Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    translate  1.3*z
  }
  object { Eagle_CSG44GEAR }
  torus { // Torus8Eagle_GEAR
    1.5, 0.5  rotate -x*90
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.06>
    translate  1.27*z
  }
  photons {
    collect off
  }
}
#declare Eagle_ANKLE9 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <-0.115, 0.0, 0.345336>
}
#declare Eagle_ANKLE10 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <0.115, 0.000374, 0.344997>
}
#declare Eagle_ANKLES6 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <0.0, -0.461675, 0.269988>
}
#declare Eagle_ANKLES7 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.0, 0.468766, 0.269988>
}
#declare Eagle_pad6 = prism {
  linear_sweep
  linear_spline
  -1.25,0.0
  5  // control points
  <-1.375, -0.125>,
  <1.375, -0.125>,
  <1.6, 0.125>,
  <-1.6, 0.125>,
  <-1.375, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <0.625, -0.0, 0.0>
}
#declare Eagle_pad7 = prism {
  linear_sweep
  linear_spline
  -1.75,0.0
  5  // control points
  <-1.15, -0.125>,
  <1.15, -0.125>,
  <1.4, 0.125>,
  <-1.4, 0.125>,
  <-1.15, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <-0.0, -0.875, 0.0>
}
#declare Eagle_TraSwp90Eagle_GEAR = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -68.455841, -90.0>
  translate  <-0.096541, 0.752204, 0.553565>
}
#declare Eagle_TraSwp91Eagle_GEAR = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -46.368126, 90.0>
  translate  <-0.147043, 0.811385, 0.900128>
}
#declare Eagle_GEAR3 = union {
  cylinder { // Cylndr133Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.0, 0.343582>
  }
  cylinder { // Cylndr134GEAR
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 1.4>
    translate  0.19503*z
  }
  object { Eagle_ANKLE9 }
  object { Eagle_ANKLE10 }
  object { Eagle_ANKLES6 }
  object { Eagle_ANKLES7 }
  box { // Cube147Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.875, 0.625, 0.035>
    rotate -90.0*z
    translate  0.16*z
  }
  cylinder { // Cylndr135Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.174411, 1.056223, 0.673279>
  }
  cylinder { // Cylndr136Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.39>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.194769, 0.56824, 1.128579>
  }
  cylinder { // Cylndr137Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.44827, 0.428438>
  }
  box { // Cube148Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, 1.263, 0.125>
  }
  box { // Cube149Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, 1.263, 0.125>
  }
  box { // Cube150Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, 1.263, 0.125>
  }
  box { // Cube151Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, 1.263, 0.125>
  }
  box { // Cube152Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, 1.263, 0.125>
  }
  box { // Cube153Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, -1.263, 0.125>
  }
  box { // Cube154GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, -1.263, 0.125>
  }
  box { // Cube155Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, -1.263, 0.125>
  }
  box { // Cube156Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, -1.263, 0.125>
  }
  box { // Cube157Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, -1.263, 0.125>
  }
  object { Eagle_pad6 }
  box { // Cube158Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube159Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube160Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube161Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.0, 0.125>
  }
  box { // Cube162Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.344521, 0.125>
  }
  box { // Cube163Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.678611, 0.125>
  }
  box { // Cube164GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.677193, 0.125>
  }
  box { // Cube165Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.344834, 0.125>
  }
  box { // Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube167Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  object { Eagle_pad7 }
  object { Eagle_TraSwp90Eagle_GEAR }
  object { Eagle_TraSwp91Eagle_GEAR }
  photons {
    collect off
  }
  translate  -0.25*z
}
#declare Eagle_gearlf = union {
  object { Eagle_gearstruta }
  object { Eagle_GEAR3 }
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  translate  <5.669117, -19.643061, -6.149076>
}
#declare Eagle_CSG42Eagle_GEAR = difference {
  box { // Cube122Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.31698, 0.525, 0.05>
    translate  0.94*z
  }
  box { // Cube123Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.223629, 0.49418, 0.08>
    translate  <0.0, -0.089332, 0.94>
  }
  photons {
    collect off
  }
  scale <1.038307, 1.212514, 1.0>
}
#declare Eagle_CSG43Eagle_GEAR = union {
  cylinder { // Cylndr118Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-19.433929, -24.383585, -0.036361>
    translate  <-0.28273, 0.576777, 0.97194>
  }
  cylinder { // Cylndr119Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-23.208288, 21.251493, -9.656242>
    translate  <0.27971, 0.574937, 0.971881>
  }
  cylinder { // Cylndr120Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <19.116533, 24.203886, 0.586954>
    translate  <0.28036, -0.579915, 0.97194>
  }
  cylinder { // Cylndr121Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <18.384859, -23.857531, 0.240646>
    translate  <-0.281417, -0.583656, 0.971926>
  }
  cylinder { // Cylndr122Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    translate  1.3*z
  }
  object { Eagle_CSG42Eagle_GEAR }
  torus { // Torus7Eagle_GEAR
    1.5, 0.5  rotate -x*90
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.06>
    translate  1.27*z
  }
  photons {
    collect off
  }
}
#declare Eagle_ANKLE7 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <-0.115, 0.0, 0.345336>
}
#declare Eagle_ANKLE8 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <0.115, 0.000374, 0.344997>
}
#declare Eagle_ANKLES4 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <0.0, -0.461675, 0.269988>
}
#declare Eagle_ANKLES5 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.0, 0.468766, 0.269988>
}
#declare Eagle_pad4 = prism {
  linear_sweep
  linear_spline
  -1.25,0.0
  5  // control points
  <-1.375, -0.125>,
  <1.375, -0.125>,
  <1.6, 0.125>,
  <-1.6, 0.125>,
  <-1.375, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <0.625, -0.0, 0.0>
}
#declare Eagle_pad5 = prism {
  linear_sweep
  linear_spline
  -1.75,0.0
  5  // control points
  <-1.15, -0.125>,
  <1.15, -0.125>,
  <1.4, 0.125>,
  <-1.4, 0.125>,
  <-1.15, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <-0.0, -0.875, 0.0>
}
#declare Eagle_TraSwp88Eagle_GEAR = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -68.455841, -90.0>
  translate  <-0.102071, 0.752204, 0.553565>
}
#declare Eagle_TraSwp89Eagle_GEAR = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -46.368126, 90.0>
  translate  <-0.150165, 0.811385, 0.900128>
}
#declare Eagle_GEAR2 = union {
  cylinder { // Cylndr123Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.0, 0.343582>
  }
  cylinder { // Cylndr124GEAR
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 1.4>
    translate  0.19503*z
  }
  object { Eagle_ANKLE7 }
  object { Eagle_ANKLE8 }
  object { Eagle_ANKLES4 }
  object { Eagle_ANKLES5 }
  box { // Cube124GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.875, 0.625, 0.035>
    rotate -90.0*z
    translate  0.16*z
  }
  cylinder { // Cylndr125Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.177683, 1.052337, 0.673279>
  }
  cylinder { // Cylndr126Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.176376, 0.56824, 1.128579>
  }
  cylinder { // Cylndr127Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.44827, 0.428438>
  }
  box { // Cube125Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, 1.263, 0.125>
  }
  box { // Cube126Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, 1.263, 0.125>
  }
  box { // Cube127Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, 1.263, 0.125>
  }
  box { // Cube128Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, 1.263, 0.125>
  }
  box { // Cube129Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, 1.263, 0.125>
  }
  box { // Cube130Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, -1.263, 0.125>
  }
  box { // Cube131Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, -1.263, 0.125>
  }
  box { // Cube132Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, -1.263, 0.125>
  }
  box { // Cube133Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, -1.263, 0.125>
  }
  box { // Cube134GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, -1.263, 0.125>
  }
  object { Eagle_pad4 }
  box { // Cube135Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube136Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube137Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube138Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.0, 0.125>
  }
  box { // Cube139Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.344521, 0.125>
  }
  box { // Cube140Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.678611, 0.125>
  }
  box { // Cube141Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.677193, 0.125>
  }
  box { // Cube142Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.344834, 0.125>
  }
  box { // Cube143Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube144GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  object { Eagle_pad5 }
  object { Eagle_TraSwp88Eagle_GEAR }
  object { Eagle_TraSwp89Eagle_GEAR }
  photons {
    collect off
  }
  translate  -0.25*z
}
#declare Eagle_gearrf = union {
  object { Eagle_CSG43Eagle_GEAR }
  object { Eagle_GEAR2 }
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  translate  <-4.052927, -19.643217, -6.149264>
}
#declare Eagle_CSG40Eagle_GEAR = difference {
  box { // Cube99Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.31698, 0.525, 0.05>
    translate  0.94*z
  }
  box { // Cube100Eagle_GEAR
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.223629, 0.49418, 0.08>
    translate  <0.0, -0.089332, 0.94>
  }
  photons {
    collect off
  }
  scale <1.038307, 1.212514, 1.0>
}
#declare Eagle_CSG41Eagle_GEAR = union {
  cylinder { // Cylndr108Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-19.433929, -24.383585, -0.036361>
    translate  <-0.28273, 0.576777, 0.97194>
  }
  cylinder { // Cylndr109Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-23.208288, 21.251493, -9.656242>
    translate  <0.27971, 0.574937, 0.971881>
  }
  cylinder { // Cylndr110Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <19.116533, 24.203886, 0.586954>
    translate  <0.28036, -0.579915, 0.97194>
  }
  cylinder { // Cylndr111Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <18.384859, -23.857531, 0.240646>
    translate  <-0.281417, -0.583656, 0.971926>
  }
  cylinder { // Cylndr112Eagle_GEAR
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    translate  1.3*z
  }
  object { Eagle_CSG40Eagle_GEAR }
  torus { // Torus6Eagle_GEAR
    1.5, 0.5  rotate -x*90
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.06>
    translate  1.27*z
  }
  photons {
    collect off
  }
}
#declare Eagle_ANKLE5 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <-0.115, 0.0, 0.345336>
}
#declare Eagle_ANKLE6 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <0.115, 0.000374, 0.344997>
}
#declare Eagle_ANKLES2 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <0.0, -0.461675, 0.269988>
}
#declare Eagle_ANKLES3 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.0, 0.468766, 0.269988>
}
#declare Eagle_pad1 = prism {
  linear_sweep
  linear_spline
  -1.25,0.0
  5  // control points
  <-1.375, -0.125>,
  <1.375, -0.125>,
  <1.6, 0.125>,
  <-1.6, 0.125>,
  <-1.375, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <0.625, -0.0, 0.0>
}
#declare Eagle_pad3 = prism {
  linear_sweep
  linear_spline
  -1.75,0.0
  5  // control points
  <-1.15, -0.125>,
  <1.15, -0.125>,
  <1.4, 0.125>,
  <-1.4, 0.125>,
  <-1.15, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <-0.0, -0.875, 0.0>
}
#declare Eagle_TraSwp86ge = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -68.455841, -90.0>
  translate  <-0.101111, 0.752204, 0.553565>
}
#declare Eagle_TraSwp87ge = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -46.368126, 90.0>
  translate  <-0.149169, 0.80849, 0.900128>
}
#declare Eagle_GEAR1 = union {
  cylinder { // Cylndr113ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.0, 0.343582>
  }
  cylinder { // Cylndr114ge
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 1.4>
    translate  0.19503*z
  }
  object { Eagle_ANKLE5 }
  object { Eagle_ANKLE6 }
  object { Eagle_ANKLES2 }
  object { Eagle_ANKLES3 }
  box { // Cube101ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.875, 0.625, 0.035>
    rotate -90.0*z
    translate  0.16*z
  }
  cylinder { // Cylndr115ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.177685, 1.058127, 0.673279>
  }
  cylinder { // Cylndr116ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.17483, 0.566193, 1.128579>
  }
  cylinder { // Cylndr117ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.44827, 0.428438>
  }
  box { // Cube102ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, 1.263, 0.125>
  }
  box { // Cube103ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, 1.263, 0.125>
  }
  box { // Cube104ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, 1.263, 0.125>
  }
  box { // Cube105ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, 1.263, 0.125>
  }
  box { // Cube106ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, 1.263, 0.125>
  }
  box { // Cube107ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, -1.263, 0.125>
  }
  box { // Cube108ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, -1.263, 0.125>
  }
  box { // Cube109ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, -1.263, 0.125>
  }
  box { // Cube110ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, -1.263, 0.125>
  }
  box { // Cube111ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, -1.263, 0.125>
  }
  object { Eagle_pad1 }
  box { // Cube112ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube113ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube114ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube115ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.0, 0.125>
  }
  box { // Cube116ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.344521, 0.125>
  }
  box { // Cube117ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.678611, 0.125>
  }
  box { // Cube118ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.677193, 0.125>
  }
  box { // Cube119ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.344834, 0.125>
  }
  box { // Cube120ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube121ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  object { Eagle_pad3 }
  object { Eagle_TraSwp86ge }
  object { Eagle_TraSwp87ge }
  photons {
    collect off
  }
  translate  -0.25*z
}
#declare Eagle_gearrr = union {
  object { Eagle_CSG41Eagle_GEAR }
  object { Eagle_GEAR1 }
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  translate  <-4.053547, -1.505786, -6.149264>
}
#declare Eagle_CSG38ge = difference {
  box { // Cube76ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.31698, 0.525, 0.05>
    translate  0.94*z
  }
  box { // Cube77ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.223629, 0.49418, 0.08>
    translate  <0.0, -0.089332, 0.94>
  }
  photons {
    collect off
  }
  scale <1.038307, 1.212514, 1.0>
}
#declare Eagle_CSG39ge = union {
  cylinder { // Cylndr98ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-19.433929, -24.383585, -0.036361>
    translate  <-0.28273, 0.576777, 0.97194>
  }
  cylinder { // Cylndr99ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <-23.208288, 21.251493, -9.656242>
    translate  <0.27971, 0.574937, 0.971881>
  }
  cylinder { // Cylndr100ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <19.116533, 24.203886, 0.586954>
    translate  <0.28036, -0.579915, 0.97194>
  }
  cylinder { // Cylndr101ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.8>
    rotate <18.384859, -23.857531, 0.240646>
    translate  <-0.281417, -0.583656, 0.971926>
  }
  cylinder { // Cylndr102ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    translate  1.3*z
  }
  object { Eagle_CSG38ge }
  torus { // Torus5ge
    1.5, 0.5  rotate -x*90
    photons {
      collect off
    }
    scale <0.1, 0.1, 0.06>
    translate  1.27*z
  }
  photons {
    collect off
  }
}
#declare Eagle_ANKLE4 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <-0.115, 0.0, 0.345336>
}
#declare Eagle_ANKLE3 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  5  // control points
  <-0.7, -0.15>,
  <0.7, -0.15>,
  <0.5, 0.15>,
  <-0.5, 0.15>,
  <-0.7, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <0.115, 0.000374, 0.344997>
}
#declare Eagle_ANKLES1 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <0.0, -0.461675, 0.269988>
}
#declare Eagle_ANKLES = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.575, -0.075>,
  <0.575, -0.075>,
  <0.45, 0.075>,
  <-0.45, 0.075>,
  <-0.575, -0.075>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.0, 0.468766, 0.269988>
}
#declare Eagle_pad = prism {
  linear_sweep
  linear_spline
  -1.25,0.0
  5  // control points
  <-1.375, -0.125>,
  <1.375, -0.125>,
  <1.6, 0.125>,
  <-1.6, 0.125>,
  <-1.375, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <0.625, -0.0, 0.0>
}
#declare Eagle_pad2 = prism {
  linear_sweep
  linear_spline
  -1.75,0.0
  5  // control points
  <-1.15, -0.125>,
  <1.15, -0.125>,
  <1.4, 0.125>,
  <-1.4, 0.125>,
  <-1.15, -0.125>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, 180.0>
  translate  <-0.0, -0.875, 0.0>
}
#declare Eagle_TraSwp84ge = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -68.455841, -90.0>
  translate  <-0.100345, 0.752204, 0.553565>
}
#declare Eagle_TraSwp85ge = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -46.368126, 90.0>
  translate  <-0.151302, 0.811385, 0.900128>
}
#declare Eagle_GEAR = union {
  cylinder { // Cylndr103gee
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.07, 0.07, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.0, 0.343582>
  }
  cylinder { // Cylndr104ge
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 1.4>
    translate  0.19503*z
  }
  object { Eagle_ANKLE4 }
  object { Eagle_ANKLE3 }
  object { Eagle_ANKLES1 }
  object { Eagle_ANKLES }
  box { // Cube78ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.875, 0.625, 0.035>
    rotate -90.0*z
    translate  0.16*z
  }
  cylinder { // Cylndr105ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.178535, 1.052337, 0.673279>
  }
  cylinder { // Cylndr106ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.176162, 0.56601, 1.128579>
  }
  cylinder { // Cylndr107ge
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.4>
    rotate <-0.0, 90.0, 0.0>
    translate  <-0.202668, 0.44827, 0.428438>
  }
  box { // Cube79ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, 1.263, 0.125>
  }
  box { // Cube80ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, 1.263, 0.125>
  }
  box { // Cube81ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, 1.263, 0.125>
  }
  box { // Cube82ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, 1.263, 0.125>
  }
  box { // Cube83ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, 1.263, 0.125>
  }
  box { // Cube84ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.000941, -1.263, 0.125>
  }
  box { // Cube85ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.246809, -1.263, 0.125>
  }
  box { // Cube86ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <0.485897, -1.263, 0.125>
  }
  box { // Cube87ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.493247, -1.263, 0.125>
  }
  box { // Cube88ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.094876, 0.295701, 0.035>
    translate  <-0.249132, -1.263, 0.125>
  }
  object { Eagle_pad }
  box { // Cube89ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube90ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube91ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube92ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.0, 0.125>
  }
  box { // Cube93ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.344521, 0.125>
  }
  box { // Cube94ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, -0.678611, 0.125>
  }
  box { // Cube95ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.677193, 0.125>
  }
  box { // Cube96ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <-1.05, 0.344834, 0.125>
  }
  box { // Cube97ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube98ge
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  object { Eagle_pad2 }
  object { Eagle_TraSwp84ge }
  object { Eagle_TraSwp85ge }
  photons {
    collect off
  }
  translate  -0.25*z
}
#declare Eagle_gearlr = union {
  object { Eagle_CSG39ge }
  object { Eagle_GEAR }
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  translate  <5.668995, -1.505786, -6.149264>
}
#declare Eagle_TraSwp21 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp22 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -90.0>
  translate  <-1.1, -1.4, -0.65>
}
#declare Eagle_TraSwp23 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <-1.1, -1.4, 0.65>
}
#declare Eagle_TraSwp24 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -0.0>
  translate  <1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp25 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 90.0, 0.0>
  translate  <1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp26 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -180.0>
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp5 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*y
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp27 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, -90.0, -0.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp28 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, 0.0, 45.0>
  translate  <0.984846, -1.302238, 1.293298>
}
#declare Eagle_TraSwp29 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, 135.0>
  translate  <1.002227, 1.284839, 1.293298>
}
#declare Eagle_TraSwp30 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -135.0>
  translate  <-0.984844, 1.302236, 1.293298>
}
#declare Eagle_TraSwp31 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.002236, -1.284844, 1.293298>
}
#declare Eagle_TraSwp32 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 45.0>
  translate  <1.158052, -1.475444, -1.466497>
}
#declare Eagle_TraSwp33 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 135.0>
  translate  <1.175444, 1.458052, -1.466497>
}
#declare Eagle_TraSwp34 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, -0.0, -135.0>
  translate  <-1.158052, 1.475444, -1.466497>
}
#declare Eagle_TraSwp35 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, -45.0>
  translate  <-1.175444, -1.458052, -1.466497>
}
#declare Eagle_TraSwp36 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, 135.0>
  translate  <1.065912, 1.348523, 1.292493>
}
#declare Eagle_TraSwp37 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -135.0>
  translate  <-1.038963, 1.356356, 1.30218>
}
#declare Eagle_TraSwp38 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.061085, -1.343693, 1.297021>
}
#declare Eagle_TraSwp39 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, 0.0, 45.0>
  translate  <1.036965, -1.354358, 1.29839>
}
#declare Eagle_pods1 = union {
  object { Eagle_TraSwp21 }
  object { Eagle_TraSwp22 }
  object { Eagle_TraSwp23 }
  object { Eagle_TraSwp24 }
  object { Eagle_TraSwp25 }
  object { Eagle_TraSwp26 }
  object { Eagle_TraSwp5 }
  box { // pod2
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.1, 1.4, 1.6>
  }
  box { // pod3
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.05, 2.35, 0.65>
  }
  object { Eagle_TraSwp27 }
  object { Eagle_TraSwp28 }
  object { Eagle_TraSwp29 }
  object { Eagle_TraSwp30 }
  object { Eagle_TraSwp31 }
  object { Eagle_TraSwp32 }
  object { Eagle_TraSwp33 }
  object { Eagle_TraSwp34 }
  object { Eagle_TraSwp35 }
  object { Eagle_TraSwp36 }
  object { Eagle_TraSwp37 }
  object { Eagle_TraSwp38 }
  object { Eagle_TraSwp39 }
  box { // details10
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, 0.0, -0.0>
    translate  <0.520092, -2.306431, 0.0>
  }
  box { // details11
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, 0.0, -0.0>
    translate  <0.831892, -2.305553, -0.000387>
  }
  box { // details12
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.214134, 0.53431, 0.1>
    rotate <90.0, 0.0, -0.0>
    translate  <-0.808366, -2.311085, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_corners1 = union {
  box { // cutouttt4
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <-1.887544, 2.128141, 0.0>
  }
  box { // cutouttt5
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <1.868491, 2.147195, 0.0>
  }
  box { // cutouttt6
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <-1.875645, -2.14004, 0.0>
  }
  box { // cutouttt7
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <1.835482, -2.180203, 0.0>
  }
  box { // details13
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.016129, 0.53431, 0.1>
    rotate <90.0, 0.0, -0.0>
    translate  <-0.007032, 2.396445, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_podss1 = difference {
  object { Eagle_pods1 }
  object { Eagle_corners1 }
  photons {
    collect off
  }
}
#declare Eagle_CSG16 = union {
  cylinder { // Cylndr61
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale <0.06, 0.06, 0.1>
    rotate 45.0*y
    translate  <1.565881, 0.968648, 1.090452>
  }
  cylinder { // Cylndr62
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.565881, 1.140489, 1.086633>
  }
  cylinder { // Cylndr63
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.565881, 0.804445, 1.090452>
  }
  cylinder { // Cylndr64
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.43919, 0.968648, 1.21955>
  }
  cylinder { // Cylndr65
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.695589, 0.968648, 0.963151>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG17 = difference {
  cylinder { // Cylndr60
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    rotate 45.0*y
    translate  <1.55678, 0.968648, 1.084393>
  }
  object { Eagle_CSG16 }
  photons {
    collect off
  }
}
#declare Eagle_CSG18 = difference {
  box { // details19
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.638447, 0.474085, 0.101723>
    rotate 90.0*x
    translate  <-0.298564, 2.254878, 0.0>
  }
  cylinder { // Cylndr66
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.25, 0.25, 0.222895>
    rotate 90.0*x
    translate  <-0.595948, 2.474234, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG19 = difference {
  box { // Cube28
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, 45.0>
    translate  <1.538216, -1.894901, 0.0>
  }
  cylinder { // Cylndr67
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale 0.15
    rotate <90.0, 0.0, 45.0>
    translate  <1.557149, -1.903054, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_RotSwp5 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <90.0, -0.0, -0.0>
  translate  <2.299984, 0.654983, 0.000003>
}
#declare Eagle_RotSwp6 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <-90.0, -0.0, 0.0>
  translate  <2.300001, -0.655, 0.000014>
}
#declare Eagle_RotSwp7 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate 180.0*x
  translate  <2.299944, -0.0, 0.579997>
}
#declare Eagle_RotSwp8 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  translate  <2.29998, 0.000028, -0.579984>
}
#declare Eagle_lfEagle_podspheredet2 = lathe {
  linear_spline
  10  // control points
  <0.017094, -0.501425>,
  <1.790401, -0.5>,
  <1.790401, 0.5>,
  <1.643722, 0.49899>,
  <1.643669, 0.589571>,
  <1.549475, 0.589139>,
  <1.552686, 0.497756>,
  <1.412992, 0.496795>,
  <1.417809, -0.335185>,
  <0.002849, -0.339031>
  rotate <90,0,90>
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  scale 0.062782
  rotate <-45.0, 0.0, 180.0>
  translate  <-0.44278, -2.013531, 1.244105>
}
#declare podetails1 = union {
  cylinder { // Cylndr58
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.222895>
    rotate 90.0*x
    translate  <-0.600895, 2.379453, 0.0>
  }
  box { // details14
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.049883, 0.251479, 0.101723>
    rotate 90.0*x
    translate  <0.830208, 2.249624, 0.0>
  }
  box { // details18
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.375523, 0.53431, 0.1>
    rotate 90.0*x
    translate  <-0.094684, -2.309971, 0.0>
  }
  box { // Cube13
    <-1, -1, -1>, <1, 1, 1>
    material {
      thrusters
      scale <1.916959, 1.916933, 1.800311>
      translate <-0.916959, -0.907763, 0.308391>
    }
    photons {
      collect off
    }
    scale <0.65, 1.35, 0.1>
    rotate <-0.0, 90.0, 0.0>
    translate  2.0*x
  }
  box { // Cube14
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.394618, 2.080114, 0.007156>
  }
  box { // Cube15
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.775841, 1.707945, 0.007156>
  }
  box { // Cube16
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, -45.0>
    translate  <-1.576331, -1.879875, 0.0>
  }
  box { // Cube17
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.384006, 2.063083, 0.007156>
  }
  box { // Cube18
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.759809, 1.687423, 0.007156>
  }
  box { // Cube19
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.352468, 0.557803, 0.062537>
    rotate 45.0*y
    translate  <1.562522, -0.723164, 1.10487>
  }
  box { // Cube20
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.435367, 0.768652, 0.03654>
    rotate -45.0*y
    translate  <-1.566077, 0.0, 1.120275>
  }
  box { // Cube21
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.499572, 0.500782, 0.1>
    translate  <0.517691, 0.706973, 1.552503>
  }
  box { // Cube22
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.441879, 0.654631, 0.1>
    translate  <-0.541624, 0.555544, 1.552503>
  }
  cylinder { // Cylndr59
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <0.518265, -0.825361, 1.541025>
  }
  sphere { // Sphere12
    <0,0,0>,1
    photons {
      collect off
    }
    scale 0.22
    translate  <-0.555693, -0.614372, 1.582052>
  }
  object { Eagle_CSG17 }
  box { // Cube23
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <-0.091818, -0.472462, -0.048306>
    rotate <-135.0, 0.0, -180.0>
    translate  <-0.814766, 1.853404, 1.109259>
  }
  box { // Cube24
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <0.536169, 2.053322, 0.929678>
  }
  box { // Cube25
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <0.536169, 1.676239, 1.315065>
  }
  box { // Cube26
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.070355, 0.330477, 0.091429>
    rotate 45.0*x
    translate  <-0.915547, -1.879346, 1.08871>
  }
  sphere { // Sphere13
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale 0.22
    translate  <-0.446544, -1.887489, 1.103062>
  }
  box { // Cube27
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.560765, 0.286208, 0.04716>
    rotate 45.0*x
    translate  <0.420039, -1.902621, 1.101183>
  }
  object { Eagle_CSG18 }
  object { Eagle_CSG19 }
  object { Eagle_RotSwp5 }
  object { Eagle_RotSwp6 }
  object { Eagle_RotSwp7 }
  object { Eagle_RotSwp8 }
  box { // Cube29
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.175, 0.325, 0.25>
    translate  2.27*x
  }
  box { // Cube30
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate 45.0*x
    translate  <0.0, 2.024267, -0.972516>
  }
  box { // Cube31
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate -45.0*x
    translate  <0.0, -2.013755, -0.972516>
  }
  box { // Cube209
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.28, 0.286208, 0.04716>
    rotate 45.0*x
    translate  <0.703991, -1.612702, 1.34779>
  }
  box { // Cube210
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.070355, 0.227644, 0.091429>
    rotate 90.0*z
    translate  <-0.15968, -0.278878, 1.532602>
  }
  cylinder { // tinypoddetail3
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.047977, 0.050836, 0.225233>
    rotate <-180.0, -90.0, 0.0>
    translate  <-0.365675, -1.880369, 1.126341>
  }
  object { Eagle_lfEagle_podspheredet2 }
  photons {
    collect off
  }
}
#declare Eagle_CSG20po = union {
  object { Eagle_podss1 }
  object { podetails1 }
  photons {
    collect off
  }
}
#declare Eagle_CSG21po = union {
  box { // Cube32
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.7, 2.0, 0.25>
    translate  -2.5*z
  }
  box { // Cube33
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.0, 0.95, 0.25>
    translate  -2.5*z
  }
  photons {
    collect off
  }
  translate  0.9*z
}
#declare podrr = difference {
  object { Eagle_CSG20po }
  object { Eagle_CSG21po }
  material {
    Eagle_basic2
    translate <0.602597, -0.120519, 0.000000>
  }
  photons {
    collect off
  }
  rotate 180.0*z
  translate  <-4.010064, -1.49874, -3.149625>
}
#declare Eagle_TraSwp8 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp7 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -90.0>
  translate  <-1.1, -1.4, -0.65>
}
#declare Eagle_TraSwp6 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <-1.1, -1.4, 0.65>
}
#declare Eagle_TraSwp9 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -0.0>
  translate  <1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp10 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 90.0, 0.0>
  translate  <1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp11 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -180.0>
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp12 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*y
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp13 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, -90.0, -0.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp002 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, 0.0, 45.0>
  translate  <0.984846, -1.302238, 1.293298>
}
#declare Eagle_TraSwp14 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, 135.0>
  translate  <1.002227, 1.284839, 1.293298>
}
#declare Eagle_TraSwp15 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -135.0>
  translate  <-0.984844, 1.302236, 1.293298>
}
#declare Eagle_TraSwp16 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.002236, -1.284844, 1.293298>
}
#declare Eagle_TraSwp17 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 45.0>
  translate  <1.158052, -1.475444, -1.466497>
}
#declare Eagle_TraSwp18 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 135.0>
  translate  <1.175444, 1.458052, -1.466497>
}
#declare Eagle_TraSwp19 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, -0.0, -135.0>
  translate  <-1.158052, 1.475444, -1.466497>
}
#declare Eagle_TraSwp20 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, -45.0>
  translate  <-1.175444, -1.458052, -1.466497>
}
#declare Eagle_TraSwp40 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, 135.0>
  translate  <1.065912, 1.348523, 1.292493>
}
#declare Eagle_TraSwp41 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -135.0>
  translate  <-1.038963, 1.356356, 1.30218>
}
#declare Eagle_TraSwp42 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.061085, -1.343693, 1.297021>
}
#declare Eagle_TraSwp43 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, 0.0, 45.0>
  translate  <1.036965, -1.354358, 1.29839>
}
#declare Eagle_pods = union {
  object { Eagle_TraSwp8 }
  object { Eagle_TraSwp7 }
  object { Eagle_TraSwp6 }
  object { Eagle_TraSwp9 }
  object { Eagle_TraSwp10 }
  object { Eagle_TraSwp11 }
  object { Eagle_TraSwp12 }
  box { // pod
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.1, 1.4, 1.6>
  }
  box { // pod1
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.05, 2.35, 0.65>
  }
  object { Eagle_TraSwp13 }
  object { Eagle_TraSwp002 }
  object { Eagle_TraSwp14 }
  object { Eagle_TraSwp15 }
  object { Eagle_TraSwp16 }
  object { Eagle_TraSwp17 }
  object { Eagle_TraSwp18 }
  object { Eagle_TraSwp19 }
  object { Eagle_TraSwp20 }
  object { Eagle_TraSwp40 }
  object { Eagle_TraSwp41 }
  object { Eagle_TraSwp42 }
  object { Eagle_TraSwp43 }
  box { // details1
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, -0.0, -0.0>
    translate  <0.507757, -2.343796, 0.0>
  }
  box { // details2
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, -0.0, -0.0>
    translate  <0.825724, -2.351459, -0.000387>
  }
  box { // details3
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.214134, 0.53431, 0.1>
    rotate <90.0, -0.0, -0.0>
    translate  <-0.801231, -2.339344, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_corners = union {
  box { // cutouttt3
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <-1.887544, 2.128141, 0.0>
  }
  box { // cutouttt2
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <1.868491, 2.147195, 0.0>
  }
  box { // cutouttt1
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <-1.875645, -2.14004, 0.0>
  }
  box { // cutouttt
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <1.835482, -2.180203, 0.0>
  }
  box { // details7
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.016129, 0.53431, 0.1>
    rotate 90.0*x
    translate  <-0.007032, 2.396445, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_podss = difference {
  object { Eagle_pods }
  object { Eagle_corners }
  photons {
    collect off
  }
}
#declare Eagle_CSG22 = union {
  cylinder { // Cylndr71
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale <0.06, 0.06, 0.1>
    rotate 45.0*y
    translate  <1.565881, 0.968648, 1.090452>
  }
  cylinder { // Cylndr72
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.565881, 1.140489, 1.086633>
  }
  cylinder { // Cylndr73
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.565881, 0.804445, 1.090452>
  }
  cylinder { // Cylndr74
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.43919, 0.968648, 1.21955>
  }
  cylinder { // Cylndr75
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate 45.0*y
    translate  <1.695589, 0.968648, 0.963151>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG23 = difference {
  cylinder { // Cylndr70
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    rotate 45.0*y
    translate  <1.55678, 0.968648, 1.084393>
  }
  object { Eagle_CSG22 }
  photons {
    collect off
  }
}
#declare Eagle_CSG24 = difference {
  box { // details8
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.638447, 0.474085, 0.101723>
    rotate 90.0*x
    translate  <-0.298564, 2.254878, 0.0>
  }
  cylinder { // Cylndr76
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.25, 0.25, 0.222895>
    rotate 90.0*x
    translate  <-0.595948, 2.474234, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG25 = difference {
  box { // Cube001
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, 45.0>
    translate  <1.538216, -1.894901, 0.0>
  }
  cylinder { // Cylndr77
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale 0.15
    rotate <90.0, 0.0, 45.0>
    translate  <1.557149, -1.903054, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_RotSwp4 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <90.0, -0.0, -0.0>
  translate  <2.299984, 0.654983, 0.000003>
}
#declare Eagle_RotSwp3 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <-90.0, -0.0, 0.0>
  translate  <2.300001, -0.655, 0.000014>
}
#declare Eagle_RotSwp2 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate 180.0*x
  translate  <2.299944, -0.0, 0.579997>
}
#declare Eagle_RotSwp001 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  translate  <2.29998, 0.000028, -0.579984>
}
#declare Eagle_lfEagle_podspheredet = lathe {
  linear_spline
  10  // control points
  <0.017094, -0.501425>,
  <1.790401, -0.5>,
  <1.790401, 0.5>,
  <1.643722, 0.49899>,
  <1.643669, 0.589571>,
  <1.549475, 0.589139>,
  <1.552686, 0.497756>,
  <1.412992, 0.496795>,
  <1.417809, -0.335185>,
  <0.002849, -0.339031>
  rotate <90,0,90>
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  scale 0.062782
  rotate <45.0, -0.0, -0.0>
  translate  <-0.453081, -2.010166, 1.245494>
}
#declare podetails = union {
  cylinder { // Cylndr68
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.222895>
    rotate 90.0*x
    translate  <-0.600895, 2.379453, 0.0>
  }
  box { // details9
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.049883, 0.251479, 0.101723>
    rotate 90.0*x
    translate  <0.830208, 2.249624, 0.0>
  }
  box { // details
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.375523, 0.53431, 0.1>
    rotate 90.0*x
    translate  <-0.094684, -2.335447, -0.0>
  }
  box { // Cube002
    <-1, -1, -1>, <1, 1, 1>
    material {
      thrusters
      scale <1.923967, 1.921337, 1.625962>
      translate <-0.913223, -0.914231, 0.250048>
    }
    photons {
      collect off
    }
    scale <0.65, 1.35, 0.1>
    rotate <-0.0, 90.0, 0.0>
    translate  2.0*x
  }
  box { // Cube2
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.397256, 2.076429, 0.007156>
  }
  box { // Cube3
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.765831, 1.700392, 0.007156>
  }
  box { // Cube4
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, -45.0>
    translate  <-1.576331, -1.879875, 0.0>
  }
  box { // Cube5
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.384006, 2.063083, 0.007156>
  }
  box { // Cube6
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.759809, 1.687423, 0.007156>
  }
  box { // Cube005
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.352468, 0.557803, 0.062537>
    rotate 45.0*y
    translate  <1.562522, -0.723164, 1.10487>
  }
  box { // Cube007
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.435367, 0.768652, 0.03654>
    rotate -45.0*y
    translate  <-1.566077, 0.0, 1.120275>
  }
  box { // Cube10
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.499572, 0.500782, 0.1>
    translate  <0.517691, 0.706973, 1.552503>
  }
  box { // Cube006
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.441879, 0.654631, 0.1>
    translate  <-0.541624, 0.555544, 1.552503>
  }
  cylinder { // Cylndr69
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <0.518265, -0.825361, 1.541025>
  }
  sphere { // Sphere14
    <0,0,0>,1
    photons {
      collect off
    }
    scale 0.22
    translate  <-0.555693, -0.614372, 1.582052>
  }
  object { Eagle_CSG23 }
  box { // Cube9
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <-0.091818, -0.472462, -0.048306>
    rotate <-135.0, 0.0, -180.0>
    translate  <-0.814766, 1.853404, 1.109259>
  }
  box { // Cube8
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <0.536169, 2.053322, 0.929678>
  }
  box { // Cube004
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <0.536169, 1.676239, 1.315065>
  }
  box { // Cube7
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.070355, 0.330477, 0.091429>
    rotate 45.0*x
    translate  <-0.915547, -1.864294, 1.077046>
  }
  sphere { // Sphere15
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale 0.22
    translate  <-0.446544, -1.88847, 1.09795>
  }
  box { // Cube003
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.560765, 0.286208, 0.04716>
    rotate 45.914688*x
    translate  <0.420039, -1.890972, 1.099474>
  }
  object { Eagle_CSG24 }
  object { Eagle_CSG25 }
  object { Eagle_RotSwp4 }
  object { Eagle_RotSwp3 }
  object { Eagle_RotSwp2 }
  object { Eagle_RotSwp001 }
  box { // Cube009
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.175, 0.325, 0.25>
    translate  2.27*x
  }
  box { // Cube12
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate 45.0*x
    translate  <0.0, 2.024267, -0.972516>
  }
  box { // Cube010
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate -45.0*x
    translate  <0.0, -2.013755, -0.972516>
  }
  box { // Cube169
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.28, 0.286208, 0.04716>
    rotate 45.914688*x
    translate  <0.701999, -1.599733, 1.352767>
  }
  box { // Cube212
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.070355, 0.248557, 0.091429>
    rotate -90.0*z
    translate  <-0.087962, -0.341703, 1.539467>
  }
  cylinder { // tinypoddetail1
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.047977, 0.050836, 0.225233>
    rotate <0.0, -90.0, 0.0>
    translate  <-0.140699, -1.891185, 1.127015>
  }
  object { Eagle_lfEagle_podspheredet }
  photons {
    collect off
  }
}
#declare Eagle_CSG007po = union {
  object { Eagle_podss }
  object { podetails }
  photons {
    collect off
  }
}
#declare Eagle_CSG005po = union {
  box { // Cube11
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.7, 2.0, 0.25>
    translate  -2.5*z
  }
  box { // Cube008
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.0, 0.95, 0.25>
    translate  -2.5*z
  }
  photons {
    collect off
  }
  translate  0.9*z
}
#declare podlf = difference {
  object { Eagle_CSG007po }
  object { Eagle_CSG005po }
  material {
    Eagle_basic2
    translate <0.627845, -0.000000, 0.000000>
  }
  photons {
    collect off
  }
  translate  <5.660183, -19.636663, -3.150299>
}
#declare Eagle_TraSwp44 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp45 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -90.0>
  translate  <-1.1, -1.4, -0.65>
}
#declare Eagle_TraSwp46 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <-1.1, -1.4, 0.65>
}
#declare Eagle_TraSwp47 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -0.0>
  translate  <1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp48 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 90.0, 0.0>
  translate  <1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp49 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -180.0>
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp50 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*y
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp51 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, -90.0, -0.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp52 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, 0.0, 45.0>
  translate  <0.984846, -1.302238, 1.293298>
}
#declare Eagle_TraSwp53 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, 135.0>
  translate  <1.002227, 1.284839, 1.293298>
}
#declare Eagle_TraSwp54 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -135.0>
  translate  <-0.984844, 1.302236, 1.293298>
}
#declare Eagle_TraSwp55 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.002236, -1.284844, 1.293298>
}
#declare Eagle_TraSwp56 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 45.0>
  translate  <1.158052, -1.475444, -1.466497>
}
#declare Eagle_TraSwp57 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 135.0>
  translate  <1.175444, 1.458052, -1.466497>
}
#declare Eagle_TraSwp58 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, -0.0, -135.0>
  translate  <-1.158052, 1.475444, -1.466497>
}
#declare Eagle_TraSwp59 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, -45.0>
  translate  <-1.175444, -1.458052, -1.466497>
}
#declare Eagle_TraSwp60 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, 135.0>
  translate  <1.065912, 1.348523, 1.292493>
}
#declare Eagle_TraSwp61 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -135.0>
  translate  <-1.038963, 1.356356, 1.30218>
}
#declare Eagle_TraSwp62 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.061085, -1.343693, 1.297021>
}
#declare Eagle_TraSwp63 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, 0.0, 45.0>
  translate  <1.036965, -1.354358, 1.29839>
}
#declare Eagle_pods2 = union {
  object { Eagle_TraSwp44 }
  object { Eagle_TraSwp45 }
  object { Eagle_TraSwp46 }
  object { Eagle_TraSwp47 }
  object { Eagle_TraSwp48 }
  object { Eagle_TraSwp49 }
  object { Eagle_TraSwp50 }
  box { // pod4
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.1, 1.4, 1.6>
  }
  box { // pod5
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.05, 2.35, 0.65>
  }
  object { Eagle_TraSwp51 }
  object { Eagle_TraSwp52 }
  object { Eagle_TraSwp53 }
  object { Eagle_TraSwp54 }
  object { Eagle_TraSwp55 }
  object { Eagle_TraSwp56 }
  object { Eagle_TraSwp57 }
  object { Eagle_TraSwp58 }
  object { Eagle_TraSwp59 }
  object { Eagle_TraSwp60 }
  object { Eagle_TraSwp61 }
  object { Eagle_TraSwp62 }
  object { Eagle_TraSwp63 }
  box { // details20
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <-0.507757, -2.300263, 0.0>
  }
  box { // details21
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <-0.813389, -2.305553, -0.000387>
  }
  box { // details22
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.214134, 0.53431, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <0.814534, -2.292582, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_corners2 = union {
  box { // cutouttt8
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <-1.887544, 2.128141, 0.0>
  }
  box { // cutouttt9
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <1.868491, 2.147195, 0.0>
  }
  box { // cutouttt10
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <-1.875645, -2.14004, 0.0>
  }
  box { // cutouttt11
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <1.835482, -2.180203, 0.0>
  }
  box { // details23
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.016129, 0.53431, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <-0.007032, 2.396445, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_podss2 = difference {
  object { Eagle_pods2 }
  object { Eagle_corners2 }
  photons {
    collect off
  }
}
#declare Eagle_CSG26 = union {
  cylinder { // Cylndr81
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale <0.06, 0.06, 0.1>
    rotate -45.0*y
    translate  <-1.565881, 0.968648, 1.090452>
  }
  cylinder { // Cylndr82
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.565881, 1.140489, 1.086633>
  }
  cylinder { // Cylndr83
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.565881, 0.804445, 1.090452>
  }
  cylinder { // Cylndr84
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.43919, 0.968648, 1.21955>
  }
  cylinder { // Cylndr85
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.695589, 0.968648, 0.963151>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG27 = difference {
  cylinder { // Cylndr80
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    rotate -45.0*y
    translate  <-1.55678, 0.968648, 1.084393>
  }
  object { Eagle_CSG26 }
  photons {
    collect off
  }
}
#declare Eagle_CSG28 = difference {
  box { // details29
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.638447, 0.474085, 0.101723>
    rotate 90.0*x
    translate  <0.298564, 2.254878, 0.0>
  }
  cylinder { // Cylndr86
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.25, 0.25, 0.222895>
    rotate 90.0*x
    translate  <0.595948, 2.474234, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG29 = difference {
  box { // Cube49
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, -45.0>
    translate  <-1.538216, -1.894901, 0.0>
  }
  cylinder { // Cylndr87
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale 0.15
    rotate <90.0, 0.0, -45.0>
    translate  <-1.557149, -1.903054, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_RotSwp9 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <90.0, -0.0, -0.0>
  translate  <-2.3, 0.654983, 0.000003>
}
#declare Eagle_RotSwp10 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <-90.0, -0.0, 0.0>
  translate  <-2.3, -0.655, 0.000014>
}
#declare Eagle_RotSwp11 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate 180.0*x
  translate  <-2.3, -0.0, 0.579997>
}
#declare Eagle_RotSwp12 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  translate  <-2.3, 0.000028, -0.579984>
}
#declare Eagle_lfEagle_podspheredet3 = lathe {
  linear_spline
  10  // control points
  <0.017094, -0.501425>,
  <1.790401, -0.5>,
  <1.790401, 0.5>,
  <1.643722, 0.49899>,
  <1.643669, 0.589571>,
  <1.549475, 0.589139>,
  <1.552686, 0.497756>,
  <1.412992, 0.496795>,
  <1.417809, -0.335185>,
  <0.002849, -0.339031>
  rotate <90,0,90>
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  scale 0.062782
  rotate <-45.0, 0.0, -180.0>
  translate  <0.446376, -2.01283, 1.245356>
}
#declare podetails2 = union {
  cylinder { // Cylndr78
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.222895>
    rotate 90.0*x
    translate  <0.600895, 2.379453, 0.0>
  }
  box { // details24
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.049883, 0.251479, 0.101723>
    rotate 90.0*x
    translate  <-0.830208, 2.249624, 0.0>
  }
  box { // details28
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.375523, 0.53431, 0.1>
    rotate 90.0*x
    translate  <0.094684, -2.297636, 0.0>
  }
  box { // Cube34
    <-1, -1, -1>, <1, 1, 1>
    material {
      thrusters
      scale <1.907602, 1.903546, 1.989>
      translate <-0.906910, -0.897914, 0.006775>
    }
    photons {
      collect off
    }
    scale <0.65, 1.35, 0.1>
    rotate <180.0, 90.0, 0.0>
    translate  -2.0*x
  }
  box { // Cube35
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.38197, 2.061143, 0.007156>
  }
  box { // Cube36
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.750545, 1.695297, 0.007156>
  }
  box { // Cube37
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, 45.0>
    translate  <1.576331, -1.879875, 0.0>
  }
  box { // Cube38
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.401187, 2.085991, 0.007156>
  }
  box { // Cube39
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.782718, 1.710331, 0.007156>
  }
  box { // Cube40
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.352468, 0.557803, 0.062537>
    rotate <180.0, 45.0, 180.0>
    translate  <-1.562522, -0.723164, 1.10487>
  }
  box { // Cube41
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.435367, 0.768652, 0.03654>
    rotate 45.0*y
    translate  <1.566077, 0.0, 1.120275>
  }
  box { // Cube42
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.499572, 0.500782, 0.1>
    translate  <-0.517691, 0.706973, 1.552503>
  }
  box { // Cube43
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.441879, 0.654631, 0.1>
    translate  <0.541624, 0.555544, 1.552503>
  }
  cylinder { // Cylndr79
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.518265, -0.825361, 1.541025>
  }
  sphere { // Sphere16
    <0,0,0>,1
    photons {
      collect off
    }
    scale 0.22
    translate  <0.555693, -0.614372, 1.582052>
  }
  object { Eagle_CSG27 }
  box { // Cube44
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <-0.091818, -0.472462, -0.048306>
    rotate <-135.0, 0.0, -180.0>
    translate  <0.814766, 1.853404, 1.109259>
  }
  box { // Cube45
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <-0.536169, 2.053322, 0.929678>
  }
  box { // Cube46
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <-0.536169, 1.676239, 1.315065>
  }
  box { // Cube47
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.070355, 0.330477, 0.091429>
    rotate 45.0*x
    translate  <0.915547, -1.879346, 1.08871>
  }
  sphere { // Sphere17
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale 0.22
    translate  <0.446544, -1.880446, 1.103062>
  }
  box { // Cube48
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.560765, 0.286208, 0.04716>
    rotate 45.0*x
    translate  <-0.420039, -1.895578, 1.108226>
  }
  object { Eagle_CSG28 }
  object { Eagle_CSG29 }
  object { Eagle_RotSwp9 }
  object { Eagle_RotSwp10 }
  object { Eagle_RotSwp11 }
  object { Eagle_RotSwp12 }
  box { // Cube50
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.175, 0.325, 0.25>
    rotate -180.0*z
    translate  -2.27*x
  }
  box { // Cube51
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate 45.0*x
    translate  <0.0, 2.024267, -0.972516>
  }
  box { // Cube52
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate -45.0*x
    translate  <0.0, -2.013755, -0.972516>
  }
  box { // Cube208
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.28, 0.286208, 0.04716>
    rotate 45.0*x
    translate  <-0.69634, -1.60639, 1.349331>
  }
  box { // Cube211
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.057837, 0.192785, 0.091429>
    rotate 90.0*z
    translate  <0.189536, -0.279911, 1.53391>
  }
  cylinder { // tinypoddetail2
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.047977, 0.050836, 0.225233>
    rotate <180.0, -90.0, 0.0>
    translate  <0.141282, -1.879588, 1.127592>
  }
  object { Eagle_lfEagle_podspheredet3 }
  photons {
    collect off
  }
}
#declare Eagle_CSG30po = union {
  object { Eagle_podss2 }
  object { podetails2 }
  photons {
    collect off
  }
}
#declare Eagle_CSG31po = union {
  box { // Cube53
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.7, 2.0, 0.25>
    translate  -2.5*z
  }
  box { // Cube54
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.0, 0.95, 0.25>
    translate  -2.5*z
  }
  photons {
    collect off
  }
  translate  0.9*z
}
#declare podlr = difference {
  object { Eagle_CSG30po }
  object { Eagle_CSG31po }
  material {
    Eagle_basic2
    translate <-2.169349, 0.241039, -0.000000>
  }
  photons {
    collect off
  }
  rotate -180.0*z
  translate  <5.660866, -1.498878, -3.150876>
}
#declare Eagle_TraSwp64 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp65 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -90.0>
  translate  <-1.1, -1.4, -0.65>
}
#declare Eagle_TraSwp66 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-180.0, -90.0, 0.0>
  translate  <-1.1, -1.4, 0.65>
}
#declare Eagle_TraSwp67 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, -0.0>
  translate  <1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp68 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 90.0, 0.0>
  translate  <1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp69 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-90.0, 0.0, -180.0>
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp70 = prism {
  linear_sweep
  linear_spline
  -2.2,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*y
  translate  <-1.1, 1.4, -0.65>
}
#declare Eagle_TraSwp71 = prism {
  linear_sweep
  linear_spline
  -2.8,0.0
  4  // control points
  <-0.0, -0.0>,
  <0.95, -0.0>,
  <-0.0, 0.95>,
  <-0.0, -0.0>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, -90.0, -0.0>
  translate  <-1.1, 1.4, 0.65>
}
#declare Eagle_TraSwp72 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, 0.0, 45.0>
  translate  <0.984846, -1.302238, 1.293298>
}
#declare Eagle_TraSwp73 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, 135.0>
  translate  <1.002227, 1.284839, 1.293298>
}
#declare Eagle_TraSwp74 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -135.0>
  translate  <-0.984844, 1.302236, 1.293298>
}
#declare Eagle_TraSwp75 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.002236, -1.284844, 1.293298>
}
#declare Eagle_TraSwp76 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 45.0>
  translate  <1.158052, -1.475444, -1.466497>
}
#declare Eagle_TraSwp77 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, 135.0>
  translate  <1.175444, 1.458052, -1.466497>
}
#declare Eagle_TraSwp78 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, -0.0, -135.0>
  translate  <-1.158052, 1.475444, -1.466497>
}
#declare Eagle_TraSwp79 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-54.736931, 0.0, -45.0>
  translate  <-1.175444, -1.458052, -1.466497>
}
#declare Eagle_TraSwp80 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, 135.0>
  translate  <1.065912, 1.348523, 1.292493>
}
#declare Eagle_TraSwp81 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -135.0>
  translate  <-1.038963, 1.356356, 1.30218>
}
#declare Eagle_TraSwp82 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, -0.0, -45.0>
  translate  <-1.061085, -1.343693, 1.297021>
}
#declare Eagle_TraSwp83 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  4  // control points
  <-0.659742, -0.999999>,
  <0.68402, -0.999996>,
  <0.012298, 0.163504>,
  <-0.659742, -0.999999>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.88
  rotate <54.736931, 0.0, 45.0>
  translate  <1.036965, -1.354358, 1.29839>
}
#declare Eagle_pods3 = union {
  object { Eagle_TraSwp64 }
  object { Eagle_TraSwp65 }
  object { Eagle_TraSwp66 }
  object { Eagle_TraSwp67 }
  object { Eagle_TraSwp68 }
  object { Eagle_TraSwp69 }
  object { Eagle_TraSwp70 }
  box { // pod6
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.1, 1.4, 1.6>
  }
  box { // pod7
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.05, 2.35, 0.65>
  }
  object { Eagle_TraSwp71 }
  object { Eagle_TraSwp72 }
  object { Eagle_TraSwp73 }
  object { Eagle_TraSwp74 }
  object { Eagle_TraSwp75 }
  object { Eagle_TraSwp76 }
  object { Eagle_TraSwp77 }
  object { Eagle_TraSwp78 }
  object { Eagle_TraSwp79 }
  object { Eagle_TraSwp80 }
  object { Eagle_TraSwp81 }
  object { Eagle_TraSwp82 }
  object { Eagle_TraSwp83 }
  box { // details30
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <-0.4971, -2.330342, -0.0>
  }
  box { // details31
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.112586, 0.534145, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <-0.818589, -2.338637, -0.000387>
  }
  box { // details32
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.214134, 0.53431, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <0.801371, -2.32612, -0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_corners3 = union {
  box { // cutouttt12
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <-1.887544, 2.128141, 0.0>
  }
  box { // cutouttt13
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <1.868491, 2.147195, 0.0>
  }
  box { // cutouttt14
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate -45.0*z
    translate  <-1.875645, -2.14004, 0.0>
  }
  box { // cutouttt15
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.8, 0.4, 0.651>
    rotate 45.0*z
    translate  <1.835482, -2.180203, 0.0>
  }
  box { // details33
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.016129, 0.53431, 0.1>
    rotate <90.0, -0.0, 0.0>
    translate  <-0.007032, 2.396445, -0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_podss3 = difference {
  object { Eagle_pods3 }
  object { Eagle_corners3 }
  photons {
    collect off
  }
}
#declare Eagle_CSG32 = union {
  cylinder { // Cylndr91
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale <0.06, 0.06, 0.1>
    rotate -45.0*y
    translate  <-1.565881, 0.968648, 1.090452>
  }
  cylinder { // Cylndr92
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.565881, 1.140489, 1.086633>
  }
  cylinder { // Cylndr93
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.565881, 0.804445, 1.090452>
  }
  cylinder { // Cylndr94
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.43919, 0.968648, 1.21955>
  }
  cylinder { // Cylndr95
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.1>
    rotate -45.0*y
    translate  <-1.695589, 0.968648, 0.963151>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG33 = difference {
  cylinder { // Cylndr90
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    rotate -45.0*y
    translate  <-1.55678, 0.968648, 1.084393>
  }
  object { Eagle_CSG32 }
  photons {
    collect off
  }
}
#declare Eagle_CSG34 = difference {
  box { // details39
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.638447, 0.474085, 0.101723>
    rotate 90.0*x
    translate  <0.298564, 2.254878, 0.0>
  }
  cylinder { // Cylndr96
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.25, 0.25, 0.222895>
    rotate 90.0*x
    translate  <0.595948, 2.474234, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_CSG35 = difference {
  box { // Cube70
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, -45.0>
    translate  <-1.538216, -1.894901, 0.0>
  }
  cylinder { // Cylndr97
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale 0.15
    rotate <90.0, 0.0, -45.0>
    translate  <-1.557149, -1.903054, 0.0>
  }
  photons {
    collect off
  }
}
#declare Eagle_RotSwp13 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <90.0, -0.0, -0.0>
  translate  <-2.3, 0.654983, 0.000003>
}
#declare Eagle_RotSwp14 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate <-90.0, -0.0, 0.0>
  translate  <-2.3, -0.655, 0.000014>
}
#declare Eagle_RotSwp15 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  rotate 180.0*x
  translate  <-2.3, -0.0, 0.579997>
}
#declare Eagle_RotSwp16 = lathe {
  linear_spline
  16  // control points
  <-0.000007, 0.315569>,
  <0.040896, 0.31451>,
  <0.063942, 0.236563>,
  <0.073979, 0.187878>,
  <0.085298, 0.128834>,
  <0.099753, 0.054152>,
  <0.108173, 0.000674>,
  <0.125, -0.0>,
  <0.121546, 0.037434>,
  <0.115846, 0.074869>,
  <0.106155, 0.12832>,
  <0.091816, 0.191153>,
  <0.079722, 0.24291>,
  <0.063135, 0.294667>,
  <0.05, 0.33>,
  <0.000001, 0.329999>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  translate  <-2.3, 0.000028, -0.579984>
}
#declare Eagle_lfEagle_podspheredet1 = lathe {
  linear_spline
  10  // control points
  <0.017094, -0.501425>,
  <1.790401, -0.5>,
  <1.790401, 0.5>,
  <1.643722, 0.49899>,
  <1.643669, 0.589571>,
  <1.549475, 0.589139>,
  <1.552686, 0.497756>,
  <1.412992, 0.496795>,
  <1.417809, -0.335185>,
  <0.002849, -0.339031>
  rotate <90,0,90>
  material {
    Eagle_darkgrey
  }
  photons {
    collect off
  }
  scale 0.062782
  rotate <45.0, -0.0, 0.0>
  translate  <0.444122, -2.009279, 1.245524>
}
#declare podetails3 = union {
  cylinder { // Cylndr88
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.222895>
    rotate 90.0*x
    translate  <0.600895, 2.379453, 0.0>
  }
  box { // details34
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.049883, 0.251479, 0.101723>
    rotate 90.0*x
    translate  <-0.830208, 2.249624, 0.0>
  }
  box { // details38
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.375523, 0.53431, 0.1>
    rotate 90.0*x
    translate  <0.091071, -2.332806, -0.0>
  }
  box { // Cube55
    <-1, -1, -1>, <1, 1, 1>
    material {
      thrusters
      scale <1.926316, 1.941905, 2.009736>
      translate <-0.926316, -0.932483, 0.010202>
    }
    photons {
      collect off
    }
    scale <0.65, 1.35, 0.1>
    rotate <180.0, 90.0, 0.0>
    translate  -2.0*x
  }
  box { // Cube56
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.38197, 2.061143, 0.007156>
  }
  box { // Cube57
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, -45.0>
    translate  <1.750545, 1.695297, 0.007156>
  }
  box { // Cube58
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.51345, 0.577313, 0.083041>
    rotate <90.0, 0.0, 45.0>
    translate  <1.576331, -1.879875, 0.0>
  }
  box { // Cube59
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.404318, 2.09863, 0.007156>
  }
  box { // Cube60
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.246679, 0.577313, 0.047684>
    rotate <90.0, 0.0, 45.0>
    translate  <-1.7852, 1.702657, 0.007156>
  }
  box { // Cube61
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.352468, 0.557803, 0.062537>
    rotate <180.0, 45.0, 180.0>
    translate  <-1.562522, -0.723164, 1.10487>
  }
  box { // Cube62
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.435367, 0.768652, 0.03654>
    rotate 45.0*y
    translate  <1.566077, 0.0, 1.120275>
  }
  box { // Cube63
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.499572, 0.500782, 0.1>
    translate  <-0.517691, 0.706973, 1.552503>
  }
  box { // Cube64
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.441879, 0.654631, 0.1>
    translate  <0.541624, 0.555544, 1.552503>
  }
  cylinder { // Cylndr89
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.3, 0.3, 0.1>
    translate  <-0.518265, -0.825361, 1.541025>
  }
  sphere { // Sphere18
    <0,0,0>,1
    photons {
      collect off
    }
    scale 0.22
    translate  <0.555693, -0.614372, 1.582052>
  }
  object { Eagle_CSG33 }
  box { // Cube65
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <-0.091818, -0.472462, -0.048306>
    rotate <-135.0, 0.0, -180.0>
    translate  <0.814766, 1.853404, 1.109259>
  }
  box { // Cube66
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <-0.536169, 2.053322, 0.929678>
  }
  box { // Cube67
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.481778, 0.194696, 0.057631>
    rotate -45.0*x
    translate  <-0.536169, 1.676239, 1.315065>
  }
  box { // Cube68
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.070355, 0.330477, 0.091429>
    rotate 45.0*x
    translate  <0.915547, -1.856678, 1.076675>
  }
  sphere { // Sphere19
    <0,0,0>,1
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale 0.22
    translate  <0.446544, -1.88847, 1.09795>
  }
  box { // Cube69
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.560765, 0.286208, 0.04716>
    rotate 45.0*x
    translate  <-0.420039, -1.88786, 1.103747>
  }
  object { Eagle_CSG34 }
  object { Eagle_CSG35 }
  object { Eagle_RotSwp13 }
  object { Eagle_RotSwp14 }
  object { Eagle_RotSwp15 }
  object { Eagle_RotSwp16 }
  box { // Cube71
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.175, 0.325, 0.25>
    rotate -180.0*z
    translate  -2.27*x
  }
  box { // Cube72
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate 45.0*x
    translate  <0.0, 2.024267, -0.972516>
  }
  box { // Cube73
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.840866, 0.331584, 0.044288>
    rotate -45.0*x
    translate  <0.0, -2.013755, -0.972516>
  }
  box { // Cube168
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_lightgrey
    }
    photons {
      collect off
    }
    scale <0.28, 0.286208, 0.04716>
    rotate 45.0*x
    translate  <-0.701265, -1.602642, 1.354778>
  }
  box { // Cube213
    <-1, -1, -1>, <1, 1, 1>
    material {
      yellow1
    }
    photons {
      collect off
    }
    scale <0.06991, 0.196729, 0.091506>
    rotate -90.0*z
    translate  <0.132168, -0.34247, 1.539315>
  }
  cylinder { // tinypoddetail
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_darkgrey
    }
    photons {
      collect off
    }
    scale <0.047977, 0.050836, 0.225233>
    rotate <0.0, -90.0, 0.0>
    translate  <0.367541, -1.891935, 1.127045>
  }
  object { Eagle_lfEagle_podspheredet1 }
  photons {
    collect off
  }
}
#declare Eagle_CSG36po = union {
  object { Eagle_podss3 }
  object { podetails3 }
  photons {
    collect off
  }
}
#declare Eagle_CSG37po = union {
  box { // Cube74
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.7, 2.0, 0.25>
    translate  -2.5*z
  }
  box { // Cube75
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <2.0, 0.95, 0.25>
    translate  -2.5*z
  }
  photons {
    collect off
  }
  translate  0.9*z
}
#declare podrf = difference {
  object { Eagle_CSG36po }
  object { Eagle_CSG37po }
  material {
    Eagle_basic2
    translate <-2.410388, -0.000000, -0.000000>
  }
  photons {
    collect off
  }
  translate  <-4.01279, -19.636592, -3.150329>
}
#declare Eagle_crostruts = union {
  cylinder { // crosstruts9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -21.0*y
  }
  cylinder { // crosstruts8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -18.45*y
  }
  cylinder { // crosstruts7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -15.95*y
  }
  cylinder { // crosstruts6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -13.45*y
  }
  cylinder { // crosstruts5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -11.0*y
  }
  cylinder { // crosstruts4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -10.1*y
  }
  cylinder { // crosstruts3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -7.65*y
  }
  cylinder { // crosstruts2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -5.1*y
  }
  cylinder { // crosstruts1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -2.6*y
  }
  cylinder { // crosstruts
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate 90.0*y
    translate  -0.1*y
  }
  cylinder { // crosstruts10
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, 1.6, -0.85>
  }
  cylinder { // crosstruts11
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -22.7, -0.85>
  }
  cylinder { // crosstruts12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -0.1, -0.85>
  }
  cylinder { // crosstruts13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -2.6, -0.85>
  }
  cylinder { // crosstruts14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -5.1, -0.85>
  }
  cylinder { // crosstruts15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -7.65, -0.85>
  }
  cylinder { // crosstruts16
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -10.1, -0.85>
  }
  cylinder { // crosstruts17
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -11.0, -0.85>
  }
  cylinder { // crosstruts18
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -13.45, -0.85>
  }
  cylinder { // crosstruts19
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -15.95, -0.85>
  }
  cylinder { // crosstruts20
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -18.45, -0.85>
  }
  cylinder { // crosstruts21
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 3.1>
    rotate 90.0*y
    translate  <-0.75, -21.0, -0.85>
  }
  photons {
    collect off
  }
}
#declare rstrut1 = union {
  cylinder { // struts22
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.05>
    rotate <-119.766022, -38.124104, 177.537262>
    translate  -21.0*y
  }
  cylinder { // struts23
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate <124.371849, -38.504139, -176.945923>
    translate  <-0.07056, -20.984249, -0.071674>
  }
  cylinder { // struts24
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate <-122.047699, -38.342361, 176.770889>
    translate  <-0.09757, -18.498932, -0.114418>
  }
  cylinder { // struts25
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <108.591263, -37.869995, -178.443924>
    translate  <-0.10216, -18.456514, -0.121799>
  }
  cylinder { // struts26
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-108.893959, -37.741322, 177.834274>
    translate  <-0.083996, -13.433055, -0.101889>
  }
  cylinder { // struts27
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.55>
    rotate <107.798943, -37.981747, -177.990356>
    translate  <-0.088348, -13.419605, -0.102706>
  }
  cylinder { // struts28
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-108.893959, -37.741322, 177.834274>
    translate  <-0.051769, -7.661753, -0.07719>
  }
  cylinder { // struts29
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <107.798943, -37.981747, -177.990356>
    translate  <-0.051517, -7.641001, -0.076773>
  }
  cylinder { // struts30
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.75>
    rotate <-107.591682, -37.09742, 177.985382>
    translate  <-0.087453, -2.563354, -0.10202>
  }
  cylinder { // struts31
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate <-126.186691, -38.721985, 176.858154>
    translate  <-0.019305, -0.085332, -0.028989>
  }
  cylinder { // struts32
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate <124.371849, -38.504139, -176.945923>
    translate  <-0.024522, -2.623154, -0.033135>
  }
  cylinder { // struts33
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -0.1*y
  }
  cylinder { // struts34
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -21.0*y
  }
  cylinder { // struts35
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -18.45*y
  }
  cylinder { // struts36
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -15.95*y
  }
  cylinder { // struts37
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -13.45*y
  }
  cylinder { // struts38
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -11.0*y
  }
  cylinder { // struts39
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -10.1*y
  }
  cylinder { // struts40
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -7.65*y
  }
  cylinder { // struts41
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -5.1*y
  }
  cylinder { // struts42
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -2.6*y
  }
  cylinder { // struts43
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.05>
    rotate <120.746048, -40.193592, -178.868561>
    translate  -0.1*y
  }
  cylinder { // supports22
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -22.15, -0.85>
  }
  cylinder { // supports23
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -20.7, -0.85>
  }
  cylinder { // supports24
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -19.4, -0.85>
  }
  cylinder { // supports25
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -18.15, -0.85>
  }
  cylinder { // supports26
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  <-0.75, -15.3, -0.85>
  }
  cylinder { // supports27
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -13.15, -0.85>
  }
  cylinder { // supports28
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.95>
    rotate 90.0*x
    translate  <-0.75, -9.6, -0.85>
  }
  cylinder { // supports29
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -7.35, -0.85>
  }
  cylinder { // supports30
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  <-0.75, -4.5, -0.85>
  }
  cylinder { // supports31
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -2.3, -0.85>
  }
  cylinder { // supports32
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -1.0, -0.85>
  }
  cylinder { // supports33
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, 0.2, -0.85>
  }
  cylinder { // supports34
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, 1.7, -0.85>
  }
  cylinder { // supports35
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  -20.45*y
  }
  cylinder { // supports36
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -17.8*y
  }
  cylinder { // supports37
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  -15.6*y
  }
  cylinder { // supports38
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -12.8*y
  }
  cylinder { // supports39
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -9.9*y
  }
  cylinder { // supports40
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -7.0*y
  }
  cylinder { // supports41
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  -4.8*y
  }
  cylinder { // supports42
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -1.95*y
  }
  cylinder { // supports43
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
  }
  cylinder { // topframe2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 24.5>
    rotate 90.0*x
    translate  <-0.75, 1.7, -0.85>
  }
  cylinder { // topframe3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 21.1>
    rotate 90.0*x
  }
  photons {
    collect off
  }
  rotate -82.753006*y
  translate  1.65*x
}
#declare rstrut = union {
  cylinder { // struts21
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.05>
    rotate <-119.766022, -38.124104, 177.537262>
    translate  -21.0*y
  }
  cylinder { // struts20
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate <124.371849, -38.504139, -176.945923>
    translate  <-0.07056, -20.984249, -0.071674>
  }
  cylinder { // struts19
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.6>
    rotate <-122.047699, -38.342361, 176.770889>
    translate  <-0.09757, -18.498932, -0.114418>
  }
  cylinder { // struts18
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <108.591263, -37.869995, -178.443924>
    translate  <-0.10216, -18.456514, -0.121799>
  }
  cylinder { // struts17
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <-108.893959, -37.741322, 177.834274>
    translate  <-0.083996, -13.433055, -0.101889>
  }
  cylinder { // struts16
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.55>
    rotate <107.798943, -37.981747, -177.990356>
    translate  <-0.088348, -13.419605, -0.102706>
  }
  cylinder { // struts15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.6>
    rotate <-108.893959, -37.741322, 177.834274>
    translate  <-0.051769, -7.661753, -0.07719>
  }
  cylinder { // struts14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.7>
    rotate <107.798943, -37.981747, -177.990356>
    translate  <-0.051517, -7.641001, -0.076773>
  }
  cylinder { // struts13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.75>
    rotate <-107.591682, -37.09742, 177.985382>
    translate  <-0.087453, -2.563354, -0.10202>
  }
  cylinder { // struts12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate <-126.186691, -38.721985, 176.858154>
    translate  <-0.019305, -0.085332, -0.028989>
  }
  cylinder { // struts11
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.7>
    rotate <124.371849, -38.504139, -176.945923>
    translate  <-0.024522, -2.623154, -0.033135>
  }
  cylinder { // struts10
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -0.1*y
  }
  cylinder { // struts9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -21.0*y
  }
  cylinder { // struts8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -18.45*y
  }
  cylinder { // struts7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -15.95*y
  }
  cylinder { // struts6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -13.45*y
  }
  cylinder { // struts5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -11.0*y
  }
  cylinder { // struts4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -10.1*y
  }
  cylinder { // struts3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -7.65*y
  }
  cylinder { // struts2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -5.1*y
  }
  cylinder { // struts1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 1.15>
    rotate <-180.0, -41.509865, -180.0>
    translate  -2.6*y
  }
  cylinder { // struts
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.05>
    rotate <120.746048, -40.193592, -178.868561>
    translate  -0.1*y
  }
  cylinder { // supports21
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -22.15, -0.85>
  }
  cylinder { // supports20
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -20.7, -0.85>
  }
  cylinder { // supports19
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -19.4, -0.85>
  }
  cylinder { // supports18
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -18.15, -0.85>
  }
  cylinder { // supports17
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  <-0.75, -15.3, -0.85>
  }
  cylinder { // supports16
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -13.15, -0.85>
  }
  cylinder { // supports15
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.95>
    rotate 90.0*x
    translate  <-0.75, -9.6, -0.85>
  }
  cylinder { // supports14
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -7.35, -0.85>
  }
  cylinder { // supports13
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  <-0.75, -4.5, -0.85>
  }
  cylinder { // supports12
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -2.3, -0.85>
  }
  cylinder { // supports11
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, -1.0, -0.85>
  }
  cylinder { // supports10
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, 0.2, -0.85>
  }
  cylinder { // supports9
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  <-0.75, 1.7, -0.85>
  }
  cylinder { // supports8
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  -20.45*y
  }
  cylinder { // supports7
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -17.8*y
  }
  cylinder { // supports6
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  -15.6*y
  }
  cylinder { // supports5
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -12.8*y
  }
  cylinder { // supports4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -9.9*y
  }
  cylinder { // supports3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -7.0*y
  }
  cylinder { // supports2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
    translate  -4.8*y
  }
  cylinder { // supports1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 1.3>
    rotate 90.0*x
    translate  -1.95*y
  }
  cylinder { // supports
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.15, 0.15, 0.65>
    rotate 90.0*x
  }
  cylinder { // topframe1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 24.5>
    rotate 90.0*x
    translate  <-0.75, 1.7, -0.85>
  }
  cylinder { // topframe
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 21.1>
    rotate 90.0*x
  }
  photons {
    collect off
  }
}
#declare Eagle_overframe = union {
  object { Eagle_crostruts }
  object { rstrut1 }
  object { rstrut }
  photons {
    collect off
  }
}
#declare Eagle_ovframeplugs = union {
  cylinder { // ovframeplug
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.058894, 0.058894, 0.100206>
    rotate 90.0*x
    translate  <-0.7459, -22.83524, -0.846873>
  }
  cylinder { // ovframeplug1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.058894, 0.058894, 0.100206>
    rotate 90.0*x
    translate  <2.398117, -22.83491, -0.84703>
  }
  photons {
    collect off
  }
  translate  0.127579*y
}
#declare Eagle_overframeassembly = difference {
  object { Eagle_overframe }
  object { Eagle_ovframeplugs }
  photons {
    collect off
  }
  translate  0.115587*y
}
#declare Eagle_capsulemain = lathe {
  linear_spline
  19  // control points
  <-0.0, 0.0>,
  <1.25, 0.0>,
  <1.498743, 0.3375>,
  <1.7, 0.75>,
  <1.832884, 1.1375>,
  <1.927071, 1.525>,
  <1.992559, 1.9125>,
  <2.0, 2.3>,
  <1.901036, 2.913757>,
  <1.75, 3.5>,
  <1.615016, 3.909571>,
  <1.458, 4.319142>,
  <1.221122, 4.83>,
  <1.010828, 5.245793>,
  <0.722929, 5.715607>,
  <0.430962, 6.07895>,
  <0.286654, 6.240287>,
  <0.128047, 6.393641>,
  <0.0, 6.45>
  rotate <90,0,90>
  photons {
    collect off
  }
  scale <1.5925, 0.98, 0.98>
  rotate 90.0*x
  translate  <0.0, -0.046009, 0.000039>
}
#declare Eagle_capsulesecondary = lathe {
  cubic_spline
  20  // control points
  <-0.0, 0.0>,
  <1.10439, -0.056004>,
  <1.498743, 0.3375>,
  <1.7, 0.75>,
  <1.832884, 1.1375>,
  <1.927071, 1.525>,
  <1.992559, 1.9125>,
  <2.0, 2.3>,
  <1.901036, 2.913757>,
  <1.75, 3.5>,
  <1.615016, 3.909571>,
  <1.458, 4.319142>,
  <1.221122, 4.83>,
  <1.010828, 5.245793>,
  <0.722929, 5.715607>,
  <0.430962, 6.07895>,
  <0.286654, 6.240287>,
  <0.128047, 6.393641>,
  <0.000119, 6.453832>,
  <0.0, 6.45>
  rotate <90,0,90>
  photons {
    collect off
  }
  scale <1.625, 1.0, 1.0>
  rotate 90.0*x
}
#declare Eagle_TraSwp92ca = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  53  // control points
  <-1.119255, -0.338822>,
  <-1.090991, -0.348369>,
  <-0.572563, -0.352328>,
  <-0.549011, -0.364591>,
  <-0.544199, -0.398565>,
  <-0.560814, -0.551431>,
  <-0.552873, -0.586375>,
  <-0.532734, -0.597486>,
  <-0.436698, -0.646075>,
  <-0.257115, -0.678223>,
  <0.000795, -0.688669>,
  <0.251792, -0.68332>,
  <0.426285, -0.644644>,
  <0.552434, -0.591802>,
  <0.574887, -0.580685>,
  <0.581476, -0.545741>,
  <0.565005, -0.401259>,
  <0.57303, -0.364463>,
  <0.593153, -0.355114>,
  <1.077609, -0.348369>,
  <1.106928, -0.333888>,
  <1.135285, -0.27697>,
  <1.165354, -0.153236>,
  <1.174435, -0.003268>,
  <1.162067, 0.155139>,
  <1.133345, 0.273058>,
  <1.118554, 0.322309>,
  <1.08925, 0.342549>,
  <0.577356, 0.36254>,
  <0.555597, 0.371905>,
  <0.54913, 0.405862>,
  <0.568467, 0.571409>,
  <0.562078, 0.606585>,
  <0.540309, 0.617664>,
  <0.43197, 0.66513>,
  <0.268635, 0.688332>,
  <0.001047, 0.700512>,
  <-0.218846, 0.686997>,
  <-0.428333, 0.655987>,
  <-0.529699, 0.622001>,
  <-0.54826, 0.608707>,
  <-0.557858, 0.576799>,
  <-0.545717, 0.410976>,
  <-0.552179, 0.370827>,
  <-0.57401, 0.352328>,
  <-1.089094, 0.348369>,
  <-1.12283, 0.332586>,
  <-1.145845, 0.263851>,
  <-1.167156, 0.175644>,
  <-1.18125, 0.004334>,
  <-1.166829, -0.180613>,
  <-1.14382, -0.297113>,
  <-1.119255, -0.338822>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.0, -5.454104, 0.000316>
}
#declare Eagle_TraSwp003ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.391739, -0.305544>,
  <-0.366965, -0.323163>,
  <-0.33706, -0.331681>,
  <0.391277, -0.338571>,
  <0.423324, -0.33241>,
  <0.448475, -0.31697>,
  <0.458034, -0.284716>,
  <0.46317, -0.245293>,
  <0.462749, 0.276066>,
  <0.458181, 0.311011>,
  <0.448324, 0.335837>,
  <0.42647, 0.34844>,
  <0.39788, 0.352372>,
  <-0.330957, 0.341406>,
  <-0.358859, 0.339095>,
  <-0.383232, 0.330329>,
  <-0.396157, 0.307717>,
  <-0.403073, 0.274097>,
  <-0.403073, -0.232275>,
  <-0.401763, -0.268941>,
  <-0.391739, -0.305544>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 47.464909>
  translate  <1.483597, -5.219625, 0.0>
}
#declare Eagle_TraSwp93ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.68487, -0.35427>,
  <-0.641287, -0.374379>,
  <-0.588678, -0.384101>,
  <0.61998, -0.45919>,
  <0.676648, -0.450962>,
  <0.721121, -0.430338>,
  <0.738025, -0.387256>,
  <0.747107, -0.3346>,
  <0.746362, 0.361782>,
  <0.738285, 0.408458>,
  <0.720854, 0.441619>,
  <0.682211, 0.458453>,
  <0.631656, 0.463704>,
  <-0.577943, 0.384101>,
  <-0.627028, 0.381463>,
  <-0.669904, 0.371459>,
  <-0.692642, 0.345651>,
  <-0.704808, 0.307281>,
  <-0.704808, -0.270648>,
  <-0.702504, -0.312495>,
  <-0.68487, -0.35427>
  rotate -x*90
  material {
    Eagle_basic
    scale <1.443767, 0.912626, 0.695768>
    translate <-0.664705, -0.450665, 0.217810>
  }
  photons {
    collect off
  }
  rotate <90.0, 0.0, 55.56678>
  translate  <2.224764, -4.203877, 0.0>
}
#declare Eagle_TraSwp94ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.389308, -0.292507>,
  <-0.364533, -0.309497>,
  <-0.334629, -0.31771>,
  <0.395455, -0.330613>,
  <0.427845, -0.324597>,
  <0.453264, -0.30952>,
  <0.462925, -0.278024>,
  <0.468116, -0.239528>,
  <0.46769, 0.269578>,
  <0.463074, 0.303702>,
  <0.453111, 0.327944>,
  <0.431024, 0.340251>,
  <0.402129, 0.34409>,
  <-0.328526, 0.331332>,
  <-0.356428, 0.329103>,
  <-0.3808, 0.320651>,
  <-0.393726, 0.298846>,
  <-0.400641, 0.266428>,
  <-0.400641, -0.221856>,
  <-0.399332, -0.257212>,
  <-0.389308, -0.292507>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, -0.0, 132.096588>
  translate  <-1.633836, -5.355555, 0.0>
}
#declare Eagle_TraSwp95ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.68487, -0.35427>,
  <-0.641287, -0.374379>,
  <-0.588678, -0.384101>,
  <0.61998, -0.45919>,
  <0.676648, -0.450962>,
  <0.721121, -0.430338>,
  <0.738025, -0.387256>,
  <0.747107, -0.3346>,
  <0.746362, 0.361782>,
  <0.738285, 0.408458>,
  <0.720854, 0.441619>,
  <0.682211, 0.458453>,
  <0.631656, 0.463704>,
  <-0.577943, 0.384101>,
  <-0.627028, 0.381463>,
  <-0.669904, 0.371459>,
  <-0.692642, 0.345651>,
  <-0.704808, 0.307281>,
  <-0.704808, -0.270648>,
  <-0.702504, -0.312495>,
  <-0.68487, -0.35427>
  rotate -x*90
  material {
    Eagle_basic
    scale <1.45617, 0.912626, 1.318633>
    translate <-0.663585, -0.450665, -0.029719>
  }
  photons {
    collect off
  }
  rotate <90.0, -0.0, 124.934128>
  translate  <-2.443847, -4.31581, 0.0>
}
#declare Eagle_TraSwp96ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.561112, -0.345864>,
  <-0.524973, -0.364928>,
  <-0.48135, -0.374144>,
  <0.481036, -0.374089>,
  <0.52843, -0.367655>,
  <0.565625, -0.351528>,
  <0.579762, -0.326518>,
  <0.587358, -0.291351>,
  <0.614515, 0.303791>,
  <0.607398, 0.340291>,
  <0.592038, 0.366221>,
  <0.557986, 0.379385>,
  <0.513438, 0.383491>,
  <-0.501783, 0.381965>,
  <-0.544667, 0.379464>,
  <-0.582126, 0.36998>,
  <-0.601992, 0.345514>,
  <-0.612621, 0.309138>,
  <-0.58169, -0.287078>,
  <-0.574292, -0.322819>,
  <-0.561112, -0.345864>
  rotate -x*90
  photons {
    collect off
  }
  rotate <30.616938, 0.0, 0.0>
  translate  <-0.005519, -5.286944, 0.856736>
}
#declare Eagle_TraSwp97ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.613803, -0.71705>,
  <-0.57427, -0.756572>,
  <-0.52655, -0.775679>,
  <0.526207, -0.775566>,
  <0.578052, -0.762225>,
  <0.618739, -0.728791>,
  <0.634204, -0.67694>,
  <0.642513, -0.604031>,
  <0.667605, 0.437098>,
  <0.659819, 0.512769>,
  <0.643017, 0.566529>,
  <0.605767, 0.59382>,
  <0.557036, 0.602333>,
  <-0.553518, 0.599168>,
  <-0.60043, 0.593984>,
  <-0.641406, 0.574321>,
  <-0.663137, 0.523598>,
  <-0.674764, 0.448183>,
  <-0.636313, -0.595173>,
  <-0.628221, -0.669271>,
  <-0.613803, -0.71705>
  rotate -x*90
  photons {
    collect off
  }
  rotate <23.741093, 0.0, 0.0>
  translate  <-0.005519, -4.127703, 1.348001>
}
#declare Eagle_TraSwp98ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.561112, -0.345864>,
  <-0.524973, -0.364928>,
  <-0.48135, -0.374144>,
  <0.481036, -0.374089>,
  <0.52843, -0.367655>,
  <0.565625, -0.351528>,
  <0.579762, -0.326518>,
  <0.587358, -0.291351>,
  <0.614515, 0.303791>,
  <0.607398, 0.340291>,
  <0.592038, 0.366221>,
  <0.557986, 0.379385>,
  <0.513438, 0.383491>,
  <-0.501783, 0.381965>,
  <-0.544667, 0.379464>,
  <-0.582126, 0.36998>,
  <-0.601992, 0.345514>,
  <-0.612621, 0.309138>,
  <-0.58169, -0.287078>,
  <-0.574292, -0.322819>,
  <-0.561112, -0.345864>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-29.953863, 0.0, -0.0>
  translate  <-0.01183, -5.395643, -1.01804>
}
#declare Eagle_TraSwp99ca = prism {
  linear_sweep
  linear_spline
  -0.2,0.0
  21  // control points
  <-0.613803, -0.71705>,
  <-0.57427, -0.756572>,
  <-0.52655, -0.775679>,
  <0.526207, -0.775566>,
  <0.578052, -0.762225>,
  <0.618739, -0.728791>,
  <0.634204, -0.67694>,
  <0.642513, -0.604031>,
  <0.667605, 0.437098>,
  <0.659819, 0.512769>,
  <0.643017, 0.566529>,
  <0.605767, 0.59382>,
  <0.557036, 0.602333>,
  <-0.553518, 0.599168>,
  <-0.60043, 0.593984>,
  <-0.641406, 0.574321>,
  <-0.663137, 0.523598>,
  <-0.674764, 0.448183>,
  <-0.636313, -0.595173>,
  <-0.628221, -0.669271>,
  <-0.613803, -0.71705>
  rotate -x*90
  photons {
    collect off
  }
  rotate <-22.182617, 0.0, -0.0>
  translate  <-0.005519, -4.211843, -1.541566>
}
#declare Eagle_TraSwp100ca = prism {
  linear_sweep
  linear_spline
  -7.0,0.0
  45  // control points
  <-0.717077, -0.461452>,
  <-0.673987, -0.487645>,
  <-0.621974, -0.500308>,
  <0.04965, -0.6005>,
  <0.090938, -0.611305>,
  <0.115264, -0.627277>,
  <0.133699, -0.66702>,
  <0.13942, -0.716683>,
  <0.142662, -1.293744>,
  <0.149218, -1.322705>,
  <0.173188, -1.329475>,
  <0.706451, -1.331447>,
  <0.730452, -1.326098>,
  <0.749093, -1.302832>,
  <1.122102, -0.583801>,
  <1.715637, -0.477445>,
  <1.772305, -0.468934>,
  <1.816778, -0.447605>,
  <1.833682, -0.403047>,
  <1.842764, -0.348588>,
  <1.842019, 0.371635>,
  <1.833942, 0.419909>,
  <1.816511, 0.454204>,
  <1.777868, 0.471615>,
  <1.727313, 0.477046>,
  <1.113485, 0.578669>,
  <0.743587, 1.29714>,
  <0.723874, 1.317804>,
  <0.703331, 1.321844>,
  <0.185159, 1.322741>,
  <0.159258, 1.315353>,
  <0.151676, 1.285422>,
  <0.149666, 0.69784>,
  <0.145462, 0.65742>,
  <0.132483, 0.624263>,
  <0.104737, 0.609631>,
  <0.066304, 0.60224>,
  <-0.611359, 0.500308>,
  <-0.65989, 0.496872>,
  <-0.70228, 0.483841>,
  <-0.724761, 0.450226>,
  <-0.73679, 0.400246>,
  <-0.73679, -0.352531>,
  <-0.734512, -0.407038>,
  <-0.717077, -0.461452>
  rotate -x*90
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <-3.5, -2.73013, 0.0>
}
#declare Eagle_TraSwp101ca = prism {
  linear_sweep
  linear_spline
  -7.0,0.0
  45  // control points
  <-0.763542, -0.623339>,
  <-0.717659, -0.658683>,
  <-0.662276, -0.67577>,
  <0.052867, -0.711486>,
  <0.096831, -0.724142>,
  <0.122733, -0.74285>,
  <0.142362, -0.789401>,
  <0.148454, -0.847571>,
  <0.166634, -1.458026>,
  <0.173191, -1.489247>,
  <0.197161, -1.496546>,
  <0.730424, -1.498672>,
  <0.754424, -1.492905>,
  <0.773066, -1.467823>,
  <1.122102, -0.709254>,
  <1.715637, -0.580042>,
  <1.772305, -0.569703>,
  <1.816778, -0.54379>,
  <1.833682, -0.489658>,
  <1.842764, -0.423496>,
  <1.842019, 0.451495>,
  <1.833942, 0.510142>,
  <1.816511, 0.551808>,
  <1.777868, 0.57296>,
  <1.727313, 0.579558>,
  <1.113485, 0.703019>,
  <0.813257, 1.398383>,
  <0.793544, 1.420659>,
  <0.773001, 1.425015>,
  <0.185159, 1.425982>,
  <0.159258, 1.418018>,
  <0.151676, 1.38575>,
  <0.159364, 0.833232>,
  <0.154888, 0.785888>,
  <0.141067, 0.747051>,
  <0.111523, 0.729913>,
  <0.0706, 0.721256>,
  <-0.650974, 0.674445>,
  <-0.702648, 0.669809>,
  <-0.747786, 0.652225>,
  <-0.771724, 0.606865>,
  <-0.784531, 0.539424>,
  <-0.784531, -0.476362>,
  <-0.782106, -0.549913>,
  <-0.763542, -0.623339>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <0.0, 0.0, 90.0>
  translate  <0.007828, -2.732548, -2.5>
}
#declare Eagle_TraSwp102ca = prism {
  linear_sweep
  linear_spline
  -7.0,0.0
  15  // control points
  <0.766723, -0.47359>,
  <0.951928, -0.832614>,
  <1.197136, -1.146637>,
  <1.502853, -1.05073>,
  <1.786152, -0.922171>,
  <1.833682, -0.863203>,
  <1.842764, -0.797041>,
  <1.842019, 0.929233>,
  <1.833942, 0.987881>,
  <1.816511, 1.029546>,
  <1.777868, 1.050698>,
  <1.727313, 1.057296>,
  <1.185737, 0.931496>,
  <0.763767, 0.018309>,
  <0.766723, -0.47359>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <0.0, 0.0, 90.0>
  translate  <1.75244, -2.728344, -2.5>
}
#declare Eagle_TraSwp103ca = prism {
  linear_sweep
  linear_spline
  -7.0,0.0
  15  // control points
  <0.766723, 0.47359>,
  <0.951928, 0.832614>,
  <1.197136, 1.146637>,
  <1.502853, 1.05073>,
  <1.786152, 0.922171>,
  <1.833682, 0.863203>,
  <1.842764, 0.797041>,
  <1.842019, -0.929233>,
  <1.833942, -0.987881>,
  <1.816511, -1.029546>,
  <1.777868, -1.050698>,
  <1.727313, -1.057296>,
  <1.185737, -0.931496>,
  <0.763767, -0.018309>,
  <0.766723, 0.47359>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <0.0, 0.0, 90.0>
  translate  <-1.75244, -2.728344, -2.5>
}
#declare Eagle_TraSwp104ca = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  19  // control points
  <1.163862, -0.602472>,
  <1.17015, -0.625077>,
  <1.189415, -0.639747>,
  <1.210832, -0.641098>,
  <1.715637, -0.641289>,
  <1.772305, -0.630013>,
  <1.816778, -0.601753>,
  <1.833682, -0.542717>,
  <1.842764, -0.470562>,
  <1.842019, 0.492396>,
  <1.833942, 0.556357>,
  <1.816511, 0.601797>,
  <1.777868, 0.624864>,
  <1.727313, 0.63206>,
  <1.224568, 0.637249>,
  <1.195067, 0.635445>,
  <1.173208, 0.620445>,
  <1.166123, 0.586572>,
  <1.163862, -0.602472>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <0.0, 0.0, 90.0>
  translate  <-0.004258, -1.88862, 1.2>
}
#declare Eagle_TraSwp105ca = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  19  // control points
  <1.18561, -0.606913>,
  <1.191898, -0.629518>,
  <1.211163, -0.644188>,
  <1.232579, -0.645539>,
  <1.715637, -0.641289>,
  <1.772305, -0.630013>,
  <1.816778, -0.601753>,
  <1.833682, -0.542717>,
  <1.842764, -0.470562>,
  <1.842019, 0.492396>,
  <1.833942, 0.556357>,
  <1.816511, 0.601797>,
  <1.777868, 0.624864>,
  <1.727313, 0.63206>,
  <1.246316, 0.632808>,
  <1.216814, 0.631004>,
  <1.194956, 0.616004>,
  <1.187871, 0.58213>,
  <1.18561, -0.606913>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <0.0, 0.0, 90.0>
  translate  <-0.004258, -1.88862, -1.9>
}
#declare Eagle_TraSwp106ca = prism {
  linear_sweep
  linear_spline
  -1.5,0.0
  19  // control points
  <1.183651, -0.433515>,
  <1.18994, -0.449781>,
  <1.209205, -0.460337>,
  <1.230621, -0.461308>,
  <1.715637, -0.458316>,
  <1.772305, -0.450202>,
  <1.816778, -0.429867>,
  <1.833682, -0.387387>,
  <1.842764, -0.335467>,
  <1.842019, 0.357439>,
  <1.833942, 0.403462>,
  <1.816511, 0.436159>,
  <1.777868, 0.452758>,
  <1.727313, 0.457936>,
  <1.244358, 0.458539>,
  <1.214856, 0.457241>,
  <1.192998, 0.446448>,
  <1.185913, 0.422074>,
  <1.183651, -0.433515>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <90.0, -0.0, 90.0>
  translate  <1.9, -1.88862, 0.0>
}
#declare Eagle_TraSwp107ca = prism {
  linear_sweep
  linear_spline
  -1.5,0.0
  19  // control points
  <1.183651, -0.433515>,
  <1.18994, -0.449781>,
  <1.209205, -0.460337>,
  <1.230621, -0.461308>,
  <1.715637, -0.458316>,
  <1.772305, -0.450202>,
  <1.816778, -0.429867>,
  <1.833682, -0.387387>,
  <1.842764, -0.335467>,
  <1.842019, 0.357439>,
  <1.833942, 0.403462>,
  <1.816511, 0.436159>,
  <1.777868, 0.452758>,
  <1.727313, 0.457936>,
  <1.244358, 0.458539>,
  <1.214856, 0.457241>,
  <1.192998, 0.446448>,
  <1.185913, 0.422074>,
  <1.183651, -0.433515>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <90.0, -0.0, 90.0>
  translate  <-3.0, -1.88862, 0.0>
}
#declare Eagle_TraSwp108ca = prism {
  linear_sweep
  linear_spline
  -7.0,0.0
  13  // control points
  <1.203872, 0.766696>,
  <1.388973, 0.635079>,
  <1.580281, 0.453805>,
  <1.715293, 0.290498>,
  <1.834209, 0.093692>,
  <1.843291, 0.02753>,
  <1.842019, -0.929233>,
  <1.833942, -0.987881>,
  <1.816511, -1.029546>,
  <1.777868, -1.050698>,
  <1.727313, -1.057296>,
  <1.193237, -1.051499>,
  <1.203872, 0.766696>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <0.0, 0.0, 90.0>
  translate  <-1.765892, -1.88758, -2.5>
}
#declare Eagle_TraSwp109ca = prism {
  linear_sweep
  linear_spline
  -7.0,0.0
  13  // control points
  <1.203872, -0.766696>,
  <1.388973, -0.635079>,
  <1.580281, -0.453805>,
  <1.715293, -0.290498>,
  <1.834209, -0.093692>,
  <1.843291, -0.02753>,
  <1.842019, 0.929233>,
  <1.833942, 0.987881>,
  <1.816511, 1.029546>,
  <1.777868, 1.050698>,
  <1.727313, 1.057296>,
  <1.193237, 1.051499>,
  <1.203872, -0.766696>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 0.7>
  rotate <0.0, 0.0, 90.0>
  translate  <1.766, -1.88758, -2.5>
}
#declare Eagle_hulldetails = union {
  object { Eagle_TraSwp92ca }
  object { Eagle_TraSwp003ca }
  object { Eagle_TraSwp93ca }
  object { Eagle_TraSwp94ca }
  object { Eagle_TraSwp95ca }
  object { Eagle_TraSwp96ca }
  object { Eagle_TraSwp97ca }
  object { Eagle_TraSwp98ca }
  object { Eagle_TraSwp99ca }
  object { Eagle_TraSwp100ca }
  object { Eagle_TraSwp101ca }
  object { Eagle_TraSwp102ca }
  object { Eagle_TraSwp103ca }
  object { Eagle_TraSwp104ca }
  object { Eagle_TraSwp105ca }
  object { Eagle_TraSwp106ca }
  object { Eagle_TraSwp107ca }
  object { Eagle_TraSwp108ca }
  object { Eagle_TraSwp109ca }
  photons {
    collect off
  }
}
#declare Eagle_CSG46Eagle_cap = intersection {
  object { Eagle_capsulesecondary }
  object { Eagle_hulldetails }
  photons {
    collect off
  }
}
#declare Eagle_decalpatch = object {   object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.158855, -0.613853, -0.065254>, <-0.579427, -0.613853, -0.006321>, <0.000000, -0.613853, -0.023159>, <0.579427, -0.613853, -0.056835>, 
      <-1.158855, -0.306927, 0.000000>, <-0.579427, -0.306927, 0.084190>, <0.000000, -0.306927, 0.058933>, <0.579427, -0.306927, 0.000000>, 
      <-1.158855, 0.000000, 0.000000>, <-0.579427, 0.000000, 0.084190>, <0.000000, 0.000000, 0.058933>, <0.579427, 0.000000, 0.000000>, 
      <-1.158855, 0.306927, -0.084190>, <-0.571008, 0.306927, 0.016838>, <0.000000, 0.306927, -0.025257>, <0.579427, 0.306927, -0.067352>
    }
  }
  material {
    Eagle_decal
    scale <1.744751, 0.928586, 1.0>
    translate <-1.163563, -0.618082, 0.000000>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.498045
  rotate <90.0, -0.0, 55.83075>
  translate  <2.468713, -4.159843, 0.070443>
}
#declare Eagle_decalpatch1 = object {   object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-1.158855, -0.613853, 0.050514>, <-0.579427, -0.613853, -0.008419>, <0.000000, -0.613853, 0.008419>, <0.579427, -0.613853, 0.042095>, 
      <-1.158855, -0.306927, 0.000000>, <-0.579427, -0.306927, -0.084190>, <0.000000, -0.306927, -0.058933>, <0.579427, -0.306927, 0.000000>, 
      <-1.158855, 0.000000, 0.000000>, <-0.579427, 0.000000, -0.084190>, <0.000000, 0.000000, -0.058933>, <0.579427, 0.000000, 0.000000>, 
      <-1.158855, 0.306927, 0.067195>, <-0.571008, 0.306927, -0.028504>, <0.000000, 0.306927, 0.016052>, <0.579427, 0.306927, 0.067352>
    }
  }
  material {
    Eagle_decal
    scale <1.744751, 0.928586, 1.0>
    rotate <-180.0, 0.0, 180.0>
    translate <0.594857, -0.616482, -0.025809>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.498045
  rotate <90.0, -0.0, 124.223412>
  translate  <-2.46638, -4.158485, 0.070479>
}
#declare Eagle_capsulemainframe = union {
  object { Eagle_capsulemain }
  object { Eagle_CSG46Eagle_cap }
  box { // torpedodetail
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale <0.06, 0.06, 0.2>
    rotate <39.63129, 11.184066, 5.167594>
    translate  <0.38703, -5.705354, 0.439711>
  }
  box { // torpedodetail2
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_windows
    }
    photons {
      collect off
    }
    scale <0.06, 0.06, 0.2>
    rotate <39.81078, -10.220619, -4.942398>
    translate  <-0.38703, -5.703361, 0.439863>
  }
  object { Eagle_decalpatch }
  object { Eagle_decalpatch1 }
  photons {
    collect off
  }
}
#declare Eagle_TraSwp110w = prism {
  linear_sweep
  linear_spline
  -4.0,0.0
  5  // control points
  <0.000001, 0.000002>,
  <2.823934, -0.497725>,
  <2.817127, 0.921499>,
  <0.000001, 1.442866>,
  <0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_windows
  }
  photons {
    collect off
  }
  rotate <101.5, 0.0, -2.4>
  translate  <0.778753, -2.688715, 1.084069>
}
#declare Eagle_TraSwp111w = prism {
  linear_sweep
  linear_spline
  -4.0,0.0
  5  // control points
  <-0.000001, 0.000002>,
  <-2.823934, -0.497725>,
  <-2.817127, 0.921499>,
  <-0.000001, 1.442866>,
  <-0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_windows
  }
  photons {
    collect off
  }
  rotate <101.5, 0.0, 2.4>
  translate  <-0.778753, -2.688715, 1.084069>
}
#declare Eagle_TraSwp112w = prism {
  linear_sweep
  linear_spline
  -4.0,0.0
  5  // control points
  <0.000001, -0.000002>,
  <2.823934, 0.497725>,
  <2.817127, -0.921499>,
  <0.000001, -1.442866>,
  <0.000001, -0.000002>
  rotate -x*90
  material {
    Eagle_windows
  }
  photons {
    collect off
  }
  rotate <-281.5, 0.0, -2.4>
  translate  <0.778753, -2.688715, -1.084069>
}
#declare Eagle_TraSwp113w = prism {
  linear_sweep
  linear_spline
  -4.0,0.0
  5  // control points
  <-0.000001, -0.000002>,
  <-2.823934, 0.497725>,
  <-2.817127, -0.921499>,
  <-0.000001, -1.442866>,
  <-0.000001, -0.000002>
  rotate -x*90
  material {
    Eagle_windows
  }
  photons {
    collect off
  }
  rotate <-281.5, 0.0, 2.4>
  translate  <-0.778753, -2.688715, -1.084069>
}
#declare Eagle_TraSwp114w = prism {
  linear_sweep
  linear_spline
  -0.5,0.0
  5  // control points
  <0.000001, 0.000002>,
  <2.827531, -0.487026>,
  <2.817127, 0.921499>,
  <0.000001, 1.442866>,
  <0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_windows
    scale <2.835414, 1.079369, 1.0>
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.765389, -2.688716, 1.084069>
}
#declare Eagle_TraSwp115w = prism {
  linear_sweep
  linear_spline
  -0.5,0.0
  5  // control points
  <0.000001, -0.000002>,
  <2.827531, 0.487026>,
  <2.817127, -0.921499>,
  <0.000001, -1.442866>,
  <0.000001, -0.000002>
  rotate -x*90
  material {
    Eagle_windows
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.765389, -2.688716, -1.084069>
}
#declare Eagle_TraSwp116w = prism {
  linear_sweep
  linear_spline
  -0.5,0.0
  5  // control points
  <-0.000001, -0.000002>,
  <-2.827531, 0.487026>,
  <-2.817127, -0.921499>,
  <-0.000001, -1.442866>,
  <-0.000001, -0.000002>
  rotate -x*90
  material {
    Eagle_windows
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <-0.765389, -2.688716, -1.084069>
}
#declare Eagle_TraSwp117w = prism {
  linear_sweep
  linear_spline
  -0.5,0.0
  5  // control points
  <-0.000001, 0.000002>,
  <-2.827531, -0.487026>,
  <-2.817127, 0.921499>,
  <-0.000001, 1.442866>,
  <-0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_windows
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <-0.765389, -2.688716, 1.084069>
}
#declare Eagle_frmoutline = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <0.000001, 0.000002>,
  <0.091896, -0.015827>,
  <0.091558, 1.425921>,
  <0.000001, 1.442866>,
  <0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
    scale <2.835414, 1.079369, 1.0>
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.765392, -2.688709, 1.084069>
}
#declare Eagle_frmoutline2 = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <0.000001, 0.000002>,
  <2.827531, -0.487026>,
  <2.827125, -0.432094>,
  <0.000001, 0.068935>,
  <0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
    scale <2.835414, 1.079369, 1.0>
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <0.765389, -2.688689, 1.084089>
}
#declare Eagle_frmoutline3 = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <-0.000001, 0.000002>,
  <-0.084827, -0.014609>,
  <-0.084515, 1.427225>,
  <-0.000001, 1.442866>,
  <-0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <-0.765393, -2.68871, 1.084069>
}
#declare Eagle_frmoutline4 = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <-0.000001, 0.000002>,
  <-2.827531, -0.487026>,
  <-2.827011, -0.4166>,
  <-0.000001, 0.072145>,
  <-0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <-0.765397, -2.688701, 1.084069>
}
#declare Eagle_bottomEagle_frmoutline5 = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <0.000001, 0.000002>,
  <2.827531, -0.487026>,
  <2.827125, -0.432094>,
  <0.000001, 0.068935>,
  <0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
    scale <2.835414, 1.079369, 1.0>
  }
  photons {
    collect off
  }
  scale -1.0
  rotate 90.0*x
  translate  <-0.765373, -2.689696, -1.084071>
}
#declare Eagle_bottomEagle_frmoutline7 = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <-0.000001, 0.000002>,
  <-2.827531, -0.487026>,
  <-2.827011, -0.4166>,
  <-0.000001, 0.072145>,
  <-0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
  }
  photons {
    collect off
  }
  scale -1.0
  rotate 90.0*x
  translate  <0.765388, -2.689697, -1.084072>
}
#declare Eagle_bottomEagle_frmoutline8 = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <0.000001, 0.000002>,
  <0.091896, -0.015827>,
  <0.091558, 1.425921>,
  <0.000001, 1.442866>,
  <0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
    scale <2.835414, 1.079369, 1.0>
  }
  photons {
    collect off
  }
  scale -1.0
  rotate 90.0*x
  translate  <0.857287, -2.689696, -0.612875>
}
#declare Eagle_bottomEagle_frmoutline9 = prism {
  linear_sweep
  linear_spline
  -0.001,0.0
  5  // control points
  <-0.000001, 0.000002>,
  <-0.084827, -0.014609>,
  <-0.084515, 1.427225>,
  <-0.000001, 1.442866>,
  <-0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_basic
  }
  photons {
    collect off
  }
  scale -1.0
  rotate 90.0*x
  translate  <-0.850211, -2.689693, -0.611654>
}
#declare windowunions = union {
  object { Eagle_TraSwp110w }
  object { Eagle_TraSwp111w }
  object { Eagle_TraSwp112w }
  object { Eagle_TraSwp113w }
  object { Eagle_TraSwp114w }
  object { Eagle_TraSwp115w }
  object { Eagle_TraSwp116w }
  object { Eagle_TraSwp117w }
  object { Eagle_frmoutline }
  object { Eagle_frmoutline2 }
  object { Eagle_frmoutline3 }
  object { Eagle_frmoutline4 }
  object { Eagle_bottomEagle_frmoutline5 }
  object { Eagle_bottomEagle_frmoutline7 }
  object { Eagle_bottomEagle_frmoutline8 }
  object { Eagle_bottomEagle_frmoutline9 }
  photons {
    collect off
  }
}
#declare Eagle_capmain2 = difference {
  object { Eagle_capsulemainframe }
  object { windowunions }
  photons {
    collect off
  }
}
#declare Eagle_cmthrust1 = lathe {
  linear_spline
  4  // control points
  <-0.000119, 0.899992>,
  <0.100325, 0.899525>,
  <0.370056, 1.000002>,
  <0.000016, 1.0>
  rotate <90,0,90>
  material {
    Eagle_capSIDE
    scale 0.53
    translate <-0.268415, -0.256259, 1.022445>
  }
  photons {
    collect off
  }
  scale <1.5, 1.5, 1.0>
  translate  <0.0, -2.2, 1.02>
}
#declare Eagle_cmthrust2 = lathe {
  linear_spline
  4  // control points
  <0.000085, 0.899727>,
  <0.100326, 0.899922>,
  <0.370121, 0.999997>,
  <0.000016, 1.0>
  rotate <90,0,90>
  material {
    Eagle_capSIDE
    scale 0.42
    translate <-0.213508, -0.192910, 0.997090>
  }
  photons {
    collect off
  }
  scale <1.5, 1.5, 1.0>
  rotate -90.0*y
  translate  <-2.27, -2.2, 0.0>
}
#declare Eagle_cmthrust3 = lathe {
  linear_spline
  4  // control points
  <-0.000089, 0.898908>,
  <0.099303, 0.899882>,
  <0.370025, 1.000039>,
  <0.000016, 1.0>
  rotate <90,0,90>
  material {
    Eagle_capSIDE
    scale 0.42
    translate <-0.208918, -0.189828, 1.026706>
  }
  photons {
    collect off
  }
  scale <1.5, 1.5, 1.0>
  rotate 90.0*y
  translate  <2.27, -2.2, 0.0>
}
#declare Eagle_cmthrust4 = lathe {
  linear_spline
  4  // control points
  <0.001282, 0.899729>,
  <0.099882, 0.899924>,
  <0.369973, 0.999965>,
  <0.000016, 1.0>
  rotate <90,0,90>
  material {
    Eagle_capSIDE
    scale 0.53
    translate <-0.262978, -0.256581, 1.006469>
  }
  photons {
    collect off
  }
  scale <1.5, 1.5, 1.0>
  rotate <180.0, 0.0, 180.0>
  translate  <0.0, -2.2, -1.02>
}
#declare Eagle_cmthrusters = union {
  object { Eagle_cmthrust1 }
  object { Eagle_cmthrust2 }
  object { Eagle_cmthrust3 }
  object { Eagle_cmthrust4 }
  photons {
    collect off
  }
}
#declare Eagle_cap = difference {
  object { Eagle_capmain2 }
  object { Eagle_cmthrusters }
  material {
    Eagle_capsulewraptext
    scale <4.243629, 4.243629, 6.541785>
    rotate <-90.0, -90.0, 180.0>
  }
  photons {
    collect off
  }
  translate  <0.820898, -22.536618, -2.403745>
}
#declare Eagle_cockpitcutout = lathe {
  linear_spline
  14  // control points
  <-0.0, 0.0>,
  <1.25, 0.0>,
  <1.498743, 0.3375>,
  <1.7, 0.75>,
  <1.832884, 1.1375>,
  <1.927071, 1.525>,
  <1.992559, 1.9125>,
  <2.0, 2.3>,
  <1.936663, 2.692805>,
  <1.932091, 2.72116>,
  <1.92835, 2.74436>,
  <1.927237, 2.751262>,
  <1.927082, 2.752224>,
  <-0.002162, 2.755356>
  rotate <90,0,90>
  material {
    Eagle_cpinterior
    scale <1.0, 1.0, 2.152672>
    rotate 90.0*z
    translate <0.000000, -0.012834, 0.509110>
  }
  photons {
    collect off
  }
  scale <1.553092, 0.955749, 0.955749>
  rotate 90.0*x
  translate  <0.819014, -22.584574, -2.378657>
}
#declare Eagle_testtest = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  8  // control points
  <0.000001, 0.000002>,
  <2.114188, -0.364546>,
  <1.694663, -0.003106>,
  <1.26008, 0.275513>,
  <0.70735, 0.555011>,
  <0.296097, 0.662585>,
  <0.000001, 0.703372>,
  <0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_windows
    scale <2.835414, 1.079369, 1.0>
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <1.678291, -25.19527, -1.250658>
}
#declare Eagle_testtest1 = prism {
  linear_sweep
  linear_spline
  -0.05,0.0
  8  // control points
  <-0.000001, 0.000002>,
  <-2.112707, -0.370469>,
  <-1.694663, -0.003106>,
  <-1.26008, 0.275513>,
  <-0.70735, 0.555011>,
  <-0.296097, 0.662585>,
  <-0.000001, 0.703372>,
  <-0.000001, 0.000002>
  rotate -x*90
  material {
    Eagle_windows
    scale <2.835414, 1.079369, 1.0>
  }
  photons {
    collect off
  }
  rotate 90.0*x
  translate  <-0.02935, -25.195238, -1.250658>
}
#declare Eagle_cockpitunion = union {
  object { Eagle_cockpitcutout }
  object { Eagle_testtest }
  object { Eagle_testtest1 }
  photons {
    collect off
  }
}
#declare Eagle_thrustcutunion = union {
  cylinder { // thrustjoiner1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.31395, 0.321381, 0.207655>
    translate  <0.820447, -24.737908, -0.649809>
  }
  cylinder { // thrustjoiner2
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.31395, 0.321381, 0.207655>
    translate  <0.820447, -24.735785, -4.366391>
  }
  cylinder { // thrustjoiner3
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.236031, 0.241617, 0.156117>
    rotate <0.0, 90.0, -0.0>
    translate  <3.781541, -24.733047, -2.409929>
  }
  cylinder { // thrustjoiner4
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.233052, 0.238568, 0.154147>
    rotate <0.0, 90.0, -0.0>
    translate  <-2.291786, -24.736477, -2.409929>
  }
  photons {
    collect off
  }
}
#declare Eagle_thrustcutfidd = difference {
  object { Eagle_cockpitunion }
  object { Eagle_thrustcutunion }
  photons {
    collect off
  }
}
#declare Eagle_capsule200 = difference {
  object { Eagle_cap }
  object { Eagle_thrustcutfidd }
  photons {
    collect off
  }
}
#declare Eagle_backwall = lathe {
  linear_spline
  4  // control points
  <-0.013083, 0.340167>,
  <1.498743, 0.3375>,
  <1.538994, 0.42>,
  <-0.015246, 0.413434>
  rotate <90,0,90>
  material {
    Eagle_backwalltexture
    scale <2.936028, 2.450305, 1.0>
    translate <-1.478682, -0.935571, 0.398086>
  }
  photons {
    collect off
  }
  scale <1.553092, 0.955749, 0.955749>
  rotate 90.0*x
  translate  <0.819014, -22.584574, -2.378657>
}
#declare Eagle_basicEagle_door2 = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  21  // control points
  <-3.37431, -5.81324>,
  <-3.138757, -5.933523>,
  <-2.850859, -5.939853>,
  <2.897893, -5.92767>,
  <3.197517, -5.887787>,
  <3.419644, -5.763073>,
  <3.534074, -5.519391>,
  <3.547215, -5.199742>,
  <2.856374, 5.338956>,
  <2.824483, 5.589823>,
  <2.733764, 5.792544>,
  <2.53108, 5.917997>,
  <2.2587, 5.931936>,
  <-2.227257, 5.919753>,
  <-2.488857, 5.898844>,
  <-2.694701, 5.7943>,
  <-2.832673, 5.588415>,
  <-2.887008, 5.326773>,
  <-3.577849, -5.275232>,
  <-3.514063, -5.58222>,
  <-3.37431, -5.81324>
  rotate -x*90
  photons {
    collect off
  }
  translate  -0.15*z
}
#declare Eagle_basicdoorcutout = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  21  // control points
  <-2.671723, -5.113285>,
  <-2.464383, -5.21916>,
  <-2.210967, -5.224733>,
  <2.25248, -5.223974>,
  <2.516218, -5.188867>,
  <2.711739, -5.079091>,
  <2.812464, -4.864596>,
  <2.824031, -4.583232>,
  <2.215935, 4.693211>,
  <2.187863, 4.914031>,
  <2.108009, 5.092471>,
  <1.929602, 5.202898>,
  <1.689846, 5.215168>,
  <-1.662056, 5.214409>,
  <-1.892324, 5.196004>,
  <-2.073513, 5.103981>,
  <-2.194959, 4.922756>,
  <-2.242787, 4.692451>,
  <-2.850883, -4.639715>,
  <-2.794737, -4.909934>,
  <-2.671723, -5.113285>
  rotate -x*90
  photons {
    collect off
  }
  translate  0.65*z
}
#declare Eagle_doordetails = difference {
  object { Eagle_basicEagle_door2 }
  object { Eagle_basicdoorcutout }
  photons {
    collect off
  }
}
#declare Eagle_basicdoor = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  21  // control points
  <-3.976362, -6.354293>,
  <-3.718345, -6.486047>,
  <-3.40299, -6.492981>,
  <3.488065, -6.492981>,
  <3.816264, -6.449294>,
  <4.059575, -6.312687>,
  <4.184918, -6.045766>,
  <4.199311, -5.695632>,
  <3.442587, 5.848122>,
  <3.407655, 6.122914>,
  <3.308283, 6.344968>,
  <3.08627, 6.482386>,
  <2.787914, 6.497654>,
  <-2.719916, 6.497654>,
  <-3.006465, 6.474751>,
  <-3.23194, 6.360237>,
  <-3.383069, 6.134717>,
  <-3.442587, 5.848122>,
  <-4.199311, -5.764976>,
  <-4.129443, -6.101241>,
  <-3.976362, -6.354293>
  rotate -x*90
  material {
    Eagle_doorframered
  }
  photons {
    collect off
  }
}
#declare Eagle_basicdoor1 = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  21  // control points
  <-3.37431, -5.81324>,
  <-3.138757, -5.933523>,
  <-2.850859, -5.939853>,
  <2.897893, -5.92767>,
  <3.197517, -5.887787>,
  <3.419644, -5.763073>,
  <3.534074, -5.519391>,
  <3.547215, -5.199742>,
  <2.856374, 5.338956>,
  <2.824483, 5.589823>,
  <2.733764, 5.792544>,
  <2.53108, 5.917997>,
  <2.2587, 5.931936>,
  <-2.227257, 5.919753>,
  <-2.488857, 5.898844>,
  <-2.694701, 5.7943>,
  <-2.832673, 5.588415>,
  <-2.887008, 5.326773>,
  <-3.577849, -5.275232>,
  <-3.514063, -5.58222>,
  <-3.37431, -5.81324>
  rotate -x*90
  photons {
    collect off
  }
  translate  0.1*z
}
#declare Eagle_doordiff = difference {
  object { Eagle_basicdoor }
  object { Eagle_basicdoor1 }
  photons {
    collect off
  }
}
#declare Eagle_maindoor = union {
  object { Eagle_doordetails }
  object { Eagle_doordiff }
  box { // doorbeam6
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.35, 2.8, 0.2>
    rotate 27.73756*z
    translate  <1.466344, -2.755306, 0.65>
  }
  box { // doorbeam5
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.35, 2.7, 0.2>
    rotate <-0.0, 0.0, 18.767548>
    translate  <-1.165631, 2.749725, 0.65>
  }
  box { // doorbeam3
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.35, 2.7, 0.2>
    rotate <0.0, 0.0, -21.220175>
    translate  <1.188129, 2.725709, 0.65>
  }
  box { // doorbeam4
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.35, 2.8, 0.2>
    rotate -27.737562*z
    translate  <-1.520624, -2.71588, 0.65>
  }
  box { // doorbeam2
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.35, 2.7, 0.2>
    rotate 90.0*z
    translate  0.65*z
  }
  box { // doorbeam1
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.35, 5.37, 0.2>
    translate  0.65*z
  }
  box { // doorbeam7
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_door3text
      scale <2.001292, 2.001292, 1.0>
      translate <-1.001292, -1.001292, 0.000000>
    }
    photons {
      collect off
    }
    scale <0.6, 0.6, 0.2>
    translate  <-0.024304, -0.065941, 0.651>
  }
  material {
    Eagle_maindoortexture
  }
  photons {
    collect off
  }
  scale 0.162831
  rotate 90.0*x
  translate  <0.723788, -22.930828, -2.135235>
}

#declare Eagle_suitneck = lathe {
  linear_spline
  28  // control points
  <-0.005402, -0.294756>,
  <0.312536, -0.29398>,
  <0.347988, -0.312429>,
  <0.363847, -0.307349>,
  <0.36478, -0.287342>,
  <0.350469, -0.270635>,
  <0.315832, -0.237042>,
  <0.311292, -0.226921>,
  <0.315539, -0.218323>,
  <0.330265, -0.204774>,
  <0.330756, -0.194216>,
  <0.331085, -0.185417>,
  <0.315244, -0.169154>,
  <0.309931, -0.158552>,
  <0.316263, -0.149114>,
  <0.328133, -0.141602>,
  <0.32961, -0.127021>,
  <0.324391, -0.114695>,
  <0.310098, -0.103465>,
  <0.314526, -0.090191>,
  <0.321554, -0.083996>,
  <0.326219, -0.074501>,
  <0.322487, -0.063775>,
  <0.315024, -0.056292>,
  <0.30557, -0.050777>,
  <0.308804, -0.04398>,
  <0.312536, -0.032787>,
  <0.002672, -0.036332>
  rotate <90,0,90>
  photons {
    collect off
  }
  rotate -54.427162*y
  translate  <-0.856194, 0.0, -1.285713>
}
#declare Eagle_neckring = lathe {
  linear_spline
  4  // control points
  <-0.000427, -0.079559>,
  <0.338658, -0.079926>,
  <0.338658, -0.032787>,
  <0.002672, -0.033844>
  rotate <90,0,90>
  material {
    Eagle_neckringtexture
  }
  photons {
    collect off
  }
  scale -1.0
  rotate <-180.0, 54.427162, -180.0>
  translate  <-0.894273, 0.0, -1.264231>
}
#declare Eagle_chestpack = difference {
  box { // chestunit
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.279184, 0.358451, 0.119288>
    rotate <90.0, 0.0, -90.0>
    translate  <-0.891056, 0.0, -1.858429>
  }
  box { // chestunitcutout
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.100088, 0.301345, 0.153548>
    rotate 30.546072*y
    translate  <-1.021354, 0.0, -1.568164>
  }
  material {
    Eagle_chestunittext
    scale <0.573499, 0.732067, 1.0>
    rotate <90.0, 0.0, -90.0>
    translate <-1.018642, 0.287726, -2.215175>
  }
  photons {
    collect off
  }
  scale <1.0, 1.046114, 1.0>
  rotate -38.073509*y
  translate  <-1.116852, 0.0, -0.088543>
}
#declare Eagle_cheststrap = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -3.431095, -2.131698>, <-1.000000, -3.431095, -2.131698>, <0.000000, -3.431095, -2.131698>, <1.000000, -3.431095, -2.131698>, 
      <-2.000000, -3.960557, -0.788858>, <-1.000000, -3.960557, -0.788858>, <0.000000, -3.960557, -0.788858>, <1.000000, -3.960557, -0.788858>, 
      <-2.000000, -3.000000, -0.394429>, <-1.000000, -3.000000, -0.394429>, <0.000000, -3.000000, -0.394429>, <1.000000, -3.000000, -0.394429>, 
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>, 
      <-2.000000, 0.538272, 0.000000>, <-1.000000, 0.538272, 0.000000>, <0.000000, 0.538272, 0.000000>, <1.000000, 0.538272, 0.000000>, 
      <-2.000000, 0.000000, 0.000000>, <-1.000000, 0.000000, 0.000000>, <0.000000, 0.000000, 0.000000>, <1.000000, 0.000000, 0.000000>, 
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>, 
      <-2.000000, 0.225070, -0.039443>, <-1.000000, 0.225070, -0.039443>, <0.000000, 0.225070, -0.039443>, <1.000000, 0.225070, -0.039443>, 
      <-2.000000, -0.300514, 0.000000>, <-1.000000, -0.300514, 0.000000>, <0.000000, -0.300514, 0.000000>, <1.000000, -0.300514, 0.000000>, 
      <-2.000000, 0.699486, 0.000000>, <-1.000000, 0.699486, 0.000000>, <0.000000, 0.699486, 0.000000>, <1.000000, 0.699486, 0.000000>
    }
  }
  material {
    Eagle_straptexture
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale <0.035769, 0.212435, 0.212435>
  rotate <-116.094658, -19.234064, 105.861633>
  translate  <-0.757934, -0.165762, -2.039582>
}
#declare Eagle_cheststrap1 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -3.431095, -2.131698>, <-1.000000, -3.431095, -2.131698>, <0.000000, -3.431095, -2.131698>, <1.000000, -3.431095, -2.131698>, 
      <-2.000000, -3.960557, -0.788858>, <-1.000000, -3.960557, -0.788858>, <0.000000, -3.960557, -0.788858>, <1.000000, -3.960557, -0.788858>, 
      <-2.000000, -3.000000, -0.394429>, <-1.000000, -3.000000, -0.394429>, <0.000000, -3.000000, -0.394429>, <1.000000, -3.000000, -0.394429>, 
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>, 
      <-2.000000, 0.538272, 0.000000>, <-1.000000, 0.538272, 0.000000>, <0.000000, 0.538272, 0.000000>, <1.000000, 0.538272, 0.000000>, 
      <-2.000000, 0.000000, 0.000000>, <-1.000000, 0.000000, 0.000000>, <0.000000, 0.000000, 0.000000>, <1.000000, 0.000000, 0.000000>, 
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>, 
      <-2.000000, 0.225070, -0.039443>, <-1.000000, 0.225070, -0.039443>, <0.000000, 0.225070, -0.039443>, <1.000000, 0.225070, -0.039443>, 
      <-2.000000, -0.300514, 0.000000>, <-1.000000, -0.300514, 0.000000>, <0.000000, -0.300514, 0.000000>, <1.000000, -0.300514, 0.000000>, 
      <-2.000000, 0.699486, 0.000000>, <-1.000000, 0.699486, 0.000000>, <0.000000, 0.699486, 0.000000>, <1.000000, 0.699486, 0.000000>
    }
  }
  material {
    Eagle_straptexture
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale <0.035769, 0.212435, 0.212435>
  rotate <-115.648216, 17.67075, 75.548584>
  translate  <-0.735015, 0.223381, -2.06884>
}
#declare Eagle_helmetframecut = prism {
  linear_sweep
  linear_spline
  -2.0,0.0
  35  // control points
  <-0.000643, -0.368027>,
  <0.006187, -0.401986>,
  <0.020096, -0.448884>,
  <0.052374, -0.496094>,
  <0.192587, -0.44977>,
  <0.41499, -0.352107>,
  <0.55508, -0.295029>,
  <0.694365, -0.225701>,
  <0.802838, -0.138379>,
  <0.85703, -0.079881>,
  <0.882335, -0.0>,
  <0.852509, 0.071168>,
  <0.794403, 0.148058>,
  <0.683274, 0.221847>,
  <0.532985, 0.287526>,
  <0.394648, 0.366086>,
  <0.214414, 0.437502>,
  <0.134549, 0.473669>,
  <0.097685, 0.454104>,
  <0.076628, 0.430048>,
  <0.044744, 0.365087>,
  <0.146068, 0.324615>,
  <0.228194, 0.270903>,
  <0.282249, 0.205962>,
  <0.314503, 0.158682>,
  <0.340057, 0.111402>,
  <0.350325, 0.060155>,
  <0.352949, 0.0>,
  <0.347272, -0.051678>,
  <0.332889, -0.09747>,
  <0.309366, -0.144514>,
  <0.279142, -0.189325>,
  <0.219038, -0.252814>,
  <0.147705, -0.299461>,
  <-0.000643, -0.368027>
  rotate -x*90
  material {
    Eagle_helmettexture
  }
  photons {
    collect off
  }
  scale <0.527692, 0.548794, 0.517621>
  rotate <90.0, -12.709352, 0.0>
  translate  <-1.027293, 0.49453, -0.899949>
}
#declare Eagle_visorframe = intersection {
  sphere { // helmetintersect
    <0,0,0>,1
    material {
      Eagle_helmettexture
    }
    photons {
      collect off
    }
    scale <0.444671, 0.403538, 0.430767>
    translate  <-0.614097, 0.0, -0.847994>
  }
  object { Eagle_helmetframecut }
  photons {
    collect off
  }
  rotate -38.073509*y
  translate  <-1.139438, 0.0, -0.059711>
}
#declare Eagle_man5_group = union {
  object { Eagle_suitneck }
  object { Eagle_neckring }
  box { // backpack
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_packtexture
    }
    photons {
      collect off
    }
    scale <0.141443, 0.483424, 0.715796>
    rotate -38.073509*y
    translate  <-0.020462, 0.0, -1.546164>
  }
  sphere { // helmet
    <0,0,0>,1
    material {
      Eagle_helmettexture
    }
    photons {
      collect off
    }
    scale <0.419064, 0.380299, 0.40596>
    rotate -38.073509*y
    translate  <-1.099987, 0.0, -1.105799>
  }
  cylinder { // helmetbottom
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_helmettexture
    }
    photons {
      collect off
    }
    scale <0.317301, 0.317301, 0.2>
    rotate -53.339344*y
    translate  <-0.842205, 0.0, -1.305067>
  }
  sphere { // visor
    <0,0,0>,1
    material {
      Eagle_visortexture
    }
    photons {
      collect off
    }
    scale <0.327853, 0.337682, 0.30218>
    rotate -50.555511*y
    translate  <-1.194657, 0.0, -1.200003>
  }
  object { Eagle_chestpack }
  object { Eagle_cheststrap }
  object { Eagle_cheststrap1 }
  object { Eagle_visorframe }
  cylinder { // visorswivel
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_neckringtexture
    }
    photons {
      collect off
    }
    scale <0.01414, 0.01414, 0.84>
    rotate <90.0, -38.073509, 0.0>
    translate  <-1.131079, 0.419904, -1.097484>
  }
  box { // helmetstripes
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate -14.559975*y
    translate  <-1.492287, 0.0, -1.202898>
  }
  box { // helmetstripes1
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate -66.19397*y
    translate  <-1.182235, 0.0, -1.500233>
  }
  box { // helmetstripes2
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate -66.19397*y
    translate  <-1.182235, 0.0, -1.500233>
  }
  box { // helmetstripes3
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-23.863575, -64.277084, 21.402306>
    translate  <-1.17869, -0.132887, -1.480565>
  }
  box { // helmetstripes4
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <32.930004, -59.866936, -42.456177>
    translate  <-1.170966, 0.141306, -1.48132>
  }
  box { // helmetstripes5
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-2.157874, -14.336593, 11.936019>
    translate  <-1.48527, -0.093734, -1.202101>
  }
  box { // helmetstripes6
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <6.297852, -13.368946, -21.895948>
    translate  <-1.486309, 0.092356, -1.201375>
  }
  box { // helmetstripes7
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-2.478497, -13.222614, 23.647978>
    translate  <-1.448285, -0.189605, -1.193053>
  }
  box { // helmetstripes8
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-0.437556, -14.622518, -30.641428>
    translate  <-1.448426, 0.182122, -1.193904>
  }
  material {
    suittexture
  }
  photons {
    collect off
  }
  scale 0.39
  rotate <-0.0, 38.073509, 90.0>
  translate  <2.107479, -23.845907, -0.998412>
}
#declare Eagle_suitneck1 = lathe {
  linear_spline
  28  // control points
  <-0.005402, -0.294756>,
  <0.312536, -0.29398>,
  <0.347988, -0.312429>,
  <0.363847, -0.307349>,
  <0.36478, -0.287342>,
  <0.350469, -0.270635>,
  <0.315832, -0.237042>,
  <0.311292, -0.226921>,
  <0.315539, -0.218323>,
  <0.330265, -0.204774>,
  <0.330756, -0.194216>,
  <0.331085, -0.185417>,
  <0.315244, -0.169154>,
  <0.309931, -0.158552>,
  <0.316263, -0.149114>,
  <0.328133, -0.141602>,
  <0.32961, -0.127021>,
  <0.324391, -0.114695>,
  <0.310098, -0.103465>,
  <0.314526, -0.090191>,
  <0.321554, -0.083996>,
  <0.326219, -0.074501>,
  <0.322487, -0.063775>,
  <0.315024, -0.056292>,
  <0.30557, -0.050777>,
  <0.308804, -0.04398>,
  <0.312536, -0.032787>,
  <0.002672, -0.036332>
  rotate <90,0,90>
  photons {
    collect off
  }
  rotate -54.427162*y
  translate  <-0.856194, 0.0, -1.285713>
}
#declare Eagle_neckring1 = lathe {
  linear_spline
  4  // control points
  <-0.000427, -0.079559>,
  <0.338658, -0.079926>,
  <0.338658, -0.032787>,
  <0.002672, -0.033844>
  rotate <90,0,90>
  material {
    Eagle_neckringtexture
  }
  photons {
    collect off
  }
  scale -1.0
  rotate <-180.0, 54.427162, -180.0>
  translate  <-0.894273, 0.0, -1.264231>
}
#declare Eagle_chestpack1 = difference {
  box { // chestunit1
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.279184, 0.358451, 0.119288>
    rotate <90.0, 0.0, -90.0>
    translate  <-0.891056, 0.0, -1.858429>
  }
  box { // chestunitcutout1
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.100088, 0.301345, 0.153548>
    rotate 30.546072*y
    translate  <-1.021354, 0.0, -1.568164>
  }
  material {
    Eagle_chestunittext
    scale <0.573499, 0.732067, 1.0>
    rotate <90.0, 0.0, -90.0>
    translate <-1.018642, 0.287726, -2.215175>
  }
  photons {
    collect off
  }
  scale <1.0, 1.046114, 1.0>
  rotate -38.073509*y
  translate  <-1.116852, 0.0, -0.088543>
}
#declare Eagle_cheststrap2 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -3.431095, -2.131698>, <-1.000000, -3.431095, -2.131698>, <0.000000, -3.431095, -2.131698>, <1.000000, -3.431095, -2.131698>, 
      <-2.000000, -3.960557, -0.788858>, <-1.000000, -3.960557, -0.788858>, <0.000000, -3.960557, -0.788858>, <1.000000, -3.960557, -0.788858>, 
      <-2.000000, -3.000000, -0.394429>, <-1.000000, -3.000000, -0.394429>, <0.000000, -3.000000, -0.394429>, <1.000000, -3.000000, -0.394429>, 
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>, 
      <-2.000000, 0.538272, 0.000000>, <-1.000000, 0.538272, 0.000000>, <0.000000, 0.538272, 0.000000>, <1.000000, 0.538272, 0.000000>, 
      <-2.000000, 0.000000, 0.000000>, <-1.000000, 0.000000, 0.000000>, <0.000000, 0.000000, 0.000000>, <1.000000, 0.000000, 0.000000>, 
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>, 
      <-2.000000, 0.225070, -0.039443>, <-1.000000, 0.225070, -0.039443>, <0.000000, 0.225070, -0.039443>, <1.000000, 0.225070, -0.039443>, 
      <-2.000000, -0.300514, 0.000000>, <-1.000000, -0.300514, 0.000000>, <0.000000, -0.300514, 0.000000>, <1.000000, -0.300514, 0.000000>, 
      <-2.000000, 0.699486, 0.000000>, <-1.000000, 0.699486, 0.000000>, <0.000000, 0.699486, 0.000000>, <1.000000, 0.699486, 0.000000>
    }
  }
  material {
    Eagle_straptexture
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale <0.035769, 0.212435, 0.212435>
  rotate <-116.094658, -19.234064, 105.861633>
  translate  <-0.757934, -0.165762, -2.039582>
}
#declare Eagle_cheststrap3 = union { 
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -3.431095, -2.131698>, <-1.000000, -3.431095, -2.131698>, <0.000000, -3.431095, -2.131698>, <1.000000, -3.431095, -2.131698>, 
      <-2.000000, -3.960557, -0.788858>, <-1.000000, -3.960557, -0.788858>, <0.000000, -3.960557, -0.788858>, <1.000000, -3.960557, -0.788858>, 
      <-2.000000, -3.000000, -0.394429>, <-1.000000, -3.000000, -0.394429>, <0.000000, -3.000000, -0.394429>, <1.000000, -3.000000, -0.394429>, 
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, -1.230864, -0.197214>, <-1.000000, -1.230864, -0.197214>, <0.000000, -1.230864, -0.197214>, <1.000000, -1.230864, -0.197214>, 
      <-2.000000, 0.538272, 0.000000>, <-1.000000, 0.538272, 0.000000>, <0.000000, 0.538272, 0.000000>, <1.000000, 0.538272, 0.000000>, 
      <-2.000000, 0.000000, 0.000000>, <-1.000000, 0.000000, 0.000000>, <0.000000, 0.000000, 0.000000>, <1.000000, 0.000000, 0.000000>, 
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>
    }
  }
  object {
    bicubic_patch { type 1 flatness 0.0100 u_steps 3 v_steps 3,
      <-2.000000, 0.112535, -0.019721>, <-1.000000, 0.112535, -0.019721>, <0.000000, 0.112535, -0.019721>, <1.000000, 0.112535, -0.019721>, 
      <-2.000000, 0.225070, -0.039443>, <-1.000000, 0.225070, -0.039443>, <0.000000, 0.225070, -0.039443>, <1.000000, 0.225070, -0.039443>, 
      <-2.000000, -0.300514, 0.000000>, <-1.000000, -0.300514, 0.000000>, <0.000000, -0.300514, 0.000000>, <1.000000, -0.300514, 0.000000>, 
      <-2.000000, 0.699486, 0.000000>, <-1.000000, 0.699486, 0.000000>, <0.000000, 0.699486, 0.000000>, <1.000000, 0.699486, 0.000000>
    }
  }
  material {
    Eagle_straptexture
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale <0.035769, 0.212435, 0.212435>
  rotate <-115.648216, 17.67075, 75.548584>
  translate  <-0.735015, 0.223381, -2.06884>
}
#declare Eagle_helmetframecut1 = prism {
  linear_sweep
  linear_spline
  -2.0,0.0
  35  // control points
  <-0.000643, -0.368027>,
  <0.006187, -0.401986>,
  <0.020096, -0.448884>,
  <0.052374, -0.496094>,
  <0.192587, -0.44977>,
  <0.41499, -0.352107>,
  <0.55508, -0.295029>,
  <0.694365, -0.225701>,
  <0.802838, -0.138379>,
  <0.85703, -0.079881>,
  <0.882335, -0.0>,
  <0.852509, 0.071168>,
  <0.794403, 0.148058>,
  <0.683274, 0.221847>,
  <0.532985, 0.287526>,
  <0.394648, 0.366086>,
  <0.214414, 0.437502>,
  <0.134549, 0.473669>,
  <0.097685, 0.454104>,
  <0.076628, 0.430048>,
  <0.044744, 0.365087>,
  <0.146068, 0.324615>,
  <0.228194, 0.270903>,
  <0.282249, 0.205962>,
  <0.314503, 0.158682>,
  <0.340057, 0.111402>,
  <0.350325, 0.060155>,
  <0.352949, 0.0>,
  <0.347272, -0.051678>,
  <0.332889, -0.09747>,
  <0.309366, -0.144514>,
  <0.279142, -0.189325>,
  <0.219038, -0.252814>,
  <0.147705, -0.299461>,
  <-0.000643, -0.368027>
  rotate -x*90
  material {
    Eagle_helmettexture
  }
  photons {
    collect off
  }
  scale <0.527692, 0.548794, 0.517621>
  rotate <90.0, -12.709352, 0.0>
  translate  <-1.027293, 0.49453, -0.899949>
}
#declare Eagle_visorframe1 = intersection {
  sphere { // helmetintersect1
    <0,0,0>,1
    material {
      Eagle_helmettexture
    }
    photons {
      collect off
    }
    scale <0.444671, 0.403538, 0.430767>
    translate  <-0.614097, 0.0, -0.847994>
  }
  object { Eagle_helmetframecut1 }
  photons {
    collect off
  }
  rotate -38.073509*y
  translate  <-1.139438, 0.0, -0.059711>
}
#declare Eagle_man5_group1 = union {
  object { Eagle_suitneck1 }
  object { Eagle_neckring1 }
  box { // backpack1
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_packtexture
    }
    photons {
      collect off
    }
    scale <0.141443, 0.483424, 0.715796>
    rotate -38.073509*y
    translate  <-0.020462, 0.0, -1.546164>
  }
  sphere { // helmet1
    <0,0,0>,1
    material {
      Eagle_helmettexture
    }
    photons {
      collect off
    }
    scale <0.419064, 0.380299, 0.40596>
    rotate -38.073509*y
    translate  <-1.099987, 0.0, -1.105799>
  }
  cylinder { // helmetbottom1
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_helmettexture
    }
    photons {
      collect off
    }
    scale <0.317301, 0.317301, 0.2>
    rotate -53.339344*y
    translate  <-0.842205, 0.0, -1.305067>
  }
  sphere { // visor1
    <0,0,0>,1
    material {
      Eagle_visortexture
    }
    photons {
      collect off
    }
    scale <0.327853, 0.337682, 0.30218>
    rotate -50.555511*y
    translate  <-1.194657, 0.0, -1.200003>
  }
  object { Eagle_chestpack1 }
  object { Eagle_cheststrap2 }
  object { Eagle_cheststrap3 }
  object { Eagle_visorframe1 }
  cylinder { // visorswivel1
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_neckringtexture
    }
    photons {
      collect off
    }
    scale <0.01414, 0.01414, 0.84>
    rotate <90.0, -38.073509, 0.0>
    translate  <-1.131079, 0.419904, -1.097484>
  }
  box { // helmetstripes9
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate -14.559975*y
    translate  <-1.492287, 0.0, -1.202898>
  }
  box { // helmetstripes10
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate -66.19397*y
    translate  <-1.182235, 0.0, -1.500233>
  }
  box { // helmetstripes11
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate -66.19397*y
    translate  <-1.182235, 0.0, -1.500233>
  }
  box { // helmetstripes12
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-23.863575, -64.277084, 21.402306>
    translate  <-1.17869, -0.132887, -1.480565>
  }
  box { // helmetstripes13
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <32.930004, -59.866936, -42.456177>
    translate  <-1.170966, 0.141306, -1.48132>
  }
  box { // helmetstripes14
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-2.157874, -14.336593, 11.936019>
    translate  <-1.48527, -0.093734, -1.202101>
  }
  box { // helmetstripes15
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <6.297852, -13.368946, -21.895948>
    translate  <-1.486309, 0.092356, -1.201375>
  }
  box { // helmetstripes16
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-2.478497, -13.222614, 23.647978>
    translate  <-1.448285, -0.189605, -1.193053>
  }
  box { // helmetstripes17
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_straptexture
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.038406, 0.027936, 0.009851>
    rotate <-0.437556, -14.622518, -30.641428>
    translate  <-1.448426, 0.182122, -1.193904>
  }
  material {
    suittexture
  }
  photons {
    collect off
  }
  scale 0.39
  rotate <-0.0, 38.073509, 90.0>
  translate  <-0.591178, -23.835495, -0.998412>
}
#declare Eagle_cockpitdetails2 = union {
  object { Eagle_backwall }
  object { Eagle_Light002 }
  object { Eagle_maindoor }
  object { Eagle_man5_group }
  object { Eagle_man5_group1 }
  box { // instpanel
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_instpaneltext
      scale <1.99953, 2.023088, 1.0>
      translate <-0.998408, -1.017105, 0.000000>
    }
    photons {
      collect off
    }
    scale <0.220585, 0.082719, 0.036706>
    rotate <90.0, -0.0, -180.0>
    translate  <2.098294, -24.959033, -1.549844>
  }
  box { // instpanel1
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_instpaneltext
      scale <1.99953, 2.023088, 1.0>
      translate <-0.998408, -1.017105, 0.000000>
    }
    photons {
      collect off
    }
    scale <0.220585, 0.082719, 0.036706>
    rotate <90.0, -0.0, -180.0>
    translate  <-0.598429, -25.067992, -1.547063>
  }
  photons {
    collect off
  }
}
#declare Eagle_cmcapsulemain = union {
  sphere { // thrustsph
    <0,0,0>,1
    material {
      Eagle_thrustcenter
    }
    photons {
      collect off
    }
    scale <0.2, 0.2, 0.08>
    translate  <0.820966, -24.736272, -0.537846>
  }
  sphere { // thrustsph1
    <0,0,0>,1
    material {
      Eagle_thrustcenter
    }
    photons {
      collect off
    }
    scale <0.2, 0.2, 0.08>
    translate  <0.820966, -24.736035, -4.267262>
  }
  sphere { // thrustsph2
    <0,0,0>,1
    material {
      Eagle_thrustcenter
    }
    photons {
      collect off
    }
    scale <0.2, 0.2, 0.08>
    rotate -90.0*y
    translate  <3.932962, -24.73447, -2.40441>
  }
  sphere { // thrustsph3
    <0,0,0>,1
    material {
      Eagle_thrustcenter
    }
    photons {
      collect off
    }
    scale <0.2, 0.2, 0.08>
    rotate -90.0*y
    translate  <-2.295499, -24.736227, -2.404016>
  }
  object { Eagle_capsule200 }
  object { Eagle_cockpitdetails2 }
  photons {
    collect off
  }
  translate  <-0.093915, 0.115587, 0.0>
}
#declare Eagle = union {
  object { Eagle_rearframe }
  object { Eagle_frontframe }
  object { Eagle_engines }
  object { Eagle_gearlf }
  object { Eagle_gearrf }
  object { Eagle_gearrr }
  object { Eagle_gearlr }
  object { podrr }
  object { podlf }
  object { podlr }
  object { podrf }
  object { Eagle_overframeassembly }
  object { Eagle_cmcapsulemain }
  material {
    Eagle_basic
  }
  photons {
    collect off
  }
  translate  <0.093915, -0.115587, 0.0>
}
#declare Eagle_topcargodetail1 = prism {
  linear_sweep
  linear_spline
  -0.6,0.0
  5  // control points
  <-0.298117, -0.020474>,
  <0.298117, -0.020474>,
  <0.09842, 0.090476>,
  <-0.298117, 0.090476>,
  <-0.298117, -0.020474>
  rotate -x*90
  material {
    Eagle_maglocks
  }
  photons {
    collect off
  }
  rotate <112.727882, 0.0, -90.0>
  translate  <-2.348714, -5.418276, 1.581411>
}
#declare Eagle_topcargodetail2 = prism {
  linear_sweep
  linear_spline
  -0.6,0.0
  5  // control points
  <-0.298117, -0.020474>,
  <0.298117, -0.020474>,
  <0.09842, 0.090476>,
  <-0.298117, 0.090476>,
  <-0.298117, -0.020474>
  rotate -x*90
  material {
    Eagle_maglocks
  }
  photons {
    collect off
  }
  rotate <67.144135, -0.0, 90.0>
  translate  <-2.901542, -7.096868, 1.348382>
}
#declare Eagle_topcargodetail3 = prism {
  linear_sweep
  linear_spline
  -0.6,0.0
  5  // control points
  <-0.298117, -0.020474>,
  <0.298117, -0.020474>,
  <0.09842, 0.090476>,
  <-0.298117, 0.090476>,
  <-0.298117, -0.020474>
  rotate -x*90
  material {
    Eagle_maglocks
  }
  photons {
    collect off
  }
  rotate <67.144135, -0.0, -90.0>
  translate  <2.885948, -5.414286, 1.356311>
}
#declare Eagle_topcargodetail4 = prism {
  linear_sweep
  linear_spline
  -0.6,0.0
  5  // control points
  <-0.298117, -0.020474>,
  <0.298117, -0.020474>,
  <0.09842, 0.090476>,
  <-0.298117, 0.090476>,
  <-0.298117, -0.020474>
  rotate -x*90
  material {
    Eagle_maglocks
  }
  photons {
    collect off
  }
  rotate <112.618629, -0.0, 90.0>
  translate  <2.333841, -7.107678, 1.583232>
}
#declare Eagle_cargodetail = union {
  box { // Cube174
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.874696, -0.298636, 1.34146>
  }
  box { // Cube175
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.300893, -0.298636, 1.165884>
  }
  box { // Cube176
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.445309, -0.298636, 1.522588>
  }
  box { // Cube177
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.009831, -0.298636, 1.707257>
  }
  box { // Cube178
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.383264, 1.455076, 1.131492>
  }
  box { // Cube179
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.383264, 7.101216, 1.132454>
  }
  box { // Cube180
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.008941, 7.101216, 1.708053>
  }
  box { // Cube181
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.009956, 1.455076, 1.708105>
  }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  scale <1.0, 1.3, 1.0>
  rotate 180.0*z
  translate  <0.004538, -0.776549, -0.00015>
}
#declare Eagle_cargodetail2 = union {
  box { // Cube182
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.874696, -0.298636, 1.34146>
  }
  box { // Cube183
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.300893, -0.298636, 1.165884>
  }
  box { // Cube184
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.445309, -0.298636, 1.522588>
  }
  box { // Cube185
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.009831, -0.298636, 1.707257>
  }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  scale <1.0, 1.3, 1.0>
  rotate 180.0*z
  translate  <0.004538, -12.676583, -0.000116>
}
#declare Eagle_cargodetail3 = union {
  box { // Cube186
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.874696, -0.298636, 1.34146>
  }
  box { // Cube187
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.300893, -0.298636, 1.165884>
  }
  box { // Cube188
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.445309, -0.298636, 1.522588>
  }
  box { // Cube189
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.009831, -0.298636, 1.707257>
  }
  box { // Cube190
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.368285, 1.455185, 1.131643>
  }
  box { // Cube191
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.368285, 7.101674, 1.129362>
  }
  box { // Cube192
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.011267, 7.101674, 1.705252>
  }
  box { // Cube193
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.009897, 1.455185, 1.705498>
  }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  scale <1.0, 1.3, 1.0>
  translate  -11.9*y
}
#declare Eagle_cargodetail4 = union {
  box { // Cube194
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.874696, -0.298636, 1.34146>
  }
  box { // Cube195
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <3.300893, -0.298636, 1.165884>
  }
  box { // Cube196
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.445309, -0.298636, 1.522588>
  }
  box { // Cube197
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.21, 0.25, 0.04>
    rotate 22.818663*y
    translate  <2.009831, -0.298636, 1.707257>
  }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  scale <1.0, 1.3, 1.0>
}
#declare Eagle_cargodetail5 = union {
  box { // frame155
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -3.13466, 1.301668>
  }
  box { // frame156
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -1.881097, 1.302103>
  }
  photons {
    collect off
  }
  translate  -7.495*y
}
#declare Eagle_cargodetail6 = union {
  box { // frame157
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -3.13466, 1.301668>
  }
  box { // frame158
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -1.881097, 1.302103>
  }
  photons {
    collect off
  }
  rotate 180.0*z
  translate  -12.51*y
}
#declare Eagle_cargodetail7 = union {
  box { // frame159
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -3.13466, 1.301668>
  }
  box { // frame160
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -1.881097, 1.302103>
  }
  photons {
    collect off
  }
  rotate 180.0*z
  translate  -5.165*y
}
#declare Eagle_cargodetail8 = union {
  box { // frame161
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -3.13466, 1.301668>
  }
  box { // frame
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.5, 0.05, 0.013>
    rotate <-0.0, 22.887465, -0.0>
    translate  <2.713721, -1.881097, 1.302103>
  }
  photons {
    collect off
  }
  translate  -0.15*y
}
#declare Eagle_door4 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  37  // control points
  <-0.930889, -0.982129>,
  <-0.887723, -0.999993>,
  <-0.426343, -0.999939>,
  <-0.383019, -0.983897>,
  <-0.360122, -0.93995>,
  <-0.300296, -0.700014>,
  <0.299491, -0.699847>,
  <0.356123, -0.924957>,
  <0.385567, -0.978715>,
  <0.446822, -0.999995>,
  <0.853808, -0.999999>,
  <0.927581, -0.972356>,
  <0.949998, -0.908718>,
  <0.949998, -0.429258>,
  <0.9318, -0.367579>,
  <0.875041, -0.329351>,
  <0.325006, -0.14999>,
  <0.324964, 0.149981>,
  <0.895234, 0.338738>,
  <0.938388, 0.371354>,
  <0.950808, 0.419616>,
  <0.951229, 0.922506>,
  <0.931413, 0.975608>,
  <0.869798, 1.0>,
  <-0.885973, 1.0>,
  <-0.933555, 0.984659>,
  <-0.949998, 0.934974>,
  <-0.949998, 0.418879>,
  <-0.940517, 0.364443>,
  <-0.899991, 0.334571>,
  <-0.325028, 0.149968>,
  <-0.325026, -0.149948>,
  <-0.89808, -0.335891>,
  <-0.936163, -0.367648>,
  <-0.949998, -0.422347>,
  <-0.949998, -0.934996>,
  <-0.930889, -0.982129>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
}
#declare Eagle_door5 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  17  // control points
  <-0.8648, -0.89747>,
  <-0.434273, -0.897611>,
  <-0.336703, -0.659022>,
  <0.3358, -0.658871>,
  <0.420522, -0.897716>,
  <0.871134, -0.903662>,
  <0.853143, -0.392033>,
  <0.256077, -0.195764>,
  <0.256044, 0.189646>,
  <0.853583, 0.406454>,
  <0.853821, 0.897411>,
  <-0.853098, 0.896487>,
  <-0.853377, 0.404754>,
  <-0.256094, 0.189634>,
  <-0.256093, -0.195727>,
  <-0.852596, -0.391285>,
  <-0.8648, -0.89747>
  rotate -x*90
  material {
    Eagle_unknown
  }
  photons {
    collect off
  }
  translate  0.22*z
}
#declare Eagle_handle = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.099883, -0.200483>,
  <0.099883, -0.249686>,
  <0.099883, 0.249686>,
  <-0.099883, 0.200483>,
  <-0.099883, -0.200483>
  rotate -x*90
  material {
    Eagle_unknown
  }
  photons {
    collect off
  }
  rotate <-180.0, -0.0, 180.0>
  translate  <-0.868148, -0.008358, -6.154152>
}
#declare Eagle_handle1 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  5  // control points
  <-0.099883, -0.200483>,
  <0.099883, -0.249686>,
  <0.099883, 0.249686>,
  <-0.099883, 0.200483>,
  <-0.099883, -0.200483>
  rotate -x*90
  material {
    Eagle_unknown
  }
  photons {
    collect off
  }
  rotate <-0.0, 0.0, 0.0>
  translate  <0.859925, -0.001776, 0.154053>
}
#declare Eagle_cargodetail9 = union {
  object { Eagle_door4 }
  object { Eagle_door5 }
  object { Eagle_handle }
  object { Eagle_handle1 }
  photons {
    collect off
  }
  rotate <90.0, 0.0, -90.0>
  translate  <-3.000049, -6.259976, -0.299013>
}
#declare Eagle_door6 = prism {
  linear_sweep
  linear_spline
  -0.3,0.0
  37  // control points
  <-0.930889, -0.982129>,
  <-0.887723, -0.999993>,
  <-0.426343, -0.999939>,
  <-0.383019, -0.983897>,
  <-0.360122, -0.93995>,
  <-0.300296, -0.700014>,
  <0.299491, -0.699847>,
  <0.356123, -0.924957>,
  <0.385567, -0.978715>,
  <0.446822, -0.999995>,
  <0.853808, -0.999999>,
  <0.927581, -0.972356>,
  <0.949998, -0.908718>,
  <0.949998, -0.429258>,
  <0.9318, -0.367579>,
  <0.875041, -0.329351>,
  <0.325006, -0.14999>,
  <0.324964, 0.149981>,
  <0.895234, 0.338738>,
  <0.938388, 0.371354>,
  <0.950808, 0.419616>,
  <0.951229, 0.922506>,
  <0.931413, 0.975608>,
  <0.869798, 1.0>,
  <-0.885973, 1.0>,
  <-0.933555, 0.984659>,
  <-0.949998, 0.934974>,
  <-0.949998, 0.418879>,
  <-0.940517, 0.364443>,
  <-0.899991, 0.334571>,
  <-0.325028, 0.149968>,
  <-0.325026, -0.149948>,
  <-0.89808, -0.335891>,
  <-0.936163, -0.367648>,
  <-0.949998, -0.422347>,
  <-0.949998, -0.934996>,
  <-0.930889, -0.982129>
  rotate -x*90
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
}
#declare Eagle_door7 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  17  // control points
  <-0.8648, -0.89747>,
  <-0.434273, -0.897611>,
  <-0.336703, -0.659022>,
  <0.3358, -0.658871>,
  <0.420522, -0.897716>,
  <0.871134, -0.903662>,
  <0.853143, -0.392033>,
  <0.256077, -0.195764>,
  <0.256044, 0.189646>,
  <0.853583, 0.406454>,
  <0.853821, 0.897411>,
  <-0.853098, 0.896487>,
  <-0.853377, 0.404754>,
  <-0.256094, 0.189634>,
  <-0.256093, -0.195727>,
  <-0.852596, -0.391285>,
  <-0.8648, -0.89747>
  rotate -x*90
  material {
    Eagle_unknown
  }
  photons {
    collect off
  }
  translate  0.22*z
}
#declare Eagle_cargodetail10 = union {
  object { Eagle_door6 }
  object { Eagle_door7 }
  photons {
    collect off
  }
  rotate <90.0, 0.0, 90.0>
  translate  <2.99938, -6.259976, -0.299883>
}
#declare Eagle_cgbod = prism {
  linear_sweep
  linear_spline
  -12.67,0.0
  90  // control points
  <-3.348638, -1.799999>,
  <-3.013596, -1.800005>,
  <-2.899722, -1.599838>,
  <2.898901, -1.600811>,
  <3.033913, -1.800103>,
  <3.352203, -1.800108>,
  <3.418745, -1.67499>,
  <3.474976, -1.299963>,
  <3.399988, -1.300017>,
  <3.399975, -0.800034>,
  <3.300043, -0.800013>,
  <3.324405, -0.770184>,
  <3.300041, -0.740355>,
  <3.32711, -0.705684>,
  <3.300038, -0.6656>,
  <3.329813, -0.628217>,
  <3.300034, -0.590834>,
  <3.327103, -0.550742>,
  <3.300032, -0.505237>,
  <3.324394, -0.473331>,
  <3.30003, -0.427539>,
  <3.324392, -0.388047>,
  <3.300028, -0.345892>,
  <3.329804, -0.310173>,
  <3.300026, -0.266517>,
  <3.327094, -0.230846>,
  <3.300022, -0.187249>,
  <3.321677, -0.148835>,
  <3.30002, -0.105007>,
  <3.324383, -0.069253>,
  <3.300018, -0.033499>,
  <3.329793, 0.003647>,
  <3.300014, 0.038962>,
  <3.329791, 0.072353>,
  <3.300013, 0.10033>,
  <3.400057, 0.100128>,
  <3.399937, 0.799961>,
  <3.597992, 0.800162>,
  <3.623028, 0.803832>,
  <3.642242, 0.813189>,
  <3.667164, 0.849457>,
  <3.674274, 0.89777>,
  <3.663782, 0.935217>,
  <3.642416, 0.967777>,
  <3.6016, 0.999896>,
  <1.7, 1.799999>,
  <1.456541, 1.719789>,
  <-1.491109, 1.720071>,
  <-1.700083, 1.799999>,
  <-3.600012, 1.00103>,
  <-3.649242, 0.956806>,
  <-3.664493, 0.928844>,
  <-3.671793, 0.895912>,
  <-3.666743, 0.862739>,
  <-3.653739, 0.832549>,
  <-3.6282, 0.809135>,
  <-3.614522, 0.802661>,
  <-3.598687, 0.800055>,
  <-3.40002, 0.800097>,
  <-3.400015, 0.100473>,
  <-3.299912, 0.100168>,
  <-3.330531, 0.066422>,
  <-3.299902, 0.037549>,
  <-3.333304, -0.000537>,
  <-3.299892, -0.033055>,
  <-3.330509, -0.07007>,
  <-3.299878, -0.109125>,
  <-3.330496, -0.15054>,
  <-3.299867, -0.188786>,
  <-3.330486, -0.231788>,
  <-3.299859, -0.269223>,
  <-3.330476, -0.310376>,
  <-3.299847, -0.345962>,
  <-3.330456, -0.389895>,
  <-3.299822, -0.425839>,
  <-3.327649, -0.470757>,
  <-3.299799, -0.502447>,
  <-3.32763, -0.539845>,
  <-3.299777, -0.575062>,
  <-3.330394, -0.61111>,
  <-3.299767, -0.645666>,
  <-3.330383, -0.688492>,
  <-3.299754, -0.723531>,
  <-3.330368, -0.76531>,
  <-3.299732, -0.800139>,
  <-3.399759, -0.799912>,
  <-3.39988, -1.299956>,
  <-3.475116, -1.300052>,
  <-3.415024, -1.70001>,
  <-3.348638, -1.799999>
  rotate -x*90
  photons {
    collect off
  }
  rotate 90.0*x
}
#declare Eagle_cgbod2 = prism {
  linear_sweep
  linear_spline
  -2.3,0.0
  12  // control points
  <3.399937, 0.799961>,
  <3.597992, 0.800162>,
  <3.623028, 0.803832>,
  <3.642242, 0.813189>,
  <3.667164, 0.849457>,
  <3.674274, 0.89777>,
  <3.663782, 0.935217>,
  <3.642416, 0.967777>,
  <3.6016, 0.999896>,
  <2.240008, 1.553628>,
  <2.135201, 1.398398>,
  <3.399937, 0.799961>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.109347, 1.156643, 1.0>
  rotate 90.0*x
  translate  <-0.367082, -5.117193, -0.125453>
}
#declare Eagle_cgbod3 = prism {
  linear_sweep
  linear_spline
  -2.3,0.0
  12  // control points
  <3.399937, 0.799961>,
  <3.597992, 0.800162>,
  <3.623028, 0.803832>,
  <3.642242, 0.813189>,
  <3.667164, 0.849457>,
  <3.674274, 0.89777>,
  <3.663782, 0.935217>,
  <3.642416, 0.967777>,
  <3.6016, 0.999896>,
  <2.226014, 1.559844>,
  <2.119297, 1.388136>,
  <3.399937, 0.799961>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.109347, 1.156643, 1.0>
  rotate <90.0, -0.0, -180.0>
  translate  <0.367574, -7.417182, -0.126918>
}
#declare Eagle_cargounion = union {
  box { // cgdet
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.3, 1.8, 0.5>
    translate  <-3.100083, -6.335, -0.35>
  }
  box { // cgdet2
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.3, 1.8, 0.5>
    translate  <3.100083, -6.335, -0.35>
  }
  object { Eagle_cgbod }
  object { Eagle_cgbod2 }
  object { Eagle_cgbod3 }
  photons {
    collect off
  }
}
#declare Eagle_cgwincut1 = prism {
  linear_sweep
  linear_spline
  -3.8,0.0
  13  // control points
  <0.360538, 0.096331>,
  <-0.360304, 0.096318>,
  <-0.408177, 0.129934>,
  <-0.468599, 0.140512>,
  <-0.468458, 0.163907>,
  <-0.504285, 0.163906>,
  <-0.504301, 0.235133>,
  <0.504569, 0.234303>,
  <0.504493, 0.16398>,
  <0.468401, 0.164009>,
  <0.468361, 0.140512>,
  <0.40801, 0.130948>,
  <0.360538, 0.096331>
  rotate -x*90
  photons {
    collect off
  }
  translate  <2.597442, 0.0, 1.247086>
}
#declare Eagle_windowcut = union {
  box { // cgwin1
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_windowblack
    }
    photons {
      collect off
    }
    scale <0.363008, 0.007541, 1.9>
    translate  <2.595487, 0.097315, 3.146924>
  }
  object { Eagle_cgwincut1 }
  photons {
    collect off
  }
  rotate <90.0, 23.057165, 0.0>
  translate  <0.261037, 0.47, 2.242385>
}
#declare Eagle_cgwincut2 = prism {
  linear_sweep
  linear_spline
  -3.8,0.0
  13  // control points
  <0.360538, 0.096331>,
  <-0.360304, 0.096318>,
  <-0.408177, 0.129934>,
  <-0.468599, 0.140512>,
  <-0.468458, 0.163907>,
  <-0.504285, 0.163906>,
  <-0.504301, 0.235133>,
  <0.504569, 0.234303>,
  <0.504493, 0.16398>,
  <0.468401, 0.164009>,
  <0.468361, 0.140512>,
  <0.40801, 0.130948>,
  <0.360538, 0.096331>
  rotate -x*90
  photons {
    collect off
  }
  translate  <2.597442, 0.0, 1.247086>
}
#declare Eagle_windowcut1 = union {
  box { // cgwin2
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_windowblack
    }
    photons {
      collect off
    }
    scale <0.363008, 0.007541, 1.9>
    translate  <2.595487, 0.097315, 3.146924>
  }
  object { Eagle_cgwincut2 }
  photons {
    collect off
  }
  rotate <90.0, 23.057165, 0.0>
  translate  <0.261014, -6.857733, 2.242422>
}
#declare Eagle_cgwincut3 = prism {
  linear_sweep
  linear_spline
  -3.8,0.0
  13  // control points
  <0.360538, 0.096331>,
  <-0.360304, 0.096318>,
  <-0.408177, 0.129934>,
  <-0.468599, 0.140512>,
  <-0.468458, 0.163907>,
  <-0.504285, 0.163906>,
  <-0.504301, 0.235133>,
  <0.504569, 0.234303>,
  <0.504493, 0.16398>,
  <0.468401, 0.164009>,
  <0.468361, 0.140512>,
  <0.40801, 0.130948>,
  <0.360538, 0.096331>
  rotate -x*90
  photons {
    collect off
  }
  translate  <2.597442, 0.0, 1.247086>
}
#declare Eagle_windowcut2 = union {
  box { // cgwin3
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_windowblack
    }
    photons {
      collect off
    }
    scale <0.363008, 0.007541, 1.9>
    translate  <2.595487, 0.097315, 3.146924>
  }
  object { Eagle_cgwincut3 }
  photons {
    collect off
  }
  rotate <90.0, 23.057165, -180.0>
  translate  <-0.272043, -5.823, 2.242308>
}
#declare Eagle_cgwincut4 = prism {
  linear_sweep
  linear_spline
  -3.8,0.0
  13  // control points
  <0.360538, 0.096331>,
  <-0.360304, 0.096318>,
  <-0.408177, 0.129934>,
  <-0.468599, 0.140512>,
  <-0.468458, 0.163907>,
  <-0.504285, 0.163906>,
  <-0.504301, 0.235133>,
  <0.504569, 0.234303>,
  <0.504493, 0.16398>,
  <0.468401, 0.164009>,
  <0.468361, 0.140512>,
  <0.40801, 0.130948>,
  <0.360538, 0.096331>
  rotate -x*90
  photons {
    collect off
  }
  translate  <2.597442, 0.0, 1.247086>
}
#declare Eagle_windowcut3 = union {
  box { // cgwin4
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_windowblack
    }
    photons {
      collect off
    }
    scale <0.363008, 0.007541, 1.9>
    translate  <2.595487, 0.097315, 3.146924>
  }
  object { Eagle_cgwincut4 }
  photons {
    collect off
  }
  rotate <90.0, 23.057165, -180.0>
  translate  <-0.271426, -13.151913, 2.242405>
}
#declare Eagle_cutoutss = union {
  box { // cgdet5
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.1, 1.8, 0.3>
    translate  <-3.499999, -6.335, -1.501006>
  }
  box { // cgdet6
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.1, 1.8, 0.3>
    translate  <3.499999, -6.335, -1.501006>
  }
  box { // cgdet7
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_unknown
    }
    photons {
      collect off
    }
    scale <0.08, 1.15, 1.1>
    translate  <-3.324466, -6.267193, -0.300153>
  }
  box { // cgdet8
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_unknown
    }
    photons {
      collect off
    }
    scale <0.08, 1.15, 1.1>
    translate  <3.324466, -6.267193, -0.300153>
  }
  object { Eagle_windowcut }
  object { Eagle_windowcut1 }
  object { Eagle_windowcut2 }
  object { Eagle_windowcut3 }
  photons {
    collect off
  }
}
#declare Eagle_cargomainbody = difference {
  object { Eagle_cargounion }
  object { Eagle_cutoutss }
  photons {
    collect off
  }
}
#declare Eagle_lowereng7 = lathe {
  linear_spline
  34  // control points
  <0.003073, 0.017965>,
  <0.419896, 0.014492>,
  <0.420561, -0.268833>,
  <0.479319, -0.361266>,
  <0.52813, -0.46288>,
  <0.548694, -0.537416>,
  <0.566765, -0.614304>,
  <0.584424, -0.683155>,
  <0.592971, -0.75116>,
  <0.598692, -0.811755>,
  <0.649492, -0.811742>,
  <0.645906, -0.767712>,
  <0.635734, -0.767714>,
  <0.632675, -0.741683>,
  <0.643952, -0.741697>,
  <0.63883, -0.67635>,
  <0.626628, -0.609821>,
  <0.609875, -0.532569>,
  <0.589938, -0.462775>,
  <0.578475, -0.42533>,
  <0.571948, -0.404199>,
  <0.553118, -0.404699>,
  <0.53433, -0.365172>,
  <0.555821, -0.36611>,
  <0.546971, -0.347055>,
  <0.527873, -0.346719>,
  <0.506019, -0.305101>,
  <0.527166, -0.304682>,
  <0.487167, -0.243508>,
  <0.51657, -0.219443>,
  <0.608805, -0.218094>,
  <0.63135, -0.192206>,
  <0.632015, 0.084895>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <1.200004, -2.007458, -1.684778>
}
#declare Eagle_TraSwp120 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -48.080132, -90.0>
  translate  <0.956583, 0.040198, 0.584688>
}
#declare Eagle_TraSwp121 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -85.859726, 90.0>
  translate  <0.906652, -0.04767, 0.830071>
}
#declare Eagle_cgpadujoint = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  17  // control points
  <-0.615385, -0.415954>,
  <-0.524644, -0.687678>,
  <-0.336182, -0.864672>,
  <0.014245, -0.928775>,
  <0.407407, -0.878917>,
  <0.57037, -0.722222>,
  <0.672365, -0.444444>,
  <0.65812, 0.273504>,
  <0.523255, 0.273504>,
  <0.519607, -0.338319>,
  <0.326038, -0.590467>,
  <0.009898, -0.701822>,
  <-0.263507, -0.599501>,
  <-0.456677, -0.324786>,
  <-0.453704, 0.273504>,
  <-0.615385, 0.273504>,
  <-0.615385, -0.415954>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.12349
  rotate <-90.0, -0.0, -0.0>
  translate  <1.058201, -0.610675, 0.498508>
}
#declare Eagle_ANKLE11 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  5  // control points
  <-1.303669, -0.15>,
  <0.7, -0.15>,
  <0.514271, 0.107187>,
  <0.170744, 0.107187>,
  <-1.303669, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.006207, 1.003103>
  rotate <90.0, 0.0, -90.0>
  translate  <1.103684, -0.14122, 0.380834>
}
#declare Eagle_cgpadfoot = union {
  object { Eagle_ANKLE11 }
  box { // Cube216
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.002102, 0.30293, 0.035>
    rotate -90.0*z
    translate  <1.052313, 0.160843, 0.195476>
  }
  box { // Cube227
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube228
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube229
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube232
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.051789, 1.011516, 0.125>
  }
  box { // Cube235
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube236
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  photons {
    collect off
  }
  translate  <-0.007113, -0.128313, 0.017736>
}
#declare Eagle_cargopads = union {
  cylinder { // Cylndr160
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.034402, 0.034402, 0.196585>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.961653, -0.550591, 0.522398>
  }
  cylinder { // Cylndr161
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 0.4>
    translate  <1.060385, -0.547595, 0.595373>
  }
  cylinder { // Cylndr162
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.878836, 0.274438, 0.808013>
  }
  cylinder { // Cylndr163
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.8802, -0.33176, 0.854188>
  }
  cylinder { // Cylndr164
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.265019>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.923572, -0.206769, 0.358678>
  }
  object { Eagle_TraSwp120 }
  object { Eagle_TraSwp121 }
  cylinder { // Cylndr159
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    rotate <-0.0, -0.0, 0.0>
    translate  <1.059976, -0.547694, 0.682682>
  }
  object { Eagle_cgpadujoint }
  object { Eagle_cgpadfoot }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate 90.0*z
  translate  <-1.763719, -9.896014, -2.679717>
}
#declare Eagle_TraSwp122 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -48.080132, -90.0>
  translate  <0.956583, 0.040198, 0.584688>
}
#declare Eagle_TraSwp123 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -85.859726, 90.0>
  translate  <0.906652, -0.04767, 0.830071>
}
#declare Eagle_cgpadujoint1 = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  17  // control points
  <-0.615385, -0.415954>,
  <-0.524644, -0.687678>,
  <-0.336182, -0.864672>,
  <0.014245, -0.928775>,
  <0.407407, -0.878917>,
  <0.57037, -0.722222>,
  <0.672365, -0.444444>,
  <0.65812, 0.273504>,
  <0.523255, 0.273504>,
  <0.519607, -0.338319>,
  <0.326038, -0.590467>,
  <0.009898, -0.701822>,
  <-0.263507, -0.599501>,
  <-0.456677, -0.324786>,
  <-0.453704, 0.273504>,
  <-0.615385, 0.273504>,
  <-0.615385, -0.415954>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.12349
  rotate <-90.0, -0.0, -0.0>
  translate  <1.058201, -0.610675, 0.498508>
}
#declare Eagle_ANKLE12 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  5  // control points
  <-1.303669, -0.15>,
  <0.7, -0.15>,
  <0.514271, 0.107187>,
  <0.170744, 0.107187>,
  <-1.303669, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.006207, 1.003103>
  rotate <90.0, 0.0, -90.0>
  translate  <1.103684, -0.14122, 0.380834>
}
#declare Eagle_cgpadfoot1 = union {
  object { Eagle_ANKLE12 }
  box { // Cube217
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.002102, 0.30293, 0.035>
    rotate -90.0*z
    translate  <1.052313, 0.160843, 0.195476>
  }
  box { // Cube230
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube231
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube233
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube234
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.051789, 1.011516, 0.125>
  }
  box { // Cube237
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube238
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  photons {
    collect off
  }
  translate  <-0.007113, -0.128313, 0.017736>
}
#declare Eagle_cargopads1 = union {
  cylinder { // Cylndr165
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.034402, 0.034402, 0.196585>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.961653, -0.550591, 0.522398>
  }
  cylinder { // Cylndr166
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 0.4>
    translate  <1.060385, -0.547595, 0.595373>
  }
  cylinder { // Cylndr167
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.878836, 0.274438, 0.808013>
  }
  cylinder { // Cylndr168
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.8802, -0.33176, 0.854188>
  }
  cylinder { // Cylndr169
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.265019>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.923572, -0.206769, 0.358678>
  }
  object { Eagle_TraSwp122 }
  object { Eagle_TraSwp123 }
  cylinder { // Cylndr170
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    rotate <-0.0, -0.0, 0.0>
    translate  <1.059976, -0.547694, 0.682682>
  }
  object { Eagle_cgpadujoint1 }
  object { Eagle_cgpadfoot1 }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate -90.0*z
  translate  <1.762699, -7.785914, -2.679717>
}
#declare Eagle_TraSwp124 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -48.080132, -90.0>
  translate  <0.956583, 0.040198, 0.584688>
}
#declare Eagle_TraSwp125 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -85.859726, 90.0>
  translate  <0.906652, -0.04767, 0.830071>
}
#declare Eagle_cgpadujoint2 = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  17  // control points
  <-0.615385, -0.415954>,
  <-0.524644, -0.687678>,
  <-0.336182, -0.864672>,
  <0.014245, -0.928775>,
  <0.407407, -0.878917>,
  <0.57037, -0.722222>,
  <0.672365, -0.444444>,
  <0.65812, 0.273504>,
  <0.523255, 0.273504>,
  <0.519607, -0.338319>,
  <0.326038, -0.590467>,
  <0.009898, -0.701822>,
  <-0.263507, -0.599501>,
  <-0.456677, -0.324786>,
  <-0.453704, 0.273504>,
  <-0.615385, 0.273504>,
  <-0.615385, -0.415954>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.12349
  rotate <-90.0, -0.0, -0.0>
  translate  <1.058201, -0.610675, 0.498508>
}
#declare Eagle_ANKLE13 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  5  // control points
  <-1.303669, -0.15>,
  <0.7, -0.15>,
  <0.514271, 0.107187>,
  <0.170744, 0.107187>,
  <-1.303669, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.006207, 1.003103>
  rotate <90.0, 0.0, -90.0>
  translate  <1.103684, -0.14122, 0.380834>
}
#declare Eagle_cgpadfoot2 = union {
  object { Eagle_ANKLE13 }
  box { // Cube218
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.002102, 0.30293, 0.035>
    rotate -90.0*z
    translate  <1.052313, 0.160843, 0.195476>
  }
  box { // Cube239
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube240
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube241
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube242
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.051789, 1.011516, 0.125>
  }
  box { // Cube243
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube244
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  photons {
    collect off
  }
  translate  <-0.007113, -0.128313, 0.017736>
}
#declare Eagle_cargopads2 = union {
  cylinder { // Cylndr171
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.034402, 0.034402, 0.196585>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.961653, -0.550591, 0.522398>
  }
  cylinder { // Cylndr172
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 0.4>
    translate  <1.060385, -0.547595, 0.595373>
  }
  cylinder { // Cylndr173
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.878836, 0.274438, 0.808013>
  }
  cylinder { // Cylndr174
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.8802, -0.33176, 0.854188>
  }
  cylinder { // Cylndr175
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.265019>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.923572, -0.206769, 0.358678>
  }
  object { Eagle_TraSwp124 }
  object { Eagle_TraSwp125 }
  cylinder { // Cylndr176
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    rotate <-0.0, -0.0, 0.0>
    translate  <1.059976, -0.547694, 0.682682>
  }
  object { Eagle_cgpadujoint2 }
  object { Eagle_cgpadfoot2 }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate -90.0*z
  translate  <1.755741, -2.67667, -2.679717>
}
#declare Eagle_TraSwp126 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  12  // control points
  <-0.058287, -0.377586>,
  <-0.03765, -0.393115>,
  <-0.0, -0.399975>,
  <0.032185, -0.394956>,
  <0.056249, -0.382824>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.058287, -0.377586>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 2.5>
  rotate <-90.0, -48.080132, -90.0>
  translate  <0.956583, 0.040198, 0.584688>
}
#declare Eagle_TraSwp127 = prism {
  linear_sweep
  linear_spline
  -0.1,0.0
  12  // control points
  <-0.05926, -0.378072>,
  <-0.039595, -0.397005>,
  <-0.0, -0.406203>,
  <0.034616, -0.396901>,
  <0.05868, -0.38331>,
  <0.071372, -0.35519>,
  <0.075012, -0.31998>,
  <0.075012, 0.399975>,
  <-0.075012, 0.399975>,
  <-0.075012, -0.31998>,
  <-0.069207, -0.3514>,
  <-0.05926, -0.378072>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.0, 3.0>
  rotate <90.0, -85.859726, 90.0>
  translate  <0.906652, -0.04767, 0.830071>
}
#declare Eagle_cgpadujoint3 = prism {
  linear_sweep
  linear_spline
  -1.0,0.0
  17  // control points
  <-0.615385, -0.415954>,
  <-0.524644, -0.687678>,
  <-0.336182, -0.864672>,
  <0.014245, -0.928775>,
  <0.407407, -0.878917>,
  <0.57037, -0.722222>,
  <0.672365, -0.444444>,
  <0.65812, 0.273504>,
  <0.523255, 0.273504>,
  <0.519607, -0.338319>,
  <0.326038, -0.590467>,
  <0.009898, -0.701822>,
  <-0.263507, -0.599501>,
  <-0.456677, -0.324786>,
  <-0.453704, 0.273504>,
  <-0.615385, 0.273504>,
  <-0.615385, -0.415954>
  rotate -x*90
  photons {
    collect off
  }
  scale 0.12349
  rotate <-90.0, -0.0, -0.0>
  translate  <1.058201, -0.610675, 0.498508>
}
#declare Eagle_ANKLE14 = prism {
  linear_sweep
  linear_spline
  -0.08,0.0
  5  // control points
  <-1.303669, -0.15>,
  <0.7, -0.15>,
  <0.514271, 0.107187>,
  <0.170744, 0.107187>,
  <-1.303669, -0.15>
  rotate -x*90
  photons {
    collect off
  }
  scale <1.0, 1.006207, 1.003103>
  rotate <90.0, 0.0, -90.0>
  translate  <1.103684, -0.14122, 0.380834>
}
#declare Eagle_cgpadfoot3 = union {
  object { Eagle_ANKLE14 }
  box { // Cube219
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <1.002102, 0.30293, 0.035>
    rotate -90.0*z
    translate  <1.052313, 0.160843, 0.195476>
  }
  box { // Cube245
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.678611, 0.125>
  }
  box { // Cube246
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.677193, 0.125>
  }
  box { // Cube247
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, 0.344834, 0.125>
  }
  box { // Cube248
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.051789, 1.011516, 0.125>
  }
  box { // Cube249
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.344521, 0.125>
  }
  box { // Cube250
    <-1, -1, -1>, <1, 1, 1>
    photons {
      collect off
    }
    scale <0.140958, 0.288923, 0.035>
    rotate -90.0*z
    translate  <1.05, -0.0, 0.125>
  }
  photons {
    collect off
  }
  translate  <-0.007113, -0.128313, 0.017736>
}
#declare Eagle_cargopads3 = union {
  cylinder { // Cylndr177
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.034402, 0.034402, 0.196585>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.961653, -0.550591, 0.522398>
  }
  cylinder { // Cylndr178
    <0,0,1>, <0,0,0>, 1 
    material {
      Eagle_Chrome_Metal1
    }
    photons {
      collect off
    }
    scale <0.115, 0.115, 0.4>
    translate  <1.060385, -0.547595, 0.595373>
  }
  cylinder { // Cylndr179
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.878836, 0.274438, 0.808013>
  }
  cylinder { // Cylndr180
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.35>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.8802, -0.33176, 0.854188>
  }
  cylinder { // Cylndr181
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.04, 0.04, 0.265019>
    rotate <-0.0, 90.0, 0.0>
    translate  <0.923572, -0.206769, 0.358678>
  }
  object { Eagle_TraSwp126 }
  object { Eagle_TraSwp127 }
  cylinder { // Cylndr182
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.17, 0.17, 0.35>
    rotate <-0.0, -0.0, 0.0>
    translate  <1.059976, -0.547694, 0.682682>
  }
  object { Eagle_cgpadujoint3 }
  object { Eagle_cgpadfoot3 }
  material {
    Eagle_lightgrey
  }
  photons {
    collect off
  }
  rotate 90.0*z
  translate  <-1.76567, -4.792461, -2.679717>
}
#declare Eagle_lowereng11 = lathe {
  linear_spline
  34  // control points
  <0.003073, 0.017965>,
  <0.419896, 0.014492>,
  <0.420561, -0.268833>,
  <0.479319, -0.361266>,
  <0.52813, -0.46288>,
  <0.548694, -0.537416>,
  <0.566765, -0.614304>,
  <0.584424, -0.683155>,
  <0.592971, -0.75116>,
  <0.598692, -0.811755>,
  <0.649492, -0.811742>,
  <0.645906, -0.767712>,
  <0.635734, -0.767714>,
  <0.632675, -0.741683>,
  <0.643952, -0.741697>,
  <0.63883, -0.67635>,
  <0.626628, -0.609821>,
  <0.609875, -0.532569>,
  <0.589938, -0.462775>,
  <0.578475, -0.42533>,
  <0.571948, -0.404199>,
  <0.553118, -0.404699>,
  <0.53433, -0.365172>,
  <0.555821, -0.36611>,
  <0.546971, -0.347055>,
  <0.527873, -0.346719>,
  <0.506019, -0.305101>,
  <0.527166, -0.304682>,
  <0.487167, -0.243508>,
  <0.51657, -0.219443>,
  <0.608805, -0.218094>,
  <0.63135, -0.192206>,
  <0.632015, 0.084895>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <-1.226846, -2.008372, -1.684778>
}
#declare Eagle_lowereng12 = lathe {
  linear_spline
  34  // control points
  <0.003073, 0.017965>,
  <0.419896, 0.014492>,
  <0.420561, -0.268833>,
  <0.479319, -0.361266>,
  <0.52813, -0.46288>,
  <0.548694, -0.537416>,
  <0.566765, -0.614304>,
  <0.584424, -0.683155>,
  <0.592971, -0.75116>,
  <0.598692, -0.811755>,
  <0.649492, -0.811742>,
  <0.645906, -0.767712>,
  <0.635734, -0.767714>,
  <0.632675, -0.741683>,
  <0.643952, -0.741697>,
  <0.63883, -0.67635>,
  <0.626628, -0.609821>,
  <0.609875, -0.532569>,
  <0.589938, -0.462775>,
  <0.578475, -0.42533>,
  <0.571948, -0.404199>,
  <0.553118, -0.404699>,
  <0.53433, -0.365172>,
  <0.555821, -0.36611>,
  <0.546971, -0.347055>,
  <0.527873, -0.346719>,
  <0.506019, -0.305101>,
  <0.527166, -0.304682>,
  <0.487167, -0.243508>,
  <0.51657, -0.219443>,
  <0.608805, -0.218094>,
  <0.63135, -0.192206>,
  <0.632015, 0.084895>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <-1.227296, -10.649352, -1.684778>
}
#declare Eagle_lowereng13 = lathe {
  linear_spline
  34  // control points
  <0.003073, 0.017965>,
  <0.419896, 0.014492>,
  <0.420561, -0.268833>,
  <0.479319, -0.361266>,
  <0.52813, -0.46288>,
  <0.548694, -0.537416>,
  <0.566765, -0.614304>,
  <0.584424, -0.683155>,
  <0.592971, -0.75116>,
  <0.598692, -0.811755>,
  <0.649492, -0.811742>,
  <0.645906, -0.767712>,
  <0.635734, -0.767714>,
  <0.632675, -0.741683>,
  <0.643952, -0.741697>,
  <0.63883, -0.67635>,
  <0.626628, -0.609821>,
  <0.609875, -0.532569>,
  <0.589938, -0.462775>,
  <0.578475, -0.42533>,
  <0.571948, -0.404199>,
  <0.553118, -0.404699>,
  <0.53433, -0.365172>,
  <0.555821, -0.36611>,
  <0.546971, -0.347055>,
  <0.527873, -0.346719>,
  <0.506019, -0.305101>,
  <0.527166, -0.304682>,
  <0.487167, -0.243508>,
  <0.51657, -0.219443>,
  <0.608805, -0.218094>,
  <0.63135, -0.192206>,
  <0.632015, 0.084895>,
  <-0.001198, 0.107828>
  rotate <90,0,90>
  material {
    Eagle_aluminum
  }
  photons {
    collect off
  }
  scale <0.985222, 1.0, 1.0>
  translate  <1.200042, -10.649399, -1.684778>
}
#declare Eagle_cargopod = union {
  box { // Eagle_decal23
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_decals2
      scale 1.991354
      translate <-1.001681, -1.001681, 0.000000>
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <0.3, 0.3, 0.1>
    rotate <90.0, -0.0, 90.0>
    translate  <3.30449, -12.252695, 0.445436>
  }
  box { // Eagle_decal22
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_decals2
      scale 1.983801
      translate <-1.009027, -0.996414, 0.000000>
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <0.3, 0.3, 0.1>
    rotate <90.0, -0.0, -90.0>
    translate  <-3.304537, -12.252674, 0.445429>
  }
  box { // Eagle_decal21
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_decals2
      scale 2.010526
      translate <-1.001170, -1.001170, 0.000000>
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <0.3, 0.3, 0.1>
    rotate <90.0, -0.0, -90.0>
    translate  <-3.304537, -0.459039, 0.445429>
  }
  box { // Eagle_decal2
    <-1, -1, -1>, <1, 1, 1>
    material {
      Eagle_decals2
      scale 2.010526
      translate <-1.010526, -1.001170, -0.000000>
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <0.3, 0.3, 0.1>
    rotate <90.0, -0.0, 90.0>
    translate  <3.30449, -0.459039, 0.445429>
  }
  object { Eagle_topcargodetail1 }
  object { Eagle_topcargodetail2 }
  object { Eagle_topcargodetail3 }
  object { Eagle_topcargodetail4 }
  object { Eagle_cargodetail }
  object { Eagle_cargodetail2 }
  object { Eagle_cargodetail3 }
  object { Eagle_cargodetail4 }
  object { Eagle_cargodetail5 }
  object { Eagle_cargodetail6 }
  object { Eagle_cargodetail7 }
  object { Eagle_cargodetail8 }
  object { Eagle_cargodetail9 }
  object { Eagle_cargodetail10 }
  object { Eagle_cargomainbody }
  cylinder { // cgcyl1
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.2>
    rotate <90.0, 0.0, -136.373459>
    translate  <3.063604, -8.237881, -1.699841>
  }
  cylinder { // cgcyl141
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.2>
    rotate <90.0, 0.0, -139.179962>
    translate  <-1.601424, -5.903422, -1.699841>
  }
  cylinder { // cgcyl142
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.2>
    rotate <90.0, 0.0, -40.938866>
    translate  <-1.593142, -6.636641, -1.699841>
  }
  cylinder { // cgcyl143
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 2.2>
    rotate <90.0, 0.0, -40.938866>
    translate  <3.062812, -4.214243, -1.699841>
  }
  cylinder { // cgcyl144
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 4.45>
    rotate <90.0, 0.0, 0.0>
    translate  <1.548314, -4.11841, -1.699841>
  }
  cylinder { // cgcyl145
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 4.45>
    rotate <90.0, 0.0, 0.0>
    translate  <-1.558463, -4.11841, -1.699841>
  }
  cylinder { // cgcyl146
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 6.05>
    rotate <90.0, 0.0, -90.0>
    translate  <3.032191, -8.56685, -1.699841>
  }
  cylinder { // cgcyl147
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 6.05>
    rotate <90.0, 0.0, -90.0>
    translate  <3.032191, -4.11778, -1.699841>
  }
  cylinder { // cgcyl148
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 6.05>
    rotate <90.0, 0.0, -90.0>
    translate  <3.036262, -6.637033, -1.699841>
  }
  cylinder { // cgcyl149
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 6.05>
    rotate <90.0, 0.0, -90.0>
    translate  <3.032191, -5.885947, -1.699841>
  }
  cylinder { // cgcyl150
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 6.05>
    rotate <90.0, 0.0, -90.0>
    translate  <3.035501, -0.938299, -1.699841>
  }
  cylinder { // cgcyl151
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 6.05>
    rotate <90.0, 0.0, -90.0>
    translate  <3.033871, -11.720407, -1.699841>
  }
  cylinder { // cgcyl152
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 12.67>
    rotate 90.0*x
    translate  <-0.999873, 0.0, -1.70025>
  }
  cylinder { // cgcyl153
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 12.67>
    rotate 90.0*x
    translate  <0.999895, 0.0, -1.70046>
  }
  cylinder { // cgcyl154
    <0,0,1>, <0,0,0>, 1 
    photons {
      collect off
    }
    scale <0.1, 0.1, 12.67>
    rotate 90.0*x
    translate  -1.7*z
  }
  object { Eagle_lowereng7 }
  object { Eagle_cargopads }
  object { Eagle_cargopads1 }
  object { Eagle_cargopads2 }
  object { Eagle_cargopads3 }
  object { Eagle_lowereng11 }
  object { Eagle_lowereng12 }
  object { Eagle_lowereng13 }
  material {
    Eagle_cargobasic
  }
  photons {
    collect off
  }
  translate  <0.84191, -4.231072, -2.738467>
}
union { // space1999Eagle
  object { Eagle_cockpitlight2 }
  object { Eagle_cockpitlight1 }
  object { Eagle }
  object { Eagle_cargopod }
  photons {
    collect off
  }
  rotate <0,-90,-90>
  translate <10.7,6.50,-0.9>
}




