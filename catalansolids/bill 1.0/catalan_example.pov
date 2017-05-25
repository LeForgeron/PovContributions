// Example file for using catalan_solids.inc
// Bill Pragnell 2009
//
// This file is licensed under the terms of the CC-LGPL 

#include "catalan_solids.inc"

global_settings {
 assumed_gamma 1
 radiosity { 
  pretrace_start 0.08
  pretrace_end 0.01
  error_bound 0.2
  count 150
  low_error_factor 0.5
  minimum_reuse 0.01
  recursion_limit 1
  nearest_count 4
  gray_threshold 0
  brightness 1 } }

camera {
 location <-5, 16, -12>
 up y
 right x
 angle 45
 look_at <0, 0, 0> }

light_source {
 <100, 150, -25> color rgb 1
 area_light 25*x, 25*y, 8, 8 circular orient adaptive 1 jitter }

// -----
// Create an array of objects containing the plain faces polyhedra.
// -----
#declare Catalans = array[13];
#declare Catalans[0] = object { Catalan_triakis_tetrahedron_faces2(yes) }
#declare Catalans[1] = object { Catalan_rhombic_dodecahedron_faces2(yes) }
#declare Catalans[2] = object { Catalan_triakis_octahedron_faces2(yes) }
#declare Catalans[3] = object { Catalan_tetrakis_hexahedron_faces2(yes) }
#declare Catalans[4] = object { Catalan_trapezoidal_icositetrahedron_faces2(yes) }
#declare Catalans[5] = object { Catalan_disdyakis_dodecahedron_faces2(yes) }
#declare Catalans[6] = object { Catalan_pentagonal_icositetrahedron_faces2(yes) }
#declare Catalans[7] = object { Catalan_rhombic_triacontahedron_faces2(yes) }
#declare Catalans[8] = object { Catalan_triakis_icosahedron_faces2(yes) }
#declare Catalans[9] = object { Catalan_pentakis_dodecahedron_faces2(yes) }
#declare Catalans[10] = object { Catalan_trapezoidal_hexecontahedron_faces2(yes) }
#declare Catalans[11] = object { Catalan_disdyakis_triacontahedron_faces2(yes) }
#declare Catalans[12] = object { Catalan_pentagonal_hexecontahedron_faces2(yes) }

// -----
// Create an array of objects containing the edges/vertices of the polyhedra.
// -----
#declare EdgeT = texture { pigment { rgb 1 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare VertT = texture { pigment { rgb 0.75 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare R_Edge = 0.03;
#declare R_Vertex = 0.06;
#declare Catalan_skels = array[13];
#declare Catalan_skels[0] = object { Catalan_triakis_tetrahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[1] = object { Catalan_rhombic_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[2] = object { Catalan_triakis_octahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[3] = object { Catalan_tetrakis_hexahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[4] = object { Catalan_trapezoidal_icositetrahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[5] = object { Catalan_disdyakis_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[6] = object { Catalan_pentagonal_icositetrahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[7] = object { Catalan_rhombic_triacontahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[8] = object { Catalan_triakis_icosahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[9] = object { Catalan_pentakis_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[10] = object { Catalan_trapezoidal_hexecontahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[11] = object { Catalan_disdyakis_triacontahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Catalan_skels[12] = object { Catalan_pentagonal_hexecontahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }

// -----
// Loop through arrays and place the polyhedra (faces+edges) in a circular pattern.
// -----
// Please note that the faces need to be vertically translated by R_Vertex so they line up
// with the edges.
// -----
#declare Ang = 0;
#declare Num = 0;
#while (Num < 13)
 object { Catalans[Num] translate <0, 0.06, -6> rotate y*Ang pigment { rgb 1 } finish { ambient 0 } }
 object { Catalan_skels[Num] translate <0, 0, -6> rotate y*Ang }
 #declare Num = Num +  1;
 #declare Ang = Ang + 360/13;
#end

plane { y, 0 pigment { rgb 0.66 } finish { ambient 0 } }
background { rgb <0.1, 0.2, 0.25> }
