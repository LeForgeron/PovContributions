//  This file is licensed under the terms of the CC-LGPL.
//  
//  Autor  : Rafael Angel Campos Vargas
//  Correo : RofoelCompos@hotmail.com  
//  Apdo. 964-1250 Escazu, San Jose, Costa Rica
//  dedicado a Jesus y Maria...
//
//  En este momento estoy creando un programa
//  de animacion LibreN3D para FreeDOS con el compilador FreePascal
//  falta mucho... 03 julio 2018
//                
//  Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
//  1 L equivale a 0.055063 pulgadas 
//  definido como 0.001 para POVRAY.
//     
//  LCGF LicuadoraCuchillaGiratoriaFilosa
//  El archivo dibuja una licuadora corriente para cocina, de ocho botones.
//  Posee una macro para variar sus dimensiones principales y texturas. 
//  La base se ajusta en ocho posiciones, pueden oprimirse los botones, y separarse
//  algunas partes pero es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene solo un parametro.
//  #macro LCGF_Licuadora( IndiceRanura )
//          IndiceRanura        : Numero entero entre 0 y 7, para ubicar la licuadora
//              en una de las ocho ranuras (esto orienta la oreja de la licuadora). 
//              Un numero fraccionario no genera error.
//        
//  La siguiente macro permite un mayor control de las caracteristicas. Es probable
//  que los botones queden mal ubicados, y requira utilizar los modificadores.
//  #macro  LCGF_LicuadoraCuchillaGiratoriaFilosa
//          ( IndiceRanura, DiametroBase, DiametroSoporte, 
//            AltoBase, ProfundidadDelantera,
//            DiametroPichel, AltoReferenciaPichel, 
//            GruesoPlastico, AltoInternoTapa, 
//            DiametroAberturaTapa, AnchoOreja, AltoOreja,
//            MaterialPrincipal, MaterialPichel, MaterialAccesorios,
//            MaterialBotones, MaterialPlacaBotones,
//            MaterialCuchillas, MaterialCuero )
//          IndiceRanura        : Numero entero entre 0 y 7, para ubicar la licuadora
//              en una de las ocho ranuras. Esto orienta, la oreja de la licuadora
//              en una de ocho posiciones. Un numero fraccionario no genera error.
//          DiametroBase        : Diametro de la base inferior a lo ancho en X.
//              Valor por defecto 114*L.
//          DiametroSoporte     : Diametro en la zona de contacto con la licuadora.
//              Valor por defecto 73*L.
//          AltoBase            : Alto referencia para la base de la licuadora.
//              Valor por defecto 112.60*L.
//          ProfundidadDelantera            : Profundidad en Z de la zona negativa o
//              frente de la licuadora. Valor por defecto 94*L.
//          DiametroPichel      : Diametro del pichel de licuado.
//              Valor por defecto 85*L.
//          AltoReferenciaPichel            : Alto de referencia para el pichel.
//              Valor por defecto 127*L.
//          GruesoPlastico      : Grueso del material basico del pichel.
//              Valor por defecto 2*L.
//          AltoInternoTapa     : Alto de la tapa que penetra el recipiente.
//              Valor por defecto 22*L.            
//          DiametroAberturaTapa            : Diametro de la abertura en la tapa.
//              Valor por defecto 37*L.
//          AnchoOreja          : Abertura desde el cilindro para agarrar la oreja.
//              Valor por defecto 50*L.
//          AltoOreja           : Porcion del pichel a lo alto en Y, abarcado por la oreja.
//              Valor por defecto 112*L.
//          MaterialPrincipal   : Material de la base que soporta al pichel.
//              Valor por defecto LCGF_MaterialPrincipal.
//          MaterialPichel      : Material del pichel contenedor.
//              Valor por defecto LCGF_MaterialPichel.
//          MaterialAccesorios  : Material de algunos elementos del pichel,
//              como la tapa o el cilindro de union.
//              Valor por defecto LCGF_MaterialAccesorios.
//          MaterialBotones     : Material para los botones.
//              Valor por defecto LCGF_MaterialBotones.
//          MaterialPlacaBotones            : Material para la placa soporte de botones.
//              Valor por defecto LCGF_MaterialPlacaBotones.
//          MaterialCuchillas   : Material para las cuchillas.
//              Valor por defecto LCGF_MaterialCuchillas.
//          MaterialCuero       : Material para patas y contacto de giro.
//              Valor por defecto LCGF_MaterialCuero.
//
//  El aparato sin contar su oreja se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -57,    0,  -94 >*L
//      Maximo      = <  +57, +303,  +57 >*L
//  La oreja se extienda hasta 94*L de radio respecto al eje Y y tiene ocho posiciones. 
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores. 
//  #declare LCGF_InterioBase           = object { ... }                     
//      Se genera al llamar a la macro.
//      Corresponde al volumen interior del pichel. No incluye correccion
//      para las cuchillas o la tapa.
//      Puede utilzarla para ubicar material en el interior del recipiente.
//  #declare LCGF_DefectoMaterialPrincipal   
//      Material de la base que soporta al pichel.
//  #declare LCGF_DefectoMaterialPichel      
//      Material del pichel contenedor.
//  #declare LCGF_DefectoMaterialAccesorios  
//      Material de algunos elementos del pichel,
//      como la tapa o el cilindro de union.
//  #declare LCGF_DefectoMaterialBotones     
//      Material para los botones.
//  #declare LCGF_DefectoMaterialPlacaBotones            
//      Material para la placa soporte de botones.
//  #declare LCGF_DefectoMaterialCuchillas   
//      Material para las cuchillas.
//  #declare LCGF_DefectoMaterialCuero       
//      Material para patas y conctacto de giro.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default)   
//  #declare LCGF_TransformPichel           = transform { }
//      Transform adicional para ubicar el pichel.
//  #declare LCGF_TransformTapaPichel       = transform { }
//      Transform adicional para ubicar la tapa del pichel.
//  #declare LCGF_TransformVisorPichel      = transform { }
//      Transform adicional para ubicar el visor en la tapa del pichel.
//  #declare LCGF_AnguloRotarCuchillas      = 0;
//      Angulo para girar las cuchillas.
//  #declare LCGF_ColorLetras               = White;
//      Para cambiar el color de las etiquetas de los botones.
//  #declare LCGF_BanderaBotones            = on;
//      "on" botones visibles, "off" los desactiva. Util como ultimo
//      remedio si los botones quedan mal ubicados.           
//  #declare LCGF_TransformBotones          = transform { }           
//      Permite corregir la posicion de los botones. Tomar en cuenta
//      que posterior a esta transform se genera un <i>rotate 45*x</i>. 
//      De tal forma, que en muchos casos sea suficiente con desplazar
//      los botones arriba-abajo.          
//  #declare LCGF_EstadoBotones             = array [ 8 ]
//          { off, off, off, off, off, off, off, off }
//      Permite apretar botones con el valor "on".
//  #declare LCGF_LabelBotones              = array [ 8 ]
//          { "A", "R", "P", "1", "2", "3", "4", "5" }
//      Para cambiar las etiquetas de los botones. Solo se permite
//      un caracter.
//  #declare LCGF_MaterialPrincipal         =
//                  { LCGF_DefectoMaterialPrincipal             }  
//      Material de la base que soporte el pichel.
//  #declare LCGF_MaterialPichel            =
//                  { LCGF_DefectoMaterialPichel                }
//      Material del pichel contenedor.
//  #declare LCGF_MaterialAccesorios        =
//                  { LCGF_DefectoMaterialAccesorios            }
//      Material de algunos elementos del pichel,
//      como la tapa o el cilindro de union.
//  #declare LCGF_MaterialBotones           =
//                  { LCGF_DefectoMaterialBotones               }
//      Material para los botones.
//  #declare LCGF_MaterialPlacaBotones      =
//                  { LCGF_DefectoMaterialPlacaBotones          }    
//      Material para la placa soporte de botones.
//  #declare LCGF_MaterialCuchillas         =
//                  { LCGF_DefectoMaterialCuchillas             }
//      Material para las cuchillas.
//  #declare LCGF_MaterialCuero             =
//                  { LCGF_DefectoMaterialCuero                 }
//      Material para patas y conctacto de giro.
//       
//  Para colocarlo simplemente
//  #include "LCGF.inc" 
//  object { LCGF_Licuadora( 0 ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto default
//  #include "LCGF.inc"   
//  object                       {
//      LCGF_LicuadoraCuchillaGiratoriaFilosa( 0, 
//          0.114, 0.073, 0.1126, 0.094, 0.085, 0.127, 
//          0.002, 0.022, 0.037 , 0.050, 0.112,
//          LCGF_MaterialPrincipal, LCGF_MaterialPichel,
//          LCGF_MaterialAccesorios, LCGF_MaterialBotones,
//          LCGF_MaterialPlacaBotones,LCGF_MaterialCuchillas,
//          LCGF_MaterialCuero )
//  }
//        
//  Con modificadores
//  #include "LCGF.inc"
//  #include "textures.inc"
//  #declare LCGF_MaterialPichel   = material { M_Green_Glass } 
//  object        { LCGF_Licuadora( 0 ) }
//
//  Con liquido en su interior
//  #include "LCGF.inc"
//  #include "colors.inc"
//  #include "textures.inc"
//  object        { LCGF_Licuadora( 0 ) }
//  object        { LCGF_InteriorBase pigment { Orange } }
//
#include "colors.inc"
#include "metals.inc"
#include "textures.inc" 
#include "stones.inc"
#declare LCGF_L                         = 0.001;
  
