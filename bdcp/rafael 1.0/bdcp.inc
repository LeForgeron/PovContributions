// This file is licensed under the terms of the CC-LGPL.
//
// Autor  : Rafael Angel Campos Vargas
// Correo : RofoelCompos@hotmail.com  
// Apdo. 964-1250 Escazu, San Jose, Costa Rica
// dedicado a Jesus y Maria...
//
// En este momento estoy creando un programa
// de animacion LibreN3D para FreeDOS con el compilador FreePascal
// falta mucho... 05 abril 2018
//                
// Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
// 1 L equivale a 0.055063 pulgadas 
// definido como 0.001 para POVRAY.
//     
// BDCP BluerayDvdCdPlayer
// El archivo dibuja un reproductor de video para discos en formato Bluray.
// Puede cambiar la hora, abrir y cerrar el compartimento para discos, y
// otras modificaciones menores.
// Es muy poco flexible. Es compatible con POVRay 3.1.
//
// La macro principal tiene cuatro parametros.
// #macro BDCP_Bluray( FraccionAbrir, Hora, Minuto, ModoIndicador )
//          FraccionAbrir       : Fraccion propia para cerrar 0.0 
//              o abrir 1.0 el compartimento de discos.
//          Hora                : Hora del reloj.
//          Minuto              : Minuto del reloj.
//          ModoIndicador       : 1 para "on", 2 para "off", 0 inactivo.
//
// La siguiente macro permite un mayor control de las caracteristicas.
// #macro BDCP_BlurayDvdCdPlayer( FraccionAbrir, Hora, Minuto, ModoIndicador, 
//            FrenteBluray, FraccionFrontal, FraccionInferior,
//            AltoBluray, PatasBluray, ProfundidadBluray,
//            AltoBandeja, RadioCD, GruesoCD, 
//            GruesoPlastico, BocaUSB, GruesoUSB,
//            ArregloMateriales, ArregloTexturasLED )
//          FraccionAbrir       : Fraccion propia para cerrar 0.0 
//              o abrir 1.0 el compartimento de discos.
//          Hora                : Hora del reloj.
//          Minuto              : Minuto del reloj.
//          ModoIndicador       : 1 para "on", 2 para "off", 0 inactivo.   
//          FrenteBluray        : Frente del aparato de video.
//              Valor por defecto 308*L.
//          FraccionFrontal     : Fraccion que
//              divide la textura frontal de la posterior.
//              Valor por defecto 0.15.
//          FraccionInferior    : Fraccion que ubica la cuna decorativa frontal.
//              Valor por defecto 0.4.
//          AltoBluray          : Alto del aparato de video.
//              Valor por defecto 43.6*L.
//          PatasBluray         : Alto total de las patillas soporte.
//              Valor por defecto 4.5*L.
//          ProfundidadBluray   : Profundidad en Z del aparato de video.
//              Valor por defecto 154.4*L.
//          AltoBandeja         : Alto de la bandeja soporte para CD.
//              Valor por defecto 13*L.
//          RadioCD             : Radio de un disco CD.
//              Valor por defecto 42.7*L.
//          GruesoCD            : Grueso de un disco CD.
//              Valor por defecto 0.5*L.                                                                    
//          GruesoPlastico      : Grueso de plastico para soportes interiores.
//              Valor por defecto 1*L.
//          BocaUSB             : Frente de la boquilla de un conector USB.
//              Valor por defecto 8.2*L.
//          GruesoUSB           : Alto de la boquilla de un conector USB.
//              Valor por defecto 2.7*L.
//          ArregloMateriales   : Lista de los materiales principales.
//              array [6] = { MaterialPrincipal, MaterialFrontal,
//                            MaterialBandeja, MaterialFrenteBandeja,
//                            MaterialLetras, MaterialMetalico }
//              Valor por defecto similar a BDCP_DefaultArregloMateriales
//                  MaterialPrincipal       : Material del cuerpo principal
//                  MaterialFrontal         : Material para el frente
//                  MaterialBandeja         : Material para el interior de la bandeja
//                  MaterialFrenteBandeja   : Material para el frente de la bandeja
//                  MaterialLetras          : Material para algunas letras en la bandeja
//                  MaterialMetalico        : Material para elementos metalicos 
//          ArregloTexturasLED  : Lista de texturas para el reloj               
//              array[4] = { TexturaLabelLED, TexturaTransparente,
//                           TexturaLED, TexturaFondoLED } 
//              Valor por defecto similar a BDCP_DefaultArregloTexturasLED 
//                  TexturaLabelLED         : Textura del cuerpo soporte del reloj
//                  TexturaTransparente     : Textura de capa protectora del LED
//                  TexturaLED              : Textura de digitos
//                  TexturaFondoLED         : Textura de fondo del reloj 
//
// Para dibujar otros aparatos similares, se suministra la siguiente macro para dibujar
// la bandeja para CD en forma independiente, 
// de forma que el usuario pueda incorporarla en sus propios objetos.
// #macro BDCP_BandejaInterior( FrenteBandeja, AltoBandeja,
//                ProfundidadDelantera, RadioCD, RadioMini,
//                RadioAire, GruesoPlastico, CurvaturaPlastico, GruesoCD,
//                MaterialBandeja, MaterialFrenteBandeja,
//                MaterialLetras )    
//          FrenteBandeja           : Frente exterior de la bandeja.
//              Valor por defecto 94.5*L.
//          AltoBandeja             : Alto de la bandeja soporte para CD.
//              Valor por defecto 13*L.  
//          ProfundidadDelantera    : Profundidad Z hasta el centro para ubicar el CD.
//              Valor por defecto 51*L.
//          RadioCD                 : Radio de un disco CD.
//              Valor por defecto 42.7*L. 
//          RadioMini               : Radio para un mini disco CD.
//              Valor por defecto 28*L.
//          RadioAire               : Radio para la perforacion vacia interior.
//              Valor por defecto 20*L.
//          GruesoPlastico          : Grueso de plastico para soportes interiores.
//              Valor por defecto 1*L.
//          CurvaturaPlastico       : Radio de curvatura para decorar extremos y bordes.
//              Valor por defecto 1*L.
//          GruesoCD                : Grueso de un disco CD.
//              Valor por defecto 0.5*L. 
//          MaterialBandeja         : Material para el interior de la bandeja.
//              Valor por defecto BDCP_DefaultMaterialBandeja.
//          MaterialFrenteBandeja   : Material para el frente de la bandeja.
//              Valor por defecto BDCP_DefaultMaterialFrenteBandeja.
//          MaterialLetras          : Material para letras y logo.
//              Valor por defecto BDCP_DefaultMaterialLetras.                                                                  
//
// El aparato cerrado se encuentra entre las siguientes dimensiones:
//      Minimo      = < -154,    0,  -80 >*L
//      Maximo      = < +154,  +44,  +80 >*L
// El objeto se encuentra por completo en el hemisferio Y+, 
// y las patas se encuentran directamente sobre el plano XZ. 
// La macro genera el parametro :
//      #declare BDCP_InferiorCD            : Vector de posicion para la cara
//          inferior del CD, en su centro matematico. El CD no se dibuja.
//
// Estas son variables predefinidas o generadas en el
// interior de las macros que no deberian modificarse directamente.
// Si quiere cambiarlas, recurra a los modificadores.  
// #declare BDCP_DefaultMaterialPrincipal  
//      Material principal del aparato.
// #declare BDCP_DefaultMaterialFrontal
//      Material del frente del reproductor de discos de video.    
// #declare BDCP_DefaultMaterialMetalico                       
//      Material para elementos metalicos.
// #declare BDCP_DefaultMaterialBandeja   
//      Material para la bandeja. 
// #declare BDCP_DefaultMaterialFrenteBandeja     
//      Material para el frente de la bandeja.
// #declare BDCP_DefaultMaterialLetras        
//      Material para letras y logo.
// #declare BDCP_DefaultTexturaLabelLED                
//      Textura para el soporte de LED.
// #declare BDCP_DefaultTexturaTransparente       
//      Textura transparente sobre LED.
// #declare BDCP_DefaultTexturaLED      
//      Textura para LED del reloj.          
// #declare BDCP_DefaultTexturaFondoLED   
//      Textura para el fondo de los LED.             
// #declare BDCP_DefaultArregloMateriales           = array[6]
//      Arreglo con los materiales por defecto en las macros.
// #declare BDCP_DefaultArregloTexturasLED          = array[4]    
//      Arreglo con las texturas por defecto para el reloj, 
//      que sirve como parametro en las macros.
//
// Los siguientes son los modificadores
// aplicables y redefinibles por el usuario (si se indica es default)
// #declare BDCP_StringLogo                         = "Pov-ray"   
//      Mensaje para el logo de marca.
// #declare BDCP_StringCompatible                   = "CGS-BLOB"    
//      Mensaje para compatibilidad.
// #declare BDCP_Logo                               = Povray_Logo
//      Para cambiar el logo de marca si se desea.
// #declare BDCP_MaterialPrincipal                  = material { ... }
//      Material principal del aparato.
// #declare BDCP_MaterialFrontal                    = material { ... }
//      Material del frente del reproductor de discos de video.    
// #declare BDCP_MaterialMetalico                   = material { ... }
//      Material para elementos metalicos.
// #declare BDCP_MaterialBandeja                    = material { ... }
//      Material para la bandeja. 
// #declare BDCP_MaterialFrenteBandeja              = material { ... }
//      Material para el frente de la bandeja.
// #declare BDCP_MaterialLetras                     = material { ... }
//      Material para letras y logo.
// #declare BDCP_TexturaLabelLED                    = texture  { ... }
//      Textura para el soporte de LED.
// #declare BDCP_TexturaTransparente                = texture  { ... }
//      Textura transparente sobre LED.
// #declare BDCP_TexturaLED                         = texture  { ... }
//      Textura para LED del reloj.          
// #declare BDCP_TexturaFondoLED                    = texture  { ... }
//      Textura para el fondo de los LED.             
//        
// Para colocarlo simplemente
// #include "BDCP.inc" 
// object { BDCP_Bluray( 1.0, 10, 20, 1 ) }
//                                  
// Ejemplo con la macro detallada, mismo objeto default
// #include "BDCP.inc"   
// object                       {
//   BDCP_BlurayDvdCdPlayer( 1.0, 10, 20, 1,
//        0.308, 0.15, 0.4, 0.0436, 0.0045, 0.1544,  
//        0.013, 0.0427, 0.0005, 0.001, 0.0082, 0.0027,
//        BDCP_DefaultArregloMateriales, BDCP_DefaultArregloTexturasLED )
// }
//        
// Con modificadores
// #include "BDCP.inc"
// #include "textures.inc"
// #declare BDCP_MaterialPrincipal   = material { texture { PinkAlabaster } }
// object        { BDCP_Bluray( 1.0, 10, 20, 1 ) }
//

