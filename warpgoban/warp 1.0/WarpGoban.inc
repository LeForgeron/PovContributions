//This file is licensed under the terms of the CC-LGPL

/*===========================================================================
  WarpGoban include file
  ----------------------
  This include file declares the macro:

WarpGoban_CreateGoban(Kifu)

where the parameter is an array of strings, represeting a "kifu". The board
will be created from it. The array should contain 19 strings, each string
having 19 characters. If a character is 'X' a black stone will be placed at
that location, and if a character is 'O' a white stone. Any other character
will be ignored (and thus can be anything you like).

  Here's an example array of an empty kifu definition (which you can copy
into your code and fill with X's and O's as necessary):

#declare Kifu = array[19]
{ "+-----------------+", // T
  "|.................|", // S
  "|.................|", // R
  "|..,.....,.....,..|", // Q
  "|.................|", // P
  "|.................|", // O
  "|.................|", // N
  "|.................|", // M
  "|.................|", // L
  "|..,.....,.....,..|", // K
  "|.................|", // J
  "|.................|", // H
  "|.................|", // G
  "|.................|", // F
  "|.................|", // E
  "|..,.....,.....,..|", // D
  "|.................|", // C
  "|.................|", // B
  "+-----------------+", // A
// 1234567890123456789
};

  Goban dimensions: <42.1, -2, 45.6>

  The used textures can be overridden by #declaring any of the following
texture identifiers before #including "WarpGoban.inc":

WarpGoban_BlackStoneMaterial
WarpGoban_WhiteStoneMaterial
WarpGoban_BoardWoodTexture
WarpGoban_LinesTexture

-------------------------------------------------------------------------

  The include file also declares the following objects, which can be used
separately:

WarpGoban_BlackStone
WarpGoban_WhiteStone
WarpGoban_Board
WarpGoban_Bowl (without stones)
WarpGoban_BlackBowl (with some black stones)
WarpGoban_WhiteBowl (with some white stones)
WarpGoban_BowlLid

  The texture of the bowl can be overridden by #declaring the following
texture identifier before #including "WarpGoban.inc":

WarpGoban_BowlTexture

  The following macro can be used to more easily place stones on the
WarpGoban_Board object (which has not been transformed yet). The CoordX
and CoordZ parameters should have values between 1 and 19.

WarpGoban_StonePos(CoordX, CoordZ, Elevation)

-------------------------------------------------------------------------

  The following macro is also defined:

WarpGoban_CreateBowl(StoneObj, StoneAmnt, Seed)

  This can be used to create a bowl with stones in it. (The stones may
intersect each other, depending on the given seed.)

===========================================================================
*/


#ifndef(WarpGoban_BlackStoneMaterial)
  #declare WarpGoban_BlackStoneMaterial =
    material
    { texture
      { pigment { rgb 0 }
        finish { specular .4 roughness .05 }
      }
    };
#end

#ifndef(WarpGoban_WhiteStoneMaterial)
  #declare WarpGoban_WhiteStoneMaterial =
    material
    { texture
      { pigment { rgb 1 }
        finish { specular .5 roughness .02 }
      }
    };
#end

#ifndef(WarpGoban_BoardWoodTexture)
  #declare WarpGoban_BoardWoodTexture =
    texture
    { pigment
      { wood color_map
        { [0 rgb <.95,.8,.2>]
          [1 rgb <.95,.6,.1>]
        }
        turbulence 1
        scale <2,2,10>
      }
      normal
      { dents 1
        turbulence .5
        scale 1/5 rotate y*35
      }
    };
#end

#ifndef(WarpGoban_LinesTexture)
  #declare WarpGoban_LinesTexture =
    texture
    { pigment { rgb 0 }
      finish { specular .2 }
    };
#end

#ifndef(WarpGoban_BowlTexture)
  #declare WarpGoban_BowlTexture =
    texture
    { pigment
      { wood color_map
        { [0 rgb <.8,.4,.2>]
          [1 rgb <.6,.3,.1>]
        }
        turbulence .1
        scale <1,5,1>
      }
      finish { specular .1 }
      normal { dents .3 scale .2 }
    };
#end

#local WarpGoban_Stone =
  merge
  { intersection
    { sphere { y*1.8, 1.8 }
      sphere { y*(-1.8+.8), 1.8 }
      cylinder { 0, y*.8, 2.1/2 }
      bounded_by { cylinder { 0, y*.8, 2.1/2 } }
    }
    torus { 2.1/2-.01, .031 scale <1,2.12,1> translate y*.4 }
  };

#declare WarpGoban_BlackStone =
  object
  { WarpGoban_Stone
    material { WarpGoban_BlackStoneMaterial }
  };

#declare WarpGoban_WhiteStone =
  object
  { WarpGoban_Stone
    material { WarpGoban_WhiteStoneMaterial }
  };

