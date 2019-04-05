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


#include "RABA.inc"

#local FactorAcercamiento       = 20.0;

object                          {   
  RABA_Rasuradora()
  translate                     +0.024*y  
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}
