// Example file for using the johnson_solids_groupx.inc
// Bill Pragnell 2009
//
// This file is licensed under the terms of the CC-LGPL 

#include "johnson_solids_group1.inc"
#include "johnson_solids_group2.inc"
#include "johnson_solids_group3.inc"
#include "johnson_solids_group4.inc"
#include "johnson_solids_group5.inc"
#include "johnson_solids_group6.inc"
#include "johnson_solids_group7.inc"

global_settings {
 assumed_gamma 1
 radiosity { 
  pretrace_start 0.08
  pretrace_end 0.01
  error_bound 0.2
  count 150
  low_error_factor 0.5
  minimum_reuse 0.01
  recursion_limit 1
  nearest_count 4
  gray_threshold 0
  brightness 1 } }

camera {
 location <-5, 35, -25>
 up y
 right x
 angle 45
 look_at <0, 0, 0> }

light_source {
 <100, 150, -25> color rgb 1
 area_light 25*x, 25*y, 8, 8 circular orient adaptive 1 jitter }

// -----
// Create an array of objects containing the plain faces polyhedra.
// -----
#declare Johnsons = array[92];
// Group 1 - prismatoids and rotundae
#declare Johnsons[0] = object { Johnson_01_square_pyramid_faces2(yes) }
#declare Johnsons[1] = object { Johnson_02_pentagonal_pyramid_faces2(yes) }
#declare Johnsons[2] = object { Johnson_03_triangular_cupola_faces2(yes) }
#declare Johnsons[3] = object { Johnson_04_square_cupola_faces2(yes) }
#declare Johnsons[4] = object { Johnson_05_pentagonal_cupola_faces2(yes) }
#declare Johnsons[5] = object { Johnson_06_pentagonal_rotunda_faces2(yes) }
// Group 2 - modified pyramids and dipyramids
#declare Johnsons[6] = object { Johnson_07_elongated_triangular_pyramid_faces2(yes) }
#declare Johnsons[7] = object { Johnson_08_elongated_square_pyramid_faces2(yes) }
#declare Johnsons[8] = object { Johnson_09_elongated_pentagonal_pyramid_faces2(yes) }
#declare Johnsons[9] = object { Johnson_10_gyroelongated_square_pyramid_faces2(yes) }
#declare Johnsons[10] = object { Johnson_11_gyroelongated_pentagonal_pyramid_faces2(yes) }
#declare Johnsons[11] = object { Johnson_12_triangular_dipyramid_faces2(yes) }
#declare Johnsons[12] = object { Johnson_13_pentagonal_dipyramid_faces2(yes) }
#declare Johnsons[13] = object { Johnson_14_elongated_triangular_dipyramid_faces2(yes) }
#declare Johnsons[14] = object { Johnson_15_elongated_square_dipyramid_faces2(yes) }
#declare Johnsons[15] = object { Johnson_16_elongated_pentagonal_dipyramid_faces2(yes) }
#declare Johnsons[16] = object { Johnson_17_gyroelongated_square_dipyramid_faces2(yes) }
// Group 3 - modified cupolas and rotundae
#declare Johnsons[17] = object { Johnson_18_elongated_triangular_cupola_faces2(yes) }
#declare Johnsons[18] = object { Johnson_19_elongated_square_cupola_faces2(yes) }
#declare Johnsons[19] = object { Johnson_20_elongated_pentagonal_cupola_faces2(yes) }
#declare Johnsons[20] = object { Johnson_21_elongated_pentagonal_rotunda_faces2(yes) }
#declare Johnsons[21] = object { Johnson_22_gyroelongated_triangular_cupola_faces2(yes) }
#declare Johnsons[22] = object { Johnson_23_gyroelongated_square_cupola_faces2(yes) }
#declare Johnsons[23] = object { Johnson_24_gyroelongated_pentagonal_cupola_faces2(yes) }
#declare Johnsons[24] = object { Johnson_25_gyroelongated_pentagonal_rotunda_faces2(yes) }
#declare Johnsons[25] = object { Johnson_26_gyrobifastigium_faces2(yes) }
#declare Johnsons[26] = object { Johnson_27_triangular_orthobicupola_faces2(yes) }
#declare Johnsons[27] = object { Johnson_28_square_orthobicupola_faces2(yes) }
#declare Johnsons[28] = object { Johnson_29_square_gyrobicupola_faces2(yes) }
#declare Johnsons[29] = object { Johnson_30_pentagonal_orthobicupola_faces2(yes) }
#declare Johnsons[30] = object { Johnson_31_pentagonal_gyrobicupola_faces2(yes) }
#declare Johnsons[31] = object { Johnson_32_pentagonal_orthocupolarotunda_faces2(yes) }
#declare Johnsons[32] = object { Johnson_33_pentagonal_gyrocupolarotunda_faces2(yes) }
#declare Johnsons[33] = object { Johnson_34_pentagonal_orthobirotunda_faces2(yes) }
#declare Johnsons[34] = object { Johnson_35_elongated_triangular_orthobicupola_faces2(yes) }
#declare Johnsons[35] = object { Johnson_36_elongated_triangular_gyrobicupola_faces2(yes) }
#declare Johnsons[36] = object { Johnson_37_elongated_square_gyrobicupola_faces2(yes) }
#declare Johnsons[37] = object { Johnson_38_elongated_pentagonal_orthobicupola_faces2(yes) }
#declare Johnsons[38] = object { Johnson_39_elongated_pentagonal_gyrobicupola_faces2(yes) }
#declare Johnsons[39] = object { Johnson_40_elongated_pentagonal_orthocupolarotunda_faces2(yes) }
#declare Johnsons[40] = object { Johnson_41_elongated_pentagonal_gyrocupolarotunda_faces2(yes) }
#declare Johnsons[41] = object { Johnson_42_elongated_pentagonal_orthobirotunda_faces2(yes) }
#declare Johnsons[42] = object { Johnson_43_elongated_pentagonal_gyrobirotunda_faces2(yes) }
#declare Johnsons[43] = object { Johnson_44_gyroelongated_triangular_bicupola_faces2(yes) }
#declare Johnsons[44] = object { Johnson_45_gyroelongated_square_bicupola_faces2(yes) }
#declare Johnsons[45] = object { Johnson_46_gyroelongated_pentagonal_bicupola_faces2(yes) }
#declare Johnsons[46] = object { Johnson_47_gyroelongated_pentagonal_cupolarotunda_faces2(yes) }
#declare Johnsons[47] = object { Johnson_48_gyroelongated_pentagonal_birotunda_faces2(yes) }
// Group 4 - augmented prisms
#declare Johnsons[48] = object { Johnson_49_augmented_triangular_prism_faces2(yes) }
#declare Johnsons[49] = object { Johnson_50_biaugmented_triangular_prism_faces2(yes) }
#declare Johnsons[50] = object { Johnson_51_triaugmented_triangular_prism_faces2(yes) }
#declare Johnsons[51] = object { Johnson_52_augmented_pentagonal_prism_faces2(yes) }
#declare Johnsons[52] = object { Johnson_53_biaugmented_pentagonal_prism_faces2(yes) }
#declare Johnsons[53] = object { Johnson_54_augmented_hexagonal_prism_faces2(yes) }
#declare Johnsons[54] = object { Johnson_55_parabiaugmented_hexagonal_prism_faces2(yes) }
#declare Johnsons[55] = object { Johnson_56_metabiaugmented_hexagonal_prism_faces2(yes) }
#declare Johnsons[56] = object { Johnson_57_triaugmented_hexagonal_prism_faces2(yes) }
// Group 5 - modified platonic solids
#declare Johnsons[57] = object { Johnson_58_augmented_dodecahedron_faces2(yes) }
#declare Johnsons[58] = object { Johnson_59_parabiaugmented_dodecahedron_faces2(yes) }
#declare Johnsons[59] = object { Johnson_60_metabiaugmented_dodecahedron_faces2(yes) }
#declare Johnsons[60] = object { Johnson_61_triaugmented_dodecahedron_faces2(yes) }
#declare Johnsons[61] = object { Johnson_62_metabidiminished_icosahedron_faces2(yes) }
#declare Johnsons[62] = object { Johnson_63_tridiminished_icosahedron_faces2(yes) }
#declare Johnsons[63] = object { Johnson_64_augmented_tridiminished_icosahedron_faces2(yes) }
// Group 6 - modified archimedean solids
#declare Johnsons[64] = object { Johnson_65_augmented_truncated_tetrahedron_faces2(yes) }
#declare Johnsons[65] = object { Johnson_66_augmented_truncated_cube_faces2(yes) }
#declare Johnsons[66] = object { Johnson_67_biaugmented_truncated_cube_faces2(yes) }
#declare Johnsons[67] = object { Johnson_68_augmented_truncated_dodecahedron_faces2(yes) }
#declare Johnsons[68] = object { Johnson_69_parabiaugmented_truncated_dodecahedron_faces2(yes) }
#declare Johnsons[69] = object { Johnson_70_metabiaugmented_truncated_dodecahedron_faces2(yes) }
#declare Johnsons[70] = object { Johnson_71_triaugmented_truncated_dodecahedron_faces2(yes) }
#declare Johnsons[71] = object { Johnson_72_gyrate_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[72] = object { Johnson_73_parabigyrate_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[73] = object { Johnson_74_metabigyrate_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[74] = object { Johnson_75_trigyrate_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[75] = object { Johnson_76_diminished_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[76] = object { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[77] = object { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[78] = object { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[79] = object { Johnson_80_parabidiminished_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[80] = object { Johnson_81_metabidiminished_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[81] = object { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_faces2(yes) }
#declare Johnsons[82] = object { Johnson_83_tridiminished_rhombicosidodecahedron_faces2(yes) }
// Group 7 - miscellaneous
#declare Johnsons[83] = object { Johnson_84_snub_disphenoid_faces2(yes) }
#declare Johnsons[84] = object { Johnson_85_snub_square_antiprism_faces2(yes) }
#declare Johnsons[85] = object { Johnson_86_sphenocorona_faces2(yes) }
#declare Johnsons[86] = object { Johnson_87_augmented_sphenocorona_faces2(yes) }
#declare Johnsons[87] = object { Johnson_88_sphenomegacorona_faces2(yes) }
#declare Johnsons[88] = object { Johnson_89_hebesphenomegacorona_faces2(yes) }
#declare Johnsons[89] = object { Johnson_90_disphenocingulum_faces2(yes) }
#declare Johnsons[90] = object { Johnson_91_bilunabirotunda_faces2(yes) }
#declare Johnsons[91] = object { Johnson_92_triangular_hebesphenorotunda_faces2(yes) }

