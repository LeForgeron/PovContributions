//
// displaycase.pov
// ---------------
// Created by Chris Bartlett Aug 2009
//
// The 'DisplayCase' macros allow you to add a variety of different types of display 
// case to your scene. These are sealed glass cases on a base that can contain some
// sort of exhibit.
//
// This scene file illustrates the use of the 'DisplayCase' macros in 'displaycase.inc'. 
// See displaycase.html for a full list of settings and illustrations of these examples.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 1 metre
// Each example typically takes between 10 and 30 seconds to render.


// This file contains a series of separate examples, controlled using the 
// 'Example' variable. 
//
//   Example = 0   Performs the simplest macro call.
//   Example = 1   Uses parameters on the macro call and transforms the returned object.
//   Example = 2   Illustrates how to specify configuration options.
//   Example = 3   Illustrates some of the configuration options available.
//   Example = 4   A simple rope barrier.
//   Example = 5   A detailed view of the "RopeHook" object on a rope barrier.
//   Example = 10 to 13   Illustrate the standard display case types.
//   Example = 20 to 24 - Illustrate the "Pedestal", "RoundPillar", "RectangularPillar", "WallMount" and "Tree" mounts.
//   Example = 40  Generate the main image used on the web site and at the top of the documentation.
//
// You can generate a sequence of these examples using animation command-line options 
// (e.g. +kfi0 +kff3 +fj +odisplaycase_0) and the frame_number read-only identifier:
// 
//#declare Example = frame_number;

#declare Example = 0;

// Set up some scene elements that will be used in all of the examples.

// The following line is intended to compensate for differences in default gamma settings between 3.6 and 3.7 and may need adjusting for your purposes.
// In 3.6 a higher assumed_gamma setting results in a darker scene and a lower setting in a lighter scene.
// This setting is no longer supported in 3.7.
#if (version<3.7) global_settings {assumed_gamma 1} #end 

// There is a simple glass material that renders about 2-4 times quicker than the full 
// glass texture by not including reflections.
#declare DisplayCase_SimpleMaterials = false;  // 1=true=yes 0=false=no
   
// Include the macro file
#include "displaycase.inc"              

// The floor
plane { y, 0 DisplayCase_SampleFloorTexture() rotate y*90}

// The wall
plane {-z,-1.8 pigment {rgb <1,0.8,0.3>} finish {ambient 0.02}}   

// Skirting Board
union {  
  box {<-20,0,1.785><20,0.15,1.8>}
  cylinder {<-20,0.15,1.795><20,0.15,1.795>,0.01}
  pigment {rgb 1} 
  finish {ambient 0.02}
}


//-----------------------------------------//
//               The Examples              //
//-----------------------------------------//

// Example 0 - Performs the simplest macro call.
#if (Example=0)
  camera {location <0.6,0.3,-0.5> look_at <0,0.3,0>}
  light_source { <-15,7.5,-15>, rgb 1}
  DisplayCase("","")
#end


// Example 1 - Uses parameters on the macro call and transforms the returned object.
#if (Example=1)
  camera {location <1,1.4,-1> look_at <0,0.95,0>}
  light_source { <-15,7.5,-15>, rgb 1}
  object {DisplayCase("Spherical","RoundPillar") rotate -y*25 translate <-0.4,0,0.3>}
#end 


// Example 2 - Illustrates how to specify configuration options.
#if (Example=2)
  camera {location <1.5,1.7,-1.4> look_at <0,1.05,0>}
  light_source { <-15,7.5,-15>, rgb 1}
  DisplayCase_MarbleMaterial("Yellow")
  #declare DisplayCase_Height = 1.0;
  object {DisplayCase("Cylindrical","RectangularPillar")} 
#end


