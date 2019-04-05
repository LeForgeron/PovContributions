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
//  CJTD CultivadorJardinTresDientes
//  El archivo dibuja un cultivador para jardineria domestica.
//  Posee una macro para modificar las caracteristicas principales, pero 
//  es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal no tiene parametros:
//  #macro CJTD_Cultivador( )
//
//  El detalle del cultivador puede modificarse ligeramente con la siguiente macro:     
//  #macro CJTD_CultivadorJardinTresDientes( LargoBastidor,
//      DiametroMayorBastidor, DiametroMenorBastidor,
//      LargoRectoVarilla, LargoOblicuoVarilla,
//      DiametroVarillaCentral, DiametroVarillaLateral,
//      AnguloAbertura, AnguloArrastre,
//      FraccionOrigenVarillas, RadioCurvaturaVarillas,
//      MaterialDientes, MaterialMetalico,
//      MaterialMadera, MaterialAgarradera )
//          LargoBastidor                   : Largo del mango.
//              Valor por defecto 125*L.
//          DiametroMayorBastidor           : Diametro mayor del mango.
//              Valor por defecto 25*L.
//          DiametroMenorBastidor           : Diametro menor del mango.
//              Valor por defecto 14.6*L.
//          LargoRectoVarilla               : Referencia para el largo de varilla.
//              Valor por defecto 90*L.
//          LargoOblicuoVarilla             : Referencia para el largo de arrastre del
//              cultivador. Valor por defecto 27*L.
//          DiametroVarillaCentral          : Diametro de la varilla central de arrastre.
//              Valor por defecto 5.7*L.
//          DiametroVarillaLateral          : Diametro de las varillas laterales de arrastre.
//              Valor por defecto 4*L.
//          AnguloAbertura                  : Angulo de abertura de las varillas laterales.
//              Valor por defecto 15.
//          AnguloArrastre                  : Angulo inclinacion de las varillas de arrastre.
//              Valor por defecto 15.
//          FraccionOrigenVarillas          : Fraccion respecto a LargoRectoVarillas,
//              en que cruza la extrapolacion imaginaria de las varillas de arrastre.    
//              Valor por defecto 0.0.
//          RadioCurvaturaVarillas          : Radio para la curva que une la linea horizontal
//              con las lineas de arrastre en las varillas.
//              Valor por defecto 7*L.
//          MaterialDientes                 : Material de las varillas.
//              Valor por defecto CJTD_MaterialDientes.
//          MaterialMetalico                : Material de la argolla metalica de union.
//              Valor por defecto CJTD_MaterialMetalico.
//          MaterialMadera                  : Material del mango de madera.
//              Valor por defecto CJTD_MaterialMadera.
//          MaterialAgarradera              : Material de la agarradera de caucho.
//              Valor por defecto CJTD_MaterialAgarradera.
//      
//  El cultivador tiene las siguientes caracteristicas:
//      Minimo          = < -32, -125, -35 >*L
//      Maximo          = <  32,  107,  13 >*L
//  Los dientes se curvan hacia Z-. El punto de union entre el bastidor y los dientes
//  se encuentra en el origen de coordenadas.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare CJTD_DefectoMaterialDientes
//      Material de las varillas.
//  #declare CJTD_DefectoMaterialMetalico            
//      Material de la argolla metalica de union.
//  #declare CJTD_DefectoMaterialMadera            
//      Material del mango de madera.
//  #declare CJTD_DefectoMaterialAgarradera
//      Material de la agarradera de caucho.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare CJTD_MaterialDientes                   =
//                  { CJTD_DefectoMaterialDientes                 }
//      Material de las varillas.
//  #declare CJTD_MaterialMetalico                  =
//                  { CJTD_DefectoMaterialMetalico                }
//      Material de la argolla metalica de union.
//  #declare CJTD_MaterialMadera                    =
//                  { CJTD_DefectoMaterialMadera                  }
//      Material del mango de madera.
//  #declare CJTD_MaterialAgarradera                =
//                  { CJTD_DefectoMaterialAgarradera              }
//      Material de la agarradera de caucho.
//       
//  Para colocarlo simplemente
//  #include "CJTD.inc" 
//  object { CJTD_Cultivador( ) }
//   
//  Ejemplo con la macro detallada, mismo objetos por defecto
//  #include "CJTD.inc"   
//  object                       {
//    CJTD_CultivadorJardinTresDientes( 0.125, 0.025, 0.0146, 
//        0.090, 0.027, 0.0057, 0.004, 15, 15, 0, 0.007,
//        CJTD_MaterialDientes, CJTD_MaterialMetalico,
//        CJTD_MaterialMadera, CJTD_MaterialAgarradera )
//  }
//        
//  Con modificadores
//  #include "CJTD.inc"
//  #include "textures.inc"
//  #declare CJTD_MaterialDientes      = material { texture { PinkAlabaster } } 
//  object        { CJTD_Cultivador( ) }
//          
#include "colors.inc"
#include "textures.inc"
#include "metals.inc"
#include "woods.inc"

