//  This file is licensed under the terms of the CC-LGPL.
//  
//  Autor  : Rafael Angel Campos Vargas
//  Correo : RofoelCompos@hotmail.com  
//  Apdo. 964-1250 Escazu, San Jose, Costa Rica
//  dedicado a Jesus y Maria...
//
//  ADVERTENCIA: (todas las fuentes son legitimas y de libre uso comercial) 
//  Es probable que su distribucion incluya el archivo
//  "link.inc"
//  Created by Chris Colefax, 20 April 1998
//  archivo especializado para generar cadenas...
//  puede obtenerse junto con "fireplug.inc" en la misma fuente
//  link_object (el elemento base de la cadena) fue transcrito
//  con pocas modificaciones del archivo
//  "fireplug.inc"
//  Tomado de la Biblioteca de POVRAY administrada por Micha Riser
//  autor Christophe Bouffartigue de fecha 3 Julio 2000
//  email: christophe.bouffartigue@libertysurf.fr
//  FIN ADVERTENCIA
//
//  Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
//  1 L equivale a 0.055063 pulgadas 
//  definido como 0.001 para POVRAY.
//     
//  HHBI HidranteHumedadBocaIncendio
//  El archivo dibuja un modelo sencillo de hidrante municipal.
//  Posee una macro para variar sus dimensiones principales y texturas. 
//  La base se puede extener bajo el suelo para ubicar en terreno irregular.
//  Es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene solo un parametro.
//  #macro HHBI_Hidrante( FraccionSubSuelo )                            
//          FraccionSubSuelo            : Fraccion propia, para extender la base
//              bajo tierra. Util al ubicar en superficies irregulares o inclinadas.
//              Con un valor "0.0" la base termina en el plano, con un
//              maximo de "1.0" perfora Y- hasta una profundidad igual a su base.
//        
//  La siguiente macro permite un mayor control de las caracteristicas:
//  #macro HHBI_HidranteHumedadBocaIncendio( FraccionSubSuelo,
//                  AltoHidrante, DiametroHidrante,
//                  FraccionBase, CizallaBase,
//                  FraccionIntermedia, FraccionSuperior, ContactoHidrante,
//                  TexturaPrincipal, TexturaUniones, TexturaExtremos,
//                  TexturaBase, TexturaCadenas )
//          FraccionSubSuelo            : Fraccion propia, para extender la base
//              bajo tierra. Util al ubicar en superficies irregulares o inclinadas.
//              Con un valor "0.0" la base termina en el plano, con un
//              maximo de "1.0" perfora Y- hasta una profundidad igual a su base.
//          AltoHidrante                : Alto del hidrante desde la superficie.
//              Valor por defecto 600*L.
//          DiametroHidrante            : Referencia para los diametros de los cilindros.
//              Valor por defecto 150*L.
//          FraccionBase                : Fraccion propia de "AltoHidrante" ocupada
//              por la base visible del hidrante. Valor por defecto 0.4.
//          CizallaBase                 : Inclinacion de la pared delantera de la base.
//              Utilice "0" para paredes verticales, y "1.0 para 45 grados.
//              Valor por defecto 1/4.
//          FraccionIntermedia          : Fraccion propia de "AltoHidrante" para la
//              union entre la base y el hidrante propiamente.
//              Valor por defecto 0.093.
//          FraccionSuperior            : Fraccion propia de "AltoHidrante" para la
//              seccion superior del hidrante. Valor por defecto 0.093.
//          ContactoHidrante            : Referencia para el largo de las prolongaciones
//              laterales y frontal del hidrante para conectarse con las mangueras del
//              carro de bomberos.
//              Valor por defecto 60*L.          
//          TexturaPrincipal            : Textura principal del hidrante.
//              Valor por defecto HHBI_TexturaPrincipal.
//          TexturaUniones              : Textura de los cilindros metalicos que
//              unen el cuerpo principal del hidrante con la base y sus laterales.
//              Valor por defecto HHBI_TexturaUniones.
//          TexturaExtremos             : Textura de los cierres extremos del hidrante.
//              Valor por defecto HHBI_TexturaExtremos.
//          TexturaBase                 : Textura de la base de concreto.
//              Valor por defecto HHBI_TexturaBase.
//          TexturaCadenas              : Textura de las cadenas y algunos tornillos.
//              Valor por defecto HHBI_TexturaCadenas.
//
//  El aparato con parametro nulo, tiene las siguientes dimensiones:
//      Alto            = 600*L
//      Alto            = AltoHidrante
//      Frente          = 270*L
//      Frente          = DiametroHidrante+2*ContactoHidrante
//      Profundidad Z   = -150*L..95*L
//      Profundidad Z   = -( DiametroHidrante/2+1.25*ContactoHidrante )..
//          ( DiametroHidrante/2+CizallaBase*FraccionBase*AltoHidrante/3 )
//  Con parametro nulo, inicia sobre el plano XZ hacia Y+, con frente hacia Z-.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores. 
//  #declare HHBI_DefectoTexturaPrincipal            
//      Textura principal del hidrante.
//  #declare HHBI_DefectoTexturaUniones              
//      Textura de los cilindros metalicos que
//      unen el cuerpo principal del hidrante con la base y sus laterales.
//  #declare HHBI_DefectoTexturaExtremos             
//      Textura de los cierres extremos del hidrante.
//  #declare HHBI_DefectoTexturaBase                 
//      Textura de la base de concreto.
//  #declare HHBI_DefectoTexturaCadenas              
//      Textura de las cadenas y algunos tornillos.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default)   
//  #declare HHBI_BanderaLink                   = file_exists( "LINK.inc" );
//      Algunas distribuciones talvez no incluyan el archivo "LINK.inc"
//      que no es compatible con el standard de la biblioteca oficial.
//      Con un valor "on" indica que se dibujara la cadena, y un valor "off"
//      para no dibujar. Se ajusta automaticamente, pero el usuario 
//      si lo necesitara podria modificar su valor.
//  #declare HHBI_TexturaPrincipal              =
//                      { HHBI_DefectoTexturaPrincipal              }    
//      Textura principal del hidrante.
//  #declare HHBI_TexturaUniones                =
//                      { HHBI_DefectoTexturaUniones                }
//      Textura de los cilindros metalicos que
//      unen el cuerpo principal del hidrante con la base y sus laterales.
//  #declare HHBI_TexturaExtremos               =
//                      { HHBI_DefectoTexturaExtremos               }
//      Textura de los cierres extremos del hidrante.
//  #declare HHBI_TexturaBase                   =
//                      { HHBI_DefectoTexturaBase                   }
//      Textura de la base de concreto.
//  #declare HHBI_TexturaCadenas                =
//                      { HHBI_DefectoTexturaCadenas                }
//      Textura de las cadenas y algunos tornillos.
//       
//  Para colocarlo simplemente
//  #include "HHBI.inc" 
//  object { HHBI_Hidrante( 0 ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto por defecto
//  #include "HHBI.inc"   
//  object                       {
//    HHBI_HidranteHumedadBocaIncendio( 0,
//      0.600, 0.150, 0.4, 1/4, 0.093, 0.093, 0.060,
//      HHBI_TexturaPrincipal, HHBI_TexturaUniones, HHBI_TexturaExtremos,
//      HHBI_TexturaBase, HHBI_TexturaCadenas )
//  }
//        
//  Con modificadores
//  #include "HHBI.inc"
//  #include "textures.inc"
//  #declare HHBI_TexturaPrincipal   = PinkAlabaster 
//  object        { HHBI_Hidrante( 0 ) }
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

#include "HHBI.inc"

#local FactorAcercamiento       = 2.0;

object                          {
  HHBI_Hidrante( 0.0 )
  translate             -0.300*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}
