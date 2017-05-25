// Title:        TrainFaces demo scene
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   May 1, 2008
// Last updated: July 17, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#version 3.61;

#declare Use_Area = yes;

#include "colors.inc"
#include "trainfaces.inc"

global_settings {
  assumed_gamma 1.0
}

#declare Cam_Pt = <0, 4, -8>;

camera {
  location Cam_Pt
  up y
  right x * image_width/image_height
  look_at 0
}

#declare Daylight = rgb <255, 249, 251>/255;

light_source {
  <15, 10, -25>, Daylight * 60
  #if(Use_Area)
    area_light
    x * 10, y * 10, 17, 17
    adaptive 0
    circular
    orient
    jitter
  #end
  fade_power 2
  fade_distance 2
}

light_source {
  <-15, 10, -25>, Daylight * 50
  #if(Use_Area)
    area_light
    x * 10, y * 10, 17, 17
    adaptive 0
    circular
    orient
    jitter
  #end
  fade_power 2
  fade_distance 2
}

background { rgb <0.6, 0.7, 1> }

TF_Set_Defaults()
#declare TF_Show_Chin = no;
#declare TF_Eye_Style = 2;
#declare TF_Eye_Place = <-0.07, -0.05>;
#declare TF_Look_At = <-0.2, 0.4, -1>;
#declare TF_Nose_Place = -0.05;
#declare TF_Nose_Tilt = 10;
#declare TF_Nose_Size = <0.12, 0.04>;
#declare TF_Nose_Length = 0.35;
#declare TF_Mouth_Place = <0, -0.05>;
#declare TF_Brow_Style = 2;
#declare TF_Brow_Place = <0, -0.1>;
#declare TF_Cheek_Rosy = yes;
#declare TF_Cheek_Scale = <1, 1, 0.5>;
#declare TF_File = "tf_cindy_face.inc";
#declare TF_Iso_Segs = <100, 100, 100>;

object { 
  TF_Face()
  rotate y * -45
  translate <-3, 2, 0>
}

TF_Set_Defaults()
#declare TF_Show_Chin = no;
#declare TF_Eye_Scale = <0.75, 0.75>;
#declare TF_Eye_Place = <-0.1, 0>;
#declare TF_Look_At = vrotate(-z, y * -10);
#declare TF_Mouth_Shape = <0.4, 0.02, 0.03>;
#declare TF_Brow_Style = 1;
#declare TF_Brow_Scale = <0.7, 0.7>;
#declare TF_Brow_Place = <-0.1, 0>;
#declare TF_Cheek_Place = <0, -0.04>;
#declare TF_Iso_Segs = <100, 100, 100>;
#declare TF_File = "tf_demo_face_1.inc"

object {
  TF_Face()
  translate y * 2
}

TF_Set_Defaults()
#declare TF_Show_Chin = no;
#declare TF_Eye_Scale = <0.9, 0.8>;
#declare TF_Pupil_Scale = <0.7, 0.7>;
#declare TF_Look_At = vrotate(-z, <-15, 20, 0>);
#declare TF_Nose_Size = <0.1, 0.08>;
#declare TF_Nose_Scale = <1.2, 0.95, 1>;
#declare TF_Nose_Tilt = -3;
#declare TF_Nose_Length   = 0.4;
#declare TF_Mouth_Shape = <0.5, -0.1, 0.05>;
#declare TF_Cheek_Scale = <0.75, 1, 0.9>;
#declare TF_Cheek_Place = <0, -0.28>;
#declare TF_Brow_Style = 3;
#declare TF_Brow_Tilt = 20;
#declare TF_Brow_Place = <0, -0.02>;
#declare TF_File = "tf_demo_face_2.inc";
#declare TF_Iso_Segs = <100, 100, 100>;

object {
  TF_Face()
  rotate y * 45
  translate <3, 2, 0>
}


TF_Set_Defaults()
#declare TF_Show_Brows = no;
#declare TF_Shape = 2;
#declare TF_Eye_Scale = <1, 0.7>;
#declare TF_Look_At = vrotate(-z , <15, -20, 0>);
#declare TF_Eye_Place = <0, 0.29>;
#declare TF_Nose_Length = 0.25;
#declare TF_Nose_Scale = <0.9, 1.3, 1>;
#declare TF_Nose_Size = <0.15, 0.03>;
#declare TF_Nose_Place = 0.2;
#declare TF_Nose_Tilt = 30;
#declare TF_Mouth_Shape = <0.3, 0.01, 0.05>;
#declare TF_Mouth_Pigment = Black;
#declare TF_Cheek_Place = <0, -0.1>;
#declare TF_Cheek_Scale = <1, 1.1, 0.9>;
#declare TF_File = "tf_demo_face_3.inc";

object {
  TF_Face()
  rotate <10, -22.5, 0>
  translate <-1.5, -1, 0>
}

TF_Set_Defaults()
#declare TF_Show_Chin = no;
#declare TF_Shape = 2;
#declare TF_Eye_Scale = <1.3, 1.3>;
#declare TF_Pupil_Scale = <1.3, 1.3>;
#declare TF_Look_At = vrotate(-z, y * 15);
#declare TF_Nose_Tilt = 25;
#declare TF_Nose_Size = <0.1, 0.02>;
#declare TF_Nose_Length = 0.5;
#declare TF_Mouth_Shape = <0.6, 0.08, 0.1>;
#declare TF_Brow_Style = 4;
#declare TF_Brow_Scale = <1.2, 1>;
#declare TF_Brow_Place = <0.025, 0.1>;
#declare TF_Brow_Tilt = 5;
#declare TF_Cheek_Place = <0.1, 0>;
#declare TF_File = "tf_demo_face_4.inc";

object {
  TF_Face()
  rotate <10, 22.5, 0>
  translate <1.5, -1, 0>
}
