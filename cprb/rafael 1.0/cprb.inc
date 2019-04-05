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
//  CPRB (CalibradorPieReyBarato)
//  El archivo dibuja un modelo sencillo de calibrador con vernier para medidas precisas.
//  Las unidades y algunas caracteristicas basicas pueden modificarse facilmente.
//  Es compatible con POVRay 3.1.
//
//  La macro principal solo tiene un parametro.
//  #macro CPRB_Calibrador( LecturaPR )
//          LecturaPR               : Desplace el vernier hacia X- en unidades POV-Ray.
//
//
//  La siguiente macro permite un mayor control sobre las caracteristicas.
//  #macro CPRB_CalibradorPieReyBarato( LecturaPR,
//                LargoFundamental, LargoPie, GruesoFijo,
//                AnchoDeslizante, TamanoPie, FraccionDelanteraPie,
//                GruesoAire, LargoPrecision, AnchoPrecisionPosterior,
//                GruesoPrecision, DiametroAlambre,
//                MaterialPrincipal, MaterialDeslizante, 
//                MaterialAlambre, MaterialMarcas )
//          LecturaPR               : Desplace el vernier hacia X- en unidades POV-Ray. 
//          LargoFundamental        : Largo total en X del calibrador.
//              Valor por defecto 150*L.
//          LargoPie                : Tamano en X del pie fijo del calibrador.
//              Valor por defecto 11*L.
//          GruesoFijo              : Grueso de la regla fija del calibrador.
//              Valor por defecto 2*L.
//          AnchoDeslizante         : Ancho en Y de la regla fija del calibrador.
//              Valor por defecto 11*L.
//          TamanoPie               : Tamano en Y del pie fijo del calibrador.
//              Valor por defecto 53*L.
//          FraccionDelanteraPie    : Fraccion del pie fijo que se encuentra sobre
//              el plano superior Y+. Valor por defecto 0.64.
//          GruesoAire              : Grueso de las aberturas huecas en la mordedura 
//              del calibrador. Valor por defecto 1*L.
//          LargoPrecision          : Largo total del vernier movil.
//              Valor por defecto 59*L.
//          AnchoPrecisionPosterior : Grosor en Y de la escala inferior movil.
//              Valor por defecto 4*L.
//          GruesoPrecision         : Grosor Z del calibrador total.
//              Valor por defecto 3.5*L.
//          DiametroAlambre         : Diametro del alambrillo para medir profundidad.
//              Valor por defecto 1*L. 
//          MaterialPrincipal       : Material de la regla fija.
//              Valor por defecto CPRB_MaterialPrincipal.
//          MaterialDeslizante      : Material del vernier movil.
//              Valor por defecto CPRB_MaterialDeslizante.
//          MaterialAlambre         : Material del alambrillo para medir profundidad.
//              Valor por defecto CPRB_MaterialAlambre.
//          MaterialMarcas          : Material para numeros y escalas.
//              Valor por defecto CPRB_MaterialMarcas.     
//
//  La unidad por defecto del calibrador es el mL (miliLisa).  Para darle mayor versatilidad
//  se ofrece una variante con fracciones binarias del cL (centiLisa). 
//  Por razones esteticas las unidades del vernier por defecto, se ajusta 
//  proporcionalmente a LargoPrecision-LargoPie.
//  El usuario puede asignar su propio sistema de unidades, utilizando modificadores.
//
//  El calibrador se encuentra contenido entre las siguientes coordenadas:
//      Minimo          = < -( LargoFundamental+LecturaPR-LargoPie ),
//                          -( TamanoPie*( 1-FraccionDelantera ) ), -GruesoFijo/2 >                          
//      Maximo          = < LargoPie, FraccionDelantera*TamanoPie, 
//                          ( GruesoPrecision-GruesoFijo/2 ) >
//  Con los valores por defecto y parametro nulo, el resultado seria:
//      Minimo          = < -139.0,   19.1,   -1.0 >*L
//      Maximo          = <   11.0,   33.9,    2.5 >*L
//  La base del pie fijo se encuentra ajustado con el eje Y. La regla apunta hacia X-,
//  las marcas hacia Z-.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.   
//  #declare CPRB_DefectoMaterialPrincipal       
//      Material de la regla fija.
//  #declare CPRB_DefectoMaterialDeslizante      
//      Material del vernier movil.
//  #declare CPRB_DefectoMaterialAlambre         
//      Material del alambrillo para medir profundidad.
//  #declare CPRB_DefectoMaterialMarcas          
//      Material para numeros y escalas.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare CPRB_EscalaDecimal
//      Valor real. Si se declara sustituye el sistema de medidas superior Y+ del
//      calibrador. Su valor en unidades POV-Ray
//      debe corresponder al numeral 10 de la escala superior.
//      Un valor 0.010 corresponderia a la escala actual.
//  #declare CPRB_EscalaBinaria
//      Valor real. Si se declara sustituye el sistema de medidas inferior Y- del
//      calibrador. Su valor en unidades POV-Ray
//      debe corresponder al numeral 1 de la escala inferior.
//      Se modificara la separacion en el vernier inferior para que concuerde
//      con el patron del modelo original.
//      Un valor 0.010 corresponderia a la escala actual.
//  #declare CPRB_MaterialPrincipal             =
//                      { CPRB_DefectoMaterialPrincipal             }
//      Material de la regla fija.
//  #declare CPRB_MaterialDeslizante            =
//                      { CPRB_DefectoMaterialDeslizante            }
//      Material del vernier movil.
//  #declare CPRB_MaterialAlambre               =
//                      { CPRB_DefectoMaterialAlambre               }
//      Material del alambrillo para medir profundidad.
//  #declare CPRB_MaterialMarcas                =
//                      { CPRB_DefectoMaterialMarcas                }
//      Material para numeros y escalas.
//       
//  Para colocarlo simplemente
//  #include "CPRB.inc" 
//  object { CPRB_Calibrador( 0.0 ) }
//                                  
//  Con la macro detallada
//  #include "CPRB.inc" 
//  object          {
//    CPRB_CalibradorPieReyBarato( 0.0,
//            0.150, 0.011, 0.002, 0.011, 0.053, 0.64, 
//            0.001, 0.059, 0.004, 0.0035, 0.001,              
//            CPRB_MaterialPrincipal, CPRB_MaterialDeslizante,
//            CPRB_MaterialAlambre, CPRB_MaterialMarcas ) 
//  }
//      
//  Con modificadores
//  #include "CPRB.inc"
//  #include "textures.inc"
//  #declare CPRB_MaterialPrincipal         = 
//          material { texture { PinkAlabaster } }
//  object        { CPRB_Calibrador( 0.0 ) }
//
#include "colors.inc"
#include "metals.inc"

