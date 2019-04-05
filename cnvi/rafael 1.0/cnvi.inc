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
//  CNVI CandeleroNoVelaIncluida
//  El archivo dibuja un candelero con soporte metalico decorado en vidrio.
//  Posee una macro para modificar las caracteristicas principales, pero 
//  es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principale tiene solo un parametro:
//  #macro CNVI_Candelero( Semilla )
//          Semilla                         : Valor semilla para el generador de numeros
//              aleatorios. El efecto es poco apreciable.
//
//  El detalle del candelero puede modificarse ligeramente con la siguiente macro:     
//  #macro CNVI_CandeleroNoVelaIncluida( Semilla,
//      DiametroSoporte, AltoSoporte,
//      DiametroCandelero, AltoCandelero,
//      TotalColumnas, ColumnasDecoradoSeccion,
//      DiametroArgolla, FrenteVidrio, GruesoVidrio,
//      AlambreGrueso, AlambreMedio, AlambreDelgado,
//      MaterialSoporte, MaterialVidrio,
//      MaterialArgolla, MaterialCandelero )
//          Semilla                         : Valor semilla para el generador de numeros
//              aleatorios. El efecto es poco apreciable.
//          DiametroSoporte                 : Diametro del soporte metalico.
//              Valor por defecto 79*L.             
//          AltoSoporte                     : Alto del soporte metalico.
//              Valor por defecto 118*L.
//          DiametroCandelero               : Diametro del soporte interior para el candil.
//              Valor por defecto 29.4*L.
//          AltoCandelero                   : Alto del soporte interior para el candil.
//              Valor por defecto 11*L.
//          TotalColumnas                   : Total de columnas metalicas del soporte.
//              Valor por defecto 3.
//          ColumnasDecoradoSeccion         : Total de columnas de vidrio decorativa en
//              cada una de las TotalColumnas secciones del soporte.
//              Valor por defecto 4.
//          DiametroArgolla                 : Diametro de las argollitas sujetadoras.
//              Valor por defecto 8.5*L.          
//          FrenteVidrio                    : Ancho respecto del observador
//              del decorado de vidrio. Valor por defecto 15.6*L.
//          GruesoVidrio                    : Grueso radial del decorado de vidrio.
//              Valor por defecto 7.4*L.
//          AlambreGrueso                   : Diametro de los alambres soporte.
//              Valor por defecto 2.5*L.
//          AlambreMedio                    : Diametro de los alambres secundarios.
//              Valor por defecto 2*L.
//          AlambreDelgado                  : Diametro de las argollitas y laminas delgadas.
//              Valor por defecto 0.5*L.            
//          MaterialSoporte                 : Material del soporte metalico.
//              Valor por defecto CNVI_MaterialSoporte.
//          MaterialVidrio                  : Material del vidrio.
//              Valor por defecto CNVI_MaterialVidrio.
//          MaterialArgolla                 : Material de las argollitas.
//              Valor por defecto CNVI_MaterialArgolla.
//          MaterialCandelero               : Material del candelero interior.
//              Valor por defecto CNVI_MaterialCandelero.
//      
//  El candelero tiene las siguientes caracteristicas:
//      Alto            = 118*L (AltoSoporte)
//      Diametro        =  86*L (algo mayor a DiametroSoporte) 
//  El fondo del recipiente descansa sobre el plano XZ, en el hemisferio Y+.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare CNVI_BaseVela
//      Vector para ubicar la base de la vela dentro de la estructura.    
//  #declare CNVI_DefectoMaterialSoporte            
//      Material para el soporte metalico.
//  #declare CNVI_DefectoMaterialVidrio            
//      Material para el decorado de vidrio.
//  #declare CNVI_DefectoMaterialArgolla            
//      Material para las argollitas sujetadores.
//  #declare CNVI_DefectoMaterialCandelero            
//      Material para el candelero interior.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare CNVI_MaterialSoporte                   =
//                  { CNVI_DefectoMaterialSoporte                 }
//      Material para el soporte metalico.
//  #declare CNVI_MaterialVidrio                    =
//                  { CNVI_DefectoMaterialVidrio                  }
//      Material para el decorado de vidrio.
//  #declare CNVI_MaterialArgolla                   =
//                  { CNVI_DefectoMaterialArgolla                 }
//      Material para las argollitas sujetadores.
//  #declare CNVI_MaterialCandelero                 =
//                  { CNVI_DefectoMaterialCandelero               }
//      Material para el candelero interno.
//       
//  Para colocarlo simplemente
//  #include "CNVI.inc" 
//  object { CNVI_Candelero( 1000 ) }
//   
//  Con una velita
//  #include "CNVI.inc" 
//  union  {
//    object { CNVI_Candelero( 1000 ) }
//    cylinder { 0, 0.020*y, 0.020 pigment { White } translate BNVI_BaseVela }
//  }
//                               
//  Ejemplo con la macro detallada, mismos objetos por defecto
//  #include "CNVI.inc"   
//  object                       {
//    CNVI_CandeleroNoVelaIncluida( 1000, 
//        0.079, 0.118, 0.0294, 0.011, 3, 4, 
//        0.0085, 0.0156, 0.0074, 0.0025, 0.002, 0.0005,
//        CNVI_MaterialSoporte, CNVI_MaterialVidrio,
//        CNVI_MaterialArgolla, CNVI_MaterialCandelero )
//  }
//        
//  Con modificadores
//  #include "CNVI.inc"
//  #include "textures.inc"
//  #declare CNVI_MaterialSoporte         = material { texture { PinkAlabaster } } 
//  object        { CNVI_Candelero( 1000 ) }
//
#include "metals.inc"
#include "glass.inc"

