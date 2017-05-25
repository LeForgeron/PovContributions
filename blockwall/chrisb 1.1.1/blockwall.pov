// blockwall.pov
// ----------------

// This scene file illustrates the use of the macros in the blockwall.inc file
// which produce block walls in a variety of forms. The different macros allow
// you to specify the dimensions and location or path of a wall with whatever 
// information you have available. They then invoke a macro that defines a 
// randomised block pattern and a macro to create individual blocks to fit the
// pattern.   
// 
//
// This file is licensed under the terms of the CC-LGPL. 
// This license permits you to use, modify and redistribute the content.
// 
// Typical render time 10 seconds to 1 minute (at 640x480 AA 0.3) for 20 rows 
// of 20 blocks.
// The default settings produce a layer of paving stones about 1.4 POV-Ray 
// units wide laying on the XZ plane, centred on the Z axis and heading away
// from the origin in the +Z direction.  
//
// See blockwall.html for a full list of settings and illustrations of the examples.

// This file contains a series of separate examples, controlled using the 
// 'Example' variable:
//
//   Example = 0  The Blockwall macro used with the default settings, produces 
//                a 1 metre square panel with its bottom left corner at the origin.
//   Example = 1  Panels can be tiled, and the wrapping option helps conceal the 
//                joints. This example shows 3 identical panels used to create a 
//                simple wall.
//   Example = 2  The Blockwall_Fill macro allows you to define a box filled with 
//                blockwork.
//   Example = 3  The Blockwall_FollowSpline macro generates a wall that follows 
//                the spline called Blockwall_Spline. This example uses the default
//                setting for this spline which creates the wall for a hump-back 
//                bridge stretching out along the +Z axis.
//   Example = 4  The Blockwall_DropSplineToSurface macro drops the Blockwall_Spline
//                onto an arbitrary object (in this instance is defined as a torus).
//                The spline can then be used to draw a wall that sits on the object
//   Example = 5  The Blockwall_FollowArray macro draws a sequence of wall segments 
//                based upon corner points defined in the Blockwall_CornerArray array.
//                The default points define a 1 metre cube with its bottom left 
//                corner at the origin.
//   Example = 6  The Blockwall_Shell macro fills a box with a shell. This example 
//                uses CSG to poke door and window holes into that shell. 
//                Warning. Using CSG with a union of so many objects increases the 
//                render time considerably. This example takes several minutes to 
//                render (about 10 min at 640x480, AA 0.3).
//   Example = 7  A more complete scene showing a walkers refuge under construction
//                out in the countryside. It demonstrates a number of features, 
//                including the spline functions and CSG operations.
//   Example = 8  A sequence of walls demonstrating the Blockwall_FollowArray macro 
//                with a fairly arbitrary set of non-perpendicular corners.
//   Example = 9  A rough stone wall illustrating the matrix settings used to control 
//                the block distribution and relative size of blocks in the pattern.
//   Example = 10 This is really more of a testbed than an example. It can be used 
//                for developing new styles of block. It contains a couple of camera
//                settings and various optional boxes for aligning blocks.
//
//
//   The following examples just illustrate some of the alternative settings available.
// 
//   Example = 12 Three runs with different color settings
//   Example = 13 Three runs with different contrast settings
//   Example = 14 Three runs with different finish and normal settings
//   Example = 15 Three runs with different mortar gaps
//   Example = 16 Illustrations of the Blockwall_BlockThicknessDecrement variable
//   Example = 17 A set of strips illustrating the standard block color styles
//   Example = 18 A set of strips illustrating standard stone color styles
//   Example = 19 A set of strips illustrating other styles
//   Example = 20 An illustration of the use of brightness to adjust for higher or 
//                lower lighting levels
//
//   Examples illustrating new V1.1 features:
// 
//   Example = 21 A circular stone stairwell forming a corner tower for a bit of castle.
//   Example = 22 A stone well topped by winding gear. 
//   Example = 23 A stone fireplace. 
//   Example = 24 A proper bridge shape. 
//
// You can generate a sequence of these examples using animation options 
// (e.g. +kfi0 +kff24) and the frame_number read-only identifier.
// 
 #declare Example = frame_number;
//#declare Example = 0;

#include "blockwall.inc"    


// First set up a couple of pigments textures used for the backgrounds in several 
// different examples.
#declare GrassTexture = texture {
  pigment { granite turbulence 0.5 lambda 2 omega 1.8
    color_map {
      [0   color rgb <1,0.6,0.4>]
      [0.3 color rgb <0,0.2,0>]
      [0.7 color rgb <0,0.2,0>]
      [0.9 color rgb <1,0.6,0.4>*0.4]
    }
  }
  normal {
    average
    normal_map {
      [0.5  granite scale 0.1]
      [1.0  agate scale <0.01,0.05,0.01>]
      [2.0  bumps ]
      [1.0  bumps scale 0.2]
    }
  }
  finish {ambient 0}
}

#declare SkyPigment = pigment {
  gradient y
  color_map {
    [ 0.5  color rgb <0.3,0.3,0.6>]
    [ 1.0  color rgb 1 ]
  }
  scale 2
  translate -1
}

// Example 0: The default run of stone walling
#if (Example=0)
  camera {orthographic location 0.5-1.2*z look_at 0.5 }
  light_source {<-10,20,-50>, rgb 1}  
  // Call the macro to generate the default slab of blocks
  object {Blockwall("")}  
#end  

// Example 1: Three copies with wrapping to interleave the ends.
#if (Example=1)
  camera {location <-1.4,1.15,-1> look_at <-0.2,0.44,0> }
//  camera {location <0,0.5,-2> look_at <0,0.5,-0.2> }
  light_source {<-10,20,-5>, rgb 1}  
  light_source {<-100,20,5>, rgb 1}  
  
  #declare Blockwall_Wrap       = 1; 
  // Call the macro to generate the default slab of blocks
  #declare Section = Blockwall("BuffBrick")
  // Show 3 copies of the same section side by side
  object {Section translate  -Blockwall_CentreToCentre*x}
  object {Section}
  object {Section translate   Blockwall_CentreToCentre*x}
  object {Section translate 2*Blockwall_CentreToCentre*x}
  // Add some mortar
  box {
    <-0.994,0,0.006><3,0.994,0.074> 
    texture {
      pigment {rgb <1,0.6,0.4>*0.6}
      normal {Blockwall_Normal scale 0.3}
      finish {Blockwall_Finish}
    }
  }
 // Add some grass
  plane {y,0 texture {GrassTexture}}
