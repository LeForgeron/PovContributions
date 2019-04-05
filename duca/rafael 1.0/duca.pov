//  This file is licensed under the terms of the CC-LGPL.
//
//  Autor  : Rafael Angel Campos Vargas
//  Correo : RofoelCompos@hotmail.com  
//  Apdo. 964-1250 Escazu, San Jose, Costa Rica
//  dedicado a Jesus y Maria...
//
//  En este momento estoy creando un programa
//  de animacion LibreN3D para FreeDOS con el compilador FreePascal
//  falta mucho... 19 junio 2018
//                
//  Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
//  1 L equivale a 0.055063 pulgadas 
//  definido como 0.001 para POVRAY.
//     
//  DUCA DispensadorUniversalCintaAdhesiva
//  El archivo dibuja un dispensador de cinta adhesiva, tipo escolar recargable.
//  La cinta tiene dos posiciones, una enrollada y otra lista en la cuchilla. 
//  Es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene dos parametros.
//  #macro DUCA_Cinta( FactorRelleno, BanderaCortada )
//          FactorRelleno       : Fraccion de uso. 
//              0.0 indica cinta agotada, y 1.0 cinta nueva.
//              Utilice un valor negativo para no dibujar la cinta del todo.
//          BanderaCortada      : "on" dibuja la cinta puesta en el cortador metalico,
//              "off" dibuja la cinta enrollada sin ubicar en el cortador.
//        
//  La siguiente macro permite un mayor control de las caracteristicas.
//  #macro DUCA_DispensadorUniversalCintaAdhesiva( FactorRelleno, BanderaCortada,
//              DiametroDespachador, AnchoDespachador, DiametroInternoCinta,
//              DiametroAdhesivoMenor, DiametroAdhesivoMayor, AnchoAdhesivo,
//              GruesoPlastico, GruesoFilo, TotalDientes,
//              TexturaPrincipal, TexturaMetalica,
//              TexturaAdhesiva, TexturaSoporteAdhesivo )
//          FactorRelleno       : 0 indica cinta agotada, y 1.0 cinta nueva.
//              Utilice un valor negativo para no dibujar la cinta del todo.
//          BanderaCortada      : "on" dibuja la cinta puesta en el cortador metalico,
//              "off" dibuja la cinta enrollada, sin ubicar en el cortador.
//          DiametroDespachador     : Medida fundamental del despachador. El alto
//              sin las patillas inferiores. 
//              Valor por defecto 54.5*L.
//          AnchoDespachador        : Ancho en Z del despachador.
//              Valor por defecto DiametroDespachador/3.
//          DiametroInternoCinta    : Diametro del carrete de cinta.
//              Valor por defecto DiametroDespachador/3.
//          DiametroAdhesivoMenor   : Diametro menor del material adhesivo.
//              Valor por defecto 26.33*L.
//          DiametroAdhesivoMayor   : Diametro mayor del mayor adhesivo 
//              (con FactorRelleno 1.0).
//              Valor por defecto 36.33*L.
//          AnchoAdhesivo           : Ancho de la cinta.
//              Valor por defecto 13.62*L.
//          GruesoPlastico          : Grueso de las laminas de plastico.
//              Valor por defecto 1*L.
//          GruesoFilo              : Grueso del filo.
//              Valor por defecto GruesoPlastico/5.
//          TotalDientes            : Total de dientes del filo.
//              Valor por defecto 20.
//          TexturaPrincipal        : Textura principal del dispensador.
//              Valor por defecto DUCA_TexturaPrincipal.
//          TexturaMetalica         : Textura de la laminilla cortante.      
//              Valor por defecto DUCA_TexturaMetalica.
//          TexturaAdhesiva         : Textura de la cinta.
//              Valor por defecto DUCA_TexturaAdhesiva.
//          TexturaSoporteAdhesivo  : Textura del carrete que soporta la cinta.
//              Valor por defecto DUCA_TexturaSoporteAdhesivo.
//
//  El dispensador de cinta se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -27,    0,   -9 >*L
//      Maximo      = <  +42,  +56,   +9 >*L
//      Minimo      = < -DiametroDespachador/2, 0, -AnchoDespachador/2 >
//      Maximo      = < +23*DiametroDespachador/50, +DiametroDespachador+GruesoPlastico, 
//                                  +AnchoDespachador/2 >
//  Es casi simetrico con respectro al plano XY. El centro del carrete sobre el eje Y.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare DUCA_DefectoTexturaPrincipal  
//      Textura principal del dispensador.
//  #declare DUCA_DefectoTexturaMetalica
//      Textura de la laminilla cortante.
//  #declare DUCA_DefectoTexturaAdhesiva
//      Textura de la cinta.
//  #declare DUCA_DefectoTexturaSoporteAdhesivo
//      Textura del carrete que soporta la cinta.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default)   
//  #declare DUCA_TransformDispensadorZP    = transform { }
//      Permite abrir el dispensador, al desplazar su zona Z+.
//  #declare DUCA_TransformDispensadorZN    = transform { }
//      Permite abrir el dispensador, al desplazar su zona Z-.
//  #declare DUCA_TransformCinta            = transform { }
//      Permite un desplazamiento adicional a la cinta de recarga.
//  #declare DUCA_FactorAbertura            = 1.0;
//      Sirve para cambiar el tamano de la abertura para empujar la cinta con los dedos.
//      Se ha observado que la abertura podria quedar mal ubicada al cambiar los
//      parametros por defecto. Este factor sirve para mitigar el problema.
//  #declare DUCA_TexturaPrincipal          = 
//                  texture  { DUCA_DefectoTexturaPrincipal         }  
//      Textura principal del dispensador.                         
//  #declare DUCA_TexturaMetalica           =
//                  texture  { DUCA_DefectoTexturaMetalica          }
//      Textura de la laminilla cortante.
//  #declare DUCA_TexturaAdhesiva           =
//                  texture  { DUCA_DefectoTexturaAdhesiva          }
//      Textura de la cinta.
//  #declare DUCA_TexturaSoporteAdhesivo    =
//                  texture  { DUCA_DefectoTexturaSoporteAdhesivo   }
//      Textura del carrete que soporta la cinta.
//       
//  Para colocarlo simplemente
//  #include "DUCA.inc" 
//  object { DUCA_Cinta( 1.0, on ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto default
//  #include "DUCA.inc"   
//  object                       {
//      DUCA_DispensadorUniversalCintaAdhesiva( 1.0, on,
//              0.0545, 0.0545/3, 0.0545/3, 0.02633, 0.03633,
//              0.01362, 0.001, 0.001/5, 20,
//              DUCA_TexturaPrincipal, DUCA_TexturaMetalica,
//              DUCA_TexturaAdhesiva, DUCA_TexturaSoporteAdhesivo )
//  }
//        
//  Con modificadores
//  #include "DUCA.inc"
//  #include "textures.inc"
//  #declare DUCA_TexturaPrincipal   = texture { PinkAlabaster } 
//  object        { DUCA_Cinta( 1.0, on ) }
//
#if ( version >= 3.7 )
  #version 3.7; 
#end

global_settings { assumed_gamma 1.0 }

#include "colors.inc"

#declare EjeMejorado            = false;
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

#include "DUCA.inc"

#local FactorAcercamiento       = 20.0;

object                                  {
  DUCA_Cinta( 1.0, true )    
  translate     -0.027*y-0.007*x
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}

