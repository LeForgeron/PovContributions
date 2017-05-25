//This file is licensed under the terms of the CC-LGPL

/*===========================================================================
  WarpChess include file
  ----------------------
  This include file declares the following untextured objects:

WarpChess_Pawn
WarpChess_Rook
WarpChess_Knight
WarpChess_Bishop
WarpChess_Queen
WarpChess_King

  It also declares textured versions of these objects. These have the
word "White" or "Black" before the piece name, like:

WarpChess_WhitePawn
WarpChess_BlackPawn
etc.

  The textures of the pieces can be modified by #declaring any of these
texture/material identifiers *before* #including "WarpChess.inc":

WarpChess_BaseTexture
WarpChess_WhiteMaterial
WarpChess_BlackMaterial

  The materials can be transparent (and have ior).

  This include file also defines two macros to create a chessboard:

WarpChess_CreateDefaultBoard()

  Simply creates a chessboard with all the pieces in their initial places.

WarpChess_CreateBoard(Moves)

  Creates a chessboard based on the given moves. The parameter should be
an array of strings, each string denoting a chess move. These moves are
similar to the moves of a regular chess game record. The board situation
is started from the initial position, and pieces are moved according to
the given moves. Captured pieces are moved to the edge of the board.
  Example usage:

#declare Moves = array[8]
{ "E2E4", "E7E5", "G1F3", "B8C6", "D2D3", "F8B4", "B1C3", "G8F6" }

WarpChess_CreateBoard(Moves)

  The textures used in the board can be overridden by declaring these
texture identifiers before #including "WarpChess.inc":

WarpChess_WhiteSquareTexture
WarpChess_BlackSquareTexture
WarpChess_WoodTexture
WarpChess_BoardLettersTexture
WarpChess_BoardFont (default is "timrom.ttf")

===========================================================================
*/


#ifndef(WarpChess_BoardFont)
  #declare WarpChess_BoardFont = "timrom.ttf";
#end

#ifndef(WarpChess_BoardLettersTexture)
  #declare WarpChess_BoardLettersTexture =
    texture
    { pigment { rgb <1,.8,.3> }
      finish { reflection .7 specular .5 }
    };
#end

#ifndef(WarpChess_WhiteSquareTexture)
  #declare WarpChess_WhiteSquareTexture =
    texture
    { pigment
      { marble color_map
        { [0 rgb 1][.5 rgb 1][1 rgb .6]
        }
        scale 1/5 warp { turbulence .7 } scale 5
        scale .3
        rotate <10,40,70>
      }
      finish { specular .25 reflection .5 }
    };
#end

#ifndef(WarpChess_BlackSquareTexture)
  #declare WarpChess_BlackSquareTexture =
    texture
    { pigment
      { marble color_map
        { [0 rgb 0][.7 rgb 0][.9 rgb .4][1 rgb .6]
        }
        scale 1/4 warp { turbulence .5 } scale 4
        scale .3
        rotate <-15,20,-80>
      }
      finish { specular .25 reflection .5 }
    };
#end

#ifndef(WarpChess_WoodTexture)
  #declare WarpChess_WoodTexture =
    texture
    { pigment
      { wood color_map
        { [0 rgb <.8,.5,.2>][1 rgb <.5,.3,.1>]
        }
        turbulence .5
        scale <3,.25,.25>
      }
      finish { specular .3 reflection .2 }
    };
#end

#ifndef(WarpChess_BaseTexture)
  #declare WarpChess_BaseTexture =
    texture
    { pigment { rgb <.1,.8,.1> }
      normal { bozo 1 scale .025 }
      finish { crand .1 }
    };
#end

#ifndef(WarpChess_WhiteMaterial)
  #declare WarpChess_WhiteMaterial =
    material
    { texture
      { pigment { rgb <1,.95,.9> }
        finish { specular .8 roughness .02 reflection .1 }
      }
    };
#end

#ifndef(WarpChess_BlackMaterial)
  #declare WarpChess_BlackMaterial =
    material
    { texture
      { pigment { rgb <.7,.4,.1> }
        finish { specular .8 roughness .02 reflection .1 }
      }
    };
#end