#end 


// Example 2: Using Blockwall_Fill to create a wall.
#if (Example=2)
  camera {location <2,1.7,-1> look_at <0,0.4,1.75> }
  light_source {<10,20,-50>, rgb 1}  
  // Call the macro to fill a box with a stone wall
  object {Blockwall_Fill(<0,0,0>,<0.3,1,10>,"GreyBrick")}  
  // Add some mortar
  superellipsoid {
    <0.1,0.05>
    rotate x*90
    scale 0.5
    translate 0.5
    scale <0.3,1,10>-0.0160
    translate 0.008
    texture {
      pigment {rgb 0.68}
      normal {Blockwall_Normal scale 0.3}
      finish {Blockwall_Finish}
    }
  }
 // Add some grass
  plane {y,0 texture {GrassTexture}}
#end  


// Example 3: Following a spline (a hump-back bridge).
#if (Example=3)
  camera {location <2.2,1.7,-1.7> look_at <0.9,0.4,1> }
  light_source {<10,20,-50>, rgb 0.4}  
  light_source {<-10,20,-10>, rgb 0.5}
    
  // Call the macro to generate a wall from a spline.
  // The default spline will produce a straight wall with a hump.
  object {Blockwall_FollowSpline("")}
  // Add a second wall following the same spline and translate it to the left.  
  object {Blockwall_FollowSpline("") translate x*1.8} 
 // Add some grass
  plane {y,0 texture {GrassTexture}}
#end  

// Example 4: Dropping a spline onto a torus
#if (Example=4)
  camera {location <5,3,0> look_at <0.2,0.4,6> }
  light_source {<10,22,-60>, rgb 1}  
  sky_sphere { pigment {SkyPigment}}

  #declare Blockwall_Brightness = 0.6; 
  #declare Blockwall_ClipBlock  = 1;  

  // Define a surface to drop a spline onto.
  #declare Blockwall_Target = torus {8,12 
    translate -y*12 
    scale <1,0.4,1>
    translate <3,0,6>
  }  
  // Create a spline above the target surface.
  #declare Blockwall_Spline = spline {
    cubic_spline
    -.25, < 0  ,1,-1>
    0.00, < 0  ,1, 0>
    0.20, < 1  ,1, 5>
    0.40, < 2  ,1,10>
    0.60, < 1  ,1,15>
    0.80, < 0  ,1,20>
    1.00, < 1  ,1,25>
    1.25, < 2  ,1,30>
  } 
  // Drop the spline onto the surface
  Blockwall_DropSplineToSurface()  

  // Call the macro to generate a wall that follows the new spline
  object {Blockwall_FollowSpline("RoughStone")}             
  
  // Add a grassy surface using a textured copy of the target object
  object {Blockwall_Target texture {GrassTexture}}
#end  


// Example 5: Following an array of corner points.
#if (Example=5)
//  camera {location <8,1.7,-3> look_at <0,0.4,4.5> }
  camera {location <-0.6,1.25,-0.6> look_at 0.75*y }
  light_source {<-10,200,50>, rgb 1}  
  light_source {<100,20,-50>, rgb 1}  
  // Call the macro to fill a box with a stone wall
  object {Blockwall_FollowArray("GreenBrick")}  
#end  


// Example 6: Creating a shell with holes in it.
// warning. This takes several minutes to render (10 min at 640x480, AA 0.3).
#if (Example=6)
//  camera {location <8,1.7,-3> look_at <0,0.4,4.5> }
  camera {location <-6,3,-3> look_at <0,0.5,4> }
  light_source {<-10,200,50>, rgb 1}  
  light_source {<100,20,-50>, rgb 1}  

  // Create a CSG object that defines where the holes in the wall go
  #declare Blockwall_Holes = union {
    box {<0,0.1,-0.01><1,1.9,0.11>}     // Front Door
    box {<1.2,1.2,-0.01><1.6,1.9,0.11>} // Side Window
    box {<-3.5,1,-0.01><-1.5,1.9,0.11>} // Front Window
    box {<0,0.1,9.8><1,1.9,10.01>}      // Back Door
    box {<-4.01,1,1><-3.9,1.9,3>}       // Window 1 in Left Side Wall
    box {<-4.01,1,6><-3.9,1.9,8>}       // Window 2 in Left Side Wall
    box {< 4.01,1,1>< 3.9,1.9,3>}       // Window 1 in Right Side Wall
    box {< 4.01,1,6>< 3.9,1.9,8>}       // Window 2 in Right Side Wall
  }

  // Call the macro to fill a box with the outline of a stone wall
  #declare OuterShell = object {Blockwall_Shell(<-4,0,0>,<4,2.4,10>,"ColorBrick")}  
  #declare Mortar = difference {
    box {<-3.994,0.001,0.006>,<3.994,2.394,9.994>}
    box {<-3.924,0,0.076>,<3.924,2.4,9.924>}
  }

  // Draw the Block Wall 
  object {OuterShell}

  // Add Mortar
  difference {
    object {Mortar}
    object {Blockwall_Holes}
    texture {
      pigment {rgb 0.68}
      normal {Blockwall_Normal scale 0.3}
      finish {Blockwall_Finish}
    }
  }
#end  


