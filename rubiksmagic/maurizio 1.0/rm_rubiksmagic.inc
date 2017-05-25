//This file is licensed under the terms of the CC-LGPL
//
//Author: Maurizio Paolini <paolini@dmf.unicatt.it>
//

/*============================================================================
  Rubik's Magic 8 tiles include file
  -------------------------------------------------------------
  Usage:

  RM_RubiksMagic("...")

  The parameter is a string containing the configuration description.

  Uses actual measures of the real Rubik's Magic.
  1 pov unit = 1 cm

  The configuration description is a sequence of eight tokens, each describing
  how the i-th tile is connected to the (i-1)-th tile (see below).

  Configurations are restricted to the so-called "polyominoids": connected sets
  made of unit squares with all vertices in the unit cube lattice.
  We so not allow for superposed tiles (they would compenetrate; support to
  avoid this is not implemented).

  Each tile carries an orientation: an arrow drawn on one of its faces (the front
  face) parallel to an edge. The eight tiles form a chain and are numbered from 0
  to 7, adjacent sides are connected by a common edge and form an angle of 180
  degrees (complanar) or 90 degrees, in which case the "fold" can be a "mountain
  fold" or a "valley fold" with respect to the front face of the two tiles.
  The orientation of consecutive tiles is mutually consistent, this means that
  after rotating the two tiles around the common edge to make them coincident,
  the two arrows will come into contact and will be perfectly coincident (same
  direction and sense).

  In the starting rectangular 2x4 configuration, the four lower tiles, number from
  0 to 3 from left to right) have vertical arrows pointing up; the four upper tiles
  (numbered from 4 to 7 from right to left) have vertical arrows pointing down.

  Each token of the description consists of one or two ASCII characters, the first
  can be R, L, U, D (standing for Right, Left, Up, Down) and indicates which edge
  of the (i-1)-th tile connects it to the i-th tile.  The second character, if
  present, can be "m", or "v", standing for "mountain" or "valley", indicating a
  90 degrees angle, otherwise the two tiles form a 180 degrees angle.

  By default the first tile is tile number 0 oriented with its front face facing up,
  the arrow pointing in the z direction (pov-ray coordinates).
  It can be changed by defining the variable RM_StartTile.
  It is possible to orient the first tile differently by defining appropriately the
  variable RM_TilesRotation (-1, 0, 1, 2 for multiples of 90 degrees) and
  RM_FlipTiles to turn tiles upside-down.
  It is also possible to follow the chain of tiles backwards by defining
  RM_TilesIncrement as -1.

  A number of decorations are implemented, the default corresponds to the decoration
  of the puzzle available from the brand "Matchbox".
  Other possibilities include: black tiles, black tiles with a diagonal indicating
  the direction of the nylon wires, oriented tiles.

 */

#include "textures.inc"

#declare RM_SizeMatchbox = 5.25;
#declare RM_ThicknessMatchbox = 0.45;
#declare RM_Size = RM_SizeMatchbox;
#declare RM_Thickness = RM_ThicknessMatchbox;
#declare RM_GRadius = 0.1;

#declare RM_HalfSize = RM_Size/2;
#declare RM_HalfThickness = RM_Thickness/2;
#declare RM_GRadiusRel = RM_GRadius/RM_Size;

#declare RM_DecMatchbox = 0;
#declare RM_DecLingao = 1;
#declare RM_DecBlack = 2;
#declare RM_DecDiagonal = 3;
#declare RM_DecMatchboxFast = 4;
#declare RM_DecArrow = 5;
#declare RM_DecTileId = 6;
#declare RM_DecTransparent = 7;

#declare RM_decsnum = 8;

#declare RM_numtiles = 8;
#declare RM_Tile = array[8][RM_decsnum];
#declare RM_Scale = array[RM_decsnum];

#declare RM_tsmus = 0.3;  // spessore strato centrale, relativ. allo spessore totale
#declare RM_tsmus1 = RM_tsmus/2;
#declare RM_tsmus2 = (1 - RM_tsmus)/2;  // spessore smusso verticale
#declare RM_smus = RM_tsmus2*RM_Thickness/RM_Size;  // spessore smusso oriz, relativ. al lato tassello
#declare RM_goffset = 0.25;

/*
 * provision for puzzles with different size;
 * the RM_Scale vector contains the size relative to the size of the Matchbox brand puzzle.
 * The actual size will be (e.g.) RM_Size*RM_Scale[RM_Decoration]
 */

#local decid = 0;
#while (decid < RM_decsnum)
  #declare RM_Scale[decid] = 1;
  #local decid = decid + 1;
#end

