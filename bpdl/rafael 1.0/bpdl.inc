//  This file is licensed under the terms of the CC-LGPL.
//
//  Autor  : Rafael Angel Campos Vargas
//  Correo : RofoelCompos@hotmail.com  
//  Apdo. 964-1250 Escazu, San Jose, Costa Rica
//  dedicado a Jesus y Maria...
//                
//  Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
//  1 L equivale a 0.055063 pulgadas 
//  definido como 0.001 para POVRAY.
//     
//  BPDL BaseParaDecorarLampara
//  El archivo dibuja una base para lampara, en la parte superior se ubicaria
//  un bombillo o algun otro objeto con fines decorativos.
//  Tiene una macro para cambiar las texturas, y
//  es muy poco flexible. No es compatible con POVRay 3.1.
//
//  El modelo original se realizo en Blender, para expotar a POVRay se utilizo
//  el programa PoseRay http://mysite.verizon.net/sfg0000/.
//
//  La macro principal no tiene parametros.
//  #macro BPDL_BaseLampara()
//        
//  La siguiente macro permite cambiar las texturas facilmente.
//  #macro BPDL_BaseParaDecorarLampara( TexturaPrincipal, TexturaSuperior )
//          TexturaPrincipal        : Textura principal del objeto.
//              Valor por defecto BPDL_TexturaPrincipal.
//          TexturaSuperior         : Textura de la capsula superior para el bombillo.
//              Valor por defecto BPDL_TexturaSuperior.
//
//  El aparato tiene las siguientes dimensiones:
//      Alto        = 128*L
//      Radio Base  =  55*L
//  Los extremos de las patas de la base, se encuentran en los vertices de un triangulo
//  casi equilatero sobre el plano XZ.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare BPDL_DefectoTexturaPrincipal
//      Textura principal del objeto.
//  #declare BPDL_DefectoTexturaSuperior
//      Textura de la capsula superior para ubicar el bombillo.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default) 
//  #declare BPDL_TexturaPrincipal                  =
//                  { BPDL_DefectoTexturaPrincipal              }
//      Textura principal del aparato.
//  #declare BPDL_TexturaSuperior                   =
//                  { BPDL_DefectoTexturaSuperior               }   
//      Textura de la capsula superior para el bombillo.
//       
//  Para colocarlo simplemente
//  #include "BPDL.inc" 
//  object { BPDL_BaseLampara( ) }
//                                  
//  Ejemplo con la macro de textura, mismo objeto default
//  #include "BPDL.inc"   
//  object                       {
//    BPDL_BaseParaDecorarLampara( BDLP_TexturaPrincipal, BDLP_TexturaSuperior )
//  }
//        
//  Con modificadores
//  #include "BPDL.inc"
//  #include "textures.inc"
//  #declare BPDL_TexturaPrincipal   = texture { PinkAlabaster } 
//  object        { BPDL_BaseLampara( ) }
//  
#include "BPDL_AUX.inc"   
#include "colors.inc"
#include "stones.inc" 
#include "textures.inc"

#declare BPDL_DefectoTexturaPrincipal   =
  texture                               {
     T_Stone25  
     normal { agate } 
     finish { phong 1}
     scale 10
  }  

#ifndef ( BPDL_TexturaPrincipal )
  #declare BPDL_TexturaPrincipal        = BPDL_DefectoTexturaPrincipal
#end  //  #ifndef ( BPDL_TexturaPrincipal )
  
#declare BPDL_DefectoTexturaSuperior    =  
  texture                               {
     Rusty_Iron  
     finish { phong 1}
     scale 50
   }
   
#ifndef ( BPDL_TexturaSuperior )   
  #declare BPDL_TexturaSuperior         = BPDL_DefectoTexturaSuperior
#end  //  #ifndef ( BPDL_TexturaSuperior )
                  
#macro BPDL_BaseParaDecorarLampara( TexturaPrincipal, TexturaSuperior )
  union {
    object{BPDL_Cube_005_unnamed_material_  }
    object{BPDL_Cube_004_unnamed_material_  }
    object{BPDL_Cube_003_unnamed_material_  }
    object{BPDL_Icosphere_00_unnamed_material_  }
    object{BPDL_Icosphere_00_000_unnamed_material_  }
    object{BPDL_Icosphere_unnamed_material_  }
    object{BPDL_Cone_003_unnamed_material_  }
    object{BPDL_Cone_002_unnamed_material_  }
    object{BPDL_Cone_001_unnamed_material_  }
    object{BPDL_Cube_002_unnamed_material_  }
    object{BPDL_Cube_001_unnamed_material_  }
    object{BPDL_Cube_unnamed_material_  }
    object{BPDL_Torus_004_unnamed_material_  }
    object{BPDL_Torus_003_unnamed_material_  }
    object{BPDL_Torus_001_unnamed_material_  }
    object{BPDL_Torus_002_unnamed_material_  }
    object{BPDL_Mball_unnamed_material_  }
    object{BPDL_Sphere_004_unnamed_material_  }
    object{BPDL_Cylinder_unnamed_material_  }
    union             {
      object{BPDL_Surface_unnamed_material_  }
      object{BPDL_Torus_unnamed_material_  }
      object{BPDL_Cone_unnamed_material_  }   
      texture                   {
        TexturaSuperior
      }
    }
    texture                     {
      TexturaPrincipal
    }      
    scale                   0.01
  }
#end  // #macro BPDL_BaseParaDecorarLampara()

#macro BPDL_BaseLampara()
  BPDL_BaseParaDecorarLampara( BPDL_TexturaPrincipal, BPDL_TexturaSuperior )
#end  //  #macro BPDL_BaseLampara()