// This file is licensed under the terms of the CC-LGPL.
//
// Autor  : Rafael Angel Campos Vargas
// Correo : RofoelCompos@hotmail.com  
// Apdo. 964-1250 Escazu, San Jose, Costa Rica
// dedicado a Jesus y Maria...
//
// En este momento estoy creando un programa
// de animacion LibreN3D para FreeDOS con el compilador FreePascal
// falta mucho... 05 abril 2018
//                
// Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
// 1 L equivale a 0.055063 pulgadas 
// definido como 0.001 para POVRAY.
//     
// BDCP BluerayDvdCdPlayer
// El archivo dibuja un reproductor de video para discos en formato Bluray.
// Puede cambiar la hora, abrir y cerrar el compartimento para discos, y
// otras modificaciones menores.
// Es muy poco flexible. Es compatible con POVRay 3.1.
//
// La macro principal tiene cuatro parametros.
// #macro BDCP_Bluray( FraccionAbrir, Hora, Minuto, ModoIndicador )
//          FraccionAbrir       : Fraccion propia para cerrar 0.0 
//              o abrir 1.0 el compartimento de discos.
//          Hora                : Hora del reloj.
//          Minuto              : Minuto del reloj.
//          ModoIndicador       : 1 para "on", 2 para "off", 0 inactivo.
//
// La siguiente macro permite un mayor control de las caracteristicas.
// #macro BDCP_BlurayDvdCdPlayer( FraccionAbrir, Hora, Minuto, ModoIndicador, 
//            FrenteBluray, FraccionFrontal, FraccionInferior,
//            AltoBluray, PatasBluray, ProfundidadBluray,
//            AltoBandeja, RadioCD, GruesoCD, 
//            GruesoPlastico, BocaUSB, GruesoUSB,
//            ArregloMateriales, ArregloTexturasLED )
//          FraccionAbrir       : Fraccion propia para cerrar 0.0 
//              o abrir 1.0 el compartimento de discos.
//          Hora                : Hora del reloj.
//          Minuto              : Minuto del reloj.
//          ModoIndicador       : 1 para "on", 2 para "off", 0 inactivo.   
//          FrenteBluray        : Frente del aparato de video.
//              Valor por defecto 308*L.
//          FraccionFrontal     : Fraccion que
//              divide la textura frontal de la posterior.
//              Valor por defecto 0.15.
//          FraccionInferior    : Fraccion que ubica la cuna decorativa frontal.
//              Valor por defecto 0.4.
//          AltoBluray          : Alto del aparato de video.
//              Valor por defecto 43.6*L.
//          PatasBluray         : Alto total de las patillas soporte.
//              Valor por defecto 4.5*L.
//          ProfundidadBluray   : Profundidad en Z del aparato de video.
//              Valor por defecto 154.4*L.
//          AltoBandeja         : Alto de la bandeja soporte para CD.
//              Valor por defecto 13*L.
//          RadioCD             : Radio de un disco CD.
//              Valor por defecto 42.7*L.
//          GruesoCD            : Grueso de un disco CD.
//              Valor por defecto 0.5*L.                                                                    
//          GruesoPlastico      : Grueso de plastico para soportes interiores.
//              Valor por defecto 1*L.
//          BocaUSB             : Frente de la boquilla de un conector USB.
//              Valor por defecto 8.2*L.
//          GruesoUSB           : Alto de la boquilla de un conector USB.
//              Valor por defecto 2.7*L.
//          ArregloMateriales   : Lista de los materiales principales.
//              array [6] = { MaterialPrincipal, MaterialFrontal,
//                            MaterialBandeja, MaterialFrenteBandeja,
//                            MaterialLetras, MaterialMetalico }
//              Valor por defecto similar a BDCP_DefaultArregloMateriales
//                  MaterialPrincipal       : Material del cuerpo principal
//                  MaterialFrontal         : Material para el frente
//                  MaterialBandeja         : Material para el interior de la bandeja
//                  MaterialFrenteBandeja   : Material para el frente de la bandeja
//                  MaterialLetras          : Material para algunas letras en la bandeja
//                  MaterialMetalico        : Material para elementos metalicos 
//          ArregloTexturasLED  : Lista de texturas para el reloj               
//              array[4] = { TexturaLabelLED, TexturaTransparente,
//                           TexturaLED, TexturaFondoLED } 
//              Valor por defecto similar a BDCP_DefaultArregloTexturasLED 
//                  TexturaLabelLED         : Textura del cuerpo soporte del reloj
//                  TexturaTransparente     : Textura de capa protectora del LED
//                  TexturaLED              : Textura de digitos
//                  TexturaFondoLED         : Textura de fondo del reloj 
//
// Para dibujar otros aparatos similares, se suministra la siguiente macro para dibujar
// la bandeja para CD en forma independiente, 
// de forma que el usuario pueda incorporarla en sus propios objetos.
// #macro BDCP_BandejaInterior( FrenteBandeja, AltoBandeja,
//                ProfundidadDelantera, RadioCD, RadioMini,
//                RadioAire, GruesoPlastico, CurvaturaPlastico, GruesoCD,
//                MaterialBandeja, MaterialFrenteBandeja,
//                MaterialLetras )    
//          FrenteBandeja           : Frente exterior de la bandeja.
//              Valor por defecto 94.5*L.
//          AltoBandeja             : Alto de la bandeja soporte para CD.
//              Valor por defecto 13*L.  
//          ProfundidadDelantera    : Profundidad Z hasta el centro para ubicar el CD.
//              Valor por defecto 51*L.
//          RadioCD                 : Radio de un disco CD.
//              Valor por defecto 42.7*L. 
//          RadioMini               : Radio para un mini disco CD.
//              Valor por defecto 28*L.
//          RadioAire               : Radio para la perforacion vacia interior.
//              Valor por defecto 20*L.
//          GruesoPlastico          : Grueso de plastico para soportes interiores.
//              Valor por defecto 1*L.
//          CurvaturaPlastico       : Radio de curvatura para decorar extremos y bordes.
//              Valor por defecto 1*L.
//          GruesoCD                : Grueso de un disco CD.
//              Valor por defecto 0.5*L. 
//          MaterialBandeja         : Material para el interior de la bandeja.
//              Valor por defecto BDCP_DefaultMaterialBandeja.
//          MaterialFrenteBandeja   : Material para el frente de la bandeja.
//              Valor por defecto BDCP_DefaultMaterialFrenteBandeja.
//          MaterialLetras          : Material para letras y logo.
//              Valor por defecto BDCP_DefaultMaterialLetras.                                                                  
//
// El aparato cerrado se encuentra entre las siguientes dimensiones:
//      Minimo      = < -154,    0,  -80 >*L
//      Maximo      = < +154,  +44,  +80 >*L
// El objeto se encuentra por completo en el hemisferio Y+, 
// y las patas se encuentran directamente sobre el plano XZ. 
// La macro genera el parametro :
//      #declare BDCP_InferiorCD            : Vector de posicion para la cara
//          inferior del CD, en su centro matematico. El CD no se dibuja.
//
// Estas son variables predefinidas o generadas en el
// interior de las macros que no deberian modificarse directamente.
// Si quiere cambiarlas, recurra a los modificadores.  
// #declare BDCP_DefaultMaterialPrincipal  
//      Material principal del aparato.
// #declare BDCP_DefaultMaterialFrontal
//      Material del frente del reproductor de discos de video.    
// #declare BDCP_DefaultMaterialMetalico                       
//      Material para elementos metalicos.
// #declare BDCP_DefaultMaterialBandeja   
//      Material para la bandeja. 
// #declare BDCP_DefaultMaterialFrenteBandeja     
//      Material para el frente de la bandeja.
// #declare BDCP_DefaultMaterialLetras        
//      Material para letras y logo.
// #declare BDCP_DefaultTexturaLabelLED                
//      Textura para el soporte de LED.
// #declare BDCP_DefaultTexturaTransparente       
//      Textura transparente sobre LED.
// #declare BDCP_DefaultTexturaLED      
//      Textura para LED del reloj.          
// #declare BDCP_DefaultTexturaFondoLED   
//      Textura para el fondo de los LED.             
// #declare BDCP_DefaultArregloMateriales           = array[6]
//      Arreglo con los materiales por defecto en las macros.
// #declare BDCP_DefaultArregloTexturasLED          = array[4]    
//      Arreglo con las texturas por defecto para el reloj, 
//      que sirve como parametro en las macros.
//
// Los siguientes son los modificadores
// aplicables y redefinibles por el usuario (si se indica es default)
// #declare BDCP_StringLogo                         = "Pov-ray"   
//      Mensaje para el logo de marca.
// #declare BDCP_StringCompatible                   = "CGS-BLOB"    
//      Mensaje para compatibilidad.
// #declare BDCP_Logo                               = Povray_Logo
//      Para cambiar el logo de marca si se desea.
// #declare BDCP_MaterialPrincipal                  = material { ... }
//      Material principal del aparato.
// #declare BDCP_MaterialFrontal                    = material { ... }
//      Material del frente del reproductor de discos de video.    
// #declare BDCP_MaterialMetalico                   = material { ... }
//      Material para elementos metalicos.
// #declare BDCP_MaterialBandeja                    = material { ... }
//      Material para la bandeja. 
// #declare BDCP_MaterialFrenteBandeja              = material { ... }
//      Material para el frente de la bandeja.
// #declare BDCP_MaterialLetras                     = material { ... }
//      Material para letras y logo.
// #declare BDCP_TexturaLabelLED                    = texture  { ... }
//      Textura para el soporte de LED.
// #declare BDCP_TexturaTransparente                = texture  { ... }
//      Textura transparente sobre LED.
// #declare BDCP_TexturaLED                         = texture  { ... }
//      Textura para LED del reloj.          
// #declare BDCP_TexturaFondoLED                    = texture  { ... }
//      Textura para el fondo de los LED.             
//        
// Para colocarlo simplemente
// #include "BDCP.inc" 
// object { BDCP_Bluray( 1.0, 10, 20, 1 ) }
//                                  
// Ejemplo con la macro detallada, mismo objeto default
// #include "BDCP.inc"   
// object                       {
//   BDCP_BlurayDvdCdPlayer( 1.0, 10, 20, 1,
//        0.308, 0.15, 0.4, 0.0436, 0.0045, 0.1544,  
//        0.013, 0.0427, 0.0005, 0.001, 0.0082, 0.0027,
//        BDCP_DefaultArregloMateriales, BDCP_DefaultArregloTexturasLED )
// }
//        
// Con modificadores
// #include "BDCP.inc"
// #include "textures.inc"
// #declare BDCP_MaterialPrincipal   = material { texture { PinkAlabaster } }
// object        { BDCP_Bluray( 1.0, 10, 20, 1 ) }
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

#include "BDCP.inc"

#local FactorAcercamiento       = 5;

union                          {
  BDCP_Bluray( 1.0, 10, 20, 1 )  
  translate        -0.021*y      
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}  