#include "BDCP_AU1.inc"
#declare BDCP_L                         = 0.001;

#if ( version < 3.2 )
  #ifndef( BDCP_POV3_1 )
    #declare BDCP_POV3_1        = on;
  #end
#else
  #ifndef( BDCP_POV3_1 )
    #declare BDCP_POV3_1        = off;
  #end
#end

#declare BDCP_StringLogo        = "Pov-ray"  
#declare BDCP_StringCompatible  = "CGS-BLOB"

#if ( BDCP_POV3_1 )
  // Copia textual de Povray_Logo en logo.inc
  // incluido aqui por compatibilidad con POV_RAY 3.1
  #declare BDCP_Logo                      =
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
#else  // #else ( BDCP_POV3_1 )
  #include "logo.inc"
  #declare BDCP_Logo = Povray_Logo
#end   // #else ( BDCP_POV3_1 )

#declare BDCP_DefaultMaterialPrincipal  =
  material                              {
    texture                             {
      pigment                           {
        color Gray30
      }
    }
  }

#ifndef ( BDCP_MaterialPrincipal )
  #declare BDCP_MaterialPrincipal         = BDCP_DefaultMaterialPrincipal
#end  // #ifndef ( BDCP_MaterialPrincipal )

#declare BDCP_DefaultMaterialFrontal    =
  material                              {
    texture                             {
      pigment                           {
        color Gray40
      }
      finish                            {
        phong 0.5
        phong_size  10
      }
    }
  }

