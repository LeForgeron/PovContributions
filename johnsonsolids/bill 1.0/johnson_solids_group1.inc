/* -------------------
johnson_solids_group1.inc

Prismatoids and rotundae

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Johnson_01_square_pyramid (5 vertices)
  Johnson_02_pentagonal_pyramid (6 vertices)
  Johnson_03_triangular_cupola (9 vertices)
  Johnson_04_square_cupola (12 vertices)
  Johnson_05_pentagonal_cupola (15 vertices)
  Johnson_06_pentagonal_rotunda (20 vertices)

-------------------- */

#include "transforms.inc"

#declare Johnson_01_square_pyramid_verts = array[5]
{
<-0.729665, 0.670121, 0.319155>,
<-0.655235, -0.292130, -0.754096>,
<-0.093922, -0.607123, 0.537818>,
<0.702196, 0.595691, 0.485187>,
<0.776626, -0.366560, -0.588064>,
}
#declare P0 = Johnson_01_square_pyramid_verts[4];
#declare P1 = Johnson_01_square_pyramid_verts[1];
#declare P2 = Johnson_01_square_pyramid_verts[0];
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
 #declare Johnson_01_square_pyramid_verts[Num] = vtransform(Johnson_01_square_pyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_01_square_pyramid_faces(Tex3, Tex4, OnPlane)
