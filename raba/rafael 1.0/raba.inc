// This file is licensed under the terms of the CC-LGPL.
//
// Autor  : Rafael Angel Campos Vargas
// Correo : RofoelCompos@hotmail.com  
// Apdo. 964-1250 Escazu, San Jose, Costa Rica
// dedicado a Jesus y Maria...
//
// En este momento estoy creando un programa
// de animacion LibreN3D para FreeDOS con el compilador FreePascal
// falta mucho... 29 mayo 2018
//                
// Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
// 1 L equivale a 0.055063 pulgadas 
// definido como 0.001 para POVRAY.
//     
// RABA RasuradoraAfeitarBarbaAcero
// El archivo dibuja una rasuradora simple con su navajilla.
// Puede cambiar algunas caracteristicas menores incluyendo su textura, pero
// es muy poco flexible. Es compatible con POVRay 3.1.
//
// La macro principal no tiene parametros.
// #macro RABA_Rasuradora()
//
// La siguiente macro permite un mayor control de las caracteristicas.
// #macro RABA_RasuradoraAfeitarBarbaAcero( LargoHoja, AnchoHoja, GruesoHoja,
//      DiametroPerforacion, LargoRasuradora, DiametroCilindro, GruesoDecorativo,
//      AltoCabeza, AltoCabezaInterno, LargoTornillo, 
//      TexturaPrincipal, TexturaMango, TexturaMetal, TexturaFilo, TexturaRanurada )
//          LargoHoja           : Lado largo de la navajilla plana.
//              Valor por defecto 30.9*L.
//          AnchoHoja           : Ancho de la navajilla plana.
//              Valor por defecto 16.3*L.
//          GruesoHoja          : Grosor de la navajilla.
//              Valor por defecto 0.1*L.
//          DiametroPerforacion : Diametro del tornillo sujetador.
//              Valor por defecto 3.5*L.
//          LargoRasuradora     : Largo del mango.
//              Valor por defecto 50.8*L.
//          DiametroCilindro    : Diametro del mango.
//              Valor por defecto 5.4*L.
//          GruesoDecorativo    : Valor de referencia para algunas curvas y decoraciones.
//              Valor por defecto 1*L.
//          AltoCabeza          : Referencia para el alto en Y de la cabeza de la rasuradora.
//              Valor por defecto 3.2*L.
//          AltoCabezaInterno   : Alto Y de la base interna de la navajilla. Debe ser menor
//              a AltoCabeza. Valor por defecto 1*L.
//          LargoTornillo       : Largo del tornillo sujetador.
//              Valor por defecto 6*L.          
//          TexturaPrincipal    : Textura principal de la rasuradora.
//              Valor por defecto RABA_TexturaPrincipal.
//          TexturaMango        : Textura para el rojo del mango.
//              Valor por defecto RABA_TexturaMango.
//          TexturaMetal        : Textura de la navajilla.
//              Valor por defecto RABA_TexturaMetal.
//          TexturaFilo         : Textura para el filo de la navajilla.
//              Valor por defecto RABA_TexturaFilo.
//          TexturaRanurada     : Textura en la base y cerca de los extremos laterales
//              de la navajilla. Valor por defecto RABA_TexturaRanurada.     
//      
// Se puede dibujar la navajilla en forma independiente con la siguiente macro.
// #macro RABA_Navajilla
//      ( LargoHoja, AnchoHoja, GruesoHoja, CurvaturaHoja,
//        DiametroPerforacion, FactorLargoHoja,
//        FactorAnchoHoja, DiametroCurvatura,
//        TexturaMetal, TexturaFilo )
//          LargoHoja           : Lado largo de la navajilla plana.
//              Valor por defecto 30.9*L.
//          AnchoHoja           : Ancho de la navajilla plana.
//              Valor por defecto 16.3*L.
//          GruesoHoja          : Grueso de la navajilla.
//              Valor por defecto 0.1*L.   
//          CurtaturaHoja       : Inverso del radio de curvatura de la hoja. Cero para plano.
//              Valor por defecto 1/(32.1*L) (division).  
//          DiametroPerforacion : Diametro del tornillo sujetador.
//              Valor por defecto 3.5*L.
//          FactorLargoHoja     : Fraccion referencia para medida de las ranuras a lo largo.
//              Valor por defecto 0.4265.
//          FactorAnchoHoja     : Fraccion referencia para medida de las ranuras a lo ancho.
//              Valor por defecto 0.2647.
//          DiametroCurvatura   : Diametro para las curvas en las ranuras.
//              Valor por defecto 0.085*AnchoHoja.
//          TexturaMetal        : Textura de la navajilla.
//              Valor por defecto RABA_TexturaMetal.
//          TexturaFilo         : Textura para el filo de la navajilla.
//              Valor por defecto RABA_TexturaFilo.
//
// El aparato se encuentra entre las siguientes dimensiones:
//      Minimo      = < -15.5, -51,  -8.5 >*L
//      Maximo      = <  15.5,   3,  +8.5 >*L
//      Minimo      = < -LargoHoja/2, -LargoRasuradora, -0.55*AnchoHoja >
//      Maximo      = < +LargoHoja/2,      +AltoCabeza, +0.55*AnchoHoja >
// El objeto es simetrico respecto a los planos YZ y XY. El mango comienza en el origen.
//
// Estas son variables predefinidas o generadas en el
// interior de las macros que no deberian modificarse directamente.
// Si quiere cambiarlas, recurra a los modificadores.  
// #declare RABA_DefectoTexturaPrincipal  
//      Textura principal del aparato.
// #declare RABA_DefectoTexturaMango
//      Textura para el rojo del mango.
// #declare RABA_DefectoTexturaMetal  
//      Textura de la navajilla.
// #declare RABA_DefectoTexturaFilo
//      Textura del filo de la navajilla.
// #declare RABA_DefectoTexturaRanurada
//      Textura en la base y cerca de los extremos laterales de la navajilla.
//
// Los siguientes son los modificadores
// aplicables y redefinibles por el usuario (si se indica es default)
// #declare RABA_TransformCabeza           = transform     { }
//      Permite un desplazamiento adicional de la cabeza de la rasuradora.
// #declare RABA_TransformNavajilla        = transform     { }
//      Permite un desplazamiento adicional de la navajilla.
// #declare RABA_TransformBaseInterior     = transform     { }
//      Permite un desplazamiento adicional de la base de la navajilla.
// #declare RABA_TransformMango            = transform     { }
//      Permite un desplazamiento adicional del mango.
// #declare RABA_FactorCurvaturaNavajilla  = 1.0;     
//      Para cambiar la curvatura de la navajilla. Su valor es inverso
//      al radio de curvatura, por tanto, al aumentar disminuye el radio asociado.
//      Como regla excepcional, utilice 0.0 para plano.
// #declare RABA_TexturaPrincipal          = texture   { ... } 
//      Textura principal del aparato.
// #declare RABA_DefectoTexturaMango       = texture   { ... } 
//      Textura para el rojo del mango.
// #declare RABA_TexturaMetal              = texture   { ... } 
//      Textura de la navajilla.
// #declare RABA_TexturaFilo               = texture   { ... } 
//      Textura del filo de la navajilla.
// #declare RABA_TexturaRanurada           = texture   { ... } 
//      Textura en la base y cerca de los extremos laterales de la navajilla.
//        
// Para colocarlo simplemente
// #include "RABA.inc" 
// object { RABA_Rasuradora() }
//                                  
// Ejemplo con la macro detallada, mismo objeto default
// #include "RABA.inc"   
// object                       {
//   RABA_RasuradoraAfeitarBarbaAcero( 0.0309, 0.0163, 0.0001,
//          0.0035, 0.0508, 0.0054, 0.001, 0.0032, 0.001, 0.006,
//          RABA_TexturaPrincipal, RABA_TexturaMango, 
//          RABA_TexturaMetal, RABA_TexturaFilo, RABA_TexturaRanurada )
// }
//        
// Con modificadores
// #include "RABA.inc"
// #include "textures.inc"
// #declare RABA_TexturaPrincipal   = texture { PinkAlabaster } 
// object        { RABA_Rasuradora( ) }
//                      