// -----
// Create an array of objects containing the edges/vertices of the polyhedra.
// -----
#declare EdgeT = texture { pigment { rgb 1 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare VertT = texture { pigment { rgb 0.75 } finish { ambient 0 specular 1 roughness 0.01 } }
#declare R_Edge = 0.03;
#declare R_Vertex = 0.06;
#declare Johnson_skels = array[92];
// Group 1 - prismatoids and rotundae
#declare Johnson_skels[0] = object { Johnson_01_square_pyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[1] = object { Johnson_02_pentagonal_pyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[2] = object { Johnson_03_triangular_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[3] = object { Johnson_04_square_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[4] = object { Johnson_05_pentagonal_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[5] = object { Johnson_06_pentagonal_rotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
// Group 2 - modified pyramids and dipyramids
#declare Johnson_skels[6] = object { Johnson_07_elongated_triangular_pyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[7] = object { Johnson_08_elongated_square_pyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[8] = object { Johnson_09_elongated_pentagonal_pyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[9] = object { Johnson_10_gyroelongated_square_pyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[10] = object { Johnson_11_gyroelongated_pentagonal_pyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[11] = object { Johnson_12_triangular_dipyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[12] = object { Johnson_13_pentagonal_dipyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[13] = object { Johnson_14_elongated_triangular_dipyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[14] = object { Johnson_15_elongated_square_dipyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[15] = object { Johnson_16_elongated_pentagonal_dipyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[16] = object { Johnson_17_gyroelongated_square_dipyramid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
// Group 3 - modified cupolas and rotundae
#declare Johnson_skels[17] = object { Johnson_18_elongated_triangular_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[18] = object { Johnson_19_elongated_square_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[19] = object { Johnson_20_elongated_pentagonal_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[20] = object { Johnson_21_elongated_pentagonal_rotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[21] = object { Johnson_22_gyroelongated_triangular_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[22] = object { Johnson_23_gyroelongated_square_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[23] = object { Johnson_24_gyroelongated_pentagonal_cupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[24] = object { Johnson_25_gyroelongated_pentagonal_rotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[25] = object { Johnson_26_gyrobifastigium_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[26] = object { Johnson_27_triangular_orthobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[27] = object { Johnson_28_square_orthobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[28] = object { Johnson_29_square_gyrobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[29] = object { Johnson_30_pentagonal_orthobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[30] = object { Johnson_31_pentagonal_gyrobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[31] = object { Johnson_32_pentagonal_orthocupolarotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[32] = object { Johnson_33_pentagonal_gyrocupolarotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[33] = object { Johnson_34_pentagonal_orthobirotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[34] = object { Johnson_35_elongated_triangular_orthobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[35] = object { Johnson_36_elongated_triangular_gyrobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[36] = object { Johnson_37_elongated_square_gyrobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[37] = object { Johnson_38_elongated_pentagonal_orthobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[38] = object { Johnson_39_elongated_pentagonal_gyrobicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[39] = object { Johnson_40_elongated_pentagonal_orthocupolarotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[40] = object { Johnson_41_elongated_pentagonal_gyrocupolarotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[41] = object { Johnson_42_elongated_pentagonal_orthobirotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[42] = object { Johnson_43_elongated_pentagonal_gyrobirotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[43] = object { Johnson_44_gyroelongated_triangular_bicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[44] = object { Johnson_45_gyroelongated_square_bicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[45] = object { Johnson_46_gyroelongated_pentagonal_bicupola_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[46] = object { Johnson_47_gyroelongated_pentagonal_cupolarotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[47] = object { Johnson_48_gyroelongated_pentagonal_birotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
// Group 4 - augmented prisms
#declare Johnson_skels[48] = object { Johnson_49_augmented_triangular_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[49] = object { Johnson_50_biaugmented_triangular_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[50] = object { Johnson_51_triaugmented_triangular_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[51] = object { Johnson_52_augmented_pentagonal_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[52] = object { Johnson_53_biaugmented_pentagonal_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[53] = object { Johnson_54_augmented_hexagonal_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[54] = object { Johnson_55_parabiaugmented_hexagonal_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[55] = object { Johnson_56_metabiaugmented_hexagonal_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[56] = object { Johnson_57_triaugmented_hexagonal_prism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
// Group 5 - modified platonic solids
#declare Johnson_skels[57] = object { Johnson_58_augmented_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[58] = object { Johnson_59_parabiaugmented_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[59] = object { Johnson_60_metabiaugmented_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[60] = object { Johnson_61_triaugmented_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[61] = object { Johnson_62_metabidiminished_icosahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[62] = object { Johnson_63_tridiminished_icosahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[63] = object { Johnson_64_augmented_tridiminished_icosahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
// Group 6 - modified archimedean solids
#declare Johnson_skels[64] = object { Johnson_65_augmented_truncated_tetrahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[65] = object { Johnson_66_augmented_truncated_cube_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[66] = object { Johnson_67_biaugmented_truncated_cube_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[67] = object { Johnson_68_augmented_truncated_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[68] = object { Johnson_69_parabiaugmented_truncated_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[69] = object { Johnson_70_metabiaugmented_truncated_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[70] = object { Johnson_71_triaugmented_truncated_dodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[71] = object { Johnson_72_gyrate_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[72] = object { Johnson_73_parabigyrate_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[73] = object { Johnson_74_metabigyrate_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[74] = object { Johnson_75_trigyrate_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[75] = object { Johnson_76_diminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[76] = object { Johnson_77_paragyrate_diminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[77] = object { Johnson_78_metagyrate_diminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[78] = object { Johnson_79_bigyrate_diminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[79] = object { Johnson_80_parabidiminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[80] = object { Johnson_81_metabidiminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[81] = object { Johnson_82_gyrate_bidiminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[82] = object { Johnson_83_tridiminished_rhombicosidodecahedron_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
// Group 7 - miscellaneous
#declare Johnson_skels[83] = object { Johnson_84_snub_disphenoid_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[84] = object { Johnson_85_snub_square_antiprism_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[85] = object { Johnson_86_sphenocorona_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[86] = object { Johnson_87_augmented_sphenocorona_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[87] = object { Johnson_88_sphenomegacorona_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[88] = object { Johnson_89_hebesphenomegacorona_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[89] = object { Johnson_90_disphenocingulum_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[90] = object { Johnson_91_bilunabirotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }
#declare Johnson_skels[91] = object { Johnson_92_triangular_hebesphenorotunda_edges(R_Edge, R_Vertex, EdgeT, VertT, yes) }

