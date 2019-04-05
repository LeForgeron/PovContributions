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
//  CJTD CultivadorJardinTresDientes
//  El archivo dibuja un cultivador para jardineria domestica.
//  Posee una macro para modificar las caracteristicas principales, pero 
//  es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal no tiene parametros:
//  #macro CJTD_Cultivador( )
//
//  El detalle del cultivador puede modificarse ligeramente con la siguiente macro:     
//  #macro CJTD_CultivadorJardinTresDientes( LargoBastidor,
//      DiametroMayorBastidor, DiametroMenorBastidor,
//      LargoRectoVarilla, LargoOblicuoVarilla,
//      DiametroVarillaCentral, DiametroVarillaLateral,
//      AnguloAbertura, AnguloArrastre,
//      FraccionOrigenVarillas, RadioCurvaturaVarillas,
//      MaterialDientes, MaterialMetalico,
//      MaterialMadera, MaterialAgarradera )
//          LargoBastidor                   : Largo del mango.
//              Valor por defecto 125*L.
//          DiametroMayorBastidor           : Diametro mayor del mango.
//              Valor por defecto 25*L.
//          DiametroMenorBastidor           : Diametro menor del mango.
//              Valor por defecto 14.6*L.
//          LargoRectoVarilla               : Referencia para el largo de varilla.
//              Valor por defecto 90*L.
//          LargoOblicuoVarilla             : Referencia para el largo de arrastre del
//              cultivador. Valor por defecto 27*L.
//          DiametroVarillaCentral          : Diametro de la varilla central de arrastre.
//              Valor por defecto 5.7*L.
//          DiametroVarillaLateral          : Diametro de las varillas laterales de arrastre.
//              Valor por defecto 4*L.
//          AnguloAbertura                  : Angulo de abertura de las varillas laterales.
//              Valor por defecto 15.
//          AnguloArrastre                  : Angulo inclinacion de las varillas de arrastre.
//              Valor por defecto 15.
//          FraccionOrigenVarillas          : Fraccion respecto a LargoRectoVarillas,
//              en que cruza la extrapolacion imaginaria de las varillas de arrastre.    
//              Valor por defecto 0.0.
//          RadioCurvaturaVarillas          : Radio para la curva que une la linea horizontal
//              con las lineas de arrastre en las varillas.
//              Valor por defecto 7*L.
//          MaterialDientes                 : Material de las varillas.
//              Valor por defecto CJTD_MaterialDientes.
//          MaterialMetalico                : Material de la argolla metalica de union.
//              Valor por defecto CJTD_MaterialMetalico.
//          MaterialMadera                  : Material del mango de madera.
//              Valor por defecto CJTD_MaterialMadera.
//          MaterialAgarradera              : Material de la agarradera de caucho.
//              Valor por defecto CJTD_MaterialAgarradera.
//      
//  El cultivador tiene las siguientes caracteristicas:
//      Minimo          = < -32, -125, -35 >*L
//      Maximo          = <  32,  107,  13 >*L
//  Los dientes se curvan hacia Z-. El punto de union entre el bastidor y los dientes
//  se encuentra en el origen de coordenadas.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare CJTD_DefectoMaterialDientes
//      Material de las varillas.
//  #declare CJTD_DefectoMaterialMetalico            
//      Material de la argolla metalica de union.
//  #declare CJTD_DefectoMaterialMadera            
//      Material del mango de madera.
//  #declare CJTD_DefectoMaterialAgarradera
//      Material de la agarradera de caucho.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare CJTD_MaterialDientes                   =
//                  { CJTD_DefectoMaterialDientes                 }
//      Material de las varillas.
//  #declare CJTD_MaterialMetalico                  =
//                  { CJTD_DefectoMaterialMetalico                }
//      Material de la argolla metalica de union.
//  #declare CJTD_MaterialMadera                    =
//                  { CJTD_DefectoMaterialMadera                  }
//      Material del mango de madera.
//  #declare CJTD_MaterialAgarradera                =
//                  { CJTD_DefectoMaterialAgarradera              }
//      Material de la agarradera de caucho.
//       
//  Para colocarlo simplemente
//  #include "CJTD.inc" 
//  object { CJTD_Cultivador( ) }
//   
//  Ejemplo con la macro detallada, mismo objetos por defecto
//  #include "CJTD.inc"   
//  object                       {
//    CJTD_CultivadorJardinTresDientes( 0.125, 0.025, 0.0146, 
//        0.090, 0.027, 0.0057, 0.004, 15, 15, 0, 0.007,
//        CJTD_MaterialDientes, CJTD_MaterialMetalico,
//        CJTD_MaterialMadera, CJTD_MaterialAgarradera )
//  }
//        
//  Con modificadores
//  #include "CJTD.inc"
//  #include "textures.inc"
//  #declare CJTD_MaterialDientes      = material { texture { PinkAlabaster } } 
//  object        { CJTD_Cultivador( ) }
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

#include "CJTD.inc"
   
#local FactorAcercamiento       = 7;
    
object                          {
  CJTD_Cultivador()    
  rotate   -90*z
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}

