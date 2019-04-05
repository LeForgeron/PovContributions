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
#include "colors.inc"
#include "textures.inc"

#declare CGCF_L                         = 0.001;

#if ( version < 3.2 )
  #ifndef( CGCF_POV3_1 )
    #declare CGCF_POV3_1        = on;
  #end
#else
  #ifndef( CGCF_POV3_1 )
    #declare CGCF_POV3_1        = off;
  #end
#end

#declare CGCF_SimplificarModelo         = off;   
   
#if ( CGCF_POV3_1 )
  // Copia textual de Povray_Logo en logo.inc
  // incluido aqui por compatibilidad con POV_RAY 3.1
  #declare CGCF_Logo                      =
  merge {
     sphere {2*y, 1}
     difference {
        cone {2*y, 1, -4*y, 0}
        sphere {2*y, 1.4 scale <1,1,2>}
     }
     difference {
        sphere {0, 1 scale <2.6, 2.2, 1>}
        sphere {0, 1 scale <2.3, 1.8, 2> translate <-0.35, 0, 0>}
        rotate z*30 translate 2*y
     }
     rotate <0, 0, -25>
     translate <-0.5,-0.35,0>
     scale 1/4
  }
#else  // #else ( CGCF_POV3_1 )
  #include "logo.inc"
  #declare CGCF_Logo = Povray_Logo
#end   // #else ( CGCF_POV3_1 )

#declare CGCF_TotalArregloBotones       = 5;
#declare CGCF_ArregloBotones            = array [ CGCF_TotalArregloBotones ][2]
  { { 0.00, off },
    { 0.20, off },
    { 0.60, off },
    { 0.75, off },
    { 1.00, off } }

#declare CGCF_FraccionXLogo             = 0.40;   

#declare CGCF_FraccionXIndicador        = 0.10;

#declare CGCF_DefectoTexturaPrincipal   =
  texture                               {
    pigment             { Gray20 }
  }

#ifndef ( CGCF_TexturaPrincipal )
  #declare CGCF_TexturaPrincipal        = CGCF_DefectoTexturaPrincipal
#end  //  #ifndef ( CGCF_TexturaPrincipal )

#declare CGCF_DefectoTexturaBandaDecorativa     =
  texture                               {
    Sandalwood
  }

#ifndef ( CGCF_TexturaBandaDecorativa )
  #declare CGCF_TexturaBandaDecorativa  = CGCF_DefectoTexturaBandaDecorativa
#end  //  #ifndef ( CGCF_TexturaBandaDecorativa )

#declare CGCF_DefectoTexturaMetalica     =
  texture                               {
    Chrome_Texture
  }

#ifndef ( CGCF_TexturaMetalica )
  #declare CGCF_TexturaMetalica  = CGCF_DefectoTexturaMetalica
#end  //  #ifndef ( CGCF_TexturaMetalica )

#declare CGCF_DefectoTexturaBaseBotones     =
  texture                               {
    pigment             { Gray20 }
    finish              { metallic }
  }

#ifndef ( CGCF_TexturaBaseBotones )
  #declare CGCF_TexturaBaseBotones  = CGCF_DefectoTexturaBaseBotones
#end  //  #ifndef ( CGCF_TexturaBaseBotones )

#declare CGCF_DefectoTexturaBotonOn     =
  texture                               {
    pigment             { Red }
  }

#ifndef ( CGCF_TexturaBotonOn )
  #declare CGCF_TexturaBotonOn  = CGCF_DefectoTexturaBotonOn
#end  //  #ifndef ( CGCF_TexturaBotonOn )

#declare CGCF_DefectoTexturaBotones     =
  texture                               {
    pigment             { Orange }
  }

#ifndef ( CGCF_TexturaBotones )
  #declare CGCF_TexturaBotones  = CGCF_DefectoTexturaBotones
#end  //  #ifndef ( CGCF_TexturaBotones )

#declare CGCF_DefectoTexturaLedOn     =
  texture                               {
    pigment          { Red }
    finish           { ambient 0.9 diffuse 0.1 }
  }

#ifndef ( CGCF_TexturaLedOn )
  #declare CGCF_TexturaLedOn  = CGCF_DefectoTexturaLedOn
#end  //  #ifndef ( CGCF_TexturaLedOn )
                      
#declare CGCF_DefectoTexturaLedOff     =
  texture                               {
    pigment          { Red transmit 0.5 }
  }

