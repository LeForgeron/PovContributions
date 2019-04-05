// This file is licensed under the terms of the CC-LGPL.
//
// Autor  : Rafael Angel Campos Vargas
// Correo : RofoelCompos@hotmail.com  
// Apdo. 964-1250 Escazu, San Jose, Costa Rica
// dedicado a Jesus y Maria...
//
// En este momento estoy creando un programa
// de animacion LibreN3D para FreeDOS con el compilador FreePascal
// falta mucho... 15 mayo 2018
//                
// Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
// 1 L equivale a 0.055063 pulgadas 
// definido como 0.001 para POVRAY.
//     
// PIFC PeladorInoxidableFiloCortante
// El archivo dibuja un pelador de verduras para cocina.
// La cuchilla puede desplazarse levemente similar al modelo original. 
// Es muy poco flexible. Es compatible con POVRay 3.1.
//
// La macro principal tiene dos parametros.
// #macro PIFC_Pelador( RotateFilo, FraccionAvance )
//          RotateFilo          : Vector para rotar las navajas.
//          FraccionAvance      : Fraccion propia que permite un 
//                  desplazamiento leve de las cuchillas.
//        
// La siguiente macro permite un mayor control de las caracteristicas.
// #macro PIFC_PeladorInoxidableFiloCortante
//            ( RotateFilo, FraccionAvance,
//              DimensionesMango, LargoFilo, AnchoFilo, AberturaFilo, 
//              DiametroBaseFilo, ExcesoFilo, GruesoMetal,
//              TexturaMetalica, TexturaFilo, TexturaMango )
//          RotateFilo          : Vector para rotar las aspas de la batidora.
//          FraccionAvance      : Fraccion propia que permite un 
//                  desplazamiento leve de las cuchillas.
//          DimensionesMango    : Vector 3D, para dar tamano al mango.
//                  Valor por defecto <81.7,18.0,13.6>*L.
//          LargoFilo           : Largo total de la cuchilla.
//                  Valor por defecto 46.31*L.
//          AnchoFilo           : Ancho de la cuchilla.
//                  Valor por defecto 8.2*L.
//          AberturaFilo        : Ancho de la abertura del pelador.
//                  Valor por defecto 3.6*L.
//          DiametroBaseFilo    : Diametro del cilindro en la base de la cuchilla.
//                  Valor por defecto 4.5*L.
//          ExcesoFilo          : Corresponde al desplazamiento maximo de la cuchilla
//                  como si el parametro FraccionAvance fuera unitario.
//                  Valor por defecto 1.8*L.
//          GruesoMetal         : Grueso de las laminillas de metal.
//                  Valor por defecto 0.2*L. 
//          TexturaMetalica     : Textura de las hojas de metal.
//                  Valor por defecto PIFC_TexturaMetalica.
//          TexturaFilo         : Textura del filo.
//                  Valor por defecto PIFC_TexturaFilo.
//          TexturaMango        : Textura del mango.
//                  Valor por defecto PIFC_TexturaMango.
//
// El pelador con parametros nulos se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -82,   -9,  -14 >*L
//      Maximo      = <  +46,   +9,  +14 >*L
//      Minimo      = < -DimensionMango.x, -DimensionMango.y/2, -DimensionMango.z/2 >
//      Maximo      = < LargoFilo, +DimensionMango.y/2, +DimensionMango.z/2 >
// El frente del objeto mira hacia  X+, es casi simetrico con respectro al
// plano XY.
//
// Estas son variables predefinidas o generadas en el
// interior de las macros que no deberian modificarse directamente.
// Si quiere cambiarlas, recurra a los modificadores.  
// #declare PIFC_DefectoTexturaMetalica  
//      Textura de las hojas de metal.
// #declare PIFC_DefectoTexturaFilp
//      Textura del filo.
// #declare PIFC_DefectoTexturaMango
//      Textura del mango.
//
// Los siguientes son los modificadores
// aplicables y redefinibles por el usuario (si se indica es default)   
// #declare PIFC_FactorCorreccionCortante   = 1.6;
//      Este parametro existe como medida de precaucion. Es posible
//      que al variar los parametros el filo quede mal acomodado.
//      Se espera que la modificacion de este parametro ayude al usuario 
//      a mitigar el problema.
// #declare PIFC_Marca                      = "POV-Ray"
//      Mensaje del logo de marca.
// #declare PIFC_ScaleMarca                 = <1,1,1>;   
//      Modifica el escalamiento de la marca.
// #declare PIFC_TranslateMarca             = <0,0,0>;
//      Traslada el mensaje de marca, en unidades relativas a las dimensiones del mango.
// #declare PIFC_TexturaMetalica            =
//                  { PIFC_DefectoTexturaMetalica       }
//      Textura de las hojas de metal.
// #declare PIFC_TexturaFilo                =
//                  { PIFC_DefectoTexturaFilo           }
//      Textura del filo.
// #declare PIFC_TexturaMango               =
//                  { PIFC_DefectoTexturaMango          }
//      Textura del mango.
//       
// Para colocarlo simplemente
// #include "BMMD.inc" 
// object { PIFC_Pelador( <0,0,0>, 0 ) }
//                                  
// Ejemplo con la macro detallada, mismo objeto default
// #include "PIFC.inc"   
// object                       {
//   PIFC_PeladorInoxidableFiloCortante
//        ( <0,0,0>, 0, <0.0817,0.018,0.0136>, 0.04631,
//          0.0082, 0.0036, 0.0045, 0.0018, 0.0002, 
//          PIFC_TexturaMetalica, PIFC_TexturaFilo, PIFC_TexturaMango )
// }
//        
// Con modificadores
// #include "PIFC.inc"
// #include "textures.inc"
// #declare PIFC_TexturaPrincipal   = texture { PinkAlabaster } 
// object        { PIFC_Pelador( <0,0,0>, 0 ) }
//
#include "metals.inc" 
#include "colors.inc"
#include "stones.inc"

