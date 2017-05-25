/* -------------------
johnson_solids_group7.inc

Miscellaneous

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Johnson_84_snub_disphenoid (8 vertices)
  Johnson_85_snub_square_antiprism (16 vertices)
  Johnson_86_sphenocorona (10 vertices)
  Johnson_87_augmented_sphenocorona (11 vertices)
  Johnson_88_sphenomegacorona (12 vertices)
  Johnson_89_hebesphenomegacorona (14 vertices)
  Johnson_90_disphenocingulum (16 vertices)
  Johnson_91_bilunabirotunda (14 vertices)
  Johnson_92_triangular_hebesphenorotunda (18 vertices)

-------------------- */

#include "transforms.inc"

#declare Johnson_84_snub_disphenoid_verts = array[8]
{
<-0.768016, 0.559678, 0.635844>,
<-0.720709, -0.093633, -0.405339>,
<-0.635800, -0.662351, 0.681929>,
<0.098480, 0.800885, -0.202562>,
<0.269587, -0.774160, -0.143135>,
<0.285934, -0.010665, -1.107297>,
<0.352377, 0.066396, 0.750712>,
<1.118151, 0.113850, -0.210152>,
}
#declare P0 = Johnson_84_snub_disphenoid_verts[0];
#declare P1 = Johnson_84_snub_disphenoid_verts[6];
#declare P2 = Johnson_84_snub_disphenoid_verts[3];
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
 #declare Johnson_84_snub_disphenoid_verts[Num] = vtransform(Johnson_84_snub_disphenoid_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_84_snub_disphenoid_faces(Tex3, OnPlane)
#local Johnson_84_snub_disphenoid_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_84_snub_disphenoid_verts[0],
  Johnson_84_snub_disphenoid_verts[1],
  Johnson_84_snub_disphenoid_verts[2],
  Johnson_84_snub_disphenoid_verts[3],
  Johnson_84_snub_disphenoid_verts[4],
  Johnson_84_snub_disphenoid_verts[5],
  Johnson_84_snub_disphenoid_verts[6],
  Johnson_84_snub_disphenoid_verts[7]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  12,
  <6, 7, 3>, 0,
  <3, 7, 5>, 0,
  <3, 5, 1>, 0,
  <4, 7, 6>, 0,
  <7, 4, 5>, 0,
  <5, 4, 1>, 0,
  <4, 2, 1>, 0,
  <1, 2, 0>, 0,
  <1, 0, 3>, 0,
  <6, 2, 4>, 0,
  <2, 6, 0>, 0,
  <0, 6, 3>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_84_snub_disphenoid_verts[0];
 #local P1 = Johnson_84_snub_disphenoid_verts[6];
 #local P2 = Johnson_84_snub_disphenoid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_84_snub_disphenoid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_84_snub_disphenoid_obj }
#end
#end

