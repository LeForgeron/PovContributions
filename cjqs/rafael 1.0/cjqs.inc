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
#include "textures.inc"
#include "glass.inc"
#declare CJQS_L                 = 0.001;  
#declare CJQS_LetraVisible      = on;
#declare CJQS_PigmentLetra      = pigment { White }

#declare CJQS_DefectoMaterialVidrio             =
  material                                      {
    texture                                     {
      T_Glass4
      normal                                    {
        bumps
      }
      finish                                    {
        F_Glass4
      }
    }
    interior { I_Glass }
  }

#ifndef ( CJQS_MaterialVidrio )
  #declare CJQS_MaterialVidrio                  =
                CJQS_DefectoMaterialVidrio
#end  //  #ifndef ( CJQS_MaterialVidrio )

#declare CJQS_DefectoMaterialHule               =
  material                                      {
    texture                                     {
      Cork
    }
    texture                                     {
      pigment                                   {
        color rgbt <0.1,0.1,0.1,0.25>
      }
    }
  }

#ifndef ( CJQS_MaterialHule  )
  #declare CJQS_MaterialHule                    =
                CJQS_DefectoMaterialHule 
#end  //  #ifndef ( CJQS_MaterialHule  )

#declare CJQS_DefectoMaterialTapa               =
  material                                      {
    texture                                     {
      pigment { White }
      normal  { radial frequency 40 sine_wave }
    }
    texture                                     {
      pigment { color White transmit 0.25 }
      normal { bumps }
    }
  }

#ifndef ( CJQS_MaterialTapa )
  #declare CJQS_MaterialTapa                    =
                CJQS_DefectoMaterialTapa
#end  //  #ifndef ( CJQS_MaterialTapa )

#macro CJQS_TuboEnsayoDetalle( AltoTubo,
                DiametroTubo, GruesoVidrio, MaterialVidrio )
  merge                                         {
    difference                                  {
      sphere                                    {
        0, DiametroTubo/2
      }
      sphere                                    {
        0, DiametroTubo/2-GruesoVidrio
      }
      plane                                     {
        -y, 0
      }
      translate                 DiametroTubo/2*y
    }
    torus                                       {
      DiametroTubo/2, GruesoVidrio/2
      translate         ( AltoTubo-GruesoVidrio/2 )*y
    }
    difference                                  {
      cylinder                                  {
        0, ( AltoTubo-DiametroTubo/2 )*y, DiametroTubo/2
      }
      cylinder                                  {
        -GruesoVidrio*y, AltoTubo*y, DiametroTubo/2-GruesoVidrio
      }
      translate                 DiametroTubo/2*y
    }
    material                                    {
      MaterialVidrio
    }
    #declare CJQS_TuboEnsayoInterior            =
      union                                   {
        sphere                                    {
          0, DiametroTubo/2-1.1*GruesoVidrio
          translate   DiametroTubo/2*y
        }
        cylinder                                  {
          DiametroTubo/2*y, AltoTubo*y, DiametroTubo/2-1.1*GruesoVidrio
        }
      }
  }
#end  // #macro CJQS_TuboEnsayoDetalle()

