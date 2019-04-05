//  This file is licensed under the terms of the CC-LGPL.
//
//  Autor  : Rafael Angel Campos Vargas
//  Correo : RofoelCompos@hotmail.com  
//  Apdo. 964-1250 Escazu, San Jose, Costa Rica
//  dedicado a Jesus y Maria...
//
//  En este momento estoy creando un programa
//  de animacion LibreN3D para FreeDOS con el compilador FreePascal
//  falta mucho... 07 agosto 2018
//                
//  Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
//  1 L equivale a 0.055063 pulgadas 
//  definido como 0.001 para POVRAY.
//     
//  CGCF ClassicGameConsoleFull
//  El archivo dibuja una consola para video juegos, basado
//  en el modelo Atari Flashback.
//  Tiene una macro para modificar las caracteristicas principales,
//  pero es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene solo un parametro.
//  #macro CGCF_Game( BotonEncendido )
//          BotonEncendido          : "on" enciende el LED del aparato y aprieta el boton
//              respectivo. "off" para apagado.
//        
//  La siguiente macro permite un mayor control de las caracteristicas.
//  #macro CGCF_ClassicGameConsoleFull( BotonEncendido,
//                FrenteFundamental, ProfundidadFundamental,
//                ProfundidadBaseBotones, AltoFundamental,
//                LineasDecorativas, Cizalla, FraccionCuerpo,
//                FraccionBase, FraccionPatillas, 
//                FrenteConector, AltoConector, 
//                ArregloBotones, ArregloTexturas )
//          BotonEncendido          : "on" enciende el LED del aparato y aprieta el boton
//              respectivo. "off" para apagado.
//          FrenteFundamental       : Referencia para el frente X de la consola.
//              Valor por defecto 162*L.
//          ProfundidadFundamental  : Referencia para la profundidad Z de la consola.
//              Valor por defecto 105*L.
//          ProfundidadBaseBotones  : Referencia para el tamano en Z de la base de botones.
//              Valor por defecto 45*L.
//          AltoFundamental         : Referencia para el alto de la consola.
//              Valor por defecto 40*L.
//          LineasDecorativas       : Numero entero para relieve de lineas en la superficie
//              media de la consola. Valor por defecto 10.
//          Cizalla                 : Referencia para la inclinacion de las paredes laterales.
//              Valor por defecto 0.17.
//          FraccionCuerpo          : Fraccion desde el piso de AltoFundamental 
//              para ubicar la superficie plana. Debe ser mayor a FraccionBase.
//              Valor por defecto 0.73. 
//          FraccionBase            : Fraccion desde el piso de AltoFundamental
//              para ubicar el inicio de la base principal. Debe ser mayor a FraccionPatillas.
//              Valor por defecto 0.30.
//          FraccionPatillas        : Fraccion desde el piso de AltoFundamental
//              para ubicar el final de las patitas. Valor por defecto 0.045.
//          FrenteConector          : Frente en X de la entrada para Joystick.
//              Valor por defecto 8*L.
//          AltoConector            : Alto en Y de la entrada para Joystick.
//              Valor por defecto 3.5*L.
//          ArregloBotones          : Es un arreglo que describe los botones. 
//              El total de botones puede cambiarse.
//              Debe tener el formato array [TotalBotones][2]
//                 { { FraccionX, BanderaPresionar },... }
//              Valor por defecto CGCF_ArregloBotones que es modificable.
//                  FraccionX           : Fraccion propia de 0..1. Establece la posicion
//                      en X del boton. Use valores negativos para desactivar el boton.
//                      El boton 0 se asume el boton rojo de encendido.
//                  BanderaPresionar    : "on" presiona el boton, y "off" para liberar.
//                      El boton de encendido se controla con el parametro 
//                      BotonEncendido, y el valor en este campo se ignorara. 
//          ArregloTexturas         : Es un arreglo que describe las texturas.
//                  array [CGCF_TotalTexturas]  =
//                  { TexturaPrincipal, TexturaBandaDecorativa, TexturaMetalica,
//                    TexturaBaseBotones, TexturaBotonOn, TexturaBotones,
//                    TexturaLedOn, TexturaLedOff }
//                  Valor por defecto equivalente a CGCF_DefectoArregloTexturas.
//                      TexturaPrincipal        : Textura principal del aparato.
//                          Valor por defecto CGCF_TexturaPrincipal. 
//                      TexturaBandaDecorativa  : Textura de la banda decorativa y logo.
//                          Valor por defecto CGCF_TexturaBandaDecorativa.                          
//                      TexturaMetalica         : Textura de los pines metalicos.
//                          Valor por defecto CGCF_TexturaMetalica.
//                      TexturaBaseBotones      : Textura de la placa de botones.
//                          Valor por defecto CGCF_TexturaBaseBotones.
//                      TexturaBotonOn          : Textura del boton rojo de encendido.
//                          Valor por defecto CGCF_TexturaBotonOn.
//                      TexturaBotones          : Textura de los botones.
//                          Valor por defecto CGCF_TexturaBotones.
//                      TexturaLedOn            : Textura para el LED cuando encendido.
//                          Valor por defecto CGCF_TexturaLedOn.
//                      TexturaLedOff           : Textura para el LED cuando apagado.
//                          Valor por defecto CGCF_TexturaLedOff.
//
//  El aparato cerrado se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -81,    0,  -52 >*L
//      Maximo      = <  +81,  +41,  +51 >*L
//  El jugador se supone sentado hacia Z-. Con excepcion del panel de botones,
//  es simetrico respecto al plano YZ. 
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare CGCF_TotalTexturas                     = 8;
//      Total de texturas para el parametro ArregloTexturas.
//  #declare CGCF_IndiceTexturaPrincipal            = 0;   
//      Indice para la textura principal del aparato en el parametro ArregloTexturas.
//  #declare CGCF_IndiceTexturaBandaDecorativa      = 1; 
//      Indice para la textura de la banda decorativa y logo
//      en el parametro ArregloTexturas.      
//  #declare CGCF_IndiceTexturaMetalica             = 2;
//      Indice para la textura de los pines metalicos en el parametro ArregloTexturas.
//  #declare CGCF_IndiceTexturaBaseBotones          = 3;
//      Indice para la textura de la base de botones en el parametro ArregloTexturas.
//  #declare CGCF_IndiceTexturaBotonOn              = 4;
//      Indice para la textura del boton de encendido en el parametro ArregloTexturas.
//  #declare CGCF_IndiceTexturaBotones              = 5;
//      Indice para la textura general de botones en el parametro ArregloTexturas.
//  #declare CGCF_IndiceTexturaLedOn                = 6;
//      Indice para la textura del Led encendido en el parametro ArregloTexturas.
//  #declare CGCF_IndiceTexturaLedOff               = 7;
//      Indice para la textura del Led apagado en el parametro ArregloTexturas.
//  #declare CGCF_DefectoTexturaPrincipal        
//      Textura principal del aparato.
//  #declare CGCF_DefectoTexturaBandaDecorativa  
//      Textura de la banda decorativa y logo.
//  #declare CGCF_DefectoTexturaMetalica         
//      Textura de los pines metalicos.
//  #declare CGCF_DefectoTexturaBaseBotones      
//      Textura de la placa de botones.
//  #declare CGCF_DefectoTexturaBotonOn          
//      Textura del boton rojo de encendido.
//  #declare CGCF_DefectoTexturaBotones          
//      Textura de los botones.
//  #declare CGCF_DefectoTexturaLedOn            
//      Textura para el LED cuando encendido.
//  #declare CGCF_DefectoTexturaLedOff           
//      Textura para el LED cuando apagado.
//  #declare CGCF_DefectoArregloTexturas            = array [ CGCF_TotalTexturas ]
//      Sirve para pasar como parametro ArregloTexturas. Contiene las texturas
//      por defecto (no las modificadas por el usuario).
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default) 
//  #declare CGCF_LogoCustom                    = object { ... } 
//      Si se define, sustituye el logo de marca por defecto. 
//  #declare CGCF_SimplificarModelo             = off;   
//      Si se activa se genera una version mas simple de dibujo, que
//      podria ser util en procesos lentos.
//  #declare CGCF_ArregloBotones                    = array [ 5 ][ 2 ]
//      Parametro por defecto para ArregloBotones. Utilice
//      para apretar los botones de juego, o si quiere modificar su posision.
//  #declare CGCF_FraccionXLogo                     = 0.40;    
//      Para ubicar el logo, se interpreta como fraccion del panel de botones.
//      Use un valor negativo para desactivar el dibujo.
//  #declare CGCF_FraccionXIndicador                = 0.10; 
//      Para ubicar la lucesita de encendido, se interpreta como fraccion del panel
//      de botones. Use un valor negativo para desactivar el dibujo. 
//  #declare CGCF_TexturaPrincipal                  =
//                  { CGCF_DefectoTexturaPrincipal              }
//      Textura principal del aparato.
//  #declare CGCF_TexturaBandaDecorativa            =
//                  { CGCF_DefectoTexturaBandaDecorativa        } 
//      Textura de la banda decorativa y logo.
//  #declare CGCF_TexturaMetalica                   =
//                  { CGCF_DefectoTexturaMetalica               }
//      Textura de los pines metalicos.
//  #declare CGCF_TexturaBaseBotones                =
//                  { CGCF_DefectoTexturaBaseBotones            }
//      Textura de la placa de botones.
//  #declare CGCF_TexturaBotonOn                    =
//                  { CGCF_DefectoTexturaBotonOn                }
//      Textura del boton rojo de encendido.
//  #declare CGCF_TexturaBotones                    =
//                  { CGCF_DefectoTexturaBotones                }
//      Textura de los botones.
//  #declare CGCF_TexturaLedOn                      =
//                  { CGCF_DefectoTexturaLedOn                  }
//      Textura para el LED cuando encendido.
//  #declare CGCF_TexturaLedOff                     =
//                  { CGCF_DefectoTexturaLedOff                 }
//      Textura para el LED cuando apagado.
//       
//  Para colocarlo simplemente
//  #include "CGCF.inc" 
//  object { CGCF_Game( on ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto default
//  #include "CGCF.inc"   
//  object                       {
//    CGCF_ClassicGameConsoleFull( on,
//                  0.162, 0.105, 0.045, 0.040, 10, 
//                  0.17, 0.73, 0.30, 0.045, 0.008, 0.0035,    
//                  CGCF_ArregloBotones, CGCF_DefectoArregloTexturas )
//  }
//        
//  Con modificadores
//  #include "CGCF.inc"
//  #include "textures.inc"
//  #declare CGCF_TexturaPrincipal   = texture { PinkAlabaster } 
//  object        { CGCF_Game( on ) }
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

#include "CGCF.inc"

#local FactorAcercamiento       = 9;

object                                  {
  CGCF_Game( on )   
  translate             -0.02*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}