#declare CPRB_L                         = 0.001;

#declare CPRB_DefectoMaterialPrincipal  =
  material                              {
    texture                             {
      T_Chrome_4B
      normal                            {
        bumps
      }
    }
  }

#ifndef ( CPRB_MaterialPrincipal )
  #declare CPRB_MaterialPrincipal       = CPRB_DefectoMaterialPrincipal
#end  //  #ifndef ( CPRB_MaterialPrincipal )

#declare CPRB_DefectoMaterialDeslizante  =
  material                              {
    texture                             {
      T_Chrome_4A
      normal                            {
        bumps
      }
    }
  }

#ifndef ( CPRB_MaterialDeslizante )
  #declare CPRB_MaterialDeslizante       = CPRB_DefectoMaterialDeslizante
#end  //  #ifndef ( CPRB_MaterialDeslizante )

#declare CPRB_DefectoMaterialAlambre      =
  material                              {
    texture                             {
      T_Silver_2C
    }
  }

#ifndef ( CPRB_MaterialAlambre )
  #declare CPRB_MaterialAlambre          = CPRB_DefectoMaterialAlambre
#end  //  #ifndef ( CPRB_MaterialAlambre )
 
#declare CPRB_DefectoMaterialMarcas      =
  material                              {
    texture                             {
      pigment           { Black }
    }
  }

#ifndef ( CPRB_MaterialMarcas )
  #declare CPRB_MaterialMarcas           = CPRB_DefectoMaterialMarcas
#end  //  #ifndef ( CPRB_MaterialMarcas )
  