// From textures.inc (Glass2)
#declare RM_TPlastic =
texture {
    pigment { rgbf <1,1,1,1> }
    finish {
        ambient 0
        diffuse 0
        reflection 0.2
        phong 0.3
        phong_size 60
    }
}

#declare RM_TGrooves =
texture {
    pigment { rgbf <1,1,1,0.5> }
    finish {
        ambient 0
        diffuse 0
        reflection 0.1
        phong 0.3
        phong_size 60
    }
}

#declare RM_middle = box {
  <0,-1.0001*RM_tsmus1,0>,<1,1.0001*RM_tsmus1,1>
}

#declare RM_tapered = prism {
  conic_sweep
  linear_spline
    1-RM_smus/2,
    1,
    5,
    <-1,-1>,<1,-1>,<1,1>,<-1,1>,<-1,-1>
  scale <0.5,1,0.5>
  translate -y+0.5*x+0.5*z
  scale <1,-2*RM_tsmus2/RM_smus,1>
  translate 0.99*RM_tsmus1*y
}

#declare RM_plastic0 = merge {
  object {RM_middle}
  object {RM_tapered}
  object {RM_tapered
    rotate 180*z
    translate x
  }
  translate -0.5*<1,0,1>
  scale <RM_Size, RM_Thickness, RM_Size>
}

#declare RM_lgroove = cylinder {
  <-0.5-RM_goffset,0,-0.5>,<0.5,0,0.5+RM_goffset>, RM_GRadiusRel
}

#declare RM_sgroove = cylinder {
  <-0.5-RM_goffset,0,-0.5+2*RM_goffset>,<0.5-2*RM_goffset,0,0.5+RM_goffset>, RM_GRadiusRel
}

#declare RM_lgroovesup = union {
  object {RM_lgroove}
  object {RM_lgroove
    rotate 90*y}
  object {RM_lgroove
    rotate 180*y}
  object {RM_lgroove
    rotate -90*y}
  scale RM_Size
}

#declare RM_sgroovesup = union {
  object {RM_sgroove}
  object {RM_sgroove
    rotate 90*y}
  object {RM_sgroove
    rotate 180*y}
  object {RM_sgroove
    rotate -90*y}
  scale RM_Size
}

#declare RM_grooves = union {
  object {RM_lgroovesup
    translate RM_HalfThickness*y
  }
  object {RM_lgroovesup
    translate -RM_HalfThickness*y
  }
  object {RM_sgroovesup
    translate RM_HalfThickness*y
  }
  object {RM_sgroovesup
    translate -RM_HalfThickness*y
  }
  texture {RM_TGrooves}
}

#declare RM_plastic = difference {
  object {RM_plastic0}
  object {RM_grooves}
  texture {RM_TPlastic}
}

#declare RM_arrowshape = union {
  box {<-0.02,0,-0.35>,<0.02,0.02,0.35>}
  box {<-0.02,0,-0.25>,<0.02,0.02,0>
       rotate 20*y
       translate 0.35*z
  }
  box {<-0.02,0,-0.25>,<0.02,0.02,0>
       rotate -20*y
       translate 0.35*z
  }
}

#declare RM_arrow = union {
  object {RM_arrowshape
    texture {pigment {rgb <1,1,0>}}
  }
  object {RM_arrowshape
    texture {pigment {rgb <0,0,1>}}
    translate -0.02*y
  }
  finish {ambient 0.2}
}

#macro RM_createtile_fast (front, back)
  union {
    object {RM_middle
        pigment { rgb <0,0,0> }
    }
    object {RM_tapered
      texture {
        pigment { image_map {jpeg front}
                  rotate 90*x
        }
      }
    }
    object {RM_tapered
      texture {
        pigment { image_map {jpeg back}
                  rotate 90*x
        }
      }
      rotate 180*z
      translate x
    }
    translate -0.5*<1,0,1>
    scale <RM_Size, RM_Thickness, RM_Size>
    finish { specular .5 roughness .1 ambient 0.3 }
  }
#end

#macro RM_createtile (front, back)
  RM_createtileg (front, back, 0, 0, -1)
#end

