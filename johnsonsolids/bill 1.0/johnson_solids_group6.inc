/* -------------------
johnson_solids_group6.inc

Modified Archimedean solids

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Johnson_65_augmented_truncated_tetrahedron (15 vertices)
  Johnson_66_augmented_truncated_cube (28 vertices)
  Johnson_67_biaugmented_truncated_cube (32 vertices)
  Johnson_68_augmented_truncated_dodecahedron (65 vertices)
  Johnson_69_parabiaugmented_truncated_dodecahedron (70 vertices)
  Johnson_70_metabiaugmented_truncated_dodecahedron (70 vertices)
  Johnson_71_triaugmented_truncated_dodecahedron (75 vertices)
  Johnson_72_gyrate_rhombicosidodecahedron (60 vertices)
  Johnson_73_parabigyrate_rhombicosidodecahedron (60 vertices)
  Johnson_74_metabigyrate_rhombicosidodecahedron (60 vertices)
  Johnson_75_trigyrate_rhombicosidodecahedron (60 vertices)
  Johnson_76_diminished_rhombicosidodecahedron (55 vertices)
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron (55 vertices)
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron (55 vertices)
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron (55 vertices)
  Johnson_80_parabidiminished_rhombicosidodecahedron (50 vertices)
  Johnson_81_metabidiminished_rhombicosidodecahedron (50 vertices)
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron (50 vertices)
  Johnson_83_tridiminished_rhombicosidodecahedron (45 vertices)

-------------------- */

#include "transforms.inc"

#declare Johnson_65_augmented_truncated_tetrahedron_verts = array[15]
{
<-0.914030, 0.409064, -0.602734>,
<-0.830829, 0.815648, 0.102539>,
<-0.699591, -0.379344, -0.648261>,
<-0.533188, 0.433825, 0.762285>,
<-0.401951, -0.761167, 0.011485>,
<-0.338469, 0.986004, -0.528495>,
<-0.318749, -0.354582, 0.716757>,
<0.090409, -0.590810, -0.619549>,
<0.251663, -0.893891, 0.485632>,
<0.256812, 0.222359, 0.790997>,
<0.451531, 0.774538, -0.499782>,
<0.665970, -0.013869, -0.545309>,
<0.744023, -0.723534, -0.145401>,
<0.749172, 0.392715, 0.159963>,
<0.827225, -0.316950, 0.559871>,
}
#declare P0 = Johnson_65_augmented_truncated_tetrahedron_verts[8];
#declare P1 = Johnson_65_augmented_truncated_tetrahedron_verts[12];
#declare P2 = Johnson_65_augmented_truncated_tetrahedron_verts[14];
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
 #declare Johnson_65_augmented_truncated_tetrahedron_verts[Num] = vtransform(Johnson_65_augmented_truncated_tetrahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_65_augmented_truncated_tetrahedron_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_65_augmented_truncated_tetrahedron_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_65_augmented_truncated_tetrahedron_verts[0],
  Johnson_65_augmented_truncated_tetrahedron_verts[1],
  Johnson_65_augmented_truncated_tetrahedron_verts[2],
  Johnson_65_augmented_truncated_tetrahedron_verts[3],
  Johnson_65_augmented_truncated_tetrahedron_verts[4],
  Johnson_65_augmented_truncated_tetrahedron_verts[5],
  Johnson_65_augmented_truncated_tetrahedron_verts[6],
  Johnson_65_augmented_truncated_tetrahedron_verts[7],
  Johnson_65_augmented_truncated_tetrahedron_verts[8],
  Johnson_65_augmented_truncated_tetrahedron_verts[9],
  Johnson_65_augmented_truncated_tetrahedron_verts[10],
  Johnson_65_augmented_truncated_tetrahedron_verts[11],
  Johnson_65_augmented_truncated_tetrahedron_verts[12],
  Johnson_65_augmented_truncated_tetrahedron_verts[13],
  Johnson_65_augmented_truncated_tetrahedron_verts[14]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  26,
  <12, 7, 11>, 0,
  <10, 13, 11>, 0,
  <14, 13, 9>, 0,
  <9, 3, 6>, 0,
  <0, 1, 5>, 0,
  <4, 2, 7>, 0,
  <6, 4, 8>, 0,
  <14, 8, 12>, 0,
  <12, 8, 4>, 1,
  <12, 4, 7>, 1,
  <13, 14, 12>, 1,
  <13, 12, 11>, 1,
  <14, 9, 6>, 1,
  <14, 6, 8>, 1,
  <11, 7, 2>, 2,
  <11, 2, 0>, 2,
  <11, 0, 5>, 2,
  <11, 5, 10>, 2,
  <13, 10, 5>, 2,
  <13, 5, 1>, 2,
  <13, 1, 3>, 2,
  <13, 3, 9>, 2,
  <3, 1, 0>, 2,
  <3, 0, 2>, 2,
  <3, 2, 4>, 2,
  <3, 4, 6>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_65_augmented_truncated_tetrahedron_verts[8];
 #local P1 = Johnson_65_augmented_truncated_tetrahedron_verts[12];
 #local P2 = Johnson_65_augmented_truncated_tetrahedron_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_65_augmented_truncated_tetrahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_65_augmented_truncated_tetrahedron_obj }
#end
#end