// Example 3 - Illustrates some of the configuration options available.
#if (Example=3)
  global_settings {max_trace_level 12}
  camera {location <2,1.75,-1.5> look_at <0,1.7,0.75>}
  light_source { <-15,7.5,-25>, rgb 0.05}
  light_source { <-2,3.6,-1.2> color rgb 1 spotlight radius 10 falloff 35 tightness 0 point_at <0,1.5,1.8>}
  // The Shelf on the wall.
  DisplayCase_MarbleMaterial("Black")
  box {<-0.8,1.64,1.2><0.8,1.7,1.8> material {DisplayCase_DefaultMaterial}}

  DisplayCase_Undef()

  // Three cylindrical display cases up on the shelf
  #declare DisplayCase_Height          = 1.0;
  #declare DisplayCase_KickPlateHeight = 0.08;
  #declare DisplayCase_KickPlateInset  = 0.02;
  // The left-most display case.
  #declare DisplayCase_Height          = 1.5;
  #declare DisplayCase_Radius          = 0.15;
  #declare DisplayCase_TopCapHeight    = 0.15;
  #declare DisplayCase_TopRimHeight    = 0.01;
  #declare DisplayCase_JointHeight     = 0.04;
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Red")
  object {DisplayCase("Cylindrical","") translate <-0.5,1.7,1.54>} 
  // The central display case.
  #declare DisplayCase_Height          = 1.0;
  #declare DisplayCase_Radius          = 0.25;
  #declare DisplayCase_TopCapHeight    = 0;
  #declare DisplayCase_TopRimHeight    = 0;
  #declare DisplayCase_JointHeight     = 0.08;
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Green")
  object {DisplayCase("Cylindrical","") translate < 0  ,1.7,1.54>} 
  // The right-most display case.
  #declare DisplayCase_Height          = 1.5;
  #declare DisplayCase_Radius          = 0.15;
  #declare DisplayCase_TopCapHeight    = 0;
  #declare DisplayCase_TopRimHeight    = 0.15;
  #declare DisplayCase_JointHeight     = 0.04;
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Blue")
  object {DisplayCase("Cylindrical","") translate < 0.5,1.7,1.54>} 

  DisplayCase_Undef()

  // A box display case with a base and kick plate that reach down to the floor 
  DisplayCase_MarbleMaterial("Black")
  #declare DisplayCase_Height           = 1.25;                   
  #declare DisplayCase_Depth            = 0.5;                 
  #declare DisplayCase_Width            = 1.6;                 
  #declare DisplayCase_JointHeight      = 0.9;
  #declare DisplayCase_TopRimHeight     = 0;
  #declare DisplayCase_TopCapHeight     = 0;
  #declare DisplayCase_KickPlateHeight  = 0.12;
  #declare DisplayCase_CaseLights       = 0;
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Box","") translate <0,0,1.54>}

  // A second box display case in the foreground 
  #declare DisplayCase_FabricShape = "Rectangular";
  object {DisplayCase("Box","") rotate y*90 translate <1.06,0,0.99>}


//  DisplayCase_Undef()

  // A big box-shaped display case with a lid
  DisplayCase_MarbleMaterial("Black")
  #declare DisplayCase_Height           = 2.2;                   
  #declare DisplayCase_Width            = 1.6;                 
  #declare DisplayCase_Depth            = 0.9;                 
  #declare DisplayCase_JointHeight      = 0.9;
  #declare DisplayCase_TopRimHeight     = 0;
  #declare DisplayCase_TopCapHeight     = 0.3;
  #declare DisplayCase_KickPlateHeight  = 0.12;
  #declare DisplayCase_CaseLights       = 1;
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Box","") rotate -y*90 translate <-1.8,0,0.9>}
#end


