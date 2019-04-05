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
#include "colors.inc"  
#include "metals.inc"  
#include "stones.inc"
#include "BMME_AU1.inc"
#declare BMME_L                           = 0.001;   

#declare BMME_StringLogo                  = "POV-Ray"

#declare BMME_DefectoTexturaPrincipal           =
  texture                                       {
    pigment { White }
    normal  { bumps }
    finish      {
      phong 0.2
      phong_size 10
    }
  }

#ifndef ( BMME_TexturaPrincipal )
  #declare BMME_TexturaPrincipal        = BMME_DefectoTexturaPrincipal
#end  //  #ifndef ( BMME_TexturaPrincipal )

#declare BMME_DefectoTexturaDecorativa           =
  texture                                       {
    T_Stone41
  }

#ifndef ( BMME_TexturaDecorativa )
  #declare BMME_TexturaDecorativa        = BMME_DefectoTexturaDecorativa
#end  //  #ifndef ( BMME_TexturaDecorativa )

#declare BMME_DefectoTexturaTexto           =
  texture                                       {  
    T_Stone44
  }

#ifndef ( BMME_TexturaTexto )
  #declare BMME_TexturaTexto        = BMME_DefectoTexturaTexto
#end  //  #ifndef ( BMME_TexturaTexto )

#declare BMME_DefectoTexturaMetalica           =
  texture                                       { 
    T_Chrome_2C   
  }

#ifndef ( BMME_TexturaMetalica )
  #declare BMME_TexturaMetalica        = BMME_DefectoTexturaMetalica
#end  //  #ifndef ( BMME_TexturaMetalica )


#macro BMME_IntersectionObjetos
          ( VectorCuadrantal, Objeto1, Min1, Max1, //
            Objeto2, Min2, Max2,
            Objeto3, Min3, Max3 )
  intersection                    {
    object                        {
      Objeto1                          
      translate                   -( Min1+Max1 )/2
      scale                       2/( Max1-Min1 )
      rotate                    90*VectorCuadrantal.x*x
      rotate                    90*div( VectorCuadrantal.x, 4 )*y
      rotate                    90*div( VectorCuadrantal.x, 16 )*z
    }
    object                        {
      Objeto2                          
      translate                   -( Min2+Max2 )/2
      scale                       2/( Max2-Min2 )
      rotate                    90*VectorCuadrantal.y*x
      rotate                    90*div( VectorCuadrantal.y, 4 )*y
      rotate                    90*div( VectorCuadrantal.y, 16 )*z
    }
    object                        {
      Objeto3                          
      translate                   -( Min3+Max3 )/2
      scale                       2/( Max3-Min3 )
      rotate                    90*VectorCuadrantal.z*x
      rotate                    90*div( VectorCuadrantal.z, 4 )*y
      rotate                    90*div( VectorCuadrantal.z, 16 )*z
    }
  }    
#end  // #macro BMME_IntersectionObjetos

