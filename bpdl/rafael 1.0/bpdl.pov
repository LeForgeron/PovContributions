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
#if ( version >= 3.7 )
  #version 3.7; 
#end

global_settings { assumed_gamma 1.0 }

#include "colors.inc"

#local OjoAbsoluto                  = 256;
#local VecesCentroAbsoluto          = 10;     
#local L                            = 0.001;

camera {
        location  <   0,  0, -( VecesCentroAbsoluto+1 )*OjoAbsoluto >*L
        direction z
        sky       y
        angle     38.74
//        look_at  <   0,  0, -VecesCentroAbsoluto*OjoAbsoluto >*L
}         

light_source    {
         < 500  , 500   , -3000 >*L
         White
}
background      {
         Gray50
}    

#local FactorAcercamiento           = 9;

#include "BPDL.inc" 

object                                  {
  BPDL_BaseLampara( )    
  translate         -0.06*y   
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}