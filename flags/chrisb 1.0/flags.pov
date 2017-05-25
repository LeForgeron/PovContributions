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
//                       "Hungary", "Armenia", "Peru", "Nigeria", "Japan", "China". 
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
//   Example = 5 Armenia, Peru, Nigeria, Japan, China.
//   Example = 6 Image mapped flags of Spain and Portugal.  
//   Example = 7 Olympic flag.
//   Example = 8 UK and Welsh flags for thumbnail animation.
//                              
// Examples using the "height_field" flag type can be animated using command-line options
//   +kfi0 +kff12 +kc  for example.
// Alternatively you can use the POV-Ray animation feature to cycle through all of the
// above examples using command-line options +kfi0 +kff6 and by using the 'frame_number'
// identifier as follows:
//             
// #declare Example = frame_number;              
//

#declare Example = frame_number;   


// British Union Flag/Union Jack
#if (Example=0)  
  camera {location <4.5,2.5,-8> look_at <5,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  Flags("UnionFlag","height_field")                                               
#end
 

// Welsh Flag
#if (Example=1) 
  camera {location <4.5,2.5,-8> look_at <4.75,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  Flags("Wales","mesh2")                                               
#end


// British Flags
#if (Example=2) 
  camera {orthographic location <16,8.5,-25> look_at <16,8.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  #include "flags.inc" 
  object {Flags("StGeorgesCross" ,"box") translate 14*y     }                                               
  object {Flags("StAndrewsCross" ,"box") translate <11,14,0>}                                               
  object {Flags("Wales"          ,"box") translate <22,14,0>}                                               
  object {Flags("UnionFlag1606"  ,"box") translate 7*y      }                                               
  object {Flags("StPatricksCross","box") translate <11,7,0> }                                               
  object {Flags("UnionFlag"      ,"box") translate <11,0,0> } 

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
  object {Flags("USA"        ,"box") translate 7*y     }                                               
  object {Flags("Canada"     ,"box") translate <12,7,0>}                                               
  object {Flags("Australia"  ,"box") translate 0*y     }                                               
  object {Flags("NewZealand" ,"box") translate <12,0,0>}                                               

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
  object {Flags("Ireland"    ,"box") translate < 0,16,0>}                                               
  object {Flags("France"     ,"box") translate <11,16,0>}                                               
  object {Flags("Belgium"    ,"box") translate <22,16,0>}                                               
  object {Flags("Italy"      ,"box") translate < 0, 8,0>}                                               
  object {Flags("Germany"    ,"box") translate <11, 8,0>}                                               
  object {Flags("Austria"    ,"box") translate <22, 8,0>} 
  object {Flags("Luxembourg" ,"box") translate < 0, 0,0>} 
  object {Flags("Netherlands","box") translate <11, 0,0>} 
  object {Flags("Hungary"    ,"box") translate <22, 0,0>} 
  

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


// Armenia, Peru, Nigeria.
#if (Example=5) 
  camera {orthographic location <16,10.5,-28> look_at <16,10.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  background {rgb 0.1} 
  #include "flags.inc" 
  object {Flags("Armenia"    ,"box") translate < 0,16,0>}                                               
  object {Flags("Peru"       ,"box") translate <11,16,0>}                                               
  object {Flags("Nigeria"    ,"box") translate <22,16,0>}                                               
  object {Flags("Japan"      ,"box") translate < 0, 8,0>}                                               
  object {Flags("China"      ,"box") translate <11, 8,0>}                                               
//object {Flags("Austria"    ,"box") translate <22, 8,0>} 
//object {Flags("Luxembourg" ,"box") translate < 0, 0,0>} 
//object {Flags("Netherlands","box") translate <11, 0,0>} 
//object {Flags("Hungary"    ,"box") translate <22, 0,0>} 
  
  #local Text_Texture = texture {
    pigment { rgb <1,1,>}
    finish {phong 0.5 reflection 0.4}
  }
  text {ttf "timrom.ttf" "Armenia"    1, 0 texture {Text_Texture} translate < 0,16,0>+<3.0,-1,0>}                                                   
  text {ttf "timrom.ttf" "Peru"       1, 0 texture {Text_Texture} translate <11,16,0>+<3.4,-1,0>}                                              
  text {ttf "timrom.ttf" "Nigeria"    1, 0 texture {Text_Texture} translate <22,16,0>+<3.5,-1,0>}                                              
  text {ttf "timrom.ttf" "Japan"      1, 0 texture {Text_Texture} translate < 0, 8,0>+<3.3,-1,0>}                                                    
  text {ttf "timrom.ttf" "China"      1, 0 texture {Text_Texture} translate <11, 8,0>+<3.2,-1,0>}                                               
//text {ttf "timrom.ttf" "Austria"     1, 0 texture {Text_Texture} translate <22, 8,0>+<3.0,-1,0>}                                               
//text {ttf "timrom.ttf" "Luxembourg"  1, 0 texture {Text_Texture} translate < 0, 0,0>+<2.5,-1,0>}                                               
//text {ttf "timrom.ttf" "Netherlands" 1, 0 texture {Text_Texture} translate <11, 0,0>+<2.0,-1,0>}                                               
//text {ttf "timrom.ttf" "Hungary"     1, 0 texture {Text_Texture} translate <22, 0,0>+<3.2,-1,0>}                                               
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
  object {Flags("Image"    ,"height_field") rotate -y*30}                                               
  #declare Flags_ImageName  = "flags_portugal.jpg";
  object {Flags("Image"    ,"height_field") rotate -y*30 translate 7.5*x}                                               

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
  Flags("Olympic","height_field")                                               
#end

// UK and Welsh flags for thumbnail animation.
#if (Example=8) 
  camera {location <5,2.5,-10> look_at <5.8,2.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  background {rgb 0} 
  #include "flags.inc"
  #declare Flags_WindStrength  = 8;
  object {Flags("Wales"    ,"height_field") rotate -y*40 translate -0.3*x}                                               
  object {Flags("UnionJack","height_field") rotate -y*40 translate 5.9*x-4*z}                                               
#end



#if (Example=99) 
//  camera {location <4.5,2.5,-9> look_at <5,2.5,0>}
  camera {location <-5,3.5,0> look_at <0,3.5,0>}
  light_source {<-10,10,-35>, rgb 1} 
  
  #include "flags.inc"   
  Flags("China","height_field")
#end                                               


                           