#if ( version < 3.2 )
  #ifndef( LCGF_POV3_1 )
    #declare LCGF_POV3_1        = on;
  #end
#else
  #ifndef( LCGF_POV3_1 )
    #declare LCGF_POV3_1        = off;
  #end
#end
    
#declare LCGF_TransformPichel           = transform { }

#declare LCGF_TransformTapaPichel       = transform { }

#declare LCGF_TransformVisorPichel      = transform { }

#declare LCGF_AnguloRotarCuchillas      = 0;

#declare LCGF_ColorLetras               = White;

#declare LCGF_BanderaBotones            = on;
           
#declare LCGF_TransformBotones          = transform { }           
           
#declare LCGF_TotalBotones              = 8;

#declare LCGF_EstadoBotones             = array [ LCGF_TotalBotones ]
  { off, off, off, off, off, off, off, off }

#declare LCGF_LabelBotones              = array [ LCGF_TotalBotones ]
  { "A", "R", "P", "1", "2", "3", "4", "5" }

#declare LCGF_DefectoMaterialPrincipal   =  
  material                              {
    texture                               {
      pigment                       {
        White
      } 
      normal                            {
        bumps
      }
      finish                           {
        phong 0.5
        phong_size 10
      }
    }
  }

#ifndef ( LCGF_MaterialPrincipal )
  #declare LCGF_MaterialPrincipal        = LCGF_DefectoMaterialPrincipal
