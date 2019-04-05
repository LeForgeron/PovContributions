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
//  RPPM RadiocomunicadorPortatilPersonalManual
//  El archivo dibuja un radiocomunicador de mano de corto alcance.
//  Posee una macro para modificar las caracteristicas principales, pero 
//  es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal no tiene parametros.
//  #macro RPPM_Radiocomunicador()
//
//  La siguiente macro permite un mayor control sobre las caracteristicas.
//  #macro RPPM_RadiocomunicadorPortatilPersonalManual(
//              AltoFundamental, FrenteFundamental, GruesoFundamental,
//              FactorEnsanchamiento, FraccionAltoEnsanchamiento,  
//              AltoAntena, DiametroAntena,  
//              ArregloBotones, GIFBotones, FactorBoton,
//              MaterialPrincipal, MaterialBaseCaratula, 
//              MaterialAntena, MaterialPlastico,
//              MaterialPantalla, MaterialTransparente, MaterialBotones ) 
//          AltoFundamental                 : Alto de la radio sin antena. 
//              Valor por defecto 70*L.
//          FrenteFundamental               : Frente en X de la radio sin botones.
//              Valor por defecto 35*L.
//          GruesoFundamental               : Grueso en Z del cuerpo principal inferior.
//              Valor por defecto 21*L.
//          FactorEnsanchamiento            : Factor en que la seccion superior se 
//              ensancha respecto a la inferior.
//              Valor por defecto 1.15.           
//          FactorAltoEnsanchamiento        : Fraccion propia de AltoFundamental que
//              divide la seccion superior e inferior del cuerpo principal.
//              Valor por defecto 0.5.
//          AltoAntena                      : Alto de la antena.
//              Valor por defecto 40*L.
//          DiametroAntena                  : Diametro en la base de la antena.
//              Valor por defecto 11*L. 
//          ArregloBotones                  : Arreglo bidimensional de vectores 2D
//              con el formato array [TotalBotones][4]. Cada renglon definira
//              cuatro esquinas de un cuadrilatero. Las coordenadas deberan estar
//              contenidas en el dominio <-0.5,0>..<0.5,1> que son relativas al espacio
//              de dibujo, aunque el dominio
//              verdadero sera mucho menor pues debe caer en la zona de la placa delantera.
//              Los botones ocuparan el cuadrilatero en su totalidad
//              mas un borde determinado por FactorBotones.
//              Valor por defecto BMME_ArregloBotones.
//          GIFBotones                      : Archivo imagen GIF que se utiza para
//              etiquetar los botones. Utilice "" para ignorar este parametro.
//              El color de indice 0 se utiliza como color transparente.
//              Valor por defecto BMME_GIFBotones.
//          FactorBotones                   : Agrega un borde en exceso a los botones
//              definidos en ArregloBotones. Utiliza coordenadas relativas al espacio
//              disponible. Valor por defecto BMME_FactorBotones.
//          MaterialPrincipal               : Material principal del aparato.
//              Valor por defecto BMME_MaterialPrincipal.
//          MaterialBaseCaratula            : Material para la base de los botones.
//              Valor por defecto BMME_MaterialBaseCaratula.
//          MaterialAntena                  : Material para la antena.
//              Valor por defecto BMME_MaterialAntena.
//          MaterialPlastico                : Material para el borde plastico de la pantalla.
//              Valor por defecto BMME_MaterialPlastico.
//          MaterialPantalla                : Material para el fondo de pantalla.
//              Podria incluir un archivo de imagen para visualizacion.
//              Valor por defecto BMME_MaterialPantalla.
//          MaterialTransparente            : Material del vidrio que cubre la pantalla.
//              Valor por defecto BMME_MaterialTransparente.
//          MaterialBotones                 : Material de los botones.
//              Valor por defecto BMME_MaterialBotones. 
//
//  El radiocomunicador se encuentra contenido entre las siguientes coordenadas:
//      Minimo          = < -22,   0, -12 >*L
//      Maximo          = <  20, 110,  15 >*L
//  El radiocomunicador se dibuja con la pantalla hacia Z-, la antena hacia Y+ y
//  el boton de recepcion hacia X-. Descansa sobre el plano XZ.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores. 
//  #declare RPPM_GIFBotones                        = "RPPM_IM1.gif"
//      Imagen utilizada por defecto como parametro GIFBotones, para
//      dibujar los botones del radiocomunicador.
//  #declare RPPM_FactorBotones                     = 0.035;                                                               
//      Se utiliza por defecto como parametro FactorBotones, que establece un borde
//      en exceso sobre los cuadrilateros definidos en ArregloBotones.                                                               
//  #declare RPPM_ArregloBotones                    = array [5][4]  
//      Arreglo de vectores 2D que se usa como parametro por defecto 
//      ArregloBotones. Que define cuadrilateros en coordenadas relativas
//      para dibujar los botones.
//  #declare RPPM_DefectoMaterialPrincipal               
//      Material principal del aparato.
//  #declare RPPM_DefectoMaterialBaseCaratula            
//      Material para la base de los botones.
//  #declare RPPM_DefectoMaterialAntena                  
//      Material para la antena.
//  #declare RPPM_DefectoMaterialPlastico                
//      Material para el borde plastico de la pantalla.
//  #declare RPPM_DefectoMaterialPantalla                
//      Material para el fondo de pantalla.
//      Podria incluir el texto aqui de alguna manera.
//  #declare RPPM_DefectoMaterialTransparente            
//      Material del vidrio que cubre la pantalla.
//  #declare RPPM_DefectoMaterialBotones                 
//      Material de los botones.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare RPPM_MaterialPrincipal                 =
//                  { RPPM_DefectoMaterialPrincipal               }
//      Material principal del aparato.
//  #declare RPPM_MaterialBaseCaratula              =
//                  { RPPM_DefectoMaterialBaseCaratula            }
//      Material para la base de los botones.
//  #declare RPPM_MaterialAntena                    =
//                  { RPPM_DefectoMaterialAntena                  }  
//      Material para la antena.
//  #declare RPPM_MaterialPlastico                  =
//                  { RPPM_DefectoMaterialPlastico                }
//      Material para el borde plastico de la pantalla.
//  #declare RPPM_MaterialPantalla                  =
//                  { RPPM_DefectoMaterialPantalla                }
//      Material para el fondo de pantalla.
//      Podria incluir el texto aqui de alguna manera.
//  #declare RPPM_MaterialTransparente              =
//                  { RPPM_DefectoMaterialTransparente            }
//      Material del vidrio que cubre la pantalla.
//  #declare RPPM_MaterialBotones                   =
//                  { RPPM_DefectoMaterialBotones                 }
//      Material de los botones.
//       
//  Para colocarlo simplemente
//  #include "RPPM.inc" 
//  object { RPPM_Radiocomunicador(  ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto por defecto
//  #include "RPPM.inc"   
//  object                       {
//    RPPM_RadiocomunicadorPortatilPersonalManual( 0.070, 0.035, 
//                0.021, 1.15, 0.5, 0.040, 0.011,
//                RPPM_ArregloBotones, RPPM_GIFBotones, RPPM_FactorBotones,
//                RPPM_MaterialPrincipal, RPPM_MaterialBaseCaratula,
//                RPPM_MaterialAntena, RPPM_MaterialPlastico,
//                RPPM_MaterialPantalla, RPPM_MaterialTransparente,
//                RPPM_MaterialBotones )
//  }
//        
//  Con modificadores
//  #include "RPPM.inc"
//  #include "textures.inc"
//  #declare RPPM_MaterialPrincipal         = material { texture { PinkAlabaster } } 
//  object        { RPPM_Radiocomunicador(  ) }
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
 
#include "RPPM.inc"
 
#local FactorAcercamiento       = 12.0;
 
object                                  {
  RPPM_Radiocomunicador()  
  translate             -0.0525*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}


