//
// rope.pov
// --------
// Created by Chris Bartlett May 2009
// This scene file illustrates the use of the 'Rope' macros in 'rope.inc'. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 1 metre
//
// Adding a rope to your scene is likely to add between 5 and 80 seconds to your render
// time for short lengths (e.g. 1-10 metres), depending on the length and the level of 
// detail used.
//
// See rope.html for a full list of settings and illustrations of the examples.

// This file contains a series of separate examples, controlled using the 
// 'Example' variable (320x240 AA 0.3). 
//
//   Example = 0  The default rope.
//   Example = 1  Setting a path for the rope to follow.
//   Example = 2  Using an array for the path to add a knot.
//   Example = 3  Adding a figure of eight knot.
//   Example = 4  Gravity.
//   Example = 5  Adding a reef knot.
//   Example = 6  Tying two pieces of rope with a reef knot.
//   Example = 7  Inline complete reef knot.
//   Example = 8  Clove hitch.
//   Example = 9  Round turn and two half hitches.
//   Example = 10 Bowline.
//   Example = 11 Dutch Marine Bowline/Cowboy Bowline.
//   Example = 12 Two half hitches.
//   Example = 13 A noose.
//   Example = 14 Helix.
//   Example = 15 Using the Rope_FindEdge macro.
//   Example = 16 Using the Rope_TrackOver macro.
//   Example = 17 Spiral.
//   Example = 18 Bind End.
//   Example = 19 Setting individual strand colors.
//
// The following examples illustrate some of the predefined styles tied in knots (320x240 AA 0.3).
//
//   Example = 20 Gold Braided.
//   Example = 21 Patchwork.
//   Example = 22 Soft Yellow Braided.
//   Example = 23 Red Knobbly.
//   Example = 24 Loose Gold Braid.
//   Example = 25 White.
//   Example = 26 Cyan.
//   Example = 27 Cyan Braided.
//
// A few more complete scenes incorporating ropes (800x600 AA 0.3): 
//
//   Example = 40 Rope barrier on keyside.
//   Example = 41 Kids climbing frame with rope ladder.
//
//
// A set of images used to illustrate the predefined rope styles in the html documentation (320x240 AA 0.3): 
//
//   Examples: 120-131 showing left and right handed helix styles.
//   Examples: 140-151 showing braided styles.

// You can generate a sequence of these examples using animation command-line options 
// (e.g. +kfi0 +kff27) and the frame_number read-only identifier.
// 
// #declare Example = frame_number;
#declare Example = 4;


// Example 0: The default rope.
#if (Example=0)
  camera {location  <-0.6, 1, -0.6> look_at 0.75*y}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  Rope("")
#end

//  Example 1:  Setting a path for the rope to follow.
#if (Example=1)
  camera {location  <-0.3, 0.4,-0.3> look_at <0.3,0,0.3>}
  light_source {<10, 20, -80> color rgb 1}
  plane {y,-0.018 pigment {rgb <0.5,0,00>} normal {agate scale 0.1}}
  #include "rope.inc"
  #declare Rope_CentreSpline = spline {
    natural_spline   
    0   , < 0   ,0  , 0   >,
    0.25, < 0.15,0  , 1.0 >,
    0.49, < 0.52,0  , 0.54>,
    0.50, < 0.5 ,0  , 0.5 >,
    0.51, < 0.54,0  , 0.52>,
    0.75, < 1.0 ,0  , 0.15>,
    1   , < 0   ,0  , 0   >,
  }
  Rope("Gold Braided")
#end


//  Example :2  Using an array for the path to add a knot.
#if (Example=2)
  camera {location  <0.2, 1.1, -0.4> look_at <0.25,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {<-70, 0.2,  80> color rgb 0.8}
  #include "rope.inc"
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0  ,1  , 0  >)
  Rope_AddPoint(< 0.2,1  , 0  >)
  #declare Rope_KnotLooseness = 1;
  Rope_OverhandKnot()
  Rope_AddPoint(< 1,1  , 0  >)
  
  Rope_ArrayToSpline("")
  
  Rope("Left Helix Brown") 
#end   


