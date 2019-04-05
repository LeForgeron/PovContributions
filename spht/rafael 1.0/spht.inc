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
#include "SPHT_AUX.inc"
#include "colors.inc"

#declare SPHT_L                         = 0.001;

#declare SPHT_RotateSuccion             = <2,2,2>;   
#declare SPHT_FactorVolumenInterior     = 0.95;
#declare SPHT_FactorVolumenSuccion      = 0.95;

#declare SPHT_DefectoTexturaRecipiente  =
  texture                               {
    pigment                             {
      color Blue
      transmit  0.9
    }
  }

#ifndef ( SPHT_TexturaRecipiente )
  #declare SPHT_TexturaRecipiente       = SPHT_DefectoTexturaRecipiente
#end  //  #ifndef ( SPHT_TexturaRecipiente )

#declare SPHT_DefectoTexturaSprayer     =
  texture                               {
    pigment                             {
      color White
    }
  }

#ifndef ( SPHT_TexturaSprayer )
  #declare SPHT_TexturaSprayer          = SPHT_DefectoTexturaSprayer
#end  //  #ifndef ( SPHT_TexturaSprayer )

#declare SPHT_DefectoTexturaPress       =
  texture                               {
    pigment                             {
      color Blue
      transmit  0.5
    }
  }

#ifndef ( SPHT_TexturaPress )
  #declare SPHT_TexturaPress            = SPHT_DefectoTexturaPress
#end  //  #ifndef ( SPHT_TexturaPress )

#declare SPHT_DefectoTexturaSuccion       =
  texture                               {
    pigment                             {
      color Blue
      transmit  0.9
    }
  }

#ifndef ( SPHT_TexturaSuccion )
  #declare SPHT_TexturaSuccion            = SPHT_DefectoTexturaSuccion
#end  //  #ifndef ( SPHT_TexturaSuccion )