#include "metals.inc"
#include "colors.inc"
#declare RABA_L                         = 0.001;  

#declare RABA_TransformCabeza           = transform     { }
#declare RABA_TransformNavajilla        = transform     { }
#declare RABA_TransformBaseInterior     = transform     { }
#declare RABA_TransformMango            = transform     { }

#declare RABA_FactorCurvaturaNavajilla  = 1.0;

#declare RABA_DefectoTexturaMetal       =
  texture                               {
    T_Chrome_2A
    normal              {
      bumps
    }
  }

#ifndef ( RABA_TexturaMetal )
  #declare RABA_TexturaMetal            = RABA_DefectoTexturaMetal
#end  // #ifndef ( RABA_TexturaMetal )

#declare RABA_DefectoTexturaFilo        =
  texture                               {
    T_Chrome_3B
    normal                              {
      bumps
    }
  }

#ifndef ( RABA_TexturaFilo )
  #declare RABA_TexturaFilo             = RABA_DefectoTexturaFilo
#end  // #ifndef ( RABA_TexturaFilo )

#declare RABA_DefectoTexturaPrincipal   =
  texture                               {
    T_Chrome_1C
    normal              {
      bumps
    }
  }

#ifndef ( RABA_TexturaPrincipal )
  #declare RABA_TexturaPrincipal        = RABA_DefectoTexturaPrincipal
