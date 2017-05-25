/* -------------------
platonic_solids.inc

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Platonic_tetrahedron (4 vertices)
  Platonic_cube (8 vertices)
  Platonic_octahedron (6 vertices)
  Platonic_dodecahedron (20 vertices)
  Platonic_icosahedron (12 vertices)

-------------------- */

#include "transforms.inc"

#declare Platonic_tetrahedron_verts = array[4]
{
<0, 0, 1.732051>,
<1.632993, 0, -0.5773503>,
<-0.8164966, 1.414214, -0.5773503>,
<-0.8164966, -1.414214, -0.5773503>,
}
#local P0 = Platonic_tetrahedron_verts[1];
#local P1 = Platonic_tetrahedron_verts[3];
#local P2 = Platonic_tetrahedron_verts[2];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 4)
 #declare Platonic_tetrahedron_verts[Num] = vtransform(Platonic_tetrahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Platonic_tetrahedron_faces(Tex3, OnPlane)
#local Platonic_tetrahedron_obj = mesh2 {
 vertex_vectors {
  4,
  Platonic_tetrahedron_verts[0],
  Platonic_tetrahedron_verts[1],
  Platonic_tetrahedron_verts[2],
  Platonic_tetrahedron_verts[3]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  4,
  <0, 1, 2>, 0,
  <0, 2, 3>, 0,
  <0, 3, 1>, 0,
  <1, 3, 2>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_tetrahedron_verts[1];
 #local P1 = Platonic_tetrahedron_verts[3];
 #local P2 = Platonic_tetrahedron_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_tetrahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_tetrahedron_obj }
#end
#end

#macro Platonic_tetrahedron_faces2(OnPlane)
#local Platonic_tetrahedron_obj = mesh2 {
 vertex_vectors {
  4,
  Platonic_tetrahedron_verts[0],
  Platonic_tetrahedron_verts[1],
  Platonic_tetrahedron_verts[2],
  Platonic_tetrahedron_verts[3]
 }
 face_indices {
  4,
  <0, 1, 2>,
  <0, 2, 3>,
  <0, 3, 1>,
  <1, 3, 2>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_tetrahedron_verts[1];
 #local P1 = Platonic_tetrahedron_verts[3];
 #local P2 = Platonic_tetrahedron_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_tetrahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_tetrahedron_obj }
#end
#end

#macro Platonic_tetrahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Platonic_tetrahedron_verts[0], RadVer }
  sphere { Platonic_tetrahedron_verts[1], RadVer }
  sphere { Platonic_tetrahedron_verts[2], RadVer }
  sphere { Platonic_tetrahedron_verts[3], RadVer }
  texture { TexVer } }
 union {
  cylinder { Platonic_tetrahedron_verts[0], Platonic_tetrahedron_verts[1], RadEdg }
  cylinder { Platonic_tetrahedron_verts[1], Platonic_tetrahedron_verts[2], RadEdg }
  cylinder { Platonic_tetrahedron_verts[2], Platonic_tetrahedron_verts[0], RadEdg }
  cylinder { Platonic_tetrahedron_verts[2], Platonic_tetrahedron_verts[3], RadEdg }
  cylinder { Platonic_tetrahedron_verts[3], Platonic_tetrahedron_verts[0], RadEdg }
  cylinder { Platonic_tetrahedron_verts[3], Platonic_tetrahedron_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Platonic_tetrahedron_verts[1];
 #local P1 = Platonic_tetrahedron_verts[3];
 #local P2 = Platonic_tetrahedron_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Platonic_cube_verts = array[8]
{
<0, 0, 1.224745>,
<1.154701, 0, 0.4082483>,
<-0.5773503, 1., 0.4082483>,
<-0.5773503, -1., 0.4082483>,
<0.5773503, 1., -0.4082483>,
<0.5773503, -1., -0.4082483>,
<-1.154701, 0, -0.4082483>,
<0, 0, -1.224745>,
}
#local P0 = Platonic_cube_verts[3];
#local P1 = Platonic_cube_verts[6];
#local P2 = Platonic_cube_verts[7];
#local P3 = Platonic_cube_verts[5];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 8)
 #declare Platonic_cube_verts[Num] = vtransform(Platonic_cube_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Platonic_cube_faces(Tex4, OnPlane)
#local Platonic_cube_obj = mesh2 {
 vertex_vectors {
  8,
  Platonic_cube_verts[0],
  Platonic_cube_verts[1],
  Platonic_cube_verts[2],
  Platonic_cube_verts[3],
  Platonic_cube_verts[4],
  Platonic_cube_verts[5],
  Platonic_cube_verts[6],
  Platonic_cube_verts[7]
 }
 texture_list {
  1,
  texture { Tex4 }
 }
 face_indices {
  12,
  <0, 1, 4>, 0,
  <0, 4, 2>, 0,
  <0, 2, 6>, 0,
  <0, 6, 3>, 0,
  <0, 3, 5>, 0,
  <0, 5, 1>, 0,
  <1, 5, 7>, 0,
  <1, 7, 4>, 0,
  <2, 4, 7>, 0,
  <2, 7, 6>, 0,
  <3, 6, 7>, 0,
  <3, 7, 5>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_cube_verts[3];
 #local P1 = Platonic_cube_verts[6];
 #local P2 = Platonic_cube_verts[7];
 #local P3 = Platonic_cube_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_cube_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_cube_obj }
#end
#end

#macro Platonic_cube_faces2(OnPlane)
#local Platonic_cube_obj = mesh2 {
 vertex_vectors {
  8,
  Platonic_cube_verts[0],
  Platonic_cube_verts[1],
  Platonic_cube_verts[2],
  Platonic_cube_verts[3],
  Platonic_cube_verts[4],
  Platonic_cube_verts[5],
  Platonic_cube_verts[6],
  Platonic_cube_verts[7]
 }
 face_indices {
  12,
  <0, 1, 4>,
  <0, 4, 2>,
  <0, 2, 6>,
  <0, 6, 3>,
  <0, 3, 5>,
  <0, 5, 1>,
  <1, 5, 7>,
  <1, 7, 4>,
  <2, 4, 7>,
  <2, 7, 6>,
  <3, 6, 7>,
  <3, 7, 5>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_cube_verts[3];
 #local P1 = Platonic_cube_verts[6];
 #local P2 = Platonic_cube_verts[7];
 #local P3 = Platonic_cube_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_cube_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_cube_obj }
#end
#end

#macro Platonic_cube_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Platonic_cube_verts[0], RadVer }
  sphere { Platonic_cube_verts[1], RadVer }
  sphere { Platonic_cube_verts[2], RadVer }
  sphere { Platonic_cube_verts[3], RadVer }
  sphere { Platonic_cube_verts[4], RadVer }
  sphere { Platonic_cube_verts[5], RadVer }
  sphere { Platonic_cube_verts[6], RadVer }
  sphere { Platonic_cube_verts[7], RadVer }
  texture { TexVer } }
 union {
  cylinder { Platonic_cube_verts[0], Platonic_cube_verts[1], RadEdg }
  cylinder { Platonic_cube_verts[1], Platonic_cube_verts[4], RadEdg }
  cylinder { Platonic_cube_verts[4], Platonic_cube_verts[2], RadEdg }
  cylinder { Platonic_cube_verts[2], Platonic_cube_verts[0], RadEdg }
  cylinder { Platonic_cube_verts[2], Platonic_cube_verts[6], RadEdg }
  cylinder { Platonic_cube_verts[6], Platonic_cube_verts[3], RadEdg }
  cylinder { Platonic_cube_verts[3], Platonic_cube_verts[0], RadEdg }
  cylinder { Platonic_cube_verts[3], Platonic_cube_verts[5], RadEdg }
  cylinder { Platonic_cube_verts[5], Platonic_cube_verts[1], RadEdg }
  cylinder { Platonic_cube_verts[5], Platonic_cube_verts[7], RadEdg }
  cylinder { Platonic_cube_verts[7], Platonic_cube_verts[4], RadEdg }
  cylinder { Platonic_cube_verts[7], Platonic_cube_verts[6], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Platonic_cube_verts[3];
 #local P1 = Platonic_cube_verts[6];
 #local P2 = Platonic_cube_verts[7];
 #local P3 = Platonic_cube_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Platonic_octahedron_verts = array[6]
{
<0, 0, 1.414214>,
<1.414214, 0, 0>,
<0, 1.414214, 0>,
<-1.414214, 0, 0>,
<0, -1.414214, 0>,
<0, 0, -1.414214>,
}
#local P0 = Platonic_octahedron_verts[1];
#local P1 = Platonic_octahedron_verts[2];
#local P2 = Platonic_octahedron_verts[3];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 6)
 #declare Platonic_octahedron_verts[Num] = vtransform(Platonic_octahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Platonic_octahedron_faces(Tex3, OnPlane)
#local Platonic_octahedron_obj = mesh2 {
 vertex_vectors {
  6,
  Platonic_octahedron_verts[0],
  Platonic_octahedron_verts[1],
  Platonic_octahedron_verts[2],
  Platonic_octahedron_verts[3],
  Platonic_octahedron_verts[4],
  Platonic_octahedron_verts[5]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  8,
  <0, 1, 2>, 0,
  <0, 2, 3>, 0,
  <0, 3, 4>, 0,
  <0, 4, 1>, 0,
  <1, 4, 5>, 0,
  <1, 5, 2>, 0,
  <2, 5, 3>, 0,
  <3, 5, 4>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_octahedron_verts[3];
 #local P1 = Platonic_octahedron_verts[5];
 #local P2 = Platonic_octahedron_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_octahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_octahedron_obj }
#end
#end

#macro Platonic_octahedron_faces2(OnPlane)
#local Platonic_octahedron_obj = mesh2 {
 vertex_vectors {
  6,
  Platonic_octahedron_verts[0],
  Platonic_octahedron_verts[1],
  Platonic_octahedron_verts[2],
  Platonic_octahedron_verts[3],
  Platonic_octahedron_verts[4],
  Platonic_octahedron_verts[5]
 }
 face_indices {
  8,
  <0, 1, 2>,
  <0, 2, 3>,
  <0, 3, 4>,
  <0, 4, 1>,
  <1, 4, 5>,
  <1, 5, 2>,
  <2, 5, 3>,
  <3, 5, 4>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_octahedron_verts[3];
 #local P1 = Platonic_octahedron_verts[5];
 #local P2 = Platonic_octahedron_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_octahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_octahedron_obj }
#end
#end

#macro Platonic_octahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Platonic_octahedron_verts[0], RadVer }
  sphere { Platonic_octahedron_verts[1], RadVer }
  sphere { Platonic_octahedron_verts[2], RadVer }
  sphere { Platonic_octahedron_verts[3], RadVer }
  sphere { Platonic_octahedron_verts[4], RadVer }
  sphere { Platonic_octahedron_verts[5], RadVer }
  texture { TexVer } }
 union {
  cylinder { Platonic_octahedron_verts[0], Platonic_octahedron_verts[1], RadEdg }
  cylinder { Platonic_octahedron_verts[1], Platonic_octahedron_verts[2], RadEdg }
  cylinder { Platonic_octahedron_verts[2], Platonic_octahedron_verts[0], RadEdg }
  cylinder { Platonic_octahedron_verts[2], Platonic_octahedron_verts[3], RadEdg }
  cylinder { Platonic_octahedron_verts[3], Platonic_octahedron_verts[0], RadEdg }
  cylinder { Platonic_octahedron_verts[3], Platonic_octahedron_verts[4], RadEdg }
  cylinder { Platonic_octahedron_verts[4], Platonic_octahedron_verts[0], RadEdg }
  cylinder { Platonic_octahedron_verts[4], Platonic_octahedron_verts[1], RadEdg }
  cylinder { Platonic_octahedron_verts[4], Platonic_octahedron_verts[5], RadEdg }
  cylinder { Platonic_octahedron_verts[5], Platonic_octahedron_verts[1], RadEdg }
  cylinder { Platonic_octahedron_verts[5], Platonic_octahedron_verts[2], RadEdg }
  cylinder { Platonic_octahedron_verts[5], Platonic_octahedron_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Platonic_octahedron_verts[3];
 #local P1 = Platonic_octahedron_verts[5];
 #local P2 = Platonic_octahedron_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Platonic_dodecahedron_verts = array[20]
{
<0, 0, 1.070466>,
<0.7136442, 0, 0.7978784>,
<-0.3568221, 0.618034, 0.7978784>,
<-0.3568221, -0.618034, 0.7978784>,
<0.7978784, 0.618034, 0.3568221>,
<0.7978784, -0.618034, 0.3568221>,
<-0.9341724, 0.381966, 0.3568221>,
<0.1362939, 1., 0.3568221>,
<0.1362939, -1., 0.3568221>,
<-0.9341724, -0.381966, 0.3568221>,
<0.9341724, 0.381966, -0.3568221>,
<0.9341724, -0.381966, -0.3568221>,
<-0.7978784, 0.618034, -0.3568221>,
<-0.1362939, 1., -0.3568221>,
<-0.1362939, -1., -0.3568221>,
<-0.7978784, -0.618034, -0.3568221>,
<0.3568221, 0.618034, -0.7978784>,
<0.3568221, -0.618034, -0.7978784>,
<-0.7136442, 0, -0.7978784>,
<0, 0, -1.070466>,
}
#local P0 = Platonic_dodecahedron_verts[14];
#local P1 = Platonic_dodecahedron_verts[15];
#local P2 = Platonic_dodecahedron_verts[18];
#local P3 = Platonic_dodecahedron_verts[19];
#local P4 = Platonic_dodecahedron_verts[17];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 20)
 #declare Platonic_dodecahedron_verts[Num] = vtransform(Platonic_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Platonic_dodecahedron_faces(Tex5, OnPlane)
#local Platonic_dodecahedron_obj = mesh2 {
 vertex_vectors {
  20,
  Platonic_dodecahedron_verts[0],
  Platonic_dodecahedron_verts[1],
  Platonic_dodecahedron_verts[2],
  Platonic_dodecahedron_verts[3],
  Platonic_dodecahedron_verts[4],
  Platonic_dodecahedron_verts[5],
  Platonic_dodecahedron_verts[6],
  Platonic_dodecahedron_verts[7],
  Platonic_dodecahedron_verts[8],
  Platonic_dodecahedron_verts[9],
  Platonic_dodecahedron_verts[10],
  Platonic_dodecahedron_verts[11],
  Platonic_dodecahedron_verts[12],
  Platonic_dodecahedron_verts[13],
  Platonic_dodecahedron_verts[14],
  Platonic_dodecahedron_verts[15],
  Platonic_dodecahedron_verts[16],
  Platonic_dodecahedron_verts[17],
  Platonic_dodecahedron_verts[18],
  Platonic_dodecahedron_verts[19]
 }
 texture_list {
  1,
  texture { Tex5 }
 }
 face_indices {
  36,
  <0, 1, 4>, 0,
  <0, 4, 7>, 0,
  <0, 7, 2>, 0,
  <0, 2, 6>, 0,
  <0, 6, 9>, 0,
  <0, 9, 3>, 0,
  <0, 3, 8>, 0,
  <0, 8, 5>, 0,
  <0, 5, 1>, 0,
  <1, 5, 11>, 0,
  <1, 11, 10>, 0,
  <1, 10, 4>, 0,
  <2, 7, 13>, 0,
  <2, 13, 12>, 0,
  <2, 12, 6>, 0,
  <3, 9, 15>, 0,
  <3, 15, 14>, 0,
  <3, 14, 8>, 0,
  <4, 10, 16>, 0,
  <4, 16, 13>, 0,
  <4, 13, 7>, 0,
  <5, 8, 14>, 0,
  <5, 14, 17>, 0,
  <5, 17, 11>, 0,
  <6, 12, 18>, 0,
  <6, 18, 15>, 0,
  <6, 15, 9>, 0,
  <10, 11, 17>, 0,
  <10, 17, 19>, 0,
  <10, 19, 16>, 0,
  <12, 13, 16>, 0,
  <12, 16, 19>, 0,
  <12, 19, 18>, 0,
  <14, 15, 18>, 0,
  <14, 18, 19>, 0,
  <14, 19, 17>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_dodecahedron_verts[14];
 #local P1 = Platonic_dodecahedron_verts[15];
 #local P2 = Platonic_dodecahedron_verts[18];
 #local P3 = Platonic_dodecahedron_verts[19];
 #local P4 = Platonic_dodecahedron_verts[17];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_dodecahedron_obj }
#end
#end

#macro Platonic_dodecahedron_faces2(OnPlane)
#local Platonic_dodecahedron_obj = mesh2 {
 vertex_vectors {
  20,
  Platonic_dodecahedron_verts[0],
  Platonic_dodecahedron_verts[1],
  Platonic_dodecahedron_verts[2],
  Platonic_dodecahedron_verts[3],
  Platonic_dodecahedron_verts[4],
  Platonic_dodecahedron_verts[5],
  Platonic_dodecahedron_verts[6],
  Platonic_dodecahedron_verts[7],
  Platonic_dodecahedron_verts[8],
  Platonic_dodecahedron_verts[9],
  Platonic_dodecahedron_verts[10],
  Platonic_dodecahedron_verts[11],
  Platonic_dodecahedron_verts[12],
  Platonic_dodecahedron_verts[13],
  Platonic_dodecahedron_verts[14],
  Platonic_dodecahedron_verts[15],
  Platonic_dodecahedron_verts[16],
  Platonic_dodecahedron_verts[17],
  Platonic_dodecahedron_verts[18],
  Platonic_dodecahedron_verts[19]
 }
 face_indices {
  36,
  <0, 1, 4>,
  <0, 4, 7>,
  <0, 7, 2>,
  <0, 2, 6>,
  <0, 6, 9>,
  <0, 9, 3>,
  <0, 3, 8>,
  <0, 8, 5>,
  <0, 5, 1>,
  <1, 5, 11>,
  <1, 11, 10>,
  <1, 10, 4>,
  <2, 7, 13>,
  <2, 13, 12>,
  <2, 12, 6>,
  <3, 9, 15>,
  <3, 15, 14>,
  <3, 14, 8>,
  <4, 10, 16>,
  <4, 16, 13>,
  <4, 13, 7>,
  <5, 8, 14>,
  <5, 14, 17>,
  <5, 17, 11>,
  <6, 12, 18>,
  <6, 18, 15>,
  <6, 15, 9>,
  <10, 11, 17>,
  <10, 17, 19>,
  <10, 19, 16>,
  <12, 13, 16>,
  <12, 16, 19>,
  <12, 19, 18>,
  <14, 15, 18>,
  <14, 18, 19>,
  <14, 19, 17>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_dodecahedron_verts[14];
 #local P1 = Platonic_dodecahedron_verts[15];
 #local P2 = Platonic_dodecahedron_verts[18];
 #local P3 = Platonic_dodecahedron_verts[19];
 #local P4 = Platonic_dodecahedron_verts[17];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_dodecahedron_obj }
#end
#end

#macro Platonic_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Platonic_dodecahedron_verts[0], RadVer }
  sphere { Platonic_dodecahedron_verts[1], RadVer }
  sphere { Platonic_dodecahedron_verts[2], RadVer }
  sphere { Platonic_dodecahedron_verts[3], RadVer }
  sphere { Platonic_dodecahedron_verts[4], RadVer }
  sphere { Platonic_dodecahedron_verts[5], RadVer }
  sphere { Platonic_dodecahedron_verts[6], RadVer }
  sphere { Platonic_dodecahedron_verts[7], RadVer }
  sphere { Platonic_dodecahedron_verts[8], RadVer }
  sphere { Platonic_dodecahedron_verts[9], RadVer }
  sphere { Platonic_dodecahedron_verts[10], RadVer }
  sphere { Platonic_dodecahedron_verts[11], RadVer }
  sphere { Platonic_dodecahedron_verts[12], RadVer }
  sphere { Platonic_dodecahedron_verts[13], RadVer }
  sphere { Platonic_dodecahedron_verts[14], RadVer }
  sphere { Platonic_dodecahedron_verts[15], RadVer }
  sphere { Platonic_dodecahedron_verts[16], RadVer }
  sphere { Platonic_dodecahedron_verts[17], RadVer }
  sphere { Platonic_dodecahedron_verts[18], RadVer }
  sphere { Platonic_dodecahedron_verts[19], RadVer }
  texture { TexVer } }
 union {
  cylinder { Platonic_dodecahedron_verts[0], Platonic_dodecahedron_verts[1], RadEdg }
  cylinder { Platonic_dodecahedron_verts[1], Platonic_dodecahedron_verts[4], RadEdg }
  cylinder { Platonic_dodecahedron_verts[4], Platonic_dodecahedron_verts[7], RadEdg }
  cylinder { Platonic_dodecahedron_verts[7], Platonic_dodecahedron_verts[2], RadEdg }
  cylinder { Platonic_dodecahedron_verts[2], Platonic_dodecahedron_verts[0], RadEdg }
  cylinder { Platonic_dodecahedron_verts[2], Platonic_dodecahedron_verts[6], RadEdg }
  cylinder { Platonic_dodecahedron_verts[6], Platonic_dodecahedron_verts[9], RadEdg }
  cylinder { Platonic_dodecahedron_verts[9], Platonic_dodecahedron_verts[3], RadEdg }
  cylinder { Platonic_dodecahedron_verts[3], Platonic_dodecahedron_verts[0], RadEdg }
  cylinder { Platonic_dodecahedron_verts[3], Platonic_dodecahedron_verts[8], RadEdg }
  cylinder { Platonic_dodecahedron_verts[8], Platonic_dodecahedron_verts[5], RadEdg }
  cylinder { Platonic_dodecahedron_verts[5], Platonic_dodecahedron_verts[1], RadEdg }
  cylinder { Platonic_dodecahedron_verts[5], Platonic_dodecahedron_verts[11], RadEdg }
  cylinder { Platonic_dodecahedron_verts[11], Platonic_dodecahedron_verts[10], RadEdg }
  cylinder { Platonic_dodecahedron_verts[10], Platonic_dodecahedron_verts[4], RadEdg }
  cylinder { Platonic_dodecahedron_verts[7], Platonic_dodecahedron_verts[13], RadEdg }
  cylinder { Platonic_dodecahedron_verts[13], Platonic_dodecahedron_verts[12], RadEdg }
  cylinder { Platonic_dodecahedron_verts[12], Platonic_dodecahedron_verts[6], RadEdg }
  cylinder { Platonic_dodecahedron_verts[9], Platonic_dodecahedron_verts[15], RadEdg }
  cylinder { Platonic_dodecahedron_verts[15], Platonic_dodecahedron_verts[14], RadEdg }
  cylinder { Platonic_dodecahedron_verts[14], Platonic_dodecahedron_verts[8], RadEdg }
  cylinder { Platonic_dodecahedron_verts[10], Platonic_dodecahedron_verts[16], RadEdg }
  cylinder { Platonic_dodecahedron_verts[16], Platonic_dodecahedron_verts[13], RadEdg }
  cylinder { Platonic_dodecahedron_verts[14], Platonic_dodecahedron_verts[17], RadEdg }
  cylinder { Platonic_dodecahedron_verts[17], Platonic_dodecahedron_verts[11], RadEdg }
  cylinder { Platonic_dodecahedron_verts[12], Platonic_dodecahedron_verts[18], RadEdg }
  cylinder { Platonic_dodecahedron_verts[18], Platonic_dodecahedron_verts[15], RadEdg }
  cylinder { Platonic_dodecahedron_verts[17], Platonic_dodecahedron_verts[19], RadEdg }
  cylinder { Platonic_dodecahedron_verts[19], Platonic_dodecahedron_verts[16], RadEdg }
  cylinder { Platonic_dodecahedron_verts[19], Platonic_dodecahedron_verts[18], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Platonic_dodecahedron_verts[14];
 #local P1 = Platonic_dodecahedron_verts[15];
 #local P2 = Platonic_dodecahedron_verts[18];
 #local P3 = Platonic_dodecahedron_verts[19];
 #local P4 = Platonic_dodecahedron_verts[17];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Platonic_icosahedron_verts = array[12]
{
<0, 0, 1.175571>,
<1.051462, 0, 0.5257311>,
<0.3249197, 1., 0.5257311>,
<-0.8506508, 0.618034, 0.5257311>,
<-0.8506508, -0.618034, 0.5257311>,
<0.3249197, -1., 0.5257311>,
<0.8506508, 0.618034, -0.5257311>,
<0.8506508, -0.618034, -0.5257311>,
<-0.3249197, 1., -0.5257311>,
<-1.051462, 0, -0.5257311>,
<-0.3249197, -1., -0.5257311>,
<0, 0, -1.175571>,
}
#local P0 = Platonic_icosahedron_verts[1];
#local P1 = Platonic_icosahedron_verts[2];
#local P2 = Platonic_icosahedron_verts[3];
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
 #declare Platonic_icosahedron_verts[Num] = vtransform(Platonic_icosahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Platonic_icosahedron_faces(Tex3, OnPlane)
#local Platonic_icosahedron_obj = mesh2 {
 vertex_vectors {
  12,
  Platonic_icosahedron_verts[0],
  Platonic_icosahedron_verts[1],
  Platonic_icosahedron_verts[2],
  Platonic_icosahedron_verts[3],
  Platonic_icosahedron_verts[4],
  Platonic_icosahedron_verts[5],
  Platonic_icosahedron_verts[6],
  Platonic_icosahedron_verts[7],
  Platonic_icosahedron_verts[8],
  Platonic_icosahedron_verts[9],
  Platonic_icosahedron_verts[10],
  Platonic_icosahedron_verts[11]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  20,
  <0, 1, 2>, 0,
  <0, 2, 3>, 0,
  <0, 3, 4>, 0,
  <0, 4, 5>, 0,
  <0, 5, 1>, 0,
  <1, 5, 7>, 0,
  <1, 7, 6>, 0,
  <1, 6, 2>, 0,
  <2, 6, 8>, 0,
  <2, 8, 3>, 0,
  <3, 8, 9>, 0,
  <3, 9, 4>, 0,
  <4, 9, 10>, 0,
  <4, 10, 5>, 0,
  <5, 10, 7>, 0,
  <6, 7, 11>, 0,
  <6, 11, 8>, 0,
  <7, 10, 11>, 0,
  <8, 11, 9>, 0,
  <9, 11, 10>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_icosahedron_verts[9];
 #local P1 = Platonic_icosahedron_verts[11];
 #local P2 = Platonic_icosahedron_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_icosahedron_obj }
#end
#end

#macro Platonic_icosahedron_faces2(OnPlane)
#local Platonic_icosahedron_obj = mesh2 {
 vertex_vectors {
  12,
  Platonic_icosahedron_verts[0],
  Platonic_icosahedron_verts[1],
  Platonic_icosahedron_verts[2],
  Platonic_icosahedron_verts[3],
  Platonic_icosahedron_verts[4],
  Platonic_icosahedron_verts[5],
  Platonic_icosahedron_verts[6],
  Platonic_icosahedron_verts[7],
  Platonic_icosahedron_verts[8],
  Platonic_icosahedron_verts[9],
  Platonic_icosahedron_verts[10],
  Platonic_icosahedron_verts[11]
 }
 face_indices {
  20,
  <0, 1, 2>,
  <0, 2, 3>,
  <0, 3, 4>,
  <0, 4, 5>,
  <0, 5, 1>,
  <1, 5, 7>,
  <1, 7, 6>,
  <1, 6, 2>,
  <2, 6, 8>,
  <2, 8, 3>,
  <3, 8, 9>,
  <3, 9, 4>,
  <4, 9, 10>,
  <4, 10, 5>,
  <5, 10, 7>,
  <6, 7, 11>,
  <6, 11, 8>,
  <7, 10, 11>,
  <8, 11, 9>,
  <9, 11, 10>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Platonic_icosahedron_verts[9];
 #local P1 = Platonic_icosahedron_verts[11];
 #local P2 = Platonic_icosahedron_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Platonic_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Platonic_icosahedron_obj }
#end
#end

#macro Platonic_icosahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Platonic_icosahedron_verts[0], RadVer }
  sphere { Platonic_icosahedron_verts[1], RadVer }
  sphere { Platonic_icosahedron_verts[2], RadVer }
  sphere { Platonic_icosahedron_verts[3], RadVer }
  sphere { Platonic_icosahedron_verts[4], RadVer }
  sphere { Platonic_icosahedron_verts[5], RadVer }
  sphere { Platonic_icosahedron_verts[6], RadVer }
  sphere { Platonic_icosahedron_verts[7], RadVer }
  sphere { Platonic_icosahedron_verts[8], RadVer }
  sphere { Platonic_icosahedron_verts[9], RadVer }
  sphere { Platonic_icosahedron_verts[10], RadVer }
  sphere { Platonic_icosahedron_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Platonic_icosahedron_verts[0], Platonic_icosahedron_verts[1], RadEdg }
  cylinder { Platonic_icosahedron_verts[1], Platonic_icosahedron_verts[2], RadEdg }
  cylinder { Platonic_icosahedron_verts[2], Platonic_icosahedron_verts[0], RadEdg }
  cylinder { Platonic_icosahedron_verts[2], Platonic_icosahedron_verts[3], RadEdg }
  cylinder { Platonic_icosahedron_verts[3], Platonic_icosahedron_verts[0], RadEdg }
  cylinder { Platonic_icosahedron_verts[3], Platonic_icosahedron_verts[4], RadEdg }
  cylinder { Platonic_icosahedron_verts[4], Platonic_icosahedron_verts[0], RadEdg }
  cylinder { Platonic_icosahedron_verts[4], Platonic_icosahedron_verts[5], RadEdg }
  cylinder { Platonic_icosahedron_verts[5], Platonic_icosahedron_verts[0], RadEdg }
  cylinder { Platonic_icosahedron_verts[5], Platonic_icosahedron_verts[1], RadEdg }
  cylinder { Platonic_icosahedron_verts[5], Platonic_icosahedron_verts[7], RadEdg }
  cylinder { Platonic_icosahedron_verts[7], Platonic_icosahedron_verts[1], RadEdg }
  cylinder { Platonic_icosahedron_verts[7], Platonic_icosahedron_verts[6], RadEdg }
  cylinder { Platonic_icosahedron_verts[6], Platonic_icosahedron_verts[1], RadEdg }
  cylinder { Platonic_icosahedron_verts[6], Platonic_icosahedron_verts[2], RadEdg }
  cylinder { Platonic_icosahedron_verts[6], Platonic_icosahedron_verts[8], RadEdg }
  cylinder { Platonic_icosahedron_verts[8], Platonic_icosahedron_verts[2], RadEdg }
  cylinder { Platonic_icosahedron_verts[8], Platonic_icosahedron_verts[3], RadEdg }
  cylinder { Platonic_icosahedron_verts[8], Platonic_icosahedron_verts[9], RadEdg }
  cylinder { Platonic_icosahedron_verts[9], Platonic_icosahedron_verts[3], RadEdg }
  cylinder { Platonic_icosahedron_verts[9], Platonic_icosahedron_verts[4], RadEdg }
  cylinder { Platonic_icosahedron_verts[9], Platonic_icosahedron_verts[10], RadEdg }
  cylinder { Platonic_icosahedron_verts[10], Platonic_icosahedron_verts[4], RadEdg }
  cylinder { Platonic_icosahedron_verts[10], Platonic_icosahedron_verts[5], RadEdg }
  cylinder { Platonic_icosahedron_verts[10], Platonic_icosahedron_verts[7], RadEdg }
  cylinder { Platonic_icosahedron_verts[7], Platonic_icosahedron_verts[11], RadEdg }
  cylinder { Platonic_icosahedron_verts[11], Platonic_icosahedron_verts[6], RadEdg }
  cylinder { Platonic_icosahedron_verts[11], Platonic_icosahedron_verts[8], RadEdg }
  cylinder { Platonic_icosahedron_verts[10], Platonic_icosahedron_verts[11], RadEdg }
  cylinder { Platonic_icosahedron_verts[11], Platonic_icosahedron_verts[9], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Platonic_icosahedron_verts[9];
 #local P1 = Platonic_icosahedron_verts[11];
 #local P2 = Platonic_icosahedron_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