#declare CJTD_L         = 0.001;

#if ( version < 3.2 )
  #ifndef( CJTD_POV3_1 )
    #declare CJTD_POV3_1        = on;
  #end
#else
  #ifndef( CJTD_POV3_1 )
    #declare CJTD_POV3_1        = off;
  #end    
#end

#declare CJTD_DefectoMaterialDientes    =
  material                              {
    texture                             {
      pigment                           {
        Jade
      }
      normal                            {
        onion
        scale  0.01
      }
      finish                            {
        phong 0.3
        phong_size 15
      }
    }
  }

#ifndef ( CJTD_MaterialDientes )
  #declare CJTD_MaterialDientes         = CJTD_DefectoMaterialDientes
#end  //  #ifndef ( CJTD_MaterialDientes )

#declare CJTD_DefectoMaterialMetalico   =
  material                              {
    texture                             {
      T_Chrome_3C
      normal                            {
        agate
      }
    }      
  }

#ifndef ( CJTD_MaterialMetalico )
  #declare CJTD_MaterialMetalico        = CJTD_DefectoMaterialMetalico
#end  //  #ifndef ( CJTD_MaterialMetalico )

#declare CJTD_DefectoMaterialMadera     =
  material                              {
    texture                             {
      T_Wood9
    }
  }

#ifndef ( CJTD_MaterialMadera )
  #declare CJTD_MaterialMadera          = CJTD_DefectoMaterialMadera
#end  //  #ifndef ( CJTD_MaterialMadera )

#declare CJTD_DefectoMaterialAgarradera =
  material                              {
    texture                             {
      Cork
    }
    texture                             {
      pigment                           { 
        color HuntersGreen transmit 0.1
      }
      #if ( CJTD_POV3_1 )
        normal { bumps }
      #else
        normal                            {
          pavement  
          number_of_sides 4
          number_of_tiles 4
          pattern  4
          rotate 45
          scale  0.001
        }
      #end
      finish                            {
        phong 0.3
        phong_size 15
      }
    }
  }

#ifndef ( CJTD_MaterialAgarradera )
  #declare CJTD_MaterialAgarradera      = CJTD_DefectoMaterialAgarradera
#end  //  #ifndef ( CJTD_MaterialAgarradera )