// Example 7: A more complete scene (a walkers refuge under construction)
#if (Example=7)
//  camera {location <2.5,3,-2.5> look_at <0,0.4,2> }
  camera {location <2.5,1.7,-2.5> look_at <0,1.6,1.4> }
  light_source {<10,22,-60>, rgb 1}  
  sky_sphere { pigment {SkyPigment}}

  // Define a surface to drop a spline onto.
  #declare Blockwall_Target = torus {8,12 
    translate -y*12 
    scale <1,0.4,1>
    translate <3,0,6>
  }
    
  // Add a grassy surface using a textured copy of the target object
  object {Blockwall_Target texture {GrassTexture}}

  // Create a spline some distance above the target surface.
  #declare Blockwall_Spline = spline {
    cubic_spline
    -.25, <0, 1, -1>
    0.00, <0, 1,  0>
    0.20, <1, 1,  5>
    0.40, <2, 1, 10>
    0.60, <1, 1, 15>
    0.80, <0, 1, 20>
    1.00, <1, 1, 25>
    1.25, <2, 1, 30>
  }
   
  // Drop the spline onto the surface
  Blockwall_DropSplineToSurface()  

  // Call the macro to generate a wall that follows the new spline
  #declare Blockwall_ClipBlock       = 1;
  #declare Blockwall_MatrixSpacing   = 0.03;
  #declare Blockwall_BlockThickness  = 0.35;
  #declare Blockwall_HBias           = 1;
  #declare Blockwall_VBias           = 3;  
  #declare Blockwall_MaxHU           = 10;  
  #declare Blockwall_MaxVU           = 5;  
  object {Blockwall_FollowSpline("BuffStone")}  
  
  // Now for the refuge itself
  #declare Blockwall_MatrixSpacing   = 0.1;
  #declare Blockwall_HBias           = 2.5;
  #declare Blockwall_VBias           = 3;  
  #declare Blockwall_MaxHU           = 5;  
  #declare Blockwall_MaxVU           = 3;  
  #declare Blockwall_BlockThickness  = 0.15;
  // Create a CSG object that defines where the holes in the wall go
  #declare Blockwall_Holes = union {
    // Roofline
    box {0,<3,2,4.2> rotate z*35 translate <-4+Blockwall_BlockThickness,1.78,0.9>}
    box {0,<3,2,4.2> rotate z*35 scale <-1,1,1> translate <-1-Blockwall_BlockThickness,1.78,0.9>}
    // Level off tops of walls
    box {0,<Blockwall_BlockThickness+0.01,1,4.2> translate <-1-Blockwall_BlockThickness,1.78,0.9>}
    box {0,<Blockwall_BlockThickness+0.01,1,4.2> scale <-1,1,1>  translate <-4+Blockwall_BlockThickness,1.78,0.9>}
    // Doorway
    box {0,<0.9,1.8,Blockwall_BlockThickness+0.1> translate <-3,0  ,0.95>}
    // Lintel
    box {0,<1.2,0.2,Blockwall_BlockThickness+0.1> translate <-3.1 ,1.8,0.95> }
  }
  // Call a macro to fill a box with the outline of a building then use CSG to cut away the bits we don't want.
  object {Blockwall_Shell(<-4,0,1><-1,3,5>,"ColorBrick")}
  // Add a chimney.
  // We need to #undef the Blockwall_Holes object first or we'll slice bits off the chimney at the roofline.
  #undef Blockwall_Holes
  Blockwall_Shell(<-4,0,4.5><-3,2.8,5.1>,"ColorBrick")
  
  // Add Mortar
  difference {
    box {<-3.994,0,1.006>,<-1.006,3,4.994>}
    box {<-3.926,-0.01,1.074>,<-1.074,3.01,4.926>}
    // Roofline
    box {0,<3,2,4.2> rotate z*35 translate <-4+Blockwall_BlockThickness,1.75,0.9> }
    box {0,<3,2,4.2> rotate z*35 scale <-1,1,1> translate <-1-Blockwall_BlockThickness,1.75,0.9>}
    // Level off tops of walls
    box {0,<Blockwall_BlockThickness+0.01,1,4.2> translate <-1-Blockwall_BlockThickness,1.8,0.9> texture {Blockwall_ThisBlockTexture}}
    box {0,<Blockwall_BlockThickness+0.01,1,4.2> scale <-1,1,1>  translate <-4+Blockwall_BlockThickness,1.8,0.9> texture {Blockwall_ThisBlockTexture}}
    // Doorway
    box {0,<0.9,1.8,Blockwall_BlockThickness+0.1> translate <-3,0,0.95>}
    texture {
      pigment {rgb 0.68}
      normal {Blockwall_Normal scale 0.3}
      finish {Blockwall_Finish}
    }
  }

  // Foundations
  box {<-4.1,-0.5,0.9><-0.9,0,5.1> 
    texture {
      pigment {rgb 0.68}
      normal {Blockwall_Normal scale 0.3}
      finish {Blockwall_Finish}
    }
  }
             
  // Pond
  box {<0,-1,2><5,-0.6,8> 
    texture {
      pigment {rgbt <0.05,0.05,0.4,0.32>}
      normal {bumps 0.3 scale 0.06}
      finish {reflection 0.3}
    }
  }
  
  // Cement Mixer
  intersection {
    box {-0.375,0.375}
    sphere {0,0.5 scale <1,0.75,0.75>}
    scale <0.86,1,1>
    translate <-1.2,0.15,6>
    pigment {rgb <0.7,0.7,0>}
  }
#end  


// Example 8: A sequence of walls demonstrating the Blockwall_FollowArray macro with non-perpendicular corners
#if (Example=8)
#local Pos = vrotate(x,y*clock*180);
  camera {location <-1,1.6,-4> look_at <0,0,-0.3> }
  light_source {<-20,22,-6>, rgb 0.6}  
  light_source {<-50,20,20>, rgb 0.6}  
  sky_sphere { pigment {SkyPigment}}
  
  // Create some fairly randomly shaped planters.
  #declare Blockwall_WallHeight = 0.5;
  #declare Blockwall_MatrixSpacing   = 0.04;
  #declare Blockwall_HBias           = 0.5;
  #declare Blockwall_VBias           = 3;  
  #declare Blockwall_MaxHU           = 5;  
  #declare Blockwall_MaxVU           = 3;  
  #declare Blockwall_BlockThickness  = 0.30;
  #declare Blockwall_Finish = finish {ambient 0.01};
  #declare Blockwall_CornerArray = array [10] {
    <0.5  ,1.2>,
    <0.8  ,1.5>,
    <1.28 ,1.28>,  
    <1.5  ,0.8>,
    <1.2  ,0.5>,
    <2.2  ,0.5>,
    <2.2  ,1.5>,
    <1.5  ,2.2>,
    <0.5  ,2.2>,  
    <0.5  ,1.2>  
  } 
  #declare Blockwall_BlockThickness = 0.1;
  object {Blockwall_FollowArray("GreenBrick")}
  object {Blockwall_FollowArray("GreenBrick") rotate y*90}
  object {Blockwall_FollowArray("GreenBrick") rotate y*180}
  object {Blockwall_FollowArray("GreenBrick") rotate y*270}  
  
  // Add the central feature (maybe a little tower or something).
  #declare Blockwall_WallHeight = 1.4;
  #declare Blockwall_CornerArray = array[9];
  #local I = 0;
  #while (I<8)
    #declare Blockwall_CornerArray[I]=<vrotate(0.6*x,y*I*360/8).x,vrotate(0.6*x,y*I*360/8).z>; 
    #local I = I + 1;
  #end
  #declare Blockwall_CornerArray[8]=Blockwall_CornerArray[0];
  #declare Blockwall_ClipBlock = 1;
  Blockwall_FollowArray("PinkBrick")
  
  // Paving. To use as paving, we can use a matching horizontal and 
  // vertical bias for the pattern and rotate the 'wall' to be horizontal. 
  Blockwall_Undef()
  #declare Blockwall_WallLength = 4.5;
  #declare Blockwall_WallHeight = Blockwall_WallLength;
  #declare Blockwall_MatrixSpacing   = 0.05;
  #declare Blockwall_HBias           = 2;
  #declare Blockwall_VBias           = 2;  
  #declare Blockwall_MaxHU           = 5;  
  #declare Blockwall_MaxVU           = 5;  
  #declare Blockwall_Finish = finish {ambient 0.01};
  object {Blockwall("") rotate x*90 translate <-Blockwall_WallLength/2,0,-Blockwall_WallHeight/2>}
  
  // Add some grass
  plane {y,-0.01 texture {GrassTexture}}