#declare CNVI_L                         = 0.001;

#declare CNVI_DefectoMaterialSoporte    =
  material                              {
    texture                             {
      T_Chrome_2A
    }
  }

#ifndef ( CNVI_MaterialSoporte )
  #declare CNVI_MaterialSoporte         = CNVI_DefectoMaterialSoporte
#end  //  #ifndef ( CNVI_MaterialSoporte )

#declare CNVI_DefectoMaterialVidrio     =
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

#ifndef ( CNVI_MaterialVidrio )
  #declare CNVI_MaterialVidrio          = CNVI_DefectoMaterialVidrio
#end  //  #ifndef ( CNVI_MaterialVidrio )

#declare CNVI_DefectoMaterialArgolla    =
  material                              {
    texture                             {
      T_Copper_2A
    }
  }

#ifndef ( CNVI_MaterialArgolla )
  #declare CNVI_MaterialArgolla         = CNVI_DefectoMaterialArgolla
#end  //  #ifndef ( CNVI_MaterialArgolla )

#declare CNVI_DefectoMaterialCandelero     =
  material                              {
    texture                             {
      T_Chrome_2A
    }
  }

#ifndef ( CNVI_MaterialCandelero )
  #declare CNVI_MaterialCandelero          = CNVI_DefectoMaterialCandelero
#end  //  #ifndef ( CNVI_MaterialCandelero )

