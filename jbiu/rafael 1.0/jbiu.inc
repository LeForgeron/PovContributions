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
#include "colors.inc"

#declare JBIU_L                         = 0.001;

#if ( version < 3.2 )
  #ifndef( JBIU_POV3_1 )
    #declare JBIU_POV3_1        = on;
  #end
#else
  #ifndef( JBIU_POV3_1 )
    #declare JBIU_POV3_1        = off;
  #end
#end

#if ( JBIU_POV3_1 )
  // Copia textual de Povray_Logo en logo.inc
  // incluido aqui por compatibilidad con POV_RAY 3.1
  #declare JBIU_Logo                      =
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
#else  // #else ( JBIU_POV3_1 )
  #include "logo.inc"
  #declare JBIU_Logo = Povray_Logo
#end   // #else ( JBIU_POV3_1 )

#declare JBIU_DefectoTexturaPrincipal   =
  texture                               {
    pigment                             {
      Gray20
    }
  }

#ifndef ( JBIU_TexturaPrincipal )
  #declare JBIU_TexturaPrincipal        = JBIU_DefectoTexturaPrincipal
#end  //  #ifndef ( JBIU_TexturaPrincipal )

#declare JBIU_DefectoTexturaAmortiguado   =
  texture                               {
    pigment                             {
      Gray20
    }
    finish                              {
      metallic
      phong  0.4
      phong_size 20
    }
  }

#ifndef ( JBIU_TexturaAmortiguado )
  #declare JBIU_TexturaAmortiguado        = JBIU_DefectoTexturaAmortiguado
#end  //  #ifndef ( JBIU_TexturaAmortiguado )

#declare JBIU_DefectoTexturaBoton   =
  texture                               {
    pigment                             {
      Red
    }
    finish                              {
      metallic
      phong 0.5
      phong_size 20
    }
  }

#ifndef ( JBIU_TexturaBoton )
  #declare JBIU_TexturaBoton        = JBIU_DefectoTexturaBoton
#end  //  #ifndef ( JBIU_TexturaBoton )

#declare JBIU_DefectoTexturaPlastica   =
  texture                               {
    pigment                             {
      Gray10
    }
    finish                              {
      metallic
      phong 0.8
      phong_size 20
    }
  }

#ifndef ( JBIU_TexturaPlastica )
  #declare JBIU_TexturaPlastica        = JBIU_DefectoTexturaPlastica
#end  //  #ifndef ( JBIU_TexturaPlastica )

#declare JBIU_DefectoTexturaLogo    =
  texture                               {
    pigment                             {
      color ( Orange+Black )/2
    }
    finish                              {
      metallic
      phong 0.5
      phong_size 20
    }
  }

#ifndef ( JBIU_TexturaLogo )
  #declare JBIU_TexturaLogo        = JBIU_DefectoTexturaLogo
#end  //  #ifndef ( JBIU_TexturaLogo )

#declare JBIU_TotalTexturas             = 5;
#declare JBIU_IndiceTexturaPrincipal    = 0;
#declare JBIU_IndiceTexturaAmortiguado  = 1;
#declare JBIU_IndiceTexturaBoton        = 2;
#declare JBIU_IndiceTexturaPlastica     = 3;
#declare JBIU_IndiceTexturaLogo         = 4;
#declare JBIU_DefectoArregloTexturas    = array [ JBIU_TotalTexturas ]
       { JBIU_DefectoTexturaPrincipal, JBIU_DefectoTexturaAmortiguado,
         JBIU_DefectoTexturaBoton, JBIU_DefectoTexturaPlastica,
         JBIU_DefectoTexturaLogo }