#ifndef ( BDCP_MaterialFrontal )
  #declare BDCP_MaterialFrontal         = BDCP_DefaultMaterialFrontal
#end  // #ifndef ( BDCP_MaterialFrontal )

#declare BDCP_DefaultMaterialMetalico    =
  material                              {
    texture                             {
      pigment                           {
        color Silver
      }
      finish                            {
        metallic
        phong 0.7
        phong_size  10
      }
    }
  }

#ifndef ( BDCP_MaterialMetalico )
  #declare BDCP_MaterialMetalico         = BDCP_DefaultMaterialMetalico
#end  // #ifndef ( BDCP_MaterialMetalico )

#declare BDCP_DefaultMaterialBandeja    =
  material                              {
    texture                             {
      pigment                           {
        color Gray50
      }
    }
  }

#ifndef ( BDCP_MaterialBandeja )
  #declare BDCP_MaterialBandeja         = BDCP_DefaultMaterialBandeja
#end  // #ifndef ( BDCP_MaterialBandeja )

#declare BDCP_DefaultMaterialFrenteBandeja      =
  material                              {
    texture                             {
      pigment                           {
        color Gray40
      }
      finish                            {
        phong 0.5
        phong_size  10
      }
    }
  }

#ifndef ( BDCP_MaterialFrenteBandeja )
  #declare BDCP_MaterialFrenteBandeja   = BDCP_DefaultMaterialFrenteBandeja
#end  // #ifndef ( BDCP_MaterialFrenteBandeja )

#declare BDCP_DefaultMaterialLetras    =
  material                              {
    texture                             {
      pigment                           {
        color White
      }
    }
  }

#ifndef ( BDCP_MaterialLetras )
  #declare BDCP_MaterialLetras         = BDCP_DefaultMaterialLetras
#end  // #ifndef ( BDCP_MaterialLetras )

#declare BDCP_DefaultTexturaLabelLED                =
  texture { pigment { Gray10 } }

#ifndef ( BDCP_TexturaLabelLED )
  #declare BDCP_TexturaLabelLED              = BDCP_DefaultTexturaLabelLED
#end  // #ifndef ( BDCP_TexturaLabelLED )

#declare BDCP_DefaultTexturaTransparente       =
  texture { pigment { Green transmit 0.95 } }

#ifndef ( BDCP_TexturaTransparente )
  #declare BDCP_TexturaTransparente     = BDCP_DefaultTexturaTransparente
#end  // #ifndef ( BDCP_TexturaTransparente )

#declare BDCP_DefaultTexturaLED                =
  texture { pigment { Green } }

#ifndef ( BDCP_TexturaLED )
  #declare BDCP_TexturaLED              = BDCP_DefaultTexturaLED
#end  // #ifndef ( BDCP_TexturaLED )

#declare BDCP_DefaultTexturaFondoLED                =
  texture { pigment { Gray10 } }

#ifndef ( BDCP_TexturaFondoLED )
  #declare BDCP_TexturaFondoLED              = BDCP_DefaultTexturaFondoLED
#end  // #ifndef ( BDCP_TexturaFondoLED )  

#declare BDCP_DefaultArregloMateriales          = array[6]
      { BDCP_DefaultMaterialPrincipal, BDCP_DefaultMaterialFrontal, 
        BDCP_DefaultMaterialBandeja, BDCP_DefaultMaterialFrenteBandeja,
        BDCP_DefaultMaterialLetras, BDCP_DefaultMaterialMetalico }
        
#declare BDCP_DefaultArregloTexturasLED         = array[4]    
        { BDCP_DefaultTexturaLabelLED, BDCP_DefaultTexturaTransparente,
          BDCP_DefaultTexturaLED, BDCP_DefaultTexturaFondoLED }


