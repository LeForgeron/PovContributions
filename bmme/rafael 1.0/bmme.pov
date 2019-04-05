// This file is licensed under the terms of the CC-LGPL.
//
// Autor  : Rafael Angel Campos Vargas
// Correo : RofoelCompos@hotmail.com  
// Apdo. 964-1250 Escazu, San Jose, Costa Rica
// dedicado a Jesus y Maria...
//
// En este momento estoy creando un programa
// de animacion LibreN3D para FreeDOS con el compilador FreePascal
// falta mucho... 24 abril 2018
//                
// Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
// 1 L equivale a 0.055063 pulgadas 
// definido como 0.001 para POVRAY.
//     
// BMME BatidoraManualMotorizadaElectrica
// El archivo dibuja una batidora de mano para cocina.
// Pueden girarse las aspas ademas de algunos cambios menores, pero 
// es muy poco flexible. Es compatible con POVRay 3.1.
//
// La macro principal tiene solo un parametro.
// #macro BMME_Batidora( GiroAspas )
//          GiroAspas           : Angulo para rotar las aspas de la batidora.
//        
// La siguiente macro permite un mayor control de las caracteristicas.
// #macro BMME_BatidoraManualMotorizadaElectrica
//          ( GiroAspas, LateralBatidora, FrenteBatidora, AltoBatidora,
//            SeparacionAspas, FraccionPosAspas,
//            LargoAspas, DiametroSoporte, FraccionAspas, DiametroAspas,
//            TexturaPrincipal, TexturaDecorativa, TexturaTexto, TexturaMetalica )
//          GiroAspas           : Angulo para rotar las aspas de la batidora.
//          LateralBatidora     : Largo en X de la batidora desde el frente hasta
//              su parte posterior. Valor por defecto 127*L.
//          FrenteBatidora      : Ancho frontal en Z de la batidora.
//              Valor por defecto 64*L.
//          AltoBatidora        : Alto del aparato sin aspas en Y.
//              Valor por defecto 94*L.
//          SeparacionAspas     : Separacion entre las aspas.
//              Valor por defecto 27*L.
//          FraccionPosAspas    : Fraccion para ubicar lateralmente las aspas a
//              partir del frente. Valor por defecto 0.35.
//          LargoAspas          : Largo externo visible de las aspas. 
//              Valor por defecto 113*L.
//          DiametroSoporte     : Diametro de los cilindros metalicos que soportan
//              las aspas. Valor por defecto 3.6*L.
//          FraccionAspas       : Fraccion del cilindro de aspas que se encuentra
//              ocupado por las aspas. Valor por defecto 0.516.
//          DiametroAspas       : Diametro efectivo abarcado por las aspas.
//              Valor por defecto 27*L. 
//          TexturaPrincipal    : Textura principal de la batidora.
//              Valor por defecto BMME_TexturaPrincipal.
//          TexturaDecorativa   : Textura del lomo superior de la batidora.
//              Valor por defecto BMME_TexturaDecorativa.
//          TexturaTexto        : Textura del logo de marca.
//              Valor por defecto BMME_TexturaTexto.
//          TexturaMetalica     : Textura de las aspas.
//              Valor por defecto BMME_TexturaMetalica.        
//
// El aparato cerrado se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -64, -122,  -32 >*L
//      Maximo      = <  +64,  +89,  +32 >*L
// El frente del objeto mira hacia  X+, es casi simetrico con respecto
// al plano XY. 
//
// Estas son variables predefinidas o generadas en el
// interior de las macros que no deberian modificarse directamente.
// Si quiere cambiarlas, recurra a los modificadores.  
// #declare BMME_StringLogo                   = "POV-Ray"
//      Cadena de texto para la marca.
// #declare BMME_DefectoTexturaPrincipal  
//      Textura principal del aparato.
// #declare BMME_DefectoTexturaDecorativa
//      Textura del lomo superior de la batidora.
// #declare BMME_DefectoTexturaTexto
//      Textura del logo de marca.
// #declare BMME_DefectoTexturaMetalica
//      Textura de las aspas.    
//
// Los siguientes son los modificadores
// aplicables y redefinibles por el usuario (si se indica es default)   
// #declare BMME_TexturaPrincipal           =
//                  { BMME_DefectoTexturaPrincipal      }
//      Textura principal del aparato.
// #declare BMME_TexturaDecorativa          =
//                  { BMME_DefectoTexturaDecorativa     }
//      Textura del lomo superior de la batidora.
// #declare BMME_TexturaTexto               =
//                  { BMME_DefectoTexturaTexto          }
//      Textura del logo de marca.
// #declare BMME_TexturaMetalica            =
//                  { BMME_DefectoTexturaMetalica       }
//      Textura de las aspas.    
//       
// Para colocarlo simplemente
// #include "BMME.inc" 
// object { BMME_Batidora( 0.0 ) }
//                                  
// Ejemplo con la macro detallada, mismo objeto default
// #include "BMME.inc"   
// object                       {
//   BMME_BatidoraManualMotorizadaElectrica( 0.0, 
//        0.127, 0.064, 0.094, 0.027, 0.35, 0.113, 0.0036, 0.516, 0.027,
//        BMME_TexturaPrincipal, BMME_TexturaDecorativa,
//        BMME_TexturaTexto, BMME_TexturaMetalica )
// }
//        
// Con modificadores
// #include "BMME.inc"
// #include "textures.inc"
// #declare BMME_TexturaPrincipal   = texture { PinkAlabaster } 
// object        { BMME_Batidora( 0.0 ) }
//
#if ( version >= 3.7 )
  #version 3.7; 
#end

global_settings { assumed_gamma 1.0 }

#include "colors.inc"

#declare OjoAbsoluto            = 256;
#declare VecesCentroAbsoluto    = 10;     
#declare L                      = 0.001;
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

#include "BMME.inc"

#local FactorAcercamiento       = 5.5;

object                          {
  BMME_Batidora( 0 )    
  translate             +0.020*y    
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}

