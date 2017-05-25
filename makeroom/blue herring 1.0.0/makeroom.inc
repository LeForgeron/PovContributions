// Title:        MakeRoom
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   July 1, 2008
// Last updated: July 11, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(Makeroom_Inc)
#declare Makeroom_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including makeroom.inc\n"
#end

#include "colors.inc"
#include "math.inc"
#include "transforms.inc"

// MakeRoom
// Creates a low detail indoor room for use as background.  Each wall, the ceiling,
// and the floor can be indivually textured.  Optionally, simple doors, windows, 
// baseboards and crown moldings can be added.  These can also be textured individually.
//
//  Size -
//    Type: 3D Vector
//    Use:  Specifies the x, y, and z sizes of the room's interior space.  The room will be
//          created centered on the origin.  The resultant object will be slightly larger
//          than this value, due to the thickness of the walls.
//
// Room structure variables:
//  MR_Thickness -
//    Type:    Float
//    Default: 5
//    Use:     Defines the wall thickness of all walls, ceiling, and floor.  Thus the room
//             object will be shaped like a box { -Size/2 - MR_Thickness, Size/2 + MR_Thickness }
//
// Room texture variables:
//  MR_Wall_T -
//    Type:    Texture
//    Default: MR_Wall_Default_T
//    Use:     Defines the texture of the walls, ceiling, and floor, if they are not
//             specifically defined by the variables below.
//
//  MR_Floor_T -
//    Type:    Texture
//    Default: MR_Wall_T
//    Use:     Defines the floor texture of the room (-y direction).
//
//  MR_Ceiling_T -
//    Type:    Texture
//    Default: MR_Wall_T
//    Use:     Defines the ceiling texture of the room (+y direction).
//
//  MR_Wall_Front_T -
//    Type:    Texture
//    Default: MR_Wall_T
//    Use:     Defines the texture of the front wall (-z direction).
//
//  MR_Wall_Back_T -
//    Type:    Texture
//    Default: MR_Wall_T
//    Use:     Defines the texture of the back wall  (+z direction).
//
//  MR_Wall_Left_T -
//    Type:    Texture
//    Default: MR_Wall_T
//    Use:     Defines the texture of the left wall (-x direction).
//
//  MR_Wall_Right_T -
//    Type:    Texture
//    Default: MR_Wall_T
//    Use:     Defines the texture of the right wall (+x direction).
//
// Window variables:
//  MR_Windows -
//    Type:    1D array of integers
//    Default: None
//    Use:     Defines how many windows will be added to the room, by enumerating
//             a numeric type for each window.  The types currently defined are:
//               0 - Rectangular, no frame
//               1 - Rectangular, outer frame
//               2 - Rectangular, outer frame and vertical divider
//               3 - Rectangular, outer frame and horizontal divider
//               4 - Rectangular, outer frame, vertical and horizontal dividers
//               5 - Elliptical, no frame
//               6 - Elliptical, outer frame
//               7 - Elliptical, outer frame and vertical divider
//               8 - Elliptical, outer frame and horizontal divider
//               9 - Elliptical, outer frame, vertical and horizontal dividers
//
//  MR_Windows_Side -
//    Type:    1D array of 3D vectors
//    Default: None
//    Use:     Enumerates vectors specifying which wall the window will be placed on 
//             (+y for ceiling, -y for floor, -z for front wall etc.)  Using non axis
//             vectors will have unpredictable results.
//
//  MR_Windows_Pos -
//    Type:    1D array of 3D vectors
//    Default: None
//    Use:     Enumerates the vectors specifying the position of each window on the walls.
//             The point should lie somewhere within the box defined by -Side/2, Side/2.
//             The actual position of the window is determined by projecting this point
//             to the wall determined by MR_Windows_Side.
//
//  MR_Windows_Size -
//    Type:    1D array of 2D vectors
//    Default: None
//    Use:     Enumerates the width and height of each window, corresponding to the x and y
//             values respectively of each vector.
//
//  MR_Windows_Thickness -
//    Type:    Float
//    Default: 0.5
//    Use:     Determines the width of window frames, and how far from the wall they protrude.
//
//  MR_Windows_T -
//    Type:    Texture
//    Default: MR_Windows_Default_T
//    Use:     Specifies the texture applied to the window frames and dividers.
//
//  MR_Windows_Use_Glass -
//    Type:    Boolean
//    Default: off
//    Use:     If enabled, each window will be covered by a pane of glass.  Otherwise, the
//             window openings will be empty holes.
//
//  MR_Windows_Glass_M -
//    Type:    Material
//    Default: MR_Windows_Glass_Default_M
//    Use:     Specifies the material to be applied to the panes of glass.
//
//  MR_Windows_Glass_Photons -
//    Type:    4D vector
//    Default: None
//    Use:     If defined, a photon block will added to each pane of glass.  The x, y, z, and t
//             values of the vector correspond to the object photon settings "target",
//             "reflection", "refraction", and "collect" respectively.
//
// Door variables:
//  MR_Doors -
//    Type:    1D array of integers
//    Default: None
//    Use:     Defines the door opening types to be added to the room. The currently available
//             door types are:
//               0 - Rectangular, no frame
//               1 - Rectangular, outer frame
//             Currently there are only door openings, not actual doors.  The primary differences
//             between doors and windows are: door frames are only at the top and sides, doors
//             cannot have glass panes, any molding or baseboards will be removed from in front
//             of the door, and doors are auto-aligned to the floor.
//
//  MR_Doors_Side -
//    Type:    1D array of 3D vectors
//    Default: None
//    Use:     Defines which wall each door is on, in the same way as for windows.
//
//  MR_Doors_Pos -
//    Type:    1D array of 3D vectors
//    Default: None
//    Use:     Enumerates the positions of each door in the same manner as windows.  The only
//             difference is that for doors on the -x, +x, -z, and +z walls the position will
//             be automatically adjusted so the bottom of the door rests on the floor (-y).
//             This behavior can be disabled using the MR_Doors_Align option.
//
//  MR_Doors_Size -
//    Type:    1D array of 2D vectors
//    Default: None
//    Use:     Enumerates the width/height of each door in the same manner as windows.
//
//  MR_Doors_Align -
//    Type:    Boolean
//    Default: on
//    Use:     If false, the automatic aligment of doors to the floor will be disabled.  In
//             this case positioning is identical to that of windows.
//
//  MR_Doors_Thickness -
//    Type:    Float
//    Default: 0.5
//    Use:     Determines the width of the door frames, and how far they protrude from the wall.
//
//  MR_Doors_T -
//    Type:    Texture
//    Default: MR_Windows_T
//    Use:     Specifies the texture to be applied to door frames.
//
// Baseboard variables:
//  MR_Baseboard -
//    Type:    Boolean
//    Default: off
//    Use:     Enables/disables creation of a baseboard around the bottom edge of the room.
//             The default shape is a rectangular board 2 units tall and 1 unit deep.
//
//  MR_Baseboard_Shape -
//    Type:    Object
//    Default: MR_Baseboard_Default_Shape
//    Use:     Defines the object to be used for the baseboard.  The object should be 1 unit
//             long in the x direction and faced so the side against the wall points in the
//             +z direction.  The object will be scaled along the x axis then positioned along
//             the bottom edge of each wall.
//
//  MR_Baseboard_T -
//    Type:    Texture
//    Default: MR_Windows_T
//    Use:     Defines the texture to be applied to the baseboards.
//             
// Crown molding variables:
//  MR_Crown -
//    Type:    Boolean
//    Default: off
//    Use:     Enables/disables crown molding at the tops of the walls.  The default shape is
//             a curve 2 units tall and 2 units deep.
//
//  MR_Crown_Shape -
//    Type:    Object
//    Default: MR_Crown_Default_Shape
//    Use:     Defines the object to be used for the crown molding.  The object should be 1 unit
//             long in the x direction and faced so the side against the wall points in the
//             +z direction.  The object will be scaled along the x axis then positioned along
//             the top edge of each wall.
//
//  MR_Crown_T -
//    Type:    Texture
//    Default: MR_Windows_T
//    Use:     Defines the texture to be applied to the crown molding.
//
#macro MakeRoom(Size)

  #ifdef(MR_Thickness)
    #local Th = MR_Thickness;
  #else
    #local Th = 5;
  #end
  
  #local Sz = Size * <1, 1, 1>;
  
  #ifndef(MR_Wall_T)
    #local MR_Wall_T = MR_Wall_Default_T;
  #end
  
  #ifndef(MR_Wall_Front_T)
    #local MR_Wall_Front_T = MR_Wall_T;
  #end
  
  #ifndef(MR_Wall_Back_T)
    #local MR_Wall_Back_T = MR_Wall_T;
  #end
  
  #ifndef(MR_Wall_Left_T)
    #local MR_Wall_Left_T = MR_Wall_T;
  #end
  
  #ifndef(MR_Wall_Right_T)
    #local MR_Wall_Right_T = MR_Wall_T;
  #end
  
  #ifndef(MR_Ceiling_T)
    #local MR_Ceiling_T = MR_Wall_T;
  #end
  
  #ifndef(MR_Floor_T)
    #local MR_Floor_T = MR_Wall_T;
  #end
  
  #ifndef(MR_Windows_T)
    #local MR_Windows_T = MR_Windows_Default_T;
  #end
  
  #ifndef(MR_Windows_Use_Glass)
    #local MR_Windows_Use_Glass = no;
  #end
  
  #ifndef(MR_Windows_Glass_M)
    #local MR_Windows_Glass_M = MR_Windows_Glass_Default_M;
  #end
  
  #ifdef(MR_Windows_Thickness)  
    #local W_Th = MR_Windows_Thickness;
  #else
    #local W_Th = 0.5;
  #end
  
  #ifndef(MR_Crown)
    #local MR_Crown = no;
  #end
  
  #ifndef(MR_Crown_T)
    #local MR_Crown_T = MR_Windows_T;
  #end
  
  #ifndef(MR_Crown_Shape)
    #local MR_Crown_Shape = MR_Crown_Default_Shape;
  #end
  
  #ifndef(MR_Baseboard)
    #local MR_Baseboard = no;
  #end
  
  #ifndef(MR_Baseboard_T)
    #local MR_Baseboard_T = MR_Windows_T;
  #end
  
  #ifndef(MR_Baseboard_Shape)
    #local MR_Baseboard_Shape = MR_Baseboard_Default_Shape;
  #end
  
  #ifndef(MR_Doors_Align)
    #local MR_Doors_Align = yes;
  #end
  
  #ifndef(MR_Doors_T)
    #local MR_Doors_T = MR_Windows_T;
  #end
  
  #ifdef(MR_Doors_Thickness)
    #local D_Th = MR_Doors_Thickness;
  #else
    #local D_Th = 0.5;
  #end
  
  //#local SzX = Sz.x + Th * 2;
  //#local SzY = Sz.y + Th * 2;
  //#local SzZ = Sz.z + Th * 2;

  #local SzX = Sz.x;
  #local SzY = Sz.y;
  #local SzZ = Sz.z;

  #local Box_F =    
    function {
      max(
        (abs(x) < y & abs(z) < y) * 1/6,
        (abs(x) < -y & abs(z) < -y) * 2/6,
        (abs(y) < x & abs(z) < x) * 3/6,
        (abs(y) < -x & abs(z) < -x) * 4/6,
        (abs(x) < z & abs(y) < z) * 5/6,
        (abs(x) < -z & abs(y) < -z)
      )
    }
    
  #local Room =
    difference {
      box { -Sz/2 - Th, Sz/2 + Th }
      box { -Sz/2, Sz/2 }
      bounded_by {
        box { -Sz/2 - Th, Sz/2 + Th }
      }        
      texture {
        function { Box_F(x/SzX, y/SzY, z/SzZ) }
        texture_map {
          [1/6 MR_Ceiling_T]
          [2/6 MR_Floor_T]
          [3/6 MR_Wall_Right_T]
          [4/6 MR_Wall_Left_T]
          [5/6 MR_Wall_Back_T]
          [6/6 MR_Wall_Front_T]
        }
      }
    }
    
  #local WC_Count = 0;
  #local WF_Count = 0;
  #local WG_Count = 0;

  #ifdef(MR_Windows)
    #local W_Count = dimension_size(MR_Windows, 1);
    #local Window_Cuts = array[W_Count];
    #local Window_Frames = array[W_Count];
    #local Window_Glass = array[W_Count];
    #local Norm = <0, 0, 0>;
    
    #local Ct =  0;
    #while(Ct < W_Count)
      #local W_Type = MR_Windows[Ct];
      #local W_Size = MR_Windows_Size[Ct] * <1, 1, 0> + z * (W_Th * 2 + Th);
      #local W_Pos = MR_Windows_Pos[Ct] * <1, 1, 1>;
      #local W_Side = MR_Windows_Side[Ct] * <1, 1, 1>;
      
      #if(W_Type < 0 | W_Type > 9 | W_Type != int(W_Type))
        #error "MakeRoom: Invalid window type.\n"
      #end
      
      #switch(W_Type)
        #range(0, 4)
        
          #local Window_Cuts[Ct] = box { -W_Size/2, W_Size/2 }
            
          #if(MR_Windows_Use_Glass)
            #local Window_Glass[Ct] =
              box { <-W_Size.x/2, -W_Size.y/2, -W_Th/4>,
                    <W_Size.x/2, W_Size.y/2, W_Th/4>  }
          #end

          #if(W_Type > 0)
            #local Window_Frames[Ct] =
              difference {
                box { -W_Size/2, W_Size/2 }
                box { <-W_Size.x/2 + W_Th, -W_Size.y/2 + W_Th, -W_Size.z>,
                      <W_Size.x/2 - W_Th, W_Size.y/2 - W_Th, W_Size.z> }
                bounded_by {
                  box { -W_Size/2, W_Size/2 }
                }
              }
              
            #if(W_Type > 1)
              #local Window_Frames[Ct] =
                union { 
                  object { Window_Frames[Ct] }
                  #if(W_Type = 2 | W_Type = 4)
                    box { <-W_Th/3, -W_Size.y/2, -W_Th/3>,
                          <W_Th/3, W_Size.y/2, W_Th/3> }
                  #end
                  #if(W_Type = 3 | W_Type = 4)
                    box { <-W_Size.x/2, -W_Th/3, -W_Th/3>,
                          <W_Size.x/2,  W_Th/3, -W_Th/3> }
                  #end
                }
            #end
          #end
        #break
        
        #range(5, 9)
          #local Window_Cuts[Ct] = 
            cylinder {
              z * -W_Size.z/2, z * W_Size.z/2, 0.5
              scale <W_Size.x, W_Size.y, 1>
            }
            
          #if(MR_Windows_Use_Glass)
            #local Window_Glass[Ct] =
              cylinder {
                z * -W_Th/4, z * W_Th/4, 0.5
                scale <W_Size.x, W_Size.y, 1>
              }
          #end

          #if(W_Type > 5)
            #local Window_Frames[Ct] =
              difference {
                object { Window_Cuts[Ct] }
                cylinder {
                  z * -W_Size.z, z * W_Size.z, 0.5
                  scale <W_Size.x - W_Th * 2, W_Size.y - W_Th * 2, 1>
                }
                bounded_by { Window_Cuts[Ct] }
              }
            
            #if(W_Type > 6)
              #local Window_Frames[Ct] =
                union {
                  object { Window_Frames[Ct] }
                  #if(W_Type = 7 | W_Type = 9)
                    cylinder { y * (-W_Size.y/2 + W_Th/2), y * (W_Size.y/2 - W_Th/2), W_Th/3 }
                  #end
                  #if(W_Type = 8 | W_Type = 9)
                    cylinder { x * (-W_Size.x/2 + W_Th/2), x * (W_Size.x/2 - W_Th/2), W_Th/3 }
                  #end
                }
            #end
          #end
        #break
      #end
      
      #local Pos = trace(Room, W_Pos, W_Side, Norm);
      #if(VZero(Norm))
        #error "MakeRoom: Invalid window position.\n"
      #else
        #local Pos = MR_Extend(W_Pos, Pos, Th/2);
      #end
      
      #local Trans =
        transform {
          Reorient_Trans(-z, W_Side)
          translate Pos
        }
        
      #ifdef(Window_Cuts[Ct])
        #local Window_Cuts[Ct] =
          object {
            Window_Cuts[Ct]
            texture { MR_Windows_T }
            transform { Trans }
          }
        #local WC_Count = WC_Count + 1;
      #end
      
      #ifdef(Window_Frames[Ct])
        #local Window_Frames[Ct] =
          object {
            Window_Frames[Ct]
            texture { MR_Windows_T }
            transform { Trans }
          }
        #local WF_Count = WF_Count + 1;
      #end
      
      #ifdef(Window_Glass[Ct])
        #local Window_Glass[Ct] =
          object {
            Window_Glass[Ct]
            #ifdef(MR_Windows_Glass_Photons)
              photons{
                target MR_Windows_Glass_Photons.x
                reflection MR_Windows_Glass_Photons.y
                refraction MR_Windows_Glass_Photons.z
                collect MR_Windows_Glass_Photons.t
              }
            #end
            material { MR_Windows_Glass_M }
            transform { Trans }
          }
        #local WG_Count = WG_Count + 1;
      #end
      
      

      #local Ct = Ct + 1;
    #end
  #end
  
  #local DC_Count = 0;
  #local DF_Count = 0;
  
  #ifdef(MR_Doors)
    #local D_Count = dimension_size(MR_Doors, 1);
    #local Door_Cuts = array[D_Count];
    #local Door_Frames = array[D_Count];
    #local Norm = <0, 0, 0>;
    
    #local Ct = 0;
    #while(Ct < D_Count)
      #local D_Type = MR_Doors[Ct];
      #local D_Side = MR_Doors_Side[Ct] * <1, 1, 1>;
      #local D_Size = MR_Doors_Size[Ct] * <1, 1, 0> + z * (2 * D_Th + Th);
      #local D_Pos = MR_Doors_Pos[Ct] * <1, 1, 1>;
      
      #if(D_Type != 0 & D_Type != 1)
        #error "MakeRoom: Invalid door type.\n"
      #end
      
      #local Pos = trace(Room, D_Pos, D_Side, Norm);
      #if(VZero(Norm))
        #error "MakeRoom: Invalid door position.\n"
      #else
        #local Pos = MR_Extend(D_Pos, Pos, Th/2);
      #end        

      #declare Trans =
        transform {
          Reorient_Trans(-z, D_Side)
          translate Pos
        }
        
      #local Door_Cuts[Ct] = 
        box { 
          <-D_Size.x/2, -D_Size.y/2, -Sz.z/2>, <D_Size.x/2, D_Size.y/2, Sz.z/2>
          texture { MR_Doors_T }
          transform { Trans }
        }
      
      #if(MR_Doors_Align & abs(D_Side.y) < 0.5)
        #local Door_Cuts[Ct] =
          object {
            Door_Cuts[Ct]
            Align_Trans(Door_Cuts[Ct], -y, y * (-Sz.y/2 + 0.0001))
          }
      #end
      
      #local DC_Count = DC_Count + 1;
      
      #if(D_Type = 1)
        #local Door_Frames[Ct] =
          difference {
            box { -D_Size/2, D_Size/2 }
            box { <-D_Size.x/2 + D_Th, -D_Size.y, -D_Size.z>,
                  <D_Size.x/2 - D_Th, D_Size.y/2 - D_Th, D_Size.z> }
            bounded_by {
              box { -D_Size/2, D_Size/2 }
            }
            texture { MR_Doors_T }
            transform { Trans }
          }
        
        #if(MR_Doors_Align & abs(D_Side.y) < 0.5)
          #local Door_Frames[Ct] =
            object {
              Door_Frames[Ct]
              Align_Trans(Door_Frames[Ct], -y, y * (-Sz.y/2 + 0.0001))
            }
        #end
        
        #local DF_Count = DF_Count + 1;
      #end
            
      #local Ct = Ct + 1;
    #end
  #end            
  
  #if(WC_Count > 0)
    #local Room = 
      difference {
        object { Room }

        #local Ct = 0;
        #while(Ct < W_Count)
          #ifdef(Window_Cuts[Ct])
            object { Window_Cuts[Ct] }
          #end
          #local Ct = Ct + 1;
        #end
        
        //cutaway_textures
        
        bounded_by {
          box { -Sz/2 - Th, Sz/2 + Th }
        }
      }
  #end      

  #if(WF_Count > 0 | WG_Count > 0 | MR_Baseboard | MR_Crown)
    #local Room =
      union {
        object { Room }
        
        #if(WF_Count > 0 | WG_Count > 0)
          #local Ct = 0;
          #while(Ct < W_Count)
            #ifdef(Window_Frames[Ct])
              object { Window_Frames[Ct] }
            #end
            #ifdef(Window_Glass[Ct])
              object { Window_Glass[Ct] }
            #end
            #local Ct = Ct + 1;
          #end
        #end
        
        #if(MR_Baseboard)
          #local Trans =
            transform {
              Center_Trans(MR_Baseboard_Shape, x)
              Align_Trans(MR_Baseboard_Shape, z - y, <0, 0, 0>)
            }
        
          object {
            MR_Baseboard_Shape
            transform { Trans }
            scale <Sz.x, 1, 1>
            texture { MR_Baseboard_T }
            translate <0, -Sz.y/2, Sz.z/2>
          }
          object {
            MR_Baseboard_Shape
            transform { Trans }
            scale <Sz.x, 1, 1>
            texture { MR_Baseboard_T }
            rotate y * 180
            translate <0, -Sz.y/2, -Sz.z/2>
          }
          object {
            MR_Baseboard_Shape
            transform { Trans }
            scale <Sz.z, 1, 1>
            texture { MR_Baseboard_T }
            rotate y * -90
            translate <-Sz.x/2, -Sz.y/2, 0>
          }
          object {
            MR_Baseboard_Shape
            transform { Trans }
            scale <Sz.z, 1, 1>
            texture { MR_Baseboard_T }
            rotate y * 90
            translate <Sz.x/2, -Sz.y/2, 0>
          }
        #end
        
        #if(MR_Crown)
          #local Trans =
            transform {
              Center_Trans(MR_Crown_Shape, x)
              Align_Trans(MR_Crown_Shape, y + z, <0, 0, 0>)
            }
            
            object {
              MR_Crown_Shape
              transform { Trans }
              scale <Sz.x, 1, 1>
              texture { MR_Crown_T }
              translate <0, Sz.y/2, Sz.z/2>
            }
            object {
              MR_Crown_Shape
              transform { Trans }
              scale <Sz.x, 1, 1>
              texture { MR_Crown_T }
              rotate y * 180
              translate <0, Sz.y/2, -Sz.z/2>
            }
            object {
              MR_Crown_Shape
              transform { Trans }
              scale <Sz.z, 1, 1>
              texture { MR_Crown_T }
              rotate y * -90
              translate <-Sz.x/2, Sz.y/2, 0>
            }
            object {
              MR_Crown_Shape
              transform { Trans }
              scale <Sz.z, 1, 1>
              texture { MR_Crown_T }
              rotate y * 90
              translate <Sz.x/2, Sz.y/2, 0>
            }
        #end
      }
  #end
  
  #if(DC_Count > 0)
    #local Room =
      difference {
        object { Room }
        
        #local Ct = 0;
        #while(Ct < D_Count)
          #ifdef(Door_Cuts[Ct])
            object { Door_Cuts[Ct] }
          #end
          #local Ct = Ct + 1;
        #end
       
        //cutaway_textures
        
        bounded_by {
          box { -Sz/2 - Th - W_Th, Sz/2 + Th + W_Th }
        }
      }
  #end
  
  #if(DF_Count > 0)
    #local Room =
      union {
        object { Room }
      
        #local Ct = 0;
        #while(Ct < D_Count)
          #ifdef(Door_Frames[Ct])
            object { Door_Frames[Ct] }
          #end
          #local Ct = Ct + 1;
        #end
      }
  #end
      

  Room
