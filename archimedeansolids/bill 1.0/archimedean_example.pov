// Example file for using archimedean_solids.inc
// Bill Pragnell 2009
//
// This file is licensed under the terms of the CC-LGPL 

#include "archimedean_solids.inc"

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
 location <-5, 15, -10>
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
#declare Archimedeans = array[13];
#declare Archimedeans[0] = object { Archimedean_truncated_tetrahedron_faces2(yes) }
#declare Archimedeans[1] = object { Archimedean_cuboctahedron_faces2(yes) }
#declare Archimedeans[2] = object { Archimedean_truncated_cube_faces2(yes) }
#declare Archimedeans[3] = object { Archimedean_truncated_octahedron_faces2(yes) }
#declare Archimedeans[4] = object { Archimedean_rhombicuboctahedron_faces2(yes) }
#declare Archimedeans[5] = object { Archimedean_truncated_cuboctahedron_faces2(yes) }
#declare Archimedeans[6] = object { Archimedean_snub_cuboctahedron_faces2(yes) }
#declare Archimedeans[7] = object { Archimedean_icosidodecahedron_faces2(yes) }
#declare Archimedeans[8] = object { Archimedean_truncated_dodecahedron_faces2(yes) }
#declare Archimedeans[9] = object { Archimedean_truncated_icosahedron_faces2(yes) }
#declare Archimedeans[10] = object { Archimedean_rhombicosidodecahedron_faces2(yes) }
#declare Archimedeans[11] = object { Archimedean_truncated_icosidodecahedron_faces2(yes) }
#declare Archimedeans[12] = object { Archimedean_snub_icosidodecahedron_faces2(yes) }

// -----
// Create an array of objects containing the edges/vertices of the polyhedra.
// -----
#declare EdgeT = texture { pigment { rgb 1 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare VertT = texture { pigment { rgb 0.75 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare R_Edge = 0.03;
#declare R_Vertex = 0.06;
#declare Archimedean_skels = array[13];
#declare Archimedean_skels[0] = object { Archimedean_truncated_tetrahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[1] = object { Archimedean_cuboctahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[2] = object { Archimedean_truncated_cube_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[3] = object { Archimedean_truncated_octahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[4] = object { Archimedean_rhombicuboctahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[5] = object { Archimedean_truncated_cuboctahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[6] = object { Archimedean_snub_cuboctahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[7] = object { Archimedean_icosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[8] = object { Archimedean_truncated_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[9] = object { Archimedean_truncated_icosahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[10] = object { Archimedean_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[11] = object { Archimedean_truncated_icosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Archimedean_skels[12] = object { Archimedean_snub_icosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }

// -----
// Loop through arrays and place the polyhedra (faces+edges) in a circular pattern.
// -----
// Please note that the faces need to be vertically translated by R_Vertex so they line up
// with the edges.
// -----
#declare Ang = 0;
#declare Num = 0;
#while (Num < 13)
 object { Archimedeans[Num] translate <0, 0.06, -5> rotate y*Ang pigment { rgb 1 } finish { ambient 0 } }
 object { Archimedean_skels[Num] translate <0, 0, -5> rotate y*Ang }
 #declare Num = Num +  1;
 #declare Ang = Ang + 360/13;
#end

plane { y, 0 pigment { rgb 0.66 } finish { ambient 0 } }
background { rgb <0.1, 0.2, 0.25> }