#macro BDCP_BandejaInterior( FrenteBandeja, AltoBandeja,
                ProfundidadDelantera, RadioCD, RadioMini,
                RadioAire, GruesoPlastico, CurvaturaPlastico, GruesoCD,
                MaterialBandeja, MaterialFrenteBandeja,
                MaterialLetras )
  union                                         {
    // Frente Bandeja
    union                                       {
      box                                       {
        < -FrenteBandeja/2+CurvaturaPlastico,
          -AltoBandeja/2+CurvaturaPlastico, 0 >,
        < +FrenteBandeja/2-CurvaturaPlastico,
          +AltoBandeja/2-CurvaturaPlastico, -GruesoPlastico >
      }
      difference                                {
        union                                   {
          cylinder                                  {
            ( -FrenteBandeja/2+CurvaturaPlastico )*x,
            ( +FrenteBandeja/2-CurvaturaPlastico )*x,
            1
            scale  <1,CurvaturaPlastico,GruesoPlastico>
            translate       ( -AltoBandeja/2+CurvaturaPlastico )*y
          }
          cylinder                                  {
            ( -FrenteBandeja/2+CurvaturaPlastico )*x,
            ( +FrenteBandeja/2-CurvaturaPlastico )*x,
            1
            scale  <1,CurvaturaPlastico,GruesoPlastico>
            translate       ( +AltoBandeja/2-CurvaturaPlastico )*y
          }
          cylinder                                  {
            ( -AltoBandeja/2+CurvaturaPlastico )*y,
            ( +AltoBandeja/2-CurvaturaPlastico )*y,
            1
            scale  <CurvaturaPlastico,1,GruesoPlastico>
            translate       ( -FrenteBandeja/2+CurvaturaPlastico )*x
          }
          cylinder                                  {
            ( -AltoBandeja/2+CurvaturaPlastico )*y,
            ( +AltoBandeja/2-CurvaturaPlastico )*y,
            1
            scale  <CurvaturaPlastico,1,GruesoPlastico>
            translate       ( +FrenteBandeja/2-CurvaturaPlastico )*x
          }
          union                                 {
            object                              {
              BDCP_Logo
              scale  0.005
              translate               -GruesoPlastico*z
            }
            text                                  {
              ttf "cyrvetic.ttf", BDCP_StringLogo, 1, 0
              scale  0.005
              matrix                      <1,0,0,
                                           0.433,1,0,
                                           0,0,1,
                                           0,0,0>
              translate                   -FrenteBandeja/4*x
              translate               -1.25*GruesoPlastico*z
            }
            material                            {
              MaterialLetras
            }
          }
        }
        plane                                   {
          -z, 0
        }
      }
      #local C                                  = 0;
      #while ( C < 4 )
        cone                                      {
          0, CurvaturaPlastico,
          -GruesoPlastico*z, 0
          translate               <-FrenteBandeja/2+CurvaturaPlastico,
                                   -AltoBandeja/2+CurvaturaPlastico,0>
          #if ( mod( C, 2 ) = 0 )
            scale  <-1,+1,1>
          #end
          #if ( div( C, 2 ) = 0 )
            scale  <+1,-1,1>
          #end
        }
        #local C                                = C+1;
      #end  // #while ( C < 4 )
      material                                  {
        MaterialFrenteBandeja
      }
      translate         ( -ProfundidadDelantera+GruesoPlastico )*z
    }
    // END Frente Bandeja
    // Cuerpo Interno
    #local VacioAire                            = 2*CurvaturaPlastico;
    difference                                  {
      union                                     {
        box                                     {
          < -FrenteBandeja/2+VacioAire, -AltoBandeja/2+VacioAire,
            ProfundidadDelantera+VacioAire >,
          < +FrenteBandeja/2-VacioAire, +AltoBandeja/2-VacioAire,
            -ProfundidadDelantera+CurvaturaPlastico >
        }
      }
      box                                       {
        < -FrenteBandeja, +GruesoCD,
          -0.25*ProfundidadDelantera >,
        < +FrenteBandeja, +AltoBandeja,
          +0.25*ProfundidadDelantera >
      }
      cylinder                                  {
        -AltoBandeja*y, AltoBandeja*y, RadioAire
      }
      cylinder                                  {
        0, AltoBandeja*y, RadioCD
      }
      cylinder                                  {
        +GruesoCD/2*y, AltoBandeja*y, 1.025*RadioCD
      }
      cone                                      {
        -GruesoCD/2*y, RadioMini,
        +AltoBandeja/2*y, RadioCD
      }
      box                                       {
        < -RadioAire, -AltoBandeja, 0 >,
        < +RadioAire, +AltoBandeja, +2*ProfundidadDelantera >
      }
      #local C                                  = 0;
      #while ( C < 2 )
        union                                   {
          cylinder                              {
            -AltoBandeja*y, AltoBandeja*y, 2*CurvaturaPlastico
            translate   +( RadioMini+RadioCD )/2*x
          }
          box                                   {
            < RadioMini, -AltoBandeja,
                        -ProfundidadDelantera+2*GruesoPlastico >,
            < RadioCD, +AltoBandeja,
                -ProfundidadDelantera+2*GruesoPlastico+10*CurvaturaPlastico >
          }
          box                                   {
            < RadioMini, -AltoBandeja,
                        +ProfundidadDelantera-2*GruesoPlastico >,
            < RadioCD, +AltoBandeja,
                +ProfundidadDelantera-2*GruesoPlastico-10*CurvaturaPlastico >
          }
          #if ( C = 1 )
            scale               <-1,1,1>
          #end  // #if ( C = 1 )
        }
        #local C                                = C+1;
      #end  // #while ( C < 2 )
      difference                                 {
        box                                     {
          < -FrenteBandeja/2+VacioAire+GruesoPlastico, GruesoCD,
            ProfundidadDelantera+VacioAire-GruesoPlastico >,
          < +FrenteBandeja/2-VacioAire-GruesoPlastico, +AltoBandeja,
            -ProfundidadDelantera+CurvaturaPlastico+GruesoPlastico >
        }
        cylinder                                {
          -AltoBandeja*y, +AltoBandeja*y, 1.025*RadioCD+GruesoPlastico
        }
      }
    }
    // END Cuerpo Interno
    material                            {
      MaterialBandeja
    }
  }  // union
#end  // #macro BDCP_BanderaInterior()

