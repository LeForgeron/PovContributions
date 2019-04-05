//  This file is licensed under the terms of the CC-LGPL.
//  
//  Autor  : Rafael Angel Campos Vargas
//  Correo : RofoelCompos@hotmail.com  
//  Apdo. 964-1250 Escazu, San Jose, Costa Rica
//  dedicado a Jesus y Maria...
//
//  En este momento estoy creando un programa
//  de animacion LibreN3D para FreeDOS con el compilador FreePascal
//  falta mucho... 03 julio 2018
//                
//  Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
//  1 L equivale a 0.055063 pulgadas 
//  definido como 0.001 para POVRAY.
//     
//  LCGF LicuadoraCuchillaGiratoriaFilosa
//  El archivo dibuja una licuadora corriente para cocina, de ocho botones.
//  Posee una macro para variar sus dimensiones principales y texturas. 
//  La base se ajusta en ocho posiciones, pueden oprimirse los botones, y separarse
//  algunas partes pero es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene solo un parametro.
//  #macro LCGF_Licuadora( IndiceRanura )
//          IndiceRanura        : Numero entero entre 0 y 7, para ubicar la licuadora
//              en una de las ocho ranuras (esto orienta la oreja de la licuadora). 
//              Un numero fraccionario no genera error.
//        
//  La siguiente macro permite un mayor control de las caracteristicas. Es probable
//  que los botones queden mal ubicados, y requira utilizar los modificadores.
//  #macro  LCGF_LicuadoraCuchillaGiratoriaFilosa
//          ( IndiceRanura, DiametroBase, DiametroSoporte, 
//            AltoBase, ProfundidadDelantera,
//            DiametroPichel, AltoReferenciaPichel, 
//            GruesoPlastico, AltoInternoTapa, 
//            DiametroAberturaTapa, AnchoOreja, AltoOreja,
//            MaterialPrincipal, MaterialPichel, MaterialAccesorios,
//            MaterialBotones, MaterialPlacaBotones,
//            MaterialCuchillas, MaterialCuero )
//          IndiceRanura        : Numero entero entre 0 y 7, para ubicar la licuadora
//              en una de las ocho ranuras. Esto orienta, la oreja de la licuadora
//              en una de ocho posiciones. Un numero fraccionario no genera error.
//          DiametroBase        : Diametro de la base inferior a lo ancho en X.
//              Valor por defecto 114*L.
//          DiametroSoporte     : Diametro en la zona de contacto con la licuadora.
//              Valor por defecto 73*L.
//          AltoBase            : Alto referencia para la base de la licuadora.
//              Valor por defecto 112.60*L.
//          ProfundidadDelantera            : Profundidad en Z de la zona negativa o
//              frente de la licuadora. Valor por defecto 94*L.
//          DiametroPichel      : Diametro del pichel de licuado.
//              Valor por defecto 85*L.
//          AltoReferenciaPichel            : Alto de referencia para el pichel.
//              Valor por defecto 127*L.
//          GruesoPlastico      : Grueso del material basico del pichel.
//              Valor por defecto 2*L.
//          AltoInternoTapa     : Alto de la tapa que penetra el recipiente.
//              Valor por defecto 22*L.            
//          DiametroAberturaTapa            : Diametro de la abertura en la tapa.
//              Valor por defecto 37*L.
//          AnchoOreja          : Abertura desde el cilindro para agarrar la oreja.
//              Valor por defecto 50*L.
//          AltoOreja           : Porcion del pichel a lo alto en Y, abarcado por la oreja.
//              Valor por defecto 112*L.
//          MaterialPrincipal   : Material de la base que soporta al pichel.
//              Valor por defecto LCGF_MaterialPrincipal.
//          MaterialPichel      : Material del pichel contenedor.
//              Valor por defecto LCGF_MaterialPichel.
//          MaterialAccesorios  : Material de algunos elementos del pichel,
//              como la tapa o el cilindro de union.
//              Valor por defecto LCGF_MaterialAccesorios.
//          MaterialBotones     : Material para los botones.
//              Valor por defecto LCGF_MaterialBotones.
//          MaterialPlacaBotones            : Material para la placa soporte de botones.
//              Valor por defecto LCGF_MaterialPlacaBotones.
//          MaterialCuchillas   : Material para las cuchillas.
//              Valor por defecto LCGF_MaterialCuchillas.
//          MaterialCuero       : Material para patas y contacto de giro.
//              Valor por defecto LCGF_MaterialCuero.
//
//  El aparato sin contar su oreja se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -57,    0,  -94 >*L
//      Maximo      = <  +57, +303,  +57 >*L
//  La oreja se extienda hasta 94*L de radio respecto al eje Y y tiene ocho posiciones. 
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores. 
//  #declare LCGF_InterioBase           = object { ... }                     
//      Se genera al llamar a la macro.
//      Corresponde al volumen interior del pichel. No incluye correccion
//      para las cuchillas o la tapa.
//      Puede utilzarla para ubicar material en el interior del recipiente.
//  #declare LCGF_DefectoMaterialPrincipal   
//      Material de la base que soporta al pichel.
//  #declare LCGF_DefectoMaterialPichel      
//      Material del pichel contenedor.
//  #declare LCGF_DefectoMaterialAccesorios  
//      Material de algunos elementos del pichel,
//      como la tapa o el cilindro de union.
//  #declare LCGF_DefectoMaterialBotones     
//      Material para los botones.
//  #declare LCGF_DefectoMaterialPlacaBotones            
//      Material para la placa soporte de botones.
//  #declare LCGF_DefectoMaterialCuchillas   
//      Material para las cuchillas.
//  #declare LCGF_DefectoMaterialCuero       
//      Material para patas y conctacto de giro.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default)   
//  #declare LCGF_TransformPichel           = transform { }
//      Transform adicional para ubicar el pichel.
//  #declare LCGF_TransformTapaPichel       = transform { }
//      Transform adicional para ubicar la tapa del pichel.
//  #declare LCGF_TransformVisorPichel      = transform { }
//      Transform adicional para ubicar el visor en la tapa del pichel.
//  #declare LCGF_AnguloRotarCuchillas      = 0;
//      Angulo para girar las cuchillas.
//  #declare LCGF_ColorLetras               = White;
//      Para cambiar el color de las etiquetas de los botones.
//  #declare LCGF_BanderaBotones            = on;
//      "on" botones visibles, "off" los desactiva. Util como ultimo
//      remedio si los botones quedan mal ubicados.           
//  #declare LCGF_TransformBotones          = transform { }           
//      Permite corregir la posicion de los botones. Tomar en cuenta
//      que posterior a esta transform se genera un <i>rotate 45*x</i>. 
//      De tal forma, que en muchos casos sea suficiente con desplazar
//      los botones arriba-abajo.          
//  #declare LCGF_EstadoBotones             = array [ 8 ]
//          { off, off, off, off, off, off, off, off }
//      Permite apretar botones con el valor "on".
//  #declare LCGF_LabelBotones              = array [ 8 ]
//          { "A", "R", "P", "1", "2", "3", "4", "5" }
//      Para cambiar las etiquetas de los botones. Solo se permite
//      un caracter.
//  #declare LCGF_MaterialPrincipal         =
//                  { LCGF_DefectoMaterialPrincipal             }  
//      Material de la base que soporte el pichel.
//  #declare LCGF_MaterialPichel            =
//                  { LCGF_DefectoMaterialPichel                }
//      Material del pichel contenedor.
//  #declare LCGF_MaterialAccesorios        =
//                  { LCGF_DefectoMaterialAccesorios            }
//      Material de algunos elementos del pichel,
//      como la tapa o el cilindro de union.
//  #declare LCGF_MaterialBotones           =
//                  { LCGF_DefectoMaterialBotones               }
//      Material para los botones.
//  #declare LCGF_MaterialPlacaBotones      =
//                  { LCGF_DefectoMaterialPlacaBotones          }    
//      Material para la placa soporte de botones.
//  #declare LCGF_MaterialCuchillas         =
//                  { LCGF_DefectoMaterialCuchillas             }
//      Material para las cuchillas.
//  #declare LCGF_MaterialCuero             =
//                  { LCGF_DefectoMaterialCuero                 }
//      Material para patas y conctacto de giro.
//       
//  Para colocarlo simplemente
//  #include "LCGF.inc" 
//  object { LCGF_Licuadora( 0 ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto default
//  #include "LCGF.inc"   
//  object                       {
//      LCGF_LicuadoraCuchillaGiratoriaFilosa( 0, 
//          0.114, 0.073, 0.1126, 0.094, 0.085, 0.127, 
//          0.002, 0.022, 0.037 , 0.050, 0.112,
//          LCGF_MaterialPrincipal, LCGF_MaterialPichel,
//          LCGF_MaterialAccesorios, LCGF_MaterialBotones,
//          LCGF_MaterialPlacaBotones,LCGF_MaterialCuchillas,
//          LCGF_MaterialCuero )
//  }
//        
//  Con modificadores
//  #include "LCGF.inc"
//  #include "textures.inc"
//  #declare LCGF_MaterialPichel   = material { M_Green_Glass } 
//  object        { LCGF_Licuadora( 0 ) }
//
//  Con liquido en su interior
//  #include "LCGF.inc"
//  #include "colors.inc"
//  #include "textures.inc"
//  object        { LCGF_Licuadora( 0 ) }
//  object        { LCGF_InteriorBase pigment { Orange } }
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
 
//#declare LCGF_POV3_1           = on; 
 
#include "LCGF.inc"

#local FactorAcercamiento       = 4.0;

object                          {
  LCGF_Licuadora( 2 )            
  translate             -0.151*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}

