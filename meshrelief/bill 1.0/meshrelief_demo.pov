// --- MESH APPROXIMATOR AND SURFACE DISPLACEMENT MACROS ---
// --- by BILL PRAGNELL, 2008 ---
// --- http://www.infradead.org/~wmp/ ---
// --- This file is licensed under the terms of the CC-LGPL ---

#include "colors.inc"
#include "meshrelief.inc"

global_settings { assumed_gamma 1 }

camera {
  location <0, 4, -6>
  up <0, 1, 0>
  right <4/3, 0, 0>
  angle 45
  look_at <0, 0, 0> }

light_source { <50, 50, -20> color White }

// declare pigment for perturbation
#declare p1 = pigment { granite color_map { [0 rgb 0.2] [0.4 rgb 0] [1 rgb 1] } scale 2 }

// make rounded box with a displacement depth of 0.1, no smoothing, no saving
object {
  Weathered_Box(<-0.5,0,-0.5>,<0.5,1,0.5>,0.2, 80, p1, 0.1, no, no, "")
  translate -2*x
  pigment { color rgb <1,0.5,0.2> }
  finish { ambient 0 phong 1 phong_size 50 } }

// make sphere with displacement depth of -0.2 (protruding), smoothed, no saving
object {
  Weathered_Spheroid(<0.5,0.5,0.5>, 80, p1, -0.2, yes, no, "")
  translate 0.5*y
  pigment { color rgb <0.2,1,0.5> }
  finish { ambient 0 phong 1 phong_size 50 } }

// make cone with displacement depth of 0.3, smoothed, save mesh2 as 'democone'
// saves file 'democone.inc' with mesh2 #declared as 'democone'
object {
  Weathered_Cone(<0,0,0>,0.75,<0,1,0>,0.1,0.1, 80, p1, 0.3, yes, yes, "democone")
  translate 2*x
  pigment { color rgb <0.2,0.5,1> }
  finish { ambient 0 phong 1 phong_size 50 } }

plane { <0, 1, 0>, 0 pigment { checker color White, color Gray80 } finish { ambient 0 } }
