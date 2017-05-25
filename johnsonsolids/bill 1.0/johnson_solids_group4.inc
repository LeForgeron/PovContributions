/* -------------------
johnson_solids_group4.inc

Augmented prisms

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Johnson_49_augmented_triangular_prism (7 vertices)
  Johnson_50_biaugmented_triangular_prism (8 vertices)
  Johnson_51_triaugmented_triangular_prism (9 vertices)
  Johnson_52_augmented_pentagonal_prism (11 vertices)
  Johnson_53_biaugmented_pentagonal_prism (12 vertices)
  Johnson_54_augmented_hexagonal_prism (13 vertices)
  Johnson_55_parabiaugmented_hexagonal_prism (14 vertices)
  Johnson_56_metabiaugmented_hexagonal_prism (14 vertices)
  Johnson_57_triaugmented_hexagonal_prism (15 vertices)

-------------------- */

#include "transforms.inc"

#declare Johnson_49_augmented_triangular_prism_verts = array[7]
{
<-0.875470, -0.255205, -0.086794>,
<-0.276612, -0.313401, 1.029989>,
<-0.236035, 0.801921, -0.374595>,
<-0.051128, -0.255205, -1.050994>,
<0.218493, -0.889481, 0.014004>,
<0.362823, 0.743725, 0.742188>,
<0.857929, 0.167645, -0.273797>,
}
#declare P0 = Johnson_49_augmented_triangular_prism_verts[5];
#declare P1 = Johnson_49_augmented_triangular_prism_verts[6];
#declare P2 = Johnson_49_augmented_triangular_prism_verts[2];
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
 #declare Johnson_49_augmented_triangular_prism_verts[Num] = vtransform(Johnson_49_augmented_triangular_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_49_augmented_triangular_prism_faces(Tex3, Tex4, OnPlane)
