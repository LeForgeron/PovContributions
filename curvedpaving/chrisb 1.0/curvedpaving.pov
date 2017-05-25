// curvedpaving.pov
// ----------------

// This scene file illustrates the use of the curvedpaving.inc include file
// which produces block pavers in a "bogen" or "segmental arc" pattern commonly 
// found in traditionally block-paved European streets.
//
// This file is licensed under the terms of the CC-LGPL. 
// This license permits you to use, modify and redistribute the content.
// 
// Typical render time 10 seconds to 1 minute (at 640x480 AA 0.3) for 20 rows 
// of 20 blocks.
// The default settings produce a layer of paving stones about 1.4 POV-Ray 
// units wide laying on the XZ plane, centred on the Z axis and heading away
// from the origin in the +Z direction.

// This file contains a series of separate examples, controlled using the 
// 'Example' variable:
//
//   Example = 0  renders the default slab of paving blocks.
//   Example = 1  renders three copies of default slab of paving blocks side 
//                by side showing how the variables set by the macro can be 
//                used to align adjacent runs of blocks.
//   Example = 2  renders three runs with different color settings and no
//                contrast. 
//   Example = 3  renders three runs with different contrast settings using
//                the default color settings. 
//   Example = 4  renders three runs with different finish and normal settings. 
//   Example = 5  renders three runs with different block roundness and mortar
//                gap settings. 
//   Example = 6  renders three runs with different radii and illustrates how to
//                align them so that they meet seamlessly.
//   Example = 7  renders two runs and slices the section to form a path. This 
//                illustrates how to cut sections of paving to the size and shape
//                you need for your scene.
//   Example = 8  renders a section of footpath using the Polygon and Box objects
//                as alternative styles to the standard Superellipsoid shape. 
//                These are slightly quicker and the Polygon creates wedge shapes.
//   Example = 9  renders six different swatches showing standard color settings
//                that can be specified as styles.
//   Example = 10 renders An illustration of the use of brightness to adjust for 
//                higher lighting levels. Different scene files can use very 
//                different lighting levels. The brightness setting allows you to
//                compensate for this.


#declare Example = 6;

#include "curvedpaving.inc"  


// Example 0: The default run of paving
#if (Example=0)
  camera {orthographic location <0,2.8,1.74> look_at 1.75*z }
  light_source {<-10,20,-5>, rgb 1}   
  // Call the macro to generate the default slab of blocks
  object {CurvedPaving("")}  
//  cylinder {-0.7*x,0.7*x,0.01 pigment{rgb <0,0,2>} translate z}
#end  


// Example 1: Three copies of the default run of paving, side by side
#if (Example=1)
  camera {location <-2.8,1,7> look_at <-0.7,-0.6,5.5> }
  light_source {<-10,20,-5>, rgb 1}  
  
  #declare CurvedPaving_Rows       = 60; 
  // Call the macro to generate the default slab of blocks
  #declare Section = CurvedPaving("")
  // Show 3 copies of the same section side by side
  object {Section}
  object {Section translate  CurvedPaving_CentreToCentre*x}
  object {Section translate -CurvedPaving_CentreToCentre*x}
  // Add some mortar
  box {
    <-2.1,-CurvedPaving_BlockThickness-0.02,0.9><2.1,-0.01,6> 
    texture {
      pigment {rgb <1,0.9,0.8>}
      normal {CurvedPaving_Normal}
      finish {CurvedPaving_Finish}
    }
  }
  // Add some foundations
  box {
    <-2.2,-CurvedPaving_BlockThickness-0.02,0.5>
    <2.2,-CurvedPaving_BlockThickness,CurvedPaving_BlockDepth*CurvedPaving_Rows+CurvedPaving_Radius> 
    texture {
      pigment {rgb <0.8,0.8,0.8>}
      normal {CurvedPaving_Normal scale 0.5}
      finish {CurvedPaving_Finish}
    }
  }
  // Add some grass
  plane {y,-CurvedPaving_BlockThickness-0.02 
    texture {
      pigment {rgb <0,0.4,0>}
      normal {agate scale <0.01,0.05,0.01>}
    }
  }
#end 


// Example 2: Three runs with different color settings
#if (Example=2)
  camera {orthographic location <0,2.5,1.34> look_at 1.35*z }
  light_source {<-10,20,-5>, rgb 1}

  #declare CurvedPaving_Contrast = 0;
  #declare CurvedPaving_Radius     = 0.5;   

  // The central block shows the full color range
  #declare CurvedPaving_MinColor = <0,0,0>;
  #declare CurvedPaving_MaxColor = <1,1,1>;
  object {CurvedPaving("")}
  // The block on the left shows a reduced colour range
  #declare CurvedPaving_MinColor = <0.4,0.4,0.4>;
  #declare CurvedPaving_MaxColor = <0.8,0.8,0.8>;
  object {CurvedPaving("") translate -CurvedPaving_CentreToCentre*x}
  // The block on the right adds a buff (yellow/red) biase
  #declare CurvedPaving_MinColor = <1.0,0.7,0.6>;
  #declare CurvedPaving_MaxColor = <1.0,0.9,0.7>;
  object {CurvedPaving("") translate  CurvedPaving_CentreToCentre*x}