#macro JBIU_BezierBase( LadoJoystick, ExtraLateral, FB, FH,
                AltoBezier, RadioDecorativo )
  object                                {
    #local P0                           =
        < -LadoJoystick/2, +LadoJoystick/2+ExtraLateral >;
    #local P1                           =
        < +LadoJoystick/2, +LadoJoystick/2+ExtraLateral >;
    #local P2                           =
        < +LadoJoystick/2, -LadoJoystick/2 >;
    #local P3                           =
        < -LadoJoystick/2, -LadoJoystick/2 >;
    prism                                 {
      conic_sweep
      bezier_spline
      FB, FH,
      32,
      P0-RadioDecorativo*v, P0, P0, P0+RadioDecorativo*u,
      P0+RadioDecorativo*u, ( P0+P1 )/2, ( P0+P1 )/2, P1-RadioDecorativo*u,
      P1-RadioDecorativo*u, P1, P1, P1-RadioDecorativo*v,
      P1-RadioDecorativo*v, ( P1+P2 )/2, ( P1+P2 )/2, P2+RadioDecorativo*v,
      P2+RadioDecorativo*v, P2, P2, P2-RadioDecorativo*u,
      P2-RadioDecorativo*u, ( P2+P3 )/2, ( P2+P3 )/2, P3+RadioDecorativo*u,
      P3+RadioDecorativo*u, P3, P3, P3+RadioDecorativo*v,
      P3+RadioDecorativo*v, ( P0+P3 )/2, ( P0+P3 )/2, P0-RadioDecorativo*v
      translate         -FB*y
      scale             < 1, AltoBezier/( FH-FB ), 1 >
    }
  }
#end  //  #macro JBIU_BezierBase

