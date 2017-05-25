// flags.pov
// ---------

// This scene file illustrates the use of the Flags macro from the 'flags.inc' include file.
//
// This macro has two parameters:
//
//    Flags_Name       - Is a string naming the type of flag required, eg. "Olympic", "UnionJack",
//                       "UnionFlag1606", "StGeorgesCross", "StAndrewsCross", "StPatricksCross",
//                       "Wales", "Canada", "USA", "Australia", "New Zealand", "Ireland", "France", 
//                       "Belgium", "Italy", "Germany", "Austria", "Luxembourg", "Netherlands", 
//                       "Hungary", "Armenia", "Peru", "Nigeria", "Japan", "China", "Bulgaria".
//                       "Bolivia", "Estonia", "Gabon", "Lithuania", "Russia", "Yemen", "Ivory Coast".
//			 "Chad", "Guinea", "Mali", "Romania", "Sierra Leone", "Indonesia"."Monaco",
//			 "Poland", "Ukraine", "Mauritius", "Botswana", "Costa Rica", "Latvia",
//			 "Thailand", "Afghanistan", "Albania", "Algeria", "Andorra", "Angola"
//
//    Flags_ObjectType - Is a string naming the type of object to be used to build the flag:
//                       "mesh2", "height_field", "box". 
//
// This file is licensed under the terms of the CC-LGPL. 
// This license permits you to use, modify and redistribute the content.
// 
// Typical render time is 5 seconds for a single flag (at 640x480 AA 0.3).
// The generated object is about 5 POV-Ray units high and 10 units wide.
// Its bottom left hand corner is positioned at the origin and the flag
// stretches out in the +X and +Y directions. 
// 
// The include file contains a series of flag textures and a selection of
// different flag objects that each texture can be rendered onto.
// Most of the textures are procedural, but the macros also support the use 
// of image maps (see Example 6). Images showing sovereign flags can be found at:
// http://en.wikipedia.org/wiki/Gallery_of_sovereign_state_flags

// This file contains a series of separate examples, controlled using the 
// 'Example' variable:
//
//   Example = 0 renders the British Union Flag/Union Jack using a height field.
//   Example = 1 renders the Welsh Flag using a mesh2 object.
//   Example = 2 renders the set of British National flags on simple box objects. 
//   Example = 3 USA, Canada, Australia, New Zealand. 
//   Example = 4 Ireland, France, Belgium, Italy, Germany, Austria, Luxembourg, Netherlands, Hungary.
//   Example = 5 Armenia, Peru, Nigeria, Japan, China (R.O.C)
//   Example = 6 Image mapped flags of Spain and Portugal.  
//   Example = 7 Olympic flag.
//   Example = 8 UK and Welsh flags for thumbnail animation.
//   Example = 9 Bulgaria, Bolivia, Estonia, Gabon, Lithuania, Russia, Yemen, Ivory Coast and Chad
//   Example = 10 Guinea, Mali, Romania, Sierra Leone, Indonesia, Monaco, Poland, Ukraine, Mauritius
//   Example = 11 Botswana, Costa Rica, Latvia, Thailand, Afghanistan (raw), Albania (raw), Algeria (raw), Angola (raw)
//                              
// Examples using the "height_field" flag type can be animated using command-line options
//   +kfi0 +kff12 +kc  for example.
// Alternatively you can use the POV-Ray animation feature to cycle through all of the
// above examples using command-line options +kfi0 +kff6 and by using the 'frame_number'
// identifier as follows:
//             
// #declare Example = frame_number;              
//

#declare Example = 11;   


