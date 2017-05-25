//This file is licensed under the terms of the CC-LGPL

/*
  A simple garden chair. The declared object is named GardenChair.
  The texture can be overridden by declaring GardenChairTexture before
  including this file.
*/

#include "transforms.inc"

#ifndef(GardenChairTexture)
  #declare GardenChairTexture =
    texture
    { pigment
      { wood color_map
        { [0 rgb <1, 1, .8>*1.5]
          [.7 rgb <1, .9, .5>*1.5]
          [1 rgb <.9, .7, .4>*1.5]
        }
        turbulence .4
        scale <1, 10, 1>*.2
      }
      finish { specular .3 roughness .1 }
    };
#end

#local GardenChairSide =
  union
  { union
    { box { <-1, 0, -1>, <-.9, 2.5, -.65> }
      difference
      { box { <-1, 0, 0>, <-.9, 2.6, -.35> rotate -x*10 }
        box { <-1.01, 0, 0>, <-.89, -.5, -.5> }
        box { <-1.01, 2.5, -.4>, <-.89, 2.7, -.8> }
        translate z
      }
      texture { GardenChairTexture }
    }
    union
    { box { <-1, 2.5, -.95>, <-1.1, 2.3, .55> }
      box { <-.85, 2.5, -1.1>, <-1.3, 2.55, 1> }
      box
      { <-.9, 1.3, .6>, <-.8, 1, -.85>
        translate -z*.6
        Shear_Trans(x, y, <0, -.2, 1>)
        translate z*.6
      }
      texture { GardenChairTexture rotate x*90 }
    }
    translate -x*.1
  };

#declare GardenChair =
  union
  { object { GardenChairSide }
    object { GardenChairSide scale <-1, 1, 1> } 
    union
    { box { <-1.4, 2.55, 1>, <1.4, 2.6, .95> }
      box { <-1, 1.3, -.95>, <1, 1.6, -.85> }
      box { <-1, 1.3, .7>, <1, 1, .6> }
      union
      { box { <-1, 0, 0>, <1, .05, .3> }
        box { <-1, 0, .4>, <1, .05, .7> }
        box { <-1, 0, .8>, <1, .05, 1.1> }
        box { <-1, 0, 1.2>, <1, .05, 1.5> }
        rotate x*10 translate <0, 1.6, -1>
      }
      texture { GardenChairTexture rotate z*90 }
    }
    intersection
    { union
      { box { <0, 0, 0>, <-.3, 2.7, -.05> rotate z*1 }
        box { <0, 0, 0>, <.3, 2.7, -.05> rotate -z*1 }
        box { <0, 0, 0>, <-.28, 2.7, -.05> rotate z*3 translate -x*.3 }
        box { <0, 0, 0>, <.28, 2.7, -.05> rotate -z*3 translate x*.3 }
        box { <0, 0, 0>, <-.26, 2.7, -.05> rotate z*5 translate -x*.58 }
        box { <0, 0, 0>, <.26, 2.7, -.05> rotate -z*5 translate x*.58 }
      }
      cylinder { <0, 1.2, .01>, <0, 1.2, -.06>, 1.5 }
      rotate x*15 translate <0, 1.3, .6>
      texture { GardenChairTexture }
    }
  };
