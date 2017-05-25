/* -------------------
johnson_solids_group3.inc

Modified cupolas and rotundae

Original vertex and face index data by George W. Hart:
http://www.georgehart.com/virtual-polyhedra/vp.html

Skeleton edges and POV-Ray conversion by Bill Pragnell, 2009
This file is licensed under the terms of the CC-LGPL

This file defines the following polyhedra:

  Johnson_18_elongated_triangular_cupola (15 vertices)
  Johnson_19_elongated_square_cupola (20 vertices)
  Johnson_20_elongated_pentagonal_cupola (25 vertices)
  Johnson_21_elongated_pentagonal_rotunda (30 vertices)
  Johnson_22_gyroelongated_triangular_cupola (15 vertices)
  Johnson_23_gyroelongated_square_cupola (20 vertices)
  Johnson_24_gyroelongated_pentagonal_cupola (25 vertices)
  Johnson_25_gyroelongated_pentagonal_rotunda (30 vertices)
  Johnson_26_gyrobifastigium (8 vertices)
  Johnson_27_triangular_orthobicupola (12 vertices)
  Johnson_28_square_orthobicupola (16 vertices)
  Johnson_29_square_gyrobicupola (16 vertices)
  Johnson_30_pentagonal_orthobicupola (20 vertices)
  Johnson_31_pentagonal_gyrobicupola (20 vertices)
  Johnson_32_pentagonal_orthocupolarotunda (25 vertices)
  Johnson_33_pentagonal_gyrocupolarotunda (25 vertices)
  Johnson_34_pentagonal_orthobirotunda (30 vertices)
  Johnson_35_elongated_triangular_orthobicupola (18 vertices)
  Johnson_36_elongated_triangular_gyrobicupola (18 vertices)
  Johnson_37_elongated_square_gyrobicupola (24 vertices)
  Johnson_38_elongated_pentagonal_orthobicupola (30 vertices)
  Johnson_39_elongated_pentagonal_gyrobicupola (30 vertices)
  Johnson_40_elongated_pentagonal_orthocupolarotunda (35 vertices)
  Johnson_41_elongated_pentagonal_gyrocupolarotunda (35 vertices)
  Johnson_42_elongated_pentagonal_orthobirotunda (40 vertices)
  Johnson_43_elongated_pentagonal_gyrobirotunda (40 vertices)
  Johnson_44_gyroelongated_triangular_bicupola (18 vertices) (chiral)
  Johnson_45_gyroelongated_square_bicupola (24 vertices) (chiral)
  Johnson_46_gyroelongated_pentagonal_bicupola (30 vertices) (chiral)
  Johnson_47_gyroelongated_pentagonal_cupolarotunda (35 vertices) (chiral)
  Johnson_48_gyroelongated_pentagonal_birotunda (40 vertices) (chiral)

-------------------- */

#include "transforms.inc"

#declare Johnson_18_elongated_triangular_cupola_verts = array[15]
{
<-0.836652, 0.050764, 0.288421>,
<-0.686658, 0.016522, -0.560338>,
<-0.587106, -0.771319, 0.365687>,
<-0.571616, 0.871513, 0.302147>,
<-0.437112, -0.805561, -0.483073>,
<-0.421621, 0.837272, -0.546612>,
<-0.212729, -0.160030, 0.845510>,
<0.052308, 0.660719, 0.859236>,
<0.087260, -0.228514, -0.852008>,
<0.186811, -1.016355, 0.074016>,
<0.352296, 0.592236, -0.838282>,
<0.561189, -0.405066, 0.553840>,
<0.711183, -0.439308, -0.294919>,
<0.826226, 0.415684, 0.567566>,
<0.976220, 0.381442, -0.281193>,
}
#declare P0 = Johnson_18_elongated_triangular_cupola_verts[14];
#declare P1 = Johnson_18_elongated_triangular_cupola_verts[10];
#declare P2 = Johnson_18_elongated_triangular_cupola_verts[5];
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
 #declare Johnson_18_elongated_triangular_cupola_verts[Num] = vtransform(Johnson_18_elongated_triangular_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_18_elongated_triangular_cupola_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_18_elongated_triangular_cupola_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_18_elongated_triangular_cupola_verts[0],
  Johnson_18_elongated_triangular_cupola_verts[1],
  Johnson_18_elongated_triangular_cupola_verts[2],
  Johnson_18_elongated_triangular_cupola_verts[3],
  Johnson_18_elongated_triangular_cupola_verts[4],
  Johnson_18_elongated_triangular_cupola_verts[5],
  Johnson_18_elongated_triangular_cupola_verts[6],
  Johnson_18_elongated_triangular_cupola_verts[7],
  Johnson_18_elongated_triangular_cupola_verts[8],
  Johnson_18_elongated_triangular_cupola_verts[9],
  Johnson_18_elongated_triangular_cupola_verts[10],
  Johnson_18_elongated_triangular_cupola_verts[11],
  Johnson_18_elongated_triangular_cupola_verts[12],
  Johnson_18_elongated_triangular_cupola_verts[13],
  Johnson_18_elongated_triangular_cupola_verts[14]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  26,
  <4, 9, 2>, 0,
  <9, 12, 11>, 0,
  <2, 6, 0>, 0,
  <4, 1, 8>, 0,
  <0, 3, 5>, 1,
  <0, 5, 1>, 1,
  <1, 5, 10>, 1,
  <1, 10, 8>, 1,
  <8, 10, 14>, 1,
  <8, 14, 12>, 1,
  <12, 14, 13>, 1,
  <12, 13, 11>, 1,
  <11, 13, 7>, 1,
  <11, 7, 6>, 1,
  <6, 7, 3>, 1,
  <6, 3, 0>, 1,
  <9, 4, 8>, 1,
  <9, 8, 12>, 1,
  <2, 9, 11>, 1,
  <2, 11, 6>, 1,
  <4, 2, 0>, 1,
  <4, 0, 1>, 1,
  <14, 10, 5>, 2,
  <14, 5, 3>, 2,
  <14, 3, 7>, 2,
  <14, 7, 13>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_18_elongated_triangular_cupola_verts[14];
 #local P1 = Johnson_18_elongated_triangular_cupola_verts[10];
 #local P2 = Johnson_18_elongated_triangular_cupola_verts[5];
 #local P3 = Johnson_18_elongated_triangular_cupola_verts[3];
 #local P4 = Johnson_18_elongated_triangular_cupola_verts[7];
 #local P5 = Johnson_18_elongated_triangular_cupola_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_18_elongated_triangular_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_18_elongated_triangular_cupola_obj }
#end
#end

#macro Johnson_18_elongated_triangular_cupola_faces2(OnPlane)
#local Johnson_18_elongated_triangular_cupola_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_18_elongated_triangular_cupola_verts[0],
  Johnson_18_elongated_triangular_cupola_verts[1],
  Johnson_18_elongated_triangular_cupola_verts[2],
  Johnson_18_elongated_triangular_cupola_verts[3],
  Johnson_18_elongated_triangular_cupola_verts[4],
  Johnson_18_elongated_triangular_cupola_verts[5],
  Johnson_18_elongated_triangular_cupola_verts[6],
  Johnson_18_elongated_triangular_cupola_verts[7],
  Johnson_18_elongated_triangular_cupola_verts[8],
  Johnson_18_elongated_triangular_cupola_verts[9],
  Johnson_18_elongated_triangular_cupola_verts[10],
  Johnson_18_elongated_triangular_cupola_verts[11],
  Johnson_18_elongated_triangular_cupola_verts[12],
  Johnson_18_elongated_triangular_cupola_verts[13],
  Johnson_18_elongated_triangular_cupola_verts[14]
 }
 face_indices {
  26,
  <4, 9, 2>,
  <9, 12, 11>,
  <2, 6, 0>,
  <4, 1, 8>,
  <0, 3, 5>,
  <0, 5, 1>,
  <1, 5, 10>,
  <1, 10, 8>,
  <8, 10, 14>,
  <8, 14, 12>,
  <12, 14, 13>,
  <12, 13, 11>,
  <11, 13, 7>,
  <11, 7, 6>,
  <6, 7, 3>,
  <6, 3, 0>,
  <9, 4, 8>,
  <9, 8, 12>,
  <2, 9, 11>,
  <2, 11, 6>,
  <4, 2, 0>,
  <4, 0, 1>,
  <14, 10, 5>,
  <14, 5, 3>,
  <14, 3, 7>,
  <14, 7, 13>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_18_elongated_triangular_cupola_verts[14];
 #local P1 = Johnson_18_elongated_triangular_cupola_verts[10];
 #local P2 = Johnson_18_elongated_triangular_cupola_verts[5];
 #local P3 = Johnson_18_elongated_triangular_cupola_verts[3];
 #local P4 = Johnson_18_elongated_triangular_cupola_verts[7];
 #local P5 = Johnson_18_elongated_triangular_cupola_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_18_elongated_triangular_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_18_elongated_triangular_cupola_obj }
#end
#end

#macro Johnson_18_elongated_triangular_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_18_elongated_triangular_cupola_verts[0], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[1], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[2], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[3], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[4], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[5], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[6], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[7], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[8], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[9], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[10], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[11], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[12], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[13], RadVer }
  sphere { Johnson_18_elongated_triangular_cupola_verts[14], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_18_elongated_triangular_cupola_verts[4], Johnson_18_elongated_triangular_cupola_verts[9], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[9], Johnson_18_elongated_triangular_cupola_verts[2], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[2], Johnson_18_elongated_triangular_cupola_verts[4], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[9], Johnson_18_elongated_triangular_cupola_verts[12], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[12], Johnson_18_elongated_triangular_cupola_verts[11], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[11], Johnson_18_elongated_triangular_cupola_verts[9], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[2], Johnson_18_elongated_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[6], Johnson_18_elongated_triangular_cupola_verts[0], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[0], Johnson_18_elongated_triangular_cupola_verts[2], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[4], Johnson_18_elongated_triangular_cupola_verts[1], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[1], Johnson_18_elongated_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[8], Johnson_18_elongated_triangular_cupola_verts[4], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[0], Johnson_18_elongated_triangular_cupola_verts[3], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[3], Johnson_18_elongated_triangular_cupola_verts[5], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[5], Johnson_18_elongated_triangular_cupola_verts[1], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[1], Johnson_18_elongated_triangular_cupola_verts[0], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[5], Johnson_18_elongated_triangular_cupola_verts[10], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[10], Johnson_18_elongated_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[10], Johnson_18_elongated_triangular_cupola_verts[14], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[14], Johnson_18_elongated_triangular_cupola_verts[12], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[12], Johnson_18_elongated_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[14], Johnson_18_elongated_triangular_cupola_verts[13], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[13], Johnson_18_elongated_triangular_cupola_verts[11], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[13], Johnson_18_elongated_triangular_cupola_verts[7], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[7], Johnson_18_elongated_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[6], Johnson_18_elongated_triangular_cupola_verts[11], RadEdg }
  cylinder { Johnson_18_elongated_triangular_cupola_verts[7], Johnson_18_elongated_triangular_cupola_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_18_elongated_triangular_cupola_verts[14];
 #local P1 = Johnson_18_elongated_triangular_cupola_verts[10];
 #local P2 = Johnson_18_elongated_triangular_cupola_verts[5];
 #local P3 = Johnson_18_elongated_triangular_cupola_verts[3];
 #local P4 = Johnson_18_elongated_triangular_cupola_verts[7];
 #local P5 = Johnson_18_elongated_triangular_cupola_verts[13];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_19_elongated_square_cupola_verts = array[20]
{
<-0.889715, 0.115789, -0.359510>,
<-0.792371, -0.231368, 0.270291>,
<-0.791598, 0.494102, 0.251959>,
<-0.522446, -0.406626, -0.704240>,
<-0.521352, 0.619343, -0.730164>,
<-0.425102, -0.753782, -0.074439>,
<-0.423235, 0.997655, -0.118694>,
<-0.286344, -0.218767, 0.790309>,
<-0.285570, 0.506702, 0.771978>,
<-0.154083, 0.096928, -1.074893>,
<0.080926, -0.741182, 0.445580>,
<0.082793, 1.010256, 0.401324>,
<0.095069, -0.767118, -0.580291>,
<0.331944, 0.146209, 0.895926>,
<0.463432, -0.263565, -0.950945>,
<0.601096, -0.754518, -0.060273>,
<0.699213, -0.376205, 0.551197>,
<0.700307, 0.649763, 0.525272>,
<0.969459, -0.250964, -0.430927>,
<1.067576, 0.127349, 0.180543>,
}
#declare P0 = Johnson_19_elongated_square_cupola_verts[18];
#declare P1 = Johnson_19_elongated_square_cupola_verts[14];
#declare P2 = Johnson_19_elongated_square_cupola_verts[9];
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
 #declare Johnson_19_elongated_square_cupola_verts[Num] = vtransform(Johnson_19_elongated_square_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_19_elongated_square_cupola_faces(Tex3, Tex4, Tex8, OnPlane)
#local Johnson_19_elongated_square_cupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_19_elongated_square_cupola_verts[0],
  Johnson_19_elongated_square_cupola_verts[1],
  Johnson_19_elongated_square_cupola_verts[2],
  Johnson_19_elongated_square_cupola_verts[3],
  Johnson_19_elongated_square_cupola_verts[4],
  Johnson_19_elongated_square_cupola_verts[5],
  Johnson_19_elongated_square_cupola_verts[6],
  Johnson_19_elongated_square_cupola_verts[7],
  Johnson_19_elongated_square_cupola_verts[8],
  Johnson_19_elongated_square_cupola_verts[9],
  Johnson_19_elongated_square_cupola_verts[10],
  Johnson_19_elongated_square_cupola_verts[11],
  Johnson_19_elongated_square_cupola_verts[12],
  Johnson_19_elongated_square_cupola_verts[13],
  Johnson_19_elongated_square_cupola_verts[14],
  Johnson_19_elongated_square_cupola_verts[15],
  Johnson_19_elongated_square_cupola_verts[16],
  Johnson_19_elongated_square_cupola_verts[17],
  Johnson_19_elongated_square_cupola_verts[18],
  Johnson_19_elongated_square_cupola_verts[19]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex8 }
 }
 face_indices {
  36,
  <10, 15, 16>, 0,
  <7, 13, 8>, 0,
  <1, 2, 0>, 0,
  <5, 3, 12>, 0,
  <2, 6, 4>, 1,
  <2, 4, 0>, 1,
  <0, 4, 9>, 1,
  <0, 9, 3>, 1,
  <3, 9, 14>, 1,
  <3, 14, 12>, 1,
  <12, 14, 18>, 1,
  <12, 18, 15>, 1,
  <15, 18, 19>, 1,
  <15, 19, 16>, 1,
  <16, 19, 17>, 1,
  <16, 17, 13>, 1,
  <13, 17, 11>, 1,
  <13, 11, 8>, 1,
  <8, 11, 6>, 1,
  <8, 6, 2>, 1,
  <5, 10, 7>, 1,
  <5, 7, 1>, 1,
  <10, 5, 12>, 1,
  <10, 12, 15>, 1,
  <7, 10, 16>, 1,
  <7, 16, 13>, 1,
  <1, 7, 8>, 1,
  <1, 8, 2>, 1,
  <5, 1, 0>, 1,
  <5, 0, 3>, 1,
  <18, 14, 9>, 2,
  <18, 9, 4>, 2,
  <18, 4, 6>, 2,
  <18, 6, 11>, 2,
  <18, 11, 17>, 2,
  <18, 17, 19>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_19_elongated_square_cupola_verts[18];
 #local P1 = Johnson_19_elongated_square_cupola_verts[14];
 #local P2 = Johnson_19_elongated_square_cupola_verts[9];
 #local P3 = Johnson_19_elongated_square_cupola_verts[4];
 #local P4 = Johnson_19_elongated_square_cupola_verts[6];
 #local P5 = Johnson_19_elongated_square_cupola_verts[11];
 #local P6 = Johnson_19_elongated_square_cupola_verts[17];
 #local P7 = Johnson_19_elongated_square_cupola_verts[19];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_19_elongated_square_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_19_elongated_square_cupola_obj }
#end
#end

#macro Johnson_19_elongated_square_cupola_faces2(OnPlane)
#local Johnson_19_elongated_square_cupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_19_elongated_square_cupola_verts[0],
  Johnson_19_elongated_square_cupola_verts[1],
  Johnson_19_elongated_square_cupola_verts[2],
  Johnson_19_elongated_square_cupola_verts[3],
  Johnson_19_elongated_square_cupola_verts[4],
  Johnson_19_elongated_square_cupola_verts[5],
  Johnson_19_elongated_square_cupola_verts[6],
  Johnson_19_elongated_square_cupola_verts[7],
  Johnson_19_elongated_square_cupola_verts[8],
  Johnson_19_elongated_square_cupola_verts[9],
  Johnson_19_elongated_square_cupola_verts[10],
  Johnson_19_elongated_square_cupola_verts[11],
  Johnson_19_elongated_square_cupola_verts[12],
  Johnson_19_elongated_square_cupola_verts[13],
  Johnson_19_elongated_square_cupola_verts[14],
  Johnson_19_elongated_square_cupola_verts[15],
  Johnson_19_elongated_square_cupola_verts[16],
  Johnson_19_elongated_square_cupola_verts[17],
  Johnson_19_elongated_square_cupola_verts[18],
  Johnson_19_elongated_square_cupola_verts[19]
 }
 face_indices {
  36,
  <10, 15, 16>,
  <7, 13, 8>,
  <1, 2, 0>,
  <5, 3, 12>,
  <2, 6, 4>,
  <2, 4, 0>,
  <0, 4, 9>,
  <0, 9, 3>,
  <3, 9, 14>,
  <3, 14, 12>,
  <12, 14, 18>,
  <12, 18, 15>,
  <15, 18, 19>,
  <15, 19, 16>,
  <16, 19, 17>,
  <16, 17, 13>,
  <13, 17, 11>,
  <13, 11, 8>,
  <8, 11, 6>,
  <8, 6, 2>,
  <5, 10, 7>,
  <5, 7, 1>,
  <10, 5, 12>,
  <10, 12, 15>,
  <7, 10, 16>,
  <7, 16, 13>,
  <1, 7, 8>,
  <1, 8, 2>,
  <5, 1, 0>,
  <5, 0, 3>,
  <18, 14, 9>,
  <18, 9, 4>,
  <18, 4, 6>,
  <18, 6, 11>,
  <18, 11, 17>,
  <18, 17, 19>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_19_elongated_square_cupola_verts[18];
 #local P1 = Johnson_19_elongated_square_cupola_verts[14];
 #local P2 = Johnson_19_elongated_square_cupola_verts[9];
 #local P3 = Johnson_19_elongated_square_cupola_verts[4];
 #local P4 = Johnson_19_elongated_square_cupola_verts[6];
 #local P5 = Johnson_19_elongated_square_cupola_verts[11];
 #local P6 = Johnson_19_elongated_square_cupola_verts[17];
 #local P7 = Johnson_19_elongated_square_cupola_verts[19];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_19_elongated_square_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_19_elongated_square_cupola_obj }
#end
#end

#macro Johnson_19_elongated_square_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_19_elongated_square_cupola_verts[0], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[1], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[2], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[3], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[4], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[5], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[6], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[7], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[8], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[9], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[10], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[11], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[12], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[13], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[14], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[15], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[16], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[17], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[18], RadVer }
  sphere { Johnson_19_elongated_square_cupola_verts[19], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_19_elongated_square_cupola_verts[10], Johnson_19_elongated_square_cupola_verts[15], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[15], Johnson_19_elongated_square_cupola_verts[16], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[16], Johnson_19_elongated_square_cupola_verts[10], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[7], Johnson_19_elongated_square_cupola_verts[13], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[13], Johnson_19_elongated_square_cupola_verts[8], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[8], Johnson_19_elongated_square_cupola_verts[7], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[1], Johnson_19_elongated_square_cupola_verts[2], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[2], Johnson_19_elongated_square_cupola_verts[0], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[0], Johnson_19_elongated_square_cupola_verts[1], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[5], Johnson_19_elongated_square_cupola_verts[3], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[3], Johnson_19_elongated_square_cupola_verts[12], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[12], Johnson_19_elongated_square_cupola_verts[5], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[2], Johnson_19_elongated_square_cupola_verts[6], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[6], Johnson_19_elongated_square_cupola_verts[4], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[4], Johnson_19_elongated_square_cupola_verts[0], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[4], Johnson_19_elongated_square_cupola_verts[9], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[9], Johnson_19_elongated_square_cupola_verts[3], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[3], Johnson_19_elongated_square_cupola_verts[0], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[9], Johnson_19_elongated_square_cupola_verts[14], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[14], Johnson_19_elongated_square_cupola_verts[12], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[14], Johnson_19_elongated_square_cupola_verts[18], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[18], Johnson_19_elongated_square_cupola_verts[15], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[15], Johnson_19_elongated_square_cupola_verts[12], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[18], Johnson_19_elongated_square_cupola_verts[19], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[19], Johnson_19_elongated_square_cupola_verts[16], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[19], Johnson_19_elongated_square_cupola_verts[17], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[17], Johnson_19_elongated_square_cupola_verts[13], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[13], Johnson_19_elongated_square_cupola_verts[16], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[17], Johnson_19_elongated_square_cupola_verts[11], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[11], Johnson_19_elongated_square_cupola_verts[8], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[11], Johnson_19_elongated_square_cupola_verts[6], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[2], Johnson_19_elongated_square_cupola_verts[8], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[5], Johnson_19_elongated_square_cupola_verts[10], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[10], Johnson_19_elongated_square_cupola_verts[7], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[7], Johnson_19_elongated_square_cupola_verts[1], RadEdg }
  cylinder { Johnson_19_elongated_square_cupola_verts[1], Johnson_19_elongated_square_cupola_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_19_elongated_square_cupola_verts[18];
 #local P1 = Johnson_19_elongated_square_cupola_verts[14];
 #local P2 = Johnson_19_elongated_square_cupola_verts[9];
 #local P3 = Johnson_19_elongated_square_cupola_verts[4];
 #local P4 = Johnson_19_elongated_square_cupola_verts[6];
 #local P5 = Johnson_19_elongated_square_cupola_verts[11];
 #local P6 = Johnson_19_elongated_square_cupola_verts[17];
 #local P7 = Johnson_19_elongated_square_cupola_verts[19];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_20_elongated_pentagonal_cupola_verts = array[25]
{
<-0.934650, 0.300459, -0.271185>,
<-0.838689, -0.260219, -0.516017>,
<-0.711319, 0.717591, 0.128359>,
<-0.710334, -0.156922, 0.080946>,
<-0.599799, 0.556003, -0.725148>,
<-0.503838, -0.004675, -0.969981>,
<-0.487004, 0.260210, 0.480490>,
<-0.460089, -0.750282, -0.512622>,
<-0.376468, 0.973135, -0.325605>,
<-0.331735, -0.646985, 0.084342>,
<-0.254001, 0.831847, 0.530001>,
<-0.125239, -0.494738, -0.966586>,
<0.029622, 0.027949, 0.730817>,
<0.056536, -0.982543, -0.262295>,
<0.080850, 1.087391, 0.076037>,
<0.125583, -0.532729, 0.485984>,
<0.262625, 0.599586, 0.780328>,
<0.391387, -0.726999, -0.716259>,
<0.513854, -0.868287, 0.139347>,
<0.597475, 0.855130, 0.326364>,
<0.641224, 0.109523, 0.783723>,
<0.737185, -0.451155, 0.538891>,
<0.848705, -0.612742, -0.314616>,
<0.976075, 0.365067, 0.329760>
<1.072036, -0.195610, 0.084927>,
}
#declare P0 = Johnson_20_elongated_pentagonal_cupola_verts[22];
#declare P1 = Johnson_20_elongated_pentagonal_cupola_verts[17];
#declare P2 = Johnson_20_elongated_pentagonal_cupola_verts[11];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 25)
 #declare Johnson_20_elongated_pentagonal_cupola_verts[Num] = vtransform(Johnson_20_elongated_pentagonal_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_20_elongated_pentagonal_cupola_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_20_elongated_pentagonal_cupola_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_20_elongated_pentagonal_cupola_verts[0],
  Johnson_20_elongated_pentagonal_cupola_verts[1],
  Johnson_20_elongated_pentagonal_cupola_verts[2],
  Johnson_20_elongated_pentagonal_cupola_verts[3],
  Johnson_20_elongated_pentagonal_cupola_verts[4],
  Johnson_20_elongated_pentagonal_cupola_verts[5],
  Johnson_20_elongated_pentagonal_cupola_verts[6],
  Johnson_20_elongated_pentagonal_cupola_verts[7],
  Johnson_20_elongated_pentagonal_cupola_verts[8],
  Johnson_20_elongated_pentagonal_cupola_verts[9],
  Johnson_20_elongated_pentagonal_cupola_verts[10],
  Johnson_20_elongated_pentagonal_cupola_verts[11],
  Johnson_20_elongated_pentagonal_cupola_verts[12],
  Johnson_20_elongated_pentagonal_cupola_verts[13],
  Johnson_20_elongated_pentagonal_cupola_verts[14],
  Johnson_20_elongated_pentagonal_cupola_verts[15],
  Johnson_20_elongated_pentagonal_cupola_verts[16],
  Johnson_20_elongated_pentagonal_cupola_verts[17],
  Johnson_20_elongated_pentagonal_cupola_verts[18],
  Johnson_20_elongated_pentagonal_cupola_verts[19],
  Johnson_20_elongated_pentagonal_cupola_verts[20],
  Johnson_20_elongated_pentagonal_cupola_verts[21],
  Johnson_20_elongated_pentagonal_cupola_verts[22],
  Johnson_20_elongated_pentagonal_cupola_verts[23],
  Johnson_20_elongated_pentagonal_cupola_verts[24]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  46,
  <15, 18, 21>, 0,
  <12, 20, 16>, 0,
  <6, 10, 2>, 0,
  <3, 0, 1>, 0,
  <9, 7, 13>, 0,
  <2, 8, 4>, 1,
  <2, 4, 0>, 1,
  <0, 4, 5>, 1,
  <0, 5, 1>, 1,
  <1, 5, 11>, 1,
  <1, 11, 7>, 1,
  <7, 11, 17>, 1,
  <7, 17, 13>, 1,
  <13, 17, 22>, 1,
  <13, 22, 18>, 1,
  <18, 22, 24>, 1,
  <18, 24, 21>, 1,
  <21, 24, 23>, 1,
  <21, 23, 20>, 1,
  <20, 23, 19>, 1,
  <20, 19, 16>, 1,
  <16, 19, 14>, 1,
  <16, 14, 10>, 1,
  <10, 14, 8>, 1,
  <10, 8, 2>, 1,
  <15, 9, 13>, 1,
  <15, 13, 18>, 1,
  <12, 15, 21>, 1,
  <12, 21, 20>, 1,
  <6, 12, 16>, 1,
  <6, 16, 10>, 1,
  <3, 6, 2>, 1,
  <3, 2, 0>, 1,
  <9, 3, 1>, 1,
  <9, 1, 7>, 1,
  <9, 15, 12>, 2,
  <9, 12, 6>, 2,
  <9, 6, 3>, 2,
  <22, 17, 11>, 3,
  <22, 11, 5>, 3,
  <22, 5, 4>, 3,
  <22, 4, 8>, 3,
  <22, 8, 14>, 3,
  <22, 14, 19>, 3,
  <22, 19, 23>, 3,
  <22, 23, 24>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_20_elongated_pentagonal_cupola_verts[22];
 #local P1 = Johnson_20_elongated_pentagonal_cupola_verts[17];
 #local P2 = Johnson_20_elongated_pentagonal_cupola_verts[11];
 #local P3 = Johnson_20_elongated_pentagonal_cupola_verts[5];
 #local P4 = Johnson_20_elongated_pentagonal_cupola_verts[4];
 #local P5 = Johnson_20_elongated_pentagonal_cupola_verts[8];
 #local P6 = Johnson_20_elongated_pentagonal_cupola_verts[14];
 #local P7 = Johnson_20_elongated_pentagonal_cupola_verts[19];
 #local P8 = Johnson_20_elongated_pentagonal_cupola_verts[23];
 #local P9 = Johnson_20_elongated_pentagonal_cupola_verts[24];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_20_elongated_pentagonal_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_20_elongated_pentagonal_cupola_obj }
#end
#end

#macro Johnson_20_elongated_pentagonal_cupola_faces2(OnPlane)
#local Johnson_20_elongated_pentagonal_cupola_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_20_elongated_pentagonal_cupola_verts[0],
  Johnson_20_elongated_pentagonal_cupola_verts[1],
  Johnson_20_elongated_pentagonal_cupola_verts[2],
  Johnson_20_elongated_pentagonal_cupola_verts[3],
  Johnson_20_elongated_pentagonal_cupola_verts[4],
  Johnson_20_elongated_pentagonal_cupola_verts[5],
  Johnson_20_elongated_pentagonal_cupola_verts[6],
  Johnson_20_elongated_pentagonal_cupola_verts[7],
  Johnson_20_elongated_pentagonal_cupola_verts[8],
  Johnson_20_elongated_pentagonal_cupola_verts[9],
  Johnson_20_elongated_pentagonal_cupola_verts[10],
  Johnson_20_elongated_pentagonal_cupola_verts[11],
  Johnson_20_elongated_pentagonal_cupola_verts[12],
  Johnson_20_elongated_pentagonal_cupola_verts[13],
  Johnson_20_elongated_pentagonal_cupola_verts[14],
  Johnson_20_elongated_pentagonal_cupola_verts[15],
  Johnson_20_elongated_pentagonal_cupola_verts[16],
  Johnson_20_elongated_pentagonal_cupola_verts[17],
  Johnson_20_elongated_pentagonal_cupola_verts[18],
  Johnson_20_elongated_pentagonal_cupola_verts[19],
  Johnson_20_elongated_pentagonal_cupola_verts[20],
  Johnson_20_elongated_pentagonal_cupola_verts[21],
  Johnson_20_elongated_pentagonal_cupola_verts[22],
  Johnson_20_elongated_pentagonal_cupola_verts[23],
  Johnson_20_elongated_pentagonal_cupola_verts[24]
 }
 face_indices {
  46,
  <15, 18, 21>,
  <12, 20, 16>,
  <6, 10, 2>,
  <3, 0, 1>,
  <9, 7, 13>,
  <2, 8, 4>,
  <2, 4, 0>,
  <0, 4, 5>,
  <0, 5, 1>,
  <1, 5, 11>,
  <1, 11, 7>,
  <7, 11, 17>,
  <7, 17, 13>,
  <13, 17, 22>,
  <13, 22, 18>,
  <18, 22, 24>,
  <18, 24, 21>,
  <21, 24, 23>,
  <21, 23, 20>,
  <20, 23, 19>,
  <20, 19, 16>,
  <16, 19, 14>,
  <16, 14, 10>,
  <10, 14, 8>,
  <10, 8, 2>,
  <15, 9, 13>,
  <15, 13, 18>,
  <12, 15, 21>,
  <12, 21, 20>,
  <6, 12, 16>,
  <6, 16, 10>,
  <3, 6, 2>,
  <3, 2, 0>,
  <9, 3, 1>,
  <9, 1, 7>,
  <9, 15, 12>,
  <9, 12, 6>,
  <9, 6, 3>,
  <22, 17, 11>,
  <22, 11, 5>,
  <22, 5, 4>,
  <22, 4, 8>,
  <22, 8, 14>,
  <22, 14, 19>,
  <22, 19, 23>,
  <22, 23, 24>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_20_elongated_pentagonal_cupola_verts[22];
 #local P1 = Johnson_20_elongated_pentagonal_cupola_verts[17];
 #local P2 = Johnson_20_elongated_pentagonal_cupola_verts[11];
 #local P3 = Johnson_20_elongated_pentagonal_cupola_verts[5];
 #local P4 = Johnson_20_elongated_pentagonal_cupola_verts[4];
 #local P5 = Johnson_20_elongated_pentagonal_cupola_verts[8];
 #local P6 = Johnson_20_elongated_pentagonal_cupola_verts[14];
 #local P7 = Johnson_20_elongated_pentagonal_cupola_verts[19];
 #local P8 = Johnson_20_elongated_pentagonal_cupola_verts[23];
 #local P9 = Johnson_20_elongated_pentagonal_cupola_verts[24];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_20_elongated_pentagonal_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_20_elongated_pentagonal_cupola_obj }
#end
#end

#macro Johnson_20_elongated_pentagonal_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[0], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[1], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[2], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[3], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[4], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[5], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[6], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[7], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[8], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[9], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[10], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[11], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[12], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[13], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[14], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[15], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[16], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[17], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[18], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[19], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[20], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[21], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[22], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[23], RadVer }
  sphere { Johnson_20_elongated_pentagonal_cupola_verts[24], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[15], Johnson_20_elongated_pentagonal_cupola_verts[18], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[18], Johnson_20_elongated_pentagonal_cupola_verts[21], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[21], Johnson_20_elongated_pentagonal_cupola_verts[15], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[12], Johnson_20_elongated_pentagonal_cupola_verts[20], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[20], Johnson_20_elongated_pentagonal_cupola_verts[16], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[16], Johnson_20_elongated_pentagonal_cupola_verts[12], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[6], Johnson_20_elongated_pentagonal_cupola_verts[10], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[10], Johnson_20_elongated_pentagonal_cupola_verts[2], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[2], Johnson_20_elongated_pentagonal_cupola_verts[6], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[3], Johnson_20_elongated_pentagonal_cupola_verts[0], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[0], Johnson_20_elongated_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[1], Johnson_20_elongated_pentagonal_cupola_verts[3], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[9], Johnson_20_elongated_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[7], Johnson_20_elongated_pentagonal_cupola_verts[13], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[13], Johnson_20_elongated_pentagonal_cupola_verts[9], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[2], Johnson_20_elongated_pentagonal_cupola_verts[8], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[8], Johnson_20_elongated_pentagonal_cupola_verts[4], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[4], Johnson_20_elongated_pentagonal_cupola_verts[0], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[0], Johnson_20_elongated_pentagonal_cupola_verts[2], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[4], Johnson_20_elongated_pentagonal_cupola_verts[5], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[5], Johnson_20_elongated_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[5], Johnson_20_elongated_pentagonal_cupola_verts[11], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[11], Johnson_20_elongated_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[7], Johnson_20_elongated_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[11], Johnson_20_elongated_pentagonal_cupola_verts[17], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[17], Johnson_20_elongated_pentagonal_cupola_verts[13], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[17], Johnson_20_elongated_pentagonal_cupola_verts[22], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[22], Johnson_20_elongated_pentagonal_cupola_verts[18], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[18], Johnson_20_elongated_pentagonal_cupola_verts[13], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[22], Johnson_20_elongated_pentagonal_cupola_verts[24], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[24], Johnson_20_elongated_pentagonal_cupola_verts[21], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[24], Johnson_20_elongated_pentagonal_cupola_verts[23], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[23], Johnson_20_elongated_pentagonal_cupola_verts[20], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[20], Johnson_20_elongated_pentagonal_cupola_verts[21], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[23], Johnson_20_elongated_pentagonal_cupola_verts[19], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[19], Johnson_20_elongated_pentagonal_cupola_verts[16], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[19], Johnson_20_elongated_pentagonal_cupola_verts[14], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[14], Johnson_20_elongated_pentagonal_cupola_verts[10], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[10], Johnson_20_elongated_pentagonal_cupola_verts[16], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[14], Johnson_20_elongated_pentagonal_cupola_verts[8], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[15], Johnson_20_elongated_pentagonal_cupola_verts[9], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[12], Johnson_20_elongated_pentagonal_cupola_verts[15], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[6], Johnson_20_elongated_pentagonal_cupola_verts[12], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[3], Johnson_20_elongated_pentagonal_cupola_verts[6], RadEdg }
  cylinder { Johnson_20_elongated_pentagonal_cupola_verts[9], Johnson_20_elongated_pentagonal_cupola_verts[3], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_20_elongated_pentagonal_cupola_verts[22];
 #local P1 = Johnson_20_elongated_pentagonal_cupola_verts[17];
 #local P2 = Johnson_20_elongated_pentagonal_cupola_verts[11];
 #local P3 = Johnson_20_elongated_pentagonal_cupola_verts[5];
 #local P4 = Johnson_20_elongated_pentagonal_cupola_verts[4];
 #local P5 = Johnson_20_elongated_pentagonal_cupola_verts[8];
 #local P6 = Johnson_20_elongated_pentagonal_cupola_verts[14];
 #local P7 = Johnson_20_elongated_pentagonal_cupola_verts[19];
 #local P8 = Johnson_20_elongated_pentagonal_cupola_verts[23];
 #local P9 = Johnson_20_elongated_pentagonal_cupola_verts[24];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_21_elongated_pentagonal_rotunda_verts = array[30]
{
<-0.913903, 0.139054, -0.107690>,
<-0.801323, 0.048332, 0.456301>,
<-0.780136, -0.347362, -0.398372>,
<-0.694081, 0.568652, 0.218063>,
<-0.672895, 0.172957, -0.636610>,
<-0.597978, -0.494154, 0.514184>,
<-0.584884, -0.738707, -0.014032>,
<-0.468218, -0.603725, -0.817867>,
<-0.378156, -0.064556, 0.839937>,
<-0.360976, -0.083405, -1.056105>,
<-0.317215, 0.868060, -0.109531>,
<-0.304122, 0.623508, -0.637747>,
<-0.272966, -0.995069, -0.433527>,
<-0.204636, 0.777338, 0.454460>,
<-0.161718, -0.851595, 0.369604>,
<-0.009384, 0.385994, 0.838800>,
<0.007796, 0.367145, -1.057242>,
<0.150200, -1.107957, -0.049891>,
<0.185324, 0.832194, -0.401350>,
<0.193961, -0.156492, 0.896684>,
<0.327727, -0.642909, 0.606002>,
<0.367482, 0.685403, 0.511206>,
<0.497242, 0.575832, -0.820845>,
<0.608490, 0.719306, -0.017714>
<0.639645, -0.899271, 0.186507>,
<0.696500, -0.192358, 0.604864>,
<0.803742, 0.327961, 0.366626>,
<0.920408, 0.462943, -0.437208>,
<1.008418, -0.448720, 0.185369>,
<1.115660, 0.071599, -0.052869>,
}
#declare P0 = Johnson_21_elongated_pentagonal_rotunda_verts[24];
#declare P1 = Johnson_21_elongated_pentagonal_rotunda_verts[17];
#declare P2 = Johnson_21_elongated_pentagonal_rotunda_verts[12];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 30)
 #declare Johnson_21_elongated_pentagonal_rotunda_verts[Num] = vtransform(Johnson_21_elongated_pentagonal_rotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_21_elongated_pentagonal_rotunda_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_21_elongated_pentagonal_rotunda_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_21_elongated_pentagonal_rotunda_verts[0],
  Johnson_21_elongated_pentagonal_rotunda_verts[1],
  Johnson_21_elongated_pentagonal_rotunda_verts[2],
  Johnson_21_elongated_pentagonal_rotunda_verts[3],
  Johnson_21_elongated_pentagonal_rotunda_verts[4],
  Johnson_21_elongated_pentagonal_rotunda_verts[5],
  Johnson_21_elongated_pentagonal_rotunda_verts[6],
  Johnson_21_elongated_pentagonal_rotunda_verts[7],
  Johnson_21_elongated_pentagonal_rotunda_verts[8],
  Johnson_21_elongated_pentagonal_rotunda_verts[9],
  Johnson_21_elongated_pentagonal_rotunda_verts[10],
  Johnson_21_elongated_pentagonal_rotunda_verts[11],
  Johnson_21_elongated_pentagonal_rotunda_verts[12],
  Johnson_21_elongated_pentagonal_rotunda_verts[13],
  Johnson_21_elongated_pentagonal_rotunda_verts[14],
  Johnson_21_elongated_pentagonal_rotunda_verts[15],
  Johnson_21_elongated_pentagonal_rotunda_verts[16],
  Johnson_21_elongated_pentagonal_rotunda_verts[17],
  Johnson_21_elongated_pentagonal_rotunda_verts[18],
  Johnson_21_elongated_pentagonal_rotunda_verts[19],
  Johnson_21_elongated_pentagonal_rotunda_verts[20],
  Johnson_21_elongated_pentagonal_rotunda_verts[21],
  Johnson_21_elongated_pentagonal_rotunda_verts[22],
  Johnson_21_elongated_pentagonal_rotunda_verts[23],
  Johnson_21_elongated_pentagonal_rotunda_verts[24],
  Johnson_21_elongated_pentagonal_rotunda_verts[25],
  Johnson_21_elongated_pentagonal_rotunda_verts[26],
  Johnson_21_elongated_pentagonal_rotunda_verts[27],
  Johnson_21_elongated_pentagonal_rotunda_verts[28],
  Johnson_21_elongated_pentagonal_rotunda_verts[29]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  56,
  <8, 19, 15>, 0,
  <19, 20, 25>, 0,
  <15, 21, 13>, 0,
  <21, 26, 23>, 0,
  <13, 10, 3>, 0,
  <10, 18, 11>, 0,
  <3, 0, 1>, 0,
  <0, 4, 2>, 0,
  <1, 5, 8>, 0,
  <5, 6, 14>, 0,
  <11, 16, 9>, 1,
  <11, 9, 4>, 1,
  <4, 9, 7>, 1,
  <4, 7, 2>, 1,
  <2, 7, 12>, 1,
  <2, 12, 6>, 1,
  <6, 12, 17>, 1,
  <6, 17, 14>, 1,
  <14, 17, 24>, 1,
  <14, 24, 20>, 1,
  <20, 24, 28>, 1,
  <20, 28, 25>, 1,
  <25, 28, 29>, 1,
  <25, 29, 26>, 1,
  <26, 29, 27>, 1,
  <26, 27, 23>, 1,
  <23, 27, 22>, 1,
  <23, 22, 18>, 1,
  <18, 22, 16>, 1,
  <18, 16, 11>, 1,
  <8, 15, 13>, 2,
  <8, 13, 3>, 2,
  <8, 3, 1>, 2,
  <8, 5, 14>, 2,
  <8, 14, 20>, 2,
  <8, 20, 19>, 2,
  <15, 19, 25>, 2,
  <15, 25, 26>, 2,
  <15, 26, 21>, 2,
  <13, 21, 23>, 2,
  <13, 23, 18>, 2,
  <13, 18, 10>, 2,
  <3, 10, 11>, 2,
  <3, 11, 4>, 2,
  <3, 4, 0>, 2,
  <1, 0, 2>, 2,
  <1, 2, 6>, 2,
  <1, 6, 5>, 2,
  <24, 17, 12>, 3,
  <24, 12, 7>, 3,
  <24, 7, 9>, 3,
  <24, 9, 16>, 3,
  <24, 16, 22>, 3,
  <24, 22, 27>, 3,
  <24, 27, 29>, 3,
  <24, 29, 28>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_21_elongated_pentagonal_rotunda_verts[24];
 #local P1 = Johnson_21_elongated_pentagonal_rotunda_verts[17];
 #local P2 = Johnson_21_elongated_pentagonal_rotunda_verts[12];
 #local P3 = Johnson_21_elongated_pentagonal_rotunda_verts[7];
 #local P4 = Johnson_21_elongated_pentagonal_rotunda_verts[9];
 #local P5 = Johnson_21_elongated_pentagonal_rotunda_verts[16];
 #local P6 = Johnson_21_elongated_pentagonal_rotunda_verts[22];
 #local P7 = Johnson_21_elongated_pentagonal_rotunda_verts[27];
 #local P8 = Johnson_21_elongated_pentagonal_rotunda_verts[29];
 #local P9 = Johnson_21_elongated_pentagonal_rotunda_verts[28];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_21_elongated_pentagonal_rotunda_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_21_elongated_pentagonal_rotunda_obj }
#end
#end

#macro Johnson_21_elongated_pentagonal_rotunda_faces2(OnPlane)
#local Johnson_21_elongated_pentagonal_rotunda_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_21_elongated_pentagonal_rotunda_verts[0],
  Johnson_21_elongated_pentagonal_rotunda_verts[1],
  Johnson_21_elongated_pentagonal_rotunda_verts[2],
  Johnson_21_elongated_pentagonal_rotunda_verts[3],
  Johnson_21_elongated_pentagonal_rotunda_verts[4],
  Johnson_21_elongated_pentagonal_rotunda_verts[5],
  Johnson_21_elongated_pentagonal_rotunda_verts[6],
  Johnson_21_elongated_pentagonal_rotunda_verts[7],
  Johnson_21_elongated_pentagonal_rotunda_verts[8],
  Johnson_21_elongated_pentagonal_rotunda_verts[9],
  Johnson_21_elongated_pentagonal_rotunda_verts[10],
  Johnson_21_elongated_pentagonal_rotunda_verts[11],
  Johnson_21_elongated_pentagonal_rotunda_verts[12],
  Johnson_21_elongated_pentagonal_rotunda_verts[13],
  Johnson_21_elongated_pentagonal_rotunda_verts[14],
  Johnson_21_elongated_pentagonal_rotunda_verts[15],
  Johnson_21_elongated_pentagonal_rotunda_verts[16],
  Johnson_21_elongated_pentagonal_rotunda_verts[17],
  Johnson_21_elongated_pentagonal_rotunda_verts[18],
  Johnson_21_elongated_pentagonal_rotunda_verts[19],
  Johnson_21_elongated_pentagonal_rotunda_verts[20],
  Johnson_21_elongated_pentagonal_rotunda_verts[21],
  Johnson_21_elongated_pentagonal_rotunda_verts[22],
  Johnson_21_elongated_pentagonal_rotunda_verts[23],
  Johnson_21_elongated_pentagonal_rotunda_verts[24],
  Johnson_21_elongated_pentagonal_rotunda_verts[25],
  Johnson_21_elongated_pentagonal_rotunda_verts[26],
  Johnson_21_elongated_pentagonal_rotunda_verts[27],
  Johnson_21_elongated_pentagonal_rotunda_verts[28],
  Johnson_21_elongated_pentagonal_rotunda_verts[29]
 }
 face_indices {
  56,
  <8, 19, 15>,
  <19, 20, 25>,
  <15, 21, 13>,
  <21, 26, 23>,
  <13, 10, 3>,
  <10, 18, 11>,
  <3, 0, 1>,
  <0, 4, 2>,
  <1, 5, 8>,
  <5, 6, 14>,
  <11, 16, 9>,
  <11, 9, 4>,
  <4, 9, 7>,
  <4, 7, 2>,
  <2, 7, 12>,
  <2, 12, 6>,
  <6, 12, 17>,
  <6, 17, 14>,
  <14, 17, 24>,
  <14, 24, 20>,
  <20, 24, 28>,
  <20, 28, 25>,
  <25, 28, 29>,
  <25, 29, 26>,
  <26, 29, 27>,
  <26, 27, 23>,
  <23, 27, 22>,
  <23, 22, 18>,
  <18, 22, 16>,
  <18, 16, 11>,
  <8, 15, 13>,
  <8, 13, 3>,
  <8, 3, 1>,
  <8, 5, 14>,
  <8, 14, 20>,
  <8, 20, 19>,
  <15, 19, 25>,
  <15, 25, 26>,
  <15, 26, 21>,
  <13, 21, 23>,
  <13, 23, 18>,
  <13, 18, 10>,
  <3, 10, 11>,
  <3, 11, 4>,
  <3, 4, 0>,
  <1, 0, 2>,
  <1, 2, 6>,
  <1, 6, 5>,
  <24, 17, 12>,
  <24, 12, 7>,
  <24, 7, 9>,
  <24, 9, 16>,
  <24, 16, 22>,
  <24, 22, 27>,
  <24, 27, 29>,
  <24, 29, 28>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_21_elongated_pentagonal_rotunda_verts[24];
 #local P1 = Johnson_21_elongated_pentagonal_rotunda_verts[17];
 #local P2 = Johnson_21_elongated_pentagonal_rotunda_verts[12];
 #local P3 = Johnson_21_elongated_pentagonal_rotunda_verts[7];
 #local P4 = Johnson_21_elongated_pentagonal_rotunda_verts[9];
 #local P5 = Johnson_21_elongated_pentagonal_rotunda_verts[16];
 #local P6 = Johnson_21_elongated_pentagonal_rotunda_verts[22];
 #local P7 = Johnson_21_elongated_pentagonal_rotunda_verts[27];
 #local P8 = Johnson_21_elongated_pentagonal_rotunda_verts[29];
 #local P9 = Johnson_21_elongated_pentagonal_rotunda_verts[28];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_21_elongated_pentagonal_rotunda_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_21_elongated_pentagonal_rotunda_obj }
#end
#end

#macro Johnson_21_elongated_pentagonal_rotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[0], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[1], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[2], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[3], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[4], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[5], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[6], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[7], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[8], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[9], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[10], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[11], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[12], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[13], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[14], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[15], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[16], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[17], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[18], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[19], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[20], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[21], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[22], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[23], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[24], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[25], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[26], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[27], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[28], RadVer }
  sphere { Johnson_21_elongated_pentagonal_rotunda_verts[29], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[8], Johnson_21_elongated_pentagonal_rotunda_verts[19], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[19], Johnson_21_elongated_pentagonal_rotunda_verts[15], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[15], Johnson_21_elongated_pentagonal_rotunda_verts[8], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[19], Johnson_21_elongated_pentagonal_rotunda_verts[20], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[20], Johnson_21_elongated_pentagonal_rotunda_verts[25], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[25], Johnson_21_elongated_pentagonal_rotunda_verts[19], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[15], Johnson_21_elongated_pentagonal_rotunda_verts[21], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[21], Johnson_21_elongated_pentagonal_rotunda_verts[13], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[13], Johnson_21_elongated_pentagonal_rotunda_verts[15], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[21], Johnson_21_elongated_pentagonal_rotunda_verts[26], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[26], Johnson_21_elongated_pentagonal_rotunda_verts[23], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[23], Johnson_21_elongated_pentagonal_rotunda_verts[21], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[13], Johnson_21_elongated_pentagonal_rotunda_verts[10], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[10], Johnson_21_elongated_pentagonal_rotunda_verts[3], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[3], Johnson_21_elongated_pentagonal_rotunda_verts[13], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[10], Johnson_21_elongated_pentagonal_rotunda_verts[18], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[18], Johnson_21_elongated_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[11], Johnson_21_elongated_pentagonal_rotunda_verts[10], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[3], Johnson_21_elongated_pentagonal_rotunda_verts[0], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[0], Johnson_21_elongated_pentagonal_rotunda_verts[1], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[1], Johnson_21_elongated_pentagonal_rotunda_verts[3], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[0], Johnson_21_elongated_pentagonal_rotunda_verts[4], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[4], Johnson_21_elongated_pentagonal_rotunda_verts[2], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[2], Johnson_21_elongated_pentagonal_rotunda_verts[0], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[1], Johnson_21_elongated_pentagonal_rotunda_verts[5], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[5], Johnson_21_elongated_pentagonal_rotunda_verts[8], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[8], Johnson_21_elongated_pentagonal_rotunda_verts[1], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[5], Johnson_21_elongated_pentagonal_rotunda_verts[6], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[6], Johnson_21_elongated_pentagonal_rotunda_verts[14], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[14], Johnson_21_elongated_pentagonal_rotunda_verts[5], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[11], Johnson_21_elongated_pentagonal_rotunda_verts[16], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[16], Johnson_21_elongated_pentagonal_rotunda_verts[9], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[9], Johnson_21_elongated_pentagonal_rotunda_verts[4], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[4], Johnson_21_elongated_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[9], Johnson_21_elongated_pentagonal_rotunda_verts[7], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[7], Johnson_21_elongated_pentagonal_rotunda_verts[2], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[7], Johnson_21_elongated_pentagonal_rotunda_verts[12], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[12], Johnson_21_elongated_pentagonal_rotunda_verts[6], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[6], Johnson_21_elongated_pentagonal_rotunda_verts[2], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[12], Johnson_21_elongated_pentagonal_rotunda_verts[17], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[17], Johnson_21_elongated_pentagonal_rotunda_verts[14], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[17], Johnson_21_elongated_pentagonal_rotunda_verts[24], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[24], Johnson_21_elongated_pentagonal_rotunda_verts[20], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[20], Johnson_21_elongated_pentagonal_rotunda_verts[14], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[24], Johnson_21_elongated_pentagonal_rotunda_verts[28], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[28], Johnson_21_elongated_pentagonal_rotunda_verts[25], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[28], Johnson_21_elongated_pentagonal_rotunda_verts[29], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[29], Johnson_21_elongated_pentagonal_rotunda_verts[26], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[26], Johnson_21_elongated_pentagonal_rotunda_verts[25], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[29], Johnson_21_elongated_pentagonal_rotunda_verts[27], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[27], Johnson_21_elongated_pentagonal_rotunda_verts[23], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[27], Johnson_21_elongated_pentagonal_rotunda_verts[22], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[22], Johnson_21_elongated_pentagonal_rotunda_verts[18], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[18], Johnson_21_elongated_pentagonal_rotunda_verts[23], RadEdg }
  cylinder { Johnson_21_elongated_pentagonal_rotunda_verts[22], Johnson_21_elongated_pentagonal_rotunda_verts[16], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_21_elongated_pentagonal_rotunda_verts[24];
 #local P1 = Johnson_21_elongated_pentagonal_rotunda_verts[17];
 #local P2 = Johnson_21_elongated_pentagonal_rotunda_verts[12];
 #local P3 = Johnson_21_elongated_pentagonal_rotunda_verts[7];
 #local P4 = Johnson_21_elongated_pentagonal_rotunda_verts[9];
 #local P5 = Johnson_21_elongated_pentagonal_rotunda_verts[16];
 #local P6 = Johnson_21_elongated_pentagonal_rotunda_verts[22];
 #local P7 = Johnson_21_elongated_pentagonal_rotunda_verts[27];
 #local P8 = Johnson_21_elongated_pentagonal_rotunda_verts[29];
 #local P9 = Johnson_21_elongated_pentagonal_rotunda_verts[28];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_22_gyroelongated_triangular_cupola_verts = array[15]
{
<-0.846878, 0.066004, 0.311423>,
<-0.766106, 0.678635, -0.329908>,
<-0.708152, -0.186985, -0.531132>,
<-0.648970, -0.782761, 0.128183>,
<-0.452751, 0.845109, 0.486940>,
<-0.212470, 0.406919, -0.972407>,
<-0.165405, 0.101357, 0.883692>,
<0.032503, -0.747408, 0.700451>,
<0.112048, -0.404621, -0.801418>,
<0.171230, -1.000397, -0.142104>,
<0.414240, 0.739868, 0.661290>,
<0.654521, 0.301678, -0.798058>,
<0.654794, -0.116279, 0.613406>,
<0.793521, -0.369268, -0.229149>,
<0.967876, 0.468152, 0.018791>,
}
#declare P0 = Johnson_22_gyroelongated_triangular_cupola_verts[11];
#declare P1 = Johnson_22_gyroelongated_triangular_cupola_verts[5];
#declare P2 = Johnson_22_gyroelongated_triangular_cupola_verts[1];
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
 #declare Johnson_22_gyroelongated_triangular_cupola_verts[Num] = vtransform(Johnson_22_gyroelongated_triangular_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_22_gyroelongated_triangular_cupola_faces(Tex3, Tex4, Tex6, OnPlane)
#local Johnson_22_gyroelongated_triangular_cupola_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_22_gyroelongated_triangular_cupola_verts[0],
  Johnson_22_gyroelongated_triangular_cupola_verts[1],
  Johnson_22_gyroelongated_triangular_cupola_verts[2],
  Johnson_22_gyroelongated_triangular_cupola_verts[3],
  Johnson_22_gyroelongated_triangular_cupola_verts[4],
  Johnson_22_gyroelongated_triangular_cupola_verts[5],
  Johnson_22_gyroelongated_triangular_cupola_verts[6],
  Johnson_22_gyroelongated_triangular_cupola_verts[7],
  Johnson_22_gyroelongated_triangular_cupola_verts[8],
  Johnson_22_gyroelongated_triangular_cupola_verts[9],
  Johnson_22_gyroelongated_triangular_cupola_verts[10],
  Johnson_22_gyroelongated_triangular_cupola_verts[11],
  Johnson_22_gyroelongated_triangular_cupola_verts[12],
  Johnson_22_gyroelongated_triangular_cupola_verts[13],
  Johnson_22_gyroelongated_triangular_cupola_verts[14]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex6 }
 }
 face_indices {
  26,
  <0, 1, 2>, 0,
  <2, 1, 5>, 0,
  <2, 5, 8>, 0,
  <8, 5, 11>, 0,
  <8, 11, 13>, 0,
  <13, 11, 14>, 0,
  <3, 9, 7>, 0,
  <9, 8, 13>, 0,
  <7, 12, 6>, 0,
  <3, 0, 2>, 0,
  <13, 14, 12>, 0,
  <12, 14, 10>, 0,
  <12, 10, 6>, 0,
  <6, 10, 4>, 0,
  <6, 4, 0>, 0,
  <0, 4, 1>, 0,
  <9, 3, 2>, 1,
  <9, 2, 8>, 1,
  <7, 9, 13>, 1,
  <7, 13, 12>, 1,
  <3, 7, 6>, 1,
  <3, 6, 0>, 1,
  <11, 5, 1>, 2,
  <11, 1, 4>, 2,
  <11, 4, 10>, 2,
  <11, 10, 14>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_22_gyroelongated_triangular_cupola_verts[11];
 #local P1 = Johnson_22_gyroelongated_triangular_cupola_verts[5];
 #local P2 = Johnson_22_gyroelongated_triangular_cupola_verts[1];
 #local P3 = Johnson_22_gyroelongated_triangular_cupola_verts[4];
 #local P4 = Johnson_22_gyroelongated_triangular_cupola_verts[10];
 #local P5 = Johnson_22_gyroelongated_triangular_cupola_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_22_gyroelongated_triangular_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_22_gyroelongated_triangular_cupola_obj }
#end
#end

#macro Johnson_22_gyroelongated_triangular_cupola_faces2(OnPlane)
#local Johnson_22_gyroelongated_triangular_cupola_obj = mesh2 {
 vertex_vectors {
  15,
  Johnson_22_gyroelongated_triangular_cupola_verts[0],
  Johnson_22_gyroelongated_triangular_cupola_verts[1],
  Johnson_22_gyroelongated_triangular_cupola_verts[2],
  Johnson_22_gyroelongated_triangular_cupola_verts[3],
  Johnson_22_gyroelongated_triangular_cupola_verts[4],
  Johnson_22_gyroelongated_triangular_cupola_verts[5],
  Johnson_22_gyroelongated_triangular_cupola_verts[6],
  Johnson_22_gyroelongated_triangular_cupola_verts[7],
  Johnson_22_gyroelongated_triangular_cupola_verts[8],
  Johnson_22_gyroelongated_triangular_cupola_verts[9],
  Johnson_22_gyroelongated_triangular_cupola_verts[10],
  Johnson_22_gyroelongated_triangular_cupola_verts[11],
  Johnson_22_gyroelongated_triangular_cupola_verts[12],
  Johnson_22_gyroelongated_triangular_cupola_verts[13],
  Johnson_22_gyroelongated_triangular_cupola_verts[14]
 }
 face_indices {
  26,
  <0, 1, 2>,
  <2, 1, 5>,
  <2, 5, 8>,
  <8, 5, 11>,
  <8, 11, 13>,
  <13, 11, 14>,
  <3, 9, 7>,
  <9, 8, 13>,
  <7, 12, 6>,
  <3, 0, 2>,
  <13, 14, 12>,
  <12, 14, 10>,
  <12, 10, 6>,
  <6, 10, 4>,
  <6, 4, 0>,
  <0, 4, 1>,
  <9, 3, 2>,
  <9, 2, 8>,
  <7, 9, 13>,
  <7, 13, 12>,
  <3, 7, 6>,
  <3, 6, 0>,
  <11, 5, 1>,
  <11, 1, 4>,
  <11, 4, 10>,
  <11, 10, 14>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_22_gyroelongated_triangular_cupola_verts[11];
 #local P1 = Johnson_22_gyroelongated_triangular_cupola_verts[5];
 #local P2 = Johnson_22_gyroelongated_triangular_cupola_verts[1];
 #local P3 = Johnson_22_gyroelongated_triangular_cupola_verts[4];
 #local P4 = Johnson_22_gyroelongated_triangular_cupola_verts[10];
 #local P5 = Johnson_22_gyroelongated_triangular_cupola_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_22_gyroelongated_triangular_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_22_gyroelongated_triangular_cupola_obj }
#end
#end

#macro Johnson_22_gyroelongated_triangular_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[0], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[1], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[2], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[3], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[4], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[5], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[6], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[7], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[8], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[9], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[10], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[11], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[12], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[13], RadVer }
  sphere { Johnson_22_gyroelongated_triangular_cupola_verts[14], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[0], Johnson_22_gyroelongated_triangular_cupola_verts[1], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[1], Johnson_22_gyroelongated_triangular_cupola_verts[2], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[2], Johnson_22_gyroelongated_triangular_cupola_verts[0], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[1], Johnson_22_gyroelongated_triangular_cupola_verts[5], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[5], Johnson_22_gyroelongated_triangular_cupola_verts[2], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[5], Johnson_22_gyroelongated_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[8], Johnson_22_gyroelongated_triangular_cupola_verts[2], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[5], Johnson_22_gyroelongated_triangular_cupola_verts[11], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[11], Johnson_22_gyroelongated_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[11], Johnson_22_gyroelongated_triangular_cupola_verts[13], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[13], Johnson_22_gyroelongated_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[11], Johnson_22_gyroelongated_triangular_cupola_verts[14], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[14], Johnson_22_gyroelongated_triangular_cupola_verts[13], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[3], Johnson_22_gyroelongated_triangular_cupola_verts[9], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[9], Johnson_22_gyroelongated_triangular_cupola_verts[7], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[7], Johnson_22_gyroelongated_triangular_cupola_verts[3], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[9], Johnson_22_gyroelongated_triangular_cupola_verts[8], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[13], Johnson_22_gyroelongated_triangular_cupola_verts[9], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[7], Johnson_22_gyroelongated_triangular_cupola_verts[12], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[12], Johnson_22_gyroelongated_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[6], Johnson_22_gyroelongated_triangular_cupola_verts[7], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[3], Johnson_22_gyroelongated_triangular_cupola_verts[0], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[2], Johnson_22_gyroelongated_triangular_cupola_verts[3], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[14], Johnson_22_gyroelongated_triangular_cupola_verts[12], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[12], Johnson_22_gyroelongated_triangular_cupola_verts[13], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[14], Johnson_22_gyroelongated_triangular_cupola_verts[10], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[10], Johnson_22_gyroelongated_triangular_cupola_verts[12], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[10], Johnson_22_gyroelongated_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[10], Johnson_22_gyroelongated_triangular_cupola_verts[4], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[4], Johnson_22_gyroelongated_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[4], Johnson_22_gyroelongated_triangular_cupola_verts[0], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[0], Johnson_22_gyroelongated_triangular_cupola_verts[6], RadEdg }
  cylinder { Johnson_22_gyroelongated_triangular_cupola_verts[4], Johnson_22_gyroelongated_triangular_cupola_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_22_gyroelongated_triangular_cupola_verts[11];
 #local P1 = Johnson_22_gyroelongated_triangular_cupola_verts[5];
 #local P2 = Johnson_22_gyroelongated_triangular_cupola_verts[1];
 #local P3 = Johnson_22_gyroelongated_triangular_cupola_verts[4];
 #local P4 = Johnson_22_gyroelongated_triangular_cupola_verts[10];
 #local P5 = Johnson_22_gyroelongated_triangular_cupola_verts[14];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5)/6
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_23_gyroelongated_square_cupola_verts = array[20]
{
<-0.969170, 0.321358, -0.364138>,
<-0.902194, 0.146986, 0.353054>,
<-0.885918, -0.386527, -0.161101>,
<-0.700663, 0.819184, 0.114745>,
<-0.670588, -0.166619, -0.835289>,
<-0.389781, 0.533335, 0.723761>,
<-0.377102, -0.207546, 0.737557>,
<-0.360826, -0.741059, 0.223402>,
<-0.350486, -0.754679, -0.517520>,
<-0.022354, 1.035239, 0.320838>,
<0.020179, -0.358897, -1.022714>,
<0.351157, 0.546203, 0.733864>,
<0.363836, -0.194678, 0.747660>,
<0.380112, -0.728191, 0.233505>,
<0.390452, -0.741811, -0.507416>,
<0.668412, 0.842961, 0.133414>,
<0.698487, -0.142842, -0.816621>,
<0.886588, 0.178052, 0.377446>,
<0.902865, -0.355461, -0.136709>,
<0.966994, 0.354984, -0.337737>,
}
#declare P0 = Johnson_23_gyroelongated_square_cupola_verts[10];
#declare P1 = Johnson_23_gyroelongated_square_cupola_verts[4];
#declare P2 = Johnson_23_gyroelongated_square_cupola_verts[0];
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
 #declare Johnson_23_gyroelongated_square_cupola_verts[Num] = vtransform(Johnson_23_gyroelongated_square_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_23_gyroelongated_square_cupola_faces(Tex3, Tex4, Tex8, OnPlane)
#local Johnson_23_gyroelongated_square_cupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_23_gyroelongated_square_cupola_verts[0],
  Johnson_23_gyroelongated_square_cupola_verts[1],
  Johnson_23_gyroelongated_square_cupola_verts[2],
  Johnson_23_gyroelongated_square_cupola_verts[3],
  Johnson_23_gyroelongated_square_cupola_verts[4],
  Johnson_23_gyroelongated_square_cupola_verts[5],
  Johnson_23_gyroelongated_square_cupola_verts[6],
  Johnson_23_gyroelongated_square_cupola_verts[7],
  Johnson_23_gyroelongated_square_cupola_verts[8],
  Johnson_23_gyroelongated_square_cupola_verts[9],
  Johnson_23_gyroelongated_square_cupola_verts[10],
  Johnson_23_gyroelongated_square_cupola_verts[11],
  Johnson_23_gyroelongated_square_cupola_verts[12],
  Johnson_23_gyroelongated_square_cupola_verts[13],
  Johnson_23_gyroelongated_square_cupola_verts[14],
  Johnson_23_gyroelongated_square_cupola_verts[15],
  Johnson_23_gyroelongated_square_cupola_verts[16],
  Johnson_23_gyroelongated_square_cupola_verts[17],
  Johnson_23_gyroelongated_square_cupola_verts[18],
  Johnson_23_gyroelongated_square_cupola_verts[19]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex8 }
 }
 face_indices {
  36,
  <1, 0, 2>, 0,
  <2, 0, 4>, 0,
  <2, 4, 8>, 0,
  <8, 4, 10>, 0,
  <8, 10, 14>, 0,
  <14, 10, 16>, 0,
  <14, 16, 18>, 0,
  <18, 16, 19>, 0,
  <13, 14, 18>, 0,
  <12, 17, 11>, 0,
  <6, 5, 1>, 0,
  <7, 2, 8>, 0,
  <18, 19, 17>, 0,
  <19, 15, 17>, 0,
  <17, 15, 11>, 0,
  <11, 15, 9>, 0,
  <11, 9, 5>, 0,
  <5, 9, 3>, 0,
  <5, 3, 1>, 0,
  <1, 3, 0>, 0,
  <7, 13, 12>, 1,
  <7, 12, 6>, 1,
  <13, 7, 8>, 1,
  <13, 8, 14>, 1,
  <12, 13, 18>, 1,
  <12, 18, 17>, 1,
  <6, 12, 11>, 1,
  <6, 11, 5>, 1,
  <7, 6, 1>, 1,
  <7, 1, 2>, 1,
  <10, 4, 0>, 2,
  <10, 0, 3>, 2,
  <10, 3, 9>, 2,
  <10, 9, 15>, 2,
  <10, 15, 19>, 2,
  <10, 19, 16>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_23_gyroelongated_square_cupola_verts[10];
 #local P1 = Johnson_23_gyroelongated_square_cupola_verts[4];
 #local P2 = Johnson_23_gyroelongated_square_cupola_verts[0];
 #local P3 = Johnson_23_gyroelongated_square_cupola_verts[3];
 #local P4 = Johnson_23_gyroelongated_square_cupola_verts[9];
 #local P5 = Johnson_23_gyroelongated_square_cupola_verts[15];
 #local P6 = Johnson_23_gyroelongated_square_cupola_verts[19];
 #local P7 = Johnson_23_gyroelongated_square_cupola_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_23_gyroelongated_square_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_23_gyroelongated_square_cupola_obj }
#end
#end

#macro Johnson_23_gyroelongated_square_cupola_faces2(OnPlane)
#local Johnson_23_gyroelongated_square_cupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_23_gyroelongated_square_cupola_verts[0],
  Johnson_23_gyroelongated_square_cupola_verts[1],
  Johnson_23_gyroelongated_square_cupola_verts[2],
  Johnson_23_gyroelongated_square_cupola_verts[3],
  Johnson_23_gyroelongated_square_cupola_verts[4],
  Johnson_23_gyroelongated_square_cupola_verts[5],
  Johnson_23_gyroelongated_square_cupola_verts[6],
  Johnson_23_gyroelongated_square_cupola_verts[7],
  Johnson_23_gyroelongated_square_cupola_verts[8],
  Johnson_23_gyroelongated_square_cupola_verts[9],
  Johnson_23_gyroelongated_square_cupola_verts[10],
  Johnson_23_gyroelongated_square_cupola_verts[11],
  Johnson_23_gyroelongated_square_cupola_verts[12],
  Johnson_23_gyroelongated_square_cupola_verts[13],
  Johnson_23_gyroelongated_square_cupola_verts[14],
  Johnson_23_gyroelongated_square_cupola_verts[15],
  Johnson_23_gyroelongated_square_cupola_verts[16],
  Johnson_23_gyroelongated_square_cupola_verts[17],
  Johnson_23_gyroelongated_square_cupola_verts[18],
  Johnson_23_gyroelongated_square_cupola_verts[19]
 }
 face_indices {
  36,
  <1, 0, 2>,
  <2, 0, 4>,
  <2, 4, 8>,
  <8, 4, 10>,
  <8, 10, 14>,
  <14, 10, 16>,
  <14, 16, 18>,
  <18, 16, 19>,
  <13, 14, 18>,
  <12, 17, 11>,
  <6, 5, 1>,
  <7, 2, 8>,
  <18, 19, 17>,
  <19, 15, 17>,
  <17, 15, 11>,
  <11, 15, 9>,
  <11, 9, 5>,
  <5, 9, 3>,
  <5, 3, 1>,
  <1, 3, 0>,
  <7, 13, 12>,
  <7, 12, 6>,
  <13, 7, 8>,
  <13, 8, 14>,
  <12, 13, 18>,
  <12, 18, 17>,
  <6, 12, 11>,
  <6, 11, 5>,
  <7, 6, 1>,
  <7, 1, 2>,
  <10, 4, 0>,
  <10, 0, 3>,
  <10, 3, 9>,
  <10, 9, 15>,
  <10, 15, 19>,
  <10, 19, 16>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_23_gyroelongated_square_cupola_verts[10];
 #local P1 = Johnson_23_gyroelongated_square_cupola_verts[4];
 #local P2 = Johnson_23_gyroelongated_square_cupola_verts[0];
 #local P3 = Johnson_23_gyroelongated_square_cupola_verts[3];
 #local P4 = Johnson_23_gyroelongated_square_cupola_verts[9];
 #local P5 = Johnson_23_gyroelongated_square_cupola_verts[15];
 #local P6 = Johnson_23_gyroelongated_square_cupola_verts[19];
 #local P7 = Johnson_23_gyroelongated_square_cupola_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_23_gyroelongated_square_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_23_gyroelongated_square_cupola_obj }
#end
#end

#macro Johnson_23_gyroelongated_square_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_23_gyroelongated_square_cupola_verts[0], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[1], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[2], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[3], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[4], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[5], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[6], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[7], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[8], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[9], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[10], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[11], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[12], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[13], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[14], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[15], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[16], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[17], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[18], RadVer }
  sphere { Johnson_23_gyroelongated_square_cupola_verts[19], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[1], Johnson_23_gyroelongated_square_cupola_verts[0], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[0], Johnson_23_gyroelongated_square_cupola_verts[2], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[2], Johnson_23_gyroelongated_square_cupola_verts[1], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[0], Johnson_23_gyroelongated_square_cupola_verts[4], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[4], Johnson_23_gyroelongated_square_cupola_verts[2], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[4], Johnson_23_gyroelongated_square_cupola_verts[8], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[8], Johnson_23_gyroelongated_square_cupola_verts[2], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[4], Johnson_23_gyroelongated_square_cupola_verts[10], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[10], Johnson_23_gyroelongated_square_cupola_verts[8], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[10], Johnson_23_gyroelongated_square_cupola_verts[14], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[14], Johnson_23_gyroelongated_square_cupola_verts[8], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[10], Johnson_23_gyroelongated_square_cupola_verts[16], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[16], Johnson_23_gyroelongated_square_cupola_verts[14], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[16], Johnson_23_gyroelongated_square_cupola_verts[18], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[18], Johnson_23_gyroelongated_square_cupola_verts[14], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[16], Johnson_23_gyroelongated_square_cupola_verts[19], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[19], Johnson_23_gyroelongated_square_cupola_verts[18], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[13], Johnson_23_gyroelongated_square_cupola_verts[14], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[18], Johnson_23_gyroelongated_square_cupola_verts[13], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[12], Johnson_23_gyroelongated_square_cupola_verts[17], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[17], Johnson_23_gyroelongated_square_cupola_verts[11], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[11], Johnson_23_gyroelongated_square_cupola_verts[12], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[6], Johnson_23_gyroelongated_square_cupola_verts[5], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[5], Johnson_23_gyroelongated_square_cupola_verts[1], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[1], Johnson_23_gyroelongated_square_cupola_verts[6], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[7], Johnson_23_gyroelongated_square_cupola_verts[2], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[8], Johnson_23_gyroelongated_square_cupola_verts[7], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[19], Johnson_23_gyroelongated_square_cupola_verts[17], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[17], Johnson_23_gyroelongated_square_cupola_verts[18], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[19], Johnson_23_gyroelongated_square_cupola_verts[15], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[15], Johnson_23_gyroelongated_square_cupola_verts[17], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[15], Johnson_23_gyroelongated_square_cupola_verts[11], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[15], Johnson_23_gyroelongated_square_cupola_verts[9], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[9], Johnson_23_gyroelongated_square_cupola_verts[11], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[9], Johnson_23_gyroelongated_square_cupola_verts[5], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[5], Johnson_23_gyroelongated_square_cupola_verts[11], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[9], Johnson_23_gyroelongated_square_cupola_verts[3], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[3], Johnson_23_gyroelongated_square_cupola_verts[5], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[3], Johnson_23_gyroelongated_square_cupola_verts[1], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[3], Johnson_23_gyroelongated_square_cupola_verts[0], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[7], Johnson_23_gyroelongated_square_cupola_verts[13], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[13], Johnson_23_gyroelongated_square_cupola_verts[12], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[12], Johnson_23_gyroelongated_square_cupola_verts[6], RadEdg }
  cylinder { Johnson_23_gyroelongated_square_cupola_verts[6], Johnson_23_gyroelongated_square_cupola_verts[7], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_23_gyroelongated_square_cupola_verts[10];
 #local P1 = Johnson_23_gyroelongated_square_cupola_verts[4];
 #local P2 = Johnson_23_gyroelongated_square_cupola_verts[0];
 #local P3 = Johnson_23_gyroelongated_square_cupola_verts[3];
 #local P4 = Johnson_23_gyroelongated_square_cupola_verts[9];
 #local P5 = Johnson_23_gyroelongated_square_cupola_verts[15];
 #local P6 = Johnson_23_gyroelongated_square_cupola_verts[19];
 #local P7 = Johnson_23_gyroelongated_square_cupola_verts[16];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7)/8
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_24_gyroelongated_pentagonal_cupola_verts = array[25]
{
<-1.007937, 0.263193, -0.317378>,
<-0.995648, -0.249677, 0.045090>,
<-0.928425, 0.319026, 0.303212>,
<-0.878881, -0.297121, -0.570283>,
<-0.751014, 0.784617, -0.079308>,
<-0.682946, -0.746755, -0.177844>,
<-0.534412, -0.144902, 0.458433>,
<-0.506952, 0.742130, 0.497926>,
<-0.413141, -0.682306, -0.741423>,
<-0.221709, -0.641980, 0.235499>,
<-0.206248, 1.067984, 0.052991>,
<-0.112939, 0.278202, 0.653148>,
<-0.109759, -0.982341, -0.280438>,
<0.107781, 0.858022, 0.554860>,
<0.211385, -0.745233, -0.765428>,
<0.393024, -0.526088, 0.292433>,
<0.418278, 1.005057, 0.028986>,
<0.460247, 0.042616, 0.550554>,
<0.504974, -0.866449, -0.223504>,
<0.680968, 0.622436, 0.452266>,
<0.756151, -0.461866, -0.633128>,
<0.884017, 0.619872, -0.142153>,
<0.926446, -0.443346, -0.028789>,
<0.993670, 0.125358, 0.229332>
<1.013073, 0.059558, -0.395059>,
}
#declare P0 = Johnson_24_gyroelongated_pentagonal_cupola_verts[20];
#declare P1 = Johnson_24_gyroelongated_pentagonal_cupola_verts[14];
#declare P2 = Johnson_24_gyroelongated_pentagonal_cupola_verts[8];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 25)
 #declare Johnson_24_gyroelongated_pentagonal_cupola_verts[Num] = vtransform(Johnson_24_gyroelongated_pentagonal_cupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_24_gyroelongated_pentagonal_cupola_faces(Tex3, Tex4, Tex5, Tex10, OnPlane)
#local Johnson_24_gyroelongated_pentagonal_cupola_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_24_gyroelongated_pentagonal_cupola_verts[0],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[1],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[2],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[3],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[4],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[5],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[6],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[7],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[8],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[9],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[10],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[11],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[12],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[13],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[14],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[15],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[16],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[17],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[18],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[19],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[20],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[21],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[22],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[23],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[24]
 }
 texture_list {
  4,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  46,
  <1, 3, 5>, 0,
  <5, 3, 8>, 0,
  <5, 8, 12>, 0,
  <12, 8, 14>, 0,
  <12, 14, 18>, 0,
  <18, 14, 20>, 0,
  <18, 20, 22>, 0,
  <22, 20, 24>, 0,
  <22, 24, 23>, 0,
  <23, 24, 21>, 0,
  <15, 18, 22>, 0,
  <17, 23, 19>, 0,
  <11, 13, 7>, 0,
  <6, 2, 1>, 0,
  <9, 5, 12>, 0,
  <23, 21, 19>, 0,
  <19, 21, 16>, 0,
  <19, 16, 13>, 0,
  <13, 16, 10>, 0,
  <13, 10, 7>, 0,
  <7, 10, 4>, 0,
  <7, 4, 2>, 0,
  <2, 4, 0>, 0,
  <2, 0, 1>, 0,
  <1, 0, 3>, 0,
  <15, 9, 12>, 1,
  <15, 12, 18>, 1,
  <17, 15, 22>, 1,
  <17, 22, 23>, 1,
  <11, 17, 19>, 1,
  <11, 19, 13>, 1,
  <6, 11, 7>, 1,
  <6, 7, 2>, 1,
  <9, 6, 1>, 1,
  <9, 1, 5>, 1,
  <9, 15, 17>, 2,
  <9, 17, 11>, 2,
  <9, 11, 6>, 2,
  <20, 14, 8>, 3,
  <20, 8, 3>, 3,
  <20, 3, 0>, 3,
  <20, 0, 4>, 3,
  <20, 4, 10>, 3,
  <20, 10, 16>, 3,
  <20, 16, 21>, 3,
  <20, 21, 24>, 3
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_24_gyroelongated_pentagonal_cupola_verts[20];
 #local P1 = Johnson_24_gyroelongated_pentagonal_cupola_verts[14];
 #local P2 = Johnson_24_gyroelongated_pentagonal_cupola_verts[8];
 #local P3 = Johnson_24_gyroelongated_pentagonal_cupola_verts[3];
 #local P4 = Johnson_24_gyroelongated_pentagonal_cupola_verts[0];
 #local P5 = Johnson_24_gyroelongated_pentagonal_cupola_verts[4];
 #local P6 = Johnson_24_gyroelongated_pentagonal_cupola_verts[10];
 #local P7 = Johnson_24_gyroelongated_pentagonal_cupola_verts[16];
 #local P8 = Johnson_24_gyroelongated_pentagonal_cupola_verts[21];
 #local P9 = Johnson_24_gyroelongated_pentagonal_cupola_verts[24];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_24_gyroelongated_pentagonal_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_24_gyroelongated_pentagonal_cupola_obj }
#end
#end

#macro Johnson_24_gyroelongated_pentagonal_cupola_faces2(OnPlane)
#local Johnson_24_gyroelongated_pentagonal_cupola_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_24_gyroelongated_pentagonal_cupola_verts[0],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[1],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[2],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[3],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[4],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[5],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[6],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[7],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[8],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[9],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[10],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[11],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[12],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[13],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[14],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[15],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[16],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[17],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[18],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[19],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[20],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[21],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[22],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[23],
  Johnson_24_gyroelongated_pentagonal_cupola_verts[24]
 }
 face_indices {
  46,
  <1, 3, 5>,
  <5, 3, 8>,
  <5, 8, 12>,
  <12, 8, 14>,
  <12, 14, 18>,
  <18, 14, 20>,
  <18, 20, 22>,
  <22, 20, 24>,
  <22, 24, 23>,
  <23, 24, 21>,
  <15, 18, 22>,
  <17, 23, 19>,
  <11, 13, 7>,
  <6, 2, 1>,
  <9, 5, 12>,
  <23, 21, 19>,
  <19, 21, 16>,
  <19, 16, 13>,
  <13, 16, 10>,
  <13, 10, 7>,
  <7, 10, 4>,
  <7, 4, 2>,
  <2, 4, 0>,
  <2, 0, 1>,
  <1, 0, 3>,
  <15, 9, 12>,
  <15, 12, 18>,
  <17, 15, 22>,
  <17, 22, 23>,
  <11, 17, 19>,
  <11, 19, 13>,
  <6, 11, 7>,
  <6, 7, 2>,
  <9, 6, 1>,
  <9, 1, 5>,
  <9, 15, 17>,
  <9, 17, 11>,
  <9, 11, 6>,
  <20, 14, 8>,
  <20, 8, 3>,
  <20, 3, 0>,
  <20, 0, 4>,
  <20, 4, 10>,
  <20, 10, 16>,
  <20, 16, 21>,
  <20, 21, 24>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_24_gyroelongated_pentagonal_cupola_verts[20];
 #local P1 = Johnson_24_gyroelongated_pentagonal_cupola_verts[14];
 #local P2 = Johnson_24_gyroelongated_pentagonal_cupola_verts[8];
 #local P3 = Johnson_24_gyroelongated_pentagonal_cupola_verts[3];
 #local P4 = Johnson_24_gyroelongated_pentagonal_cupola_verts[0];
 #local P5 = Johnson_24_gyroelongated_pentagonal_cupola_verts[4];
 #local P6 = Johnson_24_gyroelongated_pentagonal_cupola_verts[10];
 #local P7 = Johnson_24_gyroelongated_pentagonal_cupola_verts[16];
 #local P8 = Johnson_24_gyroelongated_pentagonal_cupola_verts[21];
 #local P9 = Johnson_24_gyroelongated_pentagonal_cupola_verts[24];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_24_gyroelongated_pentagonal_cupola_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_24_gyroelongated_pentagonal_cupola_obj }
#end
#end

#macro Johnson_24_gyroelongated_pentagonal_cupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[0], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[1], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[2], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[3], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[4], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[5], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[6], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[7], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[8], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[9], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[10], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[11], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[12], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[13], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[14], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[15], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[16], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[17], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[18], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[19], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[20], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[21], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[22], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[23], RadVer }
  sphere { Johnson_24_gyroelongated_pentagonal_cupola_verts[24], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[1], Johnson_24_gyroelongated_pentagonal_cupola_verts[3], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[3], Johnson_24_gyroelongated_pentagonal_cupola_verts[5], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[5], Johnson_24_gyroelongated_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[3], Johnson_24_gyroelongated_pentagonal_cupola_verts[8], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[8], Johnson_24_gyroelongated_pentagonal_cupola_verts[5], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[8], Johnson_24_gyroelongated_pentagonal_cupola_verts[12], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[12], Johnson_24_gyroelongated_pentagonal_cupola_verts[5], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[8], Johnson_24_gyroelongated_pentagonal_cupola_verts[14], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[14], Johnson_24_gyroelongated_pentagonal_cupola_verts[12], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[14], Johnson_24_gyroelongated_pentagonal_cupola_verts[18], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[18], Johnson_24_gyroelongated_pentagonal_cupola_verts[12], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[14], Johnson_24_gyroelongated_pentagonal_cupola_verts[20], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[20], Johnson_24_gyroelongated_pentagonal_cupola_verts[18], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[20], Johnson_24_gyroelongated_pentagonal_cupola_verts[22], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[22], Johnson_24_gyroelongated_pentagonal_cupola_verts[18], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[20], Johnson_24_gyroelongated_pentagonal_cupola_verts[24], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[24], Johnson_24_gyroelongated_pentagonal_cupola_verts[22], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[24], Johnson_24_gyroelongated_pentagonal_cupola_verts[23], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[23], Johnson_24_gyroelongated_pentagonal_cupola_verts[22], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[24], Johnson_24_gyroelongated_pentagonal_cupola_verts[21], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[21], Johnson_24_gyroelongated_pentagonal_cupola_verts[23], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[15], Johnson_24_gyroelongated_pentagonal_cupola_verts[18], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[22], Johnson_24_gyroelongated_pentagonal_cupola_verts[15], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[17], Johnson_24_gyroelongated_pentagonal_cupola_verts[23], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[23], Johnson_24_gyroelongated_pentagonal_cupola_verts[19], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[19], Johnson_24_gyroelongated_pentagonal_cupola_verts[17], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[11], Johnson_24_gyroelongated_pentagonal_cupola_verts[13], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[13], Johnson_24_gyroelongated_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[7], Johnson_24_gyroelongated_pentagonal_cupola_verts[11], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[6], Johnson_24_gyroelongated_pentagonal_cupola_verts[2], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[2], Johnson_24_gyroelongated_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[1], Johnson_24_gyroelongated_pentagonal_cupola_verts[6], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[9], Johnson_24_gyroelongated_pentagonal_cupola_verts[5], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[12], Johnson_24_gyroelongated_pentagonal_cupola_verts[9], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[21], Johnson_24_gyroelongated_pentagonal_cupola_verts[19], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[21], Johnson_24_gyroelongated_pentagonal_cupola_verts[16], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[16], Johnson_24_gyroelongated_pentagonal_cupola_verts[19], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[16], Johnson_24_gyroelongated_pentagonal_cupola_verts[13], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[13], Johnson_24_gyroelongated_pentagonal_cupola_verts[19], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[16], Johnson_24_gyroelongated_pentagonal_cupola_verts[10], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[10], Johnson_24_gyroelongated_pentagonal_cupola_verts[13], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[10], Johnson_24_gyroelongated_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[10], Johnson_24_gyroelongated_pentagonal_cupola_verts[4], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[4], Johnson_24_gyroelongated_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[4], Johnson_24_gyroelongated_pentagonal_cupola_verts[2], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[2], Johnson_24_gyroelongated_pentagonal_cupola_verts[7], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[4], Johnson_24_gyroelongated_pentagonal_cupola_verts[0], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[0], Johnson_24_gyroelongated_pentagonal_cupola_verts[2], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[0], Johnson_24_gyroelongated_pentagonal_cupola_verts[1], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[0], Johnson_24_gyroelongated_pentagonal_cupola_verts[3], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[15], Johnson_24_gyroelongated_pentagonal_cupola_verts[9], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[17], Johnson_24_gyroelongated_pentagonal_cupola_verts[15], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[11], Johnson_24_gyroelongated_pentagonal_cupola_verts[17], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[6], Johnson_24_gyroelongated_pentagonal_cupola_verts[11], RadEdg }
  cylinder { Johnson_24_gyroelongated_pentagonal_cupola_verts[9], Johnson_24_gyroelongated_pentagonal_cupola_verts[6], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_24_gyroelongated_pentagonal_cupola_verts[20];
 #local P1 = Johnson_24_gyroelongated_pentagonal_cupola_verts[14];
 #local P2 = Johnson_24_gyroelongated_pentagonal_cupola_verts[8];
 #local P3 = Johnson_24_gyroelongated_pentagonal_cupola_verts[3];
 #local P4 = Johnson_24_gyroelongated_pentagonal_cupola_verts[0];
 #local P5 = Johnson_24_gyroelongated_pentagonal_cupola_verts[4];
 #local P6 = Johnson_24_gyroelongated_pentagonal_cupola_verts[10];
 #local P7 = Johnson_24_gyroelongated_pentagonal_cupola_verts[16];
 #local P8 = Johnson_24_gyroelongated_pentagonal_cupola_verts[21];
 #local P9 = Johnson_24_gyroelongated_pentagonal_cupola_verts[24];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_25_gyroelongated_pentagonal_rotunda_verts = array[30]
{
<-0.897802, -0.193467, -0.273331>,
<-0.877838, -0.070089, 0.304735>,
<-0.730720, -0.609618, 0.112262>,
<-0.716275, 0.285603, -0.568831>,
<-0.703732, -0.716856, -0.468730>,
<-0.696138, -0.246211, -0.826802>,
<-0.683973, 0.485232, 0.366499>,
<-0.584121, 0.705062, -0.173395>,
<-0.516890, 0.069081, 0.752092>,
<-0.378328, -1.037777, -0.093360>,
<-0.358446, 0.194389, -1.030805>,
<-0.278847, -0.803894, 0.440665>,
<-0.255475, 0.644603, -0.661367>,
<-0.223173, 0.844232, 0.273963>,
<-0.146694, -0.384435, 0.836102>,
<0.047172, 0.170886, 0.897866>,
<0.155780, -1.086392, 0.155930>,
<0.180355, 0.436649, -1.002815>,
<0.228699, 0.649956, 0.602366>,
<0.285215, -0.702090, 0.586439>,
<0.308587, 0.746408, -0.515593>,
<0.328551, 0.869786, 0.062473>,
<0.598896, 0.196439, 0.686376>,
<0.694582, -0.844133, 0.183918>
<0.714463, 0.388033, -0.753526>,
<0.746014, -0.343089, 0.493903>,
<0.760459, 0.552132, -0.187190>,
<0.927542, 0.135981, 0.198403>,
<1.032273, -0.403533, -0.020084>,
<1.039867, 0.067112, -0.378156>,
}
#declare P0 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[28];
#declare P1 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[23];
#declare P2 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[16];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 30)
 #declare Johnson_25_gyroelongated_pentagonal_rotunda_verts[Num] = vtransform(Johnson_25_gyroelongated_pentagonal_rotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_25_gyroelongated_pentagonal_rotunda_faces(Tex3, Tex5, Tex10, OnPlane)
#local Johnson_25_gyroelongated_pentagonal_rotunda_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[0],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[1],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[2],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[3],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[4],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[5],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[6],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[7],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[8],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[9],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[10],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[11],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[12],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[13],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[14],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[15],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[16],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[17],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[18],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[19],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[20],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[21],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[22],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[23],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[24],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[25],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[26],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[27],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[28],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[29]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex5 },
  texture { Tex10 }
 }
 face_indices {
  56,
  <2, 9, 11>, 0,
  <11, 9, 16>, 0,
  <11, 16, 19>, 0,
  <19, 16, 23>, 0,
  <19, 23, 25>, 0,
  <25, 23, 28>, 0,
  <25, 28, 27>, 0,
  <27, 28, 29>, 0,
  <27, 29, 26>, 0,
  <26, 29, 24>, 0,
  <15, 22, 18>, 0,
  <22, 25, 27>, 0,
  <18, 21, 13>, 0,
  <21, 26, 20>, 0,
  <13, 7, 6>, 0,
  <7, 12, 3>, 0,
  <6, 1, 8>, 0,
  <1, 0, 2>, 0,
  <8, 14, 15>, 0,
  <14, 11, 19>, 0,
  <26, 24, 20>, 0,
  <20, 24, 17>, 0,
  <20, 17, 12>, 0,
  <12, 17, 10>, 0,
  <12, 10, 3>, 0,
  <3, 10, 5>, 0,
  <3, 5, 0>, 0,
  <0, 5, 4>, 0,
  <0, 4, 2>, 0,
  <2, 4, 9>, 0,
  <15, 18, 13>, 1,
  <15, 13, 6>, 1,
  <15, 6, 8>, 1,
  <15, 14, 19>, 1,
  <15, 19, 25>, 1,
  <15, 25, 22>, 1,
  <18, 22, 27>, 1,
  <18, 27, 26>, 1,
  <18, 26, 21>, 1,
  <13, 21, 20>, 1,
  <13, 20, 12>, 1,
  <13, 12, 7>, 1,
  <6, 7, 3>, 1,
  <6, 3, 0>, 1,
  <6, 0, 1>, 1,
  <8, 1, 2>, 1,
  <8, 2, 11>, 1,
  <8, 11, 14>, 1,
  <28, 23, 16>, 2,
  <28, 16, 9>, 2,
  <28, 9, 4>, 2,
  <28, 4, 5>, 2,
  <28, 5, 10>, 2,
  <28, 10, 17>, 2,
  <28, 17, 24>, 2,
  <28, 24, 29>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[28];
 #local P1 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[23];
 #local P2 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[16];
 #local P3 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[9];
 #local P4 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[4];
 #local P5 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[5];
 #local P6 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[10];
 #local P7 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[17];
 #local P8 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[24];
 #local P9 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[29];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_25_gyroelongated_pentagonal_rotunda_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_25_gyroelongated_pentagonal_rotunda_obj }
#end
#end

#macro Johnson_25_gyroelongated_pentagonal_rotunda_faces2(OnPlane)
#local Johnson_25_gyroelongated_pentagonal_rotunda_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[0],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[1],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[2],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[3],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[4],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[5],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[6],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[7],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[8],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[9],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[10],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[11],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[12],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[13],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[14],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[15],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[16],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[17],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[18],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[19],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[20],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[21],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[22],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[23],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[24],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[25],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[26],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[27],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[28],
  Johnson_25_gyroelongated_pentagonal_rotunda_verts[29]
 }
 face_indices {
  56,
  <2, 9, 11>,
  <11, 9, 16>,
  <11, 16, 19>,
  <19, 16, 23>,
  <19, 23, 25>,
  <25, 23, 28>,
  <25, 28, 27>,
  <27, 28, 29>,
  <27, 29, 26>,
  <26, 29, 24>,
  <15, 22, 18>,
  <22, 25, 27>,
  <18, 21, 13>,
  <21, 26, 20>,
  <13, 7, 6>,
  <7, 12, 3>,
  <6, 1, 8>,
  <1, 0, 2>,
  <8, 14, 15>,
  <14, 11, 19>,
  <26, 24, 20>,
  <20, 24, 17>,
  <20, 17, 12>,
  <12, 17, 10>,
  <12, 10, 3>,
  <3, 10, 5>,
  <3, 5, 0>,
  <0, 5, 4>,
  <0, 4, 2>,
  <2, 4, 9>,
  <15, 18, 13>,
  <15, 13, 6>,
  <15, 6, 8>,
  <15, 14, 19>,
  <15, 19, 25>,
  <15, 25, 22>,
  <18, 22, 27>,
  <18, 27, 26>,
  <18, 26, 21>,
  <13, 21, 20>,
  <13, 20, 12>,
  <13, 12, 7>,
  <6, 7, 3>,
  <6, 3, 0>,
  <6, 0, 1>,
  <8, 1, 2>,
  <8, 2, 11>,
  <8, 11, 14>,
  <28, 23, 16>,
  <28, 16, 9>,
  <28, 9, 4>,
  <28, 4, 5>,
  <28, 5, 10>,
  <28, 10, 17>,
  <28, 17, 24>,
  <28, 24, 29>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[28];
 #local P1 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[23];
 #local P2 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[16];
 #local P3 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[9];
 #local P4 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[4];
 #local P5 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[5];
 #local P6 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[10];
 #local P7 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[17];
 #local P8 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[24];
 #local P9 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[29];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_25_gyroelongated_pentagonal_rotunda_obj
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_25_gyroelongated_pentagonal_rotunda_obj }
#end
#end

#macro Johnson_25_gyroelongated_pentagonal_rotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[0], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[1], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[2], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[3], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[4], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[5], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[6], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[7], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[8], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[9], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[10], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[11], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[12], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[13], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[14], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[15], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[16], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[17], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[18], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[19], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[20], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[21], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[22], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[23], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[24], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[25], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[26], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[27], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[28], RadVer }
  sphere { Johnson_25_gyroelongated_pentagonal_rotunda_verts[29], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[2], Johnson_25_gyroelongated_pentagonal_rotunda_verts[9], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[9], Johnson_25_gyroelongated_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[11], Johnson_25_gyroelongated_pentagonal_rotunda_verts[2], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[9], Johnson_25_gyroelongated_pentagonal_rotunda_verts[16], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[16], Johnson_25_gyroelongated_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[16], Johnson_25_gyroelongated_pentagonal_rotunda_verts[19], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[19], Johnson_25_gyroelongated_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[16], Johnson_25_gyroelongated_pentagonal_rotunda_verts[23], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[23], Johnson_25_gyroelongated_pentagonal_rotunda_verts[19], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[23], Johnson_25_gyroelongated_pentagonal_rotunda_verts[25], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[25], Johnson_25_gyroelongated_pentagonal_rotunda_verts[19], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[23], Johnson_25_gyroelongated_pentagonal_rotunda_verts[28], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[28], Johnson_25_gyroelongated_pentagonal_rotunda_verts[25], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[28], Johnson_25_gyroelongated_pentagonal_rotunda_verts[27], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[27], Johnson_25_gyroelongated_pentagonal_rotunda_verts[25], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[28], Johnson_25_gyroelongated_pentagonal_rotunda_verts[29], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[29], Johnson_25_gyroelongated_pentagonal_rotunda_verts[27], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[29], Johnson_25_gyroelongated_pentagonal_rotunda_verts[26], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[26], Johnson_25_gyroelongated_pentagonal_rotunda_verts[27], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[29], Johnson_25_gyroelongated_pentagonal_rotunda_verts[24], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[24], Johnson_25_gyroelongated_pentagonal_rotunda_verts[26], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[15], Johnson_25_gyroelongated_pentagonal_rotunda_verts[22], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[22], Johnson_25_gyroelongated_pentagonal_rotunda_verts[18], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[18], Johnson_25_gyroelongated_pentagonal_rotunda_verts[15], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[22], Johnson_25_gyroelongated_pentagonal_rotunda_verts[25], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[27], Johnson_25_gyroelongated_pentagonal_rotunda_verts[22], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[18], Johnson_25_gyroelongated_pentagonal_rotunda_verts[21], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[21], Johnson_25_gyroelongated_pentagonal_rotunda_verts[13], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[13], Johnson_25_gyroelongated_pentagonal_rotunda_verts[18], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[21], Johnson_25_gyroelongated_pentagonal_rotunda_verts[26], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[26], Johnson_25_gyroelongated_pentagonal_rotunda_verts[20], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[20], Johnson_25_gyroelongated_pentagonal_rotunda_verts[21], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[13], Johnson_25_gyroelongated_pentagonal_rotunda_verts[7], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[7], Johnson_25_gyroelongated_pentagonal_rotunda_verts[6], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[6], Johnson_25_gyroelongated_pentagonal_rotunda_verts[13], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[7], Johnson_25_gyroelongated_pentagonal_rotunda_verts[12], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[12], Johnson_25_gyroelongated_pentagonal_rotunda_verts[3], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[3], Johnson_25_gyroelongated_pentagonal_rotunda_verts[7], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[6], Johnson_25_gyroelongated_pentagonal_rotunda_verts[1], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[1], Johnson_25_gyroelongated_pentagonal_rotunda_verts[8], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[8], Johnson_25_gyroelongated_pentagonal_rotunda_verts[6], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[1], Johnson_25_gyroelongated_pentagonal_rotunda_verts[0], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[0], Johnson_25_gyroelongated_pentagonal_rotunda_verts[2], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[2], Johnson_25_gyroelongated_pentagonal_rotunda_verts[1], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[8], Johnson_25_gyroelongated_pentagonal_rotunda_verts[14], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[14], Johnson_25_gyroelongated_pentagonal_rotunda_verts[15], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[15], Johnson_25_gyroelongated_pentagonal_rotunda_verts[8], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[14], Johnson_25_gyroelongated_pentagonal_rotunda_verts[11], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[19], Johnson_25_gyroelongated_pentagonal_rotunda_verts[14], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[24], Johnson_25_gyroelongated_pentagonal_rotunda_verts[20], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[24], Johnson_25_gyroelongated_pentagonal_rotunda_verts[17], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[17], Johnson_25_gyroelongated_pentagonal_rotunda_verts[20], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[17], Johnson_25_gyroelongated_pentagonal_rotunda_verts[12], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[12], Johnson_25_gyroelongated_pentagonal_rotunda_verts[20], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[17], Johnson_25_gyroelongated_pentagonal_rotunda_verts[10], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[10], Johnson_25_gyroelongated_pentagonal_rotunda_verts[12], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[10], Johnson_25_gyroelongated_pentagonal_rotunda_verts[3], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[10], Johnson_25_gyroelongated_pentagonal_rotunda_verts[5], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[5], Johnson_25_gyroelongated_pentagonal_rotunda_verts[3], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[5], Johnson_25_gyroelongated_pentagonal_rotunda_verts[0], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[0], Johnson_25_gyroelongated_pentagonal_rotunda_verts[3], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[5], Johnson_25_gyroelongated_pentagonal_rotunda_verts[4], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[4], Johnson_25_gyroelongated_pentagonal_rotunda_verts[0], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[4], Johnson_25_gyroelongated_pentagonal_rotunda_verts[2], RadEdg }
  cylinder { Johnson_25_gyroelongated_pentagonal_rotunda_verts[4], Johnson_25_gyroelongated_pentagonal_rotunda_verts[9], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[28];
 #local P1 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[23];
 #local P2 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[16];
 #local P3 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[9];
 #local P4 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[4];
 #local P5 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[5];
 #local P6 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[10];
 #local P7 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[17];
 #local P8 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[24];
 #local P9 = Johnson_25_gyroelongated_pentagonal_rotunda_verts[29];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4+P5+P6+P7+P8+P9)/10
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_26_gyrobifastigium_verts = array[8]
{
<-0.577350, 0.577350, 0.000000>,
<0.577350, 0.577350, 0.000000>,
<0.577350, -0.577350, 0.000000>,
<-0.577350, -0.577350, 0.000000>,
<0.000000, 0.577350, 1.000000>,
<0.000000, -0.577350, 1.000000>,
<-0.577350, 0.000000, -1.000000>,
<0.577350, 0.000000, -1.000000>,
}
#declare P0 = Johnson_26_gyrobifastigium_verts[0];
#declare P1 = Johnson_26_gyrobifastigium_verts[1];
#declare P2 = Johnson_26_gyrobifastigium_verts[2];
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
 #declare Johnson_26_gyrobifastigium_verts[Num] = vtransform(Johnson_26_gyrobifastigium_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_26_gyrobifastigium_faces(Tex3, Tex4, OnPlane)
#local Johnson_26_gyrobifastigium_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_26_gyrobifastigium_verts[0],
  Johnson_26_gyrobifastigium_verts[1],
  Johnson_26_gyrobifastigium_verts[2],
  Johnson_26_gyrobifastigium_verts[3],
  Johnson_26_gyrobifastigium_verts[4],
  Johnson_26_gyrobifastigium_verts[5],
  Johnson_26_gyrobifastigium_verts[6],
  Johnson_26_gyrobifastigium_verts[7]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  12,
  <4, 0, 1>, 0,
  <5, 2, 3>, 0,
  <6, 0, 3>, 0,
  <7, 2, 1>, 0,
  <0, 4, 5>, 1,
  <0, 5, 3>, 1,
  <2, 5, 4>, 1,
  <2, 4, 1>, 1,
  <0, 6, 7>, 1,
  <0, 7, 1>, 1,
  <2, 7, 6>, 1,
  <2, 6, 3>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_26_gyrobifastigium_verts[7];
 #local P1 = Johnson_26_gyrobifastigium_verts[2];
 #local P2 = Johnson_26_gyrobifastigium_verts[6];
 #local P3 = Johnson_26_gyrobifastigium_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_26_gyrobifastigium_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_26_gyrobifastigium_obj }
#end
#end

#macro Johnson_26_gyrobifastigium_faces2(OnPlane)
#local Johnson_26_gyrobifastigium_obj = mesh2 {
 vertex_vectors {
  8,
  Johnson_26_gyrobifastigium_verts[0],
  Johnson_26_gyrobifastigium_verts[1],
  Johnson_26_gyrobifastigium_verts[2],
  Johnson_26_gyrobifastigium_verts[3],
  Johnson_26_gyrobifastigium_verts[4],
  Johnson_26_gyrobifastigium_verts[5],
  Johnson_26_gyrobifastigium_verts[6],
  Johnson_26_gyrobifastigium_verts[7]
 }
 face_indices {
  12,
  <4, 0, 1>,
  <5, 2, 3>,
  <6, 0, 3>,
  <7, 2, 1>,
  <0, 4, 5>,
  <0, 5, 3>,
  <2, 5, 4>,
  <2, 4, 1>,
  <0, 6, 7>,
  <0, 7, 1>,
  <2, 7, 6>,
  <2, 6, 3>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_26_gyrobifastigium_verts[7];
 #local P1 = Johnson_26_gyrobifastigium_verts[2];
 #local P2 = Johnson_26_gyrobifastigium_verts[6];
 #local P3 = Johnson_26_gyrobifastigium_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_26_gyrobifastigium_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_26_gyrobifastigium_obj }
#end
#end

#macro Johnson_26_gyrobifastigium_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_26_gyrobifastigium_verts[0], RadVer }
  sphere { Johnson_26_gyrobifastigium_verts[1], RadVer }
  sphere { Johnson_26_gyrobifastigium_verts[2], RadVer }
  sphere { Johnson_26_gyrobifastigium_verts[3], RadVer }
  sphere { Johnson_26_gyrobifastigium_verts[4], RadVer }
  sphere { Johnson_26_gyrobifastigium_verts[5], RadVer }
  sphere { Johnson_26_gyrobifastigium_verts[6], RadVer }
  sphere { Johnson_26_gyrobifastigium_verts[7], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_26_gyrobifastigium_verts[4], Johnson_26_gyrobifastigium_verts[0], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[0], Johnson_26_gyrobifastigium_verts[1], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[1], Johnson_26_gyrobifastigium_verts[4], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[5], Johnson_26_gyrobifastigium_verts[2], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[2], Johnson_26_gyrobifastigium_verts[3], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[3], Johnson_26_gyrobifastigium_verts[5], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[6], Johnson_26_gyrobifastigium_verts[0], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[0], Johnson_26_gyrobifastigium_verts[3], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[3], Johnson_26_gyrobifastigium_verts[6], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[7], Johnson_26_gyrobifastigium_verts[2], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[2], Johnson_26_gyrobifastigium_verts[1], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[1], Johnson_26_gyrobifastigium_verts[7], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[4], Johnson_26_gyrobifastigium_verts[5], RadEdg }
  cylinder { Johnson_26_gyrobifastigium_verts[6], Johnson_26_gyrobifastigium_verts[7], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_26_gyrobifastigium_verts[7];
 #local P1 = Johnson_26_gyrobifastigium_verts[2];
 #local P2 = Johnson_26_gyrobifastigium_verts[6];
 #local P3 = Johnson_26_gyrobifastigium_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_27_triangular_orthobicupola_verts = array[12]
{
<-0.969360, 0.238651, 0.058198>,
<-0.683128, -0.715413, 0.146701>,
<-0.623092, -0.255511, -0.739236>,
<-0.478567, -0.062330, 0.875836>,
<-0.286232, 0.954064, -0.088503>,
<0.060036, 0.459902, -0.885938>,
<0.204561, 0.653083, 0.729135>,
<0.286232, -0.954064, 0.088503>,
<0.346268, -0.494162, -0.797435>,
<0.490793, -0.300981, 0.817638>,
<0.683128, 0.715413, -0.146701>,
<0.969360, -0.238651, -0.058198>,
}
#declare P0 = Johnson_27_triangular_orthobicupola_verts[5];
#declare P1 = Johnson_27_triangular_orthobicupola_verts[8];
#declare P2 = Johnson_27_triangular_orthobicupola_verts[2];
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
 #declare Johnson_27_triangular_orthobicupola_verts[Num] = vtransform(Johnson_27_triangular_orthobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_27_triangular_orthobicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_27_triangular_orthobicupola_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_27_triangular_orthobicupola_verts[0],
  Johnson_27_triangular_orthobicupola_verts[1],
  Johnson_27_triangular_orthobicupola_verts[2],
  Johnson_27_triangular_orthobicupola_verts[3],
  Johnson_27_triangular_orthobicupola_verts[4],
  Johnson_27_triangular_orthobicupola_verts[5],
  Johnson_27_triangular_orthobicupola_verts[6],
  Johnson_27_triangular_orthobicupola_verts[7],
  Johnson_27_triangular_orthobicupola_verts[8],
  Johnson_27_triangular_orthobicupola_verts[9],
  Johnson_27_triangular_orthobicupola_verts[10],
  Johnson_27_triangular_orthobicupola_verts[11]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  20,
  <2, 5, 8>, 0,
  <5, 4, 10>, 0,
  <8, 11, 7>, 0,
  <2, 1, 0>, 0,
  <6, 3, 9>, 0,
  <3, 0, 1>, 0,
  <9, 7, 11>, 0,
  <6, 10, 4>, 0,
  <5, 2, 0>, 1,
  <5, 0, 4>, 1,
  <8, 5, 10>, 1,
  <8, 10, 11>, 1,
  <2, 8, 7>, 1,
  <2, 7, 1>, 1,
  <3, 6, 4>, 1,
  <3, 4, 0>, 1,
  <9, 3, 1>, 1,
  <9, 1, 7>, 1,
  <6, 9, 11>, 1,
  <6, 11, 10>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_27_triangular_orthobicupola_verts[5];
 #local P1 = Johnson_27_triangular_orthobicupola_verts[8];
 #local P2 = Johnson_27_triangular_orthobicupola_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_27_triangular_orthobicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_27_triangular_orthobicupola_obj }
#end
#end

#macro Johnson_27_triangular_orthobicupola_faces2(OnPlane)
#local Johnson_27_triangular_orthobicupola_obj = mesh2 {
 vertex_vectors {
  12,
  Johnson_27_triangular_orthobicupola_verts[0],
  Johnson_27_triangular_orthobicupola_verts[1],
  Johnson_27_triangular_orthobicupola_verts[2],
  Johnson_27_triangular_orthobicupola_verts[3],
  Johnson_27_triangular_orthobicupola_verts[4],
  Johnson_27_triangular_orthobicupola_verts[5],
  Johnson_27_triangular_orthobicupola_verts[6],
  Johnson_27_triangular_orthobicupola_verts[7],
  Johnson_27_triangular_orthobicupola_verts[8],
  Johnson_27_triangular_orthobicupola_verts[9],
  Johnson_27_triangular_orthobicupola_verts[10],
  Johnson_27_triangular_orthobicupola_verts[11]
 }
 face_indices {
  20,
  <2, 5, 8>,
  <5, 4, 10>,
  <8, 11, 7>,
  <2, 1, 0>,
  <6, 3, 9>,
  <3, 0, 1>,
  <9, 7, 11>,
  <6, 10, 4>,
  <5, 2, 0>,
  <5, 0, 4>,
  <8, 5, 10>,
  <8, 10, 11>,
  <2, 8, 7>,
  <2, 7, 1>,
  <3, 6, 4>,
  <3, 4, 0>,
  <9, 3, 1>,
  <9, 1, 7>,
  <6, 9, 11>,
  <6, 11, 10>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_27_triangular_orthobicupola_verts[5];
 #local P1 = Johnson_27_triangular_orthobicupola_verts[8];
 #local P2 = Johnson_27_triangular_orthobicupola_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_27_triangular_orthobicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_27_triangular_orthobicupola_obj }
#end
#end

#macro Johnson_27_triangular_orthobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_27_triangular_orthobicupola_verts[0], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[1], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[2], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[3], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[4], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[5], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[6], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[7], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[8], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[9], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[10], RadVer }
  sphere { Johnson_27_triangular_orthobicupola_verts[11], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_27_triangular_orthobicupola_verts[2], Johnson_27_triangular_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[5], Johnson_27_triangular_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[8], Johnson_27_triangular_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[5], Johnson_27_triangular_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[4], Johnson_27_triangular_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[10], Johnson_27_triangular_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[8], Johnson_27_triangular_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[11], Johnson_27_triangular_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[7], Johnson_27_triangular_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[2], Johnson_27_triangular_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[1], Johnson_27_triangular_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[0], Johnson_27_triangular_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[6], Johnson_27_triangular_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[3], Johnson_27_triangular_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[9], Johnson_27_triangular_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[3], Johnson_27_triangular_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[1], Johnson_27_triangular_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[9], Johnson_27_triangular_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[11], Johnson_27_triangular_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[6], Johnson_27_triangular_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[4], Johnson_27_triangular_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[0], Johnson_27_triangular_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[10], Johnson_27_triangular_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_27_triangular_orthobicupola_verts[7], Johnson_27_triangular_orthobicupola_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_27_triangular_orthobicupola_verts[5];
 #local P1 = Johnson_27_triangular_orthobicupola_verts[8];
 #local P2 = Johnson_27_triangular_orthobicupola_verts[2];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_28_square_orthobicupola_verts = array[16]
{
<-1.055402, 0.383836, -0.000110>,
<-1.017695, -0.474869, 0.000238>,
<-0.474869, 1.017695, -0.000394>,
<-0.448233, 0.410252, -0.607929>,
<-0.448179, 0.410746, 0.607634>,
<-0.410526, -0.448453, -0.607581>,
<-0.410472, -0.447959, 0.607981>,
<-0.383836, -1.055402, 0.000446>,
<0.383836, 1.055402, -0.000447>,
<0.410472, 0.447959, -0.607982>,
<0.410526, 0.448453, 0.607580>,
<0.448179, -0.410746, -0.607635>,
<0.448233, -0.410252, 0.607928>,
<0.474869, -1.017695, 0.000392>,
<1.017695, 0.474869, -0.000239>,
<1.055402, -0.383836, 0.000109>,
}
#declare P0 = Johnson_28_square_orthobicupola_verts[4];
#declare P1 = Johnson_28_square_orthobicupola_verts[10];
#declare P2 = Johnson_28_square_orthobicupola_verts[6];
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
 #declare Johnson_28_square_orthobicupola_verts[Num] = vtransform(Johnson_28_square_orthobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_28_square_orthobicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_28_square_orthobicupola_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_28_square_orthobicupola_verts[0],
  Johnson_28_square_orthobicupola_verts[1],
  Johnson_28_square_orthobicupola_verts[2],
  Johnson_28_square_orthobicupola_verts[3],
  Johnson_28_square_orthobicupola_verts[4],
  Johnson_28_square_orthobicupola_verts[5],
  Johnson_28_square_orthobicupola_verts[6],
  Johnson_28_square_orthobicupola_verts[7],
  Johnson_28_square_orthobicupola_verts[8],
  Johnson_28_square_orthobicupola_verts[9],
  Johnson_28_square_orthobicupola_verts[10],
  Johnson_28_square_orthobicupola_verts[11],
  Johnson_28_square_orthobicupola_verts[12],
  Johnson_28_square_orthobicupola_verts[13],
  Johnson_28_square_orthobicupola_verts[14],
  Johnson_28_square_orthobicupola_verts[15]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  28,
  <3, 0, 2>, 0,
  <9, 8, 14>, 0,
  <11, 15, 13>, 0,
  <5, 7, 1>, 0,
  <6, 1, 7>, 0,
  <12, 13, 15>, 0,
  <10, 14, 8>, 0,
  <4, 2, 0>, 0,
  <5, 3, 9>, 1,
  <5, 9, 11>, 1,
  <3, 5, 1>, 1,
  <3, 1, 0>, 1,
  <9, 3, 2>, 1,
  <9, 2, 8>, 1,
  <11, 9, 14>, 1,
  <11, 14, 15>, 1,
  <5, 11, 13>, 1,
  <5, 13, 7>, 1,
  <4, 6, 12>, 1,
  <4, 12, 10>, 1,
  <6, 4, 0>, 1,
  <6, 0, 1>, 1,
  <12, 6, 7>, 1,
  <12, 7, 13>, 1,
  <10, 12, 15>, 1,
  <10, 15, 14>, 1,
  <4, 10, 8>, 1,
  <4, 8, 2>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_28_square_orthobicupola_verts[10];
 #local P1 = Johnson_28_square_orthobicupola_verts[4];
 #local P2 = Johnson_28_square_orthobicupola_verts[12];
 #local P3 = Johnson_28_square_orthobicupola_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_28_square_orthobicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_28_square_orthobicupola_obj }
#end
#end

#macro Johnson_28_square_orthobicupola_faces2(OnPlane)
#local Johnson_28_square_orthobicupola_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_28_square_orthobicupola_verts[0],
  Johnson_28_square_orthobicupola_verts[1],
  Johnson_28_square_orthobicupola_verts[2],
  Johnson_28_square_orthobicupola_verts[3],
  Johnson_28_square_orthobicupola_verts[4],
  Johnson_28_square_orthobicupola_verts[5],
  Johnson_28_square_orthobicupola_verts[6],
  Johnson_28_square_orthobicupola_verts[7],
  Johnson_28_square_orthobicupola_verts[8],
  Johnson_28_square_orthobicupola_verts[9],
  Johnson_28_square_orthobicupola_verts[10],
  Johnson_28_square_orthobicupola_verts[11],
  Johnson_28_square_orthobicupola_verts[12],
  Johnson_28_square_orthobicupola_verts[13],
  Johnson_28_square_orthobicupola_verts[14],
  Johnson_28_square_orthobicupola_verts[15]
 }
 face_indices {
  28,
  <3, 0, 2>,
  <9, 8, 14>,
  <11, 15, 13>,
  <5, 7, 1>,
  <6, 1, 7>,
  <12, 13, 15>,
  <10, 14, 8>,
  <4, 2, 0>,
  <5, 3, 9>,
  <5, 9, 11>,
  <3, 5, 1>,
  <3, 1, 0>,
  <9, 3, 2>,
  <9, 2, 8>,
  <11, 9, 14>,
  <11, 14, 15>,
  <5, 11, 13>,
  <5, 13, 7>,
  <4, 6, 12>,
  <4, 12, 10>,
  <6, 4, 0>,
  <6, 0, 1>,
  <12, 6, 7>,
  <12, 7, 13>,
  <10, 12, 15>,
  <10, 15, 14>,
  <4, 10, 8>,
  <4, 8, 2>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_28_square_orthobicupola_verts[10];
 #local P1 = Johnson_28_square_orthobicupola_verts[4];
 #local P2 = Johnson_28_square_orthobicupola_verts[12];
 #local P3 = Johnson_28_square_orthobicupola_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_28_square_orthobicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_28_square_orthobicupola_obj }
#end
#end

#macro Johnson_28_square_orthobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_28_square_orthobicupola_verts[0], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[1], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[2], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[3], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[4], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[5], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[6], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[7], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[8], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[9], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[10], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[11], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[12], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[13], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[14], RadVer }
  sphere { Johnson_28_square_orthobicupola_verts[15], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_28_square_orthobicupola_verts[3], Johnson_28_square_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[0], Johnson_28_square_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[2], Johnson_28_square_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[9], Johnson_28_square_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[8], Johnson_28_square_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[14], Johnson_28_square_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[11], Johnson_28_square_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[15], Johnson_28_square_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[13], Johnson_28_square_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[5], Johnson_28_square_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[7], Johnson_28_square_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[1], Johnson_28_square_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[6], Johnson_28_square_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[7], Johnson_28_square_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[12], Johnson_28_square_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[15], Johnson_28_square_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[10], Johnson_28_square_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[8], Johnson_28_square_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[4], Johnson_28_square_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[0], Johnson_28_square_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[5], Johnson_28_square_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[3], Johnson_28_square_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[9], Johnson_28_square_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[11], Johnson_28_square_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[1], Johnson_28_square_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[2], Johnson_28_square_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[14], Johnson_28_square_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[13], Johnson_28_square_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[4], Johnson_28_square_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[6], Johnson_28_square_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[12], Johnson_28_square_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_28_square_orthobicupola_verts[10], Johnson_28_square_orthobicupola_verts[4], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_28_square_orthobicupola_verts[10];
 #local P1 = Johnson_28_square_orthobicupola_verts[4];
 #local P2 = Johnson_28_square_orthobicupola_verts[12];
 #local P3 = Johnson_28_square_orthobicupola_verts[6];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_29_square_gyrobicupola_verts = array[16]
{
<-1.105000, -0.077473, -0.184867>,
<-0.863019, 0.717824, 0.033637>,
<-0.699688, -0.827387, -0.295079>,
<-0.617244, -0.399090, 0.445571>,
<-0.487757, 0.321617, -0.630438>,
<-0.375262, 0.396206, 0.664075>,
<-0.115492, 1.092629, 0.232437>,
<-0.082444, -0.428297, -0.740649>,
<0.115493, -1.092629, -0.232437>,
<0.197937, -0.664332, 0.508212>,
<0.259770, 0.696423, -0.431638>,
<0.439918, 0.130964, 0.726716>,
<0.665082, -0.053491, -0.541849>,
<0.699688, 0.827387, 0.295079>,
<0.863019, -0.717824, -0.033637>,
<1.105000, 0.077473, 0.184867>,
}
#declare P0 = Johnson_29_square_gyrobicupola_verts[10];
#declare P1 = Johnson_29_square_gyrobicupola_verts[4];
#declare P2 = Johnson_29_square_gyrobicupola_verts[12];
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
 #declare Johnson_29_square_gyrobicupola_verts[Num] = vtransform(Johnson_29_square_gyrobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_29_square_gyrobicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_29_square_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_29_square_gyrobicupola_verts[0],
  Johnson_29_square_gyrobicupola_verts[1],
  Johnson_29_square_gyrobicupola_verts[2],
  Johnson_29_square_gyrobicupola_verts[3],
  Johnson_29_square_gyrobicupola_verts[4],
  Johnson_29_square_gyrobicupola_verts[5],
  Johnson_29_square_gyrobicupola_verts[6],
  Johnson_29_square_gyrobicupola_verts[7],
  Johnson_29_square_gyrobicupola_verts[8],
  Johnson_29_square_gyrobicupola_verts[9],
  Johnson_29_square_gyrobicupola_verts[10],
  Johnson_29_square_gyrobicupola_verts[11],
  Johnson_29_square_gyrobicupola_verts[12],
  Johnson_29_square_gyrobicupola_verts[13],
  Johnson_29_square_gyrobicupola_verts[14],
  Johnson_29_square_gyrobicupola_verts[15]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  28,
  <4, 0, 1>, 0,
  <10, 6, 13>, 0,
  <12, 15, 14>, 0,
  <7, 8, 2>, 0,
  <3, 0, 2>, 0,
  <9, 8, 14>, 0,
  <11, 15, 13>, 0,
  <5, 6, 1>, 0,
  <7, 4, 10>, 1,
  <7, 10, 12>, 1,
  <4, 7, 2>, 1,
  <4, 2, 0>, 1,
  <10, 4, 1>, 1,
  <10, 1, 6>, 1,
  <12, 10, 13>, 1,
  <12, 13, 15>, 1,
  <7, 12, 14>, 1,
  <7, 14, 8>, 1,
  <5, 3, 9>, 1,
  <5, 9, 11>, 1,
  <3, 5, 1>, 1,
  <3, 1, 0>, 1,
  <9, 3, 2>, 1,
  <9, 2, 8>, 1,
  <11, 9, 14>, 1,
  <11, 14, 15>, 1,
  <5, 11, 13>, 1,
  <5, 13, 6>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_29_square_gyrobicupola_verts[7];
 #local P1 = Johnson_29_square_gyrobicupola_verts[4];
 #local P2 = Johnson_29_square_gyrobicupola_verts[12];
 #local P3 = Johnson_29_square_gyrobicupola_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_29_square_gyrobicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_29_square_gyrobicupola_obj }
#end
#end

#macro Johnson_29_square_gyrobicupola_faces2(OnPlane)
#local Johnson_29_square_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  16,
  Johnson_29_square_gyrobicupola_verts[0],
  Johnson_29_square_gyrobicupola_verts[1],
  Johnson_29_square_gyrobicupola_verts[2],
  Johnson_29_square_gyrobicupola_verts[3],
  Johnson_29_square_gyrobicupola_verts[4],
  Johnson_29_square_gyrobicupola_verts[5],
  Johnson_29_square_gyrobicupola_verts[6],
  Johnson_29_square_gyrobicupola_verts[7],
  Johnson_29_square_gyrobicupola_verts[8],
  Johnson_29_square_gyrobicupola_verts[9],
  Johnson_29_square_gyrobicupola_verts[10],
  Johnson_29_square_gyrobicupola_verts[11],
  Johnson_29_square_gyrobicupola_verts[12],
  Johnson_29_square_gyrobicupola_verts[13],
  Johnson_29_square_gyrobicupola_verts[14],
  Johnson_29_square_gyrobicupola_verts[15]
 }
 face_indices {
  28,
  <4, 0, 1>,
  <10, 6, 13>,
  <12, 15, 14>,
  <7, 8, 2>,
  <3, 0, 2>,
  <9, 8, 14>,
  <11, 15, 13>,
  <5, 6, 1>,
  <7, 4, 10>,
  <7, 10, 12>,
  <4, 7, 2>,
  <4, 2, 0>,
  <10, 4, 1>,
  <10, 1, 6>,
  <12, 10, 13>,
  <12, 13, 15>,
  <7, 12, 14>,
  <7, 14, 8>,
  <5, 3, 9>,
  <5, 9, 11>,
  <3, 5, 1>,
  <3, 1, 0>,
  <9, 3, 2>,
  <9, 2, 8>,
  <11, 9, 14>,
  <11, 14, 15>,
  <5, 11, 13>,
  <5, 13, 6>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_29_square_gyrobicupola_verts[7];
 #local P1 = Johnson_29_square_gyrobicupola_verts[4];
 #local P2 = Johnson_29_square_gyrobicupola_verts[12];
 #local P3 = Johnson_29_square_gyrobicupola_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_29_square_gyrobicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_29_square_gyrobicupola_obj }
#end
#end

#macro Johnson_29_square_gyrobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_29_square_gyrobicupola_verts[0], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[1], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[2], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[3], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[4], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[5], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[6], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[7], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[8], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[9], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[10], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[11], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[12], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[13], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[14], RadVer }
  sphere { Johnson_29_square_gyrobicupola_verts[15], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_29_square_gyrobicupola_verts[4], Johnson_29_square_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[0], Johnson_29_square_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[1], Johnson_29_square_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[10], Johnson_29_square_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[6], Johnson_29_square_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[13], Johnson_29_square_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[12], Johnson_29_square_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[15], Johnson_29_square_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[14], Johnson_29_square_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[7], Johnson_29_square_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[8], Johnson_29_square_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[2], Johnson_29_square_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[3], Johnson_29_square_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[0], Johnson_29_square_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[2], Johnson_29_square_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[9], Johnson_29_square_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[8], Johnson_29_square_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[14], Johnson_29_square_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[11], Johnson_29_square_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[15], Johnson_29_square_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[13], Johnson_29_square_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[5], Johnson_29_square_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[6], Johnson_29_square_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[1], Johnson_29_square_gyrobicupola_verts[5], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[7], Johnson_29_square_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[4], Johnson_29_square_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[10], Johnson_29_square_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[12], Johnson_29_square_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[5], Johnson_29_square_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[3], Johnson_29_square_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[9], Johnson_29_square_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_29_square_gyrobicupola_verts[11], Johnson_29_square_gyrobicupola_verts[5], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_29_square_gyrobicupola_verts[7];
 #local P1 = Johnson_29_square_gyrobicupola_verts[4];
 #local P2 = Johnson_29_square_gyrobicupola_verts[12];
 #local P3 = Johnson_29_square_gyrobicupola_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_30_pentagonal_orthobicupola_verts = array[20]
{
<-1.197125, -0.118752, -0.001762>,
<-1.038244, 0.607337, -0.020132>,
<-0.898745, -0.799482, 0.017282>,
<-0.619431, 0.145275, 0.384690>,
<-0.616250, 0.124807, -0.396793>,
<-0.482789, 1.101444, -0.030813>,
<-0.321051, -0.535454, 0.403734>,
<-0.317871, -0.555923, -0.377750>,
<-0.257075, -1.174837, 0.029724>,
<-0.063976, 0.639383, 0.374010>,
<-0.060795, 0.618915, -0.407474>,
<0.257076, 1.174837, -0.029725>,
<0.418813, -0.462061, 0.404823>,
<0.421993, -0.482530, -0.376661>,
<0.482789, -1.101444, 0.030813>,
<0.577694, 0.264028, 0.386452>,
<0.580875, 0.243560, -0.395032>,
<0.898745, 0.799482, -0.017282>,
<1.038244, -0.607337, 0.020132>,
<1.197125, 0.118752, 0.001761>,
}
#declare P0 = Johnson_30_pentagonal_orthobicupola_verts[3];
#declare P1 = Johnson_30_pentagonal_orthobicupola_verts[6];
#declare P2 = Johnson_30_pentagonal_orthobicupola_verts[12];
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
 #declare Johnson_30_pentagonal_orthobicupola_verts[Num] = vtransform(Johnson_30_pentagonal_orthobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_30_pentagonal_orthobicupola_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_30_pentagonal_orthobicupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_30_pentagonal_orthobicupola_verts[0],
  Johnson_30_pentagonal_orthobicupola_verts[1],
  Johnson_30_pentagonal_orthobicupola_verts[2],
  Johnson_30_pentagonal_orthobicupola_verts[3],
  Johnson_30_pentagonal_orthobicupola_verts[4],
  Johnson_30_pentagonal_orthobicupola_verts[5],
  Johnson_30_pentagonal_orthobicupola_verts[6],
  Johnson_30_pentagonal_orthobicupola_verts[7],
  Johnson_30_pentagonal_orthobicupola_verts[8],
  Johnson_30_pentagonal_orthobicupola_verts[9],
  Johnson_30_pentagonal_orthobicupola_verts[10],
  Johnson_30_pentagonal_orthobicupola_verts[11],
  Johnson_30_pentagonal_orthobicupola_verts[12],
  Johnson_30_pentagonal_orthobicupola_verts[13],
  Johnson_30_pentagonal_orthobicupola_verts[14],
  Johnson_30_pentagonal_orthobicupola_verts[15],
  Johnson_30_pentagonal_orthobicupola_verts[16],
  Johnson_30_pentagonal_orthobicupola_verts[17],
  Johnson_30_pentagonal_orthobicupola_verts[18],
  Johnson_30_pentagonal_orthobicupola_verts[19]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  36,
  <4, 0, 1>, 0,
  <10, 5, 11>, 0,
  <16, 17, 19>, 0,
  <13, 18, 14>, 0,
  <7, 8, 2>, 0,
  <6, 2, 8>, 0,
  <12, 14, 18>, 0,
  <15, 19, 17>, 0,
  <9, 11, 5>, 0,
  <3, 1, 0>, 0,
  <4, 7, 2>, 1,
  <4, 2, 0>, 1,
  <10, 4, 1>, 1,
  <10, 1, 5>, 1,
  <16, 10, 11>, 1,
  <16, 11, 17>, 1,
  <13, 16, 19>, 1,
  <13, 19, 18>, 1,
  <7, 13, 14>, 1,
  <7, 14, 8>, 1,
  <6, 3, 0>, 1,
  <6, 0, 2>, 1,
  <12, 6, 8>, 1,
  <12, 8, 14>, 1,
  <15, 12, 18>, 1,
  <15, 18, 19>, 1,
  <9, 15, 17>, 1,
  <9, 17, 11>, 1,
  <3, 9, 5>, 1,
  <3, 5, 1>, 1,
  <7, 4, 10>, 2,
  <7, 10, 16>, 2,
  <7, 16, 13>, 2,
  <3, 6, 12>, 2,
  <3, 12, 15>, 2,
  <3, 15, 9>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_30_pentagonal_orthobicupola_verts[3];
 #local P1 = Johnson_30_pentagonal_orthobicupola_verts[6];
 #local P2 = Johnson_30_pentagonal_orthobicupola_verts[12];
 #local P3 = Johnson_30_pentagonal_orthobicupola_verts[15];
 #local P4 = Johnson_30_pentagonal_orthobicupola_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_30_pentagonal_orthobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_30_pentagonal_orthobicupola_obj }
#end
#end

#macro Johnson_30_pentagonal_orthobicupola_faces2(OnPlane)
#local Johnson_30_pentagonal_orthobicupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_30_pentagonal_orthobicupola_verts[0],
  Johnson_30_pentagonal_orthobicupola_verts[1],
  Johnson_30_pentagonal_orthobicupola_verts[2],
  Johnson_30_pentagonal_orthobicupola_verts[3],
  Johnson_30_pentagonal_orthobicupola_verts[4],
  Johnson_30_pentagonal_orthobicupola_verts[5],
  Johnson_30_pentagonal_orthobicupola_verts[6],
  Johnson_30_pentagonal_orthobicupola_verts[7],
  Johnson_30_pentagonal_orthobicupola_verts[8],
  Johnson_30_pentagonal_orthobicupola_verts[9],
  Johnson_30_pentagonal_orthobicupola_verts[10],
  Johnson_30_pentagonal_orthobicupola_verts[11],
  Johnson_30_pentagonal_orthobicupola_verts[12],
  Johnson_30_pentagonal_orthobicupola_verts[13],
  Johnson_30_pentagonal_orthobicupola_verts[14],
  Johnson_30_pentagonal_orthobicupola_verts[15],
  Johnson_30_pentagonal_orthobicupola_verts[16],
  Johnson_30_pentagonal_orthobicupola_verts[17],
  Johnson_30_pentagonal_orthobicupola_verts[18],
  Johnson_30_pentagonal_orthobicupola_verts[19]
 }
 face_indices {
  36,
  <4, 0, 1>,
  <10, 5, 11>,
  <16, 17, 19>,
  <13, 18, 14>,
  <7, 8, 2>,
  <6, 2, 8>,
  <12, 14, 18>,
  <15, 19, 17>,
  <9, 11, 5>,
  <3, 1, 0>,
  <4, 7, 2>,
  <4, 2, 0>,
  <10, 4, 1>,
  <10, 1, 5>,
  <16, 10, 11>,
  <16, 11, 17>,
  <13, 16, 19>,
  <13, 19, 18>,
  <7, 13, 14>,
  <7, 14, 8>,
  <6, 3, 0>,
  <6, 0, 2>,
  <12, 6, 8>,
  <12, 8, 14>,
  <15, 12, 18>,
  <15, 18, 19>,
  <9, 15, 17>,
  <9, 17, 11>,
  <3, 9, 5>,
  <3, 5, 1>,
  <7, 4, 10>,
  <7, 10, 16>,
  <7, 16, 13>,
  <3, 6, 12>,
  <3, 12, 15>,
  <3, 15, 9>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_30_pentagonal_orthobicupola_verts[3];
 #local P1 = Johnson_30_pentagonal_orthobicupola_verts[6];
 #local P2 = Johnson_30_pentagonal_orthobicupola_verts[12];
 #local P3 = Johnson_30_pentagonal_orthobicupola_verts[15];
 #local P4 = Johnson_30_pentagonal_orthobicupola_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_30_pentagonal_orthobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_30_pentagonal_orthobicupola_obj }
#end
#end

#macro Johnson_30_pentagonal_orthobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_30_pentagonal_orthobicupola_verts[0], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[1], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[2], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[3], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[4], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[5], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[6], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[7], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[8], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[9], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[10], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[11], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[12], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[13], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[14], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[15], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[16], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[17], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[18], RadVer }
  sphere { Johnson_30_pentagonal_orthobicupola_verts[19], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[4], Johnson_30_pentagonal_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[0], Johnson_30_pentagonal_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[1], Johnson_30_pentagonal_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[10], Johnson_30_pentagonal_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[5], Johnson_30_pentagonal_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[11], Johnson_30_pentagonal_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[16], Johnson_30_pentagonal_orthobicupola_verts[17], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[17], Johnson_30_pentagonal_orthobicupola_verts[19], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[19], Johnson_30_pentagonal_orthobicupola_verts[16], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[13], Johnson_30_pentagonal_orthobicupola_verts[18], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[18], Johnson_30_pentagonal_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[14], Johnson_30_pentagonal_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[7], Johnson_30_pentagonal_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[8], Johnson_30_pentagonal_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[2], Johnson_30_pentagonal_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[6], Johnson_30_pentagonal_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[8], Johnson_30_pentagonal_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[12], Johnson_30_pentagonal_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[18], Johnson_30_pentagonal_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[15], Johnson_30_pentagonal_orthobicupola_verts[19], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[17], Johnson_30_pentagonal_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[9], Johnson_30_pentagonal_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[5], Johnson_30_pentagonal_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[3], Johnson_30_pentagonal_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[0], Johnson_30_pentagonal_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[4], Johnson_30_pentagonal_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[2], Johnson_30_pentagonal_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[10], Johnson_30_pentagonal_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[1], Johnson_30_pentagonal_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[16], Johnson_30_pentagonal_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[11], Johnson_30_pentagonal_orthobicupola_verts[17], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[13], Johnson_30_pentagonal_orthobicupola_verts[16], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[19], Johnson_30_pentagonal_orthobicupola_verts[18], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[7], Johnson_30_pentagonal_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[14], Johnson_30_pentagonal_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[6], Johnson_30_pentagonal_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[12], Johnson_30_pentagonal_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[15], Johnson_30_pentagonal_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[9], Johnson_30_pentagonal_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_30_pentagonal_orthobicupola_verts[3], Johnson_30_pentagonal_orthobicupola_verts[9], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_30_pentagonal_orthobicupola_verts[3];
 #local P1 = Johnson_30_pentagonal_orthobicupola_verts[6];
 #local P2 = Johnson_30_pentagonal_orthobicupola_verts[12];
 #local P3 = Johnson_30_pentagonal_orthobicupola_verts[15];
 #local P4 = Johnson_30_pentagonal_orthobicupola_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_31_pentagonal_gyrobicupola_verts = array[20]
{
<-1.142130, -0.353364, -0.133745>,
<-1.138435, 0.385484, -0.050817>,
<-0.709570, -0.957238, -0.165587>,
<-0.699897, 0.977090, 0.051522>,
<-0.598391, 0.052172, -0.438170>,
<-0.543739, -0.405536, 0.304426>,
<-0.540044, 0.333311, 0.387353>,
<-0.165831, -0.551702, -0.470012>,
<-0.159853, 0.643778, -0.335832>,
<-0.005978, -1.195480, -0.134180>,
<0.005978, 1.195481, 0.134181>,
<0.159852, -0.643778, 0.335832>,
<0.165831, 0.551702, 0.470012>,
<0.540044, -0.333311, -0.387353>,
<0.543739, 0.405536, -0.304425>,
<0.598391, -0.052172, 0.438170>,
<0.699896, -0.977090, -0.051521>,
<0.709570, 0.957238, 0.165587>,
<1.138435, -0.385484, 0.050817>,
<1.142129, 0.353364, 0.133745>,
}
#declare P0 = Johnson_31_pentagonal_gyrobicupola_verts[6];
#declare P1 = Johnson_31_pentagonal_gyrobicupola_verts[5];
#declare P2 = Johnson_31_pentagonal_gyrobicupola_verts[11];
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
 #declare Johnson_31_pentagonal_gyrobicupola_verts[Num] = vtransform(Johnson_31_pentagonal_gyrobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_31_pentagonal_gyrobicupola_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_31_pentagonal_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_31_pentagonal_gyrobicupola_verts[0],
  Johnson_31_pentagonal_gyrobicupola_verts[1],
  Johnson_31_pentagonal_gyrobicupola_verts[2],
  Johnson_31_pentagonal_gyrobicupola_verts[3],
  Johnson_31_pentagonal_gyrobicupola_verts[4],
  Johnson_31_pentagonal_gyrobicupola_verts[5],
  Johnson_31_pentagonal_gyrobicupola_verts[6],
  Johnson_31_pentagonal_gyrobicupola_verts[7],
  Johnson_31_pentagonal_gyrobicupola_verts[8],
  Johnson_31_pentagonal_gyrobicupola_verts[9],
  Johnson_31_pentagonal_gyrobicupola_verts[10],
  Johnson_31_pentagonal_gyrobicupola_verts[11],
  Johnson_31_pentagonal_gyrobicupola_verts[12],
  Johnson_31_pentagonal_gyrobicupola_verts[13],
  Johnson_31_pentagonal_gyrobicupola_verts[14],
  Johnson_31_pentagonal_gyrobicupola_verts[15],
  Johnson_31_pentagonal_gyrobicupola_verts[16],
  Johnson_31_pentagonal_gyrobicupola_verts[17],
  Johnson_31_pentagonal_gyrobicupola_verts[18],
  Johnson_31_pentagonal_gyrobicupola_verts[19]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  36,
  <4, 0, 1>, 0,
  <8, 3, 10>, 0,
  <14, 17, 19>, 0,
  <13, 18, 16>, 0,
  <7, 9, 2>, 0,
  <5, 0, 2>, 0,
  <11, 9, 16>, 0,
  <15, 18, 19>, 0,
  <12, 17, 10>, 0,
  <6, 3, 1>, 0,
  <4, 7, 2>, 1,
  <4, 2, 0>, 1,
  <8, 4, 1>, 1,
  <8, 1, 3>, 1,
  <14, 8, 10>, 1,
  <14, 10, 17>, 1,
  <13, 14, 19>, 1,
  <13, 19, 18>, 1,
  <7, 13, 16>, 1,
  <7, 16, 9>, 1,
  <5, 6, 1>, 1,
  <5, 1, 0>, 1,
  <11, 5, 2>, 1,
  <11, 2, 9>, 1,
  <15, 11, 16>, 1,
  <15, 16, 18>, 1,
  <12, 15, 19>, 1,
  <12, 19, 17>, 1,
  <6, 12, 10>, 1,
  <6, 10, 3>, 1,
  <7, 4, 8>, 2,
  <7, 8, 14>, 2,
  <7, 14, 13>, 2,
  <6, 5, 11>, 2,
  <6, 11, 15>, 2,
  <6, 15, 12>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_31_pentagonal_gyrobicupola_verts[6];
 #local P1 = Johnson_31_pentagonal_gyrobicupola_verts[5];
 #local P2 = Johnson_31_pentagonal_gyrobicupola_verts[11];
 #local P3 = Johnson_31_pentagonal_gyrobicupola_verts[15];
 #local P4 = Johnson_31_pentagonal_gyrobicupola_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_31_pentagonal_gyrobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_31_pentagonal_gyrobicupola_obj }
#end
#end

#macro Johnson_31_pentagonal_gyrobicupola_faces2(OnPlane)
#local Johnson_31_pentagonal_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  20,
  Johnson_31_pentagonal_gyrobicupola_verts[0],
  Johnson_31_pentagonal_gyrobicupola_verts[1],
  Johnson_31_pentagonal_gyrobicupola_verts[2],
  Johnson_31_pentagonal_gyrobicupola_verts[3],
  Johnson_31_pentagonal_gyrobicupola_verts[4],
  Johnson_31_pentagonal_gyrobicupola_verts[5],
  Johnson_31_pentagonal_gyrobicupola_verts[6],
  Johnson_31_pentagonal_gyrobicupola_verts[7],
  Johnson_31_pentagonal_gyrobicupola_verts[8],
  Johnson_31_pentagonal_gyrobicupola_verts[9],
  Johnson_31_pentagonal_gyrobicupola_verts[10],
  Johnson_31_pentagonal_gyrobicupola_verts[11],
  Johnson_31_pentagonal_gyrobicupola_verts[12],
  Johnson_31_pentagonal_gyrobicupola_verts[13],
  Johnson_31_pentagonal_gyrobicupola_verts[14],
  Johnson_31_pentagonal_gyrobicupola_verts[15],
  Johnson_31_pentagonal_gyrobicupola_verts[16],
  Johnson_31_pentagonal_gyrobicupola_verts[17],
  Johnson_31_pentagonal_gyrobicupola_verts[18],
  Johnson_31_pentagonal_gyrobicupola_verts[19]
 }
 face_indices {
  36,
  <4, 0, 1>,
  <8, 3, 10>,
  <14, 17, 19>,
  <13, 18, 16>,
  <7, 9, 2>,
  <5, 0, 2>,
  <11, 9, 16>,
  <15, 18, 19>,
  <12, 17, 10>,
  <6, 3, 1>,
  <4, 7, 2>,
  <4, 2, 0>,
  <8, 4, 1>,
  <8, 1, 3>,
  <14, 8, 10>,
  <14, 10, 17>,
  <13, 14, 19>,
  <13, 19, 18>,
  <7, 13, 16>,
  <7, 16, 9>,
  <5, 6, 1>,
  <5, 1, 0>,
  <11, 5, 2>,
  <11, 2, 9>,
  <15, 11, 16>,
  <15, 16, 18>,
  <12, 15, 19>,
  <12, 19, 17>,
  <6, 12, 10>,
  <6, 10, 3>,
  <7, 4, 8>,
  <7, 8, 14>,
  <7, 14, 13>,
  <6, 5, 11>,
  <6, 11, 15>,
  <6, 15, 12>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_31_pentagonal_gyrobicupola_verts[6];
 #local P1 = Johnson_31_pentagonal_gyrobicupola_verts[5];
 #local P2 = Johnson_31_pentagonal_gyrobicupola_verts[11];
 #local P3 = Johnson_31_pentagonal_gyrobicupola_verts[15];
 #local P4 = Johnson_31_pentagonal_gyrobicupola_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_31_pentagonal_gyrobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_31_pentagonal_gyrobicupola_obj }
#end
#end

#macro Johnson_31_pentagonal_gyrobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[0], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[1], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[2], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[3], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[4], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[5], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[6], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[7], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[8], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[9], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[10], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[11], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[12], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[13], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[14], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[15], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[16], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[17], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[18], RadVer }
  sphere { Johnson_31_pentagonal_gyrobicupola_verts[19], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[4], Johnson_31_pentagonal_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[0], Johnson_31_pentagonal_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[1], Johnson_31_pentagonal_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[8], Johnson_31_pentagonal_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[3], Johnson_31_pentagonal_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[10], Johnson_31_pentagonal_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[14], Johnson_31_pentagonal_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[17], Johnson_31_pentagonal_gyrobicupola_verts[19], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[19], Johnson_31_pentagonal_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[13], Johnson_31_pentagonal_gyrobicupola_verts[18], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[18], Johnson_31_pentagonal_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[16], Johnson_31_pentagonal_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[7], Johnson_31_pentagonal_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[9], Johnson_31_pentagonal_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[2], Johnson_31_pentagonal_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[5], Johnson_31_pentagonal_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[0], Johnson_31_pentagonal_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[2], Johnson_31_pentagonal_gyrobicupola_verts[5], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[11], Johnson_31_pentagonal_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[9], Johnson_31_pentagonal_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[16], Johnson_31_pentagonal_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[15], Johnson_31_pentagonal_gyrobicupola_verts[18], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[18], Johnson_31_pentagonal_gyrobicupola_verts[19], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[19], Johnson_31_pentagonal_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[12], Johnson_31_pentagonal_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[17], Johnson_31_pentagonal_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[10], Johnson_31_pentagonal_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[6], Johnson_31_pentagonal_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[3], Johnson_31_pentagonal_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[1], Johnson_31_pentagonal_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[4], Johnson_31_pentagonal_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[8], Johnson_31_pentagonal_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[14], Johnson_31_pentagonal_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[13], Johnson_31_pentagonal_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[7], Johnson_31_pentagonal_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[5], Johnson_31_pentagonal_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[11], Johnson_31_pentagonal_gyrobicupola_verts[5], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[15], Johnson_31_pentagonal_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[12], Johnson_31_pentagonal_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_31_pentagonal_gyrobicupola_verts[6], Johnson_31_pentagonal_gyrobicupola_verts[12], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_31_pentagonal_gyrobicupola_verts[6];
 #local P1 = Johnson_31_pentagonal_gyrobicupola_verts[5];
 #local P2 = Johnson_31_pentagonal_gyrobicupola_verts[11];
 #local P3 = Johnson_31_pentagonal_gyrobicupola_verts[15];
 #local P4 = Johnson_31_pentagonal_gyrobicupola_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_32_pentagonal_orthocupolarotunda_verts = array[25]
{
<-1.086754, 0.270723, -0.022210>,
<-0.951485, 0.016307, 0.590957>,
<-0.844123, 0.345447, -0.650340>,
<-0.727726, -0.227595, -0.308179>,
<-0.678317, 0.606577, 0.401324>,
<-0.592457, -0.482012, 0.304989>,
<-0.489983, -0.320625, 0.954953>,
<-0.316268, 0.211936, -1.053507>,
<-0.285732, 0.727482, -0.615010>,
<-0.199871, -0.361106, -0.711346>,
<-0.183258, 0.888869, 0.034954>,
<-0.047989, 0.634452, 0.648121>,
<0.019000, -0.772761, 0.280780>,
<0.068408, 0.061410, 0.990283>,
<0.121473, -0.611374, 0.930744>,
<0.261631, -0.698037, -0.347350>,
<0.295188, -0.078813, -1.077716>,
<0.344597, 0.755358, -0.368213>,
<0.563468, 0.343703, 0.623912>,
<0.649328, -0.744886, 0.527576>,
<0.703625, 0.257040, -0.654181>,
<0.756690, -0.415745, -0.713720>,
<0.806099, 0.418427, -0.004217>,
<0.891959, -0.670162, -0.100552>
<0.922496, -0.154616, 0.337944>,
}
#declare P0 = Johnson_32_pentagonal_orthocupolarotunda_verts[3];
#declare P1 = Johnson_32_pentagonal_orthocupolarotunda_verts[9];
#declare P2 = Johnson_32_pentagonal_orthocupolarotunda_verts[15];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 25)
 #declare Johnson_32_pentagonal_orthocupolarotunda_verts[Num] = vtransform(Johnson_32_pentagonal_orthocupolarotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_32_pentagonal_orthocupolarotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_32_pentagonal_orthocupolarotunda_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_32_pentagonal_orthocupolarotunda_verts[0],
  Johnson_32_pentagonal_orthocupolarotunda_verts[1],
  Johnson_32_pentagonal_orthocupolarotunda_verts[2],
  Johnson_32_pentagonal_orthocupolarotunda_verts[3],
  Johnson_32_pentagonal_orthocupolarotunda_verts[4],
  Johnson_32_pentagonal_orthocupolarotunda_verts[5],
  Johnson_32_pentagonal_orthocupolarotunda_verts[6],
  Johnson_32_pentagonal_orthocupolarotunda_verts[7],
  Johnson_32_pentagonal_orthocupolarotunda_verts[8],
  Johnson_32_pentagonal_orthocupolarotunda_verts[9],
  Johnson_32_pentagonal_orthocupolarotunda_verts[10],
  Johnson_32_pentagonal_orthocupolarotunda_verts[11],
  Johnson_32_pentagonal_orthocupolarotunda_verts[12],
  Johnson_32_pentagonal_orthocupolarotunda_verts[13],
  Johnson_32_pentagonal_orthocupolarotunda_verts[14],
  Johnson_32_pentagonal_orthocupolarotunda_verts[15],
  Johnson_32_pentagonal_orthocupolarotunda_verts[16],
  Johnson_32_pentagonal_orthocupolarotunda_verts[17],
  Johnson_32_pentagonal_orthocupolarotunda_verts[18],
  Johnson_32_pentagonal_orthocupolarotunda_verts[19],
  Johnson_32_pentagonal_orthocupolarotunda_verts[20],
  Johnson_32_pentagonal_orthocupolarotunda_verts[21],
  Johnson_32_pentagonal_orthocupolarotunda_verts[22],
  Johnson_32_pentagonal_orthocupolarotunda_verts[23],
  Johnson_32_pentagonal_orthocupolarotunda_verts[24]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  46,
  <3, 0, 2>, 0,
  <9, 7, 16>, 0,
  <15, 21, 23>, 0,
  <12, 19, 14>, 0,
  <5, 6, 1>, 0,
  <18, 24, 22>, 0,
  <24, 19, 23>, 0,
  <22, 20, 17>, 0,
  <20, 21, 16>, 0,
  <17, 8, 10>, 0,
  <8, 7, 2>, 0,
  <10, 4, 11>, 0,
  <4, 0, 1>, 0,
  <11, 13, 18>, 0,
  <13, 6, 14>, 0,
  <3, 5, 1>, 1,
  <3, 1, 0>, 1,
  <9, 3, 2>, 1,
  <9, 2, 7>, 1,
  <15, 9, 16>, 1,
  <15, 16, 21>, 1,
  <12, 15, 23>, 1,
  <12, 23, 19>, 1,
  <5, 12, 14>, 1,
  <5, 14, 6>, 1,
  <5, 3, 9>, 2,
  <5, 9, 15>, 2,
  <5, 15, 12>, 2,
  <18, 22, 17>, 2,
  <18, 17, 10>, 2,
  <18, 10, 11>, 2,
  <18, 13, 14>, 2,
  <18, 14, 19>, 2,
  <18, 19, 24>, 2,
  <22, 24, 23>, 2,
  <22, 23, 21>, 2,
  <22, 21, 20>, 2,
  <17, 20, 16>, 2,
  <17, 16, 7>, 2,
  <17, 7, 8>, 2,
  <10, 8, 2>, 2,
  <10, 2, 0>, 2,
  <10, 0, 4>, 2,
  <11, 4, 1>, 2,
  <11, 1, 6>, 2,
  <11, 6, 13>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_32_pentagonal_orthocupolarotunda_verts[15];
 #local P1 = Johnson_32_pentagonal_orthocupolarotunda_verts[3];
 #local P2 = Johnson_32_pentagonal_orthocupolarotunda_verts[9];
 #local P3 = Johnson_32_pentagonal_orthocupolarotunda_verts[5];
 #local P4 = Johnson_32_pentagonal_orthocupolarotunda_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_32_pentagonal_orthocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_32_pentagonal_orthocupolarotunda_obj }
#end
#end

#macro Johnson_32_pentagonal_orthocupolarotunda_faces2(OnPlane)
#local Johnson_32_pentagonal_orthocupolarotunda_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_32_pentagonal_orthocupolarotunda_verts[0],
  Johnson_32_pentagonal_orthocupolarotunda_verts[1],
  Johnson_32_pentagonal_orthocupolarotunda_verts[2],
  Johnson_32_pentagonal_orthocupolarotunda_verts[3],
  Johnson_32_pentagonal_orthocupolarotunda_verts[4],
  Johnson_32_pentagonal_orthocupolarotunda_verts[5],
  Johnson_32_pentagonal_orthocupolarotunda_verts[6],
  Johnson_32_pentagonal_orthocupolarotunda_verts[7],
  Johnson_32_pentagonal_orthocupolarotunda_verts[8],
  Johnson_32_pentagonal_orthocupolarotunda_verts[9],
  Johnson_32_pentagonal_orthocupolarotunda_verts[10],
  Johnson_32_pentagonal_orthocupolarotunda_verts[11],
  Johnson_32_pentagonal_orthocupolarotunda_verts[12],
  Johnson_32_pentagonal_orthocupolarotunda_verts[13],
  Johnson_32_pentagonal_orthocupolarotunda_verts[14],
  Johnson_32_pentagonal_orthocupolarotunda_verts[15],
  Johnson_32_pentagonal_orthocupolarotunda_verts[16],
  Johnson_32_pentagonal_orthocupolarotunda_verts[17],
  Johnson_32_pentagonal_orthocupolarotunda_verts[18],
  Johnson_32_pentagonal_orthocupolarotunda_verts[19],
  Johnson_32_pentagonal_orthocupolarotunda_verts[20],
  Johnson_32_pentagonal_orthocupolarotunda_verts[21],
  Johnson_32_pentagonal_orthocupolarotunda_verts[22],
  Johnson_32_pentagonal_orthocupolarotunda_verts[23],
  Johnson_32_pentagonal_orthocupolarotunda_verts[24]
 }
 face_indices {
  46,
  <3, 0, 2>,
  <9, 7, 16>,
  <15, 21, 23>,
  <12, 19, 14>,
  <5, 6, 1>,
  <18, 24, 22>,
  <24, 19, 23>,
  <22, 20, 17>,
  <20, 21, 16>,
  <17, 8, 10>,
  <8, 7, 2>,
  <10, 4, 11>,
  <4, 0, 1>,
  <11, 13, 18>,
  <13, 6, 14>,
  <3, 5, 1>,
  <3, 1, 0>,
  <9, 3, 2>,
  <9, 2, 7>,
  <15, 9, 16>,
  <15, 16, 21>,
  <12, 15, 23>,
  <12, 23, 19>,
  <5, 12, 14>,
  <5, 14, 6>,
  <5, 3, 9>,
  <5, 9, 15>,
  <5, 15, 12>,
  <18, 22, 17>,
  <18, 17, 10>,
  <18, 10, 11>,
  <18, 13, 14>,
  <18, 14, 19>,
  <18, 19, 24>,
  <22, 24, 23>,
  <22, 23, 21>,
  <22, 21, 20>,
  <17, 20, 16>,
  <17, 16, 7>,
  <17, 7, 8>,
  <10, 8, 2>,
  <10, 2, 0>,
  <10, 0, 4>,
  <11, 4, 1>,
  <11, 1, 6>,
  <11, 6, 13>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_32_pentagonal_orthocupolarotunda_verts[15];
 #local P1 = Johnson_32_pentagonal_orthocupolarotunda_verts[3];
 #local P2 = Johnson_32_pentagonal_orthocupolarotunda_verts[9];
 #local P3 = Johnson_32_pentagonal_orthocupolarotunda_verts[5];
 #local P4 = Johnson_32_pentagonal_orthocupolarotunda_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_32_pentagonal_orthocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_32_pentagonal_orthocupolarotunda_obj }
#end
#end

#macro Johnson_32_pentagonal_orthocupolarotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[0], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[1], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[2], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[3], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[4], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[5], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[6], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[7], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[8], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[9], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[10], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[11], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[12], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[13], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[14], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[15], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[16], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[17], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[18], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[19], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[20], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[21], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[22], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[23], RadVer }
  sphere { Johnson_32_pentagonal_orthocupolarotunda_verts[24], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[3], Johnson_32_pentagonal_orthocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[0], Johnson_32_pentagonal_orthocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[2], Johnson_32_pentagonal_orthocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[9], Johnson_32_pentagonal_orthocupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[7], Johnson_32_pentagonal_orthocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[16], Johnson_32_pentagonal_orthocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[15], Johnson_32_pentagonal_orthocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[21], Johnson_32_pentagonal_orthocupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[23], Johnson_32_pentagonal_orthocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[12], Johnson_32_pentagonal_orthocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[19], Johnson_32_pentagonal_orthocupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[14], Johnson_32_pentagonal_orthocupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[5], Johnson_32_pentagonal_orthocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[6], Johnson_32_pentagonal_orthocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[1], Johnson_32_pentagonal_orthocupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[18], Johnson_32_pentagonal_orthocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[24], Johnson_32_pentagonal_orthocupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[22], Johnson_32_pentagonal_orthocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[24], Johnson_32_pentagonal_orthocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[19], Johnson_32_pentagonal_orthocupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[23], Johnson_32_pentagonal_orthocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[22], Johnson_32_pentagonal_orthocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[20], Johnson_32_pentagonal_orthocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[17], Johnson_32_pentagonal_orthocupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[20], Johnson_32_pentagonal_orthocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[21], Johnson_32_pentagonal_orthocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[16], Johnson_32_pentagonal_orthocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[17], Johnson_32_pentagonal_orthocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[8], Johnson_32_pentagonal_orthocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[10], Johnson_32_pentagonal_orthocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[8], Johnson_32_pentagonal_orthocupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[7], Johnson_32_pentagonal_orthocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[2], Johnson_32_pentagonal_orthocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[10], Johnson_32_pentagonal_orthocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[4], Johnson_32_pentagonal_orthocupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[11], Johnson_32_pentagonal_orthocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[4], Johnson_32_pentagonal_orthocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[0], Johnson_32_pentagonal_orthocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[1], Johnson_32_pentagonal_orthocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[11], Johnson_32_pentagonal_orthocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[13], Johnson_32_pentagonal_orthocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[18], Johnson_32_pentagonal_orthocupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[13], Johnson_32_pentagonal_orthocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[6], Johnson_32_pentagonal_orthocupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[14], Johnson_32_pentagonal_orthocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[3], Johnson_32_pentagonal_orthocupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[9], Johnson_32_pentagonal_orthocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[15], Johnson_32_pentagonal_orthocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[12], Johnson_32_pentagonal_orthocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_32_pentagonal_orthocupolarotunda_verts[5], Johnson_32_pentagonal_orthocupolarotunda_verts[12], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_32_pentagonal_orthocupolarotunda_verts[15];
 #local P1 = Johnson_32_pentagonal_orthocupolarotunda_verts[3];
 #local P2 = Johnson_32_pentagonal_orthocupolarotunda_verts[9];
 #local P3 = Johnson_32_pentagonal_orthocupolarotunda_verts[5];
 #local P4 = Johnson_32_pentagonal_orthocupolarotunda_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_33_pentagonal_gyrocupolarotunda_verts = array[25]
{
<-0.799512, 0.192706, 0.001565>,
<-0.776446, 0.593934, 0.546986>,
<-0.713384, 0.860598, -0.072621>,
<-0.640335, -0.340950, 0.387405>,
<-0.617268, 0.060277, 0.932827>,
<-0.538299, 0.090521, -0.615141>,
<-0.452171, 0.758412, -0.689327>,
<-0.296652, -0.536533, 0.937522>,
<-0.280744, -0.772953, 0.009162>,
<-0.217683, -0.506289, -0.610445>,
<-0.200278, 0.902051, 0.367837>,
<-0.092580, 0.326409, -1.067570>,
<0.057277, 0.038576, 0.992140>,
<0.062939, -0.968537, 0.559279>,
<0.222374, 0.736712, -0.630014>,
<0.228036, -0.270402, -1.062874>,
<0.314991, 0.558821, 0.642957>,
<0.324152, -1.070722, -0.057426>,
<0.378052, 0.825485, 0.023349>,
<0.387214, -0.804058, -0.677033>,
<0.635607, -0.037989, 0.647653>,
<0.639107, -0.660420, 0.380130>,
<0.737643, 0.393482, -0.354893>,
<0.741142, -0.228948, -0.622416>
<0.896820, -0.140175, 0.030947>,
}
#declare P0 = Johnson_33_pentagonal_gyrocupolarotunda_verts[5];
#declare P1 = Johnson_33_pentagonal_gyrocupolarotunda_verts[9];
#declare P2 = Johnson_33_pentagonal_gyrocupolarotunda_verts[8];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 25)
 #declare Johnson_33_pentagonal_gyrocupolarotunda_verts[Num] = vtransform(Johnson_33_pentagonal_gyrocupolarotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_33_pentagonal_gyrocupolarotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_33_pentagonal_gyrocupolarotunda_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_33_pentagonal_gyrocupolarotunda_verts[0],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[1],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[2],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[3],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[4],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[5],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[6],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[7],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[8],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[9],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[10],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[11],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[12],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[13],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[14],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[15],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[16],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[17],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[18],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[19],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[20],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[21],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[22],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[23],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[24]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  46,
  <5, 6, 11>, 0,
  <9, 15, 19>, 0,
  <8, 17, 13>, 0,
  <3, 7, 4>, 0,
  <0, 1, 2>, 0,
  <20, 21, 24>, 0,
  <21, 13, 17>, 0,
  <24, 23, 22>, 0,
  <23, 19, 15>, 0,
  <22, 14, 18>, 0,
  <14, 11, 6>, 0,
  <18, 10, 16>, 0,
  <10, 2, 1>, 0,
  <16, 12, 20>, 0,
  <12, 4, 7>, 0,
  <5, 0, 2>, 1,
  <5, 2, 6>, 1,
  <9, 5, 11>, 1,
  <9, 11, 15>, 1,
  <8, 9, 19>, 1,
  <8, 19, 17>, 1,
  <3, 8, 13>, 1,
  <3, 13, 7>, 1,
  <0, 3, 4>, 1,
  <0, 4, 1>, 1,
  <0, 5, 9>, 2,
  <0, 9, 8>, 2,
  <0, 8, 3>, 2,
  <20, 24, 22>, 2,
  <20, 22, 18>, 2,
  <20, 18, 16>, 2,
  <20, 12, 7>, 2,
  <20, 7, 13>, 2,
  <20, 13, 21>, 2,
  <24, 21, 17>, 2,
  <24, 17, 19>, 2,
  <24, 19, 23>, 2,
  <22, 23, 15>, 2,
  <22, 15, 11>, 2,
  <22, 11, 14>, 2,
  <18, 14, 6>, 2,
  <18, 6, 2>, 2,
  <18, 2, 10>, 2,
  <16, 10, 1>, 2,
  <16, 1, 4>, 2,
  <16, 4, 12>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_33_pentagonal_gyrocupolarotunda_verts[5];
 #local P1 = Johnson_33_pentagonal_gyrocupolarotunda_verts[9];
 #local P2 = Johnson_33_pentagonal_gyrocupolarotunda_verts[8];
 #local P3 = Johnson_33_pentagonal_gyrocupolarotunda_verts[0];
 #local P4 = Johnson_33_pentagonal_gyrocupolarotunda_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_33_pentagonal_gyrocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_33_pentagonal_gyrocupolarotunda_obj }
#end
#end

#macro Johnson_33_pentagonal_gyrocupolarotunda_faces2(OnPlane)
#local Johnson_33_pentagonal_gyrocupolarotunda_obj = mesh2 {
 vertex_vectors {
  25,
  Johnson_33_pentagonal_gyrocupolarotunda_verts[0],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[1],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[2],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[3],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[4],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[5],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[6],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[7],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[8],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[9],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[10],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[11],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[12],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[13],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[14],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[15],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[16],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[17],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[18],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[19],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[20],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[21],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[22],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[23],
  Johnson_33_pentagonal_gyrocupolarotunda_verts[24]
 }
 face_indices {
  46,
  <5, 6, 11>,
  <9, 15, 19>,
  <8, 17, 13>,
  <3, 7, 4>,
  <0, 1, 2>,
  <20, 21, 24>,
  <21, 13, 17>,
  <24, 23, 22>,
  <23, 19, 15>,
  <22, 14, 18>,
  <14, 11, 6>,
  <18, 10, 16>,
  <10, 2, 1>,
  <16, 12, 20>,
  <12, 4, 7>,
  <5, 0, 2>,
  <5, 2, 6>,
  <9, 5, 11>,
  <9, 11, 15>,
  <8, 9, 19>,
  <8, 19, 17>,
  <3, 8, 13>,
  <3, 13, 7>,
  <0, 3, 4>,
  <0, 4, 1>,
  <0, 5, 9>,
  <0, 9, 8>,
  <0, 8, 3>,
  <20, 24, 22>,
  <20, 22, 18>,
  <20, 18, 16>,
  <20, 12, 7>,
  <20, 7, 13>,
  <20, 13, 21>,
  <24, 21, 17>,
  <24, 17, 19>,
  <24, 19, 23>,
  <22, 23, 15>,
  <22, 15, 11>,
  <22, 11, 14>,
  <18, 14, 6>,
  <18, 6, 2>,
  <18, 2, 10>,
  <16, 10, 1>,
  <16, 1, 4>,
  <16, 4, 12>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_33_pentagonal_gyrocupolarotunda_verts[5];
 #local P1 = Johnson_33_pentagonal_gyrocupolarotunda_verts[9];
 #local P2 = Johnson_33_pentagonal_gyrocupolarotunda_verts[8];
 #local P3 = Johnson_33_pentagonal_gyrocupolarotunda_verts[0];
 #local P4 = Johnson_33_pentagonal_gyrocupolarotunda_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_33_pentagonal_gyrocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_33_pentagonal_gyrocupolarotunda_obj }
#end
#end

#macro Johnson_33_pentagonal_gyrocupolarotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[0], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[1], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[2], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[3], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[4], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[5], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[6], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[7], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[8], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[9], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[10], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[11], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[12], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[13], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[14], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[15], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[16], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[17], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[18], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[19], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[20], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[21], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[22], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[23], RadVer }
  sphere { Johnson_33_pentagonal_gyrocupolarotunda_verts[24], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[5], Johnson_33_pentagonal_gyrocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[6], Johnson_33_pentagonal_gyrocupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[11], Johnson_33_pentagonal_gyrocupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[9], Johnson_33_pentagonal_gyrocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[15], Johnson_33_pentagonal_gyrocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[19], Johnson_33_pentagonal_gyrocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[8], Johnson_33_pentagonal_gyrocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[17], Johnson_33_pentagonal_gyrocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[13], Johnson_33_pentagonal_gyrocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[3], Johnson_33_pentagonal_gyrocupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[7], Johnson_33_pentagonal_gyrocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[4], Johnson_33_pentagonal_gyrocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[0], Johnson_33_pentagonal_gyrocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[1], Johnson_33_pentagonal_gyrocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[2], Johnson_33_pentagonal_gyrocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[20], Johnson_33_pentagonal_gyrocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[21], Johnson_33_pentagonal_gyrocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[24], Johnson_33_pentagonal_gyrocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[21], Johnson_33_pentagonal_gyrocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[17], Johnson_33_pentagonal_gyrocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[24], Johnson_33_pentagonal_gyrocupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[23], Johnson_33_pentagonal_gyrocupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[22], Johnson_33_pentagonal_gyrocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[23], Johnson_33_pentagonal_gyrocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[15], Johnson_33_pentagonal_gyrocupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[22], Johnson_33_pentagonal_gyrocupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[14], Johnson_33_pentagonal_gyrocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[18], Johnson_33_pentagonal_gyrocupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[14], Johnson_33_pentagonal_gyrocupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[6], Johnson_33_pentagonal_gyrocupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[18], Johnson_33_pentagonal_gyrocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[10], Johnson_33_pentagonal_gyrocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[16], Johnson_33_pentagonal_gyrocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[10], Johnson_33_pentagonal_gyrocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[1], Johnson_33_pentagonal_gyrocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[16], Johnson_33_pentagonal_gyrocupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[12], Johnson_33_pentagonal_gyrocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[20], Johnson_33_pentagonal_gyrocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[12], Johnson_33_pentagonal_gyrocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[7], Johnson_33_pentagonal_gyrocupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[5], Johnson_33_pentagonal_gyrocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[2], Johnson_33_pentagonal_gyrocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[9], Johnson_33_pentagonal_gyrocupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[11], Johnson_33_pentagonal_gyrocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[8], Johnson_33_pentagonal_gyrocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[19], Johnson_33_pentagonal_gyrocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[3], Johnson_33_pentagonal_gyrocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[13], Johnson_33_pentagonal_gyrocupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[0], Johnson_33_pentagonal_gyrocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_33_pentagonal_gyrocupolarotunda_verts[4], Johnson_33_pentagonal_gyrocupolarotunda_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_33_pentagonal_gyrocupolarotunda_verts[5];
 #local P1 = Johnson_33_pentagonal_gyrocupolarotunda_verts[9];
 #local P2 = Johnson_33_pentagonal_gyrocupolarotunda_verts[8];
 #local P3 = Johnson_33_pentagonal_gyrocupolarotunda_verts[0];
 #local P4 = Johnson_33_pentagonal_gyrocupolarotunda_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_34_pentagonal_orthobirotunda_verts = array[30]
{
<-0.976027, 0.021192, 0.216616>,
<-0.898600, -0.336852, -0.281155>,
<-0.800821, 0.595002, 0.068255>,
<-0.778424, -0.560713, 0.282236>,
<-0.680644, 0.371141, 0.631647>,
<-0.675542, 0.015675, -0.737155>,
<-0.615111, 0.591592, -0.521207>,
<-0.523949, -0.823998, -0.215648>,
<-0.360916, -0.570400, 0.737823>,
<-0.319728, 0.941541, -0.106177>,
<-0.300485, 0.005517, 0.953771>,
<-0.194450, 0.362214, -0.911587>,
<-0.163033, -0.253598, -0.953472>,
<-0.125279, 0.579327, 0.805410>,
<-0.069344, -0.772544, -0.631163>,
<0.050833, -0.996405, -0.067772>,
<0.097779, 0.931854, 0.349410>,
<0.151593, -0.839673, 0.521506>,
<0.194449, -0.362214, 0.911587>,
<0.283489, 0.928444, -0.240052>,
<0.360916, 0.570400, -0.737823>,
<0.411749, -0.426005, -0.805595>,
<0.477939, 0.566230, 0.671534>,
<0.606198, -0.788219, 0.105992>
<0.675542, -0.015675, 0.737155>,
<0.735567, 0.083254, -0.672317>,
<0.778423, 0.560713, -0.282236>,
<0.829257, -0.435692, -0.350008>,
<0.898600, 0.336852, 0.281155>,
<0.930017, -0.278960, 0.239270>,
}
#declare P0 = Johnson_34_pentagonal_orthobirotunda_verts[13];
#declare P1 = Johnson_34_pentagonal_orthobirotunda_verts[16];
#declare P2 = Johnson_34_pentagonal_orthobirotunda_verts[9];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 30)
 #declare Johnson_34_pentagonal_orthobirotunda_verts[Num] = vtransform(Johnson_34_pentagonal_orthobirotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_34_pentagonal_orthobirotunda_faces(Tex3, Tex5, OnPlane)
#local Johnson_34_pentagonal_orthobirotunda_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_34_pentagonal_orthobirotunda_verts[0],
  Johnson_34_pentagonal_orthobirotunda_verts[1],
  Johnson_34_pentagonal_orthobirotunda_verts[2],
  Johnson_34_pentagonal_orthobirotunda_verts[3],
  Johnson_34_pentagonal_orthobirotunda_verts[4],
  Johnson_34_pentagonal_orthobirotunda_verts[5],
  Johnson_34_pentagonal_orthobirotunda_verts[6],
  Johnson_34_pentagonal_orthobirotunda_verts[7],
  Johnson_34_pentagonal_orthobirotunda_verts[8],
  Johnson_34_pentagonal_orthobirotunda_verts[9],
  Johnson_34_pentagonal_orthobirotunda_verts[10],
  Johnson_34_pentagonal_orthobirotunda_verts[11],
  Johnson_34_pentagonal_orthobirotunda_verts[12],
  Johnson_34_pentagonal_orthobirotunda_verts[13],
  Johnson_34_pentagonal_orthobirotunda_verts[14],
  Johnson_34_pentagonal_orthobirotunda_verts[15],
  Johnson_34_pentagonal_orthobirotunda_verts[16],
  Johnson_34_pentagonal_orthobirotunda_verts[17],
  Johnson_34_pentagonal_orthobirotunda_verts[18],
  Johnson_34_pentagonal_orthobirotunda_verts[19],
  Johnson_34_pentagonal_orthobirotunda_verts[20],
  Johnson_34_pentagonal_orthobirotunda_verts[21],
  Johnson_34_pentagonal_orthobirotunda_verts[22],
  Johnson_34_pentagonal_orthobirotunda_verts[23],
  Johnson_34_pentagonal_orthobirotunda_verts[24],
  Johnson_34_pentagonal_orthobirotunda_verts[25],
  Johnson_34_pentagonal_orthobirotunda_verts[26],
  Johnson_34_pentagonal_orthobirotunda_verts[27],
  Johnson_34_pentagonal_orthobirotunda_verts[28],
  Johnson_34_pentagonal_orthobirotunda_verts[29]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  56,
  <15, 7, 14>, 0,
  <7, 3, 1>, 0,
  <14, 12, 21>, 0,
  <12, 5, 11>, 0,
  <21, 25, 27>, 0,
  <25, 20, 26>, 0,
  <27, 29, 23>, 0,
  <29, 28, 24>, 0,
  <23, 17, 15>, 0,
  <17, 18, 8>, 0,
  <4, 10, 13>, 0,
  <10, 8, 18>, 0,
  <13, 22, 16>, 0,
  <22, 24, 28>, 0,
  <16, 19, 9>, 0,
  <19, 26, 20>, 0,
  <9, 6, 2>, 0,
  <6, 11, 5>, 0,
  <2, 0, 4>, 0,
  <0, 1, 3>, 0,
  <15, 14, 21>, 1,
  <15, 21, 27>, 1,
  <15, 27, 23>, 1,
  <15, 17, 8>, 1,
  <15, 8, 3>, 1,
  <15, 3, 7>, 1,
  <14, 7, 1>, 1,
  <14, 1, 5>, 1,
  <14, 5, 12>, 1,
  <21, 12, 11>, 1,
  <21, 11, 20>, 1,
  <21, 20, 25>, 1,
  <27, 25, 26>, 1,
  <27, 26, 28>, 1,
  <27, 28, 29>, 1,
  <23, 29, 24>, 1,
  <23, 24, 18>, 1,
  <23, 18, 17>, 1,
  <4, 13, 16>, 1,
  <4, 16, 9>, 1,
  <4, 9, 2>, 1,
  <4, 0, 3>, 1,
  <4, 3, 8>, 1,
  <4, 8, 10>, 1,
  <13, 10, 18>, 1,
  <13, 18, 24>, 1,
  <13, 24, 22>, 1,
  <16, 22, 28>, 1,
  <16, 28, 26>, 1,
  <16, 26, 19>, 1,
  <9, 19, 20>, 1,
  <9, 20, 11>, 1,
  <9, 11, 6>, 1,
  <2, 6, 5>, 1,
  <2, 5, 1>, 1,
  <2, 1, 0>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_34_pentagonal_orthobirotunda_verts[13];
 #local P1 = Johnson_34_pentagonal_orthobirotunda_verts[16];
 #local P2 = Johnson_34_pentagonal_orthobirotunda_verts[9];
 #local P3 = Johnson_34_pentagonal_orthobirotunda_verts[2];
 #local P4 = Johnson_34_pentagonal_orthobirotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_34_pentagonal_orthobirotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_34_pentagonal_orthobirotunda_obj }
#end
#end

#macro Johnson_34_pentagonal_orthobirotunda_faces2(OnPlane)
#local Johnson_34_pentagonal_orthobirotunda_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_34_pentagonal_orthobirotunda_verts[0],
  Johnson_34_pentagonal_orthobirotunda_verts[1],
  Johnson_34_pentagonal_orthobirotunda_verts[2],
  Johnson_34_pentagonal_orthobirotunda_verts[3],
  Johnson_34_pentagonal_orthobirotunda_verts[4],
  Johnson_34_pentagonal_orthobirotunda_verts[5],
  Johnson_34_pentagonal_orthobirotunda_verts[6],
  Johnson_34_pentagonal_orthobirotunda_verts[7],
  Johnson_34_pentagonal_orthobirotunda_verts[8],
  Johnson_34_pentagonal_orthobirotunda_verts[9],
  Johnson_34_pentagonal_orthobirotunda_verts[10],
  Johnson_34_pentagonal_orthobirotunda_verts[11],
  Johnson_34_pentagonal_orthobirotunda_verts[12],
  Johnson_34_pentagonal_orthobirotunda_verts[13],
  Johnson_34_pentagonal_orthobirotunda_verts[14],
  Johnson_34_pentagonal_orthobirotunda_verts[15],
  Johnson_34_pentagonal_orthobirotunda_verts[16],
  Johnson_34_pentagonal_orthobirotunda_verts[17],
  Johnson_34_pentagonal_orthobirotunda_verts[18],
  Johnson_34_pentagonal_orthobirotunda_verts[19],
  Johnson_34_pentagonal_orthobirotunda_verts[20],
  Johnson_34_pentagonal_orthobirotunda_verts[21],
  Johnson_34_pentagonal_orthobirotunda_verts[22],
  Johnson_34_pentagonal_orthobirotunda_verts[23],
  Johnson_34_pentagonal_orthobirotunda_verts[24],
  Johnson_34_pentagonal_orthobirotunda_verts[25],
  Johnson_34_pentagonal_orthobirotunda_verts[26],
  Johnson_34_pentagonal_orthobirotunda_verts[27],
  Johnson_34_pentagonal_orthobirotunda_verts[28],
  Johnson_34_pentagonal_orthobirotunda_verts[29]
 }
 face_indices {
  56,
  <15, 7, 14>,
  <7, 3, 1>,
  <14, 12, 21>,
  <12, 5, 11>,
  <21, 25, 27>,
  <25, 20, 26>,
  <27, 29, 23>,
  <29, 28, 24>,
  <23, 17, 15>,
  <17, 18, 8>,
  <4, 10, 13>,
  <10, 8, 18>,
  <13, 22, 16>,
  <22, 24, 28>,
  <16, 19, 9>,
  <19, 26, 20>,
  <9, 6, 2>,
  <6, 11, 5>,
  <2, 0, 4>,
  <0, 1, 3>,
  <15, 14, 21>,
  <15, 21, 27>,
  <15, 27, 23>,
  <15, 17, 8>,
  <15, 8, 3>,
  <15, 3, 7>,
  <14, 7, 1>,
  <14, 1, 5>,
  <14, 5, 12>,
  <21, 12, 11>,
  <21, 11, 20>,
  <21, 20, 25>,
  <27, 25, 26>,
  <27, 26, 28>,
  <27, 28, 29>,
  <23, 29, 24>,
  <23, 24, 18>,
  <23, 18, 17>,
  <4, 13, 16>,
  <4, 16, 9>,
  <4, 9, 2>,
  <4, 0, 3>,
  <4, 3, 8>,
  <4, 8, 10>,
  <13, 10, 18>,
  <13, 18, 24>,
  <13, 24, 22>,
  <16, 22, 28>,
  <16, 28, 26>,
  <16, 26, 19>,
  <9, 19, 20>,
  <9, 20, 11>,
  <9, 11, 6>,
  <2, 6, 5>,
  <2, 5, 1>,
  <2, 1, 0>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_34_pentagonal_orthobirotunda_verts[13];
 #local P1 = Johnson_34_pentagonal_orthobirotunda_verts[16];
 #local P2 = Johnson_34_pentagonal_orthobirotunda_verts[9];
 #local P3 = Johnson_34_pentagonal_orthobirotunda_verts[2];
 #local P4 = Johnson_34_pentagonal_orthobirotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_34_pentagonal_orthobirotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_34_pentagonal_orthobirotunda_obj }
#end
#end

#macro Johnson_34_pentagonal_orthobirotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[0], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[1], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[2], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[3], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[4], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[5], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[6], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[7], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[8], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[9], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[10], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[11], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[12], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[13], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[14], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[15], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[16], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[17], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[18], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[19], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[20], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[21], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[22], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[23], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[24], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[25], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[26], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[27], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[28], RadVer }
  sphere { Johnson_34_pentagonal_orthobirotunda_verts[29], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[15], Johnson_34_pentagonal_orthobirotunda_verts[7], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[7], Johnson_34_pentagonal_orthobirotunda_verts[14], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[14], Johnson_34_pentagonal_orthobirotunda_verts[15], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[7], Johnson_34_pentagonal_orthobirotunda_verts[3], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[3], Johnson_34_pentagonal_orthobirotunda_verts[1], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[1], Johnson_34_pentagonal_orthobirotunda_verts[7], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[14], Johnson_34_pentagonal_orthobirotunda_verts[12], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[12], Johnson_34_pentagonal_orthobirotunda_verts[21], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[21], Johnson_34_pentagonal_orthobirotunda_verts[14], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[12], Johnson_34_pentagonal_orthobirotunda_verts[5], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[5], Johnson_34_pentagonal_orthobirotunda_verts[11], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[11], Johnson_34_pentagonal_orthobirotunda_verts[12], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[21], Johnson_34_pentagonal_orthobirotunda_verts[25], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[25], Johnson_34_pentagonal_orthobirotunda_verts[27], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[27], Johnson_34_pentagonal_orthobirotunda_verts[21], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[25], Johnson_34_pentagonal_orthobirotunda_verts[20], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[20], Johnson_34_pentagonal_orthobirotunda_verts[26], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[26], Johnson_34_pentagonal_orthobirotunda_verts[25], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[27], Johnson_34_pentagonal_orthobirotunda_verts[29], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[29], Johnson_34_pentagonal_orthobirotunda_verts[23], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[23], Johnson_34_pentagonal_orthobirotunda_verts[27], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[29], Johnson_34_pentagonal_orthobirotunda_verts[28], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[28], Johnson_34_pentagonal_orthobirotunda_verts[24], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[24], Johnson_34_pentagonal_orthobirotunda_verts[29], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[23], Johnson_34_pentagonal_orthobirotunda_verts[17], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[17], Johnson_34_pentagonal_orthobirotunda_verts[15], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[15], Johnson_34_pentagonal_orthobirotunda_verts[23], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[17], Johnson_34_pentagonal_orthobirotunda_verts[18], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[18], Johnson_34_pentagonal_orthobirotunda_verts[8], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[8], Johnson_34_pentagonal_orthobirotunda_verts[17], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[4], Johnson_34_pentagonal_orthobirotunda_verts[10], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[10], Johnson_34_pentagonal_orthobirotunda_verts[13], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[13], Johnson_34_pentagonal_orthobirotunda_verts[4], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[10], Johnson_34_pentagonal_orthobirotunda_verts[8], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[18], Johnson_34_pentagonal_orthobirotunda_verts[10], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[13], Johnson_34_pentagonal_orthobirotunda_verts[22], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[22], Johnson_34_pentagonal_orthobirotunda_verts[16], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[16], Johnson_34_pentagonal_orthobirotunda_verts[13], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[22], Johnson_34_pentagonal_orthobirotunda_verts[24], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[28], Johnson_34_pentagonal_orthobirotunda_verts[22], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[16], Johnson_34_pentagonal_orthobirotunda_verts[19], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[19], Johnson_34_pentagonal_orthobirotunda_verts[9], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[9], Johnson_34_pentagonal_orthobirotunda_verts[16], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[19], Johnson_34_pentagonal_orthobirotunda_verts[26], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[20], Johnson_34_pentagonal_orthobirotunda_verts[19], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[9], Johnson_34_pentagonal_orthobirotunda_verts[6], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[6], Johnson_34_pentagonal_orthobirotunda_verts[2], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[2], Johnson_34_pentagonal_orthobirotunda_verts[9], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[6], Johnson_34_pentagonal_orthobirotunda_verts[11], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[5], Johnson_34_pentagonal_orthobirotunda_verts[6], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[2], Johnson_34_pentagonal_orthobirotunda_verts[0], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[0], Johnson_34_pentagonal_orthobirotunda_verts[4], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[4], Johnson_34_pentagonal_orthobirotunda_verts[2], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[0], Johnson_34_pentagonal_orthobirotunda_verts[1], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[3], Johnson_34_pentagonal_orthobirotunda_verts[0], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[8], Johnson_34_pentagonal_orthobirotunda_verts[3], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[1], Johnson_34_pentagonal_orthobirotunda_verts[5], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[11], Johnson_34_pentagonal_orthobirotunda_verts[20], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[26], Johnson_34_pentagonal_orthobirotunda_verts[28], RadEdg }
  cylinder { Johnson_34_pentagonal_orthobirotunda_verts[24], Johnson_34_pentagonal_orthobirotunda_verts[18], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_34_pentagonal_orthobirotunda_verts[13];
 #local P1 = Johnson_34_pentagonal_orthobirotunda_verts[16];
 #local P2 = Johnson_34_pentagonal_orthobirotunda_verts[9];
 #local P3 = Johnson_34_pentagonal_orthobirotunda_verts[2];
 #local P4 = Johnson_34_pentagonal_orthobirotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_35_elongated_triangular_orthobicupola_verts = array[18]
{
<-0.903332, -0.063468, 0.034076>,
<-0.833437, 0.283050, 0.763458>,
<-0.589483, 0.680853, 0.100738>,
<-0.561749, -0.142046, -0.696749>,
<-0.484641, -0.705032, 0.298750>,
<-0.414746, -0.358514, 1.028133>,
<-0.247900, 0.602275, -0.630087>,
<-0.143058, -0.783610, -0.432074>,
<-0.100897, 0.385807, 1.094795>,
<0.065949, 0.076155, -1.160799>,
<0.143058, 0.783610, 0.432075>,
<0.247900, -0.602274, 0.630087>,
<0.484641, -0.565409, -0.896124>,
<0.484641, 0.705032, -0.298750>,
<0.561749, 0.142046, 0.696749>,
<0.589483, -0.680852, -0.100737>,
<0.798490, 0.178912, -0.829462>,
<0.903332, 0.063468, -0.034075>,
}
#declare P0 = Johnson_35_elongated_triangular_orthobicupola_verts[9];
#declare P1 = Johnson_35_elongated_triangular_orthobicupola_verts[12];
#declare P2 = Johnson_35_elongated_triangular_orthobicupola_verts[16];
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
 #declare Johnson_35_elongated_triangular_orthobicupola_verts[Num] = vtransform(Johnson_35_elongated_triangular_orthobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_35_elongated_triangular_orthobicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_35_elongated_triangular_orthobicupola_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_35_elongated_triangular_orthobicupola_verts[0],
  Johnson_35_elongated_triangular_orthobicupola_verts[1],
  Johnson_35_elongated_triangular_orthobicupola_verts[2],
  Johnson_35_elongated_triangular_orthobicupola_verts[3],
  Johnson_35_elongated_triangular_orthobicupola_verts[4],
  Johnson_35_elongated_triangular_orthobicupola_verts[5],
  Johnson_35_elongated_triangular_orthobicupola_verts[6],
  Johnson_35_elongated_triangular_orthobicupola_verts[7],
  Johnson_35_elongated_triangular_orthobicupola_verts[8],
  Johnson_35_elongated_triangular_orthobicupola_verts[9],
  Johnson_35_elongated_triangular_orthobicupola_verts[10],
  Johnson_35_elongated_triangular_orthobicupola_verts[11],
  Johnson_35_elongated_triangular_orthobicupola_verts[12],
  Johnson_35_elongated_triangular_orthobicupola_verts[13],
  Johnson_35_elongated_triangular_orthobicupola_verts[14],
  Johnson_35_elongated_triangular_orthobicupola_verts[15],
  Johnson_35_elongated_triangular_orthobicupola_verts[16],
  Johnson_35_elongated_triangular_orthobicupola_verts[17]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  32,
  <9, 16, 12>, 0,
  <16, 13, 17>, 0,
  <12, 15, 7>, 0,
  <9, 3, 6>, 0,
  <8, 1, 5>, 0,
  <1, 2, 0>, 0,
  <5, 4, 11>, 0,
  <8, 14, 10>, 0,
  <16, 9, 6>, 1,
  <16, 6, 13>, 1,
  <12, 16, 17>, 1,
  <12, 17, 15>, 1,
  <9, 12, 7>, 1,
  <9, 7, 3>, 1,
  <1, 8, 10>, 1,
  <1, 10, 2>, 1,
  <5, 1, 0>, 1,
  <5, 0, 4>, 1,
  <8, 5, 11>, 1,
  <8, 11, 14>, 1,
  <7, 4, 0>, 1,
  <7, 0, 3>, 1,
  <3, 0, 2>, 1,
  <3, 2, 6>, 1,
  <6, 2, 10>, 1,
  <6, 10, 13>, 1,
  <13, 10, 14>, 1,
  <13, 14, 17>, 1,
  <17, 14, 11>, 1,
  <17, 11, 15>, 1,
  <15, 11, 4>, 1,
  <15, 4, 7>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_35_elongated_triangular_orthobicupola_verts[9];
 #local P1 = Johnson_35_elongated_triangular_orthobicupola_verts[16];
 #local P2 = Johnson_35_elongated_triangular_orthobicupola_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_35_elongated_triangular_orthobicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_35_elongated_triangular_orthobicupola_obj }
#end
#end

#macro Johnson_35_elongated_triangular_orthobicupola_faces2(OnPlane)
#local Johnson_35_elongated_triangular_orthobicupola_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_35_elongated_triangular_orthobicupola_verts[0],
  Johnson_35_elongated_triangular_orthobicupola_verts[1],
  Johnson_35_elongated_triangular_orthobicupola_verts[2],
  Johnson_35_elongated_triangular_orthobicupola_verts[3],
  Johnson_35_elongated_triangular_orthobicupola_verts[4],
  Johnson_35_elongated_triangular_orthobicupola_verts[5],
  Johnson_35_elongated_triangular_orthobicupola_verts[6],
  Johnson_35_elongated_triangular_orthobicupola_verts[7],
  Johnson_35_elongated_triangular_orthobicupola_verts[8],
  Johnson_35_elongated_triangular_orthobicupola_verts[9],
  Johnson_35_elongated_triangular_orthobicupola_verts[10],
  Johnson_35_elongated_triangular_orthobicupola_verts[11],
  Johnson_35_elongated_triangular_orthobicupola_verts[12],
  Johnson_35_elongated_triangular_orthobicupola_verts[13],
  Johnson_35_elongated_triangular_orthobicupola_verts[14],
  Johnson_35_elongated_triangular_orthobicupola_verts[15],
  Johnson_35_elongated_triangular_orthobicupola_verts[16],
  Johnson_35_elongated_triangular_orthobicupola_verts[17]
 }
 face_indices {
  32,
  <9, 16, 12>,
  <16, 13, 17>,
  <12, 15, 7>,
  <9, 3, 6>,
  <8, 1, 5>,
  <1, 2, 0>,
  <5, 4, 11>,
  <8, 14, 10>,
  <16, 9, 6>,
  <16, 6, 13>,
  <12, 16, 17>,
  <12, 17, 15>,
  <9, 12, 7>,
  <9, 7, 3>,
  <1, 8, 10>,
  <1, 10, 2>,
  <5, 1, 0>,
  <5, 0, 4>,
  <8, 5, 11>,
  <8, 11, 14>,
  <7, 4, 0>,
  <7, 0, 3>,
  <3, 0, 2>,
  <3, 2, 6>,
  <6, 2, 10>,
  <6, 10, 13>,
  <13, 10, 14>,
  <13, 14, 17>,
  <17, 14, 11>,
  <17, 11, 15>,
  <15, 11, 4>,
  <15, 4, 7>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_35_elongated_triangular_orthobicupola_verts[9];
 #local P1 = Johnson_35_elongated_triangular_orthobicupola_verts[16];
 #local P2 = Johnson_35_elongated_triangular_orthobicupola_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_35_elongated_triangular_orthobicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_35_elongated_triangular_orthobicupola_obj }
#end
#end

#macro Johnson_35_elongated_triangular_orthobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[0], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[1], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[2], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[3], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[4], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[5], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[6], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[7], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[8], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[9], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[10], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[11], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[12], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[13], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[14], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[15], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[16], RadVer }
  sphere { Johnson_35_elongated_triangular_orthobicupola_verts[17], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[9], Johnson_35_elongated_triangular_orthobicupola_verts[16], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[16], Johnson_35_elongated_triangular_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[12], Johnson_35_elongated_triangular_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[16], Johnson_35_elongated_triangular_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[13], Johnson_35_elongated_triangular_orthobicupola_verts[17], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[17], Johnson_35_elongated_triangular_orthobicupola_verts[16], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[12], Johnson_35_elongated_triangular_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[15], Johnson_35_elongated_triangular_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[7], Johnson_35_elongated_triangular_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[9], Johnson_35_elongated_triangular_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[3], Johnson_35_elongated_triangular_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[6], Johnson_35_elongated_triangular_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[8], Johnson_35_elongated_triangular_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[1], Johnson_35_elongated_triangular_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[5], Johnson_35_elongated_triangular_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[1], Johnson_35_elongated_triangular_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[2], Johnson_35_elongated_triangular_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[0], Johnson_35_elongated_triangular_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[5], Johnson_35_elongated_triangular_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[4], Johnson_35_elongated_triangular_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[11], Johnson_35_elongated_triangular_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[8], Johnson_35_elongated_triangular_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[14], Johnson_35_elongated_triangular_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[10], Johnson_35_elongated_triangular_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[6], Johnson_35_elongated_triangular_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[17], Johnson_35_elongated_triangular_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[7], Johnson_35_elongated_triangular_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[10], Johnson_35_elongated_triangular_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[0], Johnson_35_elongated_triangular_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[11], Johnson_35_elongated_triangular_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[7], Johnson_35_elongated_triangular_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[0], Johnson_35_elongated_triangular_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[2], Johnson_35_elongated_triangular_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[10], Johnson_35_elongated_triangular_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[14], Johnson_35_elongated_triangular_orthobicupola_verts[17], RadEdg }
  cylinder { Johnson_35_elongated_triangular_orthobicupola_verts[11], Johnson_35_elongated_triangular_orthobicupola_verts[15], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_35_elongated_triangular_orthobicupola_verts[9];
 #local P1 = Johnson_35_elongated_triangular_orthobicupola_verts[16];
 #local P2 = Johnson_35_elongated_triangular_orthobicupola_verts[12];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_36_elongated_triangular_gyrobicupola_verts = array[18]
{
<-0.821240, -0.196132, -0.329082>,
<-0.725355, -0.267867, 0.472553>,
<-0.627806, 0.589563, -0.281911>,
<-0.577286, 0.201670, -0.991803>,
<-0.531921, 0.517828, 0.519724>,
<-0.241376, -0.749828, -0.447988>,
<-0.196012, -0.433670, 1.063538>,
<-0.145492, -0.821562, 0.353647>,
<-0.002578, 0.352025, 1.110710>,
<0.002578, -0.352025, -1.110709>,
<0.145492, 0.821563, -0.353646>,
<0.196012, 0.433670, -1.063538>,
<0.241376, 0.749828, 0.447989>,
<0.531921, -0.517828, -0.519723>,
<0.577285, -0.201670, 0.991804>,
<0.627806, -0.589563, 0.281912>,
<0.725355, 0.267867, -0.472551>,
<0.821240, 0.196133, 0.329083>,
}
#declare P0 = Johnson_36_elongated_triangular_gyrobicupola_verts[3];
#declare P1 = Johnson_36_elongated_triangular_gyrobicupola_verts[11];
#declare P2 = Johnson_36_elongated_triangular_gyrobicupola_verts[9];
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
 #declare Johnson_36_elongated_triangular_gyrobicupola_verts[Num] = vtransform(Johnson_36_elongated_triangular_gyrobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_36_elongated_triangular_gyrobicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_36_elongated_triangular_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_36_elongated_triangular_gyrobicupola_verts[0],
  Johnson_36_elongated_triangular_gyrobicupola_verts[1],
  Johnson_36_elongated_triangular_gyrobicupola_verts[2],
  Johnson_36_elongated_triangular_gyrobicupola_verts[3],
  Johnson_36_elongated_triangular_gyrobicupola_verts[4],
  Johnson_36_elongated_triangular_gyrobicupola_verts[5],
  Johnson_36_elongated_triangular_gyrobicupola_verts[6],
  Johnson_36_elongated_triangular_gyrobicupola_verts[7],
  Johnson_36_elongated_triangular_gyrobicupola_verts[8],
  Johnson_36_elongated_triangular_gyrobicupola_verts[9],
  Johnson_36_elongated_triangular_gyrobicupola_verts[10],
  Johnson_36_elongated_triangular_gyrobicupola_verts[11],
  Johnson_36_elongated_triangular_gyrobicupola_verts[12],
  Johnson_36_elongated_triangular_gyrobicupola_verts[13],
  Johnson_36_elongated_triangular_gyrobicupola_verts[14],
  Johnson_36_elongated_triangular_gyrobicupola_verts[15],
  Johnson_36_elongated_triangular_gyrobicupola_verts[16],
  Johnson_36_elongated_triangular_gyrobicupola_verts[17]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  32,
  <3, 11, 9>, 0,
  <11, 10, 16>, 0,
  <9, 13, 5>, 0,
  <3, 0, 2>, 0,
  <14, 8, 6>, 0,
  <8, 12, 4>, 0,
  <6, 1, 7>, 0,
  <14, 15, 17>, 0,
  <11, 3, 2>, 1,
  <11, 2, 10>, 1,
  <9, 11, 16>, 1,
  <9, 16, 13>, 1,
  <3, 9, 5>, 1,
  <3, 5, 0>, 1,
  <8, 14, 17>, 1,
  <8, 17, 12>, 1,
  <6, 8, 4>, 1,
  <6, 4, 1>, 1,
  <14, 6, 7>, 1,
  <14, 7, 15>, 1,
  <5, 7, 1>, 1,
  <5, 1, 0>, 1,
  <0, 1, 4>, 1,
  <0, 4, 2>, 1,
  <2, 4, 12>, 1,
  <2, 12, 10>, 1,
  <10, 12, 17>, 1,
  <10, 17, 16>, 1,
  <16, 17, 15>, 1,
  <16, 15, 13>, 1,
  <13, 15, 7>, 1,
  <13, 7, 5>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_36_elongated_triangular_gyrobicupola_verts[3];
 #local P1 = Johnson_36_elongated_triangular_gyrobicupola_verts[11];
 #local P2 = Johnson_36_elongated_triangular_gyrobicupola_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_36_elongated_triangular_gyrobicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_36_elongated_triangular_gyrobicupola_obj }
#end
#end

#macro Johnson_36_elongated_triangular_gyrobicupola_faces2(OnPlane)
#local Johnson_36_elongated_triangular_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_36_elongated_triangular_gyrobicupola_verts[0],
  Johnson_36_elongated_triangular_gyrobicupola_verts[1],
  Johnson_36_elongated_triangular_gyrobicupola_verts[2],
  Johnson_36_elongated_triangular_gyrobicupola_verts[3],
  Johnson_36_elongated_triangular_gyrobicupola_verts[4],
  Johnson_36_elongated_triangular_gyrobicupola_verts[5],
  Johnson_36_elongated_triangular_gyrobicupola_verts[6],
  Johnson_36_elongated_triangular_gyrobicupola_verts[7],
  Johnson_36_elongated_triangular_gyrobicupola_verts[8],
  Johnson_36_elongated_triangular_gyrobicupola_verts[9],
  Johnson_36_elongated_triangular_gyrobicupola_verts[10],
  Johnson_36_elongated_triangular_gyrobicupola_verts[11],
  Johnson_36_elongated_triangular_gyrobicupola_verts[12],
  Johnson_36_elongated_triangular_gyrobicupola_verts[13],
  Johnson_36_elongated_triangular_gyrobicupola_verts[14],
  Johnson_36_elongated_triangular_gyrobicupola_verts[15],
  Johnson_36_elongated_triangular_gyrobicupola_verts[16],
  Johnson_36_elongated_triangular_gyrobicupola_verts[17]
 }
 face_indices {
  32,
  <3, 11, 9>,
  <11, 10, 16>,
  <9, 13, 5>,
  <3, 0, 2>,
  <14, 8, 6>,
  <8, 12, 4>,
  <6, 1, 7>,
  <14, 15, 17>,
  <11, 3, 2>,
  <11, 2, 10>,
  <9, 11, 16>,
  <9, 16, 13>,
  <3, 9, 5>,
  <3, 5, 0>,
  <8, 14, 17>,
  <8, 17, 12>,
  <6, 8, 4>,
  <6, 4, 1>,
  <14, 6, 7>,
  <14, 7, 15>,
  <5, 7, 1>,
  <5, 1, 0>,
  <0, 1, 4>,
  <0, 4, 2>,
  <2, 4, 12>,
  <2, 12, 10>,
  <10, 12, 17>,
  <10, 17, 16>,
  <16, 17, 15>,
  <16, 15, 13>,
  <13, 15, 7>,
  <13, 7, 5>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_36_elongated_triangular_gyrobicupola_verts[3];
 #local P1 = Johnson_36_elongated_triangular_gyrobicupola_verts[11];
 #local P2 = Johnson_36_elongated_triangular_gyrobicupola_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_36_elongated_triangular_gyrobicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_36_elongated_triangular_gyrobicupola_obj }
#end
#end

#macro Johnson_36_elongated_triangular_gyrobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[0], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[1], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[2], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[3], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[4], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[5], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[6], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[7], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[8], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[9], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[10], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[11], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[12], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[13], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[14], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[15], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[16], RadVer }
  sphere { Johnson_36_elongated_triangular_gyrobicupola_verts[17], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[3], Johnson_36_elongated_triangular_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[11], Johnson_36_elongated_triangular_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[9], Johnson_36_elongated_triangular_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[11], Johnson_36_elongated_triangular_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[10], Johnson_36_elongated_triangular_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[16], Johnson_36_elongated_triangular_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[9], Johnson_36_elongated_triangular_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[13], Johnson_36_elongated_triangular_gyrobicupola_verts[5], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[5], Johnson_36_elongated_triangular_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[3], Johnson_36_elongated_triangular_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[0], Johnson_36_elongated_triangular_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[2], Johnson_36_elongated_triangular_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[14], Johnson_36_elongated_triangular_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[8], Johnson_36_elongated_triangular_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[6], Johnson_36_elongated_triangular_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[8], Johnson_36_elongated_triangular_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[12], Johnson_36_elongated_triangular_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[4], Johnson_36_elongated_triangular_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[6], Johnson_36_elongated_triangular_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[1], Johnson_36_elongated_triangular_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[7], Johnson_36_elongated_triangular_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[14], Johnson_36_elongated_triangular_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[15], Johnson_36_elongated_triangular_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[17], Johnson_36_elongated_triangular_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[2], Johnson_36_elongated_triangular_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[16], Johnson_36_elongated_triangular_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[5], Johnson_36_elongated_triangular_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[17], Johnson_36_elongated_triangular_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[4], Johnson_36_elongated_triangular_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[7], Johnson_36_elongated_triangular_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[5], Johnson_36_elongated_triangular_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[1], Johnson_36_elongated_triangular_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[4], Johnson_36_elongated_triangular_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[12], Johnson_36_elongated_triangular_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[17], Johnson_36_elongated_triangular_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_36_elongated_triangular_gyrobicupola_verts[15], Johnson_36_elongated_triangular_gyrobicupola_verts[13], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_36_elongated_triangular_gyrobicupola_verts[3];
 #local P1 = Johnson_36_elongated_triangular_gyrobicupola_verts[11];
 #local P2 = Johnson_36_elongated_triangular_gyrobicupola_verts[9];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_37_elongated_square_gyrobicupola_verts = array[24]
{
<-0.862856, 0.357407, -0.357407>,
<-0.862856, -0.357407, -0.357407>,
<-0.357407, 0.862856, -0.357407>,
<-0.357407, 0.357407, -0.862856>,
<-0.357407, -0.357407, -0.862856>,
<-0.357407, -0.862856, -0.357407>,
<0.357407, 0.862856, -0.357407>,
<0.357407, 0.357407, -0.862856>,
<0.357407, -0.357407, -0.862856>,
<0.357407, -0.862856, -0.357407>,
<0.862856, 0.357407, -0.357407>,
<0.862856, -0.357407, -0.357407>,
<0.862856, 0.357407, 0.357407>,
<0.862856, -0.357407, 0.357407>,
<0.357407, 0.862856, 0.357407>,
<0.505449, 0.000000, 0.862856>,
<0.357407, -0.862856, 0.357407>,
<-0.000000, 0.505449, 0.862856>,
<-0.000000, -0.505449, 0.862856>,
<-0.357407, 0.862856, 0.357407>,
<-0.505449, 0.000000, 0.862856>,
<-0.357407, -0.862856, 0.357407>,
<-0.862856, 0.357407, 0.357407>,
<-0.862856, -0.357407, 0.357407>
}
#declare P0 = Johnson_37_elongated_square_gyrobicupola_verts[4];
#declare P1 = Johnson_37_elongated_square_gyrobicupola_verts[7];
#declare P2 = Johnson_37_elongated_square_gyrobicupola_verts[8];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 24)
 #declare Johnson_37_elongated_square_gyrobicupola_verts[Num] = vtransform(Johnson_37_elongated_square_gyrobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_37_elongated_square_gyrobicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_37_elongated_square_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  24,
  Johnson_37_elongated_square_gyrobicupola_verts[0],
  Johnson_37_elongated_square_gyrobicupola_verts[1],
  Johnson_37_elongated_square_gyrobicupola_verts[2],
  Johnson_37_elongated_square_gyrobicupola_verts[3],
  Johnson_37_elongated_square_gyrobicupola_verts[4],
  Johnson_37_elongated_square_gyrobicupola_verts[5],
  Johnson_37_elongated_square_gyrobicupola_verts[6],
  Johnson_37_elongated_square_gyrobicupola_verts[7],
  Johnson_37_elongated_square_gyrobicupola_verts[8],
  Johnson_37_elongated_square_gyrobicupola_verts[9],
  Johnson_37_elongated_square_gyrobicupola_verts[10],
  Johnson_37_elongated_square_gyrobicupola_verts[11],
  Johnson_37_elongated_square_gyrobicupola_verts[12],
  Johnson_37_elongated_square_gyrobicupola_verts[13],
  Johnson_37_elongated_square_gyrobicupola_verts[14],
  Johnson_37_elongated_square_gyrobicupola_verts[15],
  Johnson_37_elongated_square_gyrobicupola_verts[16],
  Johnson_37_elongated_square_gyrobicupola_verts[17],
  Johnson_37_elongated_square_gyrobicupola_verts[18],
  Johnson_37_elongated_square_gyrobicupola_verts[19],
  Johnson_37_elongated_square_gyrobicupola_verts[20],
  Johnson_37_elongated_square_gyrobicupola_verts[21],
  Johnson_37_elongated_square_gyrobicupola_verts[22],
  Johnson_37_elongated_square_gyrobicupola_verts[23]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  44,
  <0, 3, 2>, 0,
  <1, 5, 4>, 0,
  <6, 7, 10>, 0,
  <8, 9, 11>, 0,
  <12, 13, 15>, 0,
  <14, 17, 19>, 0,
  <16, 21, 18>, 0,
  <20, 23, 22>, 0,
  <0, 1, 4>, 1,
  <0, 4, 3>, 1,
  <2, 3, 7>, 1,
  <2, 7, 6>, 1,
  <3, 4, 8>, 1,
  <3, 8, 7>, 1,
  <4, 5, 9>, 1,
  <4, 9, 8>, 1,
  <7, 8, 11>, 1,
  <7, 11, 10>, 1,
  <12, 15, 17>, 1,
  <12, 17, 14>, 1,
  <13, 16, 18>, 1,
  <13, 18, 15>, 1,
  <15, 18, 20>, 1,
  <15, 20, 17>, 1,
  <17, 20, 22>, 1,
  <17, 22, 19>, 1,
  <18, 21, 23>, 1,
  <18, 23, 20>, 1,
  <0, 2, 19>, 1,
  <0, 19, 22>, 1,
  <2, 6, 14>, 1,
  <2, 14, 19>, 1,
  <6, 10, 12>, 1,
  <6, 12, 14>, 1,
  <10, 11, 13>, 1,
  <10, 13, 12>, 1,
  <9, 16, 13>, 1,
  <9, 13, 11>, 1,
  <5, 21, 16>, 1,
  <5, 16, 9>, 1,
  <1, 23, 21>, 1,
  <1, 21, 5>, 1,
  <0, 22, 23>, 1,
  <0, 23, 1>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_37_elongated_square_gyrobicupola_verts[4];
 #local P1 = Johnson_37_elongated_square_gyrobicupola_verts[7];
 #local P2 = Johnson_37_elongated_square_gyrobicupola_verts[8];
 #local P3 = Johnson_37_elongated_square_gyrobicupola_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_37_elongated_square_gyrobicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_37_elongated_square_gyrobicupola_obj }
#end
#end

#macro Johnson_37_elongated_square_gyrobicupola_faces2(OnPlane)
#local Johnson_37_elongated_square_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  24,
  Johnson_37_elongated_square_gyrobicupola_verts[0],
  Johnson_37_elongated_square_gyrobicupola_verts[1],
  Johnson_37_elongated_square_gyrobicupola_verts[2],
  Johnson_37_elongated_square_gyrobicupola_verts[3],
  Johnson_37_elongated_square_gyrobicupola_verts[4],
  Johnson_37_elongated_square_gyrobicupola_verts[5],
  Johnson_37_elongated_square_gyrobicupola_verts[6],
  Johnson_37_elongated_square_gyrobicupola_verts[7],
  Johnson_37_elongated_square_gyrobicupola_verts[8],
  Johnson_37_elongated_square_gyrobicupola_verts[9],
  Johnson_37_elongated_square_gyrobicupola_verts[10],
  Johnson_37_elongated_square_gyrobicupola_verts[11],
  Johnson_37_elongated_square_gyrobicupola_verts[12],
  Johnson_37_elongated_square_gyrobicupola_verts[13],
  Johnson_37_elongated_square_gyrobicupola_verts[14],
  Johnson_37_elongated_square_gyrobicupola_verts[15],
  Johnson_37_elongated_square_gyrobicupola_verts[16],
  Johnson_37_elongated_square_gyrobicupola_verts[17],
  Johnson_37_elongated_square_gyrobicupola_verts[18],
  Johnson_37_elongated_square_gyrobicupola_verts[19],
  Johnson_37_elongated_square_gyrobicupola_verts[20],
  Johnson_37_elongated_square_gyrobicupola_verts[21],
  Johnson_37_elongated_square_gyrobicupola_verts[22],
  Johnson_37_elongated_square_gyrobicupola_verts[23]
 }
 face_indices {
  44,
  <0, 3, 2>,
  <1, 5, 4>,
  <6, 7, 10>,
  <8, 9, 11>,
  <12, 13, 15>,
  <14, 17, 19>,
  <16, 21, 18>,
  <20, 23, 22>,
  <0, 1, 4>,
  <0, 4, 3>,
  <2, 3, 7>,
  <2, 7, 6>,
  <3, 4, 8>,
  <3, 8, 7>,
  <4, 5, 9>,
  <4, 9, 8>,
  <7, 8, 11>,
  <7, 11, 10>,
  <12, 15, 17>,
  <12, 17, 14>,
  <13, 16, 18>,
  <13, 18, 15>,
  <15, 18, 20>,
  <15, 20, 17>,
  <17, 20, 22>,
  <17, 22, 19>,
  <18, 21, 23>,
  <18, 23, 20>,
  <0, 2, 19>,
  <0, 19, 22>,
  <2, 6, 14>,
  <2, 14, 19>,
  <6, 10, 12>,
  <6, 12, 14>,
  <10, 11, 13>,
  <10, 13, 12>,
  <9, 16, 13>,
  <9, 13, 11>,
  <5, 21, 16>,
  <5, 16, 9>,
  <1, 23, 21>,
  <1, 21, 5>,
  <0, 22, 23>,
  <0, 23, 1>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_37_elongated_square_gyrobicupola_verts[4];
 #local P1 = Johnson_37_elongated_square_gyrobicupola_verts[7];
 #local P2 = Johnson_37_elongated_square_gyrobicupola_verts[8];
 #local P3 = Johnson_37_elongated_square_gyrobicupola_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_37_elongated_square_gyrobicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_37_elongated_square_gyrobicupola_obj }
#end
#end

#macro Johnson_37_elongated_square_gyrobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[0], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[1], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[2], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[3], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[4], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[5], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[6], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[7], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[8], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[9], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[10], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[11], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[12], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[13], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[14], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[15], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[16], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[17], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[18], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[19], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[20], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[21], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[22], RadVer }
  sphere { Johnson_37_elongated_square_gyrobicupola_verts[23], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[0], Johnson_37_elongated_square_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[3], Johnson_37_elongated_square_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[2], Johnson_37_elongated_square_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[1], Johnson_37_elongated_square_gyrobicupola_verts[5], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[5], Johnson_37_elongated_square_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[4], Johnson_37_elongated_square_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[6], Johnson_37_elongated_square_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[7], Johnson_37_elongated_square_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[10], Johnson_37_elongated_square_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[8], Johnson_37_elongated_square_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[9], Johnson_37_elongated_square_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[11], Johnson_37_elongated_square_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[12], Johnson_37_elongated_square_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[13], Johnson_37_elongated_square_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[15], Johnson_37_elongated_square_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[14], Johnson_37_elongated_square_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[17], Johnson_37_elongated_square_gyrobicupola_verts[19], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[19], Johnson_37_elongated_square_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[16], Johnson_37_elongated_square_gyrobicupola_verts[21], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[21], Johnson_37_elongated_square_gyrobicupola_verts[18], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[18], Johnson_37_elongated_square_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[20], Johnson_37_elongated_square_gyrobicupola_verts[23], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[23], Johnson_37_elongated_square_gyrobicupola_verts[22], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[22], Johnson_37_elongated_square_gyrobicupola_verts[20], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[0], Johnson_37_elongated_square_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[4], Johnson_37_elongated_square_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[3], Johnson_37_elongated_square_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[6], Johnson_37_elongated_square_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[4], Johnson_37_elongated_square_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[8], Johnson_37_elongated_square_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[5], Johnson_37_elongated_square_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[11], Johnson_37_elongated_square_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[15], Johnson_37_elongated_square_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[14], Johnson_37_elongated_square_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[13], Johnson_37_elongated_square_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[18], Johnson_37_elongated_square_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[18], Johnson_37_elongated_square_gyrobicupola_verts[20], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[20], Johnson_37_elongated_square_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[22], Johnson_37_elongated_square_gyrobicupola_verts[19], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[21], Johnson_37_elongated_square_gyrobicupola_verts[23], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[2], Johnson_37_elongated_square_gyrobicupola_verts[19], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[22], Johnson_37_elongated_square_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[6], Johnson_37_elongated_square_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[10], Johnson_37_elongated_square_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[11], Johnson_37_elongated_square_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[9], Johnson_37_elongated_square_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[5], Johnson_37_elongated_square_gyrobicupola_verts[21], RadEdg }
  cylinder { Johnson_37_elongated_square_gyrobicupola_verts[1], Johnson_37_elongated_square_gyrobicupola_verts[23], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_37_elongated_square_gyrobicupola_verts[4];
 #local P1 = Johnson_37_elongated_square_gyrobicupola_verts[7];
 #local P2 = Johnson_37_elongated_square_gyrobicupola_verts[8];
 #local P3 = Johnson_37_elongated_square_gyrobicupola_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_38_elongated_pentagonal_orthobicupola_verts = array[30]
{
<-1.047541, -0.144730, -0.164687>,
<-0.972660, 0.443085, 0.054945>,
<-0.794156, 0.029302, -0.716846>,
<-0.770690, -0.710500, -0.215961>,
<-0.748241, -0.047945, 0.383423>,
<-0.719275, 0.617116, -0.497215>,
<-0.574648, 0.828420, 0.359043>,
<-0.517304, -0.536469, -0.768120>,
<-0.471389, -0.613715, 0.332149>,
<-0.350229, 0.337390, 0.687521>,
<-0.321263, 1.002451, -0.193117>,
<-0.247853, -1.038120, -0.079291>,
<-0.228431, 0.309073, -0.749313>,
<-0.005532, 0.864089, 0.631452>,
<0.005532, -0.864089, -0.631452>,
<0.048421, -0.256696, -0.800587>,
<0.097726, -0.578045, 0.604557>,
<0.169581, 0.694408, -0.445215>,
<0.172608, 0.009769, 0.824189>,
<0.247853, 1.038120, 0.079291>,
<0.321263, -1.002451, 0.193117>,
<0.517305, 0.536469, 0.768120>,
<0.574648, -0.828420, -0.359043>,
<0.617537, -0.221027, -0.528178>
<0.692418, 0.366788, -0.308546>,
<0.719275, -0.617116, 0.497214>,
<0.770690, 0.710500, 0.215961>,
<0.794156, -0.029301, 0.716846>,
<0.972660, -0.443085, -0.054945>,
<1.047542, 0.144730, 0.164687>,
}
#declare P0 = Johnson_38_elongated_pentagonal_orthobicupola_verts[9];
#declare P1 = Johnson_38_elongated_pentagonal_orthobicupola_verts[4];
#declare P2 = Johnson_38_elongated_pentagonal_orthobicupola_verts[8];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 30)
 #declare Johnson_38_elongated_pentagonal_orthobicupola_verts[Num] = vtransform(Johnson_38_elongated_pentagonal_orthobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_38_elongated_pentagonal_orthobicupola_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_38_elongated_pentagonal_orthobicupola_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_38_elongated_pentagonal_orthobicupola_verts[0],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[1],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[2],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[3],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[4],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[5],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[6],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[7],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[8],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[9],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[10],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[11],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[12],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[13],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[14],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[15],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[16],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[17],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[18],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[19],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[20],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[21],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[22],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[23],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[24],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[25],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[26],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[27],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[28],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[29]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  56,
  <17, 10, 19>, 0,
  <24, 26, 29>, 0,
  <23, 28, 22>, 0,
  <15, 14, 7>, 0,
  <12, 2, 5>, 0,
  <4, 1, 0>, 0,
  <8, 3, 11>, 0,
  <16, 20, 25>, 0,
  <18, 27, 21>, 0,
  <9, 13, 6>, 0,
  <17, 12, 5>, 1,
  <17, 5, 10>, 1,
  <24, 17, 19>, 1,
  <24, 19, 26>, 1,
  <23, 24, 29>, 1,
  <23, 29, 28>, 1,
  <15, 23, 22>, 1,
  <15, 22, 14>, 1,
  <12, 15, 7>, 1,
  <12, 7, 2>, 1,
  <4, 9, 6>, 1,
  <4, 6, 1>, 1,
  <8, 4, 0>, 1,
  <8, 0, 3>, 1,
  <16, 8, 11>, 1,
  <16, 11, 20>, 1,
  <18, 16, 25>, 1,
  <18, 25, 27>, 1,
  <9, 18, 21>, 1,
  <9, 21, 13>, 1,
  <22, 20, 11>, 1,
  <22, 11, 14>, 1,
  <14, 11, 3>, 1,
  <14, 3, 7>, 1,
  <7, 3, 0>, 1,
  <7, 0, 2>, 1,
  <2, 0, 1>, 1,
  <2, 1, 5>, 1,
  <5, 1, 6>, 1,
  <5, 6, 10>, 1,
  <10, 6, 13>, 1,
  <10, 13, 19>, 1,
  <19, 13, 21>, 1,
  <19, 21, 26>, 1,
  <26, 21, 27>, 1,
  <26, 27, 29>, 1,
  <29, 27, 25>, 1,
  <29, 25, 28>, 1,
  <28, 25, 20>, 1,
  <28, 20, 22>, 1,
  <12, 17, 24>, 2,
  <12, 24, 23>, 2,
  <12, 23, 15>, 2,
  <9, 4, 8>, 2,
  <9, 8, 16>, 2,
  <9, 16, 18>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_38_elongated_pentagonal_orthobicupola_verts[9];
 #local P1 = Johnson_38_elongated_pentagonal_orthobicupola_verts[4];
 #local P2 = Johnson_38_elongated_pentagonal_orthobicupola_verts[8];
 #local P3 = Johnson_38_elongated_pentagonal_orthobicupola_verts[16];
 #local P4 = Johnson_38_elongated_pentagonal_orthobicupola_verts[18];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_38_elongated_pentagonal_orthobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_38_elongated_pentagonal_orthobicupola_obj }
#end
#end

#macro Johnson_38_elongated_pentagonal_orthobicupola_faces2(OnPlane)
#local Johnson_38_elongated_pentagonal_orthobicupola_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_38_elongated_pentagonal_orthobicupola_verts[0],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[1],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[2],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[3],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[4],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[5],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[6],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[7],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[8],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[9],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[10],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[11],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[12],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[13],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[14],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[15],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[16],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[17],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[18],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[19],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[20],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[21],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[22],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[23],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[24],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[25],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[26],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[27],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[28],
  Johnson_38_elongated_pentagonal_orthobicupola_verts[29]
 }
 face_indices {
  56,
  <17, 10, 19>,
  <24, 26, 29>,
  <23, 28, 22>,
  <15, 14, 7>,
  <12, 2, 5>,
  <4, 1, 0>,
  <8, 3, 11>,
  <16, 20, 25>,
  <18, 27, 21>,
  <9, 13, 6>,
  <17, 12, 5>,
  <17, 5, 10>,
  <24, 17, 19>,
  <24, 19, 26>,
  <23, 24, 29>,
  <23, 29, 28>,
  <15, 23, 22>,
  <15, 22, 14>,
  <12, 15, 7>,
  <12, 7, 2>,
  <4, 9, 6>,
  <4, 6, 1>,
  <8, 4, 0>,
  <8, 0, 3>,
  <16, 8, 11>,
  <16, 11, 20>,
  <18, 16, 25>,
  <18, 25, 27>,
  <9, 18, 21>,
  <9, 21, 13>,
  <22, 20, 11>,
  <22, 11, 14>,
  <14, 11, 3>,
  <14, 3, 7>,
  <7, 3, 0>,
  <7, 0, 2>,
  <2, 0, 1>,
  <2, 1, 5>,
  <5, 1, 6>,
  <5, 6, 10>,
  <10, 6, 13>,
  <10, 13, 19>,
  <19, 13, 21>,
  <19, 21, 26>,
  <26, 21, 27>,
  <26, 27, 29>,
  <29, 27, 25>,
  <29, 25, 28>,
  <28, 25, 20>,
  <28, 20, 22>,
  <12, 17, 24>,
  <12, 24, 23>,
  <12, 23, 15>,
  <9, 4, 8>,
  <9, 8, 16>,
  <9, 16, 18>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_38_elongated_pentagonal_orthobicupola_verts[9];
 #local P1 = Johnson_38_elongated_pentagonal_orthobicupola_verts[4];
 #local P2 = Johnson_38_elongated_pentagonal_orthobicupola_verts[8];
 #local P3 = Johnson_38_elongated_pentagonal_orthobicupola_verts[16];
 #local P4 = Johnson_38_elongated_pentagonal_orthobicupola_verts[18];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_38_elongated_pentagonal_orthobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_38_elongated_pentagonal_orthobicupola_obj }
#end
#end

#macro Johnson_38_elongated_pentagonal_orthobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[0], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[1], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[2], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[3], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[4], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[5], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[6], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[7], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[8], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[9], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[10], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[11], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[12], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[13], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[14], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[15], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[16], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[17], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[18], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[19], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[20], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[21], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[22], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[23], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[24], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[25], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[26], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[27], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[28], RadVer }
  sphere { Johnson_38_elongated_pentagonal_orthobicupola_verts[29], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[17], Johnson_38_elongated_pentagonal_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[10], Johnson_38_elongated_pentagonal_orthobicupola_verts[19], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[19], Johnson_38_elongated_pentagonal_orthobicupola_verts[17], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[24], Johnson_38_elongated_pentagonal_orthobicupola_verts[26], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[26], Johnson_38_elongated_pentagonal_orthobicupola_verts[29], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[29], Johnson_38_elongated_pentagonal_orthobicupola_verts[24], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[23], Johnson_38_elongated_pentagonal_orthobicupola_verts[28], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[28], Johnson_38_elongated_pentagonal_orthobicupola_verts[22], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[22], Johnson_38_elongated_pentagonal_orthobicupola_verts[23], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[15], Johnson_38_elongated_pentagonal_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[14], Johnson_38_elongated_pentagonal_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[7], Johnson_38_elongated_pentagonal_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[12], Johnson_38_elongated_pentagonal_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[2], Johnson_38_elongated_pentagonal_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[5], Johnson_38_elongated_pentagonal_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[4], Johnson_38_elongated_pentagonal_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[1], Johnson_38_elongated_pentagonal_orthobicupola_verts[0], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[0], Johnson_38_elongated_pentagonal_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[8], Johnson_38_elongated_pentagonal_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[3], Johnson_38_elongated_pentagonal_orthobicupola_verts[11], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[11], Johnson_38_elongated_pentagonal_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[16], Johnson_38_elongated_pentagonal_orthobicupola_verts[20], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[20], Johnson_38_elongated_pentagonal_orthobicupola_verts[25], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[25], Johnson_38_elongated_pentagonal_orthobicupola_verts[16], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[18], Johnson_38_elongated_pentagonal_orthobicupola_verts[27], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[27], Johnson_38_elongated_pentagonal_orthobicupola_verts[21], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[21], Johnson_38_elongated_pentagonal_orthobicupola_verts[18], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[9], Johnson_38_elongated_pentagonal_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[13], Johnson_38_elongated_pentagonal_orthobicupola_verts[6], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[6], Johnson_38_elongated_pentagonal_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[17], Johnson_38_elongated_pentagonal_orthobicupola_verts[12], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[5], Johnson_38_elongated_pentagonal_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[24], Johnson_38_elongated_pentagonal_orthobicupola_verts[17], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[19], Johnson_38_elongated_pentagonal_orthobicupola_verts[26], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[23], Johnson_38_elongated_pentagonal_orthobicupola_verts[24], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[29], Johnson_38_elongated_pentagonal_orthobicupola_verts[28], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[15], Johnson_38_elongated_pentagonal_orthobicupola_verts[23], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[22], Johnson_38_elongated_pentagonal_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[12], Johnson_38_elongated_pentagonal_orthobicupola_verts[15], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[7], Johnson_38_elongated_pentagonal_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[4], Johnson_38_elongated_pentagonal_orthobicupola_verts[9], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[6], Johnson_38_elongated_pentagonal_orthobicupola_verts[1], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[8], Johnson_38_elongated_pentagonal_orthobicupola_verts[4], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[0], Johnson_38_elongated_pentagonal_orthobicupola_verts[3], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[16], Johnson_38_elongated_pentagonal_orthobicupola_verts[8], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[11], Johnson_38_elongated_pentagonal_orthobicupola_verts[20], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[18], Johnson_38_elongated_pentagonal_orthobicupola_verts[16], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[25], Johnson_38_elongated_pentagonal_orthobicupola_verts[27], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[9], Johnson_38_elongated_pentagonal_orthobicupola_verts[18], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[21], Johnson_38_elongated_pentagonal_orthobicupola_verts[13], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[22], Johnson_38_elongated_pentagonal_orthobicupola_verts[20], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[11], Johnson_38_elongated_pentagonal_orthobicupola_verts[14], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[3], Johnson_38_elongated_pentagonal_orthobicupola_verts[7], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[0], Johnson_38_elongated_pentagonal_orthobicupola_verts[2], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[1], Johnson_38_elongated_pentagonal_orthobicupola_verts[5], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[6], Johnson_38_elongated_pentagonal_orthobicupola_verts[10], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[13], Johnson_38_elongated_pentagonal_orthobicupola_verts[19], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[21], Johnson_38_elongated_pentagonal_orthobicupola_verts[26], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[27], Johnson_38_elongated_pentagonal_orthobicupola_verts[29], RadEdg }
  cylinder { Johnson_38_elongated_pentagonal_orthobicupola_verts[25], Johnson_38_elongated_pentagonal_orthobicupola_verts[28], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_38_elongated_pentagonal_orthobicupola_verts[9];
 #local P1 = Johnson_38_elongated_pentagonal_orthobicupola_verts[4];
 #local P2 = Johnson_38_elongated_pentagonal_orthobicupola_verts[8];
 #local P3 = Johnson_38_elongated_pentagonal_orthobicupola_verts[16];
 #local P4 = Johnson_38_elongated_pentagonal_orthobicupola_verts[18];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_39_elongated_pentagonal_gyrobicupola_verts = array[30]
{
<-1.006864, 0.217224, -0.290603>,
<-0.990318, 0.219795, 0.341133>,
<-0.944481, -0.411647, -0.289678>,
<-0.927935, -0.409077, 0.342059>,
<-0.687819, 0.762632, -0.301179>,
<-0.671273, 0.765203, 0.330558>,
<-0.551737, -0.055664, -0.633770>,
<-0.524499, -0.883775, -0.298756>,
<-0.507953, -0.881203, 0.332980>,
<-0.446854, 0.274173, 0.659035>,
<-0.384471, -0.354698, 0.659960>,
<-0.232692, 0.489744, -0.644346>,
<-0.131755, -0.527791, -0.642848>,
<-0.109210, 1.016250, -0.317365>,
<-0.092665, 1.018821, 0.314371>,
<0.092664, -1.018821, -0.314371>,
<0.109210, -1.016250, 0.317365>,
<0.131755, 0.527791, 0.642848>,
<0.232692, -0.489745, 0.644346>,
<0.384471, 0.354698, -0.659960>,
<0.446854, -0.274173, -0.659035>,
<0.507953, 0.881203, -0.332980>,
<0.524499, 0.883774, 0.298756>,
<0.551737, 0.055664, 0.633770>
<0.671273, -0.765203, -0.330558>,
<0.687819, -0.762632, 0.301179>,
<0.927935, 0.409076, -0.342059>,
<0.944481, 0.411647, 0.289678>,
<0.990318, -0.219795, -0.341133>,
<1.006864, -0.217224, 0.290603>,
}
#declare P0 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[17];
#declare P1 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[9];
#declare P2 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[10];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 30)
 #declare Johnson_39_elongated_pentagonal_gyrobicupola_verts[Num] = vtransform(Johnson_39_elongated_pentagonal_gyrobicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_39_elongated_pentagonal_gyrobicupola_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_39_elongated_pentagonal_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[0],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[1],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[2],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[3],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[4],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[5],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[6],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[7],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[8],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[9],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[10],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[11],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[12],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[13],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[14],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[15],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[16],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[17],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[18],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[19],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[20],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[21],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[22],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[23],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[24],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[25],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[26],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[27],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[28],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[29]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  56,
  <11, 4, 13>, 0,
  <19, 21, 26>, 0,
  <20, 28, 24>, 0,
  <12, 15, 7>, 0,
  <6, 2, 0>, 0,
  <9, 5, 1>, 0,
  <10, 3, 8>, 0,
  <18, 16, 25>, 0,
  <23, 29, 27>, 0,
  <17, 22, 14>, 0,
  <11, 6, 0>, 1,
  <11, 0, 4>, 1,
  <19, 11, 13>, 1,
  <19, 13, 21>, 1,
  <20, 19, 26>, 1,
  <20, 26, 28>, 1,
  <12, 20, 24>, 1,
  <12, 24, 15>, 1,
  <6, 12, 7>, 1,
  <6, 7, 2>, 1,
  <9, 17, 14>, 1,
  <9, 14, 5>, 1,
  <10, 9, 1>, 1,
  <10, 1, 3>, 1,
  <18, 10, 8>, 1,
  <18, 8, 16>, 1,
  <23, 18, 25>, 1,
  <23, 25, 29>, 1,
  <17, 23, 27>, 1,
  <17, 27, 22>, 1,
  <24, 25, 16>, 1,
  <24, 16, 15>, 1,
  <15, 16, 8>, 1,
  <15, 8, 7>, 1,
  <7, 8, 3>, 1,
  <7, 3, 2>, 1,
  <2, 3, 1>, 1,
  <2, 1, 0>, 1,
  <0, 1, 5>, 1,
  <0, 5, 4>, 1,
  <4, 5, 14>, 1,
  <4, 14, 13>, 1,
  <13, 14, 22>, 1,
  <13, 22, 21>, 1,
  <21, 22, 27>, 1,
  <21, 27, 26>, 1,
  <26, 27, 29>, 1,
  <26, 29, 28>, 1,
  <28, 29, 25>, 1,
  <28, 25, 24>, 1,
  <6, 11, 19>, 2,
  <6, 19, 20>, 2,
  <6, 20, 12>, 2,
  <17, 9, 10>, 2,
  <17, 10, 18>, 2,
  <17, 18, 23>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[17];
 #local P1 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[9];
 #local P2 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[10];
 #local P3 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[18];
 #local P4 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[23];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_39_elongated_pentagonal_gyrobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_39_elongated_pentagonal_gyrobicupola_obj }
#end
#end

#macro Johnson_39_elongated_pentagonal_gyrobicupola_faces2(OnPlane)
#local Johnson_39_elongated_pentagonal_gyrobicupola_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[0],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[1],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[2],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[3],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[4],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[5],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[6],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[7],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[8],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[9],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[10],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[11],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[12],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[13],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[14],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[15],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[16],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[17],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[18],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[19],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[20],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[21],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[22],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[23],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[24],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[25],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[26],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[27],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[28],
  Johnson_39_elongated_pentagonal_gyrobicupola_verts[29]
 }
 face_indices {
  56,
  <11, 4, 13>,
  <19, 21, 26>,
  <20, 28, 24>,
  <12, 15, 7>,
  <6, 2, 0>,
  <9, 5, 1>,
  <10, 3, 8>,
  <18, 16, 25>,
  <23, 29, 27>,
  <17, 22, 14>,
  <11, 6, 0>,
  <11, 0, 4>,
  <19, 11, 13>,
  <19, 13, 21>,
  <20, 19, 26>,
  <20, 26, 28>,
  <12, 20, 24>,
  <12, 24, 15>,
  <6, 12, 7>,
  <6, 7, 2>,
  <9, 17, 14>,
  <9, 14, 5>,
  <10, 9, 1>,
  <10, 1, 3>,
  <18, 10, 8>,
  <18, 8, 16>,
  <23, 18, 25>,
  <23, 25, 29>,
  <17, 23, 27>,
  <17, 27, 22>,
  <24, 25, 16>,
  <24, 16, 15>,
  <15, 16, 8>,
  <15, 8, 7>,
  <7, 8, 3>,
  <7, 3, 2>,
  <2, 3, 1>,
  <2, 1, 0>,
  <0, 1, 5>,
  <0, 5, 4>,
  <4, 5, 14>,
  <4, 14, 13>,
  <13, 14, 22>,
  <13, 22, 21>,
  <21, 22, 27>,
  <21, 27, 26>,
  <26, 27, 29>,
  <26, 29, 28>,
  <28, 29, 25>,
  <28, 25, 24>,
  <6, 11, 19>,
  <6, 19, 20>,
  <6, 20, 12>,
  <17, 9, 10>,
  <17, 10, 18>,
  <17, 18, 23>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[17];
 #local P1 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[9];
 #local P2 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[10];
 #local P3 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[18];
 #local P4 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[23];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_39_elongated_pentagonal_gyrobicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_39_elongated_pentagonal_gyrobicupola_obj }
#end
#end

#macro Johnson_39_elongated_pentagonal_gyrobicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[0], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[1], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[2], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[3], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[4], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[5], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[6], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[7], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[8], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[9], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[10], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[11], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[12], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[13], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[14], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[15], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[16], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[17], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[18], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[19], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[20], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[21], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[22], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[23], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[24], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[25], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[26], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[27], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[28], RadVer }
  sphere { Johnson_39_elongated_pentagonal_gyrobicupola_verts[29], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[11], Johnson_39_elongated_pentagonal_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[4], Johnson_39_elongated_pentagonal_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[13], Johnson_39_elongated_pentagonal_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[19], Johnson_39_elongated_pentagonal_gyrobicupola_verts[21], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[21], Johnson_39_elongated_pentagonal_gyrobicupola_verts[26], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[26], Johnson_39_elongated_pentagonal_gyrobicupola_verts[19], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[20], Johnson_39_elongated_pentagonal_gyrobicupola_verts[28], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[28], Johnson_39_elongated_pentagonal_gyrobicupola_verts[24], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[24], Johnson_39_elongated_pentagonal_gyrobicupola_verts[20], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[12], Johnson_39_elongated_pentagonal_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[15], Johnson_39_elongated_pentagonal_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[7], Johnson_39_elongated_pentagonal_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[6], Johnson_39_elongated_pentagonal_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[2], Johnson_39_elongated_pentagonal_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[0], Johnson_39_elongated_pentagonal_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[9], Johnson_39_elongated_pentagonal_gyrobicupola_verts[5], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[5], Johnson_39_elongated_pentagonal_gyrobicupola_verts[1], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[1], Johnson_39_elongated_pentagonal_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[10], Johnson_39_elongated_pentagonal_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[3], Johnson_39_elongated_pentagonal_gyrobicupola_verts[8], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[8], Johnson_39_elongated_pentagonal_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[18], Johnson_39_elongated_pentagonal_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[16], Johnson_39_elongated_pentagonal_gyrobicupola_verts[25], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[25], Johnson_39_elongated_pentagonal_gyrobicupola_verts[18], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[23], Johnson_39_elongated_pentagonal_gyrobicupola_verts[29], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[29], Johnson_39_elongated_pentagonal_gyrobicupola_verts[27], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[27], Johnson_39_elongated_pentagonal_gyrobicupola_verts[23], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[17], Johnson_39_elongated_pentagonal_gyrobicupola_verts[22], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[22], Johnson_39_elongated_pentagonal_gyrobicupola_verts[14], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[14], Johnson_39_elongated_pentagonal_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[11], Johnson_39_elongated_pentagonal_gyrobicupola_verts[6], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[0], Johnson_39_elongated_pentagonal_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[19], Johnson_39_elongated_pentagonal_gyrobicupola_verts[11], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[13], Johnson_39_elongated_pentagonal_gyrobicupola_verts[21], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[20], Johnson_39_elongated_pentagonal_gyrobicupola_verts[19], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[26], Johnson_39_elongated_pentagonal_gyrobicupola_verts[28], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[12], Johnson_39_elongated_pentagonal_gyrobicupola_verts[20], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[24], Johnson_39_elongated_pentagonal_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[6], Johnson_39_elongated_pentagonal_gyrobicupola_verts[12], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[7], Johnson_39_elongated_pentagonal_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[9], Johnson_39_elongated_pentagonal_gyrobicupola_verts[17], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[14], Johnson_39_elongated_pentagonal_gyrobicupola_verts[5], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[10], Johnson_39_elongated_pentagonal_gyrobicupola_verts[9], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[1], Johnson_39_elongated_pentagonal_gyrobicupola_verts[3], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[18], Johnson_39_elongated_pentagonal_gyrobicupola_verts[10], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[8], Johnson_39_elongated_pentagonal_gyrobicupola_verts[16], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[23], Johnson_39_elongated_pentagonal_gyrobicupola_verts[18], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[25], Johnson_39_elongated_pentagonal_gyrobicupola_verts[29], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[17], Johnson_39_elongated_pentagonal_gyrobicupola_verts[23], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[27], Johnson_39_elongated_pentagonal_gyrobicupola_verts[22], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[24], Johnson_39_elongated_pentagonal_gyrobicupola_verts[25], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[16], Johnson_39_elongated_pentagonal_gyrobicupola_verts[15], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[8], Johnson_39_elongated_pentagonal_gyrobicupola_verts[7], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[3], Johnson_39_elongated_pentagonal_gyrobicupola_verts[2], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[1], Johnson_39_elongated_pentagonal_gyrobicupola_verts[0], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[5], Johnson_39_elongated_pentagonal_gyrobicupola_verts[4], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[14], Johnson_39_elongated_pentagonal_gyrobicupola_verts[13], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[22], Johnson_39_elongated_pentagonal_gyrobicupola_verts[21], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[27], Johnson_39_elongated_pentagonal_gyrobicupola_verts[26], RadEdg }
  cylinder { Johnson_39_elongated_pentagonal_gyrobicupola_verts[29], Johnson_39_elongated_pentagonal_gyrobicupola_verts[28], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[17];
 #local P1 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[9];
 #local P2 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[10];
 #local P3 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[18];
 #local P4 = Johnson_39_elongated_pentagonal_gyrobicupola_verts[23];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_40_elongated_pentagonal_orthocupolarotunda_verts = array[35]
{
<-1.055180, -0.061289, -0.047893>,
<-0.934164, 0.280612, 0.409939>,
<-0.859454, -0.241561, -0.567840>,
<-0.777777, -0.505581, 0.210572>,
<-0.776073, 0.311702, -0.400212>,
<-0.656761, -0.163679, 0.668404>,
<-0.655057, 0.653604, 0.057620>,
<-0.582051, -0.685853, -0.309375>,
<-0.542629, 0.653549, 0.630780>,
<-0.421745, -0.191346, -0.951300>,
<-0.400139, -0.685942, 0.618017>,
<-0.338365, 0.361918, -0.783672>,
<-0.265226, 0.209257, 0.889245>,
<-0.144342, -0.635637, -0.692835>,
<-0.142556, 0.915126, -0.042884>,
<-0.083446, -0.977628, -0.223275>,
<-0.030129, 0.915071, 0.530275>,
<0.028982, -0.977682, 0.349884>,
<0.053170, 0.734854, -0.562831>,
<0.090755, 0.070177, -1.051805>,
<0.149998, -0.635781, 0.807716>,
<0.233378, -0.082518, 0.975345>,
<0.247274, 0.470780, 0.788741>,
<0.368158, -0.374115, -0.793339>
<0.407580, 0.965287, 0.146815>,
<0.466690, -0.927467, -0.033576>,
<0.482290, 0.443114, -0.830964>,
<0.603306, 0.785015, -0.373132>,
<0.662498, -0.374258, 0.707212>,
<0.684983, 0.520995, 0.405281>,
<0.745797, -0.554475, -0.385895>,
<0.759693, -0.001178, -0.572498>,
<0.858225, -0.554530, 0.187265>,
<0.880709, 0.340724, -0.114666>,
<0.941605, -0.001267, 0.354893>,
}
#declare P0 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6];
#declare P1 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14];
#declare P2 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 35)
 #declare Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[Num] = vtransform(Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_40_elongated_pentagonal_orthocupolarotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_40_elongated_pentagonal_orthocupolarotunda_obj = mesh2 {
 vertex_vectors {
  35,
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[0],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[1],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[2],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[3],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[5],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[7],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[8],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[9],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[10],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[12],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[13],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[15],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[16],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[17],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[19],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[20],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[21],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[22],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[23],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[24],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[25],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[26],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[27],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[28],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[29],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[30],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[31],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[32],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[33],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[34]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  66,
  <6, 1, 8>, 0,
  <14, 16, 24>, 0,
  <18, 27, 26>, 0,
  <11, 19, 9>, 0,
  <4, 2, 0>, 0,
  <20, 10, 17>, 0,
  <10, 5, 3>, 0,
  <17, 15, 25>, 0,
  <15, 7, 13>, 0,
  <25, 30, 32>, 0,
  <30, 23, 31>, 0,
  <32, 34, 28>, 0,
  <34, 33, 29>, 0,
  <28, 21, 20>, 0,
  <21, 22, 12>, 0,
  <6, 4, 0>, 1,
  <6, 0, 1>, 1,
  <14, 6, 8>, 1,
  <14, 8, 16>, 1,
  <18, 14, 24>, 1,
  <18, 24, 27>, 1,
  <11, 18, 26>, 1,
  <11, 26, 19>, 1,
  <4, 11, 9>, 1,
  <4, 9, 2>, 1,
  <26, 31, 23>, 1,
  <26, 23, 19>, 1,
  <19, 23, 13>, 1,
  <19, 13, 9>, 1,
  <9, 13, 7>, 1,
  <9, 7, 2>, 1,
  <2, 7, 3>, 1,
  <2, 3, 0>, 1,
  <0, 3, 5>, 1,
  <0, 5, 1>, 1,
  <1, 5, 12>, 1,
  <1, 12, 8>, 1,
  <8, 12, 22>, 1,
  <8, 22, 16>, 1,
  <16, 22, 29>, 1,
  <16, 29, 24>, 1,
  <24, 29, 33>, 1,
  <24, 33, 27>, 1,
  <27, 33, 31>, 1,
  <27, 31, 26>, 1,
  <4, 6, 14>, 2,
  <4, 14, 18>, 2,
  <4, 18, 11>, 2,
  <20, 17, 25>, 2,
  <20, 25, 32>, 2,
  <20, 32, 28>, 2,
  <20, 21, 12>, 2,
  <20, 12, 5>, 2,
  <20, 5, 10>, 2,
  <17, 10, 3>, 2,
  <17, 3, 7>, 2,
  <17, 7, 15>, 2,
  <25, 15, 13>, 2,
  <25, 13, 23>, 2,
  <25, 23, 30>, 2,
  <32, 30, 31>, 2,
  <32, 31, 33>, 2,
  <32, 33, 34>, 2,
  <28, 34, 29>, 2,
  <28, 29, 22>, 2,
  <28, 22, 21>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6];
 #local P1 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14];
 #local P2 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18];
 #local P3 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11];
 #local P4 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_40_elongated_pentagonal_orthocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_40_elongated_pentagonal_orthocupolarotunda_obj }
#end
#end

#macro Johnson_40_elongated_pentagonal_orthocupolarotunda_faces2(OnPlane)
#local Johnson_40_elongated_pentagonal_orthocupolarotunda_obj = mesh2 {
 vertex_vectors {
  35,
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[0],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[1],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[2],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[3],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[5],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[7],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[8],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[9],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[10],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[12],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[13],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[15],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[16],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[17],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[19],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[20],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[21],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[22],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[23],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[24],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[25],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[26],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[27],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[28],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[29],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[30],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[31],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[32],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[33],
  Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[34]
 }
 face_indices {
  66,
  <6, 1, 8>,
  <14, 16, 24>,
  <18, 27, 26>,
  <11, 19, 9>,
  <4, 2, 0>,
  <20, 10, 17>,
  <10, 5, 3>,
  <17, 15, 25>,
  <15, 7, 13>,
  <25, 30, 32>,
  <30, 23, 31>,
  <32, 34, 28>,
  <34, 33, 29>,
  <28, 21, 20>,
  <21, 22, 12>,
  <6, 4, 0>,
  <6, 0, 1>,
  <14, 6, 8>,
  <14, 8, 16>,
  <18, 14, 24>,
  <18, 24, 27>,
  <11, 18, 26>,
  <11, 26, 19>,
  <4, 11, 9>,
  <4, 9, 2>,
  <26, 31, 23>,
  <26, 23, 19>,
  <19, 23, 13>,
  <19, 13, 9>,
  <9, 13, 7>,
  <9, 7, 2>,
  <2, 7, 3>,
  <2, 3, 0>,
  <0, 3, 5>,
  <0, 5, 1>,
  <1, 5, 12>,
  <1, 12, 8>,
  <8, 12, 22>,
  <8, 22, 16>,
  <16, 22, 29>,
  <16, 29, 24>,
  <24, 29, 33>,
  <24, 33, 27>,
  <27, 33, 31>,
  <27, 31, 26>,
  <4, 6, 14>,
  <4, 14, 18>,
  <4, 18, 11>,
  <20, 17, 25>,
  <20, 25, 32>,
  <20, 32, 28>,
  <20, 21, 12>,
  <20, 12, 5>,
  <20, 5, 10>,
  <17, 10, 3>,
  <17, 3, 7>,
  <17, 7, 15>,
  <25, 15, 13>,
  <25, 13, 23>,
  <25, 23, 30>,
  <32, 30, 31>,
  <32, 31, 33>,
  <32, 33, 34>,
  <28, 34, 29>,
  <28, 29, 22>,
  <28, 22, 21>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6];
 #local P1 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14];
 #local P2 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18];
 #local P3 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11];
 #local P4 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_40_elongated_pentagonal_orthocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_40_elongated_pentagonal_orthocupolarotunda_obj }
#end
#end

#macro Johnson_40_elongated_pentagonal_orthocupolarotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[0], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[1], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[2], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[3], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[5], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[7], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[8], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[9], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[10], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[12], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[13], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[15], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[16], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[17], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[19], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[20], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[21], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[22], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[23], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[24], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[25], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[26], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[27], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[28], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[29], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[30], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[31], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[32], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[33], RadVer }
  sphere { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[34], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[1], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[8], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[16], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[24], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[27], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[27], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[26], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[26], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[19], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[9], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[2], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[0], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[20], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[10], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[17], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[10], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[5], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[3], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[17], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[15], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[25], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[25], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[15], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[7], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[13], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[25], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[30], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[30], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[32], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[32], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[25], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[30], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[23], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[31], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[31], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[30], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[32], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[34], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[34], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[28], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[28], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[32], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[34], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[33], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[33], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[29], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[29], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[34], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[28], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[21], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[20], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[28], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[21], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[22], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[12], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[0], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[8], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[24], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[27], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[26], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[9], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[26], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[31], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[23], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[23], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[13], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[7], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[7], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[3], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[5], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[5], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[12], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[22], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[22], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[29], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[29], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[33], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[27], RadEdg }
  cylinder { Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[33], Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[31], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[6];
 #local P1 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[14];
 #local P2 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[18];
 #local P3 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[11];
 #local P4 = Johnson_40_elongated_pentagonal_orthocupolarotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts = array[35]
{
<-1.045033, 0.161365, 0.036367>,
<-0.919366, 0.043922, -0.521815>,
<-0.855707, -0.369212, 0.190625>,
<-0.830432, 0.382234, 0.532668>,
<-0.730040, -0.486655, -0.367556>,
<-0.711442, 0.528940, -0.271461>,
<-0.641106, -0.148342, 0.686927>,
<-0.544409, -0.844483, 0.055116>,
<-0.501432, 0.074765, -0.928671>,
<-0.496841, 0.749809, 0.224841>,
<-0.357534, 0.622166, 0.777518>,
<-0.312106, -0.455811, -0.774412>,
<-0.293508, 0.559783, -0.678317>,
<-0.197177, -0.487108, 0.858148>,
<-0.168208, 0.091590, 0.931777>,
<-0.137415, -0.917347, 0.467667>,
<-0.011748, -1.034790, -0.090514>,
<0.049132, 0.242114, -1.028796>,
<0.053724, 0.917158, 0.124716>,
<0.131823, -0.794577, -0.603191>,
<0.179390, 0.799715, -0.433466>,
<0.193031, 0.789515, 0.677394>,
<0.238459, -0.288463, -0.874537>,
<0.335483, -0.677415, 0.712518>
<0.382357, 0.258938, 0.831652>,
<0.522031, 0.482046, -0.783946>,
<0.538816, -0.867441, -0.190639>,
<0.610965, 0.820358, 0.270538>,
<0.693655, -0.216333, 0.696143>,
<0.711357, -0.048531, -0.629687>,
<0.736632, 0.702915, -0.287644>,
<0.753417, -0.646572, 0.305662>,
<0.800291, 0.289782, 0.424796>,
<0.896988, -0.406359, -0.207015>,
<0.925958, 0.172339, -0.133386>,
}
#declare P0 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9];
#declare P1 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18];
#declare P2 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 35)
 #declare Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[Num] = vtransform(Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_41_elongated_pentagonal_gyrocupolarotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_41_elongated_pentagonal_gyrocupolarotunda_obj = mesh2 {
 vertex_vectors {
  35,
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[0],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[1],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[2],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[3],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[4],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[6],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[7],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[8],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[10],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[11],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[13],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[14],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[15],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[16],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[17],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[19],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[21],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[22],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[23],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[24],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[25],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[26],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[27],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[28],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[29],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[30],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[31],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[32],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[33],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[34]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  66,
  <9, 3, 10>, 0,
  <18, 21, 27>, 0,
  <20, 30, 25>, 0,
  <12, 17, 8>, 0,
  <5, 1, 0>, 0,
  <15, 7, 16>, 0,
  <7, 2, 4>, 0,
  <16, 19, 26>, 0,
  <19, 11, 22>, 0,
  <26, 33, 31>, 0,
  <33, 29, 34>, 0,
  <31, 28, 23>, 0,
  <28, 32, 24>, 0,
  <23, 13, 15>, 0,
  <13, 14, 6>, 0,
  <9, 5, 0>, 1,
  <9, 0, 3>, 1,
  <18, 9, 10>, 1,
  <18, 10, 21>, 1,
  <20, 18, 27>, 1,
  <20, 27, 30>, 1,
  <12, 20, 25>, 1,
  <12, 25, 17>, 1,
  <5, 12, 8>, 1,
  <5, 8, 1>, 1,
  <25, 29, 22>, 1,
  <25, 22, 17>, 1,
  <17, 22, 11>, 1,
  <17, 11, 8>, 1,
  <8, 11, 4>, 1,
  <8, 4, 1>, 1,
  <1, 4, 2>, 1,
  <1, 2, 0>, 1,
  <0, 2, 6>, 1,
  <0, 6, 3>, 1,
  <3, 6, 14>, 1,
  <3, 14, 10>, 1,
  <10, 14, 24>, 1,
  <10, 24, 21>, 1,
  <21, 24, 32>, 1,
  <21, 32, 27>, 1,
  <27, 32, 34>, 1,
  <27, 34, 30>, 1,
  <30, 34, 29>, 1,
  <30, 29, 25>, 1,
  <5, 9, 18>, 2,
  <5, 18, 20>, 2,
  <5, 20, 12>, 2,
  <15, 16, 26>, 2,
  <15, 26, 31>, 2,
  <15, 31, 23>, 2,
  <15, 13, 6>, 2,
  <15, 6, 2>, 2,
  <15, 2, 7>, 2,
  <16, 7, 4>, 2,
  <16, 4, 11>, 2,
  <16, 11, 19>, 2,
  <26, 19, 22>, 2,
  <26, 22, 29>, 2,
  <26, 29, 33>, 2,
  <31, 33, 34>, 2,
  <31, 34, 32>, 2,
  <31, 32, 28>, 2,
  <23, 28, 24>, 2,
  <23, 24, 14>, 2,
  <23, 14, 13>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9];
 #local P1 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18];
 #local P2 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20];
 #local P3 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12];
 #local P4 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_41_elongated_pentagonal_gyrocupolarotunda_obj }
#end
#end

#macro Johnson_41_elongated_pentagonal_gyrocupolarotunda_faces2(OnPlane)
#local Johnson_41_elongated_pentagonal_gyrocupolarotunda_obj = mesh2 {
 vertex_vectors {
  35,
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[0],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[1],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[2],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[3],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[4],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[6],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[7],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[8],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[10],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[11],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[13],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[14],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[15],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[16],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[17],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[19],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[21],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[22],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[23],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[24],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[25],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[26],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[27],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[28],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[29],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[30],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[31],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[32],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[33],
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[34]
 }
 face_indices {
  66,
  <9, 3, 10>,
  <18, 21, 27>,
  <20, 30, 25>,
  <12, 17, 8>,
  <5, 1, 0>,
  <15, 7, 16>,
  <7, 2, 4>,
  <16, 19, 26>,
  <19, 11, 22>,
  <26, 33, 31>,
  <33, 29, 34>,
  <31, 28, 23>,
  <28, 32, 24>,
  <23, 13, 15>,
  <13, 14, 6>,
  <9, 5, 0>,
  <9, 0, 3>,
  <18, 9, 10>,
  <18, 10, 21>,
  <20, 18, 27>,
  <20, 27, 30>,
  <12, 20, 25>,
  <12, 25, 17>,
  <5, 12, 8>,
  <5, 8, 1>,
  <25, 29, 22>,
  <25, 22, 17>,
  <17, 22, 11>,
  <17, 11, 8>,
  <8, 11, 4>,
  <8, 4, 1>,
  <1, 4, 2>,
  <1, 2, 0>,
  <0, 2, 6>,
  <0, 6, 3>,
  <3, 6, 14>,
  <3, 14, 10>,
  <10, 14, 24>,
  <10, 24, 21>,
  <21, 24, 32>,
  <21, 32, 27>,
  <27, 32, 34>,
  <27, 34, 30>,
  <30, 34, 29>,
  <30, 29, 25>,
  <5, 9, 18>,
  <5, 18, 20>,
  <5, 20, 12>,
  <15, 16, 26>,
  <15, 26, 31>,
  <15, 31, 23>,
  <15, 13, 6>,
  <15, 6, 2>,
  <15, 2, 7>,
  <16, 7, 4>,
  <16, 4, 11>,
  <16, 11, 19>,
  <26, 19, 22>,
  <26, 22, 29>,
  <26, 29, 33>,
  <31, 33, 34>,
  <31, 34, 32>,
  <31, 32, 28>,
  <23, 28, 24>,
  <23, 24, 14>,
  <23, 14, 13>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9];
 #local P1 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18];
 #local P2 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20];
 #local P3 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12];
 #local P4 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_41_elongated_pentagonal_gyrocupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_41_elongated_pentagonal_gyrocupolarotunda_obj }
#end
#end

#macro Johnson_41_elongated_pentagonal_gyrocupolarotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[0], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[1], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[2], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[3], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[4], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[6], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[7], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[8], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[10], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[11], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[13], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[14], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[15], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[16], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[17], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[19], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[21], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[22], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[23], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[24], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[25], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[26], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[27], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[28], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[29], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[30], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[31], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[32], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[33], RadVer }
  sphere { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[34], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[3], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[10], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[21], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[27], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[27], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[30], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[30], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[25], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[25], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[17], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[8], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[1], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[0], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[15], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[7], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[16], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[7], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[2], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[4], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[16], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[19], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[26], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[26], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[19], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[11], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[22], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[26], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[33], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[33], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[31], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[31], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[26], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[33], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[29], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[29], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[34], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[34], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[33], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[31], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[28], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[28], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[23], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[31], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[28], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[32], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[32], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[24], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[28], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[23], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[13], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[15], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[13], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[14], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[6], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[0], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[10], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[27], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[30], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[25], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[8], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[25], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[29], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[29], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[22], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[11], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[11], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[4], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[2], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[2], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[6], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[14], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[14], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[24], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[32], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[27], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[32], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[34], RadEdg }
  cylinder { Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[34], Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[30], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[9];
 #local P1 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[18];
 #local P2 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[20];
 #local P3 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[12];
 #local P4 = Johnson_41_elongated_pentagonal_gyrocupolarotunda_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_42_elongated_pentagonal_orthobirotunda_verts = array[40]
{
<-1.094229, 0.091579, -0.183298>,
<-0.983491, -0.294880, 0.177777>,
<-0.974620, -0.408146, -0.350504>,
<-0.882171, 0.554599, -0.002654>,
<-0.873301, 0.441333, -0.530935>,
<-0.702994, -0.070704, 0.581578>,
<-0.679771, -0.367238, -0.801479>,
<-0.640375, 0.454303, 0.470066>,
<-0.617152, 0.157769, -0.912991>,
<-0.583386, -0.570429, 0.414373>,
<-0.569033, -0.753697, -0.440404>,
<-0.419447, 0.804058, 0.122429>,
<-0.405095, 0.620789, -0.732347>,
<-0.327237, -0.853993, 0.032316>,
<-0.251159, -0.061675, 0.877809>,
<-0.211565, -0.187782, -1.002892>,
<-0.188540, 0.463332, 0.766296>,
<-0.131551, -0.561400, 0.710603>,
<-0.124598, 0.844965, -0.328546>,
<-0.032387, -0.813085, -0.418660>,
<0.032387, 0.813086, 0.418659>,
<0.124598, -0.844964, 0.328546>,
<0.131551, 0.561401, -0.710603>,
<0.188540, -0.463331, -0.766296>
<0.237051, -0.270491, 0.977985>,
<0.251159, 0.061676, -0.877809>,
<0.327237, 0.853994, -0.032316>,
<0.338370, 0.578988, 0.797554>,
<0.419448, -0.804057, -0.122429>,
<0.583386, 0.570429, -0.414373>,
<0.601401, 0.125461, 0.928384>,
<0.640375, -0.454302, -0.470066>,
<0.651509, -0.729308, 0.359803>,
<0.702994, 0.070705, -0.581579>,
<0.721009, -0.374264, 0.761179>,
<0.815447, 0.645178, 0.067860>,
<0.822328, 0.475215, 0.580748>,
<1.008977, -0.163393, -0.202684>,
<1.015858, -0.333356, 0.310203>,
<1.078477, 0.191651, 0.198691>,
}
#declare P0 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[0];
#declare P1 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[8];
#declare P2 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[2];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 40)
 #declare Johnson_42_elongated_pentagonal_orthobirotunda_verts[Num] = vtransform(Johnson_42_elongated_pentagonal_orthobirotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_42_elongated_pentagonal_orthobirotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_42_elongated_pentagonal_orthobirotunda_obj = mesh2 {
 vertex_vectors {
  40,
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[0],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[1],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[2],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[3],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[4],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[5],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[6],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[7],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[8],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[9],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[10],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[11],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[12],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[13],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[14],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[15],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[16],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[17],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[18],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[19],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[20],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[21],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[22],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[23],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[24],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[25],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[26],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[27],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[28],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[29],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[30],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[31],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[32],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[33],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[34],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[35],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[36],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[37],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[38],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[39]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  76,
  <0, 3, 4>, 0,
  <3, 7, 11>, 0,
  <4, 12, 8>, 0,
  <12, 18, 22>, 0,
  <8, 15, 6>, 0,
  <15, 25, 23>, 0,
  <6, 10, 2>, 0,
  <10, 19, 13>, 0,
  <2, 1, 0>, 0,
  <1, 9, 5>, 0,
  <30, 24, 34>, 0,
  <24, 14, 17>, 0,
  <34, 32, 38>, 0,
  <32, 21, 28>, 0,
  <38, 37, 39>, 0,
  <37, 31, 33>, 0,
  <39, 35, 36>, 0,
  <35, 29, 26>, 0,
  <36, 27, 30>, 0,
  <27, 20, 16>, 0,
  <23, 31, 28>, 1,
  <23, 28, 19>, 1,
  <19, 28, 21>, 1,
  <19, 21, 13>, 1,
  <13, 21, 17>, 1,
  <13, 17, 9>, 1,
  <9, 17, 14>, 1,
  <9, 14, 5>, 1,
  <5, 14, 16>, 1,
  <5, 16, 7>, 1,
  <7, 16, 20>, 1,
  <7, 20, 11>, 1,
  <11, 20, 26>, 1,
  <11, 26, 18>, 1,
  <18, 26, 29>, 1,
  <18, 29, 22>, 1,
  <22, 29, 33>, 1,
  <22, 33, 25>, 1,
  <25, 33, 31>, 1,
  <25, 31, 23>, 1,
  <0, 4, 8>, 2,
  <0, 8, 6>, 2,
  <0, 6, 2>, 2,
  <0, 1, 5>, 2,
  <0, 5, 7>, 2,
  <0, 7, 3>, 2,
  <4, 3, 11>, 2,
  <4, 11, 18>, 2,
  <4, 18, 12>, 2,
  <8, 12, 22>, 2,
  <8, 22, 25>, 2,
  <8, 25, 15>, 2,
  <6, 15, 23>, 2,
  <6, 23, 19>, 2,
  <6, 19, 10>, 2,
  <2, 10, 13>, 2,
  <2, 13, 9>, 2,
  <2, 9, 1>, 2,
  <30, 34, 38>, 2,
  <30, 38, 39>, 2,
  <30, 39, 36>, 2,
  <30, 27, 16>, 2,
  <30, 16, 14>, 2,
  <30, 14, 24>, 2,
  <34, 24, 17>, 2,
  <34, 17, 21>, 2,
  <34, 21, 32>, 2,
  <38, 32, 28>, 2,
  <38, 28, 31>, 2,
  <38, 31, 37>, 2,
  <39, 37, 33>, 2,
  <39, 33, 29>, 2,
  <39, 29, 35>, 2,
  <36, 35, 26>, 2,
  <36, 26, 20>, 2,
  <36, 20, 27>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[0];
 #local P1 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[8];
 #local P2 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[2];
 #local P3 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[6];
 #local P4 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_42_elongated_pentagonal_orthobirotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_42_elongated_pentagonal_orthobirotunda_obj }
#end
#end

#macro Johnson_42_elongated_pentagonal_orthobirotunda_faces2(OnPlane)
#local Johnson_42_elongated_pentagonal_orthobirotunda_obj = mesh2 {
 vertex_vectors {
  40,
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[0],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[1],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[2],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[3],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[4],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[5],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[6],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[7],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[8],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[9],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[10],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[11],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[12],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[13],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[14],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[15],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[16],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[17],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[18],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[19],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[20],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[21],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[22],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[23],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[24],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[25],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[26],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[27],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[28],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[29],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[30],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[31],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[32],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[33],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[34],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[35],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[36],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[37],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[38],
  Johnson_42_elongated_pentagonal_orthobirotunda_verts[39]
 }
 face_indices {
  76,
  <0, 3, 4>,
  <3, 7, 11>,
  <4, 12, 8>,
  <12, 18, 22>,
  <8, 15, 6>,
  <15, 25, 23>,
  <6, 10, 2>,
  <10, 19, 13>,
  <2, 1, 0>,
  <1, 9, 5>,
  <30, 24, 34>,
  <24, 14, 17>,
  <34, 32, 38>,
  <32, 21, 28>,
  <38, 37, 39>,
  <37, 31, 33>,
  <39, 35, 36>,
  <35, 29, 26>,
  <36, 27, 30>,
  <27, 20, 16>,
  <23, 31, 28>,
  <23, 28, 19>,
  <19, 28, 21>,
  <19, 21, 13>,
  <13, 21, 17>,
  <13, 17, 9>,
  <9, 17, 14>,
  <9, 14, 5>,
  <5, 14, 16>,
  <5, 16, 7>,
  <7, 16, 20>,
  <7, 20, 11>,
  <11, 20, 26>,
  <11, 26, 18>,
  <18, 26, 29>,
  <18, 29, 22>,
  <22, 29, 33>,
  <22, 33, 25>,
  <25, 33, 31>,
  <25, 31, 23>,
  <0, 4, 8>,
  <0, 8, 6>,
  <0, 6, 2>,
  <0, 1, 5>,
  <0, 5, 7>,
  <0, 7, 3>,
  <4, 3, 11>,
  <4, 11, 18>,
  <4, 18, 12>,
  <8, 12, 22>,
  <8, 22, 25>,
  <8, 25, 15>,
  <6, 15, 23>,
  <6, 23, 19>,
  <6, 19, 10>,
  <2, 10, 13>,
  <2, 13, 9>,
  <2, 9, 1>,
  <30, 34, 38>,
  <30, 38, 39>,
  <30, 39, 36>,
  <30, 27, 16>,
  <30, 16, 14>,
  <30, 14, 24>,
  <34, 24, 17>,
  <34, 17, 21>,
  <34, 21, 32>,
  <38, 32, 28>,
  <38, 28, 31>,
  <38, 31, 37>,
  <39, 37, 33>,
  <39, 33, 29>,
  <39, 29, 35>,
  <36, 35, 26>,
  <36, 26, 20>,
  <36, 20, 27>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[0];
 #local P1 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[8];
 #local P2 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[2];
 #local P3 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[6];
 #local P4 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_42_elongated_pentagonal_orthobirotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_42_elongated_pentagonal_orthobirotunda_obj }
#end
#end

#macro Johnson_42_elongated_pentagonal_orthobirotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[0], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[1], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[2], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[3], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[4], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[5], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[6], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[7], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[8], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[9], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[10], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[11], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[12], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[13], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[14], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[15], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[16], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[17], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[18], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[19], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[20], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[21], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[22], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[23], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[24], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[25], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[26], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[27], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[28], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[29], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[30], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[31], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[32], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[33], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[34], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[35], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[36], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[37], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[38], RadVer }
  sphere { Johnson_42_elongated_pentagonal_orthobirotunda_verts[39], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[0], Johnson_42_elongated_pentagonal_orthobirotunda_verts[3], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[3], Johnson_42_elongated_pentagonal_orthobirotunda_verts[4], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[4], Johnson_42_elongated_pentagonal_orthobirotunda_verts[0], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[3], Johnson_42_elongated_pentagonal_orthobirotunda_verts[7], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[7], Johnson_42_elongated_pentagonal_orthobirotunda_verts[11], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[11], Johnson_42_elongated_pentagonal_orthobirotunda_verts[3], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[4], Johnson_42_elongated_pentagonal_orthobirotunda_verts[12], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[12], Johnson_42_elongated_pentagonal_orthobirotunda_verts[8], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[8], Johnson_42_elongated_pentagonal_orthobirotunda_verts[4], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[12], Johnson_42_elongated_pentagonal_orthobirotunda_verts[18], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[18], Johnson_42_elongated_pentagonal_orthobirotunda_verts[22], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[22], Johnson_42_elongated_pentagonal_orthobirotunda_verts[12], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[8], Johnson_42_elongated_pentagonal_orthobirotunda_verts[15], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[15], Johnson_42_elongated_pentagonal_orthobirotunda_verts[6], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[6], Johnson_42_elongated_pentagonal_orthobirotunda_verts[8], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[15], Johnson_42_elongated_pentagonal_orthobirotunda_verts[25], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[25], Johnson_42_elongated_pentagonal_orthobirotunda_verts[23], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[23], Johnson_42_elongated_pentagonal_orthobirotunda_verts[15], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[6], Johnson_42_elongated_pentagonal_orthobirotunda_verts[10], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[10], Johnson_42_elongated_pentagonal_orthobirotunda_verts[2], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[2], Johnson_42_elongated_pentagonal_orthobirotunda_verts[6], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[10], Johnson_42_elongated_pentagonal_orthobirotunda_verts[19], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[19], Johnson_42_elongated_pentagonal_orthobirotunda_verts[13], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[13], Johnson_42_elongated_pentagonal_orthobirotunda_verts[10], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[2], Johnson_42_elongated_pentagonal_orthobirotunda_verts[1], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[1], Johnson_42_elongated_pentagonal_orthobirotunda_verts[0], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[0], Johnson_42_elongated_pentagonal_orthobirotunda_verts[2], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[1], Johnson_42_elongated_pentagonal_orthobirotunda_verts[9], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[9], Johnson_42_elongated_pentagonal_orthobirotunda_verts[5], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[5], Johnson_42_elongated_pentagonal_orthobirotunda_verts[1], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[30], Johnson_42_elongated_pentagonal_orthobirotunda_verts[24], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[24], Johnson_42_elongated_pentagonal_orthobirotunda_verts[34], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[34], Johnson_42_elongated_pentagonal_orthobirotunda_verts[30], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[24], Johnson_42_elongated_pentagonal_orthobirotunda_verts[14], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[14], Johnson_42_elongated_pentagonal_orthobirotunda_verts[17], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[17], Johnson_42_elongated_pentagonal_orthobirotunda_verts[24], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[34], Johnson_42_elongated_pentagonal_orthobirotunda_verts[32], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[32], Johnson_42_elongated_pentagonal_orthobirotunda_verts[38], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[38], Johnson_42_elongated_pentagonal_orthobirotunda_verts[34], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[32], Johnson_42_elongated_pentagonal_orthobirotunda_verts[21], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[21], Johnson_42_elongated_pentagonal_orthobirotunda_verts[28], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[28], Johnson_42_elongated_pentagonal_orthobirotunda_verts[32], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[38], Johnson_42_elongated_pentagonal_orthobirotunda_verts[37], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[37], Johnson_42_elongated_pentagonal_orthobirotunda_verts[39], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[39], Johnson_42_elongated_pentagonal_orthobirotunda_verts[38], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[37], Johnson_42_elongated_pentagonal_orthobirotunda_verts[31], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[31], Johnson_42_elongated_pentagonal_orthobirotunda_verts[33], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[33], Johnson_42_elongated_pentagonal_orthobirotunda_verts[37], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[39], Johnson_42_elongated_pentagonal_orthobirotunda_verts[35], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[35], Johnson_42_elongated_pentagonal_orthobirotunda_verts[36], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[36], Johnson_42_elongated_pentagonal_orthobirotunda_verts[39], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[35], Johnson_42_elongated_pentagonal_orthobirotunda_verts[29], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[29], Johnson_42_elongated_pentagonal_orthobirotunda_verts[26], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[26], Johnson_42_elongated_pentagonal_orthobirotunda_verts[35], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[36], Johnson_42_elongated_pentagonal_orthobirotunda_verts[27], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[27], Johnson_42_elongated_pentagonal_orthobirotunda_verts[30], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[30], Johnson_42_elongated_pentagonal_orthobirotunda_verts[36], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[27], Johnson_42_elongated_pentagonal_orthobirotunda_verts[20], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[20], Johnson_42_elongated_pentagonal_orthobirotunda_verts[16], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[16], Johnson_42_elongated_pentagonal_orthobirotunda_verts[27], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[23], Johnson_42_elongated_pentagonal_orthobirotunda_verts[31], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[31], Johnson_42_elongated_pentagonal_orthobirotunda_verts[28], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[28], Johnson_42_elongated_pentagonal_orthobirotunda_verts[19], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[19], Johnson_42_elongated_pentagonal_orthobirotunda_verts[23], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[21], Johnson_42_elongated_pentagonal_orthobirotunda_verts[13], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[21], Johnson_42_elongated_pentagonal_orthobirotunda_verts[17], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[17], Johnson_42_elongated_pentagonal_orthobirotunda_verts[9], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[9], Johnson_42_elongated_pentagonal_orthobirotunda_verts[13], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[14], Johnson_42_elongated_pentagonal_orthobirotunda_verts[5], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[14], Johnson_42_elongated_pentagonal_orthobirotunda_verts[16], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[16], Johnson_42_elongated_pentagonal_orthobirotunda_verts[7], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[7], Johnson_42_elongated_pentagonal_orthobirotunda_verts[5], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[20], Johnson_42_elongated_pentagonal_orthobirotunda_verts[11], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[20], Johnson_42_elongated_pentagonal_orthobirotunda_verts[26], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[26], Johnson_42_elongated_pentagonal_orthobirotunda_verts[18], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[18], Johnson_42_elongated_pentagonal_orthobirotunda_verts[11], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[29], Johnson_42_elongated_pentagonal_orthobirotunda_verts[22], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[29], Johnson_42_elongated_pentagonal_orthobirotunda_verts[33], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[33], Johnson_42_elongated_pentagonal_orthobirotunda_verts[25], RadEdg }
  cylinder { Johnson_42_elongated_pentagonal_orthobirotunda_verts[25], Johnson_42_elongated_pentagonal_orthobirotunda_verts[22], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[0];
 #local P1 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[8];
 #local P2 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[2];
 #local P3 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[6];
 #local P4 = Johnson_42_elongated_pentagonal_orthobirotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_43_elongated_pentagonal_gyrobirotunda_verts = array[40]
{
<-1.099924, -0.170755, -0.018241>,
<-1.015744, 0.184543, -0.416570>,
<-0.979069, 0.342745, 0.098809>,
<-0.891012, -0.645186, -0.170750>,
<-0.854337, -0.486985, 0.344629>,
<-0.754806, -0.070303, -0.815260>,
<-0.677717, -0.583103, -0.663335>,
<-0.658790, 0.343875, 0.534020>,
<-0.633951, 0.443197, -0.698209>,
<-0.581702, -0.168926, 0.685945>,
<-0.574610, 0.699173, 0.135692>,
<-0.432130, -0.899333, -0.300465>,
<-0.372790, -0.643357, 0.533436>,
<-0.361315, 0.761256, -0.356893>,
<-0.295924, -0.324449, -0.944974>,
<-0.185624, 0.480819, 0.756166>,
<-0.111851, -0.898203, 0.134746>,
<-0.108536, -0.031982, 0.908091>,
<-0.101444, 0.836117, 0.357838>,
<-0.100377, 0.506410, -0.755583>,
<0.100376, -0.506413, 0.755582>,
<0.101443, -0.836120, -0.357838>,
<0.108535, 0.031979, -0.908092>,
<0.111851, 0.898200, -0.134747>
<0.185623, -0.480822, -0.756167>,
<0.295923, 0.324447, 0.944974>,
<0.361314, -0.761258, 0.356892>,
<0.372789, 0.643354, -0.533437>,
<0.432130, 0.899331, 0.300464>,
<0.574609, -0.699176, -0.135692>,
<0.581701, 0.168923, -0.685946>,
<0.633950, -0.443199, 0.698208>,
<0.658789, -0.343878, -0.534021>,
<0.677716, 0.583101, 0.663334>,
<0.754804, 0.070300, 0.815259>,
<0.854336, 0.486982, -0.344629>,
<0.891011, 0.645184, 0.170750>,
<0.979068, -0.342747, -0.098810>,
<1.015743, -0.184545, 0.416569>,
<1.099923, 0.170753, 0.018241>,
}
#declare P0 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0];
#declare P1 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1];
#declare P2 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 40)
 #declare Johnson_43_elongated_pentagonal_gyrobirotunda_verts[Num] = vtransform(Johnson_43_elongated_pentagonal_gyrobirotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_43_elongated_pentagonal_gyrobirotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_43_elongated_pentagonal_gyrobirotunda_obj = mesh2 {
 vertex_vectors {
  40,
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[2],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[4],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[7],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[8],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[9],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[10],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[11],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[12],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[13],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[14],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[15],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[16],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[17],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[18],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[19],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[20],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[21],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[22],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[23],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[24],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[25],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[26],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[27],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[28],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[29],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[30],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[31],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[32],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[33],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[34],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[35],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[36],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[37],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[38],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[39]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  76,
  <0, 2, 1>, 0,
  <2, 7, 10>, 0,
  <1, 8, 5>, 0,
  <8, 13, 19>, 0,
  <5, 14, 6>, 0,
  <14, 22, 24>, 0,
  <6, 11, 3>, 0,
  <11, 21, 16>, 0,
  <3, 4, 0>, 0,
  <4, 12, 9>, 0,
  <33, 25, 34>, 0,
  <25, 15, 17>, 0,
  <34, 31, 38>, 0,
  <31, 20, 26>, 0,
  <38, 37, 39>, 0,
  <37, 29, 32>, 0,
  <39, 35, 36>, 0,
  <35, 30, 27>, 0,
  <36, 28, 33>, 0,
  <28, 23, 18>, 0,
  <24, 32, 29>, 1,
  <24, 29, 21>, 1,
  <21, 29, 26>, 1,
  <21, 26, 16>, 1,
  <16, 26, 20>, 1,
  <16, 20, 12>, 1,
  <12, 20, 17>, 1,
  <12, 17, 9>, 1,
  <9, 17, 15>, 1,
  <9, 15, 7>, 1,
  <7, 15, 18>, 1,
  <7, 18, 10>, 1,
  <10, 18, 23>, 1,
  <10, 23, 13>, 1,
  <13, 23, 27>, 1,
  <13, 27, 19>, 1,
  <19, 27, 30>, 1,
  <19, 30, 22>, 1,
  <22, 30, 32>, 1,
  <22, 32, 24>, 1,
  <0, 1, 5>, 2,
  <0, 5, 6>, 2,
  <0, 6, 3>, 2,
  <0, 4, 9>, 2,
  <0, 9, 7>, 2,
  <0, 7, 2>, 2,
  <1, 2, 10>, 2,
  <1, 10, 13>, 2,
  <1, 13, 8>, 2,
  <5, 8, 19>, 2,
  <5, 19, 22>, 2,
  <5, 22, 14>, 2,
  <6, 14, 24>, 2,
  <6, 24, 21>, 2,
  <6, 21, 11>, 2,
  <3, 11, 16>, 2,
  <3, 16, 12>, 2,
  <3, 12, 4>, 2,
  <33, 34, 38>, 2,
  <33, 38, 39>, 2,
  <33, 39, 36>, 2,
  <33, 28, 18>, 2,
  <33, 18, 15>, 2,
  <33, 15, 25>, 2,
  <34, 25, 17>, 2,
  <34, 17, 20>, 2,
  <34, 20, 31>, 2,
  <38, 31, 26>, 2,
  <38, 26, 29>, 2,
  <38, 29, 37>, 2,
  <39, 37, 32>, 2,
  <39, 32, 30>, 2,
  <39, 30, 35>, 2,
  <36, 35, 27>, 2,
  <36, 27, 23>, 2,
  <36, 23, 28>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0];
 #local P1 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1];
 #local P2 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5];
 #local P3 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6];
 #local P4 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_43_elongated_pentagonal_gyrobirotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_43_elongated_pentagonal_gyrobirotunda_obj }
#end
#end

#macro Johnson_43_elongated_pentagonal_gyrobirotunda_faces2(OnPlane)
#local Johnson_43_elongated_pentagonal_gyrobirotunda_obj = mesh2 {
 vertex_vectors {
  40,
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[2],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[4],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[7],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[8],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[9],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[10],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[11],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[12],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[13],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[14],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[15],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[16],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[17],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[18],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[19],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[20],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[21],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[22],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[23],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[24],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[25],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[26],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[27],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[28],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[29],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[30],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[31],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[32],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[33],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[34],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[35],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[36],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[37],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[38],
  Johnson_43_elongated_pentagonal_gyrobirotunda_verts[39]
 }
 face_indices {
  76,
  <0, 2, 1>,
  <2, 7, 10>,
  <1, 8, 5>,
  <8, 13, 19>,
  <5, 14, 6>,
  <14, 22, 24>,
  <6, 11, 3>,
  <11, 21, 16>,
  <3, 4, 0>,
  <4, 12, 9>,
  <33, 25, 34>,
  <25, 15, 17>,
  <34, 31, 38>,
  <31, 20, 26>,
  <38, 37, 39>,
  <37, 29, 32>,
  <39, 35, 36>,
  <35, 30, 27>,
  <36, 28, 33>,
  <28, 23, 18>,
  <24, 32, 29>,
  <24, 29, 21>,
  <21, 29, 26>,
  <21, 26, 16>,
  <16, 26, 20>,
  <16, 20, 12>,
  <12, 20, 17>,
  <12, 17, 9>,
  <9, 17, 15>,
  <9, 15, 7>,
  <7, 15, 18>,
  <7, 18, 10>,
  <10, 18, 23>,
  <10, 23, 13>,
  <13, 23, 27>,
  <13, 27, 19>,
  <19, 27, 30>,
  <19, 30, 22>,
  <22, 30, 32>,
  <22, 32, 24>,
  <0, 1, 5>,
  <0, 5, 6>,
  <0, 6, 3>,
  <0, 4, 9>,
  <0, 9, 7>,
  <0, 7, 2>,
  <1, 2, 10>,
  <1, 10, 13>,
  <1, 13, 8>,
  <5, 8, 19>,
  <5, 19, 22>,
  <5, 22, 14>,
  <6, 14, 24>,
  <6, 24, 21>,
  <6, 21, 11>,
  <3, 11, 16>,
  <3, 16, 12>,
  <3, 12, 4>,
  <33, 34, 38>,
  <33, 38, 39>,
  <33, 39, 36>,
  <33, 28, 18>,
  <33, 18, 15>,
  <33, 15, 25>,
  <34, 25, 17>,
  <34, 17, 20>,
  <34, 20, 31>,
  <38, 31, 26>,
  <38, 26, 29>,
  <38, 29, 37>,
  <39, 37, 32>,
  <39, 32, 30>,
  <39, 30, 35>,
  <36, 35, 27>,
  <36, 27, 23>,
  <36, 23, 28>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0];
 #local P1 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1];
 #local P2 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5];
 #local P3 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6];
 #local P4 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_43_elongated_pentagonal_gyrobirotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_43_elongated_pentagonal_gyrobirotunda_obj }
#end
#end

#macro Johnson_43_elongated_pentagonal_gyrobirotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[2], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[4], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[7], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[8], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[9], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[10], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[11], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[12], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[13], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[14], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[15], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[16], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[17], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[18], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[19], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[20], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[21], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[22], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[23], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[24], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[25], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[26], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[27], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[28], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[29], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[30], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[31], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[32], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[33], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[34], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[35], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[36], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[37], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[38], RadVer }
  sphere { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[39], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[2], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[2], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[2], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[7], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[7], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[10], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[10], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[2], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[8], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[8], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[8], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[13], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[13], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[19], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[19], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[8], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[14], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[14], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[14], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[22], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[22], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[24], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[24], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[14], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[11], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[11], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[11], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[21], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[21], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[16], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[16], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[11], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[4], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[4], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[4], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[12], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[12], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[9], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[9], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[4], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[33], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[25], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[25], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[34], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[34], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[33], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[25], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[15], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[15], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[17], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[17], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[25], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[34], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[31], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[31], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[38], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[38], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[34], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[31], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[20], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[20], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[26], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[26], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[31], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[38], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[37], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[37], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[39], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[39], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[38], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[37], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[29], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[29], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[32], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[32], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[37], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[39], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[35], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[35], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[36], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[36], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[39], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[35], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[30], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[30], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[27], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[27], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[35], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[36], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[28], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[28], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[33], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[33], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[36], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[28], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[23], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[23], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[18], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[18], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[28], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[24], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[32], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[29], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[21], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[21], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[24], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[29], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[26], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[26], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[16], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[20], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[12], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[12], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[16], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[20], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[17], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[17], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[9], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[15], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[7], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[7], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[9], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[15], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[18], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[18], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[10], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[23], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[13], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[13], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[10], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[23], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[27], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[27], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[19], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[30], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[22], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[22], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[19], RadEdg }
  cylinder { Johnson_43_elongated_pentagonal_gyrobirotunda_verts[30], Johnson_43_elongated_pentagonal_gyrobirotunda_verts[32], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[0];
 #local P1 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[1];
 #local P2 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[5];
 #local P3 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[6];
 #local P4 = Johnson_43_elongated_pentagonal_gyrobirotunda_verts[3];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_44_gyroelongated_triangular_bicupola_verts = array[18]
{
<-0.789003, 0.385273, -0.254111>,
<-0.772339, -0.452189, -0.185879>,
<-0.761383, 0.026005, 0.505125>,
<-0.611639, -0.798949, 0.562592>,
<-0.381598, -0.074991, -0.827220>,
<-0.362623, 0.753266, 0.369634>,
<-0.289802, 0.760316, -0.816621>,
<-0.055737, -0.771195, -0.487529>,
<-0.033826, 0.185193, 0.894479>,
<0.104963, -1.117956, 0.260942>,
<0.115918, -0.639761, 0.951946>,
<0.136578, 1.128308, -0.192876>,
<0.452187, -0.167262, -0.776585>,
<0.471162, 0.660994, 0.420269>,
<0.543983, 0.668044, -0.765985>,
<0.671820, -0.612007, -0.098176>,
<0.682775, -0.133813, 0.592828>,
<0.878567, 0.200731, -0.152840>,
}
#declare P0 = Johnson_44_gyroelongated_triangular_bicupola_verts[3];
#declare P1 = Johnson_44_gyroelongated_triangular_bicupola_verts[9];
#declare P2 = Johnson_44_gyroelongated_triangular_bicupola_verts[10];
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
 #declare Johnson_44_gyroelongated_triangular_bicupola_verts[Num] = vtransform(Johnson_44_gyroelongated_triangular_bicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_44_gyroelongated_triangular_bicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_44_gyroelongated_triangular_bicupola_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_44_gyroelongated_triangular_bicupola_verts[0],
  Johnson_44_gyroelongated_triangular_bicupola_verts[1],
  Johnson_44_gyroelongated_triangular_bicupola_verts[2],
  Johnson_44_gyroelongated_triangular_bicupola_verts[3],
  Johnson_44_gyroelongated_triangular_bicupola_verts[4],
  Johnson_44_gyroelongated_triangular_bicupola_verts[5],
  Johnson_44_gyroelongated_triangular_bicupola_verts[6],
  Johnson_44_gyroelongated_triangular_bicupola_verts[7],
  Johnson_44_gyroelongated_triangular_bicupola_verts[8],
  Johnson_44_gyroelongated_triangular_bicupola_verts[9],
  Johnson_44_gyroelongated_triangular_bicupola_verts[10],
  Johnson_44_gyroelongated_triangular_bicupola_verts[11],
  Johnson_44_gyroelongated_triangular_bicupola_verts[12],
  Johnson_44_gyroelongated_triangular_bicupola_verts[13],
  Johnson_44_gyroelongated_triangular_bicupola_verts[14],
  Johnson_44_gyroelongated_triangular_bicupola_verts[15],
  Johnson_44_gyroelongated_triangular_bicupola_verts[16],
  Johnson_44_gyroelongated_triangular_bicupola_verts[17]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  32,
  <11, 14, 6>, 0,
  <14, 17, 12>, 0,
  <6, 4, 0>, 0,
  <11, 5, 13>, 0,
  <9, 10, 3>, 0,
  <10, 16, 8>, 0,
  <3, 2, 1>, 0,
  <9, 7, 15>, 0,
  <4, 1, 0>, 0,
  <0, 1, 2>, 0,
  <0, 2, 5>, 0,
  <5, 2, 8>, 0,
  <5, 8, 13>, 0,
  <13, 8, 16>, 0,
  <13, 16, 17>, 0,
  <17, 16, 15>, 0,
  <17, 15, 12>, 0,
  <12, 15, 7>, 0,
  <12, 7, 4>, 0,
  <4, 7, 1>, 0,
  <14, 11, 13>, 1,
  <14, 13, 17>, 1,
  <6, 14, 12>, 1,
  <6, 12, 4>, 1,
  <11, 6, 0>, 1,
  <11, 0, 5>, 1,
  <10, 9, 15>, 1,
  <10, 15, 16>, 1,
  <3, 10, 8>, 1,
  <3, 8, 2>, 1,
  <9, 3, 1>, 1,
  <9, 1, 7>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_44_gyroelongated_triangular_bicupola_verts[3];
 #local P1 = Johnson_44_gyroelongated_triangular_bicupola_verts[9];
 #local P2 = Johnson_44_gyroelongated_triangular_bicupola_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_44_gyroelongated_triangular_bicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_44_gyroelongated_triangular_bicupola_obj }
#end
#end

#macro Johnson_44_gyroelongated_triangular_bicupola_faces2(OnPlane)
#local Johnson_44_gyroelongated_triangular_bicupola_obj = mesh2 {
 vertex_vectors {
  18,
  Johnson_44_gyroelongated_triangular_bicupola_verts[0],
  Johnson_44_gyroelongated_triangular_bicupola_verts[1],
  Johnson_44_gyroelongated_triangular_bicupola_verts[2],
  Johnson_44_gyroelongated_triangular_bicupola_verts[3],
  Johnson_44_gyroelongated_triangular_bicupola_verts[4],
  Johnson_44_gyroelongated_triangular_bicupola_verts[5],
  Johnson_44_gyroelongated_triangular_bicupola_verts[6],
  Johnson_44_gyroelongated_triangular_bicupola_verts[7],
  Johnson_44_gyroelongated_triangular_bicupola_verts[8],
  Johnson_44_gyroelongated_triangular_bicupola_verts[9],
  Johnson_44_gyroelongated_triangular_bicupola_verts[10],
  Johnson_44_gyroelongated_triangular_bicupola_verts[11],
  Johnson_44_gyroelongated_triangular_bicupola_verts[12],
  Johnson_44_gyroelongated_triangular_bicupola_verts[13],
  Johnson_44_gyroelongated_triangular_bicupola_verts[14],
  Johnson_44_gyroelongated_triangular_bicupola_verts[15],
  Johnson_44_gyroelongated_triangular_bicupola_verts[16],
  Johnson_44_gyroelongated_triangular_bicupola_verts[17]
 }
 face_indices {
  32,
  <11, 14, 6>,
  <14, 17, 12>,
  <6, 4, 0>,
  <11, 5, 13>,
  <9, 10, 3>,
  <10, 16, 8>,
  <3, 2, 1>,
  <9, 7, 15>,
  <4, 1, 0>,
  <0, 1, 2>,
  <0, 2, 5>,
  <5, 2, 8>,
  <5, 8, 13>,
  <13, 8, 16>,
  <13, 16, 17>,
  <17, 16, 15>,
  <17, 15, 12>,
  <12, 15, 7>,
  <12, 7, 4>,
  <4, 7, 1>,
  <14, 11, 13>,
  <14, 13, 17>,
  <6, 14, 12>,
  <6, 12, 4>,
  <11, 6, 0>,
  <11, 0, 5>,
  <10, 9, 15>,
  <10, 15, 16>,
  <3, 10, 8>,
  <3, 8, 2>,
  <9, 3, 1>,
  <9, 1, 7>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_44_gyroelongated_triangular_bicupola_verts[3];
 #local P1 = Johnson_44_gyroelongated_triangular_bicupola_verts[9];
 #local P2 = Johnson_44_gyroelongated_triangular_bicupola_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_44_gyroelongated_triangular_bicupola_obj
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_44_gyroelongated_triangular_bicupola_obj }
#end
#end

#macro Johnson_44_gyroelongated_triangular_bicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[0], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[1], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[2], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[3], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[4], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[5], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[6], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[7], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[8], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[9], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[10], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[11], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[12], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[13], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[14], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[15], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[16], RadVer }
  sphere { Johnson_44_gyroelongated_triangular_bicupola_verts[17], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[11], Johnson_44_gyroelongated_triangular_bicupola_verts[14], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[14], Johnson_44_gyroelongated_triangular_bicupola_verts[6], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[6], Johnson_44_gyroelongated_triangular_bicupola_verts[11], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[14], Johnson_44_gyroelongated_triangular_bicupola_verts[17], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[17], Johnson_44_gyroelongated_triangular_bicupola_verts[12], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[12], Johnson_44_gyroelongated_triangular_bicupola_verts[14], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[6], Johnson_44_gyroelongated_triangular_bicupola_verts[4], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[4], Johnson_44_gyroelongated_triangular_bicupola_verts[0], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[0], Johnson_44_gyroelongated_triangular_bicupola_verts[6], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[11], Johnson_44_gyroelongated_triangular_bicupola_verts[5], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[5], Johnson_44_gyroelongated_triangular_bicupola_verts[13], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[13], Johnson_44_gyroelongated_triangular_bicupola_verts[11], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[9], Johnson_44_gyroelongated_triangular_bicupola_verts[10], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[10], Johnson_44_gyroelongated_triangular_bicupola_verts[3], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[3], Johnson_44_gyroelongated_triangular_bicupola_verts[9], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[10], Johnson_44_gyroelongated_triangular_bicupola_verts[16], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[16], Johnson_44_gyroelongated_triangular_bicupola_verts[8], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[8], Johnson_44_gyroelongated_triangular_bicupola_verts[10], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[3], Johnson_44_gyroelongated_triangular_bicupola_verts[2], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[2], Johnson_44_gyroelongated_triangular_bicupola_verts[1], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[1], Johnson_44_gyroelongated_triangular_bicupola_verts[3], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[9], Johnson_44_gyroelongated_triangular_bicupola_verts[7], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[7], Johnson_44_gyroelongated_triangular_bicupola_verts[15], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[15], Johnson_44_gyroelongated_triangular_bicupola_verts[9], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[4], Johnson_44_gyroelongated_triangular_bicupola_verts[1], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[1], Johnson_44_gyroelongated_triangular_bicupola_verts[0], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[2], Johnson_44_gyroelongated_triangular_bicupola_verts[0], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[2], Johnson_44_gyroelongated_triangular_bicupola_verts[5], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[5], Johnson_44_gyroelongated_triangular_bicupola_verts[0], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[2], Johnson_44_gyroelongated_triangular_bicupola_verts[8], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[8], Johnson_44_gyroelongated_triangular_bicupola_verts[5], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[8], Johnson_44_gyroelongated_triangular_bicupola_verts[13], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[16], Johnson_44_gyroelongated_triangular_bicupola_verts[13], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[16], Johnson_44_gyroelongated_triangular_bicupola_verts[17], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[17], Johnson_44_gyroelongated_triangular_bicupola_verts[13], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[16], Johnson_44_gyroelongated_triangular_bicupola_verts[15], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[15], Johnson_44_gyroelongated_triangular_bicupola_verts[17], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[15], Johnson_44_gyroelongated_triangular_bicupola_verts[12], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[7], Johnson_44_gyroelongated_triangular_bicupola_verts[12], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[7], Johnson_44_gyroelongated_triangular_bicupola_verts[4], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[4], Johnson_44_gyroelongated_triangular_bicupola_verts[12], RadEdg }
  cylinder { Johnson_44_gyroelongated_triangular_bicupola_verts[7], Johnson_44_gyroelongated_triangular_bicupola_verts[1], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_44_gyroelongated_triangular_bicupola_verts[3];
 #local P1 = Johnson_44_gyroelongated_triangular_bicupola_verts[9];
 #local P2 = Johnson_44_gyroelongated_triangular_bicupola_verts[10];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2)/3
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_45_gyroelongated_square_bicupola_verts = array[24]
{
<-0.984615, -0.215433, 0.042813>,
<-0.835086, 0.417027, 0.382665>,
<-0.776626, 0.078669, -0.596021>,
<-0.681291, -0.220722, 0.710519>,
<-0.642753, -0.628915, -0.457214>,
<-0.627097, 0.711130, -0.256169>,
<-0.577202, -0.786781, 0.255979>,
<-0.300907, 0.381853, 0.883943>,
<-0.281757, 0.897979, 0.363260>,
<-0.143631, 0.126378, -0.963315>,
<-0.068623, -0.621064, 0.757726>,
<-0.049613, -0.984736, -0.213412>,
<-0.009758, -0.581206, -0.824509>,
<0.005899, 0.758839, -0.623463>,
<0.311761, -0.018489, 0.931151>,
<0.341127, 0.667962, 0.674663>,
<0.351238, 0.945688, -0.004035>,
<0.458966, -0.819019, 0.288335>,
<0.543570, -0.100253, -0.843914>,
<0.592421, -0.698626, -0.422693>,
<0.693100, 0.532207, -0.504062>,
<0.839350, -0.216444, 0.461759>,
<0.868716, 0.470008, 0.205272>,
<0.972805, -0.096052, -0.249268>
}
#declare P0 = Johnson_45_gyroelongated_square_bicupola_verts[2];
#declare P1 = Johnson_45_gyroelongated_square_bicupola_verts[9];
#declare P2 = Johnson_45_gyroelongated_square_bicupola_verts[5];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 24)
 #declare Johnson_45_gyroelongated_square_bicupola_verts[Num] = vtransform(Johnson_45_gyroelongated_square_bicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_45_gyroelongated_square_bicupola_faces(Tex3, Tex4, OnPlane)
#local Johnson_45_gyroelongated_square_bicupola_obj = mesh2 {
 vertex_vectors {
  24,
  Johnson_45_gyroelongated_square_bicupola_verts[0],
  Johnson_45_gyroelongated_square_bicupola_verts[1],
  Johnson_45_gyroelongated_square_bicupola_verts[2],
  Johnson_45_gyroelongated_square_bicupola_verts[3],
  Johnson_45_gyroelongated_square_bicupola_verts[4],
  Johnson_45_gyroelongated_square_bicupola_verts[5],
  Johnson_45_gyroelongated_square_bicupola_verts[6],
  Johnson_45_gyroelongated_square_bicupola_verts[7],
  Johnson_45_gyroelongated_square_bicupola_verts[8],
  Johnson_45_gyroelongated_square_bicupola_verts[9],
  Johnson_45_gyroelongated_square_bicupola_verts[10],
  Johnson_45_gyroelongated_square_bicupola_verts[11],
  Johnson_45_gyroelongated_square_bicupola_verts[12],
  Johnson_45_gyroelongated_square_bicupola_verts[13],
  Johnson_45_gyroelongated_square_bicupola_verts[14],
  Johnson_45_gyroelongated_square_bicupola_verts[15],
  Johnson_45_gyroelongated_square_bicupola_verts[16],
  Johnson_45_gyroelongated_square_bicupola_verts[17],
  Johnson_45_gyroelongated_square_bicupola_verts[18],
  Johnson_45_gyroelongated_square_bicupola_verts[19],
  Johnson_45_gyroelongated_square_bicupola_verts[20],
  Johnson_45_gyroelongated_square_bicupola_verts[21],
  Johnson_45_gyroelongated_square_bicupola_verts[22],
  Johnson_45_gyroelongated_square_bicupola_verts[23]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex4 }
 }
 face_indices {
  44,
  <13, 16, 20>, 0,
  <9, 18, 12>, 0,
  <2, 4, 0>, 0,
  <5, 1, 8>, 0,
  <14, 15, 7>, 0,
  <10, 3, 6>, 0,
  <17, 11, 19>, 0,
  <21, 23, 22>, 0,
  <12, 11, 4>, 0,
  <4, 11, 6>, 0,
  <4, 6, 0>, 0,
  <0, 6, 3>, 0,
  <0, 3, 1>, 0,
  <1, 3, 7>, 0,
  <1, 7, 8>, 0,
  <8, 7, 15>, 0,
  <8, 15, 16>, 0,
  <16, 15, 22>, 0,
  <16, 22, 20>, 0,
  <20, 22, 23>, 0,
  <20, 23, 18>, 0,
  <18, 23, 19>, 0,
  <18, 19, 12>, 0,
  <12, 19, 11>, 0,
  <5, 13, 9>, 1,
  <5, 9, 2>, 1,
  <13, 5, 8>, 1,
  <13, 8, 16>, 1,
  <9, 13, 20>, 1,
  <9, 20, 18>, 1,
  <2, 9, 12>, 1,
  <2, 12, 4>, 1,
  <5, 2, 0>, 1,
  <5, 0, 1>, 1,
  <21, 14, 10>, 1,
  <21, 10, 17>, 1,
  <14, 21, 22>, 1,
  <14, 22, 15>, 1,
  <10, 14, 7>, 1,
  <10, 7, 3>, 1,
  <17, 10, 6>, 1,
  <17, 6, 11>, 1,
  <21, 17, 19>, 1,
  <21, 19, 23>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_45_gyroelongated_square_bicupola_verts[13];
 #local P1 = Johnson_45_gyroelongated_square_bicupola_verts[9];
 #local P2 = Johnson_45_gyroelongated_square_bicupola_verts[2];
 #local P3 = Johnson_45_gyroelongated_square_bicupola_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_45_gyroelongated_square_bicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_45_gyroelongated_square_bicupola_obj }
#end
#end

#macro Johnson_45_gyroelongated_square_bicupola_faces2(OnPlane)
#local Johnson_45_gyroelongated_square_bicupola_obj = mesh2 {
 vertex_vectors {
  24,
  Johnson_45_gyroelongated_square_bicupola_verts[0],
  Johnson_45_gyroelongated_square_bicupola_verts[1],
  Johnson_45_gyroelongated_square_bicupola_verts[2],
  Johnson_45_gyroelongated_square_bicupola_verts[3],
  Johnson_45_gyroelongated_square_bicupola_verts[4],
  Johnson_45_gyroelongated_square_bicupola_verts[5],
  Johnson_45_gyroelongated_square_bicupola_verts[6],
  Johnson_45_gyroelongated_square_bicupola_verts[7],
  Johnson_45_gyroelongated_square_bicupola_verts[8],
  Johnson_45_gyroelongated_square_bicupola_verts[9],
  Johnson_45_gyroelongated_square_bicupola_verts[10],
  Johnson_45_gyroelongated_square_bicupola_verts[11],
  Johnson_45_gyroelongated_square_bicupola_verts[12],
  Johnson_45_gyroelongated_square_bicupola_verts[13],
  Johnson_45_gyroelongated_square_bicupola_verts[14],
  Johnson_45_gyroelongated_square_bicupola_verts[15],
  Johnson_45_gyroelongated_square_bicupola_verts[16],
  Johnson_45_gyroelongated_square_bicupola_verts[17],
  Johnson_45_gyroelongated_square_bicupola_verts[18],
  Johnson_45_gyroelongated_square_bicupola_verts[19],
  Johnson_45_gyroelongated_square_bicupola_verts[20],
  Johnson_45_gyroelongated_square_bicupola_verts[21],
  Johnson_45_gyroelongated_square_bicupola_verts[22],
  Johnson_45_gyroelongated_square_bicupola_verts[23]
 }
 face_indices {
  44,
  <13, 16, 20>,
  <9, 18, 12>,
  <2, 4, 0>,
  <5, 1, 8>,
  <14, 15, 7>,
  <10, 3, 6>,
  <17, 11, 19>,
  <21, 23, 22>,
  <12, 11, 4>,
  <4, 11, 6>,
  <4, 6, 0>,
  <0, 6, 3>,
  <0, 3, 1>,
  <1, 3, 7>,
  <1, 7, 8>,
  <8, 7, 15>,
  <8, 15, 16>,
  <16, 15, 22>,
  <16, 22, 20>,
  <20, 22, 23>,
  <20, 23, 18>,
  <18, 23, 19>,
  <18, 19, 12>,
  <12, 19, 11>,
  <5, 13, 9>,
  <5, 9, 2>,
  <13, 5, 8>,
  <13, 8, 16>,
  <9, 13, 20>,
  <9, 20, 18>,
  <2, 9, 12>,
  <2, 12, 4>,
  <5, 2, 0>,
  <5, 0, 1>,
  <21, 14, 10>,
  <21, 10, 17>,
  <14, 21, 22>,
  <14, 22, 15>,
  <10, 14, 7>,
  <10, 7, 3>,
  <17, 10, 6>,
  <17, 6, 11>,
  <21, 17, 19>,
  <21, 19, 23>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_45_gyroelongated_square_bicupola_verts[13];
 #local P1 = Johnson_45_gyroelongated_square_bicupola_verts[9];
 #local P2 = Johnson_45_gyroelongated_square_bicupola_verts[2];
 #local P3 = Johnson_45_gyroelongated_square_bicupola_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_45_gyroelongated_square_bicupola_obj
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_45_gyroelongated_square_bicupola_obj }
#end
#end

#macro Johnson_45_gyroelongated_square_bicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[0], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[1], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[2], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[3], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[4], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[5], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[6], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[7], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[8], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[9], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[10], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[11], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[12], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[13], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[14], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[15], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[16], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[17], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[18], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[19], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[20], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[21], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[22], RadVer }
  sphere { Johnson_45_gyroelongated_square_bicupola_verts[23], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[13], Johnson_45_gyroelongated_square_bicupola_verts[16], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[16], Johnson_45_gyroelongated_square_bicupola_verts[20], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[20], Johnson_45_gyroelongated_square_bicupola_verts[13], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[9], Johnson_45_gyroelongated_square_bicupola_verts[18], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[18], Johnson_45_gyroelongated_square_bicupola_verts[12], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[12], Johnson_45_gyroelongated_square_bicupola_verts[9], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[2], Johnson_45_gyroelongated_square_bicupola_verts[4], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[4], Johnson_45_gyroelongated_square_bicupola_verts[0], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[0], Johnson_45_gyroelongated_square_bicupola_verts[2], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[5], Johnson_45_gyroelongated_square_bicupola_verts[1], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[1], Johnson_45_gyroelongated_square_bicupola_verts[8], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[8], Johnson_45_gyroelongated_square_bicupola_verts[5], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[14], Johnson_45_gyroelongated_square_bicupola_verts[15], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[15], Johnson_45_gyroelongated_square_bicupola_verts[7], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[7], Johnson_45_gyroelongated_square_bicupola_verts[14], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[10], Johnson_45_gyroelongated_square_bicupola_verts[3], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[3], Johnson_45_gyroelongated_square_bicupola_verts[6], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[6], Johnson_45_gyroelongated_square_bicupola_verts[10], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[17], Johnson_45_gyroelongated_square_bicupola_verts[11], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[11], Johnson_45_gyroelongated_square_bicupola_verts[19], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[19], Johnson_45_gyroelongated_square_bicupola_verts[17], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[21], Johnson_45_gyroelongated_square_bicupola_verts[23], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[23], Johnson_45_gyroelongated_square_bicupola_verts[22], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[22], Johnson_45_gyroelongated_square_bicupola_verts[21], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[12], Johnson_45_gyroelongated_square_bicupola_verts[11], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[11], Johnson_45_gyroelongated_square_bicupola_verts[4], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[4], Johnson_45_gyroelongated_square_bicupola_verts[12], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[11], Johnson_45_gyroelongated_square_bicupola_verts[6], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[6], Johnson_45_gyroelongated_square_bicupola_verts[4], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[6], Johnson_45_gyroelongated_square_bicupola_verts[0], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[3], Johnson_45_gyroelongated_square_bicupola_verts[0], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[3], Johnson_45_gyroelongated_square_bicupola_verts[1], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[1], Johnson_45_gyroelongated_square_bicupola_verts[0], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[3], Johnson_45_gyroelongated_square_bicupola_verts[7], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[7], Johnson_45_gyroelongated_square_bicupola_verts[1], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[7], Johnson_45_gyroelongated_square_bicupola_verts[8], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[15], Johnson_45_gyroelongated_square_bicupola_verts[8], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[15], Johnson_45_gyroelongated_square_bicupola_verts[16], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[16], Johnson_45_gyroelongated_square_bicupola_verts[8], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[15], Johnson_45_gyroelongated_square_bicupola_verts[22], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[22], Johnson_45_gyroelongated_square_bicupola_verts[16], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[22], Johnson_45_gyroelongated_square_bicupola_verts[20], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[23], Johnson_45_gyroelongated_square_bicupola_verts[20], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[23], Johnson_45_gyroelongated_square_bicupola_verts[18], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[18], Johnson_45_gyroelongated_square_bicupola_verts[20], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[23], Johnson_45_gyroelongated_square_bicupola_verts[19], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[19], Johnson_45_gyroelongated_square_bicupola_verts[18], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[19], Johnson_45_gyroelongated_square_bicupola_verts[12], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[5], Johnson_45_gyroelongated_square_bicupola_verts[13], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[13], Johnson_45_gyroelongated_square_bicupola_verts[9], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[9], Johnson_45_gyroelongated_square_bicupola_verts[2], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[2], Johnson_45_gyroelongated_square_bicupola_verts[5], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[21], Johnson_45_gyroelongated_square_bicupola_verts[14], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[14], Johnson_45_gyroelongated_square_bicupola_verts[10], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[10], Johnson_45_gyroelongated_square_bicupola_verts[17], RadEdg }
  cylinder { Johnson_45_gyroelongated_square_bicupola_verts[17], Johnson_45_gyroelongated_square_bicupola_verts[21], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_45_gyroelongated_square_bicupola_verts[13];
 #local P1 = Johnson_45_gyroelongated_square_bicupola_verts[9];
 #local P2 = Johnson_45_gyroelongated_square_bicupola_verts[2];
 #local P3 = Johnson_45_gyroelongated_square_bicupola_verts[5];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3)/4
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_46_gyroelongated_pentagonal_bicupola_verts = array[30]
{
<-0.962816, 0.187793, 0.445444>,
<-0.942301, -0.435696, 0.287991>,
<-0.736715, 0.342260, -0.136766>,
<-0.716200, -0.281228, -0.294218>,
<-0.680334, 0.758077, 0.350950>,
<-0.653736, -0.229833, 0.824928>,
<-0.626624, -0.874236, -0.061265>,
<-0.516012, 0.397771, 0.858028>,
<-0.476990, -0.788175, 0.558536>,
<-0.259134, 0.641512, -0.447112>,
<-0.225940, -0.367313, -0.701875>,
<-0.202753, 1.057329, 0.040605>,
<-0.136364, -0.960322, -0.468922>,
<-0.116423, 0.854913, 0.645191>,
<-0.053283, -1.063987, 0.160603>,
<-0.029965, -0.362198, 0.739264>,
<0.056543, 0.202971, -0.796368>,
<0.107759, 0.265405, 0.772363>,
<0.287508, 0.971244, -0.367052>,
<0.341218, -0.661070, -0.779268>,
<0.392401, 0.966981, 0.267715>,
<0.393741, -0.638011, 0.341331>,
<0.455541, -0.951919, -0.216873>,
<0.603185, 0.532703, -0.716309>
<0.616584, 0.377473, 0.394887>,
<0.623700, -0.090786, -0.873761>,
<0.793330, -0.180868, 0.128495>,
<0.816108, 0.691169, -0.130218>,
<0.855130, -0.494777, -0.429710>,
<0.992854, 0.132827, -0.396611>,
}
#declare P0 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[24];
#declare P1 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[17];
#declare P2 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[15];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 30)
 #declare Johnson_46_gyroelongated_pentagonal_bicupola_verts[Num] = vtransform(Johnson_46_gyroelongated_pentagonal_bicupola_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_46_gyroelongated_pentagonal_bicupola_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_46_gyroelongated_pentagonal_bicupola_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[0],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[1],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[2],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[3],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[4],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[5],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[6],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[7],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[8],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[9],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[10],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[11],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[12],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[13],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[14],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[15],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[16],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[17],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[18],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[19],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[20],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[21],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[22],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[23],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[24],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[25],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[26],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[27],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[28],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[29]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  56,
  <9, 11, 18>, 0,
  <16, 23, 25>, 0,
  <10, 19, 12>, 0,
  <3, 6, 1>, 0,
  <2, 0, 4>, 0,
  <17, 13, 7>, 0,
  <15, 5, 8>, 0,
  <21, 14, 22>, 0,
  <26, 28, 29>, 0,
  <24, 27, 20>, 0,
  <19, 22, 12>, 0,
  <12, 22, 14>, 0,
  <12, 14, 6>, 0,
  <6, 14, 8>, 0,
  <6, 8, 1>, 0,
  <1, 8, 5>, 0,
  <1, 5, 0>, 0,
  <0, 5, 7>, 0,
  <0, 7, 4>, 0,
  <4, 7, 13>, 0,
  <4, 13, 11>, 0,
  <11, 13, 20>, 0,
  <11, 20, 18>, 0,
  <18, 20, 27>, 0,
  <18, 27, 23>, 0,
  <23, 27, 29>, 0,
  <23, 29, 25>, 0,
  <25, 29, 28>, 0,
  <25, 28, 19>, 0,
  <19, 28, 22>, 0,
  <9, 2, 4>, 1,
  <9, 4, 11>, 1,
  <16, 9, 18>, 1,
  <16, 18, 23>, 1,
  <10, 16, 25>, 1,
  <10, 25, 19>, 1,
  <3, 10, 12>, 1,
  <3, 12, 6>, 1,
  <2, 3, 1>, 1,
  <2, 1, 0>, 1,
  <17, 24, 20>, 1,
  <17, 20, 13>, 1,
  <15, 17, 7>, 1,
  <15, 7, 5>, 1,
  <21, 15, 8>, 1,
  <21, 8, 14>, 1,
  <26, 21, 22>, 1,
  <26, 22, 28>, 1,
  <24, 26, 29>, 1,
  <24, 29, 27>, 1,
  <2, 9, 16>, 2,
  <2, 16, 10>, 2,
  <2, 10, 3>, 2,
  <24, 17, 15>, 2,
  <24, 15, 21>, 2,
  <24, 21, 26>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[24];
 #local P1 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[17];
 #local P2 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[15];
 #local P3 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[21];
 #local P4 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[26];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_46_gyroelongated_pentagonal_bicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_46_gyroelongated_pentagonal_bicupola_obj }
#end
#end

#macro Johnson_46_gyroelongated_pentagonal_bicupola_faces2(OnPlane)
#local Johnson_46_gyroelongated_pentagonal_bicupola_obj = mesh2 {
 vertex_vectors {
  30,
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[0],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[1],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[2],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[3],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[4],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[5],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[6],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[7],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[8],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[9],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[10],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[11],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[12],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[13],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[14],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[15],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[16],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[17],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[18],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[19],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[20],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[21],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[22],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[23],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[24],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[25],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[26],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[27],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[28],
  Johnson_46_gyroelongated_pentagonal_bicupola_verts[29]
 }
 face_indices {
  56,
  <9, 11, 18>,
  <16, 23, 25>,
  <10, 19, 12>,
  <3, 6, 1>,
  <2, 0, 4>,
  <17, 13, 7>,
  <15, 5, 8>,
  <21, 14, 22>,
  <26, 28, 29>,
  <24, 27, 20>,
  <19, 22, 12>,
  <12, 22, 14>,
  <12, 14, 6>,
  <6, 14, 8>,
  <6, 8, 1>,
  <1, 8, 5>,
  <1, 5, 0>,
  <0, 5, 7>,
  <0, 7, 4>,
  <4, 7, 13>,
  <4, 13, 11>,
  <11, 13, 20>,
  <11, 20, 18>,
  <18, 20, 27>,
  <18, 27, 23>,
  <23, 27, 29>,
  <23, 29, 25>,
  <25, 29, 28>,
  <25, 28, 19>,
  <19, 28, 22>,
  <9, 2, 4>,
  <9, 4, 11>,
  <16, 9, 18>,
  <16, 18, 23>,
  <10, 16, 25>,
  <10, 25, 19>,
  <3, 10, 12>,
  <3, 12, 6>,
  <2, 3, 1>,
  <2, 1, 0>,
  <17, 24, 20>,
  <17, 20, 13>,
  <15, 17, 7>,
  <15, 7, 5>,
  <21, 15, 8>,
  <21, 8, 14>,
  <26, 21, 22>,
  <26, 22, 28>,
  <24, 26, 29>,
  <24, 29, 27>,
  <2, 9, 16>,
  <2, 16, 10>,
  <2, 10, 3>,
  <24, 17, 15>,
  <24, 15, 21>,
  <24, 21, 26>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[24];
 #local P1 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[17];
 #local P2 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[15];
 #local P3 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[21];
 #local P4 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[26];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_46_gyroelongated_pentagonal_bicupola_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_46_gyroelongated_pentagonal_bicupola_obj }
#end
#end

#macro Johnson_46_gyroelongated_pentagonal_bicupola_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[0], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[1], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[2], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[3], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[4], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[5], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[6], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[7], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[8], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[9], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[10], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[11], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[12], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[13], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[14], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[15], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[16], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[17], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[18], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[19], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[20], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[21], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[22], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[23], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[24], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[25], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[26], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[27], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[28], RadVer }
  sphere { Johnson_46_gyroelongated_pentagonal_bicupola_verts[29], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[9], Johnson_46_gyroelongated_pentagonal_bicupola_verts[11], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[11], Johnson_46_gyroelongated_pentagonal_bicupola_verts[18], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[18], Johnson_46_gyroelongated_pentagonal_bicupola_verts[9], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[16], Johnson_46_gyroelongated_pentagonal_bicupola_verts[23], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[23], Johnson_46_gyroelongated_pentagonal_bicupola_verts[25], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[25], Johnson_46_gyroelongated_pentagonal_bicupola_verts[16], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[10], Johnson_46_gyroelongated_pentagonal_bicupola_verts[19], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[19], Johnson_46_gyroelongated_pentagonal_bicupola_verts[12], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[12], Johnson_46_gyroelongated_pentagonal_bicupola_verts[10], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[3], Johnson_46_gyroelongated_pentagonal_bicupola_verts[6], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[6], Johnson_46_gyroelongated_pentagonal_bicupola_verts[1], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[1], Johnson_46_gyroelongated_pentagonal_bicupola_verts[3], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[2], Johnson_46_gyroelongated_pentagonal_bicupola_verts[0], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[0], Johnson_46_gyroelongated_pentagonal_bicupola_verts[4], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[4], Johnson_46_gyroelongated_pentagonal_bicupola_verts[2], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[17], Johnson_46_gyroelongated_pentagonal_bicupola_verts[13], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[13], Johnson_46_gyroelongated_pentagonal_bicupola_verts[7], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[7], Johnson_46_gyroelongated_pentagonal_bicupola_verts[17], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[15], Johnson_46_gyroelongated_pentagonal_bicupola_verts[5], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[5], Johnson_46_gyroelongated_pentagonal_bicupola_verts[8], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[8], Johnson_46_gyroelongated_pentagonal_bicupola_verts[15], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[21], Johnson_46_gyroelongated_pentagonal_bicupola_verts[14], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[14], Johnson_46_gyroelongated_pentagonal_bicupola_verts[22], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[22], Johnson_46_gyroelongated_pentagonal_bicupola_verts[21], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[26], Johnson_46_gyroelongated_pentagonal_bicupola_verts[28], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[28], Johnson_46_gyroelongated_pentagonal_bicupola_verts[29], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[29], Johnson_46_gyroelongated_pentagonal_bicupola_verts[26], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[24], Johnson_46_gyroelongated_pentagonal_bicupola_verts[27], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[27], Johnson_46_gyroelongated_pentagonal_bicupola_verts[20], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[20], Johnson_46_gyroelongated_pentagonal_bicupola_verts[24], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[19], Johnson_46_gyroelongated_pentagonal_bicupola_verts[22], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[22], Johnson_46_gyroelongated_pentagonal_bicupola_verts[12], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[14], Johnson_46_gyroelongated_pentagonal_bicupola_verts[12], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[14], Johnson_46_gyroelongated_pentagonal_bicupola_verts[6], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[6], Johnson_46_gyroelongated_pentagonal_bicupola_verts[12], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[14], Johnson_46_gyroelongated_pentagonal_bicupola_verts[8], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[8], Johnson_46_gyroelongated_pentagonal_bicupola_verts[6], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[8], Johnson_46_gyroelongated_pentagonal_bicupola_verts[1], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[5], Johnson_46_gyroelongated_pentagonal_bicupola_verts[1], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[5], Johnson_46_gyroelongated_pentagonal_bicupola_verts[0], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[0], Johnson_46_gyroelongated_pentagonal_bicupola_verts[1], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[5], Johnson_46_gyroelongated_pentagonal_bicupola_verts[7], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[7], Johnson_46_gyroelongated_pentagonal_bicupola_verts[0], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[7], Johnson_46_gyroelongated_pentagonal_bicupola_verts[4], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[13], Johnson_46_gyroelongated_pentagonal_bicupola_verts[4], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[13], Johnson_46_gyroelongated_pentagonal_bicupola_verts[11], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[11], Johnson_46_gyroelongated_pentagonal_bicupola_verts[4], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[13], Johnson_46_gyroelongated_pentagonal_bicupola_verts[20], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[20], Johnson_46_gyroelongated_pentagonal_bicupola_verts[11], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[20], Johnson_46_gyroelongated_pentagonal_bicupola_verts[18], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[27], Johnson_46_gyroelongated_pentagonal_bicupola_verts[18], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[27], Johnson_46_gyroelongated_pentagonal_bicupola_verts[23], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[23], Johnson_46_gyroelongated_pentagonal_bicupola_verts[18], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[27], Johnson_46_gyroelongated_pentagonal_bicupola_verts[29], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[29], Johnson_46_gyroelongated_pentagonal_bicupola_verts[23], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[29], Johnson_46_gyroelongated_pentagonal_bicupola_verts[25], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[28], Johnson_46_gyroelongated_pentagonal_bicupola_verts[25], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[28], Johnson_46_gyroelongated_pentagonal_bicupola_verts[19], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[19], Johnson_46_gyroelongated_pentagonal_bicupola_verts[25], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[28], Johnson_46_gyroelongated_pentagonal_bicupola_verts[22], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[9], Johnson_46_gyroelongated_pentagonal_bicupola_verts[2], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[16], Johnson_46_gyroelongated_pentagonal_bicupola_verts[9], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[10], Johnson_46_gyroelongated_pentagonal_bicupola_verts[16], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[3], Johnson_46_gyroelongated_pentagonal_bicupola_verts[10], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[2], Johnson_46_gyroelongated_pentagonal_bicupola_verts[3], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[17], Johnson_46_gyroelongated_pentagonal_bicupola_verts[24], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[15], Johnson_46_gyroelongated_pentagonal_bicupola_verts[17], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[21], Johnson_46_gyroelongated_pentagonal_bicupola_verts[15], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[26], Johnson_46_gyroelongated_pentagonal_bicupola_verts[21], RadEdg }
  cylinder { Johnson_46_gyroelongated_pentagonal_bicupola_verts[24], Johnson_46_gyroelongated_pentagonal_bicupola_verts[26], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[24];
 #local P1 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[17];
 #local P2 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[15];
 #local P3 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[21];
 #local P4 = Johnson_46_gyroelongated_pentagonal_bicupola_verts[26];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts = array[35]
{
<-0.908535, -0.523787, -0.144699>,
<-0.894854, -0.367641, 0.429886>,
<-0.853258, 0.048135, -0.301436>,
<-0.839577, 0.204280, 0.273149>,
<-0.708763, -0.381742, -0.687498>,
<-0.672946, 0.027052, 0.816785>,
<-0.520247, -0.782937, 0.225153>,
<-0.516340, 0.434114, -0.605119>,
<-0.494204, 0.686763, 0.324579>,
<-0.422413, -0.790350, -0.362291>,
<-0.396391, -0.493344, 0.730635>,
<-0.371845, 0.004237, -0.991181>,
<-0.327573, 0.509534, 0.868216>,
<-0.294432, 0.828807, -0.218221>,
<-0.140258, -0.512752, -0.807313>,
<-0.098153, -0.032185, 0.961078>,
<-0.026471, 0.486719, -0.939751>,
<-0.010949, -1.005224, 0.010862>,
<0.009345, 0.895513, 0.564533>,
<0.189455, -0.536653, 0.828749>,
<0.195436, 0.881412, -0.552852>,
<0.209117, 1.037558, 0.021734>,
<0.218444, -0.056175, -0.939930>,
<0.260549, 0.424392, 0.828462>
<0.427671, -0.853012, 0.383905>,
<0.445587, -0.556061, -0.709199>,
<0.516681, 0.404984, -0.709486>,
<0.525505, -0.860425, -0.203539>,
<0.542703, 0.701990, 0.383440>,
<0.640537, 0.694577, -0.204005>,
<0.725908, -0.391854, 0.614349>,
<0.769847, 0.202104, 0.614171>,
<0.884207, -0.403849, -0.336156>,
<0.928145, 0.190109, -0.336334>,
<1.008063, -0.114255, 0.169326>,
}
#declare P0 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8];
#declare P1 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13];
#declare P2 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 35)
 #declare Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[Num] = vtransform(Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_47_gyroelongated_pentagonal_cupolarotunda_faces(Tex3, Tex4, Tex5, OnPlane)
#local Johnson_47_gyroelongated_pentagonal_cupolarotunda_obj = mesh2 {
 vertex_vectors {
  35,
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[17],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[19],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[24],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[25],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[27],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[30],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[31],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[32],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[33],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[34]
 }
 texture_list {
  3,
  texture { Tex3 },
  texture { Tex4 },
  texture { Tex5 }
 }
 face_indices {
  66,
  <8, 12, 18>, 0,
  <13, 21, 20>, 0,
  <7, 16, 11>, 0,
  <2, 4, 0>, 0,
  <3, 1, 5>, 0,
  <30, 19, 24>, 0,
  <19, 15, 10>, 0,
  <24, 17, 27>, 0,
  <17, 6, 9>, 0,
  <27, 25, 32>, 0,
  <25, 14, 22>, 0,
  <32, 33, 34>, 0,
  <33, 26, 29>, 0,
  <34, 31, 30>, 0,
  <31, 28, 23>, 0,
  <16, 22, 11>, 0,
  <11, 22, 14>, 0,
  <11, 14, 4>, 0,
  <4, 14, 9>, 0,
  <4, 9, 0>, 0,
  <0, 9, 6>, 0,
  <0, 6, 1>, 0,
  <1, 6, 10>, 0,
  <1, 10, 5>, 0,
  <5, 10, 15>, 0,
  <5, 15, 12>, 0,
  <12, 15, 23>, 0,
  <12, 23, 18>, 0,
  <18, 23, 28>, 0,
  <18, 28, 21>, 0,
  <21, 28, 29>, 0,
  <21, 29, 20>, 0,
  <20, 29, 26>, 0,
  <20, 26, 16>, 0,
  <16, 26, 22>, 0,
  <8, 3, 5>, 1,
  <8, 5, 12>, 1,
  <13, 8, 18>, 1,
  <13, 18, 21>, 1,
  <7, 13, 20>, 1,
  <7, 20, 16>, 1,
  <2, 7, 11>, 1,
  <2, 11, 4>, 1,
  <3, 2, 0>, 1,
  <3, 0, 1>, 1,
  <3, 8, 13>, 2,
  <3, 13, 7>, 2,
  <3, 7, 2>, 2,
  <30, 24, 27>, 2,
  <30, 27, 32>, 2,
  <30, 32, 34>, 2,
  <30, 31, 23>, 2,
  <30, 23, 15>, 2,
  <30, 15, 19>, 2,
  <24, 19, 10>, 2,
  <24, 10, 6>, 2,
  <24, 6, 17>, 2,
  <27, 17, 9>, 2,
  <27, 9, 14>, 2,
  <27, 14, 25>, 2,
  <32, 25, 22>, 2,
  <32, 22, 26>, 2,
  <32, 26, 33>, 2,
  <34, 33, 29>, 2,
  <34, 29, 28>, 2,
  <34, 28, 31>, 2
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8];
 #local P1 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13];
 #local P2 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2];
 #local P3 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3];
 #local P4 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_47_gyroelongated_pentagonal_cupolarotunda_obj }
#end
#end

#macro Johnson_47_gyroelongated_pentagonal_cupolarotunda_faces2(OnPlane)
#local Johnson_47_gyroelongated_pentagonal_cupolarotunda_obj = mesh2 {
 vertex_vectors {
  35,
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[17],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[19],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[24],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[25],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[27],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[30],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[31],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[32],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[33],
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[34]
 }
 face_indices {
  66,
  <8, 12, 18>,
  <13, 21, 20>,
  <7, 16, 11>,
  <2, 4, 0>,
  <3, 1, 5>,
  <30, 19, 24>,
  <19, 15, 10>,
  <24, 17, 27>,
  <17, 6, 9>,
  <27, 25, 32>,
  <25, 14, 22>,
  <32, 33, 34>,
  <33, 26, 29>,
  <34, 31, 30>,
  <31, 28, 23>,
  <16, 22, 11>,
  <11, 22, 14>,
  <11, 14, 4>,
  <4, 14, 9>,
  <4, 9, 0>,
  <0, 9, 6>,
  <0, 6, 1>,
  <1, 6, 10>,
  <1, 10, 5>,
  <5, 10, 15>,
  <5, 15, 12>,
  <12, 15, 23>,
  <12, 23, 18>,
  <18, 23, 28>,
  <18, 28, 21>,
  <21, 28, 29>,
  <21, 29, 20>,
  <20, 29, 26>,
  <20, 26, 16>,
  <16, 26, 22>,
  <8, 3, 5>,
  <8, 5, 12>,
  <13, 8, 18>,
  <13, 18, 21>,
  <7, 13, 20>,
  <7, 20, 16>,
  <2, 7, 11>,
  <2, 11, 4>,
  <3, 2, 0>,
  <3, 0, 1>,
  <3, 8, 13>,
  <3, 13, 7>,
  <3, 7, 2>,
  <30, 24, 27>,
  <30, 27, 32>,
  <30, 32, 34>,
  <30, 31, 23>,
  <30, 23, 15>,
  <30, 15, 19>,
  <24, 19, 10>,
  <24, 10, 6>,
  <24, 6, 17>,
  <27, 17, 9>,
  <27, 9, 14>,
  <27, 14, 25>,
  <32, 25, 22>,
  <32, 22, 26>,
  <32, 26, 33>,
  <34, 33, 29>,
  <34, 29, 28>,
  <34, 28, 31>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8];
 #local P1 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13];
 #local P2 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2];
 #local P3 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3];
 #local P4 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_47_gyroelongated_pentagonal_cupolarotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_47_gyroelongated_pentagonal_cupolarotunda_obj }
#end
#end

#macro Johnson_47_gyroelongated_pentagonal_cupolarotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[17], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[19], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[24], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[25], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[27], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[30], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[31], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[32], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[33], RadVer }
  sphere { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[34], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[30], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[19], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[24], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[30], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[19], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[19], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[24], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[17], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[27], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[27], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[24], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[17], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[17], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[27], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[25], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[25], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[32], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[32], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[27], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[25], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[25], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[32], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[33], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[33], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[34], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[34], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[32], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[33], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[33], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[34], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[31], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[31], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[30], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[30], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[34], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[31], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[31], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[11], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[14], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[4], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[9], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[0], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[6], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[1], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[10], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[5], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[15], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[12], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[23], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[18], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[28], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[21], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[29], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[16], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[20], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[26], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[22], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7], RadEdg }
  cylinder { Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3], Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[8];
 #local P1 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[13];
 #local P2 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[2];
 #local P3 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[3];
 #local P4 = Johnson_47_gyroelongated_pentagonal_cupolarotunda_verts[7];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end

#declare Johnson_48_gyroelongated_pentagonal_birotunda_verts = array[40]
{
<-1.023844, 0.349350, 0.211966>,
<-1.022840, 0.245289, -0.329944>,
<-0.984402, -0.132386, 0.478181>,
<-0.982778, -0.300762, -0.398647>,
<-0.959023, -0.534178, 0.100801>,
<-0.762835, 0.690856, -0.134076>,
<-0.724398, 0.313181, 0.674049>,
<-0.721770, 0.040743, -0.744690>,
<-0.659577, -0.570348, 0.562884>,
<-0.657953, -0.738723, -0.313945>,
<-0.302078, 0.865747, 0.114140>,
<-0.301074, 0.761686, -0.427769>,
<-0.278322, 0.632332, 0.613589>,
<-0.275694, 0.359894, -0.805149>,
<-0.238881, 0.150594, 0.879804>,
<-0.235633, -0.186157, -0.873853>,
<-0.198819, -0.395456, 0.811100>,
<-0.196192, -0.667893, -0.607638>,
<-0.173439, -0.797247, 0.433720>,
<-0.172436, -0.901309, -0.108190>,
<0.169627, 0.892069, -0.170988>,
<0.181588, 0.824063, 0.376487>,
<0.183498, 0.626126, -0.654287>,
<0.214813, 0.448086, 0.779020>
<0.217902, 0.127816, -0.888807>,
<0.256610, -0.092255, 0.882858>,
<0.259699, -0.412524, -0.784969>,
<0.291015, -0.590564, 0.648338>,
<0.292924, -0.788502, -0.382436>,
<0.304885, -0.856507, 0.165038>,
<0.651020, 0.715912, -0.375257>,
<0.670374, 0.605876, 0.510575>,
<0.706688, -0.090371, -0.754719>,
<0.738003, -0.268411, 0.678589>,
<0.760446, -0.698716, -0.103406>,
<0.960498, 0.539035, 0.045972>,
<0.974369, 0.273093, -0.437327>,
<0.993723, 0.163058, 0.448505>,
<1.016166, -0.267247, -0.333489>,
<1.028128, -0.335253, 0.213985>,
}
#declare P0 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[0];
#declare P1 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[1];
#declare P2 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[2];
#declare V1 = P1 - P0;
#declare V2 = P2 - P0;
#declare Axis = vcross(V2, V1);
#declare Tran1 = transform { Reorient_Trans(Axis, y) }
#declare TV1 = vtransform(V1, Tran1);
#declare The_Tran = transform {
 Reorient_Trans(Axis, y)
 Reorient_Trans(TV1, x) }
#declare Num = 0;
#while (Num < 40)
 #declare Johnson_48_gyroelongated_pentagonal_birotunda_verts[Num] = vtransform(Johnson_48_gyroelongated_pentagonal_birotunda_verts[Num], The_Tran);
 #declare Num = Num + 1;
#end

#macro Johnson_48_gyroelongated_pentagonal_birotunda_faces(Tex3, Tex5, OnPlane)
#local Johnson_48_gyroelongated_pentagonal_birotunda_obj = mesh2 {
 vertex_vectors {
  40,
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[0],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[1],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[2],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[3],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[4],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[5],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[6],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[7],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[8],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[9],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[10],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[11],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[12],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[13],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[14],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[15],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[16],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[17],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[18],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[19],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[20],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[21],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[22],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[23],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[24],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[25],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[26],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[27],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[28],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[29],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[30],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[31],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[32],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[33],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[34],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[35],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[36],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[37],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[38],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[39]
 }
 texture_list {
  2,
  texture { Tex3 },
  texture { Tex5 }
 }
 face_indices {
  76,
  <0, 5, 1>, 0,
  <5, 10, 11>, 0,
  <1, 7, 3>, 0,
  <7, 13, 15>, 0,
  <3, 9, 4>, 0,
  <9, 17, 19>, 0,
  <4, 8, 2>, 0,
  <8, 18, 16>, 0,
  <2, 6, 0>, 0,
  <6, 14, 12>, 0,
  <35, 31, 37>, 0,
  <31, 21, 23>, 0,
  <37, 33, 39>, 0,
  <33, 25, 27>, 0,
  <39, 34, 38>, 0,
  <34, 29, 28>, 0,
  <38, 32, 36>, 0,
  <32, 26, 24>, 0,
  <36, 30, 35>, 0,
  <30, 22, 20>, 0,
  <17, 28, 19>, 0,
  <19, 28, 29>, 0,
  <19, 29, 18>, 0,
  <18, 29, 27>, 0,
  <18, 27, 16>, 0,
  <16, 27, 25>, 0,
  <16, 25, 14>, 0,
  <14, 25, 23>, 0,
  <14, 23, 12>, 0,
  <12, 23, 21>, 0,
  <12, 21, 10>, 0,
  <10, 21, 20>, 0,
  <10, 20, 11>, 0,
  <11, 20, 22>, 0,
  <11, 22, 13>, 0,
  <13, 22, 24>, 0,
  <13, 24, 15>, 0,
  <15, 24, 26>, 0,
  <15, 26, 17>, 0,
  <17, 26, 28>, 0,
  <0, 1, 3>, 1,
  <0, 3, 4>, 1,
  <0, 4, 2>, 1,
  <0, 6, 12>, 1,
  <0, 12, 10>, 1,
  <0, 10, 5>, 1,
  <1, 5, 11>, 1,
  <1, 11, 13>, 1,
  <1, 13, 7>, 1,
  <3, 7, 15>, 1,
  <3, 15, 17>, 1,
  <3, 17, 9>, 1,
  <4, 9, 19>, 1,
  <4, 19, 18>, 1,
  <4, 18, 8>, 1,
  <2, 8, 16>, 1,
  <2, 16, 14>, 1,
  <2, 14, 6>, 1,
  <35, 37, 39>, 1,
  <35, 39, 38>, 1,
  <35, 38, 36>, 1,
  <35, 30, 20>, 1,
  <35, 20, 21>, 1,
  <35, 21, 31>, 1,
  <37, 31, 23>, 1,
  <37, 23, 25>, 1,
  <37, 25, 33>, 1,
  <39, 33, 27>, 1,
  <39, 27, 29>, 1,
  <39, 29, 34>, 1,
  <38, 34, 28>, 1,
  <38, 28, 26>, 1,
  <38, 26, 32>, 1,
  <36, 32, 24>, 1,
  <36, 24, 22>, 1,
  <36, 22, 30>, 1
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[0];
 #local P1 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[1];
 #local P2 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[2];
 #local P3 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[3];
 #local P4 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_48_gyroelongated_pentagonal_birotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_48_gyroelongated_pentagonal_birotunda_obj }
#end
#end

#macro Johnson_48_gyroelongated_pentagonal_birotunda_faces2(OnPlane)
#local Johnson_48_gyroelongated_pentagonal_birotunda_obj = mesh2 {
 vertex_vectors {
  40,
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[0],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[1],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[2],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[3],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[4],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[5],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[6],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[7],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[8],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[9],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[10],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[11],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[12],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[13],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[14],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[15],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[16],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[17],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[18],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[19],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[20],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[21],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[22],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[23],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[24],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[25],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[26],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[27],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[28],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[29],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[30],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[31],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[32],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[33],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[34],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[35],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[36],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[37],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[38],
  Johnson_48_gyroelongated_pentagonal_birotunda_verts[39]
 }
 face_indices {
  76,
  <0, 5, 1>,
  <5, 10, 11>,
  <1, 7, 3>,
  <7, 13, 15>,
  <3, 9, 4>,
  <9, 17, 19>,
  <4, 8, 2>,
  <8, 18, 16>,
  <2, 6, 0>,
  <6, 14, 12>,
  <35, 31, 37>,
  <31, 21, 23>,
  <37, 33, 39>,
  <33, 25, 27>,
  <39, 34, 38>,
  <34, 29, 28>,
  <38, 32, 36>,
  <32, 26, 24>,
  <36, 30, 35>,
  <30, 22, 20>,
  <17, 28, 19>,
  <19, 28, 29>,
  <19, 29, 18>,
  <18, 29, 27>,
  <18, 27, 16>,
  <16, 27, 25>,
  <16, 25, 14>,
  <14, 25, 23>,
  <14, 23, 12>,
  <12, 23, 21>,
  <12, 21, 10>,
  <10, 21, 20>,
  <10, 20, 11>,
  <11, 20, 22>,
  <11, 22, 13>,
  <13, 22, 24>,
  <13, 24, 15>,
  <15, 24, 26>,
  <15, 26, 17>,
  <17, 26, 28>,
  <0, 1, 3>,
  <0, 3, 4>,
  <0, 4, 2>,
  <0, 6, 12>,
  <0, 12, 10>,
  <0, 10, 5>,
  <1, 5, 11>,
  <1, 11, 13>,
  <1, 13, 7>,
  <3, 7, 15>,
  <3, 15, 17>,
  <3, 17, 9>,
  <4, 9, 19>,
  <4, 19, 18>,
  <4, 18, 8>,
  <2, 8, 16>,
  <2, 16, 14>,
  <2, 14, 6>,
  <35, 37, 39>,
  <35, 39, 38>,
  <35, 38, 36>,
  <35, 30, 20>,
  <35, 20, 21>,
  <35, 21, 31>,
  <37, 31, 23>,
  <37, 23, 25>,
  <37, 25, 33>,
  <39, 33, 27>,
  <39, 27, 29>,
  <39, 29, 34>,
  <38, 34, 28>,
  <38, 28, 26>,
  <38, 26, 32>,
  <36, 32, 24>,
  <36, 24, 22>,
  <36, 22, 30>
 }
 inside_vector y
 hollow }
#if (OnPlane)
 #local P0 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[0];
 #local P1 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[1];
 #local P2 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[2];
 #local P3 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[3];
 #local P4 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
 object {
  Johnson_48_gyroelongated_pentagonal_birotunda_obj
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
 }
#else
 object { Johnson_48_gyroelongated_pentagonal_birotunda_obj }
#end
#end

#macro Johnson_48_gyroelongated_pentagonal_birotunda_edges(RadEdg, RadVer, TexEdg, TexVer, OnPlane)
union {
 union {
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[0], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[1], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[2], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[3], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[4], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[5], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[6], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[7], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[8], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[9], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[10], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[11], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[12], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[13], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[14], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[15], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[16], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[17], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[18], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[19], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[20], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[21], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[22], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[23], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[24], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[25], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[26], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[27], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[28], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[29], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[30], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[31], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[32], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[33], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[34], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[35], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[36], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[37], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[38], RadVer }
  sphere { Johnson_48_gyroelongated_pentagonal_birotunda_verts[39], RadVer }
  texture { TexVer } }
 union {
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[0], Johnson_48_gyroelongated_pentagonal_birotunda_verts[5], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[5], Johnson_48_gyroelongated_pentagonal_birotunda_verts[1], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[1], Johnson_48_gyroelongated_pentagonal_birotunda_verts[0], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[5], Johnson_48_gyroelongated_pentagonal_birotunda_verts[10], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[10], Johnson_48_gyroelongated_pentagonal_birotunda_verts[11], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[11], Johnson_48_gyroelongated_pentagonal_birotunda_verts[5], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[1], Johnson_48_gyroelongated_pentagonal_birotunda_verts[7], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[7], Johnson_48_gyroelongated_pentagonal_birotunda_verts[3], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[3], Johnson_48_gyroelongated_pentagonal_birotunda_verts[1], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[7], Johnson_48_gyroelongated_pentagonal_birotunda_verts[13], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[13], Johnson_48_gyroelongated_pentagonal_birotunda_verts[15], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[15], Johnson_48_gyroelongated_pentagonal_birotunda_verts[7], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[3], Johnson_48_gyroelongated_pentagonal_birotunda_verts[9], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[9], Johnson_48_gyroelongated_pentagonal_birotunda_verts[4], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[4], Johnson_48_gyroelongated_pentagonal_birotunda_verts[3], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[9], Johnson_48_gyroelongated_pentagonal_birotunda_verts[17], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[17], Johnson_48_gyroelongated_pentagonal_birotunda_verts[19], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[19], Johnson_48_gyroelongated_pentagonal_birotunda_verts[9], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[4], Johnson_48_gyroelongated_pentagonal_birotunda_verts[8], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[8], Johnson_48_gyroelongated_pentagonal_birotunda_verts[2], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[2], Johnson_48_gyroelongated_pentagonal_birotunda_verts[4], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[8], Johnson_48_gyroelongated_pentagonal_birotunda_verts[18], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[18], Johnson_48_gyroelongated_pentagonal_birotunda_verts[16], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[16], Johnson_48_gyroelongated_pentagonal_birotunda_verts[8], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[2], Johnson_48_gyroelongated_pentagonal_birotunda_verts[6], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[6], Johnson_48_gyroelongated_pentagonal_birotunda_verts[0], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[0], Johnson_48_gyroelongated_pentagonal_birotunda_verts[2], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[6], Johnson_48_gyroelongated_pentagonal_birotunda_verts[14], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[14], Johnson_48_gyroelongated_pentagonal_birotunda_verts[12], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[12], Johnson_48_gyroelongated_pentagonal_birotunda_verts[6], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[35], Johnson_48_gyroelongated_pentagonal_birotunda_verts[31], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[31], Johnson_48_gyroelongated_pentagonal_birotunda_verts[37], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[37], Johnson_48_gyroelongated_pentagonal_birotunda_verts[35], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[31], Johnson_48_gyroelongated_pentagonal_birotunda_verts[21], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[21], Johnson_48_gyroelongated_pentagonal_birotunda_verts[23], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[23], Johnson_48_gyroelongated_pentagonal_birotunda_verts[31], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[37], Johnson_48_gyroelongated_pentagonal_birotunda_verts[33], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[33], Johnson_48_gyroelongated_pentagonal_birotunda_verts[39], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[39], Johnson_48_gyroelongated_pentagonal_birotunda_verts[37], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[33], Johnson_48_gyroelongated_pentagonal_birotunda_verts[25], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[25], Johnson_48_gyroelongated_pentagonal_birotunda_verts[27], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[27], Johnson_48_gyroelongated_pentagonal_birotunda_verts[33], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[39], Johnson_48_gyroelongated_pentagonal_birotunda_verts[34], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[34], Johnson_48_gyroelongated_pentagonal_birotunda_verts[38], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[38], Johnson_48_gyroelongated_pentagonal_birotunda_verts[39], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[34], Johnson_48_gyroelongated_pentagonal_birotunda_verts[29], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[29], Johnson_48_gyroelongated_pentagonal_birotunda_verts[28], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[28], Johnson_48_gyroelongated_pentagonal_birotunda_verts[34], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[38], Johnson_48_gyroelongated_pentagonal_birotunda_verts[32], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[32], Johnson_48_gyroelongated_pentagonal_birotunda_verts[36], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[36], Johnson_48_gyroelongated_pentagonal_birotunda_verts[38], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[32], Johnson_48_gyroelongated_pentagonal_birotunda_verts[26], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[26], Johnson_48_gyroelongated_pentagonal_birotunda_verts[24], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[24], Johnson_48_gyroelongated_pentagonal_birotunda_verts[32], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[36], Johnson_48_gyroelongated_pentagonal_birotunda_verts[30], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[30], Johnson_48_gyroelongated_pentagonal_birotunda_verts[35], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[35], Johnson_48_gyroelongated_pentagonal_birotunda_verts[36], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[30], Johnson_48_gyroelongated_pentagonal_birotunda_verts[22], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[22], Johnson_48_gyroelongated_pentagonal_birotunda_verts[20], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[20], Johnson_48_gyroelongated_pentagonal_birotunda_verts[30], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[17], Johnson_48_gyroelongated_pentagonal_birotunda_verts[28], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[28], Johnson_48_gyroelongated_pentagonal_birotunda_verts[19], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[29], Johnson_48_gyroelongated_pentagonal_birotunda_verts[19], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[29], Johnson_48_gyroelongated_pentagonal_birotunda_verts[18], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[18], Johnson_48_gyroelongated_pentagonal_birotunda_verts[19], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[29], Johnson_48_gyroelongated_pentagonal_birotunda_verts[27], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[27], Johnson_48_gyroelongated_pentagonal_birotunda_verts[18], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[27], Johnson_48_gyroelongated_pentagonal_birotunda_verts[16], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[25], Johnson_48_gyroelongated_pentagonal_birotunda_verts[16], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[25], Johnson_48_gyroelongated_pentagonal_birotunda_verts[14], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[14], Johnson_48_gyroelongated_pentagonal_birotunda_verts[16], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[25], Johnson_48_gyroelongated_pentagonal_birotunda_verts[23], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[23], Johnson_48_gyroelongated_pentagonal_birotunda_verts[14], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[23], Johnson_48_gyroelongated_pentagonal_birotunda_verts[12], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[21], Johnson_48_gyroelongated_pentagonal_birotunda_verts[12], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[21], Johnson_48_gyroelongated_pentagonal_birotunda_verts[10], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[10], Johnson_48_gyroelongated_pentagonal_birotunda_verts[12], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[21], Johnson_48_gyroelongated_pentagonal_birotunda_verts[20], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[20], Johnson_48_gyroelongated_pentagonal_birotunda_verts[10], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[20], Johnson_48_gyroelongated_pentagonal_birotunda_verts[11], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[22], Johnson_48_gyroelongated_pentagonal_birotunda_verts[11], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[22], Johnson_48_gyroelongated_pentagonal_birotunda_verts[13], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[13], Johnson_48_gyroelongated_pentagonal_birotunda_verts[11], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[22], Johnson_48_gyroelongated_pentagonal_birotunda_verts[24], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[24], Johnson_48_gyroelongated_pentagonal_birotunda_verts[13], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[24], Johnson_48_gyroelongated_pentagonal_birotunda_verts[15], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[26], Johnson_48_gyroelongated_pentagonal_birotunda_verts[15], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[26], Johnson_48_gyroelongated_pentagonal_birotunda_verts[17], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[17], Johnson_48_gyroelongated_pentagonal_birotunda_verts[15], RadEdg }
  cylinder { Johnson_48_gyroelongated_pentagonal_birotunda_verts[26], Johnson_48_gyroelongated_pentagonal_birotunda_verts[28], RadEdg }
  texture { TexEdg } }
#if (OnPlane)
 #local P0 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[0];
 #local P1 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[1];
 #local P2 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[2];
 #local P3 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[3];
 #local P4 = Johnson_48_gyroelongated_pentagonal_birotunda_verts[4];
 #local V1 = P1 - P0;
 #local V2 = P2 - P0;
 #local Axis = vcross(V2, V1);
  translate -(P0+P1+P2+P3+P4)/5
  Reorient_Trans(Axis, y)
  translate y*max(RadEdg, RadVer)
#end
 }
#end
