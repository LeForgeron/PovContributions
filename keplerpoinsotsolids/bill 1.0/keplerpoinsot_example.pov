// Example file for using keplerpoinsot_solids.inc
// Bill Pragnell 2009
//
// This file is licensed under the terms of the CC-LGPL 

#include "keplerpoinsot_solids.inc"

global_settings {
 assumed_gamma 1
 radiosity {
  pretrace_start 0.08
  pretrace_end 0.01
  error_bound 0.2
  count 250
  low_error_factor 0.5
  minimum_reuse 0.01
  recursion_limit 1
  nearest_count 4
  gray_threshold 0
  brightness 1 } }

camera {
 location <0, 10, -12.5>
 up y
 right x
 angle 45
 look_at <0, 1, 0> }

light_source {
 <100, 150, -25> color rgb 1
 area_light 25*x, 25*y, 8, 8 circular orient adaptive 1 jitter }

// -----
// Create an array of objects containing the plain faces polyhedra.
// -----
#declare KeplerPoinsots = array[4];
#declare KeplerPoinsots[0] = object { KeplerPoinsot_small_stellated_dodecahedron_faces2(yes) }
#declare KeplerPoinsots[1] = object { KeplerPoinsot_great_dodecahedron_faces2(yes) }
#declare KeplerPoinsots[2] = object { KeplerPoinsot_great_stellated_dodecahedron_faces2(yes) }
#declare KeplerPoinsots[3] = object { KeplerPoinsot_great_icosahedron_faces2(yes) }

// -----
// Create an array of objects containing the edges/vertices of the polyhedra.
// -----
#declare EdgeT = texture { pigment { rgb 1 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare VertT = texture { pigment { rgb 0.75 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare R_Edge = 0.03;
#declare R_Vertex = 0.06;
#declare KeplerPoinsot_skels = array[4];
#declare KeplerPoinsot_skels[0] = object { KeplerPoinsot_small_stellated_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare KeplerPoinsot_skels[1] = object { KeplerPoinsot_great_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare KeplerPoinsot_skels[2] = object { KeplerPoinsot_great_stellated_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare KeplerPoinsot_skels[3] = object { KeplerPoinsot_great_icosahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }

// -----
// Loop through arrays and place the polyhedra (faces+edges) in a circular pattern.
// -----
// Please note that the faces need to be vertically translated by R_Vertex so they line up
// with the edges.
// -----
#declare Ang = 0;
#declare Num = 0;
#while (Num < 4)
 object { KeplerPoinsots[Num] translate <0, 0.06, -3> rotate y*(Ang-60) pigment { rgb 1 } finish { ambient 0 } }
 object { KeplerPoinsot_skels[Num] translate <0, 0, -3> rotate y*(Ang-60) }
 #declare Num = Num +  1;
 #declare Ang = Ang + 360/4;
#end

plane { y, 0 pigment { rgb 0.66 } finish { ambient 0 } }
background { rgb <0.1, 0.2, 0.25> }
