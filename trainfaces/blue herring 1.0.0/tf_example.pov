// Title:        TrainFaces examples
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   July 17, 2008
// Last updated: July 22, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
// +W640 +H480 +A0.1
//
// To render one example add to command line:
//   Declare=Ex=n
// where n is the example number.
//
// To render all examples:
//   +KFI1 +KFF27
//
// Example numbers:
//  1  - TF_Shape
//  2  - TF_Show_Eyes, TF_Show_Nose, TF_Show_Mouth, TF_Show_Cheeks, TF_Show_Brows, TF_Show_Chin
//  3  - TF_Face_T, TF_Face_I
//  4  - TF_Eye_Style
//  5  - TF_Eye_Scale
//  6  - TF_Pupil_Scale
//  7  - TF_Eye_Place
//  8  - TF_Look_At
//  9  - TF_Eye_T, TF_Pupil_T, TF_Eye_I
//  10 - TF_Nose_Place
//  11 - TF_Nose_Tilt
//  12 - TF_Nose_Length
//  13 - TF_Nose_Size
//  14 - TF_Mouth_Shape
//  15 - TF_Mouth_Scale
//  16 - TF_Mouth_Place
//  17 - TF_Mouth_M
//  18 - TF_Brow_Style
//  19 - TF_Brow_Scale
//  20 - TF_Brow_Place
//  21 - TF_Brow_Tilt
//  22 - TF_Brow_T
//  23 - TF_Cheek_Rosy, TF_Rosy_T
//  24 - TF_Cheek_Scale
//  25 - TF_Cheek_Place
//  26 - TF_Chin_Scale
//  27 - TF_Chin_Place
//
#version 3.61;

#declare Use_Area = no;

#if(clock_on)
  #declare Ex = frame_number;
#else
  #ifndef(Ex)
    #declare Ex = 1;
  #end
#end

#include "colors.inc"
#include "trainfaces.inc"
#include "transforms.inc"

global_settings {
  assumed_gamma 1.0
  #if(Ex = 3)
    max_trace_level 6
  #end
}

#declare Cam_Pos = z * -5;

