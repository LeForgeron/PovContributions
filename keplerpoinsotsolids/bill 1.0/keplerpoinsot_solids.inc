/* -------------------
keplerpoinsot_solids.inc

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  KeplerPoinsot_small_stellated_dodecahedron (12 'genuine' vertices, 24 actual vertices)
  KeplerPoinsot_great_dodecahedron (12 vertices)
  KeplerPoinsot_great_stellated_dodecahedron (20 'genuine' vertices, 32 actual vertices)
  KeplerPoinsot_great_icosahedron (12 vertices)

-------------------- */

#include "transforms.inc"

#declare KeplerPoinsot_small_stellated_dodecahedron_verts = array[24]
{
<0, 0, 1.902113>,
<1.701302, 0, -0.8506508>,
<0.5257311, 1.618034, -0.8506508>,
<-1.376382, 1., -0.8506508>,
<-1.376382, -1., -0.8506508>,
<0.5257311, -1.618034, -0.8506508>,
<-0.5257311, 1.618034, 0.8506508>,
<-0.5257311, -1.618034, 0.8506508>,
<-1.701302, 0, 0.8506508>,
<1.376382, -1., 0.8506508>,
<1.376382, 1., 0.8506508>,
<0, 0, -1.902113>,
<0.6155367, 0.4472136, 0.3804226>,
<-0.2351141, 0.7236068, 0.3804226>,
<-0.7608452, 0, 0.3804226>,
<-0.2351141, -0.7236068, 0.3804226>,
<0.6155367, -0.4472136, 0.3804226>,
<0.2351141, -0.7236068, -0.3804226>,
<0, 0, -0.8506508>,
<0.2351141, 0.7236068, -0.3804226>,
<0.7608452, 0, -0.3804226>,
<-0.6155367, 0.4472136, -0.3804226>,
<-0.6155367, -0.4472136, -0.3804226>,
<0, 0, 0.8506508>
}
#local P0 = KeplerPoinsot_small_stellated_dodecahedron_verts[23];
#local P1 = KeplerPoinsot_small_stellated_dodecahedron_verts[9];
#local P2 = KeplerPoinsot_small_stellated_dodecahedron_verts[6];
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
 #declare KeplerPoinsot_small_stellated_dodecahedron_verts[Num] = vtransform(KeplerPoinsot_small_stellated_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro KeplerPoinsot_small_stellated_dodecahedron_faces(Tex3, OnPlane)
#local KeplerPoinsot_small_stellated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  24,
  KeplerPoinsot_small_stellated_dodecahedron_verts[0],
  KeplerPoinsot_small_stellated_dodecahedron_verts[1],
  KeplerPoinsot_small_stellated_dodecahedron_verts[2],
  KeplerPoinsot_small_stellated_dodecahedron_verts[3],
  KeplerPoinsot_small_stellated_dodecahedron_verts[4],
  KeplerPoinsot_small_stellated_dodecahedron_verts[5],
  KeplerPoinsot_small_stellated_dodecahedron_verts[6],
  KeplerPoinsot_small_stellated_dodecahedron_verts[7],
  KeplerPoinsot_small_stellated_dodecahedron_verts[8],
  KeplerPoinsot_small_stellated_dodecahedron_verts[9],
  KeplerPoinsot_small_stellated_dodecahedron_verts[10],
  KeplerPoinsot_small_stellated_dodecahedron_verts[11],
  KeplerPoinsot_small_stellated_dodecahedron_verts[12],
  KeplerPoinsot_small_stellated_dodecahedron_verts[13],
  KeplerPoinsot_small_stellated_dodecahedron_verts[14],
  KeplerPoinsot_small_stellated_dodecahedron_verts[15],
  KeplerPoinsot_small_stellated_dodecahedron_verts[16],
  KeplerPoinsot_small_stellated_dodecahedron_verts[17],
  KeplerPoinsot_small_stellated_dodecahedron_verts[18],
  KeplerPoinsot_small_stellated_dodecahedron_verts[19],
  KeplerPoinsot_small_stellated_dodecahedron_verts[20],
  KeplerPoinsot_small_stellated_dodecahedron_verts[21],
  KeplerPoinsot_small_stellated_dodecahedron_verts[22],
  KeplerPoinsot_small_stellated_dodecahedron_verts[23]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  60,
  <12, 0, 1>, 0,
  <12, 1, 6>, 0,
  <12, 6, 9>, 0,
  <12, 9, 2>, 0,
  <12, 2, 0>, 0,
  <13, 0, 2>, 0,
  <13, 2, 8>, 0,
  <13, 8, 10>, 0,
  <13, 10, 3>, 0,
  <13, 3, 0>, 0,
  <14, 0, 3>, 0,
  <14, 3, 7>, 0,
  <14, 7, 6>, 0,
  <14, 6, 4>, 0,
  <14, 4, 0>, 0,
  <15, 0, 4>, 0,
  <15, 4, 9>, 0,
  <15, 9, 8>, 0,
  <15, 8, 5>, 0,
  <15, 5, 0>, 0,
  <16, 0, 5>, 0,
  <16, 5, 10>, 0,
  <16, 10, 7>, 0,
  <16, 7, 1>, 0,
  <16, 1, 0>, 0,
  <17, 1, 7>, 0,
  <17, 7, 11>, 0,
  <17, 11, 9>, 0,
  <17, 9, 4>, 0,
  <17, 4, 1>, 0,
  <18, 1, 4>, 0,
  <18, 4, 2>, 0,
  <18, 2, 5>, 0,
  <18, 5, 3>, 0,
  <18, 3, 1>, 0,
  <19, 1, 3>, 0,
  <19, 3, 10>, 0,
  <19, 10, 11>, 0,
  <19, 11, 6>, 0,
  <19, 6, 1>, 0,
  <20, 2, 9>, 0,
  <20, 9, 11>, 0,
  <20, 11, 10>, 0,
  <20, 10, 5>, 0,
  <20, 5, 2>, 0,
  <21, 2, 4>, 0,
  <21, 4, 6>, 0,
  <21, 6, 11>, 0,
  <21, 11, 8>, 0,
  <21, 8, 2>, 0,
  <22, 3, 5>, 0,
  <22, 5, 8>, 0,
  <22, 8, 11>, 0,
  <22, 11, 7>, 0,
  <22, 7, 3>, 0,
  <23, 6, 7>, 0,
  <23, 7, 10>, 0,
  <23, 10, 8>, 0,
  <23, 8, 9>, 0,
  <23, 9, 6>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = KeplerPoinsot_small_stellated_dodecahedron_verts[2];
 #local P1 = KeplerPoinsot_small_stellated_dodecahedron_verts[1];
 #local P2 = KeplerPoinsot_small_stellated_dodecahedron_verts[11];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_small_stellated_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_small_stellated_dodecahedron_obj }