#end  // #ifndef ( RABA_TexturaPrincipal )

#declare RABA_DefectoTexturaRanurada    =
  texture                               {
    T_Chrome_1C
    normal              {
      gradient  x
      scale RABA_L/5
    }
  }

#ifndef ( RABA_TexturaRanurada )
  #declare RABA_TexturaRanurada         = RABA_DefectoTexturaRanurada
#end  // #ifndef ( RABA_TexturaRanudara )

#declare RABA_DefectoTexturaMango       =
  texture                               {
    pigment                             {
      Red
    }
    normal                              {
      agate
    }
  }

#ifndef ( RABA_TexturaMango )
  #declare RABA_TexturaMango            = RABA_DefectoTexturaMango
#end  // #ifndef ( RABA_TexturaMango )

#macro RABA_Navajilla
      ( LargoHoja, AnchoHoja, GruesoHoja, CurvaturaHoja,
        DiametroPerforacion, FactorLargoHoja,
        FactorAnchoHoja, DiametroCurvatura,
        TexturaMetal, TexturaFilo )
  difference                            {
    #local FLH                  = FactorLargoHoja;
    #local FAH                  = FactorAnchoHoja;
    #local DC                       = DiametroCurvatura;
    #if ( CurvaturaHoja = 0 )
      box                               {
        < -LargoHoja/2, -GruesoHoja/2, -AnchoHoja/2 >,
        < +LargoHoja/2, +GruesoHoja/2, +AnchoHoja/2 >
      }
    #else //  #if ( CurvaturaHoja = 0 )
      difference                        {
        cylinder                        {
          -LargoHoja/2*x, +LargoHoja/2*x, 1/CurvaturaHoja+GruesoHoja/2
        }
        cylinder                        {
          -LargoHoja*x, +LargoHoja*x, 1/CurvaturaHoja-GruesoHoja/2
        }
        #local RH                       = max( 1/CurvaturaHoja, LargoHoja );
        box                             {
          -2*RH,
          < 2, 0, 2 >*RH
          rotate                        ( 90-AnchoHoja*CurvaturaHoja*90/pi )*x
        }
        box                             {
          -2*RH,
          < 2, 0, 2 >*RH
          rotate                       -( 90-AnchoHoja*CurvaturaHoja*90/pi )*x
        }
        translate               -1/CurvaturaHoja*y
      }
    #end  //  #if ( CurvaturaHoja = 0 )
    // Muescas Laterales
    #local C                        = 0;
    #while ( C < 4 )
      union                         {
        box                         {
          < LargoHoja*FLH, -LargoHoja, AnchoHoja*FAH >,
          LargoHoja
        }
        cylinder                        {
          -AnchoHoja*y, +AnchoHoja*y, DC/2
          translate             FLH*LargoHoja*x+FAH*AnchoHoja*z+DC/2*z
        }
        scale               < -1+2*mod( C, 2 ), 1, -1+2*div ( C,2 ) >
      }
      #local C                      = C+1;
    #end  // #while ( C < 4 )
    // END MuescasLaterales
    // Muescas Internas
    #local GrosorInterno                = DiametroPerforacion/3;
    cylinder                            {
      -AnchoHoja*y, AnchoHoja*y, DiametroPerforacion/2
    }
    #local LargoInterno                 = 2*FLH*LargoHoja-DC;
    box                                 {
      < -LargoInterno/2, -AnchoHoja, -GrosorInterno/2 >,
      < +LargoInterno/2, +AnchoHoja, +GrosorInterno/2 >
    }
    #local C                            = 0;
    #while ( C < 2 )
      union                             {
        superellipsoid                  {
          <0.5,0.5>
          scale  < DC/2, AnchoHoja, DiametroPerforacion/2 >
          translate             ( LargoInterno/2-DC/2 )*x
        }
        superellipsoid                        {
          <0.3,0.3>
          rotate                45*y
          scale                 DiametroPerforacion/2
          translate             ( LargoInterno/2-DC-DiametroPerforacion/2 )*x
        }
        superellipsoid                  {
          <0.5,0.5>
          scale  < DC/2, AnchoHoja, DiametroPerforacion/2 >
          translate             ( LargoInterno/2-DC/2 )*x
          translate                     -DiametroPerforacion*x-DC*x
        }
        #if ( C = 1 )
          scale                   <-1,1,1>
        #end  // #if ( C = 1 )
      }
      #local C                          = C+1;
    #end  // #while ( C < 2 )
    // END Muescas Internas
    texture                             {
       gradient         z
       scale            AnchoHoja
       triangle_wave
       texture_map                      {
         [0.9 TexturaMetal ]
         [0.9 TexturaFilo  ]
       }
    }
  }