#end  


// Example 3: Three runs with different contrast settings
#if (Example=3)
  camera {orthographic location <0,2.5,1.34> look_at 1.35*z }
  light_source {<-10,20,-5>, rgb 1}

  // The central block shows the full default colors without contrast
  #declare CurvedPaving_Radius     = 0.5;   
  #declare CurvedPaving_Contrast = 0;
  object {CurvedPaving("")}
  // The block on the left shows the default setting
  #declare CurvedPaving_Contrast = 1;
  object {CurvedPaving("") translate -CurvedPaving_CentreToCentre*x}
  // The block on the right adds full contrast
  #declare CurvedPaving_Contrast = 0.5;
  object {CurvedPaving("") translate  CurvedPaving_CentreToCentre*x}
#end  


// Example 4: Three runs with different finish and normal settings
#if (Example=4)
  camera {orthographic location <0,2.5,1.34> look_at 1.35*z }
  light_source {<-10,20,-5>, rgb 1}

  // The central block shows the full default finish and normals
  #declare CurvedPaving_Radius     = 0.5;   
  object {CurvedPaving("")}
  // The block on the left uses a different normal
  #declare CurvedPaving_Normal = normal {agate scale <0.001,0.01,0.001>}
  object {CurvedPaving("") translate -CurvedPaving_CentreToCentre*x}
  // The block on the right uses a different finish
  #declare CurvedPaving_Normal = normal {granite scale 0.1}
  #declare CurvedPaving_Finish = finish {phong 1}
  object {CurvedPaving("") translate  CurvedPaving_CentreToCentre*x}
#end  


// Example 5: Three runs with different roundness and mortar thickness
#if (Example=5)
  camera {orthographic location <0,2.5,1.34> look_at 1.35*z }
  light_source {<-10,20,-5>, rgb 1}

  // The central block shows the default roundness and mortar thickness
  #declare CurvedPaving_Radius     = 0.5;   
  object {CurvedPaving("")}
  // The block on the left shows increased roundness
  #declare CurvedPaving_BlockRoundness = 0.8;
  object {CurvedPaving("") translate -CurvedPaving_CentreToCentre*x}
  // The block on the right removes roundness and adds to the mortar gap
  #declare CurvedPaving_BlockRoundness   = 0;
  #declare CurvedPaving_MortarGap = 0.01;
  object {CurvedPaving("") translate  CurvedPaving_CentreToCentre*x}
#end  


// Example 6: Three runs of blocks with different radii
#if (Example=6)
  camera {orthographic location <0,2.8,1.24> look_at 1.25*z }
  light_source {<-10,20,-5>, rgb 1}

  // The central block shows a reduced radius
  #declare CurvedPaving_Radius     = 0.5;   
  #declare CurvedPaving_MortarGap = 0.0008;
  #declare Paving1 = CurvedPaving("") 
  #local C2C1 = CurvedPaving_CentreToCentre;
  #local MinZ = z*min_extent(Paving1);
  object {Paving1 translate -MinZ}
  // The block on the left shows the default setting
  #declare CurvedPaving_Radius     = 1;
  #declare CurvedPaving_MortarGap = 0.004;
  #declare Paving2 = CurvedPaving("") 
  #local C2C2 = CurvedPaving_CentreToCentre;
  #local MinZ = z*min_extent(Paving2);
  object {Paving2 translate -x*(C2C1+C2C2)/2-MinZ}
  // The block on the right shows an increased radius
  #declare CurvedPaving_Radius     = 2.5;   
  #declare CurvedPaving_MortarGap = 0.006;
  #declare Paving3 = CurvedPaving("") 
  #local C2C3 = CurvedPaving_CentreToCentre;
  #local MinZ = z*min_extent(Paving3);
  object {Paving3 translate x*(C2C1+C2C3)/2-MinZ}
  // Add a layer of mortar
  plane {y,-0.01
    texture {
      pigment {rgb <1,0.9,0.8>}
      normal {CurvedPaving_Normal}
      finish {CurvedPaving_Finish}
    }
  }
#end  