#end
#end

#macro KeplerPoinsot_small_stellated_dodecahedron_faces2(OnPlane)
#local KeplerPoinsot_small_stellated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  24,
  KeplerPoinsot_small_stellated_dodecahedron_verts[0],
  KeplerPoinsot_small_stellated_dodecahedron_verts[1],
  KeplerPoinsot_small_stellated_dodecahedron_verts[2],
  KeplerPoinsot_small_stellated_dodecahedron_verts[3],
  KeplerPoinsot_small_stellated_dodecahedron_verts[4],
  KeplerPoinsot_small_stellated_dodecahedron_verts[5],
  KeplerPoinsot_small_stellated_dodecahedron_verts[6],
  KeplerPoinsot_small_stellated_dodecahedron_verts[7],
  KeplerPoinsot_small_stellated_dodecahedron_verts[8],
  KeplerPoinsot_small_stellated_dodecahedron_verts[9],
  KeplerPoinsot_small_stellated_dodecahedron_verts[10],
  KeplerPoinsot_small_stellated_dodecahedron_verts[11],
  KeplerPoinsot_small_stellated_dodecahedron_verts[12],
  KeplerPoinsot_small_stellated_dodecahedron_verts[13],
  KeplerPoinsot_small_stellated_dodecahedron_verts[14],
  KeplerPoinsot_small_stellated_dodecahedron_verts[15],
  KeplerPoinsot_small_stellated_dodecahedron_verts[16],
  KeplerPoinsot_small_stellated_dodecahedron_verts[17],
  KeplerPoinsot_small_stellated_dodecahedron_verts[18],
  KeplerPoinsot_small_stellated_dodecahedron_verts[19],
  KeplerPoinsot_small_stellated_dodecahedron_verts[20],
  KeplerPoinsot_small_stellated_dodecahedron_verts[21],
  KeplerPoinsot_small_stellated_dodecahedron_verts[22],
  KeplerPoinsot_small_stellated_dodecahedron_verts[23]
 }
 face_indices {
  60,
  <12, 0, 1>,
  <12, 1, 6>,
  <12, 6, 9>,
  <12, 9, 2>,
  <12, 2, 0>,
  <13, 0, 2>,
  <13, 2, 8>,
  <13, 8, 10>,
  <13, 10, 3>,
  <13, 3, 0>,
  <14, 0, 3>,
  <14, 3, 7>,
  <14, 7, 6>,
  <14, 6, 4>,
  <14, 4, 0>,
  <15, 0, 4>,
  <15, 4, 9>,
  <15, 9, 8>,
  <15, 8, 5>,
  <15, 5, 0>,
  <16, 0, 5>,
  <16, 5, 10>,
  <16, 10, 7>,
  <16, 7, 1>,
  <16, 1, 0>,
  <17, 1, 7>,
  <17, 7, 11>,
  <17, 11, 9>,
  <17, 9, 4>,
  <17, 4, 1>,
  <18, 1, 4>,
  <18, 4, 2>,
  <18, 2, 5>,
  <18, 5, 3>,
  <18, 3, 1>,
  <19, 1, 3>,
  <19, 3, 10>,
  <19, 10, 11>,
  <19, 11, 6>,
  <19, 6, 1>,
  <20, 2, 9>,
  <20, 9, 11>,
  <20, 11, 10>,
  <20, 10, 5>,
  <20, 5, 2>,
  <21, 2, 4>,
  <21, 4, 6>,
  <21, 6, 11>,
  <21, 11, 8>,
  <21, 8, 2>,
  <22, 3, 5>,
  <22, 5, 8>,
  <22, 8, 11>,
  <22, 11, 7>,
  <22, 7, 3>,
  <23, 6, 7>,
  <23, 7, 10>,
  <23, 10, 8>,
  <23, 8, 9>,
  <23, 9, 6>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = KeplerPoinsot_small_stellated_dodecahedron_verts[2];
 #local P1 = KeplerPoinsot_small_stellated_dodecahedron_verts[1];
 #local P2 = KeplerPoinsot_small_stellated_dodecahedron_verts[11];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_small_stellated_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_small_stellated_dodecahedron_obj }
#end
#end

#macro KeplerPoinsot_small_stellated_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[0], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[1], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[2], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[3], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[4], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[5], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[6], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[7], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[8], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[9], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[10], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[11], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[12], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[13], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[14], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[15], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[16], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[17], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[18], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[19], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[20], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[21], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[22], RadVer }
  sphere { KeplerPoinsot_small_stellated_dodecahedron_verts[23], RadVer }
  texture { TexVer } }
 union {
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[0], KeplerPoinsot_small_stellated_dodecahedron_verts[1], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[0], KeplerPoinsot_small_stellated_dodecahedron_verts[2], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[0], KeplerPoinsot_small_stellated_dodecahedron_verts[3], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[0], KeplerPoinsot_small_stellated_dodecahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[0], KeplerPoinsot_small_stellated_dodecahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[1], KeplerPoinsot_small_stellated_dodecahedron_verts[3], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[1], KeplerPoinsot_small_stellated_dodecahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[1], KeplerPoinsot_small_stellated_dodecahedron_verts[6], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[1], KeplerPoinsot_small_stellated_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[2], KeplerPoinsot_small_stellated_dodecahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[2], KeplerPoinsot_small_stellated_dodecahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[2], KeplerPoinsot_small_stellated_dodecahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[2], KeplerPoinsot_small_stellated_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[3], KeplerPoinsot_small_stellated_dodecahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[3], KeplerPoinsot_small_stellated_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[3], KeplerPoinsot_small_stellated_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[4], KeplerPoinsot_small_stellated_dodecahedron_verts[6], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[4], KeplerPoinsot_small_stellated_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[5], KeplerPoinsot_small_stellated_dodecahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[5], KeplerPoinsot_small_stellated_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[6], KeplerPoinsot_small_stellated_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[6], KeplerPoinsot_small_stellated_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[6], KeplerPoinsot_small_stellated_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[7], KeplerPoinsot_small_stellated_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[7], KeplerPoinsot_small_stellated_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[8], KeplerPoinsot_small_stellated_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[8], KeplerPoinsot_small_stellated_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[8], KeplerPoinsot_small_stellated_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[9], KeplerPoinsot_small_stellated_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_small_stellated_dodecahedron_verts[10], KeplerPoinsot_small_stellated_dodecahedron_verts[11], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = KeplerPoinsot_small_stellated_dodecahedron_verts[2];
 #local P1 = KeplerPoinsot_small_stellated_dodecahedron_verts[1];
 #local P2 = KeplerPoinsot_small_stellated_dodecahedron_verts[11];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare KeplerPoinsot_great_dodecahedron_verts = array[12]
{
<0, 0, 1.175571>,
<1.051462, 0, 0.5257311>,
<-0.8506508, 0.618034, 0.5257311>,
<0.3249197, -1., 0.5257311>,
<0.3249197, 1., 0.5257311>,
<-0.8506508, -0.618034, 0.5257311>,
<0.8506508, 0.618034, -0.5257311>,
<0.8506508, -0.618034, -0.5257311>,
<-1.051462, 0, -0.5257311>,
<-0.3249197, 1., -0.5257311>,
<-0.3249197, -1., -0.5257311>,
<0, 0, -1.175571>,
}
#local P0 = KeplerPoinsot_great_dodecahedron_verts[6];
#local P1 = KeplerPoinsot_great_dodecahedron_verts[7];
#local P2 = KeplerPoinsot_great_dodecahedron_verts[10];
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
 #declare KeplerPoinsot_great_dodecahedron_verts[Num] = vtransform(KeplerPoinsot_great_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro KeplerPoinsot_great_dodecahedron_faces(Tex5, OnPlane)
#local KeplerPoinsot_great_dodecahedron_obj = mesh2 {
 vertex_vectors {
  12,
  KeplerPoinsot_great_dodecahedron_verts[0],
  KeplerPoinsot_great_dodecahedron_verts[1],
  KeplerPoinsot_great_dodecahedron_verts[2],
  KeplerPoinsot_great_dodecahedron_verts[3],
  KeplerPoinsot_great_dodecahedron_verts[4],
  KeplerPoinsot_great_dodecahedron_verts[5],
  KeplerPoinsot_great_dodecahedron_verts[6],
  KeplerPoinsot_great_dodecahedron_verts[7],
  KeplerPoinsot_great_dodecahedron_verts[8],
  KeplerPoinsot_great_dodecahedron_verts[9],
  KeplerPoinsot_great_dodecahedron_verts[10],
  KeplerPoinsot_great_dodecahedron_verts[11]
 }
 texture_list {
  1,
  texture { Tex5 }
 }
 face_indices {
  36,
  <0, 1, 6>, 0,
  <0, 6, 9>, 0,
  <0, 9, 2>, 0,
  <0, 2, 8>, 0,
  <0, 8, 10>, 0,
  <0, 10, 3>, 0,
  <0, 3, 7>, 0,
  <0, 7, 6>, 0,
  <0, 6, 4>, 0,
  <0, 4, 9>, 0,
  <0, 9, 8>, 0,
  <0, 8, 5>, 0,
  <0, 5, 10>, 0,
  <0, 10, 7>, 0,
  <0, 7, 1>, 0,
  <1, 7, 11>, 0,
  <1, 11, 9>, 0,
  <1, 9, 4>, 0,
  <1, 4, 2>, 0,
  <1, 2, 5>, 0,
  <1, 5, 3>, 0,
  <1, 3, 10>, 0,
  <1, 10, 11>, 0,
  <1, 11, 6>, 0,
  <2, 9, 11>, 0,
  <2, 11, 10>, 0,
  <2, 10, 5>, 0,
  <2, 4, 6>, 0,
  <2, 6, 11>, 0,
  <2, 11, 8>, 0,
  <3, 5, 8>, 0,
  <3, 8, 11>, 0,
  <3, 11, 7>, 0,
  <6, 7, 10>, 0,
  <6, 10, 8>, 0,
  <6, 8, 9>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = KeplerPoinsot_great_dodecahedron_verts[1];
 #local P1 = KeplerPoinsot_great_dodecahedron_verts[0];
 #local P2 = KeplerPoinsot_great_dodecahedron_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_great_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_great_dodecahedron_obj }
#end
#end

#macro KeplerPoinsot_great_dodecahedron_faces2(OnPlane)
#local KeplerPoinsot_great_dodecahedron_obj = mesh2 {
 vertex_vectors {
  12,
  KeplerPoinsot_great_dodecahedron_verts[0],
  KeplerPoinsot_great_dodecahedron_verts[1],
  KeplerPoinsot_great_dodecahedron_verts[2],
  KeplerPoinsot_great_dodecahedron_verts[3],
  KeplerPoinsot_great_dodecahedron_verts[4],
  KeplerPoinsot_great_dodecahedron_verts[5],
  KeplerPoinsot_great_dodecahedron_verts[6],
  KeplerPoinsot_great_dodecahedron_verts[7],
  KeplerPoinsot_great_dodecahedron_verts[8],
  KeplerPoinsot_great_dodecahedron_verts[9],
  KeplerPoinsot_great_dodecahedron_verts[10],
  KeplerPoinsot_great_dodecahedron_verts[11]
 }
 face_indices {
  36,
  <0, 1, 6>,
  <0, 6, 9>,
  <0, 9, 2>,
  <0, 2, 8>,
  <0, 8, 10>,
  <0, 10, 3>,
  <0, 3, 7>,
  <0, 7, 6>,
  <0, 6, 4>,
  <0, 4, 9>,
  <0, 9, 8>,
  <0, 8, 5>,
  <0, 5, 10>,
  <0, 10, 7>,
  <0, 7, 1>,
  <1, 7, 11>,
  <1, 11, 9>,
  <1, 9, 4>,
  <1, 4, 2>,
  <1, 2, 5>,
  <1, 5, 3>,
  <1, 3, 10>,
  <1, 10, 11>,
  <1, 11, 6>,
  <2, 9, 11>,
  <2, 11, 10>,
  <2, 10, 5>,
  <2, 4, 6>,
  <2, 6, 11>,
  <2, 11, 8>,
  <3, 5, 8>,
  <3, 8, 11>,
  <3, 11, 7>,
  <6, 7, 10>,
  <6, 10, 8>,
  <6, 8, 9>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = KeplerPoinsot_great_dodecahedron_verts[1];
 #local P1 = KeplerPoinsot_great_dodecahedron_verts[0];
 #local P2 = KeplerPoinsot_great_dodecahedron_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_great_dodecahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_great_dodecahedron_obj }
#end
#end

#macro KeplerPoinsot_great_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { KeplerPoinsot_great_dodecahedron_verts[0], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[1], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[2], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[3], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[4], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[5], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[6], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[7], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[8], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[9], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[10], RadVer }
  sphere { KeplerPoinsot_great_dodecahedron_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { KeplerPoinsot_great_dodecahedron_verts[0], KeplerPoinsot_great_dodecahedron_verts[1], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[0], KeplerPoinsot_great_dodecahedron_verts[2], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[0], KeplerPoinsot_great_dodecahedron_verts[3], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[0], KeplerPoinsot_great_dodecahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[0], KeplerPoinsot_great_dodecahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[1], KeplerPoinsot_great_dodecahedron_verts[3], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[1], KeplerPoinsot_great_dodecahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[1], KeplerPoinsot_great_dodecahedron_verts[6], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[1], KeplerPoinsot_great_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[2], KeplerPoinsot_great_dodecahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[2], KeplerPoinsot_great_dodecahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[2], KeplerPoinsot_great_dodecahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[2], KeplerPoinsot_great_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[3], KeplerPoinsot_great_dodecahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[3], KeplerPoinsot_great_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[3], KeplerPoinsot_great_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[4], KeplerPoinsot_great_dodecahedron_verts[6], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[4], KeplerPoinsot_great_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[5], KeplerPoinsot_great_dodecahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[5], KeplerPoinsot_great_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[6], KeplerPoinsot_great_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[6], KeplerPoinsot_great_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[6], KeplerPoinsot_great_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[7], KeplerPoinsot_great_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[7], KeplerPoinsot_great_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[8], KeplerPoinsot_great_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[8], KeplerPoinsot_great_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[8], KeplerPoinsot_great_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[9], KeplerPoinsot_great_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_dodecahedron_verts[10], KeplerPoinsot_great_dodecahedron_verts[11], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = KeplerPoinsot_great_dodecahedron_verts[1];
 #local P1 = KeplerPoinsot_great_dodecahedron_verts[0];
 #local P2 = KeplerPoinsot_great_dodecahedron_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare KeplerPoinsot_great_stellated_dodecahedron_verts = array[32]
{
<0, 0, 2.802517>,
<1.868345, 0, -2.088873>,
<-0.9341724, 1.618034, -2.088873>,
<-0.9341724, -1.618034, -2.088873>,
<-2.088873, 1.618034, 0.9341724>,
<-2.088873, -1.618034, 0.9341724>,
<-0.3568221, -2.618034, 0.9341724>,
<2.445695, -1., 0.9341724>,
<2.445695, 1., 0.9341724>,
<-0.3568221, 2.618034, 0.9341724>,
<0.3568221, -2.618034, -0.9341724>,
<0.3568221, 2.618034, -0.9341724>,
<2.088873, 1.618034, -0.9341724>,
<-2.445695, -1., -0.9341724>,
<-2.445695, 1., -0.9341724>,
<2.088873, -1.618034, -0.9341724>,
<0.9341724, 1.618034, 2.088873>,
<0.9341724, -1.618034, 2.088873>,
<-1.868345, 0, 2.088873>,
<0, 0, -2.802517>,
<0.2581989, 0.4472136, 0.0986232>,
<-0.5163978, 0, 0.0986232>,
<0.2581989, -0.4472136, 0.0986232>,
<-0.3191514, 0, -0.4177746>
<0.1595757, -0.2763932, -0.4177746>,
<0.1595757, 0.2763932, -0.4177746>,
<-0.1595757, -0.2763932, 0.4177746>,
<-0.1595757, 0.2763932, 0.4177746>,
<0.3191514, 0, 0.4177746>,
<0.5163978, 0, -0.0986232>,
<-0.2581989, 0.4472136, -0.0986232>,
<-0.2581989, -0.4472136, -0.0986232>,
}
#local P0 = KeplerPoinsot_great_stellated_dodecahedron_verts[31];
#local P1 = KeplerPoinsot_great_stellated_dodecahedron_verts[17];
#local P2 = KeplerPoinsot_great_stellated_dodecahedron_verts[14];
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
 #declare KeplerPoinsot_great_stellated_dodecahedron_verts[Num] = vtransform(KeplerPoinsot_great_stellated_dodecahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro KeplerPoinsot_great_stellated_dodecahedron_faces(Tex3, OnPlane)
#local KeplerPoinsot_great_stellated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  32,
  KeplerPoinsot_great_stellated_dodecahedron_verts[0],
  KeplerPoinsot_great_stellated_dodecahedron_verts[1],
  KeplerPoinsot_great_stellated_dodecahedron_verts[2],
  KeplerPoinsot_great_stellated_dodecahedron_verts[3],
  KeplerPoinsot_great_stellated_dodecahedron_verts[4],
  KeplerPoinsot_great_stellated_dodecahedron_verts[5],
  KeplerPoinsot_great_stellated_dodecahedron_verts[6],
  KeplerPoinsot_great_stellated_dodecahedron_verts[7],
  KeplerPoinsot_great_stellated_dodecahedron_verts[8],
  KeplerPoinsot_great_stellated_dodecahedron_verts[9],
  KeplerPoinsot_great_stellated_dodecahedron_verts[10],
  KeplerPoinsot_great_stellated_dodecahedron_verts[11],
  KeplerPoinsot_great_stellated_dodecahedron_verts[12],
  KeplerPoinsot_great_stellated_dodecahedron_verts[13],
  KeplerPoinsot_great_stellated_dodecahedron_verts[14],
  KeplerPoinsot_great_stellated_dodecahedron_verts[15],
  KeplerPoinsot_great_stellated_dodecahedron_verts[16],
  KeplerPoinsot_great_stellated_dodecahedron_verts[17],
  KeplerPoinsot_great_stellated_dodecahedron_verts[18],
  KeplerPoinsot_great_stellated_dodecahedron_verts[19],
  KeplerPoinsot_great_stellated_dodecahedron_verts[20],
  KeplerPoinsot_great_stellated_dodecahedron_verts[21],
  KeplerPoinsot_great_stellated_dodecahedron_verts[22],
  KeplerPoinsot_great_stellated_dodecahedron_verts[23],
  KeplerPoinsot_great_stellated_dodecahedron_verts[24],
  KeplerPoinsot_great_stellated_dodecahedron_verts[25],
  KeplerPoinsot_great_stellated_dodecahedron_verts[26],
  KeplerPoinsot_great_stellated_dodecahedron_verts[27],
  KeplerPoinsot_great_stellated_dodecahedron_verts[28],
  KeplerPoinsot_great_stellated_dodecahedron_verts[29],
  KeplerPoinsot_great_stellated_dodecahedron_verts[30],
  KeplerPoinsot_great_stellated_dodecahedron_verts[31]
 }
 texture_list {
  1,
  texture { Tex3 }
 }
 face_indices {
  60,
  <20, 0, 1>, 0,
  <20, 1, 4>, 0,
  <20, 4, 7>, 0,
  <20, 7, 2>, 0,
  <20, 2, 0>, 0,
  <21, 0, 2>, 0,
  <21, 2, 6>, 0,
  <21, 6, 9>, 0,
  <21, 9, 3>, 0,
  <21, 3, 0>, 0,
  <22, 0, 3>, 0,
  <22, 3, 8>, 0,
  <22, 8, 5>, 0,
  <22, 5, 1>, 0,
  <22, 1, 0>, 0,
  <23, 1, 5>, 0,
  <23, 5, 11>, 0,
  <23, 11, 10>, 0,
  <23, 10, 4>, 0,
  <23, 4, 1>, 0,
  <24, 2, 7>, 0,
  <24, 7, 13>, 0,
  <24, 13, 12>, 0,
  <24, 12, 6>, 0,
  <24, 6, 2>, 0,
  <25, 3, 9>, 0,
  <25, 9, 15>, 0,
  <25, 15, 14>, 0,
  <25, 14, 8>, 0,
  <25, 8, 3>, 0,
  <26, 4, 10>, 0,
  <26, 10, 16>, 0,
  <26, 16, 13>, 0,
  <26, 13, 7>, 0,
  <26, 7, 4>, 0,
  <27, 5, 8>, 0,
  <27, 8, 14>, 0,
  <27, 14, 17>, 0,
  <27, 17, 11>, 0,
  <27, 11, 5>, 0,
  <28, 6, 12>, 0,
  <28, 12, 18>, 0,
  <28, 18, 15>, 0,
  <28, 15, 9>, 0,
  <28, 9, 6>, 0,
  <29, 10, 11>, 0,
  <29, 11, 17>, 0,
  <29, 17, 19>, 0,
  <29, 19, 16>, 0,
  <29, 16, 10>, 0,
  <30, 12, 13>, 0,
  <30, 13, 16>, 0,
  <30, 16, 19>, 0,
  <30, 19, 18>, 0,
  <30, 18, 12>, 0,
  <31, 14, 15>, 0,
  <31, 15, 18>, 0,
  <31, 18, 19>, 0,
  <31, 19, 17>, 0,
  <31, 17, 14>, 0
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = KeplerPoinsot_great_stellated_dodecahedron_verts[9];
 #local P1 = KeplerPoinsot_great_stellated_dodecahedron_verts[8];
 #local P2 = KeplerPoinsot_great_stellated_dodecahedron_verts[11];
 #local P3 = KeplerPoinsot_great_stellated_dodecahedron_verts[12];
 #local P4 = KeplerPoinsot_great_stellated_dodecahedron_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_great_stellated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_great_stellated_dodecahedron_obj }
#end
#end

#macro KeplerPoinsot_great_stellated_dodecahedron_faces2(OnPlane)
#local KeplerPoinsot_great_stellated_dodecahedron_obj = mesh2 {
 vertex_vectors {
  32,
  KeplerPoinsot_great_stellated_dodecahedron_verts[0],
  KeplerPoinsot_great_stellated_dodecahedron_verts[1],
  KeplerPoinsot_great_stellated_dodecahedron_verts[2],
  KeplerPoinsot_great_stellated_dodecahedron_verts[3],
  KeplerPoinsot_great_stellated_dodecahedron_verts[4],
  KeplerPoinsot_great_stellated_dodecahedron_verts[5],
  KeplerPoinsot_great_stellated_dodecahedron_verts[6],
  KeplerPoinsot_great_stellated_dodecahedron_verts[7],
  KeplerPoinsot_great_stellated_dodecahedron_verts[8],
  KeplerPoinsot_great_stellated_dodecahedron_verts[9],
  KeplerPoinsot_great_stellated_dodecahedron_verts[10],
  KeplerPoinsot_great_stellated_dodecahedron_verts[11],
  KeplerPoinsot_great_stellated_dodecahedron_verts[12],
  KeplerPoinsot_great_stellated_dodecahedron_verts[13],
  KeplerPoinsot_great_stellated_dodecahedron_verts[14],
  KeplerPoinsot_great_stellated_dodecahedron_verts[15],
  KeplerPoinsot_great_stellated_dodecahedron_verts[16],
  KeplerPoinsot_great_stellated_dodecahedron_verts[17],
  KeplerPoinsot_great_stellated_dodecahedron_verts[18],
  KeplerPoinsot_great_stellated_dodecahedron_verts[19],
  KeplerPoinsot_great_stellated_dodecahedron_verts[20],
  KeplerPoinsot_great_stellated_dodecahedron_verts[21],
  KeplerPoinsot_great_stellated_dodecahedron_verts[22],
  KeplerPoinsot_great_stellated_dodecahedron_verts[23],
  KeplerPoinsot_great_stellated_dodecahedron_verts[24],
  KeplerPoinsot_great_stellated_dodecahedron_verts[25],
  KeplerPoinsot_great_stellated_dodecahedron_verts[26],
  KeplerPoinsot_great_stellated_dodecahedron_verts[27],
  KeplerPoinsot_great_stellated_dodecahedron_verts[28],
  KeplerPoinsot_great_stellated_dodecahedron_verts[29],
  KeplerPoinsot_great_stellated_dodecahedron_verts[30],
  KeplerPoinsot_great_stellated_dodecahedron_verts[31]
 }
 face_indices {
  60,
  <20, 0, 1>,
  <20, 1, 4>,
  <20, 4, 7>,
  <20, 7, 2>,
  <20, 2, 0>,
  <21, 0, 2>,
  <21, 2, 6>,
  <21, 6, 9>,
  <21, 9, 3>,
  <21, 3, 0>,
  <22, 0, 3>,
  <22, 3, 8>,
  <22, 8, 5>,
  <22, 5, 1>,
  <22, 1, 0>,
  <23, 1, 5>,
  <23, 5, 11>,
  <23, 11, 10>,
  <23, 10, 4>,
  <23, 4, 1>,
  <24, 2, 7>,
  <24, 7, 13>,
  <24, 13, 12>,
  <24, 12, 6>,
  <24, 6, 2>,
  <25, 3, 9>,
  <25, 9, 15>,
  <25, 15, 14>,
  <25, 14, 8>,
  <25, 8, 3>,
  <26, 4, 10>,
  <26, 10, 16>,
  <26, 16, 13>,
  <26, 13, 7>,
  <26, 7, 4>,
  <27, 5, 8>,
  <27, 8, 14>,
  <27, 14, 17>,
  <27, 17, 11>,
  <27, 11, 5>,
  <28, 6, 12>,
  <28, 12, 18>,
  <28, 18, 15>,
  <28, 15, 9>,
  <28, 9, 6>,
  <29, 10, 11>,
  <29, 11, 17>,
  <29, 17, 19>,
  <29, 19, 16>,
  <29, 16, 10>,
  <30, 12, 13>,
  <30, 13, 16>,
  <30, 16, 19>,
  <30, 19, 18>,
  <30, 18, 12>,
  <31, 14, 15>,
  <31, 15, 18>,
  <31, 18, 19>,
  <31, 19, 17>,
  <31, 17, 14>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = KeplerPoinsot_great_stellated_dodecahedron_verts[9];
 #local P1 = KeplerPoinsot_great_stellated_dodecahedron_verts[8];
 #local P2 = KeplerPoinsot_great_stellated_dodecahedron_verts[11];
 #local P3 = KeplerPoinsot_great_stellated_dodecahedron_verts[12];
 #local P4 = KeplerPoinsot_great_stellated_dodecahedron_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_great_stellated_dodecahedron_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_great_stellated_dodecahedron_obj }
#end
#end

#macro KeplerPoinsot_great_stellated_dodecahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[0], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[1], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[2], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[3], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[4], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[5], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[6], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[7], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[8], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[9], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[10], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[11], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[12], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[13], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[14], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[15], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[16], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[17], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[18], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[19], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[20], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[21], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[22], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[23], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[24], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[25], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[26], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[27], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[28], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[29], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[30], RadVer }
  sphere { KeplerPoinsot_great_stellated_dodecahedron_verts[31], RadVer }
  texture { TexVer } }
 union {
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[0], KeplerPoinsot_great_stellated_dodecahedron_verts[1], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[0], KeplerPoinsot_great_stellated_dodecahedron_verts[2], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[0], KeplerPoinsot_great_stellated_dodecahedron_verts[3], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[1], KeplerPoinsot_great_stellated_dodecahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[1], KeplerPoinsot_great_stellated_dodecahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[2], KeplerPoinsot_great_stellated_dodecahedron_verts[6], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[2], KeplerPoinsot_great_stellated_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[3], KeplerPoinsot_great_stellated_dodecahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[3], KeplerPoinsot_great_stellated_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[4], KeplerPoinsot_great_stellated_dodecahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[4], KeplerPoinsot_great_stellated_dodecahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[5], KeplerPoinsot_great_stellated_dodecahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[5], KeplerPoinsot_great_stellated_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[6], KeplerPoinsot_great_stellated_dodecahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[6], KeplerPoinsot_great_stellated_dodecahedron_verts[12], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[7], KeplerPoinsot_great_stellated_dodecahedron_verts[13], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[8], KeplerPoinsot_great_stellated_dodecahedron_verts[14], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[9], KeplerPoinsot_great_stellated_dodecahedron_verts[15], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[10], KeplerPoinsot_great_stellated_dodecahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[10], KeplerPoinsot_great_stellated_dodecahedron_verts[16], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[11], KeplerPoinsot_great_stellated_dodecahedron_verts[17], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[12], KeplerPoinsot_great_stellated_dodecahedron_verts[13], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[12], KeplerPoinsot_great_stellated_dodecahedron_verts[18], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[13], KeplerPoinsot_great_stellated_dodecahedron_verts[16], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[14], KeplerPoinsot_great_stellated_dodecahedron_verts[15], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[14], KeplerPoinsot_great_stellated_dodecahedron_verts[17], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[15], KeplerPoinsot_great_stellated_dodecahedron_verts[18], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[16], KeplerPoinsot_great_stellated_dodecahedron_verts[19], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[17], KeplerPoinsot_great_stellated_dodecahedron_verts[19], RadEdg }
  cylinder { KeplerPoinsot_great_stellated_dodecahedron_verts[18], KeplerPoinsot_great_stellated_dodecahedron_verts[19], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = KeplerPoinsot_great_stellated_dodecahedron_verts[9];
 #local P1 = KeplerPoinsot_great_stellated_dodecahedron_verts[8];
 #local P2 = KeplerPoinsot_great_stellated_dodecahedron_verts[11];
 #local P3 = KeplerPoinsot_great_stellated_dodecahedron_verts[12];
 #local P4 = KeplerPoinsot_great_stellated_dodecahedron_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare KeplerPoinsot_great_icosahedron_verts = array[12]
{
<0, 0, 1.902113>,
<1.701302, 0, -0.8506508>,
<-1.376382, 1., -0.8506508>,
<0.5257311, -1.618034, -0.8506508>,
<0.5257311, 1.618034, -0.8506508>,
<-1.376382, -1., -0.8506508>,
<-0.5257311, -1.618034, 0.8506508>,
<-0.5257311, 1.618034, 0.8506508>,
<1.376382, 1., 0.8506508>,
<-1.701302, 0, 0.8506508>,
<1.376382, -1., 0.8506508>,
<0, 0, -1.902113>,
}
#local P0 = KeplerPoinsot_great_icosahedron_verts[9];
#local P1 = KeplerPoinsot_great_icosahedron_verts[11];
#local P2 = KeplerPoinsot_great_icosahedron_verts[10];
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
 #declare KeplerPoinsot_great_icosahedron_verts[Num] = vtransform(KeplerPoinsot_great_icosahedron_verts[Num], The_Tran);
 #local Num = Num + 1;
#end

#macro KeplerPoinsot_great_icosahedron_faces(Tex3, OnPlane)
#local KeplerPoinsot_great_icosahedron_obj = mesh2 {
 vertex_vectors {
  12,
  KeplerPoinsot_great_icosahedron_verts[0],
  KeplerPoinsot_great_icosahedron_verts[1],
  KeplerPoinsot_great_icosahedron_verts[2],
  KeplerPoinsot_great_icosahedron_verts[3],
  KeplerPoinsot_great_icosahedron_verts[4],
  KeplerPoinsot_great_icosahedron_verts[5],
  KeplerPoinsot_great_icosahedron_verts[6],
  KeplerPoinsot_great_icosahedron_verts[7],
  KeplerPoinsot_great_icosahedron_verts[8],
  KeplerPoinsot_great_icosahedron_verts[9],
  KeplerPoinsot_great_icosahedron_verts[10],
  KeplerPoinsot_great_icosahedron_verts[11]
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
 #local P0 = KeplerPoinsot_great_icosahedron_verts[4];
 #local P1 = KeplerPoinsot_great_icosahedron_verts[7];
 #local P2 = KeplerPoinsot_great_icosahedron_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_great_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_great_icosahedron_obj }
#end
#end

#macro KeplerPoinsot_great_icosahedron_faces2(OnPlane)
#local KeplerPoinsot_great_icosahedron_obj = mesh2 {
 vertex_vectors {
  12,
  KeplerPoinsot_great_icosahedron_verts[0],
  KeplerPoinsot_great_icosahedron_verts[1],
  KeplerPoinsot_great_icosahedron_verts[2],
  KeplerPoinsot_great_icosahedron_verts[3],
  KeplerPoinsot_great_icosahedron_verts[4],
  KeplerPoinsot_great_icosahedron_verts[5],
  KeplerPoinsot_great_icosahedron_verts[6],
  KeplerPoinsot_great_icosahedron_verts[7],
  KeplerPoinsot_great_icosahedron_verts[8],
  KeplerPoinsot_great_icosahedron_verts[9],
  KeplerPoinsot_great_icosahedron_verts[10],
  KeplerPoinsot_great_icosahedron_verts[11]
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
 #local P0 = KeplerPoinsot_great_icosahedron_verts[4];
 #local P1 = KeplerPoinsot_great_icosahedron_verts[7];
 #local P2 = KeplerPoinsot_great_icosahedron_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  KeplerPoinsot_great_icosahedron_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { KeplerPoinsot_great_icosahedron_obj }
#end
#end

#macro KeplerPoinsot_great_icosahedron_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { KeplerPoinsot_great_icosahedron_verts[0], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[1], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[2], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[3], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[4], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[5], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[6], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[7], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[8], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[9], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[10], RadVer }
  sphere { KeplerPoinsot_great_icosahedron_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { KeplerPoinsot_great_icosahedron_verts[0], KeplerPoinsot_great_icosahedron_verts[1], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[0], KeplerPoinsot_great_icosahedron_verts[2], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[0], KeplerPoinsot_great_icosahedron_verts[3], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[0], KeplerPoinsot_great_icosahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[0], KeplerPoinsot_great_icosahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[1], KeplerPoinsot_great_icosahedron_verts[2], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[1], KeplerPoinsot_great_icosahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[1], KeplerPoinsot_great_icosahedron_verts[6], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[1], KeplerPoinsot_great_icosahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[2], KeplerPoinsot_great_icosahedron_verts[3], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[2], KeplerPoinsot_great_icosahedron_verts[6], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[2], KeplerPoinsot_great_icosahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[3], KeplerPoinsot_great_icosahedron_verts[4], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[3], KeplerPoinsot_great_icosahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[3], KeplerPoinsot_great_icosahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[4], KeplerPoinsot_great_icosahedron_verts[5], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[4], KeplerPoinsot_great_icosahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[4], KeplerPoinsot_great_icosahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[5], KeplerPoinsot_great_icosahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[5], KeplerPoinsot_great_icosahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[6], KeplerPoinsot_great_icosahedron_verts[7], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[6], KeplerPoinsot_great_icosahedron_verts[8], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[6], KeplerPoinsot_great_icosahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[7], KeplerPoinsot_great_icosahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[7], KeplerPoinsot_great_icosahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[8], KeplerPoinsot_great_icosahedron_verts[9], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[8], KeplerPoinsot_great_icosahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[9], KeplerPoinsot_great_icosahedron_verts[10], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[9], KeplerPoinsot_great_icosahedron_verts[11], RadEdg }
  cylinder { KeplerPoinsot_great_icosahedron_verts[10], KeplerPoinsot_great_icosahedron_verts[11], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = KeplerPoinsot_great_icosahedron_verts[4];
 #local P1 = KeplerPoinsot_great_icosahedron_verts[7];
 #local P2 = KeplerPoinsot_great_icosahedron_verts[8];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
