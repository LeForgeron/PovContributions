// Title:        PointArrays Linear to Bezier demo scene
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 12, 2008
// Last updated: June 13, 2008
//
// This file is licensed under the terms of the CC-LGPL

#version 3.61;

#declare Font = "arial.ttf";

#default { finish { ambient 1 diffuse 0 } }

#include "colors.inc"
#include "pointarrays.inc"
#include "transforms.inc"

global_settings {
  assumed_gamma 1.0
}

camera {
  location z * -15
  up y
  right x * image_width/image_height
  look_at 0
}

#macro Label_Obj(Object, Label)
  #local Txt = 
    text { 
      ttf Font Label 0.01, 0 
      scale <0.5, 0.5, 1>
    }
  
  union {
    object {
      Object
      Center_Trans(Object, x + z)
      translate y * 0.8
    }
    object {
      Txt
      Center_Trans(Txt, x + z)
      pigment { Red }
    }
  }
#end

#declare Linear = array[6] { <0, 0>, <2, 0>, <2, 2>, <1, 1>, <0, 2>, <0, 0> };

#declare Linear_Obj = 
  object {
    PA_Prism(PA_Linear, PA_Linear, -0.01, 0, Linear, no, no, PA_No_Trans)
    rotate x * -90
  }

object {
  Label_Obj(Linear_Obj, "Linear")
  pigment { Blue }
  //translate <-7.5, 4, 0>
  translate y * 4
}

#declare Title_1 =
  text {
    ttf "arial.ttf" "PA_Linear_To_Bezier:  Round_Size, Round_Str" 0.01, 0
    scale <0.55, 0.55, 1>
  }
  
object {
  Title_1
  pigment { SkyBlue }
  Center_Trans(Title_1, x + z)
  translate y * 3.25
}

#declare St = array[6] { 0, 0.1, 0.3, 0.5, 1, -0.2 };

#declare Count = dimension_size(St, 1);
#declare Ct = 0;
#while(Ct < Count)
  #declare Pts = PA_Linear_To_Bezier(Linear, 0.5, St[Ct]);
  
  #declare Obj =
    object {
      PA_Prism(PA_Bezier, PA_Linear, -0.01, 0, Pts, no, no, PA_No_Trans)
      rotate x * -90
      pigment { Green }
    }
    
  object {
    Label_Obj(Obj, concat("0.5, ", str(St[Ct], 0, 1)))
    translate x * (-7.5 + 15/(Count - 1) * Ct)
  }
    
  #declare Ct = Ct + 1;
#end

#declare Sz = array[6] { 0, 0.3, 0.5, 0.7, 1, -0.3 };

#declare Count = dimension_size(Sz, 1);
#declare Ct = 0;
#while(Ct < Count)
  #declare Pts = PA_Linear_To_Bezier(Linear, Sz[Ct], 0.2);
  
  #declare Obj =
    object {
      PA_Prism(PA_Bezier, PA_Linear, -0.01, 0, Pts, no, no, PA_No_Trans)
      rotate x * -90
      pigment { Yellow }
    }
  
  object {
    Label_Obj(Obj, concat(str(Sz[Ct], 0, 1), ", 0.2"))
    translate <-7.5 + 15/(Count - 1) * Ct, -3.25, 0>
  }
  
  #declare Ct = Ct + 1;
#end

#declare Title_2 =
  text {
    ttf "arial.ttf" "PA_Linear_To_Bezier2:  Round_Str" 0.01, 0
    scale <0.55, 0.55, 1>
  }
  
object {
  Title_2
  pigment { SkyBlue }
  Center_Trans(Title_2, x + z)
  translate y * -4.1
}

#declare Count = dimension_size(St, 1);
#declare Ct = 0;
#while(Ct < Count)
  #declare Pts = PA_Linear_To_Bezier2(Linear, St[Ct]);
  
  #declare Obj =
    object {
      PA_Prism(PA_Bezier, PA_Linear, -0.01, 0, Pts, no, no, PA_No_Trans)
      rotate x * -90
      pigment { Violet }
    }
    
  object {
    Label_Obj(Obj, str(St[Ct], 0, 1))
    translate <-7.5 + 15/(Count - 1) * Ct, -7.25, 0>
  }
    
  #declare Ct = Ct + 1;
#end
  

#debug str(frame_number, 0, 0)

#debug "\n"