#ifndef ( CGCF_TexturaLedOff )
  #declare CGCF_TexturaLedOff  = CGCF_DefectoTexturaLedOff
#end  //  #ifndef ( CGCF_TexturaLedOff )

#declare CGCF_TotalTexturas                     = 8;
#declare CGCF_IndiceTexturaPrincipal            = 0;
#declare CGCF_IndiceTexturaBandaDecorativa      = 1;
#declare CGCF_IndiceTexturaMetalica             = 2;
#declare CGCF_IndiceTexturaBaseBotones          = 3;
#declare CGCF_IndiceTexturaBotonOn              = 4;
#declare CGCF_IndiceTexturaBotones              = 5;
#declare CGCF_IndiceTexturaLedOn                = 6;
#declare CGCF_IndiceTexturaLedOff               = 7;
#declare CGCF_DefectoArregloTexturas            = array [ CGCF_TotalTexturas ]
      { CGCF_DefectoTexturaPrincipal, CGCF_DefectoTexturaBandaDecorativa,
        CGCF_DefectoTexturaMetalica, CGCF_DefectoTexturaBaseBotones, 
        CGCF_DefectoTexturaBotonOn, CGCF_DefectoTexturaBotones,
        CGCF_DefectoTexturaLedOn, CGCF_DefectoTexturaLedOff }
             
             
