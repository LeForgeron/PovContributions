// This file is licensed under the terms of the CC-LGPL
/*************************************************************************
COBBLESTREET GENERATOR FOR POV-Ray 3.6+ 
A simple macro where cobbles are traced upon a heightfield

Created by: Thomas de Groot (the Netherlands)
    e-mail: tDOTdegrootATinterDOTnlDOTnet
        On: May 2004
   Updated: May 2005, October 2007 & June 2008
             
 Copyright: May be freely used and modified.
            Acknowledgement of author is appreciated.

  Patterns: 1 Checkerboard pattern
            2 Brick-like pattern
            3 Herringbones pattern
 *************************************************************************/

#ifndef (Standalone)	#declare Standalone = true;	#end 
// true for testing the macro, otherwise set to false in main script before including the macro file

//========================================================================================================
#macro Cobblestreet (Pattern,MySurface,Depth,StoneRot,OriginX,OriginZ,EndX,EndZ,N,R,Crack,Cobbletex)

#ifndef(_RAND_INC) #include "rand.inc"	#end
#ifndef(_TRANSFORMS_INC)	#include "transforms.inc"	#end

// ********  SEEDS  *******

#local Sx = seed(112358);
#local Sy = seed(235813);
#local Sz = seed(581321);


// ********  OBJECTS  *******
#declare CobbleStandalone = false;
#include "hfcs_cobble.inc"

#local Cobblestone =
//superellipsoid { <0.1, 0.1> scale 0.5}
object {Cobble scale 0.5}

#local HalfCobblestone =
 object { Cobblestone
   scale <0.5,1,1>
 }

// Width of the cobblestone pattern:
#local Street_Width=EndX-OriginX;

#debug concat("\nCobblestones calculation of Pattern ",str(Pattern,1,0)," started\n")

// ************  COBBLESTONE PATTERN TYPES  ************
#declare CobbleStreet =
#local Count = 0; // number of stones

#switch (Pattern)
#case (1)

#local M=Crack*(N-1);
#local C_Length=(Street_Width-M)/N;
#local C_Width=C_Length*R;

#local T_Cobblestone =
object {Cobblestone
  scale <C_Length, C_Width, C_Width>
  translate <C_Length/2, -(C_Width/2)+Depth, C_Width/2>
}

#local J=OriginZ;

// start of the cobbled street:
union {
 #while (J<=EndZ)//int(EndZ))
  #local I=OriginX;
  #local N1=1;
  
   #while (N1<=N)
      #local Norm = <0, 0, 0>;
      #local Point = <I, 1.0, J>;
      #local Pos = trace (
                           MySurface,   // object to test
                           Point,       // starting point
                           -y,          // direction
                           Norm         // normal
                         );
                           
      #if (Norm.x != 0 | Norm.y != 0 | Norm.z != 0)   // if intersection is found, normal differs from 0
        object { T_Cobblestone
          texture {
            Cobbletex
            rotate <rand(Sx), rand(Sy), rand(Sz)>
            translate <rand(Sx), rand(Sy), rand(Sz)>
          }
          #if (Crack > 0)
            rotate y*RRand(-StoneRot,StoneRot,Sy)
          #end
          Reorient_Trans(y, Norm)
          translate <Pos.x, Pos.y+RRand(-Depth/10,Depth/10,Sz), Pos.z> // place the cobble and moves its slightly up or down
        }
        #local Count = Count + 1; // number of stones led down
      #end // end of Norm intersection
      #local I=I+C_Length+Crack;
      #local N1=N1+1;
    #end // end of while N1
    #local J=J+C_Width+Crack;
  #end // end of while J
} // end of the cobbled street

#break

//---------------------------------------------------------
#case (2)

#local M=Crack*N;
// Number of half-stones:
#local Half=(N*2)+1;
#local C_Length=((Street_Width-M)/Half)*2;
#local C_Width=C_Length*R;

#local T_Cobblestone =
object {Cobblestone
  scale <C_Length, C_Width, C_Width>
  translate <C_Length/2, -(C_Width/2)+Depth, C_Width/2>
}