#end


// Example 9: A rough stone wall.
#if (Example=9)
  camera {location <1.2,1.2,-0.2> look_at <0,0.5,0.8> }
  light_source {<40,20,-20>, rgb 0.3}  
  light_source {<-10,20,-10>, rgb 1}
    
  #declare Blockwall_MinColor        = <0.98,0.65,0.25>;   
  #declare Blockwall_MaxColor        = <1.0 ,0.7 ,0.3>;
  #declare Blockwall_Contrast        = 0.6;             
  #declare Blockwall_ClipBlock       = 1;
  #declare Blockwall_MatrixSpacing   = 0.02;
  #declare Blockwall_BlockThickness  = 0.35;
  #declare Blockwall_HBias           = 0.3;
  #declare Blockwall_VBias           = 3;  
  #declare Blockwall_MaxHU           = 10;  
  #declare Blockwall_MaxVU           = 5;  
  #declare Blockwall_Finish = finish {phong 0 ambient 0}
  #declare Blockwall_Normal = normal {
    average
    normal_map {
      [0.5  granite 1 scale 0.25]
      [0.5  agate   1 scale 0.05]
      [1.0  marble  1 rotate z*90 turbulence 0.5 scale <0.3,0.1,0.5>]
    
    }
  }
  
  // Call the macro to generate a wall from a spline.
  // The default spline will produce a straight wall with a hump.
  object {Blockwall_FollowSpline("BuffStone")}
 // Add some grass
  plane {y,0 texture {GrassTexture}}
#end  


// Example 10: A rough stone run of stone walling
#if (Example=10)
  camera {orthographic location 0.5-1.2*z look_at 0.5 }
//  camera {location <-0.8,1.1,-0.8> look_at <0.5,0.5,0> }
  light_source {<-10,20,-50>, rgb 1}  
  // Call the macro to generate a block wall using the rough stone shape
  #declare Blockwall_BlockThickness = 0.3;
  #declare Blockwall_SizeSeed = seed(1);

  #declare Blockwall_HBias           = 1;
  #declare Blockwall_VBias           = 1; 
  #declare Blockwall_MaxHU           = 4; 
  #declare Blockwall_MaxVU           = 4; 

  difference {
    object {Blockwall("RoughStone")}
//    box {<-0.1,0.8,-0.2><0.5,1.5,0.5>}
  } 
  box {0,<1,1,Blockwall_BlockThickness>pigment {rgbt <1,1,0,0.5>}} 
#end  


// Example 12: Three runs with different color settings
#if (Example=12)
  camera {orthographic location <0.5,0.5,-2.5> look_at 0.5 }
  light_source {<-10,20,-5>, rgb 1}

  #declare Blockwall_Contrast = 0;
  #declare Blockwall_Radius     = 0.5;   

  // The central block shows the full color range
  #declare Blockwall_MinColor = <0,0,0>;
  #declare Blockwall_MaxColor = <1,1,1>;
  object {Blockwall("")}
  // The block on the left shows a reduced colour range
  #declare Blockwall_MinColor = <0.4,0.4,0.4>;
  #declare Blockwall_MaxColor = <0.8,0.8,0.8>;
  object {Blockwall("") translate -Blockwall_CentreToCentre*x}
  // The block on the right adds a buff (yellow/red) biase
  #declare Blockwall_MinColor = <1.0,0.7,0.6>;
  #declare Blockwall_MaxColor = <1.0,0.9,0.7>;
  object {Blockwall("") translate  Blockwall_CentreToCentre*x}
#end  


// Example 13: Three runs with different contrast settings
#if (Example=13)
  camera {orthographic location <0.5,0.5,-2.5> look_at 0.5 }
  light_source {<-10,20,-5>, rgb 1}

  // The central block shows the full default colors without contrast
  #declare Blockwall_Radius     = 0.5;   
  #declare Blockwall_Contrast = 0;
  object {Blockwall("")}
  // The block on the left shows the default setting
  #declare Blockwall_Contrast = 1;
  object {Blockwall("") translate -Blockwall_CentreToCentre*x}
  // The block on the right adds full contrast
  #declare Blockwall_Contrast = 0.5;
  object {Blockwall("") translate  Blockwall_CentreToCentre*x}
#end  


// Example 14: Three runs with different finish and normal settings
#if (Example=14)
  camera {orthographic location <0.5,0.5,-2.5> look_at 0.5 }
  light_source {<-10,20,-5>, rgb 1}

  // The central block shows the full default finish and normals
  #declare Blockwall_Radius     = 0.5;   
  object {Blockwall("")}
  // The block on the left uses a different normal
  #declare Blockwall_Normal = normal {agate scale <0.001,0.01,0.001>}
  object {Blockwall("") translate -Blockwall_CentreToCentre*x}
  // The block on the right uses a different finish
  #declare Blockwall_Normal = normal {granite scale 0.1}
  #declare Blockwall_Finish = finish {phong 1}
  object {Blockwall("") translate  Blockwall_CentreToCentre*x}