// Examples 4 & 5 - A simple rope barrier and a detailed view of the "RopeHook" object.
#if (Example=4 | Example=5)
  #if (Example=4) camera {location <1,1.35,-0.6> look_at <0,0.4,0.5>}    #end
  #if (Example=5) camera {location <0.7,1.05,-0.1> look_at <0.5,0.9,0>}  #end
  light_source { <-15,7.5,-25>, rgb 0.1}
  light_source { <2,3.6,-1.2> color rgb 1 spotlight radius 5 falloff 25 tightness 0 point_at <0,0,0.8>}
  // Add 4 posts to cordon off a small area by the wall
  object {DisplayCase("","BarrierPost") translate <-0.5,0,1.5>}
  object {DisplayCase("","BarrierPost") translate <-0.5,0,0>}
  object {DisplayCase("","BarrierPost") translate < 0.5,0,1.5>}
  object {DisplayCase("","BarrierPost") translate < 0.5,0,0>}
  // Add the rope, positioning an end cap on each end of each rope.
  #if (file_exists("rope.inc")) 
    #include "rope.inc"
    
    #local StartPoint = <0,0.867, 1.364>;
    #local EndPoint   = <0,0.867, 0.136>;
    Rope_AddPoint     (StartPoint)
    #local Rope_Catenary_a = 0.95;
    Rope_Catenary(EndPoint)
    #declare Rope_Radius = 0.03;
    #declare Rope_OuterColor       = <0,0.30,0>;   
    #declare Rope_InnerColor       = Rope_OuterColor*0.25;
    #declare Rope_ShowFibres       = 0;
    #declare RopeObject = Rope_ArrayToRope("")
    object {RopeObject translate -0.5*x}
    object {RopeObject translate  0.5*x}
  
    #declare DisplayCase_CupRadius = 1.05*Rope_Radius;
    object {DisplayCase("","RopeHook") rotate  x*45 translate StartPoint-0.5*x}
    object {DisplayCase("","RopeHook") rotate -x*45 translate EndPoint-0.5*x}
    object {DisplayCase("","RopeHook") rotate  x*45 translate StartPoint+0.5*x}
    object {DisplayCase("","RopeHook") rotate -x*45 translate EndPoint+0.5*x}
  
    Rope_Undef()
    
    #local StartPoint = <-0.441,0.85,-0.05>;
    #local EndPoint   = < 0.441,0.85,-0.05>;
    Rope_AddPoint     (StartPoint)
    #local Rope_Catenary_a = 0.3;
    Rope_Catenary(EndPoint)
    #declare Rope_Radius = 0.03;
    #declare Rope_OuterColor       = <0,0.30,0>;   
    #declare Rope_InnerColor       = Rope_OuterColor*0.25;
    #declare Rope_ShowFibres       = 0;
    object {Rope_ArrayToRope("")}
    // Cap the ends of the front rope
    object {DisplayCase("","RopeHook") rotate <0,90, 25> translate StartPoint}
    object {DisplayCase("","RopeHook") rotate <0,90,-25> translate EndPoint}
  #end
  // Add a few more randomly positioned posts within the cordon
  DisplayCase_Undef()
  DisplayCase_MarbleMaterial("Yellow")
  object {DisplayCase("","BarrierPost") translate <-0.2 ,0,0.5>}
  DisplayCase_Undef()
  DisplayCase_MarbleMaterial("Black")
  object {DisplayCase("","BarrierPost") translate < 0.05,0,0.4>}
  DisplayCase_Undef()
  DisplayCase_MarbleMaterial("Green")
  object {DisplayCase("","BarrierPost") translate < 0.1 ,0,1.2>}
  DisplayCase_Undef()
  DisplayCase_MarbleMaterial("Red")
  object {DisplayCase("","BarrierPost") translate < 0.4 ,0,0.3>}
  DisplayCase_Undef()
  DisplayCase_WoodMaterial()
  object {DisplayCase("","BarrierPost") translate < 0.2 ,0,0.8>}
#end


// Examples 10 to 13 - Illustrate the standard display case types.
#if (Example>=10 & Example<14)
  global_settings {max_trace_level 12}
  camera {location <1.4,1.75,0.2> look_at <0,2.25,1.8>}
  light_source { <-15,7.5,-15>, rgb 1}
  #local Type = array[4] {"Spherical","Oblong","Cylindrical","Box"};
  #local ThisType=Example-10;
  #local MarbleColors = array[4] {"Red","Green","Blue","Yellow"};
  // The left-most display case.
  DisplayCase_WoodMaterial()
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Red")
  object {DisplayCase(Type[ThisType],"WallMount") translate <-0.7,1.5,1.8>} 
  // The central display case.
  DisplayCase_Undef()
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Green")
  object {DisplayCase(Type[ThisType],"WallMount") translate < 0  ,1.5,1.8>} 
  // The right-most display case.
  DisplayCase_Undef()
  DisplayCase_MarbleMaterial(MarbleColors[ThisType])
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Blue")
  object {DisplayCase(Type[ThisType],"WallMount") translate < 0.7,1.5,1.8>} 