#end 

// MR_Wall_Default_T
// The default texture used for walls if none is specified.
//
#declare MR_Wall_Default_T =
  texture {
    pigment { GreenYellow }
  }

#declare MR_AntiqueWhite = rgb <0.9766, 0.9180, 0.8398>;

// MR_Windows_Default_T
// The default texture used for window frames if none is specified.
//
#declare MR_Windows_Default_T =
  texture {
    pigment { MR_AntiqueWhite }
  }

// MR_Windows_Glass_Default_M
// The default material used for glass panes if none is specified.
//
#declare MR_Windows_Glass_Default_M =
  material {
    texture {
      pigment { rgbf <0.97, 0.99, 0.98, 0.96> }
      finish {
        ambient 0
        diffuse 0
        specular 0.8
        roughness 0.001
        reflection {
          0, 1
          fresnel
        }
        conserve_energy
      }
    }
    interior {
      ior 1.51
      fade_distance 1
      fade_power 1001
      fade_color rgb <0.97, 0.99, 0.98>
    }
  }
  
// MR_Crown_Default_Shape
// The default object for the crown molding.
//
#declare MR_Crown_Default_Shape =
  difference {
    box { 0, <1, 2, 2> }
    cylinder { -x, x * 2, 1.5 }
    bounded_by {
      box { 0, <1, 2, 2> }
    }
  }