#macro CJTD_CultivadorJardinTresDientes( LargoBastidor,
        DiametroMayorBastidor, DiametroMenorBastidor,
        LargoRectoVarilla, LargoOblicuoVarilla,
        DiametroVarillaCentral, DiametroVarillaLateral,
        AnguloAbertura, AnguloArrastre,
        FraccionOrigenVarillas, RadioCurvaturaVarillas,
        MaterialDientes, MaterialMetalico,
        MaterialMadera, MaterialAgarradera )
  union                                 {
    // Bastidor
    union                               {
      #local RadioMenorTorusMadera    =
          0.1*( DiametroMayorBastidor-DiametroMenorBastidor );
      #local InicioBastidorMadera     = 2/35*LargoBastidor;
      #local InicioAgarradera         = 1/4*LargoBastidor;
      #local FinAgarradera            = 5/6*LargoBastidor;
      #local PosAgujeroMadera         = 11/12*LargoBastidor;
      #local RadioTorusAgarradera     =
        0.2*( DiametroMayorBastidor-DiametroMenorBastidor );
      //  Bastidor.ArgollaMetalica
      cylinder                            {
        0, -LargoBastidor*y/2, DiametroMenorBastidor/2
        material                          {
          MaterialMetalico
        }
      }  //  END Bastidor.ArgollaMetalica
      //  Bastidor.EstructuraMadera
      union                             {
        torus                           {
          DiametroMenorBastidor/2, RadioMenorTorusMadera
          translate     -( InicioBastidorMadera+RadioMenorTorusMadera )*y
        }
        cone                            {
          // Continua C0, pero no C1 con torus
          -( InicioBastidorMadera+RadioMenorTorusMadera )*y,
          DiametroMenorBastidor/2+RadioMenorTorusMadera,
          -( LargoBastidor/2 )*y,
          ( 0.4*DiametroMayorBastidor+0.1*DiametroMenorBastidor )
        }
        difference                      {
          cone                            {
            // Continua C0, pero no C1 con torus
            -( LargoBastidor-RadioMenorTorusMadera )*y,
            DiametroMenorBastidor/2+RadioMenorTorusMadera,
            -( LargoBastidor/2 )*y,
            ( 0.4*DiametroMayorBastidor+0.1*DiametroMenorBastidor )
          }
          union                         {
            cylinder                      {
              -DiametroMayorBastidor*z, DiametroMayorBastidor*z,
              0.25*DiametroMenorBastidor
            }
            cone                        {
              0, 0,
              -DiametroMayorBastidor*z, DiametroMayorBastidor/2
            }
            cone                        {
              0, 0,
              +DiametroMayorBastidor*z, DiametroMayorBastidor/2
            }
            translate   -PosAgujeroMadera*y
          }
        }
        torus                           {
          DiametroMenorBastidor/2, RadioMenorTorusMadera
          translate     -( LargoBastidor-RadioMenorTorusMadera )*y
        }
        material                        {
          MaterialMadera
        }
      }  //  END Bastidor.EstructuraMadera
      //  Bastidor.Agarradera
      union                           {
        cylinder                        {
          -InicioAgarradera*y,
          -FinAgarradera*y,
          DiametroMayorBastidor/2-RadioTorusAgarradera
        }
        torus                           {
          DiametroMayorBastidor/2-RadioTorusAgarradera,
          RadioTorusAgarradera
          translate     -( InicioAgarradera+RadioTorusAgarradera )*y
        }
        cylinder                        {
          -( InicioAgarradera+RadioTorusAgarradera )*y,
          -( FinAgarradera-RadioTorusAgarradera )*y,
          DiametroMayorBastidor/2
        }
        torus                           {
          DiametroMayorBastidor/2-RadioTorusAgarradera,
          RadioTorusAgarradera
          translate     -( FinAgarradera-RadioTorusAgarradera )*y
        }
        material                      {
          MaterialAgarradera
        }
      }  //  END Bastidor.Agarradera
    }  // END Bastidor
    //  Dientes
    union                               {
      #local FactorEnsanchamientoDiente = 1.5;
      //  Dientes.DienteCentral
      union                             {
        intersection                    {
          union                         {
            cone                          {
              0,  DiametroVarillaCentral/2
              LargoOblicuoVarilla*y,
              FactorEnsanchamientoDiente*DiametroVarillaCentral/2
            }
            sphere                      {
              LargoOblicuoVarilla*y,
              FactorEnsanchamientoDiente*DiametroVarillaCentral/2
            }
          }
          box                           {
            < -DiametroVarillaCentral, -DiametroVarillaCentral,
              -DiametroVarillaCentral/2 >,
            < +DiametroVarillaCentral, 1.1*LargoOblicuoVarilla,
              +DiametroVarillaCentral/2 >
          }
          translate                     +RadioCurvaturaVarillas*z
          rotate                        -( 90-AnguloArrastre )*x
          translate                     -RadioCurvaturaVarillas*z
        }
        difference                      {
          torus                         {
            RadioCurvaturaVarillas, DiametroVarillaCentral/2
            rotate                      90*z
          }
          plane                         {
            y, 0
          }
          plane                         {
            -y, 0
            rotate                        -( 90-AnguloArrastre )*x
          }
          translate                     -RadioCurvaturaVarillas*z
        }
        cylinder                        {
          0, -LargoRectoVarilla*y, DiametroVarillaCentral/2
        }
        translate       LargoRectoVarilla*y
      }  //  END Dientes.DienteCentral
      //  Dientes.DienteLateral
      union                             {
        #local AnguloAberturaR          = radians( AnguloAbertura );
        #local FraccionLateral          = ( 1-FraccionOrigenVarillas )/2;
        #local LargoRectoLateral        =
            LargoRectoVarilla*FraccionLateral/cos( AnguloAberturaR );
        #local DeltaLateral             =
          FraccionLateral*LargoRectoVarilla*tan( AnguloAberturaR );
        #local LargoOblicuoLateral      = ( LargoOblicuoVarilla
           +DiametroVarillaCentral/2
           +DiametroVarillaLateral/2 )/cos( AnguloAberturaR );
        #local RadioComunLateral        = DeltaLateral/cos( AnguloAberturaR );
        #local CorreccionPosComun       = DeltaLateral*tan( AnguloAberturaR );
        #local C                          = 0;
        //  Dientes.DienteLateral.Comun
        difference                      {
          torus                         {
            RadioComunLateral, DiametroVarillaLateral/2
            rotate                      90*x
          }
          box                           {
            -2*RadioComunLateral*<1,0,1>,
            +2*RadioComunLateral
            rotate              -AnguloAbertura*z
          }
          box                           {
            -2*RadioComunLateral*<1,0,1>,
            +2*RadioComunLateral
            rotate              +AnguloAbertura*z
          }
          translate             ( 1-FraccionLateral )*LargoRectoVarilla*y
                                +CorreccionPosComun*y
        }  //  END Dientes.DienteLateral.Comun
        #while ( C < 2 )
          //  Dientes.DienteLateral.SimetriaX
          union                           {
            intersection                    {
              union                         {
                cone                          {
                  0,  DiametroVarillaLateral/2
                  LargoOblicuoLateral*y,
                  FactorEnsanchamientoDiente*DiametroVarillaLateral/2
                }
                sphere                      {
                  LargoOblicuoLateral*y,
                  FactorEnsanchamientoDiente*DiametroVarillaLateral/2
                }
              }
              box                           {
                < -DiametroVarillaLateral, -DiametroVarillaCentral,
                  -DiametroVarillaLateral/2 >,
                < +DiametroVarillaLateral, 1.1*LargoOblicuoLateral,
                  +DiametroVarillaLateral/2 >
              }
              translate                     +RadioCurvaturaVarillas*z
              rotate                        -( 90-AnguloArrastre )*x
              translate                     -RadioCurvaturaVarillas*z
            }
            difference                      {
              torus                         {
                RadioCurvaturaVarillas, DiametroVarillaLateral/2
                rotate                      90*z
              }
              plane                         {
                y, 0
              }
              plane                         {
                -y, 0
                rotate                        -( 90-AnguloArrastre )*x
              }
              translate                     -RadioCurvaturaVarillas*z
            }
            cylinder                            {
              0, -LargoRectoLateral*y, DiametroVarillaLateral/2
            }
            translate           LargoRectoLateral*y
            rotate              -AnguloAbertura*z
            translate           LargoRectoVarilla*( 1-FraccionLateral )*y
            translate           DeltaLateral*x
            #if ( C = 1 )
              scale               <-1,1,1>
            #end  //  #if ( C = 1 )
          }  //  END Dientes.DienteLateral.SimetriaX
          #local C                        = C+1;
        #end  //  #while ( C < 2 )
        translate       ( DiametroVarillaCentral+DiametroVarillaLateral )*z/2
      }  //  END Dientes.DienteLateral
      material                          {
        MaterialDientes
      }
    }  //  END Dientes
  }