#macro CNVI_CandeleroNoVelaIncluida( Semilla,
           DiametroSoporte, AltoSoporte,
           DiametroCandelero, AltoCandelero,
           TotalColumnas, ColumnasDecoradoSeccion,
           DiametroArgolla, FrenteVidrio, GruesoVidrio,
           AlambreGrueso, AlambreMedio, AlambreDelgado,
           MaterialSoporte, MaterialVidrio,
           MaterialArgolla, MaterialCandelero )
  union                                 {
    #local S                            = seed( Semilla );
    //  Armazon Metalico
    union                               {
      torus                             {
        DiametroSoporte/2-AlambreGrueso/2, AlambreGrueso/2
        translate                       AlambreGrueso/2*y
      }
      #local C                          = 0;
      #while ( C < TotalColumnas )
        cylinder                        {
          0, AltoSoporte*y, AlambreMedio/2
          translate             +( DiametroSoporte/2
                -AlambreGrueso-AlambreMedio/2 )*z
          rotate                        360/TotalColumnas*C*y
        }
        #local C                        = C+1;
      #end  //  #while ( C < 3 )
      torus                             {
        DiametroSoporte/2-AlambreGrueso/2, AlambreGrueso/2
        translate                       ( AltoSoporte-AlambreGrueso/2 )*y
      }
      cylinder                          {
        -DiametroSoporte/2*x, DiametroSoporte/2*x, AlambreMedio/2
        translate       ( AlambreGrueso-AlambreMedio/2 )*y
      }
      material                          {
        MaterialSoporte
      }
    }
    //  END Armazon Metalico
    //  Candeleros Centrales
    difference                          {
      cylinder                          {
        0, AltoCandelero*y, DiametroCandelero/2
      }
      cylinder                          {
        AlambreDelgado*y, 1.1*AltoCandelero*y, DiametroCandelero/2-AlambreDelgado
      }      
      cylinder                          {
        -AlambreDelgado*2, 0.5*AltoCandelero*y, DiametroCandelero/4
      }
      translate                         AlambreGrueso*y
      material                          {
        MaterialCandelero
      }
    }
    //  END Candeleros Centrales
    //  Columnas Decorado
    #local FAG                    = 0.9;
    #local AltoDec              = AltoSoporte-FAG*3*AlambreGrueso;
    #local AltoArgolla          = 6*DiametroArgolla;
    #local SeparacionArgolla    = ( AltoDec-AltoArgolla )/5;
    #local AnguloCilDecorado    = degrees( atan2( GruesoVidrio, FrenteVidrio ) );
    #local DiscosDecorado               =
       difference                  {
         cylinder                    {
                  -GruesoVidrio/2*z, +GruesoVidrio/2*z, sqrt(2)*FrenteVidrio/2
         }
         #local D                       = 0;
         #while ( D < 8 )
           plane                        {
             x, -FrenteVidrio/2
             rotate             D*45*z
           }
           plane                        {
             z, 0
             rotate             0.6*AnguloCilDecorado*x
             translate          -GruesoVidrio/2*z
             rotate             D*45*z
           }
           plane                        {
             z, 0
             rotate             0.6*AnguloCilDecorado*x
             translate          -GruesoVidrio/2*z
             rotate             D*45*z
             scale              <1,1,-1>
           }
           #local D                     = D+1;
         #end
       }
    #local BoxDecorado                  =
      difference                        {
        box                               {
          < -FrenteVidrio/2, -FrenteVidrio/2-SeparacionArgolla/2-DiametroArgolla, -GruesoVidrio/2 >,
          < +FrenteVidrio/2, +FrenteVidrio/2+SeparacionArgolla/2+DiametroArgolla, +GruesoVidrio/2 >
        }
        plane                        {
          -z, 0
          rotate             -AnguloCilDecorado*x
          translate          GruesoVidrio/2*z
          translate          +( SeparacionArgolla/2+DiametroArgolla )*y
        }
        plane                        {
          -z, 0
          rotate             AnguloCilDecorado*x
          translate          GruesoVidrio/2*z
          translate          -( SeparacionArgolla/2+DiametroArgolla )*y
        }
        plane                           {
          -z, 0
          rotate        AnguloCilDecorado*y
          translate     GruesoVidrio/2*z
        }
        plane                           {
          -z, 0
          rotate        -AnguloCilDecorado*y
          translate     GruesoVidrio/2*z
        }
      }
       
    union                               {
      #local TotalDecorado              =
                 TotalColumnas*ColumnasDecoradoSeccion;
      #local C                          = 0;
      #while ( C < TotalDecorado )
        union                           {
          //  Sujetadores
          #local D                      = 0;
          #while ( D < 2 )
            union                         {
              box                           {
                < -AlambreGrueso/3, AlambreGrueso/3, -AlambreDelgado/2 >,
                < +AlambreGrueso/3, AlambreGrueso, +AlambreDelgado/2 >
              }
              difference                {
                cylinder                {
                  -AlambreDelgado/2*z, +AlambreDelgado/2*z,
                  AlambreGrueso/2
                }
                cylinder                {
                  -AlambreDelgado*z, +AlambreDelgado*z,
                  AlambreGrueso/3
                }
                translate               FAG*3*AlambreGrueso/2*y
              }
              material                  {
                MaterialSoporte
              }
              #if ( D = 1 )
                scale   <1,-1,1>
                translate               AltoSoporte*y
              #end  //  #if ( D = 1 )
            }
            #local D                    = D+1;
          #end
          //  END Sujetadores
          union                         {
            #local D                    = 0;
            #while ( D < 2 )
              union                       {
                torus                       {
                  DiametroArgolla/2-AlambreDelgado/2, AlambreDelgado/2
                  rotate                    90*x
                  rotate                    ( 85+10*rand( S ) )*y
                  translate         DiametroArgolla/2*y
                  material                  {
                    MaterialArgolla
                  }
                }
                object                          {
                  DiscosDecorado
                  translate      ( DiametroArgolla+SeparacionArgolla/2 )*y
                  rotate        ( -5+10*rand( S ) )*y
                  material                      {
                    MaterialVidrio
                  }
                }
                torus                       {
                  DiametroArgolla/2-AlambreDelgado/2, AlambreDelgado/2
                  rotate                    90*x
                  rotate                    ( 85+10*rand( S ) )*y
                  translate         ( SeparacionArgolla+3*DiametroArgolla/2 )*y
                  material                  {
                    MaterialArgolla
                  }
                }
                #if ( D = 1)
                  scale  <1,-1,1>
                  translate        ( AltoSoporte-FAG*3*AlambreGrueso )*y
                #end
              }
              #local D                  = D+1;
            #end
            union                               {
              object                            {
                DiscosDecorado
                translate       ( 2*DiametroArgolla+3*SeparacionArgolla/2 )*y
                rotate        ( -5+10*rand( S ) )*y
                material                      {
                  MaterialVidrio
                }
              }
              torus                             {
                DiametroArgolla/2-AlambreDelgado/2, AlambreDelgado/2
                rotate                    90*x
                rotate                    ( 85+10*rand( S ) )*y
                translate         ( 2*SeparacionArgolla+5*DiametroArgolla/2 )*y
                material                  {
                  MaterialArgolla
                }
              }
              object                            {
                BoxDecorado
                translate       ( 7*DiametroArgolla/2+3*SeparacionArgolla )*y
                rotate        ( -5+10*rand( S ) )*y
                material                      {
                  MaterialVidrio
                }
              }
              #if ( mod( C, 2 ) = 1 )
                scale  <1,-1,1>
                translate        ( AltoSoporte-FAG*3*AlambreGrueso )*y
              #end
            }
            translate                   FAG*3*AlambreGrueso/2*y
          }
          translate
             ( DiametroSoporte/2+AlambreDelgado/2 )*z
          rotate                        360*( C+0.5 )/TotalDecorado*y
          material                      {
            MaterialVidrio
          }
        }
        #local C                        = C+1;
      #end  //  #while ( C < Total Decorado )
    }
    //  END Columnas Decorado
    material                            {
      MaterialSoporte
    }
    #declare CNVI_BaseVela              = ( AlambreGrueso+AlambreDelgado )*y;
  }