#end  


// Example 15: Three sections with different mortar gap
#if (Example=15)
  camera {orthographic location <0.5,0.5,-2.5> look_at 0.5 }
  light_source {<-10,20,-5>, rgb 1}

  // The central section shows the default mortar gap
  object {Blockwall("")}
  // The section on the left shows slightly increased mortar gap
  #declare Blockwall_MortarGap = 0.02;
  object {Blockwall("") translate -Blockwall_CentreToCentre*x}
  // The section on the right shows a more pronounced mortar gap
  #declare Blockwall_MortarGap = 0.04;
  object {Blockwall("") translate  Blockwall_CentreToCentre*x}
#end  


// Example 16: A demonstration of the Blockwall_BlockThicknessDecrement variable.
#if (Example=16)
  camera {location <0.8,1.25,-2.2> look_at 0.5*y }
  light_source {<0,20,-10>, rgb 1}

  #declare Blockwall_BlockThickness = 0.5;
  object {Blockwall("GreenBrick") rotate -y*90 translate -0.8*x}
  object {Blockwall_FollowSpline("GreenBrick") translate -0.1*x}

  #declare Blockwall_BlockThicknessDecrement = 0.035;
  object {Blockwall_FollowSpline("GreenBrick") translate 0.6*x}
  object {Blockwall("GreenBrick") rotate -y*90 translate 1.3*x}

#end 


// Example 17: A set of strips illustrating the standard color settings
#if (Example=17)
  camera {orthographic location <0.5,1,-2.5> look_at <0.5,1,0> }
  light_source {<-10,20,-5>, rgb 1}

  #declare Blockwall_Rows       = 10;
  #declare Blockwall_Radius     = 0.8;   
  object {Blockwall("RedBrick"  ) translate  <-Blockwall_CentreToCentre,1,0>} // Top Left
  object {Blockwall("BlueBrick" ) translate  <0,1,0>}                         // Top Centre
  object {Blockwall("GreenBrick") translate  < Blockwall_CentreToCentre,1,0>} // Top Right
  object {Blockwall("PinkBrick" ) translate -x*Blockwall_CentreToCentre}      // Bottom Left
  object {Blockwall("BuffBrick" ) }                                           // Bottom Centre
  object {Blockwall("GreyBrick" ) translate  x*Blockwall_CentreToCentre}      // Bottom Right
#end  

// Example 18: A set of strips illustrating more standard color settings
#if (Example=18)
  camera {orthographic location <0.5,1,-2.5> look_at <0.5,1,0> }
  light_source {<-10,20,-5>, rgb 1}

  #declare Blockwall_Rows       = 10;
  #declare Blockwall_Radius     = 0.8;   
  object {Blockwall("RedStone"  ) translate  <-Blockwall_CentreToCentre,1,0>} // Top Left
  object {Blockwall("BlueStone" ) translate  <0,1,0>}                         // Top Centre
  object {Blockwall("GreenStone") translate  < Blockwall_CentreToCentre,1,0>} // Top Right
  object {Blockwall("PinkStone" ) translate -x*Blockwall_CentreToCentre}      // Bottom Left
  object {Blockwall("BuffStone" ) }                                           // Bottom Centre
  object {Blockwall("GreyStone" ) translate  x*Blockwall_CentreToCentre}      // Bottom Right
#end  

// Example 19: A set of strips illustrating more standard color settings
#if (Example=19)
  camera {orthographic location <0.5,1,-2.5> look_at <0.5,1,0> }
  light_source {<-10,20,-5>, rgb 1}

  #declare Blockwall_Rows       = 10;
  #declare Blockwall_Radius     = 0.8;   
  #declare Blockwall_ColorSeed  = seed(1);
  #declare Blockwall_SizeSeed   = seed(1);
  object {Blockwall("Pebbles"      ) translate  <-Blockwall_CentreToCentre/2,1,0>} // Top Left
  #declare Blockwall_ColorSeed  = seed(1);
  #declare Blockwall_SizeSeed   = seed(1);
  object {Blockwall("RoughStone"   ) translate  <Blockwall_CentreToCentre/2,1,0>}  // Top Right
  #declare Blockwall_MortarGap  = 0.015;   
  #declare Blockwall_ColorSeed  = seed(1);
  #declare Blockwall_SizeSeed   = seed(1);
  object {Blockwall("Box"          ) translate -x*Blockwall_CentreToCentre/2}      // Bottom Left
  #declare Blockwall_ColorSeed  = seed(1);
  #declare Blockwall_SizeSeed   = seed(1);
  object {Blockwall("Polygon"      ) translate  x*Blockwall_CentreToCentre/2}      // Bottom Right
#end  

// Example 20: An illustration of the use of brightness to adjust for higher or lower lighting levels
#if (Example=20)
  camera {orthographic location <0.5,1,-2.5> look_at <0.5,1,0> }
  light_source {<-10,20,-50>, rgb 10}

  #declare Blockwall_Brightness = 1;
  object {Blockwall("")}
#end 