#local Base =
  union
  { intersection
    { sphere { 0,1.02 }
      box { <-1.02,0,-1.02><1.02,.1,1.02> }
      texture { WarpChess_BaseTexture }
    }
    sphere
    { 0,1
      clipped_by { box { <-1,.101,-1>1 } }
    }
  };

#declare WarpChess_Pawn =
  merge
  { object { Base }
    cone { y*.5, .6, y*2.3, .3 }
    torus { .3, .1 translate y*2.3 }
    sphere { y*2.7, .5 }
  };

#declare WarpChess_Rook =
  merge
  { object { Base }
    cone { y*.5, .65, y*3, .5 }
    torus { .5, .1 translate y*3 }
    difference
    { sphere { y*3.5, .7 }
      sphere { y*3.5, .5 }
      box { <-.7,3.5,-.7><.7,4.2,.7> }
    }
    difference
    { cylinder { y*3.5, y*3.8, .7 }
      cylinder { y*3.49, y*3.81, .5 }
      box { <-.15,3.5,-.7><.15,3.81,.7> }
      box { <-.7,3.5,-.15><.7,3.81,.15> }
    }
  };

#local TearDrop =
 poly
  {5,
   <-0.5, 0,   0,  -0.5, 0,   0,   0,   0,   0,  0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,  0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,  0,
     0,   0,   0,   0,   0,   0,   0,   0,   0,  0,
     0,   0,   0,   0,   1,   0,   0,   0,   0,  0,
     0,   0,   0,   1,   0,   0>
     clipped_by { sphere { -x*.6, .4 } }
     bounded_by { clipped_by }
     rotate z*90
  };

#declare WarpChess_Bishop =
  merge
  { object { Base }
    cone { y*.5, .6, y*2.8, .4 }
    torus { .4, .1 translate y*2.8 }
    difference
    { object { TearDrop scale <2.8,2,2.8> translate y*4.7 }
      box { <0,0,-.5><.5,.1,.5> rotate z*35 translate y*3.4 }
    }
    sphere { y*4.2,.2 }
  };

#declare WarpChess_Queen =
  merge
  { object { Base }
    cone { y*.5, .65, y*3.5, .4 }
    torus { .4, .1 translate y*3.5 }
    sphere { 0,.6 scale <1,.75,1> translate y*3.8 }
    sphere { y*4.35, .2 }
    difference
    { sphere { y*4.2, .7 }
      sphere { y*4.2, .55 }
      sphere { y*2.2, 2 inverse }
      #local Angle = 0;
      #while(Angle < 180)
        box { <-.15,3.95,-.7><.15,4.2,.7> rotate y*Angle }
        #local Angle = Angle+45;
      #end
      bounded_by { box { <-.7,3.8,-.7><.7,4.15,.7> } }
    }
  };

#declare WarpChess_King =
  merge
  { object { Base }
    cone { y*.5, .65, y*3.5, .4 }
    torus { .4, .1 translate y*3.5 }
    sphere { 0,.6 scale <1,.9,1> translate y*3.9 }
    torus { .6,.05 scale <1,2,1> translate y*3.9 }
    torus { .15,.1 translate y*4.35 }
    box { <-.08,4.3,-.1><.08,5,.1> }
    box { <-.08,4.7,-.2><.08,4.85,.2> }
  };

#declare WarpChess_Knight =
  merge
  { object { Base }
    difference
    { box { <-1.25,0,-.5><1,4,.5> }
      box { <-1.26,0,0><1.01,4.1,-.35> rotate x*5 translate -z*.5 }
      box { <-1.26,0,0><1.01,4.1,.35> rotate x*-5 translate z*.5 }
      cylinder { <.1,2.3,-.51><.1,2.3,.51>,.3 }
      box { <0,0,-.51><1.1,-2.5,.51> rotate z*20 translate <0,2.2,0> }
      box { <0,0,-.51><.75,1.7,.51> rotate z*20 translate <.8,2.4,0> }
      box { <0,-.1,-.51><-.7,1.5,.51> rotate z*-10 translate -x*.8 }
      union
      { cylinder { <.6,2.5,-.51><.6,2.5,.51>,1.8 }
        box { <-.8,0,-.51><0,3,.51> }
        inverse
      }
      #local Angle = -20;
      #while(Angle < 50 )
        cylinder
        { <-1.1,0,-.5><-1.85,0,-.25>,.11 rotate z*-Angle translate <.6,2.5,0> }
        cylinder
        { <-1.1,0,.5><-1.85,0,.25>,.11 rotate z*-Angle translate <.6,2.5,0> }
        #local Angle = Angle+10;
      #end
      box { <0,0,-.51><.8,.5,.51> rotate z*-25 translate <-.3,3.8,0> }
      sphere { <.2,3.1,-.25>, .1 }
      sphere { <.2,3.1,.25>, .1 }
    }
  };