#end  //  #ifndef ( LCGF_MaterialPrincipal )

#declare LCGF_DefectoMaterialPichel      =
  material                              {  
    #if ( LCGF_POV3_1 )
      texture {  pigment { White transmit 0.8 } }  
    #else  //  #else ( LCGF_POV3_1 )
       M_Glass3
    #end   //  #else ( LCGF_POV3_1 )
  }

#ifndef ( LCGF_MaterialPichel )
  #declare LCGF_MaterialPichel           = LCGF_DefectoMaterialPichel
#end  //  #ifndef ( LCGF_MaterialPichel    )

#declare LCGF_DefectoMaterialAccesorios  =
  material                              {
    texture                               {
      T_Stone16
      scale 0.1
    }
  }

#ifndef ( LCGF_MaterialAccesorios    )
  #declare LCGF_MaterialAccesorios           = LCGF_DefectoMaterialAccesorios
#end  //  #ifndef ( LCGF_MaterialAccesorios    )

#declare LCGF_DefectoMaterialBotones   =
  material                              {
    texture                               {
      pigment  { Gray30 }
    }
  }

#ifndef ( LCGF_MaterialBotones     )
  #declare LCGF_MaterialBotones            = LCGF_DefectoMaterialBotones
#end  //  #ifndef ( LCGF_MaterialBotones     )

#declare LCGF_DefectoMaterialPlacaBotones   =
  material                              {
    texture                               {
      T_Brass_2B
    }
  }

#ifndef ( LCGF_MaterialPlacaBotones     )
  #declare LCGF_MaterialPlacaBotones            = LCGF_DefectoMaterialPlacaBotones
#end  //  #ifndef ( LCGF_MaterialPlacaBotones     )

#declare LCGF_DefectoMaterialCuchillas   =
  material                              {
    texture                               {
      T_Chrome_3C
    }
  }

#ifndef ( LCGF_MaterialCuchillas     )
  #declare LCGF_MaterialCuchillas            = LCGF_DefectoMaterialCuchillas
