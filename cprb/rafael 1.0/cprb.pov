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
//  CPRB (CalibradorPieReyBarato)
//  El archivo dibuja un modelo sencillo de calibrador con vernier para medidas precisas.
//  Las unidades y algunas caracteristicas basicas pueden modificarse facilmente.
//  Es compatible con POVRay 3.1.
//
//  La macro principal solo tiene un parametro.
//  #macro CPRB_Calibrador( LecturaPR )
//          LecturaPR               : Desplace el vernier hacia X- en unidades POV-Ray.
//
//
//  La siguiente macro permite un mayor control sobre las caracteristicas.
//  #macro CPRB_CalibradorPieReyBarato( LecturaPR,
//                LargoFundamental, LargoPie, GruesoFijo,
//                AnchoDeslizante, TamanoPie, FraccionDelanteraPie,
//                GruesoAire, LargoPrecision, AnchoPrecisionPosterior,
//                GruesoPrecision, DiametroAlambre,
//                MaterialPrincipal, MaterialDeslizante, 
//                MaterialAlambre, MaterialMarcas )
//          LecturaPR               : Desplace el vernier hacia X- en unidades POV-Ray. 
//          LargoFundamental        : Largo total en X del calibrador.
//              Valor por defecto 150*L.
//          LargoPie                : Tamano en X del pie fijo del calibrador.
//              Valor por defecto 11*L.
//          GruesoFijo              : Grueso de la regla fija del calibrador.
//              Valor por defecto 2*L.
//          AnchoDeslizante         : Ancho en Y de la regla fija del calibrador.
//              Valor por defecto 11*L.
//          TamanoPie               : Tamano en Y del pie fijo del calibrador.
//              Valor por defecto 53*L.
//          FraccionDelanteraPie    : Fraccion del pie fijo que se encuentra sobre
//              el plano superior Y+. Valor por defecto 0.64.
//          GruesoAire              : Grueso de las aberturas huecas en la mordedura 
//              del calibrador. Valor por defecto 1*L.
//          LargoPrecision          : Largo total del vernier movil.
//              Valor por defecto 59*L.
//          AnchoPrecisionPosterior : Grosor en Y de la escala inferior movil.
//              Valor por defecto 4*L.
//          GruesoPrecision         : Grosor Z del calibrador total.
//              Valor por defecto 3.5*L.
//          DiametroAlambre         : Diametro del alambrillo para medir profundidad.
//              Valor por defecto 1*L. 
//          MaterialPrincipal       : Material de la regla fija.
//              Valor por defecto CPRB_MaterialPrincipal.
//          MaterialDeslizante      : Material del vernier movil.
//              Valor por defecto CPRB_MaterialDeslizante.
//          MaterialAlambre         : Material del alambrillo para medir profundidad.
//              Valor por defecto CPRB_MaterialAlambre.
//          MaterialMarcas          : Material para numeros y escalas.
//              Valor por defecto CPRB_MaterialMarcas.     
//
//  La unidad por defecto del calibrador es el mL (miliLisa).  Para darle mayor versatilidad
//  se ofrece una variante con fracciones binarias del cL (centiLisa). 
//  Por razones esteticas las unidades del vernier por defecto, se ajusta 
//  proporcionalmente a LargoPrecision-LargoPie.
//  El usuario puede asignar su propio sistema de unidades, utilizando modificadores.
//
//  El calibrador se encuentra contenido entre las siguientes coordenadas:
//      Minimo          = < -( LargoFundamental+LecturaPR-LargoPie ),
//                          -( TamanoPie*( 1-FraccionDelantera ) ), -GruesoFijo/2 >                          
//      Maximo          = < LargoPie, FraccionDelantera*TamanoPie, 
//                          ( GruesoPrecision-GruesoFijo/2 ) >
//  Con los valores por defecto y parametro nulo, el resultado seria:
//      Minimo          = < -139.0,   19.1,   -1.0 >*L
//      Maximo          = <   11.0,   33.9,    2.5 >*L
//  La base del pie fijo se encuentra ajustado con el eje Y. La regla apunta hacia X-,
//  las marcas hacia Z-.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.   
//  #declare CPRB_DefectoMaterialPrincipal       
//      Material de la regla fija.
//  #declare CPRB_DefectoMaterialDeslizante      
//      Material del vernier movil.
//  #declare CPRB_DefectoMaterialAlambre         
//      Material del alambrillo para medir profundidad.
//  #declare CPRB_DefectoMaterialMarcas          
//      Material para numeros y escalas.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare CPRB_EscalaDecimal
//      Valor real. Si se declara sustituye el sistema de medidas superior Y+ del
//      calibrador. Su valor en unidades POV-Ray
//      debe corresponder al numeral 10 de la escala superior.
//      Un valor 0.010 corresponderia a la escala actual.
//  #declare CPRB_EscalaBinaria
//      Valor real. Si se declara sustituye el sistema de medidas inferior Y- del
//      calibrador. Su valor en unidades POV-Ray
//      debe corresponder al numeral 1 de la escala inferior.
//      Se modificara la separacion en el vernier inferior para que concuerde
//      con el patron del modelo original.
//      Un valor 0.010 corresponderia a la escala actual.
//  #declare CPRB_MaterialPrincipal             =
//                      { CPRB_DefectoMaterialPrincipal             }
//      Material de la regla fija.
//  #declare CPRB_MaterialDeslizante            =
//                      { CPRB_DefectoMaterialDeslizante            }
//      Material del vernier movil.
//  #declare CPRB_MaterialAlambre               =
//                      { CPRB_DefectoMaterialAlambre               }
//      Material del alambrillo para medir profundidad.
//  #declare CPRB_MaterialMarcas                =
//                      { CPRB_DefectoMaterialMarcas                }
//      Material para numeros y escalas.
//       
//  Para colocarlo simplemente
//  #include "CPRB.inc" 
//  object { CPRB_Calibrador( 0.0 ) }
//                                  
//  Con la macro detallada
//  #include "CPRB.inc" 
//  object          {
//    CPRB_CalibradorPieReyBarato( 0.0,
//            0.150, 0.011, 0.002, 0.011, 0.053, 0.64, 
//            0.001, 0.059, 0.004, 0.0035, 0.001,              
//            CPRB_MaterialPrincipal, CPRB_MaterialDeslizante,
//            CPRB_MaterialAlambre, CPRB_MaterialMarcas ) 
//  }
//      
//  Con modificadores
//  #include "CPRB.inc"
//  #include "textures.inc"
//  #declare CPRB_MaterialPrincipal         = 
//          material { texture { PinkAlabaster } }
//  object        { CPRB_Calibrador( 0.0 ) }
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

#include "CPRB.inc"
 
#local FactorAcercamiento       = 12.0;    
     
object                                  {
  CPRB_Calibrador( 0.0 )
  translate             +0.065*x
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}