#macro CPRB_CalibradorPieReyBarato( LecturaPR,
                LargoFundamental, LargoPie, GruesoFijo,
                AnchoDeslizante, TamanoPie, FraccionDelanteraPie,
                GruesoAire, LargoPrecision, AnchoPrecisionPosterior,
                GruesoPrecision, DiametroAlambre,
                MaterialPrincipal, MaterialDeslizante, 
                MaterialAlambre, MaterialMarcas )
  union                                 {    
    #local L                            = CPRB_L;
    #local EscalaLPMedida               = ( LargoPrecision-LargoPie )/( 48*L ); 
    #local EscalaLPSuperior3D           =
        < EscalaLPMedida, AnchoPrecisionPosterior/( 4*L ), GruesoFijo/( 2*L  ) >; 
    #local EscalaLPMedio3D              =
        < EscalaLPMedida, AnchoDeslizante/( 11*L ), GruesoFijo/( 2*L  ) >; 
    //  No tiene mucho sentido fisico escalar la escala por estetica,
    //  defina modificadores CPRB_EscalaDecimal y CPRB_EscalaBinaria para escoger
    //  unidades a gusto
    #local GruesoExtraPrecision         = GruesoPrecision-GruesoFijo;
    #local CabezaFijaSuperior           =
        union                           {
          prism                         {
            -AnchoDeslizante/2-AnchoPrecisionPosterior,
            +AnchoDeslizante/2+1.25*AnchoPrecisionPosterior,
            6,
            < +GruesoAire/2, +GruesoFijo/2 >,
            < +LargoPie, +GruesoFijo/2 >,
            < +LargoPie, -GruesoFijo/ 4 >,
            < +LargoPie-GruesoFijo, -GruesoFijo/2 >,
            < +GruesoAire/2, -GruesoFijo/2 >,
            < +GruesoAire/2, +GruesoFijo/2 >
          }
          #local PT1                    = < +LargoPie-GruesoFijo,
             1.25*AnchoPrecisionPosterior+AnchoDeslizante/2, -GruesoFijo/2 >;
          #local PT2                    = < +LargoPie,
             1.25*AnchoPrecisionPosterior+AnchoDeslizante/2, -GruesoFijo/4 >;
          #local PT3                    = < +LargoPie/3,
             TamanoPie*FraccionDelanteraPie-GruesoFijo, -GruesoFijo/2 >;
          #local IT1                    = < PT1.x, PT1.y, +GruesoFijo/2 >;
          #local IT2                    = < PT2.x, PT2.y, +GruesoFijo/2 >;
          #local IT3                    = < PT3.x, PT3.y, +GruesoFijo/2 >;
          #local IT5                    =
             < 0, TamanoPie*FraccionDelanteraPie, +GruesoFijo/2 >;
          #local ST4                    =
                ( 2*IT3/3+IT5/3 )*( x+y )-GruesoFijo/2*z;
          #local MT4                    = ST4-2*GruesoFijo*y;
          #local MT5                    = < IT5.x, MT4.y, IT5.z >;
          triangle                      {
            PT1, PT2, PT3
          }
          polygon                       {
            5,
            PT2, PT3, IT3, IT2, PT2
          }
          triangle                      {
            PT3, ST4, IT5
          }
          triangle                      {
            PT3, IT3, IT5
          }
          triangle                      {
            MT4, ST4, IT5
          }
          triangle                      {
            MT4, MT5, IT5
          }
          triangle                      {
            IT5, IT3, IT2
          }
          triangle                      {
            IT1, IT5, IT2
          }
          triangle                      {
            IT2, MT5, IT5
          }
          prism                         {
            -GruesoFijo/2, GruesoFijo/2,
            9,
            < IT1.x, IT1.y >,
            < +GruesoAire/2, IT1.y >,
            < +GruesoAire/2, +AnchoDeslizante/2+2*AnchoPrecisionPosterior >,
            < 0, AnchoDeslizante/2+2*AnchoPrecisionPosterior >,
            < MT5.x, MT5.y >,
            < MT4.x, MT4.y >,
            < ST4.x, ST4.y >,
            < IT3.x, IT3.y >,
            < IT1.x, IT1.y >
            rotate              -90*x
          }
        }

    #local CabezaFijaInferior                   =
        union                                     {
          prism                                   {
            -GruesoFijo/2, -GruesoFijo/2+GruesoExtraPrecision,
            7,
            < -GruesoAire/2-LargoPie/2,
              -AnchoDeslizante/2-AnchoPrecisionPosterior+GruesoFijo/2 >,
            < -GruesoAire/2, 0 >,
            < -GruesoAire/2, -AnchoDeslizante/2-1.5*AnchoPrecisionPosterior >,
            < -GruesoExtraPrecision, -AnchoDeslizante/2
              -1.5*AnchoPrecisionPosterior >,
            < -GruesoExtraPrecision, -( 1-FraccionDelanteraPie )*TamanoPie
              +GruesoFijo >,
            < -GruesoAire/2-LargoPie/2,
              -AnchoDeslizante/2-AnchoPrecisionPosterior >,
            < -GruesoAire/2-LargoPie/2,
              -AnchoDeslizante/2-AnchoPrecisionPosterior+GruesoFijo/2 >
            rotate                      -90*x
          }
          //  atan2 y, 2
          #local AnguloCorteInf           =
            degrees( atan2( GruesoFijo, GruesoExtraPrecision ) );
          difference                    {
            prism                         {
              0, -( 1-FraccionDelanteraPie )*TamanoPie,
              4,
              < -GruesoExtraPrecision, +GruesoFijo/2-GruesoExtraPrecision >,
              < -GruesoExtraPrecision, +GruesoFijo/2 >,
              < 0, +GruesoFijo/2 >,
              < -GruesoExtraPrecision, +GruesoFijo/2-GruesoExtraPrecision >
              matrix  < 1, -GruesoFijo/GruesoExtraPrecision, 0,
                        0, 1, 0,
                        0, 0, 1,
                        0, 0, 0 >
            }
            plane                         {
              -y, +AnchoDeslizante/2+1.5*AnchoPrecisionPosterior
            }
          }
        }
    //  Cuerpo Fijo
      union                               {
        difference                      {
          box                               {
            < -( LargoFundamental-LargoPie ),
              -( AnchoDeslizante-GruesoFijo )/2, -GruesoFijo/2 >,
            < +LargoPie/2,
              +( AnchoDeslizante-GruesoFijo )/2, +GruesoFijo/2 >
          }
          box                           {
            < -LargoFundamental, -0.6*DiametroAlambre,
              +GruesoFijo/2-DiametroAlambre >,
            < -1.5*LargoPie, +0.6*DiametroAlambre, +GruesoFijo >
          }
        }
        box                             {
          < -LargoFundamental+LargoPie+GruesoFijo, -GruesoFijo,
             +GruesoFijo/2 >,
          < -LargoFundamental+LargoPie+2*GruesoFijo, +GruesoFijo,
             +1.1*GruesoFijo/2 >
        }
        cylinder                        {
          -( LargoFundamental-LargoPie )*x,
          +LargoPie/2*x, GruesoFijo/2
          translate     +( AnchoDeslizante-GruesoFijo )/2*y
        }
        cylinder                        {
          -( LargoFundamental-LargoPie )*x,
          +LargoPie/2*x, GruesoFijo/2
          translate     -( AnchoDeslizante-GruesoFijo )/2*y
        }
        object                          {
          CabezaFijaSuperior
        }
        object                          {
          CabezaFijaInferior
          translate             LargoPie/2*x
        }
        //  Etiquetas Fijas
        union                           {        
          #ifdef ( CPRB_EscalaDecimal )
            #local Unidad                 = CPRB_EscalaDecimal/10;
          #else  //  #else ( CPRB_EscalaDecimal )
            #local Unidad                 = L*EscalaLPMedida;
          #end   //  #else ( CPRB_EscalaDecimal )
          #local DiametroMarca          = 1*L/5*EscalaLPMedida;
          #local EspacioDisponible      = 0.8*( LargoFundamental-LargoPie );
          #local DesplazamientoInicial  = 2*L*EscalaLPMedida;
          #local TMarca                 = DesplazamientoInicial;
          #local C                      = 0;
          #while ( TMarca < EspacioDisponible )
            #local BanderaAlargar       = ( mod( C, 5 ) = 0 );
            cylinder                    {
              +( AnchoDeslizante/2-GruesoFijo/2 )*y,
              #if ( BanderaAlargar )
                +0.5*( AnchoDeslizante/2-GruesoFijo/2 )*y
              #else
                +0.75*( AnchoDeslizante/2-GruesoFijo/2 )*y
              #end
              DiametroMarca/2
              scale     < 1,1,1 >
              translate -GruesoFijo/2*z-TMarca*x
            }
            #if ( mod( C, 10 ) = 0 )
              text                              {
                ttf  "crystal.ttf", str( C, 1, 0 ), 1, 0
                scale    2*L*EscalaLPMedio3D*<-1,-1,1>
                translate       -GruesoFijo/2*z-TMarca*x+
                       EscalaLPMedio3D*( -0.125*L*z+0.75*L*x+2*L*y )
              }
            #end  //  #if ( BanderaAlargar )
            #local C                    = C+1;
            #local TMarca               = TMarca+Unidad;
          #end  //  #while ( TMarca < EspacioDisponible )
          material                      {
            MaterialMarcas
          }
        }
        union                           {
          #ifdef ( CPRB_EscalaBinaria )
            #local Unidad                 = CPRB_EscalaBinaria/16;
          #else  //  #else ( CPRB_EscalaBinaria )
            #local Unidad                 = 10/16*L*EscalaLPMedida;
          #end   //  #else ( CPRB_EscalaBinaria )
          #local DiametroMarca          = 15*L/16*EscalaLPMedida/5;
          #local DesplazamientoInicial  = 2*L*EscalaLPMedida;
          #local EspacioDisponible      = 0.8*( LargoFundamental-LargoPie );
          #local TMarca                 = DesplazamientoInicial;
          #local C                      = 0;
          #while ( TMarca < EspacioDisponible )
            cylinder                    {
              -( AnchoDeslizante/2-GruesoFijo/2 )*y,
              #if ( mod( C, 2 ) = 0 )
                #if ( mod( C, 4 ) = 0  )
                  -0.5*( AnchoDeslizante/2-GruesoFijo/2 )*y
                #else
                  -0.65*( AnchoDeslizante/2-GruesoFijo/2 )*y
                #end
              #else
                -0.80*( AnchoDeslizante/2-GruesoFijo/2 )*y
              #end
              DiametroMarca/2
              translate -GruesoFijo/2*z-TMarca*x
            }
            #if ( mod( C, 16 ) = 0 )
              text                              {
                ttf  "crystal.ttf", str( div( C, 16 ), 1, 0 ), 1, 0
                scale    1.5*L*EscalaLPMedio3D*<-1,-1,1>
                translate       -GruesoFijo/2*z-TMarca*x+
                       EscalaLPMedio3D*( -0.125*L*z-0.0*L*x-1*L*y )
              }              
            #end  //  #if ( BanderaAlargar )
            #local TMarca               = TMarca+Unidad;   
            #local C                    = C+1;
          #end  //  #while ( TMarca < EspacioDisponible )
          material                  {
            MaterialMarcas
          }
        }
        //  END Etiquetas Fijas
      }      
    //  END Cuerpo Fijo   
    //  Cuerpo Movil
    union                               {
      difference                          {
        union                             {
          object                          {
            CabezaFijaSuperior
            rotate  0.5*z
            scale         <-1,1,1>
          }
          object                          {
            CabezaFijaInferior
            translate             -GruesoFijo/2*z
            scale         <-1,1,-1>
            translate             +GruesoFijo/2*z
            translate             LargoPie/2*x
          }
          intersection                           {
            prism                         {
              +GruesoFijo/2, -GruesoPrecision+GruesoFijo/2,
              10,
              < -LargoPrecision+LargoPie,
                -AnchoDeslizante/2-AnchoPrecisionPosterior+GruesoFijo/2 >,
              < -LargoPrecision+LargoPie,
                +AnchoDeslizante/2+AnchoPrecisionPosterior >,
              < -LargoPrecision+LargoPie+AnchoPrecisionPosterior,
                +AnchoDeslizante/2+2*AnchoPrecisionPosterior >,
              < -LargoPrecision+LargoPie+3*AnchoPrecisionPosterior,
                +AnchoDeslizante/2+2*AnchoPrecisionPosterior >,
              < -LargoPrecision+LargoPie+3.75*AnchoPrecisionPosterior,
                +AnchoDeslizante/2+1.25*AnchoPrecisionPosterior >,
              < +LargoPie,
                +AnchoDeslizante/2+1.25*AnchoPrecisionPosterior >,
              < +LargoPie, -AnchoDeslizante/2
                          -AnchoPrecisionPosterior >,
              < -LargoPrecision+LargoPie+3.75*AnchoPrecisionPosterior,
                          -AnchoDeslizante/2-AnchoPrecisionPosterior >,
              < -LargoPrecision+LargoPie+3*AnchoPrecisionPosterior,
                          -AnchoDeslizante/2+GruesoFijo/2-2*AnchoPrecisionPosterior >,
              < -LargoPrecision+LargoPie+AnchoPrecisionPosterior,
                          -AnchoDeslizante/2+GruesoFijo/2-2*AnchoPrecisionPosterior >
              rotate              -90*x
            }
            union                                 {
              prism                         {
                -LargoPrecision+1.01*LargoPie, 1.01*LargoPie,
                4,
                < -AnchoDeslizante/2-AnchoPrecisionPosterior+
                  GruesoFijo/2, -1.01*GruesoFijo/2 >,
                < +AnchoDeslizante/2+AnchoPrecisionPosterior, -1.01*GruesoFijo/2 >,
                < +AnchoDeslizante/2+6*AnchoPrecisionPosterior,
                    -1.01*GruesoFijo/2+GruesoPrecision >,
                < -AnchoDeslizante/2-6*AnchoPrecisionPosterior,
                    -1.01*GruesoFijo/2+GruesoPrecision >
                rotate              -90*z
                scale  <1,-1,1>
              }
              box                         {
                < -0.5*LargoPrecision+LargoPie, 0, -GruesoFijo >,
                < 1.01*LargoPie, -TamanoPie, +GruesoFijo+GruesoPrecision >
              }
            }
          }
        }
        box                               {
          < -2*LargoFundamental, -1.05*( AnchoDeslizante/2-GruesoFijo/2 ),
                  +1.02*GruesoFijo/2 >,
          < 2*LargoPie, 1.05*( AnchoDeslizante/2-GruesoFijo/2 ), -GruesoFijo >
        }
        cylinder                          {
          -2*LargoFundamental*x, 2*LargoPie*x, 1.025*GruesoFijo/2
          translate               ( AnchoDeslizante/2-GruesoFijo/2 )*y
        }
        cylinder                          {
          -2*LargoFundamental*x, 2*LargoPie*x, 1.025*GruesoFijo/2
          translate              -( AnchoDeslizante/2-GruesoFijo/2 )*y
        }
        box                               {
          < -2*LargoFundamental, -1.5*AnchoDeslizante/2,
                  +GruesoFijo/4 >,
          < 2*LargoPie, 1.5*AnchoDeslizante/2, -GruesoFijo/4 >
        }
        box                               {
          < -GruesoAire/2, 0, -2*GruesoPrecision >,
          < 2*LargoPie, AnchoDeslizante/2+2*AnchoPrecisionPosterior, +2*GruesoPrecision >
        }
      }
      union                             {
        cylinder                          {
          -( LargoFundamental-LargoPie )*x,
          +( LargoPie-2*LargoPrecision/3 )*x, DiametroAlambre/2
        }
        cylinder                        {
          0, ( 1.1*DiametroAlambre/2+GruesoExtraPrecision )*z, DiametroAlambre/2
          translate     +( LargoPie-2*LargoPrecision/3 )*x
        }
        translate       ( GruesoFijo-DiametroAlambre )/2*z
        material                        {
          MaterialAlambre
        }
      }
      //  Etiquetas Moviles
        union                           {
          #ifdef ( CPRB_EscalaDecimal )
            #local Unidad                 = 39/20*CPRB_EscalaDecimal/10;
          #else  //  #else ( CPRB_EscalaDecimal )
            #local Unidad                 = 39/20*L*EscalaLPMedida;
          #end   //  #else ( CPRB_EscalaDecimal )
          #local DiametroMarca          = 39*L/20/5*EscalaLPMedida;
          #local DesplazamientoInicial  = 2*L*EscalaLPMedida;
          #local EspacioDisponible      = 0.8*( LargoFundamental-LargoPie );
          #local TMarca                 = DesplazamientoInicial;
          #local C                      = 0;
          #while ( C < 21 )
            #local BanderaAlargar       = ( mod( C, 2 ) = 0 );
            cylinder                    {
              +( AnchoDeslizante/2-0.95*GruesoFijo/2 )*y,
              #if ( BanderaAlargar )
                +( AnchoDeslizante/2-GruesoFijo/2+0.5*AnchoPrecisionPosterior )*y
              #else
                +( AnchoDeslizante/2-GruesoFijo/2+0.25*AnchoPrecisionPosterior )*y
              #end
              DiametroMarca/2
              scale     < 1,1,1 >
              translate -GruesoFijo/2*z-TMarca*x
            }

            #if ( mod( C, 2 ) = 0 )
              text                              {
                ttf  "crystal.ttf", str( C/2, 1, 0 ), 1, 0
                scale    2*L*EscalaLPSuperior3D*<-1,-1,1>
                translate       -GruesoFijo/2*z-TMarca*x+
                        EscalaLPSuperior3D*( -0.125*L*z+0.5*L*x+1.5*L*y )
                        +( AnchoDeslizante/2-GruesoFijo/2
                          +0.6*AnchoPrecisionPosterior )*y
              }
            #end  //  #if ( BanderaAlargar )
            #local C                    = C+1;
            #local TMarca               = TMarca+Unidad;
          #end  //  #while ( TMarca < EspacioDisponible )
          material                      {
            MaterialMarcas
          }
        }
        union                           {
          #ifdef ( CPRB_EscalaBinaria )
            #local Unidad                 = 7/8*CPRB_EscalaBinaria/16;
          #else  //  #else ( CPRB_EscalaBinaria )
            #local Unidad                 = 310/128*L*EscalaLPMedida;
          #end   //  #else ( CPRB_EscalaBinaria )
          #local DiametroMarca          = 310*L/128/10*EscalaLPMedida;
          #local DesplazamientoInicial  = 2*L*EscalaLPMedida;
          #local EspacioDisponible      = 0.8*( LargoFundamental-LargoPie );
          #local TMarca                 = DesplazamientoInicial;
          #local C                      = 0;
          #while ( C < 9 )
            #local BanderaAlargar       = ( mod( C, 4 ) = 0 );
            cylinder                    {
              -( AnchoDeslizante/2-0.95*GruesoFijo/2 )*y,
              #if ( BanderaAlargar )
                -( AnchoDeslizante/2-GruesoFijo/2+0.5*AnchoPrecisionPosterior )*y
              #else
                -( AnchoDeslizante/2-GruesoFijo/2+0.25*AnchoPrecisionPosterior )*y
              #end
              DiametroMarca/2
              scale     < 1,1,1 >
              translate -GruesoFijo/2*z-TMarca*x
            }

            #if ( mod( C, 4 ) = 0 )
              text                              {
                ttf  "crystal.ttf", str( C, 1, 0 ), 1, 0
                scale    2*L*EscalaLPSuperior3D*<-1,-1,1>
                translate       -GruesoFijo/2*z-TMarca*x
                       +EscalaLPSuperior3D*( -0.125*L*z+0.5*L*y+0.25*L*x )
                        -( AnchoDeslizante/2-GruesoFijo/2
                          +0.6*AnchoPrecisionPosterior )*y
              }
            #end  //  #if ( BanderaAlargar )

            #local C                    = C+1;
            #local TMarca               = TMarca+Unidad;
          #end  //  #while ( TMarca < EspacioDisponible )
          material                      {
            MaterialMarcas
          }
        }
            //  END Etiquetas Moviles
      material                          {
        MaterialDeslizante
      }
      translate         -LecturaPR*x
    }
    //  END Cuerpo Movil  
    material                            {
      MaterialPrincipal
    }
  }
#end  // #macro CPRB_CalibradorPieReyBarato()

#macro CPRB_Calibrador( LecturaPR )
  object                                {
    #local L                            = CPRB_L;
    #local LargoFundamental             = 150*L;
    #local LargoPie                     =  11*L;
    #local GruesoFijo                   =   2*L;
    #local AnchoDeslizante              =  11*L;
    #local TamanoPie                    =  53*L;
    #local FraccionDelanteraPie         = 0.64;
    #local GruesoAire                   =   1*L;
    #local LargoPrecision               =  59*L;
    #local AnchoPrecisionPosterior      =   4*L;
    #local GruesoPrecision              = 3.5*L;
    #local DiametroAlambre              =   1*L;
    CPRB_CalibradorPieReyBarato( LecturaPR,
                LargoFundamental, LargoPie, GruesoFijo,
                AnchoDeslizante, TamanoPie, FraccionDelanteraPie,
                GruesoAire, LargoPrecision, AnchoPrecisionPosterior,
                GruesoPrecision, DiametroAlambre,
                CPRB_MaterialPrincipal, CPRB_MaterialDeslizante,
                CPRB_MaterialAlambre, CPRB_MaterialMarcas )
  }
#end  //  #macro CPRB_Calibrador()
