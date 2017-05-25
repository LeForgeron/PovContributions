// Title:        MultiObjectPattern
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   June 19, 2008
// Last updated: June 24, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(Multiobj_Inc)
#declare Multiobj_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including multiobj.inc\n"
#end

// The examples used in this file can be found in multiobj_examples.pov.  More
// complex examples are in multiobj.pov.

// MultiObj_Ptrn
// Creates a function pattern similar to the "object" pattern, only with
// more than one object.  The function created returns a different value
// depending on which object the input point lies inside of.  The pattern can
// be used with any kind of map (color_map, texture_map, etc.) to produce multi-
// object pigments, textures, normals, etc.
//  Objects - This is an array of objects to use in the pattern.  The number
//            of input objects determines the return value of the pattern. If
//            N objects are in the array then if the input point lies inside
//            the first object, the function returns 1/N.  If it lies inside the
//            second, it returns 2/N, and so on to the last item which returns N/N 
//            (aka 1).  The function returns zero if the point is outside of all 
//            the input objects.  In the case where the input point lies inside
//            more than one object, the object closest to the end of the array takes
//            precedence.  So if the input point lies inside both the first and third
//            objects, the funtion will return 3/N.
//
// Example:
//
// #declare Objs =
//   array[3] {
//     box { <-1.5, -1.5, -2>, <1.5, 1.5, 2> },
//     box { <-1, -1, -2>, <1, 1, 2> },
//     cylinder { z * -2, z * 2, 0.5 }
//   };
//
//  box {
//    -1, 1
//    pigment {
//      MultiObj_Ptrn(Objs)
//      color_map {
//        [0   Blue]
//        [1/3 Red]
//        [2/3 Green]
//        [1   Yellow]
//      }
//    }
//  }
//
//
#macro MultiObj_Ptrn(Objects)

  #local Count = dimension_size(Objects, 1);
  
  #if(Count > 1)
    #local F = function { 0 }

    function {
      max(
        #local Ct = 0;
        #while(Ct < Count)
          #undef F
          #local F =
            function {
              pattern {
                object { Objects[Ct] }
              }
            }
          F(x, y, z) * (Ct + 1)/Count
          #if(Ct < Count - 1) , #end
          #local Ct = Ct + 1;
        #end
      )
    }
      
  #else
    #local F =
      function {
        pattern {
          object { Objects[0] }
        }
      }
    
    function { F(x, y, z) }
  #end
#end

// MultiObj_Ptrn_1 .. 6
// These are shortcut macros for creating multi-object patterns for one
// to six objects without needing to declare an array.
//
// Examples:
// // Using predeclared objects:
// #declare Box1 =
//   box {
//    <-1, -1, -3>, <1, 1, 3>
//    translate <0.5, 0.5, 0>
//   }
// 
// #declare Box2 =
//   box {
//     <-1, -1, -3>, <1, 1, 3>
//   }
// 
// #declare Box3 =
//   box {
//     <-1, -1, -3>, <1, 1, 3>
//     translate <-0.5, -0.5, 0>
//   }
//   
// box {
//   -2, 2
//   pigment {
//     MultiObj_Ptrn_3(Box1, Box2, Box3)
//     color_map {
//       [0   Blue]
//       [1/3 Red]
//       [2/3 Green]
//       [1   Yellow]
//     }
//   }
// }
//
// // Using inline objects
// 
// box {
//   -2, 2
//   pigment {
//     MultiObj_Ptrn_3(
//       cylinder { <-0.5, 0, -3>, <-0.5, 0, 3>, 0.5 },
//       cylinder { z * -3, z * 3, 0.5 },
//       cylinder { <0.5, 0, -3>, <0.5, 0, 3>, 0.5 }
//     )      
//     color_map {
//       [0   Blue]
//       [1/3 Red]
//       [2/3 Green]
//       [1   Yellow]
//     }
//   }
// }
//
#macro MultiObj_Ptrn_1(Obj)
  #local Objects = array[1] { Obj };
  MultiObj_Ptrn(Objects)
#end

#macro MultiObj_Ptrn_2(Obj_1, Obj_2)
  #local Objects = array[2] { Obj_1, Obj_2 };
  MultiObj_Ptrn(Objects)
#end

#macro MultiObj_Ptrn_3(Obj_1, Obj_2, Obj_3)
  #local Objects = array[3] { Obj_1, Obj_2, Obj_3 };
  MultiObj_Ptrn(Objects)
#end

#macro MultiObj_Ptrn_4(Obj_1, Obj_2, Obj_3, Obj_4)
  #local Objects = array[4] { Obj_1, Obj_2, Obj_3, Obj_4 };
  MultiObj_Ptrn(Objects)
#end

#macro MultiObj_Ptrn_5(Obj_1, Obj_2, Obj_3, Obj_4, Obj_5)
  #local Objects = array[5] { Obj_1, Obj_2, Obj_3, Obj_4, Obj_5 };
  MultiObj_Ptrn(Objects)
#end

#macro MultiObj_Ptrn_6(Obj_1, Obj_2, Obj_3, Obj_4, Obj_5, Obj_6)
  #local Objects = array[6] { Obj_1, Obj_2, Obj_3, Obj_4, Obj_5, Obj_6 };
  MultiObj_Ptrn(Objects)
#end
   
#version Multiobj_Inc;
#end