#end  // #macro RABA_Navajilla()

#macro RABA_MangoNavajilla
        ( LargoRasuradora, DiametroCilindro, GruesoDecorativo,
          TexturaPrincipal, TexturaMango )
  union                                 {
    #local FraccionRojo                 = 0.607;
    difference                          {
      sphere                            {
        0, DiametroCilindro/2
      }
      plane                             {
        y, 0
      }
    }
    sphere                              {
      0, DiametroCilindro/2
      translate         ( DiametroCilindro/2+GruesoDecorativo )*y
    }
    cylinder                            {
      0, GruesoDecorativo*y, DiametroCilindro/2
      translate         DiametroCilindro*y
    }
    // Arriba
    difference                          {
      torus                               {
        DiametroCilindro/2-GruesoDecorativo/2, GruesoDecorativo/2
      }
      plane                                     {
        y, 0
      }
      translate         ( LargoRasuradora-GruesoDecorativo/2 )*y
    }
    union                               {
      cylinder                            {
        0, GruesoDecorativo*y, DiametroCilindro/2
      }
      cylinder                            {
        0, 2*GruesoDecorativo*y, DiametroCilindro/2-GruesoDecorativo/2
      }
      translate         ( DiametroCilindro+GruesoDecorativo+
                                FraccionRojo*LargoRasuradora )*y
    }
    difference                          {
      #local LargoCurvo                 = ( ( 1-FraccionRojo )*LargoRasuradora-DiametroCilindro
                        -3.5*GruesoDecorativo );
      cylinder                          {
        0, LargoCurvo*y, DiametroCilindro/2
      }
      torus                             {
        DiametroCilindro/2, GruesoDecorativo
        scale           <1,LargoCurvo/GruesoDecorativo/2,1>
        translate               LargoCurvo*y/2
      }
      translate         ( DiametroCilindro+3*GruesoDecorativo+
                                FraccionRojo*LargoRasuradora )*y
    }
    // Mango
    union                               {
      cylinder                          {
        0, FraccionRojo*LargoRasuradora*y, DiametroCilindro/2-GruesoDecorativo/2
      }
      #local C                          = 0;
      #local TotalOndulado              = 15;
      #while ( C < TotalOndulado )
        cylinder                                {
          0, FraccionRojo*LargoRasuradora*y, GruesoDecorativo/2
          translate             ( DiametroCilindro/2-GruesoDecorativo/2 )*x
          rotate                C*360*y/TotalOndulado
        }
        #local C                        = C+1;
      #end  // #while ( C < TotalOndulado )
      texture                            {
        TexturaMango
      }
      translate         ( DiametroCilindro+GruesoDecorativo )*y
    }
    // END Mango
    translate                           -LargoRasuradora*y
    texture                             {
      TexturaPrincipal
    }
  }