#end


// Examples 20 to 22 - Illustrate the "Pedestal", "RoundPillar" and "RectangularPillar" mounts.
#if (Example>=20 & Example<=22)
  global_settings {max_trace_level 12}
  camera {location <1.4,1.75,-1.2> look_at <0,1,0>}
  light_source { <-15,7.5,-15>, rgb 1}
  #local Mounts = array[3] {"Pedestal","RoundPillar","RectangularPillar"};
  #local ThisMount=Example-20;
  #local MarbleColors = array[3] {"Red","Green","Blue"};
  // The left-most display case.
  DisplayCase_WoodMaterial()
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Red")
  object {DisplayCase("",Mounts[ThisMount])} 
  // The central display case.
  DisplayCase_Undef()
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Green")
  object {DisplayCase("",Mounts[ThisMount]) translate < 0.5,0,0.5>} 
  // The right-most display case.
  DisplayCase_Undef()
  DisplayCase_MarbleMaterial(MarbleColors[ThisMount])
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Blue")
  object {DisplayCase("",Mounts[ThisMount]) translate <-0.5,0,-0.1>} 
#end


// Example 23 - Illustrates the "WallMount".
#if (Example=23)
  global_settings {max_trace_level 12}
  camera {location <1.5,1.7,0.2> look_at <0,1.9,1.8>}
  light_source { <-15,7.5,-15>, rgb 1}
  // The left-most display case.
  DisplayCase_WoodMaterial()
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Red")
  object {DisplayCase("Spherical","WallMount") translate <-0.7,1.5,1.8>} 
  // The central display case.
  DisplayCase_Undef()
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Green")
  object {DisplayCase("Oblong","WallMount") translate < 0  ,1.4,1.8>} 
  // The right-most display case.
  DisplayCase_Undef()
  DisplayCase_WoodMaterial()
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Blue")
  object {DisplayCase("Spherical","WallMount") translate < 0.7,1.5,1.8>} 
#end


// Example 24 - Illustrates the "Tree" mount type.
#if (Example=24)
  global_settings {max_trace_level 12}
  camera {location <1.4,1.75,-2.5> look_at <0,1.25,0>}
  light_source { <-15,7.5,-15>, rgb 1}

  #declare DisplayCase_Exhibits = array [5];
  #declare DisplayCase_Exhibits[0] = object {DisplayCase_SampleExhibit("White") translate 0.1*y}
  #declare DisplayCase_Exhibits[1] = DisplayCase_SampleExhibit("Red")
  #declare DisplayCase_Exhibits[2] = DisplayCase_SampleExhibit("Blue")
  #declare DisplayCase_Exhibits[3] = DisplayCase_SampleExhibit("Green")
  #declare DisplayCase_Exhibits[4] = DisplayCase_SampleExhibit("Yellow")
  // The left-most tree.
  DisplayCase_MarbleMaterial("Black")
  object {DisplayCase("","Tree") rotate y*20 translate <-1.5,0,-0.1>} 
  // The central tree.
  DisplayCase_Undef()
  #declare DisplayCase_Exhibits = array [4];
  #declare DisplayCase_Exhibits[0] = object {DisplayCase_SampleExhibit("Flame") scale 1.6 translate 0.1*y}
  #declare DisplayCase_Exhibits[1] = DisplayCase_SampleExhibit("Red")
  #declare DisplayCase_Exhibits[2] = DisplayCase_SampleExhibit("Blue")
  #declare DisplayCase_Exhibits[3] = DisplayCase_SampleExhibit("Green")
  DisplayCase_WoodMaterial()  
  object {DisplayCase("","Tree")} 
  // The right-most tree.
  DisplayCase_Undef()
  #declare DisplayCase_Exhibits = array [3];
  #declare DisplayCase_Exhibits[0] = object {DisplayCase_SampleExhibit("White") translate 0.1*y}
  #declare DisplayCase_Exhibits[1] = DisplayCase_SampleExhibit("Red")
  #declare DisplayCase_Exhibits[2] = DisplayCase_SampleExhibit("Blue")
  object {DisplayCase("","Tree") rotate 90*y translate < 1,0,1>} 