#macro BMME_Aspas( LargoExteriorAspas, LargoInterior, DiametroSoporte,
                FraccionAspas, DiametroAspas, GruesoMetal, TexturaAspas )
  union                                 {
    difference                          {
      cylinder                          {
        0, LargoInterior*y,
        DiametroSoporte/2
      }
      torus                             {
        DiametroSoporte/2, GruesoMetal/2
        scale           <1,6,1>
        translate       +( LargoInterior-2*DiametroSoporte )*y
      }
      torus                             {
        DiametroSoporte/2, GruesoMetal/2
        scale           <1,6,1>
        translate       +LargoInterior*y
      }
    }
    cylinder                            {
      0, -LargoExteriorAspas*y,
      DiametroSoporte/2
    }
    cylinder                            {
      0, GruesoMetal*y,
      DiametroSoporte
    }
    #local FPrism                       = < DiametroAspas/2,
                  FraccionAspas*LargoExteriorAspas >;
    #local C                            = 0;
    #while ( C < 4 )
      difference                        {
        prism                             {
          bezier_spline
          -DiametroSoporte/2, DiametroSoporte/2,
          16,
          <0,0>*FPrism,
          <0.1,0.0>*FPrism,
          <1,0.0>*FPrism,
          <1,0.1>*FPrism,
          <1,0.1>*FPrism,
          <0.85,0.5>*FPrism,
          <0.85,0.5>*FPrism,
          <0.7,0.9>*FPrism,
          <0.7,0.9>*FPrism,
          <0.67,1.0>*FPrism,
          <0.1,1.0>*FPrism,
          <0.0,1.0>*FPrism,
          <0.0,1.0>*FPrism,
          <0.0,0.5>*FPrism,
          <0.0,0.5>*FPrism,
          <0,0.0>*FPrism
          scale 1
          rotate          90*x
        }
        #local FC               = 0.05*DiametroAspas;
        prism                             {
          bezier_spline
          -DiametroSoporte, DiametroSoporte,
          16,
          <0,0>*FPrism+FC*v,
          <0.1,0.0>*FPrism+FC*v,
          <1,0.0>*FPrism-FC*u,
          <1,0.1>*FPrism-FC*u,
          <1,0.1>*FPrism-FC*u,
          <0.85,0.5>*FPrism-FC*u,
          <0.85,0.5>*FPrism-FC*u,
          <0.7,0.9>*FPrism-FC*u,
          <0.7,0.9>*FPrism-FC*u,
          <0.67,1.0>*FPrism-FC*u,
          <0.1,1.0>*FPrism-FC*v,
          <0.0,1.0>*FPrism-FC*v,
          <0.0,1.0>*FPrism-FC*v,
          <0.0,0.5>*FPrism,
          <0.0,0.5>*FPrism+FC*v,
          <0,0.0>*FPrism+FC*v
          translate     -0.01*FC*x
          scale 1
          rotate          90*x
        }
        rotate          90*C*y
        translate               -LargoExteriorAspas*( 1-FraccionAspas )*y
      }
      #local C                          = C+1;
    #end  // #while ( C < 2 )
    texture                             {
      TexturaAspas
    }
  }
#end  // #macro BMME_Aspas