#macro JBIU_JoystickButtonInteractiveUser
                ( ApretarBoton, GiroJoystick,
                  AnguloJoystick, FraccionEmpujar,
                  LadoJoystick, ExtraLateral, AltoBase,
                  RadioDecorativo, FraccionAltoEngorde,
                  ContraccionAltura, AltoPalanca, MaximoAngulo,
                  DiametroPalanca, AltoAmortiguado,
                  DiametroBoton, ArregloTexturas )
  union                                 {
    #local TexturaPrincipal             =
                ArregloTexturas[ JBIU_IndiceTexturaPrincipal ]
    #local TexturaAmortiguado           =
                ArregloTexturas[ JBIU_IndiceTexturaAmortiguado ]
    #local TexturaBoton                 =
                ArregloTexturas[ JBIU_IndiceTexturaBoton ]
    #local TexturaPlastica              =
                ArregloTexturas[ JBIU_IndiceTexturaPlastica ]
    #local TexturaLogo                  =
                ArregloTexturas[ JBIU_IndiceTexturaLogo ]
    #local LevantePatillas              = 0.04*AltoBase;
    #local DiametroAmortiguado          = 0.56*LadoJoystick;
    #local AltoRanura                   = 0.01*AltoBase;
    #local DiametroPatillas             = 0.11*LadoJoystick;
    #local NivelGiro                    = 0.75*AltoBase;
    #local AltoBoton                    = AltoAmortiguado/4;
    #local PosXBoton                    = -LadoJoystick/3;
    #local PosZBoton                    = -PosXBoton;
    #local DiametroGuia                 =
        0.4*DiametroAmortiguado+0.6*( 1-ContraccionAltura )*LadoJoystick;
    //  Base
    union                               {
      //  Cuerpo Base
      difference                        {
        union                           {
          object                        {
            JBIU_BezierBase( LadoJoystick, ExtraLateral, 1-ContraccionAltura, 1.0,
                FraccionAltoEngorde*AltoBase-LevantePatillas,
                RadioDecorativo )
            translate           LevantePatillas*y
          }
          object                        {
            JBIU_BezierBase( LadoJoystick, ExtraLateral, 1-ContraccionAltura/3, 1.0,
                2/3*( FraccionAltoEngorde*AltoBase-LevantePatillas ),
                RadioDecorativo )
            translate   1/3*FraccionAltoEngorde*AltoBase*y
                                +2/3*LevantePatillas*y
          }
          box                           {
            < -LadoJoystick/2+RadioDecorativo, 0,
              -LadoJoystick/2+RadioDecorativo >,
            < +LadoJoystick/2-RadioDecorativo, AltoRanura,
              +LadoJoystick/2+ExtraLateral-RadioDecorativo >
            translate   FraccionAltoEngorde*AltoBase*y
          }      
          union                         {
            #local LJoystick        = LadoJoystick/2-RadioDecorativo;
            cylinder                      {
              0, AltoRanura*y, 0.9*RadioDecorativo
              translate       -LJoystick*x-LJoystick*z
            }
            cylinder                      {
              0, AltoRanura*y, 0.9*RadioDecorativo
              translate       -LJoystick*x+LJoystick*z+ExtraLateral*z
            }
            cylinder                      {
              0, AltoRanura*y, 0.9*RadioDecorativo
              translate       +LJoystick*x-LJoystick*z
            }
            cylinder                      {
              0, AltoRanura*y, 0.9*RadioDecorativo
              translate       +LJoystick*x+LJoystick*z+ExtraLateral*z
            }
            translate   FraccionAltoEngorde*AltoBase*y
          }
          object                        {
            JBIU_BezierBase( LadoJoystick, ExtraLateral, 1.0, 1-ContraccionAltura/4,
                3/4*( ( 1-FraccionAltoEngorde )*AltoBase-AltoRanura ),
                RadioDecorativo )
            translate   ( FraccionAltoEngorde*AltoBase+AltoRanura )*y
          }
          object                        {
            JBIU_BezierBase( LadoJoystick, ExtraLateral,
                1-ContraccionAltura, 1-ContraccionAltura/4,
                1/4*( ( 1-FraccionAltoEngorde )*AltoBase-AltoRanura ),
                RadioDecorativo )
            scale  <1,-1,1>
            translate   AltoBase*y
          }
          difference                    {
            union                         {
              cylinder                    {
                -AltoBase*FraccionAltoEngorde*y, AltoBoton/5*y, 1.25*DiametroBoton/2
              }
              box                          {
                <0, -AltoBase*FraccionAltoEngorde, -1.25*DiametroBoton/2 >,
                <LadoJoystick/2, AltoBoton/5, +1.25*DiametroBoton/2 >
              }
              rotate    45*y
              texture             { TexturaPlastica }
              translate    PosXBoton*x+PosZBoton*z
            }
            cylinder            {
              -AltoBase*y, AltoBoton*y, DiametroGuia/2
            }
            translate           AltoBase*y
          }
          difference                    {
            cylinder                    {
              0, AltoBoton*y/5, DiametroGuia/2
              texture           { TexturaPlastica }
            }
            cylinder                    {
              -AltoBoton*y, AltoBoton*y, ( DiametroGuia+DiametroAmortiguado )/4
            }
            translate           AltoBase*y
          }
          //  Marcas Decorativas
          union                         {
            #local ReferenciaDec        = 36;
            #local ReferenciaQ          = ReferenciaDec/4;
            #local AnguloDec            = 360/( 2*ReferenciaDec );
            #local ArcoDec              =
              difference                {
                cylinder                {
                  0, 2*AltoBoton/5*y, ( 5*DiametroGuia+DiametroAmortiguado )/12
                }
                cylinder                {
                  -AltoBoton*y, AltoBoton*y, ( 4*DiametroGuia+2*DiametroAmortiguado )/12
                }
                plane                   {
                  -z, 0
                }
                plane                   {
                  z, 0
                  rotate                AnguloDec*y
                }
              }
            #local ArcoDobleDec              =
              difference                {
                cylinder                {
                  0, 2*AltoBoton/5*y, ( 6*DiametroGuia+0*DiametroAmortiguado )/12
                }
                cylinder                {
                  -AltoBoton*y, AltoBoton*y, ( 3*DiametroGuia+3*DiametroAmortiguado )/12
                }
                plane                   {
                  -z, 0
                  rotate                AnguloDec/3*y
                }
                plane                   {
                  z, 0
                  rotate                2/3*AnguloDec*y
                }
              }
            #local C                    = 0;
            #while ( C < ReferenciaDec )
              #if ( ( mod( C, ReferenciaQ ) = 0 ) | ( mod( C+1, ReferenciaQ ) = 0 ) )
                object                    {
                  ArcoDobleDec
                  rotate          ( AnguloDec/2+2*C*AnguloDec )*y
                }
              #else
                object                    {
                  ArcoDec
                  rotate          ( AnguloDec/2+2*C*AnguloDec )*y
                }
              #end
              #local C                  = C+1;
            #end  //  #while ( C < ReferenciaDec )
            texture                             {
              TexturaLogo
            }
            translate           AltoBase*y
          }
          //  END Marcas Decorativas
        }
        cylinder                        {
          NivelGiro*y, 1.1*AltoBase*y, DiametroAmortiguado/2
        }
        cylinder                        {
          NivelGiro*y, 1.1*AltoBase*y, 1.1*DiametroBoton/2
          translate     PosXBoton*x+PosZBoton*z
        }
      }
      //  END Cuerpo Base
      //  Joystick
      union                             {
        //  Palito
        union                           {
          #local FCPal                  = 0.9;
          #local FFPal                  = 0.03;
          prism                         {
            0, ( 1-FFPal )*AltoPalanca
            9
            #local C                    = 0;
            #while ( C < 9 )
              DiametroPalanca*< cos( C*pi/4 ), sin( C*pi/4 ) >/2
              #local C                  = C+1;
            #end
          }
          prism                         {
            conic_sweep
            FCPal, 1
            9
            #local C                    = 0;
            #while ( C < 9 )
              DiametroPalanca*< cos( C*pi/4 ), sin( C*pi/4 ) >/2
              #local C                  = C+1;
            #end
            translate           -y
            scale               <1,-FFPal*AltoPalanca/( 1-FCPal ),1>
            translate           ( 1-FFPal )*AltoPalanca*y
          }
          cylinder                      {
            0, AltoAmortiguado*y,
            ( 9*DiametroPalanca+1*DiametroAmortiguado )/20
          }
          cylinder                      {
            0, 0.7*AltoAmortiguado*y,
            ( 2*DiametroPalanca+1*DiametroAmortiguado )/6
          }
          translate                     -( NivelGiro-AltoBase )*y
          rotate                        GiroJoystick*y
          rotate                        -FraccionEmpujar*MaximoAngulo*z
          rotate                        AnguloJoystick*y
          translate                     -( AltoBase-NivelGiro )*y
        }
        //  END Palito
        //  Amortiguado
        union                           {
          #local InicioAmortiguado      =
                        ( 2*DiametroPalanca+1*DiametroAmortiguado )/6;
          #local AnchoAmortiguado       = ( DiametroAmortiguado-DiametroPalanca )/3;
          #local SeccionTorus           = AnchoAmortiguado/3;
          union                         {
            cylinder                    {
              0, ( 0.7*AltoAmortiguado-SeccionTorus/2 )*y,
              InicioAmortiguado+SeccionTorus
            }
            torus                       {
              InicioAmortiguado+SeccionTorus/2, SeccionTorus/2
              translate ( 0.7*AltoAmortiguado-SeccionTorus/2 )*y
            }
            translate                     -( NivelGiro-AltoBase )*y
            rotate                        -0.75*FraccionEmpujar*MaximoAngulo*z
            rotate                        AnguloJoystick*y
            translate                     -( AltoBase-NivelGiro )*y
          }
          union                         {
            cylinder                    {
              0, ( 2/3*0.7*AltoAmortiguado-SeccionTorus/2 )*y,
              InicioAmortiguado+2*SeccionTorus
            }
            torus                       {
              InicioAmortiguado+3*SeccionTorus/2, SeccionTorus/2
              translate ( 2/3*0.7*AltoAmortiguado-SeccionTorus/2 )*y
            }
            translate                     -( NivelGiro-AltoBase )*y
            rotate                        -0.5*FraccionEmpujar*MaximoAngulo*z
            rotate                        AnguloJoystick*y
            translate                     -( AltoBase-NivelGiro )*y
          }
          union                         {
            cylinder                    {
              0, ( 1/3*0.7*AltoAmortiguado-SeccionTorus/2 )*y,
              InicioAmortiguado+3*SeccionTorus
            }
            torus                       {
              InicioAmortiguado+5*SeccionTorus/2, SeccionTorus/2
              translate ( 1/3*0.7*AltoAmortiguado-SeccionTorus/2 )*y
            }
            translate                     -( NivelGiro-AltoBase )*y
            rotate                        -0.25*FraccionEmpujar*MaximoAngulo*z
            rotate                        AnguloJoystick*y
            translate                     -( AltoBase-NivelGiro )*y
          }
          texture                       {
            TexturaAmortiguado
          }
        }
        //  END Amortiguado
        translate                       AltoBase*y
      }
      //  END Joystick
      //  Boton
      difference                             {
        superellipsoid                  {
          <0.1,1>
          scale  < DiametroBoton/2, AltoBoton, DiametroBoton/2 >
        }
        sphere                          {
          0, 1
          scale  < DiametroBoton/2, AltoBoton/5, DiametroBoton/2 >
          translate     AltoBoton*y
        }
        #if ( ApretarBoton )
          translate             -4*AltoBoton*y/5
        #end  //  #if  ( ApretarBoton )
        translate               AltoBase*y
                                +PosXBoton*x+PosZBoton*z
        texture                         {
          TexturaBoton
        }
      }
      //  END Boton
      //  Logo
      object                            {
        #ifdef ( JBIU_LogoCustom )
          JBIU_LogoCustom
        #else  //  #else ( JBIU_LogoCustom )
          JBIU_Logo
        #end   //  #else ( JBIU_LogoCustom )
        rotate          90*x
        scale           < 0.1*LadoJoystick, AltoBoton, 0.1*LadoJoystick >
        texture         { TexturaLogo }
        translate               AltoBase*y
        translate               -PosXBoton*x+( PosZBoton+0.65*ExtraLateral )*z
      }
      //  END Logo
      //  Patillas
      union                             {
        #local TrX                      = 0.62*LadoJoystick;
        #local TrZ                      = 0.70*( LadoJoystick+ExtraLateral );
        cylinder                        {
          0, 0.5*AltoBase*y
          DiametroPatillas/2
          translate             +TrX/2*x+TrZ/2*z
        }
        cylinder                        {
          0, 0.5*AltoBase*y
          DiametroPatillas/2
          translate             +TrX/2*x-TrZ/2*z
        }
        cylinder                        {
          0, 0.5*AltoBase*y
          DiametroPatillas/2
          translate             -TrX/2*x+TrZ/2*z
        }
        cylinder                        {
          0, 0.5*AltoBase*y
          DiametroPatillas/2
          translate             -TrX/2*x-TrZ/2*z
        }
        translate               ExtraLateral/2*z
      }
      //  END Patillas
    }
    //  END Base
    texture                             {
      TexturaPrincipal
    }
  }