#end  //  #ifndef ( LCGF_MaterialCuchillas     )

#declare LCGF_DefectoMaterialCuero   =
  material                              {   
    texture                             {
      T_Stone24
      scale  0.001                           
    }
  }
  
#ifndef ( LCGF_MaterialCuero     )
  #declare LCGF_MaterialCuero            = LCGF_DefectoMaterialCuero
#end  //  #ifndef ( LCGF_MaterialCuero     )

#macro  LCGF_LicuadoraCuchillaGiratoriaFilosa
      ( IndiceRanura, DiametroBase, DiametroSoporte, AltoBase,
        ProfundidadDelantera,
        DiametroPichel, AltoReferenciaPichel, GruesoPlastico,
        AltoInternoTapa, DiametroAberturaTapa,
        AnchoOreja, AltoOreja,
        MaterialPrincipal, MaterialPichel, MaterialAccesorios,
        MaterialBotones, MaterialPlacaBotones,
        MaterialCuchillas, MaterialCuero )
  union                                 {
    //  Forma Base
    #local AltoPatas                    = 14*AltoBase/112.60;
    #local GruesoOreja                  = 17*DiametroPichel/85;
    difference                          {
      union                               {
        #local HEsc1                      = 0.5*sqrt(
          DiametroBase*DiametroBase-DiametroSoporte*DiametroSoporte );
        #local AjusteEsfera1              = AltoBase/HEsc1;
        difference                        {
          sphere                          {
            0, DiametroBase/2
            scale                 <1,AjusteEsfera1,1>
          }
          plane                           {
            y, 0
          }
          plane                           {
            -y, -AltoBase
          }
        }
        difference                        {
          intersection                    {
            sphere                          {
              0, DiametroBase/2
              scale                 <1,AjusteEsfera1,
                                    2*ProfundidadDelantera/DiametroBase>
            }
            cylinder                       {
              -AltoBase*y, +2*AltoBase*y,
              0.85*ProfundidadDelantera
              rotate              45*x
            }
          }
          plane                           {
            y, 0
          }
          plane                           {
            -z, 0
          }
          plane                           {
            -y, -AltoBase
          }
        }
        sphere                            {
          0, DiametroSoporte/2
          scale           <1,0.05,1>
          translate               AltoBase*y
        }
      }
      //  Perforacion Licuadora
      union                             {
        cylinder                      {
          -0.35*DiametroPichel*y, -0.7*DiametroPichel*y,
          0.35*DiametroPichel+GruesoPlastico
        }
        torus                           {
          0.30*DiametroPichel, GruesoPlastico
          translate             -0.70*DiametroPichel*y
          material                               {
            MaterialCuero
          }
        }
        #local C                        = 0;
        #while ( C < 8 )
          intersection                    {
            difference                  {
              cylinder                  {
                -0.3*DiametroPichel*y, -0.8*DiametroPichel*y,
                0.2*DiametroPichel+3*GruesoPlastico
              }
              cylinder                  {
                -0.3*DiametroPichel*y, -0.8*DiametroPichel*y,
                0.2*DiametroPichel-GruesoPlastico
              }
              translate               0.55*DiametroPichel*z
              rotate          C*45*y
            }
            cylinder                    {
              -0.35*DiametroPichel*y, -0.7*DiametroPichel*y,
              0.375*DiametroPichel+GruesoPlastico
            }
          }
          #local C                      = C+1;
        #end
        translate               ( AltoBase+0.06*DiametroSoporte/2
                                +0.35*DiametroPichel )*y
      }
      //  END Perforacion Licuadora
    }
    //  END Forma Base
    //  Rotor Superior
    union                               {
      cylinder                          {
        0.025*DiametroPichel*y, 0.0125*DiametroPichel*y,
        0.2*DiametroPichel
      }
      intersection                      {
        cylinder                          {
          0.025*DiametroPichel*y, 0.075*DiametroPichel*y,
          0.2*DiametroPichel
        }
        union                           {
          #local C                      = 0;
          #while ( C < 6 )
            box                         {
              < -GruesoPlastico, 0, +0.05*DiametroPichel >,
              < +GruesoPlastico, DiametroPichel, DiametroPichel >
              rotate            C*60*y
            }
            #local C                    = C+1;
          #end  //  #while ( C < 6 )
        }
      }
      translate         ( AltoBase+0.6*DiametroSoporte/2
                                -0.35*DiametroPichel )*y
      material                           {
        MaterialCuero
      }
    }
    //  END Rotor Superior
    // Botones
    object                              {
      // PlacaBotones
      difference                        {
        intersection                    {
          union                         {
            cylinder                    {
              -AltoBase*y, +2*AltoBase*y,
              0.85*ProfundidadDelantera
            } 
            #if ( LCGF_BanderaBotones )
              union                        {
                #local C                    = 0;
                #while ( C < LCGF_TotalBotones )
                  #local DeltaAngular       = 30;
                  union                             {
                    superellipsoid                      {
                      <0.2,0.2>
                      scale           0.05*AltoBase*
                                      <0.4*8/LCGF_TotalBotones,1.2,1.0>
                      translate       -0.85*ProfundidadDelantera*z
                      #if ( LCGF_EstadoBotones[C] )
                        translate     0.75*0.05*AltoBase*z
                      #end  //  #if ( LCGF_EstadoBotones[C] )
                    }
                    text                                    {
                      ttf "timrom.ttf" LCGF_LabelBotones[C], 1, 0
                      translate             -0.1*x
                      scale  0.04*AltoBase
                      translate       -0.85*ProfundidadDelantera*z
                      translate             -0.1*AltoBase*y
                      pigment { color LCGF_ColorLetras }
                    }
                    translate         -0.2*AltoBase*y
                    rotate          +DeltaAngular/2*y
                    rotate          -C*DeltaAngular/( LCGF_TotalBotones-1 )*y
                    material                 {
                      MaterialBotones
                    }
                  }
                  #local C                  = C+1;
                #end  //  #while ( C < 8 )       
                transform       LCGF_TransformBotones
              }  
            #end  //  #if ( LCGF_BanderaBotones )
            rotate              45*x
          }
          cylinder                       {
            -AltoBase*y, +2*AltoBase*y,
            1
            scale  < 0.80*DiametroBase/2, 1, 0.85*ProfundidadDelantera >
            translate   -0.15*DiametroBase/2*z
            
          }
        }
        plane                           {
          -z, 0
        }
        plane                           {
          y, 0.01*AltoBase
        }
        cylinder                        {
          -AltoBase*y, 3*AltoBase*y,
          1.1*DiametroBase/2
        }
        translate       0.01*AltoBase*y
        material                         {
          MaterialPlacaBotones
        }
      }
      //  END Placa Botones
    }
    // END Botones
    // Pichel
    merge                               {
      difference                        {
        // Exterior Base
        difference                      {
          merge                           {
            cylinder                      {
              0, AltoReferenciaPichel*y,
              DiametroPichel/2
            }
            sphere                        {
              0, DiametroPichel/2
            }
            merge                         {
              sphere                      {
                0, DiametroPichel/3
              }
              torus                     {
                DiametroPichel/3, GruesoPlastico
              }
              scale             <1,2*AltoInternoTapa/DiametroPichel,1>
              translate                 AltoReferenciaPichel*y
              translate         -0.8*DiametroPichel/3*z
            }
            //  Oreja
            object                      {
              merge                     {
                difference              {
                  cylinder                {
                    -GruesoOreja/2*x, +GruesoOreja/2*x,
                    AnchoOreja
                  }
                  cylinder                {
                    -GruesoOreja*x, +GruesoOreja*x,
                    AnchoOreja-2*GruesoPlastico
                  }
                  plane                   {
                    y, 0
                  }
                  translate             ( AltoOreja-AnchoOreja )*y
                }
                difference              {
                  cylinder                {
                    -GruesoPlastico*x/2, +GruesoPlastico/2*x,
                    AnchoOreja
                  }
                  cylinder                {
                    -GruesoOreja*x, +GruesoOreja*x,
                    0.85*AnchoOreja
                  }
                  plane                   {
                    y, 0
                  }
                  translate             ( AltoOreja-AnchoOreja )*y
                }
                difference              {
                  cylinder                {
                    -GruesoOreja/2*x, +GruesoOreja/2*x,
                    AltoOreja-AnchoOreja
                  }
                  cylinder                {
                    -GruesoOreja*x, +GruesoOreja*x,
                    AltoOreja-AnchoOreja-2*GruesoPlastico
                  }
                  plane                   {
                    -y, 0
                  }
                  translate             ( 2*AnchoOreja-AltoOreja )*z
                  translate             ( AltoOreja-AnchoOreja )*y
                }
                difference              {
                  cylinder                {
                    -GruesoPlastico*x/2, +GruesoPlastico*x/2,
                    AltoOreja-AnchoOreja
                  }
                  cylinder                {
                    -GruesoOreja*x, +GruesoOreja*x,
                    AltoOreja-1.15*AnchoOreja
                  }
                  plane                   {
                    -y, 0
                  }
                  translate             ( 2*AnchoOreja-AltoOreja )*z
                  translate             ( AltoOreja-AnchoOreja )*y
                }
                intersection            {
                  merge                     {
                    difference              {
                      cylinder                {
                        -GruesoOreja/2*x, +GruesoOreja/2*x,
                        AnchoOreja
                      }
                      plane                   {
                        y, 0
                      }
                      translate             ( AltoOreja-AnchoOreja )*y
                    }
                    difference              {
                      cylinder                {
                        -GruesoOreja/2*x, +GruesoOreja/2*x,
                        AltoOreja-AnchoOreja
                      }
                      plane                   {
                        -y, 0
                      }
                      translate             ( 2*AnchoOreja-AltoOreja )*z
                      translate             ( AltoOreja-AnchoOreja )*y
                    }
                  }
                  merge                           {
                    difference                          {
                      cylinder                      {
                        -GruesoOreja/2*x, +GruesoOreja/2*x,
                        2*AltoOreja
                      }
                      cylinder                      {
                        -GruesoOreja/2*x, +GruesoOreja/2*x,
                        2*AltoOreja-2*GruesoPlastico
                      }
                    }
                    difference                          {
                      cylinder                      {
                        -GruesoPlastico*x/2, +GruesoPlastico*x/2,
                        2*AltoOreja
                      }
                      cylinder                      {
                        -GruesoOreja/2*x, +GruesoOreja/2*x,
                        2*AltoOreja-0.15*AnchoOreja
                      }
                    }
                    translate             4*AltoOreja/5*y+AnchoOreja*z
                                          +( 2*AltoOreja-1.2*AnchoOreja/2 )*z
                  }
                }
              }
              translate         +DiametroPichel/2*z
            }
            //  END Oreja
          }
          #local C                      = 0;
          #while ( C < 4 )
            merge                       {
              cone                      {
                -DiametroPichel/2*y, 0.10*DiametroPichel,
                0.6*AltoReferenciaPichel*y, 0.05*DiametroPichel
              }
              sphere                    {
                0.6*AltoReferenciaPichel*y,
                0.05*DiametroPichel
              }
              translate                 DiametroPichel/2*x
              rotate                    45*y
              rotate                    C*90*y
            }
            #local C                    = C+1;
          #end  //  #while ( C < 4 )
        }
        // END Exterior Base
        // Interior Base
        #local InteriorBase                 =
          difference                      {
            merge                           {
              cylinder                      {
                -0.001*AltoReferenciaPichel*y,
                1.5*AltoReferenciaPichel*y,
                DiametroPichel/2-GruesoPlastico
              }
              sphere                        {
                0, DiametroPichel/2-GruesoPlastico
              }
              plane                               {
                -y, -AltoReferenciaPichel
              }  
              sphere                      {
                0, DiametroPichel/3-GruesoPlastico
                scale             <1,2*AltoInternoTapa/DiametroPichel,1>
                translate                 AltoReferenciaPichel*y
                translate         -0.8*DiametroPichel/3*z
              }
            }
            #local C                      = 0;
            #while ( C < 4 )
              merge                       {
                cone                      {
                  -DiametroPichel/2*y, 0.10*DiametroPichel+GruesoPlastico,
                  0.6*AltoReferenciaPichel*y, 0.05*DiametroPichel+GruesoPlastico
                }
                sphere                    {
                  0.6*AltoReferenciaPichel*y,
                  0.05*DiametroPichel+GruesoPlastico
                }
                translate                 DiametroPichel/2*x
                rotate                    45*y
                rotate                    C*90*y
              }
              #local C                    = C+1;
            #end  //  #while ( C < 4 )
          }
          
        object                          {
          InteriorBase
        }
        // END Interior Base
      }
      //  Accesorios
      //  Base Pichel
      difference                        {
        union                             {
          object                          {
            cylinder                      {
              -0.35*DiametroPichel*y, -0.7*DiametroPichel*y,
              0.35*DiametroPichel
            }
          }
          #local C                        = 0;
          #while ( C < 8 )
            intersection                    {
              difference                  {
                cylinder                  {
                  -0.3*DiametroPichel*y, -0.8*DiametroPichel*y,
                  0.2*DiametroPichel+2*GruesoPlastico
                }
                cylinder                  {
                  -0.3*DiametroPichel*y, -0.8*DiametroPichel*y,
                  0.2*DiametroPichel
                }
                translate               0.55*DiametroPichel*z
                rotate          C*45*y
              }
              cylinder                    {
                -0.35*DiametroPichel*y, -0.7*DiametroPichel*y,
                0.375*DiametroPichel
              }
            }
            #local C                      = C+1;
          #end
          material                         {
            MaterialAccesorios
          }
        }
        sphere                          {
          0, DiametroPichel/2
        }
        // Relieve contacto rotor
        union                               {
          cylinder                          {
            0.025*DiametroPichel*y, 0.000*DiametroPichel*y,
            0.2*DiametroPichel
          }
          intersection                      {
            cylinder                          {
              0.024*DiametroPichel*y, 0.075*DiametroPichel*y,
              0.2*DiametroPichel
            }
            union                           {
              #local C                      = 0;
              #while ( C < 6 )
                box                         {
                  < -GruesoPlastico, 0, +0.05*DiametroPichel >,
                  < +GruesoPlastico, DiametroPichel, DiametroPichel >
                  rotate            C*60*y
                  material { MaterialCuchillas }
                }
                #local C                    = C+1;
              #end  //  #while ( C < 6 )
            }
          }
          translate         -0.701*DiametroPichel*y
          material                           {
            MaterialCuero
          }
        }
        //  END Relieve contacto Rotor
      }
      //  END Base Pichel
      //  Tapa
      union                             {
        difference                      {
          union                         {
            cylinder                        {
              -AltoInternoTapa*y, 0,
              DiametroPichel/2-3*GruesoPlastico
            }
            cylinder                            {
              -0.9*AltoInternoTapa*y, -0.92*AltoInternoTapa*y,
              DiametroPichel/2-GruesoPlastico
            }
            cylinder                            {
              -0.8*AltoInternoTapa*y, -0.82*AltoInternoTapa*y,
              DiametroPichel/2-GruesoPlastico
            }
            cylinder                            {
              -0.7*AltoInternoTapa*y, -0.72*AltoInternoTapa*y,
              DiametroPichel/2-GruesoPlastico
            }
            difference                            {
              cone                                {
                0, DiametroPichel/2+3*GruesoPlastico,
                AltoInternoTapa*y, 0
              }
              cone                                {
                0, 0,
                AltoInternoTapa*y, DiametroPichel
              }
            }
          }
          cylinder                      {
            -1.1*AltoInternoTapa*y, 0.1*AltoInternoTapa*y,
            DiametroPichel/2-4*GruesoPlastico
          }
          cylinder                      {
            -0.5*AltoInternoTapa*y, 2*AltoInternoTapa*y,
            DiametroAberturaTapa/2
          }
        }
        //  Abertura Tapa
        object                          {
          difference                    {
            merge                       {
              cylinder                  {
                0, AltoInternoTapa*y,
                DiametroAberturaTapa/2-GruesoPlastico
              }
              cylinder                  {
                0, 0.02*AltoInternoTapa*y,
                DiametroAberturaTapa/2
              }
              cylinder                  {
                0, 0.02*AltoInternoTapa*y,
                DiametroAberturaTapa/2
                translate               0.1*AltoInternoTapa*y
              }
              intersection                {
                cylinder                  {
                  0, 0.3*AltoInternoTapa*y,
                  1.2*DiametroAberturaTapa/2
                }
                cone                                {
                  0, 0,
                  AltoInternoTapa*y, DiametroPichel
                }
              }
            }
            cylinder                  {
              0, AltoInternoTapa*y,
              DiametroAberturaTapa/2-2*GruesoPlastico
              translate         -GruesoPlastico*y
            }
          }
          material                       {
            MaterialPichel
          }
          transform                     LCGF_TransformVisorPichel
        }
        //  END Abertura Tapa
        material                         {
          MaterialAccesorios
        }
        translate                       1.0*AltoReferenciaPichel*y
                        +0.0*DiametroPichel/2*z
        transform                       LCGF_TransformTapaPichel
      }
      //  END tapa
      //  Cuchillas
      union                             {
        #local C                        = 0;
        #while ( C < 4 )
          difference                         {
            cylinder                      {
              0, GruesoPlastico*y,
              1
              scale  < 1.2/4, 1, 0.05 >*DiametroPichel
            }
            plane                         {
              z, 0
            }
            plane                         {
              x, 0
            }
            translate             -0.025*DiametroPichel*z
            #if ( mod( C, 2 ) = 0 )
              rotate             10*z
            #else  //  #else C odd
              rotate            -10*z
            #end   //  #else C odd
            translate           0.05*DiametroPichel*x
            rotate              90*C*y
          }
          #local C                         = C+1;
        #end
        cylinder                        {
          0.02*DiametroPichel*y, -0.15*DiametroPichel*y,
          0.05*sqrt( 2 )*DiametroPichel
        }
        cylinder                        {
          -0.10*DiametroPichel*y, -0.11*DiametroPichel*y,
          0.2*DiametroPichel
        }
        translate               -0.25*DiametroPichel*y
        rotate          LCGF_AnguloRotarCuchillas*y
        material                         {
          MaterialCuchillas
        }
      }
      //  END Cuchillas
      //  END Accesorios
      material                           {
        MaterialPichel
      }
      translate               11*DiametroPichel/32*y
      translate               1.0*AltoBase*y
      rotate                    IndiceRanura*45*y
      transform                 LCGF_TransformPichel
    }
    // END Pichel
    // Patas
    difference                          {
      union                               {
        cylinder                            {
          0, -1.00*AltoPatas*y, 0.95*DiametroBase/2
        }
        difference                          {
          cylinder                            {
            0, -1.00*AltoPatas*y, 1
            scale   < 0.95*DiametroBase/2, 1, 0.95*ProfundidadDelantera >
          }
          plane                                   {
            -z, 0
          }
        }
      }
      union                             {
        box                             {
          < -ProfundidadDelantera, -AltoPatas, -0.25*ProfundidadDelantera >,
          < +ProfundidadDelantera, 0, +0.125*DiametroBase >
        }
        box                             {
          < -0.2*DiametroBase, -AltoPatas, -ProfundidadDelantera >,
          < +0.2*DiametroBase, -0.01*AltoPatas, +ProfundidadDelantera >
        }
        translate                       -2*AltoPatas/3*y
      }
      material                           {
        MaterialCuero
      }
    }
    // END Patas
    material                             {
      MaterialPrincipal
    }
    translate           AltoPatas*y
    #declare LCGF_InteriorBase         =
        difference                          {
          object                            {
            InteriorBase
          }
          plane                             {
            -y, -0.999*AltoReferenciaPichel
          }
          translate               11*DiametroPichel/32*y
          translate               1.0*AltoBase*y
          rotate                    IndiceRanura*45*y
          transform                 LCGF_TransformPichel
          translate           AltoPatas*y
        }
  }