#macro BDCP_FrenteBluray( ModoIndicador,
                FrenteBluray, FraccionFrontal, FraccionInferior,
                AltoBluray, PatasBluray,
                ProfundidadBluray, CurvaturaBluray,
                FrenteBandeja, AltoBandeja,
                Frente, Radial, ProfundidadDisplay, BocaUSB, GruesoUSB,
                MaterialFrontal, MaterialLetras, MaterialMetal )
  difference                                    {
    union                                         {
      box                                         {
        < -FrenteBluray/2, PatasBluray+CurvaturaBluray,
          ( -0.5+FraccionFrontal )*ProfundidadBluray >,
        < +FrenteBluray/2, AltoBluray-CurvaturaBluray,
        -0.5*ProfundidadBluray+CurvaturaBluray >
      }
      box                                         {
        < -FrenteBluray/2+CurvaturaBluray, PatasBluray+CurvaturaBluray,
          ( -0.5+FraccionFrontal )*ProfundidadBluray >,
        < +FrenteBluray/2-CurvaturaBluray, AltoBluray-CurvaturaBluray,
        -0.5*ProfundidadBluray >
      }
      box                                         {
        < -FrenteBluray/2+CurvaturaBluray, PatasBluray,
          ( -0.5+FraccionFrontal )*ProfundidadBluray >,
        < +FrenteBluray/2-CurvaturaBluray, AltoBluray,
        -0.5*ProfundidadBluray+CurvaturaBluray >
      }
      #local DeltaAlto                            = AltoBluray-PatasBluray;
      #local C                                    = 0;
      #while ( C < 4 )
        union                                     {
          cylinder                                  {
            ( -0.5+FraccionFrontal )*ProfundidadBluray*z,
            ( -0.5*ProfundidadBluray+CurvaturaBluray )*z, CurvaturaBluray
          }
          sphere                                  {
            ( -0.5*ProfundidadBluray+CurvaturaBluray )*z, CurvaturaBluray
          }
          translate  ( -FrenteBluray/2+CurvaturaBluray )*x
                  +( -DeltaAlto/2+CurvaturaBluray )*y
          #if ( mod( C, 2 ) = 1 )
            scale <-1,1,1>
          #end
          #if ( div( C, 2 ) = 1 )
            scale <1,-1,1>
          #end        
          translate               PatasBluray*y+DeltaAlto/2*y
        }
        cylinder                                  {
          -y/2, y/2,
          CurvaturaBluray
          #if ( div( C, 2 ) = 1 )
            rotate                90*z
            scale <FrenteBluray-2*CurvaturaBluray,1,1>
            translate     ( -DeltaAlto/2+CurvaturaBluray )*y
            #if ( mod( C, 2 ) = 1 )
              scale <1,-1,1>
            #end
          #else
            scale  <1,DeltaAlto-2*CurvaturaBluray,1>
            translate     ( -FrenteBluray/2+CurvaturaBluray )*x
            #if ( mod( C, 2 ) = 1 )
              scale <-1,1,1>
            #end
          #end        
          translate               PatasBluray*y+DeltaAlto/2*y
          translate       ( -0.5*ProfundidadBluray+CurvaturaBluray )*z
        }
  
        #local C                                  = C+1;
      #end  // #while ( C < 4 )
    }
    box                                       {
      < -FrenteBandeja/2-CurvaturaPlastico/4,
        -AltoBandeja/2-CurvaturaPlastico/4,
        -ProfundidadBluray/2+CurvaturaPlastico >,
      < +FrenteBandeja/2+CurvaturaPlastico/4,
        +AltoBandeja/2+CurvaturaPlastico/4, -ProfundidadBluray >
      translate                 -AltoBandeja/2*y
      translate      PatasBluray*y+0.85*DeltaAlto*y-0.2*FrenteBandeja*x
    }
    box                                       {
      < -FrenteBandeja/2+CurvaturaPlastico,
        -AltoBandeja/2-CurvaturaPlastico/4, 0 >,
      < +FrenteBandeja/2-CurvaturaPlastico,
        +AltoBandeja/2+CurvaturaPlastico/4, -ProfundidadBluray >
      translate                 -AltoBandeja/2*y
      translate      PatasBluray*y+0.85*DeltaAlto*y-0.2*FrenteBandeja*x
    }
    box                             {
      // para el clock
      <-Frente/2,-Radial,+ProfundidadDisplay>,
      <+Frente/2,+Radial,-ProfundidadDisplay>
      translate         -ProfundidadBluray/2*z
      translate                 -Radial*y
      translate      PatasBluray*y+0.90*DeltaAlto*y+0.25*FrenteBluray*x
    }
    torus                               {
      2*CurvaturaBluray, CurvaturaBluray/2
      rotate            90*x
      translate         -ProfundidadBluray/2*z
      translate      PatasBluray*y+0.75*DeltaAlto*y+0.15*FrenteBluray*x
    }
    // USB
    union                               {
      difference                        {
        box                                 {
          < -BocaUSB/2, -GruesoUSB/2, 0 >,
          < +BocaUSB/2, +GruesoUSB/2, -ProfundidadBluray >
        }
        box                                 {
          < -BocaUSB/2+CurvaturaBluray/2, -GruesoUSB/4, 0 >,
          < +BocaUSB/2-CurvaturaBluray/2, +GruesoUSB/4, -ProfundidadBluray >
        }
      }
      box                                 {
        < -BocaUSB/2-CurvaturaBluray/2, -GruesoUSB/2,
                -ProfundidadBluray/2+2*CurvaturaBluray >,
        < +BocaUSB/2+CurvaturaBluray/2, +GruesoUSB/2, -ProfundidadBluray >
      }
      translate      PatasBluray*y+0.15*DeltaAlto*y+0.475*FrenteBluray*x
      material                          {
        MaterialMetal
      }
    }
    // END USB
    union                               {
      difference                        {
        torus                           {
          2*CurvaturaBluray, CurvaturaBluray/3
          rotate                90*x
        }
        box                             {
          < -CurvaturaBluray, 0, -CurvaturaBluray >,
          < +CurvaturaBluray, +10*CurvaturaBluray, +CurvaturaBluray >
        }
      }
      cylinder                                      {
        1.0*CurvaturaBluray*y, 3.0*CurvaturaBluray*y, CurvaturaBluray/3
      }
      translate         -ProfundidadBluray/2*z
      translate      PatasBluray*y+0.75*DeltaAlto*y-0.45*FrenteBluray*x
      #switch ( ModoIndicador )
        #case ( 1 )
          pigment { color 2*Green }
        #break
        #case ( 2 )
          pigment { color 2*Red }
        #break
      #end
    }
    union                                       {
      box                                       {
        < -FrenteBluray, 0, 0 >,
        < +FrenteBluray, FraccionInferior*DeltaAlto, -0.1*ProfundidadBluray >
      }
      text                                       {
        ttf "crystal.ttf", BDCP_StringCompatible, 2, 0
        translate       -z
        scale   DeltaAlto/4
        translate               0.15*DeltaAlto*y-0.45*FrenteBluray*x
        material                                {
          MaterialLetras
        }
      }
      matrix    < 1,0,0,
                  0,1,+0.3,
                  0,0,1,
                  0,0,0 >
      translate -0.5*ProfundidadBluray*z
                +PatasBluray*y
    }
    material                                    {
      MaterialFrontal
    }
  }  // union
