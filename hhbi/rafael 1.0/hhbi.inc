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
#include "colors.inc"     
#include "metals.inc"
#declare HHBI_L                         = 0.001;
#declare HHBI_BanderaLink               = file_exists( "LINK.inc" );

#if ( version < 3.2 )
  #ifndef( HHBI_POV3_1 )
    #declare HHBI_POV3_1        = on;
  #end
#else
  #ifndef( HHBI_POV3_1 )
    #declare HHBI_POV3_1        = off;
  #end
#end

#if ( HHBI_POV3_1 )
  #declare HHBI_DefectoTexturaPrincipal   =
    texture { pigment { Yellow } }
#else
  #declare HHBI_DefectoTexturaPrincipal   =
    texture                               {
      pigment                             {
        wrinkles
        scale  0.025
        pigment_map                       {
          [ 0.0 color Yellow ] 
          [ 0.5 color ( 3*Yellow+Coral )/4 ]
          [ 0.7 color Yellow ]
          [ 1.0 color Coral ]
        }
      }
      normal                              {
        onion  
        warp { turbulence  1 }
        scale  0.05
      }
    }
#end

#ifndef ( HHBI_TexturaPrincipal )
  #declare HHBI_TexturaPrincipal        = HHBI_DefectoTexturaPrincipal
#end  //  #ifndef ( HHBI_TexturaPrincipal )

#declare HHBI_DefectoTexturaUniones   =
  texture                               {
    HHBI_DefectoTexturaPrincipal
  }

#ifndef ( HHBI_TexturaUniones )
  #declare HHBI_TexturaUniones        = HHBI_DefectoTexturaUniones
#end  //  #ifndef ( HHBI_TexturaUniones )
     
#declare HHBI_DefectoTexturaExtremos   =
  texture                               {
    HHBI_DefectoTexturaPrincipal
  }

#ifndef ( HHBI_TexturaExtremos )
  #declare HHBI_TexturaExtremos         = HHBI_DefectoTexturaExtremos
#end  //  #ifndef ( HHBI_TexturaExtremos )
           
#declare HHBI_DefectoTexturaBase        =
  texture                               {  
    HHBI_DefectoTexturaPrincipal
  }

#ifndef ( HHBI_TexturaBase )
  #declare HHBI_TexturaBase             = HHBI_DefectoTexturaBase
#end  //  #ifndef ( HHBI_TexturaBase )
                      
#declare HHBI_DefectoTexturaCadenas     =
  texture                               {
    T_Chrome_3C
    normal                              {
      bumps
      warp  { turbulence 0.1 }
      scale  0.01
    }
  }
  
#ifndef ( HHBI_TexturaCadenas )
  #declare HHBI_TexturaCadenas          = HHBI_DefectoTexturaCadenas
#end  //  #ifndef ( HHBI_TexturaPrincipal )
              
#macro HHBI_BasePrisma( NumeroLados, DiametroPrisma, AltoPrisma )
  prism                                 {
    0, AltoPrisma,
    #local TotalPuntos                  = NumeroLados+1;
    TotalPuntos,
    #local C                            = 0;
    #while ( C < TotalPuntos )
      DiametroPrisma/2*<cos(2*pi*C/NumeroLados),sin(2*pi*C/NumeroLados)>
      #local C                          = C+1;
    #end  //  #while ( C < TotalPuntos )
  }
#end  //  #macro HHBI_BasePrisma