// -----
// Loop through arrays and place the polyhedra (faces+edges) in a circular pattern.
// -----
// Please note that the faces need to be vertically translated by R_Vertex so they line up
// with the edges.
// -----
#declare Ang = 0;
#declare Num = 0;
#declare RNum = 0;
#declare Rad = 3;
#declare Dang = degrees(3/Rad);
#declare Nang = floor(360/Dang);
#declare Dang = 360/(Nang+1);
#while (Num < 92)
 // sorry about all this nonsense - it's just to get them spaced out nicely!
 object { Johnsons[Num] translate <0, 0.06, -Rad> rotate y*Ang pigment { rgb 1 } finish { ambient 0 } }
 object { Johnson_skels[Num] translate <0, 0, -Rad> rotate y*Ang }
 #declare Num = Num +  1;
 #declare RNum = RNum + 1;
 #if (RNum > Nang)
  #declare Rad = Rad + 3;
  #declare Dang = degrees(3/Rad);
  #declare Nang = floor(360/Dang);
  #declare Dang = 360/(Nang+1);
  #declare RNum = 0;
 #end
 #declare Ang = Ang +Dang;
#end

plane { y, 0 pigment { rgb 0.66 } finish { ambient 0 } }
background { rgb <0.1, 0.2, 0.25> }