#declare PIFC_L                         = 0.001;

#declare PIFC_FactorCorreccionCortante  = 1.6;

#declare PIFC_Marca                     = "POV-Ray"
#declare PIFC_ScaleMarca                = <1,1,1>;   
#declare PIFC_TranslateMarca            = <0,0,0>;

#declare PIFC_DefectoTexturaMetalica    =
  texture                               {
    T_Chrome_2A
    normal              {
      bumps   
      scale 0.1
    }  
    finish                  {
      phong  0.5
      phong_size 10
    }
  }

#ifndef ( PIFC_TexturaMetalica )
  #declare PIFC_TexturaMetalica         = PIFC_DefectoTexturaMetalica
#end  // #ifndef ( PIFC_TexturaMetalica )

#declare PIFC_DefectoTexturaFilo        =
  texture                               {
    T_Chrome_4C
    normal                              {
      bumps
    }
  }

#ifndef ( PIFC_TexturaFilo )
  #declare PIFC_TexturaFilo             = PIFC_DefectoTexturaFilo
#end  // #ifndef ( PIFC_TexturaFilo )

#declare PIFC_DefectoTexturaMango       =
  texture                               {
    T_Stone36
    normal                              {
      bumps
    }
  }

#ifndef ( PIFC_TexturaMango )
  #declare PIFC_TexturaMango            = PIFC_DefectoTexturaMango
#end  // #ifndef ( PIFC_TexturaMango )