#macro HHBI_HidranteHumedadBocaIncendio( FraccionSubSuelo,
      AltoHidrante, DiametroHidrante,
      FraccionBase, CizallaBase,
      FraccionIntermedia, FraccionSuperior, ContactoHidrante,
      TexturaPrincipal, TexturaUniones, TexturaExtremos,
      TexturaBase, TexturaCadenas )
  union                                 {
    #local FraccionPrincipal            =
        1.0-FraccionBase-FraccionIntermedia-FraccionSuperior;
    // Base y Subsuelo
    difference                          {
      #local BaseCizalla                =
        union                               {
          superellipsoid                    {
            < 0.2, 0.2 >
            scale           < DiametroHidrante/2, FraccionBase*AltoHidrante,
                              DiametroHidrante/2 >
          }
          superellipsoid                    {
            < 0.2, 0.2 >
            scale           < DiametroHidrante/2, FraccionBase*AltoHidrante,
                              DiametroHidrante/2 >
            matrix        <1,0,0,
                           0,1,CizallaBase,
                           0,0,1,
                           0,0,-CizallaBase*FraccionBase*AltoHidrante>
          }
          superellipsoid                    {
            < 0.2, 0.2 >
            scale           < DiametroHidrante/2, FraccionBase*AltoHidrante,
                              DiametroHidrante/2 >
            matrix        <1,0,0,
                           0,1,-CizallaBase/3,
                           0,0,1,
                           0,0,+CizallaBase*FraccionBase*AltoHidrante/3>
          }
        }
        
      union                             {
        object                          {
          BaseCizalla
        }
        object                          {
          BaseCizalla
          matrix        <1,0,0,
                         -CizallaBase/3,1,0,
                         0,0,1,
                         +CizallaBase*FraccionBase*AltoHidrante/3,0,0>
        }
        object                          {
          BaseCizalla
          matrix        <1,0,0,
                         +CizallaBase/3,1,0,
                         0,0,1,
                         -CizallaBase*FraccionBase*AltoHidrante/3,0,0>
        }
        texture                         {
          TexturaBase
        }
      }
      plane                             {
        y, -FraccionSubSuelo*FraccionBase*AltoHidrante
      }
    }
    // END Base y Subsuelo
    // Fraccion Intermedia
    union                               {
      cylinder                            {
        0, ( 1-FraccionSuperior )*AltoHidrante*y,
        DiametroHidrante/4
        texture                         {
          TexturaUniones
        }
      }
      cylinder                          {
        -FraccionPrincipal*AltoHidrante*y/10*y, 0,
        3*DiametroHidrante/8
        translate       ( FraccionBase+FraccionIntermedia )*AltoHidrante*y 
      }
    }
    // END Fraccion Intermedia
    // Fraccion Final
    union                               {
      sphere                            {
        0, 1
        scale   < 3*DiametroHidrante/8, FraccionSuperior*AltoHidrante/2,
                  3*DiametroHidrante/8 >
      }
      cylinder                          {
        0, 1*FraccionSuperior*AltoHidrante/2*y,
        3*DiametroHidrante/16
      }
      cylinder                          {
        0, 0.875*2*FraccionSuperior*AltoHidrante/3*y,
        0.95*3*DiametroHidrante/16
      }
      object                            {
        HHBI_BasePrisma( 12, 0.95*3*DiametroHidrante/8,
                0.1*2*FraccionSuperior*AltoHidrante/3 )
        translate       0.9*2*FraccionSuperior*AltoHidrante/3*y
      }
      object                            {
        HHBI_BasePrisma( 6, 0.9*3*DiametroHidrante/16,
                FraccionSuperior*AltoHidrante )
        texture                         {
          TexturaExtremos
        }        
      }
      object                            {
        HHBI_BasePrisma( 8, 3*DiametroHidrante/16,
                5*FraccionSuperior*AltoHidrante/6 )
        texture                         {
          TexturaExtremos
        }        
      }
      translate ( 1-FraccionSuperior)*AltoHidrante*y
    }
    // END FraccionFinal
    // Cuerpo Principal
    union                               {
      cylinder                          {
        0, FraccionPrincipal*AltoHidrante*y,
        3*DiametroHidrante/8
      }
      cylinder                          {
        0, 0.90*FraccionPrincipal*AltoHidrante*y/10,
        DiametroHidrante/2
      }
      cylinder                          {
        0, FraccionPrincipal*AltoHidrante*y/10,
        DiametroHidrante/2
        translate       FraccionPrincipal*AltoHidrante*y/10*y
      }
      //  Tornillos de base
      #local C                          = 0;
      #while ( C < 8 )
        object                          {
          HHBI_BasePrisma( 8, 2*DiametroHidrante/24,
                        0.225*FraccionPrincipal*AltoHidrante )
          translate             7/16*DiametroHidrante*x
          rotate                C*45*y      
          texture                       {
            TexturaExtremos
          }
        }
        #local C                        = C+1;
      #end  //  #while ( C < 8 )
      //  END Tornillos de base
      union                             {
        cylinder                          {
          0, -DiametroHidrante/2*z, 3*DiametroHidrante/8
        }
        cylinder                        {
          -DiametroHidrante/2*x, +DiametroHidrante/2*x,
          0.75*3*DiametroHidrante/8
        }
        object                          {
          HHBI_BasePrisma( 6, 3*DiametroHidrante/16,
                        DiametroHidrante+2*ContactoHidrante )
          translate     -( DiametroHidrante/2+ContactoHidrante )*y
          rotate                        90*z   
          texture                       {
            TexturaExtremos
          }
        }
        cylinder                        {
          +( DiametroHidrante/2+ContactoHidrante/3 )*x,
          -( DiametroHidrante/2+ContactoHidrante/3 )*x,
          0.65*3*DiametroHidrante/8
        }
        #local LargoCil                 =
                DiametroHidrante+4*ContactoHidrante/3;

        cylinder                        {
          +( LargoCil/2+ContactoHidrante/12 )*x, -( LargoCil/2+ContactoHidrante/12 )*x,
          0.6*3*DiametroHidrante/16   
          texture   { TexturaUniones }
        }
        #local C                        = 0;
        #local TotalCil                 = 40;
        #local GruesoRanura             = LargoCil/( 2*TotalCil-1 );
        #while ( C < TotalCil )
          cylinder                      {
            0, GruesoRanura*x, 0.9*3*DiametroHidrante/16
            translate           ( -LargoCil/2+2*C*GruesoRanura )*x   
            texture                         {
              TexturaUniones
            }
          }
          #local C                      = C+1;
        #end  // #local TotalRanuras
        // Zona Frontal
        union                           {
          object                          {
            HHBI_BasePrisma( 6, 3*DiametroHidrante/16,
                          DiametroHidrante/2+1.25*ContactoHidrante )
            rotate                        -90*x     
            texture                     {
              TexturaExtremos
            }
          }
          union                         {
            cylinder                    {
              -2*ContactoHidrante/3*z, -0.25*ContactoHidrante*z,
              0.8*DiametroHidrante/2
            }
            cylinder                    {
              -2*ContactoHidrante*z/3, -13*ContactoHidrante/18*z,
              1.4*3*DiametroHidrante/16
            }
            cylinder                    {
              -2*ContactoHidrante/3*z, -7*ContactoHidrante/9*z,
              1.2*3*DiametroHidrante/16
            }
            cylinder                    {
              0, -2*ContactoHidrante/6*z,
              3*DiametroHidrante/16  
              texture                   {
                TexturaUniones
              }
            }
            cylinder                    {
              -2*ContactoHidrante/6*z, -5*ContactoHidrante/6*z,
              3*DiametroHidrante/16  
            }
            #local C                    = 0;
            #local TotalAros            = 4;
            #local Sep                  =
                0.25*ContactoHidrante/( 2*TotalAros+1 );
            #while ( C < TotalAros )
              cylinder                  {
                0, -Sep*z, 1.4*3*DiametroHidrante/16
                translate               -( 2*C+1 )*Sep*z   
                texture     { TexturaUniones }
              }
              #local C                  = C+1;
            #end  //  #while ( C < TotalAros )
            translate           -DiametroHidrante/2*z
          }
        }
        // END Zona Frontal
        translate       ( FraccionPrincipal*AltoHidrante
                        -DiametroHidrante/2 )*y
      }
      // Links
      #if ( HHBI_BanderaLink )
        union                                     {
          #declare link_object = union {
            torus {.7, .3 clipped_by {box {<-1, -.3, -1>, <0, .3, 1>}} translate -x * .6}
            torus {.7, .3 clipped_by {box {<-1, -.3, -1>, <0, .3, 1>}} translate -x * .6 scale <-1, 1, 1>}
            cylinder {-x*.6, x*.6, .3 translate z * .7}
            cylinder {-x*.6, x*.6, .3 translate -z * .7}
            scale 5*HHBI_L
          }
          #local   link_looseness  = 10;
          #local   link_count      = 20;
          #local   link_twist      = .475;
          #local   scale_links     = false;
          
          #local   link_point1    =
             < -DiametroHidrante/2-0.9*ContactoHidrante,
                  FraccionPrincipal*AltoHidrante-DiametroHidrante/2, 0 >;
          #local   link_point2    =
             < -sqrt(2)*DiametroHidrante/4,
                0.2*FraccionPrincipal*AltoHidrante,
               -sqrt(2)*DiametroHidrante/4 >;
          #local camera_sky       = <0.01,1, 0.01>;
          #local   MyLink         =
            object          {
              #include "LINK.inc"
            }
          object                  {
            MyLink
          }
          object                  {
            MyLink
            scale         <-1,1,1>
          }
          #local   link_point1    =
             < 0, FraccionPrincipal*AltoHidrante-DiametroHidrante/2,
               -DiametroHidrante/2-ContactoHidrante >;
          #local   link_looseness  = 5;
          #local   MyLink2        =
            object          {
              #include "LINK.inc"
            }
          object                  {
            MyLink2
          }
          object                  {
            MyLink2
            scale         <-1,1,1>
          }     
          texture                   {
            TexturaCadenas
          }
        }
      #end  //  #if ( HHBI_BanderaLink )
      // END Links
      translate ( FraccionBase+FraccionIntermedia )*AltoHidrante*y
    }
    // END Cuerpo Principal
    texture                             {
      TexturaPrincipal
    }
  }
#end  //  #macro HHBI_HidranteHumedadBocaIncendio

#macro HHBI_Hidrante( FraccionSubSuelo )
  object                                {
    #local L                            = HHBI_L;
    #local AltoHidrante                 = 600*L;
    #local DiametroHidrante             = 150*L;
    #local FraccionBase                 = 0.4;
    #local CizallaBase                  = 1/4;
    #local FraccionIntermedia           = 0.093;
    #local FraccionSuperior             = 0.093;
    #local ContactoHidrante             = 60*L;
    HHBI_HidranteHumedadBocaIncendio( FraccionSubSuelo,
      AltoHidrante, DiametroHidrante,
      FraccionBase, CizallaBase,
      FraccionIntermedia, FraccionSuperior, ContactoHidrante,
      HHBI_TexturaPrincipal, HHBI_TexturaUniones, HHBI_TexturaExtremos,
      HHBI_TexturaBase, HHBI_TexturaCadenas )
  }
#end  //  #macro HHBI_Hidrante()