#macro Johnson_84_snub_disphenoid_faces2(OnPlane)
#local Johnson_84_snub_disphenoid_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_84_snub_disphenoid_verts[0],
  Johnson_84_snub_disphenoid_verts[1],
  Johnson_84_snub_disphenoid_verts[2],
  Johnson_84_snub_disphenoid_verts[3],
  Johnson_84_snub_disphenoid_verts[4],
  Johnson_84_snub_disphenoid_verts[5],
  Johnson_84_snub_disphenoid_verts[6],
  Johnson_84_snub_disphenoid_verts[7]
 }
 face_indices {
  12,
  <6, 7, 3>,
  <3, 7, 5>,
  <3, 5, 1>,
  <4, 7, 6>,
  <7, 4, 5>,
  <5, 4, 1>,
  <4, 2, 1>,
  <1, 2, 0>,
  <1, 0, 3>,
  <6, 2, 4>,
  <2, 6, 0>,
  <0, 6, 3>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_84_snub_disphenoid_verts[0];
 #local P1 = Johnson_84_snub_disphenoid_verts[6];
 #local P2 = Johnson_84_snub_disphenoid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_84_snub_disphenoid_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_84_snub_disphenoid_obj }
#end
#end

#macro Johnson_84_snub_disphenoid_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_84_snub_disphenoid_verts[0], RadVer }
  sphere { Johnson_84_snub_disphenoid_verts[1], RadVer }
  sphere { Johnson_84_snub_disphenoid_verts[2], RadVer }
  sphere { Johnson_84_snub_disphenoid_verts[3], RadVer }
  sphere { Johnson_84_snub_disphenoid_verts[4], RadVer }
  sphere { Johnson_84_snub_disphenoid_verts[5], RadVer }
  sphere { Johnson_84_snub_disphenoid_verts[6], RadVer }
  sphere { Johnson_84_snub_disphenoid_verts[7], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_84_snub_disphenoid_verts[6], Johnson_84_snub_disphenoid_verts[7], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[7], Johnson_84_snub_disphenoid_verts[3], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[3], Johnson_84_snub_disphenoid_verts[6], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[7], Johnson_84_snub_disphenoid_verts[5], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[5], Johnson_84_snub_disphenoid_verts[3], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[5], Johnson_84_snub_disphenoid_verts[1], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[1], Johnson_84_snub_disphenoid_verts[3], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[4], Johnson_84_snub_disphenoid_verts[7], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[6], Johnson_84_snub_disphenoid_verts[4], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[4], Johnson_84_snub_disphenoid_verts[5], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[4], Johnson_84_snub_disphenoid_verts[1], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[4], Johnson_84_snub_disphenoid_verts[2], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[2], Johnson_84_snub_disphenoid_verts[1], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[2], Johnson_84_snub_disphenoid_verts[0], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[0], Johnson_84_snub_disphenoid_verts[1], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[0], Johnson_84_snub_disphenoid_verts[3], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[6], Johnson_84_snub_disphenoid_verts[2], RadEdg }
  cylinder { Johnson_84_snub_disphenoid_verts[6], Johnson_84_snub_disphenoid_verts[0], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_84_snub_disphenoid_verts[0];
 #local P1 = Johnson_84_snub_disphenoid_verts[6];
 #local P2 = Johnson_84_snub_disphenoid_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_85_snub_square_antiprism_verts = array[16]
{
<-0.984789, 0.388776, -0.318546>,
<-0.905986, -0.506450, -0.380955>,
<-0.774402, -0.096785, 0.410496>,
<-0.648503, 0.795226, 0.411689>,
<-0.327620, 0.028199, -0.818195>,
<-0.278924, -0.815280, 0.187334>,
<-0.177548, 0.786870, -0.356208>,
<-0.134682, -0.843968, -0.701432>,
<-0.066690, 0.257644, 0.840681>,
<0.229454, 0.996879, 0.419536>,
<0.428788, -0.460851, 0.617519>,
<0.523163, -0.229235, -0.671807>,
<0.553730, -0.948137, -0.129793>,
<0.673235, 0.529435, -0.209820>,
<0.811213, 0.353538, 0.662851>,
<1.079561, -0.235865, 0.036650>,
}
#declare P0 = Johnson_85_snub_square_antiprism_verts[2];
#declare P1 = Johnson_85_snub_square_antiprism_verts[5];
#declare P2 = Johnson_85_snub_square_antiprism_verts[10];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 16)
 #declare Johnson_85_snub_square_antiprism_verts[Num] = vtransform(Johnson_85_snub_square_antiprism_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_85_snub_square_antiprism_faces(Tex3, Tex4, OnPlane)
#local Johnson_85_snub_square_antiprism_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_85_snub_square_antiprism_verts[0],
  Johnson_85_snub_square_antiprism_verts[1],
  Johnson_85_snub_square_antiprism_verts[2],
  Johnson_85_snub_square_antiprism_verts[3],
  Johnson_85_snub_square_antiprism_verts[4],
  Johnson_85_snub_square_antiprism_verts[5],
  Johnson_85_snub_square_antiprism_verts[6],
  Johnson_85_snub_square_antiprism_verts[7],
  Johnson_85_snub_square_antiprism_verts[8],
  Johnson_85_snub_square_antiprism_verts[9],
  Johnson_85_snub_square_antiprism_verts[10],
  Johnson_85_snub_square_antiprism_verts[11],
  Johnson_85_snub_square_antiprism_verts[12],
  Johnson_85_snub_square_antiprism_verts[13],
  Johnson_85_snub_square_antiprism_verts[14],
  Johnson_85_snub_square_antiprism_verts[15]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  28,
  <13, 9, 14>, 0,
  <9, 13, 6>, 0,
  <9, 6, 3>, 0,
  <11, 15, 12>, 0,
  <15, 11, 13>, 0,
  <15, 13, 14>, 0,
  <4, 7, 1>, 0,
  <7, 4, 11>, 0,
  <7, 11, 12>, 0,
  <6, 0, 3>, 0,
  <0, 6, 4>, 0,
  <0, 4, 1>, 0,
  <2, 3, 0>, 0,
  <3, 2, 8>, 0,
  <3, 8, 9>, 0,
  <5, 1, 7>, 0,
  <1, 5, 2>, 0,
  <1, 2, 0>, 0,
  <10, 12, 15>, 0,
  <12, 10, 5>, 0,
  <12, 5, 7>, 0,
  <8, 14, 9>, 0,
  <14, 8, 10>, 0,
  <14, 10, 15>, 0,
  <13, 11, 4>, 1,
  <13, 4, 6>, 1,
  <2, 5, 10>, 1,
  <2, 10, 8>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_85_snub_square_antiprism_verts[2];
 #local P1 = Johnson_85_snub_square_antiprism_verts[5];
 #local P2 = Johnson_85_snub_square_antiprism_verts[10];
 #local P3 = Johnson_85_snub_square_antiprism_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_85_snub_square_antiprism_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_85_snub_square_antiprism_obj }
#end
#end

#macro Johnson_85_snub_square_antiprism_faces2(OnPlane)
#local Johnson_85_snub_square_antiprism_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_85_snub_square_antiprism_verts[0],
  Johnson_85_snub_square_antiprism_verts[1],
  Johnson_85_snub_square_antiprism_verts[2],
  Johnson_85_snub_square_antiprism_verts[3],
  Johnson_85_snub_square_antiprism_verts[4],
  Johnson_85_snub_square_antiprism_verts[5],
  Johnson_85_snub_square_antiprism_verts[6],
  Johnson_85_snub_square_antiprism_verts[7],
  Johnson_85_snub_square_antiprism_verts[8],
  Johnson_85_snub_square_antiprism_verts[9],
  Johnson_85_snub_square_antiprism_verts[10],
  Johnson_85_snub_square_antiprism_verts[11],
  Johnson_85_snub_square_antiprism_verts[12],
  Johnson_85_snub_square_antiprism_verts[13],
  Johnson_85_snub_square_antiprism_verts[14],
  Johnson_85_snub_square_antiprism_verts[15]
 }
 face_indices {
  28,
  <13, 9, 14>,
  <9, 13, 6>,
  <9, 6, 3>,
  <11, 15, 12>,
  <15, 11, 13>,
  <15, 13, 14>,
  <4, 7, 1>,
  <7, 4, 11>,
  <7, 11, 12>,
  <6, 0, 3>,
  <0, 6, 4>,
  <0, 4, 1>,
  <2, 3, 0>,
  <3, 2, 8>,
  <3, 8, 9>,
  <5, 1, 7>,
  <1, 5, 2>,
  <1, 2, 0>,
  <10, 12, 15>,
  <12, 10, 5>,
  <12, 5, 7>,
  <8, 14, 9>,
  <14, 8, 10>,
  <14, 10, 15>,
  <13, 11, 4>,
  <13, 4, 6>,
  <2, 5, 10>,
  <2, 10, 8>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_85_snub_square_antiprism_verts[2];
 #local P1 = Johnson_85_snub_square_antiprism_verts[5];
 #local P2 = Johnson_85_snub_square_antiprism_verts[10];
 #local P3 = Johnson_85_snub_square_antiprism_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_85_snub_square_antiprism_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_85_snub_square_antiprism_obj }
#end
#end

#macro Johnson_85_snub_square_antiprism_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_85_snub_square_antiprism_verts[0], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[1], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[2], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[3], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[4], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[5], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[6], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[7], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[8], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[9], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[10], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[11], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[12], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[13], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[14], RadVer }
  sphere { Johnson_85_snub_square_antiprism_verts[15], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_85_snub_square_antiprism_verts[13], Johnson_85_snub_square_antiprism_verts[9], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[9], Johnson_85_snub_square_antiprism_verts[14], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[14], Johnson_85_snub_square_antiprism_verts[13], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[13], Johnson_85_snub_square_antiprism_verts[6], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[6], Johnson_85_snub_square_antiprism_verts[9], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[6], Johnson_85_snub_square_antiprism_verts[3], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[3], Johnson_85_snub_square_antiprism_verts[9], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[11], Johnson_85_snub_square_antiprism_verts[15], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[15], Johnson_85_snub_square_antiprism_verts[12], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[12], Johnson_85_snub_square_antiprism_verts[11], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[11], Johnson_85_snub_square_antiprism_verts[13], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[13], Johnson_85_snub_square_antiprism_verts[15], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[14], Johnson_85_snub_square_antiprism_verts[15], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[4], Johnson_85_snub_square_antiprism_verts[7], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[7], Johnson_85_snub_square_antiprism_verts[1], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[1], Johnson_85_snub_square_antiprism_verts[4], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[4], Johnson_85_snub_square_antiprism_verts[11], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[11], Johnson_85_snub_square_antiprism_verts[7], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[12], Johnson_85_snub_square_antiprism_verts[7], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[6], Johnson_85_snub_square_antiprism_verts[0], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[0], Johnson_85_snub_square_antiprism_verts[3], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[6], Johnson_85_snub_square_antiprism_verts[4], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[4], Johnson_85_snub_square_antiprism_verts[0], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[1], Johnson_85_snub_square_antiprism_verts[0], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[2], Johnson_85_snub_square_antiprism_verts[3], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[0], Johnson_85_snub_square_antiprism_verts[2], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[2], Johnson_85_snub_square_antiprism_verts[8], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[8], Johnson_85_snub_square_antiprism_verts[3], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[8], Johnson_85_snub_square_antiprism_verts[9], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[5], Johnson_85_snub_square_antiprism_verts[1], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[7], Johnson_85_snub_square_antiprism_verts[5], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[5], Johnson_85_snub_square_antiprism_verts[2], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[2], Johnson_85_snub_square_antiprism_verts[1], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[10], Johnson_85_snub_square_antiprism_verts[12], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[15], Johnson_85_snub_square_antiprism_verts[10], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[10], Johnson_85_snub_square_antiprism_verts[5], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[5], Johnson_85_snub_square_antiprism_verts[12], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[8], Johnson_85_snub_square_antiprism_verts[14], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[8], Johnson_85_snub_square_antiprism_verts[10], RadEdg }
  cylinder { Johnson_85_snub_square_antiprism_verts[10], Johnson_85_snub_square_antiprism_verts[14], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_85_snub_square_antiprism_verts[2];
 #local P1 = Johnson_85_snub_square_antiprism_verts[5];
 #local P2 = Johnson_85_snub_square_antiprism_verts[10];
 #local P3 = Johnson_85_snub_square_antiprism_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_86_sphenocorona_verts = array[10]
{
<-1.101650, -0.110367, -0.010645>,
<-0.640942, 0.825699, 0.365159>,
<-0.414409, 0.468967, -0.660083>,
<-0.324965, -0.634882, -0.603383>,
<-0.317654, -0.702618, 0.503439>,
<0.143053, 0.233445, 0.879242>,
<0.402426, 0.843030, -0.010043>,
<0.585642, -0.008843, -0.695930>,
<0.603895, -0.925247, -0.071780>,
<1.064602, 0.010817, 0.304023>,
}
#declare P0 = Johnson_86_sphenocorona_verts[5];
#declare P1 = Johnson_86_sphenocorona_verts[4];
#declare P2 = Johnson_86_sphenocorona_verts[8];
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
 #declare Johnson_86_sphenocorona_verts[Num] = vtransform(Johnson_86_sphenocorona_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_86_sphenocorona_faces(Tex3, Tex4, OnPlane)
#local Johnson_86_sphenocorona_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_86_sphenocorona_verts[0],
  Johnson_86_sphenocorona_verts[1],
  Johnson_86_sphenocorona_verts[2],
  Johnson_86_sphenocorona_verts[3],
  Johnson_86_sphenocorona_verts[4],
  Johnson_86_sphenocorona_verts[5],
  Johnson_86_sphenocorona_verts[6],
  Johnson_86_sphenocorona_verts[7],
  Johnson_86_sphenocorona_verts[8],
  Johnson_86_sphenocorona_verts[9]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  16,
  <7, 3, 2>, 0,
  <2, 1, 6>, 0,
  <2, 3, 0>, 0,
  <2, 0, 1>, 0,
  <1, 5, 6>, 0,
  <6, 5, 9>, 0,
  <3, 4, 0>, 0,
  <4, 3, 8>, 0,
  <9, 7, 6>, 0,
  <9, 8, 7>, 0,
  <7, 8, 3>, 0,
  <6, 7, 2>, 0,
  <1, 0, 4>, 1,
  <1, 4, 5>, 1,
  <5, 4, 8>, 1,
  <5, 8, 9>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_86_sphenocorona_verts[5];
 #local P1 = Johnson_86_sphenocorona_verts[4];
 #local P2 = Johnson_86_sphenocorona_verts[8];
 #local P3 = Johnson_86_sphenocorona_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_86_sphenocorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_86_sphenocorona_obj }
#end
#end

#macro Johnson_86_sphenocorona_faces2(OnPlane)
#local Johnson_86_sphenocorona_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_86_sphenocorona_verts[0],
  Johnson_86_sphenocorona_verts[1],
  Johnson_86_sphenocorona_verts[2],
  Johnson_86_sphenocorona_verts[3],
  Johnson_86_sphenocorona_verts[4],
  Johnson_86_sphenocorona_verts[5],
  Johnson_86_sphenocorona_verts[6],
  Johnson_86_sphenocorona_verts[7],
  Johnson_86_sphenocorona_verts[8],
  Johnson_86_sphenocorona_verts[9]
 }
 face_indices {
  16,
  <7, 3, 2>,
  <2, 1, 6>,
  <2, 3, 0>,
  <2, 0, 1>,
  <1, 5, 6>,
  <6, 5, 9>,
  <3, 4, 0>,
  <4, 3, 8>,
  <9, 7, 6>,
  <9, 8, 7>,
  <7, 8, 3>,
  <6, 7, 2>,
  <1, 0, 4>,
  <1, 4, 5>,
  <5, 4, 8>,
  <5, 8, 9>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_86_sphenocorona_verts[5];
 #local P1 = Johnson_86_sphenocorona_verts[4];
 #local P2 = Johnson_86_sphenocorona_verts[8];
 #local P3 = Johnson_86_sphenocorona_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_86_sphenocorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_86_sphenocorona_obj }
#end
#end

#macro Johnson_86_sphenocorona_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_86_sphenocorona_verts[0], RadVer }
  sphere { Johnson_86_sphenocorona_verts[1], RadVer }
  sphere { Johnson_86_sphenocorona_verts[2], RadVer }
  sphere { Johnson_86_sphenocorona_verts[3], RadVer }
  sphere { Johnson_86_sphenocorona_verts[4], RadVer }
  sphere { Johnson_86_sphenocorona_verts[5], RadVer }
  sphere { Johnson_86_sphenocorona_verts[6], RadVer }
  sphere { Johnson_86_sphenocorona_verts[7], RadVer }
  sphere { Johnson_86_sphenocorona_verts[8], RadVer }
  sphere { Johnson_86_sphenocorona_verts[9], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_86_sphenocorona_verts[7], Johnson_86_sphenocorona_verts[3], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[3], Johnson_86_sphenocorona_verts[2], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[2], Johnson_86_sphenocorona_verts[7], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[2], Johnson_86_sphenocorona_verts[1], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[1], Johnson_86_sphenocorona_verts[6], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[6], Johnson_86_sphenocorona_verts[2], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[3], Johnson_86_sphenocorona_verts[0], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[0], Johnson_86_sphenocorona_verts[2], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[0], Johnson_86_sphenocorona_verts[1], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[1], Johnson_86_sphenocorona_verts[5], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[5], Johnson_86_sphenocorona_verts[6], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[5], Johnson_86_sphenocorona_verts[9], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[9], Johnson_86_sphenocorona_verts[6], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[3], Johnson_86_sphenocorona_verts[4], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[4], Johnson_86_sphenocorona_verts[0], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[3], Johnson_86_sphenocorona_verts[8], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[8], Johnson_86_sphenocorona_verts[4], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[9], Johnson_86_sphenocorona_verts[7], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[7], Johnson_86_sphenocorona_verts[6], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[9], Johnson_86_sphenocorona_verts[8], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[8], Johnson_86_sphenocorona_verts[7], RadEdg }
  cylinder { Johnson_86_sphenocorona_verts[4], Johnson_86_sphenocorona_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_86_sphenocorona_verts[5];
 #local P1 = Johnson_86_sphenocorona_verts[4];
 #local P2 = Johnson_86_sphenocorona_verts[8];
 #local P3 = Johnson_86_sphenocorona_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_87_augmented_sphenocorona_verts = array[11]
{
<-0.858193, -0.792464, 0.432564>,
<-0.785643, 0.057917, -0.211154>,
<-0.533044, 0.147795, 0.823687>,
<-0.229952, 0.904287, 0.131849>,
<-0.212337, 0.637025, -0.903062>,
<-0.091064, -0.748583, -0.310653>,
<0.161537, -0.658707, 0.724189>,
<0.482242, -0.169476, -1.002562>,
<0.505859, 0.352206, 0.676436>,
<0.693906, 0.639069, -0.336051>,
<0.866690, -0.369064, -0.025245>,
}
#declare P0 = Johnson_87_augmented_sphenocorona_verts[5];
#declare P1 = Johnson_87_augmented_sphenocorona_verts[1];
#declare P2 = Johnson_87_augmented_sphenocorona_verts[4];
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
 #declare Johnson_87_augmented_sphenocorona_verts[Num] = vtransform(Johnson_87_augmented_sphenocorona_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_87_augmented_sphenocorona_faces(Tex3, Tex4, OnPlane)
#local Johnson_87_augmented_sphenocorona_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_87_augmented_sphenocorona_verts[0],
  Johnson_87_augmented_sphenocorona_verts[1],
  Johnson_87_augmented_sphenocorona_verts[2],
  Johnson_87_augmented_sphenocorona_verts[3],
  Johnson_87_augmented_sphenocorona_verts[4],
  Johnson_87_augmented_sphenocorona_verts[5],
  Johnson_87_augmented_sphenocorona_verts[6],
  Johnson_87_augmented_sphenocorona_verts[7],
  Johnson_87_augmented_sphenocorona_verts[8],
  Johnson_87_augmented_sphenocorona_verts[9],
  Johnson_87_augmented_sphenocorona_verts[10]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  18,
  <5, 0, 1>, 0,
  <9, 3, 8>, 0,
  <8, 6, 10>, 0,
  <8, 3, 2>, 0,
  <8, 2, 6>, 0,
  <6, 5, 10>, 0,
  <10, 5, 7>, 0,
  <3, 1, 2>, 0,
  <1, 3, 4>, 0,
  <7, 9, 10>, 0,
  <7, 4, 9>, 0,
  <9, 4, 3>, 0,
  <10, 9, 8>, 0,
  <6, 0, 5>, 0,
  <6, 2, 0>, 0,
  <0, 2, 1>, 0,
  <5, 1, 4>, 1,
  <5, 4, 7>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_87_augmented_sphenocorona_verts[5];
 #local P1 = Johnson_87_augmented_sphenocorona_verts[1];
 #local P2 = Johnson_87_augmented_sphenocorona_verts[4];
 #local P3 = Johnson_87_augmented_sphenocorona_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_87_augmented_sphenocorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_87_augmented_sphenocorona_obj }
#end
#end

#macro Johnson_87_augmented_sphenocorona_faces2(OnPlane)
#local Johnson_87_augmented_sphenocorona_obj = mesh2 {
 vertex_vectors {
  11,
  Johnson_87_augmented_sphenocorona_verts[0],
  Johnson_87_augmented_sphenocorona_verts[1],
  Johnson_87_augmented_sphenocorona_verts[2],
  Johnson_87_augmented_sphenocorona_verts[3],
  Johnson_87_augmented_sphenocorona_verts[4],
  Johnson_87_augmented_sphenocorona_verts[5],
  Johnson_87_augmented_sphenocorona_verts[6],
  Johnson_87_augmented_sphenocorona_verts[7],
  Johnson_87_augmented_sphenocorona_verts[8],
  Johnson_87_augmented_sphenocorona_verts[9],
  Johnson_87_augmented_sphenocorona_verts[10]
 }
 face_indices {
  18,
  <5, 0, 1>,
  <9, 3, 8>,
  <8, 6, 10>,
  <8, 3, 2>,
  <8, 2, 6>,
  <6, 5, 10>,
  <10, 5, 7>,
  <3, 1, 2>,
  <1, 3, 4>,
  <7, 9, 10>,
  <7, 4, 9>,
  <9, 4, 3>,
  <10, 9, 8>,
  <6, 0, 5>,
  <6, 2, 0>,
  <0, 2, 1>,
  <5, 1, 4>,
  <5, 4, 7>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_87_augmented_sphenocorona_verts[5];
 #local P1 = Johnson_87_augmented_sphenocorona_verts[1];
 #local P2 = Johnson_87_augmented_sphenocorona_verts[4];
 #local P3 = Johnson_87_augmented_sphenocorona_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_87_augmented_sphenocorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_87_augmented_sphenocorona_obj }
#end
#end

#macro Johnson_87_augmented_sphenocorona_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_87_augmented_sphenocorona_verts[0], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[1], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[2], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[3], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[4], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[5], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[6], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[7], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[8], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[9], RadVer }
  sphere { Johnson_87_augmented_sphenocorona_verts[10], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_87_augmented_sphenocorona_verts[5], Johnson_87_augmented_sphenocorona_verts[0], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[0], Johnson_87_augmented_sphenocorona_verts[1], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[1], Johnson_87_augmented_sphenocorona_verts[5], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[9], Johnson_87_augmented_sphenocorona_verts[3], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[3], Johnson_87_augmented_sphenocorona_verts[8], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[8], Johnson_87_augmented_sphenocorona_verts[9], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[8], Johnson_87_augmented_sphenocorona_verts[6], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[6], Johnson_87_augmented_sphenocorona_verts[10], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[10], Johnson_87_augmented_sphenocorona_verts[8], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[3], Johnson_87_augmented_sphenocorona_verts[2], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[2], Johnson_87_augmented_sphenocorona_verts[8], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[2], Johnson_87_augmented_sphenocorona_verts[6], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[6], Johnson_87_augmented_sphenocorona_verts[5], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[5], Johnson_87_augmented_sphenocorona_verts[10], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[5], Johnson_87_augmented_sphenocorona_verts[7], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[7], Johnson_87_augmented_sphenocorona_verts[10], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[3], Johnson_87_augmented_sphenocorona_verts[1], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[1], Johnson_87_augmented_sphenocorona_verts[2], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[3], Johnson_87_augmented_sphenocorona_verts[4], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[4], Johnson_87_augmented_sphenocorona_verts[1], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[7], Johnson_87_augmented_sphenocorona_verts[9], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[9], Johnson_87_augmented_sphenocorona_verts[10], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[7], Johnson_87_augmented_sphenocorona_verts[4], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[4], Johnson_87_augmented_sphenocorona_verts[9], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[6], Johnson_87_augmented_sphenocorona_verts[0], RadEdg }
  cylinder { Johnson_87_augmented_sphenocorona_verts[2], Johnson_87_augmented_sphenocorona_verts[0], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_87_augmented_sphenocorona_verts[5];
 #local P1 = Johnson_87_augmented_sphenocorona_verts[1];
 #local P2 = Johnson_87_augmented_sphenocorona_verts[4];
 #local P3 = Johnson_87_augmented_sphenocorona_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_88_sphenomegacorona_verts = array[12]
{
<-0.710639, -0.297668, -0.152670>,
<-0.651151, -0.105949, 0.829841>,
<-0.621335, 0.647880, 0.169179>,
<-0.614162, -1.052419, 0.500527>,
<-0.166396, 0.361269, -0.677289>,
<-0.002058, -0.993534, -0.291612>,
<0.165944, 0.471894, 0.764865>,
<0.225836, -0.507426, 0.555374>,
<0.279224, 1.020494, -0.066987>,
<0.542185, -0.334598, -0.816231>,
<0.770079, 0.151511, 0.030755>,
<0.782476, 0.638548, -0.845752>,
}
#declare P0 = Johnson_88_sphenomegacorona_verts[4];
#declare P1 = Johnson_88_sphenomegacorona_verts[9];
#declare P2 = Johnson_88_sphenomegacorona_verts[5];
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
 #declare Johnson_88_sphenomegacorona_verts[Num] = vtransform(Johnson_88_sphenomegacorona_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_88_sphenomegacorona_faces(Tex3, Tex4, OnPlane)
#local Johnson_88_sphenomegacorona_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_88_sphenomegacorona_verts[0],
  Johnson_88_sphenomegacorona_verts[1],
  Johnson_88_sphenomegacorona_verts[2],
  Johnson_88_sphenomegacorona_verts[3],
  Johnson_88_sphenomegacorona_verts[4],
  Johnson_88_sphenomegacorona_verts[5],
  Johnson_88_sphenomegacorona_verts[6],
  Johnson_88_sphenomegacorona_verts[7],
  Johnson_88_sphenomegacorona_verts[8],
  Johnson_88_sphenomegacorona_verts[9],
  Johnson_88_sphenomegacorona_verts[10],
  Johnson_88_sphenomegacorona_verts[11]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  20,
  <6, 7, 10>, 0,
  <3, 7, 1>, 0,
  <3, 5, 7>, 0,
  <10, 11, 8>, 0,
  <10, 9, 11>, 0,
  <1, 7, 6>, 0,
  <6, 10, 8>, 0,
  <2, 4, 0>, 0,
  <11, 4, 8>, 0,
  <11, 9, 4>, 0,
  <0, 3, 1>, 0,
  <0, 5, 3>, 0,
  <8, 2, 6>, 0,
  <8, 4, 2>, 0,
  <2, 1, 6>, 0,
  <2, 0, 1>, 0,
  <7, 5, 9>, 1,
  <7, 9, 10>, 1,
  <4, 9, 5>, 1,
  <4, 5, 0>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_88_sphenomegacorona_verts[4];
 #local P1 = Johnson_88_sphenomegacorona_verts[9];
 #local P2 = Johnson_88_sphenomegacorona_verts[5];
 #local P3 = Johnson_88_sphenomegacorona_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_88_sphenomegacorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_88_sphenomegacorona_obj }
#end
#end

#macro Johnson_88_sphenomegacorona_faces2(OnPlane)
#local Johnson_88_sphenomegacorona_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_88_sphenomegacorona_verts[0],
  Johnson_88_sphenomegacorona_verts[1],
  Johnson_88_sphenomegacorona_verts[2],
  Johnson_88_sphenomegacorona_verts[3],
  Johnson_88_sphenomegacorona_verts[4],
  Johnson_88_sphenomegacorona_verts[5],
  Johnson_88_sphenomegacorona_verts[6],
  Johnson_88_sphenomegacorona_verts[7],
  Johnson_88_sphenomegacorona_verts[8],
  Johnson_88_sphenomegacorona_verts[9],
  Johnson_88_sphenomegacorona_verts[10],
  Johnson_88_sphenomegacorona_verts[11]
 }
 face_indices {
  20,
  <6, 7, 10>,
  <3, 7, 1>,
  <3, 5, 7>,
  <10, 11, 8>,
  <10, 9, 11>,
  <1, 7, 6>,
  <6, 10, 8>,
  <2, 4, 0>,
  <11, 4, 8>,
  <11, 9, 4>,
  <0, 3, 1>,
  <0, 5, 3>,
  <8, 2, 6>,
  <8, 4, 2>,
  <2, 1, 6>,
  <2, 0, 1>,
  <7, 5, 9>,
  <7, 9, 10>,
  <4, 9, 5>,
  <4, 5, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_88_sphenomegacorona_verts[4];
 #local P1 = Johnson_88_sphenomegacorona_verts[9];
 #local P2 = Johnson_88_sphenomegacorona_verts[5];
 #local P3 = Johnson_88_sphenomegacorona_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_88_sphenomegacorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_88_sphenomegacorona_obj }
#end
#end

#macro Johnson_88_sphenomegacorona_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_88_sphenomegacorona_verts[0], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[1], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[2], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[3], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[4], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[5], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[6], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[7], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[8], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[9], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[10], RadVer }
  sphere { Johnson_88_sphenomegacorona_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_88_sphenomegacorona_verts[6], Johnson_88_sphenomegacorona_verts[7], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[7], Johnson_88_sphenomegacorona_verts[10], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[10], Johnson_88_sphenomegacorona_verts[6], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[3], Johnson_88_sphenomegacorona_verts[7], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[7], Johnson_88_sphenomegacorona_verts[1], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[1], Johnson_88_sphenomegacorona_verts[3], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[3], Johnson_88_sphenomegacorona_verts[5], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[5], Johnson_88_sphenomegacorona_verts[7], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[10], Johnson_88_sphenomegacorona_verts[11], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[11], Johnson_88_sphenomegacorona_verts[8], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[8], Johnson_88_sphenomegacorona_verts[10], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[10], Johnson_88_sphenomegacorona_verts[9], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[9], Johnson_88_sphenomegacorona_verts[11], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[6], Johnson_88_sphenomegacorona_verts[1], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[8], Johnson_88_sphenomegacorona_verts[6], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[2], Johnson_88_sphenomegacorona_verts[4], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[4], Johnson_88_sphenomegacorona_verts[0], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[0], Johnson_88_sphenomegacorona_verts[2], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[11], Johnson_88_sphenomegacorona_verts[4], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[4], Johnson_88_sphenomegacorona_verts[8], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[9], Johnson_88_sphenomegacorona_verts[4], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[0], Johnson_88_sphenomegacorona_verts[3], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[1], Johnson_88_sphenomegacorona_verts[0], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[0], Johnson_88_sphenomegacorona_verts[5], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[8], Johnson_88_sphenomegacorona_verts[2], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[2], Johnson_88_sphenomegacorona_verts[6], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[2], Johnson_88_sphenomegacorona_verts[1], RadEdg }
  cylinder { Johnson_88_sphenomegacorona_verts[5], Johnson_88_sphenomegacorona_verts[9], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_88_sphenomegacorona_verts[4];
 #local P1 = Johnson_88_sphenomegacorona_verts[9];
 #local P2 = Johnson_88_sphenomegacorona_verts[5];
 #local P3 = Johnson_88_sphenomegacorona_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_89_hebesphenomegacorona_verts = array[14]
{
<-0.831170, 0.133549, -0.011648>,
<-0.700039, -0.806136, -0.111242>,
<-0.631074, -0.403619, 0.750934>,
<-0.576095, -0.225432, -0.857931>,
<-0.446282, 0.532211, 0.764918>,
<-0.172487, 0.817558, -0.103263>,
<0.082589, 0.458576, -0.949546>,
<0.105206, -0.849768, -0.620949>,
<0.145599, -0.761550, 0.328110>,
<0.235014, -0.092120, 1.001899>,
<0.469795, 0.739577, 0.597817>,
<0.750772, 0.700456, -0.313032>,
<0.763890, -0.165759, -0.712564>,
<0.804283, -0.077541, 0.236495>,
}
#declare P0 = Johnson_89_hebesphenomegacorona_verts[12];
#declare P1 = Johnson_89_hebesphenomegacorona_verts[7];
#declare P2 = Johnson_89_hebesphenomegacorona_verts[3];
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
 #declare Johnson_89_hebesphenomegacorona_verts[Num] = vtransform(Johnson_89_hebesphenomegacorona_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_89_hebesphenomegacorona_faces(Tex3, Tex4, OnPlane)
#local Johnson_89_hebesphenomegacorona_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_89_hebesphenomegacorona_verts[0],
  Johnson_89_hebesphenomegacorona_verts[1],
  Johnson_89_hebesphenomegacorona_verts[2],
  Johnson_89_hebesphenomegacorona_verts[3],
  Johnson_89_hebesphenomegacorona_verts[4],
  Johnson_89_hebesphenomegacorona_verts[5],
  Johnson_89_hebesphenomegacorona_verts[6],
  Johnson_89_hebesphenomegacorona_verts[7],
  Johnson_89_hebesphenomegacorona_verts[8],
  Johnson_89_hebesphenomegacorona_verts[9],
  Johnson_89_hebesphenomegacorona_verts[10],
  Johnson_89_hebesphenomegacorona_verts[11],
  Johnson_89_hebesphenomegacorona_verts[12],
  Johnson_89_hebesphenomegacorona_verts[13]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  24,
  <9, 8, 13>, 0,
  <1, 8, 2>, 0,
  <1, 7, 8>, 0,
  <13, 11, 10>, 0,
  <13, 12, 11>, 0,
  <2, 8, 9>, 0,
  <9, 13, 10>, 0,
  <12, 6, 11>, 0,
  <3, 7, 1>, 0,
  <4, 5, 0>, 0,
  <11, 5, 10>, 0,
  <11, 6, 5>, 0,
  <0, 1, 2>, 0,
  <0, 3, 1>, 0,
  <10, 4, 9>, 0,
  <10, 5, 4>, 0,
  <4, 2, 9>, 0,
  <4, 0, 2>, 0,
  <8, 7, 12>, 1,
  <8, 12, 13>, 1,
  <3, 6, 12>, 1,
  <3, 12, 7>, 1,
  <5, 6, 3>, 1,
  <5, 3, 0>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_89_hebesphenomegacorona_verts[12];
 #local P1 = Johnson_89_hebesphenomegacorona_verts[7];
 #local P2 = Johnson_89_hebesphenomegacorona_verts[3];
 #local P3 = Johnson_89_hebesphenomegacorona_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_89_hebesphenomegacorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_89_hebesphenomegacorona_obj }
#end
#end

#macro Johnson_89_hebesphenomegacorona_faces2(OnPlane)
#local Johnson_89_hebesphenomegacorona_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_89_hebesphenomegacorona_verts[0],
  Johnson_89_hebesphenomegacorona_verts[1],
  Johnson_89_hebesphenomegacorona_verts[2],
  Johnson_89_hebesphenomegacorona_verts[3],
  Johnson_89_hebesphenomegacorona_verts[4],
  Johnson_89_hebesphenomegacorona_verts[5],
  Johnson_89_hebesphenomegacorona_verts[6],
  Johnson_89_hebesphenomegacorona_verts[7],
  Johnson_89_hebesphenomegacorona_verts[8],
  Johnson_89_hebesphenomegacorona_verts[9],
  Johnson_89_hebesphenomegacorona_verts[10],
  Johnson_89_hebesphenomegacorona_verts[11],
  Johnson_89_hebesphenomegacorona_verts[12],
  Johnson_89_hebesphenomegacorona_verts[13]
 }
 face_indices {
  24,
  <9, 8, 13>,
  <1, 8, 2>,
  <1, 7, 8>,
  <13, 11, 10>,
  <13, 12, 11>,
  <2, 8, 9>,
  <9, 13, 10>,
  <12, 6, 11>,
  <3, 7, 1>,
  <4, 5, 0>,
  <11, 5, 10>,
  <11, 6, 5>,
  <0, 1, 2>,
  <0, 3, 1>,
  <10, 4, 9>,
  <10, 5, 4>,
  <4, 2, 9>,
  <4, 0, 2>,
  <8, 7, 12>,
  <8, 12, 13>,
  <3, 6, 12>,
  <3, 12, 7>,
  <5, 6, 3>,
  <5, 3, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_89_hebesphenomegacorona_verts[12];
 #local P1 = Johnson_89_hebesphenomegacorona_verts[7];
 #local P2 = Johnson_89_hebesphenomegacorona_verts[3];
 #local P3 = Johnson_89_hebesphenomegacorona_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_89_hebesphenomegacorona_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_89_hebesphenomegacorona_obj }
#end
#end

#macro Johnson_89_hebesphenomegacorona_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_89_hebesphenomegacorona_verts[0], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[1], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[2], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[3], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[4], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[5], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[6], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[7], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[8], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[9], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[10], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[11], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[12], RadVer }
  sphere { Johnson_89_hebesphenomegacorona_verts[13], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_89_hebesphenomegacorona_verts[9], Johnson_89_hebesphenomegacorona_verts[8], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[8], Johnson_89_hebesphenomegacorona_verts[13], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[13], Johnson_89_hebesphenomegacorona_verts[9], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[1], Johnson_89_hebesphenomegacorona_verts[8], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[8], Johnson_89_hebesphenomegacorona_verts[2], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[2], Johnson_89_hebesphenomegacorona_verts[1], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[1], Johnson_89_hebesphenomegacorona_verts[7], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[7], Johnson_89_hebesphenomegacorona_verts[8], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[13], Johnson_89_hebesphenomegacorona_verts[11], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[11], Johnson_89_hebesphenomegacorona_verts[10], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[10], Johnson_89_hebesphenomegacorona_verts[13], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[13], Johnson_89_hebesphenomegacorona_verts[12], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[12], Johnson_89_hebesphenomegacorona_verts[11], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[9], Johnson_89_hebesphenomegacorona_verts[2], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[10], Johnson_89_hebesphenomegacorona_verts[9], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[12], Johnson_89_hebesphenomegacorona_verts[6], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[6], Johnson_89_hebesphenomegacorona_verts[11], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[3], Johnson_89_hebesphenomegacorona_verts[7], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[1], Johnson_89_hebesphenomegacorona_verts[3], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[4], Johnson_89_hebesphenomegacorona_verts[5], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[5], Johnson_89_hebesphenomegacorona_verts[0], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[0], Johnson_89_hebesphenomegacorona_verts[4], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[11], Johnson_89_hebesphenomegacorona_verts[5], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[5], Johnson_89_hebesphenomegacorona_verts[10], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[6], Johnson_89_hebesphenomegacorona_verts[5], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[0], Johnson_89_hebesphenomegacorona_verts[1], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[2], Johnson_89_hebesphenomegacorona_verts[0], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[0], Johnson_89_hebesphenomegacorona_verts[3], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[10], Johnson_89_hebesphenomegacorona_verts[4], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[4], Johnson_89_hebesphenomegacorona_verts[9], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[4], Johnson_89_hebesphenomegacorona_verts[2], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[7], Johnson_89_hebesphenomegacorona_verts[12], RadEdg }
  cylinder { Johnson_89_hebesphenomegacorona_verts[3], Johnson_89_hebesphenomegacorona_verts[6], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_89_hebesphenomegacorona_verts[12];
 #local P1 = Johnson_89_hebesphenomegacorona_verts[7];
 #local P2 = Johnson_89_hebesphenomegacorona_verts[3];
 #local P3 = Johnson_89_hebesphenomegacorona_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_90_disphenocingulum_verts = array[16]
{
<-1.052782, 0.264006, 0.098264>,
<-0.753999, -0.411397, 0.610751>,
<-0.732127, -0.483215, -0.285043>,
<-0.599216, 0.763406, -0.495842>,
<-0.413906, 0.414477, 0.712494>,
<-0.278562, 0.016184, -0.879148>,
<-0.105415, -0.890983, 0.213994>,
<0.009423, -0.810270, -0.673913>,
<0.039660, 0.913876, 0.118388>,
<0.101994, -0.305887, 0.864167>,
<0.267869, 0.713733, -0.727747>,
<0.476710, 0.507934, 0.790906>,
<0.590474, -0.124774, -0.697516>,
<0.722293, -0.806255, -0.126296>,
<0.797883, 0.460322, -0.047343>,
<0.929701, -0.221158, 0.523878>,
}
#declare P0 = Johnson_90_disphenocingulum_verts[3];
#declare P1 = Johnson_90_disphenocingulum_verts[0];
#declare P2 = Johnson_90_disphenocingulum_verts[4];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 16)
 #declare Johnson_90_disphenocingulum_verts[Num] = vtransform(Johnson_90_disphenocingulum_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_90_disphenocingulum_faces(Tex3, Tex4, OnPlane)
#local Johnson_90_disphenocingulum_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_90_disphenocingulum_verts[0],
  Johnson_90_disphenocingulum_verts[1],
  Johnson_90_disphenocingulum_verts[2],
  Johnson_90_disphenocingulum_verts[3],
  Johnson_90_disphenocingulum_verts[4],
  Johnson_90_disphenocingulum_verts[5],
  Johnson_90_disphenocingulum_verts[6],
  Johnson_90_disphenocingulum_verts[7],
  Johnson_90_disphenocingulum_verts[8],
  Johnson_90_disphenocingulum_verts[9],
  Johnson_90_disphenocingulum_verts[10],
  Johnson_90_disphenocingulum_verts[11],
  Johnson_90_disphenocingulum_verts[12],
  Johnson_90_disphenocingulum_verts[13],
  Johnson_90_disphenocingulum_verts[14],
  Johnson_90_disphenocingulum_verts[15]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  28,
  <13, 6, 7>, 0,
  <9, 15, 11>, 0,
  <12, 13, 7>, 0,
  <15, 14, 11>, 0,
  <12, 10, 14>, 0,
  <12, 7, 5>, 0,
  <12, 5, 10>, 0,
  <10, 5, 3>, 0,
  <7, 6, 2>, 0,
  <5, 7, 2>, 0,
  <2, 6, 1>, 0,
  <2, 1, 0>, 0,
  <10, 3, 8>, 0,
  <10, 8, 14>, 0,
  <8, 11, 14>, 0,
  <8, 4, 11>, 0,
  <11, 4, 9>, 0,
  <9, 1, 6>, 0,
  <4, 1, 9>, 0,
  <0, 1, 4>, 0,
  <9, 6, 13>, 1,
  <9, 13, 15>, 1,
  <15, 13, 12>, 1,
  <15, 12, 14>, 1,
  <5, 2, 0>, 1,
  <5, 0, 3>, 1,
  <3, 0, 4>, 1,
  <3, 4, 8>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_90_disphenocingulum_verts[3];
 #local P1 = Johnson_90_disphenocingulum_verts[0];
 #local P2 = Johnson_90_disphenocingulum_verts[4];
 #local P3 = Johnson_90_disphenocingulum_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_90_disphenocingulum_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_90_disphenocingulum_obj }
#end
#end

#macro Johnson_90_disphenocingulum_faces2(OnPlane)
#local Johnson_90_disphenocingulum_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_90_disphenocingulum_verts[0],
  Johnson_90_disphenocingulum_verts[1],
  Johnson_90_disphenocingulum_verts[2],
  Johnson_90_disphenocingulum_verts[3],
  Johnson_90_disphenocingulum_verts[4],
  Johnson_90_disphenocingulum_verts[5],
  Johnson_90_disphenocingulum_verts[6],
  Johnson_90_disphenocingulum_verts[7],
  Johnson_90_disphenocingulum_verts[8],
  Johnson_90_disphenocingulum_verts[9],
  Johnson_90_disphenocingulum_verts[10],
  Johnson_90_disphenocingulum_verts[11],
  Johnson_90_disphenocingulum_verts[12],
  Johnson_90_disphenocingulum_verts[13],
  Johnson_90_disphenocingulum_verts[14],
  Johnson_90_disphenocingulum_verts[15]
 }
 face_indices {
  28,
  <13, 6, 7>,
  <9, 15, 11>,
  <12, 13, 7>,
  <15, 14, 11>,
  <12, 10, 14>,
  <12, 7, 5>,
  <12, 5, 10>,
  <10, 5, 3>,
  <7, 6, 2>,
  <5, 7, 2>,
  <2, 6, 1>,
  <2, 1, 0>,
  <10, 3, 8>,
  <10, 8, 14>,
  <8, 11, 14>,
  <8, 4, 11>,
  <11, 4, 9>,
  <9, 1, 6>,
  <4, 1, 9>,
  <0, 1, 4>,
  <9, 6, 13>,
  <9, 13, 15>,
  <15, 13, 12>,
  <15, 12, 14>,
  <5, 2, 0>,
  <5, 0, 3>,
  <3, 0, 4>,
  <3, 4, 8>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_90_disphenocingulum_verts[3];
 #local P1 = Johnson_90_disphenocingulum_verts[0];
 #local P2 = Johnson_90_disphenocingulum_verts[4];
 #local P3 = Johnson_90_disphenocingulum_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_90_disphenocingulum_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_90_disphenocingulum_obj }
#end
#end

#macro Johnson_90_disphenocingulum_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_90_disphenocingulum_verts[0], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[1], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[2], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[3], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[4], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[5], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[6], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[7], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[8], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[9], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[10], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[11], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[12], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[13], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[14], RadVer }
  sphere { Johnson_90_disphenocingulum_verts[15], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_90_disphenocingulum_verts[13], Johnson_90_disphenocingulum_verts[6], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[6], Johnson_90_disphenocingulum_verts[7], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[7], Johnson_90_disphenocingulum_verts[13], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[9], Johnson_90_disphenocingulum_verts[15], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[15], Johnson_90_disphenocingulum_verts[11], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[11], Johnson_90_disphenocingulum_verts[9], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[12], Johnson_90_disphenocingulum_verts[13], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[7], Johnson_90_disphenocingulum_verts[12], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[15], Johnson_90_disphenocingulum_verts[14], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[14], Johnson_90_disphenocingulum_verts[11], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[12], Johnson_90_disphenocingulum_verts[10], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[10], Johnson_90_disphenocingulum_verts[14], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[14], Johnson_90_disphenocingulum_verts[12], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[7], Johnson_90_disphenocingulum_verts[5], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[5], Johnson_90_disphenocingulum_verts[12], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[5], Johnson_90_disphenocingulum_verts[10], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[5], Johnson_90_disphenocingulum_verts[3], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[3], Johnson_90_disphenocingulum_verts[10], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[6], Johnson_90_disphenocingulum_verts[2], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[2], Johnson_90_disphenocingulum_verts[7], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[2], Johnson_90_disphenocingulum_verts[5], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[6], Johnson_90_disphenocingulum_verts[1], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[1], Johnson_90_disphenocingulum_verts[2], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[1], Johnson_90_disphenocingulum_verts[0], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[0], Johnson_90_disphenocingulum_verts[2], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[3], Johnson_90_disphenocingulum_verts[8], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[8], Johnson_90_disphenocingulum_verts[10], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[8], Johnson_90_disphenocingulum_verts[14], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[8], Johnson_90_disphenocingulum_verts[11], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[8], Johnson_90_disphenocingulum_verts[4], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[4], Johnson_90_disphenocingulum_verts[11], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[4], Johnson_90_disphenocingulum_verts[9], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[9], Johnson_90_disphenocingulum_verts[1], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[6], Johnson_90_disphenocingulum_verts[9], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[4], Johnson_90_disphenocingulum_verts[1], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[4], Johnson_90_disphenocingulum_verts[0], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[13], Johnson_90_disphenocingulum_verts[15], RadEdg }
  cylinder { Johnson_90_disphenocingulum_verts[0], Johnson_90_disphenocingulum_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_90_disphenocingulum_verts[3];
 #local P1 = Johnson_90_disphenocingulum_verts[0];
 #local P2 = Johnson_90_disphenocingulum_verts[4];
 #local P3 = Johnson_90_disphenocingulum_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_91_bilunabirotunda_verts = array[14]
{
<-0.932446, -0.071511, 0.062428>,
<-0.890073, 0.716495, 0.434115>,
<-0.483326, 0.038238, 0.802122>,
<-0.479875, -0.798287, -0.104525>,
<-0.363346, -0.088790, -0.598427>,
<-0.294782, 1.186233, 0.002976>,
<-0.030753, -0.688537, 0.635167>,
<0.030753, 0.688538, -0.635171>,
<0.294779, -1.186232, -0.002974>,
<0.363347, 0.088791, 0.598425>,
<0.479874, 0.798290, 0.104525>,
<0.483327, -0.038241, -0.802125>,
<0.890072, -0.716499, -0.434115>,
<0.932449, 0.071511, -0.062429>,
}
#declare P0 = Johnson_91_bilunabirotunda_verts[11];
#declare P1 = Johnson_91_bilunabirotunda_verts[7];
#declare P2 = Johnson_91_bilunabirotunda_verts[10];
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
 #declare Johnson_91_bilunabirotunda_verts[Num] = vtransform(Johnson_91_bilunabirotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_91_bilunabirotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_91_bilunabirotunda_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_91_bilunabirotunda_verts[0],
  Johnson_91_bilunabirotunda_verts[1],
  Johnson_91_bilunabirotunda_verts[2],
  Johnson_91_bilunabirotunda_verts[3],
  Johnson_91_bilunabirotunda_verts[4],
  Johnson_91_bilunabirotunda_verts[5],
  Johnson_91_bilunabirotunda_verts[6],
  Johnson_91_bilunabirotunda_verts[7],
  Johnson_91_bilunabirotunda_verts[8],
  Johnson_91_bilunabirotunda_verts[9],
  Johnson_91_bilunabirotunda_verts[10],
  Johnson_91_bilunabirotunda_verts[11],
  Johnson_91_bilunabirotunda_verts[12],
  Johnson_91_bilunabirotunda_verts[13]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  24,
  <11, 13, 12>, 0,
  <7, 11, 4>, 0,
  <10, 7, 5>, 0,
  <13, 10, 9>, 0,
  <3, 8, 6>, 0,
  <4, 3, 0>, 0,
  <2, 1, 0>, 0,
  <9, 2, 6>, 0,
  <13, 11, 7>, 1,
  <13, 7, 10>, 1,
  <6, 2, 0>, 1,
  <6, 0, 3>, 1,
  <12, 13, 9>, 2,
  <12, 9, 6>, 2,
  <12, 6, 8>, 2,
  <11, 12, 8>, 2,
  <11, 8, 3>, 2,
  <11, 3, 4>, 2,
  <5, 7, 4>, 2,
  <5, 4, 0>, 2,
  <5, 0, 1>, 2,
  <10, 5, 1>, 2,
  <10, 1, 2>, 2,
  <10, 2, 9>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_91_bilunabirotunda_verts[11];
 #local P1 = Johnson_91_bilunabirotunda_verts[7];
 #local P2 = Johnson_91_bilunabirotunda_verts[10];
 #local P3 = Johnson_91_bilunabirotunda_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_91_bilunabirotunda_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_91_bilunabirotunda_obj }
#end
#end

#macro Johnson_91_bilunabirotunda_faces2(OnPlane)
#local Johnson_91_bilunabirotunda_obj = mesh2 {
 vertex_vectors {
  14,
  Johnson_91_bilunabirotunda_verts[0],
  Johnson_91_bilunabirotunda_verts[1],
  Johnson_91_bilunabirotunda_verts[2],
  Johnson_91_bilunabirotunda_verts[3],
  Johnson_91_bilunabirotunda_verts[4],
  Johnson_91_bilunabirotunda_verts[5],
  Johnson_91_bilunabirotunda_verts[6],
  Johnson_91_bilunabirotunda_verts[7],
  Johnson_91_bilunabirotunda_verts[8],
  Johnson_91_bilunabirotunda_verts[9],
  Johnson_91_bilunabirotunda_verts[10],
  Johnson_91_bilunabirotunda_verts[11],
  Johnson_91_bilunabirotunda_verts[12],
  Johnson_91_bilunabirotunda_verts[13]
 }
 face_indices {
  24,
  <11, 13, 12>,
  <7, 11, 4>,
  <10, 7, 5>,
  <13, 10, 9>,
  <3, 8, 6>,
  <4, 3, 0>,
  <2, 1, 0>,
  <9, 2, 6>,
  <13, 11, 7>,
  <13, 7, 10>,
  <6, 2, 0>,
  <6, 0, 3>,
  <12, 13, 9>,
  <12, 9, 6>,
  <12, 6, 8>,
  <11, 12, 8>,
  <11, 8, 3>,
  <11, 3, 4>,
  <5, 7, 4>,
  <5, 4, 0>,
  <5, 0, 1>,
  <10, 5, 1>,
  <10, 1, 2>,
  <10, 2, 9>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_91_bilunabirotunda_verts[11];
 #local P1 = Johnson_91_bilunabirotunda_verts[7];
 #local P2 = Johnson_91_bilunabirotunda_verts[10];
 #local P3 = Johnson_91_bilunabirotunda_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_91_bilunabirotunda_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_91_bilunabirotunda_obj }
#end
#end

#macro Johnson_91_bilunabirotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_91_bilunabirotunda_verts[0], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[1], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[2], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[3], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[4], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[5], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[6], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[7], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[8], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[9], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[10], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[11], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[12], RadVer }
  sphere { Johnson_91_bilunabirotunda_verts[13], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_91_bilunabirotunda_verts[11], Johnson_91_bilunabirotunda_verts[13], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[13], Johnson_91_bilunabirotunda_verts[12], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[12], Johnson_91_bilunabirotunda_verts[11], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[7], Johnson_91_bilunabirotunda_verts[11], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[11], Johnson_91_bilunabirotunda_verts[4], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[4], Johnson_91_bilunabirotunda_verts[7], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[10], Johnson_91_bilunabirotunda_verts[7], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[7], Johnson_91_bilunabirotunda_verts[5], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[5], Johnson_91_bilunabirotunda_verts[10], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[13], Johnson_91_bilunabirotunda_verts[10], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[10], Johnson_91_bilunabirotunda_verts[9], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[9], Johnson_91_bilunabirotunda_verts[13], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[3], Johnson_91_bilunabirotunda_verts[8], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[8], Johnson_91_bilunabirotunda_verts[6], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[6], Johnson_91_bilunabirotunda_verts[3], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[4], Johnson_91_bilunabirotunda_verts[3], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[3], Johnson_91_bilunabirotunda_verts[0], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[0], Johnson_91_bilunabirotunda_verts[4], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[2], Johnson_91_bilunabirotunda_verts[1], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[1], Johnson_91_bilunabirotunda_verts[0], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[0], Johnson_91_bilunabirotunda_verts[2], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[9], Johnson_91_bilunabirotunda_verts[2], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[2], Johnson_91_bilunabirotunda_verts[6], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[6], Johnson_91_bilunabirotunda_verts[9], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[8], Johnson_91_bilunabirotunda_verts[12], RadEdg }
  cylinder { Johnson_91_bilunabirotunda_verts[1], Johnson_91_bilunabirotunda_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_91_bilunabirotunda_verts[11];
 #local P1 = Johnson_91_bilunabirotunda_verts[7];
 #local P2 = Johnson_91_bilunabirotunda_verts[10];
 #local P3 = Johnson_91_bilunabirotunda_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_92_triangular_hebesphenorotunda_verts = array[18]
{
<-0.748928, 0.557858, -0.030371>,
<-0.638635, 0.125804, -0.670329>,
<-0.593696, 0.259282, 0.673290>,
<-0.427424, 0.876636, -0.665507>,
<-0.373109, -0.604827, -0.606627>,
<-0.328170, -0.471348, 0.736992>,
<-0.217876, -0.903403, 0.097033>,
<-0.141658, 1.042101, 0.041134>,
<-0.021021, 0.094954, 1.176701>,
<0.013575, 0.743525, 0.744795>,
<0.036802, 0.343022, -0.994341>,
<0.267732, -1.036179, -0.498733>,
<0.302328, -0.387609, -0.930640>,
<0.443205, -0.438661, 0.847867>,
<0.499183, 0.610749, 0.149029>,
<0.553499, -0.870715, 0.207908>,
<0.609478, 0.178694, -0.490931>,
<0.764710, -0.119883, 0.212731>,
}
#declare P0 = Johnson_92_triangular_hebesphenorotunda_verts[1];
#declare P1 = Johnson_92_triangular_hebesphenorotunda_verts[4];
#declare P2 = Johnson_92_triangular_hebesphenorotunda_verts[6];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 18)
 #declare Johnson_92_triangular_hebesphenorotunda_verts[Num] = vtransform(Johnson_92_triangular_hebesphenorotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_92_triangular_hebesphenorotunda_faces(Tex3, Tex4, Tex5, Tex6, OnPlane)
#local Johnson_92_triangular_hebesphenorotunda_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_92_triangular_hebesphenorotunda_verts[0],
  Johnson_92_triangular_hebesphenorotunda_verts[1],
  Johnson_92_triangular_hebesphenorotunda_verts[2],
  Johnson_92_triangular_hebesphenorotunda_verts[3],
  Johnson_92_triangular_hebesphenorotunda_verts[4],
  Johnson_92_triangular_hebesphenorotunda_verts[5],
  Johnson_92_triangular_hebesphenorotunda_verts[6],
  Johnson_92_triangular_hebesphenorotunda_verts[7],
  Johnson_92_triangular_hebesphenorotunda_verts[8],
  Johnson_92_triangular_hebesphenorotunda_verts[9],
  Johnson_92_triangular_hebesphenorotunda_verts[10],
  Johnson_92_triangular_hebesphenorotunda_verts[11],
  Johnson_92_triangular_hebesphenorotunda_verts[12],
  Johnson_92_triangular_hebesphenorotunda_verts[13],
  Johnson_92_triangular_hebesphenorotunda_verts[14],
  Johnson_92_triangular_hebesphenorotunda_verts[15],
  Johnson_92_triangular_hebesphenorotunda_verts[16],
  Johnson_92_triangular_hebesphenorotunda_verts[17]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex6 }
 }
 face_indices {
  32,
  <12, 11, 4>, 0,
  <11, 6, 4>, 0,
  <6, 11, 15>, 0,
  <13, 15, 17>, 0,
  <5, 13, 8>, 0,
  <2, 5, 8>, 0,
  <2, 8, 9>, 0,
  <7, 9, 14>, 0,
  <16, 14, 17>, 0,
  <3, 0, 7>, 0,
  <3, 1, 0>, 0,
  <1, 3, 10>, 0,
  <12, 10, 16>, 0,
  <6, 15, 13>, 1,
  <6, 13, 5>, 1,
  <2, 9, 7>, 1,
  <2, 7, 0>, 1,
  <12, 4, 1>, 1,
  <12, 1, 10>, 1,
  <11, 12, 16>, 2,
  <11, 16, 17>, 2,
  <11, 17, 15>, 2,
  <8, 13, 17>, 2,
  <8, 17, 14>, 2,
  <8, 14, 9>, 2,
  <16, 10, 3>, 2,
  <16, 3, 7>, 2,
  <16, 7, 14>, 2,
  <1, 4, 6>, 3,
  <1, 6, 5>, 3,
  <1, 5, 2>, 3,
  <1, 2, 0>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_92_triangular_hebesphenorotunda_verts[1];
 #local P1 = Johnson_92_triangular_hebesphenorotunda_verts[4];
 #local P2 = Johnson_92_triangular_hebesphenorotunda_verts[6];
 #local P3 = Johnson_92_triangular_hebesphenorotunda_verts[5];
 #local P4 = Johnson_92_triangular_hebesphenorotunda_verts[2];
 #local P5 = Johnson_92_triangular_hebesphenorotunda_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_92_triangular_hebesphenorotunda_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_92_triangular_hebesphenorotunda_obj }
#end
#end

#macro Johnson_92_triangular_hebesphenorotunda_faces2(OnPlane)
#local Johnson_92_triangular_hebesphenorotunda_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_92_triangular_hebesphenorotunda_verts[0],
  Johnson_92_triangular_hebesphenorotunda_verts[1],
  Johnson_92_triangular_hebesphenorotunda_verts[2],
  Johnson_92_triangular_hebesphenorotunda_verts[3],
  Johnson_92_triangular_hebesphenorotunda_verts[4],
  Johnson_92_triangular_hebesphenorotunda_verts[5],
  Johnson_92_triangular_hebesphenorotunda_verts[6],
  Johnson_92_triangular_hebesphenorotunda_verts[7],
  Johnson_92_triangular_hebesphenorotunda_verts[8],
  Johnson_92_triangular_hebesphenorotunda_verts[9],
  Johnson_92_triangular_hebesphenorotunda_verts[10],
  Johnson_92_triangular_hebesphenorotunda_verts[11],
  Johnson_92_triangular_hebesphenorotunda_verts[12],
  Johnson_92_triangular_hebesphenorotunda_verts[13],
  Johnson_92_triangular_hebesphenorotunda_verts[14],
  Johnson_92_triangular_hebesphenorotunda_verts[15],
  Johnson_92_triangular_hebesphenorotunda_verts[16],
  Johnson_92_triangular_hebesphenorotunda_verts[17]
 }
 face_indices {
  32,
  <12, 11, 4>,
  <11, 6, 4>,
  <6, 11, 15>,
  <13, 15, 17>,
  <5, 13, 8>,
  <2, 5, 8>,
  <2, 8, 9>,
  <7, 9, 14>,
  <16, 14, 17>,
  <3, 0, 7>,
  <3, 1, 0>,
  <1, 3, 10>,
  <12, 10, 16>,
  <6, 15, 13>,
  <6, 13, 5>,
  <2, 9, 7>,
  <2, 7, 0>,
  <12, 4, 1>,
  <12, 1, 10>,
  <11, 12, 16>,
  <11, 16, 17>,
  <11, 17, 15>,
  <8, 13, 17>,
  <8, 17, 14>,
  <8, 14, 9>,
  <16, 10, 3>,
  <16, 3, 7>,
  <16, 7, 14>,
  <1, 4, 6>,
  <1, 6, 5>,
  <1, 5, 2>,
  <1, 2, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_92_triangular_hebesphenorotunda_verts[1];
 #local P1 = Johnson_92_triangular_hebesphenorotunda_verts[4];
 #local P2 = Johnson_92_triangular_hebesphenorotunda_verts[6];
 #local P3 = Johnson_92_triangular_hebesphenorotunda_verts[5];
 #local P4 = Johnson_92_triangular_hebesphenorotunda_verts[2];
 #local P5 = Johnson_92_triangular_hebesphenorotunda_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_92_triangular_hebesphenorotunda_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_92_triangular_hebesphenorotunda_obj }
#end
#end

#macro Johnson_92_triangular_hebesphenorotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[0], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[1], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[2], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[3], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[4], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[5], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[6], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[7], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[8], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[9], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[10], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[11], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[12], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[13], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[14], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[15], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[16], RadVer }
  sphere { Johnson_92_triangular_hebesphenorotunda_verts[17], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[12], Johnson_92_triangular_hebesphenorotunda_verts[11], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[11], Johnson_92_triangular_hebesphenorotunda_verts[4], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[4], Johnson_92_triangular_hebesphenorotunda_verts[12], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[11], Johnson_92_triangular_hebesphenorotunda_verts[6], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[6], Johnson_92_triangular_hebesphenorotunda_verts[4], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[11], Johnson_92_triangular_hebesphenorotunda_verts[15], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[15], Johnson_92_triangular_hebesphenorotunda_verts[6], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[13], Johnson_92_triangular_hebesphenorotunda_verts[15], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[15], Johnson_92_triangular_hebesphenorotunda_verts[17], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[17], Johnson_92_triangular_hebesphenorotunda_verts[13], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[5], Johnson_92_triangular_hebesphenorotunda_verts[13], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[13], Johnson_92_triangular_hebesphenorotunda_verts[8], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[8], Johnson_92_triangular_hebesphenorotunda_verts[5], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[2], Johnson_92_triangular_hebesphenorotunda_verts[5], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[8], Johnson_92_triangular_hebesphenorotunda_verts[2], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[8], Johnson_92_triangular_hebesphenorotunda_verts[9], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[9], Johnson_92_triangular_hebesphenorotunda_verts[2], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[7], Johnson_92_triangular_hebesphenorotunda_verts[9], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[9], Johnson_92_triangular_hebesphenorotunda_verts[14], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[14], Johnson_92_triangular_hebesphenorotunda_verts[7], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[16], Johnson_92_triangular_hebesphenorotunda_verts[14], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[14], Johnson_92_triangular_hebesphenorotunda_verts[17], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[17], Johnson_92_triangular_hebesphenorotunda_verts[16], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[3], Johnson_92_triangular_hebesphenorotunda_verts[0], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[0], Johnson_92_triangular_hebesphenorotunda_verts[7], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[7], Johnson_92_triangular_hebesphenorotunda_verts[3], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[3], Johnson_92_triangular_hebesphenorotunda_verts[1], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[1], Johnson_92_triangular_hebesphenorotunda_verts[0], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[3], Johnson_92_triangular_hebesphenorotunda_verts[10], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[10], Johnson_92_triangular_hebesphenorotunda_verts[1], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[12], Johnson_92_triangular_hebesphenorotunda_verts[10], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[10], Johnson_92_triangular_hebesphenorotunda_verts[16], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[16], Johnson_92_triangular_hebesphenorotunda_verts[12], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[5], Johnson_92_triangular_hebesphenorotunda_verts[6], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[0], Johnson_92_triangular_hebesphenorotunda_verts[2], RadEdg }
  cylinder { Johnson_92_triangular_hebesphenorotunda_verts[4], Johnson_92_triangular_hebesphenorotunda_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_92_triangular_hebesphenorotunda_verts[1];
 #local P1 = Johnson_92_triangular_hebesphenorotunda_verts[4];
 #local P2 = Johnson_92_triangular_hebesphenorotunda_verts[6];
 #local P3 = Johnson_92_triangular_hebesphenorotunda_verts[5];
 #local P4 = Johnson_92_triangular_hebesphenorotunda_verts[2];
 #local P5 = Johnson_92_triangular_hebesphenorotunda_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