#local T_HalfCobblestone =
object {HalfCobblestone
  scale <C_Length, C_Width, C_Width>
  translate <C_Length/4, -(C_Width/2)+Depth, C_Width/2>
}

#local J=OriginZ;
#local Offset=false;

// start of the cobbled street
union {
  #while (J<=EndZ)//int(EndZ))//---------------------------------------------------------------------------------- start of while J
    #local I=OriginX;
     
    #if (Offset=true)//------------------------------------------------------------------------------------
      #local Norm = <0, 0, 0>;                                                                           //
      #local Point = <I, 1.0, J>;                                                                        //
      #local Pos = trace (                                                                               //
                           MySurface,   // object to test                                                //
                           Point,       // starting point                                                //
                           -y,          // direction                                                     //
                           Norm         // normal                                                        //
                         );                                                                              //
                                                                                                         //
      #if (Norm.x != 0 | Norm.y != 0 | Norm.z != 0) // if intersection found, normal differs from 0      //
        object { T_HalfCobblestone                                                                       //
          texture {                                                                                      //
            Cobbletex                                                                                    //
            rotate <rand(Sx), rand(Sy), rand(Sz)>                                                        //
            translate <rand(Sx), rand(Sy), rand(Sz)>                                                     //
          }                                                                                              //
          #if (Crack > 0)                                                                                //
            rotate y*RRand(-StoneRot,StoneRot,Sy)                                                        //
          #end                                                                                           //
          Reorient_Trans(y, Norm)                                                                        //
          translate <Pos.x, Pos.y+RRand(-Depth/10,Depth/10,Sz), Pos.z> // place the cobble and moves its slightly up or down
        }                                                                                                //
        #local Count = Count + 1; // number of stones led down
      #end // end of Norm intersection                                                                   //
    #end // end of offset test-----------------------------------------------------------------------------
    #local N1=1;
     
    #while (N1<=N)//---------------------------------------------------------------------------------------
      #local Norm = <0, 0, 0>;                                                                           //
      #if (Offset=true)                                                                                  //
        #local I = I+(C_Length/2)+Crack;                                                                 //
      #end // end of offset test                                                                         //
      #local Point = <I, 1.0, J>;                                                                        //
      #local Pos = trace (                                                                               //
                           MySurface,   // object to test                                                //
                           Point,       // starting point                                                //
                           -y,          // direction                                                     //
                           Norm         // normal                                                        //
                         );                                                                              //
                                                                                                         //
      #if (Norm.x != 0 | Norm.y != 0 | Norm.z != 0) // if intersection found, normal differs from 0      //
        object { T_Cobblestone                                                                           //
          texture {                                                                                      //
            Cobbletex                                                                                    //
            rotate <rand(Sx), rand(Sy), rand(Sz)>                                                        //
            translate <rand(Sx), rand(Sy), rand(Sz)>                                                     //
          }                                                                                              //
          #if (Crack > 0)                                                                                //
            rotate y*RRand(-StoneRot,StoneRot,Sy)                                                        //
          #end                                                                                           //
          Reorient_Trans(y, Norm)                                                                        //
          translate <Pos.x, Pos.y+RRand(-Depth/10,Depth/10,Sz), Pos.z> // place the cobble and moves its slightly up or down
        }                                                                                                //
        #local Count = Count + 1; // number of stones led down
      #end // end of Norm intersection                                                                   //
      #if (Offset=true)                                                                                  //
        #local I=I-(C_Length/2)-Crack;                                                                   //
      #end                                                                                               //
      #local I=I+C_Length+Crack;                                                                         //
      #local N1=N1+1;                                                                                    //
    #end // end of while N1--------------------------------------------------------------------------------                                                                                
      
    #if (Offset=true)//------------------------------------------------------------------------------------
      #local Offset=false;                                                                               //
    #else                                                                                                //
      #local Norm = <0, 0, 0>;                                                                           //
      #local Point = <I, 1.0, J>;                                                                        //
      #local Pos = trace (                                                                               //
                           MySurface,   // object to test                                                //
                           Point,       // starting point                                                //
                           -y,          // direction                                                     //
                           Norm         // normal                                                        //
                         );                                                                              //
                                                                                                         //
      #if (Norm.x != 0 | Norm.y != 0 | Norm.z != 0) // if intersection found, normal differs from 0      //
        object { T_HalfCobblestone                                                                       //
          texture {                                                                                      //
            Cobbletex                                                                                    //
            rotate <rand(Sx), rand(Sy), rand(Sz)>                                                        //
            translate <rand(Sx), rand(Sy), rand(Sz)>                                                     //
          }                                                                                              //
          #if (Crack > 0)                                                                                //
            rotate y*RRand(-StoneRot,StoneRot,Sy)                                                        //
          #end                                                                                           //
          Reorient_Trans(y, Norm)                                                                        //
          translate <Pos.x, Pos.y+RRand(-Depth/10,Depth/10,Sz), Pos.z> // place the cobble and moves its slightly up or down
        }                                                                                                //
        #local Count = Count + 1; // number of stones led down
      #end // end of Norm intersection                                                                   //
      #local Offset=true;                                                                                //
    #end // end of offset test-----------------------------------------------------------------------------
    #local J=J+C_Width+Crack;
  #end //-------------------------------------------------------------------------------------------------- end of while J
} // end of the cobbled street
  
