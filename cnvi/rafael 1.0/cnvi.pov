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
//  CNVI CandeleroNoVelaIncluida
//  El archivo dibuja un candelero con soporte metalico decorado en vidrio.
//  Posee una macro para modificar las caracteristicas principales, pero 
//  es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principale tiene solo un parametro:
//  #macro CNVI_Candelero( Semilla )
//          Semilla                         : Valor semilla para el generador de numeros
//              aleatorios. El efecto es poco apreciable.
//
//  El detalle del candelero puede modificarse ligeramente con la siguiente macro:     
//  #macro CNVI_CandeleroNoVelaIncluida( Semilla,
//      DiametroSoporte, AltoSoporte,
//      DiametroCandelero, AltoCandelero,
//      TotalColumnas, ColumnasDecoradoSeccion,
//      DiametroArgolla, FrenteVidrio, GruesoVidrio,
//      AlambreGrueso, AlambreMedio, AlambreDelgado,
//      MaterialSoporte, MaterialVidrio,
//      MaterialArgolla, MaterialCandelero )
//          Semilla                         : Valor semilla para el generador de numeros
//              aleatorios. El efecto es poco apreciable.
//          DiametroSoporte                 : Diametro del soporte metalico.
//              Valor por defecto 79*L.             
//          AltoSoporte                     : Alto del soporte metalico.
//              Valor por defecto 118*L.
//          DiametroCandelero               : Diametro del soporte interior para el candil.
//              Valor por defecto 29.4*L.
//          AltoCandelero                   : Alto del soporte interior para el candil.
//              Valor por defecto 11*L.
//          TotalColumnas                   : Total de columnas metalicas del soporte.
//              Valor por defecto 3.
//          ColumnasDecoradoSeccion         : Total de columnas de vidrio decorativa en
//              cada una de las TotalColumnas secciones del soporte.
//              Valor por defecto 4.
//          DiametroArgolla                 : Diametro de las argollitas sujetadoras.
//              Valor por defecto 8.5*L.          
//          FrenteVidrio                    : Ancho respecto del observador
//              del decorado de vidrio. Valor por defecto 15.6*L.
//          GruesoVidrio                    : Grueso radial del decorado de vidrio.
//              Valor por defecto 7.4*L.
//          AlambreGrueso                   : Diametro de los alambres soporte.
//              Valor por defecto 2.5*L.
//          AlambreMedio                    : Diametro de los alambres secundarios.
//              Valor por defecto 2*L.
//          AlambreDelgado                  : Diametro de las argollitas y laminas delgadas.
//              Valor por defecto 0.5*L.            
//          MaterialSoporte                 : Material del soporte metalico.
//              Valor por defecto CNVI_MaterialSoporte.
//          MaterialVidrio                  : Material del vidrio.
//              Valor por defecto CNVI_MaterialVidrio.
//          MaterialArgolla                 : Material de las argollitas.
//              Valor por defecto CNVI_MaterialArgolla.
//          MaterialCandelero               : Material del candelero interior.
//              Valor por defecto CNVI_MaterialCandelero.
//      
//  El candelero tiene las siguientes caracteristicas:
//      Alto            = 118*L (AltoSoporte)
//      Diametro        =  86*L (algo mayor a DiametroSoporte) 
//  El fondo del recipiente descansa sobre el plano XZ, en el hemisferio Y+.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare CNVI_BaseVela
//      Vector para ubicar la base de la vela dentro de la estructura.    
//  #declare CNVI_DefectoMaterialSoporte            
//      Material para el soporte metalico.
//  #declare CNVI_DefectoMaterialVidrio            
//      Material para el decorado de vidrio.
//  #declare CNVI_DefectoMaterialArgolla            
//      Material para las argollitas sujetadores.
//  #declare CNVI_DefectoMaterialCandelero            
//      Material para el candelero interior.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare CNVI_MaterialSoporte                   =
//                  { CNVI_DefectoMaterialSoporte                 }
//      Material para el soporte metalico.
//  #declare CNVI_MaterialVidrio                    =
//                  { CNVI_DefectoMaterialVidrio                  }
//      Material para el decorado de vidrio.
//  #declare CNVI_MaterialArgolla                   =
//                  { CNVI_DefectoMaterialArgolla                 }
//      Material para las argollitas sujetadores.
//  #declare CNVI_MaterialCandelero                 =
//                  { CNVI_DefectoMaterialCandelero               }
//      Material para el candelero interno.
//       
//  Para colocarlo simplemente
//  #include "CNVI.inc" 
//  object { CNVI_Candelero( 1000 ) }
//   
//  Con una velita
//  #include "CNVI.inc" 
//  union  {
//    object { CNVI_Candelero( 1000 ) }
//    cylinder { 0, 0.020*y, 0.020 pigment { White } translate BNVI_BaseVela }
//  }
//                               
//  Ejemplo con la macro detallada, mismos objetos por defecto
//  #include "CNVI.inc"   
//  object                       {
//    CNVI_CandeleroNoVelaIncluida( 1000, 
//        0.079, 0.118, 0.0294, 0.011, 3, 4, 
//        0.0085, 0.0156, 0.0074, 0.0025, 0.002, 0.0005,
//        CNVI_MaterialSoporte, CNVI_MaterialVidrio,
//        CNVI_MaterialArgolla, CNVI_MaterialCandelero )
//  }
//        
//  Con modificadores
//  #include "CNVI.inc"
//  #include "textures.inc"
//  #declare CNVI_MaterialSoporte         = material { texture { PinkAlabaster } } 
//  object        { CNVI_Candelero( 1000 ) }
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

#include "CNVI.inc"

#local FactorAcercamiento       = 10;
 

object                          {
  CNVI_Candelero( 1000 )
  translate             -0.059*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z  
}

