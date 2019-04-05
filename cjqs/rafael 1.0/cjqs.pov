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
//  CJQS CristaleriaJuegoQuimicaSupervisado
//  El archivo dibuja un erlenmeyer, tubo de ensayo y gotero para juego de quimica.
//  Posee una macro para modificar las caracteristicas principales, pero 
//  es muy poco flexible. Es compatible con POVRay 3.1.
//
//  Las tres macros principales no tienen parametros. Para el erlenmeyer, se utiliza:
//  #macro CJQS_Erlenmeyer()
//
//  Para el tubo de ensayo, se invoca la siguiente macro:
//  #macro CJQS_TuboEnsayo()
//
//  Para el gotero, se llama la siguiente macro:
//  #macro CJQS_Gotero()
//
//  El detalle del Erlenmeyer puede modificarse ligeramente con la siguiente macro:     
//  #macro CJQS_ErlenmeyerDetalle( DiametroMayor, DiametroMenor,
//      AltoErlenmeyer, AltoDiametroMayor, AltoDiametroMenor,
//      GruesoVidrio, GruesoLinea, MaterialVidrio )   
//          DiametroMayor                   : Diametro mayor del erlenmeyer.
//              Valor por defecto 46*L.
//          DiametroMenor                   : Diametro menor del erlenmeyer.
//              Valor por defecto 16*L.
//          AltoErlenmeyer                  : Alto del erlenmeyer.
//              Valor por defecto 75*L.
//          AltoDiametroMayor               : Alto del diametro mayor respecto a la base. 
//              Valor por defecto 9*L.
//          AltoDiametroMenor               : Alto del diametro menor respecto a la base.
//              Valor por defecto 54*L.
//          GruesoVidrio                    : Grueso del vidrio del erlenmeyer.
//              Valor por defecto 1*L.
//          GruesoLinea                     : Para el grueso de la letra de inscripcion.
//              Valor por defecto 0.5*L.
//          MaterialVidrio                  : Material del vidrio.
//              Valor por defecto CJQS_MaterialVidrio.
//      
//  El tubo de ensayo puede modificarse con la siguiente macro:
//  #macro CJQS_TuboEnsayoDetalle( AltoTubo,
//      DiametroTubo, GruesoVidrio, MaterialVidrio )
//          AltoTubo                        : Alto del tubo de ensayo.
//              Valor por defecto 87*L.
//          DiametroTubo                    : Diametro principal del tubo.
//              Valor por defecto 11*L.
//          GruesoVidrio                    : Grueso del vidrio.
//              Valor por defecto 0.85*L.
//          MaterialVidrio                  : Material del vidrio.
//              Valor por defecto CJQS_MaterialVidrio.   
//
//  Para modificar el detalle del gotero se utiliza la siguiente macro: 
//  #macro CJQS_GoteroDetalle( DiametroGotero, LargoGotero,
//      LargoHule, DiametroTapa, LargoTapa,
//      GruesoVidrio, MaterialVidrio, MaterialHule, MaterialTapa )
//          DiametroGotero                  : Diametro del vidrio del gotero.
//              Valor por defecto 5*L.
//          LargoGotero                     : Largo total con el bulbo.
//              Valor por defecto 62*L.
//          LargoHule                       : Tamano en Y del bulbo de succion.
//              Valor por defecto 17*L.
//          DiametroTapa                    : Diametro de la tapilla plastica de union.
//              Valor por defecto 14*L.
//          LargoTapa                       : Tamano en Y de la tapilla plastica de union.
//              Valor por defecto 8*L.             
//          GruesoVidrio                    : Grueso del vidrio.
//              Valor por defecto 0.85*L.
//          MaterialVidrio                  : Material del vidrio.
//              Valor por defecto CJQS_MaterialVidrio.   
//          MaterialHule                    : Material del bulbo de succion.
//              Valor por defecto CJQS_MaterialHule.
//          MaterialTapa                    : Material de la tapa plastica de rosca.
//              Valor por defecto CJQS_MaterialTapa.
//                
//  El erlenmeyer es encuentra contenido entre las siguientes coordenadas:
//      Minimo          = <-23,  0,-23>*L
//      Maximo          = <+23,+75,+23>*L
//      Minimo          = <-DiametroMayor/2,              0, -DiametroMayor/2>
//      Maximo          = <+DiametroMayor/2, AltoErlenmeyer, +DiametroMayor/2>
//  El fondo del recipiente descansa sobre el plano XZ, en el hemisferio Y+.
//
//  El tubo de ensayo es encuentra contenido entre las siguientes coordenadas:
//      Minimo          = <- 6,  0,- 6>*L
//      Maximo          = <+ 6,+87,+ 6>*L
//      Minimo          = <-(DiametroTubo + GruesoVidrio)/2,        0,
//                         -(DiametroTubo + GruesoVidrio)/2>
//      Maximo          = <+(DiametroTubo + GruesoVidrio)/2, AltoTubo,
//                         +(DiametroTubo + GruesoVidrio)/2>
//  El fondo del tubo de ensayo inmediatamente sobre el plano XZ, en el hemisferio Y+.
//
//  El gotero es encuentra contenido entre las siguientes coordenadas:
//      Minimo          = <- 7,  0,- 7>*L
//      Maximo          = <+ 7,+62,+ 7>*L
//      Minimo          = <-DiametroTapa/2,          0, -DiametroTapa/2>
//      Maximo          = <+DiametroTapa/2, AltoGotero, +DiametroTapa/2>
//  La punta del gotero ligeramente por encima del plano XZ, en el hemisferio Y+.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores. 
//  #declare CJQS_DefectoMaterialVidrio            
//      Material para los instrumentos de vidrio.
//  #declare CJQS_DefectoMaterialHule            
//      Material para la goma de succion del gotero.
//  #declare CJQS_DefectoMaterialTapa                  
//      Material para la tapa sujetadora del gotero.      
//  #declare CJQS_ErlenmeyerInterior                = object { ... }
//      Volumen del interior del erlenmeyer. Un metodo simple para
//      dibujar liquido en su interior por interseccion.
//  #declare CJQS_TuboEnsayoInterior                = object { ... }
//      Volumen del interior del tubo de ensayo. Un metodo simple para
//      dibujar liquido en su interior por interseccion.
//  #declare CJQS_GoteroInterior                    = object { ... }
//      Volumen del interior del gotero. Un metodo simple para
//      dibujar liquido en su interior por interseccion.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare CJQS_LetraVisible                      = on;
//      Cuando activa "on" dibuja las marcas en el erlenmeyer. Si se desactiva
//      "off" no las dibuja.
//  #declare CJQS_PigmentLetra                      = pigment { White }
//      Cuando aplique se utilizara este pigmento para las marcas del erlenmeyer.
//  #declare CJQS_MaterialVidrio                    =
//                  { CJQS_DefectoMaterialVidrio                  }
//      Material para los instrumentos de vidrio.
//  #declare CJQS_MaterialHule                      =
//                  { CJQS_DefectoMaterialHule                    }
//      Material para la goma de succion del gotero.
//  #declare CJQS_MaterialTapa                      =
//                  { CJQS_DefectoMaterialTapa                    }  
//      Material para la tapa sujetadora del gotero.
//       
//  Para colocarlo simplemente
//  #include "CJQS.inc" 
//  object { CJQS_Erlenmeyer(  ) translate... }
//  object { CJQS_TuboEnsayo(  ) translate... }
//  object { CJQS_Gotero(  ) translate... }
//   
//  Un tubo de ensayo con liquido
//  #include "CJQS.inc" 
//  union                               {
//    object { CJQS_TuboEnsayo(  ) }
//    intersection                      {
//      object { CJQS_TuboEnsayoInterior }
//      box    { <-0.010,0,-0.010>, <+0.010,0.030,+0.010> } 
//      pigment { Cyan }
//    }
//  }
//                               
//  Ejemplo con la macro detallada, mismos objetos por defecto
//  #include "CJQS.inc"   
//  object                       {
//    CJQS_ErlenmeyerDetalle( 0.046, 0.016, 0.075, 0.009, 0.054, 
//        0.001, 0.0005, CJQS_MaterialVidrio )
//    translate ...
//  }
//  object                       {
//    CJQS_TuboEnsayoDetalle( 0.087, 0.011, 0.00085, CJQS_MaterialVidrio )
//    translate ...
//  }
//  object                       {
//    CJQS_GoteroDetalle( 0.005, 0.062, 0.017, 0.014, 0.008, 0.00085,
//        CJQS_MaterialVidrio, CJQS_MaterialHule, CJQS_MaterialTapa )
//    translate ...
//  }
//        
//  Con modificadores
//  #include "CJQS.inc"
//  #include "textures.inc"
//  #declare CJQS_MaterialTapa         = material { texture { PinkAlabaster } } 
//  object        { CJQS_Gotero(  ) }
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

#include "CJQS.INC"
 
#local FactorAcercamiento       = 12;
 
union                          {
  object { CJQS_TuboEnsayo() translate -0.050*x }
  object { CJQS_Erlenmeyer() }
  object { CJQS_Gotero()     translate +0.050*x+0.020*y }
  translate             -0.045*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z  
}