#break

//---------------------------------------------------------
#case (3)

#local M=Crack*(N-1);
#local Xoff=(Street_Width-M)/N;
#local Zoff=Xoff/2;
// Size of the individual stones as a function of Zoff:
#local C_Width=sqrt(pow(Zoff,2)+pow(Zoff,2));
#local C_Length=C_Width*2;


#local T_Cobblestone =
object {Cobblestone
  scale <C_Length, C_Width, C_Width>
  translate <0, -(C_Width/2)+Depth, 0>
}

#local J=OriginZ;
#local Herring=false;

// start of the cobbled street
union {
 #while (J<=EndZ)//int(EndZ))
  #local I=OriginX;
  #local Hump=0;
  #local N1=1;
  
   #while (N1<=N)
     #local Norm = <0, 0, 0>;                                                                         
     #if (Herring=false)
       #local J = J-(Zoff*0.5);
       #local Point = <I, 1.0, J>;                                                                      
       #local Pos = trace (                                                                             
                            MySurface,   // object to test                                              
                            Point,       // starting point                                              
                            -y,          // direction                                                   
                            Norm         // normal                                                      
                          );                                                                            
                                                                                                         
       #if (Norm.x != 0 | Norm.y != 0 | Norm.z != 0) // if intersection found, normal differs from 0      
         object { T_Cobblestone
           texture {
             Cobbletex
             rotate <rand(Sx), rand(Sy), rand(Sz)>
             translate <rand(Sx), rand(Sy), rand(Sz)>
           }
           rotate -45*y
           #if (Crack > 0)
             rotate y*RRand(-StoneRot,StoneRot,Sy)
           #end
           Reorient_Trans(y, Norm)                                                                        
           translate <Pos.x, Pos.y+RRand(-Depth/10,Depth/10,Sz), Pos.z> // place the cobble and moves its slightly up or down
         }                                                                                                
        #local Count = Count + 1; // number of stones led down
       #end // end of Norm intersection                                                                   
       #local J = J+(Zoff*0.5);                                                                   
       #local Herring=true;
        
     #else
       #local J = J+(Zoff*0.5);
       #local Point = <I, 1.0, J>;                                                                      
       #local Pos = trace (                                                                             
                            MySurface,   // object to test                                              
                            Point,       // starting point                                              
                            -y,          // direction                                                   
                            Norm         // normal                                                     
                          );                                                                            
                                                                                                         
       #if (Norm.x != 0 | Norm.y != 0 | Norm.z != 0) // if intersection found, normal differs from 0    
         object { T_Cobblestone
           texture {
             Cobbletex
             rotate <rand(Sx), rand(Sy), rand(Sz)>
             translate <rand(Sx), rand(Sy), rand(Sz)>
           }
           rotate 45*y
           #if (Crack > 0)
             rotate y*RRand(-StoneRot,StoneRot,Sy)
           #end
           Reorient_Trans(y, Norm)                                                                      
           translate <Pos.x, Pos.y+RRand(-Depth/10,Depth/10,Sz), Pos.z> // place the cobble and moves its slightly up or down
         }                                                                                           
        #local Count = Count + 1; // number of stones led down
       #end // end of Norm intersection                                                            
       #local J = J-(Zoff*0.5);                                                                   
       #local Herring=false;
     #end // end of herring test
     #local I=I+(Xoff)+Crack;
     #local N1=N1+1;
   #end // end of while N1
   
   #local J=J+(Zoff*2)+Crack;
 #end // end of while J

} // end of the cobbled street

