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
//  JBIU JoystickButtonInteractiveUser
//  El archivo dibuja un joystick para video juegos, basado
//  en el modelo Atari Flashback.
//  Tiene una macro para modificar las caracteristicas principales,
//  pero es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene cuatro parametros.
//  #macro JBIU_Joystick( ApretarBoton, GiroJoystick,
//                        AnguloJoystick, FraccionEmpujar )
//          ApretarBoton            : "on" presiona el boton de disparo. 
//              "off" no lo presiona.
//          GiroJoystick            : Gira la palanca sobre su propio eje.
//          AnguloJoystick          : Angulo en grados para presionar
//              la palanca. "0" es sentido X+.
//          FraccionEmpujar         : Fraccion en el rango 0..1 para presionar
//              la palanca.    
//                  
//  La siguiente macro permite un mayor control de las caracteristicas.
//  #macro JBIU_JoystickButtonInteractiveUser
//                 ( ApretarBoton, GiroJoystick,
//                   AnguloJoystick, FraccionEmpujar,
//                   LadoJoystick, ExtraLateral, AltoBase,
//                   RadioDecorativo, FraccionAltoEngorde,
//                   ContraccionAltura, AltoPalanca, MaximoAngulo,
//                   DiametroPalanca, AltoAmortiguado,
//                   DiametroBoton, ArregloTexturas )
//          ApretarBoton            : "on" presiona el boton de disparo. 
//              "off" no lo presiona.
//          GiroJoystick            : Gira la palanca sobre su propio eje.
//          AnguloJoystick          : Elige un angulo en grados para presionar
//              la palanca. "0" es sentido X+.
//          FraccionEmpujar         : Fraccion en el rango 0..1 para presionar
//              la palanca.    
//          LadoJoystick            : Tamano del frente en X del Joystick.
//              Valor por defecto 61*L.
//          ExtraLateral            : Tamano en exceso de la dimension Z respecto
//              a la dimension X para ubicar el boton y el logo.
//              Valor por defecto 5*L.
//          AltoBase                : Altura de la base sin relieve.
//              Valor por defecto 26*L.
//          RadioDecorativo         : Referencia para la curvatura en los extremos.
//              Valor por defecto 5*L.
//          FraccionAltoEngorde     : Fraccion propia respecto al AltoBase de la
//              seccion mas ancha de la base.
//              Valor por defecto 0.75.
//          ContraccionAltura       : Referencia para la inclinacion lateral de la base.
//              Utilice fracciones propias pequenas.
//              Valor por defecto 0.10.
//          AltoPalanca             : Alto de la palanca.
//              Valor por defecto 52*L.
//          MaximoAngulo            : Maxima inclinacion en grados de la palanca al empujar.
//              Valor por defecto 14.
//          DiametroPalanca         : Diametro principal de la palanca.
//              Valor por defecto 11*L.
//          AltoAmortiguado         : Referencia para el alto de la palanca, 
//              ocupado por el plastico amortiguador. 
//              Valor por defecto 6*L.
//          DiametroBoton           : Diametro del boton.
//              Valor por defecto 10*L.
//          ArregloTexturas         : Es un arreglo que describe las texturas.
//                  array [JBIU_TotalTexturas]  =
//                      { TexturaPrincipal, TexturaAmortiguado,
//                        TexturaBoton, TexturaPlastica, TexturaLogo }
//                  Valor por defecto equivalente a JBIU_DefectoArregloTexturas.
//                      TexturaPrincipal        : Textura principal del aparato.
//                          Valor por defecto JBIU_TexturaPrincipal. 
//                      TexturaAmortiguado      : Textura del plastico de amortiguamiento.
//                          Valor por defecto JBIU_TexturaAmortiguado.                          
//                      TexturaBoton            : Textura del boton.
//                          Valor por defecto JBIU_TexturaBoton.
//                      TexturaPlastica         : Textura de la superficie decorada.
//                          Valor por defecto JBIU_TexturaPlastica.
//                      TexturaLogo             : Textura del logo y marcas.
//                          Valor por defecto JBIU_TexturaLogo.
//
//  El joystick con parametros nulos se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -31,    0,  -31 >*L
//      Maximo      = <  +31,  +78,  +36 >*L
//      Minimo      = < -LadoJoystick/2, 0, -LadoJoystick/2 >
//      Maximo      = < +LadoJoystick/2, AltoBase+AltoPalanca,
//                      +LadoJoystick/2+ExtraLateral >
//  El boton en el hemisferio X-Z+. La palanca con parametros nulos en el eje Y+.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare JBIU_TotalTexturas                     = 5;
//      Total de texturas para el parametro ArregloTexturas.
//  #declare JBIU_IndiceTexturaPrincipal            = 0;   
//      Indice para la textura principal del aparato en el parametro ArregloTexturas.
//  #declare JBIU_IndiceTexturaAmortiguado          = 1; 
//      Indice para la textura del plastico de amortiguamiento
//      en el parametro ArregloTexturas.      
//  #declare JBIU_IndiceTexturaBoton                = 2;
//      Indice para la textura del boton en el parametro ArregloTexturas.
//  #declare JBIU_IndiceTexturaPlastica             = 3;
//      Indice para la textura de la superficie decorada en el parametro ArregloTexturas.
//  #declare JBIU_IndiceTexturaLogo                 = 4;
//      Indice para la textura del logo y marcas en el parametro ArregloTexturas.
//  #declare JBIU_DefectoTexturaPrincipal        
//      Textura principal del aparato.
//  #declare JBIU_DefectoTexturaAmortiguado
//      Textura del plastico de amortiguamiento.
//  #declare JBIU_DefectoTexturaBoton         
//      Textura del boton.
//  #declare JBIU_DefectoTexturaPlastica      
//      Textura de la superficie decorada.
//  #declare JBIU_DefectoTexturaLogo          
//      Textura del logo y marcas.
//  #declare JBIU_DefectoArregloTexturas            = array [ JBIU_TotalTexturas ]
//      Sirve para pasar como parametro ArregloTexturas. Contiene las texturas
//      por defecto (no las modificadas por el usuario).
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default) 
//  #declare JBIU_LogoCustom                    = object { ... } 
//      Si se define, sustituye el logo de marca por defecto. 
//  #declare JBIU_TexturaPrincipal                  =
//                  { JBIU_DefectoTexturaPrincipal              }
//      Textura principal del aparato.
//  #declare JBIU_TexturaAmortiguado                =
//                  { JBIU_DefectoTexturaAmortiguado            } 
//      Textura del plastico de amortiguamiento.
//  #declare JBIU_TexturaBoton                      =
//                  { JBIU_DefectoTexturaBoton                  }
//      Textura del boton.
//  #declare JBIU_TexturaPlastica                   =
//                  { JBIU_DefectoTexturaPlastica               }
//      Textura de la superficie decorada.
//  #declare JBIU_TexturaLogo                       =
//                  { JBIU_DefectoTexturaLogo                   }
//      Textura del logo y marcas.
//       
//  Para colocarlo simplemente
//  #include "JBIU.inc" 
//  object { JBIU_Joystick( off, 0, 45, 1 ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto default
//  #include "JBIU.inc"   
//  object                       {
//    JBIU_JoystickButtonInteractiveUser( off, 0, 45, 1,
//              0.061, 0.005, 0.026, 0.005, 0.75, 0.10,
//              0.052, 14, 0.011, 0.006, 0.010, JBIU_DefectoArregloTexturas )
//  }
//        
//  Con modificadores
//  #include "JBIU.inc"
//  #include "textures.inc"
//  #declare JBIU_TexturaPrincipal   = texture { PinkAlabaster } 
//  object        { JBIU_Joystick( off, 0, 0, 0 ) }
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

#include "JBIU.inc"

#local FactorAcercamiento       = 15;

object                                  {
  JBIU_Joystick( off, 0, 0, 0 ) 
  rotate            180*y
  translate         -0.038*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}


