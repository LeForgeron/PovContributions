//This file is licensed under the terms of the CC-LGPL
#version 3.7;
global_settings { assumed_gamma 1.4 }
#declare Fast = yes;

#include "RM_RubiksMagic.inc"

#declare RM_Decoration = RM_DecMatchbox;     // this is the default decoration
//#declare RM_Decoration = RM_DecLingao;     // another brand
//#declare RM_Decoration = RM_DecMatchboxFast; // renders faster, no transparent plastic
//#declare RM_Decoration = RM_DecBlack;      // undecorated tiles
//#declare RM_Decoration = RM_DecDiagonal;   // undecorated with diagonal parallel to wires
//#declare RM_Decoration = RM_DecArrow;      // with orientation
//#declare RM_Decoration = RM_DecTileId;     // with orientation and tiles numbering
//#declare RM_Decoration = RM_DecTransparent;// transparent tiles

//#declare RM_StartTile = 3;      // default: 0
//#declare RM_TilesIncrement = 1; // default: 1
//#declare RM_TilesRotation = -1; // default: 0
//#declare RM_FlipTiles = 1;      // default: 0

object
{ RM_RubiksMagic("RRRURRRU")    // rectangle
//{ RM_RubiksMagic("RDLDURRU")  // solved
//{ RM_RubiksMagic("RRvRmURRmRvU")  // hinge equivalent to "rectangle"
//{ RM_RubiksMagic("RURmDvRvUvLvUm")     // magic (2,7)
  translate RM_HalfThickness*y + RM_Size*<-1.5,0,0.5>
  rotate -60*x
  translate RM_Size*2*z
}

object
{ RM_RubiksMagic("RULDLLDU")
  translate -RM_Size*(x+z)
  rotate 180*z
  translate RM_HalfThickness*y
  rotate 135*y
}

object
{ RM_RubiksMagic("RRmUmLmDUmLmDm")
  rotate 90*z
  translate RM_HalfThickness*y
  translate RM_HalfSize*y
  rotate -30*y
  translate RM_Size*<-4,0,0>
}

object
{ RM_RubiksMagic("RmRmUmLmLmDvDmDv")
  translate RM_HalfThickness*y
  translate 3*RM_HalfSize*z
  rotate -135*x
  //rotate -30*y
  translate RM_Size*<-3,0,2.5>
}

/*
 * floor, lights, camera...
 */

camera
{ location <8, 9, -10>*3
  //look_at 6.6/2-y*.4
  look_at 1.2*RM_Size*y
  angle 35
}

light_source
{ <20, 30, -10>, 1
  fade_distance 30
  fade_power 2
  #if(!Fast)
    area_light x*4, y*4, 16, 16 jitter adaptive 1 circular orient
  #end
}

light_source
{ <-20, 20, -15>, .5
  fade_distance 30
  fade_power 2
  #if(!Fast)
    area_light x*4, y*4, 16, 16 jitter adaptive 1 circular orient
  #end
}

plane
{ y, 0
  #if(Fast)
    pigment { rgb <1, .9, .7> }
  #else
    texture
    { average texture_map
      { #declare S = seed(0);
        #local ReflColor = .8*<1, .9, .7> + .2*<1,1,1>;
        #declare Ind = 0;
        #while(Ind < 20)
          [1 pigment { rgb <1, .9, .7> }
             normal { bumps .1 translate <rand(S),rand(S),rand(S)>*100 scale .001 }
             finish { reflection { ReflColor*.1, ReflColor*.5 } }
          ]
          #declare Ind = Ind+1;
        #end
      }
    }
  #end
}