#macro PIFC_PeladorInoxidableFiloCortante
        ( RotateFilo, FraccionAvance, DimensionesMango,
          LargoFilo, AnchoFilo, AberturaFilo, 
          DiametroBaseFilo, ExcesoFilo, GruesoMetal, 
          TexturaMetalica, TexturaFilo, TexturaMango )
  union                                 {
    #local EjeXRotacion                 = 0;
    // Mango
    difference                          {
      intersection                      {
        superellipsoid                  {
          <0.35,0.7>
          scale         DimensionesMango*<1,0.5,0.5>
        }
        sphere                          {
          0,    0.51*DimensionesMango.x
          translate     -0.51*DimensionesMango.x*x
        }
      }
      difference                        {
        sphere                          {
          0,    0.45*DimensionesMango.x
          translate     -0.51*DimensionesMango.x*x
        }
        sphere                          {
          0,    0.44*DimensionesMango.x
          translate     -0.51*DimensionesMango.x*x
        }
        superellipsoid                  {
          <0.35,0.7>
          scale         DimensionesMango*<1,0.5,0.5>*<1,0.95,0.95>
        }
      }
      cylinder                          {
        -DimensionesMango.z*z, +DimensionesMango.z*z,
        0.175*DimensionesMango.y
        translate               -0.9*DimensionesMango.x*x
      }
      box                               {
        <0,-1,-1>,1
        scale           0.175*DimensionesMango.y*<1,1,0>+z*DimensionesMango.z
        translate               -0.9*DimensionesMango.x*x
      }
      union                             {
        cylinder                          {
          -DimensionesMango.z*z, +DimensionesMango.z*z,
          0.175*DimensionesMango.y
        }
        box                               {
          <-1.1,-1,-1>,<0,1,1>
          scale           0.175*DimensionesMango.y*<1,1,0>+z*DimensionesMango.z
        }
        scale  <1,1,-1>
        translate              ( -0.9*DimensionesMango.x+
                                2*   0.175*DimensionesMango.y )*x
                        -1.25*DimensionesMango.z*z
      }
      union                             {
        cylinder                          {
          -DimensionesMango.z*z, +DimensionesMango.z*z,
          0.175*DimensionesMango.y
        }
        box                               {
          <-8.1,-1,-1>,<0,1,1>
          scale           0.175*DimensionesMango.y*<1,1,0>+z*DimensionesMango.z
        }
        
        translate              ( -0.9*DimensionesMango.x+
                                9*   0.175*DimensionesMango.y )*x
                        -1.25*DimensionesMango.z*z
      }
      texture                           {
        TexturaMango
      }
    }
    // END Mango
    // Filo
    union                               {
      difference                        {
        cylinder                        {
          0, -3*ExcesoFilo*x, DiametroBaseFilo/2
        }
        cylinder                        {
          ExcesoFilo*x, -4*ExcesoFilo*x, DiametroBaseFilo/2-GruesoMetal
        }
      }
      cone                              {
        0, DiametroBaseFilo/2,
        0.05*LargoFilo*x, 0
      }
      #local FactorCurvo                = 1.5;
      difference                        {
        intersection                    {
          cylinder                      {
            0, LargoFilo*x, FactorCurvo*AnchoFilo/2
          }
          union                         {
            superellipsoid              {
              <0.5,0.5>
              scale             <0.8*LargoFilo/2,AnchoFilo/2,LargoFilo>
            }
            superellipsoid              {
              <0.5,0.5>
              scale             <LargoFilo/2,DiametroBaseFilo/2,LargoFilo>
            }
            translate           LargoFilo*x/2
          }
        }
        box                             {
           -1, 1
           scale             <0.6*LargoFilo/2,AberturaFilo/2,LargoFilo>
           translate            LargoFilo*x/2
        }
        cylinder                        {
          -LargoFilo*z, LargoFilo*z, AberturaFilo/2
          translate     0.2*LargoFilo*x
        }
        cylinder                        {
          -LargoFilo*z, LargoFilo*z, AberturaFilo/2
          translate     0.8*LargoFilo*x
        }
        difference                      {
          cylinder                      {
            0.2*LargoFilo*x, 0.8*LargoFilo*x, AnchoFilo
          }
          cylinder                        {
            -0.1*LargoFilo*x,+0.9*LargoFilo*x,
            0.5*AnchoFilo-GruesoMetal
          }
          texture                       {
            TexturaFilo
          }
          scale  <1,PIFC_FactorCorreccionCortante,1>
          translate             -( FactorCurvo-1 )*AnchoFilo/2*z
        }
        cylinder                        {
          -LargoFilo*x, 1.1*LargoFilo*x, FactorCurvo*AnchoFilo/2-GruesoMetal
        }
        plane                           {
          -z, 0
        }
        translate                       FactorCurvo*AnchoFilo/2*z
      }
      texture                           {
        TexturaMetalica
      }
      translate         -EjeXRotacion*x
      rotate            RotateFilo
      translate         +EjeXRotacion*x
      translate         FraccionAvance*ExcesoFilo*x
    }
    // END Filo
    text                                {
      ttf "crystal.ttf", PIFC_Marca, 1, 0
      scale             DimensionesMango*<0.075,0.2,0.1>*PIFC_ScaleMarca
      translate         DimensionesMango*<-0.8,-0.1,-0.35>  
      translate         DimensionesMango*PIFC_TranslateMarca
    }
    texture                     {
      TexturaMango
    }
  }
#end  // #macro PIFC_PeladorInoxidableFiloCortante()

#macro PIFC_Pelador( RotateFilo, FraccionAvance )
  object                                {
    #local L                            = PIFC_L;
    #local DimensionesMango             =
                < 81.7, 18, 13.6 >*L;
    #local LargoFilo                    = 46.31*L;
    #local AnchoFilo                    = 8.2*L;
    #local AberturaFilo                 = 3.6*L;
    #local DiametroBaseFilo             = 4.5*L;
    #local ExcesoFilo                   = 1.8*L;
    #local GruesoMetal                  = 0.2*L;
    PIFC_PeladorInoxidableFiloCortante
        ( RotateFilo, FraccionAvance, DimensionesMango, 
          LargoFilo, AnchoFilo, AberturaFilo, 
          DiametroBaseFilo, ExcesoFilo, GruesoMetal, 
          PIFC_TexturaMetalica, PIFC_TexturaFilo, PIFC_TexturaMango )
  }
#end  // #macro PIFC_Pelador()