#end  //  #macro JBIU_JoystickButtonInteractiveUser

#macro JBIU_Joystick( ApretarBoton, GiroJoystick,
                        AnguloJoystick, FraccionEmpujar )
  object                                {
    #local L                            = JBIU_L;
    #local LadoJoystick                 = 61*L;
    #local ExtraLateral                 =  5*L;
    #local AltoBase                     = 26*L;
    #local RadioDecorativo              =  5*L;
    #local FraccionAltoEngorde          = 0.75;
    #local ContraccionAltura            = 0.10;
    #local AltoPalanca                  = 52*L;
    #local MaximoAngulo                 = 14;
    #local DiametroPalanca              = 11*L;
    #local AltoAmortiguado              =  6*L;
    #local DiametroBoton                = 10*L;
    #local ArregloTexturas              = array [ JBIU_TotalTexturas ]
    #local ArregloTexturas[ JBIU_IndiceTexturaPrincipal ]           =
                                JBIU_TexturaPrincipal
    #local ArregloTexturas[ JBIU_IndiceTexturaAmortiguado ]         =
                                JBIU_TexturaAmortiguado
    #local ArregloTexturas[ JBIU_IndiceTexturaBoton ]               =
                                JBIU_TexturaBoton
    #local ArregloTexturas[ JBIU_IndiceTexturaPlastica ]            =
                                JBIU_TexturaPlastica
    #local ArregloTexturas[ JBIU_IndiceTexturaLogo ]                =
                                JBIU_TexturaLogo
    JBIU_JoystickButtonInteractiveUser
                ( ApretarBoton, GiroJoystick,
                  AnguloJoystick, FraccionEmpujar,
                  LadoJoystick, ExtraLateral, AltoBase,
                  RadioDecorativo, FraccionAltoEngorde,
                  ContraccionAltura, AltoPalanca, MaximoAngulo,
                  DiametroPalanca, AltoAmortiguado, DiametroBoton, ArregloTexturas )
  }
#end  //  JBIU_Joystick
