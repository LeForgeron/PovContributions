// Title:        TrainFaces
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   May 1, 2008
// Last updated: July 18, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(Trainfaces_Inc)
  #declare Trainfaces_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including trainfaces.inc\n"
#end

#include "functions.inc"
#include "math.inc"
#include "shapes.inc"
#include "tf_extra.inc"
#include "tf_textures.inc"
#include "transforms.inc"

// TF_Face
// 
// Variables:
//  TF_Shape -
//   Type:    Integer
//   Default: 1
//   Use:     Defines the overal shape of the face.  Currently there are two shapes defined:
//              1 - Rounded circular
//              2 - Rounded square
//
//  TF_Show_Eyes -
//   Type:    Boolean
//   Default: on
//   Use:     Enables/disables creation of eyes and eye sockets.  If disabled, eye related
//            options have no effect.
//
//  TF_Show_Nose -
//   Type:    Boolean
//   Default: on
//   Use:     Enables/disables creation of a nose.  If disabled, nose related options have 
//            no effect.
//
//  TF_Show_Mouth -
//   Type:    Boolean
//   Default: on
//   Use:     Enables/disables creation of a mouth.  If disabled, mouth related options have 
//            no effect.
//
//  TF_Show_Cheeks -
//   Type:    Boolean
//   Default: on
//   Use:     Enables/disables creation of cheeks.  If disabled, cheek related options have 
//            no effect.  An exception to this is that TF_Cheek_Rosy still functions, and
//            TF_Cheek_Scale will affect the size of the coloring.
//
//  TF_Show_Brows -
//   Type:    Boolean
//   Default: on
//   Use:     Enables/disables creation of eyebrows.  If disabled, brow related options have 
//            no effect.  Additionally TF_Brow_Style must be a value other than zero if
//            eyebrows are to be visible.
//
//  TF_Show_Chin -
//   Type:    Boolean
//   Default: on
//   Use:     Enables/disables creation of a chin.  If disabled, chin related options have 
//            no effect.
//
//  TF_Face_T -
//   Type:    Texture
//   Default: TF_Default_Face_T
//   Use:     The texture to be applied to the face.
//
//  TF_Face_I -
//   Type:    Interior
//   Default: TF_Default_Face_I
//   Use:     The interior to be applied to the face object.
//
//  TF_Eye_Style -
//   Type:    Integer
//   Default: 1
//   Use:     Defines the style of the eye/pupil.  Currently the following styles are defined:
//              1 - Elliptical eye and pupils
//              2 - Elliptical eye and pupils, with sylized pupil highlight
//  
//  TF_Eye_Scale -
//   Type:    2D vector
//   Default: <1, 1>
//   Use:     Defines scaling of the eyes/eye sockets in the x and y directions.  The pupils
//            are not affected by this option, see TF_Pupil_Scale.
//
//  TF_Pupil_Scale -
//   Type:    2D vector
//   Default: <1, 1>
//   Use:     Defines scaling of the pupils only, in the x and y directions.
//
//  TF_Eye_Place -
//   Type:    2D vector
//   Default: <0, 0>
//   Use:     Defines an adjustment to the placement of the eyes in the x and y directions. 
//            A negative x value will move both eyes closer together, while a positive x
//            value will move them further apart.
//
//  TF_Look_At -
//   Type:    3D vector
//   Default: -z
//   Use:     The vector defines the direction both eyes will point in.  The center of each
//            eye is assumed to be at the origin for the purposes of interpreting this value.
//            Reasonable values should be consistant with the fact that a face is initially
//            created faced in the -z direction.
//
//  TF_Eye_T -
//   Type:    Texture
//   Default: TF_Default_Eye_T
//   Use:     Defines the texture to be applied to the eye (except for the pupil.)
//
//  TF_Pupil_T -
//   Type:    Texture
//   Default: TF_Default_Pupil_T
//   Use:     Defines the texture to be applied to the pupils of each eye.
//
//  TF_Eye_I -
//   Type:    Interior
//   Default: TF_Default_Eye_I
//   Use:     Defines the interior that will be applied to each eye object.
//
//  TF_Nose_Place -
//   Type:    Float
//   Default: 0
//   Use:     Adjusts the placement of the nose.  Negative values place it lower on the face,
//            while positive value place it higher.
//
//  TF_Nose_Tilt -
//   Type:    Float
//   Default: 0
//   Use:     Defines the angle at which the nose protrudes from the face.  Negative values
//            tilt upwards, positive downwards.
//
//  TF_Nose_Length -
//   Type:    Float
//   Default: 0.3
//   Use:     Sets the approximate length of the nose from base to tip.
//
//  TF_Nose_Size - 
//   Type:    2D vector
//   Default: <0.15, 0.1>
//   Use:     The nose is roughly cone shaped.  The u and v elements of this vector specify
//            the radius of the cone at the base and tip, respectively.  Generally, u should
//            be less than or equal to v.
//
//  TF_Mouth_Shape -
//   Type:    3D vector
//   Default: <0.6, 0.05, 0.1>
//   Use:     The x component defines the horizontal width of the mouth, from left to right
//            corner.  The y and z values define the vertical offset from the baseline of the
//            mouth of the top and bottom lips.  The smaller of y and z is assumed to be the top
//            lip, with the larger being the bottom.  If y and z are both positive, the mouth is
//            smiling; both negative, frowning; one postive and one negative gives a rounded mouth.
//            Currently setting y and z too close together may not produce the expected result.
//
//  TF_Mouth_Scale -
//   Type:    2D vector
//   Default: <1, 1>
//   Use:     Defines scaling of the mouth in the x and y directions.
//
//  TF_Mouth_Place -
//   Type:    2D vector
//   Default: <0, 0>
//   Use:     Offsets the location of the mouth in the x and y directions.
//
//  TF_Mouth_M -
//   Type:    Material
//   Default: TF_Default_Mouth_M
//   Use:     Defines the material applied to the inside of the mouth.
//
//  TF_Brow_Style -
//   Type:    Integer
//   Default: 0
//   Use:     Sets what kind of eyebrows are created.  Currently the following styles are defined:
//              0 - No eyebrows
//              1 - Angular, "caret shaped"
//              2 - Curved and tapered
//              3 - Horizontal bars
//              4 - Arcs
//
//  TF_Brow_Scale -
//   Type:    2D vector
//   Default: <1, 1>
//   Use:     Sets the scaling of each eyebrow in the x and y directions.
//
//  TF_Brow_Place - 
//   Type:    2D vector
//   Default: <0, 0>
//   Use:     Offsets the eyebrows location in the x and y directions.  Negative x values
//            will move the brows closer together, positive values move them farther apart.
//
//  TF_Brow_Tilt -
//   Type:    Float
//   Default: 0
//   Use:     Rotates each brow around the z axis by this angle.
//
//  TF_Brow_T -
//   Type:    Texture
//   Default: TF_Default_Brow_T
//   Use:     Sets the texture to be applied to the eyebrows.
//
//  TF_Cheek_Rosy -
//   Type:    Boolean
//   Default: Off
//   Use:     Enables/disables round patches of color on the cheeks.  Note this option still
//            works if cheeks are disabled.
//
//  TF_Cheek_Scale -
//   Type:    3D vector
//   Default: <1, 1, 1>
//   Use:     Sets the scaling of the cheeks and the areas of color if TF_Cheek_Rosy is enabled.
//
//  TF_Cheek_Place -
//   Type:    2D vector
//   Default: <0, 0>
//   Use:     Offset to be applied to the cheek location in the x and y directions.  Negative x
//            values will move the cheeks closer together, positive values further apart.
//
//  TF_Rosy_T -
//   Type:    Texture
//   Default: TF_Default_Rosy_T
//   Use:     Sets the texture to use for the coloration when TF_Cheek_Rosy is enabled.
//
//  TF_Chin_Scale -
//   Type:    3D vector
//   Default: <1, 1, 1>
//   Use:     Sets the scaling of the chin in the x, y, and z directions.
//
//  TF_Chin_Place -
//   Type:    2D vector
//   Default: <0, 0>
//   Use:     Adjusts the location of the chin in the x and y directions.  By default the chin is
//           centered horizontally on the face.  A positive x offset creates a cleft, widening
//           the chin.
//
//  TF_File -
//   Type:    String
//   Default: Empty string
//   Use:     By default the shape of a face is created using an isosurface.  If TF_File is given
//            a non-empty value, it will be considered a file name containing a mesh object
//            defining the face.  If the file name given does not exist, a mesh approximation
//            of the face isosurface will be generated and stored in the file.  This feature
//            is only available if an Isosurface Approximation include file is available, not
//            included in this package.  This will be discussed further below.  If the file
//            does exists, it will be included as the face instead of generating the isosurface.
//            The approximation macro is not necessary to load an existing mesh file.
//
//            If a mesh file is loaded for the face, the shape is fixed and options that change the
//            shape will not function.  The following options can still be changed and will work
//            correctly:  TF_Show_Brows, TF_Eye_Style, TF_Pupil_Scale, TF_Look_At, TF_Eye_T,
//            TF_Pupil_T, TF_Eye_I, TF_Mouth_M, TF_Brow_Style, TF_Brow_Scale, TF_Brow_Place,
//            TF_Brow_Tilt, TF_Brow_T, TF_Cheek_Rosy, TF_Cheek_Scale (rosy only), TF_Cheek_Place
//            (rosy only), TF_Rosy_T, TF_Face_T, TF_Face_I.
//
//            The following options should be set to the same values as when the mesh was created:
//            TF_Show_Eyes, TF_Eye_Scale, TF_Eye_Place.
//
//  TF_Name -
//   Type:    String
//   Default: Empty string
//   Use:     When creating and/or loading a mesh file, if TF_Name is non-empty its value will be
//            interpreted as a variable containing the mesh object.  If the variable is undefined
//            the mesh will be created and/or loaded and assigned to the variable.  If the variable
//            is defined it will be used as the mesh object and any creation/loading will be skipped.
//            This option should be used any time the same mesh file is used more than once in a
//            scene, as it can dramatically reduce both parse time and memory usage.
//
//  TF_Iso_Inc -
//   Type:    String
//   Default: "isosurface_KL_JF_TOK_JF.inc"
//   Use:     Defines the include file name for the Isosurface Approximation include file.  The
//            latest version as of this writing was written by Kevin Loney, Jaap Frank, and
//            Tor Olav Kristensen, and is available here: 
//            http://news.povray.org/47cc76fd%40news.povray.org
//            Some information about its use is available here:
//            http://www.econym.demon.co.uk/isotut/approx.htm
//            
//  TF_Iso_Min -
//   Type:    3D vector
//   Default: Undefined (automatic)
//   Use:     Defines the minimum corner of the container box for the face isosurface.  If undefined
//            it will be calculated automatically.  Generally this should not be changed, but if
//            the face appears clipped it might be useful.
//
//  TF_Iso_Max -
//   Type:    3D vector
//   Default: <1.1, 1.1, 0.25>
//   Use:     Defines the maximum corner of the isosurface container.  Generally it doesn't
//            need to be changed, but it clipping is seen then it might be useful.
//
//  TF_Iso_Segs -
//   Type:    3D vector
//   Default: <100, 100, 100>
//   Use:     Defines the resolution of the mesh approximation.  The higher the values the
//            more accurate the result, but parse time will increase.  If holes appear in
//            the mesh, try increasing this value.
//
//  TF_Iso_Depth -
//   Type:    Integer
//   Default: 0
//   Use:     If greater than zero, the approximation will perform the given number of subdivision
//            steps on the mesh.  This will not close holes, but it will make the mesh smoother.
//            The fairly high setting required for TF_Iso_Segs usually makes this unnecessary.
//
#macro TF_Face()
                   
  #local ES = TF_Eye_Scale * <1, 1>;
  #local PS = TF_Pupil_Scale * <1, 1>;
  #local EP = TF_Eye_Place * <1, 1>;
  #local LA = TF_Look_At * <1, 1>;
  #local NS = TF_Nose_Scale * <1, 1, 1>;
  #local NR = TF_Nose_Size * <1, 1>;
  #local M  = TF_Mouth_Shape * <1, 1, 1>;
  #local MS = TF_Mouth_Scale * <1, 1>;
  #local MP = TF_Mouth_Place * <1, 1>;
  #local BS = TF_Brow_Scale * <1, 1>;
  #local BP = TF_Brow_Place * <1, 1>;
  #local CS = TF_Cheek_Scale * <1, 1, 1>;
  #local CP = TF_Cheek_Place * <1, 1>;
  #local ChS = TF_Chin_Scale * <1, 1, 1>;
  #local ChP = TF_Chin_Place * <1, 1>;

  #local EPX = EP.x;
  #local EPY = EP.y;
  #local ESX = ES.x;
  #local ESY = ES.y;
  #local NSX = NS.x;
  #local NSY = NS.y;
  #local NSZ = NS.z;
  #local NR1 = NR.x;
  #local NR2 = NR.y;
  #local MW  = M.x;
  #local MH1 = min(M.y, M.z);
  #local MH2 = max(M.y, M.z);
  #local MSX = MS.x;
  #local MSY = MS.y;
  #local MPX = MP.x;
  #local MPY = MP.y;
  #local CSX = CS.x;
  #local CSY = CS.y;
  #local CSZ = CS.z;
  #local CPX = CP.x;
  #local CPY = CP.y;
  #local ChSX = ChS.x;
  #local ChSY = ChS.y;
  #local ChSZ = ChS.z;
  #local ChPX = abs(ChP.x);
  #local ChPY = ChP.y;

  #ifndef(TF_Iso_Min)
    #local TF_Iso_Min = <-1.1, -1.1, min(-0.5, -(NR2 + TF_Nose_Length + 0.1) * NS.z)>;
  #end
  
  #if(TF_Show_Eyes)
    #switch(TF_Eye_Style)
      #range(1, 2)
        #local Eye_T =
          texture {
            #if(TF_Eye_Style = 1)
              function { f_r(x, y, 0) }
            #else            
              function { select(f_ph(x, y - 0.08, 0) - pi/10, 1, f_r(x, y, 0)) }
            #end

            texture_map {
              [0     TF_Pupil_T]
              [0.125 TF_Pupil_T]
              [0.125 TF_Eye_T]
              [1     TF_Eye_T]
            }
            rotate z * 45
            scale <PS.x / ES.x, PS.y / ES.y, 1>
          }
    
        #local Eye =
          sphere {
            0, 0.25
            texture { Eye_T }
            interior { TF_Eye_I }
            Reorient_Trans(-z, TF_Look_At)
            scale <ES.x, ES.y, 1/5>
          }
      #break
   
      #else
        #error "TF_Face: Invalid eye style.\n"
    #end
  #end
  
  #if(TF_Show_Brows)
    #switch(TF_Brow_Style)
      #case(0)
      #break
    
      #case(1)
        #local Brow =
          sphere_sweep {
            linear_spline
            3,
            <-0.08, -0.06, 0>, 0.01,
            0, 0.02
            <0.08, -0.06, 0>, 0.01
            scale <1, 1, 10>
          }
      #break
    
      #case(2)
        #local Brow =
          sphere_sweep {
            cubic_spline
            5,
            <0.3, 0, 0>, 0.03,
            <0.25, 0.02, 0>, 0.03,
            <0.1, 0.02, 0>, 0.02,
            <-0.15, -0.03, 0>, 0.01,
            <-0.2, -0.05, 0>, 0.008
            scale <1, 1, 10>
          }
      #break
      
      #case(3)
        #local Brow = Round_Box_Union(<-0.1, -0.02, -10>, <0.1, 0.02, 10>, 0.02)
      #break
      
      #case(4)
        #local Brow =
          sphere_sweep {
            b_spline
            4,
            <-0.2, -0.15, 0>, 0.02,
            <-0.1, -0.02, 0>, 0.02,
            <0.1, -0.02, 0>, 0.02,
            <0.2, -0.15, 0>, 0.02
            scale <1, 1, 10>
          }
      #break

      #else
        #error "TF_Face: Invalid brow style.\n"
    #end

    #if(TF_Brow_Style > 0)
      #local Brows =
        union {
          object {
            Brow
            scale <BS.x, BS.y, 1>
            rotate z * TF_Brow_Tilt
            translate <-0.4 - BP.x, 0.7 + BP.y, 0>
          }

          object {
            Brow
            scale <-BS.x, BS.y, 1>
            rotate z * -TF_Brow_Tilt
            translate <0.4 + BP.x, 0.7 + BP.y, 0>
          }
        }
    #else
      #local Brows = sphere { 0, 1e-15 }
    #end
  #end
    
  #if(TF_Cheek_Rosy)
    #local Head_T =
      texture {
        spherical
        texture_map {
          [0 TF_Face_T]
          [1 TF_Rosy_T]
        }
        scale <0.3 * CSX, 0.3 * CSY, 1>
        translate <MW/2 * MSX + 0.3 * CSX + 0.1, -0.5 + MPY * MSY + 0.3 * CSY + 0.1, 0>
        warp { repeat x * 3 flip x }
      }
  #else
    #local Head_T = TF_Face_T;
  #end
  
  #if(TF_Show_Nose)
    #local Nose_T =
      function {
        transform {
          scale TF_Nose_Scale
          rotate x * -(TF_Nose_Tilt + 180)
          translate y * TF_Nose_Place
        }
      }
  #end
  
  #if(TF_Show_Mouth)
    #local Mouth_F =
      function {
        max(
          -(-cos(x / (MW - 0.1) * pi) * MH1 - y),
          -cos(x / (MW - 0.1) * pi) * MH2 - y,
          abs(x) - MW / 2 - 0.05
        )
      }
  #end
    
  #local T = 1e-2;
  #local T2 = 1e-10;
  #local T3 = 1e-8; 
  #local T4 = 1e-12;
  
  #local Head_F =
    function {
      (1 + T)
      #switch(TF_Shape)
        #case(1)
          - pow(T, -f_superellipsoid(x, y, z - 1, 1, 0.2))
        #break
          d
        #case(2)
          - pow(T, -f_superellipsoid(x, y, z - 1, 0.2, 0.2))
        #break
          
        #else
          #error "TF_Face: Invalid shape.\n"
      #end
    
      #if(TF_Show_Cheeks)
        - pow(T, f_sphere((x - 0.5 - CPX)/CSX, (y - CPY)/CSY, z/CSZ, 0.15))
        - pow(T, f_sphere((x + 0.5 + CPX)/CSX, (y - CPY)/CSY, z/CSZ, 0.15))
      #end

      #if(TF_Show_Nose)
        #local N_Count = max(3, int(TF_Nose_Length * 10) + 1);
        #local Ct = 0;
        #while(Ct < N_Count)
          #local N_Pt = Nose_T(0, 0, adj_range2(Ct, 0, N_Count - 1, 0, TF_Nose_Length));
          #local N_X = N_Pt.x;
          #local N_Y = N_Pt.y;
          #local N_Z = N_Pt.z;
          #local N_R = adj_range2(Ct, 0, N_Count - 1, NR1, NR2);
          
          - pow(T3, f_sphere(x - N_X, y - N_Y, z - N_Z, N_R))
           
          #local Ct = Ct + 1;
        #end
      #end
      
      #if(TF_Show_Eyes)
        + pow(T2, f_sphere((x - 0.4 - EPX) / ESX, (y - 0.25 - EPY) / ESY, 0, 0.23))
        + pow(T2, f_sphere((x + 0.4 + EPX) / ESX, (y - 0.25 - EPY) / ESY, 0, 0.23))
      #end
      
      #if(TF_Show_Mouth)
        + pow(1e-20, Mouth_F((x - MPX) / MSX, (y + 0.5 - MPY) / MSY, z))
      #end
      
      #if(TF_Show_Chin)
        - pow(1e-4, f_sphere((x - ChPX) / ChSX, (y + 0.8 - ChPY) / ChSY, z / ChSZ, 0.05))
        #if(ChPX > 0)
          - pow(1e-4, f_sphere((x + ChPX) / ChSX, (y + 0.8 - ChPY) / ChSY, z / ChSZ, 0.05))
        #end
      #end
    }
    
  #local Iso = yes;
  
  #if(strlen(TF_File) > 0)
    #if(file_exists(TF_File))
      #local Head = TF_Load_Mesh(TF_File, TF_Name);
      #local Iso = no;
    #else
      #if(!file_exists(TF_Iso_Inc))
        #warning concat("TF_Face: Isosurface approximation include file: \"",
                        TF_Iso_Inc, "\", is not found.  Face mesh will ",
                        "not be created.  Using true isosurface instead.\n")
      #else
        #local Fn = Head_F;
        #local isoSmooth = yes;
        #local isoMin = TF_Iso_Min;
        #local isoMax = TF_Iso_Max;
        #local isoFileOption = 1;
        #local isoFile = TF_File;
        #local isoSegs = TF_Iso_Segs;
        #local Depth = TF_Iso_Depth;
        
        #ifdef(T_Fn)
          #undef T_Fn
        #end
        
        #ifdef(GX_Fn)
          #undef GX_Fn
        #end
        
        #ifdef(GY_Fn)
          #undef GY_Fn
        #end

        #ifdef(GZ_Fn)
          #undef GZ_Fn
        #end
        
        #local Head =
          #include TF_Iso_Inc
          
        #local Iso = no;
      #end
    #end
  #end

  #if(Iso)
    #local Head =
      isosurface {
        function { Head_F(x, y, z) }
        contained_by {
          box { TF_Iso_Min, TF_Iso_Max }
        }
        evaluate TF_Iso_Calc_Evaluate(150, 0, 0)
      }
  #end
    
  #local Face_T =
    texture {
      #if(TF_Show_Brows)
        object {
          Brows
          texture { Head_T }
          texture { TF_Brow_T }
        }
      #else
        Head_T
      #end
    }

  #if(TF_Show_Eyes | TF_Show_Mouth)
  union {
  #else
  object {
  #end
    object { Head }
    
    #if(TF_Show_Eyes)
      object {
        Eye
        translate <0.4 + EP.x, 0.25 + EP.y, 0.1>
      }
      object {
        Eye
        translate <-0.4 - EP.x, 0.25 + EP.y, 0.1>
      }
    #end
    
    #if(TF_Show_Mouth)
      difference {
        cylinder { z * 0.075, z * 0.1, 0.9 }
        plane { -y, 0 }
        bounded_by {
          box { <-0.9, -0.9, 0.075>, <0.9, 0, 0.1> }
        }
        material { TF_Mouth_M }
      }
    #end
    
    texture { Face_T }
    interior { TF_Face_I }    
    
    translate z * -0.25
  }
#end

#macro TF_Set_Defaults()
  #declare TF_Shape         = 1;
  #declare TF_Show_Eyes     = yes;
  #declare TF_Show_Nose     = yes;
  #declare TF_Show_Mouth    = yes;
  #declare TF_Show_Cheeks   = yes;
  #declare TF_Show_Brows    = yes;
  #declare TF_Show_Chin     = yes;
  #declare TF_Face_T        = TF_Default_Face_T;
  #declare TF_Face_I        = TF_Default_Face_I;
  #declare TF_Eye_Style     = 1;
  #declare TF_Eye_Scale     = <1, 1>;
  #declare TF_Pupil_Scale   = <1, 1>;
  #declare TF_Eye_Place     = <0, 0>;
  #declare TF_Look_At       = -z;
  #declare TF_Eye_T         = TF_Default_Eye_T;
  #declare TF_Pupil_T       = TF_Default_Pupil_T;
  #declare TF_Eye_I         = TF_Default_Eye_I;
  #declare TF_Nose_Scale    = <1, 1, 1>;
  #declare TF_Nose_Place    = 0;
  #declare TF_Nose_Tilt     = 0;
  #declare TF_Nose_Length   = 0.3;
  #declare TF_Nose_Size     = <0.15, 0.1>;
  #declare TF_Mouth_Shape   = <0.6, 0.05, 0.1>;
  #declare TF_Mouth_Scale   = <1, 1>;
  #declare TF_Mouth_Place   = <0, 0>;
  #declare TF_Mouth_M       = TF_Default_Mouth_M;
  #declare TF_Brow_Style    = 0;
  #declare TF_Brow_Scale    = <1, 1>;
  #declare TF_Brow_Place    = <0, 0>;
  #declare TF_Brow_Tilt     = 0;
  #declare TF_Brow_T        = TF_Default_Brow_T;
  #declare TF_Cheek_Rosy    = no;
  #declare TF_Cheek_Scale   = <1, 1, 1>;
  #declare TF_Cheek_Place   = <0, 0>;
  #declare TF_Rosy_T        = TF_Default_Rosy_T;
  #declare TF_Chin_Scale    = <1, 1, 1>;
  #declare TF_Chin_Place    = <0, 0>;
  #declare TF_File          = "";
  #declare TF_Name          = "";
  #declare TF_Iso_Inc       = "isosurface_KL_JF_TOK_JF.inc";
  #declare TF_Iso_Max       = <1.1, 1.1, 0.25>;
  #declare TF_Iso_Segs      = <100, 100, 100>;
  #declare TF_Iso_Depth     = 0;

  #while(defined(TF_Iso_Min))
    #undef TF_Iso_Min
  #end
  
#end

TF_Set_Defaults() 

#version Trainfaces_Inc;
#end