//  Example :3  Adding a figure of eight knot.
#if (Example=3)
  camera {location  <0.3, 1.3, 0.03> look_at <0.28,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {<-70, 0.2,  80> color rgb 0.8}
  #include "rope.inc"
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
//  #declare Rope_KnotHandedness = -1;
  Rope_AddPoint(< 0  ,1  , 0  >)
  Rope_AddPoint(< 0.2,1  , 0  >)
  #declare Rope_KnotLooseness = 1;
  Rope_FigureOfEight()
  Rope_AddPoint(< 1,1  , 0  >)
  
  Rope_ArrayToSpline("")
  
//  #declare Rope_ShowFibres      = 0;
  Rope("Left Helix Brown") 
#end   


//  Example :4  Gravity.
#if (Example=4)
  camera {location  <0.5, 1.0, -1.75> look_at <0.5,1.0,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {<-70, 0.2,  80> color rgb 0.8}
  #include "rope.inc"

  Rope_AddPoint     (< 0  ,1.5, 00  >)
  Rope_SlackSegment(< 1.0  ,1.0, 0  >,2)
  Rope_ArrayToRope("") 
  
  Rope_Undef()
  
  Rope_AddPoint     (< 0  ,1.5, 00  >)
  #local Rope_Catenary_a = 0.23;
  Rope_Catenary(< 1.0  ,1.0, 0  >)
  #declare Rope_Radius = Rope_Radius*2;
  object {Rope_ArrayToRope("Cyan") translate 0.03*z}
#end   


//  Example :5  Adding a reef knot.
#if (Example=5)
  camera {location  <0.1, 1.4,-0.03> look_at <0.28,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {<-70, 0.2,  80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres      = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0  ,1  , 0  >)
  Rope_AddPoint(< 0.2,1  , 0  >)
  #declare Rope_KnotLooseness = 1;
  Rope_ReefKnot(1)
  Rope_AddPoint(< 0.12,1  , 0.17>)
  Rope_AddPoint(< 0  ,1  , 0.4>)
  
  Rope_ArrayToSpline("")
  Rope("Left Helix Brown") 
  #undef Rope_Array 

  
  Rope_AddPoint(< 0.6,1  , 0.038>)
  Rope_ReefKnot(2)
  Rope_AddPoint(< 0.6,1  , 0   >)
  
  Rope_ArrayToSpline("")
  Rope("Left Helix Brown") 
#end   


//  Example :6  Tying two pieces of rope with a reef knot.
#if (Example=6)
  camera {location  <0.20, 1.32,-0.09> look_at <0.25,1,-0.03>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 1;
  #declare Rope_KnotLooseness = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  // Create a little lead-in to where the knot will start.
  Rope_AddPoint(< 0  ,1  , 0  >)
  Rope_AddPoint(< 0.2,1  , 0  >)
  // Turn the rope so the knot is formed at an angle.
  #declare Rope_ArrayAheadVector = <0.3,0,-0.5>;
  // Add the knot at this angle
  Rope_ReefKnot(1)
  // Lead the rope away. 
  // Note A1: The first half of this knot ends close to where it began.
  Rope_AddPoint(< 0.3,1.1, 0.1>)
  // Add the first length of rope to the scene.
  Rope_ArrayToSpline("")      // See Note A2 below.
  Rope("Left Helix Brown")   // See Note A2 below.
  // Undefine the array before starting a second piece of rope. 
  #undef Rope_Array           // See Note A2 below.
  // Note A2: If you comment out these last 3 lines of code it just creates 
  // a single length of rope by connecting the last point added above to the 
  // first point specified below. 
  
  // Create a point some distance from the knot.
  Rope_AddPoint(< 0.5,0.9,-0.1>)
  // Add the second half of the same knot.
  Rope_ReefKnot(2)
  // Lead the rope away.
  Rope_AddPoint(< 0.15,1  ,-0.4>)
  // Add this second length of rope to the scene.
  Rope_ArrayToSpline("")
  Rope("Left Helix Brown") 
#end   


//  Example :7  Inline complete reef knot.
#if (Example=7)
  camera {location  <0.25, 1.22,-0.2> look_at <0.25,1,-0.03>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  1;
  #declare Rope_KnotLooseness  =  1;
  #declare Rope_KnotHandedness = -1;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0  ,1  , 0  >)
  Rope_AddPoint(< 0.2,1  , 0  >)
  Rope_ReefKnot(0)
  Rope_AddPoint(< 0.5,1  , 0  >)
  Rope_ArrayToSpline("quadratic_spline")
  Rope("Left Helix Brown") 
#end   


//  Example :8  Clove hitch.
#if (Example=8)
  camera {location  <0.2,1.25,-0.05> look_at <0.25,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  1;
  #declare Rope_KnotLooseness  =  1;
  #declare Rope_KnotHandedness =  1;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  #declare Rope_PoleRadius     = 0.02;
  cylinder {<0,0.98,0>,<0.5,0.98,0>,Rope_PoleRadius pigment {rgb <1,1,0>}}
  
  Rope_AddPoint(< 0.25,1    , -0.2  >)
  Rope_AddPoint(< 0.25,1.018, -(Rope_PoleRadius+0.018)>)
  Rope_CloveHitch()
  Rope_AddPoint(< 0.214,1.05,  0.2>)
  Rope_ArrayToSpline("")
  Rope("Left Helix Brown") 
#end   
 

//  Example :9  Round turn and two half hitches.
#if (Example=9)
  camera {location  <0.23, 1.4,-0.05> look_at <0.25,1,-0.03>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 1;
  #declare Rope_KnotLooseness = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0   ,1, 0  >)
  Rope_AddPoint(< 0.2 ,1, 0  >)
  // Add the first part of the knot (just a straight section)
  Rope_RoundTurnAndTwoHalfHitches(0)
  // Lead the rope away.
  Rope_AddPoint(< 0.22,1   , 0.1>)
  Rope_AddPoint(< 0.2 ,0.95, 0.2>)
  // Add the rope to the scene.
  Rope_ArrayToSpline("")
  Rope("Left Helix Brown") 
#end   
 
 
//  Example :10 Bowline.
#if (Example=10)
//  camera {location  <-0.1, 1.45,-0.15> look_at <0.1,1,0>}
  camera {location  < 0.16, 1.4,-0.04> look_at <0.16,1,0>}
  light_source {<-70, 200,-80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 0;
  #declare Rope_KnotLooseness = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0.5 ,1, 0>)
  Rope_AddPoint(< 0.3 ,1, 0>)
  Rope_Bowline(0)
  Rope_AddPoint(< 0.1 ,0.98 ,-0.01>)

  Rope_ArrayToRope("White")
#end   


//  Example :11 Dutch Marine Bowline/Cowboy Bowline.
#if (Example=11)
  camera {location  < 0.16, 1.4,-0.04> look_at <0.16,1,0>}
  light_source {<-70, 200,-80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 0;
  #declare Rope_KnotLooseness = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0.5 ,1, 0>)
  Rope_AddPoint(< 0.3 ,1, 0>)
  Rope_DutchBowline(0)
  Rope_AddPoint(< 0.1 ,1 ,-0.15>)

  Rope_ArrayToRope("White")
#end   


//  Example :12  Two half hitches.
#if (Example=12)
  camera {location  <0.23, 1.4,-0.05> look_at <0.25,1,-0.03>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 1;
  #declare Rope_KnotLooseness = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0   ,1, 0  >)
  Rope_AddPoint(< 0.2 ,1, 0  >)
  // Add the first part of the knot (just a straight section)
  Rope_RoundTurnAndTwoHalfHitches(1)
  Rope_AddPoint(< 0.45,1, 0  >)
  Rope_AddPoint(< 0.45,1.03,-0.1>)
  Rope_AddPoint(< 0.3 ,1.03,-0.1>)
  // Add the second and main part of the same knot.
  Rope_RoundTurnAndTwoHalfHitches(2)
  // Lead the rope away.
  Rope_AddPoint(< 0.22,1   , 0.1>)
  Rope_AddPoint(< 0.2 ,0.95, 0.2>)
  // Add the rope to the scene.
  Rope_ArrayToSpline("")
  Rope("Left Helix Brown") 
#end   
 

//  Example: 13  A noose.
#if (Example=13)
  camera {location  <0, 0.75,-2.5> look_at <0,0.75,0>}
  light_source {< 70, 200, -80> color rgb 0.8}
  light_source {<-70, 0.2,  80> color rgb 0.8}
  #include "rope.inc"
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(< 0  ,3  , 0  >)
  Rope_AddPoint(< 0  ,1.8  , 0  >)
  #declare Rope_KnotLooseness = 1;
  Rope_Noose(0)
  Rope_AddPoint(< 0.17  ,1.76, -0.02>)
  
  Rope_ArrayToSpline("")
  
  #declare Rope_ShowFibres      = 0;
  Rope("") 
#end  
 
 
//  Example :14 Helix.
#if (Example=14)
  camera {location  <-0.15, 1.25,-0.25> look_at <0.15,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 0;
  #declare Rope_KnotLooseness = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  #declare Rope_PoleRadius     = 0.03;
  #declare Rope_Radius         = 0.02;
  cylinder {<0,1,0>,<0.5,1,0>,Rope_PoleRadius
    pigment {rgb <1,1,0>}
    normal {wood turbulence 0.01 scale 0.003 rotate y*90 translate y}
  }
  
  Rope_AddPoint(< 0.3 ,1+Rope_PoleRadius+Rope_Radius,-0.15>)
  Rope_AddPoint(< 0.3 ,1+Rope_PoleRadius+Rope_Radius, 0  >)
  // Add the helix
  #declare Rope_Coils  = 6;
  #declare Rope_UpDispPerCoil     = 0;  
  #declare Rope_RightDispPerCoil  = -1;  
  Rope_Spiral()
  Rope_AddPoint(<0 ,1 ,0.15>)

  Rope_ArrayToRope("White")
#end   

 
//  Example :15 Using the Rope_FindEdge macro.
#if (Example=15)
  camera {location  <0, 0.6,-0.5> look_at <2,1,1>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 1;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  #declare TargetObject = box {<2,0,0><2.5,2,2> } 
  object {TargetObject pigment {brick scale 0.02 rotate y*90}}
  
  Rope_AddPoint(< 0.5 ,1, 0.5>)
  Rope_SlackSegment(Rope_FindEdge(TargetObject)+0.036*vnormalize(Rope_TraceNormal),2.5)

  Rope_ArrayToRope("Left Helix Brown")
#end   


//  Example :16 Using the Rope_TrackOver macro.
#if (Example=16)
  camera {location  <-0.15, 2.2,-0.3> look_at <0.7,0.6,0.2>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 1;
  #declare Rope_Radius        = 0.035;
  
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  // Create a composite object and turn it through 30 degrees
  #declare TargetObject = union {
    box {<0,0,0><1,1,1>                     pigment {brick scale 0.02}}    
    box {<0.1,1,0.1><0.9,1.1.9>             pigment {rgb <1,1,0>}}    
    cylinder {<0.5,1,0.05><0.5,1,0.95>,0.25 pigment {rgb <1,0,1>}}
    rotate y*30
  }
  object {TargetObject}
  
  // Add a starting point for the rope
  Rope_AddPoint(< 0 ,0, 0.3>)
  // Find the leading edge of the object and add it into the rope 
  Rope_AddPoint(Rope_FindEdge(TargetObject)+0.018*vnormalize(Rope_TraceNormal))
  // Break the spline into two so we get a sharp transition
  Rope_BreakSpline("")
  // Drape the rope over the top of the object
  Rope_TrackOver(TargetObject)

  // Add the rope to the scene
  Rope_ArrayToRope("Cyan")
#end   


//  Example :17 Spiral.
#if (Example=17)
  camera {location  <-0.15, 0.45,-0.35> look_at 0.1*x}
  light_source {<-90, 200,-20> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 0;
  
  plane {y,-0.02 pigment {rgb <0,0.1,0.3>}}
  
  Rope_AddPoint(<0,0.09,-0.1>)
  Rope_AddPoint(<0,0.1, 0   >) 
  #declare Rope_ArrayUpVector = -x;
  // Add the helix
  #declare Rope_CentreDisplacement = 3;
  #declare Rope_Coils  = 2.1;
  #declare Rope_UpDispPerCoil     = 0;  
  #declare Rope_RightDispPerCoil  = -1;  
  Rope_Spiral()                
  #declare Rope_Coils  = 4.2;
  #declare Rope_UpDispPerCoil     = 1;  
  #declare Rope_RightDispPerCoil  = 0;  
  Rope_Spiral()                
  Rope_AddPoint(<0.4 ,0,0.35>) 
  
  Rope_ArrayToRope("White")
  Rope_Binding("Both")
#end      


//  Example :18 Bind Ends.
#if (Example=18)
  camera {location  <-0.12, 0.1,-0.15> look_at <0.1,0,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres    = 1;
    
  // Add a starting point for the rope
  Rope_AddPoint(< 0   ,0, 0>)
  Rope_AddPoint(< 0.1 ,0, 0>)
  Rope_AddPoint(< 0.16,0.06,0>)

  // Add the rope to the scene
  Rope_ArrayToRope("Loose Gold Braid")
  // Bind the end
  Rope_Binding("Both")
  
  Rope_Undef()
  // Add a starting point for the rope
  Rope_AddPoint(< 0   ,0, 0>)
  Rope_AddPoint(< 0.1 ,0, 0>)
  Rope_AddPoint(< 0.16,0.06,0>)
  // Add a braided rope to the scene 
  union {
    Rope_ArrayToRope("")
    // Bind the end
    Rope_Binding("Both")
    translate -0.07*z 
  }
#end   


//  Example: 19 Setting individual strand colors.
#if (Example=19)   
  camera {location  <-0.6, 1, -0.6> look_at 0.75*y}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {< 70, 0.2, -80> color rgb 1.2}
  plane {y,0 pigment {rgb <0,0.1,0.3>}}

  #include "rope.inc"
  #declare Rope_StrandTextureArray     =  array[6];
  #declare Rope_StrandTextureArray[0]  = texture {pigment {rgb <1.5,0,0>}}
  #declare Rope_StrandTextureArray[1]  = texture {pigment {rgb <0,0,1.5>}}
  #declare Rope_StrandTextureArray[2]  = texture {pigment {rgb <1,1,1>}}
  #declare Rope_ShowFibres     =  0;
  Rope("") 
#end
   

//  Example: 20 Gold Braided.
#if (Example=20)   
  camera {location  <0.1,1.25,-0.05> look_at <0.25,1,0>}
  light_source {<-90, 200, 80> color rgb 1}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  1;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  #declare Rope_PoleRadius     = 0.04;
  cylinder {<0,0.98,0>,<0.5,0.98,0>,Rope_PoleRadius 
    pigment {rgb <0,0.04,0.01>} 
    normal {wood rotate y*90 scale 0.005 turbulence 0.2}
  }
  
  Rope_AddPoint(< 0.25,1    , -0.2  >)
  Rope_AddPoint(< 0.25,1.018, -(Rope_PoleRadius+0.018)>)
  Rope_CloveHitch()
  Rope_AddPoint(< 0.214,1.05,  0.2>)
  Rope_ArrayToSpline("")
  Rope("Gold Braided") 
#end   
 

//  Example: 21 Patchwork.
#if (Example=21)   
  camera {location  <0.2,1.45,-0.05> look_at <0.25,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  1;
  #declare Rope_KnotLooseness  =  1;
  #declare Rope_KnotHandedness =  1;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  #declare Rope_PoleRadius     = 0.02;
  cylinder {<0,0.98,0>,<0.5,0.98,0>,Rope_PoleRadius pigment {rgb <1,1,0>}}
  
  Rope_AddPoint(< 0.25,1    , -0.2  >)
  Rope_AddPoint(< 0.25,1.018, -(Rope_PoleRadius+0.018)>)
  Rope_CloveHitch()
  Rope_AddPoint(< 0.214,1.05,  0.2>)
  Rope_ArrayToSpline("")
  Rope("Patchwork") 
#end   
 

//  Example: 22 Soft Yellow Braided.
#if (Example=22)   
  camera {location  <0.2,1.25,-0.05> look_at <0.25,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  0;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  #declare Rope_PoleRadius     = 0.02;
  cylinder {<0,0.98,0>,<0.5,0.98,0>,Rope_PoleRadius pigment {rgb <1,1,0>}}
  
  Rope_AddPoint(< 0.25,1    , -0.2  >)
  Rope_AddPoint(< 0.25,1.018, -(Rope_PoleRadius+0.018)>)
  Rope_CloveHitch()
  Rope_AddPoint(< 0.214,1.05,  0.2>)
  Rope_ArrayToSpline("")
  Rope("Soft Yellow Braided") 
#end   


//  Example: 23 Red Knobbly.
#if (Example=23)   
  camera {location  <0.2,1.25,-0.05> look_at <0.25,1,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  1;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  #declare Rope_PoleRadius     = 0.02;
  cylinder {<0,0.98,0>,<0.5,0.98,0>,Rope_PoleRadius pigment {rgb <1,1,0>}}
  
  Rope_AddPoint(< 0.25,1    , -0.2  >)
  Rope_AddPoint(< 0.25,1.018, -(Rope_PoleRadius+0.018)>)
  Rope_CloveHitch()
  Rope_AddPoint(< 0.214,1.05,  0.2>)
  Rope_ArrayToSpline("")
  Rope("Red Knobbly") 
#end   


//  Example: 24 Loose Gold Braid.
#if (Example=24)   
  camera {location  <-0.6, 1, -0.6> look_at 0.75*y}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {< 70, 0.2, -80> color rgb 1.2}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  1;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  #declare Rope_Radius     =  0.036;
  Rope("Loose Gold Braid") 
#end   


//  Example: 25 White.
#if (Example=25)   
  camera {location  <-0.6, 1, -0.6> look_at 0.75*y}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {< 70, 0.2, -80> color rgb 1.2}
  #include "rope.inc"
  #declare Rope_ShowFibres     =  1;
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  
  Rope("White") 
#end   


//  Example: 26 Cyan.
#if (Example=26)   
  camera {location  <-0.6, 1, -0.6> look_at 0.75*y}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {< 70, 0.2, -80> color rgb 1.2}
  plane {y,0 pigment {rgb <0,0.1,0.3>}}

  #include "rope.inc"
  Rope("Cyan") 
#end   


//  Example: 27 Cyan Braided.
#if (Example=27)   
  camera {location  <-0.6, 1, -0.6> look_at 0.75*y}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {< 70, 0.2, -80> color rgb 1.2}
  plane {y,0 pigment {rgb <0,0.1,0.3>}}

  #include "rope.inc"
  Rope("Cyan Braided") 
#end 


// Set up a couple of pigments textures used for the backgrounds in several 
// of the more elaborate examples.
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


//  Example: 40 Rope barrier on keyside.
#if (Example=40)   
  camera {location  <-0.9, 0.8, -0.8> look_at <1.5,0.5,-0.2>}
//  camera {location  <-0.8, 4.8, -1.7> look_at <1.5,0.5,0>}
//  camera {location  <-1, 0.5,-1> look_at <0,0.4,0>}
  light_source {<-1, 5, -5> color rgb <1,0.7,0.4>}
//  light_source {< 70, 0.2, -80> color rgb 1.2}
  plane {y,-2 texture {pigment {rgb <0,0.05,0.15>} normal {waves 1 turbulence 0.5} finish {phong 0.5}}}
  
  // Create a simple corner at the quayside with a little bit of road and pavement.
  #declare MyGradient = pigment {gradient x turbulence 0.01
    color_map {
      [0     color rgbt 1]
      [0.995 color rgbt 1]
      [0.995 color rgbt 0]
      [1     color rgbt 0]
    }
    scale 0.35
  }
  union {
    difference {
      box {<-0.5,-0.2,-3.5><3.5,0,0.5> }
      cylinder {<-0.5,-0.1,-3.5><-0.5,0.01,-3.5>,2.8}
    }
    cylinder {<-0.5,-0.1,-3.5><-0.5,-0.099,-3.5>,2.8 pigment {rgb 0.03}normal {agate scale 0.1}}
    box {<-0.5,-3,-3.5><3.3,-0.2,0.5> pigment {rgb 1}}
    torus {2.8,0.01 translate <-0.5,-0.01,-3.5>}
    cylinder {<-0.5,-0.1,0.5><3.5,-0.1,0.5>,0.1} 
    cylinder {<3.5,-0.1,-3.5><3.5,-0.1,0.5>,0.1} 
    sphere   {<3.5,-0.1,0.5>,0.1} 
    texture {pigment {rgb 1} normal {agate 0.2 scale 0.03 turbulence 0.1} finish {ambient 0.05}}
    texture {pigment {MyGradient}}
    texture {pigment {MyGradient} rotate y*90}
  }

  #include "rope.inc"
  #declare Rope_ShowFibres = 1;
  #declare Rope_StrandFinish = finish {ambient 0}
  #declare Rope_FibreFinish  = finish {ambient 0}
  #local HoleHeight = 0.47;
  #declare FencePost = difference {
    box {<-0.05,0,-0.05><0.05,0.563,0.05>}
    cylinder {<-0.051,HoleHeight,0><0.051,HoleHeight,0>,0.025}
    box {<0,0,-0.051><0.03,0.03,0.051> rotate z*45 translate <-0.05,0.55,0>}
    box {<0,0,-0.051><0.03,0.03,0.051> rotate z*45 translate <-0.05,0.55,0> rotate y*90}
    box {<0,0,-0.051><0.03,0.03,0.051> rotate z*45 translate <-0.05,0.55,0> rotate y*180}
    box {<0,0,-0.051><0.03,0.03,0.051> rotate z*45 translate <-0.05,0.55,0> rotate y*270}
    texture {pigment {rgb 1} finish {ambient 0}}
  }
//#declare Rope_ShowPositions = 1;
//#declare Rope_ShowPositions = 0;
  
  object {FencePost}
  Rope_AddPoint (<-0.12,HoleHeight-0.15,0>)
  Rope_AddPoint (<-0.09,HoleHeight-0.05,0>)
  #declare Rope_ArrayUpVector = -y;
  Rope_OverhandKnot        ()
  Rope_AddPoint (< -0.05,HoleHeight,0>)
  Rope_AddPoint (<  0.05,HoleHeight,0>)

  Rope_BreakSpline("")
  #local I = 1;
  #while (I<=3)
    Rope_SlackSegment(<I,HoleHeight+0.01,0>,1.02+0.02*rand(Rope_RandomStream))
    object {FencePost translate I*x}
    #local I = I + 1;
  #end 
  Rope_BreakSpline("")
  #local I = 1;
  #while (I<=3)
    Rope_SlackSegment(<3,HoleHeight+0.01,-I>,1.02+0.02*rand(Rope_RandomStream))
    object {FencePost rotate y*90translate <3,0,-I>}
    #local I = I + 1;
  #end 
  Rope_ArrayToRope("")
#end 
   
//  Example: 41 Helicopter climbing frame with rope ladder and rope swing.
#if (Example=41)   
//  camera {location  <-2.3, 1.75, -2.7> look_at <0.6,1.55,0>}
//  camera {location  <-0.8, 1.75, -1.6> look_at <0.6,0.45,0>}
  camera {location  <-0.9, 0.85, -1.6> look_at <0.6,0.5,0>}
  light_source {<-10, 60, -45> color rgb 1.5}
  light_source {<-10, 1, -15> color rgb 0.5}
  sky_sphere { pigment {SkyPigment}}
  plane {y,0 texture {GrassTexture}}

  // Create some soft matting for the play area.
  #declare MyGradient = pigment {gradient x turbulence 0.01
    color_map {
      [0     color rgbt 1]
      [0.99  color rgbt 1]
      [0.99  color rgbt 0]
      [1     color rgbt 0]
    }
    scale 0.35
  }
  cylinder {-y*0.1,y*0.0001,4
    texture {
      pigment {rgb <0.05,0.3,0.2>}
      normal {agate 1 scale 0.001}
    }
    texture {pigment {MyGradient}}
    texture {pigment {MyGradient} rotate y*90}
  }
  
  #include "rope.inc"                      
  #declare Rope_ShowFibres = 1;
  #declare Rope_Radius = 0.012;
  #declare RandSeed = seed(1);
  #declare Rope_StrandFinish = finish {ambient 0.04}
  #declare Rope_FibreFinish  = finish {ambient 0.04}

  // Define a rung for the rope ladder 
  #declare Rung = difference {
    box {<-0.19,-0.015,-0.025>< 0.19, 0.015, 0.025>}
    cylinder {<-0.148,-0.016,0><-0.148, 0.016,0>,0.012} 
    cylinder {< 0.148,-0.016,0>< 0.148, 0.016,0>,0.012}
    pigment {rgb <1,0.8,0.2>}
    finish {ambient 0.04}
  }
                                           
  // Create an array of points for the rope part of the rope ladder
  Rope_AddPoint (<0,0.1,0>)
  Rope_AddPoint (<0,0.16,0>)
  #local I = 1;
  #while (I<=5)
    #declare Rope_ArrayUpVector = vrotate(Rope_ArrayUpVector,y*360*rand(RandSeed));
    Rope_OverhandKnot()
    Rope_AddPoint (<0,0.16+I*0.2,0>)
    object {Rung translate <0,0.02+0.2*I,-0.55>}
    #local I = I + 1;
  #end
  #declare Rope_KnotUpVector = -z;
  Rope_RoundTurnAndTwoHalfHitches(0)
  Rope_AddPoint (<0,1.16 ,-0.05>)
  Rope_AddPoint (<0,1.125,-0.07>)

  // Assemble the rope ladder
  #declare MyRope = Rope_ArrayToRope("")
  object {MyRope translate <-0.148,0,-0.55>}
  object {MyRope translate < 0.148,0,-0.55>}
  
  // Start a new array for the climbing rope
  Rope_Undef()
  #declare Rope_StrandFinish = finish {ambient 0.04}
  #declare Rope_FibreFinish  = finish {ambient 0.04}
  Rope_AddPoint (<-0.02,0.3,0>)
  Rope_AddPoint (<0,0.4,0>)
  Rope_ReefKnot(0)
  Rope_AddPoint (<0,1.01,0>)
  Rope_Bowline(0)
  // Add the rope to the scene
  object {Rope_ArrayToRope("") translate z*0.55}
  
  // Define a bright red skid for the helicopter
  #declare Skid = union {
    cylinder {<-0.5,1.255,0.045>< 0.1,1.255,0.045>,0.03} 
    intersection {
      torus {1,0.03}
      box {<0,-0.04,-1.04><1.04,0.04,0>}
      translate z
      rotate -x*60
      translate <0.1,1.255,0.045>
    }
    pigment {rgb <1,0,0>}
  }
  // Add two skids to the scene
  object {Skid translate -0.55*z}
  object {Skid scale <1,1,-1> translate 0.55*z}
  // Connect them with a little grey deck
  box {<-0.25,1.255,-0.53><0.2,1.27,0.53>
    pigment {color rgb 0.8} 
    normal {agate scale 0.01}
  }

  // Make a cabin
  difference {
    sphere {<0.35,1.9,0>,0.65}
    sphere {<0.35,1.9,0>,0.645}
    cylinder {<0,0,-0.66><0,0, 0.66>,0.42 scale <0.8,1,1> translate <0.054,1.95,0>}
    pigment {rgb <1,1,0>}
    normal {agate 0.3 scale 0.01}
  }
  // Add a floor
  intersection {
    box {<-1,1.5,-0.65><1,1.51,0.65>}
    sphere {<0.35,1.9,0>,0.645}
    pigment {color rgb 0.8}
    normal {agate scale 0.01}
  }
  // Add a seat
  intersection {
    box {<0,1.7,-0.65><1,1.75,0.65>}
    sphere {<0.35,1.9,0>,0.645}
    pigment {color rgb <1,0,0>}
    normal {agate scale 0.01}
  }
  
  
  // Add a yellow tail
  union {
    cylinder {<1.1,1.5,0><3.05,1.9,0>,0.05}
    cylinder {<1.1,1.9,0><3   ,1.9,0>,0.03}
    pigment {color rgb <1,1,0>}
    normal {agate 0.3 scale 0.01}
  }
  // The tail rotor
  cylinder {0,x,0.05 scale <0.5,1,0.4> pigment {color rgb <0.1,0.8,0.8>} translate <3.05,1.9,-0.04>}
  cylinder {0,x,0.05 scale <0.5,1,0.4> pigment {color rgb <0.1,0.8,0.8>} rotate z*120 translate <3.05,1.9,-0.04>}
  cylinder {0,x,0.05 scale <0.5,1,0.4> pigment {color rgb <0.1,0.8,0.8>} rotate z*240 translate <3.05,1.9,-0.04>}
  
  // The main post that holds up the helicopter.
  cylinder {<1.1,0,0><1.1,2.05,0>,0.1  pigment {color rgb 0.1} finish {reflection 0.8 ambient 0}}
  cylinder {<1.1,0,0><1.1,2.75,0>,0.05 pigment {color rgb <0  ,0.95,0>}}
  // The main blades
  cylinder {0,x,0.1 scale <1.5,0.4,1> pigment {color rgb <0.8,0.1,0.8>} translate <1.1,2.75,0>}
  cylinder {0,x,0.1 scale <1.5,0.4,1> pigment {color rgb <0.8,0.1,0.8>} rotate y*120 translate <1.1,2.75,0>}
  cylinder {0,x,0.1 scale <1.5,0.4,1> pigment {color rgb <0.8,0.1,0.8>} rotate y*240 translate <1.1,2.75,0>}
  
#end 
 
//  Example: 120-131 and 140-151 predefined rope styles.
#if (Example>120 & Example<160)   
  camera {location  <0,1.10,-0.01> look_at <0,1,0>}
  light_source {<-90, 200, 80> color rgb 1}
  #include "rope.inc"
  #if (Example>=140) 
    #declare Rope_ShowFibres = 0;
  #else
    #declare Rope_ShowFibres = 1;
  #end
  plane {y,0 pigment {rgb <0,0.1,0.3>}}
  #declare Rope_PoleRadius     = 0.04;
  Rope_AddPoint(<0,1    , -0.05 >)
  Rope_AddPoint(<0,1    ,  0.05 >)
  #if (Example = 120 | Example = 140)   Rope_ArrayToRope("Gold Braided"       ) #end
  #if (Example = 121 | Example = 141)   Rope_ArrayToRope("Patchwork"          ) #end
  #if (Example = 122 | Example = 142)   Rope_ArrayToRope("Soft Yellow Braided") #end
  #if (Example = 123 | Example = 143)   Rope_ArrayToRope("Red Knobbly"        ) #end
  #if (Example = 124 | Example = 144)   Rope_ArrayToRope("Loose Gold Braid"   ) #end
  #if (Example = 125 | Example = 145)   Rope_ArrayToRope("White"              ) #end
  #if (Example = 126 | Example = 146)   Rope_ArrayToRope("Cyan"               ) #end
  #if (Example = 127 | Example = 147)   Rope_ArrayToRope("Cyan Braided"       ) #end

  #if (Example = 128 | Example = 148)   Rope_ArrayToRope("Brown Braided"      ) #end
  #if (Example = 129 | Example = 149)   Rope_ArrayToRope("Brown"              ) #end
  #if (Example = 130 | Example = 150)   Rope_ArrayToRope("Left Helix Brown"   ) #end
  #if (Example = 131 | Example = 151)   Rope_ArrayToRope(""                   ) #end
#end   


#if (Example=999)
  camera {location  <0.5, 1.25, -4> look_at <0.5,1.25,0>}
  light_source {<-70, 200, -80> color rgb 0.8}
  light_source {<-70, 0.2,  80> color rgb 0.8}
  #include "rope.inc"
  Rope("") 
#end  








      