// Coords: 1-19
#macro WarpGoban_StonePos(CoordX, CoordZ, Elevation)
  <1.4+(42.1-1.4*2)*(CoordX-1)/18, Elevation, 1.55+(45.6-1.55*2)*(CoordZ-1)/18>
#end

#declare WarpGoban_Board =
  union
  { box
    { 0, <42.1, -2, 45.6>
      texture { WarpGoban_BoardWoodTexture }
    }

    #local LineWidth = .1;
    #local Ind = 1;
    #while(Ind <= 19)
      #local XPos = 1.4+(42.1-1.4*2)*Ind/18;
      #local ZPos = 1.55+(45.6-1.55*2)*Ind/18;
      box
      { WarpGoban_StonePos(Ind, 1, .001) - <LineWidth/2, 0, LineWidth/2>,
        WarpGoban_StonePos(Ind, 19, 0) + <LineWidth/2, 0, LineWidth/2>
      }
      box
      { WarpGoban_StonePos(1, Ind, .001) - <LineWidth/2, 0, LineWidth/2>,
        WarpGoban_StonePos(19, Ind, 0) + <LineWidth/2, 0, LineWidth/2>
      }
      #local Ind = Ind+1;
    #end

    #local IndX = 4;
    #while(IndX < 19)
      #local IndZ = 4;
      #while(IndZ < 19)
        cylinder
        { WarpGoban_StonePos(IndX, IndZ, .001),
          WarpGoban_StonePos(IndX, IndZ, 0), .3
        }
        #local IndZ = IndZ+6;
      #end
      #local IndX = IndX+6;
    #end

    texture { WarpGoban_LinesTexture }
  };

#declare WarpGoban_Bowl =
  difference
  { intersection
    { sphere { 0, 14/2 }
      box { -<14/2, 9/2, 14/2>, <14/2, 9/2, 14/2> }
    }
    intersection
    { sphere { 0, 14/2-.4 }
      box { -<14/2, 9/2-.4, 14/2>, <14/2, 9/2+.1, 14/2> }
    }
    texture { WarpGoban_BowlTexture }
    translate y*9/2
    scale <1,.8,1>
  };

#declare WarpGoban_BowlLid =
  union
  { difference
    { intersection
      { sphere { 0, 14/2 }
        box { <-14/2, 9/2, -14/2>, <14/2, 14/2, 14/2> }
      }
      sphere { 0, 14/2-.4 }
    }
    torus { 10/2, .2 translate y*9/2 }
    texture { WarpGoban_BowlTexture }
    rotate x*180
    translate y*14/2
    scale <1,.8,1>
  };

#macro WarpGoban_CreateBowl(StoneObj, StoneAmnt, Seed)
  union
  { object { WarpGoban_Bowl }

    #local Ind = 0;
    #while(Ind < StoneAmnt)
      object
      { StoneObj
        rotate <rand(Seed)*20, rand(Seed)*360>
        #local Loc = <-4+rand(Seed)*10, 0, -4+rand(Seed)*10>;
        #while(vlength(Loc) > 4)
          #local Loc = <-4+rand(Seed)*10, 0, -4+rand(Seed)*10>;
        #end
        translate Loc+y*(.4+rand(Seed)*2)
      }
      #local Ind = Ind+1;
    #end
  }
#end

#declare WarpGoban_BlackBowl =
  WarpGoban_CreateBowl(WarpGoban_BlackStone, 30, seed(1));

#declare WarpGoban_WhiteBowl =
  WarpGoban_CreateBowl(WarpGoban_WhiteStone, 30*3, seed(10));

#macro WarpGoban_CreateGoban(Kifu)
  union
  { object { WarpGoban_Board }

    #local Seed = seed(0);
    #local Lines = dimension_size(Kifu, 1);
    #local LineInd = 0;
    #while(LineInd < Lines)
      #local Len = strlen(Kifu[LineInd]);
      #local StrInd = 0;
      #while(StrInd < Len)
        #local Char = substr(Kifu[LineInd], StrInd+1, 1);
        #local HasStone = no;
        #if(strcmp(Char, "X") = 0)
          #local Stone = WarpGoban_BlackStone;
          #local HasStone = yes;
        #end
        #if(strcmp(Char, "O") = 0)
          #local Stone = WarpGoban_WhiteStone;
          #local HasStone = yes;
        #end

        #if(HasStone)
          object
          { Stone
            rotate <-2.5+5*rand(Seed), 0, -2.5+5*rand(Seed)>
            translate WarpGoban_StonePos((StrInd+1)-.025+.05*rand(Seed),
              (19-LineInd)-.05+.1*rand(Seed), 0)
          }
        #end

        #local StrInd = StrInd+1;
      #end
      #local LineInd = LineInd+1;
    #end

    translate <-42/2, 0, -45/2>
  }
#end
