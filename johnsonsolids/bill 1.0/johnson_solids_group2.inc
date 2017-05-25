/* -------------------
johnson_solids_group1.inc

Modified pyramids and dipyramids

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Johnson_07_elongated_triangular_pyramid (7 vertices)
  Johnson_08_elongated_square_pyramid (9 vertices)
  Johnson_09_elongated_pentagonal_pyramid (11 vertices)
  Johnson_10_gyroelongated_square_pyramid (9 vertices)
  Johnson_11_gyroelongated_pentagonal_pyramid (11 vertices)
  Johnson_12_triangular_dipyramid (5 vertices)
  Johnson_13_pentagonal_dipyramid (7 vertices)
  Johnson_14_elongated_triangular_dipyramid (8 vertices)
  Johnson_15_elongated_square_dipyramid (10 vertices)
  Johnson_16_elongated_pentagonal_dipyramid (12 vertices)
  Johnson_17_gyroelongated_square_dipyramid (10 vertices)

-------------------- */

#include "transforms.inc"

#declare Johnson_07_elongated_triangular_pyramid_verts = array[7]
{
<-0.793941, -0.708614, 0.016702>,
<-0.451882, 0.284418, 0.565280>,
<-0.252303, -0.348111, -0.973610>,
<0.089756, 0.644920, -0.425033>,
<0.340161, -0.993103, -0.175472>,
<0.385988, 1.120562, 0.619029>,
<0.682220, -0.000072, 0.373105>,
}
#declare P0 = Johnson_07_elongated_triangular_pyramid_verts[0];
#declare P1 = Johnson_07_elongated_triangular_pyramid_verts[2];
#declare P2 = Johnson_07_elongated_triangular_pyramid_verts[4];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 7)
 #declare Johnson_07_elongated_triangular_pyramid_verts[Num] = vtransform(Johnson_07_elongated_triangular_pyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_07_elongated_triangular_pyramid_faces(Tex3, Tex4, OnPlane)