#local Johnson_01_square_pyramid_obj = mesh2 {
 vertex_vectors {
  5,
  Johnson_01_square_pyramid_verts[0],
  Johnson_01_square_pyramid_verts[1],
  Johnson_01_square_pyramid_verts[2],
  Johnson_01_square_pyramid_verts[3],
  Johnson_01_square_pyramid_verts[4]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  6,
  <1, 4, 2>, 0,
  <0, 1, 2>, 0,
  <3, 0, 2>, 0,
  <4, 3, 2>, 0,
  <4, 1, 0>, 1,
  <4, 0, 3>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_01_square_pyramid_verts[4];
 #local P1 = Johnson_01_square_pyramid_verts[1];
 #local P2 = Johnson_01_square_pyramid_verts[0];
 #local P3 = Johnson_01_square_pyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_01_square_pyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_01_square_pyramid_obj }
#end
#end

#macro Johnson_01_square_pyramid_faces2(OnPlane)
#local Johnson_01_square_pyramid_obj = mesh2 {
 vertex_vectors {
  5,
  Johnson_01_square_pyramid_verts[0],
  Johnson_01_square_pyramid_verts[1],
  Johnson_01_square_pyramid_verts[2],
  Johnson_01_square_pyramid_verts[3],
  Johnson_01_square_pyramid_verts[4]
 }
 face_indices {
  6,
  <1, 4, 2>,
  <0, 1, 2>,
  <3, 0, 2>,
  <4, 3, 2>,
  <4, 1, 0>,
  <4, 0, 3>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_01_square_pyramid_verts[4];
 #local P1 = Johnson_01_square_pyramid_verts[1];
 #local P2 = Johnson_01_square_pyramid_verts[0];
 #local P3 = Johnson_01_square_pyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_01_square_pyramid_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_01_square_pyramid_obj }
#end
#end

#macro Johnson_01_square_pyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_01_square_pyramid_verts[0], RadVer }
  sphere { Johnson_01_square_pyramid_verts[1], RadVer }
  sphere { Johnson_01_square_pyramid_verts[2], RadVer }
  sphere { Johnson_01_square_pyramid_verts[3], RadVer }
  sphere { Johnson_01_square_pyramid_verts[4], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_01_square_pyramid_verts[1], Johnson_01_square_pyramid_verts[4], RadEdg }
  cylinder { Johnson_01_square_pyramid_verts[4], Johnson_01_square_pyramid_verts[2], RadEdg }
  cylinder { Johnson_01_square_pyramid_verts[2], Johnson_01_square_pyramid_verts[1], RadEdg }
  cylinder { Johnson_01_square_pyramid_verts[0], Johnson_01_square_pyramid_verts[1], RadEdg }
  cylinder { Johnson_01_square_pyramid_verts[2], Johnson_01_square_pyramid_verts[0], RadEdg }
  cylinder { Johnson_01_square_pyramid_verts[3], Johnson_01_square_pyramid_verts[0], RadEdg }
  cylinder { Johnson_01_square_pyramid_verts[2], Johnson_01_square_pyramid_verts[3], RadEdg }
  cylinder { Johnson_01_square_pyramid_verts[4], Johnson_01_square_pyramid_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_01_square_pyramid_verts[4];
 #local P1 = Johnson_01_square_pyramid_verts[1];
 #local P2 = Johnson_01_square_pyramid_verts[0];
 #local P3 = Johnson_01_square_pyramid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_02_pentagonal_pyramid_verts = array[6]
{
<-0.868849, -0.100041, 0.612570>,
<-0.329458, 0.976099, 0.280780>,
<-0.266290, -0.013796, -0.477654>,
<-0.133920, -1.034115, 0.229829>,
<0.738834, 0.707117, -0.307018>,
<0.859683, -0.535264, -0.338508>,
}
#declare P0 = Johnson_02_pentagonal_pyramid_verts[0];
#declare P1 = Johnson_02_pentagonal_pyramid_verts[3];
#declare P2 = Johnson_02_pentagonal_pyramid_verts[5];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 6)
 #declare Johnson_02_pentagonal_pyramid_verts[Num] = vtransform(Johnson_02_pentagonal_pyramid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_02_pentagonal_pyramid_faces(Tex3, Tex5, OnPlane)
#local Johnson_02_pentagonal_pyramid_obj = mesh2 {
 vertex_vectors {
  6,
  Johnson_02_pentagonal_pyramid_verts[0],
  Johnson_02_pentagonal_pyramid_verts[1],
  Johnson_02_pentagonal_pyramid_verts[2],
  Johnson_02_pentagonal_pyramid_verts[3],
  Johnson_02_pentagonal_pyramid_verts[4],
  Johnson_02_pentagonal_pyramid_verts[5]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  8,
  <3, 0, 2>, 0,
  <5, 3, 2>, 0,
  <4, 5, 2>, 0,
  <1, 4, 2>, 0,
  <0, 1, 2>, 0,
  <0, 3, 5>, 1,
  <0, 5, 4>, 1,
  <0, 4, 1>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_02_pentagonal_pyramid_verts[0];
 #local P1 = Johnson_02_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_02_pentagonal_pyramid_verts[5];
 #local P3 = Johnson_02_pentagonal_pyramid_verts[4];
 #local P4 = Johnson_02_pentagonal_pyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_02_pentagonal_pyramid_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_02_pentagonal_pyramid_obj }
#end
#end

#macro Johnson_02_pentagonal_pyramid_faces2(OnPlane)
#local Johnson_02_pentagonal_pyramid_obj = mesh2 {
 vertex_vectors {
  6,
  Johnson_02_pentagonal_pyramid_verts[0],
  Johnson_02_pentagonal_pyramid_verts[1],
  Johnson_02_pentagonal_pyramid_verts[2],
  Johnson_02_pentagonal_pyramid_verts[3],
  Johnson_02_pentagonal_pyramid_verts[4],
  Johnson_02_pentagonal_pyramid_verts[5]
 }
 face_indices {
  8,
  <3, 0, 2>,
  <5, 3, 2>,
  <4, 5, 2>,
  <1, 4, 2>,
  <0, 1, 2>,
  <0, 3, 5>,
  <0, 5, 4>,
  <0, 4, 1>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_02_pentagonal_pyramid_verts[0];
 #local P1 = Johnson_02_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_02_pentagonal_pyramid_verts[5];
 #local P3 = Johnson_02_pentagonal_pyramid_verts[4];
 #local P4 = Johnson_02_pentagonal_pyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_02_pentagonal_pyramid_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_02_pentagonal_pyramid_obj }
#end
#end

#macro Johnson_02_pentagonal_pyramid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_02_pentagonal_pyramid_verts[0], RadVer }
  sphere { Johnson_02_pentagonal_pyramid_verts[1], RadVer }
  sphere { Johnson_02_pentagonal_pyramid_verts[2], RadVer }
  sphere { Johnson_02_pentagonal_pyramid_verts[3], RadVer }
  sphere { Johnson_02_pentagonal_pyramid_verts[4], RadVer }
  sphere { Johnson_02_pentagonal_pyramid_verts[5], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_02_pentagonal_pyramid_verts[3], Johnson_02_pentagonal_pyramid_verts[0], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[0], Johnson_02_pentagonal_pyramid_verts[2], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[2], Johnson_02_pentagonal_pyramid_verts[3], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[5], Johnson_02_pentagonal_pyramid_verts[3], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[2], Johnson_02_pentagonal_pyramid_verts[5], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[4], Johnson_02_pentagonal_pyramid_verts[5], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[2], Johnson_02_pentagonal_pyramid_verts[4], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[1], Johnson_02_pentagonal_pyramid_verts[4], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[2], Johnson_02_pentagonal_pyramid_verts[1], RadEdg }
  cylinder { Johnson_02_pentagonal_pyramid_verts[0], Johnson_02_pentagonal_pyramid_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_02_pentagonal_pyramid_verts[0];
 #local P1 = Johnson_02_pentagonal_pyramid_verts[3];
 #local P2 = Johnson_02_pentagonal_pyramid_verts[5];
 #local P3 = Johnson_02_pentagonal_pyramid_verts[4];
 #local P4 = Johnson_02_pentagonal_pyramid_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_03_triangular_cupola_verts = array[9]
{
<-0.909743, 0.523083, 0.242386>,
<-0.747863, 0.227870, -0.740794>,
<-0.678803, -0.467344, 0.028562>,
<-0.114530, 0.564337, 0.910169>,
<0.116410, -0.426091, 0.696344>,
<0.209231, -0.026090, -1.056192>,
<0.278291, -0.721304, -0.286836>,
<0.842564, 0.310377, 0.594771>,
<1.004444, 0.015163, -0.388410>,
}
#declare P0 = Johnson_03_triangular_cupola_verts[0];
#declare P1 = Johnson_03_triangular_cupola_verts[3];
#declare P2 = Johnson_03_triangular_cupola_verts[7];
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
 #declare Johnson_03_triangular_cupola_verts[Num] = vtransform(Johnson_03_triangular_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_03_triangular_cupola_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_03_triangular_cupola_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_03_triangular_cupola_verts[0],
  Johnson_03_triangular_cupola_verts[1],
  Johnson_03_triangular_cupola_verts[2],
  Johnson_03_triangular_cupola_verts[3],
  Johnson_03_triangular_cupola_verts[4],
  Johnson_03_triangular_cupola_verts[5],
  Johnson_03_triangular_cupola_verts[6],
  Johnson_03_triangular_cupola_verts[7],
  Johnson_03_triangular_cupola_verts[8]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  14,
  <2, 6, 4>, 0,
  <6, 5, 8>, 0,
  <4, 7, 3>, 0,
  <2, 0, 1>, 0,
  <6, 2, 1>, 1,
  <6, 1, 5>, 1,
  <4, 6, 8>, 1,
  <4, 8, 7>, 1,
  <2, 4, 3>, 1,
  <2, 3, 0>, 1,
  <0, 3, 7>, 2,
  <0, 7, 8>, 2,
  <0, 8, 5>, 2,
  <0, 5, 1>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_03_triangular_cupola_verts[0];
 #local P1 = Johnson_03_triangular_cupola_verts[3];
 #local P2 = Johnson_03_triangular_cupola_verts[7];
 #local P3 = Johnson_03_triangular_cupola_verts[8];
 #local P4 = Johnson_03_triangular_cupola_verts[5];
 #local P5 = Johnson_03_triangular_cupola_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_03_triangular_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_03_triangular_cupola_obj }
#end
#end

#macro Johnson_03_triangular_cupola_faces2(OnPlane)
#local Johnson_03_triangular_cupola_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_03_triangular_cupola_verts[0],
  Johnson_03_triangular_cupola_verts[1],
  Johnson_03_triangular_cupola_verts[2],
  Johnson_03_triangular_cupola_verts[3],
  Johnson_03_triangular_cupola_verts[4],
  Johnson_03_triangular_cupola_verts[5],
  Johnson_03_triangular_cupola_verts[6],
  Johnson_03_triangular_cupola_verts[7],
  Johnson_03_triangular_cupola_verts[8]
 }
 face_indices {
  14,
  <2, 6, 4>,
  <6, 5, 8>,
  <4, 7, 3>,
  <2, 0, 1>,
  <6, 2, 1>,
  <6, 1, 5>,
  <4, 6, 8>,
  <4, 8, 7>,
  <2, 4, 3>,
  <2, 3, 0>,
  <0, 3, 7>,
  <0, 7, 8>,
  <0, 8, 5>,
  <0, 5, 1>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_03_triangular_cupola_verts[0];
 #local P1 = Johnson_03_triangular_cupola_verts[3];
 #local P2 = Johnson_03_triangular_cupola_verts[7];
 #local P3 = Johnson_03_triangular_cupola_verts[8];
 #local P4 = Johnson_03_triangular_cupola_verts[5];
 #local P5 = Johnson_03_triangular_cupola_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_03_triangular_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_03_triangular_cupola_obj }
#end
#end

#macro Johnson_03_triangular_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_03_triangular_cupola_verts[0], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[1], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[2], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[3], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[4], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[5], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[6], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[7], RadVer }
  sphere { Johnson_03_triangular_cupola_verts[8], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_03_triangular_cupola_verts[2], Johnson_03_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[6], Johnson_03_triangular_cupola_verts[4], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[4], Johnson_03_triangular_cupola_verts[2], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[6], Johnson_03_triangular_cupola_verts[5], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[5], Johnson_03_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[8], Johnson_03_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[4], Johnson_03_triangular_cupola_verts[7], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[7], Johnson_03_triangular_cupola_verts[3], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[3], Johnson_03_triangular_cupola_verts[4], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[2], Johnson_03_triangular_cupola_verts[0], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[0], Johnson_03_triangular_cupola_verts[1], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[1], Johnson_03_triangular_cupola_verts[2], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[1], Johnson_03_triangular_cupola_verts[5], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[8], Johnson_03_triangular_cupola_verts[7], RadEdg }
  cylinder { Johnson_03_triangular_cupola_verts[3], Johnson_03_triangular_cupola_verts[0], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_03_triangular_cupola_verts[0];
 #local P1 = Johnson_03_triangular_cupola_verts[3];
 #local P2 = Johnson_03_triangular_cupola_verts[7];
 #local P3 = Johnson_03_triangular_cupola_verts[8];
 #local P4 = Johnson_03_triangular_cupola_verts[5];
 #local P5 = Johnson_03_triangular_cupola_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_04_square_cupola_verts = array[12]
{
<-0.600135, 0.398265, -0.852158>,
<-0.585543, -0.441941, -0.840701>,
<-0.584691, 0.409990, -0.011971>,
<-0.570099, -0.430216, -0.000514>,
<-0.182660, 1.005432, -0.447988>,
<-0.147431, -1.023005, -0.420329>,
<0.020300, 0.428447, 0.571068>,
<0.034892, -0.411759, 0.582525>,
<0.422331, 1.023889, 0.135052>,
<0.457559, -1.004548, 0.162711>,
<0.860442, 0.442825, 0.555424>,
<0.875034, -0.397381, 0.566881>,
}
#declare P0 = Johnson_04_square_cupola_verts[4];
#declare P1 = Johnson_04_square_cupola_verts[8];
#declare P2 = Johnson_04_square_cupola_verts[10];
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
 #declare Johnson_04_square_cupola_verts[Num] = vtransform(Johnson_04_square_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_04_square_cupola_faces(Tex3, Tex4, Tex8, OnPlane)
#local Johnson_04_square_cupola_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_04_square_cupola_verts[0],
  Johnson_04_square_cupola_verts[1],
  Johnson_04_square_cupola_verts[2],
  Johnson_04_square_cupola_verts[3],
  Johnson_04_square_cupola_verts[4],
  Johnson_04_square_cupola_verts[5],
  Johnson_04_square_cupola_verts[6],
  Johnson_04_square_cupola_verts[7],
  Johnson_04_square_cupola_verts[8],
  Johnson_04_square_cupola_verts[9],
  Johnson_04_square_cupola_verts[10],
  Johnson_04_square_cupola_verts[11]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex8 }
 }
 face_indices {
  20,
  <3, 1, 5>, 0,
  <7, 9, 11>, 0,
  <6, 10, 8>, 0,
  <2, 4, 0>, 0,
  <2, 3, 7>, 1,
  <2, 7, 6>, 1,
  <3, 2, 0>, 1,
  <3, 0, 1>, 1,
  <7, 3, 5>, 1,
  <7, 5, 9>, 1,
  <6, 7, 11>, 1,
  <6, 11, 10>, 1,
  <2, 6, 8>, 1,
  <2, 8, 4>, 1,
  <4, 8, 10>, 2,
  <4, 10, 11>, 2,
  <4, 11, 9>, 2,
  <4, 9, 5>, 2,
  <4, 5, 1>, 2,
  <4, 1, 0>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_04_square_cupola_verts[4];
 #local P1 = Johnson_04_square_cupola_verts[8];
 #local P2 = Johnson_04_square_cupola_verts[10];
 #local P3 = Johnson_04_square_cupola_verts[11];
 #local P4 = Johnson_04_square_cupola_verts[9];
 #local P5 = Johnson_04_square_cupola_verts[5];
 #local P6 = Johnson_04_square_cupola_verts[1];
 #local P7 = Johnson_04_square_cupola_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_04_square_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_04_square_cupola_obj }
#end
#end

#macro Johnson_04_square_cupola_faces2(OnPlane)
#local Johnson_04_square_cupola_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_04_square_cupola_verts[0],
  Johnson_04_square_cupola_verts[1],
  Johnson_04_square_cupola_verts[2],
  Johnson_04_square_cupola_verts[3],
  Johnson_04_square_cupola_verts[4],
  Johnson_04_square_cupola_verts[5],
  Johnson_04_square_cupola_verts[6],
  Johnson_04_square_cupola_verts[7],
  Johnson_04_square_cupola_verts[8],
  Johnson_04_square_cupola_verts[9],
  Johnson_04_square_cupola_verts[10],
  Johnson_04_square_cupola_verts[11]
 }
 face_indices {
  20,
  <3, 1, 5>,
  <7, 9, 11>,
  <6, 10, 8>,
  <2, 4, 0>,
  <2, 3, 7>,
  <2, 7, 6>,
  <3, 2, 0>,
  <3, 0, 1>,
  <7, 3, 5>,
  <7, 5, 9>,
  <6, 7, 11>,
  <6, 11, 10>,
  <2, 6, 8>,
  <2, 8, 4>,
  <4, 8, 10>,
  <4, 10, 11>,
  <4, 11, 9>,
  <4, 9, 5>,
  <4, 5, 1>,
  <4, 1, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_04_square_cupola_verts[4];
 #local P1 = Johnson_04_square_cupola_verts[8];
 #local P2 = Johnson_04_square_cupola_verts[10];
 #local P3 = Johnson_04_square_cupola_verts[11];
 #local P4 = Johnson_04_square_cupola_verts[9];
 #local P5 = Johnson_04_square_cupola_verts[5];
 #local P6 = Johnson_04_square_cupola_verts[1];
 #local P7 = Johnson_04_square_cupola_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_04_square_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_04_square_cupola_obj }
#end
#end

#macro Johnson_04_square_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_04_square_cupola_verts[0], RadVer }
  sphere { Johnson_04_square_cupola_verts[1], RadVer }
  sphere { Johnson_04_square_cupola_verts[2], RadVer }
  sphere { Johnson_04_square_cupola_verts[3], RadVer }
  sphere { Johnson_04_square_cupola_verts[4], RadVer }
  sphere { Johnson_04_square_cupola_verts[5], RadVer }
  sphere { Johnson_04_square_cupola_verts[6], RadVer }
  sphere { Johnson_04_square_cupola_verts[7], RadVer }
  sphere { Johnson_04_square_cupola_verts[8], RadVer }
  sphere { Johnson_04_square_cupola_verts[9], RadVer }
  sphere { Johnson_04_square_cupola_verts[10], RadVer }
  sphere { Johnson_04_square_cupola_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_04_square_cupola_verts[3], Johnson_04_square_cupola_verts[1], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[1], Johnson_04_square_cupola_verts[5], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[5], Johnson_04_square_cupola_verts[3], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[7], Johnson_04_square_cupola_verts[9], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[9], Johnson_04_square_cupola_verts[11], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[11], Johnson_04_square_cupola_verts[7], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[6], Johnson_04_square_cupola_verts[10], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[10], Johnson_04_square_cupola_verts[8], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[8], Johnson_04_square_cupola_verts[6], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[2], Johnson_04_square_cupola_verts[4], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[4], Johnson_04_square_cupola_verts[0], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[0], Johnson_04_square_cupola_verts[2], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[2], Johnson_04_square_cupola_verts[3], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[3], Johnson_04_square_cupola_verts[7], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[7], Johnson_04_square_cupola_verts[6], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[6], Johnson_04_square_cupola_verts[2], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[0], Johnson_04_square_cupola_verts[1], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[5], Johnson_04_square_cupola_verts[9], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[11], Johnson_04_square_cupola_verts[10], RadEdg }
  cylinder { Johnson_04_square_cupola_verts[8], Johnson_04_square_cupola_verts[4], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_04_square_cupola_verts[4];
 #local P1 = Johnson_04_square_cupola_verts[8];
 #local P2 = Johnson_04_square_cupola_verts[10];
 #local P3 = Johnson_04_square_cupola_verts[11];
 #local P4 = Johnson_04_square_cupola_verts[9];
 #local P5 = Johnson_04_square_cupola_verts[5];
 #local P6 = Johnson_04_square_cupola_verts[1];
 #local P7 = Johnson_04_square_cupola_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_05_pentagonal_cupola_verts = array[15]
{
<-0.973114, 0.120196, -0.576150>,
<-0.844191, -0.563656, -0.512814>,
<-0.711039, 0.757830, -0.462020>,
<-0.594483, 0.244733, -0.002202>,
<-0.465560, -0.439119, 0.061133>,
<-0.373515, -1.032518, -0.296206>,
<-0.158070, 1.105692, -0.214020>,
<-0.041514, 0.592595, 0.245798>,
<0.167087, -0.513901, 0.348277>,
<0.259132, -1.107300, -0.009062>,
<0.429162, 0.123733, 0.462406>,
<0.474577, 1.030910, 0.073124>,
<0.812101, -0.759438, 0.238938>,
<0.945253, 0.562048, 0.289732>,
<1.074175, -0.121804, 0.353067>,
}
#declare P0 = Johnson_05_pentagonal_cupola_verts[2];
#declare P1 = Johnson_05_pentagonal_cupola_verts[6];
#declare P2 = Johnson_05_pentagonal_cupola_verts[11];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 15)
 #declare Johnson_05_pentagonal_cupola_verts[Num] = vtransform(Johnson_05_pentagonal_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_05_pentagonal_cupola_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_05_pentagonal_cupola_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_05_pentagonal_cupola_verts[0],
  Johnson_05_pentagonal_cupola_verts[1],
  Johnson_05_pentagonal_cupola_verts[2],
  Johnson_05_pentagonal_cupola_verts[3],
  Johnson_05_pentagonal_cupola_verts[4],
  Johnson_05_pentagonal_cupola_verts[5],
  Johnson_05_pentagonal_cupola_verts[6],
  Johnson_05_pentagonal_cupola_verts[7],
  Johnson_05_pentagonal_cupola_verts[8],
  Johnson_05_pentagonal_cupola_verts[9],
  Johnson_05_pentagonal_cupola_verts[10],
  Johnson_05_pentagonal_cupola_verts[11],
  Johnson_05_pentagonal_cupola_verts[12],
  Johnson_05_pentagonal_cupola_verts[13],
  Johnson_05_pentagonal_cupola_verts[14]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  26,
  <4, 1, 5>, 0,
  <8, 9, 12>, 0,
  <10, 14, 13>, 0,
  <7, 11, 6>, 0,
  <3, 2, 0>, 0,
  <4, 3, 0>, 1,
  <4, 0, 1>, 1,
  <8, 4, 5>, 1,
  <8, 5, 9>, 1,
  <10, 8, 12>, 1,
  <10, 12, 14>, 1,
  <7, 10, 13>, 1,
  <7, 13, 11>, 1,
  <3, 7, 6>, 1,
  <3, 6, 2>, 1,
  <3, 4, 8>, 2,
  <3, 8, 10>, 2,
  <3, 10, 7>, 2,
  <2, 6, 11>, 3,
  <2, 11, 13>, 3,
  <2, 13, 14>, 3,
  <2, 14, 12>, 3,
  <2, 12, 9>, 3,
  <2, 9, 5>, 3,
  <2, 5, 1>, 3,
  <2, 1, 0>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_05_pentagonal_cupola_verts[2];
 #local P1 = Johnson_05_pentagonal_cupola_verts[6];
 #local P2 = Johnson_05_pentagonal_cupola_verts[11];
 #local P3 = Johnson_05_pentagonal_cupola_verts[13];
 #local P4 = Johnson_05_pentagonal_cupola_verts[14];
 #local P5 = Johnson_05_pentagonal_cupola_verts[12];
 #local P6 = Johnson_05_pentagonal_cupola_verts[9];
 #local P7 = Johnson_05_pentagonal_cupola_verts[5];
 #local P8 = Johnson_05_pentagonal_cupola_verts[1];
 #local P9 = Johnson_05_pentagonal_cupola_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_05_pentagonal_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_05_pentagonal_cupola_obj }
#end
#end

#macro Johnson_05_pentagonal_cupola_faces2(OnPlane)
#local Johnson_05_pentagonal_cupola_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_05_pentagonal_cupola_verts[0],
  Johnson_05_pentagonal_cupola_verts[1],
  Johnson_05_pentagonal_cupola_verts[2],
  Johnson_05_pentagonal_cupola_verts[3],
  Johnson_05_pentagonal_cupola_verts[4],
  Johnson_05_pentagonal_cupola_verts[5],
  Johnson_05_pentagonal_cupola_verts[6],
  Johnson_05_pentagonal_cupola_verts[7],
  Johnson_05_pentagonal_cupola_verts[8],
  Johnson_05_pentagonal_cupola_verts[9],
  Johnson_05_pentagonal_cupola_verts[10],
  Johnson_05_pentagonal_cupola_verts[11],
  Johnson_05_pentagonal_cupola_verts[12],
  Johnson_05_pentagonal_cupola_verts[13],
  Johnson_05_pentagonal_cupola_verts[14]
 }
 face_indices {
  26,
  <4, 1, 5>,
  <8, 9, 12>,
  <10, 14, 13>,
  <7, 11, 6>,
  <3, 2, 0>,
  <4, 3, 0>,
  <4, 0, 1>,
  <8, 4, 5>,
  <8, 5, 9>,
  <10, 8, 12>,
  <10, 12, 14>,
  <7, 10, 13>,
  <7, 13, 11>,
  <3, 7, 6>,
  <3, 6, 2>,
  <3, 4, 8>,
  <3, 8, 10>,
  <3, 10, 7>,
  <2, 6, 11>,
  <2, 11, 13>,
  <2, 13, 14>,
  <2, 14, 12>,
  <2, 12, 9>,
  <2, 9, 5>,
  <2, 5, 1>,
  <2, 1, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_05_pentagonal_cupola_verts[2];
 #local P1 = Johnson_05_pentagonal_cupola_verts[6];
 #local P2 = Johnson_05_pentagonal_cupola_verts[11];
 #local P3 = Johnson_05_pentagonal_cupola_verts[13];
 #local P4 = Johnson_05_pentagonal_cupola_verts[14];
 #local P5 = Johnson_05_pentagonal_cupola_verts[12];
 #local P6 = Johnson_05_pentagonal_cupola_verts[9];
 #local P7 = Johnson_05_pentagonal_cupola_verts[5];
 #local P8 = Johnson_05_pentagonal_cupola_verts[1];
 #local P9 = Johnson_05_pentagonal_cupola_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_05_pentagonal_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_05_pentagonal_cupola_obj }
#end
#end

#macro Johnson_05_pentagonal_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_05_pentagonal_cupola_verts[0], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[1], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[2], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[3], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[4], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[5], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[6], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[7], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[8], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[9], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[10], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[11], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[12], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[13], RadVer }
  sphere { Johnson_05_pentagonal_cupola_verts[14], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_05_pentagonal_cupola_verts[4], Johnson_05_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[1], Johnson_05_pentagonal_cupola_verts[5], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[5], Johnson_05_pentagonal_cupola_verts[4], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[8], Johnson_05_pentagonal_cupola_verts[9], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[9], Johnson_05_pentagonal_cupola_verts[12], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[12], Johnson_05_pentagonal_cupola_verts[8], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[10], Johnson_05_pentagonal_cupola_verts[14], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[14], Johnson_05_pentagonal_cupola_verts[13], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[13], Johnson_05_pentagonal_cupola_verts[10], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[7], Johnson_05_pentagonal_cupola_verts[11], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[11], Johnson_05_pentagonal_cupola_verts[6], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[6], Johnson_05_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[3], Johnson_05_pentagonal_cupola_verts[2], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[2], Johnson_05_pentagonal_cupola_verts[0], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[0], Johnson_05_pentagonal_cupola_verts[3], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[4], Johnson_05_pentagonal_cupola_verts[3], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[0], Johnson_05_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[8], Johnson_05_pentagonal_cupola_verts[4], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[5], Johnson_05_pentagonal_cupola_verts[9], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[10], Johnson_05_pentagonal_cupola_verts[8], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[12], Johnson_05_pentagonal_cupola_verts[14], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[7], Johnson_05_pentagonal_cupola_verts[10], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[13], Johnson_05_pentagonal_cupola_verts[11], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[3], Johnson_05_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_05_pentagonal_cupola_verts[6], Johnson_05_pentagonal_cupola_verts[2], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_05_pentagonal_cupola_verts[2];
 #local P1 = Johnson_05_pentagonal_cupola_verts[6];
 #local P2 = Johnson_05_pentagonal_cupola_verts[11];
 #local P3 = Johnson_05_pentagonal_cupola_verts[13];
 #local P4 = Johnson_05_pentagonal_cupola_verts[14];
 #local P5 = Johnson_05_pentagonal_cupola_verts[12];
 #local P6 = Johnson_05_pentagonal_cupola_verts[9];
 #local P7 = Johnson_05_pentagonal_cupola_verts[5];
 #local P8 = Johnson_05_pentagonal_cupola_verts[1];
 #local P9 = Johnson_05_pentagonal_cupola_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_06_pentagonal_rotunda_verts = array[20]
{
<-0.905691, -0.396105, -0.539844>,
<-0.883472, -0.258791, 0.103519>,
<-0.719735, -0.859265, -0.110695>,
<-0.703659, 0.137080, -0.868724>,
<-0.667708, 0.359259, 0.172260>,
<-0.556577, 0.603920, -0.428619>,
<-0.481752, -0.103901, 0.601410>,
<-0.216820, -1.075487, 0.254804>,
<-0.190808, 0.536633, -0.971712>,
<-0.154857, 0.758811, 0.069272>,
<-0.069738, -0.608646, 0.694909>,
<0.146026, 0.009404, 0.763650>,
<0.348059, 0.542589, 0.434771>,
<0.410958, -0.962182, 0.417045>,
<0.436971, 0.649937, -0.809472>,
<0.459190, 0.787251, -0.166109>,
<0.760072, 0.037844, 0.528270>,
<0.923809, -0.562629, 0.314056>,
<0.939886, 0.433715, -0.443973>,
<1.125842, -0.029444, -0.014823>,
}
#declare P0 = Johnson_06_pentagonal_rotunda_verts[2];
#declare P1 = Johnson_06_pentagonal_rotunda_verts[0];
#declare P2 = Johnson_06_pentagonal_rotunda_verts[3];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 20)
 #declare Johnson_06_pentagonal_rotunda_verts[Num] = vtransform(Johnson_06_pentagonal_rotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_06_pentagonal_rotunda_faces(Tex3, Tex5, Tex10, OnPlane)
#local Johnson_06_pentagonal_rotunda_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_06_pentagonal_rotunda_verts[0],
  Johnson_06_pentagonal_rotunda_verts[1],
  Johnson_06_pentagonal_rotunda_verts[2],
  Johnson_06_pentagonal_rotunda_verts[3],
  Johnson_06_pentagonal_rotunda_verts[4],
  Johnson_06_pentagonal_rotunda_verts[5],
  Johnson_06_pentagonal_rotunda_verts[6],
  Johnson_06_pentagonal_rotunda_verts[7],
  Johnson_06_pentagonal_rotunda_verts[8],
  Johnson_06_pentagonal_rotunda_verts[9],
  Johnson_06_pentagonal_rotunda_verts[10],
  Johnson_06_pentagonal_rotunda_verts[11],
  Johnson_06_pentagonal_rotunda_verts[12],
  Johnson_06_pentagonal_rotunda_verts[13],
  Johnson_06_pentagonal_rotunda_verts[14],
  Johnson_06_pentagonal_rotunda_verts[15],
  Johnson_06_pentagonal_rotunda_verts[16],
  Johnson_06_pentagonal_rotunda_verts[17],
  Johnson_06_pentagonal_rotunda_verts[18],
  Johnson_06_pentagonal_rotunda_verts[19]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  36,
  <11, 16, 12>, 0,
  <16, 17, 19>, 0,
  <12, 15, 9>, 0,
  <15, 18, 14>, 0,
  <9, 5, 4>, 0,
  <5, 8, 3>, 0,
  <4, 1, 6>, 0,
  <1, 0, 2>, 0,
  <6, 10, 11>, 0,
  <10, 7, 13>, 0,
  <11, 12, 9>, 1,
  <11, 9, 4>, 1,
  <11, 4, 6>, 1,
  <11, 10, 13>, 1,
  <11, 13, 17>, 1,
  <11, 17, 16>, 1,
  <12, 16, 19>, 1,
  <12, 19, 18>, 1,
  <12, 18, 15>, 1,
  <9, 15, 14>, 1,
  <9, 14, 8>, 1,
  <9, 8, 5>, 1,
  <4, 5, 3>, 1,
  <4, 3, 0>, 1,
  <4, 0, 1>, 1,
  <6, 1, 2>, 1,
  <6, 2, 7>, 1,
  <6, 7, 10>, 1,
  <2, 0, 3>, 2,
  <2, 3, 8>, 2,
  <2, 8, 14>, 2,
  <2, 14, 18>, 2,
  <2, 18, 19>, 2,
  <2, 19, 17>, 2,
  <2, 17, 13>, 2,
  <2, 13, 7>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_06_pentagonal_rotunda_verts[2];
 #local P1 = Johnson_06_pentagonal_rotunda_verts[0];
 #local P2 = Johnson_06_pentagonal_rotunda_verts[3];
 #local P3 = Johnson_06_pentagonal_rotunda_verts[8];
 #local P4 = Johnson_06_pentagonal_rotunda_verts[14];
 #local P5 = Johnson_06_pentagonal_rotunda_verts[18];
 #local P6 = Johnson_06_pentagonal_rotunda_verts[19];
 #local P7 = Johnson_06_pentagonal_rotunda_verts[17];
 #local P8 = Johnson_06_pentagonal_rotunda_verts[13];
 #local P9 = Johnson_06_pentagonal_rotunda_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_06_pentagonal_rotunda_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_06_pentagonal_rotunda_obj }
#end
#end

#macro Johnson_06_pentagonal_rotunda_faces2(OnPlane)
#local Johnson_06_pentagonal_rotunda_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_06_pentagonal_rotunda_verts[0],
  Johnson_06_pentagonal_rotunda_verts[1],
  Johnson_06_pentagonal_rotunda_verts[2],
  Johnson_06_pentagonal_rotunda_verts[3],
  Johnson_06_pentagonal_rotunda_verts[4],
  Johnson_06_pentagonal_rotunda_verts[5],
  Johnson_06_pentagonal_rotunda_verts[6],
  Johnson_06_pentagonal_rotunda_verts[7],
  Johnson_06_pentagonal_rotunda_verts[8],
  Johnson_06_pentagonal_rotunda_verts[9],
  Johnson_06_pentagonal_rotunda_verts[10],
  Johnson_06_pentagonal_rotunda_verts[11],
  Johnson_06_pentagonal_rotunda_verts[12],
  Johnson_06_pentagonal_rotunda_verts[13],
  Johnson_06_pentagonal_rotunda_verts[14],
  Johnson_06_pentagonal_rotunda_verts[15],
  Johnson_06_pentagonal_rotunda_verts[16],
  Johnson_06_pentagonal_rotunda_verts[17],
  Johnson_06_pentagonal_rotunda_verts[18],
  Johnson_06_pentagonal_rotunda_verts[19]
 }
 face_indices {
  36,
  <11, 16, 12>,
  <16, 17, 19>,
  <12, 15, 9>,
  <15, 18, 14>,
  <9, 5, 4>,
  <5, 8, 3>,
  <4, 1, 6>,
  <1, 0, 2>,
  <6, 10, 11>,
  <10, 7, 13>,
  <11, 12, 9>,
  <11, 9, 4>,
  <11, 4, 6>,
  <11, 10, 13>,
  <11, 13, 17>,
  <11, 17, 16>,
  <12, 16, 19>,
  <12, 19, 18>,
  <12, 18, 15>,
  <9, 15, 14>,
  <9, 14, 8>,
  <9, 8, 5>,
  <4, 5, 3>,
  <4, 3, 0>,
  <4, 0, 1>,
  <6, 1, 2>,
  <6, 2, 7>,
  <6, 7, 10>,
  <2, 0, 3>,
  <2, 3, 8>,
  <2, 8, 14>,
  <2, 14, 18>,
  <2, 18, 19>,
  <2, 19, 17>,
  <2, 17, 13>,
  <2, 13, 7>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_06_pentagonal_rotunda_verts[2];
 #local P1 = Johnson_06_pentagonal_rotunda_verts[0];
 #local P2 = Johnson_06_pentagonal_rotunda_verts[3];
 #local P3 = Johnson_06_pentagonal_rotunda_verts[8];
 #local P4 = Johnson_06_pentagonal_rotunda_verts[14];
 #local P5 = Johnson_06_pentagonal_rotunda_verts[18];
 #local P6 = Johnson_06_pentagonal_rotunda_verts[19];
 #local P7 = Johnson_06_pentagonal_rotunda_verts[17];
 #local P8 = Johnson_06_pentagonal_rotunda_verts[13];
 #local P9 = Johnson_06_pentagonal_rotunda_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_06_pentagonal_rotunda_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_06_pentagonal_rotunda_obj }
#end
#end

#macro Johnson_06_pentagonal_rotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_06_pentagonal_rotunda_verts[0], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[1], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[2], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[3], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[4], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[5], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[6], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[7], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[8], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[9], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[10], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[11], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[12], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[13], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[14], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[15], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[16], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[17], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[18], RadVer }
  sphere { Johnson_06_pentagonal_rotunda_verts[19], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_06_pentagonal_rotunda_verts[11], Johnson_06_pentagonal_rotunda_verts[16], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[16], Johnson_06_pentagonal_rotunda_verts[12], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[12], Johnson_06_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[16], Johnson_06_pentagonal_rotunda_verts[17], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[17], Johnson_06_pentagonal_rotunda_verts[19], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[19], Johnson_06_pentagonal_rotunda_verts[16], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[12], Johnson_06_pentagonal_rotunda_verts[15], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[15], Johnson_06_pentagonal_rotunda_verts[9], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[9], Johnson_06_pentagonal_rotunda_verts[12], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[15], Johnson_06_pentagonal_rotunda_verts[18], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[18], Johnson_06_pentagonal_rotunda_verts[14], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[14], Johnson_06_pentagonal_rotunda_verts[15], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[9], Johnson_06_pentagonal_rotunda_verts[5], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[5], Johnson_06_pentagonal_rotunda_verts[4], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[4], Johnson_06_pentagonal_rotunda_verts[9], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[5], Johnson_06_pentagonal_rotunda_verts[8], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[8], Johnson_06_pentagonal_rotunda_verts[3], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[3], Johnson_06_pentagonal_rotunda_verts[5], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[4], Johnson_06_pentagonal_rotunda_verts[1], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[1], Johnson_06_pentagonal_rotunda_verts[6], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[6], Johnson_06_pentagonal_rotunda_verts[4], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[1], Johnson_06_pentagonal_rotunda_verts[0], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[0], Johnson_06_pentagonal_rotunda_verts[2], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[2], Johnson_06_pentagonal_rotunda_verts[1], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[6], Johnson_06_pentagonal_rotunda_verts[10], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[10], Johnson_06_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[11], Johnson_06_pentagonal_rotunda_verts[6], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[10], Johnson_06_pentagonal_rotunda_verts[7], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[7], Johnson_06_pentagonal_rotunda_verts[13], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[13], Johnson_06_pentagonal_rotunda_verts[10], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[13], Johnson_06_pentagonal_rotunda_verts[17], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[19], Johnson_06_pentagonal_rotunda_verts[18], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[14], Johnson_06_pentagonal_rotunda_verts[8], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[3], Johnson_06_pentagonal_rotunda_verts[0], RadEdg }
  cylinder { Johnson_06_pentagonal_rotunda_verts[2], Johnson_06_pentagonal_rotunda_verts[7], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_06_pentagonal_rotunda_verts[2];
 #local P1 = Johnson_06_pentagonal_rotunda_verts[0];
 #local P2 = Johnson_06_pentagonal_rotunda_verts[3];
 #local P3 = Johnson_06_pentagonal_rotunda_verts[8];
 #local P4 = Johnson_06_pentagonal_rotunda_verts[14];
 #local P5 = Johnson_06_pentagonal_rotunda_verts[18];
 #local P6 = Johnson_06_pentagonal_rotunda_verts[19];
 #local P7 = Johnson_06_pentagonal_rotunda_verts[17];
 #local P8 = Johnson_06_pentagonal_rotunda_verts[13];
 #local P9 = Johnson_06_pentagonal_rotunda_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