#end  // #macro RABA_MangoNavajilla

#macro RABA_CabezaRasuradora
        ( LargoCabeza, AnchoCabeza, AltoCabeza, AltoCabezaInterno,
          DiametroTornillo, LargoTornillo, FactorLargoHoja,
          TexturaPrincipal )
  union                                 {
    #local RadioCabeza                  = AnchoCabeza*AnchoCabeza
        /( 8*AltoCabeza )+AltoCabeza/2;
    #local RadioCabezaInterno           = AnchoCabeza*AnchoCabeza
        /( 8*AltoCabezaInterno )+AltoCabezaInterno/2;
    difference                          {
      cylinder                          {
        -LargoCabeza/2*x, +LargoCabeza/2*x, RadioCabeza
        translate               -( RadioCabeza-AltoCabeza )*y
      }
      cylinder                          {
        -LargoCabeza*x, LargoCabeza*x, RadioCabezaInterno
        translate               -( RadioCabezaInterno-AltoCabezaInterno )*y
      }
      plane                             {
        y, 0
      }
    }
    #local PasoTornillo                  = 0.08*LargoTornillo;
    difference                          {
      cylinder                          {
        0, -LargoTornillo*y, DiametroTornillo/2
      }
      #local PosT                       = AltoCabezaInterno+PasoTornillo/2;
      #while ( PosT < LargoTornillo )
        torus                           {
          DiametroTornillo/2, 0.4*PasoTornillo
          translate             -PosT*y
        }
        #local PosT                     = PosT+PasoTornillo;
      #end
      translate                 AltoCabezaInterno*y
    }
    cylinder                        {
      -0.7*DiametroTornillo*x, 0.7*DiametroTornillo*x, DiametroTornillo/6
      translate                 AltoCabezaInterno*y
    }    
    #local C                            = 0;
    #while ( C < 2 )
      union                             {
        cylinder                        {
          0, -LargoTornillo/3*y, DiametroTornillo/2
        }
        cone                            {
          -LargoTornillo/3*y, DiametroTornillo/2,
          -2*LargoTornillo/3*y, 0
        }
        cylinder                        {
          -0.7*DiametroTornillo*x, 0.7*DiametroTornillo*x, DiametroTornillo/6
        }
        translate               0.725*FactorLargoHoja*LargoCabeza*x
        translate               AltoCabezaInterno*y
        #if ( C = 1 )
          scale                 <-1,1,1>
        #end  // #if ( C = 1 )
      }
      #local C                          = C+1;
    #end  // #while ( C < 2 )
    texture                             {
      TexturaPrincipal
    }
  }
