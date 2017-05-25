/* -------------------
catalan_solids.inc

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Catalan_triakis_tetrahedron (8 vertices)
  Catalan_rhombic_dodecahedron (14 vertices)
  Catalan_triakis_octahedron (14 vertices)
  Catalan_tetrakis_hexahedron (14 vertices)
  Catalan_trapezoidal_icositetrahedron (26 vertices)
  Catalan_disdyakis_dodecahedron (26 vertices)
  Catalan_pentagonal_icositetrahedron (38 vertices)
  Catalan_rhombic_triacontahedron (32 vertices)
  Catalan_triakis_icosahedron (32 vertices)
  Catalan_pentakis_dodecahedron (32 vertices)
  Catalan_trapezoidal_hexecontahedron (62 vertices)
  Catalan_disdyakis_triacontahedron (62 vertices)
  Catalan_pentagonal_hexecontahedron (92 vertices)

-------------------- */

#include "transforms.inc"

#declare Catalan_triakis_tetrahedron_verts = array[8]
{
<0.4264014, 1.414214, 0.904534>,
<-1.13707, -0.942809, 0.904534>,
<0.4264014, -0.2828427, 0.904534>,
<1.421338, -0.942809, -0.3015113>,
<-0.8528029, 0.5656854, 0.1809068>,
<0.6822423, 0.5656854, -0.5427204>,
<-0.7106691, 0.4714045, -1.507557>,
<-0.2558409, -0.8485281, -0.5427204>,
}
#local P0 = Catalan_triakis_tetrahedron_verts[0];
#local P1 = Catalan_triakis_tetrahedron_verts[3];
#local P2 = Catalan_triakis_tetrahedron_verts[6];
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
 #declare Catalan_triakis_tetrahedron_verts[Num] = vtransform(Catalan_triakis_tetrahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_triakis_tetrahedron_faces(Tex3, OnPlane)
