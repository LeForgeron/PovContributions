//This file is licensed under the terms of the CC-LGPL

#declare UseRadiosity = yes;
#declare UseAreaLight = yes;

#include "WarpGoban.inc"

#declare Kifu = array[19]
{ "+--------XOO------+", // T
  "|..X.....XO.O.OOX.|", // S
  "|.OO.X..OXXOO.OX..|", // R
  "|..,.....,.XXX.,X.|", // Q
  "|....X....X....XX.|", // P
  "|.O............XOO|", // O
  "|............OOOXXX", // N
  "|.............XOOOX", // M
  "|........X..XOOXXX|", // L
  "|..,.....,..OOX,XO|", // K
  "|.O...........OXXO|", // J
  "|.............OXOX|", // H
  "|...........O.OXOO|", // G
  "|.O......X.XO.OX..|", // F
  "|.....X.O..XOXOXO.|", // E
  "|.X,X..X.,.XOOXOO.|", // D
  "|....XOXO.OOXXXXOO|", // C
  "|.....XO.OO.OXX.XO|", // B
  "+-------O--O-X-X-X+", // A
// 1234567890123456789
};

global_settings
{ assumed_gamma 1
  #if(UseRadiosity)
    radiosity
    { brightness 1.5
      count 200
      low_error_factor .1
      pretrace_end .01
    }
  #end
}

camera
{ location <-10,20,-20>*4
  look_at 0 angle 35
}

light_source
{ <20,50,-10>*2, 1
  #ifdef(UseAreaLight)
    area_light x*50,y*50,15,15 circular orient jitter adaptive 1
  #end
}

plane
{ y, -2
  pigment
  { wood color_map
    { [0 rgb <.4,.25,.15>]
      [1 rgb <.3,.2,.1>]
    }
    rotate y*90
    turbulence .2
    scale <5,1,1>
  }
  normal
  { average normal_map
    { [1  wood 1 slope_map
          { [0 <0,0>][.5 <.5,1>][1 <1,0>]
          }
          rotate y*90
          turbulence .2
          scale <5,1,1>
      ]
      [.5 gradient z, 2 slope_map
          { [0 <0,1>][.01 <1,0>]
            [.99 <1,0>][1 <0,-1>]
          }
          scale 20
      ]
    }
  }
  finish { specular .3 reflection .05 }
}

WarpGoban_CreateGoban(Kifu)
object { WarpGoban_BlackBowl rotate y*60 translate <10,-2,-32> }
object { WarpGoban_WhiteBowl translate <-12,-2,33> }

union
{ object { WarpGoban_BowlLid }
  object { WarpGoban_BlackStone translate <.2, .4, .1> }
  object { WarpGoban_BlackStone rotate z*-10 translate <-1.8, .7, -.6> }
  object { WarpGoban_BlackStone rotate <20,-10> translate <-1.2, .7, 1> }
  object { WarpGoban_BlackStone rotate z*10 translate <1.5, .6, 1.9> }
  rotate y*150
  translate <-27, -2, 25>
}
union
{ object { WarpGoban_BowlLid }
  object { WarpGoban_WhiteStone translate <.2, .4, .1> }
  object { WarpGoban_WhiteStone rotate z*-10 translate <-1.8, .7, -.6> }
  object { WarpGoban_WhiteStone rotate <20,-10> translate <-1.2, .7, 1> }
  object { WarpGoban_WhiteStone rotate z*-10 translate <1.5, .6, -1.9> }
  translate <25, -2, -28>
}
