/* -------------------
johnson_solids_group5.inc

Modified Platonic solids

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Johnson_58_augmented_dodecahedron (21 vertices)
  Johnson_59_parabiaugmented_dodecahedron (22 vertices)
  Johnson_60_metabiaugmented_dodecahedron (22 vertices)
  Johnson_61_triaugmented_dodecahedron (23 vertices)
  Johnson_62_metabidiminished_icosahedron (10 vertices)
  Johnson_63_tridiminished_icosahedron (9 vertices)
  Johnson_64_augmented_tridiminished_icosahedron (10 vertices)

-------------------- */

#include "transforms.inc"

#declare Johnson_58_augmented_dodecahedron_verts = array[21]
{
<-0.906673, 0.136106, 0.246909>,
<-0.827056, 0.097501, -0.456089>,
<-0.822039, 0.728118, -0.133084>,
<-0.682157, -0.474972, 0.526574>,
<-0.553334, -0.537436, -0.610901>,
<-0.486770, 0.654002, 0.486704>,
<-0.463781, -0.891244, -0.003583>,
<-0.357947, 0.591537, -0.650771>,
<-0.147639, 0.935474, -0.068093>,
<-0.123496, -0.334743, 0.939211>,
<-0.002740, 0.363001, 0.914570>,
<0.084945, -0.435813, -0.901263>,
<0.205700, 0.261931, -0.925903>,
<0.229843, -1.008285, 0.081400>,
<0.440151, -0.664349, 0.664079>,
<0.545986, 0.818432, 0.016890>,
<0.568974, -0.726814, -0.473396>,
<0.635538, 0.464625, 0.624209>,
<0.764361, 0.402160, -0.513266>,
<0.909260, -0.170313, 0.469397>,
<0.988877, -0.208918, -0.233601>,
}
#declare P0 = Johnson_58_augmented_dodecahedron_verts[19];
#declare P1 = Johnson_58_augmented_dodecahedron_verts[16];
#declare P2 = Johnson_58_augmented_dodecahedron_verts[20];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 21)
 #declare Johnson_58_augmented_dodecahedron_verts[Num] = vtransform(Johnson_58_augmented_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_58_augmented_dodecahedron_faces(Tex3, Tex5, OnPlane)
#local Johnson_58_augmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  21,
  Johnson_58_augmented_dodecahedron_verts[0],
  Johnson_58_augmented_dodecahedron_verts[1],
  Johnson_58_augmented_dodecahedron_verts[2],
  Johnson_58_augmented_dodecahedron_verts[3],
  Johnson_58_augmented_dodecahedron_verts[4],
  Johnson_58_augmented_dodecahedron_verts[5],
  Johnson_58_augmented_dodecahedron_verts[6],
  Johnson_58_augmented_dodecahedron_verts[7],
  Johnson_58_augmented_dodecahedron_verts[8],
  Johnson_58_augmented_dodecahedron_verts[9],
  Johnson_58_augmented_dodecahedron_verts[10],
  Johnson_58_augmented_dodecahedron_verts[11],
  Johnson_58_augmented_dodecahedron_verts[12],
  Johnson_58_augmented_dodecahedron_verts[13],
  Johnson_58_augmented_dodecahedron_verts[14],
  Johnson_58_augmented_dodecahedron_verts[15],
  Johnson_58_augmented_dodecahedron_verts[16],
  Johnson_58_augmented_dodecahedron_verts[17],
  Johnson_58_augmented_dodecahedron_verts[18],
  Johnson_58_augmented_dodecahedron_verts[19],
  Johnson_58_augmented_dodecahedron_verts[20]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  38,
  <2, 0, 5>, 0,
  <2, 5, 8>, 0,
  <2, 1, 0>, 0,
  <2, 7, 1>, 0,
  <7, 2, 8>, 0,
  <18, 20, 16>, 1,
  <18, 16, 11>, 1,
  <18, 11, 12>, 1,
  <6, 4, 11>, 1,
  <6, 11, 16>, 1,
  <6, 16, 13>, 1,
  <1, 7, 12>, 1,
  <1, 12, 11>, 1,
  <1, 11, 4>, 1,
  <8, 15, 18>, 1,
  <8, 18, 12>, 1,
  <8, 12, 7>, 1,
  <17, 19, 20>, 1,
  <17, 20, 18>, 1,
  <17, 18, 15>, 1,
  <14, 13, 16>, 1,
  <14, 16, 20>, 1,
  <14, 20, 19>, 1,
  <19, 17, 10>, 1,
  <19, 10, 9>, 1,
  <19, 9, 14>, 1,
  <15, 8, 5>, 1,
  <15, 5, 10>, 1,
  <15, 10, 17>, 1,
  <4, 6, 3>, 1,
  <4, 3, 0>, 1,
  <4, 0, 1>, 1,
  <13, 14, 9>, 1,
  <13, 9, 3>, 1,
  <13, 3, 6>, 1,
  <3, 9, 10>, 1,
  <3, 10, 5>, 1,
  <3, 5, 0>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_58_augmented_dodecahedron_verts[19];
 #local P1 = Johnson_58_augmented_dodecahedron_verts[16];
 #local P2 = Johnson_58_augmented_dodecahedron_verts[20];
 #local P3 = Johnson_58_augmented_dodecahedron_verts[13];
 #local P4 = Johnson_58_augmented_dodecahedron_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_58_augmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_58_augmented_dodecahedron_obj }
#end
#end