#local Catalan_triakis_tetrahedron_obj = mesh2 {
 vertex_vectors {
  8,
  Catalan_triakis_tetrahedron_verts[0],
  Catalan_triakis_tetrahedron_verts[1],
  Catalan_triakis_tetrahedron_verts[2],
  Catalan_triakis_tetrahedron_verts[3],
  Catalan_triakis_tetrahedron_verts[4],
  Catalan_triakis_tetrahedron_verts[5],
  Catalan_triakis_tetrahedron_verts[6],
  Catalan_triakis_tetrahedron_verts[7]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  12,
  <2, 0, 1>, 0,
  <2, 3, 0>, 0,
  <0, 4, 1>, 0,
  <1, 3, 2>, 0,
  <0, 3, 5>, 0,
  <1, 4, 6>, 0,
  <4, 0, 6>, 0,
  <3, 1, 7>, 0,
  <3, 6, 5>, 0,
  <5, 6, 0>, 0,
  <6, 7, 1>, 0,
  <7, 6, 3>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_triakis_tetrahedron_verts[7];
 #local P1 = Catalan_triakis_tetrahedron_verts[6];
 #local P2 = Catalan_triakis_tetrahedron_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_triakis_tetrahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_triakis_tetrahedron_obj }
#end
#end

#macro Catalan_triakis_tetrahedron_faces2(OnPlane)
#local Catalan_triakis_tetrahedron_obj = mesh2 {
 vertex_vectors {
  8,
  Catalan_triakis_tetrahedron_verts[0],
  Catalan_triakis_tetrahedron_verts[1],
  Catalan_triakis_tetrahedron_verts[2],
  Catalan_triakis_tetrahedron_verts[3],
  Catalan_triakis_tetrahedron_verts[4],
  Catalan_triakis_tetrahedron_verts[5],
  Catalan_triakis_tetrahedron_verts[6],
  Catalan_triakis_tetrahedron_verts[7]
 }
 face_indices {
  12,
  <2, 0, 1>,
  <2, 3, 0>,
  <0, 4, 1>,
  <1, 3, 2>,
  <0, 3, 5>,
  <1, 4, 6>,
  <4, 0, 6>,
  <3, 1, 7>,
  <3, 6, 5>,
  <5, 6, 0>,
  <6, 7, 1>,
  <7, 6, 3>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_triakis_tetrahedron_verts[7];
 #local P1 = Catalan_triakis_tetrahedron_verts[6];
 #local P2 = Catalan_triakis_tetrahedron_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_triakis_tetrahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_triakis_tetrahedron_obj }
#end
#end

#macro Catalan_triakis_tetrahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_triakis_tetrahedron_verts[0], RadVer }
  sphere { Catalan_triakis_tetrahedron_verts[1], RadVer }
  sphere { Catalan_triakis_tetrahedron_verts[2], RadVer }
  sphere { Catalan_triakis_tetrahedron_verts[3], RadVer }
  sphere { Catalan_triakis_tetrahedron_verts[4], RadVer }
  sphere { Catalan_triakis_tetrahedron_verts[5], RadVer }
  sphere { Catalan_triakis_tetrahedron_verts[6], RadVer }
  sphere { Catalan_triakis_tetrahedron_verts[7], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_triakis_tetrahedron_verts[2], Catalan_triakis_tetrahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[0], Catalan_triakis_tetrahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[1], Catalan_triakis_tetrahedron_verts[2], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[2], Catalan_triakis_tetrahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[3], Catalan_triakis_tetrahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[0], Catalan_triakis_tetrahedron_verts[4], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[4], Catalan_triakis_tetrahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[1], Catalan_triakis_tetrahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[3], Catalan_triakis_tetrahedron_verts[5], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[5], Catalan_triakis_tetrahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[4], Catalan_triakis_tetrahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[6], Catalan_triakis_tetrahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[0], Catalan_triakis_tetrahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[1], Catalan_triakis_tetrahedron_verts[7], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[7], Catalan_triakis_tetrahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[3], Catalan_triakis_tetrahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[6], Catalan_triakis_tetrahedron_verts[5], RadEdg }
  cylinder { Catalan_triakis_tetrahedron_verts[6], Catalan_triakis_tetrahedron_verts[7], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_triakis_tetrahedron_verts[7];
 #local P1 = Catalan_triakis_tetrahedron_verts[6];
 #local P2 = Catalan_triakis_tetrahedron_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_rhombic_dodecahedron_verts = array[14]
{
<0.5, 0.3535534, 0.8660254>,
<-0.5, 0.7071068, 0.8660254>,
<-0.5, -0.3535534, 0.8660254>,
<0.5, -0.7071068, 0.8660254>,
<1., -0.3535534, 0>,
<1., 0.7071068, 0>,
<0, 1.06066, 0>,
<-1., 0.3535534, 0>,
<-1., -0.7071068, 0>,
<0, -1.06066, 0>,
<0.5, -0.7071068, -0.8660254>,
<0.5, 0.3535534, -0.8660254>,
<-0.5, 0.7071068, -0.8660254>,
<-0.5, -0.3535534, -0.8660254>,
}
#local P0 = Catalan_rhombic_dodecahedron_verts[1];
#local P1 = Catalan_rhombic_dodecahedron_verts[3];
#local P2 = Catalan_rhombic_dodecahedron_verts[0];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 14)
 #declare Catalan_rhombic_dodecahedron_verts[Num] = vtransform(Catalan_rhombic_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_rhombic_dodecahedron_faces(Tex4, OnPlane)
#local Catalan_rhombic_dodecahedron_obj = mesh2 {
 vertex_vectors {
  14,
  Catalan_rhombic_dodecahedron_verts[0],
  Catalan_rhombic_dodecahedron_verts[1],
  Catalan_rhombic_dodecahedron_verts[2],
  Catalan_rhombic_dodecahedron_verts[3],
  Catalan_rhombic_dodecahedron_verts[4],
  Catalan_rhombic_dodecahedron_verts[5],
  Catalan_rhombic_dodecahedron_verts[6],
  Catalan_rhombic_dodecahedron_verts[7],
  Catalan_rhombic_dodecahedron_verts[8],
  Catalan_rhombic_dodecahedron_verts[9],
  Catalan_rhombic_dodecahedron_verts[10],
  Catalan_rhombic_dodecahedron_verts[11],
  Catalan_rhombic_dodecahedron_verts[12],
  Catalan_rhombic_dodecahedron_verts[13]
 }
 texture_list {
  1,
  texture { Tex4 }
 }
 face_indices {
  24,
  <3, 0, 1>, 0,
  <3, 1, 2>, 0,
  <3, 4, 5>, 0,
  <3, 5, 0>, 0,
  <0, 5, 6>, 0,
  <0, 6, 1>, 0,
  <1, 7, 8>, 0,
  <1, 8, 2>, 0,
  <2, 8, 9>, 0,
  <2, 9, 3>, 0,
  <5, 4, 10>, 0,
  <5, 10, 11>, 0,
  <4, 3, 9>, 0,
  <4, 9, 10>, 0,
  <1, 6, 12>, 0,
  <1, 12, 7>, 0,
  <6, 5, 11>, 0,
  <6, 11, 12>, 0,
  <8, 7, 12>, 0,
  <8, 12, 13>, 0,
  <9, 8, 13>, 0,
  <9, 13, 10>, 0,
  <10, 13, 12>, 0,
  <10, 12, 11>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_rhombic_dodecahedron_verts[1];
 #local P1 = Catalan_rhombic_dodecahedron_verts[3];
 #local P2 = Catalan_rhombic_dodecahedron_verts[0];
 #local P3 = Catalan_rhombic_dodecahedron_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_rhombic_dodecahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_rhombic_dodecahedron_obj }
#end
#end

#macro Catalan_rhombic_dodecahedron_faces2(OnPlane)
#local Catalan_rhombic_dodecahedron_obj = mesh2 {
 vertex_vectors {
  14,
  Catalan_rhombic_dodecahedron_verts[0],
  Catalan_rhombic_dodecahedron_verts[1],
  Catalan_rhombic_dodecahedron_verts[2],
  Catalan_rhombic_dodecahedron_verts[3],
  Catalan_rhombic_dodecahedron_verts[4],
  Catalan_rhombic_dodecahedron_verts[5],
  Catalan_rhombic_dodecahedron_verts[6],
  Catalan_rhombic_dodecahedron_verts[7],
  Catalan_rhombic_dodecahedron_verts[8],
  Catalan_rhombic_dodecahedron_verts[9],
  Catalan_rhombic_dodecahedron_verts[10],
  Catalan_rhombic_dodecahedron_verts[11],
  Catalan_rhombic_dodecahedron_verts[12],
  Catalan_rhombic_dodecahedron_verts[13]
 }
 face_indices {
  24,
  <3, 0, 1>,
  <3, 1, 2>,
  <3, 4, 5>,
  <3, 5, 0>,
  <0, 5, 6>,
  <0, 6, 1>,
  <1, 7, 8>,
  <1, 8, 2>,
  <2, 8, 9>,
  <2, 9, 3>,
  <5, 4, 10>,
  <5, 10, 11>,
  <4, 3, 9>,
  <4, 9, 10>,
  <1, 6, 12>,
  <1, 12, 7>,
  <6, 5, 11>,
  <6, 11, 12>,
  <8, 7, 12>,
  <8, 12, 13>,
  <9, 8, 13>,
  <9, 13, 10>,
  <10, 13, 12>,
  <10, 12, 11>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_rhombic_dodecahedron_verts[1];
 #local P1 = Catalan_rhombic_dodecahedron_verts[3];
 #local P2 = Catalan_rhombic_dodecahedron_verts[0];
 #local P3 = Catalan_rhombic_dodecahedron_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_rhombic_dodecahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_rhombic_dodecahedron_obj }
#end
#end

#macro Catalan_rhombic_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_rhombic_dodecahedron_verts[0], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[1], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[2], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[3], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[4], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[5], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[6], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[7], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[8], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[9], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[10], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[11], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[12], RadVer }
  sphere { Catalan_rhombic_dodecahedron_verts[13], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_rhombic_dodecahedron_verts[3], Catalan_rhombic_dodecahedron_verts[0], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[0], Catalan_rhombic_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[1], Catalan_rhombic_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[2], Catalan_rhombic_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[3], Catalan_rhombic_dodecahedron_verts[4], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[4], Catalan_rhombic_dodecahedron_verts[5], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[5], Catalan_rhombic_dodecahedron_verts[0], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[5], Catalan_rhombic_dodecahedron_verts[6], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[6], Catalan_rhombic_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[1], Catalan_rhombic_dodecahedron_verts[7], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[7], Catalan_rhombic_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[8], Catalan_rhombic_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[8], Catalan_rhombic_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[9], Catalan_rhombic_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[4], Catalan_rhombic_dodecahedron_verts[10], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[10], Catalan_rhombic_dodecahedron_verts[11], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[11], Catalan_rhombic_dodecahedron_verts[5], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[9], Catalan_rhombic_dodecahedron_verts[10], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[6], Catalan_rhombic_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[12], Catalan_rhombic_dodecahedron_verts[7], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[11], Catalan_rhombic_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[12], Catalan_rhombic_dodecahedron_verts[13], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[13], Catalan_rhombic_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_rhombic_dodecahedron_verts[13], Catalan_rhombic_dodecahedron_verts[10], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_rhombic_dodecahedron_verts[1];
 #local P1 = Catalan_rhombic_dodecahedron_verts[3];
 #local P2 = Catalan_rhombic_dodecahedron_verts[0];
 #local P3 = Catalan_rhombic_dodecahedron_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_triakis_octahedron_verts = array[14]
{
<0.2810846, 1., 0.959683>,
<-0.7609261, -0.7071068, 0.959683>,
<0.2810846, -0.1715729, 0.959683>,
<1.15844, -0.7071068, 0.3975137>,
<-0.6785983, 0.4142136, 0.6303718>,
<0.9114565, 0.4142136, 0.1646556>,
<-1.15844, 0.7071068, -0.3975137>,
<0.0482265, -1., 0.1646556>,
<0.7609261, 0.7071068, -0.959683>,
<-0.9114565, -0.4142136, -0.1646556>,
<-0.0482265, 1., -0.1646556>,
<-0.2810846, -1., -0.959683>,
<0.6785983, -0.4142136, -0.6303718>,
<-0.2810846, 0.1715729, -0.959683>,
}
#local P0 = Catalan_triakis_octahedron_verts[3];
#local P1 = Catalan_triakis_octahedron_verts[8];
#local P2 = Catalan_triakis_octahedron_verts[6];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 14)
 #declare Catalan_triakis_octahedron_verts[Num] = vtransform(Catalan_triakis_octahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_triakis_octahedron_faces(Tex3, OnPlane)
#local Catalan_triakis_octahedron_obj = mesh2 {
 vertex_vectors {
  14,
  Catalan_triakis_octahedron_verts[0],
  Catalan_triakis_octahedron_verts[1],
  Catalan_triakis_octahedron_verts[2],
  Catalan_triakis_octahedron_verts[3],
  Catalan_triakis_octahedron_verts[4],
  Catalan_triakis_octahedron_verts[5],
  Catalan_triakis_octahedron_verts[6],
  Catalan_triakis_octahedron_verts[7],
  Catalan_triakis_octahedron_verts[8],
  Catalan_triakis_octahedron_verts[9],
  Catalan_triakis_octahedron_verts[10],
  Catalan_triakis_octahedron_verts[11],
  Catalan_triakis_octahedron_verts[12],
  Catalan_triakis_octahedron_verts[13]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  24,
  <2, 0, 1>, 0,
  <2, 3, 0>, 0,
  <0, 4, 1>, 0,
  <1, 3, 2>, 0,
  <0, 3, 5>, 0,
  <1, 4, 6>, 0,
  <4, 0, 6>, 0,
  <3, 1, 7>, 0,
  <3, 8, 5>, 0,
  <5, 8, 0>, 0,
  <6, 9, 1>, 0,
  <0, 10, 6>, 0,
  <1, 11, 7>, 0,
  <7, 11, 3>, 0,
  <8, 3, 12>, 0,
  <0, 8, 10>, 0,
  <1, 9, 11>, 0,
  <9, 6, 11>, 0,
  <6, 10, 8>, 0,
  <3, 11, 12>, 0,
  <12, 11, 8>, 0,
  <6, 13, 11>, 0,
  <8, 13, 6>, 0,
  <8, 11, 13>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_triakis_octahedron_verts[2];
 #local P1 = Catalan_triakis_octahedron_verts[0];
 #local P2 = Catalan_triakis_octahedron_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_triakis_octahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_triakis_octahedron_obj }
#end
#end

#macro Catalan_triakis_octahedron_faces2(OnPlane)
#local Catalan_triakis_octahedron_obj = mesh2 {
 vertex_vectors {
  14,
  Catalan_triakis_octahedron_verts[0],
  Catalan_triakis_octahedron_verts[1],
  Catalan_triakis_octahedron_verts[2],
  Catalan_triakis_octahedron_verts[3],
  Catalan_triakis_octahedron_verts[4],
  Catalan_triakis_octahedron_verts[5],
  Catalan_triakis_octahedron_verts[6],
  Catalan_triakis_octahedron_verts[7],
  Catalan_triakis_octahedron_verts[8],
  Catalan_triakis_octahedron_verts[9],
  Catalan_triakis_octahedron_verts[10],
  Catalan_triakis_octahedron_verts[11],
  Catalan_triakis_octahedron_verts[12],
  Catalan_triakis_octahedron_verts[13]
 }
 face_indices {
  24,
  <2, 0, 1>,
  <2, 3, 0>,
  <0, 4, 1>,
  <1, 3, 2>,
  <0, 3, 5>,
  <1, 4, 6>,
  <4, 0, 6>,
  <3, 1, 7>,
  <3, 8, 5>,
  <5, 8, 0>,
  <6, 9, 1>,
  <0, 10, 6>,
  <1, 11, 7>,
  <7, 11, 3>,
  <8, 3, 12>,
  <0, 8, 10>,
  <1, 9, 11>,
  <9, 6, 11>,
  <6, 10, 8>,
  <3, 11, 12>,
  <12, 11, 8>,
  <6, 13, 11>,
  <8, 13, 6>,
  <8, 11, 13>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_triakis_octahedron_verts[2];
 #local P1 = Catalan_triakis_octahedron_verts[0];
 #local P2 = Catalan_triakis_octahedron_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_triakis_octahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_triakis_octahedron_obj }
#end
#end

#macro Catalan_triakis_octahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_triakis_octahedron_verts[0], RadVer }
  sphere { Catalan_triakis_octahedron_verts[1], RadVer }
  sphere { Catalan_triakis_octahedron_verts[2], RadVer }
  sphere { Catalan_triakis_octahedron_verts[3], RadVer }
  sphere { Catalan_triakis_octahedron_verts[4], RadVer }
  sphere { Catalan_triakis_octahedron_verts[5], RadVer }
  sphere { Catalan_triakis_octahedron_verts[6], RadVer }
  sphere { Catalan_triakis_octahedron_verts[7], RadVer }
  sphere { Catalan_triakis_octahedron_verts[8], RadVer }
  sphere { Catalan_triakis_octahedron_verts[9], RadVer }
  sphere { Catalan_triakis_octahedron_verts[10], RadVer }
  sphere { Catalan_triakis_octahedron_verts[11], RadVer }
  sphere { Catalan_triakis_octahedron_verts[12], RadVer }
  sphere { Catalan_triakis_octahedron_verts[13], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_triakis_octahedron_verts[2], Catalan_triakis_octahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[0], Catalan_triakis_octahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[1], Catalan_triakis_octahedron_verts[2], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[2], Catalan_triakis_octahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[3], Catalan_triakis_octahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[0], Catalan_triakis_octahedron_verts[4], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[4], Catalan_triakis_octahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[1], Catalan_triakis_octahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[3], Catalan_triakis_octahedron_verts[5], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[5], Catalan_triakis_octahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[4], Catalan_triakis_octahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[6], Catalan_triakis_octahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[0], Catalan_triakis_octahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[1], Catalan_triakis_octahedron_verts[7], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[7], Catalan_triakis_octahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[3], Catalan_triakis_octahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[8], Catalan_triakis_octahedron_verts[5], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[8], Catalan_triakis_octahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[6], Catalan_triakis_octahedron_verts[9], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[9], Catalan_triakis_octahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[0], Catalan_triakis_octahedron_verts[10], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[10], Catalan_triakis_octahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[1], Catalan_triakis_octahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[11], Catalan_triakis_octahedron_verts[7], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[11], Catalan_triakis_octahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[3], Catalan_triakis_octahedron_verts[12], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[12], Catalan_triakis_octahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[8], Catalan_triakis_octahedron_verts[10], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[9], Catalan_triakis_octahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[6], Catalan_triakis_octahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[8], Catalan_triakis_octahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[11], Catalan_triakis_octahedron_verts[12], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[11], Catalan_triakis_octahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[6], Catalan_triakis_octahedron_verts[13], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[13], Catalan_triakis_octahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_octahedron_verts[8], Catalan_triakis_octahedron_verts[13], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_triakis_octahedron_verts[2];
 #local P1 = Catalan_triakis_octahedron_verts[0];
 #local P2 = Catalan_triakis_octahedron_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_tetrakis_hexahedron_verts = array[14]
{
<0.3162278, 0.7071068, 0.9486833>,
<-0.7378648, -0.2357023, 0.9486833>,
<0.3162278, -0.3535534, 0.9486833>,
<1.159502, -0.2357023, 0.3162278>,
<-0.6324555, 0.7071068, 0.4743416>,
<0.1054093, -1.178511, 0.3162278>,
<0.7905694, 0.7071068, 0>,
<-1.159502, 0.2357023, -0.3162278>,
<-0.1054093, 1.178511, -0.3162278>,
<-0.7905694, -0.7071068, 0>,
<0.7378648, 0.2357023, -0.9486833>,
<0.6324555, -0.7071068, -0.4743416>,
<-0.3162278, -0.7071068, -0.9486833>,
<-0.3162278, 0.3535534, -0.9486833>,
}
#local P0 = Catalan_tetrakis_hexahedron_verts[1];
#local P1 = Catalan_tetrakis_hexahedron_verts[0];
#local P2 = Catalan_tetrakis_hexahedron_verts[3];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 14)
 #declare Catalan_tetrakis_hexahedron_verts[Num] = vtransform(Catalan_tetrakis_hexahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_tetrakis_hexahedron_faces(Tex3, OnPlane)
#local Catalan_tetrakis_hexahedron_obj = mesh2 {
 vertex_vectors {
  14,
  Catalan_tetrakis_hexahedron_verts[0],
  Catalan_tetrakis_hexahedron_verts[1],
  Catalan_tetrakis_hexahedron_verts[2],
  Catalan_tetrakis_hexahedron_verts[3],
  Catalan_tetrakis_hexahedron_verts[4],
  Catalan_tetrakis_hexahedron_verts[5],
  Catalan_tetrakis_hexahedron_verts[6],
  Catalan_tetrakis_hexahedron_verts[7],
  Catalan_tetrakis_hexahedron_verts[8],
  Catalan_tetrakis_hexahedron_verts[9],
  Catalan_tetrakis_hexahedron_verts[10],
  Catalan_tetrakis_hexahedron_verts[11],
  Catalan_tetrakis_hexahedron_verts[12],
  Catalan_tetrakis_hexahedron_verts[13]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  24,
  <2, 0, 1>, 0,
  <2, 3, 0>, 0,
  <0, 4, 1>, 0,
  <1, 5, 2>, 0,
  <0, 3, 6>, 0,
  <3, 2, 5>, 0,
  <1, 4, 7>, 0,
  <4, 0, 8>, 0,
  <5, 1, 9>, 0,
  <3, 10, 6>, 0,
  <6, 8, 0>, 0,
  <5, 11, 3>, 0,
  <4, 8, 7>, 0,
  <7, 9, 1>, 0,
  <9, 12, 5>, 0,
  <6, 10, 8>, 0,
  <10, 3, 11>, 0,
  <11, 5, 12>, 0,
  <7, 8, 13>, 0,
  <9, 7, 12>, 0,
  <10, 13, 8>, 0,
  <11, 12, 10>, 0,
  <13, 12, 7>, 0,
  <13, 10, 12>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_tetrakis_hexahedron_verts[13];
 #local P1 = Catalan_tetrakis_hexahedron_verts[10];
 #local P2 = Catalan_tetrakis_hexahedron_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_tetrakis_hexahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_tetrakis_hexahedron_obj }
#end
#end

#macro Catalan_tetrakis_hexahedron_faces2(OnPlane)
#local Catalan_tetrakis_hexahedron_obj = mesh2 {
 vertex_vectors {
  14,
  Catalan_tetrakis_hexahedron_verts[0],
  Catalan_tetrakis_hexahedron_verts[1],
  Catalan_tetrakis_hexahedron_verts[2],
  Catalan_tetrakis_hexahedron_verts[3],
  Catalan_tetrakis_hexahedron_verts[4],
  Catalan_tetrakis_hexahedron_verts[5],
  Catalan_tetrakis_hexahedron_verts[6],
  Catalan_tetrakis_hexahedron_verts[7],
  Catalan_tetrakis_hexahedron_verts[8],
  Catalan_tetrakis_hexahedron_verts[9],
  Catalan_tetrakis_hexahedron_verts[10],
  Catalan_tetrakis_hexahedron_verts[11],
  Catalan_tetrakis_hexahedron_verts[12],
  Catalan_tetrakis_hexahedron_verts[13]
 }
 face_indices {
  24,
  <2, 0, 1>,
  <2, 3, 0>,
  <0, 4, 1>,
  <1, 5, 2>,
  <0, 3, 6>,
  <3, 2, 5>,
  <1, 4, 7>,
  <4, 0, 8>,
  <5, 1, 9>,
  <3, 10, 6>,
  <6, 8, 0>,
  <5, 11, 3>,
  <4, 8, 7>,
  <7, 9, 1>,
  <9, 12, 5>,
  <6, 10, 8>,
  <10, 3, 11>,
  <11, 5, 12>,
  <7, 8, 13>,
  <9, 7, 12>,
  <10, 13, 8>,
  <11, 12, 10>,
  <13, 12, 7>,
  <13, 10, 12>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_tetrakis_hexahedron_verts[13];
 #local P1 = Catalan_tetrakis_hexahedron_verts[10];
 #local P2 = Catalan_tetrakis_hexahedron_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_tetrakis_hexahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_tetrakis_hexahedron_obj }
#end
#end

#macro Catalan_tetrakis_hexahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_tetrakis_hexahedron_verts[0], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[1], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[2], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[3], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[4], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[5], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[6], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[7], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[8], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[9], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[10], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[11], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[12], RadVer }
  sphere { Catalan_tetrakis_hexahedron_verts[13], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_tetrakis_hexahedron_verts[2], Catalan_tetrakis_hexahedron_verts[0], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[0], Catalan_tetrakis_hexahedron_verts[1], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[1], Catalan_tetrakis_hexahedron_verts[2], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[2], Catalan_tetrakis_hexahedron_verts[3], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[3], Catalan_tetrakis_hexahedron_verts[0], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[0], Catalan_tetrakis_hexahedron_verts[4], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[4], Catalan_tetrakis_hexahedron_verts[1], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[1], Catalan_tetrakis_hexahedron_verts[5], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[5], Catalan_tetrakis_hexahedron_verts[2], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[3], Catalan_tetrakis_hexahedron_verts[6], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[6], Catalan_tetrakis_hexahedron_verts[0], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[5], Catalan_tetrakis_hexahedron_verts[3], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[4], Catalan_tetrakis_hexahedron_verts[7], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[7], Catalan_tetrakis_hexahedron_verts[1], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[0], Catalan_tetrakis_hexahedron_verts[8], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[8], Catalan_tetrakis_hexahedron_verts[4], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[1], Catalan_tetrakis_hexahedron_verts[9], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[9], Catalan_tetrakis_hexahedron_verts[5], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[3], Catalan_tetrakis_hexahedron_verts[10], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[10], Catalan_tetrakis_hexahedron_verts[6], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[6], Catalan_tetrakis_hexahedron_verts[8], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[5], Catalan_tetrakis_hexahedron_verts[11], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[11], Catalan_tetrakis_hexahedron_verts[3], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[8], Catalan_tetrakis_hexahedron_verts[7], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[7], Catalan_tetrakis_hexahedron_verts[9], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[9], Catalan_tetrakis_hexahedron_verts[12], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[12], Catalan_tetrakis_hexahedron_verts[5], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[10], Catalan_tetrakis_hexahedron_verts[8], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[11], Catalan_tetrakis_hexahedron_verts[10], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[12], Catalan_tetrakis_hexahedron_verts[11], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[8], Catalan_tetrakis_hexahedron_verts[13], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[13], Catalan_tetrakis_hexahedron_verts[7], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[7], Catalan_tetrakis_hexahedron_verts[12], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[10], Catalan_tetrakis_hexahedron_verts[13], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[12], Catalan_tetrakis_hexahedron_verts[10], RadEdg }
  cylinder { Catalan_tetrakis_hexahedron_verts[13], Catalan_tetrakis_hexahedron_verts[12], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_tetrakis_hexahedron_verts[13];
 #local P1 = Catalan_tetrakis_hexahedron_verts[10];
 #local P2 = Catalan_tetrakis_hexahedron_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_trapezoidal_icositetrahedron_verts = array[26]
{
<0.3574067, 0.4142136, 0.9339488>,
<-0.2764395, 0.3203772, 0.9339488>,
<-0.4620888, -0.2928932, 0.9339488>,
<0.3574067, -0.4142136, 0.9339488>,
<0.9675382, -0.2928932, 0.3868543>,
<0.8293185, 0.3203772, 0.5107936>,
<0.1480427, 1., 0.3868543>,
<-0.6101315, 0.7071068, 0.5470946>,
<-1.010899, 0, 0.3868543>,
<-0.438374, -0.7734591, 0.5107936>,
<0.1480427, -1., 0.3868543>,
<0.8194955, 0.7071068, 0>,
<1.010899, 0, -0.3868543>,
<0.667384, -0.7734591, 0.08763832>,
<-0.1480427, 1., -0.3868543>,
<-0.667384, 0.7734591, -0.08763832>,
<-0.8194955, -0.7071068, 0>,
<-0.9675382, 0.2928932, -0.3868543>,
<-0.1480427, -1., -0.3868543>,
<0.438374, 0.7734591, -0.5107936>,
<0.6101315, -0.7071068, -0.5470946>,
<0.4620888, 0.2928932, -0.9339488>,
<-0.3574067, 0.4142136, -0.9339488>,
<-0.8293185, -0.3203772, -0.5107936>
<-0.3574067, -0.4142136, -0.9339488>,
<0.2764395, -0.3203772, -0.9339488>,
}
#local P0 = Catalan_trapezoidal_icositetrahedron_verts[9];
#local P1 = Catalan_trapezoidal_icositetrahedron_verts[13];
#local P2 = Catalan_trapezoidal_icositetrahedron_verts[10];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 26)
 #declare Catalan_trapezoidal_icositetrahedron_verts[Num] = vtransform(Catalan_trapezoidal_icositetrahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_trapezoidal_icositetrahedron_faces(Tex4, OnPlane)
#local Catalan_trapezoidal_icositetrahedron_obj = mesh2 {
 vertex_vectors {
  26,
  Catalan_trapezoidal_icositetrahedron_verts[0],
  Catalan_trapezoidal_icositetrahedron_verts[1],
  Catalan_trapezoidal_icositetrahedron_verts[2],
  Catalan_trapezoidal_icositetrahedron_verts[3],
  Catalan_trapezoidal_icositetrahedron_verts[4],
  Catalan_trapezoidal_icositetrahedron_verts[5],
  Catalan_trapezoidal_icositetrahedron_verts[6],
  Catalan_trapezoidal_icositetrahedron_verts[7],
  Catalan_trapezoidal_icositetrahedron_verts[8],
  Catalan_trapezoidal_icositetrahedron_verts[9],
  Catalan_trapezoidal_icositetrahedron_verts[10],
  Catalan_trapezoidal_icositetrahedron_verts[11],
  Catalan_trapezoidal_icositetrahedron_verts[12],
  Catalan_trapezoidal_icositetrahedron_verts[13],
  Catalan_trapezoidal_icositetrahedron_verts[14],
  Catalan_trapezoidal_icositetrahedron_verts[15],
  Catalan_trapezoidal_icositetrahedron_verts[16],
  Catalan_trapezoidal_icositetrahedron_verts[17],
  Catalan_trapezoidal_icositetrahedron_verts[18],
  Catalan_trapezoidal_icositetrahedron_verts[19],
  Catalan_trapezoidal_icositetrahedron_verts[20],
  Catalan_trapezoidal_icositetrahedron_verts[21],
  Catalan_trapezoidal_icositetrahedron_verts[22],
  Catalan_trapezoidal_icositetrahedron_verts[23],
  Catalan_trapezoidal_icositetrahedron_verts[24],
  Catalan_trapezoidal_icositetrahedron_verts[25]
 }
 texture_list {
  1,
  texture { Tex4 }
 }
 face_indices {
  48,
  <3, 0, 1>, 0,
  <3, 1, 2>, 0,
  <3, 4, 5>, 0,
  <3, 5, 0>, 0,
  <0, 6, 7>, 0,
  <0, 7, 1>, 0,
  <1, 7, 8>, 0,
  <1, 8, 2>, 0,
  <2, 9, 10>, 0,
  <2, 10, 3>, 0,
  <0, 5, 11>, 0,
  <0, 11, 6>, 0,
  <5, 4, 12>, 0,
  <5, 12, 11>, 0,
  <4, 3, 10>, 0,
  <4, 10, 13>, 0,
  <7, 6, 14>, 0,
  <7, 14, 15>, 0,
  <2, 8, 16>, 0,
  <2, 16, 9>, 0,
  <8, 7, 15>, 0,
  <8, 15, 17>, 0,
  <10, 9, 16>, 0,
  <10, 16, 18>, 0,
  <11, 19, 14>, 0,
  <11, 14, 6>, 0,
  <4, 13, 20>, 0,
  <4, 20, 12>, 0,
  <12, 21, 19>, 0,
  <12, 19, 11>, 0,
  <10, 18, 20>, 0,
  <10, 20, 13>, 0,
  <14, 22, 17>, 0,
  <14, 17, 15>, 0,
  <8, 17, 23>, 0,
  <8, 23, 16>, 0,
  <16, 23, 24>, 0,
  <16, 24, 18>, 0,
  <14, 19, 21>, 0,
  <14, 21, 22>, 0,
  <12, 20, 25>, 0,
  <12, 25, 21>, 0,
  <20, 18, 24>, 0,
  <20, 24, 25>, 0,
  <17, 22, 24>, 0,
  <17, 24, 23>, 0,
  <21, 25, 24>, 0,
  <21, 24, 22>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_trapezoidal_icositetrahedron_verts[21];
 #local P1 = Catalan_trapezoidal_icositetrahedron_verts[25];
 #local P2 = Catalan_trapezoidal_icositetrahedron_verts[24];
 #local P3 = Catalan_trapezoidal_icositetrahedron_verts[22];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_trapezoidal_icositetrahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_trapezoidal_icositetrahedron_obj }
#end
#end

#macro Catalan_trapezoidal_icositetrahedron_faces2(OnPlane)
#local Catalan_trapezoidal_icositetrahedron_obj = mesh2 {
 vertex_vectors {
  26,
  Catalan_trapezoidal_icositetrahedron_verts[0],
  Catalan_trapezoidal_icositetrahedron_verts[1],
  Catalan_trapezoidal_icositetrahedron_verts[2],
  Catalan_trapezoidal_icositetrahedron_verts[3],
  Catalan_trapezoidal_icositetrahedron_verts[4],
  Catalan_trapezoidal_icositetrahedron_verts[5],
  Catalan_trapezoidal_icositetrahedron_verts[6],
  Catalan_trapezoidal_icositetrahedron_verts[7],
  Catalan_trapezoidal_icositetrahedron_verts[8],
  Catalan_trapezoidal_icositetrahedron_verts[9],
  Catalan_trapezoidal_icositetrahedron_verts[10],
  Catalan_trapezoidal_icositetrahedron_verts[11],
  Catalan_trapezoidal_icositetrahedron_verts[12],
  Catalan_trapezoidal_icositetrahedron_verts[13],
  Catalan_trapezoidal_icositetrahedron_verts[14],
  Catalan_trapezoidal_icositetrahedron_verts[15],
  Catalan_trapezoidal_icositetrahedron_verts[16],
  Catalan_trapezoidal_icositetrahedron_verts[17],
  Catalan_trapezoidal_icositetrahedron_verts[18],
  Catalan_trapezoidal_icositetrahedron_verts[19],
  Catalan_trapezoidal_icositetrahedron_verts[20],
  Catalan_trapezoidal_icositetrahedron_verts[21],
  Catalan_trapezoidal_icositetrahedron_verts[22],
  Catalan_trapezoidal_icositetrahedron_verts[23],
  Catalan_trapezoidal_icositetrahedron_verts[24],
  Catalan_trapezoidal_icositetrahedron_verts[25]
 }
 face_indices {
  48,
  <3, 0, 1>,
  <3, 1, 2>,
  <3, 4, 5>,
  <3, 5, 0>,
  <0, 6, 7>,
  <0, 7, 1>,
  <1, 7, 8>,
  <1, 8, 2>,
  <2, 9, 10>,
  <2, 10, 3>,
  <0, 5, 11>,
  <0, 11, 6>,
  <5, 4, 12>,
  <5, 12, 11>,
  <4, 3, 10>,
  <4, 10, 13>,
  <7, 6, 14>,
  <7, 14, 15>,
  <2, 8, 16>,
  <2, 16, 9>,
  <8, 7, 15>,
  <8, 15, 17>,
  <10, 9, 16>,
  <10, 16, 18>,
  <11, 19, 14>,
  <11, 14, 6>,
  <4, 13, 20>,
  <4, 20, 12>,
  <12, 21, 19>,
  <12, 19, 11>,
  <10, 18, 20>,
  <10, 20, 13>,
  <14, 22, 17>,
  <14, 17, 15>,
  <8, 17, 23>,
  <8, 23, 16>,
  <16, 23, 24>,
  <16, 24, 18>,
  <14, 19, 21>,
  <14, 21, 22>,
  <12, 20, 25>,
  <12, 25, 21>,
  <20, 18, 24>,
  <20, 24, 25>,
  <17, 22, 24>,
  <17, 24, 23>,
  <21, 25, 24>,
  <21, 24, 22>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_trapezoidal_icositetrahedron_verts[21];
 #local P1 = Catalan_trapezoidal_icositetrahedron_verts[25];
 #local P2 = Catalan_trapezoidal_icositetrahedron_verts[24];
 #local P3 = Catalan_trapezoidal_icositetrahedron_verts[22];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_trapezoidal_icositetrahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_trapezoidal_icositetrahedron_obj }
#end
#end

#macro Catalan_trapezoidal_icositetrahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_trapezoidal_icositetrahedron_verts[0], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[1], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[2], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[3], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[4], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[5], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[6], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[7], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[8], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[9], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[10], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[11], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[12], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[13], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[14], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[15], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[16], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[17], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[18], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[19], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[20], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[21], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[22], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[23], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[24], RadVer }
  sphere { Catalan_trapezoidal_icositetrahedron_verts[25], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[3], Catalan_trapezoidal_icositetrahedron_verts[0], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[0], Catalan_trapezoidal_icositetrahedron_verts[1], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[1], Catalan_trapezoidal_icositetrahedron_verts[2], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[2], Catalan_trapezoidal_icositetrahedron_verts[3], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[3], Catalan_trapezoidal_icositetrahedron_verts[4], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[4], Catalan_trapezoidal_icositetrahedron_verts[5], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[5], Catalan_trapezoidal_icositetrahedron_verts[0], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[0], Catalan_trapezoidal_icositetrahedron_verts[6], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[6], Catalan_trapezoidal_icositetrahedron_verts[7], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[7], Catalan_trapezoidal_icositetrahedron_verts[1], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[7], Catalan_trapezoidal_icositetrahedron_verts[8], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[8], Catalan_trapezoidal_icositetrahedron_verts[2], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[2], Catalan_trapezoidal_icositetrahedron_verts[9], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[9], Catalan_trapezoidal_icositetrahedron_verts[10], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[10], Catalan_trapezoidal_icositetrahedron_verts[3], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[5], Catalan_trapezoidal_icositetrahedron_verts[11], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[11], Catalan_trapezoidal_icositetrahedron_verts[6], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[4], Catalan_trapezoidal_icositetrahedron_verts[12], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[12], Catalan_trapezoidal_icositetrahedron_verts[11], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[10], Catalan_trapezoidal_icositetrahedron_verts[13], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[13], Catalan_trapezoidal_icositetrahedron_verts[4], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[6], Catalan_trapezoidal_icositetrahedron_verts[14], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[14], Catalan_trapezoidal_icositetrahedron_verts[15], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[15], Catalan_trapezoidal_icositetrahedron_verts[7], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[8], Catalan_trapezoidal_icositetrahedron_verts[16], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[16], Catalan_trapezoidal_icositetrahedron_verts[9], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[15], Catalan_trapezoidal_icositetrahedron_verts[17], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[17], Catalan_trapezoidal_icositetrahedron_verts[8], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[16], Catalan_trapezoidal_icositetrahedron_verts[18], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[18], Catalan_trapezoidal_icositetrahedron_verts[10], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[11], Catalan_trapezoidal_icositetrahedron_verts[19], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[19], Catalan_trapezoidal_icositetrahedron_verts[14], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[13], Catalan_trapezoidal_icositetrahedron_verts[20], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[20], Catalan_trapezoidal_icositetrahedron_verts[12], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[12], Catalan_trapezoidal_icositetrahedron_verts[21], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[21], Catalan_trapezoidal_icositetrahedron_verts[19], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[18], Catalan_trapezoidal_icositetrahedron_verts[20], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[14], Catalan_trapezoidal_icositetrahedron_verts[22], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[22], Catalan_trapezoidal_icositetrahedron_verts[17], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[17], Catalan_trapezoidal_icositetrahedron_verts[23], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[23], Catalan_trapezoidal_icositetrahedron_verts[16], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[23], Catalan_trapezoidal_icositetrahedron_verts[24], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[24], Catalan_trapezoidal_icositetrahedron_verts[18], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[21], Catalan_trapezoidal_icositetrahedron_verts[22], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[20], Catalan_trapezoidal_icositetrahedron_verts[25], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[25], Catalan_trapezoidal_icositetrahedron_verts[21], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[24], Catalan_trapezoidal_icositetrahedron_verts[25], RadEdg }
  cylinder { Catalan_trapezoidal_icositetrahedron_verts[22], Catalan_trapezoidal_icositetrahedron_verts[24], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_trapezoidal_icositetrahedron_verts[21];
 #local P1 = Catalan_trapezoidal_icositetrahedron_verts[25];
 #local P2 = Catalan_trapezoidal_icositetrahedron_verts[24];
 #local P3 = Catalan_trapezoidal_icositetrahedron_verts[22];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_disdyakis_dodecahedron_verts = array[26]
{
<0.2157394, 0.2265409, 0.976451>,
<-0.4242512, 0.1952621, 0.976451>,
<0.2157394, -0.6306019, 0.976451>,
<0.7961552, 0.1952621, 0.7068115>,
<0.1360457, 1., 0.6157519>,
<-0.5756442, -0.3867295, 0.7552449>,
<0.8402574, -0.3867295, 0.4424122>,
<-0.624518, 0.6132705, 0.5340388>,
<-0.5680774, -0.8619288, 0.3254837>,
<-1.154386, 0, 0.2550528>,
<0.7913836, 0.6132705, 0.2212061>,
<0.6523289, -0.8619288, 0.05584417>,
<1.154386, 0, -0.2550528>,
<-0.6523289, 0.8619288, -0.05584417>,
<0.0488738, -1., 0.2212061>,
<0.5680774, 0.8619288, -0.3254837>,
<-0.0488738, 1., -0.2212061>,
<-0.7913836, -0.6132705, -0.2212061>,
<-0.1360457, -1., -0.6157519>,
<0.624518, -0.6132705, -0.5340388>,
<-0.8402574, 0.3867295, -0.4424122>,
<-0.2157394, 0.6306019, -0.976451>,
<-0.7961552, -0.1952621, -0.7068115>,
<0.5756442, 0.3867295, -0.7552449>
<0.4242512, -0.1952621, -0.976451>,
<-0.2157394, -0.2265409, -0.976451>,
}
#local P0 = Catalan_disdyakis_dodecahedron_verts[3];
#local P1 = Catalan_disdyakis_dodecahedron_verts[1];
#local P2 = Catalan_disdyakis_dodecahedron_verts[8];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 26)
 #declare Catalan_disdyakis_dodecahedron_verts[Num] = vtransform(Catalan_disdyakis_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_disdyakis_dodecahedron_faces(Tex3, OnPlane)
#local Catalan_disdyakis_dodecahedron_obj = mesh2 {
 vertex_vectors {
  26,
  Catalan_disdyakis_dodecahedron_verts[0],
  Catalan_disdyakis_dodecahedron_verts[1],
  Catalan_disdyakis_dodecahedron_verts[2],
  Catalan_disdyakis_dodecahedron_verts[3],
  Catalan_disdyakis_dodecahedron_verts[4],
  Catalan_disdyakis_dodecahedron_verts[5],
  Catalan_disdyakis_dodecahedron_verts[6],
  Catalan_disdyakis_dodecahedron_verts[7],
  Catalan_disdyakis_dodecahedron_verts[8],
  Catalan_disdyakis_dodecahedron_verts[9],
  Catalan_disdyakis_dodecahedron_verts[10],
  Catalan_disdyakis_dodecahedron_verts[11],
  Catalan_disdyakis_dodecahedron_verts[12],
  Catalan_disdyakis_dodecahedron_verts[13],
  Catalan_disdyakis_dodecahedron_verts[14],
  Catalan_disdyakis_dodecahedron_verts[15],
  Catalan_disdyakis_dodecahedron_verts[16],
  Catalan_disdyakis_dodecahedron_verts[17],
  Catalan_disdyakis_dodecahedron_verts[18],
  Catalan_disdyakis_dodecahedron_verts[19],
  Catalan_disdyakis_dodecahedron_verts[20],
  Catalan_disdyakis_dodecahedron_verts[21],
  Catalan_disdyakis_dodecahedron_verts[22],
  Catalan_disdyakis_dodecahedron_verts[23],
  Catalan_disdyakis_dodecahedron_verts[24],
  Catalan_disdyakis_dodecahedron_verts[25]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  48,
  <2, 0, 1>, 0,
  <2, 3, 0>, 0,
  <0, 4, 1>, 0,
  <1, 5, 2>, 0,
  <0, 3, 4>, 0,
  <3, 2, 6>, 0,
  <1, 4, 7>, 0,
  <2, 5, 8>, 0,
  <5, 1, 9>, 0,
  <3, 10, 4>, 0,
  <2, 11, 6>, 0,
  <6, 12, 3>, 0,
  <4, 13, 7>, 0,
  <7, 9, 1>, 0,
  <5, 9, 8>, 0,
  <8, 14, 2>, 0,
  <4, 10, 15>, 0,
  <10, 3, 12>, 0,
  <6, 11, 12>, 0,
  <11, 2, 14>, 0,
  <7, 13, 9>, 0,
  <13, 4, 16>, 0,
  <8, 9, 17>, 0,
  <14, 8, 18>, 0,
  <10, 12, 15>, 0,
  <15, 16, 4>, 0,
  <11, 19, 12>, 0,
  <14, 18, 11>, 0,
  <13, 20, 9>, 0,
  <16, 21, 13>, 0,
  <9, 22, 17>, 0,
  <17, 18, 8>, 0,
  <15, 12, 23>, 0,
  <16, 15, 21>, 0,
  <12, 19, 24>, 0,
  <19, 11, 18>, 0,
  <9, 20, 22>, 0,
  <20, 13, 21>, 0,
  <17, 22, 18>, 0,
  <12, 24, 23>, 0,
  <23, 21, 15>, 0,
  <19, 18, 24>, 0,
  <20, 21, 22>, 0,
  <22, 25, 18>, 0,
  <23, 24, 21>, 0,
  <24, 18, 25>, 0,
  <22, 21, 25>, 0,
  <24, 25, 21>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_disdyakis_dodecahedron_verts[24];
 #local P1 = Catalan_disdyakis_dodecahedron_verts[25];
 #local P2 = Catalan_disdyakis_dodecahedron_verts[21];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_disdyakis_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_disdyakis_dodecahedron_obj }
#end
#end

#macro Catalan_disdyakis_dodecahedron_faces2(OnPlane)
#local Catalan_disdyakis_dodecahedron_obj = mesh2 {
 vertex_vectors {
  26,
  Catalan_disdyakis_dodecahedron_verts[0],
  Catalan_disdyakis_dodecahedron_verts[1],
  Catalan_disdyakis_dodecahedron_verts[2],
  Catalan_disdyakis_dodecahedron_verts[3],
  Catalan_disdyakis_dodecahedron_verts[4],
  Catalan_disdyakis_dodecahedron_verts[5],
  Catalan_disdyakis_dodecahedron_verts[6],
  Catalan_disdyakis_dodecahedron_verts[7],
  Catalan_disdyakis_dodecahedron_verts[8],
  Catalan_disdyakis_dodecahedron_verts[9],
  Catalan_disdyakis_dodecahedron_verts[10],
  Catalan_disdyakis_dodecahedron_verts[11],
  Catalan_disdyakis_dodecahedron_verts[12],
  Catalan_disdyakis_dodecahedron_verts[13],
  Catalan_disdyakis_dodecahedron_verts[14],
  Catalan_disdyakis_dodecahedron_verts[15],
  Catalan_disdyakis_dodecahedron_verts[16],
  Catalan_disdyakis_dodecahedron_verts[17],
  Catalan_disdyakis_dodecahedron_verts[18],
  Catalan_disdyakis_dodecahedron_verts[19],
  Catalan_disdyakis_dodecahedron_verts[20],
  Catalan_disdyakis_dodecahedron_verts[21],
  Catalan_disdyakis_dodecahedron_verts[22],
  Catalan_disdyakis_dodecahedron_verts[23],
  Catalan_disdyakis_dodecahedron_verts[24],
  Catalan_disdyakis_dodecahedron_verts[25]
 }
 face_indices {
  48,
  <2, 0, 1>,
  <2, 3, 0>,
  <0, 4, 1>,
  <1, 5, 2>,
  <0, 3, 4>,
  <3, 2, 6>,
  <1, 4, 7>,
  <2, 5, 8>,
  <5, 1, 9>,
  <3, 10, 4>,
  <2, 11, 6>,
  <6, 12, 3>,
  <4, 13, 7>,
  <7, 9, 1>,
  <5, 9, 8>,
  <8, 14, 2>,
  <4, 10, 15>,
  <10, 3, 12>,
  <6, 11, 12>,
  <11, 2, 14>,
  <7, 13, 9>,
  <13, 4, 16>,
  <8, 9, 17>,
  <14, 8, 18>,
  <10, 12, 15>,
  <15, 16, 4>,
  <11, 19, 12>,
  <14, 18, 11>,
  <13, 20, 9>,
  <16, 21, 13>,
  <9, 22, 17>,
  <17, 18, 8>,
  <15, 12, 23>,
  <16, 15, 21>,
  <12, 19, 24>,
  <19, 11, 18>,
  <9, 20, 22>,
  <20, 13, 21>,
  <17, 22, 18>,
  <12, 24, 23>,
  <23, 21, 15>,
  <19, 18, 24>,
  <20, 21, 22>,
  <22, 25, 18>,
  <23, 24, 21>,
  <24, 18, 25>,
  <22, 21, 25>,
  <24, 25, 21>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_disdyakis_dodecahedron_verts[24];
 #local P1 = Catalan_disdyakis_dodecahedron_verts[25];
 #local P2 = Catalan_disdyakis_dodecahedron_verts[21];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_disdyakis_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_disdyakis_dodecahedron_obj }
#end
#end

#macro Catalan_disdyakis_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_disdyakis_dodecahedron_verts[0], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[1], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[2], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[3], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[4], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[5], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[6], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[7], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[8], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[9], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[10], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[11], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[12], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[13], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[14], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[15], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[16], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[17], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[18], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[19], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[20], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[21], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[22], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[23], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[24], RadVer }
  sphere { Catalan_disdyakis_dodecahedron_verts[25], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_disdyakis_dodecahedron_verts[2], Catalan_disdyakis_dodecahedron_verts[0], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[0], Catalan_disdyakis_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[1], Catalan_disdyakis_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[2], Catalan_disdyakis_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[3], Catalan_disdyakis_dodecahedron_verts[0], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[0], Catalan_disdyakis_dodecahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[4], Catalan_disdyakis_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[1], Catalan_disdyakis_dodecahedron_verts[5], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[5], Catalan_disdyakis_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[3], Catalan_disdyakis_dodecahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[2], Catalan_disdyakis_dodecahedron_verts[6], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[6], Catalan_disdyakis_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[4], Catalan_disdyakis_dodecahedron_verts[7], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[7], Catalan_disdyakis_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[5], Catalan_disdyakis_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[8], Catalan_disdyakis_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[1], Catalan_disdyakis_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[9], Catalan_disdyakis_dodecahedron_verts[5], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[3], Catalan_disdyakis_dodecahedron_verts[10], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[10], Catalan_disdyakis_dodecahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[2], Catalan_disdyakis_dodecahedron_verts[11], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[11], Catalan_disdyakis_dodecahedron_verts[6], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[6], Catalan_disdyakis_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[12], Catalan_disdyakis_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[4], Catalan_disdyakis_dodecahedron_verts[13], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[13], Catalan_disdyakis_dodecahedron_verts[7], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[7], Catalan_disdyakis_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[9], Catalan_disdyakis_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[8], Catalan_disdyakis_dodecahedron_verts[14], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[14], Catalan_disdyakis_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[10], Catalan_disdyakis_dodecahedron_verts[15], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[15], Catalan_disdyakis_dodecahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[12], Catalan_disdyakis_dodecahedron_verts[10], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[11], Catalan_disdyakis_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[14], Catalan_disdyakis_dodecahedron_verts[11], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[13], Catalan_disdyakis_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[4], Catalan_disdyakis_dodecahedron_verts[16], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[16], Catalan_disdyakis_dodecahedron_verts[13], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[9], Catalan_disdyakis_dodecahedron_verts[17], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[17], Catalan_disdyakis_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[8], Catalan_disdyakis_dodecahedron_verts[18], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[18], Catalan_disdyakis_dodecahedron_verts[14], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[12], Catalan_disdyakis_dodecahedron_verts[15], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[15], Catalan_disdyakis_dodecahedron_verts[16], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[11], Catalan_disdyakis_dodecahedron_verts[19], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[19], Catalan_disdyakis_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[18], Catalan_disdyakis_dodecahedron_verts[11], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[13], Catalan_disdyakis_dodecahedron_verts[20], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[20], Catalan_disdyakis_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[16], Catalan_disdyakis_dodecahedron_verts[21], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[21], Catalan_disdyakis_dodecahedron_verts[13], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[9], Catalan_disdyakis_dodecahedron_verts[22], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[22], Catalan_disdyakis_dodecahedron_verts[17], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[17], Catalan_disdyakis_dodecahedron_verts[18], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[12], Catalan_disdyakis_dodecahedron_verts[23], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[23], Catalan_disdyakis_dodecahedron_verts[15], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[15], Catalan_disdyakis_dodecahedron_verts[21], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[19], Catalan_disdyakis_dodecahedron_verts[24], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[24], Catalan_disdyakis_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[18], Catalan_disdyakis_dodecahedron_verts[19], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[20], Catalan_disdyakis_dodecahedron_verts[22], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[21], Catalan_disdyakis_dodecahedron_verts[20], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[22], Catalan_disdyakis_dodecahedron_verts[18], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[24], Catalan_disdyakis_dodecahedron_verts[23], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[23], Catalan_disdyakis_dodecahedron_verts[21], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[18], Catalan_disdyakis_dodecahedron_verts[24], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[21], Catalan_disdyakis_dodecahedron_verts[22], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[22], Catalan_disdyakis_dodecahedron_verts[25], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[25], Catalan_disdyakis_dodecahedron_verts[18], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[24], Catalan_disdyakis_dodecahedron_verts[21], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[25], Catalan_disdyakis_dodecahedron_verts[24], RadEdg }
  cylinder { Catalan_disdyakis_dodecahedron_verts[21], Catalan_disdyakis_dodecahedron_verts[25], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_disdyakis_dodecahedron_verts[24];
 #local P1 = Catalan_disdyakis_dodecahedron_verts[25];
 #local P2 = Catalan_disdyakis_dodecahedron_verts[21];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_pentagonal_icositetrahedron_verts = array[38]
{
<0.3721032, 0.2379147, 0.9281914>,
<-0.05980191, 0.4375933, 0.9281914>,
<-0.4222941, 0.1293516, 0.9281914>,
<-0.2946239, -0.3290302, 0.9281914>,
<0.3721032, -0.4375933, 0.9281914>,
<0.8541992, -0.3290302, 0.467639>,
<0.9465147, 0.1293516, 0.3794488>,
<0.6844044, 0.4375933, 0.6298461>,
<0.5146097, 0.8048595, 0.3794488>,
<-0.1310552, 0.9589804, 0.5046475>,
<-0.7116927, 0.6372719, 0.3794488>,
<-0.77672, 0.2379147, 0.6298461>,
<-1.017768, -0.2834724, 0.2743713>,
<-0.5418979, -0.6051809, 0.6298461>,
<-0.2797876, -0.9134226, 0.3794488>,
<0.1874721, -0.8959751, 0.467639>,
<0.4644187, -0.9134226, 0.08110353>,
<0.8269109, -0.6051809, 0.08110353>,
<0.8963238, -0.3785687, -0.3315008>,
<1.017768, 0.2834724, -0.2743713>,
<0.6342135, 0.8048595, -0.08110353>,
<0.2797876, 0.9134226, -0.3794488>,
<-0.1372811, 1.004538, -0.1692937>,
<-0.5146097, 0.8048595, -0.3794488>
<-0.8269109, 0.6051809, -0.08110353>,
<-0.9886393, 0.1788901, -0.2172418>,
<-0.7538173, -0.6642055, -0.2172418>,
<-0.3950058, -0.9455136, -0.08110353>,
<0.1310552, -0.9589804, -0.5046475>,
<0.5920889, -0.4966178, -0.6777941>,
<0.4222941, -0.1293516, -0.9281914>,
<0.5840225, 0.2969392, -0.7920531>,
<0.2524994, 0.6372719, -0.7659843>,
<-0.3721032, 0.4375933, -0.9281914>,
<-0.8120746, 0.02078851, -0.6298461>,
<-0.6844044, -0.4375933, -0.6298461>,
<-0.2673357, -0.5287088, -0.8400012>,
<-0.04496558, -0.1467991, -1.016382>,
}
#local P0 = Catalan_pentagonal_icositetrahedron_verts[34];
#local P1 = Catalan_pentagonal_icositetrahedron_verts[33];
#local P2 = Catalan_pentagonal_icositetrahedron_verts[37];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 38)
 #declare Catalan_pentagonal_icositetrahedron_verts[Num] = vtransform(Catalan_pentagonal_icositetrahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_pentagonal_icositetrahedron_faces(Tex5, OnPlane)
#local Catalan_pentagonal_icositetrahedron_obj = mesh2 {
 vertex_vectors {
  38,
  Catalan_pentagonal_icositetrahedron_verts[0],
  Catalan_pentagonal_icositetrahedron_verts[1],
  Catalan_pentagonal_icositetrahedron_verts[2],
  Catalan_pentagonal_icositetrahedron_verts[3],
  Catalan_pentagonal_icositetrahedron_verts[4],
  Catalan_pentagonal_icositetrahedron_verts[5],
  Catalan_pentagonal_icositetrahedron_verts[6],
  Catalan_pentagonal_icositetrahedron_verts[7],
  Catalan_pentagonal_icositetrahedron_verts[8],
  Catalan_pentagonal_icositetrahedron_verts[9],
  Catalan_pentagonal_icositetrahedron_verts[10],
  Catalan_pentagonal_icositetrahedron_verts[11],
  Catalan_pentagonal_icositetrahedron_verts[12],
  Catalan_pentagonal_icositetrahedron_verts[13],
  Catalan_pentagonal_icositetrahedron_verts[14],
  Catalan_pentagonal_icositetrahedron_verts[15],
  Catalan_pentagonal_icositetrahedron_verts[16],
  Catalan_pentagonal_icositetrahedron_verts[17],
  Catalan_pentagonal_icositetrahedron_verts[18],
  Catalan_pentagonal_icositetrahedron_verts[19],
  Catalan_pentagonal_icositetrahedron_verts[20],
  Catalan_pentagonal_icositetrahedron_verts[21],
  Catalan_pentagonal_icositetrahedron_verts[22],
  Catalan_pentagonal_icositetrahedron_verts[23],
  Catalan_pentagonal_icositetrahedron_verts[24],
  Catalan_pentagonal_icositetrahedron_verts[25],
  Catalan_pentagonal_icositetrahedron_verts[26],
  Catalan_pentagonal_icositetrahedron_verts[27],
  Catalan_pentagonal_icositetrahedron_verts[28],
  Catalan_pentagonal_icositetrahedron_verts[29],
  Catalan_pentagonal_icositetrahedron_verts[30],
  Catalan_pentagonal_icositetrahedron_verts[31],
  Catalan_pentagonal_icositetrahedron_verts[32],
  Catalan_pentagonal_icositetrahedron_verts[33],
  Catalan_pentagonal_icositetrahedron_verts[34],
  Catalan_pentagonal_icositetrahedron_verts[35],
  Catalan_pentagonal_icositetrahedron_verts[36],
  Catalan_pentagonal_icositetrahedron_verts[37]
 }
 texture_list {
  1,
  texture { Tex5 }
 }
 face_indices {
  72,
  <4, 0, 1>, 0,
  <4, 1, 2>, 0,
  <4, 2, 3>, 0,
  <0, 4, 5>, 0,
  <0, 5, 6>, 0,
  <0, 6, 7>, 0,
  <1, 0, 7>, 0,
  <1, 7, 8>, 0,
  <1, 8, 9>, 0,
  <2, 1, 9>, 0,
  <2, 9, 10>, 0,
  <2, 10, 11>, 0,
  <3, 2, 11>, 0,
  <3, 11, 12>, 0,
  <3, 12, 13>, 0,
  <4, 3, 13>, 0,
  <4, 13, 14>, 0,
  <4, 14, 15>, 0,
  <5, 4, 15>, 0,
  <5, 15, 16>, 0,
  <5, 16, 17>, 0,
  <6, 5, 17>, 0,
  <6, 17, 18>, 0,
  <6, 18, 19>, 0,
  <7, 6, 19>, 0,
  <7, 19, 20>, 0,
  <7, 20, 8>, 0,
  <9, 8, 20>, 0,
  <9, 20, 21>, 0,
  <9, 21, 22>, 0,
  <10, 9, 22>, 0,
  <10, 22, 23>, 0,
  <10, 23, 24>, 0,
  <11, 10, 24>, 0,
  <11, 24, 25>, 0,
  <11, 25, 12>, 0,
  <13, 12, 26>, 0,
  <13, 26, 27>, 0,
  <13, 27, 14>, 0,
  <15, 14, 27>, 0,
  <15, 27, 28>, 0,
  <15, 28, 16>, 0,
  <17, 16, 28>, 0,
  <17, 28, 29>, 0,
  <17, 29, 18>, 0,
  <19, 18, 29>, 0,
  <19, 29, 30>, 0,
  <19, 30, 31>, 0,
  <20, 19, 31>, 0,
  <20, 31, 32>, 0,
  <20, 32, 21>, 0,
  <22, 21, 32>, 0,
  <22, 32, 33>, 0,
  <22, 33, 23>, 0,
  <24, 23, 33>, 0,
  <24, 33, 34>, 0,
  <24, 34, 25>, 0,
  <12, 25, 34>, 0,
  <12, 34, 35>, 0,
  <12, 35, 26>, 0,
  <27, 26, 35>, 0,
  <27, 35, 36>, 0,
  <27, 36, 28>, 0,
  <29, 28, 36>, 0,
  <29, 36, 37>, 0,
  <29, 37, 30>, 0,
  <31, 30, 37>, 0,
  <31, 37, 33>, 0,
  <31, 33, 32>, 0,
  <34, 33, 37>, 0,
  <34, 37, 36>, 0,
  <34, 36, 35>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_pentagonal_icositetrahedron_verts[34];
 #local P1 = Catalan_pentagonal_icositetrahedron_verts[33];
 #local P2 = Catalan_pentagonal_icositetrahedron_verts[37];
 #local P3 = Catalan_pentagonal_icositetrahedron_verts[36];
 #local P4 = Catalan_pentagonal_icositetrahedron_verts[35];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_pentagonal_icositetrahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_pentagonal_icositetrahedron_obj }
#end
#end

#macro Catalan_pentagonal_icositetrahedron_faces2(OnPlane)
#local Catalan_pentagonal_icositetrahedron_obj = mesh2 {
 vertex_vectors {
  38,
  Catalan_pentagonal_icositetrahedron_verts[0],
  Catalan_pentagonal_icositetrahedron_verts[1],
  Catalan_pentagonal_icositetrahedron_verts[2],
  Catalan_pentagonal_icositetrahedron_verts[3],
  Catalan_pentagonal_icositetrahedron_verts[4],
  Catalan_pentagonal_icositetrahedron_verts[5],
  Catalan_pentagonal_icositetrahedron_verts[6],
  Catalan_pentagonal_icositetrahedron_verts[7],
  Catalan_pentagonal_icositetrahedron_verts[8],
  Catalan_pentagonal_icositetrahedron_verts[9],
  Catalan_pentagonal_icositetrahedron_verts[10],
  Catalan_pentagonal_icositetrahedron_verts[11],
  Catalan_pentagonal_icositetrahedron_verts[12],
  Catalan_pentagonal_icositetrahedron_verts[13],
  Catalan_pentagonal_icositetrahedron_verts[14],
  Catalan_pentagonal_icositetrahedron_verts[15],
  Catalan_pentagonal_icositetrahedron_verts[16],
  Catalan_pentagonal_icositetrahedron_verts[17],
  Catalan_pentagonal_icositetrahedron_verts[18],
  Catalan_pentagonal_icositetrahedron_verts[19],
  Catalan_pentagonal_icositetrahedron_verts[20],
  Catalan_pentagonal_icositetrahedron_verts[21],
  Catalan_pentagonal_icositetrahedron_verts[22],
  Catalan_pentagonal_icositetrahedron_verts[23],
  Catalan_pentagonal_icositetrahedron_verts[24],
  Catalan_pentagonal_icositetrahedron_verts[25],
  Catalan_pentagonal_icositetrahedron_verts[26],
  Catalan_pentagonal_icositetrahedron_verts[27],
  Catalan_pentagonal_icositetrahedron_verts[28],
  Catalan_pentagonal_icositetrahedron_verts[29],
  Catalan_pentagonal_icositetrahedron_verts[30],
  Catalan_pentagonal_icositetrahedron_verts[31],
  Catalan_pentagonal_icositetrahedron_verts[32],
  Catalan_pentagonal_icositetrahedron_verts[33],
  Catalan_pentagonal_icositetrahedron_verts[34],
  Catalan_pentagonal_icositetrahedron_verts[35],
  Catalan_pentagonal_icositetrahedron_verts[36],
  Catalan_pentagonal_icositetrahedron_verts[37]
 }
 face_indices {
  72,
  <4, 0, 1>,
  <4, 1, 2>,
  <4, 2, 3>,
  <0, 4, 5>,
  <0, 5, 6>,
  <0, 6, 7>,
  <1, 0, 7>,
  <1, 7, 8>,
  <1, 8, 9>,
  <2, 1, 9>,
  <2, 9, 10>,
  <2, 10, 11>,
  <3, 2, 11>,
  <3, 11, 12>,
  <3, 12, 13>,
  <4, 3, 13>,
  <4, 13, 14>,
  <4, 14, 15>,
  <5, 4, 15>,
  <5, 15, 16>,
  <5, 16, 17>,
  <6, 5, 17>,
  <6, 17, 18>,
  <6, 18, 19>,
  <7, 6, 19>,
  <7, 19, 20>,
  <7, 20, 8>,
  <9, 8, 20>,
  <9, 20, 21>,
  <9, 21, 22>,
  <10, 9, 22>,
  <10, 22, 23>,
  <10, 23, 24>,
  <11, 10, 24>,
  <11, 24, 25>,
  <11, 25, 12>,
  <13, 12, 26>,
  <13, 26, 27>,
  <13, 27, 14>,
  <15, 14, 27>,
  <15, 27, 28>,
  <15, 28, 16>,
  <17, 16, 28>,
  <17, 28, 29>,
  <17, 29, 18>,
  <19, 18, 29>,
  <19, 29, 30>,
  <19, 30, 31>,
  <20, 19, 31>,
  <20, 31, 32>,
  <20, 32, 21>,
  <22, 21, 32>,
  <22, 32, 33>,
  <22, 33, 23>,
  <24, 23, 33>,
  <24, 33, 34>,
  <24, 34, 25>,
  <12, 25, 34>,
  <12, 34, 35>,
  <12, 35, 26>,
  <27, 26, 35>,
  <27, 35, 36>,
  <27, 36, 28>,
  <29, 28, 36>,
  <29, 36, 37>,
  <29, 37, 30>,
  <31, 30, 37>,
  <31, 37, 33>,
  <31, 33, 32>,
  <34, 33, 37>,
  <34, 37, 36>,
  <34, 36, 35>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_pentagonal_icositetrahedron_verts[34];
 #local P1 = Catalan_pentagonal_icositetrahedron_verts[33];
 #local P2 = Catalan_pentagonal_icositetrahedron_verts[37];
 #local P3 = Catalan_pentagonal_icositetrahedron_verts[36];
 #local P4 = Catalan_pentagonal_icositetrahedron_verts[35];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_pentagonal_icositetrahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_pentagonal_icositetrahedron_obj }
#end
#end

#macro Catalan_pentagonal_icositetrahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_pentagonal_icositetrahedron_verts[0], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[1], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[2], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[3], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[4], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[5], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[6], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[7], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[8], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[9], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[10], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[11], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[12], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[13], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[14], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[15], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[16], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[17], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[18], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[19], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[20], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[21], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[22], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[23], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[24], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[25], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[26], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[27], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[28], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[29], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[30], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[31], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[32], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[33], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[34], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[35], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[36], RadVer }
  sphere { Catalan_pentagonal_icositetrahedron_verts[37], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_pentagonal_icositetrahedron_verts[4], Catalan_pentagonal_icositetrahedron_verts[0], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[0], Catalan_pentagonal_icositetrahedron_verts[1], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[1], Catalan_pentagonal_icositetrahedron_verts[2], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[2], Catalan_pentagonal_icositetrahedron_verts[3], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[3], Catalan_pentagonal_icositetrahedron_verts[4], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[4], Catalan_pentagonal_icositetrahedron_verts[5], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[5], Catalan_pentagonal_icositetrahedron_verts[6], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[6], Catalan_pentagonal_icositetrahedron_verts[7], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[7], Catalan_pentagonal_icositetrahedron_verts[0], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[7], Catalan_pentagonal_icositetrahedron_verts[8], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[8], Catalan_pentagonal_icositetrahedron_verts[9], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[9], Catalan_pentagonal_icositetrahedron_verts[1], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[9], Catalan_pentagonal_icositetrahedron_verts[10], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[10], Catalan_pentagonal_icositetrahedron_verts[11], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[11], Catalan_pentagonal_icositetrahedron_verts[2], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[11], Catalan_pentagonal_icositetrahedron_verts[12], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[12], Catalan_pentagonal_icositetrahedron_verts[13], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[13], Catalan_pentagonal_icositetrahedron_verts[3], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[13], Catalan_pentagonal_icositetrahedron_verts[14], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[14], Catalan_pentagonal_icositetrahedron_verts[15], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[15], Catalan_pentagonal_icositetrahedron_verts[4], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[15], Catalan_pentagonal_icositetrahedron_verts[16], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[16], Catalan_pentagonal_icositetrahedron_verts[17], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[17], Catalan_pentagonal_icositetrahedron_verts[5], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[17], Catalan_pentagonal_icositetrahedron_verts[18], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[18], Catalan_pentagonal_icositetrahedron_verts[19], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[19], Catalan_pentagonal_icositetrahedron_verts[6], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[19], Catalan_pentagonal_icositetrahedron_verts[20], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[20], Catalan_pentagonal_icositetrahedron_verts[8], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[20], Catalan_pentagonal_icositetrahedron_verts[21], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[21], Catalan_pentagonal_icositetrahedron_verts[22], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[22], Catalan_pentagonal_icositetrahedron_verts[9], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[22], Catalan_pentagonal_icositetrahedron_verts[23], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[23], Catalan_pentagonal_icositetrahedron_verts[24], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[24], Catalan_pentagonal_icositetrahedron_verts[10], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[24], Catalan_pentagonal_icositetrahedron_verts[25], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[25], Catalan_pentagonal_icositetrahedron_verts[12], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[12], Catalan_pentagonal_icositetrahedron_verts[26], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[26], Catalan_pentagonal_icositetrahedron_verts[27], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[27], Catalan_pentagonal_icositetrahedron_verts[14], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[27], Catalan_pentagonal_icositetrahedron_verts[28], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[28], Catalan_pentagonal_icositetrahedron_verts[16], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[28], Catalan_pentagonal_icositetrahedron_verts[29], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[29], Catalan_pentagonal_icositetrahedron_verts[18], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[29], Catalan_pentagonal_icositetrahedron_verts[30], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[30], Catalan_pentagonal_icositetrahedron_verts[31], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[31], Catalan_pentagonal_icositetrahedron_verts[19], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[31], Catalan_pentagonal_icositetrahedron_verts[32], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[32], Catalan_pentagonal_icositetrahedron_verts[21], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[32], Catalan_pentagonal_icositetrahedron_verts[33], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[33], Catalan_pentagonal_icositetrahedron_verts[23], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[33], Catalan_pentagonal_icositetrahedron_verts[34], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[34], Catalan_pentagonal_icositetrahedron_verts[25], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[34], Catalan_pentagonal_icositetrahedron_verts[35], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[35], Catalan_pentagonal_icositetrahedron_verts[26], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[35], Catalan_pentagonal_icositetrahedron_verts[36], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[36], Catalan_pentagonal_icositetrahedron_verts[28], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[36], Catalan_pentagonal_icositetrahedron_verts[37], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[37], Catalan_pentagonal_icositetrahedron_verts[30], RadEdg }
  cylinder { Catalan_pentagonal_icositetrahedron_verts[37], Catalan_pentagonal_icositetrahedron_verts[33], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_pentagonal_icositetrahedron_verts[34];
 #local P1 = Catalan_pentagonal_icositetrahedron_verts[33];
 #local P2 = Catalan_pentagonal_icositetrahedron_verts[37];
 #local P3 = Catalan_pentagonal_icositetrahedron_verts[36];
 #local P4 = Catalan_pentagonal_icositetrahedron_verts[35];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_rhombic_triacontahedron_verts = array[32]
{
<0.309017, 0.190983, 0.9510565>,
<-0.309017, 0.5, 0.9510565>,
<-0.309017, -0.190983, 0.9510565>,
<0.309017, -0.5, 0.9510565>,
<0.809017, -0.190983, 0.5877853>,
<0.809017, 0.5, 0.5877853>,
<0.190983, 0.809017, 0.5877853>,
<-0.809017, 0.190983, 0.5877853>,
<-0.809017, -0.5, 0.5877853>,
<-0.190983, -0.809017, 0.5877853>,
<1., -0.5, 0>,
<1., 0.190983, 0>,
<0.5, -0.809017, 0.3632713>,
<0, 1.118034, 0>,
<-0.5, 0.809017, 0.3632713>,
<0.618034, 0.809017, 0>,
<-1., 0.5, 0>,
<-1., -0.190983, 0>,
<0, -1.118034, 0>,
<-0.618034, -0.809017, 0>,
<0.809017, -0.190983, -0.5877853>,
<0.809017, 0.5, -0.5877853>,
<0.5, -0.809017, -0.3632713>,
<-0.5, 0.809017, -0.3632713>
<0.190983, 0.809017, -0.5877853>,
<-0.809017, 0.190983, -0.5877853>,
<-0.809017, -0.5, -0.5877853>,
<-0.190983, -0.809017, -0.5877853>,
<0.309017, -0.5, -0.9510565>,
<0.309017, 0.190983, -0.9510565>,
<-0.309017, 0.5, -0.9510565>,
<-0.309017, -0.190983, -0.9510565>,
}
#local P0 = Catalan_rhombic_triacontahedron_verts[0];
#local P1 = Catalan_rhombic_triacontahedron_verts[4];
#local P2 = Catalan_rhombic_triacontahedron_verts[2];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 32)
 #declare Catalan_rhombic_triacontahedron_verts[Num] = vtransform(Catalan_rhombic_triacontahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_rhombic_triacontahedron_faces(Tex4, OnPlane)
#local Catalan_rhombic_triacontahedron_obj = mesh2 {
 vertex_vectors {
  32,
  Catalan_rhombic_triacontahedron_verts[0],
  Catalan_rhombic_triacontahedron_verts[1],
  Catalan_rhombic_triacontahedron_verts[2],
  Catalan_rhombic_triacontahedron_verts[3],
  Catalan_rhombic_triacontahedron_verts[4],
  Catalan_rhombic_triacontahedron_verts[5],
  Catalan_rhombic_triacontahedron_verts[6],
  Catalan_rhombic_triacontahedron_verts[7],
  Catalan_rhombic_triacontahedron_verts[8],
  Catalan_rhombic_triacontahedron_verts[9],
  Catalan_rhombic_triacontahedron_verts[10],
  Catalan_rhombic_triacontahedron_verts[11],
  Catalan_rhombic_triacontahedron_verts[12],
  Catalan_rhombic_triacontahedron_verts[13],
  Catalan_rhombic_triacontahedron_verts[14],
  Catalan_rhombic_triacontahedron_verts[15],
  Catalan_rhombic_triacontahedron_verts[16],
  Catalan_rhombic_triacontahedron_verts[17],
  Catalan_rhombic_triacontahedron_verts[18],
  Catalan_rhombic_triacontahedron_verts[19],
  Catalan_rhombic_triacontahedron_verts[20],
  Catalan_rhombic_triacontahedron_verts[21],
  Catalan_rhombic_triacontahedron_verts[22],
  Catalan_rhombic_triacontahedron_verts[23],
  Catalan_rhombic_triacontahedron_verts[24],
  Catalan_rhombic_triacontahedron_verts[25],
  Catalan_rhombic_triacontahedron_verts[26],
  Catalan_rhombic_triacontahedron_verts[27],
  Catalan_rhombic_triacontahedron_verts[28],
  Catalan_rhombic_triacontahedron_verts[29],
  Catalan_rhombic_triacontahedron_verts[30],
  Catalan_rhombic_triacontahedron_verts[31]
 }
 texture_list {
  1,
  texture { Tex4 }
 }
 face_indices {
  60,
  <3, 0, 1>, 0,
  <3, 1, 2>, 0,
  <3, 4, 5>, 0,
  <3, 5, 0>, 0,
  <0, 5, 6>, 0,
  <0, 6, 1>, 0,
  <1, 7, 8>, 0,
  <1, 8, 2>, 0,
  <2, 8, 9>, 0,
  <2, 9, 3>, 0,
  <5, 4, 10>, 0,
  <5, 10, 11>, 0,
  <4, 3, 12>, 0,
  <4, 12, 10>, 0,
  <1, 6, 13>, 0,
  <1, 13, 14>, 0,
  <6, 5, 15>, 0,
  <6, 15, 13>, 0,
  <8, 7, 16>, 0,
  <8, 16, 17>, 0,
  <7, 1, 14>, 0,
  <7, 14, 16>, 0,
  <3, 9, 18>, 0,
  <3, 18, 12>, 0,
  <9, 8, 19>, 0,
  <9, 19, 18>, 0,
  <10, 20, 21>, 0,
  <10, 21, 11>, 0,
  <11, 21, 15>, 0,
  <11, 15, 5>, 0,
  <12, 18, 22>, 0,
  <12, 22, 10>, 0,
  <13, 23, 16>, 0,
  <13, 16, 14>, 0,
  <15, 21, 24>, 0,
  <15, 24, 13>, 0,
  <16, 25, 26>, 0,
  <16, 26, 17>, 0,
  <17, 26, 19>, 0,
  <17, 19, 8>, 0,
  <19, 26, 27>, 0,
  <19, 27, 18>, 0,
  <21, 20, 28>, 0,
  <21, 28, 29>, 0,
  <20, 10, 22>, 0,
  <20, 22, 28>, 0,
  <22, 18, 27>, 0,
  <22, 27, 28>, 0,
  <16, 23, 30>, 0,
  <16, 30, 25>, 0,
  <23, 13, 24>, 0,
  <23, 24, 30>, 0,
  <24, 21, 29>, 0,
  <24, 29, 30>, 0,
  <26, 25, 30>, 0,
  <26, 30, 31>, 0,
  <27, 26, 31>, 0,
  <27, 31, 28>, 0,
  <28, 31, 30>, 0,
  <28, 30, 29>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_rhombic_triacontahedron_verts[28];
 #local P1 = Catalan_rhombic_triacontahedron_verts[31];
 #local P2 = Catalan_rhombic_triacontahedron_verts[30];
 #local P3 = Catalan_rhombic_triacontahedron_verts[29];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_rhombic_triacontahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_rhombic_triacontahedron_obj }
#end
#end

#macro Catalan_rhombic_triacontahedron_faces2(OnPlane)
#local Catalan_rhombic_triacontahedron_obj = mesh2 {
 vertex_vectors {
  32,
  Catalan_rhombic_triacontahedron_verts[0],
  Catalan_rhombic_triacontahedron_verts[1],
  Catalan_rhombic_triacontahedron_verts[2],
  Catalan_rhombic_triacontahedron_verts[3],
  Catalan_rhombic_triacontahedron_verts[4],
  Catalan_rhombic_triacontahedron_verts[5],
  Catalan_rhombic_triacontahedron_verts[6],
  Catalan_rhombic_triacontahedron_verts[7],
  Catalan_rhombic_triacontahedron_verts[8],
  Catalan_rhombic_triacontahedron_verts[9],
  Catalan_rhombic_triacontahedron_verts[10],
  Catalan_rhombic_triacontahedron_verts[11],
  Catalan_rhombic_triacontahedron_verts[12],
  Catalan_rhombic_triacontahedron_verts[13],
  Catalan_rhombic_triacontahedron_verts[14],
  Catalan_rhombic_triacontahedron_verts[15],
  Catalan_rhombic_triacontahedron_verts[16],
  Catalan_rhombic_triacontahedron_verts[17],
  Catalan_rhombic_triacontahedron_verts[18],
  Catalan_rhombic_triacontahedron_verts[19],
  Catalan_rhombic_triacontahedron_verts[20],
  Catalan_rhombic_triacontahedron_verts[21],
  Catalan_rhombic_triacontahedron_verts[22],
  Catalan_rhombic_triacontahedron_verts[23],
  Catalan_rhombic_triacontahedron_verts[24],
  Catalan_rhombic_triacontahedron_verts[25],
  Catalan_rhombic_triacontahedron_verts[26],
  Catalan_rhombic_triacontahedron_verts[27],
  Catalan_rhombic_triacontahedron_verts[28],
  Catalan_rhombic_triacontahedron_verts[29],
  Catalan_rhombic_triacontahedron_verts[30],
  Catalan_rhombic_triacontahedron_verts[31]
 }
 face_indices {
  60,
  <3, 0, 1>,
  <3, 1, 2>,
  <3, 4, 5>,
  <3, 5, 0>,
  <0, 5, 6>,
  <0, 6, 1>,
  <1, 7, 8>,
  <1, 8, 2>,
  <2, 8, 9>,
  <2, 9, 3>,
  <5, 4, 10>,
  <5, 10, 11>,
  <4, 3, 12>,
  <4, 12, 10>,
  <1, 6, 13>,
  <1, 13, 14>,
  <6, 5, 15>,
  <6, 15, 13>,
  <8, 7, 16>,
  <8, 16, 17>,
  <7, 1, 14>,
  <7, 14, 16>,
  <3, 9, 18>,
  <3, 18, 12>,
  <9, 8, 19>,
  <9, 19, 18>,
  <10, 20, 21>,
  <10, 21, 11>,
  <11, 21, 15>,
  <11, 15, 5>,
  <12, 18, 22>,
  <12, 22, 10>,
  <13, 23, 16>,
  <13, 16, 14>,
  <15, 21, 24>,
  <15, 24, 13>,
  <16, 25, 26>,
  <16, 26, 17>,
  <17, 26, 19>,
  <17, 19, 8>,
  <19, 26, 27>,
  <19, 27, 18>,
  <21, 20, 28>,
  <21, 28, 29>,
  <20, 10, 22>,
  <20, 22, 28>,
  <22, 18, 27>,
  <22, 27, 28>,
  <16, 23, 30>,
  <16, 30, 25>,
  <23, 13, 24>,
  <23, 24, 30>,
  <24, 21, 29>,
  <24, 29, 30>,
  <26, 25, 30>,
  <26, 30, 31>,
  <27, 26, 31>,
  <27, 31, 28>,
  <28, 31, 30>,
  <28, 30, 29>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_rhombic_triacontahedron_verts[28];
 #local P1 = Catalan_rhombic_triacontahedron_verts[31];
 #local P2 = Catalan_rhombic_triacontahedron_verts[30];
 #local P3 = Catalan_rhombic_triacontahedron_verts[29];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_rhombic_triacontahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_rhombic_triacontahedron_obj }
#end
#end

#macro Catalan_rhombic_triacontahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_rhombic_triacontahedron_verts[0], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[1], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[2], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[3], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[4], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[5], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[6], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[7], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[8], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[9], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[10], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[11], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[12], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[13], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[14], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[15], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[16], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[17], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[18], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[19], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[20], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[21], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[22], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[23], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[24], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[25], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[26], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[27], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[28], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[29], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[30], RadVer }
  sphere { Catalan_rhombic_triacontahedron_verts[31], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_rhombic_triacontahedron_verts[3], Catalan_rhombic_triacontahedron_verts[0], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[0], Catalan_rhombic_triacontahedron_verts[1], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[1], Catalan_rhombic_triacontahedron_verts[2], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[2], Catalan_rhombic_triacontahedron_verts[3], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[3], Catalan_rhombic_triacontahedron_verts[4], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[4], Catalan_rhombic_triacontahedron_verts[5], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[5], Catalan_rhombic_triacontahedron_verts[0], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[5], Catalan_rhombic_triacontahedron_verts[6], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[6], Catalan_rhombic_triacontahedron_verts[1], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[1], Catalan_rhombic_triacontahedron_verts[7], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[7], Catalan_rhombic_triacontahedron_verts[8], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[8], Catalan_rhombic_triacontahedron_verts[2], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[8], Catalan_rhombic_triacontahedron_verts[9], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[9], Catalan_rhombic_triacontahedron_verts[3], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[4], Catalan_rhombic_triacontahedron_verts[10], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[10], Catalan_rhombic_triacontahedron_verts[11], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[11], Catalan_rhombic_triacontahedron_verts[5], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[3], Catalan_rhombic_triacontahedron_verts[12], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[12], Catalan_rhombic_triacontahedron_verts[10], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[6], Catalan_rhombic_triacontahedron_verts[13], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[13], Catalan_rhombic_triacontahedron_verts[14], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[14], Catalan_rhombic_triacontahedron_verts[1], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[5], Catalan_rhombic_triacontahedron_verts[15], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[15], Catalan_rhombic_triacontahedron_verts[13], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[7], Catalan_rhombic_triacontahedron_verts[16], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[16], Catalan_rhombic_triacontahedron_verts[17], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[17], Catalan_rhombic_triacontahedron_verts[8], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[14], Catalan_rhombic_triacontahedron_verts[16], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[9], Catalan_rhombic_triacontahedron_verts[18], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[18], Catalan_rhombic_triacontahedron_verts[12], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[8], Catalan_rhombic_triacontahedron_verts[19], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[19], Catalan_rhombic_triacontahedron_verts[18], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[10], Catalan_rhombic_triacontahedron_verts[20], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[20], Catalan_rhombic_triacontahedron_verts[21], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[21], Catalan_rhombic_triacontahedron_verts[11], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[21], Catalan_rhombic_triacontahedron_verts[15], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[18], Catalan_rhombic_triacontahedron_verts[22], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[22], Catalan_rhombic_triacontahedron_verts[10], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[13], Catalan_rhombic_triacontahedron_verts[23], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[23], Catalan_rhombic_triacontahedron_verts[16], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[21], Catalan_rhombic_triacontahedron_verts[24], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[24], Catalan_rhombic_triacontahedron_verts[13], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[16], Catalan_rhombic_triacontahedron_verts[25], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[25], Catalan_rhombic_triacontahedron_verts[26], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[26], Catalan_rhombic_triacontahedron_verts[17], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[26], Catalan_rhombic_triacontahedron_verts[19], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[26], Catalan_rhombic_triacontahedron_verts[27], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[27], Catalan_rhombic_triacontahedron_verts[18], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[20], Catalan_rhombic_triacontahedron_verts[28], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[28], Catalan_rhombic_triacontahedron_verts[29], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[29], Catalan_rhombic_triacontahedron_verts[21], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[22], Catalan_rhombic_triacontahedron_verts[28], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[27], Catalan_rhombic_triacontahedron_verts[28], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[23], Catalan_rhombic_triacontahedron_verts[30], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[30], Catalan_rhombic_triacontahedron_verts[25], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[24], Catalan_rhombic_triacontahedron_verts[30], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[29], Catalan_rhombic_triacontahedron_verts[30], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[30], Catalan_rhombic_triacontahedron_verts[31], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[31], Catalan_rhombic_triacontahedron_verts[26], RadEdg }
  cylinder { Catalan_rhombic_triacontahedron_verts[31], Catalan_rhombic_triacontahedron_verts[28], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_rhombic_triacontahedron_verts[28];
 #local P1 = Catalan_rhombic_triacontahedron_verts[31];
 #local P2 = Catalan_rhombic_triacontahedron_verts[30];
 #local P3 = Catalan_rhombic_triacontahedron_verts[29];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_triakis_icosahedron_verts = array[32]
{
<0.1683814, 0.618034, 0.9857219>,
<-0.4586047, -0.4472136, 0.9857219>,
<0.1683814, -0.09910636, 0.9857219>,
<0.7598146, -0.4472136, 0.7775911>,
<-0.4408282, 0.2594638, 0.8649688>,
<0.7029615, 0.2594638, 0.6695862>,
<-0.9391824, 0.5527864, 0.4408282>,
<0.114379, -0.7405362, 0.6695862>,
<1.032261, 0.5527864, 0.1040654>,
<-0.8713429, -0.1603575, 0.4742036>,
<-0.2827604, 0.8396425, 0.4742036>,
<0.0177765, -1.17082, 0.1040654>,
<0.9793478, -0.1603575, 0.1580679>,
<0.4241406, 0.8396425, 0.3534505>,
<-1.032261, -0.5527864, -0.1040654>,
<-0.0177765, 1.17082, -0.1040654>,
<-0.528206, -0.7783914, 0.3534505>,
<0.6155838, -0.7783914, 0.1580679>,
<0.9391824, -0.5527864, -0.4408282>,
<-0.9793478, 0.1603575, -0.1580679>,
<-0.6155838, 0.7783914, -0.1580679>,
<0.8713429, 0.1603575, -0.4742036>,
<0.528206, 0.7783914, -0.3534505>,
<-0.7598146, 0.4472136, -0.7775911>
<-0.4241406, -0.8396425, -0.3534505>,
<0.2827604, -0.8396425, -0.4742036>,
<0.4586047, 0.4472136, -0.9857219>,
<-0.7029615, -0.2594638, -0.6695862>,
<-0.114379, 0.7405362, -0.6695862>,
<-0.1683814, -0.618034, -0.9857219>,
<0.4408282, -0.2594638, -0.8649688>,
<-0.1683814, 0.09910636, -0.9857219>,
}
#local P0 = Catalan_triakis_icosahedron_verts[0];
#local P1 = Catalan_triakis_icosahedron_verts[1];
#local P2 = Catalan_triakis_icosahedron_verts[8];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 32)
 #declare Catalan_triakis_icosahedron_verts[Num] = vtransform(Catalan_triakis_icosahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_triakis_icosahedron_faces(Tex3, OnPlane)
#local Catalan_triakis_icosahedron_obj = mesh2 {
 vertex_vectors {
  32,
  Catalan_triakis_icosahedron_verts[0],
  Catalan_triakis_icosahedron_verts[1],
  Catalan_triakis_icosahedron_verts[2],
  Catalan_triakis_icosahedron_verts[3],
  Catalan_triakis_icosahedron_verts[4],
  Catalan_triakis_icosahedron_verts[5],
  Catalan_triakis_icosahedron_verts[6],
  Catalan_triakis_icosahedron_verts[7],
  Catalan_triakis_icosahedron_verts[8],
  Catalan_triakis_icosahedron_verts[9],
  Catalan_triakis_icosahedron_verts[10],
  Catalan_triakis_icosahedron_verts[11],
  Catalan_triakis_icosahedron_verts[12],
  Catalan_triakis_icosahedron_verts[13],
  Catalan_triakis_icosahedron_verts[14],
  Catalan_triakis_icosahedron_verts[15],
  Catalan_triakis_icosahedron_verts[16],
  Catalan_triakis_icosahedron_verts[17],
  Catalan_triakis_icosahedron_verts[18],
  Catalan_triakis_icosahedron_verts[19],
  Catalan_triakis_icosahedron_verts[20],
  Catalan_triakis_icosahedron_verts[21],
  Catalan_triakis_icosahedron_verts[22],
  Catalan_triakis_icosahedron_verts[23],
  Catalan_triakis_icosahedron_verts[24],
  Catalan_triakis_icosahedron_verts[25],
  Catalan_triakis_icosahedron_verts[26],
  Catalan_triakis_icosahedron_verts[27],
  Catalan_triakis_icosahedron_verts[28],
  Catalan_triakis_icosahedron_verts[29],
  Catalan_triakis_icosahedron_verts[30],
  Catalan_triakis_icosahedron_verts[31]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  60,
  <2, 0, 1>, 0,
  <2, 3, 0>, 0,
  <0, 4, 1>, 0,
  <1, 3, 2>, 0,
  <0, 3, 5>, 0,
  <1, 4, 6>, 0,
  <4, 0, 6>, 0,
  <3, 1, 7>, 0,
  <3, 8, 5>, 0,
  <5, 8, 0>, 0,
  <6, 9, 1>, 0,
  <0, 10, 6>, 0,
  <1, 11, 7>, 0,
  <7, 11, 3>, 0,
  <8, 3, 12>, 0,
  <0, 8, 13>, 0,
  <1, 9, 14>, 0,
  <9, 6, 14>, 0,
  <6, 10, 15>, 0,
  <10, 0, 15>, 0,
  <11, 1, 16>, 0,
  <3, 11, 17>, 0,
  <3, 18, 12>, 0,
  <12, 18, 8>, 0,
  <8, 15, 13>, 0,
  <13, 15, 0>, 0,
  <14, 16, 1>, 0,
  <6, 19, 14>, 0,
  <15, 20, 6>, 0,
  <16, 14, 11>, 0,
  <11, 18, 17>, 0,
  <17, 18, 3>, 0,
  <8, 18, 21>, 0,
  <15, 8, 22>, 0,
  <14, 19, 23>, 0,
  <19, 6, 23>, 0,
  <6, 20, 23>, 0,
  <20, 15, 23>, 0,
  <11, 14, 24>, 0,
  <18, 11, 25>, 0,
  <18, 26, 21>, 0,
  <21, 26, 8>, 0,
  <8, 26, 22>, 0,
  <22, 26, 15>, 0,
  <23, 27, 14>, 0,
  <15, 28, 23>, 0,
  <14, 29, 24>, 0,
  <24, 29, 11>, 0,
  <11, 29, 25>, 0,
  <25, 29, 18>, 0,
  <26, 18, 30>, 0,
  <15, 26, 28>, 0,
  <14, 27, 29>, 0,
  <27, 23, 29>, 0,
  <23, 28, 26>, 0,
  <18, 29, 30>, 0,
  <30, 29, 26>, 0,
  <23, 31, 29>, 0,
  <26, 31, 23>, 0,
  <26, 29, 31>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_triakis_icosahedron_verts[26];
 #local P1 = Catalan_triakis_icosahedron_verts[29];
 #local P2 = Catalan_triakis_icosahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_triakis_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_triakis_icosahedron_obj }
#end
#end

#macro Catalan_triakis_icosahedron_faces2(OnPlane)
#local Catalan_triakis_icosahedron_obj = mesh2 {
 vertex_vectors {
  32,
  Catalan_triakis_icosahedron_verts[0],
  Catalan_triakis_icosahedron_verts[1],
  Catalan_triakis_icosahedron_verts[2],
  Catalan_triakis_icosahedron_verts[3],
  Catalan_triakis_icosahedron_verts[4],
  Catalan_triakis_icosahedron_verts[5],
  Catalan_triakis_icosahedron_verts[6],
  Catalan_triakis_icosahedron_verts[7],
  Catalan_triakis_icosahedron_verts[8],
  Catalan_triakis_icosahedron_verts[9],
  Catalan_triakis_icosahedron_verts[10],
  Catalan_triakis_icosahedron_verts[11],
  Catalan_triakis_icosahedron_verts[12],
  Catalan_triakis_icosahedron_verts[13],
  Catalan_triakis_icosahedron_verts[14],
  Catalan_triakis_icosahedron_verts[15],
  Catalan_triakis_icosahedron_verts[16],
  Catalan_triakis_icosahedron_verts[17],
  Catalan_triakis_icosahedron_verts[18],
  Catalan_triakis_icosahedron_verts[19],
  Catalan_triakis_icosahedron_verts[20],
  Catalan_triakis_icosahedron_verts[21],
  Catalan_triakis_icosahedron_verts[22],
  Catalan_triakis_icosahedron_verts[23],
  Catalan_triakis_icosahedron_verts[24],
  Catalan_triakis_icosahedron_verts[25],
  Catalan_triakis_icosahedron_verts[26],
  Catalan_triakis_icosahedron_verts[27],
  Catalan_triakis_icosahedron_verts[28],
  Catalan_triakis_icosahedron_verts[29],
  Catalan_triakis_icosahedron_verts[30],
  Catalan_triakis_icosahedron_verts[31]
 }
 face_indices {
  60,
  <2, 0, 1>,
  <2, 3, 0>,
  <0, 4, 1>,
  <1, 3, 2>,
  <0, 3, 5>,
  <1, 4, 6>,
  <4, 0, 6>,
  <3, 1, 7>,
  <3, 8, 5>,
  <5, 8, 0>,
  <6, 9, 1>,
  <0, 10, 6>,
  <1, 11, 7>,
  <7, 11, 3>,
  <8, 3, 12>,
  <0, 8, 13>,
  <1, 9, 14>,
  <9, 6, 14>,
  <6, 10, 15>,
  <10, 0, 15>,
  <11, 1, 16>,
  <3, 11, 17>,
  <3, 18, 12>,
  <12, 18, 8>,
  <8, 15, 13>,
  <13, 15, 0>,
  <14, 16, 1>,
  <6, 19, 14>,
  <15, 20, 6>,
  <16, 14, 11>,
  <11, 18, 17>,
  <17, 18, 3>,
  <8, 18, 21>,
  <15, 8, 22>,
  <14, 19, 23>,
  <19, 6, 23>,
  <6, 20, 23>,
  <20, 15, 23>,
  <11, 14, 24>,
  <18, 11, 25>,
  <18, 26, 21>,
  <21, 26, 8>,
  <8, 26, 22>,
  <22, 26, 15>,
  <23, 27, 14>,
  <15, 28, 23>,
  <14, 29, 24>,
  <24, 29, 11>,
  <11, 29, 25>,
  <25, 29, 18>,
  <26, 18, 30>,
  <15, 26, 28>,
  <14, 27, 29>,
  <27, 23, 29>,
  <23, 28, 26>,
  <18, 29, 30>,
  <30, 29, 26>,
  <23, 31, 29>,
  <26, 31, 23>,
  <26, 29, 31>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_triakis_icosahedron_verts[26];
 #local P1 = Catalan_triakis_icosahedron_verts[29];
 #local P2 = Catalan_triakis_icosahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_triakis_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_triakis_icosahedron_obj }
#end
#end

#macro Catalan_triakis_icosahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_triakis_icosahedron_verts[0], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[1], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[2], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[3], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[4], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[5], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[6], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[7], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[8], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[9], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[10], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[11], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[12], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[13], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[14], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[15], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[16], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[17], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[18], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[19], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[20], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[21], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[22], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[23], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[24], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[25], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[26], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[27], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[28], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[29], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[30], RadVer }
  sphere { Catalan_triakis_icosahedron_verts[31], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_triakis_icosahedron_verts[2], Catalan_triakis_icosahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[0], Catalan_triakis_icosahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[1], Catalan_triakis_icosahedron_verts[2], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[2], Catalan_triakis_icosahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[3], Catalan_triakis_icosahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[0], Catalan_triakis_icosahedron_verts[4], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[4], Catalan_triakis_icosahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[1], Catalan_triakis_icosahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[3], Catalan_triakis_icosahedron_verts[5], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[5], Catalan_triakis_icosahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[4], Catalan_triakis_icosahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[6], Catalan_triakis_icosahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[0], Catalan_triakis_icosahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[1], Catalan_triakis_icosahedron_verts[7], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[7], Catalan_triakis_icosahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[3], Catalan_triakis_icosahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[8], Catalan_triakis_icosahedron_verts[5], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[8], Catalan_triakis_icosahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[6], Catalan_triakis_icosahedron_verts[9], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[9], Catalan_triakis_icosahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[0], Catalan_triakis_icosahedron_verts[10], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[10], Catalan_triakis_icosahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[1], Catalan_triakis_icosahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[11], Catalan_triakis_icosahedron_verts[7], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[11], Catalan_triakis_icosahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[3], Catalan_triakis_icosahedron_verts[12], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[12], Catalan_triakis_icosahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[8], Catalan_triakis_icosahedron_verts[13], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[13], Catalan_triakis_icosahedron_verts[0], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[9], Catalan_triakis_icosahedron_verts[14], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[14], Catalan_triakis_icosahedron_verts[1], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[6], Catalan_triakis_icosahedron_verts[14], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[10], Catalan_triakis_icosahedron_verts[15], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[15], Catalan_triakis_icosahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[0], Catalan_triakis_icosahedron_verts[15], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[1], Catalan_triakis_icosahedron_verts[16], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[16], Catalan_triakis_icosahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[11], Catalan_triakis_icosahedron_verts[17], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[17], Catalan_triakis_icosahedron_verts[3], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[3], Catalan_triakis_icosahedron_verts[18], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[18], Catalan_triakis_icosahedron_verts[12], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[18], Catalan_triakis_icosahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[8], Catalan_triakis_icosahedron_verts[15], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[15], Catalan_triakis_icosahedron_verts[13], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[14], Catalan_triakis_icosahedron_verts[16], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[6], Catalan_triakis_icosahedron_verts[19], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[19], Catalan_triakis_icosahedron_verts[14], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[15], Catalan_triakis_icosahedron_verts[20], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[20], Catalan_triakis_icosahedron_verts[6], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[14], Catalan_triakis_icosahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[11], Catalan_triakis_icosahedron_verts[18], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[18], Catalan_triakis_icosahedron_verts[17], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[18], Catalan_triakis_icosahedron_verts[21], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[21], Catalan_triakis_icosahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[8], Catalan_triakis_icosahedron_verts[22], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[22], Catalan_triakis_icosahedron_verts[15], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[19], Catalan_triakis_icosahedron_verts[23], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[23], Catalan_triakis_icosahedron_verts[14], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[6], Catalan_triakis_icosahedron_verts[23], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[20], Catalan_triakis_icosahedron_verts[23], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[15], Catalan_triakis_icosahedron_verts[23], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[14], Catalan_triakis_icosahedron_verts[24], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[24], Catalan_triakis_icosahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[11], Catalan_triakis_icosahedron_verts[25], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[25], Catalan_triakis_icosahedron_verts[18], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[18], Catalan_triakis_icosahedron_verts[26], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[26], Catalan_triakis_icosahedron_verts[21], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[26], Catalan_triakis_icosahedron_verts[8], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[26], Catalan_triakis_icosahedron_verts[22], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[26], Catalan_triakis_icosahedron_verts[15], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[23], Catalan_triakis_icosahedron_verts[27], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[27], Catalan_triakis_icosahedron_verts[14], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[15], Catalan_triakis_icosahedron_verts[28], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[28], Catalan_triakis_icosahedron_verts[23], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[14], Catalan_triakis_icosahedron_verts[29], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[29], Catalan_triakis_icosahedron_verts[24], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[29], Catalan_triakis_icosahedron_verts[11], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[29], Catalan_triakis_icosahedron_verts[25], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[29], Catalan_triakis_icosahedron_verts[18], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[18], Catalan_triakis_icosahedron_verts[30], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[30], Catalan_triakis_icosahedron_verts[26], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[26], Catalan_triakis_icosahedron_verts[28], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[27], Catalan_triakis_icosahedron_verts[29], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[23], Catalan_triakis_icosahedron_verts[29], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[26], Catalan_triakis_icosahedron_verts[23], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[29], Catalan_triakis_icosahedron_verts[30], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[29], Catalan_triakis_icosahedron_verts[26], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[23], Catalan_triakis_icosahedron_verts[31], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[31], Catalan_triakis_icosahedron_verts[29], RadEdg }
  cylinder { Catalan_triakis_icosahedron_verts[26], Catalan_triakis_icosahedron_verts[31], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_triakis_icosahedron_verts[26];
 #local P1 = Catalan_triakis_icosahedron_verts[29];
 #local P2 = Catalan_triakis_icosahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_pentakis_dodecahedron_verts = array[32]
{
<0.2017741, 0.381966, 0.9794321>,
<-0.4292385, -0.04863268, 0.9794321>,
<0.2017741, -0.295686, 0.9794321>,
<0.7814061, -0.04863268, 0.7300256>,
<-0.4035482, 0.591372, 0.758194>,
<-0.2395937, -0.745356, 0.7300256>,
<0.6703638, 0.591372, 0.536956>,
<0.5086258, -0.745356, 0.5758839>,
<-0.9219869, 0.254644, 0.4806191>,
<0.09901297, 0.9513673, 0.4806191>,
<-0.7950671, -0.408628, 0.536956>,
<1.036877, 0.254644, 0.07707085>,
<0.9425591, -0.408628, 0.1789853>,
<-0.5955095, 0.872678, 0.1723357>,
<0.03687301, -1.026662, 0.1789853>,
<-0.6151351, -0.872678, 0.07707085>,
<0.6151351, 0.872678, -0.07707085>,
<0.5955095, -0.872678, -0.1723357>,
<-0.9425591, 0.408628, -0.1789853>,
<-1.036877, -0.254644, -0.07707085>,
<-0.03687301, 1.026662, -0.1789853>,
<0.7950671, 0.408628, -0.536956>,
<0.9219869, -0.254644, -0.4806191>,
<-0.5086258, 0.745356, -0.5758839>
<-0.09901297, -0.9513673, -0.4806191>,
<-0.6703638, -0.591372, -0.536956>,
<0.2395937, 0.745356, -0.7300256>,
<0.4035482, -0.591372, -0.758194>,
<-0.7814061, 0.04863268, -0.7300256>,
<0.4292385, 0.04863268, -0.9794321>,
<-0.2017741, 0.295686, -0.9794321>,
<-0.2017741, -0.381966, -0.9794321>,
}
#local P0 = Catalan_pentakis_dodecahedron_verts[0];
#local P1 = Catalan_pentakis_dodecahedron_verts[1];
#local P2 = Catalan_pentakis_dodecahedron_verts[3];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 32)
 #declare Catalan_pentakis_dodecahedron_verts[Num] = vtransform(Catalan_pentakis_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_pentakis_dodecahedron_faces(Tex3, OnPlane)
#local Catalan_pentakis_dodecahedron_obj = mesh2 {
 vertex_vectors {
  32,
  Catalan_pentakis_dodecahedron_verts[0],
  Catalan_pentakis_dodecahedron_verts[1],
  Catalan_pentakis_dodecahedron_verts[2],
  Catalan_pentakis_dodecahedron_verts[3],
  Catalan_pentakis_dodecahedron_verts[4],
  Catalan_pentakis_dodecahedron_verts[5],
  Catalan_pentakis_dodecahedron_verts[6],
  Catalan_pentakis_dodecahedron_verts[7],
  Catalan_pentakis_dodecahedron_verts[8],
  Catalan_pentakis_dodecahedron_verts[9],
  Catalan_pentakis_dodecahedron_verts[10],
  Catalan_pentakis_dodecahedron_verts[11],
  Catalan_pentakis_dodecahedron_verts[12],
  Catalan_pentakis_dodecahedron_verts[13],
  Catalan_pentakis_dodecahedron_verts[14],
  Catalan_pentakis_dodecahedron_verts[15],
  Catalan_pentakis_dodecahedron_verts[16],
  Catalan_pentakis_dodecahedron_verts[17],
  Catalan_pentakis_dodecahedron_verts[18],
  Catalan_pentakis_dodecahedron_verts[19],
  Catalan_pentakis_dodecahedron_verts[20],
  Catalan_pentakis_dodecahedron_verts[21],
  Catalan_pentakis_dodecahedron_verts[22],
  Catalan_pentakis_dodecahedron_verts[23],
  Catalan_pentakis_dodecahedron_verts[24],
  Catalan_pentakis_dodecahedron_verts[25],
  Catalan_pentakis_dodecahedron_verts[26],
  Catalan_pentakis_dodecahedron_verts[27],
  Catalan_pentakis_dodecahedron_verts[28],
  Catalan_pentakis_dodecahedron_verts[29],
  Catalan_pentakis_dodecahedron_verts[30],
  Catalan_pentakis_dodecahedron_verts[31]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  60,
  <2, 0, 1>, 0,
  <2, 3, 0>, 0,
  <0, 4, 1>, 0,
  <1, 5, 2>, 0,
  <0, 3, 6>, 0,
  <3, 2, 7>, 0,
  <1, 4, 8>, 0,
  <4, 0, 9>, 0,
  <2, 5, 7>, 0,
  <5, 1, 10>, 0,
  <3, 11, 6>, 0,
  <6, 9, 0>, 0,
  <7, 12, 3>, 0,
  <4, 13, 8>, 0,
  <8, 10, 1>, 0,
  <9, 13, 4>, 0,
  <5, 14, 7>, 0,
  <10, 15, 5>, 0,
  <6, 11, 16>, 0,
  <11, 3, 12>, 0,
  <9, 6, 16>, 0,
  <12, 7, 17>, 0,
  <8, 13, 18>, 0,
  <10, 8, 19>, 0,
  <13, 9, 20>, 0,
  <7, 14, 17>, 0,
  <14, 5, 15>, 0,
  <15, 10, 19>, 0,
  <11, 21, 16>, 0,
  <12, 22, 11>, 0,
  <16, 20, 9>, 0,
  <17, 22, 12>, 0,
  <13, 23, 18>, 0,
  <18, 19, 8>, 0,
  <20, 23, 13>, 0,
  <14, 24, 17>, 0,
  <15, 24, 14>, 0,
  <19, 25, 15>, 0,
  <16, 21, 26>, 0,
  <21, 11, 22>, 0,
  <20, 16, 26>, 0,
  <22, 17, 27>, 0,
  <18, 23, 28>, 0,
  <19, 18, 28>, 0,
  <23, 20, 26>, 0,
  <17, 24, 27>, 0,
  <24, 15, 25>, 0,
  <25, 19, 28>, 0,
  <21, 29, 26>, 0,
  <22, 29, 21>, 0,
  <27, 29, 22>, 0,
  <23, 30, 28>, 0,
  <26, 30, 23>, 0,
  <24, 31, 27>, 0,
  <25, 31, 24>, 0,
  <28, 31, 25>, 0,
  <26, 29, 30>, 0,
  <29, 27, 31>, 0,
  <28, 30, 31>, 0,
  <29, 31, 30>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_pentakis_dodecahedron_verts[29];
 #local P1 = Catalan_pentakis_dodecahedron_verts[31];
 #local P2 = Catalan_pentakis_dodecahedron_verts[30];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_pentakis_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_pentakis_dodecahedron_obj }
#end
#end

#macro Catalan_pentakis_dodecahedron_faces2(OnPlane)
#local Catalan_pentakis_dodecahedron_obj = mesh2 {
 vertex_vectors {
  32,
  Catalan_pentakis_dodecahedron_verts[0],
  Catalan_pentakis_dodecahedron_verts[1],
  Catalan_pentakis_dodecahedron_verts[2],
  Catalan_pentakis_dodecahedron_verts[3],
  Catalan_pentakis_dodecahedron_verts[4],
  Catalan_pentakis_dodecahedron_verts[5],
  Catalan_pentakis_dodecahedron_verts[6],
  Catalan_pentakis_dodecahedron_verts[7],
  Catalan_pentakis_dodecahedron_verts[8],
  Catalan_pentakis_dodecahedron_verts[9],
  Catalan_pentakis_dodecahedron_verts[10],
  Catalan_pentakis_dodecahedron_verts[11],
  Catalan_pentakis_dodecahedron_verts[12],
  Catalan_pentakis_dodecahedron_verts[13],
  Catalan_pentakis_dodecahedron_verts[14],
  Catalan_pentakis_dodecahedron_verts[15],
  Catalan_pentakis_dodecahedron_verts[16],
  Catalan_pentakis_dodecahedron_verts[17],
  Catalan_pentakis_dodecahedron_verts[18],
  Catalan_pentakis_dodecahedron_verts[19],
  Catalan_pentakis_dodecahedron_verts[20],
  Catalan_pentakis_dodecahedron_verts[21],
  Catalan_pentakis_dodecahedron_verts[22],
  Catalan_pentakis_dodecahedron_verts[23],
  Catalan_pentakis_dodecahedron_verts[24],
  Catalan_pentakis_dodecahedron_verts[25],
  Catalan_pentakis_dodecahedron_verts[26],
  Catalan_pentakis_dodecahedron_verts[27],
  Catalan_pentakis_dodecahedron_verts[28],
  Catalan_pentakis_dodecahedron_verts[29],
  Catalan_pentakis_dodecahedron_verts[30],
  Catalan_pentakis_dodecahedron_verts[31]
 }
 face_indices {
  60,
  <2, 0, 1>,
  <2, 3, 0>,
  <0, 4, 1>,
  <1, 5, 2>,
  <0, 3, 6>,
  <3, 2, 7>,
  <1, 4, 8>,
  <4, 0, 9>,
  <2, 5, 7>,
  <5, 1, 10>,
  <3, 11, 6>,
  <6, 9, 0>,
  <7, 12, 3>,
  <4, 13, 8>,
  <8, 10, 1>,
  <9, 13, 4>,
  <5, 14, 7>,
  <10, 15, 5>,
  <6, 11, 16>,
  <11, 3, 12>,
  <9, 6, 16>,
  <12, 7, 17>,
  <8, 13, 18>,
  <10, 8, 19>,
  <13, 9, 20>,
  <7, 14, 17>,
  <14, 5, 15>,
  <15, 10, 19>,
  <11, 21, 16>,
  <12, 22, 11>,
  <16, 20, 9>,
  <17, 22, 12>,
  <13, 23, 18>,
  <18, 19, 8>,
  <20, 23, 13>,
  <14, 24, 17>,
  <15, 24, 14>,
  <19, 25, 15>,
  <16, 21, 26>,
  <21, 11, 22>,
  <20, 16, 26>,
  <22, 17, 27>,
  <18, 23, 28>,
  <19, 18, 28>,
  <23, 20, 26>,
  <17, 24, 27>,
  <24, 15, 25>,
  <25, 19, 28>,
  <21, 29, 26>,
  <22, 29, 21>,
  <27, 29, 22>,
  <23, 30, 28>,
  <26, 30, 23>,
  <24, 31, 27>,
  <25, 31, 24>,
  <28, 31, 25>,
  <26, 29, 30>,
  <29, 27, 31>,
  <28, 30, 31>,
  <29, 31, 30>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_pentakis_dodecahedron_verts[29];
 #local P1 = Catalan_pentakis_dodecahedron_verts[31];
 #local P2 = Catalan_pentakis_dodecahedron_verts[30];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_pentakis_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_pentakis_dodecahedron_obj }
#end
#end

#macro Catalan_pentakis_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_pentakis_dodecahedron_verts[0], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[1], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[2], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[3], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[4], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[5], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[6], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[7], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[8], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[9], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[10], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[11], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[12], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[13], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[14], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[15], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[16], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[17], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[18], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[19], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[20], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[21], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[22], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[23], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[24], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[25], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[26], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[27], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[28], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[29], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[30], RadVer }
  sphere { Catalan_pentakis_dodecahedron_verts[31], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_pentakis_dodecahedron_verts[2], Catalan_pentakis_dodecahedron_verts[0], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[0], Catalan_pentakis_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[1], Catalan_pentakis_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[2], Catalan_pentakis_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[3], Catalan_pentakis_dodecahedron_verts[0], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[0], Catalan_pentakis_dodecahedron_verts[4], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[4], Catalan_pentakis_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[1], Catalan_pentakis_dodecahedron_verts[5], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[5], Catalan_pentakis_dodecahedron_verts[2], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[3], Catalan_pentakis_dodecahedron_verts[6], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[6], Catalan_pentakis_dodecahedron_verts[0], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[2], Catalan_pentakis_dodecahedron_verts[7], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[7], Catalan_pentakis_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[4], Catalan_pentakis_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[8], Catalan_pentakis_dodecahedron_verts[1], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[0], Catalan_pentakis_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[9], Catalan_pentakis_dodecahedron_verts[4], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[5], Catalan_pentakis_dodecahedron_verts[7], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[1], Catalan_pentakis_dodecahedron_verts[10], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[10], Catalan_pentakis_dodecahedron_verts[5], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[3], Catalan_pentakis_dodecahedron_verts[11], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[11], Catalan_pentakis_dodecahedron_verts[6], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[6], Catalan_pentakis_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[7], Catalan_pentakis_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[12], Catalan_pentakis_dodecahedron_verts[3], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[4], Catalan_pentakis_dodecahedron_verts[13], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[13], Catalan_pentakis_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[8], Catalan_pentakis_dodecahedron_verts[10], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[9], Catalan_pentakis_dodecahedron_verts[13], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[5], Catalan_pentakis_dodecahedron_verts[14], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[14], Catalan_pentakis_dodecahedron_verts[7], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[10], Catalan_pentakis_dodecahedron_verts[15], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[15], Catalan_pentakis_dodecahedron_verts[5], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[11], Catalan_pentakis_dodecahedron_verts[16], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[16], Catalan_pentakis_dodecahedron_verts[6], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[12], Catalan_pentakis_dodecahedron_verts[11], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[16], Catalan_pentakis_dodecahedron_verts[9], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[7], Catalan_pentakis_dodecahedron_verts[17], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[17], Catalan_pentakis_dodecahedron_verts[12], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[13], Catalan_pentakis_dodecahedron_verts[18], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[18], Catalan_pentakis_dodecahedron_verts[8], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[8], Catalan_pentakis_dodecahedron_verts[19], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[19], Catalan_pentakis_dodecahedron_verts[10], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[9], Catalan_pentakis_dodecahedron_verts[20], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[20], Catalan_pentakis_dodecahedron_verts[13], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[14], Catalan_pentakis_dodecahedron_verts[17], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[15], Catalan_pentakis_dodecahedron_verts[14], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[19], Catalan_pentakis_dodecahedron_verts[15], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[11], Catalan_pentakis_dodecahedron_verts[21], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[21], Catalan_pentakis_dodecahedron_verts[16], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[12], Catalan_pentakis_dodecahedron_verts[22], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[22], Catalan_pentakis_dodecahedron_verts[11], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[16], Catalan_pentakis_dodecahedron_verts[20], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[17], Catalan_pentakis_dodecahedron_verts[22], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[13], Catalan_pentakis_dodecahedron_verts[23], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[23], Catalan_pentakis_dodecahedron_verts[18], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[18], Catalan_pentakis_dodecahedron_verts[19], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[20], Catalan_pentakis_dodecahedron_verts[23], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[14], Catalan_pentakis_dodecahedron_verts[24], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[24], Catalan_pentakis_dodecahedron_verts[17], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[15], Catalan_pentakis_dodecahedron_verts[24], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[19], Catalan_pentakis_dodecahedron_verts[25], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[25], Catalan_pentakis_dodecahedron_verts[15], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[21], Catalan_pentakis_dodecahedron_verts[26], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[26], Catalan_pentakis_dodecahedron_verts[16], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[22], Catalan_pentakis_dodecahedron_verts[21], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[26], Catalan_pentakis_dodecahedron_verts[20], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[17], Catalan_pentakis_dodecahedron_verts[27], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[27], Catalan_pentakis_dodecahedron_verts[22], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[23], Catalan_pentakis_dodecahedron_verts[28], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[28], Catalan_pentakis_dodecahedron_verts[18], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[28], Catalan_pentakis_dodecahedron_verts[19], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[26], Catalan_pentakis_dodecahedron_verts[23], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[24], Catalan_pentakis_dodecahedron_verts[27], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[25], Catalan_pentakis_dodecahedron_verts[24], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[28], Catalan_pentakis_dodecahedron_verts[25], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[21], Catalan_pentakis_dodecahedron_verts[29], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[29], Catalan_pentakis_dodecahedron_verts[26], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[22], Catalan_pentakis_dodecahedron_verts[29], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[27], Catalan_pentakis_dodecahedron_verts[29], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[23], Catalan_pentakis_dodecahedron_verts[30], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[30], Catalan_pentakis_dodecahedron_verts[28], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[26], Catalan_pentakis_dodecahedron_verts[30], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[24], Catalan_pentakis_dodecahedron_verts[31], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[31], Catalan_pentakis_dodecahedron_verts[27], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[25], Catalan_pentakis_dodecahedron_verts[31], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[28], Catalan_pentakis_dodecahedron_verts[31], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[29], Catalan_pentakis_dodecahedron_verts[30], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[31], Catalan_pentakis_dodecahedron_verts[29], RadEdg }
  cylinder { Catalan_pentakis_dodecahedron_verts[30], Catalan_pentakis_dodecahedron_verts[31], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_pentakis_dodecahedron_verts[29];
 #local P1 = Catalan_pentakis_dodecahedron_verts[31];
 #local P2 = Catalan_pentakis_dodecahedron_verts[30];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_trapezoidal_hexecontahedron_verts = array[62]
{
<0.223919, 0.236068, 0.9746078>,
<-0.1454638, 0.2165424, 0.9746078>,
<-0.3032091, -0.118034, 0.9746078>,
<0.223919, -0.3333333, 0.9746078>,
<0.698187, -0.118034, 0.7445341>,
<0.5562603, 0.2165424, 0.8133846>,
<0.1668994, 0.745356, 0.7264297>,
<-0.3358785, 0.5, 0.8324144>,
<-0.7531269, 0.127322, 0.7264297>,
<-0.4107965, -0.4330847, 0.8133846>,
<-0.1547242, -0.690983, 0.7445341>,
<0.6655177, 0.5, 0.6023407>,
<0.9946659, 0.127322, 0.3248693>,
<0.4641726, -0.690983, 0.6023407>,
<0.724617, -0.4330847, 0.55252>,
<-0.2402536, 0.927051, 0.372267>,
<-0.4707309, 0.7007458, 0.55252>,
<-0.7145217, -0.427051, 0.6023407>,
<-0.7673818, 0.572949, 0.372267>,
<0.1269431, -0.8345764, 0.55252>,
<-0.4939678, -0.872678, 0.3248693>,
<0.6646826, 0.7007458, 0.2916555>,
<0.3786432, 0.927051, 0.2300737>,
<0.9057713, -0.427051, 0.2300737>
<0.8529112, 0.572949, 0>,
<0.5862275, -0.872678, 0.07669123>,
<0.0299672, 1., 0.1304323>,
<-0.5862275, 0.872678, -0.07669123>,
<-1.001396, 0, 0.2300737>,
<-0.9000481, -0.3503729, 0.2916555>,
<-0.9370896, 0.3503729, 0.1304323>,
<0.0528601, -1., 0.2300737>,
<-0.8529112, -0.572949, 0>,
<0.4939678, 0.872678, -0.3248693>,
<0.9370896, -0.3503729, -0.1304323>,
<1.001396, 0, -0.2300737>,
<0.9000481, 0.3503729, -0.2916555>,
<0.7673818, -0.572949, -0.372267>,
<-0.0528601, 1., -0.2300737>,
<-0.9057713, 0.427051, -0.2300737>,
<-0.9946659, -0.127322, -0.3248693>,
<-0.3786432, -0.927051, -0.2300737>,
<-0.0299672, -1., -0.1304323>,
<0.2402536, -0.927051, -0.372267>,
<-0.6646826, -0.7007458, -0.2916555>,
<0.7145217, 0.427051, -0.6023407>,
<0.7531269, -0.127322, -0.7264297>,
<0.4707309, -0.7007458, -0.55252>,
<-0.1269431, 0.8345764, -0.55252>,
<-0.4641726, 0.690983, -0.6023407>,
<0.1547242, 0.690983, -0.7445341>,
<-0.724617, 0.4330847, -0.55252>,
<-0.6655177, -0.5, -0.6023407>,
<-0.698187, 0.118034, -0.7445341>,
<-0.1668994, -0.745356, -0.7264297>,
<0.4107965, 0.4330847, -0.8133846>,
<0.3358785, -0.5, -0.8324144>,
<0.3032091, 0.118034, -0.9746078>,
<-0.223919, 0.3333333, -0.9746078>,
<-0.5562603, -0.2165424, -0.8133846>,
<-0.223919, -0.236068, -0.9746078>,
<0.1454638, -0.2165424, -0.9746078>,
}
#local P0 = Catalan_trapezoidal_hexecontahedron_verts[5];
#local P1 = Catalan_trapezoidal_hexecontahedron_verts[1];
#local P2 = Catalan_trapezoidal_hexecontahedron_verts[9];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 62)
 #declare Catalan_trapezoidal_hexecontahedron_verts[Num] = vtransform(Catalan_trapezoidal_hexecontahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_trapezoidal_hexecontahedron_faces(Tex4, OnPlane)
#local Catalan_trapezoidal_hexecontahedron_obj = mesh2 {
 vertex_vectors {
  62,
  Catalan_trapezoidal_hexecontahedron_verts[0],
  Catalan_trapezoidal_hexecontahedron_verts[1],
  Catalan_trapezoidal_hexecontahedron_verts[2],
  Catalan_trapezoidal_hexecontahedron_verts[3],
  Catalan_trapezoidal_hexecontahedron_verts[4],
  Catalan_trapezoidal_hexecontahedron_verts[5],
  Catalan_trapezoidal_hexecontahedron_verts[6],
  Catalan_trapezoidal_hexecontahedron_verts[7],
  Catalan_trapezoidal_hexecontahedron_verts[8],
  Catalan_trapezoidal_hexecontahedron_verts[9],
  Catalan_trapezoidal_hexecontahedron_verts[10],
  Catalan_trapezoidal_hexecontahedron_verts[11],
  Catalan_trapezoidal_hexecontahedron_verts[12],
  Catalan_trapezoidal_hexecontahedron_verts[13],
  Catalan_trapezoidal_hexecontahedron_verts[14],
  Catalan_trapezoidal_hexecontahedron_verts[15],
  Catalan_trapezoidal_hexecontahedron_verts[16],
  Catalan_trapezoidal_hexecontahedron_verts[17],
  Catalan_trapezoidal_hexecontahedron_verts[18],
  Catalan_trapezoidal_hexecontahedron_verts[19],
  Catalan_trapezoidal_hexecontahedron_verts[20],
  Catalan_trapezoidal_hexecontahedron_verts[21],
  Catalan_trapezoidal_hexecontahedron_verts[22],
  Catalan_trapezoidal_hexecontahedron_verts[23],
  Catalan_trapezoidal_hexecontahedron_verts[24],
  Catalan_trapezoidal_hexecontahedron_verts[25],
  Catalan_trapezoidal_hexecontahedron_verts[26],
  Catalan_trapezoidal_hexecontahedron_verts[27],
  Catalan_trapezoidal_hexecontahedron_verts[28],
  Catalan_trapezoidal_hexecontahedron_verts[29],
  Catalan_trapezoidal_hexecontahedron_verts[30],
  Catalan_trapezoidal_hexecontahedron_verts[31],
  Catalan_trapezoidal_hexecontahedron_verts[32],
  Catalan_trapezoidal_hexecontahedron_verts[33],
  Catalan_trapezoidal_hexecontahedron_verts[34],
  Catalan_trapezoidal_hexecontahedron_verts[35],
  Catalan_trapezoidal_hexecontahedron_verts[36],
  Catalan_trapezoidal_hexecontahedron_verts[37],
  Catalan_trapezoidal_hexecontahedron_verts[38],
  Catalan_trapezoidal_hexecontahedron_verts[39],
  Catalan_trapezoidal_hexecontahedron_verts[40],
  Catalan_trapezoidal_hexecontahedron_verts[41],
  Catalan_trapezoidal_hexecontahedron_verts[42],
  Catalan_trapezoidal_hexecontahedron_verts[43],
  Catalan_trapezoidal_hexecontahedron_verts[44],
  Catalan_trapezoidal_hexecontahedron_verts[45],
  Catalan_trapezoidal_hexecontahedron_verts[46],
  Catalan_trapezoidal_hexecontahedron_verts[47],
  Catalan_trapezoidal_hexecontahedron_verts[48],
  Catalan_trapezoidal_hexecontahedron_verts[49],
  Catalan_trapezoidal_hexecontahedron_verts[50],
  Catalan_trapezoidal_hexecontahedron_verts[51],
  Catalan_trapezoidal_hexecontahedron_verts[52],
  Catalan_trapezoidal_hexecontahedron_verts[53],
  Catalan_trapezoidal_hexecontahedron_verts[54],
  Catalan_trapezoidal_hexecontahedron_verts[55],
  Catalan_trapezoidal_hexecontahedron_verts[56],
  Catalan_trapezoidal_hexecontahedron_verts[57],
  Catalan_trapezoidal_hexecontahedron_verts[58],
  Catalan_trapezoidal_hexecontahedron_verts[59],
  Catalan_trapezoidal_hexecontahedron_verts[60],
  Catalan_trapezoidal_hexecontahedron_verts[61]
 }
 texture_list {
  1,
  texture { Tex4 }
 }
 face_indices {
  120,
  <3, 0, 1>, 0,
  <3, 1, 2>, 0,
  <3, 4, 5>, 0,
  <3, 5, 0>, 0,
  <0, 6, 7>, 0,
  <0, 7, 1>, 0,
  <1, 7, 8>, 0,
  <1, 8, 2>, 0,
  <2, 9, 10>, 0,
  <2, 10, 3>, 0,
  <0, 5, 11>, 0,
  <0, 11, 6>, 0,
  <5, 4, 12>, 0,
  <5, 12, 11>, 0,
  <4, 3, 13>, 0,
  <4, 13, 14>, 0,
  <7, 6, 15>, 0,
  <7, 15, 16>, 0,
  <2, 8, 17>, 0,
  <2, 17, 9>, 0,
  <8, 7, 16>, 0,
  <8, 16, 18>, 0,
  <3, 10, 19>, 0,
  <3, 19, 13>, 0,
  <10, 9, 17>, 0,
  <10, 17, 20>, 0,
  <11, 21, 22>, 0,
  <11, 22, 6>, 0,
  <4, 14, 23>, 0,
  <4, 23, 12>, 0,
  <12, 24, 21>, 0,
  <12, 21, 11>, 0,
  <13, 25, 23>, 0,
  <13, 23, 14>, 0,
  <6, 22, 26>, 0,
  <6, 26, 15>, 0,
  <15, 27, 18>, 0,
  <15, 18, 16>, 0,
  <8, 28, 29>, 0,
  <8, 29, 17>, 0,
  <18, 30, 28>, 0,
  <18, 28, 8>, 0,
  <10, 20, 31>, 0,
  <10, 31, 19>, 0,
  <19, 31, 25>, 0,
  <19, 25, 13>, 0,
  <17, 29, 32>, 0,
  <17, 32, 20>, 0,
  <22, 21, 24>, 0,
  <22, 24, 33>, 0,
  <12, 23, 34>, 0,
  <12, 34, 35>, 0,
  <24, 12, 35>, 0,
  <24, 35, 36>, 0,
  <23, 25, 37>, 0,
  <23, 37, 34>, 0,
  <15, 26, 38>, 0,
  <15, 38, 27>, 0,
  <26, 22, 33>, 0,
  <26, 33, 38>, 0,
  <18, 27, 39>, 0,
  <18, 39, 30>, 0,
  <29, 28, 40>, 0,
  <29, 40, 32>, 0,
  <28, 30, 39>, 0,
  <28, 39, 40>, 0,
  <31, 20, 41>, 0,
  <31, 41, 42>, 0,
  <25, 31, 42>, 0,
  <25, 42, 43>, 0,
  <20, 32, 44>, 0,
  <20, 44, 41>, 0,
  <24, 36, 45>, 0,
  <24, 45, 33>, 0,
  <34, 37, 46>, 0,
  <34, 46, 35>, 0,
  <35, 46, 45>, 0,
  <35, 45, 36>, 0,
  <25, 43, 47>, 0,
  <25, 47, 37>, 0,
  <38, 48, 49>, 0,
  <38, 49, 27>, 0,
  <33, 50, 48>, 0,
  <33, 48, 38>, 0,
  <27, 49, 51>, 0,
  <27, 51, 39>, 0,
  <40, 52, 44>, 0,
  <40, 44, 32>, 0,
  <39, 51, 53>, 0,
  <39, 53, 40>, 0,
  <41, 54, 43>, 0,
  <41, 43, 42>, 0,
  <44, 52, 54>, 0,
  <44, 54, 41>, 0,
  <33, 45, 55>, 0,
  <33, 55, 50>, 0,
  <46, 37, 47>, 0,
  <46, 47, 56>, 0,
  <45, 46, 57>, 0,
  <45, 57, 55>, 0,
  <47, 43, 54>, 0,
  <47, 54, 56>, 0,
  <49, 48, 50>, 0,
  <49, 50, 58>, 0,
  <51, 49, 58>, 0,
  <51, 58, 53>, 0,
  <52, 40, 53>, 0,
  <52, 53, 59>, 0,
  <54, 52, 59>, 0,
  <54, 59, 60>, 0,
  <55, 57, 58>, 0,
  <55, 58, 50>, 0,
  <56, 61, 57>, 0,
  <56, 57, 46>, 0,
  <54, 60, 61>, 0,
  <54, 61, 56>, 0,
  <58, 60, 59>, 0,
  <58, 59, 53>, 0,
  <58, 57, 61>, 0,
  <58, 61, 60>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_trapezoidal_hexecontahedron_verts[58];
 #local P1 = Catalan_trapezoidal_hexecontahedron_verts[57];
 #local P2 = Catalan_trapezoidal_hexecontahedron_verts[61];
 #local P3 = Catalan_trapezoidal_hexecontahedron_verts[60];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_trapezoidal_hexecontahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_trapezoidal_hexecontahedron_obj }
#end
#end

#macro Catalan_trapezoidal_hexecontahedron_faces2(OnPlane)
#local Catalan_trapezoidal_hexecontahedron_obj = mesh2 {
 vertex_vectors {
  62,
  Catalan_trapezoidal_hexecontahedron_verts[0],
  Catalan_trapezoidal_hexecontahedron_verts[1],
  Catalan_trapezoidal_hexecontahedron_verts[2],
  Catalan_trapezoidal_hexecontahedron_verts[3],
  Catalan_trapezoidal_hexecontahedron_verts[4],
  Catalan_trapezoidal_hexecontahedron_verts[5],
  Catalan_trapezoidal_hexecontahedron_verts[6],
  Catalan_trapezoidal_hexecontahedron_verts[7],
  Catalan_trapezoidal_hexecontahedron_verts[8],
  Catalan_trapezoidal_hexecontahedron_verts[9],
  Catalan_trapezoidal_hexecontahedron_verts[10],
  Catalan_trapezoidal_hexecontahedron_verts[11],
  Catalan_trapezoidal_hexecontahedron_verts[12],
  Catalan_trapezoidal_hexecontahedron_verts[13],
  Catalan_trapezoidal_hexecontahedron_verts[14],
  Catalan_trapezoidal_hexecontahedron_verts[15],
  Catalan_trapezoidal_hexecontahedron_verts[16],
  Catalan_trapezoidal_hexecontahedron_verts[17],
  Catalan_trapezoidal_hexecontahedron_verts[18],
  Catalan_trapezoidal_hexecontahedron_verts[19],
  Catalan_trapezoidal_hexecontahedron_verts[20],
  Catalan_trapezoidal_hexecontahedron_verts[21],
  Catalan_trapezoidal_hexecontahedron_verts[22],
  Catalan_trapezoidal_hexecontahedron_verts[23],
  Catalan_trapezoidal_hexecontahedron_verts[24],
  Catalan_trapezoidal_hexecontahedron_verts[25],
  Catalan_trapezoidal_hexecontahedron_verts[26],
  Catalan_trapezoidal_hexecontahedron_verts[27],
  Catalan_trapezoidal_hexecontahedron_verts[28],
  Catalan_trapezoidal_hexecontahedron_verts[29],
  Catalan_trapezoidal_hexecontahedron_verts[30],
  Catalan_trapezoidal_hexecontahedron_verts[31],
  Catalan_trapezoidal_hexecontahedron_verts[32],
  Catalan_trapezoidal_hexecontahedron_verts[33],
  Catalan_trapezoidal_hexecontahedron_verts[34],
  Catalan_trapezoidal_hexecontahedron_verts[35],
  Catalan_trapezoidal_hexecontahedron_verts[36],
  Catalan_trapezoidal_hexecontahedron_verts[37],
  Catalan_trapezoidal_hexecontahedron_verts[38],
  Catalan_trapezoidal_hexecontahedron_verts[39],
  Catalan_trapezoidal_hexecontahedron_verts[40],
  Catalan_trapezoidal_hexecontahedron_verts[41],
  Catalan_trapezoidal_hexecontahedron_verts[42],
  Catalan_trapezoidal_hexecontahedron_verts[43],
  Catalan_trapezoidal_hexecontahedron_verts[44],
  Catalan_trapezoidal_hexecontahedron_verts[45],
  Catalan_trapezoidal_hexecontahedron_verts[46],
  Catalan_trapezoidal_hexecontahedron_verts[47],
  Catalan_trapezoidal_hexecontahedron_verts[48],
  Catalan_trapezoidal_hexecontahedron_verts[49],
  Catalan_trapezoidal_hexecontahedron_verts[50],
  Catalan_trapezoidal_hexecontahedron_verts[51],
  Catalan_trapezoidal_hexecontahedron_verts[52],
  Catalan_trapezoidal_hexecontahedron_verts[53],
  Catalan_trapezoidal_hexecontahedron_verts[54],
  Catalan_trapezoidal_hexecontahedron_verts[55],
  Catalan_trapezoidal_hexecontahedron_verts[56],
  Catalan_trapezoidal_hexecontahedron_verts[57],
  Catalan_trapezoidal_hexecontahedron_verts[58],
  Catalan_trapezoidal_hexecontahedron_verts[59],
  Catalan_trapezoidal_hexecontahedron_verts[60],
  Catalan_trapezoidal_hexecontahedron_verts[61]
 }
 face_indices {
  120,
  <3, 0, 1>,
  <3, 1, 2>,
  <3, 4, 5>,
  <3, 5, 0>,
  <0, 6, 7>,
  <0, 7, 1>,
  <1, 7, 8>,
  <1, 8, 2>,
  <2, 9, 10>,
  <2, 10, 3>,
  <0, 5, 11>,
  <0, 11, 6>,
  <5, 4, 12>,
  <5, 12, 11>,
  <4, 3, 13>,
  <4, 13, 14>,
  <7, 6, 15>,
  <7, 15, 16>,
  <2, 8, 17>,
  <2, 17, 9>,
  <8, 7, 16>,
  <8, 16, 18>,
  <3, 10, 19>,
  <3, 19, 13>,
  <10, 9, 17>,
  <10, 17, 20>,
  <11, 21, 22>,
  <11, 22, 6>,
  <4, 14, 23>,
  <4, 23, 12>,
  <12, 24, 21>,
  <12, 21, 11>,
  <13, 25, 23>,
  <13, 23, 14>,
  <6, 22, 26>,
  <6, 26, 15>,
  <15, 27, 18>,
  <15, 18, 16>,
  <8, 28, 29>,
  <8, 29, 17>,
  <18, 30, 28>,
  <18, 28, 8>,
  <10, 20, 31>,
  <10, 31, 19>,
  <19, 31, 25>,
  <19, 25, 13>,
  <17, 29, 32>,
  <17, 32, 20>,
  <22, 21, 24>,
  <22, 24, 33>,
  <12, 23, 34>,
  <12, 34, 35>,
  <24, 12, 35>,
  <24, 35, 36>,
  <23, 25, 37>,
  <23, 37, 34>,
  <15, 26, 38>,
  <15, 38, 27>,
  <26, 22, 33>,
  <26, 33, 38>,
  <18, 27, 39>,
  <18, 39, 30>,
  <29, 28, 40>,
  <29, 40, 32>,
  <28, 30, 39>,
  <28, 39, 40>,
  <31, 20, 41>,
  <31, 41, 42>,
  <25, 31, 42>,
  <25, 42, 43>,
  <20, 32, 44>,
  <20, 44, 41>,
  <24, 36, 45>,
  <24, 45, 33>,
  <34, 37, 46>,
  <34, 46, 35>,
  <35, 46, 45>,
  <35, 45, 36>,
  <25, 43, 47>,
  <25, 47, 37>,
  <38, 48, 49>,
  <38, 49, 27>,
  <33, 50, 48>,
  <33, 48, 38>,
  <27, 49, 51>,
  <27, 51, 39>,
  <40, 52, 44>,
  <40, 44, 32>,
  <39, 51, 53>,
  <39, 53, 40>,
  <41, 54, 43>,
  <41, 43, 42>,
  <44, 52, 54>,
  <44, 54, 41>,
  <33, 45, 55>,
  <33, 55, 50>,
  <46, 37, 47>,
  <46, 47, 56>,
  <45, 46, 57>,
  <45, 57, 55>,
  <47, 43, 54>,
  <47, 54, 56>,
  <49, 48, 50>,
  <49, 50, 58>,
  <51, 49, 58>,
  <51, 58, 53>,
  <52, 40, 53>,
  <52, 53, 59>,
  <54, 52, 59>,
  <54, 59, 60>,
  <55, 57, 58>,
  <55, 58, 50>,
  <56, 61, 57>,
  <56, 57, 46>,
  <54, 60, 61>,
  <54, 61, 56>,
  <58, 60, 59>,
  <58, 59, 53>,
  <58, 57, 61>,
  <58, 61, 60>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_trapezoidal_hexecontahedron_verts[58];
 #local P1 = Catalan_trapezoidal_hexecontahedron_verts[57];
 #local P2 = Catalan_trapezoidal_hexecontahedron_verts[61];
 #local P3 = Catalan_trapezoidal_hexecontahedron_verts[60];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_trapezoidal_hexecontahedron_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_trapezoidal_hexecontahedron_obj }
#end
#end

#macro Catalan_trapezoidal_hexecontahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_trapezoidal_hexecontahedron_verts[0], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[1], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[2], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[3], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[4], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[5], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[6], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[7], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[8], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[9], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[10], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[11], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[12], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[13], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[14], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[15], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[16], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[17], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[18], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[19], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[20], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[21], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[22], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[23], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[24], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[25], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[26], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[27], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[28], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[29], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[30], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[31], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[32], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[33], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[34], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[35], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[36], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[37], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[38], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[39], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[40], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[41], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[42], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[43], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[44], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[45], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[46], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[47], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[48], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[49], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[50], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[51], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[52], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[53], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[54], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[55], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[56], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[57], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[58], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[59], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[60], RadVer }
  sphere { Catalan_trapezoidal_hexecontahedron_verts[61], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[3], Catalan_trapezoidal_hexecontahedron_verts[0], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[0], Catalan_trapezoidal_hexecontahedron_verts[1], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[1], Catalan_trapezoidal_hexecontahedron_verts[2], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[2], Catalan_trapezoidal_hexecontahedron_verts[3], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[3], Catalan_trapezoidal_hexecontahedron_verts[4], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[4], Catalan_trapezoidal_hexecontahedron_verts[5], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[5], Catalan_trapezoidal_hexecontahedron_verts[0], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[0], Catalan_trapezoidal_hexecontahedron_verts[6], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[6], Catalan_trapezoidal_hexecontahedron_verts[7], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[7], Catalan_trapezoidal_hexecontahedron_verts[1], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[7], Catalan_trapezoidal_hexecontahedron_verts[8], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[8], Catalan_trapezoidal_hexecontahedron_verts[2], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[2], Catalan_trapezoidal_hexecontahedron_verts[9], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[9], Catalan_trapezoidal_hexecontahedron_verts[10], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[10], Catalan_trapezoidal_hexecontahedron_verts[3], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[5], Catalan_trapezoidal_hexecontahedron_verts[11], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[11], Catalan_trapezoidal_hexecontahedron_verts[6], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[4], Catalan_trapezoidal_hexecontahedron_verts[12], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[12], Catalan_trapezoidal_hexecontahedron_verts[11], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[3], Catalan_trapezoidal_hexecontahedron_verts[13], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[13], Catalan_trapezoidal_hexecontahedron_verts[14], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[14], Catalan_trapezoidal_hexecontahedron_verts[4], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[6], Catalan_trapezoidal_hexecontahedron_verts[15], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[15], Catalan_trapezoidal_hexecontahedron_verts[16], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[16], Catalan_trapezoidal_hexecontahedron_verts[7], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[8], Catalan_trapezoidal_hexecontahedron_verts[17], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[17], Catalan_trapezoidal_hexecontahedron_verts[9], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[16], Catalan_trapezoidal_hexecontahedron_verts[18], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[18], Catalan_trapezoidal_hexecontahedron_verts[8], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[10], Catalan_trapezoidal_hexecontahedron_verts[19], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[19], Catalan_trapezoidal_hexecontahedron_verts[13], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[17], Catalan_trapezoidal_hexecontahedron_verts[20], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[20], Catalan_trapezoidal_hexecontahedron_verts[10], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[11], Catalan_trapezoidal_hexecontahedron_verts[21], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[21], Catalan_trapezoidal_hexecontahedron_verts[22], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[22], Catalan_trapezoidal_hexecontahedron_verts[6], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[14], Catalan_trapezoidal_hexecontahedron_verts[23], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[23], Catalan_trapezoidal_hexecontahedron_verts[12], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[12], Catalan_trapezoidal_hexecontahedron_verts[24], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[24], Catalan_trapezoidal_hexecontahedron_verts[21], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[13], Catalan_trapezoidal_hexecontahedron_verts[25], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[25], Catalan_trapezoidal_hexecontahedron_verts[23], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[22], Catalan_trapezoidal_hexecontahedron_verts[26], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[26], Catalan_trapezoidal_hexecontahedron_verts[15], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[15], Catalan_trapezoidal_hexecontahedron_verts[27], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[27], Catalan_trapezoidal_hexecontahedron_verts[18], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[8], Catalan_trapezoidal_hexecontahedron_verts[28], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[28], Catalan_trapezoidal_hexecontahedron_verts[29], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[29], Catalan_trapezoidal_hexecontahedron_verts[17], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[18], Catalan_trapezoidal_hexecontahedron_verts[30], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[30], Catalan_trapezoidal_hexecontahedron_verts[28], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[20], Catalan_trapezoidal_hexecontahedron_verts[31], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[31], Catalan_trapezoidal_hexecontahedron_verts[19], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[31], Catalan_trapezoidal_hexecontahedron_verts[25], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[29], Catalan_trapezoidal_hexecontahedron_verts[32], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[32], Catalan_trapezoidal_hexecontahedron_verts[20], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[24], Catalan_trapezoidal_hexecontahedron_verts[33], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[33], Catalan_trapezoidal_hexecontahedron_verts[22], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[23], Catalan_trapezoidal_hexecontahedron_verts[34], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[34], Catalan_trapezoidal_hexecontahedron_verts[35], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[35], Catalan_trapezoidal_hexecontahedron_verts[12], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[35], Catalan_trapezoidal_hexecontahedron_verts[36], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[36], Catalan_trapezoidal_hexecontahedron_verts[24], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[25], Catalan_trapezoidal_hexecontahedron_verts[37], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[37], Catalan_trapezoidal_hexecontahedron_verts[34], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[26], Catalan_trapezoidal_hexecontahedron_verts[38], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[38], Catalan_trapezoidal_hexecontahedron_verts[27], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[33], Catalan_trapezoidal_hexecontahedron_verts[38], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[27], Catalan_trapezoidal_hexecontahedron_verts[39], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[39], Catalan_trapezoidal_hexecontahedron_verts[30], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[28], Catalan_trapezoidal_hexecontahedron_verts[40], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[40], Catalan_trapezoidal_hexecontahedron_verts[32], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[39], Catalan_trapezoidal_hexecontahedron_verts[40], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[20], Catalan_trapezoidal_hexecontahedron_verts[41], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[41], Catalan_trapezoidal_hexecontahedron_verts[42], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[42], Catalan_trapezoidal_hexecontahedron_verts[31], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[42], Catalan_trapezoidal_hexecontahedron_verts[43], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[43], Catalan_trapezoidal_hexecontahedron_verts[25], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[32], Catalan_trapezoidal_hexecontahedron_verts[44], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[44], Catalan_trapezoidal_hexecontahedron_verts[41], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[36], Catalan_trapezoidal_hexecontahedron_verts[45], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[45], Catalan_trapezoidal_hexecontahedron_verts[33], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[37], Catalan_trapezoidal_hexecontahedron_verts[46], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[46], Catalan_trapezoidal_hexecontahedron_verts[35], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[46], Catalan_trapezoidal_hexecontahedron_verts[45], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[43], Catalan_trapezoidal_hexecontahedron_verts[47], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[47], Catalan_trapezoidal_hexecontahedron_verts[37], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[38], Catalan_trapezoidal_hexecontahedron_verts[48], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[48], Catalan_trapezoidal_hexecontahedron_verts[49], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[49], Catalan_trapezoidal_hexecontahedron_verts[27], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[33], Catalan_trapezoidal_hexecontahedron_verts[50], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[50], Catalan_trapezoidal_hexecontahedron_verts[48], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[49], Catalan_trapezoidal_hexecontahedron_verts[51], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[51], Catalan_trapezoidal_hexecontahedron_verts[39], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[40], Catalan_trapezoidal_hexecontahedron_verts[52], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[52], Catalan_trapezoidal_hexecontahedron_verts[44], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[51], Catalan_trapezoidal_hexecontahedron_verts[53], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[53], Catalan_trapezoidal_hexecontahedron_verts[40], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[41], Catalan_trapezoidal_hexecontahedron_verts[54], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[54], Catalan_trapezoidal_hexecontahedron_verts[43], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[52], Catalan_trapezoidal_hexecontahedron_verts[54], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[45], Catalan_trapezoidal_hexecontahedron_verts[55], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[55], Catalan_trapezoidal_hexecontahedron_verts[50], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[47], Catalan_trapezoidal_hexecontahedron_verts[56], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[56], Catalan_trapezoidal_hexecontahedron_verts[46], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[46], Catalan_trapezoidal_hexecontahedron_verts[57], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[57], Catalan_trapezoidal_hexecontahedron_verts[55], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[54], Catalan_trapezoidal_hexecontahedron_verts[56], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[50], Catalan_trapezoidal_hexecontahedron_verts[58], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[58], Catalan_trapezoidal_hexecontahedron_verts[49], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[58], Catalan_trapezoidal_hexecontahedron_verts[53], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[53], Catalan_trapezoidal_hexecontahedron_verts[59], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[59], Catalan_trapezoidal_hexecontahedron_verts[52], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[59], Catalan_trapezoidal_hexecontahedron_verts[60], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[60], Catalan_trapezoidal_hexecontahedron_verts[54], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[57], Catalan_trapezoidal_hexecontahedron_verts[58], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[56], Catalan_trapezoidal_hexecontahedron_verts[61], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[61], Catalan_trapezoidal_hexecontahedron_verts[57], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[60], Catalan_trapezoidal_hexecontahedron_verts[61], RadEdg }
  cylinder { Catalan_trapezoidal_hexecontahedron_verts[58], Catalan_trapezoidal_hexecontahedron_verts[60], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_trapezoidal_hexecontahedron_verts[58];
 #local P1 = Catalan_trapezoidal_hexecontahedron_verts[57];
 #local P2 = Catalan_trapezoidal_hexecontahedron_verts[61];
 #local P3 = Catalan_trapezoidal_hexecontahedron_verts[60];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_disdyakis_triacontahedron_verts = array[62]
{
<0.1314961, 0.1338305, 0.9913167>,
<-0.2383452, 0.127322, 0.9913167>,
<0.1314961, -0.4472136, 0.9913167>,
<0.4885473, 0.127322, 0.8948959>,
<0.1114053, 0.6944272, 0.839857>,
<-0.3882567, -0.2007458, 0.9093231>,
<0.6118981, -0.2007458, 0.7766546>,
<-0.399133, 0.4172882, 0.8273295>,
<-0.5004043, -0.509288, 0.7388838>,
<-0.8486892, 0.0763932, 0.6883973>,
<0.6010218, 0.4172882, 0.694661>,
<0.6757324, -0.509288, 0.5828718>,
<0.9988105, 0.0763932, 0.4433303>,
<-0.521099, 0.6666667, 0.5828718>,
<-0.2290796, -0.7421017, 0.6439862>,
<0.6550378, 0.6666667, 0.4268597>,
<0.3890501, -0.7421017, 0.5619926>,
<-0.257554, 0.8759323, 0.4293241>,
<-0.7597086, -0.4586441, 0.479999>,
<0.06452671, -0.9027346, 0.486451>,
<-0.554655, -0.9236068, 0.1982633>,
<0.3605756, 0.8759323, 0.3473305>,
<0.8585759, -0.4586441, 0.2653369>,
<0.5871626, -0.9236068, 0.04680363>
<-0.7773068, 0.5413559, 0.3473305>,
<0.03104202, 1., 0.2340181>,
<-0.5871626, 0.9236068, -0.04680363>,
<-0.9451196, -0.36339, 0.1744268>,
<0.8409777, 0.5413559, 0.1326684>,
<0.554655, 0.9236068, -0.1982633>,
<0.9579096, -0.36339, -0.07800604>,
<-0.9579096, 0.36339, 0.07800604>,
<-1.000155, 0, 0.1326684>,
<0.01759819, -1., 0.1326684>,
<0.9451196, 0.36339, -0.1744268>,
<1.000155, 0, -0.1326684>,
<-0.01759819, 1., -0.1326684>,
<-0.8409777, -0.5413559, -0.1326684>,
<-0.9988105, -0.0763932, -0.4433303>,
<-0.03104202, -1., -0.2340181>,
<0.7773068, -0.5413559, -0.3473305>,
<0.8486892, -0.0763932, -0.6883973>,
<-0.8585759, 0.4586441, -0.2653369>,
<-0.06452671, 0.9027346, -0.486451>,
<-0.6550378, -0.6666667, -0.4268597>,
<-0.3605756, -0.8759323, -0.3473305>,
<0.7597086, 0.4586441, -0.479999>,
<0.521099, -0.6666667, -0.5828718>,
<0.257554, -0.8759323, -0.4293241>,
<-0.6757324, 0.509288, -0.5828718>,
<-0.3890501, 0.7421017, -0.5619926>,
<-0.1114053, -0.6944272, -0.839857>,
<0.5004043, 0.509288, -0.7388838>,
<0.2290796, 0.7421017, -0.6439862>,
<-0.1314961, 0.4472136, -0.9913167>,
<-0.6010218, -0.4172882, -0.694661>,
<0.399133, -0.4172882, -0.8273295>,
<-0.6118981, 0.2007458, -0.7766546>,
<-0.4885473, -0.127322, -0.8948959>,
<0.3882567, 0.2007458, -0.9093231>,
<0.2383452, -0.127322, -0.9913167>,
<-0.1314961, -0.1338305, -0.9913167>,
}
#local P0 = Catalan_disdyakis_triacontahedron_verts[3];
#local P1 = Catalan_disdyakis_triacontahedron_verts[1];
#local P2 = Catalan_disdyakis_triacontahedron_verts[8];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 62)
 #declare Catalan_disdyakis_triacontahedron_verts[Num] = vtransform(Catalan_disdyakis_triacontahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_disdyakis_triacontahedron_faces(Tex3, OnPlane)
#local Catalan_disdyakis_triacontahedron_obj = mesh2 {
 vertex_vectors {
  62,
  Catalan_disdyakis_triacontahedron_verts[0],
  Catalan_disdyakis_triacontahedron_verts[1],
  Catalan_disdyakis_triacontahedron_verts[2],
  Catalan_disdyakis_triacontahedron_verts[3],
  Catalan_disdyakis_triacontahedron_verts[4],
  Catalan_disdyakis_triacontahedron_verts[5],
  Catalan_disdyakis_triacontahedron_verts[6],
  Catalan_disdyakis_triacontahedron_verts[7],
  Catalan_disdyakis_triacontahedron_verts[8],
  Catalan_disdyakis_triacontahedron_verts[9],
  Catalan_disdyakis_triacontahedron_verts[10],
  Catalan_disdyakis_triacontahedron_verts[11],
  Catalan_disdyakis_triacontahedron_verts[12],
  Catalan_disdyakis_triacontahedron_verts[13],
  Catalan_disdyakis_triacontahedron_verts[14],
  Catalan_disdyakis_triacontahedron_verts[15],
  Catalan_disdyakis_triacontahedron_verts[16],
  Catalan_disdyakis_triacontahedron_verts[17],
  Catalan_disdyakis_triacontahedron_verts[18],
  Catalan_disdyakis_triacontahedron_verts[19],
  Catalan_disdyakis_triacontahedron_verts[20],
  Catalan_disdyakis_triacontahedron_verts[21],
  Catalan_disdyakis_triacontahedron_verts[22],
  Catalan_disdyakis_triacontahedron_verts[23],
  Catalan_disdyakis_triacontahedron_verts[24],
  Catalan_disdyakis_triacontahedron_verts[25],
  Catalan_disdyakis_triacontahedron_verts[26],
  Catalan_disdyakis_triacontahedron_verts[27],
  Catalan_disdyakis_triacontahedron_verts[28],
  Catalan_disdyakis_triacontahedron_verts[29],
  Catalan_disdyakis_triacontahedron_verts[30],
  Catalan_disdyakis_triacontahedron_verts[31],
  Catalan_disdyakis_triacontahedron_verts[32],
  Catalan_disdyakis_triacontahedron_verts[33],
  Catalan_disdyakis_triacontahedron_verts[34],
  Catalan_disdyakis_triacontahedron_verts[35],
  Catalan_disdyakis_triacontahedron_verts[36],
  Catalan_disdyakis_triacontahedron_verts[37],
  Catalan_disdyakis_triacontahedron_verts[38],
  Catalan_disdyakis_triacontahedron_verts[39],
  Catalan_disdyakis_triacontahedron_verts[40],
  Catalan_disdyakis_triacontahedron_verts[41],
  Catalan_disdyakis_triacontahedron_verts[42],
  Catalan_disdyakis_triacontahedron_verts[43],
  Catalan_disdyakis_triacontahedron_verts[44],
  Catalan_disdyakis_triacontahedron_verts[45],
  Catalan_disdyakis_triacontahedron_verts[46],
  Catalan_disdyakis_triacontahedron_verts[47],
  Catalan_disdyakis_triacontahedron_verts[48],
  Catalan_disdyakis_triacontahedron_verts[49],
  Catalan_disdyakis_triacontahedron_verts[50],
  Catalan_disdyakis_triacontahedron_verts[51],
  Catalan_disdyakis_triacontahedron_verts[52],
  Catalan_disdyakis_triacontahedron_verts[53],
  Catalan_disdyakis_triacontahedron_verts[54],
  Catalan_disdyakis_triacontahedron_verts[55],
  Catalan_disdyakis_triacontahedron_verts[56],
  Catalan_disdyakis_triacontahedron_verts[57],
  Catalan_disdyakis_triacontahedron_verts[58],
  Catalan_disdyakis_triacontahedron_verts[59],
  Catalan_disdyakis_triacontahedron_verts[60],
  Catalan_disdyakis_triacontahedron_verts[61]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  120,
  <2, 0, 1>, 0,
  <2, 3, 0>, 0,
  <0, 4, 1>, 0,
  <1, 5, 2>, 0,
  <0, 3, 4>, 0,
  <3, 2, 6>, 0,
  <1, 4, 7>, 0,
  <2, 5, 8>, 0,
  <5, 1, 9>, 0,
  <3, 10, 4>, 0,
  <2, 11, 6>, 0,
  <6, 12, 3>, 0,
  <4, 13, 7>, 0,
  <7, 9, 1>, 0,
  <5, 9, 8>, 0,
  <8, 14, 2>, 0,
  <4, 10, 15>, 0,
  <10, 3, 12>, 0,
  <6, 11, 12>, 0,
  <11, 2, 16>, 0,
  <7, 13, 9>, 0,
  <13, 4, 17>, 0,
  <8, 9, 18>, 0,
  <2, 14, 19>, 0,
  <14, 8, 20>, 0,
  <10, 12, 15>, 0,
  <15, 21, 4>, 0,
  <11, 22, 12>, 0,
  <2, 19, 16>, 0,
  <16, 23, 11>, 0,
  <13, 24, 9>, 0,
  <4, 25, 17>, 0,
  <17, 26, 13>, 0,
  <9, 27, 18>, 0,
  <18, 20, 8>, 0,
  <14, 20, 19>, 0,
  <15, 12, 28>, 0,
  <4, 21, 25>, 0,
  <21, 15, 29>, 0,
  <12, 22, 30>, 0,
  <22, 11, 23>, 0,
  <16, 19, 23>, 0,
  <9, 24, 31>, 0,
  <24, 13, 26>, 0,
  <17, 25, 26>, 0,
  <18, 27, 20>, 0,
  <27, 9, 32>, 0,
  <19, 20, 33>, 0,
  <12, 34, 28>, 0,
  <28, 29, 15>, 0,
  <21, 29, 25>, 0,
  <22, 23, 30>, 0,
  <30, 35, 12>, 0,
  <19, 33, 23>, 0,
  <24, 26, 31>, 0,
  <31, 32, 9>, 0,
  <25, 36, 26>, 0,
  <27, 37, 20>, 0,
  <32, 38, 27>, 0,
  <20, 39, 33>, 0,
  <28, 34, 29>, 0,
  <34, 12, 35>, 0,
  <25, 29, 36>, 0,
  <30, 23, 40>, 0,
  <35, 30, 41>, 0,
  <23, 33, 39>, 0,
  <31, 26, 42>, 0,
  <32, 31, 38>, 0,
  <26, 36, 43>, 0,
  <20, 37, 44>, 0,
  <37, 27, 38>, 0,
  <39, 20, 45>, 0,
  <34, 46, 29>, 0,
  <35, 41, 34>, 0,
  <29, 43, 36>, 0,
  <23, 47, 40>, 0,
  <40, 41, 30>, 0,
  <39, 48, 23>, 0,
  <26, 49, 42>, 0,
  <42, 38, 31>, 0,
  <43, 50, 26>, 0,
  <37, 38, 44>, 0,
  <44, 45, 20>, 0,
  <45, 51, 39>, 0,
  <29, 46, 52>, 0,
  <46, 34, 41>, 0,
  <43, 29, 53>, 0,
  <40, 47, 41>, 0,
  <47, 23, 48>, 0,
  <48, 39, 51>, 0,
  <42, 49, 38>, 0,
  <49, 26, 50>, 0,
  <50, 43, 54>, 0,
  <44, 38, 55>, 0,
  <45, 44, 51>, 0,
  <46, 41, 52>, 0,
  <52, 53, 29>, 0,
  <53, 54, 43>, 0,
  <47, 56, 41>, 0,
  <48, 51, 47>, 0,
  <49, 57, 38>, 0,
  <50, 54, 49>, 0,
  <38, 58, 55>, 0,
  <55, 51, 44>, 0,
  <52, 41, 59>, 0,
  <53, 52, 54>, 0,
  <41, 56, 60>, 0,
  <56, 47, 51>, 0,
  <38, 57, 58>, 0,
  <57, 49, 54>, 0,
  <55, 58, 51>, 0,
  <41, 60, 59>, 0,
  <59, 54, 52>, 0,
  <56, 51, 60>, 0,
  <57, 54, 58>, 0,
  <58, 61, 51>, 0,
  <59, 60, 54>, 0,
  <60, 51, 61>, 0,
  <58, 54, 61>, 0,
  <60, 61, 54>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_disdyakis_triacontahedron_verts[60];
 #local P1 = Catalan_disdyakis_triacontahedron_verts[61];
 #local P2 = Catalan_disdyakis_triacontahedron_verts[54];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_disdyakis_triacontahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_disdyakis_triacontahedron_obj }
#end
#end

#macro Catalan_disdyakis_triacontahedron_faces2(OnPlane)
#local Catalan_disdyakis_triacontahedron_obj = mesh2 {
 vertex_vectors {
  62,
  Catalan_disdyakis_triacontahedron_verts[0],
  Catalan_disdyakis_triacontahedron_verts[1],
  Catalan_disdyakis_triacontahedron_verts[2],
  Catalan_disdyakis_triacontahedron_verts[3],
  Catalan_disdyakis_triacontahedron_verts[4],
  Catalan_disdyakis_triacontahedron_verts[5],
  Catalan_disdyakis_triacontahedron_verts[6],
  Catalan_disdyakis_triacontahedron_verts[7],
  Catalan_disdyakis_triacontahedron_verts[8],
  Catalan_disdyakis_triacontahedron_verts[9],
  Catalan_disdyakis_triacontahedron_verts[10],
  Catalan_disdyakis_triacontahedron_verts[11],
  Catalan_disdyakis_triacontahedron_verts[12],
  Catalan_disdyakis_triacontahedron_verts[13],
  Catalan_disdyakis_triacontahedron_verts[14],
  Catalan_disdyakis_triacontahedron_verts[15],
  Catalan_disdyakis_triacontahedron_verts[16],
  Catalan_disdyakis_triacontahedron_verts[17],
  Catalan_disdyakis_triacontahedron_verts[18],
  Catalan_disdyakis_triacontahedron_verts[19],
  Catalan_disdyakis_triacontahedron_verts[20],
  Catalan_disdyakis_triacontahedron_verts[21],
  Catalan_disdyakis_triacontahedron_verts[22],
  Catalan_disdyakis_triacontahedron_verts[23],
  Catalan_disdyakis_triacontahedron_verts[24],
  Catalan_disdyakis_triacontahedron_verts[25],
  Catalan_disdyakis_triacontahedron_verts[26],
  Catalan_disdyakis_triacontahedron_verts[27],
  Catalan_disdyakis_triacontahedron_verts[28],
  Catalan_disdyakis_triacontahedron_verts[29],
  Catalan_disdyakis_triacontahedron_verts[30],
  Catalan_disdyakis_triacontahedron_verts[31],
  Catalan_disdyakis_triacontahedron_verts[32],
  Catalan_disdyakis_triacontahedron_verts[33],
  Catalan_disdyakis_triacontahedron_verts[34],
  Catalan_disdyakis_triacontahedron_verts[35],
  Catalan_disdyakis_triacontahedron_verts[36],
  Catalan_disdyakis_triacontahedron_verts[37],
  Catalan_disdyakis_triacontahedron_verts[38],
  Catalan_disdyakis_triacontahedron_verts[39],
  Catalan_disdyakis_triacontahedron_verts[40],
  Catalan_disdyakis_triacontahedron_verts[41],
  Catalan_disdyakis_triacontahedron_verts[42],
  Catalan_disdyakis_triacontahedron_verts[43],
  Catalan_disdyakis_triacontahedron_verts[44],
  Catalan_disdyakis_triacontahedron_verts[45],
  Catalan_disdyakis_triacontahedron_verts[46],
  Catalan_disdyakis_triacontahedron_verts[47],
  Catalan_disdyakis_triacontahedron_verts[48],
  Catalan_disdyakis_triacontahedron_verts[49],
  Catalan_disdyakis_triacontahedron_verts[50],
  Catalan_disdyakis_triacontahedron_verts[51],
  Catalan_disdyakis_triacontahedron_verts[52],
  Catalan_disdyakis_triacontahedron_verts[53],
  Catalan_disdyakis_triacontahedron_verts[54],
  Catalan_disdyakis_triacontahedron_verts[55],
  Catalan_disdyakis_triacontahedron_verts[56],
  Catalan_disdyakis_triacontahedron_verts[57],
  Catalan_disdyakis_triacontahedron_verts[58],
  Catalan_disdyakis_triacontahedron_verts[59],
  Catalan_disdyakis_triacontahedron_verts[60],
  Catalan_disdyakis_triacontahedron_verts[61]
 }
 face_indices {
  120,
  <2, 0, 1>,
  <2, 3, 0>,
  <0, 4, 1>,
  <1, 5, 2>,
  <0, 3, 4>,
  <3, 2, 6>,
  <1, 4, 7>,
  <2, 5, 8>,
  <5, 1, 9>,
  <3, 10, 4>,
  <2, 11, 6>,
  <6, 12, 3>,
  <4, 13, 7>,
  <7, 9, 1>,
  <5, 9, 8>,
  <8, 14, 2>,
  <4, 10, 15>,
  <10, 3, 12>,
  <6, 11, 12>,
  <11, 2, 16>,
  <7, 13, 9>,
  <13, 4, 17>,
  <8, 9, 18>,
  <2, 14, 19>,
  <14, 8, 20>,
  <10, 12, 15>,
  <15, 21, 4>,
  <11, 22, 12>,
  <2, 19, 16>,
  <16, 23, 11>,
  <13, 24, 9>,
  <4, 25, 17>,
  <17, 26, 13>,
  <9, 27, 18>,
  <18, 20, 8>,
  <14, 20, 19>,
  <15, 12, 28>,
  <4, 21, 25>,
  <21, 15, 29>,
  <12, 22, 30>,
  <22, 11, 23>,
  <16, 19, 23>,
  <9, 24, 31>,
  <24, 13, 26>,
  <17, 25, 26>,
  <18, 27, 20>,
  <27, 9, 32>,
  <19, 20, 33>,
  <12, 34, 28>,
  <28, 29, 15>,
  <21, 29, 25>,
  <22, 23, 30>,
  <30, 35, 12>,
  <19, 33, 23>,
  <24, 26, 31>,
  <31, 32, 9>,
  <25, 36, 26>,
  <27, 37, 20>,
  <32, 38, 27>,
  <20, 39, 33>,
  <28, 34, 29>,
  <34, 12, 35>,
  <25, 29, 36>,
  <30, 23, 40>,
  <35, 30, 41>,
  <23, 33, 39>,
  <31, 26, 42>,
  <32, 31, 38>,
  <26, 36, 43>,
  <20, 37, 44>,
  <37, 27, 38>,
  <39, 20, 45>,
  <34, 46, 29>,
  <35, 41, 34>,
  <29, 43, 36>,
  <23, 47, 40>,
  <40, 41, 30>,
  <39, 48, 23>,
  <26, 49, 42>,
  <42, 38, 31>,
  <43, 50, 26>,
  <37, 38, 44>,
  <44, 45, 20>,
  <45, 51, 39>,
  <29, 46, 52>,
  <46, 34, 41>,
  <43, 29, 53>,
  <40, 47, 41>,
  <47, 23, 48>,
  <48, 39, 51>,
  <42, 49, 38>,
  <49, 26, 50>,
  <50, 43, 54>,
  <44, 38, 55>,
  <45, 44, 51>,
  <46, 41, 52>,
  <52, 53, 29>,
  <53, 54, 43>,
  <47, 56, 41>,
  <48, 51, 47>,
  <49, 57, 38>,
  <50, 54, 49>,
  <38, 58, 55>,
  <55, 51, 44>,
  <52, 41, 59>,
  <53, 52, 54>,
  <41, 56, 60>,
  <56, 47, 51>,
  <38, 57, 58>,
  <57, 49, 54>,
  <55, 58, 51>,
  <41, 60, 59>,
  <59, 54, 52>,
  <56, 51, 60>,
  <57, 54, 58>,
  <58, 61, 51>,
  <59, 60, 54>,
  <60, 51, 61>,
  <58, 54, 61>,
  <60, 61, 54>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_disdyakis_triacontahedron_verts[60];
 #local P1 = Catalan_disdyakis_triacontahedron_verts[61];
 #local P2 = Catalan_disdyakis_triacontahedron_verts[54];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_disdyakis_triacontahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_disdyakis_triacontahedron_obj }
#end
#end

#macro Catalan_disdyakis_triacontahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_disdyakis_triacontahedron_verts[0], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[1], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[2], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[3], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[4], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[5], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[6], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[7], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[8], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[9], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[10], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[11], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[12], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[13], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[14], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[15], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[16], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[17], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[18], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[19], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[20], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[21], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[22], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[23], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[24], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[25], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[26], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[27], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[28], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[29], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[30], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[31], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[32], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[33], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[34], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[35], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[36], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[37], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[38], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[39], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[40], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[41], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[42], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[43], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[44], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[45], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[46], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[47], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[48], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[49], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[50], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[51], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[52], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[53], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[54], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[55], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[56], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[57], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[58], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[59], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[60], RadVer }
  sphere { Catalan_disdyakis_triacontahedron_verts[61], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_disdyakis_triacontahedron_verts[2], Catalan_disdyakis_triacontahedron_verts[0], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[0], Catalan_disdyakis_triacontahedron_verts[1], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[1], Catalan_disdyakis_triacontahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[2], Catalan_disdyakis_triacontahedron_verts[3], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[3], Catalan_disdyakis_triacontahedron_verts[0], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[0], Catalan_disdyakis_triacontahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[4], Catalan_disdyakis_triacontahedron_verts[1], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[1], Catalan_disdyakis_triacontahedron_verts[5], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[5], Catalan_disdyakis_triacontahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[3], Catalan_disdyakis_triacontahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[2], Catalan_disdyakis_triacontahedron_verts[6], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[6], Catalan_disdyakis_triacontahedron_verts[3], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[4], Catalan_disdyakis_triacontahedron_verts[7], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[7], Catalan_disdyakis_triacontahedron_verts[1], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[5], Catalan_disdyakis_triacontahedron_verts[8], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[8], Catalan_disdyakis_triacontahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[1], Catalan_disdyakis_triacontahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[9], Catalan_disdyakis_triacontahedron_verts[5], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[3], Catalan_disdyakis_triacontahedron_verts[10], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[10], Catalan_disdyakis_triacontahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[2], Catalan_disdyakis_triacontahedron_verts[11], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[11], Catalan_disdyakis_triacontahedron_verts[6], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[6], Catalan_disdyakis_triacontahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[12], Catalan_disdyakis_triacontahedron_verts[3], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[4], Catalan_disdyakis_triacontahedron_verts[13], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[13], Catalan_disdyakis_triacontahedron_verts[7], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[7], Catalan_disdyakis_triacontahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[9], Catalan_disdyakis_triacontahedron_verts[8], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[8], Catalan_disdyakis_triacontahedron_verts[14], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[14], Catalan_disdyakis_triacontahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[10], Catalan_disdyakis_triacontahedron_verts[15], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[15], Catalan_disdyakis_triacontahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[12], Catalan_disdyakis_triacontahedron_verts[10], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[11], Catalan_disdyakis_triacontahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[2], Catalan_disdyakis_triacontahedron_verts[16], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[16], Catalan_disdyakis_triacontahedron_verts[11], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[13], Catalan_disdyakis_triacontahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[4], Catalan_disdyakis_triacontahedron_verts[17], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[17], Catalan_disdyakis_triacontahedron_verts[13], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[9], Catalan_disdyakis_triacontahedron_verts[18], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[18], Catalan_disdyakis_triacontahedron_verts[8], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[14], Catalan_disdyakis_triacontahedron_verts[19], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[19], Catalan_disdyakis_triacontahedron_verts[2], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[8], Catalan_disdyakis_triacontahedron_verts[20], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[20], Catalan_disdyakis_triacontahedron_verts[14], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[12], Catalan_disdyakis_triacontahedron_verts[15], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[15], Catalan_disdyakis_triacontahedron_verts[21], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[21], Catalan_disdyakis_triacontahedron_verts[4], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[11], Catalan_disdyakis_triacontahedron_verts[22], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[22], Catalan_disdyakis_triacontahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[19], Catalan_disdyakis_triacontahedron_verts[16], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[16], Catalan_disdyakis_triacontahedron_verts[23], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[23], Catalan_disdyakis_triacontahedron_verts[11], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[13], Catalan_disdyakis_triacontahedron_verts[24], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[24], Catalan_disdyakis_triacontahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[4], Catalan_disdyakis_triacontahedron_verts[25], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[25], Catalan_disdyakis_triacontahedron_verts[17], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[17], Catalan_disdyakis_triacontahedron_verts[26], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[26], Catalan_disdyakis_triacontahedron_verts[13], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[9], Catalan_disdyakis_triacontahedron_verts[27], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[27], Catalan_disdyakis_triacontahedron_verts[18], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[18], Catalan_disdyakis_triacontahedron_verts[20], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[20], Catalan_disdyakis_triacontahedron_verts[19], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[12], Catalan_disdyakis_triacontahedron_verts[28], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[28], Catalan_disdyakis_triacontahedron_verts[15], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[21], Catalan_disdyakis_triacontahedron_verts[25], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[15], Catalan_disdyakis_triacontahedron_verts[29], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[29], Catalan_disdyakis_triacontahedron_verts[21], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[22], Catalan_disdyakis_triacontahedron_verts[30], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[30], Catalan_disdyakis_triacontahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[23], Catalan_disdyakis_triacontahedron_verts[22], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[19], Catalan_disdyakis_triacontahedron_verts[23], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[24], Catalan_disdyakis_triacontahedron_verts[31], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[31], Catalan_disdyakis_triacontahedron_verts[9], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[26], Catalan_disdyakis_triacontahedron_verts[24], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[25], Catalan_disdyakis_triacontahedron_verts[26], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[27], Catalan_disdyakis_triacontahedron_verts[20], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[9], Catalan_disdyakis_triacontahedron_verts[32], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[32], Catalan_disdyakis_triacontahedron_verts[27], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[20], Catalan_disdyakis_triacontahedron_verts[33], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[33], Catalan_disdyakis_triacontahedron_verts[19], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[12], Catalan_disdyakis_triacontahedron_verts[34], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[34], Catalan_disdyakis_triacontahedron_verts[28], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[28], Catalan_disdyakis_triacontahedron_verts[29], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[29], Catalan_disdyakis_triacontahedron_verts[25], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[23], Catalan_disdyakis_triacontahedron_verts[30], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[30], Catalan_disdyakis_triacontahedron_verts[35], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[35], Catalan_disdyakis_triacontahedron_verts[12], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[33], Catalan_disdyakis_triacontahedron_verts[23], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[26], Catalan_disdyakis_triacontahedron_verts[31], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[31], Catalan_disdyakis_triacontahedron_verts[32], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[25], Catalan_disdyakis_triacontahedron_verts[36], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[36], Catalan_disdyakis_triacontahedron_verts[26], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[27], Catalan_disdyakis_triacontahedron_verts[37], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[37], Catalan_disdyakis_triacontahedron_verts[20], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[32], Catalan_disdyakis_triacontahedron_verts[38], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[38], Catalan_disdyakis_triacontahedron_verts[27], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[20], Catalan_disdyakis_triacontahedron_verts[39], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[39], Catalan_disdyakis_triacontahedron_verts[33], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[34], Catalan_disdyakis_triacontahedron_verts[29], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[35], Catalan_disdyakis_triacontahedron_verts[34], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[29], Catalan_disdyakis_triacontahedron_verts[36], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[23], Catalan_disdyakis_triacontahedron_verts[40], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[40], Catalan_disdyakis_triacontahedron_verts[30], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[30], Catalan_disdyakis_triacontahedron_verts[41], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[41], Catalan_disdyakis_triacontahedron_verts[35], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[39], Catalan_disdyakis_triacontahedron_verts[23], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[26], Catalan_disdyakis_triacontahedron_verts[42], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[42], Catalan_disdyakis_triacontahedron_verts[31], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[31], Catalan_disdyakis_triacontahedron_verts[38], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[36], Catalan_disdyakis_triacontahedron_verts[43], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[43], Catalan_disdyakis_triacontahedron_verts[26], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[37], Catalan_disdyakis_triacontahedron_verts[44], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[44], Catalan_disdyakis_triacontahedron_verts[20], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[38], Catalan_disdyakis_triacontahedron_verts[37], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[20], Catalan_disdyakis_triacontahedron_verts[45], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[45], Catalan_disdyakis_triacontahedron_verts[39], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[34], Catalan_disdyakis_triacontahedron_verts[46], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[46], Catalan_disdyakis_triacontahedron_verts[29], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[41], Catalan_disdyakis_triacontahedron_verts[34], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[29], Catalan_disdyakis_triacontahedron_verts[43], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[23], Catalan_disdyakis_triacontahedron_verts[47], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[47], Catalan_disdyakis_triacontahedron_verts[40], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[40], Catalan_disdyakis_triacontahedron_verts[41], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[39], Catalan_disdyakis_triacontahedron_verts[48], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[48], Catalan_disdyakis_triacontahedron_verts[23], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[26], Catalan_disdyakis_triacontahedron_verts[49], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[49], Catalan_disdyakis_triacontahedron_verts[42], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[42], Catalan_disdyakis_triacontahedron_verts[38], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[43], Catalan_disdyakis_triacontahedron_verts[50], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[50], Catalan_disdyakis_triacontahedron_verts[26], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[38], Catalan_disdyakis_triacontahedron_verts[44], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[44], Catalan_disdyakis_triacontahedron_verts[45], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[45], Catalan_disdyakis_triacontahedron_verts[51], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[51], Catalan_disdyakis_triacontahedron_verts[39], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[46], Catalan_disdyakis_triacontahedron_verts[52], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[52], Catalan_disdyakis_triacontahedron_verts[29], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[41], Catalan_disdyakis_triacontahedron_verts[46], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[29], Catalan_disdyakis_triacontahedron_verts[53], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[53], Catalan_disdyakis_triacontahedron_verts[43], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[47], Catalan_disdyakis_triacontahedron_verts[41], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[48], Catalan_disdyakis_triacontahedron_verts[47], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[51], Catalan_disdyakis_triacontahedron_verts[48], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[49], Catalan_disdyakis_triacontahedron_verts[38], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[50], Catalan_disdyakis_triacontahedron_verts[49], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[43], Catalan_disdyakis_triacontahedron_verts[54], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[54], Catalan_disdyakis_triacontahedron_verts[50], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[38], Catalan_disdyakis_triacontahedron_verts[55], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[55], Catalan_disdyakis_triacontahedron_verts[44], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[44], Catalan_disdyakis_triacontahedron_verts[51], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[41], Catalan_disdyakis_triacontahedron_verts[52], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[52], Catalan_disdyakis_triacontahedron_verts[53], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[53], Catalan_disdyakis_triacontahedron_verts[54], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[47], Catalan_disdyakis_triacontahedron_verts[56], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[56], Catalan_disdyakis_triacontahedron_verts[41], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[51], Catalan_disdyakis_triacontahedron_verts[47], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[49], Catalan_disdyakis_triacontahedron_verts[57], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[57], Catalan_disdyakis_triacontahedron_verts[38], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[54], Catalan_disdyakis_triacontahedron_verts[49], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[38], Catalan_disdyakis_triacontahedron_verts[58], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[58], Catalan_disdyakis_triacontahedron_verts[55], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[55], Catalan_disdyakis_triacontahedron_verts[51], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[41], Catalan_disdyakis_triacontahedron_verts[59], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[59], Catalan_disdyakis_triacontahedron_verts[52], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[52], Catalan_disdyakis_triacontahedron_verts[54], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[56], Catalan_disdyakis_triacontahedron_verts[60], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[60], Catalan_disdyakis_triacontahedron_verts[41], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[51], Catalan_disdyakis_triacontahedron_verts[56], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[57], Catalan_disdyakis_triacontahedron_verts[58], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[54], Catalan_disdyakis_triacontahedron_verts[57], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[58], Catalan_disdyakis_triacontahedron_verts[51], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[60], Catalan_disdyakis_triacontahedron_verts[59], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[59], Catalan_disdyakis_triacontahedron_verts[54], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[51], Catalan_disdyakis_triacontahedron_verts[60], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[54], Catalan_disdyakis_triacontahedron_verts[58], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[58], Catalan_disdyakis_triacontahedron_verts[61], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[61], Catalan_disdyakis_triacontahedron_verts[51], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[60], Catalan_disdyakis_triacontahedron_verts[54], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[61], Catalan_disdyakis_triacontahedron_verts[60], RadEdg }
  cylinder { Catalan_disdyakis_triacontahedron_verts[54], Catalan_disdyakis_triacontahedron_verts[61], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_disdyakis_triacontahedron_verts[60];
 #local P1 = Catalan_disdyakis_triacontahedron_verts[61];
 #local P2 = Catalan_disdyakis_triacontahedron_verts[54];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Catalan_pentagonal_hexecontahedron_verts = array[92]
{
<0.2319284, 0.1389806, 0.9727329>,
<-0.01318484, 0.2700603, 0.9727329>,
<-0.2443637, 0.1157271, 0.9727329>,
<-0.2172871, -0.1609121, 0.9727329>,
<0.2319284, -0.3474105, 0.9727329>,
<0.6328167, -0.1609121, 0.7700428>,
<0.6569803, 0.1157271, 0.7578256>,
<0.450672, 0.2700603, 0.8621356>,
<0.4118671, 0.524768, 0.7578256>,
<-0.03494478, 0.7157612, 0.7792039>,
<-0.4610267, 0.4821517, 0.7578256>,
<-0.4748357, 0.2248753, 0.8621356>,
<-0.807821, -0.07906707, 0.6796085>,
<-0.4222218, -0.3126766, 0.8621356>,
<-0.3587899, -0.5623929, 0.7578256>,
<-0.09402938, -0.6461487, 0.7700428>,
<0.4313637, -0.6461487, 0.6447735>,
<0.6621283, -0.5623929, 0.5144084>,
<0.7658016, -0.3126766, 0.5788755>,
<0.9153902, -0.1791742, 0.3863585>,
<0.9295636, 0.3067204, 0.4031479>,
<0.5815764, 0.6106627, 0.5551356>,
<0.4862954, 0.8008226, 0.3761854>,
<0.2267217, 0.8942775, 0.4100984>
<-0.3127563, 0.8679392, 0.4100984>,
<-0.561992, 0.7496433, 0.3761854>,
<-0.6382961, 0.5511063, 0.5551356>,
<-0.8192969, 0.3588645, 0.4682782>,
<-0.7341657, -0.5109127, 0.4682782>,
<-0.519325, -0.6644108, 0.5551356>,
<-0.3209764, -0.9793389, 0.2419992>,
<-0.00485529, -0.8271609, 0.5788755>,
<0.2655267, -0.8271609, 0.5144084>,
<0.3398819, -0.9141271, 0.2610892>,
<0.7527863, -0.7409091, 0.07113717>,
<0.9528016, -0.3029775, 0.1403188>,
<0.9961858, -0.1420654, -0.08213905>,
<0.9996924, 0.1335024, -0.04591079>,
<0.7933841, 0.6216485, 0.05839917>,
<0.5952976, 0.8064762, 0.120551>,
<0.3209764, 0.9793389, -0.2419992>,
<0.09090658, 0.9880731, 0.186449>,
<-0.1867239, 0.9745186, 0.186449>,
<-0.3170919, 0.9567434, -0.05839917>,
<-0.7527863, 0.7409091, -0.07113717>,
<-0.9137039, 0.3760884, 0.2074084>,
<-0.9961858, 0.1420654, 0.08213905>,
<-0.9795717, -0.09587751, 0.2248609>,
<-0.9497342, -0.3325262, 0.08213905>,
<-0.8234415, -0.5461149, 0.2074084>,
<-0.6928012, -0.732814, 0.04822608>,
<0.1396282, -0.9961493, 0.08663801>,
<0.1867239, -0.9745186, -0.186449>,
<0.431396, -0.8720954, -0.2695602>,
<0.8102012, -0.4943842, -0.3442004>,
<0.9227997, -0.2405687, -0.3314862>,
<0.807821, 0.07906707, -0.6796085>,
<0.9296135, 0.2949013, -0.2610892>,
<0.8234415, 0.5461149, -0.2074084>,
<0.6537036, 0.6597031, -0.3959533>,
<-0.1624182, 0.953533, -0.289328>,
<-0.2655267, 0.8271609, -0.5144084>,
<-0.5174473, 0.7111833, -0.4957643>,
<-0.8861738, 0.3523188, -0.3314862>,
<-0.982018, 0.1298329, -0.1951912>,
<-0.9295636, -0.3067204, -0.4031479>,
<-0.6958805, -0.6953107, -0.2271762>,
<-0.4862954, -0.8008226, -0.3761854>,
<-0.2855458, -0.9378397, -0.2413213>,
<-0.03208251, -0.9445109, -0.3552261>,
<0.03494478, -0.7157612, -0.7792039>,
<0.4433524, -0.7454871, -0.5167237>,
<0.6382961, -0.5511063, -0.5551356>,
<0.5887621, -0.3507883, -0.7413652>,
<0.5997871, 0.5156204, -0.6274605>,
<0.3587899, 0.5623929, -0.7578256>,
<0.1854095, 0.7505892, -0.6492725>,
<-0.08652481, 0.7227204, -0.6996458>,
<-0.2319284, 0.3474105, -0.9727329>,
<-0.5760447, 0.4973583, -0.6634176>,
<-0.7658016, 0.3126766, -0.5788755>,
<-0.7481168, 0.05280211, -0.675906>,
<-0.571274, -0.4571647, -0.6956738>,
<-0.4221694, -0.678266, -0.6172874>,
<0.3471003, -0.3562388, -0.878596>,
<0.2443637, -0.1157271, -0.9727329>,
<0.3891294, 0.1165623, -0.9242874>,
<0.2503795, 0.3570264, -0.910581>,
<-0.5416803, -0.007617117, -0.8519625>,
<-0.450672, -0.2700603, -0.8621356>,
<-0.1878216, -0.3146939, -0.9407478>,
<-0.03092203, -0.09434697, -1.004718>,
}
#local P0 = Catalan_pentagonal_hexecontahedron_verts[88];
#local P1 = Catalan_pentagonal_hexecontahedron_verts[78];
#local P2 = Catalan_pentagonal_hexecontahedron_verts[91];
#local V1 = P1 - P0;
#local V2 = P2 - P0;
#local Axis = vcross(V2, V1);
#local Tran1 = transform { Reorient_Trans(Axis, y) }
#local TV1 = vtransform(V1, Tran1);
#local The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#local Num = 0;
#while (Num < 92)
 #declare Catalan_pentagonal_hexecontahedron_verts[Num] = vtransform(Catalan_pentagonal_hexecontahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro Catalan_pentagonal_hexecontahedron_faces(Tex5, OnPlane)
#local Catalan_pentagonal_hexecontahedron_obj = mesh2 {
 vertex_vectors {
  92,
  Catalan_pentagonal_hexecontahedron_verts[0],
  Catalan_pentagonal_hexecontahedron_verts[1],
  Catalan_pentagonal_hexecontahedron_verts[2],
  Catalan_pentagonal_hexecontahedron_verts[3],
  Catalan_pentagonal_hexecontahedron_verts[4],
  Catalan_pentagonal_hexecontahedron_verts[5],
  Catalan_pentagonal_hexecontahedron_verts[6],
  Catalan_pentagonal_hexecontahedron_verts[7],
  Catalan_pentagonal_hexecontahedron_verts[8],
  Catalan_pentagonal_hexecontahedron_verts[9],
  Catalan_pentagonal_hexecontahedron_verts[10],
  Catalan_pentagonal_hexecontahedron_verts[11],
  Catalan_pentagonal_hexecontahedron_verts[12],
  Catalan_pentagonal_hexecontahedron_verts[13],
  Catalan_pentagonal_hexecontahedron_verts[14],
  Catalan_pentagonal_hexecontahedron_verts[15],
  Catalan_pentagonal_hexecontahedron_verts[16],
  Catalan_pentagonal_hexecontahedron_verts[17],
  Catalan_pentagonal_hexecontahedron_verts[18],
  Catalan_pentagonal_hexecontahedron_verts[19],
  Catalan_pentagonal_hexecontahedron_verts[20],
  Catalan_pentagonal_hexecontahedron_verts[21],
  Catalan_pentagonal_hexecontahedron_verts[22],
  Catalan_pentagonal_hexecontahedron_verts[23],
  Catalan_pentagonal_hexecontahedron_verts[24],
  Catalan_pentagonal_hexecontahedron_verts[25],
  Catalan_pentagonal_hexecontahedron_verts[26],
  Catalan_pentagonal_hexecontahedron_verts[27],
  Catalan_pentagonal_hexecontahedron_verts[28],
  Catalan_pentagonal_hexecontahedron_verts[29],
  Catalan_pentagonal_hexecontahedron_verts[30],
  Catalan_pentagonal_hexecontahedron_verts[31],
  Catalan_pentagonal_hexecontahedron_verts[32],
  Catalan_pentagonal_hexecontahedron_verts[33],
  Catalan_pentagonal_hexecontahedron_verts[34],
  Catalan_pentagonal_hexecontahedron_verts[35],
  Catalan_pentagonal_hexecontahedron_verts[36],
  Catalan_pentagonal_hexecontahedron_verts[37],
  Catalan_pentagonal_hexecontahedron_verts[38],
  Catalan_pentagonal_hexecontahedron_verts[39],
  Catalan_pentagonal_hexecontahedron_verts[40],
  Catalan_pentagonal_hexecontahedron_verts[41],
  Catalan_pentagonal_hexecontahedron_verts[42],
  Catalan_pentagonal_hexecontahedron_verts[43],
  Catalan_pentagonal_hexecontahedron_verts[44],
  Catalan_pentagonal_hexecontahedron_verts[45],
  Catalan_pentagonal_hexecontahedron_verts[46],
  Catalan_pentagonal_hexecontahedron_verts[47],
  Catalan_pentagonal_hexecontahedron_verts[48],
  Catalan_pentagonal_hexecontahedron_verts[49],
  Catalan_pentagonal_hexecontahedron_verts[50],
  Catalan_pentagonal_hexecontahedron_verts[51],
  Catalan_pentagonal_hexecontahedron_verts[52],
  Catalan_pentagonal_hexecontahedron_verts[53],
  Catalan_pentagonal_hexecontahedron_verts[54],
  Catalan_pentagonal_hexecontahedron_verts[55],
  Catalan_pentagonal_hexecontahedron_verts[56],
  Catalan_pentagonal_hexecontahedron_verts[57],
  Catalan_pentagonal_hexecontahedron_verts[58],
  Catalan_pentagonal_hexecontahedron_verts[59],
  Catalan_pentagonal_hexecontahedron_verts[60],
  Catalan_pentagonal_hexecontahedron_verts[61],
  Catalan_pentagonal_hexecontahedron_verts[62],
  Catalan_pentagonal_hexecontahedron_verts[63],
  Catalan_pentagonal_hexecontahedron_verts[64],
  Catalan_pentagonal_hexecontahedron_verts[65],
  Catalan_pentagonal_hexecontahedron_verts[66],
  Catalan_pentagonal_hexecontahedron_verts[67],
  Catalan_pentagonal_hexecontahedron_verts[68],
  Catalan_pentagonal_hexecontahedron_verts[69],
  Catalan_pentagonal_hexecontahedron_verts[70],
  Catalan_pentagonal_hexecontahedron_verts[71],
  Catalan_pentagonal_hexecontahedron_verts[72],
  Catalan_pentagonal_hexecontahedron_verts[73],
  Catalan_pentagonal_hexecontahedron_verts[74],
  Catalan_pentagonal_hexecontahedron_verts[75],
  Catalan_pentagonal_hexecontahedron_verts[76],
  Catalan_pentagonal_hexecontahedron_verts[77],
  Catalan_pentagonal_hexecontahedron_verts[78],
  Catalan_pentagonal_hexecontahedron_verts[79],
  Catalan_pentagonal_hexecontahedron_verts[80],
  Catalan_pentagonal_hexecontahedron_verts[81],
  Catalan_pentagonal_hexecontahedron_verts[82],
  Catalan_pentagonal_hexecontahedron_verts[83],
  Catalan_pentagonal_hexecontahedron_verts[84],
  Catalan_pentagonal_hexecontahedron_verts[85],
  Catalan_pentagonal_hexecontahedron_verts[86],
  Catalan_pentagonal_hexecontahedron_verts[87],
  Catalan_pentagonal_hexecontahedron_verts[88],
  Catalan_pentagonal_hexecontahedron_verts[89],
  Catalan_pentagonal_hexecontahedron_verts[90],
  Catalan_pentagonal_hexecontahedron_verts[91]
 }
 texture_list {
  1,
  texture { Tex5 }
 }
 face_indices {
  180,
  <4, 0, 1>, 0,
  <4, 1, 2>, 0,
  <4, 2, 3>, 0,
  <0, 4, 5>, 0,
  <0, 5, 6>, 0,
  <0, 6, 7>, 0,
  <1, 0, 7>, 0,
  <1, 7, 8>, 0,
  <1, 8, 9>, 0,
  <2, 1, 9>, 0,
  <2, 9, 10>, 0,
  <2, 10, 11>, 0,
  <3, 2, 11>, 0,
  <3, 11, 12>, 0,
  <3, 12, 13>, 0,
  <4, 3, 13>, 0,
  <4, 13, 14>, 0,
  <4, 14, 15>, 0,
  <5, 4, 16>, 0,
  <5, 16, 17>, 0,
  <5, 17, 18>, 0,
  <6, 5, 18>, 0,
  <6, 18, 19>, 0,
  <6, 19, 20>, 0,
  <7, 6, 20>, 0,
  <7, 20, 21>, 0,
  <7, 21, 8>, 0,
  <9, 8, 21>, 0,
  <9, 21, 22>, 0,
  <9, 22, 23>, 0,
  <10, 9, 24>, 0,
  <10, 24, 25>, 0,
  <10, 25, 26>, 0,
  <11, 10, 26>, 0,
  <11, 26, 27>, 0,
  <11, 27, 12>, 0,
  <13, 12, 28>, 0,
  <13, 28, 29>, 0,
  <13, 29, 14>, 0,
  <15, 14, 29>, 0,
  <15, 29, 30>, 0,
  <15, 30, 31>, 0,
  <4, 15, 31>, 0,
  <4, 31, 32>, 0,
  <4, 32, 16>, 0,
  <17, 16, 32>, 0,
  <17, 32, 33>, 0,
  <17, 33, 34>, 0,
  <18, 17, 34>, 0,
  <18, 34, 35>, 0,
  <18, 35, 19>, 0,
  <20, 19, 35>, 0,
  <20, 35, 36>, 0,
  <20, 36, 37>, 0,
  <21, 20, 38>, 0,
  <21, 38, 39>, 0,
  <21, 39, 22>, 0,
  <23, 22, 39>, 0,
  <23, 39, 40>, 0,
  <23, 40, 41>, 0,
  <9, 23, 41>, 0,
  <9, 41, 42>, 0,
  <9, 42, 24>, 0,
  <25, 24, 42>, 0,
  <25, 42, 43>, 0,
  <25, 43, 44>, 0,
  <26, 25, 44>, 0,
  <26, 44, 45>, 0,
  <26, 45, 27>, 0,
  <12, 27, 45>, 0,
  <12, 45, 46>, 0,
  <12, 46, 47>, 0,
  <28, 12, 47>, 0,
  <28, 47, 48>, 0,
  <28, 48, 49>, 0,
  <29, 28, 49>, 0,
  <29, 49, 50>, 0,
  <29, 50, 30>, 0,
  <31, 30, 51>, 0,
  <31, 51, 33>, 0,
  <31, 33, 32>, 0,
  <34, 33, 51>, 0,
  <34, 51, 52>, 0,
  <34, 52, 53>, 0,
  <35, 34, 54>, 0,
  <35, 54, 55>, 0,
  <35, 55, 36>, 0,
  <37, 36, 55>, 0,
  <37, 55, 56>, 0,
  <37, 56, 57>, 0,
  <20, 37, 57>, 0,
  <20, 57, 58>, 0,
  <20, 58, 38>, 0,
  <39, 38, 58>, 0,
  <39, 58, 59>, 0,
  <39, 59, 40>, 0,
  <41, 40, 60>, 0,
  <41, 60, 43>, 0,
  <41, 43, 42>, 0,
  <44, 43, 60>, 0,
  <44, 60, 61>, 0,
  <44, 61, 62>, 0,
  <45, 44, 63>, 0,
  <45, 63, 64>, 0,
  <45, 64, 46>, 0,
  <47, 46, 64>, 0,
  <47, 64, 65>, 0,
  <47, 65, 48>, 0,
  <49, 48, 65>, 0,
  <49, 65, 66>, 0,
  <49, 66, 50>, 0,
  <30, 50, 66>, 0,
  <30, 66, 67>, 0,
  <30, 67, 68>, 0,
  <51, 30, 68>, 0,
  <51, 68, 69>, 0,
  <51, 69, 52>, 0,
  <53, 52, 69>, 0,
  <53, 69, 70>, 0,
  <53, 70, 71>, 0,
  <34, 53, 71>, 0,
  <34, 71, 72>, 0,
  <34, 72, 54>, 0,
  <55, 54, 72>, 0,
  <55, 72, 73>, 0,
  <55, 73, 56>, 0,
  <57, 56, 74>, 0,
  <57, 74, 59>, 0,
  <57, 59, 58>, 0,
  <40, 59, 74>, 0,
  <40, 74, 75>, 0,
  <40, 75, 76>, 0,
  <60, 40, 76>, 0,
  <60, 76, 77>, 0,
  <60, 77, 61>, 0,
  <62, 61, 77>, 0,
  <62, 77, 78>, 0,
  <62, 78, 79>, 0,
  <44, 62, 79>, 0,
  <44, 79, 80>, 0,
  <44, 80, 63>, 0,
  <64, 63, 80>, 0,
  <64, 80, 81>, 0,
  <64, 81, 65>, 0,
  <66, 65, 82>, 0,
  <66, 82, 83>, 0,
  <66, 83, 67>, 0,
  <68, 67, 83>, 0,
  <68, 83, 70>, 0,
  <68, 70, 69>, 0,
  <71, 70, 84>, 0,
  <71, 84, 73>, 0,
  <71, 73, 72>, 0,
  <56, 73, 84>, 0,
  <56, 84, 85>, 0,
  <56, 85, 86>, 0,
  <74, 56, 86>, 0,
  <74, 86, 87>, 0,
  <74, 87, 75>, 0,
  <76, 75, 87>, 0,
  <76, 87, 78>, 0,
  <76, 78, 77>, 0,
  <79, 78, 88>, 0,
  <79, 88, 81>, 0,
  <79, 81, 80>, 0,
  <65, 81, 88>, 0,
  <65, 88, 89>, 0,
  <65, 89, 82>, 0,
  <83, 82, 89>, 0,
  <83, 89, 90>, 0,
  <83, 90, 70>, 0,
  <84, 70, 90>, 0,
  <84, 90, 91>, 0,
  <84, 91, 85>, 0,
  <86, 85, 91>, 0,
  <86, 91, 78>, 0,
  <86, 78, 87>, 0,
  <88, 78, 91>, 0,
  <88, 91, 90>, 0,
  <88, 90, 89>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_pentagonal_hexecontahedron_verts[88];
 #local P1 = Catalan_pentagonal_hexecontahedron_verts[78];
 #local P2 = Catalan_pentagonal_hexecontahedron_verts[91];
 #local P3 = Catalan_pentagonal_hexecontahedron_verts[90];
 #local P4 = Catalan_pentagonal_hexecontahedron_verts[89];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_pentagonal_hexecontahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_pentagonal_hexecontahedron_obj }
#end
#end

#macro Catalan_pentagonal_hexecontahedron_faces2(OnPlane)
#local Catalan_pentagonal_hexecontahedron_obj = mesh2 {
 vertex_vectors {
  92,
  Catalan_pentagonal_hexecontahedron_verts[0],
  Catalan_pentagonal_hexecontahedron_verts[1],
  Catalan_pentagonal_hexecontahedron_verts[2],
  Catalan_pentagonal_hexecontahedron_verts[3],
  Catalan_pentagonal_hexecontahedron_verts[4],
  Catalan_pentagonal_hexecontahedron_verts[5],
  Catalan_pentagonal_hexecontahedron_verts[6],
  Catalan_pentagonal_hexecontahedron_verts[7],
  Catalan_pentagonal_hexecontahedron_verts[8],
  Catalan_pentagonal_hexecontahedron_verts[9],
  Catalan_pentagonal_hexecontahedron_verts[10],
  Catalan_pentagonal_hexecontahedron_verts[11],
  Catalan_pentagonal_hexecontahedron_verts[12],
  Catalan_pentagonal_hexecontahedron_verts[13],
  Catalan_pentagonal_hexecontahedron_verts[14],
  Catalan_pentagonal_hexecontahedron_verts[15],
  Catalan_pentagonal_hexecontahedron_verts[16],
  Catalan_pentagonal_hexecontahedron_verts[17],
  Catalan_pentagonal_hexecontahedron_verts[18],
  Catalan_pentagonal_hexecontahedron_verts[19],
  Catalan_pentagonal_hexecontahedron_verts[20],
  Catalan_pentagonal_hexecontahedron_verts[21],
  Catalan_pentagonal_hexecontahedron_verts[22],
  Catalan_pentagonal_hexecontahedron_verts[23],
  Catalan_pentagonal_hexecontahedron_verts[24],
  Catalan_pentagonal_hexecontahedron_verts[25],
  Catalan_pentagonal_hexecontahedron_verts[26],
  Catalan_pentagonal_hexecontahedron_verts[27],
  Catalan_pentagonal_hexecontahedron_verts[28],
  Catalan_pentagonal_hexecontahedron_verts[29],
  Catalan_pentagonal_hexecontahedron_verts[30],
  Catalan_pentagonal_hexecontahedron_verts[31],
  Catalan_pentagonal_hexecontahedron_verts[32],
  Catalan_pentagonal_hexecontahedron_verts[33],
  Catalan_pentagonal_hexecontahedron_verts[34],
  Catalan_pentagonal_hexecontahedron_verts[35],
  Catalan_pentagonal_hexecontahedron_verts[36],
  Catalan_pentagonal_hexecontahedron_verts[37],
  Catalan_pentagonal_hexecontahedron_verts[38],
  Catalan_pentagonal_hexecontahedron_verts[39],
  Catalan_pentagonal_hexecontahedron_verts[40],
  Catalan_pentagonal_hexecontahedron_verts[41],
  Catalan_pentagonal_hexecontahedron_verts[42],
  Catalan_pentagonal_hexecontahedron_verts[43],
  Catalan_pentagonal_hexecontahedron_verts[44],
  Catalan_pentagonal_hexecontahedron_verts[45],
  Catalan_pentagonal_hexecontahedron_verts[46],
  Catalan_pentagonal_hexecontahedron_verts[47],
  Catalan_pentagonal_hexecontahedron_verts[48],
  Catalan_pentagonal_hexecontahedron_verts[49],
  Catalan_pentagonal_hexecontahedron_verts[50],
  Catalan_pentagonal_hexecontahedron_verts[51],
  Catalan_pentagonal_hexecontahedron_verts[52],
  Catalan_pentagonal_hexecontahedron_verts[53],
  Catalan_pentagonal_hexecontahedron_verts[54],
  Catalan_pentagonal_hexecontahedron_verts[55],
  Catalan_pentagonal_hexecontahedron_verts[56],
  Catalan_pentagonal_hexecontahedron_verts[57],
  Catalan_pentagonal_hexecontahedron_verts[58],
  Catalan_pentagonal_hexecontahedron_verts[59],
  Catalan_pentagonal_hexecontahedron_verts[60],
  Catalan_pentagonal_hexecontahedron_verts[61],
  Catalan_pentagonal_hexecontahedron_verts[62],
  Catalan_pentagonal_hexecontahedron_verts[63],
  Catalan_pentagonal_hexecontahedron_verts[64],
  Catalan_pentagonal_hexecontahedron_verts[65],
  Catalan_pentagonal_hexecontahedron_verts[66],
  Catalan_pentagonal_hexecontahedron_verts[67],
  Catalan_pentagonal_hexecontahedron_verts[68],
  Catalan_pentagonal_hexecontahedron_verts[69],
  Catalan_pentagonal_hexecontahedron_verts[70],
  Catalan_pentagonal_hexecontahedron_verts[71],
  Catalan_pentagonal_hexecontahedron_verts[72],
  Catalan_pentagonal_hexecontahedron_verts[73],
  Catalan_pentagonal_hexecontahedron_verts[74],
  Catalan_pentagonal_hexecontahedron_verts[75],
  Catalan_pentagonal_hexecontahedron_verts[76],
  Catalan_pentagonal_hexecontahedron_verts[77],
  Catalan_pentagonal_hexecontahedron_verts[78],
  Catalan_pentagonal_hexecontahedron_verts[79],
  Catalan_pentagonal_hexecontahedron_verts[80],
  Catalan_pentagonal_hexecontahedron_verts[81],
  Catalan_pentagonal_hexecontahedron_verts[82],
  Catalan_pentagonal_hexecontahedron_verts[83],
  Catalan_pentagonal_hexecontahedron_verts[84],
  Catalan_pentagonal_hexecontahedron_verts[85],
  Catalan_pentagonal_hexecontahedron_verts[86],
  Catalan_pentagonal_hexecontahedron_verts[87],
  Catalan_pentagonal_hexecontahedron_verts[88],
  Catalan_pentagonal_hexecontahedron_verts[89],
  Catalan_pentagonal_hexecontahedron_verts[90],
  Catalan_pentagonal_hexecontahedron_verts[91]
 }
 face_indices {
  180,
  <4, 0, 1>,
  <4, 1, 2>,
  <4, 2, 3>,
  <0, 4, 5>,
  <0, 5, 6>,
  <0, 6, 7>,
  <1, 0, 7>,
  <1, 7, 8>,
  <1, 8, 9>,
  <2, 1, 9>,
  <2, 9, 10>,
  <2, 10, 11>,
  <3, 2, 11>,
  <3, 11, 12>,
  <3, 12, 13>,
  <4, 3, 13>,
  <4, 13, 14>,
  <4, 14, 15>,
  <5, 4, 16>,
  <5, 16, 17>,
  <5, 17, 18>,
  <6, 5, 18>,
  <6, 18, 19>,
  <6, 19, 20>,
  <7, 6, 20>,
  <7, 20, 21>,
  <7, 21, 8>,
  <9, 8, 21>,
  <9, 21, 22>,
  <9, 22, 23>,
  <10, 9, 24>,
  <10, 24, 25>,
  <10, 25, 26>,
  <11, 10, 26>,
  <11, 26, 27>,
  <11, 27, 12>,
  <13, 12, 28>,
  <13, 28, 29>,
  <13, 29, 14>,
  <15, 14, 29>,
  <15, 29, 30>,
  <15, 30, 31>,
  <4, 15, 31>,
  <4, 31, 32>,
  <4, 32, 16>,
  <17, 16, 32>,
  <17, 32, 33>,
  <17, 33, 34>,
  <18, 17, 34>,
  <18, 34, 35>,
  <18, 35, 19>,
  <20, 19, 35>,
  <20, 35, 36>,
  <20, 36, 37>,
  <21, 20, 38>,
  <21, 38, 39>,
  <21, 39, 22>,
  <23, 22, 39>,
  <23, 39, 40>,
  <23, 40, 41>,
  <9, 23, 41>,
  <9, 41, 42>,
  <9, 42, 24>,
  <25, 24, 42>,
  <25, 42, 43>,
  <25, 43, 44>,
  <26, 25, 44>,
  <26, 44, 45>,
  <26, 45, 27>,
  <12, 27, 45>,
  <12, 45, 46>,
  <12, 46, 47>,
  <28, 12, 47>,
  <28, 47, 48>,
  <28, 48, 49>,
  <29, 28, 49>,
  <29, 49, 50>,
  <29, 50, 30>,
  <31, 30, 51>,
  <31, 51, 33>,
  <31, 33, 32>,
  <34, 33, 51>,
  <34, 51, 52>,
  <34, 52, 53>,
  <35, 34, 54>,
  <35, 54, 55>,
  <35, 55, 36>,
  <37, 36, 55>,
  <37, 55, 56>,
  <37, 56, 57>,
  <20, 37, 57>,
  <20, 57, 58>,
  <20, 58, 38>,
  <39, 38, 58>,
  <39, 58, 59>,
  <39, 59, 40>,
  <41, 40, 60>,
  <41, 60, 43>,
  <41, 43, 42>,
  <44, 43, 60>,
  <44, 60, 61>,
  <44, 61, 62>,
  <45, 44, 63>,
  <45, 63, 64>,
  <45, 64, 46>,
  <47, 46, 64>,
  <47, 64, 65>,
  <47, 65, 48>,
  <49, 48, 65>,
  <49, 65, 66>,
  <49, 66, 50>,
  <30, 50, 66>,
  <30, 66, 67>,
  <30, 67, 68>,
  <51, 30, 68>,
  <51, 68, 69>,
  <51, 69, 52>,
  <53, 52, 69>,
  <53, 69, 70>,
  <53, 70, 71>,
  <34, 53, 71>,
  <34, 71, 72>,
  <34, 72, 54>,
  <55, 54, 72>,
  <55, 72, 73>,
  <55, 73, 56>,
  <57, 56, 74>,
  <57, 74, 59>,
  <57, 59, 58>,
  <40, 59, 74>,
  <40, 74, 75>,
  <40, 75, 76>,
  <60, 40, 76>,
  <60, 76, 77>,
  <60, 77, 61>,
  <62, 61, 77>,
  <62, 77, 78>,
  <62, 78, 79>,
  <44, 62, 79>,
  <44, 79, 80>,
  <44, 80, 63>,
  <64, 63, 80>,
  <64, 80, 81>,
  <64, 81, 65>,
  <66, 65, 82>,
  <66, 82, 83>,
  <66, 83, 67>,
  <68, 67, 83>,
  <68, 83, 70>,
  <68, 70, 69>,
  <71, 70, 84>,
  <71, 84, 73>,
  <71, 73, 72>,
  <56, 73, 84>,
  <56, 84, 85>,
  <56, 85, 86>,
  <74, 56, 86>,
  <74, 86, 87>,
  <74, 87, 75>,
  <76, 75, 87>,
  <76, 87, 78>,
  <76, 78, 77>,
  <79, 78, 88>,
  <79, 88, 81>,
  <79, 81, 80>,
  <65, 81, 88>,
  <65, 88, 89>,
  <65, 89, 82>,
  <83, 82, 89>,
  <83, 89, 90>,
  <83, 90, 70>,
  <84, 70, 90>,
  <84, 90, 91>,
  <84, 91, 85>,
  <86, 85, 91>,
  <86, 91, 78>,
  <86, 78, 87>,
  <88, 78, 91>,
  <88, 91, 90>,
  <88, 90, 89>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Catalan_pentagonal_hexecontahedron_verts[88];
 #local P1 = Catalan_pentagonal_hexecontahedron_verts[78];
 #local P2 = Catalan_pentagonal_hexecontahedron_verts[91];
 #local P3 = Catalan_pentagonal_hexecontahedron_verts[90];
 #local P4 = Catalan_pentagonal_hexecontahedron_verts[89];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Catalan_pentagonal_hexecontahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Catalan_pentagonal_hexecontahedron_obj }
#end
#end

#macro Catalan_pentagonal_hexecontahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Catalan_pentagonal_hexecontahedron_verts[0], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[1], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[2], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[3], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[4], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[5], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[6], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[7], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[8], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[9], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[10], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[11], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[12], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[13], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[14], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[15], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[16], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[17], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[18], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[19], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[20], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[21], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[22], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[23], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[24], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[25], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[26], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[27], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[28], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[29], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[30], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[31], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[32], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[33], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[34], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[35], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[36], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[37], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[38], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[39], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[40], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[41], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[42], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[43], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[44], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[45], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[46], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[47], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[48], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[49], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[50], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[51], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[52], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[53], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[54], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[55], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[56], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[57], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[58], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[59], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[60], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[61], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[62], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[63], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[64], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[65], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[66], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[67], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[68], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[69], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[70], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[71], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[72], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[73], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[74], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[75], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[76], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[77], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[78], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[79], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[80], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[81], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[82], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[83], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[84], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[85], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[86], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[87], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[88], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[89], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[90], RadVer }
  sphere { Catalan_pentagonal_hexecontahedron_verts[91], RadVer }
  texture { TexVer } }
 union {
  cylinder { Catalan_pentagonal_hexecontahedron_verts[4], Catalan_pentagonal_hexecontahedron_verts[0], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[0], Catalan_pentagonal_hexecontahedron_verts[1], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[1], Catalan_pentagonal_hexecontahedron_verts[2], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[2], Catalan_pentagonal_hexecontahedron_verts[3], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[3], Catalan_pentagonal_hexecontahedron_verts[4], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[4], Catalan_pentagonal_hexecontahedron_verts[5], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[5], Catalan_pentagonal_hexecontahedron_verts[6], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[6], Catalan_pentagonal_hexecontahedron_verts[7], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[7], Catalan_pentagonal_hexecontahedron_verts[0], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[7], Catalan_pentagonal_hexecontahedron_verts[8], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[8], Catalan_pentagonal_hexecontahedron_verts[9], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[9], Catalan_pentagonal_hexecontahedron_verts[1], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[9], Catalan_pentagonal_hexecontahedron_verts[10], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[10], Catalan_pentagonal_hexecontahedron_verts[11], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[11], Catalan_pentagonal_hexecontahedron_verts[2], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[11], Catalan_pentagonal_hexecontahedron_verts[12], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[12], Catalan_pentagonal_hexecontahedron_verts[13], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[13], Catalan_pentagonal_hexecontahedron_verts[3], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[13], Catalan_pentagonal_hexecontahedron_verts[14], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[14], Catalan_pentagonal_hexecontahedron_verts[15], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[15], Catalan_pentagonal_hexecontahedron_verts[4], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[4], Catalan_pentagonal_hexecontahedron_verts[16], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[16], Catalan_pentagonal_hexecontahedron_verts[17], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[17], Catalan_pentagonal_hexecontahedron_verts[18], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[18], Catalan_pentagonal_hexecontahedron_verts[5], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[18], Catalan_pentagonal_hexecontahedron_verts[19], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[19], Catalan_pentagonal_hexecontahedron_verts[20], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[20], Catalan_pentagonal_hexecontahedron_verts[6], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[20], Catalan_pentagonal_hexecontahedron_verts[21], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[21], Catalan_pentagonal_hexecontahedron_verts[8], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[21], Catalan_pentagonal_hexecontahedron_verts[22], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[22], Catalan_pentagonal_hexecontahedron_verts[23], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[23], Catalan_pentagonal_hexecontahedron_verts[9], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[9], Catalan_pentagonal_hexecontahedron_verts[24], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[24], Catalan_pentagonal_hexecontahedron_verts[25], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[25], Catalan_pentagonal_hexecontahedron_verts[26], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[26], Catalan_pentagonal_hexecontahedron_verts[10], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[26], Catalan_pentagonal_hexecontahedron_verts[27], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[27], Catalan_pentagonal_hexecontahedron_verts[12], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[12], Catalan_pentagonal_hexecontahedron_verts[28], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[28], Catalan_pentagonal_hexecontahedron_verts[29], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[29], Catalan_pentagonal_hexecontahedron_verts[14], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[29], Catalan_pentagonal_hexecontahedron_verts[30], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[30], Catalan_pentagonal_hexecontahedron_verts[31], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[31], Catalan_pentagonal_hexecontahedron_verts[15], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[31], Catalan_pentagonal_hexecontahedron_verts[32], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[32], Catalan_pentagonal_hexecontahedron_verts[16], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[32], Catalan_pentagonal_hexecontahedron_verts[33], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[33], Catalan_pentagonal_hexecontahedron_verts[34], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[34], Catalan_pentagonal_hexecontahedron_verts[17], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[34], Catalan_pentagonal_hexecontahedron_verts[35], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[35], Catalan_pentagonal_hexecontahedron_verts[19], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[35], Catalan_pentagonal_hexecontahedron_verts[36], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[36], Catalan_pentagonal_hexecontahedron_verts[37], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[37], Catalan_pentagonal_hexecontahedron_verts[20], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[20], Catalan_pentagonal_hexecontahedron_verts[38], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[38], Catalan_pentagonal_hexecontahedron_verts[39], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[39], Catalan_pentagonal_hexecontahedron_verts[22], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[39], Catalan_pentagonal_hexecontahedron_verts[40], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[40], Catalan_pentagonal_hexecontahedron_verts[41], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[41], Catalan_pentagonal_hexecontahedron_verts[23], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[41], Catalan_pentagonal_hexecontahedron_verts[42], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[42], Catalan_pentagonal_hexecontahedron_verts[24], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[42], Catalan_pentagonal_hexecontahedron_verts[43], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[43], Catalan_pentagonal_hexecontahedron_verts[44], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[44], Catalan_pentagonal_hexecontahedron_verts[25], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[44], Catalan_pentagonal_hexecontahedron_verts[45], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[45], Catalan_pentagonal_hexecontahedron_verts[27], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[45], Catalan_pentagonal_hexecontahedron_verts[46], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[46], Catalan_pentagonal_hexecontahedron_verts[47], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[47], Catalan_pentagonal_hexecontahedron_verts[12], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[47], Catalan_pentagonal_hexecontahedron_verts[48], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[48], Catalan_pentagonal_hexecontahedron_verts[49], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[49], Catalan_pentagonal_hexecontahedron_verts[28], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[49], Catalan_pentagonal_hexecontahedron_verts[50], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[50], Catalan_pentagonal_hexecontahedron_verts[30], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[30], Catalan_pentagonal_hexecontahedron_verts[51], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[51], Catalan_pentagonal_hexecontahedron_verts[33], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[51], Catalan_pentagonal_hexecontahedron_verts[52], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[52], Catalan_pentagonal_hexecontahedron_verts[53], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[53], Catalan_pentagonal_hexecontahedron_verts[34], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[34], Catalan_pentagonal_hexecontahedron_verts[54], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[54], Catalan_pentagonal_hexecontahedron_verts[55], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[55], Catalan_pentagonal_hexecontahedron_verts[36], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[55], Catalan_pentagonal_hexecontahedron_verts[56], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[56], Catalan_pentagonal_hexecontahedron_verts[57], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[57], Catalan_pentagonal_hexecontahedron_verts[37], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[57], Catalan_pentagonal_hexecontahedron_verts[58], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[58], Catalan_pentagonal_hexecontahedron_verts[38], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[58], Catalan_pentagonal_hexecontahedron_verts[59], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[59], Catalan_pentagonal_hexecontahedron_verts[40], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[40], Catalan_pentagonal_hexecontahedron_verts[60], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[60], Catalan_pentagonal_hexecontahedron_verts[43], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[60], Catalan_pentagonal_hexecontahedron_verts[61], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[61], Catalan_pentagonal_hexecontahedron_verts[62], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[62], Catalan_pentagonal_hexecontahedron_verts[44], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[44], Catalan_pentagonal_hexecontahedron_verts[63], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[63], Catalan_pentagonal_hexecontahedron_verts[64], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[64], Catalan_pentagonal_hexecontahedron_verts[46], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[64], Catalan_pentagonal_hexecontahedron_verts[65], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[65], Catalan_pentagonal_hexecontahedron_verts[48], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[65], Catalan_pentagonal_hexecontahedron_verts[66], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[66], Catalan_pentagonal_hexecontahedron_verts[50], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[66], Catalan_pentagonal_hexecontahedron_verts[67], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[67], Catalan_pentagonal_hexecontahedron_verts[68], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[68], Catalan_pentagonal_hexecontahedron_verts[30], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[68], Catalan_pentagonal_hexecontahedron_verts[69], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[69], Catalan_pentagonal_hexecontahedron_verts[52], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[69], Catalan_pentagonal_hexecontahedron_verts[70], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[70], Catalan_pentagonal_hexecontahedron_verts[71], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[71], Catalan_pentagonal_hexecontahedron_verts[53], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[71], Catalan_pentagonal_hexecontahedron_verts[72], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[72], Catalan_pentagonal_hexecontahedron_verts[54], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[72], Catalan_pentagonal_hexecontahedron_verts[73], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[73], Catalan_pentagonal_hexecontahedron_verts[56], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[56], Catalan_pentagonal_hexecontahedron_verts[74], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[74], Catalan_pentagonal_hexecontahedron_verts[59], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[74], Catalan_pentagonal_hexecontahedron_verts[75], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[75], Catalan_pentagonal_hexecontahedron_verts[76], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[76], Catalan_pentagonal_hexecontahedron_verts[40], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[76], Catalan_pentagonal_hexecontahedron_verts[77], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[77], Catalan_pentagonal_hexecontahedron_verts[61], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[77], Catalan_pentagonal_hexecontahedron_verts[78], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[78], Catalan_pentagonal_hexecontahedron_verts[79], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[79], Catalan_pentagonal_hexecontahedron_verts[62], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[79], Catalan_pentagonal_hexecontahedron_verts[80], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[80], Catalan_pentagonal_hexecontahedron_verts[63], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[80], Catalan_pentagonal_hexecontahedron_verts[81], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[81], Catalan_pentagonal_hexecontahedron_verts[65], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[65], Catalan_pentagonal_hexecontahedron_verts[82], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[82], Catalan_pentagonal_hexecontahedron_verts[83], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[83], Catalan_pentagonal_hexecontahedron_verts[67], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[83], Catalan_pentagonal_hexecontahedron_verts[70], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[70], Catalan_pentagonal_hexecontahedron_verts[84], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[84], Catalan_pentagonal_hexecontahedron_verts[73], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[84], Catalan_pentagonal_hexecontahedron_verts[85], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[85], Catalan_pentagonal_hexecontahedron_verts[86], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[86], Catalan_pentagonal_hexecontahedron_verts[56], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[86], Catalan_pentagonal_hexecontahedron_verts[87], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[87], Catalan_pentagonal_hexecontahedron_verts[75], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[87], Catalan_pentagonal_hexecontahedron_verts[78], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[78], Catalan_pentagonal_hexecontahedron_verts[88], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[88], Catalan_pentagonal_hexecontahedron_verts[81], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[88], Catalan_pentagonal_hexecontahedron_verts[89], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[89], Catalan_pentagonal_hexecontahedron_verts[82], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[89], Catalan_pentagonal_hexecontahedron_verts[90], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[90], Catalan_pentagonal_hexecontahedron_verts[70], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[90], Catalan_pentagonal_hexecontahedron_verts[91], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[91], Catalan_pentagonal_hexecontahedron_verts[85], RadEdg }
  cylinder { Catalan_pentagonal_hexecontahedron_verts[91], Catalan_pentagonal_hexecontahedron_verts[78], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Catalan_pentagonal_hexecontahedron_verts[88];
 #local P1 = Catalan_pentagonal_hexecontahedron_verts[78];
 #local P2 = Catalan_pentagonal_hexecontahedron_verts[91];
 #local P3 = Catalan_pentagonal_hexecontahedron_verts[90];
 #local P4 = Catalan_pentagonal_hexecontahedron_verts[89];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