#macro RM_createtileg (front, back, tiletype, arrow, tid)
  union {
    object {RM_plastic}
    union {
      object {box {<0,0,0>,<1,0.01,1>}
        texture {
          pigment {
            image_map {jpeg front}
            rotate 90*x
          }
        }
        translate -0.5*<1,0,1>
      }
      object {box {<0,-0.01,0>,<1,0,1>}
        texture {
          pigment {
            image_map {jpeg back}
            rotate 90*x
            rotate 180*z
          }
        }
        translate -0.5*<1,0,1>
      }
      #if (tiletype != 0)
      box {<-0.4,0,-0.05>,<0.4,0.015,0.05>
        rotate (-45*tiletype*y)
        texture {pigment {rgb <1,1,1>}}
      }
      box {<-0.4,-0.015,-0.05>,<0.4,0,0.05>
        rotate (45*tiletype*y)
        texture {pigment {rgb <1,1,1>}}
      }
      #end
      #if (arrow != 0)
        object {RM_arrow}
      #end
      #if (tid >= 0)
        text {ttf "timrom.ttf" str(tid,1,0) 0.02, 0
          pigment {rgb <1,1,1>}
          rotate 90*x
          scale y+0.35*(x+z)
          translate 0.02*y+0.2*x-0.12*z
          finish {ambient 0.3}
        }
        text {ttf "timrom.ttf" str(tid,1,0) 0.02, 0
          pigment {rgb <0,0,1>}
          rotate 90*x
          scale y+0.35*(x+z)
          translate 0.02*y+0.2*x-0.12*z
          rotate 180*z
          finish {ambient 0.3}
        }
      #end
      scale <RM_Size, RM_Thickness, RM_Size>
      finish { specular .5 roughness .1 ambient 0.3 }
    }
  }
#end

#declare RM_Tile[0][RM_DecMatchbox] = RM_createtile ("rm_tile0f_matchbox.jpg", "rm_tile0b_matchbox.jpg")
#declare RM_Tile[1][RM_DecMatchbox] = RM_createtile ("rm_tile1f_matchbox.jpg", "rm_tile1b_matchbox.jpg")
#declare RM_Tile[2][RM_DecMatchbox] = RM_createtile ("rm_tile2f_matchbox.jpg", "rm_tile2b_matchbox.jpg")
#declare RM_Tile[3][RM_DecMatchbox] = RM_createtile ("rm_tile3f_matchbox.jpg", "rm_tile3b_matchbox.jpg")
#declare RM_Tile[4][RM_DecMatchbox] = RM_createtile ("rm_tile4f_matchbox.jpg", "rm_tile4b_matchbox.jpg")
#declare RM_Tile[5][RM_DecMatchbox] = RM_createtile ("rm_tile5f_matchbox.jpg", "rm_tile5b_matchbox.jpg")
#declare RM_Tile[6][RM_DecMatchbox] = RM_createtile ("rm_tile6f_matchbox.jpg", "rm_tile6b_matchbox.jpg")
#declare RM_Tile[7][RM_DecMatchbox] = RM_createtile ("rm_tile7f_matchbox.jpg", "rm_tile7b_matchbox.jpg")

#declare RM_Tile[0][RM_DecLingao] = RM_createtile ("rm_tile0f_lingao.jpg", "rm_tile0b_lingao.jpg")
#declare RM_Tile[1][RM_DecLingao] = RM_createtile ("rm_tile1f_lingao.jpg", "rm_tile1b_lingao.jpg")
#declare RM_Tile[2][RM_DecLingao] = RM_createtile ("rm_tile2f_lingao.jpg", "rm_tile2b_lingao.jpg")
#declare RM_Tile[3][RM_DecLingao] = RM_createtile ("rm_tile3f_lingao.jpg", "rm_tile3b_lingao.jpg")
#declare RM_Tile[4][RM_DecLingao] = RM_createtile ("rm_tile4f_lingao.jpg", "rm_tile4b_lingao.jpg")
#declare RM_Tile[5][RM_DecLingao] = RM_createtile ("rm_tile5f_lingao.jpg", "rm_tile5b_lingao.jpg")
#declare RM_Tile[6][RM_DecLingao] = RM_createtile ("rm_tile6f_lingao.jpg", "rm_tile6b_lingao.jpg")
#declare RM_Tile[7][RM_DecLingao] = RM_createtile ("rm_tile7f_lingao.jpg", "rm_tile7b_lingao.jpg")

#declare RM_Tile[0][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile0f_matchbox.jpg", "rm_tile0b_matchbox.jpg")
#declare RM_Tile[1][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile1f_matchbox.jpg", "rm_tile1b_matchbox.jpg")
#declare RM_Tile[2][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile2f_matchbox.jpg", "rm_tile2b_matchbox.jpg")
#declare RM_Tile[3][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile3f_matchbox.jpg", "rm_tile3b_matchbox.jpg")
#declare RM_Tile[4][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile4f_matchbox.jpg", "rm_tile4b_matchbox.jpg")
#declare RM_Tile[5][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile5f_matchbox.jpg", "rm_tile5b_matchbox.jpg")
#declare RM_Tile[6][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile6f_matchbox.jpg", "rm_tile6b_matchbox.jpg")
#declare RM_Tile[7][RM_DecMatchboxFast] = RM_createtile_fast ("rm_tile7f_matchbox.jpg", "rm_tile7b_matchbox.jpg")