#macro CGCF_ClassicGameConsoleFull( BotonEncendido,
                FrenteFundamental, ProfundidadFundamental,
                ProfundidadBaseBotones, AltoFundamental,
                LineasDecorativas, Cizalla, FraccionCuerpo,
                FraccionBase, FraccionPatillas, 
                FrenteConector, AltoConector, 
                ArregloBotones, ArregloTexturas )
  union                                 {
    #local TexturaPrincipal         = ArregloTexturas[ CGCF_IndiceTexturaPrincipal ]
    #local TexturaBandaDecorativa   = ArregloTexturas[ CGCF_IndiceTexturaBandaDecorativa ]
    #local TexturaMetalica          = ArregloTexturas[ CGCF_IndiceTexturaMetalica ]
    #local TexturaBaseBotones       = ArregloTexturas[ CGCF_IndiceTexturaBaseBotones ]
    #local TexturaBotonOn           = ArregloTexturas[ CGCF_IndiceTexturaBotonOn ]
    #local TexturaBotones           = ArregloTexturas[ CGCF_IndiceTexturaBotones ]
    #local TexturaLedOn             = ArregloTexturas[ CGCF_IndiceTexturaLedOn ]
    #local TexturaLedOff            = ArregloTexturas[ CGCF_IndiceTexturaLedOff ]
    
    #local AlturaH                  =
            AltoFundamental*( FraccionCuerpo-FraccionBase );
    #local CuerpoBasico                 =
      difference                          {
        union                             {
          superellipsoid                      {
            <0.2,0.2>
            scale             < FrenteFundamental/2-2*Cizalla*AlturaH, AlturaH,
                              ProfundidadFundamental/2-Cizalla*AlturaH >
          }
          superellipsoid                      {
            <0.1,0.1>
            scale             < 0.75*FrenteFundamental/2,
                              AltoFundamental*( FraccionCuerpo-FraccionPatillas ),
                                0.8*ProfundidadFundamental/2 >
          }
          difference                          {
            superellipsoid                      {
              <0.1,0.1>
              scale             < 0.55*FrenteFundamental/2,
                                AltoFundamental*( FraccionCuerpo-FraccionPatillas ),
                                  ProfundidadFundamental/2-Cizalla*AlturaH >
            }
            plane                         {
              -z, 0
            }
          }
        }
        plane                             {
          -y, 0
        }
      }

    #local CuerpoBasicoCizallaFrontal   =
      union                               {
        object                            {
          CuerpoBasico
          matrix             < 1, 0, 0,
                               -Cizalla, 1, 0,
                               0, 0, 1,
                               0, 0, 0 >
  
          translate       -1.3*Cizalla*AlturaH*x
        }
        object                            {
          CuerpoBasico
          matrix             < 1, 0, 0,
                               Cizalla, 1, 0,
                               0, 0, 1,
                               0, 0, 0 >
  
          translate       +1.3*Cizalla*AlturaH*x
        }
      }

    #local CuerpoBasicoCizallado        =
      union                               {
        object                            {
          CuerpoBasicoCizallaFrontal
            matrix             < 1, 0, 0,
                                 0, 1, Cizalla/2,
                                 0, 0, 1,
                                 0, 0, 0 >
        }
        object                            {
          CuerpoBasicoCizallaFrontal
            matrix             < 1, 0, 0,
                                 0, 1, -Cizalla/2,
                                 0, 0, 1,
                                 0, 0, 0 >
        }
      }

    // Cascaron Principal   
    #if ( !CGCF_SimplificarModelo )
        union                               {
          difference                          {
            object                            {
              CuerpoBasicoCizallado
            }
            object                            {
              CuerpoBasicoCizallado
              scale  0.975
              translate   +0.01*AltoFundamental*y
            }
            object                            {
              CuerpoBasicoCizallado
              scale  0.90
              translate               -0.11*ProfundidadFundamental*z
                                      +0.01*AltoFundamental*y
            }
          }
          // Patillas
          #local LadoPatilla                =
                    min( 0.025*ProfundidadFundamental,
                         0.025*FrenteFundamental );
          #local C                          = 0;
          #while ( C < 4 )
            union                           {
              box                           {
                < -1, 0.125, -1 >
                < +0, 1, +0 >
              }
              cylinder                      {
                0, y
                1
              }
              scale                 < LadoPatilla,
                            1.01*FraccionPatillas*AltoFundamental, LadoPatilla >
              translate             -AltoFundamental*FraccionCuerpo*y
              translate             +0.33*ProfundidadFundamental*z+
                                    +0.33*FrenteFundamental*x
              #if ( mod( C, 2 ) = 0 )
                scale               <-1,1,1>
              #end
              #if ( div( C, 2 ) = 0 )
                scale               <1,1,-1>
              #end          
            }
            #local C                        = C+1;
          #end  //  #while ( C < 4 )
          // END Patillas
        }
    #end  //  #if ( CGCF_SimplificarModelo )
    //  END Cascaron Principal
    // Cuerpo
    union                               {
      difference                        {
        object                          {
          CuerpoBasicoCizallado
          scale <0.95,0.95,0.925 >
        }
        box                             {
          < -FrenteFundamental, CGCF_L, -0.35*ProfundidadFundamental >,
          < +FrenteFundamental, -0.05*AlturaH, ProfundidadFundamental >
        }
        box                             {
          < -FrenteFundamental, CGCF_L, -0.34*ProfundidadFundamental >,
          < +FrenteFundamental, -CGCF_L, -ProfundidadFundamental >
          texture               { TexturaBandaDecorativa }
        }
        #local DistanciaTotalLineas     =
                        0.45*ProfundidadFundamental
                        -ProfundidadBaseBotones
                        +0.35*ProfundidadFundamental;
        #local DistanciaC               =
                        DistanciaTotalLineas/
                                ( 3*LineasDecorativas-2 );
        #local C                        = 0;
        #while ( C < LineasDecorativas )
          box                           {
            < -FrenteFundamental, CGCF_L, 0 >,
            < +FrenteFundamental, -0.15*AlturaH, +DistanciaC >
            translate           -0.35*ProfundidadFundamental*z
            translate           ( 3*C+1 )*DistanciaC*z
          }
          #local C                      = C+1;
        #end
        //  Entrada Joystick
        #local C                        = 0;
        #while ( C < 2 )    
          difference                    {
            prism                         {
              0.85*ProfundidadFundamental/2, 0.51*ProfundidadFundamental,
              5,
              < -0.5, 0.5 >,
              < +0.5, 0.5 >,
              <  0.6, -0.5 >,
              < -0.6, -0.5 >,
              < -0.5, 0.5 >                
            }
            #local D                    = 0;
            #while ( D < 9 )
              cylinder                {
                0, 0.52*ProfundidadFundamental*y, 0.05
                #if ( D < 4 )                
                  translate        ( -0.3+0.2*D )*x+0.25*z
                #else  //  #else ( D < 4 )
                  translate        ( -1.2+0.2*D )*x-0.25*z 
                #end   //  #else ( D < 4 )  
                texture         { TexturaMetalica }
              }
              #local D                  = D+1;
            #end
            rotate              -90*x
            scale       < FrenteConector, AltoConector, 1 >
            translate           -0.75*AlturaH*y           
            translate           -0.2*FrenteFundamental*x
            #if ( C = 1 )
              scale         <-1,1,1>
            #end  //  #if ( C = 1 )
          }
          #local C                      = C+1;
        #end  //  #while ( C < 2 )
        //  END Entrada Joystick                        
      }
      //  Base Botones
      union                             {
        difference                        {
          union                           {
            #local CizallaBB              = 0.75;
            difference                    {
                superellipsoid                {
                  <0.1,0.5>
                  scale   < 0.4*FrenteFundamental,
                      ( 1-FraccionCuerpo )*AltoFundamental, ProfundidadBaseBotones/2 >
                  matrix                <  1, 0, 0,
                                           CizallaBB, 1, 0,
                                           0, 0, 1, 0, 0, 0 >
                  translate     -0.07*FrenteFundamental*x
                }
                plane                       {
                  -x, 0
                }
            } 
            difference                      {
                superellipsoid                {
                  <0.1,0.5>
                  scale   < 0.4*FrenteFundamental,
                      ( 1-FraccionCuerpo )*AltoFundamental, ProfundidadBaseBotones/2 >
                  matrix                <  1, 0, 0,
                                           -CizallaBB, 1, 0,
                                           0, 0, 1, 0, 0, 0 >
                  translate     +0.07*FrenteFundamental*x
                }  
                plane                       {
                  +x, 0
                }
            }
          }
          plane                           {
            z, 0
            rotate        60*x
            translate             -ProfundidadBaseBotones/2*z
          }
          plane                           {
            -z, 0
            rotate        -30*x
            translate             +ProfundidadBaseBotones/2*z
          }
          plane                           {
            y, -CGCF_L
          }
        }
        #local Alto60                   =
                AltoFundamental*( 1-FraccionCuerpo )/cos( pi/3 );
        #local RecorridoBotones         =
                        0.80*FrenteFundamental-0.90*Alto60;
        union                           {
          difference                      {
            union                         {
              cylinder                    {
                -0.15*AlturaH*z, 0.15*AlturaH*z,
                0.45*Alto60
                translate +RecorridoBotones*x/2
              }
              box                         {
                < +( 0.40*FrenteFundamental-0.45*Alto60 ),
                  -0.45*Alto60, -0.15*AlturaH >,
                < -( 0.40*FrenteFundamental-0.45*Alto60 ),
                  +0.45*Alto60, +0.15*AlturaH >
              }
              cylinder                    {
                -0.15*AlturaH*z, 0.15*AlturaH*z,
                0.45*Alto60
                translate -( 0.40*FrenteFundamental-0.45*Alto60 )*x
              }
            }  
            #if ( CGCF_FraccionXIndicador >= 0 ) 
                cylinder                      {
                  -0.001*AlturaH*z, -AlturaH*z, Alto60*0.05
                  translate               -RecorridoBotones/2*x
                  translate       CGCF_FraccionXIndicador*RecorridoBotones*x
                  #if ( BotonEncendido ) 
                    texture                 { TexturaLedOn }
                  #else  //  #else ( BotonEncendido )
                    texture                 { TexturaLedOff }
                  #end   //  #else ( BotonEncendido )
                }
            #end  //  #if ( CGCF_FraccionIndicaro >= 0 )
            union                         {
              cylinder                    {
                -0.01*AlturaH*z, -AlturaH*z,
                0.45*Alto60-DistanciaC
                translate +( 0.40*FrenteFundamental-0.45*Alto60 )*x
              }
              box                         {
                < +( 0.40*FrenteFundamental-0.45*Alto60 ),
                  -0.45*Alto60+DistanciaC, -0.01*AlturaH >,
                < -( 0.40*FrenteFundamental-0.45*Alto60 ),
                  +0.45*Alto60-DistanciaC, -AlturaH >
              }
              cylinder                    {
                -0.01*AlturaH*z, -AlturaH*z,
                0.45*Alto60-DistanciaC
                translate -( 0.40*FrenteFundamental-0.45*Alto60 )*x
              }
              texture             {
                TexturaBaseBotones
              }
            }
          }
          //  Botones
          union                         {
            #local TotalBotones           = dimension_size( ArregloBotones, 1 );
            #local RadioBoton             = 0.30*Alto60-DistanciaC;
            #local AltoBoton              = 0.15*AlturaH;
            #local C                      = 0;
            #while ( C < TotalBotones ) 
              #if ( ArregloBotones[C][0] >= 0 )
                  union                     {
                    cylinder                    {
                      0, -0.8*AltoBoton*z,
                      RadioBoton
                    }
                    sphere                          {
                      0, RadioBoton
                      scale <1,1,0.2*AltoBoton/RadioBoton>
                      translate     -0.8*AltoBoton*z
                    }
                    #if ( C = 0 )
                      #if ( BotonEncendido )
                        translate     +0.8*AltoBoton*z
                      #end  //  #if ( BotonEncendido )
                    #else  //  #else ( C = 0 )
                      #if ( ArregloBotones[ C ][1] )
                        translate     +0.8*AltoBoton*z
                      #end  //  #if ( ArregloBotones[ C ][1] )
                    #end   //  #else ( C = 0 )
                    translate               -RecorridoBotones/2*x
                    translate       ArregloBotones[ C ][0]*RecorridoBotones*x                  
                    translate               -0.05*Alto60*y
                    #if ( C = 0 )
                      texture               {
                        TexturaBotonOn
                      }
                    #else  //  #else ( C = 0 )
                      texture                 {
                        TexturaBotones
                      }
                    #end   //  #else ( C = 0 )
                  }               
              #end  //  #if ( ArregloBotones[ C ][0] >= 0 )    
              #local C                    = C+1;
            #end  //  #while ( C < TotalBotones )  
            #if ( CGCF_FraccionXLogo >= 0 )
                object                      {    
                  #ifdef ( CGCF_LogoCustom )
                    CGCF_LogoCustom
                  #else  //  #else ( ...Logo )
                    CGCF_Logo
                  #end   //  #else ( ...Logo )
                  scale   0.4*Alto60
                  translate               -RecorridoBotones/2*x
                  translate       CGCF_FraccionXLogo*RecorridoBotones*x
                  texture           { TexturaBandaDecorativa }
                }
            #end  //  #if ( CGCF_FraccionXLogo )
          }
          //  END Botones
          translate                     Alto60*y/2
          rotate                        60*x
          translate             -ProfundidadBaseBotones/2*z
        }
        translate       -ProfundidadBaseBotones/2*z
                        +0.45*ProfundidadFundamental*z
      }
      //  END Base Botones
    }
    // END Cuerpo
    translate           AltoFundamental*FraccionCuerpo*y
    texture                             {
      TexturaPrincipal
    }
  }