#declare WarpChess_WhitePawn =
  object { WarpChess_Pawn material { WarpChess_WhiteMaterial } };

#declare WarpChess_BlackPawn =
  object { WarpChess_Pawn material { WarpChess_BlackMaterial } };

#declare WarpChess_WhiteRook =
  object { WarpChess_Rook material { WarpChess_WhiteMaterial } };

#declare WarpChess_BlackRook =
  object { WarpChess_Rook material { WarpChess_BlackMaterial } };

#declare WarpChess_WhiteBishop =
  object { WarpChess_Bishop material { WarpChess_WhiteMaterial } };

#declare WarpChess_BlackBishop =
  object { WarpChess_Bishop material { WarpChess_BlackMaterial } };

#declare WarpChess_WhiteQueen =
  object { WarpChess_Queen material { WarpChess_WhiteMaterial } };

#declare WarpChess_BlackQueen =
  object { WarpChess_Queen material { WarpChess_BlackMaterial } };

#declare WarpChess_WhiteKing =
  object { WarpChess_King material { WarpChess_WhiteMaterial } };

#declare WarpChess_BlackKing =
  object { WarpChess_King material { WarpChess_BlackMaterial } };

#declare WarpChess_WhiteKnight =
  object { WarpChess_Knight material { WarpChess_WhiteMaterial } };

#declare WarpChess_BlackKnight =
  object { WarpChess_Knight material { WarpChess_BlackMaterial } };

//=============================================================================

#macro WarpChess_CreateDefaultBoard()
  #local Moves = array[1] { "" };
  WarpChess_CreateBoard(Moves)
#end