#local tid = 0;
#while (tid < RM_numtiles)
  #declare RM_Tile[tid][RM_DecBlack] = RM_createtile ("rm_tileblack.jpg", "rm_tileblack.jpg")
  #local tid = tid + 1;
#end

#local tid = 0;
#while (tid < RM_numtiles)
  #declare RM_Tile[tid][RM_DecTransparent] = object {RM_plastic}
  #local tid = tid + 1;
#end

#local tid = 0;
#while (tid < RM_numtiles)
  #declare RM_Tile[tid][RM_DecDiagonal] = RM_createtileg ("rm_tileblack.jpg", "rm_tileblack.jpg", 1, 0, -1)
  #local tid = tid + 1;
  #declare RM_Tile[tid][RM_DecDiagonal] = RM_createtileg ("rm_tileblack.jpg", "rm_tileblack.jpg", -1, 0, -1)
  #local tid = tid + 1;
#end

#local tid = 0;
#while (tid < RM_numtiles)
  #declare RM_Tile[tid][RM_DecArrow] = RM_createtileg ("rm_tileblack.jpg", "rm_tileblack.jpg", 1, 1, -1)
  #local tid = tid + 1;
  #declare RM_Tile[tid][RM_DecArrow] = RM_createtileg ("rm_tileblack.jpg", "rm_tileblack.jpg", -1, 1, -1)
  #local tid = tid + 1;
#end

#local tid = 0;
#while (tid < RM_numtiles)
  #declare RM_Tile[tid][RM_DecTileId] = RM_createtileg ("rm_tileblack.jpg", "rm_tileblack.jpg", 1, 1, tid)
  #local tid = tid + 1;
  #declare RM_Tile[tid][RM_DecTileId] = RM_createtileg ("rm_tileblack.jpg", "rm_tileblack.jpg", -1, 1, tid)
  #local tid = tid + 1;
#end

#macro RM_RMgen(numtiles, tileid, tiletype, moves, tr)
  #local tid = tileid;
  #if (tid > 7) #local tid = tid - 8; #end
  #if (tid < 0) #local tid = tid + 8; #end
  object {
    RM_Tile[tid][RM_Decoration]
    rotate RM_FlipTiles*180*z
    rotate tiletype*RM_TilesRotation*90*y
    transform {tr}
  }
  #if (numtiles > 1)
    #local mlen = strlen(moves);
    #if (mlen > 0)
      #local dir = asc(substr(moves,1,1));
      #local fold = 0;
      #local eat = 1;
      #if (mlen > 1)
        #local fld = asc(substr(moves,2,1));
        #switch (fld)
          #case(109)
            #local fold = 90;
            #local eat = eat + 1;
            #break;
          #case(118)
            #local fold = -90;
            #local eat = eat + 1;
            #break;
        #end
      #end
      #local nmoves = substr(moves, eat+1, mlen-eat);
      #local newtr = transform {translate RM_Thickness*<1,1,1>}
      #switch (dir)
        #case(82) // R
          #local newtr = transform {translate RM_HalfSize*x rotate -fold*z translate RM_HalfSize*x}
          #break
        #case(76) // L
          #local newtr = transform {translate -RM_HalfSize*x rotate fold*z translate -RM_HalfSize*x}
          #break
        #case(85) // U
          #local newtr = transform {rotate 180*y translate RM_HalfSize*z rotate fold*x translate RM_HalfSize*z}
          #break
        #case(68) // D
          #local newtr = transform {rotate 180*y translate -RM_HalfSize*z rotate -fold*x translate -RM_HalfSize*z}
          #break
      #end
      RM_RMgen(numtiles - 1, tid + RM_TilesIncrement, -tiletype, nmoves, transform{newtr tr})
    #end
  #end
#end

#macro RM_RubiksMagic(moves)
  #ifndef (RM_StartTile) #declare RM_StartTile = 0; #end
  #ifndef (RM_StartType) #declare RM_StartType = 1; #end
  #ifndef (RM_TilesIncrement) #declare RM_TilesIncrement = 1; #end
  #ifndef (RM_TilesRotation) #declare RM_TilesRotation = 0; #end
  #ifndef (RM_FlipTiles) #declare RM_FlipTiles = 0; #end
  #ifndef (RM_Decoration) #declare RM_Decoration = RM_DecLingao; #end
  union {
    RM_RMgen(8, RM_StartTile, RM_StartType, moves, transform {rotate 0*x})
    scale RM_Scale[RM_Decoration]
  }
#end