#end  //  #macro CGCF_ClassicGameConsoleFull()

#macro CGCF_Game( BotonEncendido )
  object                                {
    #local L                            = CGCF_L;
    #local FrenteFundamental            = 162*L;   
    #local ProfundidadFundamental       = 105*L;
    #local ProfundidadBaseBotones       =  45*L;
    #local AltoFundamental              =  40*L;
    #local LineasDecorativas            = 10;
    #local Cizalla                      = 0.17;
    #local FraccionCuerpo               = 0.73;
    #local FraccionBase                 = 0.30;
    #local FraccionPatillas             = 0.045;
    #local FrenteConector               = 8*L;
    #local AltoConector                 = 3.5*L; 
    #local ArregloTexturas              = array [ CGCF_TotalTexturas ]
    #local ArregloTexturas[ CGCF_IndiceTexturaPrincipal ]           =
                                CGCF_TexturaPrincipal
    #local ArregloTexturas[ CGCF_IndiceTexturaBandaDecorativa ]     =
                                CGCF_TexturaBandaDecorativa
    #local ArregloTexturas[ CGCF_IndiceTexturaMetalica ]            =
                                CGCF_TexturaMetalica
    #local ArregloTexturas[ CGCF_IndiceTexturaBaseBotones ]         =
                                CGCF_TexturaBaseBotones
    #local ArregloTexturas[ CGCF_IndiceTexturaBotonOn ]             =
                                CGCF_TexturaBotonOn
    #local ArregloTexturas[ CGCF_IndiceTexturaBotones ]             =
                                CGCF_TexturaBotones
    #local ArregloTexturas[ CGCF_IndiceTexturaLedOn ]               =
                                CGCF_TexturaLedOn
    #local ArregloTexturas[ CGCF_IndiceTexturaLedOff ]              =
                                CGCF_TexturaLedOff
    CGCF_ClassicGameConsoleFull( BotonEncendido,    
      FrenteFundamental, ProfundidadFundamental,
      ProfundidadBaseBotones, AltoFundamental,
      LineasDecorativas, Cizalla, FraccionCuerpo,
      FraccionBase, FraccionPatillas, 
      FrenteConector, AltoConector, CGCF_ArregloBotones,
      ArregloTexturas )
  }
#end  //  #macro CGCF_Game()