#end


// Example 40 - Is used to generate the main image used on the web site and at the top of the documentation.
#if (Example=40)

  camera {location <1,1.8,-2.5> look_at <0,1.28,0>}  
  global_settings {max_trace_level 16}              
  
  light_source { < 2,3.4,-1  > color rgb 1 spotlight radius  5 falloff 25 tightness 0 point_at <0,1,0>}
  light_source { <-2,3.6,-1.2> color rgb 1 spotlight radius 10 falloff 35 tightness 0 point_at <0,1.5,0>}
  light_source { <-2.5,3.6,-1.2> color rgb 1 spotlight radius 10 falloff 35 tightness 0 point_at <-2.5,1.5,1.5>}
  
  #declare MyExhibit = DisplayCase_SampleExhibit("Flame")
  
  #declare DisplayCase_Exhibits = array [5];
  #declare DisplayCase_Exhibits[0] = object {DisplayCase_SampleExhibit("White") translate 0.1*y}
  #declare DisplayCase_Exhibits[1] = DisplayCase_SampleExhibit("Red")
  #declare DisplayCase_Exhibits[2] = DisplayCase_SampleExhibit("Blue")
  #declare DisplayCase_Exhibits[3] = DisplayCase_SampleExhibit("Green")
  #declare DisplayCase_Exhibits[4] = DisplayCase_SampleExhibit("Yellow")
  
  // A tree shaped stand holding an array of display cases (3 spherical cases  
  // arranged around a central oblong case).                                  
  DisplayCase("","Tree") 
  
  
  // Three wall mounted display cases
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Spherical","WallMount") translate <-3.8,1.4,1.8>}
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Flame")
  object {DisplayCase("Oblong"   ,"WallMount") translate <-3  ,1.4,1.8>}
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Spherical","WallMount") translate <-2.2,1.4,1.8>}
  
  
  // A rope barrier 
  object {DisplayCase("","BarrierPost") translate <-2,0,1.5>}
  object {DisplayCase("","BarrierPost") translate <-2,0,0>}
  object {DisplayCase("","BarrierPost") translate <-4,0,1.5>}
  object {DisplayCase("","BarrierPost") translate <-4,0,0>}
  #if (file_exists("rope.inc")) 
    #local StartPoint = <0,0.867, 1.364>;
    #local EndPoint   = <0,0.867, 0.136>;
    #include "rope.inc"
    Rope_AddPoint     (StartPoint)
    #local Rope_Catenary_a = 0.95;
    Rope_Catenary(EndPoint)
    #declare Rope_Radius = 0.03;
    #declare Rope_OuterColor       = <0,0.30,0>;   
    #declare Rope_InnerColor       = Rope_OuterColor*0.25;
    #declare Rope_ShowFibres       = 0;
    #declare RopeObject = Rope_ArrayToRope("")
    object {RopeObject translate -2*x}
    object {RopeObject translate -4*x}
    #declare DisplayCase_CupRadius = 1.05*Rope_Radius;
    object {DisplayCase("","RopeHook") rotate  x*45 translate StartPoint-2*x}
    object {DisplayCase("","RopeHook") rotate -x*45 translate EndPoint-2*x}
    object {DisplayCase("","RopeHook") rotate  x*45 translate StartPoint-4*x}
    object {DisplayCase("","RopeHook") rotate -x*45 translate EndPoint-4*x}
  #end
  
  // A box display case with a base and kick plate that reach down to the floor 
  #declare DisplayCase_Height           = 1.5;                   
  #declare DisplayCase_Width            = 1.6;                 
  #declare DisplayCase_JointHeight      = 0.9;
  #declare DisplayCase_TopRimHeight     = 0.01;
  #declare DisplayCase_TopCapHeight     = 0.05;
  #declare DisplayCase_KickPlateHeight  = 0.12;
  #declare DisplayCase_CaseLights       = 2;
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Box","") translate <1.6,0,1.305>}
  
