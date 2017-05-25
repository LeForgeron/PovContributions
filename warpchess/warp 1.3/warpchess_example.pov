//This file is licensed under the terms of the CC-LGPL

#declare UseAreaLight = no;
#declare UseFocalBlur = no;
#declare UseRadiosity = no;

global_settings
{ max_trace_level 10
  ambient_light (UseRadiosity ? 0 : 2)
  #if(UseRadiosity)
    radiosity
    { pretrace_end .01
      count 100
      brightness 3
    }
  #end
}

camera
{ location <3,4,-4>*8 look_at -y*2 angle 35+2
  #if(UseFocalBlur)
    focal_point 0 aperture 3 blur_samples 50 variance 1/10000
  #end
}

/*
camera
{
  ultra_wide_angle
  right x*image_width/image_height
  location <1,2,-4>*5 look_at 0 angle 70
  #if(UseFocalBlur)
    focal_point 0 aperture 1 blur_samples 50 variance 1/10000
  #end
  translate -y
}
*/

light_source
{ <-4,30,-15>*2, 1
  #if(UseAreaLight)
    area_light x*8,y*8,10,10 adaptive 0 orient circular
  #end
}
light_source
{ <10,20,5>*2, <.5,.75,1>*.25
  #if(UseAreaLight)
    area_light x*8,y*8,10,10 adaptive 0 orient circular
  #end
}
plane { y,-1 pigment { rgb <1,.5,0> } }

//---------------------------------------------------------------------------
#include "WarpChess.inc"

#declare Moves = array[8]
{ "E2E4", "E7E5", "G1F3", "B8C6", "D2D3", "F8B4", "B1C3", "G8F6" }

WarpChess_CreateBoard(Moves)