camera {
  location Cam_Pos
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

#switch(Ex)
  // 1 - TF_Shape
  #case(1)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object {
      TF_Face()
      translate x * -1.5
    }
    
    TF_Set_Defaults()
    #declare TF_Shape = 2;
    #declare TF_File = "tf_face_default_square.inc"
    object {
      TF_Face()
      translate x * 1.5
    }
  #break
  
  // 2 - TF_Show_Eyes, TF_Show_Nose, TF_Show_Mouth, TF_Show_Cheeks, TF_Show_Brows, TF_Show_Chin
  #case(2)
    TF_Set_Defaults()
    #declare TF_Brow_Style = 1;
    #declare TF_Show_Eyes = no;
    object {
      TF_Face()
      translate <-2.5, 1.75, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Brow_Style = 1;
    #declare TF_Show_Nose = no;
    object {
      TF_Face()
      translate <0, 1.75, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Brow_Style = 1;
    #declare TF_Show_Mouth = no;
    object {
      TF_Face()
      translate <2.5, 1.75, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Brow_Style = 1;
    #declare TF_Show_Cheeks = no;
    object {
      TF_Face()
      translate <-2.5, -1.75, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Brow_Style = 1;
    #declare TF_Show_Brows = no;
    object {
      TF_Face()
      translate <0, -1.75, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Brow_Style = 1;
    #declare TF_Show_Chin = no;
    object {
      TF_Face()
      translate <2.5, -1.75, 1>
    }
  #break    
  
  // 3 - TF_Face_T, TF_Face_I
  #case(3)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Face_T =
      texture {
        pigment { LimeGreen }
        finish {
          specular 0.75
          roughness 0.0001
          reflection {
            0, 1
            fresnel
          }
          conserve_energy
        }
      }
    #declare TF_Face_I =
      interior {
        ior 1.71
      }
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Face_T =
      texture {
        pigment { rgb <0.96, 0.8, 0.69> }
      }
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break
    

  // 4 - TF_Eye_Style
  #case(4)
    TF_Set_Defaults()
    #declare TF_Eye_Style = 1;
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object {
      TF_Face()
      translate x * -1.5
    }
    
    TF_Set_Defaults()
    #declare TF_Eye_Style = 2;
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object {
      TF_Face()
      translate x * 1.5
    }
  #break

  // 5 - TF_Eye_Scale
  #case(5)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Eye_Scale = <1.5, 1.5>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Eye_Scale = <0.75, 0.75>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Eye_Scale = <1.25, 1>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Eye_Scale = <1, 1.25>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break
  
  // 6 - TF_Pupil_Scale
  #case(6)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Pupil_Scale = <1.5, 1.5>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Pupil_Scale = <0.75, 0.75>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Pupil_Scale = <1.25, 1>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Pupil_Scale = <1, 1.25>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 7 - TF_Eye_Place
  #case(7)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Eye_Place = <-0.1, 0>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Eye_Place = <0.1, 0>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Eye_Place = <0, -0.1>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Eye_Place = <0, 0.1>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break
  
  // 8 - TF_Look_At
  #case(8)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Look_At = <0, -0.5, -1>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Look_At = <-0.5, 0, -1>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Look_At = <0.5, 0.5, -1>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Look_At = <0, 0.5, -1>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break
  
  // 9 - TF_Eye_T, TF_Pupil_T, TF_Eye_I
  #case(9)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object { 
      TF_Face() 
      translate <-1.5, 0, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Eye_T =
      texture {
        pigment { LightBlue }
        finish {
          specular 0.75
          roughness 0.0001
          reflection {
            0. 1
            fresnel
          }
          conserve_energy
        }
      }
    #declare TF_Eye_I =
      interior {
        ior 1.71
      }
    #declare TF_Pupil_T = 
      texture {
        TF_Eye_T
        pigment { DarkGreen }
      }
    object { 
      TF_Face()
      translate <1.5, 0, 1>
    }
    
  #break

  // 10 - TF_Nose_Place
  #case(10)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Place = -0.1;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Place = 0.1;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 11 - TF_Nose_Tilt
  #case(11)
    TF_Set_Defaults()
    #declare TF_Nose_Length = 0.45;
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Length = 0.45;
    #declare TF_Nose_Tilt = 30;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Length = 0.45;
    #declare TF_Nose_Tilt = -30;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 12 - TF_Nose_Length
  #case(12)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Length = 0.45;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Length = 0.1;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 13 - TF_Nose_Size
  #case(13)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Size = <0.2, 0.2>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Nose_Size = <0.15, 0.05>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 14 - TF_Mouth_Shape
  #case(14)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Mouth_Shape = <0.6, -0.05, -0.1>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Mouth_Shape = <0.3, 0.05, 0.1>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Mouth_Shape = <0.6, 0, 0>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Mouth_Shape = <0.6, 0.15, -0.2>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break
  
  // 15 - TF_Mouth_Scale
  #case(15)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Mouth_Scale = <1.5, 1>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Mouth_Scale = <1, 1.5>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Mouth_Scale = <1.5, 1.5>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Mouth_Scale = <0.5, 0.5>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break
  
  // 16 - TF_Mouth_Place
  #case(16)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Mouth_Place = <-0.15, 0>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Mouth_Place = <0, -0.15>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Mouth_Place = <0.15, 0.15>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Mouth_Place = <-0.15, -0.15>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 17 - TF_Mouth_M  
  #case(17)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object { 
      TF_Face() 
      translate <-1.5, 0, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Mouth_M =
      material {
        texture {
          pigment { Black }
          finish {
            specular 0.9
            roughness 0.0001
            reflection {
              0, 1
              fresnel
            }
            conserve_energy
          }
        }
        interior {
          ior 1.51
        }
      }
    object { 
      TF_Face()
      translate <1.5, 0, 1>
    }
    
  #break

  // 18 - TF_Brow_Style
  #case(18)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 2;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 3;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 4;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 19 - TF_Brow_Scale
  #case(19)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Scale = <2, 2>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Scale = <0.5, 0.5>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Scale = <2, 1>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Scale = <1, 2>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 20 - TF_Brow_Place
  #case(20)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Place = <-0.1, 0>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Place = <0.1, 0>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Place = <0, -0.1>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_Place = <0, 0.1>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 21 - TF_Brow_Tilt
  #case(21)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 3;
    object { 
      TF_Face()
      translate z
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 3;
    #declare TF_Brow_Tilt = 45;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 3;
    #declare TF_Brow_Tilt = -45;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 22 - TF_Brow_T  
  #case(22)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    object { 
      TF_Face() 
      translate <-1.5, 0, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Brow_Style = 1;
    #declare TF_Brow_T =
      texture {
        TF_Default_Brow_T
        pigment { OrangeRed }
      }
    object { 
      TF_Face()
      translate <1.5, 0, 1>
    }
    
  #break

  // 23 - TF_Cheek_Rosy, TF_Rosy_T
  #case(23)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    object { 
      TF_Face()
      translate z
    }

    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Cheek_Rosy = yes;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    #declare TF_Name = "TF_Face_Default_Round";
    #declare TF_Cheek_Rosy = yes;
    #declare TF_Rosy_T =
      texture {
        TF_Default_Rosy_T
        pigment { rgb <177, 244, 231>/255 }
      }
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 24 - TF_Cheek_Scale
  #case(24)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Cheek_Scale = <1.5, 1, 1>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Cheek_Scale = <1, 1.5, 1>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Cheek_Scale = <1, 1, 1.5>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Cheek_Scale = <0.5, 0.5, 0.5>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 25 - TF_Cheek_Place
  #case(25)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Cheek_Place = <-0.2, 0>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Cheek_Place = <0.2, 0>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Cheek_Place = <-0.1, -0.2>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Cheek_Place = <0.1, 0.2>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 26 - TF_Chin_Scale
  #case(26)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Chin_Scale = <1.5, 1, 1>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Chin_Scale = <1, 1.5, 1>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Chin_Scale = <1, 1, 1.5>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Chin_Scale = <0.5, 0.5, 0.5>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break

  // 27 - TF_Chin_Place
  #case(27)
    TF_Set_Defaults()
    #declare TF_File = "tf_face_default_round.inc";
    object { 
      TF_Face() 
      translate z
    }
    
    TF_Set_Defaults()
    #declare TF_Chin_Place = <0, -0.2>;
    object { 
      TF_Face()
      translate <-2, 1.5, 1>
    }
    
    TF_Set_Defaults()
    #declare TF_Chin_Place = <0, 0.2>;
    object {
      TF_Face()
      translate <2, 1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Chin_Place = <0.2, 0>;
    object {
      TF_Face()
      translate <-2, -1.5, 1>
    }

    TF_Set_Defaults()
    #declare TF_Chin_Place = <0.2, -0.2>;
    object {
      TF_Face()
      translate <2, -1.5, 1>
    }
  #break
#end