#macro BMME_BatidoraManualMotorizadaElectrica
      ( GiroAspas, LateralBatidora, FrenteBatidora, AltoBatidora,
        SeparacionAspas, FraccionPosAspas,
          LargoAspas, DiametroSoporte, FraccionAspas, DiametroAspas,
          TexturaPrincipal, TexturaDecorativa, TexturaTexto, TexturaMetalica )
  union                                 {
    #local InteriorAspas                = 0.318*LargoAspas;
    #local GruesoMetal                  = DiametroSoporte/4;
    #local UnaAspa                      =
      BMME_Aspas( LargoAspas, InteriorAspas, DiametroSoporte,
           FraccionAspas, DiametroAspas, GruesoMetal, TexturaMetalica )
    #local VNU  = <-1,-1,-1>;
    #local VU   = <1,1,1>;
    #local PosAspas                     = +SeparacionAspas/2*z
                        +( 0.5-FraccionPosAspas )*LateralBatidora*x;
    #local CuerpoBatidora               =
    union                              {
      #local MinLI                      =
        < BMME_LateralInferior_left,-1,BMME_LateralSuperior_top>;
      
      #local MaxLI                      =
        <BMME_LateralInferior_right,1,BMME_LateralInferior_bottom>;
      #local MinVI                      =
        < BMME_VistaInferior_left,-1,BMME_VistaInferior_top>;
      #local MaxVI                      =
        <BMME_VistaInferior_right,1,BMME_VistaInferior_bottom>;
      #local MinVF                      =
        < BMME_VistaFrontal_left,-1,BMME_VistaFrontal_top>;
      #local MaxVF                      =
        <BMME_VistaFrontal_right,1,BMME_VistaFrontal_bottom>;
      union                             {      
        object                          {
          BMME_IntersectionObjetos
            ( <1,0,1+4>,
              BMME_LateralInferior, MinLI, MaxLI,
              BMME_VistaInferior, MinVI, MaxVI,
              BMME_FrontalInferior, MinVF, MaxVF )
        }
        object                          {
          BMME_IntersectionObjetos
            ( <1,0,1+4>,
              BMME_LateralInferior, MinLI, MaxLI,
              BMME_VistaInferior, MinVI, MaxVI,
              BMME_FrontalInferior, MinVF, MaxVF )
          scale  <1,1,-1>
        }
        texture                 { TexturaPrincipal }
      }
      union                             {      
        object                          {
          BMME_IntersectionObjetos
            ( <1,0,1+4>,
              BMME_LateralSuperior, MinLI, MaxLI,
              BMME_VistaSuperior, MinVI, MaxVI,
              BMME_VistaFrontal, MinVF, MaxVF )
        }
        object                          {
          BMME_IntersectionObjetos
            ( <1,0,1+4>,
              BMME_LateralSuperior, MinLI, MaxLI,
              BMME_VistaSuperior, MinVI, MaxVI,
              BMME_VistaFrontal, MinVF, MaxVF )
          scale  <1,1,-1>
        }
        scale  <1,1,0.95>
        translate               -0.05*y+0.02*x
        texture                 { TexturaPrincipal }
      }
      union                             {      
        object                          {
          BMME_IntersectionObjetos
            ( <1,0,1+4>,
              BMME_LateralGris, MinLI, MaxLI,
              BMME_VistaSuperior, MinVI, MaxVI,
              BMME_VistaFrontal, MinVF, MaxVF )
        }
        object                          {
          BMME_IntersectionObjetos
            ( <1,0,1+4>,
              BMME_LateralGris, MinLI, MaxLI,
              BMME_VistaSuperior, MinVI, MaxVI,
              BMME_VistaFrontal, MinVF, MaxVF )
          scale  <1,1,-1>
        }
        texture                 { TexturaDecorativa }
      }
      scale  < LateralBatidora, AltoBatidora, FrenteBatidora >/2
    }
    
    difference                                          {
      object                                            {
        CuerpoBatidora
        translate       0.45*AltoBatidora*y
      }  
      cylinder                                          {
        -0.1*AltoBatidora*y, 0.1*AltoBatidora*y, 0.080*FrenteBatidora
        translate       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.6,0.825,-0.20>  
        texture         { TexturaPrincipal }
      } 
      cylinder                                          {
        -0.1*AltoBatidora*y, 0.1*AltoBatidora*y, 0.080*FrenteBatidora
        translate       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.6,0.825,+0.20>  
        texture         { TexturaPrincipal }
      } 
      cylinder                                          {
        -0.1*AltoBatidora*y, 0.1*AltoBatidora*y, 0.080*FrenteBatidora    
        scale           <1,1,2>
        translate       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.7,0.800,+0.00>  
        texture         { TexturaPrincipal }
      }   
      cone                                              {
        -InteriorAspas*y, 2*DiametroSoporte,
        InteriorAspas*y, 0
        translate               PosAspas
      }
      cone                                              {
        -InteriorAspas*y, 2*DiametroSoporte,
        InteriorAspas*y, 0
        translate               PosAspas*<1,1,-1>
      }
      cylinder                                          {
        -0.2*InteriorAspas*y, +0.2*InteriorAspas*y,
        DiametroSoporte/2
        translate       <LateralBatidora,0,FrenteBatidora>*<-0.4,0,+0.25>
      }
      cylinder                                          {
        -0.2*InteriorAspas*y, +0.2*InteriorAspas*y,
        DiametroSoporte/2
        translate       <LateralBatidora,0,FrenteBatidora>*<-0.4,0,-0.25>
      }
      cylinder                                          {
        -0.2*InteriorAspas*y, +0.2*InteriorAspas*y,
        DiametroSoporte/2
        translate       <LateralBatidora,0,FrenteBatidora>*<-0.0,0,+0.35>
      }
      cylinder                                          {
        -0.2*InteriorAspas*y, +0.2*InteriorAspas*y,
        DiametroSoporte/2
        translate       <LateralBatidora,0,FrenteBatidora>*<-0.0,0,-0.35>
      }
      box                                               {
        <-0.2*LateralBatidora,-0.2*InteriorAspas,-0.03*FrenteBatidora>,
        <-0.3*LateralBatidora,+0.2*InteriorAspas,+0.03*FrenteBatidora>
      }
      difference                                        {
        cone                                            {
          0.2*AltoBatidora*y, 0
          0.25*AltoBatidora*y, LateralBatidora
        }
        cone                                            {
          0.2*AltoBatidora*y, 0
          0.25*AltoBatidora*y, LateralBatidora
          translate     0.01*AltoBatidora*y
        }
      }
      difference                                        {
        union                                                   {
          #local C                                        = 0;
          #while ( C < 4 )
            box                                         {
              < -LateralBatidora, 0.45*AltoBatidora, -0.2*( 1+C/6 )*FrenteBatidora >,
              < -0.45*LateralBatidora, 0.425*AltoBatidora, +0.2*( 1+C/6 )*FrenteBatidora >
              translate         -0.05*C*AltoBatidora*y
            }
            
            #local C                              = C+1;
          #end  // #while ( C < 1 )
          #local C                                        = 0;
          #while ( C < 5 )
            box                                         {
              < +( 0.30-0.1*C/4 )*LateralBatidora, 0.5*AltoBatidora, -FrenteBatidora >,
              < +0.45*LateralBatidora, 0.475*AltoBatidora, -0.4*FrenteBatidora >
              translate         -0.05*C*AltoBatidora*y
            }
            
            #local C                              = C+1;
          #end  // #while ( C < 1 )
          #local C                                        = 0;
          #while ( C < 5 )
            box                                         {
              < -0.2700*LateralBatidora, 0.20*AltoBatidora, -FrenteBatidora >,
              < -0.2625*LateralBatidora, 0.10*AltoBatidora, -0.30*FrenteBatidora >
              translate         -0.05*C*AltoBatidora*x
            }
            
            #local C                              = C+1;
          #end  // #while ( C < 1 )
        }
        cylinder                                        {
          0, -LateralBatidora*x, 0.20*FrenteBatidora
          scale  <1,1,0.5>
          translate     0.35*AltoBatidora*y
        }
      }
      texture           { TexturaPrincipal }
    }
    union                                               {
      object                                            {
        UnaAspa
        rotate          GiroAspas*y
        translate               PosAspas
      }    
      object                                            {
        UnaAspa
        rotate          ( 45+GiroAspas )*y
        translate               PosAspas*<1,1,-1>
      }   
      superellipsoid                                    {
        <1.0,0.2>  
        rotate      90*x
        scale       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.075,0.1,0.075>
        translate       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.6,0.825,-0.20>  
        texture         { TexturaPrincipal }
      }
      superellipsoid                                    {
        <1.0,0.2>  
        rotate      90*x
        scale       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.075,0.1,0.075>
        translate       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.6,0.825,+0.20>  
        texture         { TexturaPrincipal }
      }
      superellipsoid                                    {
        <1.0,0.2>  
        rotate      90*x
        scale       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.075,0.1,0.15>
        translate       <FrenteBatidora,AltoBatidora,FrenteBatidora>*<0.7,0.800,+0.00>  
        texture         { TexturaPrincipal }
      }
      text                                              {
        ttf "crystal.ttf", BMME_StringLogo, 0.1, 0
        scale   0.10*AltoBatidora*<-1,1,1>
        texture                 { TexturaTexto }
        translate       +0.4375*FrenteBatidora*z+0.3*AltoBatidora*y
                        -0.05*LateralBatidora*x
      }
    }
  }
#end  // #macro BatidoraManualMotorizadaElectrica()

#macro BMME_Batidora( GiroAspas )
  object                                {
    #local L                            = BMME_L;
    #local LateralBatidora              = 127*L;
    #local FrenteBatidora               = 64*L;
    #local AltoBatidora                 = 94*L;
    #local SeparacionAspas              = 27*L;
    #local FraccionPosAspas             = 0.35;
    #local LargoAspas                   = 113*L;
    #local DiametroSoporte              = 3.6*L;
    #local FraccionAspas                = 0.516;
    #local DiametroAspas                = 27*L;
    
    BMME_BatidoraManualMotorizadaElectrica
      ( GiroAspas, LateralBatidora, FrenteBatidora, AltoBatidora,
        SeparacionAspas, FraccionPosAspas,
        LargoAspas, DiametroSoporte, FraccionAspas, DiametroAspas, 
        BMME_TexturaPrincipal, BMME_TexturaDecorativa,
        BMME_TexturaTexto, BMME_TexturaMetalica )
  }
#end  // #macro BMME_Batidora()