#macro CJQS_ErlenmeyerDetalle( DiametroMayor, DiametroMenor,
    AltoErlenmeyer, AltoDiametroMayor, AltoDiametroMenor,
    GruesoVidrio, GruesoLinea, MaterialVidrio )
  union                                         {
    #local PivoteLado           = sqrt(
      ( AltoDiametroMenor-AltoDiametroMayor )*
      ( AltoDiametroMenor-AltoDiametroMayor )+
      ( DiametroMayor/2-AltoDiametroMayor )*
      ( DiametroMayor/2-AltoDiametroMayor ) );
    #local AnguloParedR         = atan2( DiametroMayor/2-AltoDiametroMayor,
        AltoDiametroMenor-AltoDiametroMayor )+
        asin( AltoDiametroMayor/PivoteLado );
    difference                                  {
      merge                                     {
        torus                                   {
          DiametroMayor/2-AltoDiametroMayor, AltoDiametroMayor
          translate             AltoDiametroMayor*y
        }
        cylinder                                {
          0.05*GruesoVidrio*y, GruesoVidrio*y,
          DiametroMayor/2-AltoDiametroMayor
        }
        cone            {
          AltoDiametroMayor*( 1+sin( AnguloParedR ) )*y,
          DiametroMayor/2-AltoDiametroMayor*( 1-cos( AnguloParedR ) ),
          AltoDiametroMenor*y, DiametroMenor/2
        }
        cylinder                        {
          AltoDiametroMenor*y, AltoErlenmeyer*y, DiametroMenor/2
        }
        merge                           {
          cone                            {
            AltoErlenmeyer*y, 1.2*DiametroMenor/2,
            ( AltoErlenmeyer-0.2*DiametroMenor/2 )*y, DiametroMenor/2
          }
          torus                         {
            1.2*DiametroMenor/2-GruesoVidrio*sqrt(2)/2,
            GruesoVidrio*sqrt(2)/2
            translate   AltoErlenmeyer*y
          }
          translate             -GruesoVidrio*sqrt(2)/2*y
        }
      }
      torus                                   {
        DiametroMayor/2-AltoDiametroMayor, AltoDiametroMayor-GruesoVidrio
        translate             AltoDiametroMayor*y
      }
      cone            {
        AltoDiametroMayor*( 1+sin( AnguloParedR ) )*y
        -GruesoVidrio*sin( AnguloParedR )*y,
        DiametroMayor/2-AltoDiametroMayor*( 1-cos( AnguloParedR ) )
        -GruesoVidrio*cos( AnguloParedR ),
        1.001*AltoDiametroMenor*y, DiametroMenor/2
        -GruesoVidrio/cos( AnguloParedR )
      }
      cylinder                                  {
        AltoDiametroMayor*y, AltoErlenmeyer*y, DiametroMenor/2-GruesoVidrio
      }
      cylinder                                  {
        GruesoVidrio*y, 2*AltoDiametroMayor*y,
        DiametroMayor/2-AltoDiametroMayor
      }
      cone                            {
        AltoErlenmeyer*y, 1.2*DiametroMenor/2-GruesoVidrio,
        ( AltoErlenmeyer-1.2*DiametroMenor/2+GruesoVidrio )*y, 0
      }
    }      
    #if ( CJQS_LetraVisible )
        difference                          {
          union                             {
            difference                        {
              union                           {
                cylinder                        {
                  0, GruesoLinea*y, DiametroMayor/2
                  translate 0.8*( AltoDiametroMenor-AltoDiametroMayor )*y
                }
                cylinder                        {
                  0, GruesoLinea*y, DiametroMayor/2
                  translate 0.4*( AltoDiametroMenor-AltoDiametroMayor )*y
                }
                cylinder                        {
                  0, GruesoLinea*y, DiametroMayor/2
                  translate 0.2*( AltoDiametroMenor-AltoDiametroMayor )*y
                }
              }
              plane                           {
                x, 0
                rotate      20*y
              }
              plane                           {
                -x, 0
                rotate   0*y
              }
            }
            text                            {
              ttf "timrom.ttf", "44", 1, 0
              translate             -0.5*z
              scale  7.5*GruesoLinea*<1,1,0>+z
              translate 0.18*( AltoDiametroMenor-AltoDiametroMayor )*y
              rotate     -5*y
            }
            text                            {
              ttf "timrom.ttf", "74", 1, 0
              translate             -0.5*z
              scale  7.5*GruesoLinea*<1,1,0>+z
              translate 0.38*( AltoDiametroMenor-AltoDiametroMayor )*y
              rotate     -5*y
            }
            text                            {
              ttf "timrom.ttf", "98", 1, 0
              translate             -0.5*z
              scale  7.5*GruesoLinea*<1,1,0>+z
              translate 0.78*( AltoDiametroMenor-AltoDiametroMayor )*y
              rotate     -5*y
            }
            cylinder                        {
              0, -DiametroMayor/2*z, 0.1*( AltoDiametroMenor-AltoDiametroMayor )
              translate 0.25*( AltoDiametroMenor-AltoDiametroMayor )*y
              rotate     +60*y
            }
            translate       AltoDiametroMayor*y
          }
          cone                                {
            AltoDiametroMenor*y, 0.996*DiametroMenor/2,
            AltoDiametroMayor*y, 0.996*DiametroMayor/2
          }
          cone                                {
            AltoDiametroMenor*y, 1.001*DiametroMenor/2,
            AltoDiametroMayor*y, 1.001*DiametroMayor/2
            inverse
          }          
          plane                               {
            -z, -0.9*DiametroMenor/2
          }            
          pigment { CJQS_PigmentLetra }
        }
    #end  //  #if ( CJQS_LetraVisible )
    material                                    {
      MaterialVidrio
    }
    #declare CJQS_ErlenmeyerInterior            =
      union                                     {
        torus                                   {
          DiametroMayor/2-AltoDiametroMayor, AltoDiametroMayor-1.1*GruesoVidrio
          translate             AltoDiametroMayor*y
        }
        cone            {
          AltoDiametroMayor*( 1+sin( AnguloParedR ) )*y
          -1.1*GruesoVidrio*sin( AnguloParedR )*y,
          DiametroMayor/2-AltoDiametroMayor*( 1-cos( AnguloParedR ) )
          -1.1*GruesoVidrio*cos( AnguloParedR ),
          AltoDiametroMenor*y, DiametroMenor/2
          -1.1*GruesoVidrio/cos( AnguloParedR )
        }
        cylinder                                  {
          AltoDiametroMayor*y, AltoErlenmeyer*y, DiametroMenor/2
          -1.1*GruesoVidrio
        }
        cylinder                                  {
          1.1*GruesoVidrio*y, 2*AltoDiametroMayor*y,
          DiametroMayor/2-AltoDiametroMayor
        }
        cone                            {
          AltoErlenmeyer*y, 1.2*DiametroMenor/2-1.1*GruesoVidrio,
          ( AltoErlenmeyer-1.2*DiametroMenor/2+1.1*GruesoVidrio )*y, 0
        }
      }
  }