#macro WarpChess_CreateBoard(Moves)
  #local Coords = array[32];
  #local IndX = 0;
  #while(IndX < 8)
    #local Coords[IndX] = <IndX,0>;
    #local Coords[IndX+8] = <IndX,1>;
    #local Coords[IndX+16] = <IndX,6>;
    #local Coords[IndX+24] = <IndX,7>;
    #local IndX = IndX+1;
  #end

  #local CapturedWhite = 0;
  #local CapturedBlack = 0;

  #macro WarpChess_CheckCoords(ix, iy, si, ei)
    #local Res = -1;
    #local Ind = si;
    #while(Ind <= ei)
      #if(Coords[Ind].u = ix & Coords[Ind].v = iy)
        #local Res = Ind;
        #local Ind = ei;
      #end
      #local Ind = Ind+1;
    #end
    Res
  #end

  #if(strlen(Moves[0]) > 0)
    #local Ind = 0;
    #while(Ind < dimension_size(Moves, 1))
      #if(strcmp(Moves[Ind],"0-0")=0)
        #if(mod(Ind,2)=0) // black
          #local Coords[4+8*3] = <6,7>;
          #local Coords[7+8*3] = <5,7>;
        #else // white
          #local Coords[4] = <6,0>;
          #local Coords[7] = <5,0>;
        #end
      #else
        #local c1x = asc(substr(Moves[Ind], 1, 1))-65;
        #local c1y = asc(substr(Moves[Ind], 2, 1))-49;
        #local c2x = asc(substr(Moves[Ind], 3, 1))-65;
        #local c2y = asc(substr(Moves[Ind], 4, 1))-49;

        #local CapInd = WarpChess_CheckCoords(c2x, c2y, 0, 15);
        #if(CapInd >= 0)
          #local Coords[CapInd] = <CapturedWhite*.8, 8.5>;
          #local CapturedWhite = CapturedWhite+1;
        #else
          #local CapInd = WarpChess_CheckCoords(c2x, c2y, 16, 31);
          #if(CapInd >= 0)
            #local Coords[CapInd] = <CapturedBlack*.8, -1.5>;
            #local CapturedBlack = CapturedBlack+1;
          #end
        #end

        #local PInd = WarpChess_CheckCoords(c1x, c1y, 0, 31);
        #local Coords[PInd] = <c2x, c2y>;
      #end

      #local Ind = Ind+1;
    #end
  #end

  #local SquareSize = 2.7;

  #macro WarpChess_Trans(X, Z)
    translate <X*SquareSize, (X>7 | X<0 ? -1 : 0), Z*SquareSize>
  #end

  union
  { union
    { box
      { 0,<SquareSize*8, -1, SquareSize*8>
        texture
        { checker
          texture { WarpChess_WhiteSquareTexture },
          texture { WarpChess_BlackSquareTexture }
          scale SquareSize
        }
      }

      #local Side =
        difference
        { box { <-SquareSize/2, 0, -SquareSize/2><SquareSize*8.5, -1, 0> }
          box { y*.01,<-SquareSize*.8, -1.01, SquareSize*.4> rotate y*-45 }
          box
          { y*.01,<SquareSize*.8, -1.01, SquareSize*.4>
            rotate y*45 translate x*SquareSize*8
          }
        };

      object { Side texture { WarpChess_WoodTexture } }
      object
      { Side texture { WarpChess_WoodTexture translate <10,20,30> }
        rotate y*90 translate z*SquareSize*8
      }
      object
      { Side texture { WarpChess_WoodTexture translate <-10,20,-30> }
        rotate y*-90 translate x*SquareSize*8
      }
      object
      { Side texture { WarpChess_WoodTexture translate <10,-20,80> }
        rotate y*180 translate <SquareSize*8, 0, SquareSize*8>
      }

      translate <-SquareSize/2, 0, -SquareSize/2>
    }

    union
    { text
      { ttf WarpChess_BoardFont, "abcdefgh", .1, x*SquareSize*.64
        scale 1.25
        rotate <90,-90>
        translate <SquareSize*7.9,.05,-SquareSize*.1>
      }
      text
      { ttf WarpChess_BoardFont, "hgfedcba", .1, x*SquareSize*.64
        scale 1.25
        rotate <90,90>
        translate <-SquareSize*.9,.05,SquareSize*7.2>
      }
      text
      { ttf WarpChess_BoardFont, "12345678", .1, <-.5,SquareSize*.8,0>
        scale 1.25
        rotate <90,-90>
        translate <SquareSize*7.2,.05,-SquareSize*.8>
      }
      text
      { ttf WarpChess_BoardFont, "87654321", .1, <-.5,SquareSize*.8,0>
        scale 1.25
        rotate <90,90>
        translate <-SquareSize*.2,.05,SquareSize*7.85>
      }

      texture { WarpChess_BoardLettersTexture }
    }

    #local Pieces = array[32]
    { WarpChess_WhiteRook, object { WarpChess_WhiteKnight rotate y*180 },
      object { WarpChess_WhiteBishop rotate y*180 }, WarpChess_WhiteQueen,
      WarpChess_WhiteKing, object { WarpChess_WhiteBishop rotate y*180 },
      object { WarpChess_WhiteKnight rotate y*180 }, WarpChess_WhiteRook,
      WarpChess_WhitePawn, WarpChess_WhitePawn,
      WarpChess_WhitePawn, WarpChess_WhitePawn,
      WarpChess_WhitePawn, WarpChess_WhitePawn,
      WarpChess_WhitePawn, WarpChess_WhitePawn,
      WarpChess_BlackPawn, WarpChess_BlackPawn,
      WarpChess_BlackPawn, WarpChess_BlackPawn,
      WarpChess_BlackPawn, WarpChess_BlackPawn,
      WarpChess_BlackPawn, WarpChess_BlackPawn,
      WarpChess_BlackRook, WarpChess_BlackKnight,
      WarpChess_BlackBishop, WarpChess_BlackQueen,
      WarpChess_BlackKing, WarpChess_BlackBishop,
      WarpChess_BlackKnight, WarpChess_BlackRook
    };

    #local Ind = 0;
    #while(Ind < 32)
      object { Pieces[Ind] WarpChess_Trans(7-Coords[Ind].v, Coords[Ind].u) }
      #local Ind = Ind+1;
    #end

    translate
    <SquareSize/2, 0, SquareSize/2>+<-SquareSize*8/2, 0, -SquareSize*8/2>
  }
#end