#macro Johnson_58_augmented_dodecahedron_faces2(OnPlane)
#local Johnson_58_augmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  21,
  Johnson_58_augmented_dodecahedron_verts[0],
  Johnson_58_augmented_dodecahedron_verts[1],
  Johnson_58_augmented_dodecahedron_verts[2],
  Johnson_58_augmented_dodecahedron_verts[3],
  Johnson_58_augmented_dodecahedron_verts[4],
  Johnson_58_augmented_dodecahedron_verts[5],
  Johnson_58_augmented_dodecahedron_verts[6],
  Johnson_58_augmented_dodecahedron_verts[7],
  Johnson_58_augmented_dodecahedron_verts[8],
  Johnson_58_augmented_dodecahedron_verts[9],
  Johnson_58_augmented_dodecahedron_verts[10],
  Johnson_58_augmented_dodecahedron_verts[11],
  Johnson_58_augmented_dodecahedron_verts[12],
  Johnson_58_augmented_dodecahedron_verts[13],
  Johnson_58_augmented_dodecahedron_verts[14],
  Johnson_58_augmented_dodecahedron_verts[15],
  Johnson_58_augmented_dodecahedron_verts[16],
  Johnson_58_augmented_dodecahedron_verts[17],
  Johnson_58_augmented_dodecahedron_verts[18],
  Johnson_58_augmented_dodecahedron_verts[19],
  Johnson_58_augmented_dodecahedron_verts[20]
 }
 face_indices {
  38,
  <2, 0, 5>,
  <2, 5, 8>,
  <2, 1, 0>,
  <2, 7, 1>,
  <7, 2, 8>,
  <18, 20, 16>,
  <18, 16, 11>,
  <18, 11, 12>,
  <6, 4, 11>,
  <6, 11, 16>,
  <6, 16, 13>,
  <1, 7, 12>,
  <1, 12, 11>,
  <1, 11, 4>,
  <8, 15, 18>,
  <8, 18, 12>,
  <8, 12, 7>,
  <17, 19, 20>,
  <17, 20, 18>,
  <17, 18, 15>,
  <14, 13, 16>,
  <14, 16, 20>,
  <14, 20, 19>,
  <19, 17, 10>,
  <19, 10, 9>,
  <19, 9, 14>,
  <15, 8, 5>,
  <15, 5, 10>,
  <15, 10, 17>,
  <4, 6, 3>,
  <4, 3, 0>,
  <4, 0, 1>,
  <13, 14, 9>,
  <13, 9, 3>,
  <13, 3, 6>,
  <3, 9, 10>,
  <3, 10, 5>,
  <3, 5, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_58_augmented_dodecahedron_verts[19];
 #local P1 = Johnson_58_augmented_dodecahedron_verts[16];
 #local P2 = Johnson_58_augmented_dodecahedron_verts[20];
 #local P3 = Johnson_58_augmented_dodecahedron_verts[13];
 #local P4 = Johnson_58_augmented_dodecahedron_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_58_augmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_58_augmented_dodecahedron_obj }
#end
#end

#macro Johnson_58_augmented_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_58_augmented_dodecahedron_verts[0], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[1], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[2], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[3], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[4], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[5], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[6], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[7], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[8], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[9], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[10], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[11], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[12], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[13], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[14], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[15], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[16], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[17], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[18], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[19], RadVer }
  sphere { Johnson_58_augmented_dodecahedron_verts[20], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_58_augmented_dodecahedron_verts[2], Johnson_58_augmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[0], Johnson_58_augmented_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[5], Johnson_58_augmented_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[5], Johnson_58_augmented_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[8], Johnson_58_augmented_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[2], Johnson_58_augmented_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[1], Johnson_58_augmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[2], Johnson_58_augmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[7], Johnson_58_augmented_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[8], Johnson_58_augmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[18], Johnson_58_augmented_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[20], Johnson_58_augmented_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[16], Johnson_58_augmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[11], Johnson_58_augmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[12], Johnson_58_augmented_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[6], Johnson_58_augmented_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[4], Johnson_58_augmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[16], Johnson_58_augmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[13], Johnson_58_augmented_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[7], Johnson_58_augmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[4], Johnson_58_augmented_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[8], Johnson_58_augmented_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[15], Johnson_58_augmented_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[17], Johnson_58_augmented_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[19], Johnson_58_augmented_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[15], Johnson_58_augmented_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[14], Johnson_58_augmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[19], Johnson_58_augmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[17], Johnson_58_augmented_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[10], Johnson_58_augmented_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[9], Johnson_58_augmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[5], Johnson_58_augmented_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[6], Johnson_58_augmented_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[3], Johnson_58_augmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_58_augmented_dodecahedron_verts[9], Johnson_58_augmented_dodecahedron_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_58_augmented_dodecahedron_verts[19];
 #local P1 = Johnson_58_augmented_dodecahedron_verts[16];
 #local P2 = Johnson_58_augmented_dodecahedron_verts[20];
 #local P3 = Johnson_58_augmented_dodecahedron_verts[13];
 #local P4 = Johnson_58_augmented_dodecahedron_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_59_parabiaugmented_dodecahedron_verts = array[22]
{
<-0.987924, -0.168105, -0.565605>,
<-0.950092, -0.216897, 0.133657>,
<-0.877263, 0.407337, -0.179083>,
<-0.637339, -0.699196, -0.269274>,
<-0.609869, -0.193139, 0.747222>,
<-0.519498, 0.310837, -0.775297>,
<-0.492028, 0.816894, 0.241199>,
<-0.371218, -0.373038, -0.831038>,
<-0.326770, 0.445779, 0.813687>,
<-0.103824, -0.973514, 0.095267>,
<-0.086847, -0.660753, 0.723496>,
<0.086847, 0.660753, -0.723496>,
<0.103824, 0.973513, -0.095267>,
<0.326770, -0.445780, -0.813687>,
<0.371218, 0.373038, 0.831038>,
<0.492028, -0.816894, -0.241199>,
<0.519498, -0.310837, 0.775297>,
<0.609869, 0.193139, -0.747222>,
<0.637339, 0.699195, 0.269274>,
<0.877262, -0.407338, 0.179083>,
<0.950092, 0.216897, -0.133657>,
<0.987924, 0.168105, 0.565605>,
}
#declare P0 = Johnson_59_parabiaugmented_dodecahedron_verts[15];
#declare P1 = Johnson_59_parabiaugmented_dodecahedron_verts[9];
#declare P2 = Johnson_59_parabiaugmented_dodecahedron_verts[3];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 22)
 #declare Johnson_59_parabiaugmented_dodecahedron_verts[Num] = vtransform(Johnson_59_parabiaugmented_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_59_parabiaugmented_dodecahedron_faces(Tex3, Tex5, OnPlane)
#local Johnson_59_parabiaugmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  22,
  Johnson_59_parabiaugmented_dodecahedron_verts[0],
  Johnson_59_parabiaugmented_dodecahedron_verts[1],
  Johnson_59_parabiaugmented_dodecahedron_verts[2],
  Johnson_59_parabiaugmented_dodecahedron_verts[3],
  Johnson_59_parabiaugmented_dodecahedron_verts[4],
  Johnson_59_parabiaugmented_dodecahedron_verts[5],
  Johnson_59_parabiaugmented_dodecahedron_verts[6],
  Johnson_59_parabiaugmented_dodecahedron_verts[7],
  Johnson_59_parabiaugmented_dodecahedron_verts[8],
  Johnson_59_parabiaugmented_dodecahedron_verts[9],
  Johnson_59_parabiaugmented_dodecahedron_verts[10],
  Johnson_59_parabiaugmented_dodecahedron_verts[11],
  Johnson_59_parabiaugmented_dodecahedron_verts[12],
  Johnson_59_parabiaugmented_dodecahedron_verts[13],
  Johnson_59_parabiaugmented_dodecahedron_verts[14],
  Johnson_59_parabiaugmented_dodecahedron_verts[15],
  Johnson_59_parabiaugmented_dodecahedron_verts[16],
  Johnson_59_parabiaugmented_dodecahedron_verts[17],
  Johnson_59_parabiaugmented_dodecahedron_verts[18],
  Johnson_59_parabiaugmented_dodecahedron_verts[19],
  Johnson_59_parabiaugmented_dodecahedron_verts[20],
  Johnson_59_parabiaugmented_dodecahedron_verts[21]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  40,
  <0, 7, 3>, 0,
  <0, 3, 1>, 0,
  <0, 5, 7>, 0,
  <0, 2, 5>, 0,
  <2, 0, 1>, 0,
  <21, 18, 14>, 0,
  <21, 14, 16>, 0,
  <21, 20, 18>, 0,
  <21, 19, 20>, 0,
  <19, 21, 16>, 0,
  <6, 8, 14>, 1,
  <6, 14, 18>, 1,
  <6, 18, 12>, 1,
  <17, 11, 12>, 1,
  <17, 12, 18>, 1,
  <17, 18, 20>, 1,
  <5, 2, 6>, 1,
  <5, 6, 12>, 1,
  <5, 12, 11>, 1,
  <1, 4, 8>, 1,
  <1, 8, 6>, 1,
  <1, 6, 2>, 1,
  <10, 16, 14>, 1,
  <10, 14, 8>, 1,
  <10, 8, 4>, 1,
  <4, 1, 3>, 1,
  <4, 3, 9>, 1,
  <4, 9, 10>, 1,
  <11, 17, 13>, 1,
  <11, 13, 7>, 1,
  <11, 7, 5>, 1,
  <20, 19, 15>, 1,
  <20, 15, 13>, 1,
  <20, 13, 17>, 1,
  <16, 10, 9>, 1,
  <16, 9, 15>, 1,
  <16, 15, 19>, 1,
  <15, 9, 3>, 1,
  <15, 3, 7>, 1,
  <15, 7, 13>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_59_parabiaugmented_dodecahedron_verts[15];
 #local P1 = Johnson_59_parabiaugmented_dodecahedron_verts[9];
 #local P2 = Johnson_59_parabiaugmented_dodecahedron_verts[3];
 #local P3 = Johnson_59_parabiaugmented_dodecahedron_verts[7];
 #local P4 = Johnson_59_parabiaugmented_dodecahedron_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_59_parabiaugmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_59_parabiaugmented_dodecahedron_obj }
#end
#end

#macro Johnson_59_parabiaugmented_dodecahedron_faces2(OnPlane)
#local Johnson_59_parabiaugmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  22,
  Johnson_59_parabiaugmented_dodecahedron_verts[0],
  Johnson_59_parabiaugmented_dodecahedron_verts[1],
  Johnson_59_parabiaugmented_dodecahedron_verts[2],
  Johnson_59_parabiaugmented_dodecahedron_verts[3],
  Johnson_59_parabiaugmented_dodecahedron_verts[4],
  Johnson_59_parabiaugmented_dodecahedron_verts[5],
  Johnson_59_parabiaugmented_dodecahedron_verts[6],
  Johnson_59_parabiaugmented_dodecahedron_verts[7],
  Johnson_59_parabiaugmented_dodecahedron_verts[8],
  Johnson_59_parabiaugmented_dodecahedron_verts[9],
  Johnson_59_parabiaugmented_dodecahedron_verts[10],
  Johnson_59_parabiaugmented_dodecahedron_verts[11],
  Johnson_59_parabiaugmented_dodecahedron_verts[12],
  Johnson_59_parabiaugmented_dodecahedron_verts[13],
  Johnson_59_parabiaugmented_dodecahedron_verts[14],
  Johnson_59_parabiaugmented_dodecahedron_verts[15],
  Johnson_59_parabiaugmented_dodecahedron_verts[16],
  Johnson_59_parabiaugmented_dodecahedron_verts[17],
  Johnson_59_parabiaugmented_dodecahedron_verts[18],
  Johnson_59_parabiaugmented_dodecahedron_verts[19],
  Johnson_59_parabiaugmented_dodecahedron_verts[20],
  Johnson_59_parabiaugmented_dodecahedron_verts[21]
 }
 face_indices {
  40,
  <0, 7, 3>,
  <0, 3, 1>,
  <0, 5, 7>,
  <0, 2, 5>,
  <2, 0, 1>,
  <21, 18, 14>,
  <21, 14, 16>,
  <21, 20, 18>,
  <21, 19, 20>,
  <19, 21, 16>,
  <6, 8, 14>,
  <6, 14, 18>,
  <6, 18, 12>,
  <17, 11, 12>,
  <17, 12, 18>,
  <17, 18, 20>,
  <5, 2, 6>,
  <5, 6, 12>,
  <5, 12, 11>,
  <1, 4, 8>,
  <1, 8, 6>,
  <1, 6, 2>,
  <10, 16, 14>,
  <10, 14, 8>,
  <10, 8, 4>,
  <4, 1, 3>,
  <4, 3, 9>,
  <4, 9, 10>,
  <11, 17, 13>,
  <11, 13, 7>,
  <11, 7, 5>,
  <20, 19, 15>,
  <20, 15, 13>,
  <20, 13, 17>,
  <16, 10, 9>,
  <16, 9, 15>,
  <16, 15, 19>,
  <15, 9, 3>,
  <15, 3, 7>,
  <15, 7, 13>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_59_parabiaugmented_dodecahedron_verts[15];
 #local P1 = Johnson_59_parabiaugmented_dodecahedron_verts[9];
 #local P2 = Johnson_59_parabiaugmented_dodecahedron_verts[3];
 #local P3 = Johnson_59_parabiaugmented_dodecahedron_verts[7];
 #local P4 = Johnson_59_parabiaugmented_dodecahedron_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_59_parabiaugmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_59_parabiaugmented_dodecahedron_obj }
#end
#end

#macro Johnson_59_parabiaugmented_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[0], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[1], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[2], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[3], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[4], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[5], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[6], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[7], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[8], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[9], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[10], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[11], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[12], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[13], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[14], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[15], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[16], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[17], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[18], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[19], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[20], RadVer }
  sphere { Johnson_59_parabiaugmented_dodecahedron_verts[21], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[0], Johnson_59_parabiaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[7], Johnson_59_parabiaugmented_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[3], Johnson_59_parabiaugmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[3], Johnson_59_parabiaugmented_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[1], Johnson_59_parabiaugmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[0], Johnson_59_parabiaugmented_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[5], Johnson_59_parabiaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[0], Johnson_59_parabiaugmented_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[2], Johnson_59_parabiaugmented_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[1], Johnson_59_parabiaugmented_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[21], Johnson_59_parabiaugmented_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[18], Johnson_59_parabiaugmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[14], Johnson_59_parabiaugmented_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[14], Johnson_59_parabiaugmented_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[16], Johnson_59_parabiaugmented_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[21], Johnson_59_parabiaugmented_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[20], Johnson_59_parabiaugmented_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[21], Johnson_59_parabiaugmented_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[19], Johnson_59_parabiaugmented_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[16], Johnson_59_parabiaugmented_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[6], Johnson_59_parabiaugmented_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[8], Johnson_59_parabiaugmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[18], Johnson_59_parabiaugmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[12], Johnson_59_parabiaugmented_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[17], Johnson_59_parabiaugmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[11], Johnson_59_parabiaugmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[20], Johnson_59_parabiaugmented_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[2], Johnson_59_parabiaugmented_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[11], Johnson_59_parabiaugmented_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[1], Johnson_59_parabiaugmented_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[4], Johnson_59_parabiaugmented_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[10], Johnson_59_parabiaugmented_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[4], Johnson_59_parabiaugmented_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[3], Johnson_59_parabiaugmented_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[9], Johnson_59_parabiaugmented_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[17], Johnson_59_parabiaugmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[13], Johnson_59_parabiaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[19], Johnson_59_parabiaugmented_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[15], Johnson_59_parabiaugmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_59_parabiaugmented_dodecahedron_verts[9], Johnson_59_parabiaugmented_dodecahedron_verts[15], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_59_parabiaugmented_dodecahedron_verts[15];
 #local P1 = Johnson_59_parabiaugmented_dodecahedron_verts[9];
 #local P2 = Johnson_59_parabiaugmented_dodecahedron_verts[3];
 #local P3 = Johnson_59_parabiaugmented_dodecahedron_verts[7];
 #local P4 = Johnson_59_parabiaugmented_dodecahedron_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_60_metabiaugmented_dodecahedron_verts = array[22]
{
<-0.858966, -0.256781, -0.362035>,
<-0.807204, -0.391109, 0.326114>,
<-0.719263, 0.425042, -0.461407>,
<-0.635510, 0.207695, 0.652043>,
<-0.581160, 0.712103, 0.165328>,
<-0.463060, -0.410585, 0.938862>,
<-0.364654, -0.630479, -0.694119>,
<-0.311484, 0.996138, -0.418515>,
<-0.280902, -0.847826, 0.419331>,
<-0.138610, 0.472734, -0.854906>,
<-0.007391, -0.995764, -0.211209>,
<-0.003096, 0.121058, 0.946694>,
<0.080550, -0.179614, -0.998730>,
<0.084846, 0.937209, 0.159173>,
<0.216065, -0.531289, 0.802870>,
<0.358357, 0.789271, -0.471366>,
<0.442109, 0.571923, 0.642084>,
<0.658614, -0.770659, -0.217364>,
<0.712965, -0.266250, -0.704079>,
<0.796718, -0.483597, 0.409371>,
<0.884659, 0.332554, -0.378150>,
<0.936421, 0.198226, 0.310000>,
}
#declare P0 = Johnson_60_metabiaugmented_dodecahedron_verts[21];
#declare P1 = Johnson_60_metabiaugmented_dodecahedron_verts[20];
#declare P2 = Johnson_60_metabiaugmented_dodecahedron_verts[15];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 22)
 #declare Johnson_60_metabiaugmented_dodecahedron_verts[Num] = vtransform(Johnson_60_metabiaugmented_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_60_metabiaugmented_dodecahedron_faces(Tex3, Tex5, OnPlane)
#local Johnson_60_metabiaugmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  22,
  Johnson_60_metabiaugmented_dodecahedron_verts[0],
  Johnson_60_metabiaugmented_dodecahedron_verts[1],
  Johnson_60_metabiaugmented_dodecahedron_verts[2],
  Johnson_60_metabiaugmented_dodecahedron_verts[3],
  Johnson_60_metabiaugmented_dodecahedron_verts[4],
  Johnson_60_metabiaugmented_dodecahedron_verts[5],
  Johnson_60_metabiaugmented_dodecahedron_verts[6],
  Johnson_60_metabiaugmented_dodecahedron_verts[7],
  Johnson_60_metabiaugmented_dodecahedron_verts[8],
  Johnson_60_metabiaugmented_dodecahedron_verts[9],
  Johnson_60_metabiaugmented_dodecahedron_verts[10],
  Johnson_60_metabiaugmented_dodecahedron_verts[11],
  Johnson_60_metabiaugmented_dodecahedron_verts[12],
  Johnson_60_metabiaugmented_dodecahedron_verts[13],
  Johnson_60_metabiaugmented_dodecahedron_verts[14],
  Johnson_60_metabiaugmented_dodecahedron_verts[15],
  Johnson_60_metabiaugmented_dodecahedron_verts[16],
  Johnson_60_metabiaugmented_dodecahedron_verts[17],
  Johnson_60_metabiaugmented_dodecahedron_verts[18],
  Johnson_60_metabiaugmented_dodecahedron_verts[19],
  Johnson_60_metabiaugmented_dodecahedron_verts[20],
  Johnson_60_metabiaugmented_dodecahedron_verts[21]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  40,
  <7, 13, 15>, 0,
  <7, 15, 9>, 0,
  <7, 4, 13>, 0,
  <7, 2, 4>, 0,
  <2, 7, 9>, 0,
  <5, 1, 8>, 0,
  <5, 8, 14>, 0,
  <5, 3, 1>, 0,
  <5, 11, 3>, 0,
  <11, 5, 14>, 0,
  <0, 6, 10>, 1,
  <0, 10, 8>, 1,
  <0, 8, 1>, 1,
  <19, 14, 8>, 1,
  <19, 8, 10>, 1,
  <19, 10, 17>, 1,
  <4, 2, 0>, 1,
  <4, 0, 1>, 1,
  <4, 1, 3>, 1,
  <9, 12, 6>, 1,
  <9, 6, 0>, 1,
  <9, 0, 2>, 1,
  <18, 17, 10>, 1,
  <18, 10, 6>, 1,
  <18, 6, 12>, 1,
  <12, 9, 15>, 1,
  <12, 15, 20>, 1,
  <12, 20, 18>, 1,
  <3, 11, 16>, 1,
  <3, 16, 13>, 1,
  <3, 13, 4>, 1,
  <14, 19, 21>, 1,
  <14, 21, 16>, 1,
  <14, 16, 11>, 1,
  <17, 18, 20>, 1,
  <17, 20, 21>, 1,
  <17, 21, 19>, 1,
  <21, 20, 15>, 1,
  <21, 15, 13>, 1,
  <21, 13, 16>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_60_metabiaugmented_dodecahedron_verts[21];
 #local P1 = Johnson_60_metabiaugmented_dodecahedron_verts[20];
 #local P2 = Johnson_60_metabiaugmented_dodecahedron_verts[15];
 #local P3 = Johnson_60_metabiaugmented_dodecahedron_verts[13];
 #local P4 = Johnson_60_metabiaugmented_dodecahedron_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_60_metabiaugmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_60_metabiaugmented_dodecahedron_obj }
#end
#end

#macro Johnson_60_metabiaugmented_dodecahedron_faces2(OnPlane)
#local Johnson_60_metabiaugmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  22,
  Johnson_60_metabiaugmented_dodecahedron_verts[0],
  Johnson_60_metabiaugmented_dodecahedron_verts[1],
  Johnson_60_metabiaugmented_dodecahedron_verts[2],
  Johnson_60_metabiaugmented_dodecahedron_verts[3],
  Johnson_60_metabiaugmented_dodecahedron_verts[4],
  Johnson_60_metabiaugmented_dodecahedron_verts[5],
  Johnson_60_metabiaugmented_dodecahedron_verts[6],
  Johnson_60_metabiaugmented_dodecahedron_verts[7],
  Johnson_60_metabiaugmented_dodecahedron_verts[8],
  Johnson_60_metabiaugmented_dodecahedron_verts[9],
  Johnson_60_metabiaugmented_dodecahedron_verts[10],
  Johnson_60_metabiaugmented_dodecahedron_verts[11],
  Johnson_60_metabiaugmented_dodecahedron_verts[12],
  Johnson_60_metabiaugmented_dodecahedron_verts[13],
  Johnson_60_metabiaugmented_dodecahedron_verts[14],
  Johnson_60_metabiaugmented_dodecahedron_verts[15],
  Johnson_60_metabiaugmented_dodecahedron_verts[16],
  Johnson_60_metabiaugmented_dodecahedron_verts[17],
  Johnson_60_metabiaugmented_dodecahedron_verts[18],
  Johnson_60_metabiaugmented_dodecahedron_verts[19],
  Johnson_60_metabiaugmented_dodecahedron_verts[20],
  Johnson_60_metabiaugmented_dodecahedron_verts[21]
 }
 face_indices {
  40,
  <7, 13, 15>,
  <7, 15, 9>,
  <7, 4, 13>,
  <7, 2, 4>,
  <2, 7, 9>,
  <5, 1, 8>,
  <5, 8, 14>,
  <5, 3, 1>,
  <5, 11, 3>,
  <11, 5, 14>,
  <0, 6, 10>,
  <0, 10, 8>,
  <0, 8, 1>,
  <19, 14, 8>,
  <19, 8, 10>,
  <19, 10, 17>,
  <4, 2, 0>,
  <4, 0, 1>,
  <4, 1, 3>,
  <9, 12, 6>,
  <9, 6, 0>,
  <9, 0, 2>,
  <18, 17, 10>,
  <18, 10, 6>,
  <18, 6, 12>,
  <12, 9, 15>,
  <12, 15, 20>,
  <12, 20, 18>,
  <3, 11, 16>,
  <3, 16, 13>,
  <3, 13, 4>,
  <14, 19, 21>,
  <14, 21, 16>,
  <14, 16, 11>,
  <17, 18, 20>,
  <17, 20, 21>,
  <17, 21, 19>,
  <21, 20, 15>,
  <21, 15, 13>,
  <21, 13, 16>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_60_metabiaugmented_dodecahedron_verts[21];
 #local P1 = Johnson_60_metabiaugmented_dodecahedron_verts[20];
 #local P2 = Johnson_60_metabiaugmented_dodecahedron_verts[15];
 #local P3 = Johnson_60_metabiaugmented_dodecahedron_verts[13];
 #local P4 = Johnson_60_metabiaugmented_dodecahedron_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_60_metabiaugmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_60_metabiaugmented_dodecahedron_obj }
#end
#end

#macro Johnson_60_metabiaugmented_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[0], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[1], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[2], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[3], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[4], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[5], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[6], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[7], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[8], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[9], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[10], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[11], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[12], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[13], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[14], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[15], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[16], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[17], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[18], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[19], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[20], RadVer }
  sphere { Johnson_60_metabiaugmented_dodecahedron_verts[21], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[7], Johnson_60_metabiaugmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[13], Johnson_60_metabiaugmented_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[15], Johnson_60_metabiaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[15], Johnson_60_metabiaugmented_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[9], Johnson_60_metabiaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[7], Johnson_60_metabiaugmented_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[4], Johnson_60_metabiaugmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[7], Johnson_60_metabiaugmented_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[2], Johnson_60_metabiaugmented_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[9], Johnson_60_metabiaugmented_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[5], Johnson_60_metabiaugmented_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[1], Johnson_60_metabiaugmented_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[8], Johnson_60_metabiaugmented_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[8], Johnson_60_metabiaugmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[14], Johnson_60_metabiaugmented_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[5], Johnson_60_metabiaugmented_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[3], Johnson_60_metabiaugmented_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[5], Johnson_60_metabiaugmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[11], Johnson_60_metabiaugmented_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[14], Johnson_60_metabiaugmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[0], Johnson_60_metabiaugmented_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[6], Johnson_60_metabiaugmented_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[10], Johnson_60_metabiaugmented_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[1], Johnson_60_metabiaugmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[19], Johnson_60_metabiaugmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[10], Johnson_60_metabiaugmented_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[17], Johnson_60_metabiaugmented_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[2], Johnson_60_metabiaugmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[3], Johnson_60_metabiaugmented_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[9], Johnson_60_metabiaugmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[12], Johnson_60_metabiaugmented_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[18], Johnson_60_metabiaugmented_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[12], Johnson_60_metabiaugmented_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[15], Johnson_60_metabiaugmented_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[20], Johnson_60_metabiaugmented_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[11], Johnson_60_metabiaugmented_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[16], Johnson_60_metabiaugmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[19], Johnson_60_metabiaugmented_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[21], Johnson_60_metabiaugmented_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_60_metabiaugmented_dodecahedron_verts[20], Johnson_60_metabiaugmented_dodecahedron_verts[21], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_60_metabiaugmented_dodecahedron_verts[21];
 #local P1 = Johnson_60_metabiaugmented_dodecahedron_verts[20];
 #local P2 = Johnson_60_metabiaugmented_dodecahedron_verts[15];
 #local P3 = Johnson_60_metabiaugmented_dodecahedron_verts[13];
 #local P4 = Johnson_60_metabiaugmented_dodecahedron_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_61_triaugmented_dodecahedron_verts = array[23]
{
<-0.875027, -0.215344, -0.354115>,
<-0.822602, -0.401147, 0.315989>,
<-0.733096, 0.465836, -0.400606>,
<-0.648272, 0.165200, 0.683645>,
<-0.625957, 0.049095, -0.949385>,
<-0.592955, 0.701024, 0.240765>,
<-0.479753, -0.469083, 0.919437>,
<-0.387571, -0.561993, -0.712628>,
<-0.302747, -0.862629, 0.371622>,
<-0.157924, 0.540178, -0.787852>,
<-0.033883, -0.962037, -0.264098>,
<-0.020675, 0.053739, 0.966503>,
<0.055623, -0.095055, -0.980693>,
<0.068831, 0.920721, 0.249908>,
<0.192872, -0.581494, 0.773662>,
<0.337694, 0.821313, -0.385812>,
<0.422519, 0.520677, 0.698439>,
<0.627903, -0.742340, -0.254955>,
<0.683221, -0.206515, -0.697835>,
<0.756251, 0.833140, 0.171845>,
<0.768045, -0.507151, 0.386416>,
<0.857550, 0.359831, -0.330178>,
<0.909975, 0.174028, 0.339925>,
}
#declare P0 = Johnson_61_triaugmented_dodecahedron_verts[2];
#declare P1 = Johnson_61_triaugmented_dodecahedron_verts[0];
#declare P2 = Johnson_61_triaugmented_dodecahedron_verts[1];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 23)
 #declare Johnson_61_triaugmented_dodecahedron_verts[Num] = vtransform(Johnson_61_triaugmented_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_61_triaugmented_dodecahedron_faces(Tex3, Tex5, OnPlane)
#local Johnson_61_triaugmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  23,
  Johnson_61_triaugmented_dodecahedron_verts[0],
  Johnson_61_triaugmented_dodecahedron_verts[1],
  Johnson_61_triaugmented_dodecahedron_verts[2],
  Johnson_61_triaugmented_dodecahedron_verts[3],
  Johnson_61_triaugmented_dodecahedron_verts[4],
  Johnson_61_triaugmented_dodecahedron_verts[5],
  Johnson_61_triaugmented_dodecahedron_verts[6],
  Johnson_61_triaugmented_dodecahedron_verts[7],
  Johnson_61_triaugmented_dodecahedron_verts[8],
  Johnson_61_triaugmented_dodecahedron_verts[9],
  Johnson_61_triaugmented_dodecahedron_verts[10],
  Johnson_61_triaugmented_dodecahedron_verts[11],
  Johnson_61_triaugmented_dodecahedron_verts[12],
  Johnson_61_triaugmented_dodecahedron_verts[13],
  Johnson_61_triaugmented_dodecahedron_verts[14],
  Johnson_61_triaugmented_dodecahedron_verts[15],
  Johnson_61_triaugmented_dodecahedron_verts[16],
  Johnson_61_triaugmented_dodecahedron_verts[17],
  Johnson_61_triaugmented_dodecahedron_verts[18],
  Johnson_61_triaugmented_dodecahedron_verts[19],
  Johnson_61_triaugmented_dodecahedron_verts[20],
  Johnson_61_triaugmented_dodecahedron_verts[21],
  Johnson_61_triaugmented_dodecahedron_verts[22]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  42,
  <6, 3, 1>, 0,
  <6, 1, 8>, 0,
  <6, 11, 3>, 0,
  <6, 14, 11>, 0,
  <14, 6, 8>, 0,
  <19, 22, 21>, 0,
  <19, 21, 15>, 0,
  <19, 16, 22>, 0,
  <19, 13, 16>, 0,
  <13, 19, 15>, 0,
  <4, 0, 2>, 0,
  <4, 2, 9>, 0,
  <4, 7, 0>, 0,
  <4, 12, 7>, 0,
  <12, 4, 9>, 0,
  <20, 17, 18>, 1,
  <20, 18, 21>, 1,
  <20, 21, 22>, 1,
  <9, 15, 21>, 1,
  <9, 21, 18>, 1,
  <9, 18, 12>, 1,
  <11, 14, 20>, 1,
  <11, 20, 22>, 1,
  <11, 22, 16>, 1,
  <8, 10, 17>, 1,
  <8, 17, 20>, 1,
  <8, 20, 14>, 1,
  <7, 12, 18>, 1,
  <7, 18, 17>, 1,
  <7, 17, 10>, 1,
  <10, 8, 1>, 1,
  <10, 1, 0>, 1,
  <10, 0, 7>, 1,
  <16, 13, 5>, 1,
  <16, 5, 3>, 1,
  <16, 3, 11>, 1,
  <15, 9, 2>, 1,
  <15, 2, 5>, 1,
  <15, 5, 13>, 1,
  <2, 0, 1>, 1,
  <2, 1, 3>, 1,
  <2, 3, 5>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_61_triaugmented_dodecahedron_verts[2];
 #local P1 = Johnson_61_triaugmented_dodecahedron_verts[0];
 #local P2 = Johnson_61_triaugmented_dodecahedron_verts[1];
 #local P3 = Johnson_61_triaugmented_dodecahedron_verts[3];
 #local P4 = Johnson_61_triaugmented_dodecahedron_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_61_triaugmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_61_triaugmented_dodecahedron_obj }
#end
#end

#macro Johnson_61_triaugmented_dodecahedron_faces2(OnPlane)
#local Johnson_61_triaugmented_dodecahedron_obj = mesh2 {
 vertex_vectors {
  23,
  Johnson_61_triaugmented_dodecahedron_verts[0],
  Johnson_61_triaugmented_dodecahedron_verts[1],
  Johnson_61_triaugmented_dodecahedron_verts[2],
  Johnson_61_triaugmented_dodecahedron_verts[3],
  Johnson_61_triaugmented_dodecahedron_verts[4],
  Johnson_61_triaugmented_dodecahedron_verts[5],
  Johnson_61_triaugmented_dodecahedron_verts[6],
  Johnson_61_triaugmented_dodecahedron_verts[7],
  Johnson_61_triaugmented_dodecahedron_verts[8],
  Johnson_61_triaugmented_dodecahedron_verts[9],
  Johnson_61_triaugmented_dodecahedron_verts[10],
  Johnson_61_triaugmented_dodecahedron_verts[11],
  Johnson_61_triaugmented_dodecahedron_verts[12],
  Johnson_61_triaugmented_dodecahedron_verts[13],
  Johnson_61_triaugmented_dodecahedron_verts[14],
  Johnson_61_triaugmented_dodecahedron_verts[15],
  Johnson_61_triaugmented_dodecahedron_verts[16],
  Johnson_61_triaugmented_dodecahedron_verts[17],
  Johnson_61_triaugmented_dodecahedron_verts[18],
  Johnson_61_triaugmented_dodecahedron_verts[19],
  Johnson_61_triaugmented_dodecahedron_verts[20],
  Johnson_61_triaugmented_dodecahedron_verts[21],
  Johnson_61_triaugmented_dodecahedron_verts[22]
 }
 face_indices {
  42,
  <6, 3, 1>,
  <6, 1, 8>,
  <6, 11, 3>,
  <6, 14, 11>,
  <14, 6, 8>,
  <19, 22, 21>,
  <19, 21, 15>,
  <19, 16, 22>,
  <19, 13, 16>,
  <13, 19, 15>,
  <4, 0, 2>,
  <4, 2, 9>,
  <4, 7, 0>,
  <4, 12, 7>,
  <12, 4, 9>,
  <20, 17, 18>,
  <20, 18, 21>,
  <20, 21, 22>,
  <9, 15, 21>,
  <9, 21, 18>,
  <9, 18, 12>,
  <11, 14, 20>,
  <11, 20, 22>,
  <11, 22, 16>,
  <8, 10, 17>,
  <8, 17, 20>,
  <8, 20, 14>,
  <7, 12, 18>,
  <7, 18, 17>,
  <7, 17, 10>,
  <10, 8, 1>,
  <10, 1, 0>,
  <10, 0, 7>,
  <16, 13, 5>,
  <16, 5, 3>,
  <16, 3, 11>,
  <15, 9, 2>,
  <15, 2, 5>,
  <15, 5, 13>,
  <2, 0, 1>,
  <2, 1, 3>,
  <2, 3, 5>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_61_triaugmented_dodecahedron_verts[2];
 #local P1 = Johnson_61_triaugmented_dodecahedron_verts[0];
 #local P2 = Johnson_61_triaugmented_dodecahedron_verts[1];
 #local P3 = Johnson_61_triaugmented_dodecahedron_verts[3];
 #local P4 = Johnson_61_triaugmented_dodecahedron_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_61_triaugmented_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_61_triaugmented_dodecahedron_obj }
#end
#end

#macro Johnson_61_triaugmented_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_61_triaugmented_dodecahedron_verts[0], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[1], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[2], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[3], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[4], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[5], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[6], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[7], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[8], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[9], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[10], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[11], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[12], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[13], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[14], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[15], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[16], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[17], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[18], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[19], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[20], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[21], RadVer }
  sphere { Johnson_61_triaugmented_dodecahedron_verts[22], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[6], Johnson_61_triaugmented_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[3], Johnson_61_triaugmented_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[1], Johnson_61_triaugmented_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[1], Johnson_61_triaugmented_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[8], Johnson_61_triaugmented_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[6], Johnson_61_triaugmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[11], Johnson_61_triaugmented_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[6], Johnson_61_triaugmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[14], Johnson_61_triaugmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[8], Johnson_61_triaugmented_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[19], Johnson_61_triaugmented_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[22], Johnson_61_triaugmented_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[21], Johnson_61_triaugmented_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[21], Johnson_61_triaugmented_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[15], Johnson_61_triaugmented_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[19], Johnson_61_triaugmented_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[16], Johnson_61_triaugmented_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[19], Johnson_61_triaugmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[13], Johnson_61_triaugmented_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[15], Johnson_61_triaugmented_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[4], Johnson_61_triaugmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[0], Johnson_61_triaugmented_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[2], Johnson_61_triaugmented_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[2], Johnson_61_triaugmented_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[9], Johnson_61_triaugmented_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[4], Johnson_61_triaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[7], Johnson_61_triaugmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[4], Johnson_61_triaugmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[12], Johnson_61_triaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[9], Johnson_61_triaugmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[20], Johnson_61_triaugmented_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[17], Johnson_61_triaugmented_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[18], Johnson_61_triaugmented_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[22], Johnson_61_triaugmented_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[9], Johnson_61_triaugmented_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[18], Johnson_61_triaugmented_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[14], Johnson_61_triaugmented_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[16], Johnson_61_triaugmented_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[8], Johnson_61_triaugmented_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[10], Johnson_61_triaugmented_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[10], Johnson_61_triaugmented_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[1], Johnson_61_triaugmented_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[13], Johnson_61_triaugmented_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[5], Johnson_61_triaugmented_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_61_triaugmented_dodecahedron_verts[2], Johnson_61_triaugmented_dodecahedron_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_61_triaugmented_dodecahedron_verts[2];
 #local P1 = Johnson_61_triaugmented_dodecahedron_verts[0];
 #local P2 = Johnson_61_triaugmented_dodecahedron_verts[1];
 #local P3 = Johnson_61_triaugmented_dodecahedron_verts[3];
 #local P4 = Johnson_61_triaugmented_dodecahedron_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_62_metabidiminished_icosahedron_verts = array[10]
{
<-0.821855, 0.223834, -0.340481>,
<-0.710390, -0.701977, 0.157898>,
<-0.692806, 0.200390, 0.708676>,
<-0.215696, -0.533443, -0.761235>,
<-0.187244, 0.926618, 0.129942>,
<-0.006891, -0.571377, 0.936336>,
<0.107626, 0.473083, -0.778513>,
<0.793541, -0.298683, -0.550854>,
<0.811125, 0.603684, -0.000076>,
<0.922590, -0.322128, 0.498303>,
}
#declare P0 = Johnson_62_metabidiminished_icosahedron_verts[7];
#declare P1 = Johnson_62_metabidiminished_icosahedron_verts[8];
#declare P2 = Johnson_62_metabidiminished_icosahedron_verts[9];
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
 #declare Johnson_62_metabidiminished_icosahedron_verts[Num] = vtransform(Johnson_62_metabidiminished_icosahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_62_metabidiminished_icosahedron_faces(Tex3, Tex5, OnPlane)
#local Johnson_62_metabidiminished_icosahedron_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_62_metabidiminished_icosahedron_verts[0],
  Johnson_62_metabidiminished_icosahedron_verts[1],
  Johnson_62_metabidiminished_icosahedron_verts[2],
  Johnson_62_metabidiminished_icosahedron_verts[3],
  Johnson_62_metabidiminished_icosahedron_verts[4],
  Johnson_62_metabidiminished_icosahedron_verts[5],
  Johnson_62_metabidiminished_icosahedron_verts[6],
  Johnson_62_metabidiminished_icosahedron_verts[7],
  Johnson_62_metabidiminished_icosahedron_verts[8],
  Johnson_62_metabidiminished_icosahedron_verts[9]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  16,
  <6, 3, 0>, 0,
  <0, 3, 1>, 0,
  <1, 5, 2>, 0,
  <1, 2, 0>, 0,
  <2, 4, 0>, 0,
  <4, 8, 6>, 0,
  <4, 6, 0>, 0,
  <9, 7, 8>, 0,
  <7, 6, 8>, 0,
  <7, 3, 6>, 0,
  <1, 3, 7>, 1,
  <1, 7, 9>, 1,
  <1, 9, 5>, 1,
  <2, 5, 9>, 1,
  <2, 9, 8>, 1,
  <2, 8, 4>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_62_metabidiminished_icosahedron_verts[7];
 #local P1 = Johnson_62_metabidiminished_icosahedron_verts[8];
 #local P2 = Johnson_62_metabidiminished_icosahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_62_metabidiminished_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_62_metabidiminished_icosahedron_obj }
#end
#end

#macro Johnson_62_metabidiminished_icosahedron_faces2(OnPlane)
#local Johnson_62_metabidiminished_icosahedron_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_62_metabidiminished_icosahedron_verts[0],
  Johnson_62_metabidiminished_icosahedron_verts[1],
  Johnson_62_metabidiminished_icosahedron_verts[2],
  Johnson_62_metabidiminished_icosahedron_verts[3],
  Johnson_62_metabidiminished_icosahedron_verts[4],
  Johnson_62_metabidiminished_icosahedron_verts[5],
  Johnson_62_metabidiminished_icosahedron_verts[6],
  Johnson_62_metabidiminished_icosahedron_verts[7],
  Johnson_62_metabidiminished_icosahedron_verts[8],
  Johnson_62_metabidiminished_icosahedron_verts[9]
 }
 face_indices {
  16,
  <6, 3, 0>,
  <0, 3, 1>,
  <1, 5, 2>,
  <1, 2, 0>,
  <2, 4, 0>,
  <4, 8, 6>,
  <4, 6, 0>,
  <9, 7, 8>,
  <7, 6, 8>,
  <7, 3, 6>,
  <1, 3, 7>,
  <1, 7, 9>,
  <1, 9, 5>,
  <2, 5, 9>,
  <2, 9, 8>,
  <2, 8, 4>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_62_metabidiminished_icosahedron_verts[7];
 #local P1 = Johnson_62_metabidiminished_icosahedron_verts[8];
 #local P2 = Johnson_62_metabidiminished_icosahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_62_metabidiminished_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_62_metabidiminished_icosahedron_obj }
#end
#end

#macro Johnson_62_metabidiminished_icosahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_62_metabidiminished_icosahedron_verts[0], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[1], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[2], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[3], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[4], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[5], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[6], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[7], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[8], RadVer }
  sphere { Johnson_62_metabidiminished_icosahedron_verts[9], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[6], Johnson_62_metabidiminished_icosahedron_verts[3], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[3], Johnson_62_metabidiminished_icosahedron_verts[0], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[0], Johnson_62_metabidiminished_icosahedron_verts[6], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[3], Johnson_62_metabidiminished_icosahedron_verts[1], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[1], Johnson_62_metabidiminished_icosahedron_verts[0], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[1], Johnson_62_metabidiminished_icosahedron_verts[5], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[5], Johnson_62_metabidiminished_icosahedron_verts[2], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[2], Johnson_62_metabidiminished_icosahedron_verts[1], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[2], Johnson_62_metabidiminished_icosahedron_verts[0], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[2], Johnson_62_metabidiminished_icosahedron_verts[4], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[4], Johnson_62_metabidiminished_icosahedron_verts[0], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[4], Johnson_62_metabidiminished_icosahedron_verts[8], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[8], Johnson_62_metabidiminished_icosahedron_verts[6], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[6], Johnson_62_metabidiminished_icosahedron_verts[4], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[9], Johnson_62_metabidiminished_icosahedron_verts[7], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[7], Johnson_62_metabidiminished_icosahedron_verts[8], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[8], Johnson_62_metabidiminished_icosahedron_verts[9], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[7], Johnson_62_metabidiminished_icosahedron_verts[6], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[7], Johnson_62_metabidiminished_icosahedron_verts[3], RadEdg }
  cylinder { Johnson_62_metabidiminished_icosahedron_verts[9], Johnson_62_metabidiminished_icosahedron_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_62_metabidiminished_icosahedron_verts[7];
 #local P1 = Johnson_62_metabidiminished_icosahedron_verts[8];
 #local P2 = Johnson_62_metabidiminished_icosahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_63_tridiminished_icosahedron_verts = array[9]
{
<-0.799898, 0.494585, -0.153719>,
<-0.680241, -0.086273, 0.717027>,
<-0.306176, 0.002547, -0.943688>,
<-0.112567, -0.937300, 0.465209>,
<-0.077419, 0.764103, 0.564122>,
<0.118618, -0.882406, -0.561170>,
<0.153766, 0.818996, -0.462256>,
<0.841097, -0.612888, 0.156672>,
<0.862820, 0.438637, 0.217804>,
}
#declare P0 = Johnson_63_tridiminished_icosahedron_verts[3];
#declare P1 = Johnson_63_tridiminished_icosahedron_verts[5];
#declare P2 = Johnson_63_tridiminished_icosahedron_verts[7];
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
 #declare Johnson_63_tridiminished_icosahedron_verts[Num] = vtransform(Johnson_63_tridiminished_icosahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_63_tridiminished_icosahedron_faces(Tex3, Tex5, OnPlane)
#local Johnson_63_tridiminished_icosahedron_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_63_tridiminished_icosahedron_verts[0],
  Johnson_63_tridiminished_icosahedron_verts[1],
  Johnson_63_tridiminished_icosahedron_verts[2],
  Johnson_63_tridiminished_icosahedron_verts[3],
  Johnson_63_tridiminished_icosahedron_verts[4],
  Johnson_63_tridiminished_icosahedron_verts[5],
  Johnson_63_tridiminished_icosahedron_verts[6],
  Johnson_63_tridiminished_icosahedron_verts[7],
  Johnson_63_tridiminished_icosahedron_verts[8]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  14,
  <0, 4, 6>, 0,
  <4, 8, 6>, 0,
  <6, 2, 0>, 0,
  <0, 1, 4>, 0,
  <5, 7, 3>, 0,
  <6, 8, 7>, 1,
  <6, 7, 5>, 1,
  <6, 5, 2>, 1,
  <0, 2, 5>, 1,
  <0, 5, 3>, 1,
  <0, 3, 1>, 1,
  <7, 8, 4>, 1,
  <7, 4, 1>, 1,
  <7, 1, 3>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_63_tridiminished_icosahedron_verts[3];
 #local P1 = Johnson_63_tridiminished_icosahedron_verts[5];
 #local P2 = Johnson_63_tridiminished_icosahedron_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_63_tridiminished_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_63_tridiminished_icosahedron_obj }
#end
#end

#macro Johnson_63_tridiminished_icosahedron_faces2(OnPlane)
#local Johnson_63_tridiminished_icosahedron_obj = mesh2 {
 vertex_vectors {
  9,
  Johnson_63_tridiminished_icosahedron_verts[0],
  Johnson_63_tridiminished_icosahedron_verts[1],
  Johnson_63_tridiminished_icosahedron_verts[2],
  Johnson_63_tridiminished_icosahedron_verts[3],
  Johnson_63_tridiminished_icosahedron_verts[4],
  Johnson_63_tridiminished_icosahedron_verts[5],
  Johnson_63_tridiminished_icosahedron_verts[6],
  Johnson_63_tridiminished_icosahedron_verts[7],
  Johnson_63_tridiminished_icosahedron_verts[8]
 }
 face_indices {
  14,
  <0, 4, 6>,
  <4, 8, 6>,
  <6, 2, 0>,
  <0, 1, 4>,
  <5, 7, 3>,
  <6, 8, 7>,
  <6, 7, 5>,
  <6, 5, 2>,
  <0, 2, 5>,
  <0, 5, 3>,
  <0, 3, 1>,
  <7, 8, 4>,
  <7, 4, 1>,
  <7, 1, 3>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_63_tridiminished_icosahedron_verts[3];
 #local P1 = Johnson_63_tridiminished_icosahedron_verts[5];
 #local P2 = Johnson_63_tridiminished_icosahedron_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_63_tridiminished_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_63_tridiminished_icosahedron_obj }
#end
#end

#macro Johnson_63_tridiminished_icosahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_63_tridiminished_icosahedron_verts[0], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[1], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[2], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[3], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[4], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[5], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[6], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[7], RadVer }
  sphere { Johnson_63_tridiminished_icosahedron_verts[8], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_63_tridiminished_icosahedron_verts[0], Johnson_63_tridiminished_icosahedron_verts[4], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[4], Johnson_63_tridiminished_icosahedron_verts[6], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[6], Johnson_63_tridiminished_icosahedron_verts[0], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[4], Johnson_63_tridiminished_icosahedron_verts[8], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[8], Johnson_63_tridiminished_icosahedron_verts[6], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[6], Johnson_63_tridiminished_icosahedron_verts[2], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[2], Johnson_63_tridiminished_icosahedron_verts[0], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[0], Johnson_63_tridiminished_icosahedron_verts[1], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[1], Johnson_63_tridiminished_icosahedron_verts[4], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[5], Johnson_63_tridiminished_icosahedron_verts[7], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[7], Johnson_63_tridiminished_icosahedron_verts[3], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[3], Johnson_63_tridiminished_icosahedron_verts[5], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[8], Johnson_63_tridiminished_icosahedron_verts[7], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[5], Johnson_63_tridiminished_icosahedron_verts[2], RadEdg }
  cylinder { Johnson_63_tridiminished_icosahedron_verts[3], Johnson_63_tridiminished_icosahedron_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_63_tridiminished_icosahedron_verts[3];
 #local P1 = Johnson_63_tridiminished_icosahedron_verts[5];
 #local P2 = Johnson_63_tridiminished_icosahedron_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_64_augmented_tridiminished_icosahedron_verts = array[10]
{
<-0.777985, -0.188235, -0.285228>,
<-0.489362, -0.260552, 0.643961>,
<-0.324420, 0.578558, -0.683014>,
<-0.099589, -0.843165, -0.034687>,
<0.142581, 0.461547, 0.820446>,
<0.244520, 0.980145, 0.000330>,
<0.634293, 0.397531, -0.678318>,
<0.773247, -0.481142, -0.277630>,
<0.922916, 0.325215, 0.250871>,
<-1.026197, -0.969903, 0.243270>,
}
#declare P0 = Johnson_64_augmented_tridiminished_icosahedron_verts[8];
#declare P1 = Johnson_64_augmented_tridiminished_icosahedron_verts[3];
#declare P2 = Johnson_64_augmented_tridiminished_icosahedron_verts[7];
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
 #declare Johnson_64_augmented_tridiminished_icosahedron_verts[Num] = vtransform(Johnson_64_augmented_tridiminished_icosahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_64_augmented_tridiminished_icosahedron_faces(Tex3, Tex5, OnPlane)
#local Johnson_64_augmented_tridiminished_icosahedron_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_64_augmented_tridiminished_icosahedron_verts[0],
  Johnson_64_augmented_tridiminished_icosahedron_verts[1],
  Johnson_64_augmented_tridiminished_icosahedron_verts[2],
  Johnson_64_augmented_tridiminished_icosahedron_verts[3],
  Johnson_64_augmented_tridiminished_icosahedron_verts[4],
  Johnson_64_augmented_tridiminished_icosahedron_verts[5],
  Johnson_64_augmented_tridiminished_icosahedron_verts[6],
  Johnson_64_augmented_tridiminished_icosahedron_verts[7],
  Johnson_64_augmented_tridiminished_icosahedron_verts[8],
  Johnson_64_augmented_tridiminished_icosahedron_verts[9]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  16,
  <6, 5, 8>, 0,
  <5, 4, 8>, 0,
  <8, 7, 6>, 0,
  <6, 2, 5>, 0,
  <9, 1, 0>, 0,
  <9, 0, 3>, 0,
  <9, 3, 1>, 0,
  <8, 4, 1>, 1,
  <8, 1, 3>, 1,
  <8, 3, 7>, 1,
  <6, 7, 3>, 1,
  <6, 3, 0>, 1,
  <6, 0, 2>, 1,
  <1, 4, 5>, 1,
  <1, 5, 2>, 1,
  <1, 2, 0>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_64_augmented_tridiminished_icosahedron_verts[7];
 #local P1 = Johnson_64_augmented_tridiminished_icosahedron_verts[8];
 #local P2 = Johnson_64_augmented_tridiminished_icosahedron_verts[3];
 #local P3 = Johnson_64_augmented_tridiminished_icosahedron_verts[1];
 #local P4 = Johnson_64_augmented_tridiminished_icosahedron_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_64_augmented_tridiminished_icosahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_64_augmented_tridiminished_icosahedron_obj }
#end
#end

#macro Johnson_64_augmented_tridiminished_icosahedron_faces2(OnPlane)
#local Johnson_64_augmented_tridiminished_icosahedron_obj = mesh2 {
 vertex_vectors {
  10,
  Johnson_64_augmented_tridiminished_icosahedron_verts[0],
  Johnson_64_augmented_tridiminished_icosahedron_verts[1],
  Johnson_64_augmented_tridiminished_icosahedron_verts[2],
  Johnson_64_augmented_tridiminished_icosahedron_verts[3],
  Johnson_64_augmented_tridiminished_icosahedron_verts[4],
  Johnson_64_augmented_tridiminished_icosahedron_verts[5],
  Johnson_64_augmented_tridiminished_icosahedron_verts[6],
  Johnson_64_augmented_tridiminished_icosahedron_verts[7],
  Johnson_64_augmented_tridiminished_icosahedron_verts[8],
  Johnson_64_augmented_tridiminished_icosahedron_verts[9]
 }
 face_indices {
  16,
  <6, 5, 8>,
  <5, 4, 8>,
  <8, 7, 6>,
  <6, 2, 5>,
  <9, 1, 0>,
  <9, 0, 3>,
  <9, 3, 1>,
  <8, 4, 1>,
  <8, 1, 3>,
  <8, 3, 7>,
  <6, 7, 3>,
  <6, 3, 0>,
  <6, 0, 2>,
  <1, 4, 5>,
  <1, 5, 2>,
  <1, 2, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_64_augmented_tridiminished_icosahedron_verts[7];
 #local P1 = Johnson_64_augmented_tridiminished_icosahedron_verts[8];
 #local P2 = Johnson_64_augmented_tridiminished_icosahedron_verts[3];
 #local P3 = Johnson_64_augmented_tridiminished_icosahedron_verts[1];
 #local P4 = Johnson_64_augmented_tridiminished_icosahedron_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_64_augmented_tridiminished_icosahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_64_augmented_tridiminished_icosahedron_obj }
#end
#end

#macro Johnson_64_augmented_tridiminished_icosahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[0], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[1], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[2], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[3], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[4], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[5], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[6], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[7], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[8], RadVer }
  sphere { Johnson_64_augmented_tridiminished_icosahedron_verts[9], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[6], Johnson_64_augmented_tridiminished_icosahedron_verts[5], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[5], Johnson_64_augmented_tridiminished_icosahedron_verts[8], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[8], Johnson_64_augmented_tridiminished_icosahedron_verts[6], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[5], Johnson_64_augmented_tridiminished_icosahedron_verts[4], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[4], Johnson_64_augmented_tridiminished_icosahedron_verts[8], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[8], Johnson_64_augmented_tridiminished_icosahedron_verts[7], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[7], Johnson_64_augmented_tridiminished_icosahedron_verts[6], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[6], Johnson_64_augmented_tridiminished_icosahedron_verts[2], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[2], Johnson_64_augmented_tridiminished_icosahedron_verts[5], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[9], Johnson_64_augmented_tridiminished_icosahedron_verts[1], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[1], Johnson_64_augmented_tridiminished_icosahedron_verts[0], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[0], Johnson_64_augmented_tridiminished_icosahedron_verts[9], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[0], Johnson_64_augmented_tridiminished_icosahedron_verts[3], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[3], Johnson_64_augmented_tridiminished_icosahedron_verts[9], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[3], Johnson_64_augmented_tridiminished_icosahedron_verts[1], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[4], Johnson_64_augmented_tridiminished_icosahedron_verts[1], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[3], Johnson_64_augmented_tridiminished_icosahedron_verts[7], RadEdg }
  cylinder { Johnson_64_augmented_tridiminished_icosahedron_verts[0], Johnson_64_augmented_tridiminished_icosahedron_verts[2], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_64_augmented_tridiminished_icosahedron_verts[7];
 #local P1 = Johnson_64_augmented_tridiminished_icosahedron_verts[8];
 #local P2 = Johnson_64_augmented_tridiminished_icosahedron_verts[3];
 #local P3 = Johnson_64_augmented_tridiminished_icosahedron_verts[1];
 #local P4 = Johnson_64_augmented_tridiminished_icosahedron_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