#end // end of case
#debug concat("Cobblestones calculation of Pattern ",str(Pattern,1,0)," finished. ",str(Count,1,0)," stones led.\n")

#end // end of CobbleStreet macro

//========================================================================================================
#if (Standalone)
#include "colors.inc"
#include "stones.inc"

global_settings {
  assumed_gamma 1.0
}

#default {
  texture { pigment {color red 1} finish {ambient 0.0} }
}

background { color <0.0,0.5,1.0> }

camera {
  location  <0.0, 1.5, -4.0>
  direction 1.5*z
  right     x*image_width/image_height
  look_at   <0.0, 0.0,  -0.5>
  angle     40
}

light_source {   // Sunlight
  <-2000, 5000, 3000>
  color rgb <1.0, 1.0, 1.0>
}

// ********  TEXTURES  *******
#declare CobbleTex= 
     texture {      
       pigment {
         granite
         color_map {
           [ 0.0     rgbft <0.499564, 0.499564, 0.499564, 0.0, 0.0> ]
           [ 0.25    rgbft <0.649707, 0.649707, 0.649707, 0.0, 0.0> ]
           [ 0.5     rgbft <0.499858, 0.499858, 0.499858, 0.0, 0.0> ]
           [ 0.75    rgbft <0.699587, 0.699587, 0.699587, 0.0, 0.0> ]
           [ 1.0     rgbft <0.499644, 0.499644, 0.499644, 0.0, 0.0> ]
         }
         frequency 100.0
         ramp_wave
       }      
       normal {
         granite , 0.5
         warp {
           turbulence <0.500164, 0.500364, 0.499804>
           omega 0.500404
           lambda 1.999712
         }
       }      
       finish {
         ambient 0.0
         diffuse 0.6
         specular 0.1
         roughness 0.005
       }      
     scale 0.025
     }
// ********  end of TEXTURES  *******

plane { y, 0.0
  pigment {DarkGreen}
}

#declare MySurface = 
height_field {
  png "plasma3.png"
  texture {
    pigment {
      image_map { png "plasma3.png" map_type 0 interpolate 2 once }
      rotate x*90 // lay X-Y image map down onto X-Z height field plane
    }
  }
  translate <-0.5,0,-0.5>
  scale <2, 0.05, 4> // don't exagerate too much y-scale!
}

// macro:
Cobblestreet ( 2,						// Pattern		=	Type of pattern: Checkerboard = 1; Brick-like = 2; Herringbones = 3
               MySurface		// MySurface	=	Surface on which the street is to be traced
               0.01,				// Depth			=	Depth of dirt between stones (i.e. depth of MySurface)
               4,						// StoneRot		=	Maximum random rotation around y (keep low! only when Crack>0)
               -0.8,					// OriginX		=	Start point X of cobblestoned surface
               -1.8,					// OriginZ		=	Start point Z of cobblestoned surface
               0.8,						// EndX				=	End point X of cobblestoned surface
               1.8,						// EndZ				=	End point Z of cobblestoned surface
               15,					// N					=	Number of cobblestones in X-direction (note: N determines the size of individual stones)
               0.333,				// R					=	Ratio length/width of each cobblestone (only for pattern 1 and 2)
               0.001,				// Crack			=	Crack-width between the cobblestones
               CobbleTex		// Cobbletex	=	Stone texture
             )

// the cobbled street:
object {CobbleStreet}

// the used surface (also the dirt between the stones):
object {MySurface}

#end // end of Standalone