// Example 21: A circular stone stairwell
#if (Example=21)
//  camera {location <0,1.8,-5> look_at 1.2*y } 
  camera {location <0,1.8,-4> look_at 0.5*y }
  light_source {<-1.05, 1  ,0>, rgb <1,0.7,0.4>}
  light_source {<-1.05,-1.2,0>, rgb <1,0.6,0.4>}
  light_source {<5000,200,5000>, rgb 0.5}
  
  // Add a night sky
  sky_sphere { 
    pigment {
      gradient y
      color_map {
        [ 0.5  color rgb <0.3,0.3,0.6>*0.02]
        [ 1.0  color rgb 0 ]
      }
      scale 2
      translate -1
    }
  }    

  // Add a bit of water
  plane {y,-10 
    texture {
      pigment {rgb 0} 
      normal {bozo scale <0.5,1,0.5>}
      finish {phong 1}
    }
  }
  
  // Declare a circular spline
  #declare Blockwall_Spline = spline {
    cubic_spline
    #local I = -0.25;
    #while (I<=1.25)  
      I, vrotate(1.4*z,-y*I*360)
      #local I = I + 0.01;
    #end
  }
  
  // Set up a very rough stone 
  #declare Blockwall_MinColor        = <0.98,0.65,0.25>;   
  #declare Blockwall_MaxColor        = <1.0 ,0.7 ,0.3>;
  #declare Blockwall_Contrast        = 0.6;             
  #declare Blockwall_ClipBlock       = 1;
  #declare Blockwall_MatrixSpacing   = 0.02;
  #declare Blockwall_HBias           = 0.3;
  #declare Blockwall_VBias           = 3;  
  #declare Blockwall_MaxHU           = 10;  
  #declare Blockwall_MaxVU           = 5;  
  #declare Blockwall_Finish = finish {phong 0 ambient 0}
  #declare Blockwall_Normal = normal {
    average
    normal_map {
      [0.5  granite 1 scale 0.25]
      [0.5  agate   1 scale 0.05]
      [1.0  marble  1 rotate z*90 turbulence 0.5 scale <0.3,0.1,0.5>]
    
    }
  }

  // Create a circular wall
  #declare Blockwall_Wrap = 1;  
  #declare Blockwall_WallHeight = 5;
  #declare Blockwall_Holes = union {
    box {<-0.401,0.099,-1.41><0.401,1.4,-1>}
    cylinder {<0,1.4,-1.41><0,1.4,-1>,0.4}
    translate 2*y
  }
   
  object {Blockwall_FollowSpline("GreyStone") translate -2*y} 
  
  // Add a little bridge
  object {Blockwall_Fill(< 0.55,0,-4>,< 0.8,1,-1.3>,"GreyStone")}
  object {Blockwall_Fill(<-0.6,0,-4>,<-0.9,0.6,-1.3>,"GreyStone")}

  // Paving. To use as paving, we can use a matching horizontal and 
  // vertical bias for the pattern and rotate the 'wall' to be horizontal. 
  Blockwall_Undef()
  #declare Blockwall_WallLength = 1.2;
  #declare Blockwall_WallHeight = 3;
  #declare Blockwall_MatrixSpacing   = 0.1;
  #declare Blockwall_HBias           = 2;
  #declare Blockwall_VBias           = 2;  
  #declare Blockwall_MaxHU           = 5;  
  #declare Blockwall_MaxVU           = 5;  
  #declare Blockwall_Finish = finish {ambient 0.001};
  difference {
    object {Blockwall("GreyBrick") rotate x*90 translate <-0.6,0,-4>}
    cylinder {-0.5*y,0.1*y,1.4}
  }

  // Declare a single stone step
  #declare Step = union {
    cylinder {0,y*0.197,0.25}
    difference {
      cylinder {0,y*0.197,1.35}
      plane { x,-0.05 rotate  y*25}
      plane {-x,-0.05 rotate -y*25}
      plane {-z,0}
    }
  }  
  
  // Declare a flight of 11 steps
  #declare FlightOfSteps = union {
    #local I = 0;
    #while (I<=10)  
      object {Step rotate y*I*31.5 translate y*I*0.2}
      #local I = I + 1;
    #end
  }
   
  #declare StepTexture = texture {
    pigment {rgb <1,0.9,0.8>*0.6}
    normal {granite 0.2 scale 0.08}
    finish {Blockwall_Finish}
  }
  object {FlightOfSteps translate -0.2*y rotate y*50 texture {StepTexture}}
  object {FlightOfSteps translate -2.4*y rotate y*50 texture {StepTexture}}
#end 


// Example 22: A well
#if (Example=22)
  camera {location <-1.0,1.2,-1.4> look_at 0.5*y }
  light_source {<20,20,-50>, rgb 1}
  
  // Add a sky and some grass
  sky_sphere {pigment {SkyPigment}}    
  plane {y,0 texture {GrassTexture}}
  
  // Set up a very rough stone 
  #declare Blockwall_Contrast        = 0.8;             
  #declare Blockwall_ClipBlock       = 1;
  #declare Blockwall_MatrixSpacing   = 0.05;
  #declare Blockwall_HBias           = 0.3;
  #declare Blockwall_VBias           = 3;  
  #declare Blockwall_MaxHU           = 3;  
  #declare Blockwall_MaxVU           = 2; 
  #declare Blockwall_Finish = finish{ambient 0.01} 

  // Create a circular wall
  #declare Blockwall_WallHeight = 0.6;
  #declare Blockwall_BlockThickness = 0.18;
  #declare Blockwall_Holes = union {
    box {<-0.401,0.099,-1.41><0.401,1.4,-1>}
    cylinder {<0,1.4,-1.41><0,1.4,-1>,0.4}
    translate 2*y
  }
   
  #declare Blockwall_Radius        = 0.6;             
  Blockwall_Arc (-360, "BuffBrick")
  
  // Upright supports
  box {<-0.45,0,-0.075><-0.4,1.2,0.075>
    texture { 
      pigment {wood scale 0.01 turbulence 0.4 rotate x*90}
      finish {ambient 0.01} 
    }
  }
  box {< 0.45,0,-0.075>< 0.4,1.2,0.075> 
    texture { 
      pigment {wood scale 0.01 turbulence 0.4 rotate x*90}
      finish {ambient 0.01}
    }
  }
  
  // Winding Handle
  union {
    cylinder {<-0.46,0,0><0.65,0,0>,0.0125 
      pigment {rgb 0.1}
      finish {reflection 0.8}
    }
    cylinder {<0.6,0.2,0><0.85,0.2,0>,0.0125
      pigment {rgb 0.1}
      finish {reflection 0.8}
    }
    box {<0.61,-0.03,-0.02><0.64,0.23,0.02>
      texture { 
        pigment {wood scale 0.01 turbulence 0.4 rotate x*90}
        finish {ambient 0.04}
      }
    }
    rotate 175*x translate y*0.85
  }
  
  // Roof
  #local RoofPanel = box {<-0.46,-0.005,-0.5><0.46,0,0>
    texture {
      pigment {rgb 0.1}
      normal {agate 1 scale 0.02}
      finish {ambient 0 phong 0.3}  
    }
    rotate -20*x
    translate 1.25*y
  }
  object {RoofPanel}
  object {RoofPanel rotate y*180}
  
#end 