// MR_Baseboard_Default_Shape
// The default object for the baseboards.
//
#declare MR_Baseboard_Default_Shape =
  box { 0, <1, 2, 1> }

// MR_Reset
// Unsets all the variables used by MakeRoom.
//
#macro MR_Reset()
  #while(defined(MR_Thickness))
    #undef MR_Thickness
  #end

  #while(defined(MR_Wall_T))
    #undef MR_Wall_T
  #end

  #while(defined(MR_Front_Wall_T))
    #undef MR_Front_Wall_T
  #end

  #while(defined(MR_Back_Wall_T))
    #undef MR_Back_Wall_T
  #end

  #while(defined(MR_Left_Wall_T))
    #undef MR_Left_Wall_T
  #end

  #while(defined(MR_Right_Wall_T))
    #undef MR_Right_Wall_T
  #end

  #while(defined(MR_Ceiling_T))
    #undef MR_Ceiling_T
  #end

  #while(defined(MR_Floor_T))
    #undef MR_Floor_T
  #end

  #while(defined(MR_Windows_T))
    #undef MR_Windows_T
  #end

  #while(defined(MR_Windows_Use_Glass))
    #undef MR_Windows_Use_Glass
  #end

  #while(defined(MR_Windows_Glass_M))
    #undef MR_Windows_Glass_M
  #end

  #while(defined(MR_Windows_Thickness))
    #undef MR_Windows_Thickness
  #end

  #while(defined(MR_Crown))
    #undef MR_Crown
  #end

  #while(defined(MR_Crown_T))
    #undef MR_Crown_T
  #end

  #while(defined(MR_Crown_Shape))
    #undef MR_Crown_Shape
  #end

  #while(defined(MR_Baseboard))
    #undef MR_Baseboard
  #end

  #while(defined(MR_Baseboard_T))
    #undef MR_Baseboard_T
  #end

  #while(defined(MR_Baseboard_Shape))
    #undef MR_Baseboard_Shape
  #end

  #while(defined(MR_Windows))
    #undef MR_Windows
  #end

  #while(defined(MR_Windows_Pos))
    #undef MR_Windows_Pos
  #end

  #while(defined(MR_Windows_Side))
    #undef MR_Windows_Side
  #end

  #while(defined(MR_Windows_Size))
    #undef MR_Windows_Size
  #end

  #while(defined(MR_Windows_Use_Glass))
    #undef MR_Windows_Use_Glass
  #end

  #while(defined(MR_Windows_Glass_Photons))
    #undef MR_Windows_Glass_Photons
  #end
#end

// MR_Extend
// Internal macro used by MakeRoom.  Extends a vector from another vector by a
// specified distance.
//
#macro MR_Extend(From_V, To_V, Distance)
  #local V = To_V - From_V;
  
  #if(vlength(V) = 0)
    #error Cannot Extend zero length vector
  #else
    #local Result = (To_V + vnormalize(To_V - From_V) * Distance);
  #end
  
  Result
#end

#version Makeroom_Inc;
#end
