/* -------------------
archimedean_solids.inc

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Archimedean_truncated_tetrahedron (12 vertices)
  Archimedean_cuboctahedron (12 vertices)
  Archimedean_truncated_cube (24 vertices)
  Archimedean_truncated_octahedron (24 vertices)
  Archimedean_rhombicuboctahedron (24 vertices)
  Archimedean_truncated_cuboctahedron (48 vertices)
  Archimedean_snub_cuboctahedron (24 vertices) (2 chiral forms)
  Archimedean_icosidodecahedron (30 vertices)
  Archimedean_truncated_dodecahedron (60 vertices)
  Archimedean_truncated_icosahedron (60 vertices)
  Archimedean_rhombicosidodecahedron (60 vertices)
  Archimedean_truncated_icosidodecahedron (120 vertices)
  Archimedean_snub_icosidodecahedron (60 vertices) (2 chiral forms)

-------------------- */

#include "transforms.inc"

#declare Archimedean_truncated_tetrahedron_verts = array[12]
{
<0, 0, 1.105542>,
<0.8528029, 0, 0.7035265>,
<-0.7106691, 0.4714045, 0.7035265>,
<0.3316456, -0.7856742, 0.7035265>,
<0.9949367, 0.4714045, -0.1005038>,
<-1.089693, 0.1571348, -0.1005038>,
<-0.5685352, 0.942809, -0.1005038>,
<-0.04737794, -1.099944, -0.1005038>,
<0.6159132, 0.1571348, -0.904534>,
<0.2842676, 0.942809, -0.5025189>,
<-0.758047, -0.6285394, -0.5025189>,
<0.09475587, -0.6285394, -0.904534>,
}
#local P0 = Archimedean_truncated_tetrahedron_verts[5];
#local P1 = Archimedean_truncated_tetrahedron_verts[6];
#local P2 = Archimedean_truncated_tetrahedron_verts[9];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 12)
 #declare Archimedean_truncated_tetrahedron_verts[Num] = vtransform(Archimedean_truncated_tetrahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_truncated_tetrahedron_faces(Tex3, Tex6, OnPlane)