#end  // #macro RABA_CabezaRasuradora

#macro RABA_IntermedioRasuradora
        ( LargoCabeza, AnchoCabeza, GruesoHoja, AltoCabeza, AltoCabezaInterno,
          DiametroTornillo, LargoTornillo, FactorLargoHoja, GruesoDecorativo,
          TexturaPrincipal, TexturaRanurada )
  union                                         {
    #local RadioGuia                            =
        AnchoCabeza*AnchoCabeza/( 8*AltoCabezaInterno )
        +AltoCabezaInterno/2;
    #local RadioExterno                         =
        AnchoCabeza*AnchoCabeza/( 8*AltoCabeza )
        +AltoCabeza/2;
    difference                                  {
      cylinder                                  {
        -LargoCabeza/2*x, +LargoCabeza/2*x, RadioGuia
        translate               -( RadioGuia-AltoCabezaInterno+2*GruesoHoja )*y
      }   
      cylinder                                  {
        -LargoCabeza*x, LargoCabeza*x, RadioExterno
        inverse
        translate               -( RadioExterno-AltoCabeza )*y
      }      
      difference                                {
        cylinder                                  {
          -LargoCabeza*x, LargoCabeza*x, RadioExterno-AltoCabezaInterno/2
          translate               -( RadioExterno-AltoCabeza )*y
        }
        box                                       {
          < -2*LargoCabeza, LargoCabeza, -0.449*AnchoCabeza >,
          < +2*LargoCabeza, -LargoCabeza, +0.449*AnchoCabeza >
        }
      }        
      box                                       {
        < -LargoCabeza, 0, -0.45*AnchoCabeza >,
        < +LargoCabeza, -LargoCabeza, +0.45*AnchoCabeza >
      }  
      #local C                                  = 0;
      #while ( C < 2 )
        union                                   {
          box                                   {
            < 0.45*LargoCabeza, -AnchoCabeza, -GruesoDecorativo/2 >,
            < 0.10*LargoCabeza, +AnchoCabeza, +GruesoDecorativo/2 >
          }
          box                                   {
            <-0.45*LargoCabeza, -AnchoCabeza, -GruesoDecorativo/2 >,
            <-0.10*LargoCabeza, +AnchoCabeza, +GruesoDecorativo/2 >
          }  
          cylinder                              {
            -LargoCabeza*x, +LargoCabeza*x, GruesoDecorativo/8
            scale               <1,2,2>
            texture                     { TexturaRanurada }
          }   
          translate                     AnchoCabeza/2*z
          #if ( C = 1 )
            scale                       <1,1,-1>
          #end  // #if ( C = 1 )
        }
        #local C                                = C+1;
      #end  //  #while ( C < 2 )
      plane                                     {
        y, -0.05*AnchoCabeza
      }   
      difference                                {  
        superellipsoid                            {
          <0.2,0.2>
            scale  < LargoCabeza*0.4, AltoCabezaInterno*0.3, AnchoCabeza*0.3 >
        }                                          
        superellipsoid                            {
          <0.2,0.2>
            scale  < LargoCabeza*0.3, AltoCabezaInterno*0.3, AnchoCabeza*0.2 >
            translate           AltoCabezaInterno*0.3*y
        }                                          
      }     
      superellipsoid                            {
        <0.2,0.2>
        scale  < LargoCabeza*0.225, AltoCabezaInterno*0.3, AnchoCabeza*0.25 >
        translate           AltoCabezaInterno*y
      }                                          
      cylinder                          {
        LargoTornillo*y, -LargoTornillo*y, 1.05*DiametroTornillo/2
      }
      cylinder                        {
        LargoTornillo*y, -LargoTornillo*y, 1.05*DiametroTornillo/2
        translate               +0.725*FactorLargoHoja*LargoCabeza*x
      }  
      cylinder                        {
        LargoTornillo*y, -LargoTornillo*y, 1.05*DiametroTornillo/2
        translate               -0.725*FactorLargoHoja*LargoCabeza*x
      }  
    }
    texture                                     {
      TexturaPrincipal
    }
  }