#end  // #macro BDCP_FrenteBluray()

#macro BDCP_PosteriorBluray( FrenteBluray, FraccionFrontal,
                AltoBluray, PatasBluray,
                ProfundidadBluray, CurvaturaBluray,
                MaterialPrincipal, MaterialMetal )
  union                                         {
    difference                                  {
      union                                     {
        box                                         {
          < -FrenteBluray/2, PatasBluray+CurvaturaBluray,
            ( -0.5+FraccionFrontal )*ProfundidadBluray >,
          < +FrenteBluray/2, AltoBluray-CurvaturaBluray,
          +0.5*ProfundidadBluray >
        }
        box                                         {
          < -FrenteBluray/2+CurvaturaBluray, PatasBluray,
            ( -0.5+FraccionFrontal )*ProfundidadBluray >,
          < +FrenteBluray/2-CurvaturaBluray, AltoBluray,
          +0.5*ProfundidadBluray >
        }
      }
      // Logo superior
      union                                 {
        object                              {
          BDCP_Logo
          rotate                90*x
          scale  <0.05,0.005,0.05>
          translate               +AltoBluray*y-0.2*FrenteBluray*x
        }
        text                                  {
          ttf "cyrvetic.ttf", BDCP_StringLogo, 1, 0
          matrix                      <1,0,0,
                                       0.433,1,0,
                                       0,0,1,
                                       0,0,0>
          translate               -0.5*z
          rotate                90*x
          scale  <0.025,0.00125,0.025>
          translate               +AltoBluray*y+0.0*FrenteBluray*x
        }
      }
      // END Logo superior
      // Aire
      box                                       {
        <0.35*FrenteBluray,AltoBluray-5*CurvaturaBluray,
                +0.3*ProfundidadBluray>,
        <0.475*FrenteBluray,AltoBluray-CurvaturaBluray/4,0>
      }
      #local C                  = 0;
      #while ( C < 2 )
        #local D                = 0;
        #while ( D < 10 )
          box                   {
            < 0.35*FrenteBluray,AltoBluray-5*CurvaturaBluray, 0 >,
            < 0.375*FrenteBluray,AltoBluray+CurvaturaBluray,
            0.0075*ProfundidadBluray >
            translate           0.030*ProfundidadBluray*z*D
            translate   0.075*FrenteBluray*x*C
          }
          #local D              = D+1;
        #end // #while ( D < 10 )
        #local C                = C+1;
      #end  // #while ( C < 2 )
      #local C                  = 0;
      #while ( C < 5 )
        #local D                = 0;
        #while ( D < 3 )
          box                   {
            < -FrenteBluray,0, -0.0125*FrenteBluray >,
            < +FrenteBluray,0.0075*ProfundidadBluray, +0.0125*FrenteBluray >
            translate           ( AltoBluray-2*CurvaturaBluray )*y
            translate           -0.030*ProfundidadBluray*y*D
            translate   0.05*FrenteBluray*z*( C-2 )
          }
          #local D              = D+1;
        #end // #while ( D < 10 )
        #local C                = C+1;
      #end  // #while ( C < 2 )
      // EMD Aire
      union                             {
        cylinder                                {
          -FrenteBluray*x, ( -FrenteBluray/2+2*CurvaturaPlastico )*x, 4*CurvaturaPlastico
        }
        cylinder                                {
          +FrenteBluray*x, -( -FrenteBluray/2+2*CurvaturaPlastico )*x, 5*CurvaturaPlastico
        }
        translate               ( 0.75*PatasBluray+0.25*AltoBluray )*y
      }
      // Diferencia Bajos    
      cylinder                                  {
        -0.4*FrenteBluray*x, 0.4*FrenteBluray*x, 3*CurvaturaPlastico
        material                                {
          MaterialMetal
        }                                                           
        translate           PatasBluray*y
      }
      cylinder                                  {
        -0.4*FrenteBluray*x, 0.4*FrenteBluray*x, 3*CurvaturaPlastico
        material                                {
          MaterialMetal
        }                                                           
        translate           PatasBluray*y-0.20*ProfundidadBluray*z
      }
      cylinder                                  {
        -0.4*FrenteBluray*x, 0.4*FrenteBluray*x, 3*CurvaturaPlastico
        material                                {
          MaterialMetal
        }                                                           
        translate           PatasBluray*y+0.20*ProfundidadBluray*z
      }
      // END Diferencia Bajos   
      // Diferencia posterior
      cylinder                                  {
        -FrenteBluray*x, FrenteBluray*x, CurvaturaPlastico
        material                                {
          MaterialMetal
        }                                                           
        translate           0.75*PatasBluray*y++0.25*AltoBluray*y+0.50*ProfundidadBluray*z
      }
      // END Diferencia Posterior
    }
    #local DeltaAlto                            = AltoBluray-PatasBluray;
    #local C                                    = 0;
    #while ( C < 4 )
      cylinder                                  {
        ( -0.5+FraccionFrontal )*ProfundidadBluray*z,
        +0.5*ProfundidadBluray*z, CurvaturaBluray
        translate  ( -FrenteBluray/2+CurvaturaBluray )*x
                +( -DeltaAlto/2+CurvaturaBluray )*y
        #if ( mod( C, 2 ) = 1 )
          scale <-1,1,1>
        #end
        #if ( div( C, 2 ) = 1 )
          scale <1,-1,1>
        #end        
        translate               PatasBluray*y+DeltaAlto/2*y
      }
      #local C                                  = C+1;
    #end  // #while ( C < 4 )
    union                                       {
      sphere                                    {
        0, 2*CurvaturaPlastico
        translate -( -FrenteBluray/2+2*CurvaturaPlastico )*x
      }
      sphere                                    {
        0, 2*CurvaturaPlastico
        translate +( -FrenteBluray/2+2*CurvaturaPlastico )*x
      }
      translate               ( 0.75*PatasBluray+0.25*AltoBluray )*y
      material                                  {
        MaterialMetal
      }
    }          
    // Decoracion posterior    
    union                                       {
      superellipsoid                            {
        <0.2,0.2>
        scale           2*<5,5,1>*CurvaturaPlastico
        translate       PatasBluray*y+0.5*AltoBluray*y+0.50*ProfundidadBluray*z
      }
      superellipsoid                            {
        <0.2,0.2>
        scale           2*<5,5,1>*CurvaturaPlastico
        translate       PatasBluray*y+0.5*AltoBluray*y+0.50*ProfundidadBluray*z
                        +0.3*FrenteBluray*x
      }
      superellipsoid                            {
        <0.2,0.2>
        scale           2*<5,5,1>*CurvaturaPlastico
        translate       PatasBluray*y+0.5*AltoBluray*y+0.50*ProfundidadBluray*z
                        -0.3*FrenteBluray*x    
      }
      cylinder                                  {
        -0.5*FrenteBluray*x, 0.5*FrenteBluray*x, CurvaturaPlastico
        translate           0.25*PatasBluray*y+0.75*AltoBluray*y+0.50*ProfundidadBluray*z
      }
      cylinder                                  {
        -0.5*FrenteBluray*x, 0.5*FrenteBluray*x, CurvaturaPlastico
        translate           0.15*PatasBluray*y+0.85*AltoBluray*y+0.50*ProfundidadBluray*z
      }
      cylinder                                  {
        -0.5*FrenteBluray*x, 0.5*FrenteBluray*x, CurvaturaPlastico
        translate           0.35*PatasBluray*y+0.65*AltoBluray*y+0.50*ProfundidadBluray*z
      }
    }
    // END Decoracion posterior
    #local C                                    = 0;
    #while ( C < 4 )                                  
      union                                     {  
        box                                     {
          <-0.04,0,-0.04>*FrenteBluray+0.2*PatasBluray*y,
          <+0.04,0,+0.04>*FrenteBluray+PatasBluray*y
        }
        cylinder                                {
          0, PatasBluray*y, 0.025*FrenteBluray
          material                              {
            MaterialMetal
          }
        }
        translate           0.35*( 1-FraccionFrontal )*ProfundidadBluray*z
                            +0.35*FrenteBluray*x
        #if ( mod( C, 2 ) = 0 )                    
          scale     < -1, 1, 1>
        #end                   
        #if ( div( C, 2 ) = 0 )                    
          scale     <  1, 1, -1>
        #end                           
      }
      #local C                                  = C+1;
    #end  // #while ( C < 4 )
    material                                    {
      MaterialPrincipal
    }
  }  // union
