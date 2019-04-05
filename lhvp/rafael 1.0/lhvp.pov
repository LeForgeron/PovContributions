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
//  LHVP (LampadarioHumoVelaParafina)
//  El archivo dibuja un lampadario de Iglesia con alcancia.
//  Incluye una macro para modificar algunas caracteristicas, ademas la macro calcula
//  las posiciones para que el usuario coloque velitas a gusto.
//  Es compatible con POVRay 3.1.
//
//  La macro principal no tiene parametros.
//  #macro LHVP_Lampadario()
//
//  La siguiente macro permite un mayor control sobre las caracteristicas.
//  #macro LHVP_LampadarioHumoVelaParafina(
//              FrenteFundamental, LateralFundamental,
//              AltoFundamental, LateralBandeja,
//              DiametroBarra, LadoCuadradoSoporte,
//              AnguloExposicion, DiametroAlcancia,
//              GruesoLamina, TotalHileras,   
//              VelasPorHilera, DiametroSoporteVela, AltoCruz,
//              MaterialPrincipal, MaterialAlcancia,  
//              MaterialBandeja, MaterialCandelero )
//          FrenteFundamental       : Valor de referencia para el frente del lampadario.
//              Valor por defecto 643*L.
//          LateralFundamental      : Valor de referencia para el ancho lateral Z.
//              valor por defecto 477*L.
//          AltoFundamental         : Alto sin la cruz del lampadario.
//              Valor por defecto 700*L.
//          LateralBandeja          : Valor de referencia para el ancho 
//              lateral Z de la bandeja. Valor por defecto 550*L.
//          DiametroBarra           : Diametro de las barras soporte.
//              Valor por defecto 10*L.
//          LadoCuadradoSoporte     : Lado del cuadrado formado por las barras laterales
//              para soporte de la estructura. Valor por defecto 100*L.
//          AnguloExposicion        : Angulo de inclinacion del plano imaginario para
//              las velitas. Valor por defecto 25.
//          DiametroAlcancia        : Diametro principal de la alcancia.
//              Valor por defecto 50*L.
//          GruesoLamina            : Grueso de algunas laminas de metal de la estructura.
//              Valor por defecto 3*L.
//          TotalHileras            : Total de hileras con velitas. Valor por defecto 6.
//          VelasPorHilera          : Total de velitas en cada hilera. Valor por defecto 10.
//          DiametroSoporteVela     : Diametro de los aros que soportan 
//              los candeleros individuales.
//              Valor por defecto 20*L.
//          AltoCruz                : Alto de la cruz posterior.
//              Valor por defecto 100*L.
//          MaterialPrincipal       : Material de las barras soporte.
//              Valor por defecto LHVP_MaterialPrincipal.
//          MaterialAlcancia        : Material para la alcancia.
//              Valor por defecto LHVP_MaterialAlcancia.
//          MaterialBandeja         : Material para la bandeja.
//              Valor por defecto LHVP_MaterialBandeja.
//          MaterialCandelero       : Material de los candeleros individuales.
//              Valor por defecto LHVP_MaterialCandelero.     
//
//  El lampadario se encuentra contenido entre las siguientes coordenadas:
//      Minimo          = < -330,    0, -305 >*L
//      Maximo          = < +330,  800, +305 >*L
//  La base descansa semicentrada sobre el plano XZ. El frente mira hacia Z-,
//  con la alcancia hacia X+.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.   
//  #declare LHVP_DefectoMaterialPrincipal       
//      Material de las barras soporte.
//  #declare LHVP_DefectoMaterialAlcancia      
//      Material para la alcancia.
//  #declare LHVP_DefectoMaterialBandeja        
//      Material para la bandeja.
//  #declare LHVP_DefectoMaterialCandelero          
//      Material de los candeleros individuales. 
//  #declare LHVP_ArregloCandelero         = array [ TotalHileras ][ VelasPorHilera ]
//      Un arreglo bidimensional que contiene la posicion de todas las velitas.
//      Las filas se numeran de abajo hacia arriba, y las columnas de izquierda a derecha.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare LHVP_MaterialPrincipal             =
//                      { LHVP_DefectoMaterialPrincipal             }
//      Material de las barras soporte.
//  #declare LHVP_MaterialAlcancia              =
//                      { LHVP_DefectoMaterialAlcancia              }
//      Material para la alcancia.
//  #declare LHVP_MaterialBandeja               =
//                      { LHVP_DefectoMaterialBandeja               }
//      Material para la bandeja.
//  #declare LHVP_MaterialCandelero             =
//                      { LHVP_DefectoMaterialCandelero             }
//      Material de los candeleros individuales. 
//       
//  Para colocarlo simplemente
//  #include "LHVP.inc" 
//  object { LHVP_Lampadario( ) }
//                                  
//  Con la macro detallada
//  #include "LHVP.inc" 
//  object          {
//    LHVP_LampadarioHumoVelaParafina(
//          0.643, 0.477, 0.700, 0.550, 0.010, 0.100,
//          25, 0.050, 0.003, 6, 10, 0.030, 0.100,
//          LHVP_MaterialPrincipal, LHVP_MaterialAlcancia,
//          LHVP_MaterialBandeja, LHVP_MaterialCandelero )
//  }
//      
//  Con modificadores
//  #include "LHVP.inc"
//  #include "textures.inc"
//  #declare LHVP_MaterialPrincipal         = 
//          material { texture { PinkAlabaster } }
//  object        { LHVP_Lampadario( ) }
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

#include "LHVP.inc"  

#local FactorAcercamiento   = 1.5;

object                                  {
  LHVP_Lampadario()    
  translate             -0.40*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}




