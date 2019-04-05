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
#include "PIFC.inc"

#local FactorAcercamiento       = 12.0;

object                                  {
  PIFC_Pelador( <0,0,0>, 0 )        
  translate         0.010*x
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}