// Example 7: Slicing and dicing sections of paving
#if (Example=7)
  camera { location <0,0.8,0> look_at 1.4*z }
  light_source {<-10,20,-5>, rgb 1}   
  // Call the macro to generate two slabs of blocks 
  #declare CurvedPaving_Rows       = 60;
  intersection {
    union { 
      object {CurvedPaving("") translate -x*CurvedPaving_CentreToCentre/2}
      object {CurvedPaving("") translate  x*CurvedPaving_CentreToCentre/2}
    }
    box {<-0.67,-0.2,1><0.67,0.01,6> texture {CurvedPaving_ThisBlockTexture}}
  }
  // Add the border on the left and right
  intersection {
    union {
      superellipsoid {<0.1,0.1> 
        translate < 1,-1,1>
        scale 0.5*<0.05,0.1,10> 
        translate <0.67,0.02,0> 
        pigment {rgb 1}
      }
      superellipsoid {<0.1,0.1> 
        translate <-1,-1,1>
        scale 0.5*<0.05,0.1,10> 
        translate <-0.67,0.02,0> 
        pigment {rgb 1}
      }                                   
    }
    // Cut the ends with the same finish and normal as the pavers
    box {<-17,-0.2,1><1,0.1,6> 
      texture {
        pigment {rgb 1}
        normal {CurvedPaving_Normal}
        finish {CurvedPaving_Finish}
      }
    }
  }
  // Add some mortar
  box {
    <-0.67,-CurvedPaving_BlockThickness-0.02,1.0001><0.67,-0.008,5.9999> 
    texture {
      pigment {rgb <1,0.9,0.8>}
      normal {CurvedPaving_Normal}
      finish {CurvedPaving_Finish}
    }
  }
#end  


// Example 8: Using alternative styles to control the generated object
#if (Example=8)
  camera { location <0,0.8,0> look_at 1.4*z }
  light_source {<-10,20,-5>, rgb 1}   
  // Call the macro to generate two slabs of blocks 
  #declare CurvedPaving_Rows       = 10;
  #declare CurvedPaving_MortarGap  = 0.01;
  intersection {
    union { 
      object {CurvedPaving("Polygon") translate -x*CurvedPaving_CentreToCentre/2}
      object {CurvedPaving("Box") translate  x*CurvedPaving_CentreToCentre/2}
    }
    box {<-0.67,-0.2,1><0.67,0.01,6> texture {CurvedPaving_ThisBlockTexture}}
  }
  // Add the border on the left and right
  intersection {
    union {
      superellipsoid {<0.1,0.1> 
        translate < 1,-1,1>
        scale 0.5*<0.05,0.1,10> 
        translate <0.67,0.02,0> 
        pigment {rgb 1}
      }
      superellipsoid {<0.1,0.1> 
        translate <-1,-1,1>
        scale 0.5*<0.05,0.1,10> 
        translate <-0.67,0.02,0> 
        pigment {rgb 1}
      }                                   
    }
    // Cut the ends with the same finish and normal as the pavers
    box {<-17,-0.2,1><1,0.1,6> 
      texture {
        pigment {rgb 1}
        normal {CurvedPaving_Normal}
        finish {CurvedPaving_Finish}
      }
    }
  }
  // Add some mortar
  box {
    <-0.67,-CurvedPaving_BlockThickness-0.02,1.0001><0.67,-0.001,5.9999> 
    texture {
      pigment {rgb <1,0.9,0.8>}
      normal {CurvedPaving_Normal}
      finish {CurvedPaving_Finish}
    }
  } 
#end  


// Example 9: A set of strips illustrating the standard color settings
#if (Example=9)
  camera {orthographic location <0,2.8,1.44> look_at 1.45*z }
  light_source {<-10,20,-5>, rgb 1}

  #declare CurvedPaving_Rows       = 10;
  #declare CurvedPaving_Radius     = 0.8;   
  object {CurvedPaving("RedBrick"  ) translate  <-CurvedPaving_CentreToCentre,0,1>} // Top Left
  object {CurvedPaving("BlueBrick" ) translate  <0,0,1>}                            // Top Centre
  object {CurvedPaving("GreenBrick") translate  < CurvedPaving_CentreToCentre,0,1>} // Top Right
  object {CurvedPaving("PinkBrick" ) translate -x*CurvedPaving_CentreToCentre}      // Bottom Left
  object {CurvedPaving("BuffBrick" ) }                                              // Bottom Centre
  object {CurvedPaving("GreyBrick" ) translate  x*CurvedPaving_CentreToCentre}      // Bottom Right
#end  


// Example 10: An illustration of the use of brightness to adjust for higher lighting levels
#if (Example=10)
  camera {orthographic location <0,2.8,1.84> look_at 1.85*z }
  light_source {<-10,20,-5>, rgb 10}

  #declare CurvedPaving_Brightness = 0.1;
  object {CurvedPaving("")}
#end 