#end


// Example 41 - Is used to generate the main image used on the web site and at the top of the documentation.
#if (Example=41)

  camera {location <1,1.8,-2.5> look_at <0,1.28,0>}  
  //camera {location <0.2,1.4,-0.5> look_at <0,1.28,0>}  
  //camera {location <0.5,2,-1.8> look_at <0,1.65,0>}  
  //camera {location <0.1,1.1,-0.8> look_at <-0.7,1.1,0>}  
  //camera {location <-1.8,1.0,1.4> look_at <-2,0.875,1.5>}  
  global_settings {max_trace_level 16}              
  
  //light_source { < 2,3.4,-1> color rgb 1 }   
  //light_source { <-2,3.4,-1> color rgb 1 }   
  
  light_source { < 2,3.4,-1  > color rgb 1 spotlight radius  5 falloff 25 tightness 0 point_at <0,1,0>}
  light_source { <-2,3.6,-1.2> color rgb 1 spotlight radius 10 falloff 35 tightness 0 point_at <0,1.5,0>}
  
  light_source { <-2.5,3.6,-1.2> color rgb 1 spotlight radius 10 falloff 35 tightness 0 point_at <-2.5,1.5,1.5>}
  
  #declare MyExhibit = DisplayCase_SampleExhibit("Flame")
  
  
  //#declare DisplayCase_LabelPigments     = array [4];
  //#declare DisplayCase_YRotations        = array [4];
  //#declare DisplayCase_JointHeights       = array [4];
  //#declare DisplayCase_SupportRodHeights = array [4]; 
  
  //#declare DisplayCase_SupportArmReach               = 0.5 ;                      
  //#declare DisplayCase_SupportRadius                 = 0.25;
  //#declare DisplayCase_SupportArmRadius              = 0.02;
  //#declare DisplayCase_JointHeights[0]           = 1.2;
  //#declare DisplayCase_JointHeights[1]           = 0.5;
  //#declare DisplayCase_JointHeights[2]           = 0.6;
  //#declare DisplayCase_JointHeights[3]           = 0.7;
  //#declare DisplayCase_YRotations[0]                 = 200;
  //#declare DisplayCase_YRotations[1]                 = 0;
  //#declare DisplayCase_YRotations[2]                 = 100;
  //#declare DisplayCase_YRotations[3]                 = 200;
  //#declare DisplayCase_LabelPigments[1]              =   ;
  //#declare DisplayCase_LabelPigments[2]              =   ;
  //#declare DisplayCase_LabelPigments[3]              =   ;
  
  #declare DisplayCase_Exhibits = array [5];
  #declare DisplayCase_Exhibits[0] = object {DisplayCase_SampleExhibit("White") translate 0.1*y}
  #declare DisplayCase_Exhibits[1] = DisplayCase_SampleExhibit("Red")
  #declare DisplayCase_Exhibits[2] = DisplayCase_SampleExhibit("Blue")
  #declare DisplayCase_Exhibits[3] = DisplayCase_SampleExhibit("Green")
  #declare DisplayCase_Exhibits[4] = DisplayCase_SampleExhibit("Yellow")
  //#declare DisplayCase_Exhibits[4] = box {<-0.08,0,-0.08> <0.08,0.16,0.08> pigment {color <1,0,1>} finish {ambient 0.5}}
                                
  //DisplayCase_WoodMaterial()  
  //DisplayCase_MarbleMaterial("Black")
  
  // A tree shaped stand holding an array of display cases (3 spherical cases  
  // arranged around a central oblong case).                                  
  DisplayCase("","Tree") 
  
  
  // Three wall mounted display cases
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Spherical","WallMount") translate <-3.8,0,1.8>}
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Flame")
  object {DisplayCase("Oblong"   ,"WallMount") translate <-3  ,0,1.8>}
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Spherical","WallMount") translate <-2.2,0,1.8>}
  
  
  // A rope barrier 
  object {DisplayCase("","BarrierPost") translate <-2,0,1.5>}
  object {DisplayCase("","BarrierPost") translate <-2,0,0>}
  object {DisplayCase("","BarrierPost") translate <-4,0,1.5>}
  object {DisplayCase("","BarrierPost") translate <-4,0,0>}
  #if (file_exists("rope.inc")) 
    #local StartPoint = <0,0.867, 1.364>;
    #local EndPoint   = <0,0.867, 0.136>;
    
    #include "rope.inc"
    
    Rope_AddPoint     (StartPoint)
    #local Rope_Catenary_a         = 0.95;
    Rope_Catenary(EndPoint)
    #declare Rope_Radius           = 0.03;
    #declare Rope_OuterColor       = <0,0.30,0>;   
    #declare Rope_InnerColor       = Rope_OuterColor*0.25;
    #declare Rope_ShowFibres       = 0;
    #declare RopeObject = Rope_ArrayToRope("")
    object {RopeObject translate -2*x}
    object {RopeObject translate -4*x}
  
    #declare DisplayCase_CupRadius = 1.05*Rope_Radius;
    object {DisplayCase("","RopeHook") rotate  x*45 translate StartPoint-2*x}
    object {DisplayCase("","RopeHook") rotate -x*45 translate EndPoint-2*x}
    object {DisplayCase("","RopeHook") rotate  x*45 translate StartPoint-4*x}
    object {DisplayCase("","RopeHook") rotate -x*45 translate EndPoint-4*x}
  
  #end
  
  
  //// A cylindrical display case of reduced radius on a pedestal
  //#local DisplayCase_Radius           = 0.15;
  //object {DisplayCase("Cylindrical","Pedestal") translate <1.2,0,1.5>} 
  //
  //// An oblong display case of reduced radius  on a pedestal
  //object {DisplayCase("Oblong","Pedestal") translate <1.6,0,1.5>} 
  //
  //// A box display case containing an eliptical mat on a pedestal 
  //#local DisplayCase_FabricShape      = "Eliptical";
  //#declare DisplayCase_CaseLights       = 0.1;
  //object {DisplayCase("Box","Pedestal")translate  <-1.4,0,1.4>}
  
  // A box display case with a base and kick plate that reach down to the floor 
  #declare DisplayCase_Height           = 1.5;                   
  #declare DisplayCase_Width            = 1.6;                 
  #declare DisplayCase_JointHeight      = 0.9;
  #declare DisplayCase_TopRimHeight     = 0.01;
  #declare DisplayCase_TopCapHeight     = 0.05;
  #declare DisplayCase_KickPlateHeight  = 0.12;
  #declare DisplayCase_CaseLights       = 2;
  #declare DisplayCase_Exhibit = DisplayCase_SampleExhibit("Violet")
  object {DisplayCase("Box","") translate <1.6,0,1.305>}
  
  
  //#local DisplayCase_Height           = 2;
  //#local DisplayCase_JointHeight      = 0.8;
  //#local DisplayCase_KickPlateHeight  = 0.12;
  //#local DisplayCase_TopRimHeight     = 0.05;                   
  //#declare MyCase = object {DisplayCase("Spherical","") scale 0.5}
  #declare DisplayCase_Exhibit = MyExhibit 
  //object {DisplayCase("Box","RectangularPillar") } 
  
  
  
  
  // The floor
  plane { y, 0 DisplayCase_SampleFloorTexture() rotate y*90}
  
  // The wall
  plane {-z,-1.8 pigment {rgb <1,0.8,0.3>} finish {ambient 0.02}}   
  
  // Skirting Board
  union {  
    box {<-20,0,1.785><20,0.15,1.8>}
    cylinder {<-20,0.15,1.795><20,0.15,1.795>,0.01}
    pigment {rgb 1} 
    finish {ambient 0.02}
  }
  
  //// The cutout of a person
  //plane {-z,0
  //  pigment {image_map {gif "Clipboard01.gif" once transmit 0 1 interpolate 0} translate -x*0.5}
  //  finish {ambient 1.5 brilliance 0}
  //  scale 1.1*<0.5,2,1> 
  //  rotate -y*25 
  //  translate <-0.6,-0.03,0.5> //no_shadow
  //}   
#end