#end  //  #macro LCGF_LicuadoraCuchillaGiratoriaFilosa

#macro LCGF_Licuadora( IndiceRanura )
  object                                {
    #local L                            = LCGF_L;
    #local DiametroBase                 = 114*L;
    #local DiametroSoporte              = 73*L;
    #local AltoBase                     = 112.60*L;
    #local ProfundidadDelantera         = 94*L;
    #local DiametroPichel               = 85*L;
    #local AltoReferenciaPichel         = 127*L;
    #local GruesoPlastico               = 2*L;
    #local AltoInternoTapa              = 22*L;
    #local DiametroAberturaTapa         = 37*L;
    #local AnchoOreja                   = 50*L;
    #local AltoOreja                    = 112*L;
    LCGF_LicuadoraCuchillaGiratoriaFilosa
      ( IndiceRanura, DiametroBase, DiametroSoporte, AltoBase,
        ProfundidadDelantera,
        DiametroPichel, AltoReferenciaPichel, GruesoPlastico,
        AltoInternoTapa, DiametroAberturaTapa,
        AnchoOreja, AltoOreja,
        LCGF_MaterialPrincipal, LCGF_MaterialPichel,
        LCGF_MaterialAccesorios, LCGF_MaterialBotones,
        LCGF_MaterialPlacaBotones,LCGF_MaterialCuchillas,
        LCGF_MaterialCuero )
  }
#end  //  #macro LCGF_Licuadora()