#end  // #macro CJQS_ErlenmeyerDetalle

#macro CJQS_GoteroDetalle( DiametroGotero, LargoGotero,
       LargoHule, DiametroTapa, LargoTapa,
       GruesoVidrio, MaterialVidrio, MaterialHule, MaterialTapa )
  union                                         {
    difference                                  {
      #local Estrecho                           = 0.75;
      merge                                     {
        cone                                    {
          ( LargoGotero-LargoHule )*y, DiametroGotero/2,
          Estrecho*DiametroGotero/2*y, Estrecho*DiametroGotero/2
        }
        sphere                                  {
          Estrecho*DiametroGotero/2*y, Estrecho*DiametroGotero/2
        }
      }
      cone                                      {
        1.001*( LargoGotero-LargoHule )*y, DiametroGotero/2-GruesoVidrio,
        -GruesoVidrio*y, Estrecho*DiametroGotero/4
      }
    }
    union                                       {
      sphere                                    {
        ( LargoGotero-DiametroGotero/2-GruesoVidrio )*y,
        DiametroGotero/2+GruesoVidrio
      }
      cylinder                                  {
        ( LargoGotero-DiametroGotero/2-GruesoVidrio )*y,
        ( LargoGotero-LargoHule-2*GruesoVidrio )*y,
        DiametroGotero/2+GruesoVidrio      
      }
      cylinder                                  {
        ( LargoGotero-LargoHule-GruesoVidrio )*y,
        ( LargoGotero-LargoHule-2*GruesoVidrio )*y,
        DiametroTapa/2-2*GruesoVidrio
      }
      material                                  {
        MaterialHule
      }
    }
    difference                                {
      union                                     {
        cylinder                                  {
          ( LargoGotero-LargoHule )*y,
          ( LargoGotero-LargoHule-LargoTapa )*y,
          0.975*DiametroTapa/2
        }
        cylinder                                  {
          ( LargoGotero-LargoHule-LargoTapa+GruesoVidrio )*y,
          ( LargoGotero-LargoHule-LargoTapa )*y,
          DiametroTapa/2
        }
      }
      cylinder                                {
        ( LargoGotero-LargoHule-GruesoVidrio )*y,
        ( LargoGotero-LargoHule-2*LargoTapa )*y,
        DiametroTapa/2-GruesoVidrio
      }
      material                                  {
        MaterialTapa
      }
    }
    material                                    {
      MaterialVidrio
    }
    #declare CJQS_GoteroInterior                =
      intersection                              {
        cone                                      {
          ( LargoGotero-LargoHule )*y, DiametroGotero/2-1.1*GruesoVidrio,
          -GruesoVidrio*y, Estrecho*DiametroGotero/4-0.1*GruesoVidrio
        }
        box                                     {
          <-DiametroGotero,LargoGotero-LargoHule-LargoTapa,-DiametroGotero>,
          <DiametroGotero,Estrecho*DiametroGotero/4,DiametroGotero>
        }
      }
  }
#end  // #CJQS_GoteroDetalle()

#macro CJQS_TuboEnsayo()
   object                                       {
     #local L                   = CJQS_L;
     #local AltoTubo            = 87*L;
     #local DiametroTubo        = 11*L;
     #local GruesoVidrio        = .85*L;
     CJQS_TuboEnsayoDetalle( AltoTubo, DiametroTubo, GruesoVidrio,
                CJQS_MaterialVidrio )
   }
#end  // #macro CJQS_TuboEnsayo()

#macro CJQS_Erlenmeyer()
   object                                       {
     #local L                   = CJQS_L;
     #local DiametroMayor       = 46*L;
     #local DiametroMenor       = 16*L;
     #local AltoErlenmeyer      = 75*L;
     #local AltoDiametroMayor   =  9*L;
     #local AltoDiametroMenor   = 54*L;
     #local GruesoVidrio        =  1*L;
     #local GruesoLinea         = 0.5*L;
     CJQS_ErlenmeyerDetalle( DiametroMayor, DiametroMenor,
       AltoErlenmeyer, AltoDiametroMayor, AltoDiametroMenor,
       GruesoVidrio, GruesoLinea, CJQS_MaterialVidrio )
   }
#end  // #macro CJQS_Erlenmeyer()

#macro CJQS_Gotero()
  object                                        {
    #local L                    = CJQS_L;
    #local DiametroGotero       = 5*L;
    #local LargoGotero          = 62*L;
    #local LargoHule            = 17*L;
    #local DiametroTapa         = 14*L;
    #local LargoTapa            = 8*L;
    #local GruesoVidrio         = .85*L;
    CJQS_GoteroDetalle( DiametroGotero, LargoGotero,
       LargoHule , DiametroTapa, LargoTapa,
       GruesoVidrio, CJQS_MaterialVidrio,
       CJQS_MaterialHule, CJQS_MaterialTapa )
  }
#end  // #macro CJQS_Gotero()