#end  // #macro BDCP_PosteriorBluray()

#macro BDCP_CirculoBotones( RadioBotones, CurvaturaBluray,
            MaterialMetalico, MaterialFrontal, MaterialLetras )
  union                                         {
    difference                                  {
      torus                                       {
        RadioBotones-CurvaturaBluray, CurvaturaBluray
        rotate                  90*x
      }
      cylinder                                  {
        -CurvaturaBluray*z, CurvaturaBluray*z, RadioBotones-CurvaturaBluray
      }
      material                                  {
        MaterialMetalico
      }
    }
    difference                                  {
      cylinder                                  {
        +RadioBotones*z, -CurvaturaBluray*z, RadioBotones-CurvaturaBluray
      }
      torus                                     {
        0.5*( RadioBotones-CurvaturaBluray ), CurvaturaBluray/2
        rotate          90*x
        translate               -CurvaturaBluray*z
      }
      #local C                                  = 0;
      #while ( C < 4 )
        cylinder                                {
          0.5*( RadioBotones-CurvaturaBluray )*x,
          ( RadioBotones-CurvaturaBluray )*x, CurvaturaBluray/2
          rotate                ( 90*C-45 )*z
          translate               -CurvaturaBluray*z
        }
        #local C                                = C+1;
      #end  //  #while ( C < 4 )
      material                                          {
        MaterialFrontal
      }
    }
  }
#end  // #mcro BDCP_CirculoBotones()