#local Archimedean_truncated_tetrahedron_obj = mesh2 {
 vertex_vectors {
  12,
  Archimedean_truncated_tetrahedron_verts[0],
  Archimedean_truncated_tetrahedron_verts[1],
  Archimedean_truncated_tetrahedron_verts[2],
  Archimedean_truncated_tetrahedron_verts[3],
  Archimedean_truncated_tetrahedron_verts[4],
  Archimedean_truncated_tetrahedron_verts[5],
  Archimedean_truncated_tetrahedron_verts[6],
  Archimedean_truncated_tetrahedron_verts[7],
  Archimedean_truncated_tetrahedron_verts[8],
  Archimedean_truncated_tetrahedron_verts[9],
  Archimedean_truncated_tetrahedron_verts[10],
  Archimedean_truncated_tetrahedron_verts[11]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex6 }
 }
 face_indices {
  20,
  <0, 3, 1>, 0,
  <2, 6, 5>, 0,
  <4, 8, 9>, 0,
  <7, 10, 11>, 0,
  <0, 1, 4>, 1,
  <0, 4, 9>, 1,
  <0, 9, 6>, 1,
  <0, 6, 2>, 1,
  <0, 2, 5>, 1,
  <0, 5, 10>, 1,
  <0, 10, 7>, 1,
  <0, 7, 3>, 1,
  <1, 3, 7>, 1,
  <1, 7, 11>, 1,
  <1, 11, 8>, 1,
  <1, 8, 4>, 1,
  <5, 6, 9>, 1,
  <5, 9, 8>, 1,
  <5, 8, 11>, 1,
  <5, 11, 10>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_tetrahedron_verts[5];
 #local P1 = Archimedean_truncated_tetrahedron_verts[6];
 #local P2 = Archimedean_truncated_tetrahedron_verts[9];
 #local P3 = Archimedean_truncated_tetrahedron_verts[8];
 #local P4 = Archimedean_truncated_tetrahedron_verts[11];
 #local P5 = Archimedean_truncated_tetrahedron_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_tetrahedron_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_tetrahedron_obj }
#end
#end

#macro Archimedean_truncated_tetrahedron_faces2(OnPlane)
#local Archimedean_truncated_tetrahedron_obj = mesh2 {
 vertex_vectors {
  12,
  Archimedean_truncated_tetrahedron_verts[0],
  Archimedean_truncated_tetrahedron_verts[1],
  Archimedean_truncated_tetrahedron_verts[2],
  Archimedean_truncated_tetrahedron_verts[3],
  Archimedean_truncated_tetrahedron_verts[4],
  Archimedean_truncated_tetrahedron_verts[5],
  Archimedean_truncated_tetrahedron_verts[6],
  Archimedean_truncated_tetrahedron_verts[7],
  Archimedean_truncated_tetrahedron_verts[8],
  Archimedean_truncated_tetrahedron_verts[9],
  Archimedean_truncated_tetrahedron_verts[10],
  Archimedean_truncated_tetrahedron_verts[11]
 }
 face_indices {
  20,
  <0, 3, 1>,
  <2, 6, 5>,
  <4, 8, 9>,
  <7, 10, 11>,
  <0, 1, 4>,
  <0, 4, 9>,
  <0, 9, 6>,
  <0, 6, 2>,
  <0, 2, 5>,
  <0, 5, 10>,
  <0, 10, 7>,
  <0, 7, 3>,
  <1, 3, 7>,
  <1, 7, 11>,
  <1, 11, 8>,
  <1, 8, 4>,
  <5, 6, 9>,
  <5, 9, 8>,
  <5, 8, 11>,
  <5, 11, 10>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_tetrahedron_verts[5];
 #local P1 = Archimedean_truncated_tetrahedron_verts[6];
 #local P2 = Archimedean_truncated_tetrahedron_verts[9];
 #local P3 = Archimedean_truncated_tetrahedron_verts[8];
 #local P4 = Archimedean_truncated_tetrahedron_verts[11];
 #local P5 = Archimedean_truncated_tetrahedron_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_tetrahedron_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_tetrahedron_obj }
#end
#end

#macro Archimedean_truncated_tetrahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_truncated_tetrahedron_verts[0], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[1], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[2], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[3], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[4], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[5], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[6], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[7], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[8], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[9], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[10], RadVer }
  sphere { Archimedean_truncated_tetrahedron_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_truncated_tetrahedron_verts[0], Archimedean_truncated_tetrahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[3], Archimedean_truncated_tetrahedron_verts[1], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[1], Archimedean_truncated_tetrahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[2], Archimedean_truncated_tetrahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[6], Archimedean_truncated_tetrahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[5], Archimedean_truncated_tetrahedron_verts[2], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[4], Archimedean_truncated_tetrahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[8], Archimedean_truncated_tetrahedron_verts[9], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[9], Archimedean_truncated_tetrahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[7], Archimedean_truncated_tetrahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[10], Archimedean_truncated_tetrahedron_verts[11], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[11], Archimedean_truncated_tetrahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[1], Archimedean_truncated_tetrahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[9], Archimedean_truncated_tetrahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[2], Archimedean_truncated_tetrahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[5], Archimedean_truncated_tetrahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[7], Archimedean_truncated_tetrahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_tetrahedron_verts[11], Archimedean_truncated_tetrahedron_verts[8], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_truncated_tetrahedron_verts[5];
 #local P1 = Archimedean_truncated_tetrahedron_verts[6];
 #local P2 = Archimedean_truncated_tetrahedron_verts[9];
 #local P3 = Archimedean_truncated_tetrahedron_verts[8];
 #local P4 = Archimedean_truncated_tetrahedron_verts[11];
 #local P5 = Archimedean_truncated_tetrahedron_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_cuboctahedron_verts = array[12]
{
<0, 0, 1.154701>,
<1., 0, 0.5773503>,
<0.3333333, 0.942809, 0.5773503>,
<-1., 0, 0.5773503>,
<-0.3333333, -0.942809, 0.5773503>,
<1., 0, -0.5773503>,
<0.6666667, -0.942809, 0>,
<-0.6666667, 0.942809, 0>,
<0.3333333, 0.942809, -0.5773503>,
<-1., 0, -0.5773503>,
<-0.3333333, -0.942809, -0.5773503>,
<0, 0, -1.154701>,
}
#local P0 = Archimedean_cuboctahedron_verts[7];
#local P1 = Archimedean_cuboctahedron_verts[8];
#local P2 = Archimedean_cuboctahedron_verts[11];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 12)
 #declare Archimedean_cuboctahedron_verts[Num] = vtransform(Archimedean_cuboctahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_cuboctahedron_faces(Tex3, Tex4, OnPlane)
#local Archimedean_cuboctahedron_obj = mesh2 {
 vertex_vectors {
  12,
  Archimedean_cuboctahedron_verts[0],
  Archimedean_cuboctahedron_verts[1],
  Archimedean_cuboctahedron_verts[2],
  Archimedean_cuboctahedron_verts[3],
  Archimedean_cuboctahedron_verts[4],
  Archimedean_cuboctahedron_verts[5],
  Archimedean_cuboctahedron_verts[6],
  Archimedean_cuboctahedron_verts[7],
  Archimedean_cuboctahedron_verts[8],
  Archimedean_cuboctahedron_verts[9],
  Archimedean_cuboctahedron_verts[10],
  Archimedean_cuboctahedron_verts[11]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  20,
  <0, 1, 2>, 0,
  <0, 3, 4>, 0,
  <1, 6, 5>, 0,
  <2, 8, 7>, 0,
  <3, 7, 9>, 0,
  <4, 10, 6>, 0,
  <5, 11, 8>, 0,
  <9, 11, 10>, 0,
  <0, 2, 7>, 1,
  <0, 7, 3>, 1,
  <0, 4, 6>, 1,
  <0, 6, 1>, 1,
  <1, 5, 8>, 1,
  <1, 8, 2>, 1,
  <3, 9, 10>, 1,
  <3, 10, 4>, 1,
  <5, 6, 10>, 1,
  <5, 10, 11>, 1,
  <7, 8, 11>, 1,
  <7, 11, 9>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_cuboctahedron_verts[7];
 #local P1 = Archimedean_cuboctahedron_verts[8];
 #local P2 = Archimedean_cuboctahedron_verts[11];
 #local P3 = Archimedean_cuboctahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_cuboctahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_cuboctahedron_obj }
#end
#end

#macro Archimedean_cuboctahedron_faces2(OnPlane)
#local Archimedean_cuboctahedron_obj = mesh2 {
 vertex_vectors {
  12,
  Archimedean_cuboctahedron_verts[0],
  Archimedean_cuboctahedron_verts[1],
  Archimedean_cuboctahedron_verts[2],
  Archimedean_cuboctahedron_verts[3],
  Archimedean_cuboctahedron_verts[4],
  Archimedean_cuboctahedron_verts[5],
  Archimedean_cuboctahedron_verts[6],
  Archimedean_cuboctahedron_verts[7],
  Archimedean_cuboctahedron_verts[8],
  Archimedean_cuboctahedron_verts[9],
  Archimedean_cuboctahedron_verts[10],
  Archimedean_cuboctahedron_verts[11]
 }
 face_indices {
  20,
  <0, 1, 2>,
  <0, 3, 4>,
  <1, 6, 5>,
  <2, 8, 7>,
  <3, 7, 9>,
  <4, 10, 6>,
  <5, 11, 8>,
  <9, 11, 10>,
  <0, 2, 7>,
  <0, 7, 3>,
  <0, 4, 6>,
  <0, 6, 1>,
  <1, 5, 8>,
  <1, 8, 2>,
  <3, 9, 10>,
  <3, 10, 4>,
  <5, 6, 10>,
  <5, 10, 11>,
  <7, 8, 11>,
  <7, 11, 9>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_cuboctahedron_verts[7];
 #local P1 = Archimedean_cuboctahedron_verts[8];
 #local P2 = Archimedean_cuboctahedron_verts[11];
 #local P3 = Archimedean_cuboctahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_cuboctahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_cuboctahedron_obj }
#end
#end

#macro Archimedean_cuboctahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_cuboctahedron_verts[0], RadVer }
  sphere { Archimedean_cuboctahedron_verts[1], RadVer }
  sphere { Archimedean_cuboctahedron_verts[2], RadVer }
  sphere { Archimedean_cuboctahedron_verts[3], RadVer }
  sphere { Archimedean_cuboctahedron_verts[4], RadVer }
  sphere { Archimedean_cuboctahedron_verts[5], RadVer }
  sphere { Archimedean_cuboctahedron_verts[6], RadVer }
  sphere { Archimedean_cuboctahedron_verts[7], RadVer }
  sphere { Archimedean_cuboctahedron_verts[8], RadVer }
  sphere { Archimedean_cuboctahedron_verts[9], RadVer }
  sphere { Archimedean_cuboctahedron_verts[10], RadVer }
  sphere { Archimedean_cuboctahedron_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_cuboctahedron_verts[0], Archimedean_cuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[1], Archimedean_cuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[2], Archimedean_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[0], Archimedean_cuboctahedron_verts[3], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[3], Archimedean_cuboctahedron_verts[4], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[4], Archimedean_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[1], Archimedean_cuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[6], Archimedean_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[5], Archimedean_cuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[2], Archimedean_cuboctahedron_verts[8], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[8], Archimedean_cuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[7], Archimedean_cuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[3], Archimedean_cuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[7], Archimedean_cuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[9], Archimedean_cuboctahedron_verts[3], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[4], Archimedean_cuboctahedron_verts[10], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[10], Archimedean_cuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[6], Archimedean_cuboctahedron_verts[4], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[5], Archimedean_cuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[11], Archimedean_cuboctahedron_verts[8], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[8], Archimedean_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[9], Archimedean_cuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[11], Archimedean_cuboctahedron_verts[10], RadEdg }
  cylinder { Archimedean_cuboctahedron_verts[10], Archimedean_cuboctahedron_verts[9], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_cuboctahedron_verts[7];
 #local P1 = Archimedean_cuboctahedron_verts[8];
 #local P2 = Archimedean_cuboctahedron_verts[11];
 #local P3 = Archimedean_cuboctahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_truncated_cube_verts = array[24]
{
<0, 0, 1.042011>,
<0.5621693, 0, 0.8773552>,
<-0.4798415, 0.2928932, 0.8773552>,
<0.2569714, -0.5, 0.8773552>,
<0.8773552, 0.2928932, 0.4798415>,
<-0.9014684, 0.2071068, 0.4798415>,
<-0.5962706, 0.7071068, 0.4798415>,
<0.1405423, -0.9142136, 0.4798415>,
<1.017898, 0.2071068, -0.08232778>,
<0.7609261, 0.7071068, 0.08232778>,
<-1.017898, -0.2071068, 0.08232778>,
<-0.2810846, 1., 0.08232778>,
<-0.2810846, -1., 0.08232778>,
<0.2810846, -1., -0.08232778>,
<0.9014684, -0.2071068, -0.4798415>,
<0.2810846, 1., -0.08232778>,
<-0.7609261, -0.7071068, -0.08232778>,
<-0.8773552, -0.2928932, -0.4798415>,
<-0.1405423, 0.9142136, -0.4798415>,
<0.5962706, -0.7071068, -0.4798415>,
<0.4798415, -0.2928932, -0.8773552>,
<-0.5621693, 0, -0.8773552>,
<-0.2569714, 0.5, -0.8773552>,
<0, 0, -1.042011>
}
#local P0 = Archimedean_truncated_cube_verts[12];
#local P1 = Archimedean_truncated_cube_verts[16];
#local P2 = Archimedean_truncated_cube_verts[17];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 24)
 #declare Archimedean_truncated_cube_verts[Num] = vtransform(Archimedean_truncated_cube_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_truncated_cube_faces(Tex3, Tex8, OnPlane)
#local Archimedean_truncated_cube_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_truncated_cube_verts[0],
  Archimedean_truncated_cube_verts[1],
  Archimedean_truncated_cube_verts[2],
  Archimedean_truncated_cube_verts[3],
  Archimedean_truncated_cube_verts[4],
  Archimedean_truncated_cube_verts[5],
  Archimedean_truncated_cube_verts[6],
  Archimedean_truncated_cube_verts[7],
  Archimedean_truncated_cube_verts[8],
  Archimedean_truncated_cube_verts[9],
  Archimedean_truncated_cube_verts[10],
  Archimedean_truncated_cube_verts[11],
  Archimedean_truncated_cube_verts[12],
  Archimedean_truncated_cube_verts[13],
  Archimedean_truncated_cube_verts[14],
  Archimedean_truncated_cube_verts[15],
  Archimedean_truncated_cube_verts[16],
  Archimedean_truncated_cube_verts[17],
  Archimedean_truncated_cube_verts[18],
  Archimedean_truncated_cube_verts[19],
  Archimedean_truncated_cube_verts[20],
  Archimedean_truncated_cube_verts[21],
  Archimedean_truncated_cube_verts[22],
  Archimedean_truncated_cube_verts[23]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex8 }
 }
 face_indices {
  44,
  <0, 3, 1>, 0,
  <2, 6, 5>, 0,
  <4, 8, 9>, 0,
  <7, 12, 13>, 0,
  <10, 17, 16>, 0,
  <11, 15, 18>, 0,
  <14, 19, 20>, 0,
  <21, 22, 23>, 0,
  <0, 1, 4>, 1,
  <0, 4, 9>, 1,
  <0, 9, 15>, 1,
  <0, 15, 11>, 1,
  <0, 11, 6>, 1,
  <0, 6, 2>, 1,
  <0, 2, 5>, 1,
  <0, 5, 10>, 1,
  <0, 10, 16>, 1,
  <0, 16, 12>, 1,
  <0, 12, 7>, 1,
  <0, 7, 3>, 1,
  <1, 3, 7>, 1,
  <1, 7, 13>, 1,
  <1, 13, 19>, 1,
  <1, 19, 14>, 1,
  <1, 14, 8>, 1,
  <1, 8, 4>, 1,
  <5, 6, 11>, 1,
  <5, 11, 18>, 1,
  <5, 18, 22>, 1,
  <5, 22, 21>, 1,
  <5, 21, 17>, 1,
  <5, 17, 10>, 1,
  <8, 14, 20>, 1,
  <8, 20, 23>, 1,
  <8, 23, 22>, 1,
  <8, 22, 18>, 1,
  <8, 18, 15>, 1,
  <8, 15, 9>, 1,
  <12, 16, 17>, 1,
  <12, 17, 21>, 1,
  <12, 21, 23>, 1,
  <12, 23, 20>, 1,
  <12, 20, 19>, 1,
  <12, 19, 13>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_cube_verts[12];
 #local P1 = Archimedean_truncated_cube_verts[16];
 #local P2 = Archimedean_truncated_cube_verts[17];
 #local P3 = Archimedean_truncated_cube_verts[21];
 #local P4 = Archimedean_truncated_cube_verts[23];
 #local P5 = Archimedean_truncated_cube_verts[20];
 #local P6 = Archimedean_truncated_cube_verts[19];
 #local P7 = Archimedean_truncated_cube_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_cube_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_cube_obj }
#end
#end

#macro Archimedean_truncated_cube_faces2(OnPlane)
#local Archimedean_truncated_cube_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_truncated_cube_verts[0],
  Archimedean_truncated_cube_verts[1],
  Archimedean_truncated_cube_verts[2],
  Archimedean_truncated_cube_verts[3],
  Archimedean_truncated_cube_verts[4],
  Archimedean_truncated_cube_verts[5],
  Archimedean_truncated_cube_verts[6],
  Archimedean_truncated_cube_verts[7],
  Archimedean_truncated_cube_verts[8],
  Archimedean_truncated_cube_verts[9],
  Archimedean_truncated_cube_verts[10],
  Archimedean_truncated_cube_verts[11],
  Archimedean_truncated_cube_verts[12],
  Archimedean_truncated_cube_verts[13],
  Archimedean_truncated_cube_verts[14],
  Archimedean_truncated_cube_verts[15],
  Archimedean_truncated_cube_verts[16],
  Archimedean_truncated_cube_verts[17],
  Archimedean_truncated_cube_verts[18],
  Archimedean_truncated_cube_verts[19],
  Archimedean_truncated_cube_verts[20],
  Archimedean_truncated_cube_verts[21],
  Archimedean_truncated_cube_verts[22],
  Archimedean_truncated_cube_verts[23]
 }
 face_indices {
  44,
  <0, 3, 1>,
  <2, 6, 5>,
  <4, 8, 9>,
  <7, 12, 13>,
  <10, 17, 16>,
  <11, 15, 18>,
  <14, 19, 20>,
  <21, 22, 23>,
  <0, 1, 4>,
  <0, 4, 9>,
  <0, 9, 15>,
  <0, 15, 11>,
  <0, 11, 6>,
  <0, 6, 2>,
  <0, 2, 5>,
  <0, 5, 10>,
  <0, 10, 16>,
  <0, 16, 12>,
  <0, 12, 7>,
  <0, 7, 3>,
  <1, 3, 7>,
  <1, 7, 13>,
  <1, 13, 19>,
  <1, 19, 14>,
  <1, 14, 8>,
  <1, 8, 4>,
  <5, 6, 11>,
  <5, 11, 18>,
  <5, 18, 22>,
  <5, 22, 21>,
  <5, 21, 17>,
  <5, 17, 10>,
  <8, 14, 20>,
  <8, 20, 23>,
  <8, 23, 22>,
  <8, 22, 18>,
  <8, 18, 15>,
  <8, 15, 9>,
  <12, 16, 17>,
  <12, 17, 21>,
  <12, 21, 23>,
  <12, 23, 20>,
  <12, 20, 19>,
  <12, 19, 13>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_cube_verts[12];
 #local P1 = Archimedean_truncated_cube_verts[16];
 #local P2 = Archimedean_truncated_cube_verts[17];
 #local P3 = Archimedean_truncated_cube_verts[21];
 #local P4 = Archimedean_truncated_cube_verts[23];
 #local P5 = Archimedean_truncated_cube_verts[20];
 #local P6 = Archimedean_truncated_cube_verts[19];
 #local P7 = Archimedean_truncated_cube_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_cube_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_cube_obj }
#end
#end

#macro Archimedean_truncated_cube_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_truncated_cube_verts[0], RadVer }
  sphere { Archimedean_truncated_cube_verts[1], RadVer }
  sphere { Archimedean_truncated_cube_verts[2], RadVer }
  sphere { Archimedean_truncated_cube_verts[3], RadVer }
  sphere { Archimedean_truncated_cube_verts[4], RadVer }
  sphere { Archimedean_truncated_cube_verts[5], RadVer }
  sphere { Archimedean_truncated_cube_verts[6], RadVer }
  sphere { Archimedean_truncated_cube_verts[7], RadVer }
  sphere { Archimedean_truncated_cube_verts[8], RadVer }
  sphere { Archimedean_truncated_cube_verts[9], RadVer }
  sphere { Archimedean_truncated_cube_verts[10], RadVer }
  sphere { Archimedean_truncated_cube_verts[11], RadVer }
  sphere { Archimedean_truncated_cube_verts[12], RadVer }
  sphere { Archimedean_truncated_cube_verts[13], RadVer }
  sphere { Archimedean_truncated_cube_verts[14], RadVer }
  sphere { Archimedean_truncated_cube_verts[15], RadVer }
  sphere { Archimedean_truncated_cube_verts[16], RadVer }
  sphere { Archimedean_truncated_cube_verts[17], RadVer }
  sphere { Archimedean_truncated_cube_verts[18], RadVer }
  sphere { Archimedean_truncated_cube_verts[19], RadVer }
  sphere { Archimedean_truncated_cube_verts[20], RadVer }
  sphere { Archimedean_truncated_cube_verts[21], RadVer }
  sphere { Archimedean_truncated_cube_verts[22], RadVer }
  sphere { Archimedean_truncated_cube_verts[23], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_truncated_cube_verts[0], Archimedean_truncated_cube_verts[3], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[3], Archimedean_truncated_cube_verts[1], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[1], Archimedean_truncated_cube_verts[0], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[2], Archimedean_truncated_cube_verts[6], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[6], Archimedean_truncated_cube_verts[5], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[5], Archimedean_truncated_cube_verts[2], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[4], Archimedean_truncated_cube_verts[8], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[8], Archimedean_truncated_cube_verts[9], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[9], Archimedean_truncated_cube_verts[4], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[7], Archimedean_truncated_cube_verts[12], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[12], Archimedean_truncated_cube_verts[13], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[13], Archimedean_truncated_cube_verts[7], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[10], Archimedean_truncated_cube_verts[17], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[17], Archimedean_truncated_cube_verts[16], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[16], Archimedean_truncated_cube_verts[10], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[11], Archimedean_truncated_cube_verts[15], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[15], Archimedean_truncated_cube_verts[18], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[18], Archimedean_truncated_cube_verts[11], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[14], Archimedean_truncated_cube_verts[19], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[19], Archimedean_truncated_cube_verts[20], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[20], Archimedean_truncated_cube_verts[14], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[21], Archimedean_truncated_cube_verts[22], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[22], Archimedean_truncated_cube_verts[23], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[23], Archimedean_truncated_cube_verts[21], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[1], Archimedean_truncated_cube_verts[4], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[9], Archimedean_truncated_cube_verts[15], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[11], Archimedean_truncated_cube_verts[6], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[2], Archimedean_truncated_cube_verts[0], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[5], Archimedean_truncated_cube_verts[10], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[16], Archimedean_truncated_cube_verts[12], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[7], Archimedean_truncated_cube_verts[3], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[13], Archimedean_truncated_cube_verts[19], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[14], Archimedean_truncated_cube_verts[8], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[18], Archimedean_truncated_cube_verts[22], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[21], Archimedean_truncated_cube_verts[17], RadEdg }
  cylinder { Archimedean_truncated_cube_verts[20], Archimedean_truncated_cube_verts[23], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_truncated_cube_verts[12];
 #local P1 = Archimedean_truncated_cube_verts[16];
 #local P2 = Archimedean_truncated_cube_verts[17];
 #local P3 = Archimedean_truncated_cube_verts[21];
 #local P4 = Archimedean_truncated_cube_verts[23];
 #local P5 = Archimedean_truncated_cube_verts[20];
 #local P6 = Archimedean_truncated_cube_verts[19];
 #local P7 = Archimedean_truncated_cube_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_truncated_octahedron_verts = array[24]
{
<0, 0, 1.054093>,
<0.6324555, 0, 0.843274>,
<-0.421637, 0.4714045, 0.843274>,
<-0.07027284, -0.6285394, 0.843274>,
<0.843274, 0.4714045, 0.421637>,
<0.5621827, -0.6285394, 0.6324555>,
<-0.9135469, 0.3142697, 0.421637>,
<-0.2108185, 0.942809, 0.421637>,
<-0.5621827, -0.7856742, 0.421637>,
<0.9838197, 0.3142697, -0.2108185>,
<0.421637, 0.942809, 0.2108185>,
<0.7027284, -0.7856742, 0>,
<-0.7027284, 0.7856742, 0>,
<-0.9838197, -0.3142697, 0.2108185>,
<-0.421637, -0.942809, -0.2108185>,
<0.5621827, 0.7856742, -0.421637>,
<0.9135469, -0.3142697, -0.421637>,
<0.2108185, -0.942809, -0.421637>,
<-0.5621827, 0.6285394, -0.6324555>,
<-0.843274, -0.4714045, -0.421637>,
<0.07027284, 0.6285394, -0.843274>,
<0.421637, -0.4714045, -0.843274>,
<-0.6324555, 0, -0.843274>,
<0, 0, -1.054093>
}
#local P0 = Archimedean_truncated_octahedron_verts[0];
#local P1 = Archimedean_truncated_octahedron_verts[1];
#local P2 = Archimedean_truncated_octahedron_verts[3];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 24)
 #declare Archimedean_truncated_octahedron_verts[Num] = vtransform(Archimedean_truncated_octahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_truncated_octahedron_faces(Tex4, Tex6, OnPlane)
#local Archimedean_truncated_octahedron_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_truncated_octahedron_verts[0],
  Archimedean_truncated_octahedron_verts[1],
  Archimedean_truncated_octahedron_verts[2],
  Archimedean_truncated_octahedron_verts[3],
  Archimedean_truncated_octahedron_verts[4],
  Archimedean_truncated_octahedron_verts[5],
  Archimedean_truncated_octahedron_verts[6],
  Archimedean_truncated_octahedron_verts[7],
  Archimedean_truncated_octahedron_verts[8],
  Archimedean_truncated_octahedron_verts[9],
  Archimedean_truncated_octahedron_verts[10],
  Archimedean_truncated_octahedron_verts[11],
  Archimedean_truncated_octahedron_verts[12],
  Archimedean_truncated_octahedron_verts[13],
  Archimedean_truncated_octahedron_verts[14],
  Archimedean_truncated_octahedron_verts[15],
  Archimedean_truncated_octahedron_verts[16],
  Archimedean_truncated_octahedron_verts[17],
  Archimedean_truncated_octahedron_verts[18],
  Archimedean_truncated_octahedron_verts[19],
  Archimedean_truncated_octahedron_verts[20],
  Archimedean_truncated_octahedron_verts[21],
  Archimedean_truncated_octahedron_verts[22],
  Archimedean_truncated_octahedron_verts[23]
 }
 texture_list {
  2,
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  44,
  <0, 3, 5>, 0,
  <0, 5, 1>, 0,
  <2, 7, 12>, 0,
  <2, 12, 6>, 0,
  <4, 9, 15>, 0,
  <4, 15, 10>, 0,
  <8, 13, 19>, 0,
  <8, 19, 14>, 0,
  <11, 17, 21>, 0,
  <11, 21, 16>, 0,
  <18, 20, 23>, 0,
  <18, 23, 22>, 0,
  <0, 1, 4>, 1,
  <0, 4, 10>, 1,
  <0, 10, 7>, 1,
  <0, 7, 2>, 1,
  <0, 2, 6>, 1,
  <0, 6, 13>, 1,
  <0, 13, 8>, 1,
  <0, 8, 3>, 1,
  <1, 5, 11>, 1,
  <1, 11, 16>, 1,
  <1, 16, 9>, 1,
  <1, 9, 4>, 1,
  <3, 8, 14>, 1,
  <3, 14, 17>, 1,
  <3, 17, 11>, 1,
  <3, 11, 5>, 1,
  <6, 12, 18>, 1,
  <6, 18, 22>, 1,
  <6, 22, 19>, 1,
  <6, 19, 13>, 1,
  <7, 10, 15>, 1,
  <7, 15, 20>, 1,
  <7, 20, 18>, 1,
  <7, 18, 12>, 1,
  <9, 16, 21>, 1,
  <9, 21, 23>, 1,
  <9, 23, 20>, 1,
  <9, 20, 15>, 1,
  <14, 19, 22>, 1,
  <14, 22, 23>, 1,
  <14, 23, 21>, 1,
  <14, 21, 17>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_octahedron_verts[14];
 #local P1 = Archimedean_truncated_octahedron_verts[19];
 #local P2 = Archimedean_truncated_octahedron_verts[22];
 #local P3 = Archimedean_truncated_octahedron_verts[23];
 #local P4 = Archimedean_truncated_octahedron_verts[21];
 #local P5 = Archimedean_truncated_octahedron_verts[17];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_octahedron_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_octahedron_obj }
#end
#end

#macro Archimedean_truncated_octahedron_faces2(OnPlane)
#local Archimedean_truncated_octahedron_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_truncated_octahedron_verts[0],
  Archimedean_truncated_octahedron_verts[1],
  Archimedean_truncated_octahedron_verts[2],
  Archimedean_truncated_octahedron_verts[3],
  Archimedean_truncated_octahedron_verts[4],
  Archimedean_truncated_octahedron_verts[5],
  Archimedean_truncated_octahedron_verts[6],
  Archimedean_truncated_octahedron_verts[7],
  Archimedean_truncated_octahedron_verts[8],
  Archimedean_truncated_octahedron_verts[9],
  Archimedean_truncated_octahedron_verts[10],
  Archimedean_truncated_octahedron_verts[11],
  Archimedean_truncated_octahedron_verts[12],
  Archimedean_truncated_octahedron_verts[13],
  Archimedean_truncated_octahedron_verts[14],
  Archimedean_truncated_octahedron_verts[15],
  Archimedean_truncated_octahedron_verts[16],
  Archimedean_truncated_octahedron_verts[17],
  Archimedean_truncated_octahedron_verts[18],
  Archimedean_truncated_octahedron_verts[19],
  Archimedean_truncated_octahedron_verts[20],
  Archimedean_truncated_octahedron_verts[21],
  Archimedean_truncated_octahedron_verts[22],
  Archimedean_truncated_octahedron_verts[23]
 }
 face_indices {
  44,
  <0, 3, 5>,
  <0, 5, 1>,
  <2, 7, 12>,
  <2, 12, 6>,
  <4, 9, 15>,
  <4, 15, 10>,
  <8, 13, 19>,
  <8, 19, 14>,
  <11, 17, 21>,
  <11, 21, 16>,
  <18, 20, 23>,
  <18, 23, 22>,
  <0, 1, 4>,
  <0, 4, 10>,
  <0, 10, 7>,
  <0, 7, 2>,
  <0, 2, 6>,
  <0, 6, 13>,
  <0, 13, 8>,
  <0, 8, 3>,
  <1, 5, 11>,
  <1, 11, 16>,
  <1, 16, 9>,
  <1, 9, 4>,
  <3, 8, 14>,
  <3, 14, 17>,
  <3, 17, 11>,
  <3, 11, 5>,
  <6, 12, 18>,
  <6, 18, 22>,
  <6, 22, 19>,
  <6, 19, 13>,
  <7, 10, 15>,
  <7, 15, 20>,
  <7, 20, 18>,
  <7, 18, 12>,
  <9, 16, 21>,
  <9, 21, 23>,
  <9, 23, 20>,
  <9, 20, 15>,
  <14, 19, 22>,
  <14, 22, 23>,
  <14, 23, 21>,
  <14, 21, 17>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_octahedron_verts[14];
 #local P1 = Archimedean_truncated_octahedron_verts[19];
 #local P2 = Archimedean_truncated_octahedron_verts[22];
 #local P3 = Archimedean_truncated_octahedron_verts[23];
 #local P4 = Archimedean_truncated_octahedron_verts[21];
 #local P5 = Archimedean_truncated_octahedron_verts[17];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_octahedron_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_octahedron_obj }
#end
#end

#macro Archimedean_truncated_octahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_truncated_octahedron_verts[0], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[1], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[2], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[3], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[4], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[5], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[6], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[7], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[8], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[9], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[10], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[11], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[12], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[13], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[14], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[15], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[16], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[17], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[18], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[19], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[20], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[21], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[22], RadVer }
  sphere { Archimedean_truncated_octahedron_verts[23], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_truncated_octahedron_verts[0], Archimedean_truncated_octahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[3], Archimedean_truncated_octahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[5], Archimedean_truncated_octahedron_verts[1], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[1], Archimedean_truncated_octahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[2], Archimedean_truncated_octahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[7], Archimedean_truncated_octahedron_verts[12], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[12], Archimedean_truncated_octahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[6], Archimedean_truncated_octahedron_verts[2], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[4], Archimedean_truncated_octahedron_verts[9], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[9], Archimedean_truncated_octahedron_verts[15], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[15], Archimedean_truncated_octahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[10], Archimedean_truncated_octahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[8], Archimedean_truncated_octahedron_verts[13], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[13], Archimedean_truncated_octahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[19], Archimedean_truncated_octahedron_verts[14], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[14], Archimedean_truncated_octahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[11], Archimedean_truncated_octahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[17], Archimedean_truncated_octahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[21], Archimedean_truncated_octahedron_verts[16], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[16], Archimedean_truncated_octahedron_verts[11], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[18], Archimedean_truncated_octahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[20], Archimedean_truncated_octahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[23], Archimedean_truncated_octahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[22], Archimedean_truncated_octahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[1], Archimedean_truncated_octahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[10], Archimedean_truncated_octahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[2], Archimedean_truncated_octahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[6], Archimedean_truncated_octahedron_verts[13], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[8], Archimedean_truncated_octahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[5], Archimedean_truncated_octahedron_verts[11], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[16], Archimedean_truncated_octahedron_verts[9], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[14], Archimedean_truncated_octahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[12], Archimedean_truncated_octahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[22], Archimedean_truncated_octahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[15], Archimedean_truncated_octahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_octahedron_verts[21], Archimedean_truncated_octahedron_verts[23], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_truncated_octahedron_verts[14];
 #local P1 = Archimedean_truncated_octahedron_verts[19];
 #local P2 = Archimedean_truncated_octahedron_verts[22];
 #local P3 = Archimedean_truncated_octahedron_verts[23];
 #local P4 = Archimedean_truncated_octahedron_verts[21];
 #local P5 = Archimedean_truncated_octahedron_verts[17];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_rhombicuboctahedron_verts = array[24]
{
<0, 0, 1.070722>,
<0.7148135, 0, 0.7971752>,
<-0.104682, 0.7071068, 0.7971752>,
<-0.6841528, 0.2071068, 0.7971752>,
<-0.104682, -0.7071068, 0.7971752>,
<0.6101315, 0.7071068, 0.5236279>,
<1.04156, 0.2071068, 0.1367736>,
<0.6101315, -0.7071068, 0.5236279>,
<-0.3574067, 1., 0.1367736>,
<-0.7888348, -0.5, 0.5236279>,
<-0.9368776, 0.5, 0.1367736>,
<-0.3574067, -1., 0.1367736>,
<0.3574067, 1., -0.1367736>,
<0.9368776, -0.5, -0.1367736>,
<0.7888348, 0.5, -0.5236279>,
<0.3574067, -1., -0.1367736>,
<-0.6101315, 0.7071068, -0.5236279>,
<-1.04156, -0.2071068, -0.1367736>,
<-0.6101315, -0.7071068, -0.5236279>,
<0.104682, 0.7071068, -0.7971752>,
<0.6841528, -0.2071068, -0.7971752>,
<0.104682, -0.7071068, -0.7971752>,
<-0.7148135, 0, -0.7971752>,
<0, 0, -1.070722>
}
#local P0 = Archimedean_rhombicuboctahedron_verts[11];
#local P1 = Archimedean_rhombicuboctahedron_verts[15];
#local P2 = Archimedean_rhombicuboctahedron_verts[18];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 24)
 #declare Archimedean_rhombicuboctahedron_verts[Num] = vtransform(Archimedean_rhombicuboctahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_rhombicuboctahedron_faces(Tex3, Tex4, OnPlane)
#local Archimedean_rhombicuboctahedron_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_rhombicuboctahedron_verts[0],
  Archimedean_rhombicuboctahedron_verts[1],
  Archimedean_rhombicuboctahedron_verts[2],
  Archimedean_rhombicuboctahedron_verts[3],
  Archimedean_rhombicuboctahedron_verts[4],
  Archimedean_rhombicuboctahedron_verts[5],
  Archimedean_rhombicuboctahedron_verts[6],
  Archimedean_rhombicuboctahedron_verts[7],
  Archimedean_rhombicuboctahedron_verts[8],
  Archimedean_rhombicuboctahedron_verts[9],
  Archimedean_rhombicuboctahedron_verts[10],
  Archimedean_rhombicuboctahedron_verts[11],
  Archimedean_rhombicuboctahedron_verts[12],
  Archimedean_rhombicuboctahedron_verts[13],
  Archimedean_rhombicuboctahedron_verts[14],
  Archimedean_rhombicuboctahedron_verts[15],
  Archimedean_rhombicuboctahedron_verts[16],
  Archimedean_rhombicuboctahedron_verts[17],
  Archimedean_rhombicuboctahedron_verts[18],
  Archimedean_rhombicuboctahedron_verts[19],
  Archimedean_rhombicuboctahedron_verts[20],
  Archimedean_rhombicuboctahedron_verts[21],
  Archimedean_rhombicuboctahedron_verts[22],
  Archimedean_rhombicuboctahedron_verts[23]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  44,
  <0, 2, 3>, 0,
  <1, 6, 5>, 0,
  <4, 9, 11>, 0,
  <7, 15, 13>, 0,
  <8, 16, 10>, 0,
  <12, 14, 19>, 0,
  <17, 22, 18>, 0,
  <20, 21, 23>, 0,
  <0, 1, 5>, 1,
  <0, 5, 2>, 1,
  <0, 3, 9>, 1,
  <0, 9, 4>, 1,
  <0, 4, 7>, 1,
  <0, 7, 1>, 1,
  <1, 7, 13>, 1,
  <1, 13, 6>, 1,
  <2, 5, 12>, 1,
  <2, 12, 8>, 1,
  <2, 8, 10>, 1,
  <2, 10, 3>, 1,
  <3, 10, 17>, 1,
  <3, 17, 9>, 1,
  <4, 11, 15>, 1,
  <4, 15, 7>, 1,
  <5, 6, 14>, 1,
  <5, 14, 12>, 1,
  <6, 13, 20>, 1,
  <6, 20, 14>, 1,
  <8, 12, 19>, 1,
  <8, 19, 16>, 1,
  <9, 17, 18>, 1,
  <9, 18, 11>, 1,
  <10, 16, 22>, 1,
  <10, 22, 17>, 1,
  <11, 18, 21>, 1,
  <11, 21, 15>, 1,
  <13, 15, 21>, 1,
  <13, 21, 20>, 1,
  <14, 20, 23>, 1,
  <14, 23, 19>, 1,
  <16, 19, 23>, 1,
  <16, 23, 22>, 1,
  <18, 22, 23>, 1,
  <18, 23, 21>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_rhombicuboctahedron_verts[11];
 #local P1 = Archimedean_rhombicuboctahedron_verts[18];
 #local P2 = Archimedean_rhombicuboctahedron_verts[15];
 #local P3 = Archimedean_rhombicuboctahedron_verts[21];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_rhombicuboctahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_rhombicuboctahedron_obj }
#end
#end

#macro Archimedean_rhombicuboctahedron_faces2(OnPlane)
#local Archimedean_rhombicuboctahedron_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_rhombicuboctahedron_verts[0],
  Archimedean_rhombicuboctahedron_verts[1],
  Archimedean_rhombicuboctahedron_verts[2],
  Archimedean_rhombicuboctahedron_verts[3],
  Archimedean_rhombicuboctahedron_verts[4],
  Archimedean_rhombicuboctahedron_verts[5],
  Archimedean_rhombicuboctahedron_verts[6],
  Archimedean_rhombicuboctahedron_verts[7],
  Archimedean_rhombicuboctahedron_verts[8],
  Archimedean_rhombicuboctahedron_verts[9],
  Archimedean_rhombicuboctahedron_verts[10],
  Archimedean_rhombicuboctahedron_verts[11],
  Archimedean_rhombicuboctahedron_verts[12],
  Archimedean_rhombicuboctahedron_verts[13],
  Archimedean_rhombicuboctahedron_verts[14],
  Archimedean_rhombicuboctahedron_verts[15],
  Archimedean_rhombicuboctahedron_verts[16],
  Archimedean_rhombicuboctahedron_verts[17],
  Archimedean_rhombicuboctahedron_verts[18],
  Archimedean_rhombicuboctahedron_verts[19],
  Archimedean_rhombicuboctahedron_verts[20],
  Archimedean_rhombicuboctahedron_verts[21],
  Archimedean_rhombicuboctahedron_verts[22],
  Archimedean_rhombicuboctahedron_verts[23]
 }
 face_indices {
  44,
  <0, 2, 3>,
  <1, 6, 5>,
  <4, 9, 11>,
  <7, 15, 13>,
  <8, 16, 10>,
  <12, 14, 19>,
  <17, 22, 18>,
  <20, 21, 23>,
  <0, 1, 5>,
  <0, 5, 2>,
  <0, 3, 9>,
  <0, 9, 4>,
  <0, 4, 7>,
  <0, 7, 1>,
  <1, 7, 13>,
  <1, 13, 6>,
  <2, 5, 12>,
  <2, 12, 8>,
  <2, 8, 10>,
  <2, 10, 3>,
  <3, 10, 17>,
  <3, 17, 9>,
  <4, 11, 15>,
  <4, 15, 7>,
  <5, 6, 14>,
  <5, 14, 12>,
  <6, 13, 20>,
  <6, 20, 14>,
  <8, 12, 19>,
  <8, 19, 16>,
  <9, 17, 18>,
  <9, 18, 11>,
  <10, 16, 22>,
  <10, 22, 17>,
  <11, 18, 21>,
  <11, 21, 15>,
  <13, 15, 21>,
  <13, 21, 20>,
  <14, 20, 23>,
  <14, 23, 19>,
  <16, 19, 23>,
  <16, 23, 22>,
  <18, 22, 23>,
  <18, 23, 21>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_rhombicuboctahedron_verts[11];
 #local P1 = Archimedean_rhombicuboctahedron_verts[18];
 #local P2 = Archimedean_rhombicuboctahedron_verts[15];
 #local P3 = Archimedean_rhombicuboctahedron_verts[21];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_rhombicuboctahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_rhombicuboctahedron_obj }
#end
#end

#macro Archimedean_rhombicuboctahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_rhombicuboctahedron_verts[0], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[1], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[2], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[3], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[4], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[5], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[6], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[7], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[8], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[9], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[10], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[11], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[12], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[13], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[14], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[15], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[16], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[17], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[18], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[19], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[20], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[21], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[22], RadVer }
  sphere { Archimedean_rhombicuboctahedron_verts[23], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_rhombicuboctahedron_verts[0], Archimedean_rhombicuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[2], Archimedean_rhombicuboctahedron_verts[3], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[3], Archimedean_rhombicuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[1], Archimedean_rhombicuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[6], Archimedean_rhombicuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[5], Archimedean_rhombicuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[4], Archimedean_rhombicuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[9], Archimedean_rhombicuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[11], Archimedean_rhombicuboctahedron_verts[4], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[7], Archimedean_rhombicuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[15], Archimedean_rhombicuboctahedron_verts[13], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[13], Archimedean_rhombicuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[8], Archimedean_rhombicuboctahedron_verts[16], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[16], Archimedean_rhombicuboctahedron_verts[10], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[10], Archimedean_rhombicuboctahedron_verts[8], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[12], Archimedean_rhombicuboctahedron_verts[14], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[14], Archimedean_rhombicuboctahedron_verts[19], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[19], Archimedean_rhombicuboctahedron_verts[12], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[17], Archimedean_rhombicuboctahedron_verts[22], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[22], Archimedean_rhombicuboctahedron_verts[18], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[18], Archimedean_rhombicuboctahedron_verts[17], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[20], Archimedean_rhombicuboctahedron_verts[21], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[21], Archimedean_rhombicuboctahedron_verts[23], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[23], Archimedean_rhombicuboctahedron_verts[20], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[0], Archimedean_rhombicuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[5], Archimedean_rhombicuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[3], Archimedean_rhombicuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[4], Archimedean_rhombicuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[4], Archimedean_rhombicuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[7], Archimedean_rhombicuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[13], Archimedean_rhombicuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[5], Archimedean_rhombicuboctahedron_verts[12], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[12], Archimedean_rhombicuboctahedron_verts[8], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[8], Archimedean_rhombicuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[10], Archimedean_rhombicuboctahedron_verts[3], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[10], Archimedean_rhombicuboctahedron_verts[17], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[17], Archimedean_rhombicuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[11], Archimedean_rhombicuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[6], Archimedean_rhombicuboctahedron_verts[14], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[13], Archimedean_rhombicuboctahedron_verts[20], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[20], Archimedean_rhombicuboctahedron_verts[14], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[19], Archimedean_rhombicuboctahedron_verts[16], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[18], Archimedean_rhombicuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[16], Archimedean_rhombicuboctahedron_verts[22], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[18], Archimedean_rhombicuboctahedron_verts[21], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[21], Archimedean_rhombicuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[23], Archimedean_rhombicuboctahedron_verts[19], RadEdg }
  cylinder { Archimedean_rhombicuboctahedron_verts[23], Archimedean_rhombicuboctahedron_verts[22], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_rhombicuboctahedron_verts[11];
 #local P1 = Archimedean_rhombicuboctahedron_verts[18];
 #local P2 = Archimedean_rhombicuboctahedron_verts[15];
 #local P3 = Archimedean_rhombicuboctahedron_verts[21];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_truncated_cuboctahedron_verts = array[48]
{
<0, 0, 1.024117>,
<0.4314788, 0, 0.928785>,
<-0.02106287, 0.4309644, 0.928785>,
<-0.3410582, -0.2642977, 0.928785>,
<0.4104159, 0.4309644, 0.833453>,
<0.7006238, -0.2642977, 0.6986333>,
<-0.3831839, 0.5976311, 0.7381211>,
<-0.3919084, -0.6380712, 0.6986333>,
<-0.7031792, -0.09763107, 0.7381211>,
<0.6584981, 0.5976311, 0.5079694>,
<0.6497736, -0.6380712, 0.4684816>,
<0.948706, -0.09763107, 0.3731496>,
<-0.4638216, 0.8333333, 0.3731496>,
<-0.7242421, 0.3333333, 0.6427891>,
<-0.7540295, -0.4714045, 0.5079694>,
<-0.1227634, -0.9023689, 0.4684816>,
<0.5778604, 0.8333333, 0.1429979>,
<0.9276431, 0.3333333, 0.2778177>,
<0.8978557, -0.4714045, 0.1429979>,
<0.3087154, -0.9023689, 0.3731496>,
<-0.8048797, 0.5690356, 0.2778177>,
<-0.2157394, 1., 0.04766598>,
<-0.8470055, -0.5690356, 0.08715377>,
<-0.2157394, -1., 0.04766598>
<0.8470055, 0.5690356, -0.08715377>,
<0.2157394, 1., -0.04766598>,
<0.8048797, -0.5690356, -0.2778177>,
<0.2157394, -1., -0.04766598>,
<-0.8978557, 0.4714045, -0.1429979>,
<-0.3087154, 0.9023689, -0.3731496>,
<-0.9276431, -0.3333333, -0.2778177>,
<-0.5778604, -0.8333333, -0.1429979>,
<0.7540295, 0.4714045, -0.5079694>,
<0.1227634, 0.9023689, -0.4684816>,
<0.7242421, -0.3333333, -0.6427891>,
<0.4638216, -0.8333333, -0.3731496>,
<-0.948706, 0.09763107, -0.3731496>,
<-0.6497736, 0.6380712, -0.4684816>,
<-0.6584981, -0.5976311, -0.5079694>,
<0.7031792, 0.09763107, -0.7381211>,
<0.3919084, 0.6380712, -0.6986333>,
<0.3831839, -0.5976311, -0.7381211>,
<-0.7006238, 0.2642977, -0.6986333>,
<-0.4104159, -0.4309644, -0.833453>,
<0.3410582, 0.2642977, -0.928785>,
<0.02106287, -0.4309644, -0.928785>,
<-0.4314788, 0, -0.928785>,
<0, 0, -1.024117>,
}
#local P0 = Archimedean_truncated_cuboctahedron_verts[29];
#local P1 = Archimedean_truncated_cuboctahedron_verts[33];
#local P2 = Archimedean_truncated_cuboctahedron_verts[40];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 48)
 #declare Archimedean_truncated_cuboctahedron_verts[Num] = vtransform(Archimedean_truncated_cuboctahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_truncated_cuboctahedron_faces(Tex4, Tex6, Tex8, OnPlane)
#local Archimedean_truncated_cuboctahedron_obj = mesh2 {
 vertex_vectors {
  48,
  Archimedean_truncated_cuboctahedron_verts[0],
  Archimedean_truncated_cuboctahedron_verts[1],
  Archimedean_truncated_cuboctahedron_verts[2],
  Archimedean_truncated_cuboctahedron_verts[3],
  Archimedean_truncated_cuboctahedron_verts[4],
  Archimedean_truncated_cuboctahedron_verts[5],
  Archimedean_truncated_cuboctahedron_verts[6],
  Archimedean_truncated_cuboctahedron_verts[7],
  Archimedean_truncated_cuboctahedron_verts[8],
  Archimedean_truncated_cuboctahedron_verts[9],
  Archimedean_truncated_cuboctahedron_verts[10],
  Archimedean_truncated_cuboctahedron_verts[11],
  Archimedean_truncated_cuboctahedron_verts[12],
  Archimedean_truncated_cuboctahedron_verts[13],
  Archimedean_truncated_cuboctahedron_verts[14],
  Archimedean_truncated_cuboctahedron_verts[15],
  Archimedean_truncated_cuboctahedron_verts[16],
  Archimedean_truncated_cuboctahedron_verts[17],
  Archimedean_truncated_cuboctahedron_verts[18],
  Archimedean_truncated_cuboctahedron_verts[19],
  Archimedean_truncated_cuboctahedron_verts[20],
  Archimedean_truncated_cuboctahedron_verts[21],
  Archimedean_truncated_cuboctahedron_verts[22],
  Archimedean_truncated_cuboctahedron_verts[23],
  Archimedean_truncated_cuboctahedron_verts[24],
  Archimedean_truncated_cuboctahedron_verts[25],
  Archimedean_truncated_cuboctahedron_verts[26],
  Archimedean_truncated_cuboctahedron_verts[27],
  Archimedean_truncated_cuboctahedron_verts[28],
  Archimedean_truncated_cuboctahedron_verts[29],
  Archimedean_truncated_cuboctahedron_verts[30],
  Archimedean_truncated_cuboctahedron_verts[31],
  Archimedean_truncated_cuboctahedron_verts[32],
  Archimedean_truncated_cuboctahedron_verts[33],
  Archimedean_truncated_cuboctahedron_verts[34],
  Archimedean_truncated_cuboctahedron_verts[35],
  Archimedean_truncated_cuboctahedron_verts[36],
  Archimedean_truncated_cuboctahedron_verts[37],
  Archimedean_truncated_cuboctahedron_verts[38],
  Archimedean_truncated_cuboctahedron_verts[39],
  Archimedean_truncated_cuboctahedron_verts[40],
  Archimedean_truncated_cuboctahedron_verts[41],
  Archimedean_truncated_cuboctahedron_verts[42],
  Archimedean_truncated_cuboctahedron_verts[43],
  Archimedean_truncated_cuboctahedron_verts[44],
  Archimedean_truncated_cuboctahedron_verts[45],
  Archimedean_truncated_cuboctahedron_verts[46],
  Archimedean_truncated_cuboctahedron_verts[47]
 }
 texture_list {
  3,
  texture { Tex4 },
  texture { Tex6 },
  texture { Tex8 }
 }
 face_indices {
  92,
  <0, 1, 4>, 0,
  <0, 4, 2>, 0,
  <3, 8, 14>, 0,
  <3, 14, 7>, 0,
  <5, 10, 18>, 0,
  <5, 18, 11>, 0,
  <6, 12, 20>, 0,
  <6, 20, 13>, 0,
  <9, 17, 24>, 0,
  <9, 24, 16>, 0,
  <15, 23, 27>, 0,
  <15, 27, 19>, 0,
  <21, 25, 33>, 0,
  <21, 33, 29>, 0,
  <22, 30, 38>, 0,
  <22, 38, 31>, 0,
  <26, 35, 41>, 0,
  <26, 41, 34>, 0,
  <28, 37, 42>, 0,
  <28, 42, 36>, 0,
  <32, 39, 44>, 0,
  <32, 44, 40>, 0,
  <43, 46, 47>, 0,
  <43, 47, 45>, 0,
  <0, 2, 6>, 1,
  <0, 6, 13>, 1,
  <0, 13, 8>, 1,
  <0, 8, 3>, 1,
  <1, 5, 11>, 1,
  <1, 11, 17>, 1,
  <1, 17, 9>, 1,
  <1, 9, 4>, 1,
  <7, 14, 22>, 1,
  <7, 22, 31>, 1,
  <7, 31, 23>, 1,
  <7, 23, 15>, 1,
  <10, 19, 27>, 1,
  <10, 27, 35>, 1,
  <10, 35, 26>, 1,
  <10, 26, 18>, 1,
  <12, 21, 29>, 1,
  <12, 29, 37>, 1,
  <12, 37, 28>, 1,
  <12, 28, 20>, 1,
  <16, 24, 32>, 1,
  <16, 32, 40>, 1,
  <16, 40, 33>, 1,
  <16, 33, 25>, 1,
  <30, 36, 42>, 1,
  <30, 42, 46>, 1,
  <30, 46, 43>, 1,
  <30, 43, 38>, 1,
  <34, 41, 45>, 1,
  <34, 45, 47>, 1,
  <34, 47, 44>, 1,
  <34, 44, 39>, 1,
  <0, 3, 7>, 2,
  <0, 7, 15>, 2,
  <0, 15, 19>, 2,
  <0, 19, 10>, 2,
  <0, 10, 5>, 2,
  <0, 5, 1>, 2,
  <2, 4, 9>, 2,
  <2, 9, 16>, 2,
  <2, 16, 25>, 2,
  <2, 25, 21>, 2,
  <2, 21, 12>, 2,
  <2, 12, 6>, 2,
  <8, 13, 20>, 2,
  <8, 20, 28>, 2,
  <8, 28, 36>, 2,
  <8, 36, 30>, 2,
  <8, 30, 22>, 2,
  <8, 22, 14>, 2,
  <11, 18, 26>, 2,
  <11, 26, 34>, 2,
  <11, 34, 39>, 2,
  <11, 39, 32>, 2,
  <11, 32, 24>, 2,
  <11, 24, 17>, 2,
  <23, 31, 38>, 2,
  <23, 38, 43>, 2,
  <23, 43, 45>, 2,
  <23, 45, 41>, 2,
  <23, 41, 35>, 2,
  <23, 35, 27>, 2,
  <29, 33, 40>, 2,
  <29, 40, 44>, 2,
  <29, 44, 47>, 2,
  <29, 47, 46>, 2,
  <29, 46, 42>, 2,
  <29, 42, 37>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_cuboctahedron_verts[29];
 #local P1 = Archimedean_truncated_cuboctahedron_verts[33];
 #local P2 = Archimedean_truncated_cuboctahedron_verts[40];
 #local P3 = Archimedean_truncated_cuboctahedron_verts[44];
 #local P4 = Archimedean_truncated_cuboctahedron_verts[47];
 #local P5 = Archimedean_truncated_cuboctahedron_verts[46];
 #local P6 = Archimedean_truncated_cuboctahedron_verts[42];
 #local P7 = Archimedean_truncated_cuboctahedron_verts[37];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_cuboctahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_cuboctahedron_obj }
#end
#end

#macro Archimedean_truncated_cuboctahedron_faces2(OnPlane)
#local Archimedean_truncated_cuboctahedron_obj = mesh2 {
 vertex_vectors {
  48,
  Archimedean_truncated_cuboctahedron_verts[0],
  Archimedean_truncated_cuboctahedron_verts[1],
  Archimedean_truncated_cuboctahedron_verts[2],
  Archimedean_truncated_cuboctahedron_verts[3],
  Archimedean_truncated_cuboctahedron_verts[4],
  Archimedean_truncated_cuboctahedron_verts[5],
  Archimedean_truncated_cuboctahedron_verts[6],
  Archimedean_truncated_cuboctahedron_verts[7],
  Archimedean_truncated_cuboctahedron_verts[8],
  Archimedean_truncated_cuboctahedron_verts[9],
  Archimedean_truncated_cuboctahedron_verts[10],
  Archimedean_truncated_cuboctahedron_verts[11],
  Archimedean_truncated_cuboctahedron_verts[12],
  Archimedean_truncated_cuboctahedron_verts[13],
  Archimedean_truncated_cuboctahedron_verts[14],
  Archimedean_truncated_cuboctahedron_verts[15],
  Archimedean_truncated_cuboctahedron_verts[16],
  Archimedean_truncated_cuboctahedron_verts[17],
  Archimedean_truncated_cuboctahedron_verts[18],
  Archimedean_truncated_cuboctahedron_verts[19],
  Archimedean_truncated_cuboctahedron_verts[20],
  Archimedean_truncated_cuboctahedron_verts[21],
  Archimedean_truncated_cuboctahedron_verts[22],
  Archimedean_truncated_cuboctahedron_verts[23],
  Archimedean_truncated_cuboctahedron_verts[24],
  Archimedean_truncated_cuboctahedron_verts[25],
  Archimedean_truncated_cuboctahedron_verts[26],
  Archimedean_truncated_cuboctahedron_verts[27],
  Archimedean_truncated_cuboctahedron_verts[28],
  Archimedean_truncated_cuboctahedron_verts[29],
  Archimedean_truncated_cuboctahedron_verts[30],
  Archimedean_truncated_cuboctahedron_verts[31],
  Archimedean_truncated_cuboctahedron_verts[32],
  Archimedean_truncated_cuboctahedron_verts[33],
  Archimedean_truncated_cuboctahedron_verts[34],
  Archimedean_truncated_cuboctahedron_verts[35],
  Archimedean_truncated_cuboctahedron_verts[36],
  Archimedean_truncated_cuboctahedron_verts[37],
  Archimedean_truncated_cuboctahedron_verts[38],
  Archimedean_truncated_cuboctahedron_verts[39],
  Archimedean_truncated_cuboctahedron_verts[40],
  Archimedean_truncated_cuboctahedron_verts[41],
  Archimedean_truncated_cuboctahedron_verts[42],
  Archimedean_truncated_cuboctahedron_verts[43],
  Archimedean_truncated_cuboctahedron_verts[44],
  Archimedean_truncated_cuboctahedron_verts[45],
  Archimedean_truncated_cuboctahedron_verts[46],
  Archimedean_truncated_cuboctahedron_verts[47]
 }
 face_indices {
  92,
  <0, 1, 4>,
  <0, 4, 2>,
  <3, 8, 14>,
  <3, 14, 7>,
  <5, 10, 18>,
  <5, 18, 11>,
  <6, 12, 20>,
  <6, 20, 13>,
  <9, 17, 24>,
  <9, 24, 16>,
  <15, 23, 27>,
  <15, 27, 19>,
  <21, 25, 33>,
  <21, 33, 29>,
  <22, 30, 38>,
  <22, 38, 31>,
  <26, 35, 41>,
  <26, 41, 34>,
  <28, 37, 42>,
  <28, 42, 36>,
  <32, 39, 44>,
  <32, 44, 40>,
  <43, 46, 47>,
  <43, 47, 45>,
  <0, 2, 6>,
  <0, 6, 13>,
  <0, 13, 8>,
  <0, 8, 3>,
  <1, 5, 11>,
  <1, 11, 17>,
  <1, 17, 9>,
  <1, 9, 4>,
  <7, 14, 22>,
  <7, 22, 31>,
  <7, 31, 23>,
  <7, 23, 15>,
  <10, 19, 27>,
  <10, 27, 35>,
  <10, 35, 26>,
  <10, 26, 18>,
  <12, 21, 29>,
  <12, 29, 37>,
  <12, 37, 28>,
  <12, 28, 20>,
  <16, 24, 32>,
  <16, 32, 40>,
  <16, 40, 33>,
  <16, 33, 25>,
  <30, 36, 42>,
  <30, 42, 46>,
  <30, 46, 43>,
  <30, 43, 38>,
  <34, 41, 45>,
  <34, 45, 47>,
  <34, 47, 44>,
  <34, 44, 39>,
  <0, 3, 7>,
  <0, 7, 15>,
  <0, 15, 19>,
  <0, 19, 10>,
  <0, 10, 5>,
  <0, 5, 1>,
  <2, 4, 9>,
  <2, 9, 16>,
  <2, 16, 25>,
  <2, 25, 21>,
  <2, 21, 12>,
  <2, 12, 6>,
  <8, 13, 20>,
  <8, 20, 28>,
  <8, 28, 36>,
  <8, 36, 30>,
  <8, 30, 22>,
  <8, 22, 14>,
  <11, 18, 26>,
  <11, 26, 34>,
  <11, 34, 39>,
  <11, 39, 32>,
  <11, 32, 24>,
  <11, 24, 17>,
  <23, 31, 38>,
  <23, 38, 43>,
  <23, 43, 45>,
  <23, 45, 41>,
  <23, 41, 35>,
  <23, 35, 27>,
  <29, 33, 40>,
  <29, 40, 44>,
  <29, 44, 47>,
  <29, 47, 46>,
  <29, 46, 42>,
  <29, 42, 37>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_cuboctahedron_verts[29];
 #local P1 = Archimedean_truncated_cuboctahedron_verts[33];
 #local P2 = Archimedean_truncated_cuboctahedron_verts[40];
 #local P3 = Archimedean_truncated_cuboctahedron_verts[44];
 #local P4 = Archimedean_truncated_cuboctahedron_verts[47];
 #local P5 = Archimedean_truncated_cuboctahedron_verts[46];
 #local P6 = Archimedean_truncated_cuboctahedron_verts[42];
 #local P7 = Archimedean_truncated_cuboctahedron_verts[37];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_cuboctahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_cuboctahedron_obj }
#end
#end

#macro Archimedean_truncated_cuboctahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_truncated_cuboctahedron_verts[0], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[1], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[2], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[3], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[4], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[5], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[6], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[7], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[8], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[9], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[10], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[11], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[12], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[13], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[14], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[15], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[16], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[17], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[18], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[19], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[20], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[21], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[22], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[23], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[24], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[25], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[26], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[27], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[28], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[29], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[30], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[31], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[32], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[33], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[34], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[35], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[36], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[37], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[38], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[39], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[40], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[41], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[42], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[43], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[44], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[45], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[46], RadVer }
  sphere { Archimedean_truncated_cuboctahedron_verts[47], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_truncated_cuboctahedron_verts[0], Archimedean_truncated_cuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[1], Archimedean_truncated_cuboctahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[4], Archimedean_truncated_cuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[2], Archimedean_truncated_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[3], Archimedean_truncated_cuboctahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[8], Archimedean_truncated_cuboctahedron_verts[14], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[14], Archimedean_truncated_cuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[7], Archimedean_truncated_cuboctahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[5], Archimedean_truncated_cuboctahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[10], Archimedean_truncated_cuboctahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[18], Archimedean_truncated_cuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[11], Archimedean_truncated_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[6], Archimedean_truncated_cuboctahedron_verts[12], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[12], Archimedean_truncated_cuboctahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[20], Archimedean_truncated_cuboctahedron_verts[13], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[13], Archimedean_truncated_cuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[9], Archimedean_truncated_cuboctahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[17], Archimedean_truncated_cuboctahedron_verts[24], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[24], Archimedean_truncated_cuboctahedron_verts[16], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[16], Archimedean_truncated_cuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[15], Archimedean_truncated_cuboctahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[23], Archimedean_truncated_cuboctahedron_verts[27], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[27], Archimedean_truncated_cuboctahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[19], Archimedean_truncated_cuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[21], Archimedean_truncated_cuboctahedron_verts[25], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[25], Archimedean_truncated_cuboctahedron_verts[33], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[33], Archimedean_truncated_cuboctahedron_verts[29], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[29], Archimedean_truncated_cuboctahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[22], Archimedean_truncated_cuboctahedron_verts[30], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[30], Archimedean_truncated_cuboctahedron_verts[38], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[38], Archimedean_truncated_cuboctahedron_verts[31], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[31], Archimedean_truncated_cuboctahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[26], Archimedean_truncated_cuboctahedron_verts[35], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[35], Archimedean_truncated_cuboctahedron_verts[41], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[41], Archimedean_truncated_cuboctahedron_verts[34], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[34], Archimedean_truncated_cuboctahedron_verts[26], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[28], Archimedean_truncated_cuboctahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[37], Archimedean_truncated_cuboctahedron_verts[42], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[42], Archimedean_truncated_cuboctahedron_verts[36], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[36], Archimedean_truncated_cuboctahedron_verts[28], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[32], Archimedean_truncated_cuboctahedron_verts[39], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[39], Archimedean_truncated_cuboctahedron_verts[44], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[44], Archimedean_truncated_cuboctahedron_verts[40], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[40], Archimedean_truncated_cuboctahedron_verts[32], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[43], Archimedean_truncated_cuboctahedron_verts[46], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[46], Archimedean_truncated_cuboctahedron_verts[47], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[47], Archimedean_truncated_cuboctahedron_verts[45], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[45], Archimedean_truncated_cuboctahedron_verts[43], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[2], Archimedean_truncated_cuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[13], Archimedean_truncated_cuboctahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[3], Archimedean_truncated_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[1], Archimedean_truncated_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[11], Archimedean_truncated_cuboctahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[9], Archimedean_truncated_cuboctahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[14], Archimedean_truncated_cuboctahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[31], Archimedean_truncated_cuboctahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[15], Archimedean_truncated_cuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[10], Archimedean_truncated_cuboctahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[27], Archimedean_truncated_cuboctahedron_verts[35], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[26], Archimedean_truncated_cuboctahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[12], Archimedean_truncated_cuboctahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[29], Archimedean_truncated_cuboctahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[28], Archimedean_truncated_cuboctahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[24], Archimedean_truncated_cuboctahedron_verts[32], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[40], Archimedean_truncated_cuboctahedron_verts[33], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[25], Archimedean_truncated_cuboctahedron_verts[16], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[30], Archimedean_truncated_cuboctahedron_verts[36], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[42], Archimedean_truncated_cuboctahedron_verts[46], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[43], Archimedean_truncated_cuboctahedron_verts[38], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[41], Archimedean_truncated_cuboctahedron_verts[45], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[47], Archimedean_truncated_cuboctahedron_verts[44], RadEdg }
  cylinder { Archimedean_truncated_cuboctahedron_verts[39], Archimedean_truncated_cuboctahedron_verts[34], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_truncated_cuboctahedron_verts[29];
 #local P1 = Archimedean_truncated_cuboctahedron_verts[33];
 #local P2 = Archimedean_truncated_cuboctahedron_verts[40];
 #local P3 = Archimedean_truncated_cuboctahedron_verts[44];
 #local P4 = Archimedean_truncated_cuboctahedron_verts[47];
 #local P5 = Archimedean_truncated_cuboctahedron_verts[46];
 #local P6 = Archimedean_truncated_cuboctahedron_verts[42];
 #local P7 = Archimedean_truncated_cuboctahedron_verts[37];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_snub_cuboctahedron_verts = array[24]
{
<0, 0, 1.077364>,
<0.7442063, 0, 0.7790187>,
<0.3123013, 0.6755079, 0.7790187>,
<-0.482096, 0.5669449, 0.7790187>,
<-0.7169181, -0.1996786, 0.7790187>,
<-0.1196038, -0.7345325, 0.7790187>,
<0.6246025, -0.7345325, 0.4806734>,
<1.056508, -0.1996786, 0.06806912>,
<0.8867128, 0.5669449, 0.2302762>,
<0.2621103, 1.042774, 0.06806912>,
<-0.532287, 0.9342111, 0.06806912>,
<-1.006317, 0.3082417, 0.2302762>,
<-0.7020817, -0.784071, 0.2302762>,
<0.02728827, -1.074865, 0.06806912>,
<0.6667271, -0.784071, -0.3184664>,
<0.8216855, -0.09111555, -0.6908285>,
<0.6518908, 0.6755079, -0.5286215>,
<-0.1196038, 0.8751866, -0.6168117>,
<-0.8092336, 0.4758293, -0.5286215>,
<-0.9914803, -0.2761507, -0.3184664>,
<-0.4467414, -0.825648, -0.5286215>,
<0.1926974, -0.5348539, -0.915157>,
<0.1846311, 0.2587032, -1.029416>,
<-0.5049987, -0.1406541, -0.9412258>
}
#local P0 = Archimedean_snub_cuboctahedron_verts[17];
#local P1 = Archimedean_snub_cuboctahedron_verts[22];
#local P2 = Archimedean_snub_cuboctahedron_verts[23];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 24)
 #declare Archimedean_snub_cuboctahedron_verts[Num] = vtransform(Archimedean_snub_cuboctahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_snub_cuboctahedron_faces(Tex3, Tex4, OnPlane)
#local Archimedean_snub_cuboctahedron_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_snub_cuboctahedron_verts[0],
  Archimedean_snub_cuboctahedron_verts[1],
  Archimedean_snub_cuboctahedron_verts[2],
  Archimedean_snub_cuboctahedron_verts[3],
  Archimedean_snub_cuboctahedron_verts[4],
  Archimedean_snub_cuboctahedron_verts[5],
  Archimedean_snub_cuboctahedron_verts[6],
  Archimedean_snub_cuboctahedron_verts[7],
  Archimedean_snub_cuboctahedron_verts[8],
  Archimedean_snub_cuboctahedron_verts[9],
  Archimedean_snub_cuboctahedron_verts[10],
  Archimedean_snub_cuboctahedron_verts[11],
  Archimedean_snub_cuboctahedron_verts[12],
  Archimedean_snub_cuboctahedron_verts[13],
  Archimedean_snub_cuboctahedron_verts[14],
  Archimedean_snub_cuboctahedron_verts[15],
  Archimedean_snub_cuboctahedron_verts[16],
  Archimedean_snub_cuboctahedron_verts[17],
  Archimedean_snub_cuboctahedron_verts[18],
  Archimedean_snub_cuboctahedron_verts[19],
  Archimedean_snub_cuboctahedron_verts[20],
  Archimedean_snub_cuboctahedron_verts[21],
  Archimedean_snub_cuboctahedron_verts[22],
  Archimedean_snub_cuboctahedron_verts[23]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  44,
  <0, 1, 2>, 0,
  <0, 2, 3>, 0,
  <0, 3, 4>, 0,
  <0, 4, 5>, 0,
  <1, 6, 7>, 0,
  <1, 7, 8>, 0,
  <1, 8, 2>, 0,
  <2, 8, 9>, 0,
  <3, 10, 11>, 0,
  <3, 11, 4>, 0,
  <4, 12, 5>, 0,
  <5, 12, 13>, 0,
  <5, 13, 6>, 0,
  <6, 13, 14>, 0,
  <6, 14, 7>, 0,
  <7, 14, 15>, 0,
  <8, 16, 9>, 0,
  <9, 16, 17>, 0,
  <9, 17, 10>, 0,
  <10, 17, 18>, 0,
  <10, 18, 11>, 0,
  <11, 18, 19>, 0,
  <12, 19, 20>, 0,
  <12, 20, 13>, 0,
  <14, 21, 15>, 0,
  <15, 21, 22>, 0,
  <15, 22, 16>, 0,
  <16, 22, 17>, 0,
  <18, 23, 19>, 0,
  <19, 23, 20>, 0,
  <20, 23, 21>, 0,
  <21, 23, 22>, 0,
  <0, 5, 6>, 1,
  <0, 6, 1>, 1,
  <2, 9, 10>, 1,
  <2, 10, 3>, 1,
  <4, 11, 19>, 1,
  <4, 19, 12>, 1,
  <7, 15, 16>, 1,
  <7, 16, 8>, 1,
  <13, 20, 21>, 1,
  <13, 21, 14>, 1,
  <17, 22, 23>, 1,
  <17, 23, 18>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_snub_cuboctahedron_verts[17];
 #local P1 = Archimedean_snub_cuboctahedron_verts[22];
 #local P2 = Archimedean_snub_cuboctahedron_verts[23];
 #local P3 = Archimedean_snub_cuboctahedron_verts[18];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_snub_cuboctahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_snub_cuboctahedron_obj }
#end
#end

#macro Archimedean_snub_cuboctahedron_faces2(OnPlane)
#local Archimedean_snub_cuboctahedron_obj = mesh2 {
 vertex_vectors {
  24,
  Archimedean_snub_cuboctahedron_verts[0],
  Archimedean_snub_cuboctahedron_verts[1],
  Archimedean_snub_cuboctahedron_verts[2],
  Archimedean_snub_cuboctahedron_verts[3],
  Archimedean_snub_cuboctahedron_verts[4],
  Archimedean_snub_cuboctahedron_verts[5],
  Archimedean_snub_cuboctahedron_verts[6],
  Archimedean_snub_cuboctahedron_verts[7],
  Archimedean_snub_cuboctahedron_verts[8],
  Archimedean_snub_cuboctahedron_verts[9],
  Archimedean_snub_cuboctahedron_verts[10],
  Archimedean_snub_cuboctahedron_verts[11],
  Archimedean_snub_cuboctahedron_verts[12],
  Archimedean_snub_cuboctahedron_verts[13],
  Archimedean_snub_cuboctahedron_verts[14],
  Archimedean_snub_cuboctahedron_verts[15],
  Archimedean_snub_cuboctahedron_verts[16],
  Archimedean_snub_cuboctahedron_verts[17],
  Archimedean_snub_cuboctahedron_verts[18],
  Archimedean_snub_cuboctahedron_verts[19],
  Archimedean_snub_cuboctahedron_verts[20],
  Archimedean_snub_cuboctahedron_verts[21],
  Archimedean_snub_cuboctahedron_verts[22],
  Archimedean_snub_cuboctahedron_verts[23]
 }
 face_indices {
  44,
  <0, 1, 2>,
  <0, 2, 3>,
  <0, 3, 4>,
  <0, 4, 5>,
  <1, 6, 7>,
  <1, 7, 8>,
  <1, 8, 2>,
  <2, 8, 9>,
  <3, 10, 11>,
  <3, 11, 4>,
  <4, 12, 5>,
  <5, 12, 13>,
  <5, 13, 6>,
  <6, 13, 14>,
  <6, 14, 7>,
  <7, 14, 15>,
  <8, 16, 9>,
  <9, 16, 17>,
  <9, 17, 10>,
  <10, 17, 18>,
  <10, 18, 11>,
  <11, 18, 19>,
  <12, 19, 20>,
  <12, 20, 13>,
  <14, 21, 15>,
  <15, 21, 22>,
  <15, 22, 16>,
  <16, 22, 17>,
  <18, 23, 19>,
  <19, 23, 20>,
  <20, 23, 21>,
  <21, 23, 22>,
  <0, 5, 6>,
  <0, 6, 1>,
  <2, 9, 10>,
  <2, 10, 3>,
  <4, 11, 19>,
  <4, 19, 12>,
  <7, 15, 16>,
  <7, 16, 8>,
  <13, 20, 21>,
  <13, 21, 14>,
  <17, 22, 23>,
  <17, 23, 18>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_snub_cuboctahedron_verts[17];
 #local P1 = Archimedean_snub_cuboctahedron_verts[22];
 #local P2 = Archimedean_snub_cuboctahedron_verts[23];
 #local P3 = Archimedean_snub_cuboctahedron_verts[18];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_snub_cuboctahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_snub_cuboctahedron_obj }
#end
#end

#macro Archimedean_snub_cuboctahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_snub_cuboctahedron_verts[0], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[1], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[2], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[3], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[4], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[5], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[6], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[7], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[8], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[9], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[10], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[11], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[12], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[13], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[14], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[15], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[16], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[17], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[18], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[19], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[20], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[21], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[22], RadVer }
  sphere { Archimedean_snub_cuboctahedron_verts[23], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_snub_cuboctahedron_verts[0], Archimedean_snub_cuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[1], Archimedean_snub_cuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[2], Archimedean_snub_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[2], Archimedean_snub_cuboctahedron_verts[3], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[3], Archimedean_snub_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[3], Archimedean_snub_cuboctahedron_verts[4], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[4], Archimedean_snub_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[4], Archimedean_snub_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[5], Archimedean_snub_cuboctahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[1], Archimedean_snub_cuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[6], Archimedean_snub_cuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[7], Archimedean_snub_cuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[7], Archimedean_snub_cuboctahedron_verts[8], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[8], Archimedean_snub_cuboctahedron_verts[1], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[8], Archimedean_snub_cuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[8], Archimedean_snub_cuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[9], Archimedean_snub_cuboctahedron_verts[2], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[3], Archimedean_snub_cuboctahedron_verts[10], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[10], Archimedean_snub_cuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[11], Archimedean_snub_cuboctahedron_verts[3], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[11], Archimedean_snub_cuboctahedron_verts[4], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[4], Archimedean_snub_cuboctahedron_verts[12], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[12], Archimedean_snub_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[12], Archimedean_snub_cuboctahedron_verts[13], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[13], Archimedean_snub_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[13], Archimedean_snub_cuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[6], Archimedean_snub_cuboctahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[13], Archimedean_snub_cuboctahedron_verts[14], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[14], Archimedean_snub_cuboctahedron_verts[6], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[14], Archimedean_snub_cuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[14], Archimedean_snub_cuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[15], Archimedean_snub_cuboctahedron_verts[7], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[8], Archimedean_snub_cuboctahedron_verts[16], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[16], Archimedean_snub_cuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[16], Archimedean_snub_cuboctahedron_verts[17], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[17], Archimedean_snub_cuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[17], Archimedean_snub_cuboctahedron_verts[10], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[10], Archimedean_snub_cuboctahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[17], Archimedean_snub_cuboctahedron_verts[18], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[18], Archimedean_snub_cuboctahedron_verts[10], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[18], Archimedean_snub_cuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[18], Archimedean_snub_cuboctahedron_verts[19], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[19], Archimedean_snub_cuboctahedron_verts[11], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[12], Archimedean_snub_cuboctahedron_verts[19], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[19], Archimedean_snub_cuboctahedron_verts[20], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[20], Archimedean_snub_cuboctahedron_verts[12], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[20], Archimedean_snub_cuboctahedron_verts[13], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[14], Archimedean_snub_cuboctahedron_verts[21], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[21], Archimedean_snub_cuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[21], Archimedean_snub_cuboctahedron_verts[22], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[22], Archimedean_snub_cuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[22], Archimedean_snub_cuboctahedron_verts[16], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[16], Archimedean_snub_cuboctahedron_verts[15], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[22], Archimedean_snub_cuboctahedron_verts[17], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[18], Archimedean_snub_cuboctahedron_verts[23], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[23], Archimedean_snub_cuboctahedron_verts[19], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[23], Archimedean_snub_cuboctahedron_verts[20], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[23], Archimedean_snub_cuboctahedron_verts[21], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[21], Archimedean_snub_cuboctahedron_verts[20], RadEdg }
  cylinder { Archimedean_snub_cuboctahedron_verts[23], Archimedean_snub_cuboctahedron_verts[22], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_snub_cuboctahedron_verts[17];
 #local P1 = Archimedean_snub_cuboctahedron_verts[22];
 #local P2 = Archimedean_snub_cuboctahedron_verts[23];
 #local P3 = Archimedean_snub_cuboctahedron_verts[18];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_icosidodecahedron_verts = array[30]
{
<0, 0, 1.051462>,
<0.618034, 0, 0.8506508>,
<0.2763932, 0.5527864, 0.8506508>,
<-0.618034, 0, 0.8506508>,
<-0.2763932, -0.5527864, 0.8506508>,
<1., 0, 0.3249197>,
<0.7236068, -0.5527864, 0.5257311>,
<-0.1708204, 0.8944272, 0.5257311>,
<0.4472136, 0.8944272, 0.3249197>,
<-1., 0, 0.3249197>,
<-0.7236068, 0.5527864, 0.5257311>,
<0.1708204, -0.8944272, 0.5257311>,
<-0.4472136, -0.8944272, 0.3249197>,
<1., 0, -0.3249197>,
<0.8944272, 0.5527864, 0>,
<0.5527864, -0.8944272, 0>,
<-0.5527864, 0.8944272, 0>,
<0.4472136, 0.8944272, -0.3249197>,
<-1., 0, -0.3249197>,
<-0.8944272, -0.5527864, 0>,
<-0.4472136, -0.8944272, -0.3249197>,
<0.618034, 0, -0.8506508>,
<0.7236068, -0.5527864, -0.5257311>,
<0.1708204, -0.8944272, -0.5257311>
<-0.7236068, 0.5527864, -0.5257311>,
<-0.1708204, 0.8944272, -0.5257311>,
<0.2763932, 0.5527864, -0.8506508>,
<-0.618034, 0, -0.8506508>,
<-0.2763932, -0.5527864, -0.8506508>,
<0, 0, -1.051462>,
}
#local P0 = Archimedean_icosidodecahedron_verts[24];
#local P1 = Archimedean_icosidodecahedron_verts[25];
#local P2 = Archimedean_icosidodecahedron_verts[26];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 30)
 #declare Archimedean_icosidodecahedron_verts[Num] = vtransform(Archimedean_icosidodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_icosidodecahedron_faces(Tex3, Tex5, OnPlane)
#local Archimedean_icosidodecahedron_obj = mesh2 {
 vertex_vectors {
  30,
  Archimedean_icosidodecahedron_verts[0],
  Archimedean_icosidodecahedron_verts[1],
  Archimedean_icosidodecahedron_verts[2],
  Archimedean_icosidodecahedron_verts[3],
  Archimedean_icosidodecahedron_verts[4],
  Archimedean_icosidodecahedron_verts[5],
  Archimedean_icosidodecahedron_verts[6],
  Archimedean_icosidodecahedron_verts[7],
  Archimedean_icosidodecahedron_verts[8],
  Archimedean_icosidodecahedron_verts[9],
  Archimedean_icosidodecahedron_verts[10],
  Archimedean_icosidodecahedron_verts[11],
  Archimedean_icosidodecahedron_verts[12],
  Archimedean_icosidodecahedron_verts[13],
  Archimedean_icosidodecahedron_verts[14],
  Archimedean_icosidodecahedron_verts[15],
  Archimedean_icosidodecahedron_verts[16],
  Archimedean_icosidodecahedron_verts[17],
  Archimedean_icosidodecahedron_verts[18],
  Archimedean_icosidodecahedron_verts[19],
  Archimedean_icosidodecahedron_verts[20],
  Archimedean_icosidodecahedron_verts[21],
  Archimedean_icosidodecahedron_verts[22],
  Archimedean_icosidodecahedron_verts[23],
  Archimedean_icosidodecahedron_verts[24],
  Archimedean_icosidodecahedron_verts[25],
  Archimedean_icosidodecahedron_verts[26],
  Archimedean_icosidodecahedron_verts[27],
  Archimedean_icosidodecahedron_verts[28],
  Archimedean_icosidodecahedron_verts[29]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  56,
  <0, 1, 2>, 0,
  <0, 3, 4>, 0,
  <1, 6, 5>, 0,
  <2, 8, 7>, 0,
  <3, 10, 9>, 0,
  <4, 12, 11>, 0,
  <5, 13, 14>, 0,
  <6, 11, 15>, 0,
  <7, 16, 10>, 0,
  <8, 14, 17>, 0,
  <9, 18, 19>, 0,
  <12, 19, 20>, 0,
  <13, 22, 21>, 0,
  <15, 23, 22>, 0,
  <16, 25, 24>, 0,
  <17, 26, 25>, 0,
  <18, 24, 27>, 0,
  <20, 28, 23>, 0,
  <21, 29, 26>, 0,
  <27, 29, 28>, 0,
  <0, 2, 7>, 1,
  <0, 7, 10>, 1,
  <0, 10, 3>, 1,
  <0, 4, 11>, 1,
  <0, 11, 6>, 1,
  <0, 6, 1>, 1,
  <1, 5, 14>, 1,
  <1, 14, 8>, 1,
  <1, 8, 2>, 1,
  <3, 9, 19>, 1,
  <3, 19, 12>, 1,
  <3, 12, 4>, 1,
  <5, 6, 15>, 1,
  <5, 15, 22>, 1,
  <5, 22, 13>, 1,
  <7, 8, 17>, 1,
  <7, 17, 25>, 1,
  <7, 25, 16>, 1,
  <9, 10, 16>, 1,
  <9, 16, 24>, 1,
  <9, 24, 18>, 1,
  <11, 12, 20>, 1,
  <11, 20, 23>, 1,
  <11, 23, 15>, 1,
  <13, 21, 26>, 1,
  <13, 26, 17>, 1,
  <13, 17, 14>, 1,
  <18, 27, 28>, 1,
  <18, 28, 20>, 1,
  <18, 20, 19>, 1,
  <21, 22, 23>, 1,
  <21, 23, 28>, 1,
  <21, 28, 29>, 1,
  <24, 25, 26>, 1,
  <24, 26, 29>, 1,
  <24, 29, 27>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_icosidodecahedron_verts[24];
 #local P1 = Archimedean_icosidodecahedron_verts[25];
 #local P2 = Archimedean_icosidodecahedron_verts[26];
 #local P3 = Archimedean_icosidodecahedron_verts[29];
 #local P4 = Archimedean_icosidodecahedron_verts[27];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_icosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_icosidodecahedron_obj }
#end
#end

#macro Archimedean_icosidodecahedron_faces2(OnPlane)
#local Archimedean_icosidodecahedron_obj = mesh2 {
 vertex_vectors {
  30,
  Archimedean_icosidodecahedron_verts[0],
  Archimedean_icosidodecahedron_verts[1],
  Archimedean_icosidodecahedron_verts[2],
  Archimedean_icosidodecahedron_verts[3],
  Archimedean_icosidodecahedron_verts[4],
  Archimedean_icosidodecahedron_verts[5],
  Archimedean_icosidodecahedron_verts[6],
  Archimedean_icosidodecahedron_verts[7],
  Archimedean_icosidodecahedron_verts[8],
  Archimedean_icosidodecahedron_verts[9],
  Archimedean_icosidodecahedron_verts[10],
  Archimedean_icosidodecahedron_verts[11],
  Archimedean_icosidodecahedron_verts[12],
  Archimedean_icosidodecahedron_verts[13],
  Archimedean_icosidodecahedron_verts[14],
  Archimedean_icosidodecahedron_verts[15],
  Archimedean_icosidodecahedron_verts[16],
  Archimedean_icosidodecahedron_verts[17],
  Archimedean_icosidodecahedron_verts[18],
  Archimedean_icosidodecahedron_verts[19],
  Archimedean_icosidodecahedron_verts[20],
  Archimedean_icosidodecahedron_verts[21],
  Archimedean_icosidodecahedron_verts[22],
  Archimedean_icosidodecahedron_verts[23],
  Archimedean_icosidodecahedron_verts[24],
  Archimedean_icosidodecahedron_verts[25],
  Archimedean_icosidodecahedron_verts[26],
  Archimedean_icosidodecahedron_verts[27],
  Archimedean_icosidodecahedron_verts[28],
  Archimedean_icosidodecahedron_verts[29]
 }
 face_indices {
  56,
  <0, 1, 2>,
  <0, 3, 4>,
  <1, 6, 5>,
  <2, 8, 7>,
  <3, 10, 9>,
  <4, 12, 11>,
  <5, 13, 14>,
  <6, 11, 15>,
  <7, 16, 10>,
  <8, 14, 17>,
  <9, 18, 19>,
  <12, 19, 20>,
  <13, 22, 21>,
  <15, 23, 22>,
  <16, 25, 24>,
  <17, 26, 25>,
  <18, 24, 27>,
  <20, 28, 23>,
  <21, 29, 26>,
  <27, 29, 28>,
  <0, 2, 7>,
  <0, 7, 10>,
  <0, 10, 3>,
  <0, 4, 11>,
  <0, 11, 6>,
  <0, 6, 1>,
  <1, 5, 14>,
  <1, 14, 8>,
  <1, 8, 2>,
  <3, 9, 19>,
  <3, 19, 12>,
  <3, 12, 4>,
  <5, 6, 15>,
  <5, 15, 22>,
  <5, 22, 13>,
  <7, 8, 17>,
  <7, 17, 25>,
  <7, 25, 16>,
  <9, 10, 16>,
  <9, 16, 24>,
  <9, 24, 18>,
  <11, 12, 20>,
  <11, 20, 23>,
  <11, 23, 15>,
  <13, 21, 26>,
  <13, 26, 17>,
  <13, 17, 14>,
  <18, 27, 28>,
  <18, 28, 20>,
  <18, 20, 19>,
  <21, 22, 23>,
  <21, 23, 28>,
  <21, 28, 29>,
  <24, 25, 26>,
  <24, 26, 29>,
  <24, 29, 27>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_icosidodecahedron_verts[24];
 #local P1 = Archimedean_icosidodecahedron_verts[25];
 #local P2 = Archimedean_icosidodecahedron_verts[26];
 #local P3 = Archimedean_icosidodecahedron_verts[29];
 #local P4 = Archimedean_icosidodecahedron_verts[27];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_icosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_icosidodecahedron_obj }
#end
#end

#macro Archimedean_icosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_icosidodecahedron_verts[0], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[1], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[2], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[3], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[4], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[5], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[6], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[7], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[8], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[9], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[10], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[11], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[12], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[13], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[14], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[15], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[16], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[17], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[18], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[19], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[20], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[21], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[22], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[23], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[24], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[25], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[26], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[27], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[28], RadVer }
  sphere { Archimedean_icosidodecahedron_verts[29], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_icosidodecahedron_verts[0], Archimedean_icosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[1], Archimedean_icosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[2], Archimedean_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[0], Archimedean_icosidodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[3], Archimedean_icosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[4], Archimedean_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[1], Archimedean_icosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[6], Archimedean_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[5], Archimedean_icosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[2], Archimedean_icosidodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[8], Archimedean_icosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[7], Archimedean_icosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[3], Archimedean_icosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[10], Archimedean_icosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[9], Archimedean_icosidodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[4], Archimedean_icosidodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[12], Archimedean_icosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[11], Archimedean_icosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[5], Archimedean_icosidodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[13], Archimedean_icosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[14], Archimedean_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[6], Archimedean_icosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[11], Archimedean_icosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[15], Archimedean_icosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[7], Archimedean_icosidodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[16], Archimedean_icosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[10], Archimedean_icosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[8], Archimedean_icosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[14], Archimedean_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[17], Archimedean_icosidodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[9], Archimedean_icosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[18], Archimedean_icosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[19], Archimedean_icosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[12], Archimedean_icosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[19], Archimedean_icosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[20], Archimedean_icosidodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[13], Archimedean_icosidodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[22], Archimedean_icosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[21], Archimedean_icosidodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[15], Archimedean_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[23], Archimedean_icosidodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[22], Archimedean_icosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[16], Archimedean_icosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[25], Archimedean_icosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[24], Archimedean_icosidodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[17], Archimedean_icosidodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[26], Archimedean_icosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[25], Archimedean_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[18], Archimedean_icosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[24], Archimedean_icosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[27], Archimedean_icosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[20], Archimedean_icosidodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[28], Archimedean_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[23], Archimedean_icosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[21], Archimedean_icosidodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[29], Archimedean_icosidodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[26], Archimedean_icosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[27], Archimedean_icosidodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[29], Archimedean_icosidodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_icosidodecahedron_verts[28], Archimedean_icosidodecahedron_verts[27], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_icosidodecahedron_verts[24];
 #local P1 = Archimedean_icosidodecahedron_verts[25];
 #local P2 = Archimedean_icosidodecahedron_verts[26];
 #local P3 = Archimedean_icosidodecahedron_verts[29];
 #local P4 = Archimedean_icosidodecahedron_verts[27];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_truncated_dodecahedron_verts = array[60]
{
<0, 0, 1.014485>,
<0.3367628, 0, 0.9569589>,
<-0.2902233, 0.1708204, 0.9569589>,
<0.1634681, -0.2944272, 0.9569589>,
<0.5914332, 0.1708204, 0.806354>,
<-0.5963465, 0.1527864, 0.806354>,
<-0.4230517, 0.4472136, 0.806354>,
<0.1377417, -0.6, 0.806354>,
<0.8302037, 0.1527864, 0.5626702>,
<0.6667356, 0.4472136, 0.6201961>,
<-0.8014407, -0.0472136, 0.6201961>,
<-0.3477493, 0.7236068, 0.6201961>,
<-0.06735256, -0.8, 0.6201961>,
<0.2694102, -0.8, 0.5626702>,
<0.9618722, -0.0472136, 0.3189863>,
<0.5339072, 0.7236068, 0.4695912>,
<-0.8271671, -0.3527864, 0.4695912>,
<-0.9599955, -0.0763932, 0.3189863>,
<-0.3992021, 0.8763932, 0.3189863>,
<-0.09307895, 0.8944272, 0.4695912>,
<-0.3734757, -0.818034, 0.4695912>,
<0.5081808, -0.818034, 0.3189863>,
<0.9361459, -0.3527864, 0.1683814>,
<1.011448, -0.0763932, -0.0177765>
<0.4824544, 0.8763932, 0.1683814>,
<0.2436839, 0.8944272, 0.4120653>,
<-0.663699, -0.6472136, 0.4120653>,
<-1.011448, 0.0763932, 0.0177765>,
<-0.5577569, 0.8472136, 0.0177765>,
<-0.5320305, -0.8472136, 0.1683814>,
<0.5577569, -0.8472136, -0.0177765>,
<0.7628511, -0.6472136, 0.1683814>,
<0.9599955, 0.0763932, -0.3189863>,
<0.5320305, 0.8472136, -0.1683814>,
<-0.9618722, 0.0472136, -0.3189863>,
<-0.9361459, 0.3527864, -0.1683814>,
<-0.7628511, 0.6472136, -0.1683814>,
<-0.5081808, 0.818034, -0.3189863>,
<-0.4824544, -0.8763932, -0.1683814>,
<0.3992021, -0.8763932, -0.3189863>,
<0.8014407, 0.0472136, -0.6201961>,
<0.8271671, 0.3527864, -0.4695912>,
<0.663699, 0.6472136, -0.4120653>,
<0.3734757, 0.818034, -0.4695912>,
<-0.8302037, -0.1527864, -0.5626702>,
<-0.2694102, 0.8, -0.5626702>,
<-0.5339072, -0.7236068, -0.4695912>,
<-0.2436839, -0.8944272, -0.4120653>,
<0.09307895, -0.8944272, -0.4695912>,
<0.3477493, -0.7236068, -0.6201961>,
<0.5963465, -0.1527864, -0.806354>,
<0.06735256, 0.8, -0.6201961>,
<-0.6667356, -0.4472136, -0.6201961>,
<-0.5914332, -0.1708204, -0.806354>,
<-0.1377417, 0.6, -0.806354>,
<0.4230517, -0.4472136, -0.806354>,
<0.2902233, -0.1708204, -0.9569589>,
<-0.3367628, 0, -0.9569589>,
<-0.1634681, 0.2944272, -0.9569589>,
<0, 0, -1.014485>,
}
#local P0 = Archimedean_truncated_dodecahedron_verts[46];
#local P1 = Archimedean_truncated_dodecahedron_verts[52];
#local P2 = Archimedean_truncated_dodecahedron_verts[53];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 60)
 #declare Archimedean_truncated_dodecahedron_verts[Num] = vtransform(Archimedean_truncated_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_truncated_dodecahedron_faces(Tex3, Tex10, OnPlane)
#local Archimedean_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_truncated_dodecahedron_verts[0],
  Archimedean_truncated_dodecahedron_verts[1],
  Archimedean_truncated_dodecahedron_verts[2],
  Archimedean_truncated_dodecahedron_verts[3],
  Archimedean_truncated_dodecahedron_verts[4],
  Archimedean_truncated_dodecahedron_verts[5],
  Archimedean_truncated_dodecahedron_verts[6],
  Archimedean_truncated_dodecahedron_verts[7],
  Archimedean_truncated_dodecahedron_verts[8],
  Archimedean_truncated_dodecahedron_verts[9],
  Archimedean_truncated_dodecahedron_verts[10],
  Archimedean_truncated_dodecahedron_verts[11],
  Archimedean_truncated_dodecahedron_verts[12],
  Archimedean_truncated_dodecahedron_verts[13],
  Archimedean_truncated_dodecahedron_verts[14],
  Archimedean_truncated_dodecahedron_verts[15],
  Archimedean_truncated_dodecahedron_verts[16],
  Archimedean_truncated_dodecahedron_verts[17],
  Archimedean_truncated_dodecahedron_verts[18],
  Archimedean_truncated_dodecahedron_verts[19],
  Archimedean_truncated_dodecahedron_verts[20],
  Archimedean_truncated_dodecahedron_verts[21],
  Archimedean_truncated_dodecahedron_verts[22],
  Archimedean_truncated_dodecahedron_verts[23],
  Archimedean_truncated_dodecahedron_verts[24],
  Archimedean_truncated_dodecahedron_verts[25],
  Archimedean_truncated_dodecahedron_verts[26],
  Archimedean_truncated_dodecahedron_verts[27],
  Archimedean_truncated_dodecahedron_verts[28],
  Archimedean_truncated_dodecahedron_verts[29],
  Archimedean_truncated_dodecahedron_verts[30],
  Archimedean_truncated_dodecahedron_verts[31],
  Archimedean_truncated_dodecahedron_verts[32],
  Archimedean_truncated_dodecahedron_verts[33],
  Archimedean_truncated_dodecahedron_verts[34],
  Archimedean_truncated_dodecahedron_verts[35],
  Archimedean_truncated_dodecahedron_verts[36],
  Archimedean_truncated_dodecahedron_verts[37],
  Archimedean_truncated_dodecahedron_verts[38],
  Archimedean_truncated_dodecahedron_verts[39],
  Archimedean_truncated_dodecahedron_verts[40],
  Archimedean_truncated_dodecahedron_verts[41],
  Archimedean_truncated_dodecahedron_verts[42],
  Archimedean_truncated_dodecahedron_verts[43],
  Archimedean_truncated_dodecahedron_verts[44],
  Archimedean_truncated_dodecahedron_verts[45],
  Archimedean_truncated_dodecahedron_verts[46],
  Archimedean_truncated_dodecahedron_verts[47],
  Archimedean_truncated_dodecahedron_verts[48],
  Archimedean_truncated_dodecahedron_verts[49],
  Archimedean_truncated_dodecahedron_verts[50],
  Archimedean_truncated_dodecahedron_verts[51],
  Archimedean_truncated_dodecahedron_verts[52],
  Archimedean_truncated_dodecahedron_verts[53],
  Archimedean_truncated_dodecahedron_verts[54],
  Archimedean_truncated_dodecahedron_verts[55],
  Archimedean_truncated_dodecahedron_verts[56],
  Archimedean_truncated_dodecahedron_verts[57],
  Archimedean_truncated_dodecahedron_verts[58],
  Archimedean_truncated_dodecahedron_verts[59]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex10 }
 }
 face_indices {
  116,
  <0, 3, 1>, 0,
  <2, 6, 5>, 0,
  <4, 8, 9>, 0,
  <7, 12, 13>, 0,
  <10, 17, 16>, 0,
  <11, 19, 18>, 0,
  <14, 22, 23>, 0,
  <15, 24, 25>, 0,
  <20, 26, 29>, 0,
  <21, 30, 31>, 0,
  <27, 35, 34>, 0,
  <28, 37, 36>, 0,
  <32, 40, 41>, 0,
  <33, 42, 43>, 0,
  <38, 46, 47>, 0,
  <39, 48, 49>, 0,
  <44, 53, 52>, 0,
  <45, 51, 54>, 0,
  <50, 55, 56>, 0,
  <57, 58, 59>, 0,
  <0, 1, 4>, 1,
  <0, 4, 9>, 1,
  <0, 9, 15>, 1,
  <0, 15, 25>, 1,
  <0, 25, 19>, 1,
  <0, 19, 11>, 1,
  <0, 11, 6>, 1,
  <0, 6, 2>, 1,
  <0, 2, 5>, 1,
  <0, 5, 10>, 1,
  <0, 10, 16>, 1,
  <0, 16, 26>, 1,
  <0, 26, 20>, 1,
  <0, 20, 12>, 1,
  <0, 12, 7>, 1,
  <0, 7, 3>, 1,
  <1, 3, 7>, 1,
  <1, 7, 13>, 1,
  <1, 13, 21>, 1,
  <1, 21, 31>, 1,
  <1, 31, 22>, 1,
  <1, 22, 14>, 1,
  <1, 14, 8>, 1,
  <1, 8, 4>, 1,
  <5, 6, 11>, 1,
  <5, 11, 18>, 1,
  <5, 18, 28>, 1,
  <5, 28, 36>, 1,
  <5, 36, 35>, 1,
  <5, 35, 27>, 1,
  <5, 27, 17>, 1,
  <5, 17, 10>, 1,
  <8, 14, 23>, 1,
  <8, 23, 32>, 1,
  <8, 32, 41>, 1,
  <8, 41, 42>, 1,
  <8, 42, 33>, 1,
  <8, 33, 24>, 1,
  <8, 24, 15>, 1,
  <8, 15, 9>, 1,
  <12, 20, 29>, 1,
  <12, 29, 38>, 1,
  <12, 38, 47>, 1,
  <12, 47, 48>, 1,
  <12, 48, 39>, 1,
  <12, 39, 30>, 1,
  <12, 30, 21>, 1,
  <12, 21, 13>, 1,
  <16, 17, 27>, 1,
  <16, 27, 34>, 1,
  <16, 34, 44>, 1,
  <16, 44, 52>, 1,
  <16, 52, 46>, 1,
  <16, 46, 38>, 1,
  <16, 38, 29>, 1,
  <16, 29, 26>, 1,
  <18, 19, 25>, 1,
  <18, 25, 24>, 1,
  <18, 24, 33>, 1,
  <18, 33, 43>, 1,
  <18, 43, 51>, 1,
  <18, 51, 45>, 1,
  <18, 45, 37>, 1,
  <18, 37, 28>, 1,
  <22, 31, 30>, 1,
  <22, 30, 39>, 1,
  <22, 39, 49>, 1,
  <22, 49, 55>, 1,
  <22, 55, 50>, 1,
  <22, 50, 40>, 1,
  <22, 40, 32>, 1,
  <22, 32, 23>, 1,
  <34, 35, 36>, 1,
  <34, 36, 37>, 1,
  <34, 37, 45>, 1,
  <34, 45, 54>, 1,
  <34, 54, 58>, 1,
  <34, 58, 57>, 1,
  <34, 57, 53>, 1,
  <34, 53, 44>, 1,
  <40, 50, 56>, 1,
  <40, 56, 59>, 1,
  <40, 59, 58>, 1,
  <40, 58, 54>, 1,
  <40, 54, 51>, 1,
  <40, 51, 43>, 1,
  <40, 43, 42>, 1,
  <40, 42, 41>, 1,
  <46, 52, 53>, 1,
  <46, 53, 57>, 1,
  <46, 57, 59>, 1,
  <46, 59, 56>, 1,
  <46, 56, 55>, 1,
  <46, 55, 49>, 1,
  <46, 49, 48>, 1,
  <46, 48, 47>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_dodecahedron_verts[46];
 #local P1 = Archimedean_truncated_dodecahedron_verts[52];
 #local P2 = Archimedean_truncated_dodecahedron_verts[53];
 #local P3 = Archimedean_truncated_dodecahedron_verts[57];
 #local P4 = Archimedean_truncated_dodecahedron_verts[59];
 #local P5 = Archimedean_truncated_dodecahedron_verts[56];
 #local P6 = Archimedean_truncated_dodecahedron_verts[55];
 #local P7 = Archimedean_truncated_dodecahedron_verts[49];
 #local P8 = Archimedean_truncated_dodecahedron_verts[48];
 #local P9 = Archimedean_truncated_dodecahedron_verts[47];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_dodecahedron_obj }
#end
#end

#macro Archimedean_truncated_dodecahedron_faces2(OnPlane)
#local Archimedean_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_truncated_dodecahedron_verts[0],
  Archimedean_truncated_dodecahedron_verts[1],
  Archimedean_truncated_dodecahedron_verts[2],
  Archimedean_truncated_dodecahedron_verts[3],
  Archimedean_truncated_dodecahedron_verts[4],
  Archimedean_truncated_dodecahedron_verts[5],
  Archimedean_truncated_dodecahedron_verts[6],
  Archimedean_truncated_dodecahedron_verts[7],
  Archimedean_truncated_dodecahedron_verts[8],
  Archimedean_truncated_dodecahedron_verts[9],
  Archimedean_truncated_dodecahedron_verts[10],
  Archimedean_truncated_dodecahedron_verts[11],
  Archimedean_truncated_dodecahedron_verts[12],
  Archimedean_truncated_dodecahedron_verts[13],
  Archimedean_truncated_dodecahedron_verts[14],
  Archimedean_truncated_dodecahedron_verts[15],
  Archimedean_truncated_dodecahedron_verts[16],
  Archimedean_truncated_dodecahedron_verts[17],
  Archimedean_truncated_dodecahedron_verts[18],
  Archimedean_truncated_dodecahedron_verts[19],
  Archimedean_truncated_dodecahedron_verts[20],
  Archimedean_truncated_dodecahedron_verts[21],
  Archimedean_truncated_dodecahedron_verts[22],
  Archimedean_truncated_dodecahedron_verts[23],
  Archimedean_truncated_dodecahedron_verts[24],
  Archimedean_truncated_dodecahedron_verts[25],
  Archimedean_truncated_dodecahedron_verts[26],
  Archimedean_truncated_dodecahedron_verts[27],
  Archimedean_truncated_dodecahedron_verts[28],
  Archimedean_truncated_dodecahedron_verts[29],
  Archimedean_truncated_dodecahedron_verts[30],
  Archimedean_truncated_dodecahedron_verts[31],
  Archimedean_truncated_dodecahedron_verts[32],
  Archimedean_truncated_dodecahedron_verts[33],
  Archimedean_truncated_dodecahedron_verts[34],
  Archimedean_truncated_dodecahedron_verts[35],
  Archimedean_truncated_dodecahedron_verts[36],
  Archimedean_truncated_dodecahedron_verts[37],
  Archimedean_truncated_dodecahedron_verts[38],
  Archimedean_truncated_dodecahedron_verts[39],
  Archimedean_truncated_dodecahedron_verts[40],
  Archimedean_truncated_dodecahedron_verts[41],
  Archimedean_truncated_dodecahedron_verts[42],
  Archimedean_truncated_dodecahedron_verts[43],
  Archimedean_truncated_dodecahedron_verts[44],
  Archimedean_truncated_dodecahedron_verts[45],
  Archimedean_truncated_dodecahedron_verts[46],
  Archimedean_truncated_dodecahedron_verts[47],
  Archimedean_truncated_dodecahedron_verts[48],
  Archimedean_truncated_dodecahedron_verts[49],
  Archimedean_truncated_dodecahedron_verts[50],
  Archimedean_truncated_dodecahedron_verts[51],
  Archimedean_truncated_dodecahedron_verts[52],
  Archimedean_truncated_dodecahedron_verts[53],
  Archimedean_truncated_dodecahedron_verts[54],
  Archimedean_truncated_dodecahedron_verts[55],
  Archimedean_truncated_dodecahedron_verts[56],
  Archimedean_truncated_dodecahedron_verts[57],
  Archimedean_truncated_dodecahedron_verts[58],
  Archimedean_truncated_dodecahedron_verts[59]
 }
 face_indices {
  116,
  <0, 3, 1>,
  <2, 6, 5>,
  <4, 8, 9>,
  <7, 12, 13>,
  <10, 17, 16>,
  <11, 19, 18>,
  <14, 22, 23>,
  <15, 24, 25>,
  <20, 26, 29>,
  <21, 30, 31>,
  <27, 35, 34>,
  <28, 37, 36>,
  <32, 40, 41>,
  <33, 42, 43>,
  <38, 46, 47>,
  <39, 48, 49>,
  <44, 53, 52>,
  <45, 51, 54>,
  <50, 55, 56>,
  <57, 58, 59>,
  <0, 1, 4>,
  <0, 4, 9>,
  <0, 9, 15>,
  <0, 15, 25>,
  <0, 25, 19>,
  <0, 19, 11>,
  <0, 11, 6>,
  <0, 6, 2>,
  <0, 2, 5>,
  <0, 5, 10>,
  <0, 10, 16>,
  <0, 16, 26>,
  <0, 26, 20>,
  <0, 20, 12>,
  <0, 12, 7>,
  <0, 7, 3>,
  <1, 3, 7>,
  <1, 7, 13>,
  <1, 13, 21>,
  <1, 21, 31>,
  <1, 31, 22>,
  <1, 22, 14>,
  <1, 14, 8>,
  <1, 8, 4>,
  <5, 6, 11>,
  <5, 11, 18>,
  <5, 18, 28>,
  <5, 28, 36>,
  <5, 36, 35>,
  <5, 35, 27>,
  <5, 27, 17>,
  <5, 17, 10>,
  <8, 14, 23>,
  <8, 23, 32>,
  <8, 32, 41>,
  <8, 41, 42>,
  <8, 42, 33>,
  <8, 33, 24>,
  <8, 24, 15>,
  <8, 15, 9>,
  <12, 20, 29>,
  <12, 29, 38>,
  <12, 38, 47>,
  <12, 47, 48>,
  <12, 48, 39>,
  <12, 39, 30>,
  <12, 30, 21>,
  <12, 21, 13>,
  <16, 17, 27>,
  <16, 27, 34>,
  <16, 34, 44>,
  <16, 44, 52>,
  <16, 52, 46>,
  <16, 46, 38>,
  <16, 38, 29>,
  <16, 29, 26>,
  <18, 19, 25>,
  <18, 25, 24>,
  <18, 24, 33>,
  <18, 33, 43>,
  <18, 43, 51>,
  <18, 51, 45>,
  <18, 45, 37>,
  <18, 37, 28>,
  <22, 31, 30>,
  <22, 30, 39>,
  <22, 39, 49>,
  <22, 49, 55>,
  <22, 55, 50>,
  <22, 50, 40>,
  <22, 40, 32>,
  <22, 32, 23>,
  <34, 35, 36>,
  <34, 36, 37>,
  <34, 37, 45>,
  <34, 45, 54>,
  <34, 54, 58>,
  <34, 58, 57>,
  <34, 57, 53>,
  <34, 53, 44>,
  <40, 50, 56>,
  <40, 56, 59>,
  <40, 59, 58>,
  <40, 58, 54>,
  <40, 54, 51>,
  <40, 51, 43>,
  <40, 43, 42>,
  <40, 42, 41>,
  <46, 52, 53>,
  <46, 53, 57>,
  <46, 57, 59>,
  <46, 59, 56>,
  <46, 56, 55>,
  <46, 55, 49>,
  <46, 49, 48>,
  <46, 48, 47>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_dodecahedron_verts[46];
 #local P1 = Archimedean_truncated_dodecahedron_verts[52];
 #local P2 = Archimedean_truncated_dodecahedron_verts[53];
 #local P3 = Archimedean_truncated_dodecahedron_verts[57];
 #local P4 = Archimedean_truncated_dodecahedron_verts[59];
 #local P5 = Archimedean_truncated_dodecahedron_verts[56];
 #local P6 = Archimedean_truncated_dodecahedron_verts[55];
 #local P7 = Archimedean_truncated_dodecahedron_verts[49];
 #local P8 = Archimedean_truncated_dodecahedron_verts[48];
 #local P9 = Archimedean_truncated_dodecahedron_verts[47];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_dodecahedron_obj }
#end
#end

#macro Archimedean_truncated_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_truncated_dodecahedron_verts[0], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[1], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[2], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[3], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[4], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[5], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[6], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[7], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[8], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[9], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[10], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[11], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[12], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[13], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[14], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[15], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[16], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[17], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[18], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[19], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[20], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[21], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[22], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[23], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[24], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[25], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[26], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[27], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[28], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[29], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[30], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[31], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[32], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[33], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[34], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[35], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[36], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[37], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[38], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[39], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[40], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[41], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[42], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[43], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[44], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[45], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[46], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[47], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[48], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[49], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[50], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[51], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[52], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[53], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[54], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[55], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[56], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[57], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[58], RadVer }
  sphere { Archimedean_truncated_dodecahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_truncated_dodecahedron_verts[0], Archimedean_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[3], Archimedean_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[1], Archimedean_truncated_dodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[2], Archimedean_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[6], Archimedean_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[5], Archimedean_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[4], Archimedean_truncated_dodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[8], Archimedean_truncated_dodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[9], Archimedean_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[7], Archimedean_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[12], Archimedean_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[13], Archimedean_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[10], Archimedean_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[17], Archimedean_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[16], Archimedean_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[11], Archimedean_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[19], Archimedean_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[18], Archimedean_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[14], Archimedean_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[22], Archimedean_truncated_dodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[23], Archimedean_truncated_dodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[15], Archimedean_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[24], Archimedean_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[25], Archimedean_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[20], Archimedean_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[26], Archimedean_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[29], Archimedean_truncated_dodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[21], Archimedean_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[30], Archimedean_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[31], Archimedean_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[27], Archimedean_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[35], Archimedean_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[34], Archimedean_truncated_dodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[28], Archimedean_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[37], Archimedean_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[36], Archimedean_truncated_dodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[32], Archimedean_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[40], Archimedean_truncated_dodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[41], Archimedean_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[33], Archimedean_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[42], Archimedean_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[43], Archimedean_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[38], Archimedean_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[46], Archimedean_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[47], Archimedean_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[39], Archimedean_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[48], Archimedean_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[49], Archimedean_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[44], Archimedean_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[53], Archimedean_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[52], Archimedean_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[45], Archimedean_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[51], Archimedean_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[54], Archimedean_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[50], Archimedean_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[55], Archimedean_truncated_dodecahedron_verts[56], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[56], Archimedean_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[57], Archimedean_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[58], Archimedean_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[59], Archimedean_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[1], Archimedean_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[9], Archimedean_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[25], Archimedean_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[11], Archimedean_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[2], Archimedean_truncated_dodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[5], Archimedean_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[16], Archimedean_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[20], Archimedean_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[7], Archimedean_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[13], Archimedean_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[31], Archimedean_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[14], Archimedean_truncated_dodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[18], Archimedean_truncated_dodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[36], Archimedean_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[27], Archimedean_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[23], Archimedean_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[41], Archimedean_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[33], Archimedean_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[29], Archimedean_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[47], Archimedean_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[39], Archimedean_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[34], Archimedean_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[52], Archimedean_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[43], Archimedean_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[45], Archimedean_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[49], Archimedean_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[50], Archimedean_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[54], Archimedean_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[57], Archimedean_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Archimedean_truncated_dodecahedron_verts[56], Archimedean_truncated_dodecahedron_verts[59], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_truncated_dodecahedron_verts[46];
 #local P1 = Archimedean_truncated_dodecahedron_verts[52];
 #local P2 = Archimedean_truncated_dodecahedron_verts[53];
 #local P3 = Archimedean_truncated_dodecahedron_verts[57];
 #local P4 = Archimedean_truncated_dodecahedron_verts[59];
 #local P5 = Archimedean_truncated_dodecahedron_verts[56];
 #local P6 = Archimedean_truncated_dodecahedron_verts[55];
 #local P7 = Archimedean_truncated_dodecahedron_verts[49];
 #local P8 = Archimedean_truncated_dodecahedron_verts[48];
 #local P9 = Archimedean_truncated_dodecahedron_verts[47];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_truncated_icosahedron_verts = array[60]
{
<0, 0, 1.021>,
<0.4035482, 0, 0.9378643>,
<-0.2274644, 0.3333333, 0.9378643>,
<-0.1471226, -0.375774, 0.9378643>,
<0.579632, 0.3333333, 0.7715933>,
<0.5058321, -0.375774, 0.8033483>,
<-0.6020514, 0.2908927, 0.7715933>,
<-0.05138057, 0.6666667, 0.7715933>,
<0.1654988, -0.6080151, 0.8033483>,
<-0.5217096, -0.4182147, 0.7715933>,
<0.8579998, 0.2908927, 0.4708062>,
<0.3521676, 0.6666667, 0.6884578>,
<0.7841999, -0.4182147, 0.5025612>,
<-0.657475, 0.5979962, 0.5025612>,
<-0.749174, -0.08488134, 0.6884578>,
<-0.3171418, 0.8302373, 0.5025612>,
<0.1035333, -0.8826969, 0.5025612>,
<-0.5836751, -0.6928964, 0.4708062>,
<0.8025761, 0.5979962, 0.2017741>,
<0.9602837, -0.08488134, 0.3362902>,
<0.4899547, 0.8302373, 0.3362902>,
<0.7222343, -0.6928964, 0.2017741>,
<-0.8600213, 0.5293258, 0.1503935>,
<-0.9517203, -0.1535518, 0.3362902>
<-0.1793548, 0.993808, 0.1503935>,
<0.381901, -0.9251375, 0.2017741>,
<-0.2710537, -0.9251375, 0.3362902>,
<-0.8494363, -0.5293258, 0.2017741>,
<0.8494363, 0.5293258, -0.2017741>,
<1.007144, -0.1535518, -0.06725804>,
<0.2241935, 0.993808, 0.06725804>,
<0.8600213, -0.5293258, -0.1503935>,
<-0.7222343, 0.6928964, -0.2017741>,
<-1.007144, 0.1535518, 0.06725804>,
<-0.381901, 0.9251375, -0.2017741>,
<0.1793548, -0.993808, -0.1503935>,
<-0.2241935, -0.993808, -0.06725804>,
<-0.8025761, -0.5979962, -0.2017741>,
<0.5836751, 0.6928964, -0.4708062>,
<0.9517203, 0.1535518, -0.3362902>,
<0.2710537, 0.9251375, -0.3362902>,
<0.657475, -0.5979962, -0.5025612>,
<-0.7841999, 0.4182147, -0.5025612>,
<-0.9602837, 0.08488134, -0.3362902>,
<-0.1035333, 0.8826969, -0.5025612>,
<0.3171418, -0.8302373, -0.5025612>,
<-0.4899547, -0.8302373, -0.3362902>,
<-0.8579998, -0.2908927, -0.4708062>,
<0.5217096, 0.4182147, -0.7715933>,
<0.749174, 0.08488134, -0.6884578>,
<0.6020514, -0.2908927, -0.7715933>,
<-0.5058321, 0.375774, -0.8033483>,
<-0.1654988, 0.6080151, -0.8033483>,
<0.05138057, -0.6666667, -0.7715933>,
<-0.3521676, -0.6666667, -0.6884578>,
<-0.579632, -0.3333333, -0.7715933>,
<0.1471226, 0.375774, -0.9378643>,
<0.2274644, -0.3333333, -0.9378643>,
<-0.4035482, 0, -0.9378643>,
<0, 0, -1.021>,
}
#local P0 = Archimedean_truncated_icosahedron_verts[53];
#local P1 = Archimedean_truncated_icosahedron_verts[54];
#local P2 = Archimedean_truncated_icosahedron_verts[55];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 60)
 #declare Archimedean_truncated_icosahedron_verts[Num] = vtransform(Archimedean_truncated_icosahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_truncated_icosahedron_faces(Tex5, Tex6, OnPlane)
#local Archimedean_truncated_icosahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_truncated_icosahedron_verts[0],
  Archimedean_truncated_icosahedron_verts[1],
  Archimedean_truncated_icosahedron_verts[2],
  Archimedean_truncated_icosahedron_verts[3],
  Archimedean_truncated_icosahedron_verts[4],
  Archimedean_truncated_icosahedron_verts[5],
  Archimedean_truncated_icosahedron_verts[6],
  Archimedean_truncated_icosahedron_verts[7],
  Archimedean_truncated_icosahedron_verts[8],
  Archimedean_truncated_icosahedron_verts[9],
  Archimedean_truncated_icosahedron_verts[10],
  Archimedean_truncated_icosahedron_verts[11],
  Archimedean_truncated_icosahedron_verts[12],
  Archimedean_truncated_icosahedron_verts[13],
  Archimedean_truncated_icosahedron_verts[14],
  Archimedean_truncated_icosahedron_verts[15],
  Archimedean_truncated_icosahedron_verts[16],
  Archimedean_truncated_icosahedron_verts[17],
  Archimedean_truncated_icosahedron_verts[18],
  Archimedean_truncated_icosahedron_verts[19],
  Archimedean_truncated_icosahedron_verts[20],
  Archimedean_truncated_icosahedron_verts[21],
  Archimedean_truncated_icosahedron_verts[22],
  Archimedean_truncated_icosahedron_verts[23],
  Archimedean_truncated_icosahedron_verts[24],
  Archimedean_truncated_icosahedron_verts[25],
  Archimedean_truncated_icosahedron_verts[26],
  Archimedean_truncated_icosahedron_verts[27],
  Archimedean_truncated_icosahedron_verts[28],
  Archimedean_truncated_icosahedron_verts[29],
  Archimedean_truncated_icosahedron_verts[30],
  Archimedean_truncated_icosahedron_verts[31],
  Archimedean_truncated_icosahedron_verts[32],
  Archimedean_truncated_icosahedron_verts[33],
  Archimedean_truncated_icosahedron_verts[34],
  Archimedean_truncated_icosahedron_verts[35],
  Archimedean_truncated_icosahedron_verts[36],
  Archimedean_truncated_icosahedron_verts[37],
  Archimedean_truncated_icosahedron_verts[38],
  Archimedean_truncated_icosahedron_verts[39],
  Archimedean_truncated_icosahedron_verts[40],
  Archimedean_truncated_icosahedron_verts[41],
  Archimedean_truncated_icosahedron_verts[42],
  Archimedean_truncated_icosahedron_verts[43],
  Archimedean_truncated_icosahedron_verts[44],
  Archimedean_truncated_icosahedron_verts[45],
  Archimedean_truncated_icosahedron_verts[46],
  Archimedean_truncated_icosahedron_verts[47],
  Archimedean_truncated_icosahedron_verts[48],
  Archimedean_truncated_icosahedron_verts[49],
  Archimedean_truncated_icosahedron_verts[50],
  Archimedean_truncated_icosahedron_verts[51],
  Archimedean_truncated_icosahedron_verts[52],
  Archimedean_truncated_icosahedron_verts[53],
  Archimedean_truncated_icosahedron_verts[54],
  Archimedean_truncated_icosahedron_verts[55],
  Archimedean_truncated_icosahedron_verts[56],
  Archimedean_truncated_icosahedron_verts[57],
  Archimedean_truncated_icosahedron_verts[58],
  Archimedean_truncated_icosahedron_verts[59]
 }
 texture_list {
  2,
  texture { Tex5 },
  texture { Tex6 }
 }
 face_indices {
  116,
  <0, 3, 8>, 0,
  <0, 8, 5>, 0,
  <0, 5, 1>, 0,
  <2, 7, 15>, 0,
  <2, 15, 13>, 0,
  <2, 13, 6>, 0,
  <4, 10, 18>, 0,
  <4, 18, 20>, 0,
  <4, 20, 11>, 0,
  <9, 14, 23>, 0,
  <9, 23, 27>, 0,
  <9, 27, 17>, 0,
  <12, 21, 31>, 0,
  <12, 31, 29>, 0,
  <12, 29, 19>, 0,
  <16, 26, 36>, 0,
  <16, 36, 35>, 0,
  <16, 35, 25>, 0,
  <22, 32, 42>, 0,
  <22, 42, 43>, 0,
  <22, 43, 33>, 0,
  <24, 30, 40>, 0,
  <24, 40, 44>, 0,
  <24, 44, 34>, 0,
  <28, 39, 49>, 0,
  <28, 49, 48>, 0,
  <28, 48, 38>, 0,
  <37, 47, 55>, 0,
  <37, 55, 54>, 0,
  <37, 54, 46>, 0,
  <41, 45, 53>, 0,
  <41, 53, 57>, 0,
  <41, 57, 50>, 0,
  <51, 52, 56>, 0,
  <51, 56, 59>, 0,
  <51, 59, 58>, 0,
  <0, 1, 4>, 1,
  <0, 4, 11>, 1,
  <0, 11, 7>, 1,
  <0, 7, 2>, 1,
  <0, 2, 6>, 1,
  <0, 6, 14>, 1,
  <0, 14, 9>, 1,
  <0, 9, 3>, 1,
  <1, 5, 12>, 1,
  <1, 12, 19>, 1,
  <1, 19, 10>, 1,
  <1, 10, 4>, 1,
  <3, 9, 17>, 1,
  <3, 17, 26>, 1,
  <3, 26, 16>, 1,
  <3, 16, 8>, 1,
  <5, 8, 16>, 1,
  <5, 16, 25>, 1,
  <5, 25, 21>, 1,
  <5, 21, 12>, 1,
  <6, 13, 22>, 1,
  <6, 22, 33>, 1,
  <6, 33, 23>, 1,
  <6, 23, 14>, 1,
  <7, 11, 20>, 1,
  <7, 20, 30>, 1,
  <7, 30, 24>, 1,
  <7, 24, 15>, 1,
  <10, 19, 29>, 1,
  <10, 29, 39>, 1,
  <10, 39, 28>, 1,
  <10, 28, 18>, 1,
  <13, 15, 24>, 1,
  <13, 24, 34>, 1,
  <13, 34, 32>, 1,
  <13, 32, 22>, 1,
  <17, 27, 37>, 1,
  <17, 37, 46>, 1,
  <17, 46, 36>, 1,
  <17, 36, 26>, 1,
  <18, 28, 38>, 1,
  <18, 38, 40>, 1,
  <18, 40, 30>, 1,
  <18, 30, 20>, 1,
  <21, 25, 35>, 1,
  <21, 35, 45>, 1,
  <21, 45, 41>, 1,
  <21, 41, 31>, 1,
  <23, 33, 43>, 1,
  <23, 43, 47>, 1,
  <23, 47, 37>, 1,
  <23, 37, 27>, 1,
  <29, 31, 41>, 1,
  <29, 41, 50>, 1,
  <29, 50, 49>, 1,
  <29, 49, 39>, 1,
  <32, 34, 44>, 1,
  <32, 44, 52>, 1,
  <32, 52, 51>, 1,
  <32, 51, 42>, 1,
  <35, 36, 46>, 1,
  <35, 46, 54>, 1,
  <35, 54, 53>, 1,
  <35, 53, 45>, 1,
  <38, 48, 56>, 1,
  <38, 56, 52>, 1,
  <38, 52, 44>, 1,
  <38, 44, 40>, 1,
  <42, 51, 58>, 1,
  <42, 58, 55>, 1,
  <42, 55, 47>, 1,
  <42, 47, 43>, 1,
  <48, 49, 50>, 1,
  <48, 50, 57>, 1,
  <48, 57, 59>, 1,
  <48, 59, 56>, 1,
  <53, 54, 55>, 1,
  <53, 55, 58>, 1,
  <53, 58, 59>, 1,
  <53, 59, 57>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_icosahedron_verts[53];
 #local P1 = Archimedean_truncated_icosahedron_verts[54];
 #local P2 = Archimedean_truncated_icosahedron_verts[55];
 #local P3 = Archimedean_truncated_icosahedron_verts[58];
 #local P4 = Archimedean_truncated_icosahedron_verts[59];
 #local P5 = Archimedean_truncated_icosahedron_verts[57];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_icosahedron_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_icosahedron_obj }
#end
#end

#macro Archimedean_truncated_icosahedron_faces2(OnPlane)
#local Archimedean_truncated_icosahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_truncated_icosahedron_verts[0],
  Archimedean_truncated_icosahedron_verts[1],
  Archimedean_truncated_icosahedron_verts[2],
  Archimedean_truncated_icosahedron_verts[3],
  Archimedean_truncated_icosahedron_verts[4],
  Archimedean_truncated_icosahedron_verts[5],
  Archimedean_truncated_icosahedron_verts[6],
  Archimedean_truncated_icosahedron_verts[7],
  Archimedean_truncated_icosahedron_verts[8],
  Archimedean_truncated_icosahedron_verts[9],
  Archimedean_truncated_icosahedron_verts[10],
  Archimedean_truncated_icosahedron_verts[11],
  Archimedean_truncated_icosahedron_verts[12],
  Archimedean_truncated_icosahedron_verts[13],
  Archimedean_truncated_icosahedron_verts[14],
  Archimedean_truncated_icosahedron_verts[15],
  Archimedean_truncated_icosahedron_verts[16],
  Archimedean_truncated_icosahedron_verts[17],
  Archimedean_truncated_icosahedron_verts[18],
  Archimedean_truncated_icosahedron_verts[19],
  Archimedean_truncated_icosahedron_verts[20],
  Archimedean_truncated_icosahedron_verts[21],
  Archimedean_truncated_icosahedron_verts[22],
  Archimedean_truncated_icosahedron_verts[23],
  Archimedean_truncated_icosahedron_verts[24],
  Archimedean_truncated_icosahedron_verts[25],
  Archimedean_truncated_icosahedron_verts[26],
  Archimedean_truncated_icosahedron_verts[27],
  Archimedean_truncated_icosahedron_verts[28],
  Archimedean_truncated_icosahedron_verts[29],
  Archimedean_truncated_icosahedron_verts[30],
  Archimedean_truncated_icosahedron_verts[31],
  Archimedean_truncated_icosahedron_verts[32],
  Archimedean_truncated_icosahedron_verts[33],
  Archimedean_truncated_icosahedron_verts[34],
  Archimedean_truncated_icosahedron_verts[35],
  Archimedean_truncated_icosahedron_verts[36],
  Archimedean_truncated_icosahedron_verts[37],
  Archimedean_truncated_icosahedron_verts[38],
  Archimedean_truncated_icosahedron_verts[39],
  Archimedean_truncated_icosahedron_verts[40],
  Archimedean_truncated_icosahedron_verts[41],
  Archimedean_truncated_icosahedron_verts[42],
  Archimedean_truncated_icosahedron_verts[43],
  Archimedean_truncated_icosahedron_verts[44],
  Archimedean_truncated_icosahedron_verts[45],
  Archimedean_truncated_icosahedron_verts[46],
  Archimedean_truncated_icosahedron_verts[47],
  Archimedean_truncated_icosahedron_verts[48],
  Archimedean_truncated_icosahedron_verts[49],
  Archimedean_truncated_icosahedron_verts[50],
  Archimedean_truncated_icosahedron_verts[51],
  Archimedean_truncated_icosahedron_verts[52],
  Archimedean_truncated_icosahedron_verts[53],
  Archimedean_truncated_icosahedron_verts[54],
  Archimedean_truncated_icosahedron_verts[55],
  Archimedean_truncated_icosahedron_verts[56],
  Archimedean_truncated_icosahedron_verts[57],
  Archimedean_truncated_icosahedron_verts[58],
  Archimedean_truncated_icosahedron_verts[59]
 }
 face_indices {
  116,
  <0, 3, 8>,
  <0, 8, 5>,
  <0, 5, 1>,
  <2, 7, 15>,
  <2, 15, 13>,
  <2, 13, 6>,
  <4, 10, 18>,
  <4, 18, 20>,
  <4, 20, 11>,
  <9, 14, 23>,
  <9, 23, 27>,
  <9, 27, 17>,
  <12, 21, 31>,
  <12, 31, 29>,
  <12, 29, 19>,
  <16, 26, 36>,
  <16, 36, 35>,
  <16, 35, 25>,
  <22, 32, 42>,
  <22, 42, 43>,
  <22, 43, 33>,
  <24, 30, 40>,
  <24, 40, 44>,
  <24, 44, 34>,
  <28, 39, 49>,
  <28, 49, 48>,
  <28, 48, 38>,
  <37, 47, 55>,
  <37, 55, 54>,
  <37, 54, 46>,
  <41, 45, 53>,
  <41, 53, 57>,
  <41, 57, 50>,
  <51, 52, 56>,
  <51, 56, 59>,
  <51, 59, 58>,
  <0, 1, 4>,
  <0, 4, 11>,
  <0, 11, 7>,
  <0, 7, 2>,
  <0, 2, 6>,
  <0, 6, 14>,
  <0, 14, 9>,
  <0, 9, 3>,
  <1, 5, 12>,
  <1, 12, 19>,
  <1, 19, 10>,
  <1, 10, 4>,
  <3, 9, 17>,
  <3, 17, 26>,
  <3, 26, 16>,
  <3, 16, 8>,
  <5, 8, 16>,
  <5, 16, 25>,
  <5, 25, 21>,
  <5, 21, 12>,
  <6, 13, 22>,
  <6, 22, 33>,
  <6, 33, 23>,
  <6, 23, 14>,
  <7, 11, 20>,
  <7, 20, 30>,
  <7, 30, 24>,
  <7, 24, 15>,
  <10, 19, 29>,
  <10, 29, 39>,
  <10, 39, 28>,
  <10, 28, 18>,
  <13, 15, 24>,
  <13, 24, 34>,
  <13, 34, 32>,
  <13, 32, 22>,
  <17, 27, 37>,
  <17, 37, 46>,
  <17, 46, 36>,
  <17, 36, 26>,
  <18, 28, 38>,
  <18, 38, 40>,
  <18, 40, 30>,
  <18, 30, 20>,
  <21, 25, 35>,
  <21, 35, 45>,
  <21, 45, 41>,
  <21, 41, 31>,
  <23, 33, 43>,
  <23, 43, 47>,
  <23, 47, 37>,
  <23, 37, 27>,
  <29, 31, 41>,
  <29, 41, 50>,
  <29, 50, 49>,
  <29, 49, 39>,
  <32, 34, 44>,
  <32, 44, 52>,
  <32, 52, 51>,
  <32, 51, 42>,
  <35, 36, 46>,
  <35, 46, 54>,
  <35, 54, 53>,
  <35, 53, 45>,
  <38, 48, 56>,
  <38, 56, 52>,
  <38, 52, 44>,
  <38, 44, 40>,
  <42, 51, 58>,
  <42, 58, 55>,
  <42, 55, 47>,
  <42, 47, 43>,
  <48, 49, 50>,
  <48, 50, 57>,
  <48, 57, 59>,
  <48, 59, 56>,
  <53, 54, 55>,
  <53, 55, 58>,
  <53, 58, 59>,
  <53, 59, 57>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_icosahedron_verts[53];
 #local P1 = Archimedean_truncated_icosahedron_verts[54];
 #local P2 = Archimedean_truncated_icosahedron_verts[55];
 #local P3 = Archimedean_truncated_icosahedron_verts[58];
 #local P4 = Archimedean_truncated_icosahedron_verts[59];
 #local P5 = Archimedean_truncated_icosahedron_verts[57];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_icosahedron_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_icosahedron_obj }
#end
#end

#macro Archimedean_truncated_icosahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_truncated_icosahedron_verts[0], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[1], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[2], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[3], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[4], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[5], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[6], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[7], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[8], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[9], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[10], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[11], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[12], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[13], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[14], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[15], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[16], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[17], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[18], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[19], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[20], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[21], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[22], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[23], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[24], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[25], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[26], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[27], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[28], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[29], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[30], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[31], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[32], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[33], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[34], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[35], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[36], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[37], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[38], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[39], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[40], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[41], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[42], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[43], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[44], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[45], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[46], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[47], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[48], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[49], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[50], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[51], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[52], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[53], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[54], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[55], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[56], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[57], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[58], RadVer }
  sphere { Archimedean_truncated_icosahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_truncated_icosahedron_verts[0], Archimedean_truncated_icosahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[3], Archimedean_truncated_icosahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[8], Archimedean_truncated_icosahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[5], Archimedean_truncated_icosahedron_verts[1], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[1], Archimedean_truncated_icosahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[2], Archimedean_truncated_icosahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[7], Archimedean_truncated_icosahedron_verts[15], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[15], Archimedean_truncated_icosahedron_verts[13], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[13], Archimedean_truncated_icosahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[6], Archimedean_truncated_icosahedron_verts[2], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[4], Archimedean_truncated_icosahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[10], Archimedean_truncated_icosahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[18], Archimedean_truncated_icosahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[20], Archimedean_truncated_icosahedron_verts[11], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[11], Archimedean_truncated_icosahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[9], Archimedean_truncated_icosahedron_verts[14], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[14], Archimedean_truncated_icosahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[23], Archimedean_truncated_icosahedron_verts[27], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[27], Archimedean_truncated_icosahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[17], Archimedean_truncated_icosahedron_verts[9], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[12], Archimedean_truncated_icosahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[21], Archimedean_truncated_icosahedron_verts[31], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[31], Archimedean_truncated_icosahedron_verts[29], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[29], Archimedean_truncated_icosahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[19], Archimedean_truncated_icosahedron_verts[12], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[16], Archimedean_truncated_icosahedron_verts[26], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[26], Archimedean_truncated_icosahedron_verts[36], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[36], Archimedean_truncated_icosahedron_verts[35], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[35], Archimedean_truncated_icosahedron_verts[25], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[25], Archimedean_truncated_icosahedron_verts[16], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[22], Archimedean_truncated_icosahedron_verts[32], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[32], Archimedean_truncated_icosahedron_verts[42], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[42], Archimedean_truncated_icosahedron_verts[43], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[43], Archimedean_truncated_icosahedron_verts[33], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[33], Archimedean_truncated_icosahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[24], Archimedean_truncated_icosahedron_verts[30], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[30], Archimedean_truncated_icosahedron_verts[40], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[40], Archimedean_truncated_icosahedron_verts[44], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[44], Archimedean_truncated_icosahedron_verts[34], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[34], Archimedean_truncated_icosahedron_verts[24], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[28], Archimedean_truncated_icosahedron_verts[39], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[39], Archimedean_truncated_icosahedron_verts[49], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[49], Archimedean_truncated_icosahedron_verts[48], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[48], Archimedean_truncated_icosahedron_verts[38], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[38], Archimedean_truncated_icosahedron_verts[28], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[37], Archimedean_truncated_icosahedron_verts[47], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[47], Archimedean_truncated_icosahedron_verts[55], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[55], Archimedean_truncated_icosahedron_verts[54], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[54], Archimedean_truncated_icosahedron_verts[46], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[46], Archimedean_truncated_icosahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[41], Archimedean_truncated_icosahedron_verts[45], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[45], Archimedean_truncated_icosahedron_verts[53], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[53], Archimedean_truncated_icosahedron_verts[57], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[57], Archimedean_truncated_icosahedron_verts[50], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[50], Archimedean_truncated_icosahedron_verts[41], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[51], Archimedean_truncated_icosahedron_verts[52], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[52], Archimedean_truncated_icosahedron_verts[56], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[56], Archimedean_truncated_icosahedron_verts[59], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[59], Archimedean_truncated_icosahedron_verts[58], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[58], Archimedean_truncated_icosahedron_verts[51], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[1], Archimedean_truncated_icosahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[11], Archimedean_truncated_icosahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[2], Archimedean_truncated_icosahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[6], Archimedean_truncated_icosahedron_verts[14], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[9], Archimedean_truncated_icosahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[5], Archimedean_truncated_icosahedron_verts[12], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[19], Archimedean_truncated_icosahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[17], Archimedean_truncated_icosahedron_verts[26], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[16], Archimedean_truncated_icosahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[25], Archimedean_truncated_icosahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[13], Archimedean_truncated_icosahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[33], Archimedean_truncated_icosahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[20], Archimedean_truncated_icosahedron_verts[30], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[24], Archimedean_truncated_icosahedron_verts[15], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[29], Archimedean_truncated_icosahedron_verts[39], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[28], Archimedean_truncated_icosahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[34], Archimedean_truncated_icosahedron_verts[32], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[27], Archimedean_truncated_icosahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[46], Archimedean_truncated_icosahedron_verts[36], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[38], Archimedean_truncated_icosahedron_verts[40], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[35], Archimedean_truncated_icosahedron_verts[45], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[41], Archimedean_truncated_icosahedron_verts[31], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[43], Archimedean_truncated_icosahedron_verts[47], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[50], Archimedean_truncated_icosahedron_verts[49], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[44], Archimedean_truncated_icosahedron_verts[52], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[51], Archimedean_truncated_icosahedron_verts[42], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[54], Archimedean_truncated_icosahedron_verts[53], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[48], Archimedean_truncated_icosahedron_verts[56], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[58], Archimedean_truncated_icosahedron_verts[55], RadEdg }
  cylinder { Archimedean_truncated_icosahedron_verts[57], Archimedean_truncated_icosahedron_verts[59], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_truncated_icosahedron_verts[53];
 #local P1 = Archimedean_truncated_icosahedron_verts[54];
 #local P2 = Archimedean_truncated_icosahedron_verts[55];
 #local P3 = Archimedean_truncated_icosahedron_verts[58];
 #local P4 = Archimedean_truncated_icosahedron_verts[59];
 #local P5 = Archimedean_truncated_icosahedron_verts[57];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_rhombicosidodecahedron_verts = array[60]
{
<0, 0, 1.026054>,
<0.447838, 0, 0.9231617>,
<-0.02363976, 0.4472136, 0.9231617>,
<-0.4050732, 0.190983, 0.9231617>,
<-0.1693344, -0.4145898, 0.9231617>,
<0.4241982, 0.4472136, 0.8202696>,
<0.7673818, 0.190983, 0.6537868>,
<0.5552827, -0.4145898, 0.7566788>,
<-0.2312241, 0.7562306, 0.6537868>,
<-0.5744076, -0.2236068, 0.8202696>,
<-0.6126576, 0.5, 0.6537868>,
<0.1738492, -0.6708204, 0.7566788>,
<-0.4669629, -0.6381966, 0.6537868>,
<0.493393, 0.7562306, 0.4873039>,
<0.8748265, -0.2236068, 0.4873039>,
<0.8365765, 0.5, 0.320821>,
<0.7054921, -0.6381966, 0.3844118>,
<0.08831973, 0.9472136, 0.3844118>,
<-0.5434628, 0.809017, 0.320821>,
<-0.8866463, -0.1708204, 0.4873039>,
<-0.9102861, 0.2763932, 0.3844118>,
<-0.1237794, -0.8944272, 0.4873039>,
<0.3240586, -0.8944272, 0.3844118>,
<-0.7792016, -0.5854102, 0.320821>
<0.6289922, 0.809017, 0.05144604>,
<1.010426, -0.1708204, 0.05144604>,
<0.9867859, 0.2763932, -0.05144604>,
<0.8410913, -0.5854102, -0.05144604>,
<-0.223919, 1., 0.05144604>,
<0.223919, 1., -0.05144604>,
<-0.8410913, 0.5854102, 0.05144604>,
<-0.9867859, -0.2763932, 0.05144604>,
<-1.010426, 0.1708204, -0.05144604>,
<-0.223919, -1., 0.05144604>,
<0.223919, -1., -0.05144604>,
<-0.6289922, -0.809017, -0.05144604>,
<0.7792016, 0.5854102, -0.320821>,
<0.9102861, -0.2763932, -0.3844118>,
<0.8866463, 0.1708204, -0.4873039>,
<0.5434628, -0.809017, -0.320821>,
<-0.3240586, 0.8944272, -0.3844118>,
<0.1237794, 0.8944272, -0.4873039>,
<-0.7054921, 0.6381966, -0.3844118>,
<-0.8365765, -0.5, -0.320821>,
<-0.8748265, 0.2236068, -0.4873039>,
<-0.08831973, -0.9472136, -0.3844118>,
<-0.493393, -0.7562306, -0.4873039>,
<0.4669629, 0.6381966, -0.6537868>,
<0.6126576, -0.5, -0.6537868>,
<0.5744076, 0.2236068, -0.8202696>,
<0.2312241, -0.7562306, -0.6537868>,
<-0.1738492, 0.6708204, -0.7566788>,
<-0.5552827, 0.4145898, -0.7566788>,
<-0.7673818, -0.190983, -0.6537868>,
<-0.4241982, -0.4472136, -0.8202696>,
<0.1693344, 0.4145898, -0.9231617>,
<0.4050732, -0.190983, -0.9231617>,
<0.02363976, -0.4472136, -0.9231617>,
<-0.447838, 0, -0.9231617>,
<0, 0, -1.026054>,
}
#local P0 = Archimedean_rhombicosidodecahedron_verts[51];
#local P1 = Archimedean_rhombicosidodecahedron_verts[55];
#local P2 = Archimedean_rhombicosidodecahedron_verts[59];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 60)
 #declare Archimedean_rhombicosidodecahedron_verts[Num] = vtransform(Archimedean_rhombicosidodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, OnPlane)
#local Archimedean_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_rhombicosidodecahedron_verts[0],
  Archimedean_rhombicosidodecahedron_verts[1],
  Archimedean_rhombicosidodecahedron_verts[2],
  Archimedean_rhombicosidodecahedron_verts[3],
  Archimedean_rhombicosidodecahedron_verts[4],
  Archimedean_rhombicosidodecahedron_verts[5],
  Archimedean_rhombicosidodecahedron_verts[6],
  Archimedean_rhombicosidodecahedron_verts[7],
  Archimedean_rhombicosidodecahedron_verts[8],
  Archimedean_rhombicosidodecahedron_verts[9],
  Archimedean_rhombicosidodecahedron_verts[10],
  Archimedean_rhombicosidodecahedron_verts[11],
  Archimedean_rhombicosidodecahedron_verts[12],
  Archimedean_rhombicosidodecahedron_verts[13],
  Archimedean_rhombicosidodecahedron_verts[14],
  Archimedean_rhombicosidodecahedron_verts[15],
  Archimedean_rhombicosidodecahedron_verts[16],
  Archimedean_rhombicosidodecahedron_verts[17],
  Archimedean_rhombicosidodecahedron_verts[18],
  Archimedean_rhombicosidodecahedron_verts[19],
  Archimedean_rhombicosidodecahedron_verts[20],
  Archimedean_rhombicosidodecahedron_verts[21],
  Archimedean_rhombicosidodecahedron_verts[22],
  Archimedean_rhombicosidodecahedron_verts[23],
  Archimedean_rhombicosidodecahedron_verts[24],
  Archimedean_rhombicosidodecahedron_verts[25],
  Archimedean_rhombicosidodecahedron_verts[26],
  Archimedean_rhombicosidodecahedron_verts[27],
  Archimedean_rhombicosidodecahedron_verts[28],
  Archimedean_rhombicosidodecahedron_verts[29],
  Archimedean_rhombicosidodecahedron_verts[30],
  Archimedean_rhombicosidodecahedron_verts[31],
  Archimedean_rhombicosidodecahedron_verts[32],
  Archimedean_rhombicosidodecahedron_verts[33],
  Archimedean_rhombicosidodecahedron_verts[34],
  Archimedean_rhombicosidodecahedron_verts[35],
  Archimedean_rhombicosidodecahedron_verts[36],
  Archimedean_rhombicosidodecahedron_verts[37],
  Archimedean_rhombicosidodecahedron_verts[38],
  Archimedean_rhombicosidodecahedron_verts[39],
  Archimedean_rhombicosidodecahedron_verts[40],
  Archimedean_rhombicosidodecahedron_verts[41],
  Archimedean_rhombicosidodecahedron_verts[42],
  Archimedean_rhombicosidodecahedron_verts[43],
  Archimedean_rhombicosidodecahedron_verts[44],
  Archimedean_rhombicosidodecahedron_verts[45],
  Archimedean_rhombicosidodecahedron_verts[46],
  Archimedean_rhombicosidodecahedron_verts[47],
  Archimedean_rhombicosidodecahedron_verts[48],
  Archimedean_rhombicosidodecahedron_verts[49],
  Archimedean_rhombicosidodecahedron_verts[50],
  Archimedean_rhombicosidodecahedron_verts[51],
  Archimedean_rhombicosidodecahedron_verts[52],
  Archimedean_rhombicosidodecahedron_verts[53],
  Archimedean_rhombicosidodecahedron_verts[54],
  Archimedean_rhombicosidodecahedron_verts[55],
  Archimedean_rhombicosidodecahedron_verts[56],
  Archimedean_rhombicosidodecahedron_verts[57],
  Archimedean_rhombicosidodecahedron_verts[58],
  Archimedean_rhombicosidodecahedron_verts[59]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  116,
  <0, 2, 3>, 0,
  <1, 6, 5>, 0,
  <4, 9, 12>, 0,
  <7, 16, 14>, 0,
  <8, 18, 10>, 0,
  <11, 21, 22>, 0,
  <13, 15, 24>, 0,
  <17, 29, 28>, 0,
  <19, 31, 23>, 0,
  <20, 30, 32>, 0,
  <25, 27, 37>, 0,
  <26, 38, 36>, 0,
  <33, 45, 34>, 0,
  <35, 43, 46>, 0,
  <39, 50, 48>, 0,
  <40, 41, 51>, 0,
  <42, 52, 44>, 0,
  <47, 49, 55>, 0,
  <53, 58, 54>, 0,
  <56, 57, 59>, 0,
  <0, 1, 5>, 1,
  <0, 5, 2>, 1,
  <0, 3, 9>, 1,
  <0, 9, 4>, 1,
  <1, 7, 14>, 1,
  <1, 14, 6>, 1,
  <2, 8, 10>, 1,
  <2, 10, 3>, 1,
  <4, 12, 21>, 1,
  <4, 21, 11>, 1,
  <5, 6, 15>, 1,
  <5, 15, 13>, 1,
  <7, 11, 22>, 1,
  <7, 22, 16>, 1,
  <8, 17, 28>, 1,
  <8, 28, 18>, 1,
  <9, 19, 23>, 1,
  <9, 23, 12>, 1,
  <10, 18, 30>, 1,
  <10, 30, 20>, 1,
  <13, 24, 29>, 1,
  <13, 29, 17>, 1,
  <14, 16, 27>, 1,
  <14, 27, 25>, 1,
  <15, 26, 36>, 1,
  <15, 36, 24>, 1,
  <19, 20, 32>, 1,
  <19, 32, 31>, 1,
  <21, 33, 34>, 1,
  <21, 34, 22>, 1,
  <23, 31, 43>, 1,
  <23, 43, 35>, 1,
  <25, 37, 38>, 1,
  <25, 38, 26>, 1,
  <27, 39, 48>, 1,
  <27, 48, 37>, 1,
  <28, 29, 41>, 1,
  <28, 41, 40>, 1,
  <30, 42, 44>, 1,
  <30, 44, 32>, 1,
  <33, 35, 46>, 1,
  <33, 46, 45>, 1,
  <34, 45, 50>, 1,
  <34, 50, 39>, 1,
  <36, 38, 49>, 1,
  <36, 49, 47>, 1,
  <40, 51, 52>, 1,
  <40, 52, 42>, 1,
  <41, 47, 55>, 1,
  <41, 55, 51>, 1,
  <43, 53, 54>, 1,
  <43, 54, 46>, 1,
  <44, 52, 58>, 1,
  <44, 58, 53>, 1,
  <48, 50, 57>, 1,
  <48, 57, 56>, 1,
  <49, 56, 59>, 1,
  <49, 59, 55>, 1,
  <54, 58, 59>, 1,
  <54, 59, 57>, 1,
  <0, 4, 11>, 2,
  <0, 11, 7>, 2,
  <0, 7, 1>, 2,
  <2, 5, 13>, 2,
  <2, 13, 17>, 2,
  <2, 17, 8>, 2,
  <3, 10, 20>, 2,
  <3, 20, 19>, 2,
  <3, 19, 9>, 2,
  <6, 14, 25>, 2,
  <6, 25, 26>, 2,
  <6, 26, 15>, 2,
  <12, 23, 35>, 2,
  <12, 35, 33>, 2,
  <12, 33, 21>, 2,
  <16, 22, 34>, 2,
  <16, 34, 39>, 2,
  <16, 39, 27>, 2,
  <18, 28, 40>, 2,
  <18, 40, 42>, 2,
  <18, 42, 30>, 2,
  <24, 36, 47>, 2,
  <24, 47, 41>, 2,
  <24, 41, 29>, 2,
  <31, 32, 44>, 2,
  <31, 44, 53>, 2,
  <31, 53, 43>, 2,
  <37, 48, 56>, 2,
  <37, 56, 49>, 2,
  <37, 49, 38>, 2,
  <45, 46, 54>, 2,
  <45, 54, 57>, 2,
  <45, 57, 50>, 2,
  <51, 55, 59>, 2,
  <51, 59, 58>, 2,
  <51, 58, 52>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_rhombicosidodecahedron_verts[51];
 #local P1 = Archimedean_rhombicosidodecahedron_verts[55];
 #local P2 = Archimedean_rhombicosidodecahedron_verts[59];
 #local P3 = Archimedean_rhombicosidodecahedron_verts[58];
 #local P4 = Archimedean_rhombicosidodecahedron_verts[52];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_rhombicosidodecahedron_obj }
#end
#end

#macro Archimedean_rhombicosidodecahedron_faces2(OnPlane)
#local Archimedean_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_rhombicosidodecahedron_verts[0],
  Archimedean_rhombicosidodecahedron_verts[1],
  Archimedean_rhombicosidodecahedron_verts[2],
  Archimedean_rhombicosidodecahedron_verts[3],
  Archimedean_rhombicosidodecahedron_verts[4],
  Archimedean_rhombicosidodecahedron_verts[5],
  Archimedean_rhombicosidodecahedron_verts[6],
  Archimedean_rhombicosidodecahedron_verts[7],
  Archimedean_rhombicosidodecahedron_verts[8],
  Archimedean_rhombicosidodecahedron_verts[9],
  Archimedean_rhombicosidodecahedron_verts[10],
  Archimedean_rhombicosidodecahedron_verts[11],
  Archimedean_rhombicosidodecahedron_verts[12],
  Archimedean_rhombicosidodecahedron_verts[13],
  Archimedean_rhombicosidodecahedron_verts[14],
  Archimedean_rhombicosidodecahedron_verts[15],
  Archimedean_rhombicosidodecahedron_verts[16],
  Archimedean_rhombicosidodecahedron_verts[17],
  Archimedean_rhombicosidodecahedron_verts[18],
  Archimedean_rhombicosidodecahedron_verts[19],
  Archimedean_rhombicosidodecahedron_verts[20],
  Archimedean_rhombicosidodecahedron_verts[21],
  Archimedean_rhombicosidodecahedron_verts[22],
  Archimedean_rhombicosidodecahedron_verts[23],
  Archimedean_rhombicosidodecahedron_verts[24],
  Archimedean_rhombicosidodecahedron_verts[25],
  Archimedean_rhombicosidodecahedron_verts[26],
  Archimedean_rhombicosidodecahedron_verts[27],
  Archimedean_rhombicosidodecahedron_verts[28],
  Archimedean_rhombicosidodecahedron_verts[29],
  Archimedean_rhombicosidodecahedron_verts[30],
  Archimedean_rhombicosidodecahedron_verts[31],
  Archimedean_rhombicosidodecahedron_verts[32],
  Archimedean_rhombicosidodecahedron_verts[33],
  Archimedean_rhombicosidodecahedron_verts[34],
  Archimedean_rhombicosidodecahedron_verts[35],
  Archimedean_rhombicosidodecahedron_verts[36],
  Archimedean_rhombicosidodecahedron_verts[37],
  Archimedean_rhombicosidodecahedron_verts[38],
  Archimedean_rhombicosidodecahedron_verts[39],
  Archimedean_rhombicosidodecahedron_verts[40],
  Archimedean_rhombicosidodecahedron_verts[41],
  Archimedean_rhombicosidodecahedron_verts[42],
  Archimedean_rhombicosidodecahedron_verts[43],
  Archimedean_rhombicosidodecahedron_verts[44],
  Archimedean_rhombicosidodecahedron_verts[45],
  Archimedean_rhombicosidodecahedron_verts[46],
  Archimedean_rhombicosidodecahedron_verts[47],
  Archimedean_rhombicosidodecahedron_verts[48],
  Archimedean_rhombicosidodecahedron_verts[49],
  Archimedean_rhombicosidodecahedron_verts[50],
  Archimedean_rhombicosidodecahedron_verts[51],
  Archimedean_rhombicosidodecahedron_verts[52],
  Archimedean_rhombicosidodecahedron_verts[53],
  Archimedean_rhombicosidodecahedron_verts[54],
  Archimedean_rhombicosidodecahedron_verts[55],
  Archimedean_rhombicosidodecahedron_verts[56],
  Archimedean_rhombicosidodecahedron_verts[57],
  Archimedean_rhombicosidodecahedron_verts[58],
  Archimedean_rhombicosidodecahedron_verts[59]
 }
 face_indices {
  116,
  <0, 2, 3>,
  <1, 6, 5>,
  <4, 9, 12>,
  <7, 16, 14>,
  <8, 18, 10>,
  <11, 21, 22>,
  <13, 15, 24>,
  <17, 29, 28>,
  <19, 31, 23>,
  <20, 30, 32>,
  <25, 27, 37>,
  <26, 38, 36>,
  <33, 45, 34>,
  <35, 43, 46>,
  <39, 50, 48>,
  <40, 41, 51>,
  <42, 52, 44>,
  <47, 49, 55>,
  <53, 58, 54>,
  <56, 57, 59>,
  <0, 1, 5>,
  <0, 5, 2>,
  <0, 3, 9>,
  <0, 9, 4>,
  <1, 7, 14>,
  <1, 14, 6>,
  <2, 8, 10>,
  <2, 10, 3>,
  <4, 12, 21>,
  <4, 21, 11>,
  <5, 6, 15>,
  <5, 15, 13>,
  <7, 11, 22>,
  <7, 22, 16>,
  <8, 17, 28>,
  <8, 28, 18>,
  <9, 19, 23>,
  <9, 23, 12>,
  <10, 18, 30>,
  <10, 30, 20>,
  <13, 24, 29>,
  <13, 29, 17>,
  <14, 16, 27>,
  <14, 27, 25>,
  <15, 26, 36>,
  <15, 36, 24>,
  <19, 20, 32>,
  <19, 32, 31>,
  <21, 33, 34>,
  <21, 34, 22>,
  <23, 31, 43>,
  <23, 43, 35>,
  <25, 37, 38>,
  <25, 38, 26>,
  <27, 39, 48>,
  <27, 48, 37>,
  <28, 29, 41>,
  <28, 41, 40>,
  <30, 42, 44>,
  <30, 44, 32>,
  <33, 35, 46>,
  <33, 46, 45>,
  <34, 45, 50>,
  <34, 50, 39>,
  <36, 38, 49>,
  <36, 49, 47>,
  <40, 51, 52>,
  <40, 52, 42>,
  <41, 47, 55>,
  <41, 55, 51>,
  <43, 53, 54>,
  <43, 54, 46>,
  <44, 52, 58>,
  <44, 58, 53>,
  <48, 50, 57>,
  <48, 57, 56>,
  <49, 56, 59>,
  <49, 59, 55>,
  <54, 58, 59>,
  <54, 59, 57>,
  <0, 4, 11>,
  <0, 11, 7>,
  <0, 7, 1>,
  <2, 5, 13>,
  <2, 13, 17>,
  <2, 17, 8>,
  <3, 10, 20>,
  <3, 20, 19>,
  <3, 19, 9>,
  <6, 14, 25>,
  <6, 25, 26>,
  <6, 26, 15>,
  <12, 23, 35>,
  <12, 35, 33>,
  <12, 33, 21>,
  <16, 22, 34>,
  <16, 34, 39>,
  <16, 39, 27>,
  <18, 28, 40>,
  <18, 40, 42>,
  <18, 42, 30>,
  <24, 36, 47>,
  <24, 47, 41>,
  <24, 41, 29>,
  <31, 32, 44>,
  <31, 44, 53>,
  <31, 53, 43>,
  <37, 48, 56>,
  <37, 56, 49>,
  <37, 49, 38>,
  <45, 46, 54>,
  <45, 54, 57>,
  <45, 57, 50>,
  <51, 55, 59>,
  <51, 59, 58>,
  <51, 58, 52>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_rhombicosidodecahedron_verts[51];
 #local P1 = Archimedean_rhombicosidodecahedron_verts[55];
 #local P2 = Archimedean_rhombicosidodecahedron_verts[59];
 #local P3 = Archimedean_rhombicosidodecahedron_verts[58];
 #local P4 = Archimedean_rhombicosidodecahedron_verts[52];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_rhombicosidodecahedron_obj }
#end
#end

#macro Archimedean_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[54], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[55], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[56], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[57], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[58], RadVer }
  sphere { Archimedean_rhombicosidodecahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_rhombicosidodecahedron_verts[0], Archimedean_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[2], Archimedean_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[3], Archimedean_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[1], Archimedean_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[6], Archimedean_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[5], Archimedean_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[4], Archimedean_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[9], Archimedean_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[12], Archimedean_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[7], Archimedean_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[16], Archimedean_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[14], Archimedean_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[8], Archimedean_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[18], Archimedean_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[10], Archimedean_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[11], Archimedean_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[21], Archimedean_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[22], Archimedean_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[13], Archimedean_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[15], Archimedean_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[24], Archimedean_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[17], Archimedean_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[29], Archimedean_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[28], Archimedean_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[19], Archimedean_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[31], Archimedean_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[23], Archimedean_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[20], Archimedean_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[30], Archimedean_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[32], Archimedean_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[25], Archimedean_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[27], Archimedean_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[37], Archimedean_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[26], Archimedean_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[38], Archimedean_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[36], Archimedean_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[33], Archimedean_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[45], Archimedean_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[34], Archimedean_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[35], Archimedean_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[43], Archimedean_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[46], Archimedean_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[39], Archimedean_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[50], Archimedean_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[48], Archimedean_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[40], Archimedean_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[41], Archimedean_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[51], Archimedean_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[42], Archimedean_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[52], Archimedean_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[44], Archimedean_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[47], Archimedean_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[49], Archimedean_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[55], Archimedean_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[53], Archimedean_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[58], Archimedean_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[54], Archimedean_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[56], Archimedean_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[57], Archimedean_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[59], Archimedean_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[0], Archimedean_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[5], Archimedean_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[3], Archimedean_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[4], Archimedean_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[1], Archimedean_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[14], Archimedean_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[2], Archimedean_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[10], Archimedean_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[12], Archimedean_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[11], Archimedean_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[6], Archimedean_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[13], Archimedean_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[7], Archimedean_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[22], Archimedean_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[8], Archimedean_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[28], Archimedean_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[9], Archimedean_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[23], Archimedean_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[18], Archimedean_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[20], Archimedean_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[24], Archimedean_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[17], Archimedean_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[16], Archimedean_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[25], Archimedean_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[15], Archimedean_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[36], Archimedean_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[19], Archimedean_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[32], Archimedean_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[21], Archimedean_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[34], Archimedean_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[31], Archimedean_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[35], Archimedean_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[37], Archimedean_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[26], Archimedean_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[27], Archimedean_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[48], Archimedean_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[29], Archimedean_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[40], Archimedean_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[30], Archimedean_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[44], Archimedean_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[33], Archimedean_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[46], Archimedean_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[45], Archimedean_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[39], Archimedean_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[38], Archimedean_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[47], Archimedean_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[51], Archimedean_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[42], Archimedean_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[41], Archimedean_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[55], Archimedean_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[43], Archimedean_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[54], Archimedean_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[52], Archimedean_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[53], Archimedean_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[50], Archimedean_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[56], Archimedean_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[49], Archimedean_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[59], Archimedean_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[58], Archimedean_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Archimedean_rhombicosidodecahedron_verts[57], Archimedean_rhombicosidodecahedron_verts[54], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_rhombicosidodecahedron_verts[51];
 #local P1 = Archimedean_rhombicosidodecahedron_verts[55];
 #local P2 = Archimedean_rhombicosidodecahedron_verts[59];
 #local P3 = Archimedean_rhombicosidodecahedron_verts[58];
 #local P4 = Archimedean_rhombicosidodecahedron_verts[52];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_truncated_icosidodecahedron_verts = array[120]
{
<0, 0, 1.008759>,
<0.2629922, 0, 0.973874>,
<-0.00462747, 0.2629515, 0.973874>,
<-0.2211363, -0.1423503, 0.973874>,
<0.2583647, 0.2629515, 0.9389886>,
<0.4673861, -0.1423503, 0.8825429>,
<-0.2303913, 0.3835526, 0.9041033>,
<-0.3159502, -0.372678, 0.8825429>,
<-0.4469001, -0.02174919, 0.9041033>,
<0.4581312, 0.3835526, 0.8127722>,
<0.5351104, -0.372678, 0.7696515>,
<0.6671526, -0.02174919, 0.7563265>,
<-0.3326926, 0.5786893, 0.7563265>,
<-0.4515276, 0.2412023, 0.8692179>,
<-0.541714, -0.2520769, 0.8127722>,
<-0.248226, -0.6030057, 0.7696515>,
<0.518368, 0.5786893, 0.6434351>,
<0.6625252, 0.2412023, 0.7214412>,
<0.7348768, -0.2520769, 0.6434351>,
<0.4402965, -0.6030057, 0.6783205>,
<-0.5538289, 0.436339, 0.7214412>,
<-0.2724557, 0.7738261, 0.5869894>,
<-0.6997536, -0.3618034, 0.6301101>,
<-0.04383203, -0.745356, 0.6783205>
<-0.4062656, -0.7127322, 0.5869894>,
<0.722762, 0.436339, 0.552104>,
<0.4160667, 0.7738261, 0.4956583>,
<0.8398294, -0.3618034, 0.4258876>,
<0.2191601, -0.745356, 0.6434351>,
<0.5452491, -0.7127322, 0.460773>,
<-0.7147284, 0.4891254, 0.5172187>,
<-0.07268925, 0.8944272, 0.460773>,
<-0.4333553, 0.8266125, 0.3827669>,
<-0.8606531, -0.309017, 0.4258876>,
<-0.6320294, -0.5921311, 0.5172187>,
<-0.2018716, -0.8550825, 0.4956583>,
<0.8248546, 0.4891254, 0.3129962>,
<0.1903029, 0.8944272, 0.4258876>,
<0.5181594, 0.8266125, 0.2565505>,
<0.9419221, -0.309017, 0.1867798>,
<0.7450156, -0.5921311, 0.3345566>,
<0.3241127, -0.8550825, 0.4258876>,
<-0.8727679, 0.3793989, 0.3345566>,
<-0.6544916, 0.6842621, 0.3478816>,
<-0.2335888, 0.9472136, 0.2565505>,
<-0.7929289, -0.5393447, 0.3129962>,
<-0.9629544, -0.1138803, 0.2781109>,
<-0.096919, -0.9648091, 0.2781109>,
<0.9298072, 0.3793989, 0.09544872>,
<0.7225533, 0.6842621, 0.1652194>,
<0.2923956, 0.9472136, 0.1867798>,
<0.8471082, -0.5393447, 0.09544872>,
<1.002159, -0.1138803, 0.01744268>,
<0.1660732, -0.9648091, 0.2432255>,
<-0.8125311, 0.5745356, 0.1652194>,
<-0.9675818, 0.1490712, 0.2432255>,
<-0.1314961, 1., 0.01744268>,
<-0.8275059, -0.5745356, 0.05232804>,
<-0.9975315, -0.1490712, 0.01744268>,
<-0.1314961, -1., 0.01744268>,
<0.8275059, 0.5745356, -0.05232804>,
<0.9975315, 0.1490712, -0.01744268>,
<0.1314961, 1., -0.01744268>,
<0.8125311, -0.5745356, -0.1652194>,
<0.9675818, -0.1490712, -0.2432255>,
<0.1314961, -1., -0.01744268>,
<-0.8471082, 0.5393447, -0.09544872>,
<-1.002159, 0.1138803, -0.01744268>,
<-0.1660732, 0.9648091, -0.2432255>,
<-0.7225533, -0.6842621, -0.1652194>,
<-0.9298072, -0.3793989, -0.09544872>,
<-0.2923956, -0.9472136, -0.1867798>,
<0.7929289, 0.5393447, -0.3129962>,
<0.9629544, 0.1138803, -0.2781109>,
<0.096919, 0.9648091, -0.2781109>,
<0.6544916, -0.6842621, -0.3478816>,
<0.8727679, -0.3793989, -0.3345566>,
<0.2335888, -0.9472136, -0.2565505>,
<-0.7450156, 0.5921311, -0.3345566>,
<-0.9419221, 0.309017, -0.1867798>,
<-0.3241127, 0.8550825, -0.4258876>,
<-0.8248546, -0.4891254, -0.3129962>,
<-0.5181594, -0.8266125, -0.2565505>,
<-0.1903029, -0.8944272, -0.4258876>,
<0.6320294, 0.5921311, -0.5172187>,
<0.8606531, 0.309017, -0.4258876>,
<0.2018716, 0.8550825, -0.4956583>,
<0.7147284, -0.4891254, -0.5172187>,
<0.4333553, -0.8266125, -0.3827669>,
<0.07268925, -0.8944272, -0.460773>,
<-0.8398294, 0.3618034, -0.4258876>,
<-0.5452491, 0.7127322, -0.460773>,
<-0.2191601, 0.745356, -0.6434351>,
<-0.722762, -0.436339, -0.552104>,
<-0.4160667, -0.7738261, -0.4956583>,
<0.6997536, 0.3618034, -0.6301101>,
<0.4062656, 0.7127322, -0.5869894>,
<0.04383203, 0.745356, -0.6783205>,
<0.5538289, -0.436339, -0.7214412>,
<0.2724557, -0.7738261, -0.5869894>,
<-0.7348768, 0.2520769, -0.6434351>,
<-0.4402965, 0.6030057, -0.6783205>,
<-0.6625252, -0.2412023, -0.7214412>,
<-0.518368, -0.5786893, -0.6434351>,
<0.541714, 0.2520769, -0.8127722>,
<0.248226, 0.6030057, -0.7696515>,
<0.4515276, -0.2412023, -0.8692179>,
<0.3326926, -0.5786893, -0.7563265>,
<-0.6671526, 0.02174919, -0.7563265>,
<-0.5351104, 0.372678, -0.7696515>,
<-0.4581312, -0.3835526, -0.8127722>,
<0.4469001, 0.02174919, -0.9041033>,
<0.3159502, 0.372678, -0.8825429>,
<0.2303913, -0.3835526, -0.9041033>,
<-0.4673861, 0.1423503, -0.8825429>,
<-0.2583647, -0.2629515, -0.9389886>,
<0.2211363, 0.1423503, -0.973874>,
<0.00462747, -0.2629515, -0.973874>,
<-0.2629922, 0, -0.973874>,
<0, 0, -1.008759>,
}
#local P0 = Archimedean_truncated_icosidodecahedron_verts[92];
#local P1 = Archimedean_truncated_icosidodecahedron_verts[97];
#local P2 = Archimedean_truncated_icosidodecahedron_verts[105];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 120)
 #declare Archimedean_truncated_icosidodecahedron_verts[Num] = vtransform(Archimedean_truncated_icosidodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_truncated_icosidodecahedron_faces(Tex4, Tex6, Tex10, OnPlane)
#local Archimedean_truncated_icosidodecahedron_obj = mesh2 {
 vertex_vectors {
  120,
  Archimedean_truncated_icosidodecahedron_verts[0],
  Archimedean_truncated_icosidodecahedron_verts[1],
  Archimedean_truncated_icosidodecahedron_verts[2],
  Archimedean_truncated_icosidodecahedron_verts[3],
  Archimedean_truncated_icosidodecahedron_verts[4],
  Archimedean_truncated_icosidodecahedron_verts[5],
  Archimedean_truncated_icosidodecahedron_verts[6],
  Archimedean_truncated_icosidodecahedron_verts[7],
  Archimedean_truncated_icosidodecahedron_verts[8],
  Archimedean_truncated_icosidodecahedron_verts[9],
  Archimedean_truncated_icosidodecahedron_verts[10],
  Archimedean_truncated_icosidodecahedron_verts[11],
  Archimedean_truncated_icosidodecahedron_verts[12],
  Archimedean_truncated_icosidodecahedron_verts[13],
  Archimedean_truncated_icosidodecahedron_verts[14],
  Archimedean_truncated_icosidodecahedron_verts[15],
  Archimedean_truncated_icosidodecahedron_verts[16],
  Archimedean_truncated_icosidodecahedron_verts[17],
  Archimedean_truncated_icosidodecahedron_verts[18],
  Archimedean_truncated_icosidodecahedron_verts[19],
  Archimedean_truncated_icosidodecahedron_verts[20],
  Archimedean_truncated_icosidodecahedron_verts[21],
  Archimedean_truncated_icosidodecahedron_verts[22],
  Archimedean_truncated_icosidodecahedron_verts[23],
  Archimedean_truncated_icosidodecahedron_verts[24],
  Archimedean_truncated_icosidodecahedron_verts[25],
  Archimedean_truncated_icosidodecahedron_verts[26],
  Archimedean_truncated_icosidodecahedron_verts[27],
  Archimedean_truncated_icosidodecahedron_verts[28],
  Archimedean_truncated_icosidodecahedron_verts[29],
  Archimedean_truncated_icosidodecahedron_verts[30],
  Archimedean_truncated_icosidodecahedron_verts[31],
  Archimedean_truncated_icosidodecahedron_verts[32],
  Archimedean_truncated_icosidodecahedron_verts[33],
  Archimedean_truncated_icosidodecahedron_verts[34],
  Archimedean_truncated_icosidodecahedron_verts[35],
  Archimedean_truncated_icosidodecahedron_verts[36],
  Archimedean_truncated_icosidodecahedron_verts[37],
  Archimedean_truncated_icosidodecahedron_verts[38],
  Archimedean_truncated_icosidodecahedron_verts[39],
  Archimedean_truncated_icosidodecahedron_verts[40],
  Archimedean_truncated_icosidodecahedron_verts[41],
  Archimedean_truncated_icosidodecahedron_verts[42],
  Archimedean_truncated_icosidodecahedron_verts[43],
  Archimedean_truncated_icosidodecahedron_verts[44],
  Archimedean_truncated_icosidodecahedron_verts[45],
  Archimedean_truncated_icosidodecahedron_verts[46],
  Archimedean_truncated_icosidodecahedron_verts[47],
  Archimedean_truncated_icosidodecahedron_verts[48],
  Archimedean_truncated_icosidodecahedron_verts[49],
  Archimedean_truncated_icosidodecahedron_verts[50],
  Archimedean_truncated_icosidodecahedron_verts[51],
  Archimedean_truncated_icosidodecahedron_verts[52],
  Archimedean_truncated_icosidodecahedron_verts[53],
  Archimedean_truncated_icosidodecahedron_verts[54],
  Archimedean_truncated_icosidodecahedron_verts[55],
  Archimedean_truncated_icosidodecahedron_verts[56],
  Archimedean_truncated_icosidodecahedron_verts[57],
  Archimedean_truncated_icosidodecahedron_verts[58],
  Archimedean_truncated_icosidodecahedron_verts[59],
  Archimedean_truncated_icosidodecahedron_verts[60],
  Archimedean_truncated_icosidodecahedron_verts[61],
  Archimedean_truncated_icosidodecahedron_verts[62],
  Archimedean_truncated_icosidodecahedron_verts[63],
  Archimedean_truncated_icosidodecahedron_verts[64],
  Archimedean_truncated_icosidodecahedron_verts[65],
  Archimedean_truncated_icosidodecahedron_verts[66],
  Archimedean_truncated_icosidodecahedron_verts[67],
  Archimedean_truncated_icosidodecahedron_verts[68],
  Archimedean_truncated_icosidodecahedron_verts[69],
  Archimedean_truncated_icosidodecahedron_verts[70],
  Archimedean_truncated_icosidodecahedron_verts[71],
  Archimedean_truncated_icosidodecahedron_verts[72],
  Archimedean_truncated_icosidodecahedron_verts[73],
  Archimedean_truncated_icosidodecahedron_verts[74],
  Archimedean_truncated_icosidodecahedron_verts[75],
  Archimedean_truncated_icosidodecahedron_verts[76],
  Archimedean_truncated_icosidodecahedron_verts[77],
  Archimedean_truncated_icosidodecahedron_verts[78],
  Archimedean_truncated_icosidodecahedron_verts[79],
  Archimedean_truncated_icosidodecahedron_verts[80],
  Archimedean_truncated_icosidodecahedron_verts[81],
  Archimedean_truncated_icosidodecahedron_verts[82],
  Archimedean_truncated_icosidodecahedron_verts[83],
  Archimedean_truncated_icosidodecahedron_verts[84],
  Archimedean_truncated_icosidodecahedron_verts[85],
  Archimedean_truncated_icosidodecahedron_verts[86],
  Archimedean_truncated_icosidodecahedron_verts[87],
  Archimedean_truncated_icosidodecahedron_verts[88],
  Archimedean_truncated_icosidodecahedron_verts[89],
  Archimedean_truncated_icosidodecahedron_verts[90],
  Archimedean_truncated_icosidodecahedron_verts[91],
  Archimedean_truncated_icosidodecahedron_verts[92],
  Archimedean_truncated_icosidodecahedron_verts[93],
  Archimedean_truncated_icosidodecahedron_verts[94],
  Archimedean_truncated_icosidodecahedron_verts[95],
  Archimedean_truncated_icosidodecahedron_verts[96],
  Archimedean_truncated_icosidodecahedron_verts[97],
  Archimedean_truncated_icosidodecahedron_verts[98],
  Archimedean_truncated_icosidodecahedron_verts[99],
  Archimedean_truncated_icosidodecahedron_verts[100],
  Archimedean_truncated_icosidodecahedron_verts[101],
  Archimedean_truncated_icosidodecahedron_verts[102],
  Archimedean_truncated_icosidodecahedron_verts[103],
  Archimedean_truncated_icosidodecahedron_verts[104],
  Archimedean_truncated_icosidodecahedron_verts[105],
  Archimedean_truncated_icosidodecahedron_verts[106],
  Archimedean_truncated_icosidodecahedron_verts[107],
  Archimedean_truncated_icosidodecahedron_verts[108],
  Archimedean_truncated_icosidodecahedron_verts[109],
  Archimedean_truncated_icosidodecahedron_verts[110],
  Archimedean_truncated_icosidodecahedron_verts[111],
  Archimedean_truncated_icosidodecahedron_verts[112],
  Archimedean_truncated_icosidodecahedron_verts[113],
  Archimedean_truncated_icosidodecahedron_verts[114],
  Archimedean_truncated_icosidodecahedron_verts[115],
  Archimedean_truncated_icosidodecahedron_verts[116],
  Archimedean_truncated_icosidodecahedron_verts[117],
  Archimedean_truncated_icosidodecahedron_verts[118],
  Archimedean_truncated_icosidodecahedron_verts[119]
 }
 texture_list {
  3,
  texture { Tex4 },
  texture { Tex6 },
  texture { Tex10 }
 }
 face_indices {
  236,
  <0, 1, 4>, 0,
  <0, 4, 2>, 0,
  <3, 8, 14>, 0,
  <3, 14, 7>, 0,
  <5, 10, 18>, 0,
  <5, 18, 11>, 0,
  <6, 12, 20>, 0,
  <6, 20, 13>, 0,
  <9, 17, 25>, 0,
  <9, 25, 16>, 0,
  <15, 24, 35>, 0,
  <15, 35, 23>, 0,
  <19, 28, 41>, 0,
  <19, 41, 29>, 0,
  <21, 31, 44>, 0,
  <21, 44, 32>, 0,
  <22, 33, 45>, 0,
  <22, 45, 34>, 0,
  <26, 38, 50>, 0,
  <26, 50, 37>, 0,
  <27, 40, 51>, 0,
  <27, 51, 39>, 0,
  <30, 43, 54>, 0,
  <30, 54, 42>, 0,
  <36, 48, 60>, 0,
  <36, 60, 49>, 0,
  <46, 55, 67>, 0,
  <46, 67, 58>, 0,
  <47, 59, 65>, 0,
  <47, 65, 53>, 0,
  <52, 64, 73>, 0,
  <52, 73, 61>, 0,
  <56, 62, 74>, 0,
  <56, 74, 68>, 0,
  <57, 70, 81>, 0,
  <57, 81, 69>, 0,
  <63, 75, 87>, 0,
  <63, 87, 76>, 0,
  <66, 78, 90>, 0,
  <66, 90, 79>, 0,
  <71, 82, 94>, 0,
  <71, 94, 83>, 0,
  <72, 85, 95>, 0,
  <72, 95, 84>, 0,
  <77, 89, 99>, 0,
  <77, 99, 88>, 0,
  <80, 92, 101>, 0,
  <80, 101, 91>, 0,
  <86, 96, 105>, 0,
  <86, 105, 97>, 0,
  <93, 102, 110>, 0,
  <93, 110, 103>, 0,
  <98, 107, 113>, 0,
  <98, 113, 106>, 0,
  <100, 109, 114>, 0,
  <100, 114, 108>, 0,
  <104, 111, 116>, 0,
  <104, 116, 112>, 0,
  <115, 118, 119>, 0,
  <115, 119, 117>, 0,
  <0, 2, 6>, 1,
  <0, 6, 13>, 1,
  <0, 13, 8>, 1,
  <0, 8, 3>, 1,
  <1, 5, 11>, 1,
  <1, 11, 17>, 1,
  <1, 17, 9>, 1,
  <1, 9, 4>, 1,
  <7, 14, 22>, 1,
  <7, 22, 34>, 1,
  <7, 34, 24>, 1,
  <7, 24, 15>, 1,
  <10, 19, 29>, 1,
  <10, 29, 40>, 1,
  <10, 40, 27>, 1,
  <10, 27, 18>, 1,
  <12, 21, 32>, 1,
  <12, 32, 43>, 1,
  <12, 43, 30>, 1,
  <12, 30, 20>, 1,
  <16, 25, 36>, 1,
  <16, 36, 49>, 1,
  <16, 49, 38>, 1,
  <16, 38, 26>, 1,
  <23, 35, 47>, 1,
  <23, 47, 53>, 1,
  <23, 53, 41>, 1,
  <23, 41, 28>, 1,
  <31, 37, 50>, 1,
  <31, 50, 62>, 1,
  <31, 62, 56>, 1,
  <31, 56, 44>, 1,
  <33, 46, 58>, 1,
  <33, 58, 70>, 1,
  <33, 70, 57>, 1,
  <33, 57, 45>, 1,
  <39, 51, 63>, 1,
  <39, 63, 76>, 1,
  <39, 76, 64>, 1,
  <39, 64, 52>, 1,
  <42, 54, 66>, 1,
  <42, 66, 79>, 1,
  <42, 79, 67>, 1,
  <42, 67, 55>, 1,
  <48, 61, 73>, 1,
  <48, 73, 85>, 1,
  <48, 85, 72>, 1,
  <48, 72, 60>, 1,
  <59, 71, 83>, 1,
  <59, 83, 89>, 1,
  <59, 89, 77>, 1,
  <59, 77, 65>, 1,
  <68, 74, 86>, 1,
  <68, 86, 97>, 1,
  <68, 97, 92>, 1,
  <68, 92, 80>, 1,
  <69, 81, 93>, 1,
  <69, 93, 103>, 1,
  <69, 103, 94>, 1,
  <69, 94, 82>, 1,
  <75, 88, 99>, 1,
  <75, 99, 107>, 1,
  <75, 107, 98>, 1,
  <75, 98, 87>, 1,
  <78, 91, 101>, 1,
  <78, 101, 109>, 1,
  <78, 109, 100>, 1,
  <78, 100, 90>, 1,
  <84, 95, 104>, 1,
  <84, 104, 112>, 1,
  <84, 112, 105>, 1,
  <84, 105, 96>, 1,
  <102, 108, 114>, 1,
  <102, 114, 118>, 1,
  <102, 118, 115>, 1,
  <102, 115, 110>, 1,
  <106, 113, 117>, 1,
  <106, 117, 119>, 1,
  <106, 119, 116>, 1,
  <106, 116, 111>, 1,
  <0, 3, 7>, 2,
  <0, 7, 15>, 2,
  <0, 15, 23>, 2,
  <0, 23, 28>, 2,
  <0, 28, 19>, 2,
  <0, 19, 10>, 2,
  <0, 10, 5>, 2,
  <0, 5, 1>, 2,
  <2, 4, 9>, 2,
  <2, 9, 16>, 2,
  <2, 16, 26>, 2,
  <2, 26, 37>, 2,
  <2, 37, 31>, 2,
  <2, 31, 21>, 2,
  <2, 21, 12>, 2,
  <2, 12, 6>, 2,
  <8, 13, 20>, 2,
  <8, 20, 30>, 2,
  <8, 30, 42>, 2,
  <8, 42, 55>, 2,
  <8, 55, 46>, 2,
  <8, 46, 33>, 2,
  <8, 33, 22>, 2,
  <8, 22, 14>, 2,
  <11, 18, 27>, 2,
  <11, 27, 39>, 2,
  <11, 39, 52>, 2,
  <11, 52, 61>, 2,
  <11, 61, 48>, 2,
  <11, 48, 36>, 2,
  <11, 36, 25>, 2,
  <11, 25, 17>, 2,
  <24, 34, 45>, 2,
  <24, 45, 57>, 2,
  <24, 57, 69>, 2,
  <24, 69, 82>, 2,
  <24, 82, 71>, 2,
  <24, 71, 59>, 2,
  <24, 59, 47>, 2,
  <24, 47, 35>, 2,
  <29, 41, 53>, 2,
  <29, 53, 65>, 2,
  <29, 65, 77>, 2,
  <29, 77, 88>, 2,
  <29, 88, 75>, 2,
  <29, 75, 63>, 2,
  <29, 63, 51>, 2,
  <29, 51, 40>, 2,
  <32, 44, 56>, 2,
  <32, 56, 68>, 2,
  <32, 68, 80>, 2,
  <32, 80, 91>, 2,
  <32, 91, 78>, 2,
  <32, 78, 66>, 2,
  <32, 66, 54>, 2,
  <32, 54, 43>, 2,
  <38, 49, 60>, 2,
  <38, 60, 72>, 2,
  <38, 72, 84>, 2,
  <38, 84, 96>, 2,
  <38, 96, 86>, 2,
  <38, 86, 74>, 2,
  <38, 74, 62>, 2,
  <38, 62, 50>, 2,
  <58, 67, 79>, 2,
  <58, 79, 90>, 2,
  <58, 90, 100>, 2,
  <58, 100, 108>, 2,
  <58, 108, 102>, 2,
  <58, 102, 93>, 2,
  <58, 93, 81>, 2,
  <58, 81, 70>, 2,
  <64, 76, 87>, 2,
  <64, 87, 98>, 2,
  <64, 98, 106>, 2,
  <64, 106, 111>, 2,
  <64, 111, 104>, 2,
  <64, 104, 95>, 2,
  <64, 95, 85>, 2,
  <64, 85, 73>, 2,
  <83, 94, 103>, 2,
  <83, 103, 110>, 2,
  <83, 110, 115>, 2,
  <83, 115, 117>, 2,
  <83, 117, 113>, 2,
  <83, 113, 107>, 2,
  <83, 107, 99>, 2,
  <83, 99, 89>, 2,
  <92, 97, 105>, 2,
  <92, 105, 112>, 2,
  <92, 112, 116>, 2,
  <92, 116, 119>, 2,
  <92, 119, 118>, 2,
  <92, 118, 114>, 2,
  <92, 114, 109>, 2,
  <92, 109, 101>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_icosidodecahedron_verts[92];
 #local P1 = Archimedean_truncated_icosidodecahedron_verts[97];
 #local P2 = Archimedean_truncated_icosidodecahedron_verts[105];
 #local P3 = Archimedean_truncated_icosidodecahedron_verts[112];
 #local P4 = Archimedean_truncated_icosidodecahedron_verts[116];
 #local P5 = Archimedean_truncated_icosidodecahedron_verts[119];
 #local P6 = Archimedean_truncated_icosidodecahedron_verts[118];
 #local P7 = Archimedean_truncated_icosidodecahedron_verts[114];
 #local P8 = Archimedean_truncated_icosidodecahedron_verts[109];
 #local P9 = Archimedean_truncated_icosidodecahedron_verts[101];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_icosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_icosidodecahedron_obj }
#end
#end

#macro Archimedean_truncated_icosidodecahedron_faces2(OnPlane)
#local Archimedean_truncated_icosidodecahedron_obj = mesh2 {
 vertex_vectors {
  120,
  Archimedean_truncated_icosidodecahedron_verts[0],
  Archimedean_truncated_icosidodecahedron_verts[1],
  Archimedean_truncated_icosidodecahedron_verts[2],
  Archimedean_truncated_icosidodecahedron_verts[3],
  Archimedean_truncated_icosidodecahedron_verts[4],
  Archimedean_truncated_icosidodecahedron_verts[5],
  Archimedean_truncated_icosidodecahedron_verts[6],
  Archimedean_truncated_icosidodecahedron_verts[7],
  Archimedean_truncated_icosidodecahedron_verts[8],
  Archimedean_truncated_icosidodecahedron_verts[9],
  Archimedean_truncated_icosidodecahedron_verts[10],
  Archimedean_truncated_icosidodecahedron_verts[11],
  Archimedean_truncated_icosidodecahedron_verts[12],
  Archimedean_truncated_icosidodecahedron_verts[13],
  Archimedean_truncated_icosidodecahedron_verts[14],
  Archimedean_truncated_icosidodecahedron_verts[15],
  Archimedean_truncated_icosidodecahedron_verts[16],
  Archimedean_truncated_icosidodecahedron_verts[17],
  Archimedean_truncated_icosidodecahedron_verts[18],
  Archimedean_truncated_icosidodecahedron_verts[19],
  Archimedean_truncated_icosidodecahedron_verts[20],
  Archimedean_truncated_icosidodecahedron_verts[21],
  Archimedean_truncated_icosidodecahedron_verts[22],
  Archimedean_truncated_icosidodecahedron_verts[23],
  Archimedean_truncated_icosidodecahedron_verts[24],
  Archimedean_truncated_icosidodecahedron_verts[25],
  Archimedean_truncated_icosidodecahedron_verts[26],
  Archimedean_truncated_icosidodecahedron_verts[27],
  Archimedean_truncated_icosidodecahedron_verts[28],
  Archimedean_truncated_icosidodecahedron_verts[29],
  Archimedean_truncated_icosidodecahedron_verts[30],
  Archimedean_truncated_icosidodecahedron_verts[31],
  Archimedean_truncated_icosidodecahedron_verts[32],
  Archimedean_truncated_icosidodecahedron_verts[33],
  Archimedean_truncated_icosidodecahedron_verts[34],
  Archimedean_truncated_icosidodecahedron_verts[35],
  Archimedean_truncated_icosidodecahedron_verts[36],
  Archimedean_truncated_icosidodecahedron_verts[37],
  Archimedean_truncated_icosidodecahedron_verts[38],
  Archimedean_truncated_icosidodecahedron_verts[39],
  Archimedean_truncated_icosidodecahedron_verts[40],
  Archimedean_truncated_icosidodecahedron_verts[41],
  Archimedean_truncated_icosidodecahedron_verts[42],
  Archimedean_truncated_icosidodecahedron_verts[43],
  Archimedean_truncated_icosidodecahedron_verts[44],
  Archimedean_truncated_icosidodecahedron_verts[45],
  Archimedean_truncated_icosidodecahedron_verts[46],
  Archimedean_truncated_icosidodecahedron_verts[47],
  Archimedean_truncated_icosidodecahedron_verts[48],
  Archimedean_truncated_icosidodecahedron_verts[49],
  Archimedean_truncated_icosidodecahedron_verts[50],
  Archimedean_truncated_icosidodecahedron_verts[51],
  Archimedean_truncated_icosidodecahedron_verts[52],
  Archimedean_truncated_icosidodecahedron_verts[53],
  Archimedean_truncated_icosidodecahedron_verts[54],
  Archimedean_truncated_icosidodecahedron_verts[55],
  Archimedean_truncated_icosidodecahedron_verts[56],
  Archimedean_truncated_icosidodecahedron_verts[57],
  Archimedean_truncated_icosidodecahedron_verts[58],
  Archimedean_truncated_icosidodecahedron_verts[59],
  Archimedean_truncated_icosidodecahedron_verts[60],
  Archimedean_truncated_icosidodecahedron_verts[61],
  Archimedean_truncated_icosidodecahedron_verts[62],
  Archimedean_truncated_icosidodecahedron_verts[63],
  Archimedean_truncated_icosidodecahedron_verts[64],
  Archimedean_truncated_icosidodecahedron_verts[65],
  Archimedean_truncated_icosidodecahedron_verts[66],
  Archimedean_truncated_icosidodecahedron_verts[67],
  Archimedean_truncated_icosidodecahedron_verts[68],
  Archimedean_truncated_icosidodecahedron_verts[69],
  Archimedean_truncated_icosidodecahedron_verts[70],
  Archimedean_truncated_icosidodecahedron_verts[71],
  Archimedean_truncated_icosidodecahedron_verts[72],
  Archimedean_truncated_icosidodecahedron_verts[73],
  Archimedean_truncated_icosidodecahedron_verts[74],
  Archimedean_truncated_icosidodecahedron_verts[75],
  Archimedean_truncated_icosidodecahedron_verts[76],
  Archimedean_truncated_icosidodecahedron_verts[77],
  Archimedean_truncated_icosidodecahedron_verts[78],
  Archimedean_truncated_icosidodecahedron_verts[79],
  Archimedean_truncated_icosidodecahedron_verts[80],
  Archimedean_truncated_icosidodecahedron_verts[81],
  Archimedean_truncated_icosidodecahedron_verts[82],
  Archimedean_truncated_icosidodecahedron_verts[83],
  Archimedean_truncated_icosidodecahedron_verts[84],
  Archimedean_truncated_icosidodecahedron_verts[85],
  Archimedean_truncated_icosidodecahedron_verts[86],
  Archimedean_truncated_icosidodecahedron_verts[87],
  Archimedean_truncated_icosidodecahedron_verts[88],
  Archimedean_truncated_icosidodecahedron_verts[89],
  Archimedean_truncated_icosidodecahedron_verts[90],
  Archimedean_truncated_icosidodecahedron_verts[91],
  Archimedean_truncated_icosidodecahedron_verts[92],
  Archimedean_truncated_icosidodecahedron_verts[93],
  Archimedean_truncated_icosidodecahedron_verts[94],
  Archimedean_truncated_icosidodecahedron_verts[95],
  Archimedean_truncated_icosidodecahedron_verts[96],
  Archimedean_truncated_icosidodecahedron_verts[97],
  Archimedean_truncated_icosidodecahedron_verts[98],
  Archimedean_truncated_icosidodecahedron_verts[99],
  Archimedean_truncated_icosidodecahedron_verts[100],
  Archimedean_truncated_icosidodecahedron_verts[101],
  Archimedean_truncated_icosidodecahedron_verts[102],
  Archimedean_truncated_icosidodecahedron_verts[103],
  Archimedean_truncated_icosidodecahedron_verts[104],
  Archimedean_truncated_icosidodecahedron_verts[105],
  Archimedean_truncated_icosidodecahedron_verts[106],
  Archimedean_truncated_icosidodecahedron_verts[107],
  Archimedean_truncated_icosidodecahedron_verts[108],
  Archimedean_truncated_icosidodecahedron_verts[109],
  Archimedean_truncated_icosidodecahedron_verts[110],
  Archimedean_truncated_icosidodecahedron_verts[111],
  Archimedean_truncated_icosidodecahedron_verts[112],
  Archimedean_truncated_icosidodecahedron_verts[113],
  Archimedean_truncated_icosidodecahedron_verts[114],
  Archimedean_truncated_icosidodecahedron_verts[115],
  Archimedean_truncated_icosidodecahedron_verts[116],
  Archimedean_truncated_icosidodecahedron_verts[117],
  Archimedean_truncated_icosidodecahedron_verts[118],
  Archimedean_truncated_icosidodecahedron_verts[119]
 }
 face_indices {
  236,
  <0, 1, 4>,
  <0, 4, 2>,
  <3, 8, 14>,
  <3, 14, 7>,
  <5, 10, 18>,
  <5, 18, 11>,
  <6, 12, 20>,
  <6, 20, 13>,
  <9, 17, 25>,
  <9, 25, 16>,
  <15, 24, 35>,
  <15, 35, 23>,
  <19, 28, 41>,
  <19, 41, 29>,
  <21, 31, 44>,
  <21, 44, 32>,
  <22, 33, 45>,
  <22, 45, 34>,
  <26, 38, 50>,
  <26, 50, 37>,
  <27, 40, 51>,
  <27, 51, 39>,
  <30, 43, 54>,
  <30, 54, 42>,
  <36, 48, 60>,
  <36, 60, 49>,
  <46, 55, 67>,
  <46, 67, 58>,
  <47, 59, 65>,
  <47, 65, 53>,
  <52, 64, 73>,
  <52, 73, 61>,
  <56, 62, 74>,
  <56, 74, 68>,
  <57, 70, 81>,
  <57, 81, 69>,
  <63, 75, 87>,
  <63, 87, 76>,
  <66, 78, 90>,
  <66, 90, 79>,
  <71, 82, 94>,
  <71, 94, 83>,
  <72, 85, 95>,
  <72, 95, 84>,
  <77, 89, 99>,
  <77, 99, 88>,
  <80, 92, 101>,
  <80, 101, 91>,
  <86, 96, 105>,
  <86, 105, 97>,
  <93, 102, 110>,
  <93, 110, 103>,
  <98, 107, 113>,
  <98, 113, 106>,
  <100, 109, 114>,
  <100, 114, 108>,
  <104, 111, 116>,
  <104, 116, 112>,
  <115, 118, 119>,
  <115, 119, 117>,
  <0, 2, 6>,
  <0, 6, 13>,
  <0, 13, 8>,
  <0, 8, 3>,
  <1, 5, 11>,
  <1, 11, 17>,
  <1, 17, 9>,
  <1, 9, 4>,
  <7, 14, 22>,
  <7, 22, 34>,
  <7, 34, 24>,
  <7, 24, 15>,
  <10, 19, 29>,
  <10, 29, 40>,
  <10, 40, 27>,
  <10, 27, 18>,
  <12, 21, 32>,
  <12, 32, 43>,
  <12, 43, 30>,
  <12, 30, 20>,
  <16, 25, 36>,
  <16, 36, 49>,
  <16, 49, 38>,
  <16, 38, 26>,
  <23, 35, 47>,
  <23, 47, 53>,
  <23, 53, 41>,
  <23, 41, 28>,
  <31, 37, 50>,
  <31, 50, 62>,
  <31, 62, 56>,
  <31, 56, 44>,
  <33, 46, 58>,
  <33, 58, 70>,
  <33, 70, 57>,
  <33, 57, 45>,
  <39, 51, 63>,
  <39, 63, 76>,
  <39, 76, 64>,
  <39, 64, 52>,
  <42, 54, 66>,
  <42, 66, 79>,
  <42, 79, 67>,
  <42, 67, 55>,
  <48, 61, 73>,
  <48, 73, 85>,
  <48, 85, 72>,
  <48, 72, 60>,
  <59, 71, 83>,
  <59, 83, 89>,
  <59, 89, 77>,
  <59, 77, 65>,
  <68, 74, 86>,
  <68, 86, 97>,
  <68, 97, 92>,
  <68, 92, 80>,
  <69, 81, 93>,
  <69, 93, 103>,
  <69, 103, 94>,
  <69, 94, 82>,
  <75, 88, 99>,
  <75, 99, 107>,
  <75, 107, 98>,
  <75, 98, 87>,
  <78, 91, 101>,
  <78, 101, 109>,
  <78, 109, 100>,
  <78, 100, 90>,
  <84, 95, 104>,
  <84, 104, 112>,
  <84, 112, 105>,
  <84, 105, 96>,
  <102, 108, 114>,
  <102, 114, 118>,
  <102, 118, 115>,
  <102, 115, 110>,
  <106, 113, 117>,
  <106, 117, 119>,
  <106, 119, 116>,
  <106, 116, 111>,
  <0, 3, 7>,
  <0, 7, 15>,
  <0, 15, 23>,
  <0, 23, 28>,
  <0, 28, 19>,
  <0, 19, 10>,
  <0, 10, 5>,
  <0, 5, 1>,
  <2, 4, 9>,
  <2, 9, 16>,
  <2, 16, 26>,
  <2, 26, 37>,
  <2, 37, 31>,
  <2, 31, 21>,
  <2, 21, 12>,
  <2, 12, 6>,
  <8, 13, 20>,
  <8, 20, 30>,
  <8, 30, 42>,
  <8, 42, 55>,
  <8, 55, 46>,
  <8, 46, 33>,
  <8, 33, 22>,
  <8, 22, 14>,
  <11, 18, 27>,
  <11, 27, 39>,
  <11, 39, 52>,
  <11, 52, 61>,
  <11, 61, 48>,
  <11, 48, 36>,
  <11, 36, 25>,
  <11, 25, 17>,
  <24, 34, 45>,
  <24, 45, 57>,
  <24, 57, 69>,
  <24, 69, 82>,
  <24, 82, 71>,
  <24, 71, 59>,
  <24, 59, 47>,
  <24, 47, 35>,
  <29, 41, 53>,
  <29, 53, 65>,
  <29, 65, 77>,
  <29, 77, 88>,
  <29, 88, 75>,
  <29, 75, 63>,
  <29, 63, 51>,
  <29, 51, 40>,
  <32, 44, 56>,
  <32, 56, 68>,
  <32, 68, 80>,
  <32, 80, 91>,
  <32, 91, 78>,
  <32, 78, 66>,
  <32, 66, 54>,
  <32, 54, 43>,
  <38, 49, 60>,
  <38, 60, 72>,
  <38, 72, 84>,
  <38, 84, 96>,
  <38, 96, 86>,
  <38, 86, 74>,
  <38, 74, 62>,
  <38, 62, 50>,
  <58, 67, 79>,
  <58, 79, 90>,
  <58, 90, 100>,
  <58, 100, 108>,
  <58, 108, 102>,
  <58, 102, 93>,
  <58, 93, 81>,
  <58, 81, 70>,
  <64, 76, 87>,
  <64, 87, 98>,
  <64, 98, 106>,
  <64, 106, 111>,
  <64, 111, 104>,
  <64, 104, 95>,
  <64, 95, 85>,
  <64, 85, 73>,
  <83, 94, 103>,
  <83, 103, 110>,
  <83, 110, 115>,
  <83, 115, 117>,
  <83, 117, 113>,
  <83, 113, 107>,
  <83, 107, 99>,
  <83, 99, 89>,
  <92, 97, 105>,
  <92, 105, 112>,
  <92, 112, 116>,
  <92, 116, 119>,
  <92, 119, 118>,
  <92, 118, 114>,
  <92, 114, 109>,
  <92, 109, 101>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_truncated_icosidodecahedron_verts[92];
 #local P1 = Archimedean_truncated_icosidodecahedron_verts[97];
 #local P2 = Archimedean_truncated_icosidodecahedron_verts[105];
 #local P3 = Archimedean_truncated_icosidodecahedron_verts[112];
 #local P4 = Archimedean_truncated_icosidodecahedron_verts[116];
 #local P5 = Archimedean_truncated_icosidodecahedron_verts[119];
 #local P6 = Archimedean_truncated_icosidodecahedron_verts[118];
 #local P7 = Archimedean_truncated_icosidodecahedron_verts[114];
 #local P8 = Archimedean_truncated_icosidodecahedron_verts[109];
 #local P9 = Archimedean_truncated_icosidodecahedron_verts[101];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_truncated_icosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_truncated_icosidodecahedron_obj }
#end
#end

#macro Archimedean_truncated_icosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_truncated_icosidodecahedron_verts[0], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[1], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[2], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[3], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[4], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[5], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[6], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[7], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[8], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[9], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[10], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[11], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[12], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[13], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[14], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[15], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[16], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[17], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[18], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[19], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[20], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[21], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[22], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[23], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[24], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[25], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[26], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[27], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[28], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[29], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[30], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[31], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[32], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[33], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[34], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[35], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[36], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[37], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[38], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[39], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[40], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[41], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[42], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[43], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[44], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[45], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[46], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[47], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[48], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[49], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[50], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[51], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[52], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[53], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[54], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[55], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[56], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[57], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[58], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[59], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[60], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[61], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[62], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[63], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[64], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[65], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[66], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[67], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[68], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[69], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[70], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[71], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[72], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[73], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[74], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[75], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[76], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[77], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[78], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[79], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[80], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[81], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[82], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[83], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[84], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[85], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[86], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[87], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[88], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[89], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[90], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[91], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[92], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[93], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[94], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[95], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[96], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[97], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[98], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[99], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[100], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[101], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[102], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[103], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[104], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[105], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[106], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[107], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[108], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[109], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[110], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[111], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[112], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[113], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[114], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[115], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[116], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[117], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[118], RadVer }
  sphere { Archimedean_truncated_icosidodecahedron_verts[119], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_truncated_icosidodecahedron_verts[0], Archimedean_truncated_icosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[1], Archimedean_truncated_icosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[4], Archimedean_truncated_icosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[2], Archimedean_truncated_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[3], Archimedean_truncated_icosidodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[8], Archimedean_truncated_icosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[14], Archimedean_truncated_icosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[7], Archimedean_truncated_icosidodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[5], Archimedean_truncated_icosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[10], Archimedean_truncated_icosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[18], Archimedean_truncated_icosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[11], Archimedean_truncated_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[6], Archimedean_truncated_icosidodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[12], Archimedean_truncated_icosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[20], Archimedean_truncated_icosidodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[13], Archimedean_truncated_icosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[9], Archimedean_truncated_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[17], Archimedean_truncated_icosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[25], Archimedean_truncated_icosidodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[16], Archimedean_truncated_icosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[15], Archimedean_truncated_icosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[24], Archimedean_truncated_icosidodecahedron_verts[35], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[35], Archimedean_truncated_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[23], Archimedean_truncated_icosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[19], Archimedean_truncated_icosidodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[28], Archimedean_truncated_icosidodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[41], Archimedean_truncated_icosidodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[29], Archimedean_truncated_icosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[21], Archimedean_truncated_icosidodecahedron_verts[31], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[31], Archimedean_truncated_icosidodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[44], Archimedean_truncated_icosidodecahedron_verts[32], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[32], Archimedean_truncated_icosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[22], Archimedean_truncated_icosidodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[33], Archimedean_truncated_icosidodecahedron_verts[45], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[45], Archimedean_truncated_icosidodecahedron_verts[34], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[34], Archimedean_truncated_icosidodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[26], Archimedean_truncated_icosidodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[38], Archimedean_truncated_icosidodecahedron_verts[50], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[50], Archimedean_truncated_icosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[37], Archimedean_truncated_icosidodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[27], Archimedean_truncated_icosidodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[40], Archimedean_truncated_icosidodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[51], Archimedean_truncated_icosidodecahedron_verts[39], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[39], Archimedean_truncated_icosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[30], Archimedean_truncated_icosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[43], Archimedean_truncated_icosidodecahedron_verts[54], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[54], Archimedean_truncated_icosidodecahedron_verts[42], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[42], Archimedean_truncated_icosidodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[36], Archimedean_truncated_icosidodecahedron_verts[48], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[48], Archimedean_truncated_icosidodecahedron_verts[60], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[60], Archimedean_truncated_icosidodecahedron_verts[49], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[49], Archimedean_truncated_icosidodecahedron_verts[36], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[46], Archimedean_truncated_icosidodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[55], Archimedean_truncated_icosidodecahedron_verts[67], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[67], Archimedean_truncated_icosidodecahedron_verts[58], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[58], Archimedean_truncated_icosidodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[47], Archimedean_truncated_icosidodecahedron_verts[59], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[59], Archimedean_truncated_icosidodecahedron_verts[65], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[65], Archimedean_truncated_icosidodecahedron_verts[53], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[53], Archimedean_truncated_icosidodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[52], Archimedean_truncated_icosidodecahedron_verts[64], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[64], Archimedean_truncated_icosidodecahedron_verts[73], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[73], Archimedean_truncated_icosidodecahedron_verts[61], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[61], Archimedean_truncated_icosidodecahedron_verts[52], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[56], Archimedean_truncated_icosidodecahedron_verts[62], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[62], Archimedean_truncated_icosidodecahedron_verts[74], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[74], Archimedean_truncated_icosidodecahedron_verts[68], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[68], Archimedean_truncated_icosidodecahedron_verts[56], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[57], Archimedean_truncated_icosidodecahedron_verts[70], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[70], Archimedean_truncated_icosidodecahedron_verts[81], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[81], Archimedean_truncated_icosidodecahedron_verts[69], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[69], Archimedean_truncated_icosidodecahedron_verts[57], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[63], Archimedean_truncated_icosidodecahedron_verts[75], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[75], Archimedean_truncated_icosidodecahedron_verts[87], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[87], Archimedean_truncated_icosidodecahedron_verts[76], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[76], Archimedean_truncated_icosidodecahedron_verts[63], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[66], Archimedean_truncated_icosidodecahedron_verts[78], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[78], Archimedean_truncated_icosidodecahedron_verts[90], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[90], Archimedean_truncated_icosidodecahedron_verts[79], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[79], Archimedean_truncated_icosidodecahedron_verts[66], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[71], Archimedean_truncated_icosidodecahedron_verts[82], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[82], Archimedean_truncated_icosidodecahedron_verts[94], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[94], Archimedean_truncated_icosidodecahedron_verts[83], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[83], Archimedean_truncated_icosidodecahedron_verts[71], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[72], Archimedean_truncated_icosidodecahedron_verts[85], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[85], Archimedean_truncated_icosidodecahedron_verts[95], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[95], Archimedean_truncated_icosidodecahedron_verts[84], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[84], Archimedean_truncated_icosidodecahedron_verts[72], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[77], Archimedean_truncated_icosidodecahedron_verts[89], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[89], Archimedean_truncated_icosidodecahedron_verts[99], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[99], Archimedean_truncated_icosidodecahedron_verts[88], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[88], Archimedean_truncated_icosidodecahedron_verts[77], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[80], Archimedean_truncated_icosidodecahedron_verts[92], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[92], Archimedean_truncated_icosidodecahedron_verts[101], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[101], Archimedean_truncated_icosidodecahedron_verts[91], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[91], Archimedean_truncated_icosidodecahedron_verts[80], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[86], Archimedean_truncated_icosidodecahedron_verts[96], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[96], Archimedean_truncated_icosidodecahedron_verts[105], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[105], Archimedean_truncated_icosidodecahedron_verts[97], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[97], Archimedean_truncated_icosidodecahedron_verts[86], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[93], Archimedean_truncated_icosidodecahedron_verts[102], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[102], Archimedean_truncated_icosidodecahedron_verts[110], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[110], Archimedean_truncated_icosidodecahedron_verts[103], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[103], Archimedean_truncated_icosidodecahedron_verts[93], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[98], Archimedean_truncated_icosidodecahedron_verts[107], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[107], Archimedean_truncated_icosidodecahedron_verts[113], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[113], Archimedean_truncated_icosidodecahedron_verts[106], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[106], Archimedean_truncated_icosidodecahedron_verts[98], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[100], Archimedean_truncated_icosidodecahedron_verts[109], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[109], Archimedean_truncated_icosidodecahedron_verts[114], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[114], Archimedean_truncated_icosidodecahedron_verts[108], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[108], Archimedean_truncated_icosidodecahedron_verts[100], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[104], Archimedean_truncated_icosidodecahedron_verts[111], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[111], Archimedean_truncated_icosidodecahedron_verts[116], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[116], Archimedean_truncated_icosidodecahedron_verts[112], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[112], Archimedean_truncated_icosidodecahedron_verts[104], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[115], Archimedean_truncated_icosidodecahedron_verts[118], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[118], Archimedean_truncated_icosidodecahedron_verts[119], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[119], Archimedean_truncated_icosidodecahedron_verts[117], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[117], Archimedean_truncated_icosidodecahedron_verts[115], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[2], Archimedean_truncated_icosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[13], Archimedean_truncated_icosidodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[3], Archimedean_truncated_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[1], Archimedean_truncated_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[11], Archimedean_truncated_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[9], Archimedean_truncated_icosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[14], Archimedean_truncated_icosidodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[34], Archimedean_truncated_icosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[15], Archimedean_truncated_icosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[10], Archimedean_truncated_icosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[29], Archimedean_truncated_icosidodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[27], Archimedean_truncated_icosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[12], Archimedean_truncated_icosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[32], Archimedean_truncated_icosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[30], Archimedean_truncated_icosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[25], Archimedean_truncated_icosidodecahedron_verts[36], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[49], Archimedean_truncated_icosidodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[26], Archimedean_truncated_icosidodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[35], Archimedean_truncated_icosidodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[53], Archimedean_truncated_icosidodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[28], Archimedean_truncated_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[31], Archimedean_truncated_icosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[50], Archimedean_truncated_icosidodecahedron_verts[62], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[56], Archimedean_truncated_icosidodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[33], Archimedean_truncated_icosidodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[58], Archimedean_truncated_icosidodecahedron_verts[70], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[57], Archimedean_truncated_icosidodecahedron_verts[45], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[51], Archimedean_truncated_icosidodecahedron_verts[63], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[76], Archimedean_truncated_icosidodecahedron_verts[64], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[52], Archimedean_truncated_icosidodecahedron_verts[39], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[54], Archimedean_truncated_icosidodecahedron_verts[66], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[79], Archimedean_truncated_icosidodecahedron_verts[67], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[55], Archimedean_truncated_icosidodecahedron_verts[42], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[48], Archimedean_truncated_icosidodecahedron_verts[61], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[73], Archimedean_truncated_icosidodecahedron_verts[85], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[72], Archimedean_truncated_icosidodecahedron_verts[60], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[59], Archimedean_truncated_icosidodecahedron_verts[71], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[83], Archimedean_truncated_icosidodecahedron_verts[89], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[77], Archimedean_truncated_icosidodecahedron_verts[65], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[74], Archimedean_truncated_icosidodecahedron_verts[86], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[97], Archimedean_truncated_icosidodecahedron_verts[92], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[80], Archimedean_truncated_icosidodecahedron_verts[68], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[81], Archimedean_truncated_icosidodecahedron_verts[93], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[103], Archimedean_truncated_icosidodecahedron_verts[94], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[82], Archimedean_truncated_icosidodecahedron_verts[69], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[75], Archimedean_truncated_icosidodecahedron_verts[88], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[99], Archimedean_truncated_icosidodecahedron_verts[107], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[98], Archimedean_truncated_icosidodecahedron_verts[87], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[78], Archimedean_truncated_icosidodecahedron_verts[91], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[101], Archimedean_truncated_icosidodecahedron_verts[109], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[100], Archimedean_truncated_icosidodecahedron_verts[90], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[95], Archimedean_truncated_icosidodecahedron_verts[104], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[112], Archimedean_truncated_icosidodecahedron_verts[105], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[96], Archimedean_truncated_icosidodecahedron_verts[84], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[102], Archimedean_truncated_icosidodecahedron_verts[108], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[114], Archimedean_truncated_icosidodecahedron_verts[118], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[115], Archimedean_truncated_icosidodecahedron_verts[110], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[113], Archimedean_truncated_icosidodecahedron_verts[117], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[119], Archimedean_truncated_icosidodecahedron_verts[116], RadEdg }
  cylinder { Archimedean_truncated_icosidodecahedron_verts[111], Archimedean_truncated_icosidodecahedron_verts[106], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_truncated_icosidodecahedron_verts[92];
 #local P1 = Archimedean_truncated_icosidodecahedron_verts[97];
 #local P2 = Archimedean_truncated_icosidodecahedron_verts[105];
 #local P3 = Archimedean_truncated_icosidodecahedron_verts[112];
 #local P4 = Archimedean_truncated_icosidodecahedron_verts[116];
 #local P5 = Archimedean_truncated_icosidodecahedron_verts[119];
 #local P6 = Archimedean_truncated_icosidodecahedron_verts[118];
 #local P7 = Archimedean_truncated_icosidodecahedron_verts[114];
 #local P8 = Archimedean_truncated_icosidodecahedron_verts[109];
 #local P9 = Archimedean_truncated_icosidodecahedron_verts[101];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Archimedean_snub_icosidodecahedron_verts = array[60]
{
<0, 0, 1.028031>,
<0.4638569, 0, 0.9174342>,
<0.2187436, 0.4090409, 0.9174342>,
<-0.2575486, 0.3857874, 0.9174342>,
<-0.4616509, -0.04518499, 0.9174342>,
<-0.177858, -0.4284037, 0.9174342>,
<0.5726782, -0.4284037, 0.7384841>,
<0.8259401, -0.04518499, 0.6104342>,
<0.6437955, 0.3857874, 0.702527>,
<0.349648, 0.7496433, 0.6104342>,
<-0.421009, 0.7120184, 0.6104342>,
<-0.6783139, 0.3212396, 0.702527>,
<-0.6031536, -0.4466658, 0.702527>,
<-0.2749612, -0.7801379, 0.6104342>,
<0.1760766, -0.6931717, 0.7384841>,
<0.5208138, -0.7801379, 0.4206978>,
<0.8552518, -0.4466658, 0.3547998>,
<1.01294, -0.03548596, 0.1718776>,
<0.7182239, 0.661842, 0.3208868>,
<0.3633691, 0.9454568, 0.1758496>,
<-0.04574087, 0.9368937, 0.4206978>,
<-0.4537394, 0.905564, 0.1758496>,
<-0.7792791, 0.5887312, 0.3208868>,
<-0.9537217, 0.1462217, 0.3547998>
<-0.9072701, -0.3283699, 0.3547998>,
<-0.6503371, -0.7286577, 0.3208868>,
<0.08459482, -0.9611501, 0.3547998>,
<0.3949153, -0.9491262, -0.007072558>,
<0.9360473, -0.409557, -0.1136978>,
<0.9829382, 0.02692292, -0.2999274>,
<0.9463677, 0.4014808, -0.007072558>,
<0.6704578, 0.7662826, -0.1419366>,
<-0.05007646, 1.025698, -0.04779978>,
<-0.4294337, 0.8845784, -0.2999274>,
<-0.9561681, 0.3719321, -0.06525234>,
<-1.022036, -0.1000338, -0.04779978>,
<-0.8659056, -0.5502712, -0.06525234>,
<-0.5227761, -0.8778535, -0.1136978>,
<-0.06856319, -1.021542, -0.09273844>,
<0.2232046, -0.8974878, -0.4489366>,
<0.6515438, -0.7200947, -0.3373472>,
<0.7969535, -0.3253959, -0.5619888>,
<0.8066872, 0.4395354, -0.461425>,
<0.4468035, 0.735788, -0.5619888>,
<0.001488801, 0.8961155, -0.503809>,
<-0.3535403, 0.6537658, -0.7102452>,
<-0.7399517, 0.5547758, -0.4489366>,
<-0.9120238, 0.1102196, -0.461425>,
<-0.6593998, -0.6182798, -0.4896639>,
<-0.2490651, -0.8608088, -0.503809>,
<0.4301047, -0.5764987, -0.734512>,
<0.5057577, -0.1305283, -0.8854492>,
<0.5117735, 0.3422252, -0.8232973>,
<0.09739587, 0.5771941, -0.8451093>,
<-0.6018946, 0.2552591, -0.7933564>,
<-0.6879024, -0.2100741, -0.734512>,
<-0.3340437, -0.5171509, -0.8232973>,
<0.08570633, -0.3414376, -0.9658797>,
<0.1277354, 0.1313635, -1.011571>,
<-0.3044499, -0.06760332, -0.979586>,
}
#local P0 = Archimedean_snub_icosidodecahedron_verts[45];
#local P1 = Archimedean_snub_icosidodecahedron_verts[53];
#local P2 = Archimedean_snub_icosidodecahedron_verts[58];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 60)
 #declare Archimedean_snub_icosidodecahedron_verts[Num] = vtransform(Archimedean_snub_icosidodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Archimedean_snub_icosidodecahedron_faces(Tex3, Tex5, OnPlane)
#local Archimedean_snub_icosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_snub_icosidodecahedron_verts[0],
  Archimedean_snub_icosidodecahedron_verts[1],
  Archimedean_snub_icosidodecahedron_verts[2],
  Archimedean_snub_icosidodecahedron_verts[3],
  Archimedean_snub_icosidodecahedron_verts[4],
  Archimedean_snub_icosidodecahedron_verts[5],
  Archimedean_snub_icosidodecahedron_verts[6],
  Archimedean_snub_icosidodecahedron_verts[7],
  Archimedean_snub_icosidodecahedron_verts[8],
  Archimedean_snub_icosidodecahedron_verts[9],
  Archimedean_snub_icosidodecahedron_verts[10],
  Archimedean_snub_icosidodecahedron_verts[11],
  Archimedean_snub_icosidodecahedron_verts[12],
  Archimedean_snub_icosidodecahedron_verts[13],
  Archimedean_snub_icosidodecahedron_verts[14],
  Archimedean_snub_icosidodecahedron_verts[15],
  Archimedean_snub_icosidodecahedron_verts[16],
  Archimedean_snub_icosidodecahedron_verts[17],
  Archimedean_snub_icosidodecahedron_verts[18],
  Archimedean_snub_icosidodecahedron_verts[19],
  Archimedean_snub_icosidodecahedron_verts[20],
  Archimedean_snub_icosidodecahedron_verts[21],
  Archimedean_snub_icosidodecahedron_verts[22],
  Archimedean_snub_icosidodecahedron_verts[23],
  Archimedean_snub_icosidodecahedron_verts[24],
  Archimedean_snub_icosidodecahedron_verts[25],
  Archimedean_snub_icosidodecahedron_verts[26],
  Archimedean_snub_icosidodecahedron_verts[27],
  Archimedean_snub_icosidodecahedron_verts[28],
  Archimedean_snub_icosidodecahedron_verts[29],
  Archimedean_snub_icosidodecahedron_verts[30],
  Archimedean_snub_icosidodecahedron_verts[31],
  Archimedean_snub_icosidodecahedron_verts[32],
  Archimedean_snub_icosidodecahedron_verts[33],
  Archimedean_snub_icosidodecahedron_verts[34],
  Archimedean_snub_icosidodecahedron_verts[35],
  Archimedean_snub_icosidodecahedron_verts[36],
  Archimedean_snub_icosidodecahedron_verts[37],
  Archimedean_snub_icosidodecahedron_verts[38],
  Archimedean_snub_icosidodecahedron_verts[39],
  Archimedean_snub_icosidodecahedron_verts[40],
  Archimedean_snub_icosidodecahedron_verts[41],
  Archimedean_snub_icosidodecahedron_verts[42],
  Archimedean_snub_icosidodecahedron_verts[43],
  Archimedean_snub_icosidodecahedron_verts[44],
  Archimedean_snub_icosidodecahedron_verts[45],
  Archimedean_snub_icosidodecahedron_verts[46],
  Archimedean_snub_icosidodecahedron_verts[47],
  Archimedean_snub_icosidodecahedron_verts[48],
  Archimedean_snub_icosidodecahedron_verts[49],
  Archimedean_snub_icosidodecahedron_verts[50],
  Archimedean_snub_icosidodecahedron_verts[51],
  Archimedean_snub_icosidodecahedron_verts[52],
  Archimedean_snub_icosidodecahedron_verts[53],
  Archimedean_snub_icosidodecahedron_verts[54],
  Archimedean_snub_icosidodecahedron_verts[55],
  Archimedean_snub_icosidodecahedron_verts[56],
  Archimedean_snub_icosidodecahedron_verts[57],
  Archimedean_snub_icosidodecahedron_verts[58],
  Archimedean_snub_icosidodecahedron_verts[59]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  116,
  <0, 1, 2>, 0,
  <0, 2, 3>, 0,
  <0, 3, 4>, 0,
  <0, 4, 5>, 0,
  <1, 6, 7>, 0,
  <1, 7, 8>, 0,
  <1, 8, 2>, 0,
  <2, 8, 9>, 0,
  <3, 10, 11>, 0,
  <3, 11, 4>, 0,
  <4, 12, 5>, 0,
  <5, 12, 13>, 0,
  <5, 13, 14>, 0,
  <6, 14, 15>, 0,
  <6, 15, 16>, 0,
  <6, 16, 7>, 0,
  <7, 16, 17>, 0,
  <8, 18, 9>, 0,
  <9, 18, 19>, 0,
  <9, 19, 20>, 0,
  <10, 20, 21>, 0,
  <10, 21, 22>, 0,
  <10, 22, 11>, 0,
  <11, 22, 23>, 0,
  <12, 24, 25>, 0,
  <12, 25, 13>, 0,
  <13, 26, 14>, 0,
  <14, 26, 15>, 0,
  <15, 26, 27>, 0,
  <16, 28, 17>, 0,
  <17, 28, 29>, 0,
  <17, 29, 30>, 0,
  <18, 30, 31>, 0,
  <18, 31, 19>, 0,
  <19, 32, 20>, 0,
  <20, 32, 21>, 0,
  <21, 32, 33>, 0,
  <22, 34, 23>, 0,
  <23, 34, 35>, 0,
  <23, 35, 24>, 0,
  <24, 35, 36>, 0,
  <24, 36, 25>, 0,
  <25, 36, 37>, 0,
  <26, 38, 27>, 0,
  <27, 38, 39>, 0,
  <27, 39, 40>, 0,
  <28, 40, 41>, 0,
  <28, 41, 29>, 0,
  <29, 42, 30>, 0,
  <30, 42, 31>, 0,
  <31, 42, 43>, 0,
  <32, 44, 33>, 0,
  <33, 44, 45>, 0,
  <33, 45, 46>, 0,
  <34, 46, 47>, 0,
  <34, 47, 35>, 0,
  <36, 48, 37>, 0,
  <37, 48, 49>, 0,
  <37, 49, 38>, 0,
  <38, 49, 39>, 0,
  <39, 50, 40>, 0,
  <40, 50, 41>, 0,
  <41, 50, 51>, 0,
  <42, 52, 43>, 0,
  <43, 52, 53>, 0,
  <43, 53, 44>, 0,
  <44, 53, 45>, 0,
  <45, 54, 46>, 0,
  <46, 54, 47>, 0,
  <47, 54, 55>, 0,
  <48, 55, 56>, 0,
  <48, 56, 49>, 0,
  <50, 57, 51>, 0,
  <51, 57, 58>, 0,
  <51, 58, 52>, 0,
  <52, 58, 53>, 0,
  <54, 59, 55>, 0,
  <55, 59, 56>, 0,
  <56, 59, 57>, 0,
  <57, 59, 58>, 0,
  <0, 5, 14>, 1,
  <0, 14, 6>, 1,
  <0, 6, 1>, 1,
  <2, 9, 20>, 1,
  <2, 20, 10>, 1,
  <2, 10, 3>, 1,
  <4, 11, 23>, 1,
  <4, 23, 24>, 1,
  <4, 24, 12>, 1,
  <7, 17, 30>, 1,
  <7, 30, 18>, 1,
  <7, 18, 8>, 1,
  <13, 25, 37>, 1,
  <13, 37, 38>, 1,
  <13, 38, 26>, 1,
  <15, 27, 40>, 1,
  <15, 40, 28>, 1,
  <15, 28, 16>, 1,
  <19, 31, 43>, 1,
  <19, 43, 44>, 1,
  <19, 44, 32>, 1,
  <21, 33, 46>, 1,
  <21, 46, 34>, 1,
  <21, 34, 22>, 1,
  <29, 41, 51>, 1,
  <29, 51, 52>, 1,
  <29, 52, 42>, 1,
  <35, 47, 55>, 1,
  <35, 55, 48>, 1,
  <35, 48, 36>, 1,
  <39, 49, 56>, 1,
  <39, 56, 57>, 1,
  <39, 57, 50>, 1,
  <45, 53, 58>, 1,
  <45, 58, 59>, 1,
  <45, 59, 54>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_snub_icosidodecahedron_verts[45];
 #local P1 = Archimedean_snub_icosidodecahedron_verts[53];
 #local P2 = Archimedean_snub_icosidodecahedron_verts[58];
 #local P3 = Archimedean_snub_icosidodecahedron_verts[59];
 #local P4 = Archimedean_snub_icosidodecahedron_verts[54];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_snub_icosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_snub_icosidodecahedron_obj }
#end
#end

#macro Archimedean_snub_icosidodecahedron_faces2(OnPlane)
#local Archimedean_snub_icosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Archimedean_snub_icosidodecahedron_verts[0],
  Archimedean_snub_icosidodecahedron_verts[1],
  Archimedean_snub_icosidodecahedron_verts[2],
  Archimedean_snub_icosidodecahedron_verts[3],
  Archimedean_snub_icosidodecahedron_verts[4],
  Archimedean_snub_icosidodecahedron_verts[5],
  Archimedean_snub_icosidodecahedron_verts[6],
  Archimedean_snub_icosidodecahedron_verts[7],
  Archimedean_snub_icosidodecahedron_verts[8],
  Archimedean_snub_icosidodecahedron_verts[9],
  Archimedean_snub_icosidodecahedron_verts[10],
  Archimedean_snub_icosidodecahedron_verts[11],
  Archimedean_snub_icosidodecahedron_verts[12],
  Archimedean_snub_icosidodecahedron_verts[13],
  Archimedean_snub_icosidodecahedron_verts[14],
  Archimedean_snub_icosidodecahedron_verts[15],
  Archimedean_snub_icosidodecahedron_verts[16],
  Archimedean_snub_icosidodecahedron_verts[17],
  Archimedean_snub_icosidodecahedron_verts[18],
  Archimedean_snub_icosidodecahedron_verts[19],
  Archimedean_snub_icosidodecahedron_verts[20],
  Archimedean_snub_icosidodecahedron_verts[21],
  Archimedean_snub_icosidodecahedron_verts[22],
  Archimedean_snub_icosidodecahedron_verts[23],
  Archimedean_snub_icosidodecahedron_verts[24],
  Archimedean_snub_icosidodecahedron_verts[25],
  Archimedean_snub_icosidodecahedron_verts[26],
  Archimedean_snub_icosidodecahedron_verts[27],
  Archimedean_snub_icosidodecahedron_verts[28],
  Archimedean_snub_icosidodecahedron_verts[29],
  Archimedean_snub_icosidodecahedron_verts[30],
  Archimedean_snub_icosidodecahedron_verts[31],
  Archimedean_snub_icosidodecahedron_verts[32],
  Archimedean_snub_icosidodecahedron_verts[33],
  Archimedean_snub_icosidodecahedron_verts[34],
  Archimedean_snub_icosidodecahedron_verts[35],
  Archimedean_snub_icosidodecahedron_verts[36],
  Archimedean_snub_icosidodecahedron_verts[37],
  Archimedean_snub_icosidodecahedron_verts[38],
  Archimedean_snub_icosidodecahedron_verts[39],
  Archimedean_snub_icosidodecahedron_verts[40],
  Archimedean_snub_icosidodecahedron_verts[41],
  Archimedean_snub_icosidodecahedron_verts[42],
  Archimedean_snub_icosidodecahedron_verts[43],
  Archimedean_snub_icosidodecahedron_verts[44],
  Archimedean_snub_icosidodecahedron_verts[45],
  Archimedean_snub_icosidodecahedron_verts[46],
  Archimedean_snub_icosidodecahedron_verts[47],
  Archimedean_snub_icosidodecahedron_verts[48],
  Archimedean_snub_icosidodecahedron_verts[49],
  Archimedean_snub_icosidodecahedron_verts[50],
  Archimedean_snub_icosidodecahedron_verts[51],
  Archimedean_snub_icosidodecahedron_verts[52],
  Archimedean_snub_icosidodecahedron_verts[53],
  Archimedean_snub_icosidodecahedron_verts[54],
  Archimedean_snub_icosidodecahedron_verts[55],
  Archimedean_snub_icosidodecahedron_verts[56],
  Archimedean_snub_icosidodecahedron_verts[57],
  Archimedean_snub_icosidodecahedron_verts[58],
  Archimedean_snub_icosidodecahedron_verts[59]
 }
 face_indices {
  116,
  <0, 1, 2>,
  <0, 2, 3>,
  <0, 3, 4>,
  <0, 4, 5>,
  <1, 6, 7>,
  <1, 7, 8>,
  <1, 8, 2>,
  <2, 8, 9>,
  <3, 10, 11>,
  <3, 11, 4>,
  <4, 12, 5>,
  <5, 12, 13>,
  <5, 13, 14>,
  <6, 14, 15>,
  <6, 15, 16>,
  <6, 16, 7>,
  <7, 16, 17>,
  <8, 18, 9>,
  <9, 18, 19>,
  <9, 19, 20>,
  <10, 20, 21>,
  <10, 21, 22>,
  <10, 22, 11>,
  <11, 22, 23>,
  <12, 24, 25>,
  <12, 25, 13>,
  <13, 26, 14>,
  <14, 26, 15>,
  <15, 26, 27>,
  <16, 28, 17>,
  <17, 28, 29>,
  <17, 29, 30>,
  <18, 30, 31>,
  <18, 31, 19>,
  <19, 32, 20>,
  <20, 32, 21>,
  <21, 32, 33>,
  <22, 34, 23>,
  <23, 34, 35>,
  <23, 35, 24>,
  <24, 35, 36>,
  <24, 36, 25>,
  <25, 36, 37>,
  <26, 38, 27>,
  <27, 38, 39>,
  <27, 39, 40>,
  <28, 40, 41>,
  <28, 41, 29>,
  <29, 42, 30>,
  <30, 42, 31>,
  <31, 42, 43>,
  <32, 44, 33>,
  <33, 44, 45>,
  <33, 45, 46>,
  <34, 46, 47>,
  <34, 47, 35>,
  <36, 48, 37>,
  <37, 48, 49>,
  <37, 49, 38>,
  <38, 49, 39>,
  <39, 50, 40>,
  <40, 50, 41>,
  <41, 50, 51>,
  <42, 52, 43>,
  <43, 52, 53>,
  <43, 53, 44>,
  <44, 53, 45>,
  <45, 54, 46>,
  <46, 54, 47>,
  <47, 54, 55>,
  <48, 55, 56>,
  <48, 56, 49>,
  <50, 57, 51>,
  <51, 57, 58>,
  <51, 58, 52>,
  <52, 58, 53>,
  <54, 59, 55>,
  <55, 59, 56>,
  <56, 59, 57>,
  <57, 59, 58>,
  <0, 5, 14>,
  <0, 14, 6>,
  <0, 6, 1>,
  <2, 9, 20>,
  <2, 20, 10>,
  <2, 10, 3>,
  <4, 11, 23>,
  <4, 23, 24>,
  <4, 24, 12>,
  <7, 17, 30>,
  <7, 30, 18>,
  <7, 18, 8>,
  <13, 25, 37>,
  <13, 37, 38>,
  <13, 38, 26>,
  <15, 27, 40>,
  <15, 40, 28>,
  <15, 28, 16>,
  <19, 31, 43>,
  <19, 43, 44>,
  <19, 44, 32>,
  <21, 33, 46>,
  <21, 46, 34>,
  <21, 34, 22>,
  <29, 41, 51>,
  <29, 51, 52>,
  <29, 52, 42>,
  <35, 47, 55>,
  <35, 55, 48>,
  <35, 48, 36>,
  <39, 49, 56>,
  <39, 56, 57>,
  <39, 57, 50>,
  <45, 53, 58>,
  <45, 58, 59>,
  <45, 59, 54>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Archimedean_snub_icosidodecahedron_verts[45];
 #local P1 = Archimedean_snub_icosidodecahedron_verts[53];
 #local P2 = Archimedean_snub_icosidodecahedron_verts[58];
 #local P3 = Archimedean_snub_icosidodecahedron_verts[59];
 #local P4 = Archimedean_snub_icosidodecahedron_verts[54];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Archimedean_snub_icosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Archimedean_snub_icosidodecahedron_obj }
#end
#end

#macro Archimedean_snub_icosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Archimedean_snub_icosidodecahedron_verts[0], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[1], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[2], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[3], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[4], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[5], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[6], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[7], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[8], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[9], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[10], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[11], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[12], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[13], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[14], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[15], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[16], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[17], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[18], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[19], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[20], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[21], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[22], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[23], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[24], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[25], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[26], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[27], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[28], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[29], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[30], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[31], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[32], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[33], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[34], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[35], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[36], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[37], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[38], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[39], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[40], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[41], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[42], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[43], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[44], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[45], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[46], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[47], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[48], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[49], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[50], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[51], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[52], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[53], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[54], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[55], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[56], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[57], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[58], RadVer }
  sphere { Archimedean_snub_icosidodecahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Archimedean_snub_icosidodecahedron_verts[0], Archimedean_snub_icosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[1], Archimedean_snub_icosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[2], Archimedean_snub_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[2], Archimedean_snub_icosidodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[3], Archimedean_snub_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[3], Archimedean_snub_icosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[4], Archimedean_snub_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[4], Archimedean_snub_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[5], Archimedean_snub_icosidodecahedron_verts[0], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[1], Archimedean_snub_icosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[6], Archimedean_snub_icosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[7], Archimedean_snub_icosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[7], Archimedean_snub_icosidodecahedron_verts[8], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[8], Archimedean_snub_icosidodecahedron_verts[1], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[8], Archimedean_snub_icosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[8], Archimedean_snub_icosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[9], Archimedean_snub_icosidodecahedron_verts[2], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[3], Archimedean_snub_icosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[10], Archimedean_snub_icosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[11], Archimedean_snub_icosidodecahedron_verts[3], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[11], Archimedean_snub_icosidodecahedron_verts[4], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[4], Archimedean_snub_icosidodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[12], Archimedean_snub_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[12], Archimedean_snub_icosidodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[13], Archimedean_snub_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[13], Archimedean_snub_icosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[14], Archimedean_snub_icosidodecahedron_verts[5], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[6], Archimedean_snub_icosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[14], Archimedean_snub_icosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[15], Archimedean_snub_icosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[15], Archimedean_snub_icosidodecahedron_verts[16], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[16], Archimedean_snub_icosidodecahedron_verts[6], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[16], Archimedean_snub_icosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[16], Archimedean_snub_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[17], Archimedean_snub_icosidodecahedron_verts[7], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[8], Archimedean_snub_icosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[18], Archimedean_snub_icosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[18], Archimedean_snub_icosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[19], Archimedean_snub_icosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[19], Archimedean_snub_icosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[20], Archimedean_snub_icosidodecahedron_verts[9], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[10], Archimedean_snub_icosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[20], Archimedean_snub_icosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[21], Archimedean_snub_icosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[21], Archimedean_snub_icosidodecahedron_verts[22], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[22], Archimedean_snub_icosidodecahedron_verts[10], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[22], Archimedean_snub_icosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[22], Archimedean_snub_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[23], Archimedean_snub_icosidodecahedron_verts[11], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[12], Archimedean_snub_icosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[24], Archimedean_snub_icosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[25], Archimedean_snub_icosidodecahedron_verts[12], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[25], Archimedean_snub_icosidodecahedron_verts[13], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[13], Archimedean_snub_icosidodecahedron_verts[26], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[26], Archimedean_snub_icosidodecahedron_verts[14], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[26], Archimedean_snub_icosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[26], Archimedean_snub_icosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[27], Archimedean_snub_icosidodecahedron_verts[15], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[16], Archimedean_snub_icosidodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[28], Archimedean_snub_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[28], Archimedean_snub_icosidodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[29], Archimedean_snub_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[29], Archimedean_snub_icosidodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[30], Archimedean_snub_icosidodecahedron_verts[17], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[18], Archimedean_snub_icosidodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[30], Archimedean_snub_icosidodecahedron_verts[31], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[31], Archimedean_snub_icosidodecahedron_verts[18], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[31], Archimedean_snub_icosidodecahedron_verts[19], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[19], Archimedean_snub_icosidodecahedron_verts[32], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[32], Archimedean_snub_icosidodecahedron_verts[20], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[32], Archimedean_snub_icosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[32], Archimedean_snub_icosidodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[33], Archimedean_snub_icosidodecahedron_verts[21], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[22], Archimedean_snub_icosidodecahedron_verts[34], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[34], Archimedean_snub_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[34], Archimedean_snub_icosidodecahedron_verts[35], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[35], Archimedean_snub_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[35], Archimedean_snub_icosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[24], Archimedean_snub_icosidodecahedron_verts[23], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[35], Archimedean_snub_icosidodecahedron_verts[36], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[36], Archimedean_snub_icosidodecahedron_verts[24], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[36], Archimedean_snub_icosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[36], Archimedean_snub_icosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[37], Archimedean_snub_icosidodecahedron_verts[25], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[26], Archimedean_snub_icosidodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[38], Archimedean_snub_icosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[38], Archimedean_snub_icosidodecahedron_verts[39], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[39], Archimedean_snub_icosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[39], Archimedean_snub_icosidodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[40], Archimedean_snub_icosidodecahedron_verts[27], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[28], Archimedean_snub_icosidodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[40], Archimedean_snub_icosidodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[41], Archimedean_snub_icosidodecahedron_verts[28], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[41], Archimedean_snub_icosidodecahedron_verts[29], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[29], Archimedean_snub_icosidodecahedron_verts[42], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[42], Archimedean_snub_icosidodecahedron_verts[30], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[42], Archimedean_snub_icosidodecahedron_verts[31], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[42], Archimedean_snub_icosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[43], Archimedean_snub_icosidodecahedron_verts[31], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[32], Archimedean_snub_icosidodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[44], Archimedean_snub_icosidodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[44], Archimedean_snub_icosidodecahedron_verts[45], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[45], Archimedean_snub_icosidodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[45], Archimedean_snub_icosidodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[46], Archimedean_snub_icosidodecahedron_verts[33], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[34], Archimedean_snub_icosidodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[46], Archimedean_snub_icosidodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[47], Archimedean_snub_icosidodecahedron_verts[34], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[47], Archimedean_snub_icosidodecahedron_verts[35], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[36], Archimedean_snub_icosidodecahedron_verts[48], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[48], Archimedean_snub_icosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[48], Archimedean_snub_icosidodecahedron_verts[49], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[49], Archimedean_snub_icosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[49], Archimedean_snub_icosidodecahedron_verts[38], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[38], Archimedean_snub_icosidodecahedron_verts[37], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[49], Archimedean_snub_icosidodecahedron_verts[39], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[39], Archimedean_snub_icosidodecahedron_verts[50], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[50], Archimedean_snub_icosidodecahedron_verts[40], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[50], Archimedean_snub_icosidodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[50], Archimedean_snub_icosidodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[51], Archimedean_snub_icosidodecahedron_verts[41], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[42], Archimedean_snub_icosidodecahedron_verts[52], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[52], Archimedean_snub_icosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[52], Archimedean_snub_icosidodecahedron_verts[53], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[53], Archimedean_snub_icosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[53], Archimedean_snub_icosidodecahedron_verts[44], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[44], Archimedean_snub_icosidodecahedron_verts[43], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[53], Archimedean_snub_icosidodecahedron_verts[45], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[45], Archimedean_snub_icosidodecahedron_verts[54], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[54], Archimedean_snub_icosidodecahedron_verts[46], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[54], Archimedean_snub_icosidodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[54], Archimedean_snub_icosidodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[55], Archimedean_snub_icosidodecahedron_verts[47], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[48], Archimedean_snub_icosidodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[55], Archimedean_snub_icosidodecahedron_verts[56], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[56], Archimedean_snub_icosidodecahedron_verts[48], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[56], Archimedean_snub_icosidodecahedron_verts[49], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[50], Archimedean_snub_icosidodecahedron_verts[57], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[57], Archimedean_snub_icosidodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[57], Archimedean_snub_icosidodecahedron_verts[58], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[58], Archimedean_snub_icosidodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[58], Archimedean_snub_icosidodecahedron_verts[52], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[52], Archimedean_snub_icosidodecahedron_verts[51], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[58], Archimedean_snub_icosidodecahedron_verts[53], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[54], Archimedean_snub_icosidodecahedron_verts[59], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[59], Archimedean_snub_icosidodecahedron_verts[55], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[59], Archimedean_snub_icosidodecahedron_verts[56], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[59], Archimedean_snub_icosidodecahedron_verts[57], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[57], Archimedean_snub_icosidodecahedron_verts[56], RadEdg }
  cylinder { Archimedean_snub_icosidodecahedron_verts[59], Archimedean_snub_icosidodecahedron_verts[58], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Archimedean_snub_icosidodecahedron_verts[45];
 #local P1 = Archimedean_snub_icosidodecahedron_verts[53];
 #local P2 = Archimedean_snub_icosidodecahedron_verts[58];
 #local P3 = Archimedean_snub_icosidodecahedron_verts[59];
 #local P4 = Archimedean_snub_icosidodecahedron_verts[54];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