#end  //  #macro CJTD_CultivadorJardinTresDientes()

#macro CJTD_Cultivador()
  object                                {
    #local L                            = CJTD_L;
    #local LargoBastidor                = 125*L;
    #local DiametroMayorBastidor        =  25*L;
    #local DiametroMenorBastidor        =  14.6*L;
    #local LargoRectoVarilla            =  90*L;
    #local LargoOblicuoVarilla          =  27*L;
    #local DiametroVarillaCentral       =   5.7*L;
    #local DiametroVarillaLateral       =   4.0*L;
    #local AnguloAbertura               =  15;
    #local AnguloArrastre               =  15;
    #local FraccionOrigenVarillas       = -0.0;
    #local RadioCurvaturaVarillas       =   7*L;
    CJTD_CultivadorJardinTresDientes( LargoBastidor,
        DiametroMayorBastidor, DiametroMenorBastidor,
        LargoRectoVarilla, LargoOblicuoVarilla,
        DiametroVarillaCentral, DiametroVarillaLateral,
        AnguloAbertura, AnguloArrastre,
        FraccionOrigenVarillas, RadioCurvaturaVarillas,
        CJTD_MaterialDientes, CJTD_MaterialMetalico,
        CJTD_MaterialMadera, CJTD_MaterialAgarradera )
  }
#end  //  #macro CJTD_Cultivador()