// British Union Flag/Union Jack
#if (Example=0)  
  camera {location <4.5,2.5,-8> look_at <5,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  Flags("UnionFlag","height_field", 1)                                               
#end
 

// Welsh Flag
#if (Example=1) 
  camera {location <4.5,2.5,-8> look_at <4.75,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  Flags("Wales","mesh2", 1)                                               
#end


// British Flags
#if (Example=2) 
  camera {orthographic location <16,8.5,-25> look_at <16,8.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  object {Flags("StGeorgesCross" ,"box", 1) translate 14*y     }                                               
  object {Flags("StAndrewsCross" ,"box", 1) translate <11,14,0>}                                               
  object {Flags("Wales"          ,"box", 1) translate <22,14,0>}                                               
  object {Flags("UnionFlag1606"  ,"box", 1) translate 7*y      }                                               
  object {Flags("StPatricksCross","box", 1) translate <11,7,0> }                                               
  object {Flags("UnionFlag"      ,"box", 1) translate <11,0,0> } 

  #local Text_Texture = texture {
    pigment { rgb <1,1,>}
    finish {phong 0.5 reflection 0.4}
  }
  text {ttf "timrom.ttf" "StGeorgesCross"      1, 0 texture {Text_Texture} translate 14*y     +<2.0,-1,0>}                                                   
  text {ttf "timrom.ttf" "StAndrewsCross"      1, 0 texture {Text_Texture} translate <11,14,0>+<1.5,-1,0>}                                              
  text {ttf "timrom.ttf" "Wales"               1, 0 texture {Text_Texture} translate <22,14,0>+<3.5,-1,0>}                                              
  text {ttf "timrom.ttf" "UnionFlag1606"       1, 0 texture {Text_Texture} translate 7*y      +<2.0,-1,0>}                                                    
  text {ttf "timrom.ttf" "StPatricksCross"     1, 0 texture {Text_Texture} translate <11,7,0> +<2.0,-1,0>}                                               
  text {ttf "timrom.ttf" "UnionFlag/UnionJack" 1, 0 texture {Text_Texture} translate <11,0,0> +<0.5,-1,0>}                                               
#end


// USA, Canada, Australia and New Zealand Flags.
#if (Example=3) 
  camera {orthographic location <11,5.5,-18> look_at <11,5.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  object {Flags("USA"        ,"box", 1) translate 7*y     }                                               
  object {Flags("Canada"     ,"box", 1) translate <12,7,0>}                                               
  object {Flags("Australia"  ,"box", 1) translate 0*y     }                                               
  object {Flags("NewZealand" ,"box", 1) translate <12,0,0>}                                               

  #local Text_Texture = texture {
    pigment { rgb <1,1,0>}
    finish {phong 0.5 reflection 0.4}
  }
  text {ttf "timrom.ttf" "USA"        1, 0 texture {Text_Texture} translate 7*y     +<4.0,-1,0>}                                                   
  text {ttf "timrom.ttf" "Canada"     1, 0 texture {Text_Texture} translate <12,7,0>+<3.5,-1,0>}                                              
  text {ttf "timrom.ttf" "Australia"  1, 0 texture {Text_Texture} translate 0*y     +<3.0,-1,0>}                                              
  text {ttf "timrom.ttf" "NewZealand" 1, 0 texture {Text_Texture} translate <12,0,0>+<2.3,-1,0>}                                                    
#end


// Ireland, France, Belgium, Italy, Germany, Austria, Luxembourg, Netherlands, Hungary.
#if (Example=4) 
  camera {orthographic location <16,10.5,-28> look_at <16,10.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  background {rgb 0.1} 
  #include "flags.inc" 
  object {Flags("Ireland"    ,"box", 1) translate < 0,16,0>}                                               
  object {Flags("France"     ,"box", 1) translate <11,16,0>}                                               
  object {Flags("Belgium"    ,"box", 1) translate <22,16,0>}                                               
  object {Flags("Italy"      ,"box", 1) translate < 0, 8,0>}                                               
  object {Flags("Germany"    ,"box", 1) translate <11, 8,0>}                                               
  object {Flags("Austria"    ,"box", 1) translate <22, 8,0>} 
  object {Flags("Luxembourg" ,"box", 1) translate < 0, 0,0>} 
  object {Flags("Netherlands","box", 1) translate <11, 0,0>} 
  object {Flags("Hungary"    ,"box", 1) translate <22, 0,0>} 
  

  #local Text_Texture = texture {
    pigment { rgb <1,1,>}
    finish {phong 0.5 reflection 0.4}
  }
  text {ttf "timrom.ttf" "Ireland"     1, 0 texture {Text_Texture} translate < 0,16,0>+<3.0,-1,0>}                                                   
  text {ttf "timrom.ttf" "France"      1, 0 texture {Text_Texture} translate <11,16,0>+<3.2,-1,0>}                                              
  text {ttf "timrom.ttf" "Belgium"     1, 0 texture {Text_Texture} translate <22,16,0>+<2.9,-1,0>}                                              
  text {ttf "timrom.ttf" "Italy"       1, 0 texture {Text_Texture} translate < 0, 8,0>+<3.7,-1,0>}                                                    
  text {ttf "timrom.ttf" "Germany"     1, 0 texture {Text_Texture} translate <11, 8,0>+<3.0,-1,0>}                                               
  text {ttf "timrom.ttf" "Austria"     1, 0 texture {Text_Texture} translate <22, 8,0>+<3.0,-1,0>}                                               
  text {ttf "timrom.ttf" "Luxembourg"  1, 0 texture {Text_Texture} translate < 0, 0,0>+<2.5,-1,0>}                                               
  text {ttf "timrom.ttf" "Netherlands" 1, 0 texture {Text_Texture} translate <11, 0,0>+<2.0,-1,0>}                                               
  text {ttf "timrom.ttf" "Hungary"     1, 0 texture {Text_Texture} translate <22, 0,0>+<3.2,-1,0>}                                               
#end


// Armenia, Peru, Nigeria, Japan, China (R.O.C)
#if (Example=5) 
  camera {orthographic location <16,10.5,-28> look_at <16,10.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  background {rgb 0.1} 
  #include "flags.inc" 
  object {Flags("Armenia"    ,"box", 1) translate < 0,16,0>}                                               
  object {Flags("Peru"       ,"box", 1) translate <11,16,0>}                                               
  object {Flags("Nigeria"    ,"box", 1) translate <22,16,0>}                                               
  object {Flags("Japan"      ,"box", 1) translate < 0, 8,0>}                                               
  object {Flags("China"      ,"box", 1) translate <11, 8,0>}                                               
  
  #local Text_Texture = texture {
    pigment { rgb <1,1,>}
    finish {phong 0.5 reflection 0.4}
  }
  text {ttf "timrom.ttf" "Armenia"    1, 0 texture {Text_Texture} translate < 0,16,0>+<3.0,-1,0>}                                                   
  text {ttf "timrom.ttf" "Peru"       1, 0 texture {Text_Texture} translate <11,16,0>+<3.4,-1,0>}                                              
  text {ttf "timrom.ttf" "Nigeria"    1, 0 texture {Text_Texture} translate <22,16,0>+<3.5,-1,0>}                                              
  text {ttf "timrom.ttf" "Japan"      1, 0 texture {Text_Texture} translate < 0, 8,0>+<3.3,-1,0>}                                                    
  text {ttf "timrom.ttf" "China"      1, 0 texture {Text_Texture} translate <11, 8,0>+<3.2,-1,0>}                                               
#end


// Image map based flags of Spain and Portugal.
#if (Example=6) 
  camera {location <5,3.5,-10> look_at <5.8,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  background {rgb 0} 
  #include "flags.inc"
//  #declare Flags_WindStrength  = 10;
  #declare Flags_ImageType  = "jpeg";
  #declare Flags_ImageName  = "flags_spain.jpg";
  object {Flags("Image"    ,"height_field", 1) rotate -y*30}                                               
  #declare Flags_ImageName  = "flags_portugal.jpg";
  object {Flags("Image"    ,"height_field", 1) rotate -y*30 translate 7.5*x}                                               

  #local Text_Texture = texture {
    pigment { rgb <1,1,>}
    finish {phong 0.5 reflection 0.4}
  }
  text {ttf "timrom.ttf" "flags_spain.jpg"    0.1, 0 translate <1,-1,0> rotate -y*30 texture {Text_Texture} }                                                   
  text {ttf "timrom.ttf" "flags_portugal.jpg" 0.1, 0 translate <1,-1,0> rotate -y*30 texture {Text_Texture} translate 7.5*x}                                                   
#end


// Olympic Flag
#if (Example=7)  
  camera {location <4.5,2.5,-8> look_at <5,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  Flags("Olympic","height_field", 1)                                               
#end

// UK and Welsh flags for thumbnail animation.
#if (Example=8) 
  camera {location <5,2.5,-10> look_at <5.8,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  background {rgb 0} 
  #include "flags.inc"
  #declare Flags_WindStrength  = 8;
  object {Flags("Wales"    ,"height_field", 1) rotate -y*40 translate -0.3*x}                                               
  object {Flags("UnionJack","height_field", 1) rotate -y*40 translate 5.9*x-4*z}                                               
#end

#if (Example=9) // Bulgaria, Bolivia, Estonia, Gabon, Lithuania, Russia, Yemen, Ivory Coast and Chad
  camera {orthographic location <20, 17, -35> look_at <20, 17, 0>}
  background { rgb 0.2 }
  #include "flags.inc"
  object { Flags("Bulgaria",   "box", 0) translate <0, 26, 0> }
  object { Flags("Bolivia",    "box", 0) translate <15, 26, 0> }
  object { Flags("Estonia",    "box", 0) translate <30, 26, 0> }
  object { Flags("Gabon",      "box", 0) translate <0, 14, 0> }
  object { Flags("Lithuania",  "box", 0) translate <15, 14, 0> }
  object { Flags("Russia",     "box", 0) translate <30, 14, 0> }
  object { Flags("Yemen",      "box", 0) translate <0, 2, 0> }
  object { Flags("Ivory Coast","box", 0) translate <15, 2, 0> }
  object { Flags("Chad",       "box", 0) translate <30, 2, 0> }
  #local Text_Texture =
  texture
  {
     pigment { color rgb 1 }
     finish { ambient 1 }
  }
  text {ttf "timrom.ttf" "Bulgaria"    1, 0 texture {Text_Texture} translate < 0,26,0>+<3.0,-1.2,0>}
  text {ttf "timrom.ttf" "Bolivia"     1, 0 texture {Text_Texture} translate < 15,26,0>+<3.2,-1.2,0>}
  text {ttf "timrom.ttf" "Estonia"     1, 0 texture {Text_Texture} translate < 30,26,0>+<3.2,-1.2,0>}
  text {ttf "timrom.ttf" "Gabon"       1, 0 texture {Text_Texture} translate < 0,14,0>+<3.6,-1.2,0>}
  text {ttf "timrom.ttf" "Lithuania"   1, 0 texture {Text_Texture} translate < 15,14,0>+<2.8,-1.2,0>}
  text {ttf "timrom.ttf" "Russia"      1, 0 texture {Text_Texture} translate < 30,14,0>+<3.4,-1.2,0>}
  text {ttf "timrom.ttf" "Yemen"       1, 0 texture {Text_Texture} translate < 0,2,0>+<3.6,-1.2,0>}
  text {ttf "timrom.ttf" "Ivory Coast" 1, 0 texture {Text_Texture} translate < 15,2,0>+<2.6,-1.2,0>}
  text {ttf "timrom.ttf" "Chad"        1, 0 texture {Text_Texture} translate < 30,2,0>+<3.8,-1.2,0>}  
#end  

#if (Example=10) // Guinea, Mali, Romania, Sierra Leone, Indonesia, Monaco, Poland, Ukraine, Mauritius
  camera {orthographic location <20, 17, -35> look_at <20, 17, 0>}
  background { rgb 0.2 }
  #include "flags.inc"
  object { Flags("Guinea",      "box", 0) translate <0, 26, 0> }
  object { Flags("Mali",        "box", 0) translate <15, 26, 0> }
  object { Flags("Romania",     "box", 0) translate <30, 26, 0> }
  object { Flags("Sierra Leone","box", 0) translate <0, 14, 0> }
  object { Flags("Indonesia",   "box", 0) translate <15, 14, 0> }
  object { Flags("Monaco",      "box", 0) translate <30, 14, 0> }
  object { Flags("Poland",      "box", 0) translate <0, 2, 0> }
  object { Flags("Ukraine",     "box", 0) translate <15, 2, 0> }
  object { Flags("Mauritius",   "box", 0) translate <30, 2, 0> }
  #local Text_Texture =
  texture
  {
     pigment { color rgb 1 }
     finish { ambient 1 }
  }
  text {ttf "timrom.ttf" "Guinea"        1, 0 texture {Text_Texture} translate < 0,26,0>+<3.4,-1.2,0>}
  text {ttf "timrom.ttf" "Mali"          1, 0 texture {Text_Texture} translate < 15,26,0>+<3.8,-1.2,0>}
  text {ttf "timrom.ttf" "Romania"       1, 0 texture {Text_Texture} translate < 30,26,0>+<3.2,-1.2,0>}
  text {ttf "timrom.ttf" "Sierra Leone"  1, 0 texture {Text_Texture} translate < 0,14,0>+<2.4,-1.2,0>}
  text {ttf "timrom.ttf" "Indonesia"     1, 0 texture {Text_Texture} translate < 15,14,0>+<3,-1.2,0>}
  text {ttf "timrom.ttf" "Monaco"        1, 0 texture {Text_Texture} translate < 30,14,0>+<3.4,-1.2,0>}
  text {ttf "timrom.ttf" "Poland"        1, 0 texture {Text_Texture} translate < 0,2,0>+<3.4,-1.2,0>}
  text {ttf "timrom.ttf" "Ukraine"       1, 0 texture {Text_Texture} translate < 15,2,0>+<3.2,-1.2,0>}
  text {ttf "timrom.ttf" "Mauritius"     1, 0 texture {Text_Texture} translate < 30,2,0>+<2.8,-1.2,0>}  
#end  

#if (Example=11) // Botswana, Costa Rica, Latvia, Thailand, Afghanistan, Albania, Algeria, Andorra, Angola
  camera {orthographic location <20, 17, -35> look_at <20, 17, 0>}
  background { rgb 0.2 }
  #include "flags.inc"
  object { Flags("Botswana",      "box", 0) translate <0, 26, 0> }
  object { Flags("Costa Rica",    "box", 0) translate <15, 26, 0> }
  object { Flags("Latvia",        "box", 0) translate <30, 26, 0> }
  object { Flags("Thailand",      "box", 0) translate <0, 14, 0> }
  object { Flags("Afghanistan",   "box", 0) translate <15, 14, 0> }
  object { Flags("Albania",       "box", 0) translate <30, 14, 0> }
  object { Flags("Algeria",       "box", 0) translate <0, 2, 0> }
  object { Flags("Andorra",       "box", 0) translate <15, 2, 0> }
  object { Flags("Angola",        "box", 0) translate <30, 2, 0> }
  #local Text_Texture =
  texture
  {
     pigment { color rgb 1 }
     finish { ambient 1 }
  }
  text {ttf "timrom.ttf" "Botswana"          1, 0 texture {Text_Texture} translate < 0,26,0>+<3.1,-1.2,0>}
  text {ttf "timrom.ttf" "Costa Rica"        1, 0 texture {Text_Texture} translate < 15,26,0>+<2.7,-1.2,0>}
  text {ttf "timrom.ttf" "Latvia"            1, 0 texture {Text_Texture} translate < 30,26,0>+<3.5,-1.2,0>}
  text {ttf "timrom.ttf" "Thailand"          1, 0 texture {Text_Texture} translate < 0,14,0>+<3.1,-1.2,0>}
  text {ttf "timrom.ttf" "Afghanistan (raw)" 1, 0 texture {Text_Texture} translate < 15,14,0>+<1.8,-1.2,0>}
  text {ttf "timrom.ttf" "Albania (raw)"     1, 0 texture {Text_Texture} translate < 30,14,0>+<2.6,-1.2,0>}
  text {ttf "timrom.ttf" "Algeria (raw)"     1, 0 texture {Text_Texture} translate < 0,2,0>+<2.6,-1.2,0>}
  text {ttf "timrom.ttf" "Andorra (raw)"     1, 0 texture {Text_Texture} translate < 15,2,0>+<2.6,-1.2,0>}
  text {ttf "timrom.ttf" "Angola (raw)"      1, 0 texture {Text_Texture} translate < 30,2,0>+<2.8,-1.2,0>}
  #warning str(Flags_Brightness, 0, 3)
#end  



#if (Example=99) 
//  camera {location <4.5,2.5,-9> look_at <5,2.5,0>}
  camera {location <-5,3.5,0> look_at <0,3.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  
  #include "flags.inc"   
  Flags("China","height_field")
#end                                               


                           