#macro BDCP_BlurayDvdCdPlayer( FraccionAbrir, Hora, Minuto, ModoIndicador, 
            FrenteBluray, FraccionFrontal, FraccionInferior,
            AltoBluray, PatasBluray, ProfundidadBluray, 
            AltoBandeja, RadioCD, GruesoCD, 
            GruesoPlastico, BocaUSB, GruesoUSB,
            ArregloMateriales, ArregloTexturasLED )
  union                                 {                                       
    #local MaterialPrincipal            = ArregloMateriales[0]
    #local MaterialFrontal              = ArregloMateriales[1]
    #local MaterialBandeja              = ArregloMateriales[2]
    #local MaterialFrenteBandeja        = ArregloMateriales[3]
    #local MaterialLetras               = ArregloMateriales[4]
    #local MaterialMetalico             = ArregloMateriales[5]
    #local TexturaLabelLED              = ArregloTexturasLED[0]    
    #local TexturaTransparente          = ArregloTexturasLED[1]
    #local TexturaLED                   = ArregloTexturasLED[2]
    #local TexturaFondoLED              = ArregloTexturasLED[3]
    #local FrenteBandeja                = 94.5/42.7*RadioCD;
    #local ProfundidadDelantera         = 51/42.7*RadioCD;
    #local RadioMini                    = 28/42.7*RadioCD;
    #local RadioAire                    = 20/42.7*RadioCD;
    #local CurvaturaPlastico            = GruesoPlastico;   
    #local CurvaturaBluray              = 2*GruesoPlastico;
    #local RadioBotones                 = 12.5/43.6*AltoBluray;
    #local DeltaAlto                    = AltoBluray-PatasBluray;
    object                              {
      BDCP_BandejaInterior( FrenteBandeja, AltoBandeja, ProfundidadDelantera,
                RadioCD, RadioMini, RadioAire,
                GruesoPlastico, CurvaturaPlastico, GruesoCD,
                MaterialBandeja, MaterialFrenteBandeja,
                MaterialLetras )
      translate         ProfundidadDelantera*z-ProfundidadBluray*z/2
      translate                 -AltoBandeja/2*y
      translate      PatasBluray*y+0.85*DeltaAlto*y-0.2*FrenteBandeja*x
      translate         -FraccionAbrir*1.4*ProfundidadDelantera*z   
      #declare BDCP_InferiorCD          = ProfundidadDelantera*z
                    -ProfundidadBluray*z/2-AltoBandeja/2*y  
                    +PatasBluray*y+0.85*DeltaAlto*y-0.2*FrenteBandeja*x
                    -FraccionAbrir*1.4*ProfundidadDelantera*z;   
    }
    #local Indicadores  = 0;
    #local Frente       = 71.5/2/308*FrenteBluray;
    #local ProfundidadDisplay   = 3.6/1.0*GruesoPlastico;
    #local Radial       = 19.7/3/0.6/43.6*( 1-FraccionInferior )*AltoBluray;    
    object                         {
      BDCP_DisplayClock( Hora, Minuto,Indicadores, 0.5,
          off, Frente, ProfundidadDisplay, Radial,
          TexturaLabelLED, TexturaTransparente,
          TexturaLED, TexturaFondoLED )
      translate         -ProfundidadBluray/2*z+0.99*ProfundidadDisplay*z
      translate                 -Radial*y
      translate      PatasBluray*y+0.90*DeltaAlto*y+0.25*FrenteBluray*x
    }
    object                              {
      BDCP_CirculoBotones( RadioBotones, CurvaturaBluray,
                        MaterialMetalico,
                        MaterialFrontal, MaterialLetras )
      translate         -ProfundidadBluray/2*z
      translate      PatasBluray*y+0.50*DeltaAlto*y+0.40*FrenteBluray*x
    }
    union                               {
      BDCP_FrenteBluray( ModoIndicador,
                FrenteBluray, FraccionFrontal, FraccionInferior,
                AltoBluray, PatasBluray,
                ProfundidadBluray, CurvaturaBluray,
                FrenteBandeja, AltoBandeja,
                Frente, Radial, ProfundidadDisplay, BocaUSB, GruesoUSB,
                MaterialFrontal, MaterialLetras,
                MaterialMetalico )
      BDCP_PosteriorBluray( FrenteBluray, FraccionFrontal,
                AltoBluray, PatasBluray,
                ProfundidadBluray, CurvaturaBluray,
                MaterialPrincipal, MaterialMetalico )
    }
  }
#end  // #macro BDCP_BlurayDvdCdPlayer()

#macro BDCP_Bluray( FraccionAbrir, Hora, Minuto, ModoIndicador )
  object                                       {        
    #local L                            = BDCP_L; 
    #local FrenteBluray                 = 308*L;
    #local FraccionFrontal              = 0.15;
    #local FraccionInferior             = 0.4;
    #local AltoBluray                   = 43.6*L;
    #local PatasBluray                  = 4.5*L;
    #local ProfundidadBluray            = 154.4*L;
    #local AltoBandeja                  = 13*L;
    #local RadioCD                      = 42.7*L;
    #local GruesoCD                     = 0.5*L;
    #local GruesoPlastico               = 1*L;
    #local BocaUSB                      = 8.2*L;
    #local GruesoUSB                    = 2.7*L;
    #local ArregloMateriales            = array[6]
      { BDCP_MaterialPrincipal, BDCP_MaterialFrontal, 
        BDCP_MaterialBandeja, BDCP_MaterialFrenteBandeja,
        BDCP_MaterialLetras, BDCP_MaterialMetalico }
    #local ArregloTexturasLED           = array[4]    
        { BDCP_TexturaLabelLED, BDCP_TexturaTransparente,
          BDCP_TexturaLED, BDCP_TexturaFondoLED }
    BDCP_BlurayDvdCdPlayer( FraccionAbrir, Hora, Minuto, ModoIndicador, 
        FrenteBluray, FraccionFrontal, FraccionInferior,
        AltoBluray, PatasBluray, ProfundidadBluray,  
        AltoBandeja, RadioCD, GruesoCD, 
        GruesoPlastico, BocaUSB, GruesoUSB,
        ArregloMateriales, ArregloTexturasLED )
  }
#end  // #macro BDCP_Bluray()