#end  //  #macro CNVI_CandeleroNoVelaIncluida()

#macro CNVI_Candelero( Semilla )
  object                                {
    #local L                            = CNVI_L;
    #local DiametroSoporte              = 79*L;
    #local AltoSoporte                  = 118*L;
    #local DiametroCandelero               = 29.4*L;
    #local AltoCandelero                   = 11*L;
    #local TotalColumnas                = 3;
    #local ColumnasDecoradoSeccion      = 4;
    #local DiametroArgolla              = 8.5*L;
    #local FrenteVidrio                 = 15.6*L;
    #local GruesoVidrio                 = 7.4*L;
    #local AlambreGrueso                = 2.5*L;
    #local AlambreMedio                 = 2*L;
    #local AlambreDelgado               = 0.5*L;
    CNVI_CandeleroNoVelaIncluida( Semilla, DiametroSoporte, AltoSoporte,
      DiametroCandelero, AltoCandelero,
      TotalColumnas, ColumnasDecoradoSeccion,
      DiametroArgolla, FrenteVidrio, GruesoVidrio,
      AlambreGrueso, AlambreMedio, AlambreDelgado,
      CNVI_MaterialSoporte, CNVI_MaterialVidrio,
      CNVI_MaterialArgolla, CNVI_MaterialCandelero )
  }
#end  //  #macro CNVI_Candelero()