// Example 23: A Fireplace
#if (Example=23)
  camera {location <-0.3,1.2,-0.9> look_at 0.4*y }
  light_source {<-5,20,-10>, rgb 1}
  global_settings {ambient_light 0.2}
  
  // Declare the holes to cut
  #declare Blockwall_Holes = union {
    box {<-0.251,-0.01 ,-0.01><0.251,0.501,0.301>}
    box {<-0.351, 0.499,-0.01><0.351,0.601,0.301>}
  }

  // Generate the masonry
  #declare Blockwall_MatrixSpacing = 0.05;
  object {Blockwall_Fill(<-0.6,0,0>,<0.6,0.8,0.3>,"BlueBrick")}  
  
  // Lintel
  Blockwall_Block(<-0.35, 0.6,0>,<0.35,0.6,0.0>,<0.35,0.5,0.0>,<-0.35, 0.5,0>,"GreyBrick")

  // Surround 
  #undef Blockwall_Holes
  object {Blockwall_Fill(<-0.65,0,0>,<0.65,0.5,0.05>,"RedBrick")
    rotate x*90
    translate -z*0.2
  }  

  // Mantlepiece
  box {<-0.63,0.8,-0.03><0.63,0.83,0.33>
    pigment {wood scale 0.01 turbulence 0.4 rotate y*90}
  }
    
  // Mortar
  difference {
    box {<-0.59,0,0.011>,<0.59,0.8,0.29>}
    box {<-0.26,-0.01 ,-0.01><0.26,0.51,0.29>}
    texture {
      pigment {rgb 0.3}
      normal {agate scale 0.01}
    }
  }
  
  // Wall and Floor
  plane {-z,-0.3 pigment {rgb <1,0.9,0.4>*2}}
  plane { y,-0.04 texture {GrassTexture}}
#end 


// Example 24: A Bridge
#if (Example=24)
//  camera {location <7,2,-12> look_at -3.5*z }
  camera {location <25,10,-38> look_at -3.5*z }
  light_source {<-10,20,0>, rgb 1}  // Comment out to get night-time scene 
  light_source {<200,20,200>, rgb 0.8}
  light_source {<1,4,-14>, rgb <1,0.6,0.1> spotlight point_at <1,0,-12> falloff 60}
  light_source {<0,1.2,0>, rgb 0.1*<1,0.7,0.1> spotlight point_at 0 falloff 180}
  global_settings {ambient_light 0.3} 
  #local MatrixSpacing = 0.5;           // Use 0.05 for detailed view
  
  // Declare a line for the bridge to follow.
  #declare BridgeLineSpline = spline {
    cubic_spline 
    -0.25, < 15 ,10,-20  >
     0,    < 5  ,10,-15  >
     0.25, < 0.4,10, -7.5>
     0.5 , < 0  ,10,  0  >
     0.75, <-0.4,10,  7.5>
     1,    <-2  ,10, 15  >
     1.25, <-8  ,10, 20  >
  } 
  
  // Create a big long blobby object the shape of the top of the bridge 
  // and the indentation in the ground.
  #declare RiverCutting = blob { threshold 0.6 
    // Use a strong cylindrical core with 4 negative corner cylinders 
    // to compress the edges into cusps 
    cylinder{<-1000,0,0>, <1000,0,0>, 4  ,  1.5 scale <1,1,5> } 
    cylinder{<-1000,0,0>, <1000,0,0>, 2.5, -1   scale <1,1,3> translate <0, 2,7.5>} 
    cylinder{<-1000,0,0>, <1000,0,0>, 2.5, -1   scale <1,1,3> translate <0,-2,7.5>} 
    cylinder{<-1000,0,0>, <1000,0,0>, 2.5, -1   scale <1,1,3> translate <0, 2,-7.5>} 
    cylinder{<-1000,0,0>, <1000,0,0>, 2.5, -1   scale <1,1,3> translate <0,-2,-7.5>}
    // Add some components to break up the straight lines upstream and 
    // downstream of the bridge
    cylinder{<-1000,0,0>, <-3,0,0>, 2.5, 0.5
      scale <1,1,4> rotate <0,  3,-1> translate <  0,0,-1.5>
    }
    cylinder{<-1000,0,0>, < 3,0,0>, 4.5, 2
      scale <1,1,1> rotate <0,-30, 0> translate <-10,0, 0  >
    }
    cylinder{< 1000,0,0>, < 3,0,0>, 2.5, 1
      scale <1,1,3> rotate <0, -3, 3> translate <  4,0,-1.5>
    }
    scale <1,1,1.4>
  }
  
  // Declare an object that the Blockwall_FollowSpline macro can use to cut the 
  // bridge shape out of.
  // This includes arch holes and the top and bottom surfaces. 
  #declare Blockwall_Holes = union {
    box {<-2.5,-4,-5.15><2.5,-0.5,-2.45>}
    box {<-2.5,-4,-1.95><2.5,-0.5, 1.95>}
    box {<-2.5,-4, 5.15><2.5,-0.5, 2.45>}
    cylinder {<-2.5,-0.5,-3.8><2.5,-0.5,-3.8>,1.35}
    cylinder {<-2.5,-0.5, 0  ><2.5,-0.5, 0  >,1.95}
    cylinder {<-2.5,-0.5, 3.8><2.5,-0.5, 3.8>,1.35} 
    object {RiverCutting inverse translate -y*0.5} 
  }
  
  // Create the main body of the bridge (with holes)
  #declare Blockwall_Finish = finish {ambient 0.01}
  #declare Blockwall_MatrixSpacing   = MatrixSpacing;
  #declare Blockwall_WallHeight      = 6.75;
  #declare Blockwall_BlockThickness  = 0.4;
  // Create a spline that tracks along the bottom of the bridge
  #declare Blockwall_Target = plane {y,-4}
  #declare Blockwall_Spline = BridgeLineSpline;
  Blockwall_DropSplineToSurface() 
  object {Blockwall_FollowSpline("BuffStone") translate -1.8*x}
  object {Blockwall_FollowSpline("BuffStone") translate  2.3*x}

  // Add thick walls to support the arches
  Blockwall_Undef()
  #declare Blockwall_Finish = finish {ambient 0.01}
  #declare Blockwall_MatrixSpacing   = MatrixSpacing;
  Blockwall_Fill(<-2.4,-2.2,-5.45><2.4,-0.5,-4.95>,"BuffBrick")
  Blockwall_Fill(<-2.4,-3.0,-1.75><2.4,-0.5,-2.65>,"BuffBrick")
  Blockwall_Fill(<-2.4,-3.0, 1.75><2.4,-0.5, 2.65>,"BuffBrick")
  Blockwall_Fill(<-2.4,-2.2, 5.45><2.4,-0.5, 4.95>,"BuffBrick")
  
  // Insert the three arches
  Blockwall_Undef()
  #declare Blockwall_MatrixSpacing   = MatrixSpacing;
  #declare Blockwall_WallHeight      = 4.8;
  #declare Blockwall_Radius          = 1.15;
  #declare Blockwall_Finish = finish {ambient 0.01}
  object {Blockwall_Arc(180,"BuffBrick")
    rotate z*90 translate <2.4,-0.5,-3.80>
  }
  object {Blockwall_Arc(180,"BuffBrick")
    rotate z*90 translate <2.4,-0.5,3.80>
  }  
  #declare Blockwall_Radius          = 1.75;
  object {Blockwall_Arc(180,"BuffBrick")
    rotate z*90 translate <2.4,-0.5,0>
  }  

  // Reset control variables so we can use the defaults for the next type of wall
  Blockwall_Undef()

  // Create a spline that tracks along the top of the bridge
  #declare Blockwall_Target = object {RiverCutting translate -y*0.5}
  #declare Blockwall_Spline = BridgeLineSpline;
  Blockwall_DropSplineToSurface() 

  // Add Roadside Walls 
  #declare Blockwall_MatrixSpacing   = MatrixSpacing*1.2;
  #declare Blockwall_BlockThickness  = 0.3;
  #declare Blockwall_Finish          = finish {ambient 0.01}
  object {Blockwall_FollowSpline("BuffBrick") translate <-2.0,0.17,0>}
  object {Blockwall_FollowSpline("BuffBrick") translate < 2.3,0.17,0>}

  // Add kurbstones along the edges of the road and out through the bridge parapet
  #declare Blockwall_WallHeight      = 0.2;  
  #declare Blockwall_BlockThickness  = 0.5;  
  object {Blockwall_FollowSpline("BuffBrick") translate <-1.9,-0.02,0>}
  object {Blockwall_FollowSpline("BuffBrick") translate < 2.4,-0.02,0>}
  
  // Draw some Grass
  difference {
    plane {y,0.1}
    object {RiverCutting translate y*0.4}
    texture {GrassTexture}
  }

  // Draw some Water
  plane {y,-1.4 
    texture {
      pigment {rgbt <0,0,0.03,0.2>} 
      normal {bozo scale 0.2*<1,1,0.5>}
      finish {phong 1 reflection 0.2}
    }
  }    
  
  // Create a prism that follows the course of the road
  #local Increments = 10;
  #local Width = 2;
  #local RoadPrism = prism {
    linear_spline
    -4, 4, (Increments+1)*2+1,
    #local I = 0;
    #while (I<=Increments)
      <BridgeLineSpline(I/Increments).x-Width,BridgeLineSpline(I/Increments).z>       
      #local I = I+1;
    #end
    #local I = Increments;
    #while (I>=0)
      <BridgeLineSpline(I/Increments).x+Width,BridgeLineSpline(I/Increments).z>       
      #local I = I-1;
    #end
    <BridgeLineSpline(0).x-Width,BridgeLineSpline(0).z>       
  }

  // Cut a slice of tarmac to serve as the road surface over the bridge.
  intersection {
    object {RoadPrism}
    difference {
      object {RiverCutting}
      object {RiverCutting translate -y*0.2}
    }
    texture {
      pigment {rgb 0.03}
      normal {agate scale 0.01}
    }
    translate -y*0.5
  }