#local Johnson_07_elongated_triangular_pyramid_obj = mesh2 {
 vertex_vectors {
  7,
  Johnson_07_elongated_triangular_pyramid_verts[0],
  Johnson_07_elongated_triangular_pyramid_verts[1],
  Johnson_07_elongated_triangular_pyramid_verts[2],
  Johnson_07_elongated_triangular_pyramid_verts[3],
  Johnson_07_elongated_triangular_pyramid_verts[4],
  Johnson_07_elongated_triangular_pyramid_verts[5],
  Johnson_07_elongated_triangular_pyramid_verts[6]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  10,
  <0, 2, 4>, 0,
  <5, 3, 1>, 0,
  <5, 1, 6>, 0,
  <5, 6, 3>, 0,
  <3, 2, 0>, 1,
  <3, 0, 1>, 1,
  <1, 0, 4>, 1,
  <1, 4, 6>, 1,
  <6, 4, 2>, 1,
  <6, 2, 3>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_07_elongated_triangular_pyramid_verts[0];
 #local P1 = Johnson_07_elongated_triangular_pyramid_verts[2];
 #local P2 = Johnson_07_elongated_triangular_pyramid_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_07_elongated_triangular_pyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_07_elongated_triangular_pyramid_obj }
#end
#end

#macro Johnson_07_elongated_triangular_pyramid_faces2(OnPlane)
#local Johnson_07_elongated_triangular_pyramid_obj = mesh2 {
 vertex_vectors {
  7,
  Johnson_07_elongated_triangular_pyramid_verts[0],
  Johnson_07_elongated_triangular_pyramid_verts[1],
  Johnson_07_elongated_triangular_pyramid_verts[2],
  Johnson_07_elongated_triangular_pyramid_verts[3],
  Johnson_07_elongated_triangular_pyramid_verts[4],
  Johnson_07_elongated_triangular_pyramid_verts[5],
  Johnson_07_elongated_triangular_pyramid_verts[6]
 }
 face_indices {
  10,
  <0, 2, 4>,
  <5, 3, 1>,
  <5, 1, 6>,
  <5, 6, 3>,
  <3, 2, 0>,
  <3, 0, 1>,
  <1, 0, 4>,
  <1, 4, 6>,
  <6, 4, 2>,
  <6, 2, 3>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_07_elongated_triangular_pyramid_verts[0];
 #local P1 = Johnson_07_elongated_triangular_pyramid_verts[2];
 #local P2 = Johnson_07_elongated_triangular_pyramid_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_07_elongated_triangular_pyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_07_elongated_triangular_pyramid_obj }
#end
#end

#macro Johnson_07_elongated_triangular_pyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_07_elongated_triangular_pyramid_verts[0], RadVer }
  sphere { Johnson_07_elongated_triangular_pyramid_verts[1], RadVer }
  sphere { Johnson_07_elongated_triangular_pyramid_verts[2], RadVer }
  sphere { Johnson_07_elongated_triangular_pyramid_verts[3], RadVer }
  sphere { Johnson_07_elongated_triangular_pyramid_verts[4], RadVer }
  sphere { Johnson_07_elongated_triangular_pyramid_verts[5], RadVer }
  sphere { Johnson_07_elongated_triangular_pyramid_verts[6], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[0], Johnson_07_elongated_triangular_pyramid_verts[2], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[2], Johnson_07_elongated_triangular_pyramid_verts[4], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[4], Johnson_07_elongated_triangular_pyramid_verts[0], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[5], Johnson_07_elongated_triangular_pyramid_verts[3], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[3], Johnson_07_elongated_triangular_pyramid_verts[1], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[1], Johnson_07_elongated_triangular_pyramid_verts[5], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[1], Johnson_07_elongated_triangular_pyramid_verts[6], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[6], Johnson_07_elongated_triangular_pyramid_verts[5], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[6], Johnson_07_elongated_triangular_pyramid_verts[3], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[3], Johnson_07_elongated_triangular_pyramid_verts[2], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[0], Johnson_07_elongated_triangular_pyramid_verts[1], RadEdg }
  cylinder { Johnson_07_elongated_triangular_pyramid_verts[4], Johnson_07_elongated_triangular_pyramid_verts[6], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_07_elongated_triangular_pyramid_verts[0];
 #local P1 = Johnson_07_elongated_triangular_pyramid_verts[2];
 #local P2 = Johnson_07_elongated_triangular_pyramid_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_08_elongated_square_pyramid_verts = array[9]
{
<-0.849167, -0.427323, 0.457421>,
<-0.849167, 0.619869, 0.087182>,
<-0.478929, -0.776386, -0.529881>,
<-0.478929, 0.270805, -0.900119>,
<0.198024, -0.303910, 0.806484>,
<0.198024, 0.743282, 0.436246>,
<0.568263, -0.652974, -0.180817>,
<0.568263, 0.394218, -0.551056>,
<1.123620, 0.132420, 0.374540>,
}
#declare P0 = Johnson_08_elongated_square_pyramid_verts[0];
#declare P1 = Johnson_08_elongated_square_pyramid_verts[1];
#declare P2 = Johnson_08_elongated_square_pyramid_verts[2];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 9)
 #declare Johnson_08_elongated_square_pyramid_verts[Num] = vtransform(Johnson_08_elongated_square_pyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_08_elongated_square_pyramid_faces(Tex3, Tex4, OnPlane)
#local Johnson_08_elongated_square_pyramid_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_08_elongated_square_pyramid_verts[0],
  Johnson_08_elongated_square_pyramid_verts[1],
  Johnson_08_elongated_square_pyramid_verts[2],
  Johnson_08_elongated_square_pyramid_verts[3],
  Johnson_08_elongated_square_pyramid_verts[4],
  Johnson_08_elongated_square_pyramid_verts[5],
  Johnson_08_elongated_square_pyramid_verts[6],
  Johnson_08_elongated_square_pyramid_verts[7],
  Johnson_08_elongated_square_pyramid_verts[8]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  14,
  <8, 7, 5>, 0,
  <8, 5, 4>, 0,
  <8, 4, 6>, 0,
  <8, 6, 7>, 0,
  <1, 3, 2>, 1,
  <1, 2, 0>, 1,
  <7, 3, 1>, 1,
  <7, 1, 5>, 1,
  <5, 1, 0>, 1,
  <5, 0, 4>, 1,
  <4, 0, 2>, 1,
  <4, 2, 6>, 1,
  <6, 2, 3>, 1,
  <6, 3, 7>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_08_elongated_square_pyramid_verts[0];
 #local P1 = Johnson_08_elongated_square_pyramid_verts[1];
 #local P2 = Johnson_08_elongated_square_pyramid_verts[2];
 #local P3 = Johnson_08_elongated_square_pyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_08_elongated_square_pyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_08_elongated_square_pyramid_obj }
#end
#end

#macro Johnson_08_elongated_square_pyramid_faces2(OnPlane)
#local Johnson_08_elongated_square_pyramid_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_08_elongated_square_pyramid_verts[0],
  Johnson_08_elongated_square_pyramid_verts[1],
  Johnson_08_elongated_square_pyramid_verts[2],
  Johnson_08_elongated_square_pyramid_verts[3],
  Johnson_08_elongated_square_pyramid_verts[4],
  Johnson_08_elongated_square_pyramid_verts[5],
  Johnson_08_elongated_square_pyramid_verts[6],
  Johnson_08_elongated_square_pyramid_verts[7],
  Johnson_08_elongated_square_pyramid_verts[8]
 }
 face_indices {
  14,
  <8, 7, 5>,
  <8, 5, 4>,
  <8, 4, 6>,
  <8, 6, 7>,
  <1, 3, 2>,
  <1, 2, 0>,
  <7, 3, 1>,
  <7, 1, 5>,
  <5, 1, 0>,
  <5, 0, 4>,
  <4, 0, 2>,
  <4, 2, 6>,
  <6, 2, 3>,
  <6, 3, 7>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_08_elongated_square_pyramid_verts[0];
 #local P1 = Johnson_08_elongated_square_pyramid_verts[1];
 #local P2 = Johnson_08_elongated_square_pyramid_verts[2];
 #local P3 = Johnson_08_elongated_square_pyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_08_elongated_square_pyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_08_elongated_square_pyramid_obj }
#end
#end

#macro Johnson_08_elongated_square_pyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_08_elongated_square_pyramid_verts[0], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[1], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[2], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[3], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[4], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[5], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[6], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[7], RadVer }
  sphere { Johnson_08_elongated_square_pyramid_verts[8], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_08_elongated_square_pyramid_verts[8], Johnson_08_elongated_square_pyramid_verts[7], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[7], Johnson_08_elongated_square_pyramid_verts[5], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[5], Johnson_08_elongated_square_pyramid_verts[8], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[5], Johnson_08_elongated_square_pyramid_verts[4], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[4], Johnson_08_elongated_square_pyramid_verts[8], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[4], Johnson_08_elongated_square_pyramid_verts[6], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[6], Johnson_08_elongated_square_pyramid_verts[8], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[6], Johnson_08_elongated_square_pyramid_verts[7], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[1], Johnson_08_elongated_square_pyramid_verts[3], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[3], Johnson_08_elongated_square_pyramid_verts[2], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[2], Johnson_08_elongated_square_pyramid_verts[0], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[0], Johnson_08_elongated_square_pyramid_verts[1], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[7], Johnson_08_elongated_square_pyramid_verts[3], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[1], Johnson_08_elongated_square_pyramid_verts[5], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[0], Johnson_08_elongated_square_pyramid_verts[4], RadEdg }
  cylinder { Johnson_08_elongated_square_pyramid_verts[2], Johnson_08_elongated_square_pyramid_verts[6], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_08_elongated_square_pyramid_verts[0];
 #local P1 = Johnson_08_elongated_square_pyramid_verts[1];
 #local P2 = Johnson_08_elongated_square_pyramid_verts[2];
 #local P3 = Johnson_08_elongated_square_pyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_09_elongated_pentagonal_pyramid_verts = array[11]
{
<-0.980309, -0.338780, 0.175213>,
<-0.719686, 0.629425, 0.022210>,
<-0.520232, -0.599402, -0.690328>,
<-0.299303, -0.403757, 0.924054>,
<-0.259610, 0.368802, -0.843330>,
<-0.038680, 0.564448, 0.771051>,
<0.243026, 0.902834, -0.142672>,
<0.445117, -0.825453, -0.476420>,
<0.581659, -0.704537, 0.521323>,
<0.705739, 0.142752, -0.629422>,
<0.842281, 0.263667, 0.368320>,
}
#declare P0 = Johnson_09_elongated_pentagonal_pyramid_verts[8];
#declare P1 = Johnson_09_elongated_pentagonal_pyramid_verts[3];
#declare P2 = Johnson_09_elongated_pentagonal_pyramid_verts[0];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 11)
 #declare Johnson_09_elongated_pentagonal_pyramid_verts[Num] = vtransform(Johnson_09_elongated_pentagonal_pyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_09_elongated_pentagonal_pyramid_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_09_elongated_pentagonal_pyramid_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_09_elongated_pentagonal_pyramid_verts[0],
  Johnson_09_elongated_pentagonal_pyramid_verts[1],
  Johnson_09_elongated_pentagonal_pyramid_verts[2],
  Johnson_09_elongated_pentagonal_pyramid_verts[3],
  Johnson_09_elongated_pentagonal_pyramid_verts[4],
  Johnson_09_elongated_pentagonal_pyramid_verts[5],
  Johnson_09_elongated_pentagonal_pyramid_verts[6],
  Johnson_09_elongated_pentagonal_pyramid_verts[7],
  Johnson_09_elongated_pentagonal_pyramid_verts[8],
  Johnson_09_elongated_pentagonal_pyramid_verts[9],
  Johnson_09_elongated_pentagonal_pyramid_verts[10]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  18,
  <6, 1, 5>, 0,
  <6, 5, 10>, 0,
  <6, 10, 9>, 0,
  <6, 9, 4>, 0,
  <6, 4, 1>, 0,
  <1, 0, 3>, 1,
  <1, 3, 5>, 1,
  <5, 3, 8>, 1,
  <5, 8, 10>, 1,
  <10, 8, 7>, 1,
  <10, 7, 9>, 1,
  <9, 7, 2>, 1,
  <9, 2, 4>, 1,
  <4, 2, 0>, 1,
  <4, 0, 1>, 1,
  <8, 3, 0>, 2,
  <8, 0, 2>, 2,
  <8, 2, 7>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_09_elongated_pentagonal_pyramid_verts[8];
 #local P1 = Johnson_09_elongated_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_09_elongated_pentagonal_pyramid_verts[0];
 #local P3 = Johnson_09_elongated_pentagonal_pyramid_verts[2];
 #local P4 = Johnson_09_elongated_pentagonal_pyramid_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_09_elongated_pentagonal_pyramid_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_09_elongated_pentagonal_pyramid_obj }
#end
#end

#macro Johnson_09_elongated_pentagonal_pyramid_faces2(OnPlane)
#local Johnson_09_elongated_pentagonal_pyramid_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_09_elongated_pentagonal_pyramid_verts[0],
  Johnson_09_elongated_pentagonal_pyramid_verts[1],
  Johnson_09_elongated_pentagonal_pyramid_verts[2],
  Johnson_09_elongated_pentagonal_pyramid_verts[3],
  Johnson_09_elongated_pentagonal_pyramid_verts[4],
  Johnson_09_elongated_pentagonal_pyramid_verts[5],
  Johnson_09_elongated_pentagonal_pyramid_verts[6],
  Johnson_09_elongated_pentagonal_pyramid_verts[7],
  Johnson_09_elongated_pentagonal_pyramid_verts[8],
  Johnson_09_elongated_pentagonal_pyramid_verts[9],
  Johnson_09_elongated_pentagonal_pyramid_verts[10]
 }
 face_indices {
  18,
  <6, 1, 5>,
  <6, 5, 10>,
  <6, 10, 9>,
  <6, 9, 4>,
  <6, 4, 1>,
  <1, 0, 3>,
  <1, 3, 5>,
  <5, 3, 8>,
  <5, 8, 10>,
  <10, 8, 7>,
  <10, 7, 9>,
  <9, 7, 2>,
  <9, 2, 4>,
  <4, 2, 0>,
  <4, 0, 1>,
  <8, 3, 0>,
  <8, 0, 2>,
  <8, 2, 7>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_09_elongated_pentagonal_pyramid_verts[8];
 #local P1 = Johnson_09_elongated_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_09_elongated_pentagonal_pyramid_verts[0];
 #local P3 = Johnson_09_elongated_pentagonal_pyramid_verts[2];
 #local P4 = Johnson_09_elongated_pentagonal_pyramid_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_09_elongated_pentagonal_pyramid_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_09_elongated_pentagonal_pyramid_obj }
#end
#end

#macro Johnson_09_elongated_pentagonal_pyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[0], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[1], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[2], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[3], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[4], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[5], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[6], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[7], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[8], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[9], RadVer }
  sphere { Johnson_09_elongated_pentagonal_pyramid_verts[10], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[6], Johnson_09_elongated_pentagonal_pyramid_verts[1], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[1], Johnson_09_elongated_pentagonal_pyramid_verts[5], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[5], Johnson_09_elongated_pentagonal_pyramid_verts[6], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[5], Johnson_09_elongated_pentagonal_pyramid_verts[10], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[10], Johnson_09_elongated_pentagonal_pyramid_verts[6], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[10], Johnson_09_elongated_pentagonal_pyramid_verts[9], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[9], Johnson_09_elongated_pentagonal_pyramid_verts[6], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[9], Johnson_09_elongated_pentagonal_pyramid_verts[4], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[4], Johnson_09_elongated_pentagonal_pyramid_verts[6], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[4], Johnson_09_elongated_pentagonal_pyramid_verts[1], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[1], Johnson_09_elongated_pentagonal_pyramid_verts[0], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[0], Johnson_09_elongated_pentagonal_pyramid_verts[3], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[3], Johnson_09_elongated_pentagonal_pyramid_verts[5], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[3], Johnson_09_elongated_pentagonal_pyramid_verts[8], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[8], Johnson_09_elongated_pentagonal_pyramid_verts[10], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[8], Johnson_09_elongated_pentagonal_pyramid_verts[7], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[7], Johnson_09_elongated_pentagonal_pyramid_verts[9], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[7], Johnson_09_elongated_pentagonal_pyramid_verts[2], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[2], Johnson_09_elongated_pentagonal_pyramid_verts[4], RadEdg }
  cylinder { Johnson_09_elongated_pentagonal_pyramid_verts[2], Johnson_09_elongated_pentagonal_pyramid_verts[0], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_09_elongated_pentagonal_pyramid_verts[8];
 #local P1 = Johnson_09_elongated_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_09_elongated_pentagonal_pyramid_verts[0];
 #local P3 = Johnson_09_elongated_pentagonal_pyramid_verts[2];
 #local P4 = Johnson_09_elongated_pentagonal_pyramid_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_10_gyroelongated_square_pyramid_verts = array[9]
{
<-0.776892, 0.173498, 0.416855>,
<-0.681550, 0.270757, -0.747914>,
<-0.646922, -0.787150, -0.243069>,
<0.020463, 0.897066, -0.047806>,
<0.069435, -0.599041, 0.666153>,
<0.152630, 0.505992, 1.049841>,
<0.480709, 0.236129, -0.900199>,
<0.515337, -0.821778, -0.395353>,
<0.866791, 0.124527, 0.201492>,
}
#declare P0 = Johnson_10_gyroelongated_square_pyramid_verts[7];
#declare P1 = Johnson_10_gyroelongated_square_pyramid_verts[1];
#declare P2 = Johnson_10_gyroelongated_square_pyramid_verts[6];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 9)
 #declare Johnson_10_gyroelongated_square_pyramid_verts[Num] = vtransform(Johnson_10_gyroelongated_square_pyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_10_gyroelongated_square_pyramid_faces(Tex3, Tex4, OnPlane)
#local Johnson_10_gyroelongated_square_pyramid_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_10_gyroelongated_square_pyramid_verts[0],
  Johnson_10_gyroelongated_square_pyramid_verts[1],
  Johnson_10_gyroelongated_square_pyramid_verts[2],
  Johnson_10_gyroelongated_square_pyramid_verts[3],
  Johnson_10_gyroelongated_square_pyramid_verts[4],
  Johnson_10_gyroelongated_square_pyramid_verts[5],
  Johnson_10_gyroelongated_square_pyramid_verts[6],
  Johnson_10_gyroelongated_square_pyramid_verts[7],
  Johnson_10_gyroelongated_square_pyramid_verts[8]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  14,
  <4, 7, 8>, 0,
  <8, 7, 6>, 0,
  <8, 6, 3>, 0,
  <3, 6, 1>, 0,
  <3, 1, 0>, 0,
  <0, 1, 2>, 0,
  <0, 2, 4>, 0,
  <4, 2, 7>, 0,
  <4, 8, 5>, 0,
  <8, 3, 5>, 0,
  <3, 0, 5>, 0,
  <0, 4, 5>, 0,
  <1, 6, 7>, 1,
  <1, 7, 2>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_10_gyroelongated_square_pyramid_verts[1];
 #local P1 = Johnson_10_gyroelongated_square_pyramid_verts[6];
 #local P2 = Johnson_10_gyroelongated_square_pyramid_verts[7];
 #local P3 = Johnson_10_gyroelongated_square_pyramid_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_10_gyroelongated_square_pyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_10_gyroelongated_square_pyramid_obj }
#end
#end

#macro Johnson_10_gyroelongated_square_pyramid_faces2(OnPlane)
#local Johnson_10_gyroelongated_square_pyramid_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_10_gyroelongated_square_pyramid_verts[0],
  Johnson_10_gyroelongated_square_pyramid_verts[1],
  Johnson_10_gyroelongated_square_pyramid_verts[2],
  Johnson_10_gyroelongated_square_pyramid_verts[3],
  Johnson_10_gyroelongated_square_pyramid_verts[4],
  Johnson_10_gyroelongated_square_pyramid_verts[5],
  Johnson_10_gyroelongated_square_pyramid_verts[6],
  Johnson_10_gyroelongated_square_pyramid_verts[7],
  Johnson_10_gyroelongated_square_pyramid_verts[8]
 }
 face_indices {
  14,
  <4, 7, 8>,
  <8, 7, 6>,
  <8, 6, 3>,
  <3, 6, 1>,
  <3, 1, 0>,
  <0, 1, 2>,
  <0, 2, 4>,
  <4, 2, 7>,
  <4, 8, 5>,
  <8, 3, 5>,
  <3, 0, 5>,
  <0, 4, 5>,
  <1, 6, 7>,
  <1, 7, 2>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_10_gyroelongated_square_pyramid_verts[1];
 #local P1 = Johnson_10_gyroelongated_square_pyramid_verts[6];
 #local P2 = Johnson_10_gyroelongated_square_pyramid_verts[7];
 #local P3 = Johnson_10_gyroelongated_square_pyramid_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_10_gyroelongated_square_pyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_10_gyroelongated_square_pyramid_obj }
#end
#end

#macro Johnson_10_gyroelongated_square_pyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[0], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[1], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[2], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[3], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[4], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[5], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[6], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[7], RadVer }
  sphere { Johnson_10_gyroelongated_square_pyramid_verts[8], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[4], Johnson_10_gyroelongated_square_pyramid_verts[7], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[7], Johnson_10_gyroelongated_square_pyramid_verts[8], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[8], Johnson_10_gyroelongated_square_pyramid_verts[4], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[7], Johnson_10_gyroelongated_square_pyramid_verts[6], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[6], Johnson_10_gyroelongated_square_pyramid_verts[8], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[6], Johnson_10_gyroelongated_square_pyramid_verts[3], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[3], Johnson_10_gyroelongated_square_pyramid_verts[8], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[6], Johnson_10_gyroelongated_square_pyramid_verts[1], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[1], Johnson_10_gyroelongated_square_pyramid_verts[3], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[1], Johnson_10_gyroelongated_square_pyramid_verts[0], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[0], Johnson_10_gyroelongated_square_pyramid_verts[3], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[1], Johnson_10_gyroelongated_square_pyramid_verts[2], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[2], Johnson_10_gyroelongated_square_pyramid_verts[0], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[2], Johnson_10_gyroelongated_square_pyramid_verts[4], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[4], Johnson_10_gyroelongated_square_pyramid_verts[0], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[2], Johnson_10_gyroelongated_square_pyramid_verts[7], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[8], Johnson_10_gyroelongated_square_pyramid_verts[5], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[5], Johnson_10_gyroelongated_square_pyramid_verts[4], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[3], Johnson_10_gyroelongated_square_pyramid_verts[5], RadEdg }
  cylinder { Johnson_10_gyroelongated_square_pyramid_verts[0], Johnson_10_gyroelongated_square_pyramid_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_10_gyroelongated_square_pyramid_verts[1];
 #local P1 = Johnson_10_gyroelongated_square_pyramid_verts[6];
 #local P2 = Johnson_10_gyroelongated_square_pyramid_verts[7];
 #local P3 = Johnson_10_gyroelongated_square_pyramid_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_11_gyroelongated_pentagonal_pyramid_verts = array[11]
{
<-0.722759, -0.425905, 0.628394>,
<-0.669286, 0.622275, 0.513309>,
<-0.502035, -0.868253, -0.304556>,
<-0.415513, 0.827739, -0.490768>,
<-0.312146, -0.093458, -0.996236>,
<0.134982, 0.097675, 0.952322>,
<0.238349, -0.823522, 0.446854>,
<0.324871, 0.872469, 0.260642>,
<0.492123, -0.618058, -0.557222>,
<0.545596, 0.430122, -0.672308>,
<0.885820, -0.021082, 0.219570>,
}
#declare P0 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[1];
#declare P1 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[3];
#declare P2 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[4];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 11)
 #declare Johnson_11_gyroelongated_pentagonal_pyramid_verts[Num] = vtransform(Johnson_11_gyroelongated_pentagonal_pyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_11_gyroelongated_pentagonal_pyramid_faces(Tex3, Tex5, OnPlane)
#local Johnson_11_gyroelongated_pentagonal_pyramid_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[0],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[1],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[2],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[3],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[4],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[5],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[6],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[7],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[8],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[9],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[10]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  18,
  <6, 2, 8>, 0,
  <8, 2, 4>, 0,
  <8, 4, 9>, 0,
  <9, 4, 3>, 0,
  <9, 3, 7>, 0,
  <7, 3, 1>, 0,
  <7, 1, 5>, 0,
  <5, 1, 0>, 0,
  <5, 0, 6>, 0,
  <6, 0, 2>, 0,
  <6, 8, 10>, 0,
  <8, 9, 10>, 0,
  <9, 7, 10>, 0,
  <7, 5, 10>, 0,
  <5, 6, 10>, 0,
  <1, 3, 4>, 1,
  <1, 4, 2>, 1,
  <1, 2, 0>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[1];
 #local P1 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[4];
 #local P3 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[2];
 #local P4 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_11_gyroelongated_pentagonal_pyramid_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_11_gyroelongated_pentagonal_pyramid_obj }
#end
#end

#macro Johnson_11_gyroelongated_pentagonal_pyramid_faces2(OnPlane)
#local Johnson_11_gyroelongated_pentagonal_pyramid_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[0],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[1],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[2],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[3],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[4],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[5],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[6],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[7],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[8],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[9],
  Johnson_11_gyroelongated_pentagonal_pyramid_verts[10]
 }
 face_indices {
  18,
  <6, 2, 8>,
  <8, 2, 4>,
  <8, 4, 9>,
  <9, 4, 3>,
  <9, 3, 7>,
  <7, 3, 1>,
  <7, 1, 5>,
  <5, 1, 0>,
  <5, 0, 6>,
  <6, 0, 2>,
  <6, 8, 10>,
  <8, 9, 10>,
  <9, 7, 10>,
  <7, 5, 10>,
  <5, 6, 10>,
  <1, 3, 4>,
  <1, 4, 2>,
  <1, 2, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[1];
 #local P1 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[4];
 #local P3 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[2];
 #local P4 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_11_gyroelongated_pentagonal_pyramid_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_11_gyroelongated_pentagonal_pyramid_obj }
#end
#end

#macro Johnson_11_gyroelongated_pentagonal_pyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[0], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[1], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[2], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[3], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[4], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[5], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[6], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[7], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[8], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[9], RadVer }
  sphere { Johnson_11_gyroelongated_pentagonal_pyramid_verts[10], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[6], Johnson_11_gyroelongated_pentagonal_pyramid_verts[2], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[2], Johnson_11_gyroelongated_pentagonal_pyramid_verts[8], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[8], Johnson_11_gyroelongated_pentagonal_pyramid_verts[6], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[2], Johnson_11_gyroelongated_pentagonal_pyramid_verts[4], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[4], Johnson_11_gyroelongated_pentagonal_pyramid_verts[8], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[4], Johnson_11_gyroelongated_pentagonal_pyramid_verts[9], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[9], Johnson_11_gyroelongated_pentagonal_pyramid_verts[8], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[4], Johnson_11_gyroelongated_pentagonal_pyramid_verts[3], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[3], Johnson_11_gyroelongated_pentagonal_pyramid_verts[9], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[3], Johnson_11_gyroelongated_pentagonal_pyramid_verts[7], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[7], Johnson_11_gyroelongated_pentagonal_pyramid_verts[9], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[3], Johnson_11_gyroelongated_pentagonal_pyramid_verts[1], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[1], Johnson_11_gyroelongated_pentagonal_pyramid_verts[7], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[1], Johnson_11_gyroelongated_pentagonal_pyramid_verts[5], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[5], Johnson_11_gyroelongated_pentagonal_pyramid_verts[7], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[1], Johnson_11_gyroelongated_pentagonal_pyramid_verts[0], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[0], Johnson_11_gyroelongated_pentagonal_pyramid_verts[5], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[0], Johnson_11_gyroelongated_pentagonal_pyramid_verts[6], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[6], Johnson_11_gyroelongated_pentagonal_pyramid_verts[5], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[0], Johnson_11_gyroelongated_pentagonal_pyramid_verts[2], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[8], Johnson_11_gyroelongated_pentagonal_pyramid_verts[10], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[10], Johnson_11_gyroelongated_pentagonal_pyramid_verts[6], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[9], Johnson_11_gyroelongated_pentagonal_pyramid_verts[10], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[7], Johnson_11_gyroelongated_pentagonal_pyramid_verts[10], RadEdg }
  cylinder { Johnson_11_gyroelongated_pentagonal_pyramid_verts[5], Johnson_11_gyroelongated_pentagonal_pyramid_verts[10], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[1];
 #local P1 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[4];
 #local P3 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[2];
 #local P4 = Johnson_11_gyroelongated_pentagonal_pyramid_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_12_triangular_dipyramid_verts = array[5]
{
<-0.610389, 0.243975, 0.531213>,
<-0.187812, -0.487950, -0.664016>,
<-0.187812, 0.975900, -0.664016>,
<0.187812, -0.975900, 0.664016>,
<0.798201, 0.243975, 0.132803>,
}
#declare P0 = Johnson_12_triangular_dipyramid_verts[0];
#declare P1 = Johnson_12_triangular_dipyramid_verts[1];
#declare P2 = Johnson_12_triangular_dipyramid_verts[4];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 5)
 #declare Johnson_12_triangular_dipyramid_verts[Num] = vtransform(Johnson_12_triangular_dipyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_12_triangular_dipyramid_faces(Tex3, OnPlane)
#local Johnson_12_triangular_dipyramid_obj = mesh2 {
 vertex_vectors {
  5,
  Johnson_12_triangular_dipyramid_verts[0],
  Johnson_12_triangular_dipyramid_verts[1],
  Johnson_12_triangular_dipyramid_verts[2],
  Johnson_12_triangular_dipyramid_verts[3],
  Johnson_12_triangular_dipyramid_verts[4]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  6,
  <1, 3, 0>, 0,
  <3, 4, 0>, 0,
  <3, 1, 4>, 0,
  <0, 2, 1>, 0,
  <0, 4, 2>, 0,
  <2, 4, 1>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_12_triangular_dipyramid_verts[2];
 #local P1 = Johnson_12_triangular_dipyramid_verts[4];
 #local P2 = Johnson_12_triangular_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_12_triangular_dipyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_12_triangular_dipyramid_obj }
#end
#end

#macro Johnson_12_triangular_dipyramid_faces2(OnPlane)
#local Johnson_12_triangular_dipyramid_obj = mesh2 {
 vertex_vectors {
  5,
  Johnson_12_triangular_dipyramid_verts[0],
  Johnson_12_triangular_dipyramid_verts[1],
  Johnson_12_triangular_dipyramid_verts[2],
  Johnson_12_triangular_dipyramid_verts[3],
  Johnson_12_triangular_dipyramid_verts[4]
 }
 face_indices {
  6,
  <1, 3, 0>,
  <3, 4, 0>,
  <3, 1, 4>,
  <0, 2, 1>,
  <0, 4, 2>,
  <2, 4, 1>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_12_triangular_dipyramid_verts[2];
 #local P1 = Johnson_12_triangular_dipyramid_verts[4];
 #local P2 = Johnson_12_triangular_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_12_triangular_dipyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_12_triangular_dipyramid_obj }
#end
#end

#macro Johnson_12_triangular_dipyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_12_triangular_dipyramid_verts[0], RadVer }
  sphere { Johnson_12_triangular_dipyramid_verts[1], RadVer }
  sphere { Johnson_12_triangular_dipyramid_verts[2], RadVer }
  sphere { Johnson_12_triangular_dipyramid_verts[3], RadVer }
  sphere { Johnson_12_triangular_dipyramid_verts[4], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_12_triangular_dipyramid_verts[1], Johnson_12_triangular_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[3], Johnson_12_triangular_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[0], Johnson_12_triangular_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[3], Johnson_12_triangular_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[4], Johnson_12_triangular_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[1], Johnson_12_triangular_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[0], Johnson_12_triangular_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[2], Johnson_12_triangular_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_12_triangular_dipyramid_verts[4], Johnson_12_triangular_dipyramid_verts[2], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_12_triangular_dipyramid_verts[2];
 #local P1 = Johnson_12_triangular_dipyramid_verts[4];
 #local P2 = Johnson_12_triangular_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_13_pentagonal_dipyramid_verts = array[7]
{
<-1.028778, 0.392027, -0.048786>,
<-0.640503, -0.646161, 0.621837>,
<-0.125162, -0.395663, -0.540059>,
<0.004683, 0.888447, -0.651988>,
<0.125161, 0.395663, 0.540059>,
<0.632925, -0.791376, 0.433102>,
<1.031672, 0.157063, -0.354165>,
}
#declare P0 = Johnson_13_pentagonal_dipyramid_verts[0];
#declare P1 = Johnson_13_pentagonal_dipyramid_verts[1];
#declare P2 = Johnson_13_pentagonal_dipyramid_verts[3];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 7)
 #declare Johnson_13_pentagonal_dipyramid_verts[Num] = vtransform(Johnson_13_pentagonal_dipyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_13_pentagonal_dipyramid_faces(Tex3, OnPlane)
#local Johnson_13_pentagonal_dipyramid_obj = mesh2 {
 vertex_vectors {
  7,
  Johnson_13_pentagonal_dipyramid_verts[0],
  Johnson_13_pentagonal_dipyramid_verts[1],
  Johnson_13_pentagonal_dipyramid_verts[2],
  Johnson_13_pentagonal_dipyramid_verts[3],
  Johnson_13_pentagonal_dipyramid_verts[4],
  Johnson_13_pentagonal_dipyramid_verts[5],
  Johnson_13_pentagonal_dipyramid_verts[6]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  10,
  <3, 2, 0>, 0,
  <2, 1, 0>, 0,
  <2, 5, 1>, 0,
  <0, 4, 3>, 0,
  <0, 1, 4>, 0,
  <4, 1, 5>, 0,
  <2, 3, 6>, 0,
  <3, 4, 6>, 0,
  <5, 2, 6>, 0,
  <4, 5, 6>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_13_pentagonal_dipyramid_verts[4];
 #local P1 = Johnson_13_pentagonal_dipyramid_verts[5];
 #local P2 = Johnson_13_pentagonal_dipyramid_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_13_pentagonal_dipyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_13_pentagonal_dipyramid_obj }
#end
#end

#macro Johnson_13_pentagonal_dipyramid_faces2(OnPlane)
#local Johnson_13_pentagonal_dipyramid_obj = mesh2 {
 vertex_vectors {
  7,
  Johnson_13_pentagonal_dipyramid_verts[0],
  Johnson_13_pentagonal_dipyramid_verts[1],
  Johnson_13_pentagonal_dipyramid_verts[2],
  Johnson_13_pentagonal_dipyramid_verts[3],
  Johnson_13_pentagonal_dipyramid_verts[4],
  Johnson_13_pentagonal_dipyramid_verts[5],
  Johnson_13_pentagonal_dipyramid_verts[6]
 }
 face_indices {
  10,
  <3, 2, 0>,
  <2, 1, 0>,
  <2, 5, 1>,
  <0, 4, 3>,
  <0, 1, 4>,
  <4, 1, 5>,
  <2, 3, 6>,
  <3, 4, 6>,
  <5, 2, 6>,
  <4, 5, 6>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_13_pentagonal_dipyramid_verts[4];
 #local P1 = Johnson_13_pentagonal_dipyramid_verts[5];
 #local P2 = Johnson_13_pentagonal_dipyramid_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_13_pentagonal_dipyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_13_pentagonal_dipyramid_obj }
#end
#end

#macro Johnson_13_pentagonal_dipyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_13_pentagonal_dipyramid_verts[0], RadVer }
  sphere { Johnson_13_pentagonal_dipyramid_verts[1], RadVer }
  sphere { Johnson_13_pentagonal_dipyramid_verts[2], RadVer }
  sphere { Johnson_13_pentagonal_dipyramid_verts[3], RadVer }
  sphere { Johnson_13_pentagonal_dipyramid_verts[4], RadVer }
  sphere { Johnson_13_pentagonal_dipyramid_verts[5], RadVer }
  sphere { Johnson_13_pentagonal_dipyramid_verts[6], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_13_pentagonal_dipyramid_verts[3], Johnson_13_pentagonal_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[2], Johnson_13_pentagonal_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[0], Johnson_13_pentagonal_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[2], Johnson_13_pentagonal_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[1], Johnson_13_pentagonal_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[2], Johnson_13_pentagonal_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[5], Johnson_13_pentagonal_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[0], Johnson_13_pentagonal_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[4], Johnson_13_pentagonal_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[1], Johnson_13_pentagonal_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[5], Johnson_13_pentagonal_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[3], Johnson_13_pentagonal_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[6], Johnson_13_pentagonal_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[4], Johnson_13_pentagonal_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_13_pentagonal_dipyramid_verts[6], Johnson_13_pentagonal_dipyramid_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_13_pentagonal_dipyramid_verts[4];
 #local P1 = Johnson_13_pentagonal_dipyramid_verts[5];
 #local P2 = Johnson_13_pentagonal_dipyramid_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_14_elongated_triangular_dipyramid_verts = array[8]
{
<-0.677756, 0.338878, 0.309352>,
<-0.446131, 1.338394, 0.000000>,
<-0.338878, -0.677755, 0.309352>,
<-0.169439, 0.508317, -0.618703>,
<0.169439, -0.508317, -0.618703>,
<0.338878, 0.677756, 0.309352>,
<0.446131, -1.338394, 0.000000>,
<0.677755, -0.338878, 0.309352>,
}
#declare P0 = Johnson_14_elongated_triangular_dipyramid_verts[0];
#declare P1 = Johnson_14_elongated_triangular_dipyramid_verts[3];
#declare P2 = Johnson_14_elongated_triangular_dipyramid_verts[5];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 8)
 #declare Johnson_14_elongated_triangular_dipyramid_verts[Num] = vtransform(Johnson_14_elongated_triangular_dipyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_14_elongated_triangular_dipyramid_faces(Tex3, Tex4, OnPlane)
#local Johnson_14_elongated_triangular_dipyramid_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_14_elongated_triangular_dipyramid_verts[0],
  Johnson_14_elongated_triangular_dipyramid_verts[1],
  Johnson_14_elongated_triangular_dipyramid_verts[2],
  Johnson_14_elongated_triangular_dipyramid_verts[3],
  Johnson_14_elongated_triangular_dipyramid_verts[4],
  Johnson_14_elongated_triangular_dipyramid_verts[5],
  Johnson_14_elongated_triangular_dipyramid_verts[6],
  Johnson_14_elongated_triangular_dipyramid_verts[7]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  12,
  <4, 7, 6>, 0,
  <5, 3, 1>, 0,
  <2, 4, 6>, 0,
  <3, 0, 1>, 0,
  <7, 2, 6>, 0,
  <0, 5, 1>, 0,
  <7, 4, 3>, 1,
  <7, 3, 5>, 1,
  <4, 2, 0>, 1,
  <4, 0, 3>, 1,
  <2, 7, 5>, 1,
  <2, 5, 0>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_14_elongated_triangular_dipyramid_verts[0];
 #local P1 = Johnson_14_elongated_triangular_dipyramid_verts[4];
 #local P2 = Johnson_14_elongated_triangular_dipyramid_verts[2];
 #local P3 = Johnson_14_elongated_triangular_dipyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_14_elongated_triangular_dipyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_14_elongated_triangular_dipyramid_obj }
#end
#end

#macro Johnson_14_elongated_triangular_dipyramid_faces2(OnPlane)
#local Johnson_14_elongated_triangular_dipyramid_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_14_elongated_triangular_dipyramid_verts[0],
  Johnson_14_elongated_triangular_dipyramid_verts[1],
  Johnson_14_elongated_triangular_dipyramid_verts[2],
  Johnson_14_elongated_triangular_dipyramid_verts[3],
  Johnson_14_elongated_triangular_dipyramid_verts[4],
  Johnson_14_elongated_triangular_dipyramid_verts[5],
  Johnson_14_elongated_triangular_dipyramid_verts[6],
  Johnson_14_elongated_triangular_dipyramid_verts[7]
 }
 face_indices {
  12,
  <4, 7, 6>,
  <5, 3, 1>,
  <2, 4, 6>,
  <3, 0, 1>,
  <7, 2, 6>,
  <0, 5, 1>,
  <7, 4, 3>,
  <7, 3, 5>,
  <4, 2, 0>,
  <4, 0, 3>,
  <2, 7, 5>,
  <2, 5, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_14_elongated_triangular_dipyramid_verts[0];
 #local P1 = Johnson_14_elongated_triangular_dipyramid_verts[4];
 #local P2 = Johnson_14_elongated_triangular_dipyramid_verts[2];
 #local P3 = Johnson_14_elongated_triangular_dipyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_14_elongated_triangular_dipyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_14_elongated_triangular_dipyramid_obj }
#end
#end

#macro Johnson_14_elongated_triangular_dipyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[0], RadVer }
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[1], RadVer }
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[2], RadVer }
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[3], RadVer }
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[4], RadVer }
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[5], RadVer }
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[6], RadVer }
  sphere { Johnson_14_elongated_triangular_dipyramid_verts[7], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[4], Johnson_14_elongated_triangular_dipyramid_verts[7], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[7], Johnson_14_elongated_triangular_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[6], Johnson_14_elongated_triangular_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[5], Johnson_14_elongated_triangular_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[3], Johnson_14_elongated_triangular_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[1], Johnson_14_elongated_triangular_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[2], Johnson_14_elongated_triangular_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[6], Johnson_14_elongated_triangular_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[3], Johnson_14_elongated_triangular_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[0], Johnson_14_elongated_triangular_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[7], Johnson_14_elongated_triangular_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[0], Johnson_14_elongated_triangular_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[4], Johnson_14_elongated_triangular_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[5], Johnson_14_elongated_triangular_dipyramid_verts[7], RadEdg }
  cylinder { Johnson_14_elongated_triangular_dipyramid_verts[2], Johnson_14_elongated_triangular_dipyramid_verts[0], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_14_elongated_triangular_dipyramid_verts[0];
 #local P1 = Johnson_14_elongated_triangular_dipyramid_verts[4];
 #local P2 = Johnson_14_elongated_triangular_dipyramid_verts[2];
 #local P3 = Johnson_14_elongated_triangular_dipyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_15_elongated_square_dipyramid_verts = array[10]
{
<-0.669867, 0.334933, -0.529576>,
<-0.669867, 0.334933, 0.529577>,
<-0.404300, 1.212901, 0.000000>,
<-0.334933, -0.669867, -0.529576>,
<-0.334933, -0.669867, 0.529577>,
<0.334933, 0.669867, -0.529576>,
<0.334933, 0.669867, 0.529577>,
<0.404300, -1.212901, 0.000000>,
<0.669867, -0.334933, -0.529576>,
<0.669867, -0.334933, 0.529577>,
}
#declare P0 = Johnson_15_elongated_square_dipyramid_verts[0];
#declare P1 = Johnson_15_elongated_square_dipyramid_verts[1];
#declare P2 = Johnson_15_elongated_square_dipyramid_verts[5];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 10)
 #declare Johnson_15_elongated_square_dipyramid_verts[Num] = vtransform(Johnson_15_elongated_square_dipyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_15_elongated_square_dipyramid_faces(Tex3, Tex4, OnPlane)
#local Johnson_15_elongated_square_dipyramid_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_15_elongated_square_dipyramid_verts[0],
  Johnson_15_elongated_square_dipyramid_verts[1],
  Johnson_15_elongated_square_dipyramid_verts[2],
  Johnson_15_elongated_square_dipyramid_verts[3],
  Johnson_15_elongated_square_dipyramid_verts[4],
  Johnson_15_elongated_square_dipyramid_verts[5],
  Johnson_15_elongated_square_dipyramid_verts[6],
  Johnson_15_elongated_square_dipyramid_verts[7],
  Johnson_15_elongated_square_dipyramid_verts[8],
  Johnson_15_elongated_square_dipyramid_verts[9]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  16,
  <8, 9, 7>, 0,
  <6, 5, 2>, 0,
  <3, 8, 7>, 0,
  <5, 0, 2>, 0,
  <4, 3, 7>, 0,
  <0, 1, 2>, 0,
  <9, 4, 7>, 0,
  <1, 6, 2>, 0,
  <9, 8, 5>, 1,
  <9, 5, 6>, 1,
  <8, 3, 0>, 1,
  <8, 0, 5>, 1,
  <3, 4, 1>, 1,
  <3, 1, 0>, 1,
  <4, 9, 6>, 1,
  <4, 6, 1>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_15_elongated_square_dipyramid_verts[4];
 #local P1 = Johnson_15_elongated_square_dipyramid_verts[9];
 #local P2 = Johnson_15_elongated_square_dipyramid_verts[6];
 #local P3 = Johnson_15_elongated_square_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_15_elongated_square_dipyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_15_elongated_square_dipyramid_obj }
#end
#end

#macro Johnson_15_elongated_square_dipyramid_faces2(OnPlane)
#local Johnson_15_elongated_square_dipyramid_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_15_elongated_square_dipyramid_verts[0],
  Johnson_15_elongated_square_dipyramid_verts[1],
  Johnson_15_elongated_square_dipyramid_verts[2],
  Johnson_15_elongated_square_dipyramid_verts[3],
  Johnson_15_elongated_square_dipyramid_verts[4],
  Johnson_15_elongated_square_dipyramid_verts[5],
  Johnson_15_elongated_square_dipyramid_verts[6],
  Johnson_15_elongated_square_dipyramid_verts[7],
  Johnson_15_elongated_square_dipyramid_verts[8],
  Johnson_15_elongated_square_dipyramid_verts[9]
 }
 face_indices {
  16,
  <8, 9, 7>,
  <6, 5, 2>,
  <3, 8, 7>,
  <5, 0, 2>,
  <4, 3, 7>,
  <0, 1, 2>,
  <9, 4, 7>,
  <1, 6, 2>,
  <9, 8, 5>,
  <9, 5, 6>,
  <8, 3, 0>,
  <8, 0, 5>,
  <3, 4, 1>,
  <3, 1, 0>,
  <4, 9, 6>,
  <4, 6, 1>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_15_elongated_square_dipyramid_verts[4];
 #local P1 = Johnson_15_elongated_square_dipyramid_verts[9];
 #local P2 = Johnson_15_elongated_square_dipyramid_verts[6];
 #local P3 = Johnson_15_elongated_square_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_15_elongated_square_dipyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_15_elongated_square_dipyramid_obj }
#end
#end

#macro Johnson_15_elongated_square_dipyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_15_elongated_square_dipyramid_verts[0], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[1], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[2], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[3], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[4], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[5], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[6], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[7], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[8], RadVer }
  sphere { Johnson_15_elongated_square_dipyramid_verts[9], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_15_elongated_square_dipyramid_verts[8], Johnson_15_elongated_square_dipyramid_verts[9], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[9], Johnson_15_elongated_square_dipyramid_verts[7], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[7], Johnson_15_elongated_square_dipyramid_verts[8], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[6], Johnson_15_elongated_square_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[5], Johnson_15_elongated_square_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[2], Johnson_15_elongated_square_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[3], Johnson_15_elongated_square_dipyramid_verts[8], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[7], Johnson_15_elongated_square_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[5], Johnson_15_elongated_square_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[0], Johnson_15_elongated_square_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[4], Johnson_15_elongated_square_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[7], Johnson_15_elongated_square_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[0], Johnson_15_elongated_square_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[1], Johnson_15_elongated_square_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[9], Johnson_15_elongated_square_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[1], Johnson_15_elongated_square_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[8], Johnson_15_elongated_square_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[6], Johnson_15_elongated_square_dipyramid_verts[9], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[3], Johnson_15_elongated_square_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_15_elongated_square_dipyramid_verts[4], Johnson_15_elongated_square_dipyramid_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_15_elongated_square_dipyramid_verts[4];
 #local P1 = Johnson_15_elongated_square_dipyramid_verts[9];
 #local P2 = Johnson_15_elongated_square_dipyramid_verts[6];
 #local P3 = Johnson_15_elongated_square_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_16_elongated_pentagonal_dipyramid_verts = array[12]
{
<-0.931836, 0.219976, -0.264632>,
<-0.636706, 0.318353, 0.692816>,
<-0.613483, -0.735083, -0.264632>,
<-0.326545, 0.979634, 0.000000>,
<-0.318353, -0.636706, 0.692816>,
<-0.159176, 0.477529, -0.856368>,
<0.159176, -0.477529, -0.856368>,
<0.318353, 0.636706, 0.692816>,
<0.326545, -0.979634, 0.000000>,
<0.613482, 0.735082, -0.264632>,
<0.636706, -0.318353, 0.692816>,
<0.931835, -0.219977, -0.264632>,
}
#declare P0 = Johnson_16_elongated_pentagonal_dipyramid_verts[6];
#declare P1 = Johnson_16_elongated_pentagonal_dipyramid_verts[4];
#declare P2 = Johnson_16_elongated_pentagonal_dipyramid_verts[2];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 12)
 #declare Johnson_16_elongated_pentagonal_dipyramid_verts[Num] = vtransform(Johnson_16_elongated_pentagonal_dipyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_16_elongated_pentagonal_dipyramid_faces(Tex3, Tex4, OnPlane)
#local Johnson_16_elongated_pentagonal_dipyramid_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_16_elongated_pentagonal_dipyramid_verts[0],
  Johnson_16_elongated_pentagonal_dipyramid_verts[1],
  Johnson_16_elongated_pentagonal_dipyramid_verts[2],
  Johnson_16_elongated_pentagonal_dipyramid_verts[3],
  Johnson_16_elongated_pentagonal_dipyramid_verts[4],
  Johnson_16_elongated_pentagonal_dipyramid_verts[5],
  Johnson_16_elongated_pentagonal_dipyramid_verts[6],
  Johnson_16_elongated_pentagonal_dipyramid_verts[7],
  Johnson_16_elongated_pentagonal_dipyramid_verts[8],
  Johnson_16_elongated_pentagonal_dipyramid_verts[9],
  Johnson_16_elongated_pentagonal_dipyramid_verts[10],
  Johnson_16_elongated_pentagonal_dipyramid_verts[11]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  20,
  <11, 10, 8>, 0,
  <7, 9, 3>, 0,
  <6, 11, 8>, 0,
  <9, 5, 3>, 0,
  <2, 6, 8>, 0,
  <5, 0, 3>, 0,
  <4, 2, 8>, 0,
  <0, 1, 3>, 0,
  <10, 4, 8>, 0,
  <1, 7, 3>, 0,
  <10, 11, 9>, 1,
  <10, 9, 7>, 1,
  <11, 6, 5>, 1,
  <11, 5, 9>, 1,
  <6, 2, 0>, 1,
  <6, 0, 5>, 1,
  <2, 4, 1>, 1,
  <2, 1, 0>, 1,
  <4, 10, 7>, 1,
  <4, 7, 1>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_16_elongated_pentagonal_dipyramid_verts[7];
 #local P1 = Johnson_16_elongated_pentagonal_dipyramid_verts[11];
 #local P2 = Johnson_16_elongated_pentagonal_dipyramid_verts[9];
 #local P3 = Johnson_16_elongated_pentagonal_dipyramid_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_16_elongated_pentagonal_dipyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_16_elongated_pentagonal_dipyramid_obj }
#end
#end

#macro Johnson_16_elongated_pentagonal_dipyramid_faces2(OnPlane)
#local Johnson_16_elongated_pentagonal_dipyramid_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_16_elongated_pentagonal_dipyramid_verts[0],
  Johnson_16_elongated_pentagonal_dipyramid_verts[1],
  Johnson_16_elongated_pentagonal_dipyramid_verts[2],
  Johnson_16_elongated_pentagonal_dipyramid_verts[3],
  Johnson_16_elongated_pentagonal_dipyramid_verts[4],
  Johnson_16_elongated_pentagonal_dipyramid_verts[5],
  Johnson_16_elongated_pentagonal_dipyramid_verts[6],
  Johnson_16_elongated_pentagonal_dipyramid_verts[7],
  Johnson_16_elongated_pentagonal_dipyramid_verts[8],
  Johnson_16_elongated_pentagonal_dipyramid_verts[9],
  Johnson_16_elongated_pentagonal_dipyramid_verts[10],
  Johnson_16_elongated_pentagonal_dipyramid_verts[11]
 }
 face_indices {
  20,
  <11, 10, 8>,
  <7, 9, 3>,
  <6, 11, 8>,
  <9, 5, 3>,
  <2, 6, 8>,
  <5, 0, 3>,
  <4, 2, 8>,
  <0, 1, 3>,
  <10, 4, 8>,
  <1, 7, 3>,
  <10, 11, 9>,
  <10, 9, 7>,
  <11, 6, 5>,
  <11, 5, 9>,
  <6, 2, 0>,
  <6, 0, 5>,
  <2, 4, 1>,
  <2, 1, 0>,
  <4, 10, 7>,
  <4, 7, 1>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_16_elongated_pentagonal_dipyramid_verts[7];
 #local P1 = Johnson_16_elongated_pentagonal_dipyramid_verts[11];
 #local P2 = Johnson_16_elongated_pentagonal_dipyramid_verts[9];
 #local P3 = Johnson_16_elongated_pentagonal_dipyramid_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_16_elongated_pentagonal_dipyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_16_elongated_pentagonal_dipyramid_obj }
#end
#end

#macro Johnson_16_elongated_pentagonal_dipyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[0], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[1], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[2], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[3], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[4], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[5], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[6], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[7], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[8], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[9], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[10], RadVer }
  sphere { Johnson_16_elongated_pentagonal_dipyramid_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[11], Johnson_16_elongated_pentagonal_dipyramid_verts[10], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[10], Johnson_16_elongated_pentagonal_dipyramid_verts[8], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[8], Johnson_16_elongated_pentagonal_dipyramid_verts[11], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[7], Johnson_16_elongated_pentagonal_dipyramid_verts[9], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[9], Johnson_16_elongated_pentagonal_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[3], Johnson_16_elongated_pentagonal_dipyramid_verts[7], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[6], Johnson_16_elongated_pentagonal_dipyramid_verts[11], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[8], Johnson_16_elongated_pentagonal_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[9], Johnson_16_elongated_pentagonal_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[5], Johnson_16_elongated_pentagonal_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[2], Johnson_16_elongated_pentagonal_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[8], Johnson_16_elongated_pentagonal_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[5], Johnson_16_elongated_pentagonal_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[0], Johnson_16_elongated_pentagonal_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[4], Johnson_16_elongated_pentagonal_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[8], Johnson_16_elongated_pentagonal_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[0], Johnson_16_elongated_pentagonal_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[1], Johnson_16_elongated_pentagonal_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[10], Johnson_16_elongated_pentagonal_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[1], Johnson_16_elongated_pentagonal_dipyramid_verts[7], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[11], Johnson_16_elongated_pentagonal_dipyramid_verts[9], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[7], Johnson_16_elongated_pentagonal_dipyramid_verts[10], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[6], Johnson_16_elongated_pentagonal_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[2], Johnson_16_elongated_pentagonal_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_16_elongated_pentagonal_dipyramid_verts[4], Johnson_16_elongated_pentagonal_dipyramid_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_16_elongated_pentagonal_dipyramid_verts[7];
 #local P1 = Johnson_16_elongated_pentagonal_dipyramid_verts[11];
 #local P2 = Johnson_16_elongated_pentagonal_dipyramid_verts[9];
 #local P3 = Johnson_16_elongated_pentagonal_dipyramid_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_17_gyroelongated_square_dipyramid_verts = array[10]
{
<-0.777261, 0.485581, 0.103065>,
<-0.675344, -0.565479, -0.273294>,
<-0.379795, -0.315718, 0.778861>,
<-0.221894, 0.282623, -0.849372>,
<-0.034619, 1.231562, -0.282624>,
<0.034619, -1.231562, 0.282624>,
<0.196076, 0.635838, 0.638599>,
<0.405612, -0.602744, -0.568088>,
<0.701162, -0.352983, 0.484067>,
<0.751443, 0.432880, -0.313837>,
}
#declare P0 = Johnson_17_gyroelongated_square_dipyramid_verts[0];
#declare P1 = Johnson_17_gyroelongated_square_dipyramid_verts[3];
#declare P2 = Johnson_17_gyroelongated_square_dipyramid_verts[9];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 10)
 #declare Johnson_17_gyroelongated_square_dipyramid_verts[Num] = vtransform(Johnson_17_gyroelongated_square_dipyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_17_gyroelongated_square_dipyramid_faces(Tex3, OnPlane)
#local Johnson_17_gyroelongated_square_dipyramid_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_17_gyroelongated_square_dipyramid_verts[0],
  Johnson_17_gyroelongated_square_dipyramid_verts[1],
  Johnson_17_gyroelongated_square_dipyramid_verts[2],
  Johnson_17_gyroelongated_square_dipyramid_verts[3],
  Johnson_17_gyroelongated_square_dipyramid_verts[4],
  Johnson_17_gyroelongated_square_dipyramid_verts[5],
  Johnson_17_gyroelongated_square_dipyramid_verts[6],
  Johnson_17_gyroelongated_square_dipyramid_verts[7],
  Johnson_17_gyroelongated_square_dipyramid_verts[8],
  Johnson_17_gyroelongated_square_dipyramid_verts[9]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  16,
  <6, 8, 9>, 0,
  <9, 8, 7>, 0,
  <9, 7, 3>, 0,
  <3, 7, 1>, 0,
  <3, 1, 0>, 0,
  <0, 1, 2>, 0,
  <0, 2, 6>, 0,
  <6, 2, 8>, 0,
  <6, 9, 4>, 0,
  <9, 3, 4>, 0,
  <3, 0, 4>, 0,
  <0, 6, 4>, 0,
  <7, 8, 5>, 0,
  <1, 7, 5>, 0,
  <2, 1, 5>, 0,
  <8, 2, 5>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_17_gyroelongated_square_dipyramid_verts[0];
 #local P1 = Johnson_17_gyroelongated_square_dipyramid_verts[3];
 #local P2 = Johnson_17_gyroelongated_square_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_17_gyroelongated_square_dipyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_17_gyroelongated_square_dipyramid_obj }
#end
#end

#macro Johnson_17_gyroelongated_square_dipyramid_faces2(OnPlane)
#local Johnson_17_gyroelongated_square_dipyramid_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_17_gyroelongated_square_dipyramid_verts[0],
  Johnson_17_gyroelongated_square_dipyramid_verts[1],
  Johnson_17_gyroelongated_square_dipyramid_verts[2],
  Johnson_17_gyroelongated_square_dipyramid_verts[3],
  Johnson_17_gyroelongated_square_dipyramid_verts[4],
  Johnson_17_gyroelongated_square_dipyramid_verts[5],
  Johnson_17_gyroelongated_square_dipyramid_verts[6],
  Johnson_17_gyroelongated_square_dipyramid_verts[7],
  Johnson_17_gyroelongated_square_dipyramid_verts[8],
  Johnson_17_gyroelongated_square_dipyramid_verts[9]
 }
 face_indices {
  16,
  <6, 8, 9>,
  <9, 8, 7>,
  <9, 7, 3>,
  <3, 7, 1>,
  <3, 1, 0>,
  <0, 1, 2>,
  <0, 2, 6>,
  <6, 2, 8>,
  <6, 9, 4>,
  <9, 3, 4>,
  <3, 0, 4>,
  <0, 6, 4>,
  <7, 8, 5>,
  <1, 7, 5>,
  <2, 1, 5>,
  <8, 2, 5>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_17_gyroelongated_square_dipyramid_verts[0];
 #local P1 = Johnson_17_gyroelongated_square_dipyramid_verts[3];
 #local P2 = Johnson_17_gyroelongated_square_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_17_gyroelongated_square_dipyramid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_17_gyroelongated_square_dipyramid_obj }
#end
#end

#macro Johnson_17_gyroelongated_square_dipyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[0], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[1], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[2], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[3], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[4], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[5], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[6], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[7], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[8], RadVer }
  sphere { Johnson_17_gyroelongated_square_dipyramid_verts[9], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[6], Johnson_17_gyroelongated_square_dipyramid_verts[8], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[8], Johnson_17_gyroelongated_square_dipyramid_verts[9], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[9], Johnson_17_gyroelongated_square_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[8], Johnson_17_gyroelongated_square_dipyramid_verts[7], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[7], Johnson_17_gyroelongated_square_dipyramid_verts[9], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[7], Johnson_17_gyroelongated_square_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[3], Johnson_17_gyroelongated_square_dipyramid_verts[9], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[7], Johnson_17_gyroelongated_square_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[1], Johnson_17_gyroelongated_square_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[1], Johnson_17_gyroelongated_square_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[0], Johnson_17_gyroelongated_square_dipyramid_verts[3], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[1], Johnson_17_gyroelongated_square_dipyramid_verts[2], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[2], Johnson_17_gyroelongated_square_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[2], Johnson_17_gyroelongated_square_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[6], Johnson_17_gyroelongated_square_dipyramid_verts[0], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[2], Johnson_17_gyroelongated_square_dipyramid_verts[8], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[9], Johnson_17_gyroelongated_square_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[4], Johnson_17_gyroelongated_square_dipyramid_verts[6], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[3], Johnson_17_gyroelongated_square_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[0], Johnson_17_gyroelongated_square_dipyramid_verts[4], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[8], Johnson_17_gyroelongated_square_dipyramid_verts[5], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[5], Johnson_17_gyroelongated_square_dipyramid_verts[7], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[5], Johnson_17_gyroelongated_square_dipyramid_verts[1], RadEdg }
  cylinder { Johnson_17_gyroelongated_square_dipyramid_verts[5], Johnson_17_gyroelongated_square_dipyramid_verts[2], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_17_gyroelongated_square_dipyramid_verts[0];
 #local P1 = Johnson_17_gyroelongated_square_dipyramid_verts[3];
 #local P2 = Johnson_17_gyroelongated_square_dipyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