#macro Johnson_65_augmented_truncated_tetrahedron_faces2(OnPlane)
#local Johnson_65_augmented_truncated_tetrahedron_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_65_augmented_truncated_tetrahedron_verts[0],
  Johnson_65_augmented_truncated_tetrahedron_verts[1],
  Johnson_65_augmented_truncated_tetrahedron_verts[2],
  Johnson_65_augmented_truncated_tetrahedron_verts[3],
  Johnson_65_augmented_truncated_tetrahedron_verts[4],
  Johnson_65_augmented_truncated_tetrahedron_verts[5],
  Johnson_65_augmented_truncated_tetrahedron_verts[6],
  Johnson_65_augmented_truncated_tetrahedron_verts[7],
  Johnson_65_augmented_truncated_tetrahedron_verts[8],
  Johnson_65_augmented_truncated_tetrahedron_verts[9],
  Johnson_65_augmented_truncated_tetrahedron_verts[10],
  Johnson_65_augmented_truncated_tetrahedron_verts[11],
  Johnson_65_augmented_truncated_tetrahedron_verts[12],
  Johnson_65_augmented_truncated_tetrahedron_verts[13],
  Johnson_65_augmented_truncated_tetrahedron_verts[14]
 }
 face_indices {
  26,
  <12, 7, 11>,
  <10, 13, 11>,
  <14, 13, 9>,
  <9, 3, 6>,
  <0, 1, 5>,
  <4, 2, 7>,
  <6, 4, 8>,
  <14, 8, 12>,
  <12, 8, 4>,
  <12, 4, 7>,
  <13, 14, 12>,
  <13, 12, 11>,
  <14, 9, 6>,
  <14, 6, 8>,
  <11, 7, 2>,
  <11, 2, 0>,
  <11, 0, 5>,
  <11, 5, 10>,
  <13, 10, 5>,
  <13, 5, 1>,
  <13, 1, 3>,
  <13, 3, 9>,
  <3, 1, 0>,
  <3, 0, 2>,
  <3, 2, 4>,
  <3, 4, 6>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_65_augmented_truncated_tetrahedron_verts[8];
 #local P1 = Johnson_65_augmented_truncated_tetrahedron_verts[12];
 #local P2 = Johnson_65_augmented_truncated_tetrahedron_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_65_augmented_truncated_tetrahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_65_augmented_truncated_tetrahedron_obj }
#end
#end

#macro Johnson_65_augmented_truncated_tetrahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[0], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[1], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[2], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[3], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[4], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[5], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[6], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[7], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[8], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[9], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[10], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[11], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[12], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[13], RadVer }
  sphere { Johnson_65_augmented_truncated_tetrahedron_verts[14], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[12], Johnson_65_augmented_truncated_tetrahedron_verts[7], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[7], Johnson_65_augmented_truncated_tetrahedron_verts[11], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[11], Johnson_65_augmented_truncated_tetrahedron_verts[12], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[10], Johnson_65_augmented_truncated_tetrahedron_verts[13], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[13], Johnson_65_augmented_truncated_tetrahedron_verts[11], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[11], Johnson_65_augmented_truncated_tetrahedron_verts[10], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[14], Johnson_65_augmented_truncated_tetrahedron_verts[13], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[13], Johnson_65_augmented_truncated_tetrahedron_verts[9], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[9], Johnson_65_augmented_truncated_tetrahedron_verts[14], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[9], Johnson_65_augmented_truncated_tetrahedron_verts[3], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[3], Johnson_65_augmented_truncated_tetrahedron_verts[6], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[6], Johnson_65_augmented_truncated_tetrahedron_verts[9], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[0], Johnson_65_augmented_truncated_tetrahedron_verts[1], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[1], Johnson_65_augmented_truncated_tetrahedron_verts[5], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[5], Johnson_65_augmented_truncated_tetrahedron_verts[0], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[4], Johnson_65_augmented_truncated_tetrahedron_verts[2], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[2], Johnson_65_augmented_truncated_tetrahedron_verts[7], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[7], Johnson_65_augmented_truncated_tetrahedron_verts[4], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[6], Johnson_65_augmented_truncated_tetrahedron_verts[4], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[4], Johnson_65_augmented_truncated_tetrahedron_verts[8], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[8], Johnson_65_augmented_truncated_tetrahedron_verts[6], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[14], Johnson_65_augmented_truncated_tetrahedron_verts[8], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[8], Johnson_65_augmented_truncated_tetrahedron_verts[12], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[12], Johnson_65_augmented_truncated_tetrahedron_verts[14], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[2], Johnson_65_augmented_truncated_tetrahedron_verts[0], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[5], Johnson_65_augmented_truncated_tetrahedron_verts[10], RadEdg }
  cylinder { Johnson_65_augmented_truncated_tetrahedron_verts[1], Johnson_65_augmented_truncated_tetrahedron_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_65_augmented_truncated_tetrahedron_verts[8];
 #local P1 = Johnson_65_augmented_truncated_tetrahedron_verts[12];
 #local P2 = Johnson_65_augmented_truncated_tetrahedron_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_66_augmented_truncated_cube_verts = array[28]
{
<-0.935384, 0.507278, -0.272116>,
<-0.915801, 0.536228, 0.283002>,
<-0.882043, 0.099694, -0.646826>,
<-0.834764, 0.169584, 0.693348>,
<-0.787023, -0.447768, -0.621628>,
<-0.739744, -0.377878, 0.718546>,
<-0.705986, -0.814411, -0.211282>,
<-0.686402, -0.785462, 0.343836>,
<-0.561956, 0.553237, -0.681771>,
<-0.514677, 0.623127, 0.658404>,
<-0.332557, -0.768453, -0.620937>,
<-0.285278, -0.698562, 0.719237>,
<-0.014265, 0.647182, -0.705992>,
<0.033015, 0.717073, 0.634183>,
<0.215134, -0.674508, -0.645158>,
<0.262413, -0.604617, 0.695016>,
<0.386859, 0.734081, -0.330591>,
<0.406443, 0.763031, 0.224528>,
<0.440201, 0.326497, -0.705301>,
<0.487480, 0.396388, 0.634874>,
<0.535221, -0.220964, -0.680103>,
<0.582500, -0.151074, 0.660072>,
<0.616258, -0.587608, -0.269757>,
<0.635842, -0.558659, 0.285361>
<0.831438, 0.541255, -0.057559>,
<0.884779, 0.133670, -0.432269>,
<0.912475, 0.174611, 0.352787>,
<0.965816, -0.232973, -0.021924>,
}
#declare P0 = Johnson_66_augmented_truncated_cube_verts[4];
#declare P1 = Johnson_66_augmented_truncated_cube_verts[6];
#declare P2 = Johnson_66_augmented_truncated_cube_verts[7];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 28)
 #declare Johnson_66_augmented_truncated_cube_verts[Num] = vtransform(Johnson_66_augmented_truncated_cube_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_66_augmented_truncated_cube_faces(Tex3, Tex4, Tex8, OnPlane)
#local Johnson_66_augmented_truncated_cube_obj = mesh2 {
 vertex_vectors {
  28,
  Johnson_66_augmented_truncated_cube_verts[0],
  Johnson_66_augmented_truncated_cube_verts[1],
  Johnson_66_augmented_truncated_cube_verts[2],
  Johnson_66_augmented_truncated_cube_verts[3],
  Johnson_66_augmented_truncated_cube_verts[4],
  Johnson_66_augmented_truncated_cube_verts[5],
  Johnson_66_augmented_truncated_cube_verts[6],
  Johnson_66_augmented_truncated_cube_verts[7],
  Johnson_66_augmented_truncated_cube_verts[8],
  Johnson_66_augmented_truncated_cube_verts[9],
  Johnson_66_augmented_truncated_cube_verts[10],
  Johnson_66_augmented_truncated_cube_verts[11],
  Johnson_66_augmented_truncated_cube_verts[12],
  Johnson_66_augmented_truncated_cube_verts[13],
  Johnson_66_augmented_truncated_cube_verts[14],
  Johnson_66_augmented_truncated_cube_verts[15],
  Johnson_66_augmented_truncated_cube_verts[16],
  Johnson_66_augmented_truncated_cube_verts[17],
  Johnson_66_augmented_truncated_cube_verts[18],
  Johnson_66_augmented_truncated_cube_verts[19],
  Johnson_66_augmented_truncated_cube_verts[20],
  Johnson_66_augmented_truncated_cube_verts[21],
  Johnson_66_augmented_truncated_cube_verts[22],
  Johnson_66_augmented_truncated_cube_verts[23],
  Johnson_66_augmented_truncated_cube_verts[24],
  Johnson_66_augmented_truncated_cube_verts[25],
  Johnson_66_augmented_truncated_cube_verts[26],
  Johnson_66_augmented_truncated_cube_verts[27]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex8 }
 }
 face_indices {
  52,
  <24, 16, 17>, 0,
  <26, 19, 21>, 0,
  <27, 23, 22>, 0,
  <25, 20, 18>, 0,
  <21, 15, 23>, 0,
  <5, 7, 11>, 0,
  <17, 13, 19>, 0,
  <1, 3, 9>, 0,
  <18, 12, 16>, 0,
  <2, 0, 8>, 0,
  <22, 14, 20>, 0,
  <6, 4, 10>, 0,
  <25, 24, 26>, 1,
  <25, 26, 27>, 1,
  <24, 25, 18>, 1,
  <24, 18, 16>, 1,
  <26, 24, 17>, 1,
  <26, 17, 19>, 1,
  <27, 26, 21>, 1,
  <27, 21, 23>, 1,
  <25, 27, 22>, 1,
  <25, 22, 20>, 1,
  <23, 15, 11>, 2,
  <23, 11, 7>, 2,
  <23, 7, 6>, 2,
  <23, 6, 10>, 2,
  <23, 10, 14>, 2,
  <23, 14, 22>, 2,
  <20, 14, 10>, 2,
  <20, 10, 4>, 2,
  <20, 4, 2>, 2,
  <20, 2, 8>, 2,
  <20, 8, 12>, 2,
  <20, 12, 18>, 2,
  <16, 12, 8>, 2,
  <16, 8, 0>, 2,
  <16, 0, 1>, 2,
  <16, 1, 9>, 2,
  <16, 9, 13>, 2,
  <16, 13, 17>, 2,
  <19, 13, 9>, 2,
  <19, 9, 3>, 2,
  <19, 3, 5>, 2,
  <19, 5, 11>, 2,
  <19, 11, 15>, 2,
  <19, 15, 21>, 2,
  <4, 6, 7>, 2,
  <4, 7, 5>, 2,
  <4, 5, 3>, 2,
  <4, 3, 1>, 2,
  <4, 1, 0>, 2,
  <4, 0, 2>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_66_augmented_truncated_cube_verts[4];
 #local P1 = Johnson_66_augmented_truncated_cube_verts[6];
 #local P2 = Johnson_66_augmented_truncated_cube_verts[7];
 #local P3 = Johnson_66_augmented_truncated_cube_verts[5];
 #local P4 = Johnson_66_augmented_truncated_cube_verts[3];
 #local P5 = Johnson_66_augmented_truncated_cube_verts[1];
 #local P6 = Johnson_66_augmented_truncated_cube_verts[0];
 #local P7 = Johnson_66_augmented_truncated_cube_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_66_augmented_truncated_cube_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_66_augmented_truncated_cube_obj }
#end
#end

#macro Johnson_66_augmented_truncated_cube_faces2(OnPlane)
#local Johnson_66_augmented_truncated_cube_obj = mesh2 {
 vertex_vectors {
  28,
  Johnson_66_augmented_truncated_cube_verts[0],
  Johnson_66_augmented_truncated_cube_verts[1],
  Johnson_66_augmented_truncated_cube_verts[2],
  Johnson_66_augmented_truncated_cube_verts[3],
  Johnson_66_augmented_truncated_cube_verts[4],
  Johnson_66_augmented_truncated_cube_verts[5],
  Johnson_66_augmented_truncated_cube_verts[6],
  Johnson_66_augmented_truncated_cube_verts[7],
  Johnson_66_augmented_truncated_cube_verts[8],
  Johnson_66_augmented_truncated_cube_verts[9],
  Johnson_66_augmented_truncated_cube_verts[10],
  Johnson_66_augmented_truncated_cube_verts[11],
  Johnson_66_augmented_truncated_cube_verts[12],
  Johnson_66_augmented_truncated_cube_verts[13],
  Johnson_66_augmented_truncated_cube_verts[14],
  Johnson_66_augmented_truncated_cube_verts[15],
  Johnson_66_augmented_truncated_cube_verts[16],
  Johnson_66_augmented_truncated_cube_verts[17],
  Johnson_66_augmented_truncated_cube_verts[18],
  Johnson_66_augmented_truncated_cube_verts[19],
  Johnson_66_augmented_truncated_cube_verts[20],
  Johnson_66_augmented_truncated_cube_verts[21],
  Johnson_66_augmented_truncated_cube_verts[22],
  Johnson_66_augmented_truncated_cube_verts[23],
  Johnson_66_augmented_truncated_cube_verts[24],
  Johnson_66_augmented_truncated_cube_verts[25],
  Johnson_66_augmented_truncated_cube_verts[26],
  Johnson_66_augmented_truncated_cube_verts[27]
 }
 face_indices {
  52,
  <24, 16, 17>,
  <26, 19, 21>,
  <27, 23, 22>,
  <25, 20, 18>,
  <21, 15, 23>,
  <5, 7, 11>,
  <17, 13, 19>,
  <1, 3, 9>,
  <18, 12, 16>,
  <2, 0, 8>,
  <22, 14, 20>,
  <6, 4, 10>,
  <25, 24, 26>,
  <25, 26, 27>,
  <24, 25, 18>,
  <24, 18, 16>,
  <26, 24, 17>,
  <26, 17, 19>,
  <27, 26, 21>,
  <27, 21, 23>,
  <25, 27, 22>,
  <25, 22, 20>,
  <23, 15, 11>,
  <23, 11, 7>,
  <23, 7, 6>,
  <23, 6, 10>,
  <23, 10, 14>,
  <23, 14, 22>,
  <20, 14, 10>,
  <20, 10, 4>,
  <20, 4, 2>,
  <20, 2, 8>,
  <20, 8, 12>,
  <20, 12, 18>,
  <16, 12, 8>,
  <16, 8, 0>,
  <16, 0, 1>,
  <16, 1, 9>,
  <16, 9, 13>,
  <16, 13, 17>,
  <19, 13, 9>,
  <19, 9, 3>,
  <19, 3, 5>,
  <19, 5, 11>,
  <19, 11, 15>,
  <19, 15, 21>,
  <4, 6, 7>,
  <4, 7, 5>,
  <4, 5, 3>,
  <4, 3, 1>,
  <4, 1, 0>,
  <4, 0, 2>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_66_augmented_truncated_cube_verts[4];
 #local P1 = Johnson_66_augmented_truncated_cube_verts[6];
 #local P2 = Johnson_66_augmented_truncated_cube_verts[7];
 #local P3 = Johnson_66_augmented_truncated_cube_verts[5];
 #local P4 = Johnson_66_augmented_truncated_cube_verts[3];
 #local P5 = Johnson_66_augmented_truncated_cube_verts[1];
 #local P6 = Johnson_66_augmented_truncated_cube_verts[0];
 #local P7 = Johnson_66_augmented_truncated_cube_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_66_augmented_truncated_cube_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_66_augmented_truncated_cube_obj }
#end
#end

#macro Johnson_66_augmented_truncated_cube_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_66_augmented_truncated_cube_verts[0], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[1], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[2], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[3], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[4], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[5], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[6], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[7], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[8], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[9], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[10], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[11], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[12], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[13], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[14], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[15], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[16], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[17], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[18], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[19], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[20], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[21], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[22], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[23], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[24], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[25], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[26], RadVer }
  sphere { Johnson_66_augmented_truncated_cube_verts[27], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_66_augmented_truncated_cube_verts[24], Johnson_66_augmented_truncated_cube_verts[16], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[16], Johnson_66_augmented_truncated_cube_verts[17], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[17], Johnson_66_augmented_truncated_cube_verts[24], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[26], Johnson_66_augmented_truncated_cube_verts[19], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[19], Johnson_66_augmented_truncated_cube_verts[21], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[21], Johnson_66_augmented_truncated_cube_verts[26], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[27], Johnson_66_augmented_truncated_cube_verts[23], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[23], Johnson_66_augmented_truncated_cube_verts[22], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[22], Johnson_66_augmented_truncated_cube_verts[27], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[25], Johnson_66_augmented_truncated_cube_verts[20], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[20], Johnson_66_augmented_truncated_cube_verts[18], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[18], Johnson_66_augmented_truncated_cube_verts[25], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[21], Johnson_66_augmented_truncated_cube_verts[15], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[15], Johnson_66_augmented_truncated_cube_verts[23], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[23], Johnson_66_augmented_truncated_cube_verts[21], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[5], Johnson_66_augmented_truncated_cube_verts[7], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[7], Johnson_66_augmented_truncated_cube_verts[11], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[11], Johnson_66_augmented_truncated_cube_verts[5], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[17], Johnson_66_augmented_truncated_cube_verts[13], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[13], Johnson_66_augmented_truncated_cube_verts[19], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[19], Johnson_66_augmented_truncated_cube_verts[17], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[1], Johnson_66_augmented_truncated_cube_verts[3], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[3], Johnson_66_augmented_truncated_cube_verts[9], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[9], Johnson_66_augmented_truncated_cube_verts[1], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[18], Johnson_66_augmented_truncated_cube_verts[12], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[12], Johnson_66_augmented_truncated_cube_verts[16], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[16], Johnson_66_augmented_truncated_cube_verts[18], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[2], Johnson_66_augmented_truncated_cube_verts[0], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[0], Johnson_66_augmented_truncated_cube_verts[8], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[8], Johnson_66_augmented_truncated_cube_verts[2], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[22], Johnson_66_augmented_truncated_cube_verts[14], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[14], Johnson_66_augmented_truncated_cube_verts[20], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[20], Johnson_66_augmented_truncated_cube_verts[22], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[6], Johnson_66_augmented_truncated_cube_verts[4], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[4], Johnson_66_augmented_truncated_cube_verts[10], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[10], Johnson_66_augmented_truncated_cube_verts[6], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[25], Johnson_66_augmented_truncated_cube_verts[24], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[24], Johnson_66_augmented_truncated_cube_verts[26], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[26], Johnson_66_augmented_truncated_cube_verts[27], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[27], Johnson_66_augmented_truncated_cube_verts[25], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[15], Johnson_66_augmented_truncated_cube_verts[11], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[7], Johnson_66_augmented_truncated_cube_verts[6], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[10], Johnson_66_augmented_truncated_cube_verts[14], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[4], Johnson_66_augmented_truncated_cube_verts[2], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[8], Johnson_66_augmented_truncated_cube_verts[12], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[0], Johnson_66_augmented_truncated_cube_verts[1], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[9], Johnson_66_augmented_truncated_cube_verts[13], RadEdg }
  cylinder { Johnson_66_augmented_truncated_cube_verts[3], Johnson_66_augmented_truncated_cube_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_66_augmented_truncated_cube_verts[4];
 #local P1 = Johnson_66_augmented_truncated_cube_verts[6];
 #local P2 = Johnson_66_augmented_truncated_cube_verts[7];
 #local P3 = Johnson_66_augmented_truncated_cube_verts[5];
 #local P4 = Johnson_66_augmented_truncated_cube_verts[3];
 #local P5 = Johnson_66_augmented_truncated_cube_verts[1];
 #local P6 = Johnson_66_augmented_truncated_cube_verts[0];
 #local P7 = Johnson_66_augmented_truncated_cube_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_67_biaugmented_truncated_cube_verts = array[32]
{
<-0.854680, -0.304544, 0.321795>,
<-0.813538, 0.214997, 0.467663>,
<-0.753988, -0.584165, -0.130495>,
<-0.662946, -0.809677, 0.352981>,
<-0.654663, 0.670118, 0.221662>,
<-0.570447, -0.460068, -0.624262>,
<-0.567052, -0.168344, 0.759532>,
<-0.471123, 0.794216, -0.272106>,
<-0.411573, -0.004947, -0.870263>,
<-0.375319, -0.673477, 0.790718>,
<-0.370431, 0.514594, -0.724396>,
<-0.323962, -0.843410, -0.332393>,
<-0.232920, -1.068921, 0.151083>,
<-0.183495, 0.930415, 0.165631>,
<-0.059594, -0.255350, 0.926295>,
<-0.054707, 0.932721, -0.588818>,
<0.054707, -0.932721, 0.588819>,
<0.059595, 0.255350, -0.926294>,
<0.183496, -0.930415, -0.165630>,
<0.232920, 1.068921, -0.151082>,
<0.323962, 0.843410, 0.332394>,
<0.370432, -0.514594, 0.724397>,
<0.375320, 0.673477, -0.790717>,
<0.411574, 0.004947, 0.870264>
<0.471123, -0.794216, 0.272106>,
<0.567053, 0.168344, -0.759531>,
<0.570448, 0.460068, 0.624263>,
<0.654664, -0.670118, -0.221661>,
<0.662947, 0.809677, -0.352980>,
<0.753989, 0.584165, 0.130496>,
<0.813538, -0.214997, -0.467662>,
<0.854680, 0.304544, -0.321795>,
}
#declare P0 = Johnson_67_biaugmented_truncated_cube_verts[8];
#declare P1 = Johnson_67_biaugmented_truncated_cube_verts[5];
#declare P2 = Johnson_67_biaugmented_truncated_cube_verts[2];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 32)
 #declare Johnson_67_biaugmented_truncated_cube_verts[Num] = vtransform(Johnson_67_biaugmented_truncated_cube_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_67_biaugmented_truncated_cube_faces(Tex3, Tex4, Tex8, OnPlane)
#local Johnson_67_biaugmented_truncated_cube_obj = mesh2 {
 vertex_vectors {
  32,
  Johnson_67_biaugmented_truncated_cube_verts[0],
  Johnson_67_biaugmented_truncated_cube_verts[1],
  Johnson_67_biaugmented_truncated_cube_verts[2],
  Johnson_67_biaugmented_truncated_cube_verts[3],
  Johnson_67_biaugmented_truncated_cube_verts[4],
  Johnson_67_biaugmented_truncated_cube_verts[5],
  Johnson_67_biaugmented_truncated_cube_verts[6],
  Johnson_67_biaugmented_truncated_cube_verts[7],
  Johnson_67_biaugmented_truncated_cube_verts[8],
  Johnson_67_biaugmented_truncated_cube_verts[9],
  Johnson_67_biaugmented_truncated_cube_verts[10],
  Johnson_67_biaugmented_truncated_cube_verts[11],
  Johnson_67_biaugmented_truncated_cube_verts[12],
  Johnson_67_biaugmented_truncated_cube_verts[13],
  Johnson_67_biaugmented_truncated_cube_verts[14],
  Johnson_67_biaugmented_truncated_cube_verts[15],
  Johnson_67_biaugmented_truncated_cube_verts[16],
  Johnson_67_biaugmented_truncated_cube_verts[17],
  Johnson_67_biaugmented_truncated_cube_verts[18],
  Johnson_67_biaugmented_truncated_cube_verts[19],
  Johnson_67_biaugmented_truncated_cube_verts[20],
  Johnson_67_biaugmented_truncated_cube_verts[21],
  Johnson_67_biaugmented_truncated_cube_verts[22],
  Johnson_67_biaugmented_truncated_cube_verts[23],
  Johnson_67_biaugmented_truncated_cube_verts[24],
  Johnson_67_biaugmented_truncated_cube_verts[25],
  Johnson_67_biaugmented_truncated_cube_verts[26],
  Johnson_67_biaugmented_truncated_cube_verts[27],
  Johnson_67_biaugmented_truncated_cube_verts[28],
  Johnson_67_biaugmented_truncated_cube_verts[29],
  Johnson_67_biaugmented_truncated_cube_verts[30],
  Johnson_67_biaugmented_truncated_cube_verts[31]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex8 }
 }
 face_indices {
  60,
  <22, 25, 17>, 0,
  <15, 10, 7>, 0,
  <19, 13, 20>, 0,
  <28, 29, 31>, 0,
  <9, 14, 6>, 0,
  <3, 0, 2>, 0,
  <12, 11, 18>, 0,
  <16, 24, 21>, 0,
  <7, 4, 13>, 0,
  <0, 6, 1>, 0,
  <17, 8, 10>, 0,
  <11, 2, 5>, 0,
  <31, 30, 25>, 0,
  <24, 18, 27>, 0,
  <20, 26, 29>, 0,
  <14, 21, 23>, 0,
  <28, 22, 15>, 1,
  <28, 15, 19>, 1,
  <22, 28, 31>, 1,
  <22, 31, 25>, 1,
  <15, 22, 17>, 1,
  <15, 17, 10>, 1,
  <19, 15, 7>, 1,
  <19, 7, 13>, 1,
  <28, 19, 20>, 1,
  <28, 20, 29>, 1,
  <16, 9, 3>, 1,
  <16, 3, 12>, 1,
  <9, 16, 21>, 1,
  <9, 21, 14>, 1,
  <3, 9, 6>, 1,
  <3, 6, 0>, 1,
  <12, 3, 2>, 1,
  <12, 2, 11>, 1,
  <16, 12, 18>, 1,
  <16, 18, 24>, 1,
  <13, 4, 1>, 2,
  <13, 1, 6>, 2,
  <13, 6, 14>, 2,
  <13, 14, 23>, 2,
  <13, 23, 26>, 2,
  <13, 26, 20>, 2,
  <29, 26, 23>, 2,
  <29, 23, 21>, 2,
  <29, 21, 24>, 2,
  <29, 24, 27>, 2,
  <29, 27, 30>, 2,
  <29, 30, 31>, 2,
  <25, 30, 27>, 2,
  <25, 27, 18>, 2,
  <25, 18, 11>, 2,
  <25, 11, 5>, 2,
  <25, 5, 8>, 2,
  <25, 8, 17>, 2,
  <10, 8, 5>, 2,
  <10, 5, 2>, 2,
  <10, 2, 0>, 2,
  <10, 0, 1>, 2,
  <10, 1, 4>, 2,
  <10, 4, 7>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_67_biaugmented_truncated_cube_verts[8];
 #local P1 = Johnson_67_biaugmented_truncated_cube_verts[5];
 #local P2 = Johnson_67_biaugmented_truncated_cube_verts[2];
 #local P3 = Johnson_67_biaugmented_truncated_cube_verts[0];
 #local P4 = Johnson_67_biaugmented_truncated_cube_verts[1];
 #local P5 = Johnson_67_biaugmented_truncated_cube_verts[4];
 #local P6 = Johnson_67_biaugmented_truncated_cube_verts[7];
 #local P7 = Johnson_67_biaugmented_truncated_cube_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_67_biaugmented_truncated_cube_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_67_biaugmented_truncated_cube_obj }
#end
#end

#macro Johnson_67_biaugmented_truncated_cube_faces2(OnPlane)
#local Johnson_67_biaugmented_truncated_cube_obj = mesh2 {
 vertex_vectors {
  32,
  Johnson_67_biaugmented_truncated_cube_verts[0],
  Johnson_67_biaugmented_truncated_cube_verts[1],
  Johnson_67_biaugmented_truncated_cube_verts[2],
  Johnson_67_biaugmented_truncated_cube_verts[3],
  Johnson_67_biaugmented_truncated_cube_verts[4],
  Johnson_67_biaugmented_truncated_cube_verts[5],
  Johnson_67_biaugmented_truncated_cube_verts[6],
  Johnson_67_biaugmented_truncated_cube_verts[7],
  Johnson_67_biaugmented_truncated_cube_verts[8],
  Johnson_67_biaugmented_truncated_cube_verts[9],
  Johnson_67_biaugmented_truncated_cube_verts[10],
  Johnson_67_biaugmented_truncated_cube_verts[11],
  Johnson_67_biaugmented_truncated_cube_verts[12],
  Johnson_67_biaugmented_truncated_cube_verts[13],
  Johnson_67_biaugmented_truncated_cube_verts[14],
  Johnson_67_biaugmented_truncated_cube_verts[15],
  Johnson_67_biaugmented_truncated_cube_verts[16],
  Johnson_67_biaugmented_truncated_cube_verts[17],
  Johnson_67_biaugmented_truncated_cube_verts[18],
  Johnson_67_biaugmented_truncated_cube_verts[19],
  Johnson_67_biaugmented_truncated_cube_verts[20],
  Johnson_67_biaugmented_truncated_cube_verts[21],
  Johnson_67_biaugmented_truncated_cube_verts[22],
  Johnson_67_biaugmented_truncated_cube_verts[23],
  Johnson_67_biaugmented_truncated_cube_verts[24],
  Johnson_67_biaugmented_truncated_cube_verts[25],
  Johnson_67_biaugmented_truncated_cube_verts[26],
  Johnson_67_biaugmented_truncated_cube_verts[27],
  Johnson_67_biaugmented_truncated_cube_verts[28],
  Johnson_67_biaugmented_truncated_cube_verts[29],
  Johnson_67_biaugmented_truncated_cube_verts[30],
  Johnson_67_biaugmented_truncated_cube_verts[31]
 }
 face_indices {
  60,
  <22, 25, 17>,
  <15, 10, 7>,
  <19, 13, 20>,
  <28, 29, 31>,
  <9, 14, 6>,
  <3, 0, 2>,
  <12, 11, 18>,
  <16, 24, 21>,
  <7, 4, 13>,
  <0, 6, 1>,
  <17, 8, 10>,
  <11, 2, 5>,
  <31, 30, 25>,
  <24, 18, 27>,
  <20, 26, 29>,
  <14, 21, 23>,
  <28, 22, 15>,
  <28, 15, 19>,
  <22, 28, 31>,
  <22, 31, 25>,
  <15, 22, 17>,
  <15, 17, 10>,
  <19, 15, 7>,
  <19, 7, 13>,
  <28, 19, 20>,
  <28, 20, 29>,
  <16, 9, 3>,
  <16, 3, 12>,
  <9, 16, 21>,
  <9, 21, 14>,
  <3, 9, 6>,
  <3, 6, 0>,
  <12, 3, 2>,
  <12, 2, 11>,
  <16, 12, 18>,
  <16, 18, 24>,
  <13, 4, 1>,
  <13, 1, 6>,
  <13, 6, 14>,
  <13, 14, 23>,
  <13, 23, 26>,
  <13, 26, 20>,
  <29, 26, 23>,
  <29, 23, 21>,
  <29, 21, 24>,
  <29, 24, 27>,
  <29, 27, 30>,
  <29, 30, 31>,
  <25, 30, 27>,
  <25, 27, 18>,
  <25, 18, 11>,
  <25, 11, 5>,
  <25, 5, 8>,
  <25, 8, 17>,
  <10, 8, 5>,
  <10, 5, 2>,
  <10, 2, 0>,
  <10, 0, 1>,
  <10, 1, 4>,
  <10, 4, 7>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_67_biaugmented_truncated_cube_verts[8];
 #local P1 = Johnson_67_biaugmented_truncated_cube_verts[5];
 #local P2 = Johnson_67_biaugmented_truncated_cube_verts[2];
 #local P3 = Johnson_67_biaugmented_truncated_cube_verts[0];
 #local P4 = Johnson_67_biaugmented_truncated_cube_verts[1];
 #local P5 = Johnson_67_biaugmented_truncated_cube_verts[4];
 #local P6 = Johnson_67_biaugmented_truncated_cube_verts[7];
 #local P7 = Johnson_67_biaugmented_truncated_cube_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_67_biaugmented_truncated_cube_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_67_biaugmented_truncated_cube_obj }
#end
#end

#macro Johnson_67_biaugmented_truncated_cube_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_67_biaugmented_truncated_cube_verts[0], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[1], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[2], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[3], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[4], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[5], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[6], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[7], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[8], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[9], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[10], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[11], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[12], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[13], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[14], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[15], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[16], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[17], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[18], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[19], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[20], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[21], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[22], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[23], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[24], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[25], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[26], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[27], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[28], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[29], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[30], RadVer }
  sphere { Johnson_67_biaugmented_truncated_cube_verts[31], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[22], Johnson_67_biaugmented_truncated_cube_verts[25], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[25], Johnson_67_biaugmented_truncated_cube_verts[17], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[17], Johnson_67_biaugmented_truncated_cube_verts[22], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[15], Johnson_67_biaugmented_truncated_cube_verts[10], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[10], Johnson_67_biaugmented_truncated_cube_verts[7], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[7], Johnson_67_biaugmented_truncated_cube_verts[15], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[19], Johnson_67_biaugmented_truncated_cube_verts[13], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[13], Johnson_67_biaugmented_truncated_cube_verts[20], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[20], Johnson_67_biaugmented_truncated_cube_verts[19], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[28], Johnson_67_biaugmented_truncated_cube_verts[29], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[29], Johnson_67_biaugmented_truncated_cube_verts[31], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[31], Johnson_67_biaugmented_truncated_cube_verts[28], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[9], Johnson_67_biaugmented_truncated_cube_verts[14], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[14], Johnson_67_biaugmented_truncated_cube_verts[6], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[6], Johnson_67_biaugmented_truncated_cube_verts[9], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[3], Johnson_67_biaugmented_truncated_cube_verts[0], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[0], Johnson_67_biaugmented_truncated_cube_verts[2], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[2], Johnson_67_biaugmented_truncated_cube_verts[3], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[12], Johnson_67_biaugmented_truncated_cube_verts[11], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[11], Johnson_67_biaugmented_truncated_cube_verts[18], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[18], Johnson_67_biaugmented_truncated_cube_verts[12], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[16], Johnson_67_biaugmented_truncated_cube_verts[24], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[24], Johnson_67_biaugmented_truncated_cube_verts[21], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[21], Johnson_67_biaugmented_truncated_cube_verts[16], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[7], Johnson_67_biaugmented_truncated_cube_verts[4], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[4], Johnson_67_biaugmented_truncated_cube_verts[13], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[13], Johnson_67_biaugmented_truncated_cube_verts[7], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[0], Johnson_67_biaugmented_truncated_cube_verts[6], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[6], Johnson_67_biaugmented_truncated_cube_verts[1], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[1], Johnson_67_biaugmented_truncated_cube_verts[0], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[17], Johnson_67_biaugmented_truncated_cube_verts[8], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[8], Johnson_67_biaugmented_truncated_cube_verts[10], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[10], Johnson_67_biaugmented_truncated_cube_verts[17], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[11], Johnson_67_biaugmented_truncated_cube_verts[2], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[2], Johnson_67_biaugmented_truncated_cube_verts[5], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[5], Johnson_67_biaugmented_truncated_cube_verts[11], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[31], Johnson_67_biaugmented_truncated_cube_verts[30], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[30], Johnson_67_biaugmented_truncated_cube_verts[25], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[25], Johnson_67_biaugmented_truncated_cube_verts[31], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[24], Johnson_67_biaugmented_truncated_cube_verts[18], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[18], Johnson_67_biaugmented_truncated_cube_verts[27], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[27], Johnson_67_biaugmented_truncated_cube_verts[24], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[20], Johnson_67_biaugmented_truncated_cube_verts[26], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[26], Johnson_67_biaugmented_truncated_cube_verts[29], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[29], Johnson_67_biaugmented_truncated_cube_verts[20], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[14], Johnson_67_biaugmented_truncated_cube_verts[21], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[21], Johnson_67_biaugmented_truncated_cube_verts[23], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[23], Johnson_67_biaugmented_truncated_cube_verts[14], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[28], Johnson_67_biaugmented_truncated_cube_verts[22], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[22], Johnson_67_biaugmented_truncated_cube_verts[15], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[15], Johnson_67_biaugmented_truncated_cube_verts[19], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[19], Johnson_67_biaugmented_truncated_cube_verts[28], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[16], Johnson_67_biaugmented_truncated_cube_verts[9], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[9], Johnson_67_biaugmented_truncated_cube_verts[3], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[3], Johnson_67_biaugmented_truncated_cube_verts[12], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[12], Johnson_67_biaugmented_truncated_cube_verts[16], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[4], Johnson_67_biaugmented_truncated_cube_verts[1], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[23], Johnson_67_biaugmented_truncated_cube_verts[26], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[27], Johnson_67_biaugmented_truncated_cube_verts[30], RadEdg }
  cylinder { Johnson_67_biaugmented_truncated_cube_verts[5], Johnson_67_biaugmented_truncated_cube_verts[8], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_67_biaugmented_truncated_cube_verts[8];
 #local P1 = Johnson_67_biaugmented_truncated_cube_verts[5];
 #local P2 = Johnson_67_biaugmented_truncated_cube_verts[2];
 #local P3 = Johnson_67_biaugmented_truncated_cube_verts[0];
 #local P4 = Johnson_67_biaugmented_truncated_cube_verts[1];
 #local P5 = Johnson_67_biaugmented_truncated_cube_verts[4];
 #local P6 = Johnson_67_biaugmented_truncated_cube_verts[7];
 #local P7 = Johnson_67_biaugmented_truncated_cube_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_68_augmented_truncated_dodecahedron_verts = array[65]
{
<-1.053731, -0.062801, 0.140871>,
<-1.047729, -0.006643, -0.190675>,
<-0.967657, 0.064553, 0.440012>,
<-0.951944, 0.211579, -0.427988>,
<-0.942283, -0.266176, 0.384450>,
<-0.926570, -0.119150, -0.483549>,
<-0.822385, 0.326776, 0.592485>,
<-0.802963, 0.508510, -0.480421>,
<-0.755954, -0.539085, 0.447023>,
<-0.736532, -0.357350, -0.625883>,
<-0.673403, 0.623707, 0.540051>,
<-0.657690, 0.770733, -0.327948>,
<-0.577618, 0.841928, 0.302738>,
<-0.571617, 0.898087, -0.028808>,
<-0.565916, -0.777285, 0.304689>,
<-0.561955, 0.420332, 0.783630>,
<-0.550203, -0.630259, -0.563310>,
<-0.536531, 0.658225, -0.620822>,
<-0.479842, -0.649930, 0.603829>,
<-0.454419, -0.412037, -0.800623>,
<-0.444757, -0.889793, 0.011815>,
<-0.438755, -0.833633, -0.319731>,
<-0.311187, 0.991643, 0.162337>,
<-0.285843, 0.309485, 0.940436>
<-0.254418, 0.603538, -0.795562>,
<-0.219412, -0.556374, 0.794974>,
<-0.187987, -0.262321, -0.941024>,
<-0.162643, -0.944479, -0.162925>,
<-0.099515, 0.036577, 1.003008>,
<-0.074140, -0.294152, 0.947447>,
<-0.064380, 0.365339, -0.937896>,
<-0.039006, 0.034609, -0.993458>,
<0.024123, 1.015665, 0.172476>,
<0.049467, 0.333508, 0.950575>,
<0.080892, 0.627561, -0.785423>,
<0.115898, -0.532352, 0.805113>,
<0.147323, -0.238299, -0.930885>,
<0.172667, -0.920457, -0.152786>,
<0.300235, 0.904820, 0.329282>,
<0.306237, 0.960979, -0.002264>,
<0.315898, 0.483223, 0.810173>,
<0.341322, 0.721117, -0.594278>,
<0.398011, -0.587039, 0.630373>,
<0.411683, 0.701445, 0.572861>,
<0.423435, -0.349145, -0.774079>,
<0.427396, 0.848471, -0.295138>,
<0.433096, -0.826901, 0.038358>,
<0.439098, -0.770742, -0.293188>,
<0.519170, -0.699547, 0.337499>,
<0.534883, -0.552520, -0.530500>,
<0.598012, 0.428536, 0.635433>,
<0.617434, 0.610271, -0.437472>,
<0.664443, -0.437324, 0.489972>,
<0.683864, -0.255589, -0.582934>,
<0.721659, -0.657508, 0.072275>,
<0.727661, -0.601349, -0.259271>,
<0.788050, 0.190336, 0.493099>,
<0.803762, 0.337363, -0.374900>,
<0.813424, -0.140393, 0.437538>,
<0.829136, 0.006634, -0.430461>,
<0.866931, -0.395285, 0.224748>,
<0.876642, -0.304418, -0.311705>,
<0.909209, 0.077829, 0.200225>,
<0.915210, 0.133987, -0.131321>,
<0.962716, -0.177064, -0.012565>,
}
#declare P0 = Johnson_68_augmented_truncated_dodecahedron_verts[27];
#declare P1 = Johnson_68_augmented_truncated_dodecahedron_verts[37];
#declare P2 = Johnson_68_augmented_truncated_dodecahedron_verts[46];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 65)
 #declare Johnson_68_augmented_truncated_dodecahedron_verts[Num] = vtransform(Johnson_68_augmented_truncated_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_68_augmented_truncated_dodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_68_augmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  65,
  Johnson_68_augmented_truncated_dodecahedron_verts[0],
  Johnson_68_augmented_truncated_dodecahedron_verts[1],
  Johnson_68_augmented_truncated_dodecahedron_verts[2],
  Johnson_68_augmented_truncated_dodecahedron_verts[3],
  Johnson_68_augmented_truncated_dodecahedron_verts[4],
  Johnson_68_augmented_truncated_dodecahedron_verts[5],
  Johnson_68_augmented_truncated_dodecahedron_verts[6],
  Johnson_68_augmented_truncated_dodecahedron_verts[7],
  Johnson_68_augmented_truncated_dodecahedron_verts[8],
  Johnson_68_augmented_truncated_dodecahedron_verts[9],
  Johnson_68_augmented_truncated_dodecahedron_verts[10],
  Johnson_68_augmented_truncated_dodecahedron_verts[11],
  Johnson_68_augmented_truncated_dodecahedron_verts[12],
  Johnson_68_augmented_truncated_dodecahedron_verts[13],
  Johnson_68_augmented_truncated_dodecahedron_verts[14],
  Johnson_68_augmented_truncated_dodecahedron_verts[15],
  Johnson_68_augmented_truncated_dodecahedron_verts[16],
  Johnson_68_augmented_truncated_dodecahedron_verts[17],
  Johnson_68_augmented_truncated_dodecahedron_verts[18],
  Johnson_68_augmented_truncated_dodecahedron_verts[19],
  Johnson_68_augmented_truncated_dodecahedron_verts[20],
  Johnson_68_augmented_truncated_dodecahedron_verts[21],
  Johnson_68_augmented_truncated_dodecahedron_verts[22],
  Johnson_68_augmented_truncated_dodecahedron_verts[23],
  Johnson_68_augmented_truncated_dodecahedron_verts[24],
  Johnson_68_augmented_truncated_dodecahedron_verts[25],
  Johnson_68_augmented_truncated_dodecahedron_verts[26],
  Johnson_68_augmented_truncated_dodecahedron_verts[27],
  Johnson_68_augmented_truncated_dodecahedron_verts[28],
  Johnson_68_augmented_truncated_dodecahedron_verts[29],
  Johnson_68_augmented_truncated_dodecahedron_verts[30],
  Johnson_68_augmented_truncated_dodecahedron_verts[31],
  Johnson_68_augmented_truncated_dodecahedron_verts[32],
  Johnson_68_augmented_truncated_dodecahedron_verts[33],
  Johnson_68_augmented_truncated_dodecahedron_verts[34],
  Johnson_68_augmented_truncated_dodecahedron_verts[35],
  Johnson_68_augmented_truncated_dodecahedron_verts[36],
  Johnson_68_augmented_truncated_dodecahedron_verts[37],
  Johnson_68_augmented_truncated_dodecahedron_verts[38],
  Johnson_68_augmented_truncated_dodecahedron_verts[39],
  Johnson_68_augmented_truncated_dodecahedron_verts[40],
  Johnson_68_augmented_truncated_dodecahedron_verts[41],
  Johnson_68_augmented_truncated_dodecahedron_verts[42],
  Johnson_68_augmented_truncated_dodecahedron_verts[43],
  Johnson_68_augmented_truncated_dodecahedron_verts[44],
  Johnson_68_augmented_truncated_dodecahedron_verts[45],
  Johnson_68_augmented_truncated_dodecahedron_verts[46],
  Johnson_68_augmented_truncated_dodecahedron_verts[47],
  Johnson_68_augmented_truncated_dodecahedron_verts[48],
  Johnson_68_augmented_truncated_dodecahedron_verts[49],
  Johnson_68_augmented_truncated_dodecahedron_verts[50],
  Johnson_68_augmented_truncated_dodecahedron_verts[51],
  Johnson_68_augmented_truncated_dodecahedron_verts[52],
  Johnson_68_augmented_truncated_dodecahedron_verts[53],
  Johnson_68_augmented_truncated_dodecahedron_verts[54],
  Johnson_68_augmented_truncated_dodecahedron_verts[55],
  Johnson_68_augmented_truncated_dodecahedron_verts[56],
  Johnson_68_augmented_truncated_dodecahedron_verts[57],
  Johnson_68_augmented_truncated_dodecahedron_verts[58],
  Johnson_68_augmented_truncated_dodecahedron_verts[59],
  Johnson_68_augmented_truncated_dodecahedron_verts[60],
  Johnson_68_augmented_truncated_dodecahedron_verts[61],
  Johnson_68_augmented_truncated_dodecahedron_verts[62],
  Johnson_68_augmented_truncated_dodecahedron_verts[63],
  Johnson_68_augmented_truncated_dodecahedron_verts[64]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  126,
  <34, 30, 24>, 0,
  <45, 51, 41>, 0,
  <36, 26, 31>, 0,
  <53, 49, 44>, 0,
  <16, 9, 19>, 0,
  <27, 20, 21>, 0,
  <1, 3, 5>, 0,
  <4, 2, 0>, 0,
  <11, 17, 7>, 0,
  <12, 22, 13>, 0,
  <62, 56, 58>, 0,
  <59, 57, 63>, 0,
  <43, 40, 50>, 0,
  <39, 32, 38>, 0,
  <23, 28, 33>, 0,
  <10, 6, 15>, 0,
  <25, 35, 29>, 0,
  <8, 14, 18>, 0,
  <48, 52, 42>, 0,
  <47, 46, 37>, 0,
  <54, 48, 46>, 0,
  <55, 47, 49>, 0,
  <61, 53, 59>, 0,
  <62, 64, 63>, 0,
  <60, 58, 52>, 0,
  <54, 60, 52>, 1,
  <54, 52, 48>, 1,
  <55, 54, 46>, 1,
  <55, 46, 47>, 1,
  <61, 55, 49>, 1,
  <61, 49, 53>, 1,
  <64, 61, 59>, 1,
  <64, 59, 63>, 1,
  <60, 64, 62>, 1,
  <60, 62, 58>, 1,
  <60, 54, 55>, 2,
  <60, 55, 61>, 2,
  <60, 61, 64>, 2,
  <31, 26, 19>, 3,
  <31, 19, 9>, 3,
  <31, 9, 5>, 3,
  <31, 5, 3>, 3,
  <31, 3, 7>, 3,
  <31, 7, 17>, 3,
  <31, 17, 24>, 3,
  <31, 24, 30>, 3,
  <59, 53, 44>, 3,
  <59, 44, 36>, 3,
  <59, 36, 31>, 3,
  <59, 31, 30>, 3,
  <59, 30, 34>, 3,
  <59, 34, 41>, 3,
  <59, 41, 51>, 3,
  <59, 51, 57>, 3,
  <37, 27, 21>, 3,
  <37, 21, 16>, 3,
  <37, 16, 19>, 3,
  <37, 19, 26>, 3,
  <37, 26, 36>, 3,
  <37, 36, 44>, 3,
  <37, 44, 49>, 3,
  <37, 49, 47>, 3,
  <8, 4, 0>, 3,
  <8, 0, 1>, 3,
  <8, 1, 5>, 3,
  <8, 5, 9>, 3,
  <8, 9, 16>, 3,
  <8, 16, 21>, 3,
  <8, 21, 20>, 3,
  <8, 20, 14>, 3,
  <10, 12, 13>, 3,
  <10, 13, 11>, 3,
  <10, 11, 7>, 3,
  <10, 7, 3>, 3,
  <10, 3, 1>, 3,
  <10, 1, 0>, 3,
  <10, 0, 2>, 3,
  <10, 2, 6>, 3,
  <39, 45, 41>, 3,
  <39, 41, 34>, 3,
  <39, 34, 24>, 3,
  <39, 24, 17>, 3,
  <39, 17, 11>, 3,
  <39, 11, 13>, 3,
  <39, 13, 22>, 3,
  <39, 22, 32>, 3,
  <50, 40, 33>, 3,
  <50, 33, 28>, 3,
  <50, 28, 29>, 3,
  <50, 29, 35>, 3,
  <50, 35, 42>, 3,
  <50, 42, 52>, 3,
  <50, 52, 58>, 3,
  <50, 58, 56>, 3,
  <45, 39, 38>, 3,
  <45, 38, 43>, 3,
  <45, 43, 50>, 3,
  <45, 50, 56>, 3,
  <45, 56, 62>, 3,
  <45, 62, 63>, 3,
  <45, 63, 57>, 3,
  <45, 57, 51>, 3,
  <12, 10, 15>, 3,
  <12, 15, 23>, 3,
  <12, 23, 33>, 3,
  <12, 33, 40>, 3,
  <12, 40, 43>, 3,
  <12, 43, 38>, 3,
  <12, 38, 32>, 3,
  <12, 32, 22>, 3,
  <4, 8, 18>, 3,
  <4, 18, 25>, 3,
  <4, 25, 29>, 3,
  <4, 29, 28>, 3,
  <4, 28, 23>, 3,
  <4, 23, 15>, 3,
  <4, 15, 6>, 3,
  <4, 6, 2>, 3,
  <27, 37, 46>, 3,
  <27, 46, 48>, 3,
  <27, 48, 42>, 3,
  <27, 42, 35>, 3,
  <27, 35, 25>, 3,
  <27, 25, 18>, 3,
  <27, 18, 14>, 3,
  <27, 14, 20>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_68_augmented_truncated_dodecahedron_verts[27];
 #local P1 = Johnson_68_augmented_truncated_dodecahedron_verts[37];
 #local P2 = Johnson_68_augmented_truncated_dodecahedron_verts[46];
 #local P3 = Johnson_68_augmented_truncated_dodecahedron_verts[48];
 #local P4 = Johnson_68_augmented_truncated_dodecahedron_verts[42];
 #local P5 = Johnson_68_augmented_truncated_dodecahedron_verts[35];
 #local P6 = Johnson_68_augmented_truncated_dodecahedron_verts[25];
 #local P7 = Johnson_68_augmented_truncated_dodecahedron_verts[18];
 #local P8 = Johnson_68_augmented_truncated_dodecahedron_verts[14];
 #local P9 = Johnson_68_augmented_truncated_dodecahedron_verts[20];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_68_augmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_68_augmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_68_augmented_truncated_dodecahedron_faces2(OnPlane)
#local Johnson_68_augmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  65,
  Johnson_68_augmented_truncated_dodecahedron_verts[0],
  Johnson_68_augmented_truncated_dodecahedron_verts[1],
  Johnson_68_augmented_truncated_dodecahedron_verts[2],
  Johnson_68_augmented_truncated_dodecahedron_verts[3],
  Johnson_68_augmented_truncated_dodecahedron_verts[4],
  Johnson_68_augmented_truncated_dodecahedron_verts[5],
  Johnson_68_augmented_truncated_dodecahedron_verts[6],
  Johnson_68_augmented_truncated_dodecahedron_verts[7],
  Johnson_68_augmented_truncated_dodecahedron_verts[8],
  Johnson_68_augmented_truncated_dodecahedron_verts[9],
  Johnson_68_augmented_truncated_dodecahedron_verts[10],
  Johnson_68_augmented_truncated_dodecahedron_verts[11],
  Johnson_68_augmented_truncated_dodecahedron_verts[12],
  Johnson_68_augmented_truncated_dodecahedron_verts[13],
  Johnson_68_augmented_truncated_dodecahedron_verts[14],
  Johnson_68_augmented_truncated_dodecahedron_verts[15],
  Johnson_68_augmented_truncated_dodecahedron_verts[16],
  Johnson_68_augmented_truncated_dodecahedron_verts[17],
  Johnson_68_augmented_truncated_dodecahedron_verts[18],
  Johnson_68_augmented_truncated_dodecahedron_verts[19],
  Johnson_68_augmented_truncated_dodecahedron_verts[20],
  Johnson_68_augmented_truncated_dodecahedron_verts[21],
  Johnson_68_augmented_truncated_dodecahedron_verts[22],
  Johnson_68_augmented_truncated_dodecahedron_verts[23],
  Johnson_68_augmented_truncated_dodecahedron_verts[24],
  Johnson_68_augmented_truncated_dodecahedron_verts[25],
  Johnson_68_augmented_truncated_dodecahedron_verts[26],
  Johnson_68_augmented_truncated_dodecahedron_verts[27],
  Johnson_68_augmented_truncated_dodecahedron_verts[28],
  Johnson_68_augmented_truncated_dodecahedron_verts[29],
  Johnson_68_augmented_truncated_dodecahedron_verts[30],
  Johnson_68_augmented_truncated_dodecahedron_verts[31],
  Johnson_68_augmented_truncated_dodecahedron_verts[32],
  Johnson_68_augmented_truncated_dodecahedron_verts[33],
  Johnson_68_augmented_truncated_dodecahedron_verts[34],
  Johnson_68_augmented_truncated_dodecahedron_verts[35],
  Johnson_68_augmented_truncated_dodecahedron_verts[36],
  Johnson_68_augmented_truncated_dodecahedron_verts[37],
  Johnson_68_augmented_truncated_dodecahedron_verts[38],
  Johnson_68_augmented_truncated_dodecahedron_verts[39],
  Johnson_68_augmented_truncated_dodecahedron_verts[40],
  Johnson_68_augmented_truncated_dodecahedron_verts[41],
  Johnson_68_augmented_truncated_dodecahedron_verts[42],
  Johnson_68_augmented_truncated_dodecahedron_verts[43],
  Johnson_68_augmented_truncated_dodecahedron_verts[44],
  Johnson_68_augmented_truncated_dodecahedron_verts[45],
  Johnson_68_augmented_truncated_dodecahedron_verts[46],
  Johnson_68_augmented_truncated_dodecahedron_verts[47],
  Johnson_68_augmented_truncated_dodecahedron_verts[48],
  Johnson_68_augmented_truncated_dodecahedron_verts[49],
  Johnson_68_augmented_truncated_dodecahedron_verts[50],
  Johnson_68_augmented_truncated_dodecahedron_verts[51],
  Johnson_68_augmented_truncated_dodecahedron_verts[52],
  Johnson_68_augmented_truncated_dodecahedron_verts[53],
  Johnson_68_augmented_truncated_dodecahedron_verts[54],
  Johnson_68_augmented_truncated_dodecahedron_verts[55],
  Johnson_68_augmented_truncated_dodecahedron_verts[56],
  Johnson_68_augmented_truncated_dodecahedron_verts[57],
  Johnson_68_augmented_truncated_dodecahedron_verts[58],
  Johnson_68_augmented_truncated_dodecahedron_verts[59],
  Johnson_68_augmented_truncated_dodecahedron_verts[60],
  Johnson_68_augmented_truncated_dodecahedron_verts[61],
  Johnson_68_augmented_truncated_dodecahedron_verts[62],
  Johnson_68_augmented_truncated_dodecahedron_verts[63],
  Johnson_68_augmented_truncated_dodecahedron_verts[64]
 }
 face_indices {
  126,
  <34, 30, 24>,
  <45, 51, 41>,
  <36, 26, 31>,
  <53, 49, 44>,
  <16, 9, 19>,
  <27, 20, 21>,
  <1, 3, 5>,
  <4, 2, 0>,
  <11, 17, 7>,
  <12, 22, 13>,
  <62, 56, 58>,
  <59, 57, 63>,
  <43, 40, 50>,
  <39, 32, 38>,
  <23, 28, 33>,
  <10, 6, 15>,
  <25, 35, 29>,
  <8, 14, 18>,
  <48, 52, 42>,
  <47, 46, 37>,
  <54, 48, 46>,
  <55, 47, 49>,
  <61, 53, 59>,
  <62, 64, 63>,
  <60, 58, 52>,
  <54, 60, 52>,
  <54, 52, 48>,
  <55, 54, 46>,
  <55, 46, 47>,
  <61, 55, 49>,
  <61, 49, 53>,
  <64, 61, 59>,
  <64, 59, 63>,
  <60, 64, 62>,
  <60, 62, 58>,
  <60, 54, 55>,
  <60, 55, 61>,
  <60, 61, 64>,
  <31, 26, 19>,
  <31, 19, 9>,
  <31, 9, 5>,
  <31, 5, 3>,
  <31, 3, 7>,
  <31, 7, 17>,
  <31, 17, 24>,
  <31, 24, 30>,
  <59, 53, 44>,
  <59, 44, 36>,
  <59, 36, 31>,
  <59, 31, 30>,
  <59, 30, 34>,
  <59, 34, 41>,
  <59, 41, 51>,
  <59, 51, 57>,
  <37, 27, 21>,
  <37, 21, 16>,
  <37, 16, 19>,
  <37, 19, 26>,
  <37, 26, 36>,
  <37, 36, 44>,
  <37, 44, 49>,
  <37, 49, 47>,
  <8, 4, 0>,
  <8, 0, 1>,
  <8, 1, 5>,
  <8, 5, 9>,
  <8, 9, 16>,
  <8, 16, 21>,
  <8, 21, 20>,
  <8, 20, 14>,
  <10, 12, 13>,
  <10, 13, 11>,
  <10, 11, 7>,
  <10, 7, 3>,
  <10, 3, 1>,
  <10, 1, 0>,
  <10, 0, 2>,
  <10, 2, 6>,
  <39, 45, 41>,
  <39, 41, 34>,
  <39, 34, 24>,
  <39, 24, 17>,
  <39, 17, 11>,
  <39, 11, 13>,
  <39, 13, 22>,
  <39, 22, 32>,
  <50, 40, 33>,
  <50, 33, 28>,
  <50, 28, 29>,
  <50, 29, 35>,
  <50, 35, 42>,
  <50, 42, 52>,
  <50, 52, 58>,
  <50, 58, 56>,
  <45, 39, 38>,
  <45, 38, 43>,
  <45, 43, 50>,
  <45, 50, 56>,
  <45, 56, 62>,
  <45, 62, 63>,
  <45, 63, 57>,
  <45, 57, 51>,
  <12, 10, 15>,
  <12, 15, 23>,
  <12, 23, 33>,
  <12, 33, 40>,
  <12, 40, 43>,
  <12, 43, 38>,
  <12, 38, 32>,
  <12, 32, 22>,
  <4, 8, 18>,
  <4, 18, 25>,
  <4, 25, 29>,
  <4, 29, 28>,
  <4, 28, 23>,
  <4, 23, 15>,
  <4, 15, 6>,
  <4, 6, 2>,
  <27, 37, 46>,
  <27, 46, 48>,
  <27, 48, 42>,
  <27, 42, 35>,
  <27, 35, 25>,
  <27, 25, 18>,
  <27, 18, 14>,
  <27, 14, 20>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_68_augmented_truncated_dodecahedron_verts[27];
 #local P1 = Johnson_68_augmented_truncated_dodecahedron_verts[37];
 #local P2 = Johnson_68_augmented_truncated_dodecahedron_verts[46];
 #local P3 = Johnson_68_augmented_truncated_dodecahedron_verts[48];
 #local P4 = Johnson_68_augmented_truncated_dodecahedron_verts[42];
 #local P5 = Johnson_68_augmented_truncated_dodecahedron_verts[35];
 #local P6 = Johnson_68_augmented_truncated_dodecahedron_verts[25];
 #local P7 = Johnson_68_augmented_truncated_dodecahedron_verts[18];
 #local P8 = Johnson_68_augmented_truncated_dodecahedron_verts[14];
 #local P9 = Johnson_68_augmented_truncated_dodecahedron_verts[20];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_68_augmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_68_augmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_68_augmented_truncated_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[0], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[1], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[2], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[3], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[4], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[5], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[6], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[7], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[8], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[9], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[10], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[11], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[12], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[13], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[14], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[15], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[16], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[17], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[18], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[19], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[20], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[21], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[22], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[23], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[24], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[25], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[26], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[27], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[28], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[29], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[30], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[31], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[32], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[33], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[34], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[35], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[36], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[37], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[38], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[39], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[40], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[41], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[42], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[43], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[44], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[45], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[46], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[47], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[48], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[49], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[50], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[51], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[52], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[53], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[54], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[55], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[56], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[57], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[58], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[59], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[60], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[61], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[62], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[63], RadVer }
  sphere { Johnson_68_augmented_truncated_dodecahedron_verts[64], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[34], Johnson_68_augmented_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[30], Johnson_68_augmented_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[24], Johnson_68_augmented_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[45], Johnson_68_augmented_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[51], Johnson_68_augmented_truncated_dodecahedron_verts[41], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[41], Johnson_68_augmented_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[36], Johnson_68_augmented_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[26], Johnson_68_augmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[31], Johnson_68_augmented_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[53], Johnson_68_augmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[49], Johnson_68_augmented_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[44], Johnson_68_augmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[16], Johnson_68_augmented_truncated_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[9], Johnson_68_augmented_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[19], Johnson_68_augmented_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[27], Johnson_68_augmented_truncated_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[20], Johnson_68_augmented_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[21], Johnson_68_augmented_truncated_dodecahedron_verts[27], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[1], Johnson_68_augmented_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[3], Johnson_68_augmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[5], Johnson_68_augmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[4], Johnson_68_augmented_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[2], Johnson_68_augmented_truncated_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[0], Johnson_68_augmented_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[11], Johnson_68_augmented_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[17], Johnson_68_augmented_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[7], Johnson_68_augmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[12], Johnson_68_augmented_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[22], Johnson_68_augmented_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[13], Johnson_68_augmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[62], Johnson_68_augmented_truncated_dodecahedron_verts[56], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[56], Johnson_68_augmented_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[58], Johnson_68_augmented_truncated_dodecahedron_verts[62], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[59], Johnson_68_augmented_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[57], Johnson_68_augmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[63], Johnson_68_augmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[43], Johnson_68_augmented_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[40], Johnson_68_augmented_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[50], Johnson_68_augmented_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[39], Johnson_68_augmented_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[32], Johnson_68_augmented_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[38], Johnson_68_augmented_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[23], Johnson_68_augmented_truncated_dodecahedron_verts[28], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[28], Johnson_68_augmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[33], Johnson_68_augmented_truncated_dodecahedron_verts[23], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[10], Johnson_68_augmented_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[6], Johnson_68_augmented_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[15], Johnson_68_augmented_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[25], Johnson_68_augmented_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[35], Johnson_68_augmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[29], Johnson_68_augmented_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[8], Johnson_68_augmented_truncated_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[14], Johnson_68_augmented_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[18], Johnson_68_augmented_truncated_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[48], Johnson_68_augmented_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[52], Johnson_68_augmented_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[42], Johnson_68_augmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[47], Johnson_68_augmented_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[46], Johnson_68_augmented_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[37], Johnson_68_augmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[54], Johnson_68_augmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[48], Johnson_68_augmented_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[46], Johnson_68_augmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[55], Johnson_68_augmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[47], Johnson_68_augmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[49], Johnson_68_augmented_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[61], Johnson_68_augmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[53], Johnson_68_augmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[59], Johnson_68_augmented_truncated_dodecahedron_verts[61], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[62], Johnson_68_augmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[64], Johnson_68_augmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[63], Johnson_68_augmented_truncated_dodecahedron_verts[62], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[60], Johnson_68_augmented_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[58], Johnson_68_augmented_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[52], Johnson_68_augmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[54], Johnson_68_augmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[55], Johnson_68_augmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[61], Johnson_68_augmented_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[64], Johnson_68_augmented_truncated_dodecahedron_verts[61], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[60], Johnson_68_augmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[26], Johnson_68_augmented_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[9], Johnson_68_augmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[3], Johnson_68_augmented_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[17], Johnson_68_augmented_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[30], Johnson_68_augmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[44], Johnson_68_augmented_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[34], Johnson_68_augmented_truncated_dodecahedron_verts[41], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[51], Johnson_68_augmented_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[37], Johnson_68_augmented_truncated_dodecahedron_verts[27], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[21], Johnson_68_augmented_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[8], Johnson_68_augmented_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[0], Johnson_68_augmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[20], Johnson_68_augmented_truncated_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[10], Johnson_68_augmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[13], Johnson_68_augmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[2], Johnson_68_augmented_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[39], Johnson_68_augmented_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[22], Johnson_68_augmented_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[40], Johnson_68_augmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[28], Johnson_68_augmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[35], Johnson_68_augmented_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[56], Johnson_68_augmented_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[38], Johnson_68_augmented_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[15], Johnson_68_augmented_truncated_dodecahedron_verts[23], RadEdg }
  cylinder { Johnson_68_augmented_truncated_dodecahedron_verts[18], Johnson_68_augmented_truncated_dodecahedron_verts[25], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_68_augmented_truncated_dodecahedron_verts[27];
 #local P1 = Johnson_68_augmented_truncated_dodecahedron_verts[37];
 #local P2 = Johnson_68_augmented_truncated_dodecahedron_verts[46];
 #local P3 = Johnson_68_augmented_truncated_dodecahedron_verts[48];
 #local P4 = Johnson_68_augmented_truncated_dodecahedron_verts[42];
 #local P5 = Johnson_68_augmented_truncated_dodecahedron_verts[35];
 #local P6 = Johnson_68_augmented_truncated_dodecahedron_verts[25];
 #local P7 = Johnson_68_augmented_truncated_dodecahedron_verts[18];
 #local P8 = Johnson_68_augmented_truncated_dodecahedron_verts[14];
 #local P9 = Johnson_68_augmented_truncated_dodecahedron_verts[20];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_69_parabiaugmented_truncated_dodecahedron_verts = array[70]
{
<-0.988041, 0.082361, -0.032394>,
<-0.940439, 0.105620, 0.297446>,
<-0.939030, -0.112232, -0.299475>,
<-0.911497, 0.377114, 0.104950>,
<-0.814408, -0.051339, 0.564056>,
<-0.812127, -0.403831, -0.401783>,
<-0.783185, -0.132338, -0.594279>,
<-0.738637, 0.659440, 0.060095>,
<-0.658086, -0.328563, 0.665601>,
<-0.655805, -0.681055, -0.300238>,
<-0.621075, -0.575598, -0.615315>,
<-0.592133, -0.304105, -0.807812>,
<-0.581542, -0.033810, 0.802944>,
<-0.580033, 0.029724, -0.804200>,
<-0.535485, 0.821501, -0.149826>,
<-0.531183, -0.620162, 0.563294>,
<-0.529773, -0.838014, -0.033627>,
<-0.487884, 0.844761, 0.180013>,
<-0.482172, -0.814755, 0.296212>,
<-0.407173, 0.312050, -0.849055>,
<-0.379640, 0.801396, -0.444630>,
<-0.373928, -0.858119, -0.328432>,
<-0.339198, -0.752663, -0.643508>,
<-0.330790, 0.151510, 0.922864>
<-0.330629, 0.606803, -0.711711>,
<-0.292369, -0.313377, -0.954974>,
<-0.280270, 0.020452, -0.951362>,
<-0.255019, 0.862289, 0.418901>,
<-0.249306, -0.797226, 0.535100>,
<-0.157929, 0.433837, 0.878008>,
<-0.136047, -0.590601, -0.853430>,
<-0.128987, 0.705330, 0.685512>,
<-0.079877, 0.792123, -0.591793>,
<-0.074164, -0.867392, -0.475594>,
<-0.001607, 0.156613, 0.979553>,
<0.001607, -0.156613, -0.979556>,
<0.074164, 0.867391, 0.475591>,
<0.079877, -0.792124, 0.591790>,
<0.128987, -0.705330, -0.685515>,
<0.136047, 0.590601, 0.853427>,
<0.157929, -0.433837, -0.878011>,
<0.249306, 0.797226, -0.535103>,
<0.255019, -0.862289, -0.418905>,
<0.280269, -0.020452, 0.951360>,
<0.292369, 0.313377, 0.954971>,
<0.330629, -0.606803, 0.711709>,
<0.330790, -0.151511, -0.922866>,
<0.339198, 0.752662, 0.643506>,
<0.373928, 0.858119, 0.328428>,
<0.379640, -0.801396, 0.444627>,
<0.407172, -0.312051, 0.849052>,
<0.482172, 0.814754, -0.296215>,
<0.487884, -0.844761, -0.180016>,
<0.529773, 0.838013, 0.033625>,
<0.531183, 0.620161, -0.563297>,
<0.535485, -0.821502, 0.149823>,
<0.580033, -0.029724, 0.804197>,
<0.581542, 0.033810, -0.802948>,
<0.592133, 0.304105, 0.807809>,
<0.621074, 0.575598, 0.615313>,
<0.655804, 0.681055, 0.300235>,
<0.658086, 0.328562, -0.665604>,
<0.738637, -0.659440, -0.060097>,
<0.783184, 0.132337, 0.594276>,
<0.812126, 0.403830, 0.401780>,
<0.814408, 0.051338, -0.564059>,
<0.911497, -0.377114, -0.104953>,
<0.939029, 0.112232, 0.299472>,
<0.940439, -0.105620, -0.297449>,
<0.988041, -0.082361, 0.032391>,
}
#declare P0 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52];
#declare P1 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42];
#declare P2 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 70)
 #declare Johnson_69_parabiaugmented_truncated_dodecahedron_verts[Num] = vtransform(Johnson_69_parabiaugmented_truncated_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_69_parabiaugmented_truncated_dodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_69_parabiaugmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  70,
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[0],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[1],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[2],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[3],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[4],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[5],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[6],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[7],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[8],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[9],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[10],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[11],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[12],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[13],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[14],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[15],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[16],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[17],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[18],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[19],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[20],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[21],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[22],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[23],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[24],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[25],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[26],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[27],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[28],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[29],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[30],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[31],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[32],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[33],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[34],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[35],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[36],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[37],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[39],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[41],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[43],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[44],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[45],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[47],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[48],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[49],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[50],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[51],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[53],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[54],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[55],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[56],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[58],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[59],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[60],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[61],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[63],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[64],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[67],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[69]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  136,
  <4, 8, 12>, 0,
  <3, 0, 1>, 0,
  <18, 28, 15>, 0,
  <9, 21, 16>, 0,
  <49, 45, 37>, 0,
  <52, 62, 55>, 0,
  <56, 43, 50>, 0,
  <64, 63, 67>, 0,
  <29, 23, 34>, 0,
  <36, 27, 31>, 0,
  <13, 19, 26>, 0,
  <5, 2, 6>, 0,
  <20, 32, 24>, 0,
  <7, 17, 14>, 0,
  <51, 54, 41>, 0,
  <60, 53, 48>, 0,
  <65, 57, 61>, 0,
  <69, 66, 68>, 0,
  <40, 35, 46>, 0,
  <33, 38, 42>, 0,
  <30, 40, 38>, 0,
  <22, 33, 21>, 0,
  <10, 9, 5>, 0,
  <13, 11, 6>, 0,
  <25, 26, 35>, 0,
  <58, 56, 63>, 0,
  <59, 64, 60>, 0,
  <47, 48, 36>, 0,
  <29, 39, 31>, 0,
  <44, 34, 43>, 0,
  <30, 25, 35>, 1,
  <30, 35, 40>, 1,
  <22, 30, 38>, 1,
  <22, 38, 33>, 1,
  <10, 22, 21>, 1,
  <10, 21, 9>, 1,
  <11, 10, 5>, 1,
  <11, 5, 6>, 1,
  <25, 11, 13>, 1,
  <25, 13, 26>, 1,
  <58, 44, 43>, 1,
  <58, 43, 56>, 1,
  <59, 58, 63>, 1,
  <59, 63, 64>, 1,
  <47, 59, 60>, 1,
  <47, 60, 48>, 1,
  <39, 47, 36>, 1,
  <39, 36, 31>, 1,
  <44, 39, 29>, 1,
  <44, 29, 34>, 1,
  <25, 30, 22>, 2,
  <25, 22, 10>, 2,
  <25, 10, 11>, 2,
  <44, 58, 59>, 2,
  <44, 59, 47>, 2,
  <44, 47, 39>, 2,
  <15, 28, 37>, 3,
  <15, 37, 45>, 3,
  <15, 45, 50>, 3,
  <15, 50, 43>, 3,
  <15, 43, 34>, 3,
  <15, 34, 23>, 3,
  <15, 23, 12>, 3,
  <15, 12, 8>, 3,
  <5, 9, 16>, 3,
  <5, 16, 18>, 3,
  <5, 18, 15>, 3,
  <5, 15, 8>, 3,
  <5, 8, 4>, 3,
  <5, 4, 1>, 3,
  <5, 1, 0>, 3,
  <5, 0, 2>, 3,
  <42, 52, 55>, 3,
  <42, 55, 49>, 3,
  <42, 49, 37>, 3,
  <42, 37, 28>, 3,
  <42, 28, 18>, 3,
  <42, 18, 16>, 3,
  <42, 16, 21>, 3,
  <42, 21, 33>, 3,
  <69, 67, 63>, 3,
  <69, 63, 56>, 3,
  <69, 56, 50>, 3,
  <69, 50, 45>, 3,
  <69, 45, 49>, 3,
  <69, 49, 55>, 3,
  <69, 55, 62>, 3,
  <69, 62, 66>, 3,
  <67, 69, 68>, 3,
  <67, 68, 65>, 3,
  <67, 65, 61>, 3,
  <67, 61, 54>, 3,
  <67, 54, 51>, 3,
  <67, 51, 53>, 3,
  <67, 53, 60>, 3,
  <67, 60, 64>, 3,
  <7, 3, 1>, 3,
  <7, 1, 4>, 3,
  <7, 4, 12>, 3,
  <7, 12, 23>, 3,
  <7, 23, 29>, 3,
  <7, 29, 31>, 3,
  <7, 31, 27>, 3,
  <7, 27, 17>, 3,
  <24, 32, 41>, 3,
  <24, 41, 54>, 3,
  <24, 54, 61>, 3,
  <24, 61, 57>, 3,
  <24, 57, 46>, 3,
  <24, 46, 35>, 3,
  <24, 35, 26>, 3,
  <24, 26, 19>, 3,
  <3, 7, 14>, 3,
  <3, 14, 20>, 3,
  <3, 20, 24>, 3,
  <3, 24, 19>, 3,
  <3, 19, 13>, 3,
  <3, 13, 6>, 3,
  <3, 6, 2>, 3,
  <3, 2, 0>, 3,
  <36, 48, 53>, 3,
  <36, 53, 51>, 3,
  <36, 51, 41>, 3,
  <36, 41, 32>, 3,
  <36, 32, 20>, 3,
  <36, 20, 14>, 3,
  <36, 14, 17>, 3,
  <36, 17, 27>, 3,
  <52, 42, 38>, 3,
  <52, 38, 40>, 3,
  <52, 40, 46>, 3,
  <52, 46, 57>, 3,
  <52, 57, 65>, 3,
  <52, 65, 68>, 3,
  <52, 68, 66>, 3,
  <52, 66, 62>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52];
 #local P1 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42];
 #local P2 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38];
 #local P3 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40];
 #local P4 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46];
 #local P5 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57];
 #local P6 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65];
 #local P7 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68];
 #local P8 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66];
 #local P9 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_69_parabiaugmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_69_parabiaugmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_69_parabiaugmented_truncated_dodecahedron_faces2(OnPlane)
#local Johnson_69_parabiaugmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  70,
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[0],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[1],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[2],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[3],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[4],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[5],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[6],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[7],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[8],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[9],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[10],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[11],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[12],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[13],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[14],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[15],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[16],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[17],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[18],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[19],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[20],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[21],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[22],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[23],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[24],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[25],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[26],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[27],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[28],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[29],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[30],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[31],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[32],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[33],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[34],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[35],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[36],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[37],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[39],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[41],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[43],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[44],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[45],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[47],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[48],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[49],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[50],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[51],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[53],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[54],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[55],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[56],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[58],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[59],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[60],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[61],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[63],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[64],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[67],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68],
  Johnson_69_parabiaugmented_truncated_dodecahedron_verts[69]
 }
 face_indices {
  136,
  <4, 8, 12>,
  <3, 0, 1>,
  <18, 28, 15>,
  <9, 21, 16>,
  <49, 45, 37>,
  <52, 62, 55>,
  <56, 43, 50>,
  <64, 63, 67>,
  <29, 23, 34>,
  <36, 27, 31>,
  <13, 19, 26>,
  <5, 2, 6>,
  <20, 32, 24>,
  <7, 17, 14>,
  <51, 54, 41>,
  <60, 53, 48>,
  <65, 57, 61>,
  <69, 66, 68>,
  <40, 35, 46>,
  <33, 38, 42>,
  <30, 40, 38>,
  <22, 33, 21>,
  <10, 9, 5>,
  <13, 11, 6>,
  <25, 26, 35>,
  <58, 56, 63>,
  <59, 64, 60>,
  <47, 48, 36>,
  <29, 39, 31>,
  <44, 34, 43>,
  <30, 25, 35>,
  <30, 35, 40>,
  <22, 30, 38>,
  <22, 38, 33>,
  <10, 22, 21>,
  <10, 21, 9>,
  <11, 10, 5>,
  <11, 5, 6>,
  <25, 11, 13>,
  <25, 13, 26>,
  <58, 44, 43>,
  <58, 43, 56>,
  <59, 58, 63>,
  <59, 63, 64>,
  <47, 59, 60>,
  <47, 60, 48>,
  <39, 47, 36>,
  <39, 36, 31>,
  <44, 39, 29>,
  <44, 29, 34>,
  <25, 30, 22>,
  <25, 22, 10>,
  <25, 10, 11>,
  <44, 58, 59>,
  <44, 59, 47>,
  <44, 47, 39>,
  <15, 28, 37>,
  <15, 37, 45>,
  <15, 45, 50>,
  <15, 50, 43>,
  <15, 43, 34>,
  <15, 34, 23>,
  <15, 23, 12>,
  <15, 12, 8>,
  <5, 9, 16>,
  <5, 16, 18>,
  <5, 18, 15>,
  <5, 15, 8>,
  <5, 8, 4>,
  <5, 4, 1>,
  <5, 1, 0>,
  <5, 0, 2>,
  <42, 52, 55>,
  <42, 55, 49>,
  <42, 49, 37>,
  <42, 37, 28>,
  <42, 28, 18>,
  <42, 18, 16>,
  <42, 16, 21>,
  <42, 21, 33>,
  <69, 67, 63>,
  <69, 63, 56>,
  <69, 56, 50>,
  <69, 50, 45>,
  <69, 45, 49>,
  <69, 49, 55>,
  <69, 55, 62>,
  <69, 62, 66>,
  <67, 69, 68>,
  <67, 68, 65>,
  <67, 65, 61>,
  <67, 61, 54>,
  <67, 54, 51>,
  <67, 51, 53>,
  <67, 53, 60>,
  <67, 60, 64>,
  <7, 3, 1>,
  <7, 1, 4>,
  <7, 4, 12>,
  <7, 12, 23>,
  <7, 23, 29>,
  <7, 29, 31>,
  <7, 31, 27>,
  <7, 27, 17>,
  <24, 32, 41>,
  <24, 41, 54>,
  <24, 54, 61>,
  <24, 61, 57>,
  <24, 57, 46>,
  <24, 46, 35>,
  <24, 35, 26>,
  <24, 26, 19>,
  <3, 7, 14>,
  <3, 14, 20>,
  <3, 20, 24>,
  <3, 24, 19>,
  <3, 19, 13>,
  <3, 13, 6>,
  <3, 6, 2>,
  <3, 2, 0>,
  <36, 48, 53>,
  <36, 53, 51>,
  <36, 51, 41>,
  <36, 41, 32>,
  <36, 32, 20>,
  <36, 20, 14>,
  <36, 14, 17>,
  <36, 17, 27>,
  <52, 42, 38>,
  <52, 38, 40>,
  <52, 40, 46>,
  <52, 46, 57>,
  <52, 57, 65>,
  <52, 65, 68>,
  <52, 68, 66>,
  <52, 66, 62>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52];
 #local P1 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42];
 #local P2 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38];
 #local P3 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40];
 #local P4 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46];
 #local P5 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57];
 #local P6 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65];
 #local P7 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68];
 #local P8 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66];
 #local P9 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_69_parabiaugmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_69_parabiaugmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_69_parabiaugmented_truncated_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[0], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[1], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[2], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[3], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[4], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[5], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[6], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[7], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[8], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[9], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[10], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[11], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[12], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[13], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[14], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[15], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[16], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[17], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[18], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[19], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[20], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[21], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[22], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[23], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[24], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[25], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[26], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[27], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[28], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[29], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[30], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[31], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[32], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[33], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[34], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[35], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[36], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[37], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[39], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[41], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[43], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[44], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[45], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[47], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[48], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[49], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[50], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[51], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[53], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[54], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[55], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[56], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[58], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[59], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[60], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[61], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[63], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[64], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[67], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68], RadVer }
  sphere { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[69], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[4], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[8], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[12], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[3], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[0], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[1], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[18], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[28], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[28], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[15], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[9], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[21], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[16], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[49], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[45], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[37], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[55], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[56], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[43], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[50], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[56], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[64], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[63], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[67], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[67], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[29], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[23], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[23], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[34], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[36], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[27], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[27], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[31], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[13], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[19], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[26], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[5], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[2], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[6], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[20], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[32], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[24], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[7], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[17], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[14], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[51], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[54], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[41], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[41], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[60], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[53], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[48], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[61], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[61], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[69], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[69], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[35], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[33], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[30], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[22], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[33], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[21], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[10], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[9], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[5], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[13], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[11], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[6], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[25], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[26], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[35], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[58], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[56], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[56], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[63], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[59], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[64], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[60], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[47], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[48], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[36], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[29], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[39], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[31], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[44], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[34], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[43], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[30], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[22], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[10], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[11], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[25], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[58], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[59], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[47], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[39], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[44], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[28], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[45], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[23], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[8], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[16], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[4], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[0], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[55], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[69], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[67], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[61], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[51], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[7], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[27], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[32], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[41], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[19], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Johnson_69_parabiaugmented_truncated_dodecahedron_verts[14], Johnson_69_parabiaugmented_truncated_dodecahedron_verts[20], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[52];
 #local P1 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[42];
 #local P2 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[38];
 #local P3 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[40];
 #local P4 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[46];
 #local P5 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[57];
 #local P6 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[65];
 #local P7 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[68];
 #local P8 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[66];
 #local P9 = Johnson_69_parabiaugmented_truncated_dodecahedron_verts[62];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_70_metabiaugmented_truncated_dodecahedron_verts = array[70]
{
<-0.989194, -0.091477, -0.102373>,
<-0.986156, -0.109996, 0.232129>,
<-0.908902, 0.233330, -0.085120>,
<-0.905864, 0.214811, 0.249382>,
<-0.892465, -0.388533, -0.223390>,
<-0.887549, -0.418497, 0.317846>,
<-0.850998, 0.061184, -0.366646>,
<-0.843044, 0.012701, 0.509091>,
<-0.829645, -0.590642, 0.036320>,
<-0.810408, 0.497156, 0.096369>,
<-0.754269, -0.235871, -0.487662>,
<-0.744438, -0.295800, 0.594808>,
<-0.658813, 0.046474, -0.640675>,
<-0.655662, -0.544372, -0.401946>,
<-0.647709, -0.592856, 0.473792>,
<-0.645943, -0.031974, 0.776297>,
<-0.593136, 0.751890, 0.108498>,
<-0.592842, -0.746482, -0.142236>,
<-0.589804, -0.765001, 0.192266>,
<-0.405755, 0.194817, -0.802538>,
<-0.400657, -0.761193, -0.416265>,
<-0.392703, -0.809676, 0.459472>,
<-0.389847, 0.097850, 0.948936>,
<-0.340078, 0.900233, -0.053365>
<-0.337040, 0.881715, 0.281137>,
<-0.188483, 0.449551, -0.790409>,
<-0.172576, 0.352585, 0.961066>,
<-0.147893, 0.885523, -0.327394>,
<-0.139939, 0.837040, 0.548343>,
<-0.091754, 0.152496, -0.911425>,
<-0.089989, 0.713378, -0.608920>,
<-0.086657, -0.803514, -0.525152>,
<-0.077120, 0.634930, 0.808053>,
<-0.076826, -0.863443, 0.557318>,
<-0.073969, 0.044084, 1.046782>,
<0.126005, 0.562254, -0.815685>,
<0.163251, -0.064325, -0.925745>,
<0.166107, 0.843202, -0.436281>,
<0.166401, -0.655171, -0.687015>,
<0.175938, 0.783273, 0.646190>,
<0.179271, -0.733618, 0.729957>,
<0.181036, -0.172737, 1.032463>,
<0.222734, 0.265199, -0.936702>,
<0.229221, -0.857281, -0.427306>,
<0.237175, -0.905764, 0.448431>,
<0.261857, -0.372826, -0.840028>,
<0.277765, -0.469792, 0.911446>,
<0.382101, 0.692078, -0.643046>,
<0.426322, -0.901955, -0.160100>,
<0.429360, -0.920474, 0.174402>,
<0.479129, -0.118091, -0.827899>,
<0.481985, 0.789435, -0.338434>,
<0.489939, 0.740952, 0.537303>,
<0.495036, -0.215058, 0.923576>,
<0.538612, 0.211432, -0.838855>,
<0.637106, 0.475258, -0.657366>,
<0.679086, 0.744760, -0.071228>,
<0.682124, 0.726241, 0.263273>,
<0.682418, -0.772131, 0.012539>,
<0.735225, 0.011733, -0.655260>,
<0.736990, 0.572615, -0.352754>,
<0.744944, 0.524132, 0.522983>,
<0.748094, -0.066715, 0.761713>,
<0.833719, 0.275559, -0.473771>,
<0.843550, 0.215630, 0.608700>,
<0.899689, -0.517397, 0.024669>,
<0.932326, -0.032942, -0.388054>,
<0.940279, -0.081425, 0.487683>,
<0.995146, -0.235051, -0.128344>,
<0.998184, -0.253571, 0.206158>,
}
#declare P0 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31];
#declare P1 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20];
#declare P2 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 70)
 #declare Johnson_70_metabiaugmented_truncated_dodecahedron_verts[Num] = vtransform(Johnson_70_metabiaugmented_truncated_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_70_metabiaugmented_truncated_dodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_70_metabiaugmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  70,
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[0],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[1],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[2],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[3],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[4],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[5],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[6],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[7],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[8],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[9],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[11],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[14],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[15],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[16],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[17],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[18],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[21],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[22],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[23],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[24],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[25],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[26],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[27],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[28],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[30],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[32],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[33],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[34],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[35],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[37],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[39],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[40],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[41],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[42],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[43],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[44],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[46],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[47],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[48],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[49],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[50],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[51],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[52],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[53],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[54],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[55],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[56],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[57],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[58],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[59],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[60],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[61],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[62],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[63],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[64],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[65],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[66],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[67],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[68],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[69]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  136,
  <41, 46, 53>, 0,
  <26, 22, 34>, 0,
  <33, 44, 40>, 0,
  <14, 18, 21>, 0,
  <48, 58, 49>, 0,
  <31, 38, 43>, 0,
  <68, 69, 65>, 0,
  <59, 63, 66>, 0,
  <64, 62, 67>, 0,
  <57, 52, 61>, 0,
  <3, 9, 2>, 0,
  <11, 15, 7>, 0,
  <24, 23, 16>, 0,
  <32, 39, 28>, 0,
  <37, 30, 27>, 0,
  <60, 51, 56>, 0,
  <29, 19, 25>, 0,
  <50, 45, 36>, 0,
  <10, 6, 12>, 0,
  <17, 13, 20>, 0,
  <4, 10, 13>, 0,
  <8, 17, 18>, 0,
  <5, 14, 11>, 0,
  <3, 1, 7>, 0,
  <0, 2, 6>, 0,
  <47, 37, 51>, 0,
  <55, 60, 63>, 0,
  <54, 59, 50>, 0,
  <29, 42, 36>, 0,
  <35, 25, 30>, 0,
  <4, 0, 6>, 1,
  <4, 6, 10>, 1,
  <8, 4, 13>, 1,
  <8, 13, 17>, 1,
  <5, 8, 18>, 1,
  <5, 18, 14>, 1,
  <1, 5, 11>, 1,
  <1, 11, 7>, 1,
  <0, 1, 3>, 1,
  <0, 3, 2>, 1,
  <47, 35, 30>, 1,
  <47, 30, 37>, 1,
  <55, 47, 51>, 1,
  <55, 51, 60>, 1,
  <54, 55, 63>, 1,
  <54, 63, 59>, 1,
  <42, 54, 50>, 1,
  <42, 50, 36>, 1,
  <35, 42, 29>, 1,
  <35, 29, 25>, 1,
  <0, 4, 8>, 2,
  <0, 8, 5>, 2,
  <0, 5, 1>, 2,
  <35, 47, 55>, 2,
  <35, 55, 54>, 2,
  <35, 54, 42>, 2,
  <40, 44, 49>, 3,
  <40, 49, 58>, 3,
  <40, 58, 65>, 3,
  <40, 65, 69>, 3,
  <40, 69, 67>, 3,
  <40, 67, 62>, 3,
  <40, 62, 53>, 3,
  <40, 53, 46>, 3,
  <11, 14, 21>, 3,
  <11, 21, 33>, 3,
  <11, 33, 40>, 3,
  <11, 40, 46>, 3,
  <11, 46, 41>, 3,
  <11, 41, 34>, 3,
  <11, 34, 22>, 3,
  <11, 22, 15>, 3,
  <20, 31, 43>, 3,
  <20, 43, 48>, 3,
  <20, 48, 49>, 3,
  <20, 49, 44>, 3,
  <20, 44, 33>, 3,
  <20, 33, 21>, 3,
  <20, 21, 18>, 3,
  <20, 18, 17>, 3,
  <50, 59, 66>, 3,
  <50, 66, 68>, 3,
  <50, 68, 65>, 3,
  <50, 65, 58>, 3,
  <50, 58, 48>, 3,
  <50, 48, 43>, 3,
  <50, 43, 38>, 3,
  <50, 38, 45>, 3,
  <56, 57, 61>, 3,
  <56, 61, 64>, 3,
  <56, 64, 67>, 3,
  <56, 67, 69>, 3,
  <56, 69, 68>, 3,
  <56, 68, 66>, 3,
  <56, 66, 63>, 3,
  <56, 63, 60>, 3,
  <32, 26, 34>, 3,
  <32, 34, 41>, 3,
  <32, 41, 53>, 3,
  <32, 53, 62>, 3,
  <32, 62, 64>, 3,
  <32, 64, 61>, 3,
  <32, 61, 52>, 3,
  <32, 52, 39>, 3,
  <16, 23, 27>, 3,
  <16, 27, 30>, 3,
  <16, 30, 25>, 3,
  <16, 25, 19>, 3,
  <16, 19, 12>, 3,
  <16, 12, 6>, 3,
  <16, 6, 2>, 3,
  <16, 2, 9>, 3,
  <26, 32, 28>, 3,
  <26, 28, 24>, 3,
  <26, 24, 16>, 3,
  <26, 16, 9>, 3,
  <26, 9, 3>, 3,
  <26, 3, 7>, 3,
  <26, 7, 15>, 3,
  <26, 15, 22>, 3,
  <57, 56, 51>, 3,
  <57, 51, 37>, 3,
  <57, 37, 27>, 3,
  <57, 27, 23>, 3,
  <57, 23, 24>, 3,
  <57, 24, 28>, 3,
  <57, 28, 39>, 3,
  <57, 39, 52>, 3,
  <31, 20, 13>, 3,
  <31, 13, 10>, 3,
  <31, 10, 12>, 3,
  <31, 12, 19>, 3,
  <31, 19, 29>, 3,
  <31, 29, 36>, 3,
  <31, 36, 45>, 3,
  <31, 45, 38>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31];
 #local P1 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20];
 #local P2 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13];
 #local P3 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10];
 #local P4 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12];
 #local P5 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19];
 #local P6 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29];
 #local P7 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36];
 #local P8 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45];
 #local P9 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_70_metabiaugmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_70_metabiaugmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_70_metabiaugmented_truncated_dodecahedron_faces2(OnPlane)
#local Johnson_70_metabiaugmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  70,
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[0],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[1],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[2],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[3],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[4],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[5],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[6],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[7],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[8],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[9],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[11],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[14],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[15],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[16],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[17],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[18],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[21],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[22],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[23],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[24],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[25],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[26],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[27],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[28],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[30],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[32],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[33],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[34],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[35],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[37],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[39],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[40],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[41],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[42],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[43],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[44],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[46],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[47],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[48],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[49],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[50],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[51],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[52],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[53],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[54],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[55],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[56],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[57],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[58],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[59],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[60],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[61],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[62],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[63],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[64],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[65],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[66],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[67],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[68],
  Johnson_70_metabiaugmented_truncated_dodecahedron_verts[69]
 }
 face_indices {
  136,
  <41, 46, 53>,
  <26, 22, 34>,
  <33, 44, 40>,
  <14, 18, 21>,
  <48, 58, 49>,
  <31, 38, 43>,
  <68, 69, 65>,
  <59, 63, 66>,
  <64, 62, 67>,
  <57, 52, 61>,
  <3, 9, 2>,
  <11, 15, 7>,
  <24, 23, 16>,
  <32, 39, 28>,
  <37, 30, 27>,
  <60, 51, 56>,
  <29, 19, 25>,
  <50, 45, 36>,
  <10, 6, 12>,
  <17, 13, 20>,
  <4, 10, 13>,
  <8, 17, 18>,
  <5, 14, 11>,
  <3, 1, 7>,
  <0, 2, 6>,
  <47, 37, 51>,
  <55, 60, 63>,
  <54, 59, 50>,
  <29, 42, 36>,
  <35, 25, 30>,
  <4, 0, 6>,
  <4, 6, 10>,
  <8, 4, 13>,
  <8, 13, 17>,
  <5, 8, 18>,
  <5, 18, 14>,
  <1, 5, 11>,
  <1, 11, 7>,
  <0, 1, 3>,
  <0, 3, 2>,
  <47, 35, 30>,
  <47, 30, 37>,
  <55, 47, 51>,
  <55, 51, 60>,
  <54, 55, 63>,
  <54, 63, 59>,
  <42, 54, 50>,
  <42, 50, 36>,
  <35, 42, 29>,
  <35, 29, 25>,
  <0, 4, 8>,
  <0, 8, 5>,
  <0, 5, 1>,
  <35, 47, 55>,
  <35, 55, 54>,
  <35, 54, 42>,
  <40, 44, 49>,
  <40, 49, 58>,
  <40, 58, 65>,
  <40, 65, 69>,
  <40, 69, 67>,
  <40, 67, 62>,
  <40, 62, 53>,
  <40, 53, 46>,
  <11, 14, 21>,
  <11, 21, 33>,
  <11, 33, 40>,
  <11, 40, 46>,
  <11, 46, 41>,
  <11, 41, 34>,
  <11, 34, 22>,
  <11, 22, 15>,
  <20, 31, 43>,
  <20, 43, 48>,
  <20, 48, 49>,
  <20, 49, 44>,
  <20, 44, 33>,
  <20, 33, 21>,
  <20, 21, 18>,
  <20, 18, 17>,
  <50, 59, 66>,
  <50, 66, 68>,
  <50, 68, 65>,
  <50, 65, 58>,
  <50, 58, 48>,
  <50, 48, 43>,
  <50, 43, 38>,
  <50, 38, 45>,
  <56, 57, 61>,
  <56, 61, 64>,
  <56, 64, 67>,
  <56, 67, 69>,
  <56, 69, 68>,
  <56, 68, 66>,
  <56, 66, 63>,
  <56, 63, 60>,
  <32, 26, 34>,
  <32, 34, 41>,
  <32, 41, 53>,
  <32, 53, 62>,
  <32, 62, 64>,
  <32, 64, 61>,
  <32, 61, 52>,
  <32, 52, 39>,
  <16, 23, 27>,
  <16, 27, 30>,
  <16, 30, 25>,
  <16, 25, 19>,
  <16, 19, 12>,
  <16, 12, 6>,
  <16, 6, 2>,
  <16, 2, 9>,
  <26, 32, 28>,
  <26, 28, 24>,
  <26, 24, 16>,
  <26, 16, 9>,
  <26, 9, 3>,
  <26, 3, 7>,
  <26, 7, 15>,
  <26, 15, 22>,
  <57, 56, 51>,
  <57, 51, 37>,
  <57, 37, 27>,
  <57, 27, 23>,
  <57, 23, 24>,
  <57, 24, 28>,
  <57, 28, 39>,
  <57, 39, 52>,
  <31, 20, 13>,
  <31, 13, 10>,
  <31, 10, 12>,
  <31, 12, 19>,
  <31, 19, 29>,
  <31, 29, 36>,
  <31, 36, 45>,
  <31, 45, 38>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31];
 #local P1 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20];
 #local P2 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13];
 #local P3 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10];
 #local P4 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12];
 #local P5 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19];
 #local P6 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29];
 #local P7 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36];
 #local P8 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45];
 #local P9 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_70_metabiaugmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_70_metabiaugmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_70_metabiaugmented_truncated_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[0], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[1], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[2], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[3], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[4], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[5], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[6], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[7], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[8], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[9], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[11], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[14], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[15], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[16], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[17], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[18], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[21], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[22], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[23], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[24], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[25], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[26], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[27], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[28], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[30], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[32], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[33], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[34], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[35], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[37], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[39], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[40], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[41], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[42], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[43], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[44], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[46], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[47], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[48], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[49], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[50], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[51], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[52], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[53], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[54], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[55], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[56], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[57], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[58], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[59], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[60], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[61], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[62], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[63], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[64], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[65], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[66], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[67], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[68], RadVer }
  sphere { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[69], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[41], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[46], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[53], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[41], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[26], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[22], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[34], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[33], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[44], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[40], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[14], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[18], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[21], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[48], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[58], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[49], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[43], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[68], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[69], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[69], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[65], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[65], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[68], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[59], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[63], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[66], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[66], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[64], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[62], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[62], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[67], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[67], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[57], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[52], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[61], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[61], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[3], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[9], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[2], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[11], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[15], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[7], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[24], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[23], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[23], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[16], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[32], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[39], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[28], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[28], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[37], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[30], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[27], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[27], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[60], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[51], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[56], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[56], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[25], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[50], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[6], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[17], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[4], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[8], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[17], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[18], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[5], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[14], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[11], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[3], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[1], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[7], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[0], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[2], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[6], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[47], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[37], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[51], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[55], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[60], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[63], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[54], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[59], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[50], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[42], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[35], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[25], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[30], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[4], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[8], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[5], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[1], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[0], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[47], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[55], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[54], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[42], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[35], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[44], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[58], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[65], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[69], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[67], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[62], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[46], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[21], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[41], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[22], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[43], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[66], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[68], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[56], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[61], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[32], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[52], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[23], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[27], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[9], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_70_metabiaugmented_truncated_dodecahedron_verts[28], Johnson_70_metabiaugmented_truncated_dodecahedron_verts[24], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[31];
 #local P1 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[20];
 #local P2 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[13];
 #local P3 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[10];
 #local P4 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[12];
 #local P5 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[19];
 #local P6 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[29];
 #local P7 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[36];
 #local P8 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[45];
 #local P9 = Johnson_70_metabiaugmented_truncated_dodecahedron_verts[38];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_71_triaugmented_truncated_dodecahedron_verts = array[75]
{
<-0.942902, 0.070270, -0.149675>,
<-0.907058, 0.322313, 0.065363>,
<-0.897048, -0.257164, -0.191336>,
<-0.851819, 0.371393, -0.259585>,
<-0.803207, 0.402693, 0.371640>,
<-0.802539, 0.632087, 0.129919>,
<-0.787011, -0.534922, -0.043707>,
<-0.747300, 0.681167, -0.195029>,
<-0.731772, -0.485841, -0.368655>,
<-0.671018, 0.280706, 0.652170>,
<-0.658589, 0.531186, -0.479085>,
<-0.654821, -0.656908, 0.236823>,
<-0.579935, 0.581829, 0.542259>,
<-0.579266, 0.811224, 0.300537>,
<-0.560981, 0.002949, 0.799799>,
<-0.550971, -0.576528, 0.543100>,
<-0.515127, -0.324486, 0.758138>,
<-0.510203, -0.528414, -0.613902>,
<-0.489887, 0.890637, -0.225239>,
<-0.437021, 0.488613, -0.724333>,
<-0.401177, 0.740656, -0.509295>,
<-0.386037, 0.971017, 0.081037>,
<-0.385694, -0.805205, 0.365781>,
<-0.322522, 0.791299, 0.512049>
<-0.317618, -0.591958, 0.780503>,
<-0.316974, -0.368621, -0.833402>,
<-0.291854, -0.145349, 0.928756>,
<-0.271745, 0.259936, -0.901652>,
<-0.225891, -0.067498, -0.943313>,
<-0.206937, -0.646378, -0.685774>,
<-0.177904, 0.919793, -0.338677>,
<-0.152342, -0.820635, 0.603184>,
<-0.129293, 0.951092, 0.292549>,
<-0.094345, -0.412822, 0.951122>,
<-0.082428, -0.923170, 0.293910>,
<-0.074054, 1.000172, -0.032399>,
<0.002897, 0.829106, 0.573078>,
<0.031522, 0.141972, -0.973523>,
<0.033565, -0.107542, 0.989786>,
<0.062190, -0.794676, -0.556816>,
<0.139140, -0.965743, 0.048662>,
<0.147515, 0.957600, -0.277647>,
<0.173077, -0.782829, 0.664213>,
<0.194380, -0.916662, -0.276286>,
<0.208921, -0.530786, 0.879250>,
<0.242991, -0.885363, 0.354939>,
<0.272024, 0.680808, 0.702036>,
<0.290978, 0.101928, 0.959576>,
<0.336832, -0.225507, 0.917915>,
<0.356941, 0.179778, -0.912493>,
<0.382061, 0.403051, 0.849665>,
<0.387609, -0.756870, -0.495786>,
<0.450781, 0.839635, -0.349518>,
<0.466264, -0.706226, 0.525558>,
<0.502108, -0.454184, 0.740596>,
<0.575290, 0.562844, 0.630165>,
<0.580214, 0.358915, -0.741875>,
<-0.018946, -0.326587, -0.976456>,
<0.616058, 0.610958, -0.526838>,
<0.626068, 0.031481, -0.783536>,
<0.645022, -0.547400, -0.525996>,
<0.238466, -0.117117, -1.006666>,
<0.719908, 0.691337, -0.220560>,
<0.723676, -0.496756, 0.495348>,
<0.736105, -0.246276, -0.635907>,
<0.796859, 0.520271, 0.384917>,
<0.091091, -0.604344, -0.828827>,
<0.852098, 0.569351, 0.059969>,
<0.868294, -0.368263, -0.355377>,
<0.507593, -0.265415, -0.877708>,
<0.916906, -0.336964, 0.275848>,
<0.962135, 0.291594, 0.207599>,
<0.416510, -0.566538, -0.767798>,
<0.972145, -0.287883, -0.049100>,
<1.007989, -0.035841, 0.165937>,
}
#declare P0 = Johnson_71_triaugmented_truncated_dodecahedron_verts[46];
#declare P1 = Johnson_71_triaugmented_truncated_dodecahedron_verts[36];
#declare P2 = Johnson_71_triaugmented_truncated_dodecahedron_verts[23];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 75)
 #declare Johnson_71_triaugmented_truncated_dodecahedron_verts[Num] = vtransform(Johnson_71_triaugmented_truncated_dodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_71_triaugmented_truncated_dodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_71_triaugmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  75,
  Johnson_71_triaugmented_truncated_dodecahedron_verts[0],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[1],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[2],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[3],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[4],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[5],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[6],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[7],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[8],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[9],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[10],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[11],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[12],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[13],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[14],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[15],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[16],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[17],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[18],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[19],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[20],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[21],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[22],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[23],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[24],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[25],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[26],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[27],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[28],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[29],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[30],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[31],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[32],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[33],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[34],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[35],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[36],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[37],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[38],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[39],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[40],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[41],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[42],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[43],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[44],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[45],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[46],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[47],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[48],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[49],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[50],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[51],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[52],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[53],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[54],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[55],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[56],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[57],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[58],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[59],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[60],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[61],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[62],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[63],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[64],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[65],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[66],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[67],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[68],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[69],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[70],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[71],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[72],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[73],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[74]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  146,
  <70, 73, 74>, 0,
  <54, 53, 63>, 0,
  <60, 64, 68>, 0,
  <43, 39, 51>, 0,
  <49, 56, 59>, 0,
  <28, 27, 37>, 0,
  <52, 62, 58>, 0,
  <30, 35, 41>, 0,
  <65, 71, 67>, 0,
  <50, 55, 46>, 0,
  <3, 0, 1>, 0,
  <20, 19, 10>, 0,
  <8, 6, 2>, 0,
  <25, 29, 17>, 0,
  <22, 15, 11>, 0,
  <45, 34, 40>, 0,
  <26, 14, 16>, 0,
  <48, 47, 38>, 0,
  <12, 4, 9>, 0,
  <32, 23, 36>, 0,
  <13, 12, 23>, 0,
  <21, 32, 35>, 0,
  <18, 30, 20>, 0,
  <3, 7, 10>, 0,
  <5, 1, 4>, 0,
  <31, 22, 34>, 0,
  <42, 45, 53>, 0,
  <44, 54, 48>, 0,
  <26, 33, 38>, 0,
  <24, 16, 15>, 0,
  <66, 39, 29>, 0,
  <57, 25, 28>, 0,
  <61, 37, 49>, 0,
  <69, 59, 64>, 0,
  <72, 60, 51>, 0,
  <13, 5, 4>, 1,
  <13, 4, 12>, 1,
  <21, 13, 23>, 1,
  <21, 23, 32>, 1,
  <18, 21, 35>, 1,
  <18, 35, 30>, 1,
  <7, 18, 20>, 1,
  <7, 20, 10>, 1,
  <5, 7, 3>, 1,
  <5, 3, 1>, 1,
  <31, 24, 15>, 1,
  <31, 15, 22>, 1,
  <42, 31, 34>, 1,
  <42, 34, 45>, 1,
  <44, 42, 53>, 1,
  <44, 53, 54>, 1,
  <33, 44, 48>, 1,
  <33, 48, 38>, 1,
  <24, 33, 26>, 1,
  <24, 26, 16>, 1,
  <66, 72, 51>, 1,
  <66, 51, 39>, 1,
  <66, 29, 25>, 1,
  <66, 25, 57>, 1,
  <57, 28, 37>, 1,
  <57, 37, 61>, 1,
  <61, 49, 59>, 1,
  <61, 59, 69>, 1,
  <69, 64, 60>, 1,
  <69, 60, 72>, 1,
  <5, 13, 21>, 2,
  <5, 21, 18>, 2,
  <5, 18, 7>, 2,
  <24, 31, 42>, 2,
  <24, 42, 44>, 2,
  <24, 44, 33>, 2,
  <72, 66, 57>, 2,
  <72, 57, 61>, 2,
  <72, 61, 69>, 2,
  <68, 64, 59>, 3,
  <68, 59, 56>, 3,
  <68, 56, 58>, 3,
  <68, 58, 62>, 3,
  <68, 62, 67>, 3,
  <68, 67, 71>, 3,
  <68, 71, 74>, 3,
  <68, 74, 73>, 3,
  <40, 43, 51>, 3,
  <40, 51, 60>, 3,
  <40, 60, 68>, 3,
  <40, 68, 73>, 3,
  <40, 73, 70>, 3,
  <40, 70, 63>, 3,
  <40, 63, 53>, 3,
  <40, 53, 45>, 3,
  <54, 63, 70>, 3,
  <54, 70, 74>, 3,
  <54, 74, 71>, 3,
  <54, 71, 65>, 3,
  <54, 65, 55>, 3,
  <54, 55, 50>, 3,
  <54, 50, 47>, 3,
  <54, 47, 48>, 3,
  <20, 30, 41>, 3,
  <20, 41, 52>, 3,
  <20, 52, 58>, 3,
  <20, 58, 56>, 3,
  <20, 56, 49>, 3,
  <20, 49, 37>, 3,
  <20, 37, 27>, 3,
  <20, 27, 19>, 3,
  <36, 46, 55>, 3,
  <36, 55, 65>, 3,
  <36, 65, 67>, 3,
  <36, 67, 62>, 3,
  <36, 62, 52>, 3,
  <36, 52, 41>, 3,
  <36, 41, 35>, 3,
  <36, 35, 32>, 3,
  <2, 6, 11>, 3,
  <2, 11, 15>, 3,
  <2, 15, 16>, 3,
  <2, 16, 14>, 3,
  <2, 14, 9>, 3,
  <2, 9, 4>, 3,
  <2, 4, 1>, 3,
  <2, 1, 0>, 3,
  <28, 25, 17>, 3,
  <28, 17, 8>, 3,
  <28, 8, 2>, 3,
  <28, 2, 0>, 3,
  <28, 0, 3>, 3,
  <28, 3, 10>, 3,
  <28, 10, 19>, 3,
  <28, 19, 27>, 3,
  <43, 40, 34>, 3,
  <43, 34, 22>, 3,
  <43, 22, 11>, 3,
  <43, 11, 6>, 3,
  <43, 6, 8>, 3,
  <43, 8, 17>, 3,
  <43, 17, 29>, 3,
  <43, 29, 39>, 3,
  <46, 36, 23>, 3,
  <46, 23, 12>, 3,
  <46, 12, 9>, 3,
  <46, 9, 14>, 3,
  <46, 14, 26>, 3,
  <46, 26, 38>, 3,
  <46, 38, 47>, 3,
  <46, 47, 50>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_71_triaugmented_truncated_dodecahedron_verts[46];
 #local P1 = Johnson_71_triaugmented_truncated_dodecahedron_verts[36];
 #local P2 = Johnson_71_triaugmented_truncated_dodecahedron_verts[23];
 #local P3 = Johnson_71_triaugmented_truncated_dodecahedron_verts[12];
 #local P4 = Johnson_71_triaugmented_truncated_dodecahedron_verts[9];
 #local P5 = Johnson_71_triaugmented_truncated_dodecahedron_verts[14];
 #local P6 = Johnson_71_triaugmented_truncated_dodecahedron_verts[26];
 #local P7 = Johnson_71_triaugmented_truncated_dodecahedron_verts[38];
 #local P8 = Johnson_71_triaugmented_truncated_dodecahedron_verts[47];
 #local P9 = Johnson_71_triaugmented_truncated_dodecahedron_verts[50];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_71_triaugmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_71_triaugmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_71_triaugmented_truncated_dodecahedron_faces2(OnPlane)
#local Johnson_71_triaugmented_truncated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  75,
  Johnson_71_triaugmented_truncated_dodecahedron_verts[0],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[1],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[2],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[3],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[4],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[5],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[6],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[7],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[8],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[9],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[10],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[11],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[12],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[13],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[14],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[15],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[16],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[17],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[18],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[19],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[20],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[21],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[22],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[23],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[24],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[25],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[26],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[27],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[28],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[29],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[30],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[31],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[32],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[33],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[34],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[35],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[36],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[37],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[38],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[39],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[40],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[41],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[42],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[43],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[44],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[45],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[46],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[47],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[48],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[49],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[50],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[51],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[52],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[53],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[54],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[55],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[56],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[57],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[58],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[59],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[60],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[61],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[62],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[63],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[64],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[65],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[66],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[67],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[68],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[69],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[70],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[71],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[72],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[73],
  Johnson_71_triaugmented_truncated_dodecahedron_verts[74]
 }
 face_indices {
  146,
  <70, 73, 74>,
  <54, 53, 63>,
  <60, 64, 68>,
  <43, 39, 51>,
  <49, 56, 59>,
  <28, 27, 37>,
  <52, 62, 58>,
  <30, 35, 41>,
  <65, 71, 67>,
  <50, 55, 46>,
  <3, 0, 1>,
  <20, 19, 10>,
  <8, 6, 2>,
  <25, 29, 17>,
  <22, 15, 11>,
  <45, 34, 40>,
  <26, 14, 16>,
  <48, 47, 38>,
  <12, 4, 9>,
  <32, 23, 36>,
  <13, 12, 23>,
  <21, 32, 35>,
  <18, 30, 20>,
  <3, 7, 10>,
  <5, 1, 4>,
  <31, 22, 34>,
  <42, 45, 53>,
  <44, 54, 48>,
  <26, 33, 38>,
  <24, 16, 15>,
  <66, 39, 29>,
  <57, 25, 28>,
  <61, 37, 49>,
  <69, 59, 64>,
  <72, 60, 51>,
  <13, 5, 4>,
  <13, 4, 12>,
  <21, 13, 23>,
  <21, 23, 32>,
  <18, 21, 35>,
  <18, 35, 30>,
  <7, 18, 20>,
  <7, 20, 10>,
  <5, 7, 3>,
  <5, 3, 1>,
  <31, 24, 15>,
  <31, 15, 22>,
  <42, 31, 34>,
  <42, 34, 45>,
  <44, 42, 53>,
  <44, 53, 54>,
  <33, 44, 48>,
  <33, 48, 38>,
  <24, 33, 26>,
  <24, 26, 16>,
  <66, 72, 51>,
  <66, 51, 39>,
  <66, 29, 25>,
  <66, 25, 57>,
  <57, 28, 37>,
  <57, 37, 61>,
  <61, 49, 59>,
  <61, 59, 69>,
  <69, 64, 60>,
  <69, 60, 72>,
  <5, 13, 21>,
  <5, 21, 18>,
  <5, 18, 7>,
  <24, 31, 42>,
  <24, 42, 44>,
  <24, 44, 33>,
  <72, 66, 57>,
  <72, 57, 61>,
  <72, 61, 69>,
  <68, 64, 59>,
  <68, 59, 56>,
  <68, 56, 58>,
  <68, 58, 62>,
  <68, 62, 67>,
  <68, 67, 71>,
  <68, 71, 74>,
  <68, 74, 73>,
  <40, 43, 51>,
  <40, 51, 60>,
  <40, 60, 68>,
  <40, 68, 73>,
  <40, 73, 70>,
  <40, 70, 63>,
  <40, 63, 53>,
  <40, 53, 45>,
  <54, 63, 70>,
  <54, 70, 74>,
  <54, 74, 71>,
  <54, 71, 65>,
  <54, 65, 55>,
  <54, 55, 50>,
  <54, 50, 47>,
  <54, 47, 48>,
  <20, 30, 41>,
  <20, 41, 52>,
  <20, 52, 58>,
  <20, 58, 56>,
  <20, 56, 49>,
  <20, 49, 37>,
  <20, 37, 27>,
  <20, 27, 19>,
  <36, 46, 55>,
  <36, 55, 65>,
  <36, 65, 67>,
  <36, 67, 62>,
  <36, 62, 52>,
  <36, 52, 41>,
  <36, 41, 35>,
  <36, 35, 32>,
  <2, 6, 11>,
  <2, 11, 15>,
  <2, 15, 16>,
  <2, 16, 14>,
  <2, 14, 9>,
  <2, 9, 4>,
  <2, 4, 1>,
  <2, 1, 0>,
  <28, 25, 17>,
  <28, 17, 8>,
  <28, 8, 2>,
  <28, 2, 0>,
  <28, 0, 3>,
  <28, 3, 10>,
  <28, 10, 19>,
  <28, 19, 27>,
  <43, 40, 34>,
  <43, 34, 22>,
  <43, 22, 11>,
  <43, 11, 6>,
  <43, 6, 8>,
  <43, 8, 17>,
  <43, 17, 29>,
  <43, 29, 39>,
  <46, 36, 23>,
  <46, 23, 12>,
  <46, 12, 9>,
  <46, 9, 14>,
  <46, 14, 26>,
  <46, 26, 38>,
  <46, 38, 47>,
  <46, 47, 50>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_71_triaugmented_truncated_dodecahedron_verts[46];
 #local P1 = Johnson_71_triaugmented_truncated_dodecahedron_verts[36];
 #local P2 = Johnson_71_triaugmented_truncated_dodecahedron_verts[23];
 #local P3 = Johnson_71_triaugmented_truncated_dodecahedron_verts[12];
 #local P4 = Johnson_71_triaugmented_truncated_dodecahedron_verts[9];
 #local P5 = Johnson_71_triaugmented_truncated_dodecahedron_verts[14];
 #local P6 = Johnson_71_triaugmented_truncated_dodecahedron_verts[26];
 #local P7 = Johnson_71_triaugmented_truncated_dodecahedron_verts[38];
 #local P8 = Johnson_71_triaugmented_truncated_dodecahedron_verts[47];
 #local P9 = Johnson_71_triaugmented_truncated_dodecahedron_verts[50];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_71_triaugmented_truncated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_71_triaugmented_truncated_dodecahedron_obj }
#end
#end

#macro Johnson_71_triaugmented_truncated_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[0], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[1], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[2], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[3], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[4], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[5], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[6], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[7], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[8], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[9], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[10], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[11], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[12], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[13], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[14], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[15], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[16], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[17], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[18], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[19], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[20], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[21], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[22], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[23], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[24], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[25], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[26], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[27], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[28], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[29], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[30], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[31], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[32], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[33], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[34], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[35], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[36], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[37], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[38], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[39], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[40], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[41], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[42], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[43], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[44], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[45], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[46], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[47], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[48], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[49], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[50], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[51], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[52], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[53], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[54], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[55], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[56], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[57], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[58], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[59], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[60], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[61], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[62], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[63], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[64], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[65], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[66], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[67], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[68], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[69], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[70], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[71], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[72], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[73], RadVer }
  sphere { Johnson_71_triaugmented_truncated_dodecahedron_verts[74], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[70], Johnson_71_triaugmented_truncated_dodecahedron_verts[73], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[73], Johnson_71_triaugmented_truncated_dodecahedron_verts[74], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[74], Johnson_71_triaugmented_truncated_dodecahedron_verts[70], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[54], Johnson_71_triaugmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[53], Johnson_71_triaugmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[63], Johnson_71_triaugmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[60], Johnson_71_triaugmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[64], Johnson_71_triaugmented_truncated_dodecahedron_verts[68], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[68], Johnson_71_triaugmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[43], Johnson_71_triaugmented_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[39], Johnson_71_triaugmented_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[51], Johnson_71_triaugmented_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[49], Johnson_71_triaugmented_truncated_dodecahedron_verts[56], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[56], Johnson_71_triaugmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[59], Johnson_71_triaugmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[28], Johnson_71_triaugmented_truncated_dodecahedron_verts[27], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[27], Johnson_71_triaugmented_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[37], Johnson_71_triaugmented_truncated_dodecahedron_verts[28], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[52], Johnson_71_triaugmented_truncated_dodecahedron_verts[62], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[62], Johnson_71_triaugmented_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[58], Johnson_71_triaugmented_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[30], Johnson_71_triaugmented_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[35], Johnson_71_triaugmented_truncated_dodecahedron_verts[41], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[41], Johnson_71_triaugmented_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[65], Johnson_71_triaugmented_truncated_dodecahedron_verts[71], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[71], Johnson_71_triaugmented_truncated_dodecahedron_verts[67], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[67], Johnson_71_triaugmented_truncated_dodecahedron_verts[65], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[50], Johnson_71_triaugmented_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[55], Johnson_71_triaugmented_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[46], Johnson_71_triaugmented_truncated_dodecahedron_verts[50], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[3], Johnson_71_triaugmented_truncated_dodecahedron_verts[0], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[0], Johnson_71_triaugmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[1], Johnson_71_triaugmented_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[20], Johnson_71_triaugmented_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[19], Johnson_71_triaugmented_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[10], Johnson_71_triaugmented_truncated_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[8], Johnson_71_triaugmented_truncated_dodecahedron_verts[6], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[6], Johnson_71_triaugmented_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[2], Johnson_71_triaugmented_truncated_dodecahedron_verts[8], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[25], Johnson_71_triaugmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[29], Johnson_71_triaugmented_truncated_dodecahedron_verts[17], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[17], Johnson_71_triaugmented_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[22], Johnson_71_triaugmented_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[15], Johnson_71_triaugmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[11], Johnson_71_triaugmented_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[45], Johnson_71_triaugmented_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[34], Johnson_71_triaugmented_truncated_dodecahedron_verts[40], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[40], Johnson_71_triaugmented_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[26], Johnson_71_triaugmented_truncated_dodecahedron_verts[14], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[14], Johnson_71_triaugmented_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[16], Johnson_71_triaugmented_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[48], Johnson_71_triaugmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[47], Johnson_71_triaugmented_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[38], Johnson_71_triaugmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[12], Johnson_71_triaugmented_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[4], Johnson_71_triaugmented_truncated_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[9], Johnson_71_triaugmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[32], Johnson_71_triaugmented_truncated_dodecahedron_verts[23], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[23], Johnson_71_triaugmented_truncated_dodecahedron_verts[36], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[36], Johnson_71_triaugmented_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[13], Johnson_71_triaugmented_truncated_dodecahedron_verts[12], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[12], Johnson_71_triaugmented_truncated_dodecahedron_verts[23], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[23], Johnson_71_triaugmented_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[21], Johnson_71_triaugmented_truncated_dodecahedron_verts[32], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[32], Johnson_71_triaugmented_truncated_dodecahedron_verts[35], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[35], Johnson_71_triaugmented_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[18], Johnson_71_triaugmented_truncated_dodecahedron_verts[30], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[30], Johnson_71_triaugmented_truncated_dodecahedron_verts[20], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[20], Johnson_71_triaugmented_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[3], Johnson_71_triaugmented_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[7], Johnson_71_triaugmented_truncated_dodecahedron_verts[10], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[10], Johnson_71_triaugmented_truncated_dodecahedron_verts[3], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[5], Johnson_71_triaugmented_truncated_dodecahedron_verts[1], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[1], Johnson_71_triaugmented_truncated_dodecahedron_verts[4], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[4], Johnson_71_triaugmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[31], Johnson_71_triaugmented_truncated_dodecahedron_verts[22], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[22], Johnson_71_triaugmented_truncated_dodecahedron_verts[34], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[34], Johnson_71_triaugmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[42], Johnson_71_triaugmented_truncated_dodecahedron_verts[45], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[45], Johnson_71_triaugmented_truncated_dodecahedron_verts[53], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[53], Johnson_71_triaugmented_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[44], Johnson_71_triaugmented_truncated_dodecahedron_verts[54], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[54], Johnson_71_triaugmented_truncated_dodecahedron_verts[48], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[48], Johnson_71_triaugmented_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[26], Johnson_71_triaugmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[33], Johnson_71_triaugmented_truncated_dodecahedron_verts[38], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[38], Johnson_71_triaugmented_truncated_dodecahedron_verts[26], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[24], Johnson_71_triaugmented_truncated_dodecahedron_verts[16], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[16], Johnson_71_triaugmented_truncated_dodecahedron_verts[15], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[15], Johnson_71_triaugmented_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[66], Johnson_71_triaugmented_truncated_dodecahedron_verts[39], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[39], Johnson_71_triaugmented_truncated_dodecahedron_verts[29], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[29], Johnson_71_triaugmented_truncated_dodecahedron_verts[66], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[57], Johnson_71_triaugmented_truncated_dodecahedron_verts[25], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[25], Johnson_71_triaugmented_truncated_dodecahedron_verts[28], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[28], Johnson_71_triaugmented_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[61], Johnson_71_triaugmented_truncated_dodecahedron_verts[37], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[37], Johnson_71_triaugmented_truncated_dodecahedron_verts[49], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[49], Johnson_71_triaugmented_truncated_dodecahedron_verts[61], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[69], Johnson_71_triaugmented_truncated_dodecahedron_verts[59], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[59], Johnson_71_triaugmented_truncated_dodecahedron_verts[64], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[64], Johnson_71_triaugmented_truncated_dodecahedron_verts[69], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[72], Johnson_71_triaugmented_truncated_dodecahedron_verts[60], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[60], Johnson_71_triaugmented_truncated_dodecahedron_verts[51], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[51], Johnson_71_triaugmented_truncated_dodecahedron_verts[72], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[13], Johnson_71_triaugmented_truncated_dodecahedron_verts[5], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[21], Johnson_71_triaugmented_truncated_dodecahedron_verts[13], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[18], Johnson_71_triaugmented_truncated_dodecahedron_verts[21], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[7], Johnson_71_triaugmented_truncated_dodecahedron_verts[18], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[5], Johnson_71_triaugmented_truncated_dodecahedron_verts[7], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[31], Johnson_71_triaugmented_truncated_dodecahedron_verts[24], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[42], Johnson_71_triaugmented_truncated_dodecahedron_verts[31], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[44], Johnson_71_triaugmented_truncated_dodecahedron_verts[42], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[33], Johnson_71_triaugmented_truncated_dodecahedron_verts[44], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[24], Johnson_71_triaugmented_truncated_dodecahedron_verts[33], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[66], Johnson_71_triaugmented_truncated_dodecahedron_verts[72], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[57], Johnson_71_triaugmented_truncated_dodecahedron_verts[66], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[61], Johnson_71_triaugmented_truncated_dodecahedron_verts[57], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[69], Johnson_71_triaugmented_truncated_dodecahedron_verts[61], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[72], Johnson_71_triaugmented_truncated_dodecahedron_verts[69], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[56], Johnson_71_triaugmented_truncated_dodecahedron_verts[58], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[62], Johnson_71_triaugmented_truncated_dodecahedron_verts[67], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[71], Johnson_71_triaugmented_truncated_dodecahedron_verts[74], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[73], Johnson_71_triaugmented_truncated_dodecahedron_verts[68], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[40], Johnson_71_triaugmented_truncated_dodecahedron_verts[43], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[70], Johnson_71_triaugmented_truncated_dodecahedron_verts[63], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[65], Johnson_71_triaugmented_truncated_dodecahedron_verts[55], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[50], Johnson_71_triaugmented_truncated_dodecahedron_verts[47], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[41], Johnson_71_triaugmented_truncated_dodecahedron_verts[52], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[27], Johnson_71_triaugmented_truncated_dodecahedron_verts[19], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[36], Johnson_71_triaugmented_truncated_dodecahedron_verts[46], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[6], Johnson_71_triaugmented_truncated_dodecahedron_verts[11], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[14], Johnson_71_triaugmented_truncated_dodecahedron_verts[9], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[0], Johnson_71_triaugmented_truncated_dodecahedron_verts[2], RadEdg }
  cylinder { Johnson_71_triaugmented_truncated_dodecahedron_verts[17], Johnson_71_triaugmented_truncated_dodecahedron_verts[8], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_71_triaugmented_truncated_dodecahedron_verts[46];
 #local P1 = Johnson_71_triaugmented_truncated_dodecahedron_verts[36];
 #local P2 = Johnson_71_triaugmented_truncated_dodecahedron_verts[23];
 #local P3 = Johnson_71_triaugmented_truncated_dodecahedron_verts[12];
 #local P4 = Johnson_71_triaugmented_truncated_dodecahedron_verts[9];
 #local P5 = Johnson_71_triaugmented_truncated_dodecahedron_verts[14];
 #local P6 = Johnson_71_triaugmented_truncated_dodecahedron_verts[26];
 #local P7 = Johnson_71_triaugmented_truncated_dodecahedron_verts[38];
 #local P8 = Johnson_71_triaugmented_truncated_dodecahedron_verts[47];
 #local P9 = Johnson_71_triaugmented_truncated_dodecahedron_verts[50];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_72_gyrate_rhombicosidodecahedron_verts = array[60]
{
<-0.976612, 0.213547, -0.025026>,
<-0.942883, -0.134569, -0.304734>,
<-0.917763, 0.061996, 0.392261>,
<-0.863187, -0.501268, -0.060316>,
<-0.847662, -0.379783, 0.370450>,
<-0.806942, 0.483006, -0.339927>,
<-0.791417, 0.604490, 0.090839>,
<-0.773213, 0.134890, -0.619635>,
<-0.732567, 0.452939, 0.508126>,
<-0.703113, -0.306889, -0.641445>,
<-0.652871, 0.086241, 0.752543>,
<-0.623417, -0.673588, -0.397028>,
<-0.582771, -0.355538, 0.730732>,
<-0.564567, -0.825138, 0.020258>,
<-0.549042, -0.703654, 0.451025>,
<-0.473560, 0.767450, -0.432161>,
<-0.458035, 0.888934, -0.001394>,
<-0.418985, 0.204186, -0.884738>,
<-0.362814, 0.643719, 0.673789>,
<-0.348885, -0.237593, -0.906548>,
<-0.283118, 0.277021, 0.918206>,
<-0.233790, 0.595129, -0.768872>,
<-0.219935, -0.830923, -0.511073>,
<-0.193143, 0.913179, 0.358888>
<-0.169693, -0.437793, 0.882916>,
<-0.161085, -0.982474, -0.093786>,
<-0.135964, -0.785909, 0.603208>,
<-0.103807, 0.958230, -0.266497>,
<-0.050264, -0.561464, -0.825973>,
<-0.015503, 0.046850, -0.998782>,
<0.015502, -0.046850, 0.998781>,
<0.075132, 0.737294, 0.671381>,
<0.103807, -0.958229, 0.266497>,
<0.135964, 0.785910, -0.603209>,
<0.154828, 0.370596, 0.915798>,
<0.161084, 0.982475, 0.093785>,
<0.169693, 0.437794, -0.882917>,
<0.193143, -0.913178, -0.358889>,
<0.233789, -0.595129, 0.768871>,
<0.283118, -0.277021, -0.918207>,
<0.362813, -0.643719, -0.673790>,
<0.418985, -0.204186, 0.884737>,
<0.429360, 0.806590, 0.406278>,
<0.458035, -0.888933, 0.001394>,
<0.473560, -0.767449, 0.432160>,
<0.549042, 0.703655, -0.451025>,
<0.558311, 0.213260, 0.801754>,
<0.564567, 0.825139, -0.020259>,
<0.582771, 0.355539, -0.730733>,
<0.652871, -0.086240, -0.752544>,
<0.727981, 0.482720, 0.486853>,
<0.732567, -0.452939, -0.508127>,
<0.773213, -0.134890, 0.619634>,
<0.791417, -0.604490, -0.090840>,
<0.806942, -0.483006, 0.339926>,
<0.847662, 0.379784, -0.370451>,
<0.863187, 0.501268, 0.060316>,
<0.917763, -0.061995, -0.392261>,
<0.942883, 0.134570, 0.304733>,
<0.976612, -0.213546, 0.025025>,
}
#declare P0 = Johnson_72_gyrate_rhombicosidodecahedron_verts[22];
#declare P1 = Johnson_72_gyrate_rhombicosidodecahedron_verts[11];
#declare P2 = Johnson_72_gyrate_rhombicosidodecahedron_verts[28];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 60)
 #declare Johnson_72_gyrate_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_72_gyrate_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_72_gyrate_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_72_gyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_72_gyrate_rhombicosidodecahedron_verts[0],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[1],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[2],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[3],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[4],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[5],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[6],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[7],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[8],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[9],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[10],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[11],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[12],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[13],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[14],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[15],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[16],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[17],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[18],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[19],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[20],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[21],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[22],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[23],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[24],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[25],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[26],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[27],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[28],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[29],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[30],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[31],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[32],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[33],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[34],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[35],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[36],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[37],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[38],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[39],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[40],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[41],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[42],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[43],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[44],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[45],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[46],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[47],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[48],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[49],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[50],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[51],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[52],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[53],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[54],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[55],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[56],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[57],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[58],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[59]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  116,
  <48, 45, 55>, 0,
  <35, 42, 47>, 0,
  <23, 18, 31>, 0,
  <20, 30, 34>, 0,
  <49, 57, 51>, 0,
  <59, 54, 53>, 0,
  <56, 50, 58>, 0,
  <46, 41, 52>, 0,
  <39, 40, 28>, 0,
  <37, 25, 22>, 0,
  <43, 44, 32>, 0,
  <38, 24, 26>, 0,
  <29, 19, 17>, 0,
  <9, 1, 7>, 0,
  <11, 13, 3>, 0,
  <14, 12, 4>, 0,
  <36, 21, 33>, 0,
  <15, 16, 27>, 0,
  <5, 0, 6>, 0,
  <2, 10, 8>, 0,
  <36, 33, 45>, 1,
  <36, 45, 48>, 1,
  <45, 47, 56>, 1,
  <45, 56, 55>, 1,
  <47, 42, 50>, 1,
  <47, 50, 56>, 1,
  <23, 31, 42>, 1,
  <23, 42, 35>, 1,
  <18, 20, 34>, 1,
  <18, 34, 31>, 1,
  <34, 30, 41>, 1,
  <34, 41, 46>, 1,
  <48, 55, 57>, 1,
  <48, 57, 49>, 1,
  <57, 59, 53>, 1,
  <57, 53, 51>, 1,
  <53, 54, 44>, 1,
  <53, 44, 43>, 1,
  <58, 52, 54>, 1,
  <58, 54, 59>, 1,
  <50, 46, 52>, 1,
  <50, 52, 58>, 1,
  <41, 30, 24>, 1,
  <41, 24, 38>, 1,
  <49, 51, 40>, 1,
  <49, 40, 39>, 1,
  <40, 37, 22>, 1,
  <40, 22, 28>, 1,
  <22, 25, 13>, 1,
  <22, 13, 11>, 1,
  <43, 32, 25>, 1,
  <43, 25, 37>, 1,
  <44, 38, 26>, 1,
  <44, 26, 32>, 1,
  <26, 24, 12>, 1,
  <26, 12, 14>, 1,
  <39, 28, 19>, 1,
  <39, 19, 29>, 1,
  <19, 9, 7>, 1,
  <19, 7, 17>, 1,
  <7, 1, 0>, 1,
  <7, 0, 5>, 1,
  <11, 3, 1>, 1,
  <11, 1, 9>, 1,
  <13, 14, 4>, 1,
  <13, 4, 3>, 1,
  <4, 12, 10>, 1,
  <4, 10, 2>, 1,
  <29, 17, 21>, 1,
  <29, 21, 36>, 1,
  <21, 15, 27>, 1,
  <21, 27, 33>, 1,
  <27, 16, 23>, 1,
  <27, 23, 35>, 1,
  <5, 6, 16>, 1,
  <5, 16, 15>, 1,
  <0, 2, 8>, 1,
  <0, 8, 6>, 1,
  <8, 10, 20>, 1,
  <8, 20, 18>, 1,
  <33, 27, 35>, 2,
  <33, 35, 47>, 2,
  <33, 47, 45>, 2,
  <31, 34, 46>, 2,
  <31, 46, 50>, 2,
  <31, 50, 42>, 2,
  <55, 56, 58>, 2,
  <55, 58, 59>, 2,
  <55, 59, 57>, 2,
  <52, 41, 38>, 2,
  <52, 38, 44>, 2,
  <52, 44, 54>, 2,
  <51, 53, 43>, 2,
  <51, 43, 37>, 2,
  <51, 37, 40>, 2,
  <32, 26, 14>, 2,
  <32, 14, 13>, 2,
  <32, 13, 25>, 2,
  <28, 22, 11>, 2,
  <28, 11, 9>, 2,
  <28, 9, 19>, 2,
  <3, 4, 2>, 2,
  <3, 2, 0>, 2,
  <3, 0, 1>, 2,
  <17, 7, 5>, 2,
  <17, 5, 15>, 2,
  <17, 15, 21>, 2,
  <6, 8, 18>, 2,
  <6, 18, 23>, 2,
  <6, 23, 16>, 2,
  <36, 48, 49>, 2,
  <36, 49, 39>, 2,
  <36, 39, 29>, 2,
  <10, 12, 24>, 2,
  <10, 24, 30>, 2,
  <10, 30, 20>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_72_gyrate_rhombicosidodecahedron_verts[22];
 #local P1 = Johnson_72_gyrate_rhombicosidodecahedron_verts[11];
 #local P2 = Johnson_72_gyrate_rhombicosidodecahedron_verts[28];
 #local P3 = Johnson_72_gyrate_rhombicosidodecahedron_verts[19];
 #local P4 = Johnson_72_gyrate_rhombicosidodecahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_72_gyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_72_gyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_72_gyrate_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_72_gyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_72_gyrate_rhombicosidodecahedron_verts[0],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[1],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[2],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[3],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[4],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[5],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[6],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[7],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[8],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[9],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[10],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[11],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[12],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[13],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[14],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[15],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[16],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[17],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[18],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[19],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[20],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[21],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[22],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[23],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[24],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[25],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[26],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[27],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[28],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[29],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[30],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[31],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[32],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[33],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[34],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[35],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[36],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[37],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[38],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[39],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[40],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[41],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[42],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[43],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[44],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[45],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[46],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[47],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[48],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[49],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[50],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[51],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[52],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[53],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[54],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[55],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[56],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[57],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[58],
  Johnson_72_gyrate_rhombicosidodecahedron_verts[59]
 }
 face_indices {
  116,
  <48, 45, 55>,
  <35, 42, 47>,
  <23, 18, 31>,
  <20, 30, 34>,
  <49, 57, 51>,
  <59, 54, 53>,
  <56, 50, 58>,
  <46, 41, 52>,
  <39, 40, 28>,
  <37, 25, 22>,
  <43, 44, 32>,
  <38, 24, 26>,
  <29, 19, 17>,
  <9, 1, 7>,
  <11, 13, 3>,
  <14, 12, 4>,
  <36, 21, 33>,
  <15, 16, 27>,
  <5, 0, 6>,
  <2, 10, 8>,
  <36, 33, 45>,
  <36, 45, 48>,
  <45, 47, 56>,
  <45, 56, 55>,
  <47, 42, 50>,
  <47, 50, 56>,
  <23, 31, 42>,
  <23, 42, 35>,
  <18, 20, 34>,
  <18, 34, 31>,
  <34, 30, 41>,
  <34, 41, 46>,
  <48, 55, 57>,
  <48, 57, 49>,
  <57, 59, 53>,
  <57, 53, 51>,
  <53, 54, 44>,
  <53, 44, 43>,
  <58, 52, 54>,
  <58, 54, 59>,
  <50, 46, 52>,
  <50, 52, 58>,
  <41, 30, 24>,
  <41, 24, 38>,
  <49, 51, 40>,
  <49, 40, 39>,
  <40, 37, 22>,
  <40, 22, 28>,
  <22, 25, 13>,
  <22, 13, 11>,
  <43, 32, 25>,
  <43, 25, 37>,
  <44, 38, 26>,
  <44, 26, 32>,
  <26, 24, 12>,
  <26, 12, 14>,
  <39, 28, 19>,
  <39, 19, 29>,
  <19, 9, 7>,
  <19, 7, 17>,
  <7, 1, 0>,
  <7, 0, 5>,
  <11, 3, 1>,
  <11, 1, 9>,
  <13, 14, 4>,
  <13, 4, 3>,
  <4, 12, 10>,
  <4, 10, 2>,
  <29, 17, 21>,
  <29, 21, 36>,
  <21, 15, 27>,
  <21, 27, 33>,
  <27, 16, 23>,
  <27, 23, 35>,
  <5, 6, 16>,
  <5, 16, 15>,
  <0, 2, 8>,
  <0, 8, 6>,
  <8, 10, 20>,
  <8, 20, 18>,
  <33, 27, 35>,
  <33, 35, 47>,
  <33, 47, 45>,
  <31, 34, 46>,
  <31, 46, 50>,
  <31, 50, 42>,
  <55, 56, 58>,
  <55, 58, 59>,
  <55, 59, 57>,
  <52, 41, 38>,
  <52, 38, 44>,
  <52, 44, 54>,
  <51, 53, 43>,
  <51, 43, 37>,
  <51, 37, 40>,
  <32, 26, 14>,
  <32, 14, 13>,
  <32, 13, 25>,
  <28, 22, 11>,
  <28, 11, 9>,
  <28, 9, 19>,
  <3, 4, 2>,
  <3, 2, 0>,
  <3, 0, 1>,
  <17, 7, 5>,
  <17, 5, 15>,
  <17, 15, 21>,
  <6, 8, 18>,
  <6, 18, 23>,
  <6, 23, 16>,
  <36, 48, 49>,
  <36, 49, 39>,
  <36, 39, 29>,
  <10, 12, 24>,
  <10, 24, 30>,
  <10, 30, 20>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_72_gyrate_rhombicosidodecahedron_verts[22];
 #local P1 = Johnson_72_gyrate_rhombicosidodecahedron_verts[11];
 #local P2 = Johnson_72_gyrate_rhombicosidodecahedron_verts[28];
 #local P3 = Johnson_72_gyrate_rhombicosidodecahedron_verts[19];
 #local P4 = Johnson_72_gyrate_rhombicosidodecahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_72_gyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_72_gyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_72_gyrate_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[54], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[55], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[56], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[57], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[58], RadVer }
  sphere { Johnson_72_gyrate_rhombicosidodecahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[48], Johnson_72_gyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[45], Johnson_72_gyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[55], Johnson_72_gyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[35], Johnson_72_gyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[42], Johnson_72_gyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[47], Johnson_72_gyrate_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[23], Johnson_72_gyrate_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[18], Johnson_72_gyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[31], Johnson_72_gyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[20], Johnson_72_gyrate_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[30], Johnson_72_gyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[34], Johnson_72_gyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[49], Johnson_72_gyrate_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[57], Johnson_72_gyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[51], Johnson_72_gyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[59], Johnson_72_gyrate_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[54], Johnson_72_gyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[53], Johnson_72_gyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[56], Johnson_72_gyrate_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[50], Johnson_72_gyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[58], Johnson_72_gyrate_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[46], Johnson_72_gyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[41], Johnson_72_gyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[52], Johnson_72_gyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[39], Johnson_72_gyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[40], Johnson_72_gyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[28], Johnson_72_gyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[37], Johnson_72_gyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[25], Johnson_72_gyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[22], Johnson_72_gyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[43], Johnson_72_gyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[44], Johnson_72_gyrate_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[32], Johnson_72_gyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[38], Johnson_72_gyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[24], Johnson_72_gyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[26], Johnson_72_gyrate_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[29], Johnson_72_gyrate_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[19], Johnson_72_gyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[17], Johnson_72_gyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[9], Johnson_72_gyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[1], Johnson_72_gyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[7], Johnson_72_gyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[11], Johnson_72_gyrate_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[13], Johnson_72_gyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[3], Johnson_72_gyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[14], Johnson_72_gyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[12], Johnson_72_gyrate_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[4], Johnson_72_gyrate_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[36], Johnson_72_gyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[21], Johnson_72_gyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[33], Johnson_72_gyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[15], Johnson_72_gyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[16], Johnson_72_gyrate_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[27], Johnson_72_gyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[5], Johnson_72_gyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[0], Johnson_72_gyrate_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[6], Johnson_72_gyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[2], Johnson_72_gyrate_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[10], Johnson_72_gyrate_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[8], Johnson_72_gyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[33], Johnson_72_gyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[48], Johnson_72_gyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[45], Johnson_72_gyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[47], Johnson_72_gyrate_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[56], Johnson_72_gyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[42], Johnson_72_gyrate_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[31], Johnson_72_gyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[35], Johnson_72_gyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[18], Johnson_72_gyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[34], Johnson_72_gyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[30], Johnson_72_gyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[46], Johnson_72_gyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[55], Johnson_72_gyrate_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[49], Johnson_72_gyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[57], Johnson_72_gyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[53], Johnson_72_gyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[54], Johnson_72_gyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[43], Johnson_72_gyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[58], Johnson_72_gyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[52], Johnson_72_gyrate_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[59], Johnson_72_gyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[50], Johnson_72_gyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[30], Johnson_72_gyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[38], Johnson_72_gyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[51], Johnson_72_gyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[39], Johnson_72_gyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[40], Johnson_72_gyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[22], Johnson_72_gyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[25], Johnson_72_gyrate_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[11], Johnson_72_gyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[32], Johnson_72_gyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[37], Johnson_72_gyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[44], Johnson_72_gyrate_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[26], Johnson_72_gyrate_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[24], Johnson_72_gyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[14], Johnson_72_gyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[28], Johnson_72_gyrate_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[29], Johnson_72_gyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[19], Johnson_72_gyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[7], Johnson_72_gyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[1], Johnson_72_gyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[5], Johnson_72_gyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[3], Johnson_72_gyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[9], Johnson_72_gyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[13], Johnson_72_gyrate_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[4], Johnson_72_gyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[12], Johnson_72_gyrate_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[2], Johnson_72_gyrate_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[17], Johnson_72_gyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[36], Johnson_72_gyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[21], Johnson_72_gyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[27], Johnson_72_gyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[16], Johnson_72_gyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[35], Johnson_72_gyrate_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[6], Johnson_72_gyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[15], Johnson_72_gyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[0], Johnson_72_gyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[8], Johnson_72_gyrate_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[10], Johnson_72_gyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_72_gyrate_rhombicosidodecahedron_verts[18], Johnson_72_gyrate_rhombicosidodecahedron_verts[8], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_72_gyrate_rhombicosidodecahedron_verts[22];
 #local P1 = Johnson_72_gyrate_rhombicosidodecahedron_verts[11];
 #local P2 = Johnson_72_gyrate_rhombicosidodecahedron_verts[28];
 #local P3 = Johnson_72_gyrate_rhombicosidodecahedron_verts[19];
 #local P4 = Johnson_72_gyrate_rhombicosidodecahedron_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_73_parabigyrate_rhombicosidodecahedron_verts = array[60]
{
<-0.984691, 0.125192, 0.121281>,
<-0.957572, -0.075612, -0.278094>,
<-0.942455, -0.319982, 0.096891>,
<-0.856557, 0.512005, -0.064506>,
<-0.832097, 0.116607, 0.542233>,
<-0.829438, 0.311200, -0.463882>,
<-0.789861, -0.328568, 0.517842>,
<-0.761099, -0.409107, -0.503346>,
<-0.745982, -0.653477, -0.128361>,
<-0.624772, 0.742482, 0.241623>,
<-0.609655, 0.498112, 0.616608>,
<-0.606996, 0.692705, -0.389506>,
<-0.558076, -0.098091, 0.823971>,
<-0.553774, 0.216768, -0.803956>,
<-0.511538, -0.228406, -0.828346>,
<-0.499080, -0.667369, 0.552753>,
<-0.471962, -0.868174, 0.153378>,
<-0.405520, -0.630422, -0.661906>,
<-0.390403, -0.874792, -0.286921>,
<-0.375211, 0.923183, -0.083378>,
<-0.335634, 0.283415, 0.898346>,
<-0.331332, 0.598273, -0.729581>,
<-0.287416, 0.797110, 0.531045>,
<-0.267295, -0.436892, 0.858882>
<-0.134858, 0.264778, -0.954832>,
<-0.092623, -0.180396, -0.979223>,
<-0.070822, -0.770387, 0.633630>,
<-0.043703, -0.971192, 0.234255>,
<-0.037854, 0.977811, 0.206045>,
<-0.013394, 0.582413, 0.812784>,
<0.013396, -0.582411, -0.812783>,
<0.037856, -0.977809, -0.206044>,
<0.043705, 0.971193, -0.234254>,
<0.070824, 0.770388, -0.633630>,
<0.092624, 0.180397, 0.979223>,
<0.134860, -0.264777, 0.954833>,
<0.267297, 0.436893, -0.858881>,
<0.287417, -0.797109, -0.531044>,
<0.331333, -0.598272, 0.729581>,
<0.335635, -0.283414, -0.898346>,
<0.375212, -0.923181, 0.083378>,
<0.390404, 0.874793, 0.286922>,
<0.405521, 0.630423, 0.661907>,
<0.471963, 0.868175, -0.153377>,
<0.499082, 0.667370, -0.552753>,
<0.511539, 0.228408, 0.828347>,
<0.553775, -0.216766, 0.803957>,
<0.558078, 0.098092, -0.823971>,
<0.606997, -0.692704, 0.389507>,
<0.609656, -0.498111, -0.616607>,
<0.624773, -0.742480, -0.241622>,
<0.745984, 0.653478, 0.128361>,
<0.761101, 0.409108, 0.503346>,
<0.789863, 0.328569, -0.517842>,
<0.829440, -0.311199, 0.463882>,
<0.832099, -0.116605, -0.542232>,
<0.856558, -0.512003, 0.064507>,
<0.942457, 0.319983, -0.096890>,
<0.957574, 0.075614, 0.278095>,
<0.984692, -0.125191, -0.121281>,
}
#declare P0 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29];
#declare P1 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42];
#declare P2 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 60)
 #declare Johnson_73_parabigyrate_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_73_parabigyrate_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_73_parabigyrate_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_73_parabigyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[0],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[1],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[2],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[3],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[4],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[5],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[6],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[7],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[8],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[9],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[10],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[11],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[12],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[13],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[14],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[15],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[16],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[17],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[18],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[19],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[20],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[21],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[23],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[24],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[25],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[26],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[27],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[30],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[31],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[32],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[33],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[34],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[35],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[36],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[37],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[38],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[39],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[40],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[43],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[44],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[45],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[46],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[47],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[48],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[49],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[50],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[51],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[52],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[53],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[54],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[55],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[56],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[57],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[58],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[59]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  116,
  <36, 33, 44>, 0,
  <19, 28, 32>, 0,
  <9, 10, 22>, 0,
  <20, 34, 29>, 0,
  <47, 53, 55>, 0,
  <57, 58, 59>, 0,
  <43, 41, 51>, 0,
  <42, 45, 52>, 0,
  <49, 50, 37>, 0,
  <40, 27, 31>, 0,
  <56, 54, 48>, 0,
  <46, 35, 38>, 0,
  <39, 30, 25>, 0,
  <17, 7, 14>, 0,
  <18, 16, 8>, 0,
  <26, 23, 15>, 0,
  <24, 13, 21>, 0,
  <5, 3, 11>, 0,
  <1, 2, 0>, 0,
  <6, 12, 4>, 0,
  <24, 21, 33>, 1,
  <24, 33, 36>, 1,
  <33, 32, 43>, 1,
  <33, 43, 44>, 1,
  <32, 28, 41>, 1,
  <32, 41, 43>, 1,
  <9, 22, 28>, 1,
  <9, 28, 19>, 1,
  <10, 20, 29>, 1,
  <10, 29, 22>, 1,
  <29, 34, 45>, 1,
  <29, 45, 42>, 1,
  <36, 44, 53>, 1,
  <36, 53, 47>, 1,
  <53, 57, 59>, 1,
  <53, 59, 55>, 1,
  <59, 58, 54>, 1,
  <59, 54, 56>, 1,
  <51, 52, 58>, 1,
  <51, 58, 57>, 1,
  <41, 42, 52>, 1,
  <41, 52, 51>, 1,
  <45, 34, 35>, 1,
  <45, 35, 46>, 1,
  <47, 55, 49>, 1,
  <47, 49, 39>, 1,
  <50, 40, 31>, 1,
  <50, 31, 37>, 1,
  <31, 27, 16>, 1,
  <31, 16, 18>, 1,
  <56, 48, 40>, 1,
  <56, 40, 50>, 1,
  <54, 46, 38>, 1,
  <54, 38, 48>, 1,
  <38, 35, 23>, 1,
  <38, 23, 26>, 1,
  <49, 37, 30>, 1,
  <49, 30, 39>, 1,
  <30, 17, 14>, 1,
  <30, 14, 25>, 1,
  <7, 8, 2>, 1,
  <7, 2, 1>, 1,
  <18, 8, 7>, 1,
  <18, 7, 17>, 1,
  <27, 26, 15>, 1,
  <27, 15, 16>, 1,
  <15, 23, 12>, 1,
  <15, 12, 6>, 1,
  <25, 14, 13>, 1,
  <25, 13, 24>, 1,
  <13, 5, 11>, 1,
  <13, 11, 21>, 1,
  <11, 3, 9>, 1,
  <11, 9, 19>, 1,
  <1, 0, 3>, 1,
  <1, 3, 5>, 1,
  <2, 6, 4>, 1,
  <2, 4, 0>, 1,
  <4, 12, 20>, 1,
  <4, 20, 10>, 1,
  <21, 11, 19>, 2,
  <21, 19, 32>, 2,
  <21, 32, 33>, 2,
  <22, 29, 42>, 2,
  <22, 42, 41>, 2,
  <22, 41, 28>, 2,
  <44, 43, 51>, 2,
  <44, 51, 57>, 2,
  <44, 57, 53>, 2,
  <52, 45, 46>, 2,
  <52, 46, 54>, 2,
  <52, 54, 58>, 2,
  <55, 59, 56>, 2,
  <55, 56, 50>, 2,
  <55, 50, 49>, 2,
  <48, 38, 26>, 2,
  <48, 26, 27>, 2,
  <48, 27, 40>, 2,
  <37, 31, 18>, 2,
  <37, 18, 17>, 2,
  <37, 17, 30>, 2,
  <16, 15, 6>, 2,
  <16, 6, 2>, 2,
  <16, 2, 8>, 2,
  <14, 7, 1>, 2,
  <14, 1, 5>, 2,
  <14, 5, 13>, 2,
  <0, 4, 10>, 2,
  <0, 10, 9>, 2,
  <0, 9, 3>, 2,
  <24, 36, 47>, 2,
  <24, 47, 39>, 2,
  <24, 39, 25>, 2,
  <12, 23, 35>, 2,
  <12, 35, 34>, 2,
  <12, 34, 20>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29];
 #local P1 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42];
 #local P2 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22];
 #local P3 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41];
 #local P4 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_73_parabigyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_73_parabigyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_73_parabigyrate_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_73_parabigyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[0],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[1],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[2],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[3],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[4],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[5],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[6],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[7],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[8],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[9],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[10],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[11],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[12],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[13],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[14],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[15],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[16],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[17],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[18],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[19],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[20],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[21],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[23],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[24],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[25],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[26],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[27],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[30],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[31],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[32],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[33],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[34],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[35],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[36],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[37],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[38],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[39],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[40],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[43],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[44],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[45],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[46],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[47],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[48],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[49],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[50],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[51],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[52],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[53],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[54],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[55],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[56],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[57],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[58],
  Johnson_73_parabigyrate_rhombicosidodecahedron_verts[59]
 }
 face_indices {
  116,
  <36, 33, 44>,
  <19, 28, 32>,
  <9, 10, 22>,
  <20, 34, 29>,
  <47, 53, 55>,
  <57, 58, 59>,
  <43, 41, 51>,
  <42, 45, 52>,
  <49, 50, 37>,
  <40, 27, 31>,
  <56, 54, 48>,
  <46, 35, 38>,
  <39, 30, 25>,
  <17, 7, 14>,
  <18, 16, 8>,
  <26, 23, 15>,
  <24, 13, 21>,
  <5, 3, 11>,
  <1, 2, 0>,
  <6, 12, 4>,
  <24, 21, 33>,
  <24, 33, 36>,
  <33, 32, 43>,
  <33, 43, 44>,
  <32, 28, 41>,
  <32, 41, 43>,
  <9, 22, 28>,
  <9, 28, 19>,
  <10, 20, 29>,
  <10, 29, 22>,
  <29, 34, 45>,
  <29, 45, 42>,
  <36, 44, 53>,
  <36, 53, 47>,
  <53, 57, 59>,
  <53, 59, 55>,
  <59, 58, 54>,
  <59, 54, 56>,
  <51, 52, 58>,
  <51, 58, 57>,
  <41, 42, 52>,
  <41, 52, 51>,
  <45, 34, 35>,
  <45, 35, 46>,
  <47, 55, 49>,
  <47, 49, 39>,
  <50, 40, 31>,
  <50, 31, 37>,
  <31, 27, 16>,
  <31, 16, 18>,
  <56, 48, 40>,
  <56, 40, 50>,
  <54, 46, 38>,
  <54, 38, 48>,
  <38, 35, 23>,
  <38, 23, 26>,
  <49, 37, 30>,
  <49, 30, 39>,
  <30, 17, 14>,
  <30, 14, 25>,
  <7, 8, 2>,
  <7, 2, 1>,
  <18, 8, 7>,
  <18, 7, 17>,
  <27, 26, 15>,
  <27, 15, 16>,
  <15, 23, 12>,
  <15, 12, 6>,
  <25, 14, 13>,
  <25, 13, 24>,
  <13, 5, 11>,
  <13, 11, 21>,
  <11, 3, 9>,
  <11, 9, 19>,
  <1, 0, 3>,
  <1, 3, 5>,
  <2, 6, 4>,
  <2, 4, 0>,
  <4, 12, 20>,
  <4, 20, 10>,
  <21, 11, 19>,
  <21, 19, 32>,
  <21, 32, 33>,
  <22, 29, 42>,
  <22, 42, 41>,
  <22, 41, 28>,
  <44, 43, 51>,
  <44, 51, 57>,
  <44, 57, 53>,
  <52, 45, 46>,
  <52, 46, 54>,
  <52, 54, 58>,
  <55, 59, 56>,
  <55, 56, 50>,
  <55, 50, 49>,
  <48, 38, 26>,
  <48, 26, 27>,
  <48, 27, 40>,
  <37, 31, 18>,
  <37, 18, 17>,
  <37, 17, 30>,
  <16, 15, 6>,
  <16, 6, 2>,
  <16, 2, 8>,
  <14, 7, 1>,
  <14, 1, 5>,
  <14, 5, 13>,
  <0, 4, 10>,
  <0, 10, 9>,
  <0, 9, 3>,
  <24, 36, 47>,
  <24, 47, 39>,
  <24, 39, 25>,
  <12, 23, 35>,
  <12, 35, 34>,
  <12, 34, 20>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29];
 #local P1 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42];
 #local P2 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22];
 #local P3 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41];
 #local P4 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_73_parabigyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_73_parabigyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_73_parabigyrate_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[54], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[55], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[56], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[57], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[58], RadVer }
  sphere { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[36], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[33], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[44], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[19], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[32], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[9], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[10], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[20], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[34], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[47], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[53], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[55], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[57], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[58], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[59], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[43], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[51], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[45], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[52], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[49], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[50], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[37], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[40], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[27], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[31], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[56], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[54], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[48], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[46], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[35], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[38], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[39], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[30], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[25], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[17], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[7], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[14], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[18], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[16], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[8], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[26], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[23], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[15], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[24], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[13], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[21], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[5], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[3], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[11], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[1], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[2], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[0], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[6], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[12], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[4], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[21], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[36], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[33], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[32], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[43], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[19], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[10], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[34], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[44], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[47], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[53], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[59], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[58], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[56], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[51], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[52], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[57], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[34], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[46], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[55], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[49], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[39], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[50], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[31], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[27], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[18], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[48], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[50], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[54], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[38], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[35], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[26], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[37], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[30], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[14], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[7], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[8], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[1], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[17], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[27], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[15], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[23], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[6], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[14], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[24], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[13], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[11], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[3], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[19], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[0], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[5], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[2], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[4], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[12], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_73_parabigyrate_rhombicosidodecahedron_verts[10], Johnson_73_parabigyrate_rhombicosidodecahedron_verts[4], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[29];
 #local P1 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[42];
 #local P2 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[22];
 #local P3 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[41];
 #local P4 = Johnson_73_parabigyrate_rhombicosidodecahedron_verts[28];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_74_metabigyrate_rhombicosidodecahedron_verts = array[60]
{
<-0.966046, -0.051368, 0.253213>,
<-0.952290, 0.304660, -0.018105>,
<-0.940892, -0.323000, -0.101952>,
<-0.927135, 0.033028, -0.373270>,
<-0.826492, -0.473879, 0.303890>,
<-0.790478, 0.458215, -0.406430>,
<-0.767188, 0.060532, 0.638560>,
<-0.744929, 0.636598, 0.199559>,
<-0.701332, -0.650609, -0.291274>,
<-0.679074, -0.074543, -0.730275>,
<-0.630530, 0.485719, 0.605400>,
<-0.627634, -0.361979, 0.689237>,
<-0.586933, -0.801488, 0.114568>,
<-0.583117, 0.790154, -0.188766>,
<-0.542416, 0.350644, -0.763435>,
<-0.539520, -0.497054, -0.679599>,
<-0.420274, -0.030040, 0.906900>,
<-0.397364, 0.817911, 0.416083>,
<-0.338872, -0.909059, -0.242438>,
<-0.302857, 0.023036, -0.952757>,
<-0.283617, 0.395147, 0.873740>,
<-0.265174, -0.620429, 0.738072>,
<-0.240019, -0.892061, 0.382907>,
<-0.235552, 0.971466, 0.027758>
<-0.206901, 0.887732, -0.411248>,
<-0.181746, 0.616100, -0.766413>,
<-0.177060, -0.755504, -0.630763>,
<-0.163303, -0.399475, -0.902081>,
<-0.057814, -0.288491, 0.955736>,
<-0.050450, 0.727338, 0.684423>,
<0.008042, -0.999632, 0.025902>,
<0.057813, 0.288491, -0.955736>,
<0.163303, 0.399477, 0.902082>,
<0.181745, -0.616099, 0.766414>,
<0.206900, -0.887731, 0.411249>,
<0.211368, 0.975796, 0.056100>,
<0.240019, 0.892062, -0.382907>,
<0.265173, 0.620430, -0.738072>,
<0.269860, -0.751174, -0.602422>,
<0.283616, -0.395146, -0.873739>,
<0.302857, -0.023034, 0.952758>,
<0.325767, 0.824917, 0.461941>,
<0.384259, -0.902053, -0.196580>,
<0.420273, 0.030041, -0.906900>,
<0.539519, 0.497055, 0.679600>,
<0.542416, -0.350643, 0.763436>,
<0.583117, -0.790152, 0.188767>,
<0.586933, 0.801489, -0.114567>,
<0.627634, 0.361980, -0.689236>,
<0.658347, -0.625824, -0.418238>,
<0.672103, -0.269795, -0.689555>,
<0.679073, 0.074544, 0.730276>,
<0.701332, 0.650610, 0.291275>,
<0.790477, -0.458214, 0.406430>,
<0.826492, 0.473881, -0.303889>,
<0.857205, -0.513923, -0.032890>,
<0.879463, 0.062143, -0.471892>,
<0.927134, -0.033027, 0.373270>,
<0.940891, 0.323002, 0.101953>,
<0.993863, -0.088736, -0.066050>,
}
#declare P0 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16];
#declare P1 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28];
#declare P2 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 60)
 #declare Johnson_74_metabigyrate_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_74_metabigyrate_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_74_metabigyrate_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_74_metabigyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[0],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[1],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[2],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[3],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[4],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[5],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[6],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[7],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[8],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[9],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[10],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[11],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[12],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[13],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[14],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[15],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[17],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[18],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[19],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[21],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[22],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[23],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[24],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[25],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[26],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[27],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[29],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[30],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[31],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[33],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[34],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[35],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[36],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[37],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[38],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[39],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[41],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[42],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[43],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[44],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[45],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[46],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[47],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[48],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[49],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[50],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[51],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[52],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[53],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[54],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[55],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[56],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[57],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[58],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[59]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  116,
  <31, 25, 37>, 0,
  <13, 23, 24>, 0,
  <7, 10, 17>, 0,
  <20, 32, 29>, 0,
  <48, 54, 56>, 0,
  <58, 57, 59>, 0,
  <36, 35, 47>, 0,
  <41, 44, 52>, 0,
  <43, 50, 39>, 0,
  <49, 42, 38>, 0,
  <55, 53, 46>, 0,
  <51, 40, 45>, 0,
  <27, 26, 15>, 0,
  <18, 12, 8>, 0,
  <30, 34, 22>, 0,
  <33, 28, 21>, 0,
  <19, 9, 14>, 0,
  <3, 1, 5>, 0,
  <2, 4, 0>, 0,
  <11, 16, 6>, 0,
  <19, 14, 25>, 1,
  <19, 25, 31>, 1,
  <25, 24, 36>, 1,
  <25, 36, 37>, 1,
  <24, 23, 35>, 1,
  <24, 35, 36>, 1,
  <7, 17, 23>, 1,
  <7, 23, 13>, 1,
  <10, 20, 29>, 1,
  <10, 29, 17>, 1,
  <29, 32, 44>, 1,
  <29, 44, 41>, 1,
  <31, 37, 48>, 1,
  <31, 48, 43>, 1,
  <54, 58, 59>, 1,
  <54, 59, 56>, 1,
  <59, 57, 53>, 1,
  <59, 53, 55>, 1,
  <47, 52, 58>, 1,
  <47, 58, 54>, 1,
  <35, 41, 52>, 1,
  <35, 52, 47>, 1,
  <44, 32, 40>, 1,
  <44, 40, 51>, 1,
  <48, 56, 50>, 1,
  <48, 50, 43>, 1,
  <50, 49, 38>, 1,
  <50, 38, 39>, 1,
  <42, 46, 34>, 1,
  <42, 34, 30>, 1,
  <55, 46, 42>, 1,
  <55, 42, 49>, 1,
  <57, 51, 45>, 1,
  <57, 45, 53>, 1,
  <45, 40, 28>, 1,
  <45, 28, 33>, 1,
  <39, 38, 26>, 1,
  <39, 26, 27>, 1,
  <26, 18, 8>, 1,
  <26, 8, 15>, 1,
  <8, 12, 4>, 1,
  <8, 4, 2>, 1,
  <30, 22, 12>, 1,
  <30, 12, 18>, 1,
  <34, 33, 21>, 1,
  <34, 21, 22>, 1,
  <21, 28, 16>, 1,
  <21, 16, 11>, 1,
  <27, 15, 9>, 1,
  <27, 9, 19>, 1,
  <9, 3, 5>, 1,
  <9, 5, 14>, 1,
  <5, 1, 7>, 1,
  <5, 7, 13>, 1,
  <2, 0, 1>, 1,
  <2, 1, 3>, 1,
  <4, 11, 6>, 1,
  <4, 6, 0>, 1,
  <6, 16, 20>, 1,
  <6, 20, 10>, 1,
  <14, 5, 13>, 2,
  <14, 13, 24>, 2,
  <14, 24, 25>, 2,
  <17, 29, 41>, 2,
  <17, 41, 35>, 2,
  <17, 35, 23>, 2,
  <37, 36, 47>, 2,
  <37, 47, 54>, 2,
  <37, 54, 48>, 2,
  <52, 44, 51>, 2,
  <52, 51, 57>, 2,
  <52, 57, 58>, 2,
  <56, 59, 55>, 2,
  <56, 55, 49>, 2,
  <56, 49, 50>, 2,
  <53, 45, 33>, 2,
  <53, 33, 34>, 2,
  <53, 34, 46>, 2,
  <38, 42, 30>, 2,
  <38, 30, 18>, 2,
  <38, 18, 26>, 2,
  <22, 21, 11>, 2,
  <22, 11, 4>, 2,
  <22, 4, 12>, 2,
  <15, 8, 2>, 2,
  <15, 2, 3>, 2,
  <15, 3, 9>, 2,
  <0, 6, 10>, 2,
  <0, 10, 7>, 2,
  <0, 7, 1>, 2,
  <19, 31, 43>, 2,
  <19, 43, 39>, 2,
  <19, 39, 27>, 2,
  <16, 28, 40>, 2,
  <16, 40, 32>, 2,
  <16, 32, 20>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16];
 #local P1 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28];
 #local P2 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40];
 #local P3 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32];
 #local P4 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_74_metabigyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_74_metabigyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_74_metabigyrate_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_74_metabigyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[0],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[1],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[2],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[3],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[4],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[5],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[6],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[7],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[8],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[9],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[10],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[11],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[12],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[13],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[14],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[15],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[17],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[18],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[19],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[21],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[22],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[23],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[24],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[25],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[26],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[27],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[29],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[30],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[31],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[33],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[34],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[35],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[36],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[37],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[38],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[39],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[41],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[42],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[43],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[44],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[45],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[46],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[47],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[48],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[49],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[50],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[51],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[52],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[53],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[54],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[55],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[56],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[57],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[58],
  Johnson_74_metabigyrate_rhombicosidodecahedron_verts[59]
 }
 face_indices {
  116,
  <31, 25, 37>,
  <13, 23, 24>,
  <7, 10, 17>,
  <20, 32, 29>,
  <48, 54, 56>,
  <58, 57, 59>,
  <36, 35, 47>,
  <41, 44, 52>,
  <43, 50, 39>,
  <49, 42, 38>,
  <55, 53, 46>,
  <51, 40, 45>,
  <27, 26, 15>,
  <18, 12, 8>,
  <30, 34, 22>,
  <33, 28, 21>,
  <19, 9, 14>,
  <3, 1, 5>,
  <2, 4, 0>,
  <11, 16, 6>,
  <19, 14, 25>,
  <19, 25, 31>,
  <25, 24, 36>,
  <25, 36, 37>,
  <24, 23, 35>,
  <24, 35, 36>,
  <7, 17, 23>,
  <7, 23, 13>,
  <10, 20, 29>,
  <10, 29, 17>,
  <29, 32, 44>,
  <29, 44, 41>,
  <31, 37, 48>,
  <31, 48, 43>,
  <54, 58, 59>,
  <54, 59, 56>,
  <59, 57, 53>,
  <59, 53, 55>,
  <47, 52, 58>,
  <47, 58, 54>,
  <35, 41, 52>,
  <35, 52, 47>,
  <44, 32, 40>,
  <44, 40, 51>,
  <48, 56, 50>,
  <48, 50, 43>,
  <50, 49, 38>,
  <50, 38, 39>,
  <42, 46, 34>,
  <42, 34, 30>,
  <55, 46, 42>,
  <55, 42, 49>,
  <57, 51, 45>,
  <57, 45, 53>,
  <45, 40, 28>,
  <45, 28, 33>,
  <39, 38, 26>,
  <39, 26, 27>,
  <26, 18, 8>,
  <26, 8, 15>,
  <8, 12, 4>,
  <8, 4, 2>,
  <30, 22, 12>,
  <30, 12, 18>,
  <34, 33, 21>,
  <34, 21, 22>,
  <21, 28, 16>,
  <21, 16, 11>,
  <27, 15, 9>,
  <27, 9, 19>,
  <9, 3, 5>,
  <9, 5, 14>,
  <5, 1, 7>,
  <5, 7, 13>,
  <2, 0, 1>,
  <2, 1, 3>,
  <4, 11, 6>,
  <4, 6, 0>,
  <6, 16, 20>,
  <6, 20, 10>,
  <14, 5, 13>,
  <14, 13, 24>,
  <14, 24, 25>,
  <17, 29, 41>,
  <17, 41, 35>,
  <17, 35, 23>,
  <37, 36, 47>,
  <37, 47, 54>,
  <37, 54, 48>,
  <52, 44, 51>,
  <52, 51, 57>,
  <52, 57, 58>,
  <56, 59, 55>,
  <56, 55, 49>,
  <56, 49, 50>,
  <53, 45, 33>,
  <53, 33, 34>,
  <53, 34, 46>,
  <38, 42, 30>,
  <38, 30, 18>,
  <38, 18, 26>,
  <22, 21, 11>,
  <22, 11, 4>,
  <22, 4, 12>,
  <15, 8, 2>,
  <15, 2, 3>,
  <15, 3, 9>,
  <0, 6, 10>,
  <0, 10, 7>,
  <0, 7, 1>,
  <19, 31, 43>,
  <19, 43, 39>,
  <19, 39, 27>,
  <16, 28, 40>,
  <16, 40, 32>,
  <16, 32, 20>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16];
 #local P1 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28];
 #local P2 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40];
 #local P3 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32];
 #local P4 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_74_metabigyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_74_metabigyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_74_metabigyrate_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[54], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[55], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[56], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[57], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[58], RadVer }
  sphere { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[31], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[25], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[37], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[13], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[23], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[24], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[7], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[10], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[17], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[29], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[48], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[54], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[56], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[58], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[57], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[59], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[36], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[35], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[47], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[41], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[44], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[52], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[43], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[50], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[39], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[49], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[42], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[38], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[55], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[53], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[46], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[51], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[45], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[27], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[26], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[15], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[18], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[12], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[8], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[30], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[34], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[22], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[33], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[21], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[19], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[9], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[14], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[3], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[1], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[5], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[2], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[4], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[0], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[11], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[6], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[14], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[31], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[25], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[24], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[36], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[23], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[17], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[13], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[10], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[29], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[41], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[37], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[48], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[43], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[54], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[59], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[57], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[55], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[47], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[52], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[54], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[35], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[51], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[56], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[50], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[38], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[42], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[46], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[30], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[49], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[57], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[45], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[33], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[38], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[27], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[26], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[8], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[12], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[2], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[22], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[18], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[34], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[21], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[11], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[15], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[19], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[9], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[5], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[1], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[13], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[0], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[3], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[4], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[6], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_74_metabigyrate_rhombicosidodecahedron_verts[10], Johnson_74_metabigyrate_rhombicosidodecahedron_verts[6], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[16];
 #local P1 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[28];
 #local P2 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[40];
 #local P3 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[32];
 #local P4 = Johnson_74_metabigyrate_rhombicosidodecahedron_verts[20];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_75_trigyrate_rhombicosidodecahedron_verts = array[60]
{
<-0.980376, -0.197048, -0.005857>,
<-0.946332, 0.150802, -0.285858>,
<-0.935804, 0.079716, 0.343390>,
<-0.901759, 0.427566, 0.063389>,
<-0.812124, -0.532510, 0.238510>,
<-0.804800, -0.555655, -0.208670>,
<-0.767552, -0.255746, 0.587757>,
<-0.759203, 0.553784, -0.341957>,
<-0.749715, 0.007177, -0.661721>,
<-0.688108, 0.168923, 0.705672>,
<-0.662244, -0.429437, -0.614016>,
<-0.633023, 0.731755, 0.252621>,
<-0.562586, 0.410160, -0.717820>,
<-0.500979, 0.571905, 0.649573>,
<-0.490467, 0.857973, -0.152725>,
<-0.483464, -0.835984, 0.259599>,
<-0.476140, -0.859129, -0.187580>,
<-0.411344, -0.388171, 0.824694>,
<-0.387011, 0.051553, -0.920632>,
<-0.333584, -0.732911, -0.592926>,
<-0.331901, 0.036498, 0.942608>,
<-0.299539, -0.385062, -0.872928>,
<-0.245677, 0.868112, 0.431306>,
<-0.235768, -0.746778, 0.621881>
<-0.172335, 0.625585, -0.760884>,
<-0.144772, 0.439480, 0.886510>,
<-0.127762, 0.902348, -0.411637>,
<-0.119933, -0.991554, 0.049356>,
<-0.103121, 0.994331, 0.025960>,
<-0.003241, -0.266976, 0.963698>,
<0.003241, 0.266978, -0.963697>,
<0.110530, 0.735688, 0.668243>,
<0.110728, -0.787329, -0.606508>,
<0.127763, -0.902347, 0.411638>,
<0.144773, -0.439479, -0.886509>,
<0.172335, -0.625583, 0.760885>,
<0.242772, -0.947178, -0.209555>,
<0.271977, 0.571167, -0.774465>,
<0.299540, 0.385063, 0.872928>,
<0.316550, 0.847931, -0.425218>,
<0.331901, -0.036497, -0.942608>,
<0.341191, 0.939913, 0.012379>,
<0.387011, -0.051552, 0.920633>,
<0.473235, 0.780063, 0.409331>,
<0.490467, -0.857972, 0.152726>,
<0.528066, -0.712229, -0.462467>,
<0.562111, -0.364379, -0.742468>,
<0.562587, -0.410159, 0.717821>,
<0.600637, 0.267692, -0.753376>,
<0.662244, 0.429438, 0.614017>,
<0.672757, 0.715506, -0.188282>,
<0.749716, -0.007176, 0.661722>,
<0.759203, -0.553783, 0.341958>,
<0.775762, -0.623022, -0.100185>,
<0.804801, 0.555656, 0.208671>,
<0.830847, -0.060190, -0.553237>,
<0.848333, 0.356899, -0.391094>,
<0.946332, -0.150800, 0.285859>,
<0.962890, -0.220040, -0.156284>,
<0.980377, 0.197049, 0.005858>,
}
#declare P0 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[20];
#declare P1 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[29];
#declare P2 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[42];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 60)
 #declare Johnson_75_trigyrate_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_75_trigyrate_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_75_trigyrate_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_75_trigyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[0],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[1],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[2],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[3],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[4],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[5],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[6],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[7],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[8],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[9],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[10],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[11],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[12],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[13],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[14],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[15],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[16],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[17],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[18],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[19],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[20],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[21],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[22],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[23],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[24],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[25],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[26],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[27],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[28],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[29],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[30],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[31],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[32],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[33],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[34],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[35],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[36],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[37],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[38],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[39],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[40],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[41],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[42],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[43],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[44],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[45],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[46],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[47],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[48],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[49],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[50],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[51],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[52],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[53],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[54],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[55],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[56],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[57],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[58],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[59]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  116,
  <30, 24, 37>, 0,
  <14, 28, 26>, 0,
  <11, 13, 22>, 0,
  <25, 38, 31>, 0,
  <48, 56, 55>, 0,
  <59, 57, 58>, 0,
  <39, 41, 50>, 0,
  <43, 49, 54>, 0,
  <40, 46, 34>, 0,
  <45, 36, 32>, 0,
  <53, 52, 44>, 0,
  <51, 42, 47>, 0,
  <21, 19, 10>, 0,
  <27, 15, 16>, 0,
  <33, 35, 23>, 0,
  <29, 20, 17>, 0,
  <18, 8, 12>, 0,
  <1, 3, 7>, 0,
  <5, 4, 0>, 0,
  <6, 9, 2>, 0,
  <18, 12, 24>, 1,
  <18, 24, 30>, 1,
  <24, 26, 39>, 1,
  <24, 39, 37>, 1,
  <26, 28, 41>, 1,
  <26, 41, 39>, 1,
  <11, 22, 28>, 1,
  <11, 28, 14>, 1,
  <13, 25, 31>, 1,
  <13, 31, 22>, 1,
  <31, 38, 49>, 1,
  <31, 49, 43>, 1,
  <30, 37, 48>, 1,
  <30, 48, 40>, 1,
  <56, 59, 58>, 1,
  <56, 58, 55>, 1,
  <58, 57, 52>, 1,
  <58, 52, 53>, 1,
  <50, 54, 59>, 1,
  <50, 59, 56>, 1,
  <41, 43, 54>, 1,
  <41, 54, 50>, 1,
  <49, 38, 42>, 1,
  <49, 42, 51>, 1,
  <48, 55, 46>, 1,
  <48, 46, 40>, 1,
  <46, 45, 32>, 1,
  <46, 32, 34>, 1,
  <36, 44, 33>, 1,
  <36, 33, 27>, 1,
  <53, 44, 36>, 1,
  <53, 36, 45>, 1,
  <57, 51, 47>, 1,
  <57, 47, 52>, 1,
  <47, 42, 29>, 1,
  <47, 29, 35>, 1,
  <34, 32, 19>, 1,
  <34, 19, 21>, 1,
  <19, 16, 5>, 1,
  <19, 5, 10>, 1,
  <16, 15, 4>, 1,
  <16, 4, 5>, 1,
  <33, 23, 15>, 1,
  <33, 15, 27>, 1,
  <35, 29, 17>, 1,
  <35, 17, 23>, 1,
  <17, 20, 9>, 1,
  <17, 9, 6>, 1,
  <21, 10, 8>, 1,
  <21, 8, 18>, 1,
  <8, 1, 7>, 1,
  <8, 7, 12>, 1,
  <7, 3, 11>, 1,
  <7, 11, 14>, 1,
  <0, 2, 3>, 1,
  <0, 3, 1>, 1,
  <4, 6, 2>, 1,
  <4, 2, 0>, 1,
  <9, 20, 25>, 1,
  <9, 25, 13>, 1,
  <12, 7, 14>, 2,
  <12, 14, 26>, 2,
  <12, 26, 24>, 2,
  <22, 31, 43>, 2,
  <22, 43, 41>, 2,
  <22, 41, 28>, 2,
  <37, 39, 50>, 2,
  <37, 50, 56>, 2,
  <37, 56, 48>, 2,
  <54, 49, 51>, 2,
  <54, 51, 57>, 2,
  <54, 57, 59>, 2,
  <55, 58, 53>, 2,
  <55, 53, 45>, 2,
  <55, 45, 46>, 2,
  <52, 47, 35>, 2,
  <52, 35, 33>, 2,
  <52, 33, 44>, 2,
  <32, 36, 27>, 2,
  <32, 27, 16>, 2,
  <32, 16, 19>, 2,
  <23, 17, 6>, 2,
  <23, 6, 4>, 2,
  <23, 4, 15>, 2,
  <10, 5, 0>, 2,
  <10, 0, 1>, 2,
  <10, 1, 8>, 2,
  <2, 9, 13>, 2,
  <2, 13, 11>, 2,
  <2, 11, 3>, 2,
  <18, 30, 40>, 2,
  <18, 40, 34>, 2,
  <18, 34, 21>, 2,
  <20, 29, 42>, 2,
  <20, 42, 38>, 2,
  <20, 38, 25>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[20];
 #local P1 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[29];
 #local P2 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[42];
 #local P3 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[38];
 #local P4 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[25];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_75_trigyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_75_trigyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_75_trigyrate_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_75_trigyrate_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  60,
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[0],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[1],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[2],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[3],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[4],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[5],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[6],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[7],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[8],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[9],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[10],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[11],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[12],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[13],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[14],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[15],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[16],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[17],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[18],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[19],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[20],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[21],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[22],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[23],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[24],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[25],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[26],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[27],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[28],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[29],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[30],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[31],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[32],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[33],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[34],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[35],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[36],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[37],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[38],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[39],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[40],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[41],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[42],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[43],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[44],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[45],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[46],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[47],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[48],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[49],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[50],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[51],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[52],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[53],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[54],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[55],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[56],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[57],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[58],
  Johnson_75_trigyrate_rhombicosidodecahedron_verts[59]
 }
 face_indices {
  116,
  <30, 24, 37>,
  <14, 28, 26>,
  <11, 13, 22>,
  <25, 38, 31>,
  <48, 56, 55>,
  <59, 57, 58>,
  <39, 41, 50>,
  <43, 49, 54>,
  <40, 46, 34>,
  <45, 36, 32>,
  <53, 52, 44>,
  <51, 42, 47>,
  <21, 19, 10>,
  <27, 15, 16>,
  <33, 35, 23>,
  <29, 20, 17>,
  <18, 8, 12>,
  <1, 3, 7>,
  <5, 4, 0>,
  <6, 9, 2>,
  <18, 12, 24>,
  <18, 24, 30>,
  <24, 26, 39>,
  <24, 39, 37>,
  <26, 28, 41>,
  <26, 41, 39>,
  <11, 22, 28>,
  <11, 28, 14>,
  <13, 25, 31>,
  <13, 31, 22>,
  <31, 38, 49>,
  <31, 49, 43>,
  <30, 37, 48>,
  <30, 48, 40>,
  <56, 59, 58>,
  <56, 58, 55>,
  <58, 57, 52>,
  <58, 52, 53>,
  <50, 54, 59>,
  <50, 59, 56>,
  <41, 43, 54>,
  <41, 54, 50>,
  <49, 38, 42>,
  <49, 42, 51>,
  <48, 55, 46>,
  <48, 46, 40>,
  <46, 45, 32>,
  <46, 32, 34>,
  <36, 44, 33>,
  <36, 33, 27>,
  <53, 44, 36>,
  <53, 36, 45>,
  <57, 51, 47>,
  <57, 47, 52>,
  <47, 42, 29>,
  <47, 29, 35>,
  <34, 32, 19>,
  <34, 19, 21>,
  <19, 16, 5>,
  <19, 5, 10>,
  <16, 15, 4>,
  <16, 4, 5>,
  <33, 23, 15>,
  <33, 15, 27>,
  <35, 29, 17>,
  <35, 17, 23>,
  <17, 20, 9>,
  <17, 9, 6>,
  <21, 10, 8>,
  <21, 8, 18>,
  <8, 1, 7>,
  <8, 7, 12>,
  <7, 3, 11>,
  <7, 11, 14>,
  <0, 2, 3>,
  <0, 3, 1>,
  <4, 6, 2>,
  <4, 2, 0>,
  <9, 20, 25>,
  <9, 25, 13>,
  <12, 7, 14>,
  <12, 14, 26>,
  <12, 26, 24>,
  <22, 31, 43>,
  <22, 43, 41>,
  <22, 41, 28>,
  <37, 39, 50>,
  <37, 50, 56>,
  <37, 56, 48>,
  <54, 49, 51>,
  <54, 51, 57>,
  <54, 57, 59>,
  <55, 58, 53>,
  <55, 53, 45>,
  <55, 45, 46>,
  <52, 47, 35>,
  <52, 35, 33>,
  <52, 33, 44>,
  <32, 36, 27>,
  <32, 27, 16>,
  <32, 16, 19>,
  <23, 17, 6>,
  <23, 6, 4>,
  <23, 4, 15>,
  <10, 5, 0>,
  <10, 0, 1>,
  <10, 1, 8>,
  <2, 9, 13>,
  <2, 13, 11>,
  <2, 11, 3>,
  <18, 30, 40>,
  <18, 40, 34>,
  <18, 34, 21>,
  <20, 29, 42>,
  <20, 42, 38>,
  <20, 38, 25>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[20];
 #local P1 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[29];
 #local P2 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[42];
 #local P3 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[38];
 #local P4 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[25];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_75_trigyrate_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_75_trigyrate_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_75_trigyrate_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[54], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[55], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[56], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[57], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[58], RadVer }
  sphere { Johnson_75_trigyrate_rhombicosidodecahedron_verts[59], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[30], Johnson_75_trigyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[24], Johnson_75_trigyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[37], Johnson_75_trigyrate_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[14], Johnson_75_trigyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[28], Johnson_75_trigyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[26], Johnson_75_trigyrate_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[11], Johnson_75_trigyrate_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[13], Johnson_75_trigyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[22], Johnson_75_trigyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[25], Johnson_75_trigyrate_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[38], Johnson_75_trigyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[31], Johnson_75_trigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[48], Johnson_75_trigyrate_rhombicosidodecahedron_verts[56], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[56], Johnson_75_trigyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[55], Johnson_75_trigyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[59], Johnson_75_trigyrate_rhombicosidodecahedron_verts[57], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[57], Johnson_75_trigyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[58], Johnson_75_trigyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[39], Johnson_75_trigyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[41], Johnson_75_trigyrate_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[50], Johnson_75_trigyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[43], Johnson_75_trigyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[49], Johnson_75_trigyrate_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[54], Johnson_75_trigyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[40], Johnson_75_trigyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[46], Johnson_75_trigyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[34], Johnson_75_trigyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[45], Johnson_75_trigyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[36], Johnson_75_trigyrate_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[32], Johnson_75_trigyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[53], Johnson_75_trigyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[52], Johnson_75_trigyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[44], Johnson_75_trigyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[51], Johnson_75_trigyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[42], Johnson_75_trigyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[47], Johnson_75_trigyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[21], Johnson_75_trigyrate_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[19], Johnson_75_trigyrate_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[10], Johnson_75_trigyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[27], Johnson_75_trigyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[15], Johnson_75_trigyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[16], Johnson_75_trigyrate_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[33], Johnson_75_trigyrate_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[35], Johnson_75_trigyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[23], Johnson_75_trigyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[29], Johnson_75_trigyrate_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[20], Johnson_75_trigyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[17], Johnson_75_trigyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[18], Johnson_75_trigyrate_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[8], Johnson_75_trigyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[12], Johnson_75_trigyrate_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[1], Johnson_75_trigyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[3], Johnson_75_trigyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[7], Johnson_75_trigyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[5], Johnson_75_trigyrate_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[4], Johnson_75_trigyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[0], Johnson_75_trigyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[6], Johnson_75_trigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[9], Johnson_75_trigyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[2], Johnson_75_trigyrate_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[12], Johnson_75_trigyrate_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[30], Johnson_75_trigyrate_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[24], Johnson_75_trigyrate_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[26], Johnson_75_trigyrate_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[39], Johnson_75_trigyrate_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[28], Johnson_75_trigyrate_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[22], Johnson_75_trigyrate_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[14], Johnson_75_trigyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[13], Johnson_75_trigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[31], Johnson_75_trigyrate_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[38], Johnson_75_trigyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[43], Johnson_75_trigyrate_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[37], Johnson_75_trigyrate_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[48], Johnson_75_trigyrate_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[40], Johnson_75_trigyrate_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[56], Johnson_75_trigyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[58], Johnson_75_trigyrate_rhombicosidodecahedron_verts[55], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[57], Johnson_75_trigyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[53], Johnson_75_trigyrate_rhombicosidodecahedron_verts[58], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[50], Johnson_75_trigyrate_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[54], Johnson_75_trigyrate_rhombicosidodecahedron_verts[59], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[56], Johnson_75_trigyrate_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[41], Johnson_75_trigyrate_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[38], Johnson_75_trigyrate_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[51], Johnson_75_trigyrate_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[55], Johnson_75_trigyrate_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[46], Johnson_75_trigyrate_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[32], Johnson_75_trigyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[36], Johnson_75_trigyrate_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[44], Johnson_75_trigyrate_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[33], Johnson_75_trigyrate_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[27], Johnson_75_trigyrate_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[45], Johnson_75_trigyrate_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[57], Johnson_75_trigyrate_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[47], Johnson_75_trigyrate_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[42], Johnson_75_trigyrate_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[29], Johnson_75_trigyrate_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[35], Johnson_75_trigyrate_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[32], Johnson_75_trigyrate_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[21], Johnson_75_trigyrate_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[19], Johnson_75_trigyrate_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[16], Johnson_75_trigyrate_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[5], Johnson_75_trigyrate_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[15], Johnson_75_trigyrate_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[23], Johnson_75_trigyrate_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[17], Johnson_75_trigyrate_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[20], Johnson_75_trigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[6], Johnson_75_trigyrate_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[10], Johnson_75_trigyrate_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[18], Johnson_75_trigyrate_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[8], Johnson_75_trigyrate_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[7], Johnson_75_trigyrate_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[3], Johnson_75_trigyrate_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[14], Johnson_75_trigyrate_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[0], Johnson_75_trigyrate_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[2], Johnson_75_trigyrate_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[1], Johnson_75_trigyrate_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[4], Johnson_75_trigyrate_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[20], Johnson_75_trigyrate_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_75_trigyrate_rhombicosidodecahedron_verts[13], Johnson_75_trigyrate_rhombicosidodecahedron_verts[9], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[20];
 #local P1 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[29];
 #local P2 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[42];
 #local P3 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[38];
 #local P4 = Johnson_75_trigyrate_rhombicosidodecahedron_verts[25];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_76_diminished_rhombicosidodecahedron_verts = array[55]
{
<-0.975594, -0.152802, -0.163647>,
<-0.930864, 0.290583, -0.105382>,
<-0.885816, -0.354103, 0.228021>,
<-0.840234, -0.110417, -0.590106>,
<-0.813441, 0.363309, 0.322296>,
<-0.812393, -0.508854, -0.384052>,
<-0.795504, 0.332968, -0.531841>,
<-0.785600, -0.035128, 0.528350>,
<-0.722614, -0.710155, 0.007616>,
<-0.695288, 0.651943, -0.231511>,
<-0.605191, -0.637428, 0.435294>,
<-0.577865, 0.724669, 0.196167>,
<-0.531438, -0.243136, -0.888462>,
<-0.504975, -0.318454, 0.735624>,
<-0.503596, -0.641573, -0.682408>,
<-0.488086, 0.523369, 0.587835>,
<-0.460245, 0.124931, 0.793890>,
<-0.459063, 0.474276, -0.794187>,
<-0.358847, 0.793251, -0.493857>,
<-0.358332, -0.967284, -0.048676>,
<-0.295861, 0.118224, -1.014591>,
<-0.240909, -0.894558, 0.379002>,
<-0.222972, -0.924899, -0.475135>,
<-0.168853, 0.910925, 0.198140>
<-0.079074, 0.709624, 0.589809>,
<-0.078756, -0.378446, 0.864946>,
<-0.050051, 0.660532, -0.792214>,
<-0.034026, 0.064939, 0.923211>,
<-0.033492, 0.953310, -0.228318>,
<0.067887, -1.027277, 0.080646>,
<0.084446, -0.734498, 0.644541>,
<0.113151, 0.304480, -1.012618>,
<0.201551, 0.426299, 0.797082>,
<0.203247, -0.984891, -0.345813>,
<0.257366, 0.850932, 0.327462>,
<0.275304, 0.820591, -0.526675>,
<0.330256, -0.192191, 0.866919>,
<0.392727, 0.893318, -0.098997>,
<0.393242, -0.867217, 0.346185>,
<0.493458, -0.548243, 0.646514>,
<0.537991, 0.567607, 0.534736>,
<0.539370, 0.244487, -0.883296>,
<0.565833, 0.169169, 0.740790>,
<0.612260, -0.798636, -0.343840>,
<0.639586, 0.563462, -0.582967>,
<0.729683, -0.725909, 0.083838>,
<0.757009, 0.636188, -0.155289>,
<0.819995, -0.038838, -0.676023>,
<0.829899, -0.406935, 0.384168>,
<0.846787, 0.434888, 0.236379>,
<0.847836, -0.437276, -0.469969>,
<0.874629, 0.036450, 0.442434>,
<0.920211, 0.280136, -0.375693>,
<0.965259, -0.364549, -0.042291>,
<1.009989, 0.078836, 0.015975>,
}
#declare P0 = Johnson_76_diminished_rhombicosidodecahedron_verts[41];
#declare P1 = Johnson_76_diminished_rhombicosidodecahedron_verts[47];
#declare P2 = Johnson_76_diminished_rhombicosidodecahedron_verts[50];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 55)
 #declare Johnson_76_diminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_76_diminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_76_diminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_76_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_76_diminished_rhombicosidodecahedron_verts[0],
  Johnson_76_diminished_rhombicosidodecahedron_verts[1],
  Johnson_76_diminished_rhombicosidodecahedron_verts[2],
  Johnson_76_diminished_rhombicosidodecahedron_verts[3],
  Johnson_76_diminished_rhombicosidodecahedron_verts[4],
  Johnson_76_diminished_rhombicosidodecahedron_verts[5],
  Johnson_76_diminished_rhombicosidodecahedron_verts[6],
  Johnson_76_diminished_rhombicosidodecahedron_verts[7],
  Johnson_76_diminished_rhombicosidodecahedron_verts[8],
  Johnson_76_diminished_rhombicosidodecahedron_verts[9],
  Johnson_76_diminished_rhombicosidodecahedron_verts[10],
  Johnson_76_diminished_rhombicosidodecahedron_verts[11],
  Johnson_76_diminished_rhombicosidodecahedron_verts[12],
  Johnson_76_diminished_rhombicosidodecahedron_verts[13],
  Johnson_76_diminished_rhombicosidodecahedron_verts[14],
  Johnson_76_diminished_rhombicosidodecahedron_verts[15],
  Johnson_76_diminished_rhombicosidodecahedron_verts[16],
  Johnson_76_diminished_rhombicosidodecahedron_verts[17],
  Johnson_76_diminished_rhombicosidodecahedron_verts[18],
  Johnson_76_diminished_rhombicosidodecahedron_verts[19],
  Johnson_76_diminished_rhombicosidodecahedron_verts[20],
  Johnson_76_diminished_rhombicosidodecahedron_verts[21],
  Johnson_76_diminished_rhombicosidodecahedron_verts[22],
  Johnson_76_diminished_rhombicosidodecahedron_verts[23],
  Johnson_76_diminished_rhombicosidodecahedron_verts[24],
  Johnson_76_diminished_rhombicosidodecahedron_verts[25],
  Johnson_76_diminished_rhombicosidodecahedron_verts[26],
  Johnson_76_diminished_rhombicosidodecahedron_verts[27],
  Johnson_76_diminished_rhombicosidodecahedron_verts[28],
  Johnson_76_diminished_rhombicosidodecahedron_verts[29],
  Johnson_76_diminished_rhombicosidodecahedron_verts[30],
  Johnson_76_diminished_rhombicosidodecahedron_verts[31],
  Johnson_76_diminished_rhombicosidodecahedron_verts[32],
  Johnson_76_diminished_rhombicosidodecahedron_verts[33],
  Johnson_76_diminished_rhombicosidodecahedron_verts[34],
  Johnson_76_diminished_rhombicosidodecahedron_verts[35],
  Johnson_76_diminished_rhombicosidodecahedron_verts[36],
  Johnson_76_diminished_rhombicosidodecahedron_verts[37],
  Johnson_76_diminished_rhombicosidodecahedron_verts[38],
  Johnson_76_diminished_rhombicosidodecahedron_verts[39],
  Johnson_76_diminished_rhombicosidodecahedron_verts[40],
  Johnson_76_diminished_rhombicosidodecahedron_verts[41],
  Johnson_76_diminished_rhombicosidodecahedron_verts[42],
  Johnson_76_diminished_rhombicosidodecahedron_verts[43],
  Johnson_76_diminished_rhombicosidodecahedron_verts[44],
  Johnson_76_diminished_rhombicosidodecahedron_verts[45],
  Johnson_76_diminished_rhombicosidodecahedron_verts[46],
  Johnson_76_diminished_rhombicosidodecahedron_verts[47],
  Johnson_76_diminished_rhombicosidodecahedron_verts[48],
  Johnson_76_diminished_rhombicosidodecahedron_verts[49],
  Johnson_76_diminished_rhombicosidodecahedron_verts[50],
  Johnson_76_diminished_rhombicosidodecahedron_verts[51],
  Johnson_76_diminished_rhombicosidodecahedron_verts[52],
  Johnson_76_diminished_rhombicosidodecahedron_verts[53],
  Johnson_76_diminished_rhombicosidodecahedron_verts[54]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  106,
  <26, 17, 18>, 0,
  <6, 1, 9>, 0,
  <3, 5, 0>, 0,
  <8, 10, 2>, 0,
  <35, 28, 37>, 0,
  <23, 24, 34>, 0,
  <11, 4, 15>, 0,
  <7, 13, 16>, 0,
  <44, 46, 52>, 0,
  <49, 51, 54>, 0,
  <40, 32, 42>, 0,
  <27, 25, 36>, 0,
  <53, 48, 45>, 0,
  <39, 30, 38>, 0,
  <29, 21, 19>, 0,
  <31, 20, 17>, 1,
  <31, 17, 26>, 1,
  <17, 6, 9>, 1,
  <17, 9, 18>, 1,
  <9, 1, 4>, 1,
  <9, 4, 11>, 1,
  <3, 0, 1>, 1,
  <3, 1, 6>, 1,
  <5, 8, 2>, 1,
  <5, 2, 0>, 1,
  <2, 10, 13>, 1,
  <2, 13, 7>, 1,
  <26, 18, 28>, 1,
  <26, 28, 35>, 1,
  <28, 23, 34>, 1,
  <28, 34, 37>, 1,
  <34, 24, 32>, 1,
  <34, 32, 40>, 1,
  <11, 15, 24>, 1,
  <11, 24, 23>, 1,
  <4, 7, 16>, 1,
  <4, 16, 15>, 1,
  <16, 13, 25>, 1,
  <16, 25, 27>, 1,
  <35, 37, 46>, 1,
  <35, 46, 44>, 1,
  <46, 49, 54>, 1,
  <46, 54, 52>, 1,
  <54, 51, 48>, 1,
  <54, 48, 53>, 1,
  <40, 42, 51>, 1,
  <40, 51, 49>, 1,
  <32, 27, 36>, 1,
  <32, 36, 42>, 1,
  <36, 25, 30>, 1,
  <36, 30, 39>, 1,
  <44, 52, 47>, 1,
  <44, 47, 41>, 1,
  <53, 45, 43>, 1,
  <53, 43, 50>, 1,
  <48, 39, 38>, 1,
  <48, 38, 45>, 1,
  <38, 30, 21>, 1,
  <38, 21, 29>, 1,
  <12, 14, 5>, 1,
  <12, 5, 3>, 1,
  <33, 29, 19>, 1,
  <33, 19, 22>, 1,
  <19, 21, 10>, 1,
  <19, 10, 8>, 1,
  <20, 12, 3>, 2,
  <20, 3, 6>, 2,
  <20, 6, 17>, 2,
  <0, 2, 7>, 2,
  <0, 7, 4>, 2,
  <0, 4, 1>, 2,
  <18, 9, 11>, 2,
  <18, 11, 23>, 2,
  <18, 23, 28>, 2,
  <15, 16, 27>, 2,
  <15, 27, 32>, 2,
  <15, 32, 24>, 2,
  <37, 34, 40>, 2,
  <37, 40, 49>, 2,
  <37, 49, 46>, 2,
  <42, 36, 39>, 2,
  <42, 39, 48>, 2,
  <42, 48, 51>, 2,
  <52, 54, 53>, 2,
  <52, 53, 50>, 2,
  <52, 50, 47>, 2,
  <45, 38, 29>, 2,
  <45, 29, 33>, 2,
  <45, 33, 43>, 2,
  <22, 19, 8>, 2,
  <22, 8, 5>, 2,
  <22, 5, 14>, 2,
  <31, 26, 35>, 2,
  <31, 35, 44>, 2,
  <31, 44, 41>, 2,
  <21, 30, 25>, 2,
  <21, 25, 13>, 2,
  <21, 13, 10>, 2,
  <41, 47, 50>, 3,
  <41, 50, 43>, 3,
  <41, 43, 33>, 3,
  <41, 33, 22>, 3,
  <41, 22, 14>, 3,
  <41, 14, 12>, 3,
  <41, 12, 20>, 3,
  <41, 20, 31>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_76_diminished_rhombicosidodecahedron_verts[41];
 #local P1 = Johnson_76_diminished_rhombicosidodecahedron_verts[47];
 #local P2 = Johnson_76_diminished_rhombicosidodecahedron_verts[50];
 #local P3 = Johnson_76_diminished_rhombicosidodecahedron_verts[43];
 #local P4 = Johnson_76_diminished_rhombicosidodecahedron_verts[33];
 #local P5 = Johnson_76_diminished_rhombicosidodecahedron_verts[22];
 #local P6 = Johnson_76_diminished_rhombicosidodecahedron_verts[14];
 #local P7 = Johnson_76_diminished_rhombicosidodecahedron_verts[12];
 #local P8 = Johnson_76_diminished_rhombicosidodecahedron_verts[20];
 #local P9 = Johnson_76_diminished_rhombicosidodecahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_76_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_76_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_76_diminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_76_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_76_diminished_rhombicosidodecahedron_verts[0],
  Johnson_76_diminished_rhombicosidodecahedron_verts[1],
  Johnson_76_diminished_rhombicosidodecahedron_verts[2],
  Johnson_76_diminished_rhombicosidodecahedron_verts[3],
  Johnson_76_diminished_rhombicosidodecahedron_verts[4],
  Johnson_76_diminished_rhombicosidodecahedron_verts[5],
  Johnson_76_diminished_rhombicosidodecahedron_verts[6],
  Johnson_76_diminished_rhombicosidodecahedron_verts[7],
  Johnson_76_diminished_rhombicosidodecahedron_verts[8],
  Johnson_76_diminished_rhombicosidodecahedron_verts[9],
  Johnson_76_diminished_rhombicosidodecahedron_verts[10],
  Johnson_76_diminished_rhombicosidodecahedron_verts[11],
  Johnson_76_diminished_rhombicosidodecahedron_verts[12],
  Johnson_76_diminished_rhombicosidodecahedron_verts[13],
  Johnson_76_diminished_rhombicosidodecahedron_verts[14],
  Johnson_76_diminished_rhombicosidodecahedron_verts[15],
  Johnson_76_diminished_rhombicosidodecahedron_verts[16],
  Johnson_76_diminished_rhombicosidodecahedron_verts[17],
  Johnson_76_diminished_rhombicosidodecahedron_verts[18],
  Johnson_76_diminished_rhombicosidodecahedron_verts[19],
  Johnson_76_diminished_rhombicosidodecahedron_verts[20],
  Johnson_76_diminished_rhombicosidodecahedron_verts[21],
  Johnson_76_diminished_rhombicosidodecahedron_verts[22],
  Johnson_76_diminished_rhombicosidodecahedron_verts[23],
  Johnson_76_diminished_rhombicosidodecahedron_verts[24],
  Johnson_76_diminished_rhombicosidodecahedron_verts[25],
  Johnson_76_diminished_rhombicosidodecahedron_verts[26],
  Johnson_76_diminished_rhombicosidodecahedron_verts[27],
  Johnson_76_diminished_rhombicosidodecahedron_verts[28],
  Johnson_76_diminished_rhombicosidodecahedron_verts[29],
  Johnson_76_diminished_rhombicosidodecahedron_verts[30],
  Johnson_76_diminished_rhombicosidodecahedron_verts[31],
  Johnson_76_diminished_rhombicosidodecahedron_verts[32],
  Johnson_76_diminished_rhombicosidodecahedron_verts[33],
  Johnson_76_diminished_rhombicosidodecahedron_verts[34],
  Johnson_76_diminished_rhombicosidodecahedron_verts[35],
  Johnson_76_diminished_rhombicosidodecahedron_verts[36],
  Johnson_76_diminished_rhombicosidodecahedron_verts[37],
  Johnson_76_diminished_rhombicosidodecahedron_verts[38],
  Johnson_76_diminished_rhombicosidodecahedron_verts[39],
  Johnson_76_diminished_rhombicosidodecahedron_verts[40],
  Johnson_76_diminished_rhombicosidodecahedron_verts[41],
  Johnson_76_diminished_rhombicosidodecahedron_verts[42],
  Johnson_76_diminished_rhombicosidodecahedron_verts[43],
  Johnson_76_diminished_rhombicosidodecahedron_verts[44],
  Johnson_76_diminished_rhombicosidodecahedron_verts[45],
  Johnson_76_diminished_rhombicosidodecahedron_verts[46],
  Johnson_76_diminished_rhombicosidodecahedron_verts[47],
  Johnson_76_diminished_rhombicosidodecahedron_verts[48],
  Johnson_76_diminished_rhombicosidodecahedron_verts[49],
  Johnson_76_diminished_rhombicosidodecahedron_verts[50],
  Johnson_76_diminished_rhombicosidodecahedron_verts[51],
  Johnson_76_diminished_rhombicosidodecahedron_verts[52],
  Johnson_76_diminished_rhombicosidodecahedron_verts[53],
  Johnson_76_diminished_rhombicosidodecahedron_verts[54]
 }
 face_indices {
  106,
  <26, 17, 18>,
  <6, 1, 9>,
  <3, 5, 0>,
  <8, 10, 2>,
  <35, 28, 37>,
  <23, 24, 34>,
  <11, 4, 15>,
  <7, 13, 16>,
  <44, 46, 52>,
  <49, 51, 54>,
  <40, 32, 42>,
  <27, 25, 36>,
  <53, 48, 45>,
  <39, 30, 38>,
  <29, 21, 19>,
  <31, 20, 17>,
  <31, 17, 26>,
  <17, 6, 9>,
  <17, 9, 18>,
  <9, 1, 4>,
  <9, 4, 11>,
  <3, 0, 1>,
  <3, 1, 6>,
  <5, 8, 2>,
  <5, 2, 0>,
  <2, 10, 13>,
  <2, 13, 7>,
  <26, 18, 28>,
  <26, 28, 35>,
  <28, 23, 34>,
  <28, 34, 37>,
  <34, 24, 32>,
  <34, 32, 40>,
  <11, 15, 24>,
  <11, 24, 23>,
  <4, 7, 16>,
  <4, 16, 15>,
  <16, 13, 25>,
  <16, 25, 27>,
  <35, 37, 46>,
  <35, 46, 44>,
  <46, 49, 54>,
  <46, 54, 52>,
  <54, 51, 48>,
  <54, 48, 53>,
  <40, 42, 51>,
  <40, 51, 49>,
  <32, 27, 36>,
  <32, 36, 42>,
  <36, 25, 30>,
  <36, 30, 39>,
  <44, 52, 47>,
  <44, 47, 41>,
  <53, 45, 43>,
  <53, 43, 50>,
  <48, 39, 38>,
  <48, 38, 45>,
  <38, 30, 21>,
  <38, 21, 29>,
  <12, 14, 5>,
  <12, 5, 3>,
  <33, 29, 19>,
  <33, 19, 22>,
  <19, 21, 10>,
  <19, 10, 8>,
  <20, 12, 3>,
  <20, 3, 6>,
  <20, 6, 17>,
  <0, 2, 7>,
  <0, 7, 4>,
  <0, 4, 1>,
  <18, 9, 11>,
  <18, 11, 23>,
  <18, 23, 28>,
  <15, 16, 27>,
  <15, 27, 32>,
  <15, 32, 24>,
  <37, 34, 40>,
  <37, 40, 49>,
  <37, 49, 46>,
  <42, 36, 39>,
  <42, 39, 48>,
  <42, 48, 51>,
  <52, 54, 53>,
  <52, 53, 50>,
  <52, 50, 47>,
  <45, 38, 29>,
  <45, 29, 33>,
  <45, 33, 43>,
  <22, 19, 8>,
  <22, 8, 5>,
  <22, 5, 14>,
  <31, 26, 35>,
  <31, 35, 44>,
  <31, 44, 41>,
  <21, 30, 25>,
  <21, 25, 13>,
  <21, 13, 10>,
  <41, 47, 50>,
  <41, 50, 43>,
  <41, 43, 33>,
  <41, 33, 22>,
  <41, 22, 14>,
  <41, 14, 12>,
  <41, 12, 20>,
  <41, 20, 31>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_76_diminished_rhombicosidodecahedron_verts[41];
 #local P1 = Johnson_76_diminished_rhombicosidodecahedron_verts[47];
 #local P2 = Johnson_76_diminished_rhombicosidodecahedron_verts[50];
 #local P3 = Johnson_76_diminished_rhombicosidodecahedron_verts[43];
 #local P4 = Johnson_76_diminished_rhombicosidodecahedron_verts[33];
 #local P5 = Johnson_76_diminished_rhombicosidodecahedron_verts[22];
 #local P6 = Johnson_76_diminished_rhombicosidodecahedron_verts[14];
 #local P7 = Johnson_76_diminished_rhombicosidodecahedron_verts[12];
 #local P8 = Johnson_76_diminished_rhombicosidodecahedron_verts[20];
 #local P9 = Johnson_76_diminished_rhombicosidodecahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_76_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_76_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_76_diminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_76_diminished_rhombicosidodecahedron_verts[54], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[26], Johnson_76_diminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[17], Johnson_76_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[18], Johnson_76_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[6], Johnson_76_diminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[1], Johnson_76_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[9], Johnson_76_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[3], Johnson_76_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[5], Johnson_76_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[0], Johnson_76_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[8], Johnson_76_diminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[10], Johnson_76_diminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[2], Johnson_76_diminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[35], Johnson_76_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[28], Johnson_76_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[37], Johnson_76_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[23], Johnson_76_diminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[24], Johnson_76_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[34], Johnson_76_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[11], Johnson_76_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[4], Johnson_76_diminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[15], Johnson_76_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[7], Johnson_76_diminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[13], Johnson_76_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[16], Johnson_76_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[44], Johnson_76_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[46], Johnson_76_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[52], Johnson_76_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[49], Johnson_76_diminished_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[51], Johnson_76_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[54], Johnson_76_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[40], Johnson_76_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[32], Johnson_76_diminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[42], Johnson_76_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[27], Johnson_76_diminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[25], Johnson_76_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[36], Johnson_76_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[53], Johnson_76_diminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[48], Johnson_76_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[45], Johnson_76_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[39], Johnson_76_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[30], Johnson_76_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[38], Johnson_76_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[29], Johnson_76_diminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[21], Johnson_76_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[19], Johnson_76_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[31], Johnson_76_diminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[20], Johnson_76_diminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[26], Johnson_76_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[17], Johnson_76_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[9], Johnson_76_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[1], Johnson_76_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[11], Johnson_76_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[0], Johnson_76_diminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[6], Johnson_76_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[5], Johnson_76_diminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[2], Johnson_76_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[10], Johnson_76_diminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[7], Johnson_76_diminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[18], Johnson_76_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[35], Johnson_76_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[28], Johnson_76_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[34], Johnson_76_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[24], Johnson_76_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[40], Johnson_76_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[15], Johnson_76_diminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[23], Johnson_76_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[4], Johnson_76_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[16], Johnson_76_diminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[13], Johnson_76_diminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[27], Johnson_76_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[37], Johnson_76_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[44], Johnson_76_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[46], Johnson_76_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[54], Johnson_76_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[51], Johnson_76_diminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[53], Johnson_76_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[42], Johnson_76_diminished_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[49], Johnson_76_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[32], Johnson_76_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[36], Johnson_76_diminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[25], Johnson_76_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[39], Johnson_76_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[52], Johnson_76_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[47], Johnson_76_diminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[41], Johnson_76_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[45], Johnson_76_diminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[43], Johnson_76_diminished_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[50], Johnson_76_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[48], Johnson_76_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[38], Johnson_76_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[30], Johnson_76_diminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[29], Johnson_76_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[12], Johnson_76_diminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[14], Johnson_76_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[3], Johnson_76_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[33], Johnson_76_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[19], Johnson_76_diminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[22], Johnson_76_diminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[21], Johnson_76_diminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[8], Johnson_76_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[20], Johnson_76_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[50], Johnson_76_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[33], Johnson_76_diminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[14], Johnson_76_diminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_76_diminished_rhombicosidodecahedron_verts[41], Johnson_76_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_76_diminished_rhombicosidodecahedron_verts[41];
 #local P1 = Johnson_76_diminished_rhombicosidodecahedron_verts[47];
 #local P2 = Johnson_76_diminished_rhombicosidodecahedron_verts[50];
 #local P3 = Johnson_76_diminished_rhombicosidodecahedron_verts[43];
 #local P4 = Johnson_76_diminished_rhombicosidodecahedron_verts[33];
 #local P5 = Johnson_76_diminished_rhombicosidodecahedron_verts[22];
 #local P6 = Johnson_76_diminished_rhombicosidodecahedron_verts[14];
 #local P7 = Johnson_76_diminished_rhombicosidodecahedron_verts[12];
 #local P8 = Johnson_76_diminished_rhombicosidodecahedron_verts[20];
 #local P9 = Johnson_76_diminished_rhombicosidodecahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts = array[55]
{
<-0.965273, -0.178368, -0.195819>,
<-0.921193, 0.268836, -0.202934>,
<-0.899923, -0.317663, 0.226452>,
<-0.828599, 0.405929, 0.214939>,
<-0.815454, 0.043453, 0.480314>,
<-0.804857, -0.200850, -0.615041>,
<-0.791711, -0.563327, -0.349666>,
<-0.760776, 0.246354, -0.622156>,
<-0.726361, -0.702622, 0.072605>,
<-0.676307, 0.607470, -0.368293>,
<-0.633767, -0.565529, 0.490477>,
<-0.583713, 0.744563, 0.049579>,
<-0.582414, 0.411487, 0.590902>,
<-0.549298, -0.204413, 0.744340>,
<-0.479947, -0.376522, -0.871086>,
<-0.466801, -0.738998, -0.605711>,
<-0.408623, 0.347071, -0.882598>,
<-0.361062, -0.964382, 0.077537>,
<-0.337528, 0.750121, 0.425542>,
<-0.324153, 0.708187, -0.628736>,
<-0.316259, 0.163621, 0.854928>,
<-0.268468, -0.827289, 0.495410>,
<-0.235061, -0.037888, -1.036445>,
<-0.200645, -0.986864, -0.341685>
<-0.174334, 0.930008, 0.047397>,
<-0.131794, -0.242991, 0.906168>,
<-0.013917, 0.907526, -0.371825>,
<0.000756, 0.532515, -0.884780>,
<0.041768, -0.627950, 0.752321>,
<0.056442, -1.002960, 0.239365>,
<0.079975, 0.711542, 0.587370>,
<0.093121, 0.349066, 0.852745>,
<0.174319, 0.147557, -1.038628>,
<0.216858, -1.025442, -0.179857>,
<0.243170, 0.891430, 0.209225>,
<0.277585, -0.057546, 0.903985>,
<0.310993, 0.731855, -0.627870>,
<0.366678, -0.803621, 0.496276>,
<0.403586, 0.868948, -0.209997>,
<0.451147, -0.442505, 0.750138>,
<0.509326, 0.643564, 0.473251>,
<0.522471, 0.281088, 0.738626>,
<0.591822, 0.108979, -0.876800>,
<0.626237, -0.839998, -0.182039>,
<0.676292, 0.470095, -0.622937>,
<0.718831, -0.702904, 0.235834>,
<0.768885, 0.607188, -0.205064>,
<0.803300, -0.341788, 0.489696>,
<0.834235, 0.467893, 0.217206>,
<0.847381, 0.105416, 0.482581>,
<0.857978, -0.138887, -0.612774>,
<0.871123, -0.501364, -0.347399>,
<0.942447, 0.222229, -0.358911>,
<0.963717, -0.364270, 0.070474>,
<1.007798, 0.082934, 0.063359>,
}
#declare P0 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42];
#declare P1 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50];
#declare P2 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 55)
 #declare Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_77_paragyrate_diminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_77_paragyrate_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[0],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[1],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[2],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[3],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[4],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[5],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[6],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[7],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[8],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[9],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[10],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[11],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[12],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[13],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[16],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[17],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[18],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[19],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[20],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[21],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[24],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[25],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[26],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[27],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[28],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[29],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[30],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[31],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[34],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[35],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[36],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[37],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[38],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[39],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[40],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[41],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[44],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[45],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[46],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[47],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[48],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[49],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[52],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[53],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[54]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  106,
  <27, 16, 19>, 0,
  <7, 1, 9>, 0,
  <5, 6, 0>, 0,
  <8, 10, 2>, 0,
  <36, 26, 38>, 0,
  <11, 18, 24>, 0,
  <3, 4, 12>, 0,
  <13, 25, 20>, 0,
  <44, 46, 52>, 0,
  <48, 49, 54>, 0,
  <34, 30, 40>, 0,
  <31, 35, 41>, 0,
  <53, 47, 45>, 0,
  <39, 28, 37>, 0,
  <29, 21, 17>, 0,
  <32, 22, 16>, 1,
  <32, 16, 27>, 1,
  <16, 7, 9>, 1,
  <16, 9, 19>, 1,
  <9, 1, 3>, 1,
  <9, 3, 11>, 1,
  <5, 0, 1>, 1,
  <5, 1, 7>, 1,
  <6, 8, 2>, 1,
  <6, 2, 0>, 1,
  <2, 10, 13>, 1,
  <2, 13, 4>, 1,
  <27, 19, 26>, 1,
  <27, 26, 36>, 1,
  <26, 24, 34>, 1,
  <26, 34, 38>, 1,
  <24, 18, 30>, 1,
  <24, 30, 34>, 1,
  <3, 12, 18>, 1,
  <3, 18, 11>, 1,
  <4, 13, 20>, 1,
  <4, 20, 12>, 1,
  <20, 25, 35>, 1,
  <20, 35, 31>, 1,
  <36, 38, 46>, 1,
  <36, 46, 44>, 1,
  <46, 48, 54>, 1,
  <46, 54, 52>, 1,
  <54, 49, 47>, 1,
  <54, 47, 53>, 1,
  <40, 41, 49>, 1,
  <40, 49, 48>, 1,
  <30, 31, 41>, 1,
  <30, 41, 40>, 1,
  <35, 25, 28>, 1,
  <35, 28, 39>, 1,
  <44, 52, 50>, 1,
  <44, 50, 42>, 1,
  <53, 45, 43>, 1,
  <53, 43, 51>, 1,
  <47, 39, 37>, 1,
  <47, 37, 45>, 1,
  <37, 28, 21>, 1,
  <37, 21, 29>, 1,
  <14, 15, 6>, 1,
  <14, 6, 5>, 1,
  <33, 29, 17>, 1,
  <33, 17, 23>, 1,
  <17, 21, 10>, 1,
  <17, 10, 8>, 1,
  <22, 14, 5>, 2,
  <22, 5, 7>, 2,
  <22, 7, 16>, 2,
  <0, 2, 4>, 2,
  <0, 4, 3>, 2,
  <0, 3, 1>, 2,
  <19, 9, 11>, 2,
  <19, 11, 24>, 2,
  <19, 24, 26>, 2,
  <12, 20, 31>, 2,
  <12, 31, 30>, 2,
  <12, 30, 18>, 2,
  <38, 34, 40>, 2,
  <38, 40, 48>, 2,
  <38, 48, 46>, 2,
  <41, 35, 39>, 2,
  <41, 39, 47>, 2,
  <41, 47, 49>, 2,
  <52, 54, 53>, 2,
  <52, 53, 51>, 2,
  <52, 51, 50>, 2,
  <45, 37, 29>, 2,
  <45, 29, 33>, 2,
  <45, 33, 43>, 2,
  <23, 17, 8>, 2,
  <23, 8, 6>, 2,
  <23, 6, 15>, 2,
  <32, 27, 36>, 2,
  <32, 36, 44>, 2,
  <32, 44, 42>, 2,
  <21, 28, 25>, 2,
  <21, 25, 13>, 2,
  <21, 13, 10>, 2,
  <42, 50, 51>, 3,
  <42, 51, 43>, 3,
  <42, 43, 33>, 3,
  <42, 33, 23>, 3,
  <42, 23, 15>, 3,
  <42, 15, 14>, 3,
  <42, 14, 22>, 3,
  <42, 22, 32>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42];
 #local P1 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50];
 #local P2 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51];
 #local P3 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43];
 #local P4 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33];
 #local P5 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23];
 #local P6 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15];
 #local P7 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P8 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22];
 #local P9 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_77_paragyrate_diminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_77_paragyrate_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[0],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[1],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[2],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[3],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[4],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[5],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[6],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[7],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[8],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[9],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[10],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[11],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[12],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[13],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[16],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[17],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[18],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[19],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[20],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[21],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[24],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[25],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[26],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[27],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[28],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[29],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[30],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[31],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[34],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[35],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[36],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[37],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[38],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[39],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[40],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[41],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[44],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[45],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[46],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[47],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[48],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[49],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[52],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[53],
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[54]
 }
 face_indices {
  106,
  <27, 16, 19>,
  <7, 1, 9>,
  <5, 6, 0>,
  <8, 10, 2>,
  <36, 26, 38>,
  <11, 18, 24>,
  <3, 4, 12>,
  <13, 25, 20>,
  <44, 46, 52>,
  <48, 49, 54>,
  <34, 30, 40>,
  <31, 35, 41>,
  <53, 47, 45>,
  <39, 28, 37>,
  <29, 21, 17>,
  <32, 22, 16>,
  <32, 16, 27>,
  <16, 7, 9>,
  <16, 9, 19>,
  <9, 1, 3>,
  <9, 3, 11>,
  <5, 0, 1>,
  <5, 1, 7>,
  <6, 8, 2>,
  <6, 2, 0>,
  <2, 10, 13>,
  <2, 13, 4>,
  <27, 19, 26>,
  <27, 26, 36>,
  <26, 24, 34>,
  <26, 34, 38>,
  <24, 18, 30>,
  <24, 30, 34>,
  <3, 12, 18>,
  <3, 18, 11>,
  <4, 13, 20>,
  <4, 20, 12>,
  <20, 25, 35>,
  <20, 35, 31>,
  <36, 38, 46>,
  <36, 46, 44>,
  <46, 48, 54>,
  <46, 54, 52>,
  <54, 49, 47>,
  <54, 47, 53>,
  <40, 41, 49>,
  <40, 49, 48>,
  <30, 31, 41>,
  <30, 41, 40>,
  <35, 25, 28>,
  <35, 28, 39>,
  <44, 52, 50>,
  <44, 50, 42>,
  <53, 45, 43>,
  <53, 43, 51>,
  <47, 39, 37>,
  <47, 37, 45>,
  <37, 28, 21>,
  <37, 21, 29>,
  <14, 15, 6>,
  <14, 6, 5>,
  <33, 29, 17>,
  <33, 17, 23>,
  <17, 21, 10>,
  <17, 10, 8>,
  <22, 14, 5>,
  <22, 5, 7>,
  <22, 7, 16>,
  <0, 2, 4>,
  <0, 4, 3>,
  <0, 3, 1>,
  <19, 9, 11>,
  <19, 11, 24>,
  <19, 24, 26>,
  <12, 20, 31>,
  <12, 31, 30>,
  <12, 30, 18>,
  <38, 34, 40>,
  <38, 40, 48>,
  <38, 48, 46>,
  <41, 35, 39>,
  <41, 39, 47>,
  <41, 47, 49>,
  <52, 54, 53>,
  <52, 53, 51>,
  <52, 51, 50>,
  <45, 37, 29>,
  <45, 29, 33>,
  <45, 33, 43>,
  <23, 17, 8>,
  <23, 8, 6>,
  <23, 6, 15>,
  <32, 27, 36>,
  <32, 36, 44>,
  <32, 44, 42>,
  <21, 28, 25>,
  <21, 25, 13>,
  <21, 13, 10>,
  <42, 50, 51>,
  <42, 51, 43>,
  <42, 43, 33>,
  <42, 33, 23>,
  <42, 23, 15>,
  <42, 15, 14>,
  <42, 14, 22>,
  <42, 22, 32>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42];
 #local P1 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50];
 #local P2 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51];
 #local P3 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43];
 #local P4 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33];
 #local P5 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23];
 #local P6 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15];
 #local P7 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P8 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22];
 #local P9 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_77_paragyrate_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_77_paragyrate_diminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[54], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[27], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[16], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[19], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[7], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[1], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[9], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[5], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[6], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[0], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[8], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[10], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[2], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[36], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[26], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[38], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[11], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[18], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[24], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[3], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[4], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[12], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[13], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[20], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[44], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[46], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[52], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[48], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[49], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[54], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[34], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[30], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[40], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[31], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[35], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[41], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[53], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[47], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[45], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[39], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[28], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[37], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[29], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[21], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[17], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[27], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[16], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[9], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[1], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[3], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[11], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[0], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[7], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[6], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[2], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[10], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[13], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[4], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[19], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[36], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[26], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[24], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[34], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[18], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[12], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[20], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[31], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[38], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[44], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[46], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[54], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[49], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[53], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[40], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[41], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[48], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[30], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[39], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[52], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[45], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[47], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[37], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[28], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[29], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[5], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[17], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[21], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[8], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42], Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[42];
 #local P1 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[50];
 #local P2 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[51];
 #local P3 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[43];
 #local P4 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[33];
 #local P5 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[23];
 #local P6 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[15];
 #local P7 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P8 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[22];
 #local P9 = Johnson_77_paragyrate_diminished_rhombicosidodecahedron_verts[32];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts = array[55]
{
<-0.969175, 0.215371, -0.127391>,
<-0.952173, -0.166819, -0.363246>,
<-0.946899, -0.019645, 0.255045>,
<-0.929897, -0.401835, 0.019190>,
<-0.840084, 0.222491, -0.557822>,
<-0.781766, -0.392789, 0.443408>,
<-0.765536, 0.610272, -0.059785>,
<-0.729493, 0.230008, 0.559009>,
<-0.721025, -0.390315, -0.677262>,
<-0.684982, -0.770578, -0.058468>,
<-0.636445, 0.617392, -0.490216>,
<-0.617404, 0.619318, 0.364433>,
<-0.608936, -0.001005, -0.871838>,
<-0.564360, -0.143136, 0.747372>,
<-0.555892, -0.763458, -0.488899>,
<-0.536851, -0.761533, 0.365750>,
<-0.419039, 0.867044, -0.186253>,
<-0.360721, 0.251764, 0.814977>,
<-0.305703, -0.985028, 0.051734>,
<-0.279442, 0.637958, -0.762450>,
<-0.270908, 0.876090, 0.237966>,
<-0.262440, 0.255768, -0.998305>,
<-0.248632, 0.641074, 0.620402>,
<-0.185081, -0.357586, 0.857574>
<-0.176613, -0.977908, -0.378698>,
<-0.168079, -0.739776, 0.621718>,
<-0.062036, 0.887611, -0.458486>,
<0.018558, 0.037315, 0.925179>,
<0.063069, -0.963271, 0.307702>,
<0.169112, 0.664116, -0.772503>,
<0.177646, 0.902248, 0.227913>,
<0.186114, 0.281925, -1.008358>,
<0.199922, 0.667232, 0.610349>,
<0.211888, -0.546211, 0.763647>,
<0.271941, -0.951751, -0.388750>,
<0.306736, 0.909368, -0.202518>,
<0.365054, 0.294088, 0.798712>,
<0.415527, -0.151311, 0.831252>,
<0.420072, -0.942705, 0.035468>,
<0.443036, -0.769707, 0.449630>,
<0.537884, 0.685872, -0.516534>,
<0.556925, 0.687798, 0.338115>,
<0.565393, 0.067476, -0.898156>,
<0.618437, -0.694978, -0.515217>,
<0.686015, 0.694918, -0.092316>,
<0.722058, 0.314654, 0.526478>,
<0.730526, -0.305668, -0.709793>,
<0.766569, -0.685932, -0.090999>,
<0.772530, -0.130744, 0.559019>,
<0.782799, 0.317129, -0.594192>,
<0.789532, -0.512934, 0.323163>,
<0.930930, 0.326175, -0.169974>,
<0.947932, -0.056015, -0.405829>,
<0.953206, 0.091159, 0.212462>,
<0.970208, -0.291031, -0.023393>,
}
#declare P0 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42];
#declare P1 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46];
#declare P2 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 55)
 #declare Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_78_metagyrate_diminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_78_metagyrate_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[0],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[1],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[2],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[3],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[4],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[5],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[6],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[7],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[9],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[10],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[11],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[13],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[15],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[16],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[17],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[18],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[19],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[20],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[22],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[23],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[25],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[26],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[27],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[28],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[29],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[30],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[32],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[33],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[35],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[36],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[37],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[38],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[39],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[40],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[41],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[44],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[45],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[47],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[48],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[49],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[50],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[51],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[52],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[53],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[54]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  106,
  <29, 19, 26>, 0,
  <10, 6, 16>, 0,
  <4, 1, 0>, 0,
  <3, 5, 2>, 0,
  <40, 35, 44>, 0,
  <30, 32, 41>, 0,
  <20, 11, 22>, 0,
  <7, 13, 17>, 0,
  <49, 51, 52>, 0,
  <45, 48, 53>, 0,
  <36, 27, 37>, 0,
  <23, 25, 33>, 0,
  <54, 50, 47>, 0,
  <39, 28, 38>, 0,
  <18, 15, 9>, 0,
  <31, 21, 19>, 1,
  <31, 19, 29>, 1,
  <19, 10, 16>, 1,
  <19, 16, 26>, 1,
  <16, 6, 11>, 1,
  <16, 11, 20>, 1,
  <4, 0, 6>, 1,
  <4, 6, 10>, 1,
  <1, 3, 2>, 1,
  <1, 2, 0>, 1,
  <2, 5, 13>, 1,
  <2, 13, 7>, 1,
  <29, 26, 35>, 1,
  <29, 35, 40>, 1,
  <35, 30, 41>, 1,
  <35, 41, 44>, 1,
  <41, 32, 36>, 1,
  <41, 36, 45>, 1,
  <20, 22, 32>, 1,
  <20, 32, 30>, 1,
  <11, 7, 17>, 1,
  <11, 17, 22>, 1,
  <17, 13, 23>, 1,
  <17, 23, 27>, 1,
  <40, 44, 51>, 1,
  <40, 51, 49>, 1,
  <51, 53, 54>, 1,
  <51, 54, 52>, 1,
  <53, 48, 50>, 1,
  <53, 50, 54>, 1,
  <36, 37, 48>, 1,
  <36, 48, 45>, 1,
  <27, 23, 33>, 1,
  <27, 33, 37>, 1,
  <33, 25, 28>, 1,
  <33, 28, 39>, 1,
  <49, 52, 46>, 1,
  <49, 46, 42>, 1,
  <47, 38, 34>, 1,
  <47, 34, 43>, 1,
  <50, 39, 38>, 1,
  <50, 38, 47>, 1,
  <28, 25, 15>, 1,
  <28, 15, 18>, 1,
  <12, 8, 1>, 1,
  <12, 1, 4>, 1,
  <24, 18, 9>, 1,
  <24, 9, 14>, 1,
  <9, 15, 5>, 1,
  <9, 5, 3>, 1,
  <21, 12, 4>, 2,
  <21, 4, 10>, 2,
  <21, 10, 19>, 2,
  <0, 2, 7>, 2,
  <0, 7, 11>, 2,
  <0, 11, 6>, 2,
  <26, 16, 20>, 2,
  <26, 20, 30>, 2,
  <26, 30, 35>, 2,
  <22, 17, 27>, 2,
  <22, 27, 36>, 2,
  <22, 36, 32>, 2,
  <44, 41, 45>, 2,
  <44, 45, 53>, 2,
  <44, 53, 51>, 2,
  <37, 33, 39>, 2,
  <37, 39, 50>, 2,
  <37, 50, 48>, 2,
  <52, 54, 47>, 2,
  <52, 47, 43>, 2,
  <52, 43, 46>, 2,
  <38, 28, 18>, 2,
  <38, 18, 24>, 2,
  <38, 24, 34>, 2,
  <14, 9, 3>, 2,
  <14, 3, 1>, 2,
  <14, 1, 8>, 2,
  <31, 29, 40>, 2,
  <31, 40, 49>, 2,
  <31, 49, 42>, 2,
  <15, 25, 23>, 2,
  <15, 23, 13>, 2,
  <15, 13, 5>, 2,
  <42, 46, 43>, 3,
  <42, 43, 34>, 3,
  <42, 34, 24>, 3,
  <42, 24, 14>, 3,
  <42, 14, 8>, 3,
  <42, 8, 12>, 3,
  <42, 12, 21>, 3,
  <42, 21, 31>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42];
 #local P1 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46];
 #local P2 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43];
 #local P3 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34];
 #local P4 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24];
 #local P5 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P6 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8];
 #local P7 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12];
 #local P8 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21];
 #local P9 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_78_metagyrate_diminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_78_metagyrate_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[0],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[1],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[2],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[3],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[4],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[5],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[6],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[7],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[9],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[10],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[11],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[13],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[15],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[16],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[17],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[18],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[19],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[20],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[22],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[23],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[25],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[26],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[27],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[28],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[29],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[30],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[32],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[33],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[35],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[36],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[37],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[38],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[39],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[40],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[41],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[44],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[45],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[47],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[48],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[49],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[50],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[51],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[52],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[53],
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[54]
 }
 face_indices {
  106,
  <29, 19, 26>,
  <10, 6, 16>,
  <4, 1, 0>,
  <3, 5, 2>,
  <40, 35, 44>,
  <30, 32, 41>,
  <20, 11, 22>,
  <7, 13, 17>,
  <49, 51, 52>,
  <45, 48, 53>,
  <36, 27, 37>,
  <23, 25, 33>,
  <54, 50, 47>,
  <39, 28, 38>,
  <18, 15, 9>,
  <31, 21, 19>,
  <31, 19, 29>,
  <19, 10, 16>,
  <19, 16, 26>,
  <16, 6, 11>,
  <16, 11, 20>,
  <4, 0, 6>,
  <4, 6, 10>,
  <1, 3, 2>,
  <1, 2, 0>,
  <2, 5, 13>,
  <2, 13, 7>,
  <29, 26, 35>,
  <29, 35, 40>,
  <35, 30, 41>,
  <35, 41, 44>,
  <41, 32, 36>,
  <41, 36, 45>,
  <20, 22, 32>,
  <20, 32, 30>,
  <11, 7, 17>,
  <11, 17, 22>,
  <17, 13, 23>,
  <17, 23, 27>,
  <40, 44, 51>,
  <40, 51, 49>,
  <51, 53, 54>,
  <51, 54, 52>,
  <53, 48, 50>,
  <53, 50, 54>,
  <36, 37, 48>,
  <36, 48, 45>,
  <27, 23, 33>,
  <27, 33, 37>,
  <33, 25, 28>,
  <33, 28, 39>,
  <49, 52, 46>,
  <49, 46, 42>,
  <47, 38, 34>,
  <47, 34, 43>,
  <50, 39, 38>,
  <50, 38, 47>,
  <28, 25, 15>,
  <28, 15, 18>,
  <12, 8, 1>,
  <12, 1, 4>,
  <24, 18, 9>,
  <24, 9, 14>,
  <9, 15, 5>,
  <9, 5, 3>,
  <21, 12, 4>,
  <21, 4, 10>,
  <21, 10, 19>,
  <0, 2, 7>,
  <0, 7, 11>,
  <0, 11, 6>,
  <26, 16, 20>,
  <26, 20, 30>,
  <26, 30, 35>,
  <22, 17, 27>,
  <22, 27, 36>,
  <22, 36, 32>,
  <44, 41, 45>,
  <44, 45, 53>,
  <44, 53, 51>,
  <37, 33, 39>,
  <37, 39, 50>,
  <37, 50, 48>,
  <52, 54, 47>,
  <52, 47, 43>,
  <52, 43, 46>,
  <38, 28, 18>,
  <38, 18, 24>,
  <38, 24, 34>,
  <14, 9, 3>,
  <14, 3, 1>,
  <14, 1, 8>,
  <31, 29, 40>,
  <31, 40, 49>,
  <31, 49, 42>,
  <15, 25, 23>,
  <15, 23, 13>,
  <15, 13, 5>,
  <42, 46, 43>,
  <42, 43, 34>,
  <42, 34, 24>,
  <42, 24, 14>,
  <42, 14, 8>,
  <42, 8, 12>,
  <42, 12, 21>,
  <42, 21, 31>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42];
 #local P1 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46];
 #local P2 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43];
 #local P3 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34];
 #local P4 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24];
 #local P5 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P6 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8];
 #local P7 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12];
 #local P8 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21];
 #local P9 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_78_metagyrate_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_78_metagyrate_diminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[54], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[29], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[19], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[26], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[10], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[6], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[16], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[4], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[1], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[0], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[3], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[5], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[2], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[40], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[35], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[44], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[30], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[32], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[41], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[20], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[11], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[22], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[7], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[13], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[17], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[49], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[51], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[52], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[45], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[48], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[53], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[36], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[27], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[37], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[23], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[33], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[54], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[50], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[47], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[39], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[28], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[38], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[18], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[15], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[9], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[29], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[19], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[16], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[6], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[20], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[0], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[10], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[1], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[2], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[5], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[7], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[26], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[40], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[35], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[41], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[32], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[36], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[45], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[22], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[30], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[11], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[17], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[13], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[23], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[27], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[44], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[49], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[51], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[53], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[54], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[48], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[37], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[33], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[39], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[52], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[47], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[38], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[50], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[18], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[4], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[9], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[15], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[3], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42], Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[42];
 #local P1 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[46];
 #local P2 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[43];
 #local P3 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[34];
 #local P4 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[24];
 #local P5 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P6 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[8];
 #local P7 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[12];
 #local P8 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[21];
 #local P9 = Johnson_78_metagyrate_diminished_rhombicosidodecahedron_verts[31];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts = array[55]
{
<-1.035663, 0.179510, 0.161516>,
<-1.027893, 0.048482, -0.268318>,
<-0.891113, 0.078842, 0.574986>,
<-0.870771, -0.264193, -0.550334>,
<-0.833419, 0.579967, 0.188311>,
<-0.820848, 0.367959, -0.507174>,
<-0.700657, 0.696435, -0.224962>,
<-0.688870, 0.479299, 0.601781>,
<-0.663727, 0.055284, -0.789190>,
<-0.649458, -0.215069, 0.814161>,
<-0.624314, -0.639084, -0.576811>,
<-0.485083, 0.858791, 0.134418>,
<-0.461483, 0.455741, -0.762395>,
<-0.403000, -0.589960, 0.787683>,
<-0.382659, -0.932996, -0.337637>,
<-0.341293, 0.784217, -0.480183>,
<-0.340534, 0.758124, 0.547888>,
<-0.322222, 0.432884, 0.857516>,
<-0.297863, 0.003740, 0.988774>,
<-0.289308, -0.122159, -0.963290>,
<-0.264950, -0.551303, -0.832032>,
<-0.245879, -0.902636, 0.505667>,
<-0.238109, -1.033664, 0.075833>,
<-0.125719, 0.946573, -0.120803>
<-0.087065, 0.278298, -0.936494>,
<-0.051406, -0.371151, 0.962296>,
<-0.023294, -0.845214, -0.592857>,
<0.107408, 0.809782, -0.479865>,
<0.108167, 0.783689, 0.548206>,
<0.110226, -0.325890, -0.934099>,
<0.126479, 0.458449, 0.857834>,
<0.150837, 0.029306, 0.989092>,
<0.202822, -0.877070, 0.505985>,
<0.210592, -1.008098, 0.076151>,
<0.240930, 0.900157, 0.134932>,
<0.264529, 0.497107, -0.761881>,
<0.312469, 0.074567, -0.907304>,
<0.323013, -0.548594, 0.788197>,
<0.343354, -0.891630, -0.337123>,
<0.351882, -0.619801, -0.694925>,
<0.474057, 0.763367, -0.224131>,
<0.485843, 0.546231, 0.602613>,
<0.525256, -0.148138, 0.814992>,
<0.562186, -0.789288, 0.250764>,
<0.618606, 0.662699, 0.189339>,
<0.631178, 0.450691, -0.506147>,
<0.679118, 0.028151, -0.651569>,
<0.682377, -0.460813, 0.532976>,
<0.694949, -0.672821, -0.162510>,
<0.703476, -0.400992, -0.520312>,
<0.732300, 0.171340, 0.576135>,
<0.865063, 0.287808, 0.162862>,
<0.872833, 0.156780, -0.266972>,
<0.889422, -0.141336, 0.294120>,
<0.897192, -0.272364, -0.135714>,
}
#declare P0 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1];
#declare P1 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3];
#declare P2 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 55)
 #declare Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_79_bigyrate_diminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_79_bigyrate_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[4],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[5],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[6],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[7],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[8],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[11],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[12],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[15],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[16],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[17],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[18],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[19],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[20],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[23],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[24],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[25],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[26],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[27],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[28],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[29],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[30],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[31],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[32],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[33],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[34],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[35],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[36],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[37],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[38],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[39],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[40],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[41],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[42],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[43],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[44],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[45],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[46],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[47],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[48],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[49],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[50],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[51],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[52],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[53],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[54]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  106,
  <7, 17, 16>, 0,
  <30, 41, 28>, 0,
  <18, 25, 31>, 0,
  <37, 47, 42>, 0,
  <4, 11, 6>, 0,
  <23, 27, 15>, 0,
  <34, 44, 40>, 0,
  <50, 53, 51>, 0,
  <5, 12, 8>, 0,
  <35, 36, 24>, 0,
  <45, 52, 46>, 0,
  <54, 48, 49>, 0,
  <19, 29, 20>, 0,
  <39, 38, 26>, 0,
  <33, 43, 32>, 0,
  <0, 2, 7>, 1,
  <0, 7, 4>, 1,
  <17, 30, 28>, 1,
  <17, 28, 16>, 1,
  <28, 41, 44>, 1,
  <28, 44, 34>, 1,
  <18, 31, 30>, 1,
  <18, 30, 17>, 1,
  <25, 37, 42>, 1,
  <25, 42, 31>, 1,
  <42, 47, 53>, 1,
  <42, 53, 50>, 1,
  <7, 16, 11>, 1,
  <7, 11, 4>, 1,
  <11, 23, 15>, 1,
  <11, 15, 6>, 1,
  <27, 40, 45>, 1,
  <27, 45, 35>, 1,
  <34, 40, 27>, 1,
  <34, 27, 23>, 1,
  <41, 50, 51>, 1,
  <41, 51, 44>, 1,
  <51, 53, 54>, 1,
  <51, 54, 52>, 1,
  <6, 15, 12>, 1,
  <6, 12, 5>, 1,
  <12, 24, 19>, 1,
  <12, 19, 8>, 1,
  <24, 36, 29>, 1,
  <24, 29, 19>, 1,
  <45, 46, 36>, 1,
  <45, 36, 35>, 1,
  <52, 54, 49>, 1,
  <52, 49, 46>, 1,
  <49, 48, 38>, 1,
  <49, 38, 39>, 1,
  <5, 8, 3>, 1,
  <5, 3, 1>, 1,
  <20, 26, 14>, 1,
  <20, 14, 10>, 1,
  <29, 39, 26>, 1,
  <29, 26, 20>, 1,
  <38, 48, 43>, 1,
  <38, 43, 33>, 1,
  <9, 13, 25>, 1,
  <9, 25, 18>, 1,
  <22, 33, 32>, 1,
  <22, 32, 21>, 1,
  <32, 43, 47>, 1,
  <32, 47, 37>, 1,
  <2, 9, 18>, 2,
  <2, 18, 17>, 2,
  <2, 17, 7>, 2,
  <31, 42, 50>, 2,
  <31, 50, 41>, 2,
  <31, 41, 30>, 2,
  <16, 28, 34>, 2,
  <16, 34, 23>, 2,
  <16, 23, 11>, 2,
  <44, 51, 52>, 2,
  <44, 52, 45>, 2,
  <44, 45, 40>, 2,
  <15, 27, 35>, 2,
  <15, 35, 24>, 2,
  <15, 24, 12>, 2,
  <46, 49, 39>, 2,
  <46, 39, 29>, 2,
  <46, 29, 36>, 2,
  <8, 19, 20>, 2,
  <8, 20, 10>, 2,
  <8, 10, 3>, 2,
  <26, 38, 33>, 2,
  <26, 33, 22>, 2,
  <26, 22, 14>, 2,
  <21, 32, 37>, 2,
  <21, 37, 25>, 2,
  <21, 25, 13>, 2,
  <0, 4, 6>, 2,
  <0, 6, 5>, 2,
  <0, 5, 1>, 2,
  <43, 48, 54>, 2,
  <43, 54, 53>, 2,
  <43, 53, 47>, 2,
  <1, 3, 10>, 3,
  <1, 10, 14>, 3,
  <1, 14, 22>, 3,
  <1, 22, 21>, 3,
  <1, 21, 13>, 3,
  <1, 13, 9>, 3,
  <1, 9, 2>, 3,
  <1, 2, 0>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1];
 #local P1 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3];
 #local P2 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10];
 #local P3 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P4 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22];
 #local P5 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21];
 #local P6 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13];
 #local P7 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9];
 #local P8 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2];
 #local P9 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_79_bigyrate_diminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_79_bigyrate_diminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  55,
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[4],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[5],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[6],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[7],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[8],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[11],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[12],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[15],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[16],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[17],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[18],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[19],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[20],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[23],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[24],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[25],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[26],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[27],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[28],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[29],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[30],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[31],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[32],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[33],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[34],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[35],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[36],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[37],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[38],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[39],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[40],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[41],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[42],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[43],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[44],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[45],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[46],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[47],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[48],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[49],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[50],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[51],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[52],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[53],
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[54]
 }
 face_indices {
  106,
  <7, 17, 16>,
  <30, 41, 28>,
  <18, 25, 31>,
  <37, 47, 42>,
  <4, 11, 6>,
  <23, 27, 15>,
  <34, 44, 40>,
  <50, 53, 51>,
  <5, 12, 8>,
  <35, 36, 24>,
  <45, 52, 46>,
  <54, 48, 49>,
  <19, 29, 20>,
  <39, 38, 26>,
  <33, 43, 32>,
  <0, 2, 7>,
  <0, 7, 4>,
  <17, 30, 28>,
  <17, 28, 16>,
  <28, 41, 44>,
  <28, 44, 34>,
  <18, 31, 30>,
  <18, 30, 17>,
  <25, 37, 42>,
  <25, 42, 31>,
  <42, 47, 53>,
  <42, 53, 50>,
  <7, 16, 11>,
  <7, 11, 4>,
  <11, 23, 15>,
  <11, 15, 6>,
  <27, 40, 45>,
  <27, 45, 35>,
  <34, 40, 27>,
  <34, 27, 23>,
  <41, 50, 51>,
  <41, 51, 44>,
  <51, 53, 54>,
  <51, 54, 52>,
  <6, 15, 12>,
  <6, 12, 5>,
  <12, 24, 19>,
  <12, 19, 8>,
  <24, 36, 29>,
  <24, 29, 19>,
  <45, 46, 36>,
  <45, 36, 35>,
  <52, 54, 49>,
  <52, 49, 46>,
  <49, 48, 38>,
  <49, 38, 39>,
  <5, 8, 3>,
  <5, 3, 1>,
  <20, 26, 14>,
  <20, 14, 10>,
  <29, 39, 26>,
  <29, 26, 20>,
  <38, 48, 43>,
  <38, 43, 33>,
  <9, 13, 25>,
  <9, 25, 18>,
  <22, 33, 32>,
  <22, 32, 21>,
  <32, 43, 47>,
  <32, 47, 37>,
  <2, 9, 18>,
  <2, 18, 17>,
  <2, 17, 7>,
  <31, 42, 50>,
  <31, 50, 41>,
  <31, 41, 30>,
  <16, 28, 34>,
  <16, 34, 23>,
  <16, 23, 11>,
  <44, 51, 52>,
  <44, 52, 45>,
  <44, 45, 40>,
  <15, 27, 35>,
  <15, 35, 24>,
  <15, 24, 12>,
  <46, 49, 39>,
  <46, 39, 29>,
  <46, 29, 36>,
  <8, 19, 20>,
  <8, 20, 10>,
  <8, 10, 3>,
  <26, 38, 33>,
  <26, 33, 22>,
  <26, 22, 14>,
  <21, 32, 37>,
  <21, 37, 25>,
  <21, 25, 13>,
  <0, 4, 6>,
  <0, 6, 5>,
  <0, 5, 1>,
  <43, 48, 54>,
  <43, 54, 53>,
  <43, 53, 47>,
  <1, 3, 10>,
  <1, 10, 14>,
  <1, 14, 22>,
  <1, 22, 21>,
  <1, 21, 13>,
  <1, 13, 9>,
  <1, 9, 2>,
  <1, 2, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1];
 #local P1 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3];
 #local P2 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10];
 #local P3 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P4 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22];
 #local P5 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21];
 #local P6 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13];
 #local P7 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9];
 #local P8 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2];
 #local P9 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_79_bigyrate_diminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_79_bigyrate_diminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[49], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[50], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[51], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[52], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[53], RadVer }
  sphere { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[54], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[7], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[17], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[16], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[30], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[41], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[28], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[18], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[31], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[37], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[47], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[42], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[4], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[11], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[6], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[23], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[27], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[15], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[34], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[44], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[40], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[50], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[53], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[51], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[5], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[12], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[8], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[35], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[36], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[24], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[45], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[52], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[46], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[54], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[48], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[49], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[19], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[29], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[20], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[39], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[38], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[26], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[33], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[43], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[32], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[7], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[4], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[17], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[28], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[41], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[34], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[31], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[17], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[25], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[42], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[47], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[53], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[50], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[16], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[11], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[15], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[27], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[40], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[45], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[35], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[23], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[41], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[50], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[51], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[53], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[54], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[54], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[52], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[52], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[51], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[15], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[5], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[12], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[24], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[19], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[36], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[46], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[49], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[48], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[39], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[8], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[20], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[26], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[29], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[48], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[33], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[18], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[32], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[43], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[37], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1], Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[1];
 #local P1 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[3];
 #local P2 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[10];
 #local P3 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[14];
 #local P4 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[22];
 #local P5 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[21];
 #local P6 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[13];
 #local P7 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[9];
 #local P8 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[2];
 #local P9 = Johnson_79_bigyrate_diminished_rhombicosidodecahedron_verts[0];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_80_parabidiminished_rhombicosidodecahedron_verts = array[50]
{
<-0.981435, -0.157408, -0.109585>,
<-0.942153, -0.069788, 0.327838>,
<-0.915510, 0.224660, -0.333721>,
<-0.851950, 0.366431, 0.374044>,
<-0.835484, 0.548410, -0.034822>,
<-0.804260, -0.387840, -0.450273>,
<-0.738335, -0.005772, -0.674410>,
<-0.701418, -0.158450, 0.694914>,
<-0.648132, 0.430447, -0.628204>,
<-0.611216, 0.277770, 0.741120>,
<-0.568107, 0.754197, -0.329305>,
<-0.545291, 0.659837, 0.516984>,
<-0.528825, 0.841816, 0.108118>,
<-0.478303, -0.673069, -0.564096>,
<-0.371634, -0.054870, -0.926756>,
<-0.351184, -0.389527, 0.851433>,
<-0.281432, 0.381349, -0.880550>,
<-0.210926, -0.467282, -0.858579>,
<-0.205234, 0.316291, 0.926196>,
<-0.151948, 0.905188, -0.396922>,
<-0.139309, 0.698359, 0.702060>,
<-0.128068, -0.904145, -0.407577>,
<-0.112666, 0.992807, 0.040501>,
<-0.044525, -0.096120, 0.994373>
<-0.025227, -0.674755, 0.737610>,
<0.025227, 0.674755, -0.737610>,
<0.044525, 0.096121, -0.994373>,
<0.112666, -0.992807, -0.040501>,
<0.128068, 0.904146, 0.407577>,
<0.139309, -0.698358, -0.702060>,
<0.151948, -0.905188, 0.396922>,
<0.205234, -0.316291, -0.926196>,
<0.210926, 0.467282, 0.858579>,
<0.281432, -0.381349, 0.880550>,
<0.351184, 0.389527, -0.851433>,
<0.371634, 0.054870, 0.926756>,
<0.478303, 0.673069, 0.564096>,
<0.528825, -0.841816, -0.108118>,
<0.545291, -0.659837, -0.516984>,
<0.568107, -0.754197, 0.329305>,
<0.611216, -0.277769, -0.741120>,
<0.648133, -0.430447, 0.628204>,
<0.701419, 0.158450, -0.694914>,
<0.738335, 0.005773, 0.674410>,
<0.804260, 0.387841, 0.450273>,
<0.835484, -0.548410, 0.034822>,
<0.851950, -0.366431, -0.374044>,
<0.915510, -0.224660, 0.333721>,
<0.942153, 0.069789, -0.327838>,
<0.981435, 0.157408, 0.109585>,
}
#declare P0 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28];
#declare P1 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36];
#declare P2 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 50)
 #declare Johnson_80_parabidiminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_80_parabidiminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_80_parabidiminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_80_parabidiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  50,
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[0],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[1],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[2],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[3],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[4],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[5],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[6],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[7],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[8],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[9],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[10],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[11],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[12],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[13],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[14],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[15],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[16],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[17],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[18],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[20],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[21],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[23],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[24],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[26],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[27],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[29],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[30],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[31],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[32],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[33],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[35],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[37],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[38],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[39],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[40],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[41],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[43],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[45],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[46],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[47],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  96,
  <12, 10, 4>, 0,
  <8, 6, 2>, 0,
  <16, 26, 14>, 0,
  <31, 29, 17>, 0,
  <11, 3, 9>, 0,
  <20, 18, 32>, 0,
  <23, 33, 35>, 0,
  <43, 41, 47>, 0,
  <39, 37, 45>, 0,
  <46, 38, 40>, 0,
  <22, 19, 10>, 1,
  <22, 10, 12>, 1,
  <10, 8, 2>, 1,
  <10, 2, 4>, 1,
  <2, 6, 5>, 1,
  <2, 5, 0>, 1,
  <16, 14, 6>, 1,
  <16, 6, 8>, 1,
  <26, 31, 17>, 1,
  <26, 17, 14>, 1,
  <17, 29, 21>, 1,
  <17, 21, 13>, 1,
  <12, 4, 3>, 1,
  <12, 3, 11>, 1,
  <3, 1, 7>, 1,
  <3, 7, 9>, 1,
  <11, 9, 18>, 1,
  <11, 18, 20>, 1,
  <18, 23, 35>, 1,
  <18, 35, 32>, 1,
  <35, 33, 41>, 1,
  <35, 41, 43>, 1,
  <15, 24, 33>, 1,
  <15, 33, 23>, 1,
  <30, 27, 37>, 1,
  <30, 37, 39>, 1,
  <20, 32, 36>, 1,
  <20, 36, 28>, 1,
  <43, 47, 49>, 1,
  <43, 49, 44>, 1,
  <41, 39, 45>, 1,
  <41, 45, 47>, 1,
  <45, 37, 38>, 1,
  <45, 38, 46>, 1,
  <25, 34, 26>, 1,
  <25, 26, 16>, 1,
  <48, 46, 40>, 1,
  <48, 40, 42>, 1,
  <40, 38, 29>, 1,
  <40, 29, 31>, 1,
  <19, 25, 16>, 2,
  <19, 16, 8>, 2,
  <19, 8, 10>, 2,
  <14, 17, 13>, 2,
  <14, 13, 5>, 2,
  <14, 5, 6>, 2,
  <4, 2, 0>, 2,
  <4, 0, 1>, 2,
  <4, 1, 3>, 2,
  <9, 7, 15>, 2,
  <9, 15, 23>, 2,
  <9, 23, 18>, 2,
  <24, 30, 39>, 2,
  <24, 39, 41>, 2,
  <24, 41, 33>, 2,
  <32, 35, 43>, 2,
  <32, 43, 44>, 2,
  <32, 44, 36>, 2,
  <47, 45, 46>, 2,
  <47, 46, 48>, 2,
  <47, 48, 49>, 2,
  <42, 40, 31>, 2,
  <42, 31, 26>, 2,
  <42, 26, 34>, 2,
  <22, 12, 11>, 2,
  <22, 11, 20>, 2,
  <22, 20, 28>, 2,
  <38, 37, 27>, 2,
  <38, 27, 21>, 2,
  <38, 21, 29>, 2,
  <24, 15, 7>, 3,
  <24, 7, 1>, 3,
  <24, 1, 0>, 3,
  <24, 0, 5>, 3,
  <24, 5, 13>, 3,
  <24, 13, 21>, 3,
  <24, 21, 27>, 3,
  <24, 27, 30>, 3,
  <28, 36, 44>, 3,
  <28, 44, 49>, 3,
  <28, 49, 48>, 3,
  <28, 48, 42>, 3,
  <28, 42, 34>, 3,
  <28, 34, 25>, 3,
  <28, 25, 19>, 3,
  <28, 19, 22>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28];
 #local P1 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36];
 #local P2 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44];
 #local P3 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49];
 #local P4 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48];
 #local P5 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42];
 #local P6 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34];
 #local P7 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25];
 #local P8 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19];
 #local P9 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_80_parabidiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_80_parabidiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_80_parabidiminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_80_parabidiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  50,
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[0],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[1],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[2],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[3],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[4],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[5],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[6],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[7],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[8],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[9],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[10],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[11],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[12],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[13],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[14],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[15],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[16],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[17],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[18],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[20],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[21],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[23],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[24],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[26],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[27],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[29],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[30],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[31],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[32],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[33],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[35],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[37],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[38],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[39],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[40],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[41],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[43],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[45],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[46],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[47],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48],
  Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49]
 }
 face_indices {
  96,
  <12, 10, 4>,
  <8, 6, 2>,
  <16, 26, 14>,
  <31, 29, 17>,
  <11, 3, 9>,
  <20, 18, 32>,
  <23, 33, 35>,
  <43, 41, 47>,
  <39, 37, 45>,
  <46, 38, 40>,
  <22, 19, 10>,
  <22, 10, 12>,
  <10, 8, 2>,
  <10, 2, 4>,
  <2, 6, 5>,
  <2, 5, 0>,
  <16, 14, 6>,
  <16, 6, 8>,
  <26, 31, 17>,
  <26, 17, 14>,
  <17, 29, 21>,
  <17, 21, 13>,
  <12, 4, 3>,
  <12, 3, 11>,
  <3, 1, 7>,
  <3, 7, 9>,
  <11, 9, 18>,
  <11, 18, 20>,
  <18, 23, 35>,
  <18, 35, 32>,
  <35, 33, 41>,
  <35, 41, 43>,
  <15, 24, 33>,
  <15, 33, 23>,
  <30, 27, 37>,
  <30, 37, 39>,
  <20, 32, 36>,
  <20, 36, 28>,
  <43, 47, 49>,
  <43, 49, 44>,
  <41, 39, 45>,
  <41, 45, 47>,
  <45, 37, 38>,
  <45, 38, 46>,
  <25, 34, 26>,
  <25, 26, 16>,
  <48, 46, 40>,
  <48, 40, 42>,
  <40, 38, 29>,
  <40, 29, 31>,
  <19, 25, 16>,
  <19, 16, 8>,
  <19, 8, 10>,
  <14, 17, 13>,
  <14, 13, 5>,
  <14, 5, 6>,
  <4, 2, 0>,
  <4, 0, 1>,
  <4, 1, 3>,
  <9, 7, 15>,
  <9, 15, 23>,
  <9, 23, 18>,
  <24, 30, 39>,
  <24, 39, 41>,
  <24, 41, 33>,
  <32, 35, 43>,
  <32, 43, 44>,
  <32, 44, 36>,
  <47, 45, 46>,
  <47, 46, 48>,
  <47, 48, 49>,
  <42, 40, 31>,
  <42, 31, 26>,
  <42, 26, 34>,
  <22, 12, 11>,
  <22, 11, 20>,
  <22, 20, 28>,
  <38, 37, 27>,
  <38, 27, 21>,
  <38, 21, 29>,
  <24, 15, 7>,
  <24, 7, 1>,
  <24, 1, 0>,
  <24, 0, 5>,
  <24, 5, 13>,
  <24, 13, 21>,
  <24, 21, 27>,
  <24, 27, 30>,
  <28, 36, 44>,
  <28, 44, 49>,
  <28, 49, 48>,
  <28, 48, 42>,
  <28, 42, 34>,
  <28, 34, 25>,
  <28, 25, 19>,
  <28, 19, 22>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28];
 #local P1 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36];
 #local P2 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44];
 #local P3 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49];
 #local P4 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48];
 #local P5 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42];
 #local P6 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34];
 #local P7 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25];
 #local P8 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19];
 #local P9 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_80_parabidiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_80_parabidiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_80_parabidiminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[12], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[10], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[4], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[8], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[6], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[2], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[16], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[26], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[14], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[31], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[29], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[17], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[11], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[3], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[9], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[20], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[18], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[32], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[23], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[33], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[35], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[43], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[41], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[47], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[39], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[37], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[45], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[46], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[38], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[40], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[12], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[10], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[2], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[6], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[5], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[0], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[14], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[8], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[26], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[17], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[29], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[21], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[13], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[4], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[11], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[3], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[1], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[7], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[9], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[20], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[18], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[35], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[33], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[43], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[15], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[24], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[23], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[30], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[27], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[39], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[32], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[47], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[41], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[45], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[37], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[46], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[16], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[40], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[38], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[31], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[13], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[0], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[7], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[24], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_80_parabidiminished_rhombicosidodecahedron_verts[27], Johnson_80_parabidiminished_rhombicosidodecahedron_verts[21], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[28];
 #local P1 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[36];
 #local P2 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[44];
 #local P3 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[49];
 #local P4 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[48];
 #local P5 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[42];
 #local P6 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[34];
 #local P7 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[25];
 #local P8 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[19];
 #local P9 = Johnson_80_parabidiminished_rhombicosidodecahedron_verts[22];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_81_metabidiminished_rhombicosidodecahedron_verts = array[50]
{
<-0.915540, -0.171560, 0.190699>,
<-0.874123, -0.218610, -0.254883>,
<-0.873513, 0.274357, 0.147520>,
<-0.832096, 0.227307, -0.298062>,
<-0.790984, -0.567471, 0.016881>,
<-0.738991, -0.290113, 0.587244>,
<-0.680957, 0.599954, -0.096163>,
<-0.670991, 0.431396, 0.517379>,
<-0.630562, -0.413291, -0.579305>,
<-0.614436, -0.686024, 0.413427>,
<-0.587852, 0.082534, 0.789144>,
<-0.562561, 0.308217, -0.649170>,
<-0.547423, -0.762153, -0.307540>,
<-0.478435, 0.756993, 0.273697>,
<-0.438006, -0.087694, -0.822987>,
<-0.411421, 0.680864, -0.447270>,
<-0.301886, 0.638440, 0.670242>,
<-0.277887, -0.681242, -0.658648>,
<-0.261761, -0.953976, 0.334084>,
<-0.220345, -1.001026, -0.111498>,
<-0.218747, 0.289578, 0.942007>,
<-0.167860, 0.486183, -0.771692>,
<-0.085331, -0.355646, -0.902330>,
<-0.083733, 0.934958, 0.151175>
<-0.043304, 0.090271, -0.945509>,
<-0.042317, 0.887908, -0.294407>,
<0.049191, -0.920115, -0.462606>,
<0.092815, 0.816405, 0.547720>,
<0.184323, -0.991618, 0.379522>,
<0.201245, 0.693227, -0.618829>,
<0.225739, -1.038668, -0.066060>,
<0.227337, 0.251936, 0.987445>,
<0.360753, -0.393288, -0.856892>,
<0.362351, 0.897316, 0.196613>,
<0.402780, 0.052629, -0.900071>,
<0.403767, 0.850266, -0.248970>,
<0.419893, 0.577533, 0.743762>,
<0.443892, -0.742150, -0.585128>,
<0.553427, -0.784574, 0.532385>,
<0.553919, 0.425276, -0.698172>,
<0.580011, -0.016016, 0.908102>,
<0.620440, -0.860702, -0.188582>,
<0.689428, 0.658443, 0.392655>,
<0.704567, -0.411927, 0.734284>,
<0.756442, 0.582315, -0.328312>,
<0.772567, 0.309582, 0.664419>,
<0.822963, -0.703664, 0.181277>,
<0.932990, 0.463762, 0.068233>,
<0.974102, -0.331017, 0.383177>,
<1.016129, 0.114900, 0.339998>,
}
#declare P0 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47];
#declare P1 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49];
#declare P2 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 50)
 #declare Johnson_81_metabidiminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_81_metabidiminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_81_metabidiminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_81_metabidiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  50,
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[0],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[1],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[2],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[3],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[4],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[5],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[6],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[7],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[8],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[9],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[10],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[11],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[12],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[13],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[14],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[15],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[16],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[17],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[18],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[19],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[20],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[21],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[22],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[23],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[24],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[25],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[26],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[27],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[28],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[29],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[30],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[31],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[33],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[35],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[36],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[38],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[40],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[42],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[43],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[45],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  96,
  <35, 29, 25>, 0,
  <21, 11, 15>, 0,
  <24, 22, 14>, 0,
  <17, 12, 8>, 0,
  <33, 23, 27>, 0,
  <13, 7, 16>, 0,
  <6, 3, 2>, 0,
  <1, 4, 0>, 0,
  <42, 36, 45>, 0,
  <30, 19, 26>, 0,
  <44, 39, 29>, 1,
  <44, 29, 35>, 1,
  <29, 21, 15>, 1,
  <29, 15, 25>, 1,
  <15, 11, 3>, 1,
  <15, 3, 6>, 1,
  <24, 14, 11>, 1,
  <24, 11, 21>, 1,
  <22, 17, 8>, 1,
  <22, 8, 14>, 1,
  <8, 12, 4>, 1,
  <8, 4, 1>, 1,
  <35, 25, 23>, 1,
  <35, 23, 33>, 1,
  <23, 13, 16>, 1,
  <23, 16, 27>, 1,
  <16, 7, 10>, 1,
  <16, 10, 20>, 1,
  <6, 2, 7>, 1,
  <6, 7, 13>, 1,
  <3, 1, 0>, 1,
  <3, 0, 2>, 1,
  <0, 4, 9>, 1,
  <0, 9, 5>, 1,
  <33, 27, 36>, 1,
  <33, 36, 42>, 1,
  <36, 31, 40>, 1,
  <36, 40, 45>, 1,
  <42, 45, 49>, 1,
  <42, 49, 47>, 1,
  <43, 38, 46>, 1,
  <43, 46, 48>, 1,
  <28, 18, 19>, 1,
  <28, 19, 30>, 1,
  <34, 32, 22>, 1,
  <34, 22, 24>, 1,
  <41, 30, 26>, 1,
  <41, 26, 37>, 1,
  <26, 19, 12>, 1,
  <26, 12, 17>, 1,
  <39, 34, 24>, 2,
  <39, 24, 21>, 2,
  <39, 21, 29>, 2,
  <14, 8, 1>, 2,
  <14, 1, 3>, 2,
  <14, 3, 11>, 2,
  <25, 15, 6>, 2,
  <25, 6, 13>, 2,
  <25, 13, 23>, 2,
  <2, 0, 5>, 2,
  <2, 5, 10>, 2,
  <2, 10, 7>, 2,
  <27, 16, 20>, 2,
  <27, 20, 31>, 2,
  <27, 31, 36>, 2,
  <45, 40, 43>, 2,
  <45, 43, 48>, 2,
  <45, 48, 49>, 2,
  <38, 28, 30>, 2,
  <38, 30, 41>, 2,
  <38, 41, 46>, 2,
  <37, 26, 17>, 2,
  <37, 17, 22>, 2,
  <37, 22, 32>, 2,
  <44, 35, 33>, 2,
  <44, 33, 42>, 2,
  <44, 42, 47>, 2,
  <19, 18, 9>, 2,
  <19, 9, 4>, 2,
  <19, 4, 12>, 2,
  <38, 43, 40>, 3,
  <38, 40, 31>, 3,
  <38, 31, 20>, 3,
  <38, 20, 10>, 3,
  <38, 10, 5>, 3,
  <38, 5, 9>, 3,
  <38, 9, 18>, 3,
  <38, 18, 28>, 3,
  <47, 49, 48>, 3,
  <47, 48, 46>, 3,
  <47, 46, 41>, 3,
  <47, 41, 37>, 3,
  <47, 37, 32>, 3,
  <47, 32, 34>, 3,
  <47, 34, 39>, 3,
  <47, 39, 44>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47];
 #local P1 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49];
 #local P2 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48];
 #local P3 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46];
 #local P4 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41];
 #local P5 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37];
 #local P6 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32];
 #local P7 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34];
 #local P8 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39];
 #local P9 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_81_metabidiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_81_metabidiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_81_metabidiminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_81_metabidiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  50,
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[0],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[1],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[2],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[3],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[4],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[5],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[6],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[7],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[8],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[9],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[10],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[11],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[12],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[13],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[14],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[15],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[16],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[17],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[18],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[19],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[20],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[21],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[22],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[23],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[24],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[25],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[26],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[27],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[28],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[29],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[30],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[31],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[33],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[35],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[36],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[38],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[40],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[42],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[43],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[45],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48],
  Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49]
 }
 face_indices {
  96,
  <35, 29, 25>,
  <21, 11, 15>,
  <24, 22, 14>,
  <17, 12, 8>,
  <33, 23, 27>,
  <13, 7, 16>,
  <6, 3, 2>,
  <1, 4, 0>,
  <42, 36, 45>,
  <30, 19, 26>,
  <44, 39, 29>,
  <44, 29, 35>,
  <29, 21, 15>,
  <29, 15, 25>,
  <15, 11, 3>,
  <15, 3, 6>,
  <24, 14, 11>,
  <24, 11, 21>,
  <22, 17, 8>,
  <22, 8, 14>,
  <8, 12, 4>,
  <8, 4, 1>,
  <35, 25, 23>,
  <35, 23, 33>,
  <23, 13, 16>,
  <23, 16, 27>,
  <16, 7, 10>,
  <16, 10, 20>,
  <6, 2, 7>,
  <6, 7, 13>,
  <3, 1, 0>,
  <3, 0, 2>,
  <0, 4, 9>,
  <0, 9, 5>,
  <33, 27, 36>,
  <33, 36, 42>,
  <36, 31, 40>,
  <36, 40, 45>,
  <42, 45, 49>,
  <42, 49, 47>,
  <43, 38, 46>,
  <43, 46, 48>,
  <28, 18, 19>,
  <28, 19, 30>,
  <34, 32, 22>,
  <34, 22, 24>,
  <41, 30, 26>,
  <41, 26, 37>,
  <26, 19, 12>,
  <26, 12, 17>,
  <39, 34, 24>,
  <39, 24, 21>,
  <39, 21, 29>,
  <14, 8, 1>,
  <14, 1, 3>,
  <14, 3, 11>,
  <25, 15, 6>,
  <25, 6, 13>,
  <25, 13, 23>,
  <2, 0, 5>,
  <2, 5, 10>,
  <2, 10, 7>,
  <27, 16, 20>,
  <27, 20, 31>,
  <27, 31, 36>,
  <45, 40, 43>,
  <45, 43, 48>,
  <45, 48, 49>,
  <38, 28, 30>,
  <38, 30, 41>,
  <38, 41, 46>,
  <37, 26, 17>,
  <37, 17, 22>,
  <37, 22, 32>,
  <44, 35, 33>,
  <44, 33, 42>,
  <44, 42, 47>,
  <19, 18, 9>,
  <19, 9, 4>,
  <19, 4, 12>,
  <38, 43, 40>,
  <38, 40, 31>,
  <38, 31, 20>,
  <38, 20, 10>,
  <38, 10, 5>,
  <38, 5, 9>,
  <38, 9, 18>,
  <38, 18, 28>,
  <47, 49, 48>,
  <47, 48, 46>,
  <47, 46, 41>,
  <47, 41, 37>,
  <47, 37, 32>,
  <47, 32, 34>,
  <47, 34, 39>,
  <47, 39, 44>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47];
 #local P1 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49];
 #local P2 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48];
 #local P3 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46];
 #local P4 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41];
 #local P5 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37];
 #local P6 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32];
 #local P7 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34];
 #local P8 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39];
 #local P9 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_81_metabidiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_81_metabidiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_81_metabidiminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[35], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[29], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[25], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[21], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[11], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[15], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[24], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[22], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[14], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[17], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[12], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[8], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[33], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[23], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[27], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[13], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[7], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[16], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[6], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[3], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[2], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[1], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[4], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[0], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[42], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[36], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[45], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[30], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[19], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[26], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[35], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[29], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[15], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[11], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[6], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[14], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[21], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[22], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[8], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[12], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[1], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[25], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[33], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[23], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[16], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[7], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[10], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[20], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[2], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[13], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[3], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[0], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[4], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[9], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[5], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[27], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[42], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[36], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[31], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[40], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[45], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[43], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[38], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[28], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[18], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[30], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[24], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[26], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[19], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[17], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[5], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[20], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[40], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[38], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_81_metabidiminished_rhombicosidodecahedron_verts[18], Johnson_81_metabidiminished_rhombicosidodecahedron_verts[9], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[47];
 #local P1 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[49];
 #local P2 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[48];
 #local P3 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[46];
 #local P4 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[41];
 #local P5 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[37];
 #local P6 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[32];
 #local P7 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[34];
 #local P8 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[39];
 #local P9 = Johnson_81_metabidiminished_rhombicosidodecahedron_verts[44];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts = array[50]
{
<-0.915244, -0.149547, 0.004878>,
<-0.857812, 0.261033, -0.170045>,
<-0.853796, 0.017864, 0.418001>,
<-0.796364, 0.428444, 0.243078>,
<-0.772518, -0.333547, -0.380149>,
<-0.759676, -0.571754, 0.001381>,
<-0.715086, 0.077033, -0.555071>,
<-0.660252, -0.300878, 0.669827>,
<-0.638771, 0.334916, 0.654040>,
<-0.609317, 0.503159, -0.456572>,
<-0.602083, -0.665282, 0.412342>,
<-0.509893, 0.774035, 0.211875>,
<-0.463372, -0.606112, -0.560730>,
<-0.450530, -0.844319, -0.179200>,
<-0.445227, 0.016174, 0.905866>,
<-0.394292, 0.820211, -0.220533>,
<-0.370445, 0.058220, -0.843760>,
<-0.352300, 0.680507, 0.622836>,
<-0.292937, -0.937847, 0.231761>,
<-0.264676, 0.484346, -0.745261>,
<-0.214877, -0.363987, -0.847257>,
<-0.105889, -0.863132, -0.467889>,
<-0.103806, 0.922633, 0.336308>,
<-0.049651, 0.801399, -0.509222>
<-0.039139, 0.164772, 1.030300>,
<0.011796, 0.968809, -0.096099>,
<0.018293, 0.575352, 0.855378>,
<0.044470, 0.211781, -0.925842>,
<0.142605, -0.621006, -0.754417>,
<0.149102, -1.014463, 0.197061>,
<0.200037, -0.210426, -0.929339>,
<0.264704, -0.968287, -0.235347>,
<0.266787, 0.817478, 0.568850>,
<0.392388, 0.724782, -0.543923>,
<0.402900, 0.088156, 0.995600>,
<0.450558, 0.360379, -0.801408>,
<0.453835, 0.892193, -0.130800>,
<0.460331, 0.498736, 0.820677>,
<0.513198, -0.726161, -0.521875>,
<0.555190, -0.865866, 0.321494>,
<0.606125, -0.061828, -0.804905>,
<0.611428, 0.798665, 0.280161>,
<0.670792, -0.819689, -0.110913>,
<0.712045, -0.184410, 0.815019>,
<0.770215, -0.548813, 0.557534>,
<0.799669, -0.380570, -0.553078>,
<0.804972, 0.479923, 0.531988>,
<0.957263, -0.474098, -0.142117>,
<0.960540, 0.057716, 0.528491>,
<1.018710, -0.306688, 0.271006>,
}
#declare P0 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41];
#declare P1 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46];
#declare P2 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 50)
 #declare Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  50,
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[0],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[1],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[2],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[3],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[4],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[5],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[6],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[7],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[8],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[9],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[10],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[11],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[12],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[13],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[14],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[15],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[16],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[17],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[18],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[19],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[20],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[21],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[22],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[23],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[24],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[25],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[26],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[27],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[28],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[29],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[30],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[31],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[32],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[34],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[37],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[38],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[39],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[42],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[43],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[44],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  96,
  <25, 23, 15>, 0,
  <27, 16, 19>, 0,
  <30, 28, 20>, 0,
  <21, 13, 12>, 0,
  <22, 11, 17>, 0,
  <3, 2, 8>, 0,
  <9, 6, 1>, 0,
  <4, 5, 0>, 0,
  <32, 26, 37>, 0,
  <42, 31, 38>, 0,
  <36, 33, 23>, 1,
  <36, 23, 25>, 1,
  <23, 19, 9>, 1,
  <23, 9, 15>, 1,
  <19, 16, 6>, 1,
  <19, 6, 9>, 1,
  <30, 20, 16>, 1,
  <30, 16, 27>, 1,
  <28, 21, 12>, 1,
  <28, 12, 20>, 1,
  <12, 13, 5>, 1,
  <12, 5, 4>, 1,
  <25, 15, 11>, 1,
  <25, 11, 22>, 1,
  <11, 3, 8>, 1,
  <11, 8, 17>, 1,
  <8, 2, 7>, 1,
  <8, 7, 14>, 1,
  <1, 0, 2>, 1,
  <1, 2, 3>, 1,
  <6, 4, 0>, 1,
  <6, 0, 1>, 1,
  <5, 13, 18>, 1,
  <5, 18, 10>, 1,
  <22, 17, 26>, 1,
  <22, 26, 32>, 1,
  <26, 24, 34>, 1,
  <26, 34, 37>, 1,
  <32, 37, 46>, 1,
  <32, 46, 41>, 1,
  <43, 44, 49>, 1,
  <43, 49, 48>, 1,
  <39, 29, 31>, 1,
  <39, 31, 42>, 1,
  <35, 40, 30>, 1,
  <35, 30, 27>, 1,
  <47, 42, 38>, 1,
  <47, 38, 45>, 1,
  <38, 31, 21>, 1,
  <38, 21, 28>, 1,
  <33, 35, 27>, 2,
  <33, 27, 19>, 2,
  <33, 19, 23>, 2,
  <20, 12, 4>, 2,
  <20, 4, 6>, 2,
  <20, 6, 16>, 2,
  <15, 9, 1>, 2,
  <15, 1, 3>, 2,
  <15, 3, 11>, 2,
  <0, 5, 10>, 2,
  <0, 10, 7>, 2,
  <0, 7, 2>, 2,
  <17, 8, 14>, 2,
  <17, 14, 24>, 2,
  <17, 24, 26>, 2,
  <37, 34, 43>, 2,
  <37, 43, 48>, 2,
  <37, 48, 46>, 2,
  <44, 39, 42>, 2,
  <44, 42, 47>, 2,
  <44, 47, 49>, 2,
  <45, 38, 28>, 2,
  <45, 28, 30>, 2,
  <45, 30, 40>, 2,
  <36, 25, 22>, 2,
  <36, 22, 32>, 2,
  <36, 32, 41>, 2,
  <31, 29, 18>, 2,
  <31, 18, 13>, 2,
  <31, 13, 21>, 2,
  <44, 43, 34>, 3,
  <44, 34, 24>, 3,
  <44, 24, 14>, 3,
  <44, 14, 7>, 3,
  <44, 7, 10>, 3,
  <44, 10, 18>, 3,
  <44, 18, 29>, 3,
  <44, 29, 39>, 3,
  <41, 46, 48>, 3,
  <41, 48, 49>, 3,
  <41, 49, 47>, 3,
  <41, 47, 45>, 3,
  <41, 45, 40>, 3,
  <41, 40, 35>, 3,
  <41, 35, 33>, 3,
  <41, 33, 36>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41];
 #local P1 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46];
 #local P2 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48];
 #local P3 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49];
 #local P4 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47];
 #local P5 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45];
 #local P6 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40];
 #local P7 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35];
 #local P8 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33];
 #local P9 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  50,
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[0],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[1],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[2],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[3],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[4],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[5],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[6],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[7],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[8],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[9],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[10],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[11],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[12],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[13],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[14],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[15],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[16],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[17],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[18],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[19],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[20],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[21],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[22],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[23],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[24],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[25],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[26],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[27],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[28],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[29],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[30],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[31],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[32],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[34],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[37],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[38],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[39],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[42],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[43],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[44],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48],
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49]
 }
 face_indices {
  96,
  <25, 23, 15>,
  <27, 16, 19>,
  <30, 28, 20>,
  <21, 13, 12>,
  <22, 11, 17>,
  <3, 2, 8>,
  <9, 6, 1>,
  <4, 5, 0>,
  <32, 26, 37>,
  <42, 31, 38>,
  <36, 33, 23>,
  <36, 23, 25>,
  <23, 19, 9>,
  <23, 9, 15>,
  <19, 16, 6>,
  <19, 6, 9>,
  <30, 20, 16>,
  <30, 16, 27>,
  <28, 21, 12>,
  <28, 12, 20>,
  <12, 13, 5>,
  <12, 5, 4>,
  <25, 15, 11>,
  <25, 11, 22>,
  <11, 3, 8>,
  <11, 8, 17>,
  <8, 2, 7>,
  <8, 7, 14>,
  <1, 0, 2>,
  <1, 2, 3>,
  <6, 4, 0>,
  <6, 0, 1>,
  <5, 13, 18>,
  <5, 18, 10>,
  <22, 17, 26>,
  <22, 26, 32>,
  <26, 24, 34>,
  <26, 34, 37>,
  <32, 37, 46>,
  <32, 46, 41>,
  <43, 44, 49>,
  <43, 49, 48>,
  <39, 29, 31>,
  <39, 31, 42>,
  <35, 40, 30>,
  <35, 30, 27>,
  <47, 42, 38>,
  <47, 38, 45>,
  <38, 31, 21>,
  <38, 21, 28>,
  <33, 35, 27>,
  <33, 27, 19>,
  <33, 19, 23>,
  <20, 12, 4>,
  <20, 4, 6>,
  <20, 6, 16>,
  <15, 9, 1>,
  <15, 1, 3>,
  <15, 3, 11>,
  <0, 5, 10>,
  <0, 10, 7>,
  <0, 7, 2>,
  <17, 8, 14>,
  <17, 14, 24>,
  <17, 24, 26>,
  <37, 34, 43>,
  <37, 43, 48>,
  <37, 48, 46>,
  <44, 39, 42>,
  <44, 42, 47>,
  <44, 47, 49>,
  <45, 38, 28>,
  <45, 28, 30>,
  <45, 30, 40>,
  <36, 25, 22>,
  <36, 22, 32>,
  <36, 32, 41>,
  <31, 29, 18>,
  <31, 18, 13>,
  <31, 13, 21>,
  <44, 43, 34>,
  <44, 34, 24>,
  <44, 24, 14>,
  <44, 14, 7>,
  <44, 7, 10>,
  <44, 10, 18>,
  <44, 18, 29>,
  <44, 29, 39>,
  <41, 46, 48>,
  <41, 48, 49>,
  <41, 49, 47>,
  <41, 47, 45>,
  <41, 45, 40>,
  <41, 40, 35>,
  <41, 35, 33>,
  <41, 33, 36>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41];
 #local P1 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46];
 #local P2 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48];
 #local P3 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49];
 #local P4 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47];
 #local P5 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45];
 #local P6 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40];
 #local P7 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35];
 #local P8 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33];
 #local P9 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[44], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48], RadVer }
  sphere { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[25], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[23], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[15], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[27], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[16], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[19], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[30], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[28], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[20], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[21], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[13], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[12], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[22], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[11], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[17], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[3], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[2], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[8], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[9], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[6], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[1], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[4], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[5], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[0], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[32], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[26], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[37], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[42], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[31], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[38], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[25], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[23], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[19], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[9], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[16], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[20], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[27], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[28], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[12], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[13], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[4], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[15], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[22], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[11], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[8], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[2], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[7], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[14], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[1], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[0], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[3], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[6], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[13], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[18], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[10], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[17], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[32], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[26], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[24], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[34], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[37], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[43], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[44], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[39], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[29], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[42], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[27], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[38], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[31], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[28], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[10], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[14], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[34], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[44], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[29], Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[18], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[41];
 #local P1 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[46];
 #local P2 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[48];
 #local P3 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[49];
 #local P4 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[47];
 #local P5 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[45];
 #local P6 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[40];
 #local P7 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[35];
 #local P8 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[33];
 #local P9 = Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_verts[36];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_83_tridiminished_rhombicosidodecahedron_verts = array[45]
{
<-0.932936, 0.189273, 0.192295>,
<-0.922398, 0.241407, -0.253129>,
<-0.911995, -0.249962, 0.280987>,
<-0.894943, -0.165606, -0.439724>,
<-0.888514, -0.469289, -0.109623>,
<-0.719187, 0.580372, 0.243128>,
<-0.712758, 0.276690, 0.573230>,
<-0.708649, 0.632507, -0.202295>,
<-0.691817, -0.162545, 0.661922>,
<-0.636773, -0.433068, -0.690809>,
<-0.630343, -0.736751, -0.360707>,
<-0.352393, 0.773950, 0.414070>,
<-0.345964, 0.470268, 0.744172>,
<-0.335341, 0.858306, -0.306641>,
<-0.312080, -0.240428, 0.887678>,
<-0.246498, -0.458817, -0.910477>,
<-0.236095, -0.950186, -0.376361>,
<-0.115163, 0.945723, 0.074294>,
<-0.098331, 0.150671, 0.938511>,
<0.001135, -0.778414, -0.716137>,
<0.027344, 0.696067, 0.639826>,
<0.054934, 0.832556, -0.526309>,
<0.082168, -0.453864, 0.872024>,
<0.126810, -0.233018, -1.014822>
<0.143641, -1.028070, -0.150605>,
<0.264573, 0.867839, 0.300050>,
<0.274976, 0.376470, 0.834165>,
<0.275112, 0.919973, -0.145374>,
<0.295917, -0.062764, 0.922857>,
<0.313104, 0.565095, -0.777393>,
<0.340339, -0.721326, 0.620939>,
<0.340559, 0.158081, -0.963989>,
<0.363820, -0.940653, 0.230330>,
<0.374442, -0.552615, -0.820483>,
<0.380871, -0.856297, -0.490381>,
<0.658822, 0.654404, 0.284396>,
<0.665251, 0.350721, 0.614498>,
<0.669360, 0.706538, -0.161028>,
<0.686192, -0.088513, 0.703189>,
<0.692841, 0.487211, -0.551637>,
<0.713646, -0.495527, 0.516594>,
<0.720295, 0.080198, -0.738233>,
<0.737127, -0.714854, 0.125984>,
<0.741236, -0.359037, -0.649541>,
<0.747665, -0.662719, -0.319440>,
}
#declare P0 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[36];
#declare P1 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[38];
#declare P2 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[40];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 45)
 #declare Johnson_83_tridiminished_rhombicosidodecahedron_verts[Num] = vtransform(Johnson_83_tridiminished_rhombicosidodecahedron_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_83_tridiminished_rhombicosidodecahedron_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_83_tridiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  45,
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[0],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[1],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[2],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[3],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[4],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[5],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[6],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[7],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[8],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[9],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[10],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[11],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[12],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[13],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[14],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[15],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[16],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[17],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[18],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[19],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[20],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[21],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[22],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[23],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[24],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[25],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[26],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[27],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[28],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[29],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[30],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[31],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[32],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[33],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[34],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[35],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[36],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[37],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[38],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[39],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[40],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[41],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[42],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[43],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[44]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  86,
  <25, 27, 17>, 0,
  <20, 11, 12>, 0,
  <5, 0, 6>, 0,
  <26, 18, 28>, 0,
  <34, 19, 33>, 0,
  <35, 37, 27>, 1,
  <35, 27, 25>, 1,
  <27, 21, 13>, 1,
  <27, 13, 17>, 1,
  <25, 17, 11>, 1,
  <25, 11, 20>, 1,
  <11, 5, 6>, 1,
  <11, 6, 12>, 1,
  <6, 0, 2>, 1,
  <6, 2, 8>, 1,
  <7, 1, 0>, 1,
  <7, 0, 5>, 1,
  <3, 9, 10>, 1,
  <3, 10, 4>, 1,
  <20, 12, 18>, 1,
  <20, 18, 26>, 1,
  <18, 14, 22>, 1,
  <18, 22, 28>, 1,
  <26, 28, 38>, 1,
  <26, 38, 36>, 1,
  <30, 32, 42>, 1,
  <30, 42, 40>, 1,
  <24, 16, 19>, 1,
  <24, 19, 34>, 1,
  <39, 41, 31>, 1,
  <39, 31, 29>, 1,
  <44, 34, 33>, 1,
  <44, 33, 43>, 1,
  <33, 19, 15>, 1,
  <33, 15, 23>, 1,
  <37, 39, 29>, 2,
  <37, 29, 21>, 2,
  <37, 21, 27>, 2,
  <17, 13, 7>, 2,
  <17, 7, 5>, 2,
  <17, 5, 11>, 2,
  <1, 3, 4>, 2,
  <1, 4, 2>, 2,
  <1, 2, 0>, 2,
  <12, 6, 8>, 2,
  <12, 8, 14>, 2,
  <12, 14, 18>, 2,
  <28, 22, 30>, 2,
  <28, 30, 40>, 2,
  <28, 40, 38>, 2,
  <32, 24, 34>, 2,
  <32, 34, 44>, 2,
  <32, 44, 42>, 2,
  <43, 33, 23>, 2,
  <43, 23, 31>, 2,
  <43, 31, 41>, 2,
  <35, 25, 20>, 2,
  <35, 20, 26>, 2,
  <35, 26, 36>, 2,
  <19, 16, 10>, 2,
  <19, 10, 9>, 2,
  <19, 9, 15>, 2,
  <1, 7, 13>, 3,
  <1, 13, 21>, 3,
  <1, 21, 29>, 3,
  <1, 29, 31>, 3,
  <1, 31, 23>, 3,
  <1, 23, 15>, 3,
  <1, 15, 9>, 3,
  <1, 9, 3>, 3,
  <32, 30, 22>, 3,
  <32, 22, 14>, 3,
  <32, 14, 8>, 3,
  <32, 8, 2>, 3,
  <32, 2, 4>, 3,
  <32, 4, 10>, 3,
  <32, 10, 16>, 3,
  <32, 16, 24>, 3,
  <36, 38, 40>, 3,
  <36, 40, 42>, 3,
  <36, 42, 44>, 3,
  <36, 44, 43>, 3,
  <36, 43, 41>, 3,
  <36, 41, 39>, 3,
  <36, 39, 37>, 3,
  <36, 37, 35>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[36];
 #local P1 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[38];
 #local P2 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[40];
 #local P3 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[42];
 #local P4 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[44];
 #local P5 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[43];
 #local P6 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[41];
 #local P7 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[39];
 #local P8 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[37];
 #local P9 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[35];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_83_tridiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_83_tridiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_83_tridiminished_rhombicosidodecahedron_faces2(OnPlane)
#local Johnson_83_tridiminished_rhombicosidodecahedron_obj = mesh2 {
 vertex_vectors {
  45,
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[0],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[1],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[2],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[3],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[4],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[5],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[6],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[7],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[8],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[9],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[10],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[11],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[12],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[13],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[14],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[15],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[16],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[17],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[18],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[19],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[20],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[21],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[22],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[23],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[24],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[25],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[26],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[27],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[28],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[29],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[30],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[31],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[32],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[33],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[34],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[35],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[36],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[37],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[38],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[39],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[40],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[41],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[42],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[43],
  Johnson_83_tridiminished_rhombicosidodecahedron_verts[44]
 }
 face_indices {
  86,
  <25, 27, 17>,
  <20, 11, 12>,
  <5, 0, 6>,
  <26, 18, 28>,
  <34, 19, 33>,
  <35, 37, 27>,
  <35, 27, 25>,
  <27, 21, 13>,
  <27, 13, 17>,
  <25, 17, 11>,
  <25, 11, 20>,
  <11, 5, 6>,
  <11, 6, 12>,
  <6, 0, 2>,
  <6, 2, 8>,
  <7, 1, 0>,
  <7, 0, 5>,
  <3, 9, 10>,
  <3, 10, 4>,
  <20, 12, 18>,
  <20, 18, 26>,
  <18, 14, 22>,
  <18, 22, 28>,
  <26, 28, 38>,
  <26, 38, 36>,
  <30, 32, 42>,
  <30, 42, 40>,
  <24, 16, 19>,
  <24, 19, 34>,
  <39, 41, 31>,
  <39, 31, 29>,
  <44, 34, 33>,
  <44, 33, 43>,
  <33, 19, 15>,
  <33, 15, 23>,
  <37, 39, 29>,
  <37, 29, 21>,
  <37, 21, 27>,
  <17, 13, 7>,
  <17, 7, 5>,
  <17, 5, 11>,
  <1, 3, 4>,
  <1, 4, 2>,
  <1, 2, 0>,
  <12, 6, 8>,
  <12, 8, 14>,
  <12, 14, 18>,
  <28, 22, 30>,
  <28, 30, 40>,
  <28, 40, 38>,
  <32, 24, 34>,
  <32, 34, 44>,
  <32, 44, 42>,
  <43, 33, 23>,
  <43, 23, 31>,
  <43, 31, 41>,
  <35, 25, 20>,
  <35, 20, 26>,
  <35, 26, 36>,
  <19, 16, 10>,
  <19, 10, 9>,
  <19, 9, 15>,
  <1, 7, 13>,
  <1, 13, 21>,
  <1, 21, 29>,
  <1, 29, 31>,
  <1, 31, 23>,
  <1, 23, 15>,
  <1, 15, 9>,
  <1, 9, 3>,
  <32, 30, 22>,
  <32, 22, 14>,
  <32, 14, 8>,
  <32, 8, 2>,
  <32, 2, 4>,
  <32, 4, 10>,
  <32, 10, 16>,
  <32, 16, 24>,
  <36, 38, 40>,
  <36, 40, 42>,
  <36, 42, 44>,
  <36, 44, 43>,
  <36, 43, 41>,
  <36, 41, 39>,
  <36, 39, 37>,
  <36, 37, 35>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[36];
 #local P1 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[38];
 #local P2 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[40];
 #local P3 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[42];
 #local P4 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[44];
 #local P5 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[43];
 #local P6 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[41];
 #local P7 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[39];
 #local P8 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[37];
 #local P9 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[35];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_83_tridiminished_rhombicosidodecahedron_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_83_tridiminished_rhombicosidodecahedron_obj }
#end
#end

#macro Johnson_83_tridiminished_rhombicosidodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[0], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[1], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[2], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[3], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[4], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[5], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[6], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[7], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[8], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[9], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[10], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[11], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[12], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[13], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[14], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[15], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[16], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[17], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[18], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[19], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[20], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[21], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[22], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[23], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[24], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[25], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[26], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[27], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[28], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[29], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[30], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[31], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[32], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[33], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[34], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[35], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[36], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[37], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[38], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[39], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[40], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[41], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[42], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[43], RadVer }
  sphere { Johnson_83_tridiminished_rhombicosidodecahedron_verts[44], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[25], Johnson_83_tridiminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[27], Johnson_83_tridiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[17], Johnson_83_tridiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[20], Johnson_83_tridiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[11], Johnson_83_tridiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[12], Johnson_83_tridiminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[5], Johnson_83_tridiminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[0], Johnson_83_tridiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[6], Johnson_83_tridiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[26], Johnson_83_tridiminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[18], Johnson_83_tridiminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[28], Johnson_83_tridiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[34], Johnson_83_tridiminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[19], Johnson_83_tridiminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[33], Johnson_83_tridiminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[35], Johnson_83_tridiminished_rhombicosidodecahedron_verts[37], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[37], Johnson_83_tridiminished_rhombicosidodecahedron_verts[27], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[25], Johnson_83_tridiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[27], Johnson_83_tridiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[21], Johnson_83_tridiminished_rhombicosidodecahedron_verts[13], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[13], Johnson_83_tridiminished_rhombicosidodecahedron_verts[17], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[17], Johnson_83_tridiminished_rhombicosidodecahedron_verts[11], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[20], Johnson_83_tridiminished_rhombicosidodecahedron_verts[25], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[11], Johnson_83_tridiminished_rhombicosidodecahedron_verts[5], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[6], Johnson_83_tridiminished_rhombicosidodecahedron_verts[12], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[0], Johnson_83_tridiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[2], Johnson_83_tridiminished_rhombicosidodecahedron_verts[8], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[8], Johnson_83_tridiminished_rhombicosidodecahedron_verts[6], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[7], Johnson_83_tridiminished_rhombicosidodecahedron_verts[1], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[1], Johnson_83_tridiminished_rhombicosidodecahedron_verts[0], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[5], Johnson_83_tridiminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[3], Johnson_83_tridiminished_rhombicosidodecahedron_verts[9], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[9], Johnson_83_tridiminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[10], Johnson_83_tridiminished_rhombicosidodecahedron_verts[4], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[4], Johnson_83_tridiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[12], Johnson_83_tridiminished_rhombicosidodecahedron_verts[18], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[26], Johnson_83_tridiminished_rhombicosidodecahedron_verts[20], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[18], Johnson_83_tridiminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[14], Johnson_83_tridiminished_rhombicosidodecahedron_verts[22], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[22], Johnson_83_tridiminished_rhombicosidodecahedron_verts[28], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[28], Johnson_83_tridiminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[38], Johnson_83_tridiminished_rhombicosidodecahedron_verts[36], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[36], Johnson_83_tridiminished_rhombicosidodecahedron_verts[26], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[30], Johnson_83_tridiminished_rhombicosidodecahedron_verts[32], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[32], Johnson_83_tridiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[42], Johnson_83_tridiminished_rhombicosidodecahedron_verts[40], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[40], Johnson_83_tridiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[24], Johnson_83_tridiminished_rhombicosidodecahedron_verts[16], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[16], Johnson_83_tridiminished_rhombicosidodecahedron_verts[19], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[34], Johnson_83_tridiminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[39], Johnson_83_tridiminished_rhombicosidodecahedron_verts[41], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[41], Johnson_83_tridiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[31], Johnson_83_tridiminished_rhombicosidodecahedron_verts[29], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[29], Johnson_83_tridiminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[44], Johnson_83_tridiminished_rhombicosidodecahedron_verts[34], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[33], Johnson_83_tridiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[43], Johnson_83_tridiminished_rhombicosidodecahedron_verts[44], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[19], Johnson_83_tridiminished_rhombicosidodecahedron_verts[15], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[15], Johnson_83_tridiminished_rhombicosidodecahedron_verts[23], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[23], Johnson_83_tridiminished_rhombicosidodecahedron_verts[33], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[37], Johnson_83_tridiminished_rhombicosidodecahedron_verts[39], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[29], Johnson_83_tridiminished_rhombicosidodecahedron_verts[21], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[13], Johnson_83_tridiminished_rhombicosidodecahedron_verts[7], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[1], Johnson_83_tridiminished_rhombicosidodecahedron_verts[3], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[4], Johnson_83_tridiminished_rhombicosidodecahedron_verts[2], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[8], Johnson_83_tridiminished_rhombicosidodecahedron_verts[14], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[22], Johnson_83_tridiminished_rhombicosidodecahedron_verts[30], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[40], Johnson_83_tridiminished_rhombicosidodecahedron_verts[38], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[32], Johnson_83_tridiminished_rhombicosidodecahedron_verts[24], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[44], Johnson_83_tridiminished_rhombicosidodecahedron_verts[42], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[23], Johnson_83_tridiminished_rhombicosidodecahedron_verts[31], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[41], Johnson_83_tridiminished_rhombicosidodecahedron_verts[43], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[36], Johnson_83_tridiminished_rhombicosidodecahedron_verts[35], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[16], Johnson_83_tridiminished_rhombicosidodecahedron_verts[10], RadEdg }
  cylinder { Johnson_83_tridiminished_rhombicosidodecahedron_verts[9], Johnson_83_tridiminished_rhombicosidodecahedron_verts[15], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[36];
 #local P1 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[38];
 #local P2 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[40];
 #local P3 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[42];
 #local P4 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[44];
 #local P5 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[43];
 #local P6 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[41];
 #local P7 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[39];
 #local P8 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[37];
 #local P9 = Johnson_83_tridiminished_rhombicosidodecahedron_verts[35];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
