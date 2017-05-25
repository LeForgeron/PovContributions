// flags.inc
// ---------

// This include file contains a number of macros to define a series of flag 
// textures and a choice of flag objects using different types of POV-Ray
// object. 
//
// This file is licensed under the terms of the CC-LGPL. 
// This license permits you to use, modify and redistribute the content.
// 
// Typical render time is about 5 seconds for a single flag (at 640x480 AA 0.3).
// The default object is about 5 POV-Ray units high and about 10 units wide.
// Its bottom left hand corner is positioned at the origin and the flag
// stretches out in the +X and +Y directions. 
//

#include "math.inc"                                                

// This macro calls a macro to define the appropriate texture, then it calls a second macro to 
// generate an object using that texture. 
//
// This macro has two parameters:
//
//    Flags_Name       - Is a string naming the type of flag required, eg. "Olympic", "UnionJack",
//                       "UnionFlag1606", "StGeorgesCross", "StAndrewsCross", "StPatricksCross",
//                       "Wales", "Canada", "USA", "Australia", "New Zealand", "Ireland", "France", 
//                       "Belgium", "Italy", "Germany", "Austria", "Luxembourg", "Netherlands", 
//                       "Hungary", "Armenia", "Peru", "Nigeria", "Japan", "China", "Bulgaria",
//			 "Bolivia", "Estonia", "Gabon", "Lithuania", "Russia". "Yemen", "Ivory Coast",
//                       "Chad", "Guinea", "Mali", "Romania", "Sierra Leone", "Indonesia", "Monaco",
//			 "Poland", "Ukraine", "Mauritius", "Botswana", "Costa Rica", "Latvia",
//                       "Thailand", "Afghanistan", "Albania", "Algeria", "Andorra", "Angola"
//
//    Flags_ObjectType - Is a string naming the type of object to be used to build the flag:
//                       "mesh2", "height_field", "box". 
//
#macro Flags(Flags_Name,Flags_ObjectType,light) 

  #ifndef(Flags_Brightness) #declare Flags_Brightness = 1; #end

  // Create a default Normal setting
  #ifndef (Flags_Normal)
    //#if(strcmp(Flags_ObjectType,"height_field")=0 & strcmp(Flags_Name,"Image")!=0)
    //  #declare Flags_Normal = normal{ // cloth weave
    //    average
    //    normal_map{
    //      [1.0 gradient x triangle_wave bump_size 1.2 scale .0008]
    //      [1.0 gradient z triangle_wave bump_size 1.2 scale .0016]
    //    }
    //  }
    //#else
      #declare Flags_Normal = normal{wrinkles 0.035 scale 3}
    //#end
  #end
  // Create a default Finish setting
  #ifndef (Flags_Finish)
    #if(strcmp(Flags_ObjectType,"height_field")=0 )
      #declare Flags_Finish = finish{
        ambient 0.3
        diffuse 0.3 
      }
    #else
      #declare Flags_Finish = finish{ ambient 0.3}
    #end
    #if (light = 0)
      #declare Flags_Finish = finish { ambient 1 diffuse 0 }
    #end
  #end

  // First define a texture containing the pattern required for the flag.
  #switch (0)
  // If the "Image" option has been specified for the Flags_Name parameter then 
  // we need to make sure that the Flags_ImageName and Flags_BitmapType variables
  // have been set.
  #case (strcmp(Flags_Name,"Image")) 
    #declare Flags_Width  = 9;
    #declare Flags_Height = 5;
    #ifndef(Flags_ImageName)  #declare Flags_ImageName  = "flags.jpg"; #end
    #ifndef(Flags_BitmapType) #declare Flags_BitmapType = "jpeg";      #end
    #declare Flags_Texture = texture {
      pigment {
        image_map{
          #switch(0)
          #case (strcmp(Flags_BitmapType,"gif" )) gif  #break
          #case (strcmp(Flags_BitmapType,"tga" )) tga  #break
          #case (strcmp(Flags_BitmapType,"iff" )) iff  #break
          #case (strcmp(Flags_BitmapType,"ppm" )) ppm  #break
          #case (strcmp(Flags_BitmapType,"pgm" )) pgm  #break
          #case (strcmp(Flags_BitmapType,"png" )) png  #break
          #case (strcmp(Flags_BitmapType,"jpeg")) jpeg #break
          #case (strcmp(Flags_BitmapType,"tiff")) tiff #break
          #case (strcmp(Flags_BitmapType,"sys" )) sys  #break
          #end
          Flags_ImageName 
          interpolate 2 
          // The once keyword keeps extraneous pixels 
          // from showing up at the edges of the flag.
          once 
        }
      }
      finish {Flags_Finish} normal {Flags_Normal}
    }
  #break
  #case (strcmp(Flags_Name,"Olympic"))
    #declare Flags_Width  = 9;
    #declare Flags_Height = 5;
    Flags_Olympic()
  #break
  #case (strcmp(Flags_Name,"UnionFlag"))
  #case (strcmp(Flags_Name,"UnionFlag1606"))
  #case (strcmp(Flags_Name,"UnionJack"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 5;
    Flags_UKUnionFlag()
  #break
  #case (strcmp(Flags_Name,"StGeorgesCross"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 5;
    Flags_StGeorgesCross()
  #break
  #case (strcmp(Flags_Name,"StAndrewsCross"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 5;
    Flags_StAndrewsCross()
  #break
  #case (strcmp(Flags_Name,"StPatricksCross"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 5;
    Flags_StPatricksCross()
  #break
  #case (strcmp(Flags_Name,"Wales"))
    #declare Flags_Width  = 9;
    #declare Flags_Height = 6;
    Flags_WelshFlag()
  #break
  #case (strcmp(Flags_Name,"Canada"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 5;
    Flags_CanadianFlag()
  #break
  #case (strcmp(Flags_Name,"USA"))
    #declare Flags_Width  = 9.5;
    #declare Flags_Height = 5;
    Flags_USFlag()
  #break
  #case (strcmp(Flags_Name,"Australia"))
    #declare Flags_Width  = 10.08;   
    #declare Flags_Height =  5.04;
    Flags_AustralianFlag()
  #break
  #case (strcmp(Flags_Name,"NewZealand"))
    #declare Flags_Width  = 9.5;
    #declare Flags_Height = 5;
    Flags_NewZealandFlag()
  #break
  #case (strcmp(Flags_Name,"Ireland"))                            
    #declare Flags_Width  = 9;                                   
    #declare Flags_Height = 6;                                   
    Flags_ThreeColumnFlag(<0,100, 50>/255,1,<255,80, 25>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"France"))                            
    #declare Flags_Width  = 9;                                   
    #declare Flags_Height = 6;                                   
    Flags_ThreeColumnFlag(<0, 16,140>/255,1,<255, 10, 15>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Belgium"))                            
    #declare Flags_Width  = 9;                                   
    #declare Flags_Height = 7.8;                                   
    Flags_ThreeColumnFlag(0,<255,255,0>,<255, 0, 0>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Italy"))                            
    #declare Flags_Width  = 9;                                   
    #declare Flags_Height = 6;                                   
    Flags_ThreeColumnFlag(<0,90, 15>/255,1,<200,10, 10>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Nigeria"))                            
    #declare Flags_Width  = 10;                                   
    #declare Flags_Height = 5;                                   
    Flags_ThreeColumnFlag(<5,75, 20>/255,1,<5,75, 20>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Peru"))                            
    #declare Flags_Width  = 9;                                   
    #declare Flags_Height = 6;                                   
    Flags_ThreeColumnFlag(<160,5, 5>/255,1,<160,5, 5>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Germany"))                           
    #declare Flags_Width  = 10;                                  
    #declare Flags_Height = 6;                                   
    Flags_ThreeStripeFlag(0,<0.9,0,0>,<1,0.9,0>)                           
  #break                                                         
  #case (strcmp(Flags_Name,"Austria"))                            
    #declare Flags_Width  = 9;                                   
    #declare Flags_Height = 6;                                   
    Flags_ThreeStripeFlag(<235,5, 5>/255,1,<235,5, 5>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Luxembourg"))                            
    #declare Flags_Width  = 10;                                   
    #declare Flags_Height = 6;                                   
    Flags_ThreeStripeFlag(<235,5, 5>/255,1,<20,110,200>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Netherlands"))                            
    #declare Flags_Width  = 9;                                   
    #declare Flags_Height = 6;                                   
    Flags_ThreeStripeFlag(0.5*<235,5, 5>/255,1,0.5*<5,50,180>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Armenia"))                            
    #declare Flags_Width  = 10;                                   
    #declare Flags_Height = 5;                                   
    Flags_ThreeStripeFlag(<255,0, 0>/255,<0,0,100>,<185,85, 0>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Hungary"))                            
    #declare Flags_Width  = 10;                                   
    #declare Flags_Height = 5;                                   
    Flags_ThreeStripeFlag(<180,0, 0>/255,1,<5,60, 20>/255)                    
  #break                                                         
  #case (strcmp(Flags_Name,"Japan"))
    #declare Flags_Width  = 9;
    #declare Flags_Height = 6;
    Flags_JapaneseFlag()
  #break
  #case (strcmp(Flags_Name,"China"))
    #declare Flags_Width  = 9;
    #declare Flags_Height = 6;
    Flags_ChineseRepublicFlag()
  #break
  #case (strcmp(Flags_Name,"Bulgaria"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6;
    Flags_ThreeStripeFlag(1, <0, 150, 110>/255, <214, 38, 18>/255)
  #break
  #case (strcmp(Flags_Name,"Bolivia"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6.8125;
    Flags_ThreeStripeFlag(<206, 17, 38>/255, <249, 214, 22>/255, <0, 122, 61>/255)
  #break
  #case (strcmp(Flags_Name,"Estonia"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6.3625;
    Flags_ThreeStripeFlag(<58, 117, 196>/255, 0, 1)
  #break
  #case (strcmp(Flags_Name,"Gabon"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 7.5;
    Flags_ThreeStripeFlag(<0, 158, 96>/255, <252, 209, 22>/255, <58, 117, 196>/255)
  #break
  #case (strcmp(Flags_Name,"Lithuania"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6;
    Flags_ThreeStripeFlag(<253, 185, 19>/255, <0, 106, 68>/255, <193, 39, 45>/255)
  #break
  #case (strcmp(Flags_Name,"Russia"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeStripeFlag(1, <0, 0, 1>, <1, 0, 0>)
  #break
  #case (strcmp(Flags_Name,"Yemen"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeStripeFlag(<206, 17, 38>/255, 1, 0 )
  #break
  #case (strcmp(Flags_Name,"Ivory Coast"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeColumnFlag(<247, 127, 0>/255, 1, <0, 158, 96>/255 )
  #break
  #case (strcmp(Flags_Name,"Chad"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeColumnFlag(<0, 37, 105>/255, <255, 206, 0>/255, <210, 16, 52>/255)
  #break
  #case (strcmp(Flags_Name,"Guinea"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeColumnFlag(<206, 17, 38>/255, <252, 209, 22>/255, <0, 148, 96>/255 )
  #break
  #case (strcmp(Flags_Name,"Mali"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeColumnFlag(<20, 181, 58>/255, <252, 209, 22>/255, <206, 17, 38>/255 )
  #break
  #case (strcmp(Flags_Name,"Romania"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeColumnFlag(<0, 43, 127>/255, <252, 209, 22>/255, <206, 17, 38>/255)
  #break
  #case (strcmp(Flags_Name,"Sierra Leone"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_ThreeStripeFlag(<30, 181, 58>/255, 1, <0, 114, 198>/255)
  #break
  #case (strcmp(Flags_Name,"Indonesia"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_TwoStripeFlag(<206, 17, 38>/255, 1)
  #break
  #case (strcmp(Flags_Name,"Monaco"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 8;
    Flags_TwoStripeFlag(<206, 17, 38>/255, 1)
  #break
  #case (strcmp(Flags_Name,"Poland"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6.25;
    Flags_TwoStripeFlag(1, <220, 20, 60>/255)
  #break
  #case (strcmp(Flags_Name,"Ukraine"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_TwoStripeFlag(<58, 117, 196>/255, <249, 221, 22>/255)
  #break
  #case (strcmp(Flags_Name,"Mauritius"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_FourStripeFlag(<220, 24, 30>/255, <1, 42, 135>/255, <252, 235, 15>/255, <22, 146, 83>/255)
  #break
  #case (strcmp(Flags_Name,"Botswana"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_SymmetricalThreeColorStripeFlag(<117, 170, 219>/255, 1, 0, 0.75, 0.8325 )
  #break
  #case (strcmp(Flags_Name,"Costa Rica"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6;
    Flags_SymmetricalThreeColorStripeFlag(<0, 43, 127>/255, 1, <206, 17, 38>/255, 1/3, 2/3 )
  #break
  #case (strcmp(Flags_Name,"Latvia"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 5;
    Flags_SymmetricalTwoColorStripeFlag(<134, 22, 35>/255, 1, 0.8)
  #break
  #case (strcmp(Flags_Name,"Thailand"))
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_SymmetricalThreeColorStripeFlag(<222, 16, 24>/255, 1, <0, 36, 125>/255, 1/3, 2/3 )
  #break
  #case (strcmp(Flags_Name,"Afghanistan")) // raw - no coat of arms yet!
    #include "flags_afghanistan_coat_of_arms.inc"
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6.636;
    Flags_AfghanFlag()
  #break
  #case (strcmp(Flags_Name,"Albania")) // raw - no coat of arms yet!
    #declare Flags_Width  = 10;
    #declare Flags_Height = 10*(5/7);
    Flags_AlbanianFlag()
  #break
  #case (strcmp(Flags_Name,"Algeria")) // raw - no crescent and star yet!
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_AlgerianFlag()
  #break
  #case (strcmp(Flags_Name,"Andorra")) // raw - no coat of arms yet!
    #declare Flags_Width  = 10;
    #declare Flags_Height = 7;
    Flags_AndorranFlag()
  #break
  #case (strcmp(Flags_Name,"Angola")) // raw - no coat of arms yet!
    #declare Flags_Width  = 10;
    #declare Flags_Height = 6+2/3;
    Flags_AngolanFlag()
  #break
  

  


  #else                                                          
    Flags_Olympic() 
  #end 
  
  // Next create and return an object of the required type with the texture mapped onto it.
  #switch (0)
  #case (strcmp(Flags_ObjectType,"mesh2"))
    Flags_CreateMesh2FlagObject() 
  #break
  #case (strcmp(Flags_ObjectType,"height_field"))
    Flags_CreateHeightFieldFlagObject() 
  #break
  #else
    Flags_CreateBoxFlagObject() 
  #end
#end 


// This macro draws the St Georges Cross, the national flag of England.
// We're working in units of 60x30, but we scale the texture to a unit square before returning. 
#macro Flags_StGeorgesCross()
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // White
    texture { pigment {object {
      union {                          
        box {<27,0,-1> <33,30,1>}
        box {<0,12,-1> <60,18,1>}
      }
      color rgbt 1
      color rgb <204/255,0,0>*Flags_Brightness // Red Pantone 186
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/60,1/30,1>}
#end  


// This macro draws the St Andrews Cross, the national flag of Scotland.
// We're working in units of 60x30, but we scale the texture to a unit square before returning. 
#macro Flags_StAndrewsCross()
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb <0,25/255,102/255>*Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // Blue 
    texture { pigment {object {
      union {                          
        box {<-3,0,-1> <3,30*sqrt(5),1> rotate -z*atan2d(2,1)}
        box {<-3,0,-1> <3,30*sqrt(5),1> rotate  z*atan2d(2,1) translate 60*x}
      }
      color rgbt 1
      color rgb Flags_Brightness // White Diagonal
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/60,1/30,1>}
#end


// This macro draws the St Patricks Cross, the national flag of Ireland.
// We're working in units of 60x30, but we scale the texture to a unit square before returning. 
#macro Flags_StPatricksCross()
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // White
    texture { pigment {object {
      union {                          
        box {<-2,0,-1> <2,30*sqrt(5),1> rotate -z* atan2d(2,1)}
        box {<-2,0,-1> <2,30*sqrt(5),1> rotate  z* atan2d(2,1)      translate 60*x}
      }
      color rgbt 1
      color rgb <204/255,0,0>*Flags_Brightness // Red Diagonal Pantone 186
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/60,1/30,1>}
#end  

// This macro draws the British Union Flag, known as the Union Jack when flown from 
// the bows of a warship and often in common parlance.
// The Union Flag went through two manifestations with the first being the merging of the St Georges
// cross and the St Andrews cross in 1606.
// We're working in units of 60x30, but we scale the texture to a unit square before returning. 
// Based on dimensions from http://www.jdawiseman.com/papers/union-jack/union-jack.html
#macro Flags_UKUnionFlag()
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb <0,0,102/255>*Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // Blue Pantone 280
    texture { pigment {object {
      intersection {
        union {                          
          box {<-3,0,-1> <3,30*sqrt(5),1> rotate -z*atan2d(2,1)}
          box {<-3,0,-1> <3,30*sqrt(5),1> rotate  z*atan2d(2,1) translate 60*x}
        }
        box {<0,0,-1><60,30,1>}
      }
      color rgbt 1
      color rgb Flags_Brightness // White Diagonal
    }} finish {Flags_Finish} normal {Flags_Normal}}
    
  #if (strcmp(Flags_Name,"UnionFlag1606")!=0)
    #declare Flags_Texture = 
      texture {Flags_Texture}
      texture { pigment {object {
        intersection {
          union {                          
            box {<0,0,-1> <2,15*sqrt(5),1> rotate -z* atan2d(2,1)}
            box {<0,0,-1> <2,15*sqrt(5),1> rotate  z* atan2d(2,1)      translate 60*x}
            box {<0,0,-1> <2,15*sqrt(5),1> rotate -z*(atan2d(2,1)+180) translate <60,30,0>}
            box {<0,0,-1> <2,15*sqrt(5),1> rotate  z*(atan2d(2,1)+180) translate 30*y}
          }
          box {<0,0,-1><60,30,1>}
        }
        color rgbt 1
        color rgb <204/255,0,0>*Flags_Brightness // Red Diagonal Pantone 186
      }} finish {Flags_Finish} normal {Flags_Normal}}
  #end 
    
  #declare Flags_Texture = 
    texture {Flags_Texture}
    texture { pigment {object {
      union {                          
        box {<25,0,-1> <35,30,1>}
        box {<0,10,-1> <60,20,1>}
      }
      color rgbt 1
      color rgb Flags_Brightness // White
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      union {                          
        box {<27,0,-1> <33,30,1>}
        box {<0,12,-1> <60,18,1>}
      }
      color rgbt 1
      color rgb <204/255,0,0>*Flags_Brightness // Red Pantone 186
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/60,1/30,1>}
#end


// This macro draws the Welsh Flag, the national flag of Wales.
// We're working in units of 9x6 which we use directly for the background.
// The dragon is in a separate file and is at 1200x800. It comes in two parts (Black and Red).
// We scale the texture to a unit square before returning. 
#macro Flags_WelshFlag()
  #include "flags_welshdragon.inc"
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // White Background
    texture { pigment {object {
      box {<0,0,-1> <9,3,1>}
      color rgbt 1
      color rgb <0,0.5,0>*Flags_Brightness // Green Background
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      object {Flag_BlackDragon rotate -x*90 scale <9/1200,6/800,2> translate z}
      color rgbt 1
      color rgb 0 // Black Dragon
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      object {Flag_RedDragon rotate -x*90 scale <9/1200,6/800,2> translate z}
      color rgbt 1
      color rgb <204/255,0,0>*Flags_Brightness // Red Dragon
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/9,1/6,1>}
#end


// This macro draws the Canadian Flag.
// We're working in units of 10x5 which we use directly for the rectangular blocks of colour.
// The maple leaf is in a separate file and is at 1200x600.
// We scale the texture to a unit square before returning. 
#macro Flags_CanadianFlag()
  #include "flags_canadaleaf.inc"
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // White Background
    texture { pigment {object {
      union {
        box {<0,0,-1> <2.5,5,1>}
        box {<7.5,0,-1> <10,5,1>}
        object {Flag_MapleLeaf rotate -x*90 scale <10/1200,5/600,2> translate z}
      }
      color rgbt 1
      color rgb <1,0,0>*Flags_Brightness // Red
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/10,1/5,1>}
#end


// This macro draws the United States Flag.
// We're working in units of 1.9 x 1 based on http://www.jdawiseman.com/papers/union-jack/us-flag.gif
// We scale the texture to a unit square before returning. 
#macro Flags_USFlag()
  #declare Flags_Stripes = union {
    #local Flags_I = 0;
    #while (Flags_I<7)
      box {<0,0,-1> <1.9,1/13,1> translate y*2*Flags_I/13}
      #local Flags_I = Flags_I+1;
    #end  
  }
  #declare Flags_Star = prism {
    linear_spline linear_sweep 
    -1,1,11
    #local Flags_I = 0;
    #while (Flags_I<5)
      #local Flags_Vector = vrotate(z*0.0616/2,Flags_I*y*360/5);
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_Vector = vrotate(z*4.94*0.0616/(2*12.94),y*(360/10+Flags_I*360/5));
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_I = Flags_I+1;
    #end 
    <0,1>*0.0616/2
    rotate -x*90  
  }
  #declare Flags_Stars = union {
    #local Flags_I = 0;
    #while (Flags_I<6)
      #local Flags_J = 0;
      #while (Flags_J<5)
        object {Flags_Star translate <0.063+2*0.063*Flags_I,6/13+0.054+0.054*2*Flags_J,0>} 
        #if (Flags_I<5&Flags_J<4)
          object {Flags_Star translate <2*0.063+2*0.063*Flags_I,6/13+2*0.054+0.054*2*Flags_J,0>} 
        #end
        #local Flags_J = Flags_J+1;
      #end  
      #local Flags_I = Flags_I+1;
    #end  
  }
  
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // White Background
    texture { pigment {object {
      Flags_Stripes
      color rgbt 1
      color rgb <204/255,0,0>*Flags_Brightness // Red Stripes
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      box {<0,6/13,-1> <0.76,1,1>}
      color rgbt 1
      color rgb <0,0,102/255>*Flags_Brightness // Blue Corner
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      Flags_Stars
      color rgbt 1
      color rgb Flags_Brightness // White Stars
    }} finish {Flags_Finish} normal {Flags_Normal}}

  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/1.9,1,1>}

#end
 
// This macro draws the Australian Flag.
// We're working in units of 30240 x 15120 based on http://flagspot.net/flags/au%27.html#det.
// We scale the texture to a unit square before returning. 
#macro Flags_AustralianFlag()
  Flags_UKUnionFlag()
  #local Flags_UnionJack = texture {Flags_Texture scale <(6300+504)*2+1512,(2520+504)*2+1512,1> translate y*((2520+504)*2+1512)}
  
  #declare Flags_FivePointedStar = prism {
    linear_spline linear_sweep 
    -1,1,11
    #local Flags_I = 0;
    #while (Flags_I<5)
      #local Flags_Vector = vrotate(z,Flags_I*y*360/5);
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_Vector = vrotate(z*4/9,y*(360/10+Flags_I*360/5));
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_I = Flags_I+1;
    #end 
    <0,1>
    rotate -x*90  
  }
  #declare Flags_SevenPointedStar = prism {
    linear_spline linear_sweep 
    -1,1,15
    #local Flags_I = 0;
    #while (Flags_I<7)
      #local Flags_Vector = vrotate(z,Flags_I*y*360/7);
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_Vector = vrotate(z*4/9,y*(360/14+Flags_I*360/7));
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_I = Flags_I+1;
    #end 
    <0,1>
    rotate -x*90  
  }
  
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb <3,0,102/255>*Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // Blue Background 
    texture {Flags_UnionJack}
    texture { pigment {object { 
      union {
        object {Flags_SevenPointedStar scale <2268,2268,1> translate <7560        ,3780      ,0>} // CommonWealth Star
        object {Flags_SevenPointedStar scale <1080,1080,1> translate <7560*3      ,2520      ,0>} // Alpha Star
        object {Flags_SevenPointedStar scale <1080,1080,1> translate <30240/2+3780,8505      ,0>} // Beta Star
        object {Flags_SevenPointedStar scale <1080,1080,1> translate <7560*3      ,15120-2520,0>} // Gamma Star
        object {Flags_SevenPointedStar scale <1080,1080,1> translate <30240-4200  ,9513      ,0>} // Delta Star
        object {Flags_FivePointedStar  scale < 630, 630,1> translate <30240-6048  ,6930      ,0>} // Epsilon Star
      }
      color rgbt 1
      color rgb Flags_Brightness // White 
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/30240,1/15120,1>}

#end
                                              

// This macro draws the New Zealand Flag.
// We're working in units of 240 x 120.
// We scale the texture to a unit square before returning. 
#macro Flags_NewZealandFlag()
  Flags_UKUnionFlag()
  #local Flags_UnionJack = texture {Flags_Texture scale <120,60,1> translate y*60}
  
  #declare Flags_FivePointedStar = prism {
    linear_spline linear_sweep 
    -1,1,11
    #local Flags_I = 0;
    #while (Flags_I<5)
      #local Flags_Vector = vrotate(z,Flags_I*y*360/5);
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_Vector = vrotate(z*4/9,y*(360/10+Flags_I*360/5));
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_I = Flags_I+1;
    #end 
    <0,1>
    rotate -x*90  
  }
  
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb <3,0,102/255>*Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // Blue Background 
    texture {Flags_UnionJack}
    texture { pigment {object { 
      union {
        object {Flags_FivePointedStar scale <9.6,9.6,1> translate <150,66    ,0>} // Beta Star
        object {Flags_FivePointedStar scale <9.6,9.6,1> translate <180,120-24,0>} // Gamma Star
        object {Flags_FivePointedStar scale <10 ,10 ,1> translate <180,120-97,0>} // Alpha Star
        object {Flags_FivePointedStar scale <8.3,8.3,1> translate <206,120-48,0>} // Delta Star
      }
      color rgbt 1
      color rgb Flags_Brightness // White 
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      union {
        object {Flags_FivePointedStar scale <6.6,6.6,1> translate <150,66    ,0>} // Beta Star
        object {Flags_FivePointedStar scale <6.6,6.6,1> translate <180,120-24,0>} // Gamma Star
        object {Flags_FivePointedStar scale <7.0,7.0,1> translate <180,120-97,0>} // Alpha Star
        object {Flags_FivePointedStar scale <5.5,5.5,1> translate <206,120-48,0>} // Delta Star
      }
      color rgbt 1
      color rgb <204/255,0,0>*Flags_Brightness // Red 
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/240,1/120,1>}

#end  


// This macro draws the Japanese flag.
// We're working in units of 3x2, but we scale the texture to a unit square before returning. 
#macro Flags_JapaneseFlag()
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // White
    texture { pigment {object {
      cylinder {-z,z,3/5 translate <1.5,1,0>}
      color rgbt 1
      color rgb <110/255,0,0>*Flags_Brightness // Red Spot
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/3,1/2,1>}
#end  


// This macro draws the flag of the Republic of China.
// We're working in units of 9x6, but we scale the texture to a unit square before returning. 
#macro Flags_ChineseRepublicFlag()

  #declare Flags_TwelvePointedStar = prism {
    linear_spline linear_sweep 
    -1,1,25
    #local Flags_I = 0;
    #while (Flags_I<12)
      #local Flags_Vector = vrotate(z,Flags_I*y*360/12);
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_Vector = vrotate(z*0.53,y*(360/24+Flags_I*360/12));
      <Flags_Vector.x,Flags_Vector.z>,
      #local Flags_I = Flags_I+1;
    #end 
    <0,1>
    rotate -x*90  
  }

  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb <1,0,0>*Flags_Brightness} finish {Flags_Finish} normal {Flags_Normal}} // White
    texture { pigment {object {
      box {-z,<4.5,3,1> translate y*3}
      color rgbt 1
      color rgb <0,5,40>/255*Flags_Brightness // Red Spot
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      object {Flags_TwelvePointedStar scale 1.1 translate <2.25,4.5,0>}
      color rgbt 1
      color rgb Flags_Brightness // White Star
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      cylinder {-z,z,0.642 translate <2.25,4.5,0>}
      color rgbt 1
      color rgb <0,5,40>/255*Flags_Brightness // Blue Circle
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      cylinder {-z,z,0.565 translate <2.25,4.5,0>}
      color rgbt 1
      color rgb Flags_Brightness // White Spot
    }} finish {Flags_Finish} normal {Flags_Normal}}
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/9,1/6,1>}
#end  


// Create a simple color_map gradient texture
#macro Flags_ThreeColumnFlag(Flags_Color1,Flags_Color2,Flags_Color3)
  #declare Flags_Texture = texture {
    pigment {gradient x 
      color_map {
        [0    color rgb Flags_Color1*Flags_Brightness] 
        [1/3  color rgb Flags_Color1*Flags_Brightness] 
        [1/3  color rgb Flags_Color2*Flags_Brightness] 
        [2/3  color rgb Flags_Color2*Flags_Brightness] 
        [2/3  color rgb Flags_Color3*Flags_Brightness] 
        [1    color rgb Flags_Color3*Flags_Brightness] 
      }
    }
    finish {Flags_Finish} 
    normal {Flags_Normal}
  }
#end

// Create a simple color_map gradient texture
#macro Flags_TwoColumnFlag(Flags_Color1,Flags_Color2)
  #declare Flags_Texture = texture {
    pigment {gradient x 
      color_map {
        [0    color rgb Flags_Color1*Flags_Brightness] 
        [0.5  color rgb Flags_Color1*Flags_Brightness] 
        [0.5  color rgb Flags_Color2*Flags_Brightness] 
        [1  color rgb Flags_Color2*Flags_Brightness] 
      }
    }
    finish {Flags_Finish} 
    normal {Flags_Normal}
  }
#end


// Create a simple color_map gradient texture
#macro Flags_ThreeStripeFlag(Flags_Color1,Flags_Color2,Flags_Color3)
  #declare Flags_Texture = texture {
    pigment {gradient y 
      color_map {
        [0    color rgb Flags_Color3*Flags_Brightness] 
        [1/3  color rgb Flags_Color3*Flags_Brightness] 
        [1/3  color rgb Flags_Color2*Flags_Brightness] 
        [2/3  color rgb Flags_Color2*Flags_Brightness] 
        [2/3  color rgb Flags_Color1*Flags_Brightness] 
        [1    color rgb Flags_Color1*Flags_Brightness] 
      }
    }
    finish {Flags_Finish} 
    normal {Flags_Normal}
  }
#end

// Create a simple color_map gradient texture
#macro Flags_TwoStripeFlag(Flags_Color1,Flags_Color2)
  #declare Flags_Texture = texture {
    pigment {gradient y 
      color_map {
        [0    color rgb Flags_Color2*Flags_Brightness] 
        [0.5  color rgb Flags_Color2*Flags_Brightness] 
        [0.5  color rgb Flags_Color1*Flags_Brightness] 
        [1    color rgb Flags_Color1*Flags_Brightness] 
      }
    }
    finish {Flags_Finish} 
    normal {Flags_Normal}
  }
#end

// Create a simple color_map gradient texture in four colors (Mauritius)
#macro Flags_FourStripeFlag(Flags_Color1,Flags_Color2,Flags_Color3,Flags_Color4)
  #declare Flags_Texture = texture {
    pigment {gradient y 
      color_map {
        [0    color rgb Flags_Color4*Flags_Brightness] 
        [0.25  color rgb Flags_Color4*Flags_Brightness] 
        [0.25  color rgb Flags_Color3*Flags_Brightness] 
        [0.5   color rgb Flags_Color3*Flags_Brightness] 
        [0.5    color rgb Flags_Color2*Flags_Brightness] 
        [0.75  color rgb Flags_Color2*Flags_Brightness] 
        [0.75  color rgb Flags_Color1*Flags_Brightness] 
        [1   color rgb Flags_Color1*Flags_Brightness] 
      }
    }
    finish {Flags_Finish} 
    normal {Flags_Normal}
  }
#end

// Creates a color map of symmetrical stripes in three colors (Botswana, Costa Rica, Thailand)
#macro Flags_SymmetricalThreeColorStripeFlag(Flags_Color1, Flags_Color2, Flags_Color3, Border1, Border2)
  #declare Flags_Texture =
  texture
  {
    pigment
    {
       gradient y
       triangle_wave
       color_map
       {
         [0 color rgb Flags_Color1 * Flags_Brightness ]
         [Border1 color rgb Flags_Color1 * Flags_Brightness ]
         [Border1 color rgb Flags_Color2 * Flags_Brightness ]
         [Border2 color rgb Flags_Color2 * Flags_Brightness ]
         [Border2 color rgb Flags_Color3 * Flags_Brightness ]
         [1 color rgb Flags_Color3 * Flags_Brightness ]
       }
     }
     finish { Flags_Finish }
     normal { Flags_Normal }
   }
#end

// Creates a color map of symmetrical stripes in two colors (Latvia)
#macro Flags_SymmetricalTwoColorStripeFlag(Flags_Color1, Flags_Color2, Border)
  #declare Flags_Texture =
  texture
  {
    pigment
    {
       gradient y
       triangle_wave
       color_map
       {
         [0 color rgb Flags_Color1 * Flags_Brightness ]
         [Border color rgb Flags_Color1 * Flags_Brightness ]
         [Border color rgb Flags_Color2 * Flags_Brightness ]
         [1 color rgb Flags_Color2 * Flags_Brightness ]
       }
     }
     finish { Flags_Finish }
     normal { Flags_Normal }
   }
#end

// Creates a color map of symmetrical stripes in four colors (The Gambia)
#macro Flags_SymmetricalFourColorStripeFlag(Flags_Color1, Flags_Color2, Flags_Color3, Flags_Color4, Border1, Border2, Border3)
  #declare Flags_Texture =
  texture
  {
    pigment
    {
       gradient y
       triangle_wave
       color_map
       {
         [0 color rgb Flags_Color1 * Flags_Brightness ]
         [Border1 color rgb Flags_Color1 * Flags_Brightness ]
         [Border1 color rgb Flags_Color2 * Flags_Brightness ]
         [Border2 color rgb Flags_Color2 * Flags_Brightness ]
         [Border2 color rgb Flags_Color3 * Flags_Brightness ]
         [Border3 color rgb Flags_Color3 * Flags_Brightness ]
         [Border3 color rgb Flags_Color4 * Flags_Brightness ]
         [1 color rgb Flags_Color4 * Flags_Brightness ]         
       }
     }
     finish { Flags_Finish }
     normal { Flags_Normal }
   }
#end

// Creates a single-colored texture (Albania, Libya, People's Republic of China)
#macro Flags_Unicolor(Flags_Color)
  #declare Flags_Texture =
  texture
  {
    pigment { color rgb Flags_Color }
    finish { Flags_Finish }
    normal { Flags_Normal }
  }
#end

// Creates a three-column gradient texture with columns of non-equal width (Andorra)
#macro Flags_ThreeIrregularColumnsFlag (Flags_Color1, Flags_Color2, Flags_Color3, Border1, Border2)
  #declare Flags_Texture =
  texture
  {
    pigment
    {
      gradient x
      color_map
      {
        [0 color rgb Flags_Color1 ]
        [Border1 color rgb Flags_Color1]
        [Border1 color rgb Flags_Color2]
        [Border2 color rgb Flags_Color2]
        [Border2 color rgb Flags_Color3]
        [1 color rgb Flags_Color3]
      }
    }
    finish { Flags_Finish }
    normal { Flags_Normal }
  }
#end
    

#macro Flags_AfghanFlag()
   Flags_ThreeColumnFlag(0, <191, 0, 0>/255, <0, 0.6, 0>) // Layered texture, coat of arms object-patterned texture yet to be added!
   texture
   {
     pigment
     {
        object
        {
          object { Flags_Afghanistan_Coat_of_Arms }
          scale 0.01
          color rgbft 1
          color rgbft <1, 1, 1, 0, 0>
        }
      }
    }
#end 

#macro Flags_AlbanianFlag()
   Flags_Unicolor(<206, 17, 38>/255) // Layered texture, coat of arms object-patterned texture yet to be added!
#end 

#macro Flags_AlgerianFlag()
  Flags_TwoColumnFlag(<0, 134, 56>/255, 1) // Layered texture, crescent and star yet to be added
#end

#macro Flags_AndorranFlag()
  Flags_ThreeIrregularColumnsFlag(<15, 34, 140>/255, <244, 228, 0>/255, <237, 25, 45>/255, 0.31375, 0.68625) // Layered texture,coat of arms object-patterned texture yet to be added!
#end

#macro Flags_AngolanFlag()
  Flags_TwoStripeFlag(<206, 17, 38>/255, 0) // Layered texture, coat of arms object-patterned texture yet to be added!
#end  

// This macro draws an olypic flag with a White background and five coloured circles.
// Because the circles link together we actually use seven circles with the bottom two 
// circles being repeated in the top layers of texture and in the bottom layers.
// This means we can cut quite approximate holes in the top two where other rings cross 
// them. The bottom pair fill in any gaps around the cut.                                              
#macro Flags_Olympic()
  // Define the number of horizontal and vertical positions per line in the mesh2 object
  // Make a circle shape
  #local Flags_Circle = difference {
    cylinder {-z,z,1.05}
    cylinder {-z*1.1,z*1.1,0.85}
  }
  // create a circle shape with two sections cut out for overlaps
  #local Flags_CutCircle = difference {
    object {Flags_Circle}
    box {<-0.55,0.7,-1.1>,<0.05,1.35,1.1>}   
    box {<0.75,-0.3,-1.1>,<1.35,0.35,1.1>}
  }
  
  // Create a layered texture using objects as pigments in each layer
  #declare Flags_Texture = 
    texture {pigment {rgb Flags_Brightness}  finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {
      Flags_Circle translate <3.25,2.15,0>
      color rgbt 1
      color rgb <0.8,0.5,0>*Flags_Brightness // Yellow
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {                          
      Flags_Circle translate <5.75,2.15,0>
      color rgbt 1
      color rgb <0,0.1,0>*Flags_Brightness // Green
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment { object {                          
      Flags_Circle translate <2,2.85,0>
      color rgbt 1
      color rgb <0,0,0.2>*Flags_Brightness // Blue
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment { object {                          
      Flags_Circle translate <4.5,2.85,0>
      color rgbt 1
      color rgb <0,0,0>*Flags_Brightness // Black
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment { object {                          
      Flags_Circle translate <7,2.85,0>
      color rgbt 1
      color rgb <0.8,0,0>*Flags_Brightness // Red
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {                          
      Flags_CutCircle translate <3.25,2.15,0>
      color rgbt 1
      color rgb <0.8,0.5,0>*Flags_Brightness // Yellow
    }} finish {Flags_Finish} normal {Flags_Normal}}
    texture { pigment {object {                          
      Flags_CutCircle translate <5.75,2.15,0>
      color rgbt 1
      color rgb <0,0.1,0>*Flags_Brightness // Green
    }} finish {Flags_Finish} normal {Flags_Normal}}
   
  // Scale the texture down to fit in a unit square in the xy-plane
  #declare Flags_Texture = texture {Flags_Texture scale <1/9,1/5,1>}
#end    


// This macro creates a flag shaped mesh2 object. 
#macro Flags_CreateMesh2FlagObject()
  // Higher values give a finer/smoother surface.
  #ifndef(Flags_XNodes) #declare Flags_XNodes = 100; #end
  #ifndef(Flags_YNodes) #declare Flags_YNodes = 100; #end
  #ifndef(Flags_Width ) #declare Flags_Width  = 5;   #end
  #ifndef(Flags_Height) #declare Flags_Height = 10;  #end
  
  // Create a simple mesh2 object using the flag texture
  mesh2 {
    vertex_vectors {Flags_XNodes*Flags_YNodes,
      #local I = 0;
      #while (I<Flags_XNodes)   
        #local J = 0;
        #while (J<Flags_YNodes)
          // The following line defines the shape of the flag.   
          <Flags_Width*I/(Flags_XNodes-1),Flags_Height*J/(Flags_YNodes-1),sind(I*700/Flags_XNodes+J*500/Flags_YNodes)*0.08-sind(I*2000/Flags_XNodes)*0.06>
          #if (J<(Flags_YNodes-1)&I<(Flags_XNodes-1))
            ,
          #end
          #local J = J+1;
        #end
        #local I = I+1;
      #end
    }
    uv_vectors {Flags_XNodes*Flags_YNodes,
      #local I = 0;
      #while (I<Flags_XNodes)   
        #local J = 0;
        #while (J<Flags_YNodes)   
          <I/(Flags_XNodes-1),J/(Flags_YNodes-1)>
          #if (J<(Flags_YNodes-1)&I<(Flags_XNodes-1))
            ,
          #end
          #local J = J+1;
        #end
      
        #local I = I+1;
      #end
    }
    face_indices {
      (Flags_XNodes-1)*(Flags_YNodes-1)*2,
      #local I = 1;
      #while (I<Flags_XNodes)   
        #local J = 1;
        #while (J<Flags_YNodes)   
          <(I-1)*Flags_YNodes+(J-1),(I)*Flags_YNodes+(J-1),(I)*Flags_YNodes+(J)>,
          <(I)*Flags_YNodes+(J),(I-1)*Flags_YNodes+(J),(I-1)*Flags_YNodes+(J-1)>
          #if (J<(Flags_YNodes-1)&I<(Flags_XNodes-1))
            ,
          #end
          #local J = J+1;
        #end
        #local I = I+1;
      #end
    } 
    texture {uv_mapping Flags_Texture}
  } 
#end
  

// This macro creates a flag shaped height_field object.
// It is adapted from code provided by Kenneth W. with his agreement.
#macro Flags_CreateHeightFieldFlagObject()
  #ifndef(Flags_Width )        #declare Flags_Width         = 10;      #end 
  #ifndef(Flags_Height)        #declare Flags_Height        = 5;       #end   
  #ifndef(Flags_FunctionSeed)  #declare Flags_FunctionSeed  = seed(1); #end                     
  #ifndef(Flags_Slackness)     #declare Flags_Slackness     = 0.03;    #end   
  #ifndef(Flags_WindStrength)  #declare Flags_WindStrength  = 5;       #end // 1 to 9  
                                              
  // Create a new function for each flag drawn
  #ifdef (Flags_Function) #undef Flags_Function #end
  // Create a randomnly offset clock cycle setting for each flag in turn.
  #local Flags_ThisFlagDisplacement = rand(Flags_FunctionSeed);
  #local Flags_ClockDependency      = mod(clock+Flags_ThisFlagDisplacement,1);
  // Declare the function that will be used to make the undulating flag surface
  #declare Flags_Function = function{
    pigment{ 
      // When used in a function pigments are evaluated on the XY plane.
      gradient x
      pigment_map{
        // The edge of the flag attached to the flagpole remains fairly Still, but
        // we can control how still my moving the stationary point back from 0.
        [-Flags_Slackness color rgb .5] 
        // The remainder of the flag gets progressively more dynamic.
        [0.85 average 
          pigment_map{
            [0.2 bozo
              scale <Flags_Height/Flags_Width,1,1>
              scale <0.165,0.55,1.1>
              color_map{
                [0.0 rgb 0]
                [1.0 rgb 1]
              }
              // Allow the pattern to be animated across the height_field in X based on the clock.
              translate 5.5*Flags_ClockDependency*x 
            ]
            [1.0 bozo
              scale <Flags_Height/Flags_Width,1,1>
              scale <0.385,0.44,1.1>
              color_map{
                [0.0 rgb 0]
                [1.0 rgb 1]
              }
              // This displacement avoids that the 'same' bozo pattern simply repeats.
              translate 2*y*Flags_ThisFlagDisplacement 
              // Add a displacement to randomly displace the pattern so we don't just get 
              // a static pattern moving left to right.
              translate 5.5*Flags_ClockDependency*<1,1,0>
            ]
          }
        ]
      }
    }
  }
  // Generate a height_field based upon the pigment function.
  height_field{
    function 1000,600 {Flags_Function(x,y,z).gray}
    smooth
    double_illuminate
    rotate -90*x
    texture{ Flags_Texture}
    translate 0.5*z
    scale <Flags_Width,Flags_Height,Flags_WindStrength/2> 
  }

#end   

// This macro creates a flag shaped object from a box object.
#macro Flags_CreateBoxFlagObject()
  #ifndef(Flags_Width ) #declare Flags_Width  = 10; #end    //944/595
  #ifndef(Flags_Height) #declare Flags_Height = 5;  #end 
  box {0,1
    texture {Flags_Texture}
    scale <Flags_Width,Flags_Height,0.003>
  }
#end