#end 



// Example 25: A country wall 
#if (Example=25)
  camera {location <-1.0,1.2,-1.4> look_at 0.5*y }
  light_source {<20,20,-50>, rgb 1}
  
  // Add a sky and some grass
  sky_sphere {pigment {SkyPigment}}    
  plane {y,0 texture {GrassTexture}}
  
  // Set up a very rough stone 
  #declare Blockwall_Contrast        = 0.8;             
  #declare Blockwall_ClipBlock       = 1;
  #declare Blockwall_MatrixSpacing   = 0.05;
  #declare Blockwall_HBias           = 0.3;
  #declare Blockwall_VBias           = 3;  
  #declare Blockwall_MaxHU           = 3;  
  #declare Blockwall_MaxVU           = 2; 
  #declare Blockwall_Finish = finish{ambient 0.01} 

  // Create a circular wall
  #declare Blockwall_WallHeight = 0.6;
  #declare Blockwall_BlockThickness = 0.18;
  #declare Blockwall_Holes = union {
    box {<-0.401,0.099,-1.41><0.401,1.4,-1>}
    cylinder {<0,1.4,-1.41><0,1.4,-1>,0.4}
    translate 2*y
  }
   
  #declare Blockwall_Radius        = 0.6;             
  Blockwall_Arc (-360, "BuffBrick")
  
  // Upright supports
  box {<-0.45,0,-0.075><-0.4,1.2,0.075>
    texture { 
      pigment {wood scale 0.01 turbulence 0.4 rotate x*90}
      finish {ambient 0.01} 
    }
  }
  box {< 0.45,0,-0.075>< 0.4,1.2,0.075> 
    texture { 
      pigment {wood scale 0.01 turbulence 0.4 rotate x*90}
      finish {ambient 0.01}
    }
  }
  
  // Winding Handle
  union {
    cylinder {<-0.46,0,0><0.65,0,0>,0.0125 
      pigment {rgb 0.1}
      finish {reflection 0.8}
    }
    cylinder {<0.6,0.2,0><0.85,0.2,0>,0.0125
      pigment {rgb 0.1}
      finish {reflection 0.8}
    }
    box {<0.61,-0.03,-0.02><0.64,0.23,0.02>
      texture { 
        pigment {wood scale 0.01 turbulence 0.4 rotate x*90}
        finish {ambient 0.04}
      }
    }
    rotate 175*x translate y*0.85
  }
  
  // Roof
  #local RoofPanel = box {<-0.46,-0.005,-0.5><0.46,0,0>
    texture {
      pigment {rgb 0.1}
      normal {agate 1 scale 0.02}
      finish {ambient 0 phong 0.3}  
    }
    rotate -20*x
    translate 1.25*y
  }
  object {RoofPanel}
  object {RoofPanel rotate y*180}
  
#end 