#end  // #macro RABA_IntermedioRasuradora 

#macro RABA_RasuradoraAfeitarBarbaAcero( LargoHoja, AnchoHoja, GruesoHoja,
    DiametroPerforacion, LargoRasuradora, DiametroCilindro, GruesoDecorativo,
    AltoCabeza, AltoCabezaInterno, LargoTornillo, 
    TexturaPrincipal, TexturaMango, TexturaMetal, TexturaFilo, TexturaRanurada )
  union                                 {
    #local FactorLargoHoja              = 0.4265;
    #local FactorAnchoHoja              = 0.2647;
    #local DiametroCurvatura            = 0.085*AnchoHoja;
    #local LargoCabeza                  = 0.941*LargoHoja;
    #local AnchoCabeza                  = 0.975*AnchoHoja;
    #local DiametroTornillo             = 0.97*DiametroPerforacion;
    #local CurvaturaHoja                = AnchoCabeza*AnchoCabeza/( 8*AltoCabezaInterno )
        +AltoCabezaInterno/2;
    #local CurvaturaHoja                = RABA_FactorCurvaturaNavajilla/CurvaturaHoja;
    object                              {
      RABA_Navajilla
        ( LargoHoja, AnchoHoja, GruesoHoja, CurvaturaHoja,
          DiametroPerforacion, FactorLargoHoja,
          FactorAnchoHoja, DiametroCurvatura,
          TexturaMetal, TexturaFilo )
      translate         ( AltoCabezaInterno+GruesoHoja )*y
      transform   RABA_TransformNavajilla 
    }

    object                              {
      RABA_MangoNavajilla
        ( LargoRasuradora, DiametroCilindro, GruesoDecorativo,
          TexturaPrincipal, TexturaMango )
      transform   RABA_TransformMango 
    }
    object                              {
      RABA_CabezaRasuradora
        ( LargoCabeza, AnchoCabeza, AltoCabeza, AltoCabezaInterno,
          DiametroTornillo, LargoTornillo, FactorLargoHoja,
          TexturaPrincipal )
      transform     RABA_TransformCabeza 
    }
    object                              {
      RABA_IntermedioRasuradora
        ( LargoCabeza, AnchoCabeza, GruesoHoja, AltoCabeza, AltoCabezaInterno,
          DiametroTornillo, LargoTornillo, FactorLargoHoja, GruesoDecorativo,
          TexturaPrincipal, TexturaRanurada )
      transform       RABA_TransformBaseInterior 
    }
  }
#end  // #macro RABA_RasuradoraAfeitarBarbaAcero() 

#macro RABA_Rasuradora()
  object                                {
    #local L                            = RABA_L;
    #local LargoHoja                    = 30.9*L;
    #local AnchoHoja                    = 16.3*L;
    #local GruesoHoja                   =  0.1*L;
    #local DiametroPerforacion          = 3.5*L;
    #local LargoRasuradora              = 50.8*L;
    #local DiametroCilindro             =  5.4*L;
    #local GruesoDecorativo             = 1*L;
    #local AltoCabeza                   = 3.2*L;
    #local AltoCabezaInterno            = 1*L;
    #local LargoTornillo                = 6*L;
    RABA_RasuradoraAfeitarBarbaAcero( LargoHoja, AnchoHoja, GruesoHoja,
        DiametroPerforacion, LargoRasuradora, DiametroCilindro, GruesoDecorativo,
        AltoCabeza, AltoCabezaInterno, LargoTornillo,
        RABA_TexturaPrincipal, RABA_TexturaMango, 
        RABA_TexturaMetal, RABA_TexturaFilo, RABA_TexturaRanurada )
  }
#end  // RABA_Rasuradora()
