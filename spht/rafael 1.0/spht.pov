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
//  SPHT (SprayerProfessionalHandTool)
//  el archivo dibuja un rociador simple, como los utilizados 
//  en jardineria y limpieza domestica.
//  Tiene una macro para cambiar algunas caracteristicas y las texturas,
//  pero es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene dos parametros.
//  #macro SPHT_Sprayer( BanderaTapilla, FraccionPress )
//          BanderaTapilla          : "on" dibuja la tapilla que tapa la boca del
//              rociador. "off" no la dibuja.
//          FraccionPress           : Fraccion propia o unitaria para presionar el
//              disparador. Utilice "0" para liberar el boton.
//        
//  La siguiente macro permite un mayor control de las caracteristicas.
//  #macro SPHT_SprayerProfessionalHandTool( BanderaTapilla, FraccionPress,
//                  DiametroRecipiente, DiametroBoquilla, 
//                  AltoRecipiente, AltoSprayer,
//                  TexturaRecipiente, TexturaSprayer,
//                  TexturaPress, TexturaSuccion )
//          BanderaTapilla          : "on" dibuja la tapilla que tapa la boca del
//              rociador. "off" no la dibuja.
//          FraccionPress           : Fraccion propia o unitaria para presionar el
//              disparador. Utilice "0" para no apretar.
//          DiametroRecipiente      : Diametro del recipiente contenedor del liquido.
//              Valor por defecto 64*L.
//          DiametroBoquilla        : Diametro de la union con el rociador.
//              Valor por defecto 18*L.
//          AltoRecipiente          : Alto del recipiente contenedor del liquido anterior
//              a la boquilla. Valor por defecto 86*L.
//          AltoSprayer             : Referencia para el tamano de la pistola rociadora.
//              Valor por defecto 50*L.
//          TexturaRecipiente       : Textura del recipiente para el liquido.
//              Valor por defecto SPHT_TexturaRecipiente.
//          TexturaSprayer          : Textura principal de la pistola rociadora.
//              Valor por defecto SPHT_TexturaSprayer.
//          TexturaPress            : Textura del gatillo y otros elementos de la pistola.
//              Valor por defecto SPHT_TexturaPress.
//          TexturaSuccion          : Textura de la pajilla de succion.
//              Valor por defecto SPHT_TexturaSuccion.
//
//  El aparato por defecto tiene las siguientes dimensiones:
//      Minimo              = <  -43,    0,  -32 >*L
//      Maximo              = <  +32,  132,  +32 >*L
//  El recipiente descansa parcialmente centrado sobre el plano XZ, gravedad Y-.
//  La pistola apunta en sentido X-.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare SPHT_VolumenInterior
//      Define un objeto que puede utilizarse para rellenar de liquido el rociador.
//  #declare SPHT_VolumenSuccion
//      Define un objeto que puede utilizarse para rellenar de liquido la pajilla.
//  #declare SPHT_DefectoTexturaRecipiente
//      Textura del recipiente para el liquido.
//  #declare SPHT_DefectoTexturaSprayer
//      Textura principal de la pistola rociadora.
//  #declare SPHT_DefectoTexturaPress
//      Textura del gatillo y otros elementos de la pistola.
//  #declare SPHT_DefectoTexturaSuccion
//      Textura de la pajilla de succion.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default) 
//  #declare SPHT_RotateSuccion             = <2,2,2>;   
//      Se aplica este "rotate" en el extremo superior de la pajilla de succion.
//  #declare SPHT_FactorVolumenInterior     = 0.95;
//      Para evitar que el liquido entre en contacto perfecto con las paredes
//      interiores, se aplica esta contraccion. El ajuste perfecto en ocasiones produce
//      defectos en el dibujo final.
//  #declare SPHT_FactorVolumenSuccion      = 0.95;
//      Para evitar que el liquido de la pajilla de succion tenga contacto perfecto
//      con la superficie interior de la pajilla se disminuye el radio por este factor.
//  #declare SPHT_TexturaRecipiente                 =
//                  { SPHT_DefectoTexturaRecipiente             }
//      Textura del recipiente para el liquido.
//  #declare SPHT_TexturaSprayer                    =
//                  { SPHT_DefectoTexturaSprayer                }
//      Textura principal de la pistola rociadora.
//  #declare SPHT_TexturaPress                      =
//                  { SPHT_DefectoTexturaPress                  }
//      Textura del gatillo y otros elementos de la pistola.
//  #declare SPHT_TexturaSuccion                    =
//                  { SPHT_DefectoTexturaSuccion                }
//      Textura de la pajilla de succion.
//       
//  Para colocarlo simplemente
//  #include "SPHT.inc" 
//  object { SPHT_Sprayer( on, 0.0 ) }
//
//  Con relleno
//  #include "SPHT.inc" 
//  union           {
//    object { SPHT_Sprayer( on, 0.0 ) }
//    object {
//      SPHT_VolumenInterior
//      pigment { Orange }
//    }  
//  }
//                                  
//  Ejemplo con la macro detallada, mismo objeto por defecto
//  #include "SPHT.inc"   
//  object                       {
//    SPHT_SprayerProfessionalHandTool( on, 0.0, 0.064, 0.018, 0.086, 0.050,
//        SPHT_TexturaRecipiente, SPHT_TexturaSprayer,
//        SPHT_TexturaPress, SPHT_TexturaSuccion )
//  }
//        
//  Con modificadores
//  #include "SPHT.inc"
//  #include "textures.inc"
//  #declare SPHT_TexturaRecipiente   = texture { PinkAlabaster } 
//  object        { SPHT_Sprayer( on, 0.0 ) }
//  
#if ( version >= 3.7 )
  #version 3.7; 
#end

global_settings { assumed_gamma 1.0 }

#include "colors.inc"

#local OjoAbsoluto            = 256;
#local VecesCentroAbsoluto    = 10;
#local L                      = 0.001;

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

#local FactorAcercamiento           = 10;

#include "SPHT.inc"

object                  {
  SPHT_Sprayer( on, 0.0 )
  translate             -0.065*y
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}