#macro SPHT_SprayerProfessionalHandTool( BanderaTapilla, FraccionPress,
             DiametroRecipiente, DiametroBoquilla, 
             AltoRecipiente, AltoSprayer,
             TexturaRecipiente, TexturaSprayer,
             TexturaPress, TexturaSuccion )
  union                                 {
    #local AltoBoquilla                 = 0.214*AltoSprayer;
    #local TotalOndulado                = 14;
    #local FactorBoquilla               =
                DiametroBoquilla/DiametroRecipiente;
    #local RecipienteBasico             =
      difference                          {
        union                             {
          lathe                             {
            cubic_spline
            12,
            <-0.70,  0.0125 >,
            < 0.00,  0.025 >,
            < 0.70,  0.0125 >,
            < 0.80,  0.00 >,
            < 0.95,  0.20 >,
            < 1.00,  0.60 >,
            < 0.95,  0.70 >,
            < 0.60,  0.80 >,
            < 1.25*FactorBoquilla, 0.95 >,
            < 1.05*FactorBoquilla, 0.96 >,
            < FactorBoquilla, 1.0 >,
            < FactorBoquilla, 1.1 >
          }
        }
        #local C                  = 0;
        #while ( C < TotalOndulado )
          union                           {
            cylinder                      {
              -2*y, 2*y, 0.1
              scale               <1,1,1.5>
            }
            rotate                -15*z
            translate                  1.1*x+y
            rotate                C*360/TotalOndulado*y
          }
          #local C                        = C+1;
        #end  //  #while ( C < TotalOndulado )
        translate         -0.5*y
        scale  < DiametroRecipiente/2, AltoRecipiente, DiametroRecipiente/2 >
      }

    union                               {
      //  Recipiente Principal
      difference                          {
        object                            {
          RecipienteBasico
        }
        object                            {
          RecipienteBasico
          scale  0.975
        }
        cylinder                          {
          0, AltoRecipiente*y, 0.975*DiametroBoquilla/2
        }
        translate         AltoRecipiente/2*y
      }
      //  END Recipiente Principal
      //  Union Sprayer
      union                             {
        difference                      {
          union                         {
            cylinder                      {
              0, AltoBoquilla*y,
              DiametroBoquilla/2
            }
            cylinder                    {
              0, 0.1*AltoBoquilla*y,
              1.25*DiametroBoquilla/2
            }
            cylinder                    {
              0, 0.1*AltoBoquilla*y,
              1.10*DiametroBoquilla/2
              translate         0.3*AltoBoquilla*y
            }
            cylinder                    {
              0, 0.1*AltoBoquilla*y,
              1.10*DiametroBoquilla/2
              translate         0.6*AltoBoquilla*y
            }
          }
          cylinder                      {
            -0.1*AltoBoquilla*y, 1.1*AltoBoquilla*y,
            0.975*DiametroBoquilla/2
          }
        }
        translate                       AltoRecipiente*y
      }
      //  END Union Sprayer
      texture                           {
        TexturaRecipiente
      }
    }
    difference                          {
      cylinder                          {
        0.2*AltoRecipiente*y, ( AltoRecipiente+AltoBoquilla )*y,
        0.1*DiametroBoquilla
      }
      cylinder                          {
        0, ( AltoRecipiente+AltoSprayer )*y,
        0.085*DiametroBoquilla
      }
      translate         -( AltoRecipiente+AltoBoquilla )*y
      rotate    SPHT_RotateSuccion
      translate         +( AltoRecipiente+AltoBoquilla )*y
      texture                           {
        TexturaSuccion
      }
    }
    union                               {
      union                             {
        #local FB                       = 1.25;
        difference                      {
          object                          {
            SPHT_LateralBlanco
          }
          object                          {
            SPHT_Hueco
            scale       <1,1.1,1>
          }
          transform       SPHT_LateralBlanco_NORMAL_TRANSFORM
          rotate          -90*x
          scale           < AltoSprayer,AltoSprayer, FB*DiametroBoquilla/4 >
        }
        union                           {
          #local PuntoGiro              =
                  < -0.425, 0.025, 0 >*AltoSprayer;
          cylinder                      {
            -FB*DiametroBoquilla/3*z, FB*DiametroBoquilla/3*z,
            DiametroBoquilla/15
            texture                     {
              TexturaPress
            }
            translate           PuntoGiro
          }
          object                          {
            SPHT_LateralPress
            scale         <1,0.9,1>
            transform       SPHT_LateralBlanco_NORMAL_TRANSFORM
            rotate          -90*x
            scale           < AltoSprayer,AltoSprayer, FB*DiametroBoquilla/4 >
            texture                       {
              TexturaPress
            }
          }
          cylinder                              {
            -0.4*AltoSprayer*x-0.200*AltoSprayer*y,
            -0.2*AltoSprayer*x-0.100*AltoSprayer*y, FB*DiametroBoquilla/6
            texture                     {
              TexturaSprayer
            }
          }
          translate             -PuntoGiro
          rotate                FraccionPress*22*z
          translate             +PuntoGiro
        }
        union                           {
          cylinder                      {
            +0.1*AltoSprayer*x, -0.125*AltoSprayer*x, 0.7*FB*DiametroBoquilla/4
          }
          #local C                      = 0;
          #local TotV                   = 6;
          #while ( C < TotV )
            cylinder                    {
              0, -0.05*AltoSprayer*x/TotV*x, 0.75*FB*DiametroBoquilla/4
              translate -0.1*C*AltoSprayer*x/TotV
            }
            #local C                    = C+1;
          #end
          cylinder                              {
            -0.125*AltoSprayer*x, -0.140*AltoSprayer*x,
            0.7*FB*DiametroBoquilla/4
            texture                     {
              TexturaPress
            }
          }
          cylinder                              {
            -0.175*AltoSprayer*x, -0.140*AltoSprayer*x,
            0.7*FB*DiametroBoquilla/4
            texture                     {
              TexturaRecipiente
            }
          }
          #if ( BanderaTapilla )
          difference                    {
            cone                        {
              -0.180*AltoSprayer*x, 0.8*FB*DiametroBoquilla/4,
              -0.01*AltoSprayer*x, 1.0*FB*DiametroBoquilla/4
            }
            cone                        {
              -0.177*AltoSprayer*x, 0.75*FB*DiametroBoquilla/4,
              -0.0099*AltoSprayer*x, 0.95*FB*DiametroBoquilla/4
            }
            texture                             {
              TexturaPress
            }
          }
          #end  //  #if ( BanderaTapilla )
          rotate                -20*z
          translate             -0.5*AltoSprayer*x+0.14*AltoSprayer*y
        }
        translate               AltoRecipiente*y+0.65*AltoSprayer*y
      }
      union                             {
        difference                      {
          union                         {
            cylinder                    {
              0.2*AltoBoquilla*y, 1.2*AltoBoquilla*y,
              1.175*DiametroBoquilla/2
            }
            cylinder                    {
              0.2*AltoBoquilla*y, 0.25*AltoBoquilla*y,
              1.25*DiametroBoquilla/2
            }
            #local TotalCil             = 24;
            #local C                    = 0;
            #while ( C < TotalCil )
              cylinder                  {
                0.2*AltoBoquilla*y, 0.9*AltoBoquilla*y,
                0.05*DiametroBoquilla/2
                translate               1.175*DiametroBoquilla/2*x
                rotate          C*360*y/TotalCil
              }
              #local C                  = C+1;
            #end
          }
          cylinder                      {
            0, 1.1*AltoBoquilla*y, 1.125*DiametroBoquilla/2
          }
          texture                       {
            TexturaPress
          }
        }
        union                           {
          cylinder                      {
            1.2*AltoBoquilla*y, 1.4*AltoBoquilla*y,
            1.175*DiametroBoquilla/2
          }
          cylinder                      {
            1.2*AltoBoquilla*y, AltoSprayer/2*y,
            0.9*DiametroBoquilla/2
          }
          sphere                      {
            AltoSprayer/2*y,
            0.9*DiametroBoquilla/2
          }
        }
        translate               AltoRecipiente*y
      }
      texture                           {
        TexturaSprayer
      }
    }
    texture                             {
      TexturaRecipiente
    }
    #declare SPHT_VolumenInterior       =
      object                            {
         RecipienteBasico
         scale          0.975*SPHT_FactorVolumenInterior
         translate      AltoRecipiente/2*y
      } 
    #declare SPHT_VolumenSuccion        =  
      cylinder                          {
        0.2*AltoRecipiente*y, ( AltoRecipiente+AltoBoquilla )*y,
        0.085*DiametroBoquilla*SPHT_FactorVolumenSuccion
        translate         -( AltoRecipiente+AltoBoquilla )*y
        rotate    SPHT_RotateSuccion
        translate         +( AltoRecipiente+AltoBoquilla )*y
      }
  }  
#end  // #macro SPHT_SprayerProfessionalHandTool()

#macro SPHT_Sprayer( BanderaTapilla, FraccionPress )
  object                                {
    #local L                            = SPHT_L;
    #local DiametroRecipiente           = 64*L;
    #local DiametroBoquilla             = 18*L;
    #local AltoRecipiente               = 86*L;
    #local AltoSprayer                  = 50*L;
    SPHT_SprayerProfessionalHandTool( BanderaTapilla, FraccionPress,
        DiametroRecipiente, DiametroBoquilla, 
        AltoRecipiente, AltoSprayer,
        SPHT_TexturaRecipiente, SPHT_TexturaSprayer,
        SPHT_TexturaPress, SPHT_TexturaSuccion )
  }
#end  // #macro SPHT_Sprayer()