#local Johnson_49_augmented_triangular_prism_obj = mesh2 {
 vertex_vectors {
  7,
  Johnson_49_augmented_triangular_prism_verts[0],
  Johnson_49_augmented_triangular_prism_verts[1],
  Johnson_49_augmented_triangular_prism_verts[2],
  Johnson_49_augmented_triangular_prism_verts[3],
  Johnson_49_augmented_triangular_prism_verts[4],
  Johnson_49_augmented_triangular_prism_verts[5],
  Johnson_49_augmented_triangular_prism_verts[6]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  10,
  <6, 3, 2>, 0,
  <3, 0, 2>, 0,
  <0, 3, 4>, 0,
  <2, 5, 6>, 0,
  <1, 0, 4>, 0,
  <6, 4, 3>, 0,
  <2, 0, 1>, 1,
  <2, 1, 5>, 1,
  <5, 1, 4>, 1,
  <5, 4, 6>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_49_augmented_triangular_prism_verts[5];
 #local P1 = Johnson_49_augmented_triangular_prism_verts[6];
 #local P2 = Johnson_49_augmented_triangular_prism_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_49_augmented_triangular_prism_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_49_augmented_triangular_prism_obj }
#end
#end

#macro Johnson_49_augmented_triangular_prism_faces2(OnPlane)
#local Johnson_49_augmented_triangular_prism_obj = mesh2 {
 vertex_vectors {
  7,
  Johnson_49_augmented_triangular_prism_verts[0],
  Johnson_49_augmented_triangular_prism_verts[1],
  Johnson_49_augmented_triangular_prism_verts[2],
  Johnson_49_augmented_triangular_prism_verts[3],
  Johnson_49_augmented_triangular_prism_verts[4],
  Johnson_49_augmented_triangular_prism_verts[5],
  Johnson_49_augmented_triangular_prism_verts[6]
 }
 face_indices {
  10,
  <6, 3, 2>,
  <3, 0, 2>,
  <0, 3, 4>,
  <2, 5, 6>,
  <1, 0, 4>,
  <6, 4, 3>,
  <2, 0, 1>,
  <2, 1, 5>,
  <5, 1, 4>,
  <5, 4, 6>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_49_augmented_triangular_prism_verts[5];
 #local P1 = Johnson_49_augmented_triangular_prism_verts[6];
 #local P2 = Johnson_49_augmented_triangular_prism_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_49_augmented_triangular_prism_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_49_augmented_triangular_prism_obj }
#end
#end

#macro Johnson_49_augmented_triangular_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_49_augmented_triangular_prism_verts[0], RadVer }
  sphere { Johnson_49_augmented_triangular_prism_verts[1], RadVer }
  sphere { Johnson_49_augmented_triangular_prism_verts[2], RadVer }
  sphere { Johnson_49_augmented_triangular_prism_verts[3], RadVer }
  sphere { Johnson_49_augmented_triangular_prism_verts[4], RadVer }
  sphere { Johnson_49_augmented_triangular_prism_verts[5], RadVer }
  sphere { Johnson_49_augmented_triangular_prism_verts[6], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_49_augmented_triangular_prism_verts[6], Johnson_49_augmented_triangular_prism_verts[3], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[3], Johnson_49_augmented_triangular_prism_verts[2], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[2], Johnson_49_augmented_triangular_prism_verts[6], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[3], Johnson_49_augmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[0], Johnson_49_augmented_triangular_prism_verts[2], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[3], Johnson_49_augmented_triangular_prism_verts[4], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[4], Johnson_49_augmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[2], Johnson_49_augmented_triangular_prism_verts[5], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[5], Johnson_49_augmented_triangular_prism_verts[6], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[1], Johnson_49_augmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[4], Johnson_49_augmented_triangular_prism_verts[1], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[6], Johnson_49_augmented_triangular_prism_verts[4], RadEdg }
  cylinder { Johnson_49_augmented_triangular_prism_verts[1], Johnson_49_augmented_triangular_prism_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_49_augmented_triangular_prism_verts[5];
 #local P1 = Johnson_49_augmented_triangular_prism_verts[6];
 #local P2 = Johnson_49_augmented_triangular_prism_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_50_biaugmented_triangular_prism_verts = array[8]
{
<-0.878027, -0.446140, 0.176652>,
<-0.856560, 0.548188, -0.533000>,
<-0.477610, 0.616903, 0.626496>,
<-0.069889, -0.364329, -0.736024>,
<0.239836, -0.921955, 0.306031>,
<0.330528, 0.698715, -0.286179>,
<0.640253, 0.141088, 0.755876>,
<1.071468, -0.272471, -0.309853>,
}
#declare P0 = Johnson_50_biaugmented_triangular_prism_verts[6];
#declare P1 = Johnson_50_biaugmented_triangular_prism_verts[2];
#declare P2 = Johnson_50_biaugmented_triangular_prism_verts[5];
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
 #declare Johnson_50_biaugmented_triangular_prism_verts[Num] = vtransform(Johnson_50_biaugmented_triangular_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_50_biaugmented_triangular_prism_faces(Tex3, Tex4, OnPlane)
#local Johnson_50_biaugmented_triangular_prism_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_50_biaugmented_triangular_prism_verts[0],
  Johnson_50_biaugmented_triangular_prism_verts[1],
  Johnson_50_biaugmented_triangular_prism_verts[2],
  Johnson_50_biaugmented_triangular_prism_verts[3],
  Johnson_50_biaugmented_triangular_prism_verts[4],
  Johnson_50_biaugmented_triangular_prism_verts[5],
  Johnson_50_biaugmented_triangular_prism_verts[6],
  Johnson_50_biaugmented_triangular_prism_verts[7]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  12,
  <3, 0, 1>, 0,
  <1, 0, 2>, 0,
  <1, 2, 5>, 0,
  <4, 0, 3>, 0,
  <2, 6, 5>, 0,
  <4, 3, 7>, 0,
  <4, 7, 6>, 0,
  <6, 7, 5>, 0,
  <7, 3, 5>, 0,
  <1, 5, 3>, 0,
  <0, 4, 6>, 1,
  <0, 6, 2>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_50_biaugmented_triangular_prism_verts[3];
 #local P1 = Johnson_50_biaugmented_triangular_prism_verts[4];
 #local P2 = Johnson_50_biaugmented_triangular_prism_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_50_biaugmented_triangular_prism_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_50_biaugmented_triangular_prism_obj }
#end
#end

#macro Johnson_50_biaugmented_triangular_prism_faces2(OnPlane)
#local Johnson_50_biaugmented_triangular_prism_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_50_biaugmented_triangular_prism_verts[0],
  Johnson_50_biaugmented_triangular_prism_verts[1],
  Johnson_50_biaugmented_triangular_prism_verts[2],
  Johnson_50_biaugmented_triangular_prism_verts[3],
  Johnson_50_biaugmented_triangular_prism_verts[4],
  Johnson_50_biaugmented_triangular_prism_verts[5],
  Johnson_50_biaugmented_triangular_prism_verts[6],
  Johnson_50_biaugmented_triangular_prism_verts[7]
 }
 face_indices {
  12,
  <3, 0, 1>,
  <1, 0, 2>,
  <1, 2, 5>,
  <4, 0, 3>,
  <2, 6, 5>,
  <4, 3, 7>,
  <4, 7, 6>,
  <6, 7, 5>,
  <7, 3, 5>,
  <1, 5, 3>,
  <0, 4, 6>,
  <0, 6, 2>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_50_biaugmented_triangular_prism_verts[3];
 #local P1 = Johnson_50_biaugmented_triangular_prism_verts[4];
 #local P2 = Johnson_50_biaugmented_triangular_prism_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_50_biaugmented_triangular_prism_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_50_biaugmented_triangular_prism_obj }
#end
#end

#macro Johnson_50_biaugmented_triangular_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_50_biaugmented_triangular_prism_verts[0], RadVer }
  sphere { Johnson_50_biaugmented_triangular_prism_verts[1], RadVer }
  sphere { Johnson_50_biaugmented_triangular_prism_verts[2], RadVer }
  sphere { Johnson_50_biaugmented_triangular_prism_verts[3], RadVer }
  sphere { Johnson_50_biaugmented_triangular_prism_verts[4], RadVer }
  sphere { Johnson_50_biaugmented_triangular_prism_verts[5], RadVer }
  sphere { Johnson_50_biaugmented_triangular_prism_verts[6], RadVer }
  sphere { Johnson_50_biaugmented_triangular_prism_verts[7], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[3], Johnson_50_biaugmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[0], Johnson_50_biaugmented_triangular_prism_verts[1], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[1], Johnson_50_biaugmented_triangular_prism_verts[3], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[0], Johnson_50_biaugmented_triangular_prism_verts[2], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[2], Johnson_50_biaugmented_triangular_prism_verts[1], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[2], Johnson_50_biaugmented_triangular_prism_verts[5], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[5], Johnson_50_biaugmented_triangular_prism_verts[1], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[4], Johnson_50_biaugmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[3], Johnson_50_biaugmented_triangular_prism_verts[4], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[2], Johnson_50_biaugmented_triangular_prism_verts[6], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[6], Johnson_50_biaugmented_triangular_prism_verts[5], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[3], Johnson_50_biaugmented_triangular_prism_verts[7], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[7], Johnson_50_biaugmented_triangular_prism_verts[4], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[7], Johnson_50_biaugmented_triangular_prism_verts[6], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[6], Johnson_50_biaugmented_triangular_prism_verts[4], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[7], Johnson_50_biaugmented_triangular_prism_verts[5], RadEdg }
  cylinder { Johnson_50_biaugmented_triangular_prism_verts[3], Johnson_50_biaugmented_triangular_prism_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_50_biaugmented_triangular_prism_verts[3];
 #local P1 = Johnson_50_biaugmented_triangular_prism_verts[4];
 #local P2 = Johnson_50_biaugmented_triangular_prism_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_51_triaugmented_triangular_prism_verts = array[9]
{
<-0.837735, -0.140456, -0.298855>,
<-0.678080, 0.951266, 0.116678>,
<-0.424767, 0.019903, 0.793738>,
<-0.041529, -0.887587, 0.145967>,
<-0.017092, -0.613922, -1.000561>,
<0.031619, 0.531638, -0.726088>,
<0.444587, 0.691997, 0.366504>,
<0.695172, -0.337344, 0.883883>,
<0.827825, -0.215493, -0.281266>,
}
#declare P0 = Johnson_51_triaugmented_triangular_prism_verts[0];
#declare P1 = Johnson_51_triaugmented_triangular_prism_verts[3];
#declare P2 = Johnson_51_triaugmented_triangular_prism_verts[2];
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
 #declare Johnson_51_triaugmented_triangular_prism_verts[Num] = vtransform(Johnson_51_triaugmented_triangular_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_51_triaugmented_triangular_prism_faces(Tex3, OnPlane)
#local Johnson_51_triaugmented_triangular_prism_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_51_triaugmented_triangular_prism_verts[0],
  Johnson_51_triaugmented_triangular_prism_verts[1],
  Johnson_51_triaugmented_triangular_prism_verts[2],
  Johnson_51_triaugmented_triangular_prism_verts[3],
  Johnson_51_triaugmented_triangular_prism_verts[4],
  Johnson_51_triaugmented_triangular_prism_verts[5],
  Johnson_51_triaugmented_triangular_prism_verts[6],
  Johnson_51_triaugmented_triangular_prism_verts[7],
  Johnson_51_triaugmented_triangular_prism_verts[8]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  14,
  <1, 5, 0>, 0,
  <8, 4, 5>, 0,
  <4, 0, 5>, 0,
  <4, 3, 0>, 0,
  <8, 3, 4>, 0,
  <5, 6, 8>, 0,
  <8, 6, 7>, 0,
  <8, 7, 3>, 0,
  <3, 7, 2>, 0,
  <7, 6, 2>, 0,
  <3, 2, 0>, 0,
  <0, 2, 1>, 0,
  <2, 6, 1>, 0,
  <1, 6, 5>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_51_triaugmented_triangular_prism_verts[0];
 #local P1 = Johnson_51_triaugmented_triangular_prism_verts[3];
 #local P2 = Johnson_51_triaugmented_triangular_prism_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_51_triaugmented_triangular_prism_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_51_triaugmented_triangular_prism_obj }
#end
#end

#macro Johnson_51_triaugmented_triangular_prism_faces2(OnPlane)
#local Johnson_51_triaugmented_triangular_prism_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_51_triaugmented_triangular_prism_verts[0],
  Johnson_51_triaugmented_triangular_prism_verts[1],
  Johnson_51_triaugmented_triangular_prism_verts[2],
  Johnson_51_triaugmented_triangular_prism_verts[3],
  Johnson_51_triaugmented_triangular_prism_verts[4],
  Johnson_51_triaugmented_triangular_prism_verts[5],
  Johnson_51_triaugmented_triangular_prism_verts[6],
  Johnson_51_triaugmented_triangular_prism_verts[7],
  Johnson_51_triaugmented_triangular_prism_verts[8]
 }
 face_indices {
  14,
  <1, 5, 0>,
  <8, 4, 5>,
  <4, 0, 5>,
  <4, 3, 0>,
  <8, 3, 4>,
  <5, 6, 8>,
  <8, 6, 7>,
  <8, 7, 3>,
  <3, 7, 2>,
  <7, 6, 2>,
  <3, 2, 0>,
  <0, 2, 1>,
  <2, 6, 1>,
  <1, 6, 5>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_51_triaugmented_triangular_prism_verts[0];
 #local P1 = Johnson_51_triaugmented_triangular_prism_verts[3];
 #local P2 = Johnson_51_triaugmented_triangular_prism_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_51_triaugmented_triangular_prism_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_51_triaugmented_triangular_prism_obj }
#end
#end

#macro Johnson_51_triaugmented_triangular_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_51_triaugmented_triangular_prism_verts[0], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[1], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[2], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[3], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[4], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[5], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[6], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[7], RadVer }
  sphere { Johnson_51_triaugmented_triangular_prism_verts[8], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[1], Johnson_51_triaugmented_triangular_prism_verts[5], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[5], Johnson_51_triaugmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[0], Johnson_51_triaugmented_triangular_prism_verts[1], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[8], Johnson_51_triaugmented_triangular_prism_verts[4], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[4], Johnson_51_triaugmented_triangular_prism_verts[5], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[5], Johnson_51_triaugmented_triangular_prism_verts[8], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[4], Johnson_51_triaugmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[4], Johnson_51_triaugmented_triangular_prism_verts[3], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[3], Johnson_51_triaugmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[8], Johnson_51_triaugmented_triangular_prism_verts[3], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[5], Johnson_51_triaugmented_triangular_prism_verts[6], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[6], Johnson_51_triaugmented_triangular_prism_verts[8], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[6], Johnson_51_triaugmented_triangular_prism_verts[7], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[7], Johnson_51_triaugmented_triangular_prism_verts[8], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[7], Johnson_51_triaugmented_triangular_prism_verts[3], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[7], Johnson_51_triaugmented_triangular_prism_verts[2], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[2], Johnson_51_triaugmented_triangular_prism_verts[3], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[6], Johnson_51_triaugmented_triangular_prism_verts[2], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[2], Johnson_51_triaugmented_triangular_prism_verts[0], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[2], Johnson_51_triaugmented_triangular_prism_verts[1], RadEdg }
  cylinder { Johnson_51_triaugmented_triangular_prism_verts[6], Johnson_51_triaugmented_triangular_prism_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_51_triaugmented_triangular_prism_verts[0];
 #local P1 = Johnson_51_triaugmented_triangular_prism_verts[3];
 #local P2 = Johnson_51_triaugmented_triangular_prism_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_52_augmented_pentagonal_prism_verts = array[11]
{
<-0.814810, 0.221521, -0.662951>,
<-0.660297, -0.683519, -0.326712>,
<-0.530730, 0.852939, 0.027439>,
<-0.280723, -0.611446, 0.571485>,
<-0.200646, 0.338137, 0.790362>,
<0.085423, 0.233517, -1.044348>,
<0.239936, -0.671523, -0.708109>,
<0.369503, 0.864935, -0.353959>,
<0.473247, -0.295241, 1.107742>,
<0.619511, -0.599450, 0.190087>,
<0.699587, 0.350133, 0.408964>,
}
#declare P0 = Johnson_52_augmented_pentagonal_prism_verts[7];
#declare P1 = Johnson_52_augmented_pentagonal_prism_verts[10];
#declare P2 = Johnson_52_augmented_pentagonal_prism_verts[9];
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
 #declare Johnson_52_augmented_pentagonal_prism_verts[Num] = vtransform(Johnson_52_augmented_pentagonal_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_52_augmented_pentagonal_prism_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_52_augmented_pentagonal_prism_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_52_augmented_pentagonal_prism_verts[0],
  Johnson_52_augmented_pentagonal_prism_verts[1],
  Johnson_52_augmented_pentagonal_prism_verts[2],
  Johnson_52_augmented_pentagonal_prism_verts[3],
  Johnson_52_augmented_pentagonal_prism_verts[4],
  Johnson_52_augmented_pentagonal_prism_verts[5],
  Johnson_52_augmented_pentagonal_prism_verts[6],
  Johnson_52_augmented_pentagonal_prism_verts[7],
  Johnson_52_augmented_pentagonal_prism_verts[8],
  Johnson_52_augmented_pentagonal_prism_verts[9],
  Johnson_52_augmented_pentagonal_prism_verts[10]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  18,
  <3, 8, 4>, 0,
  <3, 9, 8>, 0,
  <4, 8, 10>, 0,
  <10, 8, 9>, 0,
  <1, 0, 5>, 1,
  <1, 5, 6>, 1,
  <3, 1, 6>, 1,
  <3, 6, 9>, 1,
  <2, 4, 10>, 1,
  <2, 10, 7>, 1,
  <0, 2, 7>, 1,
  <0, 7, 5>, 1,
  <0, 1, 3>, 2,
  <0, 3, 4>, 2,
  <0, 4, 2>, 2,
  <7, 10, 9>, 2,
  <7, 9, 6>, 2,
  <7, 6, 5>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_52_augmented_pentagonal_prism_verts[7];
 #local P1 = Johnson_52_augmented_pentagonal_prism_verts[10];
 #local P2 = Johnson_52_augmented_pentagonal_prism_verts[9];
 #local P3 = Johnson_52_augmented_pentagonal_prism_verts[6];
 #local P4 = Johnson_52_augmented_pentagonal_prism_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_52_augmented_pentagonal_prism_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_52_augmented_pentagonal_prism_obj }
#end
#end

#macro Johnson_52_augmented_pentagonal_prism_faces2(OnPlane)
#local Johnson_52_augmented_pentagonal_prism_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_52_augmented_pentagonal_prism_verts[0],
  Johnson_52_augmented_pentagonal_prism_verts[1],
  Johnson_52_augmented_pentagonal_prism_verts[2],
  Johnson_52_augmented_pentagonal_prism_verts[3],
  Johnson_52_augmented_pentagonal_prism_verts[4],
  Johnson_52_augmented_pentagonal_prism_verts[5],
  Johnson_52_augmented_pentagonal_prism_verts[6],
  Johnson_52_augmented_pentagonal_prism_verts[7],
  Johnson_52_augmented_pentagonal_prism_verts[8],
  Johnson_52_augmented_pentagonal_prism_verts[9],
  Johnson_52_augmented_pentagonal_prism_verts[10]
 }
 face_indices {
  18,
  <3, 8, 4>,
  <3, 9, 8>,
  <4, 8, 10>,
  <10, 8, 9>,
  <1, 0, 5>,
  <1, 5, 6>,
  <3, 1, 6>,
  <3, 6, 9>,
  <2, 4, 10>,
  <2, 10, 7>,
  <0, 2, 7>,
  <0, 7, 5>,
  <0, 1, 3>,
  <0, 3, 4>,
  <0, 4, 2>,
  <7, 10, 9>,
  <7, 9, 6>,
  <7, 6, 5>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_52_augmented_pentagonal_prism_verts[7];
 #local P1 = Johnson_52_augmented_pentagonal_prism_verts[10];
 #local P2 = Johnson_52_augmented_pentagonal_prism_verts[9];
 #local P3 = Johnson_52_augmented_pentagonal_prism_verts[6];
 #local P4 = Johnson_52_augmented_pentagonal_prism_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_52_augmented_pentagonal_prism_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_52_augmented_pentagonal_prism_obj }
#end
#end

#macro Johnson_52_augmented_pentagonal_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_52_augmented_pentagonal_prism_verts[0], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[1], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[2], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[3], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[4], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[5], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[6], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[7], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[8], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[9], RadVer }
  sphere { Johnson_52_augmented_pentagonal_prism_verts[10], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[3], Johnson_52_augmented_pentagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[8], Johnson_52_augmented_pentagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[4], Johnson_52_augmented_pentagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[3], Johnson_52_augmented_pentagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[9], Johnson_52_augmented_pentagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[8], Johnson_52_augmented_pentagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[10], Johnson_52_augmented_pentagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[9], Johnson_52_augmented_pentagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[1], Johnson_52_augmented_pentagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[0], Johnson_52_augmented_pentagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[5], Johnson_52_augmented_pentagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[6], Johnson_52_augmented_pentagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[3], Johnson_52_augmented_pentagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[6], Johnson_52_augmented_pentagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[2], Johnson_52_augmented_pentagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[10], Johnson_52_augmented_pentagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[7], Johnson_52_augmented_pentagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[0], Johnson_52_augmented_pentagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_52_augmented_pentagonal_prism_verts[7], Johnson_52_augmented_pentagonal_prism_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_52_augmented_pentagonal_prism_verts[7];
 #local P1 = Johnson_52_augmented_pentagonal_prism_verts[10];
 #local P2 = Johnson_52_augmented_pentagonal_prism_verts[9];
 #local P3 = Johnson_52_augmented_pentagonal_prism_verts[6];
 #local P4 = Johnson_52_augmented_pentagonal_prism_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_53_biaugmented_pentagonal_prism_verts = array[12]
{
<-0.736376, 0.261231, -0.409511>,
<-0.572247, -0.640818, -0.200191>,
<-0.430826, 0.786388, 0.308330>,
<-0.352398, 1.103933, -0.573408>,
<-0.165260, -0.673158, 0.647018>,
<-0.077857, 0.208904, 0.961301>,
<0.083202, -1.290119, -0.017868>,
<0.110490, 0.321450, -0.814035>,
<0.274618, -0.580600, -0.604714>,
<0.416039, 0.846607, -0.096194>,
<0.681606, -0.612940, 0.242494>,
<0.769009, 0.269122, 0.556777>,
}
#declare P0 = Johnson_53_biaugmented_pentagonal_prism_verts[8];
#declare P1 = Johnson_53_biaugmented_pentagonal_prism_verts[7];
#declare P2 = Johnson_53_biaugmented_pentagonal_prism_verts[9];
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
 #declare Johnson_53_biaugmented_pentagonal_prism_verts[Num] = vtransform(Johnson_53_biaugmented_pentagonal_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_53_biaugmented_pentagonal_prism_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_53_biaugmented_pentagonal_prism_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_53_biaugmented_pentagonal_prism_verts[0],
  Johnson_53_biaugmented_pentagonal_prism_verts[1],
  Johnson_53_biaugmented_pentagonal_prism_verts[2],
  Johnson_53_biaugmented_pentagonal_prism_verts[3],
  Johnson_53_biaugmented_pentagonal_prism_verts[4],
  Johnson_53_biaugmented_pentagonal_prism_verts[5],
  Johnson_53_biaugmented_pentagonal_prism_verts[6],
  Johnson_53_biaugmented_pentagonal_prism_verts[7],
  Johnson_53_biaugmented_pentagonal_prism_verts[8],
  Johnson_53_biaugmented_pentagonal_prism_verts[9],
  Johnson_53_biaugmented_pentagonal_prism_verts[10],
  Johnson_53_biaugmented_pentagonal_prism_verts[11]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  20,
  <2, 3, 0>, 0,
  <2, 9, 3>, 0,
  <0, 3, 7>, 0,
  <7, 3, 9>, 0,
  <1, 6, 4>, 0,
  <1, 8, 6>, 0,
  <4, 6, 10>, 0,
  <10, 6, 8>, 0,
  <5, 4, 10>, 1,
  <5, 10, 11>, 1,
  <2, 5, 11>, 1,
  <2, 11, 9>, 1,
  <1, 0, 7>, 1,
  <1, 7, 8>, 1,
  <4, 5, 2>, 2,
  <4, 2, 0>, 2,
  <4, 0, 1>, 2,
  <8, 7, 9>, 2,
  <8, 9, 11>, 2,
  <8, 11, 10>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_53_biaugmented_pentagonal_prism_verts[8];
 #local P1 = Johnson_53_biaugmented_pentagonal_prism_verts[7];
 #local P2 = Johnson_53_biaugmented_pentagonal_prism_verts[9];
 #local P3 = Johnson_53_biaugmented_pentagonal_prism_verts[11];
 #local P4 = Johnson_53_biaugmented_pentagonal_prism_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_53_biaugmented_pentagonal_prism_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_53_biaugmented_pentagonal_prism_obj }
#end
#end

#macro Johnson_53_biaugmented_pentagonal_prism_faces2(OnPlane)
#local Johnson_53_biaugmented_pentagonal_prism_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_53_biaugmented_pentagonal_prism_verts[0],
  Johnson_53_biaugmented_pentagonal_prism_verts[1],
  Johnson_53_biaugmented_pentagonal_prism_verts[2],
  Johnson_53_biaugmented_pentagonal_prism_verts[3],
  Johnson_53_biaugmented_pentagonal_prism_verts[4],
  Johnson_53_biaugmented_pentagonal_prism_verts[5],
  Johnson_53_biaugmented_pentagonal_prism_verts[6],
  Johnson_53_biaugmented_pentagonal_prism_verts[7],
  Johnson_53_biaugmented_pentagonal_prism_verts[8],
  Johnson_53_biaugmented_pentagonal_prism_verts[9],
  Johnson_53_biaugmented_pentagonal_prism_verts[10],
  Johnson_53_biaugmented_pentagonal_prism_verts[11]
 }
 face_indices {
  20,
  <2, 3, 0>,
  <2, 9, 3>,
  <0, 3, 7>,
  <7, 3, 9>,
  <1, 6, 4>,
  <1, 8, 6>,
  <4, 6, 10>,
  <10, 6, 8>,
  <5, 4, 10>,
  <5, 10, 11>,
  <2, 5, 11>,
  <2, 11, 9>,
  <1, 0, 7>,
  <1, 7, 8>,
  <4, 5, 2>,
  <4, 2, 0>,
  <4, 0, 1>,
  <8, 7, 9>,
  <8, 9, 11>,
  <8, 11, 10>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_53_biaugmented_pentagonal_prism_verts[8];
 #local P1 = Johnson_53_biaugmented_pentagonal_prism_verts[7];
 #local P2 = Johnson_53_biaugmented_pentagonal_prism_verts[9];
 #local P3 = Johnson_53_biaugmented_pentagonal_prism_verts[11];
 #local P4 = Johnson_53_biaugmented_pentagonal_prism_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_53_biaugmented_pentagonal_prism_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_53_biaugmented_pentagonal_prism_obj }
#end
#end

#macro Johnson_53_biaugmented_pentagonal_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[0], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[1], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[2], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[3], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[4], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[5], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[6], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[7], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[8], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[9], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[10], RadVer }
  sphere { Johnson_53_biaugmented_pentagonal_prism_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[2], Johnson_53_biaugmented_pentagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[3], Johnson_53_biaugmented_pentagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[0], Johnson_53_biaugmented_pentagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[2], Johnson_53_biaugmented_pentagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[9], Johnson_53_biaugmented_pentagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[3], Johnson_53_biaugmented_pentagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[7], Johnson_53_biaugmented_pentagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[9], Johnson_53_biaugmented_pentagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[1], Johnson_53_biaugmented_pentagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[6], Johnson_53_biaugmented_pentagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[4], Johnson_53_biaugmented_pentagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[1], Johnson_53_biaugmented_pentagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[8], Johnson_53_biaugmented_pentagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[6], Johnson_53_biaugmented_pentagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[10], Johnson_53_biaugmented_pentagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[8], Johnson_53_biaugmented_pentagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[5], Johnson_53_biaugmented_pentagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[10], Johnson_53_biaugmented_pentagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[11], Johnson_53_biaugmented_pentagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[2], Johnson_53_biaugmented_pentagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[11], Johnson_53_biaugmented_pentagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[1], Johnson_53_biaugmented_pentagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_53_biaugmented_pentagonal_prism_verts[7], Johnson_53_biaugmented_pentagonal_prism_verts[8], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_53_biaugmented_pentagonal_prism_verts[8];
 #local P1 = Johnson_53_biaugmented_pentagonal_prism_verts[7];
 #local P2 = Johnson_53_biaugmented_pentagonal_prism_verts[9];
 #local P3 = Johnson_53_biaugmented_pentagonal_prism_verts[11];
 #local P4 = Johnson_53_biaugmented_pentagonal_prism_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_54_augmented_hexagonal_prism_verts = array[13]
{
<-0.973522, 0.388420, -0.100967>,
<-0.837708, -0.464036, -0.184620>,
<-0.457167, 0.537479, -0.781617>,
<-0.449574, 0.863826, 0.400622>,
<-0.321353, -0.314977, -0.865269>,
<-0.177946, -0.841086, 0.233318>,
<0.066781, 1.012885, -0.280028>,
<0.210188, 0.486776, 0.818559>,
<0.338409, -0.692027, -0.447332>,
<0.346002, -0.365679, 0.734907>,
<0.666998, -1.030797, 0.280259>,
<0.726543, 0.635835, 0.137910>,
<0.862357, -0.216621, 0.054258>,
}
#declare P0 = Johnson_54_augmented_hexagonal_prism_verts[11];
#declare P1 = Johnson_54_augmented_hexagonal_prism_verts[12];
#declare P2 = Johnson_54_augmented_hexagonal_prism_verts[8];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 13)
 #declare Johnson_54_augmented_hexagonal_prism_verts[Num] = vtransform(Johnson_54_augmented_hexagonal_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_54_augmented_hexagonal_prism_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_54_augmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  13,
  Johnson_54_augmented_hexagonal_prism_verts[0],
  Johnson_54_augmented_hexagonal_prism_verts[1],
  Johnson_54_augmented_hexagonal_prism_verts[2],
  Johnson_54_augmented_hexagonal_prism_verts[3],
  Johnson_54_augmented_hexagonal_prism_verts[4],
  Johnson_54_augmented_hexagonal_prism_verts[5],
  Johnson_54_augmented_hexagonal_prism_verts[6],
  Johnson_54_augmented_hexagonal_prism_verts[7],
  Johnson_54_augmented_hexagonal_prism_verts[8],
  Johnson_54_augmented_hexagonal_prism_verts[9],
  Johnson_54_augmented_hexagonal_prism_verts[10],
  Johnson_54_augmented_hexagonal_prism_verts[11],
  Johnson_54_augmented_hexagonal_prism_verts[12]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  22,
  <5, 10, 9>, 0,
  <5, 8, 10>, 0,
  <9, 10, 12>, 0,
  <12, 10, 8>, 0,
  <1, 0, 2>, 1,
  <1, 2, 4>, 1,
  <5, 1, 4>, 1,
  <5, 4, 8>, 1,
  <7, 9, 12>, 1,
  <7, 12, 11>, 1,
  <3, 7, 11>, 1,
  <3, 11, 6>, 1,
  <0, 3, 6>, 1,
  <0, 6, 2>, 1,
  <0, 1, 5>, 2,
  <0, 5, 9>, 2,
  <0, 9, 7>, 2,
  <0, 7, 3>, 2,
  <11, 12, 8>, 2,
  <11, 8, 4>, 2,
  <11, 4, 2>, 2,
  <11, 2, 6>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_54_augmented_hexagonal_prism_verts[11];
 #local P1 = Johnson_54_augmented_hexagonal_prism_verts[12];
 #local P2 = Johnson_54_augmented_hexagonal_prism_verts[8];
 #local P3 = Johnson_54_augmented_hexagonal_prism_verts[4];
 #local P4 = Johnson_54_augmented_hexagonal_prism_verts[2];
 #local P5 = Johnson_54_augmented_hexagonal_prism_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_54_augmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_54_augmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_54_augmented_hexagonal_prism_faces2(OnPlane)
#local Johnson_54_augmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  13,
  Johnson_54_augmented_hexagonal_prism_verts[0],
  Johnson_54_augmented_hexagonal_prism_verts[1],
  Johnson_54_augmented_hexagonal_prism_verts[2],
  Johnson_54_augmented_hexagonal_prism_verts[3],
  Johnson_54_augmented_hexagonal_prism_verts[4],
  Johnson_54_augmented_hexagonal_prism_verts[5],
  Johnson_54_augmented_hexagonal_prism_verts[6],
  Johnson_54_augmented_hexagonal_prism_verts[7],
  Johnson_54_augmented_hexagonal_prism_verts[8],
  Johnson_54_augmented_hexagonal_prism_verts[9],
  Johnson_54_augmented_hexagonal_prism_verts[10],
  Johnson_54_augmented_hexagonal_prism_verts[11],
  Johnson_54_augmented_hexagonal_prism_verts[12]
 }
 face_indices {
  22,
  <5, 10, 9>,
  <5, 8, 10>,
  <9, 10, 12>,
  <12, 10, 8>,
  <1, 0, 2>,
  <1, 2, 4>,
  <5, 1, 4>,
  <5, 4, 8>,
  <7, 9, 12>,
  <7, 12, 11>,
  <3, 7, 11>,
  <3, 11, 6>,
  <0, 3, 6>,
  <0, 6, 2>,
  <0, 1, 5>,
  <0, 5, 9>,
  <0, 9, 7>,
  <0, 7, 3>,
  <11, 12, 8>,
  <11, 8, 4>,
  <11, 4, 2>,
  <11, 2, 6>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_54_augmented_hexagonal_prism_verts[11];
 #local P1 = Johnson_54_augmented_hexagonal_prism_verts[12];
 #local P2 = Johnson_54_augmented_hexagonal_prism_verts[8];
 #local P3 = Johnson_54_augmented_hexagonal_prism_verts[4];
 #local P4 = Johnson_54_augmented_hexagonal_prism_verts[2];
 #local P5 = Johnson_54_augmented_hexagonal_prism_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_54_augmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_54_augmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_54_augmented_hexagonal_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_54_augmented_hexagonal_prism_verts[0], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[1], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[2], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[3], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[4], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[5], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[6], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[7], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[8], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[9], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[10], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[11], RadVer }
  sphere { Johnson_54_augmented_hexagonal_prism_verts[12], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[5], Johnson_54_augmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[10], Johnson_54_augmented_hexagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[9], Johnson_54_augmented_hexagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[5], Johnson_54_augmented_hexagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[8], Johnson_54_augmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[10], Johnson_54_augmented_hexagonal_prism_verts[12], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[12], Johnson_54_augmented_hexagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[8], Johnson_54_augmented_hexagonal_prism_verts[12], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[1], Johnson_54_augmented_hexagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[0], Johnson_54_augmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[2], Johnson_54_augmented_hexagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[4], Johnson_54_augmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[5], Johnson_54_augmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[4], Johnson_54_augmented_hexagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[7], Johnson_54_augmented_hexagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[12], Johnson_54_augmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[11], Johnson_54_augmented_hexagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[3], Johnson_54_augmented_hexagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[11], Johnson_54_augmented_hexagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[6], Johnson_54_augmented_hexagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[0], Johnson_54_augmented_hexagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_54_augmented_hexagonal_prism_verts[6], Johnson_54_augmented_hexagonal_prism_verts[2], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_54_augmented_hexagonal_prism_verts[11];
 #local P1 = Johnson_54_augmented_hexagonal_prism_verts[12];
 #local P2 = Johnson_54_augmented_hexagonal_prism_verts[8];
 #local P3 = Johnson_54_augmented_hexagonal_prism_verts[4];
 #local P4 = Johnson_54_augmented_hexagonal_prism_verts[2];
 #local P5 = Johnson_54_augmented_hexagonal_prism_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_55_parabiaugmented_hexagonal_prism_verts = array[14]
{
<-1.129559, 0.266324, 0.624401>,
<-0.925111, 0.008507, -0.145991>,
<-0.655368, -0.416841, 0.523404>,
<-0.588300, 0.710070, 0.164074>,
<-0.438148, 0.074567, -0.824427>,
<-0.318557, 0.284721, 0.833470>,
<-0.101337, 0.776130, -0.514362>,
<0.101337, -0.776130, 0.514363>,
<0.318557, -0.284721, -0.833468>,
<0.438148, -0.074567, 0.824429>,
<0.588300, -0.710069, -0.164073>,
<0.655368, 0.416842, -0.523403>,
<0.925111, -0.008507, 0.145993>,
<1.129559, -0.266324, -0.624399>,
}
#declare P0 = Johnson_55_parabiaugmented_hexagonal_prism_verts[4];
#declare P1 = Johnson_55_parabiaugmented_hexagonal_prism_verts[8];
#declare P2 = Johnson_55_parabiaugmented_hexagonal_prism_verts[10];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 14)
 #declare Johnson_55_parabiaugmented_hexagonal_prism_verts[Num] = vtransform(Johnson_55_parabiaugmented_hexagonal_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_55_parabiaugmented_hexagonal_prism_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_55_parabiaugmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_55_parabiaugmented_hexagonal_prism_verts[0],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[1],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[2],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[3],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[4],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[5],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[6],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[7],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[8],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[9],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[10],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[11],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[12],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[13]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  24,
  <12, 13, 11>, 0,
  <12, 10, 13>, 0,
  <11, 13, 8>, 0,
  <8, 13, 10>, 0,
  <3, 0, 5>, 0,
  <3, 1, 0>, 0,
  <5, 0, 2>, 0,
  <2, 0, 1>, 0,
  <9, 5, 2>, 1,
  <9, 2, 7>, 1,
  <12, 9, 7>, 1,
  <12, 7, 10>, 1,
  <6, 11, 8>, 1,
  <6, 8, 4>, 1,
  <3, 6, 4>, 1,
  <3, 4, 1>, 1,
  <5, 9, 12>, 2,
  <5, 12, 11>, 2,
  <5, 11, 6>, 2,
  <5, 6, 3>, 2,
  <4, 8, 10>, 2,
  <4, 10, 7>, 2,
  <4, 7, 2>, 2,
  <4, 2, 1>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_55_parabiaugmented_hexagonal_prism_verts[4];
 #local P1 = Johnson_55_parabiaugmented_hexagonal_prism_verts[8];
 #local P2 = Johnson_55_parabiaugmented_hexagonal_prism_verts[10];
 #local P3 = Johnson_55_parabiaugmented_hexagonal_prism_verts[7];
 #local P4 = Johnson_55_parabiaugmented_hexagonal_prism_verts[2];
 #local P5 = Johnson_55_parabiaugmented_hexagonal_prism_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_55_parabiaugmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_55_parabiaugmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_55_parabiaugmented_hexagonal_prism_faces2(OnPlane)
#local Johnson_55_parabiaugmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_55_parabiaugmented_hexagonal_prism_verts[0],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[1],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[2],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[3],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[4],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[5],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[6],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[7],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[8],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[9],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[10],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[11],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[12],
  Johnson_55_parabiaugmented_hexagonal_prism_verts[13]
 }
 face_indices {
  24,
  <12, 13, 11>,
  <12, 10, 13>,
  <11, 13, 8>,
  <8, 13, 10>,
  <3, 0, 5>,
  <3, 1, 0>,
  <5, 0, 2>,
  <2, 0, 1>,
  <9, 5, 2>,
  <9, 2, 7>,
  <12, 9, 7>,
  <12, 7, 10>,
  <6, 11, 8>,
  <6, 8, 4>,
  <3, 6, 4>,
  <3, 4, 1>,
  <5, 9, 12>,
  <5, 12, 11>,
  <5, 11, 6>,
  <5, 6, 3>,
  <4, 8, 10>,
  <4, 10, 7>,
  <4, 7, 2>,
  <4, 2, 1>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_55_parabiaugmented_hexagonal_prism_verts[4];
 #local P1 = Johnson_55_parabiaugmented_hexagonal_prism_verts[8];
 #local P2 = Johnson_55_parabiaugmented_hexagonal_prism_verts[10];
 #local P3 = Johnson_55_parabiaugmented_hexagonal_prism_verts[7];
 #local P4 = Johnson_55_parabiaugmented_hexagonal_prism_verts[2];
 #local P5 = Johnson_55_parabiaugmented_hexagonal_prism_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_55_parabiaugmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_55_parabiaugmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_55_parabiaugmented_hexagonal_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[0], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[1], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[2], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[3], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[4], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[5], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[6], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[7], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[8], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[9], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[10], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[11], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[12], RadVer }
  sphere { Johnson_55_parabiaugmented_hexagonal_prism_verts[13], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[12], Johnson_55_parabiaugmented_hexagonal_prism_verts[13], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[13], Johnson_55_parabiaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[11], Johnson_55_parabiaugmented_hexagonal_prism_verts[12], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[12], Johnson_55_parabiaugmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[10], Johnson_55_parabiaugmented_hexagonal_prism_verts[13], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[13], Johnson_55_parabiaugmented_hexagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[8], Johnson_55_parabiaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[10], Johnson_55_parabiaugmented_hexagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[3], Johnson_55_parabiaugmented_hexagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[0], Johnson_55_parabiaugmented_hexagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[5], Johnson_55_parabiaugmented_hexagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[3], Johnson_55_parabiaugmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[1], Johnson_55_parabiaugmented_hexagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[0], Johnson_55_parabiaugmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[2], Johnson_55_parabiaugmented_hexagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[1], Johnson_55_parabiaugmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[9], Johnson_55_parabiaugmented_hexagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[2], Johnson_55_parabiaugmented_hexagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[7], Johnson_55_parabiaugmented_hexagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[12], Johnson_55_parabiaugmented_hexagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[7], Johnson_55_parabiaugmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[6], Johnson_55_parabiaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[8], Johnson_55_parabiaugmented_hexagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[4], Johnson_55_parabiaugmented_hexagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[3], Johnson_55_parabiaugmented_hexagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_55_parabiaugmented_hexagonal_prism_verts[4], Johnson_55_parabiaugmented_hexagonal_prism_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_55_parabiaugmented_hexagonal_prism_verts[4];
 #local P1 = Johnson_55_parabiaugmented_hexagonal_prism_verts[8];
 #local P2 = Johnson_55_parabiaugmented_hexagonal_prism_verts[10];
 #local P3 = Johnson_55_parabiaugmented_hexagonal_prism_verts[7];
 #local P4 = Johnson_55_parabiaugmented_hexagonal_prism_verts[2];
 #local P5 = Johnson_55_parabiaugmented_hexagonal_prism_verts[1];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_56_metabiaugmented_hexagonal_prism_verts = array[14]
{
<-1.111755, 0.435562, -0.458586>,
<-0.808867, 0.159752, 0.276420>,
<-0.700013, -0.297342, -0.421621>,
<-0.454926, 0.822531, -0.102389>,
<-0.346072, 0.365437, -0.800430>,
<-0.331474, -0.383478, 0.706586>,
<-0.222620, -0.840572, 0.008545>,
<0.189019, -1.044602, 0.713507>,
<0.376408, 0.942079, -0.051032>,
<0.485263, 0.484985, -0.749073>,
<0.499860, -0.263930, 0.757943>,
<0.608714, -0.721024, 0.059902>,
<0.853802, 0.398849, 0.379134>,
<0.962656, -0.058246, -0.318907>,
}
#declare P0 = Johnson_56_metabiaugmented_hexagonal_prism_verts[6];
#declare P1 = Johnson_56_metabiaugmented_hexagonal_prism_verts[2];
#declare P2 = Johnson_56_metabiaugmented_hexagonal_prism_verts[4];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 14)
 #declare Johnson_56_metabiaugmented_hexagonal_prism_verts[Num] = vtransform(Johnson_56_metabiaugmented_hexagonal_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_56_metabiaugmented_hexagonal_prism_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_56_metabiaugmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_56_metabiaugmented_hexagonal_prism_verts[0],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[1],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[2],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[3],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[4],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[5],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[6],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[7],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[8],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[9],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[10],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[11],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[12],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[13]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  24,
  <3, 0, 1>, 0,
  <3, 4, 0>, 0,
  <1, 0, 2>, 0,
  <2, 0, 4>, 0,
  <5, 7, 10>, 0,
  <5, 6, 7>, 0,
  <10, 7, 11>, 0,
  <11, 7, 6>, 0,
  <8, 12, 13>, 1,
  <8, 13, 9>, 1,
  <3, 8, 9>, 1,
  <3, 9, 4>, 1,
  <5, 1, 2>, 1,
  <5, 2, 6>, 1,
  <12, 10, 11>, 1,
  <12, 11, 13>, 1,
  <12, 8, 3>, 2,
  <12, 3, 1>, 2,
  <12, 1, 5>, 2,
  <12, 5, 10>, 2,
  <6, 2, 4>, 2,
  <6, 4, 9>, 2,
  <6, 9, 13>, 2,
  <6, 13, 11>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_56_metabiaugmented_hexagonal_prism_verts[6];
 #local P1 = Johnson_56_metabiaugmented_hexagonal_prism_verts[2];
 #local P2 = Johnson_56_metabiaugmented_hexagonal_prism_verts[4];
 #local P3 = Johnson_56_metabiaugmented_hexagonal_prism_verts[9];
 #local P4 = Johnson_56_metabiaugmented_hexagonal_prism_verts[13];
 #local P5 = Johnson_56_metabiaugmented_hexagonal_prism_verts[11];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_56_metabiaugmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_56_metabiaugmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_56_metabiaugmented_hexagonal_prism_faces2(OnPlane)
#local Johnson_56_metabiaugmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_56_metabiaugmented_hexagonal_prism_verts[0],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[1],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[2],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[3],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[4],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[5],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[6],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[7],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[8],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[9],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[10],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[11],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[12],
  Johnson_56_metabiaugmented_hexagonal_prism_verts[13]
 }
 face_indices {
  24,
  <3, 0, 1>,
  <3, 4, 0>,
  <1, 0, 2>,
  <2, 0, 4>,
  <5, 7, 10>,
  <5, 6, 7>,
  <10, 7, 11>,
  <11, 7, 6>,
  <8, 12, 13>,
  <8, 13, 9>,
  <3, 8, 9>,
  <3, 9, 4>,
  <5, 1, 2>,
  <5, 2, 6>,
  <12, 10, 11>,
  <12, 11, 13>,
  <12, 8, 3>,
  <12, 3, 1>,
  <12, 1, 5>,
  <12, 5, 10>,
  <6, 2, 4>,
  <6, 4, 9>,
  <6, 9, 13>,
  <6, 13, 11>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_56_metabiaugmented_hexagonal_prism_verts[6];
 #local P1 = Johnson_56_metabiaugmented_hexagonal_prism_verts[2];
 #local P2 = Johnson_56_metabiaugmented_hexagonal_prism_verts[4];
 #local P3 = Johnson_56_metabiaugmented_hexagonal_prism_verts[9];
 #local P4 = Johnson_56_metabiaugmented_hexagonal_prism_verts[13];
 #local P5 = Johnson_56_metabiaugmented_hexagonal_prism_verts[11];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_56_metabiaugmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_56_metabiaugmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_56_metabiaugmented_hexagonal_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[0], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[1], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[2], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[3], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[4], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[5], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[6], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[7], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[8], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[9], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[10], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[11], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[12], RadVer }
  sphere { Johnson_56_metabiaugmented_hexagonal_prism_verts[13], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[3], Johnson_56_metabiaugmented_hexagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[0], Johnson_56_metabiaugmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[1], Johnson_56_metabiaugmented_hexagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[3], Johnson_56_metabiaugmented_hexagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[4], Johnson_56_metabiaugmented_hexagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[0], Johnson_56_metabiaugmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[2], Johnson_56_metabiaugmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[4], Johnson_56_metabiaugmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[5], Johnson_56_metabiaugmented_hexagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[7], Johnson_56_metabiaugmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[10], Johnson_56_metabiaugmented_hexagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[5], Johnson_56_metabiaugmented_hexagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[6], Johnson_56_metabiaugmented_hexagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[7], Johnson_56_metabiaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[11], Johnson_56_metabiaugmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[6], Johnson_56_metabiaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[8], Johnson_56_metabiaugmented_hexagonal_prism_verts[12], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[12], Johnson_56_metabiaugmented_hexagonal_prism_verts[13], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[13], Johnson_56_metabiaugmented_hexagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[9], Johnson_56_metabiaugmented_hexagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[3], Johnson_56_metabiaugmented_hexagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[9], Johnson_56_metabiaugmented_hexagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[5], Johnson_56_metabiaugmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[2], Johnson_56_metabiaugmented_hexagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[12], Johnson_56_metabiaugmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_56_metabiaugmented_hexagonal_prism_verts[11], Johnson_56_metabiaugmented_hexagonal_prism_verts[13], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_56_metabiaugmented_hexagonal_prism_verts[6];
 #local P1 = Johnson_56_metabiaugmented_hexagonal_prism_verts[2];
 #local P2 = Johnson_56_metabiaugmented_hexagonal_prism_verts[4];
 #local P3 = Johnson_56_metabiaugmented_hexagonal_prism_verts[9];
 #local P4 = Johnson_56_metabiaugmented_hexagonal_prism_verts[13];
 #local P5 = Johnson_56_metabiaugmented_hexagonal_prism_verts[11];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_57_triaugmented_hexagonal_prism_verts = array[15]
{
<-0.902174, -0.044182, -0.142406>,
<-0.852256, -0.160380, -0.950443>,
<-0.656940, 0.352221, 0.529639>,
<-0.484062, 0.483825, -0.606421>,
<-0.454289, -0.660407, -0.440037>,
<-0.238829, 0.880229, 0.065624>,
<-0.184058, 0.919718, 0.880707>,
<-0.036177, -0.132400, -0.904053>,
<0.036178, 0.132400, 0.904052>,
<0.238829, -0.880229, -0.065625>,
<0.454289, 0.660407, 0.440037>,
<0.484063, -0.483825, 0.606420>,
<0.656941, -0.352221, -0.529640>,
<0.902174, 0.044182, 0.142405>,
<1.036314, -0.759338, 0.069736>,
}
#declare P0 = Johnson_57_triaugmented_hexagonal_prism_verts[10];
#declare P1 = Johnson_57_triaugmented_hexagonal_prism_verts[13];
#declare P2 = Johnson_57_triaugmented_hexagonal_prism_verts[12];
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
 #declare Johnson_57_triaugmented_hexagonal_prism_verts[Num] = vtransform(Johnson_57_triaugmented_hexagonal_prism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_57_triaugmented_hexagonal_prism_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_57_triaugmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_57_triaugmented_hexagonal_prism_verts[0],
  Johnson_57_triaugmented_hexagonal_prism_verts[1],
  Johnson_57_triaugmented_hexagonal_prism_verts[2],
  Johnson_57_triaugmented_hexagonal_prism_verts[3],
  Johnson_57_triaugmented_hexagonal_prism_verts[4],
  Johnson_57_triaugmented_hexagonal_prism_verts[5],
  Johnson_57_triaugmented_hexagonal_prism_verts[6],
  Johnson_57_triaugmented_hexagonal_prism_verts[7],
  Johnson_57_triaugmented_hexagonal_prism_verts[8],
  Johnson_57_triaugmented_hexagonal_prism_verts[9],
  Johnson_57_triaugmented_hexagonal_prism_verts[10],
  Johnson_57_triaugmented_hexagonal_prism_verts[11],
  Johnson_57_triaugmented_hexagonal_prism_verts[12],
  Johnson_57_triaugmented_hexagonal_prism_verts[13],
  Johnson_57_triaugmented_hexagonal_prism_verts[14]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  26,
  <9, 14, 11>, 0,
  <9, 12, 14>, 0,
  <11, 14, 13>, 0,
  <13, 14, 12>, 0,
  <8, 6, 2>, 0,
  <8, 10, 6>, 0,
  <2, 6, 5>, 0,
  <5, 6, 10>, 0,
  <0, 1, 4>, 0,
  <0, 3, 1>, 0,
  <4, 1, 7>, 0,
  <7, 1, 3>, 0,
  <9, 4, 7>, 1,
  <9, 7, 12>, 1,
  <8, 11, 13>, 1,
  <8, 13, 10>, 1,
  <0, 2, 5>, 1,
  <0, 5, 3>, 1,
  <0, 4, 9>, 2,
  <0, 9, 11>, 2,
  <0, 11, 8>, 2,
  <0, 8, 2>, 2,
  <10, 13, 12>, 2,
  <10, 12, 7>, 2,
  <10, 7, 3>, 2,
  <10, 3, 5>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_57_triaugmented_hexagonal_prism_verts[10];
 #local P1 = Johnson_57_triaugmented_hexagonal_prism_verts[13];
 #local P2 = Johnson_57_triaugmented_hexagonal_prism_verts[12];
 #local P3 = Johnson_57_triaugmented_hexagonal_prism_verts[7];
 #local P4 = Johnson_57_triaugmented_hexagonal_prism_verts[3];
 #local P5 = Johnson_57_triaugmented_hexagonal_prism_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_57_triaugmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_57_triaugmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_57_triaugmented_hexagonal_prism_faces2(OnPlane)
#local Johnson_57_triaugmented_hexagonal_prism_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_57_triaugmented_hexagonal_prism_verts[0],
  Johnson_57_triaugmented_hexagonal_prism_verts[1],
  Johnson_57_triaugmented_hexagonal_prism_verts[2],
  Johnson_57_triaugmented_hexagonal_prism_verts[3],
  Johnson_57_triaugmented_hexagonal_prism_verts[4],
  Johnson_57_triaugmented_hexagonal_prism_verts[5],
  Johnson_57_triaugmented_hexagonal_prism_verts[6],
  Johnson_57_triaugmented_hexagonal_prism_verts[7],
  Johnson_57_triaugmented_hexagonal_prism_verts[8],
  Johnson_57_triaugmented_hexagonal_prism_verts[9],
  Johnson_57_triaugmented_hexagonal_prism_verts[10],
  Johnson_57_triaugmented_hexagonal_prism_verts[11],
  Johnson_57_triaugmented_hexagonal_prism_verts[12],
  Johnson_57_triaugmented_hexagonal_prism_verts[13],
  Johnson_57_triaugmented_hexagonal_prism_verts[14]
 }
 face_indices {
  26,
  <9, 14, 11>,
  <9, 12, 14>,
  <11, 14, 13>,
  <13, 14, 12>,
  <8, 6, 2>,
  <8, 10, 6>,
  <2, 6, 5>,
  <5, 6, 10>,
  <0, 1, 4>,
  <0, 3, 1>,
  <4, 1, 7>,
  <7, 1, 3>,
  <9, 4, 7>,
  <9, 7, 12>,
  <8, 11, 13>,
  <8, 13, 10>,
  <0, 2, 5>,
  <0, 5, 3>,
  <0, 4, 9>,
  <0, 9, 11>,
  <0, 11, 8>,
  <0, 8, 2>,
  <10, 13, 12>,
  <10, 12, 7>,
  <10, 7, 3>,
  <10, 3, 5>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_57_triaugmented_hexagonal_prism_verts[10];
 #local P1 = Johnson_57_triaugmented_hexagonal_prism_verts[13];
 #local P2 = Johnson_57_triaugmented_hexagonal_prism_verts[12];
 #local P3 = Johnson_57_triaugmented_hexagonal_prism_verts[7];
 #local P4 = Johnson_57_triaugmented_hexagonal_prism_verts[3];
 #local P5 = Johnson_57_triaugmented_hexagonal_prism_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_57_triaugmented_hexagonal_prism_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_57_triaugmented_hexagonal_prism_obj }
#end
#end

#macro Johnson_57_triaugmented_hexagonal_prism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[0], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[1], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[2], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[3], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[4], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[5], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[6], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[7], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[8], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[9], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[10], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[11], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[12], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[13], RadVer }
  sphere { Johnson_57_triaugmented_hexagonal_prism_verts[14], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[9], Johnson_57_triaugmented_hexagonal_prism_verts[14], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[14], Johnson_57_triaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[11], Johnson_57_triaugmented_hexagonal_prism_verts[9], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[9], Johnson_57_triaugmented_hexagonal_prism_verts[12], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[12], Johnson_57_triaugmented_hexagonal_prism_verts[14], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[14], Johnson_57_triaugmented_hexagonal_prism_verts[13], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[13], Johnson_57_triaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[12], Johnson_57_triaugmented_hexagonal_prism_verts[13], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[8], Johnson_57_triaugmented_hexagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[6], Johnson_57_triaugmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[2], Johnson_57_triaugmented_hexagonal_prism_verts[8], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[8], Johnson_57_triaugmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[10], Johnson_57_triaugmented_hexagonal_prism_verts[6], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[6], Johnson_57_triaugmented_hexagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[5], Johnson_57_triaugmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[10], Johnson_57_triaugmented_hexagonal_prism_verts[5], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[0], Johnson_57_triaugmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[1], Johnson_57_triaugmented_hexagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[4], Johnson_57_triaugmented_hexagonal_prism_verts[0], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[0], Johnson_57_triaugmented_hexagonal_prism_verts[3], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[3], Johnson_57_triaugmented_hexagonal_prism_verts[1], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[1], Johnson_57_triaugmented_hexagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[7], Johnson_57_triaugmented_hexagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[3], Johnson_57_triaugmented_hexagonal_prism_verts[7], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[9], Johnson_57_triaugmented_hexagonal_prism_verts[4], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[7], Johnson_57_triaugmented_hexagonal_prism_verts[12], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[8], Johnson_57_triaugmented_hexagonal_prism_verts[11], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[13], Johnson_57_triaugmented_hexagonal_prism_verts[10], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[0], Johnson_57_triaugmented_hexagonal_prism_verts[2], RadEdg }
  cylinder { Johnson_57_triaugmented_hexagonal_prism_verts[5], Johnson_57_triaugmented_hexagonal_prism_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_57_triaugmented_hexagonal_prism_verts[10];
 #local P1 = Johnson_57_triaugmented_hexagonal_prism_verts[13];
 #local P2 = Johnson_57_triaugmented_hexagonal_prism_verts[12];
 #local P3 = Johnson_57_triaugmented_hexagonal_prism_verts[7];
 #local P4 = Johnson_57_triaugmented_hexagonal_prism_verts[3];
 #local P5 = Johnson_57_triaugmented_hexagonal_prism_